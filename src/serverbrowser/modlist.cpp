// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/modlist.cpp
// Functions: 5
// ============================================================

#include "serverbrowser\modlist.h"

//------------------------------------------------------------------------------
// Address: 0x10013E00
// Name: public: char const __near * CModList::GetModName(int)
// Source: json
//------------------------------------------------------------------------------
CModList::mod_t *__thiscall CModList::GetModName(CModList *this, int index)
{
  return &this->m_ModList.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x10013E20
// Name: public: char const __near * CModList::GetModDir(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CModList::GetModDir(CModList *this, int index)
{
  return this->m_ModList.m_Memory.m_pMemory[index].gamedir;
}

//------------------------------------------------------------------------------
// Address: 0x10013E40
// Name: public: class CGameID const __near & CModList::GetAppID(int)const
// Source: json
//------------------------------------------------------------------------------
const CGameID *__thiscall CModList::GetAppID(CModList *this, int index)
{
  return &this->m_ModList.m_Memory.m_pMemory[index].m_GameID;
}

//------------------------------------------------------------------------------
// Address: 0x10013E60
// Name: public: char const __near * CModList::GetModNameForModDir(class CGameID const __near &)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CModList::GetModNameForModDir(CModList *this, const CGameID *gameID)
{
  int m_Size; // edx
  int v3; // eax
  CModList::mod_t *m_pMemory; // ebx
  CGameID *p_m_GameID; // ecx
  CServerBrowserDialog *v6; // eax
  CServerBrowserDialog *v7; // eax

  m_Size = this->m_ModList.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_ModList.m_Memory.m_pMemory;
    p_m_GameID = &this->m_ModList.m_Memory.m_pMemory->m_GameID;
    while ( gameID->m_ulGameID != p_m_GameID->m_ulGameID
         || *((_DWORD *)&gameID->m_gameID + 1) != *((_DWORD *)&p_m_GameID->m_gameID + 1) )
    {
      ++v3;
      p_m_GameID = (CGameID *)((char *)p_m_GameID + 140);
      if ( v3 >= m_Size )
        goto LABEL_6;
    }
    if ( v3 != -1 )
      return (char *)&m_pMemory[v3];
  }
LABEL_6:
  v6 = ServerBrowserDialog();
  if ( CServerBrowserDialog::GetActiveModName(this: v6) == nullptr )
    return (char *)defaultValue;
  v7 = ServerBrowserDialog();
  return CServerBrowserDialog::GetActiveGameName(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10013EE0
// Name: class CModList __near & ModList(void)
// Source: json
//------------------------------------------------------------------------------
CModList *__cdecl ModList()
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    s_ModList.m_ModList.m_Memory.m_pMemory = nullptr;
    s_ModList.m_ModList.m_Memory.m_nAllocationCount = 0;
    s_ModList.m_ModList.m_Memory.m_nGrowSize = 0;
    s_ModList.m_ModList.m_Size = 0;
    s_ModList.m_ModList.m_pElements = nullptr;
    s_ModList.m_VGUIListeners.m_Memory.m_pMemory = nullptr;
    s_ModList.m_VGUIListeners.m_Memory.m_nAllocationCount = 0;
    s_ModList.m_VGUIListeners.m_Memory.m_nGrowSize = 0;
    s_ModList.m_VGUIListeners.m_Size = 0;
    s_ModList.m_VGUIListeners.m_pElements = nullptr;
    atexit(func: ModList_::_2_::_dynamic_atexit_destructor_for__s_ModList__);
  }
  return &s_ModList;
}
