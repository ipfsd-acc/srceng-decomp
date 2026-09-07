// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/sqlaccess/recordinfo.cpp
// Functions: 18
// ============================================================

#include "gcsdk\sqlaccess\recordinfo.h"

//------------------------------------------------------------------------------
// Address: 0x10054C20
// Name: _dynamic_initializer_for__GCSDK::CRecordInfo::sm_MemPoolRecordInfo__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__GCSDK::CRecordInfo::sm_MemPoolRecordInfo__()
{
  CThreadSafeMemoryPool::CThreadSafeMemoryPool(
    this: &GCSDK::CRecordInfo::sm_MemPoolRecordInfo,
    blockSize: 312,
    numElements: 10,
    growMode: 1);
  return atexit(func: dynamic_atexit_destructor_for__GCSDK::CRecordInfo::sm_MemPoolRecordInfo__);
}

//------------------------------------------------------------------------------
// Address: 0x100554F0
// Name: _dynamic_atexit_destructor_for__GCSDK::CRecordInfo::sm_MemPoolRecordInfo__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__GCSDK::CRecordInfo::sm_MemPoolRecordInfo__()
{
  CThreadSafeMemoryPool::~CThreadSafeMemoryPool(this: &GCSDK::CRecordInfo::sm_MemPoolRecordInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10054C40
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x10054C60
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10054C70
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x10054C90
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10054CA0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (int)s_StringCharConversion.m_pConversion,
    value: nullptr,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10054D00
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10054D30
// Name: _dynamic_initializer_for__g_BitWriteMasksInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBitWriteMasksInit *dynamic_initializer_for__g_BitWriteMasksInit__()
{
  return CBitWriteMasksInit::CBitWriteMasksInit(this: &g_BitWriteMasksInit);
}

//------------------------------------------------------------------------------
// Address: 0x10054D40
// Name: _dynamic_atexit_destructor_for__g_MatchTitleGameSettingsMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchTitleGameSettingsMgr__()
{
  g_MatchTitleGameSettingsMgr.__vftable = (CMatchTitleGameSettingsMgr_vtbl *)&CMatchTitleGameSettingsMgr::`vftable';
  if ( g_MatchTitleGameSettingsMgr.m_pMatchSystemData != nullptr )
    KeyValues::deleteThis(this: g_MatchTitleGameSettingsMgr.m_pMatchSystemData);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchTitleGameSettingsMgr.m_SearchPass);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchTitleGameSettingsMgr.m_FormulaSkill);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &g_MatchTitleGameSettingsMgr.m_FormulaExperience);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &g_MatchTitleGameSettingsMgr.m_FormulaAverage);
}

//------------------------------------------------------------------------------
// Address: 0x10054D90
// Name: _dynamic_atexit_destructor_for__g_MatchTitle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchTitle__()
{
  CMatchTitle::~CMatchTitle(this: &g_MatchTitle);
}

//------------------------------------------------------------------------------
// Address: 0x10054DA0
// Name: _dynamic_atexit_destructor_for__cl_titledataversionblock1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_titledataversionblock1__()
{
  ConVar::~ConVar(this: &cl_titledataversionblock1);
}

//------------------------------------------------------------------------------
// Address: 0x10054DB0
// Name: _dynamic_atexit_destructor_for__cl_titledataversionblock2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_titledataversionblock2__()
{
  ConVar::~ConVar(this: &cl_titledataversionblock2);
}

//------------------------------------------------------------------------------
// Address: 0x10054DC0
// Name: _dynamic_atexit_destructor_for__cl_titledataversionblock3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_titledataversionblock3__()
{
  ConVar::~ConVar(this: &cl_titledataversionblock3);
}

//------------------------------------------------------------------------------
// Address: 0x10054DD0
// Name: _PrepareTitleDataStorageDescription_::_2_::_dynamic_atexit_destructor_for__s_tdfd__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl PrepareTitleDataStorageDescription_::_2_::_dynamic_atexit_destructor_for__s_tdfd__()
{
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: &stru_10081830);
}

//------------------------------------------------------------------------------
// Address: 0x10055500
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x10055510
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10055560
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}
