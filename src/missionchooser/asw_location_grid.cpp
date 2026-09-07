// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/asw_location_grid.cpp
// Functions: 44
// ============================================================

#include "missionchooser\asw_location_grid.h"

//------------------------------------------------------------------------------
// Address: 0x10001510
// Name: public: virtual int CASW_Reward::GetRewardAmount(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CASW_Reward::GetRewardAmount(CASW_Location_Group *this)
{
  return this->m_szTitleText;
}

//------------------------------------------------------------------------------
// Address: 0x10001520
// Name: public: virtual bool CASW_Reward::LoadFromKeyValues(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CASW_Reward::LoadFromKeyValues(CASW_Reward *this, KeyValues *pKeys, int iMissionDifficulty)
{
  const char *Name; // eax
  const char *v6; // eax
  int v7; // edi
  KeyValues *Key; // eax
  int Int; // eax
  const char *v10; // eax
  const char *String; // eax

  Name = KeyValues::GetName(this: pKeys);
  if ( _V_stricmp(s1: Name, s2: "MoneyReward") != 0 )
  {
    v6 = KeyValues::GetName(this: pKeys);
    if ( _V_stricmp(s1: v6, s2: "XPReward") != 0 )
    {
      v10 = KeyValues::GetName(this: pKeys);
      if ( _V_stricmp(s1: v10, s2: "ItemReward") == 0 )
      {
        this->m_RewardType = ASW_REWARD_ITEM;
        this->m_iRewardAmount = 0;
        String = KeyValues::GetString(this: pKeys, keyName: "ItemName", defaultValue: szDescription);
        this->m_szRewardName = TileGenCopyString(szString: String);
        this->m_iRewardLevel = KeyValues::GetInt(this: pKeys, keyName: "ItemLevel", defaultValue: 0);
        this->m_iRewardQuality = KeyValues::GetInt(this: pKeys, keyName: "ItemQuality", defaultValue: 0);
      }
      return 0;
    }
    else
    {
      v7 = 400 * iMissionDifficulty;
      this->m_RewardType = ASW_REWARD_XP;
      Key = KeyValues::FindKey(this: pKeys, keySymbol: 0);
      if ( Key != nullptr )
        Int = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: v7);
      else
        Int = 400 * iMissionDifficulty;
      this->m_iRewardAmount = Int;
      if ( Int == 0 )
        this->m_iRewardAmount = v7;
      return 1;
    }
  }
  else
  {
    this->m_RewardType = ASW_REWARD_MONEY;
    this->m_iRewardAmount = KeyValues::GetInt(this: pKeys, keyName: nullptr, defaultValue: 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001620
// Name: public: virtual class KeyValues __near * CASW_Reward::GetKeyValuesForEditor(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CASW_Reward::GetKeyValuesForEditor(CASW_Reward *this)
{
  ASW_Reward_Type m_RewardType; // eax
  __int32 v3; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // esi

  m_RewardType = this->m_RewardType;
  if ( m_RewardType == ASW_REWARD_MONEY )
  {
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
    {
      v10 = KeyValues::KeyValues(this: v9, setName: "MoneyReward");
      KeyValues::SetInt(this: v10, keyName: nullptr, value: this->m_iRewardAmount);
      return v10;
    }
    goto LABEL_14;
  }
  v3 = m_RewardType - 1;
  if ( v3 == 0 )
  {
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(this: v7, setName: "XPReward");
      KeyValues::SetInt(this: v8, keyName: nullptr, value: this->m_iRewardAmount);
      return v8;
    }
LABEL_14:
    KeyValues::SetInt(this: nullptr, keyName: nullptr, value: this->m_iRewardAmount);
    return nullptr;
  }
  if ( v3 != 1 )
    return nullptr;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ItemReward");
  else
    v6 = nullptr;
  KeyValues::SetString(this: v6, keyName: "ItemName", value: this->m_szRewardName);
  KeyValues::SetInt(this: v6, keyName: "ItemLevel", value: this->m_iRewardLevel);
  KeyValues::SetInt(this: v6, keyName: "ItemQuality", value: this->m_iRewardQuality);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10001720
// Name: public: virtual class KeyValues __near * CASW_Location::GetMissionSettings(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CASW_Location::GetMissionSettings(CASW_Location *this)
{
  KeyValues *m_pMissionKV; // ecx

  m_pMissionKV = this->m_pMissionKV;
  if ( m_pMissionKV != nullptr )
    return KeyValues::FindKey(this: m_pMissionKV, keyName: "mission_settings", bCreate: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001740
// Name: public: virtual class KeyValues __near * CASW_Location::GetMissionDefinition(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CASW_Location::GetMissionDefinition(CASW_Location *this)
{
  return this->m_pMissionKV;
}

//------------------------------------------------------------------------------
// Address: 0x10001750
// Name: public: virtual char const __near * CASW_Location::GetCompanyName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CASW_Location::GetCompanyName(CASW_Location *this)
{
  const char *result; // eax

  switch ( this->m_iCompanyIndex )
  {
    case 1:
      result = "#asw_company_name_deuce";
      break;
    case 2:
      result = "#asw_company_name_iaf";
      break;
    case 3:
      result = "#asw_company_name_totem";
      break;
    case 4:
      result = "#asw_company_name_oldeearth";
      break;
    case 5:
      result = "#asw_company_name_magnus";
      break;
    case 6:
      result = "#asw_company_name_civilised";
      break;
    default:
      result = "#asw_company_name_none";
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100017B0
// Name: public: virtual char const __near * CASW_Location::GetCompanyImage(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CASW_Location::GetCompanyImage(CASW_Location *this)
{
  const char *result; // eax

  switch ( this->m_iCompanyIndex )
  {
    case 1:
      result = "briefing/companylogo/deuce";
      break;
    case 2:
      result = "briefing/companylogo/iaf";
      break;
    case 3:
      result = "briefing/companylogo/totem";
      break;
    case 4:
      result = "briefing/companylogo/oldeearth";
      break;
    case 5:
      result = "briefing/companylogo/magnus";
      break;
    case 6:
      result = "briefing/companylogo/civilised";
      break;
    default:
      result = "briefing/companylogo/none";
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001810
// Name: public: virtual bool CASW_Location::IsLocationLocked(class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CASW_Location::IsLocationLocked(
        CASW_Location *this,
        CUtlVector<int,CUtlMemory<int,int> > *completedMissions)
{
  IASW_Location_Group *v4; // eax

  if ( this->GetGroup(this) == nullptr )
    return false;
  v4 = this->GetGroup(this);
  return v4->IsGroupLocked(this: v4, a2: completedMissions);
}

//------------------------------------------------------------------------------
// Address: 0x10001840
// Name: public: virtual int CASW_Location::GetNumRewards(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Location::GetNumRewards(CASW_Location *this)
{
  return this->m_Rewards.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10001850
// Name: public: virtual class IASW_Location_Group __near * CASW_Location_Grid::GetGroup(int)
// Source: json
//------------------------------------------------------------------------------
CASW_Location_Group *__thiscall CASW_Location_Grid::GetGroup(CASW_Location_Grid *this, int iIndex)
{
  if ( iIndex < 0 || iIndex >= this->m_Groups.m_Size )
    return nullptr;
  else
    return this->m_Groups.m_Memory.m_pMemory[iIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10001870
// Name: public: virtual class CASW_Location_Group __near * CASW_Location_Grid::GetGroupByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CASW_Location_Group *__thiscall CASW_Location_Grid::GetGroupByName(CASW_Location_Grid *this, const char *szName)
{
  int m_Size; // ebx
  int v4; // esi

  m_Size = this->m_Groups.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: this->m_Groups.m_Memory.m_pMemory[v4]->m_szGroupName, s2: szName) != 0 )
  {
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  return this->m_Groups.m_Memory.m_pMemory[v4];
}

//------------------------------------------------------------------------------
// Address: 0x100018C0
// Name: public: virtual class IASW_Location __near * CASW_Location_Grid::GetLocationByID(int)
// Source: json
//------------------------------------------------------------------------------
CASW_Location *__thiscall CASW_Location_Grid::GetLocationByID(CASW_Location_Grid *this, int iLocationID)
{
  int v3; // edi
  CASW_Location_Group *v4; // ecx
  int v5; // esi
  CASW_Location_Group *v6; // ecx

  v3 = 0;
  if ( this->m_Groups.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_Groups.m_Memory.m_pMemory[v3];
    v5 = 0;
    if ( v4->GetNumLocations(this: v4) > 0 )
      break;
LABEL_5:
    if ( ++v3 >= this->m_Groups.m_Size )
      return nullptr;
  }
  while ( 1 )
  {
    v6 = this->m_Groups.m_Memory.m_pMemory[v3];
    if ( v6->m_Locations.m_Memory.m_pMemory[v5]->m_iLocationID == iLocationID )
      return this->m_Groups.m_Memory.m_pMemory[v3]->m_Locations.m_Memory.m_pMemory[v5];
    if ( ++v5 >= v6->GetNumLocations(this: v6) )
      goto LABEL_5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001930
// Name: public: virtual void CASW_Location_Grid::SetLocationComplete(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Location_Grid::SetLocationComplete(CASW_Location_Grid *this, int iLocationID)
{
  int i; // edi
  CASW_Location_Group *v4; // ecx
  int v5; // esi
  CASW_Location *v6; // eax
  CASW_Location_Group *v7; // ecx

  for ( i = 0; i < this->m_Groups.m_Size; ++i )
  {
    v4 = this->m_Groups.m_Memory.m_pMemory[i];
    v5 = 0;
    if ( v4->GetNumLocations(this: v4) > 0 )
    {
      do
      {
        v6 = this->m_Groups.m_Memory.m_pMemory[i]->m_Locations.m_Memory.m_pMemory[v5];
        if ( v6->m_iLocationID == iLocationID )
          v6->m_bCompleted = true;
        v7 = this->m_Groups.m_Memory.m_pMemory[i];
        ++v5;
      }
      while ( v5 < v7->GetNumLocations(this: v7) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001990
// Name: public: int CASW_Location_Grid::GetFreeLocationID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Location_Grid::GetFreeLocationID(CASW_Location_Grid *this)
{
  int v1; // eax
  int v3; // edi
  CASW_Location_Group *v4; // ecx
  int v5; // esi
  CASW_Location_Group *v6; // ecx
  CASW_Location **m_pMemory; // edx
  int iHighestID; // [esp+8h] [ebp-4h]

  v1 = 0;
  v3 = 0;
  iHighestID = 0;
  if ( this->m_Groups.m_Size > 0 )
  {
    do
    {
      v4 = this->m_Groups.m_Memory.m_pMemory[v3];
      v5 = 0;
      if ( v4->GetNumLocations(this: v4) > 0 )
      {
        do
        {
          v6 = this->m_Groups.m_Memory.m_pMemory[v3];
          m_pMemory = v6->m_Locations.m_Memory.m_pMemory;
          if ( m_pMemory[v5]->m_iLocationID > iHighestID )
            iHighestID = m_pMemory[v5]->m_iLocationID;
          ++v5;
        }
        while ( v5 < v6->GetNumLocations(this: v6) );
      }
      ++v3;
    }
    while ( v3 < this->m_Groups.m_Size );
    v1 = iHighestID;
  }
  return v1 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001A00
// Name: public: virtual class IASW_Location __near * CASW_Location_Group::GetLocation(int)
// Source: json
//------------------------------------------------------------------------------
CASW_Location *__thiscall CASW_Location_Group::GetLocation(CASW_Location_Group *this, int iIndex)
{
  if ( iIndex < 0 || iIndex >= this->m_Locations.m_Size )
    return nullptr;
  else
    return this->m_Locations.m_Memory.m_pMemory[iIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10001A30
// Name: public: virtual int CASW_Location_Group::GetHighestUnlockMissionID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Location_Group::GetHighestUnlockMissionID(CASW_Location_Group *this)
{
  int m_Size; // ebx
  int result; // eax
  int v3; // edx
  int *m_pMemory; // edi
  CASW_Location_Group *v5; // [esp+4h] [ebp-4h]

  m_Size = this->m_UnlockedBy.m_Size;
  result = 0;
  v5 = this;
  if ( m_Size > 0 )
  {
    v3 = 0;
    m_pMemory = this->m_UnlockedBy.m_Memory.m_pMemory;
    while ( 1 )
    {
      if ( v3 != 0 )
      {
        if ( m_pMemory[v3 - 1] != 0
          && this->m_UnlockedBy.m_Memory.m_pMemory[v3] > this->m_UnlockedBy.m_Memory.m_pMemory[v3 - 1] )
        {
          result = m_pMemory[v3];
        }
      }
      else
      {
        result = *m_pMemory;
      }
      if ( ++v3 >= m_Size )
        break;
      this = v5;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001A90
// Name: public: class KeyValues __near * CASW_Location::GetKeyValuesForEditor(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CASW_Location::GetKeyValuesForEditor(CASW_Location *this)
{
  KeyValues *v2; // eax
  int v3; // edi
  KeyValues *v4; // ebx
  CASW_Mission_Chooser *v5; // ecx
  CASW_Location_Grid *v6; // eax
  KeyValues *v7; // eax
  CASW_Reward *v8; // ecx
  KeyValues *v9; // eax
  KeyValues *pRewards; // [esp+Ch] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v3 = 0;
  if ( v2 != nullptr )
    v4 = KeyValues::KeyValues(this: v2, setName: "Location");
  else
    v4 = nullptr;
  KeyValues::SetInt(this: v4, keyName: "x", value: this->m_iXPos);
  KeyValues::SetInt(this: v4, keyName: "y", value: this->m_iYPos);
  KeyValues::SetInt(this: v4, keyName: "MinDifficulty", value: this->m_iMinDifficulty);
  KeyValues::SetInt(this: v4, keyName: "MaxDifficulty", value: this->m_iMaxDifficulty);
  KeyValues::SetString(this: v4, keyName: "StoryScene", value: this->m_szStoryScene);
  KeyValues::SetString(this: v4, keyName: "ImageName", value: this->m_szImageName);
  if ( this->m_iLocationID == -1 )
  {
    v6 = (CASW_Location_Grid *)CASW_Mission_Chooser::LocationGrid(this: v5);
    this->m_iLocationID = CASW_Location_Grid::GetFreeLocationID(this: v6);
  }
  KeyValues::SetInt(this: v4, keyName: "ID", value: this->m_iLocationID);
  KeyValues::SetString(this: v4, keyName: "CustomMission", value: this->m_pszCustomMission);
  KeyValues::SetInt(this: v4, keyName: "Company", value: this->m_iCompanyIndex);
  KeyValues::SetInt(this: v4, keyName: "Optional", value: this->m_bIsMissionOptional);
  if ( this->m_Rewards.m_Size > 0 )
  {
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      pRewards = KeyValues::KeyValues(this: v7, setName: "Rewards");
      KeyValues::AddSubKey(this: v4, pSubkey: pRewards);
    }
    else
    {
      pRewards = nullptr;
      KeyValues::AddSubKey(this: v4, pSubkey: nullptr);
    }
    if ( this->m_Rewards.m_Size > 0 )
    {
      do
      {
        v8 = this->m_Rewards.m_Memory.m_pMemory[v3];
        v9 = v8->GetKeyValuesForEditor(this: v8);
        if ( v9 != nullptr )
          KeyValues::AddSubKey(this: pRewards, pSubkey: v9);
        ++v3;
      }
      while ( v3 < this->m_Rewards.m_Size );
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10001BE0
// Name: public: virtual class IASW_Reward __near * CASW_Location::GetReward(int)
// Source: json
//------------------------------------------------------------------------------
CASW_Reward *__thiscall CASW_Location::GetReward(CASW_Location *this, int iRewardIndex)
{
  if ( iRewardIndex < 0 || iRewardIndex >= this->m_Rewards.m_Size )
    return nullptr;
  else
    return this->m_Rewards.m_Memory.m_pMemory[iRewardIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10001C10
// Name: public: virtual int CASW_Location::GetMoneyReward(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Location::GetMoneyReward(CASW_Location *this)
{
  int v2; // ebx
  int i; // esi
  CASW_Reward *v4; // ecx
  CASW_Reward *v5; // ecx

  v2 = 0;
  for ( i = 0; i < this->m_Rewards.m_Size; ++i )
  {
    v4 = this->m_Rewards.m_Memory.m_pMemory[i];
    if ( v4->GetRewardType(this: v4) == 0 )
    {
      v5 = this->m_Rewards.m_Memory.m_pMemory[i];
      v2 += v5->GetRewardAmount(this: v5);
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10001C60
// Name: public: virtual int CASW_Location::GetXPReward(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Location::GetXPReward(CASW_Location *this)
{
  int v2; // ebx
  int i; // esi
  CASW_Reward *v4; // ecx
  CASW_Reward *v5; // ecx

  v2 = 0;
  for ( i = 0; i < this->m_Rewards.m_Size; ++i )
  {
    v4 = this->m_Rewards.m_Memory.m_pMemory[i];
    if ( v4->GetRewardType(this: v4) == 1 )
    {
      v5 = this->m_Rewards.m_Memory.m_pMemory[i];
      v2 += v5->GetRewardAmount(this: v5);
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10001CE0
// Name: public: void CASW_Location_Grid::DeleteGroup(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Location_Grid::DeleteGroup(CASW_Location_Grid *this, int iIndex)
{
  int v3; // eax

  v3 = this->m_Groups.m_Size - iIndex - 1;
  if ( v3 > 0 )
    _V_memmove(
      dest: &this->m_Groups.m_Memory.m_pMemory[iIndex],
      src: &this->m_Groups.m_Memory.m_pMemory[iIndex + 1],
      count: 4 * v3);
  --this->m_Groups.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10001D20
// Name: public: class KeyValues __near * CASW_Location_Group::GetKeyValuesForEditor(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CASW_Location_Group::GetKeyValuesForEditor(CASW_Location_Group *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  int i; // ebx
  KeyValues *v5; // eax
  int j; // ebx
  KeyValues *KeyValuesForEditor; // eax
  char buffer[64]; // [esp+Ch] [ebp-44h] BYREF
  KeyValues *pKey; // [esp+4Ch] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Group");
  else
    v3 = nullptr;
  KeyValues::SetInt(this: v3, keyName: "RequiredUnlocks", value: this->m_iRequiredUnlocks);
  V_snprintf(
    pDest: buffer,
    maxLen: 64,
    pFormat: "%d %d %d %d",
    this->m_Color._color[0],
    this->m_Color._color[1],
    this->m_Color._color[2],
    this->m_Color._color[3]);
  KeyValues::SetString(this: v3, keyName: "Color", value: buffer);
  KeyValues::SetString(this: v3, keyName: "Name", value: this->m_szGroupName);
  KeyValues::SetString(this: v3, keyName: "TitleText", value: this->m_szTitleText);
  KeyValues::SetString(this: v3, keyName: "DescriptionText", value: this->m_szDescriptionText);
  KeyValues::SetString(this: v3, keyName: "ImageName", value: this->m_szImageName);
  for ( i = 0; i < this->m_UnlockedBy.m_Size; ++i )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      pKey = KeyValues::KeyValues(this: v5, setName: "UnlockMissionID");
    else
      pKey = nullptr;
    V_snprintf(pDest: buffer, maxLen: 64, pFormat: "%d", this->m_UnlockedBy.m_Memory.m_pMemory[i]);
    KeyValues::SetStringValue(this: pKey, strValue: buffer);
    KeyValues::AddSubKey(this: v3, pSubkey: pKey);
  }
  for ( j = 0; j < this->m_Locations.m_Size; ++j )
  {
    KeyValuesForEditor = CASW_Location::GetKeyValuesForEditor(this: this->m_Locations.m_Memory.m_pMemory[j]);
    KeyValues::AddSubKey(this: v3, pSubkey: KeyValuesForEditor);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001E80
// Name: public: virtual bool CASW_Location_Group::IsGroupLocked(class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CASW_Location_Group::IsGroupLocked(
        CASW_Location_Group *this,
        CUtlVector<int,CUtlMemory<int,int> > *completedMissions)
{
  CASW_Location_Group *v2; // edx
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // edi
  int *i; // edx
  int m_Size; // [esp+4h] [ebp-4h]

  v2 = this;
  if ( asw_unlock_all_locations.m_pParent != nullptr && asw_unlock_all_locations.m_pParent->m_Value.m_nValue != 0 )
    return 0;
  m_Size = this->m_UnlockedBy.m_Size;
  if ( m_Size <= 0 )
    return 0;
  v4 = 0;
  v5 = completedMissions->m_Size;
  while ( 1 )
  {
    v6 = 0;
    if ( v5 <= 0 )
      return 1;
    v7 = v2->m_UnlockedBy.m_Memory.m_pMemory[v4];
    for ( i = completedMissions->m_Memory.m_pMemory; *i != v7; ++i )
    {
      if ( ++v6 >= v5 )
        return 1;
    }
    if ( v6 == -1 )
      return 1;
    if ( ++v4 >= m_Size )
      break;
    v2 = this;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001F90
// Name: public: bool CASW_Location_Grid::SaveLocationGrid(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CASW_Location_Grid::SaveLocationGrid(CASW_Location_Grid *this)
{
  int i; // esi
  KeyValues *KeyValuesForEditor; // edi
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  for ( i = 0; i < this->m_Groups.m_Size; ++i )
  {
    KeyValuesForEditor = CASW_Location_Group::GetKeyValuesForEditor(this: this->m_Groups.m_Memory.m_pMemory[i]);
    KeyValues::RecursiveSaveToFile(this: KeyValuesForEditor, &buf, indentLevel: 0);
    KeyValues::deleteThis(this: KeyValuesForEditor);
  }
  if ( g_pFullFileSystem->WriteFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: "resource/mission_grid.txt",
         a3: "GAME",
         a4: &buf) )
  {
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 1;
  }
  else
  {
    _Warning(a1: "Failed to SaveLocationGrid %s\n", "resource/mission_grid.txt");
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002060
// Name: public: CASW_Location::CASW_Location(class CASW_Location_Grid __near *)
// Source: json
//------------------------------------------------------------------------------
CASW_Location *__thiscall CASW_Location::CASW_Location(CASW_Location *this, CASW_Location_Grid *pLocationGrid)
{
  this->m_pLocationGrid = pLocationGrid;
  this->__vftable = (CASW_Location_vtbl *)&CASW_Location::`vftable';
  this->m_pMissionKV = nullptr;
  this->m_Rewards.m_Memory.m_pMemory = nullptr;
  this->m_Rewards.m_Memory.m_nAllocationCount = 0;
  this->m_Rewards.m_Memory.m_nGrowSize = 0;
  this->m_Rewards.m_Size = 0;
  this->m_Rewards.m_pElements = nullptr;
  this->m_szMapName[0] = 0;
  this->m_iDifficulty = 0;
  this->m_iMinDifficulty = 1;
  this->m_iMaxDifficulty = 100;
  this->m_pGroup = nullptr;
  this->m_bCompleted = false;
  this->m_iXPos = 0;
  this->m_iYPos = 0;
  this->m_pszCustomMission = nullptr;
  this->m_iCompanyIndex = 0;
  this->m_bIsMissionOptional = true;
  this->m_szStoryScene = nullptr;
  this->m_szImageName = nullptr;
  this->m_iLocationID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100020E0
// Name: public: virtual bool CASW_Location::GetCompleted(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CASW_Location::GetCompleted(CASW_Location *this)
{
  return this->m_bCompleted;
}

//------------------------------------------------------------------------------
// Address: 0x100020F0
// Name: public: virtual int CASW_Location::GetXPos(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Location::GetXPos(CASW_Location *this)
{
  return this->m_iXPos;
}

//------------------------------------------------------------------------------
// Address: 0x10002100
// Name: public: virtual int CASW_Location::GetYPos(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Location::GetYPos(CASW_Location *this)
{
  return this->m_iYPos;
}

//------------------------------------------------------------------------------
// Address: 0x10002110
// Name: public: virtual char const __near * CASW_Location::GetStoryScene(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CASW_Location::GetStoryScene(CASW_Location *this)
{
  return this->m_szStoryScene;
}

//------------------------------------------------------------------------------
// Address: 0x10002120
// Name: public: virtual char const __near * CASW_Location::GetImageName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CASW_Location::GetImageName(CASW_Location *this)
{
  return this->m_szImageName;
}

//------------------------------------------------------------------------------
// Address: 0x10002130
// Name: public: virtual int CASW_Location::IsMissionOptional(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CASW_Location::IsMissionOptional(CASW_Location *this)
{
  return this->m_bIsMissionOptional;
}

//------------------------------------------------------------------------------
// Address: 0x10002140
// Name: public: virtual void CASW_Location::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Location::SetPos(CASW_Location *this, int x, int y)
{
  this->m_iXPos = x;
  this->m_iYPos = y;
}

//------------------------------------------------------------------------------
// Address: 0x10002160
// Name: public: void CASW_Location::LoadFromKeyValues(class KeyValues __near *,class CUniformRandomStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Location::LoadFromKeyValues(CASW_Location *this, KeyValues *pKeys, KeyValues *pStream)
{
  const char *String; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  char *m_pszCustomMission; // eax
  char *v12; // eax
  KeyValues *m_pMissionKV; // ecx
  KeyValues *v14; // eax
  int v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  CASW_Location_Grid *v18; // eax
  KeyValues *Key; // eax
  CASW_Reward *v20; // eax
  _DWORD *v21; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CASW_Reward **m_pMemory; // ecx
  int v25; // eax
  CASW_Reward **v26; // ebx
  int m_iDifficulty; // [esp-4h] [ebp-10h]
  const char *v28; // [esp-4h] [ebp-10h]
  int m_iLocationID; // [esp-4h] [ebp-10h]
  void *v30; // [esp-4h] [ebp-10h]
  CASW_Reward *pReward; // [esp+14h] [ebp+8h]
  KeyValues *pRewardKey; // [esp+18h] [ebp+Ch]

  this->m_iXPos = KeyValues::GetInt(this: pKeys, keyName: "x", defaultValue: 0);
  this->m_iYPos = KeyValues::GetInt(this: pKeys, keyName: "y", defaultValue: 0);
  _V_strcpy(dest: this->m_szMapName, src: "random");
  this->m_iMinDifficulty = KeyValues::GetInt(this: pKeys, keyName: "MinDifficulty", defaultValue: 1);
  this->m_iMaxDifficulty = KeyValues::GetInt(this: pKeys, keyName: "MaxDifficulty", defaultValue: 100);
  this->m_iCompanyIndex = KeyValues::GetInt(this: pKeys, keyName: "Company", defaultValue: 0);
  this->m_bIsMissionOptional = KeyValues::GetInt(this: pKeys, keyName: "Optional", defaultValue: 1) != 0;
  this->m_iLocationID = KeyValues::GetInt(this: pKeys, keyName: "ID", defaultValue: -1);
  String = KeyValues::GetString(this: pKeys, keyName: "CustomMission", defaultValue: szDescription);
  this->m_pszCustomMission = TileGenCopyString(szString: String);
  v5 = KeyValues::GetString(this: pKeys, keyName: "StoryScene", defaultValue: szDescription);
  if ( TileGenCopyString(szString: v5) != nullptr )
  {
    v6 = KeyValues::GetString(this: pKeys, keyName: "StoryScene", defaultValue: szDescription);
    v7 = TileGenCopyString(szString: v6);
  }
  else
  {
    v7 = "spaceport_crashsite";
  }
  this->m_szStoryScene = v7;
  v8 = KeyValues::GetString(this: pKeys, keyName: "ImageName", defaultValue: szDescription);
  if ( TileGenCopyString(szString: v8) != nullptr )
  {
    v9 = KeyValues::GetString(this: pKeys, keyName: "ImageName", defaultValue: szDescription);
    v10 = TileGenCopyString(szString: v9);
  }
  else
  {
    v10 = "swarm/MissionPics/PlantMissionpic.vmt";
  }
  this->m_szImageName = v10;
  m_pszCustomMission = this->m_pszCustomMission;
  if ( m_pszCustomMission != nullptr )
    V_FixSlashes(pname: m_pszCustomMission, separator: 92);
  this->m_iDifficulty = (*(int (__thiscall **)(KeyValues *, int, int))(*(_DWORD *)pStream + 8))(
                          a1: pStream,
                          a2: this->m_iMinDifficulty,
                          a3: this->m_iMaxDifficulty);
  v12 = this->m_pszCustomMission;
  if ( v12 != nullptr && *v12 != 0 )
    this->m_pMissionKV = CASW_KeyValuesDatabase::GetFileByName(
                           this: this->m_pLocationGrid->m_pMissionDatabase,
                           pFilename: this->m_pszCustomMission);
  m_pMissionKV = this->m_pMissionKV;
  if ( m_pMissionKV != nullptr )
  {
    this->m_pMissionKV = KeyValues::MakeCopy(this: m_pMissionKV);
    if ( this->GetMissionSettings(this) != nullptr )
    {
      m_iDifficulty = this->m_iDifficulty;
      v14 = this->GetMissionSettings(this);
      KeyValues::SetInt(this: v14, keyName: "Difficulty", value: m_iDifficulty);
      v15 = _V_strlen(str: "tilegen/new_missions/");
      if ( V_strnicmp(s1: this->m_pszCustomMission, s2: "tilegen/new_missions/", n: v15) == 0 )
        _V_strlen(str: "tilegen/new_missions/");
      v28 = &this->m_pszCustomMission[_V_strlen(str: "tilegen/new_missions/")];
      v16 = this->GetMissionSettings(this);
      KeyValues::SetString(this: v16, keyName: "Filename", value: v28);
      m_iLocationID = this->m_iLocationID;
      v17 = this->GetMissionSettings(this);
      KeyValues::SetInt(this: v17, keyName: "GridLocationID", value: m_iLocationID);
    }
  }
  if ( this->m_iLocationID == -1 )
  {
    v18 = (CASW_Location_Grid *)CASW_Mission_Chooser::LocationGrid(this: (CASW_Mission_Chooser *)m_pMissionKV);
    this->m_iLocationID = CASW_Location_Grid::GetFreeLocationID(this: v18);
  }
  Key = KeyValues::FindKey(this: pKeys, keyName: "Rewards", bCreate: false);
  if ( Key != nullptr )
  {
    for ( pRewardKey = KeyValues::GetFirstSubKey(this: Key);
          pRewardKey != nullptr;
          pRewardKey = KeyValues::GetNextKey(this: pRewardKey) )
    {
      v20 = (CASW_Reward *)operator new(nSize: 0x18u);
      if ( v20 != nullptr )
      {
        v21 = &v20->__vftable;
        v20->__vftable = (CASW_Reward_vtbl *)&CASW_Reward::`vftable';
        v20->m_RewardType = ASW_REWARD_MONEY;
        v20->m_iRewardAmount = 0;
        v20->m_szRewardName = nullptr;
        v20->m_iRewardLevel = 1;
        v20->m_iRewardQuality = 0;
        pReward = v20;
      }
      else
      {
        pReward = nullptr;
        v21 = nullptr;
      }
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, KeyValues *, int))(*v21 + 20))(
             a1: v21,
             a2: pRewardKey,
             a3: this->m_iDifficulty) != 0 )
      {
        m_Size = this->m_Rewards.m_Size;
        m_nAllocationCount = this->m_Rewards.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rewards,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_Rewards.m_Size;
        m_pMemory = this->m_Rewards.m_Memory.m_pMemory;
        v25 = this->m_Rewards.m_Size - m_Size - 1;
        this->m_Rewards.m_pElements = m_pMemory;
        if ( v25 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v25);
        v26 = &this->m_Rewards.m_Memory.m_pMemory[m_Size];
        if ( v26 != nullptr )
          *v26 = pReward;
      }
      else
      {
        v30 = (void *)v21[3];
        *v21 = &CASW_Reward::`vftable';
        free(pMem: v30);
        free(pMem: v21);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100025D0
// Name: public: CASW_Location_Group::CASW_Location_Group(class CASW_Location_Grid __near *)
// Source: json
//------------------------------------------------------------------------------
CASW_Location_Group *__thiscall CASW_Location_Group::CASW_Location_Group(
        CASW_Location_Group *this,
        CASW_Location_Grid *pLocationGrid)
{
  this->__vftable = (CASW_Location_Group_vtbl *)&CASW_Location_Group::`vftable';
  this->m_UnlockedBy.m_Memory.m_pMemory = nullptr;
  this->m_UnlockedBy.m_Memory.m_nAllocationCount = 0;
  this->m_UnlockedBy.m_Memory.m_nGrowSize = 0;
  this->m_UnlockedBy.m_Size = 0;
  this->m_UnlockedBy.m_pElements = nullptr;
  this->m_Color = 0;
  CUniformRandomStream::CUniformRandomStream(this: &this->m_Random);
  this->m_Locations.m_Memory.m_pMemory = nullptr;
  this->m_Locations.m_Memory.m_nAllocationCount = 0;
  this->m_Locations.m_Memory.m_nGrowSize = 0;
  this->m_Locations.m_Size = 0;
  this->m_Locations.m_pElements = nullptr;
  this->m_pLocationGrid = pLocationGrid;
  this->m_szGroupName = nullptr;
  this->m_szTitleText = nullptr;
  this->m_szDescriptionText = nullptr;
  this->m_szImageName = nullptr;
  this->m_iRequiredUnlocks = 0;
  this->m_Color = (Color)-2139062144;
  CUtlVector<CASW_Location *,CUtlMemory<CASW_Location *,int>>::PurgeAndDeleteElements(this: &this->m_Locations);
  this->m_Random.SetSeed(this: &this->m_Random, a2: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10002650
// Name: public: virtual class Color __near & CASW_Location_Group::GetColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall CASW_Location_Group::GetColor(CASW_Location_Group *this)
{
  return &this->m_Color;
}

//------------------------------------------------------------------------------
// Address: 0x10002660
// Name: public: virtual int CASW_Location_Group::GetNumLocations(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Location_Group::GetNumLocations(vgui::BuildGroup *this)
{
  return this->m_RegisteredControlSettingsFiles.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10002670
// Name: public: void CASW_Location_Group::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Location_Group::LoadFromKeyValues(CASW_Location_Group *this, KeyValues *pKeys)
{
  CASW_Location_Group *v2; // ebx
  const char *String; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_UnlockedBy; // esi
  CUtlMemory<vgui::TreeNode *,int> *p_m_Locations; // edi
  KeyValues *FirstSubKey; // eax
  const char *Name; // eax
  CASW_Location *Int; // eax
  vgui::TreeNode **v12; // ebx
  int v13; // eax
  vgui::TreeNode **v14; // ecx
  int v15; // eax
  CASW_Location **v16; // ebx
  const char *v17; // eax
  CASW_Location *v18; // eax
  vgui::TreeNode **m_pMemory; // ebx
  int m_nAllocationCount; // eax
  vgui::TreeNode **v21; // ecx
  int v22; // eax
  CASW_Location **v23; // ebx
  Color result; // [esp+Ch] [ebp-Ch] BYREF
  CASW_Location_Group *v25; // [esp+10h] [ebp-8h]
  CASW_Location *pLocation; // [esp+14h] [ebp-4h] BYREF
  KeyValues *pSubKey; // [esp+20h] [ebp+8h]

  v2 = this;
  v25 = this;
  this->m_iRequiredUnlocks = KeyValues::GetInt(this: pKeys, keyName: "RequiredUnlocks", defaultValue: 0);
  pLocation = nullptr;
  v2->m_Color = *KeyValues::GetColor(this: pKeys, &result, keyName: "Color", defaultColor: (const Color *)&pLocation);
  String = KeyValues::GetString(this: pKeys, keyName: "Name", defaultValue: szDescription);
  v2->m_szGroupName = TileGenCopyString(szString: String);
  v4 = KeyValues::GetString(this: pKeys, keyName: "TitleText", defaultValue: szDescription);
  v2->m_szTitleText = TileGenCopyString(szString: v4);
  v5 = KeyValues::GetString(this: pKeys, keyName: "DescriptionText", defaultValue: szDescription);
  v2->m_szDescriptionText = TileGenCopyString(szString: v5);
  v6 = KeyValues::GetString(this: pKeys, keyName: "ImageName", defaultValue: szDescription);
  p_m_UnlockedBy = (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_UnlockedBy;
  v2->m_szImageName = TileGenCopyString(szString: v6);
  v2->m_UnlockedBy.m_Size = 0;
  if ( v2->m_UnlockedBy.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_UnlockedBy->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_UnlockedBy->m_pMemory);
      p_m_UnlockedBy->m_pMemory = nullptr;
    }
    v2->m_UnlockedBy.m_Memory.m_nAllocationCount = 0;
  }
  v2->m_UnlockedBy.m_pElements = v2->m_UnlockedBy.m_Memory.m_pMemory;
  p_m_Locations = (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_Locations;
  CUtlVector<CASW_Location *,CUtlMemory<CASW_Location *,int>>::PurgeAndDeleteElements(this: &v2->m_Locations);
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeys);
  pSubKey = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      if ( _V_stricmp(s1: Name, s2: "UnlockMissionID") != 0 )
      {
        v17 = KeyValues::GetName(this: pSubKey);
        if ( _V_stricmp(s1: v17, s2: "Location") != 0 )
          goto LABEL_26;
        v18 = (CASW_Location *)operator new(nSize: 0x94u);
        if ( v18 != nullptr )
          pLocation = CASW_Location::CASW_Location(this: v18, pLocationGrid: v2->m_pLocationGrid);
        else
          pLocation = nullptr;
        CASW_Location::LoadFromKeyValues(this: pLocation, pKeys: pSubKey, pStream: (KeyValues *)&v2->m_Random);
        pLocation->m_pGroup = v2;
        m_pMemory = p_m_Locations[1].m_pMemory;
        m_nAllocationCount = p_m_Locations->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: p_m_Locations,
            num: (int)m_pMemory - m_nAllocationCount + 1);
        ++p_m_Locations[1].m_pMemory;
        v21 = p_m_Locations->m_pMemory;
        v22 = (char *)p_m_Locations[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_Locations[1].m_nAllocationCount = (int)p_m_Locations->m_pMemory;
        if ( v22 > 0 )
          _V_memmove(dest: &v21[(_DWORD)m_pMemory + 1], src: &v21[(_DWORD)m_pMemory], count: 4 * v22);
        v23 = (CASW_Location **)&p_m_Locations->m_pMemory[(_DWORD)m_pMemory];
        if ( v23 != nullptr )
          *v23 = pLocation;
      }
      else
      {
        Int = (CASW_Location *)KeyValues::GetInt(this: pSubKey, keyName: nullptr, defaultValue: 0);
        v12 = p_m_UnlockedBy[1].m_pMemory;
        pLocation = Int;
        v13 = p_m_UnlockedBy->m_nAllocationCount;
        if ( (int)v12 + 1 > v13 )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: p_m_UnlockedBy,
            num: (int)v12 - v13 + 1);
        ++p_m_UnlockedBy[1].m_pMemory;
        v14 = p_m_UnlockedBy->m_pMemory;
        v15 = (char *)p_m_UnlockedBy[1].m_pMemory - (char *)v12 - 1;
        p_m_UnlockedBy[1].m_nAllocationCount = (int)p_m_UnlockedBy->m_pMemory;
        if ( v15 > 0 )
          _V_memmove(dest: &v14[(_DWORD)v12 + 1], src: &v14[(_DWORD)v12], count: 4 * v15);
        v16 = (CASW_Location **)&p_m_UnlockedBy->m_pMemory[(_DWORD)v12];
        if ( v16 != nullptr )
          *v16 = pLocation;
      }
      v2 = v25;
LABEL_26:
      pSubKey = KeyValues::GetNextKey(this: pSubKey);
      if ( pSubKey == nullptr )
        return;
      FirstSubKey = pSubKey;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100028C0
// Name: public: void CASW_Location_Grid::CreateNewGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Location_Grid::CreateNewGroup(CASW_Location_Grid *this)
{
  CASW_Location_Group *v2; // eax
  CASW_Location_Group *v3; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CASW_Location_Group **m_pMemory; // ecx
  int v7; // eax
  CASW_Location_Group **v8; // eax

  v2 = (CASW_Location_Group *)operator new(nSize: 0xDCu);
  if ( v2 != nullptr )
    v3 = CASW_Location_Group::CASW_Location_Group(this: v2, pLocationGrid: this);
  else
    v3 = nullptr;
  m_nAllocationCount = this->m_Groups.m_Memory.m_nAllocationCount;
  m_Size = this->m_Groups.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Groups,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Groups.m_Size;
  m_pMemory = this->m_Groups.m_Memory.m_pMemory;
  v7 = this->m_Groups.m_Size - m_Size - 1;
  this->m_Groups.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Groups.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10002AB0
// Name: public: virtual char const __near * CASW_Location_Group::GetImageName(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Location_Group::GetImageName(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x10002AC0
// Name: public: bool CASW_Location_Grid::LoadLocationGrid(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CASW_Location_Grid::LoadLocationGrid(CASW_Location_Grid *this)
{
  CASW_Location_Grid *v1; // ebx
  CUtlMemory<vgui::TreeNode *,int> *p_m_Groups; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  IBaseFileSystem *v5; // eax
  const char *Name; // eax
  CASW_Location_Group *v8; // eax
  CASW_Location_Group *v9; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v12; // ecx
  int v13; // eax
  CASW_Location_Group **v14; // eax
  KeyValues *pKeys; // [esp+10h] [ebp-4h]

  v1 = this;
  p_m_Groups = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Groups;
  CUtlVector<CASW_Location_Group *,CUtlMemory<CASW_Location_Group *,int>>::PurgeAndDeleteElements(this: &this->m_Groups);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "MissionGrid");
  else
    v4 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v4,
         filesystem: v5,
         resourceName: "resource/mission_grid.txt",
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    pKeys = v4;
    if ( v4 != nullptr )
    {
      while ( 1 )
      {
        Name = KeyValues::GetName(this: pKeys);
        if ( _V_stricmp(s1: Name, s2: "Group") == 0 )
        {
          v8 = (CASW_Location_Group *)operator new(nSize: 0xDCu);
          if ( v8 != nullptr )
            v9 = CASW_Location_Group::CASW_Location_Group(this: v8, pLocationGrid: v1);
          else
            v9 = nullptr;
          CASW_Location_Group::LoadFromKeyValues(this: v9, pKeys);
          m_pMemory = p_m_Groups[1].m_pMemory;
          m_nAllocationCount = p_m_Groups->m_nAllocationCount;
          if ( (int)m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: p_m_Groups,
              num: (int)m_pMemory - m_nAllocationCount + 1);
          ++p_m_Groups[1].m_pMemory;
          v12 = p_m_Groups->m_pMemory;
          v13 = (char *)p_m_Groups[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_Groups[1].m_nAllocationCount = (int)p_m_Groups->m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &v12[(_DWORD)m_pMemory + 1], src: &v12[(_DWORD)m_pMemory], count: 4 * v13);
          v14 = (CASW_Location_Group **)&p_m_Groups->m_pMemory[(_DWORD)m_pMemory];
          if ( v14 != nullptr )
            *v14 = v9;
        }
        pKeys = KeyValues::GetNextKey(this: pKeys);
        if ( pKeys == nullptr )
          break;
        v1 = this;
      }
    }
    return 1;
  }
  else
  {
    _Msg(a1: "Failed to load resource/mission_grid.txt\n");
    KeyValues::deleteThis(this: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002C00
// Name: public: CASW_Location_Grid::CASW_Location_Grid(void)
// Source: json
//------------------------------------------------------------------------------
CASW_Location_Grid *__thiscall CASW_Location_Grid::CASW_Location_Grid(CASW_Location_Grid *this)
{
  int v2; // ebx
  CASW_KeyValuesDatabase *v3; // eax
  CASW_KeyValuesDatabase *v4; // eax
  CASW_KeyValuesDatabase *v5; // eax
  CASW_KeyValuesDatabase *v6; // edi
  CTilegenMissionPreprocessor *v7; // eax
  bool v8; // sf
  CASW_KeyValuesDatabase::FileEntry_t *m_pMemory; // eax
  int v10; // ebx
  int v11; // edi
  int v13; // [esp+Ch] [ebp-4h]

  this->__vftable = (CASW_Location_Grid_vtbl *)&CASW_Location_Grid::`vftable';
  v2 = 0;
  this->m_Groups.m_Memory.m_pMemory = nullptr;
  this->m_Groups.m_Memory.m_nAllocationCount = 0;
  this->m_Groups.m_Memory.m_nGrowSize = 0;
  this->m_Groups.m_Size = 0;
  this->m_Groups.m_pElements = nullptr;
  v3 = (CASW_KeyValuesDatabase *)operator new(nSize: 0x118u);
  if ( v3 != nullptr )
    v4 = CASW_KeyValuesDatabase::CASW_KeyValuesDatabase(this: v3);
  else
    v4 = nullptr;
  this->m_pMissionDatabase = v4;
  CASW_KeyValuesDatabase::LoadFiles(this: v4, pFolderName: "tilegen/new_missions/");
  v5 = (CASW_KeyValuesDatabase *)operator new(nSize: 0x118u);
  if ( v5 != nullptr )
    v6 = CASW_KeyValuesDatabase::CASW_KeyValuesDatabase(this: v5);
  else
    v6 = nullptr;
  CASW_KeyValuesDatabase::LoadFiles(this: v6, pFolderName: "tilegen/rules/");
  v7 = (CTilegenMissionPreprocessor *)operator new(nSize: 0x2Cu);
  if ( v7 != nullptr )
  {
    v7->m_Enums.m_Memory.m_pMemory = nullptr;
    v7->m_Enums.m_Memory.m_nAllocationCount = 0;
    v7->m_Enums.m_Memory.m_nGrowSize = 0;
    v7->m_Enums.m_Size = 0;
    v7->m_Enums.m_pElements = nullptr;
    v7->m_Rules.m_Memory.m_pMemory = nullptr;
    v7->m_Rules.m_Memory.m_nAllocationCount = 0;
    v7->m_Rules.m_Memory.m_nGrowSize = 0;
    v7->m_Rules.m_Size = 0;
    v7->m_Rules.m_pElements = nullptr;
    v7->m_nUniqueIndex = 0;
  }
  else
  {
    v7 = nullptr;
  }
  this->m_pPreprocessor = v7;
  if ( v6->m_Files.m_Size > 0 )
  {
    v13 = 0;
    do
    {
      CTilegenMissionPreprocessor::ParseAndStripRules(
        this: this->m_pPreprocessor,
        pRulesKV: v6->m_Files.m_Memory.m_pMemory[v13++].m_pKeyValues);
      ++v2;
    }
    while ( v2 < v6->m_Files.m_Size );
  }
  v8 = v6->m_Files.m_Memory.m_nGrowSize < 0;
  v6->m_Files.m_Size = 0;
  if ( !v8 )
  {
    if ( v6->m_Files.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_Files.m_Memory.m_pMemory);
      v6->m_Files.m_Memory.m_pMemory = nullptr;
    }
    v6->m_Files.m_Memory.m_nAllocationCount = 0;
  }
  v8 = v6->m_Files.m_Memory.m_nGrowSize < 0;
  m_pMemory = v6->m_Files.m_Memory.m_pMemory;
  v6->m_Files.m_pElements = m_pMemory;
  if ( !v8 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      v6->m_Files.m_Memory.m_pMemory = nullptr;
    }
    v6->m_Files.m_Memory.m_nAllocationCount = 0;
  }
  free(pMem: v6);
  v10 = 0;
  if ( this->m_pMissionDatabase->m_Files.m_Size > 0 )
  {
    v11 = 0;
    do
    {
      if ( !CTilegenMissionPreprocessor::SubstituteRules(
              this: this->m_pPreprocessor,
              pKeyValues: this->m_pMissionDatabase->m_Files.m_Memory.m_pMemory[v11].m_pKeyValues) )
        _Warning(
          a1: "Error pre-processing mission '%s'.\n",
          this->m_pMissionDatabase->m_Files.m_Memory.m_pMemory[v11].m_Filename);
      ++v10;
      ++v11;
    }
    while ( v10 < this->m_pMissionDatabase->m_Files.m_Size );
  }
  CASW_Location_Grid::LoadLocationGrid(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100049B0
// Name: public: virtual char const __near * CASW_Location::GetMapName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CASW_Location::GetMapName(CASW_Location *this)
{
  return this->m_szMapName;
}

//------------------------------------------------------------------------------
// Address: 0x1007F040
// Name: public: virtual int CASW_Location::GetID(void)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall CASW_Location::GetID(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x1007F8F0
// Name: public: virtual class CASW_Location_Group __near * CASW_Location::GetCGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall CASW_Location::GetCGroup(vgui::Panel *this)
{
  return this->_border;
}
