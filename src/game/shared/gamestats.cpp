// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/gamestats.cpp
// Functions: 27
// ============================================================

#include "game\shared\gamestats.h"

//------------------------------------------------------------------------------
// Address: 0x100E8970
// Name: public: void CBaseGameStats_Driver::UpdatePerfStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::UpdatePerfStats(CBaseGameStats_Driver *this)
{
  float m_flLastSampleTime; // xmm1_4
  float v3; // xmm0_4
  float m_flLastRealTime; // xmm1_4
  IGameResources *v5; // edi
  int v6; // ebx
  vgui::CTreeViewListControl *v7; // ecx
  int v8; // eax
  C_BasePlayer *LocalPlayer; // eax
  IGameResources_vtbl *v10; // ebx
  int v11; // eax
  vgui::CTreeViewListControl *v12; // ecx
  int v13; // edi
  int v14; // [esp+0h] [ebp-10h]
  StatsBufferRecord_t *stat; // [esp+8h] [ebp-8h]
  float flCurTime; // [esp+Ch] [ebp-4h]

  flCurTime = _Plat_FloatTime(a1: v14);
  m_flLastSampleTime = this->m_flLastSampleTime;
  v3 = flCurTime;
  if ( m_flLastSampleTime == -1.0 || (float)(flCurTime - m_flLastSampleTime) >= 1.0 )
  {
    m_flLastRealTime = this->m_flLastRealTime;
    if ( m_flLastRealTime > 0.0 && flCurTime > m_flLastRealTime )
    {
      stat = &this->m_StatsBuffer[this->m_nWriteIndex];
      stat->m_flFrameRate = 1.0 / (float)(flCurTime - m_flLastRealTime);
      v5 = GameResources();
      v6 = 0;
      v8 = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v7);
      LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: v8);
      if ( LocalPlayer != nullptr && v5 != nullptr )
      {
        v10 = v5->__vftable;
        v11 = LocalPlayer->entindex(this: &LocalPlayer->IClientNetworkable);
        v6 = v10->GetPing(this: v5, a2: v11);
      }
      stat->m_flServerPing = (float)v6;
      if ( ++this->m_nWriteIndex == 600 )
      {
        this->m_nWriteIndex = 0;
        this->m_bBufferFull = true;
      }
      v3 = flCurTime;
      this->m_flLastSampleTime = flCurTime;
    }
  }
  this->m_flLastRealTime = v3;
  if ( g_pGameRules != nullptr && g_pGameRules->IsMultiplayer(this: g_pGameRules) )
  {
    v13 = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v12);
    this->m_bDidVoiceChat |= GetClientVoiceMgr()->m_bTalking[v13];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8AB0
// Name: void UpdatePerfStats(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdatePerfStats()
{
  CBaseGameStats_Driver::UpdatePerfStats(this: &CBGSDriver);
}

//------------------------------------------------------------------------------
// Address: 0x100E8AC0
// Name: public: virtual class CBaseGameStats __near * CBaseGameStats::OnInit(class CBaseGameStats __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseGameStats *__thiscall CBaseGameStats::OnInit(
        CBaseGameStats *this,
        CBaseGameStats *pCurrentGameStats,
        const char *gamedir)
{
  return pCurrentGameStats;
}

//------------------------------------------------------------------------------
// Address: 0x100E8AD0
// Name: public: void CBaseGameStats::StatsLog(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseGameStats::StatsLog(CBaseGameStats *this, const char *fmt, ...)
{
  const tm *v2; // eax
  char *v3; // eax
  _BYTE *v4; // eax
  void (__cdecl *m_ProxyFn)(const CRecvProxyData *, void *, void *); // eax
  char buf[2048]; // [esp+1Ch] [ebp-888h] BYREF
  char timeString[128]; // [esp+81Ch] [ebp-88h] BYREF
  __int64 aclock; // [esp+89Ch] [ebp-8h] BYREF
  va_list params; // [esp+8B4h] [ebp+10h] BYREF

  va_start(params, fmt);
  if ( (*((_BYTE *)this + 4) & 3) != 0 )
  {
    V_vsnprintf(pDest: buf, maxLen: 0x800u, pFormat: fmt, params);
    _time64(timeptr: &aclock);
    v2 = _localtime64(ptime: &aclock);
    v3 = asctime(tb: v2);
    V_strncpy(pDest: timeString, pSrc: v3, maxLen: 128);
    strstr(str1: (unsigned __int8 *)timeString, str2: "\n");
    if ( v4 != nullptr )
      *v4 = 0;
    if ( (*((_BYTE *)this + 4) & 1) != 0 )
      DevMsg(a1: "[GS %s - %7.2f] %s", timeString, *(float *)gpGlobals.m_Index, buf);
    if ( (*((_BYTE *)this + 4) & 2) != 0 )
    {
      m_ProxyFn = _S5_99.m_ProxyFn;
      if ( _S5_99.m_ProxyFn != nullptr
        || (m_ProxyFn = (void (__cdecl *)(const CRecvProxyData *, void *, void *))filesystem->Open(
                                                                                    this: &filesystem->IBaseFileSystem,
                                                                                    a2: "gamestats.log",
                                                                                    a3: "a",
                                                                                    a4: "MOD"),
            _S5_99.m_ProxyFn = m_ProxyFn,
            m_ProxyFn != nullptr) )
      {
        filesystem->FPrintf(
          this: filesystem,
          a2: m_ProxyFn,
          a3: "[GS %s - %7.2f] %s",
          timeString,
          *(float *)gpGlobals.m_Index,
          buf);
        filesystem->Flush(this: &filesystem->IBaseFileSystem, a2: _S5_99.m_ProxyFn);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8C20
// Name: public: virtual char const __near * CBaseGameStats::GetStatSaveFileName(void)
// Source: json
//------------------------------------------------------------------------------
void (__cdecl **__thiscall CBaseGameStats::GetStatSaveFileName(
        CBaseGameStats *this))(const RecvProp *, void **, void *, int)
{
  return &_S5_99.m_DataTableProxyFn;
}

//------------------------------------------------------------------------------
// Address: 0x100E8C30
// Name: public: virtual char const __near * CBaseGameStats::GetStatUploadRegistryKeyName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseGameStats::GetStatUploadRegistryKeyName(CBaseGameStats *this)
{
  return s_szStatUploadRegistryKeyName;
}

//------------------------------------------------------------------------------
// Address: 0x100E8C40
// Name: public: virtual void CBaseGameStats::Event_MapChange(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_MapChange(
        CBaseGameStats *this,
        const char *szOldMapName,
        const char *szNewMapName)
{
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_MapChange to [%s]\n", szNewMapName);
}

//------------------------------------------------------------------------------
// Address: 0x100E8C60
// Name: public: virtual void CBaseGameStats_Driver::OnSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::OnSave(CBaseGameStats_Driver *this)
{
  gamestats->Event_SaveGame(this: gamestats);
}

//------------------------------------------------------------------------------
// Address: 0x100E8C70
// Name: public: virtual void CBaseGameStats_Driver::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::OnRestore(CBaseGameStats_Driver *this)
{
  gamestats->Event_LoadGame(this: gamestats);
}

//------------------------------------------------------------------------------
// Address: 0x100E8C80
// Name: public: virtual void CBaseGameStats_Driver::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::FrameUpdatePostEntityThink(CBaseGameStats_Driver *this)
{
  bool v2; // bl
  double v3; // st7
  float m_flPauseStartTime; // xmm3_4
  float v5; // xmm0_4

  v2 = *(float *)(gpGlobals.m_Index + 16) == 0.0;
  if ( this->m_bInLevel )
  {
    if ( this->m_bGamePaused != v2 )
    {
      if ( *(float *)(gpGlobals.m_Index + 16) == 0.0 )
      {
        v3 = *(float *)gpGlobals.m_Index;
        this->m_bGamePaused = v2;
        this->m_flPauseStartTime = v3;
      }
      else
      {
        m_flPauseStartTime = this->m_flPauseStartTime;
        if ( m_flPauseStartTime != 0.0 )
        {
          v5 = *(float *)gpGlobals.m_Index - m_flPauseStartTime;
          if ( v5 < 0.0 )
          {
            _Warning(
              a1: "Game paused time showing up negative (rt %f pausestart %f)\n",
              *(float *)gpGlobals.m_Index,
              m_flPauseStartTime);
            v5 = 0.0;
          }
          this->m_flLevelStartTime = this->m_flLevelStartTime + v5;
          this->m_flPauseStartTime = 0.0;
        }
        this->m_bGamePaused = false;
      }
    }
  }
  else
  {
    this->m_flPauseStartTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8D50
// Name: void OverWriteCharsWeHate(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OverWriteCharsWeHate(char *pStr)
{
  char *i; // eax

  for ( i = pStr; *i != 0; ++i )
  {
    switch ( *i )
    {
      case 10:
      case 13:
      case 26:
      case 34:
      case 39:
      case 59:
      case 92:
        *i = 32;
        break;
      default:
        continue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8DE0
// Name: public: float CBaseGameStats_Driver::AverageStat<float>(float __near StatsBufferRecord_t::*)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseGameStats_Driver::AverageStat<float>(CBaseGameStats_Driver *this, int a2, int a3, int a4)
{
  float v4; // xmm0_4
  int m_nWriteIndex; // esi
  int v6; // edi
  unsigned int v7; // edx
  float *v8; // eax
  float *v9; // eax
  int v10; // esi
  int iMax; // [esp+0h] [ebp-8h]
  float sum; // [esp+4h] [ebp-4h]

  v4 = 0.0;
  sum = 0.0;
  m_nWriteIndex = 600;
  if ( !this->m_bBufferFull )
    m_nWriteIndex = this->m_nWriteIndex;
  v6 = 0;
  iMax = m_nWriteIndex;
  if ( m_nWriteIndex >= 4 )
  {
    v7 = ((unsigned int)(m_nWriteIndex - 4) >> 2) + 1;
    v8 = (float *)((char *)&this->m_StatsBuffer[1].m_flFrameRate + a2);
    v6 = 4 * v7;
    do
    {
      v4 = (float)((float)((float)(v4 + *(v8 - 2)) + *v8) + v8[2]) + v8[4];
      v8 += 8;
      --v7;
    }
    while ( v7 != 0 );
    sum = v4;
  }
  if ( v6 < m_nWriteIndex )
  {
    v9 = (float *)((char *)&this->m_StatsBuffer[v6].m_flFrameRate + a2);
    v10 = m_nWriteIndex - v6;
    do
    {
      v4 = v4 + *v9;
      v9 += 2;
      --v10;
    }
    while ( v10 != 0 );
    sum = v4;
  }
  return sum / (double)iMax;
}

//------------------------------------------------------------------------------
// Address: 0x100E8E80
// Name: public: float CBaseGameStats_Driver::MinStat<float>(float __near StatsBufferRecord_t::*)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseGameStats_Driver::MinStat<float>(CBaseGameStats_Driver *this, int a2, int a3, int a4)
{
  float v4; // xmm0_4
  int m_nWriteIndex; // edx
  int v6; // edi
  unsigned int v7; // eax
  float *v8; // esi
  float *v9; // eax
  int v10; // edx
  float minsofar; // [esp+0h] [ebp-4h]

  v4 = 16000000.0;
  minsofar = 16000000.0;
  m_nWriteIndex = 600;
  if ( !this->m_bBufferFull )
    m_nWriteIndex = this->m_nWriteIndex;
  v6 = 0;
  if ( m_nWriteIndex >= 4 )
  {
    v7 = ((unsigned int)(m_nWriteIndex - 4) >> 2) + 1;
    v8 = (float *)((char *)&this->m_StatsBuffer[1].m_flFrameRate + a2);
    v6 = 4 * v7;
    do
    {
      if ( *(v8 - 2) <= v4 )
        v4 = *(v8 - 2);
      if ( *v8 <= v4 )
        v4 = *v8;
      if ( v8[2] <= v4 )
        v4 = v8[2];
      if ( v8[4] <= v4 )
        v4 = v8[4];
      v8 += 8;
      --v7;
    }
    while ( v7 != 0 );
    minsofar = v4;
  }
  if ( v6 < m_nWriteIndex )
  {
    v9 = (float *)((char *)&this->m_StatsBuffer[v6].m_flFrameRate + a2);
    v10 = m_nWriteIndex - v6;
    do
    {
      if ( *v9 <= v4 )
      {
        v4 = *v9;
        minsofar = *v9;
      }
      v9 += 2;
      --v10;
    }
    while ( v10 != 0 );
  }
  return minsofar;
}

//------------------------------------------------------------------------------
// Address: 0x100E8F40
// Name: public: float CBaseGameStats_Driver::MaxStat<float>(float __near StatsBufferRecord_t::*)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseGameStats_Driver::MaxStat<float>(CBaseGameStats_Driver *this, int a2, int a3, int a4)
{
  float v4; // xmm0_4
  int m_nWriteIndex; // edx
  int v6; // edi
  unsigned int v7; // eax
  float *v8; // esi
  float *v9; // eax
  int v10; // edx
  float maxsofar; // [esp+0h] [ebp-4h]

  v4 = -16000000.0;
  maxsofar = -16000000.0;
  m_nWriteIndex = 600;
  if ( !this->m_bBufferFull )
    m_nWriteIndex = this->m_nWriteIndex;
  v6 = 0;
  if ( m_nWriteIndex >= 4 )
  {
    v7 = ((unsigned int)(m_nWriteIndex - 4) >> 2) + 1;
    v8 = (float *)((char *)&this->m_StatsBuffer[1].m_flFrameRate + a2);
    v6 = 4 * v7;
    do
    {
      if ( v4 <= *(v8 - 2) )
        v4 = *(v8 - 2);
      if ( v4 <= *v8 )
        v4 = *v8;
      if ( v4 <= v8[2] )
        v4 = v8[2];
      if ( v4 <= v8[4] )
        v4 = v8[4];
      v8 += 8;
      --v7;
    }
    while ( v7 != 0 );
    maxsofar = v4;
  }
  if ( v6 < m_nWriteIndex )
  {
    v9 = (float *)((char *)&this->m_StatsBuffer[v6].m_flFrameRate + a2);
    v10 = m_nWriteIndex - v6;
    do
    {
      if ( v4 <= *v9 )
      {
        v4 = *v9;
        maxsofar = *v9;
      }
      v9 += 2;
      --v10;
    }
    while ( v10 != 0 );
  }
  return maxsofar;
}

//------------------------------------------------------------------------------
// Address: 0x100E9000
// Name: unsigned long CRC32_ProcessSingleBuffer(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CRC32_ProcessSingleBuffer(const void *p, int len)
{
  unsigned int crc; // [esp+0h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &crc);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: p, nBuffer: len);
  CRC32_Final(pulCRC: &crc);
  return crc;
}

//------------------------------------------------------------------------------
// Address: 0x100E9040
// Name: public: void CGamestatsData::AllocData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamestatsData::AllocData(CGamestatsData *this)
{
  KeyValues *m_pKVData; // ecx
  KeyValues *v3; // eax
  char buffer[128]; // [esp+4h] [ebp-80h] BYREF

  m_pKVData = this->m_pKVData;
  if ( m_pKVData != nullptr )
  {
    KeyValues::deleteThis(this: m_pKVData);
    this->m_pKVData = nullptr;
  }
  V_snprintf(pDest: buffer, maxLen: 0x80u, pFormat: "gamestats_");
  UTIL_GetModDir(lpszTextOut: &buffer[10], nSize: 0x76u);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    this->m_pKVData = KeyValues::KeyValues(this: v3, setName: buffer);
  else
    this->m_pKVData = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E90B0
// Name: public: virtual void CBaseGameStats::Event_SaveGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_SaveGame(CBaseGameStats *this)
{
  const char *v2; // eax

  v2 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_SaveGame [%s]\n", v2);
}

//------------------------------------------------------------------------------
// Address: 0x100E90D0
// Name: public: virtual void CBaseGameStats_Driver::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::LevelInitPreEntity(CBaseGameStats_Driver *this)
{
  ConVar *v2; // esi
  ConVar *v3; // eax
  ConVar *m_pParent; // esi
  int m_nValue; // esi
  ConVar *v6; // eax
  int v7; // eax
  unsigned int v8; // eax
  int crcInput[2]; // [esp+4h] [ebp-8h] BYREF

  *(_WORD *)&this->m_bInLevel = 1;
  if ( _V_stricmp(s1: (const char *)&_S5_99.m_StringBufferSize, s2: "unknown") == 0 )
  {
    v2 = cvar->FindVar_2(this: cvar, a2: "hostip");
    v3 = cvar->FindVar_2(this: cvar, a2: "hostport");
    if ( v2 != nullptr && v3 != nullptr )
    {
      m_pParent = v2->m_pParent;
      if ( m_pParent != nullptr )
        m_nValue = m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v6 = v3->m_pParent;
      crcInput[0] = m_nValue;
      if ( v6 != nullptr )
        v7 = v6->m_Value.m_nValue;
      else
        v7 = 0;
      crcInput[1] = v7;
      if ( m_nValue != 0 && v7 != 0 )
      {
        v8 = CRC32_ProcessSingleBuffer(p: crcInput, len: 8);
        V_snprintf(pDest: (char *)&_S5_99.m_StringBufferSize, maxLen: 0x14u, pFormat: "H:%x", v8);
      }
    }
  }
  this->m_flPauseStartTime = 0.0;
  this->m_flLevelStartTime = *(float *)gpGlobals.m_Index;
  gamestats->Event_LevelInit(this: gamestats);
}

//------------------------------------------------------------------------------
// Address: 0x100E91A0
// Name: public: bool CBaseGameStats_Driver::AddBaseDataForSend(class KeyValues __near *,enum StatSendType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseGameStats_Driver::AddBaseDataForSend(
        CBaseGameStats_Driver *this,
        KeyValues *pKV,
        StatSendType_t sendType)
{
  KeyValues *v3; // ebx
  KeyValues *v5; // eax
  KeyValues *v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  float v10; // xmm1_4
  int m_nWriteIndex; // ebx
  float v12; // xmm2_4
  int v13; // edx
  unsigned int v14; // ecx
  StatsBufferRecord_t *v15; // eax
  float v16; // xmm0_4
  float m_flFrameRate; // xmm1_4
  StatsBufferRecord_t *v18; // ecx
  int v19; // eax
  float v20; // xmm0_4
  int m_nValue; // eax
  int v22; // eax
  int v23; // eax
  float value; // [esp+0h] [ebp-68h]
  KeyValues *valuea; // [esp+0h] [ebp-68h]
  char language[64]; // [esp+10h] [ebp-58h] BYREF
  __int64 v27; // [esp+50h] [ebp-18h]
  float flMaxFrameRate; // [esp+5Ch] [ebp-Ch]
  float flMinFrameRate; // [esp+60h] [ebp-8h]
  float flStandardDeviationFrameRate; // [esp+64h] [ebp-4h]
  const MaterialSystem_Config_t *config; // [esp+70h] [ebp+8h]
  char bSend_3; // [esp+77h] [ebp+Fh]

  v3 = nullptr;
  if ( sendType != STATSEND_LEVELSHUTDOWN )
  {
    if ( sendType == STATSEND_APPSHUTDOWN && this->m_iNumLevels > 0 )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v3 = KeyValues::KeyValues(this: v5, setName: "playtime");
      KeyValues::SetInt(this: v3, keyName: "TotalLevelTime", value: (int)this->m_flTotalTimeInLevels);
      KeyValues::SetInt(this: v3, keyName: "NumLevels", value: this->m_iNumLevels);
      KeyValues::AddSubKey(this: pKV, pSubkey: v3);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if ( this->m_bBufferFull || this->m_nWriteIndex >= 300 )
    {
      bSend_3 = 1;
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "perfdata");
      else
        v9 = nullptr;
      flStandardDeviationFrameRate = CBaseGameStats_Driver::AverageStat<float>(this, a2: 0, a3: 0, a4: 0);
      flMinFrameRate = CBaseGameStats_Driver::MinStat<float>(this, a2: 0, a3: 0, a4: 0);
      v27 = 0;
      flMaxFrameRate = CBaseGameStats_Driver::MaxStat<float>(this, a2: 0, a3: 0, a4: 0);
      v10 = 0.0;
      m_nWriteIndex = 600;
      if ( !this->m_bBufferFull )
        m_nWriteIndex = this->m_nWriteIndex;
      v12 = flStandardDeviationFrameRate;
      v13 = 0;
      if ( m_nWriteIndex >= 4 )
      {
        v14 = ((unsigned int)(m_nWriteIndex - 4) >> 2) + 1;
        v15 = &this->m_StatsBuffer[1];
        v13 = 4 * v14;
        do
        {
          v16 = (float)((float)(v15[1].m_flFrameRate - flStandardDeviationFrameRate)
                      * (float)(v15[1].m_flFrameRate - flStandardDeviationFrameRate))
              + (float)((float)((float)(v15->m_flFrameRate - flStandardDeviationFrameRate)
                              * (float)(v15->m_flFrameRate - flStandardDeviationFrameRate))
                      + (float)((float)((float)(v15[-1].m_flFrameRate - flStandardDeviationFrameRate)
                                      * (float)(v15[-1].m_flFrameRate - flStandardDeviationFrameRate))
                              + v10));
          m_flFrameRate = v15[2].m_flFrameRate;
          v15 += 4;
          --v14;
          v10 = (float)((float)(m_flFrameRate - flStandardDeviationFrameRate)
                      * (float)(m_flFrameRate - flStandardDeviationFrameRate))
              + v16;
        }
        while ( v14 != 0 );
      }
      if ( v13 < m_nWriteIndex )
      {
        v18 = &this->m_StatsBuffer[v13];
        v19 = m_nWriteIndex - v13;
        do
        {
          v20 = v18->m_flFrameRate;
          ++v18;
          --v19;
          v10 = v10 + (float)((float)(v20 - flStandardDeviationFrameRate) * (float)(v20 - flStandardDeviationFrameRate));
        }
        while ( v19 != 0 );
      }
      if ( m_nWriteIndex <= 1 )
        flStandardDeviationFrameRate = 0.0;
      else
        flStandardDeviationFrameRate = fsqrt(v10 / (float)(m_nWriteIndex - 1));
      KeyValues::SetFloat(this: v9, keyName: "AvgFPS", value: v12);
      KeyValues::SetFloat(this: v9, keyName: "MinFPS", value: flMinFrameRate);
      KeyValues::SetFloat(this: v9, keyName: "MaxFPS", value: flMaxFrameRate);
      KeyValues::SetFloat(this: v9, keyName: "StdDevFPS", value: flStandardDeviationFrameRate);
      v27 = 4;
      value = CBaseGameStats_Driver::AverageStat<float>(this, a2: 4, a3: 0, a4: 0);
      KeyValues::SetFloat(this: v9, keyName: "AvgServerPing", value);
      valuea = v9;
      v7 = pKV;
      KeyValues::AddSubKey(this: pKV, pSubkey: valuea);
    }
    else
    {
      v7 = pKV;
      bSend_3 = 0;
    }
    if ( g_pGameRules != nullptr && g_pGameRules->IsMultiplayer(this: g_pGameRules) )
      KeyValues::SetInt(this: v7, keyName: "UsedVoice", value: this->m_bDidVoiceChat);
    if ( closecaption.m_pParent != nullptr )
      m_nValue = closecaption.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    KeyValues::SetInt(this: v7, keyName: "Caption", value: m_nValue);
    strcpy(language, "unknown");
    memset(dst: (int)&language[8], value: nullptr, count: 0x38u);
    if ( engine != nullptr )
    {
      engine->GetUILanguage(this: engine, a2: language, a3: 64);
      v22 = engine->GetBugSubmissionCount(this: engine);
      KeyValues::SetInt(this: v7, keyName: "BugSub", value: v22);
      engine->ClearBugSubmissionCount(this: engine);
    }
    KeyValues::SetString(this: v7, keyName: "Language", value: language);
    if ( materials != nullptr )
    {
      config = materials->GetCurrentConfigForVideoCard(this: materials);
      KeyValues::SetInt(this: v7, keyName: "Windowed", value: config->m_Flags & 1);
      KeyValues::SetInt(this: v7, keyName: "WindowedNoBorder", value: (config->m_Flags & 0x20000) != 0);
    }
    if ( sv_cheats != nullptr )
    {
      if ( sv_cheats->m_pParent != nullptr )
        v23 = sv_cheats->m_pParent->m_Value.m_nValue;
      else
        v23 = 0;
      KeyValues::SetInt(this: v7, keyName: "Cheats", value: v23);
    }
    KeyValues::SetInt(
      this: v7,
      keyName: "MapTime",
      value: (int)(float)(*(float *)gpGlobals.m_Index - this->m_flLevelStartTime));
    this->m_nWriteIndex = 0;
    this->m_bBufferFull = false;
    return bSend_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E95A0
// Name: public: void CBaseGameStats_Driver::CollectData(enum StatSendType_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseGameStats_Driver::CollectData(
        CBaseGameStats_Driver *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *sendType)
{
  CGamestatsData *m_pGamestatsData; // esi
  KeyValues *m_pKVData; // edi
  int v6; // eax
  const char *v8; // eax
  const char *v9; // eax
  KeyValues *v10; // eax
  CSteamWorksGameStatsUploader *SteamWorksSGameStatsUploader; // eax
  KeyValues *v13; // [esp-4h] [ebp-114h]
  char szMap[264]; // [esp+4h] [ebp-10Ch] BYREF
  CBaseGameStats_Driver *v15; // [esp+10Ch] [ebp-4h]
  KeyValues *pKVMap; // [esp+118h] [ebp+8h]

  m_pGamestatsData = this->m_pGamestatsData;
  v15 = this;
  if ( m_pGamestatsData != nullptr )
  {
    m_pKVData = m_pGamestatsData->m_pKVData;
    v6 = ((int (__thiscall *)(IVEngineClient *, int, int))engine->GetAppID)(a1: engine, a2: a3, a3: a2);
    KeyValues::SetInt(this: m_pKVData, keyName: "appid", value: v6);
    if ( sendType == nullptr )
    {
      memset(szMap, 0, 261);
      v8 = engine->GetLevelName(this: engine);
      V_FileBase(in: v8, out: szMap, maxlen: 261);
      if ( szMap[0] == 0 )
      {
        v9 = IGameSystem::MapName();
        V_FileBase(in: v9, out: szMap, maxlen: 261);
      }
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
        pKVMap = KeyValues::KeyValues(this: v10, setName: "map");
      else
        pKVMap = nullptr;
      KeyValues::AddSubKey(this: m_pKVData, pSubkey: pKVMap);
      m_pKVData = pKVMap;
      KeyValues::SetString(this: pKVMap, keyName: "mapname", value: szMap);
    }
    m_pGamestatsData->m_bHaveData |= CBaseGameStats_Driver::AddBaseDataForSend(
                                       this: v15,
                                       pKV: m_pKVData,
                                       (StatSendType_t)sendType);
    if ( sendType == nullptr && m_pGamestatsData->m_bHaveData )
    {
      v13 = m_pGamestatsData->m_pKVData;
      SteamWorksSGameStatsUploader = GetSteamWorksSGameStatsUploader();
      CSteamWorksGameStatsUploader::AddClientPerfData(this: SteamWorksSGameStatsUploader, pKV: v13);
    }
    m_pGamestatsData->m_bHaveData |= ((int (__thiscall *)(CBaseGameStats *))gamestats->AddDataForSend)(a1: gamestats);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E96E0
// Name: public: void CBaseGameStats_Driver::ResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::ResetData(CBaseGameStats_Driver *this)
{
  CGamestatsData *m_pGamestatsData; // esi
  CGamestatsData *v3; // eax
  CGamestatsData *v4; // esi
  CGamestatsData *v5; // eax
  KeyValues *m_pKVData; // esi
  int CPUInformation; // edi
  IMaterialSystem_vtbl *v8; // edi
  int v9; // eax
  IMatRenderContext *v10; // eax
  IMatRenderContext *v11; // edi
  CFmtStrN<256> *v12; // eax
  int v13; // eax
  bool IsSplitScreen; // al
  float value; // [esp+0h] [ebp-348h]
  CFmtStrN<256> v16; // [esp+10h] [ebp-338h] BYREF
  MaterialAdapterInfo_t gpu; // [esp+11Ch] [ebp-22Ch] BYREF
  int dest_width; // [esp+340h] [ebp-8h] BYREF
  int dest_height; // [esp+344h] [ebp-4h] BYREF

  m_pGamestatsData = this->m_pGamestatsData;
  if ( m_pGamestatsData != nullptr )
  {
    if ( m_pGamestatsData->m_pKVData != nullptr )
    {
      KeyValues::deleteThis(this: m_pGamestatsData->m_pKVData);
      m_pGamestatsData->m_pKVData = nullptr;
    }
    C_BaseEntity::operator delete(pMem: m_pGamestatsData);
    this->m_pGamestatsData = nullptr;
  }
  this->m_bBufferFull = false;
  this->m_nWriteIndex = 0;
  this->m_bDidVoiceChat = false;
  v3 = (CGamestatsData *)MemAlloc_Alloc(nSize: 8u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v3->m_pKVData = nullptr;
    v3->m_bHaveData = false;
    CGamestatsData::AllocData(this: v3);
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  this->m_pGamestatsData = v5;
  m_pKVData = v5->m_pKVData;
  KeyValues::SetInt(this: v5->m_pKVData, keyName: "IsPc", value: 1);
  KeyValues::SetInt(this: m_pKVData, keyName: "version", value: 1);
  KeyValues::SetString(this: m_pKVData, keyName: "srcid", value: (const char *)&_S5_99.m_StringBufferSize);
  CPUInformation = _GetCPUInformation();
  OverWriteCharsWeHate(pStr: *(char **)(CPUInformation + 16));
  KeyValues::SetString(this: m_pKVData, keyName: "CPUID", value: *(const char **)(CPUInformation + 16));
  value = (double)*(__int64 *)(CPUInformation + 8) * 0.000000001;
  KeyValues::SetFloat(this: m_pKVData, keyName: "CPUGhz", value);
  KeyValues::SetInt(this: m_pKVData, keyName: "NumCores", value: *(unsigned __int8 *)(CPUInformation + 6));
  v8 = materials->__vftable;
  v9 = ((int (__thiscall *)(IMaterialSystem *, MaterialAdapterInfo_t *))materials->GetCurrentAdapter)(
         a1: materials,
         a2: &gpu);
  ((void (__thiscall *)(IMaterialSystem *, int))v8->GetDisplayAdapterInfo)(a1: materials, a2: v9);
  v10 = materials->GetRenderContext(this: materials);
  v11 = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11->GetRenderTargetDimensions(this: v11, a2: &dest_width, a3: &dest_height);
  OverWriteCharsWeHate(pStr: gpu.m_pDriverName);
  KeyValues::SetString(this: m_pKVData, keyName: "GPUDrv", value: gpu.m_pDriverName);
  KeyValues::SetInt(this: m_pKVData, keyName: "GPUVendor", value: gpu.m_VendorID);
  KeyValues::SetInt(this: m_pKVData, keyName: "GPUDeviceID", value: gpu.m_DeviceID);
  v12 = CFmtStrN<256>::CFmtStrN<256>(this: &v16, pszFormat: "%d.%d", gpu.m_nDriverVersionHigh, gpu.m_nDriverVersionLow);
  KeyValues::SetString(this: m_pKVData, keyName: "GPUDriverVersion", value: v12->m_szBuf);
  v13 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
  KeyValues::SetInt(this: m_pKVData, keyName: "DxLvl", value: v13);
  KeyValues::SetInt(this: m_pKVData, keyName: "Width", value: dest_width);
  KeyValues::SetInt(this: m_pKVData, keyName: "Height", value: dest_height);
  IsSplitScreen = VGui_IsSplitScreen();
  KeyValues::SetInt(this: m_pKVData, keyName: "IsSplitScreen", value: IsSplitScreen);
  engine->SetGamestatsData(this: engine, a2: this->m_pGamestatsData);
  v11->EndRender(this: v11);
  v11->Release(this: v11);
}

//------------------------------------------------------------------------------
// Address: 0x100E9910
// Name: public: virtual CBaseGameStats_Driver::~CBaseGameStats_Driver(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::~CBaseGameStats_Driver(CBaseGameStats_Driver *this)
{
  bool v2; // sf

  this->m_LastUserCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  v2 = this->m_PrevMapName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_PrevMapName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_PrevMapName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PrevMapName.m_Storage.m_Memory.m_pMemory);
      this->m_PrevMapName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_PrevMapName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E9970
// Name: public: CBaseGameStats_Driver::CBaseGameStats_Driver(void)
// Source: json
//------------------------------------------------------------------------------
CBaseGameStats_Driver *__thiscall CBaseGameStats_Driver::CBaseGameStats_Driver(CBaseGameStats_Driver *this)
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this, name: "CGameStats");
  this->m_flLastRealTime = -1.0;
  this->m_flLastSampleTime = -1.0;
  this->__vftable = (CBaseGameStats_Driver_vtbl *)&CBaseGameStats_Driver::`vftable';
  this->m_bBufferFull = false;
  this->m_nWriteIndex = 0;
  this->m_flTotalTimeInLevels = 0.0;
  this->m_iNumLevels = 0;
  this->m_bDidVoiceChat = false;
  CUtlString::CUtlString(this: &this->m_PrevMapName);
  this->m_bStationary = false;
  this->m_iLoadedVersion = -1;
  *(_DWORD *)&this->m_bEnabled = 0x1000000;
  this->m_flLevelStartTime = 0.0;
  this->m_flLastMovementTime = 0.0;
  this->m_LastUserCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  this->m_bGamePaused = false;
  this->m_pGamestatsData = nullptr;
  this->m_szLoadedUserID[0] = 0;
  this->m_tLastUpload = 0;
  this->m_LastUserCmd.command_number = 0;
  this->m_LastUserCmd.tick_count = 0;
  this->m_LastUserCmd.viewangles.x = 0.0;
  this->m_LastUserCmd.viewangles.y = 0.0;
  this->m_LastUserCmd.viewangles.z = 0.0;
  this->m_LastUserCmd.buttons = 0;
  this->m_LastUserCmd.impulse = 0;
  this->m_LastUserCmd.weaponselect = 0;
  this->m_LastUserCmd.weaponsubtype = 0;
  this->m_LastUserCmd.random_seed = 0;
  this->m_LastUserCmd.hasbeenpredicted = false;
  this->m_LastUserCmd.forwardmove = 0.0;
  this->m_LastUserCmd.sidemove = 0.0;
  this->m_LastUserCmd.upmove = 0.0;
  *(_DWORD *)&this->m_LastUserCmd.mousedx = 0;
  this->m_LastUserCmd.headangles.x = 0.0;
  this->m_LastUserCmd.headangles.y = 0.0;
  this->m_LastUserCmd.headangles.z = 0.0;
  this->m_LastUserCmd.headoffset.x = 0.0;
  this->m_LastUserCmd.headoffset.y = 0.0;
  this->m_LastUserCmd.headoffset.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E9AF0
// Name: public: virtual bool CBaseGameStats_Driver::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseGameStats_Driver::Init(CBaseGameStats_Driver *this)
{
  int v2; // eax
  char *v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  CBaseGameStats *v7; // ecx
  int v8; // eax
  bool v9; // al
  char szLoweredGameDir[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = _CommandLine(a1: this);
  v3 = (char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v2 + 32))(
                 a1: v2,
                 a2: "-game",
                 a3: "hl2");
  V_strncpy(pDest: szLoweredGameDir, pSrc: v3, maxLen: 256);
  _V_strlower(start: szLoweredGameDir);
  gamestats = (CBaseGameStats *)((int (__stdcall *)(CBaseGameStats *, char *))gamestats->OnInit)(
                                  a1: gamestats,
                                  a2: szLoweredGameDir);
  V_strncpy(pDest: (char *)&_S5_99.m_DataTableProxyFn, pSrc: szLoweredGameDir, maxLen: 256);
  V_strncat(
    pDest: (char *)&_S5_99.m_DataTableProxyFn,
    pSrc: "_gamestats.dat",
    destBufferSize: 0x100u,
    max_chars_to_copy: -1);
  V_strncpy(pDest: s_szStatUploadRegistryKeyName, pSrc: "GameStatsUpload_", maxLen: 256);
  V_strncat(pDest: s_szStatUploadRegistryKeyName, pSrc: szLoweredGameDir, destBufferSize: 0x100u, max_chars_to_copy: -1);
  v5 = _CommandLine(a1: v4);
  v6 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-gamestatsloggingtofile");
  v7 = gamestats;
  *((_BYTE *)gamestats + 4) ^= (*((_BYTE *)gamestats + 4) ^ (2 * (v6 != 0))) & 2;
  v8 = _CommandLine(a1: v7);
  *((_BYTE *)gamestats + 4) ^= (*((_BYTE *)gamestats + 4)
                              ^ ((*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(
                                   a1: v8,
                                   a2: "-gamestatslogging") != 0))
                             & 1;
  if ( gamestatsuploader != nullptr )
  {
    v9 = gamestatsuploader->IsGameStatsLoggingEnabled(this: gamestatsuploader);
    this->m_bEnabled = v9;
    if ( v9 )
      gamestatsuploader->GetPseudoUniqueId(this: gamestatsuploader, a2: (char *)&_S5_99.m_StringBufferSize, a3: 20u);
  }
  CBaseGameStats_Driver::ResetData(this);
  if ( LOBYTE(_S5_99.m_StringBufferSize) != 0 )
    gamestats->Event_Init(this: gamestats);
  else
    this->m_bEnabled = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E9C60
// Name: public: void CBaseGameStats_Driver::SendData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::SendData(CBaseGameStats_Driver *this)
{
  CGamestatsData *m_pGamestatsData; // eax
  int v3; // ecx
  int v4; // eax
  CUtlBuffer buf; // [esp+4h] [ebp-40h] BYREF
  char szFileName[16]; // [esp+34h] [ebp-10h] BYREF

  m_pGamestatsData = this->m_pGamestatsData;
  if ( m_pGamestatsData != nullptr && m_pGamestatsData->m_bHaveData )
  {
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1u);
    KeyValues::RecursiveSaveToFile(this: this->m_pGamestatsData->m_pKVData, &buf, indentLevel: 0);
    v4 = _CommandLine(a1: v3);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-gamestatsfileoutputonly") != 0 )
    {
      strcpy(szFileName, "gamestats.dat");
      filesystem->WriteFile(this: &filesystem->IBaseFileSystem, a2: szFileName, a3: "MOD", a4: &buf);
    }
    else if ( gamestatsuploader != nullptr )
    {
      gamestatsuploader->UploadGameStats(
        this: gamestatsuploader,
        a2: prType,
        a3: 1,
        a4: buf.m_Put,
        a5: buf.m_Memory.m_pMemory);
    }
    CBaseGameStats_Driver::ResetData(this);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9D50
// Name: public: virtual void CBaseGameStats_Driver::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::Shutdown(CBaseGameStats_Driver *this)
{
  CGamestatsData *m_pGamestatsData; // esi
  KeyValues *m_pKVData; // edi
  int v4; // eax
  CGamestatsData *v5; // esi

  this->m_bShuttingDown = true;
  gamestats->Event_Shutdown(this: gamestats);
  if ( gamestats->UseOldFormat(this: gamestats) == 0 && gamestats->ShouldSendDataOnAppShutdown(this: gamestats) )
  {
    m_pGamestatsData = this->m_pGamestatsData;
    if ( m_pGamestatsData != nullptr )
    {
      m_pKVData = m_pGamestatsData->m_pKVData;
      v4 = engine->GetAppID(this: engine);
      KeyValues::SetInt(this: m_pKVData, keyName: "appid", value: v4);
      m_pGamestatsData->m_bHaveData |= CBaseGameStats_Driver::AddBaseDataForSend(
                                         this,
                                         pKV: m_pKVData,
                                         sendType: STATSEND_APPSHUTDOWN);
      m_pGamestatsData->m_bHaveData |= ((int (__thiscall *)(CBaseGameStats *, KeyValues *, int))gamestats->AddDataForSend)(
                                         a1: gamestats,
                                         a2: m_pKVData,
                                         a3: 1);
    }
    CBaseGameStats_Driver::SendData(this);
  }
  if ( _S5_99.m_ProxyFn != nullptr )
  {
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: _S5_99.m_ProxyFn);
    _S5_99.m_ProxyFn = nullptr;
  }
  if ( this->m_pGamestatsData != nullptr )
  {
    engine->SetGamestatsData(this: engine, a2: nullptr);
    v5 = this->m_pGamestatsData;
    if ( v5 != nullptr )
    {
      if ( v5->m_pKVData != nullptr )
      {
        KeyValues::deleteThis(this: v5->m_pKVData);
        v5->m_pKVData = nullptr;
      }
      C_BaseEntity::operator delete(pMem: v5);
    }
    this->m_pGamestatsData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9E40
// Name: public: virtual void CBaseGameStats_Driver::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseGameStats_Driver::LevelShutdownPreEntity(
        CBaseGameStats_Driver *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  float m_flLevelStartTime; // xmm2_4
  float v5; // xmm0_4
  float m_flTotalTimeInLevels; // xmm1_4

  m_flLevelStartTime = this->m_flLevelStartTime;
  v5 = *(float *)gpGlobals.m_Index - m_flLevelStartTime;
  if ( v5 < 0.0 )
  {
    _Warning(
      a1: "EVENT_LEVELSHUTDOWN:  with negative elapsed time (rt %f starttime %f)\n",
      *(float *)gpGlobals.m_Index,
      m_flLevelStartTime);
    v5 = 0.0;
  }
  if ( this->m_bInLevel )
  {
    m_flTotalTimeInLevels = this->m_flTotalTimeInLevels;
    ++this->m_iNumLevels;
    this->m_flTotalTimeInLevels = m_flTotalTimeInLevels + v5;
    ((void (__stdcall *)(_DWORD))gamestats->Event_LevelShutdown)(a1: LODWORD(v5));
    if ( gamestats->UseOldFormat(this: gamestats) == 0 )
    {
      CBaseGameStats_Driver::CollectData(this, a2, a3, sendType: nullptr);
      if ( gamestats->ShouldSendDataOnLevelShutdown(this: gamestats) )
        CBaseGameStats_Driver::SendData(this);
    }
    this->m_bInLevel = false;
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1014D440
// Name: public: void CBaseGameStats::StatsLog(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseGameStats::StatsLog(CBaseGameStats *this, const char *fmt, ...)
{
  const tm *v2; // eax
  const char *v3; // eax
  _BYTE *v4; // eax
  void *m_nElements; // eax
  char buf[2048]; // [esp+1Ch] [ebp-888h] BYREF
  char timeString[128]; // [esp+81Ch] [ebp-88h] BYREF
  __int64 aclock; // [esp+89Ch] [ebp-8h] BYREF
  va_list params; // [esp+8B4h] [ebp+10h] BYREF

  va_start(params, fmt);
  if ( (*((_BYTE *)this + 84) & 3) != 0 )
  {
    V_vsnprintf(pDest: buf, maxLen: 2048, pFormat: fmt, params);
    _time64(timeptr: &aclock);
    v2 = _localtime64(ptime: &aclock);
    v3 = asctime(tb: v2);
    V_strncpy(pDest: timeString, pSrc: v3, maxLen: 128);
    strstr(str1: (unsigned __int8 *)timeString, str2: "\n");
    if ( v4 != nullptr )
      *v4 = 0;
    if ( (*((_BYTE *)this + 84) & 1) != 0 )
      DevMsg(a1: "[GS %s - %7.2f] %s", timeString, gpGlobals->realtime, buf);
    if ( (*((_BYTE *)this + 84) & 2) != 0 )
    {
      m_nElements = (void *)_S2_127.m_nElements;
      if ( _S2_127.m_nElements != 0
        || (m_nElements = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: "gamestats.log", a3: "a", a4: "MOD"),
            _S2_127.m_nElements = (int)m_nElements,
            m_nElements != nullptr) )
      {
        filesystem->FPrintf(
          this: filesystem,
          a2: m_nElements,
          a3: "[GS %s - %7.2f] %s",
          timeString,
          gpGlobals->realtime,
          buf);
        filesystem->Flush(this: &filesystem->IBaseFileSystem, a2: (void *)_S2_127.m_nElements);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D590
// Name: public: virtual char const __near * CBaseGameStats::GetStatSaveFileName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseGameStats::GetStatSaveFileName(CBaseGameStats *this)
{
  return (const char *)&_S2_127.m_ElementStride;
}

//------------------------------------------------------------------------------
// Address: 0x1014D5A0
// Name: public: virtual char const __near * CBaseGameStats::GetStatUploadRegistryKeyName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseGameStats::GetStatUploadRegistryKeyName(CBaseGameStats *this)
{
  return s_szStatUploadRegistryKeyName;
}

//------------------------------------------------------------------------------
// Address: 0x1014D5B0
// Name: public: virtual void CBaseGameStats::Event_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_Shutdown(CBaseGameStats *this)
{
  CBaseGameStats::StatsLog(
    this,
    fmt: "CBaseGameStats::Event_Shutdown [%dth session]\n",
    this->m_BasicStats.m_Summary.m_nCount);
  CBaseGameStats::StatsLog(this, fmt: "\n====================================================================\n\n");
}

//------------------------------------------------------------------------------
// Address: 0x1014D5E0
// Name: public: virtual void CBaseGameStats::Event_MapChange(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_MapChange(
        CBaseGameStats *this,
        const char *szOldMapName,
        const char *szNewMapName)
{
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_MapChange to [%s]\n", szNewMapName);
}

//------------------------------------------------------------------------------
// Address: 0x1014D600
// Name: public: virtual void CBaseGameStats::Event_Credits(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_Credits(CBaseGameStats *this)
{
  float elapsed; // [esp+10h] [ebp-4h]

  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_Credits\n", this);
  elapsed = 0.0;
  if ( CBGSDriver.m_bInLevel )
  {
    elapsed = gpGlobals->realtime - CBGSDriver.m_flLevelStartTime;
    if ( elapsed < 0.0 )
    {
      _Warning(
        a1: "EVENT_CREDITS with negative elapsed time (rt %f starttime %f)\n",
        gpGlobals->realtime,
        CBGSDriver.m_flLevelStartTime);
      elapsed = 0.0;
    }
  }
  if ( gamestats->m_BasicStats.m_nSecondsToCompleteGame == 0 && gamestats->UserPlayedAllTheMaps(this: gamestats) )
  {
    gamestats->m_BasicStats.m_nSecondsToCompleteGame = (int)(float)((float)gamestats->m_BasicStats.m_Summary.m_nSeconds
                                                                  + elapsed);
    gamestats->SaveToFileNOW(this: gamestats, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D6C0
// Name: public: virtual void CBaseGameStats::Event_CrateSmashed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_CrateSmashed(CBaseGameStats *this)
{
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_CrateSmashed\n");
}

//------------------------------------------------------------------------------
// Address: 0x1014D6D0
// Name: public: virtual void CBaseGameStats::Event_PreSaveGameLoaded(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_PreSaveGameLoaded(CBaseGameStats *this, const char *pSaveName, bool bInGame)
{
  const char *v3; // eax

  v3 = "in-game";
  if ( !bInGame )
    v3 = "at console";
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_PreSaveGameLoaded [%s] %s\n", pSaveName, v3);
}

//------------------------------------------------------------------------------
// Address: 0x1014D700
// Name: public: virtual void CBaseGameStats::Event_PlayerConnected(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_PlayerConnected(CBaseGameStats *this, CBasePlayer *pBasePlayer)
{
  const char *v3; // eax

  v3 = pBasePlayer->GetPlayerName(this: pBasePlayer);
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_PlayerConnected [%s]\n", v3);
}

//------------------------------------------------------------------------------
// Address: 0x1014D730
// Name: public: virtual void CBaseGameStats::Event_PlayerDisconnected(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_PlayerDisconnected(CBaseGameStats *this, CBasePlayer *pBasePlayer)
{
  const char *v3; // eax

  v3 = pBasePlayer->GetPlayerName(this: pBasePlayer);
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_PlayerDisconnected [%s]\n", v3);
}

//------------------------------------------------------------------------------
// Address: 0x1014D760
// Name: public: virtual void CBaseGameStats::Event_WeaponFired(class CBasePlayer __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_WeaponFired(
        CBaseGameStats *this,
        CBasePlayer *pShooter,
        bool bPrimary,
        const char *pchWeaponName)
{
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // [esp-8h] [ebp-Ch]
  const char *v8; // [esp-4h] [ebp-8h]

  v5 = "primary";
  if ( !bPrimary )
    v5 = "secondary";
  v6 = (const char *)((int (__thiscall *)(CBasePlayer *, const char *, const char *))pShooter->GetPlayerName)(
                       a1: pShooter,
                       a2: v5,
                       a3: pchWeaponName);
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_WeaponFired [%s] %s weapon [%s]\n", v6, v7, v8);
}

//------------------------------------------------------------------------------
// Address: 0x1014D7A0
// Name: public: virtual void CBaseGameStats::Event_PlayerEnteredGodMode(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_PlayerEnteredGodMode(CBaseGameStats *this, CBasePlayer *pBasePlayer)
{
  const char *v3; // eax

  v3 = pBasePlayer->GetPlayerName(this: pBasePlayer);
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_PlayerEnteredGodMode [%s] entered GOD mode\n", v3);
}

//------------------------------------------------------------------------------
// Address: 0x1014D7D0
// Name: public: virtual void CBaseGameStats::Event_PlayerEnteredNoClip(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_PlayerEnteredNoClip(CBaseGameStats *this, CBasePlayer *pBasePlayer)
{
  const char *v3; // eax

  v3 = pBasePlayer->GetPlayerName(this: pBasePlayer);
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_PlayerEnteredNoClip [%s] entered NOCLIPe\n", v3);
}

//------------------------------------------------------------------------------
// Address: 0x1014D800
// Name: public: virtual void CBaseGameStats::Event_DecrementPlayerEnteredNoClip(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_DecrementPlayerEnteredNoClip(CBaseGameStats *this, CBasePlayer *pBasePlayer)
{
  const char *v3; // eax

  v3 = pBasePlayer->GetPlayerName(this: pBasePlayer);
  CBaseGameStats::StatsLog(
    this,
    fmt: "CBaseGameStats::Event_DecrementPlayerEnteredNoClip [%s] decrementing NOCLIPe\n",
    v3);
}

//------------------------------------------------------------------------------
// Address: 0x1014D830
// Name: public: virtual void CBaseGameStats::Event_IncrementCountedStatistic(class Vector const __near &,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_IncrementCountedStatistic(
        CBaseGameStats *this,
        const Vector *vecAbsOrigin,
        const char *pchStatisticName,
        float flIncrementAmount)
{
  CBaseGameStats::StatsLog(
    this,
    fmt: "Incrementing %s by %f at pos (%d, %d, %d)\n",
    pchStatisticName,
    flIncrementAmount,
    (int)vecAbsOrigin->x,
    (int)vecAbsOrigin->y,
    (int)vecAbsOrigin->z);
}

//------------------------------------------------------------------------------
// Address: 0x1014D870
// Name: public: virtual void CBaseGameStats::Event_WindowShattered(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_WindowShattered(CBaseGameStats *this, CBasePlayer *pPlayer)
{
  CBaseGameStats::StatsLog(this, fmt: "In Event_WindowShattered\n");
}

//------------------------------------------------------------------------------
// Address: 0x1014D890
// Name: public: virtual void CBaseGameStats::LoadingEvent_PlayerIDDifferentThanLoadedStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::LoadingEvent_PlayerIDDifferentThanLoadedStats(CBaseGameStats *this)
{
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::LoadingEvent_PlayerIDDifferentThanLoadedStats\n");
}

//------------------------------------------------------------------------------
// Address: 0x1014D8A0
// Name: public: virtual void CBaseGameStats_Driver::OnSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::OnSave(CBaseGameStats_Driver *this)
{
  gamestats->Event_SaveGame(this: gamestats);
}

//------------------------------------------------------------------------------
// Address: 0x1014D8B0
// Name: public: virtual void CBaseGameStats_Driver::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::FrameUpdatePostEntityThink(CBaseGameStats_Driver *this)
{
  bool v2; // bl
  double realtime; // st7
  float m_flPauseStartTime; // xmm3_4
  float v5; // xmm0_4

  v2 = gpGlobals->frametime == 0.0;
  if ( this->m_bInLevel )
  {
    if ( this->m_bGamePaused != v2 )
    {
      if ( gpGlobals->frametime == 0.0 )
      {
        realtime = gpGlobals->realtime;
        this->m_bGamePaused = v2;
        this->m_flPauseStartTime = realtime;
      }
      else
      {
        m_flPauseStartTime = this->m_flPauseStartTime;
        if ( m_flPauseStartTime != 0.0 )
        {
          v5 = gpGlobals->realtime - m_flPauseStartTime;
          if ( v5 < 0.0 )
          {
            _Warning(
              a1: "Game paused time showing up negative (rt %f pausestart %f)\n",
              gpGlobals->realtime,
              m_flPauseStartTime);
            v5 = 0.0;
          }
          this->m_flLevelStartTime = this->m_flLevelStartTime + v5;
          this->m_flPauseStartTime = 0.0;
        }
        this->m_bGamePaused = false;
      }
    }
  }
  else
  {
    this->m_flPauseStartTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D980
// Name: public: virtual void CBaseGameStats::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Clear(CBaseGameStats *this)
{
  BasicGameStats_t::Clear(this: &gamestats->m_BasicStats);
}

//------------------------------------------------------------------------------
// Address: 0x1014D990
// Name: CC_ResetGameStats
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_ResetGameStats()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    gamestats->Clear(this: gamestats);
    gamestats->SaveToFileNOW(this: gamestats, a2: false);
    CBaseGameStats::StatsLog(this: gamestats, fmt: "CC_ResetGameStats : Server cleared game stats\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D9D0
// Name: public: virtual struct datamap_t __near * CPointGamestatsCounter::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointGamestatsCounter::GetDataDescMap(CPointGamestatsCounter *this)
{
  return &CPointGamestatsCounter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1014D9E0
// Name: protected: void CPointGamestatsCounter::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointGamestatsCounter::InputEnable(CPointGamestatsCounter *this, inputdata_t *inputdata)
{
  this->m_bDisabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x1014D9F0
// Name: protected: void CPointGamestatsCounter::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointGamestatsCounter::InputDisable(CPointGamestatsCounter *this, inputdata_t *inputdata)
{
  this->m_bDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x1014DA00
// Name: unsigned long CRC32_ProcessSingleBuffer(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CRC32_ProcessSingleBuffer(const void *p, int len)
{
  unsigned int crc; // [esp+0h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &crc);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: p, nBuffer: len);
  CRC32_Final(pulCRC: &crc);
  return crc;
}

//------------------------------------------------------------------------------
// Address: 0x1014DA40
// Name: public: void CGamestatsData::AllocData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamestatsData::AllocData(CGamestatsData *this)
{
  KeyValues *m_pKVData; // ecx
  KeyValues *v3; // eax
  char buffer[128]; // [esp+4h] [ebp-80h] BYREF

  m_pKVData = this->m_pKVData;
  if ( m_pKVData != nullptr )
  {
    KeyValues::deleteThis(this: m_pKVData);
    this->m_pKVData = nullptr;
  }
  V_snprintf(pDest: buffer, maxLen: 128, pFormat: "gamestats_");
  UTIL_GetModDir(lpszTextOut: &buffer[10], nSize: 0x76u);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    this->m_pKVData = KeyValues::KeyValues(this: v3, setName: buffer);
  else
    this->m_pKVData = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014DAB0
// Name: public: virtual void CBaseGameStats::Event_LevelShutdown(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_LevelShutdown(CBaseGameStats *this, float flElapsed)
{
  const char *v3; // eax
  BasicGameStatsRecord_t *v4; // eax
  const char *v5; // eax

  v3 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
  v4 = BasicGameStats_t::FindOrAddRecordForMap(this: &this->m_BasicStats, mapname: v3);
  v4->m_nSeconds += (int)flElapsed;
  gamestats->m_BasicStats.m_Summary.m_nSeconds += (int)flElapsed;
  v5 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
  CBaseGameStats::StatsLog(
    this,
    fmt: "CBaseGameStats::Event_LevelShutdown [%s] %.2f elapsed %d total\n",
    v5,
    flElapsed,
    gamestats->m_BasicStats.m_Summary.m_nSeconds);
}

//------------------------------------------------------------------------------
// Address: 0x1014DB20
// Name: public: virtual void CBaseGameStats::Event_SaveGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_SaveGame(CBaseGameStats *this)
{
  const char *v2; // eax

  v2 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_SaveGame [%s]\n", v2);
}

//------------------------------------------------------------------------------
// Address: 0x1014DB40
// Name: public: virtual void CBaseGameStats::Event_LoadGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_LoadGame(CBaseGameStats *this)
{
  const char *v2; // eax
  const char *v3; // [esp-4h] [ebp-8h]

  v3 = engine->GetMostRecentlyLoadedFileName(this: engine);
  v2 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_LoadGame [%s] from %s\n", v2, v3);
}

//------------------------------------------------------------------------------
// Address: 0x1014DB70
// Name: public: virtual void CBaseGameStats::Event_PlayerKilled(class CBasePlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_PlayerKilled(
        CBaseGameStats *this,
        CBasePlayer *pPlayer,
        const CTakeDamageInfo *info)
{
  const char *v4; // eax
  BasicGameStatsRecord_t *v5; // esi
  const char *v6; // eax
  const char *v7; // eax
  int v8; // [esp-4h] [ebp-8h]

  ++this->m_BasicStats.m_Summary.m_nDeaths;
  if ( CBGSDriver.m_bInLevel )
  {
    v4 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
    v5 = BasicGameStats_t::FindOrAddRecordForMap(this: &this->m_BasicStats, mapname: v4);
    ++v5->m_nDeaths;
    v6 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
    CBaseGameStats::StatsLog(this, fmt: "  Player died %dth time in level [%s]!!!\n", v5->m_nDeaths, v6);
  }
  else
  {
    CBaseGameStats::StatsLog(this, fmt: "  Player died, but not in a level!!!\n");
  }
  v7 = (const char *)((int (__thiscall *)(CBasePlayer *, int))pPlayer->GetPlayerName)(
                       a1: pPlayer,
                       a2: this->m_BasicStats.m_Summary.m_nDeaths);
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_PlayerKilled [%s] [%dth death]\n", v7, v8);
}

//------------------------------------------------------------------------------
// Address: 0x1014DBF0
// Name: public: virtual void CBaseGameStats::Event_Commentary(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_Commentary(CBaseGameStats *this)
{
  const char *v2; // eax
  BasicGameStatsRecord_t *v3; // eax

  if ( CBGSDriver.m_bInLevel )
  {
    v2 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
    v3 = BasicGameStats_t::FindOrAddRecordForMap(this: &this->m_BasicStats, mapname: v2);
    ++v3->m_nCommentary;
  }
  CBaseGameStats::StatsLog(
    this,
    fmt: "CBaseGameStats::Event_Commentary [%d]\n",
    ++this->m_BasicStats.m_Summary.m_nCommentary);
}

//------------------------------------------------------------------------------
// Address: 0x1014DC30
// Name: public: virtual void CBaseGameStats::Event_Punted(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_Punted(CBaseGameStats *this, CBaseEntity *pObject)
{
  const char *pszValue; // eax

  pszValue = pObject->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_Punted [%s]\n", pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x1014DC60
// Name: public: virtual void CBaseGameStats::Event_FlippedVehicle(class CBasePlayer __near *,class CPropVehicleDriveable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_FlippedVehicle(
        CBaseGameStats *this,
        CBasePlayer *pDriver,
        CPropVehicleDriveable *pVehicle)
{
  const char *pszValue; // eax
  const char *v5; // eax
  const char *v6; // [esp-4h] [ebp-8h]

  pszValue = pVehicle->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v5 = (const char *)((int (__thiscall *)(CBasePlayer *, const char *))pDriver->GetPlayerName)(
                       a1: pDriver,
                       a2: pszValue);
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_FlippedVehicle [%s] flipped [%s]\n", v5, v6);
}

//------------------------------------------------------------------------------
// Address: 0x1014DCA0
// Name: public: virtual void CBaseGameStats::Event_PlayerKilledOther(class CBasePlayer __near *,class CBaseEntity __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_PlayerKilledOther(
        CBaseGameStats *this,
        CBasePlayer *pAttacker,
        CBaseEntity *pVictim,
        const CTakeDamageInfo *info)
{
  const char *pszValue; // eax
  const char *v6; // eax
  const char *v7; // [esp-4h] [ebp-8h]

  pszValue = pVictim->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v6 = (const char *)((int (__thiscall *)(CBasePlayer *, const char *))pAttacker->GetPlayerName)(
                       a1: pAttacker,
                       a2: pszValue);
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_PlayerKilledOther [%s] killed [%s]\n", v6, v7);
}

//------------------------------------------------------------------------------
// Address: 0x1014DCE0
// Name: public: virtual void CBaseGameStats::Event_WeaponHit(class CBasePlayer __near *,bool,char const __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_WeaponHit(
        CBaseGameStats *this,
        CBasePlayer *pShooter,
        bool bPrimary,
        const char *pchWeaponName,
        const CTakeDamageInfo *info)
{
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // [esp-8h] [ebp-14h]
  const char *v9; // [esp-4h] [ebp-10h]
  double v10; // [esp+0h] [ebp-Ch]

  v6 = "primary";
  if ( !bPrimary )
    v6 = "secondary";
  v7 = (const char *)((int (__thiscall *)(CBasePlayer *, const char *, const char *, _DWORD, _DWORD))pShooter->GetPlayerName)(
                       a1: pShooter,
                       a2: v6,
                       a3: pchWeaponName,
                       a4: COERCE_UNSIGNED_INT64(info->m_flDamage),
                       a5: HIDWORD(COERCE_UNSIGNED_INT64(info->m_flDamage)));
  CBaseGameStats::StatsLog(
    this,
    fmt: "CBaseGameStats::Event_WeaponHit [%s] %s weapon [%s] damage [%f]\n",
    v7,
    v8,
    v9,
    v10);
}

//------------------------------------------------------------------------------
// Address: 0x1014DD30
// Name: public: void CBaseGameStats_Driver::CollectData(enum StatSendType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::CollectData(CBaseGameStats_Driver *this, StatSendType_t sendType)
{
  CGamestatsData *v3; // edi
  CGamestatsData *m_pGamestatsData; // esi
  KeyValues *m_pKVData; // esi
  int v6; // eax
  const char *pszValue; // eax
  const char *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  char szMap[264]; // [esp+Ch] [ebp-108h] BYREF

  v3 = engine->GetGamestatsData(this: engine);
  if ( v3 != nullptr )
  {
    m_pGamestatsData = this->m_pGamestatsData;
    if ( m_pGamestatsData != nullptr )
    {
      if ( m_pGamestatsData->m_pKVData != nullptr )
      {
        KeyValues::deleteThis(this: m_pGamestatsData->m_pKVData);
        m_pGamestatsData->m_pKVData = nullptr;
      }
      free(pMem: m_pGamestatsData);
      this->m_pGamestatsData = nullptr;
    }
  }
  else
  {
    v3 = this->m_pGamestatsData;
  }
  if ( v3 != nullptr )
  {
    m_pKVData = v3->m_pKVData;
    v6 = engine->GetAppID(this: engine);
    KeyValues::SetInt(this: m_pKVData, keyName: "appid", value: v6);
    if ( sendType == STATSEND_LEVELSHUTDOWN )
    {
      memset(szMap, 0, 261);
      pszValue = gpGlobals->mapname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      V_strncpy(pDest: szMap, pSrc: pszValue, maxLen: 261);
      if ( szMap[0] == 0 )
      {
        v8 = IGameSystem::MapName();
        V_FileBase(in: v8, out: szMap, maxlen: 261);
      }
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(this: v9, setName: "map");
      else
        v10 = nullptr;
      KeyValues::AddSubKey(this: m_pKVData, pSubkey: v10);
      KeyValues::SetString(this: v10, keyName: "mapname", value: szMap);
      m_pKVData = v10;
    }
    v3->m_bHaveData |= ((int (__thiscall *)(CBaseGameStats *, KeyValues *, StatSendType_t))gamestats->AddDataForSend)(
                         a1: gamestats,
                         a2: m_pKVData,
                         a3: sendType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DE80
// Name: protected: void CPointGamestatsCounter::InputSetName(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointGamestatsCounter::InputSetName(CPointGamestatsCounter *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_STRING )
    this->m_strStatisticName.pszValue = inputdata->value.iszVal.pszValue;
  else
    this->m_strStatisticName.pszValue = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014DEB0
// Name: protected: void CPointGamestatsCounter::InputIncrement(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointGamestatsCounter::InputIncrement(CPointGamestatsCounter *this, inputdata_t *inputdata)
{
  const char *pszValue; // edi
  edict_t *m_pPev; // eax
  const char *v5; // xmm0_4
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( !this->m_bDisabled )
  {
    pszValue = this->m_strStatisticName.pszValue;
    if ( pszValue != nullptr )
    {
      if ( inputdata->value.fieldType == FIELD_FLOAT )
        v5 = inputdata->value.iszVal.pszValue;
      else
        v5 = nullptr;
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      ((void (__stdcall *)(Vector *, const char *, const char *))gamestats->Event_IncrementCountedStatistic)(
        a1: &this->m_vecAbsOrigin,
        a2: pszValue,
        a3: v5);
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        pszValue = (const char *)(m_pPev - gpGlobals->pEdicts);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      _DevMsg(
        a1: 1,
        a2: "CPointGamestatsCounter::InputIncrement:  No stat name specified for point_gamestats_counter @%f, %f, %f [ent index %d]\n",
        this->m_vecAbsOrigin.x,
        this->m_vecAbsOrigin.y,
        this->m_vecAbsOrigin.z,
        pszValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DFD0
// Name: public: virtual void CBaseGameStats::Event_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_Init(CBaseGameStats *this)
{
  bool v2; // al
  bool v3; // bl
  const char *v4; // eax
  bool v5; // al
  bool v6; // bl
  const char *v7; // eax
  int v8; // eax

  v2 = filesystem->IsSteam(this: filesystem);
  v3 = v2;
  if ( CBGSDriver.m_bFirstLevel )
    this->m_BasicStats.m_Summary.m_bSteam = v2;
  if ( CBGSDriver.m_bInLevel )
  {
    v4 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
    BasicGameStats_t::FindOrAddRecordForMap(this: &this->m_BasicStats, mapname: v4)->m_bSteam = v3;
  }
  this->m_BasicStats.m_bSteam = v3;
  v5 = gamestatsuploader->IsCyberCafeUser(this: gamestatsuploader);
  v6 = v5;
  if ( CBGSDriver.m_bFirstLevel )
    this->m_BasicStats.m_Summary.m_bCyberCafe = v5;
  if ( CBGSDriver.m_bInLevel )
  {
    v7 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
    BasicGameStats_t::FindOrAddRecordForMap(this: &this->m_BasicStats, mapname: v7)->m_bCyberCafe = v6;
  }
  this->m_BasicStats.m_bCyberCafe = v6;
  v8 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
  ++this->m_BasicStats.m_Summary.m_nCount;
  this->m_BasicStats.m_nDXLevel = v8;
  CBaseGameStats::StatsLog(
    this,
    fmt: "CBaseGameStats::Event_Init [%dth session]\n",
    this->m_BasicStats.m_Summary.m_nCount);
}

//------------------------------------------------------------------------------
// Address: 0x1014E080
// Name: public: virtual void CBaseGameStats::Event_LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats::Event_LevelInit(CBaseGameStats *this)
{
  const char *v2; // eax
  const char *v3; // eax
  BasicGameStatsRecord_t *v4; // eax
  const char *v5; // eax
  BasicGameStatsRecord_t *v6; // eax
  const char *v7; // eax
  BasicGameStatsRecord_t *v8; // eax
  int m_nValue; // edi
  const char *v10; // eax
  BasicGameStatsRecord_t *v11; // eax
  bool v12; // al
  bool v13; // bl
  const char *v14; // eax
  bool v15; // al
  bool v16; // bl
  const char *v17; // eax
  ConVarRef closecaption; // [esp+8h] [ebp-8h] BYREF

  v2 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
  CBaseGameStats::StatsLog(this, fmt: "CBaseGameStats::Event_LevelInit [%s]\n", v2);
  v3 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
  v4 = BasicGameStats_t::FindOrAddRecordForMap(this: &gamestats->m_BasicStats, mapname: v3);
  ++v4->m_nCount;
  if ( gpGlobals->maxClients == 1 )
  {
    ConVarRef::ConVarRef(this: &closecaption, pName: "closecaption");
    if ( ConVarRef::IsValid(this: &closecaption) )
    {
      if ( CBGSDriver.m_bInLevel )
      {
        v5 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
        v6 = BasicGameStats_t::FindOrAddRecordForMap(this: &this->m_BasicStats, mapname: v5);
        ++v6->m_nCaptions;
      }
      if ( CBGSDriver.m_bFirstLevel )
        ++this->m_BasicStats.m_Summary.m_nCaptions;
    }
    if ( gamestatsuploader->IsHDREnabled(this: gamestatsuploader) )
    {
      if ( CBGSDriver.m_bInLevel )
      {
        v7 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
        v8 = BasicGameStats_t::FindOrAddRecordForMap(this: &this->m_BasicStats, mapname: v7);
        ++v8->m_nHDR;
      }
      if ( CBGSDriver.m_bFirstLevel )
        ++this->m_BasicStats.m_Summary.m_nHDR;
    }
    if ( skill.m_pParent != nullptr && (m_nValue = skill.m_pParent->m_Value.m_nValue) >= 1 )
    {
      if ( m_nValue > 3 )
        m_nValue = 3;
    }
    else
    {
      m_nValue = 1;
    }
    if ( CBGSDriver.m_bInLevel )
    {
      v10 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
      v11 = BasicGameStats_t::FindOrAddRecordForMap(this: &this->m_BasicStats, mapname: v10);
      ++*(&v11->m_nCaptions + m_nValue);
    }
    if ( CBGSDriver.m_bFirstLevel )
      ++*(&this->m_BasicStats.m_Summary.m_nCaptions + m_nValue);
    v12 = filesystem->IsSteam(this: filesystem);
    v13 = v12;
    if ( CBGSDriver.m_bFirstLevel )
      this->m_BasicStats.m_Summary.m_bSteam = v12;
    if ( CBGSDriver.m_bInLevel )
    {
      v14 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
      BasicGameStats_t::FindOrAddRecordForMap(this: &this->m_BasicStats, mapname: v14)->m_bSteam = v13;
    }
    this->m_BasicStats.m_bSteam = v13;
    v15 = gamestatsuploader->IsCyberCafeUser(this: gamestatsuploader);
    v16 = v15;
    if ( CBGSDriver.m_bFirstLevel )
      this->m_BasicStats.m_Summary.m_bCyberCafe = v15;
    if ( CBGSDriver.m_bInLevel )
    {
      v17 = CUtlString::operator char const *(this: &CBGSDriver.m_PrevMapName);
      BasicGameStats_t::FindOrAddRecordForMap(this: &this->m_BasicStats, mapname: v17)->m_bCyberCafe = v16;
    }
    this->m_BasicStats.m_bCyberCafe = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E220
// Name: public: void CBaseGameStats_Driver::ResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::ResetData(CBaseGameStats_Driver *this)
{
  CGamestatsData *m_pGamestatsData; // esi
  CGamestatsData *v3; // eax
  CGamestatsData *v4; // esi
  KeyValues *m_pKVData; // esi

  if ( engine->GetGamestatsData(this: engine) == nullptr )
  {
    m_pGamestatsData = this->m_pGamestatsData;
    if ( m_pGamestatsData != nullptr )
    {
      if ( m_pGamestatsData->m_pKVData != nullptr )
      {
        KeyValues::deleteThis(this: m_pGamestatsData->m_pKVData);
        m_pGamestatsData->m_pKVData = nullptr;
      }
      free(pMem: m_pGamestatsData);
      this->m_pGamestatsData = nullptr;
    }
    this->m_bBufferFull = false;
    this->m_nWriteIndex = 0;
    this->m_bDidVoiceChat = false;
    v3 = (CGamestatsData *)operator new(nSize: 8u);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3->m_pKVData = nullptr;
      v3->m_bHaveData = false;
      CGamestatsData::AllocData(this: v3);
    }
    else
    {
      v4 = nullptr;
    }
    this->m_pGamestatsData = v4;
    m_pKVData = v4->m_pKVData;
    KeyValues::SetInt(this: m_pKVData, keyName: "IsPc", value: 1);
    KeyValues::SetInt(this: m_pKVData, keyName: "version", value: 1);
    KeyValues::SetString(this: m_pKVData, keyName: "srcid", value: (const char *)&_S2_127.m_nBits);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E440
// Name: public: virtual bool CBaseGameStats::UploadStatsFileNOW(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseGameStats::UploadStatsFileNOW(CBaseGameStats *this)
{
  IBaseFileSystem_vtbl *v2; // edi
  int v3; // eax
  char result; // al
  IRegistry *v5; // edi
  IRegistry v6; // ebx
  int v7; // eax
  IBaseFileSystem_vtbl *v8; // edi
  int v9; // eax
  char v10; // bl
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  if ( !CBGSDriver.m_bEnabled
    || !gamestats->StatTrackingEnabledForMod(this: gamestats)
    || !this->HaveValidData(this)
    || gamestats->UseOldFormat(this: gamestats) == 0 )
  {
    return 0;
  }
  v2 = filesystem->IBaseFileSystem::__vftable;
  v3 = ((int (__thiscall *)(CBaseGameStats *, const char *))gamestats->GetStatSaveFileName)(a1: gamestats, a2: "MOD");
  result = ((int (__thiscall *)(IBaseFileSystem *, int))v2->FileExists)(a1: &filesystem->IBaseFileSystem, a2: v3);
  if ( result != 0 )
  {
    CBGSDriver.m_tLastUpload = (int)_Plat_FloatTime();
    v5 = InstanceRegistry(subDirectoryUnderValve: "Steam");
    v6.__vftable = v5->__vftable;
    v7 = ((int (__thiscall *)(CBaseGameStats *, _DWORD))this->GetStatUploadRegistryKeyName)(
           a1: this,
           a2: CBGSDriver.m_tLastUpload);
    ((void (__thiscall *)(IRegistry *, int))v6.WriteInt_2)(a1: v5, a2: v7);
    ReleaseInstancedRegistry(reg: v5);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    v8 = filesystem->IBaseFileSystem::__vftable;
    v9 = ((int (__thiscall *)(CBaseGameStats *, const char *, CUtlBuffer *, _DWORD, _DWORD, _DWORD))this->GetStatSaveFileName)(
           a1: this,
           a2: "MOD",
           a3: &buf,
           a4: 0,
           a5: 0,
           a6: 0);
    ((void (__thiscall *)(IBaseFileSystem *, int))v8->ReadFile)(a1: &filesystem->IBaseFileSystem, a2: v9);
    if ( buf.m_Put != 0 && gamestatsuploader != nullptr )
    {
      v10 = gamestatsuploader->UploadGameStats(
              this: gamestatsuploader,
              a2: locale,
              a3: 1,
              a4: buf.m_Put,
              a5: buf.m_Memory.m_pMemory);
      CUtlBuffer::~CUtlBuffer(this: &buf);
      return v10;
    }
    else
    {
      CUtlBuffer::~CUtlBuffer(this: &buf);
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014E5A0
// Name: public: virtual bool CBaseGameStats_Driver::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseGameStats_Driver::Init(CBaseGameStats_Driver *this)
{
  ICommandLine *v2; // eax
  const char *v3; // eax
  CResponseRulesToEngineInterface *v4; // ecx
  ICommandLine *v5; // eax
  int v6; // eax
  CResponseRulesToEngineInterface *v7; // ecx
  ICommandLine *v8; // eax
  bool v9; // al
  IRegistry *v10; // esi
  IRegistry v11; // ebx
  int v12; // eax
  char szLoweredGameDir[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = _CommandLine((CResponseRulesToEngineInterface *)this);
  v3 = v2->ParmValue_3(this: v2, a2: "-game", a3: "hl2");
  V_strncpy(pDest: szLoweredGameDir, pSrc: v3, maxLen: 256);
  _V_strlower(start: szLoweredGameDir);
  gamestats = (CBaseGameStats *)((int (__stdcall *)(CBaseGameStats *, char *))gamestats->OnInit)(
                                  a1: gamestats,
                                  a2: szLoweredGameDir);
  V_strncpy(pDest: (char *)&_S2_127.m_ElementStride, pSrc: szLoweredGameDir, maxLen: 256);
  V_strncat(
    pDest: (char *)&_S2_127.m_ElementStride,
    pSrc: "_gamestats.dat",
    destBufferSize: 0x100u,
    max_chars_to_copy: -1);
  V_strncpy(pDest: s_szStatUploadRegistryKeyName, pSrc: "GameStatsUpload_", maxLen: 256);
  V_strncat(pDest: s_szStatUploadRegistryKeyName, pSrc: szLoweredGameDir, destBufferSize: 0x100u, max_chars_to_copy: -1);
  v5 = _CommandLine(this: v4);
  v6 = v5->FindParm(this: v5, a2: "-gamestatsloggingtofile");
  v7 = (CResponseRulesToEngineInterface *)gamestats;
  *((_BYTE *)gamestats + 84) ^= (*((_BYTE *)gamestats + 84) ^ (2 * (v6 != 0))) & 2;
  v8 = _CommandLine(this: v7);
  *((_BYTE *)gamestats + 84) ^= (*((_BYTE *)gamestats + 84)
                               ^ (v8->FindParm(this: v8, a2: "-gamestatslogging") != 0))
                              & 1;
  if ( gamestatsuploader != nullptr )
  {
    v9 = gamestatsuploader->IsGameStatsLoggingEnabled(this: gamestatsuploader);
    this->m_bEnabled = v9;
    if ( v9 )
      gamestatsuploader->GetPseudoUniqueId(this: gamestatsuploader, a2: (char *)&_S2_127.m_nBits, a3: 20u);
  }
  CBaseGameStats_Driver::ResetData(this);
  if ( CBGSDriver.m_bEnabled && gamestats->StatTrackingEnabledForMod(this: gamestats) )
  {
    v10 = InstanceRegistry(subDirectoryUnderValve: "Steam");
    v11.__vftable = v10->__vftable;
    v12 = ((int (__thiscall *)(CBaseGameStats *, _DWORD))gamestats->GetStatUploadRegistryKeyName)(a1: gamestats, a2: 0);
    this->m_tLastUpload = ((int (__thiscall *)(IRegistry *, int))v11.ReadInt_2)(a1: v10, a2: v12);
    ReleaseInstancedRegistry(reg: v10);
    gamestats->LoadFromFile(this: gamestats);
  }
  if ( LOBYTE(_S2_127.m_nBits) != 0 )
  {
    gamestats->Event_Init(this: gamestats);
    if ( gamestats->UseOldFormat(this: gamestats) != 0 )
    {
      if ( gamestats->AutoSave_OnInit(this: gamestats) )
        gamestats->SaveToFileNOW(this: gamestats, a2: false);
      if ( gamestats->AutoUpload_OnInit(this: gamestats) )
      {
        gamestats->UploadStatsFileNOW(this: gamestats);
        return 1;
      }
    }
  }
  else
  {
    this->m_bEnabled = false;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014E7D0
// Name: public: void CBaseGameStats_Driver::SendData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::SendData(CBaseGameStats_Driver *this)
{
  CGamestatsData *m_pGamestatsData; // eax
  CResponseRulesToEngineInterface *v3; // ecx
  bool v4; // bl
  char *m_pszString; // esi
  ICommandLine *v6; // eax
  int v7; // esi
  char pDest[260]; // [esp+4h] [ebp-26Ch] BYREF
  char szPathName[260]; // [esp+108h] [ebp-168h] BYREF
  tm timeinfo; // [esp+20Ch] [ebp-64h] BYREF
  CUtlBuffer buf; // [esp+230h] [ebp-40h] BYREF
  char szFileName[16]; // [esp+260h] [ebp-10h] BYREF

  m_pGamestatsData = this->m_pGamestatsData;
  if ( m_pGamestatsData == nullptr || !m_pGamestatsData->m_bHaveData )
    return;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  KeyValues::RecursiveSaveToFile(this: this->m_pGamestatsData->m_pKVData, &buf, indentLevel: 0);
  v4 = gamestats_file_output_directory.m_Value.m_StringLength > 1;
  if ( (gamestats_file_output_directory.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = gamestats_file_output_directory.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)locale;
  }
  v6 = _CommandLine(this: v3);
  if ( v6->FindParm(this: v6, a2: "-gamestatsfileoutputonly") != 0 )
  {
    if ( !v4 )
    {
      strcpy(szFileName, "gamestats.dat");
      filesystem->WriteFile(this: &filesystem->IBaseFileSystem, a2: szFileName, a3: "MOD", a4: &buf);
      goto LABEL_14;
    }
  }
  else if ( !v4 )
  {
    if ( gamestatsuploader != nullptr )
      gamestatsuploader->UploadGameStats(
        this: gamestatsuploader,
        a2: locale,
        a3: 1,
        a4: buf.m_Put,
        a5: buf.m_Memory.m_pMemory);
    goto LABEL_14;
  }
  memset(szPathName, 0, sizeof(szPathName));
  V_strncat(pDest: szPathName, pSrc: m_pszString, destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_AppendSlash(pStr: szPathName, strSize: 260);
  v7 = _V_strlen(str: szPathName);
  memset(pDest, 0, sizeof(pDest));
  _Plat_GetLocalTime(a1: &timeinfo);
  V_snprintf(
    pDest,
    maxLen: 260,
    pFormat: "%s__%2d_%3d_%2d_%2d_%2d.txt",
    (const char *)&_S2_127.m_nBits,
    timeinfo.tm_year % 100,
    timeinfo.tm_yday,
    timeinfo.tm_hour,
    timeinfo.tm_min,
    timeinfo.tm_sec);
  V_strncat(pDest: &szPathName[v7], pSrc: pDest, destBufferSize: 260 - v7, max_chars_to_copy: -1);
  filesystem->WriteFile(this: &filesystem->IBaseFileSystem, a2: szPathName, a3: nullptr, a4: &buf);
LABEL_14:
  CBaseGameStats_Driver::ResetData(this);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1014ED60
// Name: public: virtual CBaseGameStats_Driver::~CBaseGameStats_Driver(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::~CBaseGameStats_Driver(CBaseGameStats_Driver *this)
{
  bool v2; // sf

  this->m_LastUserCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  v2 = this->m_PrevMapName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_PrevMapName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_PrevMapName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PrevMapName.m_Storage.m_Memory.m_pMemory);
      this->m_PrevMapName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_PrevMapName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x1014EDC0
// Name: public: CBaseGameStats_Driver::CBaseGameStats_Driver(void)
// Source: json
//------------------------------------------------------------------------------
CBaseGameStats_Driver *__thiscall CBaseGameStats_Driver::CBaseGameStats_Driver(CBaseGameStats_Driver *this)
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this, name: "CGameStats");
  this->m_flLastRealTime = -1.0;
  this->m_flLastSampleTime = -1.0;
  this->__vftable = (CBaseGameStats_Driver_vtbl *)&CBaseGameStats_Driver::`vftable';
  this->m_bBufferFull = false;
  this->m_nWriteIndex = 0;
  this->m_flTotalTimeInLevels = 0.0;
  this->m_iNumLevels = 0;
  this->m_bDidVoiceChat = false;
  CUtlString::CUtlString(this: &this->m_PrevMapName);
  this->m_bStationary = false;
  this->m_iLoadedVersion = -1;
  *(_DWORD *)&this->m_bEnabled = 0x1000000;
  this->m_flLevelStartTime = 0.0;
  this->m_flLastMovementTime = 0.0;
  this->m_LastUserCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  this->m_bGamePaused = false;
  this->m_pGamestatsData = nullptr;
  this->m_szLoadedUserID[0] = 0;
  this->m_tLastUpload = 0;
  this->m_LastUserCmd.command_number = 0;
  this->m_LastUserCmd.tick_count = 0;
  this->m_LastUserCmd.viewangles.x = 0.0;
  this->m_LastUserCmd.viewangles.y = 0.0;
  this->m_LastUserCmd.viewangles.z = 0.0;
  this->m_LastUserCmd.buttons = 0;
  this->m_LastUserCmd.impulse = 0;
  this->m_LastUserCmd.weaponselect = 0;
  this->m_LastUserCmd.weaponsubtype = 0;
  this->m_LastUserCmd.random_seed = 0;
  this->m_LastUserCmd.hasbeenpredicted = false;
  this->m_LastUserCmd.forwardmove = 0.0;
  this->m_LastUserCmd.sidemove = 0.0;
  this->m_LastUserCmd.upmove = 0.0;
  *(_DWORD *)&this->m_LastUserCmd.mousedx = 0;
  this->m_LastUserCmd.headangles.x = 0.0;
  this->m_LastUserCmd.headangles.y = 0.0;
  this->m_LastUserCmd.headangles.z = 0.0;
  this->m_LastUserCmd.headoffset.x = 0.0;
  this->m_LastUserCmd.headoffset.y = 0.0;
  this->m_LastUserCmd.headoffset.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014EF40
// Name: public: virtual void CBaseGameStats_Driver::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::Shutdown(CBaseGameStats_Driver *this)
{
  bool v2; // zf
  CBaseGameStats_vtbl *v3; // eax
  CGamestatsData *m_pGamestatsData; // esi

  this->m_bShuttingDown = true;
  gamestats->Event_Shutdown(this: gamestats);
  v2 = gamestats->UseOldFormat(this: gamestats) == 0;
  v3 = gamestats->__vftable;
  if ( v2 )
  {
    if ( ((unsigned __int8 (*)(void))v3->ShouldSendDataOnAppShutdown)() != 0 )
    {
      CBaseGameStats_Driver::CollectData(this, sendType: STATSEND_APPSHUTDOWN);
      CBaseGameStats_Driver::SendData(this);
    }
  }
  else
  {
    if ( ((unsigned __int8 (*)(void))v3->AutoSave_OnShutdown)() != 0 )
      gamestats->SaveToFileNOW(this: gamestats, a2: false);
    if ( gamestats->AutoUpload_OnShutdown(this: gamestats) )
      gamestats->UploadStatsFileNOW(this: gamestats);
  }
  if ( _S2_127.m_nElements != 0 )
  {
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: (void *)_S2_127.m_nElements);
    _S2_127.m_nElements = 0;
  }
  m_pGamestatsData = this->m_pGamestatsData;
  if ( m_pGamestatsData != nullptr )
  {
    if ( m_pGamestatsData->m_pKVData != nullptr )
    {
      KeyValues::deleteThis(this: m_pGamestatsData->m_pKVData);
      m_pGamestatsData->m_pKVData = nullptr;
    }
    free(pMem: m_pGamestatsData);
    this->m_pGamestatsData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014F030
// Name: public: void CBaseGameStats_Driver::PossibleMapChange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::PossibleMapChange(CBaseGameStats_Driver *this)
{
  const char *pszValue; // edi
  CUtlString *p_m_PrevMapName; // esi
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // esi
  const char *v6; // eax
  CUtlString PrevMapBackup; // [esp+8h] [ebp-10h] BYREF

  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  p_m_PrevMapName = &this->m_PrevMapName;
  v3 = CUtlString::operator char const *(this: &this->m_PrevMapName);
  if ( _V_stricmp(s1: v3, s2: pszValue) != 0 )
  {
    CUtlString::CUtlString(this: &PrevMapBackup, string: p_m_PrevMapName);
    v4 = gpGlobals->mapname.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    CUtlString::operator=(this: p_m_PrevMapName, src: v4);
    v5 = gpGlobals->mapname.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    v6 = CUtlString::operator char const *(this: &PrevMapBackup);
    gamestats->Event_MapChange(this: gamestats, a2: v6, a3: v5);
    if ( gamestats->UseOldFormat(this: gamestats) != 0 )
    {
      if ( gamestats->AutoSave_OnMapChange(this: gamestats) )
        gamestats->SaveToFileNOW(this: gamestats, a2: false);
      if ( gamestats->AutoUpload_OnMapChange(this: gamestats) )
        gamestats->UploadStatsFileNOW(this: gamestats);
    }
    PrevMapBackup.m_Storage.m_nActualLength = 0;
    if ( PrevMapBackup.m_Storage.m_Memory.m_nGrowSize >= 0 && PrevMapBackup.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: PrevMapBackup.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014F140
// Name: public: virtual void CBaseGameStats_Driver::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::LevelInitPreEntity(CBaseGameStats_Driver *this)
{
  ConVar *v2; // esi
  ConVar *v3; // eax
  ConVar *m_pParent; // esi
  int v5; // esi
  ConVar *v6; // eax
  int v7; // eax
  unsigned int v8; // eax
  int crcInput[2]; // [esp+4h] [ebp-8h] BYREF

  *(_WORD *)&this->m_bInLevel = 1;
  if ( _V_stricmp(s1: (const char *)&_S2_127.m_nBits, s2: "unknown") == 0 )
  {
    v2 = cvar->FindVar_2(this: cvar, a2: "hostip");
    v3 = cvar->FindVar_2(this: cvar, a2: "hostport");
    if ( v2 != nullptr && v3 != nullptr )
    {
      m_pParent = v2->m_pParent;
      v5 = m_pParent != nullptr ? m_pParent->m_Value.m_nValue : 0;
      v6 = v3->m_pParent;
      crcInput[0] = v5;
      v7 = v6 != nullptr ? v6->m_Value.m_nValue : 0;
      crcInput[1] = v7;
      if ( v5 != 0 && v7 != 0 )
      {
        v8 = CRC32_ProcessSingleBuffer(p: crcInput, len: 8);
        V_snprintf(pDest: (char *)&_S2_127.m_nBits, maxLen: 20, pFormat: "H:%x", v8);
      }
    }
  }
  CBaseGameStats_Driver::PossibleMapChange(this);
  this->m_flPauseStartTime = 0.0;
  this->m_flLevelStartTime = gpGlobals->realtime;
  gamestats->Event_LevelInit(this: gamestats);
  if ( gamestats->UseOldFormat(this: gamestats) != 0 )
  {
    if ( ((unsigned __int8 (__thiscall *)(CBaseGameStats *, int, int))gamestats->AutoSave_OnLevelInit)(
           a1: gamestats,
           a2: crcInput[0],
           a3: crcInput[1]) != 0 )
      gamestats->SaveToFileNOW(this: gamestats, a2: false);
    if ( gamestats->AutoUpload_OnLevelInit(this: gamestats) )
      gamestats->UploadStatsFileNOW(this: gamestats);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014F270
// Name: public: virtual void CBaseGameStats_Driver::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::LevelShutdownPreEntity(CBaseGameStats_Driver *this)
{
  float m_flLevelStartTime; // xmm2_4
  float v3; // xmm0_4
  float m_flTotalTimeInLevels; // xmm1_4

  m_flLevelStartTime = this->m_flLevelStartTime;
  v3 = gpGlobals->realtime - m_flLevelStartTime;
  if ( v3 < 0.0 )
  {
    _Warning(
      a1: "EVENT_LEVELSHUTDOWN:  with negative elapsed time (rt %f starttime %f)\n",
      gpGlobals->realtime,
      m_flLevelStartTime);
    v3 = 0.0;
  }
  if ( this->m_bInLevel && gpGlobals->eLoadType != MapLoad_Background )
  {
    m_flTotalTimeInLevels = this->m_flTotalTimeInLevels;
    ++this->m_iNumLevels;
    this->m_flTotalTimeInLevels = m_flTotalTimeInLevels + v3;
    ((void (__stdcall *)(_DWORD))gamestats->Event_LevelShutdown)(a1: LODWORD(v3));
    if ( gamestats->UseOldFormat(this: gamestats) != 0 )
    {
      if ( gamestats->AutoSave_OnLevelShutdown(this: gamestats) )
        gamestats->SaveToFileNOW(this: gamestats, a2: true);
      if ( gamestats->AutoUpload_OnLevelShutdown(this: gamestats) )
      {
        gamestats->UploadStatsFileNOW(this: gamestats);
        this->m_bInLevel = false;
        return;
      }
    }
    else
    {
      CBaseGameStats_Driver::CollectData(this, sendType: STATSEND_LEVELSHUTDOWN);
      if ( gamestats->ShouldSendDataOnLevelShutdown(this: gamestats) )
        CBaseGameStats_Driver::SendData(this);
    }
    this->m_bInLevel = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014F390
// Name: public: virtual void CBaseGameStats_Driver::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGameStats_Driver::OnRestore(CBaseGameStats_Driver *this)
{
  CBaseGameStats_Driver::PossibleMapChange(this);
  gamestats->Event_LoadGame(this: gamestats);
}

//------------------------------------------------------------------------------
// Address: 0x1014F3B0
// Name: public: virtual bool CBaseGameStats::SaveToFileNOW(bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CBaseGameStats::SaveToFileNOW@<al>(CBaseGameStats *this@<ecx>, int a2@<edi>, bool bForceSyncWrite)
{
  IBaseFileSystem_vtbl *v5; // edi
  int v6; // eax
  IFileSystem_vtbl *v7; // edi
  int v8; // eax
  const char *v9; // eax
  int m_Put; // esi
  const void *v11; // eax
  char gamePath[256]; // [esp+4h] [ebp-360h] BYREF
  char fullpath[512]; // [esp+104h] [ebp-260h] BYREF
  CUtlBuffer statsBuffer; // [esp+304h] [ebp-60h] BYREF
  CUtlBuffer buf; // [esp+334h] [ebp-30h] BYREF

  if ( !CBGSDriver.m_bEnabled
    || !gamestats->StatTrackingEnabledForMod(this: gamestats)
    || gamestats->UseOldFormat(this: gamestats) == 0 )
  {
    return 0;
  }
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%hd", 6);
  else
    CUtlBuffer::PutTypeBin<short>(this: &buf, src: 6);
  CUtlBuffer::Put(this: &buf, pMem: &_S2_127.m_nBits, size: 16);
  if ( this->ShouldTrackStandardStats(this) )
  {
    BasicGameStats_t::SaveToBuffer(this: &this->m_BasicStats, &buf);
  }
  else if ( (buf.m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: &buf, pFmt: "%d", -17973521);
  }
  else
  {
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: -17973521);
  }
  ((void (__thiscall *)(CBaseGameStats *, CUtlBuffer *, int))gamestats->AppendCustomDataToSaveBuffer)(
    a1: gamestats,
    a2: &buf,
    a3: a2);
  memset(fullpath, 0, sizeof(fullpath));
  v5 = filesystem->IBaseFileSystem::__vftable;
  v6 = ((int (__thiscall *)(CBaseGameStats *, const char *))this->GetStatSaveFileName)(a1: this, a2: "MOD");
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, int))v5->FileExists)(
         a1: &filesystem->IBaseFileSystem,
         a2: v6) != 0 )
  {
    v7 = filesystem->IAppSystem::__vftable;
    v8 = ((int (__thiscall *)(CBaseGameStats *, const char *, char *, int, _DWORD))this->GetStatSaveFileName)(
           a1: this,
           a2: "MOD",
           a3: fullpath,
           a4: 512,
           a5: 0);
    ((void (__thiscall *)(IFileSystem *, int))v7->RelativePathToFullPath)(a1: filesystem, a2: v8);
  }
  else
  {
    ((void (__thiscall *)(IVEngineServer *, char *))engine->GetGameDir)(a1: engine, a2: gamePath);
    V_StripTrailingSlash(ppath: gamePath);
    v9 = this->GetStatSaveFileName(this);
    V_snprintf(pDest: fullpath, maxLen: 512, pFormat: "%s/%s", gamePath, v9);
    _V_strlower(start: fullpath);
    V_FixSlashes(pname: fullpath, separator: 92);
  }
  if ( CBGSDriver.m_bShuttingDown || bForceSyncWrite )
  {
    filesystem->WriteFile(this: &filesystem->IBaseFileSystem, a2: fullpath, a3: "MOD", a4: &buf);
    CBaseGameStats::StatsLog(this, fmt: "Shut down wrote to '%s'\n", fullpath);
  }
  else
  {
    m_Put = buf.m_Put;
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: buf.m_Put);
    CUtlBuffer::CUtlBuffer(this: &statsBuffer, pBuffer: v11, nSize: m_Put, nFlags: 0);
    CUtlBuffer::Put(this: &statsBuffer, pMem: buf.m_Memory.m_pMemory, size: m_Put);
    filesystem->AsyncWrite(
      this: filesystem,
      a2: fullpath,
      a3: statsBuffer.m_Memory.m_pMemory,
      a4: statsBuffer.m_Put,
      a5: true,
      a6: false,
      a7: nullptr);
    CUtlBuffer::~CUtlBuffer(this: &statsBuffer);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014F640
// Name: public: virtual bool CBaseGameStats::LoadFromFile(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseGameStats::LoadFromFile(CBaseGameStats *this)
{
  IBaseFileSystem_vtbl *v1; // esi
  const char *(__thiscall *GetStatSaveFileName)(CBaseGameStats *); // eax
  int v4; // eax
  IFileSystem_vtbl *v5; // esi
  int v6; // eax
  IBaseFileSystem_vtbl *v7; // esi
  int v8; // eax
  char v9; // bl
  __int16 Short; // ax
  int v11; // edi
  IFileSystem_vtbl *v13; // esi
  int v14; // eax
  char fullpath[512]; // [esp+8h] [ebp-234h] BYREF
  CUtlBuffer buf; // [esp+208h] [ebp-34h] BYREF
  CBaseGameStats *v17; // [esp+238h] [ebp-4h]

  v1 = filesystem->IBaseFileSystem::__vftable;
  GetStatSaveFileName = gamestats->GetStatSaveFileName;
  v17 = this;
  v4 = ((int (__thiscall *)(CBaseGameStats *, const char *))GetStatSaveFileName)(a1: gamestats, a2: "MOD");
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, int))v1->FileExists)(
         a1: &filesystem->IBaseFileSystem,
         a2: v4) != 0 )
  {
    v5 = filesystem->IAppSystem::__vftable;
    v6 = ((int (__thiscall *)(CBaseGameStats *, const char *, char *, int, _DWORD, _DWORD))gamestats->GetStatSaveFileName)(
           a1: gamestats,
           a2: "MOD",
           a3: fullpath,
           a4: 512,
           a5: 0,
           a6: 0);
    ((void (__thiscall *)(IFileSystem *, int))v5->RelativePathToFullPath)(a1: filesystem, a2: v6);
    CBaseGameStats::StatsLog(this, fmt: "Loading stats from '%s'\n", fullpath);
  }
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  v7 = filesystem->IBaseFileSystem::__vftable;
  v8 = ((int (__thiscall *)(CBaseGameStats *, const char *, CUtlBuffer *, _DWORD, _DWORD, _DWORD))gamestats->GetStatSaveFileName)(
         a1: gamestats,
         a2: "MOD",
         a3: &buf,
         a4: 0,
         a5: 0,
         a6: 0);
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, int))v7->ReadFile)(a1: &filesystem->IBaseFileSystem, a2: v8) != 0 )
  {
    v9 = 1;
    Short = CUtlBuffer::GetShort(this: &buf);
    v11 = Short;
    if ( Short <= 6 )
    {
      CBGSDriver.m_iLoadedVersion = Short;
      CUtlBuffer::Get(this: &buf, pMem: CBGSDriver.m_szLoadedUserID, size: 16);
      CBGSDriver.m_szLoadedUserID[16] = 0;
      if ( LOBYTE(_S2_127.m_nBits) != 0 )
      {
        if ( _V_stricmp(s1: CBGSDriver.m_szLoadedUserID, s2: (const char *)&_S2_127.m_nBits) != 0 )
        {
          v13 = filesystem->IAppSystem::__vftable;
          v14 = ((int (__thiscall *)(CBaseGameStats *, const char *))gamestats->GetStatSaveFileName)(
                  a1: gamestats,
                  a2: "MOD");
          ((void (__thiscall *)(IFileSystem *, int))v13->RemoveFile)(a1: filesystem, a2: v14);
          filesystem->RemoveFile(this: filesystem, a2: "gamestats.log", a3: "MOD");
          _Warning(a1: "Userid changed, clearing stats file\n");
          CBGSDriver.m_szLoadedUserID[0] = 0;
          CBGSDriver.m_iLoadedVersion = -1;
          BasicGameStats_t::Clear(this: &gamestats->m_BasicStats);
          gamestats->LoadingEvent_PlayerIDDifferentThanLoadedStats(this: gamestats);
          v9 = 0;
        }
        if ( v11 > 5 )
        {
          if ( *(_DWORD *)&buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset] == -17973521 )
          {
            CUtlBuffer::GetInt(this: &buf);
          }
          else if ( !BasicGameStats_t::ParseFromBuffer(this: &gamestats->m_BasicStats, &buf, iBufferStatsVersion: v11) )
          {
            BasicGameStats_t::Clear(this: &v17->m_BasicStats);
          }
          if ( buf.m_Put != buf.m_Get )
            gamestats->LoadCustomDataFromBuffer(this: gamestats, a2: &buf);
        }
        else
        {
          BasicGameStats_t::Clear(this: &gamestats->m_BasicStats);
          v9 = 0;
        }
      }
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return v9;
    }
    else
    {
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return 0;
    }
  }
  else
  {
    filesystem->RemoveFile(this: filesystem, a2: "gamestats.log", a3: "MOD");
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014FA30
// Name: public: BasicGameStats_t::BasicGameStats_t(void)
// Source: json
//------------------------------------------------------------------------------
BasicGameStats_t *__thiscall BasicGameStats_t::BasicGameStats_t(BasicGameStats_t *this)
{
  UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx

  this->m_nSecondsToCompleteGame = 0;
  this->m_Summary.m_nCount = 0;
  this->m_Summary.m_nSeconds = 0;
  this->m_Summary.m_nCommentary = 0;
  this->m_Summary.m_nHDR = 0;
  this->m_Summary.m_nCaptions = 0;
  *(_WORD *)&this->m_Summary.m_bSteam = 1;
  this->m_Summary.m_nDeaths = 0;
  _V_memset(dest: this->m_Summary.m_nSkill, fill: 0, count: 12);
  this->m_MapTotals.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_MapTotals.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_MapTotals.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_MapTotals.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_MapTotals.m_Elements.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_MapTotals.m_Elements.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_MapTotals.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_MapTotals.m_Elements.m_Tree.m_pElements = m_pMemory;
  if ( this->m_MapTotals.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_MapTotals.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_nDXLevel = 0;
  *(_WORD *)&this->m_bSteam = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014FAA0
// Name: public: CBaseGameStats::CBaseGameStats(void)
// Source: json
//------------------------------------------------------------------------------
CBaseGameStats *__thiscall CBaseGameStats::CBaseGameStats(CBaseGameStats *this)
{
  this->__vftable = (CBaseGameStats_vtbl *)&CBaseGameStats::`vftable';
  BasicGameStats_t::BasicGameStats_t(this: &this->m_BasicStats);
  *((_BYTE *)this + 84) &= 0xFCu;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014FAD0
// Name: public: virtual class CBaseGameStats __near * CBaseGameStats::OnInit(class CBaseGameStats __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseGameStats *__thiscall CBaseGameStats::OnInit(
        CBaseGameStats *this,
        CBaseGameStats *pCurrentGameStats,
        const char *gamedir)
{
  return pCurrentGameStats;
}

//------------------------------------------------------------------------------
// Address: 0x10404C60
// Name: CPointGamestatsCounter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointGamestatsCounter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointGamestatsCounter>();
  CPointGamestatsCounter_DataDescInit::g_DataMapHolder = result;
  return result;
}

} // namespace server
