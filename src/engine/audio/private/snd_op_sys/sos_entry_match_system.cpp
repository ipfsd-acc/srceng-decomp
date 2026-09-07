// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_entry_match_system.cpp
// Functions: 7
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_entry_match_system.h"

//------------------------------------------------------------------------------
// Address: 0x100450B0
// Name: private: void CSosManagedEntryMatch::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosManagedEntryMatch::Reset(CSosManagedEntryMatch *this)
{
  this->m_nMatchString1[0] = 10;
  *(_WORD *)&this->m_bMatchString1 = 2560;
  *(_WORD *)&this->m_bMatchString2 = 0;
  this->m_nMatchInt1 = -1;
  this->m_bMatchInt1 = false;
  this->m_nMatchInt2 = -1;
  this->m_bMatchInt2 = false;
  *(_WORD *)&this->m_bActive = 0;
  this->m_flStartTime = -1.0;
  this->m_flDuration = -1.0;
  this->m_bFree = true;
}

//------------------------------------------------------------------------------
// Address: 0x10045110
// Name: private: void CSosManagedEntryMatch::Print(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosManagedEntryMatch::Print(CSosManagedEntryMatch *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  double v8; // st7
  const char *v9; // eax
  const char *v10; // eax

  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "Match String 1: %s\n",
      this->m_nMatchString1);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v2 = "true";
    if ( !this->m_bMatchString1 )
      v2 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Match String 1?: %s\n", v2);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "Match String 2: %s\n",
      this->m_nMatchString2);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v3 = "true";
    if ( !this->m_bMatchString2 )
      v3 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Match String 2?: %s\n", v3);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v4 = "true";
    if ( !this->m_bMatchSubString )
      v4 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Match SubString ?: %s\n", v4);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "Match Int 1: %i\n",
      this->m_nMatchInt1);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v5 = "true";
    if ( !this->m_bMatchInt1 )
      v5 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Match Int 1?: %s\n", v5);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "Match Int 2: %i\n",
      this->m_nMatchInt2);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v6 = "true";
    if ( !this->m_bMatchInt2 )
      v6 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Match Int 2?: %s\n", v6);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v7 = "true";
    if ( !this->m_bTimed )
      v7 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Timed ?: %s\n", v7);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "Duration: %f\n",
      this->m_flDuration);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "StartTime: %f\n",
      this->m_flStartTime);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "StopTime: %f\n",
      this->m_flDuration + this->m_flStartTime);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v8 = ((double (__thiscall *)(ISoundServices *))g_pSoundServices->GetClientTime)(a1: g_pSoundServices);
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "CurTime: %f\n", v8);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v9 = "true";
    if ( !this->m_bActive )
      v9 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Active ?: %s\n", v9);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v10 = "true";
    if ( !this->m_bFree )
      v10 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Free ?: %s\n", v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100454D0
// Name: public: bool CSosEntryMatch::IsAMatch(class CSosEntryMatch __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSosEntryMatch::IsAMatch(CSosEntryMatch *this, CSosEntryMatch *pEntryMatch)
{
  char v2; // bl
  bool m_bMatchInt1; // cl
  bool m_bMatchInt2; // al
  bool bMatchInt2; // [esp+Dh] [ebp-3h]
  bool bMatchInt1; // [esp+Eh] [ebp-2h]
  bool bMatchString2; // [esp+Fh] [ebp-1h]

  v2 = 1;
  bMatchString2 = true;
  bMatchInt2 = true;
  bMatchInt1 = true;
  if ( this->m_bMatchString1 )
  {
    if ( this->m_bMatchSubString )
    {
      if ( V_stristr(pStr: pEntryMatch->m_nMatchString1, pSearch: this->m_nMatchString1) != nullptr )
        goto LABEL_7;
    }
    else if ( _V_stricmp(s1: pEntryMatch->m_nMatchString1, s2: this->m_nMatchString1) == 0 )
    {
      goto LABEL_7;
    }
    v2 = 0;
  }
LABEL_7:
  if ( this->m_bMatchString2 )
  {
    if ( this->m_bMatchSubString )
    {
      if ( V_stristr(pStr: pEntryMatch->m_nMatchString2, pSearch: this->m_nMatchString2) == nullptr )
        goto LABEL_12;
    }
    else if ( _V_stricmp(s1: pEntryMatch->m_nMatchString2, s2: this->m_nMatchString2) != 0 )
    {
LABEL_12:
      bMatchString2 = false;
    }
  }
  m_bMatchInt1 = this->m_bMatchInt1;
  if ( m_bMatchInt1 && pEntryMatch->m_nMatchInt1 != this->m_nMatchInt1 )
    bMatchInt1 = false;
  m_bMatchInt2 = this->m_bMatchInt2;
  if ( m_bMatchInt2 && pEntryMatch->m_nMatchInt2 != this->m_nMatchInt2 )
    bMatchInt2 = false;
  return (v2 != 0 && this->m_bMatchString1 || !this->m_bMatchString1)
      && (bMatchString2 && this->m_bMatchString2 || !this->m_bMatchString2)
      && (bMatchInt1 && m_bMatchInt1 || !m_bMatchInt1)
      && (bMatchInt2 && m_bMatchInt2 || !m_bMatchInt2);
}

//------------------------------------------------------------------------------
// Address: 0x100455F0
// Name: public: int CSosEntryMatchList::GetFreeEntryIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSosEntryMatchList::GetFreeEntryIndex(CSosEntryMatchList *this)
{
  int v1; // edx
  int result; // eax
  CSosManagedEntryMatch **i; // esi

  v1 = 1;
  result = 0;
  for ( i = this->m_vEntryMatchList; !(*i)->m_bFree; ++i )
  {
    ++result;
    v1 *= 2;
    if ( result >= 32 )
      return -1;
  }
  this->m_vEntryMatchList[result]->m_bFree = false;
  this->m_Free &= ~v1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10045630
// Name: public: class CSosManagedEntryMatch __near * CSosEntryMatchList::GetEntryFromIndex(int)const
// Source: json
//------------------------------------------------------------------------------
CSosManagedEntryMatch *__thiscall CSosEntryMatchList::GetEntryFromIndex(CSosEntryMatchList *this, unsigned int nIndex)
{
  if ( nIndex > 0x1F )
    return nullptr;
  else
    return this->m_vEntryMatchList[nIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10045650
// Name: public: bool CSosEntryMatchList::HasAMatch(class CSosEntryMatch __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSosEntryMatchList::HasAMatch(CSosEntryMatchList *this, CSosEntryMatch *pEntryMatch)
{
  CSosManagedEntryMatch *v3; // esi
  char v4; // bl
  bool m_bMatchInt1; // cl
  bool m_bMatchInt2; // al
  CSosEntryMatchList *v8; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  unsigned int bit; // [esp+14h] [ebp-Ch]
  CSosManagedEntryMatch **j; // [esp+18h] [ebp-8h]
  char v12; // [esp+1Eh] [ebp-2h]
  char v13; // [esp+1Fh] [ebp-1h]
  char pEntryMatch_3; // [esp+2Bh] [ebp+Bh]

  v8 = this;
  bit = 1;
  i = 0;
  for ( j = this->m_vEntryMatchList; ; ++j )
  {
    if ( (bit & this->m_Free) != 0 )
      goto LABEL_35;
    v3 = *j;
    if ( !(*j)->m_bActive )
      goto LABEL_35;
    v4 = 1;
    pEntryMatch_3 = 1;
    v12 = 1;
    v13 = 1;
    if ( v3->m_bMatchString1 )
    {
      if ( v3->m_bMatchSubString )
      {
        if ( V_stristr(pStr: pEntryMatch->m_nMatchString1, pSearch: v3->m_nMatchString1) != nullptr )
          goto LABEL_10;
      }
      else if ( _V_stricmp(s1: pEntryMatch->m_nMatchString1, s2: v3->m_nMatchString1) == 0 )
      {
        goto LABEL_10;
      }
      v4 = 0;
    }
LABEL_10:
    if ( v3->m_bMatchString2 )
    {
      if ( v3->m_bMatchSubString )
      {
        if ( V_stristr(pStr: pEntryMatch->m_nMatchString2, pSearch: v3->m_nMatchString2) == nullptr )
          goto LABEL_15;
      }
      else if ( _V_stricmp(s1: pEntryMatch->m_nMatchString2, s2: v3->m_nMatchString2) != 0 )
      {
LABEL_15:
        pEntryMatch_3 = 0;
      }
    }
    m_bMatchInt1 = v3->m_bMatchInt1;
    if ( m_bMatchInt1 && pEntryMatch->m_nMatchInt1 != v3->m_nMatchInt1 )
      v13 = 0;
    m_bMatchInt2 = v3->m_bMatchInt2;
    if ( m_bMatchInt2 && pEntryMatch->m_nMatchInt2 != v3->m_nMatchInt2 )
      v12 = 0;
    if ( (v4 != 0 && v3->m_bMatchString1 || !v3->m_bMatchString1)
      && (pEntryMatch_3 != 0 && v3->m_bMatchString2 || !v3->m_bMatchString2)
      && (v13 != 0 && m_bMatchInt1 || !m_bMatchInt1)
      && (v12 != 0 && m_bMatchInt2 || !m_bMatchInt2) )
    {
      break;
    }
    this = v8;
LABEL_35:
    bit *= 2;
    if ( ++i >= 32 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100457C0
// Name: public: void CSosEntryMatchList::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosEntryMatchList::Update(CSosEntryMatchList *this)
{
  int i; // edi
  CSosManagedEntryMatch *v3; // eax
  CSosManagedEntryMatch *v4; // eax
  unsigned int bit; // [esp+0h] [ebp-4h]

  bit = 1;
  for ( i = 0; i < 32; ++i )
  {
    if ( (bit & this->m_Free) == 0 )
    {
      v3 = this->m_vEntryMatchList[i];
      if ( v3->m_bTimed )
      {
        if ( v3->m_flDuration <= -1.0 || v3->m_flStartTime <= -1.0 )
        {
          if ( snd_sos_show_entry_match_free.m_pParent != nullptr
            && snd_sos_show_entry_match_free.m_pParent->m_Value.m_nValue != 0 )
          {
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
              LoggingSystem_Log(
                a1: LOG_SOUND_OPERATOR_SYSTEM,
                a2: LS_MESSAGE,
                a3: StackColor,
                a4: "\nFREEING MATCH ENTRY:\n");
            CSosManagedEntryMatch::Print(this: this->m_vEntryMatchList[i]);
          }
          v4 = this->m_vEntryMatchList[i];
          v4->m_nMatchString1[0] = 10;
          *(_WORD *)&v4->m_bMatchString1 = 2560;
          *(_WORD *)&v4->m_bMatchString2 = 0;
          v4->m_nMatchInt1 = -1;
          v4->m_bMatchInt1 = false;
          v4->m_nMatchInt2 = -1;
          v4->m_bMatchInt2 = false;
          *(_WORD *)&v4->m_bActive = 0;
          v4->m_flStartTime = -1.0;
          v4->m_flDuration = -1.0;
          v4->m_bFree = true;
          this->m_Free |= bit;
        }
        else if ( ((double (__thiscall *)(ISoundServices *))g_pSoundServices->GetClientTime)(a1: g_pSoundServices) >= this->m_vEntryMatchList[i]->m_flDuration + this->m_vEntryMatchList[i]->m_flStartTime )
        {
          if ( snd_sos_show_entry_match_free.m_pParent != nullptr
            && snd_sos_show_entry_match_free.m_pParent->m_Value.m_nValue != 0 )
          {
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
              LoggingSystem_Log(
                a1: LOG_SOUND_OPERATOR_SYSTEM,
                a2: LS_MESSAGE,
                a3: StackColor,
                a4: "\nFREEING MATCH ENTRY:\n");
            CSosManagedEntryMatch::Print(this: this->m_vEntryMatchList[i]);
          }
          CSosManagedEntryMatch::Reset(this: this->m_vEntryMatchList[i]);
          this->m_Free |= bit;
        }
      }
    }
    bit *= 2;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10044DC0
// Name: private: void CSosManagedEntryMatch::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosManagedEntryMatch::Reset(CSosManagedEntryMatch *this)
{
  this->m_nMatchString1[0] = 10;
  *(_WORD *)&this->m_bMatchString1 = 2560;
  *(_WORD *)&this->m_bMatchString2 = 0;
  this->m_nMatchInt1 = -1;
  this->m_bMatchInt1 = false;
  this->m_nMatchInt2 = -1;
  this->m_bMatchInt2 = false;
  *(_WORD *)&this->m_bActive = 0;
  this->m_flStartTime = -1.0;
  this->m_flDuration = -1.0;
  this->m_bFree = true;
}

//------------------------------------------------------------------------------
// Address: 0x10044E20
// Name: private: void CSosManagedEntryMatch::Print(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosManagedEntryMatch::Print(CSosManagedEntryMatch *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  double v8; // st7
  const char *v9; // eax
  const char *v10; // eax

  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "Match String 1: %s\n",
      this->m_nMatchString1);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v2 = "true";
    if ( !this->m_bMatchString1 )
      v2 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Match String 1?: %s\n", v2);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "Match String 2: %s\n",
      this->m_nMatchString2);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v3 = "true";
    if ( !this->m_bMatchString2 )
      v3 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Match String 2?: %s\n", v3);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v4 = "true";
    if ( !this->m_bMatchSubString )
      v4 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Match SubString ?: %s\n", v4);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "Match Int 1: %i\n",
      this->m_nMatchInt1);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v5 = "true";
    if ( !this->m_bMatchInt1 )
      v5 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Match Int 1?: %s\n", v5);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "Match Int 2: %i\n",
      this->m_nMatchInt2);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v6 = "true";
    if ( !this->m_bMatchInt2 )
      v6 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Match Int 2?: %s\n", v6);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v7 = "true";
    if ( !this->m_bTimed )
      v7 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Timed ?: %s\n", v7);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "Duration: %f\n",
      this->m_flDuration);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "StartTime: %f\n",
      this->m_flStartTime);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SOUND_OPERATOR_SYSTEM,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "StopTime: %f\n",
      this->m_flDuration + this->m_flStartTime);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v8 = ((double (__thiscall *)(ISoundServices *))g_pSoundServices->GetClientTime)(a1: g_pSoundServices);
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "CurTime: %f\n", v8);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v9 = "true";
    if ( !this->m_bActive )
      v9 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Active ?: %s\n", v9);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
  {
    v10 = "true";
    if ( !this->m_bFree )
      v10 = "false";
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "Free ?: %s\n", v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100451E0
// Name: public: bool CSosEntryMatch::IsAMatch(class CSosEntryMatch __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSosEntryMatch::IsAMatch(CSosEntryMatch *this, CSosEntryMatch *pEntryMatch)
{
  char v2; // bl
  bool m_bMatchInt1; // cl
  bool m_bMatchInt2; // al
  bool bMatchInt2; // [esp+Dh] [ebp-3h]
  bool bMatchInt1; // [esp+Eh] [ebp-2h]
  bool bMatchString2; // [esp+Fh] [ebp-1h]

  v2 = 1;
  bMatchString2 = true;
  bMatchInt2 = true;
  bMatchInt1 = true;
  if ( this->m_bMatchString1 )
  {
    if ( this->m_bMatchSubString )
    {
      if ( V_stristr(pStr: pEntryMatch->m_nMatchString1, pSearch: this->m_nMatchString1) != nullptr )
        goto LABEL_7;
    }
    else if ( _V_stricmp(s1: pEntryMatch->m_nMatchString1, s2: this->m_nMatchString1) == 0 )
    {
      goto LABEL_7;
    }
    v2 = 0;
  }
LABEL_7:
  if ( this->m_bMatchString2 )
  {
    if ( this->m_bMatchSubString )
    {
      if ( V_stristr(pStr: pEntryMatch->m_nMatchString2, pSearch: this->m_nMatchString2) == nullptr )
        goto LABEL_12;
    }
    else if ( _V_stricmp(s1: pEntryMatch->m_nMatchString2, s2: this->m_nMatchString2) != 0 )
    {
LABEL_12:
      bMatchString2 = false;
    }
  }
  m_bMatchInt1 = this->m_bMatchInt1;
  if ( m_bMatchInt1 && pEntryMatch->m_nMatchInt1 != this->m_nMatchInt1 )
    bMatchInt1 = false;
  m_bMatchInt2 = this->m_bMatchInt2;
  if ( m_bMatchInt2 && pEntryMatch->m_nMatchInt2 != this->m_nMatchInt2 )
    bMatchInt2 = false;
  return (v2 != 0 && this->m_bMatchString1 || !this->m_bMatchString1)
      && (bMatchString2 && this->m_bMatchString2 || !this->m_bMatchString2)
      && (bMatchInt1 && m_bMatchInt1 || !m_bMatchInt1)
      && (bMatchInt2 && m_bMatchInt2 || !m_bMatchInt2);
}

//------------------------------------------------------------------------------
// Address: 0x10045300
// Name: public: int CSosEntryMatchList::GetFreeEntryIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSosEntryMatchList::GetFreeEntryIndex(CSosEntryMatchList *this)
{
  int v1; // edx
  int result; // eax
  CSosManagedEntryMatch **i; // esi

  v1 = 1;
  result = 0;
  for ( i = this->m_vEntryMatchList; !(*i)->m_bFree; ++i )
  {
    ++result;
    v1 *= 2;
    if ( result >= 32 )
      return -1;
  }
  this->m_vEntryMatchList[result]->m_bFree = false;
  this->m_Free &= ~v1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10045340
// Name: public: class CSosManagedEntryMatch __near * CSosEntryMatchList::GetEntryFromIndex(int)const
// Source: json
//------------------------------------------------------------------------------
CSosManagedEntryMatch *__thiscall CSosEntryMatchList::GetEntryFromIndex(CSosEntryMatchList *this, unsigned int nIndex)
{
  if ( nIndex > 0x1F )
    return nullptr;
  else
    return this->m_vEntryMatchList[nIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10045360
// Name: public: bool CSosEntryMatchList::HasAMatch(class CSosEntryMatch __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSosEntryMatchList::HasAMatch(CSosEntryMatchList *this, CSosEntryMatch *pEntryMatch)
{
  CSosManagedEntryMatch *v3; // esi
  char v4; // bl
  bool m_bMatchInt1; // cl
  bool m_bMatchInt2; // al
  CSosEntryMatchList *v8; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  unsigned int bit; // [esp+14h] [ebp-Ch]
  CSosManagedEntryMatch **j; // [esp+18h] [ebp-8h]
  char v12; // [esp+1Eh] [ebp-2h]
  char v13; // [esp+1Fh] [ebp-1h]
  char pEntryMatch_3; // [esp+2Bh] [ebp+Bh]

  v8 = this;
  bit = 1;
  i = 0;
  for ( j = this->m_vEntryMatchList; ; ++j )
  {
    if ( (bit & this->m_Free) != 0 )
      goto LABEL_35;
    v3 = *j;
    if ( !(*j)->m_bActive )
      goto LABEL_35;
    v4 = 1;
    pEntryMatch_3 = 1;
    v12 = 1;
    v13 = 1;
    if ( v3->m_bMatchString1 )
    {
      if ( v3->m_bMatchSubString )
      {
        if ( V_stristr(pStr: pEntryMatch->m_nMatchString1, pSearch: v3->m_nMatchString1) != nullptr )
          goto LABEL_10;
      }
      else if ( _V_stricmp(s1: pEntryMatch->m_nMatchString1, s2: v3->m_nMatchString1) == 0 )
      {
        goto LABEL_10;
      }
      v4 = 0;
    }
LABEL_10:
    if ( v3->m_bMatchString2 )
    {
      if ( v3->m_bMatchSubString )
      {
        if ( V_stristr(pStr: pEntryMatch->m_nMatchString2, pSearch: v3->m_nMatchString2) == nullptr )
          goto LABEL_15;
      }
      else if ( _V_stricmp(s1: pEntryMatch->m_nMatchString2, s2: v3->m_nMatchString2) != 0 )
      {
LABEL_15:
        pEntryMatch_3 = 0;
      }
    }
    m_bMatchInt1 = v3->m_bMatchInt1;
    if ( m_bMatchInt1 && pEntryMatch->m_nMatchInt1 != v3->m_nMatchInt1 )
      v13 = 0;
    m_bMatchInt2 = v3->m_bMatchInt2;
    if ( m_bMatchInt2 && pEntryMatch->m_nMatchInt2 != v3->m_nMatchInt2 )
      v12 = 0;
    if ( (v4 != 0 && v3->m_bMatchString1 || !v3->m_bMatchString1)
      && (pEntryMatch_3 != 0 && v3->m_bMatchString2 || !v3->m_bMatchString2)
      && (v13 != 0 && m_bMatchInt1 || !m_bMatchInt1)
      && (v12 != 0 && m_bMatchInt2 || !m_bMatchInt2) )
    {
      break;
    }
    this = v8;
LABEL_35:
    bit *= 2;
    if ( ++i >= 32 )
      return 0;
  }
  return 1;
}

} // namespace engine_xlsp
