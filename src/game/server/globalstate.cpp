// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/globalstate.cpp
// Functions: 27
// ============================================================

#include "game\server\globalstate.h"

//------------------------------------------------------------------------------
// Address: 0x10158D80
// Name: void GlobalEntity_EnableStateUpdates(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GlobalEntity_EnableStateUpdates(bool bEnable)
{
  gGlobalState.m_disableStateUpdates = !bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10158DA0
// Name: server_game_time
// Source: json
//------------------------------------------------------------------------------
void __cdecl server_game_time()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    _Msg(a1: "Server game time: %f\n", gpGlobals->curtime);
}

//------------------------------------------------------------------------------
// Address: 0x10158DD0
// Name: int GlobalEntity_GetNumGlobals(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GlobalEntity_GetNumGlobals()
{
  return gGlobalState.m_list.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10158DE0
// Name: public: virtual void CUtlSymbolDataOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolDataOps::Save(CUtlSymbolDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo, ISave *pSave)
{
  const char *v3; // eax

  v3 = CUtlSymbolTable::String(this: this->m_symbolTable, id: *(CUtlSymbol *)fieldInfo->pField);
  pSave->WriteString_4(this: pSave, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10158E10
// Name: public: virtual void CUtlSymbolDataOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolDataOps::Restore(
        CUtlSymbolDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlSymbol *pField; // edi
  char tmp[1024]; // [esp+8h] [ebp-400h] BYREF

  pField = (CUtlSymbol *)fieldInfo->pField;
  pRestore->ReadString_2(this: pRestore, a2: tmp, a3: 1024, a4: 0);
  pField->m_Id = CUtlSymbolTable::AddString(
                   this: this->m_symbolTable,
                   result: (CUtlSymbol *)&fieldInfo + 1,
                   pString: tmp)->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10158E60
// Name: public: virtual void CUtlSymbolDataOps::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolDataOps::MakeEmpty(CUtlSymbolDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  *(_WORD *)fieldInfo->pField = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10158E80
// Name: public: virtual bool CUtlSymbolDataOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlSymbolDataOps::IsEmpty(CUtlSymbolDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  return *(_WORD *)fieldInfo->pField == 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10158EA0
// Name: void GlobalEntity_SetState(int,enum GLOBALESTATE)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GlobalEntity_SetState(int globalIndex, GLOBALESTATE state)
{
  if ( !gGlobalState.m_disableStateUpdates && globalIndex >= 0 && globalIndex < gGlobalState.m_list.m_Size )
    gGlobalState.m_list.m_Memory.m_pMemory[globalIndex].state = state;
}

//------------------------------------------------------------------------------
// Address: 0x10158ED0
// Name: void GlobalEntity_SetCounter(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GlobalEntity_SetCounter(int globalIndex, int counter)
{
  if ( !gGlobalState.m_disableStateUpdates && globalIndex >= 0 && globalIndex < gGlobalState.m_list.m_Size )
    gGlobalState.m_list.m_Memory.m_pMemory[globalIndex].counter = counter;
}

//------------------------------------------------------------------------------
// Address: 0x10158F00
// Name: int GlobalEntity_AddToCounter(int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GlobalEntity_AddToCounter(int globalIndex, int delta)
{
  globalentity_t *m_pMemory; // ecx

  if ( gGlobalState.m_disableStateUpdates || globalIndex < 0 || globalIndex >= gGlobalState.m_list.m_Size )
    return 0;
  m_pMemory = gGlobalState.m_list.m_Memory.m_pMemory;
  gGlobalState.m_list.m_Memory.m_pMemory[globalIndex].counter += delta;
  return m_pMemory[globalIndex].counter;
}

//------------------------------------------------------------------------------
// Address: 0x10158F40
// Name: void GlobalEntity_SetMap(int,struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GlobalEntity_SetMap(int globalIndex, string_t mapname)
{
  const char *pszValue; // ecx
  globalentity_t *v3; // esi

  if ( globalIndex >= 0 && globalIndex < gGlobalState.m_list.m_Size )
  {
    pszValue = mapname.pszValue;
    if ( mapname.pszValue == nullptr )
      pszValue = locale;
    v3 = &gGlobalState.m_list.m_Memory.m_pMemory[globalIndex];
    v3->levelName = (CUtlSymbol)CUtlSymbolTable::AddString(
                                  this: &gGlobalState.m_nameList,
                                  result: (CUtlSymbol *)&globalIndex + 1,
                                  pString: pszValue)->m_Id;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158F90
// Name: int GlobalEntity_GetIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GlobalEntity_GetIndex(const char *pGlobalname)
{
  int result; // eax
  globalentity_t *i; // ecx
  CUtlSymbol v3; // [esp+0h] [ebp-4h] BYREF

  CUtlSymbolTable::Find(this: &gGlobalState.m_nameList, result: &v3, pString: pGlobalname);
  if ( v3.m_Id == 0xFFFF )
    return -1;
  result = gGlobalState.m_list.m_Size - 1;
  if ( gGlobalState.m_list.m_Size - 1 < 0 )
    return -1;
  for ( i = &gGlobalState.m_list.m_Memory.m_pMemory[result]; i->name.m_Id != v3.m_Id; --i )
  {
    if ( --result < 0 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10158FF0
// Name: enum GLOBALESTATE GlobalEntity_GetState(int)
// Source: json
//------------------------------------------------------------------------------
GLOBALESTATE __cdecl GlobalEntity_GetState(int globalIndex)
{
  if ( globalIndex >= 0 && globalIndex < gGlobalState.m_list.m_Size )
    return gGlobalState.m_list.m_Memory.m_pMemory[globalIndex].state;
  else
    return GLOBAL_OFF;
}

//------------------------------------------------------------------------------
// Address: 0x10159020
// Name: int GlobalEntity_GetCounter(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GlobalEntity_GetCounter(int globalIndex)
{
  if ( globalIndex >= 0 && globalIndex < gGlobalState.m_list.m_Size )
    return gGlobalState.m_list.m_Memory.m_pMemory[globalIndex].counter;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10159050
// Name: char const __near * GlobalEntity_GetMap(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GlobalEntity_GetMap(int globalIndex)
{
  if ( globalIndex >= 0 && globalIndex < gGlobalState.m_list.m_Size )
    return CUtlSymbolTable::String(
             this: &gGlobalState.m_nameList,
             id: gGlobalState.m_list.m_Memory.m_pMemory[globalIndex].levelName);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10159090
// Name: char const __near * GlobalEntity_GetName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GlobalEntity_GetName(int globalIndex)
{
  if ( globalIndex >= 0 && globalIndex < gGlobalState.m_list.m_Size )
    return CUtlSymbolTable::String(
             this: &gGlobalState.m_nameList,
             id: gGlobalState.m_list.m_Memory.m_pMemory[globalIndex].name);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101590D0
// Name: public: void CGlobalState::DumpGlobals(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalState::DumpGlobals(CGlobalState *this)
{
  int v2; // edi
  globalentity_t *m_pMemory; // eax
  const char *v4; // eax
  const char *v5; // [esp-Ch] [ebp-1Ch]
  const char *v6; // [esp-8h] [ebp-18h]
  int counter; // [esp-4h] [ebp-14h]
  int i; // [esp+Ch] [ebp-4h]

  _Msg(a1: "-- Globals --\n");
  v2 = 0;
  for ( i = 0; i < this->m_list.m_Size; ++i )
  {
    m_pMemory = this->m_list.m_Memory.m_pMemory;
    counter = m_pMemory[v2].counter;
    v6 = *((const char **)&estates.m_Id + m_pMemory[v2].state);
    v5 = CUtlSymbolTable::String(this: &this->m_nameList, id: m_pMemory[v2].levelName);
    v4 = CUtlSymbolTable::String(this: &this->m_nameList, id: this->m_list.m_Memory.m_pMemory[v2].name);
    _Msg(a1: "%s: %s (%s) = %d\n", v4, v5, v6, counter);
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101592C0
// Name: dump_globals
// Source: json
//------------------------------------------------------------------------------
void __cdecl dump_globals()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CGlobalState::DumpGlobals(this: &gGlobalState);
}

//------------------------------------------------------------------------------
// Address: 0x10159360
// Name: void ResetGlobalState(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResetGlobalState()
{
  globalentity_t *m_pMemory; // eax

  m_pMemory = gGlobalState.m_list.m_Memory.m_pMemory;
  gGlobalState.m_list.m_Size = 0;
  if ( gGlobalState.m_list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( gGlobalState.m_list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: gGlobalState.m_list.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      gGlobalState.m_list.m_Memory.m_pMemory = nullptr;
    }
    gGlobalState.m_list.m_Memory.m_nAllocationCount = 0;
  }
  gGlobalState.m_list.m_pElements = m_pMemory;
  CUtlSymbolTable::RemoveAll(this: &gGlobalState.m_nameList);
}

//------------------------------------------------------------------------------
// Address: 0x101593B0
// Name: public: virtual void CGlobalState::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalState::LevelShutdownPreEntity(CGlobalState *this)
{
  this->m_disableStateUpdates = true;
}

//------------------------------------------------------------------------------
// Address: 0x101593C0
// Name: public: virtual void CGlobalState::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalState::LevelShutdownPostEntity(CGlobalState *this)
{
  this->m_disableStateUpdates = false;
}

//------------------------------------------------------------------------------
// Address: 0x101593D0
// Name: public: int CGlobalState::AddEntity(char const __near *,char const __near *,enum GLOBALESTATE)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGlobalState::AddEntity(
        CGlobalState *this,
        const char *pGlobalname,
        const char *pMapName,
        GLOBALESTATE state)
{
  const char *v5; // eax
  int result; // eax
  globalentity_t *i; // ecx
  globalentity_t entity; // [esp+Ch] [ebp-Ch] BYREF

  entity.name = (CUtlSymbol)CUtlSymbolTable::AddString(
                              this: &this->m_nameList,
                              result: (CUtlSymbol *)&pGlobalname + 1,
                              pString: pGlobalname)->m_Id;
  entity.levelName = (CUtlSymbol)CUtlSymbolTable::AddString(
                                   this: &this->m_nameList,
                                   result: (CUtlSymbol *)&pGlobalname + 1,
                                   pString: pMapName)->m_Id;
  entity.state = state;
  v5 = CUtlSymbolTable::String(this: &this->m_nameList, id: entity.name);
  CUtlSymbolTable::Find(this: &this->m_nameList, result: (CUtlSymbol *)&pGlobalname, pString: v5);
  if ( (_WORD)pGlobalname == 0xFFFF )
    return CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>::InsertBefore(
             this: &this->m_list,
             elem: this->m_list.m_Size,
             src: &entity);
  result = this->m_list.m_Size - 1;
  if ( result < 0 )
    return CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>::InsertBefore(
             this: &this->m_list,
             elem: this->m_list.m_Size,
             src: &entity);
  for ( i = &this->m_list.m_Memory.m_pMemory[result]; i->name.m_Id != (_WORD)pGlobalname; --i )
  {
    if ( --result < 0 )
      return CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>::InsertBefore(
               this: &this->m_list,
               elem: this->m_list.m_Size,
               src: &entity);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101594A0
// Name: public: int CGlobalState::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGlobalState::Restore(CGlobalState *this, IRestore *restore)
{
  bool v3; // sf

  v3 = this->m_list.m_Memory.m_nGrowSize < 0;
  this->m_list.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_list.m_Memory.m_pMemory);
      this->m_list.m_Memory.m_pMemory = nullptr;
    }
    this->m_list.m_Memory.m_nAllocationCount = 0;
  }
  this->m_list.m_pElements = this->m_list.m_Memory.m_pMemory;
  CUtlSymbolTable::RemoveAll(this: &this->m_nameList);
  return restore->ReadFields(
           this: restore,
           a2: "GLOBAL",
           a3: this,
           a4: nullptr,
           a5: CGlobalState::m_DataMap.dataDesc,
           a6: CGlobalState::m_DataMap.dataNumFields) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10159510
// Name: void SaveGlobalState(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveGlobalState(CSaveRestoreData *pSaveData)
{
  CSave saveHelper; // [esp+0h] [ebp-28h] BYREF

  CSave::CSave(this: &saveHelper, pdata: pSaveData);
  saveHelper.WriteFields(
    this: &saveHelper,
    a2: "GLOBAL",
    a3: &gGlobalState,
    a4: nullptr,
    a5: CGlobalState::m_DataMap.dataDesc,
    a6: CGlobalState::m_DataMap.dataNumFields);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&saveHelper.m_BlockStartStack);
}

//------------------------------------------------------------------------------
// Address: 0x10159560
// Name: void RestoreGlobalState(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RestoreGlobalState(CSaveRestoreData *pSaveData)
{
  CRestore restoreHelper; // [esp+0h] [ebp-28h] BYREF

  CRestore::CRestore(this: &restoreHelper, pdata: pSaveData);
  CGlobalState::Restore(this: &gGlobalState, restore: &restoreHelper);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&restoreHelper.m_BlockEndStack);
}

//------------------------------------------------------------------------------
// Address: 0x104050E0
// Name: CGlobalState_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGlobalState_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGlobalState>();
  CGlobalState_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104050F0
// Name: globalentity_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *globalentity_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<globalentity_t>();
  globalentity_t_DataDescInit::g_DataMapHolder = result;
  return result;
}
