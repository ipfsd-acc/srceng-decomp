// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_baseplayer.cpp
// Functions: 144
// ============================================================

#include "game\client\c_baseplayer.h"

//------------------------------------------------------------------------------
// Address: 0x10057FC0
// Name: public: void CFlashlightEffectManager::TurnOnFlashlight(int,char const __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashlightEffectManager::TurnOnFlashlight(
        CFlashlightEffectManager *this,
        int nEntIndex,
        const char *pszTextureName,
        float flFov,
        float flFarZ,
        float flLinearAtten)
{
  bool v7; // zf
  CFlashlightEffect *m_pFlashlightEffect; // ecx
  CFlashlightEffect *v9; // eax
  CFlashlightEffect *v10; // eax

  v7 = !this->m_bFlashlightOverride;
  this->m_flFov = flFov;
  this->m_flFarZ = flFarZ;
  this->m_pFlashlightTextureName = pszTextureName;
  this->m_nFlashlightEntIndex = nEntIndex;
  this->m_flLinearAtten = flLinearAtten;
  this->m_bFlashlightOn = true;
  if ( v7 )
  {
    m_pFlashlightEffect = this->m_pFlashlightEffect;
    if ( this->m_pFlashlightEffect != nullptr
      || ((v9 = (CFlashlightEffect *)MemAlloc_Alloc(nSize: 0x6Cu), pszTextureName == nullptr)
        ? (v9 == nullptr
         ? (v10 = nullptr)
         : (v10 = CFlashlightEffect::CFlashlightEffect(
                    this: v9,
                    nEntIndex: this->m_nFlashlightEntIndex,
                    pszTextureName: nullptr,
                    flFov: 0.0,
                    flFarZ: 0.0,
                    flLinearAtten: 0.0)))
        : v9 == nullptr
        ? (v10 = nullptr)
        : (v10 = CFlashlightEffect::CFlashlightEffect(
                   this: v9,
                   nEntIndex: this->m_nFlashlightEntIndex,
                   pszTextureName,
                   flFov,
                   flFarZ,
                   flLinearAtten)),
          m_pFlashlightEffect = v10,
          this->m_pFlashlightEffect = v10,
          v10 != nullptr) )
    {
      CFlashlightEffect::TurnOn(this: m_pFlashlightEffect);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058090
// Name: class Vector RandomVector(float,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
Vector *__cdecl RandomVector(Vector *result, float minVal, float maxVal)
{
  IUniformRandomStream *v3; // ecx
  IUniformRandomStream *v4; // ecx
  IUniformRandomStream *v5; // ecx

  result->x = _RandomFloat(this: v3, a2: minVal, a3: maxVal);
  result->y = _RandomFloat(this: v4, a2: minVal, a3: maxVal);
  result->z = _RandomFloat(this: v5, a2: minVal, a3: maxVal);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10058160
// Name: public: virtual class ClientClass __near * C_BasePlayer::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BasePlayer::GetClientClass(C_BasePlayer *this)
{
  return &__g_C_BasePlayerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10058170
// Name: public: virtual struct datamap_t __near * CPlayerState::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPlayerState::GetPredDescMap(CPlayerState *this)
{
  return &CPlayerState::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10058180
// Name: public: virtual struct datamap_t __near * CPlayerLocalData::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPlayerLocalData::GetPredDescMap(CPlayerLocalData *this)
{
  return &CPlayerLocalData::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10058190
// Name: public: virtual struct datamap_t __near * C_BasePlayer::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BasePlayer::GetPredDescMap(C_BasePlayer *this)
{
  return &C_BasePlayer::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x100581A0
// Name: public: bool C_BasePlayer::IsBot(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BasePlayer::IsBot(C_BasePlayer *this)
{
  IGameResources *v2; // esi
  IGameResources_vtbl *v3; // edi
  int v4; // eax
  BOOL result; // eax

  v2 = GameResources();
  result = false;
  if ( v2 != nullptr )
  {
    v3 = v2->__vftable;
    v4 = this->entindex(this: &this->IClientNetworkable);
    if ( v3->IsFakePlayer(this: v2, a2: v4) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100581E0
// Name: protected: virtual void C_BasePlayer::SetLocalViewAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SetLocalViewAngles(C_BasePlayer *this, const QAngle *viewAngles)
{
  this->pl.v_angle = *viewAngles;
}

//------------------------------------------------------------------------------
// Address: 0x10058210
// Name: protected: virtual void C_BasePlayer::SetViewAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SetViewAngles(C_BasePlayer *this, const QAngle *ang)
{
  C_BaseEntity::SetLocalAngles(this, angles: ang);
  C_BaseEntity::SetNetworkAngles(this, ang);
}

//------------------------------------------------------------------------------
// Address: 0x10058230
// Name: public: char const __near * C_BasePlayer::GetPlayerName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_BasePlayer::GetPlayerName(C_BasePlayer *this)
{
  IGameResources_vtbl *v1; // esi
  int v2; // eax

  if ( g_PR == nullptr )
    return prType;
  v1 = g_PR->IGameResources::__vftable;
  v2 = this->entindex(this: &this->IClientNetworkable);
  return v1->GetPlayerName(this: &g_PR->IGameResources, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10058270
// Name: public: virtual void C_BasePlayer::PreDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::PreDataUpdate(C_BasePlayer *this, DataUpdateType_t updateType)
{
  C_BaseAnimating::PreDataUpdate(this, updateType);
  this->m_bSentFreezeFrame = this->m_chTextureType;
}

//------------------------------------------------------------------------------
// Address: 0x10058290
// Name: public: virtual bool C_BasePlayer::CanSetSoundMixer(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::CanSetSoundMixer(C_BasePlayer *this)
{
  return this->GetObserverMode(this) != 2;
}

//------------------------------------------------------------------------------
// Address: 0x100582B0
// Name: protected: virtual float C_BasePlayer::GetDeathCamInterpolationTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BasePlayer::GetDeathCamInterpolationTime(C_BasePlayer *this)
{
  return 3.0;
}

//------------------------------------------------------------------------------
// Address: 0x100582C0
// Name: public: static class C_BasePlayer __near * C_BasePlayer::GetLocalPlayer(int)
// Source: json
//------------------------------------------------------------------------------
C_BasePlayer *__cdecl C_BasePlayer::GetLocalPlayer(int nSlot)
{
  if ( nSlot == -1 )
    return s_pLocalPlayer[0];
  else
    return s_pLocalPlayer[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x100582E0
// Name: public: static void C_BasePlayer::SetRemoteSplitScreenPlayerViewsAreLocalPlayer(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BasePlayer::SetRemoteSplitScreenPlayerViewsAreLocalPlayer(bool bSet)
{
  if ( !IsLocalSplitScreenPlayer(nSlot: 0) )
  {
    if ( bSet )
      s_pLocalPlayer[0] = GetSplitScreenViewPlayer(nSlot: 0);
    else
      s_pLocalPlayer[0] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058310
// Name: public: static bool C_BasePlayer::HasAnyLocalPlayer(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl C_BasePlayer::HasAnyLocalPlayer()
{
  int v0; // eax

  v0 = 0;
  while ( s_pLocalPlayer[v0] == nullptr )
  {
    if ( ++v0 != 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10058330
// Name: public: virtual void C_BasePlayer::ThirdPersonSwitch(bool)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall C_BasePlayer::ThirdPersonSwitch(C_BasePlayer *this, bool bThirdperson)
{
  C_BaseEntity::UpdateVisibility(this);
}

//------------------------------------------------------------------------------
// Address: 0x10058340
// Name: public: bool C_BasePlayer::ShouldDrawLocalPlayer(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BasePlayer::ShouldDrawLocalPlayer(C_BasePlayer *this)
{
  return input->CAM_IsThirdPerson(this: input, a2: -1) != 0 || ToolsEnabled() && ToolFramework_IsThirdPersonCamera();
}

//------------------------------------------------------------------------------
// Address: 0x10058380
// Name: public: static bool C_BasePlayer::IsLocalPlayer(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl C_BasePlayer::IsLocalPlayer(C_BaseEntity *pEntity)
{
  if ( pEntity != nullptr && pEntity->IsPlayer(this: pEntity) )
    return (bool)pEntity[2].m_pIntermediateData[71];
  else
    return false;
}

//------------------------------------------------------------------------------
// Address: 0x100583B0
// Name: public: int C_BasePlayer::GetUserID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BasePlayer::GetUserID(C_BasePlayer *this)
{
  IVEngineClient_vtbl *v1; // esi
  int v2; // eax
  player_info_s pi; // [esp+4h] [ebp-90h] BYREF

  v1 = engine->__vftable;
  v2 = ((int (__thiscall *)(IClientNetworkable *, player_info_s *))this->entindex)(
         a1: &this->IClientNetworkable,
         a2: &pi);
  if ( ((unsigned __int8 (__thiscall *)(IVEngineClient *, int))v1->GetPlayerInfo)(a1: engine, a2: v2) != 0 )
    return pi.userID;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10058400
// Name: public: void C_BasePlayer::ResetAutoaim(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::ResetAutoaim(C_BasePlayer *this)
{
  this->m_fOnTarget = false;
}

//------------------------------------------------------------------------------
// Address: 0x10058410
// Name: public: virtual bool C_BasePlayer::ShouldPredict(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::ShouldPredict(C_BasePlayer *this)
{
  return this != nullptr && this->IsPlayer(this) && this->m_bIsLocalPlayer;
}

//------------------------------------------------------------------------------
// Address: 0x10058440
// Name: public: float C_BasePlayer::GetWaterJumpTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BasePlayer::GetWaterJumpTime(C_BasePlayer *this)
{
  return this->m_flWaterJumpTime;
}

//------------------------------------------------------------------------------
// Address: 0x10058450
// Name: public: virtual class C_BaseEntity __near * C_BasePlayer::GetPotentialUseEntity(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BasePlayer::GetPotentialUseEntity(C_BasePlayer *this)
{
  return this->GetUseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10058460
// Name: public: static void C_BasePlayer::RecvProxy_LocalOriginXY(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BasePlayer::RecvProxy_LocalOriginXY(const CRecvProxyData *pData, void *pStruct, __int64 *pOut)
{
  *pOut = pData->m_Value.m_Int64;
}

//------------------------------------------------------------------------------
// Address: 0x10058480
// Name: public: static void C_BasePlayer::RecvProxy_NonLocalCellOriginXY(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BasePlayer::RecvProxy_NonLocalCellOriginXY(const CRecvProxyData *pData, char *pStruct, float *pOut)
{
  int v3; // edx
  int v4; // esi

  v3 = *((_DWORD *)pStruct + 29);
  v4 = *((_DWORD *)pStruct + 30);
  *(_QWORD *)(pStruct + 132) = pData->m_Value.m_Int64;
  *pOut = (float)(v3 * v4 - 0x4000) + pData->m_Value.m_Float;
  pOut[1] = (float)(v3 * *((_DWORD *)pStruct + 31) - 0x4000) + pData->m_Value.m_Vector[1];
}

//------------------------------------------------------------------------------
// Address: 0x100584E0
// Name: public: static void C_BasePlayer::RecvProxy_NonLocalCellOriginZ(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BasePlayer::RecvProxy_NonLocalCellOriginZ(const CRecvProxyData *pData, float *pStruct, float *pOut)
{
  int v3; // edx

  v3 = *((_DWORD *)pStruct + 29) * *((_DWORD *)pStruct + 32) - 0x4000;
  pStruct[35] = pData->m_Value.m_Float;
  *pOut = (float)v3 + pData->m_Value.m_Float;
}

//------------------------------------------------------------------------------
// Address: 0x10058520
// Name: public: virtual float C_BasePlayer::GetMinFOV(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BasePlayer::GetMinFOV(C_BasePlayer *this)
{
  if ( *(_DWORD *)(gpGlobals.m_Index + 20) == 1 )
    return 5.0;
  else
    return 75.0;
}

//------------------------------------------------------------------------------
// Address: 0x10058540
// Name: public: float C_BasePlayer::GetFinalPredictedTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BasePlayer::GetFinalPredictedTime(C_BasePlayer *this)
{
  return (double)this->m_nFinalPredictedTick * *(float *)(gpGlobals.m_Index + 28);
}

//------------------------------------------------------------------------------
// Address: 0x10058550
// Name: public: float C_BasePlayer::PredictedServerTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BasePlayer::PredictedServerTime(C_BasePlayer *this)
{
  return (double)(this->m_nTickBase - this->m_nLastUpdateTickBase) * *(float *)(gpGlobals.m_Index + 28)
       + this->m_fLastUpdateServerTime;
}

//------------------------------------------------------------------------------
// Address: 0x10058580
// Name: public: virtual class IRagdoll __near * C_BasePlayer::GetRepresentativeRagdoll(void)const
// Source: json
//------------------------------------------------------------------------------
CRagdoll *__thiscall C_BasePlayer::GetRepresentativeRagdoll(C_BasePlayer *this)
{
  return this->m_pRagdoll;
}

//------------------------------------------------------------------------------
// Address: 0x10058590
// Name: public: virtual class IMaterial __near * C_BasePlayer::GetHeadLabelMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall C_BasePlayer::GetHeadLabelMaterial(C_BasePlayer *this)
{
  IMaterial *result; // eax

  result = (IMaterial *)GetClientVoiceMgr();
  if ( result != nullptr )
    return GetClientVoiceMgr()->m_pHeadLabelMaterial;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100585B0
// Name: public: int C_BasePlayer::GetSplitScreenPlayerSlot(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BasePlayer::GetSplitScreenPlayerSlot(C_BasePlayer *this)
{
  return this->m_nSplitScreenSlot;
}

//------------------------------------------------------------------------------
// Address: 0x100585C0
// Name: public: bool C_BasePlayer::IsSplitScreenPlayer(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BasePlayer::IsSplitScreenPlayer(C_BasePlayer *this)
{
  return this->m_nSplitScreenSlot >= 1;
}

//------------------------------------------------------------------------------
// Address: 0x100585D0
// Name: public: virtual bool C_BasePlayer::ShouldRegenerateOriginFromCellBits(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::ShouldRegenerateOriginFromCellBits(C_BasePlayer *this)
{
  return (this == nullptr || !this->IsPlayer(this) || !this->m_bIsLocalPlayer)
      && g_pGameRules->IsMultiplayer(this: g_pGameRules)
      && CMoveHelperClient::PlayerFallingDamage((vgui::PropertySheet *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10058640
// Name: float SimpleSplineRemapValClamped(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SimpleSplineRemapValClamped(float val, float A, float B, float C, float D)
{
  float v6; // xmm0_4
  int v7; // xmm1_4
  float Aa; // [esp+Ch] [ebp+Ch]

  if ( A == B )
  {
    if ( val < B )
      return C;
    else
      return D;
  }
  else
  {
    v6 = (float)(val - A) / (float)(B - A);
    v7 = 0;
    if ( v6 < 0.0 || (v7 = 1065353216, v6 > 1.0) )
      Aa = *(float *)&v7;
    else
      Aa = (float)(val - A) / (float)(B - A);
    return C + (D - C) * (3.0 * (Aa * Aa) - Aa * (Aa * Aa + Aa * Aa));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100586E0
// Name: public: virtual void C_BasePlayer::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::Spawn(C_BasePlayer *this)
{
  const char *(__thiscall *GetPlayerModelName)(C_BasePlayer *); // eax
  const char *v3; // eax
  __int128 v4; // [esp-10h] [ebp-30h]
  _QWORD v5[2]; // [esp+10h] [ebp-10h] BYREF

  C_BaseEntity::ClearFlags(this);
  C_BaseEntity::AddFlag(this, flags: 256);
  C_BaseEntity::SetEffects(this, nEffects: this->m_fEffects & 0x10);
  GetPlayerModelName = this->GetPlayerModelName;
  this->m_iFOV = 0;
  v3 = GetPlayerModelName(this);
  C_BaseEntity::SetModel(this, pModelName: v3);
  this->Precache(this);
  v5[0] = 0;
  *(_QWORD *)&v4 = 0;
  v5[1] = 0xFFFFFFFF00000000uLL;
  *((_QWORD *)&v4 + 1) = 0xFFFFFFFF00000000uLL;
  C_BaseEntity::ThinkSet(this, a2: v5, func: v4, thinkTime: 0.0, szContext: nullptr);
  this->SharedSpawn(this);
  this->m_bWasFreezeFraming = false;
  this->m_bFiredWeapon = false;
}

//------------------------------------------------------------------------------
// Address: 0x10058790
// Name: public: bool C_BasePlayer::AudioStateIsUnderwater(class Vector)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::AudioStateIsUnderwater(C_BasePlayer *this, Vector vecMainViewOrigin)
{
  if ( this->GetObserverMode(this) != 0 )
    return (enginetrace->GetPointContents_WorldOnly(this: enginetrace, a2: &vecMainViewOrigin, a3: 16432) & 0x4030) != 0;
  else
    return this->m_nWaterLevel >= 3u;
}

//------------------------------------------------------------------------------
// Address: 0x100587E0
// Name: public: virtual class C_BaseEntity __near * C_BasePlayer::GetObserverTarget(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BasePlayer::GetObserverTarget(C_BasePlayer *this)
{
  C_HLTVCamera *v2; // eax
  unsigned int m_Index; // ecx

  if ( this->m_bIsLocalPlayer && g_bEngineIsHLTV )
  {
    v2 = HLTVCamera();
    return C_HLTVCamera::GetPrimaryTarget(this: v2);
  }
  else
  {
    if ( this->GetObserverMode(this) == 6 )
      return nullptr;
    m_Index = this->m_hObserverTarget.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      return nullptr;
    else
      return (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058840
// Name: public: virtual int C_BasePlayer::GetObserverMode(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BasePlayer::GetObserverMode(C_BasePlayer *this)
{
  C_HLTVCamera *v1; // eax

  if ( !this->m_bIsLocalPlayer || !g_bEngineIsHLTV )
    return this->m_iObserverMode;
  v1 = HLTVCamera();
  return C_HLTVCamera::GetMode(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10058870
// Name: public: bool C_BasePlayer::IsPlayerDead(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BasePlayer::IsPlayerDead(C_BasePlayer *this)
{
  return this->pl.deadflag.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10058880
// Name: public: virtual void C_BasePlayer::OnPreDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::OnPreDataChanged(C_BasePlayer *this, DataUpdateType_t updateType)
{
  int v2; // esi
  C_BaseCombatCharacter *v3; // ebx
  float *p_m_flVehicleViewFOV; // edi
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // ecx

  v2 = 0;
  v3 = (C_BasePlayer *)((char *)this - 8);
  p_m_flVehicleViewFOV = &this->m_flVehicleViewFOV;
  do
    *(_DWORD *)p_m_flVehicleViewFOV++ = C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v2++);
  while ( v2 < 32 );
  LOBYTE(this->m_flFreezeFrameStartTime) = v3->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].YouForgotToImplementOrDeclareClientClass(this: v3) == 2;
  m_Index = this->m_hColorCorrectionCtrl.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
    *(_DWORD *)&this->m_CurrentFog.enable.m_Value = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
  else
    *(_DWORD *)&this->m_CurrentFog.enable.m_Value = -1;
  C_BaseAnimating::OnPreDataChanged(this, updateType);
}

//------------------------------------------------------------------------------
// Address: 0x10058940
// Name: public: virtual void C_BasePlayer::ReceiveMessage(int,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::ReceiveMessage(C_BasePlayer *this, int classID, bf_read *msg)
{
  C_BasePlayer *v3; // edi
  int m_nBitsAvail; // ecx
  unsigned int v5; // edx
  int v6; // esi
  int v7; // ecx
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  unsigned int v10; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v13; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx

  v3 = this;
  if ( classID != *(_DWORD *)(((int (__fastcall *)(C_BasePlayer *))this->GetRefEHandle)(a1: this) + 20) )
  {
    C_BaseEntity::ReceiveMessage(this: v3, classID, msg);
    return;
  }
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v13 = 8 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
LABEL_17:
        if ( msg->m_bOverflow )
        {
          v6 = 0;
        }
        else
        {
          v15 = msg->m_nInBufWord;
          v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << msg->m_nBitsAvail;
          msg->m_nBitsAvail = 32 - v13;
          msg->m_nInBufWord = v15 >> v13;
          v6 = v16 | m_nInBufWord;
        }
        v3 = this;
        goto LABEL_21;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
    goto LABEL_17;
  }
  v5 = msg->m_nInBufWord;
  v6 = (unsigned __int8)v5;
  v7 = m_nBitsAvail - 8;
  msg->m_nBitsAvail = v7;
  if ( v7 != 0 )
  {
    msg->m_nInBufWord = v5 >> 8;
  }
  else
  {
    v8 = msg->m_pDataIn;
    v9 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      v10 = *v8;
      msg->m_pDataIn = v8 + 1;
      msg->m_nInBufWord = v10;
    }
    else
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
  }
LABEL_21:
  if ( v6 == 1 )
    (*(void (__thiscall **)(float *))(LODWORD(v3[-1].m_PlayerFog.m_flNewFarZ) + 1208))(a1: &v3[-1].m_PlayerFog.m_flNewFarZ);
}

//------------------------------------------------------------------------------
// Address: 0x10058A70
// Name: public: virtual void C_BasePlayer::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::OnRestore(C_BasePlayer *this)
{
  int v2; // esi
  int *m_iOldAmmo; // edi
  int ammoTypes; // [esp+8h] [ebp-4h]

  C_BaseEntity::OnRestore(this);
  if ( this != nullptr && this->IsPlayer(this) && this->m_bIsLocalPlayer )
  {
    input->ClearInputButton(this: input, a2: 526337);
    input->GetButtonBits(this: input, a2: false);
  }
  v2 = 0;
  ammoTypes = GetAmmoDef()->m_nAmmoIndex;
  if ( ammoTypes >= 0 )
  {
    m_iOldAmmo = this->m_iOldAmmo;
    do
      *m_iOldAmmo++ = C_BaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v2++);
    while ( v2 <= ammoTypes );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058AF0
// Name: public: bool C_BasePlayer::IsInVGuiInputMode(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::IsInVGuiInputMode(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_pCurrentVguiScreen.m_Index;
  return m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10058B30
// Name: public: bool C_BasePlayer::IsInViewModelVGuiInputMode(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::IsInViewModelVGuiInputMode(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx
  C_VGuiScreen **v2; // eax
  C_VGuiScreen *v3; // esi

  m_Index = this->m_pCurrentVguiScreen.m_Index;
  if ( m_Index == -1 )
    return false;
  v2 = (C_VGuiScreen **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return false;
  v3 = *v2;
  if ( *v2 == nullptr )
    return false;
  return C_VGuiScreen::IsAttachedToViewModel(this: *v2) && C_VGuiScreen::AcceptsInput(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10058B90
// Name: public: virtual bool C_BasePlayer::ShouldInterpolate(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::ShouldInterpolate(C_BasePlayer *this)
{
  bool result; // al
  C_HLTVCamera *v3; // eax

  result = this != nullptr && this->IsPlayer(this) && this->m_bIsLocalPlayer
        || (v3 = HLTVCamera(), C_HLTVCamera::GetCameraMan(this: v3) == this)
        || C_BaseEntity::ShouldInterpolate(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10058BD0
// Name: public: virtual bool C_BasePlayer::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BasePlayer::ShouldDraw(C_BasePlayer *this)
{
  return ((C_BasePlayer *)((char *)this - 4) != GetSplitScreenViewPlayer(nSlot: 0)
       || input->CAM_IsThirdPerson(this: input, a2: -1) != 0
       || ToolsEnabled() && ToolFramework_IsThirdPersonCamera()
       || (*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 1020))(a1: (char *)this - 4) == 1)
      && C_BaseEntity::ShouldDraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x10058C40
// Name: public: virtual int C_BasePlayer::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BasePlayer::DrawModel(C_BasePlayer *this, int flags, const RenderableInstance_t *instance)
{
  C_BasePlayer *v4; // esi
  int result; // eax

  v4 = s_pLocalPlayer[0];
  if ( s_pLocalPlayer[0] == nullptr )
    return C_BaseAnimating::DrawModel(this, flags, instance);
  if ( s_pLocalPlayer[0]->GetObserverMode(this: s_pLocalPlayer[0]) == 0 )
    return C_BaseAnimating::DrawModel(this, flags, instance);
  if ( v4->GetObserverMode(this: v4) != 4 )
    return C_BaseAnimating::DrawModel(this, flags, instance);
  if ( v4->GetObserverTarget(this: v4) != (C_BasePlayer *)((char *)this - 4) )
    return C_BaseAnimating::DrawModel(this, flags, instance);
  result = input->CAM_IsThirdPerson(this: input, a2: -1);
  if ( result != 0 )
    return C_BaseAnimating::DrawModel(this, flags, instance);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10058CC0
// Name: public: virtual bool C_BasePlayer::ShouldSuppressForSplitScreenPlayer(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BasePlayer::ShouldSuppressForSplitScreenPlayer(C_BasePlayer *this, int nSlot)
{
  return this->GetPlayerRenderMode(this, a2: nSlot) == PLAYER_RENDER_FIRSTPERSON;
}

//------------------------------------------------------------------------------
// Address: 0x10058CE0
// Name: protected: virtual class Vector C_BasePlayer::GetChaseCamViewOffset(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall C_BasePlayer::GetChaseCamViewOffset(C_BasePlayer *this, Vector *result, C_BaseEntity *target)
{
  const CViewVectors *v3; // eax
  __int64 v4; // xmm0_8
  float z; // eax
  const CViewVectors *v7; // eax
  float v8; // edx
  const CViewVectors *v9; // eax
  __int64 v10; // xmm0_8
  float v11; // eax

  if ( target != nullptr && target->IsPlayer(this: target) && target->IsAlive(this: target) )
  {
    if ( (target->m_fFlags & 2) != 0 )
    {
      v3 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v4 = *(_QWORD *)&v3->m_vDuckView.x;
      z = v3->m_vDuckView.z;
      *(_QWORD *)&result->x = v4;
      result->z = z;
    }
    else
    {
      v7 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v8 = v7->m_vView.z;
      *(_QWORD *)&result->x = *(_QWORD *)&v7->m_vView.x;
      result->z = v8;
    }
    return result;
  }
  else
  {
    v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v10 = *(_QWORD *)&v9->m_vDeadViewHeight.x;
    v11 = v9->m_vDeadViewHeight.z;
    *(_QWORD *)&result->x = v10;
    result->z = v11;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058D80
// Name: public: static int C_BasePlayer::GetSplitScreenSlotForPlayer(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl C_BasePlayer::GetSplitScreenSlotForPlayer(C_BaseEntity *pl)
{
  if ( pl != nullptr && pl->IsPlayer(this: pl) )
    return pl[2].m_pIntermediateData[69];
  else
    return (unsigned __int8 *)-1;
}

//------------------------------------------------------------------------------
// Address: 0x10058DB0
// Name: public: virtual class IClientModelRenderable __near * C_BasePlayer::GetClientModelRenderable(void)
// Source: json
//------------------------------------------------------------------------------
IClientModelRenderable *__thiscall C_BasePlayer::GetClientModelRenderable(C_BasePlayer *this)
{
  IClientModelRenderable *result; // eax
  char *v3; // esi
  C_BasePlayer *v4; // esi

  result = C_BaseFlex::GetClientModelRenderable(this);
  if ( result != nullptr )
  {
    v3 = (char *)this - 4;
    if ( this != (C_BasePlayer *)4
      && (*(unsigned __int8 (__thiscall **)(char *))(*(_DWORD *)v3 + 584))(a1: (char *)this - 4) != 0
      && v3[6276] != 0
      && input->CAM_IsThirdPerson(this: input, a2: -1) == 0
      && (!ToolsEnabled() || !ToolFramework_IsThirdPersonCamera()) )
    {
      return nullptr;
    }
    v4 = s_pLocalPlayer[0];
    if ( s_pLocalPlayer[0] != nullptr
      && s_pLocalPlayer[0]->GetObserverMode(this: s_pLocalPlayer[0]) != 0
      && v4->GetObserverMode(this: v4) == 4
      && v4->GetObserverTarget(this: v4) == (C_BasePlayer *)((char *)this - 4)
      && input->CAM_IsThirdPerson(this: input, a2: -1) == 0 )
    {
      return nullptr;
    }
    if ( this == (C_BasePlayer *)4 )
      return nullptr;
    else
      return (IClientModelRenderable *)&this->IClientThinkable;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10058E70
// Name: public: virtual void C_BasePlayer::UpdateClientData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UpdateClientData(C_BasePlayer *this)
{
  int i; // edi
  C_BaseCombatWeapon *v3; // eax

  for ( i = 0; i < 64; ++i )
  {
    if ( this->GetWeapon(this, a2: i) != nullptr )
    {
      v3 = this->GetWeapon(this, a2: i);
      v3->UpdateClientData(this: v3, a2: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058EB0
// Name: public: virtual void C_BasePlayer::PostThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::PostThink(C_BasePlayer *this)
{
  IMDLCache *v1; // edi

  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  if ( this->IsAlive(this) )
  {
    this->UpdateCollisionBounds(this);
    if ( !CommentaryModeShouldSwallowInput(pPlayer: this) )
      this->ItemPostFrame(this);
    if ( (this->m_fFlags & 1) != 0 )
      this->m_Local.m_flFallVelocity = 0.0;
    if ( this->m_nSequence == -1 )
      C_BaseAnimating::SetSequence(this, nSequence: 0);
    this->StudioFrameAdvance(this);
    C_BasePlayer::PostThinkVPhysics(this, a2: (int)v1);
  }
  C_BasePlayer::SimulatePlayerSimulatedEntities(this);
  v1->EndLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10058F60
// Name: public: virtual void C_BasePlayer::GetToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::GetToolRecordingState(C_BasePlayer *this, KeyValues *msg)
{
  bool v3; // al
  IGameResources_vtbl *v4; // edi
  int v5; // eax
  const char *v6; // eax
  bool v7; // al
  Vector camRight; // [esp+4h] [ebp-44h] BYREF
  Vector camUp; // [esp+10h] [ebp-38h] BYREF
  Vector camForward; // [esp+1Ch] [ebp-2Ch] BYREF
  Vector cam_ofs; // [esp+28h] [ebp-20h] BYREF
  QAngle camAngles; // [esp+34h] [ebp-14h] BYREF
  float flZNear; // [esp+40h] [ebp-8h] BYREF
  float flZFar; // [esp+44h] [ebp-4h] BYREF

  if ( ToolsEnabled() )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "C_BasePlayer::GetToolRecordingState",
      a3: 0,
      a4: "Tools",
      a5: false,
      a6: 4);
    C_BaseFlex::GetToolRecordingState(this, msg);
    KeyValues::SetInt(this: msg, keyName: "baseplayer", value: 1);
    v3 = this != nullptr && this->IsPlayer(this) && this->m_bIsLocalPlayer;
    KeyValues::SetInt(this: msg, keyName: "localplayer", value: v3);
    if ( g_PR != nullptr )
    {
      v4 = g_PR->IGameResources::__vftable;
      v5 = this->entindex(this: &this->IClientNetworkable);
      v6 = v4->GetPlayerName(this: &g_PR->IGameResources, a2: v5);
    }
    else
    {
      v6 = prType;
    }
    KeyValues::SetString(this: msg, keyName: "playername", value: v6);
    if ( (_S9_2 & 1) == 0 )
      _S9_2 |= 1u;
    state_2.m_flFOV = this->GetFOV(this);
    flZNear = view->GetZNear(this: view);
    flZFar = view->GetZFar(this: view);
    this->CalcView(
      this,
      a2: &state_2.m_vecEyePosition,
      a3: &state_2.m_vecEyeAngles,
      a4: &flZNear,
      a5: &flZFar,
      a6: &state_2.m_flFOV);
    v7 = !engine->IsPaused(this: engine) && input->CAM_IsThirdPerson(this: input, a2: -1) != 0;
    state_2.m_bThirdPerson = v7;
    state_2.m_bPlayerEyeIsPortalled = false;
    if ( v7 )
    {
      input->CAM_GetCameraOffset(this: input, a2: &cam_ofs);
      camAngles.x = cam_ofs.x;
      camAngles.y = cam_ofs.y;
      camAngles.z = 0.0;
      AngleVectors(angles: &camAngles, forward: &camForward, right: &camRight, up: &camUp);
      state_2.m_vecEyePosition.x = (float)(camForward.x * COERCE_FLOAT(LODWORD(cam_ofs.z) ^ _mask__NegFloat_))
                                 + state_2.m_vecEyePosition.x;
      state_2.m_vecEyePosition.y = (float)(COERCE_FLOAT(LODWORD(cam_ofs.z) ^ _mask__NegFloat_) * camForward.y)
                                 + state_2.m_vecEyePosition.y;
      state_2.m_vecEyeAngles = camAngles;
      state_2.m_vecEyePosition.z = (float)(camForward.z * COERCE_FLOAT(LODWORD(cam_ofs.z) ^ _mask__NegFloat_))
                                 + state_2.m_vecEyePosition.z;
    }
    KeyValues::SetPtr(this: msg, keyName: "camera", value: &state_2);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100591C0
// Name: public: virtual class C_BaseCombatWeapon __near * C_BasePlayer::GetActiveWeapon(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_BasePlayer::GetActiveWeapon(C_BasePlayer *this)
{
  C_CSPlayer *v1; // esi
  C_BaseEntity *v2; // edi

  v1 = (C_CSPlayer *)this;
  if ( this != nullptr && this->IsPlayer(this) && v1->m_bIsLocalPlayer && v1->GetObserverMode(this: v1) == 4 )
  {
    v2 = v1->GetObserverTarget(this: v1);
    if ( v2 != nullptr && v2->IsPlayer(this: v2) )
      v1 = ToBasePlayer(pEntity: v2);
  }
  return C_BaseCombatCharacter::GetActiveWeapon(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10059230
// Name: public: virtual class Vector C_BasePlayer::GetAutoaimVector(float)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall C_BasePlayer::GetAutoaimVector(C_BasePlayer *this, Vector *result, float flScale)
{
  const QAngle *v4; // eax
  QAngle angles; // [esp+4h] [ebp-Ch] BYREF

  v4 = this->GetAbsAngles(this);
  angles.x = this->m_Local.m_vecPunchAngle.m_Value.x + v4->x;
  angles.y = this->m_Local.m_vecPunchAngle.m_Value.y + v4->y;
  angles.z = this->m_Local.m_vecPunchAngle.m_Value.z + v4->z;
  AngleVectors(&angles, forward: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059290
// Name: public: virtual class QAngle const __near & C_BasePlayer::GetPunchAngle(void)
// Source: json
//------------------------------------------------------------------------------
CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *__thiscall C_BasePlayer::GetPunchAngle(
        C_BasePlayer *this)
{
  return &this->m_Local.m_vecPunchAngle;
}

//------------------------------------------------------------------------------
// Address: 0x100592A0
// Name: public: virtual class C_BaseEntity __near * C_BasePlayer::GetUseEntity(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BasePlayer::GetUseEntity(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hUseEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100592D0
// Name: public: static void C_BasePlayer::RecvProxy_LocalVelocityX(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BasePlayer::RecvProxy_LocalVelocityX(const CRecvProxyData *pData, C_BaseEntity *pStruct)
{
  float m_Float; // xmm0_4
  float z; // edx
  Vector vecVelocity; // [esp+0h] [ebp-Ch] BYREF

  m_Float = pData->m_Value.m_Float;
  z = pStruct->m_vecVelocity.z;
  *(_QWORD *)&vecVelocity.x = *(_QWORD *)&pStruct->m_vecVelocity.x;
  vecVelocity.z = z;
  if ( vecVelocity.x != m_Float )
  {
    vecVelocity.x = m_Float;
    C_BaseEntity::SetLocalVelocity(this: pStruct, &vecVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059320
// Name: public: static void C_BasePlayer::RecvProxy_LocalVelocityY(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BasePlayer::RecvProxy_LocalVelocityY(const CRecvProxyData *pData, C_BaseEntity *pStruct)
{
  float m_Float; // xmm0_4
  float z; // edx
  Vector vecVelocity; // [esp+0h] [ebp-Ch] BYREF

  m_Float = pData->m_Value.m_Float;
  z = pStruct->m_vecVelocity.z;
  *(_QWORD *)&vecVelocity.x = *(_QWORD *)&pStruct->m_vecVelocity.x;
  vecVelocity.z = z;
  if ( vecVelocity.y != m_Float )
  {
    vecVelocity.y = m_Float;
    C_BaseEntity::SetLocalVelocity(this: pStruct, &vecVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059370
// Name: public: static void C_BasePlayer::RecvProxy_LocalVelocityZ(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BasePlayer::RecvProxy_LocalVelocityZ(const CRecvProxyData *pData, float *pStruct)
{
  float v2; // edx
  float m_Float; // xmm0_4
  Vector vecVelocity; // [esp+0h] [ebp-Ch] BYREF

  v2 = pStruct[68];
  m_Float = pData->m_Value.m_Float;
  *(_QWORD *)&vecVelocity.x = *((_QWORD *)pStruct + 33);
  vecVelocity.z = v2;
  if ( v2 != m_Float )
  {
    vecVelocity.z = m_Float;
    C_BaseEntity::SetLocalVelocity(this: (C_BaseEntity *)pStruct, &vecVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100593C0
// Name: public: void C_BasePlayer::GetPredictionErrorSmoothingVector(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::GetPredictionErrorSmoothingVector(C_BasePlayer *this, Vector *vOffset)
{
  float v3; // xmm1_4
  Vector *v4; // eax
  float v5; // xmm2_4
  float v6; // xmm3_4

  if ( !engine->IsPlayingDemo(this: engine)
    && cl_smooth.m_pParent != nullptr
    && cl_smooth.m_pParent->m_Value.m_nValue != 0
    && cl_predict->GetInt(this: cl_predict) != 0
    && !engine->IsPaused(this: engine) )
  {
    v3 = (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_flPredictionErrorTime)
       / cl_smoothtime.m_pParent->m_Value.m_fValue;
    v4 = vOffset;
    if ( v3 < 1.0 )
    {
      v5 = this->m_vecPredictionError.y * (float)(1.0 - v3);
      v6 = this->m_vecPredictionError.z * (float)(1.0 - v3);
      vOffset->x = (float)(1.0 - v3) * this->m_vecPredictionError.x;
      vOffset->y = v5;
      vOffset->z = v6;
      return;
    }
  }
  else
  {
    v4 = vOffset;
  }
  *(_QWORD *)&v4->y = 0;
  v4->x = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100594A0
// Name: public: virtual class CNewParticleEffect __near * C_BasePlayer::GetVOIPParticleEffect(void)
// Source: json
//------------------------------------------------------------------------------
CNewParticleEffect *__thiscall C_BasePlayer::GetVOIPParticleEffect(C_BasePlayer *this)
{
  CVoiceStatus *ClientVoiceMgr; // eax
  const Vector *v3; // edi
  Vector *v4; // eax
  unsigned int v5; // xmm1_4
  unsigned int v6; // xmm2_4
  C_BasePlayer_vtbl *v7; // edx
  const char *v8; // eax
  Vector v10; // [esp-10h] [ebp-3Ch]
  _BYTE v11[20]; // [esp+8h] [ebp-24h] BYREF
  float HeadLabelOffset; // [esp+1Ch] [ebp-10h]
  unsigned __int64 v13; // [esp+20h] [ebp-Ch]
  float v14; // [esp+28h] [ebp-4h]

  ClientVoiceMgr = GetClientVoiceMgr();
  HeadLabelOffset = CVoiceStatus::GetHeadLabelOffset(this: ClientVoiceMgr);
  v3 = this->GetAbsOrigin(this);
  v4 = this->EyePosition(this, result: v11);
  *(float *)&v5 = v4->x - v3->x;
  *(float *)&v6 = v4->y - v3->y;
  v7 = this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  v14 = (float)(v4->z - v3->z) + HeadLabelOffset;
  v13 = __PAIR64__(v6, v5);
  *(_QWORD *)&v10.x = __PAIR64__(v6, v5);
  v10.z = v14;
  v8 = v7->GetVOIPParticleEffectName(this);
  return CParticleProperty::Create(
           this: &this->m_Particles,
           pszParticleName: v8,
           iAttachType: PATTACH_ABSORIGIN_FOLLOW,
           iAttachmentPoint: -1,
           vecOriginOffset: v10,
           matOffset: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10059540
// Name: public: class C_PostProcessController __near * C_BasePlayer::GetActivePostProcessController(void)const
// Source: json
//------------------------------------------------------------------------------
C_PostProcessController *__thiscall C_BasePlayer::GetActivePostProcessController(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hPostProcessCtrl.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_PostProcessController *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10059570
// Name: public: class C_ColorCorrection __near * C_BasePlayer::GetActiveColorCorrection(void)const
// Source: json
//------------------------------------------------------------------------------
C_ColorCorrection *__thiscall C_BasePlayer::GetActiveColorCorrection(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hColorCorrectionCtrl.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_ColorCorrection *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100595A0
// Name: void UTIL_TraceRay(struct Ray_t const __near &,unsigned int,class IHandleEntity const __near *,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_TraceRay(
        const Ray_t *ray,
        unsigned int mask,
        const IHandleEntity *ignore,
        int collisionGroup,
        CGameTrace *ptr)
{
  CTraceFilterSimple traceFilter; // [esp+18h] [ebp-10h] BYREF

  CTraceFilterSimple::CTraceFilterSimple(
    this: &traceFilter,
    passedict: ignore,
    collisionGroup,
    pExtraShouldHitFunc: nullptr);
  enginetrace->TraceRay(this: enginetrace, a2: ray, a3: mask, a4: &traceFilter, a5: ptr);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &ptr->startpos, vecAbsEnd: &ptr->endpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10059610
// Name: public: bool CountdownTimer::IsElapsed(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CountdownTimer::IsElapsed(CountdownTimer *this)
{
  return CountdownTimer::Now((CEffectsClient *)this) > (double)this->m_timestamp.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10059630
// Name: public: void CFlashlightEffectManager::UpdateFlashlight(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,bool,float,float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashlightEffectManager::UpdateFlashlight(
        CFlashlightEffectManager *this,
        const Vector *vecPos,
        const Vector *vecDir,
        const Vector *vecRight,
        const Vector *vecUp,
        float flFov,
        bool castsShadows,
        float flFarZ,
        float flLinearAtten,
        const char *pTextureName)
{
  bool v11; // bl
  CFlashlightEffect *m_pFlashlightEffect; // ecx
  CFlashlightEffect *v13; // edi
  CFlashlightEffect *v14; // eax
  CFlashlightEffect *v15; // eax
  int v16; // eax
  int m_nFlashlightEntIndex; // [esp-14h] [ebp-38h]
  float flBrightness; // [esp+10h] [ebp-14h]

  if ( !this->m_bFlashlightOverride )
  {
    v11 = this->m_nMuzzleFlashFrameCountdown > 0
       || CountdownTimer::Now(this: (CEffectsClient *)&this->m_muzzleFlashTimer) <= (double)this->m_muzzleFlashTimer.m_timestamp.m_Value;
    m_pFlashlightEffect = this->m_pFlashlightEffect;
    if ( this->m_pFlashlightEffect != nullptr )
    {
      m_nFlashlightEntIndex = this->m_nFlashlightEntIndex;
      this->m_flFov = flFov;
      this->m_flFarZ = flFarZ;
      this->m_flLinearAtten = flLinearAtten;
      CFlashlightEffect::UpdateLight(
        this: m_pFlashlightEffect,
        nEntIdx: m_nFlashlightEntIndex,
        vecPos,
        vecForward: vecDir,
        vecRight,
        vecUp,
        flFov,
        flFarZ,
        flLinearAtten,
        castsShadows,
        pTextureName);
      CFlashlightEffect::SetMuzzleFlashEnabled(
        this: this->m_pFlashlightEffect,
        bEnabled: v11,
        flBrightness: this->m_flMuzzleFlashBrightness);
    }
    if ( v11 )
    {
      if ( !this->m_bFlashlightOn && this->m_pFlashlightEffect == nullptr )
      {
        v14 = (CFlashlightEffect *)MemAlloc_Alloc(nSize: 0x6Cu);
        if ( v14 != nullptr )
          v15 = CFlashlightEffect::CFlashlightEffect(
                  this: v14,
                  nEntIndex: this->m_nFlashlightEntIndex,
                  pszTextureName: nullptr,
                  flFov: 0.0,
                  flFarZ: 0.0,
                  flLinearAtten: 0.0);
        else
          v15 = nullptr;
        flBrightness = this->m_flMuzzleFlashBrightness;
        this->m_pFlashlightEffect = v15;
        CFlashlightEffect::SetMuzzleFlashEnabled(this: v15, bEnabled: v11, flBrightness);
      }
      v16 = *(_DWORD *)(gpGlobals.m_Index + 4);
      if ( this->m_nFXComputeFrame != v16 )
      {
        --this->m_nMuzzleFlashFrameCountdown;
        this->m_nFXComputeFrame = v16;
      }
    }
    else if ( !this->m_bFlashlightOn )
    {
      v13 = this->m_pFlashlightEffect;
      if ( this->m_pFlashlightEffect != nullptr )
      {
        CFlashlightEffect::~CFlashlightEffect(this: this->m_pFlashlightEffect);
        C_BaseEntity::operator delete(pMem: v13);
        this->m_pFlashlightEffect = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059FF0
// Name: protected: struct surfacedata_t __near * C_BasePlayer::GetGroundSurface(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
surfacedata_t *__usercall C_BasePlayer::GetGroundSurface@<eax>(C_BasePlayer *this@<ecx>, float a2@<ebp>, int a3@<esi>)
{
  int v4; // eax
  float v5; // xmm1_4
  float v6; // xmm2_4
  const Vector *(__thiscall *GetPlayerMaxs)(C_BasePlayer *, const Vector *); // edx
  int v8; // eax
  const Vector *v9; // eax
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  _BYTE v13[12]; // [esp+2Ch] [ebp-ECh] BYREF
  Ray_t ray; // [esp+38h] [ebp-E0h] BYREF
  CGameTrace trace; // [esp+88h] [ebp-90h] BYREF
  CTraceFilterSimple v16; // [esp+E4h] [ebp-34h] BYREF
  Vector v17; // [esp+F4h] [ebp-24h] BYREF
  Vector end; // [esp+100h] [ebp-18h] BYREF
  Vector start; // [esp+10Ch] [ebp-Ch]
  float retaddr; // [esp+118h] [ebp+0h]

  start.x = a2;
  start.y = retaddr;
  v4 = ((int (__thiscall *)(C_BasePlayer *, int))this->GetAbsOrigin)(a1: this, a2: a3);
  v5 = *(float *)v4;
  v6 = *(float *)(v4 + 4);
  GetPlayerMaxs = this->GetPlayerMaxs;
  end.z = *(float *)(v4 + 8);
  end.y = v6;
  v17.x = v5;
  v17.y = v6;
  v17.z = end.z - 64.0;
  ray.m_Extents.y = 0.0;
  v8 = (int)GetPlayerMaxs(this, result: (const Vector *)LODWORD(v5));
  v9 = (const Vector *)((int (__thiscall *)(C_BasePlayer *, const IHandleEntity **, int))this->GetPlayerMins)(
                         a1: this,
                         a2: &v16.m_pPassEnt,
                         a3: v8);
  Ray_t::Init(this: (Ray_t *)v13, start: &end, end: &v17, mins: v9, maxs: (const Vector *)LODWORD(end.y));
  CTraceFilterSimple::CTraceFilterSimple(this: &v16, passedict: this, collisionGroup: 8, pExtraShouldHitFunc: nullptr);
  TraceRay = enginetrace->TraceRay;
  LODWORD(end.y) = &ray.m_IsRay;
  ((void (__thiscall *)(IEngineTrace *, _BYTE *, int, CTraceFilterSimple *))TraceRay)(
    a1: enginetrace,
    a2: v13,
    a3: 81931,
    a4: &v16);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(
      vecAbsStart: (const Vector *)&ray.m_IsRay,
      vecAbsEnd: &trace.startpos,
      r: 255,
      g: 0,
      b: 0,
      test: 1,
      duration: -1.0);
  if ( trace.plane.normal.z == 1.0 )
    return nullptr;
  else
    return physprops->GetSurfaceData(this: physprops, a2: (__int16)trace.dispFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1005A130
// Name: public: virtual void C_BasePlayer::SetVehicleRole(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SetVehicleRole(C_BasePlayer *this, int nRole)
{
  unsigned int m_Index; // ecx
  char szCmd[64]; // [esp+0h] [ebp-40h] BYREF

  m_Index = this->m_hVehicle.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
    && nRole <= 0 )
  {
    V_snprintf(pDest: szCmd, maxLen: 64, pFormat: "vehicleRole %i\n", nRole);
    engine->ServerCmd(this: engine, a2: szCmd, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A1A0
// Name: public: void C_BasePlayer::CheckForLocalPlayer(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::CheckForLocalPlayer(C_BasePlayer *this, int nSplitScreenSlot)
{
  int v3; // eax
  ConVar *v4; // eax

  if ( nSplitScreenSlot == -1 )
    v3 = 0;
  else
    v3 = engine->GetLocalPlayer(this: engine);
  if ( g_nKillCamMode != 0 )
    v3 = g_nKillCamTarget1;
  if ( v3 == this->index )
  {
    s_pLocalPlayer[nSplitScreenSlot] = this;
    this->m_bIsLocalPlayer = true;
    if ( nSplitScreenSlot != 0 )
    {
      this->m_nSplitScreenSlot = nSplitScreenSlot;
      if ( s_pLocalPlayer[0] != nullptr )
        this->m_hSplitOwner.m_Index = s_pLocalPlayer[0]->GetRefEHandle(this: s_pLocalPlayer[0])->m_Index;
      else
        this->m_hSplitOwner.m_Index = -1;
      if ( s_pLocalPlayer[0] != nullptr )
      {
        C_BasePlayer::AddSplitScreenPlayer(this: s_pLocalPlayer[0], pOther: this);
        C_BaseEntity::UpdateVisibilityAllEntities();
        return;
      }
    }
    else
    {
      this->m_nSplitScreenSlot = 0;
      this->m_hSplitOwner.m_Index = -1;
      v4 = cvar->FindVar_2(this: cvar, a2: "snd_soundmixer");
      ConVar::Revert(this: v4);
    }
    C_BaseEntity::UpdateVisibilityAllEntities();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A270
// Name: protected: void C_BasePlayer::DetermineVguiInputMode(class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BasePlayer::DetermineVguiInputMode(C_BasePlayer *this@<ecx>, int a2@<edi>, CUserCmd *pCmd)
{
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // eax
  unsigned int v6; // esi
  C_BaseEntity *v7; // eax
  int buttons; // eax
  bool v9; // al
  CHandle<C_BaseEntity> *p_m_pCurrentVguiScreen; // ecx
  C_BaseCombatWeapon *v11; // eax
  C_BaseCombatWeapon *v12; // esi
  const Vector *v13; // eax
  C_BasePlayer *NearbyVguiScreen; // eax
  C_BaseCombatWeapon *v15; // eax
  C_BaseCombatWeapon *v16; // eax
  const char *v17; // [esp-Ch] [ebp-1Ch]
  QAngle viewAngle; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( !this->IsAlive(this) )
  {
    m_Index = this->m_pCurrentVguiScreen.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    DeactivateVguiScreen(pVguiScreenEnt: m_pEntity);
    this->m_pCurrentVguiScreen.m_Index = -1;
    return;
  }
  v6 = this->m_pCurrentVguiScreen.m_Index;
  if ( v6 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity != nullptr
    && (pCmd->buttons & 0x80801) != 0 )
  {
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6) )
      v7 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    else
      v7 = nullptr;
    SetVGuiScreenButtonState(pVguiScreenEnt: v7, nButtonState: (const char *)pCmd->buttons);
    pCmd->buttons &= 0xFFF7F7FE;
    return;
  }
  buttons = pCmd->buttons;
  if ( (buttons & 1) != 0 || (buttons & 0x80800) != 0 )
  {
    if ( v6 == -1 )
      goto LABEL_30;
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity == nullptr )
    {
      goto LABEL_28;
    }
  }
  if ( C_BasePlayer::IsInAVehicle(this) )
  {
LABEL_28:
    if ( v6 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6) )
    {
      v11 = (C_BaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
      goto LABEL_31;
    }
LABEL_30:
    v11 = nullptr;
    goto LABEL_31;
  }
  v9 = g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface);
  p_m_pCurrentVguiScreen = &this->m_pCurrentVguiScreen;
  if ( v9 )
  {
    v11 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)p_m_pCurrentVguiScreen);
LABEL_31:
    DeactivateVguiScreen(pVguiScreenEnt: v11);
    this->m_pCurrentVguiScreen.m_Index = -1;
    return;
  }
  v12 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)p_m_pCurrentVguiScreen);
  ((void (__thiscall *)(C_BasePlayer *, int))this->GetTeamNumber)(a1: this, a2);
  v13 = (const Vector *)((int (__thiscall *)(C_BasePlayer *))this->EyePosition)(a1: this);
  NearbyVguiScreen = FindNearbyVguiScreen(
                       a1: COERCE_FLOAT(&savedregs),
                       viewPosition: v13,
                       &viewAngle,
                       nTeam: (int)&pCmd->viewangles);
  CHandle<C_ViewmodelAttachmentModel>::operator=(this: &this->m_pCurrentVguiScreen, val: NearbyVguiScreen);
  if ( v12 != CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_pCurrentVguiScreen) )
  {
    DeactivateVguiScreen(pVguiScreenEnt: v12);
    v15 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_pCurrentVguiScreen);
    ActivateVguiScreen(pVguiScreenEnt: v15);
  }
  if ( CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_pCurrentVguiScreen) != nullptr )
  {
    v17 = (const char *)pCmd->buttons;
    v16 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_pCurrentVguiScreen);
    SetVGuiScreenButtonState(pVguiScreenEnt: v16, nButtonState: v17);
    pCmd->buttons &= 0xFFF7F7FE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A4A0
// Name: public: virtual bool C_BasePlayer::CreateMove(float,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BasePlayer::CreateMove(C_BasePlayer *this, float flInputSampleTime, CUserCmd *pCmd)
{
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *m_pEntity; // ecx
  int v12; // eax
  C_BaseCombatWeapon *v13; // eax

  m_Index = this->m_hVehicle.m_Index;
  if ( m_Index != -1
    && (v5 = (unsigned __int16)m_Index,
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v7 = HIWORD(m_Index),
        v6->m_SerialNumber == v7)
    && v6->m_pEntity != nullptr )
  {
    v8 = v5;
    v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
    v10 = &g_pEntityList->m_EntPtrArray[v8];
    if ( v9 )
      m_pEntity = v10->m_pEntity;
    else
      m_pEntity = nullptr;
    v12 = ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: m_pEntity);
    if ( v12 != 0 )
    {
      (*(void (__thiscall **)(int, C_BasePlayer *, CUserCmd *))(*(_DWORD *)v12 + 36))(a1: v12, a2: this, a3: pCmd);
      engine->SetViewAngles(this: engine, a2: &pCmd->viewangles);
    }
  }
  else
  {
    if ( joy_autosprint.m_pParent != nullptr
      && joy_autosprint.m_pParent->m_Value.m_nValue != 0
      && ((double (__thiscall *)(IInput *, kbutton_t *))input->KeyState)(a1: input, a2: &in_joyspeed) != 0.0 )
    {
      pCmd->buttons |= 0x20000u;
    }
    v13 = this->GetActiveWeapon(this);
    if ( v13 != nullptr )
      ((void (__thiscall *)(C_BaseCombatWeapon *, _DWORD, CUserCmd *, QAngle *))v13->CreateMove)(
        a1: v13,
        a2: LODWORD(flInputSampleTime),
        a3: pCmd,
        a4: &this->m_vecOldViewAngles);
  }
  if ( (this->m_fFlags & 0x40) != 0 )
  {
    if ( this->m_bWasFrozen )
    {
      pCmd->viewangles = this->m_vecOldViewAngles;
      engine->SetViewAngles(this: engine, a2: &pCmd->viewangles);
    }
    else
    {
      this->m_bWasFrozen = true;
    }
  }
  else
  {
    this->m_bWasFrozen = false;
  }
  this->m_vecOldViewAngles = pCmd->viewangles;
  C_BasePlayer::DetermineVguiInputMode(this, a2: (int)pCmd, pCmd);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005A600
// Name: public: virtual enum PlayerRenderMode_t C_BasePlayer::GetPlayerRenderMode(int)
// Source: json
//------------------------------------------------------------------------------
PlayerRenderMode_t __thiscall C_BasePlayer::GetPlayerRenderMode(C_BasePlayer *this, int nSlot)
{
  C_BasePlayer *SplitScreenViewPlayer; // esi
  PlayerRenderMode_t result; // eax

  SplitScreenViewPlayer = GetSplitScreenViewPlayer(nSlot);
  if ( SplitScreenViewPlayer == nullptr )
    return PLAYER_RENDER_THIRDPERSON;
  if ( SplitScreenViewPlayer->GetObserverMode(this: SplitScreenViewPlayer) != 0 )
  {
    if ( SplitScreenViewPlayer->GetObserverTarget(this: SplitScreenViewPlayer) != this
      || SplitScreenViewPlayer->GetObserverMode(this: SplitScreenViewPlayer) != 4 )
    {
      return PLAYER_RENDER_THIRDPERSON;
    }
  }
  else if ( SplitScreenViewPlayer != this )
  {
    return PLAYER_RENDER_THIRDPERSON;
  }
  if ( input->CAM_IsThirdPerson(this: input, a2: nSlot) != 0 )
    return PLAYER_RENDER_THIRDPERSON;
  if ( C_BasePlayer::GetViewEntity(this: SplitScreenViewPlayer) == nullptr )
    return PLAYER_RENDER_FIRSTPERSON;
  if ( C_BasePlayer::GetViewEntity(this: SplitScreenViewPlayer) == SplitScreenViewPlayer )
    return PLAYER_RENDER_FIRSTPERSON;
  result = PLAYER_RENDER_THIRDPERSON;
  if ( !SplitScreenViewPlayer->m_bShouldDrawPlayerWhileUsingViewEntity )
    return PLAYER_RENDER_FIRSTPERSON;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005A6B0
// Name: protected: void C_BasePlayer::CalcChaseCamView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1005ABD0
// Name: protected: virtual void C_BasePlayer::CalcRoamingView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::CalcRoamingView(C_BasePlayer *this, Vector *eyeOrigin, QAngle *eyeAngles, float *fov)
{
  C_BasePlayer *v5; // edi
  float *v6; // eax
  const QAngle *(__thiscall *v7)(C_BaseEntity *); // edx
  int m_nValue; // eax
  C_BaseEntity *BaseEntity; // eax
  int v10; // eax
  float v11; // ecx
  float v12; // xmm1_4
  float v13; // xmm0_4
  Vector vSmoothOffset; // [esp+Ch] [ebp-24h] BYREF
  Vector v; // [esp+18h] [ebp-18h]
  QAngle a; // [esp+24h] [ebp-Ch] BYREF

  v5 = (C_BasePlayer *)this->GetObserverTarget(this);
  if ( v5 == nullptr )
    v5 = this;
  this->m_flObserverChaseDistance = 0.0;
  v6 = (float *)v5->EyePosition(this: v5, result: &vSmoothOffset);
  eyeOrigin->x = *v6;
  eyeOrigin->y = v6[1];
  v7 = v5->EyeAngles;
  eyeOrigin->z = v6[2];
  *eyeAngles = *v7(this: v5);
  if ( spec_track.m_pParent != nullptr )
  {
    m_nValue = spec_track.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
    {
      BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: m_nValue);
      if ( BaseEntity != nullptr )
      {
        v10 = (int)BaseEntity->GetAbsOrigin(this: BaseEntity);
        v11 = *(float *)(v10 + 8);
        *(_QWORD *)&v.x = *(_QWORD *)v10;
        v12 = v.x - eyeOrigin->x;
        v.z = v11;
        v13 = (float)(v11 + 54.0) - eyeOrigin->z;
        vSmoothOffset.x = v12;
        vSmoothOffset.y = v.y - eyeOrigin->y;
        vSmoothOffset.z = v13;
        VectorAngles(forward: &vSmoothOffset, angles: &a);
        NormalizeAngles(angles: &a);
        *eyeAngles = a;
        engine->SetViewAngles(this: engine, a2: &a);
      }
    }
  }
  C_BasePlayer::GetPredictionErrorSmoothingVector(this, vOffset: &vSmoothOffset);
  eyeOrigin->x = eyeOrigin->x + vSmoothOffset.x;
  eyeOrigin->y = eyeOrigin->y + vSmoothOffset.y;
  eyeOrigin->z = eyeOrigin->z + vSmoothOffset.z;
  *fov = this->GetFOV(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005AD50
// Name: protected: virtual void C_BasePlayer::CalcFreezeCamView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::CalcFreezeCamView(C_BasePlayer *this, Vector *eyeOrigin, QAngle *eyeAngles, float *fov)
{
  C_BaseEntity *v5; // esi
  float v6; // xmm2_4
  float v7; // xmm0_4
  Vector *v8; // eax
  C_BaseEntity_vtbl *v9; // edx
  bool (__thiscall *IsAlive)(C_BaseEntity *); // eax
  bool v11; // zf
  int (*GetViewVectors)(void); // eax
  int v13; // eax
  float v14; // ecx
  float v15; // xmm0_4
  float z; // ecx
  float m_flFreezeFrameDistance; // xmm2_4
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  float v19; // xmm0_4
  IGameEvent *v20; // eax
  CGameTrace trace; // [esp+2Ch] [ebp-94h] BYREF
  float flCurTime; // [esp+80h] [ebp-40h]
  Vector maxs; // [esp+84h] [ebp-3Ch] BYREF
  Vector vecToTarget; // [esp+90h] [ebp-30h] BYREF
  Vector vecCamDesired; // [esp+9Ch] [ebp-24h] BYREF
  Vector vecTargetPos; // [esp+A8h] [ebp-18h] BYREF
  Vector vecCamTarget; // [esp+B4h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+C0h] [ebp+0h] BYREF
  float flBlendPerc; // [esp+D0h] [ebp+10h]

  v5 = this->GetObserverTarget(this);
  if ( v5 != nullptr )
  {
    v6 = 1.0;
    flCurTime = *(float *)(gpGlobals.m_Index + 12) - this->m_flFreezeFrameStartTime;
    v7 = flCurTime / spec_freeze_traveltime.m_pParent->m_Value.m_fValue;
    if ( v7 >= 0.0 )
    {
      if ( v7 <= 1.0 )
        v6 = flCurTime / spec_freeze_traveltime.m_pParent->m_Value.m_fValue;
    }
    else
    {
      v6 = 0.0;
    }
    flBlendPerc = (float)((float)(v6 * v6) * 3.0) - (float)((float)((float)(v6 * v6) * 2.0) * v6);
    v5->GetObserverCamOrigin(this: v5, result: &vecCamDesired);
    v8 = this->GetChaseCamViewOffset(this, result: &maxs, a3: v5);
    vecCamDesired.x = v8->x + vecCamDesired.x;
    vecCamDesired.y = v8->y + vecCamDesired.y;
    vecCamDesired.z = v8->z + vecCamDesired.z;
    v9 = v5->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    vecCamTarget.z = vecCamDesired.z;
    IsAlive = v9->IsAlive;
    *(_QWORD *)&vecCamTarget.x = *(_QWORD *)&vecCamDesired.x;
    v11 = !IsAlive(this: v5);
    GetViewVectors = (int (*)(void))g_pGameRules->GetViewVectors;
    if ( v11 )
    {
      v15 = *(float *)(GetViewVectors() + 104) + vecCamTarget.z;
    }
    else
    {
      v13 = GetViewVectors();
      v14 = *(float *)(v13 + 32);
      *(_QWORD *)&maxs.x = *(_QWORD *)(v13 + 24);
      maxs.z = v14;
      v15 = vecCamTarget.z - (float)(v14 * 0.5);
    }
    vecCamTarget.z = v15;
    z = eyeOrigin->z;
    *(_QWORD *)&maxs.x = *(_QWORD *)&eyeOrigin->x;
    vecTargetPos = vecCamTarget;
    vecToTarget.x = vecCamTarget.x - maxs.x;
    vecToTarget.y = vecCamTarget.y - maxs.y;
    maxs.z = z;
    vecToTarget.z = 0.0;
    VectorNormalize(vec: &vecToTarget);
    m_flFreezeFrameDistance = this->m_flFreezeFrameDistance;
    EyePosition = v5->EyePosition;
    vecTargetPos.x = vecCamTarget.x - (float)(vecToTarget.x * m_flFreezeFrameDistance);
    vecTargetPos.y = vecCamTarget.y - (float)(vecToTarget.y * m_flFreezeFrameDistance);
    vecTargetPos.z = this->m_flFreezeZOffset + EyePosition(this: v5, result: &maxs)->z;
    C_BaseEntity::PushEnableAbsRecomputations(bEnable: false);
    UTIL_TraceHull(
      a1: &savedregs,
      a2: (int)v5,
      vecAbsStart: &vecCamTarget,
      vecAbsEnd: &vecTargetPos,
      hullMin: &WALL_MIN,
      hullMax: &WALL_MAX,
      mask: 0x200400Bu,
      ignore: v5,
      collisionGroup: 0,
      ptr: &trace);
    C_BaseEntity::PopEnableAbsRecomputations();
    if ( trace.fraction < 1.0 )
    {
      vecTargetPos.x = trace.endpos.x;
      vecTargetPos.y = trace.endpos.y;
      vecCamTarget = vecCamDesired;
      v19 = COERCE_FLOAT(COERCE_UNSIGNED_INT(vecCamDesired.z - trace.endpos.z) & _mask__AbsFloat_) * 0.85
          + trace.endpos.z;
      vecTargetPos.z = v19;
      C_BaseEntity::PushEnableAbsRecomputations(bEnable: false);
      UTIL_TraceHull(
        a1: &savedregs,
        a2: (int)v5,
        vecAbsStart: &vecCamTarget,
        vecAbsEnd: &vecTargetPos,
        hullMin: &WALL_MIN,
        hullMax: &WALL_MAX,
        mask: 0x200400Bu,
        ignore: v5,
        collisionGroup: 0,
        ptr: &trace);
      C_BaseEntity::PopEnableAbsRecomputations();
      vecTargetPos = trace.endpos;
    }
    vecToTarget.x = vecCamTarget.x - vecTargetPos.x;
    vecToTarget.y = vecCamTarget.y - vecTargetPos.y;
    vecToTarget.z = vecCamTarget.z - vecTargetPos.z;
    VectorNormalize(vec: &vecToTarget);
    VectorAngles(forward: &vecToTarget, angles: eyeAngles);
    eyeOrigin->x = (float)((float)(vecTargetPos.x - this->m_vecFreezeFrameStart.x) * flBlendPerc)
                 + this->m_vecFreezeFrameStart.x;
    eyeOrigin->y = (float)((float)(vecTargetPos.y - this->m_vecFreezeFrameStart.y) * flBlendPerc)
                 + this->m_vecFreezeFrameStart.y;
    eyeOrigin->z = (float)((float)(vecTargetPos.z - this->m_vecFreezeFrameStart.z) * flBlendPerc)
                 + this->m_vecFreezeFrameStart.z;
    if ( flCurTime >= spec_freeze_traveltime.m_pParent->m_Value.m_fValue && !this->m_bSentFreezeFrame )
    {
      v20 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "freezecam_started", a3: 0, a4: 0);
      if ( v20 != nullptr )
        gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v20);
      this->m_bSentFreezeFrame = true;
      ((void (__stdcall *)(_DWORD))view->FreezeFrame)(a1: LODWORD(spec_freeze_time.m_pParent->m_Value.m_fValue));
    }
  }
  else
  {
    this->CalcDeathCamView(this, a2: eyeOrigin, a3: eyeAngles, a4: fov);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B180
// Name: protected: void C_BasePlayer::CalcInEyeCamView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BasePlayer::CalcInEyeCamView(
        C_BasePlayer *this@<ecx>,
        int a2@<ebx>,
        Vector *eyeOrigin,
        QAngle *eyeAngles,
        float *fov)
{
  C_BaseEntity *v6; // edi
  const QAngle *v7; // eax
  int (*GetViewVectors)(void); // eax
  float *v9; // eax
  float v10; // xmm0_4
  float *v11; // eax
  float z; // ecx
  float v13; // xmm0_4
  Vector offset; // [esp+8h] [ebp-10h] BYREF
  C_BaseEntity *target; // [esp+14h] [ebp-4h]

  v6 = this->GetObserverTarget(this);
  target = v6;
  if ( v6 != nullptr )
  {
    if ( v6->IsAlive(this: v6) )
    {
      *fov = ((double (__thiscall *)(C_BasePlayer *, int))this->GetFOV)(a1: this, a2);
      this->m_flObserverChaseDistance = 0.0;
      *eyeAngles = *v6->EyeAngles(this: v6);
      *eyeOrigin = *v6->GetAbsOrigin(this: v6);
      v7 = this->GetPunchAngle(this);
      eyeAngles->x = v7->x + eyeAngles->x;
      eyeAngles->y = v7->y + eyeAngles->y;
      eyeAngles->z = v7->z + eyeAngles->z;
      if ( g_bEngineIsHLTV )
      {
        GetViewVectors = (int (*)(void))g_pGameRules->GetViewVectors;
        if ( (target->m_fFlags & 2) != 0 )
        {
          v9 = (float *)GetViewVectors();
          eyeOrigin->x = v9[15] + eyeOrigin->x;
          eyeOrigin->y = v9[16] + eyeOrigin->y;
          v10 = v9[17] + eyeOrigin->z;
        }
        else
        {
          v11 = (float *)GetViewVectors();
          eyeOrigin->x = eyeOrigin->x + *v11;
          eyeOrigin->y = v11[1] + eyeOrigin->y;
          v10 = v11[2] + eyeOrigin->z;
        }
      }
      else
      {
        z = this->m_vecViewOffset.z;
        *(_QWORD *)&offset.x = *(_QWORD *)&this->m_vecViewOffset.x;
        eyeOrigin->x = eyeOrigin->x + offset.x;
        eyeOrigin->y = eyeOrigin->y + offset.y;
        v13 = eyeOrigin->z;
        offset.z = z;
        v10 = v13 + z;
      }
      eyeOrigin->z = v10;
      ((void (__thiscall *)(IVEngineClient *))engine->SetViewAngles)(a1: engine);
    }
    else
    {
      C_BasePlayer::CalcChaseCamView(this, eyeOrigin, eyeAngles, fov);
    }
  }
  else
  {
    *eyeOrigin = *this->EyePosition(this, result: &offset);
    *eyeAngles = *this->EyeAngles(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B370
// Name: protected: virtual void C_BasePlayer::CalcDeathCamView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge C_BasePlayer::CalcDeathCamView(
        C_BasePlayer *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        Vector *eyeOrigin,
        QAngle *eyeAngles,
        float *fov)
{
  float (__thiscall *GetDeathCamInterpolationTime)(C_BasePlayer *); // eax
  double v9; // st7
  double v10; // st7
  float x; // xmm0_4
  float v12; // xmm0_4
  int v13; // xmm1_4
  C_BasePlayer_vtbl *v14; // eax
  __int64 v15; // xmm0_8
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  IRagdoll *v17; // eax
  int v18; // eax
  const CViewVectors *v19; // eax
  float *v20; // eax
  float v21; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  __int128 v27; // xmm0
  int v28; // [esp+Ch] [ebp-CCh]
  int v29; // [esp+10h] [ebp-C8h]
  _DWORD v30[3]; // [esp+14h] [ebp-C4h] BYREF
  CGameTrace trace; // [esp+20h] [ebp-B8h] BYREF
  int v32; // [esp+74h] [ebp-64h]
  int v33; // [esp+78h] [ebp-60h]
  __int128 aKiller; // [esp+7Ch] [ebp-5Ch] OVERLAPPED BYREF
  int v35; // [esp+8Ch] [ebp-4Ch]
  int v36; // [esp+90h] [ebp-48h]
  QAngle v37; // [esp+94h] [ebp-44h] BYREF
  QAngle aForward; // [esp+A0h] [ebp-38h] BYREF
  Vector vKiller; // [esp+ACh] [ebp-2Ch] BYREF
  Vector vForward; // [esp+B8h] [ebp-20h] BYREF
  C_BaseEntity *pKiller; // [esp+C4h] [ebp-14h]
  Vector origin; // [esp+C8h] [ebp-10h] BYREF
  float retaddr; // [esp+D8h] [ebp+0h]

  origin.y = a2;
  origin.z = retaddr;
  v29 = a4;
  v28 = a3;
  vForward.x = 0.0;
  if ( mp_forcecamera.m_pParent == nullptr || mp_forcecamera.m_pParent->m_Value.m_nValue == 0 )
  {
    LODWORD(vForward.x) = ((int (__thiscall *)(C_BasePlayer *, int, int))this->GetObserverTarget)(
                            a1: this,
                            a2: a3,
                            a3: v29);
    *eyeAngles = *this->EyeAngles(this);
  }
  GetDeathCamInterpolationTime = this->GetDeathCamInterpolationTime;
  origin.x = *(float *)(gpGlobals.m_Index + 12) - this->m_flDeathTime;
  v9 = ((double (__thiscall *)(C_BasePlayer *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, struct CBaseEntity *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, C_BaseEntity *, _DWORD))GetDeathCamInterpolationTime)(
         a1: this,
         a2: v28,
         a3: v29,
         a4: v30[0],
         a5: v30[1],
         a6: v30[2],
         a7: LODWORD(trace.startpos.x),
         a8: LODWORD(trace.startpos.y),
         a9: LODWORD(trace.startpos.z),
         a10: LODWORD(trace.endpos.x),
         a11: LODWORD(trace.endpos.y),
         a12: LODWORD(trace.endpos.z),
         a13: LODWORD(trace.plane.normal.x),
         a14: LODWORD(trace.plane.normal.y),
         a15: LODWORD(trace.plane.normal.z),
         a16: LODWORD(trace.plane.dist),
         a17: *(_DWORD *)&trace.plane.type,
         a18: LODWORD(trace.fraction),
         a19: trace.contents,
         a20: *(_DWORD *)&trace.dispFlags,
         a21: LODWORD(trace.fractionleftsolid),
         a22: trace.surface.name,
         a23: *(_DWORD *)&trace.surface.surfaceProps,
         a24: trace.hitgroup,
         a25: *(_DWORD *)&trace.physicsbone,
         a26: trace.m_pEnt,
         a27: trace.hitbox,
         a28: v32,
         a29: v33,
         a30: aKiller,
         a31: DWORD1(aKiller),
         a32: DWORD2(aKiller),
         a33: HIDWORD(aKiller),
         a34: v35,
         a35: v36,
         a36: LODWORD(v37.x),
         a37: LODWORD(v37.y),
         a38: LODWORD(v37.z),
         a39: LODWORD(aForward.x),
         a40: LODWORD(aForward.y),
         a41: LODWORD(aForward.z),
         a42: LODWORD(vKiller.x),
         a43: LODWORD(vKiller.y),
         a44: LODWORD(vKiller.z),
         a45: LODWORD(vForward.x),
         a46: LODWORD(vForward.y),
         a47: LODWORD(vForward.z),
         a48: pKiller,
         a49: LODWORD(origin.x));
  v10 = origin.x / v9;
  origin.x = v10;
  if ( v10 >= 0.0 )
  {
    x = origin.x;
    if ( origin.x > 1.0 )
    {
      origin.x = 1.0;
      goto LABEL_7;
    }
  }
  else
  {
    x = 0.0;
  }
  origin.x = x;
LABEL_7:
  v12 = (float)(*(float *)(gpGlobals.m_Index + 16) * 48.0) + this->m_flObserverChaseDistance;
  *(float *)&v13 = 16.0;
  this->m_flObserverChaseDistance = v12;
  if ( v12 < 16.0 || (*(float *)&v13 = 96.0, v12 > 96.0) )
    v12 = *(float *)&v13;
  v14 = this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  this->m_flObserverChaseDistance = v12;
  v15 = *(_QWORD *)&eyeAngles->x;
  v37.z = eyeAngles->z;
  EyePosition = v14->EyePosition;
  LODWORD(origin.x) = &vForward.y;
  *(_QWORD *)&v37.x = v15;
  ((void (__thiscall *)(C_BasePlayer *))EyePosition)(a1: this);
  v17 = this->GetRepresentativeRagdoll(this);
  if ( v17 != nullptr )
  {
    v18 = (int)v17->GetRagdollOrigin(this: v17);
    vForward.y = *(float *)v18;
    vForward.z = *(float *)(v18 + 4);
    pKiller = *(C_BaseEntity **)(v18 + 8);
    v19 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    *(float *)&pKiller = v19->m_vDeadViewHeight.z + *(float *)&pKiller;
  }
  if ( LODWORD(vForward.x) != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(vForward.x) + 584))(a1: LODWORD(vForward.x)) != 0
    && (C_BasePlayer *)LODWORD(vForward.x) != this )
  {
    v20 = (float *)(*(int (__thiscall **)(_DWORD, char *))(*(_DWORD *)LODWORD(vForward.x) + 624))(
                     a1: LODWORD(vForward.x),
                     a2: (char *)&aKiller + 4);
    aForward.x = *v20 - vForward.y;
    aForward.y = v20[1] - vForward.z;
    aForward.z = v20[2] - *(float *)&pKiller;
    VectorAngles(forward: (const Vector *)&aForward, angles: (QAngle *)&trace.hitbox);
    InterpolateAngles(start: &v37, end: (const QAngle *)&trace.hitbox, output: eyeAngles, frac: origin.x);
  }
  AngleVectors(angles: eyeAngles, forward: &vKiller);
  VectorNormalize(vec: &vKiller);
  LODWORD(v21) = LODWORD(this->m_flObserverChaseDistance) ^ _mask__NegFloat_;
  eyeOrigin->x = (float)(vKiller.x * v21) + vForward.y;
  eyeOrigin->y = (float)(vKiller.y * v21) + vForward.z;
  LOBYTE(vForward.x) = 0;
  eyeOrigin->z = (float)(vKiller.z * v21) + *(float *)&pKiller;
  C_BaseEntity::PushEnableAbsRecomputations(bEnable: SLOBYTE(vForward.x));
  UTIL_TraceHull(
    a1: (const IHandleEntity *)&origin.y,
    a2: (int)this,
    vecAbsStart: (Vector *)&vForward.y,
    vecAbsEnd: eyeOrigin,
    hullMin: &WALL_MIN,
    hullMax: &WALL_MAX,
    mask: 0x200400Bu,
    ignore: this,
    collisionGroup: 0,
    ptr: (CGameTrace *)v30);
  C_BaseEntity::PopEnableAbsRecomputations();
  if ( trace.plane.normal.z < 1.0 )
  {
    y = trace.startpos.y;
    z = trace.startpos.z;
    v24 = vForward.y - trace.startpos.x;
    eyeOrigin->x = trace.startpos.x;
    v25 = vForward.z - y;
    eyeOrigin->y = y;
    v26 = (float)((float)(v25 * v25) + (float)((float)(*(float *)&pKiller - z) * (float)(*(float *)&pKiller - z)))
        + (float)(v24 * v24);
    v27 = 0;
    eyeOrigin->z = z;
    *(float *)&v27 = fsqrt(v26);
    aKiller = v27;
    LODWORD(this->m_flObserverChaseDistance) = v27;
  }
  *fov = this->GetFOV(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005B6A0
// Name: public: class C_BaseViewModel __near * C_BasePlayer::GetViewModel(int)
// Source: json
//------------------------------------------------------------------------------
C_BaseViewModel *__thiscall C_BasePlayer::GetViewModel(C_BasePlayer *this, int index)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // ebx
  C_BaseEntity *v5; // eax
  C_BasePlayer *v6; // esi

  m_Index = this->m_hViewModel[index].m_Index;
  if ( m_Index == -1 )
  {
    m_pEntity = nullptr;
  }
  else if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  else
  {
    m_pEntity = nullptr;
  }
  if ( this->GetObserverMode(this) != 4 )
    return (C_BaseViewModel *)m_pEntity;
  v5 = this->GetObserverTarget(this);
  v6 = (C_BasePlayer *)v5;
  if ( v5 == nullptr || !v5->IsPlayer(this: v5) || v6 == this || v6->GetObserverMode(this: v6) != 0 )
    return (C_BaseViewModel *)m_pEntity;
  else
    return C_BasePlayer::GetViewModel(this: v6, index);
}

//------------------------------------------------------------------------------
// Address: 0x1005B760
// Name: public: virtual void C_BasePlayer::PhysicsSimulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::PhysicsSimulate(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  int v4; // eax
  C_BasePlayer_vtbl *v5; // edx
  bool v6; // zf

  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
      m_pEntity->__vftable[47].GetRefEHandle(this: m_pEntity);
  }
  v4 = *(_DWORD *)(gpGlobals.m_Index + 24);
  if ( this->m_nSimulationTick != v4 )
  {
    v5 = this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    this->m_nSimulationTick = v4;
    if ( v5->IsPlayer(this) && this->m_bIsLocalPlayer && this->m_CommandContext.needsprocessing )
    {
      this->m_CommandContext.needsprocessing = false;
      v6 = (this->m_fFlags & 0x40) == 0;
      this->m_bTouchedPhysObject = false;
      if ( !v6 )
      {
        this->m_CommandContext.cmd.forwardmove = 0.0;
        this->m_CommandContext.cmd.sidemove = 0.0;
        this->m_CommandContext.cmd.upmove = 0.0;
        this->m_CommandContext.cmd.buttons = 0;
        this->m_CommandContext.cmd.impulse = 0;
      }
      IMoveHelper::sm_pSingleton->SetHost(this: IMoveHelper::sm_pSingleton, a2: (struct CBaseEntity *)this);
      prediction->RunCommand(
        this: prediction,
        a2: this,
        a3: &this->m_CommandContext.cmd,
        a4: IMoveHelper::sm_pSingleton);
      C_BasePlayer::UpdateVPhysicsPosition(
        this,
        position: &this->m_vNewVPhysicsPosition,
        velocity: &this->m_vNewVPhysicsVelocity,
        secondsToArrival: *(float *)(gpGlobals.m_Index + 28));
      IMoveHelper::sm_pSingleton->SetHost(this: IMoveHelper::sm_pSingleton, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B880
// Name: public: virtual float C_BasePlayer::GetFOV(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BasePlayer::GetFOV(C_BasePlayer *this)
{
  C_BaseEntity *v2; // edi
  unsigned int m_Index; // ecx
  CEntInfo *v5; // eax
  float m_flVehicleViewFOV; // xmm0_4
  int m_iFOV; // eax
  float m_flFOVRate; // xmm1_4
  float val; // xmm0_4
  float deltaTime; // [esp+1Ch] [ebp-8h]
  float fFOV; // [esp+20h] [ebp-4h]

  if ( this->GetObserverMode(this) == 4 )
  {
    v2 = this->GetObserverTarget(this);
    if ( v2 != nullptr
      && v2->IsPlayer(this: v2)
      && v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetTeamNumber(this: v2) == 0 )
    {
      return ((float (__thiscall *)(C_BaseEntity *))v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].SetHealth)(a1: v2);
    }
  }
  m_Index = this->m_hVehicle.m_Index;
  if ( m_Index == -1
    || (v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index))
    || v5->m_pEntity == nullptr
    || ((int (__thiscall *)(IHandleEntity *))v5->m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: v5->m_pEntity) == 0
    || (C_BasePlayer::CacheVehicleView(this), (m_flVehicleViewFOV = this->m_flVehicleViewFOV) == 0.0) )
  {
    m_flVehicleViewFOV = (float)this->GetDefaultFOV(this);
  }
  m_iFOV = this->m_iFOV;
  if ( m_iFOV != 0 )
    m_flVehicleViewFOV = (float)m_iFOV;
  fFOV = m_flVehicleViewFOV;
  if ( !prediction->InPrediction(this: prediction)
    && this->IsPlayer(this)
    && this->m_bIsLocalPlayer
    && m_flVehicleViewFOV != (float)this->m_iFOVStart )
  {
    m_flFOVRate = this->m_Local.m_flFOVRate;
    if ( m_flFOVRate > 0.0 )
    {
      deltaTime = (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_flFOVTime) / m_flFOVRate;
      if ( C_BaseEntity::GetPredictable(this) )
        val = (float)((float)((float)((float)this->m_nFinalPredictedTick * *(float *)(gpGlobals.m_Index + 28))
                            - this->m_flFOVTime)
                    + (float)(*(float *)(gpGlobals.m_Index + 32) * *(float *)(gpGlobals.m_Index + 28)))
            / this->m_Local.m_flFOVRate;
      else
        val = deltaTime;
      if ( val >= 1.0 )
      {
        this->m_iFOVStart = (int)fFOV;
        return fFOV;
      }
      return (float)SimpleSplineRemapValClamped(val, A: 0.0, B: 1.0, C: (float)this->m_iFOVStart, D: fFOV);
    }
  }
  return fFOV;
}

//------------------------------------------------------------------------------
// Address: 0x1005BA90
// Name: public: void C_BasePlayer::NotePredictionError(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::NotePredictionError(C_BasePlayer *this, const Vector *vDelta)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  void (__thiscall *ResetLatched)(C_BaseEntity *); // eax
  Vector vOldDelta; // [esp+4h] [ebp-Ch] BYREF

  if ( this->IsAlive(this) )
  {
    C_BasePlayer::GetPredictionErrorSmoothingVector(this, vOffset: &vOldDelta);
    v3 = vDelta->y + vOldDelta.y;
    v4 = vDelta->z + vOldDelta.z;
    this->m_vecPredictionError.x = vDelta->x + vOldDelta.x;
    this->m_vecPredictionError.y = v3;
    this->m_vecPredictionError.z = v4;
    ResetLatched = this->ResetLatched;
    this->m_flPredictionErrorTime = *(float *)(gpGlobals.m_Index + 12);
    ResetLatched(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BB10
// Name: protected: void C_BasePlayer::ForceSetupBonesAtTimeFakeInterpolation(class matrix3x4a_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::ForceSetupBonesAtTimeFakeInterpolation(
        C_BasePlayer *this,
        matrix3x4a_t *pBonesOut,
        float curtimeOffset)
{
  float v4; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  Vector v7; // [esp+Ch] [ebp-20h] BYREF
  Vector origin; // [esp+18h] [ebp-14h] BYREF
  float cycle; // [esp+24h] [ebp-8h]
  float v10; // [esp+28h] [ebp-4h]

  cycle = this->m_flCycle.m_Val;
  origin = *C_BaseEntity::GetLocalOrigin(this);
  C_BaseAnimating::InvalidateBoneCache(this);
  ((void (__thiscall *)(C_BasePlayer *, _DWORD))this->Interpolate)(
    a1: this,
    a2: *(float *)(gpGlobals.m_Index + 12) + curtimeOffset);
  v4 = 1.0 - this->m_flFrozen;
  if ( v4 >= 0.0 )
  {
    if ( v4 <= 1.0 )
      v10 = 1.0 - this->m_flFrozen;
    else
      v10 = 1.0;
  }
  else
  {
    v10 = 0.0;
  }
  this->m_flCycle.m_Val = fmod(this->m_flPlaybackRate * v10 * curtimeOffset + cycle + 10.0, 1.0);
  y = this->m_vecVelocity.y;
  z = this->m_vecVelocity.z;
  v7.x = (float)(curtimeOffset * this->m_vecVelocity.x) + origin.x;
  v7.y = (float)(y * curtimeOffset) + origin.y;
  v7.z = origin.z + (float)(z * curtimeOffset);
  C_BaseEntity::SetLocalOrigin(this, origin: &v7);
  ((void (__stdcall *)(matrix3x4a_t *, int, int, _DWORD))this->SetupBones)(
    a1: pBonesOut,
    a2: 256,
    a3: 524032,
    a4: *(float *)(gpGlobals.m_Index + 12) + curtimeOffset);
  this->m_flCycle.m_Val = cycle;
  C_BaseEntity::SetLocalOrigin(this, &origin);
}

//------------------------------------------------------------------------------
// Address: 0x1005BC60
// Name: public: virtual void C_BasePlayer::GetRagdollInitBoneArrays(class matrix3x4a_t __near *,class matrix3x4a_t __near *,class matrix3x4a_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::GetRagdollInitBoneArrays(
        C_BasePlayer *this,
        matrix3x4a_t *pDeltaBones0,
        matrix3x4a_t *pDeltaBones1,
        matrix3x4a_t *pCurrentBones,
        float boneDt)
{
  float v6; // xmm1_4
  float ragdollCreateTime; // [esp+1Ch] [ebp+14h]

  if ( this != nullptr && this->IsPlayer(this) && this->m_bIsLocalPlayer )
  {
    C_BasePlayer::ForceSetupBonesAtTimeFakeInterpolation(
      this,
      pBonesOut: pDeltaBones0,
      curtimeOffset: COERCE_FLOAT(LODWORD(boneDt) ^ _mask__NegFloat_));
    C_BasePlayer::ForceSetupBonesAtTimeFakeInterpolation(this, pBonesOut: pDeltaBones1, curtimeOffset: 0.0);
    ragdollCreateTime = PhysGetSyncCreateTime();
    v6 = *(float *)(gpGlobals.m_Index + 12);
    if ( ragdollCreateTime == v6 )
      ((void (__stdcall *)(matrix3x4a_t *, int, int, _DWORD))this->SetupBones)(
        a1: pCurrentBones,
        a2: 256,
        a3: 524032,
        a4: *(_DWORD *)(gpGlobals.m_Index + 12));
    else
      C_BasePlayer::ForceSetupBonesAtTimeFakeInterpolation(
        this,
        pBonesOut: pCurrentBones,
        curtimeOffset: ragdollCreateTime - v6);
  }
  else
  {
    C_BaseAnimating::GetRagdollInitBoneArrays(this, pDeltaBones0, pDeltaBones1, pCurrentBones, boneDt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BD40
// Name: public: virtual bool C_BasePlayer::ShouldShowVOIPIcon(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BasePlayer::ShouldShowVOIPIcon(C_BasePlayer *this)
{
  return g_pGameRules != nullptr
      && g_pGameRules->IsMultiplayer(this: g_pGameRules)
      && (this == nullptr
       || !this->IsPlayer(this)
       || !this->m_bIsLocalPlayer
       || voice_all_icons.m_pParent != nullptr && voice_all_icons.m_pParent->m_Value.m_nValue != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005BDA0
// Name: void CC_DumpClientSoundscapeData(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_DumpClientSoundscapeData()
{
  C_BasePlayer *v0; // esi
  float *v1; // ebx
  int v2; // eax
  int v3; // eax
  int v4; // ebx
  double v5; // [esp+10h] [ebp-2Ch]
  int v6; // [esp+30h] [ebp-Ch]
  float *p_localSound; // [esp+34h] [ebp-8h]
  bool bFoundOne; // [esp+3Bh] [ebp-1h]

  v0 = s_pLocalPlayer[0];
  if ( s_pLocalPlayer[0] != nullptr )
  {
    _Msg(a1: "Client Soundscape data dump:\n");
    v1 = (float *)v0->GetAbsOrigin(this: v0);
    v2 = (int)v0->GetAbsOrigin(this: v0);
    v3 = ((int (__thiscall *)(C_BasePlayer *, _DWORD, _DWORD))v0->GetAbsOrigin)(
           a1: v0,
           a2: COERCE_UNSIGNED_INT64(*(float *)(v2 + 8)),
           a3: HIDWORD(COERCE_UNSIGNED_INT64(*(float *)(v2 + 8))));
    _Msg(a1: "   Position: %.2f %.2f %.2f\n", *v1, *(float *)(v3 + 4), v5);
    _Msg(a1: "   soundscape index: %d\n", v0->m_Local.m_audio.soundscapeIndex.m_Value);
    _Msg(a1: "   entity index: %d\n", v0->m_Local.m_audio.entIndex.m_Value);
    bFoundOne = false;
    v4 = 0;
    v6 = 1;
    p_localSound = (float *)&v0->m_Local.m_audio.localSound;
    do
    {
      if ( (v6 & v0->m_Local.m_audio.localBits.m_Value) != 0 )
      {
        if ( !bFoundOne )
        {
          _Msg(a1: "   Sound Positions:\n");
          bFoundOne = true;
        }
        _Msg(a1: "   %d: %.2f %.2f %.2f\n", v4, *p_localSound, p_localSound[1], p_localSound[2]);
      }
      p_localSound += 3;
      ++v4;
      v6 = __ROL4__(v6, 1);
    }
    while ( v4 < 8 );
    _Msg(a1: "End dump.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BEE0
// Name: public: void CountdownTimer::Invalidate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CountdownTimer::Invalidate(CountdownTimer *this)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi

  p_m_timestamp = &this->m_timestamp;
  if ( this->m_timestamp.m_Value != -1.0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_timestamp);
    p_m_timestamp->m_Value = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BF10
// Name: public: fogplayerparams_t::fogplayerparams_t(void)
// Source: json
//------------------------------------------------------------------------------
fogplayerparams_t *__thiscall fogplayerparams_t::fogplayerparams_t(fogplayerparams_t *this)
{
  CNetworkHandleBase<C_FogController,fogplayerparams_t::NetworkVar_m_hCtrl> *p_m_hCtrl; // edi
  unsigned int m_Index; // eax

  p_m_hCtrl = &this->m_hCtrl;
  this->__vftable = (fogplayerparams_t_vtbl *)&fogplayerparams_t::`vftable';
  this->m_hCtrl.m_Value.m_Index = -1;
  m_Index = this->m_hCtrl.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    this->NetworkStateChanged(this, a2: &this->m_hCtrl);
    p_m_hCtrl->m_Value.m_Index = -1;
  }
  this->m_flTransitionTime = -1.0;
  this->m_OldColor.a = 0;
  *(_WORD *)&this->m_OldColor.r = 0;
  this->m_NewColor.a = 0;
  *(_WORD *)&this->m_NewColor.r = 0;
  this->m_flOldStart = 0.0;
  this->m_flOldEnd = 0.0;
  this->m_flOldMaxDensity = 1.0;
  this->m_flOldHDRColorScale = 1.0;
  this->m_flOldFarZ = 0.0;
  this->m_flNewStart = 0.0;
  this->m_flNewEnd = 0.0;
  this->m_flNewMaxDensity = 1.0;
  this->m_flNewHDRColorScale = 1.0;
  this->m_flNewFarZ = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005BFC0
// Name: UpdateViewmodelVisibility
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateViewmodelVisibility(C_BasePlayer *player)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  C_BaseViewModel *ViewModel; // edi
  C_BasePlayer *v4; // esi
  CHandle<C_BaseViewModel> *m_hViewModel; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  i = 0;
  m_hViewModel = player->m_hViewModel;
  do
  {
    m_Index = m_hViewModel->m_Index;
    if ( m_hViewModel->m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    ViewModel = (C_BaseViewModel *)m_pEntity;
    if ( player->GetObserverMode(this: player) == 4 )
    {
      v4 = (C_BasePlayer *)player->GetObserverTarget(this: player);
      if ( v4 != nullptr && v4->IsPlayer(this: v4) && v4 != player && v4->GetObserverMode(this: v4) == 0 )
        ViewModel = C_BasePlayer::GetViewModel(this: v4, index: i);
    }
    if ( ViewModel != nullptr )
      C_BaseEntity::UpdateVisibility(this: ViewModel);
    ++m_hViewModel;
    ++i;
  }
  while ( i < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x1005C090
// Name: public: void C_BasePlayer::SetObserverTarget(class CHandle<class C_BaseEntity>)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SetObserverTarget(C_BasePlayer *this, CHandle<C_BaseEntity> hObserverTarget)
{
  unsigned int m_Index; // ecx
  C_BasePlayer **v4; // eax
  C_BasePlayer *v5; // edi
  int m_Index_low; // edx
  int v7; // ecx
  int v8; // ecx
  IGameEvent *v9; // eax

  m_Index = this->m_hObserverTarget.m_Index;
  if ( m_Index == -1
    || (v4 = (C_BasePlayer **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index))
    || (v5 = *v4, *v4 == nullptr)
    || !v5->IsPlayer(this: v5) )
  {
    v5 = nullptr;
  }
  if ( hObserverTarget.m_Index == -1 )
    m_Index_low = 0x1FFF;
  else
    m_Index_low = LOWORD(hObserverTarget.m_Index);
  if ( this->m_hObserverTarget.m_Index == -1 )
    v7 = 0x1FFF;
  else
    v7 = (unsigned __int16)this->m_hObserverTarget.m_Index;
  if ( m_Index_low != v7 || ((hObserverTarget.m_Index ^ this->m_hObserverTarget.m_Index) & 0xFFFF0000) != 0 )
  {
    if ( hObserverTarget.m_Index == -1 )
      v8 = 0x1FFF;
    else
      v8 = LOWORD(hObserverTarget.m_Index);
    this->m_hObserverTarget.m_Index = v8 | hObserverTarget.m_Index & 0xFFFF0000;
    v9 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "spec_target_updated", a3: 0, a4: 0);
    if ( v9 != nullptr )
      gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v9);
    if ( this->IsPlayer(this) && this->m_bIsLocalPlayer )
      ResetToneMapping(flTonemappingScale: -1.0);
    UpdateViewmodelVisibility(player: this);
    C_BaseEntity::UpdateVisibility(this);
  }
  if ( v5 != nullptr )
    UpdateViewmodelVisibility(player: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1005C1C0
// Name: public: void C_BasePlayer::UpdateFlashlight(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UpdateFlashlight(C_BasePlayer *this)
{
  C_BasePlayer *v2; // esi
  CFlashlightEffectManager *v3; // eax
  CFlashlightEffect **p_m_pFlashlightEffect; // ebx
  bool v5; // zf
  CFlashlightEffect *v6; // ecx
  int index; // ebx
  int v8; // eax
  const char *v9; // ebx
  CFlashlightEffectManager *v10; // eax
  const Vector *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  CFlashlightEffectManager *v14; // eax
  int v15; // [esp+0h] [ebp-54h]
  float v16; // [esp+0h] [ebp-54h]
  const char *v17; // [esp+4h] [ebp-50h]
  bool v18; // [esp+4h] [ebp-50h]
  float flFov; // [esp+8h] [ebp-4Ch]
  float flFova; // [esp+8h] [ebp-4Ch]
  float flFarZ; // [esp+Ch] [ebp-48h]
  float flFarZa; // [esp+Ch] [ebp-48h]
  float flLinearAtten; // [esp+10h] [ebp-44h]
  const char *flLinearAttena; // [esp+10h] [ebp-44h]
  Vector vecForward; // [esp+20h] [ebp-34h] BYREF
  Vector vecRight; // [esp+2Ch] [ebp-28h] BYREF
  Vector vecUp; // [esp+38h] [ebp-1Ch] BYREF
  Vector vecPos; // [esp+44h] [ebp-10h] BYREF
  void *pMem; // [esp+50h] [ebp-4h]

  v2 = this;
  if ( ((unsigned __int8 (__fastcall *)(C_BasePlayer *))this->IsAlive)(a1: this) == 0
    && this->GetObserverMode(this) == 4 )
  {
    v2 = (C_BasePlayer *)this->GetObserverTarget(this);
    if ( v2 == nullptr || !v2->IsPlayer(this: v2) )
    {
      v2 = nullptr;
      goto LABEL_6;
    }
  }
  if ( v2 == nullptr
    || (index = v2->index,
        FlashlightEffectManager(nSplitscreenPlayerOverride: -1)->m_nFlashlightEntIndex = index,
        !v2->IsAlive(this: v2))
    || (v2->m_fEffects & 4) == 0
    || C_BasePlayer::GetViewEntity(this: v2) != nullptr )
  {
LABEL_6:
    if ( this->m_bFlashlightEnabled[0] )
    {
      v3 = FlashlightEffectManager(nSplitscreenPlayerOverride: -1);
      p_m_pFlashlightEffect = &v3->m_pFlashlightEffect;
      v5 = !v3->m_bFlashlightOverride;
      v3->m_pFlashlightTextureName = nullptr;
      v3->m_bFlashlightOn = false;
      if ( v5
        && v3->m_nMuzzleFlashFrameCountdown == 0
        && CountdownTimer::Now(this: (CEffectsClient *)&v3->m_muzzleFlashTimer) > (double)v3->m_muzzleFlashTimer.m_timestamp.m_Value )
      {
        v6 = *p_m_pFlashlightEffect;
        pMem = v6;
        if ( v6 != nullptr )
        {
          CFlashlightEffect::~CFlashlightEffect(this: v6);
          C_BaseEntity::operator delete(pMem);
        }
        *p_m_pFlashlightEffect = nullptr;
      }
      this->m_bFlashlightEnabled[0] = false;
    }
    goto LABEL_14;
  }
  v8 = (int)v2->GetFlashlightTextureName(this: v2);
  v9 = (const char *)v8;
  if ( !this->m_bFlashlightEnabled[0] )
  {
    if ( v8 != 0 )
    {
      flLinearAtten = v2->GetFlashlightLinearAtten(this: v2);
      flFarZ = v2->GetFlashlightFarZ(this: v2);
      flFov = v2->GetFlashlightFOV(this: v2);
      v17 = v9;
    }
    else
    {
      flLinearAtten = 0.0;
      flFarZ = 0.0;
      flFov = 0.0;
      v17 = nullptr;
    }
    v15 = v2->index;
    v10 = FlashlightEffectManager(nSplitscreenPlayerOverride: -1);
    CFlashlightEffectManager::TurnOnFlashlight(
      this: v10,
      nEntIndex: v15,
      pszTextureName: v17,
      flFov,
      flFarZ,
      flLinearAtten);
    this->m_bFlashlightEnabled[0] = true;
  }
LABEL_14:
  if ( v2 != nullptr && this->m_bFlashlightEnabled[0] )
  {
    pMem = (void *)LODWORD(v2->m_vecFlashlightOrigin.x);
    if ( vec3_origin.x == *(float *)&pMem
      && vec3_origin.y == v2->m_vecFlashlightOrigin.y
      && vec3_origin.z == v2->m_vecFlashlightOrigin.z
      || !Vector::IsValid(this: &v2->m_vecFlashlightOrigin) )
    {
      C_BasePlayer::EyeVectors(this, pForward: &vecForward, pRight: &vecRight, pUp: &vecUp);
      v11 = this->GetRenderOrigin(this: &this->IClientRenderable);
      v12 = this->m_vecViewOffset.y + v11->y;
      v13 = this->m_vecViewOffset.z + v11->z;
      vecPos.x = v11->x + this->m_vecViewOffset.x;
      vecPos.y = v12;
      vecPos.z = v13;
    }
    else
    {
      LODWORD(vecPos.x) = pMem;
      vecPos.y = v2->m_vecFlashlightOrigin.y;
      vecPos.z = v2->m_vecFlashlightOrigin.z;
      vecForward = v2->m_vecFlashlightForward;
      vecRight = v2->m_vecFlashlightRight;
      vecUp = v2->m_vecFlashlightUp;
    }
    flLinearAttena = v2->GetFlashlightTextureName(this: v2);
    flFarZa = v2->GetFlashlightLinearAtten(this: v2);
    flFova = v2->GetFlashlightFarZ(this: v2);
    v18 = v2->CastsFlashlightShadows(this: v2);
    v16 = v2->GetFlashlightFOV(this: v2);
    v14 = FlashlightEffectManager(nSplitscreenPlayerOverride: -1);
    CFlashlightEffectManager::UpdateFlashlight(
      this: v14,
      &vecPos,
      vecDir: &vecForward,
      &vecRight,
      &vecUp,
      flFov: v16,
      castsShadows: v18,
      flFarZ: flFova,
      flLinearAtten: flFarZa,
      pTextureName: flLinearAttena);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C540
// Name: public: virtual class C_BaseAnimating __near * C_BasePlayer::GetRenderedWeaponModel(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_BasePlayer::GetRenderedWeaponModel(C_BasePlayer *this)
{
  if ( input->CAM_IsThirdPerson(this: input, a2: -1) != 0
    || ToolsEnabled() && ToolFramework_IsThirdPersonCamera()
    || this == nullptr
    || !this->IsPlayer(this)
    || !this->m_bIsLocalPlayer )
  {
    return this->GetActiveWeapon(this);
  }
  else
  {
    return (C_BaseCombatWeapon *)C_BasePlayer::GetViewModel(this, index: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C5A0
// Name: public: void C_BasePlayer::SetPunchAngle(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SetPunchAngle(C_BasePlayer *this, const QAngle *angle)
{
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *p_m_vecPunchAngle; // esi

  p_m_vecPunchAngle = &this->m_Local.m_vecPunchAngle;
  if ( angle->x != this->m_Local.m_vecPunchAngle.m_Value.x
    || angle->y != this->m_Local.m_vecPunchAngle.m_Value.y
    || angle->z != this->m_Local.m_vecPunchAngle.m_Value.z )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: p_m_vecPunchAngle);
    p_m_vecPunchAngle->m_Value = *angle;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C600
// Name: public: static void C_BasePlayer::RecvProxy_ObserverMode(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BasePlayer::RecvProxy_ObserverMode(const CRecvProxyData *pData, C_BasePlayer *pStruct, void *pOut)
{
  int v3; // eax
  C_BasePlayer *v4; // esi

  RecvProxy_Int32ToInt32(pData, pStruct, pOut);
  if ( pStruct != nullptr && pStruct->IsPlayer(this: pStruct) && pStruct->m_bIsLocalPlayer )
  {
    C_BaseEntity::UpdateVisibility(this: pStruct);
    UpdateViewmodelVisibility(player: pStruct);
  }
  v3 = (int)pStruct->GetObserverTarget(this: pStruct);
  v4 = (C_BasePlayer *)v3;
  if ( v3 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 584))(a1: v3) != 0 )
    UpdateViewmodelVisibility(player: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1005C680
// Name: public: static void C_BasePlayer::RecvProxy_ObserverTarget(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BasePlayer::RecvProxy_ObserverTarget(const CRecvProxyData *pData, C_BasePlayer *pStruct)
{
  CHandle<C_BaseEntity> hTarget; // [esp+4h] [ebp-4h] BYREF

  hTarget.m_Index = -1;
  RecvProxy_IntToEHandle(pData, pStruct, pOut: (void *)&hTarget);
  C_BasePlayer::SetObserverTarget(this: pStruct, hObserverTarget: hTarget);
}

//------------------------------------------------------------------------------
// Address: 0x1005C6C0
// Name: public: void C_BasePlayer::UpdateFogBlend(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UpdateFogBlend(C_BasePlayer *this)
{
  float m_flTransitionTime; // xmm0_4
  float v3; // xmm1_4
  float m_Value; // xmm0_4
  CNetworkColor32Base<color32_s,fogparams_t::NetworkVar_colorPrimary> *p_colorPrimary; // edi
  float v6; // xmm1_4
  float v7; // xmm0_4
  int v8; // ebx
  int v9; // ebx
  int v10; // ebx
  float m_flNewFarZ; // xmm2_4
  float m_flOldFarZ; // xmm3_4
  CNetworkVarBase<float,fogparams_t::NetworkVar_farz> *p_farz; // esi
  float v14; // xmm0_4
  unsigned __int8 r; // bl
  unsigned __int8 g; // bl
  unsigned __int8 b; // bl
  float v18; // [esp+4h] [ebp-Ch]
  float v19; // [esp+4h] [ebp-Ch]
  float v20; // [esp+4h] [ebp-Ch]
  float v21; // [esp+4h] [ebp-Ch]

  m_flTransitionTime = this->m_PlayerFog.m_flTransitionTime;
  if ( m_flTransitionTime != -1.0 )
  {
    v3 = *(float *)(gpGlobals.m_Index + 12) - m_flTransitionTime;
    m_Value = this->m_CurrentFog.duration.m_Value;
    p_colorPrimary = &this->m_CurrentFog.colorPrimary;
    if ( m_Value <= v3 )
    {
      r = this->m_PlayerFog.m_NewColor.r;
      if ( p_colorPrimary->m_Value.r != r )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.colorPrimary);
        p_colorPrimary->m_Value.r = r;
      }
      g = this->m_PlayerFog.m_NewColor.g;
      if ( this->m_CurrentFog.colorPrimary.m_Value.g != g )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.colorPrimary);
        this->m_CurrentFog.colorPrimary.m_Value.g = g;
      }
      b = this->m_PlayerFog.m_NewColor.b;
      if ( this->m_CurrentFog.colorPrimary.m_Value.b != b )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.colorPrimary);
        this->m_CurrentFog.colorPrimary.m_Value.b = b;
      }
      if ( this->m_CurrentFog.start.m_Value != this->m_PlayerFog.m_flNewStart )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.start);
        this->m_CurrentFog.start.m_Value = this->m_PlayerFog.m_flNewStart;
      }
      if ( this->m_CurrentFog.end.m_Value != this->m_PlayerFog.m_flNewEnd )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.end);
        this->m_CurrentFog.end.m_Value = this->m_PlayerFog.m_flNewEnd;
      }
      if ( this->m_CurrentFog.maxdensity.m_Value != this->m_PlayerFog.m_flNewMaxDensity )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.maxdensity);
        this->m_CurrentFog.maxdensity.m_Value = this->m_PlayerFog.m_flNewMaxDensity;
      }
      if ( this->m_CurrentFog.HDRColorScale.m_Value != this->m_PlayerFog.m_flNewHDRColorScale )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.HDRColorScale);
        this->m_CurrentFog.HDRColorScale.m_Value = this->m_PlayerFog.m_flNewHDRColorScale;
      }
      if ( this->m_CurrentFog.farz.m_Value != this->m_PlayerFog.m_flNewFarZ )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.farz);
        this->m_CurrentFog.farz.m_Value = this->m_PlayerFog.m_flNewFarZ;
      }
      this->m_PlayerFog.m_flTransitionTime = -1.0;
    }
    else
    {
      v6 = v3 / m_Value;
      v7 = 1.0 - v6;
      v8 = (int)(float)((float)((float)this->m_PlayerFog.m_OldColor.r * (float)(1.0 - v6))
                      + (float)((float)this->m_PlayerFog.m_NewColor.r * v6));
      if ( p_colorPrimary->m_Value.r != (_BYTE)v8 )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.colorPrimary);
        v7 = 1.0 - v6;
        p_colorPrimary->m_Value.r = v8;
      }
      v9 = (int)(float)((float)((float)this->m_PlayerFog.m_OldColor.g * v7)
                      + (float)((float)this->m_PlayerFog.m_NewColor.g * v6));
      if ( this->m_CurrentFog.colorPrimary.m_Value.g != (_BYTE)v9 )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.colorPrimary);
        v7 = 1.0 - v6;
        this->m_CurrentFog.colorPrimary.m_Value.g = v9;
      }
      v10 = (int)(float)((float)((float)this->m_PlayerFog.m_OldColor.b * v7)
                       + (float)((float)this->m_PlayerFog.m_NewColor.b * v6));
      if ( this->m_CurrentFog.colorPrimary.m_Value.b != (_BYTE)v10 )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.colorPrimary);
        v7 = 1.0 - v6;
        this->m_CurrentFog.colorPrimary.m_Value.b = v10;
      }
      v18 = (float)(this->m_PlayerFog.m_flOldStart * v7) + (float)(this->m_PlayerFog.m_flNewStart * v6);
      if ( this->m_CurrentFog.start.m_Value != v18 )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.start);
        this->m_CurrentFog.start.m_Value = v18;
        v7 = 1.0 - v6;
      }
      v19 = (float)(this->m_PlayerFog.m_flOldEnd * v7) + (float)(this->m_PlayerFog.m_flNewEnd * v6);
      if ( this->m_CurrentFog.end.m_Value != v19 )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.end);
        this->m_CurrentFog.end.m_Value = v19;
        v7 = 1.0 - v6;
      }
      v20 = (float)(this->m_PlayerFog.m_flOldMaxDensity * v7) + (float)(this->m_PlayerFog.m_flNewMaxDensity * v6);
      if ( this->m_CurrentFog.maxdensity.m_Value != v20 )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.maxdensity);
        this->m_CurrentFog.maxdensity.m_Value = v20;
        v7 = 1.0 - v6;
      }
      v21 = (float)(this->m_PlayerFog.m_flOldHDRColorScale * v7) + (float)(v6 * this->m_PlayerFog.m_flNewHDRColorScale);
      if ( this->m_CurrentFog.HDRColorScale.m_Value != v21 )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.HDRColorScale);
        this->m_CurrentFog.HDRColorScale.m_Value = v21;
        v7 = 1.0 - v6;
      }
      m_flNewFarZ = this->m_PlayerFog.m_flNewFarZ;
      if ( m_flNewFarZ <= 0.0 )
        m_flNewFarZ = r_mapextents.m_pParent->m_Value.m_fValue * 1.7320508;
      m_flOldFarZ = this->m_PlayerFog.m_flOldFarZ;
      if ( m_flOldFarZ <= 0.0 )
        m_flOldFarZ = r_mapextents.m_pParent->m_Value.m_fValue * 1.7320508;
      p_farz = &this->m_CurrentFog.farz;
      v14 = (float)(v7 * m_flOldFarZ) + (float)(m_flNewFarZ * v6);
      if ( p_farz->m_Value != v14 )
      {
        (*(void (__thiscall **)(int, CNetworkVarBase<float,fogparams_t::NetworkVar_farz> *))LODWORD(p_farz[-10].m_Value))(
          a1: (int)&p_farz[-10],
          a2: p_farz);
        p_farz->m_Value = v14;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CB20
// Name: public: virtual bool C_BasePlayer::PreRender(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::PreRender(C_BasePlayer *this, int nSplitScreenPlayerSlot)
{
  IClientMode *ClientMode; // eax
  bool result; // al

  result = this->m_hRender == 0xFFFF
        || (this->m_VisibilityBits.m_Ints[0] & 1) == 0
        || (ClientMode = GetClientMode(), !ClientMode->ShouldDrawLocalPlayer(this: ClientMode, a2: this))
        || this->CreateLightEffects(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005CB70
// Name: public: struct fogparams_t __near & fogparams_t::operator=(struct fogparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
fogparams_t *__thiscall fogparams_t::operator=(fogparams_t *this, const fogparams_t *__that)
{
  CNetworkVectorBase<Vector,fogparams_t::NetworkVar_dirPrimary> *p_dirPrimary; // edi

  p_dirPrimary = &this->dirPrimary;
  if ( __that->dirPrimary.m_Value.x != this->dirPrimary.m_Value.x
    || __that->dirPrimary.m_Value.y != this->dirPrimary.m_Value.y
    || __that->dirPrimary.m_Value.z != this->dirPrimary.m_Value.z )
  {
    this->NetworkStateChanged(this, a2: &this->dirPrimary);
    *p_dirPrimary = __that->dirPrimary;
  }
  if ( this->colorPrimary.m_Value.r != __that->colorPrimary.m_Value.r
    || this->colorPrimary.m_Value.g != __that->colorPrimary.m_Value.g
    || this->colorPrimary.m_Value.b != __that->colorPrimary.m_Value.b
    || this->colorPrimary.m_Value.a != __that->colorPrimary.m_Value.a )
  {
    this->NetworkStateChanged(this, a2: &this->colorPrimary);
    this->colorPrimary = __that->colorPrimary;
  }
  if ( this->colorSecondary.m_Value.r != __that->colorSecondary.m_Value.r
    || this->colorSecondary.m_Value.g != __that->colorSecondary.m_Value.g
    || this->colorSecondary.m_Value.b != __that->colorSecondary.m_Value.b
    || this->colorSecondary.m_Value.a != __that->colorSecondary.m_Value.a )
  {
    this->NetworkStateChanged(this, a2: &this->colorSecondary);
    this->colorSecondary = __that->colorSecondary;
  }
  if ( this->colorPrimaryLerpTo.m_Value.r != __that->colorPrimaryLerpTo.m_Value.r
    || this->colorPrimaryLerpTo.m_Value.g != __that->colorPrimaryLerpTo.m_Value.g
    || this->colorPrimaryLerpTo.m_Value.b != __that->colorPrimaryLerpTo.m_Value.b
    || this->colorPrimaryLerpTo.m_Value.a != __that->colorPrimaryLerpTo.m_Value.a )
  {
    this->NetworkStateChanged(this, a2: &this->colorPrimaryLerpTo);
    this->colorPrimaryLerpTo = __that->colorPrimaryLerpTo;
  }
  if ( this->colorSecondaryLerpTo.m_Value.r != __that->colorSecondaryLerpTo.m_Value.r
    || this->colorSecondaryLerpTo.m_Value.g != __that->colorSecondaryLerpTo.m_Value.g
    || this->colorSecondaryLerpTo.m_Value.b != __that->colorSecondaryLerpTo.m_Value.b
    || this->colorSecondaryLerpTo.m_Value.a != __that->colorSecondaryLerpTo.m_Value.a )
  {
    this->NetworkStateChanged(this, a2: &this->colorSecondaryLerpTo);
    this->colorSecondaryLerpTo = __that->colorSecondaryLerpTo;
  }
  this->start.m_Value = __that->start.m_Value;
  this->end.m_Value = __that->end.m_Value;
  this->farz.m_Value = __that->farz.m_Value;
  this->maxdensity.m_Value = __that->maxdensity.m_Value;
  this->startLerpTo.m_Value = __that->startLerpTo.m_Value;
  this->endLerpTo.m_Value = __that->endLerpTo.m_Value;
  this->maxdensityLerpTo.m_Value = __that->maxdensityLerpTo.m_Value;
  this->lerptime.m_Value = __that->lerptime.m_Value;
  this->duration.m_Value = __that->duration.m_Value;
  this->enable.m_Value = __that->enable.m_Value;
  this->blend.m_Value = __that->blend.m_Value;
  this->HDRColorScale.m_Value = __that->HDRColorScale.m_Value;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005D0C0
// Name: public: virtual void C_BasePlayer::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::PostDataUpdate(C_BasePlayer *this, DataUpdateType_t updateType)
{
  int v2; // ebx
  int v4; // edi
  bool v5; // al
  char *v6; // edi
  float *v7; // ebx
  const Vector *NetworkOrigin; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  IUniformRandomStream *m_Index; // ecx
  IUniformRandomStream *v12; // ecx
  IGameEvent *v13; // ebx
  int v14; // eax
  int v15; // eax
  const Vector *v16; // eax
  void (__thiscall *SetValue_4)(IConVar *, const char *); // eax
  char v18; // bl
  ConVar *v19; // eax
  IGameEvent *v20; // eax
  QAngle angles; // [esp+20h] [ebp-14h] BYREF
  float flTimeDelta; // [esp+2Ch] [ebp-8h]
  bool bForceEFNoInterp; // [esp+33h] [ebp-1h]
  void (__thiscall **bHideFreezePanel)(IGameEvent *, const char *, const Vector *); // [esp+3Ch] [ebp+8h]

  v2 = -1;
  v4 = 0;
  while ( engine->GetSplitScreenPlayer(this: engine, a2: v4) != DWORD2(this->m_pfnTouch) )
  {
    if ( ++v4 != 0 )
      goto LABEL_6;
  }
  v2 = v4;
LABEL_6:
  v5 = false;
  if ( v2 != -1 )
    v5 = s_pLocalPlayer[v2] == nullptr;
  if ( updateType == DATA_UPDATE_CREATED || v5 )
    C_BasePlayer::CheckForLocalPlayer(this: (C_BasePlayer *)((char *)this - 8), nSplitScreenSlot: v2);
  v6 = (char *)this - 8;
  bForceEFNoInterp = this->m_bSentFreezeFrame != this->m_chTextureType;
  if ( this != (C_BasePlayer *)8
    && (*(unsigned __int8 (__thiscall **)(char *))(*(_DWORD *)v6 + 584))(a1: (char *)this - 8) != 0
    && v6[6276] != 0 )
  {
    if ( v6[2346] != 1 )
    {
      v6[2346] = 1;
      C_BaseEntity::Interp_UpdateInterpolationAmounts(
        this: (C_BasePlayer *)((char *)this - 8),
        map: (VarMapping_t *)(v6 + 32));
    }
  }
  else
  {
    if ( v6[2346] != 0 )
    {
      v6[2346] = 0;
      C_BaseEntity::Interp_UpdateInterpolationAmounts(
        this: (C_BasePlayer *)((char *)this - 8),
        map: (VarMapping_t *)(v6 + 32));
    }
    flTimeDelta = this->m_flAnimTime - this->m_flOldAnimTime;
    if ( C_BaseEntity::IsParentChanging(this: (C_BasePlayer *)((char *)this - 8)) )
      bForceEFNoInterp = true;
    if ( flTimeDelta > 0.0 && (this->m_iEFlags & 8) == 0 && !bForceEFNoInterp )
    {
      v7 = (float *)(*(int (__thiscall **)(char *))(*(_DWORD *)v6 + 380))(a1: (char *)this - 8);
      NetworkOrigin = C_BaseEntity::GetNetworkOrigin(this: (C_BasePlayer *)((char *)this - 8));
      v9 = (float)(NetworkOrigin->y - v7[1]) * (float)(1.0 / flTimeDelta);
      v10 = (float)(NetworkOrigin->z - v7[2]) * (float)(1.0 / flTimeDelta);
      angles.x = (float)(1.0 / flTimeDelta) * (float)(NetworkOrigin->x - *v7);
      angles.y = v9;
      angles.z = v10;
      C_BaseEntity::SetLocalVelocity(this: (C_BasePlayer *)((char *)this - 8), vecVelocity: (const Vector *)&angles);
    }
  }
  C_BaseAnimating::PostDataUpdate(this, updateType);
  if ( this != (C_BasePlayer *)8
    && (*(unsigned __int8 (__thiscall **)(char *))(*(_DWORD *)v6 + 584))(a1: (char *)this - 8) != 0
    && v6[6276] != 0 )
  {
    engine->GetViewAngles(this: engine, a2: &angles);
    if ( updateType == DATA_UPDATE_CREATED )
    {
      (*(void (__thiscall **)(char *, QAngle *))(*(_DWORD *)v6 + 1304))(a1: (char *)this - 8, a2: &angles);
      *(float *)&this->m_SimulatedByThisPlayer.m_Size = C_BaseEntity::GetLocalOrigin(this: (C_BasePlayer *)((char *)this - 8))->z;
    }
    C_BaseEntity::SetLocalAngles(this: (C_BasePlayer *)((char *)this - 8), &angles);
    if ( LOBYTE(this->m_flFreezeFrameStartTime) == 0 )
    {
      if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v6 + 1020))(a1: (char *)this - 8) == 2 )
      {
        *(Vector *)&this->m_hObserverTarget.m_Index = *MainViewOrigin(nSlot: this->m_hPipPlayers.m_Size);
        m_Index = (IUniformRandomStream *)gpGlobals.m_Index;
        this->m_vecFreezeFrameStart.y = *(float *)(gpGlobals.m_Index + 12);
        this->m_vecFreezeFrameStart.z = _RandomFloat(
                                          this: m_Index,
                                          a2: spec_freeze_distance_min.m_pParent->m_Value.m_fValue,
                                          a3: spec_freeze_distance_max.m_pParent->m_Value.m_fValue);
        *(float *)&this->m_pSurfaceData = _RandomFloat(this: v12, a2: -30.0, a3: 20.0);
        BYTE1(this->m_surfaceProps) = 0;
        v13 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "show_freezepanel", a3: 0, a4: 0);
        if ( v13 != nullptr )
        {
          if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v6 + 1024))(a1: (char *)this - 8) != 0 )
          {
            v14 = (*(int (__thiscall **)(char *))(*(_DWORD *)v6 + 1024))(a1: (char *)this - 8);
            v15 = (*(int (__thiscall **)(int))(*(_DWORD *)(v14 + 8) + 40))(a1: v14 + 8);
          }
          else
          {
            v15 = 0;
          }
          v13->SetInt(this: v13, a2: "killer", a3: v15);
          bHideFreezePanel = (void (__thiscall **)(IGameEvent *, const char *, const Vector *))&v13->SetInt;
          v16 = this->GetAbsOrigin(this);
          (*bHideFreezePanel)(a1: v13, a2: "victim", a3: v16);
          gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v13);
        }
        SetValue_4 = cvar->FindVar_2(this: cvar, a2: "snd_soundmixer")->SetValue_4;
        ((void (__cdecl *)(const char *))SetValue_4)(a1: "FreezeCam_Only");
        goto LABEL_45;
      }
      if ( LOBYTE(this->m_flFreezeFrameStartTime) == 0 )
        goto LABEL_50;
    }
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v6 + 1020))(a1: (char *)this - 8) != 2 )
    {
      if ( spec_freeze_panel_extended_time.m_pParent->m_Value.m_fValue <= 0.0 )
      {
        v18 = 1;
      }
      else
      {
        v18 = 0;
        this->m_flFreezeFrameDistance = *(float *)(gpGlobals.m_Index + 12);
        this->m_bWasFreezeFraming = true;
      }
      ((void (__cdecl *)(_DWORD))view->FreezeFrame)(a1: 0);
      v19 = cvar->FindVar_2(this: cvar, a2: "snd_soundmixer");
      ConVar::Revert(this: v19);
      if ( v18 == 0 )
        goto LABEL_45;
    }
    else
    {
LABEL_50:
      if ( !this->m_bWasFreezeFraming
        || *(float *)(gpGlobals.m_Index + 12) < (float)(this->m_flFreezeFrameDistance
                                                      + spec_freeze_panel_extended_time.m_pParent->m_Value.m_fValue) )
      {
        goto LABEL_45;
      }
      this->m_bWasFreezeFraming = false;
    }
    v20 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hide_freezepanel", a3: 0, a4: 0);
    if ( v20 != nullptr )
      ((void (__cdecl *)(IGameEvent *))gameeventmanager->FireEventClientSide)(a1: v20);
  }
LABEL_45:
  if ( engine->IsPaused(this: engine) || bForceEFNoInterp )
    (*(void (__thiscall **)(char *))(*(_DWORD *)v6 + 424))(a1: (char *)this - 8);
  this->m_vecFlashlightRight.y = engine->GetLastTimeStamp(this: engine);
  this->m_vecFlashlightRight.z = this->m_vecOldViewAngles.z;
  LODWORD(this->m_fLastUpdateServerTime) = engine->GetServerTick(this: engine);
}

//------------------------------------------------------------------------------
// Address: 0x1005D550
// Name: public: void C_BasePlayer::UpdateFogController(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UpdateFogController(C_BasePlayer *this)
{
  unsigned int m_Index; // eax
  int v3; // edx
  unsigned int v4; // esi
  unsigned int v5; // ecx
  IHandleEntity *m_pEntity; // eax
  int v7; // edx
  const fogparams_t *v8; // eax
  const fogparams_t *v9; // esi
  float m_Value; // xmm1_4
  IHandleEntity *v11; // [esp+Ch] [ebp-4h]

  m_Index = this->m_PlayerFog.m_hCtrl.m_Value.m_Index;
  if ( m_Index != -1
    && (v3 = (unsigned __int16)m_Index,
        v4 = HIWORD(m_Index),
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( this->m_PlayerFog.m_flTransitionTime == -1.0 )
    {
      v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == v4
          ? g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity
          : nullptr;
      v5 = this->m_hOldFogController.m_Index;
      if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      if ( m_pEntity == v11 )
      {
        v7 = v3;
        v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v4
           ? (const fogparams_t *)g_pEntityList->m_EntPtrArray[v7].m_pEntity
           : nullptr;
        v9 = v8 + 32;
        if ( fogparams_t::operator!=(this: &this->m_CurrentFog, other: v8 + 32) )
        {
          fogparams_t::operator=(this: &this->m_CurrentFog, __that: v9);
          C_BasePlayer::UpdateFogBlend(this);
          return;
        }
      }
    }
  }
  else
  {
    m_Value = this->m_CurrentFog.farz.m_Value;
    if ( m_Value != -1.0 || this->m_CurrentFog.enable.m_Value )
    {
      if ( m_Value != -1.0 )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.farz);
        this->m_CurrentFog.farz.m_Value = -1.0;
      }
      if ( this->m_CurrentFog.enable.m_Value )
      {
        this->m_CurrentFog.NetworkStateChanged(this: &this->m_CurrentFog, a2: &this->m_CurrentFog.enable);
        this->m_CurrentFog.enable.m_Value = false;
      }
    }
  }
  C_BasePlayer::UpdateFogBlend(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005D6B0
// Name: public: virtual void sky3dparams_t::NetworkVar_fog::NetworkStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sky3dparams_t::NetworkVar_fog::NetworkStateChanged(sky3dparams_t::NetworkVar_fog *this)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 6) + 4))(a1: (char *)this - 24);
}

//------------------------------------------------------------------------------
// Address: 0x1005D6C0
// Name: public: virtual void sky3dparams_t::NetworkVar_fog::NetworkStateChanged(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall sky3dparams_t::NetworkVar_fog::NetworkStateChanged(sky3dparams_t::NetworkVar_fog *this, void *pVar)
{
  (**((void (__thiscall ***)(char *, void *))this - 6))(a1: (char *)this - 24, a2: pVar);
}

//------------------------------------------------------------------------------
// Address: 0x1005D6D0
// Name: public: CPlayerLocalData::~CPlayerLocalData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerLocalData::~CPlayerLocalData(CPlayerLocalData *this)
{
  CInterpolatedVarEntryBase<QAngle,0> *m_pElements; // eax
  CInterpolatedVarEntryBase<QAngle,0> *v3; // eax

  this->m_iv_vecPunchAngleVel.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVarArrayBase<QAngle,0>::`vftable';
  *(_DWORD *)&this->m_iv_vecPunchAngleVel.m_VarHistory.m_firstElement = 0;
  C_BaseEntity::operator delete(pMem: this->m_iv_vecPunchAngleVel.m_bLooping);
  C_BaseEntity::operator delete(pMem: (void *)this->m_iv_vecPunchAngleVel.m_LastNetworkedValue);
  m_pElements = this->m_iv_vecPunchAngleVel.m_VarHistory.m_pElements;
  if ( m_pElements != nullptr )
    C_BaseEntity::operator delete(pMem: &m_pElements[-1].value.z);
  this->m_iv_vecPunchAngleVel.m_VarHistory.m_pElements = nullptr;
  this->m_iv_vecPunchAngleVel.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&IInterpolatedVar::`vftable';
  this->m_iv_vecPunchAngle.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVarArrayBase<QAngle,0>::`vftable';
  *(_DWORD *)&this->m_iv_vecPunchAngle.m_VarHistory.m_firstElement = 0;
  C_BaseEntity::operator delete(pMem: this->m_iv_vecPunchAngle.m_bLooping);
  C_BaseEntity::operator delete(pMem: (void *)this->m_iv_vecPunchAngle.m_LastNetworkedValue);
  v3 = this->m_iv_vecPunchAngle.m_VarHistory.m_pElements;
  if ( v3 != nullptr )
    C_BaseEntity::operator delete(pMem: &v3[-1].value.z);
  this->m_iv_vecPunchAngle.m_VarHistory.m_pElements = nullptr;
  this->m_iv_vecPunchAngle.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&IInterpolatedVar::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1005D790
// Name: public: virtual void C_BasePlayer::PreThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::PreThink(C_BasePlayer *this)
{
  this->ItemPreFrame(this);
  this->UpdateClientData(this);
  C_BasePlayer::UpdateUnderwaterState(this);
  C_BasePlayer::UpdateFogController(this);
  if ( this->m_lifeState < 1 )
  {
    if ( (this->m_fFlags & 1) == 0 )
    {
      C_BaseEntity::CalcAbsoluteVelocity(this);
      LODWORD(this->m_Local.m_flFallVelocity) = LODWORD(this->m_vecAbsVelocity.z) ^ _mask__NegFloat_;
    }
    if ( C_BaseEntity::GetGroundEntity(this) != nullptr )
      this->m_flTimeLastTouchedGround = *(float *)(gpGlobals.m_Index + 12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D810
// Name: public: virtual bool C_BasePlayer::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BasePlayer::Simulate(C_BasePlayer *this)
{
  C_BasePlayer_vtbl *v2; // edi
  surfacedata_t *GroundSurface; // eax
  int v5; // [esp-8h] [ebp-18h]
  Vector vel; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( this != nullptr && this->IsPlayer(this) && this->m_bIsLocalPlayer )
  {
    C_BasePlayer::UpdateFlashlight(this);
    C_BasePlayer::UpdateFogController(this);
  }
  else
  {
    this->EstimateAbsVelocity(this, a2: &vel);
    v2 = this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    v5 = ((int (__thiscall *)(C_BasePlayer *, Vector *))this->GetAbsOrigin)(a1: this, a2: &vel);
    GroundSurface = C_BasePlayer::GetGroundSurface(this, a2: COERCE_FLOAT(&savedregs), a3: (int)this);
    ((void (__thiscall *)(C_BasePlayer *, surfacedata_t *, int))v2->UpdateStepSound)(
      a1: this,
      a2: GroundSurface,
      a3: v5);
  }
  C_BaseAnimating::Simulate(this);
  if ( (this->m_fEffects & 8) != 0 || C_BaseEntity::Teleported(this) )
    this->ResetLatched(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005D8B0
// Name: public: virtual void C_BasePlayer::PlayPlayerJingle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::PlayPlayerJingle(C_BasePlayer *this)
{
  IVEngineClient_vtbl *v2; // esi
  int v3; // eax
  int SoundSourceIndex; // eax
  char custname[512]; // [esp+4h] [ebp-508h] BYREF
  char fullsoundname[512]; // [esp+204h] [ebp-308h] BYREF
  player_info_s info; // [esp+404h] [ebp-108h] BYREF
  CLocalPlayerFilter filter; // [esp+494h] [ebp-78h] BYREF
  EmitSound_t ep; // [esp+4B4h] [ebp-58h] BYREF
  char soundhex[16]; // [esp+4FCh] [ebp-10h] BYREF

  if ( cl_customsounds.m_pParent != nullptr && cl_customsounds.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = engine->__vftable;
    v3 = ((int (__thiscall *)(IClientNetworkable *, player_info_s *))this->entindex)(
           a1: &this->IClientNetworkable,
           a2: &info);
    ((void (__thiscall *)(IVEngineClient *, int))v2->GetPlayerInfo)(a1: engine, a2: v3);
    if ( info.customFiles[1] != 0 )
    {
      V_binarytohex(in: (const unsigned __int8 *)&info.customFiles[1], inputbytes: 4, out: soundhex, outsize: 16);
      V_snprintf(pDest: fullsoundname, maxLen: 512, pFormat: "sound/temp/%s.wav", soundhex);
      if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: fullsoundname, a3: nullptr)
        || (V_snprintf(pDest: custname, maxLen: 512, pFormat: "downloads/%s.dat", soundhex),
            filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: custname, a3: nullptr))
        && engine->CopyFileA(this: engine, a2: custname, a3: fullsoundname) )
      {
        V_snprintf(pDest: fullsoundname, maxLen: 512, pFormat: "temp/%s.wav", soundhex);
        CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
        EmitSound_t::EmitSound_t(this: &ep);
        ep.m_nChannel = 2;
        ep.m_pSoundName = fullsoundname;
        ep.m_flVolume = 1.0;
        ep.m_SoundLevel = SNDLVL_NORM;
        SoundSourceIndex = C_BaseEntity::GetSoundSourceIndex(this);
        C_BaseEntity::EmitSound(&filter, iEntIndex: SoundSourceIndex, params: &ep);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
        C_RecipientFilter::~C_RecipientFilter(this: &filter);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005DA40
// Name: public: void C_BasePlayer::FogControllerChanged(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::FogControllerChanged(C_BasePlayer *this, bool bSnap)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // eax
  color32_s colorPrimary; // ecx
  const fogparams_t *v12; // eax
  float v13; // xmm0_4

  m_Index = this->m_PlayerFog.m_hCtrl.m_Value.m_Index;
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
      colorPrimary = (color32_s)this->m_CurrentFog.colorPrimary;
      this->m_PlayerFog.m_flOldStart = this->m_CurrentFog.start.m_Value;
      v12 = (const fogparams_t *)&m_pEntity[608];
      this->m_PlayerFog.m_flOldEnd = this->m_CurrentFog.end.m_Value;
      this->m_PlayerFog.m_OldColor = colorPrimary;
      this->m_PlayerFog.m_flOldMaxDensity = this->m_CurrentFog.maxdensity.m_Value;
      this->m_PlayerFog.m_flOldHDRColorScale = this->m_CurrentFog.HDRColorScale.m_Value;
      this->m_PlayerFog.m_flOldFarZ = this->m_CurrentFog.farz.m_Value;
      this->m_PlayerFog.m_NewColor = (color32_s)v12->colorPrimary;
      this->m_PlayerFog.m_flNewStart = v12->start.m_Value;
      this->m_PlayerFog.m_flNewEnd = v12->end.m_Value;
      this->m_PlayerFog.m_flNewMaxDensity = v12->maxdensity.m_Value;
      this->m_PlayerFog.m_flNewHDRColorScale = v12->HDRColorScale.m_Value;
      this->m_PlayerFog.m_flNewFarZ = v12->farz.m_Value;
      if ( bSnap )
        v13 = -1.0;
      else
        v13 = *(float *)(gpGlobals.m_Index + 12);
      this->m_PlayerFog.m_flTransitionTime = v13;
      fogparams_t::operator=(this: &this->m_CurrentFog, __that: v12);
      C_BasePlayer::UpdateFogController(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005DB60
// Name: public: virtual C_BasePlayer::~C_BasePlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::~C_BasePlayer(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // eax
  CFlashlightEffectManager *v4; // edi
  CHandle<C_BasePlayer> *m_pMemory; // eax
  CHandle<C_BasePlayer> *v6; // eax
  CHandle<C_BasePlayer> *v7; // eax
  WaterDebrisEffect *m_pObj; // ecx
  CHandle<C_BaseEntity> *v9; // eax
  CDiscontinuousInterpolatedVar<Vector>::Discontinuity_t *v10; // eax
  CInterpolatedVarEntryBase<Vector,0> *m_pElements; // eax
  CUtlReference<CNewParticleEffect> *p_m_speechVOIPParticleEffect; // eax
  CNewParticleEffect *m_pObject; // edx
  CUtlReference<CNewParticleEffect> *m_pPrev; // ecx
  CUtlReference<CNewParticleEffect> *m_pNext; // ecx
  CFlashlightEffect *pMem; // [esp+Ch] [ebp-4h]

  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BasePlayer_vtbl *)&C_BasePlayer::`vftable'{for `IClientUnknown'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BasePlayer::`vftable'{for `IClientRenderable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BasePlayer::`vftable'{for `IClientNetworkable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BasePlayer::`vftable'{for `IClientThinkable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BasePlayer::`vftable';
  m_Index = this->m_pCurrentVguiScreen.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  DeactivateVguiScreen(pVguiScreenEnt: m_pEntity);
  if ( this == s_pLocalPlayer[0] )
  {
    s_pLocalPlayer[0] = nullptr;
  }
  else if ( s_pLocalPlayer[0] != nullptr )
  {
    C_BasePlayer::RemoveSplitScreenPlayer(this: s_pLocalPlayer[0], pOther: (unsigned int)this);
  }
  if ( this->m_bFlashlightEnabled[0] )
  {
    v4 = FlashlightEffectManager(nSplitscreenPlayerOverride: 0);
    v4->m_pFlashlightTextureName = nullptr;
    v4->m_bFlashlightOn = false;
    v4->m_bFlashlightOverride = false;
    v4->m_nMuzzleFlashFrameCountdown = 0;
    if ( v4->m_muzzleFlashTimer.m_timestamp.m_Value != -1.0 )
    {
      v4->m_muzzleFlashTimer.NetworkStateChanged(this: &v4->m_muzzleFlashTimer, a2: &v4->m_muzzleFlashTimer.m_timestamp);
      v4->m_muzzleFlashTimer.m_timestamp.m_Value = -1.0;
    }
    pMem = v4->m_pFlashlightEffect;
    if ( v4->m_pFlashlightEffect != nullptr )
    {
      CFlashlightEffect::~CFlashlightEffect(this: v4->m_pFlashlightEffect);
      C_BaseEntity::operator delete(pMem);
    }
    v4->m_pFlashlightEffect = nullptr;
    this->m_bFlashlightEnabled[0] = false;
  }
  this->m_hPipPlayers.m_Size = 0;
  if ( this->m_hPipPlayers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_hPipPlayers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hPipPlayers.m_Memory.m_pMemory);
      this->m_hPipPlayers.m_Memory.m_pMemory = nullptr;
    }
    this->m_hPipPlayers.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_hPipPlayers.m_Memory.m_pMemory;
  this->m_hPipPlayers.m_pElements = m_pMemory;
  if ( this->m_hPipPlayers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_hPipPlayers.m_Memory.m_pMemory = nullptr;
    }
    this->m_hPipPlayers.m_Memory.m_nAllocationCount = 0;
  }
  this->m_hSplitScreenAndPipPlayers.m_Size = 0;
  if ( this->m_hSplitScreenAndPipPlayers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_hSplitScreenAndPipPlayers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hSplitScreenAndPipPlayers.m_Memory.m_pMemory);
      this->m_hSplitScreenAndPipPlayers.m_Memory.m_pMemory = nullptr;
    }
    this->m_hSplitScreenAndPipPlayers.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_hSplitScreenAndPipPlayers.m_Memory.m_pMemory;
  this->m_hSplitScreenAndPipPlayers.m_pElements = v6;
  if ( this->m_hSplitScreenAndPipPlayers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_hSplitScreenAndPipPlayers.m_Memory.m_pMemory = nullptr;
    }
    this->m_hSplitScreenAndPipPlayers.m_Memory.m_nAllocationCount = 0;
  }
  this->m_hSplitScreenPlayers.m_Size = 0;
  if ( this->m_hSplitScreenPlayers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_hSplitScreenPlayers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hSplitScreenPlayers.m_Memory.m_pMemory);
      this->m_hSplitScreenPlayers.m_Memory.m_pMemory = nullptr;
    }
    this->m_hSplitScreenPlayers.m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->m_hSplitScreenPlayers.m_Memory.m_pMemory;
  this->m_hSplitScreenPlayers.m_pElements = v7;
  if ( this->m_hSplitScreenPlayers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      this->m_hSplitScreenPlayers.m_Memory.m_pMemory = nullptr;
    }
    this->m_hSplitScreenPlayers.m_Memory.m_nAllocationCount = 0;
  }
  m_pObj = this->m_pWaterEmitter.m_pObj;
  if ( m_pObj != nullptr )
    CParticleEffect::Release(this: m_pObj);
  this->m_CommandContext.cmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  this->m_SimulatedByThisPlayer.m_Size = 0;
  if ( this->m_SimulatedByThisPlayer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SimulatedByThisPlayer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_SimulatedByThisPlayer.m_Memory.m_pMemory);
      this->m_SimulatedByThisPlayer.m_Memory.m_pMemory = nullptr;
    }
    this->m_SimulatedByThisPlayer.m_Memory.m_nAllocationCount = 0;
  }
  v9 = this->m_SimulatedByThisPlayer.m_Memory.m_pMemory;
  this->m_SimulatedByThisPlayer.m_pElements = v9;
  if ( this->m_SimulatedByThisPlayer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v9);
      this->m_SimulatedByThisPlayer.m_Memory.m_pMemory = nullptr;
    }
    this->m_SimulatedByThisPlayer.m_Memory.m_nAllocationCount = 0;
  }
  this->m_iv_vecViewOffset.m_Discontinuities.m_Size = 0;
  if ( this->m_iv_vecViewOffset.m_Discontinuities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_iv_vecViewOffset.m_Discontinuities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_iv_vecViewOffset.m_Discontinuities.m_Memory.m_pMemory);
      this->m_iv_vecViewOffset.m_Discontinuities.m_Memory.m_pMemory = nullptr;
    }
    this->m_iv_vecViewOffset.m_Discontinuities.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_iv_vecViewOffset.m_Discontinuities.m_Memory.m_pMemory;
  this->m_iv_vecViewOffset.m_Discontinuities.m_pElements = v10;
  if ( this->m_iv_vecViewOffset.m_Discontinuities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v10 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
      this->m_iv_vecViewOffset.m_Discontinuities.m_Memory.m_pMemory = nullptr;
    }
    this->m_iv_vecViewOffset.m_Discontinuities.m_Memory.m_nAllocationCount = 0;
  }
  this->m_iv_vecViewOffset.__vftable = (CDiscontinuousInterpolatedVar<Vector>_vtbl *)&CInterpolatedVarArrayBase<Vector,0>::`vftable';
  *(_DWORD *)&this->m_iv_vecViewOffset.m_VarHistory.m_firstElement = 0;
  C_BaseEntity::operator delete(pMem: this->m_iv_vecViewOffset.m_bLooping);
  C_BaseEntity::operator delete(pMem: (void *)this->m_iv_vecViewOffset.m_LastNetworkedValue);
  m_pElements = this->m_iv_vecViewOffset.m_VarHistory.m_pElements;
  if ( m_pElements != nullptr )
    C_BaseEntity::operator delete(pMem: &m_pElements[-1].value.z);
  this->m_iv_vecViewOffset.m_VarHistory.m_pElements = nullptr;
  p_m_speechVOIPParticleEffect = &this->m_speechVOIPParticleEffect;
  this->m_iv_vecViewOffset.__vftable = (CDiscontinuousInterpolatedVar<Vector>_vtbl *)&IInterpolatedVar::`vftable';
  m_pObject = this->m_speechVOIPParticleEffect.m_pObject;
  if ( m_pObject != nullptr )
  {
    m_pPrev = this->m_speechVOIPParticleEffect.m_pPrev;
    if ( m_pPrev != nullptr )
    {
      m_pPrev->m_pNext = p_m_speechVOIPParticleEffect->m_pNext;
      if ( p_m_speechVOIPParticleEffect->m_pNext != nullptr )
        p_m_speechVOIPParticleEffect->m_pNext->m_pPrev = this->m_speechVOIPParticleEffect.m_pPrev;
    }
    else if ( m_pObject->m_References.m_pHead == p_m_speechVOIPParticleEffect )
    {
      m_pNext = p_m_speechVOIPParticleEffect->m_pNext;
      m_pObject->m_References.m_pHead = p_m_speechVOIPParticleEffect->m_pNext;
      if ( m_pNext != nullptr )
        m_pNext->m_pPrev = nullptr;
    }
    this->m_speechVOIPParticleEffect.m_pPrev = nullptr;
    p_m_speechVOIPParticleEffect->m_pNext = nullptr;
    this->m_speechVOIPParticleEffect.m_pObject = nullptr;
  }
  this->m_LastCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  this->pl.__vftable = (CPlayerState_vtbl *)&CPlayerState::`vftable';
  CPlayerLocalData::~CPlayerLocalData(this: &this->m_Local);
  C_BaseCombatCharacter::~C_BaseCombatCharacter(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005DF30
// Name: public: virtual class C_BaseCombatCharacter __near * C_BasePlayer::ActivePlayerCombatCharacter(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall C_BasePlayer::ActivePlayerCombatCharacter(CChoreoActor *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005DF80
// Name: public: virtual char const __near * C_BasePlayer::GetVOIPParticleEffectName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_BasePlayer::GetVOIPParticleEffectName(C_BasePlayer *this)
{
  return "impact_physics_dust";
}

//------------------------------------------------------------------------------
// Address: 0x1005DF90
// Name: public: virtual struct fogparams_t __near * C_BasePlayer::GetFogParams(void)
// Source: json
//------------------------------------------------------------------------------
fogparams_t *__thiscall C_BasePlayer::GetFogParams(C_BasePlayer *this)
{
  return &this->m_CurrentFog;
}

//------------------------------------------------------------------------------
// Address: 0x1005DFA0
// Name: protected: virtual bool C_BasePlayer::IsDucked(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::IsDucked(C_BasePlayer *this)
{
  return this->m_Local.m_bDucked;
}

//------------------------------------------------------------------------------
// Address: 0x1005DFB0
// Name: protected: virtual bool C_BasePlayer::IsDucking(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::IsDucking(C_BasePlayer *this)
{
  return this->m_Local.m_bDucking;
}

//------------------------------------------------------------------------------
// Address: 0x1005DFC0
// Name: protected: virtual float C_BasePlayer::GetFallVelocity(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BasePlayer::GetFallVelocity(C_BasePlayer *this)
{
  return this->m_Local.m_flFallVelocity;
}

//------------------------------------------------------------------------------
// Address: 0x1005DFD0
// Name: public: virtual bool C_BasePlayer::IsAllowedToSwitchWeapons(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BasePlayer::IsAllowedToSwitchWeapons(C_BasePlayer *this)
{
  return this->GetObserverMode(this) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005DFE0
// Name: public: virtual class C_BaseCombatWeapon __near * C_BasePlayer::GetLastWeapon(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_BasePlayer::GetLastWeapon(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hLastWeapon.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1005E010
// Name: public: virtual void C_BasePlayer::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UpdateOnRemove(C_BasePlayer *this)
{
  IPhysicsPlayerController *m_pPhysicsController; // eax
  CNewParticleEffect *m_pObject; // eax
  CNewParticleEffect *v4; // eax

  m_pPhysicsController = this->m_pPhysicsController;
  if ( m_pPhysicsController != nullptr )
  {
    physenv->DestroyPlayerController(this: physenv, a2: m_pPhysicsController);
    this->m_pPhysicsController = nullptr;
  }
  PhysRemoveShadow(pEntity: this);
  C_BaseEntity::VPhysicsSetObject(this, pPhysics: nullptr);
  if ( this->m_pShadowStand != nullptr )
  {
    physenv->DestroyObject(this: physenv, a2: this->m_pShadowStand);
    this->m_pShadowStand = nullptr;
  }
  if ( this->m_pShadowCrouch != nullptr )
  {
    physenv->DestroyObject(this: physenv, a2: this->m_pShadowCrouch);
    this->m_pShadowCrouch = nullptr;
  }
  m_pObject = this->m_speechVOIPParticleEffect.m_pObject;
  if ( m_pObject != nullptr )
  {
    CParticleProperty::StopEmissionAndDestroyImmediately(this: &this->m_Particles, pEffect: m_pObject);
    v4 = this->m_speechVOIPParticleEffect.m_pObject;
    if ( v4 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&v4->m_References,
        which: (CUtlReference<CSheet> *)&this->m_speechVOIPParticleEffect);
      this->m_speechVOIPParticleEffect.m_pObject = nullptr;
    }
  }
  C_BaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E0D0
// Name: public: virtual void C_BasePlayer::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::OnDataChanged(C_BasePlayer *this, DataUpdateType_t updateType)
{
  C_BasePlayer *v3; // esi
  int v4; // ebx
  const FileWeaponInfo_t *WeaponFromAmmo; // eax
  char *v6; // ebx
  CHud *Hud; // eax
  _DWORD *v8; // eax
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // ebx
  unsigned int v11; // ecx
  IHandleEntity *v12; // eax
  float z; // ecx
  const CViewVectors *v14; // eax
  const struct CPhysCollide *Bbox; // eax
  IPhysicsObject *v16; // eax
  const CViewVectors *v17; // eax
  const struct CPhysCollide *v18; // eax
  IPhysicsPlayerController *v19; // eax
  IPhysicsPlayerController *v20; // eax
  IPhysicsPlayerController *m_nLastRecordedFrame; // eax
  IPhysicsObject *v22; // ecx
  const Vector *v23; // eax
  Vector *p_m_vDuckHullMax; // [esp+8h] [ebp-684h]
  Vector *p_m_vHullMax; // [esp+Ch] [ebp-680h]
  const Vector *v26; // [esp+Ch] [ebp-680h]
  const Vector *LocalOrigin; // [esp+10h] [ebp-67Ch]
  const QAngle *v28; // [esp+10h] [ebp-67Ch]
  const QAngle *LocalAngles; // [esp+14h] [ebp-678h]
  IPhysicsObject *m_pShadowStand; // [esp+18h] [ebp-674h]
  solid_t solid; // [esp+24h] [ebp-668h] BYREF
  Vector vecAbsVelocity; // [esp+664h] [ebp-28h] BYREF
  Vector vecAbsOrigin; // [esp+670h] [ebp-1Ch] BYREF
  SFItemHistory *pHudIR; // [esp+67Ch] [ebp-10h]
  int ammoTypes; // [esp+680h] [ebp-Ch]
  float *p_m_flVehicleViewFOV; // [esp+684h] [ebp-8h]
  int i; // [esp+688h] [ebp-4h]

  v3 = (C_BasePlayer *)((char *)this - 8);
  if ( this != (C_BasePlayer *)8 && v3->IsPlayer(this: (C_BasePlayer *)((char *)this - 8)) && v3->m_bIsLocalPlayer )
    C_BaseEntity::SetPredictionEligible(this: v3, canpredict: true);
  C_BaseAnimating::OnDataChanged(this, updateType);
  if ( v3 != nullptr && v3->IsPlayer(this: v3) && v3->m_bIsLocalPlayer )
  {
    if ( this->m_hPipPlayers.m_Size == 0 )
      render->SetAreaState(this: render, a2: (unsigned __int8 *)&this->m_StuckLast, a3: &this->m_Local.m_chAreaBits[24]);
    v4 = 0;
    ammoTypes = GetAmmoDef()->m_nAmmoIndex;
    i = 0;
    if ( ammoTypes >= 0 )
    {
      p_m_flVehicleViewFOV = &this->m_flVehicleViewFOV;
      do
      {
        if ( C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v4) > *(_DWORD *)p_m_flVehicleViewFOV )
        {
          WeaponFromAmmo = WeaponsResource::GetWeaponFromAmmo(this: &gWR, iAmmoId: v4);
          v6 = (char *)WeaponFromAmmo;
          if ( WeaponFromAmmo == nullptr || (WeaponFromAmmo->iFlags & 0x40) == 0 )
          {
            Hud = GetHud(nSlot: -1);
            pHudIR = (SFItemHistory *)CHud::FindElement(this: Hud, pName: "SFItemHistory");
            if ( pHudIR != nullptr )
            {
              v8 = __RTDynamicCast(
                     inptr: v6,
                     VfDelta: 0,
                     SrcType: &FileWeaponInfo_t `RTTI Type Descriptor',
                     TargetType: &CCSWeaponInfo `RTTI Type Descriptor',
                     isReference: 0);
              if ( v8 != nullptr && v8[467] == 8 )
                SFItemHistory::AddToHistory(this: pHudIR, name: v6 + 6, displayName: v6 + 86);
            }
          }
          v4 = i;
        }
        ++p_m_flVehicleViewFOV;
        i = ++v4;
      }
      while ( v4 <= ammoTypes );
    }
    Soundscape_Update(audio: (audioparams_t *)&this->m_Local.m_skybox3d.fog.enable);
    m_Index = this->m_hColorCorrectionCtrl.m_Value.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v11 = *(_DWORD *)&this->m_CurrentFog.enable.m_Value;
    if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
      v12 = nullptr;
    else
      v12 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
    if ( v12 != m_pEntity )
      C_BasePlayer::FogControllerChanged(this: v3, bSnap: updateType == DATA_UPDATE_CREATED);
  }
  if ( updateType == DATA_UPDATE_CREATED
    && physenv->IsPredicted(this: physenv)
    && engine->GetLocalPlayer(this: engine) == DWORD2(this->m_pfnTouch) )
  {
    vecAbsOrigin = *v3->GetAbsOrigin(this: v3);
    C_BaseEntity::CalcAbsoluteVelocity(this: v3);
    z = v3->m_vecAbsVelocity.z;
    *(_QWORD *)&vecAbsVelocity.x = *(_QWORD *)&v3->m_vecAbsVelocity.x;
    vecAbsVelocity.z = z;
    V_strncpy(pDest: solid.surfaceprop, pSrc: "player", maxLen: 512);
    solid.params.massCenterOverride = g_PhysDefaultObjectParams.massCenterOverride;
    solid.params.damping = g_PhysDefaultObjectParams.damping;
    *(_QWORD *)&solid.params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
    *(_QWORD *)&solid.params.pName = *(_QWORD *)&g_PhysDefaultObjectParams.pName;
    memset(&solid.params.volume, 0, 12);
    solid.params.mass = 85.0;
    solid.params.inertia = 1.0e24;
    LocalAngles = C_BaseEntity::GetLocalAngles(this: v3);
    LocalOrigin = C_BaseEntity::GetLocalOrigin(this: v3);
    p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
    v14 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    Bbox = PhysCreateBbox(minsIn: &v14->m_vHullMin, maxsIn: p_m_vHullMax);
    v16 = PhysModelCreateCustom(
            pEntity: v3,
            pModel: Bbox,
            origin: LocalOrigin,
            angles: LocalAngles,
            pName: "player_stand",
            isStatic: false,
            pSolid: &solid);
    this->m_hZoomOwner.m_Index = (unsigned int)v16;
    v16->SetCallbackFlags(this: v16, a2: 17u);
    v28 = C_BaseEntity::GetLocalAngles(this: v3);
    v26 = C_BaseEntity::GetLocalOrigin(this: v3);
    p_m_vDuckHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vDuckHullMax;
    v17 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v18 = PhysCreateBbox(minsIn: &v17->m_vDuckHullMin, maxsIn: p_m_vDuckHullMax);
    v19 = (IPhysicsPlayerController *)PhysModelCreateCustom(
                                        pEntity: v3,
                                        pModel: v18,
                                        origin: v26,
                                        angles: v28,
                                        pName: "player_crouch",
                                        isStatic: false,
                                        pSolid: &solid);
    this->m_pPhysicsController = v19;
    v19->__vftable[1].MaxSpeed(this: v19, a2: (const Vector *)17);
    C_BaseEntity::VPhysicsSetObject(this: v3, pPhysics: (IPhysicsObject *)this->m_hZoomOwner.m_Index);
    PhysAddShadow(pEntity: v3);
    v20 = physenv->CreatePlayerController(this: physenv, a2: this->m_hZoomOwner.m_Index);
    LODWORD(this->m_flMaxspeed) = v20;
    ((void (__thiscall *)(IPhysicsPlayerController *, int))v20->SetPushMassLimit)(a1: v20, a2: 1135542272);
    (*(void (__stdcall **)(int))(*(_DWORD *)LODWORD(this->m_flMaxspeed) + 52))(a1: 1112014848);
    C_BasePlayer::UpdatePhysicsShadowToPosition(this: v3, &vecAbsOrigin);
    if ( (this->m_nNextThinkTick & 2) != 0 )
      C_BasePlayer::SetVCollisionState(this: v3, &vecAbsOrigin, &vecAbsVelocity, collisionState: 1);
    else
      C_BasePlayer::SetVCollisionState(this: v3, &vecAbsOrigin, &vecAbsVelocity, collisionState: 0);
  }
  if ( LOBYTE(this->m_nSplitScreenSlot) != 0 )
  {
    m_nLastRecordedFrame = (IPhysicsPlayerController *)this->m_nLastRecordedFrame;
    if ( m_nLastRecordedFrame != nullptr
      && ((v22 = this->m_pShadowStand) == (IPhysicsObject *)1
       && m_nLastRecordedFrame == (IPhysicsPlayerController *)this->m_hZoomOwner.m_Index
       || v22 == nullptr && m_nLastRecordedFrame == this->m_pPhysicsController) )
    {
      C_BaseEntity::CalcAbsoluteVelocity(this: v3);
      m_pShadowStand = this->m_pShadowStand;
      v23 = v3->GetAbsOrigin(this: v3);
      C_BasePlayer::SetVCollisionState(
        this: v3,
        vecAbsOrigin: v23,
        vecAbsVelocity: &v3->m_vecAbsVelocity,
        collisionState: (int)m_pShadowStand);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E540
// Name: public: virtual void C_BasePlayer::UpdateSpeechVOIP(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UpdateSpeechVOIP(C_BasePlayer *this, bool bVoice)
{
  IMDLCache *v3; // ebx
  CNewParticleEffect *v4; // eax
  CUtlReference<CSheet> *p_m_speechVOIPParticleEffect; // esi
  CNewParticleEffect *v6; // edi
  CUtlIntrusiveDList<CUtlReference<CSheet> > *p_m_References; // eax
  CUtlReference<CNewParticleEffect> *m_pHead; // eax
  CNewParticleEffect *m_pObject; // eax
  CUtlReference<CSheet> *v10; // esi

  if ( bVoice && this->ShouldShowVOIPIcon(this) )
  {
    if ( this->m_speechVOIPParticleEffect.m_pObject == nullptr )
    {
      v3 = mdlcache;
      mdlcache->BeginLock(this: mdlcache);
      v4 = this->GetVOIPParticleEffect(this);
      p_m_speechVOIPParticleEffect = (CUtlReference<CSheet> *)&this->m_speechVOIPParticleEffect;
      v6 = v4;
      p_m_References = &p_m_speechVOIPParticleEffect->m_pObject->m_References;
      if ( p_m_References != (CUtlIntrusiveDList<CUtlReference<CSheet> > *)v6 )
      {
        if ( p_m_References != nullptr )
        {
          CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
            this: p_m_References + 232,
            which: p_m_speechVOIPParticleEffect);
          p_m_speechVOIPParticleEffect->m_pObject = nullptr;
        }
        p_m_speechVOIPParticleEffect->m_pObject = (CSheet *)v6;
        if ( v6 != nullptr )
        {
          p_m_speechVOIPParticleEffect->m_pNext = (CUtlReference<CSheet> *)v6->m_References.m_pHead;
          m_pHead = v6->m_References.m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = (CUtlReference<CNewParticleEffect> *)p_m_speechVOIPParticleEffect;
          p_m_speechVOIPParticleEffect->m_pPrev = nullptr;
          v6->m_References.m_pHead = (CUtlReference<CNewParticleEffect> *)p_m_speechVOIPParticleEffect;
        }
      }
      v3->EndLock(this: v3);
    }
  }
  else if ( this->m_speechVOIPParticleEffect.m_pObject != nullptr )
  {
    CParticleProperty::StopEmissionAndDestroyImmediately(
      this: &this->m_Particles,
      pEffect: this->m_speechVOIPParticleEffect.m_pObject);
    m_pObject = this->m_speechVOIPParticleEffect.m_pObject;
    v10 = (CUtlReference<CSheet> *)&this->m_speechVOIPParticleEffect;
    if ( m_pObject != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
        which: v10);
      v10->m_pObject = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E630
// Name: public: CPlayerLocalData::CPlayerLocalData(void)
// Source: json
//------------------------------------------------------------------------------
CPlayerLocalData *__thiscall CPlayerLocalData::CPlayerLocalData(CPlayerLocalData *this)
{
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0> > *p_m_VarHistory; // ecx

  this->__vftable = (CPlayerLocalData_vtbl *)&CPlayerLocalData::`vftable';
  p_m_VarHistory = &this->m_iv_vecPunchAngle.m_VarHistory;
  this->m_iv_vecPunchAngle.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVarArrayBase<QAngle,0>::`vftable';
  p_m_VarHistory->m_pElements = nullptr;
  *(_DWORD *)&p_m_VarHistory->m_maxElement = 0;
  *(_DWORD *)&p_m_VarHistory->m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(
    this: p_m_VarHistory,
    capSize: (CInterpolatedVarEntryBase<QAngle,0> *)4);
  this->m_iv_vecPunchAngle.m_pDebugName = "CPlayerLocalData::m_iv_vecPunchAngle";
  this->m_iv_vecPunchAngle.m_pValue = nullptr;
  this->m_iv_vecPunchAngle.m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_iv_vecPunchAngle.m_fType = 1;
  this->m_iv_vecPunchAngle.m_LastNetworkedTime = 0.0;
  this->m_iv_vecPunchAngle.m_LastNetworkedValue = nullptr;
  this->m_iv_vecPunchAngle.m_bLooping = nullptr;
  this->m_iv_vecPunchAngle.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVar<QAngle>::`vftable';
  CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(this: &this->m_iv_vecPunchAngle, flCurrentTime: 0.0, newmax: 1);
  this->m_iv_vecPunchAngleVel.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVarArrayBase<QAngle,0>::`vftable';
  this->m_iv_vecPunchAngleVel.m_VarHistory.m_pElements = nullptr;
  *(_DWORD *)&this->m_iv_vecPunchAngleVel.m_VarHistory.m_maxElement = 0;
  *(_DWORD *)&this->m_iv_vecPunchAngleVel.m_VarHistory.m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(
    this: &this->m_iv_vecPunchAngleVel.m_VarHistory,
    capSize: (CInterpolatedVarEntryBase<QAngle,0> *)4);
  this->m_iv_vecPunchAngleVel.m_pDebugName = "CPlayerLocalData::m_iv_vecPunchAngleVel";
  this->m_iv_vecPunchAngleVel.m_pValue = nullptr;
  this->m_iv_vecPunchAngleVel.m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_iv_vecPunchAngleVel.m_fType = 1;
  this->m_iv_vecPunchAngleVel.m_LastNetworkedTime = 0.0;
  this->m_iv_vecPunchAngleVel.m_LastNetworkedValue = nullptr;
  this->m_iv_vecPunchAngleVel.m_bLooping = nullptr;
  this->m_iv_vecPunchAngleVel.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVar<QAngle>::`vftable';
  CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(this: &this->m_iv_vecPunchAngleVel, flCurrentTime: 0.0, newmax: 1);
  this->m_skybox3d.__vftable = (sky3dparams_t_vtbl *)&sky3dparams_t::`vftable';
  this->m_skybox3d.fog.__vftable = (sky3dparams_t::NetworkVar_fog_vtbl *)&sky3dparams_t::NetworkVar_fog::`vftable';
  this->m_audio.__vftable = (audioparams_t_vtbl *)&audioparams_t::`vftable';
  this->m_iv_vecPunchAngle.Setup(this: &this->m_iv_vecPunchAngle, a2: &this->m_vecPunchAngle, a3: 2);
  this->m_iv_vecPunchAngleVel.Setup(this: &this->m_iv_vecPunchAngleVel, a2: &this->m_vecPunchAngleVel, a3: 2);
  this->m_flFOVRate = 0.0;
  this->m_bSlowMovement = false;
  this->m_fTBeamEndTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005E7D0
// Name: public: C_BasePlayer::C_BasePlayer(void)
// Source: json
//------------------------------------------------------------------------------
C_BasePlayer *__thiscall C_BasePlayer::C_BasePlayer(C_BasePlayer *this)
{
  C_BaseCombatCharacter::C_BaseCombatCharacter(this);
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BasePlayer_vtbl *)&C_BasePlayer::`vftable'{for `IClientUnknown'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BasePlayer::`vftable'{for `IClientRenderable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BasePlayer::`vftable'{for `IClientNetworkable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BasePlayer::`vftable'{for `IClientThinkable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BasePlayer::`vftable';
  this->m_CurrentFog.__vftable = (fogparams_t_vtbl *)&fogparams_t::`vftable';
  this->m_hOldFogController.m_Index = -1;
  CPlayerLocalData::CPlayerLocalData(this: &this->m_Local);
  this->m_Local.__vftable = (C_BasePlayer::NetworkVar_m_Local_vtbl *)&C_BasePlayer::NetworkVar_m_Local::`vftable';
  this->m_hTonemapController.m_Index = -1;
  this->pl.__vftable = (CPlayerState_vtbl *)&CPlayerState::`vftable';
  this->m_hZoomOwner.m_Index = -1;
  this->m_LastCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  this->m_LastCmd.command_number = 0;
  this->m_LastCmd.tick_count = 0;
  this->m_LastCmd.viewangles.x = 0.0;
  this->m_LastCmd.viewangles.y = 0.0;
  this->m_LastCmd.viewangles.z = 0.0;
  this->m_LastCmd.forwardmove = 0.0;
  this->m_LastCmd.sidemove = 0.0;
  this->m_LastCmd.upmove = 0.0;
  this->m_LastCmd.buttons = 0;
  this->m_LastCmd.impulse = 0;
  this->m_LastCmd.weaponselect = 0;
  this->m_LastCmd.weaponsubtype = 0;
  this->m_LastCmd.random_seed = 0;
  this->m_LastCmd.hasbeenpredicted = false;
  *(_DWORD *)&this->m_LastCmd.mousedx = 0;
  this->m_LastCmd.headangles.x = 0.0;
  this->m_LastCmd.headangles.y = 0.0;
  this->m_LastCmd.headangles.z = 0.0;
  this->m_LastCmd.headoffset.x = 0.0;
  this->m_LastCmd.headoffset.y = 0.0;
  this->m_LastCmd.headoffset.z = 0.0;
  this->m_hVehicle.m_Index = -1;
  this->m_hLastWeapon.m_Index = -1;
  this->m_hViewModel[0].m_Index = -1;
  this->m_hViewModel[1].m_Index = -1;
  this->m_speechVOIPParticleEffect.m_pPrev = nullptr;
  this->m_speechVOIPParticleEffect.m_pNext = nullptr;
  this->m_speechVOIPParticleEffect.m_pObject = nullptr;
  this->m_hUseEntity.m_Index = -1;
  this->m_hViewEntity.m_Index = -1;
  this->m_hConstraintEntity.m_Index = -1;
  this->m_hObserverTarget.m_Index = -1;
  CDiscontinuousInterpolatedVar<Vector>::CDiscontinuousInterpolatedVar<Vector>(
    this: &this->m_iv_vecViewOffset,
    pDebugName: "C_BasePlayer::m_iv_vecViewOffset");
  this->m_hOldVehicle.m_Index = -1;
  this->m_pCurrentVguiScreen.m_Index = -1;
  this->m_SimulatedByThisPlayer.m_Memory.m_pMemory = nullptr;
  this->m_SimulatedByThisPlayer.m_Memory.m_nAllocationCount = 0;
  this->m_SimulatedByThisPlayer.m_Memory.m_nGrowSize = 0;
  this->m_SimulatedByThisPlayer.m_Size = 0;
  this->m_SimulatedByThisPlayer.m_pElements = nullptr;
  this->m_CommandContext.cmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  this->m_CommandContext.cmd.command_number = 0;
  this->m_CommandContext.cmd.tick_count = 0;
  this->m_CommandContext.cmd.viewangles.x = 0.0;
  this->m_CommandContext.cmd.viewangles.y = 0.0;
  this->m_CommandContext.cmd.viewangles.z = 0.0;
  this->m_CommandContext.cmd.forwardmove = 0.0;
  this->m_CommandContext.cmd.sidemove = 0.0;
  this->m_CommandContext.cmd.upmove = 0.0;
  this->m_CommandContext.cmd.buttons = 0;
  this->m_CommandContext.cmd.impulse = 0;
  this->m_CommandContext.cmd.weaponselect = 0;
  this->m_CommandContext.cmd.weaponsubtype = 0;
  this->m_CommandContext.cmd.random_seed = 0;
  *(_DWORD *)&this->m_CommandContext.cmd.mousedx = 0;
  this->m_CommandContext.cmd.hasbeenpredicted = false;
  this->m_CommandContext.cmd.headangles.x = 0.0;
  this->m_CommandContext.cmd.headangles.y = 0.0;
  this->m_CommandContext.cmd.headangles.z = 0.0;
  this->m_CommandContext.cmd.headoffset.x = 0.0;
  this->m_CommandContext.cmd.headoffset.y = 0.0;
  this->m_CommandContext.cmd.headoffset.z = 0.0;
  this->m_tWaterParticleTimer.m_fNextEvent = 0.0;
  this->m_pWaterEmitter.m_pObj = nullptr;
  this->m_tWaterParticleTimer.m_TimeBetweenEvents = -1.0;
  this->m_hSplitScreenPlayers.m_Memory.m_pMemory = nullptr;
  this->m_hSplitScreenPlayers.m_Memory.m_nAllocationCount = 0;
  this->m_hSplitScreenPlayers.m_Memory.m_nGrowSize = 0;
  this->m_hSplitScreenPlayers.m_Size = 0;
  this->m_hSplitScreenPlayers.m_pElements = nullptr;
  this->m_hSplitScreenAndPipPlayers.m_Memory.m_pMemory = nullptr;
  this->m_hSplitScreenAndPipPlayers.m_Memory.m_nAllocationCount = 0;
  this->m_hSplitScreenAndPipPlayers.m_Memory.m_nGrowSize = 0;
  this->m_hSplitScreenAndPipPlayers.m_Size = 0;
  this->m_hSplitScreenAndPipPlayers.m_pElements = nullptr;
  this->m_hPipPlayers.m_Memory.m_pMemory = nullptr;
  this->m_hPipPlayers.m_Memory.m_nAllocationCount = 0;
  this->m_hPipPlayers.m_Memory.m_nGrowSize = 0;
  this->m_hPipPlayers.m_Size = 0;
  this->m_hPipPlayers.m_pElements = nullptr;
  this->m_hSplitOwner.m_Index = -1;
  this->m_StepSoundCache[0].m_SoundParameters.m_nSoundEntryVersion = 1;
  this->m_StepSoundCache[1].m_SoundParameters.m_nSoundEntryVersion = 1;
  this->m_StepSoundCache[0].m_SoundParameters.pitch = 100;
  this->m_StepSoundCache[0].m_SoundParameters.pitchlow = 100;
  this->m_StepSoundCache[0].m_SoundParameters.pitchhigh = 100;
  this->m_StepSoundCache[0].m_SoundParameters.m_hSoundScriptHandle = -1;
  this->m_StepSoundCache[1].m_SoundParameters.pitch = 100;
  this->m_StepSoundCache[1].m_SoundParameters.pitchlow = 100;
  this->m_StepSoundCache[1].m_SoundParameters.pitchhigh = 100;
  this->m_StepSoundCache[1].m_usSoundNameIndex = 0;
  this->m_StepSoundCache[0].m_SoundParameters.channel = 0;
  this->m_StepSoundCache[0].m_SoundParameters.volume = 1.0;
  this->m_StepSoundCache[0].m_SoundParameters.soundlevel = SNDLVL_NORM;
  this->m_StepSoundCache[0].m_SoundParameters.soundname[0] = 0;
  this->m_StepSoundCache[0].m_SoundParameters.play_to_owner_only = false;
  this->m_StepSoundCache[0].m_SoundParameters.count = 0;
  this->m_StepSoundCache[0].m_SoundParameters.delay_msec = 0;
  this->m_StepSoundCache[0].m_SoundParameters.m_pOperatorsKV = nullptr;
  this->m_StepSoundCache[0].m_SoundParameters.m_nRandomSeed = -1;
  this->m_StepSoundCache[0].m_usSoundNameIndex = 0;
  this->m_StepSoundCache[1].m_SoundParameters.channel = 0;
  this->m_StepSoundCache[1].m_SoundParameters.volume = 1.0;
  this->m_StepSoundCache[1].m_SoundParameters.soundlevel = SNDLVL_NORM;
  this->m_StepSoundCache[1].m_SoundParameters.soundname[0] = 0;
  this->m_StepSoundCache[1].m_SoundParameters.play_to_owner_only = false;
  this->m_StepSoundCache[1].m_SoundParameters.count = 0;
  this->m_StepSoundCache[1].m_SoundParameters.delay_msec = 0;
  this->m_StepSoundCache[1].m_SoundParameters.m_hSoundScriptHandle = -1;
  this->m_StepSoundCache[1].m_SoundParameters.m_pOperatorsKV = nullptr;
  this->m_StepSoundCache[1].m_SoundParameters.m_nRandomSeed = -1;
  this->m_hPostProcessCtrl.m_Value.m_Index = -1;
  this->m_hColorCorrectionCtrl.m_Value.m_Index = -1;
  fogplayerparams_t::fogplayerparams_t(this: &this->m_PlayerFog);
  C_BaseEntity::AddVar(
    this,
    data: (void *)&this->m_vecViewOffset,
    watcher: &this->m_iv_vecViewOffset,
    type: 2,
    bSetup: false);
  this->m_hViewEntity.m_Index = -1;
  this->m_bShouldDrawPlayerWhileUsingViewEntity = false;
  this->m_bFlashlightEnabled[0] = false;
  this->m_pCurrentVguiScreen.m_Index = -1;
  this->m_pCurrentCommand = nullptr;
  this->m_flPredictionErrorTime = -100.0;
  this->m_StuckLast = 0;
  this->m_bWasFrozen = false;
  this->m_bResampleWaterSurface = true;
  C_BasePlayer::ResetObserverMode(this);
  this->m_flTimeLastTouchedGround = 0.0;
  this->m_vecPredictionError.x = 0.0;
  this->m_vecPredictionError.y = 0.0;
  this->m_vecPredictionError.z = 0.0;
  this->m_nSplitScreenSlot = -1;
  this->m_surfaceProps = 0;
  this->m_pSurfaceData = nullptr;
  this->m_chTextureType = 0;
  this->m_bIsLocalPlayer = false;
  this->m_afButtonForced = 0;
  this->m_bWasFreezePanelExtended = false;
  this->m_bFiredWeapon = false;
  this->m_flPredictionErrorTime = 0.0;
  this->m_surfaceFriction = 1.0;
  this->m_bDisableSimulationFix = true;
  this->m_flNextAchievementAnnounceTime = 0.0;
  this->m_flFreezePanelExtendedStartTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005ECB0
// Name: CC_BasePlayerFactory
// Source: json
//------------------------------------------------------------------------------
C_BasePlayer *__cdecl CC_BasePlayerFactory()
{
  C_BasePlayer *v0; // eax

  v0 = (C_BasePlayer *)C_BaseEntity::operator new(stAllocateBlock: 0x1A40u);
  if ( v0 != nullptr )
    return C_BasePlayer::C_BasePlayer(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100D0230
// Name: public: static void C_BasePlayer::RecvProxy_LocalOriginZ(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BasePlayer::RecvProxy_LocalOriginZ(const CRecvProxyData *pData, void *pStruct, float *pOut)
{
  *pOut = pData->m_Value.m_Float;
}

//------------------------------------------------------------------------------
// Address: 0x10411390
// Name: DT_PlayerState::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PlayerState::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PlayerState::g_RecvTable);
  return atexit(func: DT_PlayerState::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104113B0
// Name: DT_PlayerState::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PlayerState::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PlayerState::ignored>();
  DT_PlayerState::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104113C0
// Name: DT_Local::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Local::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Local::g_RecvTable);
  return atexit(func: DT_Local::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104113E0
// Name: DT_Local::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Local::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Local::ignored>();
  DT_Local::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104113F0
// Name: DT_LocalPlayerExclusive::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalPlayerExclusive::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_LocalPlayerExclusive::g_RecvTable);
  return atexit(func: DT_LocalPlayerExclusive::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411410
// Name: DT_LocalPlayerExclusive::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalPlayerExclusive::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_LocalPlayerExclusive::ignored>();
  DT_LocalPlayerExclusive::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411440
// Name: DT_BasePlayer::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BasePlayer::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BasePlayer::g_RecvTable);
  return atexit(func: DT_BasePlayer::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411460
// Name: DT_BasePlayer::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BasePlayer::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BasePlayer::ignored>();
  DT_BasePlayer::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411470
// Name: CPlayerState_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void CPlayerState_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  CPlayerState::m_PredMap.dataNumFields = 1;
  CPlayerState::m_PredMap.dataDesc = (typedescription_t *)&unk_1059BCF4;
}

//------------------------------------------------------------------------------
// Address: 0x10411490
// Name: CPlayerLocalData_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void CPlayerLocalData_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  CPlayerLocalData::m_PredMap.dataNumFields = 18;
  CPlayerLocalData::m_PredMap.dataDesc = (typedescription_t *)&unk_1059BD6C;
}

//------------------------------------------------------------------------------
// Address: 0x104114B0
// Name: C_BasePlayer_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_BasePlayer_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_BasePlayer::m_PredMap.dataNumFields = 41;
  C_BasePlayer::m_PredMap.dataDesc = (typedescription_t *)&unk_1059C1E4;
}

//------------------------------------------------------------------------------
// Address: 0x10430010
// Name: DT_PlayerState::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PlayerState::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PlayerState::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10430020
// Name: DT_Local::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Local::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Local::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10430030
// Name: DT_LocalPlayerExclusive::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_LocalPlayerExclusive::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_LocalPlayerExclusive::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10430040
// Name: DT_BasePlayer::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BasePlayer::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BasePlayer::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1005EC60
// Name: _C_BasePlayer_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BasePlayer_CreateObject(int entnum, int serialNum)
{
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // eax
  C_BasePlayer *v4; // esi

  v2 = (C_BasePlayer *)C_BaseEntity::operator new(stAllocateBlock: 0x1A40u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BasePlayer::C_BasePlayer(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411420
// Name: _dynamic_initializer_for____g_C_BasePlayerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BasePlayerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BasePlayerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BasePlayerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104114D0
// Name: _dynamic_initializer_for__g_CplayerFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CplayerFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BasePlayer *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "player",
             a3: "C_BasePlayer",
             a4: 6720,
             a5: CC_BasePlayerFactory);
  __g_C_BasePlayerClientClass.m_pMapClassname = "player";
  return result;
}
