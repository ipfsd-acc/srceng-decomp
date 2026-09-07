// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/sceneentity.cpp
// Functions: 188
// ============================================================

#include "game\server\sceneentity.h"

//------------------------------------------------------------------------------
// Address: 0x10044800
// Name: public: void CScriptScopeT<class CDefScriptScopeBase>::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptScopeT<CDefScriptScopeBase>::Term(CScriptScopeT<CDefScriptScopeBase> *this)
{
  IScriptVM *v2; // ebx
  int i; // edi

  if ( this->m_hScope == (HSCRIPT__ *)-1 )
  {
    this->m_flags = 0;
  }
  else
  {
    v2 = g_pScriptVM;
    if ( g_pScriptVM != nullptr )
    {
      for ( i = 0; i < this->m_FuncHandles.m_Size; ++i )
        v2->ReleaseFunction(this: v2, a2: *this->m_FuncHandles.m_Memory.m_pMemory[i]);
    }
    this->m_FuncHandles.m_Size = 0;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FuncHandles.m_Memory.m_pMemory);
    this->m_FuncHandles.m_Memory.m_pMemory = nullptr;
    this->m_FuncHandles.m_pElements = nullptr;
    if ( this->m_hScope != nullptr && v2 != nullptr && (this->m_flags & 1) == 0 )
      v2->ReleaseScope(this: v2, a2: this->m_hScope);
    this->m_flags = 0;
    this->m_hScope = (HSCRIPT__ *)-1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098BA0
// Name: public: static bool CMemberScriptBinding0<class CBasePlayer __near *,bool (CBasePlayer::*)(void),bool>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding0<CBasePlayer *,bool (__thiscall CBasePlayer::*)(void),bool>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext == nullptr )
    return 0;
  pReturn->m_char = pFunction();
  pReturn->m_type = 6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1009F960
// Name: public: static void UtlVectorTemplate<class CAnimationLayer,class CUtlMemory<class CAnimationLayer,int>>::EnsureCapacity(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UtlVectorTemplate<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>::EnsureCapacity(
        char *pStruct,
        int offsetToUtlVector,
        int len)
{
  char *v3; // ebx
  void *v4; // edx
  void *v5; // eax
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // [esp-4h] [ebp-10h]

  v3 = &pStruct[offsetToUtlVector + 4];
  if ( *(_DWORD *)v3 < len && *(int *)&pStruct[offsetToUtlVector + 8] >= 0 )
  {
    v4 = *(void **)&pStruct[offsetToUtlVector];
    *(_DWORD *)v3 = len;
    v8 = 76 * len;
    if ( v4 != nullptr )
      v5 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v4, a3: v8);
    else
      v5 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v8);
    *(_DWORD *)&pStruct[offsetToUtlVector] = v5;
  }
  v6 = *(_DWORD *)&pStruct[offsetToUtlVector];
  v7 = *(_DWORD *)v3;
  *(_DWORD *)&pStruct[offsetToUtlVector + 16] = v6;
  memset(
    dst: (unsigned __int8 *)(v6 + 76 * *(_DWORD *)&pStruct[offsetToUtlVector + 12]),
    value: 0,
    count: 76 * (v7 - *(_DWORD *)&pStruct[offsetToUtlVector + 12]));
}

//------------------------------------------------------------------------------
// Address: 0x100B4A20
// Name: public: struct HSCRIPT__ __near * CScriptScopeT<class CDefScriptScopeBase>::LookupFunction(char const __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CScriptScopeT<CDefScriptScopeBase>::LookupFunction(
        CScriptScopeT<CDefScriptScopeBase> *this,
        const char *pszFunction)
{
  return g_pScriptVM->LookupFunction(this: g_pScriptVM, a2: pszFunction, a3: this->m_hScope);
}

//------------------------------------------------------------------------------
// Address: 0x100BBFD0
// Name: public: void CScriptScopeT<class CDefScriptScopeBase>::InvalidateCachedValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptScopeT<CDefScriptScopeBase>::InvalidateCachedValues(CScriptScopeT<CDefScriptScopeBase> *this)
{
  IScriptVM *v1; // ebx
  int v3; // esi
  HSCRIPT__ **v4; // eax
  HSCRIPT__ **v5; // ecx

  v1 = g_pScriptVM;
  v3 = 0;
  if ( this->m_FuncHandles.m_Size <= 0 )
  {
    this->m_FuncHandles.m_Size = 0;
  }
  else
  {
    do
    {
      v4 = this->m_FuncHandles.m_Memory.m_pMemory[v3];
      if ( *v4 != nullptr )
        v1->ReleaseFunction(this: v1, a2: *v4);
      v5 = this->m_FuncHandles.m_Memory.m_pMemory[v3++];
      *v5 = (HSCRIPT__ *)-1;
    }
    while ( v3 < this->m_FuncHandles.m_Size );
    this->m_FuncHandles.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C02B0
// Name: public: enum ScriptStatus_t CScriptScopeT<class CDefScriptScopeBase>::Run(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptScopeT<CDefScriptScopeBase>::Run(
        CScriptScopeT<CDefScriptScopeBase> *this,
        const char *pszScriptText,
        const char *pszScriptName)
{
  HSCRIPT__ *v4; // esi
  ScriptStatus_t v5; // edi

  CScriptScopeT<CDefScriptScopeBase>::InvalidateCachedValues(this);
  v4 = g_pScriptVM->CompileScript(this: g_pScriptVM, a2: pszScriptText, a3: pszScriptName);
  if ( v4 == nullptr )
    return -1;
  v5 = g_pScriptVM->Run_2(this: g_pScriptVM, a2: v4, a3: this->m_hScope, a4: true);
  g_pScriptVM->ReleaseScript(this: g_pScriptVM, a2: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1014C450
// Name: public: virtual short CChoreoStringPool::FindOrAddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoStringPool::FindOrAddString(CGameRules *this, const char *pTeamName)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6950
// Name: public: enum ScriptStatus_t CScriptScopeT<class CDefScriptScopeBase>::Call(char const __near *,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptScopeT<CDefScriptScopeBase>::Call(
        CScriptScopeT<CDefScriptScopeBase> *this,
        const char *pszFunction,
        ScriptVariant_t *pReturn)
{
  HSCRIPT__ *v4; // esi
  ScriptStatus_t v6; // edi

  v4 = g_pScriptVM->LookupFunction(this: g_pScriptVM, a2: pszFunction, a3: this->m_hScope);
  if ( v4 == nullptr )
    return -1;
  v6 = g_pScriptVM->ExecuteFunction(
         this: g_pScriptVM,
         a2: v4,
         a3: nullptr,
         a4: 0,
         a5: pReturn,
         a6: this->m_hScope,
         a7: true);
  g_pScriptVM->ReleaseFunction(this: g_pScriptVM, a2: v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101D69B0
// Name: public: enum ScriptStatus_t CScriptScopeT<class CDefScriptScopeBase>::Call<struct HSCRIPT__ __near *>(char const __near *,struct ScriptVariant_t __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptScopeT<CDefScriptScopeBase>::Call<HSCRIPT__ *>(
        CScriptScopeT<CDefScriptScopeBase> *this,
        const char *pszFunction,
        ScriptVariant_t *pReturn,
        HSCRIPT__ *arg1)
{
  HSCRIPT__ *v5; // esi
  ScriptStatus_t v7; // edi
  HSCRIPT__ *m_hScope; // [esp-4h] [ebp-14h]
  ScriptVariant_t args[1]; // [esp+8h] [ebp-8h] BYREF

  args[0].m_int = (int)arg1;
  m_hScope = this->m_hScope;
  *(_DWORD *)&args[0].m_type = 33;
  v5 = g_pScriptVM->LookupFunction(this: g_pScriptVM, a2: pszFunction, a3: m_hScope);
  if ( v5 == nullptr )
    return -1;
  v7 = g_pScriptVM->ExecuteFunction(
         this: g_pScriptVM,
         a2: v5,
         a3: args,
         a4: 1,
         a5: pReturn,
         a6: this->m_hScope,
         a7: true);
  g_pScriptVM->ReleaseFunction(this: g_pScriptVM, a2: v5);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101FE000
// Name: private: virtual struct datamap_t __near * CSceneManager::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSceneManager::GetDataDescMap(CSceneManager *this)
{
  return &CSceneManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101FE010
// Name: public: virtual class ServerClass __near * CSceneEntity::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CSceneEntity::GetServerClass(CSceneEntity *this)
{
  return &g_CSceneEntity_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101FE020
// Name: public: virtual struct datamap_t __near * CSceneEntity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSceneEntity::GetDataDescMap(CSceneEntity *this)
{
  return &CSceneEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101FE030
// Name: public: virtual struct ScriptClassDesc_t __near * CSceneEntity::GetScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__thiscall CSceneEntity::GetScriptDesc(CSceneEntity *this)
{
  return GetScriptDesc(__formal: this);
}

//------------------------------------------------------------------------------
// Address: 0x101FE050
// Name: public: virtual void CSceneEntity::DispatchPauseScene(class CChoreoScene __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchPauseScene(CSceneEntity *this, CChoreoScene *scene, const char *parameters)
{
  const char *v4; // edi
  const char *v5; // edi
  long double v6; // st7
  char token[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( !this->m_bRestoring )
  {
    this->PausePlayback(this);
    this->m_bPausedViaInput = false;
    this->m_bAutomated = false;
    this->m_nAutomatedAction = 0;
    this->m_flAutomationDelay = 0.0;
    this->m_flAutomationTime = 0.0;
    v4 = engine->ParseFile(this: engine, a2: parameters, a3: token, a4: 1024);
    if ( _V_stricmp(s1: token, s2: "automate") == 0 )
    {
      v5 = engine->ParseFile(this: engine, a2: v4, a3: token, a4: 1024);
      if ( _V_stricmp(s1: token, s2: "Cancel") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "Resume") == 0 )
          this->m_nAutomatedAction = 2;
      }
      else
      {
        this->m_nAutomatedAction = 1;
      }
      if ( this->m_nAutomatedAction != 0 )
      {
        engine->ParseFile(this: engine, a2: v5, a3: token, a4: 1024);
        v6 = atof(nptr: token);
        this->m_flAutomationDelay = v6;
        if ( v6 > 0.0 )
        {
          this->m_bAutomated = true;
          this->m_flAutomationTime = 0.0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE1B0
// Name: public: virtual void CSceneEntity::DispatchStopPoint(class CChoreoScene __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchStopPoint(CSceneEntity *this, CChoreoScene *scene, CChoreoScene *parameters)
{
  const char *pszValue; // ecx

  if ( this->m_bCompletedEarly )
  {
    pszValue = this->m_iszSceneFile.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "Scene '%s' with two stop point events!\n", pszValue);
  }
  else
  {
    this->m_bCompletedEarly = true;
    COutputEvent::FireOutput(this: &this->m_OnCompletion, pActivator: this, pCaller: this, fDelay: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE200
// Name: public: virtual void CSceneEntity::DispatchStartInterrupt(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchStartInterrupt(CSceneEntity *this, CChoreoScene *scene, CChoreoScene *event)
{
  const char *pszValue; // eax

  if ( !this->m_bRestoring )
  {
    if ( this->m_bCancelAtNextInterrupt )
    {
      this->m_bCancelAtNextInterrupt = false;
      pszValue = this->m_iszSceneFile.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      Scene_Printf(pFormat: "%s : cancelled via interrupt\n", pszValue);
      this->CancelPlayback(this);
    }
    else
    {
      ++this->m_nInterruptCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE260
// Name: public: virtual void CSceneEntity::DispatchEndInterrupt(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchEndInterrupt(CSceneEntity *this, CChoreoScene *scene, CChoreoScene *event)
{
  if ( !this->m_bRestoring && --this->m_nInterruptCount < 0 )
    this->m_nInterruptCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FE280
// Name: public: virtual void CSceneEntity::DispatchEndFlexAnimation(class CChoreoScene __near *,class CBaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchEndFlexAnimation(
        CSceneEntity *this,
        CChoreoScene *scene,
        CBaseFlex *actor,
        CChoreoEvent *event)
{
  CBaseFlex::RemoveSceneEvent(this: actor, scene, event, fastKill: false);
}

//------------------------------------------------------------------------------
// Address: 0x101FE2A0
// Name: public: virtual void CSceneEntity::DispatchStartGesture(class CChoreoScene __near *,class CBaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchStartGesture(
        CSceneEntity *this,
        CChoreoActor *scene,
        CBaseFlex *actor,
        CChoreoEvent *event)
{
  const char *Name; // eax

  Name = CChoreoEvent::GetName(this: event);
  if ( _V_stricmp(s1: Name, s2: "NULL") != 0 )
    CBaseFlex::AddSceneEvent(this: actor, scene, event, pTarget: nullptr, pSceneEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x101FE2E0
// Name: public: virtual void CSceneEntity::DispatchEndGesture(class CChoreoScene __near *,class CBaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchEndGesture(
        CSceneEntity *this,
        CChoreoScene *scene,
        CBaseFlex *actor,
        CChoreoEvent *event)
{
  const char *Name; // eax

  Name = CChoreoEvent::GetName(this: event);
  if ( _V_stricmp(s1: Name, s2: "NULL") != 0 )
    CBaseFlex::RemoveSceneEvent(this: actor, scene, event, fastKill: this->m_bRestoring);
}

//------------------------------------------------------------------------------
// Address: 0x101FE320
// Name: public: virtual void CSceneEntity::DispatchStartGeneric(class CChoreoScene __near *,class CBaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchStartGeneric(
        CSceneEntity *this,
        CChoreoActor *scene,
        CBaseFlex *actor,
        CChoreoEvent *event)
{
  CSceneEntity_vtbl *v5; // edi
  const char *Parameters2; // eax
  CBaseEntity *v7; // eax

  v5 = this->CPointEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  Parameters2 = CChoreoEvent::GetParameters2(this: event);
  v7 = v5->FindNamedEntity(this, a2: Parameters2, a3: nullptr, a4: false, a5: false);
  CBaseFlex::AddSceneEvent(this: actor, scene, event, pTarget: v7, pSceneEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x101FE360
// Name: public: virtual void CSceneEntity::DispatchStartFace(class CChoreoScene __near *,class CBaseFlex __near *,class CBaseEntity __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchStartFace(
        CSceneEntity *this,
        CChoreoActor *scene,
        CBaseFlex *actor,
        CBaseEntity *actor2,
        CChoreoEvent *event)
{
  CBaseFlex::AddSceneEvent(this: actor, scene, event, pTarget: actor2, pSceneEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x101FE380
// Name: public: virtual void CSceneEntity::DispatchStartExpression(class CChoreoScene __near *,class CBaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchStartExpression(
        CSceneEntity *this,
        CChoreoActor *scene,
        CBaseFlex *actor,
        CChoreoEvent *event)
{
  CBaseFlex::AddSceneEvent(this: actor, scene, event, pTarget: nullptr, pSceneEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x101FE3A0
// Name: public: virtual void CSceneEntity::DispatchEndMoveTo(class CChoreoScene __near *,class CBaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchEndMoveTo(
        CSceneEntity *this,
        CChoreoScene *scene,
        CBaseFlex *actor,
        CChoreoEvent *event)
{
  CBaseFlex::RemoveSceneEvent(this: actor, scene, event, fastKill: this->m_bRestoring);
}

//------------------------------------------------------------------------------
// Address: 0x101FE3C0
// Name: public: virtual void CSceneEntity::DispatchStartPermitResponses(class CChoreoScene __near *,class CBaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchStartPermitResponses(
        CSceneEntity *this,
        CChoreoScene *scene,
        CBaseFlex *actor,
        CChoreoEvent *event)
{
  float endtime; // [esp+0h] [ebp-4h]

  endtime = ((double (__thiscall *)(CChoreoEvent *))event->GetDuration)(a1: event) + gpGlobals->curtime;
  CBaseFlex::SetPermitResponse(this: actor, endtime);
}

//------------------------------------------------------------------------------
// Address: 0x101FE3F0
// Name: public: virtual void CSceneEntity::DispatchEndPermitResponses(class CChoreoScene __near *,class CBaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchEndPermitResponses(
        CSceneEntity *this,
        CChoreoScene *scene,
        CBaseFlex *actor,
        CChoreoEvent *event)
{
  CBaseFlex::SetPermitResponse(this: actor, endtime: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101FE410
// Name: public: bool CSceneEntity::InvolvesActor(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneEntity::InvolvesActor(CSceneEntity *this, CBaseFlex *pActor)
{
  CChoreoScene *m_pScene; // ecx
  int v5; // edi
  CBaseFlex *v6; // eax

  m_pScene = this->m_pScene;
  if ( m_pScene == nullptr )
    return 0;
  v5 = 0;
  if ( CChoreoScene::GetNumActors(this: m_pScene) <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = this->FindNamedActor_3(this, a2: v5);
    if ( v6 != nullptr && v6 == pActor )
      break;
    if ( ++v5 >= CChoreoScene::GetNumActors(this: this->m_pScene) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101FE470
// Name: public: void CSceneEntity::InputPausePlayback(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputPausePlayback(CSceneEntity *this, inputdata_t *inputdata)
{
  this->PausePlayback(this);
  this->m_bPausedViaInput = true;
}

//------------------------------------------------------------------------------
// Address: 0x101FE490
// Name: public: void CSceneEntity::InputResumePlayback(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputResumePlayback(CSceneEntity *this, inputdata_t *inputdata)
{
  this->ResumePlayback(this);
}

//------------------------------------------------------------------------------
// Address: 0x101FE4A0
// Name: public: void CSceneEntity::InputCancelPlayback(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputCancelPlayback(CSceneEntity *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  pszValue = this->m_iszSceneFile.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  Scene_Printf(pFormat: "%s : cancelled via input\n", pszValue);
  this->CancelPlayback(this);
}

//------------------------------------------------------------------------------
// Address: 0x101FE4D0
// Name: public: void CSceneEntity::InputScriptPlayerDeath(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputScriptPlayerDeath(CSceneEntity *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  if ( this->m_iPlayerDeathBehavior == 1 )
  {
    pszValue = this->m_iszSceneFile.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    Scene_Printf(pFormat: "%s : cancelled via player death\n", pszValue);
    this->CancelPlayback(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE510
// Name: public: void CSceneEntity::InputCancelAtNextInterrupt(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputCancelAtNextInterrupt(CSceneEntity *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  if ( this->m_nInterruptCount <= 0 )
  {
    this->m_bCancelAtNextInterrupt = true;
  }
  else
  {
    pszValue = this->m_iszSceneFile.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    Scene_Printf(pFormat: "%s : cancelled via input at interrupt point\n", pszValue);
    this->CancelPlayback(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE560
// Name: public: static bool CSceneEntity::SpeakEventSoundLessFunc(struct CSceneEntity::SpeakEventSound_t const __near &,struct CSceneEntity::SpeakEventSound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CSceneEntity::SpeakEventSoundLessFunc(
        const CSceneEntity::SpeakEventSound_t *lhs,
        const CSceneEntity::SpeakEventSound_t *rhs)
{
  return rhs->m_flStartTime > lhs->m_flStartTime;
}

//------------------------------------------------------------------------------
// Address: 0x101FE580
// Name: public: virtual void CSceneEntity::DispatchStartSubScene(class CChoreoScene __near *,class CBaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchStartSubScene(
        CSceneEntity *this,
        CChoreoScene *scene,
        CBaseFlex *pActor,
        CChoreoEvent *event)
{
  CChoreoScene *SubScene; // eax

  if ( !CChoreoScene::IsSubScene(this: scene) )
  {
    SubScene = (CChoreoScene *)CChoreoEvent::GetSubScene(this: (vgui::Panel *)event);
    if ( SubScene != nullptr )
      CChoreoScene::ResetSimulation(this: SubScene, forward: true, starttime: 0.0, endtime: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE5C0
// Name: public: virtual void CSceneEntity::ProcessEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::ProcessEvent(
        CSceneEntity *this,
        float currenttime,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  CChoreoScene *SubScene; // eax
  CChoreoScene *v6; // esi

  if ( CChoreoEvent::GetType(this: event) == SUBSCENE )
  {
    SubScene = (CChoreoScene *)CChoreoEvent::GetSubScene(this: (vgui::Panel *)event);
    v6 = SubScene;
    if ( SubScene != nullptr && !CChoreoScene::SimulationFinished(this: SubScene) )
      CChoreoScene::Think(this: v6, curtime: this->m_flPrevAnimTime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE610
// Name: public: virtual class CBaseFlex __near * CSceneEntity::FindNamedActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseFlex *__thiscall CSceneEntity::FindNamedActor(CSceneEntity *this, CChoreoActor *pChoreoActor)
{
  int ActorIndex; // eax

  ActorIndex = CChoreoScene::FindActorIndex(this: this->m_pScene, actor: pChoreoActor);
  if ( ActorIndex < 0 )
    return nullptr;
  else
    return this->FindNamedActor_3(this, a2: ActorIndex);
}

//------------------------------------------------------------------------------
// Address: 0x101FE650
// Name: public: virtual class CBaseFlex __near * CSceneEntity::FindNamedActor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseFlex *__thiscall CSceneEntity::FindNamedActor(CSceneEntity *this, const char *name)
{
  CBaseFlex *result; // eax

  result = (CBaseFlex *)this->FindNamedEntity(this, a2: name, a3: 0, a4: 1, a5: 0);
  if ( result != nullptr )
    return (CBaseFlex *)__RTDynamicCast(
                          inptr: result,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CBaseFlex `RTTI Type Descriptor',
                          isReference: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FE690
// Name: private: void CSceneEntity::ClearSceneEvents(class CChoreoScene __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::ClearSceneEvents(CSceneEntity *this, CChoreoScene *scene, BOOL canceled)
{
  const char *pszValue; // eax
  int i; // edi
  CBaseFlex *v6; // eax
  int j; // ebx
  CChoreoEvent *Event; // eax
  vgui::Panel *v9; // edi
  CChoreoScene *SubScene; // eax

  if ( this->m_pScene != nullptr )
  {
    pszValue = this->m_iszSceneFile.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    Scene_Printf(pFormat: "%s : %8.2f:  clearing events\n", pszValue, this->m_flCurrentTime);
    for ( i = 0; i < CChoreoScene::GetNumActors(this: this->m_pScene); ++i )
    {
      v6 = this->FindNamedActor_3(this, a2: i);
      if ( v6 != nullptr )
        CBaseFlex::ClearSceneEvents(this: v6, scene, canceled);
    }
    for ( j = 0; j < vgui::Image::GetTall(this: (vgui::Image *)scene); ++j )
    {
      Event = CChoreoScene::GetEvent(this: scene, event: j);
      v9 = (vgui::Panel *)Event;
      if ( Event != nullptr && CChoreoEvent::GetType(this: Event) == SUBSCENE && !CChoreoScene::IsSubScene(this: scene) )
      {
        SubScene = (CChoreoScene *)CChoreoEvent::GetSubScene(this: v9);
        if ( SubScene != nullptr )
          CSceneEntity::ClearSceneEvents(this, scene: SubScene, canceled);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE780
// Name: public: virtual void CSceneEntity::NotifyOfCompletion(class CSceneEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::NotifyOfCompletion(CSceneEntity *this, CSceneEntity *interruptor)
{
  void (*CheckInterruptCompletion)(void); // edx

  CheckInterruptCompletion = (void (*)(void))this->CheckInterruptCompletion;
  this->m_bInterruptSceneFinished = true;
  CheckInterruptCompletion();
}

//------------------------------------------------------------------------------
// Address: 0x101FE7A0
// Name: public: void CSceneEntity::AddBroadcastTeamTarget(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::AddBroadcastTeamTarget(CSceneEntity *this, int nTeamIndex)
{
  CRecipientFilter *v3; // eax
  CRecipientFilter *v4; // eax
  CTeam *GlobalTeam; // eax
  CRecipientFilter filter; // [esp+4h] [ebp-20h] BYREF

  if ( this->m_pRecipientFilter == nullptr )
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    v3 = (CRecipientFilter *)operator new(nSize: 0x20u);
    if ( v3 != nullptr )
      v4 = CRecipientFilter::CRecipientFilter(this: v3);
    else
      v4 = nullptr;
    this->m_pRecipientFilter = v4;
    CRecipientFilter::CopyFrom(this: v4, src: &filter);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  GlobalTeam = GetGlobalTeam(iIndex: nTeamIndex);
  if ( GlobalTeam != nullptr )
    CRecipientFilter::AddRecipientsByTeam(this: this->m_pRecipientFilter, team: GlobalTeam);
}

//------------------------------------------------------------------------------
// Address: 0x101FE810
// Name: public: void CSceneEntity::RemoveBroadcastTeamTarget(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::RemoveBroadcastTeamTarget(CSceneEntity *this, int nTeamIndex)
{
  CRecipientFilter *v3; // eax
  CRecipientFilter *v4; // eax
  CTeam *GlobalTeam; // eax
  CRecipientFilter filter; // [esp+4h] [ebp-20h] BYREF

  if ( this->m_pRecipientFilter == nullptr )
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    v3 = (CRecipientFilter *)operator new(nSize: 0x20u);
    if ( v3 != nullptr )
      v4 = CRecipientFilter::CRecipientFilter(this: v3);
    else
      v4 = nullptr;
    this->m_pRecipientFilter = v4;
    CRecipientFilter::CopyFrom(this: v4, src: &filter);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  GlobalTeam = GetGlobalTeam(iIndex: nTeamIndex);
  if ( GlobalTeam != nullptr )
    CRecipientFilter::RemoveRecipientsByTeam(this: this->m_pRecipientFilter, team: GlobalTeam);
}

//------------------------------------------------------------------------------
// Address: 0x101FE880
// Name: private: virtual struct datamap_t __near * CInstancedSceneEntity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CInstancedSceneEntity::GetDataDescMap(CInstancedSceneEntity *this)
{
  return &CInstancedSceneEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101FE890
// Name: int SceneNameAutocomplete(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __cdecl SceneNameAutocomplete(const char *partial, char (*commands)[64])
{
  int v2; // ebx
  const char *v3; // esi
  const char *v4; // esi
  const char *v5; // eax
  char path[512]; // [esp+Ch] [ebp-508h] BYREF
  char dirName[512]; // [esp+20Ch] [ebp-308h] BYREF
  char txtFilenameNoExtension[260]; // [esp+40Ch] [ebp-108h] BYREF
  int findHandle; // [esp+510h] [ebp-4h] BYREF
  int partialLength; // [esp+51Ch] [ebp+8h]

  v2 = 0;
  v3 = &partial[_V_strlen(str: "scene_playvcd") + 1];
  _V_strlen(str: v3);
  V_snprintf(pDest: dirName, maxLen: 512, pFormat: "%sjunk", v3);
  V_ExtractFilePath(path: dirName, dest: dirName, destSize: 512);
  v4 = &v3[_V_strlen(str: dirName)];
  partialLength = _V_strlen(str: v4);
  V_snprintf(pDest: path, maxLen: 512, pFormat: "scenes/%s%s*.*", dirName, v4);
  v5 = filesystem->FindFirstEx(this: filesystem, a2: path, a3: "MOD", a4: &findHandle);
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      if ( *v5 != 46 )
      {
        V_FileBase(in: v5, out: txtFilenameNoExtension, maxlen: 260);
        if ( V_strnicmp(s1: txtFilenameNoExtension, s2: v4, n: partialLength) == 0 )
        {
          if ( filesystem->FindIsDirectory(this: filesystem, a2: findHandle) )
            V_snprintf(
              pDest: (char *)commands,
              maxLen: 64,
              pFormat: "%s %s%s/",
              "scene_playvcd",
              dirName,
              txtFilenameNoExtension);
          else
            V_snprintf(
              pDest: (char *)commands,
              maxLen: 64,
              pFormat: "%s %s%s",
              "scene_playvcd",
              dirName,
              txtFilenameNoExtension);
          ++v2;
          ++commands;
          if ( v2 == 64 )
            break;
        }
      }
      v5 = filesystem->FindNext(this: filesystem, a2: findHandle);
      if ( v5 == nullptr )
        goto LABEL_9;
    }
    filesystem->FindClose(this: filesystem, a2: findHandle);
    return 64;
  }
  else
  {
LABEL_9:
    filesystem->FindClose(this: filesystem, a2: findHandle);
    return v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FEA30
// Name: float GetSceneDuration(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetSceneDuration(const char *pszScene)
{
  unsigned int msecs; // esi
  SceneCachedData_t cachedData; // [esp+4h] [ebp-14h] BYREF

  msecs = 0;
  if ( scenefilecache->GetSceneCachedData(this: scenefilecache, a2: pszScene, a3: &cachedData) )
    msecs = cachedData.msecs;
  return (double)msecs * 0.001;
}

//------------------------------------------------------------------------------
// Address: 0x101FEA70
// Name: public: virtual struct datamap_t __near * CSceneListManager::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSceneListManager::GetDataDescMap(CSceneListManager *this)
{
  return &CSceneListManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101FEA80
// Name: int GetRecentNPCSpeech(struct recentNPCSpeech_t __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetRecentNPCSpeech(recentNPCSpeech_t *speech)
{
  int v1; // ebx
  int v2; // ecx
  int result; // eax
  int v4; // ebx
  int v5; // ebx
  int v6; // ebx
  int v7; // ebx
  int v8; // ebx

  v1 = speechListIndex;
  v2 = speechListIndex;
  result = 0;
  speech->time = 0.0;
  speech->name[0] = 0;
  speech->sceneName[0] = 0;
  speech[1].time = 0.0;
  speech[1].name[0] = 0;
  speech[1].sceneName[0] = 0;
  speech[2].time = 0.0;
  speech[2].name[0] = 0;
  speech[2].sceneName[0] = 0;
  speech[3].time = 0.0;
  speech[3].name[0] = 0;
  speech[3].sceneName[0] = 0;
  speech[4].time = 0.0;
  speech[4].name[0] = 0;
  speech[4].sceneName[0] = 0;
  if ( speechListSounds[v2].name[0] != 0 )
  {
    *speech = speechListSounds[v2];
    result = 1;
  }
  v4 = v1 + 1;
  if ( v4 >= 5 )
    v4 = 0;
  if ( speechListSounds[v4].name[0] != 0 )
    qmemcpy(&speech[result++], &speechListSounds[v4], sizeof(recentNPCSpeech_t));
  v5 = v4 + 1;
  if ( v5 >= 5 )
    v5 = 0;
  if ( speechListSounds[v5].name[0] != 0 )
    qmemcpy(&speech[result++], &speechListSounds[v5], sizeof(recentNPCSpeech_t));
  v6 = v5 + 1;
  if ( v6 >= 5 )
    v6 = 0;
  if ( speechListSounds[v6].name[0] != 0 )
    qmemcpy(&speech[result++], &speechListSounds[v6], sizeof(recentNPCSpeech_t));
  v7 = v6 + 1;
  if ( v7 >= 5 )
    v7 = 0;
  v8 = v7;
  if ( speechListSounds[v8].name[0] != 0 )
    qmemcpy(&speech[result++], &speechListSounds[v8], sizeof(recentNPCSpeech_t));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FEBF0
// Name: ListRecentNPCSpeech
// Source: json
//------------------------------------------------------------------------------
void __cdecl ListRecentNPCSpeech()
{
  int RecentNPCSpeech; // edi
  char *name; // esi
  recentNPCSpeech_t speech[5]; // [esp+1Ch] [ebp-C94h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    RecentNPCSpeech = GetRecentNPCSpeech(speech);
    _Msg(a1: "Recent NPC speech:\n");
    if ( RecentNPCSpeech > 0 )
    {
      name = speech[0].name;
      do
      {
        _Msg(a1: "   time: %6.3f   sound name: %s   scene: %s\n", *((float *)name - 1), name, name + 512);
        name += 644;
        --RecentNPCSpeech;
      }
      while ( RecentNPCSpeech != 0 );
    }
    _Msg(a1: "Current time: %6.3f\n", gpGlobals->curtime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FEC90
// Name: scene_flush
// Source: json
//------------------------------------------------------------------------------
void __cdecl scene_flush()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    _Msg(a1: "Reloading\n");
    scenefilecache->Reload(this: scenefilecache);
    _Msg(a1: "   done\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FECD0
// Name: public: enum ScriptStatus_t CScriptScopeT<class CDefScriptScopeBase>::Call<struct HSCRIPT__ __near *,char const __near *,float>(struct HSCRIPT__ __near *,struct ScriptVariant_t __near *,struct HSCRIPT__ __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
ScriptStatus_t __thiscall CScriptScopeT<CDefScriptScopeBase>::Call<HSCRIPT__ *,char const *,float>(
        CScriptScopeT<CDefScriptScopeBase> *this,
        HSCRIPT__ *hFunction,
        ScriptVariant_t *pReturn,
        HSCRIPT__ *arg1,
        const char *arg2,
        float arg3)
{
  HSCRIPT__ *m_hScope; // [esp-8h] [ebp-20h]
  ScriptVariant_t args[3]; // [esp+0h] [ebp-18h] BYREF

  m_hScope = this->m_hScope;
  args[1].m_flags = 0;
  args[0].m_flags = 0;
  args[2].m_flags = 0;
  args[0].m_type = 33;
  args[0].m_int = (int)arg1;
  args[1].m_type = 32;
  args[1].m_int = (int)arg2;
  args[2].m_type = 1;
  args[2].m_float = arg3;
  return g_pScriptVM->ExecuteFunction(
           this: g_pScriptVM,
           a2: hFunction,
           a3: args,
           a4: 3,
           a5: pReturn,
           a6: m_hScope,
           a7: true);
}

//------------------------------------------------------------------------------
// Address: 0x101FED50
// Name: public: virtual bool CChoreoStringPool::GetString(short,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoStringPool::GetString(CChoreoStringPool *this, int stringId, char *buff, int buffSize)
{
  const char *v4; // eax

  v4 = scenefilecache->GetSceneString(this: scenefilecache, a2: stringId);
  if ( v4 != nullptr )
  {
    V_strncpy(pDest: buff, pSrc: v4, maxLen: buffSize);
    return 1;
  }
  else
  {
    V_strncpy(pDest: buff, pSrc: locale, maxLen: buffSize);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FEDA0
// Name: public: bool CSceneEntity::IsPlayingBack(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneEntity::IsPlayingBack(CSceneEntity *this)
{
  return this->m_bIsPlayingBack.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101FEDB0
// Name: public: bool CSceneEntity::IsPaused(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneEntity::IsPaused(CSceneEntity *this)
{
  return this->m_bPaused.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101FEDC0
// Name: private: class CChoreoScene __near * CSceneEntity::GenerateSceneForSound(class CBaseFlex __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoScene *__thiscall CSceneEntity::GenerateSceneForSound(
        CSceneEntity *this,
        CChoreoScene *pFlexActor,
        const char *soundname)
{
  const char *v4; // eax
  const char *v5; // esi
  double SoundDuration; // st7
  CChoreoScene *v8; // eax
  IChoreoEventCallback *v9; // edx
  CBaseFlex *v10; // eax
  CChoreoScene *v11; // esi
  CChoreoActor *v12; // edi
  CChoreoChannel *v13; // ebx
  CChoreoEvent *v14; // eax
  CChoreoEvent *v15; // esi
  const char *pszValue; // eax
  CBaseFlex *v17; // esi
  float duration; // [esp+10h] [ebp-8h]

  if ( pFlexActor != nullptr )
  {
    v4 = *(const char **)((int (__thiscall *)(CChoreoScene *, CChoreoScene **))pFlexActor->__vftable[2].CurveHasEndTime)(
                           a1: pFlexActor,
                           a2: &pFlexActor);
    if ( v4 == nullptr )
      v4 = locale;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = soundname;
  SoundDuration = CBaseEntity::GetSoundDuration(soundname, actormodel: v4);
  if ( SoundDuration <= 0.0 )
  {
    _Warning(a1: "CSceneEntity::GenerateSceneForSound:  Couldn't determine duration of %s\n", v5);
    return nullptr;
  }
  v8 = (CChoreoScene *)operator new(nSize: 0x21Cu);
  if ( v8 == nullptr )
  {
    pFlexActor = nullptr;
    v11 = nullptr;
LABEL_12:
    _Warning(a1: "CSceneEntity::GenerateSceneForSound:  Failed to allocated new scene!!!\n");
    return v11;
  }
  if ( this != nullptr )
    v9 = &this->IChoreoEventCallback;
  else
    v9 = nullptr;
  v10 = (CBaseFlex *)CChoreoScene::CChoreoScene(this: v8, callback: v9);
  v11 = (CChoreoScene *)v10;
  pFlexActor = (CChoreoScene *)v10;
  if ( v10 == nullptr )
    goto LABEL_12;
  vgui::Panel::SetCursor(this: (vgui::Panel *)v10, cursor: (unsigned int)Scene_Printf);
  v12 = CChoreoScene::AllocActor(this: v11);
  v13 = CChoreoScene::AllocChannel(this: v11);
  v14 = CChoreoScene::AllocEvent(this: v11);
  v15 = v14;
  if ( v12 != nullptr && v13 != nullptr && v14 != nullptr )
  {
    CChoreoActor::SetName(this: v12, name: "!self");
    CChoreoActor::SetActive(this: v12, active: true);
    pszValue = this->m_iszSceneFile.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CChoreoChannel::SetName(this: v13, name: pszValue);
    CAI_WaypointList::Set(this: v13, actor: v12);
    CChoreoActor::AddChannel(this: v12, channel: v13);
    CChoreoEvent::SetType(this: v15, type: SPEAK);
    CChoreoEvent::SetName(this: v15, name: soundname);
    CChoreoEvent::SetParameters(this: v15, param: soundname);
    CChoreoEvent::SetStartTime(this: v15, starttime: 0.0);
    CChoreoEvent::SetUsingRelativeTag(this: v15, usetag: false, tagname: nullptr, wavname: nullptr);
    duration = SoundDuration;
    CChoreoEvent::SetEndTime(this: v15, endtime: duration);
    CChoreoEvent::SnapTimes(this: v15);
    CChoreoChannel::AddEvent(this: v13, event: v15);
    CChoreoEvent::SetChannel(this: v15, channel: v13);
    CChoreoEvent::SetActor(this: v15, actor: v12);
    return pFlexActor;
  }
  else
  {
    _Warning(a1: "CSceneEntity::GenerateSceneForSound:  Alloc of actor, channel, or event failed!!!\n");
    v17 = (CBaseFlex *)pFlexActor;
    CChoreoScene::~CChoreoScene(this: pFlexActor);
    free(pMem: v17);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FEFA0
// Name: public: bool CSceneEntity::GetSoundNameForPlayer(class CChoreoEvent __near *,class CBasePlayer __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneEntity::GetSoundNameForPlayer(
        CSceneEntity *this,
        CChoreoEvent *event,
        CBasePlayer *player,
        char *buf,
        unsigned int buflen)
{
  const char *Parameters; // eax
  edict_t *m_pPev; // eax
  char v7; // bl
  const char *v8; // eax
  char tok[66]; // [esp+Ch] [ebp-44h] BYREF
  bool validtoken; // [esp+4Eh] [ebp-2h]
  bool ismasterevent; // [esp+4Fh] [ebp-1h]

  ismasterevent = true;
  validtoken = false;
  tok[0] = 0;
  if ( CChoreoEvent::GetCloseCaptionType(this: event) == CC_SLAVE
    || CChoreoEvent::GetCloseCaptionType(this: event) == CC_DISABLED )
  {
    ismasterevent = false;
  }
  else
  {
    validtoken = CChoreoEvent::GetPlaybackCloseCaptionToken(this: event, dest: tok, destlen: 64);
  }
  Parameters = CChoreoEvent::GetParameters(this: event);
  V_strncpy(pDest: buf, pSrc: Parameters, maxLen: buflen);
  m_pPev = player->m_Network.m_pPev;
  v7 = 1;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  v8 = engine->GetClientConVarValue(this: engine, a2: m_pPev, a3: "english");
  if ( v8 != nullptr && *v8 != 0 && V_atoi(str: v8) != 1 )
    v7 = 0;
  if ( (scene_forcecombined.m_pParent == nullptr || scene_forcecombined.m_pParent->m_Value.m_nValue == 0) && v7 != 0 )
    return 1;
  if ( ismasterevent )
  {
    if ( validtoken )
      V_strncpy(pDest: buf, pSrc: tok, maxLen: buflen);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FF090
// Name: public: virtual float CSceneEntity::EstimateLength(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall CSceneEntity::EstimateLength@<st0>(CSceneEntity *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  CChoreoScene *m_pScene; // ecx
  const char *pszValue; // eax
  unsigned int v6; // esi
  _DWORD v9[5]; // [esp+0h] [ebp-14h] BYREF

  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
    return CChoreoScene::FindStopTime(this: m_pScene);
  pszValue = this->m_iszSceneFile.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v6 = 0;
  if ( ((unsigned __int8 (__thiscall *)(ISceneFileCache *, const char *, _DWORD *, int, int))scenefilecache->GetSceneCachedData)(
         a1: scenefilecache,
         a2: pszValue,
         a3: v9,
         a4: a2,
         a5: a3) != 0 )
    v6 = v9[0];
  v9[4] = v6;
  return (double)v6 * 0.001;
}

//------------------------------------------------------------------------------
// Address: 0x101FF100
// Name: public: void CSceneEntity::InputPitchShiftPlayback(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputPitchShiftPlayback(CSceneEntity *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    ((void (__stdcall *)(int))this->PitchShiftPlayback)(a1: inputdata->value.iVal);
  else
    ((void (__stdcall *)(_DWORD))this->PitchShiftPlayback)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101FF140
// Name: public: void CSceneEntity::InputTriggerEvent(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputTriggerEvent(CSceneEntity *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  switch ( (unsigned int)pszValue )
  {
    case 1u:
      COutputEvent::FireOutput(this: &this->m_OnTrigger1, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 2u:
      COutputEvent::FireOutput(this: &this->m_OnTrigger2, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 3u:
      COutputEvent::FireOutput(this: &this->m_OnTrigger3, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 4u:
      COutputEvent::FireOutput(this: &this->m_OnTrigger4, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 5u:
      COutputEvent::FireOutput(this: &this->m_OnTrigger5, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 6u:
      COutputEvent::FireOutput(this: &this->m_OnTrigger6, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 7u:
      COutputEvent::FireOutput(this: &this->m_OnTrigger7, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 8u:
      COutputEvent::FireOutput(this: &this->m_OnTrigger8, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 9u:
      COutputEvent::FireOutput(this: &this->m_OnTrigger9, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 0xAu:
      COutputEvent::FireOutput(this: &this->m_OnTrigger10, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 0xBu:
      COutputEvent::FireOutput(this: &this->m_OnTrigger11, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 0xCu:
      COutputEvent::FireOutput(this: &this->m_OnTrigger12, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 0xDu:
      COutputEvent::FireOutput(this: &this->m_OnTrigger13, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 0xEu:
      COutputEvent::FireOutput(this: &this->m_OnTrigger14, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 0xFu:
      COutputEvent::FireOutput(this: &this->m_OnTrigger15, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    case 0x10u:
      COutputEvent::FireOutput(this: &this->m_OnTrigger16, pActivator: this, pCaller: this, fDelay: 0.0);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FF350
// Name: public: void CSceneEntity::InputStopWaitingForActor(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputStopWaitingForActor(CSceneEntity *this, inputdata_t *inputdata)
{
  if ( !this->m_bIsPlayingBack.m_Value )
    this->m_bWaitingForActor = false;
}

//------------------------------------------------------------------------------
// Address: 0x101FF370
// Name: public: virtual void CSceneEntity::EndEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::EndEvent(CSceneEntity *this, float currenttime, CChoreoScene *scene, CChoreoEvent *event)
{
  const char *Name; // eax
  int v7; // esi
  CChoreoActor *Actor; // eax
  const char *Description; // eax
  const char *Parameters; // eax
  CChoreoScene *SubScene; // eax
  const char *eventa; // [esp+2Ch] [ebp+10h]

  Name = CChoreoEvent::GetName(this: event);
  if ( _V_stricmp(s1: Name, s2: "NULL") != 0 )
  {
    v7 = 0;
    Actor = CChoreoEvent::GetActor(this: event);
    if ( Actor != nullptr )
      v7 = (*(int (__thiscall **)(char *, CChoreoActor *))(*((_DWORD *)this - 213) + 948))(
             a1: (char *)this - 852,
             a2: Actor);
    eventa = (const char *)this->m_pfnMoveDone;
    if ( eventa == nullptr )
      eventa = locale;
    Description = CChoreoEvent::GetDescription(this: event);
    Scene_Printf(pFormat: "%s : %8.2f:  finish %s\n", eventa, currenttime, Description);
    switch ( CChoreoEvent::GetType(this: event) )
    {
      case EXPRESSION:
        if ( v7 != 0 && !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
          (*(void (__thiscall **)(char *, CChoreoScene *, int, CChoreoEvent *))(*((_DWORD *)this - 213) + 836))(
            a1: (char *)this - 852,
            a2: scene,
            a3: v7,
            a4: event);
        break;
      case LOOKAT:
        if ( v7 != 0 && !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
          (*(void (__thiscall **)(char *, CChoreoScene *, int, CChoreoEvent *))(*((_DWORD *)this - 213) + 860))(
            a1: (char *)this - 852,
            a2: scene,
            a3: v7,
            a4: event);
        break;
      case MOVETO:
        if ( v7 != 0 && !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
          (*(void (__thiscall **)(char *, CChoreoScene *, int, CChoreoEvent *))(*((_DWORD *)this - 213) + 868))(
            a1: (char *)this - 852,
            a2: scene,
            a3: v7,
            a4: event);
        break;
      case SPEAK:
        if ( v7 != 0 )
          (*(void (__thiscall **)(char *, CChoreoScene *, int, CChoreoEvent *))(*((_DWORD *)this - 213) + 876))(
            a1: (char *)this - 852,
            a2: scene,
            a3: v7,
            a4: event);
        break;
      case GESTURE:
        if ( v7 != 0 )
          (*(void (__thiscall **)(char *, CChoreoScene *, int, CChoreoEvent *))(*((_DWORD *)this - 213) + 852))(
            a1: (char *)this - 852,
            a2: scene,
            a3: v7,
            a4: event);
        break;
      case SEQUENCE:
        if ( v7 != 0 )
          (*(void (__thiscall **)(char *, CChoreoScene *, int, CChoreoEvent *))(*((_DWORD *)this - 213) + 892))(
            a1: (char *)this - 852,
            a2: scene,
            a3: v7,
            a4: event);
        break;
      case FACE:
        if ( v7 != 0 && !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
          (*(void (__thiscall **)(char *, CChoreoScene *, int, CChoreoEvent *))(*((_DWORD *)this - 213) + 884))(
            a1: (char *)this - 852,
            a2: scene,
            a3: v7,
            a4: event);
        break;
      case FLEXANIMATION:
        if ( v7 != 0 && !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
          (*(void (__thiscall **)(char *, CChoreoScene *, int, CChoreoEvent *))(*((_DWORD *)this - 213) + 844))(
            a1: (char *)this - 852,
            a2: scene,
            a3: v7,
            a4: event);
        break;
      case SUBSCENE:
        if ( !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
        {
          SubScene = (CChoreoScene *)CChoreoEvent::GetSubScene(this: (vgui::Panel *)event);
          if ( SubScene != nullptr )
            CChoreoScene::ResetSimulation(this: SubScene, forward: true, starttime: 0.0, endtime: 0.0);
        }
        break;
      case INTERRUPT:
        if ( !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
          (*(void (__thiscall **)(char *, CChoreoScene *, CChoreoEvent *))(*((_DWORD *)this - 213) + 904))(
            a1: (char *)this - 852,
            a2: scene,
            a3: event);
        break;
      case PERMIT_RESPONSES:
        if ( !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
          (*(void (__thiscall **)(char *, CChoreoScene *, int, CChoreoEvent *))(*((_DWORD *)this - 213) + 920))(
            a1: (char *)this - 852,
            a2: scene,
            a3: v7,
            a4: event);
        break;
      case GENERIC:
        if ( CChoreoEvent::GetParameters(this: event) == nullptr
          || (Parameters = CChoreoEvent::GetParameters(this: event),
              V_strncmp(s1: Parameters, s2: "debugtext", count: 9) != 0) )
        {
          if ( v7 != 0 )
            (*(void (__thiscall **)(char *, CChoreoScene *, int, CChoreoEvent *))(*((_DWORD *)this - 213) + 912))(
              a1: (char *)this - 852,
              a2: scene,
              a3: v7,
              a4: event);
        }
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FF6A0
// Name: void MissingSceneWarning(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MissingSceneWarning(const char *scenename)
{
  CUtlSymbol result; // [esp+2h] [ebp-2h] BYREF

  if ( (_S6_22 & 1) == 0 )
  {
    _S6_22 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &missing, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: MissingSceneWarning_::_2_::_dynamic_atexit_destructor_for__missing__);
  }
  if ( CUtlSymbolTable::Find(this: &missing, &result, pString: scenename)->m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(this: &missing, &result, pString: scenename);
    _Warning(a1: "Scene '%s' missing!\n", scenename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FF720
// Name: private: bool CSceneEntity::ShouldNetwork(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneEntity::ShouldNetwork(CSceneEntity *this)
{
  bool v2; // zf
  CChoreoScene *m_pScene; // ecx

  v2 = !this->m_bMultiplayer.m_Value;
  m_pScene = this->m_pScene;
  if ( v2 )
  {
    if ( m_pScene == nullptr )
      return false;
    if ( CChoreoScene::HasEventsOfType(this: m_pScene, type: FLEXANIMATION) )
      return true;
    return CChoreoScene::HasEventsOfType(this: this->m_pScene, type: EXPRESSION);
  }
  else
  {
    if ( m_pScene == nullptr )
      return false;
    if ( CChoreoScene::HasEventsOfType(this: m_pScene, type: FLEXANIMATION)
      || CChoreoScene::HasEventsOfType(this: this->m_pScene, type: EXPRESSION)
      || CChoreoScene::HasEventsOfType(this: this->m_pScene, type: GESTURE) )
    {
      return true;
    }
    return CChoreoScene::HasEventsOfType(this: this->m_pScene, type: SEQUENCE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FF790
// Name: public: class CBaseEntity __near * CSceneEntity::FindNamedTarget(struct string_t,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CSceneEntity::FindNamedTarget(CSceneEntity *this, string_t iszTarget, bool bBaseFlexOnly)
{
  const char *pszValue; // eax
  unsigned int m_Index; // ecx
  char *v7; // eax
  int v8; // eax
  const char *v9; // eax
  CBaseEntity *v10; // esi
  const char *v11; // eax
  CBaseEntity *EntityByName; // eax

  pszValue = iszTarget.pszValue;
  if ( iszTarget.pszValue == nullptr )
    pszValue = locale;
  if ( _V_stricmp(s1: pszValue, s2: "!activator") != 0 )
  {
    v7 = (char *)iszTarget.pszValue;
    if ( iszTarget.pszValue == nullptr )
      v7 = (char *)locale;
    strchr(string: (unsigned __int8 *)v7, chr: 0x2Au);
    if ( v8 != 0 )
    {
      v10 = nullptr;
      while ( 1 )
      {
        v11 = iszTarget.pszValue;
        if ( iszTarget.pszValue == nullptr )
          v11 = locale;
        EntityByName = CGlobalEntityList::FindEntityByName(
                         this: &gEntList,
                         pStartEntity: v10,
                         szName: v11,
                         pSearchingEntity: nullptr,
                         pActivator: nullptr,
                         pCaller: nullptr,
                         pFilter: nullptr);
        v10 = EntityByName;
        if ( EntityByName == nullptr )
          break;
        if ( !bBaseFlexOnly
          || __RTDynamicCast(
               inptr: EntityByName,
               VfDelta: 0,
               SrcType: &CBaseEntity `RTTI Type Descriptor',
               TargetType: &CBaseFlex `RTTI Type Descriptor',
               isReference: 0) != nullptr )
        {
          return v10;
        }
      }
      return nullptr;
    }
    else
    {
      v9 = iszTarget.pszValue;
      if ( iszTarget.pszValue == nullptr )
        v9 = locale;
      return CGlobalEntityList::FindEntityByName(
               this: &gEntList,
               pStartEntity: nullptr,
               szName: v9,
               pSearchingEntity: nullptr,
               pActivator: nullptr,
               pCaller: nullptr,
               pFilter: nullptr);
    }
  }
  else
  {
    m_Index = this->m_hActivator.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      return nullptr;
    else
      return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FF890
// Name: public: void CSceneFindMarkFilter::SetActor(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneFindMarkFilter::SetActor(CSceneFindMarkFilter *this, CBaseEntity *pActor)
{
  if ( pActor != nullptr )
    this->m_hActor.m_Index = pActor->GetRefEHandle(this: pActor)->m_Index;
  else
    this->m_hActor.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x101FF8C0
// Name: public: CSceneFindNearestMarkFilter::CSceneFindNearestMarkFilter(class CBaseEntity const __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
CSceneFindNearestMarkFilter *__userpurge CSceneFindNearestMarkFilter::CSceneFindNearestMarkFilter@<eax>(
        CSceneFindNearestMarkFilter *this@<ecx>,
        int a2@<ebp>,
        CBaseEntity *pActor,
        const Vector *vecPos2,
        unsigned int flMaxRadius)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  double v9; // xmm0_8
  float v11; // xmm0_4
  double v12; // xmm0_8
  _DWORD v13[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v13[0] = a2;
  v13[1] = retaddr;
  this->__vftable = (CSceneFindNearestMarkFilter_vtbl *)&CSceneFindNearestMarkFilter::`vftable';
  this->m_hActor.m_Index = -1;
  this->m_vecPos2 = *vecPos2;
  this->m_flMaxSegmentDistance = *(float *)&flMaxRadius;
  *(_QWORD *)&this->m_flNearestToTarget = flMaxRadius;
  *(_QWORD *)&this->m_flNearestToActor = flMaxRadius;
  if ( pActor != nullptr )
  {
    this->m_hActor.m_Index = pActor->GetRefEHandle(this: pActor)->m_Index;
    if ( (pActor->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pActor, a2: (int)v13);
    this->m_vecPos1 = pActor->m_vecAbsOrigin;
    v6 = this->m_vecPos1.y - this->m_vecPos2.y;
    v7 = this->m_vecPos1.z - this->m_vecPos2.z;
    v8 = this->m_vecPos1.x - this->m_vecPos2.x;
    if ( (float)(fsqrt((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8)) + 1.0) <= *(float *)&flMaxRadius )
      v9 = (float)(fsqrt((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8)) + 1.0);
    else
      v9 = *(float *)&flMaxRadius;
    v11 = v9;
    this->m_flMaxSegmentDistance = v11;
    if ( v11 <= 1.0 )
    {
      v12 = 56755.84086242099;
      if ( *(float *)&flMaxRadius < 56755.84086242099 )
        v12 = *(float *)&flMaxRadius;
      this->m_flMaxSegmentDistance = v12;
    }
    return this;
  }
  else
  {
    this->m_hActor.m_Index = -1;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FFA50
// Name: public: virtual class CBaseEntity __near * CSceneFindNearestMarkFilter::GetFilterResult(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CSceneFindNearestMarkFilter::GetFilterResult(CSceneFindNearestMarkFilter *this)
{
  CBaseEntity *result; // eax

  result = this->m_pNearestToTarget;
  if ( result == nullptr )
    return this->m_pNearestToActor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FFA60
// Name: public: struct HSCRIPT__ __near * CSceneEntity::ScriptFindNamedEntity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CSceneEntity::ScriptFindNamedEntity(CSceneEntity *this, const char *name)
{
  CBaseEntity *v2; // eax

  v2 = this->FindNamedEntity(this, a2: name, a3: 0, a4: 0, a5: 0);
  if ( v2 != nullptr )
    return CBaseEntity::GetScriptInstance(this: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FFA90
// Name: public: virtual class CBaseEntity __near * CSceneFindMarkFilter::GetFilterResult(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CSceneFindMarkFilter::GetFilterResult(CSceneFindMarkFilter *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hEntityFound.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101FFAC0
// Name: public: virtual class CBaseEntity __near * CSceneEntity::FindNamedEntityClosest(char const __near *,class CBaseEntity __near *,bool,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__userpurge CSceneEntity::FindNamedEntityClosest@<eax>(
        CSceneEntity *this@<ecx>,
        int a2@<edi>,
        const char *name,
        CBaseEntity *pActor,
        bool bBaseFlexOnly,
        bool bUseClear,
        const char *pszSecondary)
{
  const char *pszValue; // ebx
  unsigned int m_Index; // ecx
  CBasePlayer *result; // eax
  CBaseEntity *v11; // esi
  const Vector *AbsOrigin; // eax
  CSceneFindNearestMarkFilter *NearestMarkFilter; // esi
  CAI_BaseNPC *v14; // eax
  CSceneFindMarkFilter *v15; // esi
  CSceneFindMarkFilter *v16; // eax
  CAI_BaseNPC *v17; // eax
  CBaseEntity *EntityByName; // esi
  int savedregs; // [esp+24h] [ebp+0h] BYREF
  CSceneFindNearestMarkFilter *namea; // [esp+2Ch] [ebp+8h]
  int iCount; // [esp+38h] [ebp+14h]

  pszValue = name;
  if ( _V_stricmp(s1: name, s2: "!activator") == 0 )
  {
    m_Index = this->m_hActivator.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      return (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    return nullptr;
  }
  if ( _V_stricmp(s1: name, s2: "Player") == 0 || _V_stricmp(s1: name, s2: "!player") == 0 )
  {
    if ( gpGlobals->maxClients == 1 )
      return UTIL_GetLocalPlayer();
    return nullptr;
  }
  if ( _V_stricmp(s1: name, s2: "!target1") == 0 )
  {
    pszValue = this->m_iszTarget1.pszValue;
    goto LABEL_21;
  }
  if ( _V_stricmp(s1: name, s2: "!target2") == 0 )
  {
    pszValue = this->m_iszTarget2.pszValue;
    goto LABEL_21;
  }
  if ( _V_stricmp(s1: name, s2: "!target3") == 0 )
  {
    pszValue = this->m_iszTarget3.pszValue;
    goto LABEL_21;
  }
  if ( _V_stricmp(s1: name, s2: "!target4") == 0 )
  {
    pszValue = this->m_iszTarget4.pszValue;
    goto LABEL_21;
  }
  if ( _V_stricmp(s1: name, s2: "!target5") == 0 )
  {
    pszValue = this->m_iszTarget5.pszValue;
    goto LABEL_21;
  }
  if ( _V_stricmp(s1: name, s2: "!target6") == 0 )
  {
    pszValue = this->m_iszTarget6.pszValue;
    goto LABEL_21;
  }
  if ( _V_stricmp(s1: name, s2: "!target7") == 0 )
  {
    pszValue = this->m_iszTarget7.pszValue;
LABEL_21:
    if ( pszValue == nullptr )
      pszValue = locale;
  }
  if ( pActor != nullptr && ((int (__thiscall *)(CBaseEntity *, int))pActor->MyNPCPointer)(a1: pActor, a2) != 0 )
  {
    if ( pszSecondary == nullptr
      || strlen(pszSecondary) == 0
      || (v11 = this->FindNamedEntityClosest(this, a2: pszSecondary, a3: pActor, a4: 0, a5: 0, a6: 0)) == nullptr
      || ((namea = (CSceneFindNearestMarkFilter *)operator new(nSize: 0x34u)) == nullptr
        ? (NearestMarkFilter = nullptr)
        : (AbsOrigin = CBaseEntity::GetAbsOrigin(this: v11),
           NearestMarkFilter = CSceneFindNearestMarkFilter::CSceneFindNearestMarkFilter(
                                 this: namea,
                                 a2: (int)&savedregs,
                                 pActor,
                                 vecPos2: AbsOrigin,
                                 flMaxRadius: 0x475DB3D7u)),
          (v14 = pActor->MyNPCPointer(this: pActor),
           (result = (CBasePlayer *)v14->FindNamedEntity(this: v14, a2: pszValue, a3: NearestMarkFilter)) == nullptr)
       && (NearestMarkFilter == nullptr
        || (result = (CBasePlayer *)NearestMarkFilter->GetFilterResult(this: NearestMarkFilter)) == nullptr)) )
    {
      v15 = nullptr;
      if ( bUseClear )
      {
        v16 = (CSceneFindMarkFilter *)operator new(nSize: 0xCu);
        if ( v16 != nullptr )
        {
          v16->__vftable = (CSceneFindMarkFilter_vtbl *)&CSceneFindMarkFilter::`vftable';
          v16->m_hActor.m_Index = -1;
          v16->m_hEntityFound.m_Index = -1;
          v15 = v16;
        }
        else
        {
          v15 = nullptr;
        }
        CSceneFindMarkFilter::SetActor(this: v15, pActor);
      }
      v17 = pActor->MyNPCPointer(this: pActor);
      result = (CBasePlayer *)v17->FindNamedEntity(this: v17, a2: pszValue, a3: v15);
      if ( result == nullptr && v15 != nullptr )
        return (CBasePlayer *)v15->GetFilterResult(this: v15);
    }
  }
  else
  {
    EntityByName = nullptr;
    for ( iCount = 0; iCount < 32; ++iCount )
    {
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: EntityByName,
                       szName: pszValue,
                       pSearchingEntity: nullptr,
                       pActivator: pActor,
                       pCaller: nullptr,
                       pFilter: nullptr);
      if ( EntityByName != nullptr )
        _RandomInt(this: (IUniformRandomStream *)iCount, a2: 0, a3: iCount);
    }
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FFDA0
// Name: public: virtual int CSceneEntity::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSceneEntity::UpdateTransmitState(CSceneEntity *this)
{
  if ( !CSceneEntity::ShouldNetwork(this) )
    return CBaseEntity::SetTransmitState(this, nFlag: 16);
  if ( this->m_pRecipientFilter != nullptr )
    return CBaseEntity::SetTransmitState(this, nFlag: 0);
  return CBaseEntity::SetTransmitState(this, nFlag: 8);
}

//------------------------------------------------------------------------------
// Address: 0x101FFDE0
// Name: public: virtual int CSceneEntity::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSceneEntity::DrawDebugTextOverlays(CSceneEntity *this)
{
  int result; // eax
  int v3; // edi
  const char *v4; // eax
  int v5; // edi
  const char *v6; // eax
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    v4 = "yes";
    if ( !this->m_bIsPlayingBack.m_Value )
      v4 = "no";
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Playing back: %s", v4);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v5 = v3 + 1;
    if ( this->m_bPaused.m_Value )
    {
      if ( this->m_bPausedViaInput )
        v6 = "yes - via input";
      else
        v6 = "yes";
    }
    else
    {
      v6 = "no";
    }
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Paused: %s", v6);
    CBaseEntity::EntityText(this, text_offset: v5, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v5 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FFED0
// Name: void StopScriptedScene(class CBaseFlex __near *,class CHandle<class CBaseEntity>)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StopScriptedScene(CBaseFlex *pActor, CHandle<CBaseEntity> hSceneEnt)
{
  IHandleEntity *m_pEntity; // eax
  const char **v3; // eax
  const char **v4; // esi
  const char *v5; // eax

  if ( hSceneEnt.m_Index == -1
    || g_pEntityList->m_EntPtrArray[LOWORD(hSceneEnt.m_Index)].m_SerialNumber != HIWORD(hSceneEnt.m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[LOWORD(hSceneEnt.m_Index)].m_pEntity;
  }
  v3 = (const char **)__RTDynamicCast(
                        inptr: m_pEntity,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CSceneEntity `RTTI Type Descriptor',
                        isReference: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v5 = v3[214];
    if ( v5 == nullptr )
      v5 = locale;
    Scene_Printf(pFormat: "%s : stop scripted scene\n", v5);
    (*((void (__thiscall **)(const char **))*v4 + 205))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FFF50
// Name: struct HSCRIPT__ __near * ScriptCreateSceneEntity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__usercall ScriptCreateSceneEntity@<eax>(int a1@<esi>)
{
  CBaseEntity *NoSpawn; // esi
  char pszValue[4]; // [esp+0h] [ebp-4h] BYREF

  if ( IsEntityCreationAllowedInScripts() )
  {
    ((void (__thiscall *)(IScriptVM *, ScriptClassDesc_t *, int))g_pScriptVM->RegisterClass)(
      a1: g_pScriptVM,
      a2: &g_CSceneEntity_ScriptDesc,
      a3: a1);
    NoSpawn = CBaseEntity::CreateNoSpawn(
                szName: "logic_choreographed_scene",
                vecOrigin: &vec3_origin,
                vecAngles: &vec3_angle,
                pOwner: nullptr);
    if ( NoSpawn != nullptr )
    {
      NoSpawn[1].m_pfnMoveDone = *(void (__thiscall **)(CBaseEntity *))AllocPooledString(pszValue).pszValue;
      DispatchSpawn(pEntity: NoSpawn, bRunVScripts: true);
      return CBaseEntity::GetScriptInstance(this: NoSpawn);
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    _Warning(
      a1: "VScript error: A script attempted to create a scene entity mid-game. Entity creation from scripts is only allowed "
      "during map init.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FFFE0
// Name: public: virtual float CInstancedSceneEntity::EstimateLength(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall CInstancedSceneEntity::EstimateLength@<st0>(CInstancedSceneEntity *this@<ecx>, int a2@<edi>)
{
  float v4; // [esp+4h] [ebp-4h]

  v4 = this->GetPreDelay(this);
  return CSceneEntity::EstimateLength(this, a2, a3: (int)this) + v4;
}

//------------------------------------------------------------------------------
// Address: 0x10200010
// Name: public: void CSceneListManager::ShutdownList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneListManager::ShutdownList(CSceneListManager *this)
{
  int v2; // esi
  CHandle<CBaseEntity> *m_hScenes; // edi
  unsigned int m_Index; // eax

  v2 = 0;
  m_hScenes = this->m_hScenes;
  do
  {
    m_Index = m_hScenes->m_Index;
    if ( m_hScenes->m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      CSceneListManager::RemoveScene(this, iIndex: v2);
    }
    ++v2;
    ++m_hScenes;
  }
  while ( v2 < 16 );
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x10200070
// Name: public: void CSceneListManager::RemoveScene(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneListManager::RemoveScene(CSceneListManager *this, int iIndex)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v5; // eax
  unsigned int v6; // eax
  IHandleEntity *v7; // ecx
  CSceneListManager *v8; // eax

  m_Index = this->m_hScenes[iIndex].m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v5 = (CBaseEntity *)__RTDynamicCast(
                        inptr: m_pEntity,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CSceneEntity `RTTI Type Descriptor',
                        isReference: 0);
  if ( v5 != nullptr )
  {
    UTIL_Remove(oldObj: v5);
  }
  else
  {
    v6 = this->m_hScenes[iIndex].m_Index;
    if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      v7 = nullptr;
    else
      v7 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    v8 = (CSceneListManager *)__RTDynamicCast(
                                inptr: v7,
                                VfDelta: 0,
                                SrcType: &CBaseEntity `RTTI Type Descriptor',
                                TargetType: &CSceneListManager `RTTI Type Descriptor',
                                isReference: 0);
    if ( v8 != nullptr )
      CSceneListManager::ShutdownList(this: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200240
// Name: public: static bool CMemberScriptBinding0<class CSceneEntity __near *,float (CSceneEntity::*)(void),float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding0<CSceneEntity *,float (__thiscall CSceneEntity::*)(void),float>::Call(
        double (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext == nullptr )
    return 0;
  pReturn->m_float = pFunction();
  pReturn->m_type = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10200270
// Name: public: static bool CMemberScriptBinding2<class CSceneEntity __near *,bool (CSceneEntity::*)(char const __near *,char const __near *),bool,char const __near *,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding2<CSceneEntity *,bool (__thiscall CSceneEntity::*)(char const *,char const *),bool,char const *,char const *>::Call(
        int (__stdcall *pFunction)(const char *, const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_pszString; // eax
  const char *m_int; // edx

  if ( nArguments != 2 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_pszString = pArguments[1].m_pszString;
  if ( m_pszString == nullptr )
    m_pszString = locale;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pReturn->m_char = pFunction(a1: m_int, a2: m_pszString);
  pReturn->m_type = 6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102002C0
// Name: public: void CUtlMemory<struct CSceneManager::CRestoreSceneSound,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSceneManager::CRestoreSceneSound,int>::Grow(
        CUtlMemory<CSceneManager::CRestoreSceneSound,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CSceneManager::CRestoreSceneSound *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 140 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CSceneManager::CRestoreSceneSound *)_g_pMemAlloc->Realloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: m_pMemory,
                                                               a3: v7);
    else
      this->m_pMemory = (CSceneManager::CRestoreSceneSound *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200460
// Name: class CSceneManager __near * GetSceneManager(void)
// Source: json
//------------------------------------------------------------------------------
CSceneManager *__cdecl GetSceneManager()
{
  unsigned int m_Index; // eax
  CBaseEntityList *v1; // esi
  CBaseEntity *EntityByName; // eax
  IHandleEntity *m_pEntity; // ecx

  if ( (_S3_110 & 1) != 0 )
  {
    m_Index = s_SceneManager.m_Index;
    if ( s_SceneManager.m_Index != -1 )
    {
      v1 = g_pEntityList;
      if ( g_pEntityList->m_EntPtrArray[LOWORD(s_SceneManager.m_Index)].m_SerialNumber == HIWORD(s_SceneManager.m_Index)
        && g_pEntityList->m_EntPtrArray[LOWORD(s_SceneManager.m_Index)].m_pEntity != nullptr )
      {
        goto LABEL_16;
      }
    }
  }
  else
  {
    _S3_110 |= 1u;
    s_SceneManager.m_Index = -1;
  }
  EntityByName = CreateEntityByName(className: "scene_manager", iForceEdictIndex: -1, bNotify: true);
  if ( EntityByName == nullptr )
  {
    s_SceneManager.m_Index = -1;
    return nullptr;
  }
  m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  s_SceneManager.m_Index = m_Index;
  if ( m_Index == -1 )
    return nullptr;
  v1 = g_pEntityList;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    else
      m_pEntity = nullptr;
    m_pEntity->__vftable[8].dtr_IHandleEntity(this: m_pEntity);
    m_Index = s_SceneManager.m_Index;
    v1 = g_pEntityList;
  }
LABEL_16:
  if ( m_Index == -1 || v1->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  return (CSceneManager *)v1->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10200560
// Name: public: virtual void CSceneEntity::PauseThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::PauseThink(CSceneEntity *this)
{
  CChoreoScene *m_pScene; // edi
  const char *pszValue; // eax
  float m_flAutomationDelay; // xmm1_4
  float v5; // xmm0_4
  const char *v6; // eax
  const char *v7; // eax

  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr && !this->m_bInterrupted )
  {
    if ( this->m_bPausedViaInput )
    {
      if ( !this->m_bWaitingForResumeScene
        || !CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&this->m_hWaitingForThisResumeScene) )
      {
        return;
      }
      this->m_bWaitingForResumeScene = false;
    }
    if ( !this->m_bAutomated )
    {
      if ( !CChoreoScene::CheckEventCompletion(this: m_pScene) )
        return;
      if ( this->m_nAutomatedAction == 1 )
      {
        pszValue = this->m_iszSceneFile.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        Scene_Printf(pFormat: "%s : PauseThink canceling playback\n", pszValue);
        this->CancelPlayback(this);
      }
      else
      {
        this->ResumePlayback(this);
      }
      goto LABEL_27;
    }
    m_flAutomationDelay = this->m_flAutomationDelay;
    v5 = gpGlobals->frametime + this->m_flAutomationTime;
    this->m_flAutomationTime = v5;
    if ( m_flAutomationDelay <= 0.0 || m_flAutomationDelay <= v5 )
    {
      if ( this->m_nAutomatedAction == 1 )
      {
        v7 = this->m_iszSceneFile.pszValue;
        if ( v7 == nullptr )
          v7 = locale;
        Scene_Printf(pFormat: "%s : Automatically canceling playback\n", v7);
        this->CancelPlayback(this);
      }
      else
      {
        v6 = this->m_iszSceneFile.pszValue;
        if ( this->m_nAutomatedAction == 2 )
        {
          if ( v6 == nullptr )
            v6 = locale;
          Scene_Printf(pFormat: "%s : Automatically resuming playback\n", v6);
          this->ResumePlayback(this);
        }
        else
        {
          if ( v6 == nullptr )
            v6 = locale;
          Scene_Printf(
            pFormat: "%s : Unknown action %i, automatically resuming playback\n",
            v6,
            this->m_nAutomatedAction);
          this->ResumePlayback(this);
        }
      }
LABEL_27:
      this->m_bPausedViaInput = false;
      this->m_flAutomationDelay = 0.0;
      this->m_flAutomationTime = 0.0;
      this->m_nAutomatedAction = 0;
      this->m_bAutomated = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102006F0
// Name: bool AttenuateCaption(char const __near *,class Vector const __near &,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AttenuateCaption(
        const char *token,
        const Vector *listener,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *soundorigins)
{
  int m_Size; // edx
  int v5; // eax
  Vector *i; // ecx

  if ( scene_maxcaptionradius.m_pParent->m_Value.m_fValue <= 0.0 )
    return 0;
  m_Size = soundorigins->m_Size;
  if ( m_Size > 0 )
  {
    v5 = 0;
    for ( i = soundorigins->m_Memory.m_pMemory;
          (float)(scene_maxcaptionradius.m_pParent->m_Value.m_fValue * scene_maxcaptionradius.m_pParent->m_Value.m_fValue) < (float)((float)((float)((float)(i->x - listener->x) * (float)(i->x - listener->x)) + (float)((float)(i->y - listener->y) * (float)(i->y - listener->y))) + (float)((float)(i->z - listener->z) * (float)(i->z - listener->z)));
          ++i )
    {
      if ( ++v5 >= m_Size )
        return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10200780
// Name: public: virtual void CSceneEntity::StartEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::StartEvent(
        CSceneEntity *this,
        float currenttime,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  const char *Name; // eax
  const char *m_pfnMoveDone; // esi
  const char *v8; // eax
  CBaseEntity *v9; // ebx
  const char *v10; // esi
  const char *v11; // eax
  const char *Description; // eax
  const char *v13; // eax
  int v14; // eax
  const char *Parameters2; // eax
  const char *v16; // eax
  int v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  int v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *Parameters3; // eax
  CBaseEntity *v25; // ebx
  CTriggerCamera *EntityByClassname; // eax
  const char *v27; // esi
  const char *v28; // ebx
  CBaseEntity *EntityByName; // eax
  CScriptScopeT<CDefScriptScopeBase> *v30; // edi
  CScriptScopeT<CDefScriptScopeBase> *v31; // ebx
  HSCRIPT__ *v32; // edi
  CBaseEntity *v33; // esi
  HSCRIPT__ *ScriptInstance; // eax
  const char *v35; // eax
  int v36; // ebx
  const char *Parameters; // eax
  int v38; // ebx
  const char *v39; // eax
  float endtime_4; // [esp+20h] [ebp-3Ch]
  const char *endtime_4a; // [esp+20h] [ebp-3Ch]
  hudtextparms_s tTextParam; // [esp+30h] [ebp-2Ch] BYREF
  const char *pszActorName; // [esp+58h] [ebp-4h]
  soundlevel_t iSoundlevel; // [esp+64h] [ebp+8h]
  char *iSoundlevela; // [esp+64h] [ebp+8h]
  float iSoundlevelb; // [esp+64h] [ebp+8h]
  const char *pszFunctionNameb; // [esp+68h] [ebp+Ch]
  const char *pszFunctionNamec; // [esp+68h] [ebp+Ch]
  float pszFunctionName; // [esp+68h] [ebp+Ch]
  const char *pszFunctionNamea; // [esp+68h] [ebp+Ch]
  CChoreoActor *pszScriptParameters; // [esp+6Ch] [ebp+10h]
  const char *pszScriptParametersa; // [esp+6Ch] [ebp+10h]
  const char *pszScriptParametersd; // [esp+6Ch] [ebp+10h]
  const char *pszScriptParameterse; // [esp+6Ch] [ebp+10h]
  const char *pszScriptParametersf; // [esp+6Ch] [ebp+10h]
  const char *pszScriptParametersg; // [esp+6Ch] [ebp+10h]
  CBaseEntity *pszScriptParametersb; // [esp+6Ch] [ebp+10h]
  const char *pszScriptParametersc; // [esp+6Ch] [ebp+10h]

  Name = CChoreoEvent::GetName(this: event);
  if ( _V_stricmp(s1: Name, s2: "NULL") != 0 )
  {
    v9 = nullptr;
    pszScriptParameters = CChoreoEvent::GetActor(this: event);
    if ( pszScriptParameters == nullptr
      || CChoreoEvent::GetType(this: event) == SCRIPT
      || CChoreoEvent::GetType(this: event) == CAMERA
      || (v9 = (CBaseEntity *)(*(int (__thiscall **)(char *, CChoreoActor *))(*((_DWORD *)this - 213) + 948))(
                                a1: (char *)this - 852,
                                a2: pszScriptParameters)) != nullptr )
    {
      pszScriptParametersa = (const char *)this->m_pfnMoveDone;
      if ( pszScriptParametersa == nullptr )
        pszScriptParametersa = locale;
      Description = CChoreoEvent::GetDescription(this: event);
      Scene_Printf(pFormat: "%s : %8.2f:  start %s\n", pszScriptParametersa, currenttime, Description);
      switch ( CChoreoEvent::GetType(this: event) )
      {
        case SECTION:
          if ( !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
          {
            v36 = *((_DWORD *)this - 213);
            Parameters = CChoreoEvent::GetParameters(this: event);
            (*(void (__thiscall **)(char *, CChoreoScene *, const char *))(v36 + 928))(
              a1: (char *)this - 852,
              a2: scene,
              a3: Parameters);
          }
          break;
        case EXPRESSION:
          if ( v9 != nullptr && !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
            (*(void (__thiscall **)(char *, CChoreoScene *, CBaseEntity *, CChoreoEvent *))(*((_DWORD *)this - 213) + 832))(
              a1: (char *)this - 852,
              a2: scene,
              a3: v9,
              a4: event);
          break;
        case LOOKAT:
          if ( v9 != nullptr && !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
          {
            pszScriptParametersd = *((const char **)this - 213);
            v13 = CChoreoEvent::GetParameters(this: event);
            v14 = (*((int (__thiscall **)(char *, const char *, CBaseEntity *, _DWORD, _DWORD))pszScriptParametersd + 239))(
                    a1: (char *)this - 852,
                    a2: v13,
                    a3: v9,
                    a4: 0,
                    a5: 0);
            if ( v14 == 0 )
              goto LABEL_46;
            (*(void (__thiscall **)(char *, CChoreoScene *, CBaseEntity *, int, CChoreoEvent *))(*((_DWORD *)this - 213)
                                                                                               + 856))(
              a1: (char *)this - 852,
              a2: scene,
              a3: v9,
              a4: v14,
              a5: event);
          }
          break;
        case MOVETO:
          if ( !CChoreoEvent::CurveHasEndTime(this: event) )
          {
            endtime_4 = CChoreoEvent::GetStartTime(this: event) + 1.0;
            CChoreoEvent::SetEndTime(this: event, endtime: endtime_4);
          }
          if ( v9 != nullptr && !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
          {
            if ( CChoreoEvent::GetParameters3(this: event) != nullptr
              && strlen(CChoreoEvent::GetParameters3(this: event)) != 0 )
            {
              pszScriptParameterse = *((const char **)this - 213);
              iSoundlevela = (char *)this - 852;
              endtime_4a = CChoreoEvent::GetParameters3(this: event);
              v16 = CChoreoEvent::GetParameters(this: event);
              v17 = (*((int (__thiscall **)(char *, const char *, CBaseEntity *, _DWORD, int, const char *))pszScriptParameterse
                     + 240))(
                      a1: (char *)this - 852,
                      a2: v16,
                      a3: v9,
                      a4: 0,
                      a5: 1,
                      a6: endtime_4a);
            }
            else
            {
              pszScriptParametersf = *((const char **)this - 213);
              iSoundlevela = (char *)this - 852;
              v18 = CChoreoEvent::GetParameters(this: event);
              v17 = (*((int (__thiscall **)(char *, const char *, CBaseEntity *, _DWORD, int))pszScriptParametersf + 239))(
                      a1: (char *)this - 852,
                      a2: v18,
                      a3: v9,
                      a4: 0,
                      a5: 1);
            }
            if ( v17 == 0 )
              goto LABEL_46;
            (*(void (__thiscall **)(char *, CChoreoScene *, CBaseEntity *, int, CChoreoEvent *))(*(_DWORD *)iSoundlevela
                                                                                               + 864))(
              a1: iSoundlevela,
              a2: scene,
              a3: v9,
              a4: v17,
              a5: event);
          }
          break;
        case SPEAK:
          if ( v9 != nullptr )
          {
            iSoundlevel = SNDLVL_80dB;
            if ( CChoreoEvent::GetParameters2(this: event) != nullptr )
            {
              Parameters2 = CChoreoEvent::GetParameters2(this: event);
              iSoundlevel = atoi(nptr: Parameters2);
            }
            (*(void (__thiscall **)(char *, CChoreoScene *, CBaseEntity *, CChoreoEvent *, soundlevel_t))(*((_DWORD *)this - 213) + 872))(
              a1: (char *)this - 852,
              a2: scene,
              a3: v9,
              a4: event,
              a5: iSoundlevel);
          }
          break;
        case GESTURE:
          if ( v9 != nullptr )
            (*(void (__thiscall **)(char *, CChoreoScene *, CBaseEntity *, CChoreoEvent *))(*((_DWORD *)this - 213) + 848))(
              a1: (char *)this - 852,
              a2: scene,
              a3: v9,
              a4: event);
          break;
        case SEQUENCE:
          if ( v9 != nullptr )
            (*(void (__thiscall **)(char *, CChoreoScene *, CBaseEntity *, CChoreoEvent *))(*((_DWORD *)this - 213) + 888))(
              a1: (char *)this - 852,
              a2: scene,
              a3: v9,
              a4: event);
          break;
        case FACE:
          if ( v9 != nullptr && !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
          {
            pszScriptParametersg = *((const char **)this - 213);
            v19 = CChoreoEvent::GetParameters(this: event);
            v20 = (*((int (__thiscall **)(char *, const char *, CBaseEntity *, _DWORD, _DWORD))pszScriptParametersg + 239))(
                    a1: (char *)this - 852,
                    a2: v19,
                    a3: v9,
                    a4: 0,
                    a5: 0);
            if ( v20 == 0 )
            {
LABEL_46:
              v10 = *((const char **)this - 162);
              if ( v10 == nullptr )
                v10 = locale;
              v11 = CChoreoEvent::GetParameters(this: event);
              goto LABEL_49;
            }
            (*(void (__thiscall **)(char *, CChoreoScene *, CBaseEntity *, int, CChoreoEvent *))(*((_DWORD *)this - 213)
                                                                                               + 880))(
              a1: (char *)this - 852,
              a2: scene,
              a3: v9,
              a4: v20,
              a5: event);
          }
          break;
        case FIRETRIGGER:
          if ( LOBYTE(this->m_cellZ.m_Value) == 0 )
          {
            if ( v9 == nullptr )
              v9 = (CSceneEntity *)((char *)this - 852);
            v35 = CChoreoEvent::GetParameters(this: event);
            switch ( atoi(nptr: v35) )
            {
              case 1:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_Collision.m_vecMaxs,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 2:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_Collision.m_vecSpecifiedSurroundingMins,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 3:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_Collision.m_vecSurroundingMins,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 4:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_hOwnerEntity,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 5:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_hGroundEntity,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 6:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_vecAbsVelocity.y,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 7:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_rgflCoordinateFrame.m_flMatVal[0][1],
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 8:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_rgflCoordinateFrame.m_flMatVal[1][3],
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 9:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_flElasticity,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 10:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_vecAbsOrigin.y,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 11:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_vecVelocity.m_Value.y,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 12:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_iParent,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 13:
                COutputEvent::FireOutput(
                  this: (COutputEvent *)&this->m_hDamageFilter,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 14:
                COutputEvent::FireOutput(
                  this: &this->m_OnUser1,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 15:
                COutputEvent::FireOutput(
                  this: &this->m_OnUser2,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              case 16:
                COutputEvent::FireOutput(
                  this: &this->m_OnUser3,
                  pActivator: v9,
                  pCaller: (CSceneEntity *)((char *)this - 852),
                  fDelay: 0.0);
                break;
              default:
                return;
            }
          }
          break;
        case FLEXANIMATION:
          if ( v9 != nullptr && !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
            (*(void (__thiscall **)(char *, CChoreoScene *, CBaseEntity *, CChoreoEvent *))(*((_DWORD *)this - 213) + 840))(
              a1: (char *)this - 852,
              a2: scene,
              a3: v9,
              a4: event);
          break;
        case SUBSCENE:
          if ( v9 != nullptr && !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
            (*(void (__thiscall **)(char *, CChoreoScene *, CBaseEntity *, CChoreoEvent *))(*((_DWORD *)this - 213) + 896))(
              a1: (char *)this - 852,
              a2: scene,
              a3: v9,
              a4: event);
          break;
        case LOOP:
          (*(void (__thiscall **)(char *, CChoreoScene *, CChoreoEvent *))(*((_DWORD *)this - 213) + 924))(
            a1: (char *)this - 852,
            a2: scene,
            a3: event);
          break;
        case INTERRUPT:
          if ( !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
            (*(void (__thiscall **)(char *, CChoreoScene *, CChoreoEvent *))(*((_DWORD *)this - 213) + 900))(
              a1: (char *)this - 852,
              a2: scene,
              a3: event);
          break;
        case STOPPOINT:
          if ( !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
          {
            v38 = *((_DWORD *)this - 213);
            v39 = CChoreoEvent::GetParameters(this: event);
            (*(void (__thiscall **)(char *, CChoreoScene *, const char *))(v38 + 932))(
              a1: (char *)this - 852,
              a2: scene,
              a3: v39);
          }
          break;
        case PERMIT_RESPONSES:
          if ( !*(&this->m_Network.m_TimerEvent.m_bRegistered + 2) )
            (*(void (__thiscall **)(char *, CChoreoScene *, CBaseEntity *, CChoreoEvent *))(*((_DWORD *)this - 213) + 916))(
              a1: (char *)this - 852,
              a2: scene,
              a3: v9,
              a4: event);
          break;
        case GENERIC:
          if ( CChoreoEvent::GetParameters(this: event) == nullptr
            || (v21 = CChoreoEvent::GetParameters(this: event), V_strncmp(s1: v21, s2: "debugtext", count: 9) != 0) )
          {
            if ( v9 != nullptr )
              (*(void (__thiscall **)(char *, CChoreoScene *, CBaseEntity *, CChoreoEvent *))(*((_DWORD *)this - 213)
                                                                                            + 908))(
                a1: (char *)this - 852,
                a2: scene,
                a3: v9,
                a4: event);
          }
          else
          {
            v22 = CChoreoEvent::GetParameters(this: event);
            tTextParam.x = -1.0;
            tTextParam.y = 0.64999998;
            tTextParam.effect = 0;
            *(_DWORD *)&tTextParam.r1 = -16733441;
            *(_DWORD *)&tTextParam.r2 = -16733441;
            tTextParam.fadeinTime = 0.0;
            tTextParam.fadeoutTime = 0.0;
            tTextParam.holdTime = 3.0999999;
            tTextParam.fxTime = 0.0;
            tTextParam.channel = 1;
            UTIL_HudMessageAll(textparms: &tTextParam, pMessage: v22 + 10);
          }
          break;
        case CAMERA:
          pszActorName = CChoreoEvent::GetParameters(this: event);
          pszFunctionNameb = *((const char **)this - 213);
          v23 = CChoreoEvent::GetParameters2(this: event);
          pszScriptParametersb = (CBaseEntity *)(*((int (__thiscall **)(char *, const char *, CBaseEntity *, _DWORD, _DWORD))pszFunctionNameb
                                                 + 239))(
                                                  a1: (char *)this - 852,
                                                  a2: v23,
                                                  a3: v9,
                                                  a4: 0,
                                                  a5: 0);
          pszFunctionNamec = *((const char **)this - 213);
          Parameters3 = CChoreoEvent::GetParameters3(this: event);
          v25 = (CBaseEntity *)(*((int (__thiscall **)(char *, const char *, CBaseEntity *, _DWORD, _DWORD))pszFunctionNamec
                                + 239))(
                                 a1: (char *)this - 852,
                                 a2: Parameters3,
                                 a3: v9,
                                 a4: 0,
                                 a5: 0);
          pszFunctionName = event->GetDuration(this: event);
          EntityByClassname = (CTriggerCamera *)CGlobalEntityList::FindEntityByClassname(
                                                  this: &gEntList,
                                                  pStartEntity: nullptr,
                                                  szName: "point_viewcontrol");
          if ( EntityByClassname != nullptr )
          {
            CTriggerCamera::StartCameraShot(
              this: EntityByClassname,
              pszShotType: pszActorName,
              pSceneEntity: (CSceneEntity *)((char *)this - 852),
              pActor1: pszScriptParametersb,
              pActor2: v25,
              duration: pszFunctionName);
          }
          else
          {
            v27 = *((const char **)this - 162);
            if ( v27 == nullptr )
              v27 = locale;
            _Warning(a1: "CSceneEntity %s unable to find a camera (point_viewcontrol) in this map!\n", v27);
          }
          break;
        case SCRIPT:
          v28 = CChoreoEvent::GetParameters(this: event);
          pszActorName = v28;
          pszFunctionNamea = CChoreoEvent::GetParameters2(this: event);
          pszScriptParametersc = CChoreoEvent::GetParameters3(this: event);
          iSoundlevelb = event->GetDuration(this: event);
          EntityByName = CGlobalEntityList::FindEntityByName(
                           this: &gEntList,
                           pStartEntity: nullptr,
                           szName: v28,
                           pSearchingEntity: nullptr,
                           pActivator: nullptr,
                           pCaller: nullptr,
                           pFilter: nullptr);
          v30 = (CScriptScopeT<CDefScriptScopeBase> *)EntityByName;
          if ( EntityByName != nullptr )
          {
            if ( CBaseEntity::ValidateScriptScope(this: EntityByName) != 0 )
            {
              v31 = v30 + 41;
              v32 = CScriptScopeT<CDefScriptScopeBase>::LookupFunction(this: v30 + 41, pszFunction: pszFunctionNamea);
              if ( v32 != nullptr )
              {
                v33 = (CSceneEntity *)((char *)this - 852);
                if ( v33 != nullptr )
                  ScriptInstance = CBaseEntity::GetScriptInstance(this: v33);
                else
                  ScriptInstance = nullptr;
                CScriptScopeT<CDefScriptScopeBase>::Call<HSCRIPT__ *,char const *,float>(
                  this: v31,
                  hFunction: v32,
                  pReturn: nullptr,
                  arg1: ScriptInstance,
                  arg2: pszScriptParametersc,
                  arg3: iSoundlevelb);
                g_pScriptVM->ReleaseFunction(this: g_pScriptVM, a2: v32);
              }
              else
              {
                _Warning(
                  a1: "CSceneEntity::SCRIPT event - '%s' entity has no script function '%s' defined!\n",
                  pszActorName,
                  pszFunctionNamea);
              }
            }
            else
            {
              DevMsg(a1: "\n***\nCChoreoEvent::SCRIPT - FAILED to create private ScriptScope. ABORTING script call\n***\n");
            }
          }
          else
          {
            _Warning(a1: "CSceneEntity::SCRIPT event - unable to find entity named '%s' in this map!\n", v28);
          }
          break;
        default:
          return;
      }
    }
    else
    {
      v10 = *((const char **)this - 162);
      if ( v10 == nullptr )
        v10 = locale;
      v11 = (const char *)CBasePlayer::ActivePlayerCombatCharacter(this: (vgui::Panel *)pszScriptParameters);
LABEL_49:
      _Warning(a1: "CSceneEntity %s unable to find actor named \"%s\"\n", v10, v11);
    }
  }
  else
  {
    m_pfnMoveDone = (const char *)this->m_pfnMoveDone;
    if ( m_pfnMoveDone == nullptr )
      m_pfnMoveDone = locale;
    v8 = CChoreoEvent::GetDescription(this: event);
    Scene_Printf(pFormat: "%s : %8.2f:  ignored %s\n", m_pfnMoveDone, currenttime, v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10201220
// Name: public: virtual bool CSceneEntity::CheckEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneEntity::CheckEvent(
        CSceneEntity *this,
        float currenttime,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  vgui::Panel *Actor; // esi
  CBaseFlex *v6; // eax
  const char *v7; // edi
  const char *v8; // eax

  if ( CChoreoEvent::GetType(this: event) == SUBSCENE )
    return true;
  Actor = (vgui::Panel *)CChoreoEvent::GetActor(this: event);
  if ( Actor == nullptr )
    return true;
  v6 = (CBaseFlex *)(*(int (__thiscall **)(char *, vgui::Panel *))(*((_DWORD *)this - 213) + 948))(
                      a1: (char *)this - 852,
                      a2: Actor);
  if ( v6 == nullptr )
  {
    v7 = *((const char **)this - 162);
    if ( v7 == nullptr )
      v7 = locale;
    v8 = (const char *)CBasePlayer::ActivePlayerCombatCharacter(this: Actor);
    _Warning(a1: "CSceneEntity %s unable to find actor \"%s\"\n", v7, v8);
    return true;
  }
  return CBaseFlex::CheckSceneEvent(this: v6, currenttime, scene, event);
}

//------------------------------------------------------------------------------
// Address: 0x102012B0
// Name: public: virtual bool CSceneFindMarkFilter::ShouldFindEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneFindMarkFilter::ShouldFindEntity(CSceneFindMarkFilter *this, CBaseEntity *pEntity)
{
  unsigned int m_Index; // eax
  unsigned int v5; // eax
  unsigned int v7; // eax
  IHandleEntity *m_pEntity; // eax
  int v9; // eax
  unsigned int v10; // ecx
  IHandleEntity *v11; // edx
  const Vector *v12; // eax
  const Vector *v13; // [esp-18h] [ebp-80h]
  CGameTrace tr; // [esp+8h] [ebp-60h] BYREF
  Vector vecOrigin; // [esp+5Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+68h] [ebp+0h] BYREF
  CBaseEntity *pEntitya; // [esp+70h] [ebp+8h]

  m_Index = this->m_hActor.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    return 1;
  }
  v5 = this->m_hEntityFound.m_Index;
  if ( v5 == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity == nullptr )
  {
    if ( pEntity != nullptr )
      this->m_hEntityFound.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
    else
      this->m_hEntityFound.m_Index = -1;
  }
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  vecOrigin.z = pEntity->m_vecAbsOrigin.z;
  v7 = this->m_hActor.m_Index;
  *(_QWORD *)&vecOrigin.x = *(_QWORD *)&pEntity->m_vecAbsOrigin.x;
  if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
    pEntitya = nullptr;
  else
    pEntitya = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
  if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
  v9 = (int)m_pEntity[57].GetRefEHandle(this: m_pEntity + 57);
  v10 = this->m_hActor.m_Index;
  if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
    v11 = nullptr;
  else
    v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
  v13 = (const Vector *)v9;
  v12 = (const Vector *)((int (__thiscall *)(IHandleEntity *))v11[57].SetRefEHandle)(a1: &v11[57]);
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)pEntity,
    vecAbsStart: &vecOrigin,
    vecAbsEnd: &vecOrigin,
    hullMin: v12,
    hullMax: v13,
    mask: 0x200400Bu,
    ignore: pEntitya,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.startsolid )
    return 0;
  this->m_hEntityFound.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10201450
// Name: public: virtual bool CSceneFindNearestMarkFilter::ShouldFindEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CSceneFindNearestMarkFilter::ShouldFindEntity@<al>(
        CSceneFindNearestMarkFilter *this@<ecx>,
        IHandleEntity_vtbl *a2@<ebp>,
        CBaseEntity *pEntity)
{
  unsigned int m_Index; // eax
  unsigned int v6; // eax
  float z; // ecx
  IHandleEntity *v8; // eax
  float v9; // eax
  unsigned int v10; // ecx
  IHandleEntity *v11; // edx
  IHandleEntity_vtbl *v12; // eax
  const Vector *v13; // eax
  unsigned int v14; // eax
  IHandleEntity *v15; // ecx
  float v16; // xmm0_4
  float v17; // xmm1_4
  __int128 v18; // xmm0
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  __int128 v22; // xmm0
  float v23; // xmm0_4
  float m_flMaxSegmentDistance; // xmm0_4
  float v25; // xmm0_4
  _BYTE v26[12]; // [esp-Ch] [ebp-94h] BYREF
  _BYTE tr_43[49]; // [esp+2Bh] [ebp-5Dh] OVERLAPPED
  __int128 v28; // [esp+5Ch] [ebp-2Ch] BYREF
  Vector vecOrigin; // [esp+6Ch] [ebp-1Ch]
  IHandleEntity *m_pEntity; // [esp+78h] [ebp-10h]
  IHandleEntity v31[3]; // [esp+7Ch] [ebp-Ch] BYREF
  IHandleEntity_vtbl *retaddr; // [esp+88h] [ebp+0h]

  v31[0].__vftable = a2;
  v31[1].__vftable = retaddr;
  m_Index = this->m_hActor.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    return 1;
  }
  if ( this->m_pNearestToActor == nullptr )
    this->m_pNearestToActor = pEntity;
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)v31);
  v6 = this->m_hActor.m_Index;
  z = pEntity->m_vecAbsOrigin.z;
  *(_QWORD *)((char *)&v28 + 4) = *(_QWORD *)&pEntity->m_vecAbsOrigin.x;
  *((float *)&v28 + 3) = z;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v8 = nullptr;
  else
    v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  v9 = COERCE_FLOAT((int)v8[57].GetRefEHandle(this: v8 + 57));
  v10 = this->m_hActor.m_Index;
  vecOrigin.z = v9;
  if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
    v11 = nullptr;
  else
    v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
  LODWORD(vecOrigin.z) = v26;
  vecOrigin.y = 0.0;
  LODWORD(vecOrigin.x) = m_pEntity;
  v12 = v11[57].__vftable;
  HIDWORD(v28) = 33570827;
  DWORD2(v28) = v26;
  v13 = (const Vector *)((int (__thiscall *)(IHandleEntity *))v12->SetRefEHandle)(a1: v11 + 57);
  UTIL_TraceHull(
    a1: v31,
    a2: (int)this,
    vecAbsStart: (const Vector *)((char *)&v28 + 4),
    vecAbsEnd: (const Vector *)((char *)&v28 + 4),
    hullMin: v13,
    hullMax: (const Vector *)DWORD2(v28),
    mask: HIDWORD(v28),
    ignore: (const IHandleEntity *)LODWORD(vecOrigin.x),
    collisionGroup: SLODWORD(vecOrigin.y),
    ptr: (CGameTrace *)LODWORD(vecOrigin.z));
  if ( tr_43[0] == 0
    || ((v14 = this->m_hActor.m_Index) == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14)
      ? (v15 = nullptr)
      : (v15 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity),
        *(IHandleEntity **)&tr_43[21] == v15) )
  {
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)v31);
    v16 = this->m_vecPos1.x - pEntity->m_vecAbsOrigin.x;
    v17 = (float)((float)((float)(this->m_vecPos1.y - pEntity->m_vecAbsOrigin.y)
                        * (float)(this->m_vecPos1.y - pEntity->m_vecAbsOrigin.y))
                + (float)((float)(this->m_vecPos1.z - pEntity->m_vecAbsOrigin.z)
                        * (float)(this->m_vecPos1.z - pEntity->m_vecAbsOrigin.z)))
        + (float)(v16 * v16);
    v18 = 0;
    v19 = (unsigned int)pEntity->m_iEFlags >> 11;
    *(float *)&v18 = fsqrt(v17);
    *(_OWORD *)&tr_43[33] = v18;
    if ( (v19 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)v31);
    v20 = this->m_vecPos2.x - pEntity->m_vecAbsOrigin.x;
    v21 = (float)((float)((float)(this->m_vecPos2.y - pEntity->m_vecAbsOrigin.y)
                        * (float)(this->m_vecPos2.y - pEntity->m_vecAbsOrigin.y))
                + (float)((float)(this->m_vecPos2.z - pEntity->m_vecAbsOrigin.z)
                        * (float)(this->m_vecPos2.z - pEntity->m_vecAbsOrigin.z)))
        + (float)(v20 * v20);
    v22 = 0;
    *(float *)&v22 = fsqrt(v21);
    v28 = v22;
    if ( this->m_flNearestToActor >= *(float *)&tr_43[33] )
    {
      v23 = *(float *)&v28;
      this->m_pNearestToActor = pEntity;
      this->m_flNearestToActor = v23;
    }
    m_flMaxSegmentDistance = this->m_flMaxSegmentDistance;
    if ( m_flMaxSegmentDistance >= *(float *)&tr_43[33]
      && m_flMaxSegmentDistance >= *(float *)&v28
      && this->m_flNearestToTarget > *(float *)&v28 )
    {
      v25 = *(float *)&v28;
      this->m_pNearestToTarget = pEntity;
      this->m_flNearestToTarget = v25;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10201700
// Name: public: virtual class CBaseEntity __near * CSceneEntity::FindNamedEntity(char const __near *,class CBaseEntity __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CSceneEntity::FindNamedEntity(
        CSceneEntity *this,
        const char *name,
        CBaseEntity *pActor,
        bool bBaseFlexOnly,
        bool bUseClear)
{
  const CBaseEntity *NamedTarget; // eax
  unsigned int m_Index; // ecx
  CBasePlayer *result; // eax
  const CBaseEntity *v9; // eax
  const CBaseEntity *v10; // eax
  const CBaseEntity *v11; // eax
  const CBaseEntity *v12; // eax
  const CBaseEntity *v13; // eax
  const CBaseEntity *v14; // eax
  const CBaseEntity *v15; // eax
  CSceneFindMarkFilter *v16; // esi
  CSceneFindMarkFilter *v17; // eax
  CAI_BaseNPC *v18; // eax
  CBaseEntity *EntityByName; // eax
  int i; // esi
  IUniformRandomStream *v21; // ecx
  CBaseEntity *entityList[32]; // [esp+Ch] [ebp-80h]

  if ( _V_stricmp(s1: name, s2: "Player") == 0 || _V_stricmp(s1: name, s2: "!player") == 0 )
  {
    if ( gpGlobals->maxClients == 1 )
      return UTIL_GetLocalPlayer();
    return nullptr;
  }
  if ( _V_stricmp(s1: name, s2: "!target1") == 0 )
  {
    if ( CHandle<CBaseEntity>::operator==(this: &this->m_hTarget1, val: nullptr) )
    {
      NamedTarget = CSceneEntity::FindNamedTarget(this, iszTarget: this->m_iszTarget1, bBaseFlexOnly);
      CHandle<CBaseEntity>::operator=(this: &this->m_hTarget1, val: NamedTarget);
    }
    m_Index = this->m_hTarget1.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      return (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    return nullptr;
  }
  if ( _V_stricmp(s1: name, s2: "!target2") != 0 )
  {
    if ( _V_stricmp(s1: name, s2: "!target3") != 0 )
    {
      if ( _V_stricmp(s1: name, s2: "!target4") != 0 )
      {
        if ( _V_stricmp(s1: name, s2: "!target5") != 0 )
        {
          if ( _V_stricmp(s1: name, s2: "!target6") != 0 )
          {
            if ( _V_stricmp(s1: name, s2: "!target7") != 0 )
            {
              if ( _V_stricmp(s1: name, s2: "!target8") != 0 )
              {
                if ( pActor == nullptr || pActor->MyNPCPointer(this: pActor) == nullptr )
                {
                  EntityByName = nullptr;
                  for ( i = 0; i < 32; ++i )
                  {
                    EntityByName = CGlobalEntityList::FindEntityByName(
                                     this: &gEntList,
                                     pStartEntity: EntityByName,
                                     szName: name,
                                     pSearchingEntity: nullptr,
                                     pActivator: pActor,
                                     pCaller: nullptr,
                                     pFilter: nullptr);
                    if ( EntityByName == nullptr )
                      break;
                    entityList[i] = EntityByName;
                  }
                  if ( i > 0 )
                    return (CBasePlayer *)entityList[_RandomInt(this: v21, a2: 0, a3: i - 1)];
                  return nullptr;
                }
                v16 = nullptr;
                if ( bUseClear )
                {
                  v17 = (CSceneFindMarkFilter *)operator new(nSize: 0xCu);
                  if ( v17 != nullptr )
                  {
                    v17->__vftable = (CSceneFindMarkFilter_vtbl *)&CSceneFindMarkFilter::`vftable';
                    v17->m_hActor.m_Index = -1;
                    v17->m_hEntityFound.m_Index = -1;
                    v16 = v17;
                  }
                  else
                  {
                    v16 = nullptr;
                  }
                  CSceneFindMarkFilter::SetActor(this: v16, pActor);
                }
                v18 = pActor->MyNPCPointer(this: pActor);
                result = (CBasePlayer *)v18->FindNamedEntity(this: v18, a2: name, a3: v16);
                if ( result == nullptr && v16 != nullptr )
                  return (CBasePlayer *)v16->GetFilterResult(this: v16);
              }
              else
              {
                if ( CHandle<CBaseEntity>::operator==(this: &this->m_hTarget8, val: nullptr) )
                {
                  v15 = CSceneEntity::FindNamedTarget(this, iszTarget: this->m_iszTarget8, bBaseFlexOnly);
                  CHandle<CBaseEntity>::operator=(this: &this->m_hTarget8, val: v15);
                }
                return (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTarget8);
              }
            }
            else
            {
              if ( CHandle<CBaseEntity>::operator==(this: &this->m_hTarget7, val: nullptr) )
              {
                v14 = CSceneEntity::FindNamedTarget(this, iszTarget: this->m_iszTarget7, bBaseFlexOnly);
                CHandle<CBaseEntity>::operator=(this: &this->m_hTarget7, val: v14);
              }
              return (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTarget7);
            }
          }
          else
          {
            if ( CHandle<CBaseEntity>::operator==(this: &this->m_hTarget6, val: nullptr) )
            {
              v13 = CSceneEntity::FindNamedTarget(this, iszTarget: this->m_iszTarget6, bBaseFlexOnly);
              CHandle<CBaseEntity>::operator=(this: &this->m_hTarget6, val: v13);
            }
            return (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTarget6);
          }
        }
        else
        {
          if ( CHandle<CBaseEntity>::operator==(this: &this->m_hTarget5, val: nullptr) )
          {
            v12 = CSceneEntity::FindNamedTarget(this, iszTarget: this->m_iszTarget5, bBaseFlexOnly);
            CHandle<CBaseEntity>::operator=(this: &this->m_hTarget5, val: v12);
          }
          return (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTarget5);
        }
      }
      else
      {
        if ( CHandle<CBaseEntity>::operator==(this: &this->m_hTarget4, val: nullptr) )
        {
          v11 = CSceneEntity::FindNamedTarget(this, iszTarget: this->m_iszTarget4, bBaseFlexOnly);
          CHandle<CBaseEntity>::operator=(this: &this->m_hTarget4, val: v11);
        }
        return (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTarget4);
      }
    }
    else
    {
      if ( CHandle<CBaseEntity>::operator==(this: &this->m_hTarget3, val: nullptr) )
      {
        v10 = CSceneEntity::FindNamedTarget(this, iszTarget: this->m_iszTarget3, bBaseFlexOnly);
        CHandle<CBaseEntity>::operator=(this: &this->m_hTarget3, val: v10);
      }
      return (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTarget3);
    }
  }
  else
  {
    if ( CHandle<CBaseEntity>::operator==(this: &this->m_hTarget2, val: nullptr) )
    {
      v9 = CSceneEntity::FindNamedTarget(this, iszTarget: this->m_iszTarget2, bBaseFlexOnly);
      CHandle<CBaseEntity>::operator=(this: &this->m_hTarget2, val: v9);
    }
    return (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTarget2);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10201AF0
// Name: public: virtual void CSceneEntity::CheckInterruptCompletion(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::CheckInterruptCompletion(CSceneEntity *this)
{
  unsigned int m_Index; // eax

  if ( this->m_bInterrupted )
  {
    m_Index = this->m_hInterruptScene.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr
      || this->m_bInterruptSceneFinished )
    {
      this->m_bInterrupted = false;
      this->m_hInterruptScene.m_Index = -1;
      this->ResumePlayback(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10201B50
// Name: public: virtual void CSceneEntity::ClearInterrupt(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::ClearInterrupt(CSceneEntity *this)
{
  this->m_nInterruptCount = 0;
  this->m_bInterrupted = false;
  this->m_hInterruptScene.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10201B70
// Name: public: virtual int CSceneEntity::ShouldTransmit(class CCheckTransmitInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSceneEntity::ShouldTransmit(CSceneEntity *this, const CCheckTransmitInfo *pInfo)
{
  int result; // eax
  int v4; // ebx
  int v5; // eax
  edict_t *pEdicts; // esi
  edict_t *v7; // eax
  IServerUnknown *m_pUnk; // ecx
  CBasePlayer *v9; // eax
  int v10; // [esp+4h] [ebp-4h]

  result = CBaseEntity::ShouldTransmit(this, pInfo);
  v10 = result;
  if ( this->m_pRecipientFilter != nullptr && result != 16 )
  {
    v4 = 0;
    if ( this->m_pRecipientFilter->GetRecipientCount(this: this->m_pRecipientFilter) <= 0 )
    {
      return 16;
    }
    else
    {
      while ( 1 )
      {
        v5 = this->m_pRecipientFilter->GetRecipientIndex(this: this->m_pRecipientFilter, a2: v4);
        pEdicts = gpGlobals->pEdicts;
        v7 = pEdicts != nullptr ? ((pEdicts[v5].m_fStateFlags & 2) == 0 ? &pEdicts[v5] : nullptr) : nullptr;
        if ( v7 != nullptr || pEdicts != nullptr && (v7 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0) )
        {
          m_pUnk = v7->m_pUnk;
          if ( m_pUnk != nullptr )
          {
            v9 = (CBasePlayer *)m_pUnk->GetBaseEntity(this: m_pUnk);
            if ( v9 != nullptr
              && (v9->m_Network.m_pPev == pInfo->m_pClientEnt
               || CBasePlayer::IsSplitScreenUserOnEdict(this: v9, edict: pInfo->m_pClientEnt)) )
            {
              break;
            }
          }
        }
        if ( ++v4 >= this->m_pRecipientFilter->GetRecipientCount(this: this->m_pRecipientFilter) )
          return 16;
      }
      return v10;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10201C60
// Name: float InstancedAutoGeneratedSoundScene(class CBaseFlex __near *,char const __near *,class CHandle<class CBaseEntity> __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl InstancedAutoGeneratedSoundScene(
        CBaseFlex *pActor,
        const char *soundname,
        CHandle<CBaseEntity> *phSceneEnt)
{
  CBaseEntity *NoSpawn; // esi
  unsigned int *p_m_ListByClass; // ebx
  const char *v6; // eax
  const char *v7; // eax

  if ( pActor != nullptr )
  {
    NoSpawn = CBaseEntity::CreateNoSpawn(
                szName: "instanced_scripted_scene",
                vecOrigin: &vec3_origin,
                vecAngles: &vec3_angle,
                pOwner: nullptr);
    p_m_ListByClass = &NoSpawn[1].m_ListByClass;
    v6 = UTIL_VarArgs(format: "AutoGenerated(%s)", soundname);
    V_strncpy(pDest: (char *)&NoSpawn[1].m_ListByClass, pSrc: v6, maxLen: 128);
    if ( NoSpawn == (CBaseEntity *)-1592 || *(_BYTE *)p_m_ListByClass == 0 )
      p_m_ListByClass = nullptr;
    NoSpawn[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))p_m_ListByClass;
    NoSpawn[1].m_RefEHandle.m_Index = pActor->GetRefEHandle(this: pActor)->m_Index;
    LOBYTE(NoSpawn[1].m_vecViewOffset.m_Value.x) = 1;
    BYTE1(NoSpawn[1].m_cellZ.m_Value) = 1;
    v7 = soundname;
    if ( soundname == nullptr || *soundname == 0 )
      v7 = nullptr;
    LODWORD(NoSpawn[1].m_vecOrigin.m_Value.x) = v7;
    LODWORD(NoSpawn[1].m_vecOrigin.m_Value.y) = pActor->GetRefEHandle(this: pActor)->m_Index;
    NoSpawn->Spawn(this: NoSpawn);
    NoSpawn->Activate(this: NoSpawn);
    ((void (__thiscall *)(CBaseEntity *))NoSpawn->__vftable[1].SetModelIndex)(a1: NoSpawn);
    if ( phSceneEnt != nullptr )
      phSceneEnt->m_Index = NoSpawn->GetRefEHandle(this: NoSpawn)->m_Index;
    return ((float (__thiscall *)(CBaseEntity *))NoSpawn->__vftable[1].GetPlayerName)(a1: NoSpawn);
  }
  else
  {
    _Warning(a1: "InstancedAutoGeneratedSoundScene:  Expecting non-NULL pActor for sound %s\n", soundname);
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10201D60
// Name: public: virtual class CBaseFlex __near * CInstancedSceneEntity::FindNamedActor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseFlex *__thiscall CInstancedSceneEntity::FindNamedActor(CInstancedSceneEntity *this, const char *name)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *v10; // ecx
  CBaseFlex *result; // eax

  if ( CChoreoScene::GetNumActors(this: this->m_pScene) != 1 && _V_stricmp(s1: name, s2: "!self") != 0 )
    goto LABEL_10;
  m_Index = this->m_hOwner.m_Index;
  if ( m_Index == -1 )
    goto LABEL_10;
  v4 = (unsigned __int16)m_Index;
  v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v6 = HIWORD(m_Index);
  if ( v5->m_SerialNumber != v6 || v5->m_pEntity == nullptr )
    goto LABEL_10;
  v7 = v4;
  v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
  v9 = &g_pEntityList->m_EntPtrArray[v7];
  v10 = v8 ? v9->m_pEntity : nullptr;
  result = (CBaseFlex *)((int (__thiscall *)(IHandleEntity *))v10->__vftable[25].dtr_IHandleEntity)(a1: v10);
  if ( result == nullptr )
  {
LABEL_10:
    result = (CBaseFlex *)this->FindNamedEntity(this, a2: name, a3: 0, a4: 1, a5: 0);
    if ( result != nullptr )
      return (CBaseFlex *)__RTDynamicCast(
                            inptr: result,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CBaseFlex `RTTI Type Descriptor',
                            isReference: 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10201E20
// Name: public: virtual class CBaseEntity __near * CInstancedSceneEntity::FindNamedEntity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CInstancedSceneEntity::FindNamedEntity(CInstancedSceneEntity *this, const char *name)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // ecx
  int v11; // eax
  CBasePlayer *result; // eax
  unsigned int v13; // eax
  IHandleEntity *v14; // ecx
  unsigned int v15; // eax

  m_Index = this->m_hOwner.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = &g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        m_pEntity = v9->m_pEntity;
      else
        m_pEntity = nullptr;
      v11 = (int)m_pEntity->__vftable[24].GetRefEHandle(this: m_pEntity);
      if ( v11 != 0 )
      {
        result = (CBasePlayer *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v11 + 2248))(
                                  a1: v11,
                                  a2: name,
                                  a3: 0);
        goto LABEL_18;
      }
      v13 = this->m_hOwner.m_Index;
      if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
        v14 = nullptr;
      else
        v14 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
      if ( ((int (__thiscall *)(IHandleEntity *))v14->__vftable[25].dtr_IHandleEntity)(a1: v14) != 0 )
      {
        v15 = this->m_hOwner.m_Index;
        if ( v15 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
          result = nullptr;
        else
          result = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
LABEL_18:
        if ( result != nullptr )
          return result;
      }
    }
  }
  return CSceneEntity::FindNamedEntity(this, name, pActor: nullptr, bBaseFlexOnly: false, bUseClear: false);
}

//------------------------------------------------------------------------------
// Address: 0x10201F20
// Name: public: void CSceneManager::RemoveActorFromScenes(class CBaseFlex __near *,bool,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManager::RemoveActorFromScenes(
        CSceneManager *this,
        CBaseFlex *pActor,
        bool bInstancedOnly,
        bool bNonIdleOnly,
        const char *pszThisSceneOnly)
{
  int v5; // edi
  unsigned int m_Index; // eax
  CSceneEntity **v7; // ecx
  CSceneEntity *v8; // esi
  const char *pszValue; // eax
  const char *DebugName; // eax
  const char *v11; // ecx
  int c; // [esp+4h] [ebp-8h]
  CSceneManager *v13; // [esp+8h] [ebp-4h]

  v5 = 0;
  v13 = this;
  c = this->m_Scenes.m_Size;
  if ( c > 0 )
  {
    while ( 1 )
    {
      m_Index = this->m_Scenes.m_Memory.m_pMemory[v5].m_Index;
      if ( m_Index != -1 )
      {
        v7 = (CSceneEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          v8 = *v7;
          if ( *v7 != nullptr
            && (!bInstancedOnly
             || __RTDynamicCast(
                  inptr: v8,
                  VfDelta: 0,
                  SrcType: &CSceneEntity `RTTI Type Descriptor',
                  TargetType: &CInstancedSceneEntity `RTTI Type Descriptor',
                  isReference: 0) != nullptr)
            && (!bNonIdleOnly || v8->m_bBreakOnNonIdle)
            && CSceneEntity::InvolvesActor(this: v8, pActor) != 0 )
          {
            if ( pszThisSceneOnly == nullptr || *pszThisSceneOnly == 0 )
              goto LABEL_18;
            pszValue = v8->m_iszSceneFile.pszValue;
            if ( pszValue == nullptr )
              pszValue = locale;
            if ( _V_strcmp(s1: pszThisSceneOnly, s2: pszValue) == 0 )
            {
LABEL_18:
              if ( scene_print.m_pParent != nullptr && scene_print.m_pParent->m_Value.m_nValue != 0 )
              {
                if ( pActor != nullptr )
                  DebugName = CBaseEntity::GetDebugName(this: pActor);
                else
                  DebugName = "NULL";
                v11 = v8->m_iszSceneFile.pszValue;
                if ( v11 == nullptr )
                  v11 = locale;
                Scene_Printf(pFormat: "%s : removed for '%s'\n", v11, DebugName);
              }
              v8->CancelPlayback(this: v8);
            }
          }
        }
      }
      if ( ++v5 >= c )
        break;
      this = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202060
// Name: public: void CSceneManager::PauseActorsScenes(class CBaseFlex __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManager::PauseActorsScenes(CSceneManager *this, CBaseFlex *pActor, bool bInstancedOnly)
{
  int v3; // eax
  unsigned int m_Index; // eax
  CSceneEntity **v5; // ecx
  CSceneEntity *v6; // esi
  const char *pszValue; // eax
  const char *DebugName; // eax
  const char *v9; // [esp-4h] [ebp-30h]
  int c; // [esp+20h] [ebp-Ch]
  CSceneManager *v11; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  v3 = 0;
  v11 = this;
  c = this->m_Scenes.m_Size;
  i = 0;
  if ( c > 0 )
  {
    while ( 1 )
    {
      m_Index = this->m_Scenes.m_Memory.m_pMemory[v3].m_Index;
      if ( m_Index != -1 )
      {
        v5 = (CSceneEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          v6 = *v5;
          if ( *v5 != nullptr
            && (!bInstancedOnly
             || __RTDynamicCast(
                  inptr: v6,
                  VfDelta: 0,
                  SrcType: &CSceneEntity `RTTI Type Descriptor',
                  TargetType: &CInstancedSceneEntity `RTTI Type Descriptor',
                  isReference: 0) != nullptr)
            && CSceneEntity::InvolvesActor(this: v6, pActor) != 0
            && v6->m_bIsPlayingBack.m_Value )
          {
            pszValue = v6->m_iszSceneFile.pszValue;
            if ( pszValue == nullptr )
              pszValue = locale;
            v9 = pszValue;
            DebugName = CBaseEntity::GetDebugName(this: pActor);
            Scene_Printf(pFormat: "Pausing actor %s scripted scene: %s\n", DebugName, v9);
            ((void (__thiscall *)(CSceneEntity *, const char *, CSceneEntity *, CSceneEntity *, _DWORD))v6->AcceptInput)(
              a1: v6,
              a2: "Pause",
              a3: v6,
              a4: v6,
              a5: 0);
          }
        }
      }
      v3 = i + 1;
      i = v3;
      if ( v3 >= c )
        break;
      this = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202180
// Name: public: bool CSceneManager::IsInInterruptableScenes(class CBaseFlex __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneManager::IsInInterruptableScenes(CSceneManager *this, CBaseFlex *pActor)
{
  int m_Size; // edx
  int v4; // edi
  unsigned int m_Index; // eax
  CSceneEntity **v6; // ecx
  CSceneEntity *v7; // esi
  CChoreoScene *m_pScene; // ecx
  int c; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Scenes.m_Size;
  v4 = 0;
  c = m_Size;
  if ( m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    m_Index = this->m_Scenes.m_Memory.m_pMemory[v4].m_Index;
    if ( m_Index != -1 )
    {
      v6 = (CSceneEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        goto LABEL_11;
      v7 = *v6;
      if ( *v6 == nullptr )
        goto LABEL_11;
      m_pScene = v7->m_pScene;
      if ( (m_pScene == nullptr || !CChoreoScene::IsBackground(this: m_pScene))
        && CSceneEntity::InvolvesActor(this: v7, pActor) != 0
        && v7->m_bIsPlayingBack.m_Value
        && v7->m_nInterruptCount <= 0 )
      {
        return 0;
      }
      m_Size = c;
    }
LABEL_11:
    if ( ++v4 >= m_Size )
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202230
// Name: public: void CSceneManager::QueueActorsScenesToResume(class CBaseFlex __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManager::QueueActorsScenesToResume(CSceneManager *this, CBaseFlex *pActor, bool bInstancedOnly)
{
  int v4; // edi
  unsigned int m_Index; // eax
  CSceneEntity **v6; // ecx
  CSceneEntity *v7; // esi
  int c; // [esp+8h] [ebp-4h]

  v4 = 0;
  c = this->m_Scenes.m_Size;
  if ( c > 0 )
  {
    do
    {
      m_Index = this->m_Scenes.m_Memory.m_pMemory[v4].m_Index;
      if ( m_Index != -1 )
      {
        v6 = (CSceneEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          v7 = *v6;
          if ( *v6 != nullptr
            && (!bInstancedOnly
             || __RTDynamicCast(
                  inptr: v7,
                  VfDelta: 0,
                  SrcType: &CSceneEntity `RTTI Type Descriptor',
                  TargetType: &CInstancedSceneEntity `RTTI Type Descriptor',
                  isReference: 0) != nullptr)
            && CSceneEntity::InvolvesActor(this: v7, pActor) != 0
            && v7->m_bIsPlayingBack.m_Value
            && v7->m_bPaused.m_Value )
          {
            v7->QueueResumePlayback(this: v7);
          }
        }
      }
      ++v4;
    }
    while ( v4 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102022F0
// Name: public: bool CSceneManager::IsRunningScriptedScene(class CBaseFlex __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneManager::IsRunningScriptedScene(
        CSceneManager *this,
        CBaseFlex *pActor,
        bool bIgnoreInstancedScenes)
{
  int m_Size; // edx
  int v5; // edi
  unsigned int m_Index; // eax
  CSceneEntity **v7; // ecx
  CSceneEntity *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Scenes.m_Size;
  v5 = 0;
  c = m_Size;
  if ( m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    m_Index = this->m_Scenes.m_Memory.m_pMemory[v5].m_Index;
    if ( m_Index != -1 )
    {
      v7 = (CSceneEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        goto LABEL_10;
      v8 = *v7;
      if ( *v7 == nullptr || !v8->m_bIsPlayingBack.m_Value )
        goto LABEL_10;
      if ( (!bIgnoreInstancedScenes
         || __RTDynamicCast(
              inptr: v8,
              VfDelta: 0,
              SrcType: &CSceneEntity `RTTI Type Descriptor',
              TargetType: &CInstancedSceneEntity `RTTI Type Descriptor',
              isReference: 0) == nullptr)
        && CSceneEntity::InvolvesActor(this: v8, pActor) != 0 )
      {
        return 1;
      }
      m_Size = c;
    }
LABEL_10:
    if ( ++v5 >= m_Size )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102023A0
// Name: public: bool CSceneManager::IsRunningScriptedSceneAndNotPaused(class CBaseFlex __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneManager::IsRunningScriptedSceneAndNotPaused(
        CSceneManager *this,
        CBaseFlex *pActor,
        bool bIgnoreInstancedScenes)
{
  int m_Size; // edx
  int v5; // edi
  unsigned int m_Index; // eax
  CSceneEntity **v7; // ecx
  CSceneEntity *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Scenes.m_Size;
  v5 = 0;
  c = m_Size;
  if ( m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    m_Index = this->m_Scenes.m_Memory.m_pMemory[v5].m_Index;
    if ( m_Index != -1 )
    {
      v7 = (CSceneEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        goto LABEL_11;
      v8 = *v7;
      if ( *v7 == nullptr || !v8->m_bIsPlayingBack.m_Value || v8->m_bPaused.m_Value )
        goto LABEL_11;
      if ( (!bIgnoreInstancedScenes
         || __RTDynamicCast(
              inptr: v8,
              VfDelta: 0,
              SrcType: &CSceneEntity `RTTI Type Descriptor',
              TargetType: &CInstancedSceneEntity `RTTI Type Descriptor',
              isReference: 0) == nullptr)
        && CSceneEntity::InvolvesActor(this: v8, pActor) != 0 )
      {
        return 1;
      }
      m_Size = c;
    }
LABEL_11:
    if ( ++v5 >= m_Size )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202460
// Name: public: bool CSceneManager::IsRunningScriptedSceneWithSpeech(class CBaseFlex __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneManager::IsRunningScriptedSceneWithSpeech(
        CSceneManager *this,
        CBaseFlex *pActor,
        bool bIgnoreInstancedScenes)
{
  int m_Size; // edx
  int v5; // edi
  unsigned int m_Index; // eax
  CSceneEntity **v7; // ecx
  CSceneEntity *v8; // esi
  CChoreoScene *m_pScene; // ecx
  int c; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Scenes.m_Size;
  v5 = 0;
  c = m_Size;
  if ( m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    m_Index = this->m_Scenes.m_Memory.m_pMemory[v5].m_Index;
    if ( m_Index != -1 )
    {
      v7 = (CSceneEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        goto LABEL_12;
      v8 = *v7;
      if ( *v7 == nullptr || !v8->m_bIsPlayingBack.m_Value )
        goto LABEL_12;
      if ( (!bIgnoreInstancedScenes
         || __RTDynamicCast(
              inptr: v8,
              VfDelta: 0,
              SrcType: &CSceneEntity `RTTI Type Descriptor',
              TargetType: &CInstancedSceneEntity `RTTI Type Descriptor',
              isReference: 0) == nullptr)
        && CSceneEntity::InvolvesActor(this: v8, pActor) != 0 )
      {
        m_pScene = v8->m_pScene;
        if ( m_pScene != nullptr && CChoreoScene::HasUnplayedSpeech(this: m_pScene) )
          return 1;
      }
      m_Size = c;
    }
LABEL_12:
    if ( ++v5 >= m_Size )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202530
// Name: public: bool CSceneManager::IsRunningScriptedSceneWithSpeechAndNotPaused(class CBaseFlex __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneManager::IsRunningScriptedSceneWithSpeechAndNotPaused(
        CSceneManager *this,
        CBaseFlex *pActor,
        bool bIgnoreInstancedScenes)
{
  int m_Size; // edx
  int v5; // edi
  unsigned int m_Index; // eax
  CSceneEntity **v7; // ecx
  CSceneEntity *v8; // esi
  CChoreoScene *m_pScene; // ecx
  int c; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Scenes.m_Size;
  v5 = 0;
  c = m_Size;
  if ( m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    m_Index = this->m_Scenes.m_Memory.m_pMemory[v5].m_Index;
    if ( m_Index != -1 )
    {
      v7 = (CSceneEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        goto LABEL_13;
      v8 = *v7;
      if ( *v7 == nullptr || !v8->m_bIsPlayingBack.m_Value || v8->m_bPaused.m_Value )
        goto LABEL_13;
      if ( (!bIgnoreInstancedScenes
         || __RTDynamicCast(
              inptr: v8,
              VfDelta: 0,
              SrcType: &CSceneEntity `RTTI Type Descriptor',
              TargetType: &CInstancedSceneEntity `RTTI Type Descriptor',
              isReference: 0) == nullptr)
        && CSceneEntity::InvolvesActor(this: v8, pActor) != 0 )
      {
        m_pScene = v8->m_pScene;
        if ( m_pScene != nullptr && CChoreoScene::HasUnplayedSpeech(this: m_pScene) )
          return 1;
      }
      m_Size = c;
    }
LABEL_13:
    if ( ++v5 >= m_Size )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202600
// Name: void RemoveActorFromScriptedScenes(class CBaseFlex __near *,bool,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveActorFromScriptedScenes(
        CBaseFlex *pActor,
        bool instancedscenesonly,
        bool nonidlescenesonly,
        const char *pszThisSceneOnly)
{
  CSceneManager *SceneManager; // eax

  SceneManager = GetSceneManager();
  CSceneManager::RemoveActorFromScenes(
    this: SceneManager,
    pActor,
    bInstancedOnly: instancedscenesonly,
    bNonIdleOnly: nonidlescenesonly,
    pszThisSceneOnly);
}

//------------------------------------------------------------------------------
// Address: 0x10202630
// Name: bool IsRunningScriptedScene(class CBaseFlex __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsRunningScriptedScene(CBaseFlex *pActor, bool bIgnoreInstancedScenes)
{
  CSceneManager *SceneManager; // eax

  SceneManager = GetSceneManager();
  return CSceneManager::IsRunningScriptedScene(this: SceneManager, pActor, bIgnoreInstancedScenes);
}

//------------------------------------------------------------------------------
// Address: 0x10202650
// Name: bool IsRunningScriptedSceneAndNotPaused(class CBaseFlex __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsRunningScriptedSceneAndNotPaused(CBaseFlex *pActor, bool bIgnoreInstancedScenes)
{
  CSceneManager *SceneManager; // eax

  SceneManager = GetSceneManager();
  return CSceneManager::IsRunningScriptedSceneAndNotPaused(this: SceneManager, pActor, bIgnoreInstancedScenes);
}

//------------------------------------------------------------------------------
// Address: 0x10202670
// Name: bool IsRunningScriptedSceneWithSpeechAndNotPaused(class CBaseFlex __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsRunningScriptedSceneWithSpeechAndNotPaused(CBaseFlex *pActor, bool bIgnoreInstancedScenes)
{
  CSceneManager *SceneManager; // eax

  SceneManager = GetSceneManager();
  return CSceneManager::IsRunningScriptedSceneWithSpeechAndNotPaused(this: SceneManager, pActor, bIgnoreInstancedScenes);
}

//------------------------------------------------------------------------------
// Address: 0x10202690
// Name: public: void CSceneListManager::SceneStarted(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneListManager::SceneStarted(CSceneListManager *this, CBaseEntity *pSceneOrManager)
{
  CBaseEntityList *v2; // esi
  int v3; // edi
  CHandle<CBaseEntity> *v4; // ebx
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CBaseEntity **v11; // eax
  CBaseEntity *v12; // eax
  int m_Size; // ebx
  int i; // edi
  CHandle<CSceneListManager> *v15; // edx
  unsigned int v16; // eax
  unsigned int v17; // eax
  CSceneListManager *m_pEntity; // ecx
  bool bFoundStart; // [esp+13h] [ebp-1h]

  v2 = g_pEntityList;
  bFoundStart = false;
  v3 = 15;
  v4 = &this->m_hScenes[15];
  do
  {
    m_Index = v4->m_Index;
    if ( v4->m_Index != -1 )
    {
      v6 = (unsigned __int16)m_Index;
      v7 = &v2->m_EntPtrArray[(unsigned __int16)m_Index];
      v8 = HIWORD(m_Index);
      if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
      {
        if ( bFoundStart )
        {
          CSceneListManager::RemoveScene(this, iIndex: v3);
          v2 = g_pEntityList;
        }
        else
        {
          v9 = v6;
          v10 = v2->m_EntPtrArray[v9].m_SerialNumber == v8;
          v11 = (CBaseEntity **)&v2->m_EntPtrArray[v9];
          if ( v10 )
            v12 = *v11;
          else
            v12 = nullptr;
          if ( v12 == pSceneOrManager )
            bFoundStart = true;
        }
      }
    }
    --v4;
    --v3;
  }
  while ( v3 >= 0 );
  if ( bFoundStart )
  {
    m_Size = this->m_hListManagers.m_Size;
    for ( i = 0; i < m_Size; ++i )
    {
      v15 = &this->m_hListManagers.m_Memory.m_pMemory[i];
      v16 = v15->m_Index;
      if ( v15->m_Index != -1
        && v2->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber == HIWORD(v16)
        && v2->m_EntPtrArray[(unsigned __int16)v16].m_pEntity != nullptr )
      {
        v17 = v15->m_Index;
        if ( v15->m_Index == -1 || v2->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CSceneListManager *)v2->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
        CSceneListManager::SceneStarted(this: m_pEntity, pSceneOrManager: this);
        v2 = g_pEntityList;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102027A0
// Name: public: void CSceneListManager::InputShutdown(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CSceneListManager::InputShutdown(CSceneListManager *this, inputdata_t *inputdata)
{
  CSceneListManager::ShutdownList(this);
}

//------------------------------------------------------------------------------
// Address: 0x10203050
// Name: private: bool CSceneEntity::CheckActors(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneEntity::CheckActors(CSceneEntity *this)
{
  CChoreoScene *m_pScene; // ecx
  int v4; // edi
  CBaseFlex *v5; // esi
  int v6; // eax
  int m_BusyActor; // eax
  CBaseFlex *v8; // edi
  CSceneManager *SceneManager; // eax
  int v10; // eax
  int v11; // eax
  CBaseFlex *v12; // edi
  CSceneManager *v13; // eax
  CSceneManager *v14; // eax
  CSceneManager *v15; // eax
  CBaseFlex *v16; // [esp-Ch] [ebp-18h]
  int i; // [esp+4h] [ebp-8h]
  bool bShouldWait; // [esp+Bh] [ebp-1h]

  m_pScene = this->m_pScene;
  if ( m_pScene == nullptr )
    return 0;
  v4 = 0;
  i = 0;
  if ( CChoreoScene::GetNumActors(this: m_pScene) <= 0 )
    return 1;
  while ( 1 )
  {
    v5 = this->FindNamedActor_3(this, a2: v4);
    if ( v5 == nullptr || v5->MyCombatCharacterPointer(this: v5) == nullptr )
      goto LABEL_24;
    v6 = (int)v5->MyCombatCharacterPointer(this: v5);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 272))(a1: v6) == 0 )
      return 0;
    m_BusyActor = this->m_BusyActor;
    if ( m_BusyActor == 1 )
    {
      v8 = v5->MyNPCPointer(this: v5);
      if ( v8 != nullptr )
      {
        bShouldWait = false;
        if ( hl2_episodic.m_pParent != nullptr && hl2_episodic.m_pParent->m_Value.m_nValue != 0 )
        {
          SceneManager = GetSceneManager();
          bShouldWait = CSceneManager::IsRunningScriptedSceneWithSpeech(
                          this: SceneManager,
                          pActor: v8,
                          bIgnoreInstancedScenes: false) != 0;
        }
        if ( ((int (__thiscall *)(CBaseFlex *))v8->__vftable[1].PlayScene)(a1: v8) != 0
          && (v10 = ((int (__thiscall *)(CBaseFlex *))v8->__vftable[1].PlayScene)(a1: v8),
              (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 16))(a1: v10) != 0)
          || bShouldWait )
        {
          this->m_bWaitingForActor = true;
          return 0;
        }
      }
      goto LABEL_23;
    }
    if ( m_BusyActor == 2 || m_BusyActor == 3 )
      break;
LABEL_23:
    CBaseFlex::StartChoreoScene(this: v5, scene: this->m_pScene);
    v4 = i;
LABEL_24:
    i = ++v4;
    if ( v4 >= CChoreoScene::GetNumActors(this: this->m_pScene) )
      return 1;
  }
  v11 = (int)v5->MyCombatCharacterPointer(this: v5);
  v12 = (CBaseFlex *)v11;
  if ( v11 == 0
    || (v16 = (CBaseFlex *)v11,
        v13 = GetSceneManager(),
        CSceneManager::IsInInterruptableScenes(this: v13, pActor: v16) != 0) )
  {
    if ( this->m_BusyActor == 3 )
    {
      v14 = GetSceneManager();
      CSceneManager::RemoveActorFromScenes(
        this: v14,
        pActor: v12,
        bInstancedOnly: false,
        bNonIdleOnly: false,
        pszThisSceneOnly: nullptr);
    }
    else
    {
      v15 = GetSceneManager();
      CSceneManager::PauseActorsScenes(this: v15, pActor: v12, bInstancedOnly: false);
      this->m_bInterruptedActorsScenes = true;
    }
    goto LABEL_23;
  }
  this->m_bWaitingForInterrupt = true;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10203200
// Name: public: virtual void CSceneManager::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManager::Think(CSceneManager *this)
{
  int m_nValue; // eax
  CGlobalVars *v3; // edi
  double v4; // st7
  double v5; // xmm0_8
  int m_Size; // ebx
  int v7; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int i; // ebx
  unsigned int v11; // eax
  int j; // edi
  unsigned int v13; // eax
  float thinkTime; // [esp+0h] [ebp-18h]
  float frameTime; // [esp+10h] [ebp-8h]
  float frameTimea; // [esp+10h] [ebp-8h]
  bool needCleanupPass; // [esp+17h] [ebp-1h]

  if ( scene_clientflex.m_pParent != nullptr )
    m_nValue = scene_clientflex.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  g_bClientFlex = m_nValue != 0;
  thinkTime = gpGlobals->curtime + 0.001;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  v3 = gpGlobals;
  v4 = v3->curtime - CBaseEntity::GetLastThink(this, szContext: nullptr);
  if ( v4 <= 0.1 )
  {
    frameTime = v4;
    v5 = frameTime;
  }
  else
  {
    v5 = 0.1;
  }
  if ( (CAI_BaseNPC::m_nDebugBits & 1) == 0 )
  {
    m_Size = this->m_ActiveScenes.m_Size;
    v7 = 0;
    needCleanupPass = false;
    if ( m_Size > 0 )
    {
      do
      {
        m_Index = this->m_ActiveScenes.m_Memory.m_pMemory[v7].m_Index;
        if ( m_Index != -1
          && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
          && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
        {
          frameTimea = v5;
          ((void (__stdcall *)(_DWORD))m_pEntity->__vftable[65].SetRefEHandle)(a1: LODWORD(frameTimea));
          if ( this->m_ActiveScenes.m_Size < m_Size )
          {
            m_Size = this->m_ActiveScenes.m_Size;
            --v7;
          }
        }
        else
        {
          needCleanupPass = true;
        }
        ++v7;
      }
      while ( v7 < m_Size );
      if ( needCleanupPass )
      {
        for ( i = m_Size - 1; i >= 0; --i )
        {
          v11 = this->m_Scenes.m_Memory.m_pMemory[i].m_Index;
          if ( v11 == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11)
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity == nullptr )
          {
            if ( this->m_Scenes.m_Size - i - 1 > 0 )
              _V_memmove(
                dest: &this->m_Scenes.m_Memory.m_pMemory[i],
                src: &this->m_Scenes.m_Memory.m_pMemory[i + 1],
                count: 4 * (this->m_Scenes.m_Size - i - 1));
            --this->m_Scenes.m_Size;
          }
        }
        for ( j = this->m_ActiveScenes.m_Size - 1; j >= 0; --j )
        {
          v13 = this->m_ActiveScenes.m_Memory.m_pMemory[j].m_Index;
          if ( v13 == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13)
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity == nullptr )
          {
            if ( this->m_ActiveScenes.m_Size - j - 1 > 0 )
              _V_memmove(
                dest: &this->m_ActiveScenes.m_Memory.m_pMemory[j],
                src: &this->m_ActiveScenes.m_Memory.m_pMemory[j + 1],
                count: 4 * (this->m_ActiveScenes.m_Size - j - 1));
            --this->m_ActiveScenes.m_Size;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203420
// Name: public: void CSceneManager::DeactivateScene(class CSceneEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManager::DeactivateScene(CSceneManager *this, unsigned int scene)
{
  int v3; // eax

  if ( scene != 0 )
    scene = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)scene + 8))(a1: scene);
  else
    scene = -1;
  v3 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&this->m_ActiveScenes,
         src: (CHandle<CBaseEntity> *)&scene);
  if ( v3 != -1 )
  {
    if ( this->m_ActiveScenes.m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: &this->m_ActiveScenes.m_Memory.m_pMemory[v3],
        src: &this->m_ActiveScenes.m_Memory.m_pMemory[v3 + 1],
        count: 4 * (this->m_ActiveScenes.m_Size - v3 - 1));
    --this->m_ActiveScenes.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203850
// Name: public: CSceneListManager::CSceneListManager(void)
// Source: json
//------------------------------------------------------------------------------
CSceneListManager *__thiscall CSceneListManager::CSceneListManager(CSceneListManager *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CSceneListManager_vtbl *)&CSceneListManager::`vftable';
  this->m_hListManagers.m_Memory.m_pMemory = nullptr;
  this->m_hListManagers.m_Memory.m_nAllocationCount = 0;
  this->m_hListManagers.m_Memory.m_nGrowSize = 0;
  this->m_hListManagers.m_Size = 0;
  this->m_hListManagers.m_pElements = nullptr;
  this->m_hScenes[0].m_Index = -1;
  this->m_hScenes[1].m_Index = -1;
  this->m_hScenes[2].m_Index = -1;
  this->m_hScenes[3].m_Index = -1;
  this->m_hScenes[4].m_Index = -1;
  this->m_hScenes[5].m_Index = -1;
  this->m_hScenes[6].m_Index = -1;
  this->m_hScenes[7].m_Index = -1;
  this->m_hScenes[8].m_Index = -1;
  this->m_hScenes[9].m_Index = -1;
  this->m_hScenes[10].m_Index = -1;
  this->m_hScenes[11].m_Index = -1;
  this->m_hScenes[12].m_Index = -1;
  this->m_hScenes[13].m_Index = -1;
  this->m_hScenes[14].m_Index = -1;
  this->m_hScenes[15].m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102038F0
// Name: public: static void UtlVectorTemplate<class CHandle<class CBaseFlex>,class CUtlMemory<class CHandle<class CBaseFlex>,int>>::EnsureCapacity(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UtlVectorTemplate<CHandle<CBaseFlex>,CUtlMemory<CHandle<CBaseFlex>,int>>::EnsureCapacity(
        char *pStruct,
        int offsetToUtlVector,
        int len)
{
  char *v3; // ebx
  void *v4; // edx
  void *v5; // eax
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // [esp-4h] [ebp-10h]

  v3 = &pStruct[offsetToUtlVector + 4];
  if ( *(_DWORD *)v3 < len && *(int *)&pStruct[offsetToUtlVector + 8] >= 0 )
  {
    v4 = *(void **)&pStruct[offsetToUtlVector];
    *(_DWORD *)v3 = len;
    v8 = 4 * len;
    if ( v4 != nullptr )
      v5 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v4, a3: v8);
    else
      v5 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v8);
    *(_DWORD *)&pStruct[offsetToUtlVector] = v5;
  }
  v6 = *(_DWORD *)&pStruct[offsetToUtlVector];
  v7 = *(_DWORD *)v3;
  *(_DWORD *)&pStruct[offsetToUtlVector + 16] = v6;
  memset(
    dst: (unsigned __int8 *)(v6 + 4 * *(_DWORD *)&pStruct[offsetToUtlVector + 12]),
    value: 0,
    count: 4 * (v7 - *(_DWORD *)&pStruct[offsetToUtlVector + 12]));
}

//------------------------------------------------------------------------------
// Address: 0x102047E0
// Name: public: void CSceneEntity::SetCurrentTime(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::SetCurrentTime(CSceneEntity *this, float t, bool bForceClientSync)
{
  float v3; // xmm0_4
  CNetworkVarBase<float,CSceneEntity::NetworkVar_m_flForceClientTime> *p_m_flForceClientTime; // esi
  edict_t *m_pPev; // ecx

  v3 = t;
  this->m_flCurrentTime = t;
  if ( gpGlobals->maxClients == 1 || bForceClientSync )
  {
    p_m_flForceClientTime = &this->m_flForceClientTime;
    if ( this->m_flForceClientTime.m_Value != t )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_flForceClientTime->m_Value = t;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
          v3 = t;
        }
        p_m_flForceClientTime->m_Value = v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204860
// Name: public: virtual void CSceneEntity::DispatchProcessLoop(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchProcessLoop(CSceneEntity *this, CChoreoScene *scene, CChoreoEvent *event)
{
  const char *Parameters; // eax
  int Count; // eax
  float v7; // xmm0_4
  edict_t *m_pPev; // ecx
  float backtime; // [esp+18h] [ebp+Ch]

  if ( !this->m_bRestoring )
  {
    Parameters = CChoreoEvent::GetParameters(this: event);
    backtime = atof(nptr: Parameters);
    if ( CChoreoEvent::GetLoopCount(this: event) != -1 )
    {
      Count = CBaseAchievement::GetCount(this: event);
      if ( Count <= 0 )
        return;
      CChoreoEvent::SetNumLoopsRemaining(this: event, loops: Count - 1);
    }
    CBreakable::SetDmgModExplosive(this: scene, t: backtime);
    v7 = backtime;
    this->m_flCurrentTime = backtime;
    if ( this->m_flForceClientTime.m_Value != backtime )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flForceClientTime.m_Value = backtime;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
          v7 = backtime;
        }
        this->m_flForceClientTime.m_Value = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204920
// Name: public: void CSceneEntity::InputSetTarget1(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputSetTarget1(CSceneEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  bool v5; // sf
  edict_t *m_pPev; // ecx
  CBaseEntity *NamedTarget; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
LABEL_7:
      iVal = nullptr;
      goto LABEL_8;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  if ( iVal == nullptr || *iVal == 0 )
    goto LABEL_7;
LABEL_8:
  this->m_iszTarget1.pszValue = iVal;
  v5 = this->m_hActorList.m_Memory.m_nGrowSize < 0;
  this->m_hActorList.m_Size = 0;
  if ( !v5 )
  {
    if ( this->m_hActorList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hActorList.m_Memory.m_pMemory);
      this->m_hActorList.m_Memory.m_pMemory = nullptr;
    }
    this->m_hActorList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_hActorList.m_pElements = this->m_hActorList.m_Memory.m_pMemory;
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
  {
    m_pPev->m_fStateFlags |= 0x101u;
    CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
  }
  NamedTarget = CSceneEntity::FindNamedTarget(this, iszTarget: this->m_iszTarget1, bBaseFlexOnly: false);
  if ( NamedTarget != nullptr )
    this->m_hTarget1.m_Index = NamedTarget->GetRefEHandle(this: NamedTarget)->m_Index;
  else
    this->m_hTarget1.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x102049F0
// Name: public: void CSceneEntity::InputSetTarget2(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputSetTarget2(CSceneEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  bool v5; // sf
  edict_t *m_pPev; // ecx
  CBaseEntity *NamedTarget; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
LABEL_7:
      iVal = nullptr;
      goto LABEL_8;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  if ( iVal == nullptr || *iVal == 0 )
    goto LABEL_7;
LABEL_8:
  this->m_iszTarget2.pszValue = iVal;
  v5 = this->m_hActorList.m_Memory.m_nGrowSize < 0;
  this->m_hActorList.m_Size = 0;
  if ( !v5 )
  {
    if ( this->m_hActorList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hActorList.m_Memory.m_pMemory);
      this->m_hActorList.m_Memory.m_pMemory = nullptr;
    }
    this->m_hActorList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_hActorList.m_pElements = this->m_hActorList.m_Memory.m_pMemory;
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
  {
    m_pPev->m_fStateFlags |= 0x101u;
    CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
  }
  NamedTarget = CSceneEntity::FindNamedTarget(this, iszTarget: this->m_iszTarget2, bBaseFlexOnly: false);
  if ( NamedTarget != nullptr )
    this->m_hTarget2.m_Index = NamedTarget->GetRefEHandle(this: NamedTarget)->m_Index;
  else
    this->m_hTarget2.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10204AC0
// Name: public: void CSceneEntity::InputSetTarget3(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputSetTarget3(CSceneEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  bool v5; // sf
  edict_t *m_pPev; // ecx
  CBaseEntity *NamedTarget; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
LABEL_7:
      iVal = nullptr;
      goto LABEL_8;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  if ( iVal == nullptr || *iVal == 0 )
    goto LABEL_7;
LABEL_8:
  this->m_iszTarget3.pszValue = iVal;
  v5 = this->m_hActorList.m_Memory.m_nGrowSize < 0;
  this->m_hActorList.m_Size = 0;
  if ( !v5 )
  {
    if ( this->m_hActorList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hActorList.m_Memory.m_pMemory);
      this->m_hActorList.m_Memory.m_pMemory = nullptr;
    }
    this->m_hActorList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_hActorList.m_pElements = this->m_hActorList.m_Memory.m_pMemory;
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
  {
    m_pPev->m_fStateFlags |= 0x101u;
    CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
  }
  NamedTarget = CSceneEntity::FindNamedTarget(this, iszTarget: this->m_iszTarget3, bBaseFlexOnly: false);
  if ( NamedTarget != nullptr )
    this->m_hTarget3.m_Index = NamedTarget->GetRefEHandle(this: NamedTarget)->m_Index;
  else
    this->m_hTarget3.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10204B90
// Name: public: void CSceneEntity::InputSetTarget4(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputSetTarget4(CSceneEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  bool v5; // sf
  edict_t *m_pPev; // ecx
  CBaseEntity *NamedTarget; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
LABEL_7:
      iVal = nullptr;
      goto LABEL_8;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  if ( iVal == nullptr || *iVal == 0 )
    goto LABEL_7;
LABEL_8:
  this->m_iszTarget4.pszValue = iVal;
  v5 = this->m_hActorList.m_Memory.m_nGrowSize < 0;
  this->m_hActorList.m_Size = 0;
  if ( !v5 )
  {
    if ( this->m_hActorList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hActorList.m_Memory.m_pMemory);
      this->m_hActorList.m_Memory.m_pMemory = nullptr;
    }
    this->m_hActorList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_hActorList.m_pElements = this->m_hActorList.m_Memory.m_pMemory;
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
  {
    m_pPev->m_fStateFlags |= 0x101u;
    CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
  }
  NamedTarget = CSceneEntity::FindNamedTarget(this, iszTarget: this->m_iszTarget4, bBaseFlexOnly: false);
  if ( NamedTarget != nullptr )
    this->m_hTarget4.m_Index = NamedTarget->GetRefEHandle(this: NamedTarget)->m_Index;
  else
    this->m_hTarget4.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10204C60
// Name: public: virtual void CSceneEntity::OnLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::OnLoaded(CSceneEntity *this)
{
  bool v1; // bl
  CNetworkVarBase<bool,CSceneEntity::NetworkVar_m_bMultiplayer> *p_m_bMultiplayer; // esi
  edict_t *m_pPev; // ecx

  v1 = gpGlobals->maxClients > 1;
  p_m_bMultiplayer = &this->m_bMultiplayer;
  if ( this->m_bMultiplayer.m_Value != v1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bMultiplayer->m_Value = v1;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3AAu);
      p_m_bMultiplayer->m_Value = v1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204CB0
// Name: public: void CSceneEntity::PrefetchSpeakEventSounds(class CUtlSymbolTable __near &,class CUtlRBTree<struct CSceneEntity::SpeakEventSound_t,unsigned short,bool (*)(struct CSceneEntity::SpeakEventSound_t const __near &,struct CSceneEntity::SpeakEventSound_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSceneEntity::SpeakEventSound_t,unsigned short>,unsigned short>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::PrefetchSpeakEventSounds(
        CSceneEntity *this,
        CUtlSymbolTable *table,
        CUtlRBTree<CSceneEntity::SpeakEventSound_t,unsigned short,bool (__cdecl*)(CSceneEntity::SpeakEventSound_t const &,CSceneEntity::SpeakEventSound_t const &),CUtlMemory<UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short>,unsigned short> > *soundnames)
{
  unsigned __int16 i; // si
  const char *v4; // eax

  for ( i = CUtlRBTree<CSceneEntity::SpeakEventSound_t,unsigned short,bool (__cdecl *)(CSceneEntity::SpeakEventSound_t const &,CSceneEntity::SpeakEventSound_t const &),CUtlMemory<UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short>,unsigned short>>::FirstInorder(this: soundnames);
        i != 0xFFFF;
        i = CUtlRBTree<CSceneEntity::SpeakEventSound_t,unsigned short,bool (__cdecl *)(CSceneEntity::SpeakEventSound_t const &,CSceneEntity::SpeakEventSound_t const &),CUtlMemory<UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short>,unsigned short>>::NextInorder(
              this: soundnames,
              i) )
  {
    v4 = CUtlSymbolTable::String(this: table, id: soundnames->m_Elements.m_pMemory[i].m_Data.m_Symbol);
    CBaseEntity::PrefetchScriptSound(soundname: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204D10
// Name: public: virtual void CSceneEntity::PausePlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::PausePlayback(CSceneEntity *this)
{
  CNetworkVarBase<bool,CSceneEntity::NetworkVar_m_bPaused> *p_m_bPaused; // esi
  edict_t *m_pPev; // ecx

  if ( this->m_bIsPlayingBack.m_Value )
  {
    p_m_bPaused = &this->m_bPaused;
    if ( !this->m_bPaused.m_Value && !p_m_bPaused->m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_bPaused->m_Value = true;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A9u);
        p_m_bPaused->m_Value = true;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204D60
// Name: public: virtual void CSceneEntity::ResumePlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::ResumePlayback(CSceneEntity *this)
{
  CChoreoScene *m_pScene; // ecx
  edict_t *m_pPev; // ecx

  if ( this->m_bIsPlayingBack.m_Value && this->m_bPaused.m_Value )
  {
    m_pScene = this->m_pScene;
    if ( m_pScene != nullptr )
    {
      CChoreoScene::ResumeSimulation(this: m_pScene);
      if ( this->m_bPaused.m_Value )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_bPaused.m_Value = false;
          this->m_bPausedViaInput = false;
          return;
        }
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A9u);
        this->m_bPaused.m_Value = false;
      }
      this->m_bPausedViaInput = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204DE0
// Name: public: virtual void CSceneEntity::CancelPlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::CancelPlayback(CSceneEntity *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  const char *pszValue; // eax

  if ( this->m_bIsPlayingBack.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A8u);
    }
    this->m_bIsPlayingBack.m_Value = false;
    if ( this->m_bPaused.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v3 = this->m_Network.m_pPev;
        if ( v3 != nullptr )
          CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x3A9u);
      }
      this->m_bPaused.m_Value = false;
    }
    COutputEvent::FireOutput(this: &this->m_OnCanceled, pActivator: this, pCaller: this, fDelay: 0.0);
    pszValue = this->m_iszSceneFile.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    Scene_Printf(pFormat: "%s : %8.2f:  canceled\n", pszValue, this->m_flCurrentTime);
    this->OnSceneFinished(this, a2: true, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204EC0
// Name: public: static class CChoreoScene __near * CSceneEntity::LoadScene(char const __near *,class IChoreoEventCallback __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl CSceneEntity::LoadScene(const char *filename, IChoreoEventCallback *pCallback)
{
  unsigned int v2; // eax
  unsigned int v3; // esi
  void *v4; // ebx
  CChoreoScene *v6; // eax
  vgui::Panel *v7; // edi
  char loadfile[260]; // [esp+8h] [ebp-134h] BYREF
  CUtlBuffer buf; // [esp+10Ch] [ebp-30h] BYREF

  _DevMsg(a1: 2, a2: "Blocking load of scene from '%s'\n", filename);
  V_strncpy(pDest: loadfile, pSrc: filename, maxLen: 260);
  V_SetExtension(path: loadfile, extension: ".vcd", pathStringLength: 260);
  V_FixSlashes(pname: loadfile, separator: 92);
  v2 = scenefilecache->GetSceneBufferSize(this: scenefilecache, a2: loadfile);
  v3 = v2;
  if ( v2 != 0
    && (v4 = operator new(nSize: v2),
        scenefilecache->GetSceneData(this: scenefilecache, a2: loadfile, a3: (unsigned __int8 *)v4, a4: v3)) )
  {
    v6 = (CChoreoScene *)operator new(nSize: 0x21Cu);
    if ( v6 != nullptr )
      v7 = (vgui::Panel *)CChoreoScene::CChoreoScene(this: v6, callback: nullptr);
    else
      v7 = nullptr;
    CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v4, nSize: v3, nFlags: 8);
    if ( CChoreoScene::RestoreFromBinaryBuffer(
           this: (CChoreoScene *)v7,
           &buf,
           filename: loadfile,
           pStringPool: &g_ChoreoStringPool) )
    {
      vgui::Panel::SetCursor(this: v7, cursor: (unsigned int)Scene_Printf);
      CChoreoScene::SetEventCallbackInterface(this: (CChoreoScene *)v7, callback: pCallback);
    }
    else
    {
      _Warning(a1: "CSceneEntity::LoadScene: Unable to load binary scene '%s'\n", loadfile);
      if ( v7 != nullptr )
      {
        CChoreoScene::~CChoreoScene(this: (CChoreoScene *)v7);
        free(pMem: v7);
      }
      v7 = nullptr;
    }
    free(pMem: v4);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return v7;
  }
  else
  {
    MissingSceneWarning(scenename: loadfile);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205030
// Name: public: void CSceneEntity::UnloadScene(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::UnloadScene(CSceneEntity *this)
{
  CChoreoScene *m_pScene; // eax
  int i; // edi
  CBaseFlex *v4; // eax
  CChoreoScene *v5; // edi
  CSceneManager *SceneManager; // eax

  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
  {
    CSceneEntity::ClearSceneEvents(this, scene: m_pScene, canceled: false);
    for ( i = 0; i < CChoreoScene::GetNumActors(this: this->m_pScene); ++i )
    {
      v4 = this->FindNamedActor_3(this, a2: i);
      if ( v4 != nullptr )
        CBaseFlex::RemoveChoreoScene(this: v4, scene: this->m_pScene, canceled: false);
    }
  }
  v5 = this->m_pScene;
  if ( v5 != nullptr )
  {
    CChoreoScene::~CChoreoScene(this: this->m_pScene);
    free(pMem: v5);
  }
  this->m_pScene = nullptr;
  if ( GetSceneManager() != nullptr )
  {
    SceneManager = GetSceneManager();
    CSceneManager::DeactivateScene(this: SceneManager, scene: (unsigned int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102050D0
// Name: private: void CSceneEntity::ClearSchedules(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::ClearSchedules(CSceneEntity *this, CChoreoScene *scene)
{
  CSceneEntity *v2; // esi
  CChoreoScene *m_pScene; // ecx
  int v4; // edi
  int v5; // esi
  int v6; // eax
  CBaseEdict *v7; // ecx
  int i; // edi
  CChoreoEvent *Event; // eax
  vgui::Panel *v10; // esi
  CChoreoScene *SubScene; // eax
  CSceneEntity *v12; // [esp+4h] [ebp-4h]

  v2 = this;
  m_pScene = this->m_pScene;
  v12 = v2;
  if ( m_pScene != nullptr )
  {
    v4 = 0;
    if ( CChoreoScene::GetNumActors(this: m_pScene) > 0 )
    {
      while ( 1 )
      {
        v5 = (int)v2->FindNamedActor_3(this: v2, a2: v4);
        if ( v5 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 296))(a1: v5) == 0 )
        {
          v6 = CBaseAnimating::SelectWeightedSequence(this: (CBaseAnimating *)v5, activity: ACT_IDLE);
          CBaseAnimating::ResetSequence(this: (CBaseAnimating *)v5, nSequence: v6);
          if ( *(float *)(v5 + 940) != 0.0 )
          {
            if ( *(_BYTE *)(v5 + 84) != 0 )
            {
              *(_BYTE *)(v5 + 88) |= 1u;
            }
            else
            {
              v7 = *(CBaseEdict **)(v5 + 24);
              if ( v7 != nullptr )
                CBaseEdict::StateChanged(this: v7, offset: 0x3ACu);
            }
            *(_DWORD *)(v5 + 940) = 0;
          }
        }
        if ( ++v4 >= CChoreoScene::GetNumActors(this: v12->m_pScene) )
          break;
        v2 = v12;
      }
    }
    for ( i = 0; i < vgui::Image::GetTall(this: (vgui::Image *)scene); ++i )
    {
      Event = CChoreoScene::GetEvent(this: scene, event: i);
      v10 = (vgui::Panel *)Event;
      if ( Event != nullptr && CChoreoEvent::GetType(this: Event) == SUBSCENE && !CChoreoScene::IsSubScene(this: scene) )
      {
        SubScene = (CChoreoScene *)CChoreoEvent::GetSubScene(this: v10);
        if ( SubScene != nullptr )
          CSceneEntity::ClearSchedules(this: v12, scene: SubScene);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102051F0
// Name: public: void CSceneEntity::ClearActivatorTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::ClearActivatorTargets(CSceneEntity *this)
{
  const char *pszValue; // eax
  edict_t *m_pPev; // ecx
  const char *v4; // eax
  edict_t *v5; // ecx
  const char *v6; // eax
  edict_t *v7; // ecx
  const char *v8; // eax
  edict_t *v9; // ecx
  const char *v10; // eax
  edict_t *v11; // ecx
  const char *v12; // eax
  edict_t *v13; // ecx
  const char *v14; // eax
  edict_t *v15; // ecx
  const char *v16; // eax
  edict_t *v17; // ecx

  pszValue = this->m_iszTarget1.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( _V_stricmp(s1: pszValue, s2: "!activator") == 0 )
  {
    this->m_hActorList.m_Size = 0;
    if ( this->m_hActorList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_hActorList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hActorList.m_Memory.m_pMemory);
        this->m_hActorList.m_Memory.m_pMemory = nullptr;
      }
      this->m_hActorList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_hActorList.m_pElements = this->m_hActorList.m_Memory.m_pMemory;
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      m_pPev->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
    this->m_hTarget1.m_Index = -1;
  }
  v4 = this->m_iszTarget2.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  if ( _V_stricmp(s1: v4, s2: "!activator") == 0 )
  {
    this->m_hActorList.m_Size = 0;
    if ( this->m_hActorList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_hActorList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hActorList.m_Memory.m_pMemory);
        this->m_hActorList.m_Memory.m_pMemory = nullptr;
      }
      this->m_hActorList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_hActorList.m_pElements = this->m_hActorList.m_Memory.m_pMemory;
    v5 = this->m_Network.m_pPev;
    if ( v5 != nullptr )
    {
      v5->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v5->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
    this->m_hTarget2.m_Index = -1;
  }
  v6 = this->m_iszTarget3.pszValue;
  if ( v6 == nullptr )
    v6 = locale;
  if ( _V_stricmp(s1: v6, s2: "!activator") == 0 )
  {
    this->m_hActorList.m_Size = 0;
    if ( this->m_hActorList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_hActorList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hActorList.m_Memory.m_pMemory);
        this->m_hActorList.m_Memory.m_pMemory = nullptr;
      }
      this->m_hActorList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_hActorList.m_pElements = this->m_hActorList.m_Memory.m_pMemory;
    v7 = this->m_Network.m_pPev;
    if ( v7 != nullptr )
    {
      v7->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v7->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
    this->m_hTarget3.m_Index = -1;
  }
  v8 = this->m_iszTarget4.pszValue;
  if ( v8 == nullptr )
    v8 = locale;
  if ( _V_stricmp(s1: v8, s2: "!activator") == 0 )
  {
    this->m_hActorList.m_Size = 0;
    if ( this->m_hActorList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_hActorList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hActorList.m_Memory.m_pMemory);
        this->m_hActorList.m_Memory.m_pMemory = nullptr;
      }
      this->m_hActorList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_hActorList.m_pElements = this->m_hActorList.m_Memory.m_pMemory;
    v9 = this->m_Network.m_pPev;
    if ( v9 != nullptr )
    {
      v9->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v9->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
    this->m_hTarget4.m_Index = -1;
  }
  v10 = this->m_iszTarget5.pszValue;
  if ( v10 == nullptr )
    v10 = locale;
  if ( _V_stricmp(s1: v10, s2: "!activator") == 0 )
  {
    this->m_hActorList.m_Size = 0;
    if ( this->m_hActorList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_hActorList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hActorList.m_Memory.m_pMemory);
        this->m_hActorList.m_Memory.m_pMemory = nullptr;
      }
      this->m_hActorList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_hActorList.m_pElements = this->m_hActorList.m_Memory.m_pMemory;
    v11 = this->m_Network.m_pPev;
    if ( v11 != nullptr )
    {
      v11->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v11->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
    this->m_hTarget5.m_Index = -1;
  }
  v12 = this->m_iszTarget6.pszValue;
  if ( v12 == nullptr )
    v12 = locale;
  if ( _V_stricmp(s1: v12, s2: "!activator") == 0 )
  {
    this->m_hActorList.m_Size = 0;
    if ( this->m_hActorList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_hActorList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hActorList.m_Memory.m_pMemory);
        this->m_hActorList.m_Memory.m_pMemory = nullptr;
      }
      this->m_hActorList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_hActorList.m_pElements = this->m_hActorList.m_Memory.m_pMemory;
    v13 = this->m_Network.m_pPev;
    if ( v13 != nullptr )
    {
      v13->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v13->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
    this->m_hTarget6.m_Index = -1;
  }
  v14 = this->m_iszTarget7.pszValue;
  if ( v14 == nullptr )
    v14 = locale;
  if ( _V_stricmp(s1: v14, s2: "!activator") == 0 )
  {
    this->m_hActorList.m_Size = 0;
    if ( this->m_hActorList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_hActorList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hActorList.m_Memory.m_pMemory);
        this->m_hActorList.m_Memory.m_pMemory = nullptr;
      }
      this->m_hActorList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_hActorList.m_pElements = this->m_hActorList.m_Memory.m_pMemory;
    v15 = this->m_Network.m_pPev;
    if ( v15 != nullptr )
    {
      v15->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v15->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
    this->m_hTarget7.m_Index = -1;
  }
  v16 = this->m_iszTarget8.pszValue;
  if ( v16 == nullptr )
    v16 = locale;
  if ( _V_stricmp(s1: v16, s2: "!activator") == 0 )
  {
    this->m_hActorList.m_Size = 0;
    if ( this->m_hActorList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_hActorList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hActorList.m_Memory.m_pMemory);
        this->m_hActorList.m_Memory.m_pMemory = nullptr;
      }
      this->m_hActorList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_hActorList.m_pElements = this->m_hActorList.m_Memory.m_pMemory;
    v17 = this->m_Network.m_pPev;
    if ( v17 != nullptr )
    {
      v17->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v17->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
    this->m_hTarget8.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205600
// Name: public: virtual void CSceneEntity::OnSceneFinished(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSceneEntity::OnSceneFinished(CSceneEntity *this@<ecx>, int a2@<edi>, BOOL canceled, bool fireoutput)
{
  const char *pszValue; // eax
  int m_Size; // ebx
  int i; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  edict_t *m_pPev; // ecx
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  CBaseFlex *v13; // eax
  CBaseFlex *v14; // edi
  void *v15; // eax
  int v16; // eax
  void *v17; // eax
  int j; // ebx
  CBaseFlex *v19; // edi
  CSceneManager *SceneManager; // eax

  if ( this->m_pScene == nullptr )
    return;
  pszValue = this->m_iszSceneFile.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  Scene_Printf(pFormat: "%s : %8.2f:  finished\n", pszValue, this->m_flCurrentTime);
  m_Size = this->m_hNotifySceneCompletion.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    m_Index = this->m_hNotifySceneCompletion.m_Memory.m_pMemory[i].m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
        ((void (__thiscall *)(IHandleEntity *, CSceneEntity *))m_pEntity->__vftable[67].dtr_IHandleEntity)(
          a1: m_pEntity,
          a2: this);
    }
  }
  this->m_hNotifySceneCompletion.m_Size = 0;
  CChoreoScene::ResetSimulation(this: this->m_pScene, forward: true, starttime: 0.0, endtime: 0.0);
  if ( this->m_bIsPlayingBack.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A8u);
    }
    this->m_bIsPlayingBack.m_Value = false;
  }
  if ( this->m_bPaused.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x3A9u);
    }
    this->m_bPaused.m_Value = false;
  }
  this->m_flCurrentTime = 0.0;
  if ( gpGlobals->maxClients == 1 && this->m_flForceClientTime.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x3ACu);
    }
    this->m_flForceClientTime.m_Value = 0.0;
  }
  ((void (__thiscall *)(CSceneEntity *, int))this->ClearInterrupt)(a1: this, a2);
  if ( fireoutput && !this->m_bCompletedEarly )
    COutputEvent::FireOutput(this: &this->m_OnCompletion, pActivator: this, pCaller: this, fDelay: 0.0);
  v13 = this->FindNamedActor_3(this, a2: 0);
  v14 = v13;
  if ( v13 != nullptr )
  {
    v15 = __RTDynamicCast(
            inptr: v13,
            VfDelta: 0,
            SrcType: &CBaseFlex `RTTI Type Descriptor',
            TargetType: &CBaseMultiplayerPlayer `RTTI Type Descriptor',
            isReference: 0);
    if ( v15 != nullptr )
    {
      v16 = (*(int (__thiscall **)(void *))(*(_DWORD *)v15 + 1916))(a1: v15);
    }
    else
    {
      v17 = __RTDynamicCast(
              inptr: v14,
              VfDelta: 0,
              SrcType: &CBaseFlex `RTTI Type Descriptor',
              TargetType: &CAI_BaseActor `RTTI Type Descriptor',
              isReference: 0);
      if ( v17 == nullptr )
        goto LABEL_38;
      v16 = (*(int (__thiscall **)(void *))(*(_DWORD *)v17 + 1900))(a1: v17);
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 12))(a1: v16);
  }
LABEL_38:
  CSceneEntity::ClearSceneEvents(this, scene: this->m_pScene, canceled);
  for ( j = 0; j < CChoreoScene::GetNumActors(this: this->m_pScene); ++j )
  {
    v19 = this->FindNamedActor_3(this, a2: j);
    if ( v19 != nullptr )
    {
      CBaseFlex::RemoveChoreoScene(this: v19, scene: this->m_pScene, canceled);
      if ( this->m_bInterruptedActorsScenes )
      {
        SceneManager = GetSceneManager();
        CSceneManager::QueueActorsScenesToResume(this: SceneManager, pActor: v19, bInstancedOnly: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205890
// Name: float InstancedScriptedScene(class CBaseFlex __near *,char const __near *,class CHandle<class CBaseEntity> __near *,float,bool,class ResponseRules::CRR_Response __near *,bool,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
float __cdecl InstancedScriptedScene(
        CBaseFlex *pActor,
        const char *pszScene,
        CHandle<CBaseEntity> *phSceneEnt,
        float flPostDelay,
        BOOL bIsBackground,
        ResponseRules::CRR_Response *response,
        float bMultiplayer,
        CRecipientFilter *filter)
{
  CBaseEntity *NoSpawn; // eax
  CBaseEntity *v9; // esi
  char *p_m_ListByClass; // ebx
  CBaseEdict *v11; // ecx
  CChoreoScene *pszValue; // ecx
  CRecipientFilter *v13; // eax
  CRecipientFilter *v14; // eax
  double PreDelay; // st7

  NoSpawn = CBaseEntity::CreateNoSpawn(
              szName: "instanced_scripted_scene",
              vecOrigin: &vec3_origin,
              vecAngles: &vec3_angle,
              pOwner: nullptr);
  v9 = NoSpawn;
  p_m_ListByClass = (char *)&NoSpawn[1].m_ListByClass;
  if ( pActor != nullptr )
    CBaseEntity::GenderExpandString(this: pActor, in: pszScene, out: p_m_ListByClass, maxlen: 128);
  else
    V_strncpy(pDest: (char *)&NoSpawn[1].m_ListByClass, pSrc: pszScene, maxLen: 128);
  if ( p_m_ListByClass == nullptr || *p_m_ListByClass == 0 )
    p_m_ListByClass = nullptr;
  v9[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))p_m_ListByClass;
  if ( pActor != nullptr )
    v9[1].m_RefEHandle.m_Index = pActor->GetRefEHandle(this: pActor)->m_Index;
  else
    v9[1].m_RefEHandle.m_Index = -1;
  LOBYTE(v9[1].m_vecViewOffset.m_Value.x) = pActor != nullptr;
  if ( *(&v9[1].m_Network.m_TimerEvent.m_bRegistered + 2) != LOBYTE(bMultiplayer) )
  {
    if ( v9->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v9->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = &v9->m_Network.m_pPev->CBaseEdict;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: v11, offset: 0x3AAu);
    }
    *(&v9[1].m_Network.m_TimerEvent.m_bRegistered + 2) = LOBYTE(bMultiplayer);
  }
  ((void (__thiscall *)(CBaseEntity *, _DWORD))v9->__vftable[1].RequiredEdictIndex)(a1: v9, a2: LODWORD(flPostDelay));
  DispatchSpawn(pEntity: v9, bRunVScripts: true);
  v9->Activate(this: v9);
  pszValue = (CChoreoScene *)v9[1].m_OnUser4.m_Value.iszVal.pszValue;
  LOBYTE(v9[2].m_Network.__vftable) = bIsBackground;
  if ( pszValue != nullptr )
    CChoreoScene::SetBackground(this: pszValue, bIsBackground);
  if ( filter != nullptr )
  {
    v13 = (CRecipientFilter *)operator new(nSize: 0x20u);
    if ( v13 != nullptr )
      v14 = CRecipientFilter::CRecipientFilter(this: v13);
    else
      v14 = nullptr;
    LODWORD(v9[1].m_angRotation.m_Value.z) = v14;
    CRecipientFilter::CopyFrom(this: v14, src: filter);
  }
  if ( response != nullptr )
  {
    PreDelay = ResponseRules::CRR_Response::GetPreDelay(this: response);
    bMultiplayer = PreDelay;
    if ( PreDelay != 0.0 )
      ((void (__thiscall *)(CBaseEntity *, float))v9->__vftable[1].Think)(
        a1: v9,
        a2: COERCE_FLOAT(LODWORD(bMultiplayer)));
  }
  ((void (__thiscall *)(CBaseEntity *))v9->__vftable[1].SetModelIndex)(a1: v9);
  if ( response != nullptr )
    BYTE2(v9[1].m_aThinkFunctions.m_Memory.m_nGrowSize) = ResponseRules::CRR_Response::ShouldBreakOnNonIdle(this: response);
  if ( phSceneEnt != nullptr )
    phSceneEnt->m_Index = v9->GetRefEHandle(this: v9)->m_Index;
  return ((float (__thiscall *)(CBaseEntity *, CBaseFlex *, const char *, CHandle<CBaseEntity> *, _DWORD, BOOL, ResponseRules::CRR_Response *, float))v9->__vftable[1].GetPlayerName)(
           a1: v9,
           a2: pActor,
           a3: pszScene,
           a4: phSceneEnt,
           a5: LODWORD(flPostDelay),
           a6: bIsBackground,
           a7: response,
           a8: COERCE_FLOAT(LODWORD(bMultiplayer)));
}

//------------------------------------------------------------------------------
// Address: 0x10205A40
// Name: public: virtual void CInstancedSceneEntity::DoThink(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInstancedSceneEntity::DoThink(CInstancedSceneEntity *this, float frametime)
{
  float m_flPreDelay; // xmm0_4
  float v4; // xmm0_4
  void (__thiscall *StartPlayback)(struct CInstancedSceneEntity *); // edx
  float m_fPitch; // xmm0_4
  int v7; // xmm1_4
  bool v8; // zf
  float v9; // xmm0_4
  edict_t *m_pPev; // ecx
  float flTime; // [esp+8h] [ebp-4h]

  this->CheckInterruptCompletion(this);
  m_flPreDelay = this->m_flPreDelay;
  if ( m_flPreDelay <= 0.0 )
    goto LABEL_27;
  v4 = m_flPreDelay - frametime;
  if ( v4 < 0.0 )
    v4 = 0.0;
  StartPlayback = this->StartPlayback;
  this->m_flPreDelay = v4;
  StartPlayback(this);
  if ( this->m_bIsPlayingBack.m_Value )
  {
LABEL_27:
    if ( this->m_pScene == nullptr
      || !this->m_bIsPlayingBack.m_Value
      || this->m_bHadOwner && CHandle<CBaseEntity>::operator==(this: &this->m_hOwner, val: nullptr) )
    {
      goto LABEL_24;
    }
    m_fPitch = this->m_fPitch;
    v7 = 1048576000;
    if ( m_fPitch < 0.25 || (v7 = 1075838976, m_fPitch > 2.5) )
      m_fPitch = *(float *)&v7;
    v8 = !this->m_bPaused.m_Value;
    this->m_fPitch = m_fPitch;
    if ( !v8 )
    {
      this->PauseThink(this);
      return;
    }
    flTime = engine->GetLatencyForChoreoSounds(this: engine);
    CChoreoScene::SetSoundFileStartupLatency(this: this->m_pScene, flTime);
    CChoreoScene::Think(this: this->m_pScene, curtime: this->m_flCurrentTime);
    v9 = (float)(this->m_fPitch * frametime) + this->m_flCurrentTime;
    this->m_flCurrentTime = v9;
    if ( gpGlobals->maxClients == 1 && this->m_flForceClientTime.m_Value != v9 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
      }
      this->m_flForceClientTime.m_Value = v9;
    }
    if ( CChoreoScene::SimulationFinished(this: this->m_pScene) || this->m_bCompletedEarly )
    {
      this->OnSceneFinished(this, a2: false, a3: false);
LABEL_24:
      UTIL_Remove(oldObj: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205C00
// Name: private: bool CInstancedSceneEntity::PassThrough(class CBaseFlex __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInstancedSceneEntity::PassThrough(CInstancedSceneEntity *this, CBaseFlex *actor)
{
  CAI_BaseNPC *v4; // eax
  CAI_BaseNPC *v5; // esi
  CAI_Schedule *m_pSchedule; // ecx
  const char *pszValue; // eax
  CBitVec<256> testBits; // [esp+4h] [ebp-20h] BYREF

  if ( actor == nullptr )
    return 0;
  v4 = actor->MyNPCPointer(this: actor);
  v5 = v4;
  if ( v4 != nullptr )
  {
    if ( CAI_BaseNPC::IsCurSchedule(this: v4, schedId: 63, fIdeal: true) )
      return 1;
    m_pSchedule = v5->m_pSchedule;
    if ( m_pSchedule != nullptr )
    {
      memset(&testBits, 0, sizeof(testBits));
      CAI_Schedule::GetInterruptMask(this: m_pSchedule, pBits: &testBits);
      if ( (testBits.m_Ints[0] & 4) != 0 )
        return 1;
    }
    pszValue = this->m_iszSceneFile.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    Scene_Printf(pFormat: "%s : event suppressed\n", pszValue);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10205CA0
// Name: public: virtual void CInstancedSceneEntity::OnLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInstancedSceneEntity::OnLoaded(CInstancedSceneEntity *this)
{
  bool v2; // bl
  edict_t *m_pPev; // ecx
  CChoreoScene *m_pScene; // ecx

  v2 = gpGlobals->maxClients > 1;
  if ( this->m_bMultiplayer.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3AAu);
    }
    this->m_bMultiplayer.m_Value = v2;
  }
  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
    CChoreoScene::SetBackground(this: m_pScene, bIsBackground: this->m_bIsBackground);
}

//------------------------------------------------------------------------------
// Address: 0x10205D00
// Name: public: void CSceneManager::RemoveSceneEntity(class CSceneEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManager::RemoveSceneEntity(CSceneManager *this, CHandle<CSceneEntity> scene)
{
  CSceneEntity *m_Index; // esi
  int v4; // eax

  m_Index = (CSceneEntity *)scene.m_Index;
  CSceneManager::DeactivateScene(this, scene: scene.m_Index);
  if ( m_Index != nullptr )
    scene.m_Index = m_Index->GetRefEHandle(this: m_Index)->m_Index;
  else
    scene.m_Index = -1;
  v4 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&this->m_Scenes,
         src: (CHandle<CBaseEntity> *)&scene);
  if ( v4 != -1 )
  {
    if ( this->m_Scenes.m_Size - v4 - 1 > 0 )
      _V_memmove(
        dest: &this->m_Scenes.m_Memory.m_pMemory[v4],
        src: &this->m_Scenes.m_Memory.m_pMemory[v4 + 1],
        count: 4 * (this->m_Scenes.m_Size - v4 - 1));
    --this->m_Scenes.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205D80
// Name: public: CSceneManager::CSceneManager(void)
// Source: json
//------------------------------------------------------------------------------
CSceneManager *__thiscall CSceneManager::CSceneManager(CSceneManager *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CSceneManager_vtbl *)&CSceneManager::`vftable';
  this->m_ActiveScenes.m_Memory.m_pMemory = nullptr;
  this->m_ActiveScenes.m_Memory.m_nAllocationCount = 0;
  this->m_ActiveScenes.m_Memory.m_nGrowSize = 0;
  this->m_ActiveScenes.m_Size = 0;
  this->m_ActiveScenes.m_pElements = nullptr;
  this->m_Scenes.m_Memory.m_pMemory = nullptr;
  this->m_Scenes.m_Memory.m_nAllocationCount = 0;
  this->m_Scenes.m_Memory.m_nGrowSize = 0;
  this->m_Scenes.m_Size = 0;
  this->m_Scenes.m_pElements = nullptr;
  this->m_QueuedSceneSounds.m_Memory.m_pMemory = nullptr;
  this->m_QueuedSceneSounds.m_Memory.m_nAllocationCount = 0;
  this->m_QueuedSceneSounds.m_Memory.m_nGrowSize = 0;
  this->m_QueuedSceneSounds.m_Size = 0;
  this->m_QueuedSceneSounds.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10205E00
// Name: public: virtual void CSceneManager::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManager::Spawn(CSceneManager *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10205FB0
// Name: public: CSceneEntity::CSceneEntity(void)
// Source: json
//------------------------------------------------------------------------------
CSceneEntity *__thiscall CSceneEntity::CSceneEntity(CSceneEntity *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->IChoreoEventCallback::__vftable = (IChoreoEventCallback_vtbl *)&IChoreoEventCallback::`vftable';
  this->CPointEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CSceneEntity_vtbl *)&CSceneEntity::`vftable'{for `CPointEntity'};
  this->IChoreoEventCallback::__vftable = (IChoreoEventCallback_vtbl *)&CSceneEntity::`vftable'{for `IChoreoEventCallback'};
  this->m_hWaitingForThisResumeScene.m_Index = -1;
  this->m_hTarget1.m_Index = -1;
  this->m_hTarget2.m_Index = -1;
  this->m_hTarget3.m_Index = -1;
  this->m_hTarget4.m_Index = -1;
  this->m_hTarget5.m_Index = -1;
  this->m_hTarget6.m_Index = -1;
  this->m_hTarget7.m_Index = -1;
  this->m_hTarget8.m_Index = -1;
  this->m_hActorList.m_Memory.m_pMemory = nullptr;
  this->m_hActorList.m_Memory.m_nAllocationCount = 0;
  this->m_hActorList.m_Memory.m_nGrowSize = 0;
  this->m_hActorList.m_Size = 0;
  this->m_hActorList.m_pElements = nullptr;
  this->m_hRemoveActorList.m_Memory.m_pMemory = nullptr;
  this->m_hRemoveActorList.m_Memory.m_nAllocationCount = 0;
  this->m_hRemoveActorList.m_Memory.m_nGrowSize = 0;
  this->m_hRemoveActorList.m_Size = 0;
  this->m_hRemoveActorList.m_pElements = nullptr;
  this->m_OnStart.m_Value.iVal = 0;
  this->m_OnStart.m_Value.eVal.m_Index = -1;
  this->m_OnStart.m_Value.fieldType = FIELD_VOID;
  this->m_OnCompletion.m_Value.iVal = 0;
  this->m_OnCompletion.m_Value.eVal.m_Index = -1;
  this->m_OnCompletion.m_Value.fieldType = FIELD_VOID;
  this->m_OnCanceled.m_Value.iVal = 0;
  this->m_OnCanceled.m_Value.eVal.m_Index = -1;
  this->m_OnCanceled.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger1.m_Value.iVal = 0;
  this->m_OnTrigger1.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger1.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger2.m_Value.iVal = 0;
  this->m_OnTrigger2.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger2.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger3.m_Value.iVal = 0;
  this->m_OnTrigger3.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger3.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger4.m_Value.iVal = 0;
  this->m_OnTrigger4.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger4.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger5.m_Value.iVal = 0;
  this->m_OnTrigger5.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger5.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger6.m_Value.iVal = 0;
  this->m_OnTrigger6.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger6.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger7.m_Value.iVal = 0;
  this->m_OnTrigger7.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger7.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger8.m_Value.iVal = 0;
  this->m_OnTrigger8.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger8.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger9.m_Value.iVal = 0;
  this->m_OnTrigger9.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger9.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger10.m_Value.iVal = 0;
  this->m_OnTrigger10.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger10.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger11.m_Value.iVal = 0;
  this->m_OnTrigger11.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger11.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger12.m_Value.iVal = 0;
  this->m_OnTrigger12.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger12.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger13.m_Value.iVal = 0;
  this->m_OnTrigger13.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger13.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger14.m_Value.iVal = 0;
  this->m_OnTrigger14.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger14.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger15.m_Value.iVal = 0;
  this->m_OnTrigger15.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger15.m_Value.fieldType = FIELD_VOID;
  this->m_OnTrigger16.m_Value.iVal = 0;
  this->m_OnTrigger16.m_Value.eVal.m_Index = -1;
  this->m_OnTrigger16.m_Value.fieldType = FIELD_VOID;
  this->m_hInterruptScene.m_Index = -1;
  this->m_hNotifySceneCompletion.m_Memory.m_pMemory = nullptr;
  this->m_hNotifySceneCompletion.m_Memory.m_nAllocationCount = 0;
  this->m_hNotifySceneCompletion.m_Memory.m_nGrowSize = 0;
  this->m_hNotifySceneCompletion.m_Size = 0;
  this->m_hNotifySceneCompletion.m_pElements = nullptr;
  this->m_hListManagers.m_Memory.m_pMemory = nullptr;
  this->m_hListManagers.m_Memory.m_nAllocationCount = 0;
  this->m_hListManagers.m_Memory.m_nGrowSize = 0;
  this->m_hListManagers.m_Size = 0;
  this->m_hListManagers.m_pElements = nullptr;
  this->m_hActor.m_Index = -1;
  this->m_hActivator.m_Index = -1;
  *(_WORD *)&this->m_bWaitingForActor = 0;
  this->m_bInterruptedActorsScenes = false;
  if ( this->m_bIsPlayingBack.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A8u);
    }
    this->m_bIsPlayingBack.m_Value = false;
  }
  if ( this->m_bPaused.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x3A9u);
    }
    this->m_bPaused.m_Value = false;
  }
  if ( this->m_bMultiplayer.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x3AAu);
    }
    this->m_bMultiplayer.m_Value = false;
  }
  this->m_fPitch = 1.0;
  this->m_iszSceneFile.pszValue = nullptr;
  this->m_iszResumeSceneFile.pszValue = nullptr;
  this->m_hWaitingForThisResumeScene.m_Index = -1;
  this->m_bWaitingForResumeScene = false;
  this->m_flCurrentTime = 0.0;
  if ( gpGlobals->maxClients == 1 && this->m_flForceClientTime.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x3ACu);
    }
    this->m_flForceClientTime.m_Value = 0.0;
  }
  this->m_bCancelAtNextInterrupt = false;
  this->m_bAutomated = false;
  this->m_nAutomatedAction = 0;
  this->m_bPausedViaInput = false;
  this->m_nInterruptCount = 0;
  this->m_bInterrupted = false;
  this->m_flAutomationDelay = 0.0;
  this->m_flAutomationTime = 0.0;
  this->m_hInterruptScene.m_Index = -1;
  this->m_pScene = nullptr;
  this->m_bCompletedEarly = false;
  this->m_BusyActor = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10206380
// Name: public: virtual CSceneEntity::~CSceneEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::~CSceneEntity(CSceneEntity *this)
{
  CRecipientFilter *m_pRecipientFilter; // ecx

  m_pRecipientFilter = this->m_pRecipientFilter;
  this->CPointEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CSceneEntity_vtbl *)&CSceneEntity::`vftable'{for `CPointEntity'};
  this->IChoreoEventCallback::__vftable = (IChoreoEventCallback_vtbl *)&CSceneEntity::`vftable'{for `IChoreoEventCallback'};
  if ( m_pRecipientFilter != nullptr )
    ((void (__thiscall *)(CRecipientFilter *, int))m_pRecipientFilter->dtr_IRecipientFilter)(
      a1: m_pRecipientFilter,
      a2: 1);
  this->m_pRecipientFilter = nullptr;
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hListManagers);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hNotifySceneCompletion);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger16);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger15);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger14);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger13);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger12);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger11);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger10);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger9);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger8);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger7);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger6);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger5);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger4);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger3);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger2);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnTrigger1);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnCanceled);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnCompletion);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnStart);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hRemoveActorList);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hActorList);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x102064C0
// Name: public: virtual void CSceneEntity::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::UpdateOnRemove(CSceneEntity *this)
{
  CSceneManager *SceneManager; // eax

  CSceneEntity::UnloadScene(this);
  CBaseEntity::UpdateOnRemove(this);
  if ( GetSceneManager() != nullptr )
  {
    SceneManager = GetSceneManager();
    CSceneManager::RemoveSceneEntity(this: SceneManager, scene: (CHandle<CSceneEntity>)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102064F0
// Name: private: void CSceneEntity::PrecacheScene(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::PrecacheScene(CSceneEntity *this, CChoreoScene *scene)
{
  CChoreoScene *v2; // edi
  int i; // ebx
  CChoreoEvent *Event; // eax
  CChoreoEvent *v5; // esi
  CChoreoEvent::EVENTTYPE Type; // eax
  IChoreoEventCallback *v7; // eax
  const char *v8; // eax
  CChoreoScene *v9; // edi
  const char *Parameters; // eax
  IChoreoEventCallback *v11; // [esp-8h] [ebp-54h]
  char tok[64]; // [esp+8h] [ebp-44h] BYREF
  CSceneEntity *v13; // [esp+48h] [ebp-4h]

  v2 = scene;
  v13 = this;
  for ( i = 0; i < vgui::Image::GetTall(this: (vgui::Image *)v2); ++i )
  {
    Event = CChoreoScene::GetEvent(this: v2, event: i);
    v5 = Event;
    if ( Event != nullptr )
    {
      Type = CChoreoEvent::GetType(this: Event);
      if ( Type == SPEAK )
      {
        Parameters = CChoreoEvent::GetParameters(this: v5);
        CBaseEntity::PrecacheScriptSound(soundname: Parameters);
        if ( CChoreoEvent::GetCloseCaptionType(this: v5) == CC_MASTER
          && (int)CChoreoEvent::GetNumSlaves(this: (vgui::CTreeViewListControl *)v5) > 0
          && CChoreoEvent::GetPlaybackCloseCaptionToken(this: v5, dest: tok, destlen: 64) )
        {
          CBaseEntity::PrecacheScriptSound(soundname: tok);
        }
      }
      else if ( Type == SUBSCENE
             && !CChoreoScene::IsSubScene(this: v2)
             && CChoreoEvent::GetSubScene(this: (vgui::Panel *)v5) == 0 )
      {
        if ( v13 != nullptr )
          v7 = &v13->IChoreoEventCallback;
        else
          v7 = nullptr;
        v11 = v7;
        v8 = CChoreoEvent::GetParameters(this: v5);
        v9 = (CChoreoScene *)CSceneEntity::LoadScene(filename: v8, pCallback: v11);
        CChoreoScene::SetSubScene(this: v9, sub: true);
        CChoreoEvent::SetSubScene(this: v5, scene: v9);
        CSceneEntity::PrecacheScene(this: v13, scene: v9);
        v2 = scene;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206600
// Name: public: virtual void CSceneEntity::DoThink(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DoThink(CSceneEntity *this, float frametime)
{
  float m_fPitch; // xmm0_4
  int v4; // xmm1_4
  bool v5; // zf
  float v6; // xmm0_4
  edict_t *m_pPev; // ecx
  float t; // [esp+0h] [ebp-Ch]
  float frametimea; // [esp+14h] [ebp+8h]

  this->CheckInterruptCompletion(this);
  if ( this->m_bWaitingForActor || this->m_bWaitingForInterrupt )
    this->StartPlayback(this);
  if ( this->m_pScene != nullptr && this->m_bIsPlayingBack.m_Value )
  {
    m_fPitch = this->m_fPitch;
    v4 = 1048576000;
    if ( m_fPitch < 0.25 || (v4 = 1075838976, m_fPitch > 2.5) )
      m_fPitch = *(float *)&v4;
    v5 = !this->m_bPaused.m_Value;
    this->m_fPitch = m_fPitch;
    if ( v5 )
    {
      this->m_flFrameTime = frametime;
      frametimea = engine->GetLatencyForChoreoSounds(this: engine);
      CChoreoScene::SetSoundFileStartupLatency(this: this->m_pScene, flTime: frametimea);
      CChoreoScene::Think(this: this->m_pScene, curtime: this->m_flCurrentTime);
      if ( this->m_bPaused.m_Value )
      {
        t = CBreakableProp::GetDmgModClub(this: this->m_pScene);
        CSceneEntity::SetCurrentTime(this, t, bForceClientSync: true);
      }
      else
      {
        v6 = (float)(this->m_flFrameTime * this->m_fPitch) + this->m_flCurrentTime;
        this->m_flCurrentTime = v6;
        if ( gpGlobals->maxClients == 1 && this->m_flForceClientTime.m_Value != v6 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
          }
          this->m_flForceClientTime.m_Value = v6;
        }
        if ( CChoreoScene::SimulationFinished(this: this->m_pScene) )
        {
          this->OnSceneFinished(this, a2: false, a3: true);
          CSceneEntity::ClearSchedules(this, scene: this->m_pScene);
        }
      }
    }
    else
    {
      this->PauseThink(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102067B0
// Name: public: void CSceneEntity::InputStartPlayback(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputStartPlayback(CSceneEntity *this, inputdata_t *inputdata)
{
  if ( !this->m_bIsPlayingBack.m_Value && !this->m_bWaitingForActor && !this->m_bWaitingForInterrupt )
  {
    CSceneEntity::ClearActivatorTargets(this);
    if ( inputdata->pActivator != nullptr )
      this->m_hActivator.m_Index = inputdata->pActivator->GetRefEHandle(this: inputdata->pActivator)->m_Index;
    else
      this->m_hActivator.m_Index = -1;
    this->StartPlayback(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206820
// Name: public: virtual void CSceneEntity::QueueResumePlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::QueueResumePlayback(CSceneEntity *this)
{
  CSceneEntity *m_Index; // edi
  bool v2; // zf
  const char *pszValue; // eax
  bool v4; // bl
  const char *v5; // ebx
  CBaseEntity *NoSpawn; // esi
  unsigned int *p_m_ListByClass; // edi
  CBaseEdict *v8; // ecx
  CChoreoScene *v9; // ecx
  CBaseFlex *v10; // eax
  void *v11; // esi
  const char *v12; // eax
  int (__thiscall *v13)(void *); // edx
  CAI_Expresser *v14; // eax
  char response[256]; // [esp+28h] [ebp-1B0h] BYREF
  ResponseRules::CRR_Response result; // [esp+128h] [ebp-B0h] BYREF
  CAI_Concept tmpConcept; // [esp+1D0h] [ebp-8h] BYREF

  m_Index = this;
  v2 = this->m_iszResumeSceneFile.pszValue == nullptr;
  tmpConcept.m_hSpeaker.m_Index = (unsigned int)this;
  if ( v2 )
  {
    this->ResumePlayback(this);
  }
  else
  {
    pszValue = this->m_iszResumeSceneFile.pszValue;
    v4 = false;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( V_stristr(pStr: pszValue, pSearch: ".vcd") != nullptr )
    {
      v5 = m_Index->m_iszResumeSceneFile.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      NoSpawn = CBaseEntity::CreateNoSpawn(
                  szName: "instanced_scripted_scene",
                  vecOrigin: &vec3_origin,
                  vecAngles: &vec3_angle,
                  pOwner: nullptr);
      p_m_ListByClass = &NoSpawn[1].m_ListByClass;
      V_strncpy(pDest: (char *)&NoSpawn[1].m_ListByClass, pSrc: v5, maxLen: 128);
      if ( NoSpawn == (CBaseEntity *)-1592 || *(_BYTE *)p_m_ListByClass == 0 )
        p_m_ListByClass = nullptr;
      NoSpawn[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))p_m_ListByClass;
      NoSpawn[1].m_RefEHandle.m_Index = -1;
      LOBYTE(NoSpawn[1].m_vecViewOffset.m_Value.x) = 0;
      if ( *(&NoSpawn[1].m_Network.m_TimerEvent.m_bRegistered + 2) )
      {
        if ( NoSpawn->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&NoSpawn->m_Network + 76) |= 1u;
        }
        else
        {
          v8 = &NoSpawn->m_Network.m_pPev->CBaseEdict;
          if ( v8 != nullptr )
            CBaseEdict::StateChanged(this: v8, offset: 0x3AAu);
        }
        *(&NoSpawn[1].m_Network.m_TimerEvent.m_bRegistered + 2) = false;
      }
      ((void (__thiscall *)(CBaseEntity *, _DWORD))NoSpawn->__vftable[1].RequiredEdictIndex)(a1: NoSpawn, a2: 0);
      DispatchSpawn(pEntity: NoSpawn, bRunVScripts: true);
      NoSpawn->Activate(this: NoSpawn);
      v9 = (CChoreoScene *)NoSpawn[1].m_OnUser4.m_Value.iszVal.pszValue;
      LOBYTE(NoSpawn[2].m_Network.__vftable) = 0;
      if ( v9 != nullptr )
        CChoreoScene::SetBackground(this: v9, bIsBackground: false);
      ((void (__thiscall *)(CBaseEntity *))NoSpawn->__vftable[1].SetModelIndex)(a1: NoSpawn);
      if ( tmpConcept.m_hSpeaker.m_Index != -864 )
        *(_DWORD *)(tmpConcept.m_hSpeaker.m_Index + 864) = NoSpawn->GetRefEHandle(this: NoSpawn)->m_Index;
      m_Index = (CSceneEntity *)tmpConcept.m_hSpeaker.m_Index;
      if ( ((double (__thiscall *)(CBaseEntity *))NoSpawn->__vftable[1].GetPlayerName)(a1: NoSpawn) != 0.0 )
        goto LABEL_29;
      v4 = false;
    }
    v10 = m_Index->FindNamedActor_3(this: m_Index, a2: 0);
    if ( v10 != nullptr )
    {
      v11 = __RTDynamicCast(
              inptr: v10,
              VfDelta: 0,
              SrcType: &CBaseFlex `RTTI Type Descriptor',
              TargetType: &CAI_BaseActor `RTTI Type Descriptor',
              isReference: 0);
      if ( v11 != nullptr )
      {
        ResponseRules::CRR_Response::CRR_Response(this: &result);
        v12 = m_Index->m_iszResumeSceneFile.pszValue;
        if ( v12 == nullptr )
          v12 = locale;
        ResponseRules::CRR_Concept::CRR_Concept(this: &tmpConcept, fromString: v12);
        v13 = *(int (__thiscall **)(void *))(*(_DWORD *)v11 + 1900);
        tmpConcept.m_hSpeaker.m_Index = -1;
        v14 = (CAI_Expresser *)v13(a1: v11);
        if ( CAI_Expresser::FindResponse(this: v14, outResponse: &result, concept: &tmpConcept, criteria: nullptr) )
        {
          ResponseRules::CRR_Response::GetResponse(this: &result, buf: response, buflen: 0x100u);
          v4 = InstancedScriptedScene(
                 pActor: nullptr,
                 pszScene: response,
                 phSceneEnt: &m_Index->m_hWaitingForThisResumeScene,
                 flPostDelay: 0.0,
                 bIsBackground: false,
                 response: nullptr,
                 bMultiplayer: 0.0,
                 filter: nullptr) != 0.0;
        }
        ResponseRules::CRR_Response::~CRR_Response(this: &result);
        if ( v4 )
        {
LABEL_29:
          m_Index->m_bWaitingForResumeScene = true;
          return;
        }
      }
    }
    m_Index->ResumePlayback(this: m_Index);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206AA0
// Name: public: void CSceneEntity::RequestCompletionNotification(class CSceneEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::RequestCompletionNotification(CSceneEntity *this, CSceneEntity *notify)
{
  unsigned int m_Index; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CHandle<CSceneEntity> *m_pMemory; // ecx
  int v7; // eax
  CHandle<CSceneEntity> *v8; // eax

  if ( notify != nullptr )
    m_Index = notify->GetRefEHandle(this: notify)->m_Index;
  else
    m_Index = -1;
  notify = (CSceneEntity *)m_Index;
  if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&this->m_hNotifySceneCompletion,
         src: (CHandle<CBaseEntity> *)&notify) == -1 )
  {
    m_nAllocationCount = this->m_hNotifySceneCompletion.m_Memory.m_nAllocationCount;
    m_Size = this->m_hNotifySceneCompletion.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hNotifySceneCompletion,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_hNotifySceneCompletion.m_Size;
    m_pMemory = this->m_hNotifySceneCompletion.m_Memory.m_pMemory;
    v7 = this->m_hNotifySceneCompletion.m_Size - m_Size - 1;
    this->m_hNotifySceneCompletion.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &this->m_hNotifySceneCompletion.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      v8->m_Index = m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206B50
// Name: public: void CSceneEntity::AddListManager(class CSceneListManager __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::AddListManager(CSceneEntity *this, CSceneListManager *pManager)
{
  unsigned int m_Index; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CHandle<CSceneListManager> *m_pMemory; // ecx
  int v7; // eax
  CHandle<CSceneListManager> *v8; // eax

  if ( pManager != nullptr )
    m_Index = pManager->GetRefEHandle(this: pManager)->m_Index;
  else
    m_Index = -1;
  pManager = (CSceneListManager *)m_Index;
  if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&this->m_hListManagers,
         src: (CHandle<CBaseEntity> *)&pManager) == -1 )
  {
    m_nAllocationCount = this->m_hListManagers.m_Memory.m_nAllocationCount;
    m_Size = this->m_hListManagers.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hListManagers,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_hListManagers.m_Size;
    m_pMemory = this->m_hListManagers.m_Memory.m_pMemory;
    v7 = this->m_hListManagers.m_Size - m_Size - 1;
    this->m_hListManagers.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &this->m_hListManagers.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      v8->m_Index = m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206C80
// Name: scene_playvcd
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall scene_playvcd(int a1@<edi>, int a2@<esi>, const CCommand *args)
{
  const char *v3; // eax
  CBaseEntity *NoSpawn; // esi
  unsigned int *p_m_ListByClass; // edi
  CBaseEdict *v6; // ecx
  CChoreoScene *pszValue; // ecx
  char vcdPath[512]; // [esp+Ch] [ebp-200h] BYREF

  if ( args->m_nArgc > 1 )
    v3 = args->m_ppArgv[1];
  else
    v3 = locale;
  V_snprintf(pDest: vcdPath, maxLen: 512, pFormat: "scenes/%s.vcd", v3);
  NoSpawn = CBaseEntity::CreateNoSpawn(
              szName: "instanced_scripted_scene",
              vecOrigin: &vec3_origin,
              vecAngles: &vec3_angle,
              pOwner: nullptr);
  p_m_ListByClass = &NoSpawn[1].m_ListByClass;
  V_strncpy(pDest: (char *)&NoSpawn[1].m_ListByClass, pSrc: vcdPath, maxLen: 128);
  if ( NoSpawn == (CBaseEntity *)-1592 || *(_BYTE *)p_m_ListByClass == 0 )
    p_m_ListByClass = nullptr;
  NoSpawn[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))p_m_ListByClass;
  NoSpawn[1].m_RefEHandle.m_Index = -1;
  LOBYTE(NoSpawn[1].m_vecViewOffset.m_Value.x) = 0;
  if ( *(&NoSpawn[1].m_Network.m_TimerEvent.m_bRegistered + 2) )
  {
    if ( NoSpawn->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&NoSpawn->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = &NoSpawn->m_Network.m_pPev->CBaseEdict;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x3AAu);
    }
    *(&NoSpawn[1].m_Network.m_TimerEvent.m_bRegistered + 2) = false;
  }
  ((void (__thiscall *)(CBaseEntity *, _DWORD, int, int))NoSpawn->__vftable[1].RequiredEdictIndex)(
    a1: NoSpawn,
    a2: 0,
    a3: a1,
    a4: a2);
  DispatchSpawn(pEntity: NoSpawn, bRunVScripts: true);
  NoSpawn->Activate(this: NoSpawn);
  pszValue = (CChoreoScene *)NoSpawn[1].m_OnUser4.m_Value.iszVal.pszValue;
  LOBYTE(NoSpawn[2].m_Network.__vftable) = 0;
  if ( pszValue != nullptr )
    CChoreoScene::SetBackground(this: pszValue, bIsBackground: false);
  ((void (__thiscall *)(CBaseEntity *))NoSpawn->__vftable[1].SetModelIndex)(a1: NoSpawn);
  NoSpawn->__vftable[1].GetPlayerName(this: NoSpawn);
}

//------------------------------------------------------------------------------
// Address: 0x10206DB0
// Name: public: void CSceneManager::AddSceneEntity(class CSceneEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManager::AddSceneEntity(CSceneManager *this, unsigned int scene)
{
  CSceneEntity *v2; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CHandle<CSceneEntity> *m_pMemory; // ecx
  int v7; // eax
  CHandle<CSceneEntity> *v8; // eax

  v2 = (CSceneEntity *)scene;
  if ( scene != 0 )
    scene = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)scene + 8))(a1: scene);
  else
    scene = -1;
  if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&this->m_Scenes,
         src: (CHandle<CBaseEntity> *)&scene) == -1 )
  {
    m_nAllocationCount = this->m_Scenes.m_Memory.m_nAllocationCount;
    m_Size = this->m_Scenes.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Scenes,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Scenes.m_Size;
    m_pMemory = this->m_Scenes.m_Memory.m_pMemory;
    v7 = this->m_Scenes.m_Size - m_Size - 1;
    this->m_Scenes.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &this->m_Scenes.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      v8->m_Index = scene;
    if ( v2->m_pScene != nullptr )
      CSceneManager::ActivateScene(this, scene: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206E80
// Name: public: void CSceneManager::ActivateScene(class CSceneEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManager::ActivateScene(CSceneManager *this, CSceneEntity *scene)
{
  CSceneEntity *v2; // esi
  int m_Index; // ebx
  CUtlMemory<vgui::TreeNode *,int> *p_m_ActiveScenes; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v9; // eax
  int *v10; // eax

  v2 = scene;
  CSceneManager::AddSceneEntity(this, (unsigned int)scene);
  if ( v2 != nullptr )
    m_Index = v2->GetRefEHandle(this: v2)->m_Index;
  else
    m_Index = -1;
  p_m_ActiveScenes = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ActiveScenes;
  scene = (CSceneEntity *)m_Index;
  if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&this->m_ActiveScenes,
         src: (CHandle<CBaseEntity> *)&scene) == -1 )
  {
    m_Size = this->m_ActiveScenes.m_Size;
    m_nAllocationCount = p_m_ActiveScenes->m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_ActiveScenes, num: m_Size - m_nAllocationCount + 1);
    ++p_m_ActiveScenes[1].m_pMemory;
    m_pMemory = p_m_ActiveScenes->m_pMemory;
    v9 = (int)p_m_ActiveScenes[1].m_pMemory - m_Size - 1;
    p_m_ActiveScenes[1].m_nAllocationCount = (int)p_m_ActiveScenes->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = (int *)&p_m_ActiveScenes->m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206F20
// Name: public: void CSceneManager::OnClientActive(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManager::OnClientActive(CSceneManager *this, CBasePlayer *player)
{
  int m_Size; // eax
  CBaseEntityList *v3; // edi
  CSceneManager::CRestoreSceneSound *v4; // esi
  unsigned int m_Index; // edx
  int v6; // eax
  CEntInfo *v7; // ecx
  unsigned int v8; // edx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *m_pEntity; // edi
  const Vector *v13; // eax
  unsigned int v14; // esi
  IHandleEntity *v15; // eax
  IHandleEntity_vtbl *v16; // eax
  signed int v17; // eax
  Vector *m_pMemory; // eax
  float attenuation[3]; // [esp+14h] [ebp-90h] BYREF
  char v20[12]; // [esp+20h] [ebp-84h] BYREF
  CPASAttenuationFilter filter; // [esp+2Ch] [ebp-78h] BYREF
  EmitSound_t params; // [esp+4Ch] [ebp-58h] BYREF
  const Vector *origin; // [esp+94h] [ebp-10h]
  int i; // [esp+98h] [ebp-Ch]
  CSceneManager *v25; // [esp+9Ch] [ebp-8h]
  unsigned int v26; // [esp+A0h] [ebp-4h]
  int savedregs; // [esp+A4h] [ebp+0h] BYREF

  m_Size = this->m_QueuedSceneSounds.m_Size;
  v25 = this;
  if ( m_Size > 0 )
  {
    v3 = g_pEntityList;
    v26 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v4 = &this->m_QueuedSceneSounds.m_Memory.m_pMemory[v26 / 0x8C];
      m_Index = v4->actor.m_Index;
      if ( v4->actor.m_Index != -1 )
      {
        v6 = (unsigned __int16)m_Index;
        v7 = &v3->m_EntPtrArray[(unsigned __int16)m_Index];
        v8 = HIWORD(m_Index);
        if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
        {
          v9 = v6;
          v10 = v3->m_EntPtrArray[v9].m_SerialNumber == v8;
          v11 = &v3->m_EntPtrArray[v9];
          if ( v10 )
            m_pEntity = v11->m_pEntity;
          else
            m_pEntity = nullptr;
          origin = (const Vector *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].SetRefEHandle)(a1: m_pEntity);
          CRecipientFilter::CRecipientFilter(this: &filter);
          filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
          CRecipientFilter::AddRecipientsByPAS(this: &filter, origin);
          filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
          v13 = (const Vector *)((int (__thiscall *)(IHandleEntity *, char *, int))m_pEntity->__vftable[49].SetRefEHandle)(
                                  a1: m_pEntity,
                                  a2: v20,
                                  a3: 1061997773);
          CPASAttenuationFilter::Filter(
            this: &filter,
            a2: (int)&savedregs,
            origin: v13,
            attenuation: COERCE_FLOAT(attenuation));
          params.m_SoundLevel = SNDLVL_NONE;
          params.m_pSoundName = v4->soundname;
          params.m_nFlags = 0;
          params.m_nPitch = 100;
          memset(&params.m_pOrigin, 0, 12);
          *(_WORD *)&params.m_bEmitCloseCaption = 1;
          params.m_bWarnOnDirectWaveReference = false;
          params.m_nSpeakerEntity = -1;
          memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
          params.m_hSoundScriptHandle = -1;
          params.m_nSoundEntryVersion = 1;
          params.m_nChannel = 2;
          params.m_flVolume = 1.0;
          params.m_SoundLevel = v4->soundlevel;
          params.m_flSoundTime = gpGlobals->curtime - v4->time_in_past;
          v14 = v4->actor.m_Index;
          if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
            v15 = nullptr;
          else
            v15 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
          v16 = v15[6].__vftable;
          if ( v16 != nullptr )
            v17 = ((char *)v16 - (char *)gpGlobals->pEdicts) >> 4;
          else
            v17 = 0;
          CBaseEntity::EmitSound(&filter, iEntIndex: v17, &params);
          m_pMemory = params.m_UtlVecSoundOrigin.m_Memory.m_pMemory;
          params.m_UtlVecSoundOrigin.m_Size = 0;
          if ( params.m_UtlVecSoundOrigin.m_Memory.m_nGrowSize >= 0 )
          {
            if ( params.m_UtlVecSoundOrigin.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)params.m_UtlVecSoundOrigin.m_Memory.m_pMemory);
              m_pMemory = nullptr;
              params.m_UtlVecSoundOrigin.m_Memory.m_pMemory = nullptr;
            }
            params.m_UtlVecSoundOrigin.m_Memory.m_nAllocationCount = 0;
          }
          params.m_UtlVecSoundOrigin.m_pElements = m_pMemory;
          if ( params.m_UtlVecSoundOrigin.m_Memory.m_nGrowSize >= 0 )
          {
            if ( m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory);
              params.m_UtlVecSoundOrigin.m_Memory.m_pMemory = nullptr;
            }
            params.m_UtlVecSoundOrigin.m_Memory.m_nAllocationCount = 0;
          }
          CRecipientFilter::~CRecipientFilter(this: &filter);
          v3 = g_pEntityList;
        }
        this = v25;
      }
      v26 += 140;
    }
  }
  this->m_QueuedSceneSounds.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10207150
// Name: public: void CSceneManager::QueueRestoredSound(class CBaseFlex __near *,char const __near *,enum soundlevel_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManager::QueueRestoredSound(
        CSceneManager *this,
        CBaseFlex *actor,
        const char *soundname,
        soundlevel_t soundlevel,
        float time_in_past)
{
  unsigned int m_Index; // eax
  int m_Size; // [esp-Ch] [ebp-98h]
  CSceneManager::CRestoreSceneSound e; // [esp+0h] [ebp-8Ch] BYREF

  m_Index = -1;
  e.actor.m_Index = -1;
  e.soundname[0] = 0;
  e.soundlevel = SNDLVL_NORM;
  e.time_in_past = 0.0;
  if ( actor != nullptr )
    m_Index = actor->GetRefEHandle(this: actor)->m_Index;
  e.actor.m_Index = m_Index;
  V_strncpy(pDest: e.soundname, pSrc: soundname, maxLen: 128);
  e.soundlevel = soundlevel;
  m_Size = this->m_QueuedSceneSounds.m_Size;
  e.time_in_past = time_in_past;
  CUtlVector<CSceneManager::CRestoreSceneSound,CUtlMemory<CSceneManager::CRestoreSceneSound,int>>::InsertBefore(
    this: &this->m_QueuedSceneSounds,
    elem: m_Size,
    src: &e);
}

//------------------------------------------------------------------------------
// Address: 0x102081B0
// Name: public: void CSceneListManager::AddListManager(class CSceneListManager __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneListManager::AddListManager(CSceneListManager *this, CSceneListManager *pManager)
{
  unsigned int m_Index; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CHandle<CSceneListManager> *m_pMemory; // ecx
  int v7; // eax
  CHandle<CSceneListManager> *v8; // eax

  if ( pManager != nullptr )
    m_Index = pManager->GetRefEHandle(this: pManager)->m_Index;
  else
    m_Index = -1;
  pManager = (CSceneListManager *)m_Index;
  if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&this->m_hListManagers,
         src: (CHandle<CBaseEntity> *)&pManager) == -1 )
  {
    m_nAllocationCount = this->m_hListManagers.m_Memory.m_nAllocationCount;
    m_Size = this->m_hListManagers.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hListManagers,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_hListManagers.m_Size;
    m_pMemory = this->m_hListManagers.m_Memory.m_pMemory;
    v7 = this->m_hListManagers.m_Size - m_Size - 1;
    this->m_hListManagers.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &this->m_hListManagers.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      v8->m_Index = m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208380
// Name: public: virtual void CInstancedSceneEntity::SetPostSpeakDelay(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInstancedSceneEntity::SetPostSpeakDelay(CInstancedSceneEntity *this, float flDelay)
{
  this->m_flPostSpeakDelay = flDelay;
}

//------------------------------------------------------------------------------
// Address: 0x102083A0
// Name: public: virtual float CInstancedSceneEntity::GetPreDelay(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInstancedSceneEntity::GetPreDelay(CInstancedSceneEntity *this)
{
  return this->m_flPreDelay;
}

//------------------------------------------------------------------------------
// Address: 0x102083B0
// Name: public: virtual void CInstancedSceneEntity::SetPreDelay(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInstancedSceneEntity::SetPreDelay(CInstancedSceneEntity *this, float flDelay)
{
  this->m_flPreDelay = flDelay;
}

//------------------------------------------------------------------------------
// Address: 0x102083D0
// Name: public: virtual void CInstancedSceneEntity::DispatchEndMoveTo(class CChoreoScene __near *,class CBaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInstancedSceneEntity::DispatchEndMoveTo(
        CInstancedSceneEntity *this,
        CChoreoScene *scene,
        CBaseFlex *actor,
        CChoreoEvent *event)
{
  if ( CInstancedSceneEntity::PassThrough(this, actor) != 0 )
    CBaseFlex::RemoveSceneEvent(this: actor, scene, event, fastKill: this->m_bRestoring);
}

//------------------------------------------------------------------------------
// Address: 0x10208410
// Name: public: virtual void CInstancedSceneEntity::DispatchStartFace(class CChoreoScene __near *,class CBaseFlex __near *,class CBaseEntity __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInstancedSceneEntity::DispatchStartFace(
        CInstancedSceneEntity *this,
        CChoreoActor *scene,
        CBaseFlex *actor,
        CBaseEntity *actor2,
        CChoreoEvent *event)
{
  if ( CInstancedSceneEntity::PassThrough(this, actor) != 0 )
    CBaseFlex::AddSceneEvent(this: actor, scene, event, pTarget: actor2, pSceneEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x102085F0
// Name: void SceneManager_ClientActive(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SceneManager_ClientActive(CBasePlayer *player)
{
  CSceneManager *SceneManager; // eax

  if ( GetSceneManager() != nullptr )
  {
    SceneManager = GetSceneManager();
    CSceneManager::OnClientActive(this: SceneManager, player);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208610
// Name: public: virtual void CSceneEntity::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::Activate(CSceneEntity *this)
{
  const char *pszValue; // edx
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  CSceneManager *SceneManager; // eax
  CSceneManager *v6; // eax

  if ( this->m_bGenerated && this->m_pScene == nullptr )
  {
    pszValue = this->m_iszSoundName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    m_Index = this->m_hActor.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    this->m_pScene = CSceneEntity::GenerateSceneForSound(
                       this,
                       pFlexActor: (CChoreoScene *)m_pEntity,
                       soundname: pszValue);
    if ( GetSceneManager() != nullptr )
    {
      SceneManager = GetSceneManager();
      CSceneManager::ActivateScene(this: SceneManager, scene: this);
    }
  }
  CBaseEntity::Activate(this);
  if ( GetSceneManager() != nullptr )
  {
    v6 = GetSceneManager();
    CSceneManager::AddSceneEntity(this: v6, scene: (unsigned int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102086B0
// Name: public: virtual void CSceneEntity::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::OnRestore(CSceneEntity *this)
{
  float m_fPitch; // xmm0_4
  const char *pszValue; // eax
  CChoreoScene *Scene; // eax
  CSceneManager *v5; // eax
  const char *v6; // eax
  int v7; // ebx
  edict_t *v8; // ecx
  CSceneManager *SceneManager; // eax
  CChoreoScene *m_pScene; // ecx
  int v11; // ebx
  CBaseFlex *v12; // edi
  bool m_Value; // bl
  edict_t *m_pPev; // ecx
  float m_flCurrentTime; // xmm0_4
  edict_t *v16; // ecx
  CChoreoScene *v17; // eax
  CChoreoScene *v18; // eax
  edict_t *v19; // esi
  float starttime; // [esp+4h] [ebp-18h]
  float endtime; // [esp+8h] [ebp-14h]
  float endtimea; // [esp+8h] [ebp-14h]

  CBaseEntity::OnRestore(this);
  m_fPitch = this->m_fPitch;
  if ( m_fPitch < 0.25 || m_fPitch > 2.5 )
    this->m_fPitch = 1.0;
  if ( this->m_bIsPlayingBack.m_Value )
  {
    if ( this->m_pScene != nullptr )
    {
      if ( GetSceneManager() != nullptr )
      {
        SceneManager = GetSceneManager();
        CSceneManager::ActivateScene(this: SceneManager, scene: this);
      }
      goto LABEL_24;
    }
    pszValue = this->m_iszSceneFile.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    Scene = (CChoreoScene *)CSceneEntity::LoadScene(filename: pszValue, pCallback: &this->IChoreoEventCallback);
    this->m_pScene = Scene;
    if ( Scene == nullptr )
    {
      this->m_bSceneMissing = true;
      return;
    }
    if ( GetSceneManager() != nullptr )
    {
      v5 = GetSceneManager();
      CSceneManager::ActivateScene(this: v5, scene: this);
    }
    this->OnLoaded(this);
    if ( CSceneEntity::ShouldNetwork(this) )
    {
      v6 = this->m_iszSceneFile.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      v7 = g_pStringTableClientSideChoreoScenes->AddString(
             this: g_pStringTableClientSideChoreoScenes,
             a2: true,
             a3: v6,
             a4: -1,
             a5: nullptr);
      if ( this->m_nSceneStringIndex.m_Value != v7 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_nSceneStringIndex.m_Value = v7;
          this->UpdateTransmitState(this);
LABEL_24:
          m_pScene = this->m_pScene;
          this->m_bSceneMissing = false;
          v11 = 0;
          if ( CChoreoScene::GetNumActors(this: m_pScene) > 0 )
          {
            do
            {
              v12 = this->FindNamedActor_3(this, a2: v11);
              if ( v12 != nullptr && v12->MyCombatCharacterPointer(this: v12) != nullptr )
                CBaseFlex::StartChoreoScene(this: v12, scene: this->m_pScene);
              ++v11;
            }
            while ( v11 < CChoreoScene::GetNumActors(this: this->m_pScene) );
          }
          m_Value = this->m_bPaused.m_Value;
          if ( m_Value )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
            }
            else
            {
              m_pPev = this->m_Network.m_pPev;
              if ( m_pPev != nullptr )
                CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A9u);
            }
            this->m_bPaused.m_Value = false;
          }
          endtime = this->m_flCurrentTime;
          starttime = endtime - 0.001;
          CChoreoScene::ResetSimulation(this: this->m_pScene, forward: true, starttime, endtime);
          endtimea = this->m_flCurrentTime - 0.001;
          CBreakable::SetDmgModExplosive(this: this->m_pScene, t: endtimea);
          m_flCurrentTime = this->m_flCurrentTime;
          if ( this->m_flForceClientTime.m_Value != m_flCurrentTime )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
            }
            else
            {
              v16 = this->m_Network.m_pPev;
              if ( v16 != nullptr )
                CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x3ACu);
            }
            this->m_flForceClientTime.m_Value = m_flCurrentTime;
          }
          v17 = this->m_pScene;
          this->m_bRestoring = true;
          if ( v17 != nullptr )
            *((_BYTE *)v17 + 528) |= 0x10u;
          ((void (__thiscall *)(CSceneEntity *, int))this->DoThink)(a1: this, a2: 981668463);
          v18 = this->m_pScene;
          this->m_bRestoring = false;
          if ( v18 != nullptr )
            *((_BYTE *)v18 + 528) &= ~0x10u;
          if ( m_Value )
            this->PausePlayback(this);
          v19 = this->m_Network.m_pPev;
          if ( v19 != nullptr )
          {
            v19->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: &v19->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
          }
          return;
        }
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x400u);
        this->m_nSceneStringIndex.m_Value = v7;
      }
    }
    this->UpdateTransmitState(this);
    goto LABEL_24;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102089C0
// Name: public: virtual void CSceneEntity::DispatchStartSpeak(class CChoreoScene __near *,class CBaseFlex __near *,class CChoreoEvent __near *,enum soundlevel_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::DispatchStartSpeak(
        CSceneEntity *this,
        float scene,
        float actor,
        CChoreoEvent *event,
        soundlevel_t iSoundlevel)
{
  CBaseFlex *v5; // esi
  int Flags; // esi
  int v8; // eax
  int v9; // esi
  int RecipientIndex; // edi
  double StartTime; // st7
  bool v12; // zf
  double v13; // st7
  CSceneManager *SceneManager; // eax
  double v15; // st7
  float (__thiscall *GetPostSpeakDelay)(CSceneEntity *); // eax
  double v17; // st7
  void *v18; // eax
  int v19; // eax
  char v20; // al
  const CBaseHandle *v21; // eax
  float v22; // xmm0_4
  int v23; // eax
  CBasePlayer *v24; // esi
  int v25; // eax
  CChoreoActor *v26; // edi
  const char *Filename; // eax
  float m_fPitch; // xmm0_4
  CBaseFlex *v29; // esi
  edict_t *v30; // eax
  CChoreoEvent *v31; // ebx
  CChoreoScene *v32; // eax
  int v33; // eax
  CBasePlayer *v34; // eax
  signed int v35; // esi
  float v36; // edx
  unsigned int v37; // eax
  CBaseEntity *ViewEntity; // ebx
  double v39; // st7
  double v40; // st7
  CBaseFlex *v41; // xmm0_4
  string_t (__thiscall *GetModelName)(struct CBaseEntity *); // edx
  const char *v43; // eax
  gender_t v44; // edi
  char v45; // bl
  signed int v46; // eax
  Vector *m_pMemory; // eax
  const char *Parameters; // [esp+0h] [ebp-3DCh]
  soundlevel_t v49; // [esp+4h] [ebp-3D8h]
  int time_in_past; // [esp+8h] [ebp-3D4h]
  char lowercase_nogender[256]; // [esp+18h] [ebp-3C4h] BYREF
  char pDest[256]; // [esp+118h] [ebp-2C4h] BYREF
  char lowercase[256]; // [esp+218h] [ebp-1C4h] BYREF
  char dest[32]; // [esp+318h] [ebp-C4h] BYREF
  CSingleUserRecipientFilter filter2; // [esp+338h] [ebp-A4h] BYREF
  Vector playerOrigin; // [esp+358h] [ebp-84h] BYREF
  CPASAttenuationFilter filter; // [esp+364h] [ebp-78h] BYREF
  EmitSound_t params; // [esp+384h] [ebp-58h] BYREF
  float flDuration; // [esp+3CCh] [ebp-10h]
  int soundtime; // [esp+3D0h] [ebp-Ch]
  int recipientPlayerCount; // [esp+3D4h] [ebp-8h]
  int i; // [esp+3D8h] [ebp-4h]
  int savedregs; // [esp+3DCh] [ebp+0h] BYREF

  v5 = (CBaseFlex *)LODWORD(actor);
  if ( actor == 0.0 )
    return;
  CPASAttenuationFilter::CPASAttenuationFilter(
    this: &filter,
    entity: (CBaseEntity *)LODWORD(actor),
    soundlevel: iSoundlevel);
  if ( this->m_pRecipientFilter != nullptr )
  {
    Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)&filter);
    *(float *)&recipientPlayerCount = COERCE_FLOAT(this->m_pRecipientFilter->GetRecipientCount(this: this->m_pRecipientFilter));
    v8 = Flags - 1;
    i = Flags - 1;
    if ( Flags - 1 >= 0 )
    {
      while ( 1 )
      {
        v9 = 0;
        RecipientIndex = CRecipientFilter::GetRecipientIndex(this: &filter, slot: v8);
        if ( recipientPlayerCount <= 0 )
        {
LABEL_9:
          CRecipientFilter::RemoveRecipientByPlayerIndex(this: &filter, playerindex: RecipientIndex);
        }
        else
        {
          while ( this->m_pRecipientFilter->GetRecipientIndex(this: this->m_pRecipientFilter, a2: v9) != RecipientIndex )
          {
            if ( ++v9 >= recipientPlayerCount )
              goto LABEL_9;
          }
        }
        if ( --i < 0 )
          break;
        v8 = i;
      }
    }
    v5 = (CBaseFlex *)LODWORD(actor);
  }
  *(float *)&i = CChoreoScene::GetSoundFileStartupLatency(this: (CChoreoScene *)LODWORD(scene));
  StartTime = CChoreoEvent::GetStartTime(this: event);
  v12 = !this->m_bRestoring;
  v13 = this->m_flCurrentTime - StartTime + *(float *)&i;
  *(float *)&recipientPlayerCount = v13;
  *(float *)&soundtime = gpGlobals->curtime - v13;
  if ( !v12 )
  {
    time_in_past = recipientPlayerCount;
    v49 = iSoundlevel;
    Parameters = CChoreoEvent::GetParameters(this: event);
    SceneManager = GetSceneManager();
    CSceneManager::QueueRestoredSound(
      this: SceneManager,
      actor: v5,
      soundname: Parameters,
      soundlevel: v49,
      time_in_past: *(float *)&time_in_past);
    CBaseFlex::AddSceneEvent(
      this: v5,
      scene: (CChoreoActor *)LODWORD(scene),
      event,
      pTarget: nullptr,
      pSceneEntity: this);
    CRecipientFilter::~CRecipientFilter(this: &filter);
    return;
  }
  v15 = ((double (__thiscall *)(CChoreoEvent *))event->GetDuration)(a1: event);
  GetPostSpeakDelay = this->GetPostSpeakDelay;
  flDuration = v15 - *(float *)&recipientPlayerCount;
  v17 = ((double (__thiscall *)(CSceneEntity *))GetPostSpeakDelay)(a1: this);
  *(float *)&recipientPlayerCount = v17 - *(float *)&i;
  v18 = __RTDynamicCast(
          inptr: v5,
          VfDelta: 0,
          SrcType: &CBaseFlex `RTTI Type Descriptor',
          TargetType: &CAI_BaseActor `RTTI Type Descriptor',
          isReference: 0);
  if ( v18 != nullptr )
  {
    (*(void (__thiscall **)(void *, float, int))(*(_DWORD *)v18 + 2472))(
      a1: v18,
      a2: COERCE_FLOAT(LODWORD(flDuration)),
      a3: recipientPlayerCount);
  }
  else if ( v5->IsNPC(this: v5) )
  {
    v19 = (int)v5->MyNPCPointer(this: v5);
    v20 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v19 + 1772))(a1: v19, a2: 0);
    *(float *)&i = COERCE_FLOAT(&g_AIFriendliesTalkSemaphore);
    if ( v20 == 0 )
      *(float *)&i = COERCE_FLOAT(&g_AIFoesTalkSemaphore);
    *(float *)i = (float)(*(float *)&recipientPlayerCount + flDuration) + gpGlobals->curtime;
    v21 = v5->GetRefEHandle(this: v5);
    *(CBaseHandle *)(i + 4) = (CBaseHandle)v21->m_Index;
  }
  v22 = 0.0;
  params.m_hSoundScriptHandle = -1;
  params.m_pSoundName = nullptr;
  params.m_nFlags = 0;
  params.m_nPitch = 100;
  memset(&params.m_pOrigin, 0, 12);
  *(_WORD *)&params.m_bEmitCloseCaption = 1;
  params.m_bWarnOnDirectWaveReference = false;
  params.m_nSpeakerEntity = -1;
  memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
  params.m_nSoundEntryVersion = 1;
  params.m_nChannel = 2;
  params.m_flVolume = 1.0;
  params.m_SoundLevel = iSoundlevel;
  if ( gpGlobals->maxClients == 1 )
    v22 = *(float *)&soundtime;
  params.m_flSoundTime = v22;
  params.m_nFlags = 2048;
  if ( CChoreoScene::ShouldIgnorePhonemes(this: (CChoreoScene *)LODWORD(scene)) )
    params.m_nFlags |= 0x100u;
  params.m_bEmitCloseCaption = false;
  CRecipientFilter::RemoveSplitScreenPlayers(this: &filter);
  *(float *)&soundtime = COERCE_FLOAT(ConCommandBase::GetFlags(this: (ConCommandBase *)&filter));
  *(float *)&i = 0.0;
  if ( soundtime > 0 )
  {
    do
    {
      v23 = CRecipientFilter::GetRecipientIndex(this: &filter, slot: i);
      v24 = UTIL_PlayerByIndex(playerIndex: v23);
      if ( v24 != nullptr )
      {
        CRecipientFilter::CRecipientFilter(this: &filter2);
        filter2.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
        CRecipientFilter::AddRecipient(this: &filter2, player: v24);
        if ( CSceneEntity::GetSoundNameForPlayer(this, event, player: v24, buf: lowercase_nogender, buflen: 0x200u) != 0 )
        {
          params.m_pSoundName = lowercase_nogender;
          v25 = speechListIndex;
          speechListSounds[v25].time = gpGlobals->curtime;
          V_strncpy(pDest: speechListSounds[v25].name, pSrc: lowercase_nogender, maxLen: 512);
          v26 = (CChoreoActor *)LODWORD(scene);
          if ( scene == 0.0 )
            Filename = locale;
          else
            Filename = CChoreoScene::GetFilename(this: (CChoreoScene *)LODWORD(scene));
          V_strncpy(pDest: speechListSounds[speechListIndex].sceneName, pSrc: Filename, maxLen: 128);
          if ( ++speechListIndex >= 5 )
            speechListIndex = 0;
          m_fPitch = this->m_fPitch;
          if ( m_fPitch != 1.0 )
          {
            if ( params.m_nPitch != 0 )
              params.m_nPitch = (int)(float)((float)params.m_nPitch * m_fPitch);
            else
              params.m_nPitch = (int)(float)(m_fPitch * 100.0);
            params.m_nFlags |= 2u;
          }
          v29 = (CBaseFlex *)LODWORD(actor);
          v30 = CBaseEntity::entindex(this: (CBaseEntity *)LODWORD(actor));
          if ( CBaseEntity::EmitSound(filter: &filter2, iEntIndex: (int)v30, &params) == 0 )
            _Warning(a1: "Could not play sound '%s'. Check that the sound exists.\n", lowercase_nogender);
          CBaseFlex::AddSceneEvent(this: v29, scene: v26, event, pTarget: nullptr, pSceneEntity: this);
        }
        CRecipientFilter::~CRecipientFilter(this: &filter2);
      }
      ++i;
    }
    while ( i < soundtime );
    v5 = (CBaseFlex *)LODWORD(actor);
  }
  v31 = event;
  if ( CChoreoEvent::GetCloseCaptionType(this: event) == CC_MASTER
    && CChoreoEvent::GetPlaybackCloseCaptionToken(this: v31, dest, destlen: 64) )
  {
    V_strncpy(pDest: lowercase, pSrc: dest, maxLen: 256);
    _V_strlower(start: lowercase);
    CBaseEntity::RemoveRecipientsIfNotCloseCaptioning(&filter);
    if ( !CChoreoEvent::IsSuppressingCaptionAttenuation(this: v31)
      && ConCommandBase::GetFlags(this: (ConCommandBase *)&filter) > 0 )
    {
      v32 = (CChoreoScene *)(ConCommandBase::GetFlags(this: (ConCommandBase *)&filter) - 1);
      scene = *(float *)&v32;
      if ( (int)v32 >= 0 )
      {
        while ( 1 )
        {
          v33 = CRecipientFilter::GetRecipientIndex(this: &filter, slot: (int)v32);
          v34 = UTIL_PlayerByIndex(playerIndex: v33);
          v35 = (signed int)v34;
          if ( v34 != nullptr )
          {
            if ( (v34->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: v34, a2: (int)&savedregs);
            v36 = *(float *)(v35 + 468);
            *(_QWORD *)&playerOrigin.x = *(_QWORD *)(v35 + 460);
            playerOrigin.z = v36;
            if ( iSoundlevel != SNDLVL_NONE
              && AttenuateCaption(token: lowercase, listener: &playerOrigin, soundorigins: &params.m_UtlVecSoundOrigin) != 0 )
            {
              v37 = *(_DWORD *)(v35 + 3932);
              if ( v37 == -1
                || g_pEntityList->m_EntPtrArray[(unsigned __int16)v37].m_SerialNumber != HIWORD(v37)
                || g_pEntityList->m_EntPtrArray[(unsigned __int16)v37].m_pEntity == nullptr )
              {
                goto LABEL_61;
              }
              ViewEntity = CBasePlayer::GetViewEntity(this: (CBasePlayer *)v35);
              if ( (ViewEntity->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this: ViewEntity, a2: (int)&savedregs);
              if ( AttenuateCaption(
                     token: lowercase,
                     listener: &ViewEntity->m_vecAbsOrigin,
                     soundorigins: &params.m_UtlVecSoundOrigin) != 0 )
LABEL_61:
                CRecipientFilter::RemoveRecipient(this: &filter, player: v35);
            }
          }
          --LODWORD(scene);
          if ( scene < 0.0 )
            break;
          *(float *)&v32 = scene;
        }
        v5 = (CBaseFlex *)LODWORD(actor);
        v31 = event;
      }
    }
    if ( ConCommandBase::GetFlags(this: (ConCommandBase *)&filter) > 0 )
    {
      scene = CChoreoEvent::GetLastSlaveEndTime(this: v31);
      actor = v31->GetDuration(this: v31);
      v39 = CChoreoEvent::GetStartTime(this: v31);
      v40 = scene - v39;
      scene = v40;
      if ( actor <= v40 )
        *(float *)&v41 = scene;
      else
        *(float *)&v41 = actor;
      GetModelName = v5->GetModelName;
      actor = *(float *)&v41;
      v43 = *(const char **)((int (__thiscall *)(CBaseFlex *, float *))GetModelName)(a1: v5, a2: &scene);
      if ( v43 == nullptr )
        v43 = locale;
      v44 = soundemitterbase->GetActorGender(this: soundemitterbase, a2: v43);
      V_strncpy(pDest, pSrc: lowercase, maxLen: 256);
      v45 = 0;
      if ( v44 == GENDER_MALE )
      {
        V_strncat(pDest: lowercase, pSrc: "_male", destBufferSize: 0x100u, max_chars_to_copy: -1);
      }
      else
      {
        if ( v44 != GENDER_FEMALE )
          goto LABEL_75;
        V_strncat(pDest: lowercase, pSrc: "_female", destBufferSize: 0x100u, max_chars_to_copy: -1);
      }
      v45 = 1;
LABEL_75:
      event = nullptr;
      if ( (GetCaptionHash(pchStringName: lowercase, bWarnIfMissing: true, hash: (unsigned int *)&event)
         || v45 != 0 && GetCaptionHash(pchStringName: pDest, bWarnIfMissing: true, hash: (unsigned int *)&event))
        && CanEmitCaption(hash: (unsigned int)event) )
      {
        UserMessageBegin(&filter, messagename: "CloseCaption");
        MessageWriteLong(iValue: (int)event);
        v46 = (int)(float)(actor * 10.0);
        if ( v46 >= 0 )
        {
          if ( v46 > 0xFFFF )
            v46 = 0xFFFF;
        }
        else
        {
          v46 = 0;
        }
        MessageWriteUBitLong(data: v46, numbits: 15);
        MessageWriteUBitLong(data: 0, numbits: 1);
        MessageEnd();
      }
    }
  }
  m_pMemory = params.m_UtlVecSoundOrigin.m_Memory.m_pMemory;
  params.m_UtlVecSoundOrigin.m_Size = 0;
  if ( params.m_UtlVecSoundOrigin.m_Memory.m_nGrowSize >= 0 )
  {
    if ( params.m_UtlVecSoundOrigin.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)params.m_UtlVecSoundOrigin.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      params.m_UtlVecSoundOrigin.m_Memory.m_pMemory = nullptr;
    }
    params.m_UtlVecSoundOrigin.m_Memory.m_nAllocationCount = 0;
  }
  params.m_UtlVecSoundOrigin.m_pElements = m_pMemory;
  if ( params.m_UtlVecSoundOrigin.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory);
      params.m_UtlVecSoundOrigin.m_Memory.m_pMemory = nullptr;
    }
    params.m_UtlVecSoundOrigin.m_Memory.m_nAllocationCount = 0;
  }
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10209150
// Name: public: void CSceneEntity::InputInterjectResponse(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::InputInterjectResponse(CSceneEntity *this, inputdata_t *inputdata)
{
  CSceneEntity *v2; // esi
  CChoreoScene *m_pScene; // ecx
  int v4; // edi
  int m_Size; // ebx
  CBaseFlex *v6; // eax
  CAI_BaseActor *v7; // edi
  int v8; // esi
  CAI_BaseActor **m_pMemory; // ecx
  CAI_BaseActor **v10; // eax
  CChoreoScene *v11; // ecx
  IUniformRandomStream *v12; // ecx
  int v13; // edi
  const char *pszValue; // eax
  variant_t *p_value; // ecx
  bool v16; // zf
  const char *iVal; // eax
  CAI_BaseActor *v18; // esi
  CAI_Expresser *v19; // eax
  CAI_Expresser *v20; // eax
  UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *v21; // eax
  int v22; // ecx
  CAI_Expresser *v23; // eax
  double ResponseDuration; // st7
  int v25; // ebx
  NPCInterjection *v26; // edi
  const char *v27; // eax
  CAI_BaseActor *npc; // esi
  int v29; // eax
  int v30; // edi
  NPCInterjection *v31; // esi
  int v32; // [esp-18h] [ebp-3E0h]
  char modifiers[512]; // [esp+14h] [ebp-3B4h] BYREF
  NPCInterjection inter; // [esp+214h] [ebp-1B4h] BYREF
  ResponseRules::CRR_Response response; // [esp+2C0h] [ebp-108h] BYREF
  ResponseRules::CriteriaSet set; // [esp+368h] [ebp-60h] BYREF
  CAI_Concept concept; // [esp+38Ch] [ebp-3Ch] BYREF
  CUtlVector<NPCInterjection,CUtlMemory<NPCInterjection,int> > validResponses; // [esp+394h] [ebp-34h] BYREF
  CUtlVector<CAI_BaseActor *,CUtlMemory<CAI_BaseActor *,int> > candidates; // [esp+3A8h] [ebp-20h] BYREF
  ResponseRules::CRR_Concept v40; // [esp+3BCh] [ebp-Ch] BYREF
  int v41; // [esp+3C0h] [ebp-8h]
  int i; // [esp+3C4h] [ebp-4h]
  float slota; // [esp+3D0h] [ebp+8h]
  int slot; // [esp+3D0h] [ebp+8h]

  v2 = this;
  m_pScene = this->m_pScene;
  v4 = 0;
  v41 = (int)v2;
  if ( m_pScene != nullptr )
  {
    m_Size = 0;
    memset(&candidates, 0, sizeof(candidates));
    i = 0;
    if ( CChoreoScene::GetNumActors(this: m_pScene) <= 0 )
      goto LABEL_14;
    do
    {
      v6 = v2->FindNamedActor_3(this: v2, a2: v4);
      if ( v6 != nullptr )
      {
        v7 = (CAI_BaseActor *)__RTDynamicCast(
                                inptr: v6,
                                VfDelta: 0,
                                SrcType: &CBaseFlex `RTTI Type Descriptor',
                                TargetType: &CAI_BaseActor `RTTI Type Descriptor',
                                isReference: 0);
        if ( v7 != nullptr && v7->IsAlive(this: v7) )
        {
          v8 = m_Size;
          if ( m_Size + 1 > candidates.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&candidates,
              num: m_Size - candidates.m_Memory.m_nAllocationCount + 1);
            m_Size = candidates.m_Size;
          }
          m_pMemory = candidates.m_Memory.m_pMemory;
          candidates.m_Size = ++m_Size;
          candidates.m_pElements = candidates.m_Memory.m_pMemory;
          if ( m_Size - v8 - 1 > 0 )
          {
            _V_memmove(
              dest: &candidates.m_Memory.m_pMemory[v8 + 1],
              src: &candidates.m_Memory.m_pMemory[v8],
              count: 4 * (m_Size - v8 - 1));
            m_pMemory = candidates.m_Memory.m_pMemory;
          }
          v10 = &m_pMemory[v8];
          v2 = (CSceneEntity *)v41;
          if ( v10 != nullptr )
            *v10 = v7;
        }
      }
      v11 = v2->m_pScene;
      v4 = ++i;
    }
    while ( v4 < CChoreoScene::GetNumActors(this: v11) );
    v13 = 0;
    if ( m_Size != 0 )
    {
      if ( v2->m_bIsPlayingBack.m_Value )
      {
        pszValue = v2->m_iName.m_Value.pszValue;
        memset(&validResponses, 0, sizeof(validResponses));
        if ( pszValue == nullptr )
          pszValue = locale;
        V_snprintf(pDest: modifiers, maxLen: 512, pFormat: "scene:%s", pszValue);
        p_value = &inputdata->value;
        v16 = inputdata->value.fieldType == FIELD_STRING;
        i = (int)&inputdata->value;
        if ( v16 )
        {
          iVal = (const char *)p_value->iVal;
          if ( p_value->iVal == 0 )
            iVal = locale;
        }
        else
        {
          iVal = variant_t::ToString(this: p_value);
        }
        ResponseRules::CRR_Concept::CRR_Concept(this: &concept, fromString: iVal);
        concept.m_hSpeaker.m_Index = -1;
        if ( m_Size > 0 )
        {
          do
          {
            v18 = candidates.m_Memory.m_pMemory[v13];
            ResponseRules::CriteriaSet::CriteriaSet(this: &set);
            v19 = v18->GetExpresser(this: v18);
            CAI_Expresser::GatherCriteria(this: v19, outputSet: &set, &concept, modifiers);
            ResponseRules::CRR_Response::CRR_Response(this: &response);
            v20 = v18->GetExpresser(this: v18);
            if ( CAI_Expresser::FindResponse(this: v20, outResponse: &response, &concept, criteria: &set) )
            {
              v23 = v18->GetExpresser(this: v18);
              ResponseDuration = CAI_Expresser::GetResponseDuration(this: v23, result: &response);
              if ( ResponseDuration > 0.0 )
              {
                slota = ResponseDuration;
                if ( CBaseFlex::PermitResponse(this: v18, response_length: slota) )
                {
                  ResponseRules::CRR_Response::CRR_Response(this: &inter.response);
                  ResponseRules::CRR_Response::operator=(this: &inter.response, from: &response);
                  inter.npc = v18;
                  CUtlVector<NPCInterjection,CUtlMemory<NPCInterjection,int>>::InsertBefore(
                    this: &validResponses,
                    elem: validResponses.m_Size,
                    src: &inter);
                  ResponseRules::CRR_Response::~CRR_Response(this: &inter.response);
                }
              }
              ResponseRules::CRR_Response::~CRR_Response(this: &response);
              CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &set.m_Lookup);
            }
            else
            {
              ResponseRules::CRR_Response::~CRR_Response(this: &response);
              CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::RemoveAll(this: &set.m_Lookup);
              v21 = set.m_Lookup.m_Elements.m_pMemory;
              set.m_Lookup.m_FirstFree = -1;
              if ( set.m_Lookup.m_Elements.m_nGrowSize >= 0 )
              {
                if ( set.m_Lookup.m_Elements.m_pMemory != nullptr )
                {
                  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: set.m_Lookup.m_Elements.m_pMemory);
                  v21 = nullptr;
                  set.m_Lookup.m_Elements.m_pMemory = nullptr;
                }
                set.m_Lookup.m_Elements.m_nAllocationCount = 0;
              }
              v22 = 0xFFFF;
              set.m_Lookup.m_LastAlloc.index = -1;
              if ( set.m_Lookup.m_Elements.m_nGrowSize >= 0 && v21 != nullptr )
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
            }
            ++v13;
          }
          while ( v13 < m_Size );
          if ( validResponses.m_Size >= 1 )
          {
            v25 = 0;
            slot = _RandomInt(this: (IUniformRandomStream *)v22, a2: 0, a3: validResponses.m_Size - 1);
            if ( validResponses.m_Size > 0 )
            {
              v26 = validResponses.m_Memory.m_pMemory;
              do
              {
                if ( v25 == slot )
                {
                  if ( *(_DWORD *)(i + 16) == 2 )
                  {
                    v27 = *(const char **)i;
                    if ( *(_DWORD *)i == 0 )
                      v27 = locale;
                  }
                  else
                  {
                    v27 = variant_t::ToString(this: (variant_t *)i);
                  }
                  ResponseRules::CRR_Concept::CRR_Concept(this: &v40, fromString: v27);
                  npc = v26->npc;
                  v41 = -1;
                  v29 = (int)npc->GetExpresser(this: npc);
                  if ( (*(unsigned __int8 (__thiscall **)(int, ResponseRules::CRR_Concept *, NPCInterjection *, _DWORD, _DWORD))(*(_DWORD *)v29 + 4))(
                         a1: v29,
                         a2: &v40,
                         a3: v26,
                         a4: 0,
                         a5: 0) != 0 )
                  {
                    LOWORD(v32) = v40;
                    ((void (__thiscall *)(CAI_BaseActor *, int, int, NPCInterjection *))npc->PostSpeakDispatchResponse)(
                      a1: npc,
                      a2: v32,
                      a3: v41,
                      a4: v26);
                  }
                }
                ++v25;
                ++v26;
              }
              while ( v25 < validResponses.m_Size );
            }
          }
        }
        v30 = validResponses.m_Size - 1;
        if ( validResponses.m_Size - 1 >= 0 )
        {
          v31 = &validResponses.m_Memory.m_pMemory[v30];
          do
          {
            ResponseRules::CRR_Response::~CRR_Response(this: &v31->response);
            --v31;
            --v30;
          }
          while ( v30 >= 0 );
        }
        if ( validResponses.m_Memory.m_nGrowSize >= 0 && validResponses.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validResponses.m_Memory.m_pMemory);
      }
      else
      {
        _RandomInt(this: v12, a2: 0, a3: m_Size - 1);
      }
      if ( candidates.m_Memory.m_nGrowSize >= 0 && candidates.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: candidates.m_Memory.m_pMemory);
    }
    else
    {
LABEL_14:
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&candidates);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209570
// Name: public: virtual void CSceneEntity::PitchShiftPlayback(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::PitchShiftPlayback(CSceneEntity *this, float fPitch)
{
  float v2; // xmm0_4
  CSceneEntity *v3; // edi
  CChoreoScene *m_pScene; // ecx
  CBaseFlex *v5; // esi
  const Vector *v6; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v8; // eax
  edict_t *m_pPev; // esi
  signed int v10; // esi
  CChoreoScene *v11; // ecx
  int v12; // esi
  char szBuff[256]; // [esp+18h] [ebp-188h] BYREF
  float attenuation[3]; // [esp+118h] [ebp-88h] BYREF
  char v15[12]; // [esp+124h] [ebp-7Ch] BYREF
  CPASAttenuationFilter filter; // [esp+130h] [ebp-70h] BYREF
  EmitSound_t params; // [esp+150h] [ebp-50h] BYREF
  CSceneEntity *v18; // [esp+198h] [ebp-8h]
  int iActor; // [esp+19Ch] [ebp-4h]
  int savedregs; // [esp+1A0h] [ebp+0h] BYREF

  v2 = 0.25;
  v3 = this;
  v18 = this;
  if ( fPitch >= 0.25 )
  {
    v2 = 2.5;
    if ( fPitch <= 2.5 )
      v2 = fPitch;
  }
  m_pScene = this->m_pScene;
  v3->m_fPitch = v2;
  if ( m_pScene != nullptr )
  {
    iActor = 0;
    if ( CChoreoScene::GetNumActors(this: m_pScene) > 0 )
    {
      do
      {
        v5 = v3->FindNamedActor_3(this: v3, a2: iActor);
        if ( v5 != nullptr && CChoreoScene::GetPlayingSoundName(this: v3->m_pScene, pchBuff: szBuff, iBuffLength: 256) )
        {
          v6 = (const Vector *)((int (__thiscall *)(CBaseFlex *))v5->GetSoundEmissionOrigin)(a1: v5);
          CRecipientFilter::CRecipientFilter(this: &filter);
          filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
          CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v6);
          GetSoundEmissionOrigin = v5->GetSoundEmissionOrigin;
          filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
          v8 = (const Vector *)((int (__thiscall *)(CBaseFlex *, char *, int))GetSoundEmissionOrigin)(
                                 a1: v5,
                                 a2: v15,
                                 a3: 1061997773);
          CPASAttenuationFilter::Filter(
            this: &filter,
            a2: (int)&savedregs,
            origin: v8,
            attenuation: COERCE_FLOAT(attenuation));
          m_pPev = v5->m_Network.m_pPev;
          params.m_flVolume = 1.0;
          params.m_nChannel = 0;
          params.m_SoundLevel = SNDLVL_NONE;
          memset(&params.m_pOrigin, 0, 12);
          *(_WORD *)&params.m_bEmitCloseCaption = 1;
          params.m_bWarnOnDirectWaveReference = false;
          params.m_nSpeakerEntity = -1;
          memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
          params.m_hSoundScriptHandle = -1;
          params.m_nSoundEntryVersion = 1;
          params.m_pSoundName = szBuff;
          params.m_nPitch = (int)(float)(v2 * 100.0);
          params.m_nFlags = 2;
          if ( m_pPev != nullptr )
            v10 = m_pPev - gpGlobals->pEdicts;
          else
            v10 = 0;
          CBaseEntity::EmitSound(&filter, iEntIndex: v10, &params);
          CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
          CRecipientFilter::~CRecipientFilter(this: &filter);
          v3 = v18;
        }
        v11 = v3->m_pScene;
        v12 = ++iActor;
      }
      while ( v12 < CChoreoScene::GetNumActors(this: v11) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209740
// Name: public: bool CSceneEntity::ScriptLoadSceneFromString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneEntity::ScriptLoadSceneFromString(
        CSceneEntity *this,
        const char *pszFilename,
        CAI_BaseNPC *pszData)
{
  CChoreoScene *v4; // eax
  CChoreoScene *v5; // esi
  IChoreoEventCallback *v7; // eax
  CSceneManager *SceneManager; // eax

  v4 = (CChoreoScene *)operator new(nSize: 0x21Cu);
  if ( v4 != nullptr )
    v5 = CChoreoScene::CChoreoScene(this: v4, callback: nullptr);
  else
    v5 = nullptr;
  CSceneTokenProcessor::SetBuffer(this: (CAI_Component *)&g_TokenProcessor, pOuter: pszData);
  if ( !CChoreoScene::ParseFromBuffer(this: v5, pFilename: pszFilename, tokenizer: &g_TokenProcessor) )
  {
    _Warning(a1: "CSceneEntity::LoadSceneFromString: Unable to parse scene data '%s'\n", pszFilename);
    if ( v5 != nullptr )
    {
      CChoreoScene::~CChoreoScene(this: v5);
      free(pMem: v5);
    }
    return 0;
  }
  vgui::Panel::SetCursor(this: (vgui::Panel *)v5, cursor: (unsigned int)Scene_Printf);
  if ( this != nullptr )
    v7 = &this->IChoreoEventCallback;
  else
    v7 = nullptr;
  CChoreoScene::SetEventCallbackInterface(this: v5, callback: v7);
  CSceneEntity::PrecacheScene(this, scene: v5);
  if ( v5 == nullptr )
    return 0;
  CSceneEntity::UnloadScene(this);
  this->m_pScene = v5;
  if ( GetSceneManager() != nullptr )
  {
    SceneManager = GetSceneManager();
    CSceneManager::ActivateScene(this: SceneManager, scene: this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10209810
// Name: public: virtual class CBaseFlex __near * CSceneEntity::FindNamedActor(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CSceneEntity::FindNamedActor(CSceneEntity *this, int index)
{
  int NumActors; // eax
  edict_t *m_pPev; // ecx
  const char *Filename; // eax
  vgui::Panel *result; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int v10; // ebx
  CSceneEntity_vtbl *v11; // edi
  vgui::Panel *v12; // eax
  CHandle<CBaseFlex> *v13; // edi
  edict_t *v14; // ecx
  int v15; // [esp-8h] [ebp-10h]
  int m_Size; // [esp-4h] [ebp-Ch]
  int indexa; // [esp+10h] [ebp+8h]

  if ( this->m_hActorList.m_Size == 0 )
  {
    NumActors = CChoreoScene::GetNumActors(this: this->m_pScene);
    this->m_hActorList.m_Size = 0;
    CUtlVector<CHandle<CFish>,CUtlMemory<CHandle<CFish>,int>>::InsertMultipleBefore(
      this: (CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *)&this->m_hActorList,
      elem: 0,
      num: NumActors);
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      m_pPev->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  if ( index < 0 || index >= this->m_hActorList.m_Size )
  {
    m_Size = this->m_hActorList.m_Size;
    v15 = CChoreoScene::GetNumActors(this: this->m_pScene);
    Filename = CChoreoScene::GetFilename(this: this->m_pScene);
    DevWarning(a1: "Scene %s has %d actors, but scene entity only has %d actors\n", Filename, v15, m_Size);
    return nullptr;
  }
  m_Index = this->m_hActorList.m_Memory.m_pMemory[index].m_Index;
  indexa = index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v10 = (int)m_pEntity;
  if ( m_pEntity == nullptr || m_pEntity->__vftable[22].GetRefEHandle(this: m_pEntity) == nullptr )
  {
    result = (vgui::Panel *)CChoreoScene::GetActor(this: this->m_pScene, actor: index);
    if ( result == nullptr )
      return result;
    v11 = this->CPointEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v12 = CBasePlayer::ActivePlayerCombatCharacter(this: result);
    v10 = (int)v11->FindNamedActor(this, a2: (const char *)v12);
    if ( v10 != 0 )
    {
      v13 = &this->m_hActorList.m_Memory.m_pMemory[indexa];
      v13->m_Index = *(unsigned int *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      v14 = this->m_Network.m_pPev;
      if ( v14 != nullptr )
      {
        v14->m_fStateFlags |= 0x101u;
        CBaseEdict::GetChangeAccessor(this: &v14->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
      }
    }
  }
  return (vgui::Panel *)v10;
}

//------------------------------------------------------------------------------
// Address: 0x10209960
// Name: public: virtual bool CSceneEntity::InterruptThisScene(class CSceneEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneEntity::InterruptThisScene(CSceneEntity *this, CSceneEntity *otherScene)
{
  if ( this->m_nInterruptCount <= 0 || this->m_bInterrupted )
    return 0;
  this->m_bInterrupted = true;
  if ( otherScene != nullptr )
    this->m_hInterruptScene.m_Index = otherScene->GetRefEHandle(this: otherScene)->m_Index;
  else
    this->m_hInterruptScene.m_Index = -1;
  CSceneEntity::RequestCompletionNotification(this: otherScene, notify: this);
  this->PausePlayback(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102099D0
// Name: public: virtual void CInstancedSceneEntity::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInstancedSceneEntity::OnRestore(CInstancedSceneEntity *this)
{
  unsigned int m_Index; // ecx
  CChoreoScene *m_pScene; // ecx

  if ( !this->m_bHadOwner
    || (m_Index = this->m_hOwner.m_Index) != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    m_pScene = this->m_pScene;
    if ( m_pScene != nullptr )
      CChoreoScene::SetBackground(this: m_pScene, bIsBackground: this->m_bIsBackground);
    CSceneEntity::OnRestore(this);
  }
  else
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209A40
// Name: public: virtual void CSceneListManager::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneListManager::Activate(CSceneListManager *this)
{
  CHandle<CBaseEntity> *m_hScenes; // edi
  const char *m_Index; // eax
  CBaseEntity *EntityByName; // eax
  unsigned int v5; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *m_pEntity; // eax
  CSceneEntity *v13; // eax
  unsigned int v14; // eax
  IHandleEntity *v15; // ecx
  CSceneListManager *v16; // eax
  const char *v17; // eax
  const char *DebugName; // eax
  const char *v19; // eax
  const char *v20; // eax
  const char *Classname; // [esp-14h] [ebp-1Ch]
  const char *v22; // [esp-14h] [ebp-1Ch]
  const char *v23; // [esp-Ch] [ebp-14h]
  const char *v24; // [esp-Ch] [ebp-14h]
  int i; // [esp+4h] [ebp-4h]

  CBaseEntity::Activate(this);
  if ( gpGlobals->eLoadType != MapLoad_LoadGame )
  {
    i = 0;
    m_hScenes = this->m_hScenes;
    do
    {
      m_Index = (const char *)m_hScenes[-16].m_Index;
      if ( m_Index != nullptr )
      {
        EntityByName = CGlobalEntityList::FindEntityByName(
                         this: &gEntList,
                         pStartEntity: nullptr,
                         szName: m_Index,
                         pSearchingEntity: nullptr,
                         pActivator: nullptr,
                         pCaller: nullptr,
                         pFilter: nullptr);
        if ( EntityByName != nullptr )
          m_hScenes->m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
        else
          m_hScenes->m_Index = -1;
        v5 = m_hScenes->m_Index;
        if ( m_hScenes->m_Index != -1
          && (v6 = (unsigned __int16)v5,
              v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v5],
              v8 = HIWORD(v5),
              v7->m_SerialNumber == v8)
          && v7->m_pEntity != nullptr )
        {
          v9 = v6;
          v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
          v11 = &g_pEntityList->m_EntPtrArray[v9];
          if ( v10 )
            m_pEntity = v11->m_pEntity;
          else
            m_pEntity = nullptr;
          v13 = (CSceneEntity *)__RTDynamicCast(
                                  inptr: m_pEntity,
                                  VfDelta: 0,
                                  SrcType: &CBaseEntity `RTTI Type Descriptor',
                                  TargetType: &CSceneEntity `RTTI Type Descriptor',
                                  isReference: 0);
          if ( v13 != nullptr )
          {
            CSceneEntity::AddListManager(this: v13, pManager: this);
          }
          else
          {
            v14 = m_hScenes->m_Index;
            if ( m_hScenes->m_Index == -1
              || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
            {
              v15 = nullptr;
            }
            else
            {
              v15 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
            }
            v16 = (CSceneListManager *)__RTDynamicCast(
                                         inptr: v15,
                                         VfDelta: 0,
                                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                                         TargetType: &CSceneListManager `RTTI Type Descriptor',
                                         isReference: 0);
            if ( v16 != nullptr )
            {
              CSceneListManager::AddListManager(this: v16, pManager: this);
            }
            else
            {
              v17 = (const char *)m_hScenes[-16].m_Index;
              if ( v17 == nullptr )
                v17 = locale;
              v23 = v17;
              Classname = CBaseEntity::GetClassname(this);
              DebugName = CBaseEntity::GetDebugName(this);
              _Warning(
                a1: "%s(%s) found an entity that wasn't a logic_choreographed_scene or logic_scene_list_manager in slot %d, named %s\n",
                DebugName,
                Classname,
                i,
                v23);
              m_hScenes->m_Index = -1;
            }
          }
        }
        else
        {
          v19 = (const char *)m_hScenes[-16].m_Index;
          if ( v19 == nullptr )
            v19 = locale;
          v24 = v19;
          v22 = CBaseEntity::GetClassname(this);
          v20 = CBaseEntity::GetDebugName(this);
          _Warning(a1: "%s(%s) could not find scene %d, named %s\n", v20, v22, i, v24);
        }
      }
      ++m_hScenes;
      ++i;
    }
    while ( i < 16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B310
// Name: public: void CSceneEntity::BuildSortedSpeakEventSoundsPrefetchList(class CChoreoScene __near *,class CUtlSymbolTable __near &,class CUtlRBTree<struct CSceneEntity::SpeakEventSound_t,unsigned short,bool (*)(struct CSceneEntity::SpeakEventSound_t const __near &,struct CSceneEntity::SpeakEventSound_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSceneEntity::SpeakEventSound_t,unsigned short>,unsigned short>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::BuildSortedSpeakEventSoundsPrefetchList(
        CSceneEntity *this,
        CChoreoScene *scene,
        CUtlSymbolTable *table,
        CUtlRBTree<CSceneEntity::SpeakEventSound_t,unsigned short,bool (__cdecl*)(CSceneEntity::SpeakEventSound_t const &,CSceneEntity::SpeakEventSound_t const &),CUtlMemory<UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short>,unsigned short> > *soundnames,
        float timeOffset)
{
  CChoreoScene *v5; // ebx
  int v6; // edi
  CUtlRBTree<CSceneEntity::SpeakEventSound_t,unsigned short,bool (__cdecl*)(CSceneEntity::SpeakEventSound_t const &,CSceneEntity::SpeakEventSound_t const &),CUtlMemory<UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short>,unsigned short> > *v7; // esi
  CChoreoEvent *Event; // eax
  CChoreoEvent *v9; // edi
  CChoreoEvent::EVENTTYPE Type; // eax
  IChoreoEventCallback *v11; // eax
  const char *v12; // eax
  CChoreoScene *v13; // ebx
  const char *Parameters; // eax
  CBasePlayer *LocalPlayer; // eax
  double StartTime; // st7
  unsigned __int16 v17; // ax
  unsigned __int16 v18; // dx
  unsigned __int16 v19; // cx
  int v20; // edi
  UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short> *v21; // eax
  UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short> *m_pMemory; // eax
  int v23; // edx
  UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short> *v24; // ecx
  CSceneEntity::SpeakEventSound_t *p_m_Data; // edi
  IChoreoEventCallback *v26; // [esp+0h] [ebp-68h]
  float v27; // [esp+0h] [ebp-68h]
  char soundname[64]; // [esp+10h] [ebp-58h] BYREF
  CSceneEntity::SpeakEventSound_t ses; // [esp+50h] [ebp-18h] BYREF
  int i; // [esp+58h] [ebp-10h]
  unsigned __int16 parent[2]; // [esp+5Ch] [ebp-Ch] BYREF
  CSceneEntity *v32; // [esp+60h] [ebp-8h]
  CUtlSymbol result; // [esp+66h] [ebp-2h] BYREF

  v5 = scene;
  v32 = this;
  v6 = 0;
  i = 0;
  if ( vgui::Image::GetTall(this: (vgui::Image *)scene) > 0 )
  {
    v7 = soundnames;
    do
    {
      Event = CChoreoScene::GetEvent(this: v5, event: v6);
      v9 = Event;
      if ( Event != nullptr )
      {
        Type = CChoreoEvent::GetType(this: Event);
        if ( Type == SPEAK )
        {
          Parameters = CChoreoEvent::GetParameters(this: v9);
          V_strncpy(pDest: soundname, pSrc: Parameters, maxLen: 64);
          if ( CChoreoEvent::GetCloseCaptionType(this: v9) == CC_MASTER )
            CChoreoEvent::GetPlaybackCloseCaptionToken(this: v9, dest: soundname, destlen: 64);
          if ( gpGlobals->maxClients != 1
            || (LocalPlayer = UTIL_GetLocalPlayer()) == nullptr
            || CSceneEntity::GetSoundNameForPlayer(
                 this: v32,
                 event: v9,
                 player: LocalPlayer,
                 buf: soundname,
                 buflen: 0x40u) != 0 )
          {
            ses.m_Symbol.m_Id = -1;
            ses.m_Symbol = (CUtlSymbol)CUtlSymbolTable::AddString(this: table, &result, pString: soundname)->m_Id;
            StartTime = CChoreoEvent::GetStartTime(this: v9);
            ses.m_flStartTime = StartTime + timeOffset;
            *(_DWORD *)parent = 0xFFFF;
            HIBYTE(soundnames) = 0;
            CUtlRBTree<CSceneEntity::SpeakEventSound_t,unsigned short,bool (__cdecl *)(CSceneEntity::SpeakEventSound_t const &,CSceneEntity::SpeakEventSound_t const &),CUtlMemory<UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short>,unsigned short>>::FindInsertionPosition(
              this: v7,
              insert: &ses,
              parent,
              leftchild: (bool *)&soundnames + 3);
            v17 = CUtlRBTree<CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
                    this: (CUtlRBTree<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)v7,
                    a2: (const char *)v9);
            v18 = parent[0];
            v19 = v17;
            v20 = v17;
            v21 = &v7->m_Elements.m_pMemory[v20];
            v21->m_Right = -1;
            v21->m_Left = -1;
            v21->m_Parent = v18;
            v21->m_Tag = 0;
            if ( v18 == 0xFFFF )
            {
              v7->m_Root = v19;
            }
            else
            {
              m_pMemory = v7->m_Elements.m_pMemory;
              v23 = v18;
              if ( HIBYTE(soundnames) != 0 )
                m_pMemory[v23].m_Left = v19;
              else
                m_pMemory[v23].m_Right = v19;
            }
            CUtlRBTree<CSceneEntity::SpeakEventSound_t,unsigned short,bool (__cdecl *)(CSceneEntity::SpeakEventSound_t const &,CSceneEntity::SpeakEventSound_t const &),CUtlMemory<UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short>,unsigned short>>::InsertRebalance(
              this: v7,
              elem: v19);
            v24 = v7->m_Elements.m_pMemory;
            ++v7->m_NumElements;
            p_m_Data = &v24[v20].m_Data;
            if ( p_m_Data != nullptr )
              *p_m_Data = ses;
          }
        }
        else if ( Type == SUBSCENE
               && !CChoreoScene::IsSubScene(this: v5)
               && CChoreoEvent::GetSubScene(this: (vgui::Panel *)v9) == 0 )
        {
          if ( v32 != nullptr )
            v11 = &v32->IChoreoEventCallback;
          else
            v11 = nullptr;
          v26 = v11;
          v12 = CChoreoEvent::GetParameters(this: v9);
          v13 = (CChoreoScene *)CSceneEntity::LoadScene(filename: v12, pCallback: v26);
          CChoreoScene::SetSubScene(this: v13, sub: true);
          CChoreoEvent::SetSubScene(this: v9, scene: v13);
          v27 = CChoreoEvent::GetStartTime(this: v9);
          CSceneEntity::BuildSortedSpeakEventSoundsPrefetchList(
            this: v32,
            scene: v13,
            table,
            soundnames: v7,
            timeOffset: v27);
        }
      }
      v5 = scene;
      v6 = ++i;
    }
    while ( v6 < vgui::Image::GetTall(this: (vgui::Image *)scene) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B520
// Name: public: virtual void CScenePrecacheSystem::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScenePrecacheSystem::LevelShutdownPreEntity(CModelPrecacheSystem *this)
{
  CUtlMap<int,int,unsigned short> *p_m_RepeatCounts; // esi

  p_m_RepeatCounts = &this->m_RepeatCounts;
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_RepeatCounts.m_Tree);
  p_m_RepeatCounts->m_Tree.m_FirstFree = -1;
  if ( p_m_RepeatCounts->m_Tree.m_Elements.m_nGrowSize < 0 )
  {
    p_m_RepeatCounts->m_Tree.m_LastAlloc.index = -1;
  }
  else
  {
    if ( p_m_RepeatCounts->m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_RepeatCounts->m_Tree.m_Elements.m_pMemory);
      p_m_RepeatCounts->m_Tree.m_Elements.m_pMemory = nullptr;
    }
    p_m_RepeatCounts->m_Tree.m_Elements.m_nAllocationCount = 0;
    p_m_RepeatCounts->m_Tree.m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B5A0
// Name: void InitCSceneEntityScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCSceneEntityScriptDesc()
{
  ScriptFunctionBinding_t *v0; // eax
  ScriptFunctionBinding_t *v1; // eax
  ScriptFunctionBinding_t *v2; // eax
  ScriptFunctionBinding_t *v3; // esi
  ScriptFunctionBinding_t *v4; // esi
  ScriptFunctionBinding_t *v5; // esi
  ScriptFunctionBinding_t *v6; // esi

  if ( !bInitialized_5 )
  {
    bInitialized_5 = true;
    g_CSceneEntity_ScriptDesc.m_pszDescription = "Choreographed scene which controls animation and/or dialog on one or more actors.";
    g_CSceneEntity_ScriptDesc.m_pszScriptName = "CSceneEntity";
    g_CSceneEntity_ScriptDesc.m_pszClassname = "CSceneEntity";
    g_CSceneEntity_ScriptDesc.m_pBaseDesc = GetScriptDesc(__formal: nullptr);
    g_CSceneEntity_ScriptDesc.pHelper = GetScriptInstanceHelper_CBaseEntity();
    v0 = &g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CSceneEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v0->m_desc.m_pszDescription = "Returns length of this scene in seconds.";
    v0->m_desc.m_pszScriptName = "EstimateLength";
    v0->m_desc.m_pszFunction = "EstimateLength";
    v0->m_desc.m_ReturnType = 1;
    v0->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CSceneEntity *,float (__thiscall CSceneEntity::*)(void),float>::Call;
    v0->m_pFunction =  __thiscall CSceneEntity::`vcall'{936,{flat}};
    v0->m_flags = 1;
    v1 = &g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CSceneEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v1->m_desc.m_pszDescription = "If this scene is currently playing.";
    v1->m_desc.m_pszScriptName = "IsPlayingBack";
    v1->m_desc.m_pszFunction = "IsPlayingBack";
    v1->m_desc.m_ReturnType = 6;
    v1->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CBasePlayer *,bool (__thiscall CBasePlayer::*)(void),bool>::Call;
    v1->m_pFunction = CSceneEntity::IsPlayingBack;
    v1->m_flags = 1;
    v2 = &g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CSceneEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v2->m_desc.m_pszDescription = "If this scene is currently paused.";
    v2->m_desc.m_pszScriptName = "IsPaused";
    v2->m_desc.m_pszFunction = "IsPaused";
    v2->m_desc.m_ReturnType = 6;
    v2->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CBasePlayer *,bool (__thiscall CBasePlayer::*)(void),bool>::Call;
    v2->m_pFunction = CSceneEntity::IsPaused;
    v2->m_flags = 1;
    v3 = &g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CSceneEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v3->m_desc.m_pszDescription = "Adds a team (by index) to the broadcast list";
    v3->m_desc.m_pszScriptName = "AddBroadcastTeamTarget";
    v3->m_desc.m_pszFunction = "AddBroadcastTeamTarget";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,int>(pDesc: &v3->m_desc);
    v3->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(HSCRIPT__ *),void,HSCRIPT__ *>::Call;
    v3->m_pFunction = CSceneEntity::AddBroadcastTeamTarget;
    v3->m_flags = 1;
    v4 = &g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CSceneEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v4->m_desc.m_pszDescription = "Removes a team (by index) from the broadcast list";
    v4->m_desc.m_pszScriptName = "RemoveBroadcastTeamTarget";
    v4->m_desc.m_pszFunction = "RemoveBroadcastTeamTarget";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,int>(pDesc: &v4->m_desc);
    v4->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(HSCRIPT__ *),void,HSCRIPT__ *>::Call;
    v4->m_pFunction = CSceneEntity::RemoveBroadcastTeamTarget;
    v4->m_flags = 1;
    v5 = &g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CSceneEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v5->m_desc.m_pszDescription = "given an entity reference, such as !target, get actual entity from scene object";
    v5->m_desc.m_pszScriptName = "FindNamedEntity";
    v5->m_desc.m_pszFunction = "ScriptFindNamedEntity";
    ScriptDeduceFunctionSignature<CScriptEntityIterator *,CScriptEntityIterator,HSCRIPT__ *,char const *>(
      pDesc: &v5->m_desc,
      pObject: nullptr,
      pfnProxied: (HSCRIPT__ *(__thiscall *__ptr64)(CSceneEntity *, const char *))(unsigned int)CSceneEntity::ScriptFindNamedEntity);
    v5->m_pfnBinding = CMemberScriptBinding1<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(char const *),HSCRIPT__ *,char const *>::Call;
    v5->m_pFunction = CSceneEntity::ScriptFindNamedEntity;
    v5->m_flags = 1;
    v6 = &g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CSceneEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CSceneEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v6->m_desc.m_pszDescription = "given a dummy scene name and a vcd string, load the scene";
    v6->m_desc.m_pszScriptName = "LoadSceneFromString";
    v6->m_desc.m_pszFunction = "ScriptLoadSceneFromString";
    ScriptDeduceFunctionSignature<CSceneEntity *,CSceneEntity,bool,char const *,char const *>(pDesc: &v6->m_desc);
    v6->m_flags = 1;
    v6->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CSceneEntity *,bool (__thiscall CSceneEntity::*)(char const *,char const *),bool,char const *,char const *>::Call;
    v6->m_pFunction = CSceneEntity::ScriptLoadSceneFromString;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B820
// Name: private: void CSceneEntity::PrefetchAnimBlocks(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::PrefetchAnimBlocks(CSceneEntity *this, CChoreoScene *scene)
{
  int v2; // esi
  IMDLCache *m_pCache; // edi
  void (__thiscall *BeginLock)(IMDLCache *); // eax
  CChoreoScene *v5; // ebx
  CChoreoEvent *v6; // eax
  CChoreoEvent *v7; // ebx
  CChoreoActor *Actor; // eax
  CChoreoActor *v9; // esi
  unsigned __int16 v10; // ax
  CBaseFlex *elem; // edi
  unsigned __int16 v12; // ax
  unsigned __int16 v13; // dx
  int v14; // ecx
  UtlRBTreeNode_t<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v16; // esi
  int v17; // edx
  CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t *p_m_Data; // esi
  const char *Parameters; // eax
  int v20; // esi
  CStudioHdr *ModelPtr; // eax
  CStudioHdr *v22; // edi
  mstudioseqdesc_t *v23; // esi
  CChoreoEvent *v24; // edx
  int v25; // eax
  int v26; // ebx
  int v27; // eax
  int v28; // ecx
  char *v29; // edx
  int v30; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v32; // esi
  mstudioanimdesc_t *v33; // esi
  int v34; // ebx
  char *v35; // eax
  int v36; // ebx
  char *v37; // eax
  char *v38; // eax
  int v39; // eax
  const char *v40; // [esp-Ch] [ebp-78h]
  const char *v41; // [esp-Ch] [ebp-78h]
  CChoreoEvent *v42; // [esp-8h] [ebp-74h]
  CChoreoEvent *v43; // [esp-8h] [ebp-74h]
  int animblock; // [esp-4h] [ebp-70h]
  int v45; // [esp-4h] [ebp-70h]
  int v46; // [esp-4h] [ebp-70h]
  CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short> actorMap; // [esp+Ch] [ebp-60h] BYREF
  CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t search; // [esp+28h] [ebp-44h] BYREF
  CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t insert; // [esp+30h] [ebp-3Ch] BYREF
  int iFrame; // [esp+38h] [ebp-34h] BYREF
  int seq; // [esp+3Ch] [ebp-30h]
  CSceneEntity *v52; // [esp+40h] [ebp-2Ch]
  int i; // [esp+44h] [ebp-28h]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+48h] [ebp-24h]
  int v55; // [esp+4Ch] [ebp-20h]
  int resident; // [esp+50h] [ebp-1Ch]
  int checked; // [esp+54h] [ebp-18h]
  int spew; // [esp+58h] [ebp-14h]
  mstudioseqdesc_t *seqdesc; // [esp+5Ch] [ebp-10h] BYREF
  CChoreoEvent *event; // [esp+60h] [ebp-Ch]
  int j; // [esp+64h] [ebp-8h]
  bool leftchild; // [esp+6Bh] [ebp-1h] BYREF

  v2 = 0;
  v52 = this;
  actorMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(CChoreoActor *const *, CChoreoActor *const *))CDefOps<CChoreoActor *>::LessFunc;
  memset(&actorMap.m_Tree.m_Elements, 0, sizeof(actorMap.m_Tree.m_Elements));
  *(_DWORD *)&actorMap.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&actorMap.m_Tree.m_FirstFree = -1;
  actorMap.m_Tree.m_pElements = nullptr;
  if ( scene_async_prefetch_spew.m_pParent != nullptr )
    spew = scene_async_prefetch_spew.m_pParent->m_Value.m_nValue;
  else
    spew = 0;
  m_pCache = mdlcache;
  BeginLock = mdlcache->BeginLock;
  resident = 0;
  checked = 0;
  cacheCriticalSection.m_pCache = mdlcache;
  BeginLock(this: mdlcache);
  v5 = scene;
  i = 0;
  if ( vgui::Image::GetTall(this: (vgui::Image *)scene) > 0 )
  {
    do
    {
      v6 = CChoreoScene::GetEvent(this: v5, event: v2);
      v7 = v6;
      event = v6;
      if ( v6 != nullptr && (unsigned int)(CChoreoEvent::GetType(this: v6) - 6) <= 1 )
      {
        Actor = CChoreoEvent::GetActor(this: v7);
        v9 = Actor;
        if ( Actor != nullptr )
        {
          search.key = Actor;
          v10 = CUtlRBTree<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short,CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                  this: &actorMap.m_Tree,
                  &search);
          if ( v10 == 0xFFFF )
          {
            elem = v52->FindNamedActor_2(this: v52, a2: v9);
            insert.key = v9;
            insert.elem = elem;
            seqdesc = (mstudioseqdesc_t *)0xFFFF;
            leftchild = false;
            CUtlRBTree<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short,CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
              this: &actorMap.m_Tree,
              &insert,
              parent: (unsigned __int16 *)&seqdesc,
              &leftchild);
            v12 = CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
                    this: (CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short> > *)&actorMap,
                    a2: (const char *)elem);
            v13 = (unsigned __int16)seqdesc;
            v14 = v12;
            m_pMemory = actorMap.m_Tree.m_Elements.m_pMemory;
            v16 = v14;
            actorMap.m_Tree.m_Elements.m_pMemory[v16].m_Right = -1;
            m_pMemory[v16].m_Left = -1;
            m_pMemory[v16].m_Tag = 0;
            m_pMemory[v16].m_Parent = v13;
            if ( v13 == 0xFFFF )
            {
              actorMap.m_Tree.m_Root = v14;
            }
            else
            {
              v17 = v13;
              if ( leftchild )
                m_pMemory[v17].m_Left = v14;
              else
                m_pMemory[v17].m_Right = v14;
            }
            CUtlRBTree<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short,CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
              this: &actorMap.m_Tree,
              elem: v14);
            ++actorMap.m_Tree.m_NumElements;
            v7 = event;
            p_m_Data = &actorMap.m_Tree.m_Elements.m_pMemory[v16].m_Data;
            if ( p_m_Data != nullptr )
              *p_m_Data = insert;
          }
          else
          {
            elem = actorMap.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem;
          }
          if ( elem != nullptr )
          {
            Parameters = CChoreoEvent::GetParameters(this: v7);
            v20 = CBaseAnimating::LookupSequence(this: elem, label: Parameters);
            seq = v20;
            if ( v20 >= 0 )
            {
              ModelPtr = CBaseAnimating::GetModelPtr(this: elem);
              v22 = ModelPtr;
              if ( ModelPtr != nullptr )
              {
                v23 = CStudioHdr::pSeqdesc(this: ModelPtr, iSequence: v20);
                v24 = nullptr;
                seqdesc = v23;
                event = nullptr;
                if ( v23->groupsize[0] > 0 )
                {
                  while ( 1 )
                  {
                    v25 = v23->groupsize[1];
                    v26 = 0;
                    j = 0;
                    v55 = v25;
                    if ( v25 > 0 )
                      break;
LABEL_42:
                    v24 = (CChoreoEvent *)((char *)v24 + 1);
                    event = v24;
                    if ( (int)v24 >= v23->groupsize[0] )
                      goto LABEL_43;
                  }
                  while ( 2 )
                  {
                    v27 = v23->groupsize[0];
                    v28 = v26;
                    if ( (int)v24 >= v27 )
                      v24 = (CChoreoEvent *)(v27 - 1);
                    if ( j >= v55 )
                      v28 = v55 - 1;
                    v29 = (char *)v23 + 2 * ((_DWORD)v24 + v28 * v27);
                    v30 = *(__int16 *)&v29[v23->animindexindex];
                    if ( v22->m_pVModel != nullptr
                      && (v30 = CStudioHdr::iRelativeAnim_Internal(
                                  this: v22,
                                  baseseq: seq,
                                  relanim: *(__int16 *)&v29[v23->animindexindex]),
                          v22->m_pVModel != nullptr) )
                    {
                      v33 = CStudioHdr::pAnimdesc_Internal(this: v22, i: v30);
                    }
                    else
                    {
                      m_pStudioHdr = v22->m_pStudioHdr;
                      v32 = v30;
                      if ( v30 < 0 || v30 >= m_pStudioHdr->numlocalanim )
                        v32 = 0;
                      v33 = (mstudioanimdesc_t *)((char *)m_pStudioHdr + 100 * v32 + m_pStudioHdr->localanimindex);
                    }
                    v34 = spew;
                    ++checked;
                    if ( spew != 0 )
                    {
                      animblock = v33->animblock;
                      v35 = CStudioHdr::name(this: v22);
                      _Msg(a1: "%s checking block %d\n", v35, animblock);
                    }
                    iFrame = 0;
                    if ( mstudioanimdesc_t::pAnim(this: v33, piFrame: &iFrame) != nullptr )
                    {
                      ++resident;
                      if ( v34 > 1 )
                      {
                        v36 = j;
                        v45 = j;
                        v42 = event;
                        v40 = (char *)v33 + v33->sznameindex;
                        v37 = CStudioHdr::name(this: v22);
                        _Msg(a1: "%s:%s[%i:%i] was resident\n", v37, v40, v42, v45);
                        goto LABEL_41;
                      }
LABEL_40:
                      v36 = j;
                    }
                    else
                    {
                      if ( v34 == 0 )
                        goto LABEL_40;
                      v36 = j;
                      v46 = j;
                      v43 = event;
                      v41 = (char *)v33 + v33->sznameindex;
                      v38 = CStudioHdr::name(this: v22);
                      _Msg(a1: "%s:%s[%i:%i] async load\n", v38, v41, v43, v46);
                    }
LABEL_41:
                    v39 = seqdesc->groupsize[1];
                    v26 = v36 + 1;
                    v23 = seqdesc;
                    v24 = event;
                    j = v26;
                    v55 = v39;
                    if ( v26 >= v39 )
                      goto LABEL_42;
                    continue;
                  }
                }
              }
            }
          }
LABEL_43:
          m_pCache = cacheCriticalSection.m_pCache;
        }
      }
      v5 = scene;
      v2 = ++i;
    }
    while ( v2 < vgui::Image::GetTall(this: (vgui::Image *)scene) );
  }
  if ( spew != 0 && checked > 0 )
  {
    _Msg(a1: "%d of %d animations resident\n", resident, checked);
    m_pCache->EndLock(this: m_pCache);
    CUtlRBTree<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short,CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short,CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &actorMap.m_Tree);
  }
  else
  {
    m_pCache->EndLock(this: m_pCache);
    CUtlRBTree<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short,CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CChoreoActor *,CBaseFlex *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &actorMap.m_Tree);
    if ( actorMap.m_Tree.m_Elements.m_nGrowSize >= 0 && actorMap.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: actorMap.m_Tree.m_Elements.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BBD0
// Name: public: virtual void CSceneEntity::StartPlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::StartPlayback(CSceneEntity *this)
{
  int v2; // ebx
  const char *pszValue; // eax
  CChoreoScene *Scene; // eax
  const char *v5; // eax
  CSceneManager *SceneManager; // eax
  const char *v7; // eax
  int v8; // ebx
  edict_t *m_pPev; // ecx
  edict_t *v10; // ecx
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  edict_t *v13; // ecx
  CBaseEntityList *v14; // edi
  CHandle<CSceneListManager> *m_pMemory; // ecx
  unsigned int m_Index; // eax
  CHandle<CSceneListManager> *v17; // edx
  unsigned int v18; // eax
  CSceneListManager *m_pEntity; // ecx
  CChoreoScene *m_pScene; // [esp+8h] [ebp-74h]
  CUtlSymbolTable prefetchSoundSymbolTable; // [esp+24h] [ebp-58h] BYREF
  CUtlRBTree<CSceneEntity::SpeakEventSound_t,unsigned short,bool (__cdecl*)(CSceneEntity::SpeakEventSound_t const &,CSceneEntity::SpeakEventSound_t const &),CUtlMemory<UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short>,unsigned short> > soundnames; // [esp+5Ch] [ebp-20h] BYREF
  int c; // [esp+78h] [ebp-4h]

  v2 = 0;
  if ( this->m_pScene == nullptr )
  {
    if ( this->m_bSceneMissing )
      return;
    pszValue = this->m_iszSceneFile.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    Scene = (CChoreoScene *)CSceneEntity::LoadScene(filename: pszValue, pCallback: &this->IChoreoEventCallback);
    this->m_pScene = Scene;
    if ( Scene == nullptr )
    {
      v5 = this->m_iszSceneFile.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      DevMsg(a1: "%s missing from scenes.image\n", v5);
      this->m_bSceneMissing = true;
      return;
    }
    if ( GetSceneManager() != nullptr )
    {
      SceneManager = GetSceneManager();
      CSceneManager::ActivateScene(this: SceneManager, scene: this);
    }
    this->OnLoaded(this);
    if ( CSceneEntity::ShouldNetwork(this) )
    {
      v7 = this->m_iszSceneFile.pszValue;
      if ( v7 == nullptr )
        v7 = locale;
      v8 = g_pStringTableClientSideChoreoScenes->AddString(
             this: g_pStringTableClientSideChoreoScenes,
             a2: true,
             a3: v7,
             a4: -1,
             a5: nullptr);
      if ( this->m_nSceneStringIndex.m_Value != v8 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x400u);
        }
        this->m_nSceneStringIndex.m_Value = v8;
      }
      v2 = 0;
    }
    this->UpdateTransmitState(this);
  }
  if ( !this->m_bIsPlayingBack.m_Value && CSceneEntity::CheckActors(this) != 0 )
  {
    this->m_bCompletedEarly = false;
    *(_WORD *)&this->m_bWaitingForActor = 0;
    if ( !this->m_bIsPlayingBack.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x3A8u);
      }
      this->m_bIsPlayingBack.m_Value = true;
    }
    v11 = this->m_Network.m_pPev;
    if ( v11 != nullptr )
    {
      v11->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v11->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
    if ( this->m_bPaused.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v12 = this->m_Network.m_pPev;
        if ( v12 != nullptr )
          CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x3A9u);
      }
      this->m_bPaused.m_Value = false;
    }
    this->m_flCurrentTime = 0.0;
    if ( this->m_flForceClientTime.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v13 = this->m_Network.m_pPev;
        if ( v13 != nullptr )
          CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x3ACu);
      }
      this->m_flForceClientTime.m_Value = 0.0;
    }
    CChoreoScene::ResetSimulation(this: this->m_pScene, forward: true, starttime: 0.0, endtime: 0.0);
    this->ClearInterrupt(this);
    CSceneEntity::ClearSceneEvents(this, scene: this->m_pScene, canceled: false);
    COutputEvent::FireOutput(this: &this->m_OnStart, pActivator: this, pCaller: this, fDelay: 0.0);
    CUtlSymbolTable::CUtlSymbolTable(this: &prefetchSoundSymbolTable, growSize: 0, initSize: 16, caseInsensitive: false);
    m_pScene = this->m_pScene;
    soundnames.m_LessFunc = (bool (__cdecl *)(const CSceneEntity::SpeakEventSound_t *, const CSceneEntity::SpeakEventSound_t *))CSceneEntity::SpeakEventSoundLessFunc;
    memset(&soundnames.m_Elements, 0, sizeof(soundnames.m_Elements));
    *(_DWORD *)&soundnames.m_Root = 0xFFFF;
    *(_DWORD *)&soundnames.m_FirstFree = -1;
    soundnames.m_pElements = nullptr;
    CSceneEntity::BuildSortedSpeakEventSoundsPrefetchList(
      this,
      scene: m_pScene,
      table: &prefetchSoundSymbolTable,
      &soundnames,
      timeOffset: 0.0);
    CSceneEntity::PrefetchSpeakEventSounds(this, table: &prefetchSoundSymbolTable, &soundnames);
    c = this->m_hListManagers.m_Size;
    if ( c > 0 )
    {
      v14 = g_pEntityList;
      do
      {
        m_pMemory = this->m_hListManagers.m_Memory.m_pMemory;
        m_Index = m_pMemory[v2].m_Index;
        v17 = &m_pMemory[v2];
        if ( m_Index != -1
          && v14->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
          && v14->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
        {
          v18 = v17->m_Index;
          if ( v17->m_Index == -1 || v14->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18) )
            m_pEntity = nullptr;
          else
            m_pEntity = (CSceneListManager *)v14->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
          CSceneListManager::SceneStarted(this: m_pEntity, pSceneOrManager: this);
          v14 = g_pEntityList;
        }
        ++v2;
      }
      while ( v2 < c );
    }
    CSceneEntity::PrefetchAnimBlocks(this, scene: this->m_pScene);
    CUtlRBTree<CSceneEntity::SpeakEventSound_t,unsigned short,bool (__cdecl *)(CSceneEntity::SpeakEventSound_t const &,CSceneEntity::SpeakEventSound_t const &),CUtlMemory<UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short>,unsigned short>>::~CUtlRBTree<CSceneEntity::SpeakEventSound_t,unsigned short,bool (__cdecl *)(CSceneEntity::SpeakEventSound_t const &,CSceneEntity::SpeakEventSound_t const &),CUtlMemory<UtlRBTreeNode_t<CSceneEntity::SpeakEventSound_t,unsigned short>,unsigned short>>(this: &soundnames);
    CUtlSymbolTable::~CUtlSymbolTable(this: &prefetchSoundSymbolTable);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BF20
// Name: public: bool CScenePrecacheSystem::ShouldPrecache(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScenePrecacheSystem::ShouldPrecache(CScenePrecacheSystem *this, const char *pszScene)
{
  int v3; // edi
  unsigned __int16 v4; // ax
  CUtlMap<int,int,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  v3 = HashStringCaselessConventional(pszKey: pszScene);
  search.key = v3;
  v4 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_RepeatCounts.m_Tree,
         &search);
  if ( v4 == 0xFFFF )
  {
    search.key = v3;
    search.elem = 0;
    CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
      this: &this->m_RepeatCounts.m_Tree,
      insert: &search);
    return 1;
  }
  else
  {
    ++this->m_RepeatCounts.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BF90
// Name: void PrecacheInstancedScene(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecacheInstancedScene(const char *pszScene)
{
  int v1; // eax
  int v2; // eax
  int i; // esi
  unsigned __int16 v4; // ax
  const char *v5; // eax
  SceneCachedData_t sceneData; // [esp+4h] [ebp-10h] BYREF

  if ( CScenePrecacheSystem::ShouldPrecache(this: &g_ScenePrecacheSystem, pszScene) != 0 )
  {
    v1 = nMakingReslists;
    if ( nMakingReslists == -1 )
    {
      v2 = _CommandLine();
      v1 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-makereslists") > 0;
      nMakingReslists = v1;
    }
    if ( v1 == 1 )
      g_pFullFileSystem->Size(this: &g_pFullFileSystem->IBaseFileSystem, a2: pszScene, a3: nullptr);
    if ( scenefilecache->GetSceneCachedData(this: scenefilecache, a2: pszScene, a3: &sceneData) )
    {
      for ( i = 0; i < sceneData.numSounds; ++i )
      {
        v4 = scenefilecache->GetSceneCachedSound(this: scenefilecache, a2: sceneData.sceneId, a3: i);
        v5 = scenefilecache->GetSceneString(this: scenefilecache, a2: v4);
        CBaseEntity::PrecacheScriptSound(soundname: v5);
      }
    }
    g_pStringTableClientSideChoreoScenes->AddString(
      this: g_pStringTableClientSideChoreoScenes,
      a2: true,
      a3: pszScene,
      a4: -1,
      a5: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C060
// Name: public: virtual void CInstancedSceneEntity::StartPlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInstancedSceneEntity::StartPlayback(CInstancedSceneEntity *this)
{
  if ( ((double (__thiscall *)(CInstancedSceneEntity *))this->GetPreDelay)(a1: this) == 0.0 )
    CSceneEntity::StartPlayback(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020C090
// Name: public: virtual void CSceneEntity::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneEntity::Precache(CSceneEntity *this)
{
  const char *pszValue; // esi

  if ( !this->m_bGenerated && this->m_iszSceneFile.pszValue != nullptr )
  {
    if ( this->m_iszResumeSceneFile.pszValue != nullptr )
      PrecacheInstancedScene(pszScene: this->m_iszResumeSceneFile.pszValue);
    pszValue = this->m_iszSceneFile.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    PrecacheInstancedScene(pszScene: pszValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10234810
// Name: public: virtual int CSceneManager::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSceneManager::ObjectCaps(CPlayerResource *this)
{
  return CBaseEntity::ObjectCaps(this) | 0x80000000;
}

//------------------------------------------------------------------------------
// Address: 0x10278350
// Name: public: virtual float CInstancedSceneEntity::GetPostSpeakDelay(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInstancedSceneEntity::GetPostSpeakDelay(CInstancedSceneEntity *this)
{
  return this->m_flPostSpeakDelay;
}

//------------------------------------------------------------------------------
// Address: 0x104097A0
// Name: CSceneManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSceneManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSceneManager>(__formal: nullptr);
  CSceneManager_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409810
// Name: DT_SceneEntity::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SceneEntity::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SceneEntity::g_SendTable);
  return atexit(func: DT_SceneEntity::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10409830
// Name: DT_SceneEntity::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SceneEntity::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SceneEntity::ignored>();
  DT_SceneEntity::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409840
// Name: CSceneEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSceneEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSceneEntity>();
  CSceneEntity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104098D0
// Name: CInstancedSceneEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CInstancedSceneEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CInstancedSceneEntity>(__formal: nullptr);
  CInstancedSceneEntity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104099B0
// Name: CSceneListManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSceneListManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSceneListManager>(__formal: nullptr);
  CSceneListManager_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041DBB0
// Name: DT_SceneEntity::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SceneEntity::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SceneEntity::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10206C00
// Name: struct datamap_t __near * DataMapInit<class CInstancedSceneEntity>(class CInstancedSceneEntity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CInstancedSceneEntity>()
{
  if ( (_S7_14 & 1) == 0 )
  {
    _S7_14 |= 1u;
    nameHolder_368.m_pszBase = "CInstancedSceneEntity";
    nameHolder_368.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_368.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_368.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_368.m_Names.m_Size = 0;
    nameHolder_368.m_Names.m_pElements = nullptr;
    nameHolder_368.m_nLenBase = 21;
    atexit(func: DataMapInit_CInstancedSceneEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CInstancedSceneEntity::m_DataMap.baseMap = &CSceneEntity::m_DataMap;
  CInstancedSceneEntity::m_DataMap.dataNumFields = 6;
  CInstancedSceneEntity::m_DataMap.dataDesc = &dataDesc_351[1];
  return &CInstancedSceneEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10207210
// Name: struct datamap_t __near * DataMapInit<class CSceneListManager>(class CSceneListManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSceneListManager>()
{
  if ( (_S8_11 & 1) == 0 )
  {
    _S8_11 |= 1u;
    nameHolder_369.m_pszBase = "CSceneListManager";
    nameHolder_369.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_369.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_369.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_369.m_Names.m_Size = 0;
    nameHolder_369.m_Names.m_pElements = nullptr;
    nameHolder_369.m_nLenBase = 17;
    atexit(func: DataMapInit_CSceneListManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSceneListManager::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S8_11 & 2) == 0 )
  {
    _S8_11 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneListManager>,CUtlMemory<CHandle<CSceneListManager>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneListManager>,CUtlMemory<CHandle<CSceneListManager>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneListManager>,CUtlMemory<CHandle<CSceneListManager>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CSceneListManager>,CUtlMemory<CHandle<CSceneListManager>,int>>,13>::`vftable';
    }
    dataDesc_352[2].flags = 6;
    dataDesc_352[3].fieldSize = 1;
    dataDesc_352[3].flags = 6;
    dataDesc_352[4].fieldSize = 1;
    *(_QWORD *)dataDesc_352[2].flatOffset = 0;
    dataDesc_352[4].flags = 6;
    *(_QWORD *)dataDesc_352[3].flatOffset = 0;
    dataDesc_352[2].fieldSize = 1;
    dataDesc_352[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_352[1].td = 0;
    *(_QWORD *)&dataDesc_352[1].override_field = 0;
    *(_QWORD *)&dataDesc_352[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_352[1].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_352[4].flatOffset = 0;
    dataDesc_352[1].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneListManager>,CUtlMemory<CHandle<CSceneListManager>,int>>>'::`2'::ops;
    dataDesc_352[1].inputFunc = nullptr;
    dataDesc_352[2].fieldType = FIELD_STRING;
    dataDesc_352[2].fieldName = "m_iszScenes[0]";
    dataDesc_352[2].fieldOffset = 872;
    dataDesc_352[2].externalName = "scene0";
    dataDesc_352[2].pSaveRestoreOps = nullptr;
    dataDesc_352[2].inputFunc = nullptr;
    dataDesc_352[2].td = nullptr;
    dataDesc_352[2].fieldSizeInBytes = 4;
    dataDesc_352[2].override_field = nullptr;
    dataDesc_352[2].override_count = 0;
    dataDesc_352[2].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[2].flatGroup = 0;
    dataDesc_352[3].fieldType = FIELD_STRING;
    dataDesc_352[3].fieldName = "m_iszScenes[1]";
    dataDesc_352[3].fieldOffset = 876;
    dataDesc_352[3].externalName = "scene1";
    dataDesc_352[3].pSaveRestoreOps = nullptr;
    dataDesc_352[3].inputFunc = nullptr;
    dataDesc_352[3].td = nullptr;
    dataDesc_352[3].fieldSizeInBytes = 4;
    dataDesc_352[3].override_field = nullptr;
    dataDesc_352[3].override_count = 0;
    dataDesc_352[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[3].flatGroup = 0;
    dataDesc_352[4].fieldType = FIELD_STRING;
    dataDesc_352[4].fieldName = "m_iszScenes[2]";
    dataDesc_352[4].fieldOffset = 880;
    dataDesc_352[4].externalName = "scene2";
    dataDesc_352[4].pSaveRestoreOps = nullptr;
    dataDesc_352[4].inputFunc = nullptr;
    dataDesc_352[4].td = nullptr;
    dataDesc_352[4].fieldSizeInBytes = 4;
    dataDesc_352[4].override_field = nullptr;
    dataDesc_352[4].override_count = 0;
    dataDesc_352[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[4].flatGroup = 0;
    dataDesc_352[5].fieldType = FIELD_STRING;
    dataDesc_352[5].fieldName = "m_iszScenes[3]";
    dataDesc_352[5].fieldOffset = 884;
    dataDesc_352[5].flags = 6;
    dataDesc_352[5].externalName = "scene3";
    dataDesc_352[5].pSaveRestoreOps = nullptr;
    dataDesc_352[5].inputFunc = nullptr;
    dataDesc_352[5].td = nullptr;
    dataDesc_352[5].fieldSizeInBytes = 4;
    dataDesc_352[5].override_field = nullptr;
    dataDesc_352[5].override_count = 0;
    dataDesc_352[5].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_352[5].flatOffset = 0;
    dataDesc_352[6].fieldSize = 1;
    dataDesc_352[6].flags = 6;
    dataDesc_352[7].fieldSize = 1;
    dataDesc_352[7].flags = 6;
    dataDesc_352[8].fieldSize = 1;
    dataDesc_352[8].flags = 6;
    dataDesc_352[9].fieldSize = 1;
    *(_QWORD *)dataDesc_352[6].flatOffset = 0;
    dataDesc_352[9].flags = 6;
    *(_QWORD *)dataDesc_352[7].flatOffset = 0;
    dataDesc_352[10].fieldSize = 1;
    *(_QWORD *)dataDesc_352[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_352[5].flatGroup = 0;
    dataDesc_352[6].fieldType = FIELD_STRING;
    dataDesc_352[6].fieldName = "m_iszScenes[4]";
    dataDesc_352[6].fieldOffset = 888;
    dataDesc_352[6].externalName = "scene4";
    dataDesc_352[6].pSaveRestoreOps = nullptr;
    dataDesc_352[6].inputFunc = nullptr;
    dataDesc_352[6].td = nullptr;
    dataDesc_352[6].fieldSizeInBytes = 4;
    dataDesc_352[6].override_field = nullptr;
    dataDesc_352[6].override_count = 0;
    dataDesc_352[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[6].flatGroup = 0;
    dataDesc_352[7].fieldType = FIELD_STRING;
    dataDesc_352[7].fieldName = "m_iszScenes[5]";
    dataDesc_352[7].fieldOffset = 892;
    dataDesc_352[7].externalName = "scene5";
    dataDesc_352[7].pSaveRestoreOps = nullptr;
    dataDesc_352[7].inputFunc = nullptr;
    dataDesc_352[7].td = nullptr;
    dataDesc_352[7].fieldSizeInBytes = 4;
    dataDesc_352[7].override_field = nullptr;
    dataDesc_352[7].override_count = 0;
    dataDesc_352[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[7].flatGroup = 0;
    dataDesc_352[8].fieldType = FIELD_STRING;
    dataDesc_352[8].fieldName = "m_iszScenes[6]";
    dataDesc_352[8].fieldOffset = 896;
    dataDesc_352[8].externalName = "scene6";
    dataDesc_352[8].pSaveRestoreOps = nullptr;
    dataDesc_352[8].inputFunc = nullptr;
    dataDesc_352[8].td = nullptr;
    dataDesc_352[8].fieldSizeInBytes = 4;
    dataDesc_352[8].override_field = nullptr;
    dataDesc_352[8].override_count = 0;
    dataDesc_352[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[8].flatGroup = 0;
    dataDesc_352[9].fieldType = FIELD_STRING;
    dataDesc_352[9].fieldName = "m_iszScenes[7]";
    dataDesc_352[9].fieldOffset = 900;
    dataDesc_352[9].externalName = "scene7";
    dataDesc_352[9].pSaveRestoreOps = nullptr;
    dataDesc_352[9].inputFunc = nullptr;
    dataDesc_352[9].td = nullptr;
    dataDesc_352[9].fieldSizeInBytes = 4;
    dataDesc_352[9].override_field = nullptr;
    dataDesc_352[9].override_count = 0;
    dataDesc_352[9].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_352[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_352[9].flatGroup = 0;
    dataDesc_352[10].fieldType = FIELD_STRING;
    dataDesc_352[10].fieldName = "m_iszScenes[8]";
    dataDesc_352[10].fieldOffset = 904;
    dataDesc_352[10].flags = 6;
    dataDesc_352[10].externalName = "scene8";
    dataDesc_352[11].fieldSize = 1;
    dataDesc_352[11].flags = 6;
    dataDesc_352[12].fieldSize = 1;
    dataDesc_352[12].flags = 6;
    *(_QWORD *)dataDesc_352[10].flatOffset = 0;
    dataDesc_352[13].fieldSize = 1;
    *(_QWORD *)dataDesc_352[11].flatOffset = 0;
    dataDesc_352[13].flags = 6;
    *(_QWORD *)dataDesc_352[12].flatOffset = 0;
    dataDesc_352[14].fieldSize = 1;
    *(_QWORD *)dataDesc_352[13].flatOffset = 0;
    dataDesc_352[10].pSaveRestoreOps = nullptr;
    dataDesc_352[10].inputFunc = nullptr;
    dataDesc_352[10].td = nullptr;
    dataDesc_352[10].fieldSizeInBytes = 4;
    dataDesc_352[10].override_field = nullptr;
    dataDesc_352[10].override_count = 0;
    dataDesc_352[10].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[10].flatGroup = 0;
    dataDesc_352[11].fieldType = FIELD_STRING;
    dataDesc_352[11].fieldName = "m_iszScenes[9]";
    dataDesc_352[11].fieldOffset = 908;
    dataDesc_352[11].externalName = "scene9";
    dataDesc_352[11].pSaveRestoreOps = nullptr;
    dataDesc_352[11].inputFunc = nullptr;
    dataDesc_352[11].td = nullptr;
    dataDesc_352[11].fieldSizeInBytes = 4;
    dataDesc_352[11].override_field = nullptr;
    dataDesc_352[11].override_count = 0;
    dataDesc_352[11].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[11].flatGroup = 0;
    dataDesc_352[12].fieldType = FIELD_STRING;
    dataDesc_352[12].fieldName = "m_iszScenes[10]";
    dataDesc_352[12].fieldOffset = 912;
    dataDesc_352[12].externalName = "scene10";
    dataDesc_352[12].pSaveRestoreOps = nullptr;
    dataDesc_352[12].inputFunc = nullptr;
    dataDesc_352[12].td = nullptr;
    dataDesc_352[12].fieldSizeInBytes = 4;
    dataDesc_352[12].override_field = nullptr;
    dataDesc_352[12].override_count = 0;
    dataDesc_352[12].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[12].flatGroup = 0;
    dataDesc_352[13].fieldType = FIELD_STRING;
    dataDesc_352[13].fieldName = "m_iszScenes[11]";
    dataDesc_352[13].fieldOffset = 916;
    dataDesc_352[13].externalName = "scene11";
    dataDesc_352[13].pSaveRestoreOps = nullptr;
    dataDesc_352[13].inputFunc = nullptr;
    dataDesc_352[13].td = nullptr;
    dataDesc_352[13].fieldSizeInBytes = 4;
    dataDesc_352[13].override_field = nullptr;
    dataDesc_352[13].override_count = 0;
    dataDesc_352[13].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[13].flatGroup = 0;
    dataDesc_352[14].fieldType = FIELD_STRING;
    dataDesc_352[14].fieldName = "m_iszScenes[12]";
    dataDesc_352[14].fieldOffset = 920;
    dataDesc_352[14].flags = 6;
    dataDesc_352[14].externalName = "scene12";
    dataDesc_352[14].pSaveRestoreOps = nullptr;
    dataDesc_352[14].inputFunc = nullptr;
    dataDesc_352[14].td = nullptr;
    dataDesc_352[14].fieldSizeInBytes = 4;
    dataDesc_352[14].override_field = nullptr;
    dataDesc_352[14].override_count = 0;
    dataDesc_352[14].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_352[14].flatOffset = 0;
    dataDesc_352[15].fieldSize = 1;
    dataDesc_352[15].flags = 6;
    dataDesc_352[16].fieldSize = 1;
    dataDesc_352[16].flags = 6;
    dataDesc_352[18].fieldSize = 1;
    *(_QWORD *)dataDesc_352[15].flatOffset = 0;
    dataDesc_352[17].fieldSize = 1;
    dataDesc_352[18].flags = 2;
    *(_QWORD *)dataDesc_352[16].flatOffset = 0;
    dataDesc_352[17].flags = 6;
    dataDesc_352[19].fieldSize = 1;
    *(_QWORD *)dataDesc_352[17].flatOffset = 0;
    *(_DWORD *)&dataDesc_352[14].flatGroup = 0;
    dataDesc_352[15].fieldType = FIELD_STRING;
    dataDesc_352[15].fieldName = "m_iszScenes[13]";
    dataDesc_352[15].fieldOffset = 924;
    dataDesc_352[15].externalName = "scene13";
    dataDesc_352[15].pSaveRestoreOps = nullptr;
    dataDesc_352[15].inputFunc = nullptr;
    dataDesc_352[15].td = nullptr;
    dataDesc_352[15].fieldSizeInBytes = 4;
    dataDesc_352[15].override_field = nullptr;
    dataDesc_352[15].override_count = 0;
    dataDesc_352[15].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[15].flatGroup = 0;
    dataDesc_352[16].fieldType = FIELD_STRING;
    dataDesc_352[16].fieldName = "m_iszScenes[14]";
    dataDesc_352[16].fieldOffset = 928;
    dataDesc_352[16].externalName = "scene14";
    dataDesc_352[16].pSaveRestoreOps = nullptr;
    dataDesc_352[16].inputFunc = nullptr;
    dataDesc_352[16].td = nullptr;
    dataDesc_352[16].fieldSizeInBytes = 4;
    dataDesc_352[16].override_field = nullptr;
    dataDesc_352[16].override_count = 0;
    dataDesc_352[16].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[16].flatGroup = 0;
    dataDesc_352[17].fieldType = FIELD_STRING;
    dataDesc_352[17].fieldName = "m_iszScenes[15]";
    dataDesc_352[17].fieldOffset = 932;
    dataDesc_352[17].externalName = "scene15";
    dataDesc_352[17].pSaveRestoreOps = nullptr;
    dataDesc_352[17].inputFunc = nullptr;
    dataDesc_352[17].td = nullptr;
    dataDesc_352[17].fieldSizeInBytes = 4;
    dataDesc_352[17].override_field = nullptr;
    dataDesc_352[17].override_count = 0;
    dataDesc_352[17].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[17].flatGroup = 0;
    dataDesc_352[18].fieldType = FIELD_EHANDLE;
    dataDesc_352[18].fieldName = "m_hScenes[0]";
    dataDesc_352[18].fieldOffset = 936;
    dataDesc_352[18].externalName = nullptr;
    dataDesc_352[18].pSaveRestoreOps = nullptr;
    dataDesc_352[18].inputFunc = nullptr;
    dataDesc_352[18].td = nullptr;
    dataDesc_352[18].fieldSizeInBytes = 4;
    dataDesc_352[18].override_field = nullptr;
    dataDesc_352[18].override_count = 0;
    dataDesc_352[18].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_352[18].flatOffset = 0;
    *(_DWORD *)&dataDesc_352[18].flatGroup = 0;
    dataDesc_352[19].fieldType = FIELD_EHANDLE;
    dataDesc_352[19].fieldName = "m_hScenes[1]";
    dataDesc_352[19].fieldOffset = 940;
    dataDesc_352[19].flags = 2;
    dataDesc_352[20].fieldSize = 1;
    dataDesc_352[20].flags = 2;
    dataDesc_352[21].fieldSize = 1;
    dataDesc_352[21].flags = 2;
    dataDesc_352[22].fieldSize = 1;
    *(_QWORD *)dataDesc_352[19].flatOffset = 0;
    *(_QWORD *)dataDesc_352[20].flatOffset = 0;
    dataDesc_352[22].flags = 2;
    *(_QWORD *)dataDesc_352[21].flatOffset = 0;
    dataDesc_352[23].fieldSize = 1;
    *(_QWORD *)dataDesc_352[22].flatOffset = 0;
    dataDesc_352[19].externalName = nullptr;
    dataDesc_352[19].pSaveRestoreOps = nullptr;
    dataDesc_352[19].inputFunc = nullptr;
    dataDesc_352[19].td = nullptr;
    dataDesc_352[19].fieldSizeInBytes = 4;
    dataDesc_352[19].override_field = nullptr;
    dataDesc_352[19].override_count = 0;
    dataDesc_352[19].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[19].flatGroup = 0;
    dataDesc_352[20].fieldType = FIELD_EHANDLE;
    dataDesc_352[20].fieldName = "m_hScenes[2]";
    dataDesc_352[20].fieldOffset = 944;
    dataDesc_352[20].externalName = nullptr;
    dataDesc_352[20].pSaveRestoreOps = nullptr;
    dataDesc_352[20].inputFunc = nullptr;
    dataDesc_352[20].td = nullptr;
    dataDesc_352[20].fieldSizeInBytes = 4;
    dataDesc_352[20].override_field = nullptr;
    dataDesc_352[20].override_count = 0;
    dataDesc_352[20].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[20].flatGroup = 0;
    dataDesc_352[21].fieldType = FIELD_EHANDLE;
    dataDesc_352[21].fieldName = "m_hScenes[3]";
    dataDesc_352[21].fieldOffset = 948;
    dataDesc_352[21].externalName = nullptr;
    dataDesc_352[21].pSaveRestoreOps = nullptr;
    dataDesc_352[21].inputFunc = nullptr;
    dataDesc_352[21].td = nullptr;
    dataDesc_352[21].fieldSizeInBytes = 4;
    dataDesc_352[21].override_field = nullptr;
    dataDesc_352[21].override_count = 0;
    dataDesc_352[21].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[21].flatGroup = 0;
    dataDesc_352[22].fieldType = FIELD_EHANDLE;
    dataDesc_352[22].fieldName = "m_hScenes[4]";
    dataDesc_352[22].fieldOffset = 952;
    dataDesc_352[22].externalName = nullptr;
    dataDesc_352[22].pSaveRestoreOps = nullptr;
    dataDesc_352[22].inputFunc = nullptr;
    dataDesc_352[22].td = nullptr;
    dataDesc_352[22].fieldSizeInBytes = 4;
    dataDesc_352[22].override_field = nullptr;
    dataDesc_352[22].override_count = 0;
    dataDesc_352[22].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[22].flatGroup = 0;
    dataDesc_352[23].fieldType = FIELD_EHANDLE;
    dataDesc_352[23].fieldName = "m_hScenes[5]";
    dataDesc_352[23].fieldOffset = 956;
    dataDesc_352[23].flags = 2;
    dataDesc_352[23].externalName = nullptr;
    dataDesc_352[23].pSaveRestoreOps = nullptr;
    dataDesc_352[23].inputFunc = nullptr;
    dataDesc_352[23].td = nullptr;
    dataDesc_352[23].fieldSizeInBytes = 4;
    dataDesc_352[23].override_field = nullptr;
    dataDesc_352[23].override_count = 0;
    dataDesc_352[23].fieldTolerance = 0.0;
    dataDesc_352[24].fieldSize = 1;
    dataDesc_352[24].flags = 2;
    dataDesc_352[25].fieldSize = 1;
    dataDesc_352[25].flags = 2;
    dataDesc_352[26].fieldSize = 1;
    dataDesc_352[26].flags = 2;
    *(_QWORD *)dataDesc_352[23].flatOffset = 0;
    dataDesc_352[27].fieldSize = 1;
    *(_QWORD *)dataDesc_352[24].flatOffset = 0;
    dataDesc_352[27].flags = 2;
    *(_QWORD *)dataDesc_352[25].flatOffset = 0;
    dataDesc_352[28].fieldSize = 1;
    *(_QWORD *)dataDesc_352[26].flatOffset = 0;
    *(_DWORD *)&dataDesc_352[23].flatGroup = 0;
    dataDesc_352[24].fieldType = FIELD_EHANDLE;
    dataDesc_352[24].fieldName = "m_hScenes[6]";
    dataDesc_352[24].fieldOffset = 960;
    dataDesc_352[24].externalName = nullptr;
    dataDesc_352[24].pSaveRestoreOps = nullptr;
    dataDesc_352[24].inputFunc = nullptr;
    dataDesc_352[24].td = nullptr;
    dataDesc_352[24].fieldSizeInBytes = 4;
    dataDesc_352[24].override_field = nullptr;
    dataDesc_352[24].override_count = 0;
    dataDesc_352[24].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[24].flatGroup = 0;
    dataDesc_352[25].fieldType = FIELD_EHANDLE;
    dataDesc_352[25].fieldName = "m_hScenes[7]";
    dataDesc_352[25].fieldOffset = 964;
    dataDesc_352[25].externalName = nullptr;
    dataDesc_352[25].pSaveRestoreOps = nullptr;
    dataDesc_352[25].inputFunc = nullptr;
    dataDesc_352[25].td = nullptr;
    dataDesc_352[25].fieldSizeInBytes = 4;
    dataDesc_352[25].override_field = nullptr;
    dataDesc_352[25].override_count = 0;
    dataDesc_352[25].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[25].flatGroup = 0;
    dataDesc_352[26].fieldType = FIELD_EHANDLE;
    dataDesc_352[26].fieldName = "m_hScenes[8]";
    dataDesc_352[26].fieldOffset = 968;
    dataDesc_352[26].externalName = nullptr;
    dataDesc_352[26].pSaveRestoreOps = nullptr;
    dataDesc_352[26].inputFunc = nullptr;
    dataDesc_352[26].td = nullptr;
    dataDesc_352[26].fieldSizeInBytes = 4;
    dataDesc_352[26].override_field = nullptr;
    dataDesc_352[26].override_count = 0;
    dataDesc_352[26].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[26].flatGroup = 0;
    dataDesc_352[27].fieldType = FIELD_EHANDLE;
    dataDesc_352[27].fieldName = "m_hScenes[9]";
    dataDesc_352[27].fieldOffset = 972;
    dataDesc_352[27].externalName = nullptr;
    dataDesc_352[27].pSaveRestoreOps = nullptr;
    dataDesc_352[27].inputFunc = nullptr;
    dataDesc_352[27].td = nullptr;
    dataDesc_352[27].fieldSizeInBytes = 4;
    dataDesc_352[27].override_field = nullptr;
    dataDesc_352[27].override_count = 0;
    dataDesc_352[27].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_352[27].flatOffset = 0;
    *(_DWORD *)&dataDesc_352[27].flatGroup = 0;
    dataDesc_352[28].fieldType = FIELD_EHANDLE;
    dataDesc_352[28].fieldName = "m_hScenes[10]";
    dataDesc_352[28].fieldOffset = 976;
    dataDesc_352[28].flags = 2;
    dataDesc_352[29].fieldSize = 1;
    dataDesc_352[29].flags = 2;
    dataDesc_352[30].fieldSize = 1;
    dataDesc_352[30].flags = 2;
    dataDesc_352[31].fieldSize = 1;
    *(_QWORD *)dataDesc_352[28].flatOffset = 0;
    *(_QWORD *)dataDesc_352[29].flatOffset = 0;
    dataDesc_352[31].flags = 2;
    *(_QWORD *)dataDesc_352[30].flatOffset = 0;
    dataDesc_352[32].fieldSize = 1;
    *(_QWORD *)dataDesc_352[31].flatOffset = 0;
    dataDesc_352[28].externalName = nullptr;
    dataDesc_352[28].pSaveRestoreOps = nullptr;
    dataDesc_352[28].inputFunc = nullptr;
    dataDesc_352[28].td = nullptr;
    dataDesc_352[28].fieldSizeInBytes = 4;
    dataDesc_352[28].override_field = nullptr;
    dataDesc_352[28].override_count = 0;
    dataDesc_352[28].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[28].flatGroup = 0;
    dataDesc_352[29].fieldType = FIELD_EHANDLE;
    dataDesc_352[29].fieldName = "m_hScenes[11]";
    dataDesc_352[29].fieldOffset = 980;
    dataDesc_352[29].externalName = nullptr;
    dataDesc_352[29].pSaveRestoreOps = nullptr;
    dataDesc_352[29].inputFunc = nullptr;
    dataDesc_352[29].td = nullptr;
    dataDesc_352[29].fieldSizeInBytes = 4;
    dataDesc_352[29].override_field = nullptr;
    dataDesc_352[29].override_count = 0;
    dataDesc_352[29].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[29].flatGroup = 0;
    dataDesc_352[30].fieldType = FIELD_EHANDLE;
    dataDesc_352[30].fieldName = "m_hScenes[12]";
    dataDesc_352[30].fieldOffset = 984;
    dataDesc_352[30].externalName = nullptr;
    dataDesc_352[30].pSaveRestoreOps = nullptr;
    dataDesc_352[30].inputFunc = nullptr;
    dataDesc_352[30].td = nullptr;
    dataDesc_352[30].fieldSizeInBytes = 4;
    dataDesc_352[30].override_field = nullptr;
    dataDesc_352[30].override_count = 0;
    dataDesc_352[30].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[30].flatGroup = 0;
    dataDesc_352[31].fieldType = FIELD_EHANDLE;
    dataDesc_352[31].fieldName = "m_hScenes[13]";
    dataDesc_352[31].fieldOffset = 988;
    dataDesc_352[31].externalName = nullptr;
    dataDesc_352[31].pSaveRestoreOps = nullptr;
    dataDesc_352[31].inputFunc = nullptr;
    dataDesc_352[31].td = nullptr;
    dataDesc_352[31].fieldSizeInBytes = 4;
    dataDesc_352[31].override_field = nullptr;
    dataDesc_352[31].override_count = 0;
    dataDesc_352[31].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_352[31].flatGroup = 0;
    dataDesc_352[32].fieldType = FIELD_EHANDLE;
    dataDesc_352[32].fieldName = "m_hScenes[14]";
    dataDesc_352[32].fieldOffset = 992;
    dataDesc_352[32].flags = 2;
    dataDesc_352[32].externalName = nullptr;
    dataDesc_352[32].pSaveRestoreOps = nullptr;
    dataDesc_352[32].inputFunc = nullptr;
    dataDesc_352[32].td = nullptr;
    dataDesc_352[32].fieldSizeInBytes = 4;
    dataDesc_352[32].override_field = nullptr;
    dataDesc_352[32].override_count = 0;
    dataDesc_352[32].fieldTolerance = 0.0;
    dataDesc_352[33].fieldTolerance = 0.0;
    dataDesc_352[33].fieldType = FIELD_EHANDLE;
    *(_QWORD *)dataDesc_352[33].flatOffset = 0;
    *(_QWORD *)dataDesc_352[32].flatOffset = 0;
    *(_DWORD *)&dataDesc_352[32].flatGroup = 0;
    dataDesc_352[33].fieldName = "m_hScenes[15]";
    dataDesc_352[33].fieldOffset = 996;
    dataDesc_352[33].fieldSize = 1;
    dataDesc_352[33].flags = 2;
    dataDesc_352[33].externalName = nullptr;
    dataDesc_352[33].pSaveRestoreOps = nullptr;
    dataDesc_352[33].inputFunc = nullptr;
    dataDesc_352[33].td = nullptr;
    dataDesc_352[33].fieldSizeInBytes = 4;
    dataDesc_352[33].override_field = nullptr;
    dataDesc_352[33].override_count = 0;
    *(_DWORD *)&dataDesc_352[33].flatGroup = 0;
    dataDesc_352[34].fieldType = FIELD_VOID;
    dataDesc_352[34].fieldName = "InputShutdown";
    dataDesc_352[34].fieldOffset = 0;
    *(_DWORD *)&dataDesc_352[34].fieldSize = 524289;
    dataDesc_352[34].externalName = "Shutdown";
    dataDesc_352[34].pSaveRestoreOps = nullptr;
    dataDesc_352[34].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneListManager::InputShutdown;
    *(_QWORD *)&dataDesc_352[34].td = 0;
    *(_QWORD *)&dataDesc_352[34].override_field = 0;
    *(_QWORD *)&dataDesc_352[34].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_352[34].flatOffset[1] = 0;
  }
  CSceneListManager::m_DataMap.dataNumFields = 34;
  CSceneListManager::m_DataMap.dataDesc = &dataDesc_352[1];
  return &CSceneListManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10208490
// Name: struct datamap_t __near * DataMapInit<class CSceneManager>(class CSceneManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSceneManager>()
{
  int v0; // eax

  if ( (_S2_195 & 1) == 0 )
  {
    _S2_195 |= 1u;
    nameHolder_370.m_pszBase = "CSceneManager";
    nameHolder_370.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_370.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_370.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_370.m_Names.m_Size = 0;
    nameHolder_370.m_Names.m_pElements = nullptr;
    nameHolder_370.m_nLenBase = 13;
    atexit(func: DataMapInit_CSceneManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSceneManager::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_195 & 2) == 0 )
  {
    v0 = `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::`local static guard';
    _S2_195 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      v0 = `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::`local static guard'
         | 1;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>,13>::`vftable';
    }
    dataDesc_353[2].fieldSize = 1;
    dataDesc_353[2].flags = 2;
    dataDesc_353[1].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::ops;
    dataDesc_353[1].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_353[1].td = 0;
    *(_QWORD *)&dataDesc_353[1].override_field = 0;
    *(_QWORD *)&dataDesc_353[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_353[1].flatOffset[1] = 0;
    dataDesc_353[2].fieldType = FIELD_CUSTOM;
    dataDesc_353[2].fieldName = "m_Scenes";
    dataDesc_353[2].fieldOffset = 872;
    dataDesc_353[2].externalName = nullptr;
    if ( (v0 & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::`local static guard' = v0 | 1;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>,13>::`vftable';
    }
    dataDesc_353[2].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::ops;
    dataDesc_353[2].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_353[2].td = 0;
    *(_QWORD *)&dataDesc_353[2].override_field = 0;
    *(_QWORD *)&dataDesc_353[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_353[2].flatOffset[1] = 0;
  }
  CSceneManager::m_DataMap.dataNumFields = 2;
  CSceneManager::m_DataMap.dataDesc = &dataDesc_353[1];
  return &CSceneManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10409850
// Name: _dynamic_initializer_for__g_CSceneEntity_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CSceneEntity_ScriptDesc__()
{
  InitCSceneEntityScriptDesc();
  g_CSceneEntity_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_CSceneEntity_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_CSceneEntity_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x104099C0
// Name: _dynamic_initializer_for__ListRecentNPCSpeechCmd__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ListRecentNPCSpeechCmd__()
{
  ConCommand::ConCommand(
    this: &ListRecentNPCSpeechCmd,
    pName: "listRecentNPCSpeech",
    callback: ListRecentNPCSpeech,
    pHelpString: "Displays a list of the last 5 lines of speech from NPCs.",
    flags: 131076,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ListRecentNPCSpeechCmd__);
}
