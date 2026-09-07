// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/soundent.cpp
// Functions: 30
// ============================================================

#include "game\server\soundent.h"

//------------------------------------------------------------------------------
// Address: 0x1021B8D0
// Name: public: bool CSound::FIsSound(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSound::FIsSound(CSound *this)
{
  unsigned int v1; // eax
  bool v2; // zf

  v1 = this->m_iType & 0xFFFFF;
  if ( v1 > 0x200 )
  {
    if ( (this->m_iType & 0xFFFFFu) > 0x1000 )
    {
      v2 = v1 == 0x2000;
    }
    else
    {
      if ( v1 == 4096 || v1 == 1024 )
        return 1;
      v2 = v1 == 2048;
    }
    goto LABEL_15;
  }
  if ( v1 == 512 )
    return 1;
  if ( (this->m_iType & 0xFFFFFu) > 8 )
  {
    if ( v1 == 16 )
      return 1;
    v2 = v1 == 256;
    goto LABEL_15;
  }
  if ( v1 != 8 )
  {
    if ( (this->m_iType & 0xFFFFF) == 0 )
      return 0;
    if ( (this->m_iType & 0xFFFFFu) > 2 )
    {
      v2 = v1 == 4;
LABEL_15:
      if ( !v2 )
        return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021B930
// Name: public: bool CSound::FIsScent(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSound::FIsScent(CSound *this)
{
  return this->m_iType == 32 || this->m_iType == 64 || this->m_iType == 128;
}

//------------------------------------------------------------------------------
// Address: 0x1021B950
// Name: private: virtual struct datamap_t __near * CSoundEnt::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSoundEnt::GetDataDescMap(CSoundEnt *this)
{
  return &CSoundEnt::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1021B960
// Name: public: virtual void CSoundEnt::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEnt::OnRestore(CSoundEnt *this)
{
  CBaseEntity::OnRestore(this);
  if ( g_pSoundEnt != nullptr )
    UTIL_Remove(oldObj: g_pSoundEnt);
  g_pSoundEnt = this;
}

//------------------------------------------------------------------------------
// Address: 0x1021B990
// Name: private: static void CSoundEnt::FreeSound(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSoundEnt::FreeSound(int iSound, int iPrevious)
{
  CSoundEnt *v2; // eax
  __int16 *p_m_iNext; // ecx

  v2 = g_pSoundEnt;
  if ( g_pSoundEnt != nullptr )
  {
    p_m_iNext = &g_pSoundEnt->m_SoundPool[iSound].m_iNext;
    if ( iPrevious == -1 )
      g_pSoundEnt->m_iActiveSound = *p_m_iNext;
    else
      g_pSoundEnt->m_SoundPool[iPrevious].m_iNext = *p_m_iNext;
    *p_m_iNext = v2->m_iFreeSound;
    v2->m_iFreeSound = iSound;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021BA10
// Name: public: static void CSoundEnt::FreeSound(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSoundEnt::FreeSound(int iSound)
{
  int m_iActiveSound; // eax
  int v2; // ecx

  if ( g_pSoundEnt != nullptr && iSound != -1 )
  {
    m_iActiveSound = g_pSoundEnt->m_iActiveSound;
    v2 = -1;
    if ( m_iActiveSound == -1 )
    {
LABEL_6:
      _Warning(a1: "Attempted to free unknown sound %d!\n", iSound);
    }
    else
    {
      while ( m_iActiveSound != iSound )
      {
        v2 = m_iActiveSound;
        m_iActiveSound = g_pSoundEnt->m_SoundPool[m_iActiveSound].m_iNext;
        if ( m_iActiveSound == -1 )
          goto LABEL_6;
      }
      CSoundEnt::FreeSound(iSound, iPrevious: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021BA70
// Name: public: static int CSoundEnt::ActiveList(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSoundEnt::ActiveList()
{
  if ( g_pSoundEnt != nullptr )
    return g_pSoundEnt->m_iActiveSound;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1021BA90
// Name: public: static class CSound __near * CSoundEnt::SoundPointerForIndex(int)
// Source: json
//------------------------------------------------------------------------------
CSound *__cdecl CSoundEnt::SoundPointerForIndex(int iIndex)
{
  if ( g_pSoundEnt == nullptr )
    return nullptr;
  if ( iIndex > 127 )
  {
    _Msg(a1: "SoundPointerForIndex() - Index too large!\n");
    return nullptr;
  }
  if ( iIndex >= 0 )
    return &g_pSoundEnt->m_SoundPool[iIndex];
  _Msg(a1: "SoundPointerForIndex() - Index < 0!\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1021BAE0
// Name: public: virtual struct datamap_t __near * CAISound::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAISound::GetDataDescMap(CAISound *this)
{
  return &CAISound::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1021BAF0
// Name: public: void CSound::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSound::Reset(CSound *this)
{
  this->m_vecOrigin = vec3_origin;
  this->m_iType = 0;
  this->m_iVolume = 0;
  this->m_iNext = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1021BB30
// Name: public: static bool CSoundEnt::InitSoundEnt(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CSoundEnt::InitSoundEnt()
{
  CWorld *WorldEntity; // eax
  CSoundEnt *v1; // eax

  WorldEntity = GetWorldEntity();
  v1 = (CSoundEnt *)CBaseEntity::Create(
                      szName: "soundent",
                      vecOrigin: &vec3_origin,
                      vecAngles: &vec3_angle,
                      pOwner: WorldEntity);
  g_pSoundEnt = v1;
  if ( v1 != nullptr )
  {
    v1->m_iEFlags |= 0x10u;
    return 1;
  }
  else
  {
    _Warning(a1: "**COULD NOT CREATE SOUNDENT**\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021BB80
// Name: public: static void CSoundEnt::ShutdownSoundEnt(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSoundEnt::ShutdownSoundEnt()
{
  if ( g_pSoundEnt != nullptr )
    g_pSoundEnt = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1021BBD0
// Name: public: int CSoundEnt::IAllocSound(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEnt::IAllocSound(CSoundEnt *this)
{
  int result; // eax

  result = this->m_iFreeSound;
  if ( result == -1 )
  {
    if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue >= 2 )
      _Msg(a1: "Free Sound List is full!\n");
    return -1;
  }
  else
  {
    this->m_iFreeSound = this->m_SoundPool[result].m_iNext;
    this->m_SoundPool[result].m_iNext = this->m_iActiveSound;
    this->m_iActiveSound = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021BC30
// Name: public: int CSoundEnt::FindOrAllocateSound(class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEnt::FindOrAllocateSound(CSoundEnt *this, CBaseEntity *pOwner, int soundChannelIndex)
{
  int result; // eax
  CSound *v4; // edi
  unsigned int m_Index; // edx
  CBaseEntity *m_pEntity; // esi

  result = this->m_iActiveSound;
  if ( result == -1 )
    return CSoundEnt::IAllocSound(this);
  while ( 1 )
  {
    v4 = &this->m_SoundPool[result];
    if ( this->m_SoundPool[result].m_ownerChannelIndex == soundChannelIndex )
    {
      m_Index = v4->m_hOwner.m_Index;
      if ( v4->m_hOwner.m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      if ( m_pEntity == pOwner )
        break;
    }
    result = this->m_SoundPool[result].m_iNext;
    if ( result == -1 )
      return CSoundEnt::IAllocSound(this);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021BCB0
// Name: public: void CSoundEnt::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEnt::Initialize(CSoundEnt *this)
{
  int maxClients; // eax
  int v3; // edi
  int v4; // ecx
  float *p_z; // eax
  int v6; // edx
  int m_iFreeSound; // ecx

  this->m_iFreeSound = 0;
  this->m_iActiveSound = -1;
  maxClients = gpGlobals->maxClients;
  v3 = 64;
  if ( maxClients > 1 )
  {
    v3 = maxClients + 32;
    if ( maxClients + 32 > 128 )
      v3 = 128;
  }
  if ( maxClients + 16 > v3 )
    _Warning(a1: "CSoundEnt pool is low on sounds due to high number of clients.\n");
  v4 = 0;
  if ( v3 > 0 )
  {
    p_z = &this->m_SoundPool[0].m_vecOrigin.z;
    do
    {
      *(Vector *)(p_z - 2) = vec3_origin;
      *(p_z - 7) = 0.0;
      *(p_z - 9) = 0.0;
      *(p_z - 8) = 0.0;
      *(p_z - 5) = 0.0;
      *((_BYTE *)p_z - 14) = 0;
      *(p_z - 6) = NAN;
      *((_WORD *)p_z - 8) = ++v4;
      p_z += 13;
    }
    while ( v4 < v3 );
  }
  *((_WORD *)&this->m_hScriptInstance + 26 * v4) = -1;
  v6 = 0;
  if ( gpGlobals->maxClients > 0 )
  {
    while ( 1 )
    {
      m_iFreeSound = this->m_iFreeSound;
      if ( m_iFreeSound == -1 )
        break;
      this->m_iFreeSound = this->m_SoundPool[m_iFreeSound].m_iNext;
      this->m_SoundPool[m_iFreeSound].m_iNext = this->m_iActiveSound;
      this->m_iActiveSound = m_iFreeSound;
      this->m_SoundPool[m_iFreeSound].m_bNoExpirationTime = true;
      if ( ++v6 >= gpGlobals->maxClients )
        return;
    }
    if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue >= 2 )
      _Msg(a1: "Free Sound List is full!\n");
    DevMsg(a1: "Could not AllocSound() for Client Reserve! (DLL)\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021BE00
// Name: public: static int CSoundEnt::ClientSoundIndex(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSoundEnt::ClientSoundIndex(edict_t *pClient)
{
  if ( pClient != nullptr )
    return pClient - gpGlobals->pEdicts - 1;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1021BEC0
// Name: public: class Vector const __near & CSound::GetSoundOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__usercall CSound::GetSoundOrigin@<eax>(CSound *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // edx
  int v3; // eax
  CEntInfo *v4; // esi
  unsigned int v5; // edx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // esi

  if ( this->m_iType >= 0 )
    return &this->m_vecOrigin;
  m_Index = this->m_hOwner.m_Index;
  if ( this->m_hOwner.m_Index == -1 )
    return &this->m_vecOrigin;
  v3 = (unsigned __int16)m_Index;
  v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v5 = HIWORD(m_Index);
  if ( v4->m_SerialNumber != v5 || v4->m_pEntity == nullptr )
    return &this->m_vecOrigin;
  v6 = v3;
  v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
  v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
  if ( v7 )
    v9 = *v8;
  else
    v9 = nullptr;
  if ( (v9->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v9, a2);
  return &v9->m_vecAbsOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x1021BF30
// Name: public: class Vector const __near & CSound::GetSoundReactOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__usercall CSound::GetSoundReactOrigin@<eax>(CSound *this@<ecx>, int a2@<ebp>)
{
  int m_iType; // edx
  unsigned int m_Index; // ecx
  CBaseEntity *v5; // esi
  CBaseEntity *v6; // eax
  CSound *v7; // ecx
  CBaseEntity *v8; // eax
  unsigned int v10; // ecx
  int v11; // eax
  CEntInfo *v12; // edx
  unsigned int v13; // ecx
  int v14; // eax
  bool v15; // zf
  CBaseEntity **v16; // eax

  m_iType = this->m_iType;
  if ( m_iType != 16 && m_iType != 1024 )
  {
    if ( (m_iType & 0x1000000) != 0 )
    {
      m_Index = this->m_hOwner.m_Index;
      if ( this->m_hOwner.m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        v5 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hOwner);
        goto LABEL_20;
      }
    }
    if ( (m_iType & 8) != 0 && (m_iType & 0x100000) != 0 )
    {
      v6 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hOwner);
      v7 = this;
      if ( v6 != nullptr )
      {
        v8 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hOwner);
        return CBaseEntity::GetAbsOrigin(this: v8);
      }
      return CSound::GetSoundOrigin(this: v7, a2);
    }
LABEL_12:
    v7 = this;
    return CSound::GetSoundOrigin(this: v7, a2);
  }
  v10 = this->m_hOwner.m_Index;
  if ( this->m_hOwner.m_Index == -1 )
    goto LABEL_12;
  v11 = (unsigned __int16)v10;
  v12 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v10];
  v13 = HIWORD(v10);
  if ( v12->m_SerialNumber != v13 || v12->m_pEntity == nullptr )
    goto LABEL_12;
  v14 = v11;
  v15 = g_pEntityList->m_EntPtrArray[v14].m_SerialNumber == v13;
  v16 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v14];
  if ( v15 )
    v5 = *v16;
  else
    v5 = nullptr;
LABEL_20:
  if ( (v5->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v5, a2);
  return &v5->m_vecAbsOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x1021C010
// Name: public: virtual void CSoundEnt::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEnt::Spawn(CSoundEnt *this)
{
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CSoundEnt::Initialize(this);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1021C050
// Name: public: virtual void CSoundEnt::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEnt::Think(CSoundEnt *this)
{
  int m_iActiveSound; // eax
  CSoundEnt *v3; // edi
  int v4; // ecx
  float curtime; // xmm0_4
  bool v6; // cf
  CSound *v7; // esi
  unsigned int m_Index; // eax
  int v9; // esi
  int v10; // eax
  bool v11; // zf
  bool v12; // al
  int m_nValue; // ecx
  float m_iVolume; // xmm0_4
  const Vector *SoundOrigin; // eax
  int v16; // edi
  const Vector *v17; // eax
  float v18; // xmm0_4
  const Vector *v19; // eax
  const Vector *v20; // eax
  float v21; // xmm0_4
  const Vector *v22; // eax
  const Vector *v23; // eax
  float v24; // xmm0_4
  const Vector *v25; // eax
  const Vector *v26; // eax
  float v27; // xmm0_4
  const Vector *v28; // eax
  const Vector *v29; // eax
  float v30; // xmm0_4
  const Vector *v31; // eax
  const Vector *v32; // eax
  float m_flOcclusionScale; // xmm1_4
  float v34; // xmm0_4
  const Vector *v35; // eax
  const Vector *v36; // eax
  float v37; // xmm0_4
  const Vector *v38; // eax
  const Vector *v39; // eax
  float v40; // xmm0_4
  const Vector *v41; // eax
  const Vector *v42; // eax
  float v43; // xmm0_4
  const Vector *v44; // eax
  const Vector *v45; // eax
  float v46; // xmm0_4
  const Vector *v47; // eax
  const Vector *v48; // eax
  float v49; // xmm0_4
  const Vector *v50; // eax
  const Vector *v51; // eax
  int m_iNext; // eax
  int v53; // edx
  int v54; // ecx
  int m_iFreeSound; // eax
  int v56; // esi
  int v57; // ecx
  int v58; // eax
  int i; // ecx
  int v60; // eax
  int j; // ecx
  int v62; // ecx
  int v63; // [esp+0h] [ebp-170h]
  Vector v64; // [esp+1Ch] [ebp-154h] BYREF
  Vector v65; // [esp+28h] [ebp-148h] BYREF
  Vector v66; // [esp+34h] [ebp-13Ch] BYREF
  Vector v67; // [esp+40h] [ebp-130h] BYREF
  Vector v68; // [esp+4Ch] [ebp-124h] BYREF
  Vector v69; // [esp+58h] [ebp-118h] BYREF
  Vector v70; // [esp+64h] [ebp-10Ch] BYREF
  Vector v71; // [esp+70h] [ebp-100h] BYREF
  Vector v72; // [esp+7Ch] [ebp-F4h] BYREF
  Vector v73; // [esp+88h] [ebp-E8h] BYREF
  Vector v74; // [esp+94h] [ebp-DCh] BYREF
  Vector target; // [esp+A0h] [ebp-D0h] BYREF
  float v76; // [esp+ACh] [ebp-C4h]
  float v77; // [esp+B0h] [ebp-C0h]
  float v78; // [esp+B4h] [ebp-BCh]
  float v79; // [esp+B8h] [ebp-B8h]
  float v80; // [esp+BCh] [ebp-B4h]
  float v81; // [esp+C0h] [ebp-B0h]
  float v82; // [esp+C4h] [ebp-ACh]
  float v83; // [esp+C8h] [ebp-A8h]
  float v84; // [esp+CCh] [ebp-A4h]
  float v85; // [esp+D0h] [ebp-A0h]
  float v86; // [esp+D4h] [ebp-9Ch]
  float v87; // [esp+D8h] [ebp-98h]
  float v88; // [esp+DCh] [ebp-94h]
  float v89; // [esp+E0h] [ebp-90h]
  float v90; // [esp+E4h] [ebp-8Ch]
  float v91; // [esp+E8h] [ebp-88h]
  float v92; // [esp+ECh] [ebp-84h]
  float v93; // [esp+F0h] [ebp-80h]
  float v94; // [esp+F4h] [ebp-7Ch]
  float v95; // [esp+F8h] [ebp-78h]
  float v96; // [esp+FCh] [ebp-74h]
  float v97; // [esp+100h] [ebp-70h]
  float v98; // [esp+104h] [ebp-6Ch]
  float v99; // [esp+108h] [ebp-68h]
  float v100; // [esp+10Ch] [ebp-64h]
  float v101; // [esp+110h] [ebp-60h]
  float v102; // [esp+114h] [ebp-5Ch]
  float v103; // [esp+118h] [ebp-58h]
  float v104; // [esp+11Ch] [ebp-54h]
  float v105; // [esp+120h] [ebp-50h]
  float v106; // [esp+124h] [ebp-4Ch]
  float v107; // [esp+128h] [ebp-48h]
  float v108; // [esp+12Ch] [ebp-44h]
  float v109; // [esp+130h] [ebp-40h]
  float v110; // [esp+134h] [ebp-3Ch]
  float v111; // [esp+138h] [ebp-38h]
  int iPreviousSound; // [esp+13Ch] [ebp-34h]
  Vector right; // [esp+140h] [ebp-30h] BYREF
  Vector up; // [esp+14Ch] [ebp-24h] BYREF
  Vector forward; // [esp+158h] [ebp-18h] BYREF
  int v116; // [esp+164h] [ebp-Ch]
  int iSound; // [esp+168h] [ebp-8h]
  unsigned __int8 g; // [esp+16Fh] [ebp-1h]
  int savedregs; // [esp+170h] [ebp+0h] BYREF

  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  m_iActiveSound = this->m_iActiveSound;
  iPreviousSound = -1;
  iSound = m_iActiveSound;
  if ( m_iActiveSound != -1 )
  {
    v3 = g_pSoundEnt;
    do
    {
      v4 = 52 * iSound;
      curtime = gpGlobals->curtime;
      v6 = curtime < this->m_SoundPool[iSound].m_flExpireTime;
      v116 = 52 * iSound;
      if ( v6 || *(&this->m_SoundPool[0].m_bNoExpirationTime + v4) )
      {
        v7 = (CSound *)((char *)this->m_SoundPool + v4);
        if ( !*(&this->m_SoundPool[0].m_bHasOwner + v4) )
          goto LABEL_24;
        m_Index = v7->m_hOwner.m_Index;
        if ( v7->m_hOwner.m_Index != -1 )
        {
          if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
          {
            v4 = v116;
LABEL_24:
            if ( displaysoundlist.m_pParent != nullptr && displaysoundlist.m_pParent->m_Value.m_nValue != 0 )
            {
              this->GetVectors(this, a2: &forward, a3: &right, a4: &up);
              v12 = (v7->m_iType & 8) != 0;
              v11 = (v7->m_iType & 8) == 0;
              g = -1;
              if ( !v11 )
                g = 0;
              if ( displaysoundlist.m_pParent != nullptr )
              {
                m_nValue = displaysoundlist.m_pParent->m_Value.m_nValue;
                if ( m_nValue == 1 || m_nValue == 2 && v12 )
                {
                  m_iVolume = (float)v7->m_iVolume;
                  v94 = forward.x * m_iVolume;
                  v95 = forward.y * m_iVolume;
                  v96 = forward.z * m_iVolume;
                  SoundOrigin = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                  v16 = g;
                  target.x = SoundOrigin->x + v94;
                  target.y = SoundOrigin->y + v95;
                  target.z = SoundOrigin->z + v96;
                  v63 = g;
                  v17 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                  NDebugOverlay::Line(origin: v17, &target, r: 255, g: v63, b: 0, noDepthTest: 0, duration: 0.1);
                  v18 = (float)v7->m_iVolume;
                  v103 = forward.x * v18;
                  v104 = forward.y * v18;
                  v105 = forward.z * v18;
                  v19 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                  v73.x = v19->x - v103;
                  v73.y = v19->y - v104;
                  v73.z = v19->z - v105;
                  v20 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                  NDebugOverlay::Line(origin: v20, target: &v73, r: 255, g: v16, b: 0, noDepthTest: 0, duration: 0.1);
                  v21 = (float)v7->m_iVolume;
                  v79 = right.x * v21;
                  v80 = right.y * v21;
                  v81 = right.z * v21;
                  v22 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                  v65.x = v22->x + v79;
                  v65.y = v22->y + v80;
                  v65.z = v22->z + v81;
                  v23 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                  NDebugOverlay::Line(origin: v23, target: &v65, r: 255, g: v16, b: 0, noDepthTest: 0, duration: 0.1);
                  v24 = (float)v7->m_iVolume;
                  v97 = right.x * v24;
                  v98 = right.y * v24;
                  v99 = right.z * v24;
                  v25 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                  v71.x = v25->x - v97;
                  v71.y = v25->y - v98;
                  v71.z = v25->z - v99;
                  v26 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                  NDebugOverlay::Line(origin: v26, target: &v71, r: 255, g: v16, b: 0, noDepthTest: 0, duration: 0.1);
                  v27 = (float)v7->m_iVolume;
                  v85 = up.x * v27;
                  v86 = up.y * v27;
                  v87 = up.z * v27;
                  v28 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                  v67.x = v85 + v28->x;
                  v67.y = v28->y + v86;
                  v67.z = v28->z + v87;
                  v29 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                  NDebugOverlay::Line(origin: v29, target: &v67, r: 255, g: v16, b: 0, noDepthTest: 0, duration: 0.1);
                  v30 = (float)v7->m_iVolume;
                  v91 = up.x * v30;
                  v92 = up.y * v30;
                  v93 = up.z * v30;
                  v31 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                  v69.x = v31->x - v91;
                  v69.y = v31->y - v92;
                  v69.z = v31->z - v93;
                  v32 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                  NDebugOverlay::Line(origin: v32, target: &v69, r: 255, g: v16, b: 0, noDepthTest: 0, duration: 0.1);
                  m_flOcclusionScale = v7->m_flOcclusionScale;
                  if ( m_flOcclusionScale != 1.0 )
                  {
                    v34 = (float)v7->m_iVolume * m_flOcclusionScale;
                    v106 = v34 * forward.x;
                    v107 = forward.y * v34;
                    v108 = forward.z * v34;
                    v35 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                    v74.x = v35->x + v106;
                    v74.y = v35->y + v107;
                    v74.z = v35->z + v108;
                    v36 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                    NDebugOverlay::Line(origin: v36, target: &v74, r: 0, g: 150, b: 255, noDepthTest: 0, duration: 0.1);
                    v37 = (float)v7->m_iVolume * v7->m_flOcclusionScale;
                    v100 = v37 * forward.x;
                    v101 = forward.y * v37;
                    v102 = forward.z * v37;
                    v38 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                    v72.x = v38->x - v100;
                    v72.y = v38->y - v101;
                    v72.z = v38->z - v102;
                    v39 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                    NDebugOverlay::Line(origin: v39, target: &v72, r: 0, g: 150, b: 255, noDepthTest: 0, duration: 0.1);
                    v40 = (float)v7->m_iVolume * v7->m_flOcclusionScale;
                    v109 = v40 * right.x;
                    v110 = right.y * v40;
                    v111 = right.z * v40;
                    v41 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                    v70.x = v109 + v41->x;
                    v70.y = v41->y + v110;
                    v70.z = v41->z + v111;
                    v42 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                    NDebugOverlay::Line(origin: v42, target: &v70, r: 0, g: 150, b: 255, noDepthTest: 0, duration: 0.1);
                    v43 = (float)v7->m_iVolume * v7->m_flOcclusionScale;
                    v88 = v43 * right.x;
                    v89 = right.y * v43;
                    v90 = right.z * v43;
                    v44 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                    v68.x = v44->x - v88;
                    v68.y = v44->y - v89;
                    v68.z = v44->z - v90;
                    v45 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                    NDebugOverlay::Line(origin: v45, target: &v68, r: 0, g: 150, b: 255, noDepthTest: 0, duration: 0.1);
                    v46 = (float)v7->m_iVolume * v7->m_flOcclusionScale;
                    v82 = v46 * up.x;
                    v83 = up.y * v46;
                    v84 = up.z * v46;
                    v47 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                    v66.x = v47->x + v82;
                    v66.y = v47->y + v83;
                    v66.z = v47->z + v84;
                    v48 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                    NDebugOverlay::Line(origin: v48, target: &v66, r: 0, g: 150, b: 255, noDepthTest: 0, duration: 0.1);
                    v49 = (float)v7->m_iVolume * v7->m_flOcclusionScale;
                    v76 = v49 * up.x;
                    v77 = up.y * v49;
                    v78 = up.z * v49;
                    v50 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                    v64.x = v50->x - v76;
                    v64.y = v50->y - v77;
                    v64.z = v50->z - v78;
                    v51 = CSound::GetSoundOrigin(this: v7, a2: (int)&savedregs);
                    NDebugOverlay::Line(origin: v51, target: &v64, r: 0, g: 150, b: 255, noDepthTest: 0, duration: 0.1);
                  }
                }
              }
              m_iNext = this->m_iActiveSound;
              if ( m_iNext == -1 )
              {
                v53 = 0;
              }
              else
              {
                v54 = 0;
                do
                {
                  m_iNext = this->m_SoundPool[m_iNext].m_iNext;
                  ++v54;
                }
                while ( m_iNext != -1 );
                v53 = v54;
              }
              m_iFreeSound = this->m_iFreeSound;
              if ( m_iFreeSound == -1 )
              {
                v56 = 0;
              }
              else
              {
                v57 = 0;
                do
                {
                  m_iFreeSound = this->m_SoundPool[m_iFreeSound].m_iNext;
                  ++v57;
                }
                while ( m_iFreeSound != -1 );
                v56 = v57;
              }
              v58 = this->m_iActiveSound;
              for ( i = 0; v58 != -1; ++i )
                v58 = this->m_SoundPool[v58].m_iNext;
              _DevMsg(a1: 2, a2: "Soundlist: %d / %d  (%d)\n", i, v56, v53 - this->m_cLastActiveSounds);
              v60 = this->m_iActiveSound;
              for ( j = 0; v60 != -1; ++j )
                v60 = this->m_SoundPool[v60].m_iNext;
              v3 = g_pSoundEnt;
              this->m_cLastActiveSounds = j;
              v4 = v116;
            }
            v62 = *(__int16 *)((char *)&this->m_SoundPool[0].m_iNext + v4);
            iPreviousSound = iSound;
            iSound = v62;
            continue;
          }
          v4 = v116;
        }
      }
      v9 = *(__int16 *)((char *)&this->m_SoundPool[0].m_iNext + v4);
      if ( displaysoundlist.m_pParent != nullptr )
      {
        if ( displaysoundlist.m_pParent->m_Value.m_nValue == 1 )
        {
          _Msg(a1: "  Removed Sound: %d (Time:%f)\n", *(int *)((char *)&this->m_SoundPool[0].m_iType + v4), curtime);
          v3 = g_pSoundEnt;
          v4 = v116;
        }
        if ( displaysoundlist.m_pParent != nullptr
          && displaysoundlist.m_pParent->m_Value.m_nValue == 2
          && (*(int *)((_BYTE *)&this->m_SoundPool[0].m_iType + v4) & 8) != 0 )
        {
          _Msg(
            a1: "  Removed Danger Sound: %d (time:%f)\n",
            *(int *)((char *)&this->m_SoundPool[0].m_iType + v4),
            gpGlobals->curtime);
          v3 = g_pSoundEnt;
          v4 = v116;
        }
      }
      if ( v3 != nullptr )
      {
        if ( iPreviousSound == -1 )
          v3->m_iActiveSound = *(__int16 *)((char *)&v3->m_SoundPool[0].m_iNext + v4);
        else
          v3->m_SoundPool[iPreviousSound].m_iNext = *(__int16 *)((char *)&v3->m_SoundPool[0].m_iNext + v4);
        v10 = iSound;
        *(__int16 *)((char *)&v3->m_SoundPool[0].m_iNext + v4) = v3->m_iFreeSound;
        v3->m_iFreeSound = v10;
      }
      iSound = v9;
    }
    while ( iSound != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021CB50
// Name: public: static int CSoundEnt::InsertSound(int,class Vector const __near &,int,float,class CBaseEntity __near *,int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSoundEnt::InsertSound(
        int iType,
        const Vector *vecOrigin,
        int iVolume,
        float flDuration,
        CBaseEntity *pOwner,
        int soundChannelIndex,
        CBaseEntity *pSoundTarget)
{
  int Sound; // eax
  CSound *v9; // esi
  float v10; // xmm0_4
  ConVar *m_pParent; // eax
  int iThisSound; // [esp+1Ch] [ebp-4h]

  if ( g_pSoundEnt == nullptr )
    return -1;
  if ( soundChannelIndex != 0 )
    Sound = CSoundEnt::FindOrAllocateSound(this: g_pSoundEnt, pOwner, soundChannelIndex);
  else
    Sound = CSoundEnt::IAllocSound(this: g_pSoundEnt);
  iThisSound = Sound;
  if ( Sound == -1 )
  {
    DevMsg(a1: "Could not AllocSound() for InsertSound() (Game DLL)\n");
    return -1;
  }
  else
  {
    v9 = &g_pSoundEnt->m_SoundPool[Sound];
    v9->m_vecOrigin = *vecOrigin;
    v9->m_flOcclusionScale = 0.5;
    v10 = 3.4028235e38;
    v9->m_iVolume = iVolume;
    v9->m_iType = iType;
    if ( flDuration == 3.4028235e38 )
    {
      v9->m_bNoExpirationTime = true;
    }
    else
    {
      v10 = gpGlobals->curtime + flDuration;
      v9->m_bNoExpirationTime = false;
    }
    v9->m_flExpireTime = v10;
    if ( pOwner != nullptr )
      v9->m_hOwner.m_Index = pOwner->GetRefEHandle(this: pOwner)->m_Index;
    else
      v9->m_hOwner.m_Index = -1;
    if ( pSoundTarget != nullptr )
      v9->m_hTarget.m_Index = pSoundTarget->GetRefEHandle(this: pSoundTarget)->m_Index;
    else
      v9->m_hTarget.m_Index = -1;
    v9->m_ownerChannelIndex = soundChannelIndex;
    v9->m_bHasOwner = pOwner != nullptr;
    m_pParent = displaysoundlist.m_pParent;
    if ( displaysoundlist.m_pParent != nullptr )
    {
      if ( displaysoundlist.m_pParent->m_Value.m_nValue == 1 )
      {
        _Msg(a1: "  Added Sound! Type:%d  Duration:%f (Time:%f)\n", v9->m_iType, flDuration, gpGlobals->curtime);
        m_pParent = displaysoundlist.m_pParent;
      }
      if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue == 2 && (iType & 8) != 0 )
        _Msg(a1: "  Added Danger Sound! Duration:%f (Time:%f)\n", flDuration, gpGlobals->curtime);
    }
    return iThisSound;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021CCF0
// Name: public: void CAISound::InputInsertSound(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAISound::InputInsertSound(CAISound *this, inputdata_t *inputdata)
{
  const char *pszValue; // ebx
  const char *v4; // eax
  float z; // ecx
  CBasePlayer *EntityByName; // eax
  CBasePlayer *v7; // edi
  const char *v8; // eax
  Vector vecLocation; // [esp+18h] [ebp-Ch] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v4 = this->m_iszProxyEntityName.pszValue;
  z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&vecLocation.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  vecLocation.z = z;
  if ( v4 != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: v4,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    v7 = EntityByName;
    if ( EntityByName != nullptr )
    {
      if ( (EntityByName->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
      vecLocation = v7->m_vecAbsOrigin;
    }
    else
    {
      v8 = this->m_iszProxyEntityName.pszValue;
      if ( v8 == nullptr )
        v8 = locale;
      DevWarning(a1: "Warning- ai_sound cannot find proxy entity named '%s'. Using self.\n", v8);
    }
  }
  CSoundEnt::InsertSound(
    iType: this->m_iSoundType,
    vecOrigin: &vecLocation,
    iVolume: (int)pszValue,
    flDuration: this->m_flDuration,
    pOwner: this,
    soundChannelIndex: 0,
    pSoundTarget: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1021CDF0
// Name: public: void CAISound::InputEmitAISound(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAISound::InputEmitAISound(CAISound *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  float z; // ecx
  CBasePlayer *EntityByName; // eax
  CBasePlayer *v6; // edi
  const char *v7; // eax
  Vector vecLocation; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  pszValue = this->m_iszProxyEntityName.pszValue;
  z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&vecLocation.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  vecLocation.z = z;
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
    v6 = EntityByName;
    if ( EntityByName != nullptr )
    {
      if ( (EntityByName->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
      vecLocation = v6->m_vecAbsOrigin;
    }
    else
    {
      v7 = this->m_iszProxyEntityName.pszValue;
      if ( v7 == nullptr )
        v7 = locale;
      DevWarning(a1: "Warning- ai_sound cannot find proxy entity named '%s'. Using self.\n", v7);
    }
  }
  CSoundEnt::InsertSound(
    iType: this->m_iSoundType | this->m_iSoundContext,
    vecOrigin: &vecLocation,
    iVolume: this->m_iVolume,
    flDuration: this->m_flDuration,
    pOwner: this,
    soundChannelIndex: 0,
    pSoundTarget: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1040A0F0
// Name: _dynamic_initializer_for__soundent__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundent__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSoundEnt> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &soundent,
           a3: "soundent");
}

//------------------------------------------------------------------------------
// Address: 0x1040A110
// Name: CSound_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSound_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSound>();
  CSound_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A120
// Name: CSoundEnt_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSoundEnt_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSoundEnt>();
  CSoundEnt_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A150
// Name: CAISound_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAISound_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAISound>();
  CAISound_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021CEE0
// Name: class CSoundEnt __near * _CreateEntityTemplate<class CSoundEnt>(class CSoundEnt __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSoundEnt *__cdecl _CreateEntityTemplate<CSoundEnt>(CSoundEnt *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi
  _DWORD *v4; // eax
  int i; // ecx

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x1D60u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CSoundEnt::`vftable';
    v4 = &v3[1].m_Network.__vftable;
    for ( i = 127; i >= 0; --i )
    {
      *v4 = -1;
      v4[1] = -1;
      v4 += 13;
    }
    v3->PostConstructor(this: v3, a2: className);
    return (CSoundEnt *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040A130
// Name: _dynamic_initializer_for__ai_sound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_sound__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAISound> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_sound,
           a3: "ai_sound");
}

//------------------------------------------------------------------------------
// Address: 0x1040A160
// Name: _dynamic_initializer_for__soundpatch_captionlength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundpatch_captionlength__()
{
  ConVar::ConVar(
    this: &soundpatch_captionlength,
    pName: "soundpatch_captionlength",
    pDefaultValue: "2.0",
    flags: 0x2000,
    pHelpString: "How long looping soundpatch captions should display for.");
  return atexit(func: dynamic_atexit_destructor_for__soundpatch_captionlength__);
}
