// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/pmelib.cpp
// Functions: 12
// ============================================================

#include "tier0\pmelib.h"

//------------------------------------------------------------------------------
// Address: 0x1000BA50
// Name: private: void ia32detect::init2(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ia32detect::init2(ia32detect *this, unsigned __int8 count)
{
  ia32detect *v2; // esi
  int v3; // edi
  int i; // ecx
  unsigned int v10; // edx
  unsigned int v11; // eax
  int j; // ecx
  unsigned int v13; // edx
  unsigned int v14; // eax
  int k; // ecx
  unsigned int v16; // edx
  unsigned int v17; // eax
  int m; // ecx
  unsigned int v19; // edx
  unsigned int v20; // eax
  int n; // ecx
  int v22; // ecx
  int ii; // eax
  bool c[256]; // [esp+8h] [ebp-114h] BYREF
  ia32detect *v25; // [esp+108h] [ebp-14h]
  unsigned int d[4]; // [esp+10Ch] [ebp-10h]

  v2 = this;
  v25 = this;
  memset(dst: (unsigned __int8 *)c, value: 0, count: sizeof(c));
  v3 = 0;
  if ( count != 0 )
  {
    do
    {
      _EAX = 2;
      __asm { cpuid }
      d[0] = _EAX;
      d[1] = _EBX;
      d[2] = _ECX;
      d[3] = _EDX;
      if ( v3 == 0 )
      {
        _EAX &= 0xFFFFFF00;
        d[0] = _EAX;
      }
      if ( _EAX >= 0 )
      {
        for ( i = 0; i < 32; i += 8 )
        {
          v10 = (unsigned int)_EAX >> i;
          c[(unsigned __int8)v10] = true;
        }
      }
      v11 = d[1];
      if ( (d[1] & 0x80000000) == 0 )
      {
        for ( j = 0; j < 32; j += 8 )
        {
          v13 = v11 >> j;
          c[(unsigned __int8)v13] = true;
        }
      }
      v14 = d[2];
      if ( (d[2] & 0x80000000) == 0 )
      {
        for ( k = 0; k < 32; k += 8 )
        {
          v16 = v14 >> k;
          c[(unsigned __int8)v16] = true;
        }
      }
      v17 = d[3];
      if ( (d[3] & 0x80000000) == 0 )
      {
        for ( m = 0; m < 32; m += 8 )
        {
          v19 = v17 >> m;
          c[(unsigned __int8)v19] = true;
        }
      }
      ++v3;
    }
    while ( v3 < count );
    v2 = v25;
  }
  v20 = 0;
  for ( n = 0; n < 256; n += 4 )
  {
    if ( c[n] )
      ++v20;
    if ( c[n + 1] )
      ++v20;
    if ( c[n + 2] )
      ++v20;
    if ( c[n + 3] )
      ++v20;
  }
  v2->cache = (unsigned __int8 *)operator new[](cb: v20);
  v22 = 0;
  for ( ii = 1; ii < 256; ++ii )
  {
    if ( c[ii] )
      v2->cache[v22++] = ii;
  }
  v2->cache[v22] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000BBD0
// Name: public: long PME::ReadMSR(unsigned int,__int64 __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall PME::ReadMSR(PME *this, unsigned int dw_reg, __int64 *pi64_value)
{
  HRESULT result; // eax

  if ( !this->bDriverOpen )
    return -6;
  result = DeviceIoControl(
             hDevice: this->hFile,
             dwIoControlCode: 0x9C406404,
             lpInBuffer: &dw_reg,
             nInBufferSize: 4u,
             lpOutBuffer: pi64_value,
             nOutBufferSize: 8u,
             lpBytesReturned: (LPDWORD)&pi64_value,
             lpOverlapped: nullptr);
  if ( result == 0 && pi64_value != (__int64 *)8 )
    return -8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BC20
// Name: public: long PME::WriteMSR(unsigned int,unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall PME::WriteMSR(PME *this, unsigned int dw_reg, const unsigned __int64 *i64_value)
{
  HRESULT result; // eax
  void *hFile; // ecx
  unsigned int v5; // eax
  unsigned int dw_buffer[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( !this->bDriverOpen )
    return -6;
  hFile = this->hFile;
  dw_buffer[0] = dw_reg;
  v5 = *((_DWORD *)i64_value + 1);
  dw_buffer[1] = *(_DWORD *)i64_value;
  dw_buffer[2] = v5;
  result = DeviceIoControl(
             hDevice: hFile,
             dwIoControlCode: 0x9C406400,
             lpInBuffer: dw_buffer,
             nInBufferSize: 0xCu,
             lpOutBuffer: nullptr,
             nOutBufferSize: 0,
             lpBytesReturned: &dw_reg,
             lpOverlapped: nullptr);
  if ( result == 0 && dw_reg != 0 )
    return -8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BCA0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::erase(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::erase(std::string *this, unsigned int _Off, unsigned int _Count)
{
  unsigned int Mysize; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  unsigned int Myres; // edx
  std::string *Ptr; // ebx
  std::string *v9; // edx
  unsigned int v10; // eax
  bool v11; // cf

  Mysize = this->_Mysize;
  if ( Mysize < _Off )
    std::_Xout_of_range(_Message: "invalid string position");
  v5 = _Count;
  v6 = Mysize - _Off;
  if ( v6 < _Count )
    v5 = v6;
  if ( v5 != 0 )
  {
    Myres = this->_Myres;
    if ( Myres < 0x10 )
      Ptr = this;
    else
      Ptr = (std::string *)this->_Bx._Ptr;
    if ( Myres < 0x10 )
      v9 = this;
    else
      v9 = (std::string *)this->_Bx._Ptr;
    memmove(
      dst: (unsigned __int8 *)&v9->_Bx._Buf[_Off],
      src: (unsigned __int8 *)&Ptr->_Bx._Buf[_Off + v5],
      count: v6 - v5);
    v10 = this->_Mysize - v5;
    v11 = this->_Myres < 0x10;
    this->_Mysize = v10;
    if ( !v11 )
    {
      this->_Bx._Ptr[v10] = 0;
      return this;
    }
    this->_Bx._Buf[v10] = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000BD30
// Name: public: char __near * std::allocator<char>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall std::allocator<char>::allocate(std::allocator<char> *this, unsigned int _Count)
{
  char *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 )
  {
    result = (char *)operator new(size: _Count);
    if ( result == nullptr )
    {
      _Count = 0;
      std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
      pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BD80
// Name: public: long PME::Init(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall PME::Init(PME *this)
{
  HANDLE FileA; // eax
  bool v4; // zf
  _OSVERSIONINFOA OS; // [esp+4h] [ebp-9Ch] BYREF
  unsigned __int64 i64_value; // [esp+98h] [ebp-8h] BYREF

  if ( this->bDriverOpen )
    return -5;
  if ( this->vendor > (unsigned int)AMD )
  {
    this->bDriverOpen = false;
    return -1;
  }
  else
  {
    OS.dwOSVersionInfoSize = 148;
    GetVersionExA(lpVersionInformation: &OS);
    if ( OS.dwPlatformId == 2 )
      FileA = CreateFileA(
                lpFileName: "\\\\.\\GDPERF",
                dwDesiredAccess: 0x80000000,
                dwShareMode: 0,
                lpSecurityAttributes: nullptr,
                dwCreationDisposition: 3u,
                dwFlagsAndAttributes: 0x80u,
                hTemplateFile: nullptr);
    else
      FileA = CreateFileA(
                lpFileName: "\\\\.\\GDPERF.VXD",
                dwDesiredAccess: 0x80000000,
                dwShareMode: 0,
                lpSecurityAttributes: nullptr,
                dwCreationDisposition: 3u,
                dwFlagsAndAttributes: 0x80u,
                hTemplateFile: nullptr);
    this->hFile = FileA;
    if ( FileA == (HANDLE)-1 )
    {
      return -4;
    }
    else
    {
      v4 = this->vendor == INTEL;
      this->bDriverOpen = true;
      if ( v4 && (*(_DWORD *)&this->version & 0xF00) == 0x600 )
      {
        i64_value = 4653177;
        PME::WriteMSR(this, dw_reg: 0x186u, &i64_value);
        if ( this->bDriverOpen && (*(_DWORD *)&this->version & 0xF00) == 0x600 )
        {
          i64_value = 4653177;
          PME::WriteMSR(this, dw_reg: 0x187u, &i64_value);
        }
      }
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BE80
// Name: public: void std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::_Copy(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::string::_Copy(std::string *this, unsigned int _Newsize, unsigned int _Oldlen)
{
  std::string *v3; // esi
  unsigned int v4; // edi
  unsigned int Myres; // ebx
  unsigned int v6; // ecx
  char *v7; // ebx
  unsigned int v8; // ecx
  unsigned __int8 *Ptr; // eax
  int v10; // [esp+0h] [ebp-24h] BYREF
  char *_Ptr; // [esp+Ch] [ebp-18h]
  std::string *v12; // [esp+10h] [ebp-14h]
  int *v13; // [esp+14h] [ebp-10h]
  int v14; // [esp+20h] [ebp-4h]

  v13 = &v10;
  v3 = this;
  v12 = this;
  v4 = _Newsize | 0xF;
  if ( (_Newsize | 0xF) == 0xFFFFFFFF )
  {
    v4 = _Newsize;
  }
  else
  {
    Myres = this->_Myres;
    v6 = Myres >> 1;
    if ( Myres >> 1 > v4 / 3 )
    {
      v4 = v6 + Myres;
      if ( Myres > -2 - v6 )
        v4 = -2;
    }
  }
  v14 = 0;
  v7 = std::allocator<char>::allocate(this: &v3->_Alval, _Count: v4 + 1);
  _Ptr = v7;
  v14 = -1;
  v8 = _Oldlen;
  if ( _Oldlen != 0 )
  {
    if ( v3->_Myres < 0x10 )
      Ptr = (unsigned __int8 *)v3;
    else
      Ptr = (unsigned __int8 *)v3->_Bx._Ptr;
    memcpy(dst: (unsigned __int8 *)v7, src: Ptr, count: _Oldlen);
    v8 = _Oldlen;
  }
  if ( v3->_Myres >= 0x10 )
  {
    operator delete(p: v3->_Bx._Ptr);
    v8 = _Oldlen;
  }
  v3->_Bx._Buf[0] = 0;
  v3->_Bx._Ptr = v7;
  v3->_Myres = v4;
  v3->_Mysize = v8;
  if ( v4 >= 0x10 )
    v3 = (std::string *)v7;
  v3->_Bx._Buf[v8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000BFC0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::assign(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::assign(
        std::string *this,
        const std::string *_Right,
        unsigned int _Roff,
        unsigned int _Count)
{
  const std::string *Ptr; // ecx
  unsigned int Mysize; // edi
  unsigned int v7; // edi
  unsigned int Myres; // eax
  std::string *v10; // eax
  bool v11; // cf

  Ptr = _Right;
  Mysize = _Right->_Mysize;
  if ( Mysize < _Roff )
    std::_Xout_of_range(_Message: "invalid string position");
  v7 = Mysize - _Roff;
  if ( _Count < v7 )
    v7 = _Count;
  if ( this == _Right )
  {
    std::string::erase(this, _Off: _Roff + v7, _Count: 0xFFFFFFFF);
    std::string::erase(this, _Off: 0, _Count: _Roff);
    return this;
  }
  if ( v7 == -1 )
    std::_Xlength_error(_Message: "string too long");
  Myres = this->_Myres;
  if ( Myres < v7 )
  {
    std::string::_Copy(this, _Newsize: v7, _Oldlen: this->_Mysize);
    Ptr = _Right;
    if ( v7 == 0 )
      return this;
LABEL_11:
    if ( Ptr->_Myres >= 0x10 )
      Ptr = (const std::string *)Ptr->_Bx._Ptr;
    if ( this->_Myres < 0x10 )
      v10 = this;
    else
      v10 = (std::string *)this->_Bx._Ptr;
    memcpy(dst: (unsigned __int8 *)v10, src: (unsigned __int8 *)&Ptr->_Bx._Buf[_Roff], count: v7);
    v11 = this->_Myres < 0x10;
    this->_Mysize = v7;
    if ( !v11 )
    {
      this->_Bx._Ptr[v7] = 0;
      return this;
    }
    this->_Bx._Buf[v7] = 0;
    return this;
  }
  if ( v7 != 0 )
    goto LABEL_11;
  this->_Mysize = 0;
  if ( Myres < 0x10 )
    this->_Bx._Buf[0] = 0;
  else
    *this->_Bx._Ptr = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000C0B0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::assign(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::assign(std::string *this, char *_Ptr, unsigned int _Count)
{
  unsigned int Myres; // ecx
  std::string *v5; // eax
  std::string *v6; // eax
  unsigned int v8; // eax
  std::string *Ptr; // eax
  bool v10; // cf

  if ( _Ptr != nullptr )
  {
    Myres = this->_Myres;
    v5 = Myres < 0x10 ? this : (std::string *)this->_Bx._Ptr;
    if ( _Ptr >= (char *)v5 )
    {
      v6 = Myres < 0x10 ? this : (std::string *)this->_Bx._Ptr;
      if ( (char *)v6 + this->_Mysize > _Ptr )
      {
        if ( Myres < 0x10 )
          return std::string::assign(this, _Right: this, _Roff: _Ptr - (char *)this, _Count);
        else
          return std::string::assign(this, _Right: this, _Roff: _Ptr - this->_Bx._Ptr, _Count);
      }
    }
  }
  if ( _Count == -1 )
    std::_Xlength_error(_Message: "string too long");
  v8 = this->_Myres;
  if ( v8 < _Count )
  {
    std::string::_Copy(this, _Newsize: _Count, _Oldlen: this->_Mysize);
    if ( _Count == 0 )
      return this;
LABEL_17:
    if ( this->_Myres < 0x10 )
      Ptr = this;
    else
      Ptr = (std::string *)this->_Bx._Ptr;
    memcpy(dst: (unsigned __int8 *)Ptr, src: (unsigned __int8 *)_Ptr, count: _Count);
    v10 = this->_Myres < 0x10;
    this->_Mysize = _Count;
    if ( !v10 )
    {
      this->_Bx._Ptr[_Count] = 0;
      return this;
    }
    this->_Bx._Buf[_Count] = 0;
    return this;
  }
  if ( _Count != 0 )
    goto LABEL_17;
  this->_Mysize = 0;
  if ( v8 < 0x10 )
    this->_Bx._Buf[0] = 0;
  else
    *this->_Bx._Ptr = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000C1B0
// Name: private: void ia32detect::init0x80000000(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ia32detect::init0x80000000(ia32detect *this)
{
  char *v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edi
  char *v10; // esi
  unsigned int *d; // [esp+Ch] [ebp-Ch]
  unsigned int i; // [esp+10h] [ebp-8h]
  unsigned int m; // [esp+14h] [ebp-4h]

  _EAX = 0x80000000;
  __asm { cpuid }
  m = _EAX;
  if ( _EAX < 0 )
  {
    v6 = (char *)operator new[](cb: 16 * _EAX);
    v7 = m;
    v8 = -2147483647;
    d = (unsigned int *)v6;
    for ( i = -2147483647; v8 <= m; i = v8 )
    {
      _EAX = i;
      v10 = &v6[16 * v8 - 16];
      __asm { cpuid }
      *(_DWORD *)v10 = _EAX;
      *((_DWORD *)v10 + 1) = _EBX;
      *((_DWORD *)v10 + 2) = _ECX;
      *((_DWORD *)v10 + 3) = _EDX;
      v7 = m;
      v6 = (char *)d;
      ++v8;
    }
    if ( v7 >= 0x80000002 )
      std::string::assign(this: &this->brand, _Ptr: v6 + 16, _Count: strlen(v6 + 16));
    operator delete[](p: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C270
// Name: public: ia32detect::ia32detect(void)
// Source: json
//------------------------------------------------------------------------------
ia32detect *__thiscall ia32detect::ia32detect(ia32detect *this)
{
  unsigned int v7; // esi
  unsigned int *v9; // esi
  unsigned int *v14; // eax
  unsigned int Myres; // esi
  ia32detect *Ptr; // eax
  ia32detect *v18; // eax
  char _Ptr[4]; // [esp+Ch] [ebp-20h] BYREF
  int v20; // [esp+10h] [ebp-1Ch]
  int v21; // [esp+14h] [ebp-18h]
  char v22; // [esp+18h] [ebp-14h]
  unsigned int *t; // [esp+1Ch] [ebp-10h]
  unsigned int *d; // [esp+20h] [ebp-Ch]
  unsigned int i; // [esp+24h] [ebp-8h]
  unsigned int v26; // [esp+28h] [ebp-4h]

  this->vendor_name._Myres = 15;
  this->vendor_name._Mysize = 0;
  this->vendor_name._Bx._Buf[0] = 0;
  this->brand._Myres = 15;
  this->brand._Mysize = 0;
  this->brand._Bx._Buf[0] = 0;
  this->cache = nullptr;
  v22 = 0;
  _EAX = 0;
  __asm { cpuid }
  v26 = _EAX;
  *(_DWORD *)_Ptr = _EBX;
  v20 = _EDX;
  v21 = _ECX;
  std::string::assign(this: &this->vendor_name, _Ptr, _Count: strlen(_Ptr));
  v7 = v26;
  d = (unsigned int *)operator new[](cb: 16 * v26);
  i = 1;
  if ( v7 != 0 )
  {
    do
    {
      t = &d[4 * i - 4];
      _EAX = i;
      v9 = t;
      __asm { cpuid }
      *t = _EAX;
      v9[1] = _EBX;
      v9[2] = _ECX;
      v9[3] = _EDX;
      ++i;
    }
    while ( i <= v26 );
    if ( v26 != 0 )
    {
      v14 = d;
      this->version = (ia32detect::version_t)*d;
      this->misc = (ia32detect::misc_t)v14[1];
      this->feature = (ia32detect::feature_t)v14[3];
    }
  }
  if ( v26 >= 2 )
    ia32detect::init2(this, count: *((_BYTE *)d + 16));
  operator delete[](p: d);
  ia32detect::init0x80000000(this);
  Myres = this->vendor_name._Myres;
  if ( Myres < 0x10 )
    Ptr = this;
  else
    Ptr = (ia32detect *)this->vendor_name._Bx._Ptr;
  if ( strcmp(Ptr->vendor_name._Bx._Buf, "GenuineIntel") == 0 )
  {
    this->vendor = INTEL;
    return this;
  }
  else
  {
    if ( Myres < 0x10 )
      v18 = this;
    else
      v18 = (ia32detect *)this->vendor_name._Bx._Ptr;
    if ( strcmp(v18->vendor_name._Bx._Buf, "AuthenticAMD") == 0 )
      this->vendor = AMD;
    else
      this->vendor = UNKNOWN_VENDOR;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C410
// Name: public: static class PME __near * PME::Instance(void)
// Source: json
//------------------------------------------------------------------------------
PME *__cdecl PME::Instance()
{
  PME *result; // eax
  ia32detect *v1; // eax
  ia32detect *v2; // esi

  result = PME::_singleton;
  if ( PME::_singleton == nullptr )
  {
    v1 = (ia32detect *)operator new(size: 0x60u);
    v2 = v1;
    if ( v1 != nullptr )
    {
      ia32detect::ia32detect(this: v1);
      v2[1].vendor_name._Bx._Ptr = nullptr;
      v2[1].vendor_name._Bx._Buf[4] = 0;
      *(_QWORD *)&v2[1].vendor_name._Bx._Alias[12] = 0;
      PME::Init(this: (PME *)v2);
      PME::_singleton = (PME *)v2;
      return (PME *)v2;
    }
    else
    {
      PME::_singleton = nullptr;
      return nullptr;
    }
  }
  return result;
}

// ============================================================
// Overlay from tier0_s (Missing functions)
// ============================================================
namespace tier0_s {

//------------------------------------------------------------------------------
// Address: 0x3F006740
// Name: public: ia32detect::ia32detect(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall ia32detect::ia32detect(ia32detect *this, ia32detect *thisa)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F006920
// Name: private: void ia32detect::init2(unsigned char)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge ia32detect::init2(
        ia32detect *this@<ecx>,
        int a2@<eax>,
        unsigned __int8 count,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  _BYTE retaddr[8]; // [esp+11Ch] [ebp+0h]

  *(_BYTE *)(a2 - 2092300935) += a2;
  MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x3F006AB0
// Name: private: void ia32detect::init0x80000000(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ia32detect::init0x80000000(
        ia32detect *this@<ecx>,
        int _EAX@<eax>,
        unsigned int a3@<ebx>,
        int a4@<ebp>,
        int a5@<edi>,
        int a6@<esi>,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  int v12; // eax
  int v13; // esi

  __asm { aas }
  dword_3F041DC0 = (int)this;
  if ( (a3 & 7) != 0 || a3 < 8 )
    __debugbreak();
  *(_DWORD *)(a5 + 8) = a3;
  _InterlockedExchange((volatile __int32 *)a5, 0);
  v12 = *(_DWORD *)(a4 + 8);
  *(_DWORD *)(a5 + 12) = 0;
  *(_DWORD *)(v12 + 4 * a6) = a10;
  v13 = a6 + 1;
  if ( a11 + 1 >= 193 )
  {
    if ( v13 < 256 && v13 + 1 < 257 )
    {
      if ( (v13 + 1) % 32 == 1 )
      {
        if ( (dword_3F0A360C & 1) == 0 )
        {
          dword_3F0A360C |= 1u;
          JUMPOUT(0x3F006B6D);
        }
        JUMPOUT(0x3F006B8F);
      }
      JUMPOUT(0x3F006C07);
    }
    JUMPOUT(0x3F006C1F);
  }
  JUMPOUT(0x3F006A20);
}

//------------------------------------------------------------------------------
// Address: 0x3F006B70
// Name: protected: PME::PME(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PME::PME(PME *this)
{
  JUMPOUT(0x3F006B72);
}

//------------------------------------------------------------------------------
// Address: 0x3F006BD0
// Name: public: ia32detect::~ia32detect(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ia32detect::~ia32detect(
        ia32detect *this@<ecx>,
        unsigned int a2@<ebx>,
        _DWORD *a3@<edi>,
        int a4@<esi>,
        ia32detect *thisa,
        int a6,
        int a7,
        int a8,
        int a9)
{
  int v9; // [esp+Ch] [ebp+Ch]

  dword_3F041DB8 = (int)this;
  if ( (a2 & 7) != 0 || a2 < 8 )
    __debugbreak();
  *(_DWORD *)(a4 + 8) = a2;
  _InterlockedExchange((volatile __int32 *)a4, 0);
  v9 = a7 + 1;
  *(_DWORD *)(a4 + 12) = 0;
  *a3 = a8;
  if ( a9 + 1 >= 257 )
  {
    if ( v9 != 38 )
      ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: "Assertion Failed: iCurPool == NUM_POOLS",
        a2: 0,
        a3: ".\\memstd.cpp",
        a4: 909,
        a5: &unk_3F041A49,
        a6: 0);
    JUMPOUT(0x3F006C58);
  }
  JUMPOUT(0x3F006B3B);
}

//------------------------------------------------------------------------------
// Address: 0x3F006CD0
// Name: public: long PME::Init(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int32 __userpurge PME::Init@<eax>(
        PME *this@<ecx>,
        unsigned __int8 a2@<al>,
        unsigned __int16 a3@<dx>,
        int a4@<esi>,
        int a5)
{
  __outbyte(a3, a2);
  *(_BYTE *)(a4 - 117) += a2;
  return __indword(0x5Du);
}

//------------------------------------------------------------------------------
// Address: 0x3F006E10
// Name: public: long PME::WriteMSR(unsigned int,unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall PME::WriteMSR(PME *this)
{
  unsigned int dw_ret_len; // [esp+0h] [ebp-14h]
  int dw_buffer; // [esp+4h] [ebp-10h]
  int dw_buffer_4; // [esp+8h] [ebp-Ch]
  int dw_buffer_8; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  Msg(
    a1: (int)"Pool %4u: allocated:%6i free:%6i committed:%6i (size:%5u kb)\n",
    dw_ret_len,
    dw_buffer,
    dw_buffer_4,
    dw_buffer_8,
    v7);
  JUMPOUT(0x3F006E6A);
}

//------------------------------------------------------------------------------
// Address: 0x3F006E70
// Name: public: std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::~basic_string<char,struct std::char_traits<char>,class std::allocator<char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall std::string::~string(
        std::string *this@<ecx>,
        unsigned int a2@<ebx>,
        int a3,
        int a4,
        int a5,
        unsigned int a6,
        int a7)
{
  if ( a2 > 0x6400000 )
  {
    Msg(a1: (int)"Totals: blocks:%u Committed:%u MB Allocated:%u MB\n", a7, a2 >> 20, a6 >> 20);
    JUMPOUT(0x3F006E96);
  }
  JUMPOUT(0x3F006E9D);
}

//------------------------------------------------------------------------------
// Address: 0x3F006EA0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::assign(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
std::string *__thiscall std::string::assign(std::string *this)
{
  int v2; // [esp-1Ch] [ebp-1Ch]
  int v3; // [esp-18h] [ebp-18h]
  int v4; // [esp-14h] [ebp-14h]

  MEMORY[0x2AC1BEB1](a1: this);
  return (std::string *)Msg(a1: (int)"Totals: blocks:%u Committed:%u kb Allocated:%u kb\n", v2, v3, v4);
}

//------------------------------------------------------------------------------
// Address: 0x3F006F80
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::assign(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall std::string::assign@<al>(std::string *this@<ecx>, char a2@<bl>)
{
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F007050
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::erase(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge std::string::erase(
        std::string *this@<ecx>,
        volatile signed __int32 *a2@<eax>,
        unsigned int _Off,
        unsigned int _Count)
{
  _InterlockedOr(a2, (unsigned int)a2);
  *((_BYTE *)this - 2037700486) += (_BYTE)this;
  _InterlockedOr(a2, (unsigned int)a2);
  *((_BYTE *)this + 1170677880) += (_BYTE)this;
  JUMPOUT(0x3F007063);
}

//------------------------------------------------------------------------------
// Address: 0x3F0070E0
// Name: protected: void std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::_Copy(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __usercall std::string::_Copy(std::string *this@<ecx>, int a2@<ebp>)
{
  *(_DWORD *)(a2 - 16) = this;
  *(_DWORD *)(a2 - 4) = -1;
  sub_3F0043F0((CSmallBlockHeap *)this);
}

//------------------------------------------------------------------------------
// Address: 0x3F011AC0
// Name: public: std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall std::string::string(std::string *this, const char *_Ptr, int a3, int a4)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F012310
// Name: public: struct TimeSums_t __near * std::allocator<struct TimeSums_t>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge std::allocator<TimeSums_t>::allocate(
        std::allocator<TimeSums_t> *this@<ecx>,
        char a2@<zf>,
        int a3@<esi>,
        unsigned int _Count)
{
  int v4; // eax

  if ( a2 )
  {
    if ( *(_DWORD *)(a3 + 8) == 0 )
      ((void (__cdecl *)(errentry *, _DWORD, errentry *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: &errtable[34],
        a2: 0,
        a3: &errtable[9],
        a4: 158,
        a5: &unk_3F041A88,
        a6: 0);
    v4 = *(_DWORD *)(a3 + 8);
    *(_DWORD *)(a3 + 8) = *(_DWORD *)(v4 + 12);
    if ( *(int *)(v4 + 32) <= 0 )
      --*(_DWORD *)(a3 + 20);
  }
  JUMPOUT(0x3F01234E);
}

//------------------------------------------------------------------------------
// Address: 0x3F006C70
// Name: sub_3F006C70
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall sub_3F006C70@<eax>(int a1@<eax>, unsigned int a2@<ecx>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a1 + 2544);
  return a2 >= *(_DWORD *)(v2 + 36) && a2 < *(_DWORD *)(v2 + 40);
}

//------------------------------------------------------------------------------
// Address: 0x3F007110
// Name: sub_3F007110
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F007110(CSmallBlockHeap *a1)
{
  sub_3F0043F0(this: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F007150
// Name: sub_3F007150
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__thiscall sub_3F007150(void *this)
{
  if ( (dword_3F0A3610 & 1) == 0 )
  {
    dword_3F0A3610 |= 1u;
    sub_3F007360(a1: this);
    atexit_0(a1: sub_3F02EEB0);
  }
  return &unk_3F0A1DC8;
}

} // namespace tier0_s
