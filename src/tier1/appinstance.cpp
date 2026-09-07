// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/appinstance.cpp
// Functions: 3
// ============================================================

#include "tier1\appinstance.h"

//------------------------------------------------------------------------------
// Address: 0x00407880
// Name: public: CSingleAppInstance::~CSingleAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSingleAppInstance::~CSingleAppInstance(CSingleAppInstance *this)
{
  if ( this->m_hMutex != nullptr )
  {
    ReleaseMutex(hMutex: this->m_hMutex);
    CloseHandle(hObject: this->m_hMutex);
    this->m_hMutex = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004078B0
// Name: public: bool CSingleAppInstance::CheckForOtherRunningInstances(bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSingleAppInstance::CheckForOtherRunningInstances(
        CSingleAppInstance *this,
        bool exitOnNotUnique,
        bool displayMsgIfNotUnique)
{
  if ( this->m_isUniqueInstance )
    return 0;
  if ( displayMsgIfNotUnique )
    _Plat_MessageBox(
      a1: "Alert",
      a2: "Another copy of this program is already running on this machine.  Only one instance at a time is allowed");
  if ( exitOnNotUnique )
    exit(code: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004078F0
// Name: public: CSingleAppInstance::CSingleAppInstance(char __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CSingleAppInstance *__thiscall CSingleAppInstance::CSingleAppInstance(
        CSingleAppInstance *this,
        char *InstanceName,
        bool exitOnNotUnique,
        bool displayMsgIfNotUnique)
{
  HANDLE MutexA; // eax
  DWORD v6; // eax

  this->m_hMutex = nullptr;
  this->m_isUniqueInstance = true;
  if ( InstanceName != nullptr && _V_strlen(str: InstanceName) != 0 && (int)_V_strlen(str: InstanceName) < 260 )
  {
    MutexA = CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: false, lpName: InstanceName);
    this->m_hMutex = MutexA;
    v6 = WaitForSingleObject(hHandle: MutexA, dwMilliseconds: 0);
    if ( v6 != 0 && v6 != 128 )
    {
      CloseHandle(hObject: this->m_hMutex);
      this->m_hMutex = nullptr;
      this->m_isUniqueInstance = false;
      CSingleAppInstance::CheckForOtherRunningInstances(this, exitOnNotUnique, displayMsgIfNotUnique);
      return this;
    }
    this->m_isUniqueInstance = true;
  }
  return this;
}
