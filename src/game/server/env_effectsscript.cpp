// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_effectsscript.cpp
// Functions: 41
// ============================================================

#include "game\server\env_effectsscript.h"

//------------------------------------------------------------------------------
// Address: 0x101121C0
// Name: public: void CSprite::FadeAndDie(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::FadeAndDie(CSprite *this, float duration)
{
  CSprite::SetBrightness(this, brightness: 0, time: duration);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CSprite::AnimateUntilDead,
    thinkTime: 0.0,
    szContext: nullptr);
  this->m_flDieTime = gpGlobals->curtime + duration;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10112230
// Name: bool ParseToken(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ParseToken()
{
  const char *v1; // eax

  if ( g_bUnget )
  {
    g_bUnget = false;
    return true;
  }
  else
  {
    v1 = engine->ParseFile(this: engine, a2: currenttoken, a3: token, a4: 1204);
    ++tokencount;
    currenttoken = v1;
    return v1 != nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112280
// Name: public: virtual struct datamap_t __near * CEnvEffectsScript::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvEffectsScript::GetDataDescMap(CEnvEffectsScript *this)
{
  return &CEnvEffectsScript::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10112290
// Name: public: virtual void CEnvEffectsScript::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEffectsScript::Think(CEnvEffectsScript *this)
{
  this->StudioFrameAdvance(this);
  this->DispatchAnimEvents(this, a2: this);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101122D0
// Name: public: virtual void CEnvEffectsScript::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEffectsScript::Spawn(CEnvEffectsScript *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+14h] [ebp-4h] BYREF

  this->Precache(this);
  vgui::ListViewPanel::Paint((vgui::ListViewPanel *)this);
  v2 = *(const char **)((int (__thiscall *)(CEnvEffectsScript *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CBaseEntity::AddEffects(this, nEffects: 32);
  CBaseEntity::ThinkSet(this, func:  __thiscall CBaseEntity::`vcall'{200,{flat}}, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10112400
// Name: public: class CEffectScriptElement __near * CEnvEffectsScript::GetScriptElementByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CEffectScriptElement *__thiscall CEnvEffectsScript::GetScriptElementByName(CEnvEffectsScript *this, const char *pName)
{
  int v3; // ebx
  CEffectScriptElement *v4; // esi
  int i; // [esp+Ch] [ebp-4h]

  v3 = 0;
  if ( this->m_ScriptElements.m_Size <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v4 = &this->m_ScriptElements.m_Memory.m_pMemory[i];
    if ( v4 != nullptr && _V_stricmp(s1: v4->m_szEffectName, s2: pName) == 0 )
      break;
    if ( ++v3 >= this->m_ScriptElements.m_Size )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10112470
// Name: public: CEffectScriptElement::CEffectScriptElement(class CEffectScriptElement const __near &)
// Source: json
//------------------------------------------------------------------------------
CEffectScriptElement *__thiscall CEffectScriptElement::CEffectScriptElement(
        CEffectScriptElement *this,
        const CEffectScriptElement *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10112550
// Name: public: void CEnvEffectsScript::InputSetSequence(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEffectsScript::InputSetSequence(CEnvEffectsScript *this, inputdata_t *inputdata)
{
  variant_t *p_value; // eax
  _fieldtypes fieldType; // ecx
  variant_t *p_inputdata; // edx
  const char *iVal; // eax
  int v7; // eax
  edict_t *m_pPev; // ecx
  edict_t *v9; // ecx

  p_value = &inputdata->value;
  fieldType = inputdata->value.fieldType;
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
    if ( fieldType != FIELD_STRING )
    {
      inputdata = nullptr;
      p_value = (variant_t *)&inputdata;
    }
    iVal = (const char *)p_value->iVal;
    if ( iVal == nullptr )
      iVal = locale;
    v7 = CBaseAnimating::LookupSequence(this, label: iVal);
    if ( v7 != -1 )
    {
      CBaseAnimating::SetSequence(this, nSequence: v7);
      CBaseAnimating::ResetSequenceInfo(this);
      if ( this->m_flCycle.m_Value != 0.0 )
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
        this->m_flCycle.m_Value = 0.0;
      }
      if ( this->m_flPlaybackRate.m_Value != 1.0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v9 = this->m_Network.m_pPev;
          if ( v9 != nullptr )
            CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x37Cu);
        }
        this->m_flPlaybackRate.m_Value = 1.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112860
// Name: public: void CEnvEffectsScript::ParseNewEffect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEffectsScript::ParseNewEffect(CEnvEffectsScript *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  long double v7; // st7
  CEffectScriptElement NewElement; // [esp+0h] [ebp-1B4h] BYREF
  float flTextureScale; // [esp+1B0h] [ebp-4h]

  NewElement.m_pTrail.m_Index = -1;
  NewElement.m_pSprite.m_Index = -1;
  NewElement.m_flScale = 1.0;
  NewElement.m_flFadeTime = 1.0;
  NewElement.m_iType = 0;
  NewElement.m_iRenderType = 5;
  NewElement.m_iR = 255;
  NewElement.m_iG = 0;
  NewElement.m_iB = 0;
  NewElement.m_iA = 255;
  NewElement.m_flTextureRes = -1.0;
  *(_WORD *)&NewElement.m_bStopFollowOnKill = 0;
  if ( g_bUnget )
  {
    g_bUnget = false;
  }
  else
  {
    v2 = engine->ParseFile(this: engine, a2: currenttoken, a3: token, a4: 1204);
    ++tokencount;
    currenttoken = v2;
  }
  V_strncpy(pDest: NewElement.m_szEffectName, pSrc: token, maxLen: 128);
  do
  {
    if ( g_bUnget )
    {
      g_bUnget = false;
    }
    else
    {
      v3 = engine->ParseFile(this: engine, a2: currenttoken, a3: token, a4: 1204);
      ++tokencount;
      currenttoken = v3;
    }
    if ( _V_stricmp(s1: token, s2: "effect") == 0 )
    {
      g_bUnget = true;
      goto LABEL_42;
    }
  }
  while ( _V_stricmp(s1: token, s2: "{") != 0 );
  while ( 1 )
  {
    if ( g_bUnget )
    {
      g_bUnget = false;
    }
    else
    {
      v4 = engine->ParseFile(this: engine, a2: currenttoken, a3: token, a4: 1204);
      ++tokencount;
      currenttoken = v4;
    }
    if ( _V_stricmp(s1: token, s2: "}") == 0 )
      break;
    if ( _V_stricmp(s1: token, s2: "type") != 0 )
    {
      if ( _V_stricmp(s1: token, s2: "material") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "attachment") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "color") != 0 )
          {
            if ( _V_stricmp(s1: token, s2: "scale") != 0 )
            {
              if ( _V_stricmp(s1: token, s2: "texturescale") != 0 )
              {
                if ( _V_stricmp(s1: token, s2: "fadetime") != 0 )
                {
                  if ( _V_stricmp(s1: token, s2: "stopfollowonkill") == 0 )
                  {
                    ParseToken();
                    NewElement.m_bStopFollowOnKill = atoi(nptr: token) != 0;
                  }
                }
                else
                {
                  ParseToken();
                  NewElement.m_flFadeTime = atof(nptr: token);
                }
              }
              else
              {
                ParseToken();
                v7 = atof(nptr: token);
                flTextureScale = v7;
                if ( v7 <= 0.0 )
                  NewElement.m_flTextureRes = 0.0;
                else
                  NewElement.m_flTextureRes = 1.0 / flTextureScale;
              }
            }
            else
            {
              ParseToken();
              NewElement.m_flScale = atof(nptr: token);
            }
          }
          else
          {
            ParseToken();
            sscanf(
              string: token,
              format: "%i %i %i %i",
              &NewElement.m_iR,
              &NewElement.m_iG,
              &NewElement.m_iB,
              &NewElement.m_iA);
          }
        }
        else
        {
          ParseToken();
          V_strncpy(pDest: NewElement.m_szAttachment, pSrc: token, maxLen: 128);
        }
      }
      else
      {
        if ( g_bUnget )
        {
          g_bUnget = false;
        }
        else
        {
          v6 = engine->ParseFile(this: engine, a2: currenttoken, a3: token, a4: 1204);
          ++tokencount;
          currenttoken = v6;
        }
        V_strncpy(pDest: NewElement.m_szMaterial, pSrc: token, maxLen: 128);
        CBaseEntity::PrecacheModel(
          a1: (bool (__cdecl *)(const char *))this,
          name: NewElement.m_szMaterial,
          bPreload: true);
      }
    }
    else
    {
      if ( g_bUnget )
      {
        g_bUnget = false;
      }
      else
      {
        v5 = engine->ParseFile(this: engine, a2: currenttoken, a3: token, a4: 1204);
        ++tokencount;
        currenttoken = v5;
      }
      if ( _V_stricmp(s1: token, s2: "trail") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "sprite") == 0 )
          NewElement.m_iType = 2;
      }
      else
      {
        NewElement.m_iType = 1;
      }
    }
  }
LABEL_42:
  CUtlVector<CEffectScriptElement,CUtlMemory<CEffectScriptElement,int>>::InsertBefore(
    this: &this->m_ScriptElements,
    elem: this->m_ScriptElements.m_Size,
    src: &NewElement);
}

//------------------------------------------------------------------------------
// Address: 0x10112CD0
// Name: public: void CEnvEffectsScript::TrailEffectEvent(class CEffectScriptElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEffectsScript::TrailEffectEvent(CEnvEffectsScript *this, CEffectScriptElement *pEffect)
{
  unsigned int m_Index; // eax
  CSpriteTrail *v4; // eax
  unsigned int v5; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v7; // eax
  CSprite *v8; // ecx
  unsigned int v9; // eax
  CSpriteTrail *v10; // ecx
  float m_flTextureRes; // xmm0_4
  unsigned int v12; // eax
  CSpriteTrail *v13; // ecx
  CSpriteTrail *v14; // ecx
  unsigned int v15; // eax
  CSpriteTrail *v16; // ecx
  unsigned int v17; // eax
  CSprite *v18; // ecx
  unsigned int v19; // eax
  CSprite *v20; // edi
  int v21; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  if ( !pEffect->m_bActive )
  {
    m_Index = pEffect->m_pTrail.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v4 = CSpriteTrail::SpriteTrailCreate(
             pSpriteName: pEffect->m_szMaterial,
             origin: &this->m_vecAbsOrigin,
             animate: true);
      if ( v4 != nullptr )
        pEffect->m_pTrail.m_Index = v4->GetRefEHandle(this: v4)->m_Index;
      else
        pEffect->m_pTrail.m_Index = -1;
      v5 = pEffect->m_pTrail.m_Index;
      if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      CBaseEntity::FollowEntity(this: m_pEntity, pBaseEntity: this, bBoneMerge: true);
      v7 = pEffect->m_pTrail.m_Index;
      if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
        v8 = nullptr;
      else
        v8 = (CSprite *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      CSprite::SetTransparency(
        this: v8,
        rendermode: pEffect->m_iRenderType,
        r: pEffect->m_iR,
        g: pEffect->m_iG,
        b: pEffect->m_iB,
        a: pEffect->m_iA,
        fx: 0);
      v9 = pEffect->m_pTrail.m_Index;
      if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
        v10 = nullptr;
      else
        v10 = (CSpriteTrail *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
      CSpriteTrail::SetStartWidth(this: v10, flStartWidth: pEffect->m_flScale);
      m_flTextureRes = pEffect->m_flTextureRes;
      v12 = pEffect->m_pTrail.m_Index;
      if ( m_flTextureRes >= 0.0 )
      {
        if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
          v14 = nullptr;
        else
          v14 = (CSpriteTrail *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
        CSpriteTrail::SetTextureResolution(this: v14, flTexelsPerInch: m_flTextureRes);
      }
      else
      {
        if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
          v13 = nullptr;
        else
          v13 = (CSpriteTrail *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
        CSpriteTrail::SetTextureResolution(this: v13, flTexelsPerInch: 1.0 / (float)(pEffect->m_flScale * 16.0));
      }
      v15 = pEffect->m_pTrail.m_Index;
      if ( v15 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
        v16 = nullptr;
      else
        v16 = (CSpriteTrail *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
      CSpriteTrail::SetLifeTime(this: v16, time: pEffect->m_flFadeTime);
      v17 = pEffect->m_pTrail.m_Index;
      if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
        v18 = nullptr;
      else
        v18 = (CSprite *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
      CSprite::TurnOn(this: v18);
      v19 = pEffect->m_pTrail.m_Index;
      if ( v19 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != HIWORD(v19) )
        v20 = nullptr;
      else
        v20 = (CSprite *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity;
      v21 = CBaseAnimating::LookupAttachment(this, szName: pEffect->m_szAttachment);
      CSprite::SetAttachment(this: v20, pEntity: this, attachment: v21);
      pEffect->m_bActive = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112FA0
// Name: public: void CEnvEffectsScript::SpriteEffectEvent(class CEffectScriptElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEffectsScript::SpriteEffectEvent(CEnvEffectsScript *this, CEffectScriptElement *pEffect)
{
  unsigned int m_Index; // eax
  CSprite *v4; // eax
  unsigned int v5; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v7; // eax
  CSprite *v8; // ecx
  unsigned int v9; // eax
  CSprite *v10; // ecx
  unsigned int v11; // eax
  CSprite *v12; // ecx
  unsigned int v13; // eax
  CSprite *v14; // edi
  int v15; // eax
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( !pEffect->m_bActive )
  {
    m_Index = pEffect->m_pSprite.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v4 = CSprite::SpriteCreate(pSpriteName: pEffect->m_szMaterial, origin: &this->m_vecAbsOrigin, animate: true);
      if ( v4 != nullptr )
        pEffect->m_pSprite.m_Index = v4->GetRefEHandle(this: v4)->m_Index;
      else
        pEffect->m_pSprite.m_Index = -1;
      v5 = pEffect->m_pSprite.m_Index;
      if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      CBaseEntity::FollowEntity(this: m_pEntity, pBaseEntity: this, bBoneMerge: true);
      v7 = pEffect->m_pSprite.m_Index;
      if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
        v8 = nullptr;
      else
        v8 = (CSprite *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      CSprite::SetTransparency(
        this: v8,
        rendermode: pEffect->m_iRenderType,
        r: pEffect->m_iR,
        g: pEffect->m_iG,
        b: pEffect->m_iB,
        a: pEffect->m_iA,
        fx: 0);
      v9 = pEffect->m_pSprite.m_Index;
      if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
        v10 = nullptr;
      else
        v10 = (CSprite *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
      CSprite::SetScale(this: v10, scale: pEffect->m_flScale, time: 0.0);
      v11 = pEffect->m_pSprite.m_Index;
      if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
        v12 = nullptr;
      else
        v12 = (CSprite *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
      CSprite::TurnOn(this: v12);
      v13 = pEffect->m_pSprite.m_Index;
      if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
        v14 = nullptr;
      else
        v14 = (CSprite *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
      v15 = CBaseAnimating::LookupAttachment(this, szName: pEffect->m_szAttachment);
      CSprite::SetAttachment(this: v14, pEntity: this, attachment: v15);
      pEffect->m_bActive = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101131A0
// Name: public: virtual void CEnvEffectsScript::HandleAnimEvent(struct animevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEffectsScript::HandleAnimEvent(CEnvEffectsScript *this, animevent_t *pEvent)
{
  int event_lowword; // ecx
  CEffectScriptElement *ScriptElementByName; // eax
  int m_iType; // ecx
  CEffectScriptElement *v6; // eax
  CEffectScriptElement *v7; // ebx
  int v8; // eax
  CBaseEntity *v9; // eax
  CBaseEntity *v10; // eax
  CBaseEntity *v11; // esi
  CBaseEntity_vtbl *v12; // eax
  CBaseEdict *v13; // ecx
  CBaseEntity *v14; // eax
  CBaseEntity *v15; // esi
  CBaseEdict *v16; // ecx
  CBaseEntity *v17; // eax
  CSprite *v18; // eax
  CBaseEntity *v19; // eax
  CBaseEntity *v20; // eax
  CBaseEntity *v21; // esi
  CBaseEntity_vtbl *v22; // eax
  CBaseEdict *v23; // ecx
  CBaseEntity *v24; // eax
  CBaseEntity *v25; // esi
  CBaseEdict *v26; // ecx
  CBaseEntity *v27; // eax
  CSprite *v28; // eax
  float duration; // [esp+0h] [ebp-1Ch]
  float durationa; // [esp+0h] [ebp-1Ch]
  Vector vOrigin; // [esp+10h] [ebp-Ch] BYREF

  if ( (pEvent->type & 0x400) != 0 )
    event_lowword = pEvent->_event_lowword;
  else
    event_lowword = *(_DWORD *)&pEvent->_event_highword;
  if ( event_lowword == 18 )
  {
    ScriptElementByName = CEnvEffectsScript::GetScriptElementByName(this, pName: pEvent->options);
    if ( ScriptElementByName != nullptr )
    {
      m_iType = ScriptElementByName->m_iType;
      if ( m_iType == 1 )
      {
        CEnvEffectsScript::TrailEffectEvent(this, pEffect: ScriptElementByName);
      }
      else if ( m_iType == 2 )
      {
        CEnvEffectsScript::SpriteEffectEvent(this, pEffect: ScriptElementByName);
      }
    }
  }
  else if ( event_lowword == 19 )
  {
    v6 = CEnvEffectsScript::GetScriptElementByName(this, pName: pEvent->options);
    v7 = v6;
    if ( v6 != nullptr && v6->m_bActive )
    {
      v8 = v6->m_iType;
      v7->m_bActive = false;
      if ( v8 == 1 )
      {
        if ( v7->m_bStopFollowOnKill )
        {
          v9 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v7->m_pTrail);
          CBaseAnimating::GetAttachment(
            this,
            iAttachment: (int)v9[1].m_pfnMoveDone,
            absOrigin: &vOrigin,
            forward: nullptr,
            right: nullptr,
            up: nullptr);
          v10 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v7->m_pTrail);
          CBaseEntity::StopFollowingEntity(this: v10);
          v11 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v7->m_pTrail);
          v12 = v11[1].__vftable;
          if ( v12 != (CBaseEntity_vtbl *)-1
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber == (unsigned int)v12 >> 16
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity != nullptr )
          {
            if ( v11->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v11->m_Network + 76) |= 1u;
            }
            else
            {
              v13 = &v11->m_Network.m_pPev->CBaseEdict;
              if ( v13 != nullptr )
                CBaseEdict::StateChanged(this: v13, offset: 0x354u);
            }
            v11[1].__vftable = (CBaseEntity_vtbl *)-1;
          }
          v14 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v7->m_pTrail);
          v15 = v14;
          if ( v14[1].m_pfnMoveDone != nullptr )
          {
            if ( v14->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v14->m_Network + 76) |= 1u;
            }
            else
            {
              v16 = &v14->m_Network.m_pPev->CBaseEdict;
              if ( v16 != nullptr )
                CBaseEdict::StateChanged(this: v16, offset: 0x358u);
            }
            v15[1].m_pfnMoveDone = nullptr;
          }
          v17 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v7->m_pTrail);
          CBaseEntity::SetAbsOrigin(this: v17, absOrigin: &vOrigin);
        }
        duration = v7->m_flFadeTime;
        v18 = (CSprite *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v7->m_pTrail);
        CSprite::FadeAndDie(this: v18, duration);
        v7->m_pTrail.m_Index = -1;
      }
      else if ( v8 == 2 )
      {
        if ( v7->m_bStopFollowOnKill )
        {
          v19 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v7->m_pSprite);
          CBaseAnimating::GetAttachment(
            this,
            iAttachment: (int)v19[1].m_pfnMoveDone,
            absOrigin: &vOrigin,
            forward: nullptr,
            right: nullptr,
            up: nullptr);
          v20 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v7->m_pSprite);
          CBaseEntity::StopFollowingEntity(this: v20);
          v21 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v7->m_pSprite);
          v22 = v21[1].__vftable;
          if ( v22 != (CBaseEntity_vtbl *)-1
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_SerialNumber == (unsigned int)v22 >> 16
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_pEntity != nullptr )
          {
            if ( v21->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v21->m_Network + 76) |= 1u;
            }
            else
            {
              v23 = &v21->m_Network.m_pPev->CBaseEdict;
              if ( v23 != nullptr )
                CBaseEdict::StateChanged(this: v23, offset: 0x354u);
            }
            v21[1].__vftable = (CBaseEntity_vtbl *)-1;
          }
          v24 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v7->m_pSprite);
          v25 = v24;
          if ( v24[1].m_pfnMoveDone != nullptr )
          {
            if ( v24->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v24->m_Network + 76) |= 1u;
            }
            else
            {
              v26 = &v24->m_Network.m_pPev->CBaseEdict;
              if ( v26 != nullptr )
                CBaseEdict::StateChanged(this: v26, offset: 0x358u);
            }
            v25[1].m_pfnMoveDone = nullptr;
          }
          v27 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v7->m_pSprite);
          CBaseEntity::SetAbsOrigin(this: v27, absOrigin: &vOrigin);
        }
        durationa = v7->m_flFadeTime;
        v28 = (CSprite *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v7->m_pSprite);
        CSprite::FadeAndDie(this: v28, duration: durationa);
        v7->m_pSprite.m_Index = -1;
      }
    }
  }
  else
  {
    CBaseAnimating::HandleAnimEvent(this, pEvent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101134D0
// Name: public: void CEnvEffectsScript::LoadFromBuffer(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEffectsScript::LoadFromBuffer(CEnvEffectsScript *this, const char *scriptfile, const char *buffer)
{
  const char *v4; // eax

  while ( 1 )
  {
    if ( g_bUnget )
    {
      g_bUnget = false;
    }
    else
    {
      v4 = engine->ParseFile(this: engine, a2: currenttoken, a3: token, a4: 1204);
      ++tokencount;
      currenttoken = v4;
    }
    if ( token[0] == 0 )
      break;
    if ( _V_stricmp(s1: token, s2: "effect") != 0 )
    {
      _Warning(a1: "CEnvEffectsScript: Unknown entry type '%s'\n", token);
      return;
    }
    CEnvEffectsScript::ParseNewEffect(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113550
// Name: public: void CEnvEffectsScript::ParseScriptFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEffectsScript::ParseScriptFile(CEnvEffectsScript *this)
{
  const char *pszValue; // edi
  const char *v3; // eax
  unsigned __int8 *v4; // esi
  int length; // [esp+Ch] [ebp-4h] BYREF

  this->m_ScriptElements.m_Size = 0;
  pszValue = this->m_iszScriptName.pszValue;
  length = 0;
  if ( pszValue == nullptr )
    pszValue = locale;
  g_bUnget = false;
  currenttoken = nullptr;
  tokencount = 0;
  memset(dst: (int)token, value: nullptr, count: sizeof(token));
  memset(dst: (int)name, value: nullptr, count: sizeof(name));
  v3 = (const char *)UTIL_LoadFileForMe(filename: pszValue, pLength: &length);
  v4 = (unsigned __int8 *)v3;
  if ( length > 0 && v3 != nullptr )
  {
    currenttoken = v3;
    CEnvEffectsScript::LoadFromBuffer(this, scriptfile: pszValue, buffer: v3);
    UTIL_FreeFile(buffer: v4);
  }
  else
  {
    _DevMsg(a1: 1, a2: "CEnvEffectsScript:  failed to load %s\n", pszValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113600
// Name: public: virtual void CEnvEffectsScript::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvEffectsScript::Precache(CEnvEffectsScript *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  CBaseAnimating::Precache(this);
  v3 = *(const char **)((int (__thiscall *)(CEnvEffectsScript *, _BYTE *))this->GetModelName)(a1: this, a2: v4);
  if ( v3 == nullptr )
    v3 = locale;
  CBaseEntity::PrecacheModel(a1: a2, name: v3, bPreload: true);
  if ( this->m_iszScriptName.pszValue != nullptr )
    CEnvEffectsScript::ParseScriptFile(this);
  else
    _Warning(a1: "CEnvEffectsScript with no script!\n");
}

//------------------------------------------------------------------------------
// Address: 0x10402740
// Name: CEnvEffectsScript_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvEffectsScript_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvEffectsScript>();
  CEnvEffectsScript_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040CAF0
// Name: _dynamic_initializer_for__script_connect_debugger_on_mapspawn__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_connect_debugger_on_mapspawn__()
{
  ConVar::ConVar(
    this: &script_connect_debugger_on_mapspawn,
    pName: "script_connect_debugger_on_mapspawn",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__script_connect_debugger_on_mapspawn__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CB80
// Name: _dynamic_initializer_for__script_reload_code_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_reload_code_command__()
{
  ConCommand::ConCommand(
    this: &script_reload_code_command,
    pName: "script_reload_code",
    callback: (void (__cdecl *)())script_reload_code,
    pHelpString: "Execute a vscript file, replacing existing functions with the functions in the run script",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_reload_code_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CBB0
// Name: _dynamic_initializer_for__script_reload_entity_code_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_reload_entity_code_command__()
{
  ConCommand::ConCommand(
    this: &script_reload_entity_code_command,
    pName: "script_reload_entity_code",
    callback: (void (__cdecl *)())script_reload_entity_code,
    pHelpString: "Execute all of this entity's VScripts, replacing existing functions with the functions in the run scripts",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_reload_entity_code_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CBE0
// Name: _dynamic_initializer_for__script_reload_think_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_reload_think_command__()
{
  ConCommand::ConCommand(
    this: &script_reload_think_command,
    pName: "script_reload_think",
    callback: (void (__cdecl *)())script_reload_think,
    pHelpString: "Execute an activation script, replacing existing functions with the functions in the run script",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_reload_think_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CC70
// Name: _dynamic_initializer_for__script_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_command__()
{
  ConCommand::ConCommand(
    this: &script_command,
    pName: "script",
    callback: (void (__cdecl *)())script,
    pHelpString: "Run the text as a script",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CCA0
// Name: _dynamic_initializer_for__script_execute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_execute_command__()
{
  ConCommand::ConCommand(
    this: &script_execute_command,
    pName: "script_execute",
    callback: (void (__cdecl *)())script_execute,
    pHelpString: "Run a vscript file",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_execute_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CCD0
// Name: _dynamic_initializer_for__script_debug_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_debug_command__()
{
  ConCommand::ConCommand(
    this: &script_debug_command,
    pName: "script_debug",
    callback: (void (__cdecl *)())script_debug,
    pHelpString: "Connect the vscript VM to the script debugger",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_debug_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CD00
// Name: _dynamic_initializer_for__script_help_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_help_command__()
{
  ConCommand::ConCommand(
    this: &script_help_command,
    pName: "script_help",
    callback: (void (__cdecl *)())script_help,
    pHelpString: "Output help for script functions, optionally with a search string",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_help_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CD30
// Name: _dynamic_initializer_for__script_dump_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_dump_all_command__()
{
  ConCommand::ConCommand(
    this: &script_dump_all_command,
    pName: "script_dump_all",
    callback: (void (__cdecl *)())script_dump_all,
    pHelpString: "Dump the state of the VM to the console",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_dump_all_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EFD0
// Name: _dynamic_atexit_destructor_for__script_connect_debugger_on_mapspawn__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_connect_debugger_on_mapspawn__()
{
  ConVar::~ConVar(this: &script_connect_debugger_on_mapspawn);
}

//------------------------------------------------------------------------------
// Address: 0x1041EFE0
// Name: _dynamic_atexit_destructor_for__script_reload_code_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_reload_code_command__()
{
  ConCommand::~ConCommand(this: &script_reload_code_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041EFF0
// Name: _dynamic_atexit_destructor_for__script_reload_entity_code_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_reload_entity_code_command__()
{
  ConCommand::~ConCommand(this: &script_reload_entity_code_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041F000
// Name: _dynamic_atexit_destructor_for__script_reload_think_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_reload_think_command__()
{
  ConCommand::~ConCommand(this: &script_reload_think_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041F160
// Name: _dynamic_atexit_destructor_for__script_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_command__()
{
  ConCommand::~ConCommand(this: &script_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041F170
// Name: _dynamic_atexit_destructor_for__script_execute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_execute_command__()
{
  ConCommand::~ConCommand(this: &script_execute_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041F180
// Name: _dynamic_atexit_destructor_for__script_debug_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_debug_command__()
{
  ConCommand::~ConCommand(this: &script_debug_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041F190
// Name: _dynamic_atexit_destructor_for__script_help_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_help_command__()
{
  ConCommand::~ConCommand(this: &script_help_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041F1A0
// Name: _dynamic_atexit_destructor_for__script_dump_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_dump_all_command__()
{
  ConCommand::~ConCommand(this: &script_dump_all_command);
}

//------------------------------------------------------------------------------
// Address: 0x10402750
// Name: _dynamic_initializer_for__env_effectscript__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_effectscript__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvEffectsScript> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_effectscript,
           a3: "env_effectscript");
}

//------------------------------------------------------------------------------
// Address: 0x1040CB20
// Name: _dynamic_initializer_for__g_CScriptEntityIterator_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall dynamic_initializer_for__g_CScriptEntityIterator_ScriptDesc__@<eax>(int a1@<edi>)
{
  InitCScriptEntityIteratorScriptDesc(a1);
  g_CScriptEntityIterator_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_CScriptEntityIterator_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_CScriptEntityIterator_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CB50
// Name: _dynamic_initializer_for__g_CScriptKeyValues_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall dynamic_initializer_for__g_CScriptKeyValues_ScriptDesc__@<eax>(int a1@<esi>)
{
  InitCScriptKeyValuesScriptDesc(a1);
  g_CScriptKeyValues_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_CScriptKeyValues_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_CScriptKeyValues_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CC10
// Name: _dynamic_initializer_for__g_VScriptGameSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VScriptGameSystem__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_VScriptGameSystem, name: nullptr);
  g_VScriptGameSystem.__vftable = (CVScriptGameSystem_vtbl *)&CVScriptGameSystem::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_VScriptGameSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CC40
// Name: _dynamic_initializer_for__g_VScriptSaveRestoreBlockHandler__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VScriptSaveRestoreBlockHandler__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VScriptSaveRestoreBlockHandler__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CC50
// Name: _dynamic_initializer_for__LOG_VScript__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_VScript__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "VScript",
             a2: 0,
             a3: 1,
             a4: 1,
             a5: UNSPECIFIED_LOGGING_COLOR_26);
  LOG_VScript = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041F010
// Name: _dynamic_atexit_destructor_for__g_VScriptGameSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VScriptGameSystem__()
{
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_VScriptGameSystem);
}
