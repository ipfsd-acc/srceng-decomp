// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/wmi.cpp
// Functions: 10
// ============================================================

#include "materialsystem\shaderapidx9\wmi.h"

//------------------------------------------------------------------------------
// Address: 0x10031B80
// Name: public: _bstr_t::_bstr_t(char const __near *)
// Source: json
//------------------------------------------------------------------------------
_bstr_t *__thiscall _bstr_t::_bstr_t(_bstr_t *this, const char *s)
{
  _bstr_t::Data_t *v3; // esi

  v3 = (_bstr_t::Data_t *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
  {
    v3->m_str = nullptr;
    v3->m_RefCount = 1;
    v3->m_wstr = _com_util::ConvertStringToBSTR(pSrc: s);
  }
  else
  {
    v3 = nullptr;
  }
  this->m_Data = v3;
  if ( v3 == nullptr )
    _com_issue_error(hr: -2147024882);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10031BD0
// Name: public: _bstr_t::_bstr_t(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
_bstr_t *__thiscall _bstr_t::_bstr_t(_bstr_t *this, const wchar_t *s)
{
  _bstr_t::Data_t *v3; // eax
  _bstr_t::Data_t *v4; // esi
  BSTR v5; // eax

  v3 = (_bstr_t::Data_t *)operator new(nSize: 0xCu);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v3->m_str = nullptr;
    v3->m_RefCount = 1;
    v5 = SysAllocString(psz: s);
    v4->m_wstr = v5;
    if ( v5 == nullptr && s != nullptr )
      _com_issue_error(hr: -2147024882);
  }
  else
  {
    v4 = nullptr;
  }
  this->m_Data = v4;
  if ( v4 == nullptr )
    _com_issue_error(hr: -2147024882);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10031C40
// Name: public: _bstr_t::~_bstr_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall _bstr_t::~_bstr_t(_bstr_t *this)
{
  _bstr_t::Data_t *m_Data; // esi

  m_Data = this->m_Data;
  if ( this->m_Data != nullptr )
  {
    if ( InterlockedDecrement(lpAddend: (volatile LONG *)&m_Data->m_RefCount) == 0 && m_Data != nullptr )
    {
      if ( m_Data->m_wstr != nullptr )
        SysFreeString(bstrString: m_Data->m_wstr);
      if ( m_Data->m_str != nullptr )
        free(pMem: m_Data->m_str);
      free(pMem: m_Data);
    }
    this->m_Data = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031C90
// Name: int GetVidMemBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall GetVidMemBytes@<eax>(int a1@<ebx>, int a2@<esi>)
{
  _bstr_t::Data_t *m_Data; // eax
  wchar_t *m_wstr; // ecx
  int v5; // esi
  _bstr_t::Data_t *v6; // eax
  wchar_t *v7; // esi
  _bstr_t::Data_t *v8; // eax
  wchar_t *v9; // ecx
  int v10; // esi
  IEnumWbemClassObject *v11; // eax
  tagVARIANT vtProp; // [esp+4h] [ebp-2Ch] BYREF
  _bstr_t v13; // [esp+14h] [ebp-1Ch] BYREF
  _bstr_t v14; // [esp+18h] [ebp-18h] BYREF
  unsigned int uReturn; // [esp+1Ch] [ebp-14h] BYREF
  IWbemClassObject *pclsObj; // [esp+20h] [ebp-10h] BYREF
  IEnumWbemClassObject *pEnumerator; // [esp+24h] [ebp-Ch] BYREF
  IWbemLocator *pLoc; // [esp+28h] [ebp-8h] BYREF
  IWbemServices *pSvc; // [esp+2Ch] [ebp-4h] BYREF

  if ( bBeenHere != 0 )
    return nBytes;
  bBeenHere = 1;
  if ( CoInitialize(pvReserved: nullptr) < 0 )
  {
    OutputDebugStringA(lpOutputString: "GetWMIDeviceStats - Unable to initialize COM library.\n");
    return 0;
  }
  if ( CoInitializeSecurity(
         pSecDesc: nullptr,
         cAuthSvc: -1,
         asAuthSvc: nullptr,
         pReserved1: nullptr,
         dwAuthnLevel: 0,
         dwImpLevel: 3u,
         pAuthList: nullptr,
         dwCapabilities: 0,
         pReserved3: nullptr) < 0 )
  {
    OutputDebugStringA(lpOutputString: "GetWMIDeviceStats - Unable to initialize security.\n");
    CoUninitialize();
    return 0;
  }
  pLoc = nullptr;
  if ( CoCreateInstance(
         rclsid: &CLSID_WbemLocator,
         pUnkOuter: nullptr,
         dwClsContext: 1u,
         riid: &IID_IWbemLocator,
         ppv: (LPVOID *)&pLoc) < 0 )
  {
    OutputDebugStringA(lpOutputString: "GetWMIDeviceStats - Failed to create IWbemLocator object.\n");
    CoUninitialize();
    return 0;
  }
  pSvc = nullptr;
  m_Data = _bstr_t::_bstr_t(this: &v14, s: L"ROOT\\CIMV2")->m_Data;
  if ( m_Data != nullptr )
    m_wstr = m_Data->m_wstr;
  else
    m_wstr = nullptr;
  v5 = ((int (__stdcall *)(IWbemLocator *, wchar_t *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, IWbemServices **, int))pLoc->ConnectServer)(
         a1: pLoc,
         a2: m_wstr,
         a3: 0,
         a4: 0,
         a5: 0,
         a6: 0,
         a7: 0,
         a8: 0,
         a9: &pSvc,
         a10: a2);
  _bstr_t::~_bstr_t(this: &v14);
  if ( v5 < 0 )
  {
    OutputDebugStringA(lpOutputString: "GetWMIDeviceStats - Could not connect.\n");
LABEL_16:
    ((void (__cdecl *)(IWbemLocator *))pLoc->Release)(a1: pLoc);
    CoUninitialize();
    return 0;
  }
  if ( CoSetProxyBlanket(
         pProxy: pSvc,
         dwAuthnSvc: 0xAu,
         dwAuthzSvc: 0,
         pServerPrincName: nullptr,
         dwAuthnLevel: 3u,
         dwImpLevel: 3u,
         pAuthInfo: nullptr,
         dwCapabilities: 0) < 0 )
  {
    OutputDebugStringA(lpOutputString: "GetWMIDeviceStats - Could not set proxy blanket.\n");
    pSvc->Release(this: pSvc);
    goto LABEL_16;
  }
  pEnumerator = nullptr;
  v6 = _bstr_t::_bstr_t(this: &v13, s: "SELECT * FROM Win32_VideoController")->m_Data;
  if ( v6 != nullptr )
    v7 = v6->m_wstr;
  else
    v7 = nullptr;
  v8 = _bstr_t::_bstr_t(this: &v14, s: "WQL")->m_Data;
  if ( v8 != nullptr )
    v9 = v8->m_wstr;
  else
    v9 = nullptr;
  v10 = ((int (__stdcall *)(IWbemServices *, wchar_t *, wchar_t *, int, _DWORD, IEnumWbemClassObject **, int))pSvc->ExecQuery)(
          a1: pSvc,
          a2: v9,
          a3: v7,
          a4: 48,
          a5: 0,
          a6: &pEnumerator,
          a7: a1);
  _bstr_t::~_bstr_t(this: &v14);
  _bstr_t::~_bstr_t(this: &v13);
  if ( v10 >= 0 )
  {
    v11 = pEnumerator;
    pclsObj = nullptr;
    for ( uReturn = 0; pEnumerator != nullptr; v11 = pEnumerator )
    {
      v11->Next(this: v11, a2: -1, a3: 1u, a4: &pclsObj, a5: &uReturn);
      if ( uReturn == 0 )
        break;
      VariantInit(pvarg: &vtProp);
      if ( pclsObj->Get(this: pclsObj, a2: L"AdapterRAM", a3: 0, a4: &vtProp, a5: nullptr, a6: nullptr) >= 0 )
        nBytes = vtProp.lVal;
      VariantClear(pvarg: &vtProp);
    }
    ((void (__cdecl *)(IWbemServices *))pSvc->Release)(a1: pSvc);
    ((void (__cdecl *)(IWbemLocator *))pLoc->Release)(a1: pLoc);
    pEnumerator->Release(this: pEnumerator);
    pclsObj->Release(this: pclsObj);
    CoUninitialize();
    return nBytes;
  }
  else
  {
    OutputDebugStringA(lpOutputString: "GetWMIDeviceStats - Query for Win32_VideoController failed.\n");
    ((void (__cdecl *)(IWbemServices *))pSvc->Release)(a1: pSvc);
    ((void (__cdecl *)(IWbemLocator *))pLoc->Release)(a1: pLoc);
    CoUninitialize();
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031F00
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10031F20
// Name: __calloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _calloc_crt(unsigned int count, unsigned int size)
{
  unsigned __int8 *v2; // edi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size * count);
  memset(dst: v2, value: 0, count: size * count);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10031F50
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x10031F70
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _recalloc_crt(void *ptr, unsigned int count, unsigned int size)
{
  unsigned __int8 *v3; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size * count);
  memset(dst: v3, value: 0, count: size * count);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10031FB0
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _msize(void *pMem)
{
  return _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x10031FD0
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x100385B0
// Name: public: _bstr_t::_bstr_t(char const __near *)
// Source: json
//------------------------------------------------------------------------------
_bstr_t *__thiscall _bstr_t::_bstr_t(_bstr_t *this, const char *s)
{
  _bstr_t::Data_t *v3; // esi

  v3 = (_bstr_t::Data_t *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
  {
    v3->m_str = nullptr;
    v3->m_RefCount = 1;
    v3->m_wstr = _com_util::ConvertStringToBSTR(pSrc: s);
  }
  else
  {
    v3 = nullptr;
  }
  this->m_Data = v3;
  if ( v3 == nullptr )
    _com_issue_error(hr: -2147024882);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10038600
// Name: public: _bstr_t::_bstr_t(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
_bstr_t *__thiscall _bstr_t::_bstr_t(_bstr_t *this, const wchar_t *s)
{
  _bstr_t::Data_t *v3; // eax
  _bstr_t::Data_t *v4; // esi
  BSTR v5; // eax

  v3 = (_bstr_t::Data_t *)operator new(nSize: 0xCu);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v3->m_str = nullptr;
    v3->m_RefCount = 1;
    v5 = SysAllocString(psz: s);
    v4->m_wstr = v5;
    if ( v5 == nullptr && s != nullptr )
      _com_issue_error(hr: -2147024882);
  }
  else
  {
    v4 = nullptr;
  }
  this->m_Data = v4;
  if ( v4 == nullptr )
    _com_issue_error(hr: -2147024882);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10038660
// Name: public: _bstr_t::~_bstr_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall _bstr_t::~_bstr_t(_bstr_t *this)
{
  _bstr_t::Data_t *m_Data; // esi

  m_Data = this->m_Data;
  if ( this->m_Data != nullptr )
  {
    if ( InterlockedDecrement(lpAddend: (volatile LONG *)&m_Data->m_RefCount) == 0 && m_Data != nullptr )
    {
      if ( m_Data->m_wstr != nullptr )
        SysFreeString(bstrString: m_Data->m_wstr);
      if ( m_Data->m_str != nullptr )
        free(pMem: m_Data->m_str);
      free(pMem: m_Data);
    }
    this->m_Data = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100386B0
// Name: int GetVidMemBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall GetVidMemBytes@<eax>(int a1@<ebx>, int a2@<esi>)
{
  _bstr_t::Data_t *m_Data; // eax
  wchar_t *m_wstr; // ecx
  int v5; // esi
  _bstr_t::Data_t *v6; // eax
  wchar_t *v7; // esi
  _bstr_t::Data_t *v8; // eax
  wchar_t *v9; // ecx
  int v10; // esi
  int v11; // eax
  IWbemLocator *pLoc; // [esp+68h] [ebp-2Ch] BYREF
  IEnumWbemClassObject *pEnumerator; // [esp+6Ch] [ebp-28h] BYREF
  IWbemClassObject *pclsObj; // [esp+70h] [ebp-24h]
  unsigned int uReturn; // [esp+74h] [ebp-20h] BYREF
  int v16; // [esp+78h] [ebp-1Ch]
  _bstr_t v17; // [esp+7Ch] [ebp-18h] BYREF
  tagVARIANT vtProp; // [esp+80h] [ebp-14h] BYREF
  int retaddr; // [esp+94h] [ebp+0h]

  if ( bBeenHere != 0 )
    return nBytes;
  bBeenHere = 1;
  if ( CoInitialize(pvReserved: nullptr) < 0 )
  {
    OutputDebugStringA(lpOutputString: "GetWMIDeviceStats - Unable to initialize COM library.\n");
    return 0;
  }
  if ( CoInitializeSecurity(
         pSecDesc: nullptr,
         cAuthSvc: -1,
         asAuthSvc: nullptr,
         pReserved1: nullptr,
         dwAuthnLevel: 0,
         dwImpLevel: 3u,
         pAuthList: nullptr,
         dwCapabilities: 0,
         pReserved3: nullptr) < 0 )
  {
    OutputDebugStringA(lpOutputString: "GetWMIDeviceStats - Unable to initialize security.\n");
    CoUninitialize();
    return 0;
  }
  pEnumerator = nullptr;
  if ( CoCreateInstance(
         rclsid: &CLSID_WbemLocator,
         pUnkOuter: nullptr,
         dwClsContext: 1u,
         riid: &IID_IWbemLocator,
         ppv: (LPVOID *)&pEnumerator) < 0 )
  {
    OutputDebugStringA(lpOutputString: "GetWMIDeviceStats - Failed to create IWbemLocator object.\n");
    CoUninitialize();
    return 0;
  }
  pLoc = nullptr;
  m_Data = _bstr_t::_bstr_t(this: &v17, s: L"ROOT\\CIMV2")->m_Data;
  if ( m_Data != nullptr )
    m_wstr = m_Data->m_wstr;
  else
    m_wstr = nullptr;
  v5 = ((int (__stdcall *)(IEnumWbemClassObject *, wchar_t *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, IWbemLocator **, int))pEnumerator->Reset)(
         a1: pEnumerator,
         a2: m_wstr,
         a3: 0,
         a4: 0,
         a5: 0,
         a6: 0,
         a7: 0,
         a8: 0,
         a9: &pLoc,
         a10: a2);
  _bstr_t::~_bstr_t(this: (_bstr_t *)&vtProp);
  if ( v5 < 0 )
  {
    OutputDebugStringA(lpOutputString: "GetWMIDeviceStats - Could not connect.\n");
LABEL_16:
    ((void (__cdecl *)(IWbemClassObject *))pclsObj->Release)(a1: pclsObj);
    CoUninitialize();
    return 0;
  }
  if ( CoSetProxyBlanket(
         pProxy: pEnumerator,
         dwAuthnSvc: 0xAu,
         dwAuthzSvc: 0,
         pServerPrincName: nullptr,
         dwAuthnLevel: 3u,
         dwImpLevel: 3u,
         pAuthInfo: nullptr,
         dwCapabilities: 0) < 0 )
  {
    OutputDebugStringA(lpOutputString: "GetWMIDeviceStats - Could not set proxy blanket.\n");
    pEnumerator->Release(this: pEnumerator);
    goto LABEL_16;
  }
  uReturn = 0;
  v6 = _bstr_t::_bstr_t(this: (_bstr_t *)&vtProp.gap0[4], s: "SELECT * FROM Win32_VideoController")->m_Data;
  if ( v6 != nullptr )
    v7 = v6->m_wstr;
  else
    v7 = nullptr;
  v8 = _bstr_t::_bstr_t(this: (_bstr_t *)&vtProp, s: "WQL")->m_Data;
  if ( v8 != nullptr )
    v9 = v8->m_wstr;
  else
    v9 = nullptr;
  v10 = ((int (__stdcall *)(IEnumWbemClassObject *, wchar_t *, wchar_t *, int, _DWORD, unsigned int *, int))pEnumerator->__vftable[2].Next)(
          a1: pEnumerator,
          a2: v9,
          a3: v7,
          a4: 48,
          a5: 0,
          a6: &uReturn,
          a7: a1);
  _bstr_t::~_bstr_t(this: (_bstr_t *)&vtProp.gap0[4]);
  _bstr_t::~_bstr_t(this: (_bstr_t *)&vtProp.boolVal);
  if ( v10 >= 0 )
  {
    v11 = v16;
    v17.m_Data = nullptr;
    for ( *(_DWORD *)&vtProp.vt = 0; v16 != 0; v11 = v16 )
    {
      (*(void (__stdcall **)(int, int, int, _bstr_t *, tagVARIANT *))(*(_DWORD *)v11 + 16))(
        a1: v11,
        a2: -1,
        a3: 1,
        a4: &v17,
        a5: &vtProp);
      if ( *(_DWORD *)&vtProp.vt == 0 )
        break;
      VariantInit(pvarg: (VARIANTARG *)(&vtProp.__s11 + 1));
      if ( (*((int (__stdcall **)(_bstr_t::Data_t *, const wchar_t *, _DWORD, $261BEEB313B83FAB7A29882CACD73968 *, _DWORD, _DWORD))v17.m_Data->m_wstr
            + 4))(
             a1: v17.m_Data,
             a2: L"AdapterRAM",
             a3: 0,
             a4: &vtProp.__s11 + 1,
             a5: 0,
             a6: 0) >= 0 )
        nBytes = retaddr;
      VariantClear(pvarg: (VARIANTARG *)(&vtProp.__s11 + 1));
    }
    ((void (__cdecl *)(IWbemClassObject *))pclsObj->Release)(a1: pclsObj);
    ((void (__cdecl *)(IWbemClassObject *))pclsObj->Release)(a1: pclsObj);
    pclsObj->Release(this: pclsObj);
    (*(void (__stdcall **)(unsigned int))(*(_DWORD *)uReturn + 8))(a1: uReturn);
    CoUninitialize();
    return nBytes;
  }
  else
  {
    OutputDebugStringA(lpOutputString: "GetWMIDeviceStats - Query for Win32_VideoController failed.\n");
    ((void (__cdecl *)(IWbemClassObject *))pclsObj->Release)(a1: pclsObj);
    ((void (__cdecl *)(IWbemClassObject *))pclsObj->Release)(a1: pclsObj);
    CoUninitialize();
    return 0;
  }
}

} // namespace shaderapidx10
