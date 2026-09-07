// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/registry.cpp
// Functions: 13
// ============================================================

#include "public\registry.h"

//------------------------------------------------------------------------------
// Address: 0x101CE4C0
// Name: void ReleaseInstancedRegistry(class IRegistry __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseInstancedRegistry(IRegistry *reg)
{
  if ( reg != nullptr )
  {
    reg->Shutdown(this: reg);
    free(pMem: reg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE4E0
// Name: public: virtual int CRegistry::ReadInt(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRegistry::ReadInt(CRegistry *this, const char *pKeyBase, const char *pKey, int defaultValue)
{
  int v5; // esi
  void *v6; // esp
  char v8[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v8, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  return this->ReadInt_2(this, a2: v8, a3: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x101CE550
// Name: public: virtual void CRegistry::WriteInt(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteInt(CRegistry *this, const char *pKeyBase, const char *pKey, int value)
{
  int v5; // esi
  void *v6; // esp
  char v7[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v7, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  this->WriteInt_2(this, a2: v7, a3: value);
}

//------------------------------------------------------------------------------
// Address: 0x101CE5C0
// Name: public: virtual char const __near * CRegistry::ReadString(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CRegistry::ReadString(
        CRegistry *this,
        const char *pKeyBase,
        const char *pKey,
        const char *defaultValue)
{
  int v5; // esi
  void *v6; // esp
  char v8[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v8, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  return this->ReadString_2(this, a2: v8, a3: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x101CE630
// Name: public: virtual void CRegistry::WriteString(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteString(CRegistry *this, const char *pKeyBase, const char *pKey, const char *value)
{
  int v5; // esi
  void *v6; // esp
  char v7[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v7, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  this->WriteString_2(this, a2: v7, a3: value);
}

//------------------------------------------------------------------------------
// Address: 0x101CE6A0
// Name: public: virtual int CRegistry::ReadInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRegistry::ReadInt(CRegistry *this, const char *key, int defaultValue)
{
  int result; // eax
  HKEY__ *m_hKey; // [esp-18h] [ebp-20h]
  int value; // [esp+0h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+4h] [ebp-4h] BYREF

  if ( !this->m_bValid )
    return defaultValue;
  m_hKey = this->m_hKey;
  dwSize = 4;
  if ( RegQueryValueExA(
         hKey: m_hKey,
         lpValueName: key,
         lpReserved: nullptr,
         lpType: (LPDWORD)&key,
         lpData: (LPBYTE)&value,
         lpcbData: &dwSize) != 0 )
    return defaultValue;
  result = defaultValue;
  if ( key == (const char *)4 )
    return value;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CE6F0
// Name: public: virtual void CRegistry::WriteInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteInt(CRegistry *this, const char *key, int value)
{
  if ( this->m_bValid )
    RegSetValueExA(
      hKey: this->m_hKey,
      lpValueName: key,
      Reserved: 0,
      dwType: 4u,
      lpData: (const BYTE *)&value,
      cbData: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x101CE720
// Name: public: virtual char const __near * CRegistry::ReadString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CRegistry::ReadString(CRegistry *this, const char *key, char *defaultValue)
{
  bool v3; // zf
  char *result; // eax
  unsigned int dwSize; // [esp+0h] [ebp-4h] BYREF

  value[0] = 0;
  v3 = !this->m_bValid;
  dwSize = 512;
  if ( v3
    || RegQueryValueExA(
         hKey: this->m_hKey,
         lpValueName: key,
         lpReserved: nullptr,
         lpType: (LPDWORD)&key,
         lpData: (LPBYTE)value,
         lpcbData: &dwSize) != 0 )
  {
    return defaultValue;
  }
  result = defaultValue;
  if ( key == (const char *)1 )
    return value;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CE780
// Name: public: virtual void CRegistry::WriteString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteString(CRegistry *this, const char *key, const char *value)
{
  if ( this->m_bValid )
    RegSetValueExA(
      hKey: this->m_hKey,
      lpValueName: key,
      Reserved: 0,
      dwType: 1u,
      lpData: (const BYTE *)value,
      cbData: strlen(value) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x101CE7C0
// Name: public: virtual bool CRegistry::DirectInit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRegistry::DirectInit(CRegistry *this, const char *subDirectoryUnderValve)
{
  char szModelKey[1024]; // [esp+4h] [ebp-400h] BYREF

  _wsprintfA(a1: szModelKey, a2: "Software\\Valve\\%s", subDirectoryUnderValve);
  if ( RegCreateKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: szModelKey,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 0xF003Fu,
         lpSecurityAttributes: nullptr,
         phkResult: &this->m_hKey,
         lpdwDisposition: (LPDWORD)&subDirectoryUnderValve) != 0 )
  {
    this->m_bValid = false;
    return 0;
  }
  else
  {
    this->m_bValid = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE830
// Name: public: virtual bool CRegistry::Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRegistry::Init(CRegistry *this, const char *platformName)
{
  char subDir[512]; // [esp+4h] [ebp-200h] BYREF

  _wsprintfA(a1: subDir, a2: "%s\\Settings", platformName);
  return this->DirectInit(this, a2: subDir);
}

//------------------------------------------------------------------------------
// Address: 0x101CE870
// Name: public: virtual void CRegistry::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::Shutdown(CRegistry *this)
{
  HKEY__ *m_hKey; // [esp-4h] [ebp-4h]

  if ( this->m_bValid )
  {
    m_hKey = this->m_hKey;
    this->m_bValid = false;
    RegCloseKey(hKey: m_hKey);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE8C0
// Name: class IRegistry __near * InstanceRegistry(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IRegistry *__cdecl InstanceRegistry(const char *subDirectoryUnderValve)
{
  _BYTE *v1; // eax
  _BYTE *v2; // esi

  v1 = MemAlloc_Alloc(nSize: 0xCu);
  if ( v1 != nullptr )
  {
    v1[4] = 0;
    *((_DWORD *)v1 + 2) = 0;
    v2 = v1;
    *(_DWORD *)v1 = &CRegistry::`vftable';
    (*(void (__thiscall **)(_BYTE *, const char *))(*(_DWORD *)v1 + 44))(a1: v1, a2: subDirectoryUnderValve);
    return (IRegistry *)v2;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 44))(a1: 0, a2: subDirectoryUnderValve);
    return nullptr;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101CE8A0
// Name: void ReleaseInstancedRegistry(class IRegistry __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseInstancedRegistry(IRegistry *reg)
{
  if ( reg != nullptr )
  {
    reg->Shutdown(this: reg);
    free(pMem: reg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE930
// Name: public: virtual void CRegistry::WriteInt(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteInt(CRegistry *this, const char *pKeyBase, const char *pKey, int value)
{
  int v5; // esi
  void *v6; // esp
  char v7[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v7, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  this->WriteInt_2(this, a2: v7, a3: value);
}

//------------------------------------------------------------------------------
// Address: 0x101CE9A0
// Name: public: virtual char const __near * CRegistry::ReadString(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CRegistry::ReadString(
        CRegistry *this,
        const char *pKeyBase,
        const char *pKey,
        const char *defaultValue)
{
  int v5; // esi
  void *v6; // esp
  char v8[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v8, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  return this->ReadString_2(this, a2: v8, a3: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x101CEA10
// Name: public: virtual void CRegistry::WriteString(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteString(CRegistry *this, const char *pKeyBase, const char *pKey, const char *value)
{
  int v5; // esi
  void *v6; // esp
  char v7[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v7, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  this->WriteString_2(this, a2: v7, a3: value);
}

//------------------------------------------------------------------------------
// Address: 0x101CEA80
// Name: public: virtual int CRegistry::ReadInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRegistry::ReadInt(CRegistry *this, const char *key, int defaultValue)
{
  int result; // eax
  HKEY__ *m_hKey; // [esp-18h] [ebp-20h]
  int value; // [esp+0h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+4h] [ebp-4h] BYREF

  if ( !this->m_bValid )
    return defaultValue;
  m_hKey = this->m_hKey;
  dwSize = 4;
  if ( RegQueryValueExA(
         hKey: m_hKey,
         lpValueName: key,
         lpReserved: nullptr,
         lpType: (LPDWORD)&key,
         lpData: (LPBYTE)&value,
         lpcbData: &dwSize) != 0 )
    return defaultValue;
  result = defaultValue;
  if ( key == (const char *)4 )
    return value;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CEAD0
// Name: public: virtual void CRegistry::WriteInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteInt(CRegistry *this, const char *key, int value)
{
  if ( this->m_bValid )
    RegSetValueExA(
      hKey: this->m_hKey,
      lpValueName: key,
      Reserved: 0,
      dwType: 4u,
      lpData: (const BYTE *)&value,
      cbData: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x101CEB00
// Name: public: virtual char const __near * CRegistry::ReadString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CRegistry::ReadString(CRegistry *this, const char *key, char *defaultValue)
{
  bool v3; // zf
  char *result; // eax
  unsigned int dwSize; // [esp+0h] [ebp-4h] BYREF

  value[0] = 0;
  v3 = !this->m_bValid;
  dwSize = 512;
  if ( v3
    || RegQueryValueExA(
         hKey: this->m_hKey,
         lpValueName: key,
         lpReserved: nullptr,
         lpType: (LPDWORD)&key,
         lpData: (LPBYTE)value,
         lpcbData: &dwSize) != 0 )
  {
    return defaultValue;
  }
  result = defaultValue;
  if ( key == (const char *)1 )
    return value;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CEB60
// Name: public: virtual void CRegistry::WriteString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteString(CRegistry *this, const char *key, const char *value)
{
  if ( this->m_bValid )
    RegSetValueExA(
      hKey: this->m_hKey,
      lpValueName: key,
      Reserved: 0,
      dwType: 1u,
      lpData: (const BYTE *)value,
      cbData: strlen(value) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x101CEBA0
// Name: public: virtual bool CRegistry::DirectInit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRegistry::DirectInit(CRegistry *this, const char *subDirectoryUnderValve)
{
  char szModelKey[1024]; // [esp+4h] [ebp-400h] BYREF

  _wsprintfA(a1: szModelKey, a2: "Software\\Valve\\%s", subDirectoryUnderValve);
  if ( RegCreateKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: szModelKey,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 0xF003Fu,
         lpSecurityAttributes: nullptr,
         phkResult: &this->m_hKey,
         lpdwDisposition: (LPDWORD)&subDirectoryUnderValve) != 0 )
  {
    this->m_bValid = false;
    return 0;
  }
  else
  {
    this->m_bValid = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CEC10
// Name: public: virtual bool CRegistry::Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRegistry::Init(CRegistry *this, const char *platformName)
{
  char subDir[512]; // [esp+4h] [ebp-200h] BYREF

  _wsprintfA(a1: subDir, a2: "%s\\Settings", platformName);
  return this->DirectInit(this, a2: subDir);
}

//------------------------------------------------------------------------------
// Address: 0x101CEC50
// Name: public: virtual void CRegistry::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::Shutdown(CRegistry *this)
{
  HKEY__ *m_hKey; // [esp-4h] [ebp-4h]

  if ( this->m_bValid )
  {
    m_hKey = this->m_hKey;
    this->m_bValid = false;
    RegCloseKey(hKey: m_hKey);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CECA0
// Name: class IRegistry __near * InstanceRegistry(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IRegistry *__cdecl InstanceRegistry(const char *subDirectoryUnderValve)
{
  _BYTE *v1; // eax
  _BYTE *v2; // esi

  v1 = MemAlloc_Alloc(nSize: 0xCu);
  if ( v1 != nullptr )
  {
    v1[4] = 0;
    *((_DWORD *)v1 + 2) = 0;
    v2 = v1;
    *(_DWORD *)v1 = &CRegistry::`vftable';
    (*(void (__thiscall **)(_BYTE *, const char *))(*(_DWORD *)v1 + 44))(a1: v1, a2: subDirectoryUnderValve);
    return (IRegistry *)v2;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 44))(a1: 0, a2: subDirectoryUnderValve);
    return nullptr;
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1010BC60
// Name: public: virtual int CRegistry::ReadInt(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRegistry::ReadInt(CRegistry *this, const char *pKeyBase, const char *pKey, int defaultValue)
{
  int v5; // esi
  void *v6; // esp
  char v8[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v8, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  return this->ReadInt_2(this, a2: v8, a3: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x1010BCD0
// Name: public: virtual void CRegistry::WriteInt(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteInt(CRegistry *this, const char *pKeyBase, const char *pKey, int value)
{
  int v5; // esi
  void *v6; // esp
  char v7[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v7, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  this->WriteInt_2(this, a2: v7, a3: value);
}

//------------------------------------------------------------------------------
// Address: 0x1010BD40
// Name: public: virtual char const __near * CRegistry::ReadString(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CRegistry::ReadString(
        CRegistry *this,
        const char *pKeyBase,
        const char *pKey,
        const char *defaultValue)
{
  int v5; // esi
  void *v6; // esp
  char v8[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v8, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  return this->ReadString_2(this, a2: v8, a3: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x1010BDB0
// Name: public: virtual void CRegistry::WriteString(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteString(CRegistry *this, const char *pKeyBase, const char *pKey, const char *value)
{
  int v5; // esi
  void *v6; // esp
  char v7[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v7, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  this->WriteString_2(this, a2: v7, a3: value);
}

//------------------------------------------------------------------------------
// Address: 0x1010BE20
// Name: public: virtual int CRegistry::ReadInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRegistry::ReadInt(CRegistry *this, const char *key, int defaultValue)
{
  int result; // eax
  HKEY__ *m_hKey; // [esp-18h] [ebp-20h]
  int value; // [esp+0h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+4h] [ebp-4h] BYREF

  if ( !this->m_bValid )
    return defaultValue;
  m_hKey = this->m_hKey;
  dwSize = 4;
  if ( RegQueryValueExA(
         hKey: m_hKey,
         lpValueName: key,
         lpReserved: nullptr,
         lpType: (LPDWORD)&key,
         lpData: (LPBYTE)&value,
         lpcbData: &dwSize) != 0 )
    return defaultValue;
  result = defaultValue;
  if ( key == (const char *)4 )
    return value;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010BE70
// Name: public: virtual void CRegistry::WriteInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteInt(CRegistry *this, const char *key, int value)
{
  if ( this->m_bValid )
    RegSetValueExA(
      hKey: this->m_hKey,
      lpValueName: key,
      Reserved: 0,
      dwType: 4u,
      lpData: (const BYTE *)&value,
      cbData: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x1010BEA0
// Name: public: virtual char const __near * CRegistry::ReadString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CRegistry::ReadString(CRegistry *this, const char *key, char *defaultValue)
{
  bool v3; // zf
  char *result; // eax
  unsigned int dwSize; // [esp+0h] [ebp-4h] BYREF

  value[0] = 0;
  v3 = !this->m_bValid;
  dwSize = 512;
  if ( v3
    || RegQueryValueExA(
         hKey: this->m_hKey,
         lpValueName: key,
         lpReserved: nullptr,
         lpType: (LPDWORD)&key,
         lpData: (LPBYTE)value,
         lpcbData: &dwSize) != 0 )
  {
    return defaultValue;
  }
  result = defaultValue;
  if ( key == (const char *)1 )
    return value;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010BF00
// Name: public: virtual void CRegistry::WriteString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteString(CRegistry *this, const char *key, const char *value)
{
  if ( this->m_bValid )
    RegSetValueExA(
      hKey: this->m_hKey,
      lpValueName: key,
      Reserved: 0,
      dwType: 1u,
      lpData: (const BYTE *)value,
      cbData: strlen(value) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x1010BF40
// Name: public: virtual bool CRegistry::DirectInit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRegistry::DirectInit(CRegistry *this, const char *subDirectoryUnderValve)
{
  char szModelKey[1024]; // [esp+4h] [ebp-400h] BYREF

  _wsprintfA(a1: szModelKey, a2: "Software\\Valve\\%s", subDirectoryUnderValve);
  if ( RegCreateKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: szModelKey,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 0xF003Fu,
         lpSecurityAttributes: nullptr,
         phkResult: &this->m_hKey,
         lpdwDisposition: (LPDWORD)&subDirectoryUnderValve) != 0 )
  {
    this->m_bValid = false;
    return 0;
  }
  else
  {
    this->m_bValid = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010BFB0
// Name: public: virtual bool CRegistry::Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRegistry::Init(CRegistry *this, const char *platformName)
{
  char subDir[512]; // [esp+4h] [ebp-200h] BYREF

  _wsprintfA(a1: subDir, a2: "%s\\Settings", platformName);
  return this->DirectInit(this, a2: subDir);
}

//------------------------------------------------------------------------------
// Address: 0x1010BFF0
// Name: public: virtual void CRegistry::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::Shutdown(CRegistry *this)
{
  HKEY__ *m_hKey; // [esp-4h] [ebp-4h]

  if ( this->m_bValid )
  {
    m_hKey = this->m_hKey;
    this->m_bValid = false;
    RegCloseKey(hKey: m_hKey);
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from localize (Missing functions)
// ============================================================
namespace localize {

//------------------------------------------------------------------------------
// Address: 0x100051F0
// Name: public: virtual int CRegistry::ReadInt(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRegistry::ReadInt(CRegistry *this, const char *pKeyBase, const char *pKey, int defaultValue)
{
  int v5; // esi
  void *v6; // esp
  char v8[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v8, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  return this->ReadInt_2(this, a2: v8, a3: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x10005260
// Name: public: virtual void CRegistry::WriteInt(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteInt(CRegistry *this, const char *pKeyBase, const char *pKey, int value)
{
  int v5; // esi
  void *v6; // esp
  char v7[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v7, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  this->WriteInt_2(this, a2: v7, a3: value);
}

//------------------------------------------------------------------------------
// Address: 0x100052D0
// Name: public: virtual char const __near * CRegistry::ReadString(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CRegistry::ReadString(
        CRegistry *this,
        const char *pKeyBase,
        const char *pKey,
        const char *defaultValue)
{
  int v5; // esi
  void *v6; // esp
  char v8[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v8, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  return this->ReadString_2(this, a2: v8, a3: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x10005340
// Name: public: virtual void CRegistry::WriteString(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteString(CRegistry *this, const char *pKeyBase, const char *pKey, const char *value)
{
  int v5; // esi
  void *v6; // esp
  char v7[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v7, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  this->WriteString_2(this, a2: v7, a3: value);
}

//------------------------------------------------------------------------------
// Address: 0x100053B0
// Name: public: virtual int CRegistry::ReadInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRegistry::ReadInt(CRegistry *this, const char *key, int defaultValue)
{
  int result; // eax
  HKEY__ *m_hKey; // [esp-18h] [ebp-20h]
  int value; // [esp+0h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+4h] [ebp-4h] BYREF

  if ( !this->m_bValid )
    return defaultValue;
  m_hKey = this->m_hKey;
  dwSize = 4;
  if ( RegQueryValueExA(
         hKey: m_hKey,
         lpValueName: key,
         lpReserved: nullptr,
         lpType: (LPDWORD)&key,
         lpData: (LPBYTE)&value,
         lpcbData: &dwSize) != 0 )
    return defaultValue;
  result = defaultValue;
  if ( key == (const char *)4 )
    return value;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005400
// Name: public: virtual void CRegistry::WriteInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteInt(CRegistry *this, const char *key, int value)
{
  if ( this->m_bValid )
    RegSetValueExA(
      hKey: this->m_hKey,
      lpValueName: key,
      Reserved: 0,
      dwType: 4u,
      lpData: (const BYTE *)&value,
      cbData: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x10005430
// Name: public: virtual char const __near * CRegistry::ReadString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CRegistry::ReadString(CRegistry *this, const char *key, char *defaultValue)
{
  bool v3; // zf
  char *result; // eax
  unsigned int dwSize; // [esp+0h] [ebp-4h] BYREF

  value[0] = 0;
  v3 = !this->m_bValid;
  dwSize = 512;
  if ( v3
    || RegQueryValueExA(
         hKey: this->m_hKey,
         lpValueName: key,
         lpReserved: nullptr,
         lpType: (LPDWORD)&key,
         lpData: (LPBYTE)value,
         lpcbData: &dwSize) != 0 )
  {
    return defaultValue;
  }
  result = defaultValue;
  if ( key == (const char *)1 )
    return value;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005490
// Name: public: virtual void CRegistry::WriteString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteString(CRegistry *this, const char *key, const char *value)
{
  if ( this->m_bValid )
    RegSetValueExA(
      hKey: this->m_hKey,
      lpValueName: key,
      Reserved: 0,
      dwType: 1u,
      lpData: (const BYTE *)value,
      cbData: strlen(value) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x100054D0
// Name: public: virtual bool CRegistry::DirectInit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRegistry::DirectInit(CRegistry *this, const char *subDirectoryUnderValve)
{
  char szModelKey[1024]; // [esp+4h] [ebp-400h] BYREF

  _wsprintfA(a1: szModelKey, a2: "Software\\Valve\\%s", subDirectoryUnderValve);
  if ( RegCreateKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: szModelKey,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 0xF003Fu,
         lpSecurityAttributes: nullptr,
         phkResult: &this->m_hKey,
         lpdwDisposition: (LPDWORD)&subDirectoryUnderValve) != 0 )
  {
    this->m_bValid = false;
    return 0;
  }
  else
  {
    this->m_bValid = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005540
// Name: public: virtual bool CRegistry::Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRegistry::Init(CRegistry *this, const char *platformName)
{
  char subDir[512]; // [esp+4h] [ebp-200h] BYREF

  _wsprintfA(a1: subDir, a2: "%s\\Settings", platformName);
  return this->DirectInit(this, a2: subDir);
}

//------------------------------------------------------------------------------
// Address: 0x10005580
// Name: public: virtual void CRegistry::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::Shutdown(CRegistry *this)
{
  HKEY__ *m_hKey; // [esp-4h] [ebp-4h]

  if ( this->m_bValid )
  {
    m_hKey = this->m_hKey;
    this->m_bValid = false;
    RegCloseKey(hKey: m_hKey);
  }
}

} // namespace localize

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x101F50E0
// Name: void ReleaseInstancedRegistry(class IRegistry __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseInstancedRegistry(IRegistry *reg)
{
  if ( reg != nullptr )
  {
    reg->Shutdown(this: reg);
    free(pMem: reg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5100
// Name: public: virtual int CRegistry::ReadInt(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRegistry::ReadInt(CRegistry *this, const char *pKeyBase, const char *pKey, int defaultValue)
{
  int v5; // esi
  void *v6; // esp
  char v8[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v8, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  return this->ReadInt_2(this, a2: v8, a3: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x101F5170
// Name: public: virtual void CRegistry::WriteInt(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteInt(CRegistry *this, const char *pKeyBase, const char *pKey, int value)
{
  int v5; // esi
  void *v6; // esp
  char v7[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v7, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  this->WriteInt_2(this, a2: v7, a3: value);
}

//------------------------------------------------------------------------------
// Address: 0x101F51E0
// Name: public: virtual char const __near * CRegistry::ReadString(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CRegistry::ReadString(
        CRegistry *this,
        const char *pKeyBase,
        const char *pKey,
        const char *defaultValue)
{
  int v5; // esi
  void *v6; // esp
  char v8[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v8, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  return this->ReadString_2(this, a2: v8, a3: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x101F5250
// Name: public: virtual void CRegistry::WriteString(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteString(CRegistry *this, const char *pKeyBase, const char *pKey, const char *value)
{
  int v5; // esi
  void *v6; // esp
  char v7[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = strlen(pKey) + strlen(pKeyBase) + 2;
  v6 = alloca(v5);
  V_snprintf(pDest: v7, maxLen: v5, pFormat: "%s\\%s", pKeyBase, pKey);
  this->WriteString_2(this, a2: v7, a3: value);
}

//------------------------------------------------------------------------------
// Address: 0x101F52C0
// Name: public: virtual int CRegistry::ReadInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRegistry::ReadInt(CRegistry *this, const char *key, int defaultValue)
{
  int result; // eax
  HKEY__ *m_hKey; // [esp-18h] [ebp-20h]
  int value; // [esp+0h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+4h] [ebp-4h] BYREF

  if ( !this->m_bValid )
    return defaultValue;
  m_hKey = this->m_hKey;
  dwSize = 4;
  if ( RegQueryValueExA(
         hKey: m_hKey,
         lpValueName: key,
         lpReserved: nullptr,
         lpType: (LPDWORD)&key,
         lpData: (LPBYTE)&value,
         lpcbData: &dwSize) != 0 )
    return defaultValue;
  result = defaultValue;
  if ( key == (const char *)4 )
    return value;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F5310
// Name: public: virtual void CRegistry::WriteInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteInt(CRegistry *this, const char *key, int value)
{
  if ( this->m_bValid )
    RegSetValueExA(
      hKey: this->m_hKey,
      lpValueName: key,
      Reserved: 0,
      dwType: 4u,
      lpData: (const BYTE *)&value,
      cbData: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x101F5340
// Name: public: virtual char const __near * CRegistry::ReadString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CRegistry::ReadString(CRegistry *this, const char *key, char *defaultValue)
{
  bool v3; // zf
  char *result; // eax
  unsigned int dwSize; // [esp+0h] [ebp-4h] BYREF

  value[0] = 0;
  v3 = !this->m_bValid;
  dwSize = 512;
  if ( v3
    || RegQueryValueExA(
         hKey: this->m_hKey,
         lpValueName: key,
         lpReserved: nullptr,
         lpType: (LPDWORD)&key,
         lpData: (LPBYTE)value,
         lpcbData: &dwSize) != 0 )
  {
    return defaultValue;
  }
  result = defaultValue;
  if ( key == (const char *)1 )
    return value;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F53A0
// Name: public: virtual void CRegistry::WriteString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::WriteString(CRegistry *this, const char *key, const char *value)
{
  if ( this->m_bValid )
    RegSetValueExA(
      hKey: this->m_hKey,
      lpValueName: key,
      Reserved: 0,
      dwType: 1u,
      lpData: (const BYTE *)value,
      cbData: strlen(value) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x101F53E0
// Name: public: virtual bool CRegistry::DirectInit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRegistry::DirectInit(CRegistry *this, const char *subDirectoryUnderValve)
{
  char szModelKey[1024]; // [esp+4h] [ebp-400h] BYREF

  _wsprintfA(a1: szModelKey, a2: "Software\\Valve\\%s", subDirectoryUnderValve);
  if ( RegCreateKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: szModelKey,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 0xF003Fu,
         lpSecurityAttributes: nullptr,
         phkResult: &this->m_hKey,
         lpdwDisposition: (LPDWORD)&subDirectoryUnderValve) != 0 )
  {
    this->m_bValid = false;
    return 0;
  }
  else
  {
    this->m_bValid = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5450
// Name: public: virtual bool CRegistry::Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRegistry::Init(CRegistry *this, const char *platformName)
{
  char subDir[512]; // [esp+4h] [ebp-200h] BYREF

  _wsprintfA(a1: subDir, a2: "%s\\Settings", platformName);
  return this->DirectInit(this, a2: subDir);
}

//------------------------------------------------------------------------------
// Address: 0x101F5490
// Name: public: virtual void CRegistry::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRegistry::Shutdown(CRegistry *this)
{
  HKEY__ *m_hKey; // [esp-4h] [ebp-4h]

  if ( this->m_bValid )
  {
    m_hKey = this->m_hKey;
    this->m_bValid = false;
    RegCloseKey(hKey: m_hKey);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F54E0
// Name: class IRegistry __near * InstanceRegistry(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IRegistry *__cdecl InstanceRegistry(const char *subDirectoryUnderValve)
{
  _BYTE *v1; // eax
  _BYTE *v2; // esi

  v1 = operator new(nSize: 0xCu);
  if ( v1 != nullptr )
  {
    v1[4] = 0;
    *((_DWORD *)v1 + 2) = 0;
    v2 = v1;
    *(_DWORD *)v1 = &CRegistry::`vftable';
    (*(void (__thiscall **)(_BYTE *, const char *))(*(_DWORD *)v1 + 44))(a1: v1, a2: subDirectoryUnderValve);
    return (IRegistry *)v2;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 44))(a1: 0, a2: subDirectoryUnderValve);
    return nullptr;
  }
}

} // namespace server
