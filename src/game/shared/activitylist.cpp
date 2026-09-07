// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/activitylist.cpp
// Functions: 14
// ============================================================

#include "game\shared\activitylist.h"

//------------------------------------------------------------------------------
// Address: 0x100044D0
// Name: void ActivityList_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ActivityList_Init()
{
  g_HighestActivity = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100044E0
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004530
// Name: bool StringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StringLessThan(const char **lhs, const char **rhs)
{
  int v3; // kr00_4

  if ( *lhs == nullptr )
    return false;
  if ( *rhs == nullptr )
    return true;
  v3 = strcmp(*lhs, *rhs);
  return v3 != 0 && -(v3 < 0) - ((v3 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004590
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100045C0
// Name: int ActivityList_IndexForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ActivityList_IndexForName(const char *pszActivityName)
{
  int StringID; // eax
  activitylist_t *v2; // eax

  StringID = CStringRegistry::GetStringID(this: &g_ActivityStrings, stringText: pszActivityName);
  if ( StringID >= 0 && (v2 = &g_ActivityList.m_Memory.m_pMemory[StringID]) != nullptr )
    return v2->activityIndex;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100045F0
// Name: char const __near * ActivityList_NameForIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ActivityList_NameForIndex(int activityIndex)
{
  int v1; // eax
  activitylist_t *v3; // eax

  v1 = 0;
  if ( g_ActivityList.m_Size <= 0 )
    return nullptr;
  while ( g_ActivityList.m_Memory.m_pMemory[v1].activityIndex != activityIndex )
  {
    if ( ++v1 >= g_ActivityList.m_Size )
      return nullptr;
  }
  v3 = &g_ActivityList.m_Memory.m_pMemory[v1];
  if ( v3 != nullptr )
    return CStringRegistry::GetStringForKey(this: &g_ActivityStrings, key: v3->stringKey);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10004640
// Name: public: virtual bool CActivityDataOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CActivityDataOps::IsEmpty(CActivityDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  return *(_DWORD *)fieldInfo->pField == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004660
// Name: public: virtual void CActivityDataOps::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CActivityDataOps::MakeEmpty(CActivityDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  *(_DWORD *)fieldInfo->pField = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004680
// Name: public: virtual void CActivityDataOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CActivityDataOps::Save(CActivityDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo, ISave *pSave)
{
  int m_Size; // edx
  activitylist_t *m_pMemory; // ecx
  int v5; // eax
  activitylist_t *v6; // eax
  const char *StringForKey; // edi
  int v8; // eax
  ISave *v9; // esi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  activitylist_t *v11; // eax

  m_Size = g_ActivityList.m_Size;
  m_pMemory = g_ActivityList.m_Memory.m_pMemory;
  v5 = 0;
  if ( g_ActivityList.m_Size > 0 )
  {
    while ( g_ActivityList.m_Memory.m_pMemory[v5].activityIndex != *(_DWORD *)fieldInfo->pField )
    {
      if ( ++v5 >= g_ActivityList.m_Size )
        goto LABEL_8;
    }
    v6 = &g_ActivityList.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      StringForKey = CStringRegistry::GetStringForKey(this: &g_ActivityStrings, key: v6->stringKey);
      if ( StringForKey != nullptr )
        goto LABEL_12;
      m_Size = g_ActivityList.m_Size;
      m_pMemory = g_ActivityList.m_Memory.m_pMemory;
    }
  }
LABEL_8:
  v8 = 0;
  if ( m_Size <= 0 )
    goto LABEL_11;
  while ( m_pMemory[v8].activityIndex != 0 )
  {
    if ( ++v8 >= m_Size )
      goto LABEL_11;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    StringForKey = CStringRegistry::GetStringForKey(this: &g_ActivityStrings, key: v11->stringKey);
  else
LABEL_11:
    StringForKey = nullptr;
LABEL_12:
  v9 = pSave;
  WriteInt_2 = pSave->WriteInt_2;
  fieldInfo = (const SaveRestoreFieldInfo_t *)((strlen(StringForKey) + 1) | 0x80800000);
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  v9->WriteString_4(this: v9, a2: StringForKey);
}

//------------------------------------------------------------------------------
// Address: 0x10004740
// Name: public: virtual void CActivityDataOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CActivityDataOps::Restore(
        CActivityDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  _DWORD *pField; // edi
  int v4; // eax
  int StringID; // eax
  activitylist_t *v6; // eax
  int activityIndex; // eax
  char nameBuf[1024]; // [esp+8h] [ebp-400h] BYREF

  pField = fieldInfo->pField;
  v4 = pRestore->ReadInt(this: pRestore);
  if ( (v4 & 0xFFFF0000) == 0x80800000 )
  {
    pRestore->ReadString_2(this: pRestore, a2: nameBuf, a3: 1024, a4: (unsigned __int16)v4);
    StringID = CStringRegistry::GetStringID(this: &g_ActivityStrings, stringText: nameBuf);
    if ( StringID >= 0 && (v6 = &g_ActivityList.m_Memory.m_pMemory[StringID]) != nullptr )
      activityIndex = v6->activityIndex;
    else
      activityIndex = -1;
    *pField = activityIndex;
    if ( activityIndex < 0 )
      *pField = 0;
  }
  else
  {
    *pField = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004B50
// Name: struct activitylist_t __near * ActivityList_AddActivityEntry(char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
activitylist_t *__cdecl ActivityList_AddActivityEntry(const char *pName, int iActivityIndex, bool isPrivate)
{
  int m_Size; // eax
  int v4; // esi
  activitylist_t *m_pMemory; // ecx
  int v6; // eax
  activitylist_t *v7; // edi
  activitylist_t *result; // eax

  m_Size = g_ActivityList.m_Size;
  v4 = g_ActivityList.m_Size;
  if ( g_ActivityList.m_Size + 1 > g_ActivityList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&g_ActivityList,
      num: g_ActivityList.m_Size - g_ActivityList.m_Memory.m_nAllocationCount + 1);
    m_Size = g_ActivityList.m_Size;
  }
  m_pMemory = g_ActivityList.m_Memory.m_pMemory;
  g_ActivityList.m_Size = m_Size + 1;
  v6 = m_Size - v4;
  g_ActivityList.m_pElements = g_ActivityList.m_Memory.m_pMemory;
  if ( v6 > 0 )
  {
    _V_memmove(
      dest: &g_ActivityList.m_Memory.m_pMemory[v4 + 1],
      src: &g_ActivityList.m_Memory.m_pMemory[v4],
      count: 8 * v6);
    m_pMemory = g_ActivityList.m_Memory.m_pMemory;
  }
  v7 = &m_pMemory[v4];
  v7->activityIndex = iActivityIndex;
  v7->stringKey = CStringRegistry::AddString(this: &g_ActivityStrings, stringText: pName, stringID: v4);
  v7->isPrivate = isPrivate;
  result = v7;
  if ( iActivityIndex > g_HighestActivity )
    g_HighestActivity = iActivityIndex;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004BF0
// Name: bool ActivityList_RegisterSharedActivity(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ActivityList_RegisterSharedActivity(const char *pszActivityName, int iActivityIndex)
{
  int StringID; // eax
  activitylist_t *v3; // eax
  int v4; // eax

  lastActivityIndex = iActivityIndex;
  StringID = CStringRegistry::GetStringID(this: &g_ActivityStrings, stringText: pszActivityName);
  if ( StringID >= 0 )
  {
    v3 = &g_ActivityList.m_Memory.m_pMemory[StringID];
    if ( v3 != nullptr )
      goto LABEL_8;
  }
  v4 = 0;
  if ( g_ActivityList.m_Size <= 0 )
    goto LABEL_6;
  while ( g_ActivityList.m_Memory.m_pMemory[v4].activityIndex != iActivityIndex )
  {
    if ( ++v4 >= g_ActivityList.m_Size )
      goto LABEL_6;
  }
  v3 = &g_ActivityList.m_Memory.m_pMemory[v4];
  if ( v3 != nullptr )
  {
LABEL_8:
    CStringRegistry::GetStringForKey(this: &g_ActivityStrings, key: v3->stringKey);
    _Warning(a1: "***\nShared activity collision! %s<->%s\n***\n", a2: pszActivityName);
    return 0;
  }
  else
  {
LABEL_6:
    ActivityList_AddActivityEntry(pName: pszActivityName, iActivityIndex, isPrivate: false);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004CA0
// Name: void ActivityList_RegisterSharedActivities(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ActivityList_RegisterSharedActivities()
{
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RESET", iActivityIndex: 0);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE", iActivityIndex: 1);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_TRANSITION", iActivityIndex: 2);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COVER", iActivityIndex: 3);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COVER_MED", iActivityIndex: 4);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COVER_LOW", iActivityIndex: 5);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK", iActivityIndex: 6);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM", iActivityIndex: 7);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_CROUCH", iActivityIndex: 8);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_CROUCH_AIM", iActivityIndex: 9);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN", iActivityIndex: 10);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM", iActivityIndex: 11);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_CROUCH", iActivityIndex: 12);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_CROUCH_AIM", iActivityIndex: 13);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_PROTECTED", iActivityIndex: 14);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SCRIPT_CUSTOM_MOVE", iActivityIndex: 15);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK1", iActivityIndex: 16);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK2", iActivityIndex: 17);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK1_LOW", iActivityIndex: 18);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK2_LOW", iActivityIndex: 19);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIESIMPLE", iActivityIndex: 20);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIEBACKWARD", iActivityIndex: 21);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIEFORWARD", iActivityIndex: 22);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIEVIOLENT", iActivityIndex: 23);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIERAGDOLL", iActivityIndex: 24);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLY", iActivityIndex: 25);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HOVER", iActivityIndex: 26);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GLIDE", iActivityIndex: 27);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SWIM", iActivityIndex: 28);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_JUMP", iActivityIndex: 29);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HOP", iActivityIndex: 30);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_LEAP", iActivityIndex: 31);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_LAND", iActivityIndex: 32);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CLIMB_UP", iActivityIndex: 33);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CLIMB_DOWN", iActivityIndex: 34);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CLIMB_DISMOUNT", iActivityIndex: 35);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIPLADDER_UP", iActivityIndex: 36);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIPLADDER_DOWN", iActivityIndex: 37);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STRAFE_LEFT", iActivityIndex: 38);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STRAFE_RIGHT", iActivityIndex: 39);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ROLL_LEFT", iActivityIndex: 40);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ROLL_RIGHT", iActivityIndex: 41);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_TURN_LEFT", iActivityIndex: 42);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_TURN_RIGHT", iActivityIndex: 43);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCH", iActivityIndex: 44);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHIDLE", iActivityIndex: 45);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STAND", iActivityIndex: 46);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_USE", iActivityIndex: 47);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ALIEN_BURROW_IDLE", iActivityIndex: 48);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ALIEN_BURROW_OUT", iActivityIndex: 49);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL1", iActivityIndex: 50);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL2", iActivityIndex: 51);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL3", iActivityIndex: 52);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_ADVANCE", iActivityIndex: 53);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_FORWARD", iActivityIndex: 54);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_GROUP", iActivityIndex: 55);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_HALT", iActivityIndex: 56);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_LEFT", iActivityIndex: 57);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_RIGHT", iActivityIndex: 58);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_TAKECOVER", iActivityIndex: 59);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_LOOKBACK_RIGHT", iActivityIndex: 60);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_LOOKBACK_LEFT", iActivityIndex: 61);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COWER", iActivityIndex: 62);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMALL_FLINCH", iActivityIndex: 63);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BIG_FLINCH", iActivityIndex: 64);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_ATTACK1", iActivityIndex: 65);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_ATTACK2", iActivityIndex: 66);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD", iActivityIndex: 67);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_START", iActivityIndex: 68);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_FINISH", iActivityIndex: 69);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_LOW", iActivityIndex: 70);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ARM", iActivityIndex: 71);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DISARM", iActivityIndex: 72);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DROP_WEAPON", iActivityIndex: 73);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DROP_WEAPON_SHOTGUN", iActivityIndex: 74);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PICKUP_GROUND", iActivityIndex: 75);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PICKUP_RACK", iActivityIndex: 76);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ANGRY", iActivityIndex: 77);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_RELAXED", iActivityIndex: 78);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_STIMULATED", iActivityIndex: 79);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AGITATED", iActivityIndex: 80);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_STEALTH", iActivityIndex: 81);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_HURT", iActivityIndex: 82);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_RELAXED", iActivityIndex: 83);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_STIMULATED", iActivityIndex: 84);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AGITATED", iActivityIndex: 85);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_STEALTH", iActivityIndex: 86);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_RELAXED", iActivityIndex: 87);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_STIMULATED", iActivityIndex: 88);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AGITATED", iActivityIndex: 89);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_STEALTH", iActivityIndex: 90);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_RELAXED", iActivityIndex: 91);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_STIMULATED", iActivityIndex: 92);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_AGITATED", iActivityIndex: 93);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_STEALTH", iActivityIndex: 94);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_RELAXED", iActivityIndex: 95);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_STIMULATED", iActivityIndex: 96);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_AGITATED", iActivityIndex: 97);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_STEALTH", iActivityIndex: 98);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_RELAXED", iActivityIndex: 99);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_STIMULATED", iActivityIndex: 100);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_AGITATED", iActivityIndex: 101);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_STEALTH", iActivityIndex: 102);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHIDLE_STIMULATED", iActivityIndex: 103);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHIDLE_AIM_STIMULATED", iActivityIndex: 104);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHIDLE_AGITATED", iActivityIndex: 105);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_HURT", iActivityIndex: 106);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_HURT", iActivityIndex: 107);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SPECIAL_ATTACK1", iActivityIndex: 108);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SPECIAL_ATTACK2", iActivityIndex: 109);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COMBAT_IDLE", iActivityIndex: 110);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_SCARED", iActivityIndex: 111);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_SCARED", iActivityIndex: 112);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VICTORY_DANCE", iActivityIndex: 113);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_HEADSHOT", iActivityIndex: 114);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_CHESTSHOT", iActivityIndex: 115);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_GUTSHOT", iActivityIndex: 116);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_BACKSHOT", iActivityIndex: 117);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_HEAD", iActivityIndex: 118);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_CHEST", iActivityIndex: 119);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_STOMACH", iActivityIndex: 120);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_LEFTARM", iActivityIndex: 121);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_RIGHTARM", iActivityIndex: 122);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_LEFTLEG", iActivityIndex: 123);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_RIGHTLEG", iActivityIndex: 124);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_PHYSICS", iActivityIndex: 125);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_HEAD_BACK", iActivityIndex: 126);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_CHEST_BACK", iActivityIndex: 127);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_STOMACH_BACK", iActivityIndex: 128);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_CROUCH_FRONT", iActivityIndex: 129);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_CROUCH_BACK", iActivityIndex: 130);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_CROUCH_LEFT", iActivityIndex: 131);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_CROUCH_RIGHT", iActivityIndex: 132);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ON_FIRE", iActivityIndex: 133);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_ON_FIRE", iActivityIndex: 134);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_ON_FIRE", iActivityIndex: 135);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RAPPEL_LOOP", iActivityIndex: 136);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_180_LEFT", iActivityIndex: 137);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_180_RIGHT", iActivityIndex: 138);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_90_LEFT", iActivityIndex: 139);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_90_RIGHT", iActivityIndex: 140);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STEP_LEFT", iActivityIndex: 141);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STEP_RIGHT", iActivityIndex: 142);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STEP_BACK", iActivityIndex: 143);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STEP_FORE", iActivityIndex: 144);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK1", iActivityIndex: 145);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK2", iActivityIndex: 146);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_MELEE_ATTACK1", iActivityIndex: 147);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_MELEE_ATTACK2", iActivityIndex: 148);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK1_LOW", iActivityIndex: 149);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK2_LOW", iActivityIndex: 150);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_ATTACK_SWING_GESTURE", iActivityIndex: 151);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_SMALL_FLINCH", iActivityIndex: 152);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_BIG_FLINCH", iActivityIndex: 153);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_BLAST", iActivityIndex: 154);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_BLAST_SHOTGUN", iActivityIndex: 155);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_BLAST_DAMAGED", iActivityIndex: 156);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_BLAST_DAMAGED_SHOTGUN", iActivityIndex: 157);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_HEAD", iActivityIndex: 158);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_CHEST", iActivityIndex: 159);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_STOMACH", iActivityIndex: 160);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_LEFTARM", iActivityIndex: 161);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_RIGHTARM", iActivityIndex: 162);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_LEFTLEG", iActivityIndex: 163);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_RIGHTLEG", iActivityIndex: 164);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_LEFT", iActivityIndex: 165);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_RIGHT", iActivityIndex: 166);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_LEFT45", iActivityIndex: 167);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_RIGHT45", iActivityIndex: 168);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_LEFT90", iActivityIndex: 169);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_RIGHT90", iActivityIndex: 170);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_LEFT45_FLAT", iActivityIndex: 171);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_RIGHT45_FLAT", iActivityIndex: 172);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_LEFT90_FLAT", iActivityIndex: 173);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_RIGHT90_FLAT", iActivityIndex: 174);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BARNACLE_HIT", iActivityIndex: 175);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BARNACLE_PULL", iActivityIndex: 176);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BARNACLE_CHOMP", iActivityIndex: 177);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BARNACLE_CHEW", iActivityIndex: 178);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DO_NOT_DISTURB", iActivityIndex: 179);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SPECIFIC_SEQUENCE", iActivityIndex: 180);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DRAW", iActivityIndex: 181);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HOLSTER", iActivityIndex: 182);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IDLE", iActivityIndex: 183);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_FIDGET", iActivityIndex: 184);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PULLBACK", iActivityIndex: 185);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PULLBACK_HIGH", iActivityIndex: 186);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PULLBACK_LOW", iActivityIndex: 187);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_THROW", iActivityIndex: 188);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PULLPIN", iActivityIndex: 189);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PRIMARYATTACK", iActivityIndex: 190);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SECONDARYATTACK", iActivityIndex: 191);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_RELOAD", iActivityIndex: 192);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DRYFIRE", iActivityIndex: 193);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HITLEFT", iActivityIndex: 194);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HITLEFT2", iActivityIndex: 195);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HITRIGHT", iActivityIndex: 196);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HITRIGHT2", iActivityIndex: 197);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HITCENTER", iActivityIndex: 198);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HITCENTER2", iActivityIndex: 199);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_MISSLEFT", iActivityIndex: 200);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_MISSLEFT2", iActivityIndex: 201);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_MISSRIGHT", iActivityIndex: 202);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_MISSRIGHT2", iActivityIndex: 203);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_MISSCENTER", iActivityIndex: 204);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_MISSCENTER2", iActivityIndex: 205);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HAULBACK", iActivityIndex: 206);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SWINGHARD", iActivityIndex: 207);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SWINGMISS", iActivityIndex: 208);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SWINGHIT", iActivityIndex: 209);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IDLE_TO_LOWERED", iActivityIndex: 210);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IDLE_LOWERED", iActivityIndex: 211);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_LOWERED_TO_IDLE", iActivityIndex: 212);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_RECOIL1", iActivityIndex: 213);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_RECOIL2", iActivityIndex: 214);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_RECOIL3", iActivityIndex: 215);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PICKUP", iActivityIndex: 216);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_RELEASE", iActivityIndex: 217);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_ATTACH_SILENCER", iActivityIndex: 218);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DETACH_SILENCER", iActivityIndex: 219);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_IDLE", iActivityIndex: 220);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_ND_IDLE", iActivityIndex: 221);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_ATTACH", iActivityIndex: 222);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_ATTACH2", iActivityIndex: 223);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_ND_ATTACH", iActivityIndex: 224);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_ND_ATTACH2", iActivityIndex: 225);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_DETONATE", iActivityIndex: 226);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_DETONATOR_HOLSTER", iActivityIndex: 227);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_DRAW", iActivityIndex: 228);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_ND_DRAW", iActivityIndex: 229);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_TO_THROW", iActivityIndex: 230);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_TO_THROW_ND", iActivityIndex: 231);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_TO_TRIPMINE_ND", iActivityIndex: 232);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_IDLE", iActivityIndex: 233);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_ND_IDLE", iActivityIndex: 234);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_THROW", iActivityIndex: 235);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_THROW2", iActivityIndex: 236);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_THROW_ND", iActivityIndex: 237);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_THROW_ND2", iActivityIndex: 238);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_DRAW", iActivityIndex: 239);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_ND_DRAW", iActivityIndex: 240);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_TO_STICKWALL", iActivityIndex: 241);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_TO_STICKWALL_ND", iActivityIndex: 242);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_DETONATE", iActivityIndex: 243);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_DETONATOR_HOLSTER", iActivityIndex: 244);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_TO_TRIPMINE_ND", iActivityIndex: 245);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_TRIPMINE_IDLE", iActivityIndex: 246);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_TRIPMINE_DRAW", iActivityIndex: 247);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_TRIPMINE_ATTACH", iActivityIndex: 248);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_TRIPMINE_ATTACH2", iActivityIndex: 249);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_TRIPMINE_TO_STICKWALL_ND", iActivityIndex: 250);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_TRIPMINE_TO_THROW_ND", iActivityIndex: 251);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_DETONATOR_IDLE", iActivityIndex: 252);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_DETONATOR_DRAW", iActivityIndex: 253);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_DETONATOR_DETONATE", iActivityIndex: 254);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_DETONATOR_HOLSTER", iActivityIndex: 255);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_DETONATOR_STICKWALL_DRAW", iActivityIndex: 256);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_DETONATOR_THROW_DRAW", iActivityIndex: 257);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHOTGUN_RELOAD_START", iActivityIndex: 258);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHOTGUN_RELOAD_FINISH", iActivityIndex: 259);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHOTGUN_PUMP", iActivityIndex: 260);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_IDLE2", iActivityIndex: 261);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_FIRE2", iActivityIndex: 262);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_DRAW2", iActivityIndex: 263);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_RELOAD2", iActivityIndex: 264);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_DRYFIRE2", iActivityIndex: 265);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_TOAUTO", iActivityIndex: 266);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_TOBURST", iActivityIndex: 267);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PHYSCANNON_UPGRADE", iActivityIndex: 268);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_AR1", iActivityIndex: 269);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_AR2", iActivityIndex: 270);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_AR2_LOW", iActivityIndex: 271);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_AR2_GRENADE", iActivityIndex: 272);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_HMG1", iActivityIndex: 273);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_ML", iActivityIndex: 274);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SMG1", iActivityIndex: 275);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SMG1_LOW", iActivityIndex: 276);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SMG2", iActivityIndex: 277);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SHOTGUN", iActivityIndex: 278);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SHOTGUN_LOW", iActivityIndex: 279);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_PISTOL", iActivityIndex: 280);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_PISTOL_LOW", iActivityIndex: 281);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SLAM", iActivityIndex: 282);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_TRIPWIRE", iActivityIndex: 283);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_THROW", iActivityIndex: 284);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SNIPER_RIFLE", iActivityIndex: 285);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_RPG", iActivityIndex: 286);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_ATTACK_SWING", iActivityIndex: 287);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_AIM_LOW", iActivityIndex: 288);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_AIM_SMG1_LOW", iActivityIndex: 289);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_AIM_PISTOL_LOW", iActivityIndex: 290);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_AIM_AR2_LOW", iActivityIndex: 291);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COVER_PISTOL_LOW", iActivityIndex: 292);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COVER_SMG1_LOW", iActivityIndex: 293);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_AR1", iActivityIndex: 294);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_AR2", iActivityIndex: 295);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_AR2_GRENADE", iActivityIndex: 296);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_HMG1", iActivityIndex: 297);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_ML", iActivityIndex: 298);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_SMG1", iActivityIndex: 299);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_SMG1_LOW", iActivityIndex: 300);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_SMG2", iActivityIndex: 301);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_SHOTGUN", iActivityIndex: 302);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_PISTOL", iActivityIndex: 303);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_PISTOL_LOW", iActivityIndex: 304);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_SLAM", iActivityIndex: 305);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_TRIPWIRE", iActivityIndex: 306);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_THROW", iActivityIndex: 307);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_SNIPER_RIFLE", iActivityIndex: 308);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_MELEE_ATTACK_SWING", iActivityIndex: 309);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_RIFLE", iActivityIndex: 310);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SMG1", iActivityIndex: 311);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ANGRY_SMG1", iActivityIndex: 312);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_PISTOL", iActivityIndex: 313);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ANGRY_PISTOL", iActivityIndex: 314);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ANGRY_SHOTGUN", iActivityIndex: 315);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_STEALTH_PISTOL", iActivityIndex: 316);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_PACKAGE", iActivityIndex: 317);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_PACKAGE", iActivityIndex: 318);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SUITCASE", iActivityIndex: 319);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_SUITCASE", iActivityIndex: 320);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SMG1_RELAXED", iActivityIndex: 321);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SMG1_STIMULATED", iActivityIndex: 322);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_RIFLE_RELAXED", iActivityIndex: 323);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_RIFLE_RELAXED", iActivityIndex: 324);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_RIFLE_STIMULATED", iActivityIndex: 325);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_RIFLE_STIMULATED", iActivityIndex: 326);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_RIFLE_STIMULATED", iActivityIndex: 327);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_RIFLE_STIMULATED", iActivityIndex: 328);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_RIFLE_STIMULATED", iActivityIndex: 329);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SHOTGUN_RELAXED", iActivityIndex: 330);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SHOTGUN_STIMULATED", iActivityIndex: 331);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SHOTGUN_AGITATED", iActivityIndex: 332);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_ANGRY", iActivityIndex: 333);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_POLICE_HARASS1", iActivityIndex: 334);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_POLICE_HARASS2", iActivityIndex: 335);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_MANNEDGUN", iActivityIndex: 336);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_MELEE", iActivityIndex: 337);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ANGRY_MELEE", iActivityIndex: 338);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_RPG_RELAXED", iActivityIndex: 339);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_RPG", iActivityIndex: 340);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ANGRY_RPG", iActivityIndex: 341);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COVER_LOW_RPG", iActivityIndex: 342);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_RPG", iActivityIndex: 343);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_RPG", iActivityIndex: 344);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_CROUCH_RPG", iActivityIndex: 345);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_CROUCH_RPG", iActivityIndex: 346);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_RPG_RELAXED", iActivityIndex: 347);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_RPG_RELAXED", iActivityIndex: 348);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_RIFLE", iActivityIndex: 349);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_RIFLE", iActivityIndex: 350);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_CROUCH_RIFLE", iActivityIndex: 351);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_CROUCH_AIM_RIFLE", iActivityIndex: 352);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_RIFLE", iActivityIndex: 353);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_RIFLE", iActivityIndex: 354);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_CROUCH_RIFLE", iActivityIndex: 355);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_CROUCH_AIM_RIFLE", iActivityIndex: 356);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_STEALTH_PISTOL", iActivityIndex: 357);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_SHOTGUN", iActivityIndex: 358);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_SHOTGUN", iActivityIndex: 359);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_PISTOL", iActivityIndex: 360);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_PISTOL", iActivityIndex: 361);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_PISTOL", iActivityIndex: 362);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_PISTOL", iActivityIndex: 363);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_STEALTH_PISTOL", iActivityIndex: 364);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_STEALTH_PISTOL", iActivityIndex: 365);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_STEALTH_PISTOL", iActivityIndex: 366);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_PISTOL", iActivityIndex: 367);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_PISTOL_LOW", iActivityIndex: 368);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_SMG1", iActivityIndex: 369);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_SMG1_LOW", iActivityIndex: 370);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_SHOTGUN", iActivityIndex: 371);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_SHOTGUN_LOW", iActivityIndex: 372);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RELOAD", iActivityIndex: 373);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RELOAD_PISTOL", iActivityIndex: 374);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RELOAD_SMG1", iActivityIndex: 375);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RELOAD_SHOTGUN", iActivityIndex: 376);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_LEAN_LEFT", iActivityIndex: 377);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_LEAN_LEFT_ENTRY", iActivityIndex: 378);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_LEAN_LEFT_EXIT", iActivityIndex: 379);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_LEAN_BACK", iActivityIndex: 380);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_LEAN_BACK_ENTRY", iActivityIndex: 381);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_LEAN_BACK_EXIT", iActivityIndex: 382);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_SIT_GROUND", iActivityIndex: 383);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_SIT_GROUND_ENTRY", iActivityIndex: 384);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_SIT_GROUND_EXIT", iActivityIndex: 385);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_SIT_CHAIR", iActivityIndex: 386);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_SIT_CHAIR_ENTRY", iActivityIndex: 387);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_SIT_CHAIR_EXIT", iActivityIndex: 388);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_STAND", iActivityIndex: 389);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_QUEUE", iActivityIndex: 390);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DUCK_DODGE", iActivityIndex: 391);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_BARNACLE_SWALLOW", iActivityIndex: 392);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_BARNACLE_STRANGLE", iActivityIndex: 393);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PHYSCANNON_DETACH", iActivityIndex: 394);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PHYSCANNON_ANIMATE", iActivityIndex: 395);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PHYSCANNON_ANIMATE_PRE", iActivityIndex: 396);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PHYSCANNON_ANIMATE_POST", iActivityIndex: 397);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_FRONTSIDE", iActivityIndex: 398);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_RIGHTSIDE", iActivityIndex: 399);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_BACKSIDE", iActivityIndex: 400);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_LEFTSIDE", iActivityIndex: 401);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_CROUCH_FRONTSIDE", iActivityIndex: 402);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_CROUCH_RIGHTSIDE", iActivityIndex: 403);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_CROUCH_BACKSIDE", iActivityIndex: 404);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_CROUCH_LEFTSIDE", iActivityIndex: 405);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OPEN_DOOR", iActivityIndex: 406);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DI_ALYX_ZOMBIE_MELEE", iActivityIndex: 407);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DI_ALYX_ZOMBIE_TORSO_MELEE", iActivityIndex: 408);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DI_ALYX_HEADCRAB_MELEE", iActivityIndex: 409);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DI_ALYX_ANTLION", iActivityIndex: 410);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DI_ALYX_ZOMBIE_SHOTGUN64", iActivityIndex: 411);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DI_ALYX_ZOMBIE_SHOTGUN26", iActivityIndex: 412);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_READINESS_RELAXED_TO_STIMULATED", iActivityIndex: 413);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_READINESS_RELAXED_TO_STIMULATED_WALK", iActivityIndex: 414);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_READINESS_AGITATED_TO_STIMULATED", iActivityIndex: 415);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_READINESS_STIMULATED_TO_RELAXED", iActivityIndex: 416);
  ActivityList_RegisterSharedActivity(
    pszActivityName: "ACT_READINESS_PISTOL_RELAXED_TO_STIMULATED",
    iActivityIndex: 417);
  ActivityList_RegisterSharedActivity(
    pszActivityName: "ACT_READINESS_PISTOL_RELAXED_TO_STIMULATED_WALK",
    iActivityIndex: 418);
  ActivityList_RegisterSharedActivity(
    pszActivityName: "ACT_READINESS_PISTOL_AGITATED_TO_STIMULATED",
    iActivityIndex: 419);
  ActivityList_RegisterSharedActivity(
    pszActivityName: "ACT_READINESS_PISTOL_STIMULATED_TO_RELAXED",
    iActivityIndex: 420);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_CARRY", iActivityIndex: 421);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_CARRY", iActivityIndex: 422);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STARTDYING", iActivityIndex: 423);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DYINGLOOP", iActivityIndex: 424);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DYINGTODEAD", iActivityIndex: 425);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RIDE_MANNED_GUN", iActivityIndex: 426);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SPRINT_ENTER", iActivityIndex: 427);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SPRINT_IDLE", iActivityIndex: 428);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SPRINT_LEAVE", iActivityIndex: 429);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FIRE_START", iActivityIndex: 430);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FIRE_LOOP", iActivityIndex: 431);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FIRE_END", iActivityIndex: 432);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_GRENADEIDLE", iActivityIndex: 433);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_GRENADEREADY", iActivityIndex: 434);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_PRIMARYATTACK", iActivityIndex: 435);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_GRENADEIDLE", iActivityIndex: 436);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_GRENADEREADY", iActivityIndex: 437);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_PRIMARYATTACK", iActivityIndex: 438);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_SHIELD_UP", iActivityIndex: 439);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_SHIELD_DOWN", iActivityIndex: 440);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_SHIELD_UP_IDLE", iActivityIndex: 441);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_SHIELD_ATTACK", iActivityIndex: 442);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_SHIELD_KNOCKBACK", iActivityIndex: 443);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIELD_UP", iActivityIndex: 444);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIELD_DOWN", iActivityIndex: 445);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIELD_UP_IDLE", iActivityIndex: 446);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIELD_ATTACK", iActivityIndex: 447);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIELD_KNOCKBACK", iActivityIndex: 448);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_SHIELD_UP", iActivityIndex: 449);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_SHIELD_DOWN", iActivityIndex: 450);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_SHIELD_UP_IDLE", iActivityIndex: 451);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_SHIELD_ATTACK", iActivityIndex: 452);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_SHIELD_KNOCKBACK", iActivityIndex: 453);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_TURNRIGHT45", iActivityIndex: 454);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_TURNLEFT45", iActivityIndex: 455);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_TURN", iActivityIndex: 456);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_ASSEMBLING", iActivityIndex: 457);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_DISMANTLING", iActivityIndex: 458);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_STARTUP", iActivityIndex: 459);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_RUNNING", iActivityIndex: 460);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_IDLE", iActivityIndex: 461);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_PLACING", iActivityIndex: 462);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_DETERIORATING", iActivityIndex: 463);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_UPGRADING", iActivityIndex: 464);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DEPLOY", iActivityIndex: 465);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DEPLOY_IDLE", iActivityIndex: 466);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_UNDEPLOY", iActivityIndex: 467);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROSSBOW_DRAW_UNLOADED", iActivityIndex: 468);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GAUSS_SPINUP", iActivityIndex: 469);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GAUSS_SPINCYCLE", iActivityIndex: 470);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PRIMARYATTACK_SILENCED", iActivityIndex: 471);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_RELOAD_SILENCED", iActivityIndex: 472);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DRYFIRE_SILENCED", iActivityIndex: 473);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IDLE_SILENCED", iActivityIndex: 474);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DRAW_SILENCED", iActivityIndex: 475);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IDLE_EMPTY_LEFT", iActivityIndex: 476);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DRYFIRE_LEFT", iActivityIndex: 477);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IS_DRAW", iActivityIndex: 478);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IS_HOLSTER", iActivityIndex: 479);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IS_IDLE", iActivityIndex: 480);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IS_PRIMARYATTACK", iActivityIndex: 481);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PLAYER_IDLE_FIRE", iActivityIndex: 482);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PLAYER_CROUCH_FIRE", iActivityIndex: 483);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PLAYER_CROUCH_WALK_FIRE", iActivityIndex: 484);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PLAYER_WALK_FIRE", iActivityIndex: 485);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PLAYER_RUN_FIRE", iActivityIndex: 486);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLETORUN", iActivityIndex: 487);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUNTOIDLE", iActivityIndex: 488);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DRAW_DEPLOYED", iActivityIndex: 489);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_IDLE_MELEE", iActivityIndex: 490);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_RUN_MELEE", iActivityIndex: 491);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_IDLE_CROUCH_MELEE", iActivityIndex: 492);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_WALK_CROUCH_MELEE", iActivityIndex: 493);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_GESTURE_RANGE_ATTACK_MELEE", iActivityIndex: 494);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_GESTURE_RELOAD_MELEE", iActivityIndex: 495);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_JUMP_MELEE", iActivityIndex: 496);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_FIZZLE", iActivityIndex: 497);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_IDLE", iActivityIndex: 498);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_IDLE", iActivityIndex: 499);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_DEPLOYED_IDLE", iActivityIndex: 500);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_DEPLOYED", iActivityIndex: 501);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DEPLOYED_IDLE", iActivityIndex: 502);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN", iActivityIndex: 503);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK", iActivityIndex: 504);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK", iActivityIndex: 505);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK", iActivityIndex: 506);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SPRINT", iActivityIndex: 507);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP", iActivityIndex: 508);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START", iActivityIndex: 509);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT", iActivityIndex: 510);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND", iActivityIndex: 511);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_IMPACT_N", iActivityIndex: 512);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_IMPACT_E", iActivityIndex: 513);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_IMPACT_W", iActivityIndex: 514);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_IMPACT_S", iActivityIndex: 515);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_IMPACT_TOP", iActivityIndex: 516);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DOUBLEJUMP", iActivityIndex: 517);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM", iActivityIndex: 518);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DEPLOYED", iActivityIndex: 519);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_DEPLOYED", iActivityIndex: 520);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_VCD", iActivityIndex: 521);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_PRIMARYFIRE", iActivityIndex: 522);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_PRIMARYFIRE_DEPLOYED", iActivityIndex: 523);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_SECONDARYFIRE", iActivityIndex: 524);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_GRENADE", iActivityIndex: 525);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_PRIMARYFIRE", iActivityIndex: 526);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_PRIMARYFIRE_DEPLOYED", iActivityIndex: 527);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_SECONDARYFIRE", iActivityIndex: 528);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_GRENADE", iActivityIndex: 529);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_PRIMARYFIRE", iActivityIndex: 530);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_SECONDARYFIRE", iActivityIndex: 531);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_GRENADE", iActivityIndex: 532);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_PRIMARYFIRE", iActivityIndex: 533);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_SECONDARYFIRE", iActivityIndex: 534);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_GRENADE", iActivityIndex: 535);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND", iActivityIndex: 536);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_LOOP", iActivityIndex: 537);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_END", iActivityIndex: 538);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH", iActivityIndex: 539);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_LOOP", iActivityIndex: 540);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_END", iActivityIndex: 541);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM", iActivityIndex: 542);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_LOOP", iActivityIndex: 543);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_END", iActivityIndex: 544);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK", iActivityIndex: 545);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_LOOP", iActivityIndex: 546);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_END", iActivityIndex: 547);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_PREFIRE", iActivityIndex: 548);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_POSTFIRE", iActivityIndex: 549);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_STARTFIRE", iActivityIndex: 550);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_PREFIRE", iActivityIndex: 551);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_POSTFIRE", iActivityIndex: 552);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_PREFIRE", iActivityIndex: 553);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_POSTFIRE", iActivityIndex: 554);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_PRIMARY", iActivityIndex: 555);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_PRIMARY", iActivityIndex: 556);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_PRIMARY", iActivityIndex: 557);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_PRIMARY", iActivityIndex: 558);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_PRIMARY", iActivityIndex: 559);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_PRIMARY", iActivityIndex: 560);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_PRIMARY", iActivityIndex: 561);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_PRIMARY", iActivityIndex: 562);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_PRIMARY", iActivityIndex: 563);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_PRIMARY", iActivityIndex: 564);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_PRIMARY", iActivityIndex: 565);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DEPLOYED_PRIMARY", iActivityIndex: 566);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_DEPLOYED_PRIMARY", iActivityIndex: 567);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_PRIMARY", iActivityIndex: 568);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_PRIMARY_DEPLOYED", iActivityIndex: 569);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_PRIMARY", iActivityIndex: 570);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_PRIMARY_DEPLOYED", iActivityIndex: 571);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_PRIMARY", iActivityIndex: 572);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_PRIMARY", iActivityIndex: 573);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_PRIMARY", iActivityIndex: 574);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_PRIMARY_LOOP", iActivityIndex: 575);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_PRIMARY_END", iActivityIndex: 576);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_PRIMARY", iActivityIndex: 577);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_PRIMARY_LOOP", iActivityIndex: 578);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_PRIMARY_END", iActivityIndex: 579);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_PRIMARY", iActivityIndex: 580);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_PRIMARY_LOOP", iActivityIndex: 581);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_PRIMARY_END", iActivityIndex: 582);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_PRIMARY", iActivityIndex: 583);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_PRIMARY_LOOP", iActivityIndex: 584);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_PRIMARY_END", iActivityIndex: 585);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_GRENADE_PRIMARY", iActivityIndex: 586);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_GRENADE_PRIMARY", iActivityIndex: 587);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_GRENADE_PRIMARY", iActivityIndex: 588);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_GRENADE_PRIMARY", iActivityIndex: 589);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_SECONDARY", iActivityIndex: 590);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_SECONDARY", iActivityIndex: 591);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_SECONDARY", iActivityIndex: 592);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_SECONDARY", iActivityIndex: 593);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_SECONDARY", iActivityIndex: 594);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_SECONDARY", iActivityIndex: 595);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_SECONDARY", iActivityIndex: 596);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_SECONDARY", iActivityIndex: 597);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_SECONDARY", iActivityIndex: 598);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_SECONDARY", iActivityIndex: 599);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_SECONDARY", iActivityIndex: 600);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_SECONDARY", iActivityIndex: 601);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_SECONDARY", iActivityIndex: 602);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_SECONDARY", iActivityIndex: 603);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_SECONDARY", iActivityIndex: 604);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_SECONDARY", iActivityIndex: 605);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_SECONDARY_LOOP", iActivityIndex: 606);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_SECONDARY_END", iActivityIndex: 607);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_SECONDARY", iActivityIndex: 608);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_SECONDARY_LOOP", iActivityIndex: 609);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_SECONDARY_END", iActivityIndex: 610);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_SECONDARY", iActivityIndex: 611);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_SECONDARY_LOOP", iActivityIndex: 612);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_SECONDARY_END", iActivityIndex: 613);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_SECONDARY", iActivityIndex: 614);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_SECONDARY_LOOP", iActivityIndex: 615);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_SECONDARY_END", iActivityIndex: 616);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_GRENADE_SECONDARY", iActivityIndex: 617);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_GRENADE_SECONDARY", iActivityIndex: 618);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_GRENADE_SECONDARY", iActivityIndex: 619);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_GRENADE_SECONDARY", iActivityIndex: 620);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_MELEE", iActivityIndex: 621);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_MELEE", iActivityIndex: 622);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_MELEE", iActivityIndex: 623);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_MELEE", iActivityIndex: 624);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_MELEE", iActivityIndex: 625);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_MELEE", iActivityIndex: 626);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_MELEE", iActivityIndex: 627);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_MELEE", iActivityIndex: 628);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_MELEE", iActivityIndex: 629);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_MELEE", iActivityIndex: 630);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_MELEE", iActivityIndex: 631);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_MELEE", iActivityIndex: 632);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_MELEE_SECONDARY", iActivityIndex: 633);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_MELEE", iActivityIndex: 634);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_MELEE_SECONDARY", iActivityIndex: 635);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_MELEE", iActivityIndex: 636);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_MELEE", iActivityIndex: 637);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_GRENADE_MELEE", iActivityIndex: 638);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_GRENADE_MELEE", iActivityIndex: 639);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_GRENADE_MELEE", iActivityIndex: 640);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_GRENADE_MELEE", iActivityIndex: 641);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_ITEM1", iActivityIndex: 642);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_ITEM1", iActivityIndex: 643);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_ITEM1", iActivityIndex: 644);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_ITEM1", iActivityIndex: 645);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_ITEM1", iActivityIndex: 646);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_ITEM1", iActivityIndex: 647);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_ITEM1", iActivityIndex: 648);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_ITEM1", iActivityIndex: 649);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_ITEM1", iActivityIndex: 650);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_ITEM1", iActivityIndex: 651);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_ITEM1", iActivityIndex: 652);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_ITEM1", iActivityIndex: 653);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_ITEM1_SECONDARY", iActivityIndex: 654);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_ITEM1", iActivityIndex: 655);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_ITEM1_SECONDARY", iActivityIndex: 656);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_ITEM1", iActivityIndex: 657);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_ITEM1", iActivityIndex: 658);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_ITEM2", iActivityIndex: 659);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_ITEM2", iActivityIndex: 660);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_ITEM2", iActivityIndex: 661);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_ITEM2", iActivityIndex: 662);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_ITEM2", iActivityIndex: 663);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_ITEM2", iActivityIndex: 664);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_ITEM2", iActivityIndex: 665);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_ITEM2", iActivityIndex: 666);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_ITEM2", iActivityIndex: 667);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_ITEM2", iActivityIndex: 668);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_ITEM2", iActivityIndex: 669);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_ITEM2", iActivityIndex: 670);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_ITEM2_SECONDARY", iActivityIndex: 671);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_ITEM2", iActivityIndex: 672);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_ITEM2_SECONDARY", iActivityIndex: 673);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_ITEM2", iActivityIndex: 674);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_ITEM2", iActivityIndex: 675);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH", iActivityIndex: 676);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_PRIMARY", iActivityIndex: 677);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_SECONDARY", iActivityIndex: 678);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_MELEE", iActivityIndex: 679);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_ITEM1", iActivityIndex: 680);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_ITEM2", iActivityIndex: 681);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_HEAD", iActivityIndex: 682);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_CHEST", iActivityIndex: 683);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_STOMACH", iActivityIndex: 684);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_LEFTARM", iActivityIndex: 685);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_RIGHTARM", iActivityIndex: 686);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_LEFTLEG", iActivityIndex: 687);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_RIGHTLEG", iActivityIndex: 688);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GRENADE1_DRAW", iActivityIndex: 689);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GRENADE1_IDLE", iActivityIndex: 690);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GRENADE1_ATTACK", iActivityIndex: 691);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GRENADE2_DRAW", iActivityIndex: 692);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GRENADE2_IDLE", iActivityIndex: 693);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GRENADE2_ATTACK", iActivityIndex: 694);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_PRIMARY_GRENADE1_DRAW", iActivityIndex: 695);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_PRIMARY_GRENADE1_IDLE", iActivityIndex: 696);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_PRIMARY_GRENADE1_ATTACK", iActivityIndex: 697);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_PRIMARY_GRENADE2_DRAW", iActivityIndex: 698);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_PRIMARY_GRENADE2_IDLE", iActivityIndex: 699);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_PRIMARY_GRENADE2_ATTACK", iActivityIndex: 700);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SECONDARY_GRENADE1_DRAW", iActivityIndex: 701);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SECONDARY_GRENADE1_IDLE", iActivityIndex: 702);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SECONDARY_GRENADE1_ATTACK", iActivityIndex: 703);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SECONDARY_GRENADE2_DRAW", iActivityIndex: 704);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SECONDARY_GRENADE2_IDLE", iActivityIndex: 705);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SECONDARY_GRENADE2_ATTACK", iActivityIndex: 706);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_MELEE_GRENADE1_DRAW", iActivityIndex: 707);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_MELEE_GRENADE1_IDLE", iActivityIndex: 708);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_MELEE_GRENADE1_ATTACK", iActivityIndex: 709);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_MELEE_GRENADE2_DRAW", iActivityIndex: 710);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_MELEE_GRENADE2_IDLE", iActivityIndex: 711);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_MELEE_GRENADE2_ATTACK", iActivityIndex: 712);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM1_GRENADE1_DRAW", iActivityIndex: 713);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM1_GRENADE1_IDLE", iActivityIndex: 714);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM1_GRENADE1_ATTACK", iActivityIndex: 715);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM1_GRENADE2_DRAW", iActivityIndex: 716);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM1_GRENADE2_IDLE", iActivityIndex: 717);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM1_GRENADE2_ATTACK", iActivityIndex: 718);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM2_GRENADE1_DRAW", iActivityIndex: 719);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM2_GRENADE1_IDLE", iActivityIndex: 720);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM2_GRENADE1_ATTACK", iActivityIndex: 721);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM2_GRENADE2_DRAW", iActivityIndex: 722);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM2_GRENADE2_IDLE", iActivityIndex: 723);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM2_GRENADE2_ATTACK", iActivityIndex: 724);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_BUILDING", iActivityIndex: 725);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_BUILDING", iActivityIndex: 726);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_BUILDING", iActivityIndex: 727);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_BUILDING", iActivityIndex: 728);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_BUILDING", iActivityIndex: 729);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_BUILDING", iActivityIndex: 730);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_BUILDING", iActivityIndex: 731);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_BUILDING", iActivityIndex: 732);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_BUILDING", iActivityIndex: 733);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_BUILDING", iActivityIndex: 734);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_BUILDING", iActivityIndex: 735);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_BUILDING", iActivityIndex: 736);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_BUILDING", iActivityIndex: 737);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_BUILDING", iActivityIndex: 738);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_BUILDING", iActivityIndex: 739);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_GRENADE_BUILDING", iActivityIndex: 740);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_GRENADE_BUILDING", iActivityIndex: 741);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_GRENADE_BUILDING", iActivityIndex: 742);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_GRENADE_BUILDING", iActivityIndex: 743);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_PDA", iActivityIndex: 744);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_PDA", iActivityIndex: 745);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_PDA", iActivityIndex: 746);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_PDA", iActivityIndex: 747);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_PDA", iActivityIndex: 748);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_PDA", iActivityIndex: 749);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_PDA", iActivityIndex: 750);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_PDA", iActivityIndex: 751);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_PDA", iActivityIndex: 752);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_PDA", iActivityIndex: 753);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_PDA", iActivityIndex: 754);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_PDA", iActivityIndex: 755);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_PDA", iActivityIndex: 756);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH", iActivityIndex: 757);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT", iActivityIndex: 758);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP", iActivityIndex: 759);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP", iActivityIndex: 760);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES", iActivityIndex: 761);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO", iActivityIndex: 762);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_PRIMARY", iActivityIndex: 763);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_PRIMARY", iActivityIndex: 764);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_PRIMARY", iActivityIndex: 765);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_PRIMARY", iActivityIndex: 766);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_PRIMARY", iActivityIndex: 767);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_PRIMARY", iActivityIndex: 768);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_SECONDARY", iActivityIndex: 769);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_SECONDARY", iActivityIndex: 770);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_SECONDARY", iActivityIndex: 771);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_SECONDARY", iActivityIndex: 772);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_SECONDARY", iActivityIndex: 773);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_SECONDARY", iActivityIndex: 774);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_MELEE", iActivityIndex: 775);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_MELEE", iActivityIndex: 776);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_MELEE", iActivityIndex: 777);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_MELEE", iActivityIndex: 778);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_MELEE", iActivityIndex: 779);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_MELEE", iActivityIndex: 780);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_ITEM1", iActivityIndex: 781);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_ITEM1", iActivityIndex: 782);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_ITEM1", iActivityIndex: 783);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_ITEM1", iActivityIndex: 784);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_ITEM1", iActivityIndex: 785);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_ITEM1", iActivityIndex: 786);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_ITEM2", iActivityIndex: 787);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_ITEM2", iActivityIndex: 788);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_ITEM2", iActivityIndex: 789);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_ITEM2", iActivityIndex: 790);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_ITEM2", iActivityIndex: 791);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_ITEM2", iActivityIndex: 792);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_BUILDING", iActivityIndex: 793);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_BUILDING", iActivityIndex: 794);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_BUILDING", iActivityIndex: 795);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_BUILDING", iActivityIndex: 796);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_BUILDING", iActivityIndex: 797);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_BUILDING", iActivityIndex: 798);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_PDA", iActivityIndex: 799);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_PDA", iActivityIndex: 800);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_PDA", iActivityIndex: 801);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_PDA", iActivityIndex: 802);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_PDA", iActivityIndex: 803);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_PDA", iActivityIndex: 804);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_UNUSABLE", iActivityIndex: 805);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_UNUSABLE_TO_USABLE", iActivityIndex: 806);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_USABLE_TO_UNUSABLE", iActivityIndex: 807);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_DRAW", iActivityIndex: 808);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_HOLSTER", iActivityIndex: 809);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_IDLE", iActivityIndex: 810);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_PULLBACK", iActivityIndex: 811);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_PRIMARYATTACK", iActivityIndex: 812);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_SECONDARYATTACK", iActivityIndex: 813);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_RELOAD", iActivityIndex: 814);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_DRYFIRE", iActivityIndex: 815);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_IDLE_TO_LOWERED", iActivityIndex: 816);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_IDLE_LOWERED", iActivityIndex: 817);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_LOWERED_TO_IDLE", iActivityIndex: 818);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_DRAW", iActivityIndex: 819);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_HOLSTER", iActivityIndex: 820);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_IDLE", iActivityIndex: 821);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_PULLBACK", iActivityIndex: 822);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_PRIMARYATTACK", iActivityIndex: 823);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_SECONDARYATTACK", iActivityIndex: 824);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_RELOAD", iActivityIndex: 825);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_DRYFIRE", iActivityIndex: 826);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_IDLE_TO_LOWERED", iActivityIndex: 827);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_IDLE_LOWERED", iActivityIndex: 828);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_LOWERED_TO_IDLE", iActivityIndex: 829);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_DRAW", iActivityIndex: 830);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_HOLSTER", iActivityIndex: 831);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_IDLE", iActivityIndex: 832);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_PULLBACK", iActivityIndex: 833);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_PRIMARYATTACK", iActivityIndex: 834);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_SECONDARYATTACK", iActivityIndex: 835);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_RELOAD", iActivityIndex: 836);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_DRYFIRE", iActivityIndex: 837);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_IDLE_TO_LOWERED", iActivityIndex: 838);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_IDLE_LOWERED", iActivityIndex: 839);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_LOWERED_TO_IDLE", iActivityIndex: 840);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_DRAW", iActivityIndex: 841);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_HOLSTER", iActivityIndex: 842);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_IDLE", iActivityIndex: 843);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_PULLBACK", iActivityIndex: 844);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_PRIMARYATTACK", iActivityIndex: 845);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_SECONDARYATTACK", iActivityIndex: 846);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_RELOAD", iActivityIndex: 847);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_DRYFIRE", iActivityIndex: 848);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_IDLE_TO_LOWERED", iActivityIndex: 849);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_IDLE_LOWERED", iActivityIndex: 850);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_LOWERED_TO_IDLE", iActivityIndex: 851);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_DRAW", iActivityIndex: 852);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_HOLSTER", iActivityIndex: 853);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_IDLE", iActivityIndex: 854);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_PULLBACK", iActivityIndex: 855);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_PRIMARYATTACK", iActivityIndex: 856);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_SECONDARYATTACK", iActivityIndex: 857);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_RELOAD", iActivityIndex: 858);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_DRYFIRE", iActivityIndex: 859);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_IDLE_TO_LOWERED", iActivityIndex: 860);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_IDLE_LOWERED", iActivityIndex: 861);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_LOWERED_TO_IDLE", iActivityIndex: 862);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_DRAW", iActivityIndex: 863);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_HOLSTER", iActivityIndex: 864);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_IDLE", iActivityIndex: 865);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_PULLBACK", iActivityIndex: 866);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_PRIMARYATTACK", iActivityIndex: 867);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_SECONDARYATTACK", iActivityIndex: 868);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_RELOAD", iActivityIndex: 869);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_DRYFIRE", iActivityIndex: 870);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_IDLE_TO_LOWERED", iActivityIndex: 871);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_IDLE_LOWERED", iActivityIndex: 872);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_LOWERED_TO_IDLE", iActivityIndex: 873);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_SUCCEED", iActivityIndex: 874);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_FAIL", iActivityIndex: 875);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_AUTOGUN", iActivityIndex: 876);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_AUTOGUN", iActivityIndex: 877);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AUTOGUN", iActivityIndex: 878);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_AUTOGUN", iActivityIndex: 879);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_AUTOGUN", iActivityIndex: 880);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCH_IDLE_AUTOGUN", iActivityIndex: 881);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_AUTOGUN", iActivityIndex: 882);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_JUMP_AUTOGUN", iActivityIndex: 883);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_PISTOL", iActivityIndex: 884);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_DUAL", iActivityIndex: 885);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_DUAL", iActivityIndex: 886);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_DUAL", iActivityIndex: 887);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_DUAL", iActivityIndex: 888);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_DUAL", iActivityIndex: 889);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCH_IDLE_DUAL", iActivityIndex: 890);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_DUAL", iActivityIndex: 891);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_JUMP_DUAL", iActivityIndex: 892);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SHOTGUN", iActivityIndex: 893);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_SHOTGUN", iActivityIndex: 894);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCH_IDLE_SHOTGUN", iActivityIndex: 895);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_JUMP_SHOTGUN", iActivityIndex: 896);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_RIFLE", iActivityIndex: 897);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_RIFLE", iActivityIndex: 898);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCH_IDLE_RIFLE", iActivityIndex: 899);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_RIFLE", iActivityIndex: 900);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_JUMP_RIFLE", iActivityIndex: 901);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLEEP", iActivityIndex: 902);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WAKE", iActivityIndex: 903);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLICK_LEFT", iActivityIndex: 904);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLICK_LEFT_MIDDLE", iActivityIndex: 905);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLICK_RIGHT_MIDDLE", iActivityIndex: 906);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLICK_RIGHT", iActivityIndex: 907);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SPINAROUND", iActivityIndex: 908);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PREP_TO_FIRE", iActivityIndex: 909);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FIRE", iActivityIndex: 910);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FIRE_RECOVER", iActivityIndex: 911);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SPRAY", iActivityIndex: 912);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PREP_EXPLODE", iActivityIndex: 913);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_EXPLODE", iActivityIndex: 914);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_IDLE", iActivityIndex: 915);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_RUN", iActivityIndex: 916);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_ATTACK", iActivityIndex: 917);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_ATTACK_EVENT", iActivityIndex: 918);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_DIE", iActivityIndex: 919);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_FLINCH", iActivityIndex: 920);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_DISABLED", iActivityIndex: 921);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CAST_ABILITY_1", iActivityIndex: 922);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CAST_ABILITY_2", iActivityIndex: 923);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CAST_ABILITY_3", iActivityIndex: 924);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CAST_ABILITY_4", iActivityIndex: 925);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_OVERRIDE_ABILITY_1", iActivityIndex: 926);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_OVERRIDE_ABILITY_2", iActivityIndex: 927);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_OVERRIDE_ABILITY_3", iActivityIndex: 928);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_OVERRIDE_ABILITY_4", iActivityIndex: 929);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_ABILITY_1", iActivityIndex: 930);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_ABILITY_2", iActivityIndex: 931);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_ABILITY_3", iActivityIndex: 932);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_ABILITY_4", iActivityIndex: 933);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_END_ABILITY_1", iActivityIndex: 934);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_END_ABILITY_2", iActivityIndex: 935);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_END_ABILITY_3", iActivityIndex: 936);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_END_ABILITY_4", iActivityIndex: 937);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_SPEEDPAINT", iActivityIndex: 938);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_LONG_FALL", iActivityIndex: 939);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_TRACTORBEAM_FLOAT", iActivityIndex: 940);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DEATH_CRUSH", iActivityIndex: 941);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_SPEEDPAINT_PRIMARY", iActivityIndex: 942);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DROWNING_PRIMARY", iActivityIndex: 943);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_LONG_FALL_PRIMARY", iActivityIndex: 944);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_TRACTORBEAM_FLOAT_PRIMARY", iActivityIndex: 945);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DEATH_CRUSH_PRIMARY", iActivityIndex: 946);
}

//------------------------------------------------------------------------------
// Address: 0x100085A0
// Name: void ActivityList_Free(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ActivityList_Free()
{
  activitylist_t *m_pMemory; // eax

  CStringRegistry::ClearStrings(this: &g_ActivityStrings);
  m_pMemory = g_ActivityList.m_Memory.m_pMemory;
  g_ActivityList.m_Size = 0;
  if ( g_ActivityList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ActivityList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ActivityList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_ActivityList.m_Memory.m_pMemory = nullptr;
    }
    g_ActivityList.m_Memory.m_nAllocationCount = 0;
  }
  g_ActivityList.m_pElements = m_pMemory;
  CUtlDict<CActivityRemapCache,int>::RemoveAll(this: &m_ActivityRemapDatabase);
  ++g_nActivityListVersion;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10001BB0
// Name: void ActivityList_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ActivityList_Init()
{
  g_HighestActivity = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001BC0
// Name: class ISaveRestoreOps __near * ActivityDataOps(void)
// Source: json
//------------------------------------------------------------------------------
CActivityDataOps *__cdecl ActivityDataOps()
{
  return &g_ActivityDataOps;
}

//------------------------------------------------------------------------------
// Address: 0x10001BD0
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001C20
// Name: bool StringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StringLessThan(const char **lhs, const char **rhs)
{
  int v3; // kr00_4

  if ( *lhs == nullptr )
    return false;
  if ( *rhs == nullptr )
    return true;
  v3 = strcmp(*lhs, *rhs);
  return v3 != 0 && -(v3 < 0) - ((v3 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001C80
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10001CB0
// Name: int ActivityList_IndexForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ActivityList_IndexForName(const char *pszActivityName)
{
  int StringID; // eax
  activitylist_t *v2; // eax

  StringID = CStringRegistry::GetStringID(this: &g_ActivityStrings, stringText: pszActivityName);
  if ( StringID >= 0 && (v2 = &g_ActivityList.m_Memory.m_pMemory[StringID]) != nullptr )
    return v2->activityIndex;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001CE0
// Name: char const __near * ActivityList_NameForIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ActivityList_NameForIndex(int activityIndex)
{
  int v1; // eax
  activitylist_t *v3; // eax

  v1 = 0;
  if ( g_ActivityList.m_Size <= 0 )
    return nullptr;
  while ( g_ActivityList.m_Memory.m_pMemory[v1].activityIndex != activityIndex )
  {
    if ( ++v1 >= g_ActivityList.m_Size )
      return nullptr;
  }
  v3 = &g_ActivityList.m_Memory.m_pMemory[v1];
  if ( v3 != nullptr )
    return CStringRegistry::GetStringForKey(this: &g_ActivityStrings, key: v3->stringKey);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001D30
// Name: public: virtual void CActivityDataOps::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CActivityDataOps::MakeEmpty(CActivityDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  *(_DWORD *)fieldInfo->pField = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001D50
// Name: public: virtual void CActivityDataOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CActivityDataOps::Save(CActivityDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo, ISave *pSave)
{
  int m_Size; // edx
  activitylist_t *m_pMemory; // ecx
  int v5; // eax
  activitylist_t *v6; // eax
  const char *StringForKey; // edi
  int v8; // eax
  ISave *v9; // esi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  activitylist_t *v11; // eax

  m_Size = g_ActivityList.m_Size;
  m_pMemory = g_ActivityList.m_Memory.m_pMemory;
  v5 = 0;
  if ( g_ActivityList.m_Size > 0 )
  {
    while ( g_ActivityList.m_Memory.m_pMemory[v5].activityIndex != *(_DWORD *)fieldInfo->pField )
    {
      if ( ++v5 >= g_ActivityList.m_Size )
        goto LABEL_8;
    }
    v6 = &g_ActivityList.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      StringForKey = CStringRegistry::GetStringForKey(this: &g_ActivityStrings, key: v6->stringKey);
      if ( StringForKey != nullptr )
        goto LABEL_12;
      m_Size = g_ActivityList.m_Size;
      m_pMemory = g_ActivityList.m_Memory.m_pMemory;
    }
  }
LABEL_8:
  v8 = 0;
  if ( m_Size <= 0 )
    goto LABEL_11;
  while ( m_pMemory[v8].activityIndex != 0 )
  {
    if ( ++v8 >= m_Size )
      goto LABEL_11;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    StringForKey = CStringRegistry::GetStringForKey(this: &g_ActivityStrings, key: v11->stringKey);
  else
LABEL_11:
    StringForKey = nullptr;
LABEL_12:
  v9 = pSave;
  WriteInt_2 = pSave->WriteInt_2;
  fieldInfo = (const SaveRestoreFieldInfo_t *)((strlen(StringForKey) + 1) | 0x80800000);
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  v9->WriteString_4(this: v9, a2: StringForKey);
}

//------------------------------------------------------------------------------
// Address: 0x10001E10
// Name: public: virtual void CActivityDataOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CActivityDataOps::Restore(
        CActivityDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  _DWORD *pField; // edi
  int v4; // eax
  int StringID; // eax
  activitylist_t *v6; // eax
  int activityIndex; // eax
  char nameBuf[1024]; // [esp+8h] [ebp-400h] BYREF

  pField = fieldInfo->pField;
  v4 = pRestore->ReadInt(this: pRestore);
  if ( (v4 & 0xFFFF0000) == 0x80800000 )
  {
    pRestore->ReadString_2(this: pRestore, a2: nameBuf, a3: 1024, a4: (unsigned __int16)v4);
    StringID = CStringRegistry::GetStringID(this: &g_ActivityStrings, stringText: nameBuf);
    if ( StringID >= 0 && (v6 = &g_ActivityList.m_Memory.m_pMemory[StringID]) != nullptr )
      activityIndex = v6->activityIndex;
    else
      activityIndex = -1;
    *pField = activityIndex;
    if ( activityIndex < 0 )
      *pField = 0;
  }
  else
  {
    *pField = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002220
// Name: struct activitylist_t __near * ActivityList_AddActivityEntry(char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
activitylist_t *__cdecl ActivityList_AddActivityEntry(const char *pName, int iActivityIndex, bool isPrivate)
{
  int m_Size; // eax
  int v4; // esi
  activitylist_t *m_pMemory; // ecx
  int v6; // eax
  activitylist_t *v7; // edi
  activitylist_t *result; // eax

  m_Size = g_ActivityList.m_Size;
  v4 = g_ActivityList.m_Size;
  if ( g_ActivityList.m_Size + 1 > g_ActivityList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      this: (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)&g_ActivityList,
      num: g_ActivityList.m_Size - g_ActivityList.m_Memory.m_nAllocationCount + 1);
    m_Size = g_ActivityList.m_Size;
  }
  m_pMemory = g_ActivityList.m_Memory.m_pMemory;
  g_ActivityList.m_Size = m_Size + 1;
  v6 = m_Size - v4;
  g_ActivityList.m_pElements = g_ActivityList.m_Memory.m_pMemory;
  if ( v6 > 0 )
  {
    _V_memmove(
      dest: &g_ActivityList.m_Memory.m_pMemory[v4 + 1],
      src: &g_ActivityList.m_Memory.m_pMemory[v4],
      count: 8 * v6);
    m_pMemory = g_ActivityList.m_Memory.m_pMemory;
  }
  v7 = &m_pMemory[v4];
  v7->activityIndex = iActivityIndex;
  v7->stringKey = CStringRegistry::AddString(this: &g_ActivityStrings, stringText: pName, stringID: v4);
  v7->isPrivate = isPrivate;
  result = v7;
  if ( iActivityIndex > g_HighestActivity )
    g_HighestActivity = iActivityIndex;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100022C0
// Name: bool ActivityList_RegisterSharedActivity(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ActivityList_RegisterSharedActivity(const char *pszActivityName, int iActivityIndex)
{
  int StringID; // eax
  activitylist_t *v3; // eax
  int v4; // eax
  const char *StringForKey; // eax

  lastActivityIndex = iActivityIndex;
  StringID = CStringRegistry::GetStringID(this: &g_ActivityStrings, stringText: pszActivityName);
  if ( StringID >= 0 )
  {
    v3 = &g_ActivityList.m_Memory.m_pMemory[StringID];
    if ( v3 != nullptr )
      goto LABEL_8;
  }
  v4 = 0;
  if ( g_ActivityList.m_Size <= 0 )
    goto LABEL_6;
  while ( g_ActivityList.m_Memory.m_pMemory[v4].activityIndex != iActivityIndex )
  {
    if ( ++v4 >= g_ActivityList.m_Size )
      goto LABEL_6;
  }
  v3 = &g_ActivityList.m_Memory.m_pMemory[v4];
  if ( v3 != nullptr )
  {
LABEL_8:
    StringForKey = CStringRegistry::GetStringForKey(this: &g_ActivityStrings, key: v3->stringKey);
    _Warning(a1: "***\nShared activity collision! %s<->%s\n***\n", pszActivityName, StringForKey);
    return 0;
  }
  else
  {
LABEL_6:
    ActivityList_AddActivityEntry(pName: pszActivityName, iActivityIndex, isPrivate: false);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002350
// Name: enum Activity ActivityList_RegisterPrivateActivity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ActivityList_RegisterPrivateActivity(const char *pszActivityName)
{
  int StringID; // eax
  activitylist_t *v2; // eax

  StringID = CStringRegistry::GetStringID(this: &g_ActivityStrings, stringText: pszActivityName);
  if ( StringID >= 0 && (v2 = &g_ActivityList.m_Memory.m_pMemory[StringID]) != nullptr )
  {
    if ( v2->isPrivate == 0 )
    {
      _Warning(a1: "***\nShared<->Private Activity collision!\n***\n");
      return -1;
    }
  }
  else
  {
    v2 = ActivityList_AddActivityEntry(pName: pszActivityName, iActivityIndex: g_HighestActivity + 1, isPrivate: true);
  }
  return v2->activityIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100023B0
// Name: void ActivityList_RegisterSharedActivities(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ActivityList_RegisterSharedActivities()
{
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RESET", iActivityIndex: 0);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE", iActivityIndex: 1);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_TRANSITION", iActivityIndex: 2);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COVER", iActivityIndex: 3);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COVER_MED", iActivityIndex: 4);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COVER_LOW", iActivityIndex: 5);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK", iActivityIndex: 6);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM", iActivityIndex: 7);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_CROUCH", iActivityIndex: 8);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_CROUCH_AIM", iActivityIndex: 9);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN", iActivityIndex: 10);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM", iActivityIndex: 11);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_CROUCH", iActivityIndex: 12);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_CROUCH_AIM", iActivityIndex: 13);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_PROTECTED", iActivityIndex: 14);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SCRIPT_CUSTOM_MOVE", iActivityIndex: 15);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK1", iActivityIndex: 16);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK2", iActivityIndex: 17);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK1_LOW", iActivityIndex: 18);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK2_LOW", iActivityIndex: 19);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIESIMPLE", iActivityIndex: 20);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIEBACKWARD", iActivityIndex: 21);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIEFORWARD", iActivityIndex: 22);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIEVIOLENT", iActivityIndex: 23);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIERAGDOLL", iActivityIndex: 24);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLY", iActivityIndex: 25);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HOVER", iActivityIndex: 26);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GLIDE", iActivityIndex: 27);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SWIM", iActivityIndex: 28);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_JUMP", iActivityIndex: 29);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HOP", iActivityIndex: 30);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_LEAP", iActivityIndex: 31);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_LAND", iActivityIndex: 32);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CLIMB_UP", iActivityIndex: 33);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CLIMB_DOWN", iActivityIndex: 34);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CLIMB_DISMOUNT", iActivityIndex: 35);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIPLADDER_UP", iActivityIndex: 36);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIPLADDER_DOWN", iActivityIndex: 37);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STRAFE_LEFT", iActivityIndex: 38);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STRAFE_RIGHT", iActivityIndex: 39);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ROLL_LEFT", iActivityIndex: 40);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ROLL_RIGHT", iActivityIndex: 41);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_TURN_LEFT", iActivityIndex: 42);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_TURN_RIGHT", iActivityIndex: 43);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCH", iActivityIndex: 44);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHIDLE", iActivityIndex: 45);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STAND", iActivityIndex: 46);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_USE", iActivityIndex: 47);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ALIEN_BURROW_IDLE", iActivityIndex: 48);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ALIEN_BURROW_OUT", iActivityIndex: 49);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL1", iActivityIndex: 50);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL2", iActivityIndex: 51);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL3", iActivityIndex: 52);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_ADVANCE", iActivityIndex: 53);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_FORWARD", iActivityIndex: 54);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_GROUP", iActivityIndex: 55);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_HALT", iActivityIndex: 56);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_LEFT", iActivityIndex: 57);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_RIGHT", iActivityIndex: 58);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SIGNAL_TAKECOVER", iActivityIndex: 59);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_LOOKBACK_RIGHT", iActivityIndex: 60);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_LOOKBACK_LEFT", iActivityIndex: 61);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COWER", iActivityIndex: 62);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMALL_FLINCH", iActivityIndex: 63);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BIG_FLINCH", iActivityIndex: 64);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_ATTACK1", iActivityIndex: 65);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_ATTACK2", iActivityIndex: 66);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD", iActivityIndex: 67);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_START", iActivityIndex: 68);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_FINISH", iActivityIndex: 69);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_LOW", iActivityIndex: 70);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ARM", iActivityIndex: 71);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DISARM", iActivityIndex: 72);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DROP_WEAPON", iActivityIndex: 73);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DROP_WEAPON_SHOTGUN", iActivityIndex: 74);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PICKUP_GROUND", iActivityIndex: 75);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PICKUP_RACK", iActivityIndex: 76);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ANGRY", iActivityIndex: 77);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_RELAXED", iActivityIndex: 78);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_STIMULATED", iActivityIndex: 79);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AGITATED", iActivityIndex: 80);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_STEALTH", iActivityIndex: 81);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_HURT", iActivityIndex: 82);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_RELAXED", iActivityIndex: 83);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_STIMULATED", iActivityIndex: 84);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AGITATED", iActivityIndex: 85);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_STEALTH", iActivityIndex: 86);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_RELAXED", iActivityIndex: 87);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_STIMULATED", iActivityIndex: 88);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AGITATED", iActivityIndex: 89);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_STEALTH", iActivityIndex: 90);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_RELAXED", iActivityIndex: 91);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_STIMULATED", iActivityIndex: 92);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_AGITATED", iActivityIndex: 93);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_STEALTH", iActivityIndex: 94);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_RELAXED", iActivityIndex: 95);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_STIMULATED", iActivityIndex: 96);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_AGITATED", iActivityIndex: 97);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_STEALTH", iActivityIndex: 98);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_RELAXED", iActivityIndex: 99);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_STIMULATED", iActivityIndex: 100);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_AGITATED", iActivityIndex: 101);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_STEALTH", iActivityIndex: 102);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHIDLE_STIMULATED", iActivityIndex: 103);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHIDLE_AIM_STIMULATED", iActivityIndex: 104);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHIDLE_AGITATED", iActivityIndex: 105);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_HURT", iActivityIndex: 106);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_HURT", iActivityIndex: 107);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SPECIAL_ATTACK1", iActivityIndex: 108);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SPECIAL_ATTACK2", iActivityIndex: 109);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COMBAT_IDLE", iActivityIndex: 110);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_SCARED", iActivityIndex: 111);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_SCARED", iActivityIndex: 112);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VICTORY_DANCE", iActivityIndex: 113);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_HEADSHOT", iActivityIndex: 114);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_CHESTSHOT", iActivityIndex: 115);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_GUTSHOT", iActivityIndex: 116);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_BACKSHOT", iActivityIndex: 117);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_HEAD", iActivityIndex: 118);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_CHEST", iActivityIndex: 119);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_STOMACH", iActivityIndex: 120);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_LEFTARM", iActivityIndex: 121);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_RIGHTARM", iActivityIndex: 122);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_LEFTLEG", iActivityIndex: 123);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_RIGHTLEG", iActivityIndex: 124);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_PHYSICS", iActivityIndex: 125);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_HEAD_BACK", iActivityIndex: 126);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_CHEST_BACK", iActivityIndex: 127);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_STOMACH_BACK", iActivityIndex: 128);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_CROUCH_FRONT", iActivityIndex: 129);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_CROUCH_BACK", iActivityIndex: 130);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_CROUCH_LEFT", iActivityIndex: 131);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLINCH_CROUCH_RIGHT", iActivityIndex: 132);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ON_FIRE", iActivityIndex: 133);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_ON_FIRE", iActivityIndex: 134);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_ON_FIRE", iActivityIndex: 135);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RAPPEL_LOOP", iActivityIndex: 136);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_180_LEFT", iActivityIndex: 137);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_180_RIGHT", iActivityIndex: 138);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_90_LEFT", iActivityIndex: 139);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_90_RIGHT", iActivityIndex: 140);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STEP_LEFT", iActivityIndex: 141);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STEP_RIGHT", iActivityIndex: 142);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STEP_BACK", iActivityIndex: 143);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STEP_FORE", iActivityIndex: 144);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK1", iActivityIndex: 145);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK2", iActivityIndex: 146);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_MELEE_ATTACK1", iActivityIndex: 147);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_MELEE_ATTACK2", iActivityIndex: 148);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK1_LOW", iActivityIndex: 149);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK2_LOW", iActivityIndex: 150);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_ATTACK_SWING_GESTURE", iActivityIndex: 151);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_SMALL_FLINCH", iActivityIndex: 152);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_BIG_FLINCH", iActivityIndex: 153);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_BLAST", iActivityIndex: 154);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_BLAST_SHOTGUN", iActivityIndex: 155);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_BLAST_DAMAGED", iActivityIndex: 156);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_BLAST_DAMAGED_SHOTGUN", iActivityIndex: 157);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_HEAD", iActivityIndex: 158);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_CHEST", iActivityIndex: 159);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_STOMACH", iActivityIndex: 160);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_LEFTARM", iActivityIndex: 161);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_RIGHTARM", iActivityIndex: 162);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_LEFTLEG", iActivityIndex: 163);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_FLINCH_RIGHTLEG", iActivityIndex: 164);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_LEFT", iActivityIndex: 165);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_RIGHT", iActivityIndex: 166);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_LEFT45", iActivityIndex: 167);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_RIGHT45", iActivityIndex: 168);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_LEFT90", iActivityIndex: 169);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_RIGHT90", iActivityIndex: 170);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_LEFT45_FLAT", iActivityIndex: 171);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_RIGHT45_FLAT", iActivityIndex: 172);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_LEFT90_FLAT", iActivityIndex: 173);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_TURN_RIGHT90_FLAT", iActivityIndex: 174);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BARNACLE_HIT", iActivityIndex: 175);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BARNACLE_PULL", iActivityIndex: 176);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BARNACLE_CHOMP", iActivityIndex: 177);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BARNACLE_CHEW", iActivityIndex: 178);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DO_NOT_DISTURB", iActivityIndex: 179);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SPECIFIC_SEQUENCE", iActivityIndex: 180);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DRAW", iActivityIndex: 181);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HOLSTER", iActivityIndex: 182);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IDLE", iActivityIndex: 183);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_FIDGET", iActivityIndex: 184);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PULLBACK", iActivityIndex: 185);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PULLBACK_HIGH", iActivityIndex: 186);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PULLBACK_LOW", iActivityIndex: 187);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_THROW", iActivityIndex: 188);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PULLPIN", iActivityIndex: 189);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PRIMARYATTACK", iActivityIndex: 190);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SECONDARYATTACK", iActivityIndex: 191);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_RELOAD", iActivityIndex: 192);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DRYFIRE", iActivityIndex: 193);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HITLEFT", iActivityIndex: 194);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HITLEFT2", iActivityIndex: 195);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HITRIGHT", iActivityIndex: 196);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HITRIGHT2", iActivityIndex: 197);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HITCENTER", iActivityIndex: 198);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HITCENTER2", iActivityIndex: 199);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_MISSLEFT", iActivityIndex: 200);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_MISSLEFT2", iActivityIndex: 201);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_MISSRIGHT", iActivityIndex: 202);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_MISSRIGHT2", iActivityIndex: 203);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_MISSCENTER", iActivityIndex: 204);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_MISSCENTER2", iActivityIndex: 205);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_HAULBACK", iActivityIndex: 206);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SWINGHARD", iActivityIndex: 207);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SWINGMISS", iActivityIndex: 208);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SWINGHIT", iActivityIndex: 209);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IDLE_TO_LOWERED", iActivityIndex: 210);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IDLE_LOWERED", iActivityIndex: 211);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_LOWERED_TO_IDLE", iActivityIndex: 212);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_RECOIL1", iActivityIndex: 213);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_RECOIL2", iActivityIndex: 214);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_RECOIL3", iActivityIndex: 215);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PICKUP", iActivityIndex: 216);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_RELEASE", iActivityIndex: 217);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_ATTACH_SILENCER", iActivityIndex: 218);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DETACH_SILENCER", iActivityIndex: 219);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_IDLE", iActivityIndex: 220);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_ND_IDLE", iActivityIndex: 221);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_ATTACH", iActivityIndex: 222);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_ATTACH2", iActivityIndex: 223);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_ND_ATTACH", iActivityIndex: 224);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_ND_ATTACH2", iActivityIndex: 225);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_DETONATE", iActivityIndex: 226);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_DETONATOR_HOLSTER", iActivityIndex: 227);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_DRAW", iActivityIndex: 228);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_ND_DRAW", iActivityIndex: 229);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_TO_THROW", iActivityIndex: 230);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_TO_THROW_ND", iActivityIndex: 231);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_STICKWALL_TO_TRIPMINE_ND", iActivityIndex: 232);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_IDLE", iActivityIndex: 233);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_ND_IDLE", iActivityIndex: 234);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_THROW", iActivityIndex: 235);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_THROW2", iActivityIndex: 236);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_THROW_ND", iActivityIndex: 237);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_THROW_ND2", iActivityIndex: 238);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_DRAW", iActivityIndex: 239);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_ND_DRAW", iActivityIndex: 240);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_TO_STICKWALL", iActivityIndex: 241);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_TO_STICKWALL_ND", iActivityIndex: 242);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_DETONATE", iActivityIndex: 243);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_DETONATOR_HOLSTER", iActivityIndex: 244);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_THROW_TO_TRIPMINE_ND", iActivityIndex: 245);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_TRIPMINE_IDLE", iActivityIndex: 246);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_TRIPMINE_DRAW", iActivityIndex: 247);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_TRIPMINE_ATTACH", iActivityIndex: 248);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_TRIPMINE_ATTACH2", iActivityIndex: 249);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_TRIPMINE_TO_STICKWALL_ND", iActivityIndex: 250);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_TRIPMINE_TO_THROW_ND", iActivityIndex: 251);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_DETONATOR_IDLE", iActivityIndex: 252);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_DETONATOR_DRAW", iActivityIndex: 253);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_DETONATOR_DETONATE", iActivityIndex: 254);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_DETONATOR_HOLSTER", iActivityIndex: 255);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_DETONATOR_STICKWALL_DRAW", iActivityIndex: 256);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLAM_DETONATOR_THROW_DRAW", iActivityIndex: 257);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHOTGUN_RELOAD_START", iActivityIndex: 258);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHOTGUN_RELOAD_FINISH", iActivityIndex: 259);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHOTGUN_PUMP", iActivityIndex: 260);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_IDLE2", iActivityIndex: 261);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_FIRE2", iActivityIndex: 262);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_DRAW2", iActivityIndex: 263);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_RELOAD2", iActivityIndex: 264);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_DRYFIRE2", iActivityIndex: 265);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_TOAUTO", iActivityIndex: 266);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SMG2_TOBURST", iActivityIndex: 267);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PHYSCANNON_UPGRADE", iActivityIndex: 268);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_AR1", iActivityIndex: 269);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_AR2", iActivityIndex: 270);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_AR2_LOW", iActivityIndex: 271);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_AR2_GRENADE", iActivityIndex: 272);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_HMG1", iActivityIndex: 273);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_ML", iActivityIndex: 274);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SMG1", iActivityIndex: 275);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SMG1_LOW", iActivityIndex: 276);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SMG2", iActivityIndex: 277);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SHOTGUN", iActivityIndex: 278);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SHOTGUN_LOW", iActivityIndex: 279);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_PISTOL", iActivityIndex: 280);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_PISTOL_LOW", iActivityIndex: 281);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SLAM", iActivityIndex: 282);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_TRIPWIRE", iActivityIndex: 283);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_THROW", iActivityIndex: 284);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_SNIPER_RIFLE", iActivityIndex: 285);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_RPG", iActivityIndex: 286);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_ATTACK_SWING", iActivityIndex: 287);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_AIM_LOW", iActivityIndex: 288);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_AIM_SMG1_LOW", iActivityIndex: 289);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_AIM_PISTOL_LOW", iActivityIndex: 290);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_AIM_AR2_LOW", iActivityIndex: 291);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COVER_PISTOL_LOW", iActivityIndex: 292);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COVER_SMG1_LOW", iActivityIndex: 293);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_AR1", iActivityIndex: 294);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_AR2", iActivityIndex: 295);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_AR2_GRENADE", iActivityIndex: 296);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_HMG1", iActivityIndex: 297);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_ML", iActivityIndex: 298);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_SMG1", iActivityIndex: 299);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_SMG1_LOW", iActivityIndex: 300);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_SMG2", iActivityIndex: 301);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_SHOTGUN", iActivityIndex: 302);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_PISTOL", iActivityIndex: 303);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_PISTOL_LOW", iActivityIndex: 304);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_SLAM", iActivityIndex: 305);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_TRIPWIRE", iActivityIndex: 306);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_THROW", iActivityIndex: 307);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RANGE_ATTACK_SNIPER_RIFLE", iActivityIndex: 308);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_MELEE_ATTACK_SWING", iActivityIndex: 309);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_RIFLE", iActivityIndex: 310);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SMG1", iActivityIndex: 311);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ANGRY_SMG1", iActivityIndex: 312);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_PISTOL", iActivityIndex: 313);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ANGRY_PISTOL", iActivityIndex: 314);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ANGRY_SHOTGUN", iActivityIndex: 315);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_STEALTH_PISTOL", iActivityIndex: 316);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_PACKAGE", iActivityIndex: 317);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_PACKAGE", iActivityIndex: 318);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SUITCASE", iActivityIndex: 319);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_SUITCASE", iActivityIndex: 320);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SMG1_RELAXED", iActivityIndex: 321);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SMG1_STIMULATED", iActivityIndex: 322);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_RIFLE_RELAXED", iActivityIndex: 323);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_RIFLE_RELAXED", iActivityIndex: 324);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_RIFLE_STIMULATED", iActivityIndex: 325);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_RIFLE_STIMULATED", iActivityIndex: 326);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_RIFLE_STIMULATED", iActivityIndex: 327);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_RIFLE_STIMULATED", iActivityIndex: 328);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_RIFLE_STIMULATED", iActivityIndex: 329);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SHOTGUN_RELAXED", iActivityIndex: 330);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SHOTGUN_STIMULATED", iActivityIndex: 331);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SHOTGUN_AGITATED", iActivityIndex: 332);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_ANGRY", iActivityIndex: 333);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_POLICE_HARASS1", iActivityIndex: 334);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_POLICE_HARASS2", iActivityIndex: 335);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_MANNEDGUN", iActivityIndex: 336);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_MELEE", iActivityIndex: 337);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ANGRY_MELEE", iActivityIndex: 338);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_RPG_RELAXED", iActivityIndex: 339);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_RPG", iActivityIndex: 340);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_ANGRY_RPG", iActivityIndex: 341);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_COVER_LOW_RPG", iActivityIndex: 342);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_RPG", iActivityIndex: 343);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_RPG", iActivityIndex: 344);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_CROUCH_RPG", iActivityIndex: 345);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_CROUCH_RPG", iActivityIndex: 346);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_RPG_RELAXED", iActivityIndex: 347);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_RPG_RELAXED", iActivityIndex: 348);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_RIFLE", iActivityIndex: 349);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_RIFLE", iActivityIndex: 350);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_CROUCH_RIFLE", iActivityIndex: 351);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_CROUCH_AIM_RIFLE", iActivityIndex: 352);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_RIFLE", iActivityIndex: 353);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_RIFLE", iActivityIndex: 354);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_CROUCH_RIFLE", iActivityIndex: 355);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_CROUCH_AIM_RIFLE", iActivityIndex: 356);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_STEALTH_PISTOL", iActivityIndex: 357);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_SHOTGUN", iActivityIndex: 358);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_SHOTGUN", iActivityIndex: 359);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_PISTOL", iActivityIndex: 360);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_PISTOL", iActivityIndex: 361);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_PISTOL", iActivityIndex: 362);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_PISTOL", iActivityIndex: 363);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_STEALTH_PISTOL", iActivityIndex: 364);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_STEALTH_PISTOL", iActivityIndex: 365);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_STEALTH_PISTOL", iActivityIndex: 366);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_PISTOL", iActivityIndex: 367);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_PISTOL_LOW", iActivityIndex: 368);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_SMG1", iActivityIndex: 369);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_SMG1_LOW", iActivityIndex: 370);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_SHOTGUN", iActivityIndex: 371);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_SHOTGUN_LOW", iActivityIndex: 372);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RELOAD", iActivityIndex: 373);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RELOAD_PISTOL", iActivityIndex: 374);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RELOAD_SMG1", iActivityIndex: 375);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_RELOAD_SHOTGUN", iActivityIndex: 376);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_LEAN_LEFT", iActivityIndex: 377);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_LEAN_LEFT_ENTRY", iActivityIndex: 378);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_LEAN_LEFT_EXIT", iActivityIndex: 379);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_LEAN_BACK", iActivityIndex: 380);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_LEAN_BACK_ENTRY", iActivityIndex: 381);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_LEAN_BACK_EXIT", iActivityIndex: 382);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_SIT_GROUND", iActivityIndex: 383);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_SIT_GROUND_ENTRY", iActivityIndex: 384);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_SIT_GROUND_EXIT", iActivityIndex: 385);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_SIT_CHAIR", iActivityIndex: 386);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_SIT_CHAIR_ENTRY", iActivityIndex: 387);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_SIT_CHAIR_EXIT", iActivityIndex: 388);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_STAND", iActivityIndex: 389);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_BUSY_QUEUE", iActivityIndex: 390);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DUCK_DODGE", iActivityIndex: 391);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_BARNACLE_SWALLOW", iActivityIndex: 392);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GESTURE_BARNACLE_STRANGLE", iActivityIndex: 393);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PHYSCANNON_DETACH", iActivityIndex: 394);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PHYSCANNON_ANIMATE", iActivityIndex: 395);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PHYSCANNON_ANIMATE_PRE", iActivityIndex: 396);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PHYSCANNON_ANIMATE_POST", iActivityIndex: 397);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_FRONTSIDE", iActivityIndex: 398);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_RIGHTSIDE", iActivityIndex: 399);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_BACKSIDE", iActivityIndex: 400);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_LEFTSIDE", iActivityIndex: 401);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_CROUCH_FRONTSIDE", iActivityIndex: 402);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_CROUCH_RIGHTSIDE", iActivityIndex: 403);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_CROUCH_BACKSIDE", iActivityIndex: 404);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DIE_CROUCH_LEFTSIDE", iActivityIndex: 405);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OPEN_DOOR", iActivityIndex: 406);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DI_ALYX_ZOMBIE_MELEE", iActivityIndex: 407);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DI_ALYX_ZOMBIE_TORSO_MELEE", iActivityIndex: 408);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DI_ALYX_HEADCRAB_MELEE", iActivityIndex: 409);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DI_ALYX_ANTLION", iActivityIndex: 410);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DI_ALYX_ZOMBIE_SHOTGUN64", iActivityIndex: 411);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DI_ALYX_ZOMBIE_SHOTGUN26", iActivityIndex: 412);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_READINESS_RELAXED_TO_STIMULATED", iActivityIndex: 413);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_READINESS_RELAXED_TO_STIMULATED_WALK", iActivityIndex: 414);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_READINESS_AGITATED_TO_STIMULATED", iActivityIndex: 415);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_READINESS_STIMULATED_TO_RELAXED", iActivityIndex: 416);
  ActivityList_RegisterSharedActivity(
    pszActivityName: "ACT_READINESS_PISTOL_RELAXED_TO_STIMULATED",
    iActivityIndex: 417);
  ActivityList_RegisterSharedActivity(
    pszActivityName: "ACT_READINESS_PISTOL_RELAXED_TO_STIMULATED_WALK",
    iActivityIndex: 418);
  ActivityList_RegisterSharedActivity(
    pszActivityName: "ACT_READINESS_PISTOL_AGITATED_TO_STIMULATED",
    iActivityIndex: 419);
  ActivityList_RegisterSharedActivity(
    pszActivityName: "ACT_READINESS_PISTOL_STIMULATED_TO_RELAXED",
    iActivityIndex: 420);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_CARRY", iActivityIndex: 421);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_CARRY", iActivityIndex: 422);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_STARTDYING", iActivityIndex: 423);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DYINGLOOP", iActivityIndex: 424);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DYINGTODEAD", iActivityIndex: 425);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RIDE_MANNED_GUN", iActivityIndex: 426);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SPRINT_ENTER", iActivityIndex: 427);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SPRINT_IDLE", iActivityIndex: 428);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_SPRINT_LEAVE", iActivityIndex: 429);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FIRE_START", iActivityIndex: 430);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FIRE_LOOP", iActivityIndex: 431);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FIRE_END", iActivityIndex: 432);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_GRENADEIDLE", iActivityIndex: 433);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_GRENADEREADY", iActivityIndex: 434);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_PRIMARYATTACK", iActivityIndex: 435);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_GRENADEIDLE", iActivityIndex: 436);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_GRENADEREADY", iActivityIndex: 437);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_PRIMARYATTACK", iActivityIndex: 438);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_SHIELD_UP", iActivityIndex: 439);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_SHIELD_DOWN", iActivityIndex: 440);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_SHIELD_UP_IDLE", iActivityIndex: 441);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_SHIELD_ATTACK", iActivityIndex: 442);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OVERLAY_SHIELD_KNOCKBACK", iActivityIndex: 443);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIELD_UP", iActivityIndex: 444);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIELD_DOWN", iActivityIndex: 445);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIELD_UP_IDLE", iActivityIndex: 446);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIELD_ATTACK", iActivityIndex: 447);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SHIELD_KNOCKBACK", iActivityIndex: 448);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_SHIELD_UP", iActivityIndex: 449);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_SHIELD_DOWN", iActivityIndex: 450);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_SHIELD_UP_IDLE", iActivityIndex: 451);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_SHIELD_ATTACK", iActivityIndex: 452);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCHING_SHIELD_KNOCKBACK", iActivityIndex: 453);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_TURNRIGHT45", iActivityIndex: 454);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_TURNLEFT45", iActivityIndex: 455);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_TURN", iActivityIndex: 456);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_ASSEMBLING", iActivityIndex: 457);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_DISMANTLING", iActivityIndex: 458);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_STARTUP", iActivityIndex: 459);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_RUNNING", iActivityIndex: 460);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_IDLE", iActivityIndex: 461);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_PLACING", iActivityIndex: 462);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_DETERIORATING", iActivityIndex: 463);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_OBJ_UPGRADING", iActivityIndex: 464);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DEPLOY", iActivityIndex: 465);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DEPLOY_IDLE", iActivityIndex: 466);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_UNDEPLOY", iActivityIndex: 467);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROSSBOW_DRAW_UNLOADED", iActivityIndex: 468);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GAUSS_SPINUP", iActivityIndex: 469);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_GAUSS_SPINCYCLE", iActivityIndex: 470);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_PRIMARYATTACK_SILENCED", iActivityIndex: 471);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_RELOAD_SILENCED", iActivityIndex: 472);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DRYFIRE_SILENCED", iActivityIndex: 473);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IDLE_SILENCED", iActivityIndex: 474);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DRAW_SILENCED", iActivityIndex: 475);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IDLE_EMPTY_LEFT", iActivityIndex: 476);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DRYFIRE_LEFT", iActivityIndex: 477);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IS_DRAW", iActivityIndex: 478);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IS_HOLSTER", iActivityIndex: 479);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IS_IDLE", iActivityIndex: 480);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_IS_PRIMARYATTACK", iActivityIndex: 481);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PLAYER_IDLE_FIRE", iActivityIndex: 482);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PLAYER_CROUCH_FIRE", iActivityIndex: 483);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PLAYER_CROUCH_WALK_FIRE", iActivityIndex: 484);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PLAYER_WALK_FIRE", iActivityIndex: 485);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PLAYER_RUN_FIRE", iActivityIndex: 486);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLETORUN", iActivityIndex: 487);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUNTOIDLE", iActivityIndex: 488);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_DRAW_DEPLOYED", iActivityIndex: 489);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_IDLE_MELEE", iActivityIndex: 490);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_RUN_MELEE", iActivityIndex: 491);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_IDLE_CROUCH_MELEE", iActivityIndex: 492);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_WALK_CROUCH_MELEE", iActivityIndex: 493);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_GESTURE_RANGE_ATTACK_MELEE", iActivityIndex: 494);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_GESTURE_RELOAD_MELEE", iActivityIndex: 495);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_HL2MP_JUMP_MELEE", iActivityIndex: 496);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_FIZZLE", iActivityIndex: 497);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_IDLE", iActivityIndex: 498);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_IDLE", iActivityIndex: 499);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_DEPLOYED_IDLE", iActivityIndex: 500);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_DEPLOYED", iActivityIndex: 501);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DEPLOYED_IDLE", iActivityIndex: 502);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN", iActivityIndex: 503);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK", iActivityIndex: 504);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK", iActivityIndex: 505);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK", iActivityIndex: 506);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SPRINT", iActivityIndex: 507);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP", iActivityIndex: 508);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START", iActivityIndex: 509);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT", iActivityIndex: 510);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND", iActivityIndex: 511);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_IMPACT_N", iActivityIndex: 512);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_IMPACT_E", iActivityIndex: 513);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_IMPACT_W", iActivityIndex: 514);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_IMPACT_S", iActivityIndex: 515);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_IMPACT_TOP", iActivityIndex: 516);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DOUBLEJUMP", iActivityIndex: 517);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM", iActivityIndex: 518);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DEPLOYED", iActivityIndex: 519);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_DEPLOYED", iActivityIndex: 520);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_VCD", iActivityIndex: 521);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_PRIMARYFIRE", iActivityIndex: 522);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_PRIMARYFIRE_DEPLOYED", iActivityIndex: 523);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_SECONDARYFIRE", iActivityIndex: 524);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_GRENADE", iActivityIndex: 525);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_PRIMARYFIRE", iActivityIndex: 526);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_PRIMARYFIRE_DEPLOYED", iActivityIndex: 527);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_SECONDARYFIRE", iActivityIndex: 528);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_GRENADE", iActivityIndex: 529);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_PRIMARYFIRE", iActivityIndex: 530);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_SECONDARYFIRE", iActivityIndex: 531);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_GRENADE", iActivityIndex: 532);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_PRIMARYFIRE", iActivityIndex: 533);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_SECONDARYFIRE", iActivityIndex: 534);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_GRENADE", iActivityIndex: 535);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND", iActivityIndex: 536);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_LOOP", iActivityIndex: 537);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_END", iActivityIndex: 538);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH", iActivityIndex: 539);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_LOOP", iActivityIndex: 540);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_END", iActivityIndex: 541);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM", iActivityIndex: 542);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_LOOP", iActivityIndex: 543);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_END", iActivityIndex: 544);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK", iActivityIndex: 545);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_LOOP", iActivityIndex: 546);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_END", iActivityIndex: 547);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_PREFIRE", iActivityIndex: 548);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_POSTFIRE", iActivityIndex: 549);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_STARTFIRE", iActivityIndex: 550);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_PREFIRE", iActivityIndex: 551);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_POSTFIRE", iActivityIndex: 552);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_PREFIRE", iActivityIndex: 553);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_POSTFIRE", iActivityIndex: 554);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_PRIMARY", iActivityIndex: 555);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_PRIMARY", iActivityIndex: 556);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_PRIMARY", iActivityIndex: 557);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_PRIMARY", iActivityIndex: 558);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_PRIMARY", iActivityIndex: 559);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_PRIMARY", iActivityIndex: 560);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_PRIMARY", iActivityIndex: 561);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_PRIMARY", iActivityIndex: 562);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_PRIMARY", iActivityIndex: 563);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_PRIMARY", iActivityIndex: 564);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_PRIMARY", iActivityIndex: 565);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DEPLOYED_PRIMARY", iActivityIndex: 566);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_DEPLOYED_PRIMARY", iActivityIndex: 567);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_PRIMARY", iActivityIndex: 568);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_PRIMARY_DEPLOYED", iActivityIndex: 569);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_PRIMARY", iActivityIndex: 570);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_PRIMARY_DEPLOYED", iActivityIndex: 571);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_PRIMARY", iActivityIndex: 572);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_PRIMARY", iActivityIndex: 573);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_PRIMARY", iActivityIndex: 574);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_PRIMARY_LOOP", iActivityIndex: 575);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_PRIMARY_END", iActivityIndex: 576);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_PRIMARY", iActivityIndex: 577);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_PRIMARY_LOOP", iActivityIndex: 578);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_PRIMARY_END", iActivityIndex: 579);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_PRIMARY", iActivityIndex: 580);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_PRIMARY_LOOP", iActivityIndex: 581);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_PRIMARY_END", iActivityIndex: 582);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_PRIMARY", iActivityIndex: 583);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_PRIMARY_LOOP", iActivityIndex: 584);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_PRIMARY_END", iActivityIndex: 585);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_GRENADE_PRIMARY", iActivityIndex: 586);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_GRENADE_PRIMARY", iActivityIndex: 587);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_GRENADE_PRIMARY", iActivityIndex: 588);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_GRENADE_PRIMARY", iActivityIndex: 589);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_SECONDARY", iActivityIndex: 590);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_SECONDARY", iActivityIndex: 591);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_SECONDARY", iActivityIndex: 592);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_SECONDARY", iActivityIndex: 593);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_SECONDARY", iActivityIndex: 594);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_SECONDARY", iActivityIndex: 595);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_SECONDARY", iActivityIndex: 596);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_SECONDARY", iActivityIndex: 597);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_SECONDARY", iActivityIndex: 598);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_SECONDARY", iActivityIndex: 599);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_SECONDARY", iActivityIndex: 600);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_SECONDARY", iActivityIndex: 601);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_SECONDARY", iActivityIndex: 602);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_SECONDARY", iActivityIndex: 603);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_SECONDARY", iActivityIndex: 604);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_SECONDARY", iActivityIndex: 605);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_SECONDARY_LOOP", iActivityIndex: 606);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_STAND_SECONDARY_END", iActivityIndex: 607);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_SECONDARY", iActivityIndex: 608);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_SECONDARY_LOOP", iActivityIndex: 609);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_CROUCH_SECONDARY_END", iActivityIndex: 610);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_SECONDARY", iActivityIndex: 611);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_SECONDARY_LOOP", iActivityIndex: 612);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_SWIM_SECONDARY_END", iActivityIndex: 613);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_SECONDARY", iActivityIndex: 614);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_SECONDARY_LOOP", iActivityIndex: 615);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RELOAD_AIRWALK_SECONDARY_END", iActivityIndex: 616);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_GRENADE_SECONDARY", iActivityIndex: 617);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_GRENADE_SECONDARY", iActivityIndex: 618);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_GRENADE_SECONDARY", iActivityIndex: 619);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_GRENADE_SECONDARY", iActivityIndex: 620);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_MELEE", iActivityIndex: 621);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_MELEE", iActivityIndex: 622);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_MELEE", iActivityIndex: 623);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_MELEE", iActivityIndex: 624);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_MELEE", iActivityIndex: 625);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_MELEE", iActivityIndex: 626);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_MELEE", iActivityIndex: 627);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_MELEE", iActivityIndex: 628);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_MELEE", iActivityIndex: 629);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_MELEE", iActivityIndex: 630);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_MELEE", iActivityIndex: 631);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_MELEE", iActivityIndex: 632);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_MELEE_SECONDARY", iActivityIndex: 633);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_MELEE", iActivityIndex: 634);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_MELEE_SECONDARY", iActivityIndex: 635);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_MELEE", iActivityIndex: 636);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_MELEE", iActivityIndex: 637);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_GRENADE_MELEE", iActivityIndex: 638);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_GRENADE_MELEE", iActivityIndex: 639);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_GRENADE_MELEE", iActivityIndex: 640);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_GRENADE_MELEE", iActivityIndex: 641);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_ITEM1", iActivityIndex: 642);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_ITEM1", iActivityIndex: 643);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_ITEM1", iActivityIndex: 644);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_ITEM1", iActivityIndex: 645);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_ITEM1", iActivityIndex: 646);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_ITEM1", iActivityIndex: 647);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_ITEM1", iActivityIndex: 648);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_ITEM1", iActivityIndex: 649);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_ITEM1", iActivityIndex: 650);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_ITEM1", iActivityIndex: 651);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_ITEM1", iActivityIndex: 652);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_ITEM1", iActivityIndex: 653);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_ITEM1_SECONDARY", iActivityIndex: 654);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_ITEM1", iActivityIndex: 655);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_ITEM1_SECONDARY", iActivityIndex: 656);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_ITEM1", iActivityIndex: 657);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_ITEM1", iActivityIndex: 658);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_ITEM2", iActivityIndex: 659);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_ITEM2", iActivityIndex: 660);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_ITEM2", iActivityIndex: 661);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_ITEM2", iActivityIndex: 662);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_ITEM2", iActivityIndex: 663);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_ITEM2", iActivityIndex: 664);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_ITEM2", iActivityIndex: 665);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_ITEM2", iActivityIndex: 666);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_ITEM2", iActivityIndex: 667);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_ITEM2", iActivityIndex: 668);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_ITEM2", iActivityIndex: 669);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_ITEM2", iActivityIndex: 670);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_ITEM2_SECONDARY", iActivityIndex: 671);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_ITEM2", iActivityIndex: 672);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_ITEM2_SECONDARY", iActivityIndex: 673);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_ITEM2", iActivityIndex: 674);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_ITEM2", iActivityIndex: 675);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH", iActivityIndex: 676);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_PRIMARY", iActivityIndex: 677);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_SECONDARY", iActivityIndex: 678);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_MELEE", iActivityIndex: 679);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_ITEM1", iActivityIndex: 680);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_ITEM2", iActivityIndex: 681);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_HEAD", iActivityIndex: 682);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_CHEST", iActivityIndex: 683);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_STOMACH", iActivityIndex: 684);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_LEFTARM", iActivityIndex: 685);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_RIGHTARM", iActivityIndex: 686);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_LEFTLEG", iActivityIndex: 687);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_FLINCH_RIGHTLEG", iActivityIndex: 688);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GRENADE1_DRAW", iActivityIndex: 689);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GRENADE1_IDLE", iActivityIndex: 690);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GRENADE1_ATTACK", iActivityIndex: 691);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GRENADE2_DRAW", iActivityIndex: 692);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GRENADE2_IDLE", iActivityIndex: 693);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GRENADE2_ATTACK", iActivityIndex: 694);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_PRIMARY_GRENADE1_DRAW", iActivityIndex: 695);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_PRIMARY_GRENADE1_IDLE", iActivityIndex: 696);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_PRIMARY_GRENADE1_ATTACK", iActivityIndex: 697);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_PRIMARY_GRENADE2_DRAW", iActivityIndex: 698);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_PRIMARY_GRENADE2_IDLE", iActivityIndex: 699);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_PRIMARY_GRENADE2_ATTACK", iActivityIndex: 700);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SECONDARY_GRENADE1_DRAW", iActivityIndex: 701);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SECONDARY_GRENADE1_IDLE", iActivityIndex: 702);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SECONDARY_GRENADE1_ATTACK", iActivityIndex: 703);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SECONDARY_GRENADE2_DRAW", iActivityIndex: 704);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SECONDARY_GRENADE2_IDLE", iActivityIndex: 705);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SECONDARY_GRENADE2_ATTACK", iActivityIndex: 706);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_MELEE_GRENADE1_DRAW", iActivityIndex: 707);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_MELEE_GRENADE1_IDLE", iActivityIndex: 708);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_MELEE_GRENADE1_ATTACK", iActivityIndex: 709);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_MELEE_GRENADE2_DRAW", iActivityIndex: 710);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_MELEE_GRENADE2_IDLE", iActivityIndex: 711);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_MELEE_GRENADE2_ATTACK", iActivityIndex: 712);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM1_GRENADE1_DRAW", iActivityIndex: 713);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM1_GRENADE1_IDLE", iActivityIndex: 714);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM1_GRENADE1_ATTACK", iActivityIndex: 715);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM1_GRENADE2_DRAW", iActivityIndex: 716);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM1_GRENADE2_IDLE", iActivityIndex: 717);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM1_GRENADE2_ATTACK", iActivityIndex: 718);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM2_GRENADE1_DRAW", iActivityIndex: 719);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM2_GRENADE1_IDLE", iActivityIndex: 720);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM2_GRENADE1_ATTACK", iActivityIndex: 721);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM2_GRENADE2_DRAW", iActivityIndex: 722);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM2_GRENADE2_IDLE", iActivityIndex: 723);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ITEM2_GRENADE2_ATTACK", iActivityIndex: 724);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_BUILDING", iActivityIndex: 725);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_BUILDING", iActivityIndex: 726);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_BUILDING", iActivityIndex: 727);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_BUILDING", iActivityIndex: 728);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_BUILDING", iActivityIndex: 729);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_BUILDING", iActivityIndex: 730);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_BUILDING", iActivityIndex: 731);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_BUILDING", iActivityIndex: 732);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_BUILDING", iActivityIndex: 733);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_BUILDING", iActivityIndex: 734);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_BUILDING", iActivityIndex: 735);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_BUILDING", iActivityIndex: 736);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_BUILDING", iActivityIndex: 737);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_BUILDING", iActivityIndex: 738);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_BUILDING", iActivityIndex: 739);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_GRENADE_BUILDING", iActivityIndex: 740);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_CROUCH_GRENADE_BUILDING", iActivityIndex: 741);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_GRENADE_BUILDING", iActivityIndex: 742);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_AIRWALK_GRENADE_BUILDING", iActivityIndex: 743);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_STAND_PDA", iActivityIndex: 744);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCH_PDA", iActivityIndex: 745);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_PDA", iActivityIndex: 746);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_WALK_PDA", iActivityIndex: 747);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_AIRWALK_PDA", iActivityIndex: 748);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_CROUCHWALK_PDA", iActivityIndex: 749);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_PDA", iActivityIndex: 750);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_START_PDA", iActivityIndex: 751);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_FLOAT_PDA", iActivityIndex: 752);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_JUMP_LAND_PDA", iActivityIndex: 753);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_SWIM_PDA", iActivityIndex: 754);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_STAND_PDA", iActivityIndex: 755);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_ATTACK_SWIM_PDA", iActivityIndex: 756);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH", iActivityIndex: 757);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT", iActivityIndex: 758);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP", iActivityIndex: 759);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP", iActivityIndex: 760);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES", iActivityIndex: 761);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO", iActivityIndex: 762);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_PRIMARY", iActivityIndex: 763);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_PRIMARY", iActivityIndex: 764);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_PRIMARY", iActivityIndex: 765);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_PRIMARY", iActivityIndex: 766);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_PRIMARY", iActivityIndex: 767);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_PRIMARY", iActivityIndex: 768);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_SECONDARY", iActivityIndex: 769);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_SECONDARY", iActivityIndex: 770);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_SECONDARY", iActivityIndex: 771);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_SECONDARY", iActivityIndex: 772);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_SECONDARY", iActivityIndex: 773);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_SECONDARY", iActivityIndex: 774);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_MELEE", iActivityIndex: 775);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_MELEE", iActivityIndex: 776);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_MELEE", iActivityIndex: 777);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_MELEE", iActivityIndex: 778);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_MELEE", iActivityIndex: 779);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_MELEE", iActivityIndex: 780);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_ITEM1", iActivityIndex: 781);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_ITEM1", iActivityIndex: 782);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_ITEM1", iActivityIndex: 783);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_ITEM1", iActivityIndex: 784);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_ITEM1", iActivityIndex: 785);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_ITEM1", iActivityIndex: 786);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_ITEM2", iActivityIndex: 787);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_ITEM2", iActivityIndex: 788);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_ITEM2", iActivityIndex: 789);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_ITEM2", iActivityIndex: 790);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_ITEM2", iActivityIndex: 791);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_ITEM2", iActivityIndex: 792);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_BUILDING", iActivityIndex: 793);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_BUILDING", iActivityIndex: 794);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_BUILDING", iActivityIndex: 795);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_BUILDING", iActivityIndex: 796);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_BUILDING", iActivityIndex: 797);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_BUILDING", iActivityIndex: 798);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_HANDMOUTH_PDA", iActivityIndex: 799);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FINGERPOINT_PDA", iActivityIndex: 800);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_FISTPUMP_PDA", iActivityIndex: 801);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_THUMBSUP_PDA", iActivityIndex: 802);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODYES_PDA", iActivityIndex: 803);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_GESTURE_VC_NODNO_PDA", iActivityIndex: 804);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_UNUSABLE", iActivityIndex: 805);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_UNUSABLE_TO_USABLE", iActivityIndex: 806);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_VM_USABLE_TO_UNUSABLE", iActivityIndex: 807);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_DRAW", iActivityIndex: 808);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_HOLSTER", iActivityIndex: 809);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_IDLE", iActivityIndex: 810);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_PULLBACK", iActivityIndex: 811);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_PRIMARYATTACK", iActivityIndex: 812);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_SECONDARYATTACK", iActivityIndex: 813);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_RELOAD", iActivityIndex: 814);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_DRYFIRE", iActivityIndex: 815);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_IDLE_TO_LOWERED", iActivityIndex: 816);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_IDLE_LOWERED", iActivityIndex: 817);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PRIMARY_VM_LOWERED_TO_IDLE", iActivityIndex: 818);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_DRAW", iActivityIndex: 819);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_HOLSTER", iActivityIndex: 820);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_IDLE", iActivityIndex: 821);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_PULLBACK", iActivityIndex: 822);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_PRIMARYATTACK", iActivityIndex: 823);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_SECONDARYATTACK", iActivityIndex: 824);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_RELOAD", iActivityIndex: 825);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_DRYFIRE", iActivityIndex: 826);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_IDLE_TO_LOWERED", iActivityIndex: 827);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_IDLE_LOWERED", iActivityIndex: 828);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SECONDARY_VM_LOWERED_TO_IDLE", iActivityIndex: 829);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_DRAW", iActivityIndex: 830);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_HOLSTER", iActivityIndex: 831);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_IDLE", iActivityIndex: 832);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_PULLBACK", iActivityIndex: 833);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_PRIMARYATTACK", iActivityIndex: 834);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_SECONDARYATTACK", iActivityIndex: 835);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_RELOAD", iActivityIndex: 836);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_DRYFIRE", iActivityIndex: 837);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_IDLE_TO_LOWERED", iActivityIndex: 838);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_IDLE_LOWERED", iActivityIndex: 839);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MELEE_VM_LOWERED_TO_IDLE", iActivityIndex: 840);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_DRAW", iActivityIndex: 841);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_HOLSTER", iActivityIndex: 842);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_IDLE", iActivityIndex: 843);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_PULLBACK", iActivityIndex: 844);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_PRIMARYATTACK", iActivityIndex: 845);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_SECONDARYATTACK", iActivityIndex: 846);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_RELOAD", iActivityIndex: 847);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_DRYFIRE", iActivityIndex: 848);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_IDLE_TO_LOWERED", iActivityIndex: 849);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_IDLE_LOWERED", iActivityIndex: 850);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PDA_VM_LOWERED_TO_IDLE", iActivityIndex: 851);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_DRAW", iActivityIndex: 852);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_HOLSTER", iActivityIndex: 853);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_IDLE", iActivityIndex: 854);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_PULLBACK", iActivityIndex: 855);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_PRIMARYATTACK", iActivityIndex: 856);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_SECONDARYATTACK", iActivityIndex: 857);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_RELOAD", iActivityIndex: 858);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_DRYFIRE", iActivityIndex: 859);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_IDLE_TO_LOWERED", iActivityIndex: 860);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_IDLE_LOWERED", iActivityIndex: 861);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM1_VM_LOWERED_TO_IDLE", iActivityIndex: 862);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_DRAW", iActivityIndex: 863);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_HOLSTER", iActivityIndex: 864);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_IDLE", iActivityIndex: 865);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_PULLBACK", iActivityIndex: 866);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_PRIMARYATTACK", iActivityIndex: 867);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_SECONDARYATTACK", iActivityIndex: 868);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_RELOAD", iActivityIndex: 869);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_DRYFIRE", iActivityIndex: 870);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_IDLE_TO_LOWERED", iActivityIndex: 871);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_IDLE_LOWERED", iActivityIndex: 872);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_ITEM2_VM_LOWERED_TO_IDLE", iActivityIndex: 873);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_SUCCEED", iActivityIndex: 874);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_FAIL", iActivityIndex: 875);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_AUTOGUN", iActivityIndex: 876);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_AUTOGUN", iActivityIndex: 877);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AUTOGUN", iActivityIndex: 878);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_AUTOGUN", iActivityIndex: 879);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_AUTOGUN", iActivityIndex: 880);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCH_IDLE_AUTOGUN", iActivityIndex: 881);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_AUTOGUN", iActivityIndex: 882);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_JUMP_AUTOGUN", iActivityIndex: 883);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_PISTOL", iActivityIndex: 884);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WALK_AIM_DUAL", iActivityIndex: 885);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RUN_AIM_DUAL", iActivityIndex: 886);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_DUAL", iActivityIndex: 887);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_DUAL", iActivityIndex: 888);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_DUAL", iActivityIndex: 889);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCH_IDLE_DUAL", iActivityIndex: 890);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_DUAL", iActivityIndex: 891);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_JUMP_DUAL", iActivityIndex: 892);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_SHOTGUN", iActivityIndex: 893);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_SHOTGUN", iActivityIndex: 894);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCH_IDLE_SHOTGUN", iActivityIndex: 895);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_JUMP_SHOTGUN", iActivityIndex: 896);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_IDLE_AIM_RIFLE", iActivityIndex: 897);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RELOAD_RIFLE", iActivityIndex: 898);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_CROUCH_IDLE_RIFLE", iActivityIndex: 899);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_RANGE_ATTACK_RIFLE", iActivityIndex: 900);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_JUMP_RIFLE", iActivityIndex: 901);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SLEEP", iActivityIndex: 902);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_WAKE", iActivityIndex: 903);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLICK_LEFT", iActivityIndex: 904);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLICK_LEFT_MIDDLE", iActivityIndex: 905);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLICK_RIGHT_MIDDLE", iActivityIndex: 906);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FLICK_RIGHT", iActivityIndex: 907);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SPINAROUND", iActivityIndex: 908);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PREP_TO_FIRE", iActivityIndex: 909);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FIRE", iActivityIndex: 910);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_FIRE_RECOVER", iActivityIndex: 911);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_SPRAY", iActivityIndex: 912);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_PREP_EXPLODE", iActivityIndex: 913);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_EXPLODE", iActivityIndex: 914);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_IDLE", iActivityIndex: 915);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_RUN", iActivityIndex: 916);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_ATTACK", iActivityIndex: 917);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_ATTACK_EVENT", iActivityIndex: 918);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_DIE", iActivityIndex: 919);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_FLINCH", iActivityIndex: 920);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_DISABLED", iActivityIndex: 921);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CAST_ABILITY_1", iActivityIndex: 922);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CAST_ABILITY_2", iActivityIndex: 923);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CAST_ABILITY_3", iActivityIndex: 924);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CAST_ABILITY_4", iActivityIndex: 925);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_OVERRIDE_ABILITY_1", iActivityIndex: 926);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_OVERRIDE_ABILITY_2", iActivityIndex: 927);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_OVERRIDE_ABILITY_3", iActivityIndex: 928);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_OVERRIDE_ABILITY_4", iActivityIndex: 929);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_ABILITY_1", iActivityIndex: 930);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_ABILITY_2", iActivityIndex: 931);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_ABILITY_3", iActivityIndex: 932);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_ABILITY_4", iActivityIndex: 933);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_END_ABILITY_1", iActivityIndex: 934);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_END_ABILITY_2", iActivityIndex: 935);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_END_ABILITY_3", iActivityIndex: 936);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_DOTA_CHANNEL_END_ABILITY_4", iActivityIndex: 937);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_SPEEDPAINT", iActivityIndex: 938);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_LONG_FALL", iActivityIndex: 939);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_TRACTORBEAM_FLOAT", iActivityIndex: 940);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DEATH_CRUSH", iActivityIndex: 941);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_RUN_SPEEDPAINT_PRIMARY", iActivityIndex: 942);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DROWNING_PRIMARY", iActivityIndex: 943);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_LONG_FALL_PRIMARY", iActivityIndex: 944);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_TRACTORBEAM_FLOAT_PRIMARY", iActivityIndex: 945);
  ActivityList_RegisterSharedActivity(pszActivityName: "ACT_MP_DEATH_CRUSH_PRIMARY", iActivityIndex: 946);
}

//------------------------------------------------------------------------------
// Address: 0x10005CB0
// Name: void ActivityList_Free(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ActivityList_Free()
{
  activitylist_t *m_pMemory; // eax

  CStringRegistry::ClearStrings(this: &g_ActivityStrings);
  m_pMemory = g_ActivityList.m_Memory.m_pMemory;
  g_ActivityList.m_Size = 0;
  if ( g_ActivityList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ActivityList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ActivityList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_ActivityList.m_Memory.m_pMemory = nullptr;
    }
    g_ActivityList.m_Memory.m_nAllocationCount = 0;
  }
  g_ActivityList.m_pElements = m_pMemory;
  CUtlDict<CActivityRemapCache,int>::RemoveAll(this: &m_ActivityRemapDatabase);
  ++g_nActivityListVersion;
}

//------------------------------------------------------------------------------
// Address: 0x1008B7F0
// Name: public: virtual bool CActivityDataOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CActivityDataOps::IsEmpty(CActivityDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  return *(_DWORD *)fieldInfo->pField == 0;
}

} // namespace server
