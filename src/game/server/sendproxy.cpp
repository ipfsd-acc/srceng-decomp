// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/sendproxy.cpp
// Functions: 13
// ============================================================

#include "game\server\sendproxy.h"

//------------------------------------------------------------------------------
// Address: 0x10117440
// Name: void SendProxy_StringT_To_String(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_StringT_To_String(const SendProp *pProp, const void *pStruct, int *pData, DVariant *pOut)
{
  if ( *pData != 0 )
    pOut->m_Int = *pData;
  else
    pOut->m_Int = (int)locale;
}

//------------------------------------------------------------------------------
// Address: 0x10211490
// Name: void SendProxy_IntAddOne(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_IntAddOne(const SendProp *pProp, const void *pStruct, _DWORD *pVarData, DVariant *pOut)
{
  pOut->m_Int = *pVarData + 1;
}

//------------------------------------------------------------------------------
// Address: 0x102114A0
// Name: void SendProxy_ShortAddOne(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_ShortAddOne(const SendProp *pProp, const void *pStruct, __int16 *pVarData, DVariant *pOut)
{
  pOut->m_Int = *pVarData + 1;
}

//------------------------------------------------------------------------------
// Address: 0x102114C0
// Name: class SendProp SendPropBool(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropBool(SendProp *result, char *pVarName, int offset, int sizeofVar)
{
  SendPropInt(result, pVarName, offset, sizeofVar, nBits: 1, flags: 1, varProxy: nullptr, priority: 0x80u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102114F0
// Name: class SendProp SendPropEHandle(char __near *,int,int,int,void (*)(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int))
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropEHandle(
        SendProp *result,
        char *pVarName,
        int offset,
        int flags,
        int sizeofVar,
        void (__cdecl *proxyFn)(const SendProp *, const void *, const void *, DVariant *, int, int))
{
  SendPropInt(result, pVarName, offset, sizeofVar, nBits: 21, flags: flags | 1, varProxy: proxyFn, priority: 0x80u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10211530
// Name: class SendProp SendPropIntWithMinusOneFlag(char __near *,int,int,int,void (*)(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int))
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropIntWithMinusOneFlag(
        SendProp *result,
        char *pVarName,
        int offset,
        int sizeofVar,
        int nBits,
        void (__cdecl *proxyFn)(const SendProp *, const void *, const void *, DVariant *, int, int))
{
  SendPropInt(result, pVarName, offset, sizeofVar, nBits, flags: 1, varProxy: proxyFn, priority: 0x80u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10211560
// Name: class SendProp SendPropTime(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropTime(SendProp *result, char *pVarName, int offset, int sizeofVar)
{
  SendPropFloat(
    result,
    pVarName,
    offset,
    sizeofVar,
    nBits: -1,
    flags: 4,
    fLowValue: 0.0,
    fHighValue: -121121.12,
    varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_FloatToFloat,
    priority: 0x80u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102115B0
// Name: void SendProxy_EHandleToInt(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_EHandleToInt(const SendProp *pProp, const void *pStruct, unsigned int *pVarData, DVariant *pOut)
{
  unsigned int v4; // eax
  int v5; // ecx
  CEntInfo *v6; // edx
  unsigned int v7; // eax

  if ( pVarData != nullptr
    && (v4 = *pVarData, *pVarData != -1)
    && (v5 = (unsigned __int16)v4,
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v4],
        v7 = HIWORD(v4),
        v6->m_SerialNumber == v7)
    && v6->m_pEntity != nullptr )
  {
    pOut->m_Int = v5 | ((v7 & 0x3FF) << 11);
  }
  else
  {
    pOut->m_Int = 0x1FFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211610
// Name: class SendProp SendPropStringT(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
SendProp *__cdecl SendPropStringT(SendProp *result, char *pVarName, int offset)
{
  SendPropString(
    result,
    pVarName,
    offset,
    bufferLen: 512,
    flags: 0,
    varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_StringT_To_String,
    priority: 0x80u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10211640
// Name: public: void CSendProxyRecipients::ClearRecipient(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSendProxyRecipients::ClearRecipient(CSendProxyRecipients *this, int iClient)
{
  this->m_Bits.m_Ints[iClient >> 5] &= ~(1 << (iClient & 0x1F));
}

//------------------------------------------------------------------------------
// Address: 0x10211670
// Name: void __near * SendProxy_OnlyToTeam(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl SendProxy_OnlyToTeam(
        const SendProp *pProp,
        CBaseEntity *pStruct,
        const void *pVarData,
        CSendProxyRecipients *pRecipients)
{
  CTeam *Team; // esi
  int i; // edi
  signed int m_pPev; // eax

  if ( pStruct == nullptr )
    return nullptr;
  Team = CBaseEntity::GetTeam(this: pStruct);
  if ( Team == nullptr )
    return nullptr;
  if ( pRecipients != nullptr )
    *pRecipients = 0;
  for ( i = 0;
        i < Team->GetNumPlayers(this: Team);
        pRecipients->m_Bits.m_Ints[(m_pPev - 1) >> 5] |= 1 << ((m_pPev - 1) & 0x1F) )
  {
    m_pPev = (signed int)Team->GetPlayer(this: Team, a2: i)->m_Network.m_pPev;
    if ( m_pPev != 0 )
      m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
    ++i;
  }
  return (void *)pVarData;
}

//------------------------------------------------------------------------------
// Address: 0x10211710
// Name: public: void CSendProxyRecipients::SetOnly(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSendProxyRecipients::SetOnly(CSendProxyRecipients *this, int iClient)
{
  edict_t *pEdicts; // esi
  edict_t *v4; // eax
  IServerUnknown *m_pUnk; // ecx
  int v6; // eax
  CBasePlayer *v7; // esi
  edict_t *m_pPev; // eax
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *SplitScreenPlayers; // eax
  int i; // esi
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // edx
  signed int v13; // ecx

  if ( this != nullptr )
    *this = 0;
  this->m_Bits.m_Ints[iClient >> 5] |= 1 << (iClient & 0x1F);
  pEdicts = gpGlobals->pEdicts;
  if ( pEdicts != nullptr )
    v4 = (pEdicts[iClient + 1].m_fStateFlags & 2) == 0 ? &pEdicts[iClient + 1] : nullptr;
  else
    v4 = nullptr;
  if ( v4 != nullptr || pEdicts != nullptr && (v4 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0) )
  {
    m_pUnk = v4->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v6 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      v7 = (CBasePlayer *)v6;
      if ( v6 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 336))(a1: v6) != 0 )
      {
        if ( CBasePlayer::IsSplitScreenPlayer(this: v7) )
        {
          if ( CBasePlayer::GetSplitScreenPlayerOwner(this: v7) != nullptr )
          {
            m_pPev = CBasePlayer::GetSplitScreenPlayerOwner(this: v7)->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              m_pPev -= (int)gpGlobals->pEdicts;
            this->m_Bits.m_Ints[((int)&m_pPev[-1].m_pUnk + 3) >> 5] |= 1 << (((_BYTE)m_pPev - 1) & 0x1F);
          }
        }
        else
        {
          SplitScreenPlayers = CBasePlayer::GetSplitScreenPlayers(this: v7);
          for ( i = 0; i < SplitScreenPlayers->m_Size; ++i )
          {
            m_Index = SplitScreenPlayers->m_Memory.m_pMemory[i].m_Index;
            if ( m_Index != -1
              && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
            {
              m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
              if ( m_pEntity != nullptr )
              {
                v13 = (signed int)m_pEntity[6].__vftable;
                if ( v13 != 0 )
                  v13 = (signed int)(v13 - (unsigned int)gpGlobals->pEdicts) >> 4;
                this->m_Bits.m_Ints[(v13 - 1) >> 5] |= 1 << ((v13 - 1) & 0x1F);
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211880
// Name: public: void CSendProxyRecipients::ExcludeOnly(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSendProxyRecipients::ExcludeOnly(CSendProxyRecipients *this, int iClient)
{
  edict_t *pEdicts; // esi
  edict_t *v4; // eax
  IServerUnknown *m_pUnk; // ecx
  int v6; // eax
  CBasePlayer *v7; // esi
  edict_t *m_pPev; // eax
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *SplitScreenPlayers; // eax
  int i; // esi
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // edx
  signed int v13; // ecx

  if ( this != nullptr )
  {
    this->m_Bits.m_Ints[0] = -1;
    this->m_Bits.m_Ints[1] = -1;
  }
  this->m_Bits.m_Ints[iClient >> 5] &= ~(1 << (iClient & 0x1F));
  pEdicts = gpGlobals->pEdicts;
  if ( pEdicts != nullptr )
    v4 = (pEdicts[iClient + 1].m_fStateFlags & 2) == 0 ? &pEdicts[iClient + 1] : nullptr;
  else
    v4 = nullptr;
  if ( v4 != nullptr || pEdicts != nullptr && (v4 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0) )
  {
    m_pUnk = v4->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v6 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      v7 = (CBasePlayer *)v6;
      if ( v6 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 336))(a1: v6) != 0 )
      {
        if ( CBasePlayer::IsSplitScreenPlayer(this: v7) )
        {
          if ( CBasePlayer::GetSplitScreenPlayerOwner(this: v7) != nullptr )
          {
            m_pPev = CBasePlayer::GetSplitScreenPlayerOwner(this: v7)->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              m_pPev -= (int)gpGlobals->pEdicts;
            this->m_Bits.m_Ints[((int)&m_pPev[-1].m_pUnk + 3) >> 5] &= ~(1 << (((_BYTE)m_pPev - 1) & 0x1F));
          }
        }
        else
        {
          SplitScreenPlayers = CBasePlayer::GetSplitScreenPlayers(this: v7);
          for ( i = 0; i < SplitScreenPlayers->m_Size; ++i )
          {
            m_Index = SplitScreenPlayers->m_Memory.m_pMemory[i].m_Index;
            if ( m_Index != -1
              && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
            {
              m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
              if ( m_pEntity != nullptr )
              {
                v13 = (signed int)m_pEntity[6].__vftable;
                if ( v13 != 0 )
                  v13 = (signed int)(v13 - (unsigned int)gpGlobals->pEdicts) >> 4;
                this->m_Bits.m_Ints[(v13 - 1) >> 5] &= ~(1 << ((v13 - 1) & 0x1F));
              }
            }
          }
        }
      }
    }
  }
}
