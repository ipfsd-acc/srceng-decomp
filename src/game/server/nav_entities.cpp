// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/nav_entities.cpp
// Functions: 109
// ============================================================

#include "game\server\nav_entities.h"

//------------------------------------------------------------------------------
// Address: 0x10011AF0
// Name: struct datamap_t __near * DataMapInit<struct AIAgentScheduleState_t>(struct AIAgentScheduleState_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AIAgentScheduleState_t>()
{
  if ( (_S3 & 1) == 0 )
  {
    _S3 |= 1u;
    nameHolder_1.m_pszBase = "AIAgentScheduleState_t";
    nameHolder_1.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_1.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_1.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_1.m_Names.m_Size = 0;
    nameHolder_1.m_Names.m_pElements = nullptr;
    nameHolder_1.m_nLenBase = 22;
    atexit(func: DataMapInit_AIAgentScheduleState_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AIAgentScheduleState_t::m_DataMap.baseMap = nullptr;
  AIAgentScheduleState_t::m_DataMap.dataNumFields = 7;
  AIAgentScheduleState_t::m_DataMap.dataDesc = &dataDesc_1[1];
  return &AIAgentScheduleState_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10011B70
// Name: struct datamap_t __near * DataMapInit<struct AIAgentSaveHeader_t>(struct AIAgentSaveHeader_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AIAgentSaveHeader_t>()
{
  if ( (_S4 & 1) == 0 )
  {
    _S4 |= 1u;
    nameHolder_2.m_pszBase = "AIAgentSaveHeader_t";
    nameHolder_2.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_2.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_2.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_2.m_Names.m_Size = 0;
    nameHolder_2.m_Names.m_pElements = nullptr;
    nameHolder_2.m_nLenBase = 19;
    atexit(func: DataMapInit_AIAgentSaveHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AIAgentSaveHeader_t::m_DataMap.baseMap = nullptr;
  AIAgentSaveHeader_t::m_DataMap.dataNumFields = 7;
  AIAgentSaveHeader_t::m_DataMap.dataDesc = &dataDesc_2[1];
  return &AIAgentSaveHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10037180
// Name: struct datamap_t __near * DataMapInit<struct AIScheduleState_t>(struct AIScheduleState_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AIScheduleState_t>()
{
  if ( (_S7 & 1) == 0 )
  {
    _S7 |= 1u;
    nameHolder_6.m_pszBase = "AIScheduleState_t";
    nameHolder_6.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_6.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_6.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_6.m_Names.m_Size = 0;
    nameHolder_6.m_Names.m_pElements = nullptr;
    nameHolder_6.m_nLenBase = 17;
    atexit(func: DataMapInit_AIScheduleState_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AIScheduleState_t::m_DataMap.baseMap = nullptr;
  AIScheduleState_t::m_DataMap.dataNumFields = 9;
  AIScheduleState_t::m_DataMap.dataDesc = &dataDesc_6[1];
  return &AIScheduleState_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10037200
// Name: struct datamap_t __near * DataMapInit<struct UnreachableEnt_t>(struct UnreachableEnt_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<UnreachableEnt_t>()
{
  if ( (_S9 & 1) == 0 )
  {
    _S9 |= 1u;
    nameHolder_7.m_pszBase = "UnreachableEnt_t";
    nameHolder_7.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_7.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_7.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_7.m_Names.m_Size = 0;
    nameHolder_7.m_Names.m_pElements = nullptr;
    nameHolder_7.m_nLenBase = 16;
    atexit(func: DataMapInit_UnreachableEnt_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  UnreachableEnt_t::m_DataMap.baseMap = nullptr;
  UnreachableEnt_t::m_DataMap.dataNumFields = 3;
  UnreachableEnt_t::m_DataMap.dataDesc = &dataDesc_7[1];
  return &UnreachableEnt_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10037280
// Name: struct datamap_t __near * DataMapInit<struct ScriptedNPCInteraction_Phases_t>(struct ScriptedNPCInteraction_Phases_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<ScriptedNPCInteraction_Phases_t>()
{
  if ( (_S10 & 1) == 0 )
  {
    _S10 |= 1u;
    nameHolder_8.m_pszBase = "ScriptedNPCInteraction_Phases_t";
    nameHolder_8.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_8.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_8.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_8.m_Names.m_Size = 0;
    nameHolder_8.m_Names.m_pElements = nullptr;
    nameHolder_8.m_nLenBase = 31;
    atexit(func: DataMapInit_ScriptedNPCInteraction_Phases_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  ScriptedNPCInteraction_Phases_t::m_DataMap.baseMap = nullptr;
  ScriptedNPCInteraction_Phases_t::m_DataMap.dataNumFields = 2;
  ScriptedNPCInteraction_Phases_t::m_DataMap.dataDesc = &dataDesc_8[1];
  return &ScriptedNPCInteraction_Phases_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10037300
// Name: struct datamap_t __near * DataMapInit<struct ScriptedNPCInteraction_t>(struct ScriptedNPCInteraction_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<ScriptedNPCInteraction_t>()
{
  if ( (_S11 & 1) == 0 )
  {
    _S11 |= 1u;
    nameHolder_9.m_pszBase = "ScriptedNPCInteraction_t";
    nameHolder_9.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_9.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_9.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_9.m_Names.m_Size = 0;
    nameHolder_9.m_Names.m_pElements = nullptr;
    nameHolder_9.m_nLenBase = 24;
    atexit(func: DataMapInit_ScriptedNPCInteraction_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  ScriptedNPCInteraction_t::m_DataMap.baseMap = nullptr;
  ScriptedNPCInteraction_t::m_DataMap.dataNumFields = 17;
  ScriptedNPCInteraction_t::m_DataMap.dataDesc = &dataDesc_9[1];
  return &ScriptedNPCInteraction_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10037380
// Name: struct datamap_t __near * DataMapInit<struct AIExtendedSaveHeader_t>(struct AIExtendedSaveHeader_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AIExtendedSaveHeader_t>()
{
  if ( (_S12 & 1) == 0 )
  {
    _S12 |= 1u;
    nameHolder_10.m_pszBase = "AIExtendedSaveHeader_t";
    nameHolder_10.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_10.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_10.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_10.m_Names.m_Size = 0;
    nameHolder_10.m_Names.m_pElements = nullptr;
    nameHolder_10.m_nLenBase = 22;
    atexit(func: DataMapInit_AIExtendedSaveHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AIExtendedSaveHeader_t::m_DataMap.baseMap = nullptr;
  AIExtendedSaveHeader_t::m_DataMap.dataNumFields = 7;
  AIExtendedSaveHeader_t::m_DataMap.dataDesc = &dataDesc_10[1];
  return &AIExtendedSaveHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10041BE0
// Name: struct datamap_t __near * DataMapInit<struct AIChannelScheduleState_t>(struct AIChannelScheduleState_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AIChannelScheduleState_t>()
{
  if ( (_S2_5 & 1) == 0 )
  {
    _S2_5 |= 1u;
    nameHolder_13.m_pszBase = "AIChannelScheduleState_t";
    nameHolder_13.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_13.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_13.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_13.m_Names.m_Size = 0;
    nameHolder_13.m_Names.m_pElements = nullptr;
    nameHolder_13.m_nLenBase = 24;
    atexit(func: DataMapInit_AIChannelScheduleState_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AIChannelScheduleState_t::m_DataMap.baseMap = nullptr;
  AIChannelScheduleState_t::m_DataMap.dataNumFields = 7;
  AIChannelScheduleState_t::m_DataMap.dataDesc = &dataDesc_13[1];
  return &AIChannelScheduleState_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10042030
// Name: struct datamap_t __near * DataMapInit<struct AIBehaviorChannelSaveHeader_t>(struct AIBehaviorChannelSaveHeader_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AIBehaviorChannelSaveHeader_t>()
{
  if ( (_S5_0 & 1) == 0 )
  {
    _S5_0 |= 1u;
    nameHolder_15.m_pszBase = "AIBehaviorChannelSaveHeader_t";
    nameHolder_15.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_15.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_15.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_15.m_Names.m_Size = 0;
    nameHolder_15.m_Names.m_pElements = nullptr;
    nameHolder_15.m_nLenBase = 29;
    atexit(func: DataMapInit_AIBehaviorChannelSaveHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AIBehaviorChannelSaveHeader_t::m_DataMap.baseMap = nullptr;
  AIBehaviorChannelSaveHeader_t::m_DataMap.dataNumFields = 5;
  AIBehaviorChannelSaveHeader_t::m_DataMap.dataDesc = &dataDesc_15[1];
  return &AIBehaviorChannelSaveHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10045FF0
// Name: struct datamap_t __near * DataMapInit<struct AI_FollowNavInfo_t>(struct AI_FollowNavInfo_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AI_FollowNavInfo_t>()
{
  if ( (_S2_9 & 1) == 0 )
  {
    _S2_9 |= 1u;
    nameHolder_23.m_pszBase = "AI_FollowNavInfo_t";
    nameHolder_23.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_23.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_23.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_23.m_Names.m_Size = 0;
    nameHolder_23.m_Names.m_pElements = nullptr;
    nameHolder_23.m_nLenBase = 18;
    atexit(func: DataMapInit_AI_FollowNavInfo_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AI_FollowNavInfo_t::m_DataMap.baseMap = nullptr;
  AI_FollowNavInfo_t::m_DataMap.dataNumFields = 12;
  AI_FollowNavInfo_t::m_DataMap.dataDesc = &dataDesc_23[1];
  return &AI_FollowNavInfo_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10046070
// Name: struct datamap_t __near * DataMapInit<struct AI_FollowParams_t>(struct AI_FollowParams_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AI_FollowParams_t>()
{
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    nameHolder_24.m_pszBase = "AI_FollowParams_t";
    nameHolder_24.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_24.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_24.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_24.m_Names.m_Size = 0;
    nameHolder_24.m_Names.m_pElements = nullptr;
    nameHolder_24.m_nLenBase = 17;
    atexit(func: DataMapInit_AI_FollowParams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AI_FollowParams_t::m_DataMap.baseMap = nullptr;
  AI_FollowParams_t::m_DataMap.dataNumFields = 2;
  AI_FollowParams_t::m_DataMap.dataDesc = &dataDesc_24[1];
  return &AI_FollowParams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10047D70
// Name: struct datamap_t __near * DataMapInit<struct AI_LeadArgs_t>(struct AI_LeadArgs_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AI_LeadArgs_t>()
{
  if ( (_S2_10 & 1) == 0 )
  {
    _S2_10 |= 1u;
    nameHolder_27.m_pszBase = "AI_LeadArgs_t";
    nameHolder_27.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_27.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_27.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_27.m_Names.m_Size = 0;
    nameHolder_27.m_Names.m_pElements = nullptr;
    nameHolder_27.m_nLenBase = 13;
    atexit(func: DataMapInit_AI_LeadArgs_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AI_LeadArgs_t::m_DataMap.baseMap = nullptr;
  AI_LeadArgs_t::m_DataMap.dataNumFields = 6;
  AI_LeadArgs_t::m_DataMap.dataDesc = &dataDesc_27[1];
  return &AI_LeadArgs_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100494D0
// Name: struct datamap_t __near * DataMapInit<struct AI_StandoffParams_t>(struct AI_StandoffParams_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AI_StandoffParams_t>()
{
  if ( (_S3_8 & 1) == 0 )
  {
    _S3_8 |= 1u;
    nameHolder_34.m_pszBase = "AI_StandoffParams_t";
    nameHolder_34.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_34.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_34.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_34.m_Names.m_Size = 0;
    nameHolder_34.m_Names.m_pElements = nullptr;
    nameHolder_34.m_nLenBase = 19;
    atexit(func: DataMapInit_AI_StandoffParams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AI_StandoffParams_t::m_DataMap.baseMap = nullptr;
  AI_StandoffParams_t::m_DataMap.dataNumFields = 10;
  AI_StandoffParams_t::m_DataMap.dataDesc = &dataDesc_34[1];
  return &AI_StandoffParams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100579F0
// Name: struct datamap_t __near * DataMapInit<struct HintNodeData>(struct HintNodeData __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<HintNodeData>()
{
  if ( (_S2_18 & 1) == 0 )
  {
    _S2_18 |= 1u;
    nameHolder_45.m_pszBase = "HintNodeData";
    nameHolder_45.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_45.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_45.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_45.m_Names.m_Size = 0;
    nameHolder_45.m_Names.m_pElements = nullptr;
    nameHolder_45.m_nLenBase = 12;
    atexit(func: DataMapInit_HintNodeData__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  HintNodeData::m_DataMap.baseMap = nullptr;
  HintNodeData::m_DataMap.dataNumFields = 13;
  HintNodeData::m_DataMap.dataDesc = &dataDesc_44[1];
  return &HintNodeData::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1005B490
// Name: struct datamap_t __near * DataMapInit<struct AI_EnemyInfo_t>(struct AI_EnemyInfo_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AI_EnemyInfo_t>()
{
  if ( (_S3_12 & 1) == 0 )
  {
    _S3_12 |= 1u;
    nameHolder_50.m_pszBase = "AI_EnemyInfo_t";
    nameHolder_50.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_50.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_50.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_50.m_Names.m_Size = 0;
    nameHolder_50.m_Names.m_pElements = nullptr;
    nameHolder_50.m_nLenBase = 14;
    atexit(func: DataMapInit_AI_EnemyInfo_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AI_EnemyInfo_t::m_DataMap.baseMap = nullptr;
  AI_EnemyInfo_t::m_DataMap.dataNumFields = 14;
  AI_EnemyInfo_t::m_DataMap.dataDesc = &dataDesc_48[1];
  return &AI_EnemyInfo_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10089000
// Name: struct datamap_t __near * DataMapInit<struct ConceptHistory_t>(struct ConceptHistory_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<ConceptHistory_t>()
{
  if ( (_S2_34 & 1) == 0 )
  {
    _S2_34 |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int,CUtlMap<char const *,ConceptHistory_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = (int)"ConceptHistory_t";
    `CUtlRBTree<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int,CUtlMap<char const *,ConceptHistory_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = 0;
    `CUtlRBTree<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int,CUtlMap<char const *,ConceptHistory_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = nullptr;
    unk_105E4EF0 = 0;
    unk_105E4EF4 = 0;
    unk_105E4EF8 = 0;
    `CUtlRBTree<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int,CUtlMap<char const *,ConceptHistory_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = 16;
    atexit(func: DataMapInit_ConceptHistory_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  ConceptHistory_t::m_DataMap.baseMap = nullptr;
  ConceptHistory_t::m_DataMap.dataNumFields = 1;
  ConceptHistory_t::m_DataMap.dataDesc = &dataDesc_64[1];
  return &ConceptHistory_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1008C2E0
// Name: struct datamap_t __near * DataMapInit<struct AISquadEnemyInfo_t>(struct AISquadEnemyInfo_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AISquadEnemyInfo_t>()
{
  if ( (_S2_36 & 1) == 0 )
  {
    _S2_36 |= 1u;
    nameHolder_70.m_pszBase = "AISquadEnemyInfo_t";
    nameHolder_70.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_70.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_70.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_70.m_Names.m_Size = 0;
    nameHolder_70.m_Names.m_pElements = nullptr;
    nameHolder_70.m_nLenBase = 18;
    atexit(func: DataMapInit_AISquadEnemyInfo_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AISquadEnemyInfo_t::m_DataMap.baseMap = nullptr;
  if ( (_S2_36 & 2) == 0 )
  {
    _S2_36 |= 2u;
    if ( (`GetBitstringDataOps<CBitVec<32>>'::`2'::`local static guard' & 1) == 0 )
    {
      `GetBitstringDataOps<CBitVec<32>>'::`2'::`local static guard' |= 1u;
      `GetBitstringDataOps<CBitVec<32>>'::`2'::ops = (int)&CVarBitVecSaveRestoreOps<CBitVec<32>>::`vftable';
    }
    dataDesc_67[2].pSaveRestoreOps = (ISaveRestoreOps *)&`GetBitstringDataOps<CBitVec<32>>'::`2'::ops;
    dataDesc_67[2].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_67[2].td = 0;
    *(_QWORD *)&dataDesc_67[2].override_field = 0;
    *(_QWORD *)&dataDesc_67[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_67[2].flatOffset[1] = 0;
  }
  AISquadEnemyInfo_t::m_DataMap.dataNumFields = 2;
  AISquadEnemyInfo_t::m_DataMap.dataDesc = &dataDesc_67[1];
  return &AISquadEnemyInfo_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10090790
// Name: struct datamap_t __near * DataMapInit<struct AI_FreePassParams_t>(struct AI_FreePassParams_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AI_FreePassParams_t>()
{
  if ( (_S5_3 & 1) == 0 )
  {
    _S5_3 |= 1u;
    nameHolder_77.m_pszBase = "AI_FreePassParams_t";
    nameHolder_77.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_77.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_77.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_77.m_Names.m_Size = 0;
    nameHolder_77.m_Names.m_pElements = nullptr;
    nameHolder_77.m_nLenBase = 19;
    atexit(func: DataMapInit_AI_FreePassParams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AI_FreePassParams_t::m_DataMap.baseMap = nullptr;
  AI_FreePassParams_t::m_DataMap.dataNumFields = 9;
  AI_FreePassParams_t::m_DataMap.dataDesc = &dataDesc_74[1];
  return &AI_FreePassParams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10090B70
// Name: struct datamap_t __near * DataMapInit<struct AI_Waypoint_t>(struct AI_Waypoint_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<AI_Waypoint_t>()
{
  if ( (_S2_40 & 1) == 0 )
  {
    _S2_40 |= 1u;
    nameHolder_79.m_pszBase = "AI_Waypoint_t";
    nameHolder_79.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_79.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_79.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_79.m_Names.m_Size = 0;
    nameHolder_79.m_Names.m_pElements = nullptr;
    nameHolder_79.m_nLenBase = 13;
    atexit(func: DataMapInit_AI_Waypoint_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  AI_Waypoint_t::m_DataMap.baseMap = nullptr;
  AI_Waypoint_t::m_DataMap.dataNumFields = 6;
  AI_Waypoint_t::m_DataMap.dataDesc = &dataDesc_76[1];
  return &AI_Waypoint_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100AA3D0
// Name: struct datamap_t __near * DataMapInit<struct Relationship_t>(struct Relationship_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<Relationship_t>()
{
  if ( (_S3_23 & 1) == 0 )
  {
    _S3_23 |= 1u;
    nameHolder_87.m_pszBase = "Relationship_t";
    nameHolder_87.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_87.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_87.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_87.m_Names.m_Size = 0;
    nameHolder_87.m_Names.m_pElements = nullptr;
    nameHolder_87.m_nLenBase = 14;
    atexit(func: DataMapInit_Relationship_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  Relationship_t::m_DataMap.baseMap = nullptr;
  Relationship_t::m_DataMap.dataNumFields = 5;
  Relationship_t::m_DataMap.dataDesc = &dataDesc_84[1];
  return &Relationship_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100C04E0
// Name: struct datamap_t __near * DataMapInit<struct thinkfunc_t>(struct thinkfunc_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<thinkfunc_t>()
{
  if ( (_S4_13 & 1) == 0 )
  {
    _S4_13 |= 1u;
    nameHolder_89.m_pszBase = "thinkfunc_t";
    nameHolder_89.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_89.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_89.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_89.m_Names.m_Size = 0;
    nameHolder_89.m_Names.m_pElements = nullptr;
    nameHolder_89.m_nLenBase = 11;
    atexit(func: DataMapInit_thinkfunc_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  thinkfunc_t::m_DataMap.baseMap = nullptr;
  thinkfunc_t::m_DataMap.dataNumFields = 3;
  thinkfunc_t::m_DataMap.dataDesc = &dataDesc_86[1];
  return &thinkfunc_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100C0560
// Name: struct datamap_t __near * DataMapInit<struct ResponseContext_t>(struct ResponseContext_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<ResponseContext_t>()
{
  if ( (_S5_8 & 1) == 0 )
  {
    _S5_8 |= 1u;
    nameHolder_90.m_pszBase = "ResponseContext_t";
    nameHolder_90.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_90.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_90.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_90.m_Names.m_Size = 0;
    nameHolder_90.m_Names.m_pElements = nullptr;
    nameHolder_90.m_nLenBase = 17;
    atexit(func: DataMapInit_ResponseContext_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  ResponseContext_t::m_DataMap.baseMap = nullptr;
  ResponseContext_t::m_DataMap.dataNumFields = 3;
  ResponseContext_t::m_DataMap.dataDesc = &dataDesc_87[1];
  return &ResponseContext_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100D46E0
// Name: struct datamap_t __near * DataMapInit<struct flexsettinghdr_t>(struct flexsettinghdr_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<flexsettinghdr_t>()
{
  if ( (_S5_9 & 1) == 0 )
  {
    _S5_9 |= 1u;
    nameHolder_93.m_pszBase = "flexsettinghdr_t";
    nameHolder_93.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_93.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_93.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_93.m_Names.m_Size = 0;
    nameHolder_93.m_Names.m_pElements = nullptr;
    nameHolder_93.m_nLenBase = 16;
    atexit(func: DataMapInit_flexsettinghdr_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  flexsettinghdr_t::m_DataMap.baseMap = nullptr;
  flexsettinghdr_t::m_DataMap.dataNumFields = 12;
  flexsettinghdr_t::m_DataMap.dataDesc = &dataDesc_90[1];
  return &flexsettinghdr_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100D4760
// Name: struct datamap_t __near * DataMapInit<struct flexsetting_t>(struct flexsetting_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<flexsetting_t>()
{
  if ( (_S6_7 & 1) == 0 )
  {
    _S6_7 |= 1u;
    nameHolder_94.m_pszBase = "flexsetting_t";
    nameHolder_94.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_94.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_94.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_94.m_Names.m_Size = 0;
    nameHolder_94.m_Names.m_pElements = nullptr;
    nameHolder_94.m_nLenBase = 13;
    atexit(func: DataMapInit_flexsetting_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  flexsetting_t::m_DataMap.baseMap = nullptr;
  flexsetting_t::m_DataMap.dataNumFields = 6;
  flexsetting_t::m_DataMap.dataDesc = &dataDesc_91[1];
  return &flexsetting_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100D47E0
// Name: struct datamap_t __near * DataMapInit<struct flexweight_t>(struct flexweight_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<flexweight_t>()
{
  if ( (_S7_2 & 1) == 0 )
  {
    _S7_2 |= 1u;
    nameHolder_95.m_pszBase = "flexweight_t";
    nameHolder_95.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_95.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_95.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_95.m_Names.m_Size = 0;
    nameHolder_95.m_Names.m_pElements = nullptr;
    nameHolder_95.m_nLenBase = 12;
    atexit(func: DataMapInit_flexweight_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  flexweight_t::m_DataMap.baseMap = nullptr;
  flexweight_t::m_DataMap.dataNumFields = 3;
  flexweight_t::m_DataMap.dataDesc = &dataDesc_92[1];
  return &flexweight_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100EA0F0
// Name: struct datamap_t __near * DataMapInit<struct EventQueuePrioritizedEvent_t>(struct EventQueuePrioritizedEvent_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<EventQueuePrioritizedEvent_t>()
{
  if ( (_S5_11 & 1) == 0 )
  {
    _S5_11 |= 1u;
    nameHolder_112.m_pszBase = "EventQueuePrioritizedEvent_t";
    nameHolder_112.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_112.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_112.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_112.m_Names.m_Size = 0;
    nameHolder_112.m_Names.m_pElements = nullptr;
    nameHolder_112.m_nLenBase = 28;
    atexit(func: DataMapInit_EventQueuePrioritizedEvent_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  EventQueuePrioritizedEvent_t::m_DataMap.baseMap = nullptr;
  if ( (_S5_11 & 2) == 0 )
  {
    _S5_11 |= 2u;
    dataDesc_109[8].pSaveRestoreOps = variantFuncs;
    dataDesc_109[8].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_109[8].td = 0;
    *(_QWORD *)&dataDesc_109[8].override_field = 0;
    *(_QWORD *)&dataDesc_109[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_109[8].flatOffset[1] = 0;
  }
  EventQueuePrioritizedEvent_t::m_DataMap.dataNumFields = 8;
  EventQueuePrioritizedEvent_t::m_DataMap.dataDesc = &dataDesc_109[1];
  return &EventQueuePrioritizedEvent_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F8790
// Name: struct datamap_t __near * DataMapInit<struct modifiedconvars_t>(struct modifiedconvars_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<modifiedconvars_t>()
{
  if ( (_S5_12 & 1) == 0 )
  {
    _S5_12 |= 1u;
    nameHolder_121.m_pszBase = "modifiedconvars_t";
    nameHolder_121.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_121.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_121.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_121.m_Names.m_Size = 0;
    nameHolder_121.m_Names.m_pElements = nullptr;
    nameHolder_121.m_nLenBase = 17;
    atexit(func: DataMapInit_modifiedconvars_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  modifiedconvars_t::m_DataMap.baseMap = nullptr;
  modifiedconvars_t::m_DataMap.dataNumFields = 3;
  modifiedconvars_t::m_DataMap.dataDesc = &dataDesc_116[1];
  return &modifiedconvars_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F9880
// Name: struct datamap_t __near * DataMapInit<struct CompiledCaptionHeader_t>(struct CompiledCaptionHeader_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CompiledCaptionHeader_t>()
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    nameHolder_124.m_pszBase = "CompiledCaptionHeader_t";
    nameHolder_124.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_124.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_124.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_124.m_Names.m_Size = 0;
    nameHolder_124.m_Names.m_pElements = nullptr;
    nameHolder_124.m_nLenBase = 23;
    atexit(func: DataMapInit_CompiledCaptionHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CompiledCaptionHeader_t::m_DataMap.baseMap = nullptr;
  CompiledCaptionHeader_t::m_DataMap.dataNumFields = 6;
  CompiledCaptionHeader_t::m_DataMap.dataDesc = &dataDesc_119[1];
  return &CompiledCaptionHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F9900
// Name: struct datamap_t __near * DataMapInit<struct CaptionLookup_t>(struct CaptionLookup_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CaptionLookup_t>()
{
  if ( (_S2_67 & 1) == 0 )
  {
    _S2_67 |= 1u;
    nameHolder_125.m_pszBase = "CaptionLookup_t";
    nameHolder_125.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_125.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_125.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_125.m_Names.m_Size = 0;
    nameHolder_125.m_Names.m_pElements = nullptr;
    nameHolder_125.m_nLenBase = 15;
    atexit(func: DataMapInit_CaptionLookup_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CaptionLookup_t::m_DataMap.baseMap = nullptr;
  CaptionLookup_t::m_DataMap.dataNumFields = 4;
  CaptionLookup_t::m_DataMap.dataDesc = &dataDesc_120[1];
  return &CaptionLookup_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10110A10
// Name: struct datamap_t __near * DataMapInit<struct EntityParticleTrailInfo_t>(struct EntityParticleTrailInfo_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<EntityParticleTrailInfo_t>()
{
  if ( (_S2_78 & 1) == 0 )
  {
    _S2_78 |= 1u;
    nameHolder_156.m_pszBase = "EntityParticleTrailInfo_t";
    nameHolder_156.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_156.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_156.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_156.m_Names.m_Size = 0;
    nameHolder_156.m_Names.m_pElements = nullptr;
    nameHolder_156.m_nLenBase = 25;
    atexit(func: DataMapInit_EntityParticleTrailInfo_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  EntityParticleTrailInfo_t::m_DataMap.baseMap = nullptr;
  EntityParticleTrailInfo_t::m_DataMap.dataNumFields = 4;
  EntityParticleTrailInfo_t::m_DataMap.dataDesc = &dataDesc_148[1];
  return &EntityParticleTrailInfo_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10159770
// Name: struct datamap_t __near * DataMapInit<struct globalentity_t>(struct globalentity_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<globalentity_t>()
{
  if ( (_S3_73 & 1) == 0 )
  {
    _S3_73 |= 1u;
    nameHolder_232.m_pszBase = "globalentity_t";
    nameHolder_232.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_232.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_232.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_232.m_Names.m_Size = 0;
    nameHolder_232.m_Names.m_pElements = nullptr;
    nameHolder_232.m_nLenBase = 14;
    atexit(func: DataMapInit_globalentity_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  globalentity_t::m_DataMap.baseMap = nullptr;
  globalentity_t::m_DataMap.dataNumFields = 4;
  globalentity_t::m_DataMap.dataDesc = &dataDesc_219[1];
  return &globalentity_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1018DF70
// Name: struct datamap_t __near * DataMapInit<struct physfollower_t>(struct physfollower_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<physfollower_t>()
{
  if ( (_S2_163 & 1) == 0 )
  {
    _S2_163 |= 1u;
    nameHolder_304.m_pszBase = "physfollower_t";
    nameHolder_304.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_304.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_304.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_304.m_Names.m_Size = 0;
    nameHolder_304.m_Names.m_pElements = nullptr;
    nameHolder_304.m_nLenBase = 14;
    atexit(func: DataMapInit_physfollower_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  physfollower_t::m_DataMap.baseMap = nullptr;
  physfollower_t::m_DataMap.dataNumFields = 2;
  physfollower_t::m_DataMap.dataDesc = &dataDesc_291[1];
  return &physfollower_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101A6B40
// Name: struct datamap_t __near * DataMapInit<struct PhysBlockHeader_t>(struct PhysBlockHeader_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<PhysBlockHeader_t>()
{
  if ( (_S2_169 & 1) == 0 )
  {
    _S2_169 |= 1u;
    nameHolder_314.m_pszBase = "PhysBlockHeader_t";
    nameHolder_314.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_314.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_314.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_314.m_Names.m_Size = 0;
    nameHolder_314.m_Names.m_pElements = nullptr;
    nameHolder_314.m_nLenBase = 17;
    atexit(func: DataMapInit_PhysBlockHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  PhysBlockHeader_t::m_DataMap.baseMap = nullptr;
  PhysBlockHeader_t::m_DataMap.dataNumFields = 2;
  PhysBlockHeader_t::m_DataMap.dataDesc = &dataDesc_301[1];
  return &PhysBlockHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101A6BC0
// Name: struct datamap_t __near * DataMapInit<struct PhysObjectHeader_t>(struct PhysObjectHeader_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<PhysObjectHeader_t>()
{
  if ( (_S3_93 & 1) == 0 )
  {
    _S3_93 |= 1u;
    nameHolder_315.m_pszBase = "PhysObjectHeader_t";
    nameHolder_315.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_315.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_315.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_315.m_Names.m_Size = 0;
    nameHolder_315.m_Names.m_pElements = nullptr;
    nameHolder_315.m_nLenBase = 18;
    atexit(func: DataMapInit_PhysObjectHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  PhysObjectHeader_t::m_DataMap.baseMap = nullptr;
  PhysObjectHeader_t::m_DataMap.dataNumFields = 9;
  PhysObjectHeader_t::m_DataMap.dataDesc = &dataDesc_302[1];
  return &PhysObjectHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B2EB0
// Name: struct datamap_t __near * DataMapInit<struct magnetted_objects_t>(struct magnetted_objects_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<magnetted_objects_t>()
{
  ISaveRestoreOps *PhysObjSaveRestoreOps; // eax

  if ( (_S8_8 & 1) == 0 )
  {
    _S8_8 |= 1u;
    nameHolder_321.m_pszBase = "magnetted_objects_t";
    nameHolder_321.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_321.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_321.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_321.m_Names.m_Size = 0;
    nameHolder_321.m_Names.m_pElements = nullptr;
    nameHolder_321.m_nLenBase = 19;
    atexit(func: DataMapInit_magnetted_objects_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  magnetted_objects_t::m_DataMap.baseMap = nullptr;
  if ( (_S8_8 & 2) == 0 )
  {
    _S8_8 |= 2u;
    PhysObjSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_308[1].td = 0;
    *(_QWORD *)&dataDesc_308[1].override_field = 0;
    *(_QWORD *)&dataDesc_308[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_308[1].flatOffset[1] = 0;
    dataDesc_308[1].pSaveRestoreOps = PhysObjSaveRestoreOps;
    dataDesc_308[2].fieldTolerance = 0.0;
    dataDesc_308[1].inputFunc = nullptr;
    dataDesc_308[2].fieldType = FIELD_EHANDLE;
    dataDesc_308[2].fieldName = "hEntity";
    dataDesc_308[2].fieldOffset = 4;
    *(_DWORD *)&dataDesc_308[2].fieldSize = 131073;
    dataDesc_308[2].externalName = nullptr;
    dataDesc_308[2].pSaveRestoreOps = nullptr;
    dataDesc_308[2].inputFunc = nullptr;
    dataDesc_308[2].td = nullptr;
    dataDesc_308[2].fieldSizeInBytes = 4;
    dataDesc_308[2].override_field = nullptr;
    dataDesc_308[2].override_count = 0;
    *(_QWORD *)dataDesc_308[2].flatOffset = 0;
    *(_DWORD *)&dataDesc_308[2].flatGroup = 0;
  }
  magnetted_objects_t::m_DataMap.dataNumFields = 2;
  magnetted_objects_t::m_DataMap.dataDesc = &dataDesc_308[1];
  return &magnetted_objects_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D0900
// Name: struct datamap_t __near * DataMapInit<struct fogplayerparams_t>(struct fogplayerparams_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<fogplayerparams_t>()
{
  if ( (_S3_97 & 1) == 0 )
  {
    _S3_97 |= 1u;
    nameHolder_329.m_pszBase = "fogplayerparams_t";
    nameHolder_329.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_329.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_329.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_329.m_Names.m_Size = 0;
    nameHolder_329.m_Names.m_pElements = nullptr;
    nameHolder_329.m_nLenBase = 17;
    atexit(func: DataMapInit_fogplayerparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  fogplayerparams_t::m_DataMap.baseMap = nullptr;
  fogplayerparams_t::m_DataMap.dataNumFields = 8;
  fogplayerparams_t::m_DataMap.dataDesc = &dataDesc_315[1];
  return &fogplayerparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D0980
// Name: struct datamap_t __near * DataMapInit<struct fogparams_t>(struct fogparams_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<fogparams_t>()
{
  if ( (_S4_48 & 1) == 0 )
  {
    _S4_48 |= 1u;
    nameHolder_330.m_pszBase = "fogparams_t";
    nameHolder_330.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_330.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_330.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_330.m_Names.m_Size = 0;
    nameHolder_330.m_Names.m_pElements = nullptr;
    nameHolder_330.m_nLenBase = 11;
    atexit(func: DataMapInit_fogparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  fogparams_t::m_DataMap.baseMap = nullptr;
  fogparams_t::m_DataMap.dataNumFields = 16;
  fogparams_t::m_DataMap.dataDesc = &dataDesc_316[1];
  return &fogparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D0A00
// Name: struct datamap_t __near * DataMapInit<struct sky3dparams_t>(struct sky3dparams_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<sky3dparams_t>()
{
  if ( (_S5_26 & 1) == 0 )
  {
    _S5_26 |= 1u;
    nameHolder_331.m_pszBase = "sky3dparams_t";
    nameHolder_331.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_331.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_331.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_331.m_Names.m_Size = 0;
    nameHolder_331.m_Names.m_pElements = nullptr;
    nameHolder_331.m_nLenBase = 13;
    atexit(func: DataMapInit_sky3dparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  sky3dparams_t::m_DataMap.baseMap = nullptr;
  sky3dparams_t::m_DataMap.dataNumFields = 4;
  sky3dparams_t::m_DataMap.dataDesc = &dataDesc_317[1];
  return &sky3dparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D0A80
// Name: struct datamap_t __near * DataMapInit<struct audioparams_t>(struct audioparams_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<audioparams_t>()
{
  if ( (_S6_20 & 1) == 0 )
  {
    _S6_20 |= 1u;
    nameHolder_332.m_pszBase = "audioparams_t";
    nameHolder_332.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_332.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_332.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_332.m_Names.m_Size = 0;
    nameHolder_332.m_Names.m_pElements = nullptr;
    nameHolder_332.m_nLenBase = 13;
    atexit(func: DataMapInit_audioparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  audioparams_t::m_DataMap.baseMap = nullptr;
  audioparams_t::m_DataMap.dataNumFields = 4;
  audioparams_t::m_DataMap.dataDesc = &dataDesc_318[1];
  return &audioparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D79A0
// Name: struct datamap_t __near * DataMapInit<struct template_t>(struct template_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<template_t>()
{
  if ( (_S2_181 & 1) == 0 )
  {
    _S2_181 |= 1u;
    nameHolder_341.m_pszBase = "template_t";
    nameHolder_341.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_341.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_341.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_341.m_Names.m_Size = 0;
    nameHolder_341.m_Names.m_pElements = nullptr;
    nameHolder_341.m_nLenBase = 10;
    atexit(func: DataMapInit_template_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  template_t::m_DataMap.baseMap = nullptr;
  template_t::m_DataMap.dataNumFields = 2;
  template_t::m_DataMap.dataDesc = &dataDesc_326[1];
  return &template_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101E7E70
// Name: struct datamap_t __near * DataMapInit<struct locksound_t>(struct locksound_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<locksound_t>()
{
  if ( (_S10_4 & 1) == 0 )
  {
    _S10_4 |= 1u;
    nameHolder_351.m_pszBase = "locksound_t";
    nameHolder_351.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_351.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_351.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_351.m_Names.m_Size = 0;
    nameHolder_351.m_Names.m_pElements = nullptr;
    nameHolder_351.m_nLenBase = 11;
    atexit(func: DataMapInit_locksound_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  locksound_t::m_DataMap.baseMap = nullptr;
  locksound_t::m_DataMap.dataNumFields = 10;
  locksound_t::m_DataMap.dataDesc = &dataDesc_336[1];
  return &locksound_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101FD370
// Name: struct datamap_t __near * DataMapInit<struct entitytable_t>(struct entitytable_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<entitytable_t>()
{
  if ( (_S2_194 & 1) == 0 )
  {
    _S2_194 |= 1u;
    nameHolder_366.m_pszBase = "entitytable_t";
    nameHolder_366.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_366.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_366.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_366.m_Names.m_Size = 0;
    nameHolder_366.m_Names.m_pElements = nullptr;
    nameHolder_366.m_nLenBase = 13;
    atexit(func: DataMapInit_entitytable_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  entitytable_t::m_DataMap.baseMap = nullptr;
  entitytable_t::m_DataMap.dataNumFields = 10;
  entitytable_t::m_DataMap.dataDesc = &dataDesc_349[1];
  return &entitytable_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101FD630
// Name: struct datamap_t __near * DataMapInit<struct SaveRestoreBlockHeader_t>(struct SaveRestoreBlockHeader_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<SaveRestoreBlockHeader_t>()
{
  if ( (_S3_109 & 1) == 0 )
  {
    _S3_109 |= 1u;
    nameHolder_367.m_pszBase = "SaveRestoreBlockHeader_t";
    nameHolder_367.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_367.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_367.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_367.m_Names.m_Size = 0;
    nameHolder_367.m_Names.m_pElements = nullptr;
    nameHolder_367.m_nLenBase = 24;
    atexit(func: DataMapInit_SaveRestoreBlockHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  SaveRestoreBlockHeader_t::m_DataMap.baseMap = nullptr;
  SaveRestoreBlockHeader_t::m_DataMap.dataNumFields = 3;
  SaveRestoreBlockHeader_t::m_DataMap.dataDesc = &dataDesc_350[1];
  return &SaveRestoreBlockHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1021E690
// Name: struct datamap_t __near * DataMapInit<struct SoundCommand_t>(struct SoundCommand_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<SoundCommand_t>()
{
  if ( (_S5_30 & 1) == 0 )
  {
    _S5_30 |= 1u;
    nameHolder_393.m_pszBase = "SoundCommand_t";
    nameHolder_393.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_393.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_393.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_393.m_Names.m_Size = 0;
    nameHolder_393.m_Names.m_pElements = nullptr;
    nameHolder_393.m_nLenBase = 14;
    atexit(func: DataMapInit_SoundCommand_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  SoundCommand_t::m_DataMap.baseMap = nullptr;
  SoundCommand_t::m_DataMap.dataNumFields = 4;
  SoundCommand_t::m_DataMap.dataDesc = &dataDesc_376[1];
  return &SoundCommand_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10232230
// Name: struct datamap_t __near * DataMapInit<struct TemplateEntityData_t>(struct TemplateEntityData_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<TemplateEntityData_t>()
{
  if ( (_S2_221 & 1) == 0 )
  {
    _S2_221 |= 1u;
    nameHolder_415.m_pszBase = "TemplateEntityData_t";
    nameHolder_415.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_415.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_415.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_415.m_Names.m_Size = 0;
    nameHolder_415.m_Names.m_pElements = nullptr;
    nameHolder_415.m_nLenBase = 20;
    atexit(func: DataMapInit_TemplateEntityData_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  TemplateEntityData_t::m_DataMap.baseMap = nullptr;
  TemplateEntityData_t::m_DataMap.dataNumFields = 3;
  TemplateEntityData_t::m_DataMap.dataDesc = &dataDesc_395[1];
  return &TemplateEntityData_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1025A390
// Name: struct datamap_t __near * DataMapInit<struct vehicle_gear_t>(struct vehicle_gear_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vehicle_gear_t>()
{
  if ( (_S2_231 & 1) == 0 )
  {
    _S2_231 |= 1u;
    nameHolder_456.m_pszBase = "vehicle_gear_t";
    nameHolder_456.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_456.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_456.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_456.m_Names.m_Size = 0;
    nameHolder_456.m_Names.m_pElements = nullptr;
    nameHolder_456.m_nLenBase = 14;
    atexit(func: DataMapInit_vehicle_gear_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vehicle_gear_t::m_DataMap.baseMap = nullptr;
  vehicle_gear_t::m_DataMap.dataNumFields = 3;
  vehicle_gear_t::m_DataMap.dataDesc = &dataDesc_427[1];
  return &vehicle_gear_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1025A410
// Name: struct datamap_t __near * DataMapInit<struct vehicle_crashsound_t>(struct vehicle_crashsound_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vehicle_crashsound_t>()
{
  if ( (_S3_139 & 1) == 0 )
  {
    _S3_139 |= 1u;
    nameHolder_457.m_pszBase = "vehicle_crashsound_t";
    nameHolder_457.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_457.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_457.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_457.m_Names.m_Size = 0;
    nameHolder_457.m_Names.m_pElements = nullptr;
    nameHolder_457.m_nLenBase = 20;
    atexit(func: DataMapInit_vehicle_crashsound_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vehicle_crashsound_t::m_DataMap.baseMap = nullptr;
  vehicle_crashsound_t::m_DataMap.dataNumFields = 4;
  vehicle_crashsound_t::m_DataMap.dataDesc = &dataDesc_428[1];
  return &vehicle_crashsound_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1025A490
// Name: struct datamap_t __near * DataMapInit<struct vehiclesounds_t>(struct vehiclesounds_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vehiclesounds_t>()
{
  if ( (_S4_66 & 1) == 0 )
  {
    _S4_66 |= 1u;
    nameHolder_458.m_pszBase = "vehiclesounds_t";
    nameHolder_458.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_458.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_458.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_458.m_Names.m_Size = 0;
    nameHolder_458.m_Names.m_pElements = nullptr;
    nameHolder_458.m_nLenBase = 15;
    atexit(func: DataMapInit_vehiclesounds_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vehiclesounds_t::m_DataMap.baseMap = nullptr;
  if ( (_S4_66 & 2) == 0 )
  {
    _S4_66 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>,10>::`vftable';
    }
    dataDesc_429[2].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>>'::`2'::ops;
    dataDesc_429[2].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_429[2].td = 0;
    *(_QWORD *)&dataDesc_429[2].override_field = 0;
    *(_QWORD *)&dataDesc_429[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_429[2].flatOffset[1] = 0;
    dataDesc_429[3].fieldType = FIELD_CUSTOM;
    dataDesc_429[3].fieldName = "crashSounds";
    dataDesc_429[3].fieldOffset = 24;
    dataDesc_429[3].fieldSize = 1;
    dataDesc_429[3].flags = 2;
    dataDesc_429[3].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>,10>::`vftable';
    }
    *(_QWORD *)&dataDesc_429[3].td = 0;
    *(_QWORD *)&dataDesc_429[3].override_field = 0;
    *(_QWORD *)&dataDesc_429[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_429[3].flatOffset[1] = 0;
    dataDesc_429[4].fieldSize = 20;
    dataDesc_429[4].fieldTolerance = 0.0;
    dataDesc_429[5].fieldTolerance = 0.0;
    dataDesc_429[3].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>>'::`2'::ops;
    dataDesc_429[3].inputFunc = nullptr;
    dataDesc_429[4].fieldType = FIELD_STRING;
    dataDesc_429[4].fieldName = "iszStateSounds";
    dataDesc_429[4].fieldOffset = 80;
    dataDesc_429[4].flags = 2;
    dataDesc_429[4].externalName = nullptr;
    dataDesc_429[4].pSaveRestoreOps = nullptr;
    dataDesc_429[4].inputFunc = nullptr;
    dataDesc_429[4].td = nullptr;
    dataDesc_429[4].fieldSizeInBytes = 80;
    dataDesc_429[4].override_field = nullptr;
    dataDesc_429[4].override_count = 0;
    *(_QWORD *)dataDesc_429[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_429[4].flatGroup = 0;
    dataDesc_429[5].fieldType = FIELD_FLOAT;
    dataDesc_429[5].fieldName = "minStateTime";
    dataDesc_429[5].fieldOffset = 160;
    *(_DWORD *)&dataDesc_429[5].fieldSize = 131092;
    dataDesc_429[5].externalName = nullptr;
    dataDesc_429[5].pSaveRestoreOps = nullptr;
    dataDesc_429[5].inputFunc = nullptr;
    dataDesc_429[5].td = nullptr;
    dataDesc_429[5].fieldSizeInBytes = 80;
    dataDesc_429[5].override_field = nullptr;
    dataDesc_429[5].override_count = 0;
    *(_QWORD *)dataDesc_429[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_429[5].flatGroup = 0;
  }
  vehiclesounds_t::m_DataMap.dataNumFields = 5;
  vehiclesounds_t::m_DataMap.dataDesc = &dataDesc_429[1];
  return &vehiclesounds_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1025C090
// Name: struct datamap_t __near * DataMapInit<struct ViewSmoothingData_t>(struct ViewSmoothingData_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<ViewSmoothingData_t>()
{
  if ( (_S2_232 & 1) == 0 )
  {
    _S2_232 |= 1u;
    nameHolder_461.m_pszBase = "ViewSmoothingData_t";
    nameHolder_461.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_461.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_461.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_461.m_Names.m_Size = 0;
    nameHolder_461.m_Names.m_pElements = nullptr;
    nameHolder_461.m_nLenBase = 19;
    atexit(func: DataMapInit_ViewSmoothingData_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  ViewSmoothingData_t::m_DataMap.baseMap = nullptr;
  ViewSmoothingData_t::m_DataMap.dataNumFields = 9;
  ViewSmoothingData_t::m_DataMap.dataDesc = &dataDesc_432[1];
  return &ViewSmoothingData_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102983E0
// Name: struct datamap_t __near * DataMapInit<struct JeepWaterData_t>(struct JeepWaterData_t __near *)
// Source: semantic_datamap_key
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<JeepWaterData_t>()
{
  if ( (_S2_247 & 1) == 0 )
  {
    _S2_247 |= 1u;
    nameHolder_475.m_pszBase = "JeepWaterData_t";
    nameHolder_475.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_475.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_475.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_475.m_Names.m_Size = 0;
    nameHolder_475.m_Names.m_pElements = nullptr;
    nameHolder_475.m_nLenBase = 15;
    atexit(func: DataMapInit_JeepWaterData_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  JeepWaterData_t::m_DataMap.baseMap = nullptr;
  JeepWaterData_t::m_DataMap.dataNumFields = 6;
  JeepWaterData_t::m_DataMap.dataDesc = &dataDesc_443[1];
  return &JeepWaterData_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10309700
// Name: private: virtual struct datamap_t __near * CFuncNavBlocker::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncNavBlocker::GetDataDescMap(CFuncNavBlocker *this)
{
  return &CFuncNavBlocker::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10309710
// Name: private: virtual struct datamap_t __near * CFuncNavObstruction::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncNavObstruction::GetDataDescMap(CFuncNavObstruction *this)
{
  return &CFuncNavObstruction::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10309720
// Name: public: virtual int CFuncNavObstruction::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFuncNavObstruction::DrawDebugTextOverlays(CFuncNavObstruction *this)
{
  int result; // eax
  int v3; // esi

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    if ( this->CanObstructNavAreas(this: &this->INavAvoidanceObstacle) )
      CBaseEntity::EntityText(
        this,
        text_offset: v3,
        text: "Obstructing nav",
        duration: 0.01023,
        r: 255,
        g: 255,
        b: 255,
        a: 255);
    else
      CBaseEntity::EntityText(
        this,
        text_offset: v3,
        text: "Not obstructing nav",
        duration: 0.01023,
        r: 255,
        g: 255,
        b: 255,
        a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10309790
// Name: public: virtual void CFuncNavObstruction::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncNavObstruction::UpdateOnRemove(CFuncNavObstruction *this)
{
  if ( this != nullptr )
  {
    CNavMesh::UnregisterAvoidanceObstacle(this: TheNavMesh, obstruction: &this->INavAvoidanceObstacle);
    CBaseEntity::UpdateOnRemove(this);
  }
  else
  {
    CNavMesh::UnregisterAvoidanceObstacle(this: TheNavMesh, obstruction: nullptr);
    CBaseEntity::UpdateOnRemove(this: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103097D0
// Name: public: virtual float CFuncNavObstruction::GetNavObstructionHeight(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CFuncNavObstruction::GetNavObstructionHeight(CFuncNavObstruction *this)
{
  return 58.0;
}

//------------------------------------------------------------------------------
// Address: 0x103097E0
// Name: public: virtual bool CFuncNavObstruction::CanObstructNavAreas(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFuncNavObstruction::CanObstructNavAreas(CFuncNavObstruction *this)
{
  return LOBYTE(this->m_pfnMoveDone) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x103097F0
// Name: public: virtual class CBaseEntity __near * CFuncNavObstruction::GetObstructingEntity(void)
// Source: json
//------------------------------------------------------------------------------
CFuncNavObstruction *__thiscall CFuncNavObstruction::GetObstructingEntity(CFuncNavObstruction *this)
{
  return (CFuncNavObstruction *)((char *)this - 852);
}

//------------------------------------------------------------------------------
// Address: 0x10309EF0
// Name: private: void CFuncNavBlocker::BlockNav(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncNavBlocker::BlockNav(CFuncNavBlocker *this)
{
  int m_blockedTeamNumber; // eax
  Extent extent; // [esp+4h] [ebp-18h] BYREF

  m_blockedTeamNumber = this->m_blockedTeamNumber;
  if ( m_blockedTeamNumber == -1 )
    *(_WORD *)this->m_isBlockingNav = 257;
  else
    this->m_isBlockingNav[m_blockedTeamNumber % 2] = true;
  this->m_Collision.WorldSpaceSurroundingBounds(this: &this->m_Collision, a2: (Vector *)&extent, a3: &extent.hi);
  CNavMesh::ForAllAreasOverlappingExtent<CFuncNavBlocker>(this: TheNavMesh, func: this, &extent);
}

//------------------------------------------------------------------------------
// Address: 0x10309F60
// Name: public: static bool CFuncNavBlocker::CalculateBlocked(bool __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CFuncNavBlocker::CalculateBlocked(bool *pResultByTeam, const Vector *vecMins, const Vector *vecMaxs)
{
  int m_Next; // eax
  UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short> *m_pMemory; // ecx
  int v5; // ebx
  const Vector *m_Element; // edi
  bool v7; // al
  int i; // esi
  int nTeamsBlocked; // [esp+0h] [ebp-8h]
  bool bBlocked; // [esp+7h] [ebp-1h]

  *(_WORD *)pResultByTeam = 0;
  LOWORD(m_Next) = CFuncNavBlocker::gm_NavBlockers.m_Head;
  nTeamsBlocked = 0;
  bBlocked = false;
  if ( CFuncNavBlocker::gm_NavBlockers.m_Head == 0xFFFF )
    return false;
  m_pMemory = CFuncNavBlocker::gm_NavBlockers.m_Memory.m_pMemory;
  do
  {
    v5 = (unsigned __int16)m_Next;
    m_Element = (const Vector *)m_pMemory[v5].m_Element;
    v7 = false;
    for ( i = 0; i < 2; ++i )
    {
      if ( *((_BYTE *)&m_Element[71].x + i) != 0
        && !pResultByTeam[i]
        && (v7
         || (v7 = IsBoxIntersectingBox(
                    boxMin1: m_Element + 72,
                    boxMax1: m_Element + 73,
                    boxMin2: vecMins,
                    boxMax2: vecMaxs))) )
      {
        ++nTeamsBlocked;
        bBlocked = true;
        pResultByTeam[i] = true;
      }
    }
    if ( nTeamsBlocked == 2 )
      break;
    m_pMemory = CFuncNavBlocker::gm_NavBlockers.m_Memory.m_pMemory;
    m_Next = CFuncNavBlocker::gm_NavBlockers.m_Memory.m_pMemory[v5].m_Next;
  }
  while ( m_Next != 0xFFFF );
  return bBlocked;
}

//------------------------------------------------------------------------------
// Address: 0x1030A040
// Name: public: void CFuncNavBlocker::InputBlockNav(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFuncNavBlocker::InputBlockNav(CFuncNavBlocker *this, inputdata_t *inputdata)
{
  CFuncNavBlocker::BlockNav(this);
}

//------------------------------------------------------------------------------
// Address: 0x1030A050
// Name: public: virtual void CFuncNavObstruction::OnNavMeshLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncNavObstruction::OnNavMeshLoaded(CFuncNavObstruction *this)
{
  CFuncNavObstruction *v1; // esi
  Extent extent; // [esp+0h] [ebp-18h] BYREF

  if ( LOBYTE(this->m_pfnMoveDone) == 0 )
  {
    v1 = (CFuncNavObstruction *)((char *)this - 852);
    (*(void (__thiscall **)(char *, Extent *, Vector *))(*((_DWORD *)&this->m_Collision - 213) + 60))(
      a1: (char *)&this->m_Collision - 852,
      a2: &extent,
      a3: &extent.hi);
    CNavMesh::ForAllAreasOverlappingExtent<CFuncNavObstruction>(this: TheNavMesh, func: v1, &extent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030A0A0
// Name: public: virtual void CFuncNavObstruction::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncNavObstruction::Spawn(CFuncNavObstruction *this)
{
  const char *v2; // eax
  Extent extent; // [esp+8h] [ebp-1Ch] BYREF
  _BYTE v4[4]; // [esp+20h] [ebp-4h] BYREF

  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CFuncNavObstruction *, _BYTE *))this->GetModelName)(a1: this, a2: v4);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CBaseEntity::AddEffects(this, nEffects: 32);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 0);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  if ( !this->m_bDisabled )
  {
    this->m_Collision.WorldSpaceSurroundingBounds(this: &this->m_Collision, a2: (Vector *)&extent, a3: &extent.hi);
    CNavMesh::ForAllAreasOverlappingExtent<CFuncNavObstruction>(this: TheNavMesh, func: this, &extent);
    CNavMesh::RegisterAvoidanceObstacle(this: TheNavMesh, obstruction: &this->INavAvoidanceObstacle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030A160
// Name: public: virtual int CFuncNavBlocker::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFuncNavBlocker::DrawDebugTextOverlays(CFuncNavBlocker *this)
{
  int result; // eax
  int v3; // ebx
  int i; // edi
  bool v5; // al
  CTeam *GlobalTeam; // eax
  char *v7; // eax
  void (__thiscall *WorldSpaceSurroundingBounds)(struct CBaseEntity::NetworkVar_m_Collision *, Vector *, Vector *); // eax
  int m_Size; // ebx
  CNavArea **m_pMemory; // edi
  int j; // esi
  int v12; // [esp-4h] [ebp-17Ch]
  float duration; // [esp+0h] [ebp-178h]
  int v14; // [esp+4h] [ebp-174h]
  int v15; // [esp+8h] [ebp-170h]
  int v16; // [esp+Ch] [ebp-16Ch]
  int v17; // [esp+10h] [ebp-168h]
  CFmtStrN<256> str; // [esp+20h] [ebp-158h] BYREF
  Extent areaExtent; // [esp+12Ch] [ebp-4Ch] BYREF
  Extent extent; // [esp+144h] [ebp-34h] BYREF
  NavAreaCollector collector; // [esp+15Ch] [ebp-1Ch] BYREF
  int offset; // [esp+174h] [ebp-4h]

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    str.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
    *(_WORD *)&str.m_bQuietTruncation = 1;
    str.m_nLength = 0;
    for ( i = 2; i < 4; ++i )
    {
      if ( i == -1 )
        v5 = this->m_isBlockingNav[0] || this->m_isBlockingNav[1];
      else
        v5 = this->m_isBlockingNav[i % 2];
      if ( v5 )
      {
        GlobalTeam = GetGlobalTeam(iIndex: i);
        v17 = 255;
        v16 = 255;
        v15 = 255;
        v14 = 255;
        duration = 0.0;
        if ( GlobalTeam != nullptr )
        {
          v12 = ((int (__thiscall *)(CTeam *, _DWORD, int, int, int, int))GlobalTeam->GetName)(
                  a1: GlobalTeam,
                  a2: 0,
                  a3: 255,
                  a4: 255,
                  a5: 255,
                  a6: 255);
          v7 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "blocking team %s", v12);
        }
        else
        {
          v7 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "blocking team %d", i);
        }
        CBaseEntity::EntityText(this, text_offset: v3++, text: v7, duration, r: v14, g: v15, b: v16, a: v17);
      }
    }
    WorldSpaceSurroundingBounds = this->m_Collision.WorldSpaceSurroundingBounds;
    memset(&collector.m_area, 0, sizeof(collector.m_area));
    offset = v3;
    collector.m_checkForDuplicates = true;
    WorldSpaceSurroundingBounds(this: &this->m_Collision, a2: &extent.lo, a3: &extent.hi);
    CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>(this: TheNavMesh, func: &collector, &extent);
    m_Size = collector.m_area.m_Size;
    m_pMemory = collector.m_area.m_Memory.m_pMemory;
    for ( j = 0; j < m_Size; ++j )
    {
      CNavArea::GetExtent(this: m_pMemory[j], extent: &areaExtent);
      ((void (__stdcall *)(Vector *, Extent *, Vector *, QAngle *, _DWORD, int, _DWORD, int, int))debugoverlay->AddBoxOverlay)(
        a1: &vec3_origin,
        a2: &areaExtent,
        a3: &areaExtent.hi,
        a4: &vec3_angle,
        a5: 0,
        a6: 255,
        a7: 0,
        a8: 10,
        a9: 1009228731);
    }
    if ( collector.m_area.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return offset;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030A320
// Name: private: void CFuncNavBlocker::UnblockNav(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncNavBlocker::UnblockNav(CFuncNavBlocker *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  int m_blockedTeamNumber; // eax
  void (__thiscall *WorldSpaceSurroundingBounds)(struct CBaseEntity::NetworkVar_m_Collision *, Vector *, Vector *); // edx
  int v6; // esi
  int m_Size; // ebx
  CNavArea **m_pMemory; // edi
  Extent extent; // [esp+0h] [ebp-30h] BYREF
  NavAreaCollector func; // [esp+18h] [ebp-18h] BYREF

  m_blockedTeamNumber = this->m_blockedTeamNumber;
  if ( m_blockedTeamNumber == -1 )
    *(_WORD *)this->m_isBlockingNav = 0;
  else
    this->m_isBlockingNav[m_blockedTeamNumber % 2] = false;
  WorldSpaceSurroundingBounds = this->m_Collision.WorldSpaceSurroundingBounds;
  v6 = 0;
  memset(&func.m_area, 0, sizeof(func.m_area));
  func.m_checkForDuplicates = true;
  ((void (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, Extent *, Vector *, int, int, int))WorldSpaceSurroundingBounds)(
    a1: &this->m_Collision,
    a2: &extent,
    a3: &extent.hi,
    a4: a3,
    a5: a4,
    a6: a2);
  CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>(this: TheNavMesh, &func, &extent);
  m_Size = func.m_area.m_Size;
  m_pMemory = func.m_area.m_Memory.m_pMemory;
  if ( func.m_area.m_Size > 0 )
  {
    do
    {
      m_pMemory[v6]->UpdateBlocked(this: m_pMemory[v6], a2: true, a3: -1);
      ++v6;
    }
    while ( v6 < m_Size );
  }
  if ( func.m_area.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1030A4E0
// Name: public: virtual void CFuncNavBlocker::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncNavBlocker::UpdateOnRemove(CFuncNavBlocker *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CBaseCombatWeapon *src; // [esp+4h] [ebp-4h] BYREF

  CFuncNavBlocker::UnblockNav(this, a2, a3, a4: (int)this);
  src = (CBaseCombatWeapon *)this;
  CUtlLinkedList<CFuncNavBlocker *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short>,unsigned short>>::FindAndRemove(
    this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&CFuncNavBlocker::gm_NavBlockers,
    &src);
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x1030A510
// Name: public: virtual void CFuncNavBlocker::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncNavBlocker::Spawn(CFuncNavBlocker *this@<ecx>, int a2@<ebx>)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short> *v5; // eax
  const char *v6; // eax
  _BYTE v7[4]; // [esp+8h] [ebp-4h] BYREF

  v3 = CUtlLinkedList<CFuncNavBlocker *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short>,unsigned short>>::AllocInternal(
         this: &CFuncNavBlocker::gm_NavBlockers,
         multilist: false);
  v4 = v3;
  if ( v3 != 0xFFFF )
  {
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&CFuncNavBlocker::gm_NavBlockers,
      before: 0xFFFFu,
      elem: v3);
    v5 = &CFuncNavBlocker::gm_NavBlockers.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
      v5->m_Element = this;
  }
  if ( this->m_blockedTeamNumber == 0 )
    this->m_blockedTeamNumber = -1;
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v6 = *(const char **)((int (__thiscall *)(CFuncNavBlocker *, _BYTE *))this->GetModelName)(a1: this, a2: v7);
  if ( v6 == nullptr )
    v6 = locale;
  this->SetModel(this, a2: v6);
  CBaseEntity::AddEffects(this, nEffects: 32);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 0);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CCollisionProperty::CollisionAABBToWorldAABB(
    this: &this->m_Collision,
    entityMins: &this->m_Collision.m_vecMins.m_Value,
    entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
    pWorldMins: &this->m_CachedMins,
    pWorldMaxs: &this->m_CachedMaxs);
  if ( this->m_bDisabled )
    CFuncNavBlocker::UnblockNav(this, a2, a3: v4, a4: (int)this);
  else
    CFuncNavBlocker::BlockNav(this);
}

//------------------------------------------------------------------------------
// Address: 0x1030A610
// Name: public: void CFuncNavBlocker::InputUnblockNav(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __userpurge CFuncNavBlocker::InputUnblockNav(
        CFuncNavBlocker *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        inputdata_t *inputdata)
{
  CFuncNavBlocker::UnblockNav(this, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x10413C40
// Name: CFuncNavBlocker_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncNavBlocker_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncNavBlocker>(__formal: nullptr);
  CFuncNavBlocker_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413C70
// Name: _dynamic_initializer_for__CFuncNavBlocker::gm_NavBlockers__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CFuncNavBlocker::gm_NavBlockers__()
{
  return atexit(func: dynamic_atexit_destructor_for__CFuncNavBlocker::gm_NavBlockers__);
}

//------------------------------------------------------------------------------
// Address: 0x10413C80
// Name: CFuncNavObstruction_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncNavObstruction_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncNavObstruction>(__formal: nullptr);
  CFuncNavObstruction_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421230
// Name: _dynamic_atexit_destructor_for__CFuncNavBlocker::gm_NavBlockers__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CFuncNavBlocker::gm_NavBlockers__()
{
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&CFuncNavBlocker::gm_NavBlockers);
  if ( CFuncNavBlocker::gm_NavBlockers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( CFuncNavBlocker::gm_NavBlockers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: CFuncNavBlocker::gm_NavBlockers.m_Memory.m_pMemory);
      CFuncNavBlocker::gm_NavBlockers.m_Memory.m_pMemory = nullptr;
    }
    CFuncNavBlocker::gm_NavBlockers.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041C60
// Name: struct datamap_t __near * DataMapInit<class CAI_BehaviorBase>(class CAI_BehaviorBase __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_BehaviorBase>()
{
  if ( (_S3_2 & 1) == 0 )
  {
    _S3_2 |= 1u;
    nameHolder_14.m_pszBase = "CAI_BehaviorBase";
    nameHolder_14.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_14.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_14.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_14.m_Names.m_Size = 0;
    nameHolder_14.m_Names.m_pElements = nullptr;
    nameHolder_14.m_nLenBase = 16;
    atexit(func: DataMapInit_CAI_BehaviorBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_BehaviorBase::m_DataMap.baseMap = nullptr;
  if ( (_S3_2 & 2) == 0 )
  {
    _S3_2 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int>>,10>::`vftable';
    }
    dataDesc_14[1].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int>>>'::`2'::ops;
    dataDesc_14[1].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_14[1].td = 0;
    *(_QWORD *)&dataDesc_14[1].override_field = 0;
    *(_QWORD *)&dataDesc_14[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_14[1].flatOffset[1] = 0;
  }
  CAI_BehaviorBase::m_DataMap.dataNumFields = 1;
  CAI_BehaviorBase::m_DataMap.dataDesc = &dataDesc_14[1];
  return &CAI_BehaviorBase::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100460F0
// Name: struct datamap_t __near * DataMapInit<class CAI_FollowBehavior>(class CAI_FollowBehavior __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_FollowBehavior>()
{
  CActivityDataOps *v0; // eax

  if ( (_S4_2 & 1) == 0 )
  {
    _S4_2 |= 1u;
    nameHolder_25.m_pszBase = "CAI_FollowBehavior";
    nameHolder_25.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_25.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_25.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_25.m_Names.m_Size = 0;
    nameHolder_25.m_Names.m_pElements = nullptr;
    nameHolder_25.m_nLenBase = 18;
    atexit(func: DataMapInit_CAI_FollowBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_FollowBehavior::m_DataMap.baseMap = &CAI_BehaviorBase::m_DataMap;
  if ( (_S4_2 & 2) == 0 )
  {
    _S4_2 |= 2u;
    v0 = ActivityDataOps();
    dataDesc_25[15].flags = 2;
    *(_QWORD *)dataDesc_25[15].flatOffset = 0;
    dataDesc_25[16].fieldSize = 1;
    dataDesc_25[14].pSaveRestoreOps = v0;
    *(_QWORD *)dataDesc_25[16].flatOffset = 0;
    dataDesc_25[15].fieldSize = 1;
    dataDesc_25[16].flags = 2;
    dataDesc_25[18].fieldSize = 1;
    *(_QWORD *)&dataDesc_25[14].td = 0;
    *(_QWORD *)&dataDesc_25[14].override_field = 0;
    *(_QWORD *)&dataDesc_25[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_25[14].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_25[17].flatOffset = 0;
    dataDesc_25[14].inputFunc = nullptr;
    dataDesc_25[15].fieldType = FIELD_EMBEDDED;
    dataDesc_25[15].fieldName = "m_TimeBlockUseWaitPoint";
    dataDesc_25[15].fieldOffset = 196;
    dataDesc_25[15].externalName = nullptr;
    dataDesc_25[15].pSaveRestoreOps = nullptr;
    dataDesc_25[15].inputFunc = nullptr;
    dataDesc_25[15].td = &CRandSimTimer::m_DataMap;
    dataDesc_25[15].fieldSizeInBytes = 12;
    dataDesc_25[15].override_field = nullptr;
    dataDesc_25[15].override_count = 0;
    dataDesc_25[15].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_25[15].flatGroup = 0;
    dataDesc_25[16].fieldType = FIELD_EMBEDDED;
    dataDesc_25[16].fieldName = "m_TimeCheckForWaitPoint";
    dataDesc_25[16].fieldOffset = 208;
    dataDesc_25[16].externalName = nullptr;
    dataDesc_25[16].pSaveRestoreOps = nullptr;
    dataDesc_25[16].inputFunc = nullptr;
    dataDesc_25[16].td = &CSimTimer::m_DataMap;
    dataDesc_25[16].fieldSizeInBytes = 8;
    dataDesc_25[16].override_field = nullptr;
    dataDesc_25[16].override_count = 0;
    dataDesc_25[16].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_25[16].flatGroup = 0;
    dataDesc_25[17].fieldType = FIELD_CLASSPTR;
    dataDesc_25[17].fieldName = "m_pInterruptWaitPoint";
    dataDesc_25[17].fieldOffset = 216;
    *(_DWORD *)&dataDesc_25[17].fieldSize = 131073;
    dataDesc_25[17].externalName = nullptr;
    dataDesc_25[17].pSaveRestoreOps = nullptr;
    dataDesc_25[17].inputFunc = nullptr;
    dataDesc_25[17].td = nullptr;
    dataDesc_25[17].fieldSizeInBytes = 4;
    dataDesc_25[17].override_field = nullptr;
    dataDesc_25[17].override_count = 0;
    dataDesc_25[17].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_25[17].flatGroup = 0;
    dataDesc_25[18].fieldType = FIELD_EMBEDDED;
    dataDesc_25[18].fieldName = "m_TimeBeforeSpreadFacing";
    dataDesc_25[18].fieldOffset = 220;
    dataDesc_25[18].flags = 2;
    dataDesc_25[18].externalName = nullptr;
    dataDesc_25[18].pSaveRestoreOps = nullptr;
    dataDesc_25[18].inputFunc = nullptr;
    dataDesc_25[18].td = &CRandSimTimer::m_DataMap;
    dataDesc_25[18].fieldSizeInBytes = 12;
    dataDesc_25[18].override_field = nullptr;
    dataDesc_25[18].override_count = 0;
    dataDesc_25[18].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_25[18].flatOffset = 0;
    dataDesc_25[19].fieldType = FIELD_EMBEDDED;
    dataDesc_25[20].fieldType = FIELD_EMBEDDED;
    dataDesc_25[20].fieldSize = 1;
    dataDesc_25[19].fieldSize = 1;
    dataDesc_25[20].flags = 2;
    dataDesc_25[21].fieldSize = 1;
    dataDesc_25[21].flags = 2;
    dataDesc_25[22].fieldSize = 1;
    *(_QWORD *)dataDesc_25[19].flatOffset = 0;
    dataDesc_25[22].flags = 2;
    *(_QWORD *)dataDesc_25[20].flatOffset = 0;
    dataDesc_25[23].fieldSize = 1;
    *(_QWORD *)dataDesc_25[21].flatOffset = 0;
    *(_DWORD *)&dataDesc_25[18].flatGroup = 0;
    dataDesc_25[19].fieldName = "m_TimeNextSpreadFacing";
    dataDesc_25[19].fieldOffset = 232;
    dataDesc_25[19].flags = 2;
    dataDesc_25[19].externalName = nullptr;
    dataDesc_25[19].pSaveRestoreOps = nullptr;
    dataDesc_25[19].inputFunc = nullptr;
    dataDesc_25[19].td = &CRandSimTimer::m_DataMap;
    dataDesc_25[19].fieldSizeInBytes = 12;
    dataDesc_25[19].override_field = nullptr;
    dataDesc_25[19].override_count = 0;
    dataDesc_25[19].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_25[19].flatGroup = 0;
    dataDesc_25[20].fieldName = "m_params";
    dataDesc_25[20].fieldOffset = 252;
    dataDesc_25[20].externalName = nullptr;
    dataDesc_25[20].pSaveRestoreOps = nullptr;
    dataDesc_25[20].inputFunc = nullptr;
    dataDesc_25[20].td = &AI_FollowParams_t::m_DataMap;
    dataDesc_25[20].fieldSizeInBytes = 8;
    dataDesc_25[20].override_field = nullptr;
    dataDesc_25[20].override_count = 0;
    dataDesc_25[20].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_25[20].flatGroup = 0;
    dataDesc_25[21].fieldType = FIELD_EHANDLE;
    dataDesc_25[21].fieldName = "m_hFollowGoalEnt";
    dataDesc_25[21].fieldOffset = 260;
    dataDesc_25[21].externalName = nullptr;
    dataDesc_25[21].pSaveRestoreOps = nullptr;
    dataDesc_25[21].inputFunc = nullptr;
    dataDesc_25[21].td = nullptr;
    dataDesc_25[21].fieldSizeInBytes = 4;
    dataDesc_25[21].override_field = nullptr;
    dataDesc_25[21].override_count = 0;
    dataDesc_25[21].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_25[21].flatGroup = 0;
    dataDesc_25[22].fieldType = FIELD_INTEGER;
    dataDesc_25[22].fieldName = "m_nFailedFollowAttempts";
    dataDesc_25[22].fieldOffset = 140;
    dataDesc_25[22].externalName = nullptr;
    dataDesc_25[22].pSaveRestoreOps = nullptr;
    dataDesc_25[22].inputFunc = nullptr;
    dataDesc_25[22].td = nullptr;
    dataDesc_25[22].fieldSizeInBytes = 4;
    dataDesc_25[22].override_field = nullptr;
    dataDesc_25[22].override_count = 0;
    dataDesc_25[22].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_25[22].flatOffset = 0;
    *(_DWORD *)&dataDesc_25[22].flatGroup = 0;
    dataDesc_25[23].fieldType = FIELD_TIME;
    dataDesc_25[23].fieldName = "m_flTimeFailFollowStarted";
    dataDesc_25[23].fieldOffset = 144;
    dataDesc_25[23].flags = 2;
    dataDesc_25[23].externalName = nullptr;
    dataDesc_25[23].fieldTolerance = 0.0;
    dataDesc_25[24].fieldTolerance = 0.0;
    dataDesc_25[23].pSaveRestoreOps = nullptr;
    dataDesc_25[23].inputFunc = nullptr;
    dataDesc_25[23].td = nullptr;
    dataDesc_25[23].fieldSizeInBytes = 4;
    dataDesc_25[23].override_field = nullptr;
    dataDesc_25[23].override_count = 0;
    *(_QWORD *)dataDesc_25[23].flatOffset = 0;
    *(_DWORD *)&dataDesc_25[23].flatGroup = 0;
    dataDesc_25[24].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_25[24].fieldName = "m_vFollowMoveAnchor";
    dataDesc_25[24].fieldOffset = 148;
    *(_DWORD *)&dataDesc_25[24].fieldSize = 131073;
    dataDesc_25[24].externalName = nullptr;
    dataDesc_25[24].pSaveRestoreOps = nullptr;
    dataDesc_25[24].inputFunc = nullptr;
    dataDesc_25[24].td = nullptr;
    dataDesc_25[24].fieldSizeInBytes = 12;
    dataDesc_25[24].override_field = nullptr;
    dataDesc_25[24].override_count = 0;
    *(_QWORD *)dataDesc_25[24].flatOffset = 0;
    *(_DWORD *)&dataDesc_25[24].flatGroup = 0;
  }
  CAI_FollowBehavior::m_DataMap.dataNumFields = 24;
  CAI_FollowBehavior::m_DataMap.dataDesc = &dataDesc_25[1];
  return &CAI_FollowBehavior::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10046660
// Name: struct datamap_t __near * DataMapInit<class CAI_FollowGoal>(class CAI_FollowGoal __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_FollowGoal>()
{
  if ( (_S7_0 & 1) == 0 )
  {
    _S7_0 |= 1u;
    nameHolder_26.m_pszBase = "CAI_FollowGoal";
    nameHolder_26.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_26.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_26.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_26.m_Names.m_Size = 0;
    nameHolder_26.m_Names.m_pElements = nullptr;
    nameHolder_26.m_nLenBase = 14;
    atexit(func: DataMapInit_CAI_FollowGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_FollowGoal::m_DataMap.baseMap = &CAI_GoalEntity::m_DataMap;
  CAI_FollowGoal::m_DataMap.dataNumFields = 1;
  CAI_FollowGoal::m_DataMap.dataDesc = &dataDesc_26[1];
  return &CAI_FollowGoal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10047DF0
// Name: struct datamap_t __near * DataMapInit<class CAI_LeadBehavior>(class CAI_LeadBehavior __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_LeadBehavior>()
{
  if ( (_S3_6 & 1) == 0 )
  {
    _S3_6 |= 1u;
    nameHolder_28.m_pszBase = "CAI_LeadBehavior";
    nameHolder_28.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_28.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_28.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_28.m_Names.m_Size = 0;
    nameHolder_28.m_Names.m_pElements = nullptr;
    nameHolder_28.m_nLenBase = 16;
    atexit(func: DataMapInit_CAI_LeadBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_LeadBehavior::m_DataMap.baseMap = &CAI_BehaviorBase::m_DataMap;
  CAI_LeadBehavior::m_DataMap.dataNumFields = 22;
  CAI_LeadBehavior::m_DataMap.dataDesc = &dataDesc_28[1];
  return &CAI_LeadBehavior::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10047E70
// Name: struct datamap_t __near * DataMapInit<class CAI_LeadGoal>(class CAI_LeadGoal __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_LeadGoal>()
{
  if ( (_S4_3 & 1) == 0 )
  {
    _S4_3 |= 1u;
    nameHolder_29.m_pszBase = "CAI_LeadGoal";
    nameHolder_29.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_29.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_29.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_29.m_Names.m_Size = 0;
    nameHolder_29.m_Names.m_pElements = nullptr;
    nameHolder_29.m_nLenBase = 12;
    atexit(func: DataMapInit_CAI_LeadGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_LeadGoal::m_DataMap.baseMap = &CAI_GoalEntity::m_DataMap;
  if ( (_S4_3 & 2) == 0 )
  {
    _S4_3 |= 2u;
    dataDesc_29[25].fieldSize = 1;
    dataDesc_29[25].flags = 22;
    *(_QWORD *)&dataDesc_29[24].inputFunc = 0;
    *(_QWORD *)&dataDesc_29[24].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_29[24].override_count = 0;
    *(_QWORD *)dataDesc_29[24].flatOffset = 0;
    *(_QWORD *)&dataDesc_29[25].inputFunc = 0;
    *(_QWORD *)&dataDesc_29[25].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_29[25].override_count = 0;
    *(_QWORD *)dataDesc_29[25].flatOffset = 0;
    dataDesc_29[26].fieldSize = 1;
    *(_QWORD *)&dataDesc_29[26].inputFunc = 0;
    *(_QWORD *)&dataDesc_29[26].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_29[26].override_count = 0;
    *(_QWORD *)dataDesc_29[26].flatOffset = 0;
    dataDesc_29[25].fieldType = FIELD_CUSTOM;
    dataDesc_29[26].fieldType = FIELD_CUSTOM;
    dataDesc_29[26].flags = 22;
    dataDesc_29[27].fieldType = FIELD_CUSTOM;
    dataDesc_29[28].fieldType = FIELD_CUSTOM;
    *(_QWORD *)&dataDesc_29[27].inputFunc = 0;
    *(_QWORD *)&dataDesc_29[27].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_29[27].override_count = 0;
    *(_QWORD *)dataDesc_29[27].flatOffset = 0;
    dataDesc_29[24].pSaveRestoreOps = eventFuncs;
    dataDesc_29[25].pSaveRestoreOps = eventFuncs;
    dataDesc_29[26].pSaveRestoreOps = eventFuncs;
    dataDesc_29[27].fieldSize = 1;
    dataDesc_29[27].pSaveRestoreOps = eventFuncs;
    dataDesc_29[28].fieldSize = 1;
    dataDesc_29[28].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_29[28].inputFunc = 0;
    *(_QWORD *)&dataDesc_29[28].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_29[28].override_count = 0;
    *(_QWORD *)dataDesc_29[28].flatOffset = 0;
    *(_DWORD *)&dataDesc_29[24].flatGroup = 0;
    dataDesc_29[25].fieldName = "m_OnArrival";
    dataDesc_29[25].fieldOffset = 988;
    dataDesc_29[25].externalName = "OnArrival";
    *(_DWORD *)&dataDesc_29[25].flatGroup = 0;
    dataDesc_29[26].fieldName = "m_OnArrivalDone";
    dataDesc_29[26].fieldOffset = 1012;
    dataDesc_29[26].externalName = "OnArrivalDone";
    *(_DWORD *)&dataDesc_29[26].flatGroup = 0;
    dataDesc_29[27].fieldName = "m_OnFailure";
    dataDesc_29[27].fieldOffset = 1060;
    dataDesc_29[27].flags = 22;
    dataDesc_29[27].externalName = "OnFailure";
    *(_DWORD *)&dataDesc_29[27].flatGroup = 0;
    dataDesc_29[28].fieldName = "m_OnDone";
    dataDesc_29[28].fieldOffset = 1084;
    dataDesc_29[28].flags = 22;
    dataDesc_29[28].externalName = "OnDone";
    *(_DWORD *)&dataDesc_29[28].flatGroup = 0;
    dataDesc_29[29].fieldType = FIELD_VOID;
    dataDesc_29[29].fieldName = "InputSetSuccess";
    dataDesc_29[29].fieldOffset = 0;
    dataDesc_29[29].fieldSize = 1;
    dataDesc_29[29].flags = 8;
    dataDesc_29[29].externalName = "SetSuccess";
    dataDesc_29[29].pSaveRestoreOps = nullptr;
    dataDesc_29[29].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_LeadGoal::InputSetSuccess;
    *(_QWORD *)&dataDesc_29[29].td = 0;
    *(_QWORD *)&dataDesc_29[29].override_field = 0;
    *(_QWORD *)&dataDesc_29[29].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_29[29].flatOffset[1] = 0;
    dataDesc_29[30].fieldType = FIELD_VOID;
    dataDesc_29[30].fieldName = "InputSetFailure";
    dataDesc_29[30].fieldOffset = 0;
    *(_DWORD *)&dataDesc_29[30].fieldSize = 524289;
    dataDesc_29[30].externalName = "SetFailure";
    dataDesc_29[30].pSaveRestoreOps = nullptr;
    dataDesc_29[30].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_LeadGoal::InputSetFailure;
    *(_QWORD *)&dataDesc_29[30].td = 0;
    *(_QWORD *)&dataDesc_29[30].override_field = 0;
    *(_QWORD *)&dataDesc_29[30].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_29[30].flatOffset[1] = 0;
  }
  CAI_LeadGoal::m_DataMap.dataNumFields = 30;
  CAI_LeadGoal::m_DataMap.dataDesc = &dataDesc_29[1];
  return &CAI_LeadGoal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100481A0
// Name: struct datamap_t __near * DataMapInit<class CAI_LeadGoal_Weapon>(class CAI_LeadGoal_Weapon __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_LeadGoal_Weapon>()
{
  if ( (_S5_2 & 1) == 0 )
  {
    _S5_2 |= 1u;
    nameHolder_30.m_pszBase = "CAI_LeadGoal_Weapon";
    nameHolder_30.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_30.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_30.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_30.m_Names.m_Size = 0;
    nameHolder_30.m_Names.m_pElements = nullptr;
    nameHolder_30.m_nLenBase = 19;
    atexit(func: DataMapInit_CAI_LeadGoal_Weapon__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_LeadGoal_Weapon::m_DataMap.baseMap = &CAI_LeadGoal::m_DataMap;
  CAI_LeadGoal_Weapon::m_DataMap.dataNumFields = 2;
  CAI_LeadGoal_Weapon::m_DataMap.dataDesc = &dataDesc_30[1];
  return &CAI_LeadGoal_Weapon::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10049550
// Name: struct datamap_t __near * DataMapInit<class CAI_StandoffBehavior>(class CAI_StandoffBehavior __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_StandoffBehavior>()
{
  if ( (_S4_4 & 1) == 0 )
  {
    _S4_4 |= 1u;
    nameHolder_35.m_pszBase = "CAI_StandoffBehavior";
    nameHolder_35.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_35.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_35.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_35.m_Names.m_Size = 0;
    nameHolder_35.m_Names.m_pElements = nullptr;
    nameHolder_35.m_nLenBase = 20;
    atexit(func: DataMapInit_CAI_StandoffBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_StandoffBehavior::m_DataMap.baseMap = &CAI_BehaviorBase::m_DataMap;
  CAI_StandoffBehavior::m_DataMap.dataNumFields = 18;
  CAI_StandoffBehavior::m_DataMap.dataDesc = &dataDesc_35[1];
  return &CAI_StandoffBehavior::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100495D0
// Name: struct datamap_t __near * DataMapInit<class CAI_StandoffGoal>(class CAI_StandoffGoal __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_StandoffGoal>()
{
  if ( (_S6_0 & 1) == 0 )
  {
    _S6_0 |= 1u;
    nameHolder_36.m_pszBase = "CAI_StandoffGoal";
    nameHolder_36.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_36.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_36.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_36.m_Names.m_Size = 0;
    nameHolder_36.m_Names.m_pElements = nullptr;
    nameHolder_36.m_nLenBase = 16;
    atexit(func: DataMapInit_CAI_StandoffGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_StandoffGoal::m_DataMap.baseMap = &CAI_GoalEntity::m_DataMap;
  CAI_StandoffGoal::m_DataMap.dataNumFields = 12;
  CAI_StandoffGoal::m_DataMap.dataDesc = &dataDesc_36[1];
  return &CAI_StandoffGoal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10057A70
// Name: struct datamap_t __near * DataMapInit<class CNodeEnt>(class CNodeEnt __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CNodeEnt>()
{
  if ( (_S3_11 & 1) == 0 )
  {
    _S3_11 |= 1u;
    nameHolder_46.m_pszBase = "CNodeEnt";
    nameHolder_46.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_46.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_46.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_46.m_Names.m_Size = 0;
    nameHolder_46.m_Names.m_pElements = nullptr;
    nameHolder_46.m_nLenBase = 8;
    atexit(func: DataMapInit_CNodeEnt__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CNodeEnt::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CNodeEnt::m_DataMap.dataNumFields = 1;
  CNodeEnt::m_DataMap.dataDesc = &dataDesc_45[1];
  return &CNodeEnt::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10089080
// Name: struct datamap_t __near * DataMapInit<class CAI_Expresser>(class CAI_Expresser __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_Expresser>()
{
  if ( (_S3_16 & 1) == 0 )
  {
    _S3_16 |= 1u;
    nameHolder_68.m_pszBase = "CAI_Expresser";
    nameHolder_68.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_68.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_68.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_68.m_Names.m_Size = 0;
    nameHolder_68.m_Names.m_pElements = nullptr;
    nameHolder_68.m_nLenBase = 13;
    atexit(func: DataMapInit_CAI_Expresser__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_Expresser::m_DataMap.baseMap = nullptr;
  CAI_Expresser::m_DataMap.dataNumFields = 6;
  CAI_Expresser::m_DataMap.dataDesc = &dataDesc_65[1];
  return &CAI_Expresser::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1008C3C0
// Name: struct datamap_t __near * DataMapInit<class CAI_Squad>(class CAI_Squad __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_Squad>()
{
  if ( (_S3_17 & 1) == 0 )
  {
    _S3_17 |= 1u;
    nameHolder_71.m_pszBase = "CAI_Squad";
    nameHolder_71.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_71.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_71.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_71.m_Names.m_Size = 0;
    nameHolder_71.m_Names.m_pElements = nullptr;
    nameHolder_71.m_nLenBase = 9;
    atexit(func: DataMapInit_CAI_Squad__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_Squad::m_DataMap.baseMap = nullptr;
  if ( (_S3_17 & 2) == 0 )
  {
    _S3_17 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int>>,10>::`vftable';
    }
    *(_QWORD *)&dataDesc_68[5].td = 0;
    *(_QWORD *)&dataDesc_68[5].override_field = 0;
    *(_QWORD *)&dataDesc_68[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_68[5].flatOffset[1] = 0;
    dataDesc_68[6].fieldTolerance = 0.0;
    dataDesc_68[5].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int>>>'::`2'::ops;
    dataDesc_68[5].inputFunc = nullptr;
    dataDesc_68[6].fieldType = FIELD_TIME;
    dataDesc_68[6].fieldName = "m_flEnemyInfoCleanupTime";
    dataDesc_68[6].fieldOffset = 132;
    *(_DWORD *)&dataDesc_68[6].fieldSize = 131073;
    dataDesc_68[6].externalName = nullptr;
    dataDesc_68[6].pSaveRestoreOps = nullptr;
    dataDesc_68[6].inputFunc = nullptr;
    dataDesc_68[6].td = nullptr;
    dataDesc_68[6].fieldSizeInBytes = 4;
    dataDesc_68[6].override_field = nullptr;
    dataDesc_68[6].override_count = 0;
    *(_QWORD *)dataDesc_68[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_68[6].flatGroup = 0;
  }
  CAI_Squad::m_DataMap.dataNumFields = 6;
  CAI_Squad::m_DataMap.dataDesc = &dataDesc_68[1];
  return &CAI_Squad::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10090810
// Name: struct datamap_t __near * DataMapInit<class CAI_FreePass>(class CAI_FreePass __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_FreePass>()
{
  if ( (_S6_1 & 1) == 0 )
  {
    _S6_1 |= 1u;
    nameHolder_78.m_pszBase = "CAI_FreePass";
    nameHolder_78.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_78.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_78.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_78.m_Names.m_Size = 0;
    nameHolder_78.m_Names.m_pElements = nullptr;
    nameHolder_78.m_nLenBase = 12;
    atexit(func: DataMapInit_CAI_FreePass__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_FreePass::m_DataMap.baseMap = nullptr;
  CAI_FreePass::m_DataMap.dataNumFields = 4;
  CAI_FreePass::m_DataMap.dataDesc = &dataDesc_75[1];
  return &CAI_FreePass::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100D4860
// Name: struct datamap_t __near * DataMapInit<class CBaseFlex>(class CBaseFlex __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseFlex>()
{
  if ( (_S3_26 & 1) == 0 )
  {
    _S3_26 |= 1u;
    nameHolder_96.m_pszBase = "CBaseFlex";
    nameHolder_96.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_96.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_96.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_96.m_Names.m_Size = 0;
    nameHolder_96.m_Names.m_pElements = nullptr;
    nameHolder_96.m_nLenBase = 9;
    atexit(func: DataMapInit_CBaseFlex__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseFlex::m_DataMap.baseMap = &CBaseAnimatingOverlay::m_DataMap;
  CBaseFlex::m_DataMap.dataNumFields = 4;
  CBaseFlex::m_DataMap.dataDesc = &dataDesc_93[1];
  return &CBaseFlex::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1018DFF0
// Name: struct datamap_t __near * DataMapInit<class CBoneFollowerManager>(class CBoneFollowerManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBoneFollowerManager>()
{
  if ( (_S3_87 & 1) == 0 )
  {
    _S3_87 |= 1u;
    nameHolder_305.m_pszBase = "CBoneFollowerManager";
    nameHolder_305.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_305.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_305.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_305.m_Names.m_Size = 0;
    nameHolder_305.m_Names.m_pElements = nullptr;
    nameHolder_305.m_nLenBase = 20;
    atexit(func: DataMapInit_CBoneFollowerManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBoneFollowerManager::m_DataMap.baseMap = nullptr;
  if ( (_S3_87 & 2) == 0 )
  {
    _S3_87 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int>>,10>::`vftable';
    }
    dataDesc_292[2].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int>>>'::`2'::ops;
    dataDesc_292[2].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_292[2].td = 0;
    *(_QWORD *)&dataDesc_292[2].override_field = 0;
    *(_QWORD *)&dataDesc_292[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_292[2].flatOffset[1] = 0;
  }
  CBoneFollowerManager::m_DataMap.dataNumFields = 2;
  CBoneFollowerManager::m_DataMap.dataDesc = &dataDesc_292[1];
  return &CBoneFollowerManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B2FF0
// Name: struct datamap_t __near * DataMapInit<class CPhysMagnet>(class CPhysMagnet __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysMagnet>()
{
  if ( (_S9_5 & 1) == 0 )
  {
    _S9_5 |= 1u;
    nameHolder_322.m_pszBase = "CPhysMagnet";
    nameHolder_322.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_322.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_322.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_322.m_Names.m_Size = 0;
    nameHolder_322.m_Names.m_pElements = nullptr;
    nameHolder_322.m_nLenBase = 11;
    atexit(func: DataMapInit_CPhysMagnet__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysMagnet::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S9_5 & 2) == 0 )
  {
    dataDesc_309[2].fieldSize = 1;
    *(_QWORD *)&dataDesc_309[1].inputFunc = 0;
    *(_QWORD *)&dataDesc_309[1].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_309[1].override_count = 0;
    *(_QWORD *)dataDesc_309[1].flatOffset = 0;
    *(_QWORD *)dataDesc_309[3].flatOffset = 0;
    _S9_5 |= 2u;
    dataDesc_309[1].pSaveRestoreOps = eventFuncs;
    dataDesc_309[2].flags = 22;
    dataDesc_309[2].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_309[2].inputFunc = 0;
    *(_QWORD *)&dataDesc_309[2].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_309[2].override_count = 0;
    *(_QWORD *)dataDesc_309[2].flatOffset = 0;
    *(_QWORD *)dataDesc_309[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_309[1].flatGroup = 0;
    dataDesc_309[2].fieldType = FIELD_CUSTOM;
    dataDesc_309[2].fieldName = "m_OnMagnetDetach";
    dataDesc_309[2].fieldOffset = 1192;
    dataDesc_309[2].externalName = "OnDetach";
    *(_DWORD *)&dataDesc_309[2].flatGroup = 0;
    dataDesc_309[3].fieldType = FIELD_FLOAT;
    dataDesc_309[3].fieldName = "m_massScale";
    dataDesc_309[3].fieldOffset = 1216;
    dataDesc_309[3].fieldSize = 1;
    dataDesc_309[3].flags = 6;
    dataDesc_309[3].externalName = "massScale";
    dataDesc_309[3].pSaveRestoreOps = nullptr;
    dataDesc_309[3].inputFunc = nullptr;
    dataDesc_309[3].td = nullptr;
    dataDesc_309[3].fieldSizeInBytes = 4;
    dataDesc_309[3].override_field = nullptr;
    dataDesc_309[3].override_count = 0;
    dataDesc_309[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_309[3].flatGroup = 0;
    dataDesc_309[4].fieldType = FIELD_STRING;
    dataDesc_309[4].fieldName = "m_iszOverrideScript";
    dataDesc_309[4].fieldOffset = 1220;
    dataDesc_309[4].fieldSize = 1;
    dataDesc_309[4].flags = 6;
    dataDesc_309[4].externalName = "overridescript";
    dataDesc_309[4].pSaveRestoreOps = nullptr;
    dataDesc_309[4].inputFunc = nullptr;
    dataDesc_309[4].td = nullptr;
    dataDesc_309[4].fieldSizeInBytes = 4;
    dataDesc_309[4].override_field = nullptr;
    dataDesc_309[4].override_count = 0;
    dataDesc_309[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_309[4].flatGroup = 0;
    dataDesc_309[5].fieldType = FIELD_INTEGER;
    dataDesc_309[5].fieldName = "m_iMaxObjectsAttached";
    dataDesc_309[5].fieldOffset = 1272;
    dataDesc_309[5].fieldSize = 1;
    dataDesc_309[5].flags = 6;
    dataDesc_309[5].externalName = "maxobjects";
    dataDesc_309[5].pSaveRestoreOps = nullptr;
    dataDesc_309[5].inputFunc = nullptr;
    dataDesc_309[5].td = nullptr;
    dataDesc_309[5].fieldSizeInBytes = 4;
    dataDesc_309[5].override_field = nullptr;
    dataDesc_309[5].override_count = 0;
    dataDesc_309[5].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_309[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_309[5].flatGroup = 0;
    dataDesc_309[6].fieldType = FIELD_FLOAT;
    dataDesc_309[6].fieldName = "m_forceLimit";
    dataDesc_309[6].fieldOffset = 1224;
    dataDesc_309[6].flags = 6;
    dataDesc_309[7].flags = 6;
    dataDesc_309[6].fieldSize = 1;
    dataDesc_309[7].fieldSize = 1;
    dataDesc_309[8].fieldSize = 1;
    dataDesc_309[6].fieldTolerance = 0.0;
    dataDesc_309[7].fieldTolerance = 0.0;
    dataDesc_309[6].externalName = "forcelimit";
    dataDesc_309[6].pSaveRestoreOps = nullptr;
    dataDesc_309[6].inputFunc = nullptr;
    dataDesc_309[6].td = nullptr;
    dataDesc_309[6].fieldSizeInBytes = 4;
    dataDesc_309[6].override_field = nullptr;
    dataDesc_309[6].override_count = 0;
    *(_QWORD *)dataDesc_309[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_309[6].flatGroup = 0;
    dataDesc_309[7].fieldType = FIELD_FLOAT;
    dataDesc_309[7].fieldName = "m_torqueLimit";
    dataDesc_309[7].fieldOffset = 1228;
    dataDesc_309[7].externalName = "torquelimit";
    dataDesc_309[7].pSaveRestoreOps = nullptr;
    dataDesc_309[7].inputFunc = nullptr;
    dataDesc_309[7].td = nullptr;
    dataDesc_309[7].fieldSizeInBytes = 4;
    dataDesc_309[7].override_field = nullptr;
    dataDesc_309[7].override_count = 0;
    *(_QWORD *)dataDesc_309[7].flatOffset = 0;
    *(_DWORD *)&dataDesc_309[7].flatGroup = 0;
    dataDesc_309[8].fieldType = FIELD_CUSTOM;
    dataDesc_309[8].fieldName = "m_MagnettedEntities";
    dataDesc_309[8].fieldOffset = 1232;
    dataDesc_309[8].flags = 2;
    dataDesc_309[8].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<magnetted_objects_t,CUtlMemory<magnetted_objects_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<magnetted_objects_t,CUtlMemory<magnetted_objects_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<magnetted_objects_t,CUtlMemory<magnetted_objects_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<magnetted_objects_t,CUtlMemory<magnetted_objects_t,int>>,10>::`vftable';
    }
    dataDesc_309[9].fieldType = FIELD_CUSTOM;
    dataDesc_309[8].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<magnetted_objects_t,CUtlMemory<magnetted_objects_t,int>>>'::`2'::ops;
    dataDesc_309[8].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_309[8].td = 0;
    *(_QWORD *)&dataDesc_309[8].override_field = 0;
    *(_QWORD *)&dataDesc_309[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_309[8].flatOffset[1] = 0;
    dataDesc_309[9].fieldName = "m_pConstraintGroup";
    dataDesc_309[9].fieldOffset = 1252;
    dataDesc_309[9].fieldSize = 1;
    dataDesc_309[9].flags = 2;
    dataDesc_309[9].externalName = nullptr;
    dataDesc_309[9].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINTGROUP);
    dataDesc_309[10].fieldType = FIELD_BOOLEAN;
    dataDesc_309[11].fieldType = FIELD_BOOLEAN;
    dataDesc_309[10].fieldSize = 1;
    *(_QWORD *)dataDesc_309[10].flatOffset = 0;
    dataDesc_309[10].flags = 2;
    dataDesc_309[11].fieldSize = 1;
    *(_QWORD *)&dataDesc_309[9].td = 0;
    *(_QWORD *)&dataDesc_309[9].override_field = 0;
    *(_QWORD *)&dataDesc_309[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_309[9].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_309[11].flatOffset = 0;
    dataDesc_309[9].inputFunc = nullptr;
    dataDesc_309[10].fieldName = "m_bActive";
    dataDesc_309[10].fieldOffset = 1256;
    dataDesc_309[10].externalName = nullptr;
    dataDesc_309[10].pSaveRestoreOps = nullptr;
    dataDesc_309[10].inputFunc = nullptr;
    dataDesc_309[10].td = nullptr;
    dataDesc_309[10].fieldSizeInBytes = 1;
    dataDesc_309[10].override_field = nullptr;
    dataDesc_309[10].override_count = 0;
    dataDesc_309[10].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_309[10].flatGroup = 0;
    dataDesc_309[11].fieldName = "m_bHasHitSomething";
    dataDesc_309[11].fieldOffset = 1257;
    dataDesc_309[11].flags = 2;
    dataDesc_309[11].externalName = nullptr;
    dataDesc_309[11].pSaveRestoreOps = nullptr;
    dataDesc_309[11].inputFunc = nullptr;
    dataDesc_309[11].td = nullptr;
    dataDesc_309[11].fieldSizeInBytes = 1;
    dataDesc_309[11].override_field = nullptr;
    dataDesc_309[11].override_count = 0;
    dataDesc_309[11].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_309[11].flatGroup = 0;
    dataDesc_309[12].fieldType = FIELD_FLOAT;
    dataDesc_309[12].fieldName = "m_flTotalMass";
    dataDesc_309[12].fieldOffset = 1260;
    dataDesc_309[12].fieldSize = 1;
    dataDesc_309[12].flags = 2;
    dataDesc_309[12].externalName = nullptr;
    dataDesc_309[12].pSaveRestoreOps = nullptr;
    dataDesc_309[12].inputFunc = nullptr;
    dataDesc_309[12].td = nullptr;
    dataDesc_309[12].fieldSizeInBytes = 4;
    dataDesc_309[12].override_field = nullptr;
    dataDesc_309[12].override_count = 0;
    dataDesc_309[12].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_309[12].flatOffset = 0;
    *(_DWORD *)&dataDesc_309[12].flatGroup = 0;
    dataDesc_309[13].fieldType = FIELD_FLOAT;
    dataDesc_309[13].fieldTolerance = 0.0;
    dataDesc_309[14].fieldTolerance = 0.0;
    dataDesc_309[13].fieldSize = 1;
    *(_QWORD *)dataDesc_309[14].flatOffset = 0;
    dataDesc_309[13].flags = 2;
    dataDesc_309[14].fieldSize = 1;
    *(_QWORD *)&dataDesc_309[15].td = 0;
    *(_QWORD *)&dataDesc_309[15].override_field = 0;
    *(_QWORD *)&dataDesc_309[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_309[15].flatOffset[1] = 0;
    dataDesc_309[14].flags = 2;
    dataDesc_309[15].fieldSize = 1;
    *(_QWORD *)&dataDesc_309[16].td = 0;
    *(_QWORD *)&dataDesc_309[16].override_field = 0;
    *(_QWORD *)&dataDesc_309[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_309[16].flatOffset[1] = 0;
    dataDesc_309[13].fieldSizeInBytes = 4;
    dataDesc_309[14].fieldSizeInBytes = 4;
    dataDesc_309[13].fieldName = "m_flRadius";
    dataDesc_309[13].fieldOffset = 1264;
    dataDesc_309[13].externalName = nullptr;
    dataDesc_309[13].pSaveRestoreOps = nullptr;
    dataDesc_309[13].inputFunc = nullptr;
    dataDesc_309[13].td = nullptr;
    dataDesc_309[13].override_field = nullptr;
    dataDesc_309[13].override_count = 0;
    *(_QWORD *)dataDesc_309[13].flatOffset = 0;
    *(_DWORD *)&dataDesc_309[13].flatGroup = 0;
    dataDesc_309[14].fieldType = FIELD_FLOAT;
    dataDesc_309[14].fieldName = "m_flNextSuckTime";
    dataDesc_309[14].fieldOffset = 1268;
    dataDesc_309[14].externalName = nullptr;
    dataDesc_309[14].pSaveRestoreOps = nullptr;
    dataDesc_309[14].inputFunc = nullptr;
    dataDesc_309[14].td = nullptr;
    dataDesc_309[14].override_field = nullptr;
    dataDesc_309[14].override_count = 0;
    *(_DWORD *)&dataDesc_309[14].flatGroup = 0;
    dataDesc_309[15].fieldType = FIELD_VOID;
    dataDesc_309[15].fieldName = "InputToggle";
    dataDesc_309[15].fieldOffset = 0;
    dataDesc_309[15].flags = 8;
    dataDesc_309[15].externalName = "Toggle";
    dataDesc_309[15].pSaveRestoreOps = nullptr;
    dataDesc_309[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysMagnet::InputToggle;
    dataDesc_309[16].fieldType = FIELD_VOID;
    dataDesc_309[16].fieldName = "InputTurnOn";
    dataDesc_309[16].fieldOffset = 0;
    *(_DWORD *)&dataDesc_309[16].fieldSize = 524289;
    dataDesc_309[16].externalName = "TurnOn";
    dataDesc_309[16].pSaveRestoreOps = nullptr;
    dataDesc_309[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysMagnet::InputTurnOn;
    dataDesc_309[17].fieldType = FIELD_VOID;
    dataDesc_309[17].fieldName = "InputTurnOff";
    dataDesc_309[17].fieldOffset = 0;
    *(_DWORD *)&dataDesc_309[17].fieldSize = 524289;
    dataDesc_309[17].externalName = "TurnOff";
    dataDesc_309[17].pSaveRestoreOps = nullptr;
    dataDesc_309[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysMagnet::InputTurnOff;
    *(_QWORD *)&dataDesc_309[17].td = 0;
    *(_QWORD *)&dataDesc_309[17].override_field = 0;
    *(_QWORD *)&dataDesc_309[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_309[17].flatOffset[1] = 0;
  }
  CPhysMagnet::m_DataMap.dataNumFields = 17;
  CPhysMagnet::m_DataMap.dataDesc = &dataDesc_309[1];
  return &CPhysMagnet::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D0B00
// Name: struct datamap_t __near * DataMapInit<class CPlayerLocalData>(class CPlayerLocalData __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPlayerLocalData>()
{
  if ( (_S7_12 & 1) == 0 )
  {
    _S7_12 |= 1u;
    nameHolder_333.m_pszBase = "CPlayerLocalData";
    nameHolder_333.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_333.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_333.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_333.m_Names.m_Size = 0;
    nameHolder_333.m_Names.m_pElements = nullptr;
    nameHolder_333.m_nLenBase = 16;
    atexit(func: DataMapInit_CPlayerLocalData__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPlayerLocalData::m_DataMap.baseMap = nullptr;
  CPlayerLocalData::m_DataMap.dataNumFields = 24;
  CPlayerLocalData::m_DataMap.dataDesc = &dataDesc_319[1];
  return &CPlayerLocalData::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D7A20
// Name: struct datamap_t __near * DataMapInit<class CPointTemplate>(class CPointTemplate __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointTemplate>()
{
  if ( (_S3_100 & 1) == 0 )
  {
    _S3_100 |= 1u;
    nameHolder_342.m_pszBase = "CPointTemplate";
    nameHolder_342.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_342.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_342.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_342.m_Names.m_Size = 0;
    nameHolder_342.m_Names.m_pElements = nullptr;
    nameHolder_342.m_nLenBase = 14;
    atexit(func: DataMapInit_CPointTemplate__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointTemplate::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_100 & 2) == 0 )
  {
    _S3_100 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<12>::GetDataOps<CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<12>::GetDataOps<CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<12>::GetDataOps<CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int>>,12>::`vftable';
    }
    dataDesc_327[17].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<12>::GetDataOps<CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int>>>'::`2'::ops;
    dataDesc_327[17].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_327[17].td = 0;
    *(_QWORD *)&dataDesc_327[17].override_field = 0;
    *(_QWORD *)&dataDesc_327[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_327[17].flatOffset[1] = 0;
    dataDesc_327[18].fieldType = FIELD_CUSTOM;
    dataDesc_327[18].fieldName = "m_hTemplates";
    dataDesc_327[18].fieldOffset = 936;
    dataDesc_327[18].fieldSize = 1;
    dataDesc_327[18].flags = 2;
    dataDesc_327[18].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<template_t,CUtlMemory<template_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<template_t,CUtlMemory<template_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<template_t,CUtlMemory<template_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<template_t,CUtlMemory<template_t,int>>,10>::`vftable';
    }
    *(_QWORD *)&dataDesc_327[18].td = 0;
    *(_QWORD *)&dataDesc_327[18].override_field = 0;
    *(_QWORD *)&dataDesc_327[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_327[18].flatOffset[1] = 0;
    dataDesc_327[19].fieldSize = 1;
    *(_QWORD *)&dataDesc_327[19].td = 0;
    *(_QWORD *)&dataDesc_327[19].override_field = 0;
    *(_QWORD *)&dataDesc_327[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_327[19].flatOffset[1] = 0;
    dataDesc_327[18].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<template_t,CUtlMemory<template_t,int>>>'::`2'::ops;
    dataDesc_327[18].inputFunc = nullptr;
    dataDesc_327[19].fieldType = FIELD_VOID;
    dataDesc_327[19].fieldName = "InputForceSpawn";
    dataDesc_327[19].fieldOffset = 0;
    dataDesc_327[19].flags = 8;
    dataDesc_327[19].externalName = "ForceSpawn";
    dataDesc_327[19].pSaveRestoreOps = nullptr;
    dataDesc_327[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointTemplate::InputForceSpawn;
    dataDesc_327[20].fieldType = FIELD_CUSTOM;
    dataDesc_327[20].fieldName = "m_pOutputOnSpawned";
    dataDesc_327[20].fieldOffset = 956;
    *(_DWORD *)&dataDesc_327[20].fieldSize = 1441793;
    dataDesc_327[20].externalName = "OnEntitySpawned";
    dataDesc_327[20].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_327[20].inputFunc = 0;
    *(_QWORD *)&dataDesc_327[20].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_327[20].override_count = 0;
    *(_QWORD *)dataDesc_327[20].flatOffset = 0;
    *(_DWORD *)&dataDesc_327[20].flatGroup = 0;
  }
  CPointTemplate::m_DataMap.dataNumFields = 20;
  CPointTemplate::m_DataMap.dataDesc = &dataDesc_327[1];
  return &CPointTemplate::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1025A6D0
// Name: struct datamap_t __near * DataMapInit<class CPassengerInfo>(class CPassengerInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPassengerInfo>()
{
  if ( (_S5_36 & 1) == 0 )
  {
    _S5_36 |= 1u;
    nameHolder_459.m_pszBase = "CPassengerInfo";
    nameHolder_459.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_459.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_459.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_459.m_Names.m_Size = 0;
    nameHolder_459.m_Names.m_pElements = nullptr;
    nameHolder_459.m_nLenBase = 14;
    atexit(func: DataMapInit_CPassengerInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPassengerInfo::m_DataMap.baseMap = nullptr;
  CPassengerInfo::m_DataMap.dataNumFields = 3;
  CPassengerInfo::m_DataMap.dataDesc = &dataDesc_430[1];
  return &CPassengerInfo::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1025A750
// Name: struct datamap_t __near * DataMapInit<class CBaseServerVehicle>(class CBaseServerVehicle __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseServerVehicle>()
{
  ISaveRestoreOps *SoundSaveRestoreOps; // eax

  if ( (_S6_27 & 1) == 0 )
  {
    _S6_27 |= 1u;
    nameHolder_460.m_pszBase = "CBaseServerVehicle";
    nameHolder_460.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_460.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_460.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_460.m_Names.m_Size = 0;
    nameHolder_460.m_Names.m_pElements = nullptr;
    nameHolder_460.m_nLenBase = 18;
    atexit(func: DataMapInit_CBaseServerVehicle__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseServerVehicle::m_DataMap.baseMap = nullptr;
  if ( (_S6_27 & 2) == 0 )
  {
    _S6_27 |= 2u;
    dataDesc_431[8].pSaveRestoreOps = GetSoundSaveRestoreOps();
    dataDesc_431[8].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_431[8].td = 0;
    *(_QWORD *)&dataDesc_431[8].override_field = 0;
    *(_QWORD *)&dataDesc_431[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_431[8].flatOffset[1] = 0;
    dataDesc_431[9].fieldType = FIELD_CUSTOM;
    dataDesc_431[9].fieldName = "m_pStateSoundFade";
    dataDesc_431[9].fieldOffset = 400;
    dataDesc_431[9].fieldSize = 1;
    dataDesc_431[9].flags = 2;
    dataDesc_431[9].externalName = nullptr;
    SoundSaveRestoreOps = GetSoundSaveRestoreOps();
    dataDesc_431[10].fieldSize = 1;
    dataDesc_431[11].fieldSize = 1;
    dataDesc_431[9].pSaveRestoreOps = SoundSaveRestoreOps;
    dataDesc_431[11].flags = 2;
    *(_QWORD *)dataDesc_431[10].flatOffset = 0;
    dataDesc_431[10].flags = 2;
    dataDesc_431[12].fieldSize = 1;
    *(_QWORD *)&dataDesc_431[9].td = 0;
    *(_QWORD *)&dataDesc_431[9].override_field = 0;
    *(_QWORD *)&dataDesc_431[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_431[9].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_431[11].flatOffset = 0;
    dataDesc_431[9].inputFunc = nullptr;
    dataDesc_431[10].fieldType = FIELD_INTEGER;
    dataDesc_431[10].fieldName = "m_soundState";
    dataDesc_431[10].fieldOffset = 404;
    dataDesc_431[10].externalName = nullptr;
    dataDesc_431[10].pSaveRestoreOps = nullptr;
    dataDesc_431[10].inputFunc = nullptr;
    dataDesc_431[10].td = nullptr;
    dataDesc_431[10].fieldSizeInBytes = 4;
    dataDesc_431[10].override_field = nullptr;
    dataDesc_431[10].override_count = 0;
    dataDesc_431[10].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_431[10].flatGroup = 0;
    dataDesc_431[11].fieldType = FIELD_TIME;
    dataDesc_431[11].fieldName = "m_soundStateStartTime";
    dataDesc_431[11].fieldOffset = 408;
    dataDesc_431[11].externalName = nullptr;
    dataDesc_431[11].pSaveRestoreOps = nullptr;
    dataDesc_431[11].inputFunc = nullptr;
    dataDesc_431[11].td = nullptr;
    dataDesc_431[11].fieldSizeInBytes = 4;
    dataDesc_431[11].override_field = nullptr;
    dataDesc_431[11].override_count = 0;
    dataDesc_431[11].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_431[11].flatGroup = 0;
    dataDesc_431[12].fieldType = FIELD_FLOAT;
    dataDesc_431[12].fieldName = "m_lastSpeed";
    dataDesc_431[12].fieldOffset = 412;
    dataDesc_431[12].flags = 2;
    dataDesc_431[12].externalName = nullptr;
    dataDesc_431[12].pSaveRestoreOps = nullptr;
    dataDesc_431[12].inputFunc = nullptr;
    dataDesc_431[12].td = nullptr;
    dataDesc_431[12].fieldSizeInBytes = 4;
    dataDesc_431[12].override_field = nullptr;
    dataDesc_431[12].override_count = 0;
    dataDesc_431[12].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_431[12].flatOffset = 0;
    *(_DWORD *)&dataDesc_431[12].flatGroup = 0;
    dataDesc_431[13].flags = 2;
    dataDesc_431[14].flags = 2;
    dataDesc_431[13].fieldType = FIELD_INTEGER;
    dataDesc_431[15].fieldSize = 1;
    *(_QWORD *)dataDesc_431[13].flatOffset = 0;
    dataDesc_431[13].fieldSize = 1;
    dataDesc_431[14].fieldSize = 1;
    dataDesc_431[15].flags = 2;
    *(_QWORD *)dataDesc_431[14].flatOffset = 0;
    dataDesc_431[14].fieldSizeInBytes = 12;
    dataDesc_431[16].fieldSize = 1;
    dataDesc_431[16].fieldSizeInBytes = 12;
    *(_QWORD *)dataDesc_431[15].flatOffset = 0;
    dataDesc_431[13].fieldName = "m_iCurrentExitAnim";
    dataDesc_431[13].fieldOffset = 108;
    dataDesc_431[13].externalName = nullptr;
    dataDesc_431[13].pSaveRestoreOps = nullptr;
    dataDesc_431[13].inputFunc = nullptr;
    dataDesc_431[13].td = nullptr;
    dataDesc_431[13].fieldSizeInBytes = 4;
    dataDesc_431[13].override_field = nullptr;
    dataDesc_431[13].override_count = 0;
    dataDesc_431[13].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_431[13].flatGroup = 0;
    dataDesc_431[14].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_431[14].fieldName = "m_vecCurrentExitEndPoint";
    dataDesc_431[14].fieldOffset = 112;
    dataDesc_431[14].externalName = nullptr;
    dataDesc_431[14].pSaveRestoreOps = nullptr;
    dataDesc_431[14].inputFunc = nullptr;
    dataDesc_431[14].td = nullptr;
    dataDesc_431[14].override_field = nullptr;
    dataDesc_431[14].override_count = 0;
    dataDesc_431[14].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_431[14].flatGroup = 0;
    dataDesc_431[15].fieldType = FIELD_CHARACTER;
    dataDesc_431[15].fieldName = "m_chPreviousTextureType";
    dataDesc_431[15].fieldOffset = 140;
    dataDesc_431[15].externalName = nullptr;
    dataDesc_431[15].pSaveRestoreOps = nullptr;
    dataDesc_431[15].inputFunc = nullptr;
    dataDesc_431[15].td = nullptr;
    dataDesc_431[15].fieldSizeInBytes = 1;
    dataDesc_431[15].override_field = nullptr;
    dataDesc_431[15].override_count = 0;
    dataDesc_431[15].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_431[15].flatGroup = 0;
    dataDesc_431[16].fieldType = FIELD_VECTOR;
    dataDesc_431[16].fieldName = "m_savedViewOffset";
    dataDesc_431[16].fieldOffset = 124;
    dataDesc_431[16].flags = 2;
    dataDesc_431[16].externalName = nullptr;
    dataDesc_431[16].pSaveRestoreOps = nullptr;
    dataDesc_431[16].inputFunc = nullptr;
    dataDesc_431[16].td = nullptr;
    dataDesc_431[16].override_field = nullptr;
    dataDesc_431[16].override_count = 0;
    dataDesc_431[16].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_431[16].flatOffset = 0;
    *(_DWORD *)&dataDesc_431[16].flatGroup = 0;
    dataDesc_431[17].fieldType = FIELD_EHANDLE;
    dataDesc_431[17].fieldName = "m_hExitBlocker";
    dataDesc_431[17].fieldOffset = 136;
    dataDesc_431[17].fieldSize = 1;
    dataDesc_431[17].flags = 2;
    dataDesc_431[17].externalName = nullptr;
    dataDesc_431[17].pSaveRestoreOps = nullptr;
    dataDesc_431[17].inputFunc = nullptr;
    dataDesc_431[17].td = nullptr;
    dataDesc_431[17].fieldSizeInBytes = 4;
    dataDesc_431[18].fieldOffset = 4;
    dataDesc_431[17].fieldTolerance = 0.0;
    dataDesc_431[17].override_field = nullptr;
    dataDesc_431[17].override_count = 0;
    *(_QWORD *)dataDesc_431[17].flatOffset = 0;
    *(_DWORD *)&dataDesc_431[17].flatGroup = 0;
    dataDesc_431[18].fieldType = FIELD_CUSTOM;
    dataDesc_431[18].fieldName = "m_PassengerInfo";
    dataDesc_431[18].fieldSize = 1;
    dataDesc_431[18].flags = 2;
    dataDesc_431[18].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int>>,10>::`vftable';
    }
    dataDesc_431[18].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int>>>'::`2'::ops;
    dataDesc_431[18].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_431[18].td = 0;
    *(_QWORD *)&dataDesc_431[18].override_field = 0;
    *(_QWORD *)&dataDesc_431[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_431[18].flatOffset[1] = 0;
  }
  CBaseServerVehicle::m_DataMap.dataNumFields = 18;
  CBaseServerVehicle::m_DataMap.dataDesc = &dataDesc_431[1];
  return &CBaseServerVehicle::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10298460
// Name: struct datamap_t __near * DataMapInit<class CPropJeep>(class CPropJeep __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPropJeep>()
{
  ISaveRestoreOps *SoundSaveRestoreOps; // eax

  if ( (_S3_149 & 1) == 0 )
  {
    _S3_149 |= 1u;
    nameHolder_476.m_pszBase = "CPropJeep";
    nameHolder_476.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_476.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_476.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_476.m_Names.m_Size = 0;
    nameHolder_476.m_Names.m_pElements = nullptr;
    nameHolder_476.m_nLenBase = 9;
    atexit(func: DataMapInit_CPropJeep__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPropJeep::m_DataMap.baseMap = &CPropVehicleDriveable::m_DataMap;
  if ( (_S3_149 & 2) == 0 )
  {
    _S3_149 |= 2u;
    SoundSaveRestoreOps = GetSoundSaveRestoreOps();
    *(_QWORD *)dataDesc_444[9].flatOffset = 0;
    dataDesc_444[8].pSaveRestoreOps = SoundSaveRestoreOps;
    *(_QWORD *)dataDesc_444[10].flatOffset = 0;
    dataDesc_444[9].fieldSize = 1;
    dataDesc_444[9].flags = 2;
    dataDesc_444[10].fieldSize = 1;
    dataDesc_444[10].flags = 2;
    dataDesc_444[11].fieldSize = 1;
    dataDesc_444[11].flags = 2;
    dataDesc_444[12].fieldSize = 1;
    *(_QWORD *)&dataDesc_444[8].td = 0;
    *(_QWORD *)&dataDesc_444[8].override_field = 0;
    *(_QWORD *)&dataDesc_444[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_444[8].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_444[11].flatOffset = 0;
    dataDesc_444[8].inputFunc = nullptr;
    dataDesc_444[9].fieldType = FIELD_INTEGER;
    dataDesc_444[9].fieldName = "m_nSpinPos";
    dataDesc_444[9].fieldOffset = 1784;
    dataDesc_444[9].externalName = nullptr;
    dataDesc_444[9].pSaveRestoreOps = nullptr;
    dataDesc_444[9].inputFunc = nullptr;
    dataDesc_444[9].td = nullptr;
    dataDesc_444[9].fieldSizeInBytes = 4;
    dataDesc_444[9].override_field = nullptr;
    dataDesc_444[9].override_count = 0;
    dataDesc_444[9].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_444[9].flatGroup = 0;
    dataDesc_444[10].fieldType = FIELD_FLOAT;
    dataDesc_444[10].fieldName = "m_aimYaw";
    dataDesc_444[10].fieldOffset = 1788;
    dataDesc_444[10].externalName = nullptr;
    dataDesc_444[10].pSaveRestoreOps = nullptr;
    dataDesc_444[10].inputFunc = nullptr;
    dataDesc_444[10].td = nullptr;
    dataDesc_444[10].fieldSizeInBytes = 4;
    dataDesc_444[10].override_field = nullptr;
    dataDesc_444[10].override_count = 0;
    dataDesc_444[10].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_444[10].flatGroup = 0;
    dataDesc_444[11].fieldType = FIELD_FLOAT;
    dataDesc_444[11].fieldName = "m_aimPitch";
    dataDesc_444[11].fieldOffset = 1792;
    dataDesc_444[11].externalName = nullptr;
    dataDesc_444[11].pSaveRestoreOps = nullptr;
    dataDesc_444[11].inputFunc = nullptr;
    dataDesc_444[11].td = nullptr;
    dataDesc_444[11].fieldSizeInBytes = 4;
    dataDesc_444[11].override_field = nullptr;
    dataDesc_444[11].override_count = 0;
    dataDesc_444[11].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_444[11].flatGroup = 0;
    dataDesc_444[12].fieldType = FIELD_TIME;
    dataDesc_444[12].fieldName = "m_throttleDisableTime";
    dataDesc_444[12].fieldOffset = 1796;
    dataDesc_444[12].flags = 2;
    dataDesc_444[12].externalName = nullptr;
    dataDesc_444[12].pSaveRestoreOps = nullptr;
    dataDesc_444[12].inputFunc = nullptr;
    dataDesc_444[12].td = nullptr;
    dataDesc_444[12].fieldSizeInBytes = 4;
    dataDesc_444[12].override_field = nullptr;
    dataDesc_444[12].override_count = 0;
    dataDesc_444[12].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_444[12].flatOffset = 0;
    *(_DWORD *)&dataDesc_444[12].flatGroup = 0;
    dataDesc_444[13].fieldSize = 1;
    dataDesc_444[13].flags = 2;
    dataDesc_444[14].fieldSize = 1;
    dataDesc_444[14].flags = 2;
    dataDesc_444[15].fieldSize = 1;
    dataDesc_444[15].flags = 2;
    dataDesc_444[16].fieldSize = 1;
    *(_QWORD *)dataDesc_444[13].flatOffset = 0;
    dataDesc_444[16].flags = 2;
    *(_QWORD *)dataDesc_444[14].flatOffset = 0;
    dataDesc_444[17].fieldSize = 1;
    *(_QWORD *)dataDesc_444[15].flatOffset = 0;
    dataDesc_444[13].fieldType = FIELD_TIME;
    dataDesc_444[13].fieldName = "m_flHandbrakeTime";
    dataDesc_444[13].fieldOffset = 1804;
    dataDesc_444[13].externalName = nullptr;
    dataDesc_444[13].pSaveRestoreOps = nullptr;
    dataDesc_444[13].inputFunc = nullptr;
    dataDesc_444[13].td = nullptr;
    dataDesc_444[13].fieldSizeInBytes = 4;
    dataDesc_444[13].override_field = nullptr;
    dataDesc_444[13].override_count = 0;
    dataDesc_444[13].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_444[13].flatGroup = 0;
    dataDesc_444[14].fieldType = FIELD_BOOLEAN;
    dataDesc_444[14].fieldName = "m_bInitialHandbrake";
    dataDesc_444[14].fieldOffset = 1808;
    dataDesc_444[14].externalName = nullptr;
    dataDesc_444[14].pSaveRestoreOps = nullptr;
    dataDesc_444[14].inputFunc = nullptr;
    dataDesc_444[14].td = nullptr;
    dataDesc_444[14].fieldSizeInBytes = 1;
    dataDesc_444[14].override_field = nullptr;
    dataDesc_444[14].override_count = 0;
    dataDesc_444[14].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_444[14].flatGroup = 0;
    dataDesc_444[15].fieldType = FIELD_TIME;
    dataDesc_444[15].fieldName = "m_flOverturnedTime";
    dataDesc_444[15].fieldOffset = 1812;
    dataDesc_444[15].externalName = nullptr;
    dataDesc_444[15].pSaveRestoreOps = nullptr;
    dataDesc_444[15].inputFunc = nullptr;
    dataDesc_444[15].td = nullptr;
    dataDesc_444[15].fieldSizeInBytes = 4;
    dataDesc_444[15].override_field = nullptr;
    dataDesc_444[15].override_count = 0;
    dataDesc_444[15].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_444[15].flatGroup = 0;
    dataDesc_444[16].fieldType = FIELD_FLOAT;
    dataDesc_444[16].fieldName = "m_flAmmoCrateCloseTime";
    dataDesc_444[16].fieldOffset = 1800;
    dataDesc_444[16].externalName = nullptr;
    dataDesc_444[16].pSaveRestoreOps = nullptr;
    dataDesc_444[16].inputFunc = nullptr;
    dataDesc_444[16].td = nullptr;
    dataDesc_444[16].fieldSizeInBytes = 4;
    dataDesc_444[16].override_field = nullptr;
    dataDesc_444[16].override_count = 0;
    dataDesc_444[16].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_444[16].flatOffset = 0;
    *(_DWORD *)&dataDesc_444[16].flatGroup = 0;
    dataDesc_444[17].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_444[17].fieldName = "m_vecLastEyePos";
    dataDesc_444[17].fieldOffset = 1816;
    dataDesc_444[17].flags = 2;
    dataDesc_444[17].externalName = nullptr;
    dataDesc_444[18].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_444[18].fieldSize = 1;
    dataDesc_444[18].flags = 2;
    dataDesc_444[19].fieldSize = 1;
    dataDesc_444[19].flags = 2;
    dataDesc_444[20].fieldSize = 1;
    *(_QWORD *)dataDesc_444[17].flatOffset = 0;
    dataDesc_444[20].flags = 2;
    *(_QWORD *)dataDesc_444[18].flatOffset = 0;
    dataDesc_444[17].fieldSizeInBytes = 12;
    dataDesc_444[18].fieldSizeInBytes = 12;
    dataDesc_444[19].fieldSizeInBytes = 12;
    dataDesc_444[20].fieldSizeInBytes = 12;
    dataDesc_444[21].fieldSize = 1;
    *(_QWORD *)dataDesc_444[19].flatOffset = 0;
    dataDesc_444[17].pSaveRestoreOps = nullptr;
    dataDesc_444[17].inputFunc = nullptr;
    dataDesc_444[17].td = nullptr;
    dataDesc_444[17].override_field = nullptr;
    dataDesc_444[17].override_count = 0;
    dataDesc_444[17].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_444[17].flatGroup = 0;
    dataDesc_444[18].fieldName = "m_vecLastEyeTarget";
    dataDesc_444[18].fieldOffset = 1828;
    dataDesc_444[18].externalName = nullptr;
    dataDesc_444[18].pSaveRestoreOps = nullptr;
    dataDesc_444[18].inputFunc = nullptr;
    dataDesc_444[18].td = nullptr;
    dataDesc_444[18].override_field = nullptr;
    dataDesc_444[18].override_count = 0;
    dataDesc_444[18].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_444[18].flatGroup = 0;
    dataDesc_444[19].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_444[19].fieldName = "m_vecEyeSpeed";
    dataDesc_444[19].fieldOffset = 1840;
    dataDesc_444[19].externalName = nullptr;
    dataDesc_444[19].pSaveRestoreOps = nullptr;
    dataDesc_444[19].inputFunc = nullptr;
    dataDesc_444[19].td = nullptr;
    dataDesc_444[19].override_field = nullptr;
    dataDesc_444[19].override_count = 0;
    dataDesc_444[19].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_444[19].flatGroup = 0;
    dataDesc_444[20].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_444[20].fieldName = "m_vecTargetSpeed";
    dataDesc_444[20].fieldOffset = 1852;
    dataDesc_444[20].externalName = nullptr;
    dataDesc_444[20].pSaveRestoreOps = nullptr;
    dataDesc_444[20].inputFunc = nullptr;
    dataDesc_444[20].td = nullptr;
    dataDesc_444[20].override_field = nullptr;
    dataDesc_444[20].override_count = 0;
    dataDesc_444[20].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_444[20].flatOffset = 0;
    *(_DWORD *)&dataDesc_444[20].flatGroup = 0;
    dataDesc_444[21].fieldType = FIELD_BOOLEAN;
    dataDesc_444[21].fieldName = "m_bHeadlightIsOn";
    dataDesc_444[21].fieldOffset = 1961;
    dataDesc_444[21].flags = 2;
    dataDesc_444[21].externalName = nullptr;
    dataDesc_444[21].pSaveRestoreOps = nullptr;
    dataDesc_444[21].inputFunc = nullptr;
    dataDesc_444[21].td = nullptr;
    dataDesc_444[21].fieldSizeInBytes = 1;
    dataDesc_444[21].override_field = nullptr;
    dataDesc_444[21].override_count = 0;
    dataDesc_444[21].fieldTolerance = 0.0;
    dataDesc_444[22].fieldSize = 1;
    dataDesc_444[22].flags = 2;
    dataDesc_444[23].fieldSize = 1;
    dataDesc_444[23].flags = 2;
    *(_QWORD *)dataDesc_444[21].flatOffset = 0;
    dataDesc_444[24].fieldSize = 1;
    *(_QWORD *)dataDesc_444[22].flatOffset = 0;
    dataDesc_444[24].flags = 2;
    *(_QWORD *)dataDesc_444[23].flatOffset = 0;
    dataDesc_444[25].fieldType = FIELD_TIME;
    dataDesc_444[26].fieldType = FIELD_TIME;
    dataDesc_444[25].fieldSize = 1;
    *(_QWORD *)dataDesc_444[24].flatOffset = 0;
    dataDesc_444[26].fieldSize = 1;
    *(_DWORD *)&dataDesc_444[21].flatGroup = 0;
    dataDesc_444[22].fieldType = FIELD_EMBEDDED;
    dataDesc_444[22].fieldName = "m_WaterData";
    dataDesc_444[22].fieldOffset = 1864;
    dataDesc_444[22].externalName = nullptr;
    dataDesc_444[22].pSaveRestoreOps = nullptr;
    dataDesc_444[22].inputFunc = nullptr;
    dataDesc_444[22].td = &JeepWaterData_t::m_DataMap;
    dataDesc_444[22].fieldSizeInBytes = 76;
    dataDesc_444[22].override_field = nullptr;
    dataDesc_444[22].override_count = 0;
    dataDesc_444[22].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_444[22].flatGroup = 0;
    dataDesc_444[23].fieldType = FIELD_INTEGER;
    dataDesc_444[23].fieldName = "m_iNumberOfEntries";
    dataDesc_444[23].fieldOffset = 1940;
    dataDesc_444[23].externalName = nullptr;
    dataDesc_444[23].pSaveRestoreOps = nullptr;
    dataDesc_444[23].inputFunc = nullptr;
    dataDesc_444[23].td = nullptr;
    dataDesc_444[23].fieldSizeInBytes = 4;
    dataDesc_444[23].override_field = nullptr;
    dataDesc_444[23].override_count = 0;
    dataDesc_444[23].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_444[23].flatGroup = 0;
    dataDesc_444[24].fieldType = FIELD_INTEGER;
    dataDesc_444[24].fieldName = "m_nAmmoType";
    dataDesc_444[24].fieldOffset = 1944;
    dataDesc_444[24].externalName = nullptr;
    dataDesc_444[24].pSaveRestoreOps = nullptr;
    dataDesc_444[24].inputFunc = nullptr;
    dataDesc_444[24].td = nullptr;
    dataDesc_444[24].fieldSizeInBytes = 4;
    dataDesc_444[24].override_field = nullptr;
    dataDesc_444[24].override_count = 0;
    dataDesc_444[24].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_444[24].flatGroup = 0;
    dataDesc_444[25].fieldName = "m_flPlayerExitedTime";
    dataDesc_444[25].fieldOffset = 1948;
    dataDesc_444[25].flags = 2;
    dataDesc_444[25].externalName = nullptr;
    dataDesc_444[25].pSaveRestoreOps = nullptr;
    dataDesc_444[25].inputFunc = nullptr;
    dataDesc_444[25].td = nullptr;
    dataDesc_444[25].fieldSizeInBytes = 4;
    dataDesc_444[25].override_field = nullptr;
    dataDesc_444[25].override_count = 0;
    dataDesc_444[25].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_444[25].flatOffset = 0;
    *(_DWORD *)&dataDesc_444[25].flatGroup = 0;
    dataDesc_444[26].fieldName = "m_flLastSawPlayerAt";
    dataDesc_444[26].fieldOffset = 1952;
    dataDesc_444[26].flags = 2;
    dataDesc_444[26].fieldTolerance = 0.0;
    dataDesc_444[27].fieldTolerance = 0.0;
    dataDesc_444[28].fieldTolerance = 0.0;
    dataDesc_444[27].fieldSize = 1;
    dataDesc_444[28].fieldType = FIELD_BOOLEAN;
    *(_QWORD *)dataDesc_444[28].flatOffset = 0;
    dataDesc_444[26].fieldSizeInBytes = 4;
    dataDesc_444[27].fieldSizeInBytes = 4;
    dataDesc_444[27].flags = 2;
    dataDesc_444[28].fieldSize = 1;
    *(_QWORD *)dataDesc_444[26].flatOffset = 0;
    *(_QWORD *)&dataDesc_444[29].td = 0;
    *(_QWORD *)&dataDesc_444[29].override_field = 0;
    *(_QWORD *)&dataDesc_444[29].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_444[29].flatOffset[1] = 0;
    dataDesc_444[26].externalName = nullptr;
    dataDesc_444[26].pSaveRestoreOps = nullptr;
    dataDesc_444[26].inputFunc = nullptr;
    dataDesc_444[26].td = nullptr;
    dataDesc_444[26].override_field = nullptr;
    dataDesc_444[26].override_count = 0;
    *(_DWORD *)&dataDesc_444[26].flatGroup = 0;
    dataDesc_444[27].fieldType = FIELD_EHANDLE;
    dataDesc_444[27].fieldName = "m_hLastPlayerInVehicle";
    dataDesc_444[27].fieldOffset = 1956;
    dataDesc_444[27].externalName = nullptr;
    dataDesc_444[27].pSaveRestoreOps = nullptr;
    dataDesc_444[27].inputFunc = nullptr;
    dataDesc_444[27].td = nullptr;
    dataDesc_444[27].override_field = nullptr;
    dataDesc_444[27].override_count = 0;
    *(_QWORD *)dataDesc_444[27].flatOffset = 0;
    *(_DWORD *)&dataDesc_444[27].flatGroup = 0;
    dataDesc_444[28].fieldName = "m_bHasPoop";
    dataDesc_444[28].fieldOffset = 1960;
    dataDesc_444[28].flags = 2;
    dataDesc_444[28].externalName = nullptr;
    dataDesc_444[28].pSaveRestoreOps = nullptr;
    dataDesc_444[28].inputFunc = nullptr;
    dataDesc_444[28].td = nullptr;
    dataDesc_444[28].fieldSizeInBytes = 1;
    dataDesc_444[28].override_field = nullptr;
    dataDesc_444[28].override_count = 0;
    *(_DWORD *)&dataDesc_444[28].flatGroup = 0;
    dataDesc_444[29].fieldType = FIELD_VOID;
    dataDesc_444[29].fieldName = "InputStartRemoveTauCannon";
    dataDesc_444[29].fieldOffset = 0;
    dataDesc_444[29].fieldSize = 1;
    dataDesc_444[29].flags = 8;
    dataDesc_444[29].externalName = "StartRemoveTauCannon";
    dataDesc_444[29].pSaveRestoreOps = nullptr;
    dataDesc_444[29].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPropJeep::InputStartRemoveTauCannon;
    dataDesc_444[30].fieldType = FIELD_VOID;
    dataDesc_444[30].fieldName = "InputFinishRemoveTauCannon";
    dataDesc_444[30].fieldOffset = 0;
    *(_DWORD *)&dataDesc_444[30].fieldSize = 524289;
    dataDesc_444[30].externalName = "FinishRemoveTauCannon";
    dataDesc_444[30].pSaveRestoreOps = nullptr;
    dataDesc_444[30].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPropJeep::InputFinishRemoveTauCannon;
    *(_QWORD *)&dataDesc_444[30].td = 0;
    *(_QWORD *)&dataDesc_444[30].override_field = 0;
    *(_QWORD *)&dataDesc_444[30].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_444[30].flatOffset[1] = 0;
  }
  CPropJeep::m_DataMap.dataNumFields = 30;
  CPropJeep::m_DataMap.dataDesc = &dataDesc_444[1];
  return &CPropJeep::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1030A3F0
// Name: struct datamap_t __near * DataMapInit<class CFuncNavObstruction>(class CFuncNavObstruction __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncNavObstruction>()
{
  if ( (_S3_165 & 1) == 0 )
  {
    _S3_165 |= 1u;
    nameHolder_501.m_pszBase = "CFuncNavObstruction";
    nameHolder_501.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_501.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_501.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_501.m_Names.m_Size = 0;
    nameHolder_501.m_Names.m_pElements = nullptr;
    nameHolder_501.m_nLenBase = 19;
    atexit(func: DataMapInit_CFuncNavObstruction__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncNavObstruction::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFuncNavObstruction::m_DataMap.dataNumFields = 1;
  CFuncNavObstruction::m_DataMap.dataDesc = &dataDesc_452[1];
  return &CFuncNavObstruction::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1030A620
// Name: struct datamap_t __near * DataMapInit<class CFuncNavBlocker>(class CFuncNavBlocker __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncNavBlocker>()
{
  if ( (_S2_308 & 1) == 0 )
  {
    _S2_308 |= 1u;
    nameHolder_502.m_pszBase = "CFuncNavBlocker";
    nameHolder_502.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_502.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_502.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_502.m_Names.m_Size = 0;
    nameHolder_502.m_Names.m_pElements = nullptr;
    nameHolder_502.m_nLenBase = 15;
    atexit(func: DataMapInit_CFuncNavBlocker__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncNavBlocker::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFuncNavBlocker::m_DataMap.dataNumFields = 4;
  CFuncNavBlocker::m_DataMap.dataDesc = &dataDesc_453[1];
  return &CFuncNavBlocker::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10421280
// Name: _DataMapInit_CFuncNavBlocker__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncNavBlocker__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_502);
}

//------------------------------------------------------------------------------
// Address: 0x10421290
// Name: _DataMapInit_CFuncNavObstruction__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncNavObstruction__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_501);
}

//------------------------------------------------------------------------------
// Address: 0x104212A0
// Name: _dynamic_atexit_destructor_for__nav_check_file_consistency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_check_file_consistency__()
{
  ConCommand::~ConCommand(this: &nav_check_file_consistency);
}

//------------------------------------------------------------------------------
// Address: 0x104212B0
// Name: _dynamic_atexit_destructor_for__placeDirectory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__placeDirectory__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&placeDirectory);
}

//------------------------------------------------------------------------------
// Address: 0x104212C0
// Name: _dynamic_atexit_destructor_for__nav_slope_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_slope_limit__()
{
  ConVar::~ConVar(this: &nav_slope_limit);
}

//------------------------------------------------------------------------------
// Address: 0x104212D0
// Name: _dynamic_atexit_destructor_for__nav_slope_tolerance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_slope_tolerance__()
{
  ConVar::~ConVar(this: &nav_slope_tolerance);
}

//------------------------------------------------------------------------------
// Address: 0x104212E0
// Name: _dynamic_atexit_destructor_for__nav_displacement_test__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_displacement_test__()
{
  ConVar::~ConVar(this: &nav_displacement_test);
}

//------------------------------------------------------------------------------
// Address: 0x104212F0
// Name: _dynamic_atexit_destructor_for__nav_generate_fencetops__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_generate_fencetops__()
{
  ConVar::~ConVar(this: &nav_generate_fencetops);
}

//------------------------------------------------------------------------------
// Address: 0x10421300
// Name: _dynamic_atexit_destructor_for__nav_generate_fixup_jump_areas__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_generate_fixup_jump_areas__()
{
  ConVar::~ConVar(this: &nav_generate_fixup_jump_areas);
}

//------------------------------------------------------------------------------
// Address: 0x10421310
// Name: _dynamic_atexit_destructor_for__nav_generate_incremental_range__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_generate_incremental_range__()
{
  ConVar::~ConVar(this: &nav_generate_incremental_range);
}

//------------------------------------------------------------------------------
// Address: 0x10421320
// Name: _dynamic_atexit_destructor_for__nav_generate_incremental_tolerance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_generate_incremental_tolerance__()
{
  ConVar::~ConVar(this: &nav_generate_incremental_tolerance);
}

//------------------------------------------------------------------------------
// Address: 0x10421330
// Name: _dynamic_atexit_destructor_for__nav_area_max_size__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_area_max_size__()
{
  ConVar::~ConVar(this: &nav_area_max_size);
}

//------------------------------------------------------------------------------
// Address: 0x10421340
// Name: _dynamic_atexit_destructor_for__nav_check_stairs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_check_stairs__()
{
  ConCommand::~ConCommand(this: &nav_check_stairs);
}

//------------------------------------------------------------------------------
// Address: 0x10421350
// Name: _dynamic_atexit_destructor_for__nav_test_stairs_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_test_stairs_command__()
{
  ConCommand::~ConCommand(this: &nav_test_stairs_command);
}

//------------------------------------------------------------------------------
// Address: 0x10421360
// Name: _dynamic_atexit_destructor_for__nav_subdivide_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_subdivide_command__()
{
  ConCommand::~ConCommand(this: &nav_subdivide_command);
}

//------------------------------------------------------------------------------
// Address: 0x10421370
// Name: _dynamic_atexit_destructor_for__nav_gen_cliffs_approx_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_gen_cliffs_approx_command__()
{
  ConCommand::~ConCommand(this: &nav_gen_cliffs_approx_command);
}
