// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhudradar.cpp
// Functions: 67
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhudradar.h"

//------------------------------------------------------------------------------
// Address: 0x1021C680
// Name: drawradar
// Source: json
//------------------------------------------------------------------------------
void __cdecl drawradar()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "SFHudRadar");
  Element[419].m_bActive |= 4u;
}

//------------------------------------------------------------------------------
// Address: 0x1021C6A0
// Name: hideradar
// Source: json
//------------------------------------------------------------------------------
void __cdecl hideradar()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "SFHudRadar");
  Element[419].m_bActive &= ~4u;
}

//------------------------------------------------------------------------------
// Address: 0x1021C6C0
// Name: public: void SFHudRadar::SFHudRadarIconPackage::SetIsSpeaking(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SFHudRadarIconPackage::SetIsSpeaking(SFHudRadar::SFHudRadarIconPackage *this, bool value)
{
  char v2; // al

  if ( !value || (v2 = 1, (*((_BYTE *)this + 209) & 1) == 0) )
    v2 = 0;
  *((_BYTE *)this + 208) ^= (*((_BYTE *)this + 208) ^ (8 * v2)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x1021C6F0
// Name: public: void SFHudRadar::SFHudRadarIconPackage::SetVisibilityFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SFHudRadarIconPackage::SetVisibilityFlags(
        SFHudRadar::SFHudRadarIconPackage *this,
        int newFlags)
{
  SFHudRadar::SFHudRadarIconPackage *v2; // edi
  int m_iCurrentVisibilityFlags; // edx
  int v4; // eax
  int v5; // ecx
  void *m_IconPackage; // esi
  int v7; // ebx
  int v8; // esi
  void **m_Icons; // edi
  SFHudRadar::SFHudRadarIconPackage *v10; // [esp+8h] [ebp-8h]
  int diffFlags; // [esp+Ch] [ebp-4h]
  int newFlagsa; // [esp+18h] [ebp+8h]

  v2 = this;
  m_iCurrentVisibilityFlags = this->m_iCurrentVisibilityFlags;
  v4 = newFlags & 0x1FFFF;
  v5 = newFlags & 0x1FFFF ^ m_iCurrentVisibilityFlags;
  v10 = v2;
  newFlagsa = newFlags & 0x1FFFF;
  diffFlags = v5;
  if ( v5 != 0 )
  {
    m_IconPackage = v2->m_IconPackage;
    if ( m_IconPackage != nullptr )
    {
      if ( (m_iCurrentVisibilityFlags != 0) != (v4 != 0) )
        v2->m_pScaleformUI->Value_SetVisible(this: v2->m_pScaleformUI, a2: m_IconPackage, a3: v4 != 0);
      v7 = 0;
      v8 = 1;
      m_Icons = v2->m_Icons;
      do
      {
        if ( diffFlags == 0 )
          break;
        if ( (diffFlags & 1) != 0 )
          v10->m_pScaleformUI->Value_SetVisible(this: v10->m_pScaleformUI, a2: *m_Icons, a3: (v8 & newFlagsa) != 0);
        diffFlags >>= 1;
        ++v7;
        ++m_Icons;
        v8 = __ROL4__(v8, 1);
      }
      while ( v7 < 17 );
      v2 = v10;
      v4 = newFlagsa;
    }
    v2->m_iCurrentVisibilityFlags = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021C7A0
// Name: public: void SFHudRadar::SFHudRadarHostageIcons::Init(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SFHudRadarHostageIcons::Init(
        SFHudRadar::SFHudRadarHostageIcons *this,
        IScaleformUI *scaleformui,
        void *iconPackage)
{
  int v4; // edi
  IScaleformUI_vtbl *v5; // eax
  IScaleformUI *scaleformuia; // [esp+14h] [ebp+8h]

  this->m_pScaleformUI = scaleformui;
  this->m_IconPackage = scaleformui->CreateValue_6(this: scaleformui, a2: iconPackage);
  v4 = 0;
  scaleformuia = (IScaleformUI *)this->m_Icons;
  do
  {
    if ( hostageIconNames[v4] == nullptr )
      break;
    v5 = (IScaleformUI_vtbl *)this->m_pScaleformUI->Value_GetMember(
                                this: this->m_pScaleformUI,
                                a2: this->m_IconPackage,
                                a3: hostageIconNames[v4]);
    scaleformuia->__vftable = v5;
    if ( v5 != nullptr )
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: v5, a3: this->m_iCurrentIcon == v4);
    ++scaleformuia;
    ++v4;
  }
  while ( v4 < 4 );
  this->m_pScaleformUI->Value_SetVisible(
    this: this->m_pScaleformUI,
    a2: this->m_IconPackage,
    a3: this->m_iCurrentIcon != 4);
}

//------------------------------------------------------------------------------
// Address: 0x1021C840
// Name: public: virtual void SFHudRadar::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::LevelInit(SFHudRadar *this)
{
  if ( (*((_BYTE *)this + 23476) & 3) == 0 )
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 2,
      a3: "Radar",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudRadar_Radar);
}

//------------------------------------------------------------------------------
// Address: 0x1021C870
// Name: protected: void SFHudRadar::LazyCreateGoalIcons(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::LazyCreateGoalIcons(SFHudRadar *this)
{
  char v2; // al
  IGameResources *v3; // eax
  C_CS_PlayerResource *v4; // edi
  signed int i; // edi
  Vector hostageI; // [esp+4h] [ebp-1Ch] BYREF
  Vector bombA; // [esp+10h] [ebp-10h] BYREF
  C_CS_PlayerResource *pCSPR; // [esp+1Ch] [ebp-4h]

  v2 = *((_BYTE *)this + 23476);
  if ( (v2 & 0x10) == 0 && (v2 & 2) != 0 )
  {
    v3 = GameResources();
    if ( v3 != nullptr )
    {
      v4 = (C_CS_PlayerResource *)&v3[-608];
      pCSPR = (C_CS_PlayerResource *)&v3[-608];
      if ( v3 != (IGameResources *)2432 )
      {
        this->m_iNumGoalIcons = 0;
        if ( C_CSGameRules::IsBombDefuseMap(this: (C_CSGameRules *)g_pGameRules) )
        {
          C_CS_PlayerResource::GetBombsiteAPosition(this: v4, result: &bombA);
          if ( vec3_origin.x != bombA.x || vec3_origin.y != bombA.y || vec3_origin.z != bombA.z )
          {
            this->m_GoalIcons[this->m_iNumGoalIcons].m_Position = bombA;
            this->m_GoalIcons[this->m_iNumGoalIcons].m_Icon = this->m_BombZoneIcons[0];
            this->m_pScaleformUI->Value_SetVisible(
              this: this->m_pScaleformUI,
              a2: this->m_GoalIcons[this->m_iNumGoalIcons].m_Icon,
              a3: true);
            ++this->m_iNumGoalIcons;
          }
          C_CS_PlayerResource::GetBombsiteBPosition(this: v4, result: &hostageI);
          if ( vec3_origin.x != hostageI.x || vec3_origin.y != hostageI.y || vec3_origin.z != hostageI.z )
          {
            this->m_GoalIcons[this->m_iNumGoalIcons].m_Position = hostageI;
            this->m_GoalIcons[this->m_iNumGoalIcons].m_Icon = this->m_BombZoneIcons[1];
            this->m_pScaleformUI->Value_SetVisible(
              this: this->m_pScaleformUI,
              a2: this->m_GoalIcons[this->m_iNumGoalIcons].m_Icon,
              a3: true);
            ++this->m_iNumGoalIcons;
            *((_BYTE *)this + 23476) |= 0x10u;
            return;
          }
        }
        else if ( C_CSGameRules::IsHostageRescueMap(this: (C_CSGameRules *)g_pGameRules) )
        {
          for ( i = 0; i < 4; ++i )
          {
            C_CS_PlayerResource::GetHostageRescuePosition(this: pCSPR, result: &hostageI, iIndex: i);
            if ( vec3_origin.x != hostageI.x || vec3_origin.y != hostageI.y || vec3_origin.z != hostageI.z )
            {
              this->m_GoalIcons[this->m_iNumGoalIcons].m_Position = hostageI;
              this->m_GoalIcons[this->m_iNumGoalIcons].m_Icon = this->m_HostageZoneIcons[0];
              this->m_pScaleformUI->Value_SetVisible(
                this: this->m_pScaleformUI,
                a2: this->m_GoalIcons[this->m_iNumGoalIcons].m_Icon,
                a3: true);
              ++this->m_iNumGoalIcons;
            }
          }
        }
        *((_BYTE *)this + 23476) |= 0x10u;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021CB20
// Name: public: void SFHudRadar::MapLoaded(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::MapLoaded(SFHudRadar *this, IScaleformUI *pui, void *obj)
{
  long double v4; // st7

  v4 = pui->Params_GetArgAsNumber(this: pui, a2: obj, a3: 0);
  this->m_fPixelToRadarScale = v4;
  this->m_fWorldToRadarScale = v4 * this->m_fWorldToPixelScale;
  V_strncpy(pDest: this->m_cLoadedMapName, pSrc: this->m_cDesiredMapName, maxLen: 34);
}

//------------------------------------------------------------------------------
// Address: 0x1021CB60
// Name: protected: int SFHudRadar::GetPlayerIndexFromUserID(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SFHudRadar::GetPlayerIndexFromUserID(SFHudRadar *this, int userID)
{
  int m_iLastPlayerIndex; // edx
  int result; // eax
  int *i; // ecx

  m_iLastPlayerIndex = this->m_iLastPlayerIndex;
  result = 0;
  if ( m_iLastPlayerIndex < 0 )
    return -1;
  for ( i = &this->m_Players[0].m_iUserID; (i[21] & 1) == 0 || *i != userID; i += 53 )
  {
    if ( ++result > m_iLastPlayerIndex )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021CBA0
// Name: protected: int SFHudRadar::GetHostageIndexFromHostageEntityID(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SFHudRadar::GetHostageIndexFromHostageEntityID(SFHudRadar *this, int entityID)
{
  int m_iLastHostageIndex; // edx
  int result; // eax
  int *i; // ecx

  m_iLastHostageIndex = this->m_iLastHostageIndex;
  result = 0;
  if ( m_iLastHostageIndex < 0 )
    return -1;
  for ( i = &this->m_Hostages[0].m_iUserID; (i[21] & 1) == 0 || *i != entityID; i += 53 )
  {
    if ( ++result > m_iLastHostageIndex )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021CBE0
// Name: protected: int SFHudRadar::GetDecoyIndexFromEntityID(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SFHudRadar::GetDecoyIndexFromEntityID(SFHudRadar *this, int entityID)
{
  int m_iLastDecoyIndex; // edx
  int result; // eax
  int *i; // ecx

  m_iLastDecoyIndex = this->m_iLastDecoyIndex;
  result = 0;
  if ( m_iLastDecoyIndex < 0 )
    return -1;
  for ( i = &this->m_Decoys[0].m_iUserID; (i[21] & 1) == 0 || *i != entityID; i += 53 )
  {
    if ( ++result > m_iLastDecoyIndex )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021CC20
// Name: protected: void SFHudRadar::SetVisibilityFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SetVisibilityFlags(SFHudRadar *this, __int16 newFlags)
{
  int v2; // edx
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  void **m_Icons; // edi
  SFHudRadar *v7; // [esp+0h] [ebp-8h]
  int diffFlags; // [esp+4h] [ebp-4h]
  int newFlagsa; // [esp+10h] [ebp+8h]

  v2 = newFlags & 0x1FFF;
  v3 = v2 ^ this->m_iCurrentVisibilityFlags;
  v7 = this;
  newFlagsa = v2;
  diffFlags = v3;
  if ( v3 != 0 )
  {
    if ( this->m_Icons[10] != nullptr )
    {
      v4 = 0;
      v5 = 1;
      m_Icons = this->m_Icons;
      do
      {
        if ( v3 == 0 )
          break;
        if ( (v3 & 1) != 0 )
        {
          this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: *m_Icons, a3: (v5 & v2) != 0);
          this = v7;
          v2 = newFlagsa;
          v3 = diffFlags;
        }
        ++v4;
        ++m_Icons;
        v3 >>= 1;
        v5 = __ROL4__(v5, 1);
        diffFlags = v3;
      }
      while ( v4 < 13 );
    }
    this->m_iCurrentVisibilityFlags = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021CCB0
// Name: protected: void SFHudRadar::SetVisibilityFlagsCash(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SetVisibilityFlagsCash(SFHudRadar *this, char newFlags)
{
  int v2; // edx
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  ISFTextObject **m_IconsCash; // edi
  SFHudRadar *v7; // [esp+0h] [ebp-8h]
  int diffFlags; // [esp+4h] [ebp-4h]
  int newFlagsa; // [esp+10h] [ebp+8h]

  v2 = newFlags & 3;
  v3 = v2 ^ this->m_iCashCurrentVisibilityFlags;
  v7 = this;
  newFlagsa = v2;
  diffFlags = v3;
  if ( v3 != 0 )
  {
    v4 = 0;
    v5 = 1;
    m_IconsCash = this->m_IconsCash;
    do
    {
      if ( v3 == 0 )
        break;
      if ( (v3 & 1) != 0 && *m_IconsCash != nullptr )
      {
        (*m_IconsCash)->SetVisible(this: *m_IconsCash, a2: (v5 & v2) != 0);
        this = v7;
        v2 = newFlagsa;
        v3 = diffFlags;
      }
      ++v4;
      ++m_IconsCash;
      v3 >>= 1;
      v5 = __ROL4__(v5, 1);
      diffFlags = v3;
    }
    while ( v4 < 2 );
    this->m_iCashCurrentVisibilityFlags = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021CD40
// Name: public: void SFHudRadar::SFHudRadarIconPackage::ClearAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SFHudRadarIconPackage::ClearAll(SFHudRadar::SFHudRadarIconPackage *this)
{
  char v2; // cl

  this->m_IconPackage = nullptr;
  _V_memset(dest: (int)this->m_Icons, fill: nullptr, count: 0x44u);
  v2 = *((_BYTE *)this + 208);
  *((_BYTE *)this + 209) &= ~1u;
  this->m_fCurrentAlpha = 1.0;
  this->m_pScaleformUI = nullptr;
  this->m_iCurrentVisibilityFlags = 0;
  this->m_Health = 0;
  this->m_iPlayerType = 0;
  this->m_iUserID = 0;
  this->m_fGhostTime = -1000.0;
  this->m_fDeadTime = -1000.0;
  this->m_IconPackType = ICON_PACK_PLAYER;
  this->m_fRoundStartTime = -1000.0;
  this->m_iIndex = -1;
  *((_BYTE *)this + 208) = v2 & 0x2C | 2;
  this->m_wcName[0] = 0;
  this->m_Position = vec3_origin;
  this->m_Angle.x = 0.0;
  this->m_Angle.y = 0.0;
  this->m_Angle.z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1021CE00
// Name: public: void SFHudRadar::SFHudRadarIconPackage::Init(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SFHudRadarIconPackage::Init(
        SFHudRadar::SFHudRadarIconPackage *this,
        IScaleformUI *pui,
        void *iconPackage)
{
  int v5; // ebx
  void *v6; // eax
  float m_fCurrentAlpha; // xmm0_4
  IScaleformUI *m_pScaleformUI; // ecx
  void *m_IconPackage; // eax
  ScaleformDisplayInfo displayInfo; // [esp+Ch] [ebp-3Ch] BYREF
  void **m_Icons; // [esp+44h] [ebp-4h]
  const char **puia; // [esp+50h] [ebp+8h]

  this->m_pScaleformUI = pui;
  this->m_IconPackage = pui->CreateValue_6(this: pui, a2: iconPackage);
  v5 = 1;
  puia = playerIconNames;
  m_Icons = this->m_Icons;
  do
  {
    if ( *puia == nullptr )
      break;
    v6 = pui->Value_GetMember(this: pui, a2: iconPackage, a3: *puia);
    *m_Icons = v6;
    if ( v6 != nullptr )
      pui->Value_SetVisible(this: pui, a2: v6, a3: (v5 & this->m_iCurrentVisibilityFlags) != 0);
    ++m_Icons;
    v5 = __ROL4__(v5, 1);
    ++puia;
  }
  while ( (int)puia < (int)&playerIconNames[17] );
  m_fCurrentAlpha = this->m_fCurrentAlpha;
  m_pScaleformUI = this->m_pScaleformUI;
  displayInfo.m_bVisibility = this->m_iCurrentVisibilityFlags != 0;
  m_IconPackage = this->m_IconPackage;
  displayInfo.m_fAlpha = (float)(m_fCurrentAlpha * 100.0);
  displayInfo.m_iSetFlags = 24;
  m_pScaleformUI->Value_SetDisplayInfo(this: m_pScaleformUI, a2: m_IconPackage, a3: &displayInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1021CED0
// Name: public: void SFHudRadar::SFHudRadarIconPackage::NukeFromOrbit(class SFHudRadar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SFHudRadarIconPackage::NukeFromOrbit(
        SFHudRadar::SFHudRadarIconPackage *this,
        SFHudRadar *pSFUI)
{
  SFHudRadar::SFHudRadarIconPackage *v2; // esi
  void **m_Icons; // esi
  int i; // ebx

  v2 = this;
  if ( pSFUI->m_bFlashAPIIsValid )
  {
    if ( pSFUI->m_pScaleformUI != nullptr && this->m_IconPackage != nullptr )
    {
      pSFUI->m_pScaleformUI->ReleaseValue(this: pSFUI->m_pScaleformUI, a2: this->m_IconPackage);
      v2->m_IconPackage = nullptr;
    }
    m_Icons = v2->m_Icons;
    for ( i = 17; i != 0; --i )
    {
      if ( pSFUI->m_pScaleformUI != nullptr && *m_Icons != nullptr )
      {
        pSFUI->m_pScaleformUI->ReleaseValue(this: pSFUI->m_pScaleformUI, a2: *m_Icons);
        *m_Icons = nullptr;
      }
      ++m_Icons;
    }
    v2 = this;
  }
  SFHudRadar::SFHudRadarIconPackage::ClearAll(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1021CF50
// Name: public: void SFHudRadar::SFHudRadarIconPackage::SetIsDead(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SFHudRadarIconPackage::SetIsDead(SFHudRadar::SFHudRadarIconPackage *this, bool value)
{
  char v2; // al

  v2 = *((_BYTE *)this + 208);
  if ( value != ((v2 & 0x10) != 0) )
  {
    if ( value )
    {
      if ( (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_fRoundStartTime) > 0.25 && (v2 & 0x40) == 0 )
      {
        this->m_fGhostTime = -1000.0;
        *((_BYTE *)this + 208) = v2 | 0x40;
      }
      this->m_fDeadTime = *(float *)(gpGlobals.m_Index + 12);
    }
    else
    {
      this->m_fDeadTime = -1000.0;
    }
    *((_BYTE *)this + 208) ^= (*((_BYTE *)this + 208) ^ (16 * value)) & 0x10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021CFE0
// Name: public: void SFHudRadar::SFHudRadarIconPackage::SetPlayerTeam(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SFHudRadarIconPackage::SetPlayerTeam(SFHudRadar::SFHudRadarIconPackage *this, int team)
{
  int v2; // eax

  if ( team != 0 )
  {
    if ( team == 2 )
    {
      v2 = 9;
    }
    else if ( team == 3 )
    {
      v2 = 5;
    }
    else
    {
      v2 = 0;
    }
  }
  else
  {
    v2 = 13;
  }
  if ( this->m_iPlayerType != v2 )
  {
    this->m_iPlayerType = v2;
    SFHudRadar::SFHudRadarIconPackage::SetVisibilityFlags(this, newFlags: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D030
// Name: public: void SFHudRadar::SFHudRadarHostageIcons::ReleaseHandles(class SFHudRadar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SFHudRadarHostageIcons::ReleaseHandles(
        SFHudRadar::SFHudRadarHostageIcons *this,
        SFHudRadar *pradar)
{
  void **m_Icons; // esi
  int i; // ebx

  if ( this->m_IconPackage != nullptr && pradar->m_bFlashAPIIsValid )
  {
    if ( pradar->m_pScaleformUI != nullptr && this->m_IconPackage != nullptr )
    {
      pradar->m_pScaleformUI->ReleaseValue(this: pradar->m_pScaleformUI, a2: this->m_IconPackage);
      this->m_IconPackage = nullptr;
    }
    m_Icons = this->m_Icons;
    for ( i = 4; i != 0; --i )
    {
      if ( pradar->m_pScaleformUI != nullptr && *m_Icons != nullptr )
      {
        pradar->m_pScaleformUI->ReleaseValue(this: pradar->m_pScaleformUI, a2: *m_Icons);
        *m_Icons = nullptr;
      }
      ++m_Icons;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D0A0
// Name: protected: void SFHudRadar::Show(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::Show(SFHudRadar *this, bool show)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx

  if ( (*((_BYTE *)this + 23476) & 2) != 0 && show != this->m_bActive )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      m_pScaleformUI = this->m_pScaleformUI;
      if ( show )
        m_pScaleformUI->Value_InvokeWithoutReturn(
          this: m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "showPanel",
          a4: nullptr,
          a5: 0);
      else
        m_pScaleformUI->Value_InvokeWithoutReturn(
          this: m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "hidePanel",
          a4: nullptr,
          a5: 0);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D130
// Name: public: virtual void SFHudRadar::FlashLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudRadar::FlashLoaded(SFHudRadar *this@<ecx>, int a2@<edi>)
{
  void *v3; // eax
  int v4; // ebx
  void *v5; // eax
  void *v6; // eax
  void *v7; // eax
  void *v8; // eax
  void **m_HostageZoneIcons; // edi
  void *v10; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  void *v12; // ebx
  IScaleformUI *v13; // ecx
  void *v14; // edi
  IScaleformUI *v15; // ecx
  const char *v16; // eax
  void **m_Icons; // edi
  ISFTextObject *v18; // eax
  IScaleformUI *v19; // ecx
  void *(__thiscall *Value_GetMember)(IScaleformUI *, void *, const char *); // eax
  void *v21; // edi
  ISFTextObject *v22; // eax
  IScaleformUI *v23; // ecx
  IScaleformUI_vtbl *v24; // edx
  ISFTextObject *v25; // edi
  void *v26; // ebx
  char hostageIconName[20]; // [esp+8h] [ebp-30h] BYREF
  char cHostageZoneIconName[20]; // [esp+1Ch] [ebp-1Ch] BYREF
  int i; // [esp+30h] [ebp-8h]
  int index; // [esp+34h] [ebp-4h]

  v3 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "RadarModule");
  v4 = 0;
  this->m_RadarModule = v3;
  if ( v3 == nullptr )
    return;
  v5 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int))this->m_pScaleformUI->Value_GetMember)(
                 a1: this->m_pScaleformUI,
                 a2: v3,
                 a3: "Radar",
                 a4: a2);
  this->m_Radar = v5;
  if ( v5 == nullptr )
    goto LABEL_10;
  v6 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v5, a3: "MapRotation");
  this->m_MapRotation = v6;
  if ( v6 != nullptr )
    this->m_MapTranslation = this->m_pScaleformUI->Value_GetMember(
                               this: this->m_pScaleformUI,
                               a2: v6,
                               a3: "MapTranslation");
  v7 = (void *)((int (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Value_GetMember)(
                 a1: this->m_pScaleformUI,
                 a2: this->m_Radar);
  this->m_IconRotation = v7;
  if ( v7 != nullptr )
  {
    v8 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v7, a3: "IconTranslation");
    this->m_IconTranslation = v8;
    if ( v8 != nullptr )
    {
      strcpy(cHostageZoneIconName, "HZone0");
      memset(&cHostageZoneIconName[7], 0, 13);
      m_HostageZoneIcons = this->m_HostageZoneIcons;
      do
      {
        cHostageZoneIconName[5] = v4 + 48;
        *m_HostageZoneIcons = this->m_pScaleformUI->Value_GetMember(
                                this: this->m_pScaleformUI,
                                a2: this->m_IconTranslation,
                                a3: cHostageZoneIconName);
        ++v4;
        ++m_HostageZoneIcons;
      }
      while ( v4 < 4 );
      v10 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, const char *))this->m_pScaleformUI->Value_GetMember)(
                      a1: this->m_pScaleformUI,
                      a2: this->m_IconTranslation,
                      a3: "BombZoneA",
                      a4: "IconRotation");
      m_pScaleformUI = this->m_pScaleformUI;
      this->m_BombZoneIcons[0] = v10;
      this->m_BombZoneIcons[1] = m_pScaleformUI->Value_GetMember(
                                   this: m_pScaleformUI,
                                   a2: this->m_IconTranslation,
                                   a3: "BombZoneB");
LABEL_10:
      v12 = (void *)((int (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Value_GetMember)(
                      a1: this->m_pScaleformUI,
                      a2: this->m_RadarModule);
      this->m_Icons[7] = v12;
      if ( v12 != nullptr )
      {
        strcpy(hostageIconName, "HostageStatusX");
        *(_DWORD *)&hostageIconName[15] = 0;
        hostageIconName[19] = 0;
        index = 0;
        i = (int)this->m_HostageStatusIcons;
        do
        {
          v13 = this->m_pScaleformUI;
          hostageIconName[13] = index + 49;
          v14 = v13->Value_GetMember(this: v13, a2: v12, a3: hostageIconName);
          if ( v14 == nullptr )
            break;
          SFHudRadar::SFHudRadarHostageIcons::Init(
            this: (SFHudRadar::SFHudRadarHostageIcons *)i,
            scaleformui: this->m_pScaleformUI,
            iconPackage: v14);
          v15 = this->m_pScaleformUI;
          if ( v15 != nullptr )
            v15->ReleaseValue(this: v15, a2: v14);
          i += 28;
          ++index;
        }
        while ( index < 12 );
        v16 = radarIconNames[0];
        i = 0;
        if ( radarIconNames[0] != nullptr )
        {
          m_Icons = this->m_Icons;
          do
          {
            *m_Icons = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v12, a3: v16);
            v16 = radarIconNames[++i];
            ++m_Icons;
          }
          while ( v16 != nullptr );
        }
        v18 = (ISFTextObject *)((int (__thiscall *)(IScaleformUI *, void *, const char *, const char *))this->m_pScaleformUI->TextObject_MakeTextObjectFromMember)(
                                 a1: this->m_pScaleformUI,
                                 a2: v12,
                                 a3: "Location",
                                 a4: "Dashboard");
        this->m_LocationText = v18;
        if ( v18 != nullptr )
          v18->SetText(this: v18, a2: this->m_wcLocationString);
        v19 = this->m_pScaleformUI;
        Value_GetMember = v19->Value_GetMember;
        i = 0;
        v21 = Value_GetMember(this: v19, a2: v12, a3: "CurrentCash");
        if ( v21 != nullptr )
        {
          v22 = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                  this: this->m_pScaleformUI,
                  a2: v21,
                  a3: "TextBox");
          v23 = this->m_pScaleformUI;
          v24 = v23->__vftable;
          i = (int)v22;
          v24->ReleaseValue(this: v23, a2: v21);
        }
        this->m_IconsCash[0] = (ISFTextObject *)i;
        v25 = nullptr;
        v26 = (void *)((int (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Value_GetMember)(
                        a1: this->m_pScaleformUI,
                        a2: v12);
        if ( v26 != nullptr )
        {
          v25 = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                  this: this->m_pScaleformUI,
                  a2: v26,
                  a3: "TextBox");
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v26);
        }
        this->m_IconsCash[1] = v25;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D460
// Name: protected: void SFHudRadar::FlashLoadMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFHudRadar::FlashLoadMap(SFHudRadar *this@<ecx>, int a2@<edi>, char *pMapName)
{
  char *m_cDesiredMapName; // ebx
  char *v5; // eax
  void *v6; // edi
  char i; // al

  m_cDesiredMapName = pMapName;
  if ( pMapName == nullptr )
    m_cDesiredMapName = this->m_cDesiredMapName;
  if ( _V_strcmp(s1: m_cDesiredMapName, s2: this->m_cLoadedMapName) != 0 )
  {
    v5 = this->m_cDesiredMapName;
    if ( (*((_BYTE *)this + 23476) & 2) != 0 )
    {
      if ( m_cDesiredMapName != v5 )
        V_strncpy(pDest: this->m_cDesiredMapName, pSrc: m_cDesiredMapName, maxLen: 34);
      v6 = (void *)((int (__thiscall *)(IScaleformUI *, int, int))this->m_pScaleformUI->CreateValueArray)(
                     a1: this->m_pScaleformUI,
                     a2: 1,
                     a3: a2);
      this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v6, a3: 0, a4: m_cDesiredMapName);
      for ( i = 1; i != 0; i = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        this->m_pScaleformUI->Value_InvokeWithoutReturn(
          this: this->m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "loadMap",
          a4: v6,
          a5: 1u);
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      ((void (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->ReleaseValueArray)(
        a1: this->m_pScaleformUI,
        a2: v6);
    }
    else if ( m_cDesiredMapName != v5 )
    {
      V_strncpy(pDest: this->m_cDesiredMapName, pSrc: m_cDesiredMapName, maxLen: 34);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D550
// Name: protected: bool SFHudRadar::LazyCreateIconPackage(class SFHudRadar::SFHudRadarIconPackage __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SFHudRadar::LazyCreateIconPackage@<al>(
        SFHudRadar *this@<ecx>,
        int a2@<edi>,
        SFHudRadar::SFHudRadarIconPackage *pIconPack)
{
  void *v4; // edi
  void *v5; // ebx
  char i; // al

  if ( (*((_BYTE *)this + 23476) & 2) == 0
    || (*((_BYTE *)pIconPack + 208) & 1) == 0
    || pIconPack->m_IconPackage != nullptr )
  {
    return 0;
  }
  v4 = (void *)((int (__thiscall *)(IScaleformUI *, int, int))this->m_pScaleformUI->CreateValueArray)(
                 a1: this->m_pScaleformUI,
                 a2: 2,
                 a3: a2);
  this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v4, a3: 0, a4: pIconPack->m_iIndex);
  this->m_pScaleformUI->ValueArray_SetElement_5(
    this: this->m_pScaleformUI,
    a2: v4,
    a3: 1,
    a4: pIconPack->m_IconPackType);
  v5 = nullptr;
  for ( i = 1; i != 0; i = 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    v5 = this->m_pScaleformUI->Value_Invoke(
           this: this->m_pScaleformUI,
           a2: this->m_IconTranslation,
           a3: "createIconPack",
           a4: v4,
           a5: 2);
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  SFHudRadar::SFHudRadarIconPackage::Init(this: pIconPack, pui: this->m_pScaleformUI, iconPackage: v5);
  if ( v5 != nullptr )
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v5);
  ((void (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->ReleaseValueArray)(
    a1: this->m_pScaleformUI,
    a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021D650
// Name: protected: void SFHudRadar::RemoveIconPackage(class SFHudRadar::SFHudRadarIconPackage __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFHudRadar::RemoveIconPackage(
        SFHudRadar *this@<ecx>,
        int a2@<edi>,
        SFHudRadar::SFHudRadarIconPackage *pPackage)
{
  void *v4; // edi
  char i; // al

  if ( (*((_BYTE *)pPackage + 208) & 1) != 0 )
  {
    if ( (*((_BYTE *)this + 23476) & 2) != 0 && pPackage->m_IconPackage != nullptr )
    {
      v4 = (void *)((int (__thiscall *)(IScaleformUI *, int, int))this->m_pScaleformUI->CreateValueArray)(
                     a1: this->m_pScaleformUI,
                     a2: 1,
                     a3: a2);
      this->m_pScaleformUI->ValueArray_SetElement_6(
        this: this->m_pScaleformUI,
        a2: v4,
        a3: 0,
        a4: pPackage->m_IconPackage);
      for ( i = 1; i != 0; i = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        this->m_pScaleformUI->Value_InvokeWithoutReturn(
          this: this->m_pScaleformUI,
          a2: this->m_IconTranslation,
          a3: "removeIconPack",
          a4: v4,
          a5: 1u);
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      ((void (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->ReleaseValueArray)(
        a1: this->m_pScaleformUI,
        a2: v4);
    }
    SFHudRadar::SFHudRadarIconPackage::NukeFromOrbit(this: pPackage, pSFUI: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D720
// Name: protected: void SFHudRadar::RemovePlayer(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::RemovePlayer(SFHudRadar *this, int index)
{
  int m_iLastPlayerIndex; // eax
  int v4; // eax

  SFHudRadar::RemoveIconPackage(this, a2: index, pPackage: &this->m_Players[index]);
  m_iLastPlayerIndex = this->m_iLastPlayerIndex;
  if ( index == m_iLastPlayerIndex && m_iLastPlayerIndex >= 0 )
  {
    do
    {
      if ( (*((_BYTE *)&this->m_Players[this->m_iLastPlayerIndex] + 208) & 1) != 0 )
        break;
      v4 = this->m_iLastPlayerIndex - 1;
      this->m_iLastPlayerIndex = v4;
    }
    while ( v4 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D780
// Name: protected: void SFHudRadar::RemoveHostage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::RemoveHostage(SFHudRadar *this, int index)
{
  int m_iLastHostageIndex; // eax
  int v4; // eax

  SFHudRadar::RemoveIconPackage(this, a2: index, pPackage: &this->m_Hostages[index]);
  m_iLastHostageIndex = this->m_iLastHostageIndex;
  if ( index == m_iLastHostageIndex && m_iLastHostageIndex >= 0 )
  {
    do
    {
      if ( (*((_BYTE *)&this->m_Hostages[this->m_iLastHostageIndex] + 208) & 1) != 0 )
        break;
      v4 = this->m_iLastHostageIndex - 1;
      this->m_iLastHostageIndex = v4;
    }
    while ( v4 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D7E0
// Name: protected: void SFHudRadar::RemoveDecoy(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::RemoveDecoy(SFHudRadar *this, int index)
{
  int m_iLastDecoyIndex; // eax
  int v4; // eax

  SFHudRadar::RemoveIconPackage(this, a2: index, pPackage: &this->m_Decoys[index]);
  m_iLastDecoyIndex = this->m_iLastDecoyIndex;
  if ( index == m_iLastDecoyIndex && m_iLastDecoyIndex >= 0 )
  {
    do
    {
      if ( (*((_BYTE *)&this->m_Decoys[this->m_iLastDecoyIndex] + 208) & 1) != 0 )
        break;
      v4 = this->m_iLastDecoyIndex - 1;
      this->m_iLastDecoyIndex = v4;
    }
    while ( v4 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D840
// Name: public: void SFHudRadar::MsgFunc_UpdateRadar(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::MsgFunc_UpdateRadar(SFHudRadar *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v5; // edx
  int v6; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v9; // edx
  unsigned int v10; // edi
  int v11; // eax
  const unsigned int *v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ebx
  C_CSPlayer *LocalPlayer; // ebx
  IGameResources *v16; // eax
  int v17; // edi
  C_BasePlayer *v18; // eax
  C_BasePlayer *v19; // ebx
  int v20; // ecx
  unsigned int v21; // edx
  int v22; // eax
  int v23; // ecx
  const unsigned int *v24; // ecx
  const unsigned int *v25; // edx
  unsigned int v26; // edx
  const unsigned int *v27; // edi
  unsigned int v28; // eax
  int v29; // edx
  const unsigned int *v30; // ecx
  unsigned int v31; // edi
  unsigned int v32; // ebx
  int v33; // ecx
  unsigned int v34; // edx
  int v35; // eax
  int v36; // ecx
  const unsigned int *v37; // ecx
  const unsigned int *v38; // edx
  unsigned int v39; // edx
  const unsigned int *v40; // edi
  unsigned int v41; // eax
  int v42; // edx
  const unsigned int *v43; // ecx
  unsigned int v44; // edi
  unsigned int v45; // ebx
  int v46; // ecx
  unsigned int v47; // edx
  int v48; // eax
  int v49; // ecx
  const unsigned int *v50; // ecx
  const unsigned int *v51; // edx
  unsigned int v52; // edx
  const unsigned int *v53; // edi
  unsigned int v54; // eax
  int v55; // edx
  const unsigned int *v56; // ecx
  unsigned int v57; // edi
  unsigned int v58; // ebx
  int v59; // ecx
  unsigned int v60; // edx
  int v61; // eax
  int v62; // ecx
  const unsigned int *v63; // ecx
  const unsigned int *v64; // edx
  unsigned int v65; // edx
  const unsigned int *v66; // edi
  unsigned int v67; // eax
  int v68; // edx
  const unsigned int *v69; // ecx
  unsigned int v70; // edi
  unsigned int v71; // ebx
  int v72; // edi
  int v73; // ebx
  __m128i v74; // xmm1
  C_CS_PlayerResource *v75; // edi
  SFHudRadar *v76; // edi
  C_BasePlayer *v77; // eax
  C_BasePlayer *v78; // edi
  int v79; // ecx
  unsigned int v80; // eax
  int v81; // edx
  int v82; // ecx
  int v83; // ebx
  const unsigned int *v84; // eax
  const unsigned int *v85; // ecx
  int v86; // eax
  const unsigned int *v87; // ecx
  const unsigned int *v88; // edx
  unsigned int v89; // edx
  int v90; // ebx
  int v91; // eax
  float v92; // ecx
  QAngle angles; // [esp+Ch] [ebp-38h] BYREF
  Vector origin; // [esp+18h] [ebp-2Ch] BYREF
  int z; // [esp+24h] [ebp-20h]
  int a; // [esp+28h] [ebp-1Ch]
  int y; // [esp+2Ch] [ebp-18h]
  int x; // [esp+30h] [ebp-14h]
  C_CS_PlayerResource *pCSPR; // [esp+34h] [ebp-10h]
  SFHudRadar *v100; // [esp+38h] [ebp-Ch]
  C_CSPlayer *pLocalPlayer; // [esp+3Ch] [ebp-8h]
  int iPlayerEntity; // [esp+40h] [ebp-4h]
  int bOppositeTeams; // [esp+4Ch] [ebp+8h]
  char bOppositeTeams_3; // [esp+4Fh] [ebp+Bh]

  v100 = this;
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail >= 8 )
  {
    m_nInBufWord = msg->m_nInBufWord;
    v5 = (unsigned __int8)m_nInBufWord;
    v6 = m_nBitsAvail - 8;
    msg->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      msg->m_nInBufWord = m_nInBufWord >> 8;
      bOppositeTeams = (unsigned __int8)m_nInBufWord;
    }
    else
    {
      m_pDataIn = msg->m_pDataIn;
      m_pBufferEnd = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = m_pDataIn + 1;
        bOppositeTeams = v5;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          msg->m_nInBufWord = *m_pDataIn;
          msg->m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          msg->m_bOverflow = true;
          msg->m_nInBufWord = 0;
        }
        bOppositeTeams = v5;
      }
    }
    goto LABEL_19;
  }
  v9 = msg->m_pBufferEnd;
  v10 = msg->m_nInBufWord;
  v11 = 8 - m_nBitsAvail;
  v12 = msg->m_pDataIn;
  if ( v12 == v9 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v12 > v9 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_16;
    }
    msg->m_nInBufWord = *v12;
  }
  msg->m_pDataIn = v12 + 1;
LABEL_16:
  if ( msg->m_bOverflow )
  {
    v5 = 0;
    bOppositeTeams = 0;
  }
  else
  {
    v13 = msg->m_nInBufWord;
    v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v11;
    bOppositeTeams = v14 | v10;
    msg->m_nInBufWord = v13 >> v11;
    v5 = v14 | v10;
  }
LABEL_19:
  iPlayerEntity = v5;
  LocalPlayer = CClientTools::GetLocalPlayer();
  pLocalPlayer = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    v16 = GameResources();
    if ( v16 != nullptr )
    {
      pCSPR = (C_CS_PlayerResource *)&v16[-608];
      if ( v16 != (IGameResources *)2432 )
      {
        v17 = 1;
        while ( 1 )
        {
          if ( v17 != LocalPlayer->entindex(this: &LocalPlayer->IClientNetworkable) )
          {
            v18 = UTIL_PlayerByIndex(entindex: v17);
            v19 = v18;
            if ( v18 != nullptr && v18->IsPlayer(this: v18) )
              LOBYTE(v19[1].m_cellY) = 0;
          }
          if ( ++v17 > 64 )
            break;
          LocalPlayer = pLocalPlayer;
        }
        if ( bOppositeTeams > 0 )
        {
          do
          {
            v20 = msg->m_nBitsAvail;
            if ( v20 >= 13 )
            {
              v21 = msg->m_nInBufWord;
              v22 = v21 & 0x1FFF;
              v23 = v20 - 13;
              msg->m_nBitsAvail = v23;
              if ( v23 != 0 )
              {
                msg->m_nInBufWord = v21 >> 13;
              }
              else
              {
                v24 = msg->m_pDataIn;
                v25 = msg->m_pBufferEnd;
                msg->m_nBitsAvail = 32;
                if ( v24 == v25 )
                {
                  msg->m_nBitsAvail = 1;
                  msg->m_nInBufWord = 0;
                  msg->m_pDataIn = v24 + 1;
                }
                else if ( v24 <= v25 )
                {
                  v26 = *v24;
                  msg->m_pDataIn = v24 + 1;
                  msg->m_nInBufWord = v26;
                }
                else
                {
                  msg->m_bOverflow = true;
                  msg->m_nInBufWord = 0;
                }
              }
              goto LABEL_47;
            }
            v27 = msg->m_pBufferEnd;
            v28 = msg->m_nInBufWord;
            v29 = 13 - v20;
            v30 = msg->m_pDataIn;
            if ( v30 == v27 )
            {
              msg->m_nBitsAvail = 1;
              msg->m_nInBufWord = 0;
              msg->m_bOverflow = true;
            }
            else
            {
              if ( v30 > v27 )
              {
                msg->m_bOverflow = true;
                msg->m_nInBufWord = 0;
                goto LABEL_44;
              }
              msg->m_nInBufWord = *v30;
            }
            msg->m_pDataIn = v30 + 1;
LABEL_44:
            if ( msg->m_bOverflow )
            {
              v22 = 0;
            }
            else
            {
              v31 = msg->m_nInBufWord;
              v32 = (v31 & CBitBuffer::s_nMaskTable[v29]) << msg->m_nBitsAvail;
              msg->m_nBitsAvail = 32 - v29;
              v22 = v32 | v28;
              msg->m_nInBufWord = v31 >> v29;
            }
LABEL_47:
            v33 = msg->m_nBitsAvail;
            x = 4 * (v22 << 19 >> 19);
            if ( v33 >= 13 )
            {
              v34 = msg->m_nInBufWord;
              v35 = v34 & 0x1FFF;
              v36 = v33 - 13;
              msg->m_nBitsAvail = v36;
              if ( v36 != 0 )
              {
                msg->m_nInBufWord = v34 >> 13;
              }
              else
              {
                v37 = msg->m_pDataIn;
                v38 = msg->m_pBufferEnd;
                msg->m_nBitsAvail = 32;
                if ( v37 == v38 )
                {
                  msg->m_nBitsAvail = 1;
                  msg->m_nInBufWord = 0;
                  msg->m_pDataIn = v37 + 1;
                }
                else if ( v37 <= v38 )
                {
                  v39 = *v37;
                  msg->m_pDataIn = v37 + 1;
                  msg->m_nInBufWord = v39;
                }
                else
                {
                  msg->m_bOverflow = true;
                  msg->m_nInBufWord = 0;
                }
              }
              goto LABEL_64;
            }
            v40 = msg->m_pBufferEnd;
            v41 = msg->m_nInBufWord;
            v42 = 13 - v33;
            v43 = msg->m_pDataIn;
            if ( v43 == v40 )
            {
              msg->m_nBitsAvail = 1;
              msg->m_nInBufWord = 0;
              msg->m_bOverflow = true;
            }
            else
            {
              if ( v43 > v40 )
              {
                msg->m_bOverflow = true;
                msg->m_nInBufWord = 0;
                goto LABEL_61;
              }
              msg->m_nInBufWord = *v43;
            }
            msg->m_pDataIn = v43 + 1;
LABEL_61:
            if ( msg->m_bOverflow )
            {
              v35 = 0;
            }
            else
            {
              v44 = msg->m_nInBufWord;
              v45 = (v44 & CBitBuffer::s_nMaskTable[v42]) << msg->m_nBitsAvail;
              msg->m_nBitsAvail = 32 - v42;
              v35 = v45 | v41;
              msg->m_nInBufWord = v44 >> v42;
            }
LABEL_64:
            v46 = msg->m_nBitsAvail;
            y = 4 * (v35 << 19 >> 19);
            if ( v46 >= 13 )
            {
              v47 = msg->m_nInBufWord;
              v48 = v47 & 0x1FFF;
              v49 = v46 - 13;
              msg->m_nBitsAvail = v49;
              if ( v49 != 0 )
              {
                msg->m_nInBufWord = v47 >> 13;
              }
              else
              {
                v50 = msg->m_pDataIn;
                v51 = msg->m_pBufferEnd;
                msg->m_nBitsAvail = 32;
                if ( v50 == v51 )
                {
                  msg->m_nBitsAvail = 1;
                  msg->m_nInBufWord = 0;
                  msg->m_pDataIn = v50 + 1;
                }
                else if ( v50 <= v51 )
                {
                  v52 = *v50;
                  msg->m_pDataIn = v50 + 1;
                  msg->m_nInBufWord = v52;
                }
                else
                {
                  msg->m_bOverflow = true;
                  msg->m_nInBufWord = 0;
                }
              }
              goto LABEL_81;
            }
            v53 = msg->m_pBufferEnd;
            v54 = msg->m_nInBufWord;
            v55 = 13 - v46;
            v56 = msg->m_pDataIn;
            if ( v56 == v53 )
            {
              msg->m_nBitsAvail = 1;
              msg->m_nInBufWord = 0;
              msg->m_bOverflow = true;
            }
            else
            {
              if ( v56 > v53 )
              {
                msg->m_bOverflow = true;
                msg->m_nInBufWord = 0;
                goto LABEL_78;
              }
              msg->m_nInBufWord = *v56;
            }
            msg->m_pDataIn = v56 + 1;
LABEL_78:
            if ( msg->m_bOverflow )
            {
              v48 = 0;
            }
            else
            {
              v57 = msg->m_nInBufWord;
              v58 = (v57 & CBitBuffer::s_nMaskTable[v55]) << msg->m_nBitsAvail;
              msg->m_nBitsAvail = 32 - v55;
              v48 = v58 | v54;
              msg->m_nInBufWord = v57 >> v55;
            }
LABEL_81:
            v59 = msg->m_nBitsAvail;
            z = 4 * (v48 << 19 >> 19);
            if ( v59 >= 9 )
            {
              v60 = msg->m_nInBufWord;
              v61 = v60 & 0x1FF;
              v62 = v59 - 9;
              msg->m_nBitsAvail = v62;
              if ( v62 != 0 )
              {
                msg->m_nInBufWord = v60 >> 9;
              }
              else
              {
                v63 = msg->m_pDataIn;
                v64 = msg->m_pBufferEnd;
                msg->m_nBitsAvail = 32;
                if ( v63 == v64 )
                {
                  msg->m_nBitsAvail = 1;
                  msg->m_nInBufWord = 0;
                  msg->m_pDataIn = v63 + 1;
                }
                else if ( v63 <= v64 )
                {
                  v65 = *v63;
                  msg->m_pDataIn = v63 + 1;
                  msg->m_nInBufWord = v65;
                }
                else
                {
                  msg->m_bOverflow = true;
                  msg->m_nInBufWord = 0;
                }
              }
              goto LABEL_98;
            }
            v66 = msg->m_pBufferEnd;
            v67 = msg->m_nInBufWord;
            v68 = 9 - v59;
            v69 = msg->m_pDataIn;
            if ( v69 == v66 )
            {
              msg->m_nBitsAvail = 1;
              msg->m_nInBufWord = 0;
              msg->m_bOverflow = true;
            }
            else
            {
              if ( v69 > v66 )
              {
                msg->m_bOverflow = true;
                msg->m_nInBufWord = 0;
                goto LABEL_95;
              }
              msg->m_nInBufWord = *v69;
            }
            msg->m_pDataIn = v69 + 1;
LABEL_95:
            if ( msg->m_bOverflow )
            {
              v61 = 0;
            }
            else
            {
              v70 = msg->m_nInBufWord;
              v71 = (v70 & CBitBuffer::s_nMaskTable[v68]) << msg->m_nBitsAvail;
              msg->m_nBitsAvail = 32 - v68;
              v61 = v71 | v67;
              msg->m_nInBufWord = v70 >> v68;
            }
LABEL_98:
            a = v61 << 23 >> 23;
            v72 = (int)(&v100->m_fPixelToRadarScale + 53 * iPlayerEntity);
            if ( pLocalPlayer->GetTeamNumber(this: pLocalPlayer) == 0
              || (v73 = pCSPR->GetTeam(this: &pCSPR->IGameResources, a2: iPlayerEntity)) == pLocalPlayer->GetTeamNumber(this: pLocalPlayer) )
            {
              bOppositeTeams_3 = 0;
LABEL_102:
              v74 = _mm_cvtsi32_si128(a);
              *(float *)(v72 + 76) = (float)x;
              *(float *)(v72 + 80) = (float)y;
              *(float *)(v72 + 84) = (float)z;
              *(_DWORD *)(v72 + 88) = 0;
              *(_QWORD *)(v72 + 92) = _mm_cvtepi32_ps(v74).m128_u32[0];
              goto LABEL_104;
            }
            bOppositeTeams_3 = 1;
            if ( C_CS_PlayerResource::IsPlayerSpotted(this: pCSPR, iIndex: iPlayerEntity)
              || (*((_BYTE *)v100 + 23476) & 8) != 0 )
            {
              goto LABEL_102;
            }
LABEL_104:
            v75 = pCSPR;
            if ( !C_CS_PlayerResource::HasC4(this: pCSPR, iIndex: iPlayerEntity) )
            {
              v76 = v100;
              goto LABEL_112;
            }
            if ( pLocalPlayer->GetTeamNumber(this: pLocalPlayer) != 3 || C_CS_PlayerResource::IsBombSpotted(this: v75) )
            {
              v76 = v100;
LABEL_110:
              v76->m_BombPosition.x = (float)x;
              v76->m_BombPosition.y = (float)y;
              goto LABEL_112;
            }
            v76 = v100;
            if ( (*((_BYTE *)v100 + 23476) & 8) != 0 )
              goto LABEL_110;
LABEL_112:
            if ( C_CS_PlayerResource::HasDefuser(this: pCSPR, iIndex: iPlayerEntity)
              && (pLocalPlayer->GetTeamNumber(this: pLocalPlayer) != 2
               || C_CS_PlayerResource::IsDefuserSpotted(this: pCSPR)
               || (*((_BYTE *)v76 + 23476) & 8) != 0) )
            {
              v76->m_DefuserPosition.x = (float)x;
              v76->m_DefuserPosition.y = (float)y;
            }
            v77 = UTIL_PlayerByIndex(entindex: iPlayerEntity);
            v78 = v77;
            if ( v77 == nullptr || !v77->IsPlayer(this: v77) )
              v78 = nullptr;
            v79 = msg->m_nBitsAvail;
            if ( v79 < 8 )
            {
              v86 = 8 - v79;
              v87 = msg->m_pDataIn;
              iPlayerEntity = msg->m_nInBufWord;
              v88 = msg->m_pBufferEnd;
              if ( v87 == v88 )
              {
                msg->m_nBitsAvail = 1;
                msg->m_nInBufWord = 0;
                msg->m_bOverflow = true;
                goto LABEL_134;
              }
              if ( v87 <= v88 )
              {
                msg->m_nInBufWord = *v87;
LABEL_134:
                msg->m_pDataIn = v87 + 1;
              }
              else
              {
                msg->m_bOverflow = true;
                msg->m_nInBufWord = 0;
              }
              if ( msg->m_bOverflow )
              {
                v83 = 0;
              }
              else
              {
                v89 = msg->m_nInBufWord;
                v90 = (v89 & CBitBuffer::s_nMaskTable[v86]) << msg->m_nBitsAvail;
                msg->m_nBitsAvail = 32 - v86;
                z = v90;
                v83 = v90 | iPlayerEntity;
                msg->m_nInBufWord = v89 >> v86;
              }
              goto LABEL_138;
            }
            v80 = msg->m_nInBufWord;
            v81 = (unsigned __int8)v80;
            v82 = v79 - 8;
            msg->m_nBitsAvail = v82;
            if ( v82 != 0 )
            {
              msg->m_nInBufWord = v80 >> 8;
              v83 = (unsigned __int8)v80;
            }
            else
            {
              v84 = msg->m_pDataIn;
              v85 = msg->m_pBufferEnd;
              msg->m_nBitsAvail = 32;
              if ( v84 == v85 )
              {
                msg->m_nInBufWord = 0;
                msg->m_nBitsAvail = 1;
                msg->m_pDataIn = v84 + 1;
                v83 = v81;
              }
              else
              {
                if ( v84 <= v85 )
                {
                  msg->m_nInBufWord = *v84;
                  msg->m_pDataIn = v84 + 1;
                }
                else
                {
                  msg->m_nInBufWord = 0;
                  msg->m_bOverflow = true;
                }
                v83 = v81;
              }
            }
LABEL_138:
            iPlayerEntity = v83;
            if ( v78 != nullptr
              && v78->IsDormant(this: &v78->IClientNetworkable)
              && (bOppositeTeams_3 == 0 || pLocalPlayer->GetObserverMode(this: pLocalPlayer) != 0) )
            {
              origin = *v78->GetAbsOrigin(this: v78);
              v91 = (int)v78->GetAbsAngles(this: v78);
              *(_QWORD *)&angles.x = *(_QWORD *)v91;
              v92 = *(float *)(v91 + 8);
              origin.x = (float)x;
              origin.y = (float)y;
              angles.z = v92;
              angles.y = (float)a;
              C_BaseEntity::SetAbsOrigin(this: v78, absOrigin: &origin);
              C_BaseEntity::SetAbsAngles(this: v78, absAngles: &angles);
              LOBYTE(v78[1].m_cellY) = 1;
            }
          }
          while ( v83 > 0 );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021E070
// Name: protected: void SFHudRadar::SetLocationText(wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SetLocationText(SFHudRadar *this, wchar_t *newText)
{
  const wchar_t *v2; // ebx
  char i; // al

  v2 = newText;
  if ( newText == nullptr )
    v2 = &szFunFact;
  if ( _V_wcscmp(s1: v2, s2: this->m_wcLocationString) != 0 )
  {
    V_wcsncpy(pDest: this->m_wcLocationString, pSrc: v2, maxLenInBytes: 0xC8u);
    if ( this->m_LocationText != nullptr )
    {
      for ( i = 1; i != 0; i = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        this->m_LocationText->SetText(this: this->m_LocationText, a2: this->m_wcLocationString);
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021E100
// Name: protected: void SFHudRadar::PositionRadarViewpoint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::PositionRadarViewpoint(SFHudRadar *this)
{
  C_BasePlayer *LocalPlayer; // eax
  const Vector *LocalOrigin; // eax
  float v4; // xmm1_4
  void *m_MapRotation; // eax
  float v6; // xmm0_4
  IScaleformUI *m_pScaleformUI; // ecx
  void *m_MapTranslation; // eax
  IScaleformUI *v9; // ecx
  long double v10; // xmm0_8
  void *m_IconRotation; // eax
  float m_RadarRotation; // xmm0_4
  IScaleformUI *v13; // ecx
  void *m_IconTranslation; // eax
  IScaleformUI *v15; // ecx
  long double v16; // xmm0_8
  ScaleformDisplayInfo displayInfo; // [esp+4h] [ebp-38h] BYREF

  if ( (*((_BYTE *)this + 23476) & 2) != 0 )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( (LocalPlayer != nullptr || (LocalPlayer = GetSplitScreenViewPlayer(nSlot: 0)) != nullptr)
      && this->m_iObserverMode == 0 )
    {
      LocalOrigin = C_BaseEntity::GetLocalOrigin(this: LocalPlayer);
    }
    else
    {
      LocalOrigin = MainViewOrigin(nSlot: 0);
    }
    this->m_RadarViewpointWorld.x = LocalOrigin->x;
    this->m_RadarViewpointWorld.y = LocalOrigin->y;
    this->m_RadarViewpointWorld.z = LocalOrigin->z;
    this->m_RadarRotation = MainViewAngles(nSlot: 0)->y;
    this->m_RadarViewpointWorld.z = 0.0;
    this->m_RadarViewpointMap.x = (float)(this->m_RadarViewpointWorld.x - this->m_MapOrigin.x)
                                * this->m_fWorldToRadarScale;
    v4 = (float)(this->m_MapOrigin.y - this->m_RadarViewpointWorld.y) * this->m_fWorldToRadarScale;
    this->m_RadarViewpointMap.z = 0.0;
    this->m_RadarViewpointMap.y = v4;
    m_MapRotation = this->m_MapRotation;
    v6 = this->m_RadarRotation - 90.0;
    this->m_RadarRotation = v6;
    displayInfo.m_iSetFlags = 0;
    if ( m_MapRotation != nullptr )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      displayInfo.m_iSetFlags = 4;
      displayInfo.m_fRotation = v6;
      m_pScaleformUI->Value_SetDisplayInfo(this: m_pScaleformUI, a2: m_MapRotation, a3: &displayInfo);
      m_MapTranslation = this->m_MapTranslation;
      if ( m_MapTranslation != nullptr )
      {
        v9 = this->m_pScaleformUI;
        displayInfo.m_fX = COERCE_FLOAT(LODWORD(this->m_RadarViewpointMap.x) ^ _mask__NegFloat_);
        v10 = COERCE_FLOAT(LODWORD(this->m_RadarViewpointMap.y) ^ _mask__NegFloat_);
        displayInfo.m_iSetFlags = 3;
        displayInfo.m_fY = v10;
        v9->Value_SetDisplayInfo(this: v9, a2: m_MapTranslation, a3: &displayInfo);
      }
    }
    m_IconRotation = this->m_IconRotation;
    if ( m_IconRotation != nullptr )
    {
      m_RadarRotation = this->m_RadarRotation;
      v13 = this->m_pScaleformUI;
      displayInfo.m_iSetFlags = 4;
      displayInfo.m_fRotation = m_RadarRotation;
      v13->Value_SetDisplayInfo(this: v13, a2: m_IconRotation, a3: &displayInfo);
      m_IconTranslation = this->m_IconTranslation;
      if ( m_IconTranslation != nullptr )
      {
        v15 = this->m_pScaleformUI;
        displayInfo.m_fX = COERCE_FLOAT(LODWORD(this->m_RadarViewpointMap.x) ^ _mask__NegFloat_);
        v16 = COERCE_FLOAT(LODWORD(this->m_RadarViewpointMap.y) ^ _mask__NegFloat_);
        displayInfo.m_iSetFlags = 3;
        displayInfo.m_fY = v16;
        v15->Value_SetDisplayInfo(this: v15, a2: m_IconTranslation, a3: &displayInfo);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021E2C0
// Name: protected: void SFHudRadar::PlaceGoalIcons(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::PlaceGoalIcons(SFHudRadar *this)
{
  IGameResources *v2; // eax
  int m_iSetFlags; // eax
  SFHudRadar::SFHudRadarGoalIcon *m_GoalIcons; // edi
  void *m_Icon; // edx
  float v6; // xmm0_4
  float v7; // xmm5_4
  float x; // xmm6_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm3_4
  IScaleformUI *m_pScaleformUI; // ecx
  long double v15; // xmm0_8
  ScaleformDisplayInfo displayInfo; // [esp+4h] [ebp-54h] BYREF
  Vector newMapPosition; // [esp+3Ch] [ebp-1Ch]
  Vector mapPosition; // [esp+48h] [ebp-10h]
  int i; // [esp+54h] [ebp-4h]

  v2 = GameResources();
  if ( v2 != nullptr && v2 != (IGameResources *)2432 )
  {
    m_iSetFlags = 0;
    m_GoalIcons = this->m_GoalIcons;
    for ( i = 0; i < this->m_iNumGoalIcons; ++i )
    {
      m_Icon = m_GoalIcons->m_Icon;
      v6 = (float)(m_GoalIcons->m_Position.x - this->m_MapOrigin.x) * this->m_fWorldToRadarScale;
      v7 = (float)(this->m_MapOrigin.y - m_GoalIcons->m_Position.y) * this->m_fWorldToRadarScale;
      mapPosition.x = v6;
      mapPosition.y = v7;
      mapPosition.z = 0.0;
      if ( m_Icon != nullptr )
      {
        x = this->m_RadarViewpointMap.x;
        *(_QWORD *)&newMapPosition.x = *(_QWORD *)&mapPosition.x;
        v9 = mapPosition.y - this->m_RadarViewpointMap.y;
        v10 = v6 - x;
        newMapPosition.z = mapPosition.z;
        v11 = mapPosition.z - this->m_RadarViewpointMap.z;
        v12 = (float)((float)(v9 * v9) + (float)(v10 * v10)) + (float)(v11 * v11);
        if ( v12 > 3364.0 )
        {
          v13 = fsqrt(3364.0 / v12);
          v6 = (float)(v13 * v10) + x;
          v7 = (float)(v9 * v13) + this->m_RadarViewpointMap.y;
          mapPosition.z = (float)(v11 * v13) + this->m_RadarViewpointMap.z;
        }
        m_pScaleformUI = this->m_pScaleformUI;
        displayInfo.m_fX = v6;
        displayInfo.m_fY = v7;
        v15 = COERCE_FLOAT(LODWORD(this->m_RadarRotation) ^ _mask__NegFloat_);
        displayInfo.m_iSetFlags = m_iSetFlags | 7;
        displayInfo.m_fRotation = v15;
        m_pScaleformUI->Value_SetDisplayInfo(this: m_pScaleformUI, a2: m_Icon, a3: &displayInfo);
        m_iSetFlags = displayInfo.m_iSetFlags;
      }
      ++m_GoalIcons;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021E430
// Name: protected: void SFHudRadar::ApplySpectatorModes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::ApplySpectatorModes(SFHudRadar *this)
{
  C_CSPlayer *LocalPlayer; // eax
  ConVarRef mp_forcecamera; // [esp+4h] [ebp-8h] BYREF

  LocalPlayer = CClientTools::GetLocalPlayer();
  *((_BYTE *)this + 23476) &= ~8u;
  this->m_iObserverMode = 0;
  if ( LocalPlayer != nullptr )
    this->m_iObserverMode = LocalPlayer->GetObserverMode(this: LocalPlayer);
  if ( this->m_iObserverMode != 0 )
  {
    ConVarRef::ConVarRef(this: &mp_forcecamera, pName: "mp_forcecamera");
    *((_BYTE *)this + 23476) ^= (*((_BYTE *)this + 23476)
                               ^ (8 * (mp_forcecamera.m_pConVarState->m_Value.m_nValue == 0)))
                              & 8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021E4A0
// Name: void __MsgFunc_SFHudRadar_UpdateRadar(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_SFHudRadar_UpdateRadar(bf_read *msg)
{
  CHud *Hud; // eax
  SFHudRadar *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = (SFHudRadar *)CHud::FindElement(this: Hud, pName: "SFHudRadar");
  if ( Element != nullptr )
    SFHudRadar::MsgFunc_UpdateRadar(this: Element, msg);
}

//------------------------------------------------------------------------------
// Address: 0x1021E4D0
// Name: public: void SFHudRadar::SFHudRadarIconPackage::StartRound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SFHudRadarIconPackage::StartRound(SFHudRadar::SFHudRadarIconPackage *this)
{
  void *m_IconPackage; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  char v4; // [esp+0h] [ebp-38h] BYREF
  __int64 v5; // [esp+18h] [ebp-20h]
  int v6; // [esp+30h] [ebp-8h]

  *((_BYTE *)this + 208) &= 0x2Du;
  this->m_fGhostTime = -1000.0;
  this->m_fDeadTime = -1000.0;
  this->m_Health = 100;
  this->m_fRoundStartTime = *(float *)(gpGlobals.m_Index + 12);
  this->m_Position = vec3_origin;
  this->m_Angle.x = 0.0;
  this->m_Angle.y = 0.0;
  this->m_Angle.z = 0.0;
  if ( this->m_fCurrentAlpha != 0.0 )
  {
    m_IconPackage = this->m_IconPackage;
    this->m_fCurrentAlpha = 0.0;
    if ( m_IconPackage != nullptr )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      v6 = 8;
      v5 = 0;
      m_pScaleformUI->Value_SetDisplayInfo(
        this: m_pScaleformUI,
        a2: m_IconPackage,
        a3: (const ScaleformDisplayInfo *)&v4);
    }
  }
  SFHudRadar::SFHudRadarIconPackage::SetVisibilityFlags(this, newFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1021E590
// Name: public: void SFHudRadar::SFHudRadarIconPackage::SetupIconsFromStates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SFHudRadarIconPackage::SetupIconsFromStates(SFHudRadar::SFHudRadarIconPackage *this)
{
  int m_iPlayerType; // ecx
  int v3; // edi
  float v4; // xmm0_4
  char v5; // cl
  float v6; // xmm1_4
  float v7; // xmm1_4
  void *m_IconPackage; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  char v10; // [esp+0h] [ebp-38h] BYREF
  double v11; // [esp+18h] [ebp-20h]
  int v12; // [esp+30h] [ebp-8h]

  m_iPlayerType = this->m_iPlayerType;
  v3 = 0;
  v4 = 1.0;
  if ( m_iPlayerType != 0 )
  {
    v3 = 1 << m_iPlayerType;
    v5 = *((_BYTE *)this + 208);
    if ( (v5 & 0x10) != 0 )
    {
      if ( this->m_Position.x == 0.0 && this->m_Position.y == 0.0 )
      {
        v3 = 0;
      }
      else
      {
        v6 = *(float *)(gpGlobals.m_Index + 12) - this->m_fDeadTime;
        if ( v6 <= 4.0 )
        {
          v4 = 1.0 - (float)(v6 * 0.25);
          if ( v4 >= 0.0 )
          {
            if ( v4 > 1.0 )
              v4 = 1.0;
          }
          else
          {
            v4 = 0.0;
          }
          if ( this->m_IconPackType != ICON_PACK_HOSTAGE || v5 >= 0 )
            v3 *= 4;
        }
        else
        {
          this->m_fDeadTime = -1000.0;
          v3 = 0;
        }
      }
    }
    else if ( (v5 & 0x40) != 0 )
    {
      if ( (v5 & 0x20) != 0 )
        v3 |= 8u;
      if ( (v5 & 8) != 0 )
        v3 |= 2u;
      if ( (v5 & 2) != 0 )
        v3 *= 2;
      if ( (v5 & 4) != 0 )
        v3 |= 1u;
    }
    else
    {
      v7 = *(float *)(gpGlobals.m_Index + 12) - this->m_fGhostTime;
      if ( v7 <= 6.0 )
      {
        v4 = 1.0 - (float)(v7 * 0.16666667);
        if ( v4 >= 0.0 )
        {
          if ( v4 > 1.0 )
            v4 = 1.0;
        }
        else
        {
          v4 = 0.0;
        }
      }
      else
      {
        this->m_fGhostTime = -1000.0;
        v3 = 0;
      }
      v3 *= 2;
      if ( (v5 & 2) == 0 )
        v3 *= 4;
    }
  }
  if ( v4 != this->m_fCurrentAlpha )
  {
    m_IconPackage = this->m_IconPackage;
    this->m_fCurrentAlpha = v4;
    if ( m_IconPackage != nullptr )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      v12 = 8;
      v11 = (float)(v4 * 100.0);
      m_pScaleformUI->Value_SetDisplayInfo(
        this: m_pScaleformUI,
        a2: m_IconPackage,
        a3: (const ScaleformDisplayInfo *)&v10);
    }
  }
  SFHudRadar::SFHudRadarIconPackage::SetVisibilityFlags(this, newFlags: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1021E730
// Name: public: virtual void SFHudRadar::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::LevelShutdown(SFHudRadar *this)
{
  if ( (*((_BYTE *)this + 23476) & 3) != 0 && this->m_bFlashAPIIsValid )
    this->m_pScaleformUI->RemoveElement(this: this->m_pScaleformUI, a2: this->m_iFlashSlot, a3: this->m_FlashAPI);
}

//------------------------------------------------------------------------------
// Address: 0x1021E760
// Name: public: virtual bool SFHudRadar::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SFHudRadar::ShouldDraw(SFHudRadar *this)
{
  C_CSPlayer *LocalPlayer; // eax

  LocalPlayer = CClientTools::GetLocalPlayer();
  return (*((_BYTE *)this + 23476) & 4) != 0
      && LocalPlayer != nullptr
      && cl_drawhud.m_pParent != nullptr
      && cl_drawhud.m_pParent->m_Value.m_nValue != 0
      && CHudElement::ShouldDraw(this) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021E7A0
// Name: public: virtual void SFHudRadar::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SetActive(SFHudRadar *this, bool bActive)
{
  SFHudRadar::Show(this, show: bActive);
  CHudElement::SetActive(this, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x1021E7C0
// Name: public: virtual bool SFHudRadar::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFHudRadar::PreUnloadFlash(SFHudRadar *this)
{
  void *m_IconTranslation; // eax
  void **m_BombZoneIcons; // edi
  int i; // ebx
  IScaleformUI *m_pScaleformUI; // ecx
  void **m_HostageZoneIcons; // edi
  int j; // ebx
  IScaleformUI *v8; // ecx
  int m_iLastPlayerIndex; // edi
  int v10; // eax
  int v11; // eax
  int m_iLastHostageIndex; // edi
  int v13; // eax
  int v14; // eax
  IScaleformUI *v15; // ecx
  IScaleformUI *v16; // ecx
  IScaleformUI *v17; // ecx
  IScaleformUI *v18; // ecx
  IScaleformUI *v19; // ecx
  IScaleformUI *v20; // ecx
  char k; // al
  IScaleformUI *v22; // ecx
  ISFTextObject **m_IconsCash; // edi
  int m; // ebx
  char n; // al
  IScaleformUI *v26; // ecx
  int v27; // edi
  SFHudRadar *v28; // eax
  void **m_Icons; // edi
  int ii; // ebx
  IScaleformUI *v31; // ecx

  m_IconTranslation = this->m_IconTranslation;
  if ( m_IconTranslation != nullptr )
  {
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: m_IconTranslation,
      a3: "removeBombPack",
      a4: nullptr,
      a5: 0);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_IconTranslation,
      a3: "removeDefuserPack",
      a4: nullptr,
      a5: 0);
  }
  m_BombZoneIcons = this->m_BombZoneIcons;
  for ( i = 2; i != 0; --i )
  {
    m_pScaleformUI = this->m_pScaleformUI;
    if ( m_pScaleformUI != nullptr && *m_BombZoneIcons != nullptr )
    {
      m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: *m_BombZoneIcons);
      *m_BombZoneIcons = nullptr;
    }
    ++m_BombZoneIcons;
  }
  m_HostageZoneIcons = this->m_HostageZoneIcons;
  for ( j = 4; j != 0; --j )
  {
    v8 = this->m_pScaleformUI;
    if ( v8 != nullptr && *m_HostageZoneIcons != nullptr )
    {
      v8->ReleaseValue(this: v8, a2: *m_HostageZoneIcons);
      *m_HostageZoneIcons = nullptr;
    }
    ++m_HostageZoneIcons;
  }
  while ( this->m_iLastPlayerIndex >= 0 )
  {
    m_iLastPlayerIndex = this->m_iLastPlayerIndex;
    SFHudRadar::RemoveIconPackage(this, a2: m_iLastPlayerIndex, pPackage: &this->m_Players[m_iLastPlayerIndex]);
    v10 = this->m_iLastPlayerIndex;
    if ( m_iLastPlayerIndex == v10 && v10 >= 0 )
    {
      while ( (*((_BYTE *)&this->m_Players[this->m_iLastPlayerIndex] + 208) & 1) == 0 )
      {
        v11 = this->m_iLastPlayerIndex - 1;
        this->m_iLastPlayerIndex = v11;
        if ( v11 < 0 )
          goto LABEL_20;
      }
    }
  }
LABEL_20:
  while ( this->m_iLastHostageIndex >= 0 )
  {
    m_iLastHostageIndex = this->m_iLastHostageIndex;
    SFHudRadar::RemoveIconPackage(this, a2: m_iLastHostageIndex, pPackage: &this->m_Hostages[m_iLastHostageIndex]);
    v13 = this->m_iLastHostageIndex;
    if ( m_iLastHostageIndex == v13 && v13 >= 0 )
    {
      while ( (*((_BYTE *)&this->m_Hostages[this->m_iLastHostageIndex] + 208) & 1) == 0 )
      {
        v14 = this->m_iLastHostageIndex - 1;
        this->m_iLastHostageIndex = v14;
        if ( v14 < 0 )
          goto LABEL_27;
      }
    }
  }
LABEL_27:
  v15 = this->m_pScaleformUI;
  if ( v15 != nullptr && this->m_MapRotation != nullptr )
  {
    v15->ReleaseValue(this: v15, a2: this->m_MapRotation);
    this->m_MapRotation = nullptr;
  }
  v16 = this->m_pScaleformUI;
  if ( v16 != nullptr && this->m_MapTranslation != nullptr )
  {
    v16->ReleaseValue(this: v16, a2: this->m_MapTranslation);
    this->m_MapTranslation = nullptr;
  }
  v17 = this->m_pScaleformUI;
  if ( v17 != nullptr && this->m_RadarModule != nullptr )
  {
    v17->ReleaseValue(this: v17, a2: this->m_RadarModule);
    this->m_RadarModule = nullptr;
  }
  v18 = this->m_pScaleformUI;
  if ( v18 != nullptr && this->m_Radar != nullptr )
  {
    v18->ReleaseValue(this: v18, a2: this->m_Radar);
    this->m_Radar = nullptr;
  }
  v19 = this->m_pScaleformUI;
  if ( v19 != nullptr && this->m_IconTranslation != nullptr )
  {
    v19->ReleaseValue(this: v19, a2: this->m_IconTranslation);
    this->m_IconTranslation = nullptr;
  }
  v20 = this->m_pScaleformUI;
  if ( v20 != nullptr && this->m_IconRotation != nullptr )
  {
    v20->ReleaseValue(this: v20, a2: this->m_IconRotation);
    this->m_IconRotation = nullptr;
  }
  if ( this->m_LocationText != nullptr )
  {
    for ( k = 1; ; k = 0 )
    {
      v22 = this->m_pScaleformUI;
      if ( k == 0 )
        break;
      if ( v22 != nullptr )
        v22->LockSlot(this: v22, a2: this->m_iFlashSlot);
      this->m_LocationText->Release(this: this->m_LocationText);
    }
    if ( v22 != nullptr )
      v22->UnlockSlot(this: v22, a2: this->m_iFlashSlot);
    this->m_LocationText = nullptr;
  }
  m_IconsCash = this->m_IconsCash;
  for ( m = 2; m != 0; --m )
  {
    if ( *m_IconsCash != nullptr )
    {
      for ( n = 1; ; n = 0 )
      {
        v26 = this->m_pScaleformUI;
        if ( n == 0 )
          break;
        if ( v26 != nullptr )
          v26->LockSlot(this: v26, a2: this->m_iFlashSlot);
        (*m_IconsCash)->Release(this: *m_IconsCash);
      }
      if ( v26 != nullptr )
        v26->UnlockSlot(this: v26, a2: this->m_iFlashSlot);
      *m_IconsCash = nullptr;
    }
    ++m_IconsCash;
  }
  v27 = 0;
  if ( this->m_HostageStatusIcons[0].m_IconPackage != nullptr )
  {
    v28 = this;
    do
    {
      ++v27;
      SFHudRadar::SFHudRadarHostageIcons::ReleaseHandles(this: v28->m_HostageStatusIcons, pradar: this);
      v28 = (SFHudRadar *)((char *)this + 28 * v27);
    }
    while ( v28->m_HostageStatusIcons[0].m_IconPackage != nullptr );
  }
  m_Icons = this->m_Icons;
  for ( ii = 13; ii != 0; --ii )
  {
    v31 = this->m_pScaleformUI;
    if ( v31 != nullptr && *m_Icons != nullptr )
    {
      v31->ReleaseValue(this: v31, a2: *m_Icons);
      *m_Icons = nullptr;
    }
    ++m_Icons;
  }
  *((_BYTE *)this + 23476) &= ~2u;
  this->m_cDesiredMapName[0] = 0;
  this->m_cLoadedMapName[0] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021EB40
// Name: protected: void SFHudRadar::SetMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFHudRadar::SetMap(SFHudRadar *this@<ecx>, int a2@<edi>, char *pMapName)
{
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  IBaseFileSystem *v6; // eax
  double v7; // st7
  char tempfile[260]; // [esp+10h] [ebp-104h] BYREF

  SFHudRadar::FlashLoadMap(this, a2, pMapName);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: pMapName);
  else
    v5 = nullptr;
  V_snprintf(pDest: tempfile, maxLen: 0x104u, pFormat: "resource/overviews/%s.txt", pMapName);
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v5,
         filesystem: v6,
         resourceName: tempfile,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    this->m_MapOrigin.x = (float)KeyValues::GetInt(this: v5, keyName: "pos_x", defaultValue: 0);
    this->m_MapOrigin.y = (float)KeyValues::GetInt(this: v5, keyName: "pos_y", defaultValue: 0);
    this->m_MapOrigin.z = 0.0;
    v7 = 1.0 / KeyValues::GetFloat(this: v5, keyName: "scale", defaultValue: 1.0);
    this->m_fWorldToPixelScale = v7;
    this->m_fWorldToRadarScale = v7 * this->m_fPixelToRadarScale;
    KeyValues::deleteThis(this: v5);
  }
  else
  {
    _DevMsg(a1: 1, a2: "Error! CMapOverview::SetMap: couldn't load file %s.\n");
    this->m_MapOrigin.x = 0.0;
    this->m_MapOrigin.y = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021EC60
// Name: protected: bool SFHudRadar::LazyUpdateIconArray(class SFHudRadar::SFHudRadarIconPackage __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SFHudRadar::LazyUpdateIconArray@<al>(
        SFHudRadar *this@<ecx>,
        int a2@<ebx>,
        void *a3@<edi>,
        SFHudRadar::SFHudRadarIconPackage *pArray,
        int lastIndex)
{
  void **p_m_IconPackage; // ebx
  SFHudRadar::SFHudRadarIconPackage *v7; // eax
  void *v8; // edi
  void *v9; // ebx
  char i; // al
  bool v11; // zf
  bool v15; // [esp+7h] [ebp-1h]
  SFHudRadar::SFHudRadarIconPackage *pArraya; // [esp+10h] [ebp+8h]
  void **lastIndexa; // [esp+14h] [ebp+Ch]

  v15 = true;
  if ( lastIndex < 0 )
    return 1;
  p_m_IconPackage = &pArray->m_IconPackage;
  v7 = (SFHudRadar::SFHudRadarIconPackage *)(lastIndex + 1);
  lastIndexa = &pArray->m_IconPackage;
  pArraya = v7;
  do
  {
    if ( ((_BYTE)p_m_IconPackage[51] & 1) != 0 && *p_m_IconPackage == nullptr )
    {
      if ( (*((_BYTE *)this + 23476) & 2) != 0 )
      {
        v8 = (void *)((int (__thiscall *)(IScaleformUI *, int, void *, int))this->m_pScaleformUI->CreateValueArray)(
                       a1: this->m_pScaleformUI,
                       a2: 2,
                       a3,
                       a4: a2);
        this->m_pScaleformUI->ValueArray_SetElement_5(
          this: this->m_pScaleformUI,
          a2: v8,
          a3: 0,
          a4: (int)p_m_IconPackage[29]);
        this->m_pScaleformUI->ValueArray_SetElement_5(
          this: this->m_pScaleformUI,
          a2: v8,
          a3: 1,
          a4: (int)p_m_IconPackage[50]);
        v9 = nullptr;
        for ( i = 1; i != 0; i = 0 )
        {
          if ( this->m_pScaleformUI != nullptr )
            this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
          v9 = this->m_pScaleformUI->Value_Invoke(
                 this: this->m_pScaleformUI,
                 a2: this->m_IconTranslation,
                 a3: "createIconPack",
                 a4: v8,
                 a5: 2);
        }
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        SFHudRadar::SFHudRadarIconPackage::Init(
          this: (SFHudRadar::SFHudRadarIconPackage *)(lastIndexa - 1),
          pui: this->m_pScaleformUI,
          iconPackage: v9);
        if ( v9 != nullptr )
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v9);
        a2 = 2;
        a3 = v8;
        ((void (__thiscall *)(IScaleformUI *))this->m_pScaleformUI->ReleaseValueArray)(a1: this->m_pScaleformUI);
        p_m_IconPackage = lastIndexa;
      }
      else
      {
        v15 = false;
      }
    }
    p_m_IconPackage += 53;
    v11 = pArraya == (SFHudRadar::SFHudRadarIconPackage *)1;
    pArraya = (SFHudRadar::SFHudRadarIconPackage *)((char *)pArraya - 1);
    lastIndexa = p_m_IconPackage;
  }
  while ( !v11 );
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x1021EDB0
// Name: protected: void SFHudRadar::LazyCreatePlayerIcons(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudRadar::LazyCreatePlayerIcons(SFHudRadar *this@<ecx>, int a2@<ebx>, void *a3@<edi>)
{
  char v4; // al
  char updated; // al
  bool v6; // al
  int m_iLastHostageIndex; // [esp-4h] [ebp-8h]
  int m_iLastDecoyIndex; // [esp-4h] [ebp-8h]

  v4 = *((_BYTE *)this + 23476);
  if ( (v4 & 2) != 0 && (v4 & 0x20) == 0 )
  {
    updated = SFHudRadar::LazyUpdateIconArray(
                this,
                a2,
                a3,
                pArray: this->m_Players,
                lastIndex: this->m_iLastPlayerIndex);
    m_iLastHostageIndex = this->m_iLastHostageIndex;
    *((_BYTE *)this + 23476) ^= (*((_BYTE *)this + 23476) ^ (32 * updated)) & 0x20;
    v6 = SFHudRadar::LazyUpdateIconArray(this, a2, a3, pArray: this->m_Hostages, lastIndex: m_iLastHostageIndex) != 0
      && (*((_BYTE *)this + 23476) & 0x20) != 0;
    m_iLastDecoyIndex = this->m_iLastDecoyIndex;
    *((_BYTE *)this + 23476) ^= (*((_BYTE *)this + 23476) ^ (32 * v6)) & 0x20;
    if ( SFHudRadar::LazyUpdateIconArray(this, a2, a3, pArray: this->m_Decoys, lastIndex: m_iLastDecoyIndex) != 0
      && (*((_BYTE *)this + 23476) & 0x20) != 0 )
    {
      *((_BYTE *)this + 23476) ^= (*((_BYTE *)this + 23476) ^ 0x20) & 0x20;
    }
    else
    {
      *((_BYTE *)this + 23476) ^= *((_BYTE *)this + 23476) & 0x20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021EE80
// Name: protected: class SFHudRadar::SFHudRadarIconPackage __near * SFHudRadar::CreatePlayer(int)
// Source: json
//------------------------------------------------------------------------------
SFHudRadar::SFHudRadarIconPackage *__thiscall SFHudRadar::CreatePlayer(SFHudRadar *this, int index)
{
  SFHudRadar::SFHudRadarIconPackage *v3; // esi
  int m_iLastPlayerIndex; // eax

  v3 = &this->m_Players[index];
  if ( (*((_BYTE *)&this->m_Players[index] + 208) & 1) != 0 )
    SFHudRadar::RemoveIconPackage(this, a2: (int)this, pPackage: &this->m_Players[index]);
  *((_BYTE *)v3 + 208) |= 1u;
  v3->m_IconPackType = ICON_PACK_PLAYER;
  v3->m_iIndex = index;
  SFHudRadar::SFHudRadarIconPackage::StartRound(this: v3);
  if ( v3->m_IconPackage == nullptr && SFHudRadar::LazyCreateIconPackage(this, a2: (int)this, pIconPack: v3) == 0 )
    *((_BYTE *)this + 23476) &= ~0x20u;
  m_iLastPlayerIndex = this->m_iLastPlayerIndex;
  if ( index <= m_iLastPlayerIndex )
    this->m_iLastPlayerIndex = m_iLastPlayerIndex;
  else
    this->m_iLastPlayerIndex = index;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1021EF10
// Name: protected: class SFHudRadar::SFHudRadarIconPackage __near * SFHudRadar::CreateHostage(int)
// Source: json
//------------------------------------------------------------------------------
SFHudRadar::SFHudRadarIconPackage *__thiscall SFHudRadar::CreateHostage(SFHudRadar *this, int index)
{
  SFHudRadar::SFHudRadarIconPackage *v3; // esi
  int m_iLastHostageIndex; // eax

  v3 = &this->m_Hostages[index];
  if ( (*((_BYTE *)&this->m_Hostages[index] + 208) & 1) != 0 )
    SFHudRadar::RemoveIconPackage(this, a2: (int)this, pPackage: &this->m_Hostages[index]);
  *((_BYTE *)v3 + 208) |= 1u;
  v3->m_IconPackType = ICON_PACK_HOSTAGE;
  v3->m_iIndex = index;
  SFHudRadar::SFHudRadarIconPackage::StartRound(this: v3);
  if ( v3->m_IconPackage == nullptr && SFHudRadar::LazyCreateIconPackage(this, a2: (int)this, pIconPack: v3) == 0 )
    *((_BYTE *)this + 23476) &= ~0x20u;
  m_iLastHostageIndex = this->m_iLastHostageIndex;
  if ( index <= m_iLastHostageIndex )
    this->m_iLastHostageIndex = m_iLastHostageIndex;
  else
    this->m_iLastHostageIndex = index;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1021EFA0
// Name: protected: class SFHudRadar::SFHudRadarIconPackage __near * SFHudRadar::CreateDecoy(int)
// Source: json
//------------------------------------------------------------------------------
SFHudRadar::SFHudRadarIconPackage *__thiscall SFHudRadar::CreateDecoy(SFHudRadar *this, int entityID)
{
  int m_iLastDecoyIndex; // edx
  SFHudRadar::SFHudRadarIconPackage *result; // eax
  int v5; // ebx
  int v6; // ecx
  _BYTE *v7; // edx
  SFHudRadar::SFHudRadarIconPackage *v8; // esi
  char v9; // cl
  void *m_IconPackage; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  int v12; // eax
  char v13; // [esp+8h] [ebp-3Ch] BYREF
  __int64 v14; // [esp+20h] [ebp-24h]
  int v15; // [esp+38h] [ebp-Ch]
  int index; // [esp+40h] [ebp-4h]

  m_iLastDecoyIndex = this->m_iLastDecoyIndex;
  result = nullptr;
  v5 = m_iLastDecoyIndex + 1;
  v6 = 0;
  index = m_iLastDecoyIndex + 1;
  if ( m_iLastDecoyIndex >= 0 )
  {
    v7 = (char *)this->m_Decoys + 208;
    while ( (*v7 & 1) != 0 )
    {
      ++v6;
      v7 += 212;
      if ( v6 > this->m_iLastDecoyIndex )
        goto LABEL_7;
    }
    v5 = v6;
    index = v6;
  }
LABEL_7:
  if ( v5 < 30 )
  {
    v8 = &this->m_Decoys[v5];
    if ( (*((_BYTE *)&this->m_Decoys[v5] + 208) & 1) != 0 )
      SFHudRadar::RemoveIconPackage(this, a2: (int)this, pPackage: &this->m_Decoys[v5]);
    v9 = *((_BYTE *)&this->m_Decoys[v5] + 208);
    this->m_Decoys[v5].m_fGhostTime = -1000.0;
    this->m_Decoys[v5].m_fDeadTime = -1000.0;
    this->m_Decoys[v5].m_IconPackType = ICON_PACK_DECOY;
    this->m_Decoys[v5].m_iIndex = v5;
    this->m_Decoys[v5].m_Health = 100;
    *((_BYTE *)&this->m_Decoys[v5] + 208) = v9 & 0x2C | 1;
    this->m_Decoys[v5].m_fRoundStartTime = *(float *)(gpGlobals.m_Index + 12);
    this->m_Decoys[v5].m_Position = vec3_origin;
    this->m_Decoys[v5].m_Angle.x = 0.0;
    this->m_Decoys[v5].m_Angle.y = 0.0;
    this->m_Decoys[v5].m_Angle.z = 0.0;
    if ( this->m_Decoys[v5].m_fCurrentAlpha != 0.0 )
    {
      m_IconPackage = this->m_Decoys[v5].m_IconPackage;
      this->m_Decoys[v5].m_fCurrentAlpha = 0.0;
      if ( m_IconPackage != nullptr )
      {
        m_pScaleformUI = v8->m_pScaleformUI;
        v15 = 8;
        v14 = 0;
        m_pScaleformUI->Value_SetDisplayInfo(
          this: m_pScaleformUI,
          a2: m_IconPackage,
          a3: (const ScaleformDisplayInfo *)&v13);
        v5 = index;
      }
    }
    SFHudRadar::SFHudRadarIconPackage::SetVisibilityFlags(this: v8, newFlags: 0);
    if ( v8->m_IconPackage == nullptr && SFHudRadar::LazyCreateIconPackage(this, a2: (int)this, pIconPack: v8) == 0 )
      *((_BYTE *)this + 23476) &= ~0x20u;
    v8->m_iUserID = entityID;
    v8->m_fRoundStartTime = -1000.0;
    v12 = this->m_iLastDecoyIndex;
    if ( v5 > v12 )
      v12 = v5;
    this->m_iLastDecoyIndex = v12;
    return v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021F120
// Name: protected: void SFHudRadar::RemoveAllDecoys(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::RemoveAllDecoys(SFHudRadar *this)
{
  int v2; // edi
  SFHudRadar::SFHudRadarIconPackage *m_Decoys; // ebx
  int m_iLastDecoyIndex; // eax
  int v5; // eax

  v2 = 0;
  if ( this->m_iLastDecoyIndex >= 0 )
  {
    m_Decoys = this->m_Decoys;
    do
    {
      if ( (*((_BYTE *)m_Decoys + 208) & 1) != 0 )
      {
        SFHudRadar::RemoveIconPackage(this, a2: v2, pPackage: m_Decoys);
        m_iLastDecoyIndex = this->m_iLastDecoyIndex;
        if ( v2 == m_iLastDecoyIndex && m_iLastDecoyIndex >= 0 )
        {
          do
          {
            if ( (*((_BYTE *)&this->m_Decoys[this->m_iLastDecoyIndex] + 208) & 1) != 0 )
              break;
            v5 = this->m_iLastDecoyIndex - 1;
            this->m_iLastDecoyIndex = v5;
          }
          while ( v5 >= 0 );
        }
      }
      ++v2;
      ++m_Decoys;
    }
    while ( v2 <= this->m_iLastDecoyIndex );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021F1A0
// Name: protected: void SFHudRadar::SetupIconsFromStates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SetupIconsFromStates(SFHudRadar *this)
{
  char v2; // al
  __int16 v3; // di
  char v4; // al
  double v5; // st7
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm2_4
  IScaleformUI *m_pScaleformUI; // ecx
  void *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm2_4
  IScaleformUI *v20; // ecx
  void *v21; // eax
  ScaleformDisplayInfo displayInfo; // [esp+8h] [ebp-58h] BYREF
  Vector newMapPosition; // [esp+40h] [ebp-20h]
  Vector mapPosition; // [esp+4Ch] [ebp-14h]
  float fPercent; // [esp+58h] [ebp-8h]
  int newCashFlags; // [esp+5Ch] [ebp-4h]

  v2 = *((_BYTE *)this + 23496);
  v3 = 0;
  newCashFlags = 0;
  if ( (v2 & 1) != 0 )
    v3 = 32;
  if ( (v2 & 2) != 0 )
    newCashFlags = 1;
  if ( (v2 & 4) != 0 )
    newCashFlags |= 2u;
  if ( C_CSGameRules::IsBombDefuseMap(this: (C_CSGameRules *)g_pGameRules) )
  {
    v4 = *((_BYTE *)this + 23496);
    if ( (v4 & 0x10) != 0 )
      v3 |= 8u;
    if ( (v4 & 0x20) != 0 )
      v3 |= 0x10u;
    if ( (v4 & 0x40) != 0 && g_PlantedC4s.m_Size > 0 )
    {
      v5 = C_PlantedC4::GetDetonationProgress(this: *g_PlantedC4s.m_Memory.m_pMemory) * 100.0;
      fPercent = v5;
      if ( v5 <= 60.0 )
      {
        if ( fPercent <= 30.0 )
        {
          if ( fPercent > 0.0 )
            v3 |= 4u;
        }
        else
        {
          v3 |= 2u;
        }
      }
      else
      {
        v3 |= 1u;
      }
    }
    fPercent = this->m_fBombAlpha;
    if ( fPercent > 0.0 )
    {
      v3 |= 0x400u;
      if ( (*((_BYTE *)this + 23497) & 4) != 0 )
      {
        if ( (*((_BYTE *)this + 23496) & 0x40) != 0 )
          v3 |= 0x100u;
        else
          v3 |= 0x200u;
      }
      v6 = (float)(this->m_BombPosition.x - this->m_MapOrigin.x) * this->m_fWorldToRadarScale;
      v7 = (float)(this->m_MapOrigin.y - this->m_BombPosition.y) * this->m_fWorldToRadarScale;
      mapPosition.z = 0.0;
      *(_QWORD *)&mapPosition.x = __PAIR64__(LODWORD(v7), LODWORD(v6));
      *(_QWORD *)&newMapPosition.x = __PAIR64__(LODWORD(v7), LODWORD(v6));
      v8 = v7 - this->m_RadarViewpointMap.y;
      v9 = v6 - this->m_RadarViewpointMap.x;
      newMapPosition.z = 0.0;
      v10 = (float)((float)(v8 * v8) + (float)(v9 * v9))
          + (float)((float)(0.0 - this->m_RadarViewpointMap.z) * (float)(0.0 - this->m_RadarViewpointMap.z));
      if ( v10 >= 3364.0 )
      {
        v11 = fsqrt(3364.0 / v10);
        v6 = (float)(v11 * v9) + this->m_RadarViewpointMap.x;
        v7 = (float)(v8 * v11) + this->m_RadarViewpointMap.y;
      }
      m_pScaleformUI = this->m_pScaleformUI;
      displayInfo.m_fAlpha = (float)(fPercent * 100.0);
      v13 = this->m_Icons[10];
      displayInfo.m_iSetFlags = 15;
      displayInfo.m_fX = v6;
      displayInfo.m_fY = v7;
      displayInfo.m_fRotation = COERCE_FLOAT(LODWORD(this->m_RadarRotation) ^ _mask__NegFloat_);
      m_pScaleformUI->Value_SetDisplayInfo(this: m_pScaleformUI, a2: v13, a3: &displayInfo);
    }
    fPercent = this->m_fDefuserAlpha;
    if ( fPercent > 0.0 )
    {
      v3 |= 0x1000u;
      if ( (*((_BYTE *)this + 23497) & 8) != 0 )
        v3 |= 0x800u;
      v14 = (float)(this->m_DefuserPosition.x - this->m_MapOrigin.x) * this->m_fWorldToRadarScale;
      v15 = (float)(this->m_MapOrigin.y - this->m_DefuserPosition.y) * this->m_fWorldToRadarScale;
      mapPosition.z = 0.0;
      *(_QWORD *)&mapPosition.x = __PAIR64__(LODWORD(v15), LODWORD(v14));
      *(_QWORD *)&newMapPosition.x = __PAIR64__(LODWORD(v15), LODWORD(v14));
      v16 = v15 - this->m_RadarViewpointMap.y;
      v17 = v14 - this->m_RadarViewpointMap.x;
      newMapPosition.z = 0.0;
      v18 = (float)((float)(v16 * v16) + (float)(v17 * v17))
          + (float)((float)(0.0 - this->m_RadarViewpointMap.z) * (float)(0.0 - this->m_RadarViewpointMap.z));
      if ( v18 >= 3364.0 )
      {
        v19 = fsqrt(3364.0 / v18);
        v14 = (float)(v19 * v17) + this->m_RadarViewpointMap.x;
        v15 = (float)(v16 * v19) + this->m_RadarViewpointMap.y;
      }
      v20 = this->m_pScaleformUI;
      displayInfo.m_fAlpha = (float)(fPercent * 100.0);
      v21 = this->m_Icons[12];
      displayInfo.m_iSetFlags = 15;
      displayInfo.m_fX = v14;
      displayInfo.m_fY = v15;
      displayInfo.m_fRotation = COERCE_FLOAT(LODWORD(this->m_RadarRotation) ^ _mask__NegFloat_);
      v20->Value_SetDisplayInfo(this: v20, a2: v21, a3: &displayInfo);
    }
  }
  else if ( C_CSGameRules::IsHostageRescueMap(this: (C_CSGameRules *)g_pGameRules)
         && (*((_BYTE *)this + 23496) & 8) != 0 )
  {
    v3 |= 0x40u;
  }
  if ( (*((_BYTE *)this + 23497) & 0x10) != 0 )
    v3 |= 0x80u;
  SFHudRadar::SetVisibilityFlags(this, newFlags: v3);
  SFHudRadar::SetVisibilityFlagsCash(this, newFlags: newCashFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1021F500
// Name: protected: void SFHudRadar::SetIconPackagePosition(class SFHudRadar::SFHudRadarIconPackage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::SetIconPackagePosition(SFHudRadar *this, SFHudRadar::SFHudRadarIconPackage *pPackage)
{
  float x; // xmm1_4
  float v4; // xmm5_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  char v13; // al
  IScaleformUI *m_pScaleformUI; // ecx
  void *m_IconPackage; // eax
  ScaleformDisplayInfo displayInfo; // [esp+4h] [ebp-50h] BYREF
  Vector newMapPosition; // [esp+3Ch] [ebp-18h]
  Vector mapPosition; // [esp+48h] [ebp-Ch]

  if ( (*((_BYTE *)this + 23476) & 2) != 0 )
  {
    x = (float)(pPackage->m_Position.x - this->m_MapOrigin.x) * this->m_fWorldToRadarScale;
    v4 = (float)(this->m_MapOrigin.y - pPackage->m_Position.y) * this->m_fWorldToRadarScale;
    mapPosition.z = 0.0;
    *(_QWORD *)&mapPosition.x = __PAIR64__(LODWORD(v4), LODWORD(x));
    *(_QWORD *)&newMapPosition.x = __PAIR64__(LODWORD(v4), LODWORD(x));
    v5 = v4 - this->m_RadarViewpointMap.y;
    v6 = x - this->m_RadarViewpointMap.x;
    newMapPosition.z = 0.0;
    v7 = (float)((float)(v5 * v5) + (float)(v6 * v6))
       + (float)((float)(0.0 - this->m_RadarViewpointMap.z) * (float)(0.0 - this->m_RadarViewpointMap.z));
    if ( v7 < 3364.0 )
    {
      *((_BYTE *)pPackage + 208) &= ~2u;
      v13 = *((_BYTE *)pPackage + 208);
      if ( (v13 & 0x10) != 0 || (v13 & 0x40) == 0 )
        LODWORD(v12) = LODWORD(this->m_RadarRotation) ^ _mask__NegFloat_;
      else
        v12 = 90.0 - pPackage->m_Angle.y;
    }
    else
    {
      *((_BYTE *)pPackage + 208) |= 2u;
      v8 = fsqrt(3364.0 / v7);
      v9 = v8 * v6;
      v10 = v8 * v5;
      v11 = this->m_RadarViewpointMap.y + v10;
      mapPosition.x = this->m_RadarViewpointMap.x + v9;
      mapPosition.y = v11;
      __libm_sse2_atan2();
      v4 = v11;
      x = mapPosition.x;
      v12 = (float)((float)(v10 * 180.0) * 0.31830996) + 90.0;
    }
    m_pScaleformUI = this->m_pScaleformUI;
    displayInfo.m_fX = x;
    m_IconPackage = pPackage->m_IconPackage;
    displayInfo.m_fY = v4;
    displayInfo.m_iSetFlags = 7;
    displayInfo.m_fRotation = v12;
    m_pScaleformUI->Value_SetDisplayInfo(this: m_pScaleformUI, a2: m_IconPackage, a3: &displayInfo);
    SFHudRadar::SFHudRadarIconPackage::SetupIconsFromStates(this: pPackage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021F680
// Name: protected: void SFHudRadar::PlaceHostages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::PlaceHostages(SFHudRadar *this)
{
  bool v2; // zf
  IGameResources *v3; // eax
  int v4; // ebx
  C_CSPlayer *LocalPlayer; // esi
  int i; // esi
  Vector *v7; // edi
  SFHudRadar::SFHudRadarIconPackage *p_z; // esi
  char v9; // al
  char v10; // al
  C_CS_PlayerResource *v11; // ecx
  SFHudRadar::SFHudRadarHostageIcons *m_HostageStatusIcons; // edi
  int v13; // ebx
  SFHudRadar::SFHudRadarHostageIcons *v14; // esi
  int m_iCurrentIcon; // eax
  void *m_IconPackage; // edx
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v18; // ecx
  int v19; // edx
  SFHudRadar::SFHudRadarHostageIcons *v20; // edi
  int v21; // ebx
  SFHudRadar::SFHudRadarHostageIcons *v22; // esi
  int v23; // eax
  void *v24; // edx
  IScaleformUI *v25; // ecx
  IScaleformUI *v26; // ecx
  int v27; // edx
  SFHudRadar::SFHudRadarHostageIcons *v28; // edi
  int v29; // ebx
  SFHudRadar::SFHudRadarHostageIcons *v30; // esi
  int v31; // eax
  void *v32; // edx
  IScaleformUI *v33; // ecx
  IScaleformUI *v34; // ecx
  int v35; // edx
  SFHudRadar::SFHudRadarHostageIcons *v36; // edi
  C_CSPlayer *v37; // ebx
  SFHudRadar::SFHudRadarHostageIcons *v38; // esi
  int v39; // eax
  void *v40; // edx
  IScaleformUI *v41; // ecx
  IScaleformUI *v42; // ecx
  int *v43; // esi
  int v44; // ecx
  int v45; // edx
  Vector v46; // [esp+4h] [ebp-30h] BYREF
  Vector result; // [esp+10h] [ebp-24h] BYREF
  C_CSPlayer *pLocalPlayer; // [esp+1Ch] [ebp-18h]
  int iNumMovingHostages; // [esp+20h] [ebp-14h]
  int iNumRescuedHostages; // [esp+24h] [ebp-10h]
  int iNumDeadHostages; // [esp+28h] [ebp-Ch]
  SFHudRadar *v52; // [esp+2Ch] [ebp-8h]
  C_CS_PlayerResource *pCSPR; // [esp+30h] [ebp-4h]

  v2 = (*((_BYTE *)this + 23476) & 2) == 0;
  v52 = this;
  if ( !v2 && C_CSGameRules::IsHostageRescueMap(this: (C_CSGameRules *)g_pGameRules) )
  {
    v3 = GameResources();
    v4 = 0;
    if ( v3 != nullptr )
    {
      pCSPR = (C_CS_PlayerResource *)&v3[-608];
      if ( v3 != (IGameResources *)2432 )
      {
        LocalPlayer = CClientTools::GetLocalPlayer();
        pLocalPlayer = LocalPlayer;
        if ( LocalPlayer != nullptr )
        {
          if ( LocalPlayer->GetTeamNumber(this: LocalPlayer) == 2 )
          {
            for ( i = 0; i <= this->m_iLastHostageIndex; ++i )
              SFHudRadar::RemoveHostage(this, index: i);
            LocalPlayer = pLocalPlayer;
          }
          if ( (*((_BYTE *)this + 23476) & 8) != 0 || LocalPlayer->GetTeamNumber(this: LocalPlayer) == 3 )
          {
            pLocalPlayer = nullptr;
            iNumDeadHostages = 0;
            iNumMovingHostages = 0;
            iNumRescuedHostages = 0;
            v7 = (Vector *)((char *)this->m_Hostages + 208);
            do
            {
              p_z = (SFHudRadar::SFHudRadarIconPackage *)&v7[-18].z;
              if ( C_CS_PlayerResource::IsHostageAlive(this: pCSPR, iIndex: v4) )
              {
                if ( (LOBYTE(v7->x) & 1) == 0 )
                {
                  p_z = SFHudRadar::CreateHostage(this: v52, index: v4);
                  if ( p_z->m_iPlayerType != 13 )
                  {
                    p_z->m_iPlayerType = 13;
                    SFHudRadar::SFHudRadarIconPackage::SetVisibilityFlags(this: p_z, newFlags: 0);
                  }
                  p_z->m_iUserID = C_CS_PlayerResource::GetHostageEntityID(this: pCSPR, iIndex: v4);
                }
                v9 = *((_BYTE *)p_z + 208);
                if ( (v9 & 0x10) != 0 )
                {
                  p_z->m_fDeadTime = -1000.0;
                  *((_BYTE *)p_z + 208) = v9 & 0xEF;
                }
                if ( C_CS_PlayerResource::IsHostageFollowingSomeone(this: pCSPR, iIndex: v4) )
                {
                  ++iNumMovingHostages;
                  *((_BYTE *)p_z + 208) |= 0x20u;
                }
                else
                {
                  pLocalPlayer = (C_CSPlayer *)((char *)pLocalPlayer + 1);
                  *((_BYTE *)p_z + 208) &= ~0x20u;
                }
                p_z->m_Position = *C_CS_PlayerResource::GetHostagePosition(this: pCSPR, &result, iIndex: v4);
              }
              else if ( v4 <= v52->m_iLastHostageIndex && (LOBYTE(v7->x) & 1) != 0 )
              {
                if ( SLOBYTE(v7->x) >= 0 )
                  ++iNumDeadHostages;
                else
                  ++iNumRescuedHostages;
                v7[-11] = *C_CS_PlayerResource::GetHostagePosition(this: pCSPR, result: &v46, iIndex: v4);
                SFHudRadar::SFHudRadarIconPackage::SetIsDead(
                  this: (SFHudRadar::SFHudRadarIconPackage *)&v7[-18].z,
                  value: true);
                LOBYTE(v7->x) &= ~0x20u;
              }
              v10 = *((_BYTE *)p_z + 208);
              if ( (v10 & 1) != 0 )
              {
                if ( (float)(*(float *)(gpGlobals.m_Index + 12) - p_z->m_fRoundStartTime) > 0.25 && (v10 & 0x40) == 0 )
                {
                  p_z->m_fGhostTime = -1000.0;
                  *((_BYTE *)p_z + 208) = v10 | 0x40;
                }
                SFHudRadar::SetIconPackagePosition(this: v52, pPackage: p_z);
              }
              ++v4;
              v7 = (Vector *)((char *)v7 + 212);
            }
            while ( v4 < 12 );
            v11 = nullptr;
            pCSPR = nullptr;
            if ( iNumDeadHostages > 0 )
            {
              m_HostageStatusIcons = v52->m_HostageStatusIcons;
              v13 = iNumDeadHostages;
              pCSPR = (C_CS_PlayerResource *)iNumDeadHostages;
              do
              {
                v14 = m_HostageStatusIcons;
                m_iCurrentIcon = m_HostageStatusIcons->m_iCurrentIcon;
                ++m_HostageStatusIcons;
                if ( m_iCurrentIcon != 0 )
                {
                  m_IconPackage = v14->m_IconPackage;
                  if ( m_IconPackage != nullptr )
                  {
                    m_pScaleformUI = v14->m_pScaleformUI;
                    if ( m_iCurrentIcon == 4 )
                      ((void (__stdcall *)(void *, int))m_pScaleformUI->Value_SetVisible)(a1: m_IconPackage, a2: 1);
                    else
                      ((void (__stdcall *)(void *, _DWORD))m_pScaleformUI->Value_SetVisible)(
                        a1: v14->m_Icons[m_iCurrentIcon],
                        a2: 0);
                    v18 = v14->m_pScaleformUI;
                    v14->m_iCurrentIcon = 0;
                    v18->Value_SetVisible(this: v18, a2: v14->m_Icons[0], a3: true);
                  }
                }
                --v13;
              }
              while ( v13 != 0 );
              v11 = pCSPR;
            }
            if ( iNumRescuedHostages > 0 )
            {
              v19 = (int)v11;
              v11 = (C_CS_PlayerResource *)((char *)v11 + iNumRescuedHostages);
              v20 = &v52->m_HostageStatusIcons[v19];
              v21 = iNumRescuedHostages;
              pCSPR = v11;
              do
              {
                v22 = v20;
                v23 = v20->m_iCurrentIcon;
                ++v20;
                if ( v23 != 1 )
                {
                  v24 = v22->m_IconPackage;
                  if ( v24 != nullptr )
                  {
                    v25 = v22->m_pScaleformUI;
                    if ( v23 == 4 )
                      ((void (__stdcall *)(void *, int))v25->Value_SetVisible)(a1: v24, a2: 1);
                    else
                      ((void (__stdcall *)(void *, _DWORD))v25->Value_SetVisible)(a1: v22->m_Icons[v23], a2: 0);
                    v26 = v22->m_pScaleformUI;
                    v22->m_iCurrentIcon = 1;
                    v26->Value_SetVisible(this: v26, a2: v22->m_Icons[1], a3: true);
                    v11 = pCSPR;
                  }
                }
                --v21;
              }
              while ( v21 != 0 );
            }
            if ( iNumMovingHostages > 0 )
            {
              v27 = (int)v11;
              v11 = (C_CS_PlayerResource *)((char *)v11 + iNumMovingHostages);
              v28 = &v52->m_HostageStatusIcons[v27];
              v29 = iNumMovingHostages;
              pCSPR = v11;
              do
              {
                v30 = v28;
                v31 = v28->m_iCurrentIcon;
                ++v28;
                if ( v31 != 3 )
                {
                  v32 = v30->m_IconPackage;
                  if ( v32 != nullptr )
                  {
                    v33 = v30->m_pScaleformUI;
                    if ( v31 == 4 )
                      ((void (__stdcall *)(void *, int))v33->Value_SetVisible)(a1: v32, a2: 1);
                    else
                      ((void (__stdcall *)(void *, _DWORD))v33->Value_SetVisible)(a1: v30->m_Icons[v31], a2: 0);
                    v34 = v30->m_pScaleformUI;
                    v30->m_iCurrentIcon = 3;
                    v34->Value_SetVisible(this: v34, a2: v30->m_Icons[3], a3: true);
                    v11 = pCSPR;
                  }
                }
                --v29;
              }
              while ( v29 != 0 );
            }
            if ( (int)pLocalPlayer > 0 )
            {
              v35 = (int)v11;
              v11 = (C_CS_PlayerResource *)((char *)v11 + (_DWORD)pLocalPlayer);
              v36 = &v52->m_HostageStatusIcons[v35];
              v37 = pLocalPlayer;
              pCSPR = v11;
              do
              {
                v38 = v36;
                v39 = v36->m_iCurrentIcon;
                ++v36;
                if ( v39 != 2 )
                {
                  v40 = v38->m_IconPackage;
                  if ( v40 != nullptr )
                  {
                    v41 = v38->m_pScaleformUI;
                    if ( v39 == 4 )
                      ((void (__stdcall *)(void *, int))v41->Value_SetVisible)(a1: v40, a2: 1);
                    else
                      ((void (__stdcall *)(void *, _DWORD))v41->Value_SetVisible)(a1: v38->m_Icons[v39], a2: 0);
                    v42 = v38->m_pScaleformUI;
                    v38->m_iCurrentIcon = 2;
                    v42->Value_SetVisible(this: v42, a2: v38->m_Icons[2], a3: true);
                    v11 = pCSPR;
                  }
                }
                v37 = (C_CSPlayer *)((char *)v37 - 1);
              }
              while ( v37 != nullptr );
            }
            if ( (int)v11 < 12 )
            {
              v43 = (int *)((char *)v52 + 28 * (_DWORD)&v11->m_Collision.m_nSolidType);
              do
              {
                if ( *(v43 - 5) == 0 )
                  break;
                if ( *v43 != 4 && *(v43 - 5) != 0 )
                {
                  (*(void (__thiscall **)(_DWORD, int, _DWORD))(*(_DWORD *)*(v43 - 6) + 552))(
                    a1: *(v43 - 6),
                    a2: v43[*v43 - 4],
                    a3: 0);
                  v44 = *(v43 - 6);
                  v45 = *(v43 - 5);
                  *v43 = 4;
                  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v44 + 552))(a1: v44, a2: v45, a3: 0);
                  v11 = pCSPR;
                }
                v11 = (C_CS_PlayerResource *)((char *)v11 + 1);
                v43 += 7;
                pCSPR = v11;
              }
              while ( (int)v11 < 12 );
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021FAF0
// Name: protected: void SFHudRadar::PlacePlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudRadar::PlacePlayers(SFHudRadar *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  SFHudRadar *v3; // edi
  bool v4; // zf
  IGameResources *v5; // eax
  C_CSPlayer *LocalPlayer; // eax
  C_CSPlayer *v7; // esi
  int v8; // eax
  int v9; // eax
  bool v10; // sf
  SFHudRadar::SFHudRadarIconPackage *m_Players; // esi
  int v12; // ebx
  C_CSPlayer *v13; // edi
  bool (__thiscall *IsDormant)(IClientNetworkable *); // edx
  bool v15; // al
  IGameResources *v16; // edi
  C_CS_PlayerResource *v17; // ecx
  float v18; // xmm0_4
  char v19; // al
  int v20; // eax
  char v21; // al
  char v22; // al
  char v23; // al
  Vector *C4Postion; // eax
  SFHudRadar *v25; // ecx
  bool v26; // al
  Vector *v27; // eax
  SFHudRadar *v28; // ecx
  int v29; // eax
  int v30; // eax
  int v31; // edi
  int v32; // ebx
  int v33; // edi
  char v34; // al
  C_CSPlayer *v35; // edi
  Vector result; // [esp+4h] [ebp-28h] BYREF
  int v39; // [esp+10h] [ebp-1Ch]
  int localPlayerIndex; // [esp+14h] [ebp-18h]
  C_CSPlayer *pPlayer; // [esp+18h] [ebp-14h]
  int localTeamNumber; // [esp+1Ch] [ebp-10h]
  C_CS_PlayerResource *pCSPR; // [esp+20h] [ebp-Ch]
  SFHudRadar *v44; // [esp+24h] [ebp-8h]
  bool bDefuserIsVisibleToLocalPlayer; // [esp+2Ah] [ebp-2h]
  bool playerIsActive; // [esp+2Bh] [ebp-1h]

  v3 = this;
  v4 = (*((_BYTE *)this + 23476) & 2) == 0;
  v44 = this;
  if ( !v4 )
  {
    v5 = GameResources();
    if ( v5 != nullptr )
    {
      pCSPR = (C_CS_PlayerResource *)&v5[-608];
      if ( v5 != (IGameResources *)2432 )
      {
        LocalPlayer = CClientTools::GetLocalPlayer();
        v7 = LocalPlayer;
        if ( LocalPlayer != nullptr )
        {
          v8 = LocalPlayer->entindex(this: &LocalPlayer->IClientNetworkable);
          localPlayerIndex = v8 - 1;
          if ( v8 != 0 )
          {
            v9 = v7->GetTeamNumber(this: v7);
            v10 = v3->m_iLastPlayerIndex < 0;
            localTeamNumber = v9;
            m_Players = v3->m_Players;
            if ( !v10 )
            {
              v12 = 1;
              v39 = 1;
              while ( m_Players->m_IconPackage == nullptr || (*((_BYTE *)m_Players + 208) & 1) == 0 )
              {
LABEL_66:
                ++v12;
                ++m_Players;
                v39 = v12;
                if ( v12 - 1 > v3->m_iLastPlayerIndex )
                  return;
              }
              v13 = (C_CSPlayer *)UTIL_PlayerByIndex(entindex: v12);
              if ( v13 != nullptr && v13->IsPlayer(this: v13) )
              {
                IsDormant = v13->IsDormant;
                pPlayer = v13;
                v15 = IsDormant(this: &v13->IClientNetworkable);
                playerIsActive = true;
                if ( !v15 )
                  goto LABEL_14;
              }
              else
              {
                pPlayer = nullptr;
              }
              playerIsActive = false;
LABEL_14:
              v16 = &pCSPR->IGameResources;
              if ( !pCSPR->IsConnected(this: &pCSPR->IGameResources, a2: v12) )
              {
                if ( (float)(*(float *)(gpGlobals.m_Index + 12) - m_Players->m_fRoundStartTime) > 0.25 )
                {
                  v34 = *((_BYTE *)m_Players + 208);
                  if ( (v34 & 0x40) != 0 )
                  {
                    m_Players->m_fGhostTime = *(float *)(gpGlobals.m_Index + 12);
                    *((_BYTE *)m_Players + 208) = v34 & 0xBF;
                  }
                }
                *((_BYTE *)m_Players + 208) &= ~8u;
                goto LABEL_60;
              }
              m_Players->m_Health = ((int (__thiscall *)(IGameResources *, int, int, int))v16->GetHealth)(
                                      a1: v16,
                                      a2: v12,
                                      a3: a2,
                                      a4: a3);
              if ( !v16->IsAlive(this: v16, a2: v12) )
              {
                v17 = pCSPR;
                m_Players->m_Health = 0;
                if ( C_CS_PlayerResource::GetControlledByPlayer(this: v17, index: v12) != 0 )
                {
                  v18 = -1000.0;
                  *((_BYTE *)m_Players + 208) |= 0x50u;
                  m_Players->m_fDeadTime = -1000.0;
LABEL_35:
                  m_Players->m_fGhostTime = v18;
                  goto LABEL_36;
                }
                SFHudRadar::SFHudRadarIconPackage::SetIsDead(this: m_Players, value: true);
LABEL_36:
                if ( localTeamNumber == 3
                  && !C_CS_PlayerResource::IsBombSpotted(this: pCSPR)
                  && (*((_BYTE *)v44 + 23476) & 8) == 0 )
                {
                  goto LABEL_44;
                }
                if ( (*((_BYTE *)v44 + 23496) & 0x40) == 0 )
                {
                  C4Postion = C_CS_PlayerResource::GetC4Postion(this: pCSPR, &result);
                  v25 = v44;
                  v44->m_BombPosition = *C4Postion;
                  v25->m_BombPosition.z = 0.0;
                }
                if ( localTeamNumber != 2
                  || C_CS_PlayerResource::IsDefuserSpotted(this: pCSPR)
                  || (v4 = (*((_BYTE *)v44 + 23476) & 8) == 0, bDefuserIsVisibleToLocalPlayer = false, !v4) )
                {
LABEL_44:
                  bDefuserIsVisibleToLocalPlayer = true;
                }
                v26 = playerIsActive && C_CS_PlayerResource::HasDefuser(this: pCSPR, iIndex: v12);
                if ( bDefuserIsVisibleToLocalPlayer && v26 )
                {
                  v27 = pPlayer->GetAbsOrigin(this: pPlayer);
                  v28 = v44;
                  v44->m_DefuserPosition = *v27;
                  v28->m_DefuserPosition.z = 0.0;
                }
                a3 = v12;
                v29 = ((int (__thiscall *)(IGameResources *))v16->GetTeam)(a1: v16);
                SFHudRadar::SFHudRadarIconPackage::SetPlayerTeam(this: m_Players, team: v29);
                a2 = v12;
                v30 = ((int (__thiscall *)(IGameResources *))v16->GetTeam)(a1: v16);
                *((_BYTE *)m_Players + 209) ^= ((localTeamNumber == v30) ^ *((_BYTE *)m_Players + 209)) & 1;
                v31 = v12 - 1;
                *((_BYTE *)m_Players + 208) ^= (*((_BYTE *)m_Players + 208) ^ (4 * (v12 - 1 == localPlayerIndex))) & 4;
                v32 = 1 << ((v12 - 1) & 0x1F);
                v33 = v31 >> 5;
                if ( (v32 & GetClientVoiceMgr()->m_VoicePlayers.m_Ints[v33]) != 0
                  && (v32 & GetClientVoiceMgr()->m_AudiblePlayers.m_Ints[v33]) != 0 )
                {
                  SFHudRadar::SFHudRadarIconPackage::SetIsSpeaking(this: m_Players, value: true);
                  v12 = v39;
                }
                else
                {
                  SFHudRadar::SFHudRadarIconPackage::SetIsSpeaking(this: m_Players, value: false);
                  v12 = v39;
                }
LABEL_60:
                if ( playerIsActive
                  && (*((_BYTE *)m_Players + 208) & 0x40) != 0
                  && (v44->m_iObserverMode == 0 || v12 - 1 != localPlayerIndex) )
                {
                  v35 = pPlayer;
                  m_Players->m_Position = *C_BaseEntity::GetLocalOrigin(this: pPlayer);
                  m_Players->m_Angle = *C_BaseEntity::GetLocalAngles(this: v35);
                }
                SFHudRadar::SetIconPackagePosition(this: v44, pPackage: m_Players);
                v3 = v44;
                goto LABEL_66;
              }
              v19 = *((_BYTE *)m_Players + 208);
              if ( (v19 & 0x10) != 0 )
              {
                m_Players->m_fDeadTime = -1000.0;
                *((_BYTE *)m_Players + 208) = v19 & 0xEF;
              }
              v20 = v16->GetTeam(this: v16, a2: v12);
              if ( (playerIsActive || m_Players->m_Position.x != 0.0 || m_Players->m_Position.y != 0.0)
                && (localTeamNumber == v20
                 || (*((_BYTE *)v44 + 23476) & 8) != 0
                 || C_CS_PlayerResource::IsPlayerSpotted(this: pCSPR, iIndex: v12)) )
              {
                if ( (float)(*(float *)(gpGlobals.m_Index + 12) - m_Players->m_fRoundStartTime) <= 0.25 )
                  goto LABEL_36;
                v21 = *((_BYTE *)m_Players + 208);
                if ( (v21 & 0x40) != 0 )
                  goto LABEL_36;
                v18 = -1000.0;
                v22 = v21 | 0x40;
              }
              else
              {
                v18 = *(float *)(gpGlobals.m_Index + 12);
                if ( (float)(v18 - m_Players->m_fRoundStartTime) <= 0.25 )
                  goto LABEL_36;
                v23 = *((_BYTE *)m_Players + 208);
                if ( (v23 & 0x40) == 0 )
                  goto LABEL_36;
                v22 = v23 & 0xBF;
              }
              *((_BYTE *)m_Players + 208) = v22;
              goto LABEL_35;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021FF60
// Name: protected: void SFHudRadar::UpdateDecoys(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::UpdateDecoys(SFHudRadar *this)
{
  int v2; // ebx
  float *p_m_fCurrentAlpha; // esi

  v2 = 0;
  if ( this->m_iLastDecoyIndex >= 0 )
  {
    p_m_fCurrentAlpha = &this->m_Decoys[0].m_fCurrentAlpha;
    do
    {
      if ( p_m_fCurrentAlpha != (float *)112 && ((_BYTE)p_m_fCurrentAlpha[24] & 1) != 0 )
      {
        SFHudRadar::SetIconPackagePosition(
          this,
          pPackage: (SFHudRadar::SFHudRadarIconPackage *)(p_m_fCurrentAlpha - 28));
        if ( *p_m_fCurrentAlpha == 0.0 || *((_DWORD *)p_m_fCurrentAlpha + 1) == 0 )
          SFHudRadar::RemoveDecoy(this, index: v2);
      }
      ++v2;
      p_m_fCurrentAlpha += 53;
    }
    while ( v2 <= this->m_iLastDecoyIndex );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021FFD0
// Name: protected: void SFHudRadar::ResetRoundVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::ResetRoundVariables(SFHudRadar *this)
{
  float m_Value; // xmm0_4
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi

  SFHudRadar::SetVisibilityFlags(this, newFlags: 0);
  SFHudRadar::SetLocationText(this, newText: nullptr);
  this->m_RadarViewpointWorld = vec3_origin;
  this->m_RadarViewpointMap = vec3_origin;
  this->m_BombPosition = vec3_origin;
  this->m_DefuserPosition = vec3_origin;
  *((_BYTE *)this + 23496) &= 4u;
  *((_BYTE *)this + 23497) &= 0xE0u;
  *((_BYTE *)this + 23476) &= ~8u;
  this->m_RadarRotation = 0.0;
  this->m_fBombSeenTime = -1000.0;
  this->m_fBombAlpha = 0.0;
  this->m_fDefuserSeenTime = -1000.0;
  this->m_fDefuserAlpha = 0.0;
  this->m_iPrevCash = -1;
  this->m_iObserverMode = 0;
  m_Value = this->m_CashLostDisplayTimer.m_timestamp.m_Value;
  p_m_timestamp = &this->m_CashLostDisplayTimer.m_timestamp;
  if ( m_Value != -1.0 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *, CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *))(LODWORD(p_m_timestamp[-2].m_Value) + 4))(
      a1: p_m_timestamp - 2,
      a2: p_m_timestamp);
    p_m_timestamp->m_Value = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10220120
// Name: protected: void SFHudRadar::ResetRound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::ResetRound(SFHudRadar *this)
{
  SFHudRadar *v1; // ebx
  int v2; // edi
  float *p_z; // esi
  char v4; // al
  int v5; // eax
  int v6; // ecx
  bool v7; // sf
  float *v8; // esi
  char v9; // al
  int v10; // eax
  int v11; // ecx
  int v12; // ebx
  void **j; // edi
  void *v14; // eax
  void **v15; // esi
  void *v16; // ecx
  void *v17; // edx
  _BYTE v18[24]; // [esp+0h] [ebp-40h] BYREF
  __int64 v19; // [esp+18h] [ebp-28h]
  int v20; // [esp+30h] [ebp-10h]
  int i; // [esp+38h] [ebp-8h]
  SFHudRadar *v22; // [esp+3Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  v22 = this;
  if ( this->m_iLastPlayerIndex >= 0 )
  {
    p_z = &this->m_Players[0].m_Position.z;
    do
    {
      v4 = *((_BYTE *)p_z + 124);
      if ( (v4 & 1) != 0 )
      {
        *((_DWORD *)p_z + 11) = 100;
        p_z[6] = -1000.0;
        p_z[5] = -1000.0;
        *((_BYTE *)p_z + 124) = v4 & 0x2D;
        p_z[4] = *(float *)(gpGlobals.m_Index + 12);
        *(Vector *)(p_z - 2) = vec3_origin;
        p_z[1] = 0.0;
        p_z[2] = 0.0;
        p_z[3] = 0.0;
        if ( p_z[7] != 0.0 )
        {
          v5 = *((_DWORD *)p_z - 20);
          p_z[7] = 0.0;
          if ( v5 != 0 )
          {
            v6 = *((_DWORD *)p_z - 21);
            v20 = 8;
            v19 = 0;
            (*(void (__thiscall **)(int, int, _BYTE *))(*(_DWORD *)v6 + 560))(a1: v6, a2: v5, a3: v18);
            v1 = v22;
          }
        }
        SFHudRadar::SFHudRadarIconPackage::SetVisibilityFlags(
          this: (SFHudRadar::SFHudRadarIconPackage *)(p_z - 21),
          newFlags: 0);
      }
      ++v2;
      p_z += 53;
    }
    while ( v2 <= v1->m_iLastPlayerIndex );
  }
  if ( C_CSGameRules::IsHostageRescueMap(this: (C_CSGameRules *)g_pGameRules) )
  {
    v7 = v1->m_iLastHostageIndex < 0;
    i = 0;
    if ( !v7 )
    {
      v8 = &v1->m_Hostages[0].m_Position.z;
      do
      {
        v9 = *((_BYTE *)v8 + 124);
        if ( (v9 & 1) != 0 )
        {
          v8[6] = -1000.0;
          v8[5] = -1000.0;
          *((_DWORD *)v8 + 11) = 100;
          *((_BYTE *)v8 + 124) = v9 & 0x2D;
          v8[4] = *(float *)(gpGlobals.m_Index + 12);
          *(Vector *)(v8 - 2) = vec3_origin;
          v8[1] = 0.0;
          v8[2] = 0.0;
          v8[3] = 0.0;
          if ( v8[7] != 0.0 )
          {
            v10 = *((_DWORD *)v8 - 20);
            v8[7] = 0.0;
            if ( v10 != 0 )
            {
              v11 = *((_DWORD *)v8 - 21);
              v20 = 8;
              v19 = 0;
              (*(void (__thiscall **)(int, int, _BYTE *))(*(_DWORD *)v11 + 560))(a1: v11, a2: v10, a3: v18);
            }
          }
          SFHudRadar::SFHudRadarIconPackage::SetVisibilityFlags(
            this: (SFHudRadar::SFHudRadarIconPackage *)(v8 - 21),
            newFlags: 0);
        }
        v8 += 53;
        ++i;
      }
      while ( i <= v1->m_iLastHostageIndex );
    }
    v12 = 0;
    for ( j = &v22->m_HostageStatusIcons[0].m_IconPackage; *j != nullptr; j += 7 )
    {
      if ( v12 >= 12 )
        break;
      v14 = j[5];
      v15 = j - 1;
      ++v12;
      if ( v14 != (void *)4 && v15[1] != nullptr )
      {
        (*(void (__thiscall **)(void *, void *, _DWORD))(*(_DWORD *)*v15 + 552))(
          a1: *v15,
          a2: v15[(_DWORD)v14 + 2],
          a3: 0);
        v16 = *v15;
        v17 = v15[1];
        v15[6] = (void *)4;
        (*(void (__thiscall **)(void *, void *, _DWORD))(*(_DWORD *)v16 + 552))(a1: v16, a2: v17, a3: 0);
      }
    }
    v1 = v22;
  }
  SFHudRadar::RemoveAllDecoys(this: v1);
  SFHudRadar::ResetRoundVariables(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10220380
// Name: protected: void SFHudRadar::UpdateMiscIcons(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::UpdateMiscIcons(SFHudRadar *this)
{
  C_CSPlayer *LocalPlayer; // ebx
  IGameResources *v3; // eax
  bool v4; // al
  char v5; // al
  int Account; // edi
  int m_iPrevCash; // eax
  float m_Value; // xmm0_4
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  bool HasDefuser; // al
  float x; // xmm1_4
  bool v13; // bl
  C_CSPlayer *v14; // edi
  bool IsBombSpotted; // al
  char v16; // cl
  float v17; // xmm0_4
  bool v18; // al
  float v19; // xmm1_4
  bool v20; // bl
  bool IsDefuserSpotted; // al
  float v22; // xmm0_4
  wchar_t *v23; // [esp+4h] [ebp-28h]
  ConVarRef mp_defuser_allocation; // [esp+10h] [ebp-1Ch] BYREF
  ConVarRef v25; // [esp+18h] [ebp-14h] BYREF
  C_CS_PlayerResource *pCSPR; // [esp+20h] [ebp-Ch]
  float now; // [esp+24h] [ebp-8h]
  C_CSPlayer *pLocalPlayer; // [esp+28h] [ebp-4h]

  LocalPlayer = CClientTools::GetLocalPlayer();
  pLocalPlayer = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return;
  if ( LocalPlayer->GetObserverMode(this: LocalPlayer) != 0 )
    *((_BYTE *)this + 23497) &= ~0x10u;
  else
    *((_BYTE *)this + 23497) |= 0x10u;
  if ( LocalPlayer == (C_CSPlayer *)-6164 )
  {
    SFHudRadar::SetLocationText(this, newText: nullptr);
  }
  else
  {
    v23 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: LocalPlayer->m_szLastPlaceName);
    SFHudRadar::SetLocationText(this, newText: v23);
  }
  v3 = GameResources();
  if ( v3 == nullptr )
    return;
  pCSPR = (C_CS_PlayerResource *)&v3[-608];
  if ( v3 == (IGameResources *)2432 )
    return;
  v4 = !C_CSGameRules::IsBuyTimeElapsed(this: (C_CSGameRules *)g_pGameRules)
    && C_CSPlayer::IsInBuyZone(this: LocalPlayer);
  v5 = *((_BYTE *)this + 23496) & 0xF8 | v4;
  *((_BYTE *)this + 23496) = v5;
  if ( (v5 & 1) != 0 )
  {
    if ( C_CSPlayer::GetAccount(this: LocalPlayer) <= 0 )
      Account = 0;
    else
      Account = C_CSPlayer::GetAccount(this: LocalPlayer);
    m_iPrevCash = this->m_iPrevCash;
    if ( m_iPrevCash != -1 && Account < m_iPrevCash )
      CountdownTimer::Start(this: &this->m_CashLostDisplayTimer, duration: 3.0);
    if ( this->m_CashLostDisplayTimer.m_timestamp.m_Value > 0.0
      && CountdownTimer::Now(this: (CEffectsClient *)&this->m_CashLostDisplayTimer) > this->m_CashLostDisplayTimer.m_timestamp.m_Value )
    {
      CountdownTimer::Invalidate(this: &this->m_CashLostDisplayTimer);
    }
    m_Value = this->m_CashLostDisplayTimer.m_timestamp.m_Value;
    *((_BYTE *)this + 23496) ^= (*((_BYTE *)this + 23496) ^ (2 * (m_Value <= 0.0))) & 2;
    *((_BYTE *)this + 23496) ^= (*((_BYTE *)this + 23496) ^ (4 * (m_Value > 0.0))) & 4;
    if ( Account != this->m_iPrevCash )
    {
      for ( i = 1; ; i = 0 )
      {
        m_pScaleformUI = this->m_pScaleformUI;
        if ( i == 0 )
          break;
        if ( m_pScaleformUI != nullptr )
          m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
        V_snwprintf(pDest: (wchar_t *)&mp_defuser_allocation, maxLen: 8, pFormat: L"-$%d", this->m_iPrevCash - Account);
        this->m_IconsCash[1]->SetText(this: this->m_IconsCash[1], a2: (const wchar_t *)&mp_defuser_allocation);
        V_snwprintf(pDest: (wchar_t *)&mp_defuser_allocation, maxLen: 8, pFormat: L"$%d", Account);
        this->m_IconsCash[0]->SetText(this: this->m_IconsCash[0], a2: (const wchar_t *)&mp_defuser_allocation);
      }
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      this->m_iPrevCash = Account;
    }
  }
  this->m_fBombAlpha = 0.0;
  this->m_fDefuserAlpha = 0.0;
  if ( C_CSGameRules::IsBombDefuseMap(this: (C_CSGameRules *)g_pGameRules) )
  {
    *((_BYTE *)this + 23496) ^= (*((_BYTE *)this + 23496) ^ (16 * C_CSPlayer::HasC4(this: LocalPlayer))) & 0x10;
    HasDefuser = C_CSPlayer::HasDefuser(this: LocalPlayer);
    x = this->m_BombPosition.x;
    *((_BYTE *)this + 23496) ^= (*((_BYTE *)this + 23496) ^ (32 * HasDefuser)) & 0x20;
    now = *(float *)(gpGlobals.m_Index + 12);
    v13 = x != 0.0 || this->m_BombPosition.y != 0.0;
    v14 = pLocalPlayer;
    if ( pLocalPlayer->GetTeamNumber(this: pLocalPlayer) != 3
      || (IsBombSpotted = C_CS_PlayerResource::IsBombSpotted(this: pCSPR))
      || (*((_BYTE *)this + 23476) & 8) != 0 )
    {
      IsBombSpotted = true;
    }
    if ( v13 )
    {
      v16 = *((_BYTE *)this + 23497);
      if ( (v16 & 2) == 0 && IsBombSpotted )
      {
        this->m_fBombSeenTime = now;
        this->m_fBombAlpha = 1.0;
LABEL_54:
        v18 = (v16 & 1) == 0 && (*((_BYTE *)this + 23496) & 0xC0) != 0;
        *((_BYTE *)this + 23497) = v16 ^ (v16 ^ (4 * v18)) & 4;
LABEL_59:
        ConVarRef::ConVarRef(this: &v25, pName: "mp_defuser_allocation");
        if ( v25.m_pConVarState->m_Value.m_nValue == 1 )
        {
          v19 = this->m_DefuserPosition.x;
          now = *(float *)(gpGlobals.m_Index + 12);
          v20 = v19 != 0.0 || this->m_DefuserPosition.y != 0.0;
          if ( v14->GetTeamNumber(this: v14) != 2
            || (IsDefuserSpotted = C_CS_PlayerResource::IsDefuserSpotted(this: pCSPR))
            || (*((_BYTE *)this + 23476) & 8) != 0 )
          {
            IsDefuserSpotted = true;
          }
          if ( v20 && IsDefuserSpotted )
          {
            this->m_fDefuserSeenTime = now;
            this->m_fDefuserAlpha = 1.0;
          }
          else
          {
            v22 = 1.0 - (float)((float)(now - this->m_fDefuserSeenTime) * 0.125);
            if ( v22 >= 0.0 )
            {
              if ( v22 > 1.0 )
                v22 = 1.0;
            }
            else
            {
              v22 = 0.0;
            }
            this->m_fDefuserAlpha = v22;
            if ( v22 <= 0.0 )
              this->m_fDefuserSeenTime = -1000.0;
          }
        }
        else
        {
          *((_BYTE *)this + 23497) &= ~8u;
        }
        return;
      }
    }
    v16 = *((_BYTE *)this + 23497);
    if ( (v16 & 2) != 0 )
    {
      this->m_fBombAlpha = 0.0;
    }
    else
    {
      v17 = 1.0 - (float)((float)(now - this->m_fBombSeenTime) * 0.125);
      if ( v17 >= 0.0 )
      {
        if ( v17 > 1.0 )
          v17 = 1.0;
      }
      else
      {
        v17 = 0.0;
      }
      this->m_fBombAlpha = v17;
      if ( v17 > 0.0 )
        goto LABEL_54;
    }
    this->m_fBombSeenTime = -1000.0;
    goto LABEL_59;
  }
  if ( C_CSGameRules::IsHostageRescueMap(this: (C_CSGameRules *)g_pGameRules) )
    *((_BYTE *)this + 23496) ^= (*((_BYTE *)this + 23496)
                               ^ (8 * C_CSPlayer::IsInHostageRescueZone(this: LocalPlayer)))
                              & 8;
}

//------------------------------------------------------------------------------
// Address: 0x10220850
// Name: public: virtual void SFHudRadar::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudRadar::ProcessInput(SFHudRadar *this@<ecx>, int a2@<ebx>, void *a3@<edi>)
{
  SFHudRadar::LazyCreateGoalIcons(this);
  SFHudRadar::LazyCreatePlayerIcons(this, a2, a3);
  SFHudRadar::ApplySpectatorModes(this);
  SFHudRadar::PositionRadarViewpoint(this);
  SFHudRadar::PlaceGoalIcons(this);
  SFHudRadar::PlacePlayers(this, a2, a3: (int)this);
  SFHudRadar::PlaceHostages(this);
  SFHudRadar::UpdateDecoys(this);
  SFHudRadar::UpdateMiscIcons(this);
  SFHudRadar::SetupIconsFromStates(this);
}

//------------------------------------------------------------------------------
// Address: 0x102208A0
// Name: protected: void SFHudRadar::ResetForNewMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::ResetForNewMap(SFHudRadar *this)
{
  int v2; // ebx
  void **m_BombZoneIcons; // edi
  void **m_HostageZoneIcons; // edi
  int i; // ebx
  int m_iLastHostageIndex; // edi
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  void **j; // ebx
  void *v11; // eax
  void **v12; // edi
  void *v13; // ecx
  void *v14; // edx
  int index; // [esp+8h] [ebp-4h]

  v2 = 2;
  if ( (*((_BYTE *)this + 23476) & 2) != 0 )
  {
    m_BombZoneIcons = this->m_BombZoneIcons;
    do
    {
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: *m_BombZoneIcons++, a3: false);
      --v2;
    }
    while ( v2 != 0 );
    m_HostageZoneIcons = this->m_HostageZoneIcons;
    for ( i = 4; i != 0; --i )
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: *m_HostageZoneIcons++, a3: false);
    while ( this->m_iLastHostageIndex >= 0 )
    {
      m_iLastHostageIndex = this->m_iLastHostageIndex;
      SFHudRadar::RemoveIconPackage(this, a2: m_iLastHostageIndex, pPackage: &this->m_Hostages[m_iLastHostageIndex]);
      v7 = this->m_iLastHostageIndex;
      if ( m_iLastHostageIndex == v7 && v7 >= 0 )
      {
        while ( (*((_BYTE *)&this->m_Hostages[this->m_iLastHostageIndex] + 208) & 1) == 0 )
        {
          v8 = this->m_iLastHostageIndex - 1;
          this->m_iLastHostageIndex = v8;
          if ( v8 < 0 )
            goto LABEL_13;
        }
      }
    }
LABEL_13:
    v9 = 0;
    for ( j = &this->m_HostageStatusIcons[0].m_IconPackage; *j != nullptr; j += 7 )
    {
      if ( v9 >= 12 )
        break;
      v11 = j[5];
      v12 = j - 1;
      index = ++v9;
      if ( v11 != (void *)4 && v12[1] != nullptr )
      {
        (*(void (__thiscall **)(void *, void *, _DWORD))(*(_DWORD *)*v12 + 552))(
          a1: *v12,
          a2: v12[(_DWORD)v11 + 2],
          a3: 0);
        v13 = *v12;
        v14 = v12[1];
        v12[6] = (void *)4;
        (*(void (__thiscall **)(void *, void *, _DWORD))(*(_DWORD *)v13 + 552))(a1: v13, a2: v14, a3: 0);
        v9 = index;
      }
    }
  }
  *((_BYTE *)this + 23476) &= ~0x10u;
  this->m_iNumGoalIcons = 0;
  SFHudRadar::ResetRoundVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102209F0
// Name: public: SFHudRadar::SFHudRadar(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SFHudRadar *__thiscall SFHudRadar::SFHudRadar(SFHudRadar *this, const char *value)
{
  float z; // ecx
  SFHudRadar::SFHudRadarIconPackage *m_Players; // edi
  SFHudRadar::SFHudRadarIconPackage *m_Hostages; // edi
  SFHudRadar::SFHudRadarIconPackage *m_Decoys; // edi
  void **m_Icons; // edi
  char v8; // dl
  CountdownTimer_vtbl *v9; // edx
  CountdownTimer_vtbl *v10; // edx
  int valuea; // [esp+14h] [ebp+8h]
  int valueb; // [esp+14h] [ebp+8h]
  int valuec; // [esp+14h] [ebp+8h]
  int valued; // [esp+14h] [ebp+8h]

  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->m_HudRenderGroups.m_Memory.m_pMemory = nullptr;
  this->m_HudRenderGroups.m_Memory.m_nAllocationCount = 0;
  this->m_HudRenderGroups.m_Memory.m_nGrowSize = 0;
  this->m_HudRenderGroups.m_Size = 0;
  this->m_HudRenderGroups.m_pElements = nullptr;
  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->__vftable = (SFHudRadar_vtbl *)&SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this, pElementName: value);
  this->m_fPixelToRadarScale = 1.0;
  this->m_fWorldToPixelScale = 1.0;
  this->m_fWorldToRadarScale = 1.0;
  this->__vftable = (SFHudRadar_vtbl *)&SFHudRadar::`vftable';
  this->m_RadarViewpointWorld = vec3_origin;
  this->m_RadarViewpointMap = vec3_origin;
  this->m_RadarRotation = 0.0;
  this->m_BombPosition = vec3_origin;
  this->m_fBombSeenTime = -1000.0;
  this->m_fBombAlpha = 0.0;
  *(_QWORD *)&this->m_DefuserPosition.x = *(_QWORD *)&vec3_origin.x;
  z = vec3_origin.z;
  this->m_iLastPlayerIndex = -1;
  this->m_iLastHostageIndex = -1;
  this->m_iLastDecoyIndex = -1;
  this->m_DefuserPosition.z = z;
  this->m_fDefuserSeenTime = -1000.0;
  this->m_fDefuserAlpha = 0.0;
  this->m_iCurrentVisibilityFlags = 0;
  this->m_iCashCurrentVisibilityFlags = 0;
  this->m_RadarModule = nullptr;
  this->m_Radar = nullptr;
  this->m_IconTranslation = nullptr;
  this->m_IconRotation = nullptr;
  this->m_MapRotation = nullptr;
  this->m_MapTranslation = nullptr;
  this->m_LocationText = nullptr;
  m_Players = this->m_Players;
  for ( valuea = 63; valuea >= 0; --valuea )
    SFHudRadar::SFHudRadarIconPackage::ClearAll(this: m_Players++);
  m_Hostages = this->m_Hostages;
  for ( valueb = 11; valueb >= 0; --valueb )
    SFHudRadar::SFHudRadarIconPackage::ClearAll(this: m_Hostages++);
  m_Decoys = this->m_Decoys;
  for ( valuec = 29; valuec >= 0; --valuec )
    SFHudRadar::SFHudRadarIconPackage::ClearAll(this: m_Decoys++);
  valued = 11;
  m_Icons = this->m_HostageStatusIcons[0].m_Icons;
  do
  {
    *(m_Icons - 1) = nullptr;
    _V_memset(dest: (int)m_Icons, fill: nullptr, count: 0x10u);
    m_Icons[4] = (void *)4;
    m_Icons += 7;
    --valued;
  }
  while ( valued >= 0 );
  v8 = *((_BYTE *)this + 23476) & 0xD0 | 4;
  this->m_iNumGoalIcons = 0;
  this->m_iObserverMode = 0;
  *((_BYTE *)this + 23476) = v8;
  this->m_iPrevCash = -1;
  this->m_CashLostDisplayTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v9 = this->m_CashLostDisplayTimer.__vftable;
  this->m_CashLostDisplayTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v9->NetworkStateChanged)(a1: &this->m_CashLostDisplayTimer.m_duration);
  v10 = this->m_CashLostDisplayTimer.__vftable;
  this->m_CashLostDisplayTimer.m_timestamp.m_Value = -1.0;
  v10->NetworkStateChanged(this: &this->m_CashLostDisplayTimer, a2: &this->m_CashLostDisplayTimer.m_timestamp);
  *((_BYTE *)this + 23496) &= 4u;
  *((_BYTE *)this + 23497) &= 0xE3u;
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x40);
  this->m_cDesiredMapName[0] = 0;
  this->m_cLoadedMapName[0] = 0;
  this->m_wcLocationString[0] = 0;
  _V_memset(dest: (int)this->m_BombZoneIcons, fill: nullptr, count: 0x10u);
  _V_memset(dest: (int)this->m_HostageZoneIcons, fill: nullptr, count: 0x10u);
  _V_memset(dest: (int)this->m_GoalIcons, fill: nullptr, count: 0x60u);
  _V_memset(dest: (int)this->m_HostageStatusIcons, fill: nullptr, count: 0x150u);
  _V_memset(dest: (int)this->m_Icons, fill: nullptr, count: 0x34u);
  _V_memset(dest: (int)this->m_IconsCash, fill: nullptr, count: 8u);
  if ( this->m_CashLostDisplayTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_CashLostDisplayTimer.NetworkStateChanged(
      this: &this->m_CashLostDisplayTimer,
      a2: &this->m_CashLostDisplayTimer.m_timestamp);
    this->m_CashLostDisplayTimer.m_timestamp.m_Value = -1.0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10220CE0
// Name: public: virtual void SFHudRadar::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::FlashReady(SFHudRadar *this)
{
  void *v2; // eax
  void *v3; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  void *v5; // eax
  void **m_Icons; // edi
  int i; // ebx
  ISFTextObject **m_IconsCash; // edi
  int j; // ebx
  IScaleformUI *v10; // ecx

  v2 = this->m_pScaleformUI->Value_Invoke(
         this: this->m_pScaleformUI,
         a2: this->m_IconTranslation,
         a3: "createBombPack",
         a4: 0,
         a5: 0);
  this->m_Icons[10] = v2;
  if ( v2 != nullptr )
  {
    v3 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v2, a3: "DroppedBomb");
    m_pScaleformUI = this->m_pScaleformUI;
    this->m_Icons[9] = v3;
    this->m_Icons[8] = m_pScaleformUI->Value_GetMember(this: m_pScaleformUI, a2: this->m_Icons[10], a3: "PlantedBomb");
  }
  v5 = this->m_pScaleformUI->Value_Invoke(
         this: this->m_pScaleformUI,
         a2: this->m_IconTranslation,
         a3: "createDefuserPack",
         a4: 0,
         a5: 0);
  this->m_Icons[12] = v5;
  if ( v5 != nullptr )
    this->m_Icons[11] = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v5, a3: "DroppedDefuser");
  m_Icons = this->m_Icons;
  for ( i = 13; i != 0; --i )
  {
    if ( *m_Icons != nullptr )
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: *m_Icons, a3: false);
    ++m_Icons;
  }
  m_IconsCash = this->m_IconsCash;
  for ( j = 2; j != 0; --j )
  {
    if ( *(m_IconsCash - 13) != nullptr )
      (*m_IconsCash)->SetVisible(this: *m_IconsCash, a2: false);
    ++m_IconsCash;
  }
  *((_BYTE *)this + 23476) = *((_BYTE *)this + 23476) & 0xFC | 2;
  SFHudRadar::ResetForNewMap(this);
  SFHudRadar::FlashLoadMap(this, a2: (int)m_IconsCash, pMapName: nullptr);
  v10 = this->m_pScaleformUI;
  if ( this->m_bActive )
    v10->Value_InvokeWithoutReturn(this: v10, a2: this->m_FlashAPI, a3: "showPanel", a4: nullptr, a5: 0);
  else
    v10->Value_InvokeWithoutReturn(this: v10, a2: this->m_FlashAPI, a3: "hidePanel", a4: nullptr, a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10220E40
// Name: public: virtual void SFHudRadar::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::FireGameEvent(SFHudRadar *this, IGameEvent *event)
{
  unsigned __int16 v4; // ax
  char *v5; // eax
  unsigned int v6; // ebx
  SFHudRadar::SFHudRadarIconPackage *Player; // eax
  SFHudRadar::SFHudRadarIconPackage *v8; // edi
  const char *v9; // eax
  int v10; // eax
  int PlayerIndexFromUserID; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int HostageIndexFromHostageEntityID; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  SFHudRadar::SFHudRadarIconPackage *v27; // ecx
  char v28; // al
  int v29; // eax
  C_BasePlayer *v30; // ebx
  int v31; // ebx
  SFHudRadar::SFHudRadarIconPackage *Decoy; // ebx
  char v33; // al
  int v34; // eax
  IUniformRandomStream *v35; // ecx
  int v36; // eax
  int DecoyIndexFromEntityID; // eax
  SFHudRadar::SFHudRadarIconPackage *v38; // eax
  char v39; // cl
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+34h] [ebp-8h] BYREF
  int teamNumber; // [esp+44h] [ebp+8h]
  C_CSPlayer *teamNumbera; // [esp+44h] [ebp+8h]
  int teamNumberc; // [esp+44h] [ebp+8h]
  int teamNumberb; // [esp+44h] [ebp+8h]
  float teamNumberd; // [esp+44h] [ebp+8h]

  search.key = event->GetName(this: event);
  v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &SFHudRadar::m_messageMap.m_Tree,
         &search);
  if ( v4 != 0xFFFF )
  {
    teamNumber = SFHudRadar::m_messageMap.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
    switch ( teamNumber )
    {
      case 0:
        SFHudRadar::ResetForNewMap(this);
        v5 = (char *)event->GetString(this: event, a2: "mapname", a3: prType);
        SFHudRadar::SetMap(this, a2: (int)this, pMapName: v5);
        break;
      case 1:
        SFHudRadar::ResetRound(this);
        break;
      case 2:
      case 3:
        v6 = event->GetInt(this: event, a2: "index", a3: 0);
        search.elem = event->GetInt(this: event, a2: "userid", a3: 0);
        if ( v6 <= 0x3F )
        {
          Player = SFHudRadar::CreatePlayer(this, index: v6);
          v8 = Player;
          if ( teamNumber == 2 && Player->m_iPlayerType != 0 )
          {
            Player->m_iPlayerType = 0;
            SFHudRadar::SFHudRadarIconPackage::SetVisibilityFlags(this: Player, newFlags: 0);
          }
          v8->m_iUserID = search.elem;
          v9 = event->GetString(this: event, a2: "name", a3: "unknown");
          _V_UTF8ToUnicode(a1: v9, a2: v8->m_wcName, a3: 66);
        }
        break;
      case 4:
        v10 = event->GetInt(this: event, a2: "userid", a3: 0);
        PlayerIndexFromUserID = SFHudRadar::GetPlayerIndexFromUserID(this, userID: v10);
        if ( PlayerIndexFromUserID != -1 )
        {
          v12 = event->GetInt(this: event, a2: "team", a3: 0);
          SFHudRadar::SFHudRadarIconPackage::SetPlayerTeam(this: &this->m_Players[PlayerIndexFromUserID], team: v12);
        }
        break;
      case 5:
        v17 = event->GetInt(this: event, a2: "userid", a3: 0);
        v18 = SFHudRadar::GetPlayerIndexFromUserID(this, userID: v17);
        if ( v18 != -1 )
          this->m_Players[v18].m_Health = 100;
        break;
      case 6:
        v13 = event->GetInt(this: event, a2: "userid", a3: 0);
        v14 = SFHudRadar::GetPlayerIndexFromUserID(this, userID: v13);
        if ( v14 != -1 )
        {
          v15 = v14;
          if ( (*((_BYTE *)&this->m_Players[v15] + 208) & 1) != 0 )
          {
            SFHudRadar::SFHudRadarIconPackage::SetIsDead(this: &this->m_Players[v15], value: true);
            *(_DWORD *)(v16 + 128) = 0;
          }
        }
        break;
      case 7:
        v19 = event->GetInt(this: event, a2: "userid", a3: 0);
        v20 = SFHudRadar::GetPlayerIndexFromUserID(this, userID: v19);
        if ( v20 != -1 )
          SFHudRadar::RemovePlayer(this, index: v20);
        break;
      case 8:
        v21 = event->GetInt(this: event, a2: "hostage", a3: 0);
        HostageIndexFromHostageEntityID = SFHudRadar::GetHostageIndexFromHostageEntityID(this, entityID: v21);
        if ( HostageIndexFromHostageEntityID != -1 )
        {
          v23 = HostageIndexFromHostageEntityID;
          if ( (*((_BYTE *)&this->m_Hostages[v23] + 208) & 1) != 0 )
            SFHudRadar::SFHudRadarIconPackage::SetIsDead(this: &this->m_Hostages[v23], value: true);
        }
        break;
      case 9:
        v24 = event->GetInt(this: event, a2: "hostage", a3: 0);
        v25 = SFHudRadar::GetHostageIndexFromHostageEntityID(this, entityID: v24);
        if ( v25 != -1 )
        {
          v26 = v25;
          v27 = &this->m_Hostages[v26];
          v28 = *((_BYTE *)&this->m_Hostages[v26] + 208);
          if ( (v28 & 1) != 0 )
            *((_BYTE *)v27 + 208) = v28 | 0x80;
        }
        break;
      case 10:
        *((_BYTE *)this + 23497) |= 1u;
        break;
      case 11:
        *((_BYTE *)this + 23497) |= 2u;
        break;
      case 12:
        *((_BYTE *)this + 23496) |= 0x40u;
        this->m_BombPosition.x = (float)event->GetInt(this: event, a2: "posx", a3: 0);
        this->m_BombPosition.y = (float)event->GetInt(this: event, a2: "posy", a3: 0);
        this->m_BombPosition.z = 0.0;
        break;
      case 13:
        *((_BYTE *)this + 23496) &= ~0x80u;
        break;
      case 14:
        *((_BYTE *)this + 23496) |= 0x80u;
        break;
      case 15:
        *((_BYTE *)this + 23497) &= ~8u;
        break;
      case 16:
        *((_BYTE *)this + 23497) |= 8u;
        break;
      case 17:
        teamNumbera = CClientTools::GetLocalPlayer();
        if ( teamNumbera != nullptr )
        {
          v29 = event->GetInt(this: event, a2: "userid", a3: 0);
          v30 = UTIL_PlayerByUserId(userID: v29);
          search.elem = (int)v30;
          if ( v30 != nullptr )
          {
            teamNumberc = teamNumbera->GetTeamNumber(this: teamNumbera);
            if ( v30->GetTeamNumber(this: v30) != teamNumberc )
            {
              v31 = event->GetInt(this: event, a2: "entityid", a3: 0);
              teamNumberb = (*(int (__thiscall **)(int))(*(_DWORD *)search.elem + 332))(a1: search.elem);
              Decoy = SFHudRadar::CreateDecoy(this, entityID: v31);
              if ( Decoy != nullptr )
              {
                SFHudRadar::SFHudRadarIconPackage::SetPlayerTeam(this: Decoy, team: teamNumberb);
                if ( (float)(*(float *)(gpGlobals.m_Index + 12) - Decoy->m_fRoundStartTime) > 0.25 )
                {
                  v33 = *((_BYTE *)Decoy + 208);
                  if ( (v33 & 0x40) == 0 )
                  {
                    Decoy->m_fGhostTime = -1000.0;
                    *((_BYTE *)Decoy + 208) = v33 | 0x40;
                  }
                }
                teamNumberd = (float)event->GetInt(this: event, a2: "x", a3: 0);
                v34 = event->GetInt(this: event, a2: "y", a3: 0);
                Decoy->m_Position.x = teamNumberd;
                Decoy->m_Position.y = (float)v34;
                Decoy->m_Position.z = 0.0;
                Decoy->m_Angle.y = _RandomFloat(this: v35, a2: 0.0, a3: 360.0);
                Decoy->m_Angle.x = 0.0;
                Decoy->m_Angle.z = 0.0;
                SFHudRadar::SetIconPackagePosition(this, pPackage: Decoy);
              }
            }
          }
        }
        break;
      case 18:
        v36 = event->GetInt(this: event, a2: "entityid", a3: 0);
        DecoyIndexFromEntityID = SFHudRadar::GetDecoyIndexFromEntityID(this, entityID: v36);
        if ( DecoyIndexFromEntityID != -1 )
        {
          v38 = &this->m_Decoys[DecoyIndexFromEntityID];
          if ( (float)(*(float *)(gpGlobals.m_Index + 12) - v38->m_fRoundStartTime) > 0.25 )
          {
            v39 = *((_BYTE *)v38 + 208);
            if ( (v39 & 0x40) != 0 )
            {
              v38->m_fGhostTime = *(float *)(gpGlobals.m_Index + 12);
              *((_BYTE *)v38 + 208) = v39 & 0xBF;
            }
          }
          SFHudRadar::SetIconPackagePosition(this, pPackage: v38);
        }
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102213E0
// Name: Create_SFHudRadar
// Source: json
//------------------------------------------------------------------------------
SFHudRadar *__cdecl Create_SFHudRadar()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 23500);
  memset(dst: v0, value: 0, count: 0x5BCCu);
  if ( v0 != nullptr )
    return SFHudRadar::SFHudRadar(this: (SFHudRadar *)v0, value: "SFHudRadar");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10221420
// Name: public: virtual void SFHudRadar::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudRadar::Init(SFHudRadar *this)
{
  const char *v1; // eax
  const char **v3; // esi
  const char **v4; // ecx
  const char *v5; // edi
  const char *v6; // ecx
  unsigned __int16 v7; // cx
  int v8; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v9; // eax
  unsigned __int16 v10; // dx
  int v11; // edx
  bool v12; // zf
  CUtlMap<char const *,int,unsigned short>::Node_t insert; // [esp+Ch] [ebp-14h] BYREF
  const char **pwalk; // [esp+14h] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+18h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Fh] [ebp-1h] BYREF

  v1 = desiredMessageNames[0];
  v3 = desiredMessageNames;
  if ( desiredMessageNames[0] != nullptr )
  {
    do
    {
      this->m_bRegisteredForEvents = true;
      gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: v1, a4: false);
      v1 = v3[1];
      ++v3;
    }
    while ( v1 != nullptr );
    v1 = desiredMessageNames[0];
  }
  if ( SFHudRadar::m_messageMap.m_Tree.m_NumElements == 0 )
  {
    v4 = desiredMessageNames;
    v5 = nullptr;
    pwalk = desiredMessageNames;
    if ( v1 != nullptr )
    {
      do
      {
        v6 = *v4;
        insert.elem = (int)v5;
        insert.key = v6;
        ++v5;
        *(_DWORD *)parent = 0xFFFF;
        leftchild = false;
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
          this: &SFHudRadar::m_messageMap.m_Tree,
          &insert,
          parent,
          &leftchild);
        v7 = CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
               this: (CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&SFHudRadar::m_messageMap,
               a2: v5);
        v8 = v7;
        v9 = &SFHudRadar::m_messageMap.m_Tree.m_Elements.m_pMemory[v7];
        v10 = parent[0];
        v9->m_Right = -1;
        v9->m_Left = -1;
        v9->m_Parent = v10;
        v9->m_Tag = 0;
        if ( v10 == 0xFFFF )
        {
          SFHudRadar::m_messageMap.m_Tree.m_Root = v7;
        }
        else
        {
          v11 = v10;
          if ( leftchild )
            SFHudRadar::m_messageMap.m_Tree.m_Elements.m_pMemory[v11].m_Left = v7;
          else
            SFHudRadar::m_messageMap.m_Tree.m_Elements.m_pMemory[v11].m_Right = v7;
        }
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
          this: &SFHudRadar::m_messageMap.m_Tree,
          elem: v7);
        ++SFHudRadar::m_messageMap.m_Tree.m_NumElements;
        if ( &SFHudRadar::m_messageMap.m_Tree.m_Elements.m_pMemory[v8] != (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)-8 )
          SFHudRadar::m_messageMap.m_Tree.m_Elements.m_pMemory[v8].m_Data = insert;
        v4 = pwalk + 1;
        v12 = pwalk[1] == nullptr;
        ++pwalk;
      }
      while ( !v12 );
    }
  }
  CUserMessages::HookMessage(this: usermessages, name: "UpdateRadar", hook: __MsgFunc_SFHudRadar_UpdateRadar);
}

//------------------------------------------------------------------------------
// Address: 0x10426D70
// Name: _dynamic_initializer_for__SFHudRadar::m_messageMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__SFHudRadar::m_messageMap__()
{
  return atexit(func: dynamic_atexit_destructor_for__SFHudRadar::m_messageMap__);
}

//------------------------------------------------------------------------------
// Address: 0x10435D40
// Name: _dynamic_atexit_destructor_for__SFHudRadar::m_messageMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__SFHudRadar::m_messageMap__()
{
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &SFHudRadar::m_messageMap.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10426D80
// Name: _dynamic_initializer_for__g_SFHudRadar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_SFHudRadar_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_SFHudRadar_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_SFHudRadar,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10426DA0
// Name: _dynamic_initializer_for__drawradar_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__drawradar_command__()
{
  ConCommand::ConCommand(
    this: &drawradar_command,
    pName: "drawradar",
    callback: drawradar,
    pHelpString: "Draws HUD radar",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__drawradar_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10426DD0
// Name: _dynamic_initializer_for__hideradar_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hideradar_command__()
{
  ConCommand::ConCommand(
    this: &hideradar_command,
    pName: "hideradar",
    callback: hideradar,
    pHelpString: "Hides HUD radar",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hideradar_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10435D50
// Name: _dynamic_atexit_destructor_for__sfcrosshair__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sfcrosshair__()
{
  ConVar::~ConVar(this: &sfcrosshair);
}
