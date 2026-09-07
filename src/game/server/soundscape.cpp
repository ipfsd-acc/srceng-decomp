// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/soundscape.cpp
// Functions: 44
// ============================================================

#include "game\server\soundscape.h"

//------------------------------------------------------------------------------
// Address: 0x1021F6C0
// Name: public: virtual struct datamap_t __near * CEnvSoundscapeProxy::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvSoundscapeProxy::GetDataDescMap(CEnvSoundscapeProxy *this)
{
  return &CEnvSoundscapeProxy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1021F6D0
// Name: public: virtual struct datamap_t __near * CEnvSoundscape::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvSoundscape::GetDataDescMap(CEnvSoundscape *this)
{
  return &CEnvSoundscape::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1021F6E0
// Name: public: virtual struct datamap_t __near * CEnvSoundscapeTriggerable::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvSoundscapeTriggerable::GetDataDescMap(CEnvSoundscapeTriggerable *this)
{
  return &CEnvSoundscapeTriggerable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1021F6F0
// Name: public: virtual struct datamap_t __near * CTriggerSoundscape::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTriggerSoundscape::GetDataDescMap(CTriggerSoundscape *this)
{
  return &CTriggerSoundscape::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1021F700
// Name: public: void CEnvSoundscape::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSoundscape::InputEnable(CEnvSoundscape *this, inputdata_t *inputdata)
{
  if ( this->m_bDisabled || !g_pGameRules->AllowSoundscapes(this: g_pGameRules) )
    this->m_bDisabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x1021F730
// Name: public: void CEnvSoundscape::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSoundscape::InputDisable(CEnvSoundscape *this, inputdata_t *inputdata)
{
  if ( !this->m_bDisabled && g_pGameRules->AllowSoundscapes(this: g_pGameRules) )
    this->m_bDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x1021F760
// Name: public: void CEnvSoundscape::InputToggleEnabled(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSoundscape::InputToggleEnabled(CEnvSoundscape *this, inputdata_t *inputdata)
{
  this->m_bDisabled = !this->m_bDisabled && g_pGameRules->AllowSoundscapes(this: g_pGameRules);
}

//------------------------------------------------------------------------------
// Address: 0x1021F7A0
// Name: public: virtual bool CEnvSoundscape::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEnvSoundscape::KeyValue(CEnvSoundscape *this, char *szKeyName, const char *szValue)
{
  if ( szKeyName != "soundscape" && _V_stricmp(s1: szKeyName, s2: "soundscape") != 0 )
    return CBaseEntity::KeyValue(this, szKeyName, szValue);
  this->m_soundscapeName.pszValue = *(const char **)AllocPooledString(pszValue: (char *)&szValue, pszValuea: szValue).pszValue;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1021F800
// Name: public: virtual void CEnvSoundscape::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSoundscape::Precache(CEnvSoundscape *this)
{
  const char *pszValue; // eax
  int SoundscapeIndex; // eax
  const char *v4; // esi

  if ( this->m_soundscapeName.pszValue != nullptr )
  {
    pszValue = this->m_soundscapeName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    SoundscapeIndex = CSoundscapeSystem::GetSoundscapeIndex(this: &g_SoundscapeSystem, pName: pszValue);
    this->m_soundscapeIndex = SoundscapeIndex;
    if ( !CSoundscapeSystem::IsValidIndex(this: &g_SoundscapeSystem, index: SoundscapeIndex) )
    {
      v4 = this->m_soundscapeName.pszValue;
      if ( v4 == nullptr )
        v4 = locale;
      DevWarning(a1: "Can't find soundscape: %s\n", v4);
    }
  }
  else
  {
    DevMsg(a1: "Found soundscape entity with no soundscape name.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021F870
// Name: public: virtual void CEnvSoundscape::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvSoundscape::DrawDebugGeometryOverlays(CEnvSoundscape *this@<ecx>, int a2@<ebp>)
{
  CBasePlayer *ListenServerHost; // eax
  int v4; // esi
  const Vector *v5; // eax

  if ( (this->m_debugOverlays & 0x2C) != 0 )
  {
    ListenServerHost = UTIL_GetListenServerHost();
    if ( ListenServerHost != nullptr && ListenServerHost->m_Local.m_audio.entIndex.m_Value != this->m_soundscapeEntityId )
    {
      v4 = (int)ListenServerHost->GetSoundscapeListener(this: ListenServerHost);
      if ( v4 != 0 )
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2);
        v5 = (const Vector *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 588))(a1: v4);
        NDebugOverlay::Line(
          origin: &this->m_vecAbsOrigin,
          target: v5,
          r: 255,
          g: 0,
          b: 255,
          noDepthTest: 0,
          duration: 0.0);
      }
    }
  }
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x1021F910
// Name: public: CEnvSoundscape::CEnvSoundscape(void)
// Source: json
//------------------------------------------------------------------------------
CEnvSoundscape *__thiscall CEnvSoundscape::CEnvSoundscape(CEnvSoundscape *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CEnvSoundscape_vtbl *)&CEnvSoundscape::`vftable';
  this->m_OnPlay.m_Value.iVal = 0;
  this->m_OnPlay.m_Value.eVal.m_Index = -1;
  this->m_OnPlay.m_Value.fieldType = FIELD_VOID;
  this->m_hProxySoundscape.m_Index = -1;
  this->m_soundscapeName.pszValue = nullptr;
  this->m_bDisabled = false;
  this->m_soundscapeIndex = -1;
  this->m_soundscapeEntityId = -1;
  CSoundscapeSystem::AddSoundscapeEntity(this: &g_SoundscapeSystem, pSoundscape: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1021F970
// Name: public: bool CEnvSoundscape::InRangeOfPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
bool __userpurge CEnvSoundscape::InRangeOfPlayer@<al>(
        CEnvSoundscape *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CBasePlayer *pTarget)
{
  __int128 v6; // xmm0
  float m_flRadius; // xmm0_4
  bool result; // al
  _DWORD v10[3]; // [esp-Ch] [ebp-94h] BYREF
  _BYTE tr[92]; // [esp+0h] [ebp-88h] OVERLAPPED
  int v12; // [esp+5Ch] [ebp-2Ch]
  int v13; // [esp+60h] [ebp-28h]
  Vector v14; // [esp+64h] [ebp-24h] BYREF
  Vector vecSpot1; // [esp+70h] [ebp-18h] BYREF
  Vector vecSpot2; // [esp+7Ch] [ebp-Ch] BYREF
  float retaddr; // [esp+88h] [ebp+0h]

  vecSpot2.x = a2;
  vecSpot2.y = retaddr;
  ((void (__thiscall *)(CEnvSoundscape *, Vector *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int))this->EarPosition)(
    a1: this,
    a2: &v14,
    a3,
    a4,
    a5: v10[0],
    a6: v10[1],
    a7: v10[2],
    a8: *(_DWORD *)tr,
    a9: *(_DWORD *)&tr[4],
    a10: *(_DWORD *)&tr[8],
    a11: *(_DWORD *)&tr[12],
    a12: *(_DWORD *)&tr[16],
    a13: *(_DWORD *)&tr[20],
    a14: *(_DWORD *)&tr[24],
    a15: *(_DWORD *)&tr[28],
    a16: *(_DWORD *)&tr[32],
    a17: *(_DWORD *)&tr[36],
    a18: *(_DWORD *)&tr[40],
    a19: *(_DWORD *)&tr[44],
    a20: *(_DWORD *)&tr[48],
    a21: *(_DWORD *)&tr[52],
    a22: *(_DWORD *)&tr[56],
    a23: *(_DWORD *)&tr[60],
    a24: *(_DWORD *)&tr[64],
    a25: *(_DWORD *)&tr[68],
    a26: *(_DWORD *)&tr[72],
    a27: *(_DWORD *)&tr[76],
    a28: *(_DWORD *)&tr[80],
    a29: *(_DWORD *)&tr[84],
    a30: *(_DWORD *)&tr[88],
    a31: v12,
    a32: v13);
  pTarget->EarPosition(this: pTarget, result: &vecSpot1);
  v6 = 0;
  *(float *)&v6 = fsqrt(
                    (float)((float)((float)(vecSpot1.y - v14.y) * (float)(vecSpot1.y - v14.y))
                          + (float)((float)(vecSpot1.z - v14.z) * (float)(vecSpot1.z - v14.z)))
                  + (float)((float)(vecSpot1.x - v14.x) * (float)(vecSpot1.x - v14.x)));
  *(_OWORD *)&tr[76] = v6;
  m_flRadius = this->m_flRadius;
  result = false;
  if ( m_flRadius > *(float *)&tr[76] || m_flRadius == -1.0 )
  {
    UTIL_TraceLine(
      a1: (const IHandleEntity *)&vecSpot2,
      a2: (int)this,
      vecAbsStart: &v14,
      vecAbsEnd: &vecSpot1,
      mask: 0x403Bu,
      ignore: pTarget,
      collisionGroup: 0,
      ptr: (CGameTrace *)v10);
    if ( *(float *)&tr[32] == 1.0 && tr[43] == 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021FA60
// Name: public: CEnvSoundscapeTriggerable::CEnvSoundscapeTriggerable(void)
// Source: json
//------------------------------------------------------------------------------
CEnvSoundscapeTriggerable *__thiscall CEnvSoundscapeTriggerable::CEnvSoundscapeTriggerable(
        CEnvSoundscapeTriggerable *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CEnvSoundscapeTriggerable_vtbl *)&CEnvSoundscape::`vftable';
  this->m_OnPlay.m_Value.iVal = 0;
  this->m_OnPlay.m_Value.eVal.m_Index = -1;
  this->m_OnPlay.m_Value.fieldType = FIELD_VOID;
  this->m_hProxySoundscape.m_Index = -1;
  this->m_soundscapeName.pszValue = nullptr;
  this->m_bDisabled = false;
  this->m_soundscapeIndex = -1;
  this->m_soundscapeEntityId = -1;
  CSoundscapeSystem::AddSoundscapeEntity(this: &g_SoundscapeSystem, pSoundscape: this);
  this->__vftable = (CEnvSoundscapeTriggerable_vtbl *)&CEnvSoundscapeTriggerable::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1021FB00
// Name: public: CEnvSoundscapeProxy::CEnvSoundscapeProxy(void)
// Source: json
//------------------------------------------------------------------------------
CEnvSoundscapeProxy *__thiscall CEnvSoundscapeProxy::CEnvSoundscapeProxy(CEnvSoundscapeProxy *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CEnvSoundscapeProxy_vtbl *)&CEnvSoundscape::`vftable';
  this->m_OnPlay.m_Value.iVal = 0;
  this->m_OnPlay.m_Value.eVal.m_Index = -1;
  this->m_OnPlay.m_Value.fieldType = FIELD_VOID;
  this->m_hProxySoundscape.m_Index = -1;
  this->m_soundscapeName.pszValue = nullptr;
  this->m_soundscapeIndex = -1;
  this->m_soundscapeEntityId = -1;
  this->m_bDisabled = false;
  CSoundscapeSystem::AddSoundscapeEntity(this: &g_SoundscapeSystem, pSoundscape: this);
  this->m_MainSoundscapeName.pszValue = nullptr;
  this->__vftable = (CEnvSoundscapeProxy_vtbl *)&CEnvSoundscapeProxy::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1021FB70
// Name: public: virtual void CEnvSoundscapeProxy::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSoundscapeProxy::Activate(CEnvSoundscapeProxy *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  void *v4; // eax
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *m_pEntity; // eax
  unsigned int v13; // edi
  string_t *v14; // ecx
  unsigned int v15; // eax
  IHandleEntity *v16; // eax
  unsigned int v17; // eax
  IHandleEntity *v18; // eax
  unsigned int v19; // eax
  IHandleEntity *v20; // eax
  unsigned int v21; // eax
  IHandleEntity *v22; // eax
  const char *v23; // eax

  pszValue = this->m_MainSoundscapeName.pszValue;
  if ( pszValue != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
    {
      v4 = __RTDynamicCast(
             inptr: EntityByName,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CEnvSoundscape `RTTI Type Descriptor',
             isReference: 0);
      if ( v4 != nullptr )
        this->m_hProxySoundscape.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
      else
        this->m_hProxySoundscape.m_Index = -1;
    }
  }
  m_Index = this->m_hProxySoundscape.m_Index;
  if ( m_Index != -1
    && (v6 = (unsigned __int16)m_Index,
        v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v8 = HIWORD(m_Index),
        v7->m_SerialNumber == v8)
    && v7->m_pEntity != nullptr )
  {
    v9 = v6;
    v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
    v11 = &g_pEntityList->m_EntPtrArray[v9];
    if ( v10 )
      m_pEntity = v11->m_pEntity;
    else
      m_pEntity = nullptr;
    this->m_soundscapeIndex = (int)m_pEntity[221].__vftable;
    v13 = 224;
    v14 = &this->m_positionNames[1];
    do
    {
      v15 = this->m_hProxySoundscape.m_Index;
      if ( v15 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
        v16 = nullptr;
      else
        v16 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
      v14[-1].pszValue = *(const char **)((char *)&v16->__vftable + (_DWORD)((char *)v14 - 4 - (_DWORD)this));
      v17 = this->m_hProxySoundscape.m_Index;
      if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
        v18 = nullptr;
      else
        v18 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
      v14->pszValue = (const char *)v18[v13].__vftable;
      v19 = this->m_hProxySoundscape.m_Index;
      if ( v19 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != HIWORD(v19) )
        v20 = nullptr;
      else
        v20 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity;
      v14[1].pszValue = *(const char **)((char *)&v20->__vftable + (_DWORD)v14 + 4 - (_DWORD)this);
      v21 = this->m_hProxySoundscape.m_Index;
      if ( v21 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
        v22 = nullptr;
      else
        v22 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
      v14[2].pszValue = *(const char **)((char *)&v22->__vftable + (_DWORD)v14 + 8 - (_DWORD)this);
      v13 += 4;
      v14 += 4;
    }
    while ( v13 < 232 );
    CBaseEntity::Activate(this);
  }
  else
  {
    v23 = this->m_MainSoundscapeName.pszValue;
    if ( v23 == nullptr )
      v23 = locale;
    _Warning(a1: "env_soundscape_proxy can't find target soundscape: '%s'\n", v23);
    CBaseEntity::Activate(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021FD90
// Name: public: virtual void CTriggerSoundscape::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerSoundscape::Activate(CTriggerSoundscape *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  void *v4; // eax

  pszValue = this->m_SoundscapeName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  v4 = __RTDynamicCast(
         inptr: EntityByName,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CEnvSoundscapeTriggerable `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
    this->m_hSoundscape.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
  else
    this->m_hSoundscape.m_Index = -1;
  CBaseTrigger::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x1021FE80
// Name: public: void CEnvSoundscape::WriteAudioParamsTo(struct audioparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSoundscape::WriteAudioParamsTo(CEnvSoundscape *this, audioparams_t *audio)
{
  CEnvSoundscape *v2; // esi
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // ebx
  int v5; // edi
  float *v6; // edi
  unsigned int v7; // ecx
  _DWORD *p_x; // eax
  int v10; // [esp+28h] [ebp-Ch]
  unsigned int v11; // [esp+2Ch] [ebp-8h]
  const char **p_pszValue; // [esp+30h] [ebp-4h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  v2 = this;
  if ( !CSoundscapeSystem::IsValidIndex(this: &g_SoundscapeSystem, index: this->m_soundscapeIndex) )
  {
    pszValue = v2->m_soundscapeName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(
      a1: "Setting invalid soundscape, %s, as the active soundscape. There is probably no script entry matching this name. BUG THIS!\n",
      pszValue);
  }
  if ( audio->entIndex.m_Value != v2->m_soundscapeEntityId )
  {
    audio->NetworkStateChanged(this: audio, a2: &audio->entIndex);
    audio->entIndex.m_Value = v2->m_soundscapeEntityId;
  }
  if ( audio->soundscapeIndex.m_Value != v2->m_soundscapeIndex )
  {
    audio->NetworkStateChanged(this: audio, a2: &audio->soundscapeIndex);
    audio->soundscapeIndex.m_Value = v2->m_soundscapeIndex;
  }
  if ( audio->localBits.m_Value != 0 )
  {
    audio->NetworkStateChanged(this: audio, a2: &audio->localBits);
    audio->localBits.m_Value = 0;
  }
  v10 = 1;
  v11 = 0;
  p_pszValue = &v2->m_positionNames[0].pszValue;
  do
  {
    if ( *p_pszValue != nullptr )
    {
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: nullptr,
                       szName: *p_pszValue,
                       pSearchingEntity: v2,
                       pActivator: v2,
                       pCaller: nullptr,
                       pFilter: nullptr);
      if ( EntityByName != nullptr )
      {
        v5 = v10 | audio->localBits.m_Value;
        if ( audio->localBits.m_Value != v5 )
        {
          audio->NetworkStateChanged(this: audio, a2: &audio->localBits);
          audio->localBits.m_Value = v5;
        }
        if ( (EntityByName->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
        v6 = (float *)((char *)&audio->localSound + v11 * 12);
        v7 = 12;
        p_x = (_DWORD *)&EntityByName->m_vecAbsOrigin.x;
        while ( *(_DWORD *)((char *)p_x + (char *)&audio->localSound + v11 * 12 - (char *)&EntityByName->m_vecAbsOrigin) == *p_x )
        {
          v7 -= 4;
          ++p_x;
          if ( v7 < 4 )
            goto LABEL_23;
        }
        audio->NetworkStateChanged(this: audio, a2: v6);
        *v6 = EntityByName->m_vecAbsOrigin.x;
        audio->localSound.m_Value[v11].y = EntityByName->m_vecAbsOrigin.y;
        audio->localSound.m_Value[v11].z = EntityByName->m_vecAbsOrigin.z;
LABEL_23:
        v2 = this;
      }
    }
    ++p_pszValue;
    ++v11;
    v10 = __ROL4__(v10, 1);
  }
  while ( v11 < 8 );
  COutputEvent::FireOutput(this: &v2->m_OnPlay, pActivator: v2, pCaller: v2, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10220020
// Name: public: void CEnvSoundscape::UpdateForPlayer(struct ss_update_t __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CEnvSoundscape::UpdateForPlayer(
        CEnvSoundscape *this@<ecx>,
        IHandleEntity_vtbl *a2@<ebp>,
        ss_update_t *update)
{
  __int128 v4; // xmm0
  float m_flRadius; // xmm0_4
  CBasePlayer *pPlayer; // edx
  float v7; // xmm0_4
  CBasePlayer *v8; // eax
  float v9; // xmm0_4
  unsigned int v10; // eax
  CBasePlayer *v11; // eax
  const Vector *v12; // eax
  const Vector *AbsOrigin; // eax
  long double curtime; // st7
  const Vector *v15; // esi
  long double v16; // st7
  bool v17; // zf
  const char *pszValue; // esi
  const Vector *size; // [esp+4h] [ebp-C4h]
  const Vector *sizea; // [esp+4h] [ebp-C4h]
  int duration; // [esp+8h] [ebp-C0h]
  int v22; // [esp+Ch] [ebp-BCh]
  int v23; // [esp+Ch] [ebp-BCh]
  int v24; // [esp+10h] [ebp-B8h]
  _BYTE v25[12]; // [esp+24h] [ebp-A4h] BYREF
  CGameTrace tr; // [esp+30h] [ebp-98h] BYREF
  int v27; // [esp+84h] [ebp-44h]
  Vector v28; // [esp+88h] [ebp-40h] BYREF
  _BYTE target[24]; // [esp+94h] [ebp-34h] OVERLAPPED BYREF
  const Vector *p_m_vecAbsOrigin; // [esp+B0h] [ebp-18h]
  int v31; // [esp+B4h] [ebp-14h]
  int p_m_audio; // [esp+B8h] [ebp-10h]
  IHandleEntity v33[2]; // [esp+BCh] [ebp-Ch] BYREF
  IHandleEntity_vtbl *retaddr; // [esp+C8h] [ebp+0h]

  v33[0].__vftable = a2;
  v33[1].__vftable = retaddr;
  if ( this->m_bDisabled || !g_pGameRules->AllowSoundscapes(this: g_pGameRules) )
  {
    if ( update->pCurrentSoundscape == this )
    {
      update->pCurrentSoundscape = nullptr;
      update->currentDistance = 0.0;
      update->bInRange = false;
    }
    return;
  }
  this->EarPosition(this, result: &v28);
  v4 = 0;
  *(float *)&v4 = fsqrt(
                    (float)((float)((float)(update->playerPosition.y - v28.y) * (float)(update->playerPosition.y - v28.y))
                          + (float)((float)(update->playerPosition.z - v28.z) * (float)(update->playerPosition.z - v28.z)))
                  + (float)((float)(update->playerPosition.x - v28.x) * (float)(update->playerPosition.x - v28.x)));
  *(_OWORD *)&target[8] = v4;
  if ( update->pCurrentSoundscape == this )
  {
    update->currentDistance = *(float *)&target[8];
    update->bInRange = false;
    m_flRadius = this->m_flRadius;
    if ( m_flRadius > *(float *)&target[8] || m_flRadius == -1.0 )
    {
      pPlayer = update->pPlayer;
      ++update->traceCount;
      UTIL_TraceLine(
        a1: v33,
        a2: (int)update,
        vecAbsStart: &v28,
        vecAbsEnd: &update->playerPosition,
        mask: 0x403Bu,
        ignore: pPlayer,
        collisionGroup: 0,
        ptr: (CGameTrace *)v25);
      if ( tr.plane.normal.z == 1.0 && tr.plane.pad[1] == 0 )
        goto LABEL_18;
    }
  }
  else if ( !update->bInRange || update->currentDistance > *(float *)&target[8] )
  {
    v7 = this->m_flRadius;
    if ( v7 > *(float *)&target[8] || v7 == -1.0 )
    {
      v8 = update->pPlayer;
      ++update->traceCount;
      UTIL_TraceLine(
        a1: v33,
        a2: (int)update,
        vecAbsStart: &v28,
        vecAbsEnd: &update->playerPosition,
        mask: 0x403Bu,
        ignore: v8,
        collisionGroup: 0,
        ptr: (CGameTrace *)v25);
      if ( tr.plane.normal.z == 1.0 && tr.plane.pad[1] == 0 )
      {
        CEnvSoundscape::WriteAudioParamsTo(this, audio: &update->pPlayer->m_Local.m_audio);
        v9 = *(float *)&target[8];
        update->pCurrentSoundscape = this;
        update->currentDistance = v9;
LABEL_18:
        update->bInRange = true;
      }
    }
  }
  if ( soundscape_debug.m_pParent != nullptr && soundscape_debug.m_pParent->m_Value.m_nValue != 0 )
  {
    v10 = (unsigned int)this->m_iEFlags >> 11;
    tr.m_pEnt = (CBaseEntity *)1092616192;
    tr.hitbox = 1092616192;
    v27 = 1092616192;
    *(_DWORD *)&target[12] = -1054867456;
    *(_DWORD *)&target[16] = -1054867456;
    *(_DWORD *)&target[20] = -1054867456;
    if ( (v10 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)v33);
    p_m_vecAbsOrigin = &this->m_vecAbsOrigin;
    NDebugOverlay::Box(
      origin: &this->m_vecAbsOrigin,
      mins: (const Vector *)&target[12],
      maxs: (const Vector *)&tr.m_pEnt,
      r: 255,
      g: 0,
      b: 255,
      a: 64,
      flDuration: 0.01023);
    v11 = update->pPlayer;
    if ( update->pPlayer != nullptr )
    {
      p_m_audio = (int)&v11->m_Local.m_audio;
      if ( v11->m_Local.m_audio.entIndex.m_Value == this->m_soundscapeEntityId )
      {
        if ( CEnvSoundscape::InRangeOfPlayer(this, a2: COERCE_FLOAT(v33), a3: (int)this, a4: (int)update, pTarget: v11) )
        {
          v23 = 255;
          duration = 0;
        }
        else
        {
          v23 = 170;
          duration = 255;
        }
        sizea = (const Vector *)((int (__fastcall *)(CBasePlayer *))update->pPlayer->WorldSpaceCenter)(a1: update->pPlayer);
        AbsOrigin = CBaseEntity::GetAbsOrigin(this);
        NDebugOverlay::Line(
          origin: AbsOrigin,
          target: sizea,
          r: duration,
          g: v23,
          b: 0,
          noDepthTest: 1,
          duration: 0.01023);
        curtime = gpGlobals->curtime;
        *(_DWORD *)target = *(_DWORD *)(p_m_audio + 104);
        v31 = 1;
        v15 = (const Vector *)(p_m_audio + 4);
        p_m_audio = 8;
        v16 = sin((fmod(curtime, 2.0) - 1.0) * 3.141592653589793);
        *(float *)&target[4] = v16 + v16;
        do
        {
          if ( (*(_DWORD *)target & v31) != 0 )
          {
            if ( (this->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this, a2: (int)v33);
            NDebugOverlay::Line(
              origin: p_m_vecAbsOrigin,
              target: v15,
              r: 0,
              g: 32,
              b: 255,
              noDepthTest: 0,
              duration: 0.01023);
            NDebugOverlay::Cross3D(
              position: v15,
              size: *(float *)&target[4] + 16.0,
              r: 0,
              g: 0,
              b: 255,
              noDepthTest: 0,
              flDuration: 0.01023);
          }
          ++v15;
          v17 = p_m_audio-- == 1;
          v31 = __ROL4__(v31, 1);
        }
        while ( !v17 );
      }
      else
      {
        if ( CEnvSoundscape::InRangeOfPlayer(this, a2: COERCE_FLOAT(v33), a3: (int)this, a4: (int)update, pTarget: v11) )
        {
          v24 = 255;
          v22 = 255;
        }
        else
        {
          v24 = 0;
          v22 = 0;
        }
        size = (const Vector *)((int (__fastcall *)(CBasePlayer *))update->pPlayer->WorldSpaceCenter)(a1: update->pPlayer);
        v12 = CBaseEntity::GetAbsOrigin(this);
        NDebugOverlay::Line(origin: v12, target: size, r: 255, g: v22, b: v24, noDepthTest: 1, duration: 0.01023);
      }
    }
    pszValue = this->m_soundscapeName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)v33);
    NDebugOverlay::EntityTextAtPosition(
      origin: p_m_vecAbsOrigin,
      text_offset: 0,
      text: pszValue,
      duration: 0.01023,
      r: 255,
      g: 255,
      b: 255,
      a: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10220460
// Name: private: void CEnvSoundscapeTriggerable::DelegateEndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSoundscapeTriggerable::DelegateEndTouch(CEnvSoundscapeTriggerable *this, unsigned int pEnt)
{
  char *v3; // edi
  int v4; // eax
  unsigned int v5; // eax
  IHandleEntity *m_pEntity; // ecx
  CEnvSoundscape *v7; // eax

  v3 = (char *)__RTDynamicCast(
                 inptr: (void *)pEnt,
                 VfDelta: 0,
                 SrcType: &CBaseEntity `RTTI Type Descriptor',
                 TargetType: &CBasePlayer `RTTI Type Descriptor',
                 isReference: 0);
  if ( v3 != nullptr )
  {
    if ( this != nullptr )
      pEnt = this->GetRefEHandle(this)->m_Index;
    else
      pEnt = -1;
    v4 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
           this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)v3 + 144,
           src: (CHandle<CBaseEntity> *)&pEnt);
    if ( v4 != -1 )
    {
      if ( *((_DWORD *)v3 + 723) - v4 - 1 > 0 )
        _V_memmove(
          dest: (void *)(*((_DWORD *)v3 + 720) + 4 * v4),
          src: (const void *)(*((_DWORD *)v3 + 720) + 4 * v4 + 4),
          count: 4 * (*((_DWORD *)v3 + 723) - v4 - 1));
      --*((_DWORD *)v3 + 723);
    }
    if ( *((int *)v3 + 723) <= 0 )
    {
LABEL_18:
      if ( *((_DWORD *)v3 + 695) != 0 )
      {
        (**((void (__thiscall ***)(int, int))v3 + 668))(a1: (int)(v3 + 2672), a2: (int)(v3 + 2780));
        *((_DWORD *)v3 + 695) = 0;
      }
    }
    else
    {
      while ( 1 )
      {
        v5 = **((_DWORD **)v3 + 720);
        if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
        v7 = (CEnvSoundscape *)__RTDynamicCast(
                                 inptr: m_pEntity,
                                 VfDelta: 0,
                                 SrcType: &CBaseEntity `RTTI Type Descriptor',
                                 TargetType: &CEnvSoundscapeTriggerable `RTTI Type Descriptor',
                                 isReference: 0);
        if ( v7 != nullptr )
          break;
        if ( *((_DWORD *)v3 + 723) - 1 > 0 )
          _V_memmove(
            dest: *((void **)v3 + 720),
            src: (const void *)(*((_DWORD *)v3 + 720) + 4),
            count: 4 * (*((_DWORD *)v3 + 723) - 1));
        if ( (int)--*((_DWORD *)v3 + 723) <= 0 )
          goto LABEL_18;
      }
      CEnvSoundscape::WriteAudioParamsTo(this: v7, audio: (audioparams_t *)(v3 + 2672));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102205B0
// Name: public: virtual void CTriggerSoundscape::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerSoundscape::EndTouch(CTriggerSoundscape *this, CBaseEntity *pOther)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEnvSoundscapeTriggerable **v9; // eax
  CEnvSoundscapeTriggerable *v10; // eax

  m_Index = this->m_hSoundscape.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = (CEnvSoundscapeTriggerable **)&g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        v10 = *v9;
      else
        v10 = nullptr;
      CEnvSoundscapeTriggerable::DelegateEndTouch(this: v10, pEnt: (unsigned int)pOther);
    }
  }
  CBaseTrigger::EndTouch(this, pOther);
}

//------------------------------------------------------------------------------
// Address: 0x102206E0
// Name: private: void CEnvSoundscapeTriggerable::DelegateStartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSoundscapeTriggerable::DelegateStartTouch(CEnvSoundscapeTriggerable *this, unsigned int pEnt)
{
  CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *v3; // esi
  unsigned int m_Index; // ebx
  int v5; // eax
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CHandle<CBaseEntity> *m_pMemory; // eax
  int v9; // ecx
  CHandle<CBaseEntity> *v10; // esi
  CBasePlayer *pPlayer; // [esp+8h] [ebp-4h]

  v3 = (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)__RTDynamicCast(
                                                                                   inptr: (void *)pEnt,
                                                                                   VfDelta: 0,
                                                                                   SrcType: &CBaseEntity `RTTI Type Descriptor',
                                                                                   TargetType: &CBasePlayer `RTTI Type Descriptor',
                                                                                   isReference: 0);
  pPlayer = (CBasePlayer *)v3;
  if ( v3 != nullptr )
  {
    m_Index = -1;
    if ( this != nullptr )
      pEnt = this->GetRefEHandle(this)->m_Index;
    else
      pEnt = -1;
    v5 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
           this: v3 + 144,
           src: (CHandle<CBaseEntity> *)&pEnt);
    if ( v5 != -1 )
    {
      if ( v3[144].m_Size - v5 - 1 > 0 )
        _V_memmove(
          dest: &v3[144].m_Memory.m_pMemory[v5],
          src: &v3[144].m_Memory.m_pMemory[v5 + 1],
          count: 4 * (v3[144].m_Size - v5 - 1));
      --v3[144].m_Size;
    }
    if ( this != nullptr )
      m_Index = this->GetRefEHandle(this)->m_Index;
    m_Size = v3[144].m_Size;
    m_nAllocationCount = v3[144].m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v3[144],
        num: m_Size - m_nAllocationCount + 1);
    ++v3[144].m_Size;
    m_pMemory = v3[144].m_Memory.m_pMemory;
    v9 = v3[144].m_Size - 1;
    v3[144].m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[1], src: m_pMemory, count: 4 * v9);
    v10 = v3[144].m_Memory.m_pMemory;
    if ( v10 != nullptr )
      v10->m_Index = m_Index;
    CEnvSoundscape::WriteAudioParamsTo(this, audio: &pPlayer->m_Local.m_audio);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10220830
// Name: public: virtual void CTriggerSoundscape::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerSoundscape::StartTouch(CTriggerSoundscape *this, CBaseEntity *pOther)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEnvSoundscapeTriggerable **v9; // eax
  CEnvSoundscapeTriggerable *v10; // eax

  m_Index = this->m_hSoundscape.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = (CEnvSoundscapeTriggerable **)&g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        v10 = *v9;
      else
        v10 = nullptr;
      CEnvSoundscapeTriggerable::DelegateStartTouch(this: v10, pEnt: (unsigned int)pOther);
    }
  }
  CBaseTrigger::StartTouch(this, pOther);
}

//------------------------------------------------------------------------------
// Address: 0x10220A70
// Name: public: void CTriggerSoundscape::PlayerUpdateThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerSoundscape::PlayerUpdateThink(CTriggerSoundscape *this)
{
  double curtime; // xmm0_8
  CTriggerSoundscape *v2; // ebx
  int m_Size; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_spectators; // esi
  int j; // eax
  CBasePlayer *v6; // eax
  CBaseEntity *v7; // edi
  const CBaseHandle *v8; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode *m_Index; // ebx
  int m_nAllocationCount; // eax
  vgui::TreeNode **v12; // ecx
  int v13; // eax
  vgui::TreeNode **v14; // eax
  int k; // ebx
  unsigned int v16; // eax
  CEntInfo *v17; // ecx
  CBaseEntity *m_pEntity; // edi
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > oldSpectators; // [esp+14h] [ebp-20h] BYREF
  CHandle<CBaseEntity> src; // [esp+28h] [ebp-Ch] BYREF
  CTriggerSoundscape *v21; // [esp+2Ch] [ebp-8h]
  int i; // [esp+30h] [ebp-4h]

  curtime = gpGlobals->curtime;
  v2 = this;
  v21 = this;
  CBaseEntity::SetNextThink(this, thinkTime: curtime + 0.2, szContext: nullptr);
  m_Size = v2->m_spectators.m_Size;
  memset(&oldSpectators, 0, sizeof(oldSpectators));
  p_m_spectators = (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_spectators;
  CUtlVector<CHandle<CFish>,CUtlMemory<CHandle<CFish>,int>>::InsertMultipleBefore(
    this: (CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *)&oldSpectators,
    elem: 0,
    num: m_Size);
  for ( j = 0; j < m_Size; ++j )
    oldSpectators.m_Memory.m_pMemory[j].m_Index = (unsigned int)p_m_spectators->m_pMemory[j];
  v2->m_spectators.m_Size = 0;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v6 = UTIL_PlayerByIndex(playerIndex: i);
    v7 = v6;
    if ( v6 != nullptr && !v6->IsAlive(this: v6) && CBaseEntity::Intersects(this: v2, pOther: v7) )
    {
      src.m_Index = v7->GetRefEHandle(this: v7)->m_Index;
      if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
             this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&oldSpectators,
             &src) < 0 )
        v2->StartTouch(this: v2, a2: v7);
      v8 = v7->GetRefEHandle(this: v7);
      m_pMemory = p_m_spectators[1].m_pMemory;
      m_Index = (vgui::TreeNode *)v8->m_Index;
      m_nAllocationCount = p_m_spectators->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: p_m_spectators, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_spectators[1].m_pMemory;
      v12 = p_m_spectators->m_pMemory;
      v13 = (char *)p_m_spectators[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_spectators[1].m_nAllocationCount = (int)p_m_spectators->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[(_DWORD)m_pMemory + 1], src: &v12[(_DWORD)m_pMemory], count: 4 * v13);
      v14 = &p_m_spectators->m_pMemory[(_DWORD)m_pMemory];
      if ( v14 != nullptr )
        *v14 = m_Index;
      v2 = v21;
    }
  }
  for ( k = 0; k < oldSpectators.m_Size; ++k )
  {
    v16 = oldSpectators.m_Memory.m_pMemory[k].m_Index;
    if ( v16 != -1 )
    {
      v17 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v16];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber == HIWORD(v16) )
      {
        m_pEntity = (CBaseEntity *)v17->m_pEntity;
        if ( v17->m_pEntity != nullptr )
        {
          src.m_Index = m_pEntity->GetRefEHandle(this: v17->m_pEntity)->m_Index;
          if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
                 this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)p_m_spectators,
                 &src) < 0 )
            v21->EndTouch(this: v21, a2: m_pEntity);
        }
      }
    }
  }
  if ( oldSpectators.m_Memory.m_nGrowSize >= 0 && oldSpectators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: oldSpectators.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10220ED0
// Name: public: virtual void CTriggerSoundscape::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerSoundscape::Spawn(CTriggerSoundscape *this)
{
  CBaseTrigger::Spawn(this);
  CBaseTrigger::InitTrigger(this);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CTriggerSoundscape::PlayerUpdateThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.2, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1040A2D0
// Name: _dynamic_initializer_for__soundscape_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundscape_debug__()
{
  ConVar::ConVar(
    this: &soundscape_debug,
    pName: "soundscape_debug",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "When on, draws lines to all env_soundscape entities. Green lines show the active soundscape, red lines show soundsca"
    "pes that aren't in range, and white lines show soundscapes that are in range, but not the active soundscape.");
  return atexit(func: dynamic_atexit_destructor_for__soundscape_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A320
// Name: CEnvSoundscapeProxy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvSoundscapeProxy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvSoundscapeProxy>();
  CEnvSoundscapeProxy_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A350
// Name: CEnvSoundscape_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvSoundscape_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvSoundscape>();
  CEnvSoundscape_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A380
// Name: CEnvSoundscapeTriggerable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvSoundscapeTriggerable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvSoundscapeTriggerable>();
  CEnvSoundscapeTriggerable_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A3B0
// Name: CTriggerSoundscape_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTriggerSoundscape_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTriggerSoundscape>(__formal: nullptr);
  CTriggerSoundscape_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A3C0
// Name: _dynamic_initializer_for__soundscape_flush_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundscape_flush_command__()
{
  ConCommand::ConCommand(
    this: &soundscape_flush_command,
    pName: "soundscape_flush",
    callback: (void (__cdecl *)())soundscape_flush,
    pHelpString: "Flushes the server & client side soundscapes",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__soundscape_flush_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E060
// Name: _dynamic_atexit_destructor_for__soundscape_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundscape_debug__()
{
  ConVar::~ConVar(this: &soundscape_debug);
}

//------------------------------------------------------------------------------
// Address: 0x1041E0B0
// Name: _dynamic_atexit_destructor_for__soundscape_flush_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundscape_flush_command__()
{
  ConCommand::~ConCommand(this: &soundscape_flush_command);
}

//------------------------------------------------------------------------------
// Address: 0x10220C70
// Name: struct datamap_t __near * DataMapInit<class CTriggerSoundscape>(class CTriggerSoundscape __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerSoundscape>()
{
  char *Name; // eax

  if ( (_S5_31 & 1) == 0 )
  {
    _S5_31 |= 1u;
    nameHolder_397.m_pszBase = "CTriggerSoundscape";
    nameHolder_397.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_397.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_397.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_397.m_Names.m_Size = 0;
    nameHolder_397.m_Names.m_pElements = nullptr;
    nameHolder_397.m_nLenBase = 18;
    atexit(func: DataMapInit_CTriggerSoundscape__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerSoundscape::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  if ( (_S5_31 & 2) == 0 )
  {
    _S5_31 |= 2u;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_397, pszIdentifier: "PlayerUpdateThink");
    *(_QWORD *)&dataDesc_485[1].td = 0;
    *(_QWORD *)&dataDesc_485[1].override_field = 0;
    *(_QWORD *)&dataDesc_485[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_485[1].flatOffset[1] = 0;
    dataDesc_485[2].fieldTolerance = 0.0;
    dataDesc_485[3].fieldTolerance = 0.0;
    dataDesc_485[1].fieldName = Name;
    dataDesc_485[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_485[1].fieldSize = 2097153;
    dataDesc_485[1].externalName = nullptr;
    dataDesc_485[1].pSaveRestoreOps = nullptr;
    dataDesc_485[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerSoundscape::PlayerUpdateThink;
    dataDesc_485[2].fieldType = FIELD_STRING;
    dataDesc_485[2].fieldName = "m_SoundscapeName";
    dataDesc_485[2].fieldOffset = 1156;
    *(_DWORD *)&dataDesc_485[2].fieldSize = 393217;
    dataDesc_485[2].externalName = "soundscape";
    dataDesc_485[2].pSaveRestoreOps = nullptr;
    dataDesc_485[2].inputFunc = nullptr;
    dataDesc_485[2].td = nullptr;
    dataDesc_485[2].fieldSizeInBytes = 4;
    dataDesc_485[2].override_field = nullptr;
    dataDesc_485[2].override_count = 0;
    *(_QWORD *)dataDesc_485[2].flatOffset = 0;
    *(_DWORD *)&dataDesc_485[2].flatGroup = 0;
    dataDesc_485[3].fieldType = FIELD_EHANDLE;
    dataDesc_485[3].fieldName = "m_hSoundscape";
    dataDesc_485[3].fieldOffset = 1152;
    dataDesc_485[3].fieldSize = 1;
    dataDesc_485[3].flags = 2;
    dataDesc_485[3].externalName = nullptr;
    dataDesc_485[3].pSaveRestoreOps = nullptr;
    dataDesc_485[3].inputFunc = nullptr;
    dataDesc_485[3].td = nullptr;
    dataDesc_485[3].fieldSizeInBytes = 4;
    dataDesc_485[3].override_field = nullptr;
    dataDesc_485[3].override_count = 0;
    *(_QWORD *)dataDesc_485[3].flatOffset = 0;
    *(_DWORD *)&dataDesc_485[3].flatGroup = 0;
    dataDesc_485[4].fieldType = FIELD_CUSTOM;
    dataDesc_485[4].fieldName = "m_spectators";
    dataDesc_485[4].fieldOffset = 1160;
    *(_DWORD *)&dataDesc_485[4].fieldSize = 131073;
    dataDesc_485[4].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int>>,13>::`vftable';
    }
    dataDesc_485[4].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int>>>'::`2'::ops;
    dataDesc_485[4].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_485[4].td = 0;
    *(_QWORD *)&dataDesc_485[4].override_field = 0;
    *(_QWORD *)&dataDesc_485[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_485[4].flatOffset[1] = 0;
  }
  CTriggerSoundscape::m_DataMap.dataNumFields = 4;
  CTriggerSoundscape::m_DataMap.dataDesc = &dataDesc_485[1];
  return &CTriggerSoundscape::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040A300
// Name: _dynamic_initializer_for__env_soundscape_proxy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_soundscape_proxy__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvSoundscapeProxy> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_soundscape_proxy,
           a3: "env_soundscape_proxy");
}

//------------------------------------------------------------------------------
// Address: 0x1040A330
// Name: _dynamic_initializer_for__env_soundscape__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_soundscape__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvSoundscape> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_soundscape,
           a3: "env_soundscape");
}

//------------------------------------------------------------------------------
// Address: 0x1040A360
// Name: _dynamic_initializer_for__env_soundscape_triggerable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_soundscape_triggerable__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvSoundscapeTriggerable> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_soundscape_triggerable,
           a3: "env_soundscape_triggerable");
}

//------------------------------------------------------------------------------
// Address: 0x1040A3F0
// Name: _dynamic_initializer_for__g_SoundscapeSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SoundscapeSystem__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_SoundscapeSystem, name: "CSoundscapeSystem");
  g_SoundscapeSystem.__vftable = (CSoundscapeSystem_vtbl *)&CSoundscapeSystem::`vftable';
  CStringRegistry::CStringRegistry(this: &g_SoundscapeSystem.m_soundscapes);
  g_SoundscapeSystem.m_soundscapeEntities.m_Memory.m_pMemory = nullptr;
  g_SoundscapeSystem.m_soundscapeEntities.m_Memory.m_nAllocationCount = 0;
  g_SoundscapeSystem.m_soundscapeEntities.m_Memory.m_nGrowSize = 0;
  g_SoundscapeSystem.m_soundscapeEntities.m_Size = 0;
  g_SoundscapeSystem.m_soundscapeEntities.m_pElements = nullptr;
  g_SoundscapeSystem.m_soundscapesInCluster.m_Memory.m_pMemory = nullptr;
  g_SoundscapeSystem.m_soundscapesInCluster.m_Memory.m_nAllocationCount = 0;
  g_SoundscapeSystem.m_soundscapesInCluster.m_Memory.m_nGrowSize = 0;
  g_SoundscapeSystem.m_soundscapesInCluster.m_Size = 0;
  g_SoundscapeSystem.m_soundscapesInCluster.m_pElements = nullptr;
  g_SoundscapeSystem.m_soundscapeIndexList.m_Memory.m_pMemory = nullptr;
  g_SoundscapeSystem.m_soundscapeIndexList.m_Memory.m_nAllocationCount = 0;
  g_SoundscapeSystem.m_soundscapeIndexList.m_Memory.m_nGrowSize = 0;
  g_SoundscapeSystem.m_soundscapeIndexList.m_Size = 0;
  g_SoundscapeSystem.m_soundscapeIndexList.m_pElements = nullptr;
  g_SoundscapeSystem.m_soundscapeSounds.m_Memory.m_pMemory = nullptr;
  g_SoundscapeSystem.m_soundscapeSounds.m_Memory.m_nAllocationCount = 0;
  g_SoundscapeSystem.m_soundscapeSounds.m_Memory.m_nGrowSize = 0;
  g_SoundscapeSystem.m_soundscapeSounds.m_Size = 0;
  g_SoundscapeSystem.m_soundscapeSounds.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_SoundscapeSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A490
// Name: _dynamic_initializer_for__sv_soundscape_printdebuginfo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_soundscape_printdebuginfo_command__()
{
  ConCommand::ConCommand(
    this: &sv_soundscape_printdebuginfo_command,
    pName: "sv_soundscape_printdebuginfo",
    callback: (void (__cdecl *)())sv_soundscape_printdebuginfo,
    pHelpString: "print soundscapes",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_soundscape_printdebuginfo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E070
// Name: _DataMapInit_CEnvSoundscapeProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvSoundscapeProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_394);
}

//------------------------------------------------------------------------------
// Address: 0x1041E080
// Name: _DataMapInit_CEnvSoundscape__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvSoundscape__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_395);
}

//------------------------------------------------------------------------------
// Address: 0x1041E090
// Name: _DataMapInit_CEnvSoundscapeTriggerable__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvSoundscapeTriggerable__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_396);
}

//------------------------------------------------------------------------------
// Address: 0x1041E0A0
// Name: _DataMapInit_CTriggerSoundscape__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTriggerSoundscape__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_397);
}

//------------------------------------------------------------------------------
// Address: 0x1041E0C0
// Name: _dynamic_atexit_destructor_for__sv_soundscape_printdebuginfo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_soundscape_printdebuginfo_command__()
{
  ConCommand::~ConCommand(this: &sv_soundscape_printdebuginfo_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041E0D0
// Name: _dynamic_atexit_destructor_for__g_SoundscapeSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SoundscapeSystem__()
{
  CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,int>>::~CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,int>>(this: &g_SoundscapeSystem.m_soundscapeSounds);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_SoundscapeSystem.m_soundscapeIndexList);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_SoundscapeSystem.m_soundscapesInCluster);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_SoundscapeSystem.m_soundscapeEntities);
  CStringRegistry::~CStringRegistry(this: &g_SoundscapeSystem.m_soundscapes);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_SoundscapeSystem);
}
