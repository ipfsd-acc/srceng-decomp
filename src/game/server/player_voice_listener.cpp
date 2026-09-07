// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/player_voice_listener.cpp
// Functions: 8
// ============================================================

#include "game\server\player_voice_listener.h"

//------------------------------------------------------------------------------
// Address: 0x101CFAB0
// Name: public: float CPlayerVoiceListener::ScriptGetPlayerSpeechDuration(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPlayerVoiceListener::ScriptGetPlayerSpeechDuration(CPlayerVoiceListener *this, int nPlayerIndex)
{
  if ( (unsigned int)(nPlayerIndex - 1) <= 0x3F )
    return this->m_flPlayerSpeechDuration[nPlayerIndex];
  else
    return -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x101CFAF0
// Name: public: virtual void CPlayerVoiceListener::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerVoiceListener::LevelShutdownPreEntity(CPlayerVoiceListener *this)
{
  memset(dst: (int)this->m_flLastPlayerSpeechTime, value: nullptr, count: 0x40u);
  memset(dst: (int)this->m_flPlayerSpeechDuration, value: nullptr, count: 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x101CFB20
// Name: class CPlayerVoiceListener __near & PlayerVoiceListener(void)
// Source: json
//------------------------------------------------------------------------------
CPlayerVoiceListener *__cdecl PlayerVoiceListener()
{
  return &g_PlayerVoiceListener;
}

//------------------------------------------------------------------------------
// Address: 0x101CFB30
// Name: public: bool CPlayerVoiceListener::ScriptIsPlayerSpeaking(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPlayerVoiceListener::ScriptIsPlayerSpeaking(CPlayerVoiceListener *this, int nPlayerIndex)
{
  return (unsigned int)(nPlayerIndex - 1) <= 0x3F
      && (float)(this->m_flLastPlayerSpeechTime[nPlayerIndex]
               + voice_player_speaking_delay_threshold.m_pParent->m_Value.m_fValue) >= gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x101CFB70
// Name: public: void CPlayerVoiceListener::AddPlayerSpeakTime(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerVoiceListener::AddPlayerSpeakTime(CPlayerVoiceListener *this, CBasePlayer *pPlayer)
{
  edict_t *m_pPev; // eax
  CGlobalVars *v3; // edx
  signed int v4; // eax
  float v5; // xmm1_4
  float curtime; // xmm0_4
  float v7; // xmm0_4

  if ( pPlayer != nullptr )
  {
    m_pPev = pPlayer->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      v3 = gpGlobals;
      v4 = m_pPev - gpGlobals->pEdicts;
      if ( (unsigned int)(v4 - 1) <= 0x3F )
      {
        v5 = this->m_flLastPlayerSpeechTime[v4];
        curtime = gpGlobals->curtime;
        if ( (float)(voice_player_speaking_delay_threshold.m_pParent->m_Value.m_fValue + v5) < curtime )
          v7 = 0.0;
        else
          v7 = (float)(curtime - v5) + this->m_flPlayerSpeechDuration[v4];
        this->m_flPlayerSpeechDuration[v4] = v7;
        this->m_flLastPlayerSpeechTime[v4] = v3->curtime;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CFBE0
// Name: public: static bool CMemberScriptBinding1<class CPlayerVoiceListener __near *,bool (CPlayerVoiceListener::*)(int),bool,int>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding1<CPlayerVoiceListener *,bool (__thiscall CPlayerVoiceListener::*)(int),bool,int>::Call(
        int (__stdcall *pFunction)(int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 1 || pReturn == nullptr || pContext == nullptr )
    return 0;
  pReturn->m_char = pFunction(a1: pArguments->m_int);
  pReturn->m_type = 6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CFC20
// Name: public: static bool CMemberScriptBinding1<class CPlayerVoiceListener __near *,float (CPlayerVoiceListener::*)(int),float,int>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding1<CPlayerVoiceListener *,float (__thiscall CPlayerVoiceListener::*)(int),float,int>::Call(
        double (__stdcall *pFunction)(int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 1 || pReturn == nullptr || pContext == nullptr )
    return 0;
  pReturn->m_float = pFunction(a1: pArguments->m_int);
  pReturn->m_type = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CFC60
// Name: void InitCPlayerVoiceListenerScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCPlayerVoiceListenerScriptDesc()
{
  ScriptFunctionBinding_t *v0; // edi
  int *m_pMemory; // eax
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v6; // ecx
  int v7; // eax
  int *v8; // ebx
  ScriptFunctionBinding_t *v9; // edi
  int *v10; // eax
  int *v11; // eax
  int v12; // ebx
  int v13; // eax
  int *v14; // ecx
  int v15; // eax
  int *v16; // ebx

  if ( !bInitialized_4 )
  {
    g_CPlayerVoiceListener_ScriptDesc.m_pszScriptName = "CPlayerVoiceListener";
    g_CPlayerVoiceListener_ScriptDesc.m_pszClassname = "CPlayerVoiceListener";
    bInitialized_4 = true;
    g_CPlayerVoiceListener_ScriptDesc.m_pszDescription = "!Player voice listeners";
    g_CPlayerVoiceListener_ScriptDesc.m_pBaseDesc = nullptr;
    g_CPlayerVoiceListener_ScriptDesc.pHelper = nullptr;
    v0 = &g_CPlayerVoiceListener_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                    this: &g_CPlayerVoiceListener_ScriptDesc.m_FunctionBindings,
                                                                                    elem: g_CPlayerVoiceListener_ScriptDesc.m_FunctionBindings.m_Size)];
    v0->m_desc.m_pszDescription = "Returns whether the player specified is speaking.";
    v0->m_desc.m_pszScriptName = "IsPlayerSpeaking";
    v0->m_desc.m_pszFunction = "ScriptIsPlayerSpeaking";
    v0->m_desc.m_ReturnType = 6;
    v0->m_desc.m_Parameters.m_Memory.m_nGrowSize = 1;
    if ( v0->m_desc.m_Parameters.m_Memory.m_nAllocationCount < 1 )
    {
      v0->m_desc.m_Parameters.m_Memory.m_nAllocationCount = 1;
      m_pMemory = v0->m_desc.m_Parameters.m_Memory.m_pMemory;
      v2 = _g_pMemAlloc->__vftable;
      if ( m_pMemory != nullptr )
        v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: m_pMemory, a2: 4);
      else
        v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 4);
      v0->m_desc.m_Parameters.m_Memory.m_pMemory = (int *)v3;
    }
    v0->m_desc.m_Parameters.m_pElements = v0->m_desc.m_Parameters.m_Memory.m_pMemory;
    m_Size = v0->m_desc.m_Parameters.m_Size;
    m_nAllocationCount = v0->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v0->m_desc.m_Parameters,
        num: m_Size - m_nAllocationCount + 1);
    ++v0->m_desc.m_Parameters.m_Size;
    v6 = v0->m_desc.m_Parameters.m_Memory.m_pMemory;
    v7 = v0->m_desc.m_Parameters.m_Size - m_Size - 1;
    v0->m_desc.m_Parameters.m_pElements = v6;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_Size + 1], src: &v6[m_Size], count: 4 * v7);
    v8 = &v0->m_desc.m_Parameters.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = 5;
    v0->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding1<CPlayerVoiceListener *,bool (__thiscall CPlayerVoiceListener::*)(int),bool,int>::Call;
    v0->m_pFunction = CPlayerVoiceListener::ScriptIsPlayerSpeaking;
    v0->m_flags = 1;
    v9 = &g_CPlayerVoiceListener_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                                    this: &g_CPlayerVoiceListener_ScriptDesc.m_FunctionBindings,
                                                                                    elem: g_CPlayerVoiceListener_ScriptDesc.m_FunctionBindings.m_Size)];
    v9->m_desc.m_pszDescription = "Returns the number of seconds the player has been continuously speaking.";
    v9->m_desc.m_pszScriptName = "GetPlayerSpeechDuration";
    v9->m_desc.m_pszFunction = "ScriptGetPlayerSpeechDuration";
    v9->m_desc.m_ReturnType = 1;
    v9->m_desc.m_Parameters.m_Memory.m_nGrowSize = 1;
    if ( v9->m_desc.m_Parameters.m_Memory.m_nAllocationCount < 1 )
    {
      v10 = v9->m_desc.m_Parameters.m_Memory.m_pMemory;
      v9->m_desc.m_Parameters.m_Memory.m_nAllocationCount = 1;
      if ( v10 != nullptr )
        v11 = (int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v10, a3: 4);
      else
        v11 = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4);
      v9->m_desc.m_Parameters.m_Memory.m_pMemory = v11;
    }
    v9->m_desc.m_Parameters.m_pElements = v9->m_desc.m_Parameters.m_Memory.m_pMemory;
    v12 = v9->m_desc.m_Parameters.m_Size;
    v13 = v9->m_desc.m_Parameters.m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v9->m_desc.m_Parameters,
        num: v12 - v13 + 1);
    ++v9->m_desc.m_Parameters.m_Size;
    v14 = v9->m_desc.m_Parameters.m_Memory.m_pMemory;
    v15 = v9->m_desc.m_Parameters.m_Size - v12 - 1;
    v9->m_desc.m_Parameters.m_pElements = v14;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
    v16 = &v9->m_desc.m_Parameters.m_Memory.m_pMemory[v12];
    if ( v16 != nullptr )
      *v16 = 5;
    v9->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding1<CPlayerVoiceListener *,float (__thiscall CPlayerVoiceListener::*)(int),float,int>::Call;
    v9->m_pFunction = CPlayerVoiceListener::ScriptGetPlayerSpeechDuration;
    v9->m_flags = 1;
  }
}
