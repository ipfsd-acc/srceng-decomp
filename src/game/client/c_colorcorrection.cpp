// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_colorcorrection.cpp
// Functions: 11
// ============================================================

#include "game\client\c_colorcorrection.h"

//------------------------------------------------------------------------------
// Address: 0x10061C30
// Name: public: virtual class ClientClass __near * C_ColorCorrection::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_ColorCorrection::GetClientClass(C_ColorCorrection *this)
{
  return &__g_C_ColorCorrectionClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10061E00
// Name: public: virtual void C_ColorCorrection::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ColorCorrection::OnDataChanged(C_ColorCorrection *this, DataUpdateType_t updateType)
{
  const Vector *v3; // eax
  char name[260]; // [esp+8h] [ebp-208h] BYREF
  char cleanName[260]; // [esp+10Ch] [ebp-104h] BYREF

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED && LODWORD(this->m_flFadeStartTime[0]) == 0 )
  {
    V_StripExtension(in: (char *)&this->m_flMaxWeight, out: cleanName, outSize: 260);
    v3 = this->GetAbsOrigin(this);
    V_snprintf(pDest: name, maxLen: 0x104u, pFormat: "%s_%d", cleanName, v3);
    LODWORD(this->m_flFadeStartTime[0]) = CColorCorrectionMgr::AddColorCorrectionEntity(
                                            this: g_pColorCorrectionMgr,
                                            pEntity: (C_ColorCorrection *)((char *)this - 8),
                                            pName: name,
                                            pFileName: (const char *)&this->m_flMaxWeight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061E90
// Name: void UpdateColorCorrectionEntities(class C_BasePlayer __near *,float,class C_ColorCorrection __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateColorCorrectionEntities(
        C_BasePlayer *pPlayer,
        float ccScale,
        C_ColorCorrection **pList,
        int listCount)
{
  int i; // esi

  for ( i = 0; i < listCount; ++i )
    ((void (__stdcall *)(C_BasePlayer *, _DWORD))pList[i]->Update)(a1: pPlayer, a2: LODWORD(ccScale));
}

//------------------------------------------------------------------------------
// Address: 0x10061ED0
// Name: public: C_ColorCorrection::C_ColorCorrection(void)
// Source: json
//------------------------------------------------------------------------------
C_ColorCorrection *__thiscall C_ColorCorrection::C_ColorCorrection(C_ColorCorrection *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->m_minFalloff = -1.0;
  this->m_maxFalloff = -1.0;
  this->m_netLookupFilename[0] = 0;
  *(_WORD *)&this->m_bEnabled = 0;
  this->m_CCHandle = nullptr;
  *(_WORD *)&this->m_bExclusive = 0;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ColorCorrection_vtbl *)&C_ColorCorrection::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ColorCorrection::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ColorCorrection::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ColorCorrection::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ColorCorrection::`vftable';
  this->m_flFadeInDuration = 0.0;
  this->m_flFadeOutDuration = 0.0;
  *(_QWORD *)&this->m_flMaxWeight = 1065353216;
  this->m_flCurWeightOnClient[0] = 0.0;
  this->m_bFadingIn[0] = false;
  this->m_flFadeStartWeight[0] = 0.0;
  this->m_flFadeStartTime[0] = 0.0;
  this->m_flFadeDuration[0] = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062040
// Name: public: virtual void C_ColorCorrection::Update(class C_BasePlayer __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ColorCorrection::Update(C_ColorCorrection *this, C_BasePlayer *pPlayer, float ccScale)
{
  bool m_bClientSide; // cl
  ConVar *m_pParent; // eax
  bool m_bEnabled; // dl
  float v7; // xmm3_4
  float m_flMaxWeight; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float m_flCurWeight; // xmm0_4
  const Vector *v12; // eax
  float m_minFalloff; // xmm1_4
  float v14; // xmm0_4
  float m_maxFalloff; // xmm3_4
  __int64 v16; // [esp+1Ch] [ebp-28h]
  float v17; // [esp+34h] [ebp-10h]

  if ( mat_colcorrection_disableentities.m_pParent != nullptr
    && mat_colcorrection_disableentities.m_pParent->m_Value.m_nValue != 0 )
  {
    CColorCorrectionMgr::SetColorCorrectionWeight(
      this: g_pColorCorrectionMgr,
      h: this->m_CCHandle,
      flWeight: 0.0,
      bExclusive: this->m_bExclusive);
  }
  else
  {
    m_bClientSide = this->m_bClientSide;
    m_pParent = mat_colcorrection_forceentitiesclientside.m_pParent;
    if ( m_bClientSide
      || mat_colcorrection_forceentitiesclientside.m_pParent != nullptr
      && mat_colcorrection_forceentitiesclientside.m_pParent->m_Value.m_nValue != 0 )
    {
      m_bEnabled = this->m_bEnabledOnClient[0];
    }
    else
    {
      m_bEnabled = this->m_bEnabled;
    }
    v7 = 1.0;
    if ( m_bClientSide
      || mat_colcorrection_forceentitiesclientside.m_pParent != nullptr
      && mat_colcorrection_forceentitiesclientside.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( this->m_bFadingIn[0] )
        m_flMaxWeight = this->m_flMaxWeight;
      else
        m_flMaxWeight = 0.0;
      v9 = this->m_flFadeDuration[0];
      if ( v9 != 0.0 )
      {
        v10 = (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_flFadeStartTime[0]) / v9;
        if ( v10 >= 0.0 )
        {
          if ( v10 > 1.0 )
            v10 = 1.0;
        }
        else
        {
          v10 = 0.0;
        }
        v7 = v10;
      }
      this->m_flCurWeightOnClient[0] = (float)((float)(m_flMaxWeight - this->m_flFadeStartWeight[0]) * v7)
                                     + this->m_flFadeStartWeight[0];
      m_pParent = mat_colcorrection_forceentitiesclientside.m_pParent;
    }
    if ( this->m_bClientSide || m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      m_flCurWeight = this->m_flCurWeightOnClient[0];
    else
      m_flCurWeight = this->m_flCurWeight;
    v17 = m_flCurWeight;
    if ( m_bEnabled || m_flCurWeight != 0.0 )
    {
      v12 = pPlayer->GetAbsOrigin(this: pPlayer);
      m_minFalloff = this->m_minFalloff;
      v14 = 0.0;
      if ( m_minFalloff != -1.0 )
      {
        m_maxFalloff = this->m_maxFalloff;
        if ( m_maxFalloff != -1.0 && m_minFalloff != m_maxFalloff )
        {
          v16 = *(_QWORD *)&v12->x;
          v14 = (float)(fsqrt(
                          (float)((float)((float)(*((float *)&v16 + 1) - this->m_vecOrigin.y)
                                        * (float)(*((float *)&v16 + 1) - this->m_vecOrigin.y))
                                + (float)((float)(v12->z - this->m_vecOrigin.z) * (float)(v12->z - this->m_vecOrigin.z)))
                        + (float)((float)(*(float *)&v16 - this->m_vecOrigin.x)
                                * (float)(*(float *)&v16 - this->m_vecOrigin.x)))
                      - this->m_minFalloff)
              / (float)(m_maxFalloff - this->m_minFalloff);
          if ( v14 >= 0.0 )
          {
            if ( v14 > 1.0 )
              v14 = 1.0;
          }
          else
          {
            v14 = 0.0;
          }
        }
      }
      CColorCorrectionMgr::SetColorCorrectionWeight(
        this: g_pColorCorrectionMgr,
        h: this->m_CCHandle,
        flWeight: (float)((float)(1.0 - v14) * v17) * ccScale,
        bExclusive: this->m_bExclusive);
    }
    else
    {
      CColorCorrectionMgr::SetColorCorrectionWeight(
        this: g_pColorCorrectionMgr,
        h: this->m_CCHandle,
        flWeight: 0.0,
        bExclusive: this->m_bExclusive);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100622A0
// Name: public: void C_ColorCorrection::EnableOnClient(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ColorCorrection::EnableOnClient(C_ColorCorrection *this, bool bEnable, bool bSkipFade)
{
  float v3; // xmm4_4
  float v4; // xmm0_4
  float m_flMaxWeight; // xmm3_4
  float v6; // xmm2_4
  bool v7; // al
  float m_flFadeInDuration; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4

  if ( (this->m_bClientSide
     || mat_colcorrection_forceentitiesclientside.m_pParent != nullptr
     && mat_colcorrection_forceentitiesclientside.m_pParent->m_Value.m_nValue != 0)
    && this->m_bEnabledOnClient[0] != bEnable )
  {
    v3 = 1.0;
    this->m_bFadingIn[0] = bEnable;
    this->m_bEnabledOnClient[0] = bEnable;
    v4 = this->m_flCurWeightOnClient[0];
    this->m_flFadeStartWeight[0] = v4;
    m_flMaxWeight = this->m_flMaxWeight;
    v6 = 1.0;
    if ( m_flMaxWeight != 0.0 )
      v6 = v4 / m_flMaxWeight;
    v7 = this->m_bFadingIn[0];
    if ( v7 )
      v6 = 1.0 - v6;
    if ( bSkipFade )
      v6 = 0.0;
    if ( v7 )
      m_flFadeInDuration = this->m_flFadeInDuration;
    else
      m_flFadeInDuration = this->m_flFadeOutDuration;
    v9 = m_flFadeInDuration * v6;
    this->m_flFadeStartTime[0] = *(float *)(gpGlobals.m_Index + 12);
    if ( v9 <= 0.0 )
      v10 = 0.0;
    else
      v10 = v9;
    this->m_flFadeDuration[0] = v10;
    if ( this->m_bFadingIn[0] )
      v11 = this->m_flMaxWeight;
    else
      v11 = 0.0;
    if ( v10 != 0.0 )
    {
      v12 = (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_flFadeStartTime[0]) / v10;
      if ( v12 >= 0.0 )
      {
        if ( v12 > 1.0 )
          v12 = 1.0;
      }
      else
      {
        v12 = 0.0;
      }
      v3 = v12;
    }
    this->m_flCurWeightOnClient[0] = (float)((float)(v11 - this->m_flFadeStartWeight[0]) * v3)
                                   + this->m_flFadeStartWeight[0];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10411850
// Name: DT_ColorCorrection::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ColorCorrection::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_ColorCorrection::g_RecvTable);
  return atexit(func: DT_ColorCorrection::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411870
// Name: DT_ColorCorrection::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ColorCorrection::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_ColorCorrection::ignored>();
  DT_ColorCorrection::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430110
// Name: DT_ColorCorrection::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ColorCorrection::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_ColorCorrection::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10061FF0
// Name: _C_ColorCorrection_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_ColorCorrection_CreateObject(int entnum, int serialNum)
{
  C_ColorCorrection *v2; // eax
  C_ColorCorrection *v3; // eax
  C_ColorCorrection *v4; // esi

  v2 = (C_ColorCorrection *)C_BaseEntity::operator new(stAllocateBlock: 0xAC8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_ColorCorrection::C_ColorCorrection(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411880
// Name: _dynamic_initializer_for____g_C_ColorCorrectionVolumeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_ColorCorrectionVolumeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_ColorCorrectionVolumeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_ColorCorrectionVolumeClientClass;
  return result;
}
