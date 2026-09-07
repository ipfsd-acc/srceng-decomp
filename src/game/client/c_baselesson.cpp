// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_baselesson.cpp
// Functions: 98
// ============================================================

#include "game\client\c_baselesson.h"

//------------------------------------------------------------------------------
// Address: 0x1003AD50
// Name: public: static class C_BaseEntity __near * C_BaseEntity::Instance(class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl C_BaseEntity::Instance(CBaseHandle hEnt)
{
  return CClientEntityList::GetBaseEntityFromHandle(this: (CClientEntityList *)cl_entitylist.m_Index, hEnt);
}

//------------------------------------------------------------------------------
// Address: 0x1003AD70
// Name: public: static class C_BaseEntity __near * C_BaseEntity::Instance(int)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl C_BaseEntity::Instance(int iEnt)
{
  return CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: iEnt);
}

//------------------------------------------------------------------------------
// Address: 0x10049130
// Name: public: bool CBaseLesson::NoPriority(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseLesson::NoPriority(CBaseLesson *this)
{
  return this->m_iPriority == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10049140
// Name: public: bool CBaseLesson::IsLocked(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseLesson::IsLocked(CBaseLesson *this)
{
  float m_fLockTime; // xmm0_4
  float v3; // xmm1_4

  if ( this->m_fLockDuration == 0.0 || this->m_fStartTime <= 0.0 || !this->IsVisible(this) )
    return false;
  m_fLockTime = this->m_fLockTime;
  if ( m_fLockTime == 0.0 )
    m_fLockTime = this->m_fStartTime;
  v3 = *(float *)(gpGlobals.m_Index + 12);
  return v3 > (float)(this->m_fStartTime + 0.1) && (float)(m_fLockTime + this->m_fLockDuration) > v3;
}

//------------------------------------------------------------------------------
// Address: 0x100491D0
// Name: public: bool CBaseLesson::IsLearned(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseLesson::IsLearned(CBaseLesson *this)
{
  int m_iDisplayLimit; // eax
  bool result; // al
  int m_iSuccessLimit; // eax

  m_iDisplayLimit = this->m_iDisplayLimit;
  result = true;
  if ( m_iDisplayLimit <= 0 || this->m_iDisplayCount < m_iDisplayLimit )
  {
    m_iSuccessLimit = this->m_iSuccessLimit;
    if ( m_iSuccessLimit <= 0 || this->m_iSuccessCount < m_iSuccessLimit )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100491F0
// Name: public: void CBaseLesson::ResetDisplaysAndSuccesses(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseLesson::ResetDisplaysAndSuccesses(CBaseLesson *this)
{
  *((_BYTE *)this + 60) &= ~2u;
  this->m_iDisplayCount = 0;
  this->m_iSuccessCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10049200
// Name: public: bool CBaseLesson::IncDisplayCount(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseLesson::IncDisplayCount(CBaseLesson *this)
{
  int m_iDisplayCount; // eax

  m_iDisplayCount = this->m_iDisplayCount;
  if ( m_iDisplayCount >= this->m_iDisplayLimit )
    return 0;
  this->m_iDisplayCount = m_iDisplayCount + 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10049220
// Name: public: bool CBaseLesson::IncSuccessCount(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseLesson::IncSuccessCount(CBaseLesson *this)
{
  int m_iSuccessCount; // eax

  m_iSuccessCount = this->m_iSuccessCount;
  if ( m_iSuccessCount >= this->m_iSuccessLimit )
    return 0;
  this->m_iSuccessCount = m_iSuccessCount + 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10049240
// Name: public: virtual void CBaseLesson::TakePlaceOf(class CBaseLesson __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseLesson::TakePlaceOf(CBaseLesson *this, CBaseLesson *pLesson)
{
  this->m_bWasDisplayed = pLesson->m_bWasDisplayed;
  pLesson->m_bWasDisplayed = false;
}

//------------------------------------------------------------------------------
// Address: 0x10049260
// Name: public: virtual void CIconLesson::TakePlaceOf(class CBaseLesson __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconLesson::TakePlaceOf(CIconLesson *this, CBaseLesson *pLesson)
{
  float *v3; // eax
  float *v4; // esi

  this->m_bWasDisplayed = pLesson->m_bWasDisplayed;
  pLesson->m_bWasDisplayed = false;
  v3 = (float *)__RTDynamicCast(
                  inptr: pLesson,
                  VfDelta: 0,
                  SrcType: &CBaseLesson `RTTI Type Descriptor',
                  TargetType: &CIconLesson `RTTI Type Descriptor',
                  isReference: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    if ( *((_DWORD *)v3 + 64) != -1 && Locator_GetTargetFromHandle(hTarget: *((_DWORD *)v3 + 64)) != nullptr )
      this->m_hLocatorTarget = (int)v4[64];
    this->m_fOnScreenStartTime = v4[68];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100492D0
// Name: public: bool CIconLesson::IsPresentComplete(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIconLesson::IsPresentComplete(CIconLesson *this)
{
  CLocatorTarget *TargetFromHandle; // eax

  return this->m_hLocatorTarget != -1
      && (TargetFromHandle = Locator_GetTargetFromHandle(hTarget: this->m_hLocatorTarget)) != nullptr
      && !CLocatorTarget::IsPresenting(this: TargetFromHandle);
}

//------------------------------------------------------------------------------
// Address: 0x10049300
// Name: public: void CIconLesson::PresentStart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconLesson::PresentStart(CIconLesson *this)
{
  CLocatorTarget *TargetFromHandle; // eax

  if ( this->m_hLocatorTarget != -1 )
  {
    TargetFromHandle = Locator_GetTargetFromHandle(hTarget: this->m_hLocatorTarget);
    if ( TargetFromHandle != nullptr )
      CLocatorTarget::StartPresent(this: TargetFromHandle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049320
// Name: public: void CIconLesson::PresentEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconLesson::PresentEnd(CIconLesson *this)
{
  CLocatorTarget *TargetFromHandle; // eax

  if ( this->m_hLocatorTarget != -1 )
  {
    TargetFromHandle = Locator_GetTargetFromHandle(hTarget: this->m_hLocatorTarget);
    if ( TargetFromHandle != nullptr )
      CLocatorTarget::EndPresent(this: TargetFromHandle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049340
// Name: public: static class C_BaseEntity __near * C_BaseEntity::Instance(class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl C_BaseEntity::Instance(IClientEntity *ent)
{
  if ( ent != nullptr )
    return ent->GetBaseEntity(this: ent);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10049360
// Name: public: CGameInstructorSymbol::CGameInstructorSymbol(void)
// Source: json
//------------------------------------------------------------------------------
CGameInstructorSymbol *__thiscall CGameInstructorSymbol::CGameInstructorSymbol(CGameInstructorSymbol *this)
{
  this->m_SymbolId.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10049370
// Name: public: CGameInstructorSymbol::CGameInstructorSymbol(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGameInstructorSymbol *__thiscall CGameInstructorSymbol::CGameInstructorSymbol(
        CGameInstructorSymbol *this,
        const char *pStr)
{
  const char *v4; // [esp-4h] [ebp-8h]

  v4 = pStr;
  this->m_SymbolId.m_Id = -1;
  this->m_SymbolId.m_Id = CUtlSymbolTable::AddString(
                            this: &g_CGameInstructorSymbolSymbolTable,
                            result: (CUtlSymbol *)&pStr + 1,
                            pString: v4)->m_Id;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100493A0
// Name: public: class CGameInstructorSymbol __near & CGameInstructorSymbol::operator=(class CGameInstructorSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
CGameInstructorSymbol *__thiscall CGameInstructorSymbol::operator=(
        CGameInstructorSymbol *this,
        const CGameInstructorSymbol *src)
{
  this->m_SymbolId.m_Id = src->m_SymbolId.m_Id;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100493C0
// Name: public: bool CGameInstructorSymbol::operator==(class CGameInstructorSymbol const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameInstructorSymbol::operator==(CGameInstructorSymbol *this, const CGameInstructorSymbol *src)
{
  return this->m_SymbolId.m_Id == src->m_SymbolId.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x100493E0
// Name: public: char const __near * CGameInstructorSymbol::String(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameInstructorSymbol::String(CGameInstructorSymbol *this)
{
  return CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_SymbolId);
}

//------------------------------------------------------------------------------
// Address: 0x10049400
// Name: protected: bool CBaseLesson::DoDelayedPlayerSwaps(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseLesson::DoDelayedPlayerSwaps(CBaseLesson *this)
{
  C_BasePlayer *v2; // edi
  unsigned int *v3; // ebx

  if ( this->m_iNumDelayedPlayerSwaps == 0 )
    return 1;
  while ( 1 )
  {
    v2 = UTIL_PlayerByUserId(userID: *((_DWORD *)&this->m_bOnceLearnedNeverOpen + 2 * this->m_iNumDelayedPlayerSwaps));
    if ( v2 == nullptr )
      break;
    if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 1 )
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tSuccessful delayed player swap!");
    v3 = *((unsigned int **)&this->m_szLessonGroup.m_SymbolId.m_Id + 2 * this->m_iNumDelayedPlayerSwaps);
    *v3 = v2->GetRefEHandle(this: v2)->m_Index;
    if ( --this->m_iNumDelayedPlayerSwaps == 0 )
      return 1;
  }
  if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 1 )
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tFailed delayed player swap!");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100494A0
// Name: public: void CTextLesson::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextLesson::Init(CTextLesson *this)
{
  CUtlSymbol result; // [esp+6h] [ebp-2h] BYREF

  this->m_szDisplayText.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                   this: &g_CGameInstructorSymbolSymbolTable,
                                                   &result,
                                                   pString: prType)->m_Id;
  this->m_szDisplayParamText.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                        this: &g_CGameInstructorSymbolSymbolTable,
                                                        &result,
                                                        pString: prType)->m_Id;
  this->m_szBinding.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                               this: &g_CGameInstructorSymbolSymbolTable,
                                               &result,
                                               pString: prType)->m_Id;
  this->m_szGamepadBinding.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                      this: &g_CGameInstructorSymbolSymbolTable,
                                                      &result,
                                                      pString: prType)->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10049520
// Name: public: void CIconLesson::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconLesson::Init(CIconLesson *this)
{
  CUtlSymbol result; // [esp+Ah] [ebp-2h] BYREF

  this->m_hIconTarget.m_Index = -1;
  this->m_szVguiTargetName.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                      this: &g_CGameInstructorSymbolSymbolTable,
                                                      &result,
                                                      pString: prType)->m_Id;
  this->m_szVguiTargetLookup.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                        this: &g_CGameInstructorSymbolSymbolTable,
                                                        &result,
                                                        pString: prType)->m_Id;
  this->m_nVguiTargetEdge = 0;
  this->m_hLocatorTarget = -1;
  *(_DWORD *)&this->m_bFixedPosition = 0x1000000;
  *(_WORD *)&this->m_bShowWhenOccluded = 1;
  this->m_bForceCaption = false;
  this->m_szOnscreenIcon.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                    this: &g_CGameInstructorSymbolSymbolTable,
                                                    &result,
                                                    pString: prType)->m_Id;
  this->m_szOffscreenIcon.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                     this: &g_CGameInstructorSymbolSymbolTable,
                                                     &result,
                                                     pString: prType)->m_Id;
  this->m_flUpOffset = 0.0;
  this->m_flRelativeUpOffset = 0.0;
  this->m_fFixedPositionX = 0.0;
  this->m_fFixedPositionY = 0.0;
  this->m_fRange = 0.0;
  this->m_fCurrentDistance = 0.0;
  this->m_fOnScreenStartTime = 0.0;
  this->m_fUpdateDistanceTime = 0.0;
  this->m_iFlags = 0;
  this->m_szCaptionColor.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                    this: &g_CGameInstructorSymbolSymbolTable,
                                                    &result,
                                                    pString: "255,255,255")->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10049640
// Name: public: virtual void CIconLesson::Stop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconLesson::Stop(CIconLesson *this)
{
  if ( CBaseLesson::DoDelayedPlayerSwaps(this) != 0 )
  {
    if ( this->m_hLocatorTarget != -1 )
      Locator_RemoveTarget(hTarget: this->m_hLocatorTarget);
    this->m_fOnScreenStartTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049670
// Name: public: virtual bool CIconLesson::ShouldDisplay(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIconLesson::ShouldDisplay(CIconLesson *this)
{
  float m_fRange; // xmm0_4
  CLocatorTarget *TargetFromHandle; // eax
  C_GameInstructor *GameInstructor; // eax
  C_BasePlayer *LocalPlayer; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CIconLesson::ShouldDisplay",
    a3: 0,
    a4: "GameInstructor",
    a5: false,
    a6: 4);
  if ( CBaseLesson::DoDelayedPlayerSwaps(this) != 0
    && ((m_fRange = this->m_fRange) <= 0.0 || this->m_fCurrentDistance <= m_fRange)
    && (this->m_bShowWhenOccluded
     || this->m_hLocatorTarget < 0
     || (TargetFromHandle = Locator_GetTargetFromHandle(hTarget: this->m_hLocatorTarget)) == nullptr
     || !TargetFromHandle->m_bOccluded)
    && ((GameInstructor = GetGameInstructor(),
         LocalPlayer = C_GameInstructor::GetLocalPlayer(this: GameInstructor),
         this->m_bUsableInMidair)
     || LocalPlayer != nullptr && C_BasePlayer::GetAirTime(this: LocalPlayer) <= 0.75) )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049730
// Name: public: virtual bool CIconLesson::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIconLesson::IsVisible(CIconLesson *this)
{
  bool m_bNoIconTarget; // bl
  CLocatorTarget *TargetFromHandle; // eax
  bool IsVisible; // bl

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CIconLesson::IsVisible",
    a3: 0,
    a4: "GameInstructor",
    a5: false,
    a6: 4);
  if ( this->m_hLocatorTarget == -1 )
  {
    m_bNoIconTarget = this->m_bNoIconTarget;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return m_bNoIconTarget;
  }
  else
  {
    TargetFromHandle = Locator_GetTargetFromHandle(hTarget: this->m_hLocatorTarget);
    if ( TargetFromHandle != nullptr )
    {
      IsVisible = CLocatorTarget::IsVisible(this: TargetFromHandle);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return IsVisible;
    }
    else
    {
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100497B0
// Name: public: virtual void CIconLesson::SwapOutPlayers(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconLesson::SwapOutPlayers(CIconLesson *this, C_BasePlayer *iOldUserID, int iNewUserID)
{
  C_BasePlayer *v4; // eax
  unsigned int m_Index; // edx
  CHandle<C_BaseEntity> *p_m_hIconTarget; // ebx
  IHandleEntity *m_pEntity; // edi
  int m_iNumDelayedPlayerSwaps; // eax
  C_BasePlayer *pOldPlayer; // [esp+Ch] [ebp+8h]

  if ( !this->m_bNoIconTarget )
  {
    pOldPlayer = UTIL_PlayerByUserId(userID: (int)iOldUserID);
    v4 = UTIL_PlayerByUserId(userID: iNewUserID);
    m_Index = this->m_hIconTarget.m_Index;
    p_m_hIconTarget = &this->m_hIconTarget;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( pOldPlayer == m_pEntity )
    {
      if ( v4 != nullptr )
      {
        p_m_hIconTarget->m_Index = v4->GetRefEHandle(this: v4)->m_Index;
      }
      else
      {
        m_iNumDelayedPlayerSwaps = this->m_iNumDelayedPlayerSwaps;
        if ( m_iNumDelayedPlayerSwaps < 8 )
        {
          this->m_pDelayedPlayerSwap[m_iNumDelayedPlayerSwaps].phHandleToChange = p_m_hIconTarget;
          this->m_pDelayedPlayerSwap[this->m_iNumDelayedPlayerSwaps++].iNewUserID = iNewUserID;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049860
// Name: public: void CIconLesson::SetLocatorBinding(class CLocatorTarget __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconLesson::SetLocatorBinding(CIconLesson *this, CLocatorTarget *pLocatorTarget)
{
  unsigned __int16 m_Id; // dx
  const char *v4; // eax

  if ( !input->ControllerModeActive(this: input) )
  {
    m_Id = this->m_szBinding.m_SymbolId.m_Id;
    goto LABEL_6;
  }
  if ( *CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_szGamepadBinding.m_SymbolId) != 0 )
  {
    m_Id = this->m_szGamepadBinding.m_SymbolId.m_Id;
LABEL_6:
    v4 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: (CUtlSymbol)m_Id);
    goto LABEL_7;
  }
  v4 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_szBinding.m_SymbolId);
LABEL_7:
  CLocatorTarget::SetBinding(this: pLocatorTarget, pszBinding: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100498D0
// Name: private: virtual void CIconLesson::UpdateLocatorTarget(class CLocatorTarget __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconLesson::UpdateLocatorTarget(
        CIconLesson *this,
        CLocatorTarget *pLocatorTarget,
        C_BasePlayer *pIconTarget)
{
  const char *v5; // eax
  const char *v6; // eax
  const Vector *v7; // eax
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  float *v9; // eax
  float v10; // xmm2_4
  float v11; // xmm0_4
  const char *PlayerName; // ebx
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  C_GameInstructor *GameInstructor; // eax
  C_BasePlayer *LocalPlayer; // eax
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // ecx
  unsigned int v20; // ecx
  C_World *v21; // ebx
  float m_fLockTime; // xmm0_4
  float v23; // xmm1_4
  C_GameInstructor *v24; // eax
  const char *v25; // [esp-4h] [ebp-34h]
  Vector v26; // [esp+Ch] [ebp-24h] BYREF
  float m_flUpOffset; // [esp+20h] [ebp-10h]
  float v28; // [esp+24h] [ebp-Ch]
  float v29; // [esp+28h] [ebp-8h]
  float v30; // [esp+2Ch] [ebp-4h]
  float pLocatorTargeta; // [esp+38h] [ebp+8h]

  if ( this->m_bFixedPosition )
  {
    pLocatorTarget->m_bOriginInScreenspace = true;
    pLocatorTarget->m_vecOrigin.x = this->m_fFixedPositionX;
    pLocatorTarget->m_vecOrigin.y = this->m_fFixedPositionY;
    v5 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_szVguiTargetName.m_SymbolId);
    CLocatorTarget::SetVguiTargetName(this: pLocatorTarget, pchVguiTargetName: v5);
    v6 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_szVguiTargetLookup.m_SymbolId);
    CLocatorTarget::SetVguiTargetLookup(this: pLocatorTarget, pchVguiTargetLookup: v6);
    CLocatorTarget::SetVguiTargetEdge(this: pLocatorTarget, nVguiEdge: this->m_nVguiTargetEdge);
  }
  else
  {
    pLocatorTarget->m_bOriginInScreenspace = false;
    m_flUpOffset = this->m_flUpOffset;
    pLocatorTargeta = this->m_flRelativeUpOffset;
    v7 = MainViewUp(nSlot: 0);
    EyePosition = pIconTarget->EyePosition;
    v28 = v7->x * pLocatorTargeta;
    v29 = v7->y * pLocatorTargeta;
    v30 = v7->z * pLocatorTargeta;
    v9 = (float *)EyePosition(this: pIconTarget, result: &v26);
    v10 = v9[1] + v29;
    v11 = (float)(v9[2] + v30) + m_flUpOffset;
    pLocatorTarget->m_vecOrigin.x = *v9 + v28;
    pLocatorTarget->m_vecOrigin.y = v10;
    pLocatorTarget->m_vecOrigin.z = v11;
    CLocatorTarget::SetVguiTargetName(this: pLocatorTarget, pchVguiTargetName: prType);
  }
  PlayerName = CUtlSymbolTable::String(
                 this: &g_CGameInstructorSymbolSymbolTable,
                 id: this->m_szDisplayParamText.m_SymbolId);
  if ( _V_stricmp(s1: PlayerName, s2: "use_name") == 0 )
  {
    if ( pIconTarget != nullptr && pIconTarget->IsPlayer(this: pIconTarget) )
      PlayerName = C_BasePlayer::GetPlayerName(this: pIconTarget);
    else
      PlayerName = prType;
  }
  v13 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_szDisplayText.m_SymbolId);
  CLocatorTarget::SetCaptionText(this: pLocatorTarget, pszText: v13, pszParam: PlayerName);
  CIconLesson::SetLocatorBinding(this, pLocatorTarget);
  v14 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_szOnscreenIcon.m_SymbolId);
  CLocatorTarget::SetOnscreenIconTextureName(this: pLocatorTarget, pszTexture: v14);
  v15 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_szOffscreenIcon.m_SymbolId);
  CLocatorTarget::SetOffscreenIconTextureName(this: pLocatorTarget, pszTexture: v15);
  CLocatorTarget::SetVisible(this: pLocatorTarget, bVisible: this->m_bVisible);
  GameInstructor = GetGameInstructor();
  LocalPlayer = C_GameInstructor::GetLocalPlayer(this: GameInstructor);
  if ( !this->m_bFixedPosition )
  {
    if ( LocalPlayer != nullptr
      && ((m_Index = this->m_hIconTarget.m_Index) == -1
       || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        ? (m_pEntity = nullptr)
        : (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity),
          LocalPlayer == m_pEntity)
      || ((v20 = this->m_hIconTarget.m_Index) == -1
       || g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber != HIWORD(v20)
        ? (v21 = nullptr)
        : (v21 = (C_World *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_pEntity),
          GetClientWorldEntity() == v21) )
    {
      pLocatorTarget->m_iEffectsFlags |= 0x100u;
    }
  }
  if ( this->m_bNoOffscreen )
    pLocatorTarget->m_iEffectsFlags |= 0x200u;
  else
    pLocatorTarget->m_iEffectsFlags &= ~0x200u;
  if ( this->m_bForceCaption )
    goto LABEL_34;
  if ( this->m_fLockDuration == 0.0 || this->m_fStartTime <= 0.0 || !this->IsVisible(this) )
    goto LABEL_33;
  m_fLockTime = this->m_fLockTime;
  if ( m_fLockTime == 0.0 )
    m_fLockTime = this->m_fStartTime;
  v23 = *(float *)(gpGlobals.m_Index + 12);
  if ( v23 > (float)(this->m_fStartTime + 0.1) && (float)(this->m_fLockDuration + m_fLockTime) > v23 )
LABEL_34:
    pLocatorTarget->m_iEffectsFlags |= 0x400u;
  else
LABEL_33:
    pLocatorTarget->m_iEffectsFlags &= ~0x400u;
  CLocatorTarget::Update(this: pLocatorTarget);
  if ( pLocatorTarget->m_bIsDrawing && !this->m_bHasPlayedSound )
  {
    v25 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_szStartSound.m_SymbolId);
    v24 = GetGameInstructor();
    C_GameInstructor::PlaySound(this: v24, pchSoundName: v25);
    this->m_bHasPlayedSound = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049C40
// Name: public: virtual void CScriptedIconLesson::SwapOutPlayers(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptedIconLesson::SwapOutPlayers(
        CScriptedIconLesson *this,
        C_BasePlayer *iOldUserID,
        C_BasePlayer *iNewUserID)
{
  C_BasePlayer *v5; // edx
  unsigned int m_Index; // eax
  CHandle<C_BaseEntity> *p_m_hEntity1; // edi
  IHandleEntity *m_pEntity; // ecx
  const CBaseHandle *v9; // eax
  int m_iNumDelayedPlayerSwaps; // eax
  unsigned int v11; // ecx
  CHandle<C_BaseEntity> *p_m_hEntity2; // edi
  IHandleEntity *v13; // eax
  int v14; // eax
  C_BasePlayer *pOldPlayer; // [esp+14h] [ebp+8h]
  C_BasePlayer *pNewPlayer; // [esp+18h] [ebp+Ch]

  CIconLesson::SwapOutPlayers(this, iOldUserID, (int)iNewUserID);
  pOldPlayer = UTIL_PlayerByUserId(userID: (int)iOldUserID);
  v5 = UTIL_PlayerByUserId(userID: (int)iNewUserID);
  m_Index = this->m_hEntity1.m_Index;
  p_m_hEntity1 = &this->m_hEntity1;
  pNewPlayer = v5;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( pOldPlayer == m_pEntity )
  {
    if ( v5 != nullptr )
    {
      v9 = v5->GetRefEHandle(this: v5);
      v5 = pNewPlayer;
      p_m_hEntity1->m_Index = v9->m_Index;
    }
    else
    {
      m_iNumDelayedPlayerSwaps = this->m_iNumDelayedPlayerSwaps;
      if ( m_iNumDelayedPlayerSwaps < 8 )
      {
        this->m_pDelayedPlayerSwap[m_iNumDelayedPlayerSwaps].phHandleToChange = p_m_hEntity1;
        this->m_pDelayedPlayerSwap[this->m_iNumDelayedPlayerSwaps++].iNewUserID = (int)iNewUserID;
      }
    }
  }
  v11 = this->m_hEntity2.m_Index;
  p_m_hEntity2 = &this->m_hEntity2;
  if ( v11 == -1
    || (p_m_hEntity2 = &this->m_hEntity2,
        g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11)) )
  {
    v13 = nullptr;
  }
  else
  {
    v13 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
  }
  if ( pOldPlayer == v13 )
  {
    if ( v5 != nullptr )
    {
      p_m_hEntity2->m_Index = v5->GetRefEHandle(this: v5)->m_Index;
    }
    else
    {
      v14 = this->m_iNumDelayedPlayerSwaps;
      if ( v14 < 8 )
      {
        this->m_pDelayedPlayerSwap[v14].phHandleToChange = p_m_hEntity2;
        this->m_pDelayedPlayerSwap[this->m_iNumDelayedPlayerSwaps++].iNewUserID = (int)iNewUserID;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049EC0
// Name: public: char const __near * CIconLesson::GetCaptionColorString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CIconLesson::GetCaptionColorString(CIconLesson *this)
{
  return CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_szCaptionColor.m_SymbolId);
}

//------------------------------------------------------------------------------
// Address: 0x10049EE0
// Name: public: bool CBaseLesson::ShouldShowSpew(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CBaseLesson::ShouldShowSpew@<al>(CBaseLesson *this@<ecx>, const char *a2@<ebx>)
{
  char *m_pszString; // eax
  char *v4; // esi
  const char *v5; // eax
  const char *v6; // ecx

  if ( (gameinstructor_verbose_lesson.m_nFlags & 0x1000) == 0 )
  {
    m_pszString = gameinstructor_verbose_lesson.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr || *m_pszString == 0 )
      return false;
  }
  if ( (gameinstructor_verbose_lesson.m_nFlags & 0x1000) != 0 )
  {
    v4 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v4 = gameinstructor_verbose_lesson.m_pParent->m_Value.m_pszString;
    if ( v4 == nullptr )
      v4 = (char *)prType;
  }
  v5 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
  return V_stristr(a1: v6, a2, pStr: v5, pSearch: v4) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10049F50
// Name: public: bool CBaseLesson::PrerequisitesHaveBeenMet(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseLesson::PrerequisitesHaveBeenMet(CBaseLesson *this)
{
  int m_Size; // edi
  int v2; // edx
  const CBaseLesson **i; // esi
  const CBaseLesson *v4; // eax
  int m_iDisplayLimit; // ecx
  int m_iSuccessLimit; // ecx

  m_Size = this->m_Prerequisites.m_Size;
  v2 = 0;
  if ( m_Size <= 0 )
    return 1;
  for ( i = this->m_Prerequisites.m_Memory.m_pMemory; ; ++i )
  {
    v4 = *i;
    m_iDisplayLimit = (*i)->m_iDisplayLimit;
    if ( m_iDisplayLimit <= 0 || v4->m_iDisplayCount < m_iDisplayLimit )
    {
      m_iSuccessLimit = v4->m_iSuccessLimit;
      if ( m_iSuccessLimit <= 0 || v4->m_iSuccessCount < m_iSuccessLimit )
        break;
    }
    if ( ++v2 >= m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10049F90
// Name: public: bool CBaseLesson::IsTimedOut(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseLesson::IsTimedOut(CBaseLesson *this)
{
  float m_fTimeout; // xmm0_4
  CBaseLesson *m_pRoot; // eax
  int m_iDisplayLimit; // ecx
  float m_fStartTime; // xmm1_4
  int m_iSuccessLimit; // ecx
  CUtlSymbol v8; // [esp+6h] [ebp-2h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseLesson::IsTimedOut",
    a3: 0,
    a4: "GameInstructor",
    a5: false,
    a6: 4);
  m_fTimeout = this->m_fTimeout;
  if ( m_fTimeout == 0.0 )
    goto LABEL_15;
  m_pRoot = this->m_pRoot;
  m_iDisplayLimit = m_pRoot->m_iDisplayLimit;
  m_fStartTime = this->m_fStartTime;
  if ( m_iDisplayLimit > 0 && m_pRoot->m_iDisplayCount >= m_iDisplayLimit
    || (m_iSuccessLimit = m_pRoot->m_iSuccessLimit) > 0 && m_pRoot->m_iSuccessCount >= m_iSuccessLimit )
  {
    if ( !this->m_bBumpWithTimeoutWhenLearned )
    {
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return 1;
    }
    m_fStartTime = this->m_fInitTime;
  }
  if ( m_fStartTime == 0.0 )
  {
    if ( !this->m_bCanTimeoutWhileInactive )
      goto LABEL_15;
    m_fStartTime = this->m_fInitTime;
  }
  if ( *(float *)(gpGlobals.m_Index + 12) > (float)(m_fTimeout + m_fStartTime) )
  {
    this->m_stringCloseReason.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                         this: &g_CGameInstructorSymbolSymbolTable,
                                                         result: &v8,
                                                         pString: "Timed out.")->m_Id;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
LABEL_15:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004A090
// Name: public: void CBaseLesson::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseLesson::Init(CBaseLesson *this)
{
  CUtlSymbol result; // [esp+Ah] [ebp-2h] BYREF

  *((_BYTE *)this + 60) &= ~2u;
  this->m_pRoot = nullptr;
  this->m_stringCloseReason.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                       this: &g_CGameInstructorSymbolSymbolTable,
                                                       &result,
                                                       pString: "None given.")->m_Id;
  this->m_fLockDuration = 0.0;
  this->m_fTimeout = 0.0;
  this->m_iPriority = 1000;
  this->m_iInstanceType = LESSON_INSTANCE_MULTIPLE;
  this->m_iFixedInstancesMax = 1;
  this->m_bReplaceOnlyWhenStopped = false;
  this->m_iTeam = -1;
  *(_WORD *)&this->m_bOnlyKeyboard = 0;
  this->m_bNoSplitscreen = false;
  this->m_iDisplayLimit = 0;
  this->m_iDisplayCount = 0;
  this->m_bWasDisplayed = false;
  this->m_iSuccessLimit = 0;
  this->m_iSuccessCount = 0;
  *(_DWORD *)&this->m_bCanOpenWhenDead = 0;
  this->m_bUsableInMidair = false;
  this->m_fInitTime = *(float *)(gpGlobals.m_Index + 12);
  this->m_fStartTime = 0.0;
  this->m_fLockTime = 0.0;
  this->m_fUpdateInterval = 0.5;
  this->m_bHasPlayedSound = false;
  this->m_szStartSound.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                  this: &g_CGameInstructorSymbolSymbolTable,
                                                  &result,
                                                  pString: "Instructor.LessonStart")->m_Id;
  this->m_szLessonGroup.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                   this: &g_CGameInstructorSymbolSymbolTable,
                                                   &result,
                                                   pString: prType)->m_Id;
  this->m_iNumDelayedPlayerSwaps = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004A180
// Name: protected: void CBaseLesson::MarkSucceeded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseLesson::MarkSucceeded(CBaseLesson *this)
{
  C_GameInstructor *GameInstructor; // eax
  const char *v3; // [esp-4h] [ebp-8h]

  if ( (*((_BYTE *)this + 60) & 2) == 0 )
  {
    v3 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
    GameInstructor = GetGameInstructor();
    C_GameInstructor::MarkSucceeded(this: GameInstructor, pchLessonName: v3);
    *((_BYTE *)this + 60) |= 2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A1B0
// Name: public: virtual void CIconLesson::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconLesson::Start(CIconLesson *this)
{
  unsigned int m_Index; // ecx
  C_BaseEntity **v3; // eax
  C_BaseEntity *v4; // ebx
  CUtlSymbol *v5; // eax
  int m_hLocatorTarget; // eax
  CLocatorTarget *TargetFromHandle; // edi
  int v8; // eax
  const char *CaptionColorString; // eax
  CUtlSymbol result; // [esp+6h] [ebp-2h] BYREF

  if ( CBaseLesson::DoDelayedPlayerSwaps(this) != 0 )
  {
    m_Index = this->m_hIconTarget.m_Index;
    if ( m_Index == -1
      || (v3 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index))
      || (v4 = *v3, *v3 == nullptr) )
    {
      if ( this->m_bNoIconTarget )
        return;
      v5 = CUtlSymbolTable::AddString(
             this: &g_CGameInstructorSymbolSymbolTable,
             &result,
             pString: "Icon Target handle went invalid before the lesson started!");
      goto LABEL_11;
    }
    if ( ((v4->m_fEffects & 0x20) != 0 || v4->IsDormant(this: &v4->IClientNetworkable)) && !this->m_bAllowNodrawTarget )
    {
      v5 = CUtlSymbolTable::AddString(
             this: &g_CGameInstructorSymbolSymbolTable,
             &result,
             pString: "Icon Target is using effect NODRAW and allow_nodraw_target is false!");
LABEL_11:
      this->m_stringCloseReason.m_SymbolId = (CUtlSymbol)v5->m_Id;
      *((_BYTE *)&this->CBaseLesson + 60) &= ~8u;
      return;
    }
    m_hLocatorTarget = this->m_hLocatorTarget;
    if ( m_hLocatorTarget == -1
      || (TargetFromHandle = Locator_GetTargetFromHandle(hTarget: m_hLocatorTarget)) == nullptr )
    {
      v8 = Locator_AddTarget();
      this->m_hLocatorTarget = v8;
      TargetFromHandle = Locator_GetTargetFromHandle(hTarget: v8);
    }
    if ( this->m_hLocatorTarget == -1 || TargetFromHandle == nullptr )
    {
      this->m_stringCloseReason.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                           this: &g_CGameInstructorSymbolSymbolTable,
                                                           &result,
                                                           pString: "Could not get a handle for new locator target. Too many targets in use!")->m_Id;
      *((_BYTE *)&this->CBaseLesson + 60) &= ~8u;
    }
    else
    {
      TargetFromHandle->m_iEffectsFlags |= this->m_iFlags;
      CaptionColorString = CIconLesson::GetCaptionColorString(this);
      CLocatorTarget::SetCaptionColor(this: TargetFromHandle, pszCaptionColor: CaptionColorString);
      this->UpdateLocatorTarget(this, a2: TargetFromHandle, a3: v4);
      Locator_ComputeTargetIconPositionFromHandle(hTarget: this->m_hLocatorTarget);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A2F0
// Name: public: virtual void CIconLesson::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CIconLesson::Update(CIconLesson *this@<ecx>, const char *a2@<ebp>)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  CUtlSymbol *v5; // eax
  CLocatorTarget *TargetFromHandle; // edi
  int m_iDisplayLimit; // eax
  const char *v8; // edi
  int m_iSuccessLimit; // eax
  float m_fStartTime; // xmm0_4
  const char *v11; // eax
  C_GameInstructor *GameInstructor; // eax
  const char *LocalPlayer; // eax
  float m_fOnScreenStartTime; // xmm0_4
  const char *v15; // eax
  const char *v16; // edi
  float *v17; // edi
  float *v18; // eax
  __int128 v19; // xmm0
  __int128 v20; // [esp-20h] [ebp-2Ch] BYREF
  char *v21; // [esp-8h] [ebp-14h]
  const char *v22[2]; // [esp-4h] [ebp-10h] BYREF
  C_BasePlayer *pLocalPlayer; // [esp+4h] [ebp-8h]
  C_BasePlayer *retaddr; // [esp+Ch] [ebp+0h]

  v22[1] = a2;
  pLocalPlayer = retaddr;
  if ( CBaseLesson::DoDelayedPlayerSwaps(this) != 0 )
  {
    m_Index = this->m_hIconTarget.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity,
          v21 = (char *)m_pEntity,
          m_pEntity == nullptr) )
    {
      if ( this->m_bNoIconTarget )
        return;
      v5 = CUtlSymbolTable::AddString(
             this: &g_CGameInstructorSymbolSymbolTable,
             result: (CUtlSymbol *)v22 + 1,
             pString: "Lost our icon target handle returned NULL.");
      goto LABEL_7;
    }
    if ( (((int)m_pEntity[58].__vftable & 0x20) != 0
       || ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity[2].__vftable[3].dtr_IHandleEntity)(a1: &m_pEntity[2]) != 0)
      && !this->m_bAllowNodrawTarget )
    {
      v5 = CUtlSymbolTable::AddString(
             this: &g_CGameInstructorSymbolSymbolTable,
             result: (CUtlSymbol *)v22 + 1,
             pString: "Icon Target is using effect NODRAW and allow_nodraw_target is false!");
LABEL_7:
      this->m_stringCloseReason.m_SymbolId = (CUtlSymbol)v5->m_Id;
      *((_BYTE *)&this->CBaseLesson + 60) &= ~8u;
      return;
    }
    TargetFromHandle = Locator_GetTargetFromHandle(hTarget: this->m_hLocatorTarget);
    if ( TargetFromHandle != nullptr )
    {
      this->UpdateLocatorTarget(this, a2: TargetFromHandle, a3: (C_BaseEntity *)v21);
      GameInstructor = GetGameInstructor();
      LocalPlayer = (const char *)C_GameInstructor::GetLocalPlayer(this: GameInstructor);
      m_fOnScreenStartTime = this->m_fOnScreenStartTime;
      v21 = (char *)LocalPlayer;
      if ( m_fOnScreenStartTime == 0.0 )
      {
        if ( TargetFromHandle->m_bOnscreen
          && (CIconLesson::IsPresentComplete(this) || (TargetFromHandle->m_iEffectsFlags & 0x100) != 0) )
        {
          this->m_fOnScreenStartTime = *(float *)(gpGlobals.m_Index + 12);
        }
      }
      else if ( TargetFromHandle->m_bOnscreen )
      {
        if ( (float)(*(float *)(gpGlobals.m_Index + 12) - m_fOnScreenStartTime) >= 1.5 )
          this->m_bWasDisplayed = true;
      }
      else
      {
        this->m_fOnScreenStartTime = 0.0;
      }
      if ( *(float *)(gpGlobals.m_Index + 12) > this->m_fUpdateDistanceTime )
      {
        v15 = (const char *)CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_hIconTarget);
        v16 = v15;
        if ( v21 != nullptr && v15 != nullptr && v21 != v15 )
        {
          v21 = (char *)(*(int (__thiscall **)(char *))(*(_DWORD *)v21 + 984))(a1: v21);
          v17 = (float *)(*(int (__thiscall **)(const char *))(*(_DWORD *)v16 + 300))(a1: v16);
          v18 = (float *)(*(int (__thiscall **)(char *, char *))(*(_DWORD *)v21 + 624))(a1: v21, a2: (char *)&v20 + 4);
          v19 = 0;
          *(float *)&v19 = fsqrt(
                             (float)((float)((float)(v18[1] - v17[1]) * (float)(v18[1] - v17[1]))
                                   + (float)((float)(v18[2] - v17[2]) * (float)(v18[2] - v17[2])))
                           + (float)((float)(*v18 - *v17) * (float)(*v18 - *v17)));
          v20 = v19;
        }
        else
        {
          LODWORD(v19) = 0;
        }
        LODWORD(this->m_fCurrentDistance) = v19;
        this->m_fUpdateDistanceTime = *(float *)(gpGlobals.m_Index + 12) + 0.25;
      }
    }
    else
    {
      m_iDisplayLimit = this->m_iDisplayLimit;
      v8 = "yes";
      if ( (m_iDisplayLimit <= 0 || this->m_iDisplayCount < m_iDisplayLimit)
        && ((m_iSuccessLimit = this->m_iSuccessLimit) <= 0 || this->m_iSuccessCount < m_iSuccessLimit) )
      {
        v22[0] = "no";
      }
      else
      {
        v22[0] = "yes";
      }
      m_fStartTime = this->m_fStartTime;
      v21 = "yes";
      if ( m_fStartTime <= 0.0 )
        v21 = "no";
      if ( (*((_BYTE *)&this->CBaseLesson + 60) & 1) == 0 )
        v8 = "no";
      v11 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
      _Warning(
        a1: "Problem in lesson %s: Locator_GetTargetFromHandle returned null for handle %d.\n"
        " IsInstanceActive: %s. IsInstructing: %s. IsLearned: %s\n",
        v11,
        this->m_hLocatorTarget,
        v8,
        v21,
        v22[0]);
      this->m_stringCloseReason.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                           this: &g_CGameInstructorSymbolSymbolTable,
                                                           result: (CUtlSymbol *)v22 + 1,
                                                           pString: "Lost locator target handle.")->m_Id;
      *((_BYTE *)&this->CBaseLesson + 60) &= ~8u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A5D0
// Name: public: virtual void CIconLesson::UpdateInactive(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CIconLesson::UpdateInactive(CIconLesson *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  C_BasePlayer *m_pEntity; // esi
  C_GameInstructor *GameInstructor; // eax
  C_BasePlayer *LocalPlayer; // eax
  int v8; // eax
  C_BasePlayer_vtbl *v9; // edx
  float *v10; // esi
  float *v11; // eax
  __int128 v12; // xmm0
  __int128 v13; // [esp-20h] [ebp-2Ch] BYREF
  _DWORD v14[4]; // [esp-4h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v14[1] = a2;
  v14[2] = retaddr;
  if ( *(float *)(gpGlobals.m_Index + 12) > this->m_fUpdateDistanceTime && CBaseLesson::DoDelayedPlayerSwaps(this) != 0 )
  {
    m_Index = this->m_hIconTarget.m_Index;
    if ( m_Index != -1
      && (v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
      && (m_pEntity = (C_BasePlayer *)v4->m_pEntity, v4->m_pEntity != nullptr) )
    {
      if ( ((m_pEntity->m_fEffects & 0x20) != 0 || m_pEntity->IsDormant(this: &m_pEntity->IClientNetworkable))
        && !this->m_bAllowNodrawTarget )
      {
        this->m_stringCloseReason.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                             this: &g_CGameInstructorSymbolSymbolTable,
                                                             result: (CUtlSymbol *)v14 + 1,
                                                             pString: "Icon Target is using effect NODRAW and allow_nodraw_target is false!")->m_Id;
        *((_BYTE *)&this->CBaseLesson + 60) &= ~8u;
      }
      else
      {
        GameInstructor = GetGameInstructor();
        LocalPlayer = C_GameInstructor::GetLocalPlayer(this: GameInstructor);
        if ( LocalPlayer == nullptr || LocalPlayer == m_pEntity )
        {
          LODWORD(v12) = 0;
        }
        else
        {
          v8 = (int)LocalPlayer->ActivePlayerCombatCharacter(this: LocalPlayer);
          v9 = m_pEntity->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
          v14[0] = v8;
          v10 = (float *)v9->WorldSpaceCenter(this: m_pEntity);
          v11 = (float *)(*(int (__thiscall **)(_DWORD, char *))(*(_DWORD *)v14[0] + 624))(
                           a1: v14[0],
                           a2: (char *)&v13 + 4);
          v12 = 0;
          *(float *)&v12 = fsqrt(
                             (float)((float)((float)(v11[1] - v10[1]) * (float)(v11[1] - v10[1]))
                                   + (float)((float)(v11[2] - v10[2]) * (float)(v11[2] - v10[2])))
                           + (float)((float)(*v11 - *v10) * (float)(*v11 - *v10)));
          v13 = v12;
        }
        LODWORD(this->m_fCurrentDistance) = v12;
        this->m_fUpdateDistanceTime = *(float *)(gpGlobals.m_Index + 12) + 0.25;
      }
    }
    else
    {
      if ( !this->m_bNoIconTarget )
      {
        this->m_stringCloseReason.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                             this: &g_CGameInstructorSymbolSymbolTable,
                                                             result: (CUtlSymbol *)v14 + 1,
                                                             pString: "Lost our icon target handle returned NULL.")->m_Id;
        *((_BYTE *)&this->CBaseLesson + 60) &= ~8u;
      }
      this->m_fCurrentDistance = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A780
// Name: public: virtual void CGameInstructorSymbolSaveRestoreOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameInstructorSymbolSaveRestoreOps::Save(
        CGameInstructorSymbolSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  ISave *v3; // esi
  CUtlSymbol *pField; // edi
  const char *v5; // eax
  const char *v6; // eax

  v3 = pSave;
  pSave->StartBlock(this: pSave);
  pField = (CUtlSymbol *)fieldInfo->pField;
  if ( CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: *(CUtlSymbol *)fieldInfo->pField) != nullptr )
  {
    v5 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: (CUtlSymbol)pField->m_Id);
    pSave = (ISave *)(_V_strlen(str: v5) + 1);
  }
  else
  {
    pSave = nullptr;
  }
  v3->WriteInt_2(this: v3, a2: (const int *)&pSave, a3: 1);
  if ( (int)pSave > 0 )
  {
    v6 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: (CUtlSymbol)pField->m_Id);
    v3->WriteData_2(this: v3, a2: v6, a3: (int)pSave);
  }
  v3->EndBlock(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1004A820
// Name: public: virtual void CGameInstructorSymbolSaveRestoreOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameInstructorSymbolSaveRestoreOps::Restore(
        CGameInstructorSymbolSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  IRestore *v3; // esi
  void *v4; // esp
  CUtlSymbol *pField; // edi
  char v6[12]; // [esp+0h] [ebp-10h] BYREF
  int nNumChars; // [esp+Ch] [ebp-4h] BYREF

  v3 = pRestore;
  pRestore->StartBlock(this: pRestore);
  v3->ReadInt_2(this: v3, a2: &nNumChars, a3: 1, a4: 0);
  if ( nNumChars > 0 )
  {
    v4 = alloca(nNumChars);
    v3->ReadData(this: v3, a2: v6, a3: nNumChars, a4: nNumChars);
    pField = (CUtlSymbol *)fieldInfo->pField;
    pField->m_Id = CUtlSymbolTable::AddString(
                     this: &g_CGameInstructorSymbolSymbolTable,
                     result: (CUtlSymbol *)&pRestore + 1,
                     pString: v6)->m_Id;
  }
  v3->EndBlock(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1004A8A0
// Name: public: virtual void CScriptedIconLesson::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptedIconLesson::FireGameEvent(CScriptedIconLesson *this, IGameEvent *event)
{
  C_GameInstructor *GameInstructor; // eax
  C_BasePlayer *LocalPlayer; // eax
  int i; // ebx
  void *v6; // edi
  const char *name; // [esp+4h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CScriptedIconLesson::FireGameEvent",
    a3: 0,
    a4: "GameInstructor",
    a5: false,
    a6: 4);
  if ( !this->m_bDisabled
    && CBaseLesson::DoDelayedPlayerSwaps(this) != 0
    && C_BasePlayer::GetLocalPlayer(nSlot: -1) != nullptr
    && (!this->m_bOnlyKeyboard || !input->ControllerModeActive(this: input))
    && (!this->m_bOnlyGamepad || input->ControllerModeActive(this: input)) )
  {
    GameInstructor = GetGameInstructor();
    LocalPlayer = C_GameInstructor::GetLocalPlayer(this: GameInstructor);
    if ( this->m_iTeam == -1 || LocalPlayer == nullptr || LocalPlayer->GetTeamNumber(this: LocalPlayer) == this->m_iTeam )
    {
      name = event->GetName(this: event);
      this->ProcessOpenGameEvents(this, a2: this, a3: name, a4: event);
      for ( i = 0; i < this->m_OpenOpportunities.m_Size; ++i )
      {
        v6 = __RTDynamicCast(
               inptr: this->m_OpenOpportunities.m_Memory.m_pMemory[i],
               VfDelta: 0,
               SrcType: &CBaseLesson `RTTI Type Descriptor',
               TargetType: &CScriptedIconLesson `RTTI Type Descriptor',
               isReference: 0);
        (*(void (__thiscall **)(void *, CScriptedIconLesson *, const char *, IGameEvent *))(*(_DWORD *)v6 + 64))(
          a1: v6,
          a2: this,
          a3: name,
          a4: event);
        (*(void (__thiscall **)(void *, CScriptedIconLesson *, const char *, IGameEvent *))(*(_DWORD *)v6 + 68))(
          a1: v6,
          a2: this,
          a3: name,
          a4: event);
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1004A9E0
// Name: private: bool CScriptedIconLesson::ProcessElementAction(int,bool,char const __near *,float __near &,class CGameInstructorSymbol const __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CScriptedIconLesson::ProcessElementAction@<al>(
        CScriptedIconLesson *this@<ecx>,
        const char *a2@<ebx>,
        int iAction,
        bool bNot,
        const char *pchVarName,
        float *fVar,
        CGameInstructorSymbol *pchParamName,
        float fParam)
{
  const char *v8; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // edi
  const char *v14; // eax
  const char *v15; // edi
  const char *v16; // eax
  const char *v17; // ebx
  int v18; // esi
  const char *v19; // eax
  const char *v20; // eax
  int v21; // esi
  int v22; // edi
  const char *v23; // ebx
  const char *v24; // eax
  int v25; // edi
  const char *v26; // ebx
  const char *v27; // eax
  const char *fParama; // [esp+3Ch] [ebp+1Ch]
  const char *fParamb; // [esp+3Ch] [ebp+1Ch]

  switch ( iAction )
  {
    case 11:
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2) )
      {
        v8 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s] = [%s] ", pchVarName, v8);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f\n", fParam);
      }
      *fVar = fParam;
      return 1;
    case 12:
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2) )
      {
        v10 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s] += [%s] ", pchVarName, v10);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f\n", fParam);
      }
      *fVar = *fVar + fParam;
      return 1;
    case 13:
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2) )
      {
        v11 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s] -= [%s] ", pchVarName, v11);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f\n", fParam);
      }
      *fVar = *fVar - fParam;
      return 1;
    case 14:
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2) )
      {
        v12 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s] *= [%s] ", pchVarName, v12);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f\n", fParam);
      }
      *fVar = *fVar * fParam;
      return 1;
    case 15:
      LOBYTE(a2) = bNot;
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2) )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s] ", pchVarName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f ", *fVar);
        v13 = "!= [%s] ";
        if ( !bNot )
          v13 = "== [%s] ";
        v14 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v13, v14);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f\n", fParam);
      }
      if ( !bNot )
        return *fVar == fParam;
      return *fVar != fParam;
    case 16:
      LOBYTE(a2) = bNot;
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2) )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s] ", pchVarName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f ", *fVar);
        v15 = ">= [%s] ";
        if ( !bNot )
          v15 = "< [%s] ";
        v16 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v15, v16);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f\n", fParam);
      }
      if ( bNot )
        return *fVar >= fParam;
      return fParam > *fVar;
    case 18:
      v17 = (const char *)(int)*fVar;
      v18 = 1 << (int)fParam;
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2: v17) )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t([%s] ", pchVarName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "0x%X ", v17);
        v19 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "& [%s] ", v19);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "0x%X", v18);
        v20 = ") == 0\n";
        if ( !bNot )
          v20 = ") != 0\n";
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v20);
      }
      v21 = (unsigned int)v17 & v18;
      if ( bNot )
        return v21 == 0;
      else
        return v21 != 0;
    case 19:
      v22 = (int)fParam;
      v23 = (const char *)UTIL_CountNumBitsSet(nVar: (__int64)*fVar);
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2: v23) )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tUTIL_CountNumBitsSet([%s]) ", pchVarName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%i ", v23);
        fParama = " != [%s] ";
        if ( !bNot )
          fParama = " == [%s] ";
        v24 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: fParama, v24);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%i\n", v22);
      }
      if ( bNot )
        return v23 != (const char *)v22;
      else
        return v23 == (const char *)v22;
    case 20:
      v25 = (int)fParam;
      v26 = (const char *)UTIL_CountNumBitsSet(nVar: (__int64)*fVar);
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2: v26) )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tUTIL_CountNumBitsSet([%s]) ", pchVarName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%i ", v26);
        fParamb = " >= [%s] ";
        if ( !bNot )
          fParamb = " < [%s] ";
        v27 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: fParamb, v27);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%i\n", v25);
      }
      if ( bNot )
        return (int)v26 >= v25;
      else
        return (int)v26 < v25;
    default:
      DevWarning(a1: "Invalid lesson action type used with \"%s\" variable type.\n", pchVarName);
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B010
// Name: private: bool CScriptedIconLesson::ProcessElementAction(int,bool,char const __near *,int __near &,class CGameInstructorSymbol const __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CScriptedIconLesson::ProcessElementAction@<al>(
        CScriptedIconLesson *this@<ecx>,
        const char *a2@<ebx>,
        int iAction,
        bool bNot,
        const char *pchVarName,
        float iVar,
        CGameInstructorSymbol *pchParamName,
        float fParam)
{
  float v8; // esi
  char result; // al

  v8 = iVar;
  iVar = (float)(int)*(_DWORD *)LODWORD(iVar);
  result = CScriptedIconLesson::ProcessElementAction(
             this,
             a2,
             iAction,
             bNot,
             pchVarName,
             fVar: &iVar,
             pchParamName,
             fParam);
  *(_DWORD *)LODWORD(v8) = (int)iVar;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004B060
// Name: private: bool CScriptedIconLesson::ProcessElementAction(int,bool,char const __near *,bool __near &,class CGameInstructorSymbol const __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CScriptedIconLesson::ProcessElementAction@<al>(
        CScriptedIconLesson *this@<ecx>,
        const char *a2@<ebx>,
        int iAction,
        bool bNot,
        const char *pchVarName,
        bool *bVar,
        CGameInstructorSymbol *pchParamName,
        float fParam)
{
  bool *v8; // esi
  int v9; // xmm0_4
  char result; // al

  v8 = bVar;
  if ( *bVar )
    v9 = 1065353216;
  else
    v9 = 0;
  bVar = (bool *)v9;
  result = CScriptedIconLesson::ProcessElementAction(
             this,
             a2,
             iAction,
             bNot,
             pchVarName,
             fVar: (float *)&bVar,
             pchParamName,
             fParam);
  *v8 = *(float *)&bVar != 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004B0D0
// Name: private: bool CScriptedIconLesson::ProcessElementAction(int,bool,char const __near *,class CHandle<class C_BaseEntity> __near &,class CGameInstructorSymbol const __near *,float,class C_BaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CScriptedIconLesson::ProcessElementAction@<al>(
        CScriptedIconLesson *this@<ecx>,
        int a2@<ebp>,
        int iAction,
        bool bNot,
        const char *pchVarName,
        CHandle<C_BaseEntity> *hVar,
        CGameInstructorSymbol *pchParamName,
        __int64 fParam,
        const char *pchParam)
{
  const char *v9; // edi
  char result; // al
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // esi
  const char *v13; // eax
  const char *v14; // edi
  const char *v15; // eax
  C_BaseEntity *v16; // edi
  int v17; // eax
  int v18; // eax
  __int64 v19; // xmm0_8
  float v20; // eax
  int v21; // eax
  int v22; // eax
  __int64 v23; // xmm0_8
  float v24; // eax
  float y; // edi
  float v26; // xmm1_4
  __int128 v27; // xmm0
  C_BaseEntity *v28; // edi
  int v29; // eax
  int v30; // eax
  __int64 v31; // xmm0_8
  float v32; // eax
  int v33; // eax
  int v34; // eax
  __int64 v35; // xmm0_8
  float v36; // eax
  const Vector *v37; // eax
  float x; // edx
  const QAngle *v39; // eax
  CGameInstructorSymbol *v40; // edi
  void (*v41)(const struct Color *, const char *, ...); // esi
  const char *v42; // eax
  const char *v43; // eax
  const char *v44; // eax
  const char *v45; // eax
  const char *v46; // eax
  char *Classname; // eax
  const char *v48; // eax
  void (*v49)(const struct Color *, const char *, ...); // esi
  const char *v50; // edi
  const char *v51; // eax
  int v52; // eax
  const char *v53; // eax
  int v54; // eax
  int v55; // edx
  C_BaseAnimating *v56; // eax
  const char *v57; // eax
  const char *v58; // eax
  const char *name; // esi
  CStudioHdr *ModelPtr; // eax
  const studiohdr_t *m_pStudioHdr; // eax
  const char *v62; // eax
  const char *v63; // eax
  int v64; // eax
  int v65; // eax
  const char *v66; // eax
  int v67; // eax
  int v68; // edx
  const char *v69; // edi
  const char *v70; // eax
  double v71; // st7
  const char *v72; // eax
  int v73; // eax
  void (*v74)(const struct Color *, const char *, ...); // esi
  const C_BaseEntity *v75; // eax
  int v76; // eax
  const char *v77; // eax
  const char *v78; // esi
  const char *v79; // eax
  const char *v80; // eax
  const char *v81; // eax
  const char *v82; // eax
  float v83; // esi
  const char *v84; // esi
  const char *v85; // eax
  void (*v86)(const struct Color *, const char *, ...); // esi
  const char *v87; // esi
  const char *v88; // eax
  int v89; // eax
  int v90; // eax
  int v91; // eax
  float v92; // edi
  int v93; // eax
  const char *v94; // eax
  int v95; // eax
  float v96; // xmm0_4
  float v97; // ecx
  const char *v98; // eax
  int v99; // edi
  int v100; // eax
  const char *v101; // eax
  const C_BaseEntity *v102; // eax
  const char *v103; // eax
  int v104; // eax
  const char *v105; // edi
  const char *v106; // eax
  int v107; // eax
  int *v108; // esi
  const char *v109; // edi
  const char *v110; // eax
  unsigned __int8 (__thiscall *v111)(int *); // eax
  int (__thiscall *v112)(int *); // eax
  const char *v113; // xmm0_4
  const char *v114; // edi
  const char *v115; // eax
  C_CSPlayer *v116; // esi
  const char *v117; // eax
  int v118; // eax
  int v119; // edi
  const char *v120; // eax
  int v121; // edi
  CCSAmmoDef *AmmoDef; // eax
  float v123; // eax
  C_CSPlayer_vtbl *v124; // edx
  C_BaseCombatCharacter *v125; // eax
  bool v126; // al
  const char *v127; // eax
  const char *v128; // eax
  C_CSPlayer *v129; // edi
  const char *v130; // eax
  int v131; // eax
  int v132; // esi
  const char *v133; // eax
  int v134; // esi
  CCSAmmoDef *v135; // eax
  float v136; // eax
  C_CSPlayer_vtbl *v137; // edx
  C_BaseCombatCharacter *v138; // eax
  const char *v139; // eax
  void (*v140)(const struct Color *, const char *, ...); // esi
  const char *v141; // eax
  C_CSPlayer *v142; // edi
  const char *v143; // eax
  int v144; // eax
  int v145; // esi
  const char *v146; // eax
  int v147; // eax
  C_BaseCombatCharacter *v148; // eax
  const char *v149; // eax
  const char *v150; // eax
  C_BaseCombatWeapon *v151; // edi
  C_CSPlayer *v152; // eax
  const char *v153; // esi
  const char *v154; // eax
  const char *v155; // esi
  const char *v156; // eax
  const char *v157; // esi
  const char *v158; // eax
  C_CSPlayer *v159; // esi
  const char *v160; // esi
  const char *v161; // edi
  const char *v162; // eax
  IClientEntity *v163; // eax
  C_BaseEntity *v164; // eax
  CHandle<C_BaseEntity> *v165; // edi
  C_CSPlayer *v166; // eax
  IClientEntity *v167; // eax
  const C_BaseEntity *v168; // eax
  CHandle<C_BaseEntity> *v169; // edi
  C_CSPlayer *v170; // eax
  IClientEntity *v171; // eax
  const C_BaseEntity *v172; // eax
  const char *v173; // [esp+4h] [ebp-A8h]
  const char *v174; // [esp+4h] [ebp-A8h]
  const char *v175; // [esp+4h] [ebp-A8h]
  const char *v176; // [esp+8h] [ebp-A4h]
  const char *v177; // [esp+8h] [ebp-A4h]
  float v178; // [esp+8h] [ebp-A4h]
  const char *v179; // [esp+Ch] [ebp-A0h]
  const char *v180; // [esp+Ch] [ebp-A0h]
  const char *v181; // [esp+Ch] [ebp-A0h]
  int v182; // [esp+20h] [ebp-8Ch] BYREF
  int v183; // [esp+2Ch] [ebp-80h] BYREF
  int v184; // [esp+38h] [ebp-74h] BYREF
  int v185; // [esp+44h] [ebp-68h] BYREF
  __int128 v186; // [esp+50h] [ebp-5Ch] BYREF
  __int64 v187; // [esp+6Ch] [ebp-40h]
  float v188; // [esp+74h] [ebp-38h]
  Vector vVarPos; // [esp+78h] [ebp-34h]
  Vector vParamPos; // [esp+84h] [ebp-28h] BYREF
  Vector vVarToParam; // [esp+90h] [ebp-1Ch] BYREF
  const char *pchParamNameTemp; // [esp+9Ch] [ebp-10h] BYREF
  int v193; // [esp+A0h] [ebp-Ch]
  void *v194; // [esp+A4h] [ebp-8h] OVERLAPPED
  char bAmmoLow[3]; // [esp+A8h] [ebp-4h] BYREF
  void *retaddr; // [esp+ACh] [ebp+0h]

  v193 = a2;
  v194 = retaddr;
  LODWORD(vVarToParam.y) = this;
  v9 = pchParam;
  HIBYTE(vVarToParam.z) = 0;
  result = CScriptedIconLesson::Mod_ProcessElementAction(
             this,
             iAction,
             bNot,
             pchVarName,
             hVar,
             pchParamName,
             fParam: *(float *)&fParam,
             pParam: (C_BaseEntity *)HIDWORD(fParam),
             pchParam,
             bModHandled: (bool *)&vVarToParam.z + 3);
  if ( HIBYTE(vVarToParam.z) == 0 )
  {
    m_Index = hVar->m_Index;
    if ( hVar->m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    switch ( iAction )
    {
      case 11:
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          v13 = CGameInstructorSymbol::String(this: pchParamName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s] = [%s]\n", pchVarName, v13);
        }
        CHandle<C_ViewmodelAttachmentModel>::operator=(this: hVar, val: (const C_BaseEntity *)HIDWORD(fParam));
        return 1;
      case 15:
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          v14 = "\t[%s] != [%s]\n";
          if ( !bNot )
            v14 = "\t[%s] == [%s]\n";
          v15 = CGameInstructorSymbol::String(this: pchParamName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v14, pchVarName, v15);
        }
        if ( bNot )
          return m_pEntity != (C_BaseEntity *)HIDWORD(fParam);
        else
          return m_pEntity == (C_BaseEntity *)HIDWORD(fParam);
      case 21:
        if ( m_pEntity != nullptr && HIDWORD(fParam) != 0 )
        {
          v16 = m_pEntity->IsPlayer(this: m_pEntity) ? m_pEntity : nullptr;
          LODWORD(vVarToParam.x) = (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(fParam) + 584))(a1: HIDWORD(fParam)) != 0
                                 ? HIDWORD(fParam)
                                 : 0;
          if ( v16 != nullptr )
          {
            v17 = (int)v16->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].WorldAlignMaxs(this: v16);
            v18 = (*(int (__thiscall **)(int, int *))(*(_DWORD *)v17 + 624))(a1: v17, a2: &v185);
          }
          else
          {
            v18 = (int)m_pEntity->WorldSpaceCenter(this: m_pEntity);
          }
          v19 = *(_QWORD *)v18;
          v20 = *(float *)(v18 + 8);
          *(_QWORD *)&vParamPos.x = v19;
          vParamPos.z = v20;
          if ( LODWORD(vVarToParam.x) != 0 )
          {
            v21 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(vVarToParam.x) + 984))(a1: LODWORD(vVarToParam.x));
            v22 = (*(int (__thiscall **)(int, int *))(*(_DWORD *)v21 + 624))(a1: v21, a2: &v184);
          }
          else
          {
            v22 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(fParam) + 300))(a1: HIDWORD(fParam));
          }
          v23 = *(_QWORD *)v22;
          v24 = *(float *)(v22 + 8);
          y = vVarToParam.y;
          *(_QWORD *)&vVarPos.x = v23;
          vVarPos.z = v24;
          v26 = (float)((float)((float)(vParamPos.y - *((float *)&v23 + 1)) * (float)(vParamPos.y - *((float *)&v23 + 1)))
                      + (float)((float)(vParamPos.z - vVarPos.z) * (float)(vParamPos.z - vVarPos.z)))
              + (float)((float)(vParamPos.x - *(float *)&v23) * (float)(vParamPos.x - *(float *)&v23));
          v27 = 0;
          *(float *)&v27 = fsqrt(v26);
          v186 = v27;
          *(_DWORD *)(LODWORD(vVarToParam.y) + 300) = v27;
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(y), a2: bAmmoLow) )
          {
            LODWORD(vVarToParam.z) = CGameInstructorSymbol::String(this: pchParamName);
            LODWORD(vVarToParam.y) = pchVarName;
            LODWORD(vVarToParam.x) = "\t[output] = [%s]->DistTo( [%s] ) ";
            goto LABEL_33;
          }
          return 1;
        }
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          v179 = CGameInstructorSymbol::String(this: pchParamName);
          v176 = pchVarName;
          v173 = "\t[output] = [%s]->DistTo( [%s] )";
          goto LABEL_39;
        }
        goto LABEL_449;
      case 22:
        if ( m_pEntity != nullptr && HIDWORD(fParam) != 0 )
        {
          v28 = m_pEntity->IsPlayer(this: m_pEntity) ? m_pEntity : nullptr;
          LODWORD(vVarToParam.x) = (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(fParam) + 584))(a1: HIDWORD(fParam)) != 0
                                 ? HIDWORD(fParam)
                                 : 0;
          if ( v28 != nullptr )
          {
            v29 = (int)v28->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].WorldAlignMaxs(this: v28);
            v30 = (*(int (__thiscall **)(int, int *))(*(_DWORD *)v29 + 624))(a1: v29, a2: &v183);
          }
          else
          {
            v30 = (int)m_pEntity->WorldSpaceCenter(this: m_pEntity);
          }
          v31 = *(_QWORD *)v30;
          v32 = *(float *)(v30 + 8);
          v187 = v31;
          v188 = v32;
          if ( LODWORD(vVarToParam.x) != 0 )
          {
            v33 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(vVarToParam.x) + 984))(a1: LODWORD(vVarToParam.x));
            v34 = (*(int (__thiscall **)(int, int *))(*(_DWORD *)v33 + 624))(a1: v33, a2: &v182);
          }
          else
          {
            v34 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(fParam) + 300))(a1: HIDWORD(fParam));
          }
          v35 = *(_QWORD *)v34;
          v36 = *(float *)(v34 + 8);
          *(_QWORD *)&vVarPos.x = v35;
          vParamPos.x = *(float *)&v35 - *(float *)&v187;
          vParamPos.y = *((float *)&v35 + 1) - *((float *)&v187 + 1);
          vVarPos.z = v36;
          vParamPos.z = v36 - v188;
          VectorNormalize(vec: &vParamPos);
          if ( m_pEntity->IsPlayer(this: m_pEntity) )
          {
            v37 = m_pEntity->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].WorldAlignMaxs(this: m_pEntity);
            x = v37->x;
            vVarToParam.z = 0.0;
            vVarToParam.y = 0.0;
            LODWORD(vVarToParam.x) = (char *)&v186 + 4;
            v39 = (const QAngle *)(*(int (__thiscall **)(const Vector *))(LODWORD(x) + 628))(a1: v37);
            AngleVectors(
              angles: v39,
              forward: (Vector *)LODWORD(vVarToParam.x),
              right: (Vector *)LODWORD(vVarToParam.y),
              up: (Vector *)LODWORD(vVarToParam.z));
          }
          else
          {
            C_BaseEntity::GetVectors(
              this: m_pEntity,
              pForward: (Vector *)((char *)&v186 + 4),
              pRight: nullptr,
              pUp: nullptr);
          }
          y = vVarToParam.y;
          *(float *)(LODWORD(vVarToParam.y) + 300) = (float)((float)((float)((float)(*((float *)&v186 + 2) * vParamPos.y)
                                                                           + (float)(vParamPos.x * *((float *)&v186 + 1)))
                                                                   + (float)(*((float *)&v186 + 3) * vParamPos.z))
                                                           - 1.0)
                                                   * -90.0;
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(y), a2: bAmmoLow) )
          {
            LODWORD(vVarToParam.z) = CGameInstructorSymbol::String(this: pchParamName);
            LODWORD(vVarToParam.y) = pchVarName;
            LODWORD(vVarToParam.x) = "\t[output] = [%s]->AngularDistTo( [%s] ) ";
LABEL_33:
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: (const char *)LODWORD(vVarToParam.x));
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f\n", *(float *)(LODWORD(y) + 300));
          }
          return 1;
        }
        if ( gameinstructor_verbose.m_pParent == nullptr
          || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
          || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          goto LABEL_449;
        }
        v179 = CGameInstructorSymbol::String(this: pchParamName);
        v176 = pchVarName;
        v173 = "\t[output] = [%s]->AngularDistTo( [%s] )";
LABEL_39:
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v173, v176, v179);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "...\n");
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle or Param handle returned NULL!\n");
        return 0;
      case 23:
        if ( (unsigned int)((int)*(float *)&fParam - 1) > 1 )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            ConColorMsg(
              a1: &CBaseLesson::m_rgbaVerbosePlain,
              a2: "\tQ_strcpy( [stringINVALID], [%s]->GetPlayerName() ",
              pchVarName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "... ");
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")\n");
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tParam selecting string is out of range!\n");
            return 0;
          }
          goto LABEL_449;
        }
        if ( (int)*(float *)&fParam == 2 )
        {
          v40 = (CGameInstructorSymbol *)(LODWORD(vVarToParam.y) + 314);
          LODWORD(vVarToParam.x) = "string2";
        }
        else
        {
          v40 = (CGameInstructorSymbol *)(LODWORD(vVarToParam.y) + 312);
          LODWORD(vVarToParam.x) = "string1";
        }
        if ( m_pEntity == nullptr )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            v41 = ConColorMsg;
            ConColorMsg(
              a1: &CBaseLesson::m_rgbaVerbosePlain,
              a2: "\tQ_strcpy( [%s], [%s]->GetPlayerName() ",
              (const char *)LODWORD(vVarToParam.x),
              pchVarName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "... ");
            goto LABEL_69;
          }
          goto LABEL_449;
        }
        v42 = m_pEntity->GetPlayerName(this: m_pEntity);
        CGameInstructorSymbol::CGameInstructorSymbol(this: (CGameInstructorSymbol *)&pchParamNameTemp + 1, pStr: v42);
        v40->m_SymbolId.m_Id = *(_WORD *)((unsigned __int16)&pchParamNameTemp + 2);
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          ConColorMsg(
            a1: &CBaseLesson::m_rgbaVerbosePlain,
            a2: "\tQ_strcpy( [%s], [%s]->GetPlayerName() ",
            (const char *)LODWORD(vVarToParam.x),
            pchVarName);
          v43 = CGameInstructorSymbol::String(this: v40);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\" ", v43);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")\n");
          return 1;
        }
        return 1;
      case 24:
        if ( m_pEntity != nullptr )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            v46 = "\t!FClassnameIs( [%s] ";
            if ( !bNot )
              v46 = "\tFClassnameIs( [%s] ";
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v46, pchVarName);
            Classname = C_BaseEntity::GetClassname(this: m_pEntity);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%s", Classname);
            v48 = CGameInstructorSymbol::String(this: pchParamName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ", [%s] ", v48);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\" ", pchParam);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")\n");
            v9 = pchParam;
          }
          result = FClassnameIs(pEntity: m_pEntity, szClassname: v9);
          if ( bNot )
            return result == 0;
          return result;
        }
        if ( gameinstructor_verbose.m_pParent == nullptr
          || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
          || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          goto LABEL_449;
        }
        v44 = "\t!FClassnameIs( [%s] ";
        if ( !bNot )
          v44 = "\tFClassnameIs( [%s] ";
        v41 = ConColorMsg;
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v44, pchVarName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "...");
        v45 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ", [%s] ", v45);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\" ", pchParam);
LABEL_69:
        v41(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")\n");
        v41(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle returned NULL!\n");
        return 0;
      case 25:
        v56 = (C_BaseAnimating *)__RTDynamicCast(
                                   inptr: m_pEntity,
                                   VfDelta: 0,
                                   SrcType: &C_BaseEntity `RTTI Type Descriptor',
                                   TargetType: &C_BaseAnimating `RTTI Type Descriptor',
                                   isReference: 0);
        if ( v56 == nullptr )
        {
          if ( gameinstructor_verbose.m_pParent == nullptr
            || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
            || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            goto LABEL_449;
          }
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tQ_stricmp( [%s]->ModelName() ", pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "...");
          v57 = CGameInstructorSymbol::String(this: pchParamName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ", [%s] ", v57);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\" ", pchParam);
          v58 = ") != 0\n";
          if ( !bNot )
            v58 = ") == 0\n";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v58);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle as BaseAnimating returned NULL!\n");
          return 0;
        }
        name = "-no model-";
        LODWORD(vVarToParam.x) = "-no model-";
        ModelPtr = C_BaseAnimating::GetModelPtr(this: v56);
        if ( ModelPtr != nullptr )
        {
          m_pStudioHdr = ModelPtr->m_pStudioHdr;
          if ( m_pStudioHdr != nullptr )
          {
            name = m_pStudioHdr->name;
            LODWORD(vVarToParam.x) = m_pStudioHdr->name;
          }
        }
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tQ_stricmp( [%s]->ModelName() ", pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%s", (const char *)LODWORD(vVarToParam.x));
          v62 = CGameInstructorSymbol::String(this: pchParamName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ", [%s] ", v62);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\" ", pchParam);
          v63 = ") != 0\n";
          if ( !bNot )
            v63 = ") == 0\n";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v63);
          name = (const char *)LODWORD(vVarToParam.x);
        }
        v64 = _V_stricmp(s1: name, s2: pchParam);
        if ( bNot )
          return v64 != 0;
        return v64 == 0;
      case 26:
        if ( m_pEntity != nullptr )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->GetTeamNumber() ", pchVarName);
            v52 = m_pEntity->GetTeamNumber(this: m_pEntity);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%i ", v52);
            LODWORD(vVarToParam.x) = "!= [%s] ";
            if ( !bNot )
              LODWORD(vVarToParam.x) = "== [%s] ";
            v53 = CGameInstructorSymbol::String(this: pchParamName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: (const char *)LODWORD(vVarToParam.x), v53);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%i\n", (int)*(float *)&fParam);
          }
          v54 = m_pEntity->GetTeamNumber(this: m_pEntity);
          v55 = (int)*(float *)&fParam;
          if ( bNot )
            return v54 != v55;
          else
            return v54 == v55;
        }
        if ( gameinstructor_verbose.m_pParent == nullptr
          || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
          || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          goto LABEL_449;
        }
        v49 = ConColorMsg;
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->GetTeamNumber() ", pchVarName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "... ");
        v50 = "!= [%s] ";
        if ( !bNot )
          v50 = "== [%s] ";
        goto LABEL_101;
      case 27:
        if ( m_pEntity != nullptr )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->GetHealth() ", pchVarName);
            v65 = m_pEntity->GetHealth(this: m_pEntity);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%i ", v65);
            LODWORD(vVarToParam.x) = ">= [%s] ";
            if ( !bNot )
              LODWORD(vVarToParam.x) = "< [%s] ";
            v66 = CGameInstructorSymbol::String(this: pchParamName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: (const char *)LODWORD(vVarToParam.x), v66);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%i\n", (int)*(float *)&fParam);
          }
          v67 = m_pEntity->GetHealth(this: m_pEntity);
          v68 = (int)*(float *)&fParam;
          if ( bNot )
            return v67 >= v68;
          else
            return v67 < v68;
        }
        if ( gameinstructor_verbose.m_pParent == nullptr
          || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
          || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          goto LABEL_449;
        }
        v49 = ConColorMsg;
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->GetHealth() ", pchVarName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "... ");
        v50 = ">= [%s] ";
        if ( !bNot )
          v50 = "< [%s] ";
LABEL_101:
        v51 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v50, v51);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%i\n", (int)*(float *)&fParam);
        v49(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle returned NULL!\n");
        return 0;
      case 28:
        if ( m_pEntity != nullptr )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->HealthFraction() ", pchVarName);
            v71 = C_BaseEntity::HealthFraction(this: m_pEntity);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f ", v71);
            LODWORD(vVarToParam.x) = ">= [%s] ";
            if ( !bNot )
              LODWORD(vVarToParam.x) = "< [%s] ";
            v72 = CGameInstructorSymbol::String(this: pchParamName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: (const char *)LODWORD(vVarToParam.x), v72);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f\n", *(float *)&fParam);
          }
          if ( (float)m_pEntity->GetMaxHealth(this: m_pEntity) != 0.0 )
            vVarToParam.x = C_BaseEntity::HealthFraction(this: m_pEntity);
          if ( bNot )
          {
            if ( vVarToParam.x < *(float *)&fParam )
              return 0;
          }
          else if ( *(float *)&fParam <= vVarToParam.x )
          {
            return 0;
          }
          return 1;
        }
        else
        {
          if ( gameinstructor_verbose.m_pParent == nullptr
            || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
            || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            goto LABEL_449;
          }
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->HealthFraction() ", pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "... ");
          v69 = ">= [%s] ";
          if ( !bNot )
            v69 = "< [%s] ";
          v70 = CGameInstructorSymbol::String(this: pchParamName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v69, v70);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f\n", *(float *)&fParam);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle returned NULL!\n");
          return 0;
        }
      case 29:
        if ( (unsigned int)((int)*(float *)&fParam - 1) > 1 )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            v180 = pchVarName;
            v177 = "\t[entityINVALID] = [%s]->GetActiveWeapon()\n";
            goto LABEL_185;
          }
          goto LABEL_449;
        }
        if ( (int)*(float *)&fParam == 2 )
        {
          pchParamNameTemp = (const char *)(LODWORD(vVarToParam.y) + 308);
          LODWORD(vVarToParam.x) = "entity2";
        }
        else
        {
          pchParamNameTemp = (const char *)(LODWORD(vVarToParam.y) + 304);
          LODWORD(vVarToParam.x) = "entity1";
        }
        if ( m_pEntity == nullptr || (v73 = (int)m_pEntity->MyCombatCharacterPointer(this: m_pEntity)) == 0 )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            v74 = ConColorMsg;
            ConColorMsg(
              a1: &CBaseLesson::m_rgbaVerbosePlain,
              a2: "\t[%s] = [%s]->GetActiveWeapon()",
              vVarToParam.x,
              pchVarName);
            goto LABEL_175;
          }
          goto LABEL_449;
        }
        v75 = (const C_BaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v73 + 948))(a1: v73);
        CHandle<C_BaseEntity>::Set(this: (CHandle<C_BaseEntity> *)pchParamNameTemp, pVal: v75);
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          ConColorMsg(
            a1: &CBaseLesson::m_rgbaVerbosePlain,
            a2: "\t[%s] = [%s]->GetActiveWeapon()",
            (const char *)LODWORD(vVarToParam.x),
            pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"\n", pchParam);
          return 1;
        }
        return 1;
      case 30:
        if ( m_pEntity != nullptr && (v76 = (int)m_pEntity->MyCombatCharacterPointer(this: m_pEntity)) != 0 )
        {
          *(float *)&v78 = COERCE_FLOAT((*(int (__thiscall **)(int))(*(_DWORD *)v76 + 948))(a1: v76));
          pchParamNameTemp = v78;
          if ( *(float *)&v78 != 0.0 )
          {
            if ( gameinstructor_verbose.m_pParent != nullptr
              && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
              && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
            {
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->GetActiveWeapon()->GetName() ", pchVarName);
              v80 = (const char *)(*(int (__thiscall **)(const char *))(*(_DWORD *)pchParamNameTemp + 1296))(a1: pchParamNameTemp);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\" ", v80);
              LODWORD(vVarToParam.x) = "!= [%s] ";
              if ( !bNot )
                LODWORD(vVarToParam.x) = "== [%s] ";
              v81 = CGameInstructorSymbol::String(this: pchParamName);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: (const char *)LODWORD(vVarToParam.x), v81);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"\n", pchParam);
              v78 = pchParamNameTemp;
            }
            v82 = (const char *)(*(int (__thiscall **)(const char *))(*(_DWORD *)v78 + 1296))(a1: v78);
            v64 = _V_stricmp(s1: v82, s2: pchParam);
            if ( bNot )
              return v64 != 0;
            else
              return v64 == 0;
          }
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->GetActiveWeapon()->GetName() ", pchVarName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "... ");
            LODWORD(vVarToParam.x) = "!= [%s] ";
            if ( !bNot )
              LODWORD(vVarToParam.x) = "== [%s] ";
            v79 = CGameInstructorSymbol::String(this: pchParamName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: (const char *)LODWORD(vVarToParam.x), v79);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"\n", pchParam);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar GetActiveWeapon returned NULL!\n");
            return 0;
          }
        }
        else if ( gameinstructor_verbose.m_pParent != nullptr
               && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
               && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->GetActiveWeapon()->GetName() ", pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "... ");
          LODWORD(vVarToParam.x) = "!= [%s] ";
          if ( !bNot )
            LODWORD(vVarToParam.x) = "== [%s] ";
          v77 = CGameInstructorSymbol::String(this: pchParamName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: (const char *)LODWORD(vVarToParam.x), v77);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"\n", pchParam);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle as BaseCombatCharacter returned NULL!\n");
          return 0;
        }
        goto LABEL_449;
      case 31:
        if ( m_pEntity != nullptr )
        {
          v83 = COERCE_FLOAT((int)m_pEntity->MyCombatCharacterPointer(this: m_pEntity));
          vVarToParam.x = v83;
          if ( v83 != 0.0 )
          {
            if ( gameinstructor_verbose.m_pParent != nullptr
              && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
              && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
            {
              v87 = "\t![%s]->Weapon_OwnsThisType([%s] ";
              if ( !bNot )
                v87 = "\t[%s]->Weapon_OwnsThisType([%s] ";
              v88 = CGameInstructorSymbol::String(this: pchParamName);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v87, pchVarName, v88);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"", pchParam);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")\n");
              v83 = vVarToParam.x;
            }
            v64 = (*(int (__thiscall **)(float, const char *, _DWORD))(*(_DWORD *)LODWORD(v83) + 932))(
                    a1: COERCE_FLOAT(LODWORD(v83)),
                    a2: pchParam,
                    a3: 0);
            if ( bNot )
              return v64 == 0;
            return v64 != 0;
          }
        }
        if ( gameinstructor_verbose.m_pParent == nullptr
          || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
          || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          goto LABEL_449;
        }
        v84 = "\t![%s]->Weapon_OwnsThisType([%s] ";
        if ( !bNot )
          v84 = "\t[%s]->Weapon_OwnsThisType([%s] ";
        v85 = CGameInstructorSymbol::String(this: pchParamName);
        v174 = v84;
        v86 = ConColorMsg;
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v174, pchVarName, v85);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"", pchParam);
        goto LABEL_217;
      case 32:
        if ( m_pEntity != nullptr && (v89 = (int)m_pEntity->MyCombatCharacterPointer(this: m_pEntity)) != 0 )
        {
          v90 = (*(int (__thiscall **)(int))(*(_DWORD *)v89 + 948))(a1: v89);
          if ( v90 != 0 )
          {
            v91 = (*(int (__thiscall **)(int))(*(_DWORD *)v90 + 1288))(a1: v90);
            v92 = vVarToParam.y;
            *(float *)(LODWORD(vVarToParam.y) + 300) = (float)v91;
            if ( gameinstructor_verbose.m_pParent != nullptr
              && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
              && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(v92), a2: bAmmoLow) )
            {
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[output] = [%s]->Weapon_GetSlot() ", pchVarName);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f\n", *(float *)(LODWORD(v92) + 300));
            }
            return 1;
          }
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            ConColorMsg(
              a1: &CBaseLesson::m_rgbaVerbosePlain,
              a2: "\t[output] = [%s]->Weapon_GetActiveSlot() ...\n",
              pchVarName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar GetActiveWeapon returned NULL!\n");
            return 0;
          }
        }
        else if ( gameinstructor_verbose.m_pParent != nullptr
               && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
               && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          ConColorMsg(
            a1: &CBaseLesson::m_rgbaVerbosePlain,
            a2: "\t[output] = [%s]->Weapon_GetActiveSlot() ...\n",
            pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle as BaseCombatCharacter returned NULL!\n");
          return 0;
        }
        goto LABEL_449;
      case 33:
        if ( m_pEntity != nullptr )
        {
          v93 = (int)m_pEntity->MyCombatCharacterPointer(this: m_pEntity);
          if ( v93 != 0 )
          {
            v95 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v93 + 932))(
                    a1: v93,
                    a2: pchParam,
                    a3: 0);
            if ( v95 != 0 )
              v96 = (float)(*(int (__thiscall **)(int))(*(_DWORD *)v95 + 1288))(a1: v95);
            else
              v96 = 0.0;
            v97 = vVarToParam.y;
            *(float *)(LODWORD(vVarToParam.y) + 300) = v96;
            if ( gameinstructor_verbose.m_pParent != nullptr
              && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
              && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(v97), a2: bAmmoLow) )
            {
              v98 = CGameInstructorSymbol::String(this: pchParamName);
              ConColorMsg(
                a1: &CBaseLesson::m_rgbaVerbosePlain,
                a2: "\t[output] = [%s]->Weapon_GetSlot([%s] ",
                pchVarName,
                v98);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"", pchParam);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ") ");
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%f\n", *(float *)(LODWORD(vVarToParam.y) + 300));
            }
            return 1;
          }
        }
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          v94 = CGameInstructorSymbol::String(this: pchParamName);
          v86 = ConColorMsg;
          ConColorMsg(
            a1: &CBaseLesson::m_rgbaVerbosePlain,
            a2: "\t[output] = [%s]->Weapon_GetSlot([%s] ",
            pchVarName,
            v94);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"", pchParam);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ") ...\n");
          goto LABEL_218;
        }
        goto LABEL_449;
      case 34:
        v99 = (int)*(float *)&fParam;
        if ( m_pEntity != nullptr )
        {
          v100 = (int)m_pEntity->MyCombatCharacterPointer(this: m_pEntity);
          if ( v100 != 0 )
          {
            v102 = (const C_BaseEntity *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v100 + 952))(a1: v100, a2: v99);
            CHandle<C_ViewmodelAttachmentModel>::operator=(
              this: (CHandle<C_BaseEntity> *)(LODWORD(vVarToParam.y) + 304),
              val: v102);
            if ( gameinstructor_verbose.m_pParent != nullptr
              && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
              && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
            {
              v103 = CGameInstructorSymbol::String(this: pchParamName);
              ConColorMsg(
                a1: &CBaseLesson::m_rgbaVerbosePlain,
                a2: "\t[entity1] = [%s]->GetWeapon([%s] ",
                pchVarName,
                v103);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%i\"", v99);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")\n");
              return 1;
            }
            return 1;
          }
        }
        if ( gameinstructor_verbose.m_pParent == nullptr
          || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
          || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          goto LABEL_449;
        }
        v101 = CGameInstructorSymbol::String(this: pchParamName);
        v86 = ConColorMsg;
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[entity1] = [%s]->GetWeapon([%s] ", pchVarName, v101);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%i\"", v99);
LABEL_217:
        v86(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")\n");
LABEL_218:
        v86(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle as BaseCombatCharacter returned NULL!\n");
        return 0;
      case 35:
        if ( m_pEntity != nullptr && (v104 = (int)m_pEntity->MyCombatCharacterPointer(this: m_pEntity)) != 0 )
        {
          v107 = (*(int (__thiscall **)(int))(*(_DWORD *)v104 + 948))(a1: v104);
          v108 = (int *)v107;
          if ( v107 != 0 )
          {
            v111 = *(unsigned __int8 (__thiscall **)(int *))(*(_DWORD *)v107 + 1312);
            *(float *)&pchParamNameTemp = 100.0;
            if ( v111(a1: v108) != 0 )
            {
              v112 = *(int (__thiscall **)(int *))(*v108 + 1256);
              vVarToParam.x = (float)v108[823];
              *(float *)&v113 = (float)(vVarToParam.x / (float)v112(a1: v108)) * 100.0;
              pchParamNameTemp = v113;
            }
            else
            {
              v113 = pchParamNameTemp;
            }
            if ( gameinstructor_verbose.m_pParent != nullptr && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0 )
            {
              if ( CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
              {
                ConColorMsg(
                  a1: &CBaseLesson::m_rgbaVerbosePlain,
                  a2: "\t[%s]->GetActiveWeapon()->Clip1Percentage() ",
                  pchVarName);
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%.1f ", *(float *)&pchParamNameTemp);
                v114 = ">= [%s] ";
                if ( !bNot )
                  v114 = "< [%s] ";
                v115 = CGameInstructorSymbol::String(this: pchParamName);
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v114, v115);
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%.1f\n", *(float *)&fParam);
              }
              v113 = pchParamNameTemp;
            }
            if ( bNot )
            {
              if ( *(float *)&v113 >= *(float *)&fParam )
                return 1;
            }
            else if ( *(float *)&fParam > *(float *)&v113 )
            {
              return 1;
            }
            return 0;
          }
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            ConColorMsg(
              a1: &CBaseLesson::m_rgbaVerbosePlain,
              a2: "\t[%s]->GetActiveWeapon()->Clip1Percentage() ",
              pchVarName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "... ");
            v109 = ">= [%s] ";
            if ( !bNot )
              v109 = "< [%s] ";
            v110 = CGameInstructorSymbol::String(this: pchParamName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v109, v110);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%.1f\n", *(float *)&fParam);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar GetActiveWeapon returned NULL!\n");
            return 0;
          }
        }
        else if ( gameinstructor_verbose.m_pParent != nullptr
               && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
               && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          v74 = ConColorMsg;
          ConColorMsg(
            a1: &CBaseLesson::m_rgbaVerbosePlain,
            a2: "\t[%s]->GetActiveWeapon()->Clip1Percentage() ",
            pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "... ");
          v105 = ">= [%s] ";
          if ( !bNot )
            v105 = "< [%s] ";
          v106 = CGameInstructorSymbol::String(this: pchParamName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v105, v106);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%.1f\n", *(float *)&fParam);
LABEL_175:
          v74(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle as BaseCombatCharacter returned NULL!\n");
          return 0;
        }
LABEL_449:
        result = 0;
        break;
      case 36:
        v116 = ToBasePlayer(pEntity: m_pEntity);
        if ( v116 != nullptr )
        {
          vVarToParam.x = 0.0;
          do
          {
            v118 = (int)v116->ActivePlayerCombatCharacter(this: v116);
            v119 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v118 + 952))(a1: v118, a2: LODWORD(vVarToParam.x));
            if ( v119 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v119 + 1288))(a1: v119) == (int)*(float *)&fParam )
            {
              v121 = (*(int (__thiscall **)(int))(*(_DWORD *)v119 + 1328))(a1: v119);
              AmmoDef = GetAmmoDef();
              v123 = COERCE_FLOAT(CAmmoDef::MaxCarry(this: AmmoDef, nAmmoIndex: v121, owner: v116));
              v124 = v116->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
              vVarToParam.x = v123;
              v125 = (C_BaseCombatCharacter *)((int (__thiscall *)(C_CSPlayer *, int))v124->ActivePlayerCombatCharacter)(
                                                a1: v116,
                                                a2: v121);
              v126 = C_BaseCombatCharacter::GetAmmoCount(this: v125, iAmmoIndex: SLODWORD(vVarToParam.z)) < SLODWORD(vVarToParam.x) / 3;
              HIBYTE(pchParamNameTemp) = v126;
              if ( bNot )
                HIBYTE(pchParamNameTemp) = !v126;
              if ( gameinstructor_verbose.m_pParent != nullptr
                && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
                && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
              {
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->GetWeaponInSlot( ", pchVarName);
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%i ", (int)*(float *)&fParam);
                v127 = ")->AmmoPercentage() >= 30 ";
                if ( !bNot )
                  v127 = ")->AmmoPercentage() < 30 ";
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v127);
                v128 = "true\n";
                if ( HIBYTE(pchParamNameTemp) == 0 )
                  v128 = "false\n";
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v128);
              }
              return HIBYTE(pchParamNameTemp);
            }
            ++LODWORD(vVarToParam.x);
          }
          while ( SLODWORD(vVarToParam.x) < 64 );
          if ( gameinstructor_verbose.m_pParent == nullptr
            || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
            || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            goto LABEL_449;
          }
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->GetWeaponInSlot( ", pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%i ", (int)*(float *)&fParam);
          v120 = ")->AmmoPercentage() >= 30\n";
          if ( !bNot )
            v120 = ")->AmmoPercentage() < 30\n";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v120);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar GetActiveWeapon returned NULL!\n");
          return 0;
        }
        else
        {
          if ( gameinstructor_verbose.m_pParent == nullptr
            || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
            || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            goto LABEL_449;
          }
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t[%s]->GetWeaponInSlot( ", pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%i ", (int)*(float *)&fParam);
          v117 = ")->AmmoPercentage() >= 30\n";
          if ( !bNot )
            v117 = ")->AmmoPercentage() < 30\n";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v117);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle as BasePlayer returned NULL!\n");
          return 0;
        }
      case 37:
        v129 = ToBasePlayer(pEntity: m_pEntity);
        if ( v129 == nullptr )
        {
          if ( gameinstructor_verbose.m_pParent == nullptr
            || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
            || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            goto LABEL_449;
          }
          v130 = "\t![%s]->GetWeaponInSlot( ";
          if ( !bNot )
            v130 = "\t[%s]->GetWeaponInSlot( ";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v130, pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseSuccess, a2: "%i ", (int)*(float *)&fParam);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")->AmmoFull()\n");
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle as BasePlayer returned NULL!\n");
          return 0;
        }
        vVarToParam.x = 0.0;
        while ( 1 )
        {
          v131 = (int)v129->ActivePlayerCombatCharacter(this: v129);
          v132 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v131 + 952))(a1: v131, a2: LODWORD(vVarToParam.x));
          if ( v132 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v132 + 1288))(a1: v132) == (int)*(float *)&fParam )
            break;
          ++LODWORD(vVarToParam.x);
          if ( SLODWORD(vVarToParam.x) >= 64 )
          {
            if ( gameinstructor_verbose.m_pParent == nullptr
              || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
              || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
            {
              goto LABEL_449;
            }
            v133 = "\t![%s]->GetWeaponInSlot( ";
            if ( !bNot )
              v133 = "\t[%s]->GetWeaponInSlot( ";
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v133, pchVarName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseSuccess, a2: "%i ", (int)*(float *)&fParam);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")->AmmoFull()\n");
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar GetWeaponInSlot returned NULL!\n");
            return 0;
          }
        }
        v134 = (*(int (__thiscall **)(int))(*(_DWORD *)v132 + 1328))(a1: v132);
        v135 = GetAmmoDef();
        v136 = COERCE_FLOAT(CAmmoDef::MaxCarry(this: v135, nAmmoIndex: v134, owner: v129));
        v137 = v129->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
        vVarToParam.x = v136;
        v138 = (C_BaseCombatCharacter *)((int (__thiscall *)(C_CSPlayer *, int))v137->ActivePlayerCombatCharacter)(
                                          a1: v129,
                                          a2: v134);
        HIBYTE(pchParamNameTemp) = C_BaseCombatCharacter::GetAmmoCount(this: v138, iAmmoIndex: SLODWORD(vVarToParam.z)) >= SLODWORD(vVarToParam.x);
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          v139 = "\t![%s]->GetWeaponInSlot( ";
          if ( !bNot )
            v139 = "\t[%s]->GetWeaponInSlot( ";
          v140 = ConColorMsg;
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v139, pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseSuccess, a2: "%i ", (int)*(float *)&fParam);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")->AmmoFull() ");
LABEL_346:
          v141 = "true\n";
          if ( HIBYTE(pchParamNameTemp) == 0 )
            v141 = "false\n";
          v140(a1: &CBaseLesson::m_rgbaVerboseName, a2: v141);
        }
LABEL_349:
        if ( bNot )
          return HIBYTE(pchParamNameTemp) == 0;
        else
          return HIBYTE(pchParamNameTemp);
      case 38:
        v142 = ToBasePlayer(pEntity: m_pEntity);
        if ( v142 != nullptr )
        {
          vVarToParam.x = 0.0;
          do
          {
            v144 = (int)v142->ActivePlayerCombatCharacter(this: v142);
            v145 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v144 + 952))(a1: v144, a2: LODWORD(vVarToParam.x));
            if ( v145 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v145 + 1288))(a1: v145) == (int)*(float *)&fParam )
            {
              v147 = (*(int (__thiscall **)(int))(*(_DWORD *)v145 + 1328))(a1: v145);
              v148 = (C_BaseCombatCharacter *)((int (__thiscall *)(C_CSPlayer *, int))v142->ActivePlayerCombatCharacter)(
                                                a1: v142,
                                                a2: v147);
              HIBYTE(pchParamNameTemp) = C_BaseCombatCharacter::GetAmmoCount(
                                           this: v148,
                                           iAmmoIndex: SLODWORD(vVarToParam.z)) <= 0;
              if ( gameinstructor_verbose.m_pParent != nullptr
                && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
                && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
              {
                v149 = "\t![%s]->GetWeaponInSlot( ";
                if ( !bNot )
                  v149 = "\t[%s]->GetWeaponInSlot( ";
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v149, pchVarName);
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseSuccess, a2: "%i ", (int)*(float *)&fParam);
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")->AmmoEmpty() ");
                v150 = "true";
                if ( HIBYTE(pchParamNameTemp) == 0 )
                  v150 = "false";
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: v150);
                ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: " )\n");
              }
              goto LABEL_349;
            }
            ++LODWORD(vVarToParam.x);
          }
          while ( SLODWORD(vVarToParam.x) < 64 );
          if ( gameinstructor_verbose.m_pParent == nullptr
            || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
            || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            goto LABEL_449;
          }
          v146 = "\t![%s]->GetWeaponInSlot( ";
          if ( !bNot )
            v146 = "\t[%s]->GetWeaponInSlot( ";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v146, pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseSuccess, a2: "%i ", (int)*(float *)&fParam);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")->AmmoEmpty()\n");
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar GetWeaponInSlot returned NULL!\n");
        }
        else
        {
          if ( gameinstructor_verbose.m_pParent == nullptr
            || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
            || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            goto LABEL_449;
          }
          v143 = "\t![%s]->GetWeaponInSlot( ";
          if ( !bNot )
            v143 = "\t[%s]->GetWeaponInSlot( ";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v143, pchVarName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseSuccess, a2: "%i ", (int)*(float *)&fParam);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")->AmmoEmpty()\n");
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle as BasePlayer returned NULL!\n");
        }
        return 0;
      case 39:
        v151 = (C_BaseCombatWeapon *)__RTDynamicCast(
                                       inptr: (void *)HIDWORD(fParam),
                                       VfDelta: 0,
                                       SrcType: &C_BaseEntity `RTTI Type Descriptor',
                                       TargetType: &C_BaseCombatWeapon `RTTI Type Descriptor',
                                       isReference: 0);
        v152 = ToBasePlayer(pEntity: m_pEntity);
        if ( v152 == nullptr )
        {
          if ( gameinstructor_verbose.m_pParent == nullptr
            || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
            || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            goto LABEL_449;
          }
          v153 = "\t![%s]->Weapon_CanUse([%s])\n";
          if ( !bNot )
            v153 = "\t[%s]->Weapon_CanUse([%s])\n";
          v154 = CGameInstructorSymbol::String(this: pchParamName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v153, pchVarName, v154);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle as BasePlayer returned NULL!\n");
          return 0;
        }
        if ( v151 == nullptr )
        {
          if ( gameinstructor_verbose.m_pParent == nullptr
            || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
            || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            goto LABEL_449;
          }
          v155 = "\t![%s]->Weapon_CanUse([%s])\n";
          if ( !bNot )
            v155 = "\t[%s]->Weapon_CanUse([%s])\n";
          v156 = CGameInstructorSymbol::String(this: pchParamName);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v155, pchVarName, v156);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tParam BaseCombatWeapon returned NULL!\n");
          return 0;
        }
        HIBYTE(pchParamNameTemp) = v152->Weapon_CanUse(this: v152, a2: v151);
        if ( gameinstructor_verbose.m_pParent == nullptr
          || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
          || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          goto LABEL_349;
        }
        v157 = "\t![%s]->Weapon_CanUse([%s]) ";
        if ( !bNot )
          v157 = "\t[%s]->Weapon_CanUse([%s]) ";
        v158 = CGameInstructorSymbol::String(this: pchParamName);
        LODWORD(vVarToParam.x) = v157;
        v140 = ConColorMsg;
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: (const char *)LODWORD(vVarToParam.x), pchVarName, v158);
        goto LABEL_346;
      case 40:
        v159 = ToBasePlayer(pEntity: m_pEntity);
        if ( v159 != nullptr )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            v161 = "\tC_BaseEntity::Instance([%s]->GetUseEntity()) != [%s]\n";
            if ( !bNot )
              v161 = "\tC_BaseEntity::Instance([%s]->GetUseEntity()) == [%s]\n";
            v162 = CGameInstructorSymbol::String(this: pchParamName);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v161, pchVarName, v162);
          }
          v163 = v159->GetUseEntity(this: v159);
          v164 = C_BaseEntity::Instance(ent: v163);
          if ( bNot )
            return v164 != (C_BaseEntity *)HIDWORD(fParam);
          else
            return v164 == (C_BaseEntity *)HIDWORD(fParam);
        }
        if ( gameinstructor_verbose.m_pParent == nullptr
          || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
          || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          goto LABEL_449;
        }
        v160 = "\tC_BaseEntity::Instance([%s]->GetUseEntity()) != [%s]\n";
        if ( !bNot )
          v160 = "\tC_BaseEntity::Instance([%s]->GetUseEntity()) == [%s]\n";
        v181 = CGameInstructorSymbol::String(this: pchParamName);
        v178 = *(float *)&pchVarName;
        v175 = v160;
        goto LABEL_404;
      case 41:
        if ( (unsigned int)((int)*(float *)&fParam - 1) > 1 )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            v180 = pchVarName;
            v177 = "\t[entityINVALID] = C_BaseEntity::Instance([%s]->GetUseEntity())\n";
            goto LABEL_185;
          }
          goto LABEL_449;
        }
        if ( (int)*(float *)&fParam == 2 )
        {
          v165 = (CHandle<C_BaseEntity> *)(LODWORD(vVarToParam.y) + 308);
          LODWORD(vVarToParam.x) = "entity2";
        }
        else
        {
          v165 = (CHandle<C_BaseEntity> *)(LODWORD(vVarToParam.y) + 304);
          LODWORD(vVarToParam.x) = "entity1";
        }
        v166 = ToBasePlayer(pEntity: m_pEntity);
        if ( v166 == nullptr )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            v181 = pchVarName;
            v178 = vVarToParam.x;
            v175 = "\t[%s] = C_BaseEntity::Instance([%s]->GetUseEntity())\n";
            goto LABEL_404;
          }
          goto LABEL_449;
        }
        v167 = v166->GetUseEntity(this: v166);
        v168 = C_BaseEntity::Instance(ent: v167);
        CHandle<C_BaseEntity>::Set(this: v165, pVal: v168);
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          ConColorMsg(
            a1: &CBaseLesson::m_rgbaVerbosePlain,
            a2: "\t[%s] = C_BaseEntity::Instance([%s]->GetUseEntity())\n",
            (const char *)LODWORD(vVarToParam.x),
            pchVarName);
          return 1;
        }
        return 1;
      case 42:
        if ( (unsigned int)((int)*(float *)&fParam - 1) > 1 )
        {
          if ( gameinstructor_verbose.m_pParent == nullptr
            || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
            || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            goto LABEL_449;
          }
          v180 = pchVarName;
          v177 = "\t[entityINVALID] = C_BaseEntity::Instance([%s]->GetPotentialUseEntity())\n";
LABEL_185:
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v177, v180);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tParam selecting string is out of range!\n");
          return 0;
        }
        if ( (int)*(float *)&fParam == 2 )
        {
          v169 = (CHandle<C_BaseEntity> *)(LODWORD(vVarToParam.y) + 308);
          LODWORD(vVarToParam.x) = "entity2";
        }
        else
        {
          v169 = (CHandle<C_BaseEntity> *)(LODWORD(vVarToParam.y) + 304);
          LODWORD(vVarToParam.x) = "entity1";
        }
        v170 = ToBasePlayer(pEntity: m_pEntity);
        if ( v170 != nullptr )
        {
          v171 = v170->GetPotentialUseEntity(this: v170);
          v172 = C_BaseEntity::Instance(ent: v171);
          CHandle<C_BaseEntity>::Set(this: v169, pVal: v172);
          if ( gameinstructor_verbose.m_pParent == nullptr
            || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
            || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
          {
            return 1;
          }
          ConColorMsg(
            a1: &CBaseLesson::m_rgbaVerbosePlain,
            a2: "\t[%s] = C_BaseEntity::Instance([%s]->GetPotentialUseEntity())\n",
            (const char *)LODWORD(vVarToParam.x),
            pchVarName);
          return 1;
        }
        if ( gameinstructor_verbose.m_pParent == nullptr
          || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 0
          || !CBaseLesson::ShouldShowSpew(this: (CBaseLesson *)LODWORD(vVarToParam.y), a2: bAmmoLow) )
        {
          goto LABEL_449;
        }
        v181 = pchVarName;
        v178 = vVarToParam.x;
        v175 = "\t[%s] = C_BaseEntity::Instance([%s]->GetPotentialUseEntity())\n";
LABEL_404:
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v175, v178, v181);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tVar handle as Player returned NULL!\n");
        return 0;
      default:
        DevWarning(a1: "Invalid lesson action type used with \"%s\" variable type.\n", pchVarName);
        goto LABEL_449;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004D4D0
// Name: private: bool CScriptedIconLesson::ProcessElementAction(int,bool,char const __near *,class CGameInstructorSymbol __near *,class CGameInstructorSymbol const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptedIconLesson::ProcessElementAction(
        CScriptedIconLesson *this,
        int iAction,
        int bNot,
        const char *pchVarName,
        CGameInstructorSymbol *pchVar,
        CGameInstructorSymbol *pchParamName,
        int pchParam)
{
  CGameInstructorSymbol *v8; // esi
  C_GameInstructor *GameInstructor; // eax
  const CBaseLesson *Lesson; // edi
  const char *v11; // eax
  bool result; // al
  const char *v13; // eax
  const char *v14; // eax
  char v15; // al
  const char *v16; // edi
  const char *v17; // eax
  CUtlSymbol *v18; // eax
  const char *v19; // edi
  const char *v20; // eax
  CGameInstructorSymbol *v21; // esi
  char *v22; // eax
  const char *v23; // edi
  CGameInstructorSymbol *v24; // ebx
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  const char *v30; // edi
  CGameInstructorSymbol *v31; // ebx
  const char *v32; // eax
  const char *v33; // eax
  const char *v34; // eax
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // edi
  CGameInstructorSymbol *v38; // ebx
  const char *v39; // eax
  const char *v40; // eax
  const char *v41; // eax
  const char *v42; // eax
  const char *v43; // eax
  const char *v44; // [esp-4h] [ebp-114h]
  char szTemp[256]; // [esp+Ch] [ebp-104h] BYREF
  struct Color v46; // [esp+10Ch] [ebp-4h] BYREF

  switch ( iAction )
  {
    case 9:
      v8 = pchParamName;
      v44 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: pchParamName->m_SymbolId);
      GameInstructor = GetGameInstructor();
      Lesson = C_GameInstructor::GetLesson(this: GameInstructor, pchLessonName: v44);
      if ( Lesson != nullptr )
      {
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this, a2: (const char *)this) )
        {
          pchVar = (CGameInstructorSymbol *)"\t!( [\"%s\"]->IsInstanceActive() ";
          if ( (_BYTE)bNot == 0 )
            pchVar = (CGameInstructorSymbol *)"\t( [\"%s\"]->IsInstanceActive() ";
          pchParam = -32704;
          v13 = CGameInstructorSymbol::String(this: v8);
          ConColorMsg(a1: (const struct Color *)&pchParam, a2: (const char *)pchVar, v13);
          v14 = "true";
          if ( (*((_BYTE *)Lesson + 60) & 1) == 0 )
            v14 = "false";
          iAction = -1;
          ConColorMsg(a1: (const struct Color *)&iAction, a2: "\"%s\"", v14);
          *(_WORD *)v46._color = -32704;
          v46._color[2] = -1;
          v46._color[3] = -1;
          ConColorMsg(a1: &v46, a2: " )\n");
        }
        v15 = *((_BYTE *)Lesson + 60);
        if ( (_BYTE)bNot != 0 )
          v15 = ~v15;
        result = v15 & 1;
      }
      else
      {
        v11 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v8->m_SymbolId);
        DevWarning(a1: "Invalid lesson specified: \"%s\".", v11);
        result = false;
      }
      break;
    case 11:
      v16 = (const char *)pchParam;
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2: (const char *)this) )
      {
        v17 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tQ_strcpy([%s], [%s] ", pchVarName, v17);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"", v16);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")\n");
      }
      v18 = CUtlSymbolTable::AddString(
              this: &g_CGameInstructorSymbolSymbolTable,
              result: (CUtlSymbol *)&bNot + 1,
              pString: v16);
      pchVar->m_SymbolId.m_Id = v18->m_Id;
      result = true;
      break;
    case 12:
      v19 = (const char *)pchParam;
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2: (const char *)this) )
      {
        v20 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tQ_strcat([%s], [%s] ", pchVarName, v20);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"", v19);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ")\n");
      }
      v21 = pchVar;
      v22 = (char *)CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: pchVar->m_SymbolId);
      V_strncpy(pDest: szTemp, pSrc: v22, maxLen: 256);
      V_strncat(pDest: szTemp, pSrc: v19, destBufferSize: 0x100u, max_chars_to_copy: -1);
      v21->m_SymbolId.m_Id = CUtlSymbolTable::AddString(
                               this: &g_CGameInstructorSymbolSymbolTable,
                               result: (CUtlSymbol *)&bNot + 1,
                               pString: szTemp)->m_Id;
      result = true;
      break;
    case 15:
      v23 = (const char *)pchParam;
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2: (const char *)this) )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tQ_strcmp([%s] ", pchVarName);
        v24 = pchVar;
        v25 = CGameInstructorSymbol::String(this: pchVar);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"", v25);
        v26 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ", [%s] ", v26);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"", v23);
        v27 = ") != 0\n";
        if ( (_BYTE)bNot == 0 )
          v27 = ") == 0\n";
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v27);
      }
      else
      {
        v24 = pchVar;
      }
      if ( (_BYTE)bNot != 0 )
      {
        v28 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v24->m_SymbolId);
        result = _V_strcmp(s1: v28, s2: v23) != 0;
      }
      else
      {
        v29 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v24->m_SymbolId);
        result = _V_strcmp(s1: v29, s2: v23) == 0;
      }
      break;
    case 16:
      v37 = (const char *)pchParam;
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2: (const char *)this) )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tQ_strcmp([%s] ", pchVarName);
        v38 = pchVar;
        v39 = CGameInstructorSymbol::String(this: pchVar);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\"%s\"", v39);
        v40 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ", [%s] ", v40);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\"%s\"", v37);
        v41 = ") >= 0\n";
        if ( (_BYTE)bNot == 0 )
          v41 = ") < 0\n";
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v41);
      }
      else
      {
        v38 = pchVar;
      }
      if ( (_BYTE)bNot != 0 )
      {
        v42 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v38->m_SymbolId);
        result = _V_strcmp(s1: v42, s2: v37) >= 0;
      }
      else
      {
        v43 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v38->m_SymbolId);
        result = _V_strcmp(s1: v43, s2: v37) < 0;
      }
      break;
    case 17:
      v30 = (const char *)pchParam;
      if ( gameinstructor_verbose.m_pParent != nullptr
        && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
        && CBaseLesson::ShouldShowSpew(this, a2: (const char *)this) )
      {
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tStringHasPrefix([%s] ", pchVarName);
        v31 = pchVar;
        v32 = CGameInstructorSymbol::String(this: pchVar);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"", v32);
        v33 = CGameInstructorSymbol::String(this: pchParamName);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ", [%s] ", v33);
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"", v30);
        v34 = ") == false\n";
        if ( (_BYTE)bNot == 0 )
          v34 = ") == true\n";
        ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v34);
      }
      else
      {
        v31 = pchVar;
      }
      if ( (_BYTE)bNot != 0 )
      {
        v35 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v31->m_SymbolId);
        result = !StringHasPrefix(str: v35, prefix: v30);
      }
      else
      {
        v36 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v31->m_SymbolId);
        result = StringHasPrefix(str: v36, prefix: v30);
      }
      break;
    default:
      DevWarning(a1: "Invalid lesson action type used with \"%s\" variable type.\n", pchVarName);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004F630
// Name: public: CBaseLesson::CBaseLesson(char const __near *,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
CBaseLesson *__thiscall CBaseLesson::CBaseLesson(
        CBaseLesson *this,
        const char *pchName,
        bool bIsDefaultHolder,
        bool bIsOpenOpportunity,
        int nSplitScreenSlot)
{
  int v5; // edx

  v5 = nSplitScreenSlot;
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->__vftable = (CBaseLesson_vtbl *)&CBaseLesson::`vftable';
  this->m_OpenOpportunities.m_Memory.m_pMemory = nullptr;
  this->m_OpenOpportunities.m_Memory.m_nAllocationCount = 0;
  this->m_OpenOpportunities.m_Memory.m_nGrowSize = 0;
  this->m_OpenOpportunities.m_Size = 0;
  this->m_OpenOpportunities.m_pElements = nullptr;
  this->m_Prerequisites.m_Memory.m_pMemory = nullptr;
  this->m_Prerequisites.m_Memory.m_nAllocationCount = 0;
  this->m_Prerequisites.m_Memory.m_nGrowSize = 0;
  this->m_Prerequisites.m_Size = 0;
  this->m_Prerequisites.m_pElements = nullptr;
  *(_DWORD *)&this->m_stringCloseReason.m_SymbolId.m_Id = -1;
  this->m_stringReplaceKey.m_SymbolId.m_Id = -1;
  *(_DWORD *)&this->m_szStartSound.m_SymbolId.m_Id = -1;
  this->m_pDelayedPlayerSwap[0].phHandleToChange = nullptr;
  this->m_pDelayedPlayerSwap[1].phHandleToChange = nullptr;
  this->m_pDelayedPlayerSwap[2].phHandleToChange = nullptr;
  this->m_pDelayedPlayerSwap[3].phHandleToChange = nullptr;
  this->m_pDelayedPlayerSwap[4].phHandleToChange = nullptr;
  this->m_pDelayedPlayerSwap[5].phHandleToChange = nullptr;
  this->m_pDelayedPlayerSwap[6].phHandleToChange = nullptr;
  this->m_pDelayedPlayerSwap[7].phHandleToChange = nullptr;
  this->m_pDelayedPlayerSwap[0].iNewUserID = -1;
  this->m_pDelayedPlayerSwap[1].iNewUserID = -1;
  this->m_pDelayedPlayerSwap[2].iNewUserID = -1;
  this->m_pDelayedPlayerSwap[3].iNewUserID = -1;
  this->m_pDelayedPlayerSwap[4].iNewUserID = -1;
  this->m_pDelayedPlayerSwap[5].iNewUserID = -1;
  this->m_pDelayedPlayerSwap[6].iNewUserID = -1;
  this->m_pDelayedPlayerSwap[7].iNewUserID = -1;
  this->m_nSplitScreenSlot = v5;
  this->m_stringName.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                this: &g_CGameInstructorSymbolSymbolTable,
                                                result: (CUtlSymbol *)&nSplitScreenSlot + 1,
                                                pString: pchName)->m_Id;
  this->m_stringReplaceKey.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                      this: &g_CGameInstructorSymbolSymbolTable,
                                                      result: (CUtlSymbol *)&nSplitScreenSlot + 1,
                                                      pString: prType)->m_Id;
  *((_BYTE *)this + 60) = *((_BYTE *)this + 60) & 0xF3 | (4 * (bIsDefaultHolder | (2 * bIsOpenOpportunity)));
  CBaseLesson::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004F750
// Name: public: virtual bool CBaseLesson::WasDisplayed(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseLesson::WasDisplayed(CBaseLesson *this)
{
  return this->m_bWasDisplayed;
}

//------------------------------------------------------------------------------
// Address: 0x1004F760
// Name: public: virtual CBaseLesson::~CBaseLesson(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseLesson::~CBaseLesson(CBaseLesson *this)
{
  CBaseLesson *m_pRoot; // eax
  int i; // eax
  CBaseLesson *v4; // ecx
  const CBaseLesson **m_pMemory; // eax
  CBaseLesson **v6; // eax
  vgui::TreeNode *src; // [esp+8h] [ebp-4h] BYREF

  m_pRoot = this->m_pRoot;
  this->__vftable = (CBaseLesson_vtbl *)&CBaseLesson::`vftable';
  if ( m_pRoot != nullptr )
  {
    src = (vgui::TreeNode *)this;
    CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&m_pRoot->m_OpenOpportunities,
      &src);
  }
  else
  {
    for ( i = 0; i < this->m_OpenOpportunities.m_Size; v4->m_pRoot = nullptr )
      v4 = this->m_OpenOpportunities.m_Memory.m_pMemory[i++];
  }
  this->m_Prerequisites.m_Size = 0;
  if ( this->m_Prerequisites.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Prerequisites.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Prerequisites.m_Memory.m_pMemory);
      this->m_Prerequisites.m_Memory.m_pMemory = nullptr;
    }
    this->m_Prerequisites.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Prerequisites.m_Memory.m_pMemory;
  this->m_Prerequisites.m_pElements = m_pMemory;
  if ( this->m_Prerequisites.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Prerequisites.m_Memory.m_pMemory = nullptr;
    }
    this->m_Prerequisites.m_Memory.m_nAllocationCount = 0;
  }
  this->m_OpenOpportunities.m_Size = 0;
  if ( this->m_OpenOpportunities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OpenOpportunities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OpenOpportunities.m_Memory.m_pMemory);
      this->m_OpenOpportunities.m_Memory.m_pMemory = nullptr;
    }
    this->m_OpenOpportunities.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_OpenOpportunities.m_Memory.m_pMemory;
  this->m_OpenOpportunities.m_pElements = v6;
  if ( this->m_OpenOpportunities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_OpenOpportunities.m_Memory.m_pMemory = nullptr;
    }
    this->m_OpenOpportunities.m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CBaseLesson_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: this);
    this->m_bRegisteredForEvents = false;
  }
  this->__vftable = (CBaseLesson_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1004F950
// Name: public: CIconLesson::CIconLesson(char const __near *,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
CIconLesson *__thiscall CIconLesson::CIconLesson(
        CIconLesson *this,
        const char *pchName,
        bool bIsDefaultHolder,
        bool bIsOpenOpportunity,
        int nSplitScreenSlot)
{
  CBaseLesson::CBaseLesson(this, pchName, bIsDefaultHolder, bIsOpenOpportunity, nSplitScreenSlot);
  this->__vftable = (CIconLesson_vtbl *)&CTextLesson::`vftable';
  *(_DWORD *)&this->m_szDisplayText.m_SymbolId.m_Id = -1;
  *(_DWORD *)&this->m_szBinding.m_SymbolId.m_Id = -1;
  CTextLesson::Init(this);
  this->__vftable = (CIconLesson_vtbl *)&CIconLesson::`vftable';
  this->m_hIconTarget.m_Index = -1;
  *(_DWORD *)&this->m_szVguiTargetName.m_SymbolId.m_Id = -1;
  *(_DWORD *)&this->m_szOnscreenIcon.m_SymbolId.m_Id = -1;
  this->m_szCaptionColor.m_SymbolId.m_Id = -1;
  CIconLesson::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004F9D0
// Name: public: void CBaseLesson::AddPrerequisite(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseLesson::AddPrerequisite(CBaseLesson *this, const char *pchLessonName)
{
  const char *v4; // eax
  C_GameInstructor *GameInstructor; // eax
  const char *v6; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Prerequisites; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v11; // eax
  const CBaseLesson **v12; // edi
  const CBaseLesson *pPrerequisite; // [esp+14h] [ebp+8h]

  if ( gameinstructor_verbose.m_pParent != nullptr
    && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
    && CBaseLesson::ShouldShowSpew(this, a2: pchLessonName) )
  {
    v4 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "\t%s: ", v4);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Adding prereq ");
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseOpen, a2: "\"%s\"", pchLessonName);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ".\n");
  }
  GameInstructor = GetGameInstructor();
  pPrerequisite = C_GameInstructor::GetLesson(this: GameInstructor, pchLessonName);
  if ( pPrerequisite != nullptr )
  {
    m_nAllocationCount = this->m_Prerequisites.m_Memory.m_nAllocationCount;
    p_m_Prerequisites = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Prerequisites;
    m_Size = this->m_Prerequisites.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Prerequisites, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Prerequisites[1].m_pMemory;
    m_pMemory = p_m_Prerequisites->m_pMemory;
    v11 = (int)p_m_Prerequisites[1].m_pMemory - m_Size - 1;
    p_m_Prerequisites[1].m_nAllocationCount = (int)p_m_Prerequisites->m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
    v12 = (const CBaseLesson **)&p_m_Prerequisites->m_pMemory[m_Size];
    if ( v12 != nullptr )
      *v12 = pPrerequisite;
  }
  else
  {
    v6 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
    DevWarning(a1: "Prerequisite %s added by lesson %s doesn't exist!\n", pchLessonName, v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FAE0
// Name: public: void CBaseLesson::SetRoot(class CBaseLesson __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseLesson::SetRoot(CBaseLesson *this, CBaseLesson *pRoot)
{
  int m_Size; // ecx
  CUtlMemory<vgui::TreeNode *,int> *p_m_OpenOpportunities; // esi
  int v5; // eax
  CBaseLesson **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v8; // edi
  vgui::TreeNode **v9; // ecx
  int v10; // eax
  CBaseLesson **v11; // eax

  this->m_pRoot = pRoot;
  if ( pRoot != nullptr )
  {
    m_Size = pRoot->m_OpenOpportunities.m_Size;
    p_m_OpenOpportunities = (CUtlMemory<vgui::TreeNode *,int> *)&pRoot->m_OpenOpportunities;
    v5 = 0;
    if ( m_Size <= 0 )
      goto LABEL_8;
    m_pMemory = (CBaseLesson **)p_m_OpenOpportunities->m_pMemory;
    while ( *m_pMemory != this )
    {
      ++v5;
      ++m_pMemory;
      if ( v5 >= m_Size )
        goto LABEL_8;
    }
    if ( v5 == -1 )
    {
LABEL_8:
      m_nAllocationCount = pRoot->m_OpenOpportunities.m_Memory.m_nAllocationCount;
      v8 = pRoot->m_OpenOpportunities.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_OpenOpportunities, num: m_Size - m_nAllocationCount + 1);
      ++pRoot->m_OpenOpportunities.m_Size;
      v9 = p_m_OpenOpportunities->m_pMemory;
      v10 = pRoot->m_OpenOpportunities.m_Size - v8 - 1;
      pRoot->m_OpenOpportunities.m_pElements = pRoot->m_OpenOpportunities.m_Memory.m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &v9[v8 + 1], src: &v9[v8], count: 4 * v10);
      v11 = (CBaseLesson **)&p_m_OpenOpportunities->m_pMemory[v8];
      if ( v11 != nullptr )
        *v11 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FB70
// Name: public: virtual void CScriptedIconLesson::InitPrerequisites(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CScriptedIconLesson::InitPrerequisites(CScriptedIconLesson *this@<ecx>, const char *a2@<ebx>)
{
  const char *v3; // eax
  int i; // edi
  const char *v5; // eax

  if ( gameinstructor_verbose.m_pParent != nullptr
    && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
    && CBaseLesson::ShouldShowSpew(this, a2) )
  {
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Initializing prereqs for scripted lesson ");
    v3 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseOpen, a2: "\"%s\"", v3);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "...\n");
  }
  for ( i = 0; i < this->m_PrerequisiteNames.m_Size; ++i )
  {
    v5 = CUtlSymbolTable::String(
           this: &g_CGameInstructorSymbolSymbolTable,
           id: this->m_PrerequisiteNames.m_Memory.m_pMemory[i].m_SymbolId);
    CBaseLesson::AddPrerequisite(this, pchLessonName: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FCE0
// Name: public: void CUtlDict<enum LessonVariable,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<enum LessonVariable,int>::RemoveAll(CUtlDict<enum LessonVariable,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int,CUtlMap<char const *,enum LessonVariable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int,CUtlMap<char const *,enum LessonVariable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int,CUtlMap<char const *,enum LessonVariable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1004FD30
// Name: public: void CUtlDict<enum _fieldtypes,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<enum _fieldtypes,int>::RemoveAll(CUtlDict<enum _fieldtypes,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1004FED0
// Name: public: int CUtlMap<char const __near *,enum LessonVariable,int>::Insert(char const __near * const __near &,enum LessonVariable const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,enum LessonVariable,int>::Insert@<eax>(
        CUtlMap<char const *,enum LessonVariable,int> *this@<ecx>,
        const char *a2@<edi>,
        const char **key,
        int insert)
{
  LessonVariable v5; // eax
  int v6; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,enum LessonVariable,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v5 = *(_DWORD *)insert;
  node.key = *key;
  node.elem = v5;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int,CUtlMap<char const *,enum LessonVariable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v6 = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::NewNode(
         (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this,
         a2);
  CUtlRBTree<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int,CUtlMap<char const *,enum LessonVariable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v6,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int> *)-16 )
    m_pMemory[v6].m_Data = node;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1004FF50
// Name: public: int CUtlMap<char const __near *,enum _fieldtypes,int>::Insert(char const __near * const __near &,enum _fieldtypes const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,enum _fieldtypes,int>::Insert@<eax>(
        CUtlMap<char const *,enum _fieldtypes,int> *this@<ecx>,
        const char *a2@<edi>,
        const char **key,
        int insert)
{
  _fieldtypes v5; // eax
  int v6; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v5 = *(_DWORD *)insert;
  node.key = *key;
  node.elem = v5;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v6 = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::NewNode(
         (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this,
         a2);
  CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v6,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int> *)-16 )
    m_pMemory[v6].m_Data = node;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1004FFD0
// Name: private: struct LessonEvent_t __near * CScriptedIconLesson::AddOpenEvent(void)
// Source: json
//------------------------------------------------------------------------------
LessonEvent_t *__thiscall CScriptedIconLesson::AddOpenEvent(CScriptedIconLesson *this)
{
  return &this->m_OpenEvents.m_Memory.m_pMemory[CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::InsertBefore(
                                                  this: &this->m_OpenEvents,
                                                  elem: this->m_OpenEvents.m_Size)];
}

//------------------------------------------------------------------------------
// Address: 0x1004FFF0
// Name: private: struct LessonEvent_t __near * CScriptedIconLesson::AddCloseEvent(void)
// Source: json
//------------------------------------------------------------------------------
LessonEvent_t *__thiscall CScriptedIconLesson::AddCloseEvent(CScriptedIconLesson *this)
{
  return &this->m_CloseEvents.m_Memory.m_pMemory[CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::InsertBefore(
                                                   this: &this->m_CloseEvents,
                                                   elem: this->m_CloseEvents.m_Size)];
}

//------------------------------------------------------------------------------
// Address: 0x10050010
// Name: private: struct LessonEvent_t __near * CScriptedIconLesson::AddSuccessEvent(void)
// Source: json
//------------------------------------------------------------------------------
LessonEvent_t *__thiscall CScriptedIconLesson::AddSuccessEvent(CScriptedIconLesson *this)
{
  return &this->m_SuccessEvents.m_Memory.m_pMemory[CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::InsertBefore(
                                                     this: &this->m_SuccessEvents,
                                                     elem: this->m_SuccessEvents.m_Size)];
}

//------------------------------------------------------------------------------
// Address: 0x10050030
// Name: private: struct LessonEvent_t __near * CScriptedIconLesson::AddOnOpenEvent(void)
// Source: json
//------------------------------------------------------------------------------
LessonEvent_t *__thiscall CScriptedIconLesson::AddOnOpenEvent(CScriptedIconLesson *this)
{
  return &this->m_OnOpenEvents.m_Memory.m_pMemory[CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::InsertBefore(
                                                    this: &this->m_OnOpenEvents,
                                                    elem: this->m_OnOpenEvents.m_Size)];
}

//------------------------------------------------------------------------------
// Address: 0x10050050
// Name: private: struct LessonEvent_t __near * CScriptedIconLesson::AddUpdateEvent(void)
// Source: json
//------------------------------------------------------------------------------
LessonEvent_t *__thiscall CScriptedIconLesson::AddUpdateEvent(CScriptedIconLesson *this)
{
  return &this->m_UpdateEvents.m_Memory.m_pMemory[CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::InsertBefore(
                                                    this: &this->m_UpdateEvents,
                                                    elem: this->m_UpdateEvents.m_Size)];
}

//------------------------------------------------------------------------------
// Address: 0x100500D0
// Name: public: int CUtlDict<enum LessonVariable,int>::Insert(char const __near *,enum LessonVariable const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<enum LessonVariable,int>::Insert(
        CUtlDict<enum LessonVariable,int> *this,
        char *pName,
        const LessonVariable *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,enum LessonVariable,int>::Insert(
           this: &this->m_Elements,
           key: (const char *const *)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x10050130
// Name: public: int CUtlDict<enum _fieldtypes,int>::Insert(char const __near *,enum _fieldtypes const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<enum _fieldtypes,int>::Insert(
        CUtlDict<enum _fieldtypes,int> *this,
        char *pName,
        const _fieldtypes *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,enum _fieldtypes,int>::Insert(
           this: &this->m_Elements,
           key: (const char *const *)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x10050190
// Name: public: virtual CScriptedIconLesson::~CScriptedIconLesson(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptedIconLesson::~CScriptedIconLesson(CScriptedIconLesson *this)
{
  CScriptedIconLesson *m_pDefaultHolder; // ecx

  m_pDefaultHolder = this->m_pDefaultHolder;
  this->__vftable = (CScriptedIconLesson_vtbl *)&CScriptedIconLesson::`vftable';
  if ( m_pDefaultHolder != nullptr )
  {
    ((void (__thiscall *)(CScriptedIconLesson *, int))m_pDefaultHolder->dtr_IGameEventListener2)(
      a1: m_pDefaultHolder,
      a2: 1);
    this->m_pDefaultHolder = nullptr;
  }
  CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::~CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>(this: &this->m_UpdateEvents);
  CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::~CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>(this: &this->m_OnOpenEvents);
  CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::~CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>(this: &this->m_SuccessEvents);
  CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::~CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>(this: &this->m_CloseEvents);
  CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::~CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>(this: &this->m_OpenEvents);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_PrerequisiteNames);
  CBaseLesson::~CBaseLesson(this);
}

//------------------------------------------------------------------------------
// Address: 0x10050200
// Name: public: static void CScriptedIconLesson::PreReadLessonsFromFile(void)
// Source: json
//------------------------------------------------------------------------------
static void __thiscall CScriptedIconLesson::PreReadLessonsFromFile(void *this)
{
  int v1; // eax
  int v2; // ecx
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // ecx
  int v41; // eax
  int v42; // ecx
  int v43; // eax
  int v44; // ecx
  int v45; // eax
  int v46; // ecx
  int v47; // eax
  int v48; // ecx
  int v49; // eax
  int v50; // ecx
  int v51; // eax
  int v52; // ecx
  int v53; // eax
  int v54; // ecx
  int v55; // eax
  int v56; // ecx
  int v57; // eax
  int v58; // ecx
  int v59; // eax
  int v60; // ecx
  int v61; // eax
  int v62; // ecx
  int v63; // eax
  int v64; // ecx
  int v65; // eax
  int v66; // ecx
  int v67; // eax
  int v68; // ecx
  int v69; // eax
  int v70; // ecx
  int v71; // eax
  int v72; // ecx
  int v73; // eax
  int v74; // ecx
  int v75; // eax
  int v76; // ecx
  int v77; // eax
  int v78; // ecx
  int v79; // eax
  int v80; // ecx
  int v81; // eax
  int v82; // ecx
  int v83; // eax
  int v84; // ecx
  int v85; // eax
  int v86; // ecx
  int v87; // eax
  int v88; // ecx
  int v89; // eax
  int v90; // ecx
  int v91; // eax
  int v92; // ecx
  int v93; // eax
  LessonVariable element; // [esp+0h] [ebp-4h] BYREF

  element = (LessonVariable)this;
  if ( bFirstTime )
  {
    bFirstTime = false;
    v1 = _KeyValuesSystem(a1: this);
    g_nVOIDSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v1 + 12))(a1: v1, a2: "VOID", a3: 1);
    v3 = _KeyValuesSystem(a1: v2);
    g_nLOCAL_PLAYERSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v3 + 12))(
                              a1: v3,
                              a2: "LOCAL_PLAYER",
                              a3: 1);
    v5 = _KeyValuesSystem(a1: v4);
    g_nOUTPUTSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 12))(a1: v5, a2: "OUTPUT", a3: 1);
    v7 = _KeyValuesSystem(a1: v6);
    g_nENTITY1Symbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v7 + 12))(
                         a1: v7,
                         a2: "ENTITY1",
                         a3: 1);
    v9 = _KeyValuesSystem(a1: v8);
    g_nENTITY2Symbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v9 + 12))(
                         a1: v9,
                         a2: "ENTITY2",
                         a3: 1);
    v11 = _KeyValuesSystem(a1: v10);
    g_nSTRING1Symbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v11 + 12))(
                         a1: v11,
                         a2: "STRING1",
                         a3: 1);
    v13 = _KeyValuesSystem(a1: v12);
    g_nSTRING2Symbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v13 + 12))(
                         a1: v13,
                         a2: "STRING2",
                         a3: 1);
    v15 = _KeyValuesSystem(a1: v14);
    g_nINTEGER1Symbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v15 + 12))(
                          a1: v15,
                          a2: "INTEGER1",
                          a3: 1);
    v17 = _KeyValuesSystem(a1: v16);
    g_nINTEGER2Symbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v17 + 12))(
                          a1: v17,
                          a2: "INTEGER2",
                          a3: 1);
    v19 = _KeyValuesSystem(a1: v18);
    g_nFLOAT1Symbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v19 + 12))(
                        a1: v19,
                        a2: "FLOAT1",
                        a3: 1);
    v21 = _KeyValuesSystem(a1: v20);
    g_nFLOAT2Symbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v21 + 12))(
                        a1: v21,
                        a2: "FLOAT2",
                        a3: 1);
    v23 = _KeyValuesSystem(a1: v22);
    g_nICON_TARGETSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v23 + 12))(
                             a1: v23,
                             a2: "ICON_TARGET",
                             a3: 1);
    v25 = _KeyValuesSystem(a1: v24);
    g_nVGUI_TARGET_NAMESymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v25 + 12))(
                                  a1: v25,
                                  a2: "VGUI_TARGET_NAME",
                                  a3: 1);
    v27 = _KeyValuesSystem(a1: v26);
    g_nVGUI_TARGET_LOOKUPSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v27 + 12))(
                                    a1: v27,
                                    a2: "VGUI_TARGET_LOOKUP",
                                    a3: 1);
    v29 = _KeyValuesSystem(a1: v28);
    g_nVGUI_TARGET_EDGESymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v29 + 12))(
                                  a1: v29,
                                  a2: "VGUI_TARGET_EDGE",
                                  a3: 1);
    v31 = _KeyValuesSystem(a1: v30);
    g_nFIXED_POSITION_XSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v31 + 12))(
                                  a1: v31,
                                  a2: "FIXED_POSITION_X",
                                  a3: 1);
    v33 = _KeyValuesSystem(a1: v32);
    g_nFIXED_POSITION_YSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v33 + 12))(
                                  a1: v33,
                                  a2: "FIXED_POSITION_Y",
                                  a3: 1);
    v35 = _KeyValuesSystem(a1: v34);
    g_nFIXED_POSITIONSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v35 + 12))(
                                a1: v35,
                                a2: "FIXED_POSITION",
                                a3: 1);
    v37 = _KeyValuesSystem(a1: v36);
    g_nNO_ICON_TARGETSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v37 + 12))(
                                a1: v37,
                                a2: "NO_ICON_TARGET",
                                a3: 1);
    v39 = _KeyValuesSystem(a1: v38);
    g_nALLOW_NODRAW_TARGETSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v39 + 12))(
                                     a1: v39,
                                     a2: "ALLOW_NODRAW_TARGET",
                                     a3: 1);
    v41 = _KeyValuesSystem(a1: v40);
    g_nVISIBLESymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v41 + 12))(
                         a1: v41,
                         a2: "VISIBLE",
                         a3: 1);
    v43 = _KeyValuesSystem(a1: v42);
    g_nSHOW_WHEN_OCCLUDEDSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v43 + 12))(
                                    a1: v43,
                                    a2: "SHOW_WHEN_OCCLUDED",
                                    a3: 1);
    v45 = _KeyValuesSystem(a1: v44);
    g_nNO_OFFSCREENSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v45 + 12))(
                              a1: v45,
                              a2: "NO_OFFSCREEN",
                              a3: 1);
    v47 = _KeyValuesSystem(a1: v46);
    g_nFORCE_CAPTIONSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v47 + 12))(
                               a1: v47,
                               a2: "FORCE_CAPTION",
                               a3: 1);
    v49 = _KeyValuesSystem(a1: v48);
    g_nONSCREEN_ICONSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v49 + 12))(
                               a1: v49,
                               a2: "ONSCREEN_ICON",
                               a3: 1);
    v51 = _KeyValuesSystem(a1: v50);
    g_nOFFSCREEN_ICONSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v51 + 12))(
                                a1: v51,
                                a2: "OFFSCREEN_ICON",
                                a3: 1);
    v53 = _KeyValuesSystem(a1: v52);
    g_nICON_OFFSETSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v53 + 12))(
                             a1: v53,
                             a2: "ICON_OFFSET",
                             a3: 1);
    v55 = _KeyValuesSystem(a1: v54);
    g_nICON_RELATIVE_OFFSETSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v55 + 12))(
                                      a1: v55,
                                      a2: "ICON_RELATIVE_OFFSET",
                                      a3: 1);
    v57 = _KeyValuesSystem(a1: v56);
    g_nRANGESymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v57 + 12))(a1: v57, a2: "RANGE", a3: 1);
    v59 = _KeyValuesSystem(a1: v58);
    g_nFLAGSSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v59 + 12))(a1: v59, a2: "FLAGS", a3: 1);
    v61 = _KeyValuesSystem(a1: v60);
    g_nCAPTION_COLORSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v61 + 12))(
                               a1: v61,
                               a2: "CAPTION_COLOR",
                               a3: 1);
    v63 = _KeyValuesSystem(a1: v62);
    g_nGROUPSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v63 + 12))(a1: v63, a2: "GROUP", a3: 1);
    v65 = _KeyValuesSystem(a1: v64);
    g_nCAPTIONSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v65 + 12))(
                         a1: v65,
                         a2: "CAPTION",
                         a3: 1);
    v67 = _KeyValuesSystem(a1: v66);
    g_nCAPTION_PARAMSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v67 + 12))(
                               a1: v67,
                               a2: "CAPTION_PARAM",
                               a3: 1);
    v69 = _KeyValuesSystem(a1: v68);
    g_nBINDINGSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v69 + 12))(
                         a1: v69,
                         a2: "BINDING",
                         a3: 1);
    v71 = _KeyValuesSystem(a1: v70);
    g_nGAMEPAD_BINDINGSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v71 + 12))(
                                 a1: v71,
                                 a2: "GAMEPAD_BINDING",
                                 a3: 1);
    v73 = _KeyValuesSystem(a1: v72);
    g_nPRIORITYSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v73 + 12))(
                          a1: v73,
                          a2: "PRIORITY",
                          a3: 1);
    v75 = _KeyValuesSystem(a1: v74);
    g_nREPLACE_KEYSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v75 + 12))(
                             a1: v75,
                             a2: "REPLACE_KEY",
                             a3: 1);
    v77 = _KeyValuesSystem(a1: v76);
    g_nLOCK_DURATIONSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v77 + 12))(
                               a1: v77,
                               a2: "LOCK_DURATION",
                               a3: 1);
    v79 = _KeyValuesSystem(a1: v78);
    g_nCAN_OPEN_WHEN_DEADSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v79 + 12))(
                                    a1: v79,
                                    a2: "CAN_OPEN_WHEN_DEAD",
                                    a3: 1);
    v81 = _KeyValuesSystem(a1: v80);
    g_nBUMP_WITH_TIMEOUT_WHEN_LEARNEDSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v81 + 12))(
                                                a1: v81,
                                                a2: "BUMP_WITH_TIMEOUT_WHEN_LEARNED",
                                                a3: 1);
    v83 = _KeyValuesSystem(a1: v82);
    g_nONCE_LEARNED_NEVER_OPENSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v83 + 12))(
                                         a1: v83,
                                         a2: "ONCE_LEARNED_NEVER_OPEN",
                                         a3: 1);
    v85 = _KeyValuesSystem(a1: v84);
    g_nCAN_TIMEOUT_WHILE_INACTIVESymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v85 + 12))(
                                            a1: v85,
                                            a2: "CAN_TIMEOUT_WHILE_INACTIVE",
                                            a3: 1);
    v87 = _KeyValuesSystem(a1: v86);
    g_nUSABLE_IN_MIDAIRSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v87 + 12))(
                                  a1: v87,
                                  a2: "USABLE_IN_MIDAIR",
                                  a3: 1);
    v89 = _KeyValuesSystem(a1: v88);
    g_nTIMEOUTSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v89 + 12))(
                         a1: v89,
                         a2: "TIMEOUT",
                         a3: 1);
    v91 = _KeyValuesSystem(a1: v90);
    g_nUPDATE_INTERVALSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v91 + 12))(
                                 a1: v91,
                                 a2: "UPDATE_INTERVAL",
                                 a3: 1);
    v93 = _KeyValuesSystem(a1: v92);
    g_nSTART_SOUNDSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v93 + 12))(
                             a1: v93,
                             a2: "START_SOUND",
                             a3: 1);
    element = LESSON_VARIABLE_VOID;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "VOID", &element);
    element = LESSON_VARIABLE_LOCAL_PLAYER;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "LOCAL_PLAYER", &element);
    element = LESSON_VARIABLE_OUTPUT;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "OUTPUT", &element);
    element = LESSON_VARIABLE_ENTITY1;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "ENTITY1", &element);
    element = LESSON_VARIABLE_ENTITY2;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "ENTITY2", &element);
    element = LESSON_VARIABLE_STRING1;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "STRING1", &element);
    element = LESSON_VARIABLE_STRING2;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "STRING2", &element);
    element = LESSON_VARIABLE_INTEGER1;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "INTEGER1", &element);
    element = LESSON_VARIABLE_INTEGER2;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "INTEGER2", &element);
    element = LESSON_VARIABLE_FLOAT1;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "FLOAT1", &element);
    element = LESSON_VARIABLE_FLOAT2;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "FLOAT2", &element);
    element = LESSON_VARIABLE_ICON_TARGET;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "ICON_TARGET", &element);
    element = LESSON_VARIABLE_VGUI_TARGET_NAME;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "VGUI_TARGET_NAME", &element);
    element = LESSON_VARIABLE_VGUI_TARGET_LOOKUP;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "VGUI_TARGET_LOOKUP", &element);
    element = LESSON_VARIABLE_VGUI_TARGET_EDGE;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "VGUI_TARGET_EDGE", &element);
    element = LESSON_VARIABLE_FIXED_POSITION_X;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "FIXED_POSITION_X", &element);
    element = LESSON_VARIABLE_FIXED_POSITION_Y;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "FIXED_POSITION_Y", &element);
    element = LESSON_VARIABLE_FIXED_POSITION;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "FIXED_POSITION", &element);
    element = LESSON_VARIABLE_NO_ICON_TARGET;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "NO_ICON_TARGET", &element);
    element = LESSON_VARIABLE_ALLOW_NODRAW_TARGET;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "ALLOW_NODRAW_TARGET", &element);
    element = LESSON_VARIABLE_VISIBLE;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "VISIBLE", &element);
    element = LESSON_VARIABLE_SHOW_WHEN_OCCLUDED;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "SHOW_WHEN_OCCLUDED", &element);
    element = LESSON_VARIABLE_NO_OFFSCREEN;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "NO_OFFSCREEN", &element);
    element = LESSON_VARIABLE_FORCE_CAPTION;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "FORCE_CAPTION", &element);
    element = LESSON_VARIABLE_ONSCREEN_ICON;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "ONSCREEN_ICON", &element);
    element = LESSON_VARIABLE_OFFSCREEN_ICON;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "OFFSCREEN_ICON", &element);
    element = LESSON_VARIABLE_ICON_OFFSET;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "ICON_OFFSET", &element);
    element = LESSON_VARIABLE_ICON_RELATIVE_OFFSET;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "ICON_RELATIVE_OFFSET", &element);
    element = LESSON_VARIABLE_RANGE;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "RANGE", &element);
    element = LESSON_VARIABLE_FLAGS;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "FLAGS", &element);
    element = LESSON_VARIABLE_CAPTION_COLOR;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "CAPTION_COLOR", &element);
    element = LESSON_VARIABLE_GROUP;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "GROUP", &element);
    element = LESSON_VARIABLE_CAPTION;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "CAPTION", &element);
    element = LESSON_VARIABLE_CAPTION_PARAM;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "CAPTION_PARAM", &element);
    element = LESSON_VARIABLE_BINDING;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "BINDING", &element);
    element = LESSON_VARIABLE_GAMEPAD_BINDING;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "GAMEPAD_BINDING", &element);
    element = LESSON_VARIABLE_PRIORITY;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "PRIORITY", &element);
    element = LESSON_VARIABLE_REPLACE_KEY;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "REPLACE_KEY", &element);
    element = LESSON_VARIABLE_LOCK_DURATION;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "LOCK_DURATION", &element);
    element = LESSON_VARIABLE_CAN_OPEN_WHEN_DEAD;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "CAN_OPEN_WHEN_DEAD", &element);
    element = LESSON_VARIABLE_BUMP_WITH_TIMEOUT_WHEN_LEARNED;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "BUMP_WITH_TIMEOUT_WHEN_LEARNED", &element);
    element = LESSON_VARIABLE_ONCE_LEARNED_NEVER_OPEN;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "ONCE_LEARNED_NEVER_OPEN", &element);
    element = LESSON_VARIABLE_CAN_TIMEOUT_WHILE_INACTIVE;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "CAN_TIMEOUT_WHILE_INACTIVE", &element);
    element = LESSON_VARIABLE_USABLE_IN_MIDAIR;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "USABLE_IN_MIDAIR", &element);
    element = LESSON_VARIABLE_TIMEOUT;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "TIMEOUT", &element);
    element = LESSON_VARIABLE_UPDATE_INTERVAL;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "UPDATE_INTERVAL", &element);
    element = LESSON_VARIABLE_START_SOUND;
    CUtlDict<enum LessonVariable,int>::Insert(this: &g_NameToTypeMap, pName: "START_SOUND", &element);
    element = LESSON_VARIABLE_LOCAL_PLAYER;
    CUtlDict<enum _fieldtypes,int>::Insert(this: &g_TypeToParamTypeMap, pName: "float", (const _fieldtypes *)&element);
    element = LESSON_VARIABLE_OUTPUT;
    CUtlDict<enum _fieldtypes,int>::Insert(this: &g_TypeToParamTypeMap, pName: "string", (const _fieldtypes *)&element);
    element = LESSON_VARIABLE_STRING1;
    CUtlDict<enum _fieldtypes,int>::Insert(this: &g_TypeToParamTypeMap, pName: "int", (const _fieldtypes *)&element);
    element = LESSON_VARIABLE_STRING1;
    CUtlDict<enum _fieldtypes,int>::Insert(this: &g_TypeToParamTypeMap, pName: "integer", (const _fieldtypes *)&element);
    element = LESSON_VARIABLE_STRING1;
    CUtlDict<enum _fieldtypes,int>::Insert(this: &g_TypeToParamTypeMap, pName: "short", (const _fieldtypes *)&element);
    element = LESSON_VARIABLE_STRING1;
    CUtlDict<enum _fieldtypes,int>::Insert(this: &g_TypeToParamTypeMap, pName: "long", (const _fieldtypes *)&element);
    element = LESSON_VARIABLE_STRING2;
    CUtlDict<enum _fieldtypes,int>::Insert(this: &g_TypeToParamTypeMap, pName: "bool", (const _fieldtypes *)&element);
    element = LESSON_VARIABLE_ICON_TARGET;
    CUtlDict<enum _fieldtypes,int>::Insert(this: &g_TypeToParamTypeMap, pName: "player", (const _fieldtypes *)&element);
    element = LESSON_VARIABLE_VGUI_TARGET_LOOKUP;
    CUtlDict<enum _fieldtypes,int>::Insert(this: &g_TypeToParamTypeMap, pName: "entity", (const _fieldtypes *)&element);
    element = LESSON_VARIABLE_FLOAT2;
    CUtlDict<enum _fieldtypes,int>::Insert(this: &g_TypeToParamTypeMap, pName: "convar", (const _fieldtypes *)&element);
    element = LESSON_VARIABLE_VOID;
    CUtlDict<enum _fieldtypes,int>::Insert(this: &g_TypeToParamTypeMap, pName: "void", (const _fieldtypes *)&element);
    element = LESSON_VARIABLE_LOCAL_PLAYER;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "scope in", (const int *)&element);
    element = LESSON_VARIABLE_OUTPUT;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "scope out", (const int *)&element);
    element = LESSON_VARIABLE_ENTITY1;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "close", (const int *)&element);
    element = LESSON_VARIABLE_ENTITY2;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "success", (const int *)&element);
    element = LESSON_VARIABLE_STRING1;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "lock", (const int *)&element);
    element = LESSON_VARIABLE_STRING2;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "present complete",
      (const int *)&element);
    element = LESSON_VARIABLE_INTEGER1;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "present start",
      (const int *)&element);
    element = LESSON_VARIABLE_INTEGER2;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "present end", (const int *)&element);
    element = LESSON_VARIABLE_FLOAT1;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "reference open",
      (const int *)&element);
    element = LESSON_VARIABLE_FLOAT2;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "is multiplayer",
      (const int *)&element);
    element = LESSON_VARIABLE_ICON_TARGET;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "set", (const int *)&element);
    element = LESSON_VARIABLE_VGUI_TARGET_NAME;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "add", (const int *)&element);
    element = LESSON_VARIABLE_VGUI_TARGET_LOOKUP;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "subtract", (const int *)&element);
    element = LESSON_VARIABLE_VGUI_TARGET_EDGE;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "multiply", (const int *)&element);
    element = LESSON_VARIABLE_FIXED_POSITION_X;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "is", (const int *)&element);
    element = LESSON_VARIABLE_FIXED_POSITION_Y;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "less than", (const int *)&element);
    element = LESSON_VARIABLE_FIXED_POSITION;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "has prefix", (const int *)&element);
    element = LESSON_VARIABLE_NO_ICON_TARGET;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "has bit", (const int *)&element);
    element = LESSON_VARIABLE_ALLOW_NODRAW_TARGET;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "bit count is", (const int *)&element);
    element = LESSON_VARIABLE_VISIBLE;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "bit count less than",
      (const int *)&element);
    element = LESSON_VARIABLE_SHOW_WHEN_OCCLUDED;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "get distance", (const int *)&element);
    element = LESSON_VARIABLE_NO_OFFSCREEN;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "get angular distance",
      (const int *)&element);
    element = LESSON_VARIABLE_FORCE_CAPTION;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "get player display name",
      (const int *)&element);
    element = LESSON_VARIABLE_ONSCREEN_ICON;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "classname is", (const int *)&element);
    element = LESSON_VARIABLE_OFFSCREEN_ICON;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "modelname is", (const int *)&element);
    element = LESSON_VARIABLE_ICON_OFFSET;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "team is", (const int *)&element);
    element = LESSON_VARIABLE_ICON_RELATIVE_OFFSET;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "health less than",
      (const int *)&element);
    element = LESSON_VARIABLE_RANGE;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "health percentage less than",
      (const int *)&element);
    element = LESSON_VARIABLE_FLAGS;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "get active weapon",
      (const int *)&element);
    element = LESSON_VARIABLE_CAPTION_COLOR;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "weapon is", (const int *)&element);
    element = LESSON_VARIABLE_GROUP;
    CUtlDict<int,int>::Insert(this: &CScriptedIconLesson::LessonActionMap, pName: "weapon has", (const int *)&element);
    element = LESSON_VARIABLE_CAPTION;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "get active weapon slot",
      (const int *)&element);
    element = LESSON_VARIABLE_CAPTION_PARAM;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "get weapon slot",
      (const int *)&element);
    element = LESSON_VARIABLE_BINDING;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "get weapon in slot",
      (const int *)&element);
    element = LESSON_VARIABLE_GAMEPAD_BINDING;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "clip percentage less than",
      (const int *)&element);
    element = LESSON_VARIABLE_PRIORITY;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "weapon ammo low",
      (const int *)&element);
    element = LESSON_VARIABLE_REPLACE_KEY;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "weapon ammo full",
      (const int *)&element);
    element = LESSON_VARIABLE_LOCK_DURATION;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "weapon ammo empty",
      (const int *)&element);
    element = LESSON_VARIABLE_CAN_OPEN_WHEN_DEAD;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "weapon can use",
      (const int *)&element);
    element = LESSON_VARIABLE_BUMP_WITH_TIMEOUT_WHEN_LEARNED;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "use target is",
      (const int *)&element);
    element = LESSON_VARIABLE_ONCE_LEARNED_NEVER_OPEN;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "get use target",
      (const int *)&element);
    element = LESSON_VARIABLE_CAN_TIMEOUT_WHILE_INACTIVE;
    CUtlDict<int,int>::Insert(
      this: &CScriptedIconLesson::LessonActionMap,
      pName: "get potential use target",
      (const int *)&element);
    CScriptedIconLesson::Mod_PreReadLessonsFromFile();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100510B0
// Name: enum _fieldtypes LessonParamTypeFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
_fieldtypes __cdecl LessonParamTypeFromString(const char *pchName)
{
  int v1; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+0h] [ebp-8h] BYREF

  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile();
  if ( pchName != nullptr )
  {
    search.key = pchName;
    v1 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
           this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
           &search);
    if ( v1 != -1 )
      return g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v1].m_Data.elem;
  }
  DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", pchName);
  return FIELD_VOID;
}

//------------------------------------------------------------------------------
// Address: 0x10051110
// Name: private: void CScriptedIconLesson::InitElementsFromKeys(class CUtlVector<struct LessonElement_t,class CUtlMemory<struct LessonElement_t,int>> __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CScriptedIconLesson::InitElementsFromKeys(
        CScriptedIconLesson *this@<ecx>,
        const char *a2@<ebx>,
        CUtlVector<LessonElement_t,CUtlMemory<LessonElement_t,int> > *pLessonElements,
        KeyValues *pKey)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  const char *v6; // eax
  const char *v7; // esi
  int v8; // eax
  char *v9; // eax
  const char *v10; // esi
  char v11; // al
  int v12; // eax
  const char *v13; // eax
  const char *String; // eax
  void *v15; // ecx
  const char *v16; // esi
  int v17; // eax
  const char *v18; // edi
  const char *v19; // eax
  char *v20; // eax
  char *m_pszString; // esi
  const char *v22; // eax
  const char *v23; // ecx
  KeyValues *v24; // esi
  const char *v25; // eax
  int v26; // eax
  char v27; // bl
  CUtlSymbol *v28; // eax
  CUtlVector<LessonElement_t,CUtlMemory<LessonElement_t,int> > *v29; // edx
  int m_Size; // esi
  unsigned __int16 m_Id; // di
  int m_nAllocationCount; // eax
  LessonElement_t *m_pMemory; // ecx
  int v34; // eax
  int v35; // eax
  LessonVariable v36; // edx
  int v37; // ecx
  _fieldtypes v38; // edx
  LessonVariable v39; // ecx
  const char *v40; // [esp-4h] [ebp-160h]
  char szSubKeyName[274]; // [esp+Ch] [ebp-150h] BYREF
  char v42; // [esp+11Eh] [ebp-3Eh]
  CUtlMap<char const *,enum LessonVariable,int>::Node_t search; // [esp+120h] [ebp-3Ch] BYREF
  CUtlMap<char const *,int,int>::Node_t v44; // [esp+128h] [ebp-34h] BYREF
  CUtlMap<char const *,enum LessonVariable,int>::Node_t v45; // [esp+130h] [ebp-2Ch] BYREF
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t v46; // [esp+138h] [ebp-24h] BYREF
  CUtlSymbol result; // [esp+142h] [ebp-1Ah] BYREF
  CScriptedIconLesson *v48; // [esp+144h] [ebp-18h]
  LessonVariable iVariable; // [esp+148h] [ebp-14h]
  LessonVariable iParamVarIndex; // [esp+14Ch] [ebp-10h]
  _fieldtypes paramType; // [esp+150h] [ebp-Ch]
  int iAction; // [esp+154h] [ebp-8h]
  KeyValues *pSubKey; // [esp+158h] [ebp-4h]
  char bNot_3; // [esp+16Bh] [ebp+Fh]

  v48 = this;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKey);
  pSubKey = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      _V_strcpy(dest: szSubKeyName, src: Name);
      v6 = strtok(string: szSubKeyName, control: " ");
      v7 = v6;
      if ( v6 == nullptr
        || (search.key = v6,
            (v8 = CUtlRBTree<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int,CUtlMap<char const *,enum LessonVariable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int>,int>>::Find(
                    this: &g_NameToTypeMap.m_Elements.m_Tree,
                    &search)) == -1) )
      {
        DevWarning(a1: "Invalid scripted lesson variable: %s\n", v7);
        iVariable = LESSON_VARIABLE_TOTAL;
      }
      else
      {
        iVariable = g_NameToTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
      }
      v9 = strtok(string: nullptr, control: prType);
      v10 = v9;
      LOBYTE(a2) = 0;
      iAction = 0;
      bNot_3 = 0;
      if ( v9 != nullptr && (v11 = *v9, *v10 != 0) )
      {
        if ( v11 == 63 )
        {
          ++v10;
          LOBYTE(a2) = 1;
        }
        if ( *v10 == 33 )
        {
          ++v10;
          bNot_3 = 1;
        }
        if ( v10 == nullptr
          || (v44.key = v10,
              (v12 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                       this: &CScriptedIconLesson::LessonActionMap.m_Elements.m_Tree,
                       search: &v44)) == -1) )
        {
          DevWarning(a1: "Invalid scripted lesson action: %s\n", v10);
          iAction = 0;
        }
        else
        {
          iAction = CScriptedIconLesson::LessonActionMap.m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem;
        }
      }
      else
      {
        v13 = KeyValues::GetName(this: FirstSubKey);
        DevWarning(a1: "No action specified for variable: \"%s\"\n", v13);
      }
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
      _V_strcpy(dest: szSubKeyName, src: String);
      v16 = strtok(string: szSubKeyName, control: " ");
      if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
        CScriptedIconLesson::PreReadLessonsFromFile(this: v15);
      if ( v16 == nullptr
        || (v46.key = v16,
            (v17 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
                     this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
                     search: &v46)) == -1) )
      {
        DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", v16);
        paramType = FIELD_VOID;
      }
      else
      {
        paramType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v17].m_Data.elem;
      }
      v18 = prType;
      if ( paramType == FIELD_VOID || (v18 = strtok(string: nullptr, control: prType)) != nullptr )
      {
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && ((gameinstructor_verbose_lesson.m_nFlags & 0x1000) != 0
           || (v20 = gameinstructor_verbose_lesson.m_pParent->m_Value.m_pszString) != nullptr && *v20 != 0) )
        {
          if ( (gameinstructor_verbose_lesson.m_nFlags & 0x1000) != 0 )
          {
            m_pszString = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            m_pszString = gameinstructor_verbose_lesson.m_pParent->m_Value.m_pszString;
            if ( m_pszString == nullptr )
              m_pszString = (char *)prType;
          }
          v22 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v48->m_stringName.m_SymbolId);
          if ( V_stristr(a1: v23, a2, pStr: v22, pSearch: m_pszString) != nullptr )
          {
            v24 = pSubKey;
            v40 = KeyValues::GetString(this: pSubKey, keyName: nullptr, defaultValue: prType);
            v25 = KeyValues::GetName(this: v24);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\t\tElement \"%s %s\" added.\n", v25, v40);
          }
        }
        v45.key = v18;
        v26 = CUtlRBTree<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int,CUtlMap<char const *,enum LessonVariable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum LessonVariable,int>::Node_t,int>,int>>::Find(
                this: &g_NameToTypeMap.m_Elements.m_Tree,
                search: &v45);
        if ( v26 == -1 )
          iParamVarIndex = LESSON_VARIABLE_TOTAL;
        else
          iParamVarIndex = g_NameToTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v26].m_Data.elem;
        v27 = bNot_3 & 1 | v42 & 0xFC | (2 * ((unsigned __int8)a2 & 1));
        v28 = CUtlSymbolTable::AddString(this: &g_CGameInstructorSymbolSymbolTable, &result, pString: v18);
        v29 = pLessonElements;
        m_Size = pLessonElements->m_Size;
        m_Id = v28->m_Id;
        m_nAllocationCount = pLessonElements->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
            this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)pLessonElements,
            num: m_Size - m_nAllocationCount + 1);
          v29 = pLessonElements;
        }
        ++v29->m_Size;
        m_pMemory = v29->m_Memory.m_pMemory;
        v34 = v29->m_Size - m_Size - 1;
        v29->m_pElements = v29->m_Memory.m_pMemory;
        if ( v34 > 0 )
        {
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v34);
          v29 = pLessonElements;
        }
        v35 = (int)&v29->m_Memory.m_pMemory[m_Size];
        if ( v35 != 0 )
        {
          v36 = iVariable;
          *(_WORD *)(v35 + 16) = -1;
          v37 = iAction;
          *(_DWORD *)v35 = v36;
          *(_BYTE *)(v35 + 18) ^= (v27 ^ *(_BYTE *)(v35 + 18)) & 3;
          v38 = paramType;
          *(_DWORD *)(v35 + 8) = v37;
          v39 = iParamVarIndex;
          *(_WORD *)(v35 + 16) = m_Id;
          *(_DWORD *)(v35 + 4) = v39;
          *(_DWORD *)(v35 + 12) = v38;
        }
      }
      else
      {
        v19 = KeyValues::GetName(this: pSubKey);
        DevWarning(a1: "No parameter specified for action: \"%s\"\n", v19);
      }
      pSubKey = KeyValues::GetNextKey(this: pSubKey);
      if ( pSubKey == nullptr )
        break;
      FirstSubKey = pSubKey;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051490
// Name: private: void CScriptedIconLesson::InitFromKeys(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptedIconLesson::InitFromKeys(CScriptedIconLesson *this, KeyValues *pKey)
{
  KeyValues *v2; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  KeyValues *i; // esi
  const char *String; // eax
  const char *v22; // eax
  int m_nAllocationCount; // eax
  CGameInstructorSymbol *m_pMemory; // ecx
  int v25; // eax
  CGameInstructorSymbol *v26; // eax
  const char *Name; // eax
  const char *v28; // eax
  const char *v29; // eax
  const char *v30; // eax
  const char *v31; // eax
  const char *v32; // eax
  const char *v33; // eax
  const char *v34; // eax
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // ebx
  int v39; // eax
  const char *v40; // eax
  const char *v41; // ebx
  int v42; // eax
  const char *v43; // eax
  const char *v44; // eax
  const char *v45; // ebx
  int v46; // eax
  const char *v47; // eax
  const char *v48; // eax
  const char *v49; // ebx
  int v50; // eax
  const char *v51; // eax
  const char *v52; // ebx
  int v53; // eax
  const char *v54; // eax
  const char *v55; // ebx
  int v56; // eax
  const char *v57; // eax
  const char *v58; // ebx
  int v59; // eax
  const char *v60; // eax
  const char *v61; // ebx
  int v62; // eax
  const char *v63; // eax
  const char *v64; // eax
  const char *v65; // ebx
  int v66; // eax
  const char *v67; // eax
  const char *v68; // eax
  const char *v69; // ebx
  int v70; // eax
  const char *v71; // eax
  const char *v72; // ebx
  int v73; // eax
  const char *v74; // eax
  const char *v75; // ebx
  int v76; // eax
  const char *v77; // eax
  const char *v78; // eax
  const char *v79; // eax
  const char *v80; // eax
  const char *v81; // eax
  const char *v82; // eax
  const char *v83; // eax
  const char *v84; // eax
  const char *v85; // ebx
  int v86; // eax
  const char *v87; // eax
  const char *v88; // eax
  const char *v89; // ebx
  int v90; // eax
  const char *v91; // eax
  const char *v92; // eax
  const char *v93; // ebx
  int v94; // eax
  const char *v95; // eax
  const char *v96; // ebx
  int v97; // eax
  const char *v98; // eax
  const char *v99; // ebx
  int v100; // eax
  const char *v101; // eax
  const char *v102; // ebx
  int v103; // eax
  const char *v104; // eax
  const char *v105; // ebx
  int v106; // eax
  const char *v107; // eax
  const char *v108; // eax
  const char *v109; // ebx
  int v110; // eax
  const char *v111; // eax
  const char *v112; // eax
  const char *v113; // ebx
  int v114; // eax
  const char *v115; // eax
  const char *v116; // eax
  const char *v117; // ebx
  int v118; // eax
  const char *v119; // eax
  const char *v120; // eax
  const char *v121; // ebx
  int v122; // eax
  const char *v123; // eax
  const char *v124; // eax
  const char *v125; // ebx
  int v126; // eax
  const char *v127; // eax
  const char *v128; // eax
  const char *v129; // ebx
  int v130; // eax
  const char *v131; // eax
  const char *v132; // ebx
  int v133; // eax
  const char *v134; // eax
  const char *v135; // eax
  const char *v136; // ebx
  int v137; // eax
  const char *v138; // eax
  const char *v139; // eax
  const char *v140; // eax
  const char *v141; // eax
  const char *v142; // eax
  const char *v143; // eax
  const char *v144; // ebx
  int v145; // eax
  const char *v146; // eax
  const char *v147; // ebx
  int v148; // eax
  const char *v149; // eax
  const char *v150; // ebx
  int v151; // eax
  const char *v152; // eax
  SplitScreenConVarRef v153; // [esp+90h] [ebp-158h] BYREF
  SplitScreenConVarRef v154; // [esp+A0h] [ebp-148h] BYREF
  SplitScreenConVarRef v155; // [esp+B0h] [ebp-138h] BYREF
  ConVarRef v156; // [esp+C0h] [ebp-128h] BYREF
  ConVarRef tempCVar; // [esp+C8h] [ebp-120h] BYREF
  SplitScreenConVarRef v158; // [esp+D0h] [ebp-118h] BYREF
  SplitScreenConVarRef v159; // [esp+E0h] [ebp-108h] BYREF
  SplitScreenConVarRef v160; // [esp+F0h] [ebp-F8h] BYREF
  SplitScreenConVarRef v161; // [esp+100h] [ebp-E8h] BYREF
  SplitScreenConVarRef v162; // [esp+110h] [ebp-D8h] BYREF
  SplitScreenConVarRef v163; // [esp+120h] [ebp-C8h] BYREF
  SplitScreenConVarRef v164; // [esp+130h] [ebp-B8h] BYREF
  SplitScreenConVarRef v165; // [esp+140h] [ebp-A8h] BYREF
  SplitScreenConVarRef v166; // [esp+150h] [ebp-98h] BYREF
  SplitScreenConVarRef v167; // [esp+160h] [ebp-88h] BYREF
  SplitScreenConVarRef v168; // [esp+170h] [ebp-78h] BYREF
  CUtlSymbol result; // [esp+180h] [ebp-68h] BYREF
  CGameInstructorSymbol v170; // [esp+182h] [ebp-66h] BYREF
  CGameInstructorSymbol v171; // [esp+184h] [ebp-64h] BYREF
  CGameInstructorSymbol v172; // [esp+186h] [ebp-62h] BYREF
  CGameInstructorSymbol v173; // [esp+188h] [ebp-60h] BYREF
  CGameInstructorSymbol v174; // [esp+18Ah] [ebp-5Eh] BYREF
  CGameInstructorSymbol v175; // [esp+18Ch] [ebp-5Ch] BYREF
  CGameInstructorSymbol v176; // [esp+18Eh] [ebp-5Ah] BYREF
  CGameInstructorSymbol v177; // [esp+190h] [ebp-58h] BYREF
  CGameInstructorSymbol v178; // [esp+192h] [ebp-56h] BYREF
  CGameInstructorSymbol v179; // [esp+194h] [ebp-54h] BYREF
  CGameInstructorSymbol v180; // [esp+196h] [ebp-52h] BYREF
  CGameInstructorSymbol v181; // [esp+198h] [ebp-50h] BYREF
  CGameInstructorSymbol v182; // [esp+19Ah] [ebp-4Eh] BYREF
  CGameInstructorSymbol v183; // [esp+19Ch] [ebp-4Ch] BYREF
  CGameInstructorSymbol v184; // [esp+19Eh] [ebp-4Ah] BYREF
  CGameInstructorSymbol v185; // [esp+1A0h] [ebp-48h] BYREF
  CGameInstructorSymbol v186; // [esp+1A2h] [ebp-46h] BYREF
  CGameInstructorSymbol v187; // [esp+1A4h] [ebp-44h] BYREF
  CGameInstructorSymbol v188; // [esp+1A6h] [ebp-42h] BYREF
  CGameInstructorSymbol v189; // [esp+1A8h] [ebp-40h] BYREF
  CGameInstructorSymbol v190; // [esp+1AAh] [ebp-3Eh] BYREF
  CGameInstructorSymbol v191; // [esp+1ACh] [ebp-3Ch] BYREF
  CGameInstructorSymbol v192; // [esp+1AEh] [ebp-3Ah] BYREF
  CGameInstructorSymbol v193; // [esp+1B0h] [ebp-38h] BYREF
  CGameInstructorSymbol v194; // [esp+1B2h] [ebp-36h] BYREF
  CGameInstructorSymbol v195; // [esp+1B4h] [ebp-34h] BYREF
  CGameInstructorSymbol v196; // [esp+1B6h] [ebp-32h] BYREF
  CGameInstructorSymbol v197; // [esp+1B8h] [ebp-30h] BYREF
  CGameInstructorSymbol v198; // [esp+1BAh] [ebp-2Eh] BYREF
  CGameInstructorSymbol v199; // [esp+1BCh] [ebp-2Ch] BYREF
  CGameInstructorSymbol v200; // [esp+1BEh] [ebp-2Ah] BYREF
  CGameInstructorSymbol v201; // [esp+1C0h] [ebp-28h] BYREF
  CGameInstructorSymbol v202; // [esp+1C2h] [ebp-26h] BYREF
  CGameInstructorSymbol v203; // [esp+1C4h] [ebp-24h] BYREF
  CGameInstructorSymbol v204; // [esp+1C6h] [ebp-22h] BYREF
  CGameInstructorSymbol v205; // [esp+1C8h] [ebp-20h] BYREF
  CGameInstructorSymbol v206; // [esp+1CAh] [ebp-1Eh] BYREF
  CGameInstructorSymbol v207; // [esp+1CCh] [ebp-1Ch] BYREF
  CGameInstructorSymbol v208; // [esp+1CEh] [ebp-1Ah] BYREF
  CGameInstructorSymbol v209; // [esp+1D0h] [ebp-18h] BYREF
  CGameInstructorSymbol v210; // [esp+1D2h] [ebp-16h] BYREF
  CGameInstructorSymbol v211; // [esp+1D4h] [ebp-14h] BYREF
  CGameInstructorSymbol v212; // [esp+1D6h] [ebp-12h] BYREF
  CGameInstructorSymbol v213; // [esp+1D8h] [ebp-10h] BYREF
  CGameInstructorSymbol v214; // [esp+1DAh] [ebp-Eh] BYREF
  CGameInstructorSymbol v215; // [esp+1DCh] [ebp-Ch] BYREF
  CGameInstructorSymbol v216; // [esp+1DEh] [ebp-Ah] BYREF
  LessonEvent_t *pLessonEvent; // [esp+1E0h] [ebp-8h]
  KeyValues *pEventKey; // [esp+1E4h] [ebp-4h]

  v2 = pKey;
  if ( pKey != nullptr )
  {
    if ( (_S6_9 & 1) == 0 )
    {
      _S6_9 |= 1u;
      v4 = _KeyValuesSystem(a1: this);
      s_nInstanceTypeSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v4 + 12))(
                                a1: v4,
                                a2: "instance_type",
                                a3: 1);
    }
    if ( (_S6_9 & 2) == 0 )
    {
      _S6_9 |= 2u;
      v5 = _KeyValuesSystem(a1: this);
      s_nReplaceKeySymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 12))(
                              a1: v5,
                              a2: "replace_key",
                              a3: 1);
    }
    if ( (_S6_9 & 4) == 0 )
    {
      _S6_9 |= 4u;
      v6 = _KeyValuesSystem(a1: this);
      s_nFixedInstancesMaxSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v6 + 12))(
                                     a1: v6,
                                     a2: "fixed_instances_max",
                                     a3: 1);
    }
    if ( (_S6_9 & 8) == 0 )
    {
      _S6_9 |= 8u;
      v7 = _KeyValuesSystem(a1: this);
      s_nReplaceOnlyWhenStopped = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v7 + 12))(
                                    a1: v7,
                                    a2: "replace_only_when_stopped",
                                    a3: 1);
    }
    if ( (_S6_9 & 0x10) == 0 )
    {
      _S6_9 |= 0x10u;
      v8 = _KeyValuesSystem(a1: this);
      s_nTeamSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v8 + 12))(a1: v8, a2: "team", a3: 1);
    }
    if ( (_S6_9 & 0x20) == 0 )
    {
      _S6_9 |= 0x20u;
      v9 = _KeyValuesSystem(a1: this);
      s_nOnlyKeyboardSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v9 + 12))(
                                a1: v9,
                                a2: "only_keyboard",
                                a3: 1);
    }
    if ( (_S6_9 & 0x40) == 0 )
    {
      _S6_9 |= 0x40u;
      v10 = _KeyValuesSystem(a1: this);
      s_nOnlyGamepadSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v10 + 12))(
                               a1: v10,
                               a2: "only_gamepad",
                               a3: 1);
    }
    if ( (_S6_9 & 0x80u) == 0 )
    {
      _S6_9 |= 0x80u;
      v11 = _KeyValuesSystem(a1: this);
      s_nNoSplitscreenSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v11 + 12))(
                                 a1: v11,
                                 a2: "no_splitscreen",
                                 a3: 1);
    }
    if ( (_S6_9 & 0x100) == 0 )
    {
      _S6_9 |= 0x100u;
      v12 = _KeyValuesSystem(a1: this);
      s_nDisplayLimitSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v12 + 12))(
                                a1: v12,
                                a2: "display_limit",
                                a3: 1);
    }
    if ( (_S6_9 & 0x200) == 0 )
    {
      _S6_9 |= 0x200u;
      v13 = _KeyValuesSystem(a1: this);
      s_nSuccessLimitSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v13 + 12))(
                                a1: v13,
                                a2: "success_limit",
                                a3: 1);
    }
    if ( (_S6_9 & 0x400) == 0 )
    {
      _S6_9 |= 0x400u;
      v14 = _KeyValuesSystem(a1: this);
      s_nPreReqSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v14 + 12))(
                          a1: v14,
                          a2: "prereq",
                          a3: 1);
    }
    if ( (_S6_9 & 0x800) == 0 )
    {
      _S6_9 |= 0x800u;
      v15 = _KeyValuesSystem(a1: this);
      s_nOpenSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v15 + 12))(a1: v15, a2: "open", a3: 1);
    }
    if ( (_S6_9 & 0x1000) == 0 )
    {
      _S6_9 |= 0x1000u;
      v16 = _KeyValuesSystem(a1: this);
      s_nCloseSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v16 + 12))(
                         a1: v16,
                         a2: "close",
                         a3: 1);
    }
    if ( (_S6_9 & 0x2000) == 0 )
    {
      _S6_9 |= 0x2000u;
      v17 = _KeyValuesSystem(a1: this);
      s_nSuccessSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v17 + 12))(
                           a1: v17,
                           a2: "success",
                           a3: 1);
    }
    if ( (_S6_9 & 0x4000) == 0 )
    {
      _S6_9 |= 0x4000u;
      v18 = _KeyValuesSystem(a1: this);
      s_nOnOpenSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v18 + 12))(
                          a1: v18,
                          a2: "onopen",
                          a3: 1);
    }
    if ( (_S6_9 & 0x8000) == 0 )
    {
      _S6_9 |= 0x8000u;
      v19 = _KeyValuesSystem(a1: this);
      s_nUpdateSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v19 + 12))(
                          a1: v19,
                          a2: "update",
                          a3: 1);
    }
    for ( i = KeyValues::GetFirstSubKey(this: v2); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      if ( KeyValues::GetNameSymbol(this: i) == s_nInstanceTypeSymbol )
      {
        this->m_iInstanceType = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
      }
      else if ( KeyValues::GetNameSymbol(this: i) == s_nReplaceKeySymbol )
      {
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
        this->m_stringReplaceKey.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                            this: &g_CGameInstructorSymbolSymbolTable,
                                                            &result,
                                                            pString: String)->m_Id;
      }
      else if ( KeyValues::GetNameSymbol(this: i) == s_nFixedInstancesMaxSymbol )
      {
        this->m_iFixedInstancesMax = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
      }
      else if ( KeyValues::GetNameSymbol(this: i) == s_nReplaceOnlyWhenStopped )
      {
        this->m_bReplaceOnlyWhenStopped = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
      }
      else if ( KeyValues::GetNameSymbol(this: i) == s_nTeamSymbol )
      {
        this->m_iTeam = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
      }
      else if ( KeyValues::GetNameSymbol(this: i) == s_nOnlyKeyboardSymbol )
      {
        this->m_bOnlyKeyboard = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
      }
      else if ( KeyValues::GetNameSymbol(this: i) == s_nOnlyGamepadSymbol )
      {
        this->m_bOnlyGamepad = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
      }
      else if ( KeyValues::GetNameSymbol(this: i) == s_nNoSplitscreenSymbol )
      {
        this->m_bNoSplitscreen = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
      }
      else if ( KeyValues::GetNameSymbol(this: i) == s_nDisplayLimitSymbol )
      {
        this->m_iDisplayLimit = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
      }
      else if ( KeyValues::GetNameSymbol(this: i) == s_nSuccessLimitSymbol )
      {
        this->m_iSuccessLimit = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
      }
      else
      {
        if ( KeyValues::GetNameSymbol(this: i) == s_nPreReqSymbol )
        {
          v22 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
          CGameInstructorSymbol::CGameInstructorSymbol(this: (CGameInstructorSymbol *)&pKey + 1, pStr: v22);
          m_nAllocationCount = this->m_PrerequisiteNames.m_Memory.m_nAllocationCount;
          pEventKey = (KeyValues *)this->m_PrerequisiteNames.m_Size;
          if ( (int)pEventKey + 1 > m_nAllocationCount )
            CUtlMemory<wchar_t,int>::Grow(
              this: (CUtlMemory<CUtlSymbol,int> *)&this->m_PrerequisiteNames,
              num: (int)pEventKey - m_nAllocationCount + 1);
          ++this->m_PrerequisiteNames.m_Size;
          m_pMemory = this->m_PrerequisiteNames.m_Memory.m_pMemory;
          v25 = this->m_PrerequisiteNames.m_Size - (_DWORD)pEventKey - 1;
          this->m_PrerequisiteNames.m_pElements = m_pMemory;
          if ( v25 > 0 )
            _V_memmove(dest: &m_pMemory[(_DWORD)pEventKey + 1], src: &m_pMemory[(_DWORD)pEventKey], count: 2 * v25);
          v26 = &this->m_PrerequisiteNames.m_Memory.m_pMemory[(_DWORD)pEventKey];
          if ( v26 != nullptr )
            v26->m_SymbolId.m_Id = *(_WORD *)((unsigned __int16)&pKey + 2);
          continue;
        }
        if ( KeyValues::GetNameSymbol(this: i) == s_nOpenSymbol )
        {
          for ( pEventKey = KeyValues::GetFirstTrueSubKey(this: i);
                pEventKey != nullptr;
                pEventKey = KeyValues::GetNextTrueSubKey(this: pEventKey) )
          {
            pLessonEvent = CScriptedIconLesson::AddOpenEvent(this);
            Name = KeyValues::GetName(this: pEventKey);
            CGameInstructorSymbol::CGameInstructorSymbol(this: &v188, pStr: Name);
            pLessonEvent->szEventName = v188;
            if ( gameinstructor_verbose.m_pParent != nullptr
              && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
              && CBaseLesson::ShouldShowSpew(this, a2: (const char *)ConColorMsg) )
            {
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tAdding open event ");
              v28 = CGameInstructorSymbol::String(this: &pLessonEvent->szEventName);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseOpen, a2: "\"%s\" ", v28);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "...\n");
            }
            CScriptedIconLesson::InitElementsFromKeys(
              this,
              a2: (const char *)ConColorMsg,
              pLessonElements: &pLessonEvent->elements,
              pKey: pEventKey);
          }
          continue;
        }
        if ( KeyValues::GetNameSymbol(this: i) == s_nCloseSymbol )
        {
          for ( pEventKey = KeyValues::GetFirstTrueSubKey(this: i);
                pEventKey != nullptr;
                pEventKey = KeyValues::GetNextTrueSubKey(this: pEventKey) )
          {
            pLessonEvent = CScriptedIconLesson::AddCloseEvent(this);
            v29 = KeyValues::GetName(this: pEventKey);
            CGameInstructorSymbol::CGameInstructorSymbol(this: &v170, pStr: v29);
            pLessonEvent->szEventName = v170;
            if ( gameinstructor_verbose.m_pParent != nullptr
              && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
              && CBaseLesson::ShouldShowSpew(this, a2: (const char *)ConColorMsg) )
            {
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tAdding close event ");
              v30 = CGameInstructorSymbol::String(this: &pLessonEvent->szEventName);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\" ", v30);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "...\n");
            }
            CScriptedIconLesson::InitElementsFromKeys(
              this,
              a2: (const char *)ConColorMsg,
              pLessonElements: &pLessonEvent->elements,
              pKey: pEventKey);
          }
          continue;
        }
        if ( KeyValues::GetNameSymbol(this: i) == s_nSuccessSymbol )
        {
          for ( pEventKey = KeyValues::GetFirstTrueSubKey(this: i);
                pEventKey != nullptr;
                pEventKey = KeyValues::GetNextTrueSubKey(this: pEventKey) )
          {
            pLessonEvent = CScriptedIconLesson::AddSuccessEvent(this);
            v31 = KeyValues::GetName(this: pEventKey);
            CGameInstructorSymbol::CGameInstructorSymbol(this: &v171, pStr: v31);
            pLessonEvent->szEventName = v171;
            if ( gameinstructor_verbose.m_pParent != nullptr
              && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
              && CBaseLesson::ShouldShowSpew(this, a2: (const char *)ConColorMsg) )
            {
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tAdding success event ");
              v32 = CGameInstructorSymbol::String(this: &pLessonEvent->szEventName);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseSuccess, a2: "\"%s\" ", v32);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "...\n");
            }
            CScriptedIconLesson::InitElementsFromKeys(
              this,
              a2: (const char *)ConColorMsg,
              pLessonElements: &pLessonEvent->elements,
              pKey: pEventKey);
          }
          continue;
        }
        if ( KeyValues::GetNameSymbol(this: i) == s_nOnOpenSymbol )
        {
          for ( pEventKey = KeyValues::GetFirstTrueSubKey(this: i);
                pEventKey != nullptr;
                pEventKey = KeyValues::GetNextTrueSubKey(this: pEventKey) )
          {
            pLessonEvent = CScriptedIconLesson::AddOnOpenEvent(this);
            v33 = KeyValues::GetName(this: pEventKey);
            CGameInstructorSymbol::CGameInstructorSymbol(this: &v214, pStr: v33);
            pLessonEvent->szEventName = v214;
            if ( gameinstructor_verbose.m_pParent != nullptr
              && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
              && CBaseLesson::ShouldShowSpew(this, a2: (const char *)ConColorMsg) )
            {
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tAdding onopen event ");
              v34 = CGameInstructorSymbol::String(this: &pLessonEvent->szEventName);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseOpen, a2: "\"%s\" ", v34);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "...\n");
            }
            CScriptedIconLesson::InitElementsFromKeys(
              this,
              a2: (const char *)ConColorMsg,
              pLessonElements: &pLessonEvent->elements,
              pKey: pEventKey);
          }
          continue;
        }
        if ( KeyValues::GetNameSymbol(this: i) == s_nUpdateSymbol )
        {
          for ( pEventKey = KeyValues::GetFirstTrueSubKey(this: i);
                pEventKey != nullptr;
                pEventKey = KeyValues::GetNextTrueSubKey(this: pEventKey) )
          {
            pLessonEvent = CScriptedIconLesson::AddUpdateEvent(this);
            v35 = KeyValues::GetName(this: pEventKey);
            CGameInstructorSymbol::CGameInstructorSymbol(this: &v184, pStr: v35);
            pLessonEvent->szEventName = v184;
            if ( gameinstructor_verbose.m_pParent != nullptr
              && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
              && CBaseLesson::ShouldShowSpew(this, a2: (const char *)ConColorMsg) )
            {
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tAdding update event ");
              v36 = CGameInstructorSymbol::String(this: &pLessonEvent->szEventName);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseUpdate, a2: "\"%s\" ", v36);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "...\n");
            }
            CScriptedIconLesson::InitElementsFromKeys(
              this,
              a2: (const char *)ConColorMsg,
              pLessonElements: &pLessonEvent->elements,
              pKey: pEventKey);
          }
          continue;
        }
        if ( g_nVOIDSymbol != KeyValues::GetNameSymbol(this: i)
          && g_nLOCAL_PLAYERSymbol != KeyValues::GetNameSymbol(this: i) )
        {
          if ( g_nOUTPUTSymbol == KeyValues::GetNameSymbol(this: i) )
          {
            v37 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
            v38 = v37;
            if ( v37 != nullptr && StringHasPrefix(str: v37, prefix: "convar ") )
            {
              v39 = _V_strlen(str: "convar ");
              ConVarRef::ConVarRef(this: &tempCVar, pName: &v38[v39]);
              if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&tempCVar) )
                this->m_fOutput = tempCVar.m_pConVarState->m_Value.m_fValue;
              else
                this->m_fOutput = 0.0;
            }
            else
            {
              this->m_fOutput = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
            }
            continue;
          }
          if ( g_nENTITY1Symbol != KeyValues::GetNameSymbol(this: i)
            && g_nENTITY2Symbol != KeyValues::GetNameSymbol(this: i) )
          {
            if ( g_nSTRING1Symbol == KeyValues::GetNameSymbol(this: i) )
            {
              v40 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
              v41 = v40;
              if ( v40 != nullptr && StringHasPrefix(str: v40, prefix: "convar ") )
              {
                v42 = _V_strlen(str: "convar ");
                ConVarRef::ConVarRef(this: (ConVarRef *)&v167.m_Info[1], pName: &v41[v42]);
                if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v167.m_Info[1]) )
                {
                  CGameInstructorSymbol::CGameInstructorSymbol(
                    this: &v212,
                    pStr: v167.m_Info[1].m_pConVarState->m_Value.m_pszString);
                  this->m_szString1 = v212;
                }
                else
                {
                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v182, pStr: prType);
                  this->m_szString1 = v182;
                }
              }
              else
              {
                v43 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                CGameInstructorSymbol::CGameInstructorSymbol(this: &v210, pStr: v43);
                this->m_szString1 = v210;
              }
              continue;
            }
            if ( g_nSTRING2Symbol == KeyValues::GetNameSymbol(this: i) )
            {
              v44 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
              v45 = v44;
              if ( v44 != nullptr && StringHasPrefix(str: v44, prefix: "convar ") )
              {
                v46 = _V_strlen(str: "convar ");
                ConVarRef::ConVarRef(this: (ConVarRef *)&v160.m_Info[1], pName: &v45[v46]);
                if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v160.m_Info[1]) )
                {
                  CGameInstructorSymbol::CGameInstructorSymbol(
                    this: &v180,
                    pStr: v160.m_Info[1].m_pConVarState->m_Value.m_pszString);
                  this->m_szString2 = v180;
                }
                else
                {
                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v208, pStr: prType);
                  this->m_szString2 = v208;
                }
              }
              else
              {
                v47 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                CGameInstructorSymbol::CGameInstructorSymbol(this: &v178, pStr: v47);
                this->m_szString2 = v178;
              }
              continue;
            }
            if ( g_nINTEGER1Symbol == KeyValues::GetNameSymbol(this: i) )
            {
              v48 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
              v49 = v48;
              if ( v48 != nullptr && StringHasPrefix(str: v48, prefix: "convar ") )
              {
                v50 = _V_strlen(str: "convar ");
                ConVarRef::ConVarRef(this: (ConVarRef *)&v166.m_Info[1], pName: &v49[v50]);
                if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v166.m_Info[1]) )
                  this->m_iInteger1 = (int)v166.m_Info[1].m_pConVarState->m_Value.m_fValue;
                else
                  this->m_iInteger1 = 0;
              }
              else
              {
                this->m_iInteger1 = (int)KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
              }
              continue;
            }
            if ( g_nINTEGER2Symbol == KeyValues::GetNameSymbol(this: i) )
            {
              v51 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
              v52 = v51;
              if ( v51 != nullptr && StringHasPrefix(str: v51, prefix: "convar ") )
              {
                v53 = _V_strlen(str: "convar ");
                ConVarRef::ConVarRef(this: (ConVarRef *)&v154.m_Info[1], pName: &v52[v53]);
                if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v154.m_Info[1]) )
                  this->m_iInteger2 = (int)v154.m_Info[1].m_pConVarState->m_Value.m_fValue;
                else
                  this->m_iInteger2 = 0;
              }
              else
              {
                this->m_iInteger2 = (int)KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
              }
              continue;
            }
            if ( g_nFLOAT1Symbol == KeyValues::GetNameSymbol(this: i) )
            {
              v54 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
              v55 = v54;
              if ( v54 != nullptr && StringHasPrefix(str: v54, prefix: "convar ") )
              {
                v56 = _V_strlen(str: "convar ");
                ConVarRef::ConVarRef(this: (ConVarRef *)&v165.m_Info[1], pName: &v55[v56]);
                if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v165.m_Info[1]) )
                  this->m_fFloat1 = v165.m_Info[1].m_pConVarState->m_Value.m_fValue;
                else
                  this->m_fFloat1 = 0.0;
              }
              else
              {
                this->m_fFloat1 = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
              }
              continue;
            }
            if ( g_nFLOAT2Symbol == KeyValues::GetNameSymbol(this: i) )
            {
              v57 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
              v58 = v57;
              if ( v57 != nullptr && StringHasPrefix(str: v57, prefix: "convar ") )
              {
                v59 = _V_strlen(str: "convar ");
                ConVarRef::ConVarRef(this: (ConVarRef *)&v159.m_Info[1], pName: &v58[v59]);
                if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v159.m_Info[1]) )
                  this->m_fFloat2 = v159.m_Info[1].m_pConVarState->m_Value.m_fValue;
                else
                  this->m_fFloat2 = 0.0;
              }
              else
              {
                this->m_fFloat2 = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
              }
              continue;
            }
            if ( g_nICON_TARGETSymbol != KeyValues::GetNameSymbol(this: i) )
            {
              if ( g_nVGUI_TARGET_NAMESymbol == KeyValues::GetNameSymbol(this: i) )
              {
                v60 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                v61 = v60;
                if ( v60 != nullptr && StringHasPrefix(str: v60, prefix: "convar ") )
                {
                  v62 = _V_strlen(str: "convar ");
                  ConVarRef::ConVarRef(this: (ConVarRef *)&v164.m_Info[1], pName: &v61[v62]);
                  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v164.m_Info[1]) )
                  {
                    CGameInstructorSymbol::CGameInstructorSymbol(
                      this: &v206,
                      pStr: v164.m_Info[1].m_pConVarState->m_Value.m_pszString);
                    this->m_szVguiTargetName = v206;
                  }
                  else
                  {
                    CGameInstructorSymbol::CGameInstructorSymbol(this: &v176, pStr: prType);
                    this->m_szVguiTargetName = v176;
                  }
                }
                else
                {
                  v63 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v204, pStr: v63);
                  this->m_szVguiTargetName = v204;
                }
              }
              else if ( g_nVGUI_TARGET_LOOKUPSymbol == KeyValues::GetNameSymbol(this: i) )
              {
                v64 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                v65 = v64;
                if ( v64 != nullptr && StringHasPrefix(str: v64, prefix: "convar ") )
                {
                  v66 = _V_strlen(str: "convar ");
                  ConVarRef::ConVarRef(this: (ConVarRef *)&v155.m_Info[1], pName: &v65[v66]);
                  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v155.m_Info[1]) )
                  {
                    CGameInstructorSymbol::CGameInstructorSymbol(
                      this: &v174,
                      pStr: v155.m_Info[1].m_pConVarState->m_Value.m_pszString);
                    this->m_szVguiTargetLookup = v174;
                  }
                  else
                  {
                    CGameInstructorSymbol::CGameInstructorSymbol(this: &v172, pStr: prType);
                    this->m_szVguiTargetLookup = v172;
                  }
                }
                else
                {
                  v67 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v201, pStr: v67);
                  this->m_szVguiTargetLookup = v201;
                }
              }
              else if ( g_nVGUI_TARGET_EDGESymbol == KeyValues::GetNameSymbol(this: i) )
              {
                v68 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                v69 = v68;
                if ( v68 != nullptr && StringHasPrefix(str: v68, prefix: "convar ") )
                {
                  v70 = _V_strlen(str: "convar ");
                  ConVarRef::ConVarRef(this: (ConVarRef *)&v163.m_Info[1], pName: &v69[v70]);
                  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v163.m_Info[1]) )
                    this->m_nVguiTargetEdge = (int)v163.m_Info[1].m_pConVarState->m_Value.m_fValue;
                  else
                    this->m_nVguiTargetEdge = 0;
                }
                else
                {
                  this->m_nVguiTargetEdge = (int)KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
                }
              }
              else if ( g_nFIXED_POSITION_XSymbol == KeyValues::GetNameSymbol(this: i) )
              {
                v71 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                v72 = v71;
                if ( v71 != nullptr && StringHasPrefix(str: v71, prefix: "convar ") )
                {
                  v73 = _V_strlen(str: "convar ");
                  ConVarRef::ConVarRef(this: (ConVarRef *)&v158.m_Info[1], pName: &v72[v73]);
                  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v158.m_Info[1]) )
                    this->m_fFixedPositionX = v158.m_Info[1].m_pConVarState->m_Value.m_fValue;
                  else
                    this->m_fFixedPositionX = 0.0;
                }
                else
                {
                  this->m_fFixedPositionX = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
                }
              }
              else if ( g_nFIXED_POSITION_YSymbol == KeyValues::GetNameSymbol(this: i) )
              {
                v74 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                v75 = v74;
                if ( v74 != nullptr && StringHasPrefix(str: v74, prefix: "convar ") )
                {
                  v76 = _V_strlen(str: "convar ");
                  ConVarRef::ConVarRef(this: (ConVarRef *)&v162.m_Info[1], pName: &v75[v76]);
                  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v162.m_Info[1]) )
                    this->m_fFixedPositionY = v162.m_Info[1].m_pConVarState->m_Value.m_fValue;
                  else
                    this->m_fFixedPositionY = 0.0;
                }
                else
                {
                  this->m_fFixedPositionY = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
                }
              }
              else
              {
                v77 = KeyValues::GetName(this: i);
                if ( _V_stricmp(s1: "FIXED_POSITION", s2: v77) != 0 )
                {
                  v78 = KeyValues::GetName(this: i);
                  if ( _V_stricmp(s1: "NO_ICON_TARGET", s2: v78) != 0 )
                  {
                    v79 = KeyValues::GetName(this: i);
                    if ( _V_stricmp(s1: "ALLOW_NODRAW_TARGET", s2: v79) != 0 )
                    {
                      v80 = KeyValues::GetName(this: i);
                      if ( _V_stricmp(s1: "VISIBLE", s2: v80) != 0 )
                      {
                        v81 = KeyValues::GetName(this: i);
                        if ( _V_stricmp(s1: "SHOW_WHEN_OCCLUDED", s2: v81) != 0 )
                        {
                          v82 = KeyValues::GetName(this: i);
                          if ( _V_stricmp(s1: "NO_OFFSCREEN", s2: v82) != 0 )
                          {
                            v83 = KeyValues::GetName(this: i);
                            if ( _V_stricmp(s1: "FORCE_CAPTION", s2: v83) != 0 )
                            {
                              if ( g_nONSCREEN_ICONSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v84 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v85 = v84;
                                if ( v84 != nullptr && StringHasPrefix(str: v84, prefix: "convar ") )
                                {
                                  v86 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v153.m_Info[1], pName: &v85[v86]);
                                  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v153.m_Info[1]) )
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(
                                      this: &v185,
                                      pStr: v153.m_Info[1].m_pConVarState->m_Value.m_pszString);
                                    this->m_szOnscreenIcon = v185;
                                  }
                                  else
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(this: &v199, pStr: prType);
                                    this->m_szOnscreenIcon = v199;
                                  }
                                }
                                else
                                {
                                  v87 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v177, pStr: v87);
                                  this->m_szOnscreenIcon = v177;
                                }
                              }
                              else if ( g_nOFFSCREEN_ICONSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v88 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v89 = v88;
                                if ( v88 != nullptr && StringHasPrefix(str: v88, prefix: "convar ") )
                                {
                                  v90 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v161.m_Info[1], pName: &v89[v90]);
                                  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v161.m_Info[1]) )
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(
                                      this: &v197,
                                      pStr: v161.m_Info[1].m_pConVarState->m_Value.m_pszString);
                                    this->m_szOffscreenIcon = v197;
                                  }
                                  else
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(this: &v183, pStr: prType);
                                    this->m_szOffscreenIcon = v183;
                                  }
                                }
                                else
                                {
                                  v91 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v195, pStr: v91);
                                  this->m_szOffscreenIcon = v195;
                                }
                              }
                              else if ( g_nICON_OFFSETSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v92 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v93 = v92;
                                if ( v92 != nullptr && StringHasPrefix(str: v92, prefix: "convar ") )
                                {
                                  v94 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v168.m_Info[1], pName: &v93[v94]);
                                  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v168.m_Info[1]) )
                                    this->m_flUpOffset = v168.m_Info[1].m_pConVarState->m_Value.m_fValue;
                                  else
                                    this->m_flUpOffset = 0.0;
                                }
                                else
                                {
                                  this->m_flUpOffset = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
                                }
                              }
                              else if ( g_nICON_RELATIVE_OFFSETSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v95 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v96 = v95;
                                if ( v95 != nullptr && StringHasPrefix(str: v95, prefix: "convar ") )
                                {
                                  v97 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v168, pName: &v96[v97]);
                                  if ( ConVarRef::IsValid(this: &v168) )
                                    this->m_flRelativeUpOffset = v168.m_Info[0].m_pConVarState->m_Value.m_fValue;
                                  else
                                    this->m_flRelativeUpOffset = 0.0;
                                }
                                else
                                {
                                  this->m_flRelativeUpOffset = KeyValues::GetFloat(
                                                                 this: i,
                                                                 keyName: nullptr,
                                                                 defaultValue: 0.0);
                                }
                              }
                              else if ( g_nRANGESymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v98 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v99 = v98;
                                if ( v98 != nullptr && StringHasPrefix(str: v98, prefix: "convar ") )
                                {
                                  v100 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v167, pName: &v99[v100]);
                                  if ( ConVarRef::IsValid(this: &v167) )
                                    this->m_fRange = v167.m_Info[0].m_pConVarState->m_Value.m_fValue;
                                  else
                                    this->m_fRange = 0.0;
                                }
                                else
                                {
                                  this->m_fRange = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
                                }
                              }
                              else if ( g_nFLAGSSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v101 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v102 = v101;
                                if ( v101 != nullptr && StringHasPrefix(str: v101, prefix: "convar ") )
                                {
                                  v103 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v166, pName: &v102[v103]);
                                  if ( ConVarRef::IsValid(this: &v166) )
                                    this->m_iFlags = (int)v166.m_Info[0].m_pConVarState->m_Value.m_fValue;
                                  else
                                    this->m_iFlags = 0;
                                }
                                else
                                {
                                  this->m_iFlags = (int)KeyValues::GetFloat(
                                                          this: i,
                                                          keyName: nullptr,
                                                          defaultValue: 0.0);
                                }
                              }
                              else if ( g_nCAPTION_COLORSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v104 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v105 = v104;
                                if ( v104 != nullptr && StringHasPrefix(str: v104, prefix: "convar ") )
                                {
                                  v106 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v165, pName: &v105[v106]);
                                  if ( ConVarRef::IsValid(this: &v165) )
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(
                                      this: &v173,
                                      pStr: v165.m_Info[0].m_pConVarState->m_Value.m_pszString);
                                    this->m_szCaptionColor = v173;
                                  }
                                  else
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(this: &v193, pStr: prType);
                                    this->m_szCaptionColor = v193;
                                  }
                                }
                                else
                                {
                                  v107 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v181, pStr: v107);
                                  this->m_szCaptionColor = v181;
                                }
                              }
                              else if ( g_nGROUPSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v108 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v109 = v108;
                                if ( v108 != nullptr && StringHasPrefix(str: v108, prefix: "convar ") )
                                {
                                  v110 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v164, pName: &v109[v110]);
                                  if ( ConVarRef::IsValid(this: &v164) )
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(
                                      this: &v191,
                                      pStr: v164.m_Info[0].m_pConVarState->m_Value.m_pszString);
                                    this->m_szLessonGroup = v191;
                                  }
                                  else
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(this: &v175, pStr: prType);
                                    this->m_szLessonGroup = v175;
                                  }
                                }
                                else
                                {
                                  v111 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v189, pStr: v111);
                                  this->m_szLessonGroup = v189;
                                }
                              }
                              else if ( g_nCAPTIONSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v112 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v113 = v112;
                                if ( v112 != nullptr && StringHasPrefix(str: v112, prefix: "convar ") )
                                {
                                  v114 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v163, pName: &v113[v114]);
                                  if ( ConVarRef::IsValid(this: &v163) )
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(
                                      this: &v179,
                                      pStr: v163.m_Info[0].m_pConVarState->m_Value.m_pszString);
                                    this->m_szDisplayText = v179;
                                  }
                                  else
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(this: &v187, pStr: prType);
                                    this->m_szDisplayText = v187;
                                  }
                                }
                                else
                                {
                                  v115 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v203, pStr: v115);
                                  this->m_szDisplayText = v203;
                                }
                              }
                              else if ( g_nCAPTION_PARAMSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v116 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v117 = v116;
                                if ( v116 != nullptr && StringHasPrefix(str: v116, prefix: "convar ") )
                                {
                                  v118 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v162, pName: &v117[v118]);
                                  if ( ConVarRef::IsValid(this: &v162) )
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(
                                      this: &v202,
                                      pStr: v162.m_Info[0].m_pConVarState->m_Value.m_pszString);
                                    this->m_szDisplayParamText = v202;
                                  }
                                  else
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(this: &v200, pStr: prType);
                                    this->m_szDisplayParamText = v200;
                                  }
                                }
                                else
                                {
                                  v119 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v198, pStr: v119);
                                  this->m_szDisplayParamText = v198;
                                }
                              }
                              else if ( g_nBINDINGSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v120 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v121 = v120;
                                if ( v120 != nullptr && StringHasPrefix(str: v120, prefix: "convar ") )
                                {
                                  v122 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v161, pName: &v121[v122]);
                                  if ( ConVarRef::IsValid(this: &v161) )
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(
                                      this: &v196,
                                      pStr: v161.m_Info[0].m_pConVarState->m_Value.m_pszString);
                                    this->m_szBinding = v196;
                                  }
                                  else
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(this: &v194, pStr: prType);
                                    this->m_szBinding = v194;
                                  }
                                }
                                else
                                {
                                  v123 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v192, pStr: v123);
                                  this->m_szBinding = v192;
                                }
                              }
                              else if ( g_nGAMEPAD_BINDINGSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v124 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v125 = v124;
                                if ( v124 != nullptr && StringHasPrefix(str: v124, prefix: "convar ") )
                                {
                                  v126 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v160, pName: &v125[v126]);
                                  if ( ConVarRef::IsValid(this: &v160) )
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(
                                      this: &v190,
                                      pStr: v160.m_Info[0].m_pConVarState->m_Value.m_pszString);
                                    this->m_szGamepadBinding = v190;
                                  }
                                  else
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(this: &v216, pStr: prType);
                                    this->m_szGamepadBinding = v216;
                                  }
                                }
                                else
                                {
                                  v127 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v186, pStr: v127);
                                  this->m_szGamepadBinding = v186;
                                }
                              }
                              else if ( g_nPRIORITYSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v128 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v129 = v128;
                                if ( v128 != nullptr && StringHasPrefix(str: v128, prefix: "convar ") )
                                {
                                  v130 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v159, pName: &v129[v130]);
                                  if ( ConVarRef::IsValid(this: &v159) )
                                    this->m_iPriority = (int)v159.m_Info[0].m_pConVarState->m_Value.m_fValue;
                                  else
                                    this->m_iPriority = 0;
                                }
                                else
                                {
                                  this->m_iPriority = (int)KeyValues::GetFloat(
                                                             this: i,
                                                             keyName: nullptr,
                                                             defaultValue: 0.0);
                                }
                              }
                              else if ( g_nREPLACE_KEYSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v131 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v132 = v131;
                                if ( v131 != nullptr && StringHasPrefix(str: v131, prefix: "convar ") )
                                {
                                  v133 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: (ConVarRef *)&v158, pName: &v132[v133]);
                                  if ( ConVarRef::IsValid(this: &v158) )
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(
                                      this: &v215,
                                      pStr: v158.m_Info[0].m_pConVarState->m_Value.m_pszString);
                                    this->m_stringReplaceKey = v215;
                                  }
                                  else
                                  {
                                    CGameInstructorSymbol::CGameInstructorSymbol(this: &v213, pStr: prType);
                                    this->m_stringReplaceKey = v213;
                                  }
                                }
                                else
                                {
                                  v134 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                  CGameInstructorSymbol::CGameInstructorSymbol(this: &v211, pStr: v134);
                                  this->m_stringReplaceKey = v211;
                                }
                              }
                              else if ( g_nLOCK_DURATIONSymbol == KeyValues::GetNameSymbol(this: i) )
                              {
                                v135 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                v136 = v135;
                                if ( v135 != nullptr && StringHasPrefix(str: v135, prefix: "convar ") )
                                {
                                  v137 = _V_strlen(str: "convar ");
                                  ConVarRef::ConVarRef(this: &v156, pName: &v136[v137]);
                                  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v156) )
                                    this->m_fLockDuration = v156.m_pConVarState->m_Value.m_fValue;
                                  else
                                    this->m_fLockDuration = 0.0;
                                }
                                else
                                {
                                  this->m_fLockDuration = KeyValues::GetFloat(
                                                            this: i,
                                                            keyName: nullptr,
                                                            defaultValue: 0.0);
                                }
                              }
                              else
                              {
                                v138 = KeyValues::GetName(this: i);
                                if ( _V_stricmp(s1: "CAN_OPEN_WHEN_DEAD", s2: v138) != 0 )
                                {
                                  v139 = KeyValues::GetName(this: i);
                                  if ( _V_stricmp(s1: "BUMP_WITH_TIMEOUT_WHEN_LEARNED", s2: v139) != 0 )
                                  {
                                    v140 = KeyValues::GetName(this: i);
                                    if ( _V_stricmp(s1: "ONCE_LEARNED_NEVER_OPEN", s2: v140) != 0 )
                                    {
                                      v141 = KeyValues::GetName(this: i);
                                      if ( _V_stricmp(s1: "CAN_TIMEOUT_WHILE_INACTIVE", s2: v141) != 0 )
                                      {
                                        v142 = KeyValues::GetName(this: i);
                                        if ( _V_stricmp(s1: "USABLE_IN_MIDAIR", s2: v142) != 0 )
                                        {
                                          if ( g_nTIMEOUTSymbol == KeyValues::GetNameSymbol(this: i) )
                                          {
                                            v143 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                            v144 = v143;
                                            if ( v143 != nullptr && StringHasPrefix(str: v143, prefix: "convar ") )
                                            {
                                              v145 = _V_strlen(str: "convar ");
                                              ConVarRef::ConVarRef(this: (ConVarRef *)&v155, pName: &v144[v145]);
                                              if ( ConVarRef::IsValid(this: &v155) )
                                                this->m_fTimeout = v155.m_Info[0].m_pConVarState->m_Value.m_fValue;
                                              else
                                                this->m_fTimeout = 0.0;
                                            }
                                            else
                                            {
                                              this->m_fTimeout = KeyValues::GetFloat(
                                                                   this: i,
                                                                   keyName: nullptr,
                                                                   defaultValue: 0.0);
                                            }
                                          }
                                          else if ( g_nUPDATE_INTERVALSymbol == KeyValues::GetNameSymbol(this: i) )
                                          {
                                            v146 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                            v147 = v146;
                                            if ( v146 != nullptr && StringHasPrefix(str: v146, prefix: "convar ") )
                                            {
                                              v148 = _V_strlen(str: "convar ");
                                              ConVarRef::ConVarRef(this: (ConVarRef *)&v154, pName: &v147[v148]);
                                              if ( ConVarRef::IsValid(this: &v154) )
                                                this->m_fUpdateInterval = v154.m_Info[0].m_pConVarState->m_Value.m_fValue;
                                              else
                                                this->m_fUpdateInterval = 0.0;
                                            }
                                            else
                                            {
                                              this->m_fUpdateInterval = KeyValues::GetFloat(
                                                                          this: i,
                                                                          keyName: nullptr,
                                                                          defaultValue: 0.0);
                                            }
                                          }
                                          else if ( g_nSTART_SOUNDSymbol == KeyValues::GetNameSymbol(this: i) )
                                          {
                                            v149 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
                                            v150 = v149;
                                            if ( v149 != nullptr && StringHasPrefix(str: v149, prefix: "convar ") )
                                            {
                                              v151 = _V_strlen(str: "convar ");
                                              ConVarRef::ConVarRef(this: (ConVarRef *)&v153, pName: &v150[v151]);
                                              if ( ConVarRef::IsValid(this: &v153) )
                                              {
                                                CGameInstructorSymbol::CGameInstructorSymbol(
                                                  this: &v209,
                                                  pStr: v153.m_Info[0].m_pConVarState->m_Value.m_pszString);
                                                this->m_szStartSound = v209;
                                              }
                                              else
                                              {
                                                CGameInstructorSymbol::CGameInstructorSymbol(this: &v207, pStr: prType);
                                                this->m_szStartSound = v207;
                                              }
                                            }
                                            else
                                            {
                                              v152 = KeyValues::GetString(
                                                       this: i,
                                                       keyName: nullptr,
                                                       defaultValue: prType);
                                              CGameInstructorSymbol::CGameInstructorSymbol(this: &v205, pStr: v152);
                                              this->m_szStartSound = v205;
                                            }
                                          }
                                        }
                                        else
                                        {
                                          this->m_bUsableInMidair = KeyValues::GetInt(
                                                                      this: i,
                                                                      keyName: nullptr,
                                                                      defaultValue: 0) != 0;
                                        }
                                      }
                                      else
                                      {
                                        this->m_bCanTimeoutWhileInactive = KeyValues::GetInt(
                                                                             this: i,
                                                                             keyName: nullptr,
                                                                             defaultValue: 0) != 0;
                                      }
                                    }
                                    else
                                    {
                                      this->m_bOnceLearnedNeverOpen = KeyValues::GetInt(
                                                                        this: i,
                                                                        keyName: nullptr,
                                                                        defaultValue: 0) != 0;
                                    }
                                  }
                                  else
                                  {
                                    this->m_bBumpWithTimeoutWhenLearned = KeyValues::GetInt(
                                                                            this: i,
                                                                            keyName: nullptr,
                                                                            defaultValue: 0) != 0;
                                  }
                                }
                                else
                                {
                                  this->m_bCanOpenWhenDead = KeyValues::GetInt(
                                                               this: i,
                                                               keyName: nullptr,
                                                               defaultValue: 0) != 0;
                                }
                              }
                            }
                            else
                            {
                              this->m_bForceCaption = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
                            }
                          }
                          else
                          {
                            this->m_bNoOffscreen = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
                          }
                        }
                        else
                        {
                          this->m_bShowWhenOccluded = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
                        }
                      }
                      else
                      {
                        this->m_bVisible = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
                      }
                    }
                    else
                    {
                      this->m_bAllowNodrawTarget = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
                    }
                  }
                  else
                  {
                    this->m_bNoIconTarget = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
                  }
                }
                else
                {
                  this->m_bFixedPosition = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
                }
              }
              continue;
            }
          }
        }
        DevWarning(a1: "Can't initialize an EHANDLE from the instructor lesson script.");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053520
// Name: public: void LessonVariableInfo::Init_OUTPUT(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_OUTPUT(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 300;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "float";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "float");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053590
// Name: public: void LessonVariableInfo::Init_INTEGER1(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_INTEGER1(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 316;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "int";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "int");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053600
// Name: public: void LessonVariableInfo::Init_INTEGER2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_INTEGER2(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 320;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "int";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "int");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053670
// Name: public: void LessonVariableInfo::Init_FLOAT1(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_FLOAT1(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 324;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "float";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "float");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100536E0
// Name: public: void LessonVariableInfo::Init_FLOAT2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_FLOAT2(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 328;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "float";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "float");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053750
// Name: public: void LessonVariableInfo::Init_VGUI_TARGET_EDGE(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_VGUI_TARGET_EDGE(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 236;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "int";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "int");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100537C0
// Name: public: void LessonVariableInfo::Init_FIXED_POSITION_X(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_FIXED_POSITION_X(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 248;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "float";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "float");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053830
// Name: public: void LessonVariableInfo::Init_FIXED_POSITION_Y(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_FIXED_POSITION_Y(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 252;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "float";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "float");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100538A0
// Name: public: void LessonVariableInfo::Init_ICON_OFFSET(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_ICON_OFFSET(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 240;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "float";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "float");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053910
// Name: public: void LessonVariableInfo::Init_ICON_RELATIVE_OFFSET(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_ICON_RELATIVE_OFFSET(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 244;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "float";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "float");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053980
// Name: public: void LessonVariableInfo::Init_RANGE(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_RANGE(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 264;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "float";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "float");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100539F0
// Name: public: void LessonVariableInfo::Init_FLAGS(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_FLAGS(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 260;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "int";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "int");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053A60
// Name: public: void LessonVariableInfo::Init_PRIORITY(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_PRIORITY(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 68;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "int";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "int");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053AD0
// Name: public: void LessonVariableInfo::Init_LOCK_DURATION(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_LOCK_DURATION(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 116;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "float";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "float");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053B40
// Name: public: void LessonVariableInfo::Init_TIMEOUT(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_TIMEOUT(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 120;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "float";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "float");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053BB0
// Name: public: void LessonVariableInfo::Init_UPDATE_INTERVAL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LessonVariableInfo::Init_UPDATE_INTERVAL(LessonVariableInfo *this)
{
  int v2; // eax
  CUtlMap<char const *,enum _fieldtypes,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  this->iOffset = 136;
  if ( g_TypeToParamTypeMap.m_Elements.m_Tree.m_NumElements == 0 )
    CScriptedIconLesson::PreReadLessonsFromFile(this);
  search.key = "float";
  v2 = CUtlRBTree<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int,CUtlMap<char const *,enum _fieldtypes,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum _fieldtypes,int>::Node_t,int>,int>>::Find(
         this: &g_TypeToParamTypeMap.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    DevWarning(a1: "Invalid scripted lesson variable/param type: %s\n", "float");
    this->varType = FIELD_VOID;
  }
  else
  {
    this->varType = g_TypeToParamTypeMap.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053C20
// Name: class LessonVariableInfo const __near * GetLessonVariableInfo(int)
// Source: json
//------------------------------------------------------------------------------
const LessonVariableInfo *__cdecl GetLessonVariableInfo(int iLessonVariable)
{
  if ( dword_105FF4E4 == 0 )
  {
    g_pLessonVariableInfo[0].iOffset = 296;
    dword_105FF4E4 = 13;
    dword_105FF4E8 = 296;
    dword_105FF4EC = 13;
    LessonVariableInfo::Init_OUTPUT(this: &stru_105FF4F0);
    dword_105FF4F8 = 304;
    dword_105FF4FC = 13;
    dword_105FF500 = 308;
    dword_105FF504 = 13;
    dword_105FF508 = 312;
    dword_105FF50C = 2;
    dword_105FF510 = 314;
    dword_105FF514 = 2;
    LessonVariableInfo::Init_INTEGER1(this: &stru_105FF518);
    LessonVariableInfo::Init_INTEGER2(this: &stru_105FF520);
    LessonVariableInfo::Init_FLOAT1(this: &stru_105FF528);
    LessonVariableInfo::Init_FLOAT2(this: &stru_105FF530);
    dword_105FF538 = 228;
    dword_105FF53C = 13;
    dword_105FF540 = 232;
    dword_105FF544 = 2;
    dword_105FF548 = 234;
    dword_105FF54C = 2;
    LessonVariableInfo::Init_VGUI_TARGET_EDGE(this: &stru_105FF550);
    LessonVariableInfo::Init_FIXED_POSITION_X(this: &stru_105FF558);
    LessonVariableInfo::Init_FIXED_POSITION_Y(this: &stru_105FF560);
    dword_105FF568 = 286;
    dword_105FF56C = 6;
    dword_105FF570 = 287;
    dword_105FF574 = 6;
    dword_105FF578 = 288;
    dword_105FF57C = 6;
    dword_105FF580 = 289;
    dword_105FF584 = 6;
    dword_105FF588 = 290;
    dword_105FF58C = 6;
    dword_105FF590 = 291;
    dword_105FF594 = 6;
    dword_105FF598 = 292;
    dword_105FF59C = 6;
    dword_105FF5A0 = 280;
    dword_105FF5A4 = 2;
    dword_105FF5A8 = 282;
    dword_105FF5AC = 2;
    LessonVariableInfo::Init_ICON_OFFSET(this: &stru_105FF5B0);
    LessonVariableInfo::Init_ICON_RELATIVE_OFFSET(this: &stru_105FF5B8);
    LessonVariableInfo::Init_RANGE(this: &stru_105FF5C0);
    LessonVariableInfo::Init_FLAGS(this: &stru_105FF5C8);
    dword_105FF5D0 = 284;
    dword_105FF5D4 = 2;
    dword_105FF5D8 = 144;
    dword_105FF5DC = 2;
    dword_105FF5E0 = 220;
    dword_105FF5E4 = 2;
    dword_105FF5E8 = 222;
    dword_105FF5EC = 2;
    dword_105FF5F0 = 224;
    dword_105FF5F4 = 2;
    dword_105FF5F8 = 226;
    dword_105FF5FC = 2;
    LessonVariableInfo::Init_PRIORITY(this: &stru_105FF600);
    dword_105FF608 = 72;
    dword_105FF60C = 2;
    LessonVariableInfo::Init_LOCK_DURATION(this: &stru_105FF610);
    dword_105FF618 = 146;
    dword_105FF61C = 6;
    dword_105FF620 = 147;
    dword_105FF624 = 6;
    dword_105FF628 = 148;
    dword_105FF62C = 6;
    dword_105FF630 = 149;
    dword_105FF634 = 6;
    dword_105FF638 = 151;
    dword_105FF63C = 6;
    LessonVariableInfo::Init_TIMEOUT(this: &stru_105FF640);
    LessonVariableInfo::Init_UPDATE_INTERVAL(this: &stru_105FF648);
    dword_105FF654 = 2;
    dword_105FF650 = 142;
  }
  return &g_pLessonVariableInfo[iLessonVariable];
}

//------------------------------------------------------------------------------
// Address: 0x100553D0
// Name: public: void CScriptedIconLesson::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptedIconLesson::Init(CScriptedIconLesson *this)
{
  const char *v2; // eax
  char v3; // al
  CChoreoEvent *v4; // eax
  KeyValues *LoopCount; // eax
  const char *v6; // eax
  CScriptedIconLesson *v7; // edi
  const char *v8; // eax
  CScriptedIconLesson *v9; // eax
  unsigned int m_Index; // edx
  CUtlSymbol *v11; // edi
  const char *v12; // eax
  const char *v13; // eax
  LessonEvent_t *v14; // edi
  const char *v15; // eax
  char *v16; // eax
  const char *v17; // eax
  const char *v18; // ecx
  const char *v19; // eax
  CUtlSymbol *v20; // edi
  const char *v21; // eax
  char *v22; // eax
  const char *v23; // eax
  const char *v24; // ecx
  const char *v25; // eax
  C_GameInstructor *GameInstructor; // eax
  CBaseLesson *Lesson; // eax
  const char *v28; // [esp-10h] [ebp-1Ch]
  int v29; // [esp+0h] [ebp-Ch]
  int v30; // [esp+0h] [ebp-Ch]
  int iLessonEvent; // [esp+4h] [ebp-8h]
  int iLessonEventa; // [esp+4h] [ebp-8h]
  char *iLessonEventb; // [esp+4h] [ebp-8h]
  char *m_pszString; // [esp+8h] [ebp-4h] BYREF

  this->m_hLocalPlayer.m_Index = -1;
  this->m_fOutput = 0.0;
  this->m_hEntity1.m_Index = -1;
  this->m_hEntity2.m_Index = -1;
  this->m_szString1.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                               this: &g_CGameInstructorSymbolSymbolTable,
                                               result: (CUtlSymbol *)&m_pszString + 1,
                                               pString: prType)->m_Id;
  this->m_szString2.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                               this: &g_CGameInstructorSymbolSymbolTable,
                                               result: (CUtlSymbol *)&m_pszString + 1,
                                               pString: prType)->m_Id;
  this->m_iInteger1 = 0;
  this->m_iInteger2 = 0;
  this->m_fFloat1 = 0.0;
  this->m_fFloat2 = 0.0;
  this->m_fUpdateEventTime = 0.0;
  this->m_pDefaultHolder = nullptr;
  this->m_iScopeDepth = 0;
  if ( gameinstructor_verbose.m_pParent != nullptr
    && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
    && CBaseLesson::ShouldShowSpew(this, a2: (const char *)ConColorMsg) )
  {
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Initializing scripted lesson ");
    v2 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "\"%s\"", v2);
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "...\n");
  }
  v3 = *((_BYTE *)&this->CBaseLesson + 60);
  if ( (v3 & 4) == 0 )
  {
    if ( (v3 & 8) != 0 )
    {
      v28 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
      GameInstructor = GetGameInstructor();
      Lesson = (CBaseLesson *)C_GameInstructor::GetLesson(this: GameInstructor, pchLessonName: v28);
      CBaseLesson::SetRoot(this, pRoot: Lesson);
    }
    else
    {
      v4 = (CChoreoEvent *)GetGameInstructor();
      LoopCount = (KeyValues *)CChoreoEvent::GetLoopCount(this: v4);
      CScriptedIconLesson::InitFromKeys(this, pKey: LoopCount);
      if ( this->m_iPriority >= 1000 )
      {
        v6 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
        DevWarning(a1: "Priority level not set for lesson: %s\n", v6);
      }
      v7 = (CScriptedIconLesson *)MemAlloc_Alloc(nSize: 0x1D0u);
      if ( v7 != nullptr )
      {
        v8 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
        v9 = CScriptedIconLesson::CScriptedIconLesson(
               this: v7,
               pchName: v8,
               bIsDefaultHolder: true,
               bIsOpenOpportunity: false,
               nSplitScreenSlot: this->m_nSplitScreenSlot);
      }
      else
      {
        v9 = nullptr;
      }
      m_Index = this->m_hLocalPlayer.m_Index;
      this->m_pDefaultHolder = v9;
      v9->m_hLocalPlayer.m_Index = m_Index;
      v9->m_hLocalPlayer.m_Index = this->m_hLocalPlayer.m_Index;
      v9->m_fOutput = this->m_fOutput;
      v9->m_hEntity1.m_Index = this->m_hEntity1.m_Index;
      v9->m_hEntity2.m_Index = this->m_hEntity2.m_Index;
      v9->m_szString1.m_SymbolId.m_Id = this->m_szString1.m_SymbolId.m_Id;
      v9->m_szString2.m_SymbolId.m_Id = this->m_szString2.m_SymbolId.m_Id;
      v9->m_iInteger1 = this->m_iInteger1;
      v9->m_iInteger2 = this->m_iInteger2;
      v9->m_fFloat1 = this->m_fFloat1;
      v9->m_fFloat2 = this->m_fFloat2;
      v9->m_hIconTarget.m_Index = this->m_hIconTarget.m_Index;
      v9->m_szVguiTargetName.m_SymbolId.m_Id = this->m_szVguiTargetName.m_SymbolId.m_Id;
      v9->m_szVguiTargetLookup.m_SymbolId.m_Id = this->m_szVguiTargetLookup.m_SymbolId.m_Id;
      v9->m_nVguiTargetEdge = this->m_nVguiTargetEdge;
      v9->m_fFixedPositionX = this->m_fFixedPositionX;
      v9->m_fFixedPositionY = this->m_fFixedPositionY;
      v9->m_bFixedPosition = this->m_bFixedPosition;
      v9->m_bNoIconTarget = this->m_bNoIconTarget;
      v9->m_bAllowNodrawTarget = this->m_bAllowNodrawTarget;
      v9->m_bVisible = this->m_bVisible;
      v9->m_bShowWhenOccluded = this->m_bShowWhenOccluded;
      v9->m_bNoOffscreen = this->m_bNoOffscreen;
      v9->m_bForceCaption = this->m_bForceCaption;
      v9->m_szOnscreenIcon.m_SymbolId.m_Id = this->m_szOnscreenIcon.m_SymbolId.m_Id;
      v9->m_szOffscreenIcon.m_SymbolId.m_Id = this->m_szOffscreenIcon.m_SymbolId.m_Id;
      v9->m_flUpOffset = this->m_flUpOffset;
      v9->m_flRelativeUpOffset = this->m_flRelativeUpOffset;
      v9->m_fRange = this->m_fRange;
      v9->m_iFlags = this->m_iFlags;
      v9->m_szCaptionColor.m_SymbolId.m_Id = this->m_szCaptionColor.m_SymbolId.m_Id;
      v9->m_szLessonGroup.m_SymbolId.m_Id = this->m_szLessonGroup.m_SymbolId.m_Id;
      v9->m_szDisplayText.m_SymbolId.m_Id = this->m_szDisplayText.m_SymbolId.m_Id;
      v9->m_szDisplayParamText.m_SymbolId.m_Id = this->m_szDisplayParamText.m_SymbolId.m_Id;
      v9->m_szBinding.m_SymbolId.m_Id = this->m_szBinding.m_SymbolId.m_Id;
      v9->m_szGamepadBinding.m_SymbolId.m_Id = this->m_szGamepadBinding.m_SymbolId.m_Id;
      v9->m_iPriority = this->m_iPriority;
      v9->m_stringReplaceKey.m_SymbolId.m_Id = this->m_stringReplaceKey.m_SymbolId.m_Id;
      v9->m_fLockDuration = this->m_fLockDuration;
      v9->m_bCanOpenWhenDead = this->m_bCanOpenWhenDead;
      v9->m_bBumpWithTimeoutWhenLearned = this->m_bBumpWithTimeoutWhenLearned;
      v9->m_bOnceLearnedNeverOpen = this->m_bOnceLearnedNeverOpen;
      v9->m_bCanTimeoutWhileInactive = this->m_bCanTimeoutWhileInactive;
      v9->m_bUsableInMidair = this->m_bUsableInMidair;
      iLessonEvent = 0;
      v9->m_fTimeout = this->m_fTimeout;
      v9->m_fUpdateInterval = this->m_fUpdateInterval;
      v9->m_szStartSound.m_SymbolId.m_Id = this->m_szStartSound.m_SymbolId.m_Id;
      if ( this->m_OpenEvents.m_Size > 0 )
      {
        m_pszString = nullptr;
        do
        {
          v11 = (CUtlSymbol *)&m_pszString[(unsigned int)this->m_OpenEvents.m_Memory.m_pMemory];
          v12 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v11[10]);
          this->m_bRegisteredForEvents = true;
          gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: v12, a4: false);
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this, a2: (const char *)ConColorMsg) )
          {
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tListen for open event ");
            v13 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v11[10]);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseOpen, a2: "\"%s\"", v13);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ".\n");
          }
          m_pszString += 24;
          ++iLessonEvent;
        }
        while ( iLessonEvent < this->m_OpenEvents.m_Size );
      }
      v29 = 0;
      if ( this->m_CloseEvents.m_Size > 0 )
      {
        iLessonEventa = 0;
        do
        {
          v14 = &this->m_CloseEvents.m_Memory.m_pMemory[iLessonEventa];
          v15 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v14->szEventName.m_SymbolId);
          this->m_bRegisteredForEvents = true;
          gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: v15, a4: false);
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && ((gameinstructor_verbose_lesson.m_nFlags & 0x1000) != 0
             || (v16 = gameinstructor_verbose_lesson.m_pParent->m_Value.m_pszString) != nullptr && *v16 != 0) )
          {
            if ( (gameinstructor_verbose_lesson.m_nFlags & 0x1000) != 0 )
            {
              m_pszString = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              m_pszString = gameinstructor_verbose_lesson.m_pParent->m_Value.m_pszString;
              if ( m_pszString == nullptr )
                m_pszString = (char *)prType;
            }
            v17 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
            if ( V_stristr(a1: v18, a2: (const char *)ConColorMsg, pStr: v17, pSearch: m_pszString) != nullptr )
            {
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tListen for close event ");
              v19 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v14->szEventName.m_SymbolId);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\"", v19);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ".\n");
            }
          }
          ++iLessonEventa;
          ++v29;
        }
        while ( v29 < this->m_CloseEvents.m_Size );
      }
      v30 = 0;
      if ( this->m_SuccessEvents.m_Size > 0 )
      {
        m_pszString = nullptr;
        do
        {
          v20 = (CUtlSymbol *)&m_pszString[(unsigned int)this->m_SuccessEvents.m_Memory.m_pMemory];
          v21 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v20[10]);
          this->m_bRegisteredForEvents = true;
          gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: v21, a4: false);
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && ((gameinstructor_verbose_lesson.m_nFlags & 0x1000) != 0
             || (v22 = gameinstructor_verbose_lesson.m_pParent->m_Value.m_pszString) != nullptr && *v22 != 0) )
          {
            if ( (gameinstructor_verbose_lesson.m_nFlags & 0x1000) != 0 )
            {
              iLessonEventb = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              iLessonEventb = gameinstructor_verbose_lesson.m_pParent->m_Value.m_pszString;
              if ( iLessonEventb == nullptr )
                iLessonEventb = (char *)prType;
            }
            v23 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
            if ( V_stristr(a1: v24, a2: (const char *)ConColorMsg, pStr: v23, pSearch: iLessonEventb) != nullptr )
            {
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tListen for success event ");
              v25 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v20[10]);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseSuccess, a2: "\"%s\"", v25);
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: ".\n");
            }
          }
          m_pszString += 24;
          ++v30;
        }
        while ( v30 < this->m_SuccessEvents.m_Size );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055AF0
// Name: private: bool CScriptedIconLesson::ProcessElement(class IGameEvent __near *,struct LessonElement_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CScriptedIconLesson::ProcessElement@<al>(
        CScriptedIconLesson *this@<ecx>,
        const char *a2@<ebx>,
        IGameEvent *event,
        const LessonElement_t *pLessonElement,
        char *bInFailedScope)
{
  int iAction; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  CGameInstructorSymbol *p_szParam; // ebx
  float v14; // xmm0_4
  __int32 v15; // eax
  const LessonVariableInfo *LessonVariableInfo; // eax
  const char *v17; // eax
  double v18; // st7
  char v19; // al
  const LessonVariableInfo *v20; // eax
  const char *v21; // eax
  char v22; // al
  const LessonVariableInfo *v23; // eax
  char *v24; // eax
  const char *v25; // eax
  const LessonVariableInfo *v26; // eax
  const LessonVariableInfo *v27; // eax
  int v28; // eax
  const LessonVariableInfo *v29; // eax
  int v30; // eax
  const char *v31; // eax
  char v32; // al
  const char *v33; // [esp+28h] [ebp-11Ch]
  char eventParam_string[256]; // [esp+38h] [ebp-10Ch] BYREF
  ConVarRef tempCVar; // [esp+138h] [ebp-Ch] BYREF
  C_BaseEntity *eventParam_BaseEntity; // [esp+140h] [ebp-4h]
  int savedregs; // [esp+144h] [ebp+0h] BYREF
  float eventParam_float; // [esp+150h] [ebp+Ch]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CScriptedIconLesson::ProcessElement",
    a3: 0,
    a4: "GameInstructor",
    a5: false,
    a6: 4);
  iAction = pLessonElement->iAction;
  if ( iAction == 1 )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr
      && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
      && CBaseLesson::ShouldShowSpew(this, a2) )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tScopeIn()\n");
    }
    ++this->m_iScopeDepth;
    goto LABEL_7;
  }
  if ( iAction == 2 )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr
      && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
      && CBaseLesson::ShouldShowSpew(this, a2) )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tScopeOut()\n");
    }
    --this->m_iScopeDepth;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  if ( (_BYTE)bInFailedScope != 0 )
  {
LABEL_7:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  if ( iAction == 3 )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr
      && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
      && CBaseLesson::ShouldShowSpew(this, a2) )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tCloseOpportunity()\n");
    }
    this->m_stringCloseReason.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                         this: &g_CGameInstructorSymbolSymbolTable,
                                                         result: (CUtlSymbol *)&bInFailedScope + 1,
                                                         pString: "Close action.")->m_Id;
    *((_BYTE *)&this->CBaseLesson + 60) &= ~8u;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  if ( iAction == 4 )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr
      && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
      && CBaseLesson::ShouldShowSpew(this, a2) )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tMarkSucceeded()\n");
    }
    CBaseLesson::MarkSucceeded(this);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  if ( iAction != 5 )
  {
    switch ( iAction )
    {
      case 6:
        LOBYTE(a2) = CIconLesson::IsPresentComplete(this);
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this, a2) )
        {
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tIsPresentComplete() ");
          v9 = "true";
          if ( (_BYTE)a2 == 0 )
            v9 = "false";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%s ", v9);
          v10 = "!= true\n";
          if ( (*((_BYTE *)pLessonElement + 18) & 1) == 0 )
            v10 = "== true\n";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v10);
        }
        if ( (*((_BYTE *)pLessonElement + 18) & 1) != 0 )
        {
LABEL_43:
          CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
          return (_BYTE)a2 == 0;
        }
LABEL_239:
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return (char)a2;
      case 7:
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this, a2) )
        {
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tPresentStart()\n");
        }
        CIconLesson::PresentStart(this);
        goto LABEL_50;
      case 8:
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this, a2) )
        {
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tPresentEnd()\n");
        }
        CIconLesson::PresentEnd(this);
        goto LABEL_50;
      case 10:
        LOBYTE(a2) = g_pGameRules != nullptr && g_pGameRules->IsMultiplayer(this: g_pGameRules);
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this, a2) )
        {
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tGameRules()->IsMultiplayer() ");
          v11 = "true";
          if ( (_BYTE)a2 == 0 )
            v11 = "false";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseName, a2: "%s ", v11);
          v12 = "!= true\n";
          if ( (*((_BYTE *)pLessonElement + 18) & 1) == 0 )
            v12 = "== true\n";
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: v12);
        }
        if ( (*((_BYTE *)pLessonElement + 18) & 1) != 0 )
          goto LABEL_43;
        goto LABEL_239;
      default:
        break;
    }
    p_szParam = &pLessonElement->szParam;
    v14 = 0.0;
    bInFailedScope = (char *)CGameInstructorSymbol::String(this: &pLessonElement->szParam);
    v15 = pLessonElement->paramType - 1;
    eventParam_float = 0.0;
    eventParam_string[0] = 0;
    eventParam_BaseEntity = nullptr;
    switch ( v15 )
    {
      case 0:
        if ( pLessonElement->iParamVarIndex < 47 )
        {
          LessonVariableInfo = GetLessonVariableInfo(iLessonVariable: pLessonElement->iParamVarIndex);
          switch ( LessonVariableInfo->varType )
          {
            case FIELD_FLOAT:
              v14 = *(float *)((char *)&this->__vftable + LessonVariableInfo->iOffset);
              break;
            case FIELD_STRING:
              v17 = CGameInstructorSymbol::String(this: (CGameInstructorSymbol *)((char *)this
                                                                                + LessonVariableInfo->iOffset));
              v14 = (float)atoi(nptr: v17);
              break;
            case FIELD_INTEGER:
              v14 = (float)*(int *)((char *)&this->__vftable + LessonVariableInfo->iOffset);
              break;
            case FIELD_BOOLEAN:
              v14 = (float)*((unsigned __int8 *)&this->__vftable + LessonVariableInfo->iOffset);
              break;
            case FIELD_EHANDLE:
            case FIELD_FUNCTION:
              goto $LN151;
            default:
              goto LABEL_84;
          }
LABEL_85:
          switch ( pLessonElement->iVariable )
          {
            case 0:
            case 1:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (int)&savedregs,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_hLocalPlayer",
                      hVar: &this->m_hLocalPlayer,
                      pchParamName: &pLessonElement->szParam,
                      fParam: __SPAIR64__((unsigned int)eventParam_BaseEntity, LODWORD(v14)),
                      pchParam: eventParam_string);
              break;
            case 2:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_fOutput",
                      fVar: &this->m_fOutput,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 3:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (int)&savedregs,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_hEntity1",
                      hVar: &this->m_hEntity1,
                      pchParamName: &pLessonElement->szParam,
                      fParam: __SPAIR64__((unsigned int)eventParam_BaseEntity, LODWORD(v14)),
                      pchParam: eventParam_string);
              break;
            case 4:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (int)&savedregs,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_hEntity2",
                      hVar: &this->m_hEntity2,
                      pchParamName: &pLessonElement->szParam,
                      fParam: __SPAIR64__((unsigned int)eventParam_BaseEntity, LODWORD(v14)),
                      pchParam: eventParam_string);
              break;
            case 5:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szString1",
                      pchVar: &this->m_szString1,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 6:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szString2",
                      pchVar: &this->m_szString2,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 7:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_iInteger1",
                      iVar: COERCE_FLOAT((CScriptedIconLesson *)&this->m_iInteger1),
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 8:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_iInteger2",
                      iVar: COERCE_FLOAT((CScriptedIconLesson *)&this->m_iInteger2),
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 9:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_fFloat1",
                      fVar: &this->m_fFloat1,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0xA:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_fFloat2",
                      fVar: &this->m_fFloat2,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0xB:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (int)&savedregs,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_hIconTarget",
                      hVar: &this->m_hIconTarget,
                      pchParamName: &pLessonElement->szParam,
                      fParam: __SPAIR64__((unsigned int)eventParam_BaseEntity, LODWORD(v14)),
                      pchParam: eventParam_string);
              break;
            case 0xC:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szVguiTargetName",
                      pchVar: &this->m_szVguiTargetName,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 0xD:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szVguiTargetLookup",
                      pchVar: &this->m_szVguiTargetLookup,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 0xE:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_nVguiTargetEdge",
                      iVar: COERCE_FLOAT((CScriptedIconLesson *)&this->m_nVguiTargetEdge),
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0xF:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_fFixedPositionX",
                      fVar: &this->m_fFixedPositionX,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x10:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_fFixedPositionY",
                      fVar: &this->m_fFixedPositionY,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x11:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_bFixedPosition",
                      bVar: &this->m_bFixedPosition,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x12:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_bNoIconTarget",
                      bVar: &this->m_bNoIconTarget,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x13:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_bAllowNodrawTarget",
                      bVar: &this->m_bAllowNodrawTarget,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x14:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_bVisible",
                      bVar: &this->m_bVisible,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x15:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_bShowWhenOccluded",
                      bVar: &this->m_bShowWhenOccluded,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x16:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_bNoOffscreen",
                      bVar: &this->m_bNoOffscreen,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x17:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_bForceCaption",
                      bVar: &this->m_bForceCaption,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x18:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szOnscreenIcon",
                      pchVar: &this->m_szOnscreenIcon,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 0x19:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szOffscreenIcon",
                      pchVar: &this->m_szOffscreenIcon,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 0x1A:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_flUpOffset",
                      fVar: &this->m_flUpOffset,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x1B:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_flRelativeUpOffset",
                      fVar: &this->m_flRelativeUpOffset,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x1C:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_fRange",
                      fVar: &this->m_fRange,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x1D:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_iFlags",
                      iVar: COERCE_FLOAT((CScriptedIconLesson *)&this->m_iFlags),
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x1E:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szCaptionColor",
                      pchVar: &this->m_szCaptionColor,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 0x1F:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szLessonGroup",
                      pchVar: &this->m_szLessonGroup,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 0x20:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szDisplayText",
                      pchVar: &this->m_szDisplayText,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 0x21:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szDisplayParamText",
                      pchVar: &this->m_szDisplayParamText,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 0x22:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szBinding",
                      pchVar: &this->m_szBinding,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 0x23:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szGamepadBinding",
                      pchVar: &this->m_szGamepadBinding,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 0x24:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_iPriority",
                      iVar: COERCE_FLOAT((CScriptedIconLesson *)&this->m_iPriority),
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x25:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_stringReplaceKey",
                      pchVar: &this->m_stringReplaceKey,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            case 0x26:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_fLockDuration",
                      fVar: &this->m_fLockDuration,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x27:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_bCanOpenWhenDead",
                      bVar: &this->m_bCanOpenWhenDead,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x28:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_bBumpWithTimeoutWhenLearned",
                      bVar: &this->m_bBumpWithTimeoutWhenLearned,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x29:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_bOnceLearnedNeverOpen",
                      bVar: &this->m_bOnceLearnedNeverOpen,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x2A:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_bCanTimeoutWhileInactive",
                      bVar: &this->m_bCanTimeoutWhileInactive,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x2B:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_bUsableInMidair",
                      bVar: &this->m_bUsableInMidair,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x2C:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_fTimeout",
                      fVar: &this->m_fTimeout,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x2D:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      a2: (const char *)p_szParam,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_fUpdateInterval",
                      fVar: &this->m_fUpdateInterval,
                      pchParamName: &pLessonElement->szParam,
                      fParam: v14);
              break;
            case 0x2E:
              v32 = CScriptedIconLesson::ProcessElementAction(
                      this,
                      iAction: pLessonElement->iAction,
                      bNot: *((_BYTE *)pLessonElement + 18) & 1,
                      pchVarName: "m_szStartSound",
                      pchVar: &this->m_szStartSound,
                      pchParamName: &pLessonElement->szParam,
                      pchParam: (int)eventParam_string);
              break;
            default:
              goto LABEL_50;
          }
          LOBYTE(a2) = v32;
          goto LABEL_239;
        }
        if ( event != nullptr && !event->IsEmpty(this: event, a2: bInFailedScope) )
        {
          v18 = ((double (__stdcall *)(char *, _DWORD))event->GetFloat)(a1: bInFailedScope, a2: 0);
LABEL_83:
          eventParam_float = v18;
          goto LABEL_84;
        }
        if ( (*((_BYTE *)pLessonElement + 18) & 2) != 0 )
          goto LABEL_50;
        v19 = *bInFailedScope;
        if ( *bInFailedScope >= 48 && v19 <= 57 || v19 == 45 || v19 == 46 )
        {
          v18 = V_atof(str: bInFailedScope);
          goto LABEL_83;
        }
        DevWarning(a1: "Invalid event field name and not a float \"%s\".\n", bInFailedScope);
        goto LABEL_187;
      case 1:
        if ( pLessonElement->iParamVarIndex < 47 )
        {
          v23 = GetLessonVariableInfo(iLessonVariable: pLessonElement->iParamVarIndex);
          switch ( v23->varType )
          {
            case FIELD_FLOAT:
              V_snprintf(
                pDest: eventParam_string,
                maxLen: 0x100u,
                pFormat: "%f",
                *(float *)((char *)&this->__vftable + v23->iOffset));
              break;
            case FIELD_STRING:
              v24 = (char *)CGameInstructorSymbol::String(this: (CGameInstructorSymbol *)((char *)this + v23->iOffset));
              V_strncpy(pDest: eventParam_string, pSrc: v24, maxLen: 256);
              break;
            case FIELD_INTEGER:
              V_snprintf(
                pDest: eventParam_string,
                maxLen: 0x100u,
                pFormat: "%i",
                *(CScriptedIconLesson_vtbl **)((char *)&this->__vftable + v23->iOffset));
              break;
            case FIELD_BOOLEAN:
            case FIELD_EHANDLE:
            case FIELD_FUNCTION:
              goto $LN151;
            default:
              goto LABEL_84;
          }
          goto LABEL_84;
        }
        if ( event != nullptr && !event->IsEmpty(this: event, a2: bInFailedScope) )
        {
          v25 = event->GetString(this: event, a2: bInFailedScope, a3: prType);
          if ( v25 != nullptr && *v25 != 0 )
          {
            _V_strcpy(dest: eventParam_string, src: v25);
            goto LABEL_84;
          }
        }
        if ( (*((_BYTE *)pLessonElement + 18) & 2) == 0 )
        {
          V_strncpy(pDest: eventParam_string, pSrc: bInFailedScope, maxLen: 256);
          goto LABEL_84;
        }
        goto LABEL_50;
      case 4:
        if ( pLessonElement->iParamVarIndex < 47 )
        {
          v20 = GetLessonVariableInfo(iLessonVariable: pLessonElement->iParamVarIndex);
          switch ( v20->varType )
          {
            case FIELD_FLOAT:
              v14 = (float)(int)*(float *)((char *)&this->__vftable + v20->iOffset);
              break;
            case FIELD_STRING:
              v21 = CGameInstructorSymbol::String(this: (CGameInstructorSymbol *)((char *)this + v20->iOffset));
              eventParam_float = atof(nptr: v21);
              goto LABEL_84;
            case FIELD_INTEGER:
              v14 = (float)*(int *)((char *)&this->__vftable + v20->iOffset);
              break;
            case FIELD_BOOLEAN:
              v14 = (float)*((unsigned __int8 *)&this->__vftable + v20->iOffset);
              break;
            case FIELD_EHANDLE:
            case FIELD_FUNCTION:
              goto $LN151;
            default:
              goto LABEL_84;
          }
          goto LABEL_85;
        }
        if ( event != nullptr && !event->IsEmpty(this: event, a2: bInFailedScope) )
        {
          v14 = (float)event->GetInt(this: event, a2: bInFailedScope, a3: 0);
          goto LABEL_85;
        }
        if ( (*((_BYTE *)pLessonElement + 18) & 2) != 0 )
          goto LABEL_50;
        v22 = *bInFailedScope;
        if ( *bInFailedScope >= 48 && v22 <= 57 || v22 == 45 )
        {
          v14 = (float)(int)V_atoi(str: bInFailedScope);
          goto LABEL_85;
        }
        DevWarning(a1: "Invalid event field name and not an integer \"%s\".\n", bInFailedScope);
        goto LABEL_187;
      case 5:
        if ( pLessonElement->iParamVarIndex >= 47 )
        {
          if ( event == nullptr || event->IsEmpty(this: event, a2: bInFailedScope) )
          {
            if ( (*((_BYTE *)pLessonElement + 18) & 2) != 0 )
              goto LABEL_50;
            if ( *bInFailedScope != 48 && *bInFailedScope != 49 )
            {
              DevWarning(a1: "Invalid event field name and not an boolean \"%s\".\n", bInFailedScope);
              goto LABEL_187;
            }
            v14 = V_atof(str: bInFailedScope) != 0.0;
          }
          else if ( event->GetBool(this: event, a2: bInFailedScope, a3: false) )
          {
            v14 = 1.0;
          }
          else
          {
LABEL_132:
            v14 = 0.0;
          }
        }
        else
        {
          v26 = GetLessonVariableInfo(iLessonVariable: pLessonElement->iParamVarIndex);
          switch ( v26->varType )
          {
            case FIELD_FLOAT:
              v14 = 0.0;
              if ( *(float *)((char *)&this->__vftable + v26->iOffset) != 0.0 )
                v14 = 1.0;
              break;
            case FIELD_STRING:
            case FIELD_EHANDLE:
            case FIELD_FUNCTION:
              goto $LN151;
            case FIELD_INTEGER:
              if ( *(CScriptedIconLesson_vtbl **)((char *)&this->__vftable + v26->iOffset) == nullptr )
                goto LABEL_132;
              v14 = 1.0;
              break;
            case FIELD_BOOLEAN:
              if ( *((_BYTE *)&this->__vftable + v26->iOffset) == 0 )
                goto LABEL_132;
              v14 = 1.0;
              break;
            default:
              goto LABEL_84;
          }
        }
        goto LABEL_85;
      case 9:
        ConVarRef::ConVarRef(this: &tempCVar, pName: bInFailedScope);
        if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&tempCVar) )
        {
          eventParam_float = tempCVar.m_pConVarState->m_Value.m_fValue;
          V_strncpy(pDest: eventParam_string, pSrc: tempCVar.m_pConVarState->m_Value.m_pszString, maxLen: 256);
          goto LABEL_84;
        }
        DevWarning(a1: "Invalid convar name \"%s\".\n", bInFailedScope);
        goto LABEL_187;
      case 10:
        if ( pLessonElement->iParamVarIndex < 47 )
        {
          v27 = GetLessonVariableInfo(iLessonVariable: pLessonElement->iParamVarIndex);
          switch ( v27->varType )
          {
            case FIELD_FLOAT:
            case FIELD_STRING:
            case FIELD_INTEGER:
            case FIELD_BOOLEAN:
            case FIELD_FUNCTION:
              goto $LN151;
            case FIELD_EHANDLE:
              eventParam_BaseEntity = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)((char *)this + v27->iOffset));
              if ( eventParam_BaseEntity != nullptr )
                goto LABEL_84;
              if ( (*((_BYTE *)pLessonElement + 18) & 2) != 0 )
                goto LABEL_50;
              if ( gameinstructor_verbose.m_pParent != nullptr
                && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
                && CBaseLesson::ShouldShowSpew(this, a2: (const char *)p_szParam) )
              {
                goto LABEL_147;
              }
              goto LABEL_187;
            default:
              goto LABEL_84;
          }
        }
        if ( event == nullptr || event->IsEmpty(this: event, a2: bInFailedScope) )
        {
          if ( (*((_BYTE *)pLessonElement + 18) & 2) != 0 )
            goto LABEL_50;
          if ( _V_stricmp(s1: bInFailedScope, s2: "null") == 0 )
          {
            eventParam_BaseEntity = nullptr;
            goto LABEL_84;
          }
          goto LABEL_159;
        }
        v28 = event->GetInt(this: event, a2: bInFailedScope, a3: 0);
        eventParam_BaseEntity = UTIL_PlayerByUserId(userID: v28);
        if ( eventParam_BaseEntity != nullptr )
          goto LABEL_84;
        if ( (*((_BYTE *)pLessonElement + 18) & 2) == 0 )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this, a2: (const char *)p_szParam) )
          {
LABEL_147:
            ConColorMsg(
              a1: &CBaseLesson::m_rgbaVerbosePlain,
              a2: "\tPlayer param \"%s\" returned NULL.\n",
              bInFailedScope);
            CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            return 0;
          }
          goto LABEL_187;
        }
        goto LABEL_50;
      case 12:
        if ( pLessonElement->iParamVarIndex < 47 )
        {
          v29 = GetLessonVariableInfo(iLessonVariable: pLessonElement->iParamVarIndex);
          switch ( v29->varType )
          {
            case FIELD_FLOAT:
            case FIELD_STRING:
            case FIELD_INTEGER:
            case FIELD_BOOLEAN:
            case FIELD_FUNCTION:
$LN151:
              DevWarning(a1: "Can't use this variable type with this parameter type in lesson script.\n");
              goto LABEL_84;
            case FIELD_EHANDLE:
              eventParam_BaseEntity = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)((char *)this + v29->iOffset));
              if ( eventParam_BaseEntity != nullptr )
                goto LABEL_84;
              if ( (*((_BYTE *)pLessonElement + 18) & 2) != 0 )
                goto LABEL_50;
              if ( gameinstructor_verbose.m_pParent != nullptr
                && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
                && CBaseLesson::ShouldShowSpew(this, a2: (const char *)p_szParam) )
              {
                goto LABEL_177;
              }
              goto LABEL_187;
            default:
              goto LABEL_84;
          }
        }
        if ( event == nullptr || event->IsEmpty(this: event, a2: bInFailedScope) )
        {
          if ( (*((_BYTE *)pLessonElement + 18) & 2) != 0 )
            goto LABEL_50;
          if ( _V_stricmp(s1: bInFailedScope, s2: "null") != 0 )
          {
            if ( _V_stricmp(s1: bInFailedScope, s2: "world") != 0 )
            {
LABEL_159:
              DevWarning(a1: "Invalid event field name \"%s\".\n", bInFailedScope);
LABEL_187:
              CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
              return 0;
            }
            eventParam_BaseEntity = GetClientWorldEntity();
          }
          else
          {
            eventParam_BaseEntity = nullptr;
          }
        }
        else
        {
          v30 = event->GetInt(this: event, a2: bInFailedScope, a3: 0);
          if ( v30 >= 0x2000 )
          {
            v31 = (const char *)((int (__thiscall *)(IGameEvent *, char *))event->GetName)(
                                  a1: event,
                                  a2: bInFailedScope);
            DevWarning(a1: "Invalid entity ID used in game event (%s) for param (%s).", v31, v33);
            CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            return 0;
          }
          eventParam_BaseEntity = C_BaseEntity::Instance(iEnt: v30);
          if ( eventParam_BaseEntity == nullptr )
          {
            if ( (*((_BYTE *)pLessonElement + 18) & 2) == 0 )
            {
              if ( gameinstructor_verbose.m_pParent != nullptr
                && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
                && CBaseLesson::ShouldShowSpew(this, a2: (const char *)p_szParam) )
              {
LABEL_177:
                ConColorMsg(
                  a1: &CBaseLesson::m_rgbaVerbosePlain,
                  a2: "\tEntity param \"%s\" returned NULL.\n",
                  bInFailedScope);
                CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
                return 0;
              }
              goto LABEL_187;
            }
LABEL_50:
            CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            return 1;
          }
        }
LABEL_84:
        v14 = eventParam_float;
        goto LABEL_85;
      default:
        goto LABEL_85;
    }
  }
  if ( gameinstructor_verbose.m_pParent != nullptr
    && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
    && CBaseLesson::ShouldShowSpew(this, a2) )
  {
    ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "\tm_fLockTime = gpGlobals->curtime\n");
  }
  this->m_fLockTime = *(float *)(gpGlobals.m_Index + 12);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10056F80
// Name: public: CScriptedIconLesson::CScriptedIconLesson(char const __near *,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
CScriptedIconLesson *__thiscall CScriptedIconLesson::CScriptedIconLesson(
        CScriptedIconLesson *this,
        const char *pchName,
        bool bIsDefaultHolder,
        bool bIsOpenOpportunity,
        int nSplitScreenSlot)
{
  CIconLesson::CIconLesson(this, pchName, bIsDefaultHolder, bIsOpenOpportunity, nSplitScreenSlot);
  this->__vftable = (CScriptedIconLesson_vtbl *)&CScriptedIconLesson::`vftable';
  this->m_hLocalPlayer.m_Index = -1;
  this->m_hEntity1.m_Index = -1;
  this->m_hEntity2.m_Index = -1;
  *(_DWORD *)&this->m_szString1.m_SymbolId.m_Id = -1;
  this->m_PrerequisiteNames.m_Memory.m_pMemory = nullptr;
  this->m_PrerequisiteNames.m_Memory.m_nAllocationCount = 0;
  this->m_PrerequisiteNames.m_Memory.m_nGrowSize = 0;
  this->m_PrerequisiteNames.m_Size = 0;
  this->m_PrerequisiteNames.m_pElements = nullptr;
  this->m_OpenEvents.m_Memory.m_pMemory = nullptr;
  this->m_OpenEvents.m_Memory.m_nAllocationCount = 0;
  this->m_OpenEvents.m_Memory.m_nGrowSize = 0;
  this->m_OpenEvents.m_Size = 0;
  this->m_OpenEvents.m_pElements = nullptr;
  this->m_CloseEvents.m_Memory.m_pMemory = nullptr;
  this->m_CloseEvents.m_Memory.m_nAllocationCount = 0;
  this->m_CloseEvents.m_Memory.m_nGrowSize = 0;
  this->m_CloseEvents.m_Size = 0;
  this->m_CloseEvents.m_pElements = nullptr;
  this->m_SuccessEvents.m_Memory.m_pMemory = nullptr;
  this->m_SuccessEvents.m_Memory.m_nAllocationCount = 0;
  this->m_SuccessEvents.m_Memory.m_nGrowSize = 0;
  this->m_SuccessEvents.m_Size = 0;
  this->m_SuccessEvents.m_pElements = nullptr;
  this->m_OnOpenEvents.m_Memory.m_pMemory = nullptr;
  this->m_OnOpenEvents.m_Memory.m_nAllocationCount = 0;
  this->m_OnOpenEvents.m_Memory.m_nGrowSize = 0;
  this->m_OnOpenEvents.m_Size = 0;
  this->m_OnOpenEvents.m_pElements = nullptr;
  this->m_UpdateEvents.m_Memory.m_pMemory = nullptr;
  this->m_UpdateEvents.m_Memory.m_nAllocationCount = 0;
  this->m_UpdateEvents.m_Memory.m_nGrowSize = 0;
  this->m_UpdateEvents.m_Size = 0;
  this->m_UpdateEvents.m_pElements = nullptr;
  CScriptedIconLesson::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10057090
// Name: public: bool CScriptedIconLesson::ProcessElements(class IGameEvent __near *,class CUtlVector<struct LessonElement_t,class CUtlMemory<struct LessonElement_t,int>> const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptedIconLesson::ProcessElements(
        CScriptedIconLesson *this,
        IGameEvent *event,
        const CUtlVector<LessonElement_t,CUtlMemory<LessonElement_t,int> > *pElements)
{
  int v3; // ebx
  C_GameInstructor *GameInstructor; // eax
  C_BasePlayer *LocalPlayer; // eax
  int v7; // esi
  int v8; // esi
  int v9; // edi
  int iElementa; // [esp+Ch] [ebp-8h]
  bool bSuccess; // [esp+13h] [ebp-1h]

  v3 = 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CScriptedIconLesson::ProcessElements",
    a3: 0,
    a4: "GameInstructor",
    a5: false,
    a6: 4);
  GameInstructor = GetGameInstructor();
  LocalPlayer = C_GameInstructor::GetLocalPlayer(this: GameInstructor);
  if ( LocalPlayer != nullptr )
    this->m_hLocalPlayer.m_Index = LocalPlayer->GetRefEHandle(this: LocalPlayer)->m_Index;
  else
    this->m_hLocalPlayer.m_Index = -1;
  this->m_iScopeDepth = 0;
  v7 = -1;
  bSuccess = true;
  if ( gameinstructor_find_errors.m_pParent != nullptr && gameinstructor_find_errors.m_pParent->m_Value.m_nValue != 0 )
  {
    v8 = 0;
    if ( pElements->m_Size > 0 )
    {
      v9 = 0;
      do
      {
        CScriptedIconLesson::ProcessElement(
          this,
          a2: (const char *)pElements,
          event,
          pLessonElement: &pElements->m_Memory.m_pMemory[v9],
          bInFailedScope: nullptr);
        ++v8;
        ++v9;
      }
      while ( v8 < pElements->m_Size );
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return false;
  }
  else
  {
    iElementa = 0;
    if ( pElements->m_Size > 0 )
    {
      while ( 1 )
      {
        if ( v7 == this->m_iScopeDepth )
          v7 = -1;
        if ( CScriptedIconLesson::ProcessElement(
               this,
               a2: (const char *)(v3 * 20),
               event,
               pLessonElement: &pElements->m_Memory.m_pMemory[v3],
               bInFailedScope: (char *)(v7 != -1)) == 0 )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this, a2: (const char *)(v3 * 20)) )
          {
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tPrevious element returned false.\n");
          }
          v7 = this->m_iScopeDepth - 1;
          if ( v7 < 0 )
            break;
        }
        ++v3;
        if ( ++iElementa >= pElements->m_Size )
          goto LABEL_22;
      }
      bSuccess = false;
    }
LABEL_22:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return bSuccess;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100571F0
// Name: public: virtual void CScriptedIconLesson::OnOpen(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CScriptedIconLesson::OnOpen(CScriptedIconLesson *this@<ecx>, const char *a2@<ebx>)
{
  CBaseLesson *m_pRoot; // eax
  CHandle<C_BaseEntity> *v4; // edi
  char *m_pszString; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const CScriptedIconLesson *pLesson; // [esp+Ch] [ebp-24h]
  int iLessonEvent; // [esp+10h] [ebp-20h]
  int v11; // [esp+14h] [ebp-1Ch]
  const char *pSearch; // [esp+1Ch] [ebp-14h]
  struct Color v14; // [esp+20h] [ebp-10h] BYREF
  struct Color v15; // [esp+24h] [ebp-Ch] BYREF
  struct Color v16; // [esp+28h] [ebp-8h] BYREF
  struct Color v17; // [esp+2Ch] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CScriptedIconLesson::OnOpen",
    a3: 0,
    a4: "GameInstructor",
    a5: false,
    a6: 4);
  if ( CBaseLesson::DoDelayedPlayerSwaps(this) != 0 )
  {
    m_pRoot = this->m_pRoot;
    pLesson = (const CScriptedIconLesson *)m_pRoot;
    iLessonEvent = 0;
    if ( m_pRoot[1].m_pDelayedPlayerSwap[6].iNewUserID > 0 )
    {
      v11 = 0;
      LOBYTE(a2) = -1;
      while ( 1 )
      {
        v4 = &m_pRoot[1].m_pDelayedPlayerSwap[5].phHandleToChange[v11];
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 1
          && ((gameinstructor_verbose_lesson.m_nFlags & 0x1000) != 0
           || (m_pszString = gameinstructor_verbose_lesson.m_pParent->m_Value.m_pszString) != nullptr
           && *m_pszString != 0) )
        {
          if ( (gameinstructor_verbose_lesson.m_nFlags & 0x1000) != 0 )
          {
            pSearch = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            pSearch = gameinstructor_verbose_lesson.m_pParent->m_Value.m_pszString;
            if ( pSearch == nullptr )
              pSearch = prType;
          }
          v6 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
          if ( V_stristr(a1: pSearch, a2, pStr: v6, pSearch) != nullptr )
          {
            v17._color[0] = -1;
            *(_WORD *)&v17._color[1] = 16512;
            v17._color[3] = -1;
            ConColorMsg(a1: &v17, a2: "GAME INSTRUCTOR: ");
            *(_WORD *)v16._color = -32704;
            v16._color[2] = -1;
            v16._color[3] = -1;
            ConColorMsg(a1: &v16, a2: "OnOpen event ");
            v7 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: (CUtlSymbol)v4[5].m_Index);
            v15._color[0] = 0;
            v15._color[1] = -1;
            v15._color[2] = 0;
            v15._color[3] = -1;
            ConColorMsg(a1: &v15, a2: "\"%s\"", v7);
            v8 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
            *(_WORD *)v14._color = -32704;
            v14._color[2] = -1;
            v14._color[3] = -1;
            ConColorMsg(a1: &v14, a2: "received for lesson \"%s\"...\n", v8);
          }
        }
        CScriptedIconLesson::ProcessElements(
          this,
          event: nullptr,
          pElements: (const CUtlVector<LessonElement_t,CUtlMemory<LessonElement_t,int> > *)v4);
        v11 += 6;
        if ( ++iLessonEvent >= pLesson->m_OnOpenEvents.m_Size )
          break;
        m_pRoot = &pLesson->CIconLesson;
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100573C0
// Name: public: virtual void CScriptedIconLesson::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptedIconLesson::Update(CScriptedIconLesson *this)
{
  CBaseLesson *m_pRoot; // edi
  ConVar *m_pParent; // eax
  bool v4; // zf
  int v5; // edi
  const char *v6; // eax
  const char *v7; // eax
  int iVerbose; // [esp+Ch] [ebp-14h]
  const CScriptedIconLesson *pLesson; // [esp+10h] [ebp-10h]
  int iLessonEvent; // [esp+14h] [ebp-Ch]
  int v11; // [esp+18h] [ebp-8h]
  bool bShowSpew; // [esp+1Fh] [ebp-1h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CScriptedIconLesson::Update",
    a3: 0,
    a4: "GameInstructor",
    a5: false,
    a6: 4);
  if ( CBaseLesson::DoDelayedPlayerSwaps(this) != 0 )
  {
    m_pRoot = this->m_pRoot;
    pLesson = (const CScriptedIconLesson *)m_pRoot;
    if ( *(float *)(gpGlobals.m_Index + 12) >= this->m_fUpdateEventTime )
    {
      m_pParent = gameinstructor_verbose.m_pParent;
      if ( gameinstructor_verbose.m_pParent == nullptr
        || gameinstructor_verbose.m_pParent->m_Value.m_nValue <= 1
        || (v4 = !CBaseLesson::ShouldShowSpew(this, a2: (const char *)this),
            m_pParent = gameinstructor_verbose.m_pParent,
            bShowSpew = true,
            v4) )
      {
        bShowSpew = false;
      }
      if ( m_pParent != nullptr )
      {
        iVerbose = m_pParent->m_Value.m_nValue;
        if ( iVerbose == 1 )
          ConVar::SetValue(this: (ConVar *)&gameinstructor_verbose.IConVar, value: 0);
      }
      else
      {
        iVerbose = 0;
      }
      iLessonEvent = 0;
      if ( m_pRoot[2].m_nDebugID > 0 )
      {
        v11 = 0;
        while ( 1 )
        {
          v5 = v11 + m_pRoot[1].m_pDelayedPlayerSwap[7].iNewUserID;
          if ( bShowSpew )
          {
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Update event ");
            v6 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: *(CUtlSymbol *)(v5 + 20));
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseUpdate, a2: "\"%s\"", v6);
            v7 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "received for lesson \"%s\"...\n", v7);
          }
          CScriptedIconLesson::ProcessElements(
            this,
            event: nullptr,
            pElements: (const CUtlVector<LessonElement_t,CUtlMemory<LessonElement_t,int> > *)v5);
          v11 += 24;
          if ( ++iLessonEvent >= pLesson->m_UpdateEvents.m_Size )
            break;
          m_pRoot = &pLesson->CIconLesson;
        }
      }
      ConVar::SetValue(this: (ConVar *)&gameinstructor_verbose.IConVar, value: iVerbose);
      this->m_fUpdateEventTime = *(float *)(gpGlobals.m_Index + 12) + this->m_fUpdateInterval;
    }
    CIconLesson::Update(this, a2: (const char *)&savedregs);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10057550
// Name: public: virtual void CScriptedIconLesson::ProcessOpenGameEvents(class CScriptedIconLesson const __near *,char const __near *,class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CScriptedIconLesson::ProcessOpenGameEvents(
        CScriptedIconLesson *this@<ecx>,
        const char *a2@<ebx>,
        const CScriptedIconLesson *pRootLesson,
        const char *name,
        IGameEvent *event)
{
  const CScriptedIconLesson *v5; // edi
  C_GameInstructor *v7; // eax
  const char *v8; // eax
  LessonEvent_t *v9; // edi
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  CScriptedIconLesson *m_pDefaultHolder; // eax
  CScriptedIconLesson *v14; // eax
  CScriptedIconLesson *v15; // eax
  CScriptedIconLesson *v16; // eax
  CScriptedIconLesson *v17; // eax
  CScriptedIconLesson *v18; // eax
  int m_nSplitScreenSlot; // edi
  const char *v20; // eax
  CScriptedIconLesson *v21; // edi
  C_GameInstructor *GameInstructor; // eax
  CScriptedIconLesson *v24; // [esp+Ch] [ebp-Ch]
  int iLessonEvent; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]

  v5 = pRootLesson;
  if ( pRootLesson->m_iInstanceType == LESSON_INSTANCE_SINGLE_OPEN
    && (v7 = GetGameInstructor(), C_GameInstructor::IsLessonOfSameTypeOpen(this: v7, pLesson: this)) )
  {
    if ( gameinstructor_verbose.m_pParent != nullptr
      && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
      && CBaseLesson::ShouldShowSpew(this, a2) )
    {
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Opportunity ");
      v8 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: pRootLesson->m_stringName.m_SymbolId);
      ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\" ", v8);
      ConColorMsg(
        a1: &CBaseLesson::m_rgbaVerbosePlain,
        a2: "open events NOT processed (there is already an open lesson of this type).\n");
    }
  }
  else
  {
    iLessonEvent = 0;
    if ( pRootLesson->m_OpenEvents.m_Size > 0 )
    {
      v26 = 0;
      while ( 1 )
      {
        v9 = &v5->m_OpenEvents.m_Memory.m_pMemory[v26];
        v10 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v9->szEventName.m_SymbolId);
        if ( _V_strcmp(s1: name, s2: v10) == 0 )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this, a2: (const char *)ConColorMsg) )
          {
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Open event ");
            v11 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v9->szEventName.m_SymbolId);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseOpen, a2: "\"%s\"", v11);
            v12 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "received for lesson \"%s\"...\n", v12);
          }
          m_pDefaultHolder = this->m_pDefaultHolder;
          if ( m_pDefaultHolder != nullptr )
          {
            this->m_hLocalPlayer.m_Index = m_pDefaultHolder->m_hLocalPlayer.m_Index;
            this->m_hLocalPlayer.m_Index = m_pDefaultHolder->m_hLocalPlayer.m_Index;
            this->m_fOutput = m_pDefaultHolder->m_fOutput;
            this->m_hEntity1.m_Index = m_pDefaultHolder->m_hEntity1.m_Index;
            this->m_hEntity2.m_Index = m_pDefaultHolder->m_hEntity2.m_Index;
            this->m_szString1.m_SymbolId.m_Id = m_pDefaultHolder->m_szString1.m_SymbolId.m_Id;
            this->m_szString2.m_SymbolId.m_Id = this->m_pDefaultHolder->m_szString2.m_SymbolId.m_Id;
            v14 = this->m_pDefaultHolder;
            this->m_iInteger1 = v14->m_iInteger1;
            this->m_iInteger2 = v14->m_iInteger2;
            this->m_fFloat1 = v14->m_fFloat1;
            this->m_fFloat2 = v14->m_fFloat2;
            this->m_hIconTarget.m_Index = v14->m_hIconTarget.m_Index;
            this->m_szVguiTargetName.m_SymbolId.m_Id = v14->m_szVguiTargetName.m_SymbolId.m_Id;
            this->m_szVguiTargetLookup.m_SymbolId.m_Id = this->m_pDefaultHolder->m_szVguiTargetLookup.m_SymbolId.m_Id;
            v15 = this->m_pDefaultHolder;
            this->m_nVguiTargetEdge = v15->m_nVguiTargetEdge;
            this->m_fFixedPositionX = v15->m_fFixedPositionX;
            this->m_fFixedPositionY = v15->m_fFixedPositionY;
            this->m_bFixedPosition = v15->m_bFixedPosition;
            this->m_bNoIconTarget = v15->m_bNoIconTarget;
            this->m_bAllowNodrawTarget = v15->m_bAllowNodrawTarget;
            this->m_bVisible = v15->m_bVisible;
            this->m_bShowWhenOccluded = v15->m_bShowWhenOccluded;
            this->m_bNoOffscreen = v15->m_bNoOffscreen;
            this->m_bForceCaption = v15->m_bForceCaption;
            this->m_szOnscreenIcon.m_SymbolId.m_Id = v15->m_szOnscreenIcon.m_SymbolId.m_Id;
            this->m_szOffscreenIcon.m_SymbolId.m_Id = this->m_pDefaultHolder->m_szOffscreenIcon.m_SymbolId.m_Id;
            v16 = this->m_pDefaultHolder;
            this->m_flUpOffset = v16->m_flUpOffset;
            this->m_flRelativeUpOffset = v16->m_flRelativeUpOffset;
            this->m_fRange = v16->m_fRange;
            this->m_iFlags = v16->m_iFlags;
            this->m_szCaptionColor.m_SymbolId.m_Id = v16->m_szCaptionColor.m_SymbolId.m_Id;
            this->m_szLessonGroup.m_SymbolId.m_Id = this->m_pDefaultHolder->m_szLessonGroup.m_SymbolId.m_Id;
            this->m_szDisplayText.m_SymbolId.m_Id = this->m_pDefaultHolder->m_szDisplayText.m_SymbolId.m_Id;
            this->m_szDisplayParamText.m_SymbolId.m_Id = this->m_pDefaultHolder->m_szDisplayParamText.m_SymbolId.m_Id;
            this->m_szBinding.m_SymbolId.m_Id = this->m_pDefaultHolder->m_szBinding.m_SymbolId.m_Id;
            this->m_szGamepadBinding.m_SymbolId.m_Id = this->m_pDefaultHolder->m_szGamepadBinding.m_SymbolId.m_Id;
            v17 = this->m_pDefaultHolder;
            this->m_iPriority = v17->m_iPriority;
            this->m_stringReplaceKey.m_SymbolId.m_Id = v17->m_stringReplaceKey.m_SymbolId.m_Id;
            v18 = this->m_pDefaultHolder;
            this->m_fLockDuration = v18->m_fLockDuration;
            this->m_bCanOpenWhenDead = v18->m_bCanOpenWhenDead;
            this->m_bBumpWithTimeoutWhenLearned = v18->m_bBumpWithTimeoutWhenLearned;
            this->m_bOnceLearnedNeverOpen = v18->m_bOnceLearnedNeverOpen;
            this->m_bCanTimeoutWhileInactive = v18->m_bCanTimeoutWhileInactive;
            this->m_bUsableInMidair = v18->m_bUsableInMidair;
            this->m_fTimeout = v18->m_fTimeout;
            this->m_fUpdateInterval = v18->m_fUpdateInterval;
            this->m_szStartSound.m_SymbolId.m_Id = v18->m_szStartSound.m_SymbolId.m_Id;
          }
          if ( CScriptedIconLesson::ProcessElements(this, event, pElements: &v9->elements) )
          {
            if ( gameinstructor_verbose.m_pParent != nullptr
              && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
              && CBaseLesson::ShouldShowSpew(this, a2: (const char *)ConColorMsg) )
            {
              ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseOpen, a2: "\tAll elements returned true. Opening!\n");
            }
            v24 = (CScriptedIconLesson *)MemAlloc_Alloc(nSize: 0x1D0u);
            if ( v24 != nullptr )
            {
              m_nSplitScreenSlot = this->m_nSplitScreenSlot;
              v20 = CUtlSymbolTable::String(
                      this: &g_CGameInstructorSymbolSymbolTable,
                      id: this->m_stringName.m_SymbolId);
              v21 = CScriptedIconLesson::CScriptedIconLesson(
                      this: v24,
                      pchName: v20,
                      bIsDefaultHolder: false,
                      bIsOpenOpportunity: true,
                      nSplitScreenSlot: m_nSplitScreenSlot);
            }
            else
            {
              v21 = nullptr;
            }
            v21->m_hLocalPlayer.m_Index = this->m_hLocalPlayer.m_Index;
            v21->m_hLocalPlayer.m_Index = this->m_hLocalPlayer.m_Index;
            v21->m_fOutput = this->m_fOutput;
            v21->m_hEntity1.m_Index = this->m_hEntity1.m_Index;
            v21->m_hEntity2.m_Index = this->m_hEntity2.m_Index;
            v21->m_szString1.m_SymbolId.m_Id = this->m_szString1.m_SymbolId.m_Id;
            v21->m_szString2.m_SymbolId.m_Id = this->m_szString2.m_SymbolId.m_Id;
            v21->m_iInteger1 = this->m_iInteger1;
            v21->m_iInteger2 = this->m_iInteger2;
            v21->m_fFloat1 = this->m_fFloat1;
            v21->m_fFloat2 = this->m_fFloat2;
            v21->m_hIconTarget.m_Index = this->m_hIconTarget.m_Index;
            v21->m_szVguiTargetName.m_SymbolId.m_Id = this->m_szVguiTargetName.m_SymbolId.m_Id;
            v21->m_szVguiTargetLookup.m_SymbolId.m_Id = this->m_szVguiTargetLookup.m_SymbolId.m_Id;
            v21->m_nVguiTargetEdge = this->m_nVguiTargetEdge;
            v21->m_fFixedPositionX = this->m_fFixedPositionX;
            v21->m_fFixedPositionY = this->m_fFixedPositionY;
            v21->m_bFixedPosition = this->m_bFixedPosition;
            v21->m_bNoIconTarget = this->m_bNoIconTarget;
            v21->m_bAllowNodrawTarget = this->m_bAllowNodrawTarget;
            v21->m_bVisible = this->m_bVisible;
            v21->m_bShowWhenOccluded = this->m_bShowWhenOccluded;
            v21->m_bNoOffscreen = this->m_bNoOffscreen;
            v21->m_bForceCaption = this->m_bForceCaption;
            v21->m_szOnscreenIcon.m_SymbolId.m_Id = this->m_szOnscreenIcon.m_SymbolId.m_Id;
            v21->m_szOffscreenIcon.m_SymbolId.m_Id = this->m_szOffscreenIcon.m_SymbolId.m_Id;
            v21->m_flUpOffset = this->m_flUpOffset;
            v21->m_flRelativeUpOffset = this->m_flRelativeUpOffset;
            v21->m_fRange = this->m_fRange;
            v21->m_iFlags = this->m_iFlags;
            v21->m_szCaptionColor.m_SymbolId.m_Id = this->m_szCaptionColor.m_SymbolId.m_Id;
            v21->m_szLessonGroup.m_SymbolId.m_Id = this->m_szLessonGroup.m_SymbolId.m_Id;
            v21->m_szDisplayText.m_SymbolId.m_Id = this->m_szDisplayText.m_SymbolId.m_Id;
            v21->m_szDisplayParamText.m_SymbolId.m_Id = this->m_szDisplayParamText.m_SymbolId.m_Id;
            v21->m_szBinding.m_SymbolId.m_Id = this->m_szBinding.m_SymbolId.m_Id;
            v21->m_szGamepadBinding.m_SymbolId.m_Id = this->m_szGamepadBinding.m_SymbolId.m_Id;
            v21->m_iPriority = this->m_iPriority;
            v21->m_stringReplaceKey.m_SymbolId.m_Id = this->m_stringReplaceKey.m_SymbolId.m_Id;
            v21->m_fLockDuration = this->m_fLockDuration;
            v21->m_bCanOpenWhenDead = this->m_bCanOpenWhenDead;
            v21->m_bBumpWithTimeoutWhenLearned = this->m_bBumpWithTimeoutWhenLearned;
            v21->m_bOnceLearnedNeverOpen = this->m_bOnceLearnedNeverOpen;
            v21->m_bCanTimeoutWhileInactive = this->m_bCanTimeoutWhileInactive;
            v21->m_bUsableInMidair = this->m_bUsableInMidair;
            v21->m_fTimeout = this->m_fTimeout;
            v21->m_fUpdateInterval = this->m_fUpdateInterval;
            v21->m_szStartSound.m_SymbolId.m_Id = this->m_szStartSound.m_SymbolId.m_Id;
            GameInstructor = GetGameInstructor();
            if ( C_GameInstructor::OpenOpportunity(this: GameInstructor, pLesson: v21) )
            {
              v21->OnOpen(this: v21);
              if ( pRootLesson->m_iInstanceType == LESSON_INSTANCE_SINGLE_OPEN )
                break;
            }
          }
        }
        ++v26;
        if ( ++iLessonEvent >= pRootLesson->m_OpenEvents.m_Size )
          break;
        v5 = pRootLesson;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057C70
// Name: public: virtual void CScriptedIconLesson::ProcessCloseGameEvents(class CScriptedIconLesson const __near *,char const __near *,class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptedIconLesson::ProcessCloseGameEvents(
        CScriptedIconLesson *this,
        const CScriptedIconLesson *pRootLesson,
        const char *name,
        IGameEvent *event)
{
  LessonEvent_t *v5; // edi
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  int iLessonEvent; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  CUtlSymbol result; // [esp+16h] [ebp-2h] BYREF

  iLessonEvent = 0;
  if ( pRootLesson->m_CloseEvents.m_Size > 0 )
  {
    v10 = 0;
    do
    {
      if ( (*((_BYTE *)&this->CBaseLesson + 60) & 8) == 0 )
        break;
      v5 = &pRootLesson->m_CloseEvents.m_Memory.m_pMemory[v10];
      v6 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v5->szEventName.m_SymbolId);
      if ( _V_strcmp(s1: name, s2: v6) == 0 )
      {
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && CBaseLesson::ShouldShowSpew(this, a2: (const char *)this) )
        {
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Close event ");
          v7 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v5->szEventName.m_SymbolId);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\"%s\"", v7);
          v8 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
          ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "received for lesson \"%s\"...\n", v8);
        }
        if ( CScriptedIconLesson::ProcessElements(this, event, pElements: &v5->elements) )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this, a2: (const char *)this) )
          {
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseClose, a2: "\tAll elements returned true. Closing!\n");
          }
          this->m_stringCloseReason.m_SymbolId = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                               this: &g_CGameInstructorSymbolSymbolTable,
                                                               &result,
                                                               pString: "Close event elements completed.")->m_Id;
          *((_BYTE *)&this->CBaseLesson + 60) &= ~8u;
        }
      }
      ++v10;
      ++iLessonEvent;
    }
    while ( iLessonEvent < pRootLesson->m_CloseEvents.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057DE0
// Name: public: virtual void CScriptedIconLesson::ProcessSuccessGameEvents(class CScriptedIconLesson const __near *,char const __near *,class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptedIconLesson::ProcessSuccessGameEvents(
        CScriptedIconLesson *this,
        const CScriptedIconLesson *pRootLesson,
        const char *name,
        IGameEvent *event)
{
  LessonEvent_t *v5; // edi
  const char *v6; // eax
  char *m_pszString; // eax
  const char *v8; // eax
  const char *v9; // ecx
  const char *v10; // eax
  const char *v11; // eax
  C_GameInstructor *GameInstructor; // eax
  const char *v13; // [esp-4h] [ebp-1Ch]
  int iLessonEvent; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  const char *pSearch; // [esp+14h] [ebp-4h]

  iLessonEvent = 0;
  if ( pRootLesson->m_SuccessEvents.m_Size > 0 )
  {
    v15 = 0;
    do
    {
      v5 = &pRootLesson->m_SuccessEvents.m_Memory.m_pMemory[v15];
      v6 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v5->szEventName.m_SymbolId);
      if ( _V_strcmp(s1: name, s2: v6) == 0 )
      {
        if ( gameinstructor_verbose.m_pParent != nullptr
          && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
          && ((gameinstructor_verbose_lesson.m_nFlags & 0x1000) != 0
           || (m_pszString = gameinstructor_verbose_lesson.m_pParent->m_Value.m_pszString) != nullptr
           && *m_pszString != 0) )
        {
          if ( (gameinstructor_verbose_lesson.m_nFlags & 0x1000) != 0 )
          {
            pSearch = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            pSearch = gameinstructor_verbose_lesson.m_pParent->m_Value.m_pszString;
            if ( pSearch == nullptr )
              pSearch = prType;
          }
          v8 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
          if ( V_stristr(a1: v9, a2: (const char *)this, pStr: v8, pSearch) != nullptr )
          {
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseHeader, a2: "GAME INSTRUCTOR: ");
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "Success event ");
            v10 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: v5->szEventName.m_SymbolId);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseSuccess, a2: "\"%s\"", v10);
            v11 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerbosePlain, a2: "received for lesson \"%s\"...\n", v11);
          }
        }
        if ( CScriptedIconLesson::ProcessElements(this, event, pElements: &v5->elements) )
        {
          if ( gameinstructor_verbose.m_pParent != nullptr
            && gameinstructor_verbose.m_pParent->m_Value.m_nValue > 0
            && CBaseLesson::ShouldShowSpew(this, a2: (const char *)this) )
          {
            ConColorMsg(a1: &CBaseLesson::m_rgbaVerboseSuccess, a2: "\tAll elements returned true. Succeeding!\n");
          }
          if ( (*((_BYTE *)&this->CBaseLesson + 60) & 2) == 0 )
          {
            v13 = CUtlSymbolTable::String(this: &g_CGameInstructorSymbolSymbolTable, id: this->m_stringName.m_SymbolId);
            GameInstructor = GetGameInstructor();
            C_GameInstructor::MarkSucceeded(this: GameInstructor, pchLessonName: v13);
            *((_BYTE *)&this->CBaseLesson + 60) |= 2u;
          }
        }
      }
      ++v15;
      ++iLessonEvent;
    }
    while ( iLessonEvent < pRootLesson->m_SuccessEvents.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10411190
// Name: CScriptedIconLesson_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CScriptedIconLesson_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CScriptedIconLesson>();
  CScriptedIconLesson_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10053F00
// Name: struct datamap_t __near * DataMapInit<class CScriptedIconLesson>(class CScriptedIconLesson __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CScriptedIconLesson>()
{
  _fieldtypes v0; // eax
  _fieldtypes v1; // eax
  _fieldtypes v2; // eax
  _fieldtypes v3; // eax
  _fieldtypes v4; // eax
  _fieldtypes v5; // eax
  _fieldtypes v6; // eax
  _fieldtypes v7; // eax
  _fieldtypes v8; // eax
  _fieldtypes v9; // eax
  _fieldtypes v10; // eax
  _fieldtypes v11; // eax
  _fieldtypes v12; // eax
  _fieldtypes v13; // eax
  _fieldtypes v14; // eax
  _fieldtypes v15; // eax
  _fieldtypes v16; // eax
  _fieldtypes v17; // eax
  _fieldtypes v18; // eax
  _fieldtypes v19; // eax
  _fieldtypes v20; // eax

  if ( (_S5_16 & 1) == 0 )
  {
    _S5_16 |= 1u;
    nameHolder_6.m_pszBase = "CScriptedIconLesson";
    nameHolder_6.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_6.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_6.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_6.m_Names.m_Size = 0;
    nameHolder_6.m_Names.m_pElements = nullptr;
    nameHolder_6.m_nLenBase = 19;
    atexit(func: DataMapInit_CScriptedIconLesson__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CScriptedIconLesson::m_DataMap.baseMap = nullptr;
  if ( (_S5_16 & 2) == 0 )
  {
    _S5_16 |= 2u;
    *(_QWORD *)&dataDesc_6[1].td = 0;
    *(_QWORD *)&dataDesc_6[1].override_field = 0;
    *(_QWORD *)&dataDesc_6[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[1].flatOffset[1] = 0;
    dataDesc_6[2].fieldSize = 1;
    dataDesc_6[2].flags = 2;
    dataDesc_6[2].fieldTolerance = 0.0;
    dataDesc_6[3].fieldTolerance = 0.0;
    dataDesc_6[1].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[1].inputFunc = nullptr;
    dataDesc_6[2].fieldType = FIELD_EHANDLE;
    dataDesc_6[2].fieldName = "m_hLocalPlayer";
    dataDesc_6[2].fieldOffset = 296;
    dataDesc_6[2].externalName = nullptr;
    dataDesc_6[2].pSaveRestoreOps = nullptr;
    dataDesc_6[2].inputFunc = nullptr;
    dataDesc_6[2].td = nullptr;
    dataDesc_6[2].fieldSizeInBytes = 4;
    dataDesc_6[2].override_field = nullptr;
    dataDesc_6[2].override_count = 0;
    *(_QWORD *)dataDesc_6[2].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[2].flatGroup = 0;
    dataDesc_6[3].fieldType = FIELD_EHANDLE;
    dataDesc_6[3].fieldName = "m_hLocalPlayer";
    dataDesc_6[3].fieldOffset = 296;
    *(_DWORD *)&dataDesc_6[3].fieldSize = 131073;
    dataDesc_6[3].externalName = nullptr;
    dataDesc_6[3].pSaveRestoreOps = nullptr;
    dataDesc_6[3].inputFunc = nullptr;
    dataDesc_6[3].td = nullptr;
    dataDesc_6[3].fieldSizeInBytes = 4;
    dataDesc_6[3].override_field = nullptr;
    dataDesc_6[3].override_count = 0;
    *(_QWORD *)dataDesc_6[3].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[3].flatGroup = 0;
    dataDesc_6[4].fieldType = LessonParamTypeFromString(pchName: "float");
    *(_QWORD *)dataDesc_6[4].flatOffset = 0;
    dataDesc_6[4].fieldName = "m_fOutput";
    dataDesc_6[4].fieldOffset = 300;
    *(_DWORD *)&dataDesc_6[4].fieldSize = 131073;
    dataDesc_6[4].externalName = nullptr;
    dataDesc_6[4].pSaveRestoreOps = nullptr;
    dataDesc_6[4].inputFunc = nullptr;
    dataDesc_6[4].td = nullptr;
    dataDesc_6[4].fieldSizeInBytes = 4;
    dataDesc_6[4].override_field = nullptr;
    dataDesc_6[4].override_count = 0;
    dataDesc_6[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_6[4].flatGroup = 0;
    dataDesc_6[5].fieldType = FIELD_EHANDLE;
    dataDesc_6[5].fieldName = "m_hEntity1";
    dataDesc_6[5].fieldOffset = 304;
    *(_DWORD *)&dataDesc_6[5].fieldSize = 131073;
    dataDesc_6[5].externalName = nullptr;
    dataDesc_6[5].pSaveRestoreOps = nullptr;
    dataDesc_6[5].inputFunc = nullptr;
    dataDesc_6[5].td = nullptr;
    dataDesc_6[5].fieldSizeInBytes = 4;
    dataDesc_6[5].override_field = nullptr;
    dataDesc_6[5].override_count = 0;
    dataDesc_6[5].fieldTolerance = 0.0;
    dataDesc_6[6].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_6[6].flatOffset = 0;
    dataDesc_6[6].fieldType = FIELD_EHANDLE;
    *(_QWORD *)&dataDesc_6[7].td = 0;
    *(_QWORD *)&dataDesc_6[7].override_field = 0;
    *(_QWORD *)&dataDesc_6[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[7].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_6[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[5].flatGroup = 0;
    dataDesc_6[6].fieldName = "m_hEntity2";
    dataDesc_6[6].fieldOffset = 308;
    *(_DWORD *)&dataDesc_6[6].fieldSize = 131073;
    dataDesc_6[6].externalName = nullptr;
    dataDesc_6[6].pSaveRestoreOps = nullptr;
    dataDesc_6[6].inputFunc = nullptr;
    dataDesc_6[6].td = nullptr;
    dataDesc_6[6].fieldSizeInBytes = 4;
    dataDesc_6[6].override_field = nullptr;
    dataDesc_6[6].override_count = 0;
    *(_DWORD *)&dataDesc_6[6].flatGroup = 0;
    dataDesc_6[7].fieldType = FIELD_CUSTOM;
    dataDesc_6[7].fieldName = "m_szString1";
    dataDesc_6[7].fieldOffset = 312;
    *(_DWORD *)&dataDesc_6[7].fieldSize = 131073;
    dataDesc_6[7].externalName = nullptr;
    dataDesc_6[7].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[7].inputFunc = nullptr;
    dataDesc_6[8].fieldType = FIELD_CUSTOM;
    dataDesc_6[8].fieldName = "m_szString2";
    dataDesc_6[8].fieldOffset = 314;
    *(_DWORD *)&dataDesc_6[8].fieldSize = 131073;
    dataDesc_6[8].externalName = nullptr;
    dataDesc_6[8].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[8].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_6[8].td = 0;
    *(_QWORD *)&dataDesc_6[8].override_field = 0;
    *(_QWORD *)&dataDesc_6[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[8].flatOffset[1] = 0;
    v0 = LessonParamTypeFromString(pchName: "int");
    dataDesc_6[9].fieldTolerance = 0.0;
    dataDesc_6[9].fieldType = v0;
    dataDesc_6[9].fieldName = "m_iInteger1";
    dataDesc_6[9].fieldOffset = 316;
    *(_DWORD *)&dataDesc_6[9].fieldSize = 131073;
    dataDesc_6[9].externalName = nullptr;
    dataDesc_6[9].pSaveRestoreOps = nullptr;
    dataDesc_6[9].inputFunc = nullptr;
    dataDesc_6[9].td = nullptr;
    dataDesc_6[9].fieldSizeInBytes = 4;
    dataDesc_6[9].override_field = nullptr;
    dataDesc_6[9].override_count = 0;
    *(_QWORD *)dataDesc_6[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[9].flatGroup = 0;
    v1 = LessonParamTypeFromString(pchName: "int");
    dataDesc_6[10].fieldTolerance = 0.0;
    dataDesc_6[10].fieldType = v1;
    dataDesc_6[10].fieldName = "m_iInteger2";
    dataDesc_6[10].fieldOffset = 320;
    *(_DWORD *)&dataDesc_6[10].fieldSize = 131073;
    dataDesc_6[10].externalName = nullptr;
    dataDesc_6[10].pSaveRestoreOps = nullptr;
    dataDesc_6[10].inputFunc = nullptr;
    dataDesc_6[10].td = nullptr;
    dataDesc_6[10].fieldSizeInBytes = 4;
    dataDesc_6[10].override_field = nullptr;
    dataDesc_6[10].override_count = 0;
    *(_QWORD *)dataDesc_6[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[10].flatGroup = 0;
    dataDesc_6[11].fieldType = LessonParamTypeFromString(pchName: "float");
    dataDesc_6[11].fieldTolerance = 0.0;
    dataDesc_6[11].fieldName = "m_fFloat1";
    dataDesc_6[11].fieldOffset = 324;
    *(_DWORD *)&dataDesc_6[11].fieldSize = 131073;
    dataDesc_6[11].externalName = nullptr;
    dataDesc_6[11].pSaveRestoreOps = nullptr;
    dataDesc_6[11].inputFunc = nullptr;
    dataDesc_6[11].td = nullptr;
    dataDesc_6[11].fieldSizeInBytes = 4;
    dataDesc_6[11].override_field = nullptr;
    dataDesc_6[11].override_count = 0;
    *(_QWORD *)dataDesc_6[11].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[11].flatGroup = 0;
    v2 = LessonParamTypeFromString(pchName: "float");
    dataDesc_6[12].fieldTolerance = 0.0;
    dataDesc_6[13].fieldTolerance = 0.0;
    dataDesc_6[12].fieldType = v2;
    *(_QWORD *)dataDesc_6[13].flatOffset = 0;
    *(_QWORD *)&dataDesc_6[14].td = 0;
    *(_QWORD *)&dataDesc_6[14].override_field = 0;
    *(_QWORD *)&dataDesc_6[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[14].flatOffset[1] = 0;
    dataDesc_6[12].fieldName = "m_fFloat2";
    dataDesc_6[12].fieldOffset = 328;
    *(_DWORD *)&dataDesc_6[12].fieldSize = 131073;
    dataDesc_6[12].externalName = nullptr;
    dataDesc_6[12].pSaveRestoreOps = nullptr;
    dataDesc_6[12].inputFunc = nullptr;
    dataDesc_6[12].td = nullptr;
    dataDesc_6[12].fieldSizeInBytes = 4;
    dataDesc_6[12].override_field = nullptr;
    dataDesc_6[12].override_count = 0;
    *(_QWORD *)dataDesc_6[12].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[12].flatGroup = 0;
    dataDesc_6[13].fieldType = FIELD_EHANDLE;
    dataDesc_6[13].fieldName = "m_hIconTarget";
    dataDesc_6[13].fieldOffset = 228;
    *(_DWORD *)&dataDesc_6[13].fieldSize = 131073;
    dataDesc_6[13].externalName = nullptr;
    dataDesc_6[13].pSaveRestoreOps = nullptr;
    dataDesc_6[13].inputFunc = nullptr;
    dataDesc_6[13].td = nullptr;
    dataDesc_6[13].fieldSizeInBytes = 4;
    dataDesc_6[13].override_field = nullptr;
    dataDesc_6[13].override_count = 0;
    *(_DWORD *)&dataDesc_6[13].flatGroup = 0;
    dataDesc_6[14].fieldType = FIELD_CUSTOM;
    dataDesc_6[14].fieldName = "m_szVguiTargetName";
    dataDesc_6[14].fieldOffset = 232;
    *(_DWORD *)&dataDesc_6[14].fieldSize = 131073;
    dataDesc_6[14].externalName = nullptr;
    dataDesc_6[14].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[14].inputFunc = nullptr;
    dataDesc_6[15].fieldType = FIELD_CUSTOM;
    dataDesc_6[15].fieldName = "m_szVguiTargetLookup";
    dataDesc_6[15].fieldOffset = 234;
    *(_DWORD *)&dataDesc_6[15].fieldSize = 131073;
    dataDesc_6[15].externalName = nullptr;
    dataDesc_6[15].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[15].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_6[15].td = 0;
    *(_QWORD *)&dataDesc_6[15].override_field = 0;
    *(_QWORD *)&dataDesc_6[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[15].flatOffset[1] = 0;
    dataDesc_6[16].fieldType = LessonParamTypeFromString(pchName: "int");
    dataDesc_6[16].fieldName = "m_nVguiTargetEdge";
    dataDesc_6[16].fieldOffset = 236;
    *(_DWORD *)&dataDesc_6[16].fieldSize = 131073;
    dataDesc_6[16].externalName = nullptr;
    dataDesc_6[16].pSaveRestoreOps = nullptr;
    dataDesc_6[16].fieldTolerance = 0.0;
    dataDesc_6[16].inputFunc = nullptr;
    dataDesc_6[16].td = nullptr;
    dataDesc_6[16].fieldSizeInBytes = 4;
    dataDesc_6[16].override_field = nullptr;
    dataDesc_6[16].override_count = 0;
    *(_QWORD *)dataDesc_6[16].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[16].flatGroup = 0;
    v3 = LessonParamTypeFromString(pchName: "float");
    dataDesc_6[17].fieldTolerance = 0.0;
    dataDesc_6[17].fieldType = v3;
    dataDesc_6[17].fieldName = "m_fFixedPositionX";
    dataDesc_6[17].fieldOffset = 248;
    *(_DWORD *)&dataDesc_6[17].fieldSize = 131073;
    dataDesc_6[17].externalName = nullptr;
    dataDesc_6[17].pSaveRestoreOps = nullptr;
    dataDesc_6[17].inputFunc = nullptr;
    dataDesc_6[17].td = nullptr;
    dataDesc_6[17].fieldSizeInBytes = 4;
    dataDesc_6[17].override_field = nullptr;
    dataDesc_6[17].override_count = 0;
    *(_QWORD *)dataDesc_6[17].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[17].flatGroup = 0;
    v4 = LessonParamTypeFromString(pchName: "float");
    dataDesc_6[18].fieldTolerance = 0.0;
    dataDesc_6[18].fieldType = v4;
    dataDesc_6[18].fieldName = "m_fFixedPositionY";
    dataDesc_6[18].fieldOffset = 252;
    *(_DWORD *)&dataDesc_6[18].fieldSize = 131073;
    dataDesc_6[18].externalName = nullptr;
    dataDesc_6[18].pSaveRestoreOps = nullptr;
    dataDesc_6[18].inputFunc = nullptr;
    dataDesc_6[18].td = nullptr;
    dataDesc_6[18].fieldSizeInBytes = 4;
    dataDesc_6[18].override_field = nullptr;
    dataDesc_6[18].override_count = 0;
    *(_QWORD *)dataDesc_6[18].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[18].flatGroup = 0;
    v5 = LessonParamTypeFromString(pchName: "bool");
    dataDesc_6[19].fieldTolerance = 0.0;
    dataDesc_6[19].fieldType = v5;
    dataDesc_6[19].fieldName = "m_bFixedPosition";
    dataDesc_6[19].fieldOffset = 286;
    *(_DWORD *)&dataDesc_6[19].fieldSize = 131073;
    dataDesc_6[19].externalName = nullptr;
    dataDesc_6[19].pSaveRestoreOps = nullptr;
    dataDesc_6[19].inputFunc = nullptr;
    dataDesc_6[19].td = nullptr;
    dataDesc_6[19].fieldSizeInBytes = 1;
    dataDesc_6[19].override_field = nullptr;
    dataDesc_6[19].override_count = 0;
    *(_QWORD *)dataDesc_6[19].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[19].flatGroup = 0;
    v6 = LessonParamTypeFromString(pchName: "bool");
    dataDesc_6[20].fieldTolerance = 0.0;
    dataDesc_6[20].fieldType = v6;
    dataDesc_6[20].fieldName = "m_bNoIconTarget";
    dataDesc_6[20].fieldOffset = 287;
    *(_DWORD *)&dataDesc_6[20].fieldSize = 131073;
    dataDesc_6[20].externalName = nullptr;
    dataDesc_6[20].pSaveRestoreOps = nullptr;
    dataDesc_6[20].inputFunc = nullptr;
    dataDesc_6[20].td = nullptr;
    dataDesc_6[20].fieldSizeInBytes = 1;
    dataDesc_6[20].override_field = nullptr;
    dataDesc_6[20].override_count = 0;
    *(_QWORD *)dataDesc_6[20].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[20].flatGroup = 0;
    v7 = LessonParamTypeFromString(pchName: "bool");
    dataDesc_6[21].fieldTolerance = 0.0;
    dataDesc_6[21].fieldType = v7;
    dataDesc_6[21].fieldName = "m_bAllowNodrawTarget";
    dataDesc_6[21].fieldOffset = 288;
    *(_DWORD *)&dataDesc_6[21].fieldSize = 131073;
    dataDesc_6[21].externalName = nullptr;
    dataDesc_6[21].pSaveRestoreOps = nullptr;
    dataDesc_6[21].inputFunc = nullptr;
    dataDesc_6[21].td = nullptr;
    dataDesc_6[21].fieldSizeInBytes = 1;
    dataDesc_6[21].override_field = nullptr;
    dataDesc_6[21].override_count = 0;
    *(_QWORD *)dataDesc_6[21].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[21].flatGroup = 0;
    v8 = LessonParamTypeFromString(pchName: "bool");
    dataDesc_6[22].fieldTolerance = 0.0;
    dataDesc_6[22].fieldType = v8;
    dataDesc_6[22].fieldName = "m_bVisible";
    dataDesc_6[22].fieldOffset = 289;
    *(_DWORD *)&dataDesc_6[22].fieldSize = 131073;
    dataDesc_6[22].externalName = nullptr;
    dataDesc_6[22].pSaveRestoreOps = nullptr;
    dataDesc_6[22].inputFunc = nullptr;
    dataDesc_6[22].td = nullptr;
    dataDesc_6[22].fieldSizeInBytes = 1;
    dataDesc_6[22].override_field = nullptr;
    dataDesc_6[22].override_count = 0;
    *(_QWORD *)dataDesc_6[22].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[22].flatGroup = 0;
    v9 = LessonParamTypeFromString(pchName: "bool");
    dataDesc_6[23].fieldTolerance = 0.0;
    dataDesc_6[23].fieldType = v9;
    dataDesc_6[23].fieldName = "m_bShowWhenOccluded";
    dataDesc_6[23].fieldOffset = 290;
    *(_DWORD *)&dataDesc_6[23].fieldSize = 131073;
    dataDesc_6[23].externalName = nullptr;
    dataDesc_6[23].pSaveRestoreOps = nullptr;
    dataDesc_6[23].inputFunc = nullptr;
    dataDesc_6[23].td = nullptr;
    dataDesc_6[23].fieldSizeInBytes = 1;
    dataDesc_6[23].override_field = nullptr;
    dataDesc_6[23].override_count = 0;
    *(_QWORD *)dataDesc_6[23].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[23].flatGroup = 0;
    v10 = LessonParamTypeFromString(pchName: "bool");
    dataDesc_6[24].fieldTolerance = 0.0;
    dataDesc_6[24].fieldType = v10;
    dataDesc_6[24].fieldName = "m_bNoOffscreen";
    dataDesc_6[24].fieldOffset = 291;
    *(_DWORD *)&dataDesc_6[24].fieldSize = 131073;
    dataDesc_6[24].externalName = nullptr;
    dataDesc_6[24].pSaveRestoreOps = nullptr;
    dataDesc_6[24].inputFunc = nullptr;
    dataDesc_6[24].td = nullptr;
    dataDesc_6[24].fieldSizeInBytes = 1;
    dataDesc_6[24].override_field = nullptr;
    dataDesc_6[24].override_count = 0;
    *(_QWORD *)dataDesc_6[24].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[24].flatGroup = 0;
    dataDesc_6[25].fieldType = LessonParamTypeFromString(pchName: "bool");
    dataDesc_6[25].fieldName = "m_bForceCaption";
    dataDesc_6[25].fieldOffset = 292;
    *(_DWORD *)&dataDesc_6[25].fieldSize = 131073;
    dataDesc_6[25].externalName = nullptr;
    dataDesc_6[25].pSaveRestoreOps = nullptr;
    dataDesc_6[25].fieldTolerance = 0.0;
    dataDesc_6[25].inputFunc = nullptr;
    dataDesc_6[25].td = nullptr;
    *(_QWORD *)dataDesc_6[25].flatOffset = 0;
    *(_QWORD *)&dataDesc_6[26].td = 0;
    *(_QWORD *)&dataDesc_6[26].override_field = 0;
    *(_QWORD *)&dataDesc_6[26].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[26].flatOffset[1] = 0;
    dataDesc_6[25].fieldSizeInBytes = 1;
    dataDesc_6[25].override_field = nullptr;
    dataDesc_6[25].override_count = 0;
    *(_DWORD *)&dataDesc_6[25].flatGroup = 0;
    dataDesc_6[26].fieldType = FIELD_CUSTOM;
    dataDesc_6[26].fieldName = "m_szOnscreenIcon";
    dataDesc_6[26].fieldOffset = 280;
    *(_DWORD *)&dataDesc_6[26].fieldSize = 131073;
    dataDesc_6[26].externalName = nullptr;
    dataDesc_6[26].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[26].inputFunc = nullptr;
    dataDesc_6[27].fieldType = FIELD_CUSTOM;
    dataDesc_6[27].fieldName = "m_szOffscreenIcon";
    dataDesc_6[27].fieldOffset = 282;
    *(_DWORD *)&dataDesc_6[27].fieldSize = 131073;
    dataDesc_6[27].externalName = nullptr;
    dataDesc_6[27].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[27].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_6[27].td = 0;
    *(_QWORD *)&dataDesc_6[27].override_field = 0;
    *(_QWORD *)&dataDesc_6[27].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[27].flatOffset[1] = 0;
    v11 = LessonParamTypeFromString(pchName: "float");
    dataDesc_6[28].fieldTolerance = 0.0;
    dataDesc_6[28].fieldType = v11;
    dataDesc_6[28].fieldName = "m_flUpOffset";
    dataDesc_6[28].fieldOffset = 240;
    *(_DWORD *)&dataDesc_6[28].fieldSize = 131073;
    dataDesc_6[28].externalName = nullptr;
    dataDesc_6[28].pSaveRestoreOps = nullptr;
    dataDesc_6[28].inputFunc = nullptr;
    dataDesc_6[28].td = nullptr;
    dataDesc_6[28].fieldSizeInBytes = 4;
    dataDesc_6[28].override_field = nullptr;
    dataDesc_6[28].override_count = 0;
    *(_QWORD *)dataDesc_6[28].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[28].flatGroup = 0;
    v12 = LessonParamTypeFromString(pchName: "float");
    dataDesc_6[29].fieldTolerance = 0.0;
    dataDesc_6[29].fieldType = v12;
    dataDesc_6[29].fieldName = "m_flRelativeUpOffset";
    dataDesc_6[29].fieldOffset = 244;
    *(_DWORD *)&dataDesc_6[29].fieldSize = 131073;
    dataDesc_6[29].externalName = nullptr;
    dataDesc_6[29].pSaveRestoreOps = nullptr;
    dataDesc_6[29].inputFunc = nullptr;
    dataDesc_6[29].td = nullptr;
    dataDesc_6[29].fieldSizeInBytes = 4;
    dataDesc_6[29].override_field = nullptr;
    dataDesc_6[29].override_count = 0;
    *(_QWORD *)dataDesc_6[29].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[29].flatGroup = 0;
    dataDesc_6[30].fieldType = LessonParamTypeFromString(pchName: "float");
    dataDesc_6[30].fieldName = "m_fRange";
    dataDesc_6[30].fieldOffset = 264;
    *(_DWORD *)&dataDesc_6[30].fieldSize = 131073;
    dataDesc_6[30].externalName = nullptr;
    dataDesc_6[30].pSaveRestoreOps = nullptr;
    dataDesc_6[30].inputFunc = nullptr;
    dataDesc_6[30].fieldTolerance = 0.0;
    dataDesc_6[30].td = nullptr;
    dataDesc_6[30].fieldSizeInBytes = 4;
    dataDesc_6[30].override_field = nullptr;
    dataDesc_6[30].override_count = 0;
    *(_QWORD *)dataDesc_6[30].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[30].flatGroup = 0;
    v13 = LessonParamTypeFromString(pchName: "int");
    dataDesc_6[31].fieldTolerance = 0.0;
    dataDesc_6[31].fieldType = v13;
    dataDesc_6[31].fieldName = "m_iFlags";
    dataDesc_6[31].fieldOffset = 260;
    *(_QWORD *)dataDesc_6[31].flatOffset = 0;
    *(_QWORD *)&dataDesc_6[32].td = 0;
    *(_QWORD *)&dataDesc_6[32].override_field = 0;
    *(_QWORD *)&dataDesc_6[32].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[32].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_6[33].td = 0;
    *(_QWORD *)&dataDesc_6[33].override_field = 0;
    *(_QWORD *)&dataDesc_6[33].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[33].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_6[34].td = 0;
    *(_QWORD *)&dataDesc_6[34].override_field = 0;
    *(_QWORD *)&dataDesc_6[34].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[34].flatOffset[1] = 0;
    *(_DWORD *)&dataDesc_6[31].fieldSize = 131073;
    dataDesc_6[31].externalName = nullptr;
    dataDesc_6[31].pSaveRestoreOps = nullptr;
    dataDesc_6[31].inputFunc = nullptr;
    dataDesc_6[31].td = nullptr;
    dataDesc_6[31].fieldSizeInBytes = 4;
    dataDesc_6[31].override_field = nullptr;
    dataDesc_6[31].override_count = 0;
    *(_DWORD *)&dataDesc_6[31].flatGroup = 0;
    dataDesc_6[32].fieldType = FIELD_CUSTOM;
    dataDesc_6[32].fieldName = "m_szCaptionColor";
    dataDesc_6[32].fieldOffset = 284;
    *(_DWORD *)&dataDesc_6[32].fieldSize = 131073;
    dataDesc_6[32].externalName = nullptr;
    dataDesc_6[32].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[32].inputFunc = nullptr;
    dataDesc_6[33].fieldType = FIELD_CUSTOM;
    dataDesc_6[33].fieldName = "m_szLessonGroup";
    dataDesc_6[33].fieldOffset = 144;
    *(_DWORD *)&dataDesc_6[33].fieldSize = 131073;
    dataDesc_6[33].externalName = nullptr;
    dataDesc_6[33].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[33].inputFunc = nullptr;
    dataDesc_6[34].fieldType = FIELD_CUSTOM;
    dataDesc_6[34].fieldName = "m_szDisplayText";
    dataDesc_6[34].fieldOffset = 220;
    *(_DWORD *)&dataDesc_6[34].fieldSize = 131073;
    dataDesc_6[34].externalName = nullptr;
    dataDesc_6[34].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[34].inputFunc = nullptr;
    dataDesc_6[35].fieldType = FIELD_CUSTOM;
    dataDesc_6[35].fieldName = "m_szDisplayParamText";
    dataDesc_6[35].fieldOffset = 222;
    *(_DWORD *)&dataDesc_6[35].fieldSize = 131073;
    dataDesc_6[35].externalName = nullptr;
    dataDesc_6[35].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[35].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_6[35].td = 0;
    *(_QWORD *)&dataDesc_6[35].override_field = 0;
    *(_QWORD *)&dataDesc_6[35].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[35].flatOffset[1] = 0;
    dataDesc_6[36].fieldType = FIELD_CUSTOM;
    dataDesc_6[36].fieldName = "m_szBinding";
    dataDesc_6[36].fieldOffset = 224;
    *(_DWORD *)&dataDesc_6[36].fieldSize = 131073;
    dataDesc_6[36].externalName = nullptr;
    *(_QWORD *)&dataDesc_6[36].td = 0;
    *(_QWORD *)&dataDesc_6[36].override_field = 0;
    *(_QWORD *)&dataDesc_6[36].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[36].flatOffset[1] = 0;
    dataDesc_6[36].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[36].inputFunc = nullptr;
    dataDesc_6[37].fieldType = FIELD_CUSTOM;
    dataDesc_6[37].fieldName = "m_szGamepadBinding";
    dataDesc_6[37].fieldOffset = 226;
    *(_DWORD *)&dataDesc_6[37].fieldSize = 131073;
    dataDesc_6[37].externalName = nullptr;
    dataDesc_6[37].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[37].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_6[37].td = 0;
    *(_QWORD *)&dataDesc_6[37].override_field = 0;
    *(_QWORD *)&dataDesc_6[37].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[37].flatOffset[1] = 0;
    v14 = LessonParamTypeFromString(pchName: "int");
    dataDesc_6[38].fieldTolerance = 0.0;
    dataDesc_6[38].fieldType = v14;
    dataDesc_6[38].fieldName = "m_iPriority";
    dataDesc_6[38].fieldOffset = 68;
    *(_QWORD *)dataDesc_6[38].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[38].fieldSize = 131073;
    dataDesc_6[38].externalName = nullptr;
    dataDesc_6[38].pSaveRestoreOps = nullptr;
    dataDesc_6[38].inputFunc = nullptr;
    dataDesc_6[38].td = nullptr;
    dataDesc_6[38].fieldSizeInBytes = 4;
    dataDesc_6[38].override_field = nullptr;
    dataDesc_6[38].override_count = 0;
    *(_DWORD *)&dataDesc_6[38].flatGroup = 0;
    dataDesc_6[39].fieldType = FIELD_CUSTOM;
    dataDesc_6[39].fieldName = "m_stringReplaceKey";
    dataDesc_6[39].fieldOffset = 72;
    *(_DWORD *)&dataDesc_6[39].fieldSize = 131073;
    dataDesc_6[39].externalName = nullptr;
    dataDesc_6[39].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    dataDesc_6[39].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_6[39].td = 0;
    *(_QWORD *)&dataDesc_6[39].override_field = 0;
    *(_QWORD *)&dataDesc_6[39].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[39].flatOffset[1] = 0;
    v15 = LessonParamTypeFromString(pchName: "float");
    dataDesc_6[40].fieldTolerance = 0.0;
    dataDesc_6[40].fieldType = v15;
    dataDesc_6[40].fieldName = "m_fLockDuration";
    dataDesc_6[40].fieldOffset = 116;
    *(_DWORD *)&dataDesc_6[40].fieldSize = 131073;
    dataDesc_6[40].externalName = nullptr;
    dataDesc_6[40].pSaveRestoreOps = nullptr;
    dataDesc_6[40].inputFunc = nullptr;
    dataDesc_6[40].td = nullptr;
    dataDesc_6[40].fieldSizeInBytes = 4;
    dataDesc_6[40].override_field = nullptr;
    dataDesc_6[40].override_count = 0;
    *(_QWORD *)dataDesc_6[40].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[40].flatGroup = 0;
    dataDesc_6[41].fieldType = LessonParamTypeFromString(pchName: "bool");
    dataDesc_6[41].fieldName = "m_bCanOpenWhenDead";
    dataDesc_6[41].fieldOffset = 146;
    *(_DWORD *)&dataDesc_6[41].fieldSize = 131073;
    dataDesc_6[41].externalName = nullptr;
    dataDesc_6[41].pSaveRestoreOps = nullptr;
    dataDesc_6[41].inputFunc = nullptr;
    dataDesc_6[41].td = nullptr;
    dataDesc_6[41].fieldSizeInBytes = 1;
    dataDesc_6[41].override_field = nullptr;
    dataDesc_6[41].override_count = 0;
    dataDesc_6[41].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_6[41].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[41].flatGroup = 0;
    v16 = LessonParamTypeFromString(pchName: "bool");
    dataDesc_6[42].fieldTolerance = 0.0;
    dataDesc_6[42].fieldType = v16;
    dataDesc_6[42].fieldName = "m_bBumpWithTimeoutWhenLearned";
    dataDesc_6[42].fieldOffset = 147;
    *(_DWORD *)&dataDesc_6[42].fieldSize = 131073;
    dataDesc_6[42].externalName = nullptr;
    dataDesc_6[42].pSaveRestoreOps = nullptr;
    dataDesc_6[42].inputFunc = nullptr;
    dataDesc_6[42].td = nullptr;
    dataDesc_6[42].fieldSizeInBytes = 1;
    dataDesc_6[42].override_field = nullptr;
    dataDesc_6[42].override_count = 0;
    *(_QWORD *)dataDesc_6[42].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[42].flatGroup = 0;
    v17 = LessonParamTypeFromString(pchName: "bool");
    dataDesc_6[43].fieldTolerance = 0.0;
    dataDesc_6[43].fieldType = v17;
    dataDesc_6[43].fieldName = "m_bOnceLearnedNeverOpen";
    dataDesc_6[43].fieldOffset = 148;
    *(_DWORD *)&dataDesc_6[43].fieldSize = 131073;
    dataDesc_6[43].externalName = nullptr;
    dataDesc_6[43].pSaveRestoreOps = nullptr;
    dataDesc_6[43].inputFunc = nullptr;
    dataDesc_6[43].td = nullptr;
    dataDesc_6[43].fieldSizeInBytes = 1;
    dataDesc_6[43].override_field = nullptr;
    dataDesc_6[43].override_count = 0;
    *(_QWORD *)dataDesc_6[43].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[43].flatGroup = 0;
    v18 = LessonParamTypeFromString(pchName: "bool");
    dataDesc_6[44].fieldTolerance = 0.0;
    dataDesc_6[44].fieldType = v18;
    dataDesc_6[44].fieldName = "m_bCanTimeoutWhileInactive";
    dataDesc_6[44].fieldOffset = 149;
    *(_DWORD *)&dataDesc_6[44].fieldSize = 131073;
    dataDesc_6[44].externalName = nullptr;
    dataDesc_6[44].pSaveRestoreOps = nullptr;
    dataDesc_6[44].inputFunc = nullptr;
    dataDesc_6[44].td = nullptr;
    dataDesc_6[44].fieldSizeInBytes = 1;
    dataDesc_6[44].override_field = nullptr;
    dataDesc_6[44].override_count = 0;
    *(_QWORD *)dataDesc_6[44].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[44].flatGroup = 0;
    v19 = LessonParamTypeFromString(pchName: "bool");
    dataDesc_6[45].fieldTolerance = 0.0;
    dataDesc_6[45].fieldType = v19;
    dataDesc_6[45].fieldName = "m_bUsableInMidair";
    dataDesc_6[45].fieldOffset = 151;
    *(_DWORD *)&dataDesc_6[45].fieldSize = 131073;
    dataDesc_6[45].externalName = nullptr;
    dataDesc_6[45].pSaveRestoreOps = nullptr;
    dataDesc_6[45].inputFunc = nullptr;
    dataDesc_6[45].td = nullptr;
    dataDesc_6[45].fieldSizeInBytes = 1;
    dataDesc_6[45].override_field = nullptr;
    dataDesc_6[45].override_count = 0;
    *(_QWORD *)dataDesc_6[45].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[45].flatGroup = 0;
    dataDesc_6[46].fieldType = LessonParamTypeFromString(pchName: "float");
    dataDesc_6[46].fieldName = "m_fTimeout";
    dataDesc_6[46].fieldOffset = 120;
    dataDesc_6[46].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_6[46].fieldSize = 131073;
    dataDesc_6[46].externalName = nullptr;
    dataDesc_6[46].pSaveRestoreOps = nullptr;
    dataDesc_6[46].inputFunc = nullptr;
    dataDesc_6[46].td = nullptr;
    dataDesc_6[46].fieldSizeInBytes = 4;
    dataDesc_6[46].override_field = nullptr;
    dataDesc_6[46].override_count = 0;
    *(_QWORD *)dataDesc_6[46].flatOffset = 0;
    *(_DWORD *)&dataDesc_6[46].flatGroup = 0;
    v20 = LessonParamTypeFromString(pchName: "float");
    dataDesc_6[47].fieldTolerance = 0.0;
    dataDesc_6[47].fieldSizeInBytes = 4;
    dataDesc_6[48].pSaveRestoreOps = &s_GameInstructorSymbolSaveRestoreOps;
    *(_QWORD *)dataDesc_6[47].flatOffset = 0;
    dataDesc_6[47].fieldType = v20;
    dataDesc_6[47].fieldName = "m_fUpdateInterval";
    dataDesc_6[47].fieldOffset = 136;
    *(_DWORD *)&dataDesc_6[47].fieldSize = 131073;
    dataDesc_6[47].externalName = nullptr;
    dataDesc_6[47].pSaveRestoreOps = nullptr;
    dataDesc_6[47].inputFunc = nullptr;
    dataDesc_6[47].td = nullptr;
    dataDesc_6[47].override_field = nullptr;
    dataDesc_6[47].override_count = 0;
    *(_DWORD *)&dataDesc_6[47].flatGroup = 0;
    dataDesc_6[48].fieldType = FIELD_CUSTOM;
    dataDesc_6[48].fieldName = "m_szStartSound";
    dataDesc_6[48].fieldOffset = 142;
    *(_DWORD *)&dataDesc_6[48].fieldSize = 131073;
    dataDesc_6[48].externalName = nullptr;
    dataDesc_6[48].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_6[48].td = 0;
    *(_QWORD *)&dataDesc_6[48].override_field = 0;
    *(_QWORD *)&dataDesc_6[48].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_6[48].flatOffset[1] = 0;
  }
  CScriptedIconLesson::m_DataMap.dataNumFields = 48;
  CScriptedIconLesson::m_DataMap.dataDesc = &dataDesc_6[1];
  return &CScriptedIconLesson::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x104111A0
// Name: _dynamic_initializer_for__cl_customsounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_customsounds__()
{
  ConVar::ConVar(
    this: &cl_customsounds,
    pName: "cl_customsounds",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Enable customized player sound playback");
  return atexit(func: dynamic_atexit_destructor_for__cl_customsounds__);
}
