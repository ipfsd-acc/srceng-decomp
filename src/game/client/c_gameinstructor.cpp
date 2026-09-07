// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_gameinstructor.cpp
// Functions: 73
// ============================================================

#include "game\client\c_gameinstructor.h"

//------------------------------------------------------------------------------
// Address: 0x100735E0
// Name: struct TitleDataFieldsDescription_t const __near * TitleDataFieldsDescriptionFindByString(struct TitleDataFieldsDescription_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const TitleDataFieldsDescription_t *__cdecl TitleDataFieldsDescriptionFindByString(
        const TitleDataFieldsDescription_t *fields,
        const char *szString)
{
  const TitleDataFieldsDescription_t *v3; // esi

  if ( szString == nullptr )
    return nullptr;
  v3 = fields;
  if ( fields != nullptr )
  {
    while ( v3->m_szFieldName != nullptr )
    {
      if ( _V_stricmp(s1: v3->m_szFieldName, s2: szString) == 0 )
        return v3;
      if ( ++v3 == nullptr )
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10073620
// Name: public: virtual void GameinstructorIconsPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameinstructorIconsPrecache::CResourcePrecacher::Cache(
        GameinstructorIconsPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: KV_DEP_FILE,
    a3: "scripts/instructor_texturemanifest.txt",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10073650
// Name: class C_GameInstructor __near & GetGameInstructor(void)
// Source: json
//------------------------------------------------------------------------------
C_GameInstructor *__cdecl GetGameInstructor()
{
  return (C_GameInstructor *)&g_GameInstructor;
}

//------------------------------------------------------------------------------
// Address: 0x10073660
// Name: FixGameInstructorLessonNameForTitleData
// Source: json
//------------------------------------------------------------------------------
void __fastcall FixGameInstructorLessonNameForTitleData(char *chBuffer)
{
  char v1; // al

  for ( ; chBuffer != nullptr; ++chBuffer )
  {
    v1 = *chBuffer;
    if ( *chBuffer == 0 )
      break;
    if ( (v1 < 97 || v1 > 122) && (v1 < 65 || v1 > 90) && (v1 < 48 || v1 > 57) && v1 != 46 && v1 != 95 )
      *chBuffer = 95;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100736B0
// Name: class ISaveRestoreBlockHandler __near * GetGameInstructorRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CGameInstructorSaveRestoreBlockHandler *__cdecl GetGameInstructorRestoreBlockHandler()
{
  return &g_GameInstructorSaveRestoreBlockHandler;
}

//------------------------------------------------------------------------------
// Address: 0x100736C0
// Name: gameinstructor_reload_lessons
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameinstructor_reload_lessons()
{
  g_GameInstructor.Shutdown(this: &g_GameInstructor);
  g_GameInstructor.Init(this: &g_GameInstructor);
}

//------------------------------------------------------------------------------
// Address: 0x100736E0
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x100736F0
// Name: public: void C_GameInstructor::PlaySound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::PlaySound(C_GameInstructor *this, const char *pchSoundName)
{
  C_BasePlayer *pLocalPlayer; // [esp+10h] [ebp-4h]

  pLocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( pLocalPlayer != nullptr )
  {
    if ( *pchSoundName != 0 && _V_strcmp(s1: this->m_szPreviousStartSound, s2: pchSoundName) != 0 )
    {
      _V_strcpy(dest: this->m_szPreviousStartSound, src: pchSoundName);
      this->m_fNextStartSoundTime = 0.0;
    }
    if ( *(float *)(gpGlobals.m_Index + 12) >= this->m_fNextStartSoundTime && *pchSoundName != 0 )
    {
      C_BaseEntity::EmitSound(this: pLocalPlayer, soundname: pchSoundName, soundtime: 0, duration: nullptr);
      this->m_fNextStartSoundTime = gameinstructor_start_sound_cooldown.m_pParent->m_Value.m_fValue
                                  + *(float *)(gpGlobals.m_Index + 12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073790
// Name: private: bool C_GameInstructor::UpdateActiveLesson(class CBaseLesson __near *,class CBaseLesson const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_GameInstructor::UpdateActiveLesson(
        C_GameInstructor *this,
        CBaseLesson *pLesson,
        CBaseLesson *pRootLesson)
{
  void (__thiscall *Start)(CBaseLesson *); // eax
  const char *v4; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_GameInstructor::UpdateActiveLesson",
    a3: 0,
    a4: "GameInstructor",
    a5: false,
    a6: 4);
  if ( pLesson->m_fStartTime > 0.0 )
  {
LABEL_8:
    pLesson->Update(this: pLesson);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  if ( !CBaseLesson::IsLearned(this: pRootLesson) )
  {
    Start = pLesson->Start;
    pLesson->m_fStartTime = *(float *)(gpGlobals.m_Index + 12);
    Start(this: pLesson);
    if ( (*((_BYTE *)pLesson + 60) & 8) != 0 && pLesson->ShouldDisplay(this: pLesson) )
    {
      if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Started lesson ");
        v4 = CGameInstructorSymbol::String(this: &pLesson->m_stringName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseOpen, a2: "\"%s\"", v4);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ".\n");
      }
      goto LABEL_8;
    }
    pLesson->Stop(this: pLesson);
    pLesson->m_fStartTime = 0.0;
    pLesson->m_bHasPlayedSound = false;
  }
  pLesson->UpdateInactive(this: pLesson);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100738B0
// Name: private: void C_GameInstructor::UpdateInactiveLesson(class CBaseLesson __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::UpdateInactiveLesson(C_GameInstructor *this, CBaseLesson *pLesson)
{
  const char *v2; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_GameInstructor::UpdateInactiveLesson",
    a3: 0,
    a4: "GameInstructor",
    a5: false,
    a6: 4);
  if ( pLesson->m_fStartTime > 0.0 )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Stopped lesson ");
      v2 = CGameInstructorSymbol::String(this: &pLesson->m_stringName);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\"", v2);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ".\n");
    }
    pLesson->Stop(this: pLesson);
    pLesson->m_fStartTime = 0.0;
    pLesson->m_bHasPlayedSound = false;
  }
  pLesson->UpdateInactive(this: pLesson);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10073970
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 0xFFu, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10073A80
// Name: void GameInstructorEnable_ChangeCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GameInstructorEnable_ChangeCallback(IConVar *var, const char *pOldValue, float flOldValue)
{
  int m_nValue; // eax

  if ( gameinstructor_enable.m_pParent != nullptr )
    m_nValue = gameinstructor_enable.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( (flOldValue != 0.0) != (m_nValue != 0) )
  {
    if ( sv_gameinstructor_disable.m_pParent != nullptr && sv_gameinstructor_disable.m_pParent->m_Value.m_nValue != 0
      || gameinstructor_enable.m_pParent == nullptr
      || gameinstructor_enable.m_pParent->m_Value.m_nValue == 0 )
    {
      g_GameInstructor.Shutdown(this: &g_GameInstructor);
    }
    else
    {
      g_GameInstructor.Init(this: &g_GameInstructor);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073B00
// Name: void SVGameInstructorDisable_ChangeCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SVGameInstructorDisable_ChangeCallback()
{
  if ( engine != nullptr )
  {
    if ( sv_gameinstructor_disable.m_pParent != nullptr && sv_gameinstructor_disable.m_pParent->m_Value.m_nValue != 0
      || gameinstructor_enable.m_pParent == nullptr
      || gameinstructor_enable.m_pParent->m_Value.m_nValue == 0 )
    {
      g_GameInstructor.Shutdown(this: &g_GameInstructor);
    }
    else
    {
      g_GameInstructor.Init(this: &g_GameInstructor);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073B50
// Name: public: bool C_GameInstructor::IsLessonOfSameTypeOpen(class CBaseLesson const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_GameInstructor::IsLessonOfSameTypeOpen(C_GameInstructor *this, const CBaseLesson *pLesson)
{
  int v3; // esi

  v3 = 0;
  if ( this->m_OpenOpportunities.m_Size <= 0 )
    return 0;
  while ( !CGameInstructorSymbol::operator==(
             this: &this->m_OpenOpportunities.m_Memory.m_pMemory[v3]->m_stringName,
             src: &pLesson->m_stringName) )
  {
    if ( ++v3 >= this->m_OpenOpportunities.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10073B90
// Name: public: void C_GameInstructor::SaveGameBlock(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::SaveGameBlock(C_GameInstructor *this, ISave *pSave)
{
  int v2; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  void (__thiscall *v5)(ISave *, const int *, int); // edx
  int nCount; // [esp+8h] [ebp-4h] BYREF

  v2 = 0;
  if ( gameinstructor_save_restore_lessons.m_pParent != nullptr
    && gameinstructor_save_restore_lessons.m_pParent->m_Value.m_nValue != 0 )
  {
    WriteInt_2 = pSave->WriteInt_2;
    nCount = this->m_OpenOpportunities.m_Size;
    WriteInt_2(this: pSave, a2: &nCount, a3: 1);
    if ( nCount > 0 )
    {
      do
      {
        pSave->StartBlock(this: pSave);
        pSave->WriteAll(
          this: pSave,
          a2: this->m_OpenOpportunities.m_Memory.m_pMemory[v2],
          a3: &CScriptedIconLesson::m_DataMap);
        pSave->EndBlock(this: pSave);
        ++v2;
      }
      while ( v2 < nCount );
    }
  }
  else
  {
    v5 = pSave->WriteInt_2;
    nCount = 0;
    v5(this: pSave, a2: &nCount, a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073C20
// Name: public: void C_GameInstructor::KeyValueBuilder(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::KeyValueBuilder(C_GameInstructor *this, KeyValues *pKeyValues)
{
  IMatchSystem *v3; // eax
  int v4; // eax
  IMatchTitle *v5; // eax
  int v6; // edi
  CBaseLesson *v7; // eax
  int m_iDisplayCount; // ebx
  const char *v9; // eax
  const TitleDataFieldsDescription_t *v10; // eax
  IPlayerLocal_vtbl *v11; // edx
  CFmtStrN<256> tdKey; // [esp+4h] [ebp-11Ch] BYREF
  const TitleDataFieldsDescription_t *fields; // [esp+110h] [ebp-10h]
  IPlayerLocal *pPlayer; // [esp+114h] [ebp-Ch]
  int m_iSuccessCount; // [esp+118h] [ebp-8h]
  _BYTE v16[4]; // [esp+11Ch] [ebp-4h] BYREF

  if ( this->m_nSplitScreenSlot == 0 )
  {
    v3 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
    v4 = v3->GetPlayerManager(this: v3);
    pPlayer = (IPlayerLocal *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v4 + 4))(
                                a1: v4,
                                a2: this->m_nSplitScreenSlot);
    if ( pPlayer != nullptr )
    {
      v5 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
      v6 = 0;
      for ( fields = v5->DescribeTitleDataStorage(this: v5); v6 < this->m_Lessons.m_Size; ++v6 )
      {
        v7 = this->m_Lessons.m_Memory.m_pMemory[v6];
        m_iDisplayCount = v7->m_iDisplayCount;
        m_iSuccessCount = v7->m_iSuccessCount;
        v9 = CGameInstructorSymbol::String(this: &v7->m_stringName);
        CFmtStrN<256>::CFmtStrN<256>(this: &tdKey, pszFormat: "GI.lesson.%s", v9);
        FixGameInstructorLessonNameForTitleData(chBuffer: tdKey.m_szBuf);
        v10 = TitleDataFieldsDescriptionFindByString(fields, szString: tdKey.m_szBuf);
        if ( v10 != nullptr )
        {
          v11 = pPlayer->__vftable;
          v16[0] = (16 * m_iSuccessCount) | m_iDisplayCount & 0xF;
          v11->UpdatePlayerTitleData(this: pPlayer, a2: v10, a3: v16, a4: 1);
        }
        else
        {
          _Warning(a1: "C_GameInstructor::KeyValueBuilder failed to save %s\n", tdKey.m_szBuf);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073D40
// Name: public: void C_GameInstructor::ResetDisplaysAndSuccesses(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::ResetDisplaysAndSuccesses(C_GameInstructor *this)
{
  int i; // esi

  if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
  {
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Reset all lesson display and success counts.\n");
  }
  for ( i = 0; i < this->m_Lessons.m_Size; ++i )
    CBaseLesson::ResetDisplaysAndSuccesses(this: this->m_Lessons.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10073DA0
// Name: public: void C_GameInstructor::SetLessonGroupEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::SetLessonGroupEnabled(C_GameInstructor *this, const char *pszGroup, bool bEnabled)
{
  int i; // esi
  const char *v5; // eax

  for ( i = 0; i < this->m_Lessons.m_Size; ++i )
  {
    v5 = CGameInstructorSymbol::String(this: &this->m_Lessons.m_Memory.m_pMemory[i]->m_szLessonGroup);
    if ( _V_stricmp(s1: pszGroup, s2: v5) == 0 )
      this->m_Lessons.m_Memory.m_pMemory[i]->m_bDisabled = !bEnabled;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073DF0
// Name: private: void C_GameInstructor::FindErrors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::FindErrors(C_GameInstructor *this)
{
  int v1; // eax
  CScriptedIconLesson *v2; // eax
  CScriptedIconLesson *v3; // esi
  int v4; // edi
  int v5; // ebx
  int v6; // edi
  int v7; // ebx
  int v8; // edi
  int v9; // ebx
  int v10; // edi
  int v11; // ebx
  int v12; // edi
  int v13; // ebx
  C_GameInstructor *v14; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  v1 = 0;
  v14 = this;
  for ( i = 0; v1 < v14->m_Lessons.m_Size; i = v1 )
  {
    v2 = (CScriptedIconLesson *)__RTDynamicCast(
                                  inptr: this->m_Lessons.m_Memory.m_pMemory[v1],
                                  VfDelta: 0,
                                  SrcType: &CBaseLesson `RTTI Type Descriptor',
                                  TargetType: &CScriptedIconLesson `RTTI Type Descriptor',
                                  isReference: 0);
    v3 = v2;
    if ( v2 != nullptr )
    {
      v4 = 0;
      if ( v2->m_OpenEvents.m_Size > 0 )
      {
        v5 = 0;
        do
        {
          CScriptedIconLesson::ProcessElements(
            this: v3,
            event: nullptr,
            pElements: &v3->m_OpenEvents.m_Memory.m_pMemory[v5].elements);
          ++v4;
          ++v5;
        }
        while ( v4 < v3->m_OpenEvents.m_Size );
      }
      v6 = 0;
      if ( v3->m_CloseEvents.m_Size > 0 )
      {
        v7 = 0;
        do
        {
          CScriptedIconLesson::ProcessElements(
            this: v3,
            event: nullptr,
            pElements: &v3->m_CloseEvents.m_Memory.m_pMemory[v7].elements);
          ++v6;
          ++v7;
        }
        while ( v6 < v3->m_CloseEvents.m_Size );
      }
      v8 = 0;
      if ( v3->m_SuccessEvents.m_Size > 0 )
      {
        v9 = 0;
        do
        {
          CScriptedIconLesson::ProcessElements(
            this: v3,
            event: nullptr,
            pElements: &v3->m_SuccessEvents.m_Memory.m_pMemory[v9].elements);
          ++v8;
          ++v9;
        }
        while ( v8 < v3->m_SuccessEvents.m_Size );
      }
      v10 = 0;
      if ( v3->m_OnOpenEvents.m_Size > 0 )
      {
        v11 = 0;
        do
        {
          CScriptedIconLesson::ProcessElements(
            this: v3,
            event: nullptr,
            pElements: &v3->m_OnOpenEvents.m_Memory.m_pMemory[v11].elements);
          ++v10;
          ++v11;
        }
        while ( v10 < v3->m_OnOpenEvents.m_Size );
      }
      v12 = 0;
      if ( v3->m_UpdateEvents.m_Size > 0 )
      {
        v13 = 0;
        do
        {
          CScriptedIconLesson::ProcessElements(
            this: v3,
            event: nullptr,
            pElements: &v3->m_UpdateEvents.m_Memory.m_pMemory[v13].elements);
          ++v12;
          ++v13;
        }
        while ( v12 < v3->m_UpdateEvents.m_Size );
      }
    }
    this = v14;
    v1 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073F40
// Name: private: class CBaseLesson __near * C_GameInstructor::GetLesson_Internal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseLesson *__thiscall C_GameInstructor::GetLesson_Internal(C_GameInstructor *this, const char *pchLessonName)
{
  int v3; // esi
  CBaseLesson *v4; // edi
  const char *v5; // eax

  v3 = 0;
  if ( this->m_Lessons.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_Lessons.m_Memory.m_pMemory[v3];
    v5 = CGameInstructorSymbol::String(this: &v4->m_stringName);
    if ( _V_strcmp(s1: v5, s2: pchLessonName) == 0 )
      break;
    if ( ++v3 >= this->m_Lessons.m_Size )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10073F90
// Name: private: void C_GameInstructor::StopAllLessons(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::StopAllLessons(C_GameInstructor *this)
{
  int v1; // ebx
  CBaseLesson *v2; // esi
  const char *v3; // eax
  C_GameInstructor *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_OpenOpportunities.m_Size - 1;
  v4 = this;
  if ( v1 >= 0 )
  {
    while ( 1 )
    {
      v2 = this->m_OpenOpportunities.m_Memory.m_pMemory[v1];
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "C_GameInstructor::UpdateInactiveLesson",
        a3: 0,
        a4: "GameInstructor",
        a5: false,
        a6: 4);
      if ( v2->m_fStartTime > 0.0 )
      {
        if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
        {
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Stopped lesson ");
          v3 = CGameInstructorSymbol::String(this: &v2->m_stringName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\"", v3);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ".\n");
        }
        v2->Stop(this: v2);
        v2->m_fStartTime = 0.0;
        v2->m_bHasPlayedSound = false;
      }
      v2->UpdateInactive(this: v2);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      if ( --v1 < 0 )
        break;
      this = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074080
// Name: public: virtual char const __near * CGameInstructorSaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameInstructorSaveRestoreBlockHandler::GetBlockName(
        CGameInstructorSaveRestoreBlockHandler *this)
{
  return "GameInstructor";
}

//------------------------------------------------------------------------------
// Address: 0x10074090
// Name: public: virtual void CGameInstructorSaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameInstructorSaveRestoreBlockHandler::WriteSaveHeaders(
        CGameInstructorSaveRestoreBlockHandler *this,
        ISave *pSave)
{
  pSave->WriteShort_2(this: pSave, a2: &GAMEINSTRUCTOR_SAVE_RESTORE_VERSION, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100740B0
// Name: public: virtual void CGameInstructorSaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameInstructorSaveRestoreBlockHandler::ReadRestoreHeaders(
        CGameInstructorSaveRestoreBlockHandler *this,
        IRestore *pRestore)
{
  this->m_bDoLoad = pRestore->ReadShort_2(this: pRestore) == GAMEINSTRUCTOR_SAVE_RESTORE_VERSION;
}

//------------------------------------------------------------------------------
// Address: 0x100740E0
// Name: public: virtual void CGameInstructorSaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameInstructorSaveRestoreBlockHandler::Save(
        CGameInstructorSaveRestoreBlockHandler *this,
        ISave *pSave)
{
  C_GameInstructor::SaveGameBlock(this: (C_GameInstructor *)&g_GameInstructor, pSave);
}

//------------------------------------------------------------------------------
// Address: 0x100740F0
// Name: gameinstructor_dump_open_lessons
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameinstructor_dump_open_lessons()
{
  int v0; // edi
  int v1; // esi
  CBaseLesson *v2; // ecx
  Color v3; // ecx
  const char *v4; // eax
  struct Color v5; // [esp+8h] [ebp-4h] BYREF

  ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
  ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Open lessons...\n");
  v0 = dword_10605900 - 1;
  if ( dword_10605900 - 1 >= 0 )
  {
    while ( 1 )
    {
      v1 = *(_DWORD *)(dword_106058F4 + 4 * v0);
      v2 = *(CBaseLesson **)(v1 + 12);
      v5 = 0;
      if ( *(float *)(v1 + 128) > 0.0 )
        break;
      if ( !CBaseLesson::IsLearned(this: v2) || *(_DWORD *)(v1 + 68) < dword_10605924 )
      {
        v3 = CBaseLesson::m_rgbaVerboseClose;
        goto LABEL_8;
      }
      v5 = CBaseLesson::m_rgbaVerboseSuccess;
LABEL_9:
      v4 = CGameInstructorSymbol::String(this: (CGameInstructorSymbol *)(v1 + 58));
      ConColorMsg(a1: &v5, a2: "\t%s\n", v4);
      if ( --v0 < 0 )
        return;
    }
    v3 = CBaseLesson::m_rgbaVerboseOpen;
LABEL_8:
    v5 = v3;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100741A0
// Name: void GameInstructor_KeyValueBuilder(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GameInstructor_KeyValueBuilder(KeyValues *pKeyValues)
{
  C_GameInstructor::KeyValueBuilder(this: (C_GameInstructor *)&g_GameInstructor, pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x100741C0
// Name: protected: void CGameInstructorUserNotificationsListener::OnGameUsersChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameInstructorUserNotificationsListener::OnGameUsersChanged(
        CGameInstructorUserNotificationsListener *this)
{
  int i; // esi

  if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
  {
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Reset all lesson display and success counts.\n");
  }
  for ( i = 0; i < dword_106058EC; ++i )
    CBaseLesson::ResetDisplaysAndSuccesses(this: *(CBaseLesson **)(dword_106058E0 + 4 * i));
}

//------------------------------------------------------------------------------
// Address: 0x10074220
// Name: public: class CBaseLesson const __near * C_GameInstructor::GetLesson(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseLesson *__thiscall C_GameInstructor::GetLesson(C_GameInstructor *this, const char *pchLessonName)
{
  return C_GameInstructor::GetLesson_Internal(this, pchLessonName);
}

//------------------------------------------------------------------------------
// Address: 0x10074230
// Name: public: bool C_GameInstructor::ReadSaveData(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_GameInstructor::ReadSaveData(C_GameInstructor *this)
{
  C_GameInstructor *v1; // edi
  int v2; // eax
  IMatchSystem *v3; // eax
  int v4; // eax
  IMatchTitle *v5; // eax
  int v6; // eax
  CBaseLesson *v7; // esi
  const char *v8; // eax
  const TitleDataFieldsDescription_t *v9; // edi
  unsigned int v10; // eax
  const char *v11; // eax
  CBaseLesson *Lesson_Internal; // eax
  CBaseLesson *v13; // esi
  C_KeyValueSaver *v14; // eax
  CFmtStrN<256> tdKey; // [esp+4h] [ebp-11Ch] BYREF
  IPlayerLocal *pPlayer; // [esp+110h] [ebp-10h]
  const TitleDataFieldsDescription_t *fields; // [esp+114h] [ebp-Ch]
  int i; // [esp+118h] [ebp-8h]
  C_GameInstructor *v20; // [esp+11Ch] [ebp-4h]

  v1 = this;
  v20 = this;
  v2 = _CommandLine(a1: this);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-playtest") == 0
    && !v1->m_bHasLoadedSaveData )
  {
    C_GameInstructor::ResetDisplaysAndSuccesses(this: v1);
    if ( v1->m_nSplitScreenSlot == 0 )
    {
      v3 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
      v4 = v3->GetPlayerManager(this: v3);
      pPlayer = (IPlayerLocal *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v4 + 4))(
                                  a1: v4,
                                  a2: v1->m_nSplitScreenSlot);
      if ( pPlayer != nullptr )
      {
        v5 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
        fields = v5->DescribeTitleDataStorage(this: v5);
        v6 = 0;
        v1->m_bHasLoadedSaveData = true;
        for ( i = 0; v6 < v1->m_Lessons.m_Size; i = v6 )
        {
          v7 = v1->m_Lessons.m_Memory.m_pMemory[v6];
          if ( v7 != nullptr )
          {
            v8 = CGameInstructorSymbol::String(this: &v7->m_stringName);
            CFmtStrN<256>::CFmtStrN<256>(this: &tdKey, pszFormat: "GI.lesson.%s", v8);
            FixGameInstructorLessonNameForTitleData(chBuffer: tdKey.m_szBuf);
            v9 = TitleDataFieldsDescriptionFindByString(fields, szString: tdKey.m_szBuf);
            if ( v9 != nullptr )
            {
              v10 = *((unsigned __int8 *)pPlayer->GetPlayerTitleData(this: pPlayer, a2: v9->m_iTitleDataBlock)
                    + v9->m_numBytesOffset);
              v7->m_iDisplayCount = v10 & 0xF;
              v7->m_iSuccessCount = v10 >> 4;
              v11 = CGameInstructorSymbol::String(this: &v7->m_stringName);
              _V_strcmp(s1: v11, s2: "version number");
            }
            else
            {
              _Warning(a1: "C_GameInstructor::ReadSaveData failed to read %s\n", tdKey.m_szBuf);
            }
            v1 = v20;
          }
          v6 = i + 1;
        }
        Lesson_Internal = C_GameInstructor::GetLesson_Internal(this: v1, pchLessonName: "version number");
        v13 = Lesson_Internal;
        if ( Lesson_Internal != nullptr && !CBaseLesson::IsLearned(this: Lesson_Internal) )
        {
          C_GameInstructor::ResetDisplaysAndSuccesses(this: v1);
          v13->m_iSuccessCount = v13->m_iSuccessLimit;
          v14 = KeyValueSaver();
          C_KeyValueSaver::MarkKeyValuesDirty(this: v14, pchFileName: "game_instructor_counts.txt");
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100743E0
// Name: public: void C_GameInstructor::MarkDisplayed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::MarkDisplayed(C_GameInstructor *this, const char *pchLessonName)
{
  CBaseLesson *Lesson_Internal; // edi
  const char *v3; // eax
  C_KeyValueSaver *v4; // eax

  Lesson_Internal = C_GameInstructor::GetLesson_Internal(this, pchLessonName);
  if ( Lesson_Internal != nullptr )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Lesson ");
      v3 = CGameInstructorSymbol::String(this: &Lesson_Internal->m_stringName);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseOpen, a2: "\"%s\" ", v3);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "marked as displayed.\n");
    }
    if ( CBaseLesson::IncDisplayCount(this: Lesson_Internal) != 0 )
    {
      v4 = KeyValueSaver();
      C_KeyValueSaver::MarkKeyValuesDirty(this: v4, pchFileName: "game_instructor_counts.txt");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074470
// Name: public: void C_GameInstructor::MarkSucceeded(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::MarkSucceeded(C_GameInstructor *this, const char *pchLessonName)
{
  CBaseLesson *Lesson_Internal; // edi
  const char *v3; // eax
  C_KeyValueSaver *v4; // eax

  Lesson_Internal = C_GameInstructor::GetLesson_Internal(this, pchLessonName);
  if ( Lesson_Internal != nullptr )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Lesson ");
      v3 = CGameInstructorSymbol::String(this: &Lesson_Internal->m_stringName);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseSuccess, a2: "\"%s\" ", v3);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "marked as succeeded.\n");
    }
    if ( CBaseLesson::IncSuccessCount(this: Lesson_Internal) != 0 )
    {
      v4 = KeyValueSaver();
      C_KeyValueSaver::MarkKeyValuesDirty(this: v4, pchFileName: "game_instructor_counts.txt");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074500
// Name: public: class C_BasePlayer __near * C_GameInstructor::GetLocalPlayer(void)
// Source: json
//------------------------------------------------------------------------------
C_BasePlayer *__thiscall C_GameInstructor::GetLocalPlayer(C_GameInstructor *this)
{
  C_BasePlayer *LocalPlayer; // esi
  C_BaseEntity *v3; // edi

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( developer.m_pParent == nullptr
    || developer.m_pParent->m_Value.m_nValue == 0
    || LocalPlayer == nullptr
    || LocalPlayer->GetTeamNumber(this: LocalPlayer) != 1 )
  {
    return LocalPlayer;
  }
  v3 = nullptr;
  if ( LocalPlayer->GetObserverMode(this: LocalPlayer) == 4 || LocalPlayer->GetObserverMode(this: LocalPlayer) == 5 )
  {
    v3 = LocalPlayer->GetObserverTarget(this: LocalPlayer);
    if ( v3 == nullptr || !v3->IsPlayer(this: v3) )
      v3 = nullptr;
  }
  if ( CHandle<C_BaseEntity>::operator!=(this: &this->m_hLastSpectatedPlayer, val: v3) )
  {
    this->m_bSpectatedPlayerChanged = true;
    CHandle<C_ViewmodelAttachmentModel>::operator=(this: &this->m_hLastSpectatedPlayer, val: v3);
  }
  return (C_BasePlayer *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100745B0
// Name: public: void C_GameInstructor::EvaluateLessonsForGameRules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::EvaluateLessonsForGameRules(C_GameInstructor *this)
{
  int i; // eax
  CBaseLesson *v3; // edx
  SplitScreenConVarRef *v4; // ebx
  int v5; // edi
  const char *v6; // ebx
  const char *v7; // eax
  int nConVar; // [esp+4h] [ebp-8h]
  int v9; // [esp+8h] [ebp-4h]

  for ( i = 0; i < this->m_Lessons.m_Size; v3->m_bDisabled = false )
    v3 = this->m_Lessons.m_Memory.m_pMemory[i++];
  nConVar = 0;
  if ( this->m_LessonGroupConVarToggles.m_Size > 0 )
  {
    v9 = 0;
    do
    {
      v4 = (SplitScreenConVarRef *)&this->m_LessonGroupConVarToggles.m_Memory.m_pMemory[v9];
      if ( ConVarRef::IsValid(this: v4) && v4->m_Info[0].m_pConVarState->m_Value.m_nValue != 0 )
      {
        v5 = 0;
        if ( this->m_Lessons.m_Size > 0 )
        {
          v6 = (const char *)&v4->m_Info[1];
          do
          {
            v7 = CGameInstructorSymbol::String(this: &this->m_Lessons.m_Memory.m_pMemory[v5]->m_szLessonGroup);
            if ( _V_stricmp(s1: v6, s2: v7) == 0 )
              this->m_Lessons.m_Memory.m_pMemory[v5]->m_bDisabled = true;
            ++v5;
          }
          while ( v5 < this->m_Lessons.m_Size );
        }
      }
      ++v9;
      ++nConVar;
    }
    while ( nConVar < this->m_LessonGroupConVarToggles.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074670
// Name: public: virtual C_GameInstructor::~C_GameInstructor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::~C_GameInstructor(C_GameInstructor *this)
{
  bool v2; // zf

  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LessonGroupConVarToggles);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_OpenOpportunities);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Lessons);
  v2 = !this->m_bRegisteredForEvents;
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( !v2 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->CGameEventListener);
    this->m_bRegisteredForEvents = false;
  }
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x100746D0
// Name: private: void C_GameInstructor::CloseOpportunity(class CBaseLesson __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::CloseOpportunity(C_GameInstructor *this, CBaseLesson *pLesson)
{
  CBaseLesson *v2; // esi
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax

  v2 = pLesson;
  C_GameInstructor::UpdateInactiveLesson(this, pLesson);
  if ( v2->WasDisplayed(this: v2) )
  {
    v4 = CGameInstructorSymbol::String(this: &v2->m_stringName);
    C_GameInstructor::MarkDisplayed(this, pchLessonName: v4);
  }
  if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
  {
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Opportunity ");
    v5 = CGameInstructorSymbol::String(this: &v2->m_stringName);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\" ", v5);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "closed for reason: ");
    v6 = CGameInstructorSymbol::String(this: &v2->m_stringCloseReason);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "%s\n", v6);
  }
  if ( v2->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_OpenOpportunities,
    src: (vgui::TreeNode **)&pLesson);
  ((void (__thiscall *)(CBaseLesson *, int))v2->dtr_IGameEventListener2)(a1: v2, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100747E0
// Name: public: virtual void CGameInstructorUserNotificationsListener::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameInstructorUserNotificationsListener::OnEvent(
        CGameInstructorUserNotificationsListener *this,
        KeyValues *pEvent)
{
  const char *Name; // esi

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: Name, s2: "OnProfileDataLoaded") != 0 )
  {
    if ( _V_stricmp(s1: Name, s2: "OnProfilesChanged") == 0 )
      CGameInstructorUserNotificationsListener::OnGameUsersChanged(this);
  }
  else
  {
    KeyValues::GetInt(this: pEvent, keyName: "iController", defaultValue: 0);
    byte_106059B8 = 0;
    C_GameInstructor::ReadSaveData(this: (C_GameInstructor *)&g_GameInstructor);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074850
// Name: public: void C_GameInstructor::DefineLesson(class CBaseLesson __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::DefineLesson(C_GameInstructor *this, CBaseLesson *pLesson)
{
  const char *v3; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Lessons; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
  {
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Lesson ");
    v3 = CGameInstructorSymbol::String(this: &pLesson->m_stringName);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\" ", v3);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "defined.\n");
  }
  m_nAllocationCount = this->m_Lessons.m_Memory.m_nAllocationCount;
  p_m_Lessons = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Lessons;
  m_Size = this->m_Lessons.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Lessons, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Lessons[1].m_pMemory;
  m_pMemory = p_m_Lessons->m_pMemory;
  v8 = (int)p_m_Lessons[1].m_pMemory - m_Size - 1;
  p_m_Lessons[1].m_nAllocationCount = (int)p_m_Lessons->m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &p_m_Lessons->m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (vgui::TreeNode *)pLesson;
}

//------------------------------------------------------------------------------
// Address: 0x10074910
// Name: public: bool C_GameInstructor::OpenOpportunity(class CBaseLesson __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_GameInstructor::OpenOpportunity(C_GameInstructor *this, CBaseLesson *pLesson)
{
  CBaseLesson *v2; // edi
  CBaseLesson *m_pRoot; // ebx
  const char *v4; // eax
  C_BasePlayer *LocalPlayer; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  int v9; // eax
  CBaseLesson *v10; // edi
  const char *v11; // eax
  const char *v13; // eax
  const char *v14; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBaseLesson **m_pMemory; // ecx
  int v18; // eax
  CBaseLesson **v19; // edi
  CBaseLesson *pLastReplacableLesson; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  int iInstanceCount; // [esp+18h] [ebp-4h]

  v2 = pLesson;
  m_pRoot = pLesson->m_pRoot;
  if ( m_pRoot == nullptr )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Opportunity ");
      v4 = CGameInstructorSymbol::String(this: &pLesson->m_stringName);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\" ", v4);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "NOT opened (because root lesson could not be found).\n");
    }
LABEL_40:
    ((void (__thiscall *)(CBaseLesson *, int))v2->dtr_IGameEventListener2)(a1: v2, a2: 1);
    return 0;
  }
  LocalPlayer = C_GameInstructor::GetLocalPlayer(this);
  if ( !m_pRoot->m_bCanOpenWhenDead && (LocalPlayer == nullptr || !LocalPlayer->IsAlive(this: LocalPlayer)) )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Opportunity ");
      v6 = CGameInstructorSymbol::String(this: &pLesson->m_stringName);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\" ", v6);
      ConColorMsg(
        a1: &CBaseLesson::m_rgbaVerbosePlain,
        a2: "NOT opened (because player is dead and can_open_when_dead not set).\n");
    }
    goto LABEL_40;
  }
  if ( m_pRoot->m_bOnceLearnedNeverOpen && CBaseLesson::IsLearned(this: m_pRoot) )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Opportunity ");
      v7 = CGameInstructorSymbol::String(this: &pLesson->m_stringName);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\" ", v7);
      ConColorMsg(
        a1: &CBaseLesson::m_rgbaVerbosePlain,
        a2: "NOT opened (because this is learned and ONCE_LEARNED_NEVER_OPEN is set).\n");
    }
    goto LABEL_40;
  }
  if ( CBaseLesson::PrerequisitesHaveBeenMet(this: m_pRoot) == 0 )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Opportunity ");
      v8 = CGameInstructorSymbol::String(this: &pLesson->m_stringName);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\" ", v8);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "NOT opened (because prereqs haven't been met).\n");
    }
    goto LABEL_40;
  }
  if ( m_pRoot->m_iInstanceType == LESSON_INSTANCE_FIXED_REPLACE )
  {
    pLastReplacableLesson = nullptr;
    iInstanceCount = 0;
    v9 = this->m_OpenOpportunities.m_Size - 1;
    i = v9;
    if ( v9 < 0 )
    {
LABEL_36:
      if ( iInstanceCount >= m_pRoot->m_iFixedInstancesMax )
      {
        if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
        {
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Opportunity ");
          v11 = CGameInstructorSymbol::String(this: &v2->m_stringName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\" ", v11);
          ConColorMsg(
            a1: &CBaseLesson::m_rgbaVerbosePlain,
            a2: "NOT opened (there is too many started lessons of this type).\n");
        }
        goto LABEL_40;
      }
    }
    else
    {
      while ( 1 )
      {
        v10 = this->m_OpenOpportunities.m_Memory.m_pMemory[v9];
        if ( CGameInstructorSymbol::operator==(this: &v10->m_stringName, src: &pLesson->m_stringName)
          && CGameInstructorSymbol::operator==(this: &v10->m_stringReplaceKey, src: &pLesson->m_stringReplaceKey) )
        {
          ++iInstanceCount;
          if ( !m_pRoot->m_bReplaceOnlyWhenStopped || v10->m_fStartTime <= 0.0 )
            pLastReplacableLesson = v10;
          if ( iInstanceCount >= m_pRoot->m_iFixedInstancesMax )
            break;
        }
        if ( --i < 0 )
          goto LABEL_35;
        v9 = i;
      }
      if ( pLastReplacableLesson == nullptr )
      {
LABEL_35:
        v2 = pLesson;
        goto LABEL_36;
      }
      if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Opportunity ");
        v13 = CGameInstructorSymbol::String(this: &pLesson->m_stringName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseOpen, a2: "\"%s\" ", v13);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "replacing open lesson of same type.\n");
      }
      pLesson->TakePlaceOf(this: pLesson, a2: pLastReplacableLesson);
      C_GameInstructor::CloseOpportunity(this, pLesson: pLastReplacableLesson);
      v2 = pLesson;
    }
  }
  if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
  {
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Opportunity ");
    v14 = CGameInstructorSymbol::String(this: &v2->m_stringName);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseOpen, a2: "\"%s\" ", v14);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "opened.\n");
  }
  m_Size = this->m_OpenOpportunities.m_Size;
  m_nAllocationCount = this->m_OpenOpportunities.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_OpenOpportunities,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_OpenOpportunities.m_Size;
  m_pMemory = this->m_OpenOpportunities.m_Memory.m_pMemory;
  v18 = this->m_OpenOpportunities.m_Size - m_Size - 1;
  this->m_OpenOpportunities.m_pElements = m_pMemory;
  if ( v18 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v18);
  v19 = &this->m_OpenOpportunities.m_Memory.m_pMemory[m_Size];
  if ( v19 != nullptr )
    *v19 = pLesson;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10074D30
// Name: private: void C_GameInstructor::CloseAllOpenOpportunities(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_GameInstructor::CloseAllOpenOpportunities(C_GameInstructor *this@<ecx>, int a2@<edi>)
{
  int v3; // eax
  CBaseLesson *v4; // esi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  int m_Size; // ecx
  int v9; // eax
  CBaseLesson **m_pMemory; // edx
  int v11; // ecx
  int i; // [esp+4h] [ebp-4h]

  v3 = this->m_OpenOpportunities.m_Size - 1;
  i = v3;
  if ( v3 >= 0 )
  {
    while ( 1 )
    {
      v4 = this->m_OpenOpportunities.m_Memory.m_pMemory[v3];
      C_GameInstructor::UpdateInactiveLesson(this, pLesson: v4);
      if ( ((unsigned __int8 (__thiscall *)(CBaseLesson *, int))v4->WasDisplayed)(a1: v4, a2) != 0 )
      {
        v5 = CGameInstructorSymbol::String(this: &v4->m_stringName);
        C_GameInstructor::MarkDisplayed(this, pchLessonName: v5);
      }
      if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Opportunity ");
        v6 = CGameInstructorSymbol::String(this: &v4->m_stringName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\" ", v6);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "closed for reason: ");
        v7 = CGameInstructorSymbol::String(this: &v4->m_stringCloseReason);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "%s\n", v7);
      }
      if ( v4->m_bRegisteredForEvents )
      {
        if ( gameeventmanager != nullptr )
          gameeventmanager->RemoveListener(this: gameeventmanager, a2: v4);
        v4->m_bRegisteredForEvents = false;
      }
      m_Size = this->m_OpenOpportunities.m_Size;
      v9 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = this->m_OpenOpportunities.m_Memory.m_pMemory;
        while ( *m_pMemory != v4 )
        {
          ++v9;
          ++m_pMemory;
          if ( v9 >= m_Size )
            goto LABEL_22;
        }
        if ( v9 != -1 )
        {
          v11 = m_Size - v9 - 1;
          if ( v11 > 0 )
            _V_memmove(
              dest: &this->m_OpenOpportunities.m_Memory.m_pMemory[v9],
              src: &this->m_OpenOpportunities.m_Memory.m_pMemory[v9 + 1],
              count: 4 * v11);
          --this->m_OpenOpportunities.m_Size;
        }
      }
LABEL_22:
      a2 = 1;
      v4->dtr_IGameEventListener2(this: v4);
      if ( --i < 0 )
        break;
      v3 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074E60
// Name: public: virtual void C_GameInstructor::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_GameInstructor::Shutdown(
        C_GameInstructor *this@<ecx>,
        void (*a2)(const struct Color *, const char *, ...)@<edi>)
{
  C_KeyValueSaver *v3; // eax
  int i; // edi
  CBaseLesson **m_pMemory; // eax
  bool v6; // zf
  CBaseLesson **v7; // eax
  CBaseLesson *v8; // ebx
  CBaseLesson *v9; // ecx
  CGameEventListener *v10; // esi

  if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
  {
    a2 = ConColorMsg;
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Shutting down...\n");
  }
  C_GameInstructor::CloseAllOpenOpportunities(this, (int)a2);
  if ( !engine->IsPlayingDemo(this: engine) )
  {
    v3 = KeyValueSaver();
    C_KeyValueSaver::WriteDirtyKeyValues(this: v3, pchFileName: "game_instructor_counts.txt", bForceWrite: false);
  }
  for ( i = 0; i < this->m_Lessons.m_Size; ++i )
  {
    m_pMemory = this->m_Lessons.m_Memory.m_pMemory;
    v6 = m_pMemory[i] == nullptr;
    v7 = &m_pMemory[i];
    if ( !v6 )
    {
      v8 = *v7;
      if ( (*v7)->m_bRegisteredForEvents )
      {
        if ( gameeventmanager != nullptr )
          gameeventmanager->RemoveListener(this: gameeventmanager, a2: v8);
        v8->m_bRegisteredForEvents = false;
      }
      v9 = this->m_Lessons.m_Memory.m_pMemory[i];
      if ( v9 != nullptr )
        ((void (__thiscall *)(CBaseLesson *, int))v9->dtr_IGameEventListener2)(a1: v9, a2: 1);
      this->m_Lessons.m_Memory.m_pMemory[i] = nullptr;
    }
  }
  this->m_Lessons.m_Size = 0;
  this->m_LessonGroupConVarToggles.m_Size = 0;
  v10 = &this->CGameEventListener;
  if ( v10->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v10);
    v10->m_bRegisteredForEvents = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074F50
// Name: public: virtual void C_GameInstructor::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_GameInstructor::Update(C_GameInstructor *this@<ecx>, int a2@<edi>, float frametime)
{
  bool v4; // al
  int j; // ecx
  CBaseLesson *m_pRoot; // eax
  int v7; // edi
  int v8; // eax
  CBaseLesson **m_pMemory; // ecx
  CBaseLesson *v10; // esi
  CBaseLesson *v11; // edi
  bool IsLocked; // al
  int i; // [esp+4h] [ebp-Ch]
  int iCurrentPriority; // [esp+8h] [ebp-8h]
  bool bIsLocked; // [esp+Eh] [ebp-2h]
  bool bShouldDisplay; // [esp+Fh] [ebp-1h]
  bool bShouldDisplaya; // [esp+Fh] [ebp-1h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_GameInstructor::Update",
    a3: 0,
    a4: "GameInstructor",
    a5: false,
    a6: 4);
  v4 = IsPresetCurrentCostDebuggingEnabled((vgui::ToggleButton *)this);
  bShouldDisplay = v4;
  if ( v4 && !this->m_bHiddenDueToOtherElements )
  {
    C_GameInstructor::StopAllLessons(this);
    v4 = bShouldDisplay;
  }
  this->m_bHiddenDueToOtherElements = v4;
  if ( gameinstructor_enable.m_pParent == nullptr
    || gameinstructor_enable.m_pParent->m_Value.m_nValue == 0
    || this->m_bNoDraw
    || v4 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    if ( gameinstructor_find_errors.m_pParent != nullptr && gameinstructor_find_errors.m_pParent->m_Value.m_nValue != 0 )
    {
      C_GameInstructor::FindErrors(this);
      ConVar::SetValue(this: (ConVar *)&gameinstructor_find_errors.IConVar, value: 0);
    }
    if ( this->m_bSpectatedPlayerChanged )
    {
      if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Spectated player changed...\n");
      }
      C_GameInstructor::CloseAllOpenOpportunities(this, a2);
      this->m_bSpectatedPlayerChanged = false;
    }
    for ( j = this->m_OpenOpportunities.m_Size - 1; j >= 0; --j )
    {
      m_pRoot = this->m_OpenOpportunities.m_Memory.m_pMemory[j]->m_pRoot;
      if ( m_pRoot->m_iInstanceType == LESSON_INSTANCE_SINGLE_ACTIVE )
        *((_BYTE *)m_pRoot + 60) &= ~1u;
    }
    v7 = 0;
    v8 = this->m_OpenOpportunities.m_Size - 1;
    iCurrentPriority = 0;
    i = v8;
    if ( v8 >= 0 )
    {
      do
      {
        m_pMemory = this->m_OpenOpportunities.m_Memory.m_pMemory;
        v10 = m_pMemory[v8];
        if ( (*((_BYTE *)v10 + 60) & 8) == 0 || CBaseLesson::IsTimedOut(this: m_pMemory[v8]) != 0 )
        {
          C_GameInstructor::CloseOpportunity(this, pLesson: v10);
        }
        else
        {
          v11 = v10->m_pRoot;
          bShouldDisplaya = v10->ShouldDisplay(this: v10);
          IsLocked = CBaseLesson::IsLocked(this: v10);
          bIsLocked = IsLocked;
          if ( (bShouldDisplaya || IsLocked)
            && (v10->m_iPriority >= this->m_iCurrentPriority || CBaseLesson::NoPriority(this: v10) || bIsLocked)
            && v11 != nullptr
            && (v11->m_iInstanceType != LESSON_INSTANCE_SINGLE_ACTIVE || (*((_BYTE *)v11 + 60) & 1) == 0) )
          {
            if ( (C_GameInstructor::UpdateActiveLesson(this, pLesson: v10, pRootLesson: v11) != 0
               || CBaseLesson::IsLearned(this: v11))
              && (v10->IsVisible(this: v10) || CBaseLesson::IsLearned(this: v11)) )
            {
              *((_BYTE *)v11 + 60) |= 1u;
              if ( iCurrentPriority < v10->m_iPriority && !CBaseLesson::NoPriority(this: v10) )
                iCurrentPriority = v10->m_iPriority;
            }
          }
          else
          {
            C_GameInstructor::UpdateInactiveLesson(this, pLesson: v10);
          }
        }
        v8 = --i;
      }
      while ( i >= 0 );
      v7 = iCurrentPriority;
    }
    if ( gameinstructor_verbose.m_pParent != nullptr
      && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 1
      && this->m_iCurrentPriority != v7 )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Priority changed from ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "%i ", this->m_iCurrentPriority);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "to ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseOpen, a2: "%i", v7);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ".\n");
    }
    this->m_iCurrentPriority = v7;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100751D0
// Name: public: virtual void C_GameInstructor::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::FireGameEvent(C_GameInstructor *this, int event)
{
  int v3; // esi
  const char *v4; // ebx
  C_BasePlayer *LocalPlayer; // ebx
  int v6; // eax
  int i; // esi
  C_GameInstructor *v8; // ebx
  C_BasePlayer *v9; // edi
  int v10; // eax
  int v11; // edi
  C_GameInstructor *v12; // ebx
  C_BasePlayer *v13; // edi
  int v14; // eax
  const char *v15; // ebx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_GameInstructor::FireGameEvent",
    a3: 0,
    a4: "GameInstructor",
    a5: false,
    a6: 4);
  v3 = event;
  v4 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)event + 4))(a1: event);
  if ( _V_strcmp(s1: v4, s2: "gameinstructor_draw") == 0 )
  {
    if ( LOBYTE(this->m_LessonGroupConVarToggles.m_Size) != 0 )
    {
      if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Set to draw...\n");
        LOBYTE(this->m_LessonGroupConVarToggles.m_Size) = 0;
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return;
      }
      goto LABEL_66;
    }
    goto LABEL_71;
  }
  if ( _V_strcmp(s1: v4, s2: "gameinstructor_nodraw") == 0 )
  {
    if ( LOBYTE(this->m_LessonGroupConVarToggles.m_Size) == 0 )
    {
      if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Set to not draw...\n");
      }
      LOBYTE(this->m_LessonGroupConVarToggles.m_Size) = 1;
      C_GameInstructor::StopAllLessons(this: (C_GameInstructor *)((char *)this - 12));
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return;
    }
LABEL_71:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  if ( _V_strcmp(s1: v4, s2: "round_end") != 0 )
  {
    if ( _V_strcmp(s1: v4, s2: "round_start") != 0 )
    {
      if ( _V_strcmp(s1: v4, s2: "player_death") == 0 )
      {
        LocalPlayer = C_GameInstructor::GetLocalPlayer(this: (C_GameInstructor *)((char *)this - 12));
        if ( LocalPlayer != nullptr )
        {
          v6 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 24))(a1: v3, a2: "userid", a3: 0);
          if ( LocalPlayer == UTIL_PlayerByUserId(userID: v6) )
          {
            if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
            {
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Local player died...\n");
            }
            for ( i = (int)this->m_OpenOpportunities.m_Memory.m_pMemory - 1; i >= 0; --i )
            {
              if ( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this->m_Lessons.m_Memory.m_nGrowSize + 4 * i) + 12) + 146) == 0 )
                C_GameInstructor::CloseOpportunity(
                  this: (C_GameInstructor *)((char *)this - 12),
                  pLesson: *(CBaseLesson **)(this->m_Lessons.m_Memory.m_nGrowSize + 4 * i));
            }
          }
        }
        goto LABEL_71;
      }
      if ( _V_strcmp(s1: v4, s2: "player_team") != 0 )
      {
        if ( _V_strcmp(s1: v4, s2: "player_disconnect") != 0 )
        {
          if ( _V_strcmp(s1: v4, s2: "map_transition") != 0 )
          {
            if ( _V_strcmp(s1: v4, s2: "game_newmap") != 0 )
            {
              if ( _V_strcmp(s1: v4, s2: "set_instructor_group_enabled") == 0 )
              {
                v15 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v3 + 36))(
                                      a1: v3,
                                      a2: "group",
                                      a3: prType);
                LOBYTE(event) = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 24))(
                                  a1: v3,
                                  a2: "enabled",
                                  a3: 0) != 0;
                if ( v15 != nullptr && *v15 != 0 )
                  C_GameInstructor::SetLessonGroupEnabled(
                    this: (C_GameInstructor *)((char *)this - 12),
                    pszGroup: v15,
                    bEnabled: event);
              }
            }
            else
            {
              if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
              {
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "New map...\n");
              }
              C_GameInstructor::CloseAllOpenOpportunities(this: (C_GameInstructor *)((char *)this - 12), a2: (int)this);
              if ( LOBYTE(this->m_LessonGroupConVarToggles.m_Size) != 0 )
              {
                if ( gameinstructor_verbose.m_pParent != nullptr
                  && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
                {
                  event = -12549889;
                  ConColorMsg(a1: (const struct Color *)&event, a2: "GAME INSTRUCTOR: ");
                  event = -32704;
                  ConColorMsg(a1: (const struct Color *)&event, a2: "Set to draw...\n");
                }
LABEL_66:
                LOBYTE(this->m_LessonGroupConVarToggles.m_Size) = 0;
                CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
                return;
              }
            }
          }
          else
          {
            if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
            {
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Map transition...\n");
            }
            C_GameInstructor::CloseAllOpenOpportunities(this: (C_GameInstructor *)((char *)this - 12), a2: (int)this);
            if ( LOBYTE(this->m_LessonGroupConVarToggles.m_Size) != 0 )
            {
              if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
              {
                event = -12549889;
                ConColorMsg(a1: (const struct Color *)&event, a2: "GAME INSTRUCTOR: ");
                event = -32704;
                ConColorMsg(a1: (const struct Color *)&event, a2: "Set to draw...\n");
                LOBYTE(this->m_LessonGroupConVarToggles.m_Size) = 0;
                CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
                return;
              }
              goto LABEL_66;
            }
          }
          goto LABEL_71;
        }
        v12 = (C_GameInstructor *)((char *)this - 12);
        v13 = C_GameInstructor::GetLocalPlayer(this: (C_GameInstructor *)((char *)this - 12));
        if ( v13 == nullptr )
          goto LABEL_71;
        v14 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 24))(a1: v3, a2: "userid", a3: 0);
        if ( v13 != UTIL_PlayerByUserId(userID: v14) )
          goto LABEL_71;
        if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
        {
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Local player disconnected...\n");
        }
        C_GameInstructor::CloseAllOpenOpportunities(this: v12, a2: (int)v13);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
      else
      {
        v8 = (C_GameInstructor *)((char *)this - 12);
        v9 = C_GameInstructor::GetLocalPlayer(this: (C_GameInstructor *)((char *)this - 12));
        if ( v9 != nullptr )
        {
          v10 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 24))(a1: v3, a2: "userid", a3: 0);
          if ( v9 == UTIL_PlayerByUserId(userID: v10) )
          {
            v11 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 24))(a1: v3, a2: "oldteam", a3: 0);
            if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 24))(a1: v3, a2: "team", a3: 0) != v11
              || (*(unsigned __int8 (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 20))(
                   a1: v3,
                   a2: "disconnect",
                   a3: 0) != 0 )
            {
              if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
              {
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
                ConColorMsg(
                  a1: &CBaseLesson::m_rgbaVerbosePlain,
                  a2: "Local player changed team (or disconnected)...\n");
              }
              C_GameInstructor::CloseAllOpenOpportunities(this: v8, a2: v11);
            }
          }
        }
        C_GameInstructor::EvaluateLessonsForGameRules(this: v8);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
    }
    else
    {
      if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Round started...\n");
      }
      C_GameInstructor::CloseAllOpenOpportunities(this: (C_GameInstructor *)((char *)this - 12), a2: (int)this);
      C_GameInstructor::EvaluateLessonsForGameRules(this: (C_GameInstructor *)((char *)this - 12));
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
  }
  else
  {
    if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Round ended...\n");
    }
    C_GameInstructor::CloseAllOpenOpportunities(this: (C_GameInstructor *)((char *)this - 12), a2: (int)this);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075770
// Name: public: void C_GameInstructor::RestoreGameBlock(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_GameInstructor::RestoreGameBlock(
        C_GameInstructor *this@<ecx>,
        int a2@<edi>,
        IRestore *pRestore,
        bool fCreatePlayers)
{
  int v6; // eax
  CScriptedIconLesson *v7; // eax
  CScriptedIconLesson *v8; // edi
  const char *v9; // eax
  CBaseLesson *Lesson_Internal; // eax
  CScriptedIconLesson *v11; // eax
  CScriptedIconLesson *v12; // edi
  int v13; // eax
  int i; // ebx
  IRestore *pRestorea; // [esp+10h] [ebp+8h]

  if ( pRestore->GetGameSaveRestoreInfo(this: pRestore)->levelInfo.fUseLandmark == 0 )
  {
    C_GameInstructor::CloseAllOpenOpportunities(this, a2);
    if ( gameinstructor_save_restore_lessons.m_pParent != nullptr
      && gameinstructor_save_restore_lessons.m_pParent->m_Value.m_nValue != 0 )
    {
      v6 = pRestore->ReadInt(this: pRestore);
      if ( v6 > 0 )
      {
        for ( pRestorea = (IRestore *)v6; pRestorea != nullptr; pRestorea = (IRestore *)((char *)pRestorea - 1) )
        {
          v7 = (CScriptedIconLesson *)MemAlloc_Alloc(nSize: 0x1D0u);
          if ( v7 != nullptr )
            v8 = CScriptedIconLesson::CScriptedIconLesson(
                   this: v7,
                   pchName: prType,
                   bIsDefaultHolder: false,
                   bIsOpenOpportunity: true,
                   nSplitScreenSlot: this->m_nSplitScreenSlot);
          else
            v8 = nullptr;
          pRestore->StartBlock(this: pRestore);
          pRestore->ReadAll(this: pRestore, a2: v8, a3: &CScriptedIconLesson::m_DataMap);
          pRestore->EndBlock(this: pRestore);
          v9 = CGameInstructorSymbol::String(this: &v8->m_stringName);
          Lesson_Internal = C_GameInstructor::GetLesson_Internal(this, pchLessonName: v9);
          CBaseLesson::SetRoot(this: v8, pRoot: Lesson_Internal);
          C_GameInstructor::OpenOpportunity(this: (C_GameInstructor *)&g_GameInstructor, pLesson: v8);
        }
      }
    }
    else
    {
      v11 = (CScriptedIconLesson *)MemAlloc_Alloc(nSize: 0x1D0u);
      if ( v11 != nullptr )
        v12 = CScriptedIconLesson::CScriptedIconLesson(
                this: v11,
                pchName: prType,
                bIsDefaultHolder: false,
                bIsOpenOpportunity: true,
                nSplitScreenSlot: this->m_nSplitScreenSlot);
      else
        v12 = nullptr;
      v13 = pRestore->ReadInt(this: pRestore);
      if ( v13 > 0 )
      {
        for ( i = v13; i != 0; --i )
        {
          pRestore->StartBlock(this: pRestore);
          pRestore->ReadAll(this: pRestore, a2: v12, a3: &CScriptedIconLesson::m_DataMap);
          pRestore->EndBlock(this: pRestore);
        }
      }
      if ( v12 != nullptr )
        ((void (__thiscall *)(CScriptedIconLesson *, int))v12->dtr_IGameEventListener2)(a1: v12, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100758C0
// Name: private: void C_GameInstructor::ReadLessonsFromFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameInstructor::ReadLessonsFromFile(C_GameInstructor *this, const char *pchFileName)
{
  C_GameInstructor *v2; // esi
  KeyValues *v3; // eax
  IBaseFileSystem *v4; // eax
  KeyValues *v5; // edi
  KeyValues *FirstTrueSubKey; // eax
  const char *Name; // eax
  int v8; // eax
  KeyValues *m_pScriptKeys; // ecx
  const char *String; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlVector<LessonGroupConVarToggle_t,CUtlMemory<LessonGroupConVarToggle_t,int> > *p_m_LessonGroupConVarToggles; // ebx
  LessonGroupConVarToggle_t *m_pMemory; // ecx
  int v15; // eax
  int v16; // eax
  LessonGroupConVarToggle_t *v17; // edi
  int v18; // ebx
  const char *v19; // eax
  int v20; // edi
  CGameInstructorSymbol *v21; // ebx
  const char *v22; // eax
  CScriptedIconLesson *v23; // edi
  const char *v24; // eax
  CScriptedIconLesson *v25; // eax
  const char *v26; // eax
  KeyValues *NextTrueSubKey; // eax
  int m_nSplitScreenSlot; // [esp-8h] [ebp-60h]
  ConVarRef v29[9]; // [esp+8h] [ebp-50h] BYREF
  C_GameInstructor *v30; // [esp+50h] [ebp-8h]
  KeyValues *pLessonKeys; // [esp+54h] [ebp-4h]
  const char *pchFileNamea; // [esp+60h] [ebp+8h]

  v2 = this;
  v30 = this;
  CScriptedIconLesson::PreReadLessonsFromFile(this);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    pLessonKeys = KeyValues::KeyValues(this: v3, setName: "instructor_lessons");
  else
    pLessonKeys = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  v5 = pLessonKeys;
  KeyValues::LoadFromFile(
    this: pLessonKeys,
    filesystem: v4,
    resourceName: pchFileName,
    pathID: nullptr,
    pfnEvaluateSymbolProc: nullptr);
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pLessonKeys);
  v2->m_pScriptKeys = FirstTrueSubKey;
  if ( FirstTrueSubKey != nullptr )
  {
    do
    {
      Name = KeyValues::GetName(this: v2->m_pScriptKeys);
      v8 = _V_stricmp(s1: Name, s2: "GroupConVarToggle");
      m_pScriptKeys = v2->m_pScriptKeys;
      if ( v8 != 0 )
      {
        v20 = 0;
        pchFileNamea = KeyValues::GetName(this: m_pScriptKeys);
        if ( v2->m_Lessons.m_Size <= 0 )
          goto LABEL_19;
        while ( 1 )
        {
          v21 = (CGameInstructorSymbol *)v2->m_Lessons.m_Memory.m_pMemory[v20];
          v22 = CGameInstructorSymbol::String(this: v21 + 29);
          if ( _V_strcmp(s1: v22, s2: pchFileNamea) == 0 )
            break;
          if ( ++v20 >= v2->m_Lessons.m_Size )
            goto LABEL_19;
        }
        if ( v21 != nullptr )
        {
          v26 = KeyValues::GetName(this: v2->m_pScriptKeys);
          DevWarning(a1: "Lesson \"%s\" defined twice!\n", v26);
        }
        else
        {
LABEL_19:
          v23 = (CScriptedIconLesson *)MemAlloc_Alloc(nSize: 0x1D0u);
          if ( v23 != nullptr )
          {
            m_nSplitScreenSlot = v2->m_nSplitScreenSlot;
            v24 = KeyValues::GetName(this: v2->m_pScriptKeys);
            v25 = CScriptedIconLesson::CScriptedIconLesson(
                    this: v23,
                    pchName: v24,
                    bIsDefaultHolder: false,
                    bIsOpenOpportunity: false,
                    nSplitScreenSlot: m_nSplitScreenSlot);
          }
          else
          {
            v25 = nullptr;
          }
          C_GameInstructor::DefineLesson(this: (C_GameInstructor *)&g_GameInstructor, pLesson: v25);
        }
      }
      else
      {
        String = KeyValues::GetString(this: m_pScriptKeys, keyName: "convar", defaultValue: prType);
        ConVarRef::ConVarRef(this: v29, pName: String);
        m_Size = v2->m_LessonGroupConVarToggles.m_Size;
        m_nAllocationCount = v2->m_LessonGroupConVarToggles.m_Memory.m_nAllocationCount;
        p_m_LessonGroupConVarToggles = &v2->m_LessonGroupConVarToggles;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<LessonGroupConVarToggle_t,int>::Grow(
            this: &v2->m_LessonGroupConVarToggles.m_Memory,
            num: m_Size - m_nAllocationCount + 1);
        ++v2->m_LessonGroupConVarToggles.m_Size;
        m_pMemory = p_m_LessonGroupConVarToggles->m_Memory.m_pMemory;
        v15 = v2->m_LessonGroupConVarToggles.m_Size - m_Size - 1;
        v2->m_LessonGroupConVarToggles.m_pElements = v2->m_LessonGroupConVarToggles.m_Memory.m_pMemory;
        if ( v15 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 72 * v15);
        v16 = m_Size;
        v17 = &p_m_LessonGroupConVarToggles->m_Memory.m_pMemory[m_Size];
        if ( v17 != nullptr )
        {
          qmemcpy(v17, v29, sizeof(LessonGroupConVarToggle_t));
          v2 = v30;
        }
        v18 = (int)&p_m_LessonGroupConVarToggles->m_Memory.m_pMemory[v16];
        v19 = KeyValues::GetString(this: v2->m_pScriptKeys, keyName: "group", defaultValue: prType);
        _V_strcpy(dest: (char *)(v18 + 8), src: v19);
      }
      NextTrueSubKey = KeyValues::GetNextTrueSubKey(this: v2->m_pScriptKeys);
      v2->m_pScriptKeys = NextTrueSubKey;
    }
    while ( NextTrueSubKey != nullptr );
    v5 = pLessonKeys;
  }
  v2->m_pScriptKeys = nullptr;
  if ( v5 != nullptr )
    KeyValues::deleteThis(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10075AC0
// Name: public: virtual void CGameInstructorSaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameInstructorSaveRestoreBlockHandler::Restore(
        CGameInstructorSaveRestoreBlockHandler *this@<ecx>,
        int a2@<edi>,
        IRestore *pRestore,
        bool fCreatePlayers)
{
  if ( this->m_bDoLoad )
    C_GameInstructor::RestoreGameBlock(this: (C_GameInstructor *)&g_GameInstructor, a2, pRestore, fCreatePlayers);
}

//------------------------------------------------------------------------------
// Address: 0x10075AE0
// Name: public: virtual bool C_GameInstructor::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_GameInstructor::Init(C_GameInstructor *this)
{
  int v1; // eax
  int v3; // esi
  CBaseLesson *v4; // ecx
  C_KeyValueSaver *v5; // eax

  v1 = 0;
  while ( this != &g_GameInstructor )
  {
    if ( ++v1 >= 1 )
      goto LABEL_6;
  }
  this->m_nSplitScreenSlot = v1;
LABEL_6:
  if ( gameinstructor_enable.m_pParent != nullptr
    && gameinstructor_enable.m_pParent->m_Value.m_nValue != 0
    && (sv_gameinstructor_disable.m_pParent == nullptr || sv_gameinstructor_disable.m_pParent->m_Value.m_nValue == 0) )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Initializing...\n");
    }
    v3 = 0;
    *(_WORD *)&this->m_bNoDraw = 0;
    this->m_iCurrentPriority = 0;
    this->m_hLastSpectatedPlayer.m_Index = -1;
    *(_WORD *)&this->m_bSpectatedPlayerChanged = 0;
    this->m_fNextStartSoundTime = 0.0;
    C_GameInstructor::ReadLessonsFromFile(this, pchFileName: "scripts/mod_lessons.txt");
    C_GameInstructor::ReadLessonsFromFile(this, pchFileName: "scripts/instructor_lessons.txt");
    if ( this->m_Lessons.m_Size > 0 )
    {
      do
      {
        v4 = this->m_Lessons.m_Memory.m_pMemory[v3];
        v4->InitPrerequisites(this: v4);
        ++v3;
      }
      while ( v3 < this->m_Lessons.m_Size );
    }
    v5 = KeyValueSaver();
    C_KeyValueSaver::InitKeyValues(
      this: v5,
      pchFileName: "game_instructor_counts.txt",
      funcKeyValueBuilder: GameInstructor_KeyValueBuilder);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(
      this: gameeventmanager,
      a2: &this->CGameEventListener,
      a3: "gameinstructor_draw",
      a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(
      this: gameeventmanager,
      a2: &this->CGameEventListener,
      a3: "gameinstructor_nodraw",
      a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "round_end", a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "round_start", a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_death", a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_team", a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(
      this: gameeventmanager,
      a2: &this->CGameEventListener,
      a3: "player_disconnect",
      a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(
      this: gameeventmanager,
      a2: &this->CGameEventListener,
      a3: "map_transition",
      a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "game_newmap", a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(
      this: gameeventmanager,
      a2: &this->CGameEventListener,
      a3: "set_instructor_group_enabled",
      a4: false);
    C_GameInstructor::EvaluateLessonsForGameRules(this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10412470
// Name: GameinstructorIconsPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *GameinstructorIconsPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  GameinstructorIconsPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &GameinstructorIconsPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412530
// Name: _dynamic_initializer_for__gameinstructor_save_restore_lessons__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__gameinstructor_save_restore_lessons__()
{
  ConVar::ConVar(
    this: &gameinstructor_save_restore_lessons,
    pName: "gameinstructor_save_restore_lessons",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Set to 0 to disable save/load of open lesson opportunities in single player.");
  return atexit(func: dynamic_atexit_destructor_for__gameinstructor_save_restore_lessons__);
}

//------------------------------------------------------------------------------
// Address: 0x10412560
// Name: _dynamic_initializer_for__gameinstructor_verbose__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__gameinstructor_verbose__()
{
  ConVar::ConVar(
    this: &gameinstructor_verbose,
    pName: "gameinstructor_verbose",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Set to 1 for standard debugging or 2 (in combo with gameinstructor_verbose_lesson) to show update actions.");
  return atexit(func: dynamic_atexit_destructor_for__gameinstructor_verbose__);
}

//------------------------------------------------------------------------------
// Address: 0x10412590
// Name: _dynamic_initializer_for__gameinstructor_verbose_lesson__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__gameinstructor_verbose_lesson__()
{
  ConVar::ConVar(
    this: &gameinstructor_verbose_lesson,
    pName: "gameinstructor_verbose_lesson",
    pDefaultValue: prType,
    flags: 0x4000,
    pHelpString: "Display more verbose information for lessons have this name.");
  return atexit(func: dynamic_atexit_destructor_for__gameinstructor_verbose_lesson__);
}

//------------------------------------------------------------------------------
// Address: 0x104125C0
// Name: _dynamic_initializer_for__gameinstructor_find_errors__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__gameinstructor_find_errors__()
{
  ConVar::ConVar(
    this: &gameinstructor_find_errors,
    pName: "gameinstructor_find_errors",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Set to 1 and the game instructor will run EVERY scripted command to uncover errors.");
  return atexit(func: dynamic_atexit_destructor_for__gameinstructor_find_errors__);
}

//------------------------------------------------------------------------------
// Address: 0x104125F0
// Name: _dynamic_initializer_for__gameinstructor_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__gameinstructor_enable__()
{
  ConVar::ConVar(
    this: &gameinstructor_enable,
    pName: "gameinstructor_enable",
    pDefaultValue: "0",
    flags: 136,
    pHelpString: "Display in game lessons that teach new players.",
    callback: GameInstructorEnable_ChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__gameinstructor_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412620
// Name: _dynamic_initializer_for__gameinstructor_start_sound_cooldown__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__gameinstructor_start_sound_cooldown__()
{
  ConVar::ConVar(
    this: &gameinstructor_start_sound_cooldown,
    pName: "gameinstructor_start_sound_cooldown",
    pDefaultValue: "4.0",
    flags: 0,
    pHelpString: "Number of seconds forced between similar lesson start sounds.");
  return atexit(func: dynamic_atexit_destructor_for__gameinstructor_start_sound_cooldown__);
}

//------------------------------------------------------------------------------
// Address: 0x10412680
// Name: _dynamic_initializer_for__gameinstructor_reload_lessons_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__gameinstructor_reload_lessons_command__()
{
  ConCommand::ConCommand(
    this: &gameinstructor_reload_lessons_command,
    pName: "gameinstructor_reload_lessons",
    callback: gameinstructor_reload_lessons,
    pHelpString: "Shuts down all open lessons and reloads them from the script file.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__gameinstructor_reload_lessons_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104126B0
// Name: _dynamic_initializer_for__gameinstructor_reset_counts_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__gameinstructor_reset_counts_command__()
{
  ConCommand::ConCommand(
    this: &gameinstructor_reset_counts_command,
    pName: "gameinstructor_reset_counts",
    callback: (void (__cdecl *)())CGameInstructorUserNotificationsListener::OnGameUsersChanged,
    pHelpString: "Resets all display and success counts to zero.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__gameinstructor_reset_counts_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104126E0
// Name: _dynamic_initializer_for__gameinstructor_dump_open_lessons_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__gameinstructor_dump_open_lessons_command__()
{
  ConCommand::ConCommand(
    this: &gameinstructor_dump_open_lessons_command,
    pName: "gameinstructor_dump_open_lessons",
    callback: gameinstructor_dump_open_lessons,
    pHelpString: "Gives a list of all currently open lessons.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__gameinstructor_dump_open_lessons_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104303C0
// Name: _dynamic_atexit_destructor_for__gameinstructor_save_restore_lessons__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gameinstructor_save_restore_lessons__()
{
  ConVar::~ConVar(this: &gameinstructor_save_restore_lessons);
}

//------------------------------------------------------------------------------
// Address: 0x104303D0
// Name: _dynamic_atexit_destructor_for__gameinstructor_verbose__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gameinstructor_verbose__()
{
  ConVar::~ConVar(this: &gameinstructor_verbose);
}

//------------------------------------------------------------------------------
// Address: 0x104303E0
// Name: _dynamic_atexit_destructor_for__gameinstructor_verbose_lesson__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gameinstructor_verbose_lesson__()
{
  ConVar::~ConVar(this: &gameinstructor_verbose_lesson);
}

//------------------------------------------------------------------------------
// Address: 0x104303F0
// Name: _dynamic_atexit_destructor_for__gameinstructor_find_errors__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gameinstructor_find_errors__()
{
  ConVar::~ConVar(this: &gameinstructor_find_errors);
}

//------------------------------------------------------------------------------
// Address: 0x10430400
// Name: _dynamic_atexit_destructor_for__gameinstructor_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gameinstructor_enable__()
{
  ConVar::~ConVar(this: &gameinstructor_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10430410
// Name: _dynamic_atexit_destructor_for__gameinstructor_start_sound_cooldown__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gameinstructor_start_sound_cooldown__()
{
  ConVar::~ConVar(this: &gameinstructor_start_sound_cooldown);
}

//------------------------------------------------------------------------------
// Address: 0x10430430
// Name: _dynamic_atexit_destructor_for__gameinstructor_reload_lessons_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gameinstructor_reload_lessons_command__()
{
  ConCommand::~ConCommand(this: &gameinstructor_reload_lessons_command);
}

//------------------------------------------------------------------------------
// Address: 0x10430440
// Name: _dynamic_atexit_destructor_for__gameinstructor_reset_counts_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gameinstructor_reset_counts_command__()
{
  ConCommand::~ConCommand(this: &gameinstructor_reset_counts_command);
}

//------------------------------------------------------------------------------
// Address: 0x10430450
// Name: _dynamic_atexit_destructor_for__gameinstructor_dump_open_lessons_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gameinstructor_dump_open_lessons_command__()
{
  ConCommand::~ConCommand(this: &gameinstructor_dump_open_lessons_command);
}

//------------------------------------------------------------------------------
// Address: 0x10412490
// Name: _dynamic_initializer_for__g_GameInstructor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GameInstructor__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_GameInstructor, name: "C_GameInstructor");
  byte_106058DC = 0;
  dword_106058D8 = 42;
  g_GameInstructor.__vftable = (CAutoGameSystemPerFrame_vtbl *)&C_GameInstructor::`vftable'{for `CAutoGameSystemPerFrame'};
  dword_106058D4 = (int)&C_GameInstructor::`vftable'{for `CGameEventListener'};
  dword_106058E0 = 0;
  dword_106058E4 = 0;
  dword_106058E8 = 0;
  dword_106058EC = 0;
  dword_106058F0 = 0;
  dword_106058F4 = 0;
  dword_106058F8 = 0;
  dword_106058FC = 0;
  dword_10605900 = 0;
  dword_10605904 = 0;
  dword_10605908 = 0;
  dword_1060590C = 0;
  dword_10605910 = 0;
  dword_10605914 = 0;
  dword_10605918 = 0;
  dword_10605928 = -1;
  dword_106059B4 = -1;
  byte_106059B8 = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_GameInstructor__);
}

//------------------------------------------------------------------------------
// Address: 0x10412650
// Name: _dynamic_initializer_for__sv_gameinstructor_disable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_gameinstructor_disable__()
{
  ConVar::ConVar(
    this: &sv_gameinstructor_disable,
    pName: "sv_gameinstructor_disable",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Force all clients to disable their game instructors.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SVGameInstructorDisable_ChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__sv_gameinstructor_disable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412710
// Name: _dynamic_initializer_for__cc_CreateHairball__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_CreateHairball__()
{
  ConCommand::ConCommand(
    this: &cc_CreateHairball,
    pName: "CreateHairball",
    callback: CreateHairballCallback,
    pHelpString: nullptr,
    flags: 16386,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_CreateHairball__);
}

//------------------------------------------------------------------------------
// Address: 0x10412740
// Name: _dynamic_initializer_for____g_C_InfoOverlayAccessorClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_InfoOverlayAccessorClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_InfoOverlayAccessorClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_InfoOverlayAccessorClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430420
// Name: _dynamic_atexit_destructor_for__sv_gameinstructor_disable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_gameinstructor_disable__()
{
  ConVar::~ConVar(this: &sv_gameinstructor_disable);
}

//------------------------------------------------------------------------------
// Address: 0x10430460
// Name: _dynamic_atexit_destructor_for__g_GameInstructor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameInstructor__()
{
  void *v0; // eax
  void *v1; // eax
  void *v2; // eax

  v0 = (void *)dword_10605908;
  dword_10605914 = 0;
  if ( dword_10605910 >= 0 )
  {
    if ( dword_10605908 != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)dword_10605908);
      v0 = nullptr;
      dword_10605908 = 0;
    }
    dword_1060590C = 0;
  }
  dword_10605918 = (int)v0;
  if ( dword_10605910 >= 0 )
  {
    if ( v0 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v0);
      dword_10605908 = 0;
    }
    dword_1060590C = 0;
  }
  v1 = (void *)dword_106058F4;
  dword_10605900 = 0;
  if ( dword_106058FC >= 0 )
  {
    if ( dword_106058F4 != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)dword_106058F4);
      v1 = nullptr;
      dword_106058F4 = 0;
    }
    dword_106058F8 = 0;
  }
  dword_10605904 = (int)v1;
  if ( dword_106058FC >= 0 )
  {
    if ( v1 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1);
      dword_106058F4 = 0;
    }
    dword_106058F8 = 0;
  }
  v2 = (void *)dword_106058E0;
  dword_106058EC = 0;
  if ( dword_106058E8 >= 0 )
  {
    if ( dword_106058E0 != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)dword_106058E0);
      v2 = nullptr;
      dword_106058E0 = 0;
    }
    dword_106058E4 = 0;
  }
  dword_106058F0 = (int)v2;
  if ( dword_106058E8 >= 0 )
  {
    if ( v2 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
      dword_106058E0 = 0;
    }
    dword_106058E4 = 0;
  }
  dword_106058D4 = (int)&CGameEventListener::`vftable';
  dword_106058D8 = 13;
  if ( byte_106058DC != 0 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: (IGameEventListener2 *)&dword_106058D4);
    byte_106058DC = 0;
  }
  dword_106058D4 = (int)&IGameEventListener2::`vftable';
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_GameInstructor);
}

//------------------------------------------------------------------------------
// Address: 0x104305E0
// Name: _dynamic_atexit_destructor_for__cc_CreateHairball__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_CreateHairball__()
{
  ConCommand::~ConCommand(this: &cc_CreateHairball);
}
