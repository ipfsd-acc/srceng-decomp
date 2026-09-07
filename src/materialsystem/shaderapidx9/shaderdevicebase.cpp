// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/shaderdevicebase.cpp
// Functions: 60
// ============================================================

#include "materialsystem\shaderapidx9\shaderdevicebase.h"

//------------------------------------------------------------------------------
// Address: 0x100038E0
// Name: public: virtual bool CShaderDeviceBase::IsAAEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDeviceBase::IsAAEnabled(ConVar *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100105E0
// Name: public: virtual bool CShaderDeviceBase::AddView(void __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceBase::AddView(CShaderAPIDx8 *this, int textureHandle)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10023E80
// Name: void __near * ShaderDeviceFactory(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl ShaderDeviceFactory(const char *pName, int *pReturnCode)
{
  void *result; // eax
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  if ( pReturnCode != nullptr )
    *pReturnCode = 0;
  result = s_TempFactory(a1: pName, a2: pReturnCode);
  if ( result == nullptr )
  {
    FactoryThis = Sys_GetFactoryThis();
    result = FactoryThis(a1: pName, a2: pReturnCode);
    if ( result == nullptr )
    {
      if ( pReturnCode != nullptr )
        *pReturnCode = 1;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023ED0
// Name: public: virtual void CShaderDeviceMgrBase::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::Disconnect(CShaderDeviceMgrBase *this)
{
  KeyValues *m_pDXSupport; // ecx

  g_pShaderDeviceMgr = nullptr;
  g_pShaderUtil = nullptr;
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
  m_pDXSupport = this->m_pDXSupport;
  if ( m_pDXSupport != nullptr )
  {
    KeyValues::deleteThis(this: m_pDXSupport);
    this->m_pDXSupport = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023F10
// Name: public: virtual void __near * CShaderDeviceMgrBase::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceMgrBase *__thiscall CShaderDeviceMgrBase::QueryInterface(
        CShaderDeviceMgrBase *this,
        const char *pInterfaceName)
{
  if ( _V_stricmp(s1: pInterfaceName, s2: "ShaderDeviceMgr001") != 0 )
    return _V_stricmp(s1: pInterfaceName, s2: "MaterialSystemHardwareConfig013") == 0
         ? (CShaderDeviceMgrBase *)g_pHardwareConfig
         : nullptr;
  else
    return this;
}

//------------------------------------------------------------------------------
// Address: 0x10023F60
// Name: private: class KeyValues __near * CShaderDeviceMgrBase::FindDXLevelSpecificConfig(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CShaderDeviceMgrBase::FindDXLevelSpecificConfig(
        CShaderDeviceMgrBase *this,
        KeyValues *pKeyValues,
        int nDxLevel)
{
  KeyValues *FirstSubKey; // esi

  KeyValues::GetFirstSubKey(this: pKeyValues);
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
  if ( FirstSubKey == nullptr )
    return nullptr;
  while ( KeyValues::GetInt(this: FirstSubKey, keyName: "name", defaultValue: 0) != nDxLevel )
  {
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return nullptr;
  }
  return FirstSubKey;
}

//------------------------------------------------------------------------------
// Address: 0x10023FB0
// Name: private: class KeyValues __near * CShaderDeviceMgrBase::FindDXLevelAndVendorSpecificConfig(class KeyValues __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CShaderDeviceMgrBase::FindDXLevelAndVendorSpecificConfig(
        CShaderDeviceMgrBase *this,
        KeyValues *pKeyValues,
        int nDxLevel,
        int nVendorID)
{
  KeyValues *v4; // esi
  KeyValues *FirstSubKey; // edi
  int Int; // ebx
  const char *String; // esi
  int v8; // eax

  v4 = pKeyValues;
  KeyValues::GetFirstSubKey(this: pKeyValues);
  FirstSubKey = KeyValues::GetFirstSubKey(this: v4);
  if ( FirstSubKey == nullptr )
    return nullptr;
  while ( 1 )
  {
    Int = KeyValues::GetInt(this: FirstSubKey, keyName: "name", defaultValue: 0);
    String = KeyValues::GetString(this: FirstSubKey, keyName: "VendorID", defaultValue: nullptr);
    if ( String == nullptr
      || (v8 = strtol(nptr: String, endptr: (char **)&pKeyValues, ibase: 16), pKeyValues == (KeyValues *)String) )
    {
      v8 = -1;
    }
    if ( Int == nDxLevel && v8 == nVendorID )
      break;
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return nullptr;
  }
  return FirstSubKey;
}

//------------------------------------------------------------------------------
// Address: 0x10024040
// Name: private: class KeyValues __near * CShaderDeviceMgrBase::FindCardSpecificConfig(class KeyValues __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CShaderDeviceMgrBase::FindCardSpecificConfig(
        CShaderDeviceMgrBase *this,
        KeyValues *pKeyValues,
        int nVendorId,
        int nDeviceId)
{
  KeyValues *FirstSubKey; // edi
  const char *String; // esi
  const char *v6; // eax
  char *v7; // esi
  int v8; // eax
  int v9; // ebx
  const char *v10; // eax
  char *v11; // esi
  int v12; // eax
  char *v14; // [esp+Ch] [ebp-Ch] BYREF
  char *v15; // [esp+10h] [ebp-8h] BYREF
  char *endptr; // [esp+14h] [ebp-4h] BYREF
  int nFoundVendorId; // [esp+20h] [ebp+8h]

  KeyValues::GetFirstSubKey(this: pKeyValues);
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
  if ( FirstSubKey == nullptr )
    return nullptr;
  while ( 1 )
  {
    String = KeyValues::GetString(this: FirstSubKey, keyName: "VendorID", defaultValue: nullptr);
    if ( String == nullptr || (nFoundVendorId = strtol(nptr: String, &endptr, ibase: 16), endptr == String) )
      nFoundVendorId = -1;
    v6 = KeyValues::GetString(this: FirstSubKey, keyName: "MinDeviceID", defaultValue: nullptr);
    v7 = (char *)v6;
    if ( v6 == nullptr || (v8 = strtol(nptr: v6, endptr: &v15, ibase: 16), v15 == v7) )
      v9 = -1;
    else
      v9 = v8;
    v10 = KeyValues::GetString(this: FirstSubKey, keyName: "MaxDeviceID", defaultValue: nullptr);
    v11 = (char *)v10;
    if ( v10 == nullptr || (v12 = strtol(nptr: v10, endptr: &v14, ibase: 16), v14 == v11) )
      v12 = -1;
    if ( nFoundVendorId == nVendorId && nDeviceId >= v9 && nDeviceId <= v12 )
      break;
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return nullptr;
  }
  return FirstSubKey;
}

//------------------------------------------------------------------------------
// Address: 0x10024130
// Name: private: class KeyValues __near * CShaderDeviceMgrBase::ReadDXSupportKeyValues(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CShaderDeviceMgrBase::ReadDXSupportKeyValues(CShaderDeviceMgrBase *this)
{
  int v2; // eax
  KeyValues *result; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax

  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-ignoredxsupportcfg", a3: 0) != 0 )
    return nullptr;
  result = this->m_pDXSupport;
  if ( result == nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "dxsupport");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: v6,
           resourceName: "dxsupport.cfg",
           pathID: "EXECUTABLE_PATH",
           pfnEvaluateSymbolProc: nullptr) )
    {
      this->m_pDXSupport = v5;
      return v5;
    }
    else
    {
      KeyValues::deleteThis(this: v5);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100241C0
// Name: public: void CShaderDeviceMgrBase::ReadDXSupportLevels(struct HardwareCaps_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::ReadDXSupportLevels(CShaderDeviceMgrBase *this, HardwareCaps_t *caps)
{
  KeyValues *DXSupportKeyValues; // eax
  KeyValues *CardSpecificConfig; // eax
  KeyValues *v5; // esi
  int Int; // eax
  int v7; // eax
  int m_nMaxDXSupportLevel; // eax

  DXSupportKeyValues = CShaderDeviceMgrBase::ReadDXSupportKeyValues(this);
  if ( DXSupportKeyValues != nullptr )
  {
    CardSpecificConfig = CShaderDeviceMgrBase::FindCardSpecificConfig(
                           this,
                           pKeyValues: DXSupportKeyValues,
                           nVendorId: caps->m_VendorID,
                           nDeviceId: caps->m_DeviceID);
    v5 = CardSpecificConfig;
    if ( CardSpecificConfig != nullptr )
    {
      Int = KeyValues::GetInt(this: CardSpecificConfig, keyName: "setting.MaxDXLevel", defaultValue: 0);
      if ( Int != 0 )
        caps->m_nMaxDXSupportLevel = Int;
      v7 = KeyValues::GetInt(this: v5, keyName: "setting.MinDXLevel", defaultValue: 0);
      if ( v7 != 0 && v7 <= caps->m_nMaxDXSupportLevel )
        caps->m_nMinDXSupportLevel = v7;
      m_nMaxDXSupportLevel = KeyValues::GetInt(this: v5, keyName: "setting.DXLevel", defaultValue: 0);
      if ( m_nMaxDXSupportLevel == 0 )
        m_nMaxDXSupportLevel = caps->m_nMaxDXSupportLevel;
      caps->m_nDXSupportLevel = m_nMaxDXSupportLevel;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024250
// Name: public: static void __near * CShaderDeviceMgrBase::ShaderInterfaceFactory(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
CShaderAPIBase *__cdecl CShaderDeviceMgrBase::ShaderInterfaceFactory(const char *pInterfaceName, int *pReturnCode)
{
  if ( pReturnCode != nullptr )
    *pReturnCode = 0;
  if ( _V_stricmp(s1: pInterfaceName, s2: "ShaderDevice001") == 0 )
    return (CShaderAPIBase *)g_pShaderDevice;
  if ( _V_stricmp(s1: pInterfaceName, s2: "ShaderApi029") == 0 )
    return g_pShaderAPI;
  if ( _V_stricmp(s1: pInterfaceName, s2: "ShaderShadow010") == 0 )
    return (CShaderAPIBase *)g_pShaderShadow;
  if ( pReturnCode != nullptr )
    *pReturnCode = 1;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100242D0
// Name: public: virtual CShaderDeviceBase::~CShaderDeviceBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::~CShaderDeviceBase(CShaderDeviceBase *this)
{
  this->__vftable = (CShaderDeviceBase_vtbl *)&CShaderDeviceBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100242F0
// Name: protected: void CShaderDeviceBase::SetCurrentThreadAsOwner(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::SetCurrentThreadAsOwner(CShaderDeviceBase *this)
{
  this->m_dwThreadId = GetCurrentThreadId();
}

//------------------------------------------------------------------------------
// Address: 0x10024300
// Name: protected: void CShaderDeviceBase::RemoveThreadOwner(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::RemoveThreadOwner(CShaderDeviceBase *this)
{
  this->m_dwThreadId = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10024310
// Name: protected: bool CShaderDeviceBase::ThreadOwnsDevice(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDeviceBase::ThreadOwnsDevice(CShaderDeviceBase *this)
{
  return GetCurrentThreadId() == this->m_dwThreadId;
}

//------------------------------------------------------------------------------
// Address: 0x10024330
// Name: public: virtual enum ImageFormat CShaderDeviceBase::GetBackBufferFormat(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceBase::GetBackBufferFormat(CShaderDeviceBase *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10024340
// Name: EnumChildWindowsProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EnumChildWindowsProc(HWND__ *hWnd, unsigned int lParam)
{
  tagCOPYDATASTRUCT copyData; // [esp+4h] [ebp-Ch] BYREF

  if ( GetWindowLongA(hWnd, nIndex: -21) == -17965395 )
  {
    copyData.dwData = lParam;
    copyData.cbData = 0;
    copyData.lpData = nullptr;
    SendMessageA(hWnd, Msg: 0x4Au, wParam: 0, lParam: (LPARAM)&copyData);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10024390
// Name: EnumWindowsProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EnumWindowsProc(HWND__ *hWnd, LPARAM lParam)
{
  EnumChildWindows(hWndParent: hWnd, lpEnumFunc: (WNDENUMPROC)EnumChildWindowsProc, lParam);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100243B0
// Name: EnumWindowsProcNotThis
// Source: json
//------------------------------------------------------------------------------
int __stdcall EnumWindowsProcNotThis(HWND hWnd, LPARAM lParam)
{
  HWND__ *m_hWndCookie; // esi
  HWND i; // eax

  if ( g_pShaderDevice == nullptr )
    goto LABEL_5;
  m_hWndCookie = (HWND__ *)g_pShaderDevice->m_hWndCookie;
  for ( i = GetParent(hWnd: m_hWndCookie); i != nullptr; i = GetParent(hWnd: i) )
    m_hWndCookie = i;
  if ( m_hWndCookie != hWnd )
LABEL_5:
    EnumChildWindows(hWndParent: hWnd, lpEnumFunc: (WNDENUMPROC)EnumChildWindowsProc, lParam);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10024400
// Name: ShaderDX8WndProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall ShaderDX8WndProc(HWND__ *hWnd, UINT msg, WPARAM wParam, int *lParam)
{
  int v4; // eax

  if ( msg == 74 && g_pShaderDevice != nullptr )
  {
    v4 = *lParam;
    if ( *lParam == 1584664032 )
    {
      ((void (__stdcall *)(int))g_pShaderDevice->OtherAppInitializing)(a1: 1);
    }
    else if ( v4 == 1584664033 )
    {
      ((void (__stdcall *)(_DWORD))g_pShaderDevice->OtherAppInitializing)(a1: 0);
    }
    else if ( v4 == 1584664034 )
    {
      ((void (*)(void))g_pShaderDevice->EvictManagedResourcesInternal)();
    }
  }
  return DefWindowProcA(hWnd, Msg: msg, wParam, (LPARAM)lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10024470
// Name: protected: void CShaderDeviceBase::InstallWindowHook(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::InstallWindowHook(CShaderDeviceBase *this, HWND hWnd)
{
  HWND v2; // esi
  HWND i; // eax
  HINSTANCE__ *WindowLongA; // edi
  HWND Window; // eax
  tagWNDCLASSA wc; // [esp+Ch] [ebp-28h] BYREF

  v2 = hWnd;
  for ( i = GetParent(hWnd); i != nullptr; i = GetParent(hWnd: i) )
    v2 = i;
  WindowLongA = (HINSTANCE__ *)GetWindowLongA(hWnd: v2, nIndex: -6);
  memset(&wc.hIcon, 0, 16);
  *(_QWORD *)&wc.cbClsExtra = 0;
  wc.style = 640;
  wc.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))ShaderDX8WndProc;
  wc.hInstance = WindowLongA;
  wc.lpszClassName = "shaderdx8";
  UnregisterClassA(lpClassName: "shaderdx8", hInstance: WindowLongA);
  RegisterClassA(lpWndClass: &wc);
  Window = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: "shaderdx8",
             lpWindowName: "shaderdx8",
             dwStyle: 0x40000000u,
             X: 0,
             Y: 0,
             nWidth: 0,
             nHeight: 0,
             hWndParent: v2,
             hMenu: nullptr,
             hInstance: WindowLongA,
             lpParam: nullptr);
  this->m_hWndCookie = Window;
  SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: -17965395);
}

//------------------------------------------------------------------------------
// Address: 0x10024530
// Name: protected: void CShaderDeviceBase::RemoveWindowHook(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::RemoveWindowHook(CShaderDeviceBase *this, HWND hWnd)
{
  HWND v3; // esi
  HWND i; // eax
  HINSTANCE WindowLongA; // eax

  if ( this->m_hWndCookie != nullptr )
  {
    DestroyWindow(hWnd: (HWND)this->m_hWndCookie);
    this->m_hWndCookie = nullptr;
  }
  v3 = hWnd;
  for ( i = GetParent(hWnd); i != nullptr; i = GetParent(hWnd: i) )
    v3 = i;
  WindowLongA = (HINSTANCE)GetWindowLongA(hWnd: v3, nIndex: -6);
  UnregisterClassA(lpClassName: "shaderdx8", hInstance: WindowLongA);
}

//------------------------------------------------------------------------------
// Address: 0x10024590
// Name: public: void CShaderDeviceBase::SendIPCMessage(enum CShaderDeviceBase::IPCMessage_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::SendIPCMessage(CShaderDeviceBase *this, LPARAM msg)
{
  if ( msg == 1584664034 )
    EnumWindows(lpEnumFunc: EnumWindowsProcNotThis, lParam: 1584664034);
  else
    EnumWindows(lpEnumFunc: EnumWindowsProc, lParam: msg);
}

//------------------------------------------------------------------------------
// Address: 0x100245D0
// Name: public: virtual void CShaderDeviceBase::SetView(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::SetView(CShaderDeviceBase *this, void *hWnd)
{
  void (__thiscall *GetWindowSize)(struct CShaderDeviceBase *, int *, int *); // edx
  ShaderViewport_t viewport; // [esp+4h] [ebp-1Ch] BYREF

  viewport.m_nVersion = 1;
  g_pShaderAPI->GetViewports(this: g_pShaderAPI, a2: &viewport, a3: 1);
  GetWindowSize = this->GetWindowSize;
  this->m_ViewHWnd = hWnd;
  GetWindowSize(this, a2: &this->m_nWindowWidth, a3: &this->m_nWindowHeight);
  g_pShaderAPI->SetViewports(this: g_pShaderAPI, a2: 1, a3: &viewport, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x10024630
// Name: public: virtual void CShaderDeviceBase::GetWindowSize(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::GetWindowSize(CShaderDeviceBase *this, int *nWidth, int *nHeight)
{
  int v4; // edx
  tagRECT rect; // [esp+4h] [ebp-10h] BYREF

  if ( (*((_BYTE *)this + 16) & 2) != 0 || IsIconic(hWnd: (HWND)this->m_hWnd) )
  {
    *nHeight = 0;
    *nWidth = 0;
  }
  else
  {
    GetClientRect(hWnd: (HWND)this->m_ViewHWnd, lpRect: &rect);
    v4 = rect.bottom - rect.top;
    *nWidth = rect.right - rect.left;
    *nHeight = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024740
// Name: public: virtual bool CShaderAPIConVarAccessor::RegisterConCommandBase(class ConCommandBase __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderAPIConVarAccessor::RegisterConCommandBase(
        CShaderAPIConVarAccessor *this,
        ConCommandBase *pCommand)
{
  ICvar_vtbl *v2; // edi
  const char *v3; // eax
  int v4; // edi

  g_pCVar->RegisterConCommand(this: g_pCVar, a2: pCommand);
  v2 = g_pCVar->__vftable;
  v3 = pCommand->GetName(this: pCommand);
  v4 = (int)v2->GetCommandLineValue(this: g_pCVar, a2: v3);
  if ( v4 != 0 && !pCommand->IsCommand(this: pCommand) )
    pCommand[1].AddFlags(this: &pCommand[1], a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100247A0
// Name: private: void CShaderDeviceMgrBase::LoadHardwareCaps(class KeyValues __near *,struct HardwareCaps_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::LoadHardwareCaps(
        CShaderDeviceMgrBase *this,
        KeyValues *pGroup,
        HardwareCaps_t *caps)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  HardwareCaps_t *v6; // esi
  bool v7; // bl
  int Int; // eax
  bool v9; // bl
  int v10; // eax
  bool v11; // al
  bool v12; // bl
  int v13; // eax
  bool v14; // al
  char v15; // bl
  bool v16; // bl
  int v17; // eax
  bool v18; // al
  bool v19; // bl
  int v20; // eax
  bool v21; // al
  bool v22; // bl
  int v23; // eax
  bool v24; // al
  bool v25; // bl
  int v26; // eax
  char v27; // al
  char v28; // bl
  int v29; // eax
  char v30; // al

  if ( pGroup != nullptr )
  {
    v3 = _CommandLine(a1: this);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-arbmode") != 0
      || (v5 = _CommandLine(a1: v4),
          (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-nouserclip", a3: 0) != 0)
      || r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    {
      v6 = caps;
      *((_BYTE *)caps + 717) |= 8u;
    }
    else
    {
      v6 = caps;
      v7 = (*((_BYTE *)caps + 717) & 8) != 0;
      Int = KeyValues::GetInt(this: pGroup, keyName: "setting.NoUserClipPlanes", defaultValue: -1);
      if ( Int != -1 )
        v7 = Int != 0;
      *((_BYTE *)caps + 717) ^= (*((_BYTE *)caps + 717) ^ (8 * v7)) & 8;
    }
    v9 = (*((_BYTE *)v6 + 717) & 0x10) != 0;
    v10 = KeyValues::GetInt(this: pGroup, keyName: "setting.CentroidHack", defaultValue: -1);
    if ( v10 == -1 )
      v11 = v9;
    else
      v11 = v10 != 0;
    *((_BYTE *)v6 + 717) ^= (*((_BYTE *)v6 + 717) ^ (16 * v11)) & 0x10;
    v12 = (*((_BYTE *)v6 + 717) & 0x20) != 0;
    v13 = KeyValues::GetInt(this: pGroup, keyName: "setting.DisableShaderOptimizations", defaultValue: -1);
    if ( v13 == -1 )
      v14 = v12;
    else
      v14 = v13 != 0;
    v15 = *((_BYTE *)v6 + 719);
    *((_BYTE *)v6 + 717) ^= (*((_BYTE *)v6 + 717) ^ (32 * v14)) & 0x20;
    v16 = (v15 & 8) != 0;
    v17 = KeyValues::GetInt(this: pGroup, keyName: "setting.PreferZPrepass", defaultValue: -1);
    if ( v17 == -1 )
      v18 = v16;
    else
      v18 = v17 != 0;
    *((_BYTE *)v6 + 719) ^= (*((_BYTE *)v6 + 719) ^ (8 * v18)) & 8;
    v19 = (*((_BYTE *)v6 + 719) & 0x10) != 0;
    v20 = KeyValues::GetInt(this: pGroup, keyName: "setting.SuppressPixelShaderCentroidHackFixup", defaultValue: -1);
    if ( v20 == -1 )
      v21 = v19;
    else
      v21 = v20 != 0;
    *((_BYTE *)v6 + 719) ^= (*((_BYTE *)v6 + 719) ^ (16 * v21)) & 0x10;
    v22 = (*((_BYTE *)v6 + 719) & 0x20) != 0;
    v23 = KeyValues::GetInt(this: pGroup, keyName: "setting.PreferTexturesInHWMemory", defaultValue: -1);
    if ( v23 == -1 )
      v24 = v22;
    else
      v24 = v23 != 0;
    *((_BYTE *)v6 + 719) ^= (*((_BYTE *)v6 + 719) ^ (32 * v24)) & 0x20;
    v25 = (*((_BYTE *)v6 + 719) & 0x40) != 0;
    v26 = KeyValues::GetInt(this: pGroup, keyName: "setting.PreferHardwareSync", defaultValue: -1);
    if ( v26 == -1 )
      v27 = v25;
    else
      v27 = v26 != 0;
    *((_BYTE *)v6 + 719) ^= (*((_BYTE *)v6 + 719) ^ (v27 << 6)) & 0x40;
    v28 = *((_BYTE *)v6 + 719) >> 7;
    v29 = KeyValues::GetInt(this: pGroup, keyName: "setting.Unsupported", defaultValue: -1);
    if ( v29 == -1 )
      v30 = v28;
    else
      v30 = v29 != 0;
    *((_BYTE *)v6 + 719) = (v30 << 7) | *((_BYTE *)v6 + 719) & 0x7F;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100249E0
// Name: public: void CShaderDeviceMgrBase::ReadHardwareCaps(struct HardwareCaps_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::ReadHardwareCaps(
        CShaderDeviceMgrBase *this,
        HardwareCaps_t *caps,
        HardwareCaps_t *nDxLevel)
{
  KeyValues *DXSupportKeyValues; // ebx
  KeyValues *DXLevelSpecificConfig; // eax
  HardwareCaps_t *v6; // edi
  KeyValues *CardSpecificConfig; // eax
  KeyValues *v8; // ebx
  HardwareCaps_t *String; // eax
  int v10; // eax
  HardwareCaps_t *v11; // eax
  int v12; // eax
  KeyValues *pDXLevelAndVendorKeyValue; // [esp+8h] [ebp-8h]
  KeyValues *pDxLevelKeyValues; // [esp+Ch] [ebp-4h]

  DXSupportKeyValues = CShaderDeviceMgrBase::ReadDXSupportKeyValues(this);
  if ( DXSupportKeyValues != nullptr )
  {
    DXLevelSpecificConfig = CShaderDeviceMgrBase::FindDXLevelSpecificConfig(
                              this,
                              pKeyValues: DXSupportKeyValues,
                              (int)nDxLevel);
    v6 = caps;
    pDxLevelKeyValues = DXLevelSpecificConfig;
    pDXLevelAndVendorKeyValue = CShaderDeviceMgrBase::FindDXLevelAndVendorSpecificConfig(
                                  this,
                                  pKeyValues: DXSupportKeyValues,
                                  (int)nDxLevel,
                                  nVendorID: caps->m_VendorID);
    CardSpecificConfig = CShaderDeviceMgrBase::FindCardSpecificConfig(
                           this,
                           pKeyValues: DXSupportKeyValues,
                           nVendorId: v6->m_VendorID,
                           nDeviceId: v6->m_DeviceID);
    v8 = CardSpecificConfig;
    if ( CardSpecificConfig != nullptr
      && (String = (HardwareCaps_t *)KeyValues::GetString(
                                       this: CardSpecificConfig,
                                       keyName: "MinDeviceID",
                                       defaultValue: nullptr),
          nDxLevel = String,
          String != nullptr)
      && (v10 = strtol(nptr: String->m_pDriverName, endptr: (char **)&caps, ibase: 16), caps != nDxLevel)
      && v10 == 0
      && (v11 = (HardwareCaps_t *)KeyValues::GetString(this: v8, keyName: "MaxDeviceID", defaultValue: nullptr),
          nDxLevel = v11,
          v11 != nullptr)
      && (v12 = strtol(nptr: v11->m_pDriverName, endptr: (char **)&caps, ibase: 16), caps != nDxLevel)
      && v12 == 0xFFFF )
    {
      CShaderDeviceMgrBase::LoadHardwareCaps(this, pGroup: pDxLevelKeyValues, caps: v6);
      CShaderDeviceMgrBase::LoadHardwareCaps(this, pGroup: v8, caps: v6);
      CShaderDeviceMgrBase::LoadHardwareCaps(this, pGroup: pDXLevelAndVendorKeyValue, caps: v6);
    }
    else
    {
      CShaderDeviceMgrBase::LoadHardwareCaps(this, pGroup: pDxLevelKeyValues, caps: v6);
      CShaderDeviceMgrBase::LoadHardwareCaps(this, pGroup: v8, caps: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024AF0
// Name: public: int CShaderDeviceMgrBase::GetClosestActualDXLevel(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceMgrBase::GetClosestActualDXLevel(CShaderDeviceMgrBase *this, int nDxLevel)
{
  if ( nDxLevel < 92 )
    return 90;
  if ( nDxLevel < 95 || r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    return 92;
  return nDxLevel >= 100 ? 100 : 95;
}

//------------------------------------------------------------------------------
// Address: 0x10024B40
// Name: public: CShaderDeviceBase::CShaderDeviceBase(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceBase *__thiscall CShaderDeviceBase::CShaderDeviceBase(CShaderDeviceBase *this)
{
  *((_BYTE *)this + 16) &= ~1u;
  this->__vftable = (CShaderDeviceBase_vtbl *)&CShaderDeviceBase::`vftable';
  this->m_nAdapter = -1;
  this->m_hWnd = nullptr;
  this->m_hWndCookie = nullptr;
  this->m_dwThreadId = GetCurrentThreadId();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10024BA0
// Name: public: virtual void CBaseAppSystem<class IShaderDeviceMgr>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IShaderDeviceMgr>::Reconnect(
        CBaseAppSystem<IShaderDeviceMgr> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10024BC0
// Name: public: virtual bool CShaderDeviceMgrBase::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrBase::Connect(
        CShaderDeviceMgrBase *this,
        void *(__cdecl *factory)(const char *, int *))
{
  IShaderUtil *v3; // eax
  void *(__cdecl *FactoryThis)(const char *, int *); // eax
  IVJobs *v5; // eax
  void *(__cdecl *v6)(const char *, int *); // eax

  s_TempFactory = factory;
  factory = ShaderDeviceFactory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    pAccessor.__vftable = (IConCommandBaseAccessor_vtbl *)&CShaderAPIConVarAccessor::`vftable';
  }
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0x800000, pAccessor: &pAccessor);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  if ( g_pShaderUtil == nullptr )
  {
    v3 = (IShaderUtil *)s_TempFactory(a1: "VShaderUtil001", a2: nullptr);
    if ( v3 == nullptr )
    {
      FactoryThis = Sys_GetFactoryThis();
      v3 = (IShaderUtil *)FactoryThis(a1: "VShaderUtil001", a2: nullptr);
    }
    g_pShaderUtil = v3;
  }
  if ( g_pVJobs == nullptr )
  {
    v5 = (IVJobs *)s_TempFactory(a1: "VJobs01", a2: nullptr);
    if ( v5 == nullptr )
    {
      v6 = Sys_GetFactoryThis();
      v5 = (IVJobs *)v6(a1: "VJobs01", a2: nullptr);
    }
    g_pVJobs = v5;
  }
  g_pShaderDeviceMgr = this;
  s_TempFactory = nullptr;
  if ( g_pShaderUtil != nullptr && g_pFullFileSystem != nullptr && this != nullptr )
  {
    MathLib_Init(
      gamma: 2.2,
      texGamma: 2.2,
      brightness: 0.0,
      overbright: 2,
      bAllow3DNow: true,
      bAllowSSE: true,
      bAllowSSE2: true,
      bAllowMMX: true);
    return 1;
  }
  else
  {
    _Warning(a1: "ShaderAPIDx10 was unable to access the required interfaces!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024D00
// Name: public: struct HardwareCaps_t const __near & CShaderDeviceMgrBase::GetHardwareCaps(int)const
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceMgrBase::AdapterInfo_t *__thiscall CShaderDeviceMgrBase::GetHardwareCaps(
        CShaderDeviceMgrBase *this,
        int nAdapter)
{
  return &this->m_Adapters.m_Memory.m_pMemory[nAdapter];
}

//------------------------------------------------------------------------------
// Address: 0x10024D20
// Name: public: void CShaderDeviceMgrBase::InvokeModeChangeCallbacks(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::InvokeModeChangeCallbacks(
        CShaderDeviceMgrBase *this,
        int screenWidth,
        int screenHeight)
{
  int m_Size; // ebx
  int i; // esi
  int v6; // ebx
  int j; // esi
  IShaderDeviceDependentObject *v8; // ecx

  m_Size = this->m_ModeChangeCallbacks.m_Size;
  for ( i = 0; i < m_Size; ++i )
    this->m_ModeChangeCallbacks.m_Memory.m_pMemory[i]();
  v6 = this->m_DeviceDependentObjects.m_Size;
  for ( j = 0; j < v6; ++j )
  {
    v8 = this->m_DeviceDependentObjects.m_Memory.m_pMemory[j];
    v8->ScreenSizeChanged(this: v8, a2: screenWidth, a3: screenHeight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024D70
// Name: public: virtual void CShaderDeviceMgrBase::InvokeDeviceLostNotifications(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::InvokeDeviceLostNotifications(CShaderDeviceMgrBase *this)
{
  int m_Size; // ebx
  int i; // esi
  IShaderDeviceDependentObject *v4; // ecx

  m_Size = this->m_DeviceDependentObjects.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v4 = this->m_DeviceDependentObjects.m_Memory.m_pMemory[i];
    v4->DeviceLost(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024DA0
// Name: public: virtual void CShaderDeviceMgrBase::InvokeDeviceResetNotifications(struct IDirect3DDevice9 __near *,struct _D3DPRESENT_PARAMETERS_ __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::InvokeDeviceResetNotifications(
        CShaderDeviceMgrBase *this,
        IDirect3DDevice9 *pDevice,
        _D3DPRESENT_PARAMETERS_ *pPresentParameters,
        void *pHWnd)
{
  int m_Size; // ebx
  int i; // esi
  IShaderDeviceDependentObject *v7; // ecx

  m_Size = this->m_DeviceDependentObjects.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v7 = this->m_DeviceDependentObjects.m_Memory.m_pMemory[i];
    v7->DeviceReset(this: v7, a2: pDevice, a3: pPresentParameters, a4: pHWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024F00
// Name: public: virtual void CShaderDeviceMgrBase::RemoveModeChangeCallback(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::RemoveModeChangeCallback(CShaderDeviceMgrBase *this, void (__cdecl *func)())
{
  CUtlVector<void (__cdecl *)(void),CUtlMemory<void (__cdecl *)(void),int>>::FindAndRemove(
    this: (CUtlVector<IShaderDeviceDependentObject *,CUtlMemory<IShaderDeviceDependentObject *,int> > *)&this->m_ModeChangeCallbacks,
    src: (IShaderDeviceDependentObject *const *)&func);
}

//------------------------------------------------------------------------------
// Address: 0x10024F20
// Name: public: virtual void CShaderDeviceMgrBase::RemoveDeviceDependentObject(class IShaderDeviceDependentObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::RemoveDeviceDependentObject(
        CShaderDeviceMgrBase *this,
        IShaderDeviceDependentObject *pObject)
{
  if ( pObject != nullptr )
    CUtlVector<void (__cdecl *)(void),CUtlMemory<void (__cdecl *)(void),int>>::FindAndRemove(
      this: &this->m_DeviceDependentObjects,
      src: &pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10024F40
// Name: public: CShaderDeviceMgrBase::CShaderDeviceMgrBase(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceMgrBase *__thiscall CShaderDeviceMgrBase::CShaderDeviceMgrBase(CShaderDeviceMgrBase *this)
{
  this->__vftable = (CShaderDeviceMgrBase_vtbl *)&CShaderDeviceMgrBase::`vftable';
  this->m_Adapters.m_Memory.m_pMemory = nullptr;
  this->m_Adapters.m_Memory.m_nAllocationCount = 0;
  this->m_Adapters.m_Memory.m_nGrowSize = 0;
  this->m_Adapters.m_Size = 0;
  this->m_Adapters.m_pElements = nullptr;
  this->m_ModeChangeCallbacks.m_Memory.m_pMemory = nullptr;
  this->m_ModeChangeCallbacks.m_Memory.m_nAllocationCount = 0;
  this->m_ModeChangeCallbacks.m_Memory.m_nGrowSize = 0;
  this->m_ModeChangeCallbacks.m_Size = 0;
  this->m_ModeChangeCallbacks.m_pElements = nullptr;
  this->m_DeviceDependentObjects.m_Memory.m_pMemory = nullptr;
  this->m_DeviceDependentObjects.m_Memory.m_nAllocationCount = 0;
  this->m_DeviceDependentObjects.m_Memory.m_nGrowSize = 0;
  this->m_DeviceDependentObjects.m_Size = 0;
  this->m_DeviceDependentObjects.m_pElements = nullptr;
  this->m_pDXSupport = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10024F80
// Name: public: virtual CShaderDeviceMgrBase::~CShaderDeviceMgrBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::~CShaderDeviceMgrBase(CShaderDeviceMgrBase *this)
{
  this->__vftable = (CShaderDeviceMgrBase_vtbl *)&CShaderDeviceMgrBase::`vftable';
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_DeviceDependentObjects);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ModeChangeCallbacks);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Adapters);
}

//------------------------------------------------------------------------------
// Address: 0x10024FB0
// Name: public: virtual void CShaderDeviceMgrBase::AddModeChangeCallback(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::AddModeChangeCallback(CShaderDeviceMgrBase *this, void (__cdecl *func)())
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_ModeChangeCallbacks; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_ModeChangeCallbacks.m_Memory.m_nAllocationCount;
  p_m_ModeChangeCallbacks = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ModeChangeCallbacks;
  m_Size = this->m_ModeChangeCallbacks.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>::Grow(
      this: p_m_ModeChangeCallbacks,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ModeChangeCallbacks[1].m_pMemory;
  m_pMemory = p_m_ModeChangeCallbacks->m_pMemory;
  v6 = (int)p_m_ModeChangeCallbacks[1].m_pMemory - m_Size - 1;
  p_m_ModeChangeCallbacks[1].m_nAllocationCount = (int)p_m_ModeChangeCallbacks->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_ModeChangeCallbacks->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (CUtlSymbolTable::StringPool_t *)func;
}

//------------------------------------------------------------------------------
// Address: 0x10025010
// Name: public: virtual void CShaderDeviceMgrBase::AddDeviceDependentObject(class IShaderDeviceDependentObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::AddDeviceDependentObject(
        CShaderDeviceMgrBase *this,
        CUtlSymbolTable::StringPool_t *pObject)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_DeviceDependentObjects; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  if ( pObject != nullptr )
  {
    m_nAllocationCount = this->m_DeviceDependentObjects.m_Memory.m_nAllocationCount;
    p_m_DeviceDependentObjects = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_DeviceDependentObjects;
    m_Size = this->m_DeviceDependentObjects.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>::Grow(
        this: p_m_DeviceDependentObjects,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_DeviceDependentObjects[1].m_pMemory;
    m_pMemory = p_m_DeviceDependentObjects->m_pMemory;
    v6 = (int)p_m_DeviceDependentObjects[1].m_pMemory - m_Size - 1;
    p_m_DeviceDependentObjects[1].m_nAllocationCount = (int)p_m_DeviceDependentObjects->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &p_m_DeviceDependentObjects->m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = pObject;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100250C0
// Name: private: bool CShaderDeviceMgrBase::GetRecommendedVideoConfig(int,int,int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrBase::GetRecommendedVideoConfig(
        CShaderDeviceMgrBase *this,
        int nAdapter,
        int nVendorID,
        int nDeviceID,
        KeyValues *pConfiguration)
{
  int v5; // edi
  CShaderDeviceMgrBase_vtbl *v7; // edx
  int v8; // eax
  void (__thiscall *GetDesktopResolution)(CShaderDeviceMgrBase *, int *, int *, int); // edx
  ShaderDisplayMode_t *m_pMemory; // eax
  _MEMORYSTATUS Buffer; // [esp+Ch] [ebp-19Ch] BYREF
  VidMatConfigData_t configData; // [esp+2Ch] [ebp-17Ch] BYREF
  int nModeCount; // [esp+1B4h] [ebp+Ch]
  KeyValues *pConfigurationa; // [esp+1BCh] [ebp+14h]

  v5 = 0;
  memset(&configData.displayModes, 0, sizeof(configData.displayModes));
  _V_strcpy(dest: configData.szFileName, src: "cfg\\moddefaults.txt");
  _V_strcpy(dest: configData.szPathID, src: "MOD");
  configData.pConfigKeys = pConfiguration;
  configData.nVendorID = nVendorID;
  configData.nDeviceID = nDeviceID;
  GlobalMemoryStatus(lpBuffer: &Buffer);
  v7 = this->__vftable;
  configData.nSystemMemory = Buffer.dwTotalPhys >> 20;
  configData.nVideoMemory = v7->GetVidMemBytes(this, a2: nAdapter) / 0x100000;
  configData.bIsVideo = true;
  v8 = g_pHardwareConfig->GetMaxDXSupportLevel(this: g_pHardwareConfig);
  GetDesktopResolution = this->GetDesktopResolution;
  configData.nDXLevel = v8;
  GetDesktopResolution(this, a2: &configData.nPhysicalScreenWidth, a3: &configData.nPhysicalScreenHeight, a4: nAdapter);
  nModeCount = this->GetModeCount(this, a2: nAdapter);
  configData.displayModes.m_Size = 0;
  CUtlVector<ShaderDisplayMode_t,CUtlMemory<ShaderDisplayMode_t,int>>::InsertMultipleBefore(
    this: &configData.displayModes,
    elem: 0,
    num: nModeCount);
  if ( nModeCount > 0 )
  {
    pConfigurationa = nullptr;
    do
    {
      this->GetModeInfo(
        this,
        a2: (ShaderDisplayMode_t *)((char *)configData.displayModes.m_Memory.m_pMemory + (unsigned int)pConfigurationa),
        a3: nAdapter,
        a4: v5);
      pConfigurationa = (KeyValues *)((char *)pConfigurationa + 24);
      ++v5;
    }
    while ( v5 < nModeCount );
  }
  RecommendedConfig(&configData);
  UpdateVideoConfigConVars(pConfigKeys: configData.pConfigKeys);
  m_pMemory = configData.displayModes.m_Memory.m_pMemory;
  configData.displayModes.m_Size = 0;
  if ( configData.displayModes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( configData.displayModes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: configData.displayModes.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      configData.displayModes.m_Memory.m_pMemory = nullptr;
    }
    configData.displayModes.m_Memory.m_nAllocationCount = 0;
  }
  configData.displayModes.m_pElements = m_pMemory;
  if ( configData.displayModes.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025220
// Name: private: bool CShaderDeviceMgrBase::GetRecommendedConfigurationInfo(int,int,int,int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrBase::GetRecommendedConfigurationInfo(
        CShaderDeviceMgrBase *this,
        int nAdapter,
        int nDXLevel,
        int nVendorID,
        int nDeviceID,
        KeyValues *pConfiguration)
{
  int v6; // edi
  CShaderDeviceMgrBase_vtbl *v8; // edx
  int v9; // eax
  void (__thiscall *GetDesktopResolution)(CShaderDeviceMgrBase *, int *, int *, int); // edx
  ShaderDisplayMode_t *m_pMemory; // eax
  _MEMORYSTATUS Buffer; // [esp+Ch] [ebp-19Ch] BYREF
  VidMatConfigData_t configData; // [esp+2Ch] [ebp-17Ch] BYREF
  int nModeCount; // [esp+1B8h] [ebp+10h]
  KeyValues *pConfigurationa; // [esp+1C0h] [ebp+18h]

  v6 = 0;
  memset(&configData.displayModes, 0, sizeof(configData.displayModes));
  _V_strcpy(dest: configData.szFileName, src: "..\\bin\\dxsupport.cfg");
  _V_strcpy(dest: configData.szPathID, src: "GAME");
  configData.pConfigKeys = pConfiguration;
  configData.nVendorID = nVendorID;
  configData.nDeviceID = nDeviceID;
  GlobalMemoryStatus(lpBuffer: &Buffer);
  v8 = this->__vftable;
  configData.nSystemMemory = Buffer.dwTotalPhys >> 20;
  configData.nVideoMemory = v8->GetVidMemBytes(this, a2: nAdapter) / 0x100000;
  configData.bIsVideo = false;
  v9 = g_pHardwareConfig->GetMaxDXSupportLevel(this: g_pHardwareConfig);
  GetDesktopResolution = this->GetDesktopResolution;
  configData.nDXLevel = v9;
  GetDesktopResolution(this, a2: &configData.nPhysicalScreenWidth, a3: &configData.nPhysicalScreenHeight, a4: nAdapter);
  nModeCount = this->GetModeCount(this, a2: nAdapter);
  configData.displayModes.m_Size = 0;
  CUtlVector<ShaderDisplayMode_t,CUtlMemory<ShaderDisplayMode_t,int>>::InsertMultipleBefore(
    this: &configData.displayModes,
    elem: 0,
    num: nModeCount);
  if ( nModeCount > 0 )
  {
    pConfigurationa = nullptr;
    do
    {
      this->GetModeInfo(
        this,
        a2: (ShaderDisplayMode_t *)((char *)configData.displayModes.m_Memory.m_pMemory + (unsigned int)pConfigurationa),
        a3: nAdapter,
        a4: v6);
      pConfigurationa = (KeyValues *)((char *)pConfigurationa + 24);
      ++v6;
    }
    while ( v6 < nModeCount );
  }
  RecommendedConfig(&configData);
  m_pMemory = configData.displayModes.m_Memory.m_pMemory;
  configData.displayModes.m_Size = 0;
  if ( configData.displayModes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( configData.displayModes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: configData.displayModes.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      configData.displayModes.m_Memory.m_pMemory = nullptr;
    }
    configData.displayModes.m_Memory.m_nAllocationCount = 0;
  }
  configData.displayModes.m_pElements = m_pMemory;
  if ( configData.displayModes.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025370
// Name: public: virtual bool CShaderDeviceMgrBase::GetRecommendedVideoConfig(int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrBase::GetRecommendedVideoConfig(
        CShaderDeviceMgrBase *this,
        int nAdapter,
        KeyValues *pCongifuration)
{
  MaterialAdapterInfo_t info; // [esp+8h] [ebp-224h] BYREF

  this->GetAdapterInfo(this, a2: nAdapter, a3: &info);
  return CShaderDeviceMgrBase::GetRecommendedVideoConfig(
           this,
           nAdapter,
           nVendorID: info.m_VendorID,
           nDeviceID: info.m_DeviceID,
           pConfiguration: pCongifuration);
}

//------------------------------------------------------------------------------
// Address: 0x100253B0
// Name: public: virtual bool CShaderDeviceMgrBase::GetRecommendedConfigurationInfo(int,int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrBase::GetRecommendedConfigurationInfo(
        CShaderDeviceMgrBase *this,
        int nAdapter,
        int nDXLevel,
        KeyValues *pCongifuration)
{
  MaterialAdapterInfo_t info; // [esp+8h] [ebp-224h] BYREF

  this->GetAdapterInfo(this, a2: nAdapter, a3: &info);
  return CShaderDeviceMgrBase::GetRecommendedConfigurationInfo(
           this,
           nAdapter,
           nDXLevel,
           nVendorID: info.m_VendorID,
           nDeviceID: info.m_DeviceID,
           pConfiguration: pCongifuration);
}

//------------------------------------------------------------------------------
// Address: 0x1003C220
// Name: public: virtual enum AppSystemTier_t CBaseAppSystem<class IShaderDeviceMgr>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IShaderDeviceMgr>::GetTier(CBaseAppSystem<IShaderDeviceMgr> *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x100418C0
// Name: public: virtual enum InitReturnVal_t CBaseAppSystem<class IShaderDeviceMgr>::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IShaderDeviceMgr>::Init(CBaseAppSystem<IShaderDeviceMgr> *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10056969
// Name: public: virtual long D3DXMath::CMatrixStack::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall D3DXMath::CMatrixStack::QueryInterface(D3DXMath::CMatrixStack *this, const struct _GUID *a2, void **a3)
{
  if ( a3 == nullptr )
    return -2005530516;
  if ( memcmp(a2, &IID_ID3DXMatrixStack, 0x10u) != 0 && memcmp(a2, &IID_IUnknown, 0x10u) != 0 )
    return -2147467262;
  *a3 = this;
  (*(void (__stdcall **)(D3DXMath::CMatrixStack *))(*(_DWORD *)this + 4))(a1: this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10071A4E
// Name: public: virtual long D3DXShader::CConstantTable::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::QueryInterface(
        D3DXShader::CConstantTable *this,
        const struct _GUID *a2,
        void **a3)
{
  *a3 = nullptr;
  if ( memcmp(a2, &IID_IUnknown, 0x10u) != 0 && memcmp(a2, &IID_ID3DXConstantTable, 0x10u) != 0 )
    return -2147467262;
  *a3 = this;
  (*(void (__stdcall **)(D3DXShader::CConstantTable *))(*(_DWORD *)this + 4))(a1: this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100754B5
// Name: public: virtual long D3DXCore::CBuffer::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall D3DXCore::CBuffer::QueryInterface(D3DXCore::CBuffer *this, const struct _GUID *a2, void **a3)
{
  *a3 = nullptr;
  if ( memcmp(a2, &IID_IUnknown, 0x10u) != 0 && memcmp(a2, &IID_ID3DXBuffer, 0x10u) != 0 )
    return -2147467262;
  *a3 = this;
  (*(void (__stdcall **)(D3DXCore::CBuffer *))(*(_DWORD *)this + 4))(a1: this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10025400
// Name: __CreateCShaderDeviceMgrDx8IShaderDeviceMgr_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CShaderDeviceMgrDx8 *__cdecl _CreateCShaderDeviceMgrDx8IShaderDeviceMgr_interface()
{
  return &g_ShaderDeviceMgrDx8;
}

//------------------------------------------------------------------------------
// Address: 0x100418D0
// Name: void PadLine<unsigned char>(unsigned long,unsigned char,unsigned char __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl PadLine<unsigned char>(unsigned int a1, unsigned __int8 a2, unsigned __int8 *src)
{
  while ( a2 - a1 > a1 )
    a2 >>= 1;
  memcpy(dst: &src[a1], src, count: a2 - a1);
}

//------------------------------------------------------------------------------
// Address: 0x10041910
// Name: void PadBlock<unsigned char>(unsigned long,unsigned char,unsigned char,unsigned char __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl PadBlock<unsigned char>(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, unsigned __int8 *src)
{
  unsigned int v4; // ecx

  while ( 1 )
  {
    v4 = a3 - a1;
    if ( v4 <= a1 )
      break;
    a3 >>= 1;
  }
  memcpy(dst: &src[a1 * a2], src, count: v4 * a2);
}

//------------------------------------------------------------------------------
// Address: 0x100569DB
// Name: public: virtual long D3DXMath::CMatrixStack::Push(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXMath::CMatrixStack::Push(D3DXMath::CMatrixStack *this)
{
  int v2; // eax
  int v3; // esi
  D3DXMath::CMatrixStack *v4; // eax
  unsigned __int8 v5; // cl
  const void *v7; // esi
  int v8; // eax
  char *v9; // edi
  D3DXMath::CMatrixStack *thisa; // [esp+24h] [ebp+8h]

  ++*((_DWORD *)this + 3);
  v2 = *((_DWORD *)this + 1);
  if ( *((_DWORD *)this + 3) >= v2 )
  {
    v3 = 2 * v2;
    v4 = (D3DXMath::CMatrixStack *)operator new(nSize: (v2 << 7) + 16);
    thisa = v4;
    if ( v4 != nullptr )
    {
      v5 = 16 - ((unsigned __int8)v4 & 0xF);
      v4 = (D3DXMath::CMatrixStack *)((char *)v4 + v5);
      thisa = v4;
      *((_BYTE *)v4 - 1) = v5;
    }
    if ( v4 != nullptr )
      `vector constructor iterator'(__t: v4, __s: 0x40u, __n: v3, __f: D3DXShader::CArgument::CArgument);
    else
      thisa = nullptr;
    if ( thisa == nullptr )
      return -2147024882;
    v7 = *((const void **)this + 2);
    if ( v7 != nullptr )
    {
      qmemcpy(thisa, v7, *((_DWORD *)this + 1) << 6);
      v8 = *((_DWORD *)this + 2);
      if ( v8 != 0 )
        free(pMem: (void *)(v8 - *(unsigned __int8 *)(v8 - 1)));
    }
    *((_DWORD *)this + 1) *= 2;
    *((_DWORD *)this + 2) = thisa;
  }
  v9 = (char *)((*((_DWORD *)this + 3) << 6) + *((_DWORD *)this + 2));
  qmemcpy(v9, v9 - 64, 0x40u);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10071A97
// Name: public: virtual unsigned long D3DXCore::CBuffer::GetBufferSize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall D3DXCore::CBuffer::GetBufferSize(D3DXCore::CBuffer *this)
{
  return *((_DWORD *)this + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10071AA6
// Name: public: virtual void __near * D3DXCore::CBuffer::GetBufferPointer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__stdcall D3DXCore::CBuffer::GetBufferPointer(D3DXCore::CBuffer *this)
{
  return *((void **)this + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10071AB5
// Name: public: virtual long D3DXShader::CConstantTable::GetDesc(struct _D3DXCONSTANTTABLE_DESC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::GetDesc(D3DXShader::CConstantTable *this, struct _D3DXCONSTANTTABLE_DESC *a2)
{
  unsigned int v3; // eax
  _DWORD *v4; // ecx
  int v5; // edi
  const char *v6; // eax

  if ( a2 == nullptr )
    return -2005530516;
  v3 = *((_DWORD *)this + 3);
  if ( v3 < 0x1C )
    return -2005529767;
  v4 = *((_DWORD **)this + 2);
  if ( *v4 < 0x1Cu || v4[1] >= v3 )
    return -2005529767;
  a2->Creator = nullptr;
  a2->Version = 0;
  a2->Constants = 0;
  v5 = v4[1];
  if ( v5 != 0 )
    v6 = (const char *)(v5 + *((_DWORD *)this + 2));
  else
    v6 = nullptr;
  a2->Creator = v6;
  a2->Version = v4[2];
  a2->Constants = v4[3];
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10071B16
// Name: public: virtual long D3DXShader::CConstantTable::SetDefaults(struct IDirect3DDevice9 __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::SetDefaults(D3DXShader::CConstantTable *this, struct IDirect3DDevice9 *a2)
{
  int v2; // edi
  int result; // eax

  v2 = 0;
  if ( *((_DWORD *)this + 6) == 0 )
    return 0;
  while ( 1 )
  {
    result = D3DXShader::CConstant::SetDefaults(
               this: *(D3DXShader::CConstant **)(*((_DWORD *)this + 5) + 4 * v2),
               a2,
               a3: 0);
    if ( result < 0 )
      break;
    if ( (unsigned int)++v2 >= *((_DWORD *)this + 6) )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100754FE
// Name: public: D3DXCore::CBuffer::CBuffer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXCore::CBuffer *__thiscall D3DXCore::CBuffer::CBuffer(D3DXCore::CBuffer *this)
{
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 2) = 0;
  *(_DWORD *)this = &D3DXCore::CBuffer::`vftable';
  *((_DWORD *)this + 1) = 1;
  return this;
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x10004D10
// Name: public: virtual bool CShaderDeviceBase::IsAAEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDeviceBase::IsAAEnabled(ConVar *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1000E1E0
// Name: public: virtual bool CShaderDeviceBase::AddView(void __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceBase::AddView(CShaderAPIDx10 *this, int textureHandle)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027A20
// Name: void __near * ShaderDeviceFactory(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl ShaderDeviceFactory(const char *pName, int *pReturnCode)
{
  void *result; // eax
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  if ( pReturnCode != nullptr )
    *pReturnCode = 0;
  result = s_TempFactory(a1: pName, a2: pReturnCode);
  if ( result == nullptr )
  {
    FactoryThis = Sys_GetFactoryThis();
    result = FactoryThis(a1: pName, a2: pReturnCode);
    if ( result == nullptr )
    {
      if ( pReturnCode != nullptr )
        *pReturnCode = 1;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027A70
// Name: public: virtual void CShaderDeviceMgrBase::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::Disconnect(CShaderDeviceMgrBase *this)
{
  KeyValues *m_pDXSupport; // ecx

  g_pShaderDeviceMgr = nullptr;
  g_pShaderUtil = nullptr;
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
  m_pDXSupport = this->m_pDXSupport;
  if ( m_pDXSupport != nullptr )
  {
    KeyValues::deleteThis(this: m_pDXSupport);
    this->m_pDXSupport = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027AB0
// Name: public: virtual void __near * CShaderDeviceMgrBase::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceMgrBase *__thiscall CShaderDeviceMgrBase::QueryInterface(
        CShaderDeviceMgrBase *this,
        const char *pInterfaceName)
{
  if ( _V_stricmp(s1: pInterfaceName, s2: "ShaderDeviceMgr001") != 0 )
    return _V_stricmp(s1: pInterfaceName, s2: "MaterialSystemHardwareConfig013") == 0
         ? (CShaderDeviceMgrBase *)g_pHardwareConfig
         : nullptr;
  else
    return this;
}

//------------------------------------------------------------------------------
// Address: 0x10027AF0
// Name: private: class KeyValues __near * CShaderDeviceMgrBase::FindDXLevelSpecificConfig(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CShaderDeviceMgrBase::FindDXLevelSpecificConfig(
        CShaderDeviceMgrBase *this,
        KeyValues *pKeyValues,
        int nDxLevel)
{
  KeyValues *FirstSubKey; // esi

  KeyValues::GetFirstSubKey(this: pKeyValues);
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
  if ( FirstSubKey == nullptr )
    return nullptr;
  while ( KeyValues::GetInt(this: FirstSubKey, keyName: "name", defaultValue: 0) != nDxLevel )
  {
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return nullptr;
  }
  return FirstSubKey;
}

//------------------------------------------------------------------------------
// Address: 0x10027B40
// Name: private: class KeyValues __near * CShaderDeviceMgrBase::FindDXLevelAndVendorSpecificConfig(class KeyValues __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CShaderDeviceMgrBase::FindDXLevelAndVendorSpecificConfig(
        CShaderDeviceMgrBase *this,
        KeyValues *pKeyValues,
        int nDxLevel,
        int nVendorID)
{
  KeyValues *v4; // esi
  KeyValues *FirstSubKey; // edi
  int v6; // ebp
  int Int; // ebx
  const char *String; // esi
  int v9; // eax

  v4 = pKeyValues;
  KeyValues::GetFirstSubKey(this: pKeyValues);
  FirstSubKey = KeyValues::GetFirstSubKey(this: v4);
  if ( FirstSubKey == nullptr )
    return nullptr;
  v6 = nVendorID;
  while ( 1 )
  {
    Int = KeyValues::GetInt(this: FirstSubKey, keyName: "name", defaultValue: 0);
    String = KeyValues::GetString(this: FirstSubKey, keyName: "VendorID", defaultValue: nullptr);
    if ( String == nullptr
      || (v9 = strtol(nptr: String, endptr: (char **)&pKeyValues, ibase: 16), pKeyValues == (KeyValues *)String) )
    {
      v9 = -1;
    }
    if ( Int == nDxLevel && v9 == v6 )
      break;
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return nullptr;
  }
  return FirstSubKey;
}

//------------------------------------------------------------------------------
// Address: 0x10027BD0
// Name: private: class KeyValues __near * CShaderDeviceMgrBase::FindCardSpecificConfig(class KeyValues __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CShaderDeviceMgrBase::FindCardSpecificConfig(
        CShaderDeviceMgrBase *this,
        KeyValues *pKeyValues,
        int nVendorId,
        int nDeviceId)
{
  KeyValues *v4; // esi
  KeyValues *FirstSubKey; // edi
  const char *String; // esi
  int v7; // eax
  int v8; // ebp
  const char *v9; // eax
  char *v10; // esi
  int v11; // eax
  int v12; // ebx
  const char *v13; // eax
  char *v14; // esi
  int v15; // eax
  char *endptr; // [esp+10h] [ebp-8h] BYREF
  char *v18; // [esp+14h] [ebp-4h] BYREF

  v4 = pKeyValues;
  KeyValues::GetFirstSubKey(this: pKeyValues);
  FirstSubKey = KeyValues::GetFirstSubKey(this: v4);
  if ( FirstSubKey == nullptr )
    return nullptr;
  while ( 1 )
  {
    String = KeyValues::GetString(this: FirstSubKey, keyName: "VendorID", defaultValue: nullptr);
    if ( String == nullptr
      || (v7 = strtol(nptr: String, endptr: (char **)&pKeyValues, ibase: 16), pKeyValues == (KeyValues *)String) )
    {
      v8 = -1;
    }
    else
    {
      v8 = v7;
    }
    v9 = KeyValues::GetString(this: FirstSubKey, keyName: "MinDeviceID", defaultValue: nullptr);
    v10 = (char *)v9;
    if ( v9 == nullptr || (v11 = strtol(nptr: v9, &endptr, ibase: 16), endptr == v10) )
      v12 = -1;
    else
      v12 = v11;
    v13 = KeyValues::GetString(this: FirstSubKey, keyName: "MaxDeviceID", defaultValue: nullptr);
    v14 = (char *)v13;
    if ( v13 == nullptr || (v15 = strtol(nptr: v13, endptr: &v18, ibase: 16), v18 == v14) )
      v15 = -1;
    if ( v8 == nVendorId && nDeviceId >= v12 && nDeviceId <= v15 )
      break;
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return nullptr;
  }
  return FirstSubKey;
}

//------------------------------------------------------------------------------
// Address: 0x10027CC0
// Name: private: class KeyValues __near * CShaderDeviceMgrBase::ReadDXSupportKeyValues(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CShaderDeviceMgrBase::ReadDXSupportKeyValues(CShaderDeviceMgrBase *this)
{
  int v2; // eax
  KeyValues *result; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax

  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-ignoredxsupportcfg", a3: 0) != 0 )
    return nullptr;
  result = this->m_pDXSupport;
  if ( result == nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "dxsupport");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: v6,
           resourceName: "dxsupport.cfg",
           pathID: "EXECUTABLE_PATH",
           pfnEvaluateSymbolProc: nullptr) )
    {
      this->m_pDXSupport = v5;
      return v5;
    }
    else
    {
      KeyValues::deleteThis(this: v5);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027D50
// Name: public: void CShaderDeviceMgrBase::ReadDXSupportLevels(struct HardwareCaps_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::ReadDXSupportLevels(CShaderDeviceMgrBase *this, HardwareCaps_t *caps)
{
  KeyValues *DXSupportKeyValues; // eax
  KeyValues *CardSpecificConfig; // eax
  KeyValues *v5; // edi
  int Int; // eax
  int v7; // eax
  int v8; // eax
  bool v9; // zf

  DXSupportKeyValues = CShaderDeviceMgrBase::ReadDXSupportKeyValues(this);
  if ( DXSupportKeyValues != nullptr )
  {
    CardSpecificConfig = CShaderDeviceMgrBase::FindCardSpecificConfig(
                           this,
                           pKeyValues: DXSupportKeyValues,
                           nVendorId: caps->m_VendorID,
                           nDeviceId: caps->m_DeviceID);
    v5 = CardSpecificConfig;
    if ( CardSpecificConfig != nullptr )
    {
      Int = KeyValues::GetInt(this: CardSpecificConfig, keyName: "setting.MaxDXLevel", defaultValue: 0);
      if ( Int != 0 )
        caps->m_nMaxDXSupportLevel = Int;
      v7 = KeyValues::GetInt(this: v5, keyName: "setting.MinDXLevel", defaultValue: 0);
      if ( v7 != 0 && v7 <= caps->m_nMaxDXSupportLevel )
        caps->m_nMinDXSupportLevel = v7;
      v8 = KeyValues::GetInt(this: v5, keyName: "setting.DXLevel", defaultValue: 0);
      if ( v8 != 0 )
      {
        v9 = (*((_BYTE *)caps + 719) & 1) == 0;
        caps->m_nDXSupportLevel = v8;
        if ( !v9 )
          caps->m_nDXSupportLevel = 92;
      }
      else
      {
        caps->m_nDXSupportLevel = caps->m_nMaxDXSupportLevel;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027E00
// Name: public: int CShaderDeviceMgrBase::GetClosestActualDXLevel(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceMgrBase::GetClosestActualDXLevel(CShaderDeviceMgrBase *this, int nDxLevel)
{
  if ( nDxLevel < 92 )
    return 90;
  if ( nDxLevel >= 95 )
    return nDxLevel >= 100 ? 100 : 95;
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x10027E40
// Name: public: static void __near * CShaderDeviceMgrBase::ShaderInterfaceFactory(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
CShaderAPIBase *__cdecl CShaderDeviceMgrBase::ShaderInterfaceFactory(const char *pInterfaceName, int *pReturnCode)
{
  if ( pReturnCode != nullptr )
    *pReturnCode = 0;
  if ( _V_stricmp(s1: pInterfaceName, s2: "ShaderDevice001") == 0 )
    return (CShaderAPIBase *)g_pShaderDevice;
  if ( _V_stricmp(s1: pInterfaceName, s2: "ShaderApi030") == 0 )
    return g_pShaderAPI;
  if ( _V_stricmp(s1: pInterfaceName, s2: "ShaderShadow010") == 0 )
    return (CShaderAPIBase *)g_pShaderShadow;
  if ( pReturnCode != nullptr )
    *pReturnCode = 1;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10027EC0
// Name: public: virtual CShaderDeviceBase::~CShaderDeviceBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::~CShaderDeviceBase(CShaderDeviceBase *this)
{
  this->__vftable = (CShaderDeviceBase_vtbl *)&CShaderDeviceBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10027ED0
// Name: protected: void CShaderDeviceBase::SetCurrentThreadAsOwner(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::SetCurrentThreadAsOwner(CShaderDeviceBase *this)
{
  this->m_dwThreadId = GetCurrentThreadId();
}

//------------------------------------------------------------------------------
// Address: 0x10027EE0
// Name: protected: void CShaderDeviceBase::RemoveThreadOwner(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::RemoveThreadOwner(CShaderDeviceBase *this)
{
  this->m_dwThreadId = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10027EF0
// Name: protected: bool CShaderDeviceBase::ThreadOwnsDevice(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDeviceBase::ThreadOwnsDevice(CShaderDeviceBase *this)
{
  return GetCurrentThreadId() == this->m_dwThreadId;
}

//------------------------------------------------------------------------------
// Address: 0x10027F20
// Name: EnumChildWindowsProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EnumChildWindowsProc(HWND__ *hWnd, unsigned int lParam)
{
  tagCOPYDATASTRUCT copyData; // [esp+0h] [ebp-10h] BYREF
  int v4; // [esp+Ch] [ebp-4h]

  if ( GetWindowLongA(hWnd, nIndex: -21) == -17965395 )
  {
    copyData.cbData = lParam;
    copyData.lpData = nullptr;
    v4 = 0;
    SendMessageA(hWnd, Msg: 0x4Au, wParam: 0, lParam: (LPARAM)&copyData.cbData);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027F70
// Name: EnumWindowsProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EnumWindowsProc(HWND__ *hWnd, LPARAM lParam)
{
  EnumChildWindows(hWndParent: hWnd, lpEnumFunc: (WNDENUMPROC)EnumChildWindowsProc, lParam);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027F90
// Name: EnumWindowsProcNotThis
// Source: json
//------------------------------------------------------------------------------
int __stdcall EnumWindowsProcNotThis(HWND hWnd, LPARAM lParam)
{
  HWND__ *m_hWndCookie; // esi
  HWND i; // eax

  if ( g_pShaderDevice == nullptr )
    goto LABEL_5;
  m_hWndCookie = (HWND__ *)g_pShaderDevice->m_hWndCookie;
  for ( i = GetParent(hWnd: m_hWndCookie); i != nullptr; i = GetParent(hWnd: i) )
    m_hWndCookie = i;
  if ( m_hWndCookie != hWnd )
LABEL_5:
    EnumChildWindows(hWndParent: hWnd, lpEnumFunc: (WNDENUMPROC)EnumChildWindowsProc, lParam);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027FE0
// Name: ShaderDX8WndProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall ShaderDX8WndProc(HWND__ *hWnd, UINT msg, WPARAM wParam, int *lParam)
{
  int v4; // eax

  if ( msg == 74 && g_pShaderDevice != nullptr )
  {
    v4 = *lParam;
    if ( *lParam == 1584664032 )
    {
      ((void (__stdcall *)(int))g_pShaderDevice->OtherAppInitializing)(a1: 1);
    }
    else if ( v4 == 1584664033 )
    {
      ((void (__stdcall *)(_DWORD))g_pShaderDevice->OtherAppInitializing)(a1: 0);
    }
    else if ( v4 == 1584664034 )
    {
      ((void (*)(void))g_pShaderDevice->EvictManagedResourcesInternal)();
    }
  }
  return DefWindowProcA(hWnd, Msg: msg, wParam, (LPARAM)lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10028050
// Name: protected: void CShaderDeviceBase::InstallWindowHook(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::InstallWindowHook(CShaderDeviceBase *this, HWND hWnd)
{
  HWND v2; // esi
  HWND i; // eax
  HICON__ *WindowLongA; // edi
  HWND Window; // eax
  tagWNDCLASSA wc; // [esp+8h] [ebp-2Ch] BYREF
  const char *v8; // [esp+30h] [ebp-4h]

  v2 = hWnd;
  for ( i = GetParent(hWnd); i != nullptr; i = GetParent(hWnd: i) )
    v2 = i;
  WindowLongA = (HICON__ *)GetWindowLongA(hWnd: v2, nIndex: -6);
  memset(&wc.hCursor, 0, 16);
  *(_QWORD *)&wc.cbWndExtra = 0;
  wc.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))640;
  wc.cbClsExtra = (int)ShaderDX8WndProc;
  wc.hIcon = WindowLongA;
  v8 = "shaderdx8";
  UnregisterClassA(lpClassName: "shaderdx8", hInstance: (HINSTANCE)WindowLongA);
  RegisterClassA(lpWndClass: (const WNDCLASSA *)&wc.lpfnWndProc);
  Window = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: "shaderdx8",
             lpWindowName: "shaderdx8",
             dwStyle: 0x40000000u,
             X: 0,
             Y: 0,
             nWidth: 0,
             nHeight: 0,
             hWndParent: v2,
             hMenu: nullptr,
             hInstance: (HINSTANCE)WindowLongA,
             lpParam: nullptr);
  this->m_hWndCookie = Window;
  SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: -17965395);
}

//------------------------------------------------------------------------------
// Address: 0x10028120
// Name: protected: void CShaderDeviceBase::RemoveWindowHook(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::RemoveWindowHook(CShaderDeviceBase *this, HWND hWnd)
{
  HWND v3; // esi
  HWND i; // eax
  HINSTANCE WindowLongA; // eax

  if ( this->m_hWndCookie != nullptr )
  {
    DestroyWindow(hWnd: (HWND)this->m_hWndCookie);
    this->m_hWndCookie = nullptr;
  }
  v3 = hWnd;
  for ( i = GetParent(hWnd); i != nullptr; i = GetParent(hWnd: i) )
    v3 = i;
  WindowLongA = (HINSTANCE)GetWindowLongA(hWnd: v3, nIndex: -6);
  UnregisterClassA(lpClassName: "shaderdx8", hInstance: WindowLongA);
}

//------------------------------------------------------------------------------
// Address: 0x10028180
// Name: public: void CShaderDeviceBase::SendIPCMessage(enum CShaderDeviceBase::IPCMessage_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::SendIPCMessage(CShaderDeviceBase *this, LPARAM msg)
{
  if ( msg == 1584664034 )
    EnumWindows(lpEnumFunc: EnumWindowsProcNotThis, lParam: 1584664034);
  else
    EnumWindows(lpEnumFunc: EnumWindowsProc, lParam: msg);
}

//------------------------------------------------------------------------------
// Address: 0x100281B0
// Name: public: virtual void CShaderDeviceBase::SetView(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::SetView(CShaderDeviceBase *this, void *hWnd)
{
  void (__thiscall *GetWindowSize)(struct CShaderDeviceBase *, int *, int *); // edx
  ShaderViewport_t viewport; // [esp+Ch] [ebp-20h] BYREF

  viewport.m_nTopLeftX = 1;
  g_pShaderAPI->GetViewports(this: g_pShaderAPI, a2: (ShaderViewport_t *)&viewport.m_nTopLeftX, a3: 1);
  GetWindowSize = this->GetWindowSize;
  this->m_ViewHWnd = hWnd;
  GetWindowSize(this, a2: &this->m_nWindowWidth, a3: &this->m_nWindowHeight);
  g_pShaderAPI->SetViewports(this: g_pShaderAPI, a2: 1, a3: (const ShaderViewport_t *)&viewport.m_nTopLeftX);
}

//------------------------------------------------------------------------------
// Address: 0x10028210
// Name: public: virtual void CShaderDeviceBase::GetWindowSize(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceBase::GetWindowSize(CShaderDeviceBase *this, int *nWidth, int *nHeight)
{
  int v4; // edx
  tagRECT rect; // [esp+0h] [ebp-14h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  if ( (*((_BYTE *)this + 16) & 2) != 0 || IsIconic(hWnd: (HWND)this->m_hWnd) )
  {
    *nHeight = 0;
    *nWidth = 0;
  }
  else
  {
    GetClientRect(hWnd: (HWND)this->m_ViewHWnd, lpRect: (LPRECT)&rect.top);
    v4 = v6 - rect.right;
    *nWidth = rect.bottom - rect.top;
    *nHeight = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028320
// Name: public: virtual bool CShaderAPIConVarAccessor::RegisterConCommandBase(class ConCommandBase __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderAPIConVarAccessor::RegisterConCommandBase(
        CShaderAPIConVarAccessor *this,
        ConCommandBase *pCommand)
{
  ICvar_vtbl *v2; // edi
  const char *v3; // eax
  int v4; // edi

  g_pCVar->RegisterConCommand(this: g_pCVar, a2: pCommand);
  v2 = g_pCVar->__vftable;
  v3 = pCommand->GetName(this: pCommand);
  v4 = (int)v2->GetCommandLineValue(this: g_pCVar, a2: v3);
  if ( v4 != 0 && !pCommand->IsCommand(this: pCommand) )
    pCommand[1].AddFlags(this: &pCommand[1], a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028380
// Name: private: void CShaderDeviceMgrBase::LoadHardwareCaps(class KeyValues __near *,struct HardwareCaps_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::LoadHardwareCaps(
        CShaderDeviceMgrBase *this,
        KeyValues *pGroup,
        HardwareCaps_t *caps)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  HardwareCaps_t *v6; // esi
  bool v7; // bl
  int Int; // eax
  bool v9; // bl
  int v10; // eax
  bool v11; // al
  bool v12; // bl
  int v13; // eax
  bool v14; // al
  char v15; // bl
  bool v16; // bl
  int v17; // eax
  bool v18; // al
  bool v19; // bl
  int v20; // eax
  bool v21; // al
  bool v22; // bl
  int v23; // eax
  bool v24; // al
  bool v25; // bl
  int v26; // eax
  bool v27; // al
  bool v28; // bl
  int v29; // eax
  char v30; // al

  if ( pGroup != nullptr )
  {
    v3 = _CommandLine(a1: this);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-arbmode") != 0
      || (v5 = _CommandLine(a1: v4),
          (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-nouserclip", a3: 0) != 0)
      || r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    {
      v6 = caps;
      *((_BYTE *)caps + 717) |= 8u;
    }
    else
    {
      v6 = caps;
      v7 = (*((_BYTE *)caps + 717) & 8) != 0;
      Int = KeyValues::GetInt(this: pGroup, keyName: "setting.NoUserClipPlanes", defaultValue: -1);
      if ( Int != -1 )
        v7 = Int != 0;
      *((_BYTE *)caps + 717) ^= (*((_BYTE *)caps + 717) ^ (8 * v7)) & 8;
    }
    v9 = (*((_BYTE *)v6 + 717) & 0x10) != 0;
    v10 = KeyValues::GetInt(this: pGroup, keyName: "setting.CentroidHack", defaultValue: -1);
    if ( v10 == -1 )
      v11 = v9;
    else
      v11 = v10 != 0;
    *((_BYTE *)v6 + 717) ^= (*((_BYTE *)v6 + 717) ^ (16 * v11)) & 0x10;
    v12 = (*((_BYTE *)v6 + 717) & 0x20) != 0;
    v13 = KeyValues::GetInt(this: pGroup, keyName: "setting.DisableShaderOptimizations", defaultValue: -1);
    if ( v13 == -1 )
      v14 = v12;
    else
      v14 = v13 != 0;
    v15 = *((_BYTE *)v6 + 719);
    *((_BYTE *)v6 + 717) ^= (*((_BYTE *)v6 + 717) ^ (32 * v14)) & 0x20;
    v16 = (v15 & 4) != 0;
    v17 = KeyValues::GetInt(this: pGroup, keyName: "setting.PreferZPrepass", defaultValue: -1);
    if ( v17 == -1 )
      v18 = v16;
    else
      v18 = v17 != 0;
    *((_BYTE *)v6 + 719) ^= (*((_BYTE *)v6 + 719) ^ (4 * v18)) & 4;
    v19 = (*((_BYTE *)v6 + 719) & 8) != 0;
    v20 = KeyValues::GetInt(this: pGroup, keyName: "setting.SuppressPixelShaderCentroidHackFixup", defaultValue: -1);
    if ( v20 == -1 )
      v21 = v19;
    else
      v21 = v20 != 0;
    *((_BYTE *)v6 + 719) ^= (*((_BYTE *)v6 + 719) ^ (8 * v21)) & 8;
    v22 = (*((_BYTE *)v6 + 719) & 0x10) != 0;
    v23 = KeyValues::GetInt(this: pGroup, keyName: "setting.PreferTexturesInHWMemory", defaultValue: -1);
    if ( v23 == -1 )
      v24 = v22;
    else
      v24 = v23 != 0;
    *((_BYTE *)v6 + 719) ^= (*((_BYTE *)v6 + 719) ^ (16 * v24)) & 0x10;
    v25 = (*((_BYTE *)v6 + 719) & 0x20) != 0;
    v26 = KeyValues::GetInt(this: pGroup, keyName: "setting.PreferHardwareSync", defaultValue: -1);
    if ( v26 == -1 )
      v27 = v25;
    else
      v27 = v26 != 0;
    *((_BYTE *)v6 + 719) ^= (*((_BYTE *)v6 + 719) ^ (32 * v27)) & 0x20;
    v28 = (*((_BYTE *)v6 + 719) & 0x40) != 0;
    v29 = KeyValues::GetInt(this: pGroup, keyName: "setting.Unsupported", defaultValue: -1);
    if ( v29 == -1 )
      v30 = v28;
    else
      v30 = v29 != 0;
    *((_BYTE *)v6 + 719) ^= (*((_BYTE *)v6 + 719) ^ (v30 << 6)) & 0x40;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100285C0
// Name: public: void CShaderDeviceMgrBase::ReadHardwareCaps(struct HardwareCaps_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::ReadHardwareCaps(
        CShaderDeviceMgrBase *this,
        HardwareCaps_t *caps,
        KeyValues *nDxLevel)
{
  KeyValues *DXSupportKeyValues; // eax
  KeyValues *v5; // ebx
  KeyValues *v6; // ebp
  KeyValues *DXLevelSpecificConfig; // eax
  HardwareCaps_t *v8; // edi
  KeyValues *CardSpecificConfig; // eax
  KeyValues *v10; // ebx
  HardwareCaps_t *String; // ebp
  int v12; // eax
  const char *v13; // eax
  HardwareCaps_t *v14; // ebp
  int v15; // eax
  KeyValues *pGroup; // [esp+8h] [ebp-4h]

  DXSupportKeyValues = CShaderDeviceMgrBase::ReadDXSupportKeyValues(this);
  v5 = DXSupportKeyValues;
  if ( DXSupportKeyValues != nullptr )
  {
    v6 = nDxLevel;
    DXLevelSpecificConfig = CShaderDeviceMgrBase::FindDXLevelSpecificConfig(
                              this,
                              pKeyValues: DXSupportKeyValues,
                              (int)nDxLevel);
    v8 = caps;
    nDxLevel = DXLevelSpecificConfig;
    pGroup = CShaderDeviceMgrBase::FindDXLevelAndVendorSpecificConfig(
               this,
               pKeyValues: v5,
               nDxLevel: (int)v6,
               nVendorID: caps->m_VendorID);
    CardSpecificConfig = CShaderDeviceMgrBase::FindCardSpecificConfig(
                           this,
                           pKeyValues: v5,
                           nVendorId: v8->m_VendorID,
                           nDeviceId: v8->m_DeviceID);
    v10 = CardSpecificConfig;
    if ( CardSpecificConfig != nullptr
      && (String = (HardwareCaps_t *)KeyValues::GetString(
                                       this: CardSpecificConfig,
                                       keyName: "MinDeviceID",
                                       defaultValue: nullptr)) != nullptr
      && (v12 = strtol(nptr: String->m_pDriverName, endptr: (char **)&caps, ibase: 16), caps != String)
      && v12 == 0
      && (v13 = KeyValues::GetString(this: v10, keyName: "MaxDeviceID", defaultValue: nullptr),
          v14 = (HardwareCaps_t *)v13,
          v13 != nullptr)
      && (v15 = strtol(nptr: v13, endptr: (char **)&caps, ibase: 16), caps != v14)
      && v15 == 0xFFFF )
    {
      CShaderDeviceMgrBase::LoadHardwareCaps(this, pGroup: nDxLevel, caps: v8);
      CShaderDeviceMgrBase::LoadHardwareCaps(this, pGroup: v10, caps: v8);
      CShaderDeviceMgrBase::LoadHardwareCaps(this, pGroup, caps: v8);
    }
    else
    {
      CShaderDeviceMgrBase::LoadHardwareCaps(this, pGroup: nDxLevel, caps: v8);
      CShaderDeviceMgrBase::LoadHardwareCaps(this, pGroup: v10, caps: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100286D0
// Name: public: CShaderDeviceBase::CShaderDeviceBase(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceBase *__thiscall CShaderDeviceBase::CShaderDeviceBase(CShaderDeviceBase *this)
{
  *((_BYTE *)this + 16) &= ~1u;
  this->__vftable = (CShaderDeviceBase_vtbl *)&CShaderDeviceBase::`vftable';
  this->m_nAdapter = -1;
  this->m_hWnd = nullptr;
  this->m_hWndCookie = nullptr;
  this->m_dwThreadId = GetCurrentThreadId();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100287B0
// Name: public: virtual void CBaseAppSystem<class IShaderDeviceMgr>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IShaderDeviceMgr>::Reconnect(
        CBaseAppSystem<IShaderDeviceMgr> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x100287D0
// Name: public: virtual bool CShaderDeviceMgrBase::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrBase::Connect(
        CShaderDeviceMgrBase *this,
        void *(__cdecl *factory)(const char *, int *))
{
  IShaderUtil *v3; // eax
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  s_TempFactory = factory;
  factory = ShaderDeviceFactory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    pAccessor.__vftable = (IConCommandBaseAccessor_vtbl *)&CShaderAPIConVarAccessor::`vftable';
  }
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0x800000, pAccessor: &pAccessor);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  v3 = (IShaderUtil *)s_TempFactory(a1: "VShaderUtil001", a2: nullptr);
  if ( v3 == nullptr )
  {
    FactoryThis = Sys_GetFactoryThis();
    v3 = (IShaderUtil *)FactoryThis(a1: "VShaderUtil001", a2: nullptr);
  }
  g_pShaderUtil = v3;
  g_pShaderDeviceMgr = this;
  s_TempFactory = nullptr;
  if ( v3 != nullptr && g_pFullFileSystem != nullptr && this != nullptr )
  {
    MathLib_Init(
      gamma: 2.2,
      texGamma: 2.2,
      brightness: 0.0,
      overbright: 2,
      bAllow3DNow: true,
      bAllowSSE: true,
      bAllowSSE2: true,
      bAllowMMX: true);
    return 1;
  }
  else
  {
    _Warning(a1: "ShaderAPIDx10 was unable to access the required interfaces!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100288C0
// Name: public: struct HardwareCaps_t const __near & CShaderDeviceMgrBase::GetHardwareCaps(int)const
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceMgrBase::AdapterInfo_t *__thiscall CShaderDeviceMgrBase::GetHardwareCaps(
        CShaderDeviceMgrBase *this,
        int nAdapter)
{
  return &this->m_Adapters.m_Memory.m_pMemory[nAdapter];
}

//------------------------------------------------------------------------------
// Address: 0x100288D0
// Name: public: void CShaderDeviceMgrBase::InvokeModeChangeCallbacks(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::InvokeModeChangeCallbacks(
        CShaderDeviceMgrBase *this,
        int screenWidth,
        int screenHeight)
{
  int m_Size; // ebx
  int i; // esi
  int v6; // ebx
  int j; // esi
  IShaderDeviceDependentObject *v8; // ecx

  m_Size = this->m_ModeChangeCallbacks.m_Size;
  for ( i = 0; i < m_Size; ++i )
    this->m_ModeChangeCallbacks.m_Memory.m_pMemory[i]();
  v6 = this->m_DeviceDependentObjects.m_Size;
  for ( j = 0; j < v6; ++j )
  {
    v8 = this->m_DeviceDependentObjects.m_Memory.m_pMemory[j];
    v8->ScreenSizeChanged(this: v8, a2: screenWidth, a3: screenHeight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028930
// Name: public: virtual void CShaderDeviceMgrBase::InvokeDeviceLostNotifications(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::InvokeDeviceLostNotifications(CShaderDeviceMgrBase *this)
{
  int m_Size; // ebx
  int i; // esi
  IShaderDeviceDependentObject *v4; // ecx

  m_Size = this->m_DeviceDependentObjects.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v4 = this->m_DeviceDependentObjects.m_Memory.m_pMemory[i];
    v4->DeviceLost(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028960
// Name: public: virtual void CShaderDeviceMgrBase::InvokeDeviceResetNotifications(struct IDirect3DDevice9 __near *,struct _D3DPRESENT_PARAMETERS_ __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::InvokeDeviceResetNotifications(
        CShaderDeviceMgrBase *this,
        IDirect3DDevice9 *pDevice,
        _D3DPRESENT_PARAMETERS_ *pPresentParameters,
        void *pHWnd)
{
  int m_Size; // ebx
  int i; // esi
  IShaderDeviceDependentObject *v7; // ecx

  m_Size = this->m_DeviceDependentObjects.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v7 = this->m_DeviceDependentObjects.m_Memory.m_pMemory[i];
    v7->DeviceReset(this: v7, a2: pDevice, a3: pPresentParameters, a4: pHWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028B20
// Name: public: virtual void CShaderDeviceMgrBase::RemoveModeChangeCallback(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::RemoveModeChangeCallback(CShaderDeviceMgrBase *this, void (__cdecl *func)())
{
  CUtlVector<void (__cdecl *)(void),CUtlMemory<void (__cdecl *)(void),int>>::FindAndRemove(
    this: (CUtlVector<IShaderDeviceDependentObject *,CUtlMemory<IShaderDeviceDependentObject *,int> > *)&this->m_ModeChangeCallbacks,
    src: (IShaderDeviceDependentObject *const *)&func);
}

//------------------------------------------------------------------------------
// Address: 0x10028B30
// Name: public: virtual void CShaderDeviceMgrBase::RemoveDeviceDependentObject(class IShaderDeviceDependentObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::RemoveDeviceDependentObject(
        CShaderDeviceMgrBase *this,
        IShaderDeviceDependentObject *pObject)
{
  if ( pObject != nullptr )
    CUtlVector<void (__cdecl *)(void),CUtlMemory<void (__cdecl *)(void),int>>::FindAndRemove(
      this: &this->m_DeviceDependentObjects,
      src: &pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10028B50
// Name: public: CShaderDeviceMgrBase::CShaderDeviceMgrBase(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceMgrBase *__thiscall CShaderDeviceMgrBase::CShaderDeviceMgrBase(CShaderDeviceMgrBase *this)
{
  this->__vftable = (CShaderDeviceMgrBase_vtbl *)&CShaderDeviceMgrBase::`vftable';
  this->m_Adapters.m_Memory.m_pMemory = nullptr;
  this->m_Adapters.m_Memory.m_nAllocationCount = 0;
  this->m_Adapters.m_Memory.m_nGrowSize = 0;
  this->m_Adapters.m_Size = 0;
  this->m_Adapters.m_pElements = nullptr;
  this->m_ModeChangeCallbacks.m_Memory.m_pMemory = nullptr;
  this->m_ModeChangeCallbacks.m_Memory.m_nAllocationCount = 0;
  this->m_ModeChangeCallbacks.m_Memory.m_nGrowSize = 0;
  this->m_ModeChangeCallbacks.m_Size = 0;
  this->m_ModeChangeCallbacks.m_pElements = nullptr;
  this->m_DeviceDependentObjects.m_Memory.m_pMemory = nullptr;
  this->m_DeviceDependentObjects.m_Memory.m_nAllocationCount = 0;
  this->m_DeviceDependentObjects.m_Memory.m_nGrowSize = 0;
  this->m_DeviceDependentObjects.m_Size = 0;
  this->m_DeviceDependentObjects.m_pElements = nullptr;
  this->m_pDXSupport = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10028B90
// Name: public: virtual CShaderDeviceMgrBase::~CShaderDeviceMgrBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::~CShaderDeviceMgrBase(CShaderDeviceMgrBase *this)
{
  this->__vftable = (CShaderDeviceMgrBase_vtbl *)&CShaderDeviceMgrBase::`vftable';
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_DeviceDependentObjects);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ModeChangeCallbacks);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Adapters);
}

//------------------------------------------------------------------------------
// Address: 0x10028BC0
// Name: public: virtual void CShaderDeviceMgrBase::AddModeChangeCallback(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::AddModeChangeCallback(CShaderDeviceMgrBase *this, void (__cdecl *func)())
{
  CUtlVector<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>>::InsertBefore(
    this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ModeChangeCallbacks,
    elem: this->m_ModeChangeCallbacks.m_Size,
    src: (CUtlSymbolTable::StringPool_t *const *)&func);
}

//------------------------------------------------------------------------------
// Address: 0x10028BE0
// Name: public: virtual void CShaderDeviceMgrBase::AddDeviceDependentObject(class IShaderDeviceDependentObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrBase::AddDeviceDependentObject(
        CShaderDeviceMgrBase *this,
        IShaderDeviceDependentObject *pObject)
{
  if ( pObject != nullptr )
    CUtlVector<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>>::InsertBefore(
      this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_DeviceDependentObjects,
      elem: this->m_DeviceDependentObjects.m_Size,
      src: (CUtlSymbolTable::StringPool_t *const *)&pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10028C40
// Name: private: bool CShaderDeviceMgrBase::GetRecommendedVideoConfig(int,int,int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrBase::GetRecommendedVideoConfig(
        CShaderDeviceMgrBase *this,
        int nAdapter,
        int nVendorID,
        int nDeviceID,
        KeyValues *pConfiguration)
{
  int v5; // edi
  CShaderDeviceMgrBase_vtbl *v7; // edx
  int v8; // eax
  void (__thiscall *GetDesktopResolution)(CShaderDeviceMgrBase *, int *, int *, int); // edx
  int v10; // ebp
  int v12; // [esp+20h] [ebp-1A0h]
  _MEMORYSTATUS Buffer; // [esp+24h] [ebp-19Ch] BYREF
  VidMatConfigData_t configData; // [esp+44h] [ebp-17Ch] BYREF

  v5 = 0;
  memset(&configData.displayModes, 0, sizeof(configData.displayModes));
  _V_strcpy(dest: configData.szFileName, src: "cfg\\moddefaults.txt");
  _V_strcpy(dest: configData.szPathID, src: "MOD");
  configData.pConfigKeys = pConfiguration;
  configData.nVendorID = nVendorID;
  configData.nDeviceID = nDeviceID;
  GlobalMemoryStatus(lpBuffer: &Buffer);
  v7 = this->__vftable;
  configData.nSystemMemory = Buffer.dwTotalPhys >> 20;
  configData.nVideoMemory = v7->GetVidMemBytes(this, a2: nAdapter) / 0x100000;
  configData.bIsVideo = true;
  v8 = g_pHardwareConfig->GetMaxDXSupportLevel(this: g_pHardwareConfig);
  GetDesktopResolution = this->GetDesktopResolution;
  configData.nDXLevel = v8;
  GetDesktopResolution(this, a2: &configData.nPhysicalScreenWidth, a3: &configData.nPhysicalScreenHeight, a4: nAdapter);
  v10 = this->GetModeCount(this, a2: nAdapter);
  configData.displayModes.m_Size = 0;
  CUtlVector<ShaderDisplayMode_t,CUtlMemory<ShaderDisplayMode_t,int>>::InsertMultipleBefore(
    this: &configData.displayModes,
    elem: 0,
    num: v10);
  if ( v10 > 0 )
  {
    v12 = 0;
    do
      this->GetModeInfo(this, a2: &configData.displayModes.m_Memory.m_pMemory[v12++], a3: nAdapter, a4: v5++);
    while ( v5 < v10 );
  }
  RecommendedConfig(&configData);
  UpdateVideoConfigConVars(pConfigKeys: configData.pConfigKeys);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&configData.displayModes);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028DC0
// Name: private: bool CShaderDeviceMgrBase::GetRecommendedConfigurationInfo(int,int,int,int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrBase::GetRecommendedConfigurationInfo(
        CShaderDeviceMgrBase *this,
        int nAdapter,
        int nDXLevel,
        int nVendorID,
        int nDeviceID,
        KeyValues *pConfiguration)
{
  int v6; // edi
  CShaderDeviceMgrBase_vtbl *v8; // edx
  int v9; // eax
  void (__thiscall *GetDesktopResolution)(CShaderDeviceMgrBase *, int *, int *, int); // edx
  int v11; // ebx
  int v13; // [esp+20h] [ebp-1A0h]
  _MEMORYSTATUS Buffer; // [esp+24h] [ebp-19Ch] BYREF
  VidMatConfigData_t configData; // [esp+44h] [ebp-17Ch] BYREF

  v6 = 0;
  memset(&configData.displayModes, 0, sizeof(configData.displayModes));
  _V_strcpy(dest: configData.szFileName, src: "..\\bin\\dxsupport.cfg");
  _V_strcpy(dest: configData.szPathID, src: "GAME");
  configData.pConfigKeys = pConfiguration;
  configData.nVendorID = nVendorID;
  configData.nDeviceID = nDeviceID;
  GlobalMemoryStatus(lpBuffer: &Buffer);
  v8 = this->__vftable;
  configData.nSystemMemory = Buffer.dwTotalPhys >> 20;
  configData.nVideoMemory = v8->GetVidMemBytes(this, a2: nAdapter) / 0x100000;
  configData.bIsVideo = false;
  v9 = g_pHardwareConfig->GetMaxDXSupportLevel(this: g_pHardwareConfig);
  GetDesktopResolution = this->GetDesktopResolution;
  configData.nDXLevel = v9;
  GetDesktopResolution(this, a2: &configData.nPhysicalScreenWidth, a3: &configData.nPhysicalScreenHeight, a4: nAdapter);
  v11 = this->GetModeCount(this, a2: nAdapter);
  configData.displayModes.m_Size = 0;
  CUtlVector<ShaderDisplayMode_t,CUtlMemory<ShaderDisplayMode_t,int>>::InsertMultipleBefore(
    this: &configData.displayModes,
    elem: 0,
    num: v11);
  if ( v11 > 0 )
  {
    v13 = 0;
    do
      this->GetModeInfo(this, a2: &configData.displayModes.m_Memory.m_pMemory[v13++], a3: nAdapter, a4: v6++);
    while ( v6 < v11 );
  }
  RecommendedConfig(&configData);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&configData.displayModes);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028F30
// Name: public: virtual bool CShaderDeviceMgrBase::GetRecommendedVideoConfig(int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrBase::GetRecommendedVideoConfig(
        CShaderDeviceMgrBase *this,
        int nAdapter,
        KeyValues *pCongifuration)
{
  MaterialAdapterInfo_t info; // [esp+4h] [ebp-228h] BYREF

  this->GetAdapterInfo(this, a2: nAdapter, a3: (MaterialAdapterInfo_t *)&info.m_pDriverName[4]);
  return CShaderDeviceMgrBase::GetRecommendedVideoConfig(
           this,
           nAdapter,
           nVendorID: info.m_DeviceID,
           nDeviceID: info.m_SubSysID,
           pConfiguration: pCongifuration);
}

//------------------------------------------------------------------------------
// Address: 0x10028F80
// Name: public: virtual bool CShaderDeviceMgrBase::GetRecommendedConfigurationInfo(int,int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrBase::GetRecommendedConfigurationInfo(
        CShaderDeviceMgrBase *this,
        int nAdapter,
        int nDXLevel,
        KeyValues *pCongifuration)
{
  MaterialAdapterInfo_t info; // [esp+4h] [ebp-228h] BYREF

  this->GetAdapterInfo(this, a2: nAdapter, a3: (MaterialAdapterInfo_t *)&info.m_pDriverName[4]);
  return CShaderDeviceMgrBase::GetRecommendedConfigurationInfo(
           this,
           nAdapter,
           nDXLevel,
           nVendorID: info.m_DeviceID,
           nDeviceID: info.m_SubSysID,
           pConfiguration: pCongifuration);
}

//------------------------------------------------------------------------------
// Address: 0x1004FF80
// Name: public: virtual enum AppSystemTier_t CBaseAppSystem<class IShaderDeviceMgr>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IShaderDeviceMgr>::GetTier(CBaseAppSystem<IShaderDeviceMgr> *this)
{
  return 4;
}

} // namespace shaderapidx10
