// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/dtlibwrapper/dtlibwrapper.cpp
// Functions: 59
// ============================================================

#include "utils\ps3\dtlibwrapper\dtlibwrapper.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: public: Idtwrap::Idtwrap(void)
// Source: json
//------------------------------------------------------------------------------
Idtwrap *__thiscall Idtwrap::Idtwrap(Idtwrap *this)
{
  this->__vftable = (Idtwrap_vtbl *)&Idtwrap::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001010
// Name: public: Idtwrap::Idtwrap(class Idtwrap const __near &)
// Source: json
//------------------------------------------------------------------------------
Idtwrap *__thiscall Idtwrap::Idtwrap(Idtwrap *this, const Idtwrap *__that)
{
  this->__vftable = (Idtwrap_vtbl *)&Idtwrap::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001020
// Name: public: class Idtwrap __near & Idtwrap::operator=(class Idtwrap const __near &)
// Source: json
//------------------------------------------------------------------------------
Idtwrap *__thiscall Idtwrap::operator=(Idtwrap *this, const Idtwrap *__that)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001030
// Name: DllMain(x,x,x)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10001040
// Name: public: dtwrap::dtwrap(void)
// Source: json
//------------------------------------------------------------------------------
dtwrap *__thiscall dtwrap::dtwrap(dtwrap *this)
{
  this->__vftable = (dtwrap_vtbl *)&dtwrap::`vftable';
  deci3_lib::dtlib::dtlib(this: &this->m_dtlib);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001060
// Name: public: dtwrap::~dtwrap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall dtwrap::~dtwrap(dtwrap *this)
{
  deci3_lib::dtlib::~dtlib(this: &this->m_dtlib);
}

//------------------------------------------------------------------------------
// Address: 0x10001070
// Name: public: dtwrap::dtwrap(class dtwrap const __near &)
// Source: json
//------------------------------------------------------------------------------
dtwrap *__thiscall dtwrap::dtwrap(dtwrap *this, const dtwrap *__that)
{
  this->__vftable = (dtwrap_vtbl *)&dtwrap::`vftable';
  this->m_dtlib = __that->m_dtlib;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100010A0
// Name: public: class dtwrap __near & dtwrap::operator=(class dtwrap const __near &)
// Source: json
//------------------------------------------------------------------------------
dtwrap *__thiscall dtwrap::operator=(dtwrap *this, const dtwrap *__that)
{
  this->m_dtlib = __that->m_dtlib;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100010C0
// Name: public: static class Idtwrap __near * Idtwrap::GetSingleton(void)
// Source: json
//------------------------------------------------------------------------------
dtwrap *__cdecl Idtwrap::GetSingleton()
{
  return &g_SingletonDtWrapper;
}

//------------------------------------------------------------------------------
// Address: 0x100010D0
// Name: public: virtual unsigned int dtwrap::dt_set_option(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall dtwrap::dt_set_option(dtwrap *this, unsigned int value)
{
  return deci3_lib::dtlib::dt_set_option(this: &this->m_dtlib, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x100010E0
// Name: public: virtual void __near * dtwrap::dt_connect(char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall dtwrap::dt_connect(dtwrap *this, const char *hostname, int portNo, const char *programName)
{
  _DWORD v6[7]; // [esp-8h] [ebp-50h] BYREF
  int v7; // [esp+14h] [ebp-34h]
  _DWORD v8[9]; // [esp+18h] [ebp-30h] BYREF
  int v9; // [esp+44h] [ebp-4h]

  v8[8] = v8;
  std::string::string(a1: v8, a2: programName);
  v7 = portNo;
  v9 = 0;
  std::string::string(a1: v6, a2: hostname);
  v9 = -1;
  return deci3_lib::dtlib::dt_connect(
           a1: &this->m_dtlib,
           a2: v6[0],
           a3: v6[1],
           a4: v6[2],
           a5: v6[3],
           a6: v6[4],
           a7: v6[5],
           a8: v6[6],
           a9: v7,
           a10: v8[0],
           a11: v8[1],
           a12: v8[2],
           a13: v8[3],
           a14: v8[4],
           a15: v8[5],
           a16: v8[6]);
}

//------------------------------------------------------------------------------
// Address: 0x10001160
// Name: public: virtual void dtwrap::dt_disconnect(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall dtwrap::dt_disconnect(dtwrap *this, void *connect)
{
  deci3_lib::dtlib::dt_disconnect(this: &this->m_dtlib, a2: connect);
}

//------------------------------------------------------------------------------
// Address: 0x10001170
// Name: public: virtual void __near * dtwrap::dt_register(void __near *,int,int,enum deci3_lib::DT_DESTINATION,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall dtwrap::dt_register(
        dtwrap *this,
        void *connectH,
        int protocol,
        int port,
        deci3_lib::DT_DESTINATION dst,
        const char *lparName,
        int priority)
{
  _DWORD v9[7]; // [esp-20h] [ebp-24h] BYREF
  int v10; // [esp-4h] [ebp-8h]

  v10 = priority;
  std::string::string(a1: v9, a2: lparName);
  return deci3_lib::dtlib::dt_register(
           a1: &this->m_dtlib,
           a2: connectH,
           a3: protocol,
           a4: port,
           a5: dst,
           a6: v9[0],
           a7: v9[1],
           a8: v9[2],
           a9: v9[3],
           a10: v9[4],
           a11: v9[5],
           a12: v9[6],
           a13: v10);
}

//------------------------------------------------------------------------------
// Address: 0x100011B0
// Name: public: virtual int dtwrap::dt_unregister(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_unregister(dtwrap *this, void *deciHandle)
{
  return deci3_lib::dtlib::dt_unregister(this: &this->m_dtlib, a2: deciHandle);
}

//------------------------------------------------------------------------------
// Address: 0x100011C0
// Name: public: virtual int dtwrap::dt_send(void __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_send(dtwrap *this, void *deciHandle, unsigned __int8 *data, int length)
{
  return deci3_lib::dtlib::dt_send(this: &this->m_dtlib, a2: deciHandle, a3: data, a4: length);
}

//------------------------------------------------------------------------------
// Address: 0x100011D0
// Name: public: virtual int dtwrap::dt_receive(void __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_receive(dtwrap *this, void *deciHandle, unsigned __int8 *data, int length)
{
  return deci3_lib::dtlib::dt_receive(this: &this->m_dtlib, a2: deciHandle, a3: data, a4: length);
}

//------------------------------------------------------------------------------
// Address: 0x100011E0
// Name: public: virtual int dtwrap::dt_getlasterror(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_getlasterror(dtwrap *this)
{
  return deci3_lib::dtlib::dt_getlasterror(this: &this->m_dtlib);
}

//------------------------------------------------------------------------------
// Address: 0x100011F0
// Name: public: virtual int dtwrap::dt_geterrormsg(char __near *,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_geterrormsg(dtwrap *this, char *pOutBuf, unsigned int bufLen, int error)
{
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  int v7; // esi
  _BYTE v9[28]; // [esp+Ch] [ebp-1Ch] BYREF

  v4 = deci3_lib::dtlib::dt_geterrormsg(a1: &this->m_dtlib, a2: v9, a3: error);
  v5 = v4;
  if ( *(_DWORD *)(v4 + 24) < 0x10u )
    v6 = (const char *)(v4 + 4);
  else
    v6 = *(const char **)(v4 + 4);
  _strncpy(Destination: pOutBuf, Source: v6, Count: bufLen - 1);
  pOutBuf[bufLen - 1] = 0;
  v7 = *(_DWORD *)(v5 + 20);
  std::string::~string(a1: v9);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10001250
// Name: public: virtual int dtwrap::dt_get_protocol(void __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_get_protocol(dtwrap *this, void *handle, int *protocol, int *port)
{
  return deci3_lib::dtlib::dt_get_protocol(this: &this->m_dtlib, a2: handle, a3: protocol, a4: port);
}

//------------------------------------------------------------------------------
// Address: 0x10001260
// Name: public: virtual int dtwrap::dt_get_version(char __near *,unsigned int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_get_version(dtwrap *this, char *pOutBuf, unsigned int bufLen, void *connectH)
{
  int version; // eax
  int v5; // esi
  const char *v6; // eax
  int v7; // esi
  _BYTE v9[28]; // [esp+Ch] [ebp-1Ch] BYREF

  version = deci3_lib::dtlib::dt_get_version(a1: &this->m_dtlib, a2: v9, a3: connectH);
  v5 = version;
  if ( *(_DWORD *)(version + 24) < 0x10u )
    v6 = (const char *)(version + 4);
  else
    v6 = *(const char **)(version + 4);
  _strncpy(Destination: pOutBuf, Source: v6, Count: bufLen - 1);
  pOutBuf[bufLen - 1] = 0;
  v7 = *(_DWORD *)(v5 + 20);
  std::string::~string(a1: v9);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100012C0
// Name: public: virtual int dtwrap::dt_power_status(void __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_power_status(dtwrap *this, void *connH, int *status)
{
  return deci3_lib::dtlib::dt_power_status(this: &this->m_dtlib, a2: connH, a3: status);
}

//------------------------------------------------------------------------------
// Address: 0x100012D0
// Name: public: virtual void __near * dtwrap::dt_select(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall dtwrap::dt_select(dtwrap *this, void *connH, int waitTime)
{
  return deci3_lib::dtlib::dt_select(this: &this->m_dtlib, a2: connH, a3: waitTime);
}

//------------------------------------------------------------------------------
// Address: 0x100012E0
// Name: public: virtual int dtwrap::dt_set_dcmp_status_function(void __near *,int (*)(void __near *,unsigned char __near *,int))
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_set_dcmp_status_function(
        dtwrap *this,
        void *connectH,
        int (__stdcall *func)(void *, unsigned __int8 *, int))
{
  return deci3_lib::dtlib::dt_set_dcmp_status_function(this: &this->m_dtlib, a2: connectH, a3: func);
}

//------------------------------------------------------------------------------
// Address: 0x100012F0
// Name: public: virtual int dtwrap::dt_add_recv_function(void __near *,int (*)(void __near *,unsigned char __near *,int,int))
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_add_recv_function(
        dtwrap *this,
        void *deicH,
        int (__stdcall *func)(void *, unsigned __int8 *, int, int))
{
  return deci3_lib::dtlib::dt_add_recv_function(this: &this->m_dtlib, a2: deicH, a3: func);
}

//------------------------------------------------------------------------------
// Address: 0x10001300
// Name: public: virtual int dtwrap::dt_delete_recv_function(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_delete_recv_function(dtwrap *this, void *deciH)
{
  return deci3_lib::dtlib::dt_delete_recv_function(this: &this->m_dtlib, a2: deciH);
}

//------------------------------------------------------------------------------
// Address: 0x10001310
// Name: public: virtual int dtwrap::dt_send_dcmp(void __near *,char const __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_send_dcmp(
        dtwrap *this,
        void *connectH,
        const char *lparName,
        unsigned __int8 *data,
        int dataSize)
{
  _DWORD v7[7]; // [esp-24h] [ebp-28h] BYREF
  unsigned __int8 *v8; // [esp-8h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-8h]

  v9 = dataSize;
  v8 = data;
  std::string::string(a1: v7, a2: lparName);
  return deci3_lib::dtlib::dt_send_dcmp(
           a1: &this->m_dtlib,
           a2: connectH,
           a3: v7[0],
           a4: v7[1],
           a5: v7[2],
           a6: v7[3],
           a7: v7[4],
           a8: v7[5],
           a9: v7[6],
           a10: v8,
           a11: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10001350
// Name: public: virtual int dtwrap::dt_set_dcmp_echo_function(void __near *,int (*)(void __near *,unsigned char __near *,int))
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_set_dcmp_echo_function(
        dtwrap *this,
        void *connectH,
        int (__stdcall *func)(void *, unsigned __int8 *, int))
{
  return deci3_lib::dtlib::dt_set_dcmp_echo_function(this: &this->m_dtlib, a2: connectH, a3: func);
}

//------------------------------------------------------------------------------
// Address: 0x10001360
// Name: void std::_Destroy_range<struct DtRegisteredInfo,class std::allocator<struct DtRegisteredInfo>>(struct DtRegisteredInfo __near *,struct DtRegisteredInfo __near *,class std::allocator<struct DtRegisteredInfo> __near &,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Destroy_range<DtRegisteredInfo>(DtRegisteredInfo *_First, DtRegisteredInfo *_Last)
{
  DtRegisteredInfo *i; // esi

  for ( i = _First; i != _Last; ++i )
  {
    std::string::~string(a1: &i->info);
    std::string::~string(a1: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100013C0
// Name: public: virtual int dtwrap::dt_get_protocol_list(struct DtProtocolInfo __near *,unsigned int,void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
DtProtocolInfo *__thiscall dtwrap::dt_get_protocol_list(
        dtwrap *this,
        DtProtocolInfo *pOutArray,
        unsigned int outLen,
        void *connectH,
        const char *lparName)
{
  DtProtocolInfo *result; // eax
  DtProtocolInfo *Myend; // edx
  unsigned int v8; // ebx
  unsigned int i; // esi
  int v10; // esi
  _DWORD v11[11]; // [esp-10h] [ebp-40h] BYREF
  std::vector<DtProtocolInfo> list; // [esp+1Ch] [ebp-14h] BYREF

  *(_DWORD *)&list._Alval.std::_Allocator_base<DtProtocolInfo> = v11;
  std::string::string(a1: v11, a2: lparName);
  deci3_lib::dtlib::dt_get_protocol_list(
    a1: &this->m_dtlib,
    a2: &list._Myfirst,
    a3: connectH,
    a4: v11[0],
    a5: v11[1],
    a6: v11[2],
    a7: v11[3],
    a8: v11[4],
    a9: v11[5],
    a10: v11[6]);
  result = list._Mylast;
  Myend = list._Myend;
  if ( list._Mylast != nullptr )
  {
    v8 = outLen;
    if ( outLen >= list._Myend - list._Mylast )
      v8 = list._Myend - list._Mylast;
  }
  else
  {
    v8 = 0;
  }
  for ( i = 0; i < v8; ++i )
  {
    if ( result == nullptr || i >= Myend - result )
    {
      __invalid_parameter_noinfo();
      Myend = list._Myend;
      result = list._Mylast;
    }
    pOutArray[i] = result[i];
  }
  if ( result != nullptr )
  {
    v10 = Myend - result;
    operator delete(a1: result);
    return (DtProtocolInfo *)v10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001480
// Name: public: virtual int dtwrap::dt_get_lparlist(char (__near * const)[64],unsigned int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_get_lparlist(dtwrap *this, char (*pOutBufs)[64], unsigned int numBufs, unsigned int connectH)
{
  std::string *Mylast; // ecx
  std::string *Myend; // esi
  int v6; // ebx
  unsigned int i; // ebp
  const char *Buf; // ecx
  int v11; // edi
  std::string *v12; // ebx
  std::vector<std::string> list; // [esp+8h] [ebp-14h] BYREF
  unsigned int sentinel; // [esp+28h] [ebp+Ch]

  deci3_lib::dtlib::dt_get_lparlist(a1: &this->m_dtlib, a2: &list._Myfirst, a3: connectH);
  Mylast = list._Mylast;
  Myend = list._Myend;
  v6 = 0;
  if ( list._Mylast != nullptr )
  {
    if ( numBufs >= list._Myend - list._Mylast )
      sentinel = list._Myend - list._Mylast;
    else
      sentinel = numBufs;
  }
  else
  {
    sentinel = 0;
  }
  for ( i = 0; i < sentinel; ++pOutBufs )
  {
    if ( Mylast == nullptr || i >= Myend - Mylast )
    {
      __invalid_parameter_noinfo();
      Mylast = list._Mylast;
    }
    if ( Mylast[v6]._Myres < 0x10 )
      Buf = Mylast[v6]._Bx._Buf;
    else
      Buf = Mylast[v6]._Bx._Ptr;
    _strncpy(Destination: (char *)pOutBufs, Source: Buf, Count: 0x3Fu);
    Myend = list._Myend;
    Mylast = list._Mylast;
    (*pOutBufs)[63] = 0;
    ++i;
    ++v6;
  }
  if ( Mylast == nullptr )
    return 0;
  v11 = Myend - Mylast;
  v12 = Mylast;
  if ( Mylast != Myend )
  {
    do
      std::string::~string(a1: v12++);
    while ( v12 != Myend );
    Mylast = list._Mylast;
  }
  operator delete(a1: Mylast);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x100015A0
// Name: public: std::vector<struct DtRegisteredInfo,class std::allocator<struct DtRegisteredInfo>>::~vector<struct DtRegisteredInfo,class std::allocator<struct DtRegisteredInfo>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<DtRegisteredInfo>::~vector<DtRegisteredInfo>(std::vector<DtRegisteredInfo> *this)
{
  DtRegisteredInfo *Myfirst; // eax

  Myfirst = this->_Myfirst;
  if ( Myfirst != nullptr )
  {
    std::_Destroy_range<DtRegisteredInfo>(_First: Myfirst, _Last: this->_Mylast);
    operator delete(a1: this->_Myfirst);
  }
  this->_Myfirst = nullptr;
  this->_Mylast = nullptr;
  this->_Myend = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100015E0
// Name: public: virtual int dtwrap::dt_get_registered_list(struct DtRegisteredInfo __near *,unsigned int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall dtwrap::dt_get_registered_list(
        dtwrap *this,
        DtRegisteredInfo *pOutArray,
        unsigned int outLen,
        void *connectH)
{
  DtRegisteredInfo *Mylast; // ecx
  DtRegisteredInfo *Myend; // esi
  unsigned int v6; // ebx
  unsigned int v7; // ebp
  unsigned int *p_protocol; // edi
  char *v9; // esi
  char v10; // dl
  int v11; // edi
  std::vector<DtRegisteredInfo> list; // [esp+Ch] [ebp-20h] BYREF
  int v14; // [esp+28h] [ebp-4h]

  deci3_lib::dtlib::dt_get_registered_list(a1: &this->m_dtlib, a2: &list._Myfirst, a3: connectH);
  Mylast = list._Mylast;
  Myend = list._Myend;
  v6 = 0;
  v14 = 0;
  if ( list._Mylast != nullptr )
  {
    v7 = outLen;
    if ( outLen >= list._Myend - list._Mylast )
      v7 = list._Myend - list._Mylast;
  }
  else
  {
    v7 = 0;
  }
  if ( v7 != 0 )
  {
    p_protocol = &pOutArray->protocol;
    do
    {
      if ( Mylast == nullptr || v6 >= Myend - Mylast )
      {
        __invalid_parameter_noinfo();
        Mylast = list._Mylast;
      }
      v9 = (char *)p_protocol + (_DWORD)Mylast - (_DWORD)pOutArray - 56;
      std::string::operator=(a1: p_protocol - 14, a2: v9);
      std::string::operator=(a1: p_protocol - 7, a2: v9 + 28);
      *p_protocol = *((_DWORD *)v9 + 14);
      p_protocol[1] = *((_DWORD *)v9 + 15);
      *((_BYTE *)p_protocol + 8) = v9[64];
      v10 = v9[65];
      Myend = list._Myend;
      Mylast = list._Mylast;
      *((_BYTE *)p_protocol + 9) = v10;
      ++v6;
      p_protocol += 17;
    }
    while ( v6 < v7 );
  }
  if ( Mylast != nullptr )
    v11 = Myend - Mylast;
  else
    v11 = 0;
  v14 = -1;
  if ( Mylast != nullptr )
  {
    std::_Destroy_range<DtRegisteredInfo>(_First: Mylast, _Last: Myend);
    operator delete(a1: list._Mylast);
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x10001788
// Name: ??3@YAXPAX@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl operator delete(void *a1)
{
  __imp_??3@YAXPAX@Z(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10001833
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001845
// Name: pre_c_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl pre_c_init()
{
  _DWORD *v0; // esi

  v0 = (_DWORD *)__malloc_crt(a1: 128);
  __onexitbegin = (void (__cdecl **)())__encode_pointer(a1: v0);
  __onexitend = __onexitbegin;
  if ( v0 == nullptr )
    return 1;
  *v0 = 0;
  _RTC_Initialize();
  atexit(func: _RTC_Terminate);
  atexit(func: __clean_type_info_names);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001892
// Name: _CRT_INIT(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _CRT_INIT(void *hDllHandle, int dwReason, void *lpreserved)
{
  PVOID StackBase; // esi
  LONG v5; // eax
  int *v6; // ebp
  int *v7; // esi
  void (*v8)(void); // eax
  int nested; // [esp+Ch] [ebp+8h]
  int nesteda; // [esp+Ch] [ebp+8h]

  if ( dwReason == 0 )
  {
    if ( _proc_attached <= 0 )
      return 0;
    --_proc_attached;
  }
  _adjust_fdiv = (int)__adjust_fdiv;
  if ( dwReason == 1 )
  {
    StackBase = NtCurrentTeb()->NtTib.StackBase;
    nested = 0;
    while ( 1 )
    {
      v5 = InterlockedCompareExchange(Destination: &__native_startup_lock, Exchange: (LONG)StackBase, Comperand: 0);
      if ( v5 == 0 )
        break;
      if ( (PVOID)v5 == StackBase )
      {
        nested = 1;
        break;
      }
      Sleep(dwMilliseconds: 0x3E8u);
    }
    if ( __native_startup_state != __uninitialized )
    {
      _amsg_exit(a1: 31);
    }
    else
    {
      __native_startup_state = __initializing;
      if ( _initterm_e(First: (_PIFV *)&__xi_a, Last: (_PIFV *)&__xi_z) != 0 )
        return 0;
      _initterm(First: __xc_a, Last: __xc_z);
      __native_startup_state = __initialized;
    }
    if ( nested == 0 )
      InterlockedExchange(Target: &__native_startup_lock, Value: 0);
    if ( __dyn_tls_init_callback != nullptr
      && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&__dyn_tls_init_callback) != 0 )
    {
      __dyn_tls_init_callback(a1: hDllHandle, a2: 2u, a3: lpreserved);
    }
    ++_proc_attached;
  }
  else if ( dwReason == 0 )
  {
    while ( InterlockedCompareExchange(Destination: &__native_startup_lock, Exchange: 1, Comperand: 0) != 0 )
      Sleep(dwMilliseconds: 0x3E8u);
    if ( __native_startup_state == __initialized )
    {
      v6 = (int *)__decode_pointer(a1: __onexitbegin);
      if ( v6 != nullptr )
      {
        v7 = (int *)__decode_pointer(a1: __onexitend);
        while ( --v7 >= v6 )
        {
          if ( *v7 != 0 )
          {
            nesteda = *v7;
            if ( nesteda != __encoded_null() )
            {
              v8 = (void (*)(void))__decode_pointer(a1: nesteda);
              v8();
            }
          }
        }
        _free(Block: v6);
        __onexitend = (void (__cdecl **)())__encoded_null();
        __onexitbegin = __onexitend;
      }
      __native_startup_state = __uninitialized;
      InterlockedExchange(Target: &__native_startup_lock, Value: 0);
    }
    else
    {
      _amsg_exit(a1: 31);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001A55
// Name: __DllMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _DllMainCRTStartup(void *lpreserved, volatile unsigned int dwReason, HINSTANCE hDllHandle)
{
  BOOL v5; // eax
  int retcode; // [esp+14h] [ebp-1Ch]

  __native_dllmain_reason = dwReason;
  if ( dwReason != 0 || _proc_attached != 0 )
  {
    if ( dwReason != 1 && dwReason != 2 || (retcode = _CRT_INIT(hDllHandle, dwReason, lpreserved)) != 0 )
    {
      v5 = DllMain(hinstDLL: hDllHandle, fdwReason: dwReason, lpvReserved: lpreserved);
      retcode = v5;
      if ( dwReason == 1 && !v5 )
      {
        DllMain(hinstDLL: hDllHandle, fdwReason: 0, lpvReserved: lpreserved);
        _CRT_INIT(hDllHandle, dwReason: 0, lpreserved);
      }
      if ( (dwReason == 0 || dwReason == 3) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
        retcode = 0;
    }
  }
  else
  {
    retcode = 0;
  }
  __native_dllmain_reason = -1;
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x10001B6B
// Name: _DllMainCRTStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall _DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    __security_init_cookie();
  return _DllMainCRTStartup(lpreserved: lpReserved, dwReason: fdwReason, hDllHandle: hinstDLL);
}

//------------------------------------------------------------------------------
// Address: 0x10001B8C
// Name: void __ArrayUnwind(void __near *,unsigned int,int,void (*)(void __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __ArrayUnwind(char *ptr, unsigned int size, int count, void (*pDtor)(void))
{
  while ( --count >= 0 )
  {
    ptr -= size;
    pDtor();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001C4E
// Name: __unlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int _unlock()
{
  return __unlock();
}

//------------------------------------------------------------------------------
// Address: 0x10001C54
// Name: ___dllonexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __dllonexit()
{
  return ___dllonexit();
}

//------------------------------------------------------------------------------
// Address: 0x10001C5A
// Name: __lock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int _lock()
{
  return __lock();
}

//------------------------------------------------------------------------------
// Address: 0x10001CA5
// Name: __SEH_epilog4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _SEH_epilog4()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x10001CE8
// Name: __RTC_Initialize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Initialize()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001D0C
// Name: __RTC_Terminate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Terminate()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001D30
// Name: __ValidateImageBase
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ValidateImageBase(unsigned __int8 *pImageBase)
{
  unsigned __int8 *v2; // eax

  return *(_WORD *)pImageBase == 23117
      && *(_DWORD *)(v2 = &pImageBase[*((_DWORD *)pImageBase + 15)]) == 17744
      && *((_WORD *)v2 + 12) == 267;
}

//------------------------------------------------------------------------------
// Address: 0x10001D60
// Name: __FindPESection
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_IMAGE_SECTION_HEADER *__cdecl _FindPESection(unsigned __int8 *pImageBase, unsigned int rva)
{
  unsigned __int8 *v2; // ecx
  unsigned int v3; // esi
  unsigned int v4; // edx
  _IMAGE_SECTION_HEADER *result; // eax
  unsigned int VirtualAddress; // ecx

  v2 = &pImageBase[*((_DWORD *)pImageBase + 15)];
  v3 = *((unsigned __int16 *)v2 + 3);
  v4 = 0;
  result = (_IMAGE_SECTION_HEADER *)&v2[*((unsigned __int16 *)v2 + 10) + 24];
  if ( *((_WORD *)v2 + 3) == 0 )
    return nullptr;
  while ( 1 )
  {
    VirtualAddress = result->VirtualAddress;
    if ( rva >= VirtualAddress && rva < VirtualAddress + result->Misc.PhysicalAddress )
      break;
    ++v4;
    ++result;
    if ( v4 >= v3 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001DB0
// Name: __IsNonwritableInCurrentImage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _IsNonwritableInCurrentImage(unsigned __int8 *pTarget)
{
  _IMAGE_SECTION_HEADER *PESection; // eax

  return _ValidateImageBase(pImageBase: (unsigned __int8 *)0x10000000)
      && (PESection = _FindPESection(
                        pImageBase: (unsigned __int8 *)0x10000000,
                        rva: (unsigned int)(pTarget - 0x10000000))) != nullptr
      && (PESection->Characteristics & 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001E6C
// Name: __initterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl _initterm(_PVFV *First, _PVFV *Last)
{
  __initterm(First, Last);
}

//------------------------------------------------------------------------------
// Address: 0x10001E72
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl _initterm_e(_PIFV *First, _PIFV *Last)
{
  return __initterm_e(First, Last);
}

//------------------------------------------------------------------------------
// Address: 0x10001E78
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl _amsg_exit(int a1)
{
  return __amsg_exit(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10001E7E
// Name: ___CppXcptFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __CppXcptFilter()
{
  return ___CppXcptFilter();
}

//------------------------------------------------------------------------------
// Address: 0x10001E84
// Name: ___security_init_cookie
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __security_init_cookie()
{
  unsigned int v0; // esi
  DWORD v1; // esi
  DWORD v2; // esi
  DWORD v3; // esi
  uintptr_t v4; // esi
  _LARGE_INTEGER perfctr; // [esp+8h] [ebp-10h] BYREF
  FT systime; // [esp+10h] [ebp-8h] BYREF

  systime.ft_scalar = 0;
  if ( __security_cookie == -1153374642 || (__security_cookie & 0xFFFF0000) == 0 )
  {
    GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: (LPFILETIME)&systime);
    v0 = systime.ft_struct.dwLowDateTime ^ systime.ft_struct.dwHighDateTime;
    v1 = GetCurrentProcessId() ^ v0;
    v2 = GetCurrentThreadId() ^ v1;
    v3 = GetTickCount() ^ v2;
    QueryPerformanceCounter(lpPerformanceCount: &perfctr);
    v4 = perfctr.LowPart ^ perfctr.HighPart ^ v3;
    if ( v4 == -1153374642 )
    {
      v4 = -1153374641;
    }
    else if ( (v4 & 0xFFFF0000) == 0 )
    {
      v4 |= v4 << 16;
    }
    __security_cookie = v4;
    __security_cookie_complement = ~v4;
  }
  else
  {
    __security_cookie_complement = ~__security_cookie;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001F18
// Name: ?terminate@@YAXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl __noreturn terminate()
{
  __imp_?terminate@@YAXXZ();
}

//------------------------------------------------------------------------------
// Address: 0x10001F24
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(unsigned int cookie)
{
  if ( cookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x10001F40
// Name: ___report_gsfailure
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __report_gsfailure()
{
  unsigned int v0; // eax
  unsigned int v1; // edx
  unsigned int v2; // ecx
  unsigned int v3; // ebx
  unsigned int v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // kr00_4
  HANDLE CurrentProcess; // eax
  unsigned int vars0; // [esp+328h] [ebp+0h]
  void *retaddr; // [esp+32Ch] [ebp+4h]
  char v10; // [esp+330h] [ebp+8h] BYREF

  GS_ContextRecord.Eax = v0;
  GS_ContextRecord.Ecx = v2;
  GS_ContextRecord.Edx = v1;
  GS_ContextRecord.Ebx = v3;
  GS_ContextRecord.Esi = v5;
  GS_ContextRecord.Edi = v4;
  LOWORD(GS_ContextRecord.SegSs) = __SS__;
  LOWORD(GS_ContextRecord.SegCs) = __CS__;
  LOWORD(GS_ContextRecord.SegDs) = __DS__;
  LOWORD(GS_ContextRecord.SegEs) = __ES__;
  LOWORD(GS_ContextRecord.SegFs) = __FS__;
  LOWORD(GS_ContextRecord.SegGs) = __GS__;
  v6 = __readeflags();
  GS_ContextRecord.EFlags = v6;
  GS_ContextRecord.Ebp = vars0;
  GS_ContextRecord.Eip = (unsigned int)retaddr;
  GS_ContextRecord.Esp = (unsigned int)&v10;
  GS_ContextRecord.ContextFlags = 65537;
  GS_ExceptionRecord.ExceptionAddress = retaddr;
  GS_ExceptionRecord.ExceptionCode = -1073740791;
  GS_ExceptionRecord.ExceptionFlags = 1;
  DebuggerWasPresent = IsDebuggerPresent();
  _crt_debugger_hook(a1: 1);
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  UnhandledExceptionFilter(ExceptionInfo: &GS_ExceptionPointers);
  if ( DebuggerWasPresent == 0 )
    _crt_debugger_hook(a1: 1);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000409);
}

//------------------------------------------------------------------------------
// Address: 0x10002044
// Name: __crt_debugger_hook
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl _crt_debugger_hook(int a1)
{
  return __crt_debugger_hook(a1);
}

//------------------------------------------------------------------------------
// Address: 0x100020B0
// Name: _dynamic_initializer_for__g_SingletonDtWrapper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SingletonDtWrapper__()
{
  deci3_lib::dtlib::dtlib(this: &g_SingletonDtWrapper.m_dtlib);
  return atexit(func: dynamic_atexit_destructor_for__g_SingletonDtWrapper__);
}

//------------------------------------------------------------------------------
// Address: 0x100020D0
// Name: _dynamic_atexit_destructor_for__g_SingletonDtWrapper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SingletonDtWrapper__()
{
  deci3_lib::dtlib::~dtlib(this: &g_SingletonDtWrapper.m_dtlib);
}
