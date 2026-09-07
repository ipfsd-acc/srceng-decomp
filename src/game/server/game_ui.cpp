// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/game_ui.cpp
// Functions: 8
// ============================================================

#include "game\server\game_ui.h"

//------------------------------------------------------------------------------
// Address: 0x1013DF50
// Name: public: virtual struct datamap_t __near * CGameUI::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CGameUI::GetDataDescMap(CGameUI *this)
{
  return &CGameUI::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013DF70
// Name: public: CGameUI::CGameUI(void)
// Source: json
//------------------------------------------------------------------------------
CGameUI *__thiscall CGameUI::CGameUI(CGameUI *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CGameUI_vtbl *)&CGameUI::`vftable';
  this->m_hSaveWeapon.m_Index = -1;
  this->m_playerOn.m_Value.iVal = 0;
  this->m_playerOn.m_Value.eVal.m_Index = -1;
  this->m_playerOn.m_Value.fieldType = FIELD_VOID;
  this->m_playerOff.m_Value.iVal = 0;
  this->m_playerOff.m_Value.eVal.m_Index = -1;
  this->m_playerOff.m_Value.fieldType = FIELD_VOID;
  this->m_pressedMoveLeft.m_Value.iVal = 0;
  this->m_pressedMoveLeft.m_Value.eVal.m_Index = -1;
  this->m_pressedMoveLeft.m_Value.fieldType = FIELD_VOID;
  this->m_pressedMoveRight.m_Value.iVal = 0;
  this->m_pressedMoveRight.m_Value.eVal.m_Index = -1;
  this->m_pressedMoveRight.m_Value.fieldType = FIELD_VOID;
  this->m_pressedForward.m_Value.iVal = 0;
  this->m_pressedForward.m_Value.eVal.m_Index = -1;
  this->m_pressedForward.m_Value.fieldType = FIELD_VOID;
  this->m_pressedBack.m_Value.iVal = 0;
  this->m_pressedBack.m_Value.eVal.m_Index = -1;
  this->m_pressedBack.m_Value.fieldType = FIELD_VOID;
  this->m_pressedAttack.m_Value.iVal = 0;
  this->m_pressedAttack.m_Value.eVal.m_Index = -1;
  this->m_pressedAttack.m_Value.fieldType = FIELD_VOID;
  this->m_pressedAttack2.m_Value.iVal = 0;
  this->m_pressedAttack2.m_Value.eVal.m_Index = -1;
  this->m_pressedAttack2.m_Value.fieldType = FIELD_VOID;
  this->m_unpressedMoveLeft.m_Value.iVal = 0;
  this->m_unpressedMoveLeft.m_Value.eVal.m_Index = -1;
  this->m_unpressedMoveLeft.m_Value.fieldType = FIELD_VOID;
  this->m_unpressedMoveRight.m_Value.iVal = 0;
  this->m_unpressedMoveRight.m_Value.eVal.m_Index = -1;
  this->m_unpressedMoveRight.m_Value.fieldType = FIELD_VOID;
  this->m_unpressedForward.m_Value.iVal = 0;
  this->m_unpressedForward.m_Value.eVal.m_Index = -1;
  this->m_unpressedForward.m_Value.fieldType = FIELD_VOID;
  this->m_unpressedBack.m_Value.iVal = 0;
  this->m_unpressedBack.m_Value.eVal.m_Index = -1;
  this->m_unpressedBack.m_Value.fieldType = FIELD_VOID;
  this->m_unpressedAttack.m_Value.iVal = 0;
  this->m_unpressedAttack.m_Value.eVal.m_Index = -1;
  this->m_unpressedAttack.m_Value.fieldType = FIELD_VOID;
  this->m_unpressedAttack2.m_Value.iVal = 0;
  this->m_unpressedAttack2.m_Value.eVal.m_Index = -1;
  this->m_unpressedAttack2.m_Value.fieldType = FIELD_VOID;
  this->m_xaxis.m_Value.iVal = 0;
  this->m_xaxis.m_Value.eVal.m_Index = -1;
  this->m_xaxis.m_Value.fieldType = FIELD_VOID;
  this->m_yaxis.m_Value.iVal = 0;
  this->m_yaxis.m_Value.eVal.m_Index = -1;
  this->m_yaxis.m_Value.fieldType = FIELD_VOID;
  this->m_attackaxis.m_Value.iVal = 0;
  this->m_attackaxis.m_Value.eVal.m_Index = -1;
  this->m_attackaxis.m_Value.fieldType = FIELD_VOID;
  this->m_attack2axis.m_Value.iVal = 0;
  this->m_attack2axis.m_Value.eVal.m_Index = -1;
  this->m_attack2axis.m_Value.fieldType = FIELD_VOID;
  this->m_player.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013E0E0
// Name: public: virtual CGameUI::~CGameUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::~CGameUI(CGameUI *this)
{
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_attack2axis);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_attackaxis);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_yaxis);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_xaxis);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_unpressedAttack2);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_unpressedAttack);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_unpressedBack);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_unpressedForward);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_unpressedMoveRight);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_unpressedMoveLeft);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_pressedAttack2);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_pressedAttack);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_pressedBack);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_pressedForward);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_pressedMoveRight);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_pressedMoveLeft);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_playerOff);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_playerOn);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013E1F0
// Name: public: void CGameUI::Deactivate(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::Deactivate(CGameUI *this, IHandleEntity_vtbl *pActivator)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  IHandleEntity *v7; // ebx
  int v8; // eax
  bool v9; // zf
  CBaseEntity **v10; // eax
  CBaseEntity *v11; // eax
  IHandleEntity_vtbl *v12; // ecx
  unsigned int v13; // esi
  int v14; // edx
  int v15; // eax
  CBaseEntity *v16; // esi
  CEntInfo *v17; // eax
  unsigned int v18; // eax
  IHandleEntity *m_pEntity; // ecx
  int v20; // edx
  IHandleEntity *v21; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  const char *dtr_IHandleEntity; // ecx
  const char *pszValue; // eax

  m_Index = this->m_player.m_Index;
  if ( m_Index != -1
    && (v4 = (unsigned __int16)m_Index,
        v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v6 = HIWORD(m_Index),
        v5->m_SerialNumber == v6)
    && (v7 = v5->m_pEntity, v5->m_pEntity != nullptr) )
  {
    if ( (this->m_spawnflags.m_Value & 0x20) != 0 )
    {
      v8 = v4;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v6;
      v10 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        v11 = *v10;
      else
        v11 = nullptr;
      CBaseEntity::RemoveFlag(this: v11, flagsToRemove: 128);
    }
    if ( (this->m_spawnflags.m_Value & 0x40) != 0 )
    {
      v12 = v7[587].__vftable;
      pActivator = (IHandleEntity_vtbl *)((unsigned int)v12 & 0xFFFFFFFE);
      if ( v12 != (IHandleEntity_vtbl *)((unsigned int)v12 & 0xFFFFFFFE) )
      {
        ((void (__thiscall *)(IHandleEntity *, IHandleEntity *))v7[572].dtr_IHandleEntity)(a1: &v7[572], a2: &v7[587]);
        v7[587].__vftable = pActivator;
      }
      v13 = this->m_hSaveWeapon.m_Index;
      if ( v13 != -1 )
      {
        v14 = (unsigned __int16)v13;
        v15 = (unsigned __int16)v13;
        v16 = (CBaseEntity *)HIWORD(v13);
        v17 = &g_pEntityList->m_EntPtrArray[v15];
        pActivator = (IHandleEntity_vtbl *)v16;
        if ( (CBaseEntity *)v17->m_SerialNumber == v16 && v17->m_pEntity != nullptr )
        {
          v18 = this->m_player.m_Index;
          if ( v18 == -1
            || (v16 = (CBaseEntity *)pActivator,
                g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18)) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
          }
          v20 = v14;
          if ( (CBaseEntity *)g_pEntityList->m_EntPtrArray[v20].m_SerialNumber == v16 )
            v21 = g_pEntityList->m_EntPtrArray[v20].m_pEntity;
          else
            v21 = nullptr;
          ((void (__thiscall *)(IHandleEntity *, IHandleEntity *, _DWORD))m_pEntity->__vftable[93].dtr_IHandleEntity)(
            a1: m_pEntity,
            a2: v21,
            a3: 0);
          this->m_hSaveWeapon.m_Index = -1;
        }
      }
      if ( CBaseCombatCharacter::GetActiveWeapon(this: (CBaseCombatCharacter *)v7) != nullptr )
      {
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: (CBaseCombatCharacter *)v7);
        ActiveWeapon->Deploy(this: ActiveWeapon);
      }
    }
    COutputEvent::FireOutput(this: &this->m_playerOff, pActivator: (CBaseEntity *)v7, pCaller: this, fDelay: 0.0);
    pActivator = nullptr;
    variant_t::Set(
      this: &this->m_xaxis.m_Value,
      ftype: FIELD_FLOAT,
      data: ($3B1CACFA647AB85A7D70EA6016B49717 *)&pActivator);
    CBaseEntityOutput::FireOutput(
      this: &this->m_xaxis,
      Value: this->m_xaxis.m_Value,
      pActivator: (CBaseEntity *)v7,
      pCaller: this,
      fDelay: 0.0);
    pActivator = nullptr;
    variant_t::Set(
      this: &this->m_yaxis.m_Value,
      ftype: FIELD_FLOAT,
      data: ($3B1CACFA647AB85A7D70EA6016B49717 *)&pActivator);
    CBaseEntityOutput::FireOutput(
      this: &this->m_yaxis,
      Value: this->m_yaxis.m_Value,
      pActivator: (CBaseEntity *)v7,
      pCaller: this,
      fDelay: 0.0);
    pActivator = nullptr;
    variant_t::Set(
      this: &this->m_attackaxis.m_Value,
      ftype: FIELD_FLOAT,
      data: ($3B1CACFA647AB85A7D70EA6016B49717 *)&pActivator);
    CBaseEntityOutput::FireOutput(
      this: &this->m_attackaxis,
      Value: this->m_attackaxis.m_Value,
      pActivator: (CBaseEntity *)v7,
      pCaller: this,
      fDelay: 0.0);
    pActivator = nullptr;
    variant_t::Set(
      this: &this->m_attack2axis.m_Value,
      ftype: FIELD_FLOAT,
      data: ($3B1CACFA647AB85A7D70EA6016B49717 *)&pActivator);
    CBaseEntityOutput::FireOutput(
      this: &this->m_attack2axis,
      Value: this->m_attack2axis.m_Value,
      pActivator: (CBaseEntity *)v7,
      pCaller: this,
      fDelay: 0.0);
    this->m_nLastButtonState = 0;
    this->m_player.m_Index = -1;
  }
  else
  {
    dtr_IHandleEntity = (const char *)pActivator[17].dtr_IHandleEntity;
    if ( dtr_IHandleEntity == nullptr )
      dtr_IHandleEntity = locale;
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "%s Deactivate(): I have no player when called by %s!\n", pszValue, dtr_IHandleEntity);
  }
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1013E5C0
// Name: public: void CGameUI::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::InputActivate(CGameUI *this, inputdata_t *inputdata)
{
  inputdata_t *v2; // ebx
  _fieldtypes fieldType; // eax
  variant_t *p_value; // esi
  CGameUI *v5; // edi
  variant_t *p_inputdata; // ecx
  const char *iVal; // eax
  CBasePlayer *EntityByName; // ebx
  CBaseEntity *pActivator; // esi
  const char *v10; // esi
  const char *v11; // eax
  const char *pszValue; // ecx
  unsigned int m_Index; // ecx
  CHandle<CBaseEntity> *p_m_player; // ebx
  int v15; // eax
  CEntInfo *v16; // edx
  unsigned int v17; // ecx
  int v18; // eax
  bool v19; // zf
  CEntInfo *v20; // eax
  CBaseEntity *v21; // eax
  CBaseEntity *v22; // eax
  CHandle<CBaseEntity> *p_eVal; // esi
  int v24; // edi
  CBaseCombatCharacter *v25; // eax
  CBaseCombatCharacter *v26; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBaseCombatCharacter *v28; // eax
  CBaseCombatWeapon *v29; // eax
  CBaseCombatCharacter *v30; // eax
  CBasePlayer *v31; // eax
  const char *v32; // esi
  const char *v33; // eax
  const char *v34; // ecx

  v2 = inputdata;
  fieldType = inputdata->value.fieldType;
  p_value = &inputdata->value;
  v5 = this;
  if ( fieldType == FIELD_STRING )
  {
    p_inputdata = &inputdata->value;
  }
  else
  {
    inputdata = nullptr;
    p_inputdata = (variant_t *)&inputdata;
  }
  if ( p_inputdata->iVal != 0 )
  {
    if ( fieldType == FIELD_STRING )
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
                     pSearchingEntity: v5,
                     pActivator: v2->pActivator,
                     pCaller: v2->pCaller,
                     pFilter: nullptr);
    if ( EntityByName == nullptr || !EntityByName->IsPlayer(this: EntityByName) )
    {
      if ( p_value->fieldType == FIELD_STRING )
      {
        v10 = (const char *)p_value->iVal;
        if ( v10 != nullptr )
          v11 = v10;
        else
          v11 = locale;
      }
      else
      {
        v11 = variant_t::ToString(this: p_value);
      }
      pszValue = v5->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      _Warning(a1: "%s InputActivate: entity %s not found or is not a player!\n", pszValue, v11);
      return;
    }
    pActivator = EntityByName->IsPlayer(this: EntityByName) ? EntityByName : nullptr;
  }
  else
  {
    if ( v2->pActivator == nullptr || !v2->pActivator->IsPlayer(this: v2->pActivator) )
    {
      if ( p_value->fieldType == FIELD_STRING )
      {
        v32 = (const char *)p_value->iVal;
        if ( v32 != nullptr )
          v33 = v32;
        else
          v33 = locale;
      }
      else
      {
        v33 = variant_t::ToString(this: p_value);
      }
      v34 = v5->m_iName.m_Value.pszValue;
      if ( v34 == nullptr )
        v34 = locale;
      _Warning(a1: "%s InputActivate (%s): invalid or missing !activator!\n", v34, v33);
      return;
    }
    pActivator = v2->pActivator;
    if ( v2->pActivator == nullptr || !pActivator->IsPlayer(this: v2->pActivator) )
      pActivator = nullptr;
  }
  m_Index = v5->m_player.m_Index;
  p_m_player = (CHandle<CBaseEntity> *)&v5->m_player;
  if ( m_Index != -1 )
  {
    v15 = (unsigned __int16)m_Index;
    v16 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v17 = HIWORD(m_Index);
    if ( v16->m_SerialNumber == v17 && v16->m_pEntity != nullptr )
    {
      v18 = v15;
      v19 = g_pEntityList->m_EntPtrArray[v18].m_SerialNumber == v17;
      v20 = &g_pEntityList->m_EntPtrArray[v18];
      v21 = v19 ? (CBaseEntity *)v20->m_pEntity : nullptr;
      if ( pActivator != v21 )
        return;
    }
    v5 = this;
  }
  if ( pActivator != nullptr )
    p_m_player->m_Index = pActivator->GetRefEHandle(this: pActivator)->m_Index;
  else
    p_m_player->m_Index = -1;
  COutputEvent::FireOutput(this: &v5->m_playerOn, pActivator, pCaller: v5, fDelay: 0.0);
  CBaseEntity::SetNextThink(this: v5, thinkTime: gpGlobals->curtime, szContext: nullptr);
  if ( (v5->m_spawnflags.m_Value & 0x20) != 0 )
  {
    v22 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_player);
    CBaseEntity::AddFlag(this: v22, flags: 128);
  }
  if ( (v5->m_spawnflags.m_Value & 0x40) != 0 )
  {
    p_eVal = &CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_player)[2].m_OnUser4.m_Value.eVal;
    v24 = p_eVal->m_Index | 1;
    if ( p_eVal->m_Index != v24 )
    {
      (*(void (__thiscall **)(unsigned int *, CHandle<CBaseEntity> *))p_eVal[-15].m_Index)(
        a1: &p_eVal[-15].m_Index,
        a2: p_eVal);
      p_eVal->m_Index = v24;
    }
    v25 = (CBaseCombatCharacter *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_player);
    if ( CBaseCombatCharacter::GetActiveWeapon(this: v25) != nullptr )
    {
      v26 = (CBaseCombatCharacter *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_player);
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v26);
      CHandle<CBaseEntity>::operator=(this: (CHandle<CBaseEntity> *)&this->m_hSaveWeapon, val: ActiveWeapon);
      v28 = (CBaseCombatCharacter *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_player);
      v29 = CBaseCombatCharacter::GetActiveWeapon(this: v28);
      v29->Holster(this: v29, a2: nullptr);
      v30 = (CBaseCombatCharacter *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_player);
      CBaseCombatCharacter::SetActiveWeapon(this: v30, pNewWeapon: nullptr);
      v31 = (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_player);
      CBasePlayer::HideViewModels(this: v31);
    }
    v5 = this;
  }
  v5->m_bForceUpdate = true;
}

//------------------------------------------------------------------------------
// Address: 0x1013E880
// Name: public: virtual void CGameUI::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::Think(CGameUI *this)
{
  unsigned int m_Index; // eax
  CBasePlayer **v3; // ecx
  CBasePlayer *v4; // edi
  float *v5; // eax
  int m_afButtonPressed; // eax
  int m_nLastButtonState; // eax
  float v8; // xmm0_4
  int v9; // ebx
  COutputEvent *p_m_unpressedMoveRight; // ecx
  COutputEvent *p_m_unpressedMoveLeft; // ecx
  COutputEvent *p_m_unpressedForward; // ecx
  COutputEvent *p_m_unpressedBack; // ecx
  COutputEvent *p_m_unpressedAttack; // ecx
  COutputEvent *p_m_unpressedAttack2; // ecx
  bool v16; // zf
  float value; // xmm1_4
  int m_nButtons; // eax
  Vector vPlayerFacing; // [esp+14h] [ebp-24h] BYREF
  Vector vPlayerToUI; // [esp+20h] [ebp-18h] BYREF
  float attack2; // [esp+2Ch] [ebp-Ch]
  float attack; // [esp+30h] [ebp-8h]
  float y; // [esp+34h] [ebp-4h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  m_Index = this->m_player.m_Index;
  if ( m_Index == -1
    || (v3 = (CBasePlayer **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index))
    || (v4 = *v3, *v3 == nullptr) )
  {
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    return;
  }
  if ( this->m_bForceUpdate )
    this->m_nLastButtonState = v4->m_nButtons;
  if ( this->m_flFieldOfView > -1.0 )
  {
    CBasePlayer::EyeVectors(this: v4, pForward: &vPlayerFacing, pRight: nullptr, pUp: nullptr);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v5 = (float *)v4->WorldSpaceCenter(this: v4);
    vPlayerToUI.x = this->m_vecAbsOrigin.x - *v5;
    vPlayerToUI.y = this->m_vecAbsOrigin.y - v5[1];
    vPlayerToUI.z = this->m_vecAbsOrigin.z - v5[2];
    VectorNormalize(vec: &vPlayerToUI);
    if ( this->m_flFieldOfView > (float)((float)((float)(vPlayerFacing.y * vPlayerToUI.y)
                                               + (float)(vPlayerToUI.x * vPlayerFacing.x))
                                       + (float)(vPlayerFacing.z * vPlayerToUI.z)) )
      goto LABEL_11;
  }
  if ( (CBaseEntity::AddFlag(this: v4, flags: 16),
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr),
        ((m_afButtonPressed = v4->m_afButtonPressed) & 0x20) != 0)
    && SLOBYTE(this->m_spawnflags.m_Value) < 0
    || (m_afButtonPressed & 2) != 0 && (this->m_spawnflags.m_Value & 0x100) != 0 )
  {
LABEL_11:
    CGameUI::Deactivate(this, pActivator: (IHandleEntity_vtbl *)v4);
    return;
  }
  m_nLastButtonState = this->m_nLastButtonState;
  v8 = 0.0;
  v9 = m_nLastButtonState ^ v4->m_nButtons;
  if ( (v9 & 0x400) != 0 )
  {
    p_m_unpressedMoveRight = &this->m_unpressedMoveRight;
    if ( (m_nLastButtonState & 0x400) == 0 )
      p_m_unpressedMoveRight = &this->m_pressedMoveRight;
    COutputEvent::FireOutput(this: p_m_unpressedMoveRight, pActivator: v4, pCaller: this, fDelay: 0.0);
    v8 = 0.0;
  }
  if ( (v9 & 0x200) != 0 )
  {
    p_m_unpressedMoveLeft = &this->m_unpressedMoveLeft;
    if ( (this->m_nLastButtonState & 0x200) == 0 )
      p_m_unpressedMoveLeft = &this->m_pressedMoveLeft;
    COutputEvent::FireOutput(this: p_m_unpressedMoveLeft, pActivator: v4, pCaller: this, fDelay: 0.0);
    v8 = 0.0;
  }
  if ( (v9 & 8) != 0 )
  {
    p_m_unpressedForward = &this->m_unpressedForward;
    if ( (this->m_nLastButtonState & 8) == 0 )
      p_m_unpressedForward = &this->m_pressedForward;
    COutputEvent::FireOutput(this: p_m_unpressedForward, pActivator: v4, pCaller: this, fDelay: 0.0);
    v8 = 0.0;
  }
  if ( (v9 & 0x10) != 0 )
  {
    p_m_unpressedBack = &this->m_unpressedBack;
    if ( (this->m_nLastButtonState & 0x10) == 0 )
      p_m_unpressedBack = &this->m_pressedBack;
    COutputEvent::FireOutput(this: p_m_unpressedBack, pActivator: v4, pCaller: this, fDelay: 0.0);
    v8 = 0.0;
  }
  if ( (v9 & 1) != 0 )
  {
    p_m_unpressedAttack = &this->m_unpressedAttack;
    if ( (this->m_nLastButtonState & 1) == 0 )
      p_m_unpressedAttack = &this->m_pressedAttack;
    COutputEvent::FireOutput(this: p_m_unpressedAttack, pActivator: v4, pCaller: this, fDelay: 0.0);
    v8 = 0.0;
  }
  if ( (v9 & 0x800) != 0 )
  {
    p_m_unpressedAttack2 = &this->m_unpressedAttack2;
    if ( (this->m_nLastButtonState & 0x800) == 0 )
      p_m_unpressedAttack2 = &this->m_pressedAttack2;
    COutputEvent::FireOutput(this: p_m_unpressedAttack2, pActivator: v4, pCaller: this, fDelay: 0.0);
    v8 = 0.0;
  }
  this->m_nLastButtonState = v4->m_nButtons;
  v16 = (v4->m_nButtons & 0x400) == 0;
  value = 0.0;
  y = 0.0;
  attack = 0.0;
  attack2 = 0.0;
  if ( v16 )
  {
    if ( (v4->m_nButtons & 0x200) != 0 )
      value = -1.0;
  }
  else
  {
    value = 1.0;
  }
  m_nButtons = v4->m_nButtons;
  if ( (m_nButtons & 8) != 0 )
  {
    v8 = 1.0;
LABEL_48:
    y = v8;
    goto LABEL_49;
  }
  if ( (m_nButtons & 0x10) != 0 )
  {
    v8 = -1.0;
    goto LABEL_48;
  }
LABEL_49:
  if ( (m_nButtons & 1) != 0 )
    attack = 1.0;
  if ( (m_nButtons & 0x800) != 0 )
    attack2 = 1.0;
  if ( this->m_bForceUpdate || this->m_xaxis.m_Value.flVal != value )
  {
    CEntityOutputTemplate<float,1>::Set(this: &this->m_xaxis, value, pActivator: v4, pCaller: this);
    v8 = y;
  }
  if ( this->m_bForceUpdate || this->m_yaxis.m_Value.flVal != v8 )
    CEntityOutputTemplate<float,1>::Set(this: &this->m_yaxis, value: v8, pActivator: v4, pCaller: this);
  if ( this->m_bForceUpdate || this->m_attackaxis.m_Value.flVal != attack )
    CEntityOutputTemplate<float,1>::Set(this: &this->m_attackaxis, value: attack, pActivator: v4, pCaller: this);
  if ( this->m_bForceUpdate || this->m_attack2axis.m_Value.flVal != attack2 )
    CEntityOutputTemplate<float,1>::Set(this: &this->m_attack2axis, value: attack2, pActivator: v4, pCaller: this);
  this->m_bForceUpdate = false;
}

//------------------------------------------------------------------------------
// Address: 0x1013EC70
// Name: public: void CGameUI::InputDeactivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::InputDeactivate(CGameUI *this, inputdata_t *inputdata)
{
  CGameUI::Deactivate(this, pActivator: (IHandleEntity_vtbl *)inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x10404650
// Name: CGameUI_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGameUI_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGameUI>();
  CGameUI_DataDescInit::g_DataMapHolder = result;
  return result;
}
