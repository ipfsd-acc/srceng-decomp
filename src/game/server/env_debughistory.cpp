// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_debughistory.cpp
// Functions: 15
// ============================================================

#include "game\server\env_debughistory.h"

//------------------------------------------------------------------------------
// Address: 0x10110EB0
// Name: public: virtual struct datamap_t __near * CDebugHistory::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CDebugHistory::GetDataDescMap(CDebugHistory *this)
{
  return &CDebugHistory::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10110EC0
// Name: public: void CDebugHistory::ClearHistories(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugHistory::ClearHistories(CDebugHistory *this)
{
  char **m_DebugLineEnd; // edi
  char *v2; // esi
  int i; // ebx

  m_DebugLineEnd = this->m_DebugLineEnd;
  v2 = this->m_DebugLines[0];
  for ( i = 5; i != 0; --i )
  {
    memset(dst: (int)v2, value: nullptr, count: 0x3E800u);
    *m_DebugLineEnd++ = v2;
    v2 += 256000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110F00
// Name: public: virtual int CDebugHistory::Save(class ISave __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDebugHistory::Save(CDebugHistory *this, ISave *save)
{
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  void (__thiscall *v5)(ISave *, const int *, int); // edx
  int v6; // edi
  ISave_vtbl *v7; // eax
  int iEnd; // [esp+Ch] [ebp-Ch] BYREF
  int iMaxCategorys; // [esp+10h] [ebp-8h] BYREF
  int iVersion; // [esp+14h] [ebp-4h] BYREF
  char **savea; // [esp+20h] [ebp+8h]

  WriteInt_2 = save->WriteInt_2;
  iVersion = 6;
  WriteInt_2(this: save, a2: &iVersion, a3: 1);
  v5 = save->WriteInt_2;
  iMaxCategorys = 5;
  v5(this: save, a2: &iMaxCategorys, a3: 1);
  v6 = 0;
  savea = this->m_DebugLineEnd;
  do
  {
    v7 = save->__vftable;
    iEnd = &(*savea)[-(v6 * 256000)] - (char *)this - 852;
    v7->WriteInt_2(this: save, a2: &iEnd, a3: 1);
    save->WriteData_2(this: save, a2: this->m_DebugLines[v6], a3: 256000);
    ++savea;
    ++v6;
  }
  while ( v6 < 5 );
  return CBaseEntity::Save(this, save);
}

//------------------------------------------------------------------------------
// Address: 0x10110FA0
// Name: public: virtual int CDebugHistory::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDebugHistory::Restore(CDebugHistory *this, IRestore *restore)
{
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  int v7; // ebx
  int iMaxCategorys; // [esp+Ch] [ebp-8h]
  int iMaxCategorysa; // [esp+Ch] [ebp-8h]
  char **i; // [esp+10h] [ebp-4h]
  char **m_DebugLineEnd; // [esp+10h] [ebp-4h]
  int iCategory; // [esp+1Ch] [ebp+8h]
  int iCategorya; // [esp+1Ch] [ebp+8h]

  CDebugHistory::ClearHistories(this);
  v4 = restore->ReadInt(this: restore);
  iMaxCategorys = v4;
  if ( v4 < 5 )
  {
    v7 = 0;
    iCategorya = 0;
    m_DebugLineEnd = this->m_DebugLineEnd;
    while ( iCategorya < v4 )
    {
      *m_DebugLineEnd = &this->m_DebugLines[v7][restore->ReadInt(this: restore)];
      restore->ReadData(this: restore, a2: this->m_DebugLines[v7], a3: 256000, a4: 0);
      ++iCategorya;
      ++m_DebugLineEnd;
      v4 = iMaxCategorys;
      ++v7;
    }
  }
  else
  {
    v5 = restore->ReadInt(this: restore);
    v6 = 0;
    iMaxCategorysa = v5;
    iCategory = 0;
    for ( i = this->m_DebugLineEnd; ; ++i )
    {
      if ( v5 >= 5 )
        v5 = 5;
      if ( iCategory >= v5 )
        break;
      *i = &this->m_DebugLines[v6][restore->ReadInt(this: restore)];
      restore->ReadData(this: restore, a2: this->m_DebugLines[v6], a3: 256000, a4: 0);
      ++iCategory;
      v5 = iMaxCategorysa;
      ++v6;
    }
  }
  return CBaseEntity::Restore(this, a2: (bool (__cdecl *)(const char *))this, restore);
}

//------------------------------------------------------------------------------
// Address: 0x101110A0
// Name: public: virtual void CDebugHistory::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugHistory::Spawn(CDebugHistory *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  UTIL_Remove(oldObj: this);
  CDebugHistory::ClearHistories(this);
}

//------------------------------------------------------------------------------
// Address: 0x101110C0
// Name: void CC_DebugHistory_AddLine(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_DebugHistory_AddLine(const CCommand *args)
{
  const char *v1; // eax

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    if ( args->m_nArgc >= 3 )
    {
      v1 = locale;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      atoi(nptr: v1);
    }
    else
    {
      _Warning(a1: "Incorrect parameters. Format: <category id> <line>\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111160
// Name: void ClearDebugHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearDebugHistory()
{
  s_DebugHistory.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10111170
// Name: void CC_DebugHistory_Dump(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_DebugHistory_Dump(const CCommand *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() && args->m_nArgc < 2 )
    _Warning(a1: "Incorrect parameters. Format: <category id>\n");
}

//------------------------------------------------------------------------------
// Address: 0x104025C0
// Name: CDebugHistory_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CDebugHistory_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CDebugHistory>(__formal: nullptr);
  CDebugHistory_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101111A0
// Name: struct datamap_t __near * DataMapInit<class CDebugHistory>(class CDebugHistory __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CDebugHistory>()
{
  if ( (_S2_80 & 1) == 0 )
  {
    _S2_80 |= 1u;
    nameHolder_158.m_pszBase = "CDebugHistory";
    nameHolder_158.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_158.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_158.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_158.m_Names.m_Size = 0;
    nameHolder_158.m_Names.m_pElements = nullptr;
    nameHolder_158.m_nLenBase = 13;
    atexit(func: DataMapInit_CDebugHistory__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CDebugHistory::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CDebugHistory::m_DataMap.dataNumFields = 1;
  CDebugHistory::m_DataMap.dataDesc = dataDesc_475;
  return &CDebugHistory::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x104025D0
// Name: _dynamic_initializer_for__env_debughistory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_debughistory__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CDebugHistory> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_debughistory,
           a3: "env_debughistory");
}

//------------------------------------------------------------------------------
// Address: 0x104025F0
// Name: _dynamic_initializer_for__dbghist_addline__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dbghist_addline__()
{
  ConCommand::ConCommand(
    this: &dbghist_addline,
    pName: "dbghist_addline",
    callback: (void (__cdecl *)())CC_DebugHistory_AddLine,
    pHelpString: "Add a line to the debug history. Format: <category id> <line>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__dbghist_addline__);
}

//------------------------------------------------------------------------------
// Address: 0x10402620
// Name: _dynamic_initializer_for__dbghist_dump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dbghist_dump__()
{
  ConCommand::ConCommand(
    this: &dbghist_dump,
    pName: "dbghist_dump",
    callback: (void (__cdecl *)())CC_DebugHistory_Dump,
    pHelpString: "Dump the debug history to the console. Format: <category id>\n"
    "    Categories:\n"
    "     0: Entity I/O\n"
    "     1: AI Decisions\n"
    "     2: Scene Print\n"
    "     3: Alyx Blind\n"
    "     4: Log of damage done to player",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__dbghist_dump__);
}

//------------------------------------------------------------------------------
// Address: 0x10402650
// Name: _dynamic_initializer_for__g_CEnvDetailController_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEnvDetailController_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEnvDetailController_ClassReg,
           pNetworkName: "CEnvDetailController",
           pTable: &DT_DetailController::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10402670
// Name: _dynamic_initializer_for__env_detail_controller__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_detail_controller__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvDetailController> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_detail_controller,
           a3: "env_detail_controller");
}
