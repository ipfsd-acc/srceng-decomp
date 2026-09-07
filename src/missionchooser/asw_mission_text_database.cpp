// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/asw_mission_text_database.cpp
// Functions: 6
// ============================================================

#include "missionchooser\asw_mission_text_database.h"

//------------------------------------------------------------------------------
// Address: 0x10007170
// Name: public: void CASW_MissionTextSpec::Init(char const __near *,char const __near *,char const __near *,char const __near *,unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_MissionTextSpec::Init(
        CASW_MissionTextSpec *this,
        const char *pszShortDescription,
        const char *pszSLongDescription,
        const char *pszObjectiveEntityName,
        const char *pszMissionFilename,
        unsigned __int16 *nId)
{
  CUtlSymbol *v7; // eax
  const char *v8; // edi
  unsigned __int16 m_Id; // ax
  unsigned __int16 *v10; // ecx
  char out[256]; // [esp+8h] [ebp-100h] BYREF

  CUtlString::Set(this: &this->m_sShortDesc, pValue: pszShortDescription);
  CUtlString::Set(this: &this->m_sLongDesc, pValue: pszSLongDescription);
  v7 = CUtlSymbolTable::AddString(
         this: &CASW_MissionTextDB::s_SymTab,
         result: (CUtlSymbol *)&pszShortDescription + 1,
         pString: pszObjectiveEntityName);
  v8 = pszMissionFilename;
  this->m_nObjectiveEntityName = (CUtlSymbol)v7->m_Id;
  if ( v8 != nullptr && *v8 != 0 )
  {
    V_FileBase(in: v8, out, maxlen: 255);
    m_Id = CUtlSymbolTable::AddString(
             this: &CASW_MissionTextDB::s_SymTab,
             result: (CUtlSymbol *)&pszShortDescription + 1,
             pString: v8)->m_Id;
  }
  else
  {
    m_Id = -1;
  }
  v10 = nId;
  this->m_nMissionFilename.m_Id = m_Id;
  this->m_nId = *v10;
}

//------------------------------------------------------------------------------
// Address: 0x100072A0
// Name: public: virtual char const __near * CASW_MissionTextDB::GetShortDescriptionByID(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CASW_MissionTextDB::GetShortDescriptionByID(CASW_MissionTextDB *this, unsigned __int16 id)
{
  CASW_MissionTextSpec *v2; // eax

  if ( id < this->m_missionSpecs.m_Size && (v2 = &this->m_missionSpecs.m_Memory.m_pMemory[id]) != nullptr )
    return CUtlString::operator char const *(this: &v2->m_sShortDesc);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100072D0
// Name: public: virtual char const __near * CASW_MissionTextDB::GetLongDescriptionByID(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CASW_MissionTextDB::GetLongDescriptionByID(CASW_MissionTextDB *this, unsigned __int16 id)
{
  CASW_MissionTextSpec *v2; // eax

  if ( id < this->m_missionSpecs.m_Size && (v2 = &this->m_missionSpecs.m_Memory.m_pMemory[id]) != nullptr )
    return CUtlString::operator char const *(this: &v2->m_sLongDesc);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100073E0
// Name: public: class CASW_MissionTextSpec const __near * CASW_MissionTextDB::Find(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CASW_MissionTextDB::Find::__l4::MatchTuple *__thiscall CASW_MissionTextDB::Find(
        CASW_MissionTextDB *this,
        const char *pObjectiveEntityName,
        const char *pMissionFilename)
{
  const char *v3; // edi
  CASW_MissionTextDB::Find::__l4::MatchTuple *result; // eax
  int v6; // edx
  const char *v7; // esi
  int m_Size; // ecx
  int v9; // ebx
  int v10; // edi
  CASW_MissionTextSpec *pSpec; // esi
  unsigned __int16 m_Id; // ax
  bool v13; // dl
  int v14; // eax
  char out[256]; // [esp+8h] [ebp-124h] BYREF
  vgui::PropertySheet::Page_t src; // [esp+108h] [ebp-24h] BYREF
  CASW_MissionTextDB *v17; // [esp+110h] [ebp-1Ch]
  int N; // [esp+114h] [ebp-18h]
  CUtlVector<`CASW_MissionTextDB::Find'::`4'::MatchTuple,CUtlMemory<`CASW_MissionTextDB::Find'::`4'::MatchTuple,int> > matches; // [esp+118h] [ebp-14h] BYREF

  v3 = pObjectiveEntityName;
  result = nullptr;
  v17 = this;
  if ( pObjectiveEntityName == nullptr )
    return result;
  v6 = this->m_missionSpecs.m_Size >> 2;
  matches.m_Memory.m_pMemory = nullptr;
  matches.m_Memory.m_nAllocationCount = v6;
  matches.m_Memory.m_nGrowSize = v6;
  if ( v6 != 0 )
  {
    result = (CASW_MissionTextDB::Find::__l4::MatchTuple *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * v6);
    matches.m_Memory.m_pMemory = result;
  }
  matches.m_Size = 0;
  matches.m_pElements = result;
  CUtlSymbolTable::Find(this: &CASW_MissionTextDB::s_SymTab, result: (CUtlSymbol *)&pObjectiveEntityName, pString: v3);
  v7 = pMissionFilename;
  if ( pMissionFilename != nullptr && *pMissionFilename != 0 )
  {
    V_FileBase(in: pMissionFilename, out, maxlen: 255);
    LOWORD(pMissionFilename) = (CUtlSymbol)CUtlSymbolTable::Find(
                                             this: &CASW_MissionTextDB::s_SymTab,
                                             result: (CUtlSymbol *)&pMissionFilename + 1,
                                             pString: v7)->m_Id;
  }
  else
  {
    LOWORD(pMissionFilename) = -1;
  }
  if ( (_WORD)pObjectiveEntityName == 0xFFFF )
  {
    _Warning(a1: "No mission text specifier mentions an entity named %s\n", v3);
LABEL_10:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&matches);
    return nullptr;
  }
  m_Size = this->m_missionSpecs.m_Size;
  v9 = 0;
  N = m_Size;
  if ( m_Size <= 0 )
    goto LABEL_10;
  v10 = 0;
  do
  {
    pSpec = &v17->m_missionSpecs.m_Memory.m_pMemory[v10];
    if ( pSpec->m_nObjectiveEntityName.m_Id != (_WORD)pObjectiveEntityName )
      goto LABEL_18;
    m_Id = pSpec->m_nMissionFilename.m_Id;
    if ( m_Id == 0xFFFF )
    {
      v14 = 1;
    }
    else
    {
      v13 = m_Id != (unsigned __int16)pMissionFilename;
      v14 = m_Id != (unsigned __int16)pMissionFilename ? 0 : 2;
      if ( (v13 ? 0 : 2) == 0 )
        goto LABEL_18;
      if ( v14 == 2 )
        goto LABEL_21;
    }
    *(_DWORD *)&src.contextMenu = v14;
    src.page = (vgui::Panel *)pSpec;
    CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
      this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&matches,
      elem: matches.m_Size,
      &src);
    m_Size = N;
LABEL_18:
    ++v9;
    ++v10;
  }
  while ( v9 < m_Size );
  if ( matches.m_Size == 0 )
    goto LABEL_10;
  pSpec = (CASW_MissionTextSpec *)matches.m_Memory.m_pMemory->pSpec;
LABEL_21:
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&matches);
  return (CASW_MissionTextDB::Find::__l4::MatchTuple *)pSpec;
}

//------------------------------------------------------------------------------
// Address: 0x10007540
// Name: public: virtual unsigned short CASW_MissionTextDB::FindMissionTextID(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_MissionTextDB::FindMissionTextID(
        CASW_MissionTextDB *this,
        const char *pEntityName,
        const char *pMissionName)
{
  CASW_MissionTextDB::Find::__l4::MatchTuple *v3; // eax

  v3 = CASW_MissionTextDB::Find(this, pObjectiveEntityName: pEntityName, pMissionFilename: pMissionName);
  if ( v3 != nullptr )
    return LOWORD(v3[4].score);
  else
    return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100075F0
// Name: public: void CASW_MissionTextDB::LoadKeyValuesFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_MissionTextDB::LoadKeyValuesFile(CASW_MissionTextDB *this, const char *pFilename)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  IBaseFileSystem *v4; // eax
  const char *v5; // esi
  bool v6; // zf
  KeyValues *NextKey; // edi
  const char *Name; // eax
  KeyValues *Key; // eax
  KeyValues *v10; // eax
  const char *v11; // esi
  KeyValues *v12; // eax
  const char *v13; // ebx
  const char *String; // eax
  KeyValues *v15; // eax
  CASW_MissionTextDB *v16; // esi
  int v17; // eax
  const char *v18; // [esp-4h] [ebp-2Ch]
  const char *v19; // [esp-4h] [ebp-2Ch]
  const char *v20; // [esp-4h] [ebp-2Ch]
  const char *pShortDesc; // [esp+Ch] [ebp-1Ch]
  const char *pEntName; // [esp+10h] [ebp-18h]
  unsigned __int16 nId[2]; // [esp+14h] [ebp-14h] BYREF
  CASW_MissionTextDB *v24; // [esp+18h] [ebp-10h]
  const char *pMissionFilename; // [esp+1Ch] [ebp-Ch]
  int numAdded; // [esp+20h] [ebp-8h]
  KeyValues *pKeyValuesSource; // [esp+24h] [ebp-4h]

  v24 = this;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: pFilename);
    pKeyValuesSource = v3;
  }
  else
  {
    pKeyValuesSource = nullptr;
    v3 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  v5 = pFilename;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: pFilename,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    numAdded = 0;
    NextKey = v3;
    if ( v3 != nullptr )
    {
      do
      {
        Name = KeyValues::GetName(this: NextKey);
        if ( _V_stricmp(s1: Name, s2: "objectivetext") != 0 )
        {
          v20 = KeyValues::GetName(this: NextKey);
          _Warning(a1: "Keyvalues file contained unknown key type %s\n", v20);
        }
        else
        {
          Key = KeyValues::FindKey(this: NextKey, keyName: "entityname", bCreate: false);
          if ( Key != nullptr
            && (pEntName = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: szDescription)) != nullptr )
          {
            v10 = KeyValues::FindKey(this: NextKey, keyName: "shortdesc", bCreate: false);
            if ( v10 != nullptr
              && (v11 = KeyValues::GetString(this: v10, keyName: nullptr, defaultValue: szDescription),
                  pShortDesc = v11,
                  v11 != nullptr) )
            {
              v12 = KeyValues::FindKey(this: NextKey, keyName: "longdesc", bCreate: false);
              if ( v12 == nullptr
                || (v13 = KeyValues::GetString(this: v12, keyName: nullptr, defaultValue: szDescription)) == nullptr )
              {
                String = KeyValues::GetString(this: NextKey, keyName: nullptr, defaultValue: szDescription);
                _Warning(a1: "A mission text block did not specify a long description!\n%s\n", String);
                v13 = v11;
              }
              v15 = KeyValues::FindKey(this: NextKey, keyName: "missionfile", bCreate: false);
              if ( v15 != nullptr )
                pMissionFilename = KeyValues::GetString(this: v15, keyName: nullptr, defaultValue: szDescription);
              else
                pMissionFilename = nullptr;
              v16 = v24;
              v17 = CUtlVector<CASW_MissionTextSpec,CUtlMemory<CASW_MissionTextSpec,int>>::InsertBefore(
                      this: &v24->m_missionSpecs,
                      elem: v24->m_missionSpecs.m_Size);
              *(_DWORD *)nId = (unsigned __int16)v17;
              CASW_MissionTextSpec::Init(
                this: &v16->m_missionSpecs.m_Memory.m_pMemory[v17],
                pszShortDescription: pShortDesc,
                pszSLongDescription: v13,
                pszObjectiveEntityName: pEntName,
                pszMissionFilename: pMissionFilename,
                nId);
              ++numAdded;
              v3 = pKeyValuesSource;
            }
            else
            {
              v19 = KeyValues::GetString(this: NextKey, keyName: nullptr, defaultValue: szDescription);
              _Warning(a1: "A mission text block did not specify a short description!\n%s\n", v19);
            }
          }
          else
          {
            v18 = KeyValues::GetString(this: NextKey, keyName: nullptr, defaultValue: szDescription);
            _Warning(a1: "A mission text block did not specify an entityname!\n%s\n", v18);
          }
        }
        NextKey = KeyValues::GetNextKey(this: NextKey);
      }
      while ( NextKey != nullptr );
      v5 = pFilename;
    }
    _Msg(a1: "%d mission descriptions loaded from %s\n", numAdded, v5);
    v6 = v3 == nullptr;
  }
  else
  {
    _Warning(a1: "Could not open key values file %s\n", pFilename);
    v6 = v3 == nullptr;
  }
  if ( !v6 )
    KeyValues::deleteThis(this: v3);
}
