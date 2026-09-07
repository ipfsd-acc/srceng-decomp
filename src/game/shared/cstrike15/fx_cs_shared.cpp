// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/fx_cs_shared.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101CBBB0
// Name: void FX_PlantBomb(int,class Vector const __near &,enum PlantBombOption_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_PlantBomb(int iPlayerIndex, const Vector *vOrigin, PlantBombOption_t option)
{
  C_BaseEntity *BaseEntity; // eax
  C_BaseEntity *v4; // esi

  BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: iPlayerIndex);
  v4 = BaseEntity;
  if ( BaseEntity != nullptr && BaseEntity->IsPlayer(this: BaseEntity) && !v4->IsDormant(this: &v4->IClientNetworkable) )
  {
    if ( option != PLANTBOMB_PLANT )
    {
      if ( option == PLANTBOMB_ABORT )
        (**(void (__thiscall ***)(unsigned __int8 *, int, _DWORD))v4[2].m_pIntermediateData_FirstPredicted[41])(
          a1: v4[2].m_pIntermediateData_FirstPredicted[41],
          a2: 8,
          a3: 0);
    }
    else
    {
      (**(void (__thiscall ***)(unsigned __int8 *, _DWORD, _DWORD))v4[2].m_pIntermediateData_FirstPredicted[41])(
        a1: v4[2].m_pIntermediateData_FirstPredicted[41],
        a2: 0,
        a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CBC20
// Name: void FX_WeaponSound(int,enum WeaponSound_t,class Vector const __near &,class CCSWeaponInfo __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_WeaponSound(
        int iPlayerIndex,
        WeaponSound_t sound_type,
        const Vector *vOrigin,
        CCSWeaponInfo *pWeaponInfo,
        float flSoundTime)
{
  const char *v5; // esi
  CBroadcastRecipientFilter filter; // [esp+Ch] [ebp-20h] BYREF

  v5 = pWeaponInfo->aShootSounds[sound_type];
  if ( (CCSWeaponInfo *)((char *)pWeaponInfo + 80 * sound_type) != (CCSWeaponInfo *)-528 && *v5 != 0 )
  {
    C_RecipientFilter::C_RecipientFilter(this: &filter);
    filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
    C_RecipientFilter::AddAllPlayers(this: &filter);
    if ( te->m_nStatusPushed <= 0 && !te->m_bSuppressEvent )
      C_BaseEntity::EmitSound(
        &filter,
        iEntIndex: iPlayerIndex,
        soundname: v5,
        pOrigin: vOrigin,
        soundtime: flSoundTime,
        duration: nullptr);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CBCA0
// Name: void ShotgunImpactSoundGroup(char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShotgunImpactSoundGroup(const char *pSoundName, const Vector *vEndPos)
{
  int v2; // ebx
  CGroupedSound *m_pMemory; // eax
  int v4; // esi
  float v5; // xmm0_4
  int m_Size; // eax
  int v7; // esi
  CGroupedSound *v8; // ecx
  int v9; // eax
  int v10; // esi
  CLocalPlayerFilter filter; // [esp+14h] [ebp-20h] BYREF

  v2 = 0;
  if ( g_GroupedSounds.m_Size > 0 )
  {
    m_pMemory = g_GroupedSounds.m_Memory.m_pMemory;
    v4 = 0;
    do
    {
      v5 = vEndPos->x - m_pMemory[v4].m_vPos.x;
      if ( (float)((float)((float)((float)(vEndPos->y - m_pMemory[v4].m_vPos.y)
                                 * (float)(vEndPos->y - m_pMemory[v4].m_vPos.y))
                         + (float)(v5 * v5))
                 + (float)((float)(vEndPos->z - m_pMemory[v4].m_vPos.z) * (float)(vEndPos->z - m_pMemory[v4].m_vPos.z))) < 90000.0 )
      {
        if ( _V_stricmp(s1: m_pMemory[v4].m_SoundName, s2: pSoundName) == 0 )
          return;
        m_pMemory = g_GroupedSounds.m_Memory.m_pMemory;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < g_GroupedSounds.m_Size );
  }
  CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
  C_BaseEntity::EmitSound(
    &filter,
    iEntIndex: 0,
    soundname: pSoundName,
    pOrigin: vEndPos,
    soundtime: 0.0,
    duration: nullptr);
  m_Size = g_GroupedSounds.m_Size;
  v7 = g_GroupedSounds.m_Size;
  if ( g_GroupedSounds.m_Size + 1 > g_GroupedSounds.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&g_GroupedSounds,
      num: g_GroupedSounds.m_Size - g_GroupedSounds.m_Memory.m_nAllocationCount + 1);
    m_Size = g_GroupedSounds.m_Size;
  }
  v8 = g_GroupedSounds.m_Memory.m_pMemory;
  g_GroupedSounds.m_Size = m_Size + 1;
  v9 = m_Size - v7;
  g_GroupedSounds.m_pElements = g_GroupedSounds.m_Memory.m_pMemory;
  if ( v9 > 0 )
  {
    _V_memmove(
      dest: &g_GroupedSounds.m_Memory.m_pMemory[v7 + 1],
      src: &g_GroupedSounds.m_Memory.m_pMemory[v7],
      count: 16 * v9);
    v8 = g_GroupedSounds.m_Memory.m_pMemory;
  }
  v10 = v7;
  v8[v10].m_SoundName = pSoundName;
  g_GroupedSounds.m_Memory.m_pMemory[v10].m_vPos = *vEndPos;
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x101CBDE0
// Name: void FX_FireBullets(int,class Vector const __near &,class QAngle const __near &,enum CSWeaponID,int,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_FireBullets(
        int iPlayerIndex,
        const Vector *vOrigin,
        const QAngle *vAngles,
        CSWeaponID iWeaponID,
        int iMode,
        int iSeed,
        float fInaccuracy,
        float fSpread,
        float flSoundTime)
{
  C_BaseEntity *BaseEntity; // eax
  float v10; // ebx
  const char *v11; // eax
  const char *v12; // esi
  unsigned __int16 v13; // di
  CDetailModel *v14; // ecx
  FileWeaponInfo_t *FileWeaponInfoFromHandle; // edi
  float v16; // xmm0_4
  int v17; // edx
  WeaponSound_t v18; // eax
  float v19; // xmm0_4
  float v20; // xmm0_4
  vgui::PropertyPage *v21; // ecx
  IUniformRandomStream *v22; // ecx
  IUniformRandomStream *v23; // ecx
  IUniformRandomStream *v24; // ecx
  double v25; // st7
  int v26; // esi
  IUniformRandomStream *v27; // ecx
  double v28; // st7
  long double v29; // st6
  int i; // esi
  CGroupedSound *m_pMemory; // eax
  float v32; // [esp+18h] [ebp-A4h]
  float x1[16]; // [esp+1Ch] [ebp-A0h]
  float y1[16]; // [esp+5Ch] [ebp-60h]
  float y0; // [esp+9Ch] [ebp-20h]
  int iAmmoType; // [esp+A0h] [ebp-1Ch]
  float flRange; // [esp+A4h] [ebp-18h]
  int iPenetration; // [esp+A8h] [ebp-14h]
  float x0; // [esp+ACh] [ebp-10h]
  int iDamage; // [esp+B0h] [ebp-Ch]
  float flRangeModifier; // [esp+B4h] [ebp-8h]
  float fTheta1; // [esp+B8h] [ebp-4h]
  int iSeeda; // [esp+D8h] [ebp+1Ch]

  BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: iPlayerIndex);
  v10 = *(float *)&BaseEntity;
  if ( BaseEntity == nullptr || !BaseEntity->IsPlayer(this: BaseEntity) )
    v10 = 0.0;
  v11 = WeaponIdAsString(weaponID: iWeaponID);
  v12 = v11;
  if ( v11 == nullptr )
  {
    DevMsg(a1: "FX_FireBullets: weapon name for ID %i not found\n", iWeaponID);
    return;
  }
  v13 = LookupWeaponInfoSlot(name: v11);
  if ( v13 == CDefaultClientRenderable::GetShadowHandle(this: v14) )
  {
    DevMsg(a1: "FX_FireBullets: LookupWeaponInfoSlot failed for weapon %s\n", v12);
    return;
  }
  FileWeaponInfoFromHandle = GetFileWeaponInfoFromHandle(handle: v13);
  if ( v10 != 0.0
    && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(LODWORD(v10) + 8) + 36))(a1: LODWORD(v10) + 8) == 0 )
  {
    (***(void (****)(void))(LODWORD(v10) + 6756))();
  }
  v16 = *(float *)&FileWeaponInfoFromHandle[1].szAmmo1[24];
  v17 = *(_DWORD *)&FileWeaponInfoFromHandle[1].szAmmo1[16];
  iDamage = *(_DWORD *)&FileWeaponInfoFromHandle[1].szAmmo1[20];
  v18 = SINGLE;
  iSeeda = iSeed + 1;
  iAmmoType = FileWeaponInfoFromHandle->iAmmoType;
  flRange = v16;
  v19 = *(float *)&FileWeaponInfoFromHandle[1].szAmmo1[28];
  iPenetration = v17;
  flRangeModifier = v19;
  if ( iWeaponID == WEAPON_GLOCK )
  {
    if ( iMode != 1 )
      goto LABEL_18;
    v20 = 0.89999998;
    iDamage = 18;
    goto LABEL_17;
  }
  if ( iWeaponID == WEAPON_M4A1 && iMode == 1 )
  {
    v20 = 0.94999999;
    v18 = SPECIAL1;
LABEL_17:
    flRangeModifier = v20;
  }
LABEL_18:
  FX_WeaponSound(
    iPlayerIndex,
    sound_type: v18,
    vOrigin,
    pWeaponInfo: (CCSWeaponInfo *)FileWeaponInfoFromHandle,
    flSoundTime);
  if ( v10 != 0.0 )
  {
    SetImpactSoundRoute(fn: ShotgunImpactSoundGroup);
    if ( *(_BYTE *)(LODWORD(v10) + 6276) != 0
      && *(int *)FileWeaponInfoFromHandle[1].szAmmo2 > 0
      && FileWeaponInfoFromHandle->iRumbleEffect != -1 )
    {
      C_BasePlayer::GetSplitScreenPlayerSlot(this: (C_BasePlayer *)LODWORD(v10));
      C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v21);
    }
    _RandomSeed(a1: iSeeda);
    fTheta1 = _RandomFloat(this: v22, a2: 0.0, a3: 6.2831855);
    v25 = _RandomFloat(this: v23, a2: 0.0, a3: fInaccuracy);
    v26 = 0;
    x0 = cos(fTheta1) * v25;
    for ( y0 = v25 * sin(fTheta1); v26 < *(_DWORD *)FileWeaponInfoFromHandle[1].szAmmo2; x1[v26 + 15] = v28 * sin(v29) )
    {
      fTheta1 = _RandomFloat(this: v24, a2: 0.0, a3: 6.2831855);
      v28 = _RandomFloat(this: v27, a2: 0.0, a3: fSpread);
      v29 = fTheta1;
      x1[v26++] = cos(fTheta1) * v28;
    }
    for ( i = 0; i < *(_DWORD *)FileWeaponInfoFromHandle[1].szAmmo2; ++i )
    {
      x1[2] = y1[i] + y0;
      x1[1] = x1[i] + x0;
      LODWORD(x1[0]) = 1;
      v32 = v10;
      C_CSPlayer::FireBullet(
        this: (C_CSPlayer *)LODWORD(v10),
        vecSrc: *vOrigin,
        shootAngles: vAngles,
        flDistance: flRange,
        iPenetration,
        iBulletType: iAmmoType,
        iDamage,
        flRangeModifier,
        pevAttacker: (C_BaseEntity *)LODWORD(v10),
        bDoEffects: true,
        xSpread: x1[1],
        ySpread: x1[2]);
    }
    m_pMemory = g_GroupedSounds.m_Memory.m_pMemory;
    g_GroupedSounds.m_Size = 0;
    if ( g_GroupedSounds.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_GroupedSounds.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_GroupedSounds.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_GroupedSounds.m_Memory.m_pMemory = nullptr;
      }
      g_GroupedSounds.m_Memory.m_nAllocationCount = 0;
    }
    g_GroupedSounds.m_pElements = m_pMemory;
    SetImpactSoundRoute(fn: nullptr);
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102A0AC0
// Name: void FX_PlantBomb(int,class Vector const __near &,enum PlantBombOption_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_PlantBomb(int iPlayerIndex, const Vector *vOrigin, PlantBombOption_t option)
{
  CBasePlayer *v3; // esi
  CBaseEntity *v4; // eax
  CBaseEntity *v5; // esi

  v3 = UTIL_PlayerByIndex(playerIndex: iPlayerIndex);
  if ( v3 != nullptr && v3->IsPlayer(this: v3) )
  {
    v4 = (CBaseEntity *)__RTDynamicCast(
                          inptr: v3,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
    v5 = v4;
    if ( v4 != nullptr && !CBaseEntity::IsDormant(this: v4) )
    {
      if ( option != PLANTBOMB_PLANT )
      {
        if ( option == PLANTBOMB_ABORT )
          (**(void (__thiscall ***)(const char *, int, _DWORD))v5[7].m_iName.m_Value.pszValue)(
            a1: v5[7].m_iName.m_Value.pszValue,
            a2: 8,
            a3: 0);
      }
      else
      {
        (**(void (__thiscall ***)(const char *, _DWORD, _DWORD))v5[7].m_iName.m_Value.pszValue)(
          a1: v5[7].m_iName.m_Value.pszValue,
          a2: 0,
          a3: 0);
      }
    }
  }
  TE_PlantBomb(iPlayerIndex, vOrigin, option);
}

//------------------------------------------------------------------------------
// Address: 0x102A0B50
// Name: void FX_FireBullets(int,class Vector const __near &,class QAngle const __near &,enum CSWeaponID,int,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall FX_FireBullets(
        float a1@<ebp>,
        int iPlayerIndex,
        const Vector *vOrigin,
        const QAngle *vAngles,
        CSWeaponID iWeaponID,
        int iMode,
        int iSeed,
        float fInaccuracy,
        float fSpread)
{
  CBasePlayer *v9; // eax
  CBasePlayer *v10; // esi
  CCSPlayer *v11; // edi
  const char *v12; // ecx
  __int128 v13; // xmm0
  unsigned __int16 v14; // si
  CStringRegistry *v15; // ecx
  FileWeaponInfo_t *FileWeaponInfoFromHandle; // esi
  void (__thiscall *DoAnimationEvent)(ICSPlayerAnimState *, PlayerAnimEvent_t, int); // edx
  float v18; // xmm0_4
  int v19; // edx
  int v20; // xmm0_4
  int v21; // xmm0_4
  IUniformRandomStream *v22; // ecx
  IUniformRandomStream *v23; // ecx
  IUniformRandomStream *v24; // ecx
  double v25; // st7
  int v26; // edi
  IUniformRandomStream *v27; // ecx
  double v28; // st7
  long double v29; // st6
  int j; // edi
  char v31[12]; // [esp+48h] [ebp-1CCh] BYREF
  char szFlags[256]; // [esp+54h] [ebp-1C0h]
  float y1[16]; // [esp+154h] [ebp-C0h]
  __int128 x1_52; // [esp+1C8h] [ebp-4Ch] OVERLAPPED
  float v35; // [esp+1E4h] [ebp-30h]
  float i; // [esp+1E8h] [ebp-2Ch]
  int v37; // [esp+1ECh] [ebp-28h]
  float x0; // [esp+1F0h] [ebp-24h]
  int y0; // [esp+1F4h] [ebp-20h]
  int iPenetration; // [esp+1F8h] [ebp-1Ch]
  float flRange; // [esp+1FCh] [ebp-18h]
  int iAmmoType; // [esp+200h] [ebp-14h]
  int iDamage; // [esp+204h] [ebp-10h]
  float fTheta1; // [esp+208h] [ebp-Ch] BYREF
  CCSPlayer *pPlayer; // [esp+20Ch] [ebp-8h]
  CCSPlayer *retaddr; // [esp+214h] [ebp+0h]
  int iSeeda; // [esp+22Ch] [ebp+18h]

  fTheta1 = a1;
  pPlayer = retaddr;
  v9 = UTIL_PlayerByIndex(playerIndex: iPlayerIndex);
  v10 = v9;
  if ( v9 != nullptr && v9->IsPlayer(this: v9) )
  {
    v11 = (CCSPlayer *)__RTDynamicCast(
                         inptr: v10,
                         VfDelta: 0,
                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                         TargetType: &CCSPlayer `RTTI Type Descriptor',
                         isReference: 0);
    iAmmoType = (int)v11;
  }
  else
  {
    iAmmoType = 0;
    v11 = nullptr;
  }
  v12 = WeaponIdAsString(weaponID: iWeaponID);
  iDamage = (int)v12;
  if ( v12 == nullptr )
  {
    DevMsg(a1: "FX_FireBullets: weapon name for ID %i not found\n", iWeaponID);
    return;
  }
  if ( weapon_accuracy_logging.m_pParent != nullptr && weapon_accuracy_logging.m_pParent->m_Value.m_nValue != 0 )
  {
    _V_strcpy(dest: v31, src: " ");
    if ( v11->m_MoveType.m_Value == 9 )
      V_strncat(pDest: v31, pSrc: "LADDER ", destBufferSize: 0x100u, max_chars_to_copy: -1);
    if ( (v11->m_fFlags.m_Value & 1) != 0 )
      V_strncat(pDest: v31, pSrc: "GROUND ", destBufferSize: 0x100u, max_chars_to_copy: -1);
    if ( (v11->m_fFlags.m_Value & 2) != 0 )
      V_strncat(pDest: v31, pSrc: "DUCKING ", destBufferSize: 0x100u, max_chars_to_copy: -1);
    if ( (v11->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: v11, a2: (int)&fTheta1);
    v13 = 0;
    *(float *)&v13 = fsqrt(
                       (float)(v11->m_vecAbsVelocity.x * v11->m_vecAbsVelocity.x)
                     + (float)(v11->m_vecAbsVelocity.y * v11->m_vecAbsVelocity.y));
    x1_52 = v13;
    _Msg(
      a1: "FireBullets @ %10f [ %s ]: inaccuracy=%f  spread=%f  max dispersion=%f  mode=%2i  vel=%10f  seed=%3i  %s\n",
      gpGlobals->curtime,
      (const char *)iDamage,
      fInaccuracy,
      fSpread,
      (float)(fInaccuracy + fSpread),
      iMode,
      *(float *)&v13,
      iSeed,
      v31);
    v12 = (const char *)iDamage;
  }
  v14 = LookupWeaponInfoSlot(name: v12);
  if ( v14 == (unsigned __int16)GetInvalidWeaponInfoHandle(this: v15) )
  {
    DevMsg(a1: "FX_FireBullets: LookupWeaponInfoSlot failed for weapon %s\n", (const char *)iDamage);
    return;
  }
  FileWeaponInfoFromHandle = GetFileWeaponInfoFromHandle(handle: v14);
  if ( v11 != nullptr && !CBaseEntity::IsDormant(this: v11) )
  {
    DoAnimationEvent = v11->m_PlayerAnimState->DoAnimationEvent;
    if ( iMode != 0 )
      ((void (__cdecl *)(int, _DWORD))DoAnimationEvent)(a1: 1, a2: 0);
    else
      ((void (__cdecl *)(_DWORD, _DWORD))DoAnimationEvent)(a1: 0, a2: 0);
  }
  TE_FireBullets(iPlayerIndex, vOrigin, vAngles, iWeaponID, iMode, iSeed, fInaccuracy, fSpread);
  CCSPlayer::NoteWeaponFired(this: v11);
  v18 = *(float *)&FileWeaponInfoFromHandle[1].szAmmo1[24];
  v19 = *(_DWORD *)&FileWeaponInfoFromHandle[1].szAmmo1[16];
  iPenetration = *(_DWORD *)&FileWeaponInfoFromHandle[1].szAmmo1[20];
  iSeeda = iSeed + 1;
  y0 = FileWeaponInfoFromHandle->iAmmoType;
  x0 = v18;
  v20 = *(_DWORD *)&FileWeaponInfoFromHandle[1].szAmmo1[28];
  v37 = v19;
  iDamage = v20;
  if ( iWeaponID == WEAPON_GLOCK )
  {
    if ( iMode != 1 )
      goto LABEL_32;
    v21 = 1063675494;
    iPenetration = 18;
    goto LABEL_31;
  }
  if ( iWeaponID == WEAPON_M4A1 && iMode == 1 )
  {
    v21 = 1064514355;
LABEL_31:
    iDamage = v21;
  }
LABEL_32:
  if ( v11 != nullptr )
  {
    CCSPlayer::StartNewBulletGroup();
    ((void (__cdecl *)(CCSPlayer *, int, Vector *, QAngle *, _DWORD))lagcompensation->StartLagCompensation)(
      a1: v11,
      a2: 2,
      a3: &vec3_origin,
      a4: &vec3_angle,
      a5: 0);
    _RandomSeed(a1: iSeeda);
    flRange = _RandomFloat(this: v22, a2: 0.0, a3: 6.2831855);
    v25 = _RandomFloat(this: v23, a2: 0.0, a3: fInaccuracy);
    v26 = 0;
    v35 = cos(flRange) * v25;
    for ( i = v25 * sin(flRange);
          v26 < *(_DWORD *)FileWeaponInfoFromHandle[1].szAmmo2;
          *(float *)&szFlags[4 * v26 + 240] = v28 * sin(v29) )
    {
      flRange = _RandomFloat(this: v24, a2: 0.0, a3: 6.2831855);
      v28 = _RandomFloat(this: v27, a2: 0.0, a3: fSpread);
      v29 = flRange;
      y1[++v26 + 12] = cos(flRange) * v28;
    }
    for ( j = 0; j < *(_DWORD *)FileWeaponInfoFromHandle[1].szAmmo2; ++j )
      CCSPlayer::FireBullet(
        this: (CCSPlayer *)iAmmoType,
        a2: (int)&fTheta1,
        a3: j,
        a4: (int)FileWeaponInfoFromHandle,
        vecSrc: *vOrigin,
        shootAngles: vAngles,
        flDistance: x0,
        iPenetration: v37,
        iBulletType: y0,
        iDamage: iPenetration,
        flRangeModifier: *(float *)&iDamage,
        pevAttacker: (CCSPlayer *)iAmmoType,
        bDoEffects: false,
        xSpread: y1[j + 13] + v35,
        ySpread: *(float *)&szFlags[4 * j + 244] + i);
    lagcompensation->FinishLagCompensation(this: lagcompensation, a2: (CBasePlayer *)iAmmoType);
  }
}

} // namespace server
