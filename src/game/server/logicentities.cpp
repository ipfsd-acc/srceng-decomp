// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/logicentities.cpp
// Functions: 146
// ============================================================

#include "game\server\logicentities.h"

//------------------------------------------------------------------------------
// Address: 0x1001E6E0
// Name: public: void CEntityOutputTemplate<class CHandle<class CBaseEntity>,13>::Set(class CHandle<class CBaseEntity>,class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityOutputTemplate<CHandle<CBaseEntity>,13>::Set(
        CEntityOutputTemplate<CHandle<CBaseEntity>,13> *this,
        CHandle<CBaseEntity> value,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller)
{
  variant_t::Set(this: &this->m_Value, ftype: FIELD_EHANDLE, data: &value);
  CBaseEntityOutput::FireOutput(this, Value: this->m_Value, pActivator, pCaller, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101114E0
// Name: private: void CLogicCompare::InputSetValue(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCompare::InputSetValue(CEnvDOFController *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_flFocusTargetRange) = inputdata->value.iVal;
  else
    this->m_flFocusTargetRange = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10159480
// Name: int GlobalEntity_Add(char const __near *,char const __near *,enum GLOBALESTATE)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GlobalEntity_Add(const char *pGlobalname, const char *pMapName, GLOBALESTATE state)
{
  return CGlobalState::AddEntity(this: &gGlobalState, pGlobalname, pMapName, state);
}

//------------------------------------------------------------------------------
// Address: 0x10167D30
// Name: public: virtual struct datamap_t __near * CLogicScript::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicScript::GetDataDescMap(CLogicScript *this)
{
  return &CLogicScript::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10167D40
// Name: public: virtual struct datamap_t __near * CLogicCompareInteger::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicCompareInteger::GetDataDescMap(CLogicCompareInteger *this)
{
  return &CLogicCompareInteger::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10167D50
// Name: public: virtual struct datamap_t __near * CLogicRegisterActivator::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicRegisterActivator::GetDataDescMap(CLogicRegisterActivator *this)
{
  return &CLogicRegisterActivator::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10167D60
// Name: public: void CLogicRegisterActivator::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRegisterActivator::InputEnable(CLogicRegisterActivator *this, inputdata_t *inputdata)
{
  this->m_bDisabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x10167D70
// Name: public: void CLogicRegisterActivator::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRegisterActivator::InputDisable(CLogicRegisterActivator *this, inputdata_t *inputdata)
{
  this->m_bDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x10167D80
// Name: public: void CLogicRegisterActivator::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRegisterActivator::InputToggle(CLogicRegisterActivator *this, inputdata_t *inputdata)
{
  this->m_bDisabled = !this->m_bDisabled;
}

//------------------------------------------------------------------------------
// Address: 0x10167DA0
// Name: public: virtual struct datamap_t __near * CTimerEntity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTimerEntity::GetDataDescMap(CTimerEntity *this)
{
  return &CTimerEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10167DB0
// Name: public: void CTimerEntity::ResetTimer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimerEntity::ResetTimer(CTimerEntity *this)
{
  if ( this->m_iDisabled == 0 )
  {
    if ( this->m_iUseRandomTime != 0 )
      this->m_flRefireTime = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                               a1: random,
                               a2: LODWORD(this->m_flLowerRandomBound),
                               a3: LODWORD(this->m_flUpperRandomBound));
    CBaseEntity::SetNextThink(this, thinkTime: this->m_flRefireTime + gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167E20
// Name: public: void CTimerEntity::Enable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimerEntity::Enable(CTimerEntity *this)
{
  bool v2; // zf

  v2 = this->m_iUseRandomTime == 0;
  this->m_iDisabled = 0;
  if ( !v2 )
    this->m_flRefireTime = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                             a1: random,
                             a2: LODWORD(this->m_flLowerRandomBound),
                             a3: LODWORD(this->m_flUpperRandomBound));
  CBaseEntity::SetNextThink(this, thinkTime: this->m_flRefireTime + gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10167E90
// Name: public: void CTimerEntity::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimerEntity::InputEnable(CTimerEntity *this, inputdata_t *inputdata)
{
  bool v3; // zf

  v3 = this->m_iUseRandomTime == 0;
  this->m_iDisabled = 0;
  if ( !v3 )
    this->m_flRefireTime = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                             a1: random,
                             a2: LODWORD(this->m_flLowerRandomBound),
                             a3: LODWORD(this->m_flUpperRandomBound));
  CBaseEntity::SetNextThink(this, thinkTime: this->m_flRefireTime + gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10167F00
// Name: public: void CTimerEntity::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimerEntity::InputDisable(CTimerEntity *this, inputdata_t *inputdata)
{
  this->m_iDisabled = 1;
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10167F30
// Name: public: void CTimerEntity::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimerEntity::InputToggle(CTimerEntity *this, inputdata_t *inputdata)
{
  if ( this->m_iDisabled != 0 )
  {
    CTimerEntity::Enable(this);
  }
  else
  {
    this->m_iDisabled = 1;
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167F70
// Name: public: void CTimerEntity::InputResetTimer(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimerEntity::InputResetTimer(CTimerEntity *this, inputdata_t *inputdata)
{
  if ( this->m_iDisabled == 0 )
    CTimerEntity::ResetTimer(this);
}

//------------------------------------------------------------------------------
// Address: 0x10167F90
// Name: public: virtual int CTimerEntity::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTimerEntity::DrawDebugTextOverlays(CTimerEntity *this)
{
  int result; // eax
  int v3; // edi
  int v4; // edi
  double NextThink; // st7
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "refire interval: %.2f sec", this->m_flRefireTime);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v4 = v3 + 1;
    if ( this->m_iDisabled != 0 )
    {
      return v4;
    }
    else
    {
      NextThink = CBaseEntity::GetNextThink(this, szContext: nullptr);
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "      firing in: %.2f sec", NextThink - gpGlobals->curtime);
      CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      return v4 + 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10168090
// Name: public: virtual struct datamap_t __near * CLogicLineToEntity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicLineToEntity::GetDataDescMap(CLogicLineToEntity *this)
{
  return &CLogicLineToEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101680A0
// Name: public: virtual void CLogicLineToEntity::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicLineToEntity::Spawn(CLogicLineToEntity *this)
{
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.0099999998, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101680C0
// Name: public: virtual struct datamap_t __near * CMathRemap::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CMathRemap::GetDataDescMap(CMathRemap *this)
{
  return &CMathRemap::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101680D0
// Name: public: virtual void CMathRemap::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathRemap::Spawn(CMathRemap *this)
{
  float m_flInMin; // xmm0_4
  float m_flInMax; // xmm1_4

  if ( this->m_flInMin == this->m_flInMax )
  {
    this->m_flInMin = 0.0;
    this->m_flInMax = 1.0;
  }
  m_flInMin = this->m_flInMin;
  m_flInMax = this->m_flInMax;
  this->m_bEnabled = true;
  if ( m_flInMin > m_flInMax )
  {
    this->m_flInMin = m_flInMax;
    this->m_flInMax = m_flInMin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168130
// Name: public: virtual struct datamap_t __near * CMathColorBlend::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CMathColorBlend::GetDataDescMap(CMathColorBlend *this)
{
  return &CMathColorBlend::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10168140
// Name: public: virtual void CMathColorBlend::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathColorBlend::Spawn(CMathColorBlend *this)
{
  float m_flInMin; // xmm0_4
  float m_flInMax; // xmm1_4

  if ( this->m_flInMin == this->m_flInMax )
  {
    this->m_flInMin = 0.0;
    this->m_flInMax = 1.0;
  }
  m_flInMin = this->m_flInMin;
  m_flInMax = this->m_flInMax;
  if ( m_flInMin > m_flInMax )
  {
    this->m_flInMin = m_flInMax;
    this->m_flInMax = m_flInMin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101681A0
// Name: public: virtual struct datamap_t __near * CEnvGlobal::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvGlobal::GetDataDescMap(CEnvGlobal *this)
{
  return &CEnvGlobal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101681B0
// Name: public: virtual struct datamap_t __near * CMultiSource::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CMultiSource::GetDataDescMap(CMultiSource *this)
{
  return &CMultiSource::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101681C0
// Name: private: virtual struct datamap_t __near * CMathCounter::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CMathCounter::GetDataDescMap(CMathCounter *this)
{
  return &CMathCounter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101681D0
// Name: private: void CMathCounter::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::InputDisable(CMathCounter *this, inputdata_t *inputdata)
{
  this->m_bDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x101681E0
// Name: private: virtual struct datamap_t __near * CLogicCase::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicCase::GetDataDescMap(CLogicCase *this)
{
  return &CLogicCase::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101681F0
// Name: private: virtual void CLogicCase::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCase::Spawn(CLogicCase *this)
{
  this->m_nLastShuffleCase = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10168200
// Name: private: int CLogicCase::BuildCaseMap(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLogicCase::BuildCaseMap(CLogicCase *this, unsigned __int8 *puchCaseMap)
{
  int v2; // esi
  int v3; // ebx
  COutputEvent *m_OnCase; // edi

  *(_QWORD *)puchCaseMap = 0;
  v2 = 0;
  *((_QWORD *)puchCaseMap + 1) = 0;
  v3 = 0;
  m_OnCase = this->m_OnCase;
  do
  {
    if ( CBaseEntityOutput::NumberOfElements(this: m_OnCase) > 0 )
      puchCaseMap[v2++] = v3;
    ++v3;
    ++m_OnCase;
  }
  while ( v3 < 16 );
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10168250
// Name: private: void CLogicCase::InputPickRandom(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCase::InputPickRandom(CLogicCase *this, inputdata_t *inputdata)
{
  int v2; // esi
  int v3; // ebx
  COutputEvent *m_OnCase; // edi
  unsigned int v5; // eax
  const char *DebugName; // eax
  unsigned __int8 uchCaseMap[16]; // [esp+18h] [ebp-14h] BYREF
  CBaseEntity *pCaller; // [esp+28h] [ebp-4h]

  v2 = 0;
  pCaller = this;
  memset(uchCaseMap, 0, sizeof(uchCaseMap));
  v3 = 0;
  m_OnCase = this->m_OnCase;
  do
  {
    if ( CBaseEntityOutput::NumberOfElements(this: m_OnCase) > 0 )
      uchCaseMap[v2++] = v3;
    ++v3;
    ++m_OnCase;
  }
  while ( v3 < 16 );
  if ( v2 <= 0 )
  {
    DebugName = CBaseEntity::GetDebugName(this: pCaller);
    _DevMsg(a1: 1, a2: "Firing PickRandom input on logic_case %s with no cases set up\n", DebugName);
  }
  else
  {
    v5 = uchCaseMap[random->RandomInt(this: random, a2: 0, a3: v2 - 1)];
    if ( v5 < 0x10 )
      COutputEvent::FireOutput(
        this: (COutputEvent *)((char *)&pCaller[1].m_Network + 24 * v5 + 76),
        pActivator: inputdata->pActivator,
        pCaller,
        fDelay: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168300
// Name: private: void CLogicCase::InputPickRandomShuffle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCase::InputPickRandomShuffle(CLogicCase *this, inputdata_t *inputdata)
{
  int m_nShuffleCases; // eax
  bool v4; // cc
  unsigned __int8 *m_uchShuffleCaseMap; // edi
  int m_nLastShuffleCase; // edx
  int v7; // ecx
  unsigned __int8 v8; // dl
  int v9; // ebx
  unsigned int v10; // edi
  const char *DebugName; // eax

  m_nShuffleCases = this->m_nShuffleCases;
  v4 = m_nShuffleCases <= 0;
  if ( m_nShuffleCases == 0 )
  {
    m_uchShuffleCaseMap = this->m_uchShuffleCaseMap;
    m_nShuffleCases = CLogicCase::BuildCaseMap(this, puchCaseMap: this->m_uchShuffleCaseMap);
    this->m_nShuffleCases = m_nShuffleCases;
    if ( m_nShuffleCases > 1 )
    {
      m_nLastShuffleCase = this->m_nLastShuffleCase;
      if ( m_nLastShuffleCase != -1 )
      {
        v7 = 0;
        while ( m_uchShuffleCaseMap[v7] != m_nLastShuffleCase )
        {
          if ( ++v7 >= m_nShuffleCases )
            goto LABEL_9;
        }
        v8 = this->m_uchShuffleCaseMap[v7];
        this->m_uchShuffleCaseMap[v7] = *((_BYTE *)&this->m_nLastShuffleCase + m_nShuffleCases + 3);
        *((_BYTE *)&this->m_nLastShuffleCase + m_nShuffleCases + 3) = v8;
        --m_nShuffleCases;
      }
    }
LABEL_9:
    v4 = m_nShuffleCases <= 0;
  }
  if ( v4 )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 1, a2: "Firing PickRandom input on logic_case %s with no cases set up\n", DebugName);
  }
  else
  {
    v9 = random->RandomInt(this: random, a2: 0, a3: m_nShuffleCases - 1);
    v10 = this->m_uchShuffleCaseMap[v9];
    if ( v10 < 0x10 )
      COutputEvent::FireOutput(
        this: &this->m_OnCase[v10],
        pActivator: inputdata->pActivator,
        pCaller: this,
        fDelay: 0.0);
    this->m_uchShuffleCaseMap[v9] = *((_BYTE *)&this->m_nLastShuffleCase + this->m_nShuffleCases-- + 3);
    this->m_nLastShuffleCase = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168400
// Name: private: virtual struct datamap_t __near * CLogicCompare::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicCompare::GetDataDescMap(CLogicCompare *this)
{
  return &CLogicCompare::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10168410
// Name: public: virtual int CLogicCompare::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLogicCompare::DrawDebugTextOverlays(CLogicCompare *this)
{
  int result; // eax
  int v3; // esi
  int v4; // esi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    Initial Value: %f", this->m_flInValue);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v4 = v3 + 1;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    Compare Value: %f", this->m_flCompareValue);
    CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v4 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101684F0
// Name: private: virtual struct datamap_t __near * CLogicBranch::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicBranch::GetDataDescMap(CLogicBranch *this)
{
  return &CLogicBranch::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10168500
// Name: public: virtual int CLogicBranch::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLogicBranch::DrawDebugTextOverlays(CLogicBranch *this)
{
  int result; // eax
  int v3; // esi
  const char *v4; // eax
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    v4 = "TRUE";
    if ( !this->m_bInValue )
      v4 = "FALSE";
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Branch value: %s", v4);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10168580
// Name: protected: virtual struct datamap_t __near * CLogicAutosave::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicAutosave::GetDataDescMap(CLogicAutosave *this)
{
  return &CLogicAutosave::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10168590
// Name: protected: void CLogicAutosave::InputSave(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicAutosave::InputSave(CLogicAutosave *this, inputdata_t *inputdata)
{
  if ( this->m_bForceNewLevelUnit )
    engine->ClearSaveDir(this: engine);
  engine->ServerCommand(this: engine, a2: "autosave\n");
}

//------------------------------------------------------------------------------
// Address: 0x101685D0
// Name: private: virtual struct datamap_t __near * CLogicActiveAutosave::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicActiveAutosave::GetDataDescMap(CLogicActiveAutosave *this)
{
  return &CLogicActiveAutosave::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101685E0
// Name: public: virtual struct datamap_t __near * CLogicCollisionPair::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicCollisionPair::GetDataDescMap(CLogicCollisionPair *this)
{
  return &CLogicCollisionPair::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101685F0
// Name: private: virtual struct datamap_t __near * CLogicBranchList::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicBranchList::GetDataDescMap(CLogicBranchList *this)
{
  return &CLogicBranchList::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10168600
// Name: int GlobalEntity_Add(struct string_t,struct string_t,enum GLOBALESTATE)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GlobalEntity_Add(string_t globalname, string_t mapName, GLOBALESTATE state)
{
  const char *pszValue; // ecx
  const char *v4; // eax

  pszValue = mapName.pszValue;
  if ( mapName.pszValue == nullptr )
    pszValue = locale;
  v4 = globalname.pszValue;
  if ( globalname.pszValue == nullptr )
    v4 = locale;
  return GlobalEntity_Add(pGlobalname: v4, pMapName: pszValue, state);
}

//------------------------------------------------------------------------------
// Address: 0x10168630
// Name: public: void CLogicCompareInteger::InputCompareValues(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCompareInteger::InputCompareValues(CLogicCompareInteger *this, inputdata_t *inputdata)
{
  bool v2; // zf
  CMultiInputVar::inputitem_t *m_InputList; // eax
  int m_iIntegerValue; // esi
  int v5; // edx

  v2 = this->m_iShouldCompareToValue == 0;
  m_InputList = this->m_AllIntCompares.m_InputList;
  m_iIntegerValue = this->m_iIntegerValue;
  this->m_AllIntCompares.m_bUpdatedThisFrame = 0;
  if ( v2 )
  {
    if ( m_InputList == nullptr )
    {
LABEL_12:
      COutputEvent::FireOutput(this: &this->m_OnEqual, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
      return;
    }
    if ( m_InputList->value.fieldType == FIELD_INTEGER )
      m_iIntegerValue = m_InputList->value.iVal;
    else
      m_iIntegerValue = 0;
  }
  if ( m_InputList == nullptr )
    goto LABEL_12;
  while ( 1 )
  {
    v5 = m_InputList->value.fieldType == FIELD_INTEGER ? m_InputList->value.iVal : 0;
    if ( v5 != m_iIntegerValue )
      break;
    m_InputList = m_InputList->next;
    if ( m_InputList == nullptr )
      goto LABEL_12;
  }
  COutputEvent::FireOutput(this: &this->m_OnNotEqual, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101686C0
// Name: public: void CLogicRegisterActivator::InputRegisterEntity(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRegisterActivator::InputRegisterEntity(CLogicRegisterActivator *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  CBaseEntity *EntityByName; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
      iVal = locale;
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: iVal,
                   pSearchingEntity: this,
                   pActivator: inputdata->pActivator,
                   pCaller: inputdata->pCaller,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hRegisteredEntity.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hRegisteredEntity.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10168730
// Name: public: void CLogicRegisterActivator::InputFireRegisteredAsActivator1(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRegisterActivator::InputFireRegisteredAsActivator1(
        CLogicRegisterActivator *this,
        inputdata_t *inputdata)
{
  unsigned int m_Index; // edx
  int v3; // eax
  CEntInfo *v4; // esi
  unsigned int v5; // edx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // eax

  if ( !this->m_bDisabled )
  {
    m_Index = this->m_hRegisteredEntity.m_Index;
    if ( m_Index != -1 )
    {
      v3 = (unsigned __int16)m_Index;
      v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v5 = HIWORD(m_Index);
      if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
      {
        v6 = v3;
        v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
        v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
        if ( v7 )
          v9 = *v8;
        else
          v9 = nullptr;
        COutputEvent::FireOutput(this: &this->m_OnRegisteredActivate1, pActivator: v9, pCaller: this, fDelay: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101687A0
// Name: public: void CLogicRegisterActivator::InputFireRegisteredAsActivator2(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRegisterActivator::InputFireRegisteredAsActivator2(
        CLogicRegisterActivator *this,
        inputdata_t *inputdata)
{
  unsigned int m_Index; // edx
  int v3; // eax
  CEntInfo *v4; // esi
  unsigned int v5; // edx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // eax

  if ( !this->m_bDisabled )
  {
    m_Index = this->m_hRegisteredEntity.m_Index;
    if ( m_Index != -1 )
    {
      v3 = (unsigned __int16)m_Index;
      v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v5 = HIWORD(m_Index);
      if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
      {
        v6 = v3;
        v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
        v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
        if ( v7 )
          v9 = *v8;
        else
          v9 = nullptr;
        COutputEvent::FireOutput(this: &this->m_OnRegisteredActivate2, pActivator: v9, pCaller: this, fDelay: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168810
// Name: public: void CLogicRegisterActivator::InputFireRegisteredAsActivator3(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRegisterActivator::InputFireRegisteredAsActivator3(
        CLogicRegisterActivator *this,
        inputdata_t *inputdata)
{
  unsigned int m_Index; // edx
  int v3; // eax
  CEntInfo *v4; // esi
  unsigned int v5; // edx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // eax

  if ( !this->m_bDisabled )
  {
    m_Index = this->m_hRegisteredEntity.m_Index;
    if ( m_Index != -1 )
    {
      v3 = (unsigned __int16)m_Index;
      v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v5 = HIWORD(m_Index);
      if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
      {
        v6 = v3;
        v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
        v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
        if ( v7 )
          v9 = *v8;
        else
          v9 = nullptr;
        COutputEvent::FireOutput(this: &this->m_OnRegisteredActivate3, pActivator: v9, pCaller: this, fDelay: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168880
// Name: public: void CLogicRegisterActivator::InputFireRegisteredAsActivator4(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRegisterActivator::InputFireRegisteredAsActivator4(
        CLogicRegisterActivator *this,
        inputdata_t *inputdata)
{
  unsigned int m_Index; // edx
  int v3; // eax
  CEntInfo *v4; // esi
  unsigned int v5; // edx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // eax

  if ( !this->m_bDisabled )
  {
    m_Index = this->m_hRegisteredEntity.m_Index;
    if ( m_Index != -1 )
    {
      v3 = (unsigned __int16)m_Index;
      v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v5 = HIWORD(m_Index);
      if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
      {
        v6 = v3;
        v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
        v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
        if ( v7 )
          v9 = *v8;
        else
          v9 = nullptr;
        COutputEvent::FireOutput(this: &this->m_OnRegisteredActivate4, pActivator: v9, pCaller: this, fDelay: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101688F0
// Name: public: virtual void CTimerEntity::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimerEntity::Spawn(CTimerEntity *this)
{
  int m_iUseRandomTime; // eax

  m_iUseRandomTime = this->m_iUseRandomTime;
  if ( m_iUseRandomTime == 0 && this->m_flRefireTime < 0.0099999998 )
    this->m_flRefireTime = 0.0099999998;
  if ( this->m_iDisabled != 0 || this->m_flRefireTime <= 0.0 && m_iUseRandomTime == 0 )
  {
    this->m_iDisabled = 1;
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
  else
  {
    CTimerEntity::Enable(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168960
// Name: public: void CTimerEntity::FireTimer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimerEntity::FireTimer(CTimerEntity *this)
{
  COutputEvent *p_m_OnTimerHigh; // ecx

  if ( this->m_iDisabled == 0 )
  {
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      p_m_OnTimerHigh = &this->m_OnTimerHigh;
      if ( !this->m_bUpDownState )
        p_m_OnTimerHigh = &this->m_OnTimerLow;
      COutputEvent::FireOutput(this: p_m_OnTimerHigh, pActivator: this, pCaller: this, fDelay: 0.0);
      this->m_bUpDownState = !this->m_bUpDownState;
      CTimerEntity::ResetTimer(this);
    }
    else
    {
      COutputEvent::FireOutput(this: &this->m_OnTimer, pActivator: this, pCaller: this, fDelay: 0.0);
      CTimerEntity::ResetTimer(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101689D0
// Name: public: void CTimerEntity::InputFireTimer(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CTimerEntity::InputFireTimer(CTimerEntity *this, inputdata_t *inputdata)
{
  CTimerEntity::FireTimer(this);
}

//------------------------------------------------------------------------------
// Address: 0x101689E0
// Name: public: void CTimerEntity::InputRefireTime(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimerEntity::InputRefireTime(CTimerEntity *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4

  if ( inputdata->value.fieldType != FIELD_FLOAT || (flVal = inputdata->value.flVal) < 0.0099999998 )
    flVal = 0.0099999998;
  if ( this->m_flRefireTime != flVal )
  {
    this->m_flRefireTime = flVal;
    CTimerEntity::ResetTimer(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168A30
// Name: public: void CTimerEntity::InputAddToTimer(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimerEntity::InputAddToTimer(CTimerEntity *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  float flNextThink; // [esp+Ch] [ebp-4h]

  if ( this->m_iDisabled == 0 )
  {
    flNextThink = CBaseEntity::GetNextThink(this, szContext: nullptr);
    if ( inputdata->value.fieldType == FIELD_FLOAT )
      flVal = inputdata->value.flVal;
    else
      flVal = 0.0;
    CBaseEntity::SetNextThink(this, thinkTime: flVal + flNextThink, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168A80
// Name: public: void CTimerEntity::InputSubtractFromTimer(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimerEntity::InputSubtractFromTimer(CTimerEntity *this, inputdata_t *inputdata)
{
  _fieldtypes fieldType; // eax
  float flVal; // xmm2_4
  float thinkTime; // xmm1_4
  float v6; // xmm1_4
  float flNextThink; // [esp+Ch] [ebp-4h]

  if ( this->m_iDisabled == 0 )
  {
    flNextThink = CBaseEntity::GetNextThink(this, szContext: nullptr);
    fieldType = inputdata->value.fieldType;
    if ( fieldType == FIELD_FLOAT )
      flVal = inputdata->value.flVal;
    else
      flVal = 0.0;
    thinkTime = gpGlobals->curtime;
    if ( flVal < (float)(flNextThink - thinkTime) )
    {
      if ( fieldType == FIELD_FLOAT )
        v6 = inputdata->value.flVal;
      else
        v6 = 0.0;
      CBaseEntity::SetNextThink(this, thinkTime: flNextThink - v6, szContext: nullptr);
    }
    else
    {
      CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168B10
// Name: void CC_Global_Set(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Global_Set(const CCommand *args)
{
  const char *v1; // esi
  const char *v2; // eax
  GLOBALESTATE v3; // edi
  int Index; // eax
  const char *pszValue; // eax

  v1 = locale;
  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  if ( args->m_nArgc > 2 )
    v2 = args->m_ppArgv[2];
  else
    v2 = locale;
  if ( v1 != nullptr && v2 != nullptr )
  {
    v3 = atoi(nptr: v2);
    Index = GlobalEntity_GetIndex(pGlobalname: v1);
    if ( Index < 0 )
    {
      pszValue = gpGlobals->mapname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      GlobalEntity_Add(pGlobalname: v1, pMapName: pszValue, state: v3);
    }
    else
    {
      GlobalEntity_SetState(globalIndex: Index, state: v3);
    }
  }
  else
  {
    _Msg(a1: "Usage: global_set <globalname> <state>: Sets the state of the given env_global (0 = OFF, 1 = ON, 2 = DEAD).\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168BA0
// Name: public: virtual void CEnvGlobal::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGlobal::Spawn(CEnvGlobal *this)
{
  const char *pszValue; // eax
  const char *v3; // ecx
  int m_counter; // eax
  const char *v5; // esi
  int Index; // eax
  int v7; // [esp-4h] [ebp-8h]

  if ( this->m_globalstate.pszValue != nullptr )
  {
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      if ( GlobalEntity_GetIndex(pGlobalname: this->m_globalstate.pszValue) < 0 )
      {
        pszValue = gpGlobals->mapname.pszValue;
        v3 = this->m_globalstate.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        if ( v3 == nullptr )
          v3 = locale;
        GlobalEntity_Add(pGlobalname: v3, pMapName: pszValue, state: (GLOBALESTATE)this->m_initialstate);
      }
      m_counter = this->m_counter;
      if ( m_counter != 0 )
      {
        v5 = this->m_globalstate.pszValue;
        if ( v5 == nullptr )
          v5 = locale;
        v7 = m_counter;
        Index = GlobalEntity_GetIndex(pGlobalname: v5);
        GlobalEntity_SetCounter(globalIndex: Index, counter: v7);
      }
    }
  }
  else
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168C30
// Name: public: void CEnvGlobal::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGlobal::InputTurnOn(CEnvGlobal *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  const char *v4; // esi
  int Index; // eax
  const char *v6; // eax
  const char *v7; // ecx

  pszValue = this->m_globalstate.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( GlobalEntity_GetIndex(pGlobalname: pszValue) < 0 )
  {
    v6 = gpGlobals->mapname.pszValue;
    v7 = this->m_globalstate.pszValue;
    if ( v6 == nullptr )
      v6 = locale;
    if ( v7 == nullptr )
      v7 = locale;
    GlobalEntity_Add(pGlobalname: v7, pMapName: v6, state: GLOBAL_ON);
  }
  else
  {
    v4 = this->m_globalstate.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    Index = GlobalEntity_GetIndex(pGlobalname: v4);
    GlobalEntity_SetState(globalIndex: Index, state: GLOBAL_ON);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168CB0
// Name: public: void CEnvGlobal::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGlobal::InputTurnOff(CEnvGlobal *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  const char *v4; // esi
  int Index; // eax
  const char *v6; // eax
  const char *v7; // ecx

  pszValue = this->m_globalstate.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( GlobalEntity_GetIndex(pGlobalname: pszValue) < 0 )
  {
    v6 = gpGlobals->mapname.pszValue;
    v7 = this->m_globalstate.pszValue;
    if ( v6 == nullptr )
      v6 = locale;
    if ( v7 == nullptr )
      v7 = locale;
    GlobalEntity_Add(pGlobalname: v7, pMapName: v6, state: GLOBAL_OFF);
  }
  else
  {
    v4 = this->m_globalstate.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    Index = GlobalEntity_GetIndex(pGlobalname: v4);
    GlobalEntity_SetState(globalIndex: Index, state: GLOBAL_OFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168D30
// Name: public: void CEnvGlobal::InputRemove(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGlobal::InputRemove(CEnvGlobal *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  const char *v4; // esi
  int Index; // eax
  const char *v6; // eax
  const char *v7; // ecx

  pszValue = this->m_globalstate.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( GlobalEntity_GetIndex(pGlobalname: pszValue) < 0 )
  {
    v6 = gpGlobals->mapname.pszValue;
    v7 = this->m_globalstate.pszValue;
    if ( v6 == nullptr )
      v6 = locale;
    if ( v7 == nullptr )
      v7 = locale;
    GlobalEntity_Add(pGlobalname: v7, pMapName: v6, state: GLOBAL_DEAD);
  }
  else
  {
    v4 = this->m_globalstate.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    Index = GlobalEntity_GetIndex(pGlobalname: v4);
    GlobalEntity_SetState(globalIndex: Index, state: GLOBAL_DEAD);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168DB0
// Name: public: void CEnvGlobal::InputSetCounter(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGlobal::InputSetCounter(CEnvGlobal *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  const char *v4; // eax
  const char *v5; // ecx
  const char *v6; // ecx
  const char *v7; // eax
  int Index; // eax
  int v9; // [esp+0h] [ebp-4h]

  pszValue = this->m_globalstate.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( GlobalEntity_GetIndex(pGlobalname: pszValue) < 0 )
  {
    v4 = gpGlobals->mapname.pszValue;
    v5 = this->m_globalstate.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    if ( v5 == nullptr )
      v5 = locale;
    GlobalEntity_Add(pGlobalname: v5, pMapName: v4, state: GLOBAL_ON);
  }
  if ( inputdata->value.fieldType == FIELD_INTEGER )
    v6 = inputdata->value.iszVal.pszValue;
  else
    v6 = nullptr;
  v7 = this->m_globalstate.pszValue;
  if ( v7 == nullptr )
    v7 = locale;
  v9 = (int)v6;
  Index = GlobalEntity_GetIndex(pGlobalname: v7);
  GlobalEntity_SetCounter(globalIndex: Index, counter: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10168E40
// Name: public: void CEnvGlobal::InputAddToCounter(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGlobal::InputAddToCounter(CEnvGlobal *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  const char *v4; // eax
  const char *v5; // ecx
  const char *v6; // edi
  const char *v7; // eax
  int Index; // eax

  pszValue = this->m_globalstate.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( GlobalEntity_GetIndex(pGlobalname: pszValue) < 0 )
  {
    v4 = gpGlobals->mapname.pszValue;
    v5 = this->m_globalstate.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    if ( v5 == nullptr )
      v5 = locale;
    GlobalEntity_Add(pGlobalname: v5, pMapName: v4, state: GLOBAL_ON);
  }
  if ( inputdata->value.fieldType == FIELD_INTEGER )
    v6 = inputdata->value.iszVal.pszValue;
  else
    v6 = nullptr;
  v7 = this->m_globalstate.pszValue;
  if ( v7 == nullptr )
    v7 = locale;
  Index = GlobalEntity_GetIndex(pGlobalname: v7);
  GlobalEntity_AddToCounter(globalIndex: Index, delta: (int)v6);
}

//------------------------------------------------------------------------------
// Address: 0x10168ED0
// Name: public: void CEnvGlobal::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGlobal::InputToggle(CEnvGlobal *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  int Index; // eax
  GLOBALESTATE State; // eax
  GLOBALESTATE v6; // edi
  const char *v7; // eax
  const char *v8; // esi
  int v9; // eax
  const char *v10; // eax
  const char *v11; // ecx

  pszValue = this->m_globalstate.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  Index = GlobalEntity_GetIndex(pGlobalname: pszValue);
  State = GlobalEntity_GetState(globalIndex: Index);
  if ( State == GLOBAL_ON )
  {
    v6 = GLOBAL_OFF;
  }
  else
  {
    if ( State != GLOBAL_OFF )
      return;
    v6 = GLOBAL_ON;
  }
  v7 = this->m_globalstate.pszValue;
  if ( v7 == nullptr )
    v7 = locale;
  if ( GlobalEntity_GetIndex(pGlobalname: v7) < 0 )
  {
    v10 = gpGlobals->mapname.pszValue;
    v11 = this->m_globalstate.pszValue;
    if ( v10 == nullptr )
      v10 = locale;
    if ( v11 == nullptr )
      v11 = locale;
    GlobalEntity_Add(pGlobalname: v11, pMapName: v10, state: v6);
  }
  else
  {
    v8 = this->m_globalstate.pszValue;
    if ( v8 == nullptr )
      v8 = locale;
    v9 = GlobalEntity_GetIndex(pGlobalname: v8);
    GlobalEntity_SetState(globalIndex: v9, state: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168F80
// Name: public: virtual int CEnvGlobal::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEnvGlobal::DrawDebugTextOverlays(CEnvGlobal *this)
{
  int result; // eax
  int v3; // edi
  const char *pszValue; // eax
  const char *v5; // eax
  int v6; // edi
  int Index; // eax
  GLOBALESTATE State; // eax
  __int32 v9; // eax
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    pszValue = this->m_globalstate.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "State: %s", pszValue);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v5 = this->m_globalstate.pszValue;
    v6 = v3 + 1;
    if ( v5 == nullptr )
      v5 = locale;
    Index = GlobalEntity_GetIndex(pGlobalname: v5);
    State = GlobalEntity_GetState(globalIndex: Index);
    if ( State != GLOBAL_OFF )
    {
      v9 = State - 1;
      if ( v9 != 0 )
      {
        if ( v9 == 1 )
          V_strncpy(pDest: tempstr, pSrc: "Value: DEAD", maxLen: 512);
      }
      else
      {
        V_strncpy(pDest: tempstr, pSrc: "Value: ON", maxLen: 512);
      }
    }
    else
    {
      V_strncpy(pDest: tempstr, pSrc: "Value: OFF", maxLen: 512);
    }
    CBaseEntity::EntityText(this, text_offset: v6, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v6 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101690A0
// Name: public: virtual bool CMultiSource::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMultiSource::KeyValue(CMultiSource *this, const char *szKeyName, const char *szValue)
{
  return szKeyName == "style"
      || _V_stricmp(s1: szKeyName, s2: "style") == 0
      || szKeyName == "height"
      || _V_stricmp(s1: szKeyName, s2: "height") == 0
      || szKeyName == "killtarget"
      || _V_stricmp(s1: szKeyName, s2: "killtarget") == 0
      || szKeyName == "value1"
      || _V_stricmp(s1: szKeyName, s2: "value1") == 0
      || szKeyName == "value2"
      || _V_stricmp(s1: szKeyName, s2: "value2") == 0
      || FStrEq(sz1: szKeyName, sz2: "value3")
      || CServerOnlyPointEntity::KeyValue(this, szKeyName, szValue);
}

//------------------------------------------------------------------------------
// Address: 0x10169170
// Name: public: virtual bool CMultiSource::IsTriggered(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMultiSource::IsTriggered(CMultiSource *this, CBaseEntity *__formal)
{
  int v2; // eax
  int m_iTotal; // esi
  int *m_rgTriggered; // edx
  int Index; // eax

  v2 = 0;
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    return 0;
  m_iTotal = this->m_iTotal;
  if ( m_iTotal > 0 )
  {
    m_rgTriggered = this->m_rgTriggered;
    do
    {
      if ( *m_rgTriggered == 0 )
        break;
      ++v2;
      ++m_rgTriggered;
    }
    while ( v2 < m_iTotal );
  }
  if ( v2 != m_iTotal )
    return 0;
  if ( this->m_globalstate.pszValue != nullptr
    && (Index = GlobalEntity_GetIndex(pGlobalname: this->m_globalstate.pszValue),
        GlobalEntity_GetState(globalIndex: Index) != GLOBAL_ON) )
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101691D0
// Name: private: virtual bool CMathCounter::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMathCounter::KeyValue(CMathCounter *this, const char *szKeyName, float szValue)
{
  if ( _V_stricmp(s1: szKeyName, s2: "startvalue") != 0 )
    return CServerOnlyPointEntity::KeyValue(this, szKeyName, szValue: (const char *)LODWORD(szValue));
  szValue = (float)atoi(nptr: (const char *)LODWORD(szValue));
  variant_t::Set(this: &this->m_OutValue.m_Value, ftype: FIELD_FLOAT, data: &szValue);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10169230
// Name: private: virtual void CMathCounter::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::Spawn(CMathCounter *this)
{
  float m_flMin; // xmm0_4
  float m_flMax; // xmm1_4
  float flVal; // xmm0_4
  float v4; // xmm1_4
  CMathCounter *data; // [esp+0h] [ebp-4h] BYREF

  data = this;
  m_flMin = this->m_flMin;
  m_flMax = this->m_flMax;
  if ( m_flMin > m_flMax )
  {
    this->m_flMax = m_flMin;
    this->m_flMin = m_flMax;
  }
  if ( this->m_flMin != 0.0 || this->m_flMax != 0.0 )
  {
    flVal = this->m_OutValue.m_Value.flVal;
    v4 = this->m_flMin;
    if ( v4 > flVal || (v4 = this->m_flMax, flVal > v4) )
      flVal = v4;
    data = (CMathCounter *)LODWORD(flVal);
    variant_t::Set(this: &this->m_OutValue.m_Value, ftype: FIELD_FLOAT, &data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101692C0
// Name: private: virtual int CMathCounter::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMathCounter::DrawDebugTextOverlays(CMathCounter *this)
{
  int result; // eax
  int v3; // edi
  int v4; // edi
  int v5; // edi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    min value: %f", this->m_flMin);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v4 = v3 + 1;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    max value: %f", this->m_flMax);
    CBaseEntity::EntityText(this, text_offset: v4++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "current value: %f", this->m_OutValue.m_Value.flVal);
    CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v5 = v4 + 1;
    if ( this->m_bDisabled )
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "*DISABLED*");
    else
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Enabled.");
    CBaseEntity::EntityText(this, text_offset: v5, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v5 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10169460
// Name: private: void CMathCounter::InputSetValueNoFire(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::InputSetValueNoFire(CMathCounter *this, float inputdata)
{
  const char *DebugName; // eax
  float v3; // xmm0_4
  float m_flMin; // xmm1_4

  if ( this->m_bDisabled )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "Math Counter %s ignoring SETVALUENOFIRE because it is disabled\n", DebugName);
  }
  else
  {
    if ( *(_DWORD *)(LODWORD(inputdata) + 24) == 1 )
      v3 = *(float *)(LODWORD(inputdata) + 8);
    else
      v3 = 0.0;
    if ( this->m_flMin != 0.0 || this->m_flMax != 0.0 )
    {
      m_flMin = this->m_flMin;
      if ( m_flMin > v3 || (m_flMin = this->m_flMax, v3 > m_flMin) )
        v3 = m_flMin;
    }
    inputdata = v3;
    variant_t::Set(this: &this->m_OutValue.m_Value, ftype: FIELD_FLOAT, data: &inputdata);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169500
// Name: private: void CMathCounter::InputSetMaxValueNoFire(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::InputSetMaxValueNoFire(CMathCounter *this, float inputdata)
{
  const char *DebugName; // eax
  float v3; // xmm1_4
  float m_flMin; // xmm2_4
  const char *v5; // eax
  float flVal; // xmm0_4
  float m_flMax; // xmm1_4

  if ( this->m_bDisabled )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "Math Counter %s ignoring SETMAXVALUENOFIRE because it is disabled\n", DebugName);
  }
  else
  {
    if ( *(_DWORD *)(LODWORD(inputdata) + 24) == 1 )
      v3 = *(float *)(LODWORD(inputdata) + 8);
    else
      v3 = 0.0;
    m_flMin = this->m_flMin;
    if ( m_flMin <= v3 )
    {
      flVal = this->m_OutValue.m_Value.flVal;
      this->m_flMax = v3;
      if ( m_flMin != 0.0 || v3 != 0.0 )
      {
        m_flMax = this->m_flMin;
        if ( m_flMax > flVal || (m_flMax = this->m_flMax, flVal > m_flMax) )
          flVal = m_flMax;
      }
      inputdata = flVal;
      variant_t::Set(this: &this->m_OutValue.m_Value, ftype: FIELD_FLOAT, data: &inputdata);
    }
    else
    {
      v5 = CBaseEntity::GetDebugName(this);
      DevMsg(a1: "Math Counter %s ignoring SETMAXVALUENOFIRE because the value is less than the Minimum Value!\n", v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101695C0
// Name: private: void CMathCounter::InputSetMinValueNoFire(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::InputSetMinValueNoFire(CMathCounter *this, float inputdata)
{
  const char *DebugName; // eax
  float v3; // xmm1_4
  float m_flMax; // xmm3_4
  const char *v5; // eax
  float flVal; // xmm0_4

  if ( this->m_bDisabled )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "Math Counter %s ignoring SETMINVALUENOFIRE because it is disabled\n", DebugName);
  }
  else
  {
    if ( *(_DWORD *)(LODWORD(inputdata) + 24) == 1 )
      v3 = *(float *)(LODWORD(inputdata) + 8);
    else
      v3 = 0.0;
    m_flMax = this->m_flMax;
    if ( v3 <= m_flMax )
    {
      flVal = this->m_OutValue.m_Value.flVal;
      this->m_flMin = v3;
      if ( v3 != 0.0 || m_flMax != 0.0 )
      {
        if ( v3 > flVal || (v3 = this->m_flMax, flVal > v3) )
          flVal = v3;
      }
      inputdata = flVal;
      variant_t::Set(this: &this->m_OutValue.m_Value, ftype: FIELD_FLOAT, data: &inputdata);
    }
    else
    {
      v5 = CBaseEntity::GetDebugName(this);
      DevMsg(
        a1: "Math Counter %s ignoring SETMINVALUENOFIRE because the value is greater than the Maximum Value!\n",
        v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101696A0
// Name: protected: void CLogicAutosave::InputSetMinHitpointsThreshold(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicAutosave::InputSetMinHitpointsThreshold(CGameWeaponManager *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_INTEGER )
    this->m_iMaxPieces = inputdata->value.iVal;
  else
    this->m_iMaxPieces = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101696D0
// Name: public: void CLogicCollisionPair::EnableCollisions(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCollisionPair::EnableCollisions(CLogicCollisionPair *this, bool bEnable)
{
  const char *pszValue; // edi
  IPhysicsObject *v4; // edx
  IPhysicsObject *PhysicsObjectByName; // ebx
  const char *v6; // eax
  const char *v7; // edi
  IPhysicsObject *v8; // eax
  IPhysicsObject *v9; // ebx
  const char *v10; // eax
  IPhysicsObject *pPhysics0; // [esp+Ch] [ebp-4h]

  pszValue = this->m_nameAttach1.pszValue;
  if ( pszValue != nullptr )
  {
    PhysicsObjectByName = FindPhysicsObjectByName(pName: pszValue, pErrorEntity: this);
    if ( PhysicsObjectByName == nullptr )
    {
      v6 = this->m_iClassname.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      DevWarning(a1: "%s: can't find %s\n", v6, pszValue);
    }
    pPhysics0 = PhysicsObjectByName;
    v4 = PhysicsObjectByName;
  }
  else
  {
    v4 = g_PhysWorldObject;
    pPhysics0 = g_PhysWorldObject;
  }
  v7 = this->m_nameAttach2.pszValue;
  if ( v7 != nullptr )
  {
    v9 = FindPhysicsObjectByName(pName: v7, pErrorEntity: this);
    if ( v9 == nullptr )
    {
      v10 = this->m_iClassname.pszValue;
      if ( v10 == nullptr )
        v10 = locale;
      DevWarning(a1: "%s: can't find %s\n", v10, v7);
    }
    v4 = pPhysics0;
    v8 = v9;
  }
  else
  {
    v8 = g_PhysWorldObject;
  }
  if ( v4 != nullptr && v8 != nullptr && v4 != v8 )
  {
    this->m_disabled = !bEnable;
    this->m_succeeded = true;
    if ( bEnable )
      PhysEnableEntityCollisions(pObject0: v4, pObject1: v8);
    else
      PhysDisableEntityCollisions(pObject0: v4, pObject1: v8);
  }
  else
  {
    this->m_succeeded = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101697C0
// Name: public: void CLogicCollisionPair::InputDisableCollisions(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCollisionPair::InputDisableCollisions(CLogicCollisionPair *this, inputdata_t *inputdata)
{
  if ( !this->m_succeeded || !this->m_disabled )
    CLogicCollisionPair::EnableCollisions(this, bEnable: false);
}

//------------------------------------------------------------------------------
// Address: 0x101697E0
// Name: public: void CLogicCollisionPair::InputEnableCollisions(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCollisionPair::InputEnableCollisions(CLogicCollisionPair *this, inputdata_t *inputdata)
{
  if ( !this->m_succeeded || this->m_disabled )
    CLogicCollisionPair::EnableCollisions(this, bEnable: true);
}

//------------------------------------------------------------------------------
// Address: 0x10169870
// Name: public: virtual void CLogicCollisionPair::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCollisionPair::Activate(CLogicCollisionPair *this)
{
  if ( this->m_disabled )
    CLogicCollisionPair::EnableCollisions(this, bEnable: false);
  CBaseEntity::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10169890
// Name: public: void CLogicCompareInteger::InputValue(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCompareInteger::InputValue(CLogicCompareInteger *this, inputdata_t *inputdata)
{
  if ( variant_t::Convert(this: &inputdata->value, newType: FIELD_INTEGER) )
  {
    CMultiInputVar::AddValue(this: &this->m_AllIntCompares, newVal: inputdata->value, outputID: inputdata->nOutputID);
    if ( this->m_AllIntCompares.m_bUpdatedThisFrame == 0 )
    {
      CEventQueue::AddEvent(
        this: &g_EventQueue,
        target: this,
        action: "CompareValues",
        fireDelay: 0.0,
        pActivator: inputdata->pActivator,
        pCaller: this,
        outputID: inputdata->nOutputID);
      this->m_AllIntCompares.m_bUpdatedThisFrame = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169930
// Name: public: virtual void CTimerEntity::Think(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CTimerEntity::Think(CTimerEntity *this)
{
  CTimerEntity::FireTimer(this);
}

//------------------------------------------------------------------------------
// Address: 0x10169940
// Name: public: virtual void CLogicLineToEntity::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicLineToEntity::Activate(CLogicLineToEntity *this)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *m_pEntity; // eax
  const char *v12; // eax
  CBaseEntity *v13; // eax
  unsigned int v14; // ecx
  int v15; // eax
  CEntInfo *v16; // edx
  unsigned int v17; // ecx
  int v18; // eax
  CEntInfo *v19; // eax
  IHandleEntity *v20; // eax

  CBaseEntity::Activate(this);
  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    goto LABEL_13;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_EndEntity.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_EndEntity.m_Index = -1;
  m_Index = this->m_EndEntity.m_Index;
  if ( m_Index == -1
    || (v5 = (unsigned __int16)m_Index,
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v7 = HIWORD(m_Index),
        v6->m_SerialNumber != v7)
    || v6->m_pEntity == nullptr
    || ((v8 = v5,
         v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7,
         v10 = &g_pEntityList->m_EntPtrArray[v8],
         !v9)
      ? (m_pEntity = nullptr)
      : (m_pEntity = v10->m_pEntity),
        m_pEntity[6].__vftable == nullptr) )
  {
    _Warning(a1: "logic_lineto - Target not found or target with no origin!\n");
LABEL_13:
    this->m_EndEntity.m_Index = this->GetRefEHandle(this)->m_Index;
  }
  v12 = this->m_SourceName.pszValue;
  if ( v12 == nullptr )
  {
LABEL_26:
    this->m_StartEntity.m_Index = this->GetRefEHandle(this)->m_Index;
    return;
  }
  v13 = CGlobalEntityList::FindEntityByName(
          this: &gEntList,
          pStartEntity: nullptr,
          szName: v12,
          pSearchingEntity: nullptr,
          pActivator: nullptr,
          pCaller: nullptr,
          pFilter: nullptr);
  if ( v13 != nullptr )
    this->m_StartEntity.m_Index = v13->GetRefEHandle(this: v13)->m_Index;
  else
    this->m_StartEntity.m_Index = -1;
  v14 = this->m_StartEntity.m_Index;
  if ( v14 == -1
    || (v15 = (unsigned __int16)v14,
        v16 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v14],
        v17 = HIWORD(v14),
        v16->m_SerialNumber != v17)
    || v16->m_pEntity == nullptr
    || ((v18 = v15,
         v9 = g_pEntityList->m_EntPtrArray[v18].m_SerialNumber == v17,
         v19 = &g_pEntityList->m_EntPtrArray[v18],
         !v9)
      ? (v20 = nullptr)
      : (v20 = v19->m_pEntity),
        v20[6].__vftable == nullptr) )
  {
    _Warning(a1: "logic_lineto - Source not found or source with no origin!\n");
    goto LABEL_26;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169AA0
// Name: public: virtual void CMultiSource::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiSource::Use(
        CMultiSource *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  int v6; // edx
  CHandle<CBaseEntity> *m_rgEntities; // esi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  const char *pszValue; // eax
  const char *DebugName; // eax
  int fDelay; // [esp+4h] [ebp-10h]
  int m_iTotal; // [esp+10h] [ebp-4h]

  v6 = 0;
  m_iTotal = this->m_iTotal;
  if ( m_iTotal > 0 )
  {
    m_rgEntities = this->m_rgEntities;
    do
    {
      m_Index = m_rgEntities->m_Index;
      ++v6;
      ++m_rgEntities;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    while ( m_pEntity != pCaller && v6 < m_iTotal );
  }
  if ( v6 <= m_iTotal )
  {
    this->m_rgEntities[v6 + 31].m_Index ^= 1u;
    if ( this->IsTriggered(this, a2: pActivator) )
    {
      fDelay = this->m_iTotal;
      DebugName = CBaseEntity::GetDebugName(this);
      _DevMsg(a1: 2, a2: "Multisource %s enabled (%d inputs)\n", DebugName, fDelay);
      COutputEvent::FireOutput(this: &this->m_OnTrigger, pActivator, pCaller: this, fDelay: 0.0);
    }
  }
  else
  {
    if ( pCaller->m_Network.m_pPev != nullptr )
    {
      pszValue = pCaller->m_iClassname.pszValue;
      if ( pszValue == nullptr )
      {
        _Warning(a1: "MultiSrc: Used by non member %s.\n", locale);
        return;
      }
    }
    else
    {
      pszValue = "<logical entity>";
    }
    _Warning(a1: "MultiSrc: Used by non member %s.\n", pszValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169BA0
// Name: public: virtual void CLogicBranch::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranch::UpdateOnRemove(CLogicBranch *this)
{
  int i; // edi
  unsigned int m_Index; // eax

  for ( i = 0; i < this->m_Listeners.m_Size; ++i )
  {
    m_Index = this->m_Listeners.m_Memory.m_pMemory[i].m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      CEventQueue::AddEvent(
        this: &g_EventQueue,
        target: this,
        action: "_OnLogicBranchRemoved",
        fireDelay: 0.0,
        pActivator: this,
        pCaller: this,
        outputID: 0);
    }
  }
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10169C20
// Name: private: void CLogicBranch::UpdateValue(bool,class CBaseEntity __near *,enum CLogicBranch::LogicBranchFire_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranch::UpdateValue(
        CLogicBranch *this,
        bool bNewValue,
        CBaseEntity *pActivator,
        CLogicBranch::LogicBranchFire_t eFire)
{
  int v5; // edi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  if ( this->m_bInValue != bNewValue )
  {
    v5 = 0;
    for ( this->m_bInValue = bNewValue; v5 < this->m_Listeners.m_Size; ++v5 )
    {
      m_Index = this->m_Listeners.m_Memory.m_pMemory[v5].m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( m_pEntity != nullptr )
          CEventQueue::AddEvent(
            this: &g_EventQueue,
            target: m_pEntity,
            action: "_OnLogicBranchChanged",
            fireDelay: 0.0,
            pActivator: this,
            pCaller: this,
            outputID: 0);
      }
    }
  }
  if ( eFire == LOGIC_BRANCH_FIRE )
  {
    if ( this->m_bInValue )
      COutputEvent::FireOutput(this: &this->m_OnTrue, pActivator, pCaller: this, fDelay: 0.0);
    else
      COutputEvent::FireOutput(this: &this->m_OnFalse, pActivator, pCaller: this, fDelay: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169CE0
// Name: protected: void CLogicAutosave::InputSaveDangerous(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicAutosave::InputSaveDangerous(CLogicAutosave *this, inputdata_t *inputdata)
{
  CBasePlayer *v3; // esi
  float curtime; // xmm1_4
  float m_Value; // xmm0_4
  float flVal; // xmm0_4

  v3 = UTIL_PlayerByIndex(playerIndex: 1);
  if ( v3 != nullptr )
  {
    if ( g_ServerGameDLL.m_fAutoSaveDangerousTime != 0.0 )
    {
      curtime = gpGlobals->curtime;
      if ( g_ServerGameDLL.m_fAutoSaveDangerousTime >= curtime )
      {
        m_Value = v3->m_flDeathTime.m_Value;
        if ( m_Value == 0.0 || m_Value > curtime )
          engine->ServerCommand(this: engine, a2: "autosavedangerousissafe\n");
      }
    }
    if ( this->m_bForceNewLevelUnit )
      engine->ClearSaveDir(this: engine);
    if ( v3->m_iHealth.m_Value >= this->m_minHitPoints )
    {
      engine->ServerCommand(this: engine, a2: "autosavedangerous\n");
      if ( inputdata->value.fieldType == FIELD_FLOAT )
        flVal = inputdata->value.flVal;
      else
        flVal = 0.0;
      g_ServerGameDLL.m_fAutoSaveDangerousTime = gpGlobals->curtime + flVal;
      g_ServerGameDLL.m_fAutoSaveDangerousMinHealthToCommit = (float)this->m_minHitPointsToCommit;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169DD0
// Name: private: void CLogicBranchList::DoTest(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranchList::DoTest(CLogicBranchList *this, CBaseEntity *pActivator)
{
  CHandle<CBaseEntity> *m_pMemory; // edx
  int m_Size; // ebx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  bool bOneTrue; // [esp+Eh] [ebp-2h]
  bool bOneFalse; // [esp+Fh] [ebp-1h]

  bOneTrue = false;
  bOneFalse = false;
  if ( this->m_LogicBranchList.m_Size <= 0 )
    goto LABEL_17;
  m_pMemory = this->m_LogicBranchList.m_Memory.m_pMemory;
  m_Size = this->m_LogicBranchList.m_Size;
  do
  {
    m_Index = m_pMemory->m_Index;
    if ( m_pMemory->m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr
      && LOBYTE(m_pEntity[213].__vftable) != 0 )
    {
      bOneTrue = true;
    }
    else
    {
      bOneFalse = true;
    }
    ++m_pMemory;
    --m_Size;
  }
  while ( m_Size != 0 );
  if ( bOneTrue )
  {
    if ( !bOneFalse )
    {
      if ( this->m_eLastState != LOGIC_BRANCH_LISTENER_ALL_TRUE )
      {
        COutputEvent::FireOutput(this: &this->m_OnAllTrue, pActivator, pCaller: this, fDelay: 0.0);
        this->m_eLastState = LOGIC_BRANCH_LISTENER_ALL_TRUE;
      }
      return;
    }
    goto LABEL_17;
  }
  if ( !bOneFalse )
  {
LABEL_17:
    if ( this->m_eLastState != LOGIC_BRANCH_LISTENER_MIXED )
    {
      COutputEvent::FireOutput(this: &this->m_OnMixed, pActivator, pCaller: this, fDelay: 0.0);
      this->m_eLastState = LOGIC_BRANCH_LISTENER_MIXED;
    }
    return;
  }
  if ( this->m_eLastState != LOGIC_BRANCH_LISTENER_ALL_FALSE )
  {
    COutputEvent::FireOutput(this: &this->m_OnAllFalse, pActivator, pCaller: this, fDelay: 0.0);
    this->m_eLastState = LOGIC_BRANCH_LISTENER_ALL_FALSE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169EF0
// Name: private: virtual int CLogicBranchList::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLogicBranchList::DrawDebugTextOverlays(CLogicBranchList *this)
{
  int result; // eax
  int v3; // edi
  int v4; // ebx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  const char *v7; // edx
  const char *v8; // eax
  char tempstr[512]; // [esp+20h] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    v4 = 0;
    if ( this->m_LogicBranchList.m_Size > 0 )
    {
      do
      {
        m_Index = this->m_LogicBranchList.m_Memory.m_pMemory[v4].m_Index;
        if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          if ( m_pEntity != nullptr )
          {
            v7 = "TRUE";
            if ( LOBYTE(m_pEntity[213].__vftable) == 0 )
              v7 = "FALSE";
            v8 = (const char *)m_pEntity[51].__vftable;
            if ( v8 == nullptr )
              v8 = locale;
            V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Branch (%s): %s", v8, v7);
            CBaseEntity::EntityText(
              this,
              text_offset: v3++,
              text: tempstr,
              duration: 0.0,
              r: 255,
              g: 255,
              b: 255,
              a: 255);
          }
        }
        ++v4;
      }
      while ( v4 < this->m_LogicBranchList.m_Size );
      return v3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10169FE0
// Name: public: CTimerEntity::CTimerEntity(void)
// Source: json
//------------------------------------------------------------------------------
CTimerEntity *__thiscall CTimerEntity::CTimerEntity(CTimerEntity *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CTimerEntity_vtbl *)&CTimerEntity::`vftable';
  this->m_OnTimer.m_Value.iVal = 0;
  this->m_OnTimer.m_Value.eVal.m_Index = -1;
  this->m_OnTimer.m_Value.fieldType = FIELD_VOID;
  this->m_OnTimerHigh.m_Value.iVal = 0;
  this->m_OnTimerHigh.m_Value.eVal.m_Index = -1;
  this->m_OnTimerHigh.m_Value.fieldType = FIELD_VOID;
  this->m_OnTimerLow.m_Value.iVal = 0;
  this->m_OnTimerLow.m_Value.eVal.m_Index = -1;
  this->m_OnTimerLow.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016A030
// Name: public: CMultiSource::CMultiSource(void)
// Source: json
//------------------------------------------------------------------------------
CMultiSource *__thiscall CMultiSource::CMultiSource(CMultiSource *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CMultiSource_vtbl *)&CMultiSource::`vftable';
  this->m_rgEntities[0].m_Index = -1;
  this->m_rgEntities[1].m_Index = -1;
  this->m_rgEntities[2].m_Index = -1;
  this->m_rgEntities[3].m_Index = -1;
  this->m_rgEntities[4].m_Index = -1;
  this->m_rgEntities[5].m_Index = -1;
  this->m_rgEntities[6].m_Index = -1;
  this->m_rgEntities[7].m_Index = -1;
  this->m_rgEntities[8].m_Index = -1;
  this->m_rgEntities[9].m_Index = -1;
  this->m_rgEntities[10].m_Index = -1;
  this->m_rgEntities[11].m_Index = -1;
  this->m_rgEntities[12].m_Index = -1;
  this->m_rgEntities[13].m_Index = -1;
  this->m_rgEntities[14].m_Index = -1;
  this->m_rgEntities[15].m_Index = -1;
  this->m_rgEntities[16].m_Index = -1;
  this->m_rgEntities[17].m_Index = -1;
  this->m_rgEntities[18].m_Index = -1;
  this->m_rgEntities[19].m_Index = -1;
  this->m_rgEntities[20].m_Index = -1;
  this->m_rgEntities[21].m_Index = -1;
  this->m_rgEntities[22].m_Index = -1;
  this->m_rgEntities[23].m_Index = -1;
  this->m_rgEntities[24].m_Index = -1;
  this->m_rgEntities[25].m_Index = -1;
  this->m_rgEntities[26].m_Index = -1;
  this->m_rgEntities[27].m_Index = -1;
  this->m_rgEntities[28].m_Index = -1;
  this->m_rgEntities[29].m_Index = -1;
  this->m_rgEntities[30].m_Index = -1;
  this->m_rgEntities[31].m_Index = -1;
  this->m_OnTrigger.m_Value.iVal = 0;
  this->m_OnTrigger.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016A120
// Name: public: virtual int CMultiSource::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMultiSource::ObjectCaps(CMultiSource *this)
{
  return CBaseEntity::ObjectCaps(this) & 0xEFFFFF7F | 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x1016A1B0
// Name: public: void CEntityOutputTemplate<class Vector,3>::Set(class Vector const __near &,class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityOutputTemplate<Vector,3>::Set(
        CEntityOutputTemplate<Vector,3> *this,
        $3B1CACFA647AB85A7D70EA6016B49717 *value,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller)
{
  this->m_Value.___u0 = *value;
  this->m_Value.fieldType = FIELD_VECTOR;
  CBaseEntityOutput::FireOutput(this, Value: this->m_Value, pActivator, pCaller, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1016A220
// Name: public: CLogicRegisterActivator::CLogicRegisterActivator(void)
// Source: json
//------------------------------------------------------------------------------
CLogicRegisterActivator *__thiscall CLogicRegisterActivator::CLogicRegisterActivator(CLogicRegisterActivator *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CLogicRegisterActivator_vtbl *)&CLogicRegisterActivator::`vftable';
  this->m_OnRegisteredActivate1.m_Value.iVal = 0;
  this->m_OnRegisteredActivate1.m_Value.eVal.m_Index = -1;
  this->m_OnRegisteredActivate1.m_Value.fieldType = FIELD_VOID;
  this->m_OnRegisteredActivate2.m_Value.iVal = 0;
  this->m_OnRegisteredActivate2.m_Value.eVal.m_Index = -1;
  this->m_OnRegisteredActivate2.m_Value.fieldType = FIELD_VOID;
  this->m_OnRegisteredActivate3.m_Value.iVal = 0;
  this->m_OnRegisteredActivate3.m_Value.eVal.m_Index = -1;
  this->m_OnRegisteredActivate3.m_Value.fieldType = FIELD_VOID;
  this->m_OnRegisteredActivate4.m_Value.iVal = 0;
  this->m_OnRegisteredActivate4.m_Value.eVal.m_Index = -1;
  this->m_OnRegisteredActivate4.m_Value.fieldType = FIELD_VOID;
  this->m_hRegisteredEntity.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016A2E0
// Name: public: virtual void CLogicLineToEntity::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicLineToEntity::Think(CLogicLineToEntity *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ebx
  unsigned int v4; // eax
  CBaseEntity *v5; // edi
  float thinkTime; // xmm0_4
  Vector delta; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  m_Index = this->m_EndEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v4 = this->m_StartEntity.m_Index;
  if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    v5 = nullptr;
  else
    v5 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
  if ( m_pEntity != nullptr
    && v5 != nullptr
    && m_pEntity->m_Network.m_pPev != nullptr
    && v5->m_Network.m_pPev != nullptr )
  {
    if ( (v5->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
    if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
    delta.x = m_pEntity->m_vecAbsOrigin.x - v5->m_vecAbsOrigin.x;
    delta.y = m_pEntity->m_vecAbsOrigin.y - v5->m_vecAbsOrigin.y;
    delta.z = m_pEntity->m_vecAbsOrigin.z - v5->m_vecAbsOrigin.z;
    CEntityOutputTemplate<Vector,3>::Set(
      this: &this->m_Line,
      value: ($3B1CACFA647AB85A7D70EA6016B49717 *)&delta,
      pActivator: this,
      pCaller: this);
    thinkTime = gpGlobals->curtime + 0.0099999998;
  }
  else
  {
    this->m_Line.m_Value.___u0 = ($3B1CACFA647AB85A7D70EA6016B49717)vec3_origin;
    this->m_Line.m_Value.fieldType = FIELD_VECTOR;
    CBaseEntityOutput::FireOutput(
      this: &this->m_Line,
      Value: this->m_Line.m_Value,
      pActivator: this,
      pCaller: this,
      fDelay: 0.0);
    thinkTime = gpGlobals->curtime + 10.0;
  }
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1016A490
// Name: public: void CMathRemap::InputValue(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathRemap::InputValue(CMathRemap *this, inputdata_t *inputdata)
{
  float flVal; // xmm1_4
  float m_flInMin; // xmm0_4
  float m_flOut1; // xmm2_4
  float value; // xmm0_4
  float m_flOut2; // xmm1_4

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  m_flInMin = this->m_flInMin;
  if ( m_flInMin <= flVal )
  {
    m_flInMin = this->m_flInMax;
    if ( flVal <= m_flInMin )
      m_flInMin = flVal;
  }
  if ( m_flInMin == flVal || (this->m_spawnflags.m_Value & 1) == 0 )
  {
    m_flOut1 = this->m_flOut1;
    value = (float)((float)((float)(this->m_flOut2 - m_flOut1) * (float)(flVal - this->m_flInMin))
                  / (float)(this->m_flInMax - this->m_flInMin))
          + m_flOut1;
    if ( (this->m_spawnflags.m_Value & 2) != 0 )
    {
      m_flOut2 = this->m_flOut1;
      if ( m_flOut1 > value || (m_flOut2 = this->m_flOut2, value > m_flOut2) )
        value = m_flOut2;
    }
    if ( this->m_bEnabled )
      CEntityOutputTemplate<float,1>::Set(
        this: &this->m_OutValue,
        value,
        pActivator: inputdata->pActivator,
        pCaller: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016A550
// Name: public: void CMathColorBlend::InputValue(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathColorBlend::InputValue(CMathColorBlend *this, inputdata_t *inputdata)
{
  inputdata_t *v3; // ecx
  float flVal; // xmm0_4
  float m_flInMin; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  int g; // edx
  int v10; // eax
  float v11; // xmm2_4
  int b; // edx
  CBaseEntity *pActivator; // ebx
  int v14; // eax
  float v15; // xmm2_4
  int a; // edx

  v3 = inputdata;
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  m_flInMin = this->m_flInMin;
  if ( m_flInMin <= flVal )
  {
    m_flInMin = this->m_flInMax;
    if ( flVal <= m_flInMin )
      m_flInMin = flVal;
  }
  if ( m_flInMin == flVal || (this->m_spawnflags.m_Value & 1) == 0 )
  {
    v6 = this->m_flInMin;
    v7 = this->m_flInMax - v6;
    v8 = m_flInMin - v6;
    g = this->m_OutColor2.g;
    LOBYTE(inputdata) = (int)(float)((float)((float)((float)(this->m_OutColor2.r - this->m_OutColor1.r) * v8) / v7)
                                   + (float)this->m_OutColor1.r);
    v10 = this->m_OutColor1.g;
    v11 = (float)(g - v10);
    b = this->m_OutColor2.b;
    pActivator = v3->pActivator;
    BYTE1(inputdata) = (int)(float)((float)((float)(v11 * v8) / v7) + (float)v10);
    v14 = this->m_OutColor1.b;
    v15 = (float)(b - v14);
    a = this->m_OutColor2.a;
    BYTE2(inputdata) = (int)(float)((float)((float)(v15 * v8) / v7) + (float)v14);
    HIBYTE(inputdata) = (int)(float)((float)((float)((float)(a - this->m_OutColor1.a) * v8) / v7)
                                   + (float)this->m_OutColor1.a);
    variant_t::Set(this: &this->m_OutValue.m_Value, ftype: FIELD_COLOR32, data: &inputdata);
    CBaseEntityOutput::FireOutput(
      this: &this->m_OutValue,
      Value: this->m_OutValue.m_Value,
      pActivator,
      pCaller: this,
      fDelay: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016A710
// Name: public: void CEnvGlobal::InputGetCounter(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGlobal::InputGetCounter(CEnvGlobal *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  const char *v4; // eax
  const char *v5; // ecx
  const char *v6; // eax
  int Index; // eax
  inputdata_t *Counter; // eax
  CBaseEntity *pActivator; // ebx

  pszValue = this->m_globalstate.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( GlobalEntity_GetIndex(pGlobalname: pszValue) < 0 )
  {
    v4 = gpGlobals->mapname.pszValue;
    v5 = this->m_globalstate.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    if ( v5 == nullptr )
      v5 = locale;
    GlobalEntity_Add(pGlobalname: v5, pMapName: v4, state: GLOBAL_ON);
  }
  v6 = this->m_globalstate.pszValue;
  if ( v6 == nullptr )
    v6 = locale;
  Index = GlobalEntity_GetIndex(pGlobalname: v6);
  Counter = (inputdata_t *)GlobalEntity_GetCounter(globalIndex: Index);
  pActivator = inputdata->pActivator;
  inputdata = Counter;
  variant_t::Set(this: &this->m_outCounter.m_Value, ftype: FIELD_INTEGER, data: &inputdata);
  CBaseEntityOutput::FireOutput(
    this: &this->m_outCounter,
    Value: this->m_outCounter.m_Value,
    pActivator,
    pCaller: this,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1016A810
// Name: private: void CMathCounter::InputGetValue(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::InputGetValue(CMathCounter *this, inputdata_t *inputdata)
{
  CBaseEntity *pActivator; // ebx
  CBaseEntity *pCaller; // edi
  CEntityOutputTemplate<float,1> *p_m_OnGetValue; // esi

  pActivator = inputdata->pActivator;
  pCaller = inputdata->pCaller;
  p_m_OnGetValue = &this->m_OnGetValue;
  inputdata = (inputdata_t *)this->m_OutValue.m_Value.iszVal.pszValue;
  variant_t::Set(this: &this->m_OnGetValue.m_Value, ftype: FIELD_FLOAT, data: &inputdata);
  CBaseEntityOutput::FireOutput(this: p_m_OnGetValue, Value: p_m_OnGetValue->m_Value, pActivator, pCaller, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1016A890
// Name: private: void CMathCounter::UpdateOutValue(class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::UpdateOutValue(CMathCounter *this, CBaseEntity *pActivator, float fNewValue)
{
  float m_flMax; // xmm0_4
  float m_flMin; // xmm0_4
  float v6; // xmm0_4

  if ( this->m_flMin == 0.0 && this->m_flMax == 0.0 )
  {
    v6 = fNewValue;
  }
  else
  {
    m_flMax = this->m_flMax;
    if ( fNewValue < m_flMax )
    {
      if ( this->m_OutValue.m_Value.flVal == m_flMax )
        COutputEvent::FireOutput(this: &this->m_OnChangedFromMax, pActivator, pCaller: this, fDelay: 0.0);
      this->m_bHitMax = false;
    }
    else if ( !this->m_bHitMax )
    {
      this->m_bHitMax = true;
      COutputEvent::FireOutput(this: &this->m_OnHitMax, pActivator, pCaller: this, fDelay: 0.0);
    }
    m_flMin = this->m_flMin;
    if ( m_flMin < fNewValue )
    {
      if ( this->m_OutValue.m_Value.flVal == m_flMin )
        COutputEvent::FireOutput(this: &this->m_OnChangedFromMin, pActivator, pCaller: this, fDelay: 0.0);
      this->m_bHitMin = false;
    }
    else if ( !this->m_bHitMin )
    {
      this->m_bHitMin = true;
      COutputEvent::FireOutput(this: &this->m_OnHitMin, pActivator, pCaller: this, fDelay: 0.0);
    }
    v6 = this->m_flMin;
    if ( v6 <= fNewValue )
    {
      v6 = this->m_flMax;
      if ( fNewValue <= v6 )
        v6 = fNewValue;
    }
  }
  fNewValue = v6;
  variant_t::Set(this: &this->m_OutValue.m_Value, ftype: FIELD_FLOAT, data: &fNewValue);
  CBaseEntityOutput::FireOutput(
    this: &this->m_OutValue,
    Value: this->m_OutValue.m_Value,
    pActivator,
    pCaller: this,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1016AA40
// Name: private: void CLogicCase::InputValue(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCase::InputValue(CLogicCase *this, inputdata_t *inputdata)
{
  bool v2; // zf
  const char *v4; // eax
  int v5; // edi
  string_t *i; // ebx
  unsigned int m_Index; // edx
  const char *v8; // ecx
  float v9; // eax
  CBaseEntity *v10; // ebx
  CBaseEntity *pActivator; // edi
  variant_t v12; // [esp-1Ch] [ebp-48h]
  _DWORD data[5]; // [esp+10h] [ebp-1Ch] BYREF
  CBaseEntity *pCaller; // [esp+24h] [ebp-8h]
  const char *pszValue; // [esp+28h] [ebp-4h]

  v2 = inputdata->value.fieldType == FIELD_STRING;
  pCaller = this;
  if ( !v2 )
  {
    v4 = variant_t::ToString(this: &inputdata->value);
    goto LABEL_5;
  }
  v4 = inputdata->value.iszVal.pszValue;
  if ( v4 != nullptr )
  {
LABEL_5:
    pszValue = v4;
    goto LABEL_6;
  }
  pszValue = locale;
LABEL_6:
  v5 = 0;
  for ( i = this->m_nCase; i->pszValue == nullptr || _V_stricmp(s1: i->pszValue, s2: pszValue) != 0; ++i )
  {
    if ( ++v5 >= 16 )
    {
      m_Index = inputdata->value.eVal.m_Index;
      v8 = inputdata->value.iszVal.pszValue;
      v9 = inputdata->value.vecVal[2];
      v10 = pCaller;
      data[1] = LODWORD(inputdata->value.vecVal[1]);
      data[0] = v8;
      data[3] = m_Index;
      pActivator = inputdata->pActivator;
      *(float *)&data[2] = v9;
      data[4] = inputdata->value.fieldType;
      variant_t::Set(this: (variant_t *)&pCaller[1].m_angAbsRotation, ftype: FIELD_INPUT, data);
      v12.___u0 = ($3B1CACFA647AB85A7D70EA6016B49717)v10[1].m_angAbsRotation;
      *(_QWORD *)&v12.eVal.m_Index = *(_QWORD *)&v10[1].m_vecVelocity.m_Value.x;
      CBaseEntityOutput::FireOutput(
        this: (CBaseEntityOutput *)&v10[1].m_angAbsRotation,
        Value: v12,
        pActivator,
        pCaller: v10,
        fDelay: 0.0);
      return;
    }
  }
  COutputEvent::FireOutput(
    this: (COutputEvent *)((char *)&pCaller[1].m_Network + 24 * v5 + 76),
    pActivator: inputdata->pActivator,
    pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1016AB80
// Name: private: void CLogicCompare::DoCompare(class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCompare::DoCompare(CLogicCompare *this, CBaseEntity *pActivator, CLogicCompare *flInValue)
{
  CEntityOutputTemplate<float,1> *p_m_OnGreaterThan; // ecx
  CLogicCompare *data; // [esp+18h] [ebp-4h] BYREF

  data = this;
  if ( *(float *)&flInValue == this->m_flCompareValue )
  {
    variant_t::Set(this: &this->m_OnEqualTo.m_Value, ftype: FIELD_FLOAT, data: &flInValue);
    CBaseEntityOutput::FireOutput(
      this: &this->m_OnEqualTo,
      Value: this->m_OnEqualTo.m_Value,
      pActivator,
      pCaller: this,
      fDelay: 0.0);
  }
  else
  {
    data = flInValue;
    variant_t::Set(this: &this->m_OnNotEqualTo.m_Value, ftype: FIELD_FLOAT, &data);
    CBaseEntityOutput::FireOutput(
      this: &this->m_OnNotEqualTo,
      Value: this->m_OnNotEqualTo.m_Value,
      pActivator,
      pCaller: this,
      fDelay: 0.0);
    p_m_OnGreaterThan = &this->m_OnGreaterThan;
    if ( *(float *)&flInValue <= this->m_flCompareValue )
      p_m_OnGreaterThan = &this->m_OnLessThan;
    CEntityOutputTemplate<float,1>::Set(this: p_m_OnGreaterThan, value: *(float *)&flInValue, pActivator, pCaller: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016ACE0
// Name: private: void CLogicBranch::InputSetValue(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranch::InputSetValue(CLogicBranch *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_BOOLEAN )
    CLogicBranch::UpdateValue(
      this,
      bNewValue: inputdata->value.bVal,
      pActivator: inputdata->pActivator,
      eFire: LOGIC_BRANCH_NO_FIRE);
  else
    CLogicBranch::UpdateValue(this, bNewValue: false, pActivator: inputdata->pActivator, eFire: LOGIC_BRANCH_NO_FIRE);
}

//------------------------------------------------------------------------------
// Address: 0x1016AD10
// Name: private: void CLogicBranch::InputSetValueTest(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranch::InputSetValueTest(CLogicBranch *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_BOOLEAN )
    CLogicBranch::UpdateValue(
      this,
      bNewValue: inputdata->value.bVal,
      pActivator: inputdata->pActivator,
      eFire: LOGIC_BRANCH_FIRE);
  else
    CLogicBranch::UpdateValue(this, bNewValue: false, pActivator: inputdata->pActivator, eFire: LOGIC_BRANCH_FIRE);
}

//------------------------------------------------------------------------------
// Address: 0x1016AD40
// Name: private: void CLogicBranch::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranch::InputToggle(CLogicBranch *this, inputdata_t *inputdata)
{
  CLogicBranch::UpdateValue(
    this,
    bNewValue: !this->m_bInValue,
    pActivator: inputdata->pActivator,
    eFire: LOGIC_BRANCH_NO_FIRE);
}

//------------------------------------------------------------------------------
// Address: 0x1016AD70
// Name: private: void CLogicBranch::InputToggleTest(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranch::InputToggleTest(CLogicBranch *this, inputdata_t *inputdata)
{
  CLogicBranch::UpdateValue(
    this,
    bNewValue: !this->m_bInValue,
    pActivator: inputdata->pActivator,
    eFire: LOGIC_BRANCH_FIRE);
}

//------------------------------------------------------------------------------
// Address: 0x1016ADA0
// Name: private: void CLogicBranch::InputTest(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranch::InputTest(CLogicBranch *this, inputdata_t *inputdata)
{
  CLogicBranch::UpdateValue(
    this,
    bNewValue: this->m_bInValue,
    pActivator: inputdata->pActivator,
    eFire: LOGIC_BRANCH_FIRE);
}

//------------------------------------------------------------------------------
// Address: 0x1016ADC0
// Name: private: void CLogicActiveAutosave::SaveThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicActiveAutosave::SaveThink(CLogicActiveAutosave *this)
{
  CBasePlayer *LocalPlayer; // eax
  float m_flStartTime; // xmm1_4
  edict_t *m_pPev; // eax
  const char *pszValue; // ecx
  float m_flTimeToTrigger; // xmm0_4
  double v7; // xmm0_8
  inputdata_t inputdata; // [esp+Ch] [ebp-20h] BYREF

  LocalPlayer = UTIL_GetLocalPlayer();
  if ( LocalPlayer == nullptr )
    goto LABEL_16;
  m_flStartTime = this->m_flStartTime;
  if ( m_flStartTime >= 0.0 )
  {
    if ( LocalPlayer->m_iHealth.m_Value < this->m_TriggerHitPoints )
    {
      m_flTimeToTrigger = this->m_flTimeToTrigger;
      if ( m_flTimeToTrigger <= 0.0 || (float)(gpGlobals->curtime - m_flStartTime) <= m_flTimeToTrigger )
        goto LABEL_16;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      inputdata.value.iVal = 0;
      inputdata.value.eVal.m_Index = -1;
      inputdata.value.fieldType = FIELD_VOID;
      if ( m_pPev != nullptr )
        m_pPev -= (int)gpGlobals->pEdicts;
      pszValue = this->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      _DevMsg(a1: 2, a2: "logic_active_autosave (%s, %d) triggered\n", pszValue, m_pPev);
      if ( this->m_flDangerousTime == 0.0 )
      {
        CLogicAutosave::InputSave(this, &inputdata);
      }
      else
      {
        inputdata.value.iVal = LODWORD(this->m_flDangerousTime);
        inputdata.value.fieldType = FIELD_FLOAT;
        CLogicAutosave::InputSaveDangerous(this, &inputdata);
      }
    }
    this->m_flStartTime = -1.0;
  }
  else if ( LocalPlayer->m_iHealth.m_Value <= this->m_minHitPoints )
  {
    this->m_flStartTime = gpGlobals->curtime;
  }
LABEL_16:
  if ( this->m_flStartTime >= 0.0 )
    v7 = 0.5;
  else
    v7 = 1.0;
  CBaseEntity::SetNextThink(this, thinkTime: (float)v7 + gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1016AF20
// Name: private: void CLogicBranchList::Input_OnLogicBranchRemoved(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranchList::Input_OnLogicBranchRemoved(CLogicBranchList *this, unsigned int inputdata)
{
  inputdata_t *v2; // ebx
  int v4; // eax
  int m_Size; // edx

  v2 = (inputdata_t *)inputdata;
  if ( *(_DWORD *)inputdata != 0 )
    inputdata = *(_DWORD *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)inputdata + 8))(a1: *(_DWORD *)inputdata);
  else
    inputdata = -1;
  v4 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: &this->m_LogicBranchList,
         src: (CHandle<CBaseEntity> *)&inputdata);
  if ( v4 != -1 )
  {
    m_Size = this->m_LogicBranchList.m_Size;
    if ( m_Size > 0 )
    {
      if ( v4 != m_Size - 1 )
        this->m_LogicBranchList.m_Memory.m_pMemory[v4].m_Index = this->m_LogicBranchList.m_Memory.m_pMemory[m_Size - 1].m_Index;
      --this->m_LogicBranchList.m_Size;
    }
  }
  CLogicBranchList::DoTest(this, pActivator: v2->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x1016AF90
// Name: private: void CLogicBranchList::Input_OnLogicBranchChanged(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranchList::Input_OnLogicBranchChanged(CLogicBranchList *this, inputdata_t *inputdata)
{
  CLogicBranchList::DoTest(this, pActivator: inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x1016AFB0
// Name: private: void CLogicBranchList::InputTest(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranchList::InputTest(CLogicBranchList *this, inputdata_t *inputdata)
{
  this->m_eLastState = LOGIC_BRANCH_LISTENER_NOT_INIT;
  CLogicBranchList::DoTest(this, pActivator: inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x1016B110
// Name: public: CMathCounter::CMathCounter(void)
// Source: json
//------------------------------------------------------------------------------
CMathCounter *__thiscall CMathCounter::CMathCounter(CMathCounter *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CMathCounter_vtbl *)&CMathCounter::`vftable';
  this->m_OutValue.m_Value.iVal = 0;
  this->m_OutValue.m_Value.eVal.m_Index = -1;
  this->m_OutValue.m_Value.fieldType = FIELD_VOID;
  this->m_OnGetValue.m_Value.iVal = 0;
  this->m_OnGetValue.m_Value.eVal.m_Index = -1;
  this->m_OnGetValue.m_Value.fieldType = FIELD_VOID;
  this->m_OnHitMin.m_Value.iVal = 0;
  this->m_OnHitMin.m_Value.eVal.m_Index = -1;
  this->m_OnHitMin.m_Value.fieldType = FIELD_VOID;
  this->m_OnHitMax.m_Value.iVal = 0;
  this->m_OnHitMax.m_Value.eVal.m_Index = -1;
  this->m_OnHitMax.m_Value.fieldType = FIELD_VOID;
  this->m_OnChangedFromMin.m_Value.iVal = 0;
  this->m_OnChangedFromMin.m_Value.eVal.m_Index = -1;
  this->m_OnChangedFromMin.m_Value.fieldType = FIELD_VOID;
  this->m_OnChangedFromMax.m_Value.iVal = 0;
  this->m_OnChangedFromMax.m_Value.eVal.m_Index = -1;
  this->m_OnChangedFromMax.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016B210
// Name: public: CLogicCase::CLogicCase(void)
// Source: json
//------------------------------------------------------------------------------
CLogicCase *__thiscall CLogicCase::CLogicCase(CLogicCase *this)
{
  COutputEvent *m_OnCase; // eax
  int i; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CLogicCase_vtbl *)&CLogicCase::`vftable';
  m_OnCase = this->m_OnCase;
  for ( i = 15; i >= 0; --i )
  {
    m_OnCase->m_Value.iVal = 0;
    m_OnCase->m_Value.eVal.m_Index = -1;
    m_OnCase->m_Value.fieldType = FIELD_VOID;
    ++m_OnCase;
  }
  this->m_OnDefault.m_Value.iVal = 0;
  this->m_OnDefault.m_Value.eVal.m_Index = -1;
  this->m_OnDefault.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016B2B0
// Name: public: CLogicCompare::CLogicCompare(void)
// Source: json
//------------------------------------------------------------------------------
CLogicCompare *__thiscall CLogicCompare::CLogicCompare(CLogicCompare *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CLogicCompare_vtbl *)&CLogicCompare::`vftable';
  this->m_OnLessThan.m_Value.iVal = 0;
  this->m_OnLessThan.m_Value.eVal.m_Index = -1;
  this->m_OnLessThan.m_Value.fieldType = FIELD_VOID;
  this->m_OnEqualTo.m_Value.iVal = 0;
  this->m_OnEqualTo.m_Value.eVal.m_Index = -1;
  this->m_OnEqualTo.m_Value.fieldType = FIELD_VOID;
  this->m_OnNotEqualTo.m_Value.iVal = 0;
  this->m_OnNotEqualTo.m_Value.eVal.m_Index = -1;
  this->m_OnNotEqualTo.m_Value.fieldType = FIELD_VOID;
  this->m_OnGreaterThan.m_Value.iVal = 0;
  this->m_OnGreaterThan.m_Value.eVal.m_Index = -1;
  this->m_OnGreaterThan.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016B370
// Name: public: void CMultiSource::Register(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiSource::Register(CMultiSource *this)
{
  const char *pszValue; // eax
  CBaseEntity *i; // edi
  int m_iTotal; // ebx
  const char *v5; // eax
  CBaseEntity *j; // edi
  int v7; // ebx
  unsigned int v8; // edi
  edict_t *m_pPev; // ecx

  this->m_iTotal = 0;
  memset(dst: (unsigned __int8 *)this->m_rgEntities, value: 0, count: sizeof(this->m_rgEntities));
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CAI_BaseNPC::OnSetSchedule,
    thinkTime: 0.0,
    szContext: nullptr);
  pszValue = this->m_iName.m_Value.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  for ( i = CGlobalEntityList::FindEntityByTarget(this: &gEntList, pStartEntity: nullptr, szName: pszValue);
        i != nullptr;
        i = CGlobalEntityList::FindEntityByTarget(this: &gEntList, pStartEntity: i, szName: v5) )
  {
    m_iTotal = this->m_iTotal;
    if ( m_iTotal >= 32 )
      break;
    if ( i != nullptr )
    {
      this->m_iTotal = m_iTotal + 1;
      this->m_rgEntities[m_iTotal].m_Index = i->GetRefEHandle(this: i)->m_Index;
    }
    v5 = this->m_iName.m_Value.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
  }
  for ( j = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "multi_manager");
        j != nullptr;
        j = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: j, szName: "multi_manager") )
  {
    if ( this->m_iTotal >= 32 )
      break;
    if ( j != nullptr
      && ((unsigned __int8 (__thiscall *)(CBaseEntity *, const char *))j->HasTarget)(
           a1: j,
           a2: this->m_iName.m_Value.pszValue) != 0 )
    {
      v7 = this->m_iTotal;
      this->m_iTotal = v7 + 1;
      this->m_rgEntities[v7].m_Index = j->GetRefEHandle(this: j)->m_Index;
    }
  }
  v8 = this->m_spawnflags.m_Value & 0xFFFFFFFE;
  if ( this->m_spawnflags.m_Value != v8 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_spawnflags.m_Value = v8;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      this->m_spawnflags.m_Value = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B4D0
// Name: private: void CMathCounter::InputSetHitMax(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::InputSetHitMax(CMathCounter *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  float m_flMin; // xmm1_4

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  m_flMin = this->m_flMin;
  this->m_flMax = flVal;
  if ( m_flMin > flVal )
    this->m_flMin = flVal;
  CMathCounter::UpdateOutValue(this, pActivator: inputdata->pActivator, fNewValue: this->m_OutValue.m_Value.flVal);
}

//------------------------------------------------------------------------------
// Address: 0x1016B520
// Name: private: void CMathCounter::InputSetHitMin(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::InputSetHitMin(CMathCounter *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  bool v3; // cc

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  v3 = flVal <= this->m_flMax;
  this->m_flMin = flVal;
  if ( !v3 )
    this->m_flMax = flVal;
  CMathCounter::UpdateOutValue(this, pActivator: inputdata->pActivator, fNewValue: this->m_OutValue.m_Value.flVal);
}

//------------------------------------------------------------------------------
// Address: 0x1016B570
// Name: private: void CMathCounter::InputAdd(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::InputAdd(CMathCounter *this, inputdata_t *inputdata)
{
  const char *DebugName; // eax
  float flVal; // xmm0_4

  if ( this->m_bDisabled )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "Math Counter %s ignoring ADD because it is disabled\n", DebugName);
  }
  else
  {
    if ( inputdata->value.fieldType == FIELD_FLOAT )
      flVal = inputdata->value.flVal;
    else
      flVal = 0.0;
    CMathCounter::UpdateOutValue(
      this,
      pActivator: inputdata->pActivator,
      fNewValue: flVal + this->m_OutValue.m_Value.flVal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B5D0
// Name: private: void CMathCounter::InputDivide(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::InputDivide(CMathCounter *this, inputdata_t *inputdata)
{
  const char *DebugName; // eax
  float flVal; // xmm1_4

  if ( this->m_bDisabled )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "Math Counter %s ignoring DIVIDE because it is disabled\n", DebugName);
  }
  else if ( inputdata->value.fieldType != FIELD_FLOAT || (flVal = inputdata->value.flVal) == 0.0 )
  {
    _DevMsg(a1: 1, a2: "LEVEL DESIGN ERROR: Divide by zero in math_value\n");
    CMathCounter::UpdateOutValue(this, pActivator: inputdata->pActivator, fNewValue: this->m_OutValue.m_Value.flVal);
  }
  else
  {
    CMathCounter::UpdateOutValue(
      this,
      pActivator: inputdata->pActivator,
      fNewValue: this->m_OutValue.m_Value.flVal / flVal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B670
// Name: private: void CMathCounter::InputMultiply(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::InputMultiply(CMathCounter *this, inputdata_t *inputdata)
{
  const char *DebugName; // eax
  float flVal; // xmm0_4

  if ( this->m_bDisabled )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "Math Counter %s ignoring MULTIPLY because it is disabled\n", DebugName);
  }
  else
  {
    if ( inputdata->value.fieldType == FIELD_FLOAT )
      flVal = inputdata->value.flVal;
    else
      flVal = 0.0;
    CMathCounter::UpdateOutValue(
      this,
      pActivator: inputdata->pActivator,
      fNewValue: flVal * this->m_OutValue.m_Value.flVal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B6D0
// Name: private: void CMathCounter::InputSetValue(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::InputSetValue(CMathCounter *this, inputdata_t *inputdata)
{
  const char *DebugName; // eax

  if ( this->m_bDisabled )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "Math Counter %s ignoring SETVALUE because it is disabled\n", DebugName);
  }
  else if ( inputdata->value.fieldType == FIELD_FLOAT )
  {
    CMathCounter::UpdateOutValue(this, pActivator: inputdata->pActivator, fNewValue: inputdata->value.flVal);
  }
  else
  {
    CMathCounter::UpdateOutValue(this, pActivator: inputdata->pActivator, fNewValue: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B730
// Name: private: void CMathCounter::InputSubtract(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMathCounter::InputSubtract(CMathCounter *this, inputdata_t *inputdata)
{
  const char *DebugName; // eax
  float flVal; // xmm1_4

  if ( this->m_bDisabled )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "Math Counter %s ignoring SUBTRACT because it is disabled\n", DebugName);
  }
  else
  {
    if ( inputdata->value.fieldType == FIELD_FLOAT )
      flVal = inputdata->value.flVal;
    else
      flVal = 0.0;
    CMathCounter::UpdateOutValue(
      this,
      pActivator: inputdata->pActivator,
      fNewValue: this->m_OutValue.m_Value.flVal - flVal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B790
// Name: private: void CLogicCompare::InputSetValueCompare(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCompare::InputSetValueCompare(CLogicCompare *this, inputdata_t *inputdata)
{
  CLogicCompare *flInValue; // xmm0_4
  CBaseEntity *pActivator; // [esp-4h] [ebp-8h]

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flInValue = (CLogicCompare *)inputdata->value.iszVal.pszValue;
  else
    flInValue = nullptr;
  pActivator = inputdata->pActivator;
  LODWORD(this->m_flInValue) = flInValue;
  CLogicCompare::DoCompare(this, pActivator, flInValue);
}

//------------------------------------------------------------------------------
// Address: 0x1016B7C0
// Name: private: void CLogicCompare::InputCompare(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicCompare::InputCompare(CLogicCompare *this, inputdata_t *inputdata)
{
  CLogicCompare::DoCompare(
    this,
    pActivator: inputdata->pActivator,
    flInValue: (CLogicCompare *)LODWORD(this->m_flInValue));
}

//------------------------------------------------------------------------------
// Address: 0x1016B7E0
// Name: private: void CLogicActiveAutosave::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicActiveAutosave::InputEnable(CLogicActiveAutosave *this, inputdata_t *inputdata)
{
  this->m_flStartTime = -1.0;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CLogicActiveAutosave::SaveThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1016BB20
// Name: public: CLogicBranch::CLogicBranch(void)
// Source: json
//------------------------------------------------------------------------------
CLogicBranch *__thiscall CLogicBranch::CLogicBranch(CLogicBranch *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CLogicBranch_vtbl *)&CLogicBranch::`vftable';
  this->m_Listeners.m_Memory.m_pMemory = nullptr;
  this->m_Listeners.m_Memory.m_nAllocationCount = 0;
  this->m_Listeners.m_Memory.m_nGrowSize = 0;
  this->m_Listeners.m_Size = 0;
  this->m_Listeners.m_pElements = nullptr;
  this->m_OnTrue.m_Value.iVal = 0;
  this->m_OnTrue.m_Value.eVal.m_Index = -1;
  this->m_OnTrue.m_Value.fieldType = FIELD_VOID;
  this->m_OnFalse.m_Value.iVal = 0;
  this->m_OnFalse.m_Value.eVal.m_Index = -1;
  this->m_OnFalse.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016BB80
// Name: public: CLogicBranchList::CLogicBranchList(void)
// Source: json
//------------------------------------------------------------------------------
CLogicBranchList *__thiscall CLogicBranchList::CLogicBranchList(CLogicBranchList *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CLogicBranchList_vtbl *)&CLogicBranchList::`vftable';
  this->m_LogicBranchList.m_Memory.m_pMemory = nullptr;
  this->m_LogicBranchList.m_Memory.m_nAllocationCount = 0;
  this->m_LogicBranchList.m_Memory.m_nGrowSize = 0;
  this->m_LogicBranchList.m_Size = 0;
  this->m_LogicBranchList.m_pElements = nullptr;
  this->m_OnAllTrue.m_Value.iVal = 0;
  this->m_OnAllTrue.m_Value.eVal.m_Index = -1;
  this->m_OnAllTrue.m_Value.fieldType = FIELD_VOID;
  this->m_OnAllFalse.m_Value.iVal = 0;
  this->m_OnAllFalse.m_Value.eVal.m_Index = -1;
  this->m_OnAllFalse.m_Value.fieldType = FIELD_VOID;
  this->m_OnMixed.m_Value.iVal = 0;
  this->m_OnMixed.m_Value.eVal.m_Index = -1;
  this->m_OnMixed.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016BBF0
// Name: public: virtual void CLogicScript::RunVScripts(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLogicScript::RunVScripts(CLogicScript *this@<ecx>, int a2@<edi>)
{
  int v3; // ecx
  string_t *i; // eax
  HSCRIPT__ *v5; // ebx
  HSCRIPT__ *v6; // edi
  string_t *m_iszGroupMembers; // ebx
  const char *pszValue; // eax
  HSCRIPT__ *m_hScope; // [esp-Ch] [ebp-24h]
  _DWORD v10[2]; // [esp+4h] [ebp-14h] BYREF
  HSCRIPT__ *hAddScript; // [esp+Ch] [ebp-Ch]
  int iLastMember; // [esp+14h] [ebp-4h]

  v3 = 15;
  for ( i = &this->m_iszGroupMembers[14]; i[1].pszValue == nullptr; i -= 4 )
  {
    if ( i->pszValue != nullptr )
    {
      --v3;
      break;
    }
    if ( i[-1].pszValue != nullptr )
    {
      v3 -= 2;
      break;
    }
    if ( i[-2].pszValue != nullptr )
    {
      v3 -= 3;
      break;
    }
    v3 -= 4;
    if ( v3 < 0 )
    {
      CBaseEntity::RunVScripts(this);
      return;
    }
  }
  iLastMember = v3;
  if ( v3 >= 0 )
  {
    v5 = g_pScriptVM->CompileScript(
           this: g_pScriptVM,
           a2: "EntityGroup <- [];\r\n"
           "function __AppendToScriptGroup( name ) \r\n"
           "{\r\n"
           "\tif ( name.len() == 0 ) \r\n"
           "\t{ \r\n"
           "\t\tEntityGroup.append( null ); \r\n"
           "\t} \r\n"
           "\telse\r\n"
           "\t{ \r\n"
           "\t\tlocal ent = Entities.FindByName( null, name );\r\n"
           "\t\tEntityGroup.append( ent );\r\n"
           "\t\tif ( ent != null )\r\n"
           "\t\t{\r\n"
           "\t\t\tent.ValidateScriptScope();\r\n"
           "\t\t\tent.GetScriptScope().EntityGroup <- EntityGroup;\r\n"
           "\t\t}\r\n"
           "\t}\r\n"
           "}\r\n",
           a3: 0);
    hAddScript = v5;
    if ( v5 != nullptr )
    {
      CBaseEntity::ValidateScriptScope(this);
      CScriptScopeT<CDefScriptScopeBase>::InvalidateCachedValues(this: &this->m_ScriptScope);
      ((void (__thiscall *)(IScriptVM *, HSCRIPT__ *, HSCRIPT__ *, int, int))g_pScriptVM->Run_2)(
        a1: g_pScriptVM,
        a2: v5,
        a3: this->m_ScriptScope.m_hScope,
        a4: 1,
        a5: a2);
      v6 = g_pScriptVM->LookupFunction(this: g_pScriptVM, a2: "__AppendToScriptGroup", a3: this->m_ScriptScope.m_hScope);
      if ( v6 != nullptr )
      {
        if ( iLastMember >= 0 )
        {
          m_iszGroupMembers = this->m_iszGroupMembers;
          ++iLastMember;
          do
          {
            pszValue = m_iszGroupMembers->pszValue;
            if ( m_iszGroupMembers->pszValue == nullptr )
              pszValue = locale;
            m_hScope = this->m_ScriptScope.m_hScope;
            v10[0] = pszValue;
            v10[1] = 32;
            g_pScriptVM->ExecuteFunction(
              this: g_pScriptVM,
              a2: v6,
              a3: (ScriptVariant_t *)v10,
              a4: 1,
              a5: nullptr,
              a6: m_hScope,
              a7: true);
            ++m_iszGroupMembers;
            --iLastMember;
          }
          while ( iLastMember != 0 );
          v5 = hAddScript;
        }
        g_pScriptVM->ReleaseFunction(this: g_pScriptVM, a2: v6);
        g_pScriptVM->ClearValue(this: g_pScriptVM, a2: this->m_ScriptScope.m_hScope, a3: "__AppendToScriptGroup");
      }
      g_pScriptVM->ReleaseScript(this: g_pScriptVM, a2: v5);
    }
  }
  CBaseEntity::RunVScripts(this);
}

//------------------------------------------------------------------------------
// Address: 0x1016BD60
// Name: public: virtual void CMultiSource::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiSource::Spawn(CMultiSource *this)
{
  int v2; // esi
  edict_t *m_pPev; // ecx

  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  v2 = this->m_spawnflags.m_Value | 1;
  if ( this->m_spawnflags.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
    }
    this->m_spawnflags.m_Value = v2;
  }
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CMultiSource::Register,
    thinkTime: 0.0,
    szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1016BDE0
// Name: public: void CLogicBranch::AddLogicBranchListener(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranch::AddLogicBranchListener(CLogicBranch *this, unsigned int pEntity)
{
  unsigned int v2; // edi
  int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHandle<CBaseEntity> *m_pMemory; // ecx
  int v8; // eax
  CHandle<CBaseEntity> *v9; // eax

  v2 = pEntity;
  v3 = -1;
  if ( pEntity != 0 )
    pEntity = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)pEntity + 8))(a1: pEntity);
  else
    pEntity = -1;
  if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: &this->m_Listeners,
         src: (CHandle<CBaseEntity> *)&pEntity) == -1 )
  {
    if ( v2 != 0 )
      v3 = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v2 + 8))(a1: v2);
    m_Size = this->m_Listeners.m_Size;
    m_nAllocationCount = this->m_Listeners.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Listeners,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Listeners.m_Size;
    m_pMemory = this->m_Listeners.m_Memory.m_pMemory;
    v8 = this->m_Listeners.m_Size - m_Size - 1;
    this->m_Listeners.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_Listeners.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      v9->m_Index = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016BEA0
// Name: private: virtual void CLogicBranchList::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicBranchList::Activate(CLogicBranchList *this)
{
  CLogicBranchList *v1; // esi
  CLogicBranch *v2; // ebx
  const char *pszValue; // eax
  CBaseEntity *EntityGeneric; // eax
  unsigned int m_Index; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHandle<CBaseEntity> *m_pMemory; // ecx
  int v9; // eax
  CHandle<CBaseEntity> *v10; // eax
  CHandle<CBaseEntity> *v11; // edi
  const char *v12; // eax
  const char *DebugName; // [esp-4h] [ebp-20h]
  unsigned int v14; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  string_t *m_nLogicBranchNames; // [esp+18h] [ebp-4h]

  v1 = this;
  m_nLogicBranchNames = this->m_nLogicBranchNames;
  for ( i = 16; i != 0; --i )
  {
    v2 = nullptr;
    while ( 1 )
    {
      pszValue = m_nLogicBranchNames->pszValue;
      if ( m_nLogicBranchNames->pszValue == nullptr )
        pszValue = locale;
      EntityGeneric = CGlobalEntityList::FindEntityGeneric(
                        this: &gEntList,
                        pStartEntity: v2,
                        szName: pszValue,
                        pSearchingEntity: v1,
                        pActivator: nullptr,
                        pCaller: nullptr);
      v2 = (CLogicBranch *)EntityGeneric;
      if ( EntityGeneric == nullptr )
        break;
      if ( EntityGeneric->m_iClassname.pszValue == "logic_branch"
        || CBaseEntity::ClassMatchesComplex(this: EntityGeneric, pszClassOrWildcard: "logic_branch") != 0 )
      {
        CLogicBranch::AddLogicBranchListener(this: v2, pEntity: (unsigned int)v1);
        m_Index = v2->GetRefEHandle(this: v2)->m_Index;
        m_Size = v1->m_LogicBranchList.m_Size;
        m_nAllocationCount = v1->m_LogicBranchList.m_Memory.m_nAllocationCount;
        v14 = m_Index;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_LogicBranchList,
            num: m_Size - m_nAllocationCount + 1);
        ++v1->m_LogicBranchList.m_Size;
        m_pMemory = v1->m_LogicBranchList.m_Memory.m_pMemory;
        v9 = v1->m_LogicBranchList.m_Size - m_Size - 1;
        v1->m_LogicBranchList.m_pElements = m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = v1->m_LogicBranchList.m_Memory.m_pMemory;
        v1 = this;
        v11 = &v10[m_Size];
        if ( v11 != nullptr )
          v11->m_Index = v14;
      }
      else
      {
        DebugName = CBaseEntity::GetDebugName(this: v2);
        v12 = CBaseEntity::GetDebugName(this: v1);
        DevWarning(a1: "logic_branchlist %s refers to entity %s, which is not a logic_branch\n", v12, DebugName);
      }
    }
    ++m_nLogicBranchNames;
  }
  CBaseEntity::Activate(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10405840
// Name: CLogicScript_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicScript_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicScript>(__formal: nullptr);
  CLogicScript_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405870
// Name: CLogicCompareInteger_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicCompareInteger_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicCompareInteger>(__formal: nullptr);
  CLogicCompareInteger_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104058A0
// Name: CLogicRegisterActivator_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicRegisterActivator_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicRegisterActivator>(__formal: nullptr);
  CLogicRegisterActivator_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104058D0
// Name: CTimerEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTimerEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTimerEntity>(__formal: nullptr);
  CTimerEntity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405900
// Name: CLogicLineToEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicLineToEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicLineToEntity>(__formal: nullptr);
  CLogicLineToEntity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405930
// Name: CMathRemap_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMathRemap_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMathRemap>(__formal: nullptr);
  CMathRemap_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405960
// Name: CMathColorBlend_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMathColorBlend_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMathColorBlend>(__formal: nullptr);
  CMathColorBlend_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104059A0
// Name: CEnvGlobal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvGlobal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvGlobal>(__formal: nullptr);
  CEnvGlobal_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104059D0
// Name: CMultiSource_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMultiSource_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMultiSource>(__formal: nullptr);
  CMultiSource_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405A20
// Name: CMathCounter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMathCounter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMathCounter>(__formal: nullptr);
  CMathCounter_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405A50
// Name: CLogicCase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicCase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicCase>(__formal: nullptr);
  CLogicCase_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405A80
// Name: CLogicCompare_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicCompare_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicCompare>(__formal: nullptr);
  CLogicCompare_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405AB0
// Name: CLogicBranch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicBranch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicBranch>(__formal: nullptr);
  CLogicBranch_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405AE0
// Name: CLogicAutosave_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicAutosave_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicAutosave>(__formal: nullptr);
  CLogicAutosave_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405B10
// Name: CLogicActiveAutosave_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicActiveAutosave_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicActiveAutosave>(__formal: nullptr);
  CLogicActiveAutosave_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405B20
// Name: CLogicCollisionPair_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicCollisionPair_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicCollisionPair>(__formal: nullptr);
  CLogicCollisionPair_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405B70
// Name: CLogicBranchList_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicBranchList_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicBranchList>(__formal: nullptr);
  CLogicBranchList_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104059B0
// Name: _dynamic_initializer_for__env_global__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_global__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvGlobal> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_global,
           a3: "env_global");
}

//------------------------------------------------------------------------------
// Address: 0x104059E0
// Name: _dynamic_initializer_for__multisource__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__multisource__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CMultiSource> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &multisource,
           a3: "multisource");
}
