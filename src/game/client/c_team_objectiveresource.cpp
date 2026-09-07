// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_team_objectiveresource.cpp
// Functions: 15
// ============================================================

#include "game\client\c_team_objectiveresource.h"

//------------------------------------------------------------------------------
// Address: 0x10090FF0
// Name: public: virtual class ClientClass __near * C_BaseTeamObjectiveResource::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseTeamObjectiveResource::GetClientClass(C_BaseTeamObjectiveResource *this)
{
  return &__g_C_BaseTeamObjectiveResourceClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10091000
// Name: public: virtual void C_BaseTeamObjectiveResource::OnPreDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseTeamObjectiveResource::OnPreDataChanged(
        C_BaseTeamObjectiveResource *this,
        DataUpdateType_t updateType)
{
  int m_iTimerToShowInHUD; // eax
  int m_iPrevNumControlPoints; // ecx
  char v5; // dl

  C_BaseEntity::OnPreDataChanged(this, type: updateType);
  m_iTimerToShowInHUD = this->m_iTimerToShowInHUD;
  m_iPrevNumControlPoints = this->m_iPrevNumControlPoints;
  v5 = BYTE1(this->m_iNumControlPoints);
  this->m_iStopWatchTimer = m_iTimerToShowInHUD;
  *(_DWORD *)&this->m_bPlayingMiniRounds = m_iPrevNumControlPoints;
  BYTE2(this->m_iNumControlPoints) = v5;
  memcpy(
    dst: (unsigned __int8 *)&this->m_flLazyCapPerc[6],
    src: (unsigned __int8 *)this->m_bCPIsVisible,
    count: 4 * m_iTimerToShowInHUD);
}

//------------------------------------------------------------------------------
// Address: 0x10091060
// Name: public: void C_BaseTeamObjectiveResource::SetOwningTeam(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseTeamObjectiveResource::SetOwningTeam(C_BaseTeamObjectiveResource *this, int index, int team)
{
  IGameEvent *v3; // edi

  if ( team == this->m_iCappingTeam[index] )
  {
    this->m_iCappingTeam[index] = 0;
    this->m_flCapTimeLeft[index] = 0.0;
    this->m_flCapLastThinkTime[index] = 0.0;
  }
  this->m_iOwner[index] = team;
  v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "controlpoint_updateowner", a3: 0, a4: 0);
  if ( v3 != nullptr )
  {
    v3->SetInt(this: v3, a2: "index", a3: index);
    gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100910E0
// Name: public: virtual void C_BaseTeamObjectiveResource::SetCappingTeam(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseTeamObjectiveResource::SetCappingTeam(C_BaseTeamObjectiveResource *this, int index, int team)
{
  int v3; // edx
  IGameEvent *v4; // edi

  if ( index < this->m_iNumControlPoints )
    v3 = this->m_iOwner[index];
  else
    v3 = 0;
  if ( team == v3 || team <= 1 )
    this->m_flCapTimeLeft[index] = 0.0;
  else
    this->m_flCapTimeLeft[index] = this->m_flTeamCapTime[8 * team + index];
  this->m_iCappingTeam[index] = team;
  this->m_bWarnedOnFinalCap[index] = false;
  this->m_flCapLastThinkTime[index] = *(float *)(gpGlobals.m_Index + 12);
  ((void (__thiscall *)(C_BaseTeamObjectiveResource *, _DWORD))this->SetNextClientThink)(
    a1: this,
    a2: *(float *)(gpGlobals.m_Index + 12) + 0.1);
  v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "controlpoint_updatecapping", a3: 0, a4: 0);
  if ( v4 != nullptr )
  {
    v4->SetInt(this: v4, a2: "index", a3: index);
    gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100911B0
// Name: void RecvProxy_Owner(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Owner(const CRecvProxyData *pData)
{
  C_BaseTeamObjectiveResource::SetOwningTeam(
    this: g_pObjectiveResource,
    index: (unsigned int)pData->m_pRecvProp->m_Offset >> 2,
    team: pData->m_Value.m_Int);
}

//------------------------------------------------------------------------------
// Address: 0x100911D0
// Name: void RecvProxy_CappingTeam(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_CappingTeam(const CRecvProxyData *pData)
{
  g_pObjectiveResource->SetCappingTeam(
    this: g_pObjectiveResource,
    a2: (unsigned int)pData->m_pRecvProp->m_Offset >> 2,
    a3: pData->m_Value.m_Int);
}

//------------------------------------------------------------------------------
// Address: 0x10091200
// Name: void RecvProxy_CapLayout(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_CapLayout(const CRecvProxyData *pData)
{
  IGameEvent *v1; // esi

  V_strncpy(pDest: g_pObjectiveResource->m_pszCapLayoutInHUD, pSrc: pData->m_Value.m_pString, maxLen: 32);
  v1 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "controlpoint_updatelayout", a3: 0, a4: 0);
  if ( v1 != nullptr )
  {
    v1->SetInt(this: v1, a2: "index", a3: -1);
    gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100918E0
// Name: public: C_BaseTeamObjectiveResource::C_BaseTeamObjectiveResource(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseTeamObjectiveResource *__thiscall C_BaseTeamObjectiveResource::C_BaseTeamObjectiveResource(
        C_BaseTeamObjectiveResource *this)
{
  float *m_flCapLastThinkTime; // esi
  int *v3; // ecx
  float *v4; // eax
  int j; // [esp+Ch] [ebp-10h]
  int *m_iPreviousPoints; // [esp+10h] [ebp-Ch]
  char *v8; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseTeamObjectiveResource_vtbl *)&C_BaseTeamObjectiveResource::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseTeamObjectiveResource::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseTeamObjectiveResource::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseTeamObjectiveResource::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseTeamObjectiveResource::`vftable';
  this->m_iNumControlPoints = 0;
  this->m_iPrevNumControlPoints = 0;
  this->m_pszCapLayoutInHUD[0] = 0;
  this->m_iUpdateCapHudParity = 0;
  this->m_bControlPointsReset = false;
  i = 0;
  m_iPreviousPoints = this->m_iPreviousPoints;
  v8 = this->m_iszWarnSound[0];
  m_flCapLastThinkTime = this->m_flCapLastThinkTime;
  do
  {
    v3 = m_iPreviousPoints;
    *(m_flCapLastThinkTime - 8) = 0.0;
    *m_flCapLastThinkTime = 0.0;
    m_flCapLastThinkTime[10] = 0.0;
    this->m_bWarnedOnFinalCap[i] = false;
    *(m_flCapLastThinkTime - 624) = 0.0;
    *v8 = 0;
    *(m_flCapLastThinkTime - 1170) = 0.0;
    v4 = m_flCapLastThinkTime - 1090;
    for ( j = 8; j != 0; --j )
    {
      *(v4 - 64) = 0.0;
      *v4 = 0.0;
      v4[64] = 0.0;
      v4[128] = 0.0;
      v4[992] = 0.0;
      *v3 = -1;
      v3[1] = -1;
      v3[2] = -1;
      v3 += 24;
      v4 += 8;
    }
    v8 += 255;
    m_iPreviousPoints += 3;
    ++m_flCapLastThinkTime;
    ++i;
  }
  while ( i < 8 );
  this->m_iTeamBaseIcons[0] = 0;
  this->m_iTeamBaseIcons[1] = 0;
  this->m_iTeamBaseIcons[2] = 0;
  this->m_iTeamBaseIcons[3] = 0;
  this->m_iTeamBaseIcons[4] = 0;
  this->m_iTeamBaseIcons[5] = 0;
  this->m_iTeamBaseIcons[6] = 0;
  this->m_iTeamBaseIcons[7] = 0;
  g_pObjectiveResource = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10091A70
// Name: public: virtual void C_BaseTeamObjectiveResource::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseTeamObjectiveResource::OnDataChanged(
        C_BaseTeamObjectiveResource *this,
        DataUpdateType_t updateType)
{
  IGameEvent *v3; // eax
  IGameEvent *v4; // eax
  IGameEvent *v5; // edi
  int v6; // edx
  bool *m_bCPIsVisible; // ecx

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( BYTE2(this->m_iNumControlPoints) != BYTE1(this->m_iNumControlPoints)
    || this->m_iTimerToShowInHUD != this->m_iStopWatchTimer )
  {
    v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "controlpoint_initialized", a3: 0, a4: 0);
    if ( v3 != nullptr )
      gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v3);
  }
  if ( this->m_iPrevNumControlPoints != *(_DWORD *)&this->m_bPlayingMiniRounds )
  {
    v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "controlpoint_updateimages", a3: 0, a4: 0);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v4->SetInt(this: v4, a2: "index", a3: -1);
      gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v5);
    }
  }
  v6 = 0;
  if ( this->m_iTimerToShowInHUD > 0 )
  {
    m_bCPIsVisible = this->m_bCPIsVisible;
    do
    {
      if ( *((float *)m_bCPIsVisible + 8) != *(float *)m_bCPIsVisible )
        *((float *)m_bCPIsVisible + 1162) = *(float *)&this->m_iTeamReqCappers[8 * *((_DWORD *)m_bCPIsVisible + 1136)
                                                                             + 62
                                                                             + v6]
                                          * *(float *)m_bCPIsVisible;
      ++v6;
      m_bCPIsVisible += 4;
    }
    while ( v6 < this->m_iTimerToShowInHUD );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091B70
// Name: public: virtual void C_BaseTeamObjectiveResource::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseTeamObjectiveResource::ClientThink(C_BaseTeamObjectiveResource *this)
{
  int v2; // ebx
  int v3; // ecx
  float *v4; // esi
  float v5; // xmm3_4
  int j; // eax
  int v7; // ecx
  int v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // edx
  unsigned int v12; // ecx
  int v13; // eax
  float v14; // xmm5_4
  float v15; // xmm4_4
  int v16; // ecx
  C_BasePlayer *LocalPlayer; // eax
  float v18; // xmm0_4
  float v19; // xmm0_4
  IGameEvent *v20; // eax
  C_BasePlayer *pPlayer; // [esp+2Ch] [ebp-14h]
  C_BasePlayer *pPlayera; // [esp+2Ch] [ebp-14h]
  C_BasePlayer *pPlayerb; // [esp+2Ch] [ebp-14h]
  int i; // [esp+30h] [ebp-10h]
  char *soundname; // [esp+38h] [ebp-8h]

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  soundname = (char *)&this->m_iWarnOnCap[5];
  v2 = 0;
  v3 = -60 - (_DWORD)this;
  i = 0;
  v4 = (float *)&this->m_iOwner[5];
  do
  {
    v5 = *v4;
    if ( *v4 == 0.0 )
      goto LABEL_44;
    if ( *((_BYTE *)&this->m_iTeamInZone[5] + v2) == 0 )
    {
      j = *((_DWORD *)&this->m_bIsBlurred + 1);
      if ( v2 < j )
        v7 = *(_DWORD *)((char *)v4 + (_DWORD)this + v3 - 12);
      else
        v7 = 0;
      v8 = LODWORD(this->m_flPathDistance[8 * v7 + 5 + v2]);
      pPlayer = (C_BasePlayer *)v8;
      if ( v8 <= 0 )
      {
LABEL_33:
        if ( g_pGameRules != nullptr
          && ((unsigned __int8 (__thiscall *)(C_GameRules *, _DWORD, int))g_pGameRules->__vftable[1].Init)(
               a1: g_pGameRules,
               a2: *((_DWORD *)v4 - 26),
               a3: v2) != 0 )
        {
          v18 = (float)(*(float *)&this->m_iTeamReqCappers[8 * *((_DWORD *)v4 - 26) + 61 + v2]
                      / mp_capdeteriorate_time.m_pParent->m_Value.m_fValue)
              * (float)(*(float *)(gpGlobals.m_Index + 12) - v4[8]);
          if ( g_pGameRules != nullptr && LOBYTE(g_pGameRules[3].m_pszName) != 0 )
            v18 = v18 * 6.0;
          v19 = v18 + *v4;
        }
        else
        {
          v19 = 0.0;
        }
        *v4 = v19;
        *((_BYTE *)&this->m_flCapLastThinkTime[5] + v2) = 0;
        goto LABEL_41;
      }
      v9 = *(float *)(gpGlobals.m_Index + 12) - v4[8];
      v10 = v9;
      if ( mp_capstyle.m_pParent != nullptr && mp_capstyle.m_pParent->m_Value.m_nValue == 1 )
      {
        v11 = 1;
        if ( v8 > 1 )
        {
          if ( v8 - 1 >= 4 )
          {
            v12 = ((unsigned int)(v8 - 5) >> 2) + 1;
            v13 = 3;
            v11 = 4 * v12 + 1;
            do
            {
              v14 = (float)((float)((float)(v9 / (float)(v13 - 1)) + v10) + (float)(v9 / (float)v13))
                  + (float)(v9 / (float)(v13 + 1));
              v15 = v9 / (float)(v13 + 2);
              v13 += 4;
              --v12;
              v10 = v14 + v15;
            }
            while ( v12 != 0 );
            v8 = (int)pPlayer;
            v2 = i;
          }
          for ( j = *((_DWORD *)&this->m_bIsBlurred + 1);
                v11 < v8;
                v10 = v10 + (float)((float)(*(float *)(gpGlobals.m_Index + 12) - v4[8]) / (float)v11) )
          {
            ++v11;
          }
        }
      }
      if ( v2 < j )
        v16 = *((_DWORD *)v4 - 18);
      else
        v16 = 0;
      if ( v16 == *((_DWORD *)v4 - 26) )
      {
        *v4 = v5 - v10;
        if ( *((_BYTE *)&this->m_flCapLastThinkTime[5] + v2) == 0 )
        {
          LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
          pPlayera = LocalPlayer;
          if ( LocalPlayer != nullptr
            && *((_DWORD *)v4 - 26) != 0
            && LocalPlayer->GetTeamNumber(this: LocalPlayer) != *((_DWORD *)v4 - 26)
            && *((_DWORD *)v4 - 616) == 1
            && *(float *)(gpGlobals.m_Index + 12) > (float)(v4[18] + 5.0) )
          {
            C_BaseEntity::EmitSound(this: pPlayera, soundname, soundtime: 0, duration: nullptr);
            *((_BYTE *)&this->m_flCapLastThinkTime[5] + v2) = 1;
            v4[18] = *(float *)(gpGlobals.m_Index + 12);
          }
        }
      }
      else
      {
        if ( v2 >= j || *((_DWORD *)v4 - 8) != 0 || v2 >= j || *((_DWORD *)v4 - 18) == 0 )
          goto LABEL_33;
        *v4 = v5 + v10;
      }
    }
LABEL_41:
    v20 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "controlpoint_updatelayout", a3: 0, a4: 0);
    pPlayerb = (C_BasePlayer *)v20;
    if ( v20 != nullptr )
    {
      v20->SetInt(this: v20, a2: "index", a3: v2);
      gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: (IGameEvent *)pPlayerb);
    }
    v3 = -60 - (_DWORD)this;
    v4[8] = *(float *)(gpGlobals.m_Index + 12);
LABEL_44:
    soundname += 255;
    ++v2;
    ++v4;
    i = v2;
  }
  while ( v2 < 8 );
  (*(void (__stdcall **)(_DWORD))(*((_DWORD *)this - 3) + 456))(a1: *(float *)(gpGlobals.m_Index + 12) + 0.1);
}

//------------------------------------------------------------------------------
// Address: 0x10413C70
// Name: DT_BaseTeamObjectiveResource::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseTeamObjectiveResource::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseTeamObjectiveResource::g_RecvTable);
  return atexit(func: DT_BaseTeamObjectiveResource::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413C90
// Name: DT_BaseTeamObjectiveResource::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseTeamObjectiveResource::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseTeamObjectiveResource::ignored>();
  DT_BaseTeamObjectiveResource::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430C60
// Name: DT_BaseTeamObjectiveResource::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseTeamObjectiveResource::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseTeamObjectiveResource::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10091EE0
// Name: _C_BaseTeamObjectiveResource_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseTeamObjectiveResource_CreateObject(int entnum, int serialNum)
{
  C_BaseTeamObjectiveResource *v2; // eax
  C_BaseTeamObjectiveResource *v3; // eax
  C_BaseTeamObjectiveResource *v4; // esi

  v2 = (C_BaseTeamObjectiveResource *)C_BaseEntity::operator new(stAllocateBlock: 0x1CB8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BaseTeamObjectiveResource::C_BaseTeamObjectiveResource(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10413CA0
// Name: _dynamic_initializer_for____g_C_TeslaClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TeslaClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TeslaClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TeslaClientClass;
  return result;
}
