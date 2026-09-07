// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_schedule.cpp
// Functions: 14
// ============================================================

#include "game\server\ai_schedule.h"

//------------------------------------------------------------------------------
// Address: 0x10081A40
// Name: private: void CAI_SchedulesManager::CreateStringRegistries(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SchedulesManager::CreateStringRegistries(CAI_SchedulesManager *this)
{
  CStringRegistry *v1; // eax
  CStringRegistry *v2; // eax

  CAI_GlobalNamespace::Clear(this: &CAI_Agent::gm_SchedulingSymbols.m_ScheduleNamespace);
  CAI_GlobalNamespace::Clear(this: &CAI_Agent::gm_SchedulingSymbols.m_TaskNamespace);
  CAI_GlobalNamespace::Clear(this: &CAI_Agent::gm_SchedulingSymbols.m_ConditionNamespace);
  CAI_GlobalNamespace::Clear(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_ScheduleNamespace);
  CAI_GlobalNamespace::Clear(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_TaskNamespace);
  CAI_GlobalNamespace::Clear(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_ConditionNamespace);
  CAI_GlobalNamespace::Clear(this: &CAI_BaseNPC::gm_SquadSlotNamespace);
  v1 = (CStringRegistry *)operator new(nSize: 4u);
  if ( v1 != nullptr )
    CAI_BaseNPC::m_pActivitySR = CStringRegistry::CStringRegistry(this: v1);
  else
    CAI_BaseNPC::m_pActivitySR = nullptr;
  v2 = (CStringRegistry *)operator new(nSize: 4u);
  if ( v2 != nullptr )
    CAI_BaseNPC::m_pEventSR = CStringRegistry::CStringRegistry(this: v2);
  else
    CAI_BaseNPC::m_pEventSR = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10081AE0
// Name: public: static void CAI_BaseNPC::InitSchedulingTables(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_BaseNPC::InitSchedulingTables()
{
  CAI_BaseNPC::gm_ClassScheduleIdSpace.m_pszClassName = "CAI_BaseNPC";
  if ( CAI_LocalIdSpace::Init(
         this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
         pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols.m_ScheduleNamespace,
         pParentIDSpace: nullptr) != 0
    && CAI_LocalIdSpace::Init(
         this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
         pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols.m_TaskNamespace,
         pParentIDSpace: nullptr) != 0 )
  {
    CAI_LocalIdSpace::Init(
      this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
      pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols.m_ConditionNamespace,
      pParentIDSpace: nullptr);
  }
  CAI_BaseNPC::InitDefaultScheduleSR();
  CAI_BaseNPC::InitDefaultConditionSR();
  CAI_BaseNPC::InitDefaultTaskSR();
  CAI_BaseNPC::InitDefaultActivitySR();
  CAI_BaseNPC::InitDefaultSquadSlotSR();
}

//------------------------------------------------------------------------------
// Address: 0x10081B40
// Name: public: static void CAI_Agent::InitSchedulingTables(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_Agent::InitSchedulingTables()
{
  CAI_Agent::gm_ClassScheduleIdSpace.m_pszClassName = "CAI_Agent";
  if ( CAI_LocalIdSpace::Init(
         this: &CAI_Agent::gm_ClassScheduleIdSpace.m_ScheduleIds,
         pGlobalNamespace: &CAI_Agent::gm_SchedulingSymbols.m_ScheduleNamespace,
         pParentIDSpace: nullptr) != 0
    && CAI_LocalIdSpace::Init(
         this: &CAI_Agent::gm_ClassScheduleIdSpace.m_TaskIds,
         pGlobalNamespace: &CAI_Agent::gm_SchedulingSymbols.m_TaskNamespace,
         pParentIDSpace: nullptr) != 0 )
  {
    CAI_LocalIdSpace::Init(
      this: &CAI_Agent::gm_ClassScheduleIdSpace.m_ConditionIds,
      pGlobalNamespace: &CAI_Agent::gm_SchedulingSymbols.m_ConditionNamespace,
      pParentIDSpace: nullptr);
  }
  CAI_Agent::InitDefaultScheduleSR();
  CAI_Agent::InitDefaultConditionSR();
  CAI_Agent::InitDefaultTaskSR();
}

//------------------------------------------------------------------------------
// Address: 0x10081BA0
// Name: public: bool CAI_SchedulesManager::LoadAllSchedules(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_SchedulesManager::LoadAllSchedules(CAI_SchedulesManager *this)
{
  vgui::Panel *v1; // ecx

  if ( this->allSchedules != nullptr )
    return 1;
  CAI_BaseNPC::InitSchedulingTables();
  CAI_Agent::InitSchedulingTables();
  if ( !CAI_BaseNPC::LoadDefaultSchedules() )
  {
    CAI_BaseNPC::m_nDebugBits |= 1u;
    DevMsg(a1: "ERROR:  Mistake in default schedule definitions, AI Disabled.\n");
  }
  if ( CAI_BaseNPC::CreateBehaviors(this: v1) == 0 )
    DevMsg(a1: "ERROR:  Mistake in default schedule definitions, AI Disabled.\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10081BF0
// Name: private: int CAI_SchedulesManager::GetStateID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_SchedulesManager::GetStateID(CAI_SchedulesManager *this, const char *state_name)
{
  int result; // eax

  result = _V_stricmp(s1: state_name, s2: "NONE");
  if ( result != 0 )
  {
    if ( _V_stricmp(s1: state_name, s2: "IDLE") != 0 )
    {
      if ( _V_stricmp(s1: state_name, s2: "COMBAT") != 0 )
      {
        if ( _V_stricmp(s1: state_name, s2: "PRONE") != 0 )
        {
          if ( _V_stricmp(s1: state_name, s2: "ALERT") != 0 )
          {
            if ( _V_stricmp(s1: state_name, s2: "SCRIPT") != 0 )
            {
              if ( _V_stricmp(s1: state_name, s2: "PLAYDEAD") != 0 )
                return _V_stricmp(s1: state_name, s2: "DEAD") != 0 ? -1 : 7;
              else
                return 5;
            }
            else
            {
              return 4;
            }
          }
          else
          {
            return 2;
          }
        }
        else
        {
          return 6;
        }
      }
      else
      {
        return 3;
      }
    }
    else
    {
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10081CE0
// Name: private: int CAI_SchedulesManager::GetMemoryID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CAI_SchedulesManager::GetMemoryID(CAI_SchedulesManager *this, const char *state_name)
{
  if ( _V_stricmp(s1: state_name, s2: "PROVOKED") == 0 )
    return 1;
  if ( _V_stricmp(s1: state_name, s2: "INCOVER") == 0 )
    return 2;
  if ( _V_stricmp(s1: state_name, s2: "SUSPICIOUS") == 0 )
    return 4;
  if ( _V_stricmp(s1: state_name, s2: "PATH_FAILED") == 0 )
    return 32;
  if ( _V_stricmp(s1: state_name, s2: "FLINCHED") == 0 )
    return 64;
  if ( _V_stricmp(s1: state_name, s2: "TOURGUIDE") == 0 )
    return 256;
  if ( _V_stricmp(s1: state_name, s2: "LOCKED_HINT") == 0 )
    return 1024;
  if ( _V_stricmp(s1: state_name, s2: "TURNING") == 0 )
    return 0x2000;
  if ( _V_stricmp(s1: state_name, s2: "TURNHACK") == 0 )
    return 0x4000;
  if ( _V_stricmp(s1: state_name, s2: "CUSTOM4") == 0 )
    return 0x10000000;
  if ( _V_stricmp(s1: state_name, s2: "CUSTOM3") == 0 )
    return 0x20000000;
  if ( _V_stricmp(s1: state_name, s2: "CUSTOM2") != 0 )
    return _V_stricmp(s1: state_name, s2: "CUSTOM1") != 0 ? -1 : 0x80000000;
  return 0x40000000;
}

//------------------------------------------------------------------------------
// Address: 0x10081E60
// Name: private: int CAI_SchedulesManager::GetPathID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_SchedulesManager::GetPathID(CAI_SchedulesManager *this, const char *token)
{
  int result; // eax

  result = _V_stricmp(s1: token, s2: "TRAVEL");
  if ( result != 0 )
  {
    if ( _V_stricmp(s1: token, s2: "LOS") != 0 )
      return _V_stricmp(s1: token, s2: "COVER") != 0 ? -1 : 2;
    else
      return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10081EC0
// Name: private: int CAI_SchedulesManager::GetGoalID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_SchedulesManager::GetGoalID(CAI_SchedulesManager *this, const char *token)
{
  int result; // eax

  result = _V_stricmp(s1: token, s2: "ENEMY");
  if ( result != 0 )
  {
    if ( _V_stricmp(s1: token, s2: "ENEMY_LKP") != 0 )
    {
      if ( _V_stricmp(s1: token, s2: "TARGET") != 0 )
        return _V_stricmp(s1: token, s2: "SAVED_POSITION") != 0 ? -1 : 3;
      else
        return 1;
    }
    else
    {
      return 2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10081F40
// Name: public: class CAI_Schedule __near * CAI_SchedulesManager::GetScheduleFromID(int)
// Source: json
//------------------------------------------------------------------------------
CAI_Schedule *__thiscall CAI_SchedulesManager::GetScheduleFromID(CAI_SchedulesManager *this, int schedID)
{
  CAI_Schedule *result; // eax
  const char *v3; // eax

  result = this->allSchedules;
  if ( result != nullptr )
  {
    while ( result->m_iScheduleID != schedID )
    {
      result = result->nextSchedule;
      if ( result == nullptr )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v3 = CAI_GlobalNamespace::IdToSymbol(
           this: &CAI_BaseNPC::gm_SchedulingSymbols.m_ScheduleNamespace,
           symbolID: schedID);
    DevMsg(a1: "Couldn't find schedule (%s)\n", v3);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10081F80
// Name: private: void CAI_SchedulesManager::DestroyStringRegistries(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SchedulesManager::DestroyStringRegistries(CAI_SchedulesManager *this)
{
  CStringRegistry *v1; // esi
  CStringRegistry *v2; // esi

  CAI_GlobalNamespace::Clear(this: &CAI_Agent::gm_SchedulingSymbols.m_ScheduleNamespace);
  CAI_GlobalNamespace::Clear(this: &CAI_Agent::gm_SchedulingSymbols.m_TaskNamespace);
  CAI_GlobalNamespace::Clear(this: &CAI_Agent::gm_SchedulingSymbols.m_ConditionNamespace);
  CAI_GlobalNamespace::Clear(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_ScheduleNamespace);
  CAI_GlobalNamespace::Clear(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_TaskNamespace);
  CAI_GlobalNamespace::Clear(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_ConditionNamespace);
  CAI_GlobalNamespace::Clear(this: &CAI_BaseNPC::gm_SquadSlotNamespace);
  v1 = CAI_BaseNPC::m_pActivitySR;
  if ( CAI_BaseNPC::m_pActivitySR != nullptr )
  {
    CStringRegistry::~CStringRegistry(this: CAI_BaseNPC::m_pActivitySR);
    free(pMem: v1);
  }
  CAI_BaseNPC::m_pActivitySR = nullptr;
  CAI_BaseNPC::m_iNumActivities = 0;
  v2 = CAI_BaseNPC::m_pEventSR;
  if ( CAI_BaseNPC::m_pEventSR != nullptr )
  {
    CStringRegistry::~CStringRegistry(this: CAI_BaseNPC::m_pEventSR);
    free(pMem: v2);
  }
  CAI_BaseNPC::m_iNumEvents = 0;
  CAI_BaseNPC::m_pEventSR = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10082020
// Name: public: class CAI_Schedule __near * CAI_SchedulesManager::GetScheduleByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_Schedule *__thiscall CAI_SchedulesManager::GetScheduleByName(CAI_SchedulesManager *this, const char *name)
{
  CAI_Schedule *allSchedules; // esi
  const char *m_pName; // eax

  allSchedules = this->allSchedules;
  if ( allSchedules == nullptr )
    return nullptr;
  while ( 1 )
  {
    m_pName = allSchedules->m_pName;
    if ( m_pName == name || _V_stricmp(s1: m_pName, s2: name) == 0 )
      break;
    allSchedules = allSchedules->nextSchedule;
    if ( allSchedules == nullptr )
      return nullptr;
  }
  return allSchedules;
}

//------------------------------------------------------------------------------
// Address: 0x10082060
// Name: private: void CAI_SchedulesManager::DeleteAllSchedules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SchedulesManager::DeleteAllSchedules(CAI_SchedulesManager *this)
{
  CAI_Schedule *allSchedules; // esi
  CAI_Schedule *nextSchedule; // edi

  if ( ++this->m_CurLoadSig < 0 )
    this->m_CurLoadSig = 0;
  allSchedules = this->allSchedules;
  if ( allSchedules != nullptr )
  {
    do
    {
      nextSchedule = allSchedules->nextSchedule;
      free(pMem: allSchedules->m_pName);
      free(pMem: allSchedules->m_pTaskList);
      free(pMem: allSchedules);
      allSchedules = nextSchedule;
    }
    while ( nextSchedule != nullptr );
  }
  this->allSchedules = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100820B0
// Name: private: CAI_Schedule::CAI_Schedule(char __near *,int,class CAI_Schedule __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_Schedule *__thiscall CAI_Schedule::CAI_Schedule(
        CAI_Schedule *this,
        char *name,
        int schedule_id,
        CAI_Schedule *pNext)
{
  unsigned int v5; // kr00_4
  char *v6; // eax

  if ( this != (CAI_Schedule *)-12 )
  {
    *(_QWORD *)this->m_InterruptMask.m_Ints = 0;
    *(_QWORD *)&this->m_InterruptMask.m_Ints[2] = 0;
    *(_QWORD *)&this->m_InterruptMask.m_Ints[4] = 0;
    *(_QWORD *)&this->m_InterruptMask.m_Ints[6] = 0;
  }
  this->m_iScheduleID = schedule_id;
  v5 = strlen(name);
  v6 = (char *)operator new(nSize: v5 + 1);
  this->m_pName = v6;
  V_strncpy(pDest: v6, pSrc: name, maxLen: v5 + 1);
  this->m_pTaskList = nullptr;
  this->m_iNumTasks = 0;
  this->nextSchedule = pNext;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10082120
// Name: public: bool CAI_SchedulesManager::LoadSchedulesFromBuffer(char const __near *,char __near *,class CAI_ClassScheduleIdSpace __near *,class CAI_GlobalScheduleNamespace __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_SchedulesManager::LoadSchedulesFromBuffer(
        CAI_SchedulesManager *this,
        const char *prefix,
        char *pStartFile,
        CAI_ClassScheduleIdSpace *pIdSpace,
        CAI_GlobalScheduleNamespace *pGlobalNamespace)
{
  CAI_SchedulesManager *v5; // edi
  const char *(__thiscall *ParseFile)(IVEngineServer *, const char *, char *, int); // eax
  const char *i; // esi
  const char *v8; // eax
  CAI_Schedule *allSchedules; // esi
  char *m_pName; // eax
  int v11; // esi
  CAI_Schedule *v12; // eax
  CAI_Schedule *v13; // ebx
  const char *v14; // esi
  int v15; // edi
  const char *v16; // esi
  int v17; // eax
  int v18; // eax
  const char *v19; // esi
  const char *v20; // esi
  float ActivityID; // xmm0_4
  const char *v23; // esi
  int v24; // eax
  int v25; // eax
  const char *v26; // esi
  int v27; // eax
  int v28; // eax
  const char *v29; // esi
  float StateID; // xmm0_4
  const char *v31; // esi
  float MemoryID; // xmm0_4
  const char *v33; // esi
  float PathID; // xmm0_4
  const char *v35; // esi
  float GoalID; // xmm0_4
  const char *v37; // esi
  float Flags; // xmm0_4
  int v39; // eax
  double flTaskData; // st7
  int iTask; // esi
  double v42; // st7
  float *p_flTaskData; // ecx
  int v44; // esi
  double v45; // st7
  int v46; // esi
  double v47; // st7
  double v48; // st7
  int v49; // eax
  char v50; // cl
  unsigned int *v51; // eax
  char save_token[1024]; // [esp+Ch] [ebp-99Ch] BYREF
  Task_t tempTask[50]; // [esp+40Ch] [ebp-59Ch] BYREF
  char token[1024]; // [esp+59Ch] [ebp-40Ch] BYREF
  int v55; // [esp+99Ch] [ebp-Ch]
  int taskID; // [esp+9A0h] [ebp-8h]
  CAI_SchedulesManager *v57; // [esp+9A4h] [ebp-4h]
  const char *pfile; // [esp+9B4h] [ebp+Ch]
  const char *pfilea; // [esp+9B4h] [ebp+Ch]

  v5 = this;
  ParseFile = engine->ParseFile;
  v57 = this;
  i = ParseFile(this: engine, a2: pStartFile, a3: token, a4: 1024);
  if ( _V_stricmp(s1: "Schedule", s2: token) != 0 )
    return 1;
  while ( 1 )
  {
    v8 = engine->ParseFile(this: engine, a2: i, a3: token, a4: 1024);
    allSchedules = v5->allSchedules;
    pfile = v8;
    if ( allSchedules != nullptr )
      break;
LABEL_6:
    v11 = CAI_GlobalNamespace::SymbolToId(this: &pGlobalNamespace->m_ScheduleNamespace, pszSymbol: token);
    if ( v11 == -1 )
    {
      DevMsg(a1: "ERROR: LoadSchd (%s): Unknown schedule type (%s)\n", prefix, token);
      return 1;
    }
    v12 = (CAI_Schedule *)operator new(nSize: 0x34u);
    if ( v12 != nullptr )
      v13 = CAI_Schedule::CAI_Schedule(this: v12, name: token, schedule_id: v11, pNext: v5->allSchedules);
    else
      v13 = nullptr;
    v5->allSchedules = v13;
    v14 = engine->ParseFile(this: engine, a2: pfile, a3: token, a4: 1024);
    if ( _V_stricmp(s1: token, s2: "Tasks") != 0 )
    {
      DevMsg(
        a1: "ERROR: LoadSchd (%s): (%s) Malformed AI Schedule.  Expecting 'Tasks' keyword.\n",
        prefix,
        v13->m_pName);
      return 0;
    }
    v15 = 0;
    v16 = engine->ParseFile(this: engine, a2: v14, a3: token, a4: 1024);
    pfilea = v16;
    if ( token[0] != 0 )
    {
      while ( _V_stricmp(s1: "Interrupts", s2: token) != 0 )
      {
        v17 = CAI_GlobalNamespace::SymbolToId(this: &pGlobalNamespace->m_TaskNamespace, pszSymbol: token);
        taskID = v17;
        if ( pIdSpace != nullptr )
        {
          v18 = CAI_LocalIdSpace::GlobalToLocal(this: &pIdSpace->m_TaskIds, globalID: v17);
        }
        else if ( v17 == -1 )
        {
          v18 = -1;
        }
        else
        {
          v18 = v17 - 1000000000;
        }
        tempTask[v15].iTask = v18;
        if ( v18 == -1 )
          goto LABEL_84;
        v19 = engine->ParseFile(this: engine, a2: v16, a3: token, a4: 1024);
        if ( _V_stricmp(s1: "Activity", s2: token) != 0 )
        {
          if ( _V_stricmp(s1: "Task", s2: token) != 0 )
          {
            if ( _V_stricmp(s1: "Schedule", s2: token) != 0 )
            {
              if ( _V_stricmp(s1: "State", s2: token) != 0 )
              {
                if ( _V_stricmp(s1: "Memory", s2: token) != 0 )
                {
                  if ( _V_stricmp(s1: "Path", s2: token) != 0 )
                  {
                    if ( _V_stricmp(s1: "Goal", s2: token) != 0 )
                    {
                      if ( _V_stricmp(s1: "HintFlags", s2: token) != 0 )
                      {
                        if ( _V_stricmp(s1: "Interrupts", s2: token) == 0
                          || V_strncasecmp(s1: "TASK_", s2: token, n: 5) == 0 )
                        {
                          _Warning(
                            a1: "ERROR: LoadSchd (%s): (%s) Bad syntax at task #%d (wasn't expecting %s)\n",
                            prefix,
                            v13->m_pName,
                            v15,
                            token);
                          return 0;
                        }
                        tempTask[v15].flTaskData = atof(nptr: token);
                      }
                      else
                      {
                        v37 = engine->ParseFile(this: engine, a2: v19, a3: token, a4: 1024);
                        if ( _V_stricmp(s1: token, s2: ":") != 0 )
                        {
                          DevMsg(
                            a1: "ERROR: LoadSchd (%s): (%s) Malformed AI Schedule.  Expecting ':' after type 'HINTFLAG'\n",
                            prefix,
                            v13->m_pName);
                          return 0;
                        }
                        v19 = engine->ParseFile(this: engine, a2: v37, a3: token, a4: 1024);
                        Flags = (float)CAI_HintManager::GetFlags(token);
                        tempTask[v15].flTaskData = Flags;
                        if ( Flags == -1.0 )
                        {
                          DevMsg(
                            a1: "ERROR: LoadSchd (%s): (%s) Unknown hint flag type  %s!\n",
                            prefix,
                            v13->m_pName,
                            token);
                          return 0;
                        }
                      }
                    }
                    else
                    {
                      v35 = engine->ParseFile(this: engine, a2: v19, a3: token, a4: 1024);
                      if ( _V_stricmp(s1: token, s2: ":") != 0 )
                      {
                        DevMsg(
                          a1: "ERROR: LoadSchd (%s): (%s) Malformed AI Schedule.  Expecting ':' after type 'GOAL.\n",
                          prefix,
                          v13->m_pName);
                        return 0;
                      }
                      v19 = engine->ParseFile(this: engine, a2: v35, a3: token, a4: 1024);
                      GoalID = (float)CAI_SchedulesManager::GetGoalID(this: v57, token);
                      tempTask[v15].flTaskData = GoalID;
                      if ( GoalID == -1.0 )
                      {
                        DevMsg(a1: "ERROR: LoadSchd (%s): (%s) Unknown goal type  %s!\n", prefix, v13->m_pName, token);
                        return 0;
                      }
                    }
                  }
                  else
                  {
                    v33 = engine->ParseFile(this: engine, a2: v19, a3: token, a4: 1024);
                    if ( _V_stricmp(s1: token, s2: ":") != 0 )
                    {
                      DevMsg(
                        a1: "ERROR: LoadSchd (%s): (%s) Malformed AI Schedule.  Expecting ':' after type 'PATH.\n",
                        prefix,
                        v13->m_pName);
                      return 0;
                    }
                    v19 = engine->ParseFile(this: engine, a2: v33, a3: token, a4: 1024);
                    PathID = (float)CAI_SchedulesManager::GetPathID(this: v57, token);
                    tempTask[v15].flTaskData = PathID;
                    if ( PathID == -1.0 )
                    {
                      DevMsg(a1: "ERROR: LoadSchd (%s): (%s) Unknown path type %s!\n", prefix, v13->m_pName, token);
                      return 0;
                    }
                  }
                }
                else
                {
                  v31 = engine->ParseFile(this: engine, a2: v19, a3: token, a4: 1024);
                  if ( _V_stricmp(s1: token, s2: ":") != 0 )
                  {
LABEL_86:
                    DevMsg(
                      a1: "ERROR: LoadSchd (%s): (%s) Malformed AI Schedule.  Expecting ':' after type 'STATE.\n",
                      prefix,
                      v13->m_pName);
                    return 0;
                  }
                  v19 = engine->ParseFile(this: engine, a2: v31, a3: token, a4: 1024);
                  MemoryID = (float)(int)CAI_SchedulesManager::GetMemoryID(this: v57, state_name: token);
                  tempTask[v15].flTaskData = MemoryID;
                  if ( MemoryID == -1.0 )
                  {
                    DevMsg(a1: "ERROR: LoadSchd %d (%s): (%s) Unknown shedule %s!\n", 381, prefix, v13->m_pName, token);
                    return 0;
                  }
                }
              }
              else
              {
                v29 = engine->ParseFile(this: engine, a2: v19, a3: token, a4: 1024);
                if ( _V_stricmp(s1: token, s2: ":") != 0 )
                  goto LABEL_86;
                v19 = engine->ParseFile(this: engine, a2: v29, a3: token, a4: 1024);
                StateID = (float)CAI_SchedulesManager::GetStateID(this: v57, state_name: token);
                tempTask[v15].flTaskData = StateID;
                if ( StateID == -1.0 )
                {
                  DevMsg(a1: "ERROR: LoadSchd %d (%s): (%s) Unknown shedule %s!\n", 359, prefix, v13->m_pName, token);
                  return 0;
                }
              }
            }
            else
            {
              v26 = engine->ParseFile(this: engine, a2: v19, a3: token, a4: 1024);
              if ( _V_stricmp(s1: token, s2: ":") != 0 )
              {
LABEL_85:
                DevMsg(
                  a1: "ERROR: LoadSchd (%s): (%s) Malformed AI Schedule.  Expecting ':' after type 'ACTIVITY.\n",
                  prefix,
                  v13->m_pName);
                return 0;
              }
              v19 = engine->ParseFile(this: engine, a2: v26, a3: token, a4: 1024);
              v27 = CAI_GlobalNamespace::SymbolToId(this: &pGlobalNamespace->m_ScheduleNamespace, pszSymbol: token);
              if ( pIdSpace != nullptr )
              {
                v28 = CAI_LocalIdSpace::GlobalToLocal(this: &pIdSpace->m_ScheduleIds, globalID: v27);
              }
              else if ( v27 == -1 )
              {
                v28 = -1;
              }
              else
              {
                v28 = v27 - 1000000000;
              }
              tempTask[v15].flTaskData = (float)v28;
              if ( (float)v28 == -1.0 )
              {
                DevMsg(a1: "ERROR: LoadSchd %d (%s): (%s) Unknown shedule %s!\n", 338, prefix, v13->m_pName, token);
                return 0;
              }
            }
          }
          else
          {
            v23 = engine->ParseFile(this: engine, a2: v19, a3: token, a4: 1024);
            if ( _V_stricmp(s1: token, s2: ":") != 0 )
              goto LABEL_85;
            v19 = engine->ParseFile(this: engine, a2: v23, a3: token, a4: 1024);
            v24 = CAI_GlobalNamespace::SymbolToId(this: &pGlobalNamespace->m_TaskNamespace, pszSymbol: token);
            if ( pIdSpace != nullptr )
            {
              v25 = CAI_LocalIdSpace::GlobalToLocal(this: &pIdSpace->m_TaskIds, globalID: v24);
            }
            else if ( v24 == -1 )
            {
              v25 = -1;
            }
            else
            {
              v25 = v24 - 1000000000;
            }
            tempTask[v15].flTaskData = (float)v25;
            if ( (float)v25 == -1.0 )
            {
LABEL_84:
              DevMsg(a1: "ERROR: LoadSchd (%s): (%s) Unknown task %s!\n", prefix, v13->m_pName, token);
              return 0;
            }
          }
        }
        else
        {
          v20 = engine->ParseFile(this: engine, a2: v19, a3: token, a4: 1024);
          if ( _V_stricmp(s1: token, s2: ":") != 0 )
            goto LABEL_85;
          v19 = engine->ParseFile(this: engine, a2: v20, a3: token, a4: 1024);
          ActivityID = (float)CAI_BaseNPC::GetActivityID(actName: token);
          tempTask[v15].flTaskData = ActivityID;
          if ( ActivityID == -1.0 )
          {
            DevMsg(a1: "ERROR: LoadSchd (%s): (%s) Unknown activity %s!\n", prefix, v13->m_pName, token);
            return 0;
          }
        }
        ++v15;
        V_strncpy(pDest: save_token, pSrc: token, maxLen: 1024);
        v16 = engine->ParseFile(this: engine, a2: v19, a3: token, a4: 1024);
        pfilea = v16;
        if ( _V_stricmp(s1: token, s2: ":") == 0 )
        {
          DevMsg(
            a1: "ERROR: LoadSchd (%s): Schedule (%s),\n        Task (%s), has a malformed AI Task Argument = (%s)\n",
            prefix,
            v13->m_pName,
            (const char *)taskID,
            save_token);
          return 0;
        }
        if ( token[0] == 0 )
          break;
      }
    }
    v13->m_iNumTasks = v15;
    v13->m_pTaskList = (Task_t *)operator new(nSize: 8 * v15);
    v39 = 0;
    if ( v15 >= 4 )
    {
      v55 = 16 - (_DWORD)&tempTask[0].flTaskData;
      taskID = 24 - (_DWORD)&tempTask[0].flTaskData;
      do
      {
        flTaskData = tempTask[v39].flTaskData;
        v13->m_pTaskList[v39].iTask = tempTask[v39].iTask;
        iTask = tempTask[v39 + 1].iTask;
        v13->m_pTaskList[v39].flTaskData = flTaskData;
        v42 = tempTask[v39 + 1].flTaskData;
        p_flTaskData = &tempTask[v39].flTaskData;
        v13->m_pTaskList[v39 + 1].iTask = iTask;
        v44 = *((_DWORD *)p_flTaskData + 3);
        v13->m_pTaskList[v39 + 1].flTaskData = v42;
        v45 = p_flTaskData[4];
        v39 += 4;
        *(int *)((char *)&v13->m_pTaskList->iTask + v55 + (unsigned int)p_flTaskData) = v44;
        v46 = *((_DWORD *)p_flTaskData + 5);
        *((float *)&v13->m_pTaskList[v39 - 1] - 1) = v45;
        v47 = p_flTaskData[6];
        *(int *)((char *)&v13->m_pTaskList->iTask + taskID + (unsigned int)p_flTaskData) = v46;
        v13->m_pTaskList[v39 - 1].flTaskData = v47;
      }
      while ( v39 < v15 - 3 );
      v16 = pfilea;
    }
    for ( ; v39 < v15; ++v39 )
    {
      v48 = tempTask[v39].flTaskData;
      v13->m_pTaskList[v39].iTask = tempTask[v39].iTask;
      v13->m_pTaskList[v39].flTaskData = v48;
    }
    for ( i = engine->ParseFile(this: engine, a2: v16, a3: token, a4: 1024);
          token[0] != 0;
          i = engine->ParseFile(this: engine, a2: i, a3: token, a4: 1024) )
    {
      if ( _V_stricmp(s1: "Schedule", s2: token) == 0 )
        break;
      v49 = CAI_GlobalNamespace::SymbolToId(this: &pGlobalNamespace->m_ConditionNamespace, pszSymbol: token);
      if ( v49 == -1 )
      {
        DevMsg(a1: "ERROR: LoadSchd (%s): Schedule (%s), Unknown condition %s!\n", prefix, v13->m_pName, token);
      }
      else
      {
        v50 = v49;
        v51 = &v13->m_InterruptMask.m_Ints[(v49 - 1000000000) >> 5];
        *v51 |= 1 << (v50 & 0x1F);
      }
    }
    if ( _V_stricmp(s1: "Schedule", s2: token) != 0 )
      return 1;
    v5 = v57;
  }
  while ( 1 )
  {
    m_pName = allSchedules->m_pName;
    if ( m_pName == token || _V_stricmp(s1: m_pName, s2: token) == 0 )
      break;
    allSchedules = allSchedules->nextSchedule;
    if ( allSchedules == nullptr )
      goto LABEL_6;
  }
  DevMsg(a1: "ERROR: file contains a schedule (%s) that has already been defined!\n", token);
  DevMsg(a1: "       Aborting schedule load.\n");
  return 0;
}
