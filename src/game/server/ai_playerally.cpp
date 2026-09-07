// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_playerally.cpp
// Functions: 47
// ============================================================

#include "game\server\ai_playerally.h"

//------------------------------------------------------------------------------
// Address: 0x10079C90
// Name: private: virtual struct datamap_t __near * CAI_AllySpeechManager::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_AllySpeechManager::GetDataDescMap(CAI_AllySpeechManager *this)
{
  return &CAI_AllySpeechManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10079CA0
// Name: public: void CAI_PlayerAlly::InputMakeGameEndAlly(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlayerAlly::InputMakeGameEndAlly(CAI_PlayerAlly *this, inputdata_t *inputdata)
{
  this->m_bGameEndAlly = true;
}

//------------------------------------------------------------------------------
// Address: 0x10079CB0
// Name: public: void CAI_PlayerAlly::InputMakeRegularAlly(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlayerAlly::InputMakeRegularAlly(CAI_PlayerAlly *this, inputdata_t *inputdata)
{
  this->m_bGameEndAlly = false;
}

//------------------------------------------------------------------------------
// Address: 0x10079CC0
// Name: public: void CAI_PlayerAlly::InputSpeakResponseConcept(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlayerAlly::InputSpeakResponseConcept(CAI_PlayerAlly *this, inputdata_t *inputdata)
{
  variant_t *p_value; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    inputdata = nullptr;
    p_value = (variant_t *)&inputdata;
  }
  ((void (__thiscall *)(CAI_PlayerAlly *, int))this->SpeakMapmakerInterruptConcept)(a1: this, a2: p_value->iVal);
}

//------------------------------------------------------------------------------
// Address: 0x10079CF0
// Name: public: void CAI_PlayerAlly::InputEnableSpeakWhileScripting(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlayerAlly::InputEnableSpeakWhileScripting(CAI_PlayerAlly *this, inputdata_t *inputdata)
{
  this->m_bCanSpeakWhileScripting = true;
}

//------------------------------------------------------------------------------
// Address: 0x10079D00
// Name: public: void CAI_PlayerAlly::InputDisableSpeakWhileScripting(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlayerAlly::InputDisableSpeakWhileScripting(CAI_PlayerAlly *this, inputdata_t *inputdata)
{
  this->m_bCanSpeakWhileScripting = false;
}

//------------------------------------------------------------------------------
// Address: 0x10079F50
// Name: private: bool CAI_PlayerAlly::CategoryDelayExpired(enum ConceptCategory_t)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_PlayerAlly::CategoryDelayExpired(CAI_PlayerAlly *this, ConceptCategory_t category)
{
  return (float)(gpGlobals->curtime - this->m_ConceptCategoryTimers[category].m_next) > -0.001;
}

//------------------------------------------------------------------------------
// Address: 0x10079F90
// Name: bool ConceptStringLessFunc(struct string_t const __near &,struct string_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ConceptStringLessFunc(const string_t *lhs, const string_t *rhs)
{
  const char *pszValue; // eax
  const char *v3; // ecx

  pszValue = rhs->pszValue;
  if ( rhs->pszValue == nullptr )
    pszValue = locale;
  v3 = lhs->pszValue;
  if ( lhs->pszValue == nullptr )
    v3 = locale;
  return pszValue == nullptr || _V_stricmp(s1: v3, s2: pszValue) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10079FD0
// Name: bool ConceptIDLessFunc(class CUtlSymbol const __near &,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ConceptIDLessFunc(const CUtlSymbol *lhs, const CUtlSymbol *rhs)
{
  const char *StringForGenericId; // esi
  const char *v3; // eax

  StringForGenericId = ResponseRules::CRR_Concept::GetStringForGenericId(genericId: (CUtlSymbol)rhs->m_Id);
  v3 = ResponseRules::CRR_Concept::GetStringForGenericId(genericId: (CUtlSymbol)lhs->m_Id);
  if ( v3 == nullptr )
    return false;
  if ( StringForGenericId != nullptr )
    return _V_stricmp(s1: v3, s2: StringForGenericId) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1007A020
// Name: public: bool CAI_AllySpeechManager::CategoryDelayExpired(enum ConceptCategory_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_AllySpeechManager::CategoryDelayExpired(CAI_AllySpeechManager *this, ConceptCategory_t category)
{
  return category == SPEECH_PRIORITY
      || (float)(gpGlobals->curtime - this->m_ConceptCategoryTimers[category].m_next) > -0.001;
}

//------------------------------------------------------------------------------
// Address: 0x1007A070
// Name: public: void CAI_PlayerAlly::DeferAllIdleSpeech(float,class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlayerAlly::DeferAllIdleSpeech(CAI_PlayerAlly *this, float flDelay, CAI_BaseNPC *pIgnore)
{
  CAI_AllySpeechManager *v3; // ecx
  float *p_m_next; // esi

  v3 = CAI_AllySpeechManager::gm_pSpeechManager;
  if ( CAI_AllySpeechManager::gm_pSpeechManager == nullptr )
  {
    CreateEntityByName(className: "ai_ally_speech_manager", iForceEdictIndex: -1, bNotify: true);
    v3 = CAI_AllySpeechManager::gm_pSpeechManager;
    if ( CAI_AllySpeechManager::gm_pSpeechManager != nullptr )
    {
      DispatchSpawn(pEntity: CAI_AllySpeechManager::gm_pSpeechManager, bRunVScripts: true);
      v3 = CAI_AllySpeechManager::gm_pSpeechManager;
    }
  }
  if ( flDelay == -1.0 )
  {
    p_m_next = &v3->m_ConceptCategoryTimers[0].m_next;
    if ( *(float *)&dword_1056B264 <= 0.0 )
      *p_m_next = gpGlobals->curtime + g_ConceptCategoryInfos[0].minGlobalDelay;
    else
      *p_m_next = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                    a1: random,
                    a2: LODWORD(g_ConceptCategoryInfos[0].minGlobalDelay),
                    a3: dword_1056B264)
                + gpGlobals->curtime;
  }
  else
  {
    v3->m_ConceptCategoryTimers[0].m_next = gpGlobals->curtime + flDelay;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A140
// Name: public: char __near * std::allocator<char>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall std::allocator<char>::allocate(std::allocator<char> *this, unsigned int _Count)
{
  char *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 )
  {
    result = (char *)operator new(nSize: _Count);
    if ( result == nullptr )
    {
      _Count = 0;
      std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
      pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007A190
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct string_t,class CSimpleSimTimer,char>::Node_t,char>,char>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char> *m_pMemory; // edx
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
        m_nAllocationCount = 3;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (char)m_nAllocationCount < v5 )
    {
      if ( (_BYTE)m_nAllocationCount != 0 || v5 > -1 )
      {
        if ( (char)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (char)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char> *)_g_pMemAlloc->Realloc_2(
                                                                                                  this: _g_pMemAlloc,
                                                                                                  a2: m_pMemory,
                                                                                                  a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char> *)_g_pMemAlloc->Alloc_2(
                                                                                                  this: _g_pMemAlloc,
                                                                                                  a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A290
// Name: public: virtual bool CStdStringSaveRestoreOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CStdStringSaveRestoreOps::IsEmpty(
        CStdStringSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  return *((_DWORD *)fieldInfo->pField + 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007A2B0
// Name: public: virtual void CStdStringSaveRestoreOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdStringSaveRestoreOps::Save(
        CStdStringSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  const char *pField; // eax

  pField = (const char *)fieldInfo->pField;
  if ( *((_DWORD *)fieldInfo->pField + 4) >= 0xFFFu )
  {
    pSave->WriteString_4(this: pSave, a2: "<<invalid>>");
  }
  else
  {
    if ( *((_DWORD *)pField + 5) >= 0x10u )
      pField = *(const char **)pField;
    pSave->WriteString_4(this: pSave, a2: pField);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A2F0
// Name: public: class CAI_SpeechFilter __near * CAI_PlayerAlly::GetSpeechFilter(void)
// Source: json
//------------------------------------------------------------------------------
CAI_SpeechFilter *__thiscall CAI_PlayerAlly::GetSpeechFilter(CAI_PlayerAlly *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hSpeechFilter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CAI_SpeechFilter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1007A320
// Name: public: bool CAI_PlayerAlly::IsOkToSpeak(enum ConceptCategory_t,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_PlayerAlly::IsOkToSpeak(CAI_PlayerAlly *this, ConceptCategory_t category, bool fRespondingToPlayer)
{
  CAI_AllySpeechManager *v3; // eax
  bool result; // al
  NPC_STATE m_NPCState; // ebx
  CAI_Expresser *v7; // eax
  CAI_Expresser *v8; // ecx
  CBasePlayer *LocalPlayer; // ebx
  const Vector *v10; // edi
  float *v11; // eax
  char v12; // al
  const char *DebugName; // eax
  CAI_AllySpeechManager *pSpeechManager; // [esp+4h] [ebp-4h]
  float flDist; // [esp+10h] [ebp+8h]

  v3 = CAI_AllySpeechManager::gm_pSpeechManager;
  if ( CAI_AllySpeechManager::gm_pSpeechManager == nullptr )
  {
    CreateEntityByName(className: "ai_ally_speech_manager", iForceEdictIndex: -1, bNotify: true);
    v3 = CAI_AllySpeechManager::gm_pSpeechManager;
    if ( CAI_AllySpeechManager::gm_pSpeechManager != nullptr )
    {
      DispatchSpawn(pEntity: CAI_AllySpeechManager::gm_pSpeechManager, bRunVScripts: true);
      v3 = CAI_AllySpeechManager::gm_pSpeechManager;
    }
  }
  pSpeechManager = v3;
  if ( !this->IsAlive(this) || (this->m_spawnflags.m_Value & 2) != 0 )
    return false;
  m_NPCState = this->m_NPCState;
  if ( m_NPCState == NPC_STATE_SCRIPT && !this->m_bCanSpeakWhileScripting
    || (this->m_iEFlags & 0x100000) != 0
    || this->m_bInAScript && !this->m_bCanSpeakWhileScripting )
  {
    return false;
  }
  if ( !fRespondingToPlayer
    && (!CAI_AllySpeechManager::CategoryDelayExpired(this: pSpeechManager, category)
     || !CAI_PlayerAlly::CategoryDelayExpired(this, category))
    || category == SPEECH_IDLE
    && (m_NPCState != NPC_STATE_IDLE && m_NPCState != NPC_STATE_ALERT
     || CAI_PlayerAlly::GetSpeechFilter(this) != nullptr
     && CAI_PlayerAlly::GetSpeechFilter(this)->m_flIdleModifier < 0.001)
    || UTIL_FindClientInPVS(pEdict: this->m_Network.m_pPev) == nullptr )
  {
    return false;
  }
  if ( category == SPEECH_PRIORITY )
  {
LABEL_31:
    if ( fRespondingToPlayer )
      v12 = IsRunningScriptedSceneWithSpeechAndNotPaused(pActor: this, bIgnoreInstancedScenes: false);
    else
      v12 = IsRunningScriptedSceneAndNotPaused(pActor: this, bIgnoreInstancedScenes: true);
    if ( v12 == 0 )
      return true;
    if ( rr_debugresponses.m_pParent != nullptr && rr_debugresponses.m_pParent->m_Value.m_nValue > 0 )
    {
      DebugName = CBaseEntity::GetDebugName(this);
      DevMsg(a1: "%s not allowed to speak because they are in a scripted scene\n", DebugName);
    }
    return false;
  }
  v7 = this->GetExpresser(this);
  if ( !CAI_Expresser::SemaphoreIsAvailable(this: v7, pTalker: this) )
    return false;
  v8 = this->GetExpresser(this);
  if ( !fRespondingToPlayer )
  {
    if ( !CAI_Expresser::CanSpeak(this: v8) )
      return false;
    goto LABEL_28;
  }
  result = CAI_Expresser::CanSpeakAfterMyself(this: v8);
  if ( result )
  {
LABEL_28:
    if ( gpGlobals->maxClients <= 1 )
    {
      LocalPlayer = UTIL_GetLocalPlayer();
      if ( LocalPlayer != nullptr )
      {
        flDist = sv_npc_talker_maxdist.m_pParent->m_Value.m_fValue;
        v10 = this->WorldSpaceCenter(this);
        v11 = (float *)LocalPlayer->WorldSpaceCenter(this: LocalPlayer);
        if ( (float)((float)((float)((float)(*v11 - v10->x) * (float)(*v11 - v10->x))
                           + (float)((float)(v11[1] - v10->y) * (float)(v11[1] - v10->y)))
                   + (float)((float)(v11[2] - v10->z) * (float)(v11[2] - v10->z))) > (float)(flDist * flDist) )
          return false;
      }
    }
    goto LABEL_31;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007A580
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::erase(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::erase(std::string *this, unsigned int _Off, unsigned int _Count)
{
  unsigned int Mysize; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  unsigned int Myres; // edx
  std::string *Ptr; // ebx
  std::string *v9; // edx
  unsigned int v10; // eax
  bool v11; // cf

  Mysize = this->_Mysize;
  if ( Mysize < _Off )
    std::_Xout_of_range(_Message: "invalid string position");
  v5 = _Count;
  v6 = Mysize - _Off;
  if ( v6 < _Count )
    v5 = v6;
  if ( v5 != 0 )
  {
    Myres = this->_Myres;
    if ( Myres < 0x10 )
      Ptr = this;
    else
      Ptr = (std::string *)this->_Bx._Ptr;
    if ( Myres < 0x10 )
      v9 = this;
    else
      v9 = (std::string *)this->_Bx._Ptr;
    memmove(
      dst: (unsigned __int8 *)&v9->_Bx._Buf[_Off],
      src: (unsigned __int8 *)&Ptr->_Bx._Buf[_Off + v5],
      count: v6 - v5);
    v10 = this->_Mysize - v5;
    v11 = this->_Myres < 0x10;
    this->_Mysize = v10;
    if ( !v11 )
    {
      this->_Bx._Ptr[v10] = 0;
      return this;
    }
    this->_Bx._Buf[v10] = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007A610
// Name: public: void std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::_Copy(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::string::_Copy(std::string *this, unsigned int _Newsize, unsigned int _Oldlen)
{
  std::string *v3; // esi
  unsigned int v4; // edi
  unsigned int Myres; // ebx
  unsigned int v6; // ecx
  char *v7; // ebx
  unsigned int v8; // ecx
  unsigned __int8 *Ptr; // eax
  int v10; // [esp+0h] [ebp-24h] BYREF
  char *_Ptr; // [esp+Ch] [ebp-18h]
  std::string *v12; // [esp+10h] [ebp-14h]
  int *v13; // [esp+14h] [ebp-10h]
  int v14; // [esp+20h] [ebp-4h]

  v13 = &v10;
  v3 = this;
  v12 = this;
  v4 = _Newsize | 0xF;
  if ( (_Newsize | 0xF) == 0xFFFFFFFF )
  {
    v4 = _Newsize;
  }
  else
  {
    Myres = this->_Myres;
    v6 = Myres >> 1;
    if ( Myres >> 1 > v4 / 3 )
    {
      v4 = v6 + Myres;
      if ( Myres > -2 - v6 )
        v4 = -2;
    }
  }
  v14 = 0;
  v7 = std::allocator<char>::allocate(this: &v3->_Alval, _Count: v4 + 1);
  _Ptr = v7;
  v14 = -1;
  v8 = _Oldlen;
  if ( _Oldlen != 0 )
  {
    if ( v3->_Myres < 0x10 )
      Ptr = (unsigned __int8 *)v3;
    else
      Ptr = (unsigned __int8 *)v3->_Bx._Ptr;
    memcpy(dst: (unsigned __int8 *)v7, src: Ptr, count: _Oldlen);
    v8 = _Oldlen;
  }
  if ( v3->_Myres >= 0x10 )
  {
    free(pMem: v3->_Bx._Ptr);
    v8 = _Oldlen;
  }
  v3->_Bx._Buf[0] = 0;
  v3->_Bx._Ptr = v7;
  v3->_Myres = v4;
  v3->_Mysize = v8;
  if ( v4 >= 0x10 )
    v3 = (std::string *)v7;
  v3->_Bx._Buf[v8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007A800
// Name: public: virtual bool CUtlMapDataOps<class CUtlMap<struct string_t,class CSimpleSimTimer,char>,2,10>::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUtlMapDataOps<CUtlMap<string_t,CSimpleSimTimer,char>,2,10>::IsEmpty(
        CAI_EnemiesListSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  return *((_BYTE *)fieldInfo->pField + 17) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007B3A0
// Name: public: virtual void CStdStringSaveRestoreOps::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdStringSaveRestoreOps::MakeEmpty(
        CStdStringSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  std::string::erase(this: (std::string *)fieldInfo->pField, _Off: 0, _Count: 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x1007C200
// Name: public: void CBaseEntity::SetRenderAlpha(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetRenderAlpha(CBaseEntity *this, unsigned __int8 a)
{
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *p_m_clrRender; // esi
  edict_t *m_pPev; // ecx

  p_m_clrRender = &this->m_clrRender;
  if ( this->m_clrRender.m_Value.a != a )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_clrRender.m_Value.a = a;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
      p_m_clrRender->m_Value.a = a;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C250
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::assign(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::assign(
        std::string *this,
        const std::string *_Right,
        unsigned int _Roff,
        unsigned int _Count)
{
  const std::string *Ptr; // ecx
  unsigned int Mysize; // edi
  unsigned int v7; // edi
  unsigned int Myres; // eax
  std::string *v10; // eax
  bool v11; // cf

  Ptr = _Right;
  Mysize = _Right->_Mysize;
  if ( Mysize < _Roff )
    std::_Xout_of_range(_Message: "invalid string position");
  v7 = Mysize - _Roff;
  if ( _Count < v7 )
    v7 = _Count;
  if ( this == _Right )
  {
    std::string::erase(this, _Off: _Roff + v7, _Count: 0xFFFFFFFF);
    std::string::erase(this, _Off: 0, _Count: _Roff);
    return this;
  }
  if ( v7 == -1 )
    std::_Xlength_error(_Message: "string too long");
  Myres = this->_Myres;
  if ( Myres < v7 )
  {
    std::string::_Copy(this, _Newsize: v7, _Oldlen: this->_Mysize);
    Ptr = _Right;
    if ( v7 == 0 )
      return this;
LABEL_11:
    if ( Ptr->_Myres >= 0x10 )
      Ptr = (const std::string *)Ptr->_Bx._Ptr;
    if ( this->_Myres < 0x10 )
      v10 = this;
    else
      v10 = (std::string *)this->_Bx._Ptr;
    memcpy(dst: (unsigned __int8 *)v10, src: (unsigned __int8 *)&Ptr->_Bx._Buf[_Roff], count: v7);
    v11 = this->_Myres < 0x10;
    this->_Mysize = v7;
    if ( !v11 )
    {
      this->_Bx._Ptr[v7] = 0;
      return this;
    }
    this->_Bx._Buf[v7] = 0;
    return this;
  }
  if ( v7 != 0 )
    goto LABEL_11;
  this->_Mysize = 0;
  if ( Myres < 0x10 )
    this->_Bx._Buf[0] = 0;
  else
    *this->_Bx._Ptr = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007C3A0
// Name: public: virtual void CUtlMapDataOps<class CUtlMap<struct string_t,class CSimpleSimTimer,char>,2,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMapDataOps<CUtlMap<string_t,CSimpleSimTimer,char>,2,10>::Save(
        CUtlMapDataOps<CUtlMap<string_t,CSimpleSimTimer,char>,2,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        int pSave)
{
  ISave *v3; // esi
  CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char> > *pField; // edi
  void (__thiscall *v5)(ISave *); // edx
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  char Inorder; // al
  typedescription_t dataDesc[2]; // [esp+8h] [ebp-90h] BYREF
  datamap_t dataMap; // [esp+80h] [ebp-18h] BYREF
  char i; // [esp+A0h] [ebp+8h]

  dataDesc[0].fieldSize = 1;
  dataDesc[0].flags = 2;
  dataDesc[1].fieldSize = 1;
  dataDesc[0].fieldType = FIELD_STRING;
  dataDesc[0].fieldSizeInBytes = 4;
  dataDesc[1].fieldOffset = 4;
  dataDesc[1].flags = 2;
  v3 = (ISave *)pSave;
  dataDesc[1].fieldSizeInBytes = 4;
  dataMap.dataNumFields = 2;
  dataDesc[0].fieldOffset = 0;
  dataDesc[0].externalName = nullptr;
  dataDesc[0].pSaveRestoreOps = nullptr;
  dataDesc[0].inputFunc = nullptr;
  dataDesc[0].td = nullptr;
  dataDesc[1].externalName = nullptr;
  dataDesc[1].pSaveRestoreOps = nullptr;
  dataDesc[1].inputFunc = nullptr;
  memset(&dataMap.baseMap, 0, 12);
  pField = (CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char> > *)fieldInfo->pField;
  v5 = *(void (__thiscall **)(ISave *))(*(_DWORD *)pSave + 28);
  *(_QWORD *)&dataDesc[0].override_field = 0;
  *(_QWORD *)&dataDesc[0].fieldTolerance = 0;
  *(_QWORD *)&dataDesc[0].flatOffset[1] = 0;
  dataMap.dataDesc = dataDesc;
  dataDesc[0].fieldName = "K";
  dataDesc[1].fieldType = FIELD_EMBEDDED;
  dataDesc[1].fieldName = "T";
  dataDesc[1].td = &CSimpleSimTimer::m_DataMap;
  *(_QWORD *)&dataDesc[1].override_field = 0;
  *(_QWORD *)&dataDesc[1].fieldTolerance = 0;
  *(_QWORD *)&dataDesc[1].flatOffset[1] = 0;
  dataMap.dataClassName = "um";
  v5(this: (ISave *)pSave);
  WriteInt_2 = v3->WriteInt_2;
  pSave = pField->m_NumElements;
  WriteInt_2(this: v3, a2: &pSave, a3: 1);
  Inorder = CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char>>::FirstInorder(this: pField);
  for ( i = Inorder; Inorder != -1; i = Inorder )
  {
    v3->WriteAll(this: v3, a2: &pField->m_Elements.m_pMemory[Inorder].m_Data, a3: &dataMap);
    Inorder = CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char>>::NextInorder(
                this: pField,
                i);
  }
  v3->EndBlock(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1007C4E0
// Name: public: bool CAI_AllySpeechManager::ConceptDelayExpired(class CAI_Concept)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_AllySpeechManager::ConceptDelayExpired(CAI_AllySpeechManager *this, CAI_Concept concept)
{
  const char *StringConcept; // eax
  char v4; // al
  CUtlMap<string_t,CSimpleSimTimer,char>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  StringConcept = ResponseRules::CRR_Concept::GetStringConcept(this: &concept);
  if ( StringConcept == nullptr || *StringConcept == 0 )
    StringConcept = nullptr;
  search.key.pszValue = StringConcept;
  search.elem.m_next = -1.0;
  v4 = CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char>>::Find(
         this: &this->m_ConceptTimers.m_Tree,
         &search);
  return v4 == -1
      || (float)(gpGlobals->curtime - this->m_ConceptTimers.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.m_next) > -0.001;
}

//------------------------------------------------------------------------------
// Address: 0x1007C650
// Name: public: bool CAI_PlayerAlly::IsAllowedToSpeak(class CAI_Concept,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_PlayerAlly::IsAllowedToSpeak(CAI_PlayerAlly *this, CAI_Concept concept, bool bRespondingToPlayer)
{
  CAI_AllySpeechManager *v3; // eax
  unsigned __int16 v5; // ax
  ConceptInfo_t *elem; // ebx
  ConceptCategory_t category; // eax
  unsigned int m_Index; // ecx
  int v10; // eax
  CEntInfo *v11; // edx
  unsigned int v12; // ecx
  int v13; // eax
  bool v14; // zf
  CEntInfo *v15; // eax
  IHandleEntity *v16; // eax
  CAI_Expresser *v17; // eax
  CAI_Expresser *v18; // eax
  ResponseRules::CRR_Concept v19; // [esp+Ch] [ebp-14h] BYREF
  CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t search; // [esp+14h] [ebp-Ch] BYREF
  CAI_AllySpeechManager *pSpeechManager; // [esp+1Ch] [ebp-4h]

  v3 = CAI_AllySpeechManager::gm_pSpeechManager;
  if ( CAI_AllySpeechManager::gm_pSpeechManager == nullptr )
  {
    CreateEntityByName(className: "ai_ally_speech_manager", iForceEdictIndex: -1, bNotify: true);
    v3 = CAI_AllySpeechManager::gm_pSpeechManager;
    if ( CAI_AllySpeechManager::gm_pSpeechManager != nullptr )
    {
      DispatchSpawn(pEntity: CAI_AllySpeechManager::gm_pSpeechManager, bRunVScripts: true);
      v3 = CAI_AllySpeechManager::gm_pSpeechManager;
    }
  }
  pSpeechManager = v3;
  search.key.m_Id = concept.m_iConcept.m_Id;
  v5 = CUtlRBTree<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_ConceptInfoMap.m_Tree,
         &search);
  if ( v5 == 0xFFFF )
  {
    elem = nullptr;
  }
  else
  {
    elem = g_ConceptInfoMap.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
    if ( elem != nullptr )
    {
      category = elem->category;
      goto LABEL_9;
    }
  }
  category = SPEECH_IDLE;
LABEL_9:
  if ( !CAI_PlayerAlly::IsOkToSpeak(this, category, fRespondingToPlayer: bRespondingToPlayer) )
    return false;
  m_Index = this->m_hSpeechFilter.m_Index;
  if ( m_Index != -1 )
  {
    v10 = (unsigned __int16)m_Index;
    v11 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v12 = HIWORD(m_Index);
    if ( v11->m_SerialNumber == v12 && v11->m_pEntity != nullptr )
    {
      v13 = v10;
      v14 = g_pEntityList->m_EntPtrArray[v13].m_SerialNumber == v12;
      v15 = &g_pEntityList->m_EntPtrArray[v13];
      v16 = v14 ? v15->m_pEntity : nullptr;
      if ( LOBYTE(v16[216].__vftable) != 0 )
      {
        ResponseRules::CRR_Concept::CRR_Concept(this: &v19, fromString: "TLK_HELLO");
        if ( concept.m_iConcept.m_Id == v19.m_iConcept.m_Id )
          return false;
        ResponseRules::CRR_Concept::CRR_Concept(this: &v19, fromString: "TLK_HELLO_NPC");
        if ( concept.m_iConcept.m_Id == v19.m_iConcept.m_Id )
          return false;
      }
    }
  }
  if ( !CAI_AllySpeechManager::ConceptDelayExpired(this: pSpeechManager, concept) )
    return false;
  if ( elem != nullptr && (elem->flags & 1) != 0 )
  {
    v17 = this->GetExpresser(this);
    if ( CAI_Expresser::SpokeConcept(this: v17, concept) )
      return false;
  }
  v18 = this->GetExpresser(this);
  return CAI_Expresser::CanSpeakConcept(this: v18, concept);
}

//------------------------------------------------------------------------------
// Address: 0x1007C7F0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::assign(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::assign(std::string *this, char *_Ptr, unsigned int _Count)
{
  unsigned int Myres; // ecx
  std::string *v5; // eax
  std::string *v6; // eax
  unsigned int v8; // eax
  std::string *Ptr; // eax
  bool v10; // cf

  if ( _Ptr != nullptr )
  {
    Myres = this->_Myres;
    v5 = Myres < 0x10 ? this : (std::string *)this->_Bx._Ptr;
    if ( _Ptr >= (char *)v5 )
    {
      v6 = Myres < 0x10 ? this : (std::string *)this->_Bx._Ptr;
      if ( (char *)v6 + this->_Mysize > _Ptr )
      {
        if ( Myres < 0x10 )
          return std::string::assign(this, _Right: this, _Roff: _Ptr - (char *)this, _Count);
        else
          return std::string::assign(this, _Right: this, _Roff: _Ptr - this->_Bx._Ptr, _Count);
      }
    }
  }
  if ( _Count == -1 )
    std::_Xlength_error(_Message: "string too long");
  v8 = this->_Myres;
  if ( v8 < _Count )
  {
    std::string::_Copy(this, _Newsize: _Count, _Oldlen: this->_Mysize);
    if ( _Count == 0 )
      return this;
LABEL_17:
    if ( this->_Myres < 0x10 )
      Ptr = this;
    else
      Ptr = (std::string *)this->_Bx._Ptr;
    memcpy(dst: (unsigned __int8 *)Ptr, src: (unsigned __int8 *)_Ptr, count: _Count);
    v10 = this->_Myres < 0x10;
    this->_Mysize = _Count;
    if ( !v10 )
    {
      this->_Bx._Ptr[_Count] = 0;
      return this;
    }
    this->_Bx._Buf[_Count] = 0;
    return this;
  }
  if ( _Count != 0 )
    goto LABEL_17;
  this->_Mysize = 0;
  if ( v8 < 0x10 )
    this->_Bx._Buf[0] = 0;
  else
    *this->_Bx._Ptr = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007C960
// Name: public: virtual void CUtlMapDataOps<class CUtlMap<struct string_t,class CSimpleSimTimer,char>,2,10>::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMapDataOps<CUtlMap<string_t,CSimpleSimTimer,char>,2,10>::MakeEmpty(
        CUtlMapDataOps<CUtlMap<string_t,CSimpleSimTimer,char>,2,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char>>::RemoveAll(this: (CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char> > *)fieldInfo->pField);
}

//------------------------------------------------------------------------------
// Address: 0x1007C980
// Name: public: CAI_AllySpeechManager::CAI_AllySpeechManager(void)
// Source: json
//------------------------------------------------------------------------------
CAI_AllySpeechManager *__thiscall CAI_AllySpeechManager::CAI_AllySpeechManager(CAI_AllySpeechManager *this)
{
  CAI_AllySpeechManager *result; // eax

  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CAI_AllySpeechManager_vtbl *)&CAI_AllySpeechManager::`vftable';
  this->m_ConceptCategoryTimers[0].m_next = -1.0;
  this->m_ConceptCategoryTimers[1].m_next = -1.0;
  this->m_ConceptCategoryTimers[2].m_next = -1.0;
  this->m_ConceptTimers.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_ConceptTimers.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_ConceptTimers.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_ConceptTimers.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_ConceptTimers.m_Tree.m_Root = -1;
  this->m_ConceptTimers.m_Tree.m_NumElements = 0;
  this->m_ConceptTimers.m_Tree.m_FirstFree = -1;
  this->m_ConceptTimers.m_Tree.m_LastAlloc.index = -1;
  this->m_ConceptTimers.m_Tree.m_pElements = this->m_ConceptTimers.m_Tree.m_Elements.m_pMemory;
  result = this;
  if ( this->m_ConceptTimers.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_ConceptTimers.m_Tree.m_LessFunc.m_LessFunc = ConceptStringLessFunc;
  CAI_AllySpeechManager::gm_pSpeechManager = this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007CA50
// Name: public: virtual void CStdStringSaveRestoreOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdStringSaveRestoreOps::Restore(
        CStdStringSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  std::string *pField; // esi
  char _Ptr[4096]; // [esp+4h] [ebp-1000h] BYREF

  pField = (std::string *)fieldInfo->pField;
  pRestore->ReadString_2(this: pRestore, a2: _Ptr, a3: 4096, a4: 0);
  _Ptr[4095] = 0;
  std::string::assign(this: pField, _Ptr, _Count: strlen(_Ptr));
}

//------------------------------------------------------------------------------
// Address: 0x1007CAF0
// Name: public: virtual void CUtlMapDataOps<class CUtlMap<struct string_t,class CSimpleSimTimer,char>,2,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMapDataOps<CUtlMap<string_t,CSimpleSimTimer,char>,2,10>::Restore(
        CUtlMapDataOps<CUtlMap<string_t,CSimpleSimTimer,char>,2,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  const char *v3; // ebx
  CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char> > *pField; // esi
  IRestore_vtbl *v5; // edx
  void (__thiscall *StartBlock)(IRestore *); // eax
  void (__thiscall *v7)(const char *, CUtlMap<string_t,CSimpleSimTimer,char>::Node_t *, datamap_t *); // edx
  char v8; // al
  char v9; // dl
  int v10; // edi
  UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char> *v11; // ecx
  int v12; // edx
  UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char> *m_pMemory; // ecx
  UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char> *v14; // eax
  CUtlMap<string_t,CSimpleSimTimer,char>::Node_t *p_m_Data; // edi
  typedescription_t dataDesc[2]; // [esp+Ch] [ebp-A8h] BYREF
  datamap_t dataMap; // [esp+84h] [ebp-30h] BYREF
  char elem[4]; // [esp+9Ch] [ebp-18h]
  CUtlMap<string_t,CSimpleSimTimer,char>::Node_t temp; // [esp+A0h] [ebp-14h] BYREF
  CUtlMap<string_t,CSimpleSimTimer,char>::Node_t insert; // [esp+A8h] [ebp-Ch] BYREF
  int nElems; // [esp+B0h] [ebp-4h]

  dataDesc[0].flags = 2;
  dataDesc[0].fieldSize = 1;
  v3 = (const char *)pRestore;
  dataDesc[1].fieldSize = 1;
  dataDesc[0].fieldType = FIELD_STRING;
  dataDesc[0].fieldSizeInBytes = 4;
  dataDesc[1].fieldOffset = 4;
  dataDesc[1].fieldSizeInBytes = 4;
  dataMap.dataNumFields = 2;
  pField = (CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char> > *)fieldInfo->pField;
  dataDesc[1].flags = 2;
  v5 = pRestore->__vftable;
  *(_QWORD *)&dataDesc[0].override_field = 0;
  *(_QWORD *)&dataDesc[0].fieldTolerance = 0;
  *(_QWORD *)&dataDesc[0].flatOffset[1] = 0;
  dataMap.dataDesc = dataDesc;
  StartBlock = v5->StartBlock;
  dataDesc[0].fieldName = "K";
  dataDesc[0].fieldOffset = 0;
  dataDesc[0].externalName = nullptr;
  dataDesc[0].pSaveRestoreOps = nullptr;
  dataDesc[0].inputFunc = nullptr;
  dataDesc[0].td = nullptr;
  dataDesc[1].fieldType = FIELD_EMBEDDED;
  dataDesc[1].fieldName = "T";
  dataDesc[1].externalName = nullptr;
  dataDesc[1].pSaveRestoreOps = nullptr;
  dataDesc[1].inputFunc = nullptr;
  dataDesc[1].td = &CSimpleSimTimer::m_DataMap;
  *(_QWORD *)&dataDesc[1].override_field = 0;
  *(_QWORD *)&dataDesc[1].fieldTolerance = 0;
  *(_QWORD *)&dataDesc[1].flatOffset[1] = 0;
  dataMap.dataClassName = "um";
  memset(&dataMap.baseMap, 0, 12);
  StartBlock(this: pRestore);
  nElems = (*(int (__thiscall **)(const char *))(*(_DWORD *)v3 + 56))(a1: v3);
  temp.elem.m_next = -1.0;
  while ( nElems != 0 )
  {
    v7 = *(void (__thiscall **)(const char *, CUtlMap<string_t,CSimpleSimTimer,char>::Node_t *, datamap_t *))(*(_DWORD *)v3 + 8);
    --nElems;
    v7(a1: v3, a2: &temp, a3: &dataMap);
    insert = temp;
    HIBYTE(fieldInfo) = -1;
    HIBYTE(pRestore) = 0;
    CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char>>::FindInsertionPosition(
      this: pField,
      &insert,
      parent: (char *)&fieldInfo + 3,
      leftchild: (bool *)&pRestore + 3);
    v8 = CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char>>::NewNode(
           this: pField,
           a2: v3);
    v9 = HIBYTE(fieldInfo);
    v10 = v8;
    v11 = &pField->m_Elements.m_pMemory[v10];
    elem[0] = v8;
    v11->m_Parent = HIBYTE(fieldInfo);
    *(_WORD *)&v11->m_Left = -1;
    v11->m_Tag = 0;
    if ( v9 == -1 )
    {
      pField->m_Root = v8;
    }
    else
    {
      v12 = v9;
      m_pMemory = pField->m_Elements.m_pMemory;
      if ( HIBYTE(pRestore) != 0 )
        m_pMemory[v12].m_Left = v8;
      else
        m_pMemory[v12].m_Right = v8;
    }
    CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char>>::InsertRebalance(
      this: pField,
      elem: elem[0]);
    v14 = pField->m_Elements.m_pMemory;
    ++pField->m_NumElements;
    p_m_Data = &v14[v10].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = insert;
  }
  (*(void (__thiscall **)(const char *))(*(_DWORD *)v3 + 32))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1007CCD0
// Name: public: void AISpeechSelection_t::Set(class CAI_Concept,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AISpeechSelection_t::Set(AISpeechSelection_t *this, CAI_Concept newConcept, CBaseEntity *pTarget)
{
  char *StringConcept; // eax

  StringConcept = (char *)ResponseRules::CRR_Concept::GetStringConcept(this: &newConcept);
  std::string::assign(this: &this->concept, _Ptr: StringConcept, _Count: strlen(StringConcept));
  if ( pTarget != nullptr )
    this->hSpeechTarget.m_Index = pTarget->GetRefEHandle(this: pTarget)->m_Index;
  else
    this->hSpeechTarget.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1007CD30
// Name: public: CConceptInfoMap::CConceptInfoMap(void)
// Source: json
//------------------------------------------------------------------------------
CConceptInfoMap *__usercall CConceptInfoMap::CConceptInfoMap@<eax>(
        CConceptInfoMap *this@<ecx>,
        CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t *p_m_Data@<edi>)
{
  ConceptInfo_t *v3; // eax
  unsigned __int16 m_Id; // cx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short> *v9; // eax
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v11; // edx
  bool v12; // zf
  CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t insert; // [esp+Ch] [ebp-18h] BYREF
  int v15; // [esp+14h] [ebp-10h]
  ResponseRules::CRR_Concept *v16; // [esp+18h] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+1Ch] [ebp-8h] BYREF
  bool leftchild; // [esp+23h] [ebp-1h] BYREF

  this->m_Tree.m_LessFunc.m_LessFunc = ConceptIDLessFunc;
  this->m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Tree.m_pElements = this->m_Tree.m_Elements.m_pMemory;
  v3 = (ConceptInfo_t *)&g_ConceptInfos;
  *(_DWORD *)&this->m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Tree.m_FirstFree = -1;
  v16 = &g_ConceptInfos;
  v15 = 80;
  do
  {
    m_Id = v3->concept.m_iConcept.m_Id;
    leftchild = false;
    insert.elem = v3;
    insert.key.m_Id = m_Id;
    *(_DWORD *)parent = 0xFFFF;
    CUtlRBTree<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->m_Tree,
      &insert,
      parent,
      &leftchild);
    v5 = CUtlRBTree<CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
           this: &this->m_Tree,
           a2: (const char *)p_m_Data);
    v6 = parent[0];
    v7 = v5;
    v8 = v5;
    v9 = &this->m_Tree.m_Elements.m_pMemory[v8];
    v9->m_Right = -1;
    v9->m_Left = -1;
    v9->m_Parent = v6;
    v9->m_Tag = 0;
    if ( v6 == 0xFFFF )
    {
      this->m_Tree.m_Root = v7;
    }
    else
    {
      m_pMemory = this->m_Tree.m_Elements.m_pMemory;
      v11 = v6;
      if ( leftchild )
        m_pMemory[v11].m_Left = v7;
      else
        m_pMemory[v11].m_Right = v7;
    }
    CUtlRBTree<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,ConceptInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &this->m_Tree,
      elem: v7);
    p_m_Data = &this->m_Tree.m_Elements.m_pMemory[v8].m_Data;
    ++this->m_Tree.m_NumElements;
    if ( p_m_Data != nullptr )
      *p_m_Data = insert;
    v3 = (ConceptInfo_t *)&v16[20];
    v12 = v15-- == 1;
    v16 += 20;
  }
  while ( !v12 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007CE40
// Name: public: virtual void CAI_AllySpeechManager::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_AllySpeechManager::Spawn(CAI_AllySpeechManager *this)
{
  CUtlMap<string_t,CSimpleSimTimer,char> *p_m_ConceptTimers; // esi
  ResponseRules::CRR_Concept *v2; // ebx
  char v3; // al
  char v4; // dl
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char> *v6; // ecx
  int v7; // ecx
  UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char> *m_pMemory; // edx
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char> *v10; // ecx
  CUtlMap<string_t,CSimpleSimTimer,char>::Node_t insert; // [esp+0h] [ebp-1Ch] BYREF
  char pszValue[4]; // [esp+8h] [ebp-14h] BYREF
  char elem[4]; // [esp+Ch] [ebp-10h]
  float v14; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  bool leftchild; // [esp+1Ah] [ebp-2h] BYREF
  char parent; // [esp+1Bh] [ebp-1h] BYREF

  v14 = -1.0;
  p_m_ConceptTimers = &this->m_ConceptTimers;
  v2 = &g_ConceptInfos;
  for ( i = 80; i != 0; --i )
  {
    ResponseRules::CRR_Concept::GetStringConcept(this: v2);
    insert.key.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
    insert.elem.m_next = v14;
    parent = -1;
    leftchild = false;
    CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char>>::FindInsertionPosition(
      this: &p_m_ConceptTimers->m_Tree,
      &insert,
      &parent,
      &leftchild);
    v3 = CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char>>::NewNode(
           this: &p_m_ConceptTimers->m_Tree,
           a2: (const char *)v2);
    v4 = parent;
    v5 = v3;
    v6 = &p_m_ConceptTimers->m_Tree.m_Elements.m_pMemory[v5];
    elem[0] = v3;
    v6->m_Parent = parent;
    *(_WORD *)&v6->m_Left = -1;
    v6->m_Tag = 0;
    if ( v4 == -1 )
    {
      p_m_ConceptTimers->m_Tree.m_Root = v3;
    }
    else
    {
      v7 = v4;
      m_pMemory = p_m_ConceptTimers->m_Tree.m_Elements.m_pMemory;
      v9 = v7;
      if ( leftchild )
        m_pMemory[v9].m_Left = v3;
      else
        m_pMemory[v9].m_Right = v3;
    }
    CUtlRBTree<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char,CUtlMap<string_t,CSimpleSimTimer,char>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char>,char>>::InsertRebalance(
      this: &p_m_ConceptTimers->m_Tree,
      elem: elem[0]);
    v10 = p_m_ConceptTimers->m_Tree.m_Elements.m_pMemory;
    ++p_m_ConceptTimers->m_Tree.m_NumElements;
    if ( &v10[v5] != (UtlRBTreeNode_t<CUtlMap<string_t,CSimpleSimTimer,char>::Node_t,char> *)-4 )
      v10[v5].m_Data = insert;
    v2 += 20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CF30
// Name: public: bool CAI_PlayerAlly::SelectSpeechResponse(class CAI_Concept,char const __near *,class CBaseEntity __near *,struct AISpeechSelection_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_PlayerAlly::SelectSpeechResponse(
        CAI_PlayerAlly *this,
        CAI_Concept concept,
        const char *pszModifiers,
        CBaseEntity *pTarget,
        AISpeechSelection_t *pSelection)
{
  CAI_Expresser *v6; // eax
  AISpeechSelection_t *v7; // edi
  CAI_Expresser *v8; // eax
  ResponseRules::CRR_Response *p_response; // [esp-Ch] [ebp-38h]
  const char *v11; // [esp-4h] [ebp-30h]
  ResponseRules::CriteriaSet criteria; // [esp+8h] [ebp-24h] BYREF

  if ( CAI_PlayerAlly::IsAllowedToSpeak(this, concept, bRespondingToPlayer: false) )
  {
    ResponseRules::CriteriaSet::CriteriaSet(this: &criteria);
    v11 = pszModifiers;
    v6 = this->GetExpresser(this);
    CAI_Expresser::GatherCriteria(this: v6, outputSet: &criteria, &concept, modifiers: v11);
    v7 = pSelection;
    p_response = &pSelection->response;
    v8 = this->GetExpresser(this);
    if ( CAI_Expresser::FindResponse(this: v8, outResponse: p_response, &concept, &criteria) )
    {
      AISpeechSelection_t::Set(this: v7, newConcept: concept, pTarget);
      CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &criteria.m_Lookup);
      return 1;
    }
    CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &criteria.m_Lookup);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007CFF0
// Name: public: bool CAI_PlayerAlly::SelectAnswerFriend(class CBaseEntity __near *,struct AISpeechSelection_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_PlayerAlly::SelectAnswerFriend(
        CAI_PlayerAlly *this,
        CBaseEntity *pFriend,
        AISpeechSelection_t *pSelection,
        bool bRespondingToHello)
{
  CAI_Concept v6; // [esp-14h] [ebp-20h] BYREF
  const char *v7; // [esp-Ch] [ebp-18h]
  CBaseEntity *v8; // [esp-8h] [ebp-14h]
  AISpeechSelection_t *v9; // [esp-4h] [ebp-10h]

  if ( pFriend != nullptr )
    this->m_hPotentialSpeechTarget.m_Index = pFriend->GetRefEHandle(this: pFriend)->m_Index;
  else
    this->m_hPotentialSpeechTarget.m_Index = -1;
  if ( bRespondingToHello )
  {
    v9 = pSelection;
    v8 = pFriend;
    v7 = nullptr;
    ResponseRules::CRR_Concept::CRR_Concept(this: &v6, fromString: "TLK_ANSWER_HELLO");
    v6.m_hSpeaker.m_Index = -1;
    if ( CAI_PlayerAlly::SelectSpeechResponse(this, concept: v6, pszModifiers: v7, pTarget: v8, pSelection: v9) != 0 )
      return 1;
  }
  v9 = pSelection;
  v8 = pFriend;
  v7 = nullptr;
  ResponseRules::CRR_Concept::CRR_Concept(this: &v6, fromString: "TLK_ANSWER");
  v6.m_hSpeaker.m_Index = -1;
  return CAI_PlayerAlly::SelectSpeechResponse(this, concept: v6, pszModifiers: v7, pTarget: v8, pSelection: v9);
}

//------------------------------------------------------------------------------
// Address: 0x1007D090
// Name: public: void CAI_PlayerAlly::AnswerQuestion(class CAI_PlayerAlly __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlayerAlly::AnswerQuestion(
        CAI_PlayerAlly *this,
        CAI_PlayerAlly *pQuestioner,
        int iQARandomNum,
        bool bAnsweringHello)
{
  IHandleEntity *m_pEntity; // ecx
  AISpeechSelection_t *Ptr; // eax
  unsigned int m_Index; // eax
  IHandleEntity *v8; // ecx
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // edx
  const char *DebugName; // eax
  CAI_Concept v11; // [esp+0h] [ebp-E4h] BYREF
  float flDelay; // [esp+8h] [ebp-DCh]
  CAI_BaseNPC *pIgnore; // [esp+Ch] [ebp-D8h]
  int v14; // [esp+10h] [ebp-D4h]
  int v15; // [esp+14h] [ebp-D0h]
  AISpeechSelection_t selection; // [esp+1Ch] [ebp-C8h] BYREF

  if ( pQuestioner != nullptr )
  {
    selection.concept._Myres = 15;
    selection.concept._Mysize = 0;
    selection.concept._Bx._Buf[0] = 0;
    ResponseRules::CRR_Response::CRR_Response(this: &selection.response);
    LOBYTE(pIgnore) = bAnsweringHello;
    flDelay = COERCE_FLOAT(&selection);
    v11.m_hSpeaker.m_Index = (unsigned int)pQuestioner;
    selection.hSpeechTarget.m_Index = -1;
    this->m_iQARandomNumber = iQARandomNum;
    if ( CAI_PlayerAlly::SelectAnswerFriend(
           this,
           pFriend: (CBaseEntity *)v11.m_hSpeaker.m_Index,
           pSelection: (AISpeechSelection_t *)LODWORD(flDelay),
           bRespondingToHello: (bool)pIgnore) != 0 )
    {
      if ( rr_debug_qa.m_pParent != nullptr && rr_debug_qa.m_pParent->m_Value.m_nValue != 0 )
      {
        pIgnore = (CAI_BaseNPC *)CBaseEntity::GetDebugName(this: pQuestioner);
        flDelay = COERCE_FLOAT(CBaseEntity::GetDebugName(this));
        if ( bAnsweringHello )
          _Warning(a1: "Q&A: '%s' answered the Hello from '%s'\n", flDelay, pIgnore);
        else
          _Warning(a1: "Q&A: '%s' answered the Question from '%s'\n", flDelay, pIgnore);
      }
      if ( selection.hSpeechTarget.m_Index == -1
        || g_pEntityList->m_EntPtrArray[LOWORD(selection.hSpeechTarget.m_Index)].m_SerialNumber != HIWORD(selection.hSpeechTarget.m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[LOWORD(selection.hSpeechTarget.m_Index)].m_pEntity;
      }
      if ( m_pEntity != nullptr )
        this->m_hTalkTarget.m_Index = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
      else
        this->m_hTalkTarget.m_Index = -1;
      Ptr = (AISpeechSelection_t *)selection.concept._Bx._Ptr;
      if ( selection.concept._Myres < 0x10 )
        Ptr = &selection;
      pIgnore = nullptr;
      flDelay = COERCE_FLOAT((AISpeechSelection_t *)&selection.response);
      ResponseRules::CRR_Concept::CRR_Concept(this: &v11, fromString: Ptr->concept._Bx._Buf);
      v11.m_hSpeaker.m_Index = -1;
      CAI_ExpresserHost<CAI_BaseHumanoid>::SpeakDispatchResponse(
        this,
        concept: v11,
        response: (ResponseRules::CRR_Response *)LODWORD(flDelay),
        criteria: (ResponseRules::CriteriaSet *)pIgnore);
      m_Index = this->m_hTalkTarget.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        v8 = nullptr;
      else
        v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      v15 = ((int (__thiscall *)(IHandleEntity *, int, int))v8->__vftable[24].GetRefEHandle)(a1: v8, a2: v14, a3: v15);
      RandomFloat = random->RandomFloat;
      v14 = 1101004800;
      pIgnore = (CAI_BaseNPC *)1092616192;
      flDelay = ((double (__thiscall *)(IUniformRandomStream *))RandomFloat)(a1: random);
      CAI_PlayerAlly::DeferAllIdleSpeech(this, flDelay, pIgnore);
    }
    else if ( rr_debug_qa.m_pParent != nullptr && rr_debug_qa.m_pParent->m_Value.m_nValue != 0 )
    {
      pIgnore = (CAI_BaseNPC *)CBaseEntity::GetDebugName(this: pQuestioner);
      DebugName = CBaseEntity::GetDebugName(this);
      _Warning(a1: "Q&A: '%s' couldn't answer '%s'\n", DebugName, (const char *)pIgnore);
    }
    ResponseRules::CRR_Response::~CRR_Response(this: &selection.response);
    if ( selection.concept._Myres >= 0x10 )
      free(pMem: selection.concept._Bx._Ptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D280
// Name: public: void CAI_PlayerAlly::InputAnswerQuestion(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlayerAlly::InputAnswerQuestion(CAI_PlayerAlly *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  CAI_PlayerAlly *v4; // eax
  int v5; // [esp-8h] [ebp-Ch]

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  v5 = (int)pszValue;
  v4 = (CAI_PlayerAlly *)__RTDynamicCast(
                           inptr: inputdata->pActivator,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CAI_PlayerAlly `RTTI Type Descriptor',
                           isReference: 0);
  CAI_PlayerAlly::AnswerQuestion(this, pQuestioner: v4, iQARandomNum: v5, bAnsweringHello: false);
}

//------------------------------------------------------------------------------
// Address: 0x1007D2C0
// Name: public: void CAI_PlayerAlly::InputAnswerQuestionHello(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlayerAlly::InputAnswerQuestionHello(CAI_PlayerAlly *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  CAI_PlayerAlly *v4; // eax
  int v5; // [esp-8h] [ebp-Ch]

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  v5 = (int)pszValue;
  v4 = (CAI_PlayerAlly *)__RTDynamicCast(
                           inptr: inputdata->pActivator,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CAI_PlayerAlly `RTTI Type Descriptor',
                           isReference: 0);
  CAI_PlayerAlly::AnswerQuestion(this, pQuestioner: v4, iQARandomNum: v5, bAnsweringHello: true);
}

//------------------------------------------------------------------------------
// Address: 0x103FEA10
// Name: CAI_AllySpeechManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_AllySpeechManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_AllySpeechManager>(__formal: nullptr);
  CAI_AllySpeechManager_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FEA20
// Name: CAI_PlayerAlly_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_PlayerAlly_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_PlayerAlly>(__formal: nullptr);
  CAI_PlayerAlly_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007C570
// Name: struct datamap_t __near * DataMapInit<class CAI_AllySpeechManager>(class CAI_AllySpeechManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_AllySpeechManager>()
{
  if ( (_S2_28 & 1) == 0 )
  {
    _S2_28 |= 1u;
    nameHolder_57.m_pszBase = "CAI_AllySpeechManager";
    nameHolder_57.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_57.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_57.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_57.m_Names.m_Size = 0;
    nameHolder_57.m_Names.m_pElements = nullptr;
    nameHolder_57.m_nLenBase = 21;
    atexit(func: DataMapInit_CAI_AllySpeechManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_AllySpeechManager::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_28 & 2) == 0 )
  {
    _S2_28 |= 2u;
    if ( (`CUtlMapDataopsInstantiator<2,10>::GetDataOps<CUtlMap<string_t,CSimpleSimTimer,char>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlMapDataopsInstantiator<2,10>::GetDataOps<CUtlMap<string_t,CSimpleSimTimer,char>>'::`2'::`local static guard' |= 1u;
      `CUtlMapDataopsInstantiator<2,10>::GetDataOps<CUtlMap<string_t,CSimpleSimTimer,char>>'::`2'::ops = (int)&CUtlMapDataOps<CUtlMap<string_t,CSimpleSimTimer,char>,2,10>::`vftable';
    }
    dataDesc_55[2].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlMapDataopsInstantiator<2,10>::GetDataOps<CUtlMap<string_t,CSimpleSimTimer,char>>'::`2'::ops;
    dataDesc_55[2].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_55[2].td = 0;
    *(_QWORD *)&dataDesc_55[2].override_field = 0;
    *(_QWORD *)&dataDesc_55[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_55[2].flatOffset[1] = 0;
  }
  CAI_AllySpeechManager::m_DataMap.dataNumFields = 2;
  CAI_AllySpeechManager::m_DataMap.dataDesc = &dataDesc_55[1];
  return &CAI_AllySpeechManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1007D300
// Name: struct datamap_t __near * DataMapInit<class CAI_PlayerAlly>(class CAI_PlayerAlly __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_PlayerAlly>()
{
  if ( (_S3_13 & 1) == 0 )
  {
    _S3_13 |= 1u;
    nameHolder_58.m_pszBase = "CAI_PlayerAlly";
    nameHolder_58.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_58.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_58.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_58.m_Names.m_Size = 0;
    nameHolder_58.m_Names.m_pElements = nullptr;
    nameHolder_58.m_nLenBase = 14;
    atexit(func: DataMapInit_CAI_PlayerAlly__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_PlayerAlly::m_DataMap.baseMap = &CAI_BaseActor::m_DataMap;
  if ( (_S3_13 & 2) == 0 )
  {
    _S3_13 |= 2u;
    if ( (`GetStdStringDataOps'::`2'::`local static guard' & 1) == 0 )
    {
      `GetStdStringDataOps'::`2'::`local static guard' |= 1u;
      `GetStdStringDataOps'::`2'::ops = (int)&CStdStringSaveRestoreOps::`vftable';
    }
    dataDesc_56[3].fieldSize = 1;
    dataDesc_56[4].fieldSize = 1;
    dataDesc_56[4].flags = 2;
    dataDesc_56[5].fieldSize = 1;
    *(_QWORD *)dataDesc_56[3].flatOffset = 0;
    dataDesc_56[5].flags = 2;
    *(_QWORD *)dataDesc_56[4].flatOffset = 0;
    dataDesc_56[3].flags = 2;
    dataDesc_56[6].fieldSize = 1;
    *(_QWORD *)&dataDesc_56[2].td = 0;
    *(_QWORD *)&dataDesc_56[2].override_field = 0;
    *(_QWORD *)&dataDesc_56[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_56[2].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_56[5].flatOffset = 0;
    dataDesc_56[2].pSaveRestoreOps = (ISaveRestoreOps *)&`GetStdStringDataOps'::`2'::ops;
    dataDesc_56[2].inputFunc = nullptr;
    dataDesc_56[3].fieldType = FIELD_TIME;
    dataDesc_56[3].fieldName = "m_TimePendingSet";
    dataDesc_56[3].fieldOffset = 4448;
    dataDesc_56[3].externalName = nullptr;
    dataDesc_56[3].pSaveRestoreOps = nullptr;
    dataDesc_56[3].inputFunc = nullptr;
    dataDesc_56[3].td = nullptr;
    dataDesc_56[3].fieldSizeInBytes = 4;
    dataDesc_56[3].override_field = nullptr;
    dataDesc_56[3].override_count = 0;
    dataDesc_56[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_56[3].flatGroup = 0;
    dataDesc_56[4].fieldType = FIELD_EHANDLE;
    dataDesc_56[4].fieldName = "m_hTalkTarget";
    dataDesc_56[4].fieldOffset = 4452;
    dataDesc_56[4].externalName = nullptr;
    dataDesc_56[4].pSaveRestoreOps = nullptr;
    dataDesc_56[4].inputFunc = nullptr;
    dataDesc_56[4].td = nullptr;
    dataDesc_56[4].fieldSizeInBytes = 4;
    dataDesc_56[4].override_field = nullptr;
    dataDesc_56[4].override_count = 0;
    dataDesc_56[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_56[4].flatGroup = 0;
    dataDesc_56[5].fieldType = FIELD_TIME;
    dataDesc_56[5].fieldName = "m_flNextRegenTime";
    dataDesc_56[5].fieldOffset = 4456;
    dataDesc_56[5].externalName = nullptr;
    dataDesc_56[5].pSaveRestoreOps = nullptr;
    dataDesc_56[5].inputFunc = nullptr;
    dataDesc_56[5].td = nullptr;
    dataDesc_56[5].fieldSizeInBytes = 4;
    dataDesc_56[5].override_field = nullptr;
    dataDesc_56[5].override_count = 0;
    dataDesc_56[5].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_56[5].flatGroup = 0;
    dataDesc_56[6].fieldType = FIELD_TIME;
    dataDesc_56[6].fieldName = "m_flTimePlayerStartStare";
    dataDesc_56[6].fieldOffset = 4460;
    dataDesc_56[6].flags = 2;
    dataDesc_56[6].externalName = nullptr;
    dataDesc_56[6].pSaveRestoreOps = nullptr;
    dataDesc_56[6].inputFunc = nullptr;
    dataDesc_56[6].td = nullptr;
    dataDesc_56[6].fieldSizeInBytes = 4;
    dataDesc_56[6].override_field = nullptr;
    dataDesc_56[6].override_count = 0;
    dataDesc_56[6].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_56[6].flatOffset = 0;
    dataDesc_56[7].fieldSize = 1;
    dataDesc_56[7].flags = 2;
    dataDesc_56[9].fieldSize = 1;
    dataDesc_56[9].flags = 2;
    dataDesc_56[7].fieldType = FIELD_EHANDLE;
    dataDesc_56[10].fieldType = FIELD_EHANDLE;
    dataDesc_56[10].fieldSize = 1;
    *(_QWORD *)dataDesc_56[7].flatOffset = 0;
    dataDesc_56[10].flags = 2;
    *(_QWORD *)dataDesc_56[8].flatOffset = 0;
    dataDesc_56[11].fieldSize = 3;
    *(_QWORD *)dataDesc_56[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_56[6].flatGroup = 0;
    dataDesc_56[7].fieldName = "m_hPotentialSpeechTarget";
    dataDesc_56[7].fieldOffset = 4464;
    dataDesc_56[7].externalName = nullptr;
    dataDesc_56[7].pSaveRestoreOps = nullptr;
    dataDesc_56[7].inputFunc = nullptr;
    dataDesc_56[7].td = nullptr;
    dataDesc_56[7].fieldSizeInBytes = 4;
    dataDesc_56[7].override_field = nullptr;
    dataDesc_56[7].override_count = 0;
    dataDesc_56[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_56[7].flatGroup = 0;
    dataDesc_56[8].fieldType = FIELD_TIME;
    dataDesc_56[8].fieldName = "m_flNextIdleSpeechTime";
    dataDesc_56[8].fieldOffset = 4468;
    *(_DWORD *)&dataDesc_56[8].fieldSize = 131073;
    dataDesc_56[8].externalName = nullptr;
    dataDesc_56[8].pSaveRestoreOps = nullptr;
    dataDesc_56[8].inputFunc = nullptr;
    dataDesc_56[8].td = nullptr;
    dataDesc_56[8].fieldSizeInBytes = 4;
    dataDesc_56[8].override_field = nullptr;
    dataDesc_56[8].override_count = 0;
    dataDesc_56[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_56[8].flatGroup = 0;
    dataDesc_56[9].fieldType = FIELD_INTEGER;
    dataDesc_56[9].fieldName = "m_iQARandomNumber";
    dataDesc_56[9].fieldOffset = 4472;
    dataDesc_56[9].externalName = nullptr;
    dataDesc_56[9].pSaveRestoreOps = nullptr;
    dataDesc_56[9].inputFunc = nullptr;
    dataDesc_56[9].td = nullptr;
    dataDesc_56[9].fieldSizeInBytes = 4;
    dataDesc_56[9].override_field = nullptr;
    dataDesc_56[9].override_count = 0;
    dataDesc_56[9].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_56[9].flatGroup = 0;
    dataDesc_56[10].fieldName = "m_hSpeechFilter";
    dataDesc_56[10].fieldOffset = 4488;
    dataDesc_56[10].externalName = nullptr;
    dataDesc_56[10].pSaveRestoreOps = nullptr;
    dataDesc_56[10].inputFunc = nullptr;
    dataDesc_56[10].td = nullptr;
    dataDesc_56[10].fieldSizeInBytes = 4;
    dataDesc_56[10].override_field = nullptr;
    dataDesc_56[10].override_count = 0;
    dataDesc_56[10].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_56[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_56[10].flatGroup = 0;
    dataDesc_56[11].fieldType = FIELD_EMBEDDED;
    dataDesc_56[11].fieldName = "m_ConceptCategoryTimers";
    dataDesc_56[11].fieldOffset = 4476;
    dataDesc_56[11].flags = 2;
    dataDesc_56[11].externalName = nullptr;
    dataDesc_56[11].pSaveRestoreOps = nullptr;
    dataDesc_56[12].fieldSize = 1;
    dataDesc_56[12].flags = 6;
    dataDesc_56[13].fieldType = FIELD_BOOLEAN;
    dataDesc_56[13].fieldSize = 1;
    dataDesc_56[13].flags = 2;
    *(_QWORD *)dataDesc_56[11].flatOffset = 0;
    dataDesc_56[15].fieldType = FIELD_TIME;
    *(_QWORD *)dataDesc_56[12].flatOffset = 0;
    dataDesc_56[14].fieldSize = 1;
    dataDesc_56[15].fieldSize = 1;
    dataDesc_56[11].fieldTolerance = 0.0;
    dataDesc_56[12].fieldTolerance = 0.0;
    dataDesc_56[13].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_56[13].flatOffset = 0;
    dataDesc_56[14].fieldTolerance = 0.0;
    dataDesc_56[15].fieldTolerance = 0.0;
    dataDesc_56[11].inputFunc = nullptr;
    dataDesc_56[11].td = &CSimpleSimTimer::m_DataMap;
    dataDesc_56[11].fieldSizeInBytes = 4;
    dataDesc_56[11].override_field = nullptr;
    dataDesc_56[11].override_count = 0;
    *(_DWORD *)&dataDesc_56[11].flatGroup = 0;
    dataDesc_56[12].fieldType = FIELD_BOOLEAN;
    dataDesc_56[12].fieldName = "m_bGameEndAlly";
    dataDesc_56[12].fieldOffset = 4492;
    dataDesc_56[12].externalName = "GameEndAlly";
    dataDesc_56[12].pSaveRestoreOps = nullptr;
    dataDesc_56[12].inputFunc = nullptr;
    dataDesc_56[12].td = nullptr;
    dataDesc_56[12].fieldSizeInBytes = 1;
    dataDesc_56[12].override_field = nullptr;
    dataDesc_56[12].override_count = 0;
    *(_DWORD *)&dataDesc_56[12].flatGroup = 0;
    dataDesc_56[13].fieldName = "m_bCanSpeakWhileScripting";
    dataDesc_56[13].fieldOffset = 4493;
    dataDesc_56[13].externalName = nullptr;
    dataDesc_56[13].pSaveRestoreOps = nullptr;
    dataDesc_56[13].inputFunc = nullptr;
    dataDesc_56[13].td = nullptr;
    dataDesc_56[13].fieldSizeInBytes = 1;
    dataDesc_56[13].override_field = nullptr;
    dataDesc_56[13].override_count = 0;
    *(_DWORD *)&dataDesc_56[13].flatGroup = 0;
    dataDesc_56[14].fieldType = FIELD_FLOAT;
    dataDesc_56[14].fieldName = "m_flHealthAccumulator";
    dataDesc_56[14].fieldOffset = 4500;
    dataDesc_56[14].flags = 2;
    dataDesc_56[14].externalName = nullptr;
    dataDesc_56[14].pSaveRestoreOps = nullptr;
    dataDesc_56[14].inputFunc = nullptr;
    dataDesc_56[14].td = nullptr;
    dataDesc_56[14].fieldSizeInBytes = 4;
    dataDesc_56[14].override_field = nullptr;
    dataDesc_56[14].override_count = 0;
    *(_QWORD *)dataDesc_56[14].flatOffset = 0;
    *(_DWORD *)&dataDesc_56[14].flatGroup = 0;
    dataDesc_56[15].fieldName = "m_flTimeLastRegen";
    dataDesc_56[15].fieldOffset = 4496;
    dataDesc_56[15].flags = 2;
    dataDesc_56[15].externalName = nullptr;
    dataDesc_56[15].pSaveRestoreOps = nullptr;
    dataDesc_56[15].inputFunc = nullptr;
    dataDesc_56[15].td = nullptr;
    dataDesc_56[15].fieldSizeInBytes = 4;
    dataDesc_56[15].override_field = nullptr;
    dataDesc_56[15].override_count = 0;
    *(_QWORD *)dataDesc_56[15].flatOffset = 0;
    *(_DWORD *)&dataDesc_56[15].flatGroup = 0;
    *(_QWORD *)&dataDesc_56[16].td = 0;
    *(_QWORD *)&dataDesc_56[16].override_field = 0;
    *(_QWORD *)&dataDesc_56[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_56[16].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_56[17].td = 0;
    *(_QWORD *)&dataDesc_56[17].override_field = 0;
    *(_QWORD *)&dataDesc_56[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_56[17].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_56[18].td = 0;
    *(_QWORD *)&dataDesc_56[18].override_field = 0;
    *(_QWORD *)&dataDesc_56[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_56[18].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_56[19].td = 0;
    *(_QWORD *)&dataDesc_56[19].override_field = 0;
    *(_QWORD *)&dataDesc_56[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_56[19].flatOffset[1] = 0;
    dataDesc_56[16].fieldSize = 1;
    dataDesc_56[17].fieldSize = 1;
    dataDesc_56[18].fieldSize = 1;
    dataDesc_56[19].fieldSize = 1;
    dataDesc_56[20].fieldType = FIELD_INTEGER;
    dataDesc_56[20].fieldSize = 1;
    dataDesc_56[21].fieldType = FIELD_INTEGER;
    *(_QWORD *)&dataDesc_56[20].td = 0;
    *(_QWORD *)&dataDesc_56[20].override_field = 0;
    *(_QWORD *)&dataDesc_56[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_56[20].flatOffset[1] = 0;
    dataDesc_56[16].fieldType = FIELD_VOID;
    dataDesc_56[16].fieldName = "InputIdleRespond";
    dataDesc_56[16].fieldOffset = 0;
    dataDesc_56[16].flags = 8;
    dataDesc_56[16].externalName = "IdleRespond";
    dataDesc_56[16].pSaveRestoreOps = nullptr;
    dataDesc_56[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CAI_PlayerAlly::`vcall'{2588,{flat}};
    dataDesc_56[17].fieldType = FIELD_STRING;
    dataDesc_56[17].fieldName = "InputSpeakResponseConcept";
    dataDesc_56[17].fieldOffset = 0;
    dataDesc_56[17].flags = 8;
    dataDesc_56[17].externalName = "SpeakResponseConcept";
    dataDesc_56[17].pSaveRestoreOps = nullptr;
    dataDesc_56[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_PlayerAlly::InputSpeakResponseConcept;
    dataDesc_56[18].fieldType = FIELD_VOID;
    dataDesc_56[18].fieldName = "InputMakeGameEndAlly";
    dataDesc_56[18].fieldOffset = 0;
    dataDesc_56[18].flags = 8;
    dataDesc_56[18].externalName = "MakeGameEndAlly";
    dataDesc_56[18].pSaveRestoreOps = nullptr;
    dataDesc_56[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_PlayerAlly::InputMakeGameEndAlly;
    dataDesc_56[19].fieldType = FIELD_VOID;
    dataDesc_56[19].fieldName = "InputMakeRegularAlly";
    dataDesc_56[19].fieldOffset = 0;
    dataDesc_56[19].flags = 8;
    dataDesc_56[19].externalName = "MakeRegularAlly";
    dataDesc_56[19].pSaveRestoreOps = nullptr;
    dataDesc_56[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_PlayerAlly::InputMakeRegularAlly;
    dataDesc_56[20].fieldName = "InputAnswerQuestion";
    dataDesc_56[20].fieldOffset = 0;
    dataDesc_56[20].flags = 8;
    dataDesc_56[20].externalName = "AnswerQuestion";
    dataDesc_56[20].pSaveRestoreOps = nullptr;
    dataDesc_56[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_PlayerAlly::InputAnswerQuestion;
    dataDesc_56[21].fieldName = "InputAnswerQuestionHello";
    dataDesc_56[21].fieldOffset = 0;
    dataDesc_56[21].fieldSize = 1;
    dataDesc_56[21].flags = 8;
    dataDesc_56[21].externalName = "AnswerQuestionHello";
    dataDesc_56[21].pSaveRestoreOps = nullptr;
    dataDesc_56[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_PlayerAlly::InputAnswerQuestionHello;
    *(_QWORD *)&dataDesc_56[21].td = 0;
    *(_QWORD *)&dataDesc_56[21].override_field = 0;
    *(_QWORD *)&dataDesc_56[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_56[21].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_56[22].td = 0;
    *(_QWORD *)&dataDesc_56[22].override_field = 0;
    *(_QWORD *)&dataDesc_56[22].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_56[22].flatOffset[1] = 0;
    dataDesc_56[22].fieldType = FIELD_VOID;
    dataDesc_56[22].fieldName = "InputEnableSpeakWhileScripting";
    dataDesc_56[22].fieldOffset = 0;
    dataDesc_56[22].fieldSize = 1;
    dataDesc_56[22].flags = 8;
    dataDesc_56[22].externalName = "EnableSpeakWhileScripting";
    dataDesc_56[22].pSaveRestoreOps = nullptr;
    dataDesc_56[22].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_PlayerAlly::InputEnableSpeakWhileScripting;
    dataDesc_56[23].fieldType = FIELD_VOID;
    dataDesc_56[23].fieldName = "InputDisableSpeakWhileScripting";
    dataDesc_56[23].fieldOffset = 0;
    *(_DWORD *)&dataDesc_56[23].fieldSize = 524289;
    dataDesc_56[23].externalName = "DisableSpeakWhileScripting";
    dataDesc_56[23].pSaveRestoreOps = nullptr;
    dataDesc_56[23].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_PlayerAlly::InputDisableSpeakWhileScripting;
    *(_QWORD *)&dataDesc_56[23].td = 0;
    *(_QWORD *)&dataDesc_56[23].override_field = 0;
    *(_QWORD *)&dataDesc_56[23].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_56[23].flatOffset[1] = 0;
  }
  CAI_PlayerAlly::m_DataMap.dataNumFields = 23;
  CAI_PlayerAlly::m_DataMap.dataDesc = &dataDesc_56[1];
  return &CAI_PlayerAlly::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FEA30
// Name: _dynamic_initializer_for__npc_ally_deathmessage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__npc_ally_deathmessage__()
{
  ConVar::ConVar(this: &npc_ally_deathmessage, pName: "npc_ally_deathmessage", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__npc_ally_deathmessage__);
}

//------------------------------------------------------------------------------
// Address: 0x103FEA60
// Name: _dynamic_initializer_for__CAI_PlayerAlly::gm_ClassScheduleIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_PlayerAlly::gm_ClassScheduleIdSpace__()
{
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_PlayerAlly::gm_ClassScheduleIdSpace.m_ScheduleIds, fIsRoot: false);
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_PlayerAlly::gm_ClassScheduleIdSpace.m_TaskIds, fIsRoot: false);
  return CAI_LocalIdSpace::CAI_LocalIdSpace(
           this: &CAI_PlayerAlly::gm_ClassScheduleIdSpace.m_ConditionIds,
           fIsRoot: false);
}

//------------------------------------------------------------------------------
// Address: 0x103FEA90
// Name: _dynamic_initializer_for__CAI_PlayerAlly::gm_SquadSlotIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_PlayerAlly::gm_SquadSlotIdSpace__()
{
  return CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_PlayerAlly::gm_SquadSlotIdSpace, fIsRoot: false);
}

//------------------------------------------------------------------------------
// Address: 0x103FEAA0
// Name: _dynamic_initializer_for__g_BreakInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_BreakInit__()
{
  CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
}
