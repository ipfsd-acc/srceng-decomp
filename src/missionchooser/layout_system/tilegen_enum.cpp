// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system/tilegen_enum.cpp
// Functions: 3
// ============================================================

#include "missionchooser\layout_system\tilegen_enum.h"

//------------------------------------------------------------------------------
// Address: 0x1001A410
// Name: public: int CTilegenEnum::FindEntry(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenEnum::FindEntry(CTilegenEnum *this, int nValue)
{
  int m_Size; // edx
  int result; // eax
  EnumEntry_t *i; // ecx

  m_Size = this->m_Entries.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Entries.m_Memory.m_pMemory; i->m_nValue != nValue; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A440
// Name: public: CTilegenEnum::CTilegenEnum(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenEnum *__thiscall CTilegenEnum::CTilegenEnum(CTilegenEnum *this)
{
  this->m_pEnumName = nullptr;
  this->m_Entries.m_Memory.m_pMemory = nullptr;
  this->m_Entries.m_Memory.m_nAllocationCount = 0;
  this->m_Entries.m_Memory.m_nGrowSize = 0;
  this->m_Entries.m_Size = 0;
  this->m_Entries.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001A460
// Name: public: bool CTilegenEnum::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenEnum::LoadFromKeyValues(CTilegenEnum *this, KeyValues *pEnumKeyValues)
{
  const char *String; // eax
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // esi
  const char *Name; // edi
  int Int; // eax
  int v9; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  EnumEntry_t *m_pMemory; // ecx
  int v13; // eax
  EnumEntry_t *v14; // edi
  int enumEntry; // [esp+4h] [ebp-8h]
  const char *enumEntry_4; // [esp+8h] [ebp-4h]
  KeyValues *pSubKey; // [esp+14h] [ebp+8h]

  this->m_pEnumKV = pEnumKeyValues;
  String = KeyValues::GetString(this: pEnumKeyValues, keyName: "name", defaultValue: szDescription);
  this->m_pEnumName = String;
  if ( *String != 0 )
  {
    Key = KeyValues::FindKey(this: this->m_pEnumKV, keyName: "values", bCreate: false);
    if ( Key != nullptr )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
      pSubKey = FirstSubKey;
      if ( FirstSubKey != nullptr )
      {
        while ( 1 )
        {
          Name = KeyValues::GetName(this: FirstSubKey);
          enumEntry_4 = Name;
          Int = KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
          v9 = 0;
          enumEntry = Int;
          if ( this->m_Entries.m_Size > 0 )
            break;
LABEL_15:
          m_Size = this->m_Entries.m_Size;
          m_nAllocationCount = this->m_Entries.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<EnumEntry_t,int>::Grow(
              this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->m_Entries,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_Entries.m_Size;
          m_pMemory = this->m_Entries.m_Memory.m_pMemory;
          v13 = this->m_Entries.m_Size - m_Size - 1;
          this->m_Entries.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v13);
          v14 = &this->m_Entries.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
          {
            v14->m_nValue = enumEntry;
            v14->m_pString = enumEntry_4;
          }
          pSubKey = KeyValues::GetNextKey(this: pSubKey);
          if ( pSubKey == nullptr )
            return 1;
          FirstSubKey = pSubKey;
        }
        while ( _V_stricmp(s1: this->m_Entries.m_Memory.m_pMemory[v9].m_pString, s2: Name) != 0 )
        {
          if ( ++v9 >= this->m_Entries.m_Size )
            goto LABEL_15;
        }
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
          _LoggingSystem_Log(
            a1: LOG_TilegenLayoutSystem,
            a2: 1,
            a3: "Duplicate enumeration string found in enum '%s' (names are case insensitive): %s");
        return 0;
      }
      else
      {
        return 1;
      }
    }
    else
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "No 'values' sub-key found inside enumeration '%s'.\n");
      return 0;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Enum must have a valid 'name' key.\n");
    return 0;
  }
}
