// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_instructor_hint.cpp
// Functions: 6
// ============================================================

#include "game\server\env_instructor_hint.h"

//------------------------------------------------------------------------------
// Address: 0x10114BF0
// Name: public: virtual struct datamap_t __near * CEnvInstructorHint::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvInstructorHint::GetDataDescMap(CEnvInstructorHint *this)
{
  return &CEnvInstructorHint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10114C00
// Name: public: virtual struct datamap_t __near * CInfoInstructorHintTarget::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CInfoInstructorHintTarget::GetDataDescMap(CInfoInstructorHintTarget *this)
{
  return &CInfoInstructorHintTarget::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10114C30
// Name: private: void CEnvInstructorHint::InputShowHint(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEnvInstructorHint::InputShowHint(
        CEnvInstructorHint *this@<ecx>,
        int a2@<ebx>,
        inputdata_t *inputdata)
{
  IGameEvent *v4; // esi
  const char *pszValue; // eax
  unsigned __int8 m_iPulseOption; // al
  int v7; // eax
  int v8; // edx
  unsigned __int8 m_iAlphaOption; // al
  int v10; // eax
  int v11; // edx
  unsigned __int8 m_iShakeOption; // al
  int v13; // eax
  int v14; // ecx
  bool m_bLocalPlayerOnly; // al
  CBasePlayer *LocalPlayer; // ebx
  _fieldtypes fieldType; // edx
  variant_t *p_value; // ecx
  variant_t *p_inputdata; // eax
  const char *iVal; // ecx
  const char *v21; // eax
  CBasePlayer *EntityByName; // eax
  const char *v23; // eax
  bool v24; // zf
  const char *v25; // eax
  const char *v26; // eax
  edict_t *m_pPev; // eax
  const char *v28; // eax
  const char *v29; // eax
  const char *v30; // eax
  const char *v31; // eax
  const char *v32; // eax
  int v33; // [esp+64h] [ebp-98h]
  char szColorString[128]; // [esp+70h] [ebp-8Ch] BYREF
  int iFlags; // [esp+F0h] [ebp-Ch]
  BOOL bFilterByActivator; // [esp+F4h] [ebp-8h]
  CBaseEntity *pTargetEntity; // [esp+F8h] [ebp-4h]

  v4 = gameeventmanager->CreateEventA(
         this: gameeventmanager,
         a2: "instructor_server_hint_create",
         a3: 0,
         a4: &s_InstructorServerHintEventCreate);
  if ( v4 != nullptr )
  {
    pszValue = this->m_iszHintTargetEntity.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    pTargetEntity = CGlobalEntityList::FindEntityByName(
                      this: &gEntList,
                      pStartEntity: nullptr,
                      szName: pszValue,
                      pSearchingEntity: nullptr,
                      pActivator: nullptr,
                      pCaller: nullptr,
                      pFilter: nullptr);
    if ( pTargetEntity == nullptr )
    {
      pTargetEntity = inputdata->pActivator;
      if ( pTargetEntity == nullptr )
        pTargetEntity = GetWorldEntity();
    }
    V_snprintf(
      pDest: szColorString,
      maxLen: 128,
      pFormat: "%.3d,%.3d,%.3d",
      this->m_Color.r,
      this->m_Color.g,
      this->m_Color.b);
    m_iPulseOption = this->m_iPulseOption;
    if ( m_iPulseOption != 0 )
      v7 = 1 << (m_iPulseOption - 1);
    else
      v7 = 0;
    v8 = v7;
    m_iAlphaOption = this->m_iAlphaOption;
    if ( m_iAlphaOption != 0 )
      v10 = 8 << (m_iAlphaOption - 1);
    else
      v10 = 0;
    v11 = v10 | v8;
    m_iShakeOption = this->m_iShakeOption;
    if ( m_iShakeOption != 0 )
      v13 = 64 << (m_iShakeOption - 1);
    else
      v13 = 0;
    v14 = v13 | (this->m_bStatic ? 0x100 : 0);
    m_bLocalPlayerOnly = this->m_bLocalPlayerOnly;
    v33 = a2;
    LocalPlayer = nullptr;
    iFlags = v14 | v11;
    LOBYTE(bFilterByActivator) = m_bLocalPlayerOnly;
    if ( m_bLocalPlayerOnly )
      LocalPlayer = (CBasePlayer *)__RTDynamicCast(
                                     inptr: inputdata->pActivator,
                                     VfDelta: 0,
                                     SrcType: &CBaseEntity `RTTI Type Descriptor',
                                     TargetType: &CBasePlayer `RTTI Type Descriptor',
                                     isReference: 0);
    fieldType = inputdata->value.fieldType;
    p_value = &inputdata->value;
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
        if ( iVal != nullptr )
          v21 = iVal;
        else
          v21 = locale;
      }
      else
      {
        v21 = variant_t::ToString(this: p_value);
      }
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: nullptr,
                       szName: v21,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      LocalPlayer = (CBasePlayer *)__RTDynamicCast(
                                     inptr: EntityByName,
                                     VfDelta: 0,
                                     SrcType: &CBaseEntity `RTTI Type Descriptor',
                                     TargetType: &CBasePlayer `RTTI Type Descriptor',
                                     isReference: 0);
      if ( LocalPlayer != nullptr )
        LOBYTE(bFilterByActivator) = 1;
    }
    else if ( ((unsigned __int8 (__thiscall *)(CGameRules *, int))g_pGameRules->IsMultiplayer)(
                a1: g_pGameRules,
                a2: v33) != 0 )
    {
      if ( pTargetEntity == nullptr )
        _Warning(a1: "Failed to play server side instructor hint: no player specified for hint\n");
    }
    else
    {
      LocalPlayer = UTIL_GetLocalPlayer();
    }
    v23 = this->m_iszActivatorCaption.pszValue;
    if ( v23 == nullptr || (v24 = *v23 == 0, inputdata = (inputdata_t *)this->m_iszActivatorCaption.pszValue, v24) )
    {
      inputdata = (inputdata_t *)this->m_iszCaption.pszValue;
      if ( inputdata == nullptr )
        inputdata = (inputdata_t *)locale;
    }
    v25 = this->m_iName.m_Value.pszValue;
    if ( v25 == nullptr )
      v25 = locale;
    ((void (__thiscall *)(IGameEvent *, const char *, const char *, int))v4->SetString)(
      a1: v4,
      a2: "hint_name",
      a3: v25,
      a4: v33);
    v26 = this->m_iszReplace_Key.pszValue;
    if ( v26 == nullptr )
      v26 = locale;
    v4->SetString(this: v4, a2: "hint_replace_key", a3: v26);
    m_pPev = pTargetEntity->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    v4->SetInt(this: v4, a2: "hint_target", a3: (int)m_pPev);
    if ( LocalPlayer != nullptr )
      engine->GetPlayerUserId(this: engine, a2: LocalPlayer->m_Network.m_pPev);
    ((void (__thiscall *)(IGameEvent *, const char *))v4->SetInt)(a1: v4, a2: "hint_activator_userid");
    v4->SetInt(this: v4, a2: "hint_timeout", a3: this->m_iTimeout);
    v28 = this->m_iszIcon_Onscreen.pszValue;
    if ( v28 == nullptr )
      v28 = locale;
    v4->SetString(this: v4, a2: "hint_icon_onscreen", a3: v28);
    v29 = this->m_iszIcon_Offscreen.pszValue;
    if ( v29 == nullptr )
      v29 = locale;
    v4->SetString(this: v4, a2: "hint_icon_offscreen", a3: v29);
    v30 = this->m_iszCaption.pszValue;
    if ( v30 == nullptr )
      v30 = locale;
    v4->SetString(this: v4, a2: "hint_caption", a3: v30);
    v4->SetString(this: v4, a2: "hint_activator_caption", a3: (const char *)inputdata);
    v4->SetString(this: v4, a2: "hint_color", a3: szColorString);
    ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v4->SetFloat)(
      a1: v4,
      a2: "hint_icon_offset",
      a3: LODWORD(this->m_fIconOffset));
    ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v4->SetFloat)(
      a1: v4,
      a2: "hint_range",
      a3: LODWORD(this->m_fRange));
    v4->SetInt(this: v4, a2: "hint_flags", a3: iFlags);
    v31 = this->m_iszBinding.pszValue;
    if ( v31 == nullptr )
      v31 = locale;
    v4->SetString(this: v4, a2: "hint_binding", a3: v31);
    v32 = this->m_iszGamepadBinding.pszValue;
    if ( v32 == nullptr )
      v32 = locale;
    v4->SetString(this: v4, a2: "hint_gamepad_binding", a3: v32);
    v4->SetBool(this: v4, a2: "hint_allow_nodraw_target", a3: this->m_bAllowNoDrawTarget);
    v4->SetBool(this: v4, a2: "hint_nooffscreen", a3: this->m_bNoOffscreen);
    v4->SetBool(this: v4, a2: "hint_forcecaption", a3: this->m_bForceCaption);
    v4->SetBool(this: v4, a2: "hint_local_player_only", a3: bFilterByActivator);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v4, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115040
// Name: private: void CEnvInstructorHint::InputEndHint(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvInstructorHint::InputEndHint(CEnvInstructorHint *this, inputdata_t *inputdata)
{
  IGameEvent *v3; // esi
  const char *pszValue; // eax

  v3 = gameeventmanager->CreateEventA(
         this: gameeventmanager,
         a2: "instructor_server_hint_stop",
         a3: 0,
         a4: &s_InstructorServerHintEventStop);
  if ( v3 != nullptr )
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v3->SetString(this: v3, a2: "hint_name", a3: pszValue);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v3, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104027F0
// Name: CEnvInstructorHint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvInstructorHint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvInstructorHint>();
  CEnvInstructorHint_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402820
// Name: CInfoInstructorHintTarget_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CInfoInstructorHintTarget_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CInfoInstructorHintTarget>();
  CInfoInstructorHintTarget_DataDescInit::g_DataMapHolder = result;
  return result;
}
