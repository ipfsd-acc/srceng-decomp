// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system/tilegen_actions.cpp
// Functions: 54
// ============================================================

#include "missionchooser\layout_system\tilegen_actions.h"

//------------------------------------------------------------------------------
// Address: 0x10012200
// Name: public: bool CLayoutSystem::ShouldStopProcessingActions(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLayoutSystem::ShouldStopProcessingActions(CLayoutSystem *this)
{
  return this->m_CurrentIterationState.m_bStopIteration || this->m_bLayoutError;
}

//------------------------------------------------------------------------------
// Address: 0x10012220
// Name: public: CTilegenAction_AddRoomCandidates::CTilegenAction_AddRoomCandidates(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_AddRoomCandidates *__thiscall CTilegenAction_AddRoomCandidates::CTilegenAction_AddRoomCandidates(
        CTilegenAction_AddRoomCandidates *this)
{
  this->__vftable = (CTilegenAction_AddRoomCandidates_vtbl *)&CTilegenAction_AddRoomCandidates::`vftable';
  this->m_pLevelTheme = nullptr;
  this->m_pThemeNameExpression = nullptr;
  this->m_pExitFilter = nullptr;
  this->m_pRoomTemplateFilter = nullptr;
  this->m_pRoomCandidateFilter = nullptr;
  this->m_pRoomCandidateFilterAction = nullptr;
  this->m_pRoomCandidateFilterCondition = nullptr;
  this->m_bExcludeGlobalFilters = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012250
// Name: public: virtual CTilegenAction_AddRoomCandidates::~CTilegenAction_AddRoomCandidates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_AddRoomCandidates::~CTilegenAction_AddRoomCandidates(
        CTilegenAction_AddRoomCandidates *this)
{
  ITilegenExpression<char const *> *m_pThemeNameExpression; // ecx
  ITilegenExpression<bool> *m_pExitFilter; // ecx
  ITilegenExpression<bool> *m_pRoomTemplateFilter; // ecx
  ITilegenExpression<bool> *m_pRoomCandidateFilter; // ecx
  ITilegenAction *m_pRoomCandidateFilterAction; // ecx
  ITilegenExpression<bool> *m_pRoomCandidateFilterCondition; // ecx

  m_pThemeNameExpression = this->m_pThemeNameExpression;
  this->__vftable = (CTilegenAction_AddRoomCandidates_vtbl *)&CTilegenAction_AddRoomCandidates::`vftable';
  if ( m_pThemeNameExpression != nullptr )
    ((void (__thiscall *)(ITilegenExpression<char const *> *, int))m_pThemeNameExpression->dtr_ITilegenExpression<char const *>)(
      a1: m_pThemeNameExpression,
      a2: 1);
  m_pExitFilter = this->m_pExitFilter;
  if ( m_pExitFilter != nullptr )
    ((void (__thiscall *)(ITilegenExpression<bool> *, int))m_pExitFilter->dtr_ITilegenExpression<bool>)(
      a1: m_pExitFilter,
      a2: 1);
  m_pRoomTemplateFilter = this->m_pRoomTemplateFilter;
  if ( m_pRoomTemplateFilter != nullptr )
    ((void (__thiscall *)(ITilegenExpression<bool> *, int))m_pRoomTemplateFilter->dtr_ITilegenExpression<bool>)(
      a1: m_pRoomTemplateFilter,
      a2: 1);
  m_pRoomCandidateFilter = this->m_pRoomCandidateFilter;
  if ( m_pRoomCandidateFilter != nullptr )
    ((void (__thiscall *)(ITilegenExpression<bool> *, int))m_pRoomCandidateFilter->dtr_ITilegenExpression<bool>)(
      a1: m_pRoomCandidateFilter,
      a2: 1);
  m_pRoomCandidateFilterAction = this->m_pRoomCandidateFilterAction;
  if ( m_pRoomCandidateFilterAction != nullptr )
    ((void (__thiscall *)(ITilegenAction *, int))m_pRoomCandidateFilterAction->dtr_ITilegenAction)(
      a1: m_pRoomCandidateFilterAction,
      a2: 1);
  m_pRoomCandidateFilterCondition = this->m_pRoomCandidateFilterCondition;
  if ( m_pRoomCandidateFilterCondition != nullptr )
    ((void (__thiscall *)(ITilegenExpression<bool> *, int))m_pRoomCandidateFilterCondition->dtr_ITilegenExpression<bool>)(
      a1: m_pRoomCandidateFilterCondition,
      a2: 1);
  this->__vftable = (CTilegenAction_AddRoomCandidates_vtbl *)&ITilegenAction::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100122C0
// Name: public: CTilegenAction_AddRoomCandidatesAtLocation::CTilegenAction_AddRoomCandidatesAtLocation(class ITilegenExpression<char const __near *> __near *,class ITilegenExpression<int> __near *,class ITilegenExpression<int> __near *,class ITilegenExpression<bool> __near *)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_AddRoomCandidatesAtLocation *__thiscall CTilegenAction_AddRoomCandidatesAtLocation::CTilegenAction_AddRoomCandidatesAtLocation(
        CTilegenAction_AddRoomCandidatesAtLocation *this,
        ITilegenExpression<char const *> *pThemeNameExpression,
        ITilegenExpression<int> *pXExpression,
        ITilegenExpression<int> *pYExpression,
        ITilegenExpression<bool> *pRoomTemplateFilter)
{
  this->m_pThemeNameExpression = pThemeNameExpression;
  this->m_pXExpression = pXExpression;
  this->__vftable = (CTilegenAction_AddRoomCandidatesAtLocation_vtbl *)&CTilegenAction_AddRoomCandidatesAtLocation::`vftable';
  this->m_pLevelTheme = nullptr;
  this->m_pYExpression = pYExpression;
  this->m_pRoomTemplateFilter = pRoomTemplateFilter;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100122F0
// Name: public: virtual bool CTilegenAction_ChooseCandidate::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenAction_ChooseCandidate::LoadFromKeyValues(
        CTilegenAction_ChooseCandidate *this,
        KeyValues *pKeyValues)
{
  this->m_bStopProcessingActionsOnSuccess = KeyValues::GetInt(
                                              this: pKeyValues,
                                              keyName: "stop_processing",
                                              defaultValue: 0) != 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012320
// Name: public: CTilegenAction_FilterCandidatesByDirection::CTilegenAction_FilterCandidatesByDirection(class ITilegenExpression<char const __near *> __near *,class ITilegenExpression<int> __near *)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_FilterCandidatesByDirection *__thiscall CTilegenAction_FilterCandidatesByDirection::CTilegenAction_FilterCandidatesByDirection(
        CTilegenAction_FilterCandidatesByDirection *this,
        ITilegenExpression<char const *> *pDirectionExpression,
        ITilegenExpression<int> *pThresholdExpression)
{
  this->__vftable = (CTilegenAction_FilterCandidatesByDirection_vtbl *)&CTilegenAction_FilterCandidatesByDirection::`vftable';
  this->m_pDirectionExpression = pDirectionExpression;
  this->m_pThresholdExpression = pThresholdExpression;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012340
// Name: public: CTilegenAction_SwitchState::CTilegenAction_SwitchState(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_SwitchState *__thiscall CTilegenAction_SwitchState::CTilegenAction_SwitchState(
        CTilegenAction_SwitchState *this)
{
  this->__vftable = (CTilegenAction_SwitchState_vtbl *)&CTilegenAction_SwitchState::`vftable';
  this->m_pNewStateExpression = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012350
// Name: public: virtual void CTilegenAction_SwitchState::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_SwitchState::Execute(CTilegenAction_SwitchState *this, CLayoutSystem *pLayoutSystem)
{
  CTilegenStateList *ParentStateList; // eax
  CTilegenState *NextState; // eax
  const char *v4; // eax
  CTilegenState *m_pCurrentState; // [esp-4h] [ebp-8h]

  if ( this->m_pNewStateExpression != nullptr )
  {
    v4 = this->m_pNewStateExpression->Evaluate(this: this->m_pNewStateExpression, a2: &pLayoutSystem->m_FreeVariables);
    CLayoutSystem::TransitionToState(this: pLayoutSystem, pStateName: v4);
  }
  else
  {
    m_pCurrentState = pLayoutSystem->m_pCurrentState;
    ParentStateList = CTilegenStateList::GetParentStateList(this: &m_pCurrentState->m_ChildStates);
    NextState = CTilegenStateList::GetNextState(this: ParentStateList, pState: m_pCurrentState);
    if ( NextState != nullptr )
      CLayoutSystem::TransitionToState(this: pLayoutSystem, pState: NextState);
    else
      CLayoutSystem::OnFinished(this: pLayoutSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100123B0
// Name: public: virtual void CTilegenAction_FinishGeneration::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_FinishGeneration::Execute(
        CTilegenAction_FinishGeneration *this,
        CLayoutSystem *pLayoutSystem)
{
  CLayoutSystem::OnFinished(this: pLayoutSystem);
}

//------------------------------------------------------------------------------
// Address: 0x100123C0
// Name: public: virtual void CTilegenAction_EpicFail::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_EpicFail::Execute(CTilegenAction_EpicFail *this, CLayoutSystem *pLayoutSystem)
{
  CLayoutSystem::OnError(this: pLayoutSystem);
}

//------------------------------------------------------------------------------
// Address: 0x100123D0
// Name: public: virtual void CTilegenAction_EnsureRoomExists::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_EnsureRoomExists::Execute(
        CTilegenAction_EnsureRoomExists *this,
        CLayoutSystem *pLayoutSystem)
{
  const char *v2; // esi
  CLevelTheme *Theme; // eax
  char roomName[64]; // [esp+8h] [ebp-80h] BYREF
  char themeName[64]; // [esp+48h] [ebp-40h] BYREF

  if ( this->m_pRoomNameExpression != nullptr
    && (v2 = this->m_pRoomNameExpression->Evaluate(
               this: this->m_pRoomNameExpression,
               a2: &pLayoutSystem->m_FreeVariables)) != nullptr )
  {
    if ( CLevelTheme::SplitThemeAndRoom(
           pszFullName: v2,
           szThemeOut: themeName,
           nThemeOutSize: 64,
           szRoomOut: roomName,
           nRoomOutSize: 64) != 0 )
    {
      Theme = CLevelTheme::FindTheme(szThemeName: themeName);
      if ( Theme != nullptr )
      {
        if ( CLevelTheme::FindRoom(this: Theme, szRoomTemplate: roomName) != nullptr )
          return;
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Room %s not found.\n");
      }
      else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      {
        _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Theme %s not found.\n");
      }
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    {
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Could not split theme name from room (full name: %s).\n");
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Room name expression invalid.\n");
    CLayoutSystem::OnError(this: pLayoutSystem);
    return;
  }
  CLayoutSystem::OnError(this: pLayoutSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10012510
// Name: public: CTilegenAction_AddConnectorRoomCandidates::CTilegenAction_AddConnectorRoomCandidates(class ITilegenAction __near *)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_AddConnectorRoomCandidates *__thiscall CTilegenAction_AddConnectorRoomCandidates::CTilegenAction_AddConnectorRoomCandidates(
        CTilegenAction_AddConnectorRoomCandidates *this,
        ITilegenAction *pAddRoomCandidates)
{
  this->m_pLevelTheme = nullptr;
  this->m_pTargetThemeNameExpression = nullptr;
  this->m_pTargetRoomTemplateFilter = nullptr;
  this->m_pTargetRoomTemplate = nullptr;
  this->__vftable = (CTilegenAction_AddConnectorRoomCandidates_vtbl *)&CTilegenAction_AddConnectorRoomCandidates::`vftable';
  this->m_pAddConnectorCandidates = pAddRoomCandidates;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012540
// Name: public: CTilegenAction_LoadLayout::CTilegenAction_LoadLayout(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_LoadLayout *__thiscall CTilegenAction_LoadLayout::CTilegenAction_LoadLayout(
        CTilegenAction_LoadLayout *this)
{
  this->__vftable = (CTilegenAction_LoadLayout_vtbl *)&CTilegenAction_LoadLayout::`vftable';
  this->m_LayoutFilename[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012550
// Name: public: virtual bool CTilegenAction_LoadLayout::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenAction_LoadLayout::LoadFromKeyValues(CTilegenAction_LoadLayout *this, KeyValues *pKeyValues)
{
  const char *String; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "filename", defaultValue: nullptr);
  if ( String != nullptr )
  {
    V_strncpy(pDest: this->m_LayoutFilename, pSrc: String, maxLen: 260);
    return 1;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    {
      this->GetTypeName(this);
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "No 'filename' specified in %s.\n");
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100128B0
// Name: public: virtual void CTilegenAction_NestedActions::OnBeginGeneration(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_NestedActions::OnBeginGeneration(
        CTilegenAction_NestedActions *this,
        CLayoutSystem *pLayoutSystem)
{
  int i; // esi
  ITilegenAction *m_pAction; // ecx

  for ( i = 0; i < this->m_NestedActions.m_Size; ++i )
  {
    m_pAction = this->m_NestedActions.m_Memory.m_pMemory[i].m_pAction;
    m_pAction->OnBeginGeneration(this: m_pAction, a2: pLayoutSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100128E0
// Name: public: virtual void CTilegenAction_NestedActions::OnStateChanged(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_NestedActions::OnStateChanged(
        CTilegenAction_NestedActions *this,
        CLayoutSystem *pLayoutSystem)
{
  int i; // esi
  ITilegenAction *m_pAction; // ecx

  for ( i = 0; i < this->m_NestedActions.m_Size; ++i )
  {
    m_pAction = this->m_NestedActions.m_Memory.m_pMemory[i].m_pAction;
    m_pAction->OnStateChanged(this: m_pAction, a2: pLayoutSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012910
// Name: public: virtual void CTilegenAction_NestedActions::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_NestedActions::Execute(CTilegenAction_NestedActions *this, CLayoutSystem *pLayoutSystem)
{
  int v3; // esi

  if ( this->m_pWhileCondition == nullptr )
    goto LABEL_3;
  while ( this->m_pWhileCondition->Evaluate(this: this->m_pWhileCondition, a2: &pLayoutSystem->m_FreeVariables) )
  {
LABEL_3:
    v3 = 0;
    if ( this->m_NestedActions.m_Size > 0 )
    {
      while ( !CLayoutSystem::ShouldStopProcessingActions(this: pLayoutSystem) )
      {
        CLayoutSystem::ExecuteAction(
          this: pLayoutSystem,
          pAction: this->m_NestedActions.m_Memory.m_pMemory[v3].m_pAction,
          pCondition: this->m_NestedActions.m_Memory.m_pMemory[v3].m_pCondition);
        if ( ++v3 >= this->m_NestedActions.m_Size )
          goto LABEL_6;
      }
      return;
    }
LABEL_6:
    if ( this->m_pWhileCondition == nullptr )
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012980
// Name: public: virtual void CTilegenAction_ChooseCandidate::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_ChooseCandidate::Execute(
        CTilegenAction_ChooseCandidate *this,
        CLayoutSystem *pLayoutSystem)
{
  CUtlVector<CRoomCandidate,CUtlMemory<CRoomCandidate,int> > *m_pRoomCandidateList; // esi
  int m_Size; // eax
  float v5; // xmm0_4
  int v6; // ecx
  float *p_m_flCandidateChance; // eax
  double v8; // st7
  int v9; // edx
  int v10; // eax
  float v11; // xmm0_4
  float *v12; // ecx
  float v14; // [esp+1Ch] [ebp+8h]
  float v15; // [esp+1Ch] [ebp+8h]

  m_pRoomCandidateList = pLayoutSystem->m_CurrentIterationState.m_pRoomCandidateList;
  m_Size = m_pRoomCandidateList->m_Size;
  if ( m_Size != 0 )
  {
    v5 = 0.0;
    v14 = 0.0;
    if ( m_Size > 0 )
    {
      v6 = m_pRoomCandidateList->m_Size;
      p_m_flCandidateChance = &m_pRoomCandidateList->m_Memory.m_pMemory->m_flCandidateChance;
      do
      {
        v5 = v5 + *p_m_flCandidateChance;
        p_m_flCandidateChance += 5;
        --v6;
      }
      while ( v6 != 0 );
      v14 = v5;
    }
    v8 = ((double (__thiscall *)(CLayoutSystem *, _DWORD, int))pLayoutSystem->m_Random.RandomFloat)(
           a1: pLayoutSystem,
           a2: 0,
           a3: 1065353216);
    v9 = m_pRoomCandidateList->m_Size;
    v10 = 0;
    v15 = v8 * v14;
    if ( v9 > 0 )
    {
      v11 = v15;
      v12 = &m_pRoomCandidateList->m_Memory.m_pMemory->m_flCandidateChance;
      do
      {
        v11 = v11 - *v12;
        if ( v11 <= 0.0 )
          break;
        ++v10;
        v12 += 5;
      }
      while ( v10 < v9 );
    }
    if ( v10 == v9 )
      v10 = v9 - 1;
    CLayoutSystem::TryPlaceRoom(this: pLayoutSystem, pRoomCandidate: &m_pRoomCandidateList->m_Memory.m_pMemory[v10]);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 0, a3: "Chose room candidate %s at position (%d, %d).\n");
    m_pRoomCandidateList->m_Size = 0;
    if ( this->m_bStopProcessingActionsOnSuccess )
      pLayoutSystem->m_CurrentIterationState.m_bStopIteration = true;
    CFreeVariableMap::SetOrCreateFreeVariable(
      this: &pLayoutSystem->m_FreeVariables,
      pName: "ChoseCandidate",
      pValue: (void *)1);
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 0, a3: "No more room candidates to choose from.\n");
    CFreeVariableMap::SetOrCreateFreeVariable(
      this: &pLayoutSystem->m_FreeVariables,
      pName: "ChoseCandidate",
      pValue: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012AD0
// Name: public: virtual void CTilegenAction_FilterCandidatesByDirection::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_FilterCandidatesByDirection::Execute(
        CTilegenAction_FilterCandidatesByDirection *this,
        CLayoutSystem *pLayoutSystem)
{
  const char *v3; // ebx
  int v4; // eax
  ExitDirection_t DirectionFromString; // eax
  CUtlVector<CRoomCandidate,CUtlMemory<CRoomCandidate,int> > *v6; // edi
  int m_Size; // ebx
  int *p_m_iXPos; // esi
  int v9; // ecx
  int v10; // edx
  int v11; // ebx
  int v12; // ecx
  CRoomCandidate *m_pMemory; // edx
  int m_iYPos; // esi
  int m_iXPos; // edi
  int v16; // esi
  __int64 v17; // xmm0_8
  int v18; // esi
  ExitDirection_t direction; // [esp+8h] [ebp-10h]
  int nThreshold; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  CUtlVector<CRoomCandidate,CUtlMemory<CRoomCandidate,int> > *pRoomCandidateList; // [esp+14h] [ebp-4h]
  int nHighScore; // [esp+20h] [ebp+8h]
  int nHighScorea; // [esp+20h] [ebp+8h]

  pRoomCandidateList = pLayoutSystem->m_CurrentIterationState.m_pRoomCandidateList;
  if ( pRoomCandidateList->m_Size != 0 )
  {
    v3 = this->m_pDirectionExpression->Evaluate(this: this->m_pDirectionExpression, a2: &pLayoutSystem->m_FreeVariables);
    v4 = this->m_pThresholdExpression->Evaluate(this: this->m_pThresholdExpression, a2: &pLayoutSystem->m_FreeVariables);
    nThreshold = v4 < 0 ? 0 : v4;
    DirectionFromString = GetDirectionFromString(pDirectionString: v3);
    direction = DirectionFromString;
    if ( (unsigned int)DirectionFromString > EXITDIR_WEST )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Invalid direction specified: %s.\n");
    }
    else
    {
      v6 = pRoomCandidateList;
      m_Size = pRoomCandidateList->m_Size;
      nHighScore = 0x80000000;
      if ( m_Size > 0 )
      {
        p_m_iXPos = &pRoomCandidateList->m_Memory.m_pMemory->m_iXPos;
        v21 = pRoomCandidateList->m_Size;
        do
        {
          v9 = p_m_iXPos[1];
          v10 = *p_m_iXPos;
          switch ( DirectionFromString )
          {
            case EXITDIR_BEGIN:
              break;
            case EXITDIR_EAST:
              goto $LN33;
            case EXITDIR_SOUTH:
              v9 = -v9;
              break;
            case EXITDIR_WEST:
              v10 = -v10;
$LN33:
              v9 = v10;
              break;
          }
          if ( v9 > nHighScore )
            nHighScore = v9;
          p_m_iXPos += 5;
          --v21;
        }
        while ( v21 != 0 );
      }
      v11 = m_Size - 1;
      if ( v11 >= 0 )
      {
        nHighScorea = nHighScore - nThreshold;
        v12 = v11;
        do
        {
          m_pMemory = v6->m_Memory.m_pMemory;
          m_iYPos = v6->m_Memory.m_pMemory[v12].m_iYPos;
          m_iXPos = v6->m_Memory.m_pMemory[v12].m_iXPos;
          switch ( DirectionFromString )
          {
            case EXITDIR_BEGIN:
              break;
            case EXITDIR_EAST:
              goto $LN47;
            case EXITDIR_SOUTH:
              m_iYPos = -m_iYPos;
              break;
            case EXITDIR_WEST:
              m_iXPos = -m_iXPos;
$LN47:
              m_iYPos = m_iXPos;
              break;
            default:
              m_iYPos = 0x80000000;
              break;
          }
          v6 = pRoomCandidateList;
          if ( m_iYPos < nHighScorea )
          {
            v16 = pRoomCandidateList->m_Size;
            if ( v16 > 0 )
            {
              if ( v11 != v16 - 1 )
              {
                v17 = *(_QWORD *)&m_pMemory[v16 - 1].m_pRoomTemplate;
                v18 = (int)&m_pMemory[v16 - 1];
                *(_QWORD *)&m_pMemory[v12].m_pRoomTemplate = v17;
                *(_QWORD *)&m_pMemory[v12].m_iYPos = *(_QWORD *)(v18 + 8);
                m_pMemory[v12].m_flCandidateChance = *(float *)(v18 + 16);
              }
              --pRoomCandidateList->m_Size;
              DirectionFromString = direction;
            }
          }
          --v12;
          --v11;
        }
        while ( v11 >= 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012C70
// Name: public: virtual void CTilegenAction_FilterCandidatesForLinearGrowth::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_FilterCandidatesForLinearGrowth::Execute(
        CTilegenAction_FilterCandidatesForLinearGrowth *this,
        CLayoutSystem *pLayoutSystem)
{
  CUtlVector<CRoomCandidate,CUtlMemory<CRoomCandidate,int> > *m_pRoomCandidateList; // edi
  int v3; // ebx
  int m_Size; // esi
  int p_m_pExit; // ecx
  int v6; // eax
  int v7; // esi
  int v8; // ecx
  CRoomCandidate *m_pMemory; // eax
  int m_nPlacementIndex; // edx
  int v11; // edx
  int v12; // edx
  __int64 v13; // xmm0_8
  int v14; // edx
  int nHighestPlacementIndex; // [esp+4h] [ebp-4h]
  int nMinimumPlacementIndex; // [esp+10h] [ebp+8h]

  m_pRoomCandidateList = pLayoutSystem->m_CurrentIterationState.m_pRoomCandidateList;
  if ( m_pRoomCandidateList->m_Size != 0 )
  {
    v3 = this->m_pThresholdExpression->Evaluate(this: this->m_pThresholdExpression, a2: &pLayoutSystem->m_FreeVariables);
    if ( v3 < 0 )
      v3 = 0x7FFFFFFF;
    m_Size = m_pRoomCandidateList->m_Size;
    nHighestPlacementIndex = -1;
    if ( m_Size > 0 )
    {
      p_m_pExit = (int)&m_pRoomCandidateList->m_Memory.m_pMemory->m_pExit;
      v6 = m_pRoomCandidateList->m_Size;
      do
      {
        if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_m_pExit + 12) + 20) > nHighestPlacementIndex )
          nHighestPlacementIndex = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_m_pExit + 12) + 20);
        p_m_pExit += 20;
        --v6;
      }
      while ( v6 != 0 );
    }
    v7 = m_Size - 1;
    nMinimumPlacementIndex = pLayoutSystem->m_pMapLayout->m_PlacedRooms.m_Size - v3 - 1;
    if ( v7 >= 0 )
    {
      v8 = v7;
      do
      {
        m_pMemory = m_pRoomCandidateList->m_Memory.m_pMemory;
        m_nPlacementIndex = m_pRoomCandidateList->m_Memory.m_pMemory[v8].m_pExit->pSourceRoom->m_nPlacementIndex;
        if ( m_nPlacementIndex < nHighestPlacementIndex || m_nPlacementIndex < nMinimumPlacementIndex )
        {
          v11 = m_pRoomCandidateList->m_Size;
          if ( v11 > 0 )
          {
            if ( v7 != v11 - 1 )
            {
              v12 = v11;
              v13 = *(_QWORD *)&m_pMemory[v12 - 1].m_pRoomTemplate;
              v14 = (int)&m_pMemory[v12 - 1];
              *(_QWORD *)&m_pMemory[v8].m_pRoomTemplate = v13;
              *(_QWORD *)&m_pMemory[v8].m_iYPos = *(_QWORD *)(v14 + 8);
              m_pMemory[v8].m_flCandidateChance = *(float *)(v14 + 16);
            }
            --m_pRoomCandidateList->m_Size;
          }
        }
        --v8;
        --v7;
      }
      while ( v7 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012D50
// Name: public: virtual void CTilegenAction_LoadLayout::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_LoadLayout::Execute(CTilegenAction_LoadLayout *this, CLayoutSystem *pLayoutSystem)
{
  CMapLayout *v3; // eax
  CMapLayout *v4; // edi
  int v5; // ebx
  _DWORD *v6; // esi
  int v7; // ecx
  const CRoomTemplate *v8; // edx
  CRoomCandidate roomCandidate; // [esp+8h] [ebp-18h] BYREF
  char *m_LayoutFilename; // [esp+1Ch] [ebp-4h]

  v3 = (CMapLayout *)operator new(nSize: 0xE264u);
  if ( v3 != nullptr )
    v4 = CMapLayout::CMapLayout(this: v3, pGenerationOptions: nullptr);
  else
    v4 = nullptr;
  m_LayoutFilename = this->m_LayoutFilename;
  if ( CMapLayout::LoadMapLayout(this: v4, filename: this->m_LayoutFilename) )
  {
    v5 = 0;
    if ( v4->m_PlacedRooms.m_Size > 0 )
    {
      while ( 1 )
      {
        v6 = &v4->m_PlacedRooms.m_Memory.m_pMemory[v5]->__vftable;
        v7 = v6[1];
        v8 = (const CRoomTemplate *)v6[3];
        roomCandidate.m_iYPos = v6[2];
        roomCandidate.m_iXPos = v7;
        roomCandidate.m_pRoomTemplate = v8;
        roomCandidate.m_pExit = nullptr;
        roomCandidate.m_flCandidateChance = 0.0;
        if ( !CLayoutSystem::TryPlaceRoom(this: pLayoutSystem, pRoomCandidate: &roomCandidate) )
          break;
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 0) != 0 )
          _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 0, a3: "Chose room candidate %s at position (%d, %d).\n");
        if ( ++v5 >= v4->m_PlacedRooms.m_Size )
          return;
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Unable to place room template '%s' at position (%d, %d) based on data from layout file '%s'.\n");
      CLayoutSystem::OnError(this: pLayoutSystem);
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Unable to load map layout '%s'.\n");
    CLayoutSystem::OnError(this: pLayoutSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012FD0
// Name: public: int CUtlSortVector<struct CTilegenAction_PlaceComponent::RoomPlacementInstance_t,class CTilegenAction_PlaceComponent::CRoomPlacementInstanceLessFunc>::FindLessOrEqual(struct CTilegenAction_PlaceComponent::RoomPlacementInstance_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CTilegenAction_PlaceComponent::RoomPlacementInstance_t,CTilegenAction_PlaceComponent::CRoomPlacementInstanceLessFunc>::FindLessOrEqual(
        CUtlSortVector<CTilegenAction_PlaceComponent::RoomPlacementInstance_t,CTilegenAction_PlaceComponent::CRoomPlacementInstanceLessFunc> *this,
        const CTilegenAction_PlaceComponent::RoomPlacementInstance_t *src)
{
  int v3; // edx
  int v4; // ecx
  CTilegenAction_PlaceComponent::RoomPlacementInstance_t *m_pMemory; // esi
  float m_flPlacementFraction; // xmm1_4
  int result; // eax
  float v8; // xmm0_4

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    m_flPlacementFraction = src->m_flPlacementFraction;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].m_flPlacementFraction;
      if ( m_flPlacementFraction <= v8 )
      {
        if ( v8 <= m_flPlacementFraction )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10013570
// Name: public: CTilegenAction_NestedActions::CTilegenAction_NestedActions(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_NestedActions *__thiscall CTilegenAction_NestedActions::CTilegenAction_NestedActions(
        CTilegenAction_NestedActions *this)
{
  this->__vftable = (CTilegenAction_NestedActions_vtbl *)&CTilegenAction_NestedActions::`vftable';
  this->m_NestedActions.m_Memory.m_pMemory = nullptr;
  this->m_NestedActions.m_Memory.m_nAllocationCount = 0;
  this->m_NestedActions.m_Memory.m_nGrowSize = 0;
  this->m_NestedActions.m_Size = 0;
  this->m_NestedActions.m_pElements = nullptr;
  this->m_pWhileCondition = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10013590
// Name: public: virtual CTilegenAction_NestedActions::~CTilegenAction_NestedActions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_NestedActions::~CTilegenAction_NestedActions(CTilegenAction_NestedActions *this)
{
  int v2; // edi
  ITilegenAction *m_pAction; // ecx
  ITilegenExpression<bool> *m_pCondition; // ecx
  ITilegenExpression<bool> *m_pWhileCondition; // ecx
  ActionConditionPair_t *m_pMemory; // eax

  v2 = 0;
  for ( this->__vftable = (CTilegenAction_NestedActions_vtbl *)&CTilegenAction_NestedActions::`vftable';
        v2 < this->m_NestedActions.m_Size;
        ++v2 )
  {
    m_pAction = this->m_NestedActions.m_Memory.m_pMemory[v2].m_pAction;
    if ( m_pAction != nullptr )
      ((void (__thiscall *)(ITilegenAction *, int))m_pAction->dtr_ITilegenAction)(a1: m_pAction, a2: 1);
    m_pCondition = this->m_NestedActions.m_Memory.m_pMemory[v2].m_pCondition;
    if ( m_pCondition != nullptr )
      ((void (__thiscall *)(ITilegenExpression<bool> *, int))m_pCondition->dtr_ITilegenExpression<bool>)(
        a1: m_pCondition,
        a2: 1);
  }
  m_pWhileCondition = this->m_pWhileCondition;
  if ( m_pWhileCondition != nullptr )
    ((void (__thiscall *)(ITilegenExpression<bool> *, int))m_pWhileCondition->dtr_ITilegenExpression<bool>)(
      a1: m_pWhileCondition,
      a2: 1);
  this->m_NestedActions.m_Size = 0;
  if ( this->m_NestedActions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_NestedActions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NestedActions.m_Memory.m_pMemory);
      this->m_NestedActions.m_Memory.m_pMemory = nullptr;
    }
    this->m_NestedActions.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_NestedActions.m_Memory.m_pMemory;
  this->m_NestedActions.m_pElements = m_pMemory;
  if ( this->m_NestedActions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_NestedActions.m_Memory.m_pMemory = nullptr;
    }
    this->m_NestedActions.m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CTilegenAction_NestedActions_vtbl *)&ITilegenAction::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10013640
// Name: public: int CUtlSortVector<struct CTilegenAction_PlaceComponent::RoomPlacementInstance_t,class CTilegenAction_PlaceComponent::CRoomPlacementInstanceLessFunc>::Insert(struct CTilegenAction_PlaceComponent::RoomPlacementInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CTilegenAction_PlaceComponent::RoomPlacementInstance_t,CTilegenAction_PlaceComponent::CRoomPlacementInstanceLessFunc>::Insert(
        CUtlSortVector<CTilegenAction_PlaceComponent::RoomPlacementInstance_t,CTilegenAction_PlaceComponent::CRoomPlacementInstanceLessFunc> *this,
        const CTilegenAction_PlaceComponent::RoomPlacementInstance_t *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  CTilegenAction_PlaceComponent::RoomPlacementInstance_t *m_pMemory; // ecx
  int v8; // eax
  CTilegenAction_PlaceComponent::RoomPlacementInstance_t *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<CTilegenAction_PlaceComponent::RoomPlacementInstance_t,CTilegenAction_PlaceComponent::CRoomPlacementInstanceLessFunc>::FindLessOrEqual(
                  this,
                  src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 12 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100138D0
// Name: public: virtual bool CTilegenAction_NestedActions::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenAction_NestedActions::LoadFromKeyValues(
        CTilegenAction_NestedActions *this,
        KeyValues *pKeyValues)
{
  CTilegenAction_NestedActions *v2; // esi
  KeyValues *FirstSubKey; // ebx
  const char *Name; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ActionConditionPair_t *m_pMemory; // ecx
  int v8; // eax
  ActionConditionPair_t *v9; // ecx
  ITilegenAction **p_m_pAction; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  ITilegenExpression<bool> *LiteralBoolValue; // eax
  const char *String; // eax
  ITilegenExpression<bool> *Instance; // esi
  ITilegenAction *v17; // [esp+Ch] [ebp-14h]
  ITilegenExpression<bool> *v18; // [esp+10h] [ebp-10h]
  ITilegenExpression<bool> *pCondition; // [esp+14h] [ebp-Ch] BYREF
  ITilegenAction *pAction; // [esp+18h] [ebp-8h] BYREF
  CTilegenAction_NestedActions *v21; // [esp+1Ch] [ebp-4h]

  v2 = this;
  v21 = this;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
  if ( FirstSubKey == nullptr )
  {
LABEL_11:
    v2->GetTypeName(this: v2);
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "while", bCreate: false);
    v12 = Key;
    v2->m_pWhileCondition = nullptr;
    if ( Key == nullptr )
      return 1;
    if ( KeyValues::GetFirstSubKey(this: Key) != nullptr )
    {
      String = KeyValues::GetString(this: v12, keyName: "class", defaultValue: nullptr);
      if ( String != nullptr )
      {
        Instance = CTilegenClassRegistry<ITilegenExpression<bool>>::CreateInstance(pClassName: String);
        if ( Instance != nullptr && !Instance->LoadFromKeyValues(this: Instance, a2: v12) )
        {
          ((void (__thiscall *)(ITilegenExpression<bool> *, int))Instance->dtr_ITilegenExpression<bool>)(
            a1: Instance,
            a2: 1);
          Instance = nullptr;
        }
        LiteralBoolValue = Instance;
        v2 = v21;
      }
      else
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
          _LoggingSystem_Log(
            a1: LOG_TilegenLayoutSystem,
            a2: 1,
            a3: "No class name specified for class instantiation in key values.\n");
        LiteralBoolValue = nullptr;
      }
    }
    else
    {
      LiteralBoolValue = ReadLiteralBoolValue(pKeyValues: v12);
    }
    v2->m_pWhileCondition = LiteralBoolValue;
    if ( LiteralBoolValue != nullptr )
      return 1;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
    return 0;
  }
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "action") == 0 )
      break;
LABEL_10:
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      goto LABEL_11;
  }
  if ( CreateActionAndCondition(pKeyValues: FirstSubKey, ppAction: &pAction, ppCondition: &pCondition) )
  {
    m_Size = v2->m_NestedActions.m_Size;
    v18 = pCondition;
    m_nAllocationCount = v2->m_NestedActions.m_Memory.m_nAllocationCount;
    v17 = pAction;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<EnumEntry_t,int>::Grow(
        this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&v2->m_NestedActions,
        num: m_Size - m_nAllocationCount + 1);
    ++v2->m_NestedActions.m_Size;
    m_pMemory = v2->m_NestedActions.m_Memory.m_pMemory;
    v8 = v2->m_NestedActions.m_Size - m_Size - 1;
    v2->m_NestedActions.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v8);
    v9 = v2->m_NestedActions.m_Memory.m_pMemory;
    v2 = v21;
    p_m_pAction = &v9[m_Size].m_pAction;
    if ( p_m_pAction != nullptr )
    {
      *p_m_pAction = v17;
      p_m_pAction[1] = (ITilegenAction *)v18;
    }
    goto LABEL_10;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "Error creating nested action/condition pair in CTilegenAction_NestedActions.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013AE0
// Name: public: virtual bool CTilegenAction_FilterCandidatesForLinearGrowth::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenAction_FilterCandidatesForLinearGrowth::LoadFromKeyValues(
        CTilegenAction_FilterCandidatesForLinearGrowth *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  return CreateFromKeyValuesBlock<ITilegenExpression<int>>(
           pParentKV: pKeyValues,
           pKeyName: "threshold",
           pParentClassName: v3,
           ppClass: &this->m_pThresholdExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x10013B10
// Name: public: virtual CTilegenAction_PlaceComponent::~CTilegenAction_PlaceComponent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_PlaceComponent::~CTilegenAction_PlaceComponent(CTilegenAction_PlaceComponent *this)
{
  ITilegenExpression<bool> *m_pExitFilter; // ecx
  ITilegenExpression<bool> *m_pRoomCandidateFilter; // ecx
  ITilegenAction *m_pRoomCandidateFilterAction; // ecx
  ITilegenExpression<bool> *m_pRoomCandidateFilterCondition; // ecx
  CTilegenAction_AddConnectorRoomCandidates *m_pAddConnectorRoomCandidates; // ecx
  CTilegenAction_ChooseCandidate *m_pChooseCandidate; // ecx

  m_pExitFilter = this->m_pExitFilter;
  this->__vftable = (CTilegenAction_PlaceComponent_vtbl *)&CTilegenAction_PlaceComponent::`vftable';
  if ( m_pExitFilter != nullptr )
    ((void (__thiscall *)(ITilegenExpression<bool> *, int))m_pExitFilter->dtr_ITilegenExpression<bool>)(
      a1: m_pExitFilter,
      a2: 1);
  m_pRoomCandidateFilter = this->m_pRoomCandidateFilter;
  if ( m_pRoomCandidateFilter != nullptr )
    ((void (__thiscall *)(ITilegenExpression<bool> *, int))m_pRoomCandidateFilter->dtr_ITilegenExpression<bool>)(
      a1: m_pRoomCandidateFilter,
      a2: 1);
  m_pRoomCandidateFilterAction = this->m_pRoomCandidateFilterAction;
  if ( m_pRoomCandidateFilterAction != nullptr )
    ((void (__thiscall *)(ITilegenAction *, int))m_pRoomCandidateFilterAction->dtr_ITilegenAction)(
      a1: m_pRoomCandidateFilterAction,
      a2: 1);
  m_pRoomCandidateFilterCondition = this->m_pRoomCandidateFilterCondition;
  if ( m_pRoomCandidateFilterCondition != nullptr )
    ((void (__thiscall *)(ITilegenExpression<bool> *, int))m_pRoomCandidateFilterCondition->dtr_ITilegenExpression<bool>)(
      a1: m_pRoomCandidateFilterCondition,
      a2: 1);
  m_pAddConnectorRoomCandidates = this->m_pAddConnectorRoomCandidates;
  if ( m_pAddConnectorRoomCandidates != nullptr )
    ((void (__thiscall *)(CTilegenAction_AddConnectorRoomCandidates *, int))m_pAddConnectorRoomCandidates->dtr_ITilegenAction)(
      a1: m_pAddConnectorRoomCandidates,
      a2: 1);
  m_pChooseCandidate = this->m_pChooseCandidate;
  if ( m_pChooseCandidate != nullptr )
    ((void (__thiscall *)(CTilegenAction_ChooseCandidate *, int))m_pChooseCandidate->dtr_ITilegenAction)(
      a1: m_pChooseCandidate,
      a2: 1);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RoomsToPlace);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_OptionalRooms);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_MandatoryRooms);
  this->__vftable = (CTilegenAction_PlaceComponent_vtbl *)&ITilegenAction::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10013BA0
// Name: private: bool CTilegenAction_PlaceComponent::LoadRoomPlacementsFromKeyValues(class KeyValues __near *,class CUtlVector<struct CTilegenAction_PlaceComponent::RoomPlacementInfo_t,class CUtlMemory<struct CTilegenAction_PlaceComponent::RoomPlacementInfo_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenAction_PlaceComponent::LoadRoomPlacementsFromKeyValues(
        CTilegenAction_PlaceComponent *this,
        KeyValues *pKeyValues,
        CUtlMemory<vgui::PropertySheet::Page_t,int> *pRooms)
{
  KeyValues *FirstSubKey; // ebx
  const char *Name; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CTilegenAction_PlaceComponent::RoomPlacementInfo_t *v8; // ecx
  int v9; // eax
  CTilegenAction_PlaceComponent::RoomPlacementInfo_t *v10; // edi
  CLevelTheme *Theme; // eax
  CRoomTemplate *Room; // eax
  char szRoomOut[4]; // [esp+10h] [ebp-80h] BYREF
  char roomName[64]; // [esp+14h] [ebp-7Ch] BYREF
  const char *String; // [esp+98h] [ebp+8h]
  float pFullRoomName; // [esp+9Ch] [ebp+Ch]

  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "room") == 0 )
    {
      String = KeyValues::GetString(this: FirstSubKey, keyName: "room_name", defaultValue: nullptr);
      if ( String == nullptr )
        return 0;
      pFullRoomName = KeyValues::GetFloat(this: FirstSubKey, keyName: "fraction", defaultValue: -1.0);
      m_pMemory = (int)pRooms[1].m_pMemory;
      m_nAllocationCount = pRooms->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<EnumEntry_t,int>::Grow(this: pRooms, num: m_pMemory - m_nAllocationCount + 1);
      ++pRooms[1].m_pMemory;
      v8 = (CTilegenAction_PlaceComponent::RoomPlacementInfo_t *)pRooms->m_pMemory;
      v9 = (int)pRooms[1].m_pMemory - m_pMemory - 1;
      pRooms[1].m_nAllocationCount = (int)pRooms->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 8 * v9);
      v10 = (CTilegenAction_PlaceComponent::RoomPlacementInfo_t *)&pRooms->m_pMemory[(int)pRooms[1].m_pMemory - 1];
      v10->m_flPlacementFraction = pFullRoomName;
      if ( CLevelTheme::SplitThemeAndRoom(
             pszFullName: String,
             szThemeOut: &roomName[60],
             nThemeOutSize: 64,
             szRoomOut,
             nRoomOutSize: 64) == 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
          _LoggingSystem_Log(
            a1: LOG_TilegenLayoutSystem,
            a2: 1,
            a3: "Could not split theme name from room (full name: %s).\n");
        return 0;
      }
      Theme = CLevelTheme::FindTheme(szThemeName: &roomName[60]);
      if ( Theme == nullptr )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        {
          _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Theme %s not found.\n");
          return 0;
        }
        return 0;
      }
      Room = CLevelTheme::FindRoom(this: Theme, szRoomTemplate: szRoomOut);
      v10->m_pRoomTemplate = Room;
      if ( Room == nullptr )
        break;
    }
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return 1;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Room %s not found.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013D80
// Name: public: virtual bool CTilegenAction_AddInstances::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenAction_AddInstances::LoadFromKeyValues(
        CTilegenAction_AddInstances *this,
        KeyValues *pKeyValues)
{
  bool result; // al
  const char *v4; // eax
  bool v5; // bl
  KeyValues *Key; // eax
  ITilegenExpression<bool> *v7; // eax

  result = CInstanceSpawn::LoadFromKeyValues(this: &this->m_InstanceSpawn, pKeyValues);
  if ( result )
  {
    v4 = this->GetTypeName(this);
    v5 = CreateFromKeyValuesBlock<ITilegenExpression<int>>(
           pParentKV: pKeyValues,
           pKeyName: "instance_count",
           pParentClassName: v4,
           ppClass: &this->m_pInstanceCount,
           bOptional: false,
           bCreateEmptyInstance: false);
    this->GetTypeName(this);
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "room_template_filter", bCreate: false);
    this->m_pRoomTemplateFilter = nullptr;
    if ( Key == nullptr )
      return v5;
    v7 = CreateFromKeyValues_ITilegenExpression_bool___(pKeyValues: Key, bCreateEmptyInstance: false);
    this->m_pRoomTemplateFilter = v7;
    if ( v7 != nullptr )
    {
      return v5;
    }
    else
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013E50
// Name: BuildRoomTemplateList
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildRoomTemplateList(
        CUtlMemory<vgui::TreeNode *,int> *pRoomTemplateList@<esi>,
        CLayoutSystem *pLayoutSystem,
        CLevelTheme *pTheme,
        ITilegenExpression<bool> *pRoomTemplateFilter,
        bool bExcludeGlobalFilters)
{
  CFreeVariableMap *p_m_FreeVariables; // ebx
  ITilegenExpression<bool> *FreeVariableOrNULL; // eax
  int m_nAllocationCount; // eax
  CRoomTemplate **v8; // ebx
  int m_pMemory; // edi
  const CRoomTemplate **v10; // ecx
  int v11; // eax
  const CRoomTemplate **v12; // edi
  int i; // [esp+4h] [ebp-8h]
  ITilegenExpression<bool> *pGlobalRoomTemplateFilter; // [esp+8h] [ebp-4h]

  i = 0;
  if ( pTheme->m_RoomTemplates.m_Size > 0 )
  {
    p_m_FreeVariables = &pLayoutSystem->m_FreeVariables;
    while ( 1 )
    {
      CFreeVariableMap::SetOrCreateFreeVariable(
        this: p_m_FreeVariables,
        pName: "RoomTemplate",
        pValue: pTheme->m_RoomTemplates.m_Memory.m_pMemory[i]);
      if ( bExcludeGlobalFilters )
      {
        FreeVariableOrNULL = nullptr;
        pGlobalRoomTemplateFilter = nullptr;
      }
      else
      {
        FreeVariableOrNULL = (ITilegenExpression<bool> *)CFreeVariableMap::GetFreeVariableOrNULL(
                                                           this: p_m_FreeVariables,
                                                           pName: "GlobalRoomTemplateFilters");
        pGlobalRoomTemplateFilter = FreeVariableOrNULL;
      }
      if ( pRoomTemplateFilter == nullptr )
        goto LABEL_9;
      if ( pRoomTemplateFilter->Evaluate(this: pRoomTemplateFilter, a2: p_m_FreeVariables) )
        break;
LABEL_18:
      CFreeVariableMap::SetOrCreateFreeVariable(this: p_m_FreeVariables, pName: "RoomTemplate", pValue: nullptr);
      if ( ++i >= pTheme->m_RoomTemplates.m_Size )
        return;
    }
    FreeVariableOrNULL = pGlobalRoomTemplateFilter;
LABEL_9:
    if ( FreeVariableOrNULL == nullptr || FreeVariableOrNULL->Evaluate(this: FreeVariableOrNULL, a2: p_m_FreeVariables) )
    {
      m_nAllocationCount = pRoomTemplateList->m_nAllocationCount;
      v8 = &pTheme->m_RoomTemplates.m_Memory.m_pMemory[i];
      m_pMemory = (int)pRoomTemplateList[1].m_pMemory;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
          this: pRoomTemplateList,
          num: m_pMemory - m_nAllocationCount + 1);
      ++pRoomTemplateList[1].m_pMemory;
      v10 = (const CRoomTemplate **)pRoomTemplateList->m_pMemory;
      v11 = (int)pRoomTemplateList[1].m_pMemory - m_pMemory - 1;
      pRoomTemplateList[1].m_nAllocationCount = (int)pRoomTemplateList->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
      v12 = (const CRoomTemplate **)&pRoomTemplateList->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
        *v12 = *v8;
      p_m_FreeVariables = &pLayoutSystem->m_FreeVariables;
    }
    goto LABEL_18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013FA0
// Name: public: virtual bool CTilegenAction_AddRoomCandidates::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenAction_AddRoomCandidates::LoadFromKeyValues(
        CTilegenAction_AddRoomCandidates *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax
  bool v4; // bl
  KeyValues *Key; // eax
  ITilegenExpression<bool> *v6; // eax
  char v7; // al
  char v8; // bl
  KeyValues *v9; // eax
  ITilegenExpression<bool> *v10; // eax
  char v11; // al
  char v12; // bl
  KeyValues *v13; // eax
  ITilegenExpression<bool> *v14; // eax
  char v15; // al
  char v16; // bl
  const char *v17; // eax

  v3 = this->GetTypeName(this);
  v4 = CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
         pParentKV: pKeyValues,
         pKeyName: "theme",
         pParentClassName: v3,
         ppClass: &this->m_pThemeNameExpression,
         bOptional: false,
         bCreateEmptyInstance: false);
  this->GetTypeName(this);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: "exit_filter", bCreate: false);
  this->m_pExitFilter = nullptr;
  if ( Key == nullptr
    || (v6 = CreateFromKeyValues_ITilegenExpression_bool___(pKeyValues: Key, bCreateEmptyInstance: false),
        this->m_pExitFilter = v6,
        v6 != nullptr) )
  {
    v7 = 1;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
    v7 = 0;
  }
  v8 = v7 & v4;
  this->GetTypeName(this);
  v9 = KeyValues::FindKey(this: pKeyValues, keyName: "room_template_filter", bCreate: false);
  this->m_pRoomTemplateFilter = nullptr;
  if ( v9 == nullptr
    || (v10 = CreateFromKeyValues_ITilegenExpression_bool___(pKeyValues: v9, bCreateEmptyInstance: false),
        this->m_pRoomTemplateFilter = v10,
        v10 != nullptr) )
  {
    v11 = 1;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
    v11 = 0;
  }
  v12 = v11 & v8;
  this->GetTypeName(this);
  v13 = KeyValues::FindKey(this: pKeyValues, keyName: "room_candidate_filter", bCreate: false);
  this->m_pRoomCandidateFilter = nullptr;
  if ( v13 == nullptr
    || (v14 = CreateFromKeyValues_ITilegenExpression_bool___(pKeyValues: v13, bCreateEmptyInstance: false),
        this->m_pRoomCandidateFilter = v14,
        v14 != nullptr) )
  {
    v15 = 1;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
    v15 = 0;
  }
  v16 = v15 & v12;
  if ( KeyValues::FindKey(this: pKeyValues, keyName: "room_candidate_filter_action", bCreate: false) != nullptr )
  {
    v17 = this->GetTypeName(this);
    v16 &= CreateActionAndConditionFromKeyValuesBlock(
             pParentKV: pKeyValues,
             pKeyName: "room_candidate_filter_action",
             pParentClassName: v17,
             ppAction: &this->m_pRoomCandidateFilterAction,
             ppCondition: &this->m_pRoomCandidateFilterCondition);
  }
  this->m_bExcludeGlobalFilters = KeyValues::GetInt(
                                    this: pKeyValues,
                                    keyName: "exclude_global_filters",
                                    defaultValue: 0) != 0;
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x10014190
// Name: public: virtual bool CTilegenAction_AddRoomCandidatesAtLocation::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenAction_AddRoomCandidatesAtLocation::LoadFromKeyValues(
        CTilegenAction_AddRoomCandidatesAtLocation *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax
  bool v4; // bl
  const char *v5; // eax
  bool v6; // bl
  const char *v7; // eax
  bool v8; // bl
  KeyValues *Key; // eax
  ITilegenExpression<bool> *v10; // eax

  v3 = this->GetTypeName(this);
  v4 = CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
         pParentKV: pKeyValues,
         pKeyName: "theme",
         pParentClassName: v3,
         ppClass: &this->m_pThemeNameExpression,
         bOptional: false,
         bCreateEmptyInstance: false);
  v5 = this->GetTypeName(this);
  v6 = CreateFromKeyValuesBlock<ITilegenExpression<int>>(
         pParentKV: pKeyValues,
         pKeyName: "x",
         pParentClassName: v5,
         ppClass: &this->m_pXExpression,
         bOptional: false,
         bCreateEmptyInstance: false)
    && v4;
  v7 = this->GetTypeName(this);
  v8 = CreateFromKeyValuesBlock<ITilegenExpression<int>>(
         pParentKV: pKeyValues,
         pKeyName: "y",
         pParentClassName: v7,
         ppClass: &this->m_pYExpression,
         bOptional: false,
         bCreateEmptyInstance: false)
    && v6;
  this->GetTypeName(this);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: "room_template_filter", bCreate: false);
  this->m_pRoomTemplateFilter = nullptr;
  if ( Key == nullptr )
    return v8;
  v10 = CreateFromKeyValues_ITilegenExpression_bool___(pKeyValues: Key, bCreateEmptyInstance: false);
  this->m_pRoomTemplateFilter = v10;
  if ( v10 != nullptr )
    return v8;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10014290
// Name: public: virtual bool CTilegenAction_FilterCandidatesByDirection::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenAction_FilterCandidatesByDirection::LoadFromKeyValues(
        CTilegenAction_FilterCandidatesByDirection *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax
  bool v4; // bl
  const char *v5; // eax

  v3 = this->GetTypeName(this);
  v4 = CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
         pParentKV: pKeyValues,
         pKeyName: "direction",
         pParentClassName: v3,
         ppClass: &this->m_pDirectionExpression,
         bOptional: false,
         bCreateEmptyInstance: false);
  v5 = this->GetTypeName(this);
  return v4
       & CreateFromKeyValuesBlock<ITilegenExpression<int>>(
           pParentKV: pKeyValues,
           pKeyName: "threshold",
           pParentClassName: v5,
           ppClass: &this->m_pThresholdExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x100142F0
// Name: public: virtual bool CTilegenAction_SwitchState::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenAction_SwitchState::LoadFromKeyValues(CTilegenAction_SwitchState *this, KeyValues *pKeyValues)
{
  KeyValues *Key; // eax
  ITilegenExpression<char const *> *v4; // eax

  Key = KeyValues::FindKey(this: pKeyValues, keyName: "new_state", bCreate: false);
  this->m_pNewStateExpression = nullptr;
  if ( Key != nullptr )
  {
    v4 = CreateFromKeyValues_ITilegenExpression_char_const_____(pKeyValues: Key, bCreateEmptyInstance: false);
    this->m_pNewStateExpression = v4;
    if ( v4 == nullptr && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014370
// Name: public: virtual bool CTilegenAction_EnsureRoomExists::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenAction_EnsureRoomExists::LoadFromKeyValues(
        CTilegenAction_EnsureRoomExists *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  return CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
           pParentKV: pKeyValues,
           pKeyName: "roomname",
           pParentClassName: v3,
           ppClass: &this->m_pRoomNameExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x100143A0
// Name: public: virtual bool CTilegenAction_AddConnectorRoomCandidates::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenAction_AddConnectorRoomCandidates::LoadFromKeyValues(
        CTilegenAction_AddConnectorRoomCandidates *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax
  bool v4; // bl
  const char *v5; // eax
  bool v6; // bl
  KeyValues *Key; // edi
  const char *v9; // eax
  bool v10; // bl
  ITilegenExpression<bool> *pCondition; // [esp+Ch] [ebp-4h] BYREF

  v3 = this->GetTypeName(this);
  v4 = CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
         pParentKV: pKeyValues,
         pKeyName: "theme",
         pParentClassName: v3,
         ppClass: &this->m_pTargetThemeNameExpression,
         bOptional: false,
         bCreateEmptyInstance: false);
  v5 = this->GetTypeName(this);
  v6 = CreateFromKeyValuesBlock<ITilegenExpression<bool>>(
         pParentKV: pKeyValues,
         pKeyName: "room_template_filter",
         pParentClassName: v5,
         ppClass: &this->m_pTargetRoomTemplateFilter,
         bOptional: false,
         bCreateEmptyInstance: false)
    && v4;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: "connector_room_candidates", bCreate: false);
  if ( Key == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Key 'connector_room_candidates' not found when parsing 'CTilegenAction_AddConnectorRoomCandidates'.\n");
    return false;
  }
  v9 = this->GetTypeName(this);
  v10 = CreateActionAndConditionFromKeyValuesBlock(
          pParentKV: Key,
          pKeyName: "action",
          pParentClassName: v9,
          ppAction: &this->m_pAddConnectorCandidates,
          ppCondition: &pCondition)
     && v6;
  if ( pCondition == nullptr )
    return v10;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return false;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Action specified in 'connector_room_candidates' block of 'CTilegenAction_AddConnectorRoomCandidates' must not have a"
    " nested condition.\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100144B0
// Name: public: virtual void CTilegenAction_AddConnectorRoomCandidates::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_AddConnectorRoomCandidates::Execute(
        CTilegenAction_AddConnectorRoomCandidates *this,
        CLayoutSystem *pLayoutSystem)
{
  const CRoomTemplate **m_pMemory; // esi
  const char *v4; // esi
  CLevelTheme *Theme; // eax
  int m_Size; // ebx
  int v7; // ecx
  const CRoomTemplate *v8; // eax
  CRoomTemplateExit *v9; // edx
  const char *m_szExitTag; // esi
  int v11; // esi
  CExit *v12; // edi
  CExit *v13; // edi
  CUtlVector<CRoomCandidate,CUtlMemory<CRoomCandidate,int> > *m_pRoomCandidateList; // edi
  CExit *v15; // eax
  int v16; // esi
  int v17; // eax
  const CExit *v18; // eax
  int v19; // esi
  char *v20; // edi
  int v21; // eax
  CRoomCandidate *v22; // ecx
  int v23; // edx
  int v24; // eax
  __int64 v25; // xmm0_8
  int v26; // eax
  char v27[84]; // [esp+Ch] [ebp-A8h] BYREF
  const CExit *pNewOpenExit; // [esp+60h] [ebp-54h]
  CUtlVector<CExit,CUtlMemory<CExit,int> > desiredMatchingExits; // [esp+64h] [ebp-50h] BYREF
  int v30; // [esp+78h] [ebp-3Ch]
  CUtlVector<CRoomTemplate const *,CUtlMemory<CRoomTemplate const *,int> > roomTemplateList; // [esp+7Ch] [ebp-38h] BYREF
  CUtlVector<CExit,CUtlMemory<CExit,int> > newOpenExits; // [esp+90h] [ebp-24h] BYREF
  CUtlVector<CRoomCandidate,CUtlMemory<CRoomCandidate,int> > *pRoomCandidateList; // [esp+A4h] [ebp-10h]
  const CRoomTemplate *pTemplate; // [esp+A8h] [ebp-Ch]
  int i; // [esp+ACh] [ebp-8h]
  int j; // [esp+B0h] [ebp-4h]

  pRoomCandidateList = (CUtlVector<CRoomCandidate,CUtlMemory<CRoomCandidate,int> > *)this;
  memset(&roomTemplateList, 0, sizeof(roomTemplateList));
  if ( this->m_pTargetRoomTemplate != nullptr )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&roomTemplateList,
      num: 1);
    m_pMemory = roomTemplateList.m_Memory.m_pMemory;
    if ( roomTemplateList.m_Size++ > 0 )
      _V_memmove(
        dest: roomTemplateList.m_Memory.m_pMemory + 1,
        src: roomTemplateList.m_Memory.m_pMemory,
        count: 4 * (roomTemplateList.m_Size - 1));
    if ( m_pMemory != nullptr )
      *m_pMemory = this->m_pTargetRoomTemplate;
  }
  else
  {
    if ( this->m_pLevelTheme == nullptr )
    {
      v4 = this->m_pTargetThemeNameExpression->Evaluate(
             this: this->m_pTargetThemeNameExpression,
             a2: &pLayoutSystem->m_FreeVariables);
      Theme = CLevelTheme::FindTheme(szThemeName: v4);
      this->m_pLevelTheme = Theme;
      if ( Theme == nullptr )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Theme %s not found.\n");
        CLayoutSystem::OnError(this: pLayoutSystem);
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&roomTemplateList);
        return;
      }
    }
    BuildRoomTemplateList(
      pRoomTemplateList: (CUtlMemory<vgui::TreeNode *,int> *)&roomTemplateList,
      pLayoutSystem,
      pTheme: this->m_pLevelTheme,
      pRoomTemplateFilter: this->m_pTargetRoomTemplateFilter,
      bExcludeGlobalFilters: true);
    m_pMemory = roomTemplateList.m_Memory.m_pMemory;
  }
  m_Size = 0;
  v7 = 0;
  memset(&desiredMatchingExits, 0, sizeof(desiredMatchingExits));
  i = 0;
  if ( roomTemplateList.m_Size > 0 )
  {
    do
    {
      v8 = m_pMemory[v7];
      pTemplate = v8;
      j = 0;
      if ( v8->m_Exits.m_Size > 0 )
      {
        while ( 1 )
        {
          v9 = v8->m_Exits.m_Memory.m_pMemory[j];
          m_szExitTag = v9->m_szExitTag;
          *(_QWORD *)v27 = 0;
          *(_QWORD *)&v27[8] = (unsigned int)CRoomTemplateExit::GetOppositeDirection(Direction: v9->m_ExitDirection);
          v27[80] = 0;
          if ( m_szExitTag != nullptr )
            V_strncpy(pDest: &v27[16], pSrc: m_szExitTag, maxLen: 64);
          else
            v27[16] = 0;
          v11 = m_Size;
          if ( m_Size + 1 > desiredMatchingExits.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CExit,int>::Grow(
              this: (CUtlMemory<PanelItem_t,int> *)&desiredMatchingExits,
              num: m_Size - desiredMatchingExits.m_Memory.m_nAllocationCount + 1);
            m_Size = desiredMatchingExits.m_Size;
          }
          v12 = desiredMatchingExits.m_Memory.m_pMemory;
          desiredMatchingExits.m_Size = ++m_Size;
          desiredMatchingExits.m_pElements = desiredMatchingExits.m_Memory.m_pMemory;
          if ( m_Size - v11 - 1 > 0 )
            _V_memmove(
              dest: &desiredMatchingExits.m_Memory.m_pMemory[v11 + 1],
              src: &desiredMatchingExits.m_Memory.m_pMemory[v11],
              count: 84 * (m_Size - v11 - 1));
          v13 = &v12[v11];
          if ( v13 != nullptr )
            qmemcpy(v13, v27, sizeof(CExit));
          if ( ++j >= pTemplate->m_Exits.m_Size )
            break;
          v8 = pTemplate;
        }
        v7 = i;
        m_pMemory = roomTemplateList.m_Memory.m_pMemory;
      }
      i = ++v7;
    }
    while ( v7 < roomTemplateList.m_Size );
  }
  CLayoutSystem::ExecuteAction(
    this: pLayoutSystem,
    pAction: (ITilegenAction *)pRoomCandidateList[1].m_Memory.m_pMemory,
    pCondition: nullptr);
  m_pRoomCandidateList = pLayoutSystem->m_CurrentIterationState.m_pRoomCandidateList;
  v15 = nullptr;
  memset(&newOpenExits, 0, sizeof(newOpenExits));
  v16 = m_pRoomCandidateList->m_Size - 1;
  pRoomCandidateList = m_pRoomCandidateList;
  pTemplate = (const CRoomTemplate *)v16;
  if ( v16 >= 0 )
  {
    v17 = 20 * v16;
    for ( j = 20 * v16; ; v17 = j )
    {
      newOpenExits.m_Size = 0;
      BuildOpenExitList(
        roomCandidate: (const CRoomCandidate *)((char *)m_pRoomCandidateList->m_Memory.m_pMemory + v17),
        pMapLayout: pLayoutSystem->m_pMapLayout,
        pNewExitList: &newOpenExits);
      v30 = 0;
      if ( newOpenExits.m_Size > 0 )
      {
        i = 0;
        do
        {
          v18 = (CExit *)((char *)newOpenExits.m_Memory.m_pMemory + i);
          v19 = 0;
          pNewOpenExit = (CExit *)((char *)newOpenExits.m_Memory.m_pMemory + i);
          if ( m_Size > 0 )
          {
            v20 = desiredMatchingExits.m_Memory.m_pMemory->m_szExitTag;
            while ( 1 )
            {
              if ( v18->ExitDirection == *((_DWORD *)v20 - 2) )
              {
                if ( _V_stricmp(s1: v18->m_szExitTag, s2: v20) == 0 )
                {
                  m_pRoomCandidateList = pRoomCandidateList;
                  v16 = (int)pTemplate;
                  goto LABEL_47;
                }
                v18 = pNewOpenExit;
              }
              ++v19;
              v20 += 84;
              if ( v19 >= m_Size )
              {
                m_pRoomCandidateList = pRoomCandidateList;
                break;
              }
            }
          }
          i += 84;
          ++v30;
        }
        while ( v30 < newOpenExits.m_Size );
        v16 = (int)pTemplate;
      }
      v21 = m_pRoomCandidateList->m_Size;
      if ( v21 > 0 )
      {
        if ( v16 != v21 - 1 )
        {
          v22 = m_pRoomCandidateList->m_Memory.m_pMemory;
          v23 = j;
          v24 = v21;
          v25 = *(_QWORD *)&m_pRoomCandidateList->m_Memory.m_pMemory[v24 - 1].m_pRoomTemplate;
          v26 = (int)&m_pRoomCandidateList->m_Memory.m_pMemory[v24 - 1];
          *(_QWORD *)((char *)&v22->m_pRoomTemplate + j) = v25;
          *(_QWORD *)((char *)&v22->m_iYPos + v23) = *(_QWORD *)(v26 + 8);
          *(float *)((char *)&v22->m_flCandidateChance + v23) = *(float *)(v26 + 16);
        }
        --m_pRoomCandidateList->m_Size;
      }
LABEL_47:
      j -= 20;
      pTemplate = (const CRoomTemplate *)--v16;
      if ( v16 < 0 )
        break;
    }
    v15 = newOpenExits.m_Memory.m_pMemory;
  }
  newOpenExits.m_Size = 0;
  if ( newOpenExits.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v15 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      v15 = nullptr;
      newOpenExits.m_Memory.m_pMemory = nullptr;
    }
    newOpenExits.m_Memory.m_nAllocationCount = 0;
  }
  newOpenExits.m_pElements = v15;
  if ( newOpenExits.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v15 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      newOpenExits.m_Memory.m_pMemory = nullptr;
    }
    newOpenExits.m_Memory.m_nAllocationCount = 0;
  }
  if ( desiredMatchingExits.m_Memory.m_nGrowSize >= 0 && desiredMatchingExits.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: desiredMatchingExits.m_Memory.m_pMemory);
  if ( roomTemplateList.m_Memory.m_nGrowSize >= 0 && roomTemplateList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: roomTemplateList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10014870
// Name: public: CTilegenAction_PlaceComponent::CTilegenAction_PlaceComponent(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_PlaceComponent *__thiscall CTilegenAction_PlaceComponent::CTilegenAction_PlaceComponent(
        CTilegenAction_PlaceComponent *this)
{
  this->__vftable = (CTilegenAction_PlaceComponent_vtbl *)&CTilegenAction_PlaceComponent::`vftable';
  this->m_nMinOptionalRooms = 0;
  this->m_nMaxOptionalRooms = 0;
  this->m_pExitFilter = nullptr;
  this->m_pRoomCandidateFilter = nullptr;
  this->m_pRoomCandidateFilterAction = nullptr;
  this->m_pRoomCandidateFilterCondition = nullptr;
  this->m_pAddConnectorRoomCandidates = nullptr;
  this->m_pChooseCandidate = nullptr;
  this->m_bExcludeGlobalFilters = false;
  this->m_MandatoryRooms.m_Memory.m_pMemory = nullptr;
  this->m_MandatoryRooms.m_Memory.m_nAllocationCount = 0;
  this->m_MandatoryRooms.m_Memory.m_nGrowSize = 0;
  this->m_MandatoryRooms.m_Size = 0;
  this->m_MandatoryRooms.m_pElements = nullptr;
  this->m_OptionalRooms.m_Memory.m_pMemory = nullptr;
  this->m_OptionalRooms.m_Memory.m_nAllocationCount = 0;
  this->m_OptionalRooms.m_Memory.m_nGrowSize = 0;
  this->m_OptionalRooms.m_Size = 0;
  this->m_OptionalRooms.m_pElements = nullptr;
  this->m_RoomsToPlace.m_Memory.m_pMemory = nullptr;
  this->m_RoomsToPlace.m_Memory.m_nAllocationCount = 0;
  this->m_RoomsToPlace.m_Memory.m_nGrowSize = 0;
  this->m_RoomsToPlace.m_Size = 0;
  this->m_RoomsToPlace.m_pElements = nullptr;
  this->m_RoomsToPlace.m_pLessContext = nullptr;
  this->m_RoomsToPlace.m_bNeedsSort = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10014900
// Name: public: virtual void CTilegenAction_PlaceComponent::OnBeginGeneration(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CTilegenAction_PlaceComponent::OnBeginGeneration(
        CTilegenAction_PlaceComponent *this,
        CLayoutSystem *pLayoutSystem)
{
  int m_Size; // eax
  int v5; // edi
  CTilegenAction_PlaceComponent::RoomPlacementInfo_t *m_pMemory; // edx
  float m_flPlacementFraction; // xmm0_4
  int v8; // edi
  int v9; // eax
  CTilegenAction_PlaceComponent::RoomPlacementInfo_t *v10; // ecx
  float v11; // xmm0_4
  _BYTE dest[24]; // [esp+14h] [ebp-8Ch] BYREF
  _BYTE isRoomChosen_104[9]; // [esp+94h] [ebp-Ch] OVERLAPPED BYREF
  int isRoomChosen_124; // [esp+A8h] [ebp+8h]

  m_Size = pLayoutSystem->m_Random.RandomInt(
             this: (struct CUniformRandomStream *)pLayoutSystem,
             a2: this->m_nMinOptionalRooms,
             a3: this->m_nMaxOptionalRooms);
  if ( m_Size >= this->m_OptionalRooms.m_Size )
    m_Size = this->m_OptionalRooms.m_Size;
  v5 = 0;
  this->m_RoomsToPlace.m_Size = 0;
  for ( isRoomChosen_124 = m_Size <= 0 ? 0 : m_Size; v5 < this->m_MandatoryRooms.m_Size; ++v5 )
  {
    m_pMemory = this->m_MandatoryRooms.m_Memory.m_pMemory;
    m_flPlacementFraction = m_pMemory[v5].m_flPlacementFraction;
    *(_DWORD *)isRoomChosen_104 = &m_pMemory[v5];
    isRoomChosen_104[8] = 0;
    if ( m_flPlacementFraction >= 0.0 )
    {
      if ( m_flPlacementFraction > 1.0 )
        goto LABEL_10;
      if ( m_flPlacementFraction >= 0.0 )
      {
        if ( m_flPlacementFraction <= 1.0 )
        {
          *(float *)&isRoomChosen_104[4] = m_flPlacementFraction;
          goto LABEL_12;
        }
LABEL_10:
        *(_DWORD *)&isRoomChosen_104[4] = 1065353216;
        goto LABEL_12;
      }
      *(_DWORD *)&isRoomChosen_104[4] = 0;
    }
    else
    {
      *(float *)&isRoomChosen_104[4] = ((double (__thiscall *)(CLayoutSystem *, int, int))pLayoutSystem->m_Random.RandomFloat)(
                                         a1: pLayoutSystem,
                                         a2: 1028443341,
                                         a3: 1064514355);
    }
LABEL_12:
    CUtlSortVector<CTilegenAction_PlaceComponent::RoomPlacementInstance_t,CTilegenAction_PlaceComponent::CRoomPlacementInstanceLessFunc>::Insert(
      this: &this->m_RoomsToPlace,
      src: (const CTilegenAction_PlaceComponent::RoomPlacementInstance_t *)isRoomChosen_104);
  }
  _V_memset(dest, fill: 0, count: 128);
  v8 = 0;
  if ( isRoomChosen_124 > 0 )
  {
    while ( 1 )
    {
      v9 = pLayoutSystem->m_Random.RandomInt(
             this: (struct CUniformRandomStream *)pLayoutSystem,
             a2: 0,
             a3: isRoomChosen_124 - 1);
      if ( dest[v9] == 0 )
        break;
LABEL_24:
      if ( v8 >= isRoomChosen_124 )
        return;
    }
    v10 = this->m_OptionalRooms.m_Memory.m_pMemory;
    dest[v9] = 1;
    v11 = v10[v9].m_flPlacementFraction;
    *(_DWORD *)isRoomChosen_104 = &v10[v9];
    isRoomChosen_104[8] = 0;
    if ( v11 < 0.0 )
    {
      *(float *)&isRoomChosen_104[4] = ((double (__thiscall *)(CLayoutSystem *, int, int))pLayoutSystem->m_Random.RandomFloat)(
                                         a1: pLayoutSystem,
                                         a2: 1028443341,
                                         a3: 1064514355);
LABEL_23:
      CUtlSortVector<CTilegenAction_PlaceComponent::RoomPlacementInstance_t,CTilegenAction_PlaceComponent::CRoomPlacementInstanceLessFunc>::Insert(
        this: &this->m_RoomsToPlace,
        src: (const CTilegenAction_PlaceComponent::RoomPlacementInstance_t *)isRoomChosen_104);
      ++v8;
      goto LABEL_24;
    }
    if ( v11 <= 1.0 )
    {
      if ( v11 < 0.0 )
      {
        *(_DWORD *)&isRoomChosen_104[4] = 0;
        goto LABEL_23;
      }
      if ( v11 <= 1.0 )
      {
        *(float *)&isRoomChosen_104[4] = v11;
        goto LABEL_23;
      }
    }
    *(_DWORD *)&isRoomChosen_104[4] = 1065353216;
    goto LABEL_23;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014AC0
// Name: public: virtual bool CTilegenAction_PlaceComponent::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenAction_PlaceComponent::LoadFromKeyValues(
        CTilegenAction_PlaceComponent *this,
        KeyValues *pKeyValues)
{
  KeyValues *Key; // eax
  KeyValues *v5; // eax
  int Int; // eax
  CTilegenAction_PlaceComponent_vtbl *v7; // edx
  KeyValues *v8; // eax
  ITilegenExpression<bool> *v9; // eax
  char v10; // al
  KeyValues *v11; // eax
  ITilegenExpression<bool> *v12; // eax
  char v13; // al
  const char *v14; // eax
  KeyValues *v15; // ebx
  const char *v16; // eax
  CTilegenAction_AddConnectorRoomCandidates *v18; // eax
  ITilegenAction *v19; // ecx
  CTilegenAction_ChooseCandidate *v20; // eax
  ITilegenAction *pAction; // [esp+Ch] [ebp-8h] BYREF
  ITilegenExpression<bool> *pCondition; // [esp+10h] [ebp-4h] BYREF
  char bSuccess_3; // [esp+1Fh] [ebp+Bh]
  char bSuccess_3a; // [esp+1Fh] [ebp+Bh]

  Key = KeyValues::FindKey(this: pKeyValues, keyName: "mandatory_rooms", bCreate: false);
  if ( Key != nullptr )
    CTilegenAction_PlaceComponent::LoadRoomPlacementsFromKeyValues(
      this,
      pKeyValues: Key,
      pRooms: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->m_MandatoryRooms);
  v5 = KeyValues::FindKey(this: pKeyValues, keyName: "optional_rooms", bCreate: false);
  if ( v5 != nullptr )
    CTilegenAction_PlaceComponent::LoadRoomPlacementsFromKeyValues(
      this,
      pKeyValues: v5,
      pRooms: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->m_OptionalRooms);
  if ( this->m_OptionalRooms.m_Size >= 128 )
    return 0;
  this->m_nMinOptionalRooms = KeyValues::GetInt(this: pKeyValues, keyName: "min", defaultValue: 0);
  this->m_nMaxOptionalRooms = KeyValues::GetInt(this: pKeyValues, keyName: "max", defaultValue: 0);
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "exclude_global_filters", defaultValue: 0);
  v7 = this->__vftable;
  this->m_bExcludeGlobalFilters = Int != 0;
  v7->GetTypeName(this);
  v8 = KeyValues::FindKey(this: pKeyValues, keyName: "exit_filter", bCreate: false);
  this->m_pExitFilter = nullptr;
  if ( v8 == nullptr
    || (v9 = CreateFromKeyValues_ITilegenExpression_bool___(pKeyValues: v8, bCreateEmptyInstance: false),
        this->m_pExitFilter = v9,
        v9 != nullptr) )
  {
    v10 = 1;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
    v10 = 0;
  }
  bSuccess_3 = v10;
  pCondition = (ITilegenExpression<bool> *)this->GetTypeName(this);
  v11 = KeyValues::FindKey(this: pKeyValues, keyName: "room_candidate_filter", bCreate: false);
  this->m_pRoomCandidateFilter = nullptr;
  if ( v11 == nullptr
    || (v12 = CreateFromKeyValues_ITilegenExpression_bool___(pKeyValues: v11, bCreateEmptyInstance: false),
        this->m_pRoomCandidateFilter = v12,
        v12 != nullptr) )
  {
    v13 = 1;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
    v13 = 0;
  }
  bSuccess_3a = v13 & bSuccess_3;
  if ( KeyValues::FindKey(this: pKeyValues, keyName: "room_candidate_filter_action", bCreate: false) != nullptr )
  {
    v14 = this->GetTypeName(this);
    bSuccess_3a &= CreateActionAndConditionFromKeyValuesBlock(
                     pParentKV: pKeyValues,
                     pKeyName: "room_candidate_filter_action",
                     pParentClassName: v14,
                     ppAction: &this->m_pRoomCandidateFilterAction,
                     ppCondition: &this->m_pRoomCandidateFilterCondition);
  }
  v15 = KeyValues::FindKey(this: pKeyValues, keyName: "connector_room_candidates", bCreate: false);
  if ( v15 != nullptr )
  {
    v16 = this->GetTypeName(this);
    bSuccess_3a &= CreateActionAndConditionFromKeyValuesBlock(
                     pParentKV: v15,
                     pKeyName: "action",
                     pParentClassName: v16,
                     ppAction: &pAction,
                     ppCondition: &pCondition);
    if ( pCondition != nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      {
        this->GetTypeName(this);
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Action specified in 'connector_room_candidates' block of %s must not have a nested condition.\n");
      }
      return 0;
    }
    v18 = (CTilegenAction_AddConnectorRoomCandidates *)operator new(nSize: 0x18u);
    if ( v18 != nullptr )
    {
      v19 = pAction;
      v18->__vftable = (CTilegenAction_AddConnectorRoomCandidates_vtbl *)&CTilegenAction_AddConnectorRoomCandidates::`vftable';
      v18->m_pLevelTheme = nullptr;
      v18->m_pTargetThemeNameExpression = nullptr;
      v18->m_pTargetRoomTemplateFilter = nullptr;
      v18->m_pTargetRoomTemplate = nullptr;
      v18->m_pAddConnectorCandidates = v19;
    }
    else
    {
      v18 = nullptr;
    }
    this->m_pAddConnectorRoomCandidates = v18;
  }
  v20 = (CTilegenAction_ChooseCandidate *)operator new(nSize: 8u);
  if ( v20 != nullptr )
  {
    v20->__vftable = (CTilegenAction_ChooseCandidate_vtbl *)&CTilegenAction_ChooseCandidate::`vftable';
    v20->m_bStopProcessingActionsOnSuccess = false;
    this->m_pChooseCandidate = v20;
  }
  else
  {
    this->m_pChooseCandidate = nullptr;
  }
  return bSuccess_3a;
}

//------------------------------------------------------------------------------
// Address: 0x10014D50
// Name: public: CTilegenAction_AddInstanceToRoom::CTilegenAction_AddInstanceToRoom(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_AddInstanceToRoom *__thiscall CTilegenAction_AddInstanceToRoom::CTilegenAction_AddInstanceToRoom(
        CTilegenAction_AddInstanceToRoom *this)
{
  this->__vftable = (CTilegenAction_AddInstanceToRoom_vtbl *)&CTilegenAction_AddInstanceToRoom::`vftable';
  CInstanceSpawn::CInstanceSpawn(this: &this->m_InstanceSpawn);
  this->m_pRoomExpression = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10014D70
// Name: public: virtual bool CTilegenAction_AddInstanceToRoom::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenAction_AddInstanceToRoom::LoadFromKeyValues(
        CTilegenAction_AddInstanceToRoom *this,
        KeyValues *pKeyValues)
{
  bool result; // al
  const char *v4; // eax

  result = CInstanceSpawn::LoadFromKeyValues(this: &this->m_InstanceSpawn, pKeyValues);
  if ( result )
  {
    v4 = this->GetTypeName(this);
    return CreateFromKeyValuesBlock<ITilegenExpression<CRoom const *>>(
             pParentKV: pKeyValues,
             pKeyName: "room",
             pParentClassName: v4,
             ppClass: &this->m_pRoomExpression,
             bOptional: false,
             bCreateEmptyInstance: false);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014DC0
// Name: TryAddRoomCandidate
// Source: json
//------------------------------------------------------------------------------
void __usercall TryAddRoomCandidate(
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *pRoomCandidateList@<esi>,
        const CRoomCandidate *roomCandidate)
{
  const CRoomCandidate *v2; // edx
  int m_pMemory; // edi
  int v4; // ebx
  CRoomCandidate *v5; // eax
  int m_nAllocationCount; // eax
  CRoomCandidate *v7; // ecx
  int v8; // eax
  CRoomCandidate *v9; // eax

  v2 = roomCandidate;
  m_pMemory = (int)pRoomCandidateList[1].m_pMemory;
  v4 = 0;
  if ( m_pMemory <= 0 )
  {
LABEL_8:
    m_nAllocationCount = pRoomCandidateList->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
    {
      CUtlMemory<CRoomCandidate,int>::Grow(this: pRoomCandidateList, num: m_pMemory - m_nAllocationCount + 1);
      v2 = roomCandidate;
    }
    ++pRoomCandidateList[1].m_pMemory;
    v7 = (CRoomCandidate *)pRoomCandidateList->m_pMemory;
    v8 = (int)pRoomCandidateList[1].m_pMemory - m_pMemory - 1;
    pRoomCandidateList[1].m_nAllocationCount = (int)pRoomCandidateList->m_pMemory;
    if ( v8 > 0 )
    {
      _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 20 * v8);
      v2 = roomCandidate;
    }
    v9 = (CRoomCandidate *)&pRoomCandidateList->m_pMemory[m_pMemory];
    if ( v9 != nullptr )
    {
      *(_QWORD *)&v9->m_pRoomTemplate = *(_QWORD *)&v2->m_pRoomTemplate;
      *(_QWORD *)&v9->m_iYPos = *(_QWORD *)&v2->m_iYPos;
      v9->m_flCandidateChance = v2->m_flCandidateChance;
    }
    pRoomCandidateList->m_pMemory[v4].m_ciFlags = 1065353216;
  }
  else
  {
    v5 = (CRoomCandidate *)pRoomCandidateList->m_pMemory;
    while ( v5->m_pRoomTemplate != roomCandidate->m_pRoomTemplate
         || v5->m_iXPos != roomCandidate->m_iXPos
         || v5->m_iYPos != roomCandidate->m_iYPos
         || v5->m_pExit != roomCandidate->m_pExit )
    {
      ++v4;
      ++v5;
      if ( v4 >= m_pMemory )
        goto LABEL_8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014E90
// Name: BuildRoomCandidateList
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildRoomCandidateList(
        CLayoutSystem *pLayoutSystem,
        const CRoomTemplate **ppRoomTemplates,
        int nNumRoomTemplates,
        ITilegenExpression<bool> *pExitFilter,
        ITilegenExpression<bool> *pRoomCandidateFilter,
        ITilegenAction *pRoomCandidateFilterAction,
        ITilegenExpression<bool> *pRoomCandidateFilterCondition,
        bool bExcludeGlobalFilters)
{
  CLayoutSystem *v8; // ebx
  CFreeVariableMap *p_m_FreeVariables; // esi
  CExit *v10; // edi
  void *FreeVariableOrNULL; // eax
  CRoomTemplate *v12; // ebx
  bool v13; // cc
  int v14; // esi
  int v15; // edx
  CFreeVariableMap *v16; // esi
  ITilegenExpression<bool> *v17; // eax
  void *v18; // eax
  CRoomCandidate roomCandidate; // [esp+8h] [ebp-30h] BYREF
  CUtlVector<CRoomCandidate,CUtlMemory<CRoomCandidate,int> > *pRoomCandidateList; // [esp+1Ch] [ebp-1Ch]
  int i; // [esp+20h] [ebp-18h]
  int y; // [esp+24h] [ebp-14h]
  unsigned int v23; // [esp+28h] [ebp-10h]
  int j; // [esp+2Ch] [ebp-Ch]
  ITilegenExpression<bool> *pGlobalRoomCandidateFilter; // [esp+30h] [ebp-8h]
  int x; // [esp+34h] [ebp-4h]

  v8 = pLayoutSystem;
  pRoomCandidateList = pLayoutSystem->m_CurrentIterationState.m_pRoomCandidateList;
  i = 0;
  if ( pLayoutSystem->m_OpenExits.m_Size > 0 )
  {
    p_m_FreeVariables = &pLayoutSystem->m_FreeVariables;
    v23 = 0;
    while ( 1 )
    {
      v10 = &v8->m_OpenExits.m_Memory.m_pMemory[v23 / 0x54];
      CFreeVariableMap::SetOrCreateFreeVariable(this: p_m_FreeVariables, pName: "Exit", pValue: v10);
      if ( bExcludeGlobalFilters )
      {
        FreeVariableOrNULL = nullptr;
        x = 0;
      }
      else
      {
        FreeVariableOrNULL = CFreeVariableMap::GetFreeVariableOrNULL(
                               this: p_m_FreeVariables,
                               pName: "GlobalExitFilters");
        x = (int)FreeVariableOrNULL;
      }
      if ( pExitFilter != nullptr )
      {
        if ( !pExitFilter->Evaluate(this: pExitFilter, a2: p_m_FreeVariables) )
          goto LABEL_29;
        FreeVariableOrNULL = (void *)x;
      }
      if ( FreeVariableOrNULL == nullptr
        || (*(unsigned __int8 (__thiscall **)(void *, CFreeVariableMap *))(*(_DWORD *)FreeVariableOrNULL + 12))(
             a1: FreeVariableOrNULL,
             a2: p_m_FreeVariables) != 0 )
      {
        j = 0;
        if ( nNumRoomTemplates > 0 )
          break;
      }
LABEL_29:
      CFreeVariableMap::SetOrCreateFreeVariable(this: p_m_FreeVariables, pName: "Exit", pValue: nullptr);
      v23 += 84;
      if ( ++i >= v8->m_OpenExits.m_Size )
        goto LABEL_30;
    }
    while ( 1 )
    {
      v12 = (CRoomTemplate *)ppRoomTemplates[j];
      CFreeVariableMap::SetOrCreateFreeVariable(this: p_m_FreeVariables, pName: "RoomTemplate", pValue: v12);
      v13 = v12->m_nTilesX <= 0;
      x = 0;
      if ( !v13 )
        break;
LABEL_27:
      p_m_FreeVariables = &pLayoutSystem->m_FreeVariables;
      CFreeVariableMap::SetOrCreateFreeVariable(
        this: &pLayoutSystem->m_FreeVariables,
        pName: "RoomTemplate",
        pValue: nullptr);
      if ( ++j >= nNumRoomTemplates )
      {
        v8 = pLayoutSystem;
        goto LABEL_29;
      }
    }
    while ( 1 )
    {
      v14 = 0;
      y = 0;
      if ( v12->m_nTilesY > 0 )
        break;
LABEL_26:
      if ( ++x >= v12->m_nTilesX )
        goto LABEL_27;
    }
    while ( !CMapLayout::TemplateFits(
               this: pLayoutSystem->m_pMapLayout,
               pTemplate: v12,
               x: v10->X - x,
               y: v10->Y - v14,
               bAllowNoExits: false) )
    {
LABEL_25:
      y = ++v14;
      if ( v14 >= v12->m_nTilesY )
        goto LABEL_26;
    }
    v15 = v10->Y - v14;
    roomCandidate.m_iXPos = v10->X - x;
    v16 = &pLayoutSystem->m_FreeVariables;
    roomCandidate.m_pRoomTemplate = v12;
    roomCandidate.m_iYPos = v15;
    roomCandidate.m_pExit = v10;
    roomCandidate.m_flCandidateChance = 0.0;
    CFreeVariableMap::SetOrCreateFreeVariable(
      this: &pLayoutSystem->m_FreeVariables,
      pName: "RoomCandidate",
      pValue: &roomCandidate);
    if ( bExcludeGlobalFilters )
    {
      v17 = nullptr;
      pGlobalRoomCandidateFilter = nullptr;
    }
    else
    {
      v17 = (ITilegenExpression<bool> *)CFreeVariableMap::GetFreeVariableOrNULL(
                                          this: v16,
                                          pName: "GlobalRoomCandidateFilters");
      pGlobalRoomCandidateFilter = v17;
    }
    if ( pRoomCandidateFilter != nullptr )
    {
      if ( !pRoomCandidateFilter->Evaluate(this: pRoomCandidateFilter, a2: v16) )
      {
LABEL_24:
        CFreeVariableMap::SetOrCreateFreeVariable(
          this: &pLayoutSystem->m_FreeVariables,
          pName: "RoomCandidate",
          pValue: nullptr);
        v14 = y;
        goto LABEL_25;
      }
      v17 = pGlobalRoomCandidateFilter;
    }
    if ( v17 == nullptr || v17->Evaluate(this: v17, a2: v16) )
      TryAddRoomCandidate((CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)pRoomCandidateList, &roomCandidate);
    goto LABEL_24;
  }
LABEL_30:
  if ( !bExcludeGlobalFilters )
  {
    v18 = CFreeVariableMap::GetFreeVariableOrNULL(this: &v8->m_FreeVariables, pName: "GlobalRoomCandidateFilterActions");
    if ( v18 != nullptr )
      (*(void (__thiscall **)(void *, CLayoutSystem *))(*(_DWORD *)v18 + 20))(a1: v18, a2: v8);
  }
  if ( pRoomCandidateFilterAction != nullptr
    && (pRoomCandidateFilterCondition == nullptr
     || pRoomCandidateFilterCondition->Evaluate(this: pRoomCandidateFilterCondition, a2: &v8->m_FreeVariables)) )
  {
    pRoomCandidateFilterAction->Execute(this: pRoomCandidateFilterAction, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015100
// Name: public: virtual void CTilegenAction_AddRoomCandidates::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_AddRoomCandidates::Execute(
        CTilegenAction_AddRoomCandidates *this,
        CLayoutSystem *pLayoutSystem)
{
  const char *v3; // esi
  CLevelTheme *Theme; // eax
  ITilegenExpression<bool> *m_pRoomTemplateFilter; // ecx
  CLevelTheme *m_pLevelTheme; // edx
  CUtlVector<CRoomTemplate const *,CUtlMemory<CRoomTemplate const *,int> > validRoomTemplates; // [esp+Ch] [ebp-14h] BYREF

  if ( this->m_pLevelTheme != nullptr
    || (v3 = this->m_pThemeNameExpression->Evaluate(
               this: this->m_pThemeNameExpression,
               a2: &pLayoutSystem->m_FreeVariables),
        Theme = CLevelTheme::FindTheme(szThemeName: v3),
        this->m_pLevelTheme = Theme,
        Theme != nullptr) )
  {
    m_pRoomTemplateFilter = this->m_pRoomTemplateFilter;
    m_pLevelTheme = this->m_pLevelTheme;
    memset(&validRoomTemplates, 0, sizeof(validRoomTemplates));
    BuildRoomTemplateList(
      pRoomTemplateList: (CUtlMemory<vgui::TreeNode *,int> *)&validRoomTemplates,
      pLayoutSystem,
      pTheme: m_pLevelTheme,
      pRoomTemplateFilter: m_pRoomTemplateFilter,
      bExcludeGlobalFilters: this->m_bExcludeGlobalFilters);
    BuildRoomCandidateList(
      pLayoutSystem,
      ppRoomTemplates: validRoomTemplates.m_Memory.m_pMemory,
      nNumRoomTemplates: validRoomTemplates.m_Size,
      pExitFilter: this->m_pExitFilter,
      pRoomCandidateFilter: this->m_pRoomCandidateFilter,
      pRoomCandidateFilterAction: this->m_pRoomCandidateFilterAction,
      pRoomCandidateFilterCondition: this->m_pRoomCandidateFilterCondition,
      bExcludeGlobalFilters: this->m_bExcludeGlobalFilters);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&validRoomTemplates);
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Theme %s not found.\n");
    CLayoutSystem::OnError(this: pLayoutSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100151E0
// Name: public: virtual void CTilegenAction_AddRoomCandidatesAtLocation::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_AddRoomCandidatesAtLocation::Execute(
        CTilegenAction_AddRoomCandidatesAtLocation *this,
        CLayoutSystem *pLayoutSystem)
{
  const char *v3; // eax
  CLevelTheme *Theme; // eax
  CFreeVariableMap *p_m_FreeVariables; // ebx
  int v6; // eax
  ITilegenExpression<int> *m_pYExpression; // ecx
  ITilegenExpression<int>_vtbl *v8; // edx
  int v9; // eax
  bool v10; // cc
  int v11; // esi
  ITilegenExpression<bool> *m_pRoomTemplateFilter; // ecx
  CUtlVector<CRoomCandidate,CUtlMemory<CRoomCandidate,int> > *m_pRoomCandidateList; // esi
  CLevelTheme *m_pLevelTheme; // edx
  CRoomCandidate roomCandidate; // [esp+Ch] [ebp-20h] BYREF
  int nY; // [esp+20h] [ebp-Ch]
  int nX; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  if ( this->m_pLevelTheme == nullptr )
  {
    v3 = this->m_pThemeNameExpression->Evaluate(this: this->m_pThemeNameExpression, a2: &pLayoutSystem->m_FreeVariables);
    if ( v3 == nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "No theme name specified.\n");
LABEL_5:
      CLayoutSystem::OnError(this: pLayoutSystem);
      return;
    }
    Theme = CLevelTheme::FindTheme(szThemeName: v3);
    this->m_pLevelTheme = Theme;
    if ( Theme == nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Theme %s not found.\n");
      goto LABEL_5;
    }
  }
  p_m_FreeVariables = &pLayoutSystem->m_FreeVariables;
  v6 = this->m_pXExpression->Evaluate(this: this->m_pXExpression, a2: &pLayoutSystem->m_FreeVariables);
  m_pYExpression = this->m_pYExpression;
  v8 = m_pYExpression->__vftable;
  nX = v6;
  v9 = v8->Evaluate(this: m_pYExpression, a2: &pLayoutSystem->m_FreeVariables);
  v10 = this->m_pLevelTheme->m_RoomTemplates.m_Size <= 0;
  nY = v9;
  i = 0;
  if ( !v10 )
  {
    do
    {
      v11 = i;
      if ( CMapLayout::TemplateFits(
             this: pLayoutSystem->m_pMapLayout,
             pTemplate: this->m_pLevelTheme->m_RoomTemplates.m_Memory.m_pMemory[i],
             x: nX,
             y: nY,
             bAllowNoExits: false) )
      {
        CFreeVariableMap::SetOrCreateFreeVariable(
          this: p_m_FreeVariables,
          pName: "RoomTemplate",
          pValue: this->m_pLevelTheme->m_RoomTemplates.m_Memory.m_pMemory[v11]);
        m_pRoomTemplateFilter = this->m_pRoomTemplateFilter;
        if ( m_pRoomTemplateFilter == nullptr
          || m_pRoomTemplateFilter->Evaluate(this: m_pRoomTemplateFilter, a2: p_m_FreeVariables) )
        {
          roomCandidate.m_pRoomTemplate = this->m_pLevelTheme->m_RoomTemplates.m_Memory.m_pMemory[v11];
          roomCandidate.m_iXPos = nX;
          m_pRoomCandidateList = pLayoutSystem->m_CurrentIterationState.m_pRoomCandidateList;
          roomCandidate.m_iYPos = nY;
          roomCandidate.m_pExit = nullptr;
          roomCandidate.m_flCandidateChance = 0.0;
          TryAddRoomCandidate(
            pRoomCandidateList: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)m_pRoomCandidateList,
            &roomCandidate);
        }
        CFreeVariableMap::SetOrCreateFreeVariable(this: p_m_FreeVariables, pName: "RoomTemplate", pValue: nullptr);
      }
      m_pLevelTheme = this->m_pLevelTheme;
      ++i;
    }
    while ( i < m_pLevelTheme->m_RoomTemplates.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100153A0
// Name: private: bool CTilegenAction_PlaceComponent::PlaceRoom(class CLayoutSystem __near *,class CRoomTemplate const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenAction_PlaceComponent::PlaceRoom(
        CTilegenAction_PlaceComponent *this,
        CLayoutSystem *pLayoutSystem,
        const CRoomTemplate *pRoomTemplate)
{
  int v4; // ebx

  v4 = 0;
  while ( 1 )
  {
    BuildRoomCandidateList(
      pLayoutSystem,
      ppRoomTemplates: &pRoomTemplate,
      nNumRoomTemplates: 1,
      pExitFilter: this->m_pExitFilter,
      pRoomCandidateFilter: this->m_pRoomCandidateFilter,
      pRoomCandidateFilterAction: this->m_pRoomCandidateFilterAction,
      pRoomCandidateFilterCondition: this->m_pRoomCandidateFilterCondition,
      bExcludeGlobalFilters: this->m_bExcludeGlobalFilters);
    if ( pLayoutSystem->m_CurrentIterationState.m_pRoomCandidateList->m_Size > 0 )
    {
      CLayoutSystem::ExecuteAction(this: pLayoutSystem, pAction: this->m_pChooseCandidate, pCondition: nullptr);
      return 1;
    }
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 0) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 0,
        a3: "Unable to place component room %s, attempting to place connector room.\n");
    if ( this->m_pAddConnectorRoomCandidates == nullptr )
      break;
    this->m_pAddConnectorRoomCandidates->m_pTargetRoomTemplate = pRoomTemplate;
    CLayoutSystem::ExecuteAction(this: pLayoutSystem, pAction: this->m_pAddConnectorRoomCandidates, pCondition: nullptr);
    if ( pLayoutSystem->m_CurrentIterationState.m_pRoomCandidateList->m_Size <= 0 )
      break;
    CLayoutSystem::ExecuteAction(this: pLayoutSystem, pAction: this->m_pChooseCandidate, pCondition: nullptr);
    if ( ++v4 >= 10 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Unable to place component room %s after %d tries.\n");
      return 0;
    }
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Unable to place connector piece to connect to component room %s.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100154F0
// Name: public: CTilegenAction_AddInstances::CTilegenAction_AddInstances(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenAction_AddInstances *__thiscall CTilegenAction_AddInstances::CTilegenAction_AddInstances(
        CTilegenAction_AddInstances *this)
{
  this->__vftable = (CTilegenAction_AddInstances_vtbl *)&CTilegenAction_AddInstances::`vftable';
  CInstanceSpawn::CInstanceSpawn(this: &this->m_InstanceSpawn);
  this->m_pInstanceCount = nullptr;
  this->m_pRoomTemplateFilter = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100155E0
// Name: public: virtual void CTilegenAction_PlaceComponent::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_PlaceComponent::Execute(
        CTilegenAction_PlaceComponent *this,
        CLayoutSystem *pLayoutSystem)
{
  CTilegenState *m_pGlobalActionState; // esi
  CFreeVariableMap *p_m_FreeVariables; // edi
  const char *v4; // eax
  const char *v5; // esi
  void *FreeVariableOrNULL; // ebx
  int m_Size; // esi
  int v8; // ecx
  float *p_m_flPlacementFraction; // edx
  int v10; // esi
  void *nNumTilesPlaced; // [esp+Ch] [ebp-8h]

  m_pGlobalActionState = pLayoutSystem->m_pGlobalActionState;
  p_m_FreeVariables = &pLayoutSystem->m_FreeVariables;
  if ( CFreeVariableMap::GetFreeVariableDisallowNULL(this: &pLayoutSystem->m_FreeVariables, pName: "CurrentState") == m_pGlobalActionState )
  {
    v4 = "TotalGenerationArea";
    v5 = "NumTilesPlaced";
  }
  else
  {
    v4 = "StepGenerationArea";
    v5 = "NumTilesPlacedThisState";
  }
  FreeVariableOrNULL = CFreeVariableMap::GetFreeVariableOrNULL(this: p_m_FreeVariables, pName: v4);
  nNumTilesPlaced = CFreeVariableMap::GetFreeVariableOrNULL(this: p_m_FreeVariables, pName: v5);
  if ( (int)FreeVariableOrNULL <= 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 0) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 0,
        a3: "Ignoring PlaceComponent action since no tiles have been placed yet.\n");
    goto LABEL_7;
  }
  m_Size = this->m_RoomsToPlace.m_Size;
  v8 = 0;
  if ( m_Size <= 0 )
  {
LABEL_7:
    CFreeVariableMap::SetOrCreateFreeVariable(this: p_m_FreeVariables, pName: "PlacedComponent", pValue: nullptr);
    return;
  }
  p_m_flPlacementFraction = &this->m_RoomsToPlace.m_Memory.m_pMemory->m_flPlacementFraction;
  while ( *((_BYTE *)p_m_flPlacementFraction + 4) != 0
       || (int)nNumTilesPlaced < (int)(float)((float)(int)FreeVariableOrNULL * *p_m_flPlacementFraction) )
  {
    ++v8;
    p_m_flPlacementFraction += 3;
    if ( v8 >= m_Size )
      goto LABEL_7;
  }
  v10 = v8;
  if ( CTilegenAction_PlaceComponent::PlaceRoom(
         this,
         pLayoutSystem,
         pRoomTemplate: this->m_RoomsToPlace.m_Memory.m_pMemory[v8].pInfo->m_pRoomTemplate) != 0 )
  {
    this->m_RoomsToPlace.m_Memory.m_pMemory[v10].m_bPlaced = true;
    CFreeVariableMap::SetOrCreateFreeVariable(this: p_m_FreeVariables, pName: "PlacedComponent", pValue: (void *)1);
  }
  else
  {
    CLayoutSystem::OnError(this: pLayoutSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015830
// Name: public: virtual void CTilegenAction_AddInstances::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_AddInstances::Execute(CTilegenAction_AddInstances *this, CLayoutSystem *pLayoutSystem)
{
  CFreeVariableMap *p_m_FreeVariables; // edi
  int m_Size; // esi
  CMapLayout *m_pMapLayout; // eax
  int v6; // ecx
  int *m_pMemory; // edx
  int *v8; // ecx
  CMapLayout *v9; // edi
  int v10; // esi
  int m_nAllocationCount; // eax
  CInstanceSpawn *v12; // ecx
  int v13; // eax
  CInstanceSpawn *v14; // ecx
  int v15; // esi
  bool v16; // zf
  CInstanceSpawn *v17; // ecx
  CInstanceSpawn *v18; // esi
  int v19; // eax
  CUtlVector<int,CUtlMemory<int,int> > validCandidates; // [esp+Ch] [ebp-34h] BYREF
  char indexString[16]; // [esp+20h] [ebp-20h] BYREF
  int nInstanceCount; // [esp+30h] [ebp-10h]
  int v23; // [esp+34h] [ebp-Ch]
  CTilegenAction_AddInstances *v24; // [esp+38h] [ebp-8h]
  CMapLayout *pMapLayout; // [esp+3Ch] [ebp-4h]
  int i; // [esp+48h] [ebp+8h]
  int ia; // [esp+48h] [ebp+8h]

  v24 = this;
  p_m_FreeVariables = &pLayoutSystem->m_FreeVariables;
  m_Size = 0;
  nInstanceCount = this->m_pInstanceCount->Evaluate(this: this->m_pInstanceCount, a2: &pLayoutSystem->m_FreeVariables);
  m_pMapLayout = pLayoutSystem->m_pMapLayout;
  pMapLayout = m_pMapLayout;
  memset(&validCandidates, 0, sizeof(validCandidates));
  i = 0;
  if ( m_pMapLayout->m_PlacedRooms.m_Size <= 0 )
    goto LABEL_14;
  while ( 1 )
  {
    CFreeVariableMap::SetOrCreateFreeVariable(
      this: p_m_FreeVariables,
      pName: "RoomTemplate",
      pValue: (void *)m_pMapLayout->m_PlacedRooms.m_Memory.m_pMemory[i]->m_pRoomTemplate);
    if ( v24->m_pRoomTemplateFilter == nullptr
      || v24->m_pRoomTemplateFilter->Evaluate(this: v24->m_pRoomTemplateFilter, a2: p_m_FreeVariables) )
    {
      v6 = m_Size;
      v23 = m_Size;
      if ( m_Size + 1 > validCandidates.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&validCandidates,
          num: m_Size - validCandidates.m_Memory.m_nAllocationCount + 1);
        m_Size = validCandidates.m_Size;
        v6 = v23;
      }
      m_pMemory = validCandidates.m_Memory.m_pMemory;
      validCandidates.m_Size = ++m_Size;
      validCandidates.m_pElements = validCandidates.m_Memory.m_pMemory;
      if ( m_Size - v6 - 1 > 0 )
      {
        _V_memmove(
          dest: &validCandidates.m_Memory.m_pMemory[v6 + 1],
          src: &validCandidates.m_Memory.m_pMemory[v6],
          count: 4 * (m_Size - v6 - 1));
        v6 = v23;
        m_pMemory = validCandidates.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v6];
      if ( v8 != nullptr )
        *v8 = i;
    }
    CFreeVariableMap::SetOrCreateFreeVariable(this: p_m_FreeVariables, pName: "RoomTemplate", pValue: nullptr);
    if ( ++i >= pMapLayout->m_PlacedRooms.m_Size )
      break;
    m_pMapLayout = pMapLayout;
  }
  if ( m_Size != 0 )
  {
    ia = 0;
    if ( nInstanceCount > 0 )
    {
      v9 = pMapLayout;
      pMapLayout = (CMapLayout *)(m_Size - 1);
      do
      {
        v10 = v9->m_InstanceSpawns.m_Size;
        m_nAllocationCount = v9->m_InstanceSpawns.m_Memory.m_nAllocationCount;
        if ( v10 + 1 > m_nAllocationCount )
          CUtlMemory<CInstanceSpawn,int>::Grow(this: &v9->m_InstanceSpawns.m_Memory, num: v10 - m_nAllocationCount + 1);
        ++v9->m_InstanceSpawns.m_Size;
        v12 = v9->m_InstanceSpawns.m_Memory.m_pMemory;
        v13 = v9->m_InstanceSpawns.m_Size - v10 - 1;
        v9->m_InstanceSpawns.m_pElements = v12;
        if ( v13 > 0 )
          _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 296 * v13);
        v14 = v9->m_InstanceSpawns.m_Memory.m_pMemory;
        v15 = v10;
        v16 = &v14[v15] == nullptr;
        v17 = &v14[v15];
        v23 = v15 * 296;
        if ( !v16 )
          CInstanceSpawn::CInstanceSpawn(this: v17, __that: &v24->m_InstanceSpawn);
        v18 = (CInstanceSpawn *)((char *)v9->m_InstanceSpawns.m_Memory.m_pMemory + v23);
        V_snprintf(pDest: indexString, maxLen: 15, pFormat: "%02d", ia);
        CInstanceSpawn::FixupValues(this: v18, pFindValue: "%N", pReplaceValue: indexString);
        v19 = pLayoutSystem->m_Random.RandomInt(
                this: (struct CUniformRandomStream *)pLayoutSystem,
                a2: 0,
                a3: (int)pMapLayout);
        v18->m_nPlacedRoomIndex = validCandidates.m_Memory.m_pMemory[v19];
        v18->m_nRandomSeed = pLayoutSystem->m_Random.RandomInt(
                               this: (struct CUniformRandomStream *)pLayoutSystem,
                               a2: 1,
                               a3: 1000000000);
        ++ia;
      }
      while ( ia < nInstanceCount );
    }
  }
  else
  {
LABEL_14:
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    {
      v24->GetTypeName(this: v24);
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "No valid candidates found for rule %s.\n");
    }
  }
  if ( validCandidates.m_Memory.m_nGrowSize >= 0 && validCandidates.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validCandidates.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10015A90
// Name: public: virtual void CTilegenAction_AddInstanceToRoom::Execute(class CLayoutSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenAction_AddInstanceToRoom::Execute(
        CTilegenAction_AddInstanceToRoom *this,
        CLayoutSystem *pLayoutSystem)
{
  CMapLayout *m_pMapLayout; // esi
  int m_InstanceFilename; // esi
  const CRoom *pRoom; // [esp+10h] [ebp+8h]

  pRoom = this->m_pRoomExpression->Evaluate(this: this->m_pRoomExpression, a2: &pLayoutSystem->m_FreeVariables);
  if ( pRoom != nullptr )
  {
    m_pMapLayout = pLayoutSystem->m_pMapLayout;
    m_InstanceFilename = (int)m_pMapLayout->m_InstanceSpawns.m_Memory.m_pMemory[CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int>>::InsertBefore(
                                                                                  this: &m_pMapLayout->m_InstanceSpawns,
                                                                                  elem: m_pMapLayout->m_InstanceSpawns.m_Size,
                                                                                  src: &this->m_InstanceSpawn)].m_InstanceFilename;
    *(_DWORD *)(m_InstanceFilename + 288) = pRoom->m_nPlacementIndex;
    *(_DWORD *)(m_InstanceFilename + 292) = pLayoutSystem->m_Random.RandomInt(
                                              this: (struct CUniformRandomStream *)pLayoutSystem,
                                              a2: 1,
                                              a3: 1000000000);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013720
// Name: bool CreateFromKeyValuesBlock<class ITilegenExpression<char const __near *>>(class KeyValues __near *,char const __near *,char const __near *,class ITilegenExpression<char const __near *> __near * __near *,bool,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
        KeyValues *pParentKV,
        const char *pKeyName,
        const char *pParentClassName,
        ITilegenExpression<char const *> **ppClass,
        bool bOptional,
        bool bCreateEmptyInstance)
{
  KeyValues *Key; // eax
  ITilegenExpression<char const *> *v8; // eax

  Key = KeyValues::FindKey(this: pParentKV, keyName: pKeyName, bCreate: false);
  *ppClass = nullptr;
  if ( Key == nullptr )
  {
    if ( !bOptional )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not load sub-key '%s' for parent class '%s'.\n");
      return 0;
    }
    return 1;
  }
  v8 = CreateFromKeyValues_ITilegenExpression_char_const_____(pKeyValues: Key, bCreateEmptyInstance);
  *ppClass = v8;
  if ( v8 != nullptr )
    return 1;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100137E0
// Name: bool CreateFromKeyValuesBlock<class ITilegenExpression<class CRoom const __near *>>(class KeyValues __near *,char const __near *,char const __near *,class ITilegenExpression<class CRoom const __near *> __near * __near *,bool,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl CreateFromKeyValuesBlock<ITilegenExpression<CRoom const *>>(
        KeyValues *pParentKV,
        const char *pKeyName,
        const char *pParentClassName,
        ITilegenExpression<CRoom const *> **ppClass,
        bool bOptional,
        bool bCreateEmptyInstance)
{
  KeyValues *Key; // eax
  ITilegenExpression<CRoom const *> *v8; // eax

  Key = KeyValues::FindKey(this: pParentKV, keyName: pKeyName, bCreate: false);
  *ppClass = nullptr;
  if ( Key == nullptr )
  {
    if ( !bOptional )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not load sub-key '%s' for parent class '%s'.\n");
      return 0;
    }
    return 1;
  }
  v8 = CreateFromKeyValues_ITilegenExpression_CRoom_const_____(pKeyValues: Key, bCreateEmptyInstance);
  *ppClass = v8;
  if ( v8 != nullptr )
    return 1;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Could not create class for sub-key '%s' for parent class '%s'.\n");
  return 0;
}
