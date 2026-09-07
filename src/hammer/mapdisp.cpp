// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapdisp.cpp
// Functions: 224
// ============================================================

#include "hammer\mapdisp.h"

//------------------------------------------------------------------------------
// Address: 0x10037BC0
// Name: public: std::basic_istream<char,struct std::char_traits<char>>::sentry::~sentry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::istream::sentry::~sentry(std::istream::sentry *this)
{
  int v1; // eax

  v1 = *(_DWORD *)&this->_Myistr->gap10[*(_DWORD *)(*(_DWORD *)this->_Myistr + 4) + 40];
  if ( v1 != 0 )
    (*(void (__thiscall **)(int, std::istream::sentry *))(*(_DWORD *)v1 + 8))(a1: v1, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100384B0
// Name: public: bool std::basic_istream<char,struct std::char_traits<char>>::_Ipfx(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall std::istream::_Ipfx(std::istream *this, bool _Noskip)
{
  char *v3; // ecx
  std::ostream *v4; // ecx
  int v5; // edx
  const std::locale *v6; // eax
  const std::ctype<char> *v7; // edi
  int i; // eax
  int v10; // eax
  int v11; // [esp+0h] [ebp-24h] BYREF
  int _Meta; // [esp+Ch] [ebp-18h]
  std::istream *v13; // [esp+10h] [ebp-14h]
  int *v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+20h] [ebp-4h]

  v14 = &v11;
  v13 = this;
  v3 = &this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)];
  if ( *((_DWORD *)v3 + 3) == 0 )
  {
    v4 = *((std::ostream **)v3 + 15);
    if ( v4 != nullptr )
      std::ostream::flush(this: v4);
    if ( !_Noskip )
    {
      v5 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
      if ( (*(_DWORD *)&this->gap10[v5 + 4] & 1) != 0 )
      {
        v6 = std::ios_base::getloc(this: (std::ios_base *)&this->gap0[v5], result: (std::locale *)&_Noskip);
        v15 = 0;
        v7 = std::use_facet<std::ctype<char>>(_Loc: v6);
        v15 = -1;
        std::locale::~locale(this: (std::locale *)&_Noskip);
        v15 = 1;
        for ( i = std::streambuf::sgetc(this: *(std::streambuf **)&this->gap10[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)
                                                                             + 40]);
              ;
              i = std::streambuf::snextc(this: *(std::streambuf **)&this->gap10[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)
                                                                              + 40]) )
        {
          _Meta = i;
          if ( i == -1 )
            break;
          if ( (v7->_Ctype._Table[(unsigned __int8)i] & 0x48) == 0 )
            goto LABEL_10;
        }
        std::ios::setstate(
          this: (std::ios *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)],
          _State: 1,
          _Reraise: false);
LABEL_10:
        v15 = -1;
      }
    }
    v3 = &this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)];
    if ( *((_DWORD *)v3 + 3) == 0 )
      return 1;
  }
  v10 = *((_DWORD *)v3 + 3) | 2;
  if ( *((_DWORD *)v3 + 14) == 0 )
    v10 = *((_DWORD *)v3 + 3) | 6;
  std::ios_base::clear(this: (std::ios_base *)v3, _State: v10, _Reraise: false);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100389D0
// Name: public: std::basic_istream<char,struct std::char_traits<char>>::sentry::sentry(class std::basic_istream<char,struct std::char_traits<char>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
std::istream::sentry *__thiscall std::istream::sentry::sentry(
        std::istream::sentry *this,
        std::istream *_Istr,
        bool _Noskip)
{
  int v4; // eax

  this->_Myistr = _Istr;
  v4 = *(_DWORD *)&_Istr->gap10[*(_DWORD *)(*(_DWORD *)_Istr->gap0 + 4) + 40];
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  this->_Ok = std::istream::_Ipfx(this: this->_Myistr, _Noskip);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10038FF0
// Name: public: class std::basic_istream<char,struct std::char_traits<char>> __near & std::basic_istream<char,struct std::char_traits<char>>::read(char __near *,__int64)
// Source: json
//------------------------------------------------------------------------------
std::istream *__thiscall std::istream::read(std::istream *this, char *_Str, __int64 _Count)
{
  int v4; // ecx
  __int64 v5; // rax
  std::ios_base *v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v10; // [esp+0h] [ebp-2Ch] BYREF
  std::istream::sentry _Ok; // [esp+Ch] [ebp-20h]
  int _State; // [esp+14h] [ebp-18h]
  std::istream *v13; // [esp+18h] [ebp-14h]
  int *v14; // [esp+1Ch] [ebp-10h]
  int v15; // [esp+28h] [ebp-4h]

  v14 = &v10;
  v13 = this;
  _State = 0;
  this->_Chcount = 0;
  _Ok._Myistr = this;
  v4 = *(_DWORD *)&this->gap10[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 40];
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  v15 = 0;
  _Ok._Ok = std::istream::_Ipfx(this, _Noskip: true);
  v15 = 1;
  if ( _Ok._Ok )
  {
    LOBYTE(v15) = 2;
    v5 = std::streambuf::sgetn(
           this: (std::streambuf *)*(_DWORD *)&this->gap10[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 40],
           _Ptr: _Str,
           _Count);
    this->_Chcount += v5;
    if ( v5 != _Count )
      _State = 3;
    v15 = 1;
  }
  v6 = (std::ios_base *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)];
  if ( _State != 0 )
  {
    v7 = _State | v6->_Mystate;
    if ( v6[1].__vftable == nullptr )
      LOBYTE(v7) = v7 | 4;
    std::ios_base::clear(this: v6, _State: v7, _Reraise: false);
  }
  v15 = -1;
  v8 = *(_DWORD *)&this->gap10[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 40];
  if ( v8 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10039590
// Name: public: virtual std::basic_istream<char,struct std::char_traits<char>>::~basic_istream<char,struct std::char_traits<char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::istream::~istream<char,std::char_traits<char>>(std::istream *this)
{
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 4) + 4) - 16) = &std::istream::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100397B0
// Name: public: void std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::_Chassign(unsigned int,unsigned int,char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::string::_Chassign(std::string *this, unsigned int _Off, unsigned int _Count, char _Ch)
{
  if ( _Count == 1 )
  {
    if ( this->_Myres >= 0x10 )
      this = (std::string *)this->_Bx._Ptr;
    this->_Bx._Buf[_Off] = _Ch;
  }
  else
  {
    if ( this->_Myres >= 0x10 )
      this = (std::string *)this->_Bx._Ptr;
    memset(dst: (unsigned __int8 *)&this->_Bx._Buf[_Off], value: _Ch, count: _Count);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A070
// Name: public: void std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::_Copy(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1003A2B0
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
// Address: 0x1003A5C0
// Name: public: std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::~basic_string<char,struct std::char_traits<char>,class std::allocator<char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::string::~string(std::string *this)
{
  if ( this->_Myres >= 0x10 )
    operator delete(p: this->_Bx._Ptr);
  this->_Myres = 15;
  this->_Mysize = 0;
  this->_Bx._Buf[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003A5F0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::append(unsigned int,char)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::append(std::string *this, unsigned int _Count, char _Ch)
{
  unsigned int Mysize; // eax
  unsigned int v5; // edi
  unsigned int Myres; // ecx
  bool v7; // cf

  Mysize = this->_Mysize;
  if ( -1 - Mysize <= _Count )
    std::_Xlength_error(_Message: "string too long");
  if ( _Count == 0 )
    return this;
  v5 = Mysize + _Count;
  if ( Mysize + _Count == -1 )
    std::_Xlength_error(_Message: "string too long");
  Myres = this->_Myres;
  if ( Myres < v5 )
  {
    std::string::_Copy(this, _Newsize: Mysize + _Count, _Oldlen: Mysize);
    if ( v5 != 0 )
    {
LABEL_8:
      std::string::_Chassign(this, _Off: this->_Mysize, _Count, _Ch);
      v7 = this->_Myres < 0x10;
      this->_Mysize = v5;
      if ( !v7 )
      {
        this->_Bx._Ptr[v5] = 0;
        return this;
      }
      this->_Bx._Buf[v5] = 0;
    }
    return this;
  }
  if ( v5 != 0 )
    goto LABEL_8;
  this->_Mysize = 0;
  if ( Myres < 0x10 )
    this->_Bx._Buf[0] = 0;
  else
    *this->_Bx._Ptr = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003A6A0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::assign(unsigned int,char)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::assign(std::string *this, unsigned int _Count, char _Ch)
{
  unsigned int Myres; // eax
  std::string *Ptr; // eax
  bool v7; // cf

  if ( _Count == -1 )
    std::_Xlength_error(_Message: "string too long");
  Myres = this->_Myres;
  if ( Myres < _Count )
  {
    std::string::_Copy(this, _Newsize: _Count, _Oldlen: this->_Mysize);
    if ( _Count == 0 )
      return this;
LABEL_5:
    if ( _Count == 1 )
    {
      if ( this->_Myres < 0x10 )
        this->_Bx._Buf[0] = _Ch;
      else
        *this->_Bx._Ptr = _Ch;
    }
    else
    {
      if ( this->_Myres < 0x10 )
        Ptr = this;
      else
        Ptr = (std::string *)this->_Bx._Ptr;
      memset(dst: (unsigned __int8 *)Ptr, value: _Ch, count: _Count);
    }
    v7 = this->_Myres < 0x10;
    this->_Mysize = _Count;
    if ( !v7 )
    {
      this->_Bx._Ptr[_Count] = 0;
      return this;
    }
    this->_Bx._Buf[_Count] = 0;
    return this;
  }
  if ( _Count != 0 )
    goto LABEL_5;
  this->_Mysize = 0;
  if ( Myres < 0x10 )
    this->_Bx._Buf[0] = 0;
  else
    *this->_Bx._Ptr = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003F230
// Name: public: class std::basic_istream<char,struct std::char_traits<char>> __near & std::basic_istream<char,struct std::char_traits<char>>::seekg(class std::fpos<int>)
// Source: json
//------------------------------------------------------------------------------
std::istream *__thiscall std::istream::seekg(std::istream *this, std::fpos<int> _Pos)
{
  int v3; // ecx
  int v4; // ecx
  int v5; // eax
  std::ios_base *v6; // ecx
  char v7; // al
  __int64 v9; // [esp+4h] [ebp-18h] BYREF
  int v10; // [esp+Ch] [ebp-10h]

  v3 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
  if ( (this->gap0[v3 + 12] & 6) == 0 )
  {
    (*(void (__thiscall **)(_DWORD, __int64 *, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int))(**(_DWORD **)&this->gap10[v3 + 40]
                                                                                                + 44))(
      a1: *(_DWORD *)&this->gap10[v3 + 40],
      a2: &v9,
      a3: _Pos._Myoff,
      a4: HIDWORD(_Pos._Myoff),
      a5: _Pos._Fpos,
      a6: HIDWORD(_Pos._Fpos),
      a7: _Pos._Mystate,
      a8: *(&_Pos._Mystate + 1),
      a9: 1);
    if ( v9 + v10 == -1 )
    {
      v4 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
      v5 = *(_DWORD *)&this->gap0[v4 + 12];
      v6 = (std::ios_base *)&this->gap0[v4];
      v7 = v5 | 2;
      if ( v6[1].__vftable == nullptr )
        v7 |= 4u;
      std::ios_base::clear(this: v6, _State: v7, _Reraise: false);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100494D0
// Name: public: int std::basic_istream<char,struct std::char_traits<char>>::peek(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::istream::peek(std::istream *this)
{
  vgui::TreeView *v1; // ecx
  std::streambuf *v2; // eax
  vgui::TreeView *v3; // ecx
  int v5; // [esp+0h] [ebp-E0h] BYREF
  std::istream *thisa; // [esp+Ch] [ebp-D4h]
  int v7; // [esp+B8h] [ebp-28h]
  DmElementHandle_t a; // [esp+BCh] [ebp-24h] BYREF
  int _Meta; // [esp+C0h] [ebp-20h] BYREF
  std::istream::sentry _Ok; // [esp+C4h] [ebp-1Ch] BYREF
  int _State; // [esp+CCh] [ebp-14h]
  int *v12; // [esp+D0h] [ebp-10h]
  int v13; // [esp+DCh] [ebp-4h]

  v12 = &v5;
  thisa = this;
  _State = 0;
  this->_Chcount = 0;
  _Meta = 0;
  std::istream::sentry::sentry(this: &_Ok, _Istr: thisa, _Noskip: true);
  v13 = 0;
  if ( std::ostream::sentry::operator int std::_Bool_struct::*(this: (std::ostream::sentry *)&_Ok) == (int *)-1 )
  {
    _Meta = std::streambuf::underflow(this: v1);
  }
  else
  {
    LOBYTE(v13) = 1;
    v2 = (std::streambuf *)std::ios::rdbuf(this: (CDataModel *)&thisa->gap0[*(_DWORD *)(*(_DWORD *)thisa->gap0 + 4)]);
    _Meta = std::streambuf::sgetc(this: v2);
    a = std::streambuf::underflow(this: v3);
    if ( std::char_traits<char>::eq_int_type(&a, b: (const DmElementHandle_t *)&_Meta) )
      _State |= 1u;
    v13 = 0;
  }
  std::ios::setstate(this: (std::ios *)&thisa->gap0[*(_DWORD *)(*(_DWORD *)thisa->gap0 + 4)], _State, _Reraise: false);
  v7 = _Meta;
  v13 = -1;
  std::istream::sentry::~sentry(this: &_Ok);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10049610
// Name: public: class std::basic_istream<char,struct std::char_traits<char>> __near & std::basic_istream<char,struct std::char_traits<char>>::getline(char __near *,__int64,char)
// Source: json
//------------------------------------------------------------------------------
std::istream *__thiscall std::istream::getline(std::istream *this, char *_Str, __int64 _Count, char _Delim)
{
  std::streambuf *v4; // eax
  vgui::TreeView *v5; // ecx
  std::streambuf *v6; // eax
  std::streambuf *v7; // eax
  int v9; // [esp+0h] [ebp-F4h] BYREF
  int v10; // [esp+Ch] [ebp-E8h]
  std::istream *v11; // [esp+10h] [ebp-E4h]
  std::istream *thisa; // [esp+14h] [ebp-E0h]
  std::istream *v13; // [esp+C8h] [ebp-2Ch]
  DmElementHandle_t a; // [esp+CCh] [ebp-28h] BYREF
  int _Meta; // [esp+D0h] [ebp-24h] BYREF
  int _Metadelim; // [esp+D4h] [ebp-20h]
  std::istream::sentry _Ok; // [esp+D8h] [ebp-1Ch] BYREF
  int _State; // [esp+E0h] [ebp-14h]
  int *v19; // [esp+E4h] [ebp-10h]
  int v20; // [esp+F0h] [ebp-4h]

  v19 = &v9;
  thisa = this;
  _State = 0;
  this->_Chcount = 0;
  std::istream::sentry::sentry(this: &_Ok, _Istr: thisa, _Noskip: true);
  v20 = 0;
  if ( std::ostream::sentry::operator int std::_Bool_struct::*(this: (std::ostream::sentry *)&_Ok) != (int *)-1
    && _Count > 0 )
  {
    _Metadelim = std::char_traits<char>::to_int_type(_Ch: &_Delim);
    LOBYTE(v20) = 1;
    v4 = (std::streambuf *)std::ios::rdbuf(this: (CDataModel *)&thisa->gap0[*(_DWORD *)(*(_DWORD *)thisa->gap0 + 4)]);
    for ( _Meta = std::streambuf::sgetc(this: v4); ; _Meta = std::streambuf::snextc(this: v6) )
    {
      a = std::streambuf::underflow(this: v5);
      if ( std::char_traits<char>::eq_int_type(&a, b: (const DmElementHandle_t *)&_Meta) )
      {
        _State |= 1u;
        goto LABEL_11;
      }
      if ( _Meta == _Metadelim )
      {
        ++thisa->_Chcount;
        v7 = (std::streambuf *)std::ios::rdbuf(this: (CDataModel *)&thisa->gap0[*(_DWORD *)(*(_DWORD *)thisa->gap0 + 4)]);
        std::streambuf::sbumpc(this: v7);
        goto LABEL_11;
      }
      if ( --_Count <= 0 )
        break;
      ++thisa->_Chcount;
      *_Str++ = std::char_traits<char>::to_char_type(&_Meta);
      v6 = (std::streambuf *)std::ios::rdbuf(this: (CDataModel *)&thisa->gap0[*(_DWORD *)(*(_DWORD *)thisa->gap0 + 4)]);
    }
    _State |= 2u;
LABEL_11:
    v20 = 0;
  }
  *_Str = 0;
  v11 = thisa;
  if ( thisa->_Chcount != 0 )
    v10 = _State;
  else
    v10 = _State | 2;
  std::ios::setstate(
    this: (std::ios *)&thisa->gap0[*(_DWORD *)(*(_DWORD *)thisa->gap0 + 4)],
    _State: v10,
    _Reraise: false);
  v13 = thisa;
  v20 = -1;
  std::istream::sentry::~sentry(this: &_Ok);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x10049BB0
// Name: class std::basic_istream<char,struct std::char_traits<char>> __near & std::ws(class std::basic_istream<char,struct std::char_traits<char>> __near &)
// Source: json
//------------------------------------------------------------------------------
std::istream *__cdecl std::ws(std::istream *_Istr)
{
  int v1; // eax
  int v2; // ebx
  int v3; // ecx
  const std::locale *v4; // eax
  const std::ctype<char> *v5; // edi
  int i; // eax
  std::ios_base *v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v11; // [esp+0h] [ebp-30h] BYREF
  std::istream::sentry _Ok; // [esp+Ch] [ebp-24h]
  int _Meta; // [esp+14h] [ebp-1Ch]
  std::locale v14; // [esp+18h] [ebp-18h] BYREF
  int _State; // [esp+1Ch] [ebp-14h]
  int *v16; // [esp+20h] [ebp-10h]
  int v17; // [esp+2Ch] [ebp-4h]

  v16 = &v11;
  v1 = *(_DWORD *)(*(_DWORD *)_Istr->gap0 + 4);
  if ( (*(_DWORD *)&_Istr->gap0[v1 + 12] & 1) == 0 )
  {
    v2 = 0;
    _State = 0;
    _Ok._Myistr = _Istr;
    v3 = *(_DWORD *)&_Istr->gap10[v1 + 40];
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
    v17 = 0;
    _Ok._Ok = std::istream::_Ipfx(this: _Istr, _Noskip: true);
    v17 = 1;
    if ( _Ok._Ok )
    {
      v4 = std::ios_base::getloc(
             this: (std::ios_base *)&_Istr->gap0[*(_DWORD *)(*(_DWORD *)_Istr->gap0 + 4)],
             result: &v14);
      LOBYTE(v17) = 2;
      v5 = std::use_facet<std::ctype<char>>(_Loc: v4);
      LOBYTE(v17) = 1;
      std::locale::~locale(this: &v14);
      LOBYTE(v17) = 3;
      for ( i = std::streambuf::sgetc(this: *(std::streambuf **)&_Istr->gap10[*(_DWORD *)(*(_DWORD *)_Istr->gap0 + 4)
                                                                            + 40]);
            ;
            i = std::streambuf::snextc(this: *(std::streambuf **)&_Istr->gap10[*(_DWORD *)(*(_DWORD *)_Istr->gap0 + 4)
                                                                             + 40]) )
      {
        _Meta = i;
        if ( i == -1 )
          break;
        if ( (v5->_Ctype._Table[(unsigned __int8)i] & 0x48) == 0 )
          goto LABEL_9;
      }
      v2 = 1;
      _State = 1;
LABEL_9:
      v17 = 1;
    }
    v7 = (std::ios_base *)&_Istr->gap0[*(_DWORD *)(*(_DWORD *)_Istr->gap0 + 4)];
    if ( v2 != 0 )
    {
      v8 = v2 | v7->_Mystate;
      if ( v7[1].__vftable == nullptr )
        LOBYTE(v8) = v8 | 4;
      std::ios_base::clear(this: v7, _State: v8, _Reraise: false);
    }
    v17 = -1;
    v9 = *(_DWORD *)&_Ok._Myistr->gap10[*(_DWORD *)(*(_DWORD *)_Ok._Myistr + 4) + 40];
    if ( v9 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 8))(a1: v9);
  }
  return _Istr;
}

//------------------------------------------------------------------------------
// Address: 0x1004A270
// Name: public: class std::basic_istream<char,struct std::char_traits<char>> __near & std::basic_istream<char,struct std::char_traits<char>>::getline(char __near *,__int64)
// Source: json
//------------------------------------------------------------------------------
std::istream *__thiscall std::istream::getline(std::istream *this, char *_Str, __int64 _Count)
{
  std::locale *_Loc; // [esp+0h] [ebp-6Ch]
  char v6; // [esp+Fh] [ebp-5Dh]
  std::locale v7; // [esp+58h] [ebp-14h] BYREF
  std::ctype<char> *v8; // [esp+5Ch] [ebp-10h]
  int v9; // [esp+68h] [ebp-4h]

  _Loc = std::ios_base::getloc(this: (std::ios_base *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)], result: &v7);
  v9 = 0;
  v8 = (std::ctype<char> *)std::use_facet<std::ctype<char>>(_Loc);
  v9 = -1;
  std::locale::~locale(this: &v7);
  v6 = std::ctype<char>::widen(this: v8, _Byte: 10);
  return std::istream::getline(this, _Str, _Count, _Delim: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1004CBD0
// Name: public: class std::basic_istream<char,struct std::char_traits<char>> __near & std::basic_istream<char,struct std::char_traits<char>>::seekg(__int64,int)
// Source: json
//------------------------------------------------------------------------------
std::istream *__thiscall std::istream::seekg(std::istream *this, __int64 _Off, int _Way)
{
  int v4; // ecx
  int v5; // ecx
  int v6; // eax
  std::ios_base *v7; // ecx
  char v8; // al
  __int64 v10; // [esp+4h] [ebp-18h] BYREF
  int v11; // [esp+Ch] [ebp-10h]

  v4 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
  if ( (this->gap0[v4 + 12] & 6) == 0 )
  {
    (*(void (__thiscall **)(_DWORD, __int64 *, _DWORD, _DWORD, int, int))(**(_DWORD **)&this->gap10[v4 + 40] + 40))(
      a1: *(_DWORD *)&this->gap10[v4 + 40],
      a2: &v10,
      a3: _Off,
      a4: HIDWORD(_Off),
      a5: _Way,
      a6: 1);
    if ( v10 + v11 == -1 )
    {
      v5 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
      v6 = *(_DWORD *)&this->gap0[v5 + 12];
      v7 = (std::ios_base *)&this->gap0[v5];
      v8 = v6 | 2;
      if ( v7[1].__vftable == nullptr )
        v8 |= 4u;
      std::ios_base::clear(this: v7, _State: v8, _Reraise: false);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10113070
// Name: public: void CCoreDispInfo::ResetFieldVectors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispInfo::ResetFieldVectors(CCoreDispInfo *this)
{
  int v2; // eax
  int v3; // ebx
  int v4; // ecx
  unsigned int v5; // edi
  CoreDispVert_t *m_pVerts; // eax
  CoreDispVert_t *v7; // eax
  int v8; // eax
  CoreDispVert_t *v9; // eax
  CoreDispVert_t *v10; // eax
  int v11; // ecx
  int v12; // ebx
  CoreDispVert_t *v13; // eax
  int i; // [esp+0h] [ebp-4h]

  v2 = 0;
  v3 = ((1 << this->m_Power) + 1) * ((1 << this->m_Power) + 1);
  if ( v3 >= 4 )
  {
    v4 = 0;
    v5 = ((unsigned int)(v3 - 4) >> 2) + 1;
    i = 4 * v5;
    do
    {
      m_pVerts = this->m_pVerts;
      m_pVerts[v4].m_FieldVector.x = 0.0;
      m_pVerts[v4].m_FieldVector.y = 0.0;
      m_pVerts[v4].m_FieldVector.z = 0.0;
      v7 = this->m_pVerts;
      v7[v4 + 1].m_FieldVector.x = 0.0;
      v8 = (int)&v7[v4 + 1];
      *(_DWORD *)(v8 + 4) = 0;
      *(_DWORD *)(v8 + 8) = 0;
      v9 = &this->m_pVerts[v4 + 2];
      v9->m_FieldVector.x = 0.0;
      v9->m_FieldVector.y = 0.0;
      v9->m_FieldVector.z = 0.0;
      v10 = this->m_pVerts;
      v10[v4 + 3].m_FieldVector.x = 0.0;
      v10[v4 + 3].m_FieldVector.y = 0.0;
      v10[v4 + 3].m_FieldVector.z = 0.0;
      v4 += 4;
      --v5;
    }
    while ( v5 != 0 );
    v2 = i;
  }
  if ( v2 < v3 )
  {
    v11 = v2;
    v12 = v3 - v2;
    do
    {
      v13 = this->m_pVerts;
      v13[v11].m_FieldVector.x = 0.0;
      v13[v11].m_FieldVector.y = 0.0;
      v13[v11++].m_FieldVector.z = 0.0;
      --v12;
    }
    while ( v12 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113170
// Name: public: void CCoreDispInfo::ResetSubdivPositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispInfo::ResetSubdivPositions(CCoreDispInfo *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // eax
  unsigned int v5; // esi
  CoreDispVert_t *m_pVerts; // ecx
  CoreDispVert_t *v7; // ecx
  int p_m_SubdivPos; // ecx
  Vector *v9; // ecx
  Vector *v10; // ecx
  int v11; // ecx
  int v12; // edi
  Vector *v13; // eax

  v2 = 0;
  v3 = ((1 << this->m_Power) + 1) * ((1 << this->m_Power) + 1);
  if ( v3 >= 4 )
  {
    v4 = 0;
    v5 = ((unsigned int)(v3 - 4) >> 2) + 1;
    v2 = 4 * v5;
    do
    {
      m_pVerts = this->m_pVerts;
      m_pVerts[v4].m_SubdivPos.x = 0.0;
      m_pVerts[v4].m_SubdivPos.y = 0.0;
      m_pVerts[v4].m_SubdivPos.z = 0.0;
      v7 = this->m_pVerts;
      v7[v4 + 1].m_SubdivPos.x = 0.0;
      p_m_SubdivPos = (int)&v7[v4 + 1].m_SubdivPos;
      *(_DWORD *)(p_m_SubdivPos + 4) = 0;
      *(_DWORD *)(p_m_SubdivPos + 8) = 0;
      v9 = &this->m_pVerts[v4 + 2].m_SubdivPos;
      v9->x = 0.0;
      v9->y = 0.0;
      v9->z = 0.0;
      v10 = &this->m_pVerts[v4 + 3].m_SubdivPos;
      v10->x = 0.0;
      v4 += 4;
      --v5;
      v10->y = 0.0;
      v10->z = 0.0;
    }
    while ( v5 != 0 );
  }
  if ( v2 < v3 )
  {
    v11 = v2;
    v12 = v3 - v2;
    do
    {
      v13 = &this->m_pVerts[v11++].m_SubdivPos;
      --v12;
      v13->x = 0.0;
      v13->y = 0.0;
      v13->z = 0.0;
    }
    while ( v12 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113260
// Name: public: void CCoreDispInfo::ResetSubdivNormals(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispInfo::ResetSubdivNormals(CCoreDispInfo *this)
{
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  int v8; // ebx
  int v9; // edi
  int v10; // eax
  unsigned int v11; // edx
  CoreDispVert_t *m_pVerts; // ecx
  int p_m_SubdivNormal; // ecx
  int v14; // ecx
  int v15; // edi
  Vector normal; // [esp+8h] [ebp-Ch] BYREF

  v2 = this->m_Surf.m_Points[3].y - this->m_Surf.m_Points[0].y;
  v3 = this->m_Surf.m_Points[3].z - this->m_Surf.m_Points[0].z;
  v4 = this->m_Surf.m_Points[1].y - this->m_Surf.m_Points[0].y;
  v5 = this->m_Surf.m_Points[1].z - this->m_Surf.m_Points[0].z;
  v6 = this->m_Surf.m_Points[3].x - this->m_Surf.m_Points[0].x;
  v7 = this->m_Surf.m_Points[1].x - this->m_Surf.m_Points[0].x;
  normal.x = (float)(v2 * v5) - (float)(v3 * v4);
  normal.y = (float)(v3 * v7) - (float)(v6 * v5);
  normal.z = (float)(v6 * v4) - (float)(v2 * v7);
  VectorNormalize(vec: &normal);
  v8 = 0;
  v9 = ((1 << this->m_Power) + 1) * ((1 << this->m_Power) + 1);
  if ( v9 >= 4 )
  {
    v10 = 0;
    v11 = ((unsigned int)(v9 - 4) >> 2) + 1;
    v8 = 4 * v11;
    do
    {
      this->m_pVerts[v10].m_SubdivNormal = normal;
      this->m_pVerts[v10 + 1].m_SubdivNormal = normal;
      m_pVerts = this->m_pVerts;
      m_pVerts[v10 + 2].m_SubdivNormal.x = normal.x;
      p_m_SubdivNormal = (int)&m_pVerts[v10 + 2].m_SubdivNormal;
      *(float *)(p_m_SubdivNormal + 4) = normal.y;
      *(float *)(p_m_SubdivNormal + 8) = normal.z;
      this->m_pVerts[v10 + 3].m_SubdivNormal = normal;
      v10 += 4;
      --v11;
    }
    while ( v11 != 0 );
  }
  if ( v8 < v9 )
  {
    v14 = v8;
    v15 = v9 - v8;
    do
    {
      this->m_pVerts[v14++].m_SubdivNormal = normal;
      --v15;
    }
    while ( v15 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113440
// Name: public: void CCoreDispInfo::ResetFieldDistances(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispInfo::ResetFieldDistances(CCoreDispInfo *this)
{
  int v2; // edi
  int v3; // esi
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // esi

  v2 = 0;
  v3 = ((1 << this->m_Power) + 1) * ((1 << this->m_Power) + 1);
  if ( v3 >= 4 )
  {
    v4 = 0;
    v5 = ((unsigned int)(v3 - 4) >> 2) + 1;
    v2 = 4 * v5;
    do
    {
      this->m_pVerts[v4].m_FieldDistance = 0.0;
      this->m_pVerts[v4 + 1].m_FieldDistance = 0.0;
      this->m_pVerts[v4 + 2].m_FieldDistance = 0.0;
      this->m_pVerts[v4 + 3].m_FieldDistance = 0.0;
      v4 += 4;
      --v5;
    }
    while ( v5 != 0 );
  }
  if ( v2 < v3 )
  {
    v6 = v2;
    v7 = v3 - v2;
    do
    {
      this->m_pVerts[v6++].m_FieldDistance = 0.0;
      --v7;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101134E0
// Name: private: void CMapDisp::ResetNeighbors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::ResetNeighbors(CMapDisp *this)
{
  unsigned __int16 *v2; // eax
  int *v3; // ecx
  int *m_CornerNeighborCounts; // esi
  unsigned __int16 *m_EdgeNeighbors; // edi
  int j; // edx
  int i; // [esp+Ch] [ebp-4h]

  v2 = this->m_CornerNeighbors[0];
  v3 = this->m_CornerNeighborOrientations[0];
  m_CornerNeighborCounts = this->m_CornerNeighborCounts;
  m_EdgeNeighbors = this->m_EdgeNeighbors;
  for ( i = 4; i != 0; --i )
  {
    *m_EdgeNeighbors = -1;
    *(m_CornerNeighborCounts - 4) = -1;
    *m_CornerNeighborCounts = 0;
    for ( j = 4; j != 0; --j )
    {
      *v2 = -1;
      *v3 = -1;
      ++v2;
      ++v3;
    }
    ++m_EdgeNeighbors;
    ++m_CornerNeighborCounts;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113560
// Name: public: bool CMapDisp::InitDispSurfaceData(class CMapFace __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapDisp::InitDispSurfaceData(CMapDisp *this, CMapFace *pFace, bool bGenerateStartPoint)
{
  Vector *Points; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector2D *m_pTextureCoords; // eax
  float v12; // xmm1_4
  Vector *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  Vector2D *v18; // eax
  float v19; // xmm1_4
  Vector *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  Vector2D *v25; // eax
  float v26; // xmm1_4
  Vector *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  Vector2D *v32; // eax
  float v33; // xmm1_4
  CCoreDispSurface *p_m_Surf; // ecx
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm1_4
  float v38; // xmm1_4
  Vector4D *pFacea; // [esp+10h] [ebp+8h]
  Vector4D *bGenerateStartPointa; // [esp+14h] [ebp+Ch]

  if ( pFace->nPoints != 4 )
    return 0;
  this->m_CoreDispInfo.m_Surf.m_PointCount = 4;
  Points = pFace->Points;
  y = Points->y;
  z = Points->z;
  this->m_CoreDispInfo.m_Surf.m_Points[0].x = Points->x;
  this->m_CoreDispInfo.m_Surf.m_Points[0].y = y;
  this->m_CoreDispInfo.m_Surf.m_Points[0].z = z;
  v9 = pFace->plane.normal.y;
  v10 = pFace->plane.normal.z;
  this->m_CoreDispInfo.m_Surf.m_Normals[0].x = pFace->plane.normal.x;
  this->m_CoreDispInfo.m_Surf.m_Normals[0].y = v9;
  this->m_CoreDispInfo.m_Surf.m_Normals[0].z = v10;
  m_pTextureCoords = pFace->m_pTextureCoords;
  v12 = m_pTextureCoords->y;
  this->m_CoreDispInfo.m_Surf.m_TexCoords[0].x = m_pTextureCoords->x;
  this->m_CoreDispInfo.m_Surf.m_TexCoords[0].y = v12;
  v13 = pFace->Points;
  v14 = v13[1].y;
  v15 = v13[1].z;
  this->m_CoreDispInfo.m_Surf.m_Points[1].x = v13[1].x;
  this->m_CoreDispInfo.m_Surf.m_Points[1].y = v14;
  this->m_CoreDispInfo.m_Surf.m_Points[1].z = v15;
  v16 = pFace->plane.normal.y;
  v17 = pFace->plane.normal.z;
  this->m_CoreDispInfo.m_Surf.m_Normals[1].x = pFace->plane.normal.x;
  this->m_CoreDispInfo.m_Surf.m_Normals[1].y = v16;
  this->m_CoreDispInfo.m_Surf.m_Normals[1].z = v17;
  v18 = pFace->m_pTextureCoords;
  v19 = v18[1].y;
  this->m_CoreDispInfo.m_Surf.m_TexCoords[1].x = v18[1].x;
  this->m_CoreDispInfo.m_Surf.m_TexCoords[1].y = v19;
  v20 = pFace->Points;
  v21 = v20[2].y;
  v22 = v20[2].z;
  this->m_CoreDispInfo.m_Surf.m_Points[2].x = v20[2].x;
  this->m_CoreDispInfo.m_Surf.m_Points[2].y = v21;
  this->m_CoreDispInfo.m_Surf.m_Points[2].z = v22;
  v23 = pFace->plane.normal.y;
  v24 = pFace->plane.normal.z;
  this->m_CoreDispInfo.m_Surf.m_Normals[2].x = pFace->plane.normal.x;
  this->m_CoreDispInfo.m_Surf.m_Normals[2].y = v23;
  this->m_CoreDispInfo.m_Surf.m_Normals[2].z = v24;
  v25 = pFace->m_pTextureCoords;
  v26 = v25[2].y;
  this->m_CoreDispInfo.m_Surf.m_TexCoords[2].x = v25[2].x;
  this->m_CoreDispInfo.m_Surf.m_TexCoords[2].y = v26;
  v27 = pFace->Points;
  v28 = v27[3].y;
  v29 = v27[3].z;
  this->m_CoreDispInfo.m_Surf.m_Points[3].x = v27[3].x;
  this->m_CoreDispInfo.m_Surf.m_Points[3].y = v28;
  this->m_CoreDispInfo.m_Surf.m_Points[3].z = v29;
  v30 = pFace->plane.normal.y;
  v31 = pFace->plane.normal.z;
  this->m_CoreDispInfo.m_Surf.m_Normals[3].x = pFace->plane.normal.x;
  this->m_CoreDispInfo.m_Surf.m_Normals[3].y = v30;
  this->m_CoreDispInfo.m_Surf.m_Normals[3].z = v31;
  v32 = pFace->m_pTextureCoords;
  v33 = v32[3].y;
  this->m_CoreDispInfo.m_Surf.m_TexCoords[3].x = v32[3].x;
  this->m_CoreDispInfo.m_Surf.m_TexCoords[3].y = v33;
  if ( this->m_bHasMappingAxes && this->m_CoreDispInfo.m_Surf.m_PointStartIndex == -1 )
  {
    CCoreDispSurface::GeneratePointStartIndexFromMappingAxes(
      this: &this->m_CoreDispInfo.m_Surf,
      sAxis: this->m_MapAxes,
      tAxis: &this->m_MapAxes[1]);
  }
  else
  {
    p_m_Surf = &this->m_CoreDispInfo.m_Surf;
    if ( bGenerateStartPoint )
      CCoreDispSurface::GenerateSurfPointStartIndex(this: p_m_Surf);
    else
      CCoreDispSurface::FindSurfPointStartIndex(this: p_m_Surf);
  }
  CCoreDispSurface::AdjustSurfPointData(this: &this->m_CoreDispInfo.m_Surf);
  bGenerateStartPointa = &pFace->texture.UAxis;
  pFacea = &pFace->texture.VAxis;
  CCoreDispSurface::CalcLuxelCoords(
    this: &this->m_CoreDispInfo.m_Surf,
    nLuxels: pFace->texture.nLightmapScale,
    bAdjust: false,
    vecU: (const Vector *)&pFace->texture.UAxis,
    vecV: (const Vector *)&pFace->texture.VAxis);
  v35 = this->m_CoreDispInfo.m_Surf.m_LuxelCoords[0][0].y;
  pFace->m_pLightmapCoords->x = this->m_CoreDispInfo.m_Surf.m_LuxelCoords[0][0].x;
  pFace->m_pLightmapCoords->y = v35;
  v36 = this->m_CoreDispInfo.m_Surf.m_LuxelCoords[0][1].y;
  pFace->m_pLightmapCoords[1].x = this->m_CoreDispInfo.m_Surf.m_LuxelCoords[0][1].x;
  pFace->m_pLightmapCoords[1].y = v36;
  v37 = this->m_CoreDispInfo.m_Surf.m_LuxelCoords[0][2].y;
  pFace->m_pLightmapCoords[2].x = this->m_CoreDispInfo.m_Surf.m_LuxelCoords[0][2].x;
  pFace->m_pLightmapCoords[2].y = v37;
  v38 = this->m_CoreDispInfo.m_Surf.m_LuxelCoords[0][3].y;
  pFace->m_pLightmapCoords[3].x = this->m_CoreDispInfo.m_Surf.m_LuxelCoords[0][3].x;
  pFace->m_pLightmapCoords[3].y = v38;
  this->m_bHasMappingAxes = false;
  this->m_CoreDispInfo.m_Surf.sAxis.x = pFace->texture.UAxis.x;
  this->m_CoreDispInfo.m_Surf.sAxis.y = bGenerateStartPointa->y;
  this->m_CoreDispInfo.m_Surf.sAxis.z = bGenerateStartPointa->z;
  this->m_CoreDispInfo.m_Surf.tAxis.x = pFacea->x;
  this->m_CoreDispInfo.m_Surf.tAxis.y = pFacea->y;
  this->m_CoreDispInfo.m_Surf.tAxis.z = pFacea->z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10113890
// Name: public: void CMapDisp::InitData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::InitData(CMapDisp *this, int power)
{
  CCoreDispInfo *p_m_CoreDispInfo; // esi

  p_m_CoreDispInfo = &this->m_CoreDispInfo;
  this->m_CoreDispInfo.m_Power = power;
  CCoreDispInfo::ResetFieldVectors(this: &this->m_CoreDispInfo);
  CCoreDispInfo::ResetFieldDistances(this: p_m_CoreDispInfo);
  CCoreDispInfo::ResetSubdivPositions(this: p_m_CoreDispInfo);
  CCoreDispInfo::ResetSubdivNormals(this: p_m_CoreDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x101138C0
// Name: private: bool CMapDisp::ValidLightmapSize(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall CMapDisp::ValidLightmapSize@<al>(CMapDisp *this@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  CMapFace *v5; // eax
  int nLightmapScale; // ecx
  float v8; // xmm3_4
  int v9; // edx
  float *p_z; // esi
  int v11; // edi
  int v12; // edx
  float v13; // xmm0_4
  float v14; // xmm1_4
  __int128 v15; // xmm0
  CFaceEditSheet *m_pFaceEditSheet; // eax
  float x; // [esp-Ch] [ebp-4Ch]
  float y; // [esp-8h] [ebp-48h]
  float z; // [esp-4h] [ebp-44h] BYREF
  _BYTE vecPoints[52]; // [esp+0h] [ebp-40h] OVERLAPPED
  int v22; // [esp+34h] [ebp-Ch]
  void *v23; // [esp+38h] [ebp-8h]
  void *retaddr; // [esp+40h] [ebp+0h]

  v22 = a2;
  v23 = retaddr;
  v5 = (CMapFace *)((int (__thiscall *)(CMapDisp *, int, int))this->GetParent)(a1: this, a2: a3, a3: a4);
  if ( v5 == nullptr )
    return 0;
  nLightmapScale = v5->texture.nLightmapScale;
  x = this->m_CoreDispInfo.m_Surf.m_Points[0].x;
  v8 = 0.0;
  y = this->m_CoreDispInfo.m_Surf.m_Points[0].y;
  z = this->m_CoreDispInfo.m_Surf.m_Points[0].z;
  qmemcpy(vecPoints, &this->m_CoreDispInfo.m_Surf.m_Points[1], 36);
  v9 = 0;
  p_z = &z;
  do
  {
    v11 = v9 + 1;
    v12 = 3 * ((v9 + 1) % 4);
    v13 = *(&x + v12) - *(p_z - 2);
    v14 = (float)((float)((float)(*(&y + v12) - *(p_z - 1)) * (float)(*(&y + v12) - *(p_z - 1)))
                + (float)((float)(*(float *)&vecPoints[4 * v12 - 4] - *p_z)
                        * (float)(*(float *)&vecPoints[4 * v12 - 4] - *p_z)))
        + (float)(v13 * v13);
    v15 = 0;
    *(float *)&v15 = fsqrt(v14);
    *(_OWORD *)&vecPoints[36] = v15;
    if ( *(float *)&v15 > v8 )
      v8 = *(float *)&vecPoints[36];
    v9 = v11;
    p_z += 3;
  }
  while ( v11 < 4 );
  if ( (float)((int)(float)((float)(1.0 / (float)nLightmapScale) * v8) + 1) > 125.0 )
  {
    do
      ++nLightmapScale;
    while ( (float)((int)(float)((float)(1.0 / (float)nLightmapScale) * v8) + 1) > 125.0 );
    v5->texture.nLightmapScale = nLightmapScale;
    CMapFace::CalcTextureCoords(this: v5);
    m_pFaceEditSheet = GetMainWnd()->m_pFaceEditSheet;
    if ( m_pFaceEditSheet != nullptr )
      CFaceEditMaterialPage::UpdateDialogData(this: &m_pFaceEditSheet->m_MaterialPage, pOnlyFace: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10113A80
// Name: private: void CMapDisp::UpSample(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::UpSample(CMapDisp *this, char oldPower)
{
  int v3; // edi
  float *v4; // ebx
  char *v5; // edx
  float *v6; // eax
  int v7; // ecx
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // ecx
  int v12; // edi
  int v13; // eax
  int v14; // ebx
  CoreDispVert_t *m_pVerts; // edx
  int v16; // xmm7_4
  int v17; // xmm1_4
  int v18; // xmm2_4
  int v19; // xmm3_4
  int v20; // xmm4_4
  int v21; // xmm5_4
  int v22; // xmm6_4
  float *v23; // eax
  char *v24; // edx
  int v25; // xmm7_4
  CoreDispVert_t *v26; // edx
  float v27; // xmm2_4
  float v28; // xmm3_4
  CoreDispVert_t *v29; // edx
  float v30; // xmm2_4
  float v31; // xmm3_4
  CoreDispVert_t *v32; // edx
  float v33; // xmm2_4
  float v34; // xmm3_4
  CoreDispVert_t *v35; // edx
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  float *v39; // edx
  CoreDispVert_t *v40; // ebx
  float v41; // xmm2_4
  float v42; // xmm3_4
  CoreDispVert_t *v43; // ebx
  float v44; // xmm2_4
  float v45; // xmm3_4
  CoreDispVert_t *v46; // eax
  float v47; // xmm2_4
  float v48; // xmm3_4
  CoreDispVert_t *v49; // eax
  float v50; // xmm2_4
  float v51; // xmm3_4
  CoreDispVert_t *v52; // eax
  float v53; // xmm2_4
  float v54; // xmm3_4
  bool v55; // zf
  int v56; // edi
  int v57; // eax
  float *v58; // ecx
  float *v59; // edx
  int v60; // eax
  CoreDispVert_t *v61; // edi
  Vector *p_m_SubdivPos; // edi
  Vector *p_m_SubdivNormal; // edi
  CoreDispVert_t *v64; // edx
  Vector *v65; // edi
  Vector *v66; // edi
  CoreDispVert_t *v67; // edi
  Vector *v68; // edi
  float *v69; // ebx
  Vector *v70; // edi
  double v71; // st7
  float *v72; // ebx
  CoreDispVert_t *v73; // edi
  Vector *v74; // ebx
  Vector *v75; // ebx
  float *v76; // edx
  int v77; // eax
  CoreDispVert_t *v78; // ecx
  Vector *v79; // ecx
  Vector *v80; // ecx
  int subNVector; // [esp+Ch] [ebp-D4h]
  int subNVector_4; // [esp+10h] [ebp-D0h]
  int v83; // [esp+24h] [ebp-BCh]
  int v84; // [esp+28h] [ebp-B8h]
  int v85; // [esp+2Ch] [ebp-B4h]
  int v86; // [esp+30h] [ebp-B0h]
  int y; // [esp+34h] [ebp-ACh]
  int v88; // [esp+38h] [ebp-A8h]
  float *v89; // [esp+40h] [ebp-A0h]
  float *v90; // [esp+44h] [ebp-9Ch]
  char *v91; // [esp+48h] [ebp-98h]
  float *v92; // [esp+4Ch] [ebp-94h]
  float *v93; // [esp+50h] [ebp-90h]
  float *v94; // [esp+54h] [ebp-8Ch]
  float *v95; // [esp+58h] [ebp-88h]
  int v96; // [esp+5Ch] [ebp-84h]
  int v97; // [esp+60h] [ebp-80h]
  float *v98; // [esp+64h] [ebp-7Ch]
  int v99; // [esp+68h] [ebp-78h]
  float *v100; // [esp+6Ch] [ebp-74h]
  int v101; // [esp+70h] [ebp-70h]
  int v102; // [esp+74h] [ebp-6Ch]
  float *v103; // [esp+78h] [ebp-68h]
  float *v104; // [esp+7Ch] [ebp-64h]
  int v105; // [esp+80h] [ebp-60h]
  char *v106; // [esp+84h] [ebp-5Ch]
  float *v107; // [esp+88h] [ebp-58h]
  float *v108; // [esp+8Ch] [ebp-54h]
  int v109; // [esp+90h] [ebp-50h]
  int v110; // [esp+94h] [ebp-4Ch]
  int v111; // [esp+94h] [ebp-4Ch]
  int v112; // [esp+98h] [ebp-48h]
  int size; // [esp+9Ch] [ebp-44h]
  int sizea; // [esp+9Ch] [ebp-44h]
  float *v115; // [esp+A0h] [ebp-40h]
  float *v116; // [esp+A0h] [ebp-40h]
  int i; // [esp+A4h] [ebp-3Ch]
  int ia; // [esp+A4h] [ebp-3Ch]
  int v119; // [esp+A8h] [ebp-38h]
  float *v120; // [esp+ACh] [ebp-34h]
  float *v121; // [esp+ACh] [ebp-34h]
  float *dists; // [esp+B0h] [ebp-30h]
  int v123; // [esp+B4h] [ebp-2Ch]
  unsigned int v124; // [esp+B4h] [ebp-2Ch]
  int v125; // [esp+B4h] [ebp-2Ch]
  float *alphas; // [esp+B8h] [ebp-28h]
  float *p; // [esp+BCh] [ebp-24h]
  int v128; // [esp+C0h] [ebp-20h]
  float *v129; // [esp+C0h] [ebp-20h]
  float *v130; // [esp+C0h] [ebp-20h]
  float *v131; // [esp+C4h] [ebp-1Ch]
  float *v132; // [esp+C4h] [ebp-1Ch]
  bool bUp; // [esp+CBh] [ebp-15h]
  char *v134; // [esp+CCh] [ebp-14h]
  int v135; // [esp+D0h] [ebp-10h]
  float *v136; // [esp+D0h] [ebp-10h]
  float *bRight; // [esp+E8h] [ebp+8h]
  float *bRighta; // [esp+E8h] [ebp+8h]
  char bRight_3; // [esp+EBh] [ebp+Bh]

  v3 = (1 << this->m_CoreDispInfo.m_Power) + 1;
  dists = (float *)operator new[](nSize: 4 * v3 * v3);
  alphas = (float *)operator new[](nSize: 4 * v3 * v3);
  p = (float *)operator new[](nSize: 12 * v3 * v3);
  v4 = (float *)operator new[](nSize: 12 * v3 * v3);
  v115 = v4;
  v5 = (char *)operator new[](nSize: 12 * v3 * v3);
  v134 = v5;
  v6 = dists;
  if ( dists != nullptr && alphas != nullptr && p != nullptr && v4 != nullptr && v5 != nullptr )
  {
    v7 = (1 << oldPower) + 1;
    v135 = v7;
    if ( v7 > 0 )
    {
      v8 = 224 * v7;
      v84 = 8 * v3;
      v93 = dists;
      v120 = p + 5;
      v89 = (float *)(v5 + 16);
      v91 = (char *)(v4 + 2);
      v98 = alphas + 1;
      v101 = 0;
      v102 = 0;
      v100 = &alphas[v3];
      v9 = 24 * v3;
      v10 = 3 * v3;
      size = (int)&p[v10 + 5];
      i = (int)&v5[v10 * 4 + 16];
      v119 = (int)&v4[v10 + 2];
      v96 = (int)&v4[v10 + 3];
      v88 = v9;
      v86 = v8;
      v97 = v8;
      v128 = v135;
      do
      {
        if ( v135 > 0 )
        {
          v105 = v101;
          v103 = v100;
          v106 = v91;
          v95 = (float *)v119;
          v94 = v93;
          v90 = v120;
          v108 = v98;
          v92 = (float *)size;
          v107 = (float *)v96;
          v104 = v89;
          v11 = v102;
          v12 = v97;
          v131 = (float *)i;
          v110 = (char *)v4 - (char *)p;
          v112 = v134 - (char *)p;
          v109 = (char *)v4 - v134;
          v83 = (char *)p - (char *)v4;
          v13 = v134 - (char *)v4;
          v14 = v135;
          v85 = v13;
          v123 = v135;
          v99 = (char *)dists - (char *)alphas;
          while ( 1 )
          {
            bRight_3 = 0;
            bUp = false;
            y = v105 / v14;
            *v94 = *(float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_FieldDistance + v11);
            *(v108 - 1) = *(float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_LuxelCoords[4].x + v11);
            m_pVerts = this->m_CoreDispInfo.m_pVerts;
            v16 = *(_DWORD *)((char *)&m_pVerts->m_SubdivNormal.x + v11);
            v17 = *(_DWORD *)((char *)&m_pVerts->m_FieldVector.x + v11);
            v18 = *(_DWORD *)((char *)&m_pVerts->m_FieldVector.y + v11);
            v19 = *(_DWORD *)((char *)&m_pVerts->m_FieldVector.z + v11);
            v20 = *(_DWORD *)((char *)&m_pVerts->m_SubdivPos.x + v11);
            v21 = *(_DWORD *)((char *)&m_pVerts->m_SubdivPos.y + v11);
            v22 = *(_DWORD *)((char *)&m_pVerts->m_SubdivPos.z + v11);
            v23 = v90;
            v24 = (char *)m_pVerts + v11;
            subNVector = v16;
            subNVector_4 = *((_DWORD *)v24 + 5);
            v25 = *((_DWORD *)v24 + 6);
            *((_DWORD *)v90 - 5) = v17;
            *((_DWORD *)v90 - 4) = v18;
            *((_DWORD *)v90 - 3) = v19;
            *((_DWORD *)v106 - 2) = v20;
            *((_DWORD *)v106 - 1) = v21;
            *(_DWORD *)v106 = v22;
            *((_DWORD *)v104 - 4) = subNVector;
            *((_DWORD *)v104 - 3) = subNVector_4;
            *((_DWORD *)v104 - 2) = v25;
            if ( v105 % v14 + 1 < v14 )
            {
              *(float *)((char *)v108 + v99) = (float)(*(float *)((char *)&this->m_CoreDispInfo.m_pVerts[1].m_FieldDistance
                                                                + v11)
                                                     + *(float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_FieldDistance
                                                                + v11))
                                             * 0.5;
              *v108 = (float)(*(float *)((char *)&this->m_CoreDispInfo.m_pVerts[1].m_LuxelCoords[4].x + v11)
                            + *(float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_LuxelCoords[4].x + v11))
                    * 0.5;
              v26 = this->m_CoreDispInfo.m_pVerts;
              v27 = *(float *)((char *)&v26[1].m_FieldVector.y + v11) + *(float *)((char *)&v26->m_FieldVector.y + v11);
              v28 = *(float *)((char *)&v26[1].m_FieldVector.z + v11) + *(float *)((char *)&v26->m_FieldVector.z + v11);
              *(v90 - 2) = (float)(*(float *)((char *)&v26[1].m_FieldVector.x + v11)
                                 + *(float *)((char *)&v26->m_FieldVector.x + v11))
                         * 0.5;
              *(v90 - 1) = v27 * 0.5;
              *v90 = v28 * 0.5;
              v29 = this->m_CoreDispInfo.m_pVerts;
              v30 = *(float *)((char *)&v29[1].m_SubdivPos.y + v11) + *(float *)((char *)&v29->m_SubdivPos.y + v11);
              v31 = *(float *)((char *)&v29[1].m_SubdivPos.z + v11) + *(float *)((char *)&v29->m_SubdivPos.z + v11);
              *((float *)v106 + 1) = (float)(*(float *)((char *)&v29[1].m_SubdivPos.x + v11)
                                           + *(float *)((char *)&v29->m_SubdivPos.x + v11))
                                   * 0.5;
              *(float *)((char *)v104 + v109) = v30 * 0.5;
              *(float *)((char *)v90 + v110) = v31 * 0.5;
              v32 = this->m_CoreDispInfo.m_pVerts;
              v33 = *(float *)((char *)&v32[1].m_SubdivNormal.y + v11)
                  + *(float *)((char *)&v32->m_SubdivNormal.y + v11);
              v34 = *(float *)((char *)&v32[1].m_SubdivNormal.z + v11)
                  + *(float *)((char *)&v32->m_SubdivNormal.z + v11);
              *(v104 - 1) = (float)(*(float *)((char *)&v32[1].m_SubdivNormal.x + v11)
                                  + *(float *)((char *)&v32->m_SubdivNormal.x + v11))
                          * 0.5;
              *v104 = v33 * 0.5;
              v14 = v135;
              *(float *)((char *)v90 + v112) = v34 * 0.5;
              bRight_3 = 1;
            }
            if ( y + 1 >= v14 )
            {
              v39 = v92;
            }
            else
            {
              *(float *)((char *)v103 + v99) = (float)(*(float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_FieldDistance
                                                                + v11)
                                                     + *(float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_FieldDistance
                                                                + v12))
                                             * 0.5;
              *v103 = (float)(*(float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_LuxelCoords[4].x + v11)
                            + *(float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_LuxelCoords[4].x + v12))
                    * 0.5;
              v35 = this->m_CoreDispInfo.m_pVerts;
              v36 = *(float *)((char *)&v35->m_FieldVector.x + v12) + *(float *)((char *)&v35->m_FieldVector.x + v11);
              v37 = *(float *)((char *)&v35->m_FieldVector.y + v12) + *(float *)((char *)&v35->m_FieldVector.y + v11);
              v38 = *(float *)((char *)&v35->m_FieldVector.z + v12) + *(float *)((char *)&v35->m_FieldVector.z + v11);
              v39 = v92;
              *(v92 - 5) = v36 * 0.5;
              *(v92 - 4) = v37 * 0.5;
              *(v92 - 3) = v38 * 0.5;
              v40 = this->m_CoreDispInfo.m_pVerts;
              v41 = *(float *)((char *)&v40->m_SubdivPos.y + v12) + *(float *)((char *)&v40->m_SubdivPos.y + v11);
              v42 = *(float *)((char *)&v40->m_SubdivPos.z + v12) + *(float *)((char *)&v40->m_SubdivPos.z + v11);
              *(v95 - 2) = (float)(*(float *)((char *)&v40->m_SubdivPos.x + v12)
                                 + *(float *)((char *)&v40->m_SubdivPos.x + v11))
                         * 0.5;
              *(v95 - 1) = v41 * 0.5;
              *v95 = v42 * 0.5;
              v43 = this->m_CoreDispInfo.m_pVerts;
              v44 = *(float *)((char *)&v43->m_SubdivNormal.y + v12) + *(float *)((char *)&v43->m_SubdivNormal.y + v11);
              v45 = *(float *)((char *)&v43->m_SubdivNormal.z + v12) + *(float *)((char *)&v43->m_SubdivNormal.z + v11);
              *(v131 - 4) = (float)(*(float *)((char *)&v43->m_SubdivNormal.x + v12)
                                  + *(float *)((char *)&v43->m_SubdivNormal.x + v11))
                          * 0.5;
              *(v131 - 3) = v44 * 0.5;
              *(v131 - 2) = v45 * 0.5;
              bUp = true;
            }
            if ( bRight_3 != 0 && bUp )
            {
              *(float *)((char *)v103 + v99 + 4) = (float)(*(float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_FieldDistance
                                                                    + v12)
                                                         + *(float *)((char *)&this->m_CoreDispInfo.m_pVerts[1].m_FieldDistance
                                                                    + v11))
                                                 * 0.5;
              v103[1] = (float)(*(float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_LuxelCoords[4].x + v12)
                              + *(float *)((char *)&this->m_CoreDispInfo.m_pVerts[1].m_LuxelCoords[4].x + v11))
                      * 0.5;
              v46 = this->m_CoreDispInfo.m_pVerts;
              v47 = *(float *)((char *)&v46->m_FieldVector.y + v12) + *(float *)((char *)&v46[1].m_FieldVector.y + v11);
              v48 = *(float *)((char *)&v46->m_FieldVector.z + v12) + *(float *)((char *)&v46[1].m_FieldVector.z + v11);
              *(float *)((char *)v107 + v83) = (float)(*(float *)((char *)&v46->m_FieldVector.x + v12)
                                                     + *(float *)((char *)&v46[1].m_FieldVector.x + v11))
                                             * 0.5;
              *(v39 - 1) = v47 * 0.5;
              *v39 = v48 * 0.5;
              v49 = this->m_CoreDispInfo.m_pVerts;
              v50 = *(float *)((char *)&v49->m_SubdivPos.y + v12) + *(float *)((char *)&v49[1].m_SubdivPos.y + v11);
              v51 = *(float *)((char *)&v49->m_SubdivPos.z + v12) + *(float *)((char *)&v49[1].m_SubdivPos.z + v11);
              *v107 = (float)(*(float *)((char *)&v49->m_SubdivPos.x + v12)
                            + *(float *)((char *)&v49[1].m_SubdivPos.x + v11))
                    * 0.5;
              *(float *)((char *)v131 + v109) = v50 * 0.5;
              *(float *)((char *)v39 + v110) = v51 * 0.5;
              v52 = this->m_CoreDispInfo.m_pVerts;
              v53 = *(float *)((char *)&v52->m_SubdivNormal.y + v12)
                  + *(float *)((char *)&v52[1].m_SubdivNormal.y + v11);
              v54 = *(float *)((char *)&v52->m_SubdivNormal.z + v12)
                  + *(float *)((char *)&v52[1].m_SubdivNormal.z + v11);
              *(float *)((char *)v107 + v85) = (float)(*(float *)((char *)&v52->m_SubdivNormal.x + v12)
                                                     + *(float *)((char *)&v52[1].m_SubdivNormal.x + v11))
                                             * 0.5;
              *v131 = v53 * 0.5;
              *(float *)((char *)v39 + v112) = v54 * 0.5;
              v23 = v90;
            }
            ++v105;
            v94 += 2;
            v108 += 2;
            v103 += 2;
            v106 += 24;
            v104 += 6;
            v95 += 6;
            v107 += 6;
            v131 += 6;
            v11 += 224;
            v12 += 224;
            v55 = v123-- == 1;
            v90 = v23 + 6;
            v92 = v39 + 6;
            if ( v55 )
              break;
            v14 = v135;
          }
          v4 = v115;
          v9 = v88;
          v8 = v86;
        }
        v101 += v135;
        v102 += v8;
        v97 += v8;
        v100 = (float *)((char *)v100 + v84);
        v93 = (float *)((char *)v93 + v84);
        v98 = (float *)((char *)v98 + v84);
        v91 += v9;
        v96 += v9;
        v89 = (float *)((char *)v89 + v9);
        v120 = (float *)((char *)v120 + v9);
        v119 += v9;
        i += v9;
        size += v9;
        --v128;
      }
      while ( v128 != 0 );
      v5 = v134;
    }
    v56 = 0;
    ia = 0;
    v57 = ((1 << this->m_CoreDispInfo.m_Power) + 1) * ((1 << this->m_CoreDispInfo.m_Power) + 1);
    sizea = v57;
    if ( v57 >= 4 )
    {
      v132 = alphas + 3;
      bRight = dists + 1;
      v111 = (char *)v4 - (char *)p;
      v136 = v4 + 8;
      v58 = p + 5;
      v59 = (float *)(v5 + 16);
      v60 = 0;
      v124 = ((unsigned int)(sizea - 4) >> 2) + 1;
      v129 = v59;
      ia = 4 * v124;
      do
      {
        this->m_CoreDispInfo.m_pVerts[v60].m_Alpha = *(v132 - 3);
        v61 = this->m_CoreDispInfo.m_pVerts;
        v61[v60].m_FieldVector.x = *(v58 - 5);
        v61[v60].m_FieldVector.y = *(v58 - 4);
        v61[v60].m_FieldVector.z = *(v58 - 3);
        this->m_CoreDispInfo.m_pVerts[v60].m_FieldDistance = *(bRight - 1);
        p_m_SubdivPos = &this->m_CoreDispInfo.m_pVerts[v60].m_SubdivPos;
        p_m_SubdivPos->x = *(v136 - 8);
        p_m_SubdivPos->y = *(v136 - 7);
        p_m_SubdivPos->z = *(v136 - 6);
        p_m_SubdivNormal = &this->m_CoreDispInfo.m_pVerts[v60].m_SubdivNormal;
        p_m_SubdivNormal->x = *(v59 - 4);
        p_m_SubdivNormal->y = *(v59 - 3);
        p_m_SubdivNormal->z = *(v59 - 2);
        this->m_CoreDispInfo.m_pVerts[v60 + 1].m_Alpha = *(float *)((char *)bRight + (char *)alphas - (char *)dists);
        v64 = &this->m_CoreDispInfo.m_pVerts[v60 + 1];
        v64->m_FieldVector.x = *(v58 - 2);
        v64->m_FieldVector.y = *(v58 - 1);
        v64->m_FieldVector.z = *v58;
        this->m_CoreDispInfo.m_pVerts[v60 + 1].m_FieldDistance = *bRight;
        v65 = &this->m_CoreDispInfo.m_pVerts[v60 + 1].m_SubdivPos;
        v65->x = *(v136 - 5);
        v65->y = *(float *)((char *)v129 + (char *)v115 - v134);
        v65->z = *(float *)((char *)v58 + v111);
        v66 = &this->m_CoreDispInfo.m_pVerts[v60 + 1].m_SubdivNormal;
        v66->x = *(v129 - 1);
        v66->y = *v129;
        v66->z = *(float *)((char *)v58 + v134 - (char *)p);
        this->m_CoreDispInfo.m_pVerts[v60 + 2].m_Alpha = *(v132 - 1);
        v67 = &this->m_CoreDispInfo.m_pVerts[v60 + 2];
        v67->m_FieldVector.x = v58[1];
        v67->m_FieldVector.y = v58[2];
        v67->m_FieldVector.z = v58[3];
        this->m_CoreDispInfo.m_pVerts[v60 + 2].m_FieldDistance = bRight[1];
        v68 = &this->m_CoreDispInfo.m_pVerts[v60 + 2].m_SubdivPos;
        v68->x = *(v136 - 2);
        v59 = v129 + 12;
        v58 += 12;
        v68->y = *(v136 - 1);
        v129 = v59;
        v69 = v132;
        v68->z = *v136;
        v70 = &this->m_CoreDispInfo.m_pVerts[v60 + 2].m_SubdivNormal;
        v70->x = *(v59 - 10);
        v132 += 4;
        v70->y = *(v59 - 9);
        v70->z = *(v59 - 8);
        v71 = *v69;
        v72 = bRight;
        this->m_CoreDispInfo.m_pVerts[v60 + 3].m_Alpha = v71;
        v73 = this->m_CoreDispInfo.m_pVerts;
        bRight += 4;
        v73[v60 + 3].m_FieldVector.x = *(v58 - 8);
        v73[v60 + 3].m_FieldVector.y = *(v58 - 7);
        v73[v60 + 3].m_FieldVector.z = *(v58 - 6);
        this->m_CoreDispInfo.m_pVerts[v60 + 3].m_FieldDistance = v72[2];
        v74 = &this->m_CoreDispInfo.m_pVerts[v60 + 3].m_SubdivPos;
        v74->x = v136[1];
        v136 += 12;
        v74->y = *(v136 - 10);
        v74->z = *(v136 - 9);
        v75 = &this->m_CoreDispInfo.m_pVerts[v60 + 3].m_SubdivNormal;
        v75->x = *(v59 - 7);
        v60 += 4;
        v55 = v124-- == 1;
        v75->y = *(v59 - 6);
        v75->z = *(v59 - 5);
      }
      while ( !v55 );
      v4 = v115;
      v56 = ia;
      v57 = sizea;
    }
    if ( v56 < v57 )
    {
      v121 = &v4[3 * v56];
      v76 = &dists[v56];
      v77 = v56;
      bRighta = (float *)&v134[12 * v56 + 4];
      v116 = &p[3 * v56 + 2];
      v130 = v76;
      v125 = sizea - ia;
      do
      {
        this->m_CoreDispInfo.m_pVerts[v77].m_Alpha = *(float *)((char *)v76 + (char *)alphas - (char *)dists);
        v78 = this->m_CoreDispInfo.m_pVerts;
        v78[v77].m_FieldVector.x = *(v116 - 2);
        v78[v77].m_FieldVector.y = *(v116 - 1);
        v78[v77].m_FieldVector.z = *v116;
        this->m_CoreDispInfo.m_pVerts[v77].m_FieldDistance = *v76;
        v79 = &this->m_CoreDispInfo.m_pVerts[v77].m_SubdivPos;
        v79->x = *v121;
        v79->y = *(float *)((char *)bRighta + (char *)v4 - v134);
        v79->z = *(float *)((char *)v116 + (char *)v4 - (char *)p);
        v80 = &this->m_CoreDispInfo.m_pVerts[v77].m_SubdivNormal;
        v80->x = *(bRighta - 1);
        ++v77;
        v80->y = *bRighta;
        v80->z = *(float *)((char *)v116 + v134 - (char *)p);
        v121 += 3;
        bRighta += 3;
        v76 = v130 + 1;
        v55 = v125-- == 1;
        ++v130;
        v116 += 3;
      }
      while ( !v55 );
    }
    v6 = dists;
  }
  operator delete(p: v6);
  operator delete(p: alphas);
  operator delete(p);
  operator delete(p: v4);
  operator delete(p: v134);
}

//------------------------------------------------------------------------------
// Address: 0x10114690
// Name: private: void CMapDisp::SamplePoints(int,int,int,bool __near *,float __near *,float __near *,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::SamplePoints(
        CMapDisp *this,
        int index,
        int width,
        int height,
        bool *pValidPoints,
        float *pValue,
        float *pAlpha,
        Vector *newDispVector,
        Vector *newSubdivPos,
        Vector *newSubdivNormal)
{
  CoreDispVert_t *v11; // eax
  float z; // xmm2_4
  float m_Alpha; // xmm3_4
  float x; // xmm4_4
  float y; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  int m_FieldDistance; // edi
  int i; // ebx
  int v20; // eax
  CoreDispVert_t *m_pVerts; // ecx
  int v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  float *p_x; // eax
  float v26; // xmm0_4
  float vSPos_4; // [esp+8h] [ebp-18h]
  float vSPos_8; // [esp+Ch] [ebp-14h]
  float vSNormal; // [esp+10h] [ebp-10h]
  float vSNormal_4; // [esp+14h] [ebp-Ch]
  float vSNormal_8; // [esp+18h] [ebp-8h]
  CMapDisp *v32; // [esp+1Ch] [ebp-4h]
  int count; // [esp+28h] [ebp+8h]

  v11 = &this->m_CoreDispInfo.m_pVerts[index];
  z = v11->m_SubdivNormal.z;
  m_Alpha = v11->m_Alpha;
  x = v11->m_FieldVector.x;
  y = v11->m_FieldVector.y;
  v16 = v11->m_FieldVector.z;
  v17 = v11->m_SubdivPos.x;
  vSPos_4 = v11->m_SubdivPos.y;
  vSPos_8 = v11->m_SubdivPos.z;
  vSNormal = v11->m_SubdivNormal.x;
  m_FieldDistance = (int)v11->m_FieldDistance;
  v32 = this;
  vSNormal_4 = v11->m_SubdivNormal.y;
  vSNormal_8 = z;
  count = 1;
  for ( i = 0; i < 8; ++i )
  {
    if ( pValidPoints[i] )
    {
      switch ( i )
      {
        case 0:
          v20 = index - height - 1;
          goto LABEL_12;
        case 1:
          v20 = index - 1;
          goto LABEL_12;
        case 2:
          v20 = index + height - 1;
          goto LABEL_12;
        case 3:
          v20 = index + height;
          goto LABEL_12;
        case 4:
          v20 = index + height + 1;
          goto LABEL_12;
        case 5:
          v20 = index + 1;
          goto LABEL_12;
        case 6:
          v20 = index - height + 1;
          goto LABEL_12;
        case 7:
          v20 = index - height;
LABEL_12:
          m_pVerts = this->m_CoreDispInfo.m_pVerts;
          v22 = v20;
          v23 = m_pVerts[v22].m_SubdivPos.y + vSPos_4;
          v24 = m_pVerts[v22].m_SubdivPos.z + vSPos_8;
          m_Alpha = m_Alpha + m_pVerts[v22].m_Alpha;
          x = x + m_pVerts[v22].m_FieldVector.x;
          y = y + m_pVerts[v22].m_FieldVector.y;
          v16 = v16 + m_pVerts[v22].m_FieldVector.z;
          p_x = &m_pVerts[v22].m_FieldVector.x;
          ++count;
          this = v32;
          m_FieldDistance = (int)(float)((float)m_FieldDistance + p_x[3]);
          v17 = p_x[7] + v17;
          vSPos_4 = v23;
          vSPos_8 = v24;
          z = p_x[6] + vSNormal_8;
          vSNormal = p_x[4] + vSNormal;
          vSNormal_4 = p_x[5] + vSNormal_4;
          vSNormal_8 = z;
          break;
        default:
          continue;
      }
    }
  }
  *pValue = (float)m_FieldDistance / (float)count;
  *pAlpha = (float)(1.0 / (float)count) * m_Alpha;
  v26 = 1.0 / (float)count;
  newDispVector->x = v26 * x;
  newDispVector->z = v26 * v16;
  newDispVector->y = v26 * y;
  newSubdivPos->z = v26 * vSPos_8;
  newSubdivPos->x = v26 * v17;
  newSubdivPos->y = v26 * vSPos_4;
  newSubdivNormal->x = v26 * vSNormal;
  newSubdivNormal->y = v26 * vSNormal_4;
  newSubdivNormal->z = v26 * z;
}

//------------------------------------------------------------------------------
// Address: 0x101148E0
// Name: private: void CMapDisp::DownSample(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::DownSample(CMapDisp *this, char oldPower)
{
  float *v3; // ebx
  float *v4; // eax
  float *v5; // edi
  int v6; // ebx
  float *v7; // edx
  float *v8; // edi
  int v9; // ecx
  int v10; // eax
  bool v11; // sf
  float *v12; // ecx
  float *v13; // edx
  float *v14; // eax
  char *v15; // edx
  bool v16; // zf
  int v17; // ecx
  _BYTE *v18; // ebx
  int v19; // edx
  int v20; // eax
  float *v21; // edx
  int v22; // eax
  float *v23; // ecx
  float *v24; // ebx
  CoreDispVert_t *m_pVerts; // edi
  Vector *p_m_SubdivPos; // edi
  double v27; // st7
  float *v28; // ebx
  Vector *p_m_SubdivNormal; // edi
  double v30; // st7
  int v31; // ebx
  CoreDispVert_t *v32; // edx
  Vector *v33; // edi
  float *v34; // edx
  double v35; // st7
  char *v36; // ebx
  double v37; // st7
  char *v38; // ebx
  Vector *v39; // edi
  double v40; // st7
  float *v41; // ebx
  CoreDispVert_t *v42; // edi
  float *v43; // ebx
  double v44; // st7
  Vector *v45; // edi
  double v46; // st7
  float *v47; // ebx
  Vector *v48; // edi
  double v49; // st7
  CoreDispVert_t *v50; // edi
  Vector *v51; // ebx
  char *v52; // edi
  Vector *v53; // ebx
  unsigned int v54; // eax
  int v55; // edi
  int v56; // ecx
  unsigned int v57; // ebx
  float *v58; // edx
  int v59; // ebx
  CoreDispVert_t *v60; // edx
  float *v61; // edi
  double v62; // st7
  CoreDispVert_t *v63; // edx
  double v64; // st7
  int v65; // edi
  int v66; // edx
  double v67; // st7
  char *v68; // ebx
  double v69; // st7
  char *v70; // ebx
  Vector *v71; // edx
  double v72; // st7
  Vector newSubdivNormal; // [esp+Ch] [ebp-A0h] BYREF
  Vector newSubdivPos; // [esp+18h] [ebp-94h] BYREF
  Vector newDispVector; // [esp+24h] [ebp-88h] BYREF
  int v76; // [esp+30h] [ebp-7Ch]
  float newValue; // [esp+34h] [ebp-78h] BYREF
  int v78; // [esp+38h] [ebp-74h]
  int v79; // [esp+3Ch] [ebp-70h]
  float newAlpha; // [esp+40h] [ebp-6Ch] BYREF
  unsigned int v81; // [esp+44h] [ebp-68h]
  float *v82; // [esp+48h] [ebp-64h]
  int v83; // [esp+4Ch] [ebp-60h]
  int v84; // [esp+50h] [ebp-5Ch]
  float *v85; // [esp+54h] [ebp-58h]
  int i; // [esp+58h] [ebp-54h]
  bool validPoints[8]; // [esp+5Ch] [ebp-50h] BYREF
  int v88; // [esp+64h] [ebp-48h]
  char *v89; // [esp+68h] [ebp-44h]
  char *v90; // [esp+6Ch] [ebp-40h]
  float *dists; // [esp+70h] [ebp-3Ch]
  int size; // [esp+74h] [ebp-38h]
  float *v93; // [esp+78h] [ebp-34h]
  int index; // [esp+7Ch] [ebp-30h]
  void *p; // [esp+80h] [ebp-2Ch]
  unsigned int v96; // [esp+84h] [ebp-28h]
  float *alphas; // [esp+88h] [ebp-24h]
  float *v98; // [esp+8Ch] [ebp-20h]
  float *v99; // [esp+90h] [ebp-1Ch]
  int v100; // [esp+94h] [ebp-18h]
  void *v101; // [esp+98h] [ebp-14h]
  void *v102; // [esp+9Ch] [ebp-10h]
  int v103; // [esp+A8h] [ebp-4h]
  float *oldPowera; // [esp+B4h] [ebp+8h]
  float *oldPowerb; // [esp+B4h] [ebp+8h]

  v100 = (1 << this->m_CoreDispInfo.m_Power) + 1;
  v3 = (float *)operator new[](nSize: 4 * v100 * v100);
  dists = v3;
  alphas = (float *)operator new[](nSize: 4 * v100 * v100);
  p = operator new[](nSize: 12 * v100 * v100);
  v102 = operator new[](nSize: 12 * v100 * v100);
  v4 = (float *)operator new[](nSize: 12 * v100 * v100);
  v5 = v4;
  v101 = v4;
  v103 = -1;
  if ( v3 != nullptr && alphas != nullptr && p != nullptr && v102 != nullptr && v4 != nullptr )
  {
    v6 = (1 << oldPower) + 1;
    if ( v6 > 0 )
    {
      v7 = alphas;
      i = 4 * v100;
      v93 = (float *)v102;
      size = (int)v101 + 4;
      v8 = (float *)((char *)p + 8);
      index = 0;
      v76 = 12 * v100;
      v82 = alphas;
      v96 = (unsigned int)p + 8;
      v100 = ((unsigned int)(1 << oldPower) >> 1) + 1;
      do
      {
        v99 = v93;
        v9 = index;
        v85 = v7;
        v84 = size;
        v90 = (char *)((_BYTE *)v102 - (_BYTE *)p);
        v89 = (char *)((_BYTE *)v101 - (_BYTE *)p);
        v98 = (float *)index;
        v88 = (_BYTE *)v102 - (_BYTE *)v101;
        v79 = (char *)dists - (char *)alphas;
        v81 = ((unsigned int)(1 << oldPower) >> 1) + 1;
        while ( 1 )
        {
          *(_QWORD *)validPoints = 0;
          v83 = v9 % v6;
          v10 = v9 / v6;
          if ( v9 % v6 - 1 >= 0 )
          {
            v11 = v10 - 1 < 0;
            v10 = v9 / v6;
            if ( !v11 )
              validPoints[0] = true;
          }
          if ( v9 % v6 - 1 >= 0 )
          {
            validPoints[1] = true;
            if ( v10 + 1 < v6 )
              validPoints[2] = true;
          }
          v78 = v10 + 1;
          if ( v10 + 1 < v6 )
            validPoints[3] = true;
          if ( v83 + 1 < v6 )
          {
            v10 = v9 / v6;
            if ( v78 < v6 )
              validPoints[4] = true;
            if ( v83 + 1 < v6 )
            {
              validPoints[5] = true;
              if ( v9 / v6 - 1 >= 0 )
                validPoints[6] = true;
            }
          }
          if ( v10 - 1 >= 0 )
            validPoints[7] = true;
          CMapDisp::SamplePoints(
            this,
            index: v9,
            width: v6,
            height: v6,
            pValidPoints: validPoints,
            pValue: &newValue,
            pAlpha: &newAlpha,
            &newDispVector,
            &newSubdivPos,
            &newSubdivNormal);
          v12 = v85;
          v13 = v99;
          *(float *)((char *)v85 + v79) = newValue;
          v14 = (float *)v84;
          *v12 = newAlpha;
          *(v8 - 2) = newDispVector.x;
          v98 = (float *)((char *)v98 + 2);
          v99 += 3;
          *(v8 - 1) = newDispVector.y;
          *v8 = newDispVector.z;
          *v13 = newSubdivPos.x;
          *(float *)((char *)v14 + v88) = newSubdivPos.y;
          *(float *)((char *)v8 + (_DWORD)v90) = newSubdivPos.z;
          v15 = v89;
          *(v14 - 1) = newSubdivNormal.x;
          *v14 = newSubdivNormal.y;
          *(float *)((char *)v8 + (_DWORD)v15) = newSubdivNormal.z;
          v8 += 3;
          v16 = v81-- == 1;
          v85 = v12 + 1;
          v84 = (int)(v14 + 3);
          if ( v16 )
            break;
          v9 = (int)v98;
        }
        v17 = v100;
        v93 = (float *)((char *)v93 + v76);
        size += v76;
        index += 2 * v6;
        v7 = &v82[i / 4u];
        v8 = (float *)(v76 + v96);
        v82 = (float *)((char *)v82 + i);
        v96 += v76;
        --v100;
      }
      while ( v17 != 1 );
      v5 = (float *)v101;
    }
    v18 = p;
    v19 = 0;
    v20 = ((1 << this->m_CoreDispInfo.m_Power) + 1) * ((1 << this->m_CoreDispInfo.m_Power) + 1);
    size = v20;
    if ( v20 >= 4 )
    {
      oldPowera = dists + 1;
      v21 = v5 + 4;
      v90 = (char *)((_BYTE *)v102 - (_BYTE *)p);
      v89 = (char *)((_BYTE *)v101 - (_BYTE *)p);
      v88 = (_BYTE *)v102 - (_BYTE *)v101;
      v99 = alphas + 3;
      v93 = (float *)((char *)alphas - (char *)dists);
      v96 = ((unsigned int)(size - 4) >> 2) + 1;
      v22 = 0;
      v98 = (float *)((char *)v102 + 32);
      v100 = (int)(v5 + 4);
      v23 = (float *)((char *)p + 20);
      i = 4 * v96;
      do
      {
        this->m_CoreDispInfo.m_pVerts[v22].m_Alpha = *(v99 - 3);
        v24 = v98;
        this->m_CoreDispInfo.m_pVerts[v22].m_FieldDistance = *(oldPowera - 1);
        m_pVerts = this->m_CoreDispInfo.m_pVerts;
        m_pVerts[v22].m_FieldVector.x = *(v23 - 5);
        m_pVerts[v22].m_FieldVector.y = *(v23 - 4);
        m_pVerts[v22].m_FieldVector.z = *(v23 - 3);
        p_m_SubdivPos = &this->m_CoreDispInfo.m_pVerts[v22].m_SubdivPos;
        p_m_SubdivPos->x = *(v24 - 8);
        p_m_SubdivPos->y = *(v24 - 7);
        v27 = *(v24 - 6);
        v28 = v93;
        p_m_SubdivPos->z = v27;
        p_m_SubdivNormal = &this->m_CoreDispInfo.m_pVerts[v22].m_SubdivNormal;
        p_m_SubdivNormal->x = *(v21 - 4);
        p_m_SubdivNormal->y = *(v21 - 3);
        p_m_SubdivNormal->z = *(v21 - 2);
        v30 = *(float *)((char *)oldPowera + (_DWORD)v28);
        v31 = v88;
        this->m_CoreDispInfo.m_pVerts[v22 + 1].m_Alpha = v30;
        this->m_CoreDispInfo.m_pVerts[v22 + 1].m_FieldDistance = *oldPowera;
        v32 = &this->m_CoreDispInfo.m_pVerts[v22 + 1];
        v32->m_FieldVector.x = *(v23 - 2);
        v32->m_FieldVector.y = *(v23 - 1);
        v32->m_FieldVector.z = *v23;
        v33 = &this->m_CoreDispInfo.m_pVerts[v22 + 1].m_SubdivPos;
        v34 = (float *)v100;
        v33->x = *(v98 - 5);
        v35 = *(float *)((char *)v34 + v31);
        v36 = v90;
        v33->y = v35;
        v37 = *(float *)&v36[(_DWORD)v23];
        v38 = v89;
        v33->z = v37;
        v39 = &this->m_CoreDispInfo.m_pVerts[v22 + 1].m_SubdivNormal;
        v39->x = *(v34 - 1);
        v39->y = *v34;
        v40 = *(float *)&v38[(_DWORD)v23];
        v41 = v99;
        v39->z = v40;
        this->m_CoreDispInfo.m_pVerts[v22 + 2].m_Alpha = *(v41 - 1);
        this->m_CoreDispInfo.m_pVerts[v22 + 2].m_FieldDistance = oldPowera[1];
        v42 = &this->m_CoreDispInfo.m_pVerts[v22 + 2];
        v42->m_FieldVector.x = v23[1];
        v43 = v98;
        v42->m_FieldVector.y = v23[2];
        v21 = v34 + 12;
        v44 = v23[3];
        v23 += 12;
        v42->m_FieldVector.z = v44;
        v45 = &this->m_CoreDispInfo.m_pVerts[v22 + 2].m_SubdivPos;
        v45->x = *(v43 - 2);
        v100 = (int)v21;
        v45->y = *(v43 - 1);
        v46 = *v43;
        v47 = v99;
        v45->z = v46;
        v48 = &this->m_CoreDispInfo.m_pVerts[v22 + 2].m_SubdivNormal;
        v48->x = *(v21 - 10);
        v99 += 4;
        v48->y = *(v21 - 9);
        v48->z = *(v21 - 8);
        this->m_CoreDispInfo.m_pVerts[v22 + 3].m_Alpha = *v47;
        v49 = oldPowera[2];
        oldPowera += 4;
        this->m_CoreDispInfo.m_pVerts[v22 + 3].m_FieldDistance = v49;
        v50 = this->m_CoreDispInfo.m_pVerts;
        v50[v22 + 3].m_FieldVector.x = *(v23 - 8);
        v50[v22 + 3].m_FieldVector.y = *(v23 - 7);
        v50[v22 + 3].m_FieldVector.z = *(v23 - 6);
        v51 = &this->m_CoreDispInfo.m_pVerts[v22 + 3].m_SubdivPos;
        v52 = (char *)(v98 + 12);
        v51->x = v98[1];
        v98 = (float *)v52;
        v51->y = *((float *)v52 - 10);
        v51->z = *((float *)v52 - 9);
        v53 = &this->m_CoreDispInfo.m_pVerts[v22 + 3].m_SubdivNormal;
        v53->x = *(v21 - 7);
        v22 += 4;
        v16 = v96-- == 1;
        v53->y = *(v21 - 6);
        v53->z = *(v21 - 5);
      }
      while ( !v16 );
      v20 = size;
      v19 = i;
      v18 = p;
      v5 = (float *)v101;
    }
    if ( v19 < v20 )
    {
      index = (int)v102 + 12 * v19;
      oldPowerb = &dists[v19];
      v100 = (int)v101 + 12 * v19 + 4;
      v90 = (char *)((_BYTE *)v102 - v18);
      v89 = (char *)((_BYTE *)v101 - v18);
      v88 = (_BYTE *)v102 - (_BYTE *)v101;
      v54 = v19;
      v55 = (char *)alphas - (char *)dists;
      v56 = (int)&v18[12 * v19 + 8];
      v57 = size - v19;
      v58 = oldPowerb;
      v93 = (float *)((char *)alphas - (char *)dists);
      v96 = v57;
      while ( 1 )
      {
        this->m_CoreDispInfo.m_pVerts[v54].m_Alpha = *(float *)((char *)v58 + v55);
        v59 = v88;
        this->m_CoreDispInfo.m_pVerts[v54].m_FieldDistance = *v58;
        v60 = this->m_CoreDispInfo.m_pVerts;
        v61 = (float *)index;
        v60[v54].m_FieldVector.x = *(float *)(v56 - 8);
        index += 12;
        v62 = *(float *)(v56 - 4);
        v56 += 12;
        v60[v54].m_FieldVector.y = v62;
        v60[v54].m_FieldVector.z = *(float *)(v56 - 12);
        v63 = this->m_CoreDispInfo.m_pVerts;
        v64 = *v61;
        v65 = v100;
        v63[v54].m_SubdivPos.x = v64;
        v66 = (int)&v63[v54].m_SubdivPos;
        v67 = *(float *)(v59 + v65);
        v68 = v90;
        *(float *)(v66 + 4) = v67;
        v65 += 12;
        v69 = *(float *)&v68[v56 - 12];
        v70 = v89;
        *(float *)(v66 + 8) = v69;
        v71 = &this->m_CoreDispInfo.m_pVerts[v54].m_SubdivNormal;
        v71->x = *(float *)(v65 - 16);
        ++v54;
        v72 = *(float *)(v65 - 12);
        v100 = v65;
        v71->y = v72;
        v71->z = *(float *)&v70[v56 - 12];
        v58 = oldPowerb + 1;
        v16 = v96-- == 1;
        ++oldPowerb;
        if ( v16 )
          break;
        v55 = (int)v93;
      }
      v18 = p;
      v5 = (float *)v101;
    }
    operator delete(p: dists);
    operator delete(p: alphas);
    operator delete(p: v18);
  }
  else
  {
    operator delete(p: v3);
    operator delete(p: alphas);
    operator delete(p);
  }
  operator delete(p: v102);
  operator delete(p: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10115050
// Name: private: void CMapDisp::Flip(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::Flip(CMapDisp *this, int flipType)
{
  int v3; // ebx
  int v4; // edx
  int v5; // edi
  int v6; // eax
  int v7; // ecx
  int v8; // ebx
  CoreDispVert_t *m_pVerts; // edx
  float m_FieldDistance; // xmm0_4
  CoreDispVert_t *v11; // edx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  CoreDispVert_t *v17; // edx
  CoreDispVert_t *v18; // edx
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  CoreDispVert_t *v24; // edx
  CoreDispVert_t *v25; // edx
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  float *v31; // edx
  CoreDispVert_t *v32; // edx
  float m_Alpha; // xmm0_4
  int v34; // [esp+8h] [ebp-4h]
  int ndxHeight; // [esp+14h] [ebp+8h]

  v3 = (1 << this->m_CoreDispInfo.m_Power) + 1;
  v34 = v3;
  if ( flipType == 2 )
  {
    v4 = 0;
    ndxHeight = 0;
    if ( v3 > 0 )
    {
      do
      {
        v5 = 224 * v3;
        v6 = v4 * (v3 + 1);
        v7 = v4 * (224 * v3 + 224);
        v8 = v3 - ndxHeight;
        do
        {
          m_pVerts = this->m_CoreDispInfo.m_pVerts;
          m_FieldDistance = m_pVerts[v6].m_FieldDistance;
          m_pVerts[v6].m_FieldDistance = *(float *)((char *)&m_pVerts->m_FieldDistance + v7);
          *(float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_FieldDistance + v7) = m_FieldDistance;
          v11 = this->m_CoreDispInfo.m_pVerts;
          x = v11[v6].m_FieldVector.x;
          y = v11[v6].m_FieldVector.y;
          z = v11[v6].m_FieldVector.z;
          v15 = *(float *)((char *)&v11->m_FieldVector.y + v7);
          v16 = *(float *)((char *)&v11->m_FieldVector.z + v7);
          v11[v6].m_FieldVector.x = *(float *)((char *)&v11->m_FieldVector.x + v7);
          v11[v6].m_FieldVector.y = v15;
          v11[v6].m_FieldVector.z = v16;
          v17 = this->m_CoreDispInfo.m_pVerts;
          *(float *)((char *)&v17->m_FieldVector.x + v7) = x;
          *(float *)((char *)&v17->m_FieldVector.y + v7) = y;
          *(float *)((char *)&v17->m_FieldVector.z + v7) = z;
          v18 = this->m_CoreDispInfo.m_pVerts;
          v19 = v18[v6].m_SubdivPos.x;
          v20 = v18[v6].m_SubdivPos.y;
          v21 = v18[v6].m_SubdivPos.z;
          v22 = *(float *)((char *)&v18->m_SubdivPos.y + v7);
          v23 = *(float *)((char *)&v18->m_SubdivPos.z + v7);
          v18[v6].m_SubdivPos.x = *(float *)((char *)&v18->m_SubdivPos.x + v7);
          v18[v6].m_SubdivPos.y = v22;
          v18[v6].m_SubdivPos.z = v23;
          v24 = this->m_CoreDispInfo.m_pVerts;
          *(float *)((char *)&v24->m_SubdivPos.x + v7) = v19;
          *(float *)((char *)&v24->m_SubdivPos.y + v7) = v20;
          *(float *)((char *)&v24->m_SubdivPos.z + v7) = v21;
          v25 = this->m_CoreDispInfo.m_pVerts;
          v26 = v25[v6].m_SubdivNormal.x;
          v27 = v25[v6].m_SubdivNormal.y;
          v28 = v25[v6].m_SubdivNormal.z;
          v29 = *(float *)((char *)&v25->m_SubdivNormal.y + v7);
          v30 = *(float *)((char *)&v25->m_SubdivNormal.z + v7);
          v25[v6].m_SubdivNormal.x = *(float *)((char *)&v25->m_SubdivNormal.x + v7);
          v25[v6].m_SubdivNormal.y = v29;
          v25[v6].m_SubdivNormal.z = v30;
          v31 = (float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_SubdivNormal.x + v7);
          *v31 = v26;
          v31[1] = v27;
          v31[2] = v28;
          v32 = this->m_CoreDispInfo.m_pVerts;
          m_Alpha = v32[v6].m_Alpha;
          v32[v6].m_Alpha = *(float *)((char *)&v32->m_LuxelCoords[4].x + v7);
          *(float *)((char *)&this->m_CoreDispInfo.m_pVerts->m_LuxelCoords[4].x + v7) = m_Alpha;
          ++v6;
          v7 += v5;
          --v8;
        }
        while ( v8 != 0 );
        v3 = v34;
        v4 = ndxHeight + 1;
        ndxHeight = v4;
      }
      while ( v4 < v34 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115230
// Name: private: void CMapDisp::CalcColor(class CRender3D __near *,bool,enum SelectionState_t,class Color __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::CalcColor(
        CMapDisp *this,
        CRender3D *pRender,
        bool bIsSelected,
        SelectionState_t faceSelectionState,
        Color *pColor)
{
  CMapAtom *v5; // eax
  int v6; // eax
  CMapDoc *v7; // esi
  CMapFace *v8; // eax

  switch ( pRender->m_eCurrentRenderMode )
  {
    case RENDER_MODE_WIREFRAME:
      if ( bIsSelected )
      {
        pColor->_color[2] = 0;
        *(_WORD *)pColor->_color = -1;
      }
      break;
    case RENDER_MODE_FLAT:
    case RENDER_MODE_TRANSLUCENT_FLAT:
      if ( bIsSelected )
        goto LABEL_13;
      break;
    case RENDER_MODE_LIGHTMAP_GRID:
      v5 = this->GetParent(this);
      if ( bIsSelected )
      {
LABEL_13:
        pColor->_color[2] = 0;
        *(_WORD *)pColor->_color = 220;
      }
      else
      {
        v6 = *(_DWORD *)&v5[16].r;
        if ( v6 <= 16 )
        {
          if ( v6 < 16 )
            pColor->_color[2] = 100;
        }
        else
        {
          pColor->_color[0] = -106;
        }
      }
      break;
    case RENDER_MODE_SELECTION_OVERLAY:
      if ( faceSelectionState == SELECT_MULTI_PARTIAL )
      {
        *(_WORD *)&pColor->_color[2] = 16484;
      }
      else if ( faceSelectionState == SELECT_NORMAL || bIsSelected )
      {
        *pColor = (Color)1073742044;
      }
      break;
    case RENDER_MODE_SMOOTHING_GROUP:
      v7 = CMapDoc::m_pMapDoc;
      if ( CMapDoc::m_pMapDoc != nullptr )
      {
        v8 = (CMapFace *)this->GetParent(this);
        if ( CMapFace::InSmoothingGroup(this: v8, iGroup: v7->m_SmoothingGroupVisual) )
          pColor->_color[2] = 0;
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115340
// Name: public: void CMapDisp::Render2D(class CRender2D __near *,bool,enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::Render2D(
        CMapDisp *this,
        CRender2D *pRender,
        bool bIsSelected,
        SelectionState_t faceSelectionState)
{
  CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
  CRender::DrawDisplacement(this: pRender, pMapDisp: &this->m_CoreDispInfo);
  CRender::PopRenderMode(this: pRender);
}

//------------------------------------------------------------------------------
// Address: 0x10115370
// Name: public: static void CMapDisp::UpdateNeighborsOfDispsIntersectingBox(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapDisp::UpdateNeighborsOfDispsIntersectingBox(const Vector *bbMin, const Vector *bbMax, float flPadding)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // edi
  int v4; // ebx
  int v5; // eax
  int v6; // esi
  float bbPaddedMin; // [esp+4h] [ebp-1Ch]
  float bbPaddedMin_4; // [esp+8h] [ebp-18h]
  float bbPaddedMin_8; // [esp+Ch] [ebp-14h]
  float bbPaddedMax; // [esp+10h] [ebp-10h]
  float bbPaddedMax_4; // [esp+14h] [ebp-Ch]
  float bbPaddedMax_8; // [esp+18h] [ebp-8h]
  int count; // [esp+1Ch] [ebp-4h]

  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager != nullptr )
  {
    bbPaddedMin = bbMin->x - flPadding;
    bbPaddedMin_4 = bbMin->y - flPadding;
    bbPaddedMin_8 = bbMin->z - flPadding;
    bbPaddedMax = bbMax->x + flPadding;
    bbPaddedMax_4 = bbMax->y + flPadding;
    bbPaddedMax_8 = bbMax->z + flPadding;
    v4 = 0;
    count = ActiveWorldEditDispManager->WorldCount(this: ActiveWorldEditDispManager);
    if ( count > 0 )
    {
      do
      {
        v5 = (int)ActiveWorldEditDispManager->GetFromWorld_2(this: ActiveWorldEditDispManager, a2: v4);
        v6 = v5;
        if ( bbPaddedMax > *(float *)(v5 + 1064)
          && *(float *)(v5 + 1076) > bbPaddedMin
          && bbPaddedMax_4 > *(float *)(v5 + 1068)
          && *(float *)(v5 + 1080) > bbPaddedMin_4
          && bbPaddedMax_8 > *(float *)(v5 + 1072)
          && *(float *)(v5 + 1084) > bbPaddedMin_8 )
        {
          CMapDisp::ResetNeighbors(this: (CMapDisp *)v5);
          ActiveWorldEditDispManager->FindWorldNeighbors(this: ActiveWorldEditDispManager, a2: *(_WORD *)(v6 + 20));
        }
        ++v4;
      }
      while ( v4 < count );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115490
// Name: private: void CMapDisp::FindNeighbors(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapDisp::FindNeighbors(CMapDisp *this@<ecx>, int m_EditHandle@<ebx>)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // edi
  unsigned __int16 *v4; // eax
  int *m_CornerNeighborCounts; // ecx
  unsigned __int16 *m_EdgeNeighbors; // esi
  int v7; // esi
  CEditDispMgr *v8; // eax
  unsigned __int16 *v9; // ecx
  int *v10; // edx
  int *v11; // esi
  unsigned __int16 *v12; // eax
  int j; // edi
  unsigned __int16 *v14; // ebx
  int v15; // esi
  CEditDispMgr *v16; // eax
  CMapDisp *v17; // esi
  bool v18; // zf
  CMapDisp *pNeighborDisp; // [esp+8h] [ebp-1Ch]
  IWorldEditDispMgr *pDispMgr; // [esp+Ch] [ebp-18h]
  int v22; // [esp+10h] [ebp-14h]
  unsigned __int16 *v23; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  int v25; // [esp+18h] [ebp-Ch]
  unsigned __int16 *v26; // [esp+1Ch] [ebp-8h]
  int *v27; // [esp+20h] [ebp-4h]

  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  pDispMgr = ActiveWorldEditDispManager;
  if ( ActiveWorldEditDispManager != nullptr )
  {
    ActiveWorldEditDispManager->FindWorldNeighbors(this: ActiveWorldEditDispManager, a2: this->m_EditHandle);
    v4 = this->m_CornerNeighbors[0];
    m_CornerNeighborCounts = this->m_CornerNeighborCounts;
    m_EdgeNeighbors = this->m_EdgeNeighbors;
    v26 = v4;
    v27 = m_CornerNeighborCounts;
    v23 = m_EdgeNeighbors;
    v22 = 4;
    do
    {
      v7 = *m_EdgeNeighbors;
      if ( (_WORD)v7 != 0xFFFF )
      {
        v8 = EditDispMgr();
        pNeighborDisp = (CMapDisp *)((int (__thiscall *)(CEditDispMgr *, int, int))v8->GetDisp)(
                                      a1: v8,
                                      a2: v7,
                                      a3: m_EditHandle);
        v9 = pNeighborDisp->m_CornerNeighbors[0];
        v10 = pNeighborDisp->m_CornerNeighborOrientations[0];
        v11 = pNeighborDisp->m_CornerNeighborCounts;
        v12 = pNeighborDisp->m_EdgeNeighbors;
        for ( i = 4; i != 0; --i )
        {
          *v12 = -1;
          *(v11 - 4) = -1;
          *v11 = 0;
          for ( j = 4; j != 0; --j )
          {
            *v9 = -1;
            *v10 = -1;
            ++v9;
            ++v10;
          }
          ++v12;
          ++v11;
        }
        ActiveWorldEditDispManager = pDispMgr;
        m_EditHandle = pNeighborDisp->m_EditHandle;
        ((void (__thiscall *)(IWorldEditDispMgr *))pDispMgr->FindWorldNeighbors)(a1: pDispMgr);
      }
      if ( *v27 > 0 )
      {
        v14 = v26;
        v25 = *v27;
        do
        {
          v15 = *v14;
          if ( (_WORD)v15 != 0xFFFF )
          {
            v16 = EditDispMgr();
            v17 = v16->GetDisp(this: v16, a2: v15);
            CMapDisp::ResetNeighbors(this: v17);
            ActiveWorldEditDispManager->FindWorldNeighbors(this: ActiveWorldEditDispManager, a2: v17->m_EditHandle);
          }
          ++v14;
          --v25;
        }
        while ( v25 != 0 );
      }
      v26 += 4;
      ++v27;
      m_EdgeNeighbors = v23 + 1;
      v18 = v22-- == 1;
      ++v23;
    }
    while ( !v18 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101155F0
// Name: private: void CMapDisp::UpdateBoundingBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::UpdateBoundingBox(CMapDisp *this)
{
  int v2; // esi
  int v3; // ebx
  float x; // xmm3_4
  float v5; // xmm6_4
  float y; // xmm5_4
  float z; // xmm4_4
  int v8; // edx
  unsigned int v9; // edi
  CoreDispVert_t *m_pVerts; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  CoreDispVert_t *v14; // ecx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  CoreDispVert_t *v18; // ecx
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  CoreDispVert_t *v22; // ecx
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm6_4
  float v28; // xmm5_4
  float v29; // xmm4_4
  int v30; // edx
  int v31; // esi
  CoreDispVert_t *v32; // ecx
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // [esp+0h] [ebp-8h]
  float v37; // [esp+0h] [ebp-8h]
  float v38; // [esp+4h] [ebp-4h]
  float v39; // [esp+4h] [ebp-4h]

  this->m_BBox[0].z = 99999.0;
  this->m_BBox[0].y = 99999.0;
  this->m_BBox[0].x = 99999.0;
  this->m_BBox[1].z = -99999.0;
  this->m_BBox[1].y = -99999.0;
  this->m_BBox[1].x = -99999.0;
  v2 = ((1 << this->m_CoreDispInfo.m_Power) + 1) * ((1 << this->m_CoreDispInfo.m_Power) + 1);
  v3 = 0;
  if ( v2 >= 4 )
  {
    x = this->m_BBox[0].x;
    v5 = this->m_BBox[1].x;
    y = this->m_BBox[1].y;
    z = this->m_BBox[1].z;
    v8 = 0;
    v38 = this->m_BBox[0].y;
    v9 = ((unsigned int)(v2 - 4) >> 2) + 1;
    v36 = this->m_BBox[0].z;
    v3 = 4 * v9;
    do
    {
      m_pVerts = this->m_CoreDispInfo.m_pVerts;
      v11 = m_pVerts[v8].m_Vert.x;
      v12 = m_pVerts[v8].m_Vert.y;
      v13 = m_pVerts[v8].m_Vert.z;
      if ( x > v11 )
      {
        x = m_pVerts[v8].m_Vert.x;
        this->m_BBox[0].x = v11;
      }
      if ( v38 > v12 )
      {
        v38 = v12;
        this->m_BBox[0].y = v12;
      }
      if ( v36 > v13 )
      {
        v36 = v13;
        this->m_BBox[0].z = v13;
      }
      if ( v11 > v5 )
      {
        v5 = v11;
        this->m_BBox[1].x = v11;
      }
      if ( v12 > y )
      {
        y = v12;
        this->m_BBox[1].y = v12;
      }
      if ( v13 > z )
      {
        z = v13;
        this->m_BBox[1].z = v13;
      }
      v14 = this->m_CoreDispInfo.m_pVerts;
      v15 = v14[v8 + 1].m_Vert.x;
      v16 = v14[v8 + 1].m_Vert.y;
      v17 = v14[v8 + 1].m_Vert.z;
      if ( x > v15 )
      {
        x = v14[v8 + 1].m_Vert.x;
        this->m_BBox[0].x = v15;
      }
      if ( v38 > v16 )
      {
        v38 = v16;
        this->m_BBox[0].y = v16;
      }
      if ( v36 > v17 )
      {
        v36 = v17;
        this->m_BBox[0].z = v17;
      }
      if ( v15 > v5 )
      {
        v5 = v15;
        this->m_BBox[1].x = v15;
      }
      if ( v16 > y )
      {
        y = v16;
        this->m_BBox[1].y = v16;
      }
      if ( v17 > z )
      {
        z = v17;
        this->m_BBox[1].z = v17;
      }
      v18 = this->m_CoreDispInfo.m_pVerts;
      v19 = v18[v8 + 2].m_Vert.x;
      v20 = v18[v8 + 2].m_Vert.y;
      v21 = v18[v8 + 2].m_Vert.z;
      if ( x > v19 )
      {
        x = v18[v8 + 2].m_Vert.x;
        this->m_BBox[0].x = v19;
      }
      if ( v38 > v20 )
      {
        v38 = v20;
        this->m_BBox[0].y = v20;
      }
      if ( v36 > v21 )
      {
        v36 = v21;
        this->m_BBox[0].z = v21;
      }
      if ( v19 > v5 )
      {
        v5 = v19;
        this->m_BBox[1].x = v19;
      }
      if ( v20 > y )
      {
        y = v20;
        this->m_BBox[1].y = v20;
      }
      if ( v21 > z )
      {
        z = v21;
        this->m_BBox[1].z = v21;
      }
      v22 = this->m_CoreDispInfo.m_pVerts;
      v23 = v22[v8 + 3].m_Vert.x;
      v24 = v22[v8 + 3].m_Vert.y;
      v25 = v22[v8 + 3].m_Vert.z;
      if ( x > v23 )
      {
        x = v22[v8 + 3].m_Vert.x;
        this->m_BBox[0].x = v23;
      }
      if ( v38 > v24 )
      {
        v38 = v24;
        this->m_BBox[0].y = v24;
      }
      if ( v36 > v25 )
      {
        v36 = v25;
        this->m_BBox[0].z = v25;
      }
      if ( v23 > v5 )
      {
        v5 = v23;
        this->m_BBox[1].x = v23;
      }
      if ( v24 > y )
      {
        y = v24;
        this->m_BBox[1].y = v24;
      }
      if ( v25 > z )
      {
        z = v25;
        this->m_BBox[1].z = v25;
      }
      v8 += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  if ( v3 < v2 )
  {
    v26 = this->m_BBox[0].x;
    v27 = this->m_BBox[1].x;
    v28 = this->m_BBox[1].y;
    v29 = this->m_BBox[1].z;
    v37 = this->m_BBox[0].y;
    v30 = v3;
    v39 = this->m_BBox[0].z;
    v31 = v2 - v3;
    do
    {
      v32 = this->m_CoreDispInfo.m_pVerts;
      v33 = v32[v30].m_Vert.x;
      v34 = v32[v30].m_Vert.y;
      v35 = v32[v30].m_Vert.z;
      if ( v26 > v33 )
      {
        v26 = v32[v30].m_Vert.x;
        this->m_BBox[0].x = v33;
      }
      if ( v37 > v34 )
      {
        v37 = v34;
        this->m_BBox[0].y = v34;
      }
      if ( v39 > v35 )
      {
        v39 = v35;
        this->m_BBox[0].z = v35;
      }
      if ( v33 > v27 )
      {
        v27 = v33;
        this->m_BBox[1].x = v33;
      }
      if ( v34 > v28 )
      {
        v28 = v34;
        this->m_BBox[1].y = v34;
      }
      if ( v35 > v29 )
      {
        v29 = v35;
        this->m_BBox[1].z = v35;
      }
      ++v30;
      --v31;
    }
    while ( v31 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115A00
// Name: public: void CMapDisp::PostLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::PostLoad(CMapDisp *this)
{
  int v2; // edx
  int v3; // esi
  float *i; // ecx
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  int v11; // edx
  float *p_z; // eax
  unsigned int v13; // ecx
  float *v14; // eax
  int v15; // esi
  Vector vNormal; // [esp+8h] [ebp-Ch] BYREF

  v2 = 0;
  v3 = ((1 << this->m_CoreDispInfo.m_Power) + 1) * ((1 << this->m_CoreDispInfo.m_Power) + 1);
  if ( v3 > 0 )
  {
    for ( i = &this->m_CoreDispInfo.m_pVerts->m_SubdivNormal.z; *(i - 2) != 0.0 || *(i - 1) != 0.0 || *i != 0.0; i += 56 )
    {
      if ( ++v2 >= v3 )
        return;
    }
    v5 = this->m_CoreDispInfo.m_Surf.m_Points[3].y - this->m_CoreDispInfo.m_Surf.m_Points[0].y;
    v6 = this->m_CoreDispInfo.m_Surf.m_Points[1].z - this->m_CoreDispInfo.m_Surf.m_Points[0].z;
    v7 = this->m_CoreDispInfo.m_Surf.m_Points[3].x - this->m_CoreDispInfo.m_Surf.m_Points[0].x;
    v8 = this->m_CoreDispInfo.m_Surf.m_Points[3].z - this->m_CoreDispInfo.m_Surf.m_Points[0].z;
    v9 = this->m_CoreDispInfo.m_Surf.m_Points[1].x - this->m_CoreDispInfo.m_Surf.m_Points[0].x;
    v10 = this->m_CoreDispInfo.m_Surf.m_Points[1].y - this->m_CoreDispInfo.m_Surf.m_Points[0].y;
    vNormal.x = (float)(v5 * v6) - (float)(v8 * v10);
    vNormal.y = (float)(v8 * v9) - (float)(v6 * v7);
    vNormal.z = (float)(v7 * v10) - (float)(v5 * v9);
    VectorNormalize(vec: &vNormal);
    v11 = 0;
    if ( v3 >= 4 )
    {
      p_z = &this->m_CoreDispInfo.m_pVerts->m_SubdivNormal.z;
      v13 = ((unsigned int)(v3 - 4) >> 2) + 1;
      v11 = 4 * v13;
      do
      {
        *(Vector *)(p_z - 2) = vNormal;
        *((Vector *)p_z + 18) = vNormal;
        *(Vector *)(p_z + 110) = vNormal;
        *(Vector *)(p_z + 166) = vNormal;
        p_z += 224;
        --v13;
      }
      while ( v13 != 0 );
    }
    if ( v11 < v3 )
    {
      v14 = &this->m_CoreDispInfo.m_pVerts[v11].m_SubdivNormal.z;
      v15 = v3 - v11;
      do
      {
        *(Vector *)(v14 - 2) = vNormal;
        v14 += 56;
        --v15;
      }
      while ( v15 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115C00
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispDistancesKeyCallback(char const __near *,char const __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispDistancesKeyCallback(
        const char *szKey,
        const char *szValue,
        CMapDisp *pDisp)
{
  int m_Power; // esi
  int v4; // ebx
  const char *v5; // eax
  int v6; // esi
  char szBuf[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  if ( v5 != nullptr )
  {
    v6 = v4 * ((1 << m_Power) + 1);
    do
    {
      pDisp->m_CoreDispInfo.m_pVerts[v6].m_FieldDistance = atof(nptr: v5);
      v5 = strtok(string: nullptr, control: " ");
      ++v6;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x10115CC0
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispOffsetsKeyCallback(char const __near *,char const __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispOffsetsKeyCallback(const char *szKey, const char *szValue, CMapDisp *pDisp)
{
  const char *v3; // esi
  const char *v4; // edi
  const char *v5; // ebx
  long double v6; // st7
  float *v7; // eax
  char *v8; // eax
  char szBuf[1024]; // [esp+4h] [ebp-414h] BYREF
  Vector subdivVector; // [esp+404h] [ebp-14h]
  int nRow; // [esp+410h] [ebp-8h]
  int m_Power; // [esp+414h] [ebp-4h]

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  m_Power = pDisp->m_CoreDispInfo.m_Power;
  nRow = atoi(nptr: szKey + 3);
  v3 = strtok(string: szBuf, control: " ");
  v4 = strtok(string: nullptr, control: " ");
  v5 = strtok(string: nullptr, control: " ");
  if ( v3 != nullptr )
  {
    m_Power = 224 * nRow * ((1 << m_Power) + 1);
    do
    {
      if ( v4 == nullptr )
        break;
      if ( v5 == nullptr )
        break;
      subdivVector.x = atof(nptr: v3);
      subdivVector.y = atof(nptr: v4);
      v6 = atof(nptr: v5);
      v7 = (float *)((char *)&pDisp->m_CoreDispInfo.m_pVerts->m_SubdivPos.x + m_Power);
      *v7 = subdivVector.x;
      v7[1] = subdivVector.y;
      v7[2] = v6;
      v3 = strtok(string: nullptr, control: " ");
      v4 = strtok(string: nullptr, control: " ");
      v8 = strtok(string: nullptr, control: " ");
      m_Power += 224;
      v5 = v8;
    }
    while ( v3 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x10115DF0
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispOffsetNormalsKeyCallback(char const __near *,char const __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispOffsetNormalsKeyCallback(
        const char *szKey,
        const char *szValue,
        CMapDisp *pDisp)
{
  const char *v3; // esi
  const char *v4; // edi
  const char *v5; // ebx
  long double v6; // st7
  float *v7; // eax
  char *v8; // eax
  char szBuf[1024]; // [esp+4h] [ebp-414h] BYREF
  Vector normalVector; // [esp+404h] [ebp-14h]
  int nRow; // [esp+410h] [ebp-8h]
  int m_Power; // [esp+414h] [ebp-4h]

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  m_Power = pDisp->m_CoreDispInfo.m_Power;
  nRow = atoi(nptr: szKey + 3);
  v3 = strtok(string: szBuf, control: " ");
  v4 = strtok(string: nullptr, control: " ");
  v5 = strtok(string: nullptr, control: " ");
  if ( v3 != nullptr )
  {
    m_Power = 224 * nRow * ((1 << m_Power) + 1);
    do
    {
      if ( v4 == nullptr )
        break;
      if ( v5 == nullptr )
        break;
      normalVector.x = atof(nptr: v3);
      normalVector.y = atof(nptr: v4);
      v6 = atof(nptr: v5);
      v7 = (float *)((char *)&pDisp->m_CoreDispInfo.m_pVerts->m_SubdivNormal.x + m_Power);
      *v7 = normalVector.x;
      v7[1] = normalVector.y;
      v7[2] = v6;
      v3 = strtok(string: nullptr, control: " ");
      v4 = strtok(string: nullptr, control: " ");
      v8 = strtok(string: nullptr, control: " ");
      m_Power += 224;
      v5 = v8;
    }
    while ( v3 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x10115F20
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispKeyCallback(char const __near *,char const __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispKeyCallback(const char *szKey, const char *szValue, CMapDisp *pDisp)
{
  float v4; // xmm0_4
  float x; // xmm0_4
  Vector startPosition; // [esp+4h] [ebp-10h] BYREF
  int bSubdivided; // [esp+10h] [ebp-4h] BYREF

  if ( _V_stricmp(s1: szKey, s2: "power") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "uaxis") != 0 )
    {
      if ( _V_stricmp(s1: szKey, s2: "vaxis") != 0 )
      {
        if ( _V_stricmp(s1: szKey, s2: "startposition") != 0 )
        {
          if ( _V_stricmp(s1: szKey, s2: "flags") != 0 )
          {
            if ( _V_stricmp(s1: szKey, s2: "elevation") != 0 )
            {
              if ( _V_stricmp(s1: szKey, s2: "subdiv") == 0 )
              {
                CChunkFile::ReadKeyValueInt(pszValue: szValue, nInt: &bSubdivided);
                pDisp->m_bSubdiv = bSubdivided != 0;
              }
              return ChunkFile_Ok;
            }
            else
            {
              CChunkFile::ReadKeyValueFloat(pszValue: szValue, flFloat: (float *)&bSubdivided);
              LODWORD(pDisp->m_CoreDispInfo.m_Elevation) = bSubdivided;
              return ChunkFile_Ok;
            }
          }
          else
          {
            CChunkFile::ReadKeyValueInt(pszValue: szValue, nInt: &bSubdivided);
            pDisp->m_CoreDispInfo.m_Surf.m_Flags = bSubdivided;
            return ChunkFile_Ok;
          }
        }
        else
        {
          CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &startPosition);
          pDisp->m_CoreDispInfo.m_Surf.m_PointStart = startPosition;
          return ChunkFile_Ok;
        }
      }
      else
      {
        CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &startPosition);
        x = startPosition.x;
        pDisp->m_bHasMappingAxes = true;
        pDisp->m_MapAxes[1].x = x;
        pDisp->m_MapAxes[1].y = startPosition.y;
        pDisp->m_MapAxes[1].z = startPosition.z;
        return ChunkFile_Ok;
      }
    }
    else
    {
      CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &startPosition);
      v4 = startPosition.x;
      pDisp->m_bHasMappingAxes = true;
      pDisp->m_MapAxes[0].x = v4;
      pDisp->m_MapAxes[0].y = startPosition.y;
      pDisp->m_MapAxes[0].z = startPosition.z;
      return ChunkFile_Ok;
    }
  }
  else
  {
    CChunkFile::ReadKeyValueInt(pszValue: szValue, nInt: &bSubdivided);
    pDisp->m_CoreDispInfo.m_Power = bSubdivided;
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116110
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispAlphasKeyCallback(char const __near *,char const __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispAlphasKeyCallback(const char *szKey, const char *szValue, CMapDisp *pDisp)
{
  int m_Power; // esi
  int v4; // ebx
  const char *v5; // eax
  int v6; // esi
  char szBuf[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  if ( v5 != nullptr )
  {
    v6 = v4 * ((1 << m_Power) + 1);
    do
    {
      pDisp->m_CoreDispInfo.m_pVerts[v6].m_Alpha = atof(nptr: v5);
      v5 = strtok(string: nullptr, control: " ");
      ++v6;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x101161D0
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispMultiBlendKeyCallback(char const __near *,char const __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispMultiBlendKeyCallback(
        const char *szKey,
        const char *szValue,
        CMapDisp *pDisp)
{
  int m_Power; // esi
  int v4; // ebx
  const char *v5; // eax
  int v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  CoreDispVert_t *m_pVerts; // ecx
  float *p_x; // ecx
  char szBuf[1024]; // [esp+4h] [ebp-410h] BYREF
  Vector4D vMultiBlend; // [esp+404h] [ebp-10h]

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  if ( v5 != nullptr )
  {
    v6 = v4 * ((1 << m_Power) + 1);
    do
    {
      vMultiBlend.x = atof(nptr: v5);
      v7 = strtok(string: nullptr, control: " ");
      vMultiBlend.y = atof(nptr: v7);
      v8 = strtok(string: nullptr, control: " ");
      vMultiBlend.z = atof(nptr: v8);
      v9 = strtok(string: nullptr, control: " ");
      vMultiBlend.w = atof(nptr: v9);
      v5 = strtok(string: nullptr, control: " ");
      m_pVerts = pDisp->m_CoreDispInfo.m_pVerts;
      m_pVerts[v6].m_MultiBlend.x = vMultiBlend.x;
      p_x = &m_pVerts[v6].m_MultiBlend.x;
      p_x[1] = vMultiBlend.y;
      ++v6;
      p_x[2] = vMultiBlend.z;
      p_x[3] = vMultiBlend.w;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x101162F0
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispAlphaBlendKeyCallback(char const __near *,char const __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispAlphaBlendKeyCallback(
        const char *szKey,
        const char *szValue,
        CMapDisp *pDisp)
{
  int m_Power; // esi
  int v4; // ebx
  const char *v5; // eax
  int v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  CoreDispVert_t *m_pVerts; // ecx
  float *p_x; // ecx
  char szBuf[1024]; // [esp+4h] [ebp-410h] BYREF
  Vector4D vMultiBlend; // [esp+404h] [ebp-10h]

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  if ( v5 != nullptr )
  {
    v6 = v4 * ((1 << m_Power) + 1);
    do
    {
      vMultiBlend.x = atof(nptr: v5);
      v7 = strtok(string: nullptr, control: " ");
      vMultiBlend.y = atof(nptr: v7);
      v8 = strtok(string: nullptr, control: " ");
      vMultiBlend.z = atof(nptr: v8);
      v9 = strtok(string: nullptr, control: " ");
      vMultiBlend.w = atof(nptr: v9);
      v5 = strtok(string: nullptr, control: " ");
      m_pVerts = pDisp->m_CoreDispInfo.m_pVerts;
      m_pVerts[v6].m_AlphaBlend.x = vMultiBlend.x;
      p_x = &m_pVerts[v6].m_AlphaBlend.x;
      p_x[1] = vMultiBlend.y;
      ++v6;
      p_x[2] = vMultiBlend.z;
      p_x[3] = vMultiBlend.w;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x10116410
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispMultiBlendColorKeyCallback(char const __near *,char const __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispMultiBlendColorKeyCallback(
        const char *szKey,
        const char *szValue,
        CMapDisp *pDisp)
{
  int m_Power; // esi
  int v4; // ebx
  const char *v5; // eax
  int v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  char szBuf[1024]; // [esp+4h] [ebp-40Ch] BYREF
  Vector vMultiBlendColor; // [esp+404h] [ebp-Ch]

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  if ( v5 != nullptr )
  {
    v6 = 224 * v4 * ((1 << m_Power) + 1);
    do
    {
      vMultiBlendColor.x = atof(nptr: v5);
      v7 = strtok(string: nullptr, control: " ");
      vMultiBlendColor.y = atof(nptr: v7);
      v8 = strtok(string: nullptr, control: " ");
      vMultiBlendColor.z = atof(nptr: v8);
      v5 = strtok(string: nullptr, control: " ");
      *(Vector *)((char *)&pDisp->m_CoreDispInfo.m_pVerts->m_vBlendColors[nMultiBlendColorIndex] + v6) = vMultiBlendColor;
      v6 += 224;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x10116520
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispTriangleTagsKeyCallback(char const __near *,char const __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispTriangleTagsKeyCallback(
        const char *szKey,
        const char *szValue,
        CMapDisp *pDisp)
{
  int m_Power; // esi
  int v4; // ebx
  const char *v5; // eax
  int v6; // esi
  char szBuf[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  if ( v5 != nullptr )
  {
    v6 = 2 * v4 * (1 << m_Power);
    do
    {
      pDisp->m_CoreDispInfo.m_pTris[v6].m_uiTags = atoi(nptr: v5);
      v5 = strtok(string: nullptr, control: " ");
      ++v6;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x101165E0
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispNormalsKeyCallback(char const __near *,char const __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispNormalsKeyCallback(const char *szKey, const char *szValue, CMapDisp *pDisp)
{
  const char *v3; // esi
  const char *v4; // edi
  const char *v5; // ebx
  long double v6; // st7
  float *v7; // eax
  char *v8; // eax
  char szBuf[1024]; // [esp+4h] [ebp-414h] BYREF
  Vector vectorFieldVector; // [esp+404h] [ebp-14h]
  int nRow; // [esp+410h] [ebp-8h]
  int m_Power; // [esp+414h] [ebp-4h]

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  m_Power = pDisp->m_CoreDispInfo.m_Power;
  nRow = atoi(nptr: szKey + 3);
  v3 = strtok(string: szBuf, control: " ");
  v4 = strtok(string: nullptr, control: " ");
  v5 = strtok(string: nullptr, control: " ");
  if ( v3 != nullptr )
  {
    m_Power = 224 * nRow * ((1 << m_Power) + 1);
    do
    {
      if ( v4 == nullptr )
        break;
      if ( v5 == nullptr )
        break;
      vectorFieldVector.x = atof(nptr: v3);
      vectorFieldVector.y = atof(nptr: v4);
      v6 = atof(nptr: v5);
      v7 = (float *)((char *)&pDisp->m_CoreDispInfo.m_pVerts->m_FieldVector.x + m_Power);
      *v7 = vectorFieldVector.x;
      v7[1] = vectorFieldVector.y;
      v7[2] = v6;
      v3 = strtok(string: nullptr, control: " ");
      v4 = strtok(string: nullptr, control: " ");
      v8 = strtok(string: nullptr, control: " ");
      m_Power += 224;
      v5 = v8;
    }
    while ( v3 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x10116710
// Name: public: void CMapDisp::Paint_Init(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::Paint_Init(CMapDisp *this, int nType)
{
  int v3; // esi
  int v4; // ecx
  int v5; // esi
  float *p_z; // eax

  this->m_Canvas.m_nType = nType;
  this->m_Canvas.m_bDirty = false;
  v3 = 1 << this->m_CoreDispInfo.m_Power;
  v4 = 0;
  v5 = (v3 + 1) * (v3 + 1);
  if ( v5 > 0 )
  {
    p_z = &this->m_Canvas.m_Values[0].z;
    do
    {
      *(p_z - 2) = 0.0;
      *(p_z - 1) = 0.0;
      *p_z = 0.0;
      this->m_Canvas.m_bValuesDirty[v4++] = false;
      p_z += 3;
    }
    while ( v4 < v5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116780
// Name: public: void CMapDisp::Paint_SetValue(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::Paint_SetValue(CMapDisp *this, int iVert, const Vector *vPaint)
{
  this->m_Canvas.m_Values[iVert] = *vPaint;
  this->m_Canvas.m_bValuesDirty[iVert] = true;
  this->m_Canvas.m_bDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x101167C0
// Name: private: void CMapDisp::PaintPosition_Update(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::PaintPosition_Update(CMapDisp *this, int iVert)
{
  CoreDispVert_t *m_pVerts; // eax
  int v4; // edi
  float z; // xmm3_4
  float y; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float m_Elevation; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  double v17; // st7
  Vector vNormal; // [esp+8h] [ebp-18h] BYREF
  Vector vSeg; // [esp+14h] [ebp-Ch] BYREF
  float elev; // [esp+28h] [ebp+8h]

  m_pVerts = this->m_CoreDispInfo.m_pVerts;
  v4 = iVert;
  z = m_pVerts[iVert].m_FlatVert.z;
  y = m_pVerts[iVert].m_SubdivPos.y;
  v7 = m_pVerts[iVert].m_SubdivPos.z;
  v8 = this->m_Canvas.m_Values[iVert].y - m_pVerts[iVert].m_FlatVert.y;
  v9 = this->m_Canvas.m_Values[iVert].z;
  vSeg.x = (float)(this->m_Canvas.m_Values[iVert].x - m_pVerts[iVert].m_FlatVert.x) - m_pVerts[iVert].m_SubdivPos.x;
  m_Elevation = this->m_CoreDispInfo.m_Elevation;
  vSeg.y = v8 - y;
  vSeg.z = (float)(v9 - z) - v7;
  elev = m_Elevation;
  if ( m_Elevation != 0.0 )
  {
    v11 = this->m_CoreDispInfo.m_Surf.m_Points[3].y - this->m_CoreDispInfo.m_Surf.m_Points[0].y;
    v12 = this->m_CoreDispInfo.m_Surf.m_Points[3].z - this->m_CoreDispInfo.m_Surf.m_Points[0].z;
    v13 = this->m_CoreDispInfo.m_Surf.m_Points[1].y - this->m_CoreDispInfo.m_Surf.m_Points[0].y;
    v14 = this->m_CoreDispInfo.m_Surf.m_Points[1].z - this->m_CoreDispInfo.m_Surf.m_Points[0].z;
    v15 = this->m_CoreDispInfo.m_Surf.m_Points[3].x - this->m_CoreDispInfo.m_Surf.m_Points[0].x;
    v16 = this->m_CoreDispInfo.m_Surf.m_Points[1].x - this->m_CoreDispInfo.m_Surf.m_Points[0].x;
    vNormal.x = (float)(v11 * v14) - (float)(v12 * v13);
    vNormal.y = (float)(v12 * v16) - (float)(v15 * v14);
    vNormal.z = (float)(v15 * v13) - (float)(v11 * v16);
    VectorNormalize(vec: &vNormal);
    vSeg.y = vSeg.y - (float)(vNormal.y * elev);
    vSeg.x = vSeg.x - (float)(vNormal.x * elev);
    vSeg.z = vSeg.z - (float)(vNormal.z * elev);
  }
  v17 = VectorNormalize(vec: &vSeg);
  this->m_CoreDispInfo.m_pVerts[v4].m_FieldVector = vSeg;
  this->m_CoreDispInfo.m_pVerts[v4].m_FieldDistance = v17;
}

//------------------------------------------------------------------------------
// Address: 0x10116980
// Name: public: void CMapDisp::UpdateVertPositionForSubdiv(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::UpdateVertPositionForSubdiv(CMapDisp *this, int iVert, const Vector *vecNewSubdivPos)
{
  int v3; // edi
  CoreDispVert_t *m_pVerts; // eax
  float x; // xmm3_4
  float y; // xmm4_4
  float v8; // xmm1_4
  float z; // xmm5_4
  float v10; // xmm2_4
  float m_Elevation; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  double v20; // st7
  CoreDispVert_t *v21; // ecx
  float v22; // xmm6_4
  Vector *p_m_Vert; // eax
  float v24; // xmm1_4
  float v25; // xmm2_4
  float vecFlatPos; // [esp+14h] [ebp-28h]
  float vecFlatPos_4; // [esp+18h] [ebp-24h]
  float vecFlatPos_8; // [esp+1Ch] [ebp-20h]
  Vector vecSegment1; // [esp+20h] [ebp-1Ch] BYREF
  Vector vecFaceNormal; // [esp+2Ch] [ebp-10h] BYREF
  float flDistance; // [esp+38h] [ebp-4h]
  float flElevation; // [esp+44h] [ebp+8h]

  v3 = iVert;
  m_pVerts = this->m_CoreDispInfo.m_pVerts;
  x = m_pVerts[iVert].m_FlatVert.x;
  y = m_pVerts[iVert].m_FlatVert.y;
  v8 = m_pVerts[iVert].m_Vert.y - m_pVerts[iVert].m_SubdivPos.y;
  z = m_pVerts[iVert].m_FlatVert.z;
  v10 = m_pVerts[iVert].m_Vert.z - m_pVerts[iVert].m_SubdivPos.z;
  vecSegment1.x = (float)(m_pVerts[iVert].m_Vert.x - m_pVerts[iVert].m_SubdivPos.x) - x;
  vecSegment1.y = v8 - y;
  m_Elevation = this->m_CoreDispInfo.m_Elevation;
  vecFlatPos = x;
  vecFlatPos_4 = y;
  vecFlatPos_8 = z;
  vecSegment1.z = v10 - z;
  flElevation = m_Elevation;
  memset(&vecFaceNormal, 0, sizeof(vecFaceNormal));
  if ( m_Elevation != 0.0 )
  {
    v12 = this->m_CoreDispInfo.m_Surf.m_Points[3].y - this->m_CoreDispInfo.m_Surf.m_Points[0].y;
    v13 = this->m_CoreDispInfo.m_Surf.m_Points[3].z - this->m_CoreDispInfo.m_Surf.m_Points[0].z;
    v14 = this->m_CoreDispInfo.m_Surf.m_Points[1].y - this->m_CoreDispInfo.m_Surf.m_Points[0].y;
    v15 = this->m_CoreDispInfo.m_Surf.m_Points[1].z - this->m_CoreDispInfo.m_Surf.m_Points[0].z;
    v16 = this->m_CoreDispInfo.m_Surf.m_Points[3].x - this->m_CoreDispInfo.m_Surf.m_Points[0].x;
    v17 = this->m_CoreDispInfo.m_Surf.m_Points[1].x - this->m_CoreDispInfo.m_Surf.m_Points[0].x;
    vecFaceNormal.x = (float)(v12 * v15) - (float)(v13 * v14);
    vecFaceNormal.y = (float)(v13 * v17) - (float)(v16 * v15);
    vecFaceNormal.z = (float)(v16 * v14) - (float)(v12 * v17);
    VectorNormalize(vec: &vecFaceNormal);
    v18 = vecSegment1.x - (float)(vecFaceNormal.x * flElevation);
    vecFaceNormal.x = vecFaceNormal.x * flElevation;
    vecSegment1.y = vecSegment1.y - (float)(vecFaceNormal.y * flElevation);
    v19 = vecSegment1.z - (float)(vecFaceNormal.z * flElevation);
    vecFaceNormal.y = vecFaceNormal.y * flElevation;
    vecFaceNormal.z = vecFaceNormal.z * flElevation;
    vecSegment1.x = v18;
    vecSegment1.z = v19;
  }
  v20 = VectorNormalize(vec: &vecSegment1);
  flDistance = v20;
  this->m_CoreDispInfo.m_pVerts[v3].m_FieldVector = vecSegment1;
  this->m_CoreDispInfo.m_pVerts[v3].m_FieldDistance = v20;
  v21 = this->m_CoreDispInfo.m_pVerts;
  v21[v3].m_SubdivPos.x = vecNewSubdivPos->x;
  v22 = flDistance;
  v21[v3].m_SubdivPos.y = vecNewSubdivPos->y;
  v21[v3].m_SubdivPos.z = vecNewSubdivPos->z;
  p_m_Vert = &this->m_CoreDispInfo.m_pVerts[v3].m_Vert;
  v24 = (float)(vecSegment1.y * v22)
      + (float)(vecNewSubdivPos->y + (float)(vecFlatPos_4 + (float)(vecFaceNormal.y * flElevation)));
  v25 = (float)(vecSegment1.z * v22)
      + (float)(vecNewSubdivPos->z + (float)(vecFlatPos_8 + (float)(vecFaceNormal.z * flElevation)));
  p_m_Vert->x = (float)(vecSegment1.x * v22)
              + (float)(vecNewSubdivPos->x + (float)((float)(vecFaceNormal.x * flElevation) + vecFlatPos));
  p_m_Vert->y = v24;
  p_m_Vert->z = v25;
}

//------------------------------------------------------------------------------
// Address: 0x10116C10
// Name: public: static void CMapDisp::SetSelectMask(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapDisp::SetSelectMask(bool bSelectMask)
{
  CMapDisp::m_bSelectMask = bSelectMask;
}

//------------------------------------------------------------------------------
// Address: 0x10116C20
// Name: public: static void CMapDisp::SetGridMask(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapDisp::SetGridMask(bool bGridMask)
{
  CMapDisp::m_bGridMask = bGridMask;
}

//------------------------------------------------------------------------------
// Address: 0x10116C30
// Name: public: class std::istreambuf_iterator<char,struct std::char_traits<char>> std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::get(class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::ios_base __near &,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::num_get<char,std::istreambuf_iterator<char>>::get(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        std::istreambuf_iterator<char> *result,
        std::istreambuf_iterator<char> _First,
        std::istreambuf_iterator<char> _Last,
        std::ios_base *_Iosbase,
        int *_State,
        float *_Val)
{
  ((void (__thiscall *)(std::num_get<char,std::istreambuf_iterator<char> > *, std::istreambuf_iterator<char> *, std::streambuf *, _DWORD, std::streambuf *, _DWORD, std::ios_base *, int *, float *))this->do_get_4)(
    a1: this,
    a2: result,
    a3: _First._Strbuf,
    a4: *(_DWORD *)&_First._Got,
    a5: _Last._Strbuf,
    a6: *(_DWORD *)&_Last._Got,
    a7: _Iosbase,
    a8: _State,
    a9: _Val);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10116C70
// Name: public: bool CMapDisp::TraceLineSnapTo(class Vector __near &,class Vector __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CMapDisp::TraceLineSnapTo@<al>(
        CMapDisp *this@<ecx>,
        float a2@<ebp>,
        Vector *HitPos,
        Vector *HitNormal,
        const Vector *RayStart,
        const Vector *RayEnd)
{
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v9; // xmm0_4
  int m_Power; // ecx
  float v11; // xmm0_4
  int v12; // edi
  float v13; // xmm1_4
  int v14; // esi
  float v15; // xmm2_4
  CoreDispVert_t *m_pVerts; // ecx
  CoreDispVert_t *v17; // eax
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  int v26; // esi
  int v27; // ecx
  CoreDispVert_t *v28; // eax
  float v29; // xmm0_4
  int v30; // eax
  int v31; // esi
  int v32; // edi
  CoreDispVert_t *v33; // eax
  int v34; // eax
  int v35; // esi
  CoreDispVert_t *v36; // ecx
  int v37; // eax
  float v38; // xmm0_4
  CoreDispVert_t *v39; // eax
  _DWORD v40[3]; // [esp-Ch] [ebp-9Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-90h]
  CMapDisp *v42; // [esp+50h] [ebp-40h]
  int v43; // [esp+54h] [ebp-3Ch]
  float v44; // [esp+58h] [ebp-38h] BYREF
  float v45; // [esp+5Ch] [ebp-34h] BYREF
  Vector ndx; // [esp+60h] [ebp-30h] OVERLAPPED BYREF
  CMapDisp::Tri_t tri; // [esp+6Ch] [ebp-24h] BYREF
  float retaddr; // [esp+90h] [ebp+0h]

  tri.v[2].x = a2;
  tri.v[2].y = retaddr;
  x = RayStart->x;
  y = RayStart->y;
  z = RayStart->z;
  v9 = RayEnd->x;
  v42 = this;
  m_Power = this->m_CoreDispInfo.m_Power;
  v11 = v9 - x;
  *(float *)v40 = x;
  v12 = (1 << m_Power) + 1;
  v13 = RayEnd->y - y;
  *(float *)&v40[1] = y;
  v14 = 0;
  v15 = RayEnd->z - z;
  *(_DWORD *)(&ray.m_IsSwept + 7) = v12;
  ray.m_Extents.y = 0.0;
  *(float *)&v40[2] = z;
  ray.m_Start.y = v11;
  ray.m_Start.z = v13;
  ray.m_Start.w = v15;
  LOBYTE(ray.m_Extents.z) = 1;
  if ( 1 << m_Power > 0 )
  {
    do
    {
      m_pVerts = v42->m_CoreDispInfo.m_pVerts;
      v17 = &m_pVerts[v14];
      ndx = v17->m_Vert;
      tri.v[0] = m_pVerts[v14 + v12].m_Vert;
      tri.v[1] = v17[1].m_Vert;
      ComputeIntersectionBarycentricCoordinates(
        ray: (const Ray_t *)v40,
        v1: &ndx,
        v2: tri.v,
        v3: &tri.v[1],
        u: &v44,
        v: &v45,
        t: nullptr);
      v18 = v45;
      if ( v45 >= -0.1 && v45 <= 1.1 )
      {
        v19 = 0.0;
        if ( v44 < 0.0 )
          goto LABEL_5;
      }
      if ( v14 == 0 && v45 < 0.0 && v44 < 0.0 )
      {
LABEL_16:
        *HitPos = ndx;
        return 1;
      }
    }
    while ( ++v14 < v12 - 1 );
  }
  v26 = 0;
  v43 = 0;
  if ( v12 - 1 > 0 )
  {
    v27 = 224 * v12;
    *(_DWORD *)&ray.m_IsRay = 224 * v12;
    for ( *(_DWORD *)(&ray.m_IsSwept + 3) = 224 * v12; ; v27 = *(_DWORD *)(&ray.m_IsSwept + 3) )
    {
      v28 = v42->m_CoreDispInfo.m_pVerts;
      ndx = *(Vector *)((char *)&v28->m_Vert + v26);
      tri.v[0] = *(Vector *)((char *)&v28->m_Vert + v27);
      tri.v[1] = *(Vector *)((char *)&v28[1].m_Vert + v26);
      ComputeIntersectionBarycentricCoordinates(
        ray: (const Ray_t *)v40,
        v1: &ndx,
        v2: tri.v,
        v3: &tri.v[1],
        u: &v44,
        v: &v45,
        t: nullptr);
      v29 = v44;
      if ( v44 >= -0.1 && v44 <= 1.1 )
      {
        v19 = 0.0;
        if ( v45 < 0.0 )
          break;
      }
      v30 = v43;
      if ( v43 == v12 - 2 && v44 > 1.0 && v45 < 0.0 )
      {
LABEL_35:
        *HitPos = tri.v[0];
        return 1;
      }
      *(_DWORD *)(&ray.m_IsSwept + 3) += *(_DWORD *)&ray.m_IsRay;
      v26 += *(_DWORD *)&ray.m_IsRay;
      ++v43;
      if ( v30 + 1 >= v12 - 1 )
        goto LABEL_29;
    }
    goto LABEL_21;
  }
LABEL_29:
  v43 = 0;
  if ( v12 - 1 > 0 )
  {
    v31 = v12 * (v12 - 1);
    v32 = *(_DWORD *)(&ray.m_IsSwept + 7) * (v12 - 2);
    while ( 1 )
    {
      v33 = v42->m_CoreDispInfo.m_pVerts;
      ndx = v33[v31 + 1].m_Vert;
      tri.v[0] = v33[v32 + 1].m_Vert;
      tri.v[1] = v33[v31].m_Vert;
      ComputeIntersectionBarycentricCoordinates(
        ray: (const Ray_t *)v40,
        v1: &ndx,
        v2: tri.v,
        v3: &tri.v[1],
        u: &v44,
        v: &v45,
        t: nullptr);
      v18 = v45;
      if ( v45 >= -0.1 && v45 <= 1.1 )
      {
        v19 = 0.0;
        if ( v44 < 0.0 )
          break;
      }
      v34 = v43;
      if ( v43 == *(_DWORD *)(&ray.m_IsSwept + 7) - 2 && v45 < 0.0 && v44 < 0.0 )
        goto LABEL_16;
      ++v32;
      ++v31;
      ++v43;
      if ( v34 + 1 >= *(_DWORD *)(&ray.m_IsSwept + 7) - 1 )
      {
        v12 = *(_DWORD *)(&ray.m_IsSwept + 7);
        goto LABEL_41;
      }
    }
LABEL_5:
    if ( v18 >= 0.0 )
    {
      v19 = 1.0;
      if ( v18 <= 1.0 )
        v19 = v18;
    }
    v20 = tri.v[1].x;
    v21 = tri.v[1].y;
    v22 = tri.v[1].z;
LABEL_9:
    v23 = (float)((float)(v21 - ndx.y) * v19) + ndx.y;
    v24 = (float)((float)(v22 - ndx.z) * v19) + ndx.z;
    HitPos->x = (float)((float)(v20 - ndx.x) * v19) + ndx.x;
    HitPos->y = v23;
    HitPos->z = v24;
    return 1;
  }
LABEL_41:
  v35 = 0;
  if ( v12 - 1 > 0 )
  {
    while ( 1 )
    {
      v36 = v42->m_CoreDispInfo.m_pVerts;
      v37 = v12 * (v35 + 2);
      v38 = v36[v37 - 1].m_Vert.x;
      v39 = &v36[v37];
      ndx.x = v38;
      ndx.y = v39[-1].m_Vert.y;
      ndx.z = v39[-1].m_Vert.z;
      tri.v[0] = v36[v12 * (v35 + 1) - 1].m_Vert;
      tri.v[1] = v39[-2].m_Vert;
      ComputeIntersectionBarycentricCoordinates(
        ray: (const Ray_t *)v40,
        v1: &ndx,
        v2: tri.v,
        v3: &tri.v[1],
        u: &v44,
        v: &v45,
        t: nullptr);
      v29 = v44;
      if ( v44 >= -0.1 && v44 <= 1.1 )
      {
        v19 = 0.0;
        if ( v45 < 0.0 )
          break;
      }
      if ( v35 == 0 && v44 > 1.0 && v45 < 0.0 )
        goto LABEL_35;
      if ( ++v35 >= v12 - 1 )
        return 0;
    }
LABEL_21:
    if ( v29 >= 0.0 )
    {
      v19 = 1.0;
      if ( v29 <= 1.0 )
        v19 = v29;
    }
    v20 = tri.v[0].x;
    v21 = tri.v[0].y;
    v22 = tri.v[0].z;
    goto LABEL_9;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10117290
// Name: public: void CMapDisp::CreateShoreOverlays(class CMapFace __near *,struct Shoreline_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapDisp::CreateShoreOverlays(CMapDisp *this, CMapFace *pFace, Shoreline_t *pShoreline)
{
  CMapAtom *(__thiscall *GetParent)(struct CMapFace *); // edx
  CMapClass *v5; // eax
  int v6; // ebx
  int z_low; // ecx
  CoreDispVert_t *m_pVerts; // eax
  int z_high; // edx
  float x; // xmm6_4
  int p_m_Vert; // ecx
  float z; // xmm2_4
  float *p_x; // eax
  float v14; // xmm5_4
  float v15; // xmm0_4
  float dist; // xmm0_4
  float v17; // xmm5_4
  float y; // xmm6_4
  float v19; // xmm4_4
  int v20; // xmm0_4
  float v21; // xmm5_4
  float v22; // xmm2_4
  int v23; // ecx
  float *p_z; // eax
  float v25; // xmm3_4
  Vector maxs; // [esp+14h] [ebp-D4h] BYREF
  Vector mins; // [esp+20h] [ebp-C8h] BYREF
  Vector2D pIntersection; // [esp+2Ch] [ebp-BCh] BYREF
  float v29; // [esp+34h] [ebp-B4h]
  float v30; // [esp+38h] [ebp-B0h]
  Vector2D vecIntersect[2]; // [esp+3Ch] [ebp-ACh] BYREF
  Vector4D plane; // [esp+4Ch] [ebp-9Ch] BYREF
  _BYTE vecDispMax[20]; // [esp+5Ch] [ebp-8Ch] OVERLAPPED BYREF
  Vector org; // [esp+70h] [ebp-78h] BYREF
  float v35; // [esp+7Ch] [ebp-6Ch]
  Vector v[3]; // [esp+80h] [ebp-68h] BYREF
  int nTriangleCount; // [esp+A4h] [ebp-44h] BYREF
  Vector vecEdge; // [esp+A8h] [ebp-40h] BYREF
  Vector vecNormal; // [esp+B4h] [ebp-34h] BYREF
  Vector vV; // [esp+C0h] [ebp-28h] BYREF
  Vector vecPoints[2]; // [esp+CCh] [ebp-1Ch] BYREF
  unsigned __int16 vU; // [esp+E4h] [ebp-4h] OVERLAPPED BYREF

  GetParent = pFace->GetParent;
  *(Vector *)&vecDispMax[8] = this->m_BBox[0];
  plane.x = this->m_BBox[1].x;
  plane.y = this->m_BBox[1].y;
  plane.z = this->m_BBox[1].z;
  v5 = (CMapClass *)GetParent(this: pFace);
  CMapClass::GetCullBox(this: v5, &mins, &maxs);
  if ( IsBoxIntersectingBox(
         boxMin1: (const Vector *)&vecDispMax[8],
         boxMax1: (const Vector *)&plane,
         boxMin2: &mins,
         boxMax2: &maxs) )
  {
    v6 = 0;
    for ( LODWORD(v[1].z) = 2 * (1 << this->m_CoreDispInfo.m_Power) * (1 << this->m_CoreDispInfo.m_Power);
          v6 < SLODWORD(v[1].z);
          ++v6 )
    {
      CCoreDispInfo::GetTriIndices(
        this: &this->m_CoreDispInfo,
        iTri: v6,
        v1: (unsigned __int16 *)&vecPoints[1].z,
        v2: (unsigned __int16 *)&vecPoints[1].z + 1,
        v3: &vU);
      z_low = LOWORD(vecPoints[1].z);
      m_pVerts = this->m_CoreDispInfo.m_pVerts;
      z_high = HIWORD(vecPoints[1].z);
      x = m_pVerts[z_low].m_Vert.x;
      p_m_Vert = (int)&m_pVerts[z_low].m_Vert;
      org.x = x;
      org.y = *(float *)(p_m_Vert + 4);
      org.z = *(float *)(p_m_Vert + 8);
      v35 = m_pVerts[z_high].m_Vert.x;
      v[0].x = m_pVerts[z_high].m_Vert.y;
      z = m_pVerts[z_high].m_Vert.z;
      p_x = &m_pVerts[vU].m_Vert.x;
      v[0].y = z;
      v[0].z = *p_x;
      v[1].x = p_x[1];
      v14 = p_x[2];
      vecPoints[0].z = v35 - x;
      vecIntersect[0].x = pFace->plane.normal.x;
      vecIntersect[0].y = pFace->plane.normal.y;
      v15 = pFace->plane.normal.z;
      v[1].y = v14;
      vecIntersect[1].x = v15;
      dist = pFace->plane.dist;
      vecPoints[1].x = v[0].x - org.y;
      vecPoints[1].y = z - org.z;
      vecEdge.z = v[0].z - x;
      vecNormal.x = v[1].x - org.y;
      vecNormal.y = v14 - org.z;
      vecIntersect[1].y = dist;
      if ( IntersectTriangleWithPlaneBarycentric(
             &org,
             edgeU: (Vector *)&vecPoints[0].z,
             edgeV: (Vector *)&vecEdge.z,
             plane: (const Vector4D *)vecIntersect,
             &pIntersection) == 2 )
      {
        *(float *)&vecDispMax[4] = vecNormal.y * v30;
        *(float *)vecDispMax = vecNormal.x * v30;
        vV.z = (float)((float)(vecPoints[0].z * v29) + org.x) + (float)(vecEdge.z * v30);
        vecPoints[0].x = (float)((float)(vecPoints[1].x * v29) + org.y) + (float)(vecNormal.x * v30);
        vecPoints[0].y = (float)((float)(vecPoints[1].y * v29) + org.z) + (float)(vecNormal.y * v30);
        vecNormal.z = (float)(vecEdge.z * pIntersection.y) + (float)((float)(vecPoints[0].z * pIntersection.x) + org.x);
        vV.x = (float)(vecNormal.x * pIntersection.y) + (float)((float)(vecPoints[1].x * pIntersection.x) + org.y);
        vV.y = (float)((float)(pIntersection.x * vecPoints[1].y) + org.z) + (float)(vecNormal.y * pIntersection.y);
        v[2].x = vV.z - vecNormal.z;
        v[2].y = vecPoints[0].x - vV.x;
        v[2].z = vecPoints[0].y - vV.y;
        VectorNormalize(vec: &v[2]);
        v17 = pFace->plane.normal.z;
        y = pFace->plane.normal.y;
        v19 = pFace->plane.normal.x;
        *(float *)&v20 = (float)(v[2].y * v17) - (float)(v[2].z * y);
        v21 = (float)(v[2].z * v19) - (float)(v[2].x * v17);
        v22 = (float)(v[2].x * y) - (float)(v[2].y * v19);
        nTriangleCount = v20;
        vecEdge.x = v21;
        vecEdge.y = v22;
        v23 = 0;
        p_z = &org.z;
        while ( 1 )
        {
          v25 = *(p_z - 2);
          if ( (float)((float)((float)((float)(*(p_z - 1) * v21) + (float)(v25 * *(float *)&v20)) + (float)(*p_z * v22))
                     - (float)((float)((float)(v21 * vV.x) + (float)(*(float *)&v20 * vecNormal.z)) + (float)(v22 * vV.y))) > 0.0
            && (float)((float)((float)((float)(v25 * v19) + (float)(pFace->plane.normal.y * *(p_z - 1)))
                             + (float)(*p_z * pFace->plane.normal.z))
                     - pFace->plane.dist) < 0.0 )
          {
            break;
          }
          ++v23;
          p_z += 3;
          if ( v23 >= 3 )
            goto LABEL_10;
        }
        *(float *)&nTriangleCount = -*(float *)&v20;
        vecEdge.x = -v21;
        vecEdge.y = -v22;
LABEL_10:
        if ( fabs(vecNormal.z - vV.z) > 0.1 || fabs(vV.x - vecPoints[0].x) > 0.1 || fabs(vV.y - vecPoints[0].y) > 0.1 )
          Shoreline_t::AddSegment(
            this: pShoreline,
            vecPoint0: (Vector *)&vecNormal.z,
            vecPoint1: (Vector *)&vV.z,
            vecNormal: (Vector *)&nTriangleCount,
            flWaterZ: pFace->plane.dist,
            pWaterFace: pFace,
            hDisp: this->m_EditHandle);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117780
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispDistancesCallback(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispDistancesCallback(CChunkFile *pFile, CMapDisp *pDisp)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispDistancesKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x101177A0
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispOffsetsCallback(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispOffsetsCallback(CChunkFile *pFile, CMapDisp *pDisp)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispOffsetsKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x101177C0
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispOffsetNormalsCallback(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispOffsetNormalsCallback(CChunkFile *pFile, CMapDisp *pDisp)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispOffsetNormalsKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x101177E0
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispAlphasCallback(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispAlphasCallback(CChunkFile *pFile, CMapDisp *pDisp)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispAlphasKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x10117800
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispMultiBlendCallback(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispMultiBlendCallback(CChunkFile *pFile, CMapDisp *pDisp)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispMultiBlendKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x10117820
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispAlphaBlendCallback(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispAlphaBlendCallback(CChunkFile *pFile, CMapDisp *pDisp)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispAlphaBlendKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x10117840
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispMultiBlendColorCallback0(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispMultiBlendColorCallback0(CChunkFile *pFile, CMapDisp *pDisp)
{
  nMultiBlendColorIndex = 0;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispMultiBlendColorKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x10117860
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispMultiBlendColorCallback1(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispMultiBlendColorCallback1(CChunkFile *pFile, CMapDisp *pDisp)
{
  nMultiBlendColorIndex = 1;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispMultiBlendColorKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x10117880
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispMultiBlendColorCallback2(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispMultiBlendColorCallback2(CChunkFile *pFile, CMapDisp *pDisp)
{
  nMultiBlendColorIndex = 2;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispMultiBlendColorKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x101178A0
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispMultiBlendColorCallback3(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispMultiBlendColorCallback3(CChunkFile *pFile, CMapDisp *pDisp)
{
  nMultiBlendColorIndex = 3;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispMultiBlendColorKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x101178C0
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispTriangleTagsCallback(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispTriangleTagsCallback(CChunkFile *pFile, CMapDisp *pDisp)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispTriangleTagsKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x101178E0
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispNormalsCallback(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispNormalsCallback(CChunkFile *pFile, CMapDisp *pDisp)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispNormalsKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x10117900
// Name: public: int CMapDisp::CollideWithDispTri(class Vector const __near &,class Vector const __near &,float __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CMapDisp::CollideWithDispTri@<eax>(
        CMapDisp *this@<ecx>,
        int a2@<ebp>,
        const Vector *rayStart,
        const Vector *rayEnd,
        float *flFraction,
        int OneSided)
{
  int v6; // ecx
  int v7; // eax
  float v8; // xmm0_4
  int v9; // ecx
  int v10; // edx
  float x; // xmm3_4
  int v12; // ecx
  float y; // xmm4_4
  float v14; // xmm1_4
  float z; // xmm5_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  int v18; // eax
  float v19; // xmm0_4
  double v20; // st7
  int v21; // ecx
  _DWORD v23[3]; // [esp-Ch] [ebp-ACh] BYREF
  Ray_t ray; // [esp+0h] [ebp-A0h] BYREF
  _DWORD v25[3]; // [esp+50h] [ebp-50h] BYREF
  Vector vec2; // [esp+5Ch] [ebp-44h] BYREF
  Vector vec1; // [esp+68h] [ebp-38h] BYREF
  Vector vec3; // [esp+74h] [ebp-2Ch]
  int nTriCount; // [esp+80h] [ebp-20h]
  float flFrac; // [esp+84h] [ebp-1Ch] BYREF
  unsigned __int16 v31; // [esp+88h] [ebp-18h] BYREF
  int iTriangle; // [esp+8Ch] [ebp-14h] BYREF
  int v1; // [esp+90h] [ebp-10h] OVERLAPPED
  int v3; // [esp+94h] [ebp-Ch] OVERLAPPED
  void *v2; // [esp+98h] [ebp-8h]
  void *retaddr; // [esp+A0h] [ebp+0h]

  v3 = a2;
  v2 = retaddr;
  LODWORD(vec3.z) = this;
  nTriCount = -1;
  *flFraction = 1.0;
  LODWORD(vec3.x) = CCoreDispInfo::GetTriCount(this: &this->m_CoreDispInfo);
  v1 = 0;
  if ( SLODWORD(vec3.x) <= 0 )
    return -1;
  do
  {
    CCoreDispInfo::GetTriIndices(
      this: (CCoreDispInfo *)(LODWORD(vec3.z) + 24),
      iTri: v1,
      v1: (unsigned __int16 *)&flFrac,
      v2: (unsigned __int16 *)&iTriangle,
      v3: &v31);
    v6 = 224 * LOWORD(flFrac);
    v7 = *(_DWORD *)(LODWORD(vec3.z) + 784);
    v8 = *(float *)(v6 + v7 + 40);
    v9 = v6 + v7 + 40;
    v10 = 224 * (unsigned __int16)iTriangle;
    vec2.x = v8;
    vec2.y = *(float *)(v9 + 4);
    vec2.z = *(float *)(v9 + 8);
    v25[0] = *(_DWORD *)(v10 + v7 + 40);
    v25[1] = *(_DWORD *)(v10 + v7 + 44);
    x = rayStart->x;
    v12 = 224 * v31;
    y = rayStart->y;
    v14 = rayEnd->y;
    z = rayStart->z;
    v16 = rayEnd->z;
    v25[2] = *(_DWORD *)(v10 + v7 + 48);
    v17 = *(float *)(v12 + v7 + 40);
    v18 = v12 + v7 + 40;
    vec1.x = v17;
    vec1.y = *(float *)(v18 + 4);
    vec1.z = *(float *)(v18 + 8);
    v19 = rayEnd->x - x;
    ray.m_Start.z = v14 - y;
    ray.m_Start.y = v19;
    ray.m_Start.w = v16 - z;
    ray.m_Extents.y = 0.0;
    BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z) + (float)(v19 * v19))
                                   + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
    memset(&ray.m_StartOffset.y, 0, 12);
    LOBYTE(ray.m_Extents.z) = 1;
    *(float *)v23 = x;
    *(float *)&v23[1] = y;
    *(float *)&v23[2] = z;
    ray.m_Delta.y = -0.0;
    ray.m_Delta.z = -0.0;
    ray.m_Delta.w = -0.0;
    v20 = IntersectRayWithTriangle(
            ray: (const Ray_t *)v23,
            v1: &vec2,
            v2: COERCE_FLOAT(v25),
            v3: &vec1,
            oneSided: OneSided);
    vec3.y = v20;
    if ( v20 != -1.0 && *flFraction > vec3.y )
    {
      v21 = v1;
      *flFraction = vec3.y;
      nTriCount = v21;
    }
    ++v1;
  }
  while ( v1 < SLODWORD(vec3.x) );
  return nTriCount;
}

//------------------------------------------------------------------------------
// Address: 0x10117B30
// Name: public: bool CMapDisp::SaveDXF(struct ExportDXFInfo_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapDisp::SaveDXF(CMapDisp *this, ExportDXFInfo_s *pInfo)
{
  int m_Power; // ecx
  int v4; // edi
  int v5; // ebx
  int v6; // eax
  int v7; // ecx
  int v8; // esi
  int v9; // ebx
  int v10; // edi
  int v11; // esi
  int v12; // ebx
  bool v13; // zf
  char string[8]; // [esp+8h] [ebp-98h] BYREF
  char szName[128]; // [esp+24h] [ebp-7Ch]

  sprintf(string: &string[4], format: "OBJECT%03d", pInfo->nObject);
  m_Power = this->m_CoreDispInfo.m_Power;
  v4 = ((1 << m_Power) + 1) * ((1 << m_Power) + 1);
  fprintf(
    str: pInfo->fp,
    format: "0\nPOLYLINE\n8\n%s\n66\n1\n70\n64\n71\n%u\n72\n%u\n",
    &string[4],
    v4,
    2 * (1 << m_Power) * (1 << m_Power));
  fprintf(str: pInfo->fp, format: "62\n50\n");
  if ( v4 > 0 )
  {
    v5 = 0;
    do
    {
      fprintf(
        str: pInfo->fp,
        format: "0\nVERTEX\n8\n%s\n10\n%.6f\n20\n%.6f\n30\n%.6f\n70\n192\n",
        &string[4],
        this->m_CoreDispInfo.m_pVerts[v5].m_Vert.x,
        this->m_CoreDispInfo.m_pVerts[v5].m_Vert.y,
        this->m_CoreDispInfo.m_pVerts[v5].m_Vert.z);
      ++v5;
      --v4;
    }
    while ( v4 != 0 );
  }
  v6 = (1 << this->m_CoreDispInfo.m_Power) + 1;
  v7 = 1 << this->m_CoreDispInfo.m_Power;
  *(_DWORD *)&szName[112] = v6;
  if ( v7 > 0 )
  {
    v8 = 0;
    *(_DWORD *)&szName[120] = 0;
    *(_DWORD *)&szName[116] = v7;
    do
    {
      if ( v6 - 1 > 0 )
      {
        v9 = -v6;
        v10 = v8 + 1;
        v11 = v8 + v6 + 1 + 1;
        *(_DWORD *)&szName[104] = -v6;
        *(_DWORD *)&szName[108] = v6 - 1;
        while ( 1 )
        {
          v12 = v11 + v9;
          fprintf(
            str: pInfo->fp,
            format: "0\nVERTEX\n8\n%s\n10\n0\n20\n0\n30\n0\n70\n128\n71\n%d\n72\n%d\n73\n%d\n",
            &string[4],
            v10,
            v12 + v6 - 1,
            v11);
          fprintf(
            str: pInfo->fp,
            format: "0\nVERTEX\n8\n%s\n10\n0\n20\n0\n30\n0\n70\n128\n71\n%d\n72\n%d\n73\n%d\n",
            &string[4],
            v10,
            v11,
            v12);
          v6 = *(_DWORD *)&szName[112];
          ++v10;
          ++v11;
          if ( --*(_DWORD *)&szName[108] == 0 )
            break;
          v9 = *(_DWORD *)&szName[104];
        }
        v8 = *(_DWORD *)&szName[120];
      }
      v8 += v6;
      v13 = (*(_DWORD *)&szName[116])-- == 1;
      *(_DWORD *)&szName[120] = v8;
    }
    while ( !v13 );
  }
  fprintf(str: pInfo->fp, format: "0\nSEQEND\n8\n%s\n", &string[4]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10117CC0
// Name: public: bool CMapDisp::TraceLine(class Vector __near &,class Vector __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapDisp::TraceLine(
        CMapDisp *this,
        Vector *vecHitPos,
        Vector *vecHitNormal,
        const Vector *vecRayStart,
        const Vector *vecRayEnd)
{
  const Vector *v5; // esi
  int v7; // eax
  float y; // xmm4_4
  float z; // xmm5_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  Vector vecTriPoints[3]; // [esp+Ch] [ebp-24h] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  v5 = vecRayEnd;
  v7 = CMapDisp::CollideWithDispTri(
         this,
         a2: (int)&savedregs,
         rayStart: vecRayStart,
         rayEnd: vecRayEnd,
         flFraction: (float *)&vecRayEnd,
         OneSided: 0);
  if ( v7 == -1 )
    return 0;
  y = vecRayStart->y;
  z = vecRayStart->z;
  v11 = (float)(v5->y - y) * *(float *)&vecRayEnd;
  v12 = (float)(v5->z - z) * *(float *)&vecRayEnd;
  vecHitPos->x = vecRayStart->x + (float)((float)(v5->x - vecRayStart->x) * *(float *)&vecRayEnd);
  vecHitPos->y = y + v11;
  vecHitPos->z = z + v12;
  CCoreDispInfo::GetTriPos(
    this: &this->m_CoreDispInfo,
    iTri: v7,
    v1: vecTriPoints,
    v2: &vecTriPoints[1],
    v3: &vecTriPoints[2]);
  v13 = (float)((float)(vecTriPoints[2].z - vecTriPoints[0].z) * (float)(vecTriPoints[1].x - vecTriPoints[0].x))
      - (float)((float)(vecTriPoints[1].z - vecTriPoints[0].z) * (float)(vecTriPoints[2].x - vecTriPoints[0].x));
  v14 = (float)((float)(vecTriPoints[1].y - vecTriPoints[0].y) * (float)(vecTriPoints[2].x - vecTriPoints[0].x))
      - (float)((float)(vecTriPoints[2].y - vecTriPoints[0].y) * (float)(vecTriPoints[1].x - vecTriPoints[0].x));
  vecHitNormal->x = (float)((float)(vecTriPoints[1].z - vecTriPoints[0].z)
                          * (float)(vecTriPoints[2].y - vecTriPoints[0].y))
                  - (float)((float)(vecTriPoints[1].y - vecTriPoints[0].y)
                          * (float)(vecTriPoints[2].z - vecTriPoints[0].z));
  vecHitNormal->y = v13;
  vecHitNormal->z = v14;
  VectorNormalize(vec: vecHitNormal);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10117DF0
// Name: private: void CMapDisp::RenderDisAllowedVerts(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::RenderDisAllowedVerts(CMapDisp *this, CRender3D *pRender)
{
  CMapDisp *v2; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // edi
  CoreDispVert_t *m_pVerts; // edx
  float y; // xmm2_4
  float z; // xmm3_4
  float x; // xmm4_4
  Vector vecPointMin; // [esp+Ch] [ebp-20h] BYREF
  Vector vecPointMax; // [esp+18h] [ebp-14h] BYREF
  CMapDisp *v12; // [esp+24h] [ebp-8h]
  unsigned int v13; // [esp+28h] [ebp-4h]

  v2 = this;
  v3 = 0;
  v4 = ((1 << this->m_CoreDispInfo.m_Power) + 1) * ((1 << this->m_CoreDispInfo.m_Power) + 1);
  v12 = this;
  v5 = 1;
  if ( v4 > 0 )
  {
    v13 = 0;
    do
    {
      if ( (v5 & v2->m_CoreDispInfo.m_AllowedVerts.m_Ints[(unsigned int)v3 >> 5]) == 0 )
      {
        m_pVerts = v2->m_CoreDispInfo.m_pVerts;
        y = m_pVerts[v13 / 0xE0].m_Vert.y;
        z = m_pVerts[v13 / 0xE0].m_Vert.z;
        x = m_pVerts[v13 / 0xE0].m_Vert.x;
        vecPointMax.x = x + 5.0;
        vecPointMin.y = y - 5.0;
        vecPointMin.x = x - 5.0;
        vecPointMax.y = y + 5.0;
        vecPointMin.z = z - 5.0;
        vecPointMax.z = z + 5.0;
        CRender3D::RenderBox(
          this: pRender,
          Mins: &vecPointMin,
          Maxs: &vecPointMax,
          chRed: 0xFFu,
          chGreen: 0,
          chBlue: 0xFFu,
          eBoxSelectionState: SELECT_NONE);
        v2 = v12;
      }
      v13 += 224;
      ++v3;
      v5 = __ROL4__(v5, 1);
    }
    while ( v3 < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117EE0
// Name: private: void CMapDisp::RenderOverlaySurface(class CRender3D __near *,bool,enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapDisp::RenderOverlaySurface(
        CMapDisp *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        CRender3D *pRender,
        bool bIsSelected,
        SelectionState_t faceSelectionState)
{
  CMapDisp *v6; // edi
  int v7; // ebx
  IMatRenderContext *v8; // eax
  IMatRenderContext *v9; // esi
  CoreDispVert_t *m_pVerts; // eax
  int v11; // edi
  float *p_z; // esi
  float *m_pCurrPosition; // eax
  float *m_pCurrNormal; // eax
  unsigned __int16 *m_RenderIndices; // edi
  int v16; // ecx
  signed int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-200h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1ECh] [ebp-18h]
  CMapDisp *v22; // [esp+1F0h] [ebp-14h]
  Color color; // [esp+1F4h] [ebp-10h] BYREF
  int v24; // [esp+200h] [ebp-4h]
  IMesh *pMesh; // [esp+20Ch] [ebp+8h]
  IMatRenderContext *bIsSelecteda; // [esp+210h] [ebp+Ch]
  int nIndexCount; // [esp+214h] [ebp+10h]

  v6 = this;
  v22 = this;
  if ( !CMapDisp::m_bSelectMask )
  {
    color = (Color)-1;
    CMapDisp::CalcColor(this, pRender, bIsSelected, faceSelectionState, pColor: &color);
    nIndexCount = v6->m_CoreDispInfo.m_RenderIndexCount;
    v7 = ((1 << v6->m_CoreDispInfo.m_Power) + 1) * ((1 << v6->m_CoreDispInfo.m_Power) + 1);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v24 = 0;
    v8 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
                                a1: materials,
                                a2: a3,
                                a3: a2);
    v9 = v8;
    bIsSelecteda = v8;
    pRenderContext.m_pObject = v8;
    LOBYTE(v24) = 1;
    if ( v8 != nullptr )
      v8->BeginRender(this: v8);
    LOBYTE(v24) = 2;
    pMesh = v9->GetDynamicMesh(this: v9, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh,
      type: MATERIAL_TRIANGLES,
      nVertexCount: v7,
      nIndexCount,
      pMeshSettings: nullptr);
    m_pVerts = v6->m_CoreDispInfo.m_pVerts;
    if ( v7 > 0 )
    {
      v11 = color._color[2] | ((color._color[1] | ((color._color[0] | (color._color[3] << 8)) << 8)) << 8);
      p_z = &m_pVerts->m_Normal.z;
      do
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(p_z - 8);
        m_pCurrPosition[1] = *(p_z - 7);
        m_pCurrPosition[2] = *(p_z - 6);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v11;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = *(p_z - 2);
        m_pCurrNormal[1] = *(p_z - 1);
        m_pCurrNormal[2] = *p_z;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        p_z += 56;
        --v7;
      }
      while ( v7 != 0 );
      v9 = bIsSelecteda;
      v6 = v22;
    }
    m_RenderIndices = v6->m_CoreDispInfo.m_RenderIndices;
    v16 = 0;
    if ( nIndexCount > 0 )
    {
      m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      do
      {
        meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = m_RenderIndices[v16]
                                                               + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        ++v16;
      }
      while ( v16 < nIndexCount );
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    LOBYTE(v24) = 3;
    v9->EndRender(this: v9);
    LOBYTE(v24) = 0;
    v9->Release(this: v9);
    v24 = 4;
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    v24 = -1;
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101181C0
// Name: private: void CMapDisp::RenderSurface(class CRender3D __near *,bool,enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::RenderSurface(
        CMapDisp *this,
        CRender3D *pRender,
        bool bIsSelected,
        SelectionState_t faceSelectionState)
{
  CMapDisp *v4; // esi
  int v5; // edi
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // ebx
  int v8; // ebx
  int p_z; // esi
  float *m_pCurrPosition; // eax
  float *m_pCurrNormal; // eax
  float *v12; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  float *v16; // eax
  int v17; // xmm0_4
  int v18; // xmm2_4
  int v19; // xmm3_4
  float *v20; // eax
  int v21; // xmm0_4
  int v22; // xmm2_4
  int v23; // xmm3_4
  float *v24; // eax
  int v25; // xmm0_4
  int v26; // xmm2_4
  int v27; // xmm3_4
  float *v28; // eax
  int v29; // xmm0_4
  int v30; // xmm2_4
  int v31; // xmm3_4
  float *v32; // eax
  unsigned __int16 *m_RenderIndices; // esi
  int v34; // ecx
  signed int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-200h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-18h]
  CMapDisp *v39; // [esp+1F8h] [ebp-14h]
  Color color; // [esp+1FCh] [ebp-10h] BYREF
  int v41; // [esp+208h] [ebp-4h]
  IMesh *pMesh; // [esp+214h] [ebp+8h]
  IMatRenderContext *bIsSelecteda; // [esp+218h] [ebp+Ch]
  int numIndices; // [esp+21Ch] [ebp+10h]

  color._color[2] = -1;
  v4 = this;
  v39 = this;
  *(_WORD *)color._color = -1;
  CMapDisp::CalcColor(this, pRender, bIsSelected, faceSelectionState, pColor: &color);
  numIndices = v4->m_CoreDispInfo.m_RenderIndexCount;
  v5 = ((1 << v4->m_CoreDispInfo.m_Power) + 1) * ((1 << v4->m_CoreDispInfo.m_Power) + 1);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v41 = 0;
  v6 = materials->GetRenderContext(this: materials);
  v7 = v6;
  bIsSelecteda = v6;
  pRenderContext.m_pObject = v6;
  LOBYTE(v41) = 1;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  LOBYTE(v41) = 2;
  pMesh = v7->GetDynamicMesh(this: v7, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh,
    type: MATERIAL_TRIANGLES,
    nVertexCount: v5,
    nIndexCount: numIndices,
    pMeshSettings: nullptr);
  if ( v5 > 0 )
  {
    v8 = color._color[0];
    p_z = (int)&v4->m_CoreDispInfo.m_pVerts->m_Vert.z;
    do
    {
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(float *)(p_z - 8);
      m_pCurrPosition[1] = *(float *)(p_z - 4);
      m_pCurrPosition[2] = *(float *)p_z;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = color._color[2]
                                                          | ((color._color[1]
                                                            | ((v8 | ((unsigned __int8)(int)*(float *)(p_z + 92) << 8)) << 8)) << 8);
      m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = *(float *)(p_z + 16);
      m_pCurrNormal[1] = *(float *)(p_z + 20);
      m_pCurrNormal[2] = *(float *)(p_z + 24);
      v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      *v12 = *(float *)(p_z + 28);
      v12[1] = *(float *)(p_z + 32);
      v12[2] = *(float *)(p_z + 36);
      v13 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v13 = *(float *)(p_z + 40);
      v13[1] = *(float *)(p_z + 44);
      v13[2] = *(float *)(p_z + 48);
      v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *(float *)(p_z + 52);
      v14[1] = *(float *)(p_z + 56);
      v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = *(float *)(p_z + 60);
      v15[1] = *(float *)(p_z + 64);
      v16 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      v17 = *(_DWORD *)(p_z + 96);
      v18 = *(_DWORD *)(p_z + 132);
      v19 = *(_DWORD *)(p_z + 136);
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = *(float *)(p_z + 128);
      *((_DWORD *)v16 + 1) = v18;
      *((_DWORD *)v16 + 2) = v19;
      *((_DWORD *)v16 + 3) = v17;
      v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      v21 = *(_DWORD *)(p_z + 100);
      v22 = *(_DWORD *)(p_z + 144);
      v23 = *(_DWORD *)(p_z + 148);
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = *(float *)(p_z + 140);
      *((_DWORD *)v20 + 1) = v22;
      *((_DWORD *)v20 + 2) = v23;
      *((_DWORD *)v20 + 3) = v21;
      v24 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      v25 = *(_DWORD *)(p_z + 104);
      v26 = *(_DWORD *)(p_z + 156);
      v27 = *(_DWORD *)(p_z + 160);
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = *(float *)(p_z + 152);
      *((_DWORD *)v24 + 1) = v26;
      *((_DWORD *)v24 + 2) = v27;
      *((_DWORD *)v24 + 3) = v25;
      v28 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      v29 = *(_DWORD *)(p_z + 108);
      v30 = *(_DWORD *)(p_z + 168);
      v31 = *(_DWORD *)(p_z + 172);
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = *(float *)(p_z + 164);
      *((_DWORD *)v28 + 1) = v30;
      *((_DWORD *)v28 + 2) = v31;
      *((_DWORD *)v28 + 3) = v29;
      v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = *(float *)(p_z + 112);
      v32[1] = *(float *)(p_z + 116);
      v32[2] = *(float *)(p_z + 120);
      v32[3] = *(float *)(p_z + 124);
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      p_z += 224;
      --v5;
    }
    while ( v5 != 0 );
    v7 = bIsSelecteda;
    v4 = v39;
  }
  m_RenderIndices = v4->m_CoreDispInfo.m_RenderIndices;
  v34 = 0;
  if ( numIndices > 0 )
  {
    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    do
    {
      meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = m_RenderIndices[v34]
                                                             + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
      m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
      if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
        meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      ++v34;
    }
    while ( v34 < numIndices );
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
  LOBYTE(v41) = 3;
  v7->EndRender(this: v7);
  LOBYTE(v41) = 0;
  v7->Release(this: v7);
  v41 = 4;
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  v41 = -1;
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101185E0
// Name: private: void CMapDisp::RenderWalkableSurface(class CRender3D __near *,bool,enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::RenderWalkableSurface(
        CMapDisp *this,
        CRender3D *pRender,
        bool bIsSelected,
        SelectionState_t faceSelectionState)
{
  EditorRenderMode_t v4; // eax
  EditorRenderMode_t m_eCurrentRenderMode; // eax
  int v6; // eax
  CMapDoc *v7; // esi
  CMapFace *v8; // eax
  CMapDisp *v9; // esi
  int m_Size; // edx
  unsigned __int16 *v11; // edi
  CoreDispVert_t **m_pMemory; // eax
  int v13; // esi
  float *m_pCurrPosition; // ecx
  CoreDispVert_t *v15; // edx
  float *m_pCurrNormal; // ecx
  int v17; // ecx
  signed int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  EditorRenderMode_t v20; // eax
  CMapDisp *v21; // esi
  int v22; // edx
  unsigned __int16 *v23; // edi
  int v24; // esi
  int v25; // edi
  float *v26; // ecx
  float *v27; // edx
  float *v28; // ecx
  int v29; // ecx
  signed int v30; // eax
  CMapDoc *v31; // edi
  CMapFace *v32; // eax
  EditorRenderMode_t v33; // eax
  int v34; // eax
  int v35; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-21Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-34h]
  CoreDispVert_t **ppVerts; // [esp+1F8h] [ebp-30h]
  IMesh *v39; // [esp+1FCh] [ebp-2Ch]
  unsigned __int16 *pIndex; // [esp+200h] [ebp-28h]
  IMesh *pMesh; // [esp+204h] [ebp-24h]
  int iPass; // [esp+208h] [ebp-20h]
  int nVertCount; // [esp+20Ch] [ebp-1Ch]
  int nIndexCount; // [esp+210h] [ebp-18h]
  CMapDisp *v45; // [esp+214h] [ebp-14h]
  Color color; // [esp+218h] [ebp-10h]
  int v47; // [esp+224h] [ebp-4h]

  v45 = this;
  for ( iPass = 0; iPass < 2; ++iPass )
  {
    if ( iPass != 0 )
    {
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
      m_eCurrentRenderMode = pRender->m_eCurrentRenderMode;
      color = (Color)-16711681;
      switch ( m_eCurrentRenderMode )
      {
        case RENDER_MODE_LIGHTMAP_GRID:
$LN122_2:
          v6 = *(_DWORD *)&v45->GetParent(this: v45)[16].r;
          if ( v6 <= 16 )
          {
            if ( v6 < 16 )
              color._color[2] = 100;
          }
          else
          {
            color._color[0] = -106;
          }
          break;
        case RENDER_MODE_SELECTION_OVERLAY:
$LN127_5:
          if ( faceSelectionState == SELECT_MULTI_PARTIAL )
          {
            *(_WORD *)&color._color[2] = 16484;
          }
          else if ( faceSelectionState == SELECT_NORMAL )
          {
            color = (Color)1073742044;
          }
          break;
        case RENDER_MODE_SMOOTHING_GROUP:
$LN112_3:
          v7 = CMapDoc::m_pMapDoc;
          if ( CMapDoc::m_pMapDoc != nullptr )
          {
            v8 = (CMapFace *)v45->GetParent(this: v45);
            if ( CMapFace::InSmoothingGroup(this: v8, iGroup: v7->m_SmoothingGroupVisual) )
              color._color[2] = 0;
          }
          break;
        default:
          break;
      }
    }
    else
    {
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_TRANSLUCENT_FLAT);
      v4 = pRender->m_eCurrentRenderMode;
      color = (Color)1073807359;
      switch ( v4 )
      {
        case RENDER_MODE_LIGHTMAP_GRID:
          goto $LN122_2;
        case RENDER_MODE_SELECTION_OVERLAY:
          goto $LN127_5;
        case RENDER_MODE_SMOOTHING_GROUP:
          goto $LN112_3;
        default:
          break;
      }
    }
    v9 = v45;
    m_Size = v45->m_aWalkableIndices.m_Size;
    nVertCount = v45->m_aWalkableVerts.m_Size;
    nIndexCount = m_Size;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_bGenerateIndices = false;
    memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
    memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v47 = 2;
    v11 = (unsigned __int16 *)materials->GetRenderContext(this: materials);
    pIndex = v11;
    pRenderContext.m_pObject = (IMatRenderContext *)v11;
    LOBYTE(v47) = 3;
    if ( v11 != nullptr )
      (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)v11 + 8))(a1: v11);
    LOBYTE(v47) = 4;
    pMesh = (IMesh *)(*(int (__thiscall **)(unsigned __int16 *, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v11 + 228))(
                       a1: v11,
                       a2: 1,
                       a3: 0,
                       a4: 0,
                       a5: 0);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh,
      type: MATERIAL_TRIANGLES,
      nVertexCount: nVertCount,
      nIndexCount,
      pMeshSettings: nullptr);
    m_pMemory = v9->m_aWalkableVerts.m_Memory.m_pMemory;
    v13 = 0;
    ppVerts = m_pMemory;
    if ( nVertCount > 0 )
    {
      v39 = (IMesh *)(color._color[2] | ((color._color[1] | ((color._color[0] | (color._color[3] << 8)) << 8)) << 8));
      do
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v15 = ppVerts[v13];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v15->m_Vert.x;
        m_pCurrPosition[1] = v15->m_Vert.y;
        m_pCurrPosition[2] = v15->m_Vert.z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v39;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v15->m_Normal.x;
        m_pCurrNormal[1] = v15->m_Normal.y;
        m_pCurrNormal[2] = v15->m_Normal.z;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ++v13;
      }
      while ( v13 < nVertCount );
      v11 = pIndex;
    }
    v17 = 0;
    pIndex = v45->m_aWalkableIndices.m_Memory.m_pMemory;
    if ( nIndexCount > 0 )
    {
      m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      do
      {
        meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                               + pIndex[v17];
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        ++v17;
      }
      while ( v17 < nIndexCount );
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    CRender::PopRenderMode(this: pRender);
    LOBYTE(v47) = 5;
    (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)v11 + 12))(a1: v11);
    LOBYTE(v47) = 2;
    (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)v11 + 4))(a1: v11);
    v47 = 6;
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    v47 = -1;
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
  }
  for ( nVertCount = 0; nVertCount < 2; ++nVertCount )
  {
    if ( nVertCount == 0 )
    {
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_TRANSLUCENT_FLAT);
      v20 = pRender->m_eCurrentRenderMode;
      color = (Color)1073807104;
      switch ( v20 )
      {
        case RENDER_MODE_LIGHTMAP_GRID:
          goto $LN389;
        case RENDER_MODE_SELECTION_OVERLAY:
          goto $LN318_0;
        case RENDER_MODE_SMOOTHING_GROUP:
          goto $LN303_0;
        default:
          goto $LN594;
      }
    }
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
    v33 = pRender->m_eCurrentRenderMode;
    color = (Color)-16711936;
    switch ( v33 )
    {
      case RENDER_MODE_LIGHTMAP_GRID:
$LN389:
        v21 = v45;
        v34 = *(_DWORD *)&v45->GetParent(this: v45)[16].r;
        if ( v34 <= 16 )
        {
          if ( v34 < 16 )
            color._color[2] = 100;
        }
        else
        {
          color._color[0] = -106;
        }
        break;
      case RENDER_MODE_SELECTION_OVERLAY:
$LN318_0:
        if ( faceSelectionState == SELECT_MULTI_PARTIAL )
        {
          *(_WORD *)&color._color[2] = 16484;
        }
        else if ( faceSelectionState == SELECT_NORMAL )
        {
          color = (Color)1073742044;
        }
        goto $LN594;
      case RENDER_MODE_SMOOTHING_GROUP:
$LN303_0:
        v31 = CMapDoc::m_pMapDoc;
        if ( CMapDoc::m_pMapDoc == nullptr )
          goto $LN594;
        v21 = v45;
        v32 = (CMapFace *)v45->GetParent(this: v45);
        if ( CMapFace::InSmoothingGroup(this: v32, iGroup: v31->m_SmoothingGroupVisual) )
          color._color[2] = 0;
        break;
      default:
$LN594:
        v21 = v45;
        break;
    }
    v22 = v21->m_aForcedWalkableIndices.m_Size;
    iPass = v21->m_aWalkableVerts.m_Size;
    nIndexCount = v22;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_bGenerateIndices = false;
    memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
    memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v47 = 10;
    v23 = (unsigned __int16 *)materials->GetRenderContext(this: materials);
    pIndex = v23;
    pRenderContext.m_pObject = (IMatRenderContext *)v23;
    LOBYTE(v47) = 11;
    if ( v23 != nullptr )
      (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)v23 + 8))(a1: v23);
    LOBYTE(v47) = 12;
    v39 = (IMesh *)(*(int (__thiscall **)(unsigned __int16 *, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v23 + 228))(
                     a1: v23,
                     a2: 1,
                     a3: 0,
                     a4: 0,
                     a5: 0);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v39,
      type: MATERIAL_TRIANGLES,
      nVertexCount: iPass,
      nIndexCount,
      pMeshSettings: nullptr);
    v24 = 0;
    pMesh = (IMesh *)v45->m_aWalkableVerts.m_Memory.m_pMemory;
    if ( iPass > 0 )
    {
      v25 = color._color[2] | ((color._color[1] | ((color._color[0] | (color._color[3] << 8)) << 8)) << 8);
      do
      {
        v26 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v27 = *((float **)&pMesh->IVertexBuffer::__vftable + v24);
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v27[10];
        v26[1] = v27[11];
        v26[2] = v27[12];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v25;
        v28 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v27[16];
        v28[1] = v27[17];
        v28[2] = v27[18];
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ++v24;
      }
      while ( v24 < iPass );
      v23 = pIndex;
    }
    v29 = 0;
    pMesh = (IMesh *)v45->m_aForcedWalkableIndices.m_Memory.m_pMemory;
    if ( nIndexCount > 0 )
    {
      v30 = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      do
      {
        meshBuilder.m_IndexBuilder.m_pIndices[v30] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                   + *((_WORD *)&pMesh->IVertexBuffer::__vftable + v29);
        v30 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = v30;
        if ( v30 > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = v30;
        ++v29;
      }
      while ( v29 < nIndexCount );
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v35 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v35 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v35 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v35 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v35 = 0;
          break;
        default:
          v35 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v35);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v39->Draw_2(this: v39, a2: -1, a3: 0);
    CRender::PopRenderMode(this: pRender);
    LOBYTE(v47) = 13;
    (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)v23 + 12))(a1: v23);
    LOBYTE(v47) = 10;
    (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)v23 + 4))(a1: v23);
    v47 = 14;
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    v47 = -1;
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118E60
// Name: private: void CMapDisp::RenderBuildableSurface(class CRender3D __near *,bool,enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::RenderBuildableSurface(
        CMapDisp *this,
        CRender3D *pRender,
        bool bIsSelected,
        SelectionState_t faceSelectionState)
{
  EditorRenderMode_t v4; // eax
  EditorRenderMode_t m_eCurrentRenderMode; // eax
  int v6; // eax
  CMapDoc *v7; // esi
  CMapFace *v8; // eax
  int m_Size; // edx
  unsigned __int16 *v10; // edi
  int v11; // esi
  int v12; // edi
  float *m_pCurrPosition; // ecx
  CoreDispVert_t *v14; // edx
  float *m_pCurrNormal; // ecx
  int v16; // ecx
  signed int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  EditorRenderMode_t v19; // eax
  CMapDisp *v20; // esi
  int v21; // edx
  CoreDispVert_t **v22; // edi
  int v23; // esi
  float *v24; // ecx
  float *v25; // edx
  float *v26; // ecx
  int v27; // ecx
  signed int v28; // eax
  CMapDoc *v29; // edi
  CMapFace *v30; // eax
  EditorRenderMode_t v31; // eax
  int v32; // eax
  int v33; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-21Ch] BYREF
  CoreDispVert_t **v35; // [esp+1F4h] [ebp-34h]
  CMatRenderContextPtr pRenderContext; // [esp+1F8h] [ebp-30h]
  CoreDispVert_t **ppVerts; // [esp+1FCh] [ebp-2Ch]
  unsigned __int16 *pIndex; // [esp+200h] [ebp-28h]
  IMesh *pMesh; // [esp+204h] [ebp-24h]
  int nVertCount; // [esp+208h] [ebp-20h]
  int iPass; // [esp+20Ch] [ebp-1Ch]
  int nIndexCount; // [esp+210h] [ebp-18h]
  CMapDisp *v43; // [esp+214h] [ebp-14h]
  Color color; // [esp+218h] [ebp-10h]
  int v45; // [esp+224h] [ebp-4h]

  v43 = this;
  for ( iPass = 0; iPass < 2; ++iPass )
  {
    if ( iPass != 0 )
    {
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
      m_eCurrentRenderMode = pRender->m_eCurrentRenderMode;
      color = (Color)-16711681;
      switch ( m_eCurrentRenderMode )
      {
        case RENDER_MODE_LIGHTMAP_GRID:
$LN122_3:
          v6 = *(_DWORD *)&v43->GetParent(this: v43)[16].r;
          if ( v6 <= 16 )
          {
            if ( v6 < 16 )
              color._color[2] = 100;
          }
          else
          {
            color._color[0] = -106;
          }
          break;
        case RENDER_MODE_SELECTION_OVERLAY:
$LN127_6:
          if ( faceSelectionState == SELECT_MULTI_PARTIAL )
          {
            *(_WORD *)&color._color[2] = 16484;
          }
          else if ( faceSelectionState == SELECT_NORMAL )
          {
            color = (Color)1073742044;
          }
          break;
        case RENDER_MODE_SMOOTHING_GROUP:
$LN112_4:
          v7 = CMapDoc::m_pMapDoc;
          if ( CMapDoc::m_pMapDoc != nullptr )
          {
            v8 = (CMapFace *)v43->GetParent(this: v43);
            if ( CMapFace::InSmoothingGroup(this: v8, iGroup: v7->m_SmoothingGroupVisual) )
              color._color[2] = 0;
          }
          break;
        default:
          break;
      }
    }
    else
    {
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_TRANSLUCENT_FLAT);
      v4 = pRender->m_eCurrentRenderMode;
      color = (Color)1075406079;
      switch ( v4 )
      {
        case RENDER_MODE_LIGHTMAP_GRID:
          goto $LN122_3;
        case RENDER_MODE_SELECTION_OVERLAY:
          goto $LN127_6;
        case RENDER_MODE_SMOOTHING_GROUP:
          goto $LN112_4;
        default:
          break;
      }
    }
    m_Size = v43->m_aBuildableIndices.m_Size;
    nVertCount = v43->m_aBuildableVerts.m_Size;
    nIndexCount = m_Size;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_bGenerateIndices = false;
    memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
    memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v45 = 2;
    v10 = (unsigned __int16 *)materials->GetRenderContext(this: materials);
    pIndex = v10;
    pRenderContext.m_pObject = (IMatRenderContext *)v10;
    LOBYTE(v45) = 3;
    if ( v10 != nullptr )
      (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)v10 + 8))(a1: v10);
    LOBYTE(v45) = 4;
    pMesh = (IMesh *)(*(int (__thiscall **)(unsigned __int16 *, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v10 + 228))(
                       a1: v10,
                       a2: 1,
                       a3: 0,
                       a4: 0,
                       a5: 0);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh,
      type: MATERIAL_TRIANGLES,
      nVertexCount: nVertCount,
      nIndexCount,
      pMeshSettings: nullptr);
    v11 = 0;
    ppVerts = v43->m_aBuildableVerts.m_Memory.m_pMemory;
    if ( nVertCount > 0 )
    {
      v12 = color._color[2] | ((color._color[1] | ((color._color[0] | (color._color[3] << 8)) << 8)) << 8);
      do
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v14 = ppVerts[v11];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v14->m_Vert.x;
        m_pCurrPosition[1] = v14->m_Vert.y;
        m_pCurrPosition[2] = v14->m_Vert.z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v12;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v14->m_Normal.x;
        m_pCurrNormal[1] = v14->m_Normal.y;
        m_pCurrNormal[2] = v14->m_Normal.z;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ++v11;
      }
      while ( v11 < nVertCount );
      v10 = pIndex;
    }
    v16 = 0;
    pIndex = v43->m_aBuildableIndices.m_Memory.m_pMemory;
    if ( nIndexCount > 0 )
    {
      m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      do
      {
        meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                               + pIndex[v16];
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        ++v16;
      }
      while ( v16 < nIndexCount );
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    CRender::PopRenderMode(this: pRender);
    LOBYTE(v45) = 5;
    (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)v10 + 12))(a1: v10);
    LOBYTE(v45) = 2;
    (*(void (__thiscall **)(unsigned __int16 *))(*(_DWORD *)v10 + 4))(a1: v10);
    v45 = 6;
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    v45 = -1;
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
  }
  for ( nVertCount = 0; nVertCount < 2; ++nVertCount )
  {
    if ( nVertCount == 0 )
    {
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_TRANSLUCENT_FLAT);
      v19 = pRender->m_eCurrentRenderMode;
      color._color[0] = 0;
      *(_WORD *)&color._color[2] = 16639;
      switch ( v19 )
      {
        case RENDER_MODE_LIGHTMAP_GRID:
          goto $LN389_0;
        case RENDER_MODE_SELECTION_OVERLAY:
          goto $LN318_1;
        case RENDER_MODE_SMOOTHING_GROUP:
          goto $LN303_1;
        default:
          goto $LN588;
      }
    }
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
    v31 = pRender->m_eCurrentRenderMode;
    color._color[0] = 0;
    *(_WORD *)&color._color[2] = -1;
    switch ( v31 )
    {
      case RENDER_MODE_LIGHTMAP_GRID:
$LN389_0:
        v20 = v43;
        v32 = *(_DWORD *)&v43->GetParent(this: v43)[16].r;
        if ( v32 <= 16 )
        {
          if ( v32 < 16 )
            color._color[2] = 100;
        }
        else
        {
          color._color[0] = -106;
        }
        break;
      case RENDER_MODE_SELECTION_OVERLAY:
$LN318_1:
        if ( faceSelectionState == SELECT_MULTI_PARTIAL )
        {
          *(_WORD *)&color._color[2] = 16484;
        }
        else if ( faceSelectionState == SELECT_NORMAL )
        {
          color._color[0] = -36;
          *(_WORD *)&color._color[2] = 0x4000;
        }
        goto $LN588;
      case RENDER_MODE_SMOOTHING_GROUP:
$LN303_1:
        v29 = CMapDoc::m_pMapDoc;
        if ( CMapDoc::m_pMapDoc == nullptr )
          goto $LN588;
        v20 = v43;
        v30 = (CMapFace *)v43->GetParent(this: v43);
        if ( CMapFace::InSmoothingGroup(this: v30, iGroup: v29->m_SmoothingGroupVisual) )
          color._color[2] = 0;
        break;
      default:
$LN588:
        v20 = v43;
        break;
    }
    v21 = v20->m_aForcedBuildableIndices.m_Size;
    iPass = v20->m_aBuildableVerts.m_Size;
    nIndexCount = v21;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_bGenerateIndices = false;
    memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
    memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v45 = 10;
    v22 = (CoreDispVert_t **)materials->GetRenderContext(this: materials);
    ppVerts = v22;
    v35 = v22;
    LOBYTE(v45) = 11;
    if ( v22 != nullptr )
      ((void (__thiscall *)(CoreDispVert_t **))LODWORD((*v22)->m_FieldVector.z))(a1: v22);
    LOBYTE(v45) = 12;
    pRenderContext.m_pObject = (IMatRenderContext *)((int (__thiscall *)(CoreDispVert_t **, int, _DWORD, _DWORD, _DWORD))LODWORD((*v22)[1].m_FieldVector.y))(
                                                      a1: v22,
                                                      a2: 1,
                                                      a3: 0,
                                                      a4: 0,
                                                      a5: 0);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: (IMesh *)pRenderContext.m_pObject,
      type: MATERIAL_TRIANGLES,
      nVertexCount: iPass,
      nIndexCount,
      pMeshSettings: nullptr);
    v23 = 0;
    pMesh = (IMesh *)v43->m_aBuildableVerts.m_Memory.m_pMemory;
    if ( iPass > 0 )
    {
      pIndex = (unsigned __int16 *)(color._color[2] | ((color._color[0] | (color._color[3] << 8)) << 16));
      do
      {
        v24 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v25 = *((float **)&pMesh->IVertexBuffer::__vftable + v23);
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v25[10];
        v24[1] = v25[11];
        v24[2] = v25[12];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = pIndex;
        v26 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v25[16];
        v26[1] = v25[17];
        v26[2] = v25[18];
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ++v23;
      }
      while ( v23 < iPass );
      v22 = ppVerts;
    }
    v27 = 0;
    pMesh = (IMesh *)v43->m_aForcedBuildableIndices.m_Memory.m_pMemory;
    if ( nIndexCount > 0 )
    {
      v28 = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      do
      {
        meshBuilder.m_IndexBuilder.m_pIndices[v28] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                   + *((_WORD *)&pMesh->IVertexBuffer::__vftable + v27);
        v28 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = v28;
        if ( v28 > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = v28;
        ++v27;
      }
      while ( v27 < nIndexCount );
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v33 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v33 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v33 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v33 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v33 = 0;
          break;
        default:
          v33 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v33);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    ((void (__thiscall *)(IMatRenderContext *, int, _DWORD))pRenderContext.m_pObject->ClearBuffers)(
      a1: pRenderContext.m_pObject,
      a2: -1,
      a3: 0);
    CRender::PopRenderMode(this: pRender);
    LOBYTE(v45) = 13;
    ((void (__thiscall *)(CoreDispVert_t **))LODWORD((*v22)->m_FieldDistance))(a1: v22);
    LOBYTE(v45) = 10;
    ((void (__thiscall *)(CoreDispVert_t **))LODWORD((*v22)->m_FieldVector.y))(a1: v22);
    v45 = 14;
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    v45 = -1;
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101196E0
// Name: private: void CMapDisp::RenderWireframeSurface(class CRender3D __near *,bool,enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapDisp::RenderWireframeSurface(
        CMapDisp *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CRender3D *pRender,
        bool bIsSelected,
        Color faceSelectionState)
{
  CMapDisp *v6; // esi
  int v7; // edi
  int v8; // edi
  IMatRenderContext *v9; // eax
  IMatRenderContext *v10; // ebx
  float *p_y; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  unsigned __int16 *m_RenderIndices; // esi
  Color v16; // ecx
  signed int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-1FCh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1ECh] [ebp-14h]
  CMapDisp *v22; // [esp+1F0h] [ebp-10h]
  int v23; // [esp+1FCh] [ebp-4h]
  IMesh *pMesh; // [esp+20Ch] [ebp+Ch]

  v6 = this;
  v22 = this;
  if ( !CMapDisp::m_bGridMask )
  {
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
    CMapDisp::CalcColor(
      this: v6,
      pRender,
      bIsSelected,
      faceSelectionState: *(SelectionState_t *)&faceSelectionState,
      pColor: &faceSelectionState);
    v7 = 1 << v6->m_CoreDispInfo.m_Power;
    faceSelectionState = (Color)v6->m_CoreDispInfo.m_RenderIndexCount;
    v8 = (v7 + 1) * (v7 + 1);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v23 = 0;
    v9 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
                                a1: materials,
                                a2: a3,
                                a3: a2);
    v10 = v9;
    pRenderContext.m_pObject = v9;
    LOBYTE(v23) = 1;
    if ( v9 != nullptr )
      v9->BeginRender(this: v9);
    LOBYTE(v23) = 2;
    pMesh = v10->GetDynamicMesh(this: v10, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh,
      type: MATERIAL_TRIANGLES,
      nVertexCount: v8,
      nIndexCount: *(_DWORD *)&faceSelectionState,
      pMeshSettings: nullptr);
    if ( v8 > 0 )
    {
      p_y = &v6->m_CoreDispInfo.m_pVerts->m_Vert.y;
      do
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(p_y - 1);
        m_pCurrPosition[1] = *p_y;
        m_pCurrPosition[2] = p_y[1];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
        v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_y[14];
        v13[1] = p_y[15];
        v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_y[16];
        v14[1] = p_y[17];
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        p_y += 56;
        --v8;
      }
      while ( v8 != 0 );
      v6 = v22;
    }
    m_RenderIndices = v6->m_CoreDispInfo.m_RenderIndices;
    v16 = 0;
    if ( *(int *)&faceSelectionState > 0 )
    {
      m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      do
      {
        meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = m_RenderIndices[*(_DWORD *)&v16]
                                                               + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        ++*(_DWORD *)&v16;
      }
      while ( *(_DWORD *)&v16 < *(_DWORD *)&faceSelectionState );
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    CRender::PopRenderMode(this: pRender);
    LOBYTE(v23) = 3;
    v10->EndRender(this: v10);
    LOBYTE(v23) = 0;
    v10->Release(this: v10);
    v23 = 4;
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    v23 = -1;
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101199B0
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispAllowedVertsKeyCallback(char const __near *,char const __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispAllowedVertsKeyCallback(
        const char *szKey,
        const char *szValue,
        CMapDisp *pDisp)
{
  const char *v3; // eax
  CBitVec<289> *p_m_AllowedVerts; // esi
  char szBuf[1024]; // [esp+0h] [ebp-400h] BYREF

  if ( V_strncasecmp(s1: szKey, s2: "10", n: 2) == 0 )
  {
    strcpy(szBuf, szValue);
    v3 = strtok(string: szBuf, control: " ");
    if ( v3 != nullptr )
    {
      p_m_AllowedVerts = &pDisp->m_CoreDispInfo.m_AllowedVerts;
      do
      {
        p_m_AllowedVerts->m_Ints[0] = atoi(nptr: v3);
        v3 = strtok(string: nullptr, control: " ");
        p_m_AllowedVerts = (CBitVec<289> *)((char *)p_m_AllowedVerts + 4);
      }
      while ( v3 != nullptr );
    }
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x10119A40
// Name: public: enum ChunkFileResult_t CMapDisp::SaveVMF(class CChunkFile __near *,class CSaveInfo __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapDisp::SaveVMF(CMapDisp *this, CChunkFile *pFile, CSaveInfo *pSaveInfo)
{
  CChunkFile *v3; // edi
  ChunkFileResult_t result; // eax
  int m_Flags; // ecx
  int m_Power; // ebx
  float z; // xmm0_4
  BOOL m_bSubdiv; // esi
  int y_low; // esi
  int v11; // ecx
  char v12; // al
  int v13; // ebx
  char *v14; // edi
  char v15; // al
  int v16; // eax
  double v17; // xmm0_8
  unsigned int v18; // eax
  char *v19; // edi
  char v20; // cl
  float v21; // ebx
  float v22; // ebx
  char v23; // al
  char *v24; // edi
  char v25; // al
  double v26; // xmm0_8
  unsigned int v27; // eax
  char *v28; // edi
  char v29; // cl
  float w; // esi
  float y; // ecx
  int v32; // ebx
  char v33; // al
  char *v34; // edi
  char v35; // al
  int v36; // ecx
  double v37; // xmm0_8
  unsigned int v38; // eax
  char *v39; // edi
  char v40; // cl
  float v41; // esi
  float v42; // ecx
  int v43; // ebx
  char v44; // al
  char *v45; // edi
  char v46; // al
  int v47; // edx
  double v48; // xmm0_8
  unsigned int v49; // eax
  char *v50; // edi
  char v51; // cl
  float v52; // esi
  CChunkFile *v53; // edi
  int v54; // ebx
  float v55; // ecx
  char v56; // al
  char *v57; // edi
  char v58; // al
  double v59; // xmm0_8
  unsigned int v60; // eax
  char *v61; // edi
  char v62; // cl
  float v63; // esi
  float x; // ecx
  int v65; // ebx
  char v66; // al
  char *v67; // edi
  char v68; // al
  unsigned int v69; // eax
  char *v70; // edi
  char v71; // cl
  unsigned int v72; // eax
  char *v73; // edi
  char v74; // cl
  float v75; // esi
  int v76; // ebx
  char *v77; // edi
  char v78; // al
  unsigned int v79; // eax
  char *v80; // edi
  char v81; // cl
  int v82; // esi
  float *v83; // esi
  int v84; // edx
  float *v85; // ecx
  CChunkFile *v86; // edi
  float v87; // ecx
  int v88; // ebx
  char v89; // al
  char *v90; // edi
  char v91; // al
  int v92; // ecx
  double v93; // xmm0_8
  unsigned int v94; // eax
  char *v95; // edi
  char v96; // cl
  float v97; // esi
  ChunkFileResult_t v98; // eax
  float v99; // ecx
  int v100; // ebx
  char v101; // al
  char *v102; // edi
  char v103; // al
  int v104; // edx
  double v105; // xmm0_8
  unsigned int v106; // eax
  char *v107; // edi
  char v108; // cl
  float v109; // esi
  ChunkFileResult_t v110; // eax
  char v111; // al
  int v112; // ebx
  char *v113; // edi
  char v114; // al
  unsigned int v115; // eax
  char *v116; // edi
  char v117; // cl
  int v118; // esi
  double v119; // [esp-10h] [ebp-6C8h]
  double v120; // [esp-10h] [ebp-6C8h]
  double v121; // [esp-8h] [ebp-6C0h]
  double v122; // [esp-8h] [ebp-6C0h]
  double v123; // [esp-8h] [ebp-6C0h]
  double v124; // [esp-8h] [ebp-6C0h]
  double v125; // [esp-8h] [ebp-6C0h]
  double v126; // [esp+0h] [ebp-6B8h]
  double v127; // [esp+0h] [ebp-6B8h]
  double v128; // [esp+0h] [ebp-6B8h]
  double v129; // [esp+0h] [ebp-6B8h]
  double v130; // [esp+0h] [ebp-6B8h]
  int v131; // [esp+4h] [ebp-6B4h]
  char v132[8]; // [esp+10h] [ebp-6A8h] BYREF
  char v133[32]; // [esp+114h] [ebp-5A4h] BYREF
  char pszChunkName[32]; // [esp+194h] [ebp-524h] BYREF
  char temp[128]; // [esp+1B4h] [ebp-504h] BYREF
  char szBuf[1024]; // [esp+234h] [ebp-484h] BYREF
  Vector vColorBlend[4]; // [esp+644h] [ebp-74h] BYREF
  Vector vec; // [esp+674h] [ebp-44h] BYREF
  Vector4D v139; // [esp+680h] [ebp-38h] BYREF
  char pszKey[4]; // [esp+690h] [ebp-28h] BYREF
  Vector startPosition; // [esp+694h] [ebp-24h]
  Vector4D vAlphaBlend; // [esp+6A0h] [ebp-18h]
  char szKey[10]; // [esp+6B0h] [ebp-8h]

  v3 = pFile;
  LODWORD(startPosition.z) = this;
  result = CChunkFile::BeginChunk(this: pFile, pszChunkName: "dispinfo");
  m_Flags = this->m_CoreDispInfo.m_Surf.m_Flags;
  m_Power = this->m_CoreDispInfo.m_Power;
  vAlphaBlend.w = this->m_CoreDispInfo.m_Elevation;
  vec.x = this->m_CoreDispInfo.m_Surf.m_Points[0].x;
  vec.y = this->m_CoreDispInfo.m_Surf.m_Points[0].y;
  z = this->m_CoreDispInfo.m_Surf.m_Points[0].z;
  m_bSubdiv = this->m_bSubdiv;
  *(_DWORD *)szKey = m_Flags;
  vec.z = z;
  if ( result == ChunkFile_Ok )
  {
    result = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "power", nValue: m_Power);
    if ( result == ChunkFile_Ok )
    {
      result = CChunkFile::WriteKeyValueVector3(this: pFile, pszKey: "startposition", &vec);
      if ( result == ChunkFile_Ok )
      {
        result = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "flags", nValue: *(int *)szKey);
        if ( result == ChunkFile_Ok )
        {
          result = CChunkFile::WriteKeyValueFloat(this: pFile, pszKey: "elevation", fValue: vAlphaBlend.w);
          if ( result == ChunkFile_Ok )
          {
            result = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "subdiv", nValue: m_bSubdiv);
            if ( result == ChunkFile_Ok )
            {
              result = CChunkFile::BeginChunk(this: pFile, pszChunkName: "normals");
              if ( result == ChunkFile_Ok )
              {
                vAlphaBlend.z = 0.0;
                y_low = (1 << m_Power) + 1;
                LODWORD(vAlphaBlend.x) = 1 << m_Power;
                LODWORD(vAlphaBlend.y) = y_low;
                if ( y_low <= 0 )
                  goto LABEL_171;
                v11 = 0;
                *(_DWORD *)szKey = 0;
                LODWORD(v139.w) = 224 * y_low;
                do
                {
                  v12 = 1;
                  temp[96] = 0;
                  v13 = v11;
                  LODWORD(vAlphaBlend.w) = y_low;
                  while ( 1 )
                  {
                    if ( v12 == 0 )
                    {
                      v14 = &temp[95];
                      do
                        v15 = *++v14;
                      while ( v15 != 0 );
                      strcpy(v14, " ");
                    }
                    v16 = *(_DWORD *)(LODWORD(startPosition.z) + 784);
                    v126 = *(float *)(v16 + v13 + 8);
                    v121 = *(float *)(v16 + v13 + 4);
                    v17 = *(float *)(v16 + v13);
                    szKey[7] = 0;
                    sprintf(string: &szBuf[1008], format: "%g %g %g", v17, v121, v126);
                    v18 = strlen(&szBuf[1008]) + 1;
                    v19 = &temp[95];
                    do
                      v20 = *++v19;
                    while ( v20 != 0 );
                    qmemcpy(v19, &szBuf[1008], v18);
                    v13 += 224;
                    if ( --LODWORD(vAlphaBlend.w) == 0 )
                      break;
                    v12 = szKey[7];
                  }
                  v21 = vAlphaBlend.z;
                  sprintf(string: pszKey, format: "row%d", vAlphaBlend.z);
                  v3 = pFile;
                  result = CChunkFile::WriteKeyValue(this: pFile, pszKey, pszValue: &temp[96]);
                  v11 = LODWORD(v139.w) + *(_DWORD *)szKey;
                  y_low = LODWORD(vAlphaBlend.y);
                  LODWORD(vAlphaBlend.z) = LODWORD(v21) + 1;
                  *(_DWORD *)szKey += LODWORD(v139.w);
                }
                while ( LODWORD(v21) + 1 < SLODWORD(vAlphaBlend.y) );
                if ( result == ChunkFile_Ok )
                {
LABEL_171:
                  result = CChunkFile::EndChunk(this: v3);
                  if ( result == ChunkFile_Ok )
                  {
                    result = CChunkFile::BeginChunk(this: v3, pszChunkName: "distances");
                    if ( result == ChunkFile_Ok )
                    {
                      vAlphaBlend.w = 0.0;
                      if ( y_low > 0 )
                      {
                        vAlphaBlend.z = 0.0;
                        LODWORD(v139.w) = 224 * y_low;
                        do
                        {
                          v22 = vAlphaBlend.z;
                          v23 = 1;
                          temp[96] = 0;
                          *(float *)szKey = vAlphaBlend.y;
                          while ( 1 )
                          {
                            if ( v23 == 0 )
                            {
                              v24 = &temp[95];
                              do
                                v25 = *++v24;
                              while ( v25 != 0 );
                              strcpy(v24, " ");
                            }
                            v26 = *(float *)(LODWORD(v22) + *(_DWORD *)(LODWORD(startPosition.z) + 784) + 12);
                            szKey[7] = 0;
                            sprintf(string: &szBuf[1008], format: "%g", v26);
                            v27 = strlen(&szBuf[1008]) + 1;
                            v28 = &temp[95];
                            do
                              v29 = *++v28;
                            while ( v29 != 0 );
                            qmemcpy(v28, &szBuf[1008], v27);
                            LODWORD(v22) += 224;
                            if ( --*(_DWORD *)szKey == 0 )
                              break;
                            v23 = szKey[7];
                          }
                          w = vAlphaBlend.w;
                          sprintf(string: pszKey, format: "row%d", vAlphaBlend.w);
                          result = CChunkFile::WriteKeyValue(this: pFile, pszKey, pszValue: &temp[96]);
                          LODWORD(vAlphaBlend.z) += LODWORD(v139.w);
                          LODWORD(vAlphaBlend.w) = LODWORD(w) + 1;
                        }
                        while ( LODWORD(w) + 1 < SLODWORD(vAlphaBlend.y) );
                        if ( result != ChunkFile_Ok )
                          return result;
                        y_low = LODWORD(vAlphaBlend.y);
                        v3 = pFile;
                      }
                      result = CChunkFile::EndChunk(this: v3);
                      if ( result == ChunkFile_Ok )
                      {
                        result = CChunkFile::BeginChunk(this: v3, pszChunkName: "offsets");
                        if ( result == ChunkFile_Ok )
                        {
                          vAlphaBlend.w = 0.0;
                          if ( y_low <= 0 )
                            goto LABEL_66;
                          y = vAlphaBlend.y;
                          vAlphaBlend.z = 0.0;
                          v32 = 0;
                          LODWORD(v139.w) = 224 * LODWORD(vAlphaBlend.y);
                          do
                          {
                            v33 = 1;
                            temp[96] = 0;
                            *(float *)szKey = y;
                            while ( 1 )
                            {
                              if ( v33 == 0 )
                              {
                                v34 = &temp[95];
                                do
                                  v35 = *++v34;
                                while ( v35 != 0 );
                                strcpy(v34, " ");
                              }
                              v36 = *(_DWORD *)(LODWORD(startPosition.z) + 784);
                              v127 = *(float *)(v32 + v36 + 36);
                              v122 = *(float *)(v32 + v36 + 32);
                              v37 = *(float *)(v32 + v36 + 28);
                              szKey[7] = 0;
                              sprintf(string: &szBuf[1008], format: "%g %g %g", v37, v122, v127);
                              v38 = strlen(&szBuf[1008]) + 1;
                              v39 = &temp[95];
                              do
                                v40 = *++v39;
                              while ( v40 != 0 );
                              qmemcpy(v39, &szBuf[1008], v38);
                              v32 += 224;
                              if ( --*(_DWORD *)szKey == 0 )
                                break;
                              v33 = szKey[7];
                            }
                            v41 = vAlphaBlend.w;
                            sprintf(string: pszKey, format: "row%d", vAlphaBlend.w);
                            result = CChunkFile::WriteKeyValue(this: pFile, pszKey, pszValue: &temp[96]);
                            v32 = LODWORD(v139.w) + LODWORD(vAlphaBlend.z);
                            y = vAlphaBlend.y;
                            LODWORD(vAlphaBlend.w) = LODWORD(v41) + 1;
                            LODWORD(vAlphaBlend.z) += LODWORD(v139.w);
                          }
                          while ( LODWORD(v41) + 1 < SLODWORD(vAlphaBlend.y) );
                          if ( result == ChunkFile_Ok )
                          {
LABEL_66:
                            result = CChunkFile::EndChunk(this: pFile);
                            if ( result == ChunkFile_Ok )
                            {
                              result = CChunkFile::BeginChunk(this: pFile, pszChunkName: "offset_normals");
                              if ( result == ChunkFile_Ok )
                              {
                                vAlphaBlend.w = 0.0;
                                if ( SLODWORD(vAlphaBlend.y) <= 0 )
                                  goto LABEL_81;
                                v42 = vAlphaBlend.y;
                                vAlphaBlend.z = 0.0;
                                v43 = 0;
                                LODWORD(v139.w) = 224 * LODWORD(vAlphaBlend.y);
                                do
                                {
                                  v44 = 1;
                                  temp[96] = 0;
                                  *(float *)szKey = v42;
                                  while ( 1 )
                                  {
                                    if ( v44 == 0 )
                                    {
                                      v45 = &temp[95];
                                      do
                                        v46 = *++v45;
                                      while ( v46 != 0 );
                                      strcpy(v45, " ");
                                    }
                                    v47 = *(_DWORD *)(LODWORD(startPosition.z) + 784);
                                    v128 = *(float *)(v43 + v47 + 24);
                                    v123 = *(float *)(v43 + v47 + 20);
                                    v48 = *(float *)(v43 + v47 + 16);
                                    szKey[7] = 0;
                                    sprintf(string: &szBuf[1008], format: "%g %g %g", v48, v123, v128);
                                    v49 = strlen(&szBuf[1008]) + 1;
                                    v50 = &temp[95];
                                    do
                                      v51 = *++v50;
                                    while ( v51 != 0 );
                                    qmemcpy(v50, &szBuf[1008], v49);
                                    v43 += 224;
                                    if ( --*(_DWORD *)szKey == 0 )
                                      break;
                                    v44 = szKey[7];
                                  }
                                  v52 = vAlphaBlend.w;
                                  sprintf(string: pszKey, format: "row%d", vAlphaBlend.w);
                                  result = CChunkFile::WriteKeyValue(this: pFile, pszKey, pszValue: &temp[96]);
                                  v43 = LODWORD(v139.w) + LODWORD(vAlphaBlend.z);
                                  v42 = vAlphaBlend.y;
                                  LODWORD(vAlphaBlend.w) = LODWORD(v52) + 1;
                                  LODWORD(vAlphaBlend.z) += LODWORD(v139.w);
                                }
                                while ( LODWORD(v52) + 1 < SLODWORD(vAlphaBlend.y) );
                                if ( result == ChunkFile_Ok )
                                {
LABEL_81:
                                  v53 = pFile;
                                  result = CChunkFile::EndChunk(this: pFile);
                                  v54 = 0;
                                  if ( result == ChunkFile_Ok )
                                  {
                                    result = CChunkFile::BeginChunk(this: pFile, pszChunkName: "alphas");
                                    if ( result == ChunkFile_Ok )
                                    {
                                      v55 = vAlphaBlend.y;
                                      vAlphaBlend.w = 0.0;
                                      if ( SLODWORD(vAlphaBlend.y) <= 0 )
                                        goto LABEL_98;
                                      vAlphaBlend.z = 0.0;
                                      LODWORD(v139.w) = 224 * LODWORD(vAlphaBlend.y);
                                      do
                                      {
                                        v56 = 1;
                                        temp[96] = 0;
                                        *(float *)szKey = v55;
                                        while ( 1 )
                                        {
                                          if ( v56 == 0 )
                                          {
                                            v57 = &temp[95];
                                            do
                                              v58 = *++v57;
                                            while ( v58 != 0 );
                                            strcpy(v57, " ");
                                          }
                                          v59 = *(float *)(v54 + *(_DWORD *)(LODWORD(startPosition.z) + 784) + 140);
                                          szKey[7] = 0;
                                          sprintf(string: &szBuf[1008], format: "%g", v59);
                                          v60 = strlen(&szBuf[1008]) + 1;
                                          v61 = &temp[95];
                                          do
                                            v62 = *++v61;
                                          while ( v62 != 0 );
                                          qmemcpy(v61, &szBuf[1008], v60);
                                          v54 += 224;
                                          if ( --*(_DWORD *)szKey == 0 )
                                            break;
                                          v56 = szKey[7];
                                        }
                                        v63 = vAlphaBlend.w;
                                        sprintf(string: pszKey, format: "row%d", vAlphaBlend.w);
                                        v53 = pFile;
                                        result = CChunkFile::WriteKeyValue(this: pFile, pszKey, pszValue: &temp[96]);
                                        v54 = LODWORD(v139.w) + LODWORD(vAlphaBlend.z);
                                        v55 = vAlphaBlend.y;
                                        LODWORD(vAlphaBlend.w) = LODWORD(v63) + 1;
                                        LODWORD(vAlphaBlend.z) += LODWORD(v139.w);
                                      }
                                      while ( LODWORD(v63) + 1 < SLODWORD(vAlphaBlend.y) );
                                      if ( result == ChunkFile_Ok )
                                      {
LABEL_98:
                                        result = CChunkFile::EndChunk(this: v53);
                                        if ( result == ChunkFile_Ok )
                                        {
                                          result = CChunkFile::BeginChunk(this: v53, pszChunkName: "triangle_tags");
                                          if ( result == ChunkFile_Ok )
                                          {
                                            vAlphaBlend.w = 0.0;
                                            if ( SLODWORD(vAlphaBlend.x) <= 0 )
                                              goto LABEL_99;
                                            x = vAlphaBlend.x;
                                            vAlphaBlend.z = 0.0;
                                            v65 = 0;
                                            LODWORD(v139.w) = 16 * LODWORD(vAlphaBlend.x);
                                            do
                                            {
                                              v66 = 1;
                                              temp[96] = 0;
                                              *(float *)szKey = x;
                                              while ( 1 )
                                              {
                                                if ( v66 == 0 )
                                                {
                                                  v67 = &temp[95];
                                                  do
                                                    v68 = *++v67;
                                                  while ( v68 != 0 );
                                                  strcpy(v67, " ");
                                                }
                                                v131 = *(unsigned __int16 *)(v65
                                                                           + *(_DWORD *)(LODWORD(startPosition.z) + 788)
                                                                           + 6);
                                                szKey[7] = 0;
                                                sprintf(string: &szBuf[1008], format: "%d", v131);
                                                v69 = strlen(&szBuf[1008]) + 1;
                                                v70 = &temp[95];
                                                do
                                                  v71 = *++v70;
                                                while ( v71 != 0 );
                                                qmemcpy(v70, &szBuf[1008], v69);
                                                sprintf(
                                                  string: &szBuf[1008],
                                                  format: " %d",
                                                  *(unsigned __int16 *)(v65
                                                                      + *(_DWORD *)(LODWORD(startPosition.z) + 788)
                                                                      + 14));
                                                v72 = strlen(&szBuf[1008]) + 1;
                                                v73 = &temp[95];
                                                do
                                                  v74 = *++v73;
                                                while ( v74 != 0 );
                                                qmemcpy(v73, &szBuf[1008], v72);
                                                v65 += 16;
                                                if ( --*(_DWORD *)szKey == 0 )
                                                  break;
                                                v66 = szKey[7];
                                              }
                                              v75 = vAlphaBlend.w;
                                              sprintf(string: pszKey, format: "row%d", vAlphaBlend.w);
                                              result = CChunkFile::WriteKeyValue(
                                                         this: pFile,
                                                         pszKey,
                                                         pszValue: &temp[96]);
                                              v65 = LODWORD(v139.w) + LODWORD(vAlphaBlend.z);
                                              x = vAlphaBlend.x;
                                              LODWORD(vAlphaBlend.w) = LODWORD(v75) + 1;
                                              LODWORD(vAlphaBlend.z) += LODWORD(v139.w);
                                            }
                                            while ( LODWORD(v75) + 1 < SLODWORD(vAlphaBlend.x) );
                                            if ( result == ChunkFile_Ok )
                                            {
LABEL_99:
                                              result = CChunkFile::EndChunk(this: pFile);
                                              if ( result == ChunkFile_Ok )
                                              {
                                                result = CChunkFile::BeginChunk(
                                                           this: pFile,
                                                           pszChunkName: "allowed_verts");
                                                if ( result == ChunkFile_Ok )
                                                {
                                                  v76 = 0;
                                                  temp[96] = 0;
                                                  LODWORD(vAlphaBlend.x) = LODWORD(startPosition.z) + 824;
                                                  do
                                                  {
                                                    if ( v76 != 0 )
                                                    {
                                                      v77 = &temp[95];
                                                      do
                                                        v78 = *++v77;
                                                      while ( v78 != 0 );
                                                      strcpy(v77, " ");
                                                    }
                                                    sprintf(
                                                      string: &szBuf[1008],
                                                      format: "%d",
                                                      *(_DWORD *)LODWORD(vAlphaBlend.x));
                                                    v79 = strlen(&szBuf[1008]) + 1;
                                                    v80 = &temp[95];
                                                    do
                                                      v81 = *++v80;
                                                    while ( v81 != 0 );
                                                    LODWORD(vAlphaBlend.x) += 4;
                                                    qmemcpy(v80, &szBuf[1008], v79);
                                                    ++v76;
                                                  }
                                                  while ( v76 < 10 );
                                                  sprintf(string: (char *)&v139.z, format: "%d", 10);
                                                  result = CChunkFile::WriteKeyValue(
                                                             this: pFile,
                                                             pszKey: (const char *)&v139.z,
                                                             pszValue: &temp[96]);
                                                  if ( result == ChunkFile_Ok )
                                                  {
                                                    result = CChunkFile::EndChunk(this: pFile);
                                                    if ( result == ChunkFile_Ok )
                                                    {
                                                      szKey[7] = 0;
                                                      if ( SLODWORD(vAlphaBlend.y) <= 0 )
                                                        return CChunkFile::EndChunk(this: pFile);
                                                      v82 = *(_DWORD *)(LODWORD(startPosition.z) + 784);
                                                      LODWORD(vAlphaBlend.z) = 224 * LODWORD(vAlphaBlend.y);
                                                      v83 = (float *)(v82 + 152);
                                                      *(float *)szKey = vAlphaBlend.y;
                                                      do
                                                      {
                                                        v84 = 0;
                                                        v85 = v83;
                                                        while ( *(v85 - 2) == 0.0
                                                             && *(v85 - 1) == 0.0
                                                             && *v85 == 0.0
                                                             && v85[1] == 0.0 )
                                                        {
                                                          ++v84;
                                                          v85 += 56;
                                                          if ( v84 >= SLODWORD(vAlphaBlend.y) )
                                                            goto LABEL_121;
                                                        }
                                                        szKey[7] = 1;
LABEL_121:
                                                        v83 += 56 * LODWORD(vAlphaBlend.y);
                                                        --*(_DWORD *)szKey;
                                                      }
                                                      while ( *(_DWORD *)szKey != 0 );
                                                      if ( szKey[7] != 1 )
                                                        return CChunkFile::EndChunk(this: pFile);
                                                      v86 = pFile;
                                                      if ( CChunkFile::BeginChunk(
                                                             this: pFile,
                                                             pszChunkName: "multiblend") == ChunkFile_Ok )
                                                      {
                                                        v87 = vAlphaBlend.y;
                                                        v88 = 0;
                                                        vAlphaBlend.w = 0.0;
                                                        vAlphaBlend.x = 0.0;
                                                        do
                                                        {
                                                          v89 = 1;
                                                          temp[96] = 0;
                                                          *(float *)szKey = v87;
                                                          while ( 1 )
                                                          {
                                                            if ( v89 == 0 )
                                                            {
                                                              v90 = &temp[95];
                                                              do
                                                                v91 = *++v90;
                                                              while ( v91 != 0 );
                                                              strcpy(v90, " ");
                                                            }
                                                            v92 = *(_DWORD *)(LODWORD(startPosition.z) + 784);
                                                            v129 = *(float *)(v92 + v88 + 156);
                                                            v124 = *(float *)(v92 + v88 + 152);
                                                            v119 = *(float *)(v92 + v88 + 148);
                                                            v93 = *(float *)(v92 + v88 + 144);
                                                            szKey[7] = 0;
                                                            sprintf(
                                                              string: v133,
                                                              format: "%g %g %g %g",
                                                              v93,
                                                              v119,
                                                              v124,
                                                              v129);
                                                            v94 = strlen(v133) + 1;
                                                            v95 = &temp[95];
                                                            do
                                                              v96 = *++v95;
                                                            while ( v96 != 0 );
                                                            qmemcpy(v95, v133, v94);
                                                            v88 += 224;
                                                            if ( --*(_DWORD *)szKey == 0 )
                                                              break;
                                                            v89 = szKey[7];
                                                          }
                                                          v97 = vAlphaBlend.w;
                                                          sprintf(string: pszKey, format: "row%d", vAlphaBlend.w);
                                                          v86 = pFile;
                                                          v98 = CChunkFile::WriteKeyValue(
                                                                  this: pFile,
                                                                  pszKey,
                                                                  pszValue: &temp[96]);
                                                          v88 = LODWORD(vAlphaBlend.z) + LODWORD(vAlphaBlend.x);
                                                          v87 = vAlphaBlend.y;
                                                          LODWORD(vAlphaBlend.w) = LODWORD(v97) + 1;
                                                          LODWORD(vAlphaBlend.x) += LODWORD(vAlphaBlend.z);
                                                        }
                                                        while ( LODWORD(v97) + 1 < SLODWORD(vAlphaBlend.y) );
                                                        if ( v98 == ChunkFile_Ok )
                                                          CChunkFile::EndChunk(this: pFile);
                                                      }
                                                      if ( CChunkFile::BeginChunk(this: v86, pszChunkName: "alphablend") == ChunkFile_Ok )
                                                      {
                                                        v99 = vAlphaBlend.y;
                                                        vAlphaBlend.w = 0.0;
                                                        vAlphaBlend.x = 0.0;
                                                        v100 = 0;
                                                        do
                                                        {
                                                          v101 = 1;
                                                          temp[96] = 0;
                                                          *(float *)szKey = v99;
                                                          while ( 1 )
                                                          {
                                                            if ( v101 == 0 )
                                                            {
                                                              v102 = &temp[95];
                                                              do
                                                                v103 = *++v102;
                                                              while ( v103 != 0 );
                                                              strcpy(v102, " ");
                                                            }
                                                            v104 = *(_DWORD *)(LODWORD(startPosition.z) + 784);
                                                            v130 = *(float *)(v104 + v100 + 172);
                                                            v125 = *(float *)(v104 + v100 + 168);
                                                            v120 = *(float *)(v104 + v100 + 164);
                                                            v105 = *(float *)(v104 + v100 + 160);
                                                            szKey[7] = 0;
                                                            sprintf(
                                                              string: v133,
                                                              format: "%g %g %g %g",
                                                              v105,
                                                              v120,
                                                              v125,
                                                              v130);
                                                            v106 = strlen(v133) + 1;
                                                            v107 = &temp[95];
                                                            do
                                                              v108 = *++v107;
                                                            while ( v108 != 0 );
                                                            qmemcpy(v107, v133, v106);
                                                            v100 += 224;
                                                            if ( --*(_DWORD *)szKey == 0 )
                                                              break;
                                                            v101 = szKey[7];
                                                          }
                                                          v109 = vAlphaBlend.w;
                                                          sprintf(string: pszKey, format: "row%d", vAlphaBlend.w);
                                                          v110 = CChunkFile::WriteKeyValue(
                                                                   this: pFile,
                                                                   pszKey,
                                                                   pszValue: &temp[96]);
                                                          v100 = LODWORD(vAlphaBlend.z) + LODWORD(vAlphaBlend.x);
                                                          v99 = vAlphaBlend.y;
                                                          LODWORD(vAlphaBlend.w) = LODWORD(v109) + 1;
                                                          LODWORD(vAlphaBlend.x) += LODWORD(vAlphaBlend.z);
                                                        }
                                                        while ( LODWORD(v109) + 1 < SLODWORD(vAlphaBlend.y) );
                                                        if ( v110 == ChunkFile_Ok )
                                                          CChunkFile::EndChunk(this: pFile);
                                                      }
                                                      vAlphaBlend.z = 0.0;
                                                      LODWORD(vAlphaBlend.w) = &vColorBlend[0].y;
                                                      do
                                                      {
                                                        sprintf(
                                                          string: pszChunkName,
                                                          format: "multiblend_color_%d",
                                                          vAlphaBlend.z);
                                                        result = CChunkFile::BeginChunk(this: pFile, pszChunkName);
                                                        if ( result == ChunkFile_Ok )
                                                        {
                                                          *(_DWORD *)szKey = 0;
                                                          vAlphaBlend.x = 0.0;
                                                          do
                                                          {
                                                            v111 = 1;
                                                            temp[96] = 0;
                                                            v112 = 0;
                                                            while ( 1 )
                                                            {
                                                              if ( v111 == 0 )
                                                              {
                                                                v113 = &temp[95];
                                                                do
                                                                  v114 = *++v113;
                                                                while ( v114 != 0 );
                                                                strcpy(v113, " ");
                                                              }
                                                              szKey[7] = 0;
                                                              CCoreDispInfo::GetMultiBlend(
                                                                this: (CCoreDispInfo *)(LODWORD(startPosition.z) + 24),
                                                                index: v112 + LODWORD(vAlphaBlend.x),
                                                                vBlend: (Vector4D *)&szBuf[992],
                                                                vAlphaBlend: &v139,
                                                                vColor1: vColorBlend,
                                                                vColor2: &vColorBlend[1],
                                                                vColor3: &vColorBlend[2],
                                                                vColor4: &vColorBlend[3]);
                                                              sprintf(
                                                                string: &v132[4],
                                                                format: "%g %g %g",
                                                                *(float *)(LODWORD(vAlphaBlend.w) - 4),
                                                                *(float *)LODWORD(vAlphaBlend.w),
                                                                *(float *)(LODWORD(vAlphaBlend.w) + 4));
                                                              v115 = strlen(&v132[4]) + 1;
                                                              v116 = &temp[95];
                                                              do
                                                                v117 = *++v116;
                                                              while ( v117 != 0 );
                                                              qmemcpy(v116, &v132[4], v115);
                                                              if ( ++v112 >= SLODWORD(vAlphaBlend.y) )
                                                                break;
                                                              v111 = szKey[7];
                                                            }
                                                            v118 = *(_DWORD *)szKey;
                                                            sprintf(string: pszKey, format: "row%d", *(_DWORD *)szKey);
                                                            result = CChunkFile::WriteKeyValue(
                                                                       this: pFile,
                                                                       pszKey,
                                                                       pszValue: &temp[96]);
                                                            LODWORD(vAlphaBlend.x) += LODWORD(vAlphaBlend.y);
                                                            *(_DWORD *)szKey = v118 + 1;
                                                          }
                                                          while ( v118 + 1 < SLODWORD(vAlphaBlend.y) );
                                                          if ( result == ChunkFile_Ok )
                                                            result = CChunkFile::EndChunk(this: pFile);
                                                        }
                                                        LODWORD(vAlphaBlend.w) += 12;
                                                        ++LODWORD(vAlphaBlend.z);
                                                      }
                                                      while ( SLODWORD(vAlphaBlend.z) < 4 );
                                                      if ( result == ChunkFile_Ok )
                                                        return CChunkFile::EndChunk(this: pFile);
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011A8F0
// Name: private: void std::numpunct<char>::_Tidy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::numpunct<char>::_Tidy(std::numpunct<char> *this)
{
  operator delete(p: (void *)this->_Grouping);
  operator delete(p: (void *)this->_Falsename);
  operator delete(p: (void *)this->_Truename);
}

//------------------------------------------------------------------------------
// Address: 0x1011A920
// Name: char __near * std::_Maklocstr<char>(char const __near *,char __near *,struct _Cvtvec const __near &)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl std::_Maklocstr<char>(const char *_Ptr)
{
  const char *v1; // edi
  unsigned int v2; // kr00_4
  unsigned int v3; // esi
  char *result; // eax

  v1 = _Ptr;
  v2 = strlen(_Ptr);
  v3 = v2 + 1;
  result = (char *)operator new[](nSize: v2 + 1);
  if ( v2 != -1 )
  {
    do
    {
      v1[result - _Ptr] = *v1;
      ++v1;
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011A9C0
// Name: protected: void std::numpunct<char>::_Init(class std::_Locinfo const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1011AAC0
// Name: public: bool std::istreambuf_iterator<char,struct std::char_traits<char>>::equal(class std::istreambuf_iterator<char,struct std::char_traits<char>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::istreambuf_iterator<char>::equal(
        std::istreambuf_iterator<char> *this,
        const std::istreambuf_iterator<char> *_Right)
{
  std::streambuf *Strbuf; // ecx
  char **IGnext; // eax
  int v5; // eax
  std::streambuf *v6; // ecx
  char **v7; // eax
  int v8; // eax

  if ( !this->_Got )
  {
    Strbuf = this->_Strbuf;
    if ( this->_Strbuf == nullptr
      || (*(IGnext = Strbuf->_IGnext) == nullptr || *Strbuf->_IGcount <= 0
        ? (v5 = Strbuf->underflow(this: Strbuf))
        : (v5 = (unsigned __int8)**IGnext),
          v5 == -1) )
    {
      this->_Strbuf = nullptr;
    }
    else
    {
      this->_Val = v5;
    }
    this->_Got = true;
  }
  if ( !_Right->_Got )
  {
    v6 = _Right->_Strbuf;
    if ( _Right->_Strbuf == nullptr
      || (*(v7 = v6->_IGnext) == nullptr || *v6->_IGcount <= 0
        ? (v8 = v6->underflow(this: v6))
        : (v8 = (unsigned __int8)**v7),
          v8 == -1) )
    {
      _Right->_Strbuf = nullptr;
    }
    else
    {
      _Right->_Val = v8;
    }
    _Right->_Got = true;
  }
  if ( this->_Strbuf != nullptr )
  {
    if ( _Right->_Strbuf == nullptr )
      return 0;
  }
  else if ( _Right->_Strbuf != nullptr )
  {
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011AB70
// Name: protected: virtual char std::numpunct<char>::do_decimal_point(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall std::numpunct<char>::do_decimal_point(std::numpunct<char> *this)
{
  return this->_Dp;
}

//------------------------------------------------------------------------------
// Address: 0x1011AC10
// Name: public: void CMapDisp::Render3D(class CRender3D __near *,bool,enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::Render3D(CMapDisp *this, CRender3D *pRender, int bIsSelected, Color faceSelectionState)
{
  EditorRenderMode_t m_eCurrentRenderMode; // esi

  m_eCurrentRenderMode = pRender->m_eCurrentRenderMode;
  if ( m_eCurrentRenderMode == RENDER_MODE_SELECTION_OVERLAY )
  {
    CMapDisp::RenderOverlaySurface(
      this,
      a2: bIsSelected,
      a3: 12,
      pRender,
      bIsSelected,
      faceSelectionState: *(SelectionState_t *)&faceSelectionState);
  }
  else
  {
    CMapDisp::RenderSurface(this, pRender, bIsSelected, faceSelectionState: *(SelectionState_t *)&faceSelectionState);
    if ( m_eCurrentRenderMode != RENDER_MODE_WIREFRAME && (_BYTE)bIsSelected != 0 )
      CMapDisp::RenderWireframeSurface(this, a2: bIsSelected, a3: (int)this, pRender, bIsSelected, faceSelectionState);
  }
  if ( CMapDoc::m_pMapDoc->m_bDispDrawWalkable
    && (m_eCurrentRenderMode == RENDER_MODE_TEXTURED
     || m_eCurrentRenderMode == RENDER_MODE_TEXTURED_SHADED
     || m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED
     || m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW2) )
  {
    CMapDisp::RenderWalkableSurface(
      this,
      pRender,
      bIsSelected,
      faceSelectionState: *(SelectionState_t *)&faceSelectionState);
  }
  if ( CMapDoc::m_pMapDoc->m_bDispDrawBuildable
    && (m_eCurrentRenderMode == RENDER_MODE_TEXTURED
     || m_eCurrentRenderMode == RENDER_MODE_TEXTURED_SHADED
     || m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED
     || m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW2) )
  {
    CMapDisp::RenderBuildableSurface(
      this,
      pRender,
      bIsSelected,
      faceSelectionState: *(SelectionState_t *)&faceSelectionState);
  }
  if ( CMapDoc::m_pMapDoc->m_bDispDrawRemovedVerts
    && (m_eCurrentRenderMode == RENDER_MODE_TEXTURED
     || m_eCurrentRenderMode == RENDER_MODE_TEXTURED_SHADED
     || m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED
     || m_eCurrentRenderMode == RENDER_MODE_LIGHT_PREVIEW2) )
  {
    CMapDisp::RenderDisAllowedVerts(this, pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011AD00
// Name: private: static enum ChunkFileResult_t CMapDisp::LoadDispAllowedVertsCallback(class CChunkFile __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapDisp::LoadDispAllowedVertsCallback(CChunkFile *pFile, CMapDisp *pDisp)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispAllowedVertsKeyCallback,
           pData: pDisp);
}

//------------------------------------------------------------------------------
// Address: 0x1011AD20
// Name: public: enum ChunkFileResult_t CMapDisp::LoadVMF(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapDisp::LoadVMF(CMapDisp *this, CChunkFile *pFile)
{
  ChunkFileResult_t Chunk; // esi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-18h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v6 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "normals",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispNormalsCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "distances",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispDistancesCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "offsets",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispOffsetsCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "offset_normals",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispOffsetNormalsCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "alphas",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispAlphasCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "triangle_tags",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispTriangleTagsCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "allowed_verts",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispAllowedVertsCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "multiblend",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispMultiBlendCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "alphablend",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispAlphaBlendCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "multiblend_color_0",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispMultiBlendColorCallback0,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "multiblend_color_1",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispMultiBlendColorCallback1,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "multiblend_color_2",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispMultiBlendColorCallback2,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "multiblend_color_3",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDisp::LoadDispMultiBlendColorCallback3,
    pData: this);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapDisp::LoadDispKeyCallback,
            pData: this);
  CChunkFile::PopHandlers(this: pFile);
  v6 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x1011AE90
// Name: public: char std::istreambuf_iterator<char,struct std::char_traits<char>>::operator*(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall std::istreambuf_iterator<char>::operator*(std::istreambuf_iterator<char> *this)
{
  std::streambuf *Strbuf; // ecx
  char **IGnext; // eax
  int v4; // eax

  if ( this->_Got )
    goto LABEL_10;
  Strbuf = this->_Strbuf;
  if ( this->_Strbuf == nullptr
    || (*(IGnext = Strbuf->_IGnext) == nullptr || *Strbuf->_IGcount <= 0
      ? (v4 = Strbuf->underflow(this: Strbuf))
      : (v4 = (unsigned __int8)**IGnext),
        v4 == -1) )
  {
    this->_Strbuf = nullptr;
    this->_Got = true;
LABEL_10:
    LOBYTE(v4) = this->_Val;
    return v4;
  }
  this->_Val = v4;
  this->_Got = true;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1011AEE0
// Name: public: class std::istreambuf_iterator<char,struct std::char_traits<char>> __near & std::istreambuf_iterator<char,struct std::char_traits<char>>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::istreambuf_iterator<char>::operator++(
        std::istreambuf_iterator<char> *this)
{
  std::streambuf *Strbuf; // ecx
  int *IGcount; // edx
  char **IGnext; // ecx
  char *v5; // eax
  int v6; // eax

  Strbuf = this->_Strbuf;
  if ( Strbuf == nullptr
    || (*Strbuf->_IGnext == nullptr || *(IGcount = Strbuf->_IGcount) <= 0
      ? (v6 = Strbuf->uflow(this: Strbuf))
      : (--*IGcount, IGnext = Strbuf->_IGnext, v5 = *IGnext, ++*IGnext, v6 = (unsigned __int8)*v5),
        v6 == -1) )
  {
    this->_Strbuf = nullptr;
    this->_Got = true;
    return this;
  }
  else
  {
    this->_Got = false;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011AF30
// Name: public: static unsigned int std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::_Getcat(class std::locale::facet const __near * __near *,class std::locale const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl std::num_get<char,std::istreambuf_iterator<char>>::_Getcat(
        std::locale::facet **_Ppf,
        const std::locale *_Ploc)
{
  int v2; // ebx
  std::locale::facet *v3; // esi
  char *Myptr; // eax
  std::_Locinfo v6; // [esp+4h] [ebp-38h] BYREF
  void *p; // [esp+28h] [ebp-14h]
  unsigned int v8; // [esp+2Ch] [ebp-10h]
  int v9; // [esp+38h] [ebp-4h]

  v2 = 0;
  v8 = 0;
  if ( _Ppf != nullptr && *_Ppf == nullptr )
  {
    v3 = (std::locale::facet *)operator new(nSize: 0x10u);
    p = v3;
    v9 = 0;
    if ( v3 != nullptr )
    {
      if ( _Ploc->_Ptr->_Name._Myptr != nullptr )
        Myptr = _Ploc->_Ptr->_Name._Myptr;
      else
        Myptr = &_Ploc->_Ptr->_Name._Nul;
      std::_Locinfo::_Locinfo(this: &v6, _Pch: Myptr);
      v2 = 1;
      v8 = 1;
      v3->__vftable = (std::locale::facet_vtbl *)&std::locale::facet::`vftable';
      v3->_Refs = 0;
      v9 = 2;
      v3->__vftable = (std::locale::facet_vtbl *)&std::num_get<char,std::istreambuf_iterator<char>>::`vftable';
      v3[1] = (std::locale::facet)_Getcvt();
      LOBYTE(v9) = 1;
    }
    else
    {
      v3 = nullptr;
    }
    *_Ppf = v3;
    v9 = -1;
    if ( (v2 & 1) != 0 )
    {
      v8 = v2 & 0xFFFFFFFE;
      std::_Locinfo::~_Locinfo(this: &v6);
    }
  }
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x1011B010
// Name: public: static unsigned int std::numpunct<char>::_Getcat(class std::locale::facet const __near * __near *,class std::locale const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl std::numpunct<char>::_Getcat(std::numpunct<char> **_Ppf, const std::locale *_Ploc)
{
  int v2; // ebx
  std::numpunct<char> *v3; // esi
  char *Myptr; // eax
  const std::_Locinfo *v5; // eax
  std::_Locinfo v7; // [esp+4h] [ebp-38h] BYREF
  std::numpunct<char> *v8; // [esp+28h] [ebp-14h]
  unsigned int v9; // [esp+2Ch] [ebp-10h]
  int v10; // [esp+38h] [ebp-4h]

  v2 = 0;
  v9 = 0;
  if ( _Ppf != nullptr && *_Ppf == nullptr )
  {
    v3 = (std::numpunct<char> *)operator new(nSize: 0x18u);
    v8 = v3;
    v10 = 0;
    if ( v3 != nullptr )
    {
      if ( _Ploc->_Ptr->_Name._Myptr != nullptr )
        Myptr = _Ploc->_Ptr->_Name._Myptr;
      else
        Myptr = &_Ploc->_Ptr->_Name._Nul;
      v5 = std::_Locinfo::_Locinfo(this: &v7, _Pch: Myptr);
      v2 = 1;
      v9 = 1;
      v3->__vftable = (std::numpunct<char>_vtbl *)&std::locale::facet::`vftable';
      v3->_Refs = 0;
      v10 = 2;
      v3->__vftable = (std::numpunct<char>_vtbl *)&std::numpunct<char>::`vftable';
      std::numpunct<char>::_Init(this: v3, _Lobj: v5, _Isdef: true);
      LOBYTE(v10) = 1;
    }
    else
    {
      v3 = nullptr;
    }
    *_Ppf = v3;
    v10 = -1;
    if ( (v2 & 1) != 0 )
    {
      v9 = v2 & 0xFFFFFFFE;
      std::_Locinfo::~_Locinfo(this: &v7);
    }
  }
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x1011B0F0
// Name: public: CMapDisp::CMapDisp(void)
// Source: json
//------------------------------------------------------------------------------
CMapDisp *__thiscall CMapDisp::CMapDisp(CMapDisp *this)
{
  CoreDispVert_t **m_pMemory; // ecx
  unsigned __int16 *v3; // ecx
  unsigned __int16 *v4; // ecx
  CoreDispVert_t **v5; // ecx
  unsigned __int16 *v6; // ecx
  unsigned __int16 *v7; // ecx

  this->__vftable = (CMapAtom_vtbl *)&CMapAtom::`vftable';
  this->m_eSelectionState = SELECT_NONE;
  this->m_pParent = nullptr;
  this->m_nObjectID = CMapAtom::s_nObjectIDCtr++;
  this->__vftable = (CMapAtom_vtbl *)&CMapDisp::`vftable';
  CCoreDispInfo::CCoreDispInfo(this: &this->m_CoreDispInfo);
  this->m_aWalkableVerts.m_Memory.m_pMemory = nullptr;
  this->m_aWalkableVerts.m_Memory.m_nAllocationCount = 0;
  this->m_aWalkableVerts.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_aWalkableVerts.m_Memory.m_pMemory;
  this->m_aWalkableVerts.m_Size = 0;
  this->m_aWalkableVerts.m_pElements = m_pMemory;
  this->m_aWalkableIndices.m_Memory.m_pMemory = nullptr;
  this->m_aWalkableIndices.m_Memory.m_nAllocationCount = 0;
  this->m_aWalkableIndices.m_Memory.m_nGrowSize = 0;
  v3 = this->m_aWalkableIndices.m_Memory.m_pMemory;
  this->m_aWalkableIndices.m_Size = 0;
  this->m_aWalkableIndices.m_pElements = v3;
  this->m_aForcedWalkableIndices.m_Memory.m_pMemory = nullptr;
  this->m_aForcedWalkableIndices.m_Memory.m_nAllocationCount = 0;
  this->m_aForcedWalkableIndices.m_Memory.m_nGrowSize = 0;
  v4 = this->m_aForcedWalkableIndices.m_Memory.m_pMemory;
  this->m_aForcedWalkableIndices.m_Size = 0;
  this->m_aForcedWalkableIndices.m_pElements = v4;
  this->m_aBuildableVerts.m_Memory.m_pMemory = nullptr;
  this->m_aBuildableVerts.m_Memory.m_nAllocationCount = 0;
  this->m_aBuildableVerts.m_Memory.m_nGrowSize = 0;
  v5 = this->m_aBuildableVerts.m_Memory.m_pMemory;
  this->m_aBuildableVerts.m_Size = 0;
  this->m_aBuildableVerts.m_pElements = v5;
  this->m_aBuildableIndices.m_Memory.m_pMemory = nullptr;
  this->m_aBuildableIndices.m_Memory.m_nAllocationCount = 0;
  this->m_aBuildableIndices.m_Memory.m_nGrowSize = 0;
  v6 = this->m_aBuildableIndices.m_Memory.m_pMemory;
  this->m_aBuildableIndices.m_Size = 0;
  this->m_aBuildableIndices.m_pElements = v6;
  this->m_aForcedBuildableIndices.m_Memory.m_pMemory = nullptr;
  this->m_aForcedBuildableIndices.m_Memory.m_nAllocationCount = 0;
  this->m_aForcedBuildableIndices.m_Memory.m_nGrowSize = 0;
  v7 = this->m_aForcedBuildableIndices.m_Memory.m_pMemory;
  this->m_aForcedBuildableIndices.m_Size = 0;
  this->m_aForcedBuildableIndices.m_pElements = v7;
  CMapDisp::ResetNeighbors(this);
  this->m_bHasMappingAxes = false;
  this->m_HitTexelIndex = -1;
  this->m_HitDispIndex = -1;
  *(_QWORD *)&this->m_MapAxes[0].y = 0;
  this->m_MapAxes[0].x = 0.0;
  *(_QWORD *)&this->m_MapAxes[1].y = 0;
  this->m_MapAxes[1].x = 0.0;
  this->m_Scale = 1.0;
  *(_WORD *)&this->m_bSubdiv = 0;
  CCoreDispInfo::InitDispInfo(
    this: &this->m_CoreDispInfo,
    power: 4,
    minTess: 0,
    smoothingAngle: 0.0,
    alphas: nullptr,
    dispVectorField: nullptr,
    dispDistances: nullptr,
    nFlags: 0,
    pvMultiBlends: nullptr);
  CMapDisp::Paint_Init(this, nType: 0);
  if ( this != (CMapDisp *)-824 )
  {
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[0] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[1] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[2] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[3] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[4] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[5] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[6] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[7] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[8] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[9] = -1;
  }
  this->m_FoWTriSoupID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011B2E0
// Name: public: CMapDisp::~CMapDisp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::~CMapDisp(CMapDisp *this)
{
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_aBuildableIndices; // edi
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_aForcedBuildableIndices; // esi
  CFoW *m_pFoW; // ecx
  CUtlVector<CoreDispVert_t *,CUtlMemory<CoreDispVert_t *,int> > *p_m_aBuildableVerts; // esi
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_aForcedWalkableIndices; // esi
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_aWalkableIndices; // esi
  CUtlVector<CoreDispVert_t *,CUtlMemory<CoreDispVert_t *,int> > *p_m_aWalkableVerts; // esi

  this->__vftable = (CMapAtom_vtbl *)&CMapDisp::`vftable';
  this->m_aWalkableVerts.m_Size = 0;
  if ( this->m_aWalkableVerts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aWalkableVerts.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_aWalkableVerts.m_Memory.m_pMemory);
      this->m_aWalkableVerts.m_Memory.m_pMemory = nullptr;
    }
    this->m_aWalkableVerts.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aWalkableVerts.m_pElements = this->m_aWalkableVerts.m_Memory.m_pMemory;
  this->m_aWalkableIndices.m_Size = 0;
  if ( this->m_aWalkableIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aWalkableIndices.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_aWalkableIndices.m_Memory.m_pMemory);
      this->m_aWalkableIndices.m_Memory.m_pMemory = nullptr;
    }
    this->m_aWalkableIndices.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aWalkableIndices.m_pElements = this->m_aWalkableIndices.m_Memory.m_pMemory;
  this->m_aForcedWalkableIndices.m_Size = 0;
  if ( this->m_aForcedWalkableIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aForcedWalkableIndices.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_aForcedWalkableIndices.m_Memory.m_pMemory);
      this->m_aForcedWalkableIndices.m_Memory.m_pMemory = nullptr;
    }
    this->m_aForcedWalkableIndices.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aForcedWalkableIndices.m_pElements = this->m_aForcedWalkableIndices.m_Memory.m_pMemory;
  this->m_aBuildableVerts.m_Size = 0;
  if ( this->m_aBuildableVerts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aBuildableVerts.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_aBuildableVerts.m_Memory.m_pMemory);
      this->m_aBuildableVerts.m_Memory.m_pMemory = nullptr;
    }
    this->m_aBuildableVerts.m_Memory.m_nAllocationCount = 0;
  }
  p_m_aBuildableIndices = &this->m_aBuildableIndices;
  this->m_aBuildableVerts.m_pElements = this->m_aBuildableVerts.m_Memory.m_pMemory;
  this->m_aBuildableIndices.m_Size = 0;
  if ( this->m_aBuildableIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aBuildableIndices->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aBuildableIndices->m_Memory.m_pMemory);
      p_m_aBuildableIndices->m_Memory.m_pMemory = nullptr;
    }
    this->m_aBuildableIndices.m_Memory.m_nAllocationCount = 0;
  }
  p_m_aForcedBuildableIndices = &this->m_aForcedBuildableIndices;
  p_m_aBuildableIndices->m_pElements = p_m_aBuildableIndices->m_Memory.m_pMemory;
  p_m_aForcedBuildableIndices->m_Size = 0;
  if ( p_m_aForcedBuildableIndices->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aForcedBuildableIndices->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aForcedBuildableIndices->m_Memory.m_pMemory);
      p_m_aForcedBuildableIndices->m_Memory.m_pMemory = nullptr;
    }
    p_m_aForcedBuildableIndices->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aForcedBuildableIndices->m_pElements = p_m_aForcedBuildableIndices->m_Memory.m_pMemory;
  if ( this->m_FoWTriSoupID != -1 )
  {
    m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
    if ( m_pFoW != nullptr )
      CFoW::RemoveTriSoup(this: m_pFoW, nID: this->m_FoWTriSoupID);
    this->m_FoWTriSoupID = -1;
  }
  p_m_aForcedBuildableIndices->m_Size = 0;
  if ( p_m_aForcedBuildableIndices->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aForcedBuildableIndices->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aForcedBuildableIndices->m_Memory.m_pMemory);
      p_m_aForcedBuildableIndices->m_Memory.m_pMemory = nullptr;
    }
    p_m_aForcedBuildableIndices->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aForcedBuildableIndices->m_pElements = p_m_aForcedBuildableIndices->m_Memory.m_pMemory;
  if ( p_m_aForcedBuildableIndices->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aForcedBuildableIndices->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aForcedBuildableIndices->m_Memory.m_pMemory);
      p_m_aForcedBuildableIndices->m_Memory.m_pMemory = nullptr;
    }
    p_m_aForcedBuildableIndices->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aBuildableIndices->m_Size = 0;
  if ( p_m_aBuildableIndices->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aBuildableIndices->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aBuildableIndices->m_Memory.m_pMemory);
      p_m_aBuildableIndices->m_Memory.m_pMemory = nullptr;
    }
    p_m_aBuildableIndices->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aBuildableIndices->m_pElements = p_m_aBuildableIndices->m_Memory.m_pMemory;
  if ( p_m_aBuildableIndices->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aBuildableIndices->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aBuildableIndices->m_Memory.m_pMemory);
      p_m_aBuildableIndices->m_Memory.m_pMemory = nullptr;
    }
    p_m_aBuildableIndices->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aBuildableVerts = &this->m_aBuildableVerts;
  this->m_aBuildableVerts.m_Size = 0;
  if ( this->m_aBuildableVerts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aBuildableVerts->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aBuildableVerts->m_Memory.m_pMemory);
      p_m_aBuildableVerts->m_Memory.m_pMemory = nullptr;
    }
    this->m_aBuildableVerts.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aBuildableVerts.m_pElements = this->m_aBuildableVerts.m_Memory.m_pMemory;
  if ( this->m_aBuildableVerts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aBuildableVerts->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aBuildableVerts->m_Memory.m_pMemory);
      p_m_aBuildableVerts->m_Memory.m_pMemory = nullptr;
    }
    this->m_aBuildableVerts.m_Memory.m_nAllocationCount = 0;
  }
  p_m_aForcedWalkableIndices = &this->m_aForcedWalkableIndices;
  this->m_aForcedWalkableIndices.m_Size = 0;
  if ( this->m_aForcedWalkableIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aForcedWalkableIndices->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aForcedWalkableIndices->m_Memory.m_pMemory);
      p_m_aForcedWalkableIndices->m_Memory.m_pMemory = nullptr;
    }
    this->m_aForcedWalkableIndices.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aForcedWalkableIndices.m_pElements = this->m_aForcedWalkableIndices.m_Memory.m_pMemory;
  if ( this->m_aForcedWalkableIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aForcedWalkableIndices->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aForcedWalkableIndices->m_Memory.m_pMemory);
      p_m_aForcedWalkableIndices->m_Memory.m_pMemory = nullptr;
    }
    this->m_aForcedWalkableIndices.m_Memory.m_nAllocationCount = 0;
  }
  p_m_aWalkableIndices = &this->m_aWalkableIndices;
  this->m_aWalkableIndices.m_Size = 0;
  if ( this->m_aWalkableIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aWalkableIndices->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aWalkableIndices->m_Memory.m_pMemory);
      p_m_aWalkableIndices->m_Memory.m_pMemory = nullptr;
    }
    this->m_aWalkableIndices.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aWalkableIndices.m_pElements = this->m_aWalkableIndices.m_Memory.m_pMemory;
  if ( this->m_aWalkableIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aWalkableIndices->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aWalkableIndices->m_Memory.m_pMemory);
      p_m_aWalkableIndices->m_Memory.m_pMemory = nullptr;
    }
    this->m_aWalkableIndices.m_Memory.m_nAllocationCount = 0;
  }
  p_m_aWalkableVerts = &this->m_aWalkableVerts;
  this->m_aWalkableVerts.m_Size = 0;
  if ( this->m_aWalkableVerts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aWalkableVerts->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aWalkableVerts->m_Memory.m_pMemory);
      p_m_aWalkableVerts->m_Memory.m_pMemory = nullptr;
    }
    this->m_aWalkableVerts.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aWalkableVerts.m_pElements = this->m_aWalkableVerts.m_Memory.m_pMemory;
  if ( this->m_aWalkableVerts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aWalkableVerts->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aWalkableVerts->m_Memory.m_pMemory);
      p_m_aWalkableVerts->m_Memory.m_pMemory = nullptr;
    }
    this->m_aWalkableVerts.m_Memory.m_nAllocationCount = 0;
  }
  CCoreDispInfo::~CCoreDispInfo(this: &this->m_CoreDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1011B680
// Name: public: void CMapDisp::UpdateWalkable(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapDisp::UpdateWalkable(CMapDisp *this)
{
  int TriCount; // eax
  int esi1; // esi
  unsigned __int16 *p_m_uiTags; // eax
  CUtlMemory<CCullTreeNode *,int> *p_m_aWalkableVerts; // esi
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_aWalkableIndices; // edi
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_aForcedWalkableIndices; // ebx
  int m_nAllocationCount; // ecx
  CCullTreeNode **v9; // eax
  CCullTreeNode **v10; // edx
  int v11; // ecx
  int *v12; // eax
  int v13; // ecx
  CCullTreeNode **v14; // eax
  CCullTreeNode **v15; // edx
  int v16; // ecx
  int *v17; // eax
  CCullTreeNode **v18; // ecx
  int v19; // eax
  CCullTreeNode **v20; // edx
  int v21; // eax
  int *v22; // ecx
  int v23; // eax
  int v24; // ecx
  unsigned __int16 *v25; // edx
  int v26; // ecx
  unsigned __int16 *v27; // eax
  int v28; // ecx
  int v29; // eax
  unsigned __int16 *v30; // edx
  int v31; // eax
  unsigned __int16 *v32; // ecx
  int v33; // ecx
  int v34; // eax
  unsigned __int16 *v35; // edx
  int v36; // eax
  unsigned __int16 *v37; // edx
  int v38; // eax
  int v39; // ecx
  unsigned __int16 *v40; // edx
  int v41; // ecx
  unsigned __int16 *v42; // eax
  int v43; // ecx
  int v44; // eax
  unsigned __int16 *v45; // edx
  int v46; // eax
  unsigned __int16 *v47; // ecx
  int v48; // eax
  unsigned __int16 *v49; // edx
  int v50; // eax
  unsigned __int16 *v51; // ecx
  Vector v3; // [esp+Ch] [ebp-4Ch] BYREF
  Vector v1; // [esp+18h] [ebp-40h] BYREF
  Vector v2; // [esp+24h] [ebp-34h] BYREF
  __int64 triIndices; // [esp+30h] [ebp-28h] OVERLAPPED BYREF
  unsigned __int16 v56[2]; // [esp+38h] [ebp-20h] BYREF
  int m_Size; // [esp+3Ch] [ebp-1Ch]
  int nTriCount; // [esp+40h] [ebp-18h]
  CCullTreeNode **v59; // [esp+44h] [ebp-14h]
  CCullTreeNode **v60; // [esp+48h] [ebp-10h]
  CCullTreeNode **m_pMemory; // [esp+4Ch] [ebp-Ch]
  int iTri; // [esp+50h] [ebp-8h]
  CMapDisp *v63; // [esp+54h] [ebp-4h]

  v63 = this;
  TriCount = CCoreDispInfo::GetTriCount(this: &this->m_CoreDispInfo);
  esi1 = 0;
  nTriCount = TriCount;
  if ( TriCount > 0 )
  {
    do
    {
      CCoreDispInfo::GetTriPos(this: &this->m_CoreDispInfo, iTri: esi1, &v1, &v2, &v3);
      *(float *)&triIndices = (float)((float)(v3.y - v1.y) * (float)(v2.z - v1.z))
                            - (float)((float)(v3.z - v1.z) * (float)(v2.y - v1.y));
      *((float *)&triIndices + 1) = (float)((float)(v3.z - v1.z) * (float)(v2.x - v1.x))
                                  - (float)((float)(v2.z - v1.z) * (float)(v3.x - v1.x));
      *(float *)v56 = (float)((float)(v2.y - v1.y) * (float)(v3.x - v1.x))
                    - (float)((float)(v3.y - v1.y) * (float)(v2.x - v1.x));
      VectorNormalize(vec: (Vector *)&triIndices);
      p_m_uiTags = &this->m_CoreDispInfo.m_pTris[esi1].m_uiTags;
      *p_m_uiTags &= ~1u;
      if ( *(float *)v56 >= 0.69999999 )
        this->m_CoreDispInfo.m_pTris[esi1].m_uiTags |= 1u;
      ++esi1;
    }
    while ( esi1 < nTriCount );
    TriCount = nTriCount;
  }
  p_m_aWalkableVerts = (CUtlMemory<CCullTreeNode *,int> *)&this->m_aWalkableVerts;
  p_m_aWalkableIndices = &this->m_aWalkableIndices;
  this->m_aWalkableVerts.m_Size = 0;
  p_m_aForcedWalkableIndices = &this->m_aForcedWalkableIndices;
  p_m_aWalkableIndices->m_Size = 0;
  p_m_aForcedWalkableIndices->m_Size = 0;
  iTri = 0;
  if ( TriCount > 0 )
  {
    do
    {
      if ( (unsigned __int8)CCoreDispInfo::IsTriWalkable(this: &v63->m_CoreDispInfo, iTri) == 0 )
      {
        CCoreDispInfo::GetTriIndices(
          this: &v63->m_CoreDispInfo,
          iTri,
          v1: (unsigned __int16 *)&triIndices + 2,
          v2: (unsigned __int16 *)&triIndices + 3,
          v3: v56);
        m_nAllocationCount = p_m_aWalkableVerts->m_nAllocationCount;
        m_Size = (int)&v63->m_CoreDispInfo.m_pVerts[WORD2(triIndices)];
        m_pMemory = p_m_aWalkableVerts[1].m_pMemory;
        v9 = m_pMemory;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
        {
          CUtlMemory<CVisGroup *,int>::Grow(this: p_m_aWalkableVerts, num: (int)m_pMemory - m_nAllocationCount + 1);
          v9 = m_pMemory;
        }
        ++p_m_aWalkableVerts[1].m_pMemory;
        v10 = p_m_aWalkableVerts->m_pMemory;
        v11 = (char *)p_m_aWalkableVerts[1].m_pMemory - (char *)v9 - 1;
        p_m_aWalkableVerts[1].m_nAllocationCount = (int)p_m_aWalkableVerts->m_pMemory;
        if ( v11 > 0 )
        {
          _V_memmove(dest: &v10[(_DWORD)v9 + 1], src: &v10[(_DWORD)v9], count: 4 * v11);
          v9 = m_pMemory;
        }
        v12 = (int *)&p_m_aWalkableVerts->m_pMemory[(_DWORD)v9];
        if ( v12 != nullptr )
          *v12 = m_Size;
        v13 = p_m_aWalkableVerts->m_nAllocationCount;
        m_Size = (int)&v63->m_CoreDispInfo.m_pVerts[HIWORD(triIndices)];
        v60 = p_m_aWalkableVerts[1].m_pMemory;
        v14 = v60;
        if ( (int)v60 + 1 > v13 )
        {
          CUtlMemory<CVisGroup *,int>::Grow(this: p_m_aWalkableVerts, num: (int)v60 - v13 + 1);
          v14 = v60;
        }
        ++p_m_aWalkableVerts[1].m_pMemory;
        v15 = p_m_aWalkableVerts->m_pMemory;
        v16 = (char *)p_m_aWalkableVerts[1].m_pMemory - (char *)v14 - 1;
        p_m_aWalkableVerts[1].m_nAllocationCount = (int)p_m_aWalkableVerts->m_pMemory;
        if ( v16 > 0 )
        {
          _V_memmove(dest: &v15[(_DWORD)v14 + 1], src: &v15[(_DWORD)v14], count: 4 * v16);
          v14 = v60;
        }
        v17 = (int *)&p_m_aWalkableVerts->m_pMemory[(_DWORD)v14];
        if ( v17 != nullptr )
          *v17 = m_Size;
        v18 = p_m_aWalkableVerts[1].m_pMemory;
        m_Size = (int)&v63->m_CoreDispInfo.m_pVerts[v56[0]];
        v19 = p_m_aWalkableVerts->m_nAllocationCount;
        v59 = v18;
        if ( (int)v18 + 1 > v19 )
        {
          CUtlMemory<CVisGroup *,int>::Grow(this: p_m_aWalkableVerts, num: (int)v18 - v19 + 1);
          v18 = v59;
        }
        ++p_m_aWalkableVerts[1].m_pMemory;
        v20 = p_m_aWalkableVerts->m_pMemory;
        v21 = (char *)p_m_aWalkableVerts[1].m_pMemory - (char *)v18 - 1;
        p_m_aWalkableVerts[1].m_nAllocationCount = (int)p_m_aWalkableVerts->m_pMemory;
        if ( v21 > 0 )
        {
          _V_memmove(dest: &v20[(_DWORD)v18 + 1], src: &v20[(_DWORD)v18], count: 4 * v21);
          v18 = v59;
        }
        v22 = (int *)&p_m_aWalkableVerts->m_pMemory[(_DWORD)v18];
        if ( v22 != nullptr )
          *v22 = m_Size;
        if ( (v63->m_CoreDispInfo.m_pTris[iTri].m_uiTags & 2) != 0 )
        {
          v24 = p_m_aForcedWalkableIndices->m_Memory.m_nAllocationCount;
          m_Size = p_m_aForcedWalkableIndices->m_Size;
          v23 = m_Size;
          if ( m_Size + 1 > v24 )
          {
            CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_aForcedWalkableIndices->m_Memory, num: m_Size - v24 + 1);
            v23 = m_Size;
          }
          ++p_m_aForcedWalkableIndices->m_Size;
          v25 = p_m_aForcedWalkableIndices->m_Memory.m_pMemory;
          v26 = p_m_aForcedWalkableIndices->m_Size - v23 - 1;
          p_m_aForcedWalkableIndices->m_pElements = p_m_aForcedWalkableIndices->m_Memory.m_pMemory;
          if ( v26 > 0 )
          {
            _V_memmove(dest: &v25[v23 + 1], src: &v25[v23], count: 2 * v26);
            v23 = m_Size;
          }
          v27 = &p_m_aForcedWalkableIndices->m_Memory.m_pMemory[v23];
          if ( v27 != nullptr )
            *v27 = (unsigned __int16)m_pMemory;
          v29 = p_m_aForcedWalkableIndices->m_Memory.m_nAllocationCount;
          m_Size = p_m_aForcedWalkableIndices->m_Size;
          v28 = m_Size;
          if ( m_Size + 1 > v29 )
          {
            CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_aForcedWalkableIndices->m_Memory, num: m_Size - v29 + 1);
            v28 = m_Size;
          }
          ++p_m_aForcedWalkableIndices->m_Size;
          v30 = p_m_aForcedWalkableIndices->m_Memory.m_pMemory;
          v31 = p_m_aForcedWalkableIndices->m_Size - v28 - 1;
          p_m_aForcedWalkableIndices->m_pElements = p_m_aForcedWalkableIndices->m_Memory.m_pMemory;
          if ( v31 > 0 )
          {
            _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 2 * v31);
            v28 = m_Size;
          }
          v32 = &p_m_aForcedWalkableIndices->m_Memory.m_pMemory[v28];
          if ( v32 != nullptr )
            *v32 = (unsigned __int16)v60;
          v34 = p_m_aForcedWalkableIndices->m_Memory.m_nAllocationCount;
          m_Size = p_m_aForcedWalkableIndices->m_Size;
          v33 = m_Size;
          if ( m_Size + 1 > v34 )
          {
            CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_aForcedWalkableIndices->m_Memory, num: m_Size - v34 + 1);
            v33 = m_Size;
          }
          ++p_m_aForcedWalkableIndices->m_Size;
          v35 = p_m_aForcedWalkableIndices->m_Memory.m_pMemory;
          v36 = p_m_aForcedWalkableIndices->m_Size - v33 - 1;
          p_m_aForcedWalkableIndices->m_pElements = p_m_aForcedWalkableIndices->m_Memory.m_pMemory;
          if ( v36 > 0 )
          {
            _V_memmove(dest: &v35[v33 + 1], src: &v35[v33], count: 2 * v36);
            v33 = m_Size;
          }
          v37 = p_m_aForcedWalkableIndices->m_Memory.m_pMemory;
        }
        else
        {
          v39 = p_m_aWalkableIndices->m_Memory.m_nAllocationCount;
          m_Size = p_m_aWalkableIndices->m_Size;
          v38 = m_Size;
          if ( m_Size + 1 > v39 )
          {
            CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_aWalkableIndices->m_Memory, num: m_Size - v39 + 1);
            v38 = m_Size;
          }
          ++p_m_aWalkableIndices->m_Size;
          v40 = p_m_aWalkableIndices->m_Memory.m_pMemory;
          v41 = p_m_aWalkableIndices->m_Size - v38 - 1;
          p_m_aWalkableIndices->m_pElements = p_m_aWalkableIndices->m_Memory.m_pMemory;
          if ( v41 > 0 )
          {
            _V_memmove(dest: &v40[v38 + 1], src: &v40[v38], count: 2 * v41);
            v38 = m_Size;
          }
          v42 = &p_m_aWalkableIndices->m_Memory.m_pMemory[v38];
          if ( v42 != nullptr )
            *v42 = (unsigned __int16)m_pMemory;
          v44 = p_m_aWalkableIndices->m_Memory.m_nAllocationCount;
          m_Size = p_m_aWalkableIndices->m_Size;
          v43 = m_Size;
          if ( m_Size + 1 > v44 )
          {
            CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_aWalkableIndices->m_Memory, num: m_Size - v44 + 1);
            v43 = m_Size;
          }
          ++p_m_aWalkableIndices->m_Size;
          v45 = p_m_aWalkableIndices->m_Memory.m_pMemory;
          v46 = p_m_aWalkableIndices->m_Size - v43 - 1;
          p_m_aWalkableIndices->m_pElements = p_m_aWalkableIndices->m_Memory.m_pMemory;
          if ( v46 > 0 )
          {
            _V_memmove(dest: &v45[v43 + 1], src: &v45[v43], count: 2 * v46);
            v43 = m_Size;
          }
          v47 = &p_m_aWalkableIndices->m_Memory.m_pMemory[v43];
          if ( v47 != nullptr )
            *v47 = (unsigned __int16)v60;
          v48 = p_m_aWalkableIndices->m_Memory.m_nAllocationCount;
          m_Size = p_m_aWalkableIndices->m_Size;
          v33 = m_Size;
          if ( m_Size + 1 > v48 )
          {
            CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_aWalkableIndices->m_Memory, num: m_Size - v48 + 1);
            v33 = m_Size;
          }
          ++p_m_aWalkableIndices->m_Size;
          v49 = p_m_aWalkableIndices->m_Memory.m_pMemory;
          v50 = p_m_aWalkableIndices->m_Size - v33 - 1;
          p_m_aWalkableIndices->m_pElements = p_m_aWalkableIndices->m_Memory.m_pMemory;
          if ( v50 > 0 )
          {
            _V_memmove(dest: &v49[v33 + 1], src: &v49[v33], count: 2 * v50);
            v33 = m_Size;
          }
          v37 = p_m_aWalkableIndices->m_Memory.m_pMemory;
        }
        v51 = &v37[v33];
        if ( v51 != nullptr )
          *v51 = (unsigned __int16)v59;
      }
      ++iTri;
    }
    while ( iTri < nTriCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011BB50
// Name: public: void CMapDisp::UpdateBuildable(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapDisp::UpdateBuildable(CMapDisp *this)
{
  int TriCount; // eax
  int esi1; // esi
  unsigned __int16 *p_m_uiTags; // eax
  CUtlMemory<CCullTreeNode *,int> *p_m_aBuildableVerts; // esi
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_aBuildableIndices; // edi
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_aForcedBuildableIndices; // ebx
  int m_nAllocationCount; // ecx
  CCullTreeNode **v9; // eax
  CCullTreeNode **v10; // edx
  int v11; // ecx
  int *v12; // eax
  int v13; // ecx
  CCullTreeNode **v14; // eax
  CCullTreeNode **v15; // edx
  int v16; // ecx
  int *v17; // eax
  CCullTreeNode **v18; // ecx
  int v19; // eax
  CCullTreeNode **v20; // edx
  int v21; // eax
  int *v22; // ecx
  int v23; // eax
  int v24; // ecx
  unsigned __int16 *v25; // edx
  int v26; // ecx
  unsigned __int16 *v27; // eax
  int v28; // ecx
  int v29; // eax
  unsigned __int16 *v30; // edx
  int v31; // eax
  unsigned __int16 *v32; // ecx
  int v33; // ecx
  int v34; // eax
  unsigned __int16 *v35; // edx
  int v36; // eax
  unsigned __int16 *v37; // edx
  int v38; // eax
  int v39; // ecx
  unsigned __int16 *v40; // edx
  int v41; // ecx
  unsigned __int16 *v42; // eax
  int v43; // ecx
  int v44; // eax
  unsigned __int16 *v45; // edx
  int v46; // eax
  unsigned __int16 *v47; // ecx
  int v48; // eax
  unsigned __int16 *v49; // edx
  int v50; // eax
  unsigned __int16 *v51; // ecx
  Vector v3; // [esp+Ch] [ebp-4Ch] BYREF
  Vector v1; // [esp+18h] [ebp-40h] BYREF
  Vector v2; // [esp+24h] [ebp-34h] BYREF
  __int64 triIndices; // [esp+30h] [ebp-28h] OVERLAPPED BYREF
  unsigned __int16 v56[2]; // [esp+38h] [ebp-20h] BYREF
  int m_Size; // [esp+3Ch] [ebp-1Ch]
  int nTriCount; // [esp+40h] [ebp-18h]
  CCullTreeNode **v59; // [esp+44h] [ebp-14h]
  CCullTreeNode **v60; // [esp+48h] [ebp-10h]
  CCullTreeNode **m_pMemory; // [esp+4Ch] [ebp-Ch]
  int iTri; // [esp+50h] [ebp-8h]
  CMapDisp *v63; // [esp+54h] [ebp-4h]

  v63 = this;
  TriCount = CCoreDispInfo::GetTriCount(this: &this->m_CoreDispInfo);
  esi1 = 0;
  nTriCount = TriCount;
  if ( TriCount > 0 )
  {
    do
    {
      CCoreDispInfo::GetTriPos(this: &this->m_CoreDispInfo, iTri: esi1, &v1, &v2, &v3);
      *(float *)&triIndices = (float)((float)(v3.y - v1.y) * (float)(v2.z - v1.z))
                            - (float)((float)(v3.z - v1.z) * (float)(v2.y - v1.y));
      *((float *)&triIndices + 1) = (float)((float)(v3.z - v1.z) * (float)(v2.x - v1.x))
                                  - (float)((float)(v2.z - v1.z) * (float)(v3.x - v1.x));
      *(float *)v56 = (float)((float)(v2.y - v1.y) * (float)(v3.x - v1.x))
                    - (float)((float)(v3.y - v1.y) * (float)(v2.x - v1.x));
      VectorNormalize(vec: (Vector *)&triIndices);
      p_m_uiTags = &this->m_CoreDispInfo.m_pTris[esi1].m_uiTags;
      *p_m_uiTags &= ~8u;
      if ( *(float *)v56 >= 0.80000001 )
        this->m_CoreDispInfo.m_pTris[esi1].m_uiTags |= 8u;
      ++esi1;
    }
    while ( esi1 < nTriCount );
    TriCount = nTriCount;
  }
  p_m_aBuildableVerts = (CUtlMemory<CCullTreeNode *,int> *)&this->m_aBuildableVerts;
  p_m_aBuildableIndices = &this->m_aBuildableIndices;
  this->m_aBuildableVerts.m_Size = 0;
  p_m_aForcedBuildableIndices = &this->m_aForcedBuildableIndices;
  p_m_aBuildableIndices->m_Size = 0;
  p_m_aForcedBuildableIndices->m_Size = 0;
  iTri = 0;
  if ( TriCount > 0 )
  {
    do
    {
      if ( !CCoreDispInfo::IsTriBuildable(this: &v63->m_CoreDispInfo, iTri) )
      {
        CCoreDispInfo::GetTriIndices(
          this: &v63->m_CoreDispInfo,
          iTri,
          v1: (unsigned __int16 *)&triIndices + 2,
          v2: (unsigned __int16 *)&triIndices + 3,
          v3: v56);
        m_nAllocationCount = p_m_aBuildableVerts->m_nAllocationCount;
        m_Size = (int)&v63->m_CoreDispInfo.m_pVerts[WORD2(triIndices)];
        m_pMemory = p_m_aBuildableVerts[1].m_pMemory;
        v9 = m_pMemory;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
        {
          CUtlMemory<CVisGroup *,int>::Grow(this: p_m_aBuildableVerts, num: (int)m_pMemory - m_nAllocationCount + 1);
          v9 = m_pMemory;
        }
        ++p_m_aBuildableVerts[1].m_pMemory;
        v10 = p_m_aBuildableVerts->m_pMemory;
        v11 = (char *)p_m_aBuildableVerts[1].m_pMemory - (char *)v9 - 1;
        p_m_aBuildableVerts[1].m_nAllocationCount = (int)p_m_aBuildableVerts->m_pMemory;
        if ( v11 > 0 )
        {
          _V_memmove(dest: &v10[(_DWORD)v9 + 1], src: &v10[(_DWORD)v9], count: 4 * v11);
          v9 = m_pMemory;
        }
        v12 = (int *)&p_m_aBuildableVerts->m_pMemory[(_DWORD)v9];
        if ( v12 != nullptr )
          *v12 = m_Size;
        v13 = p_m_aBuildableVerts->m_nAllocationCount;
        m_Size = (int)&v63->m_CoreDispInfo.m_pVerts[HIWORD(triIndices)];
        v60 = p_m_aBuildableVerts[1].m_pMemory;
        v14 = v60;
        if ( (int)v60 + 1 > v13 )
        {
          CUtlMemory<CVisGroup *,int>::Grow(this: p_m_aBuildableVerts, num: (int)v60 - v13 + 1);
          v14 = v60;
        }
        ++p_m_aBuildableVerts[1].m_pMemory;
        v15 = p_m_aBuildableVerts->m_pMemory;
        v16 = (char *)p_m_aBuildableVerts[1].m_pMemory - (char *)v14 - 1;
        p_m_aBuildableVerts[1].m_nAllocationCount = (int)p_m_aBuildableVerts->m_pMemory;
        if ( v16 > 0 )
        {
          _V_memmove(dest: &v15[(_DWORD)v14 + 1], src: &v15[(_DWORD)v14], count: 4 * v16);
          v14 = v60;
        }
        v17 = (int *)&p_m_aBuildableVerts->m_pMemory[(_DWORD)v14];
        if ( v17 != nullptr )
          *v17 = m_Size;
        v18 = p_m_aBuildableVerts[1].m_pMemory;
        m_Size = (int)&v63->m_CoreDispInfo.m_pVerts[v56[0]];
        v19 = p_m_aBuildableVerts->m_nAllocationCount;
        v59 = v18;
        if ( (int)v18 + 1 > v19 )
        {
          CUtlMemory<CVisGroup *,int>::Grow(this: p_m_aBuildableVerts, num: (int)v18 - v19 + 1);
          v18 = v59;
        }
        ++p_m_aBuildableVerts[1].m_pMemory;
        v20 = p_m_aBuildableVerts->m_pMemory;
        v21 = (char *)p_m_aBuildableVerts[1].m_pMemory - (char *)v18 - 1;
        p_m_aBuildableVerts[1].m_nAllocationCount = (int)p_m_aBuildableVerts->m_pMemory;
        if ( v21 > 0 )
        {
          _V_memmove(dest: &v20[(_DWORD)v18 + 1], src: &v20[(_DWORD)v18], count: 4 * v21);
          v18 = v59;
        }
        v22 = (int *)&p_m_aBuildableVerts->m_pMemory[(_DWORD)v18];
        if ( v22 != nullptr )
          *v22 = m_Size;
        if ( (v63->m_CoreDispInfo.m_pTris[iTri].m_uiTags & 0x10) != 0 )
        {
          v24 = p_m_aForcedBuildableIndices->m_Memory.m_nAllocationCount;
          m_Size = p_m_aForcedBuildableIndices->m_Size;
          v23 = m_Size;
          if ( m_Size + 1 > v24 )
          {
            CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_aForcedBuildableIndices->m_Memory, num: m_Size - v24 + 1);
            v23 = m_Size;
          }
          ++p_m_aForcedBuildableIndices->m_Size;
          v25 = p_m_aForcedBuildableIndices->m_Memory.m_pMemory;
          v26 = p_m_aForcedBuildableIndices->m_Size - v23 - 1;
          p_m_aForcedBuildableIndices->m_pElements = p_m_aForcedBuildableIndices->m_Memory.m_pMemory;
          if ( v26 > 0 )
          {
            _V_memmove(dest: &v25[v23 + 1], src: &v25[v23], count: 2 * v26);
            v23 = m_Size;
          }
          v27 = &p_m_aForcedBuildableIndices->m_Memory.m_pMemory[v23];
          if ( v27 != nullptr )
            *v27 = (unsigned __int16)m_pMemory;
          v29 = p_m_aForcedBuildableIndices->m_Memory.m_nAllocationCount;
          m_Size = p_m_aForcedBuildableIndices->m_Size;
          v28 = m_Size;
          if ( m_Size + 1 > v29 )
          {
            CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_aForcedBuildableIndices->m_Memory, num: m_Size - v29 + 1);
            v28 = m_Size;
          }
          ++p_m_aForcedBuildableIndices->m_Size;
          v30 = p_m_aForcedBuildableIndices->m_Memory.m_pMemory;
          v31 = p_m_aForcedBuildableIndices->m_Size - v28 - 1;
          p_m_aForcedBuildableIndices->m_pElements = p_m_aForcedBuildableIndices->m_Memory.m_pMemory;
          if ( v31 > 0 )
          {
            _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 2 * v31);
            v28 = m_Size;
          }
          v32 = &p_m_aForcedBuildableIndices->m_Memory.m_pMemory[v28];
          if ( v32 != nullptr )
            *v32 = (unsigned __int16)v60;
          v34 = p_m_aForcedBuildableIndices->m_Memory.m_nAllocationCount;
          m_Size = p_m_aForcedBuildableIndices->m_Size;
          v33 = m_Size;
          if ( m_Size + 1 > v34 )
          {
            CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_aForcedBuildableIndices->m_Memory, num: m_Size - v34 + 1);
            v33 = m_Size;
          }
          ++p_m_aForcedBuildableIndices->m_Size;
          v35 = p_m_aForcedBuildableIndices->m_Memory.m_pMemory;
          v36 = p_m_aForcedBuildableIndices->m_Size - v33 - 1;
          p_m_aForcedBuildableIndices->m_pElements = p_m_aForcedBuildableIndices->m_Memory.m_pMemory;
          if ( v36 > 0 )
          {
            _V_memmove(dest: &v35[v33 + 1], src: &v35[v33], count: 2 * v36);
            v33 = m_Size;
          }
          v37 = p_m_aForcedBuildableIndices->m_Memory.m_pMemory;
        }
        else
        {
          v39 = p_m_aBuildableIndices->m_Memory.m_nAllocationCount;
          m_Size = p_m_aBuildableIndices->m_Size;
          v38 = m_Size;
          if ( m_Size + 1 > v39 )
          {
            CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_aBuildableIndices->m_Memory, num: m_Size - v39 + 1);
            v38 = m_Size;
          }
          ++p_m_aBuildableIndices->m_Size;
          v40 = p_m_aBuildableIndices->m_Memory.m_pMemory;
          v41 = p_m_aBuildableIndices->m_Size - v38 - 1;
          p_m_aBuildableIndices->m_pElements = p_m_aBuildableIndices->m_Memory.m_pMemory;
          if ( v41 > 0 )
          {
            _V_memmove(dest: &v40[v38 + 1], src: &v40[v38], count: 2 * v41);
            v38 = m_Size;
          }
          v42 = &p_m_aBuildableIndices->m_Memory.m_pMemory[v38];
          if ( v42 != nullptr )
            *v42 = (unsigned __int16)m_pMemory;
          v44 = p_m_aBuildableIndices->m_Memory.m_nAllocationCount;
          m_Size = p_m_aBuildableIndices->m_Size;
          v43 = m_Size;
          if ( m_Size + 1 > v44 )
          {
            CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_aBuildableIndices->m_Memory, num: m_Size - v44 + 1);
            v43 = m_Size;
          }
          ++p_m_aBuildableIndices->m_Size;
          v45 = p_m_aBuildableIndices->m_Memory.m_pMemory;
          v46 = p_m_aBuildableIndices->m_Size - v43 - 1;
          p_m_aBuildableIndices->m_pElements = p_m_aBuildableIndices->m_Memory.m_pMemory;
          if ( v46 > 0 )
          {
            _V_memmove(dest: &v45[v43 + 1], src: &v45[v43], count: 2 * v46);
            v43 = m_Size;
          }
          v47 = &p_m_aBuildableIndices->m_Memory.m_pMemory[v43];
          if ( v47 != nullptr )
            *v47 = (unsigned __int16)v60;
          v48 = p_m_aBuildableIndices->m_Memory.m_nAllocationCount;
          m_Size = p_m_aBuildableIndices->m_Size;
          v33 = m_Size;
          if ( m_Size + 1 > v48 )
          {
            CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_aBuildableIndices->m_Memory, num: m_Size - v48 + 1);
            v33 = m_Size;
          }
          ++p_m_aBuildableIndices->m_Size;
          v49 = p_m_aBuildableIndices->m_Memory.m_pMemory;
          v50 = p_m_aBuildableIndices->m_Size - v33 - 1;
          p_m_aBuildableIndices->m_pElements = p_m_aBuildableIndices->m_Memory.m_pMemory;
          if ( v50 > 0 )
          {
            _V_memmove(dest: &v49[v33 + 1], src: &v49[v33], count: 2 * v50);
            v33 = m_Size;
          }
          v37 = p_m_aBuildableIndices->m_Memory.m_pMemory;
        }
        v51 = &v37[v33];
        if ( v51 != nullptr )
          *v51 = (unsigned __int16)v59;
      }
      ++iTri;
    }
    while ( iTri < nTriCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C020
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> std::numpunct<char>::falsename(void)const
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::numpunct<char>::falsename(std::numpunct<char> *this, std::string *result)
{
  this->do_falsename(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011C070
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> std::numpunct<char>::truename(void)const
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::numpunct<char>::truename(std::numpunct<char> *this, std::string *result)
{
  this->do_truename(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011C0C0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> std::numpunct<char>::grouping(void)const
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::numpunct<char>::grouping(std::numpunct<char> *this, std::string *result)
{
  this->do_grouping(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011C110
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::append(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::append(
        std::string *this,
        const std::string *_Right,
        unsigned int _Roff,
        unsigned int _Count)
{
  const std::string *v4; // edx
  unsigned int Mysize; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned int Myres; // ecx
  const std::string *Ptr; // ecx
  std::string *v14; // eax
  bool v15; // cf

  v4 = _Right;
  Mysize = _Right->_Mysize;
  if ( Mysize < _Roff )
    std::_Xout_of_range(_Message: "invalid string position");
  v7 = _Count;
  v8 = Mysize - _Roff;
  if ( v8 < _Count )
    v7 = v8;
  v9 = this->_Mysize;
  if ( -1 - v9 <= v7 )
    std::_Xlength_error(_Message: "string too long");
  if ( v7 == 0 )
    return this;
  v10 = v9 + v7;
  if ( v9 + v7 == -1 )
    std::_Xlength_error(_Message: "string too long");
  Myres = this->_Myres;
  if ( Myres < v10 )
  {
    std::string::_Copy(this, _Newsize: v9 + v7, _Oldlen: v9);
    v4 = _Right;
    if ( v10 != 0 )
    {
LABEL_12:
      if ( v4->_Myres < 0x10 )
        Ptr = v4;
      else
        Ptr = (const std::string *)v4->_Bx._Ptr;
      if ( this->_Myres < 0x10 )
        v14 = this;
      else
        v14 = (std::string *)this->_Bx._Ptr;
      memcpy(
        dst: (unsigned __int8 *)&v14->_Bx._Buf[this->_Mysize],
        src: (unsigned __int8 *)&Ptr->_Bx._Buf[_Roff],
        count: v7);
      v15 = this->_Myres < 0x10;
      this->_Mysize = v10;
      if ( !v15 )
      {
        this->_Bx._Ptr[v10] = 0;
        return this;
      }
      this->_Bx._Buf[v10] = 0;
    }
    return this;
  }
  if ( v10 != 0 )
    goto LABEL_12;
  this->_Mysize = 0;
  if ( Myres < 0x10 )
    this->_Bx._Buf[0] = 0;
  else
    *this->_Bx._Ptr = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011C200
// Name: class std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>> const __near & std::use_facet<class std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>>(class std::locale const __near &)
// Source: json
//------------------------------------------------------------------------------
const std::num_get<char,std::istreambuf_iterator<char> > *__cdecl std::use_facet<std::num_get<char,std::istreambuf_iterator<char>>>(
        const std::locale *_Loc)
{
  unsigned int Id; // esi
  std::locale::_Locimp *Ptr; // eax
  std::locale::facet *v3; // ecx
  std::locale::_Locimp *v4; // eax
  std::locale::facet *v5; // esi
  std::bad_cast pExceptionObject; // [esp+0h] [ebp-24h] BYREF
  std::_Lockit _Lock; // [esp+Ch] [ebp-18h] BYREF
  std::_Lockit v9; // [esp+10h] [ebp-14h] BYREF
  const std::locale::facet *_Psave; // [esp+14h] [ebp-10h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  std::_Lockit::_Lockit(this: &_Lock, kind: 0);
  v11 = 0;
  _Psave = std::_Facetptr<std::num_get<char,std::istreambuf_iterator<char>>>::_Psave;
  if ( std::num_get<char,std::istreambuf_iterator<char>>::id._Id == 0 )
  {
    std::_Lockit::_Lockit(this: &v9, kind: 0);
    LOBYTE(v11) = 1;
    if ( std::num_get<char,std::istreambuf_iterator<char>>::id._Id == 0 )
      std::num_get<char,std::istreambuf_iterator<char>>::id._Id = ++std::locale::id::_Id_cnt;
    LOBYTE(v11) = 0;
    std::_Lockit::~_Lockit(this: &v9);
  }
  Id = std::num_get<char,std::istreambuf_iterator<char>>::id._Id;
  Ptr = _Loc->_Ptr;
  if ( std::num_get<char,std::istreambuf_iterator<char>>::id._Id >= _Loc->_Ptr->_Facetcount )
  {
    v3 = nullptr;
  }
  else
  {
    v3 = Ptr->_Facetvec[std::num_get<char,std::istreambuf_iterator<char>>::id._Id];
    if ( v3 != nullptr )
    {
LABEL_11:
      v5 = v3;
LABEL_12:
      if ( v5 != nullptr )
        goto LABEL_17;
      goto LABEL_13;
    }
  }
  if ( !Ptr->_Xparent )
    goto LABEL_11;
  v4 = std::locale::_Getgloballocale();
  if ( Id < v4->_Facetcount )
  {
    v5 = v4->_Facetvec[Id];
    goto LABEL_12;
  }
LABEL_13:
  v5 = (std::locale::facet *)_Psave;
  if ( _Psave == nullptr )
  {
    if ( std::num_get<char,std::istreambuf_iterator<char>>::_Getcat(_Ppf: (std::locale::facet **)&_Psave, _Ploc: _Loc) == -1 )
    {
      std::bad_cast::bad_cast(this: &pExceptionObject, _Message: "bad cast");
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_cast_std__);
    }
    v5 = (std::locale::facet *)_Psave;
    std::_Facetptr<std::num_get<char,std::istreambuf_iterator<char>>>::_Psave = _Psave;
    std::locale::facet::_Incref(this: (std::locale::facet *)_Psave);
    std::locale::facet::_Facet_Register(_This: v5);
  }
LABEL_17:
  v11 = -1;
  std::_Lockit::~_Lockit(this: &_Lock);
  return (const std::num_get<char,std::istreambuf_iterator<char> > *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x1011C320
// Name: class std::numpunct<char> const __near & std::use_facet<class std::numpunct<char>>(class std::locale const __near &)
// Source: json
//------------------------------------------------------------------------------
const std::numpunct<char> *__cdecl std::use_facet<std::numpunct<char>>(const std::locale *_Loc)
{
  unsigned int Id; // esi
  std::locale::_Locimp *Ptr; // eax
  std::locale::facet *v3; // ecx
  std::locale::_Locimp *v4; // eax
  std::locale::facet *v5; // esi
  std::bad_cast pExceptionObject; // [esp+0h] [ebp-24h] BYREF
  std::_Lockit _Lock; // [esp+Ch] [ebp-18h] BYREF
  std::_Lockit v9; // [esp+10h] [ebp-14h] BYREF
  const std::locale::facet *_Psave; // [esp+14h] [ebp-10h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  std::_Lockit::_Lockit(this: &_Lock, kind: 0);
  v11 = 0;
  _Psave = std::_Facetptr<std::numpunct<char>>::_Psave;
  if ( std::numpunct<char>::id._Id == 0 )
  {
    std::_Lockit::_Lockit(this: &v9, kind: 0);
    LOBYTE(v11) = 1;
    if ( std::numpunct<char>::id._Id == 0 )
      std::numpunct<char>::id._Id = ++std::locale::id::_Id_cnt;
    LOBYTE(v11) = 0;
    std::_Lockit::~_Lockit(this: &v9);
  }
  Id = std::numpunct<char>::id._Id;
  Ptr = _Loc->_Ptr;
  if ( std::numpunct<char>::id._Id >= _Loc->_Ptr->_Facetcount )
  {
    v3 = nullptr;
  }
  else
  {
    v3 = Ptr->_Facetvec[std::numpunct<char>::id._Id];
    if ( v3 != nullptr )
    {
LABEL_11:
      v5 = v3;
LABEL_12:
      if ( v5 != nullptr )
        goto LABEL_17;
      goto LABEL_13;
    }
  }
  if ( !Ptr->_Xparent )
    goto LABEL_11;
  v4 = std::locale::_Getgloballocale();
  if ( Id < v4->_Facetcount )
  {
    v5 = v4->_Facetvec[Id];
    goto LABEL_12;
  }
LABEL_13:
  v5 = (std::locale::facet *)_Psave;
  if ( _Psave == nullptr )
  {
    if ( std::numpunct<char>::_Getcat(_Ppf: (std::numpunct<char> **)&_Psave, _Ploc: _Loc) == -1 )
    {
      std::bad_cast::bad_cast(this: &pExceptionObject, _Message: "bad cast");
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_cast_std__);
    }
    v5 = (std::locale::facet *)_Psave;
    std::_Facetptr<std::numpunct<char>>::_Psave = _Psave;
    std::locale::facet::_Incref(this: (std::locale::facet *)_Psave);
    std::locale::facet::_Facet_Register(_This: v5);
  }
LABEL_17:
  v11 = -1;
  std::_Lockit::~_Lockit(this: &_Lock);
  return (const std::numpunct<char> *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x1011C440
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
// Address: 0x1011C530
// Name: private: void CMapDisp::PostCreate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapDisp::PostCreate(CMapDisp *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  CMapFace *v4; // eax
  CFoW *m_pFoW; // ebx
  CMapAtom *(__thiscall *GetParent)(CMapAtom *); // eax
  _BYTE *v7; // esi
  CMapAtom *v8; // eax
  void *v9; // eax
  void *v10; // eax
  int m_RenderIndexCount; // eax
  unsigned __int16 *v12; // esi
  unsigned int v13; // ebx
  int v14; // ecx
  CoreDispVert_t *m_pVerts; // eax
  int v16; // edx
  float x; // xmm0_4
  int p_m_Vert; // ecx
  float z; // xmm0_4
  float *p_x; // eax
  int m_FoWTriSoupID; // [esp-10h] [ebp-44h]
  Vector v[3]; // [esp+Ch] [ebp-28h] BYREF
  CFoW *pFoW; // [esp+30h] [ebp-4h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  CMapDisp::UpdateBoundingBox(this);
  CMapDisp::ResetNeighbors(this);
  CMapDisp::FindNeighbors(this, m_EditHandle: a2);
  if ( this->GetParent(this) != nullptr )
    CMapDisp::ValidLightmapSize(this, a2: (int)&savedregs, a3: (int)this, a4: a3);
  CMapDisp::UpdateWalkable(this);
  CMapDisp::UpdateBuildable(this);
  v4 = (CMapFace *)this->GetParent(this);
  if ( v4 != nullptr )
    DetailObjects::BuildAnyDetailObjects(pMapFace: v4);
  m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
  GetParent = this->GetParent;
  v7 = nullptr;
  pFoW = m_pFoW;
  v8 = GetParent(this);
  v9 = __RTDynamicCast(
         inptr: v8,
         VfDelta: 0,
         SrcType: &CMapAtom `RTTI Type Descriptor',
         TargetType: &CMapFace `RTTI Type Descriptor',
         isReference: 0);
  if ( v9 != nullptr )
  {
    v10 = (void *)(*(int (__thiscall **)(void *))(*(_DWORD *)v9 + 36))(a1: v9);
    v7 = __RTDynamicCast(
           inptr: v10,
           VfDelta: 0,
           SrcType: &CMapAtom `RTTI Type Descriptor',
           TargetType: &CMapSolid `RTTI Type Descriptor',
           isReference: 0);
  }
  if ( m_pFoW != nullptr && v7 != nullptr && (v7[180] & 2) != 0 )
  {
    if ( this->m_FoWTriSoupID == -1 )
      this->m_FoWTriSoupID = CFoW::AddTriSoup(this: m_pFoW);
    CFoW::ClearTriSoup(this: m_pFoW, nID: this->m_FoWTriSoupID);
    m_RenderIndexCount = this->m_CoreDispInfo.m_RenderIndexCount;
    if ( m_RenderIndexCount > 0 )
    {
      v12 = this->m_CoreDispInfo.m_RenderIndices + 2;
      v13 = (m_RenderIndexCount - 1) / 3u + 1;
      do
      {
        v14 = *(v12 - 2);
        m_pVerts = this->m_CoreDispInfo.m_pVerts;
        v16 = *(v12 - 1);
        x = m_pVerts[v14].m_Vert.x;
        p_m_Vert = (int)&m_pVerts[v14].m_Vert;
        v[0].x = x;
        v[0].y = *(float *)(p_m_Vert + 4);
        v[0].z = *(float *)(p_m_Vert + 8);
        v[1].x = m_pVerts[v16].m_Vert.x;
        v[1].y = m_pVerts[v16].m_Vert.y;
        z = m_pVerts[v16].m_Vert.z;
        p_x = &m_pVerts[*v12].m_Vert.x;
        v[1].z = z;
        v[2].x = *p_x;
        v[2].y = p_x[1];
        m_FoWTriSoupID = this->m_FoWTriSoupID;
        v[2].z = p_x[2];
        CFoW::AddTri(this: pFoW, nID: m_FoWTriSoupID, vPointA: v, vPointB: &v[1], vPointC: &v[2]);
        v12 += 3;
        --v13;
      }
      while ( v13 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C700
// Name: public: virtual void CMapDisp::AddShadowingTriangles(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::AddShadowingTriangles(CMapDisp *this, CUtlVector<Vector,CUtlMemory<Vector,int> > *tri_list)
{
  unsigned __int16 *m_RenderIndices; // ecx
  int m_RenderIndexCount; // eax
  unsigned __int16 *v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  Vector *m_pMemory; // ecx
  int v10; // eax
  Vector *v11; // eax
  bool v12; // zf
  int p_m_Vert; // [esp+0h] [ebp-Ch]
  CoreDispVert_t *pVert; // [esp+4h] [ebp-8h]
  unsigned int v15; // [esp+8h] [ebp-4h]
  int tri_lista; // [esp+14h] [ebp+8h]

  pVert = this->m_CoreDispInfo.m_pVerts;
  m_RenderIndices = this->m_CoreDispInfo.m_RenderIndices;
  m_RenderIndexCount = this->m_CoreDispInfo.m_RenderIndexCount;
  if ( m_RenderIndexCount > 0 )
  {
    v15 = (m_RenderIndexCount - 1) / 3u + 1;
    do
    {
      v6 = m_RenderIndices;
      for ( tri_lista = 3; tri_lista != 0; --tri_lista )
      {
        m_Size = tri_list->m_Size;
        m_nAllocationCount = tri_list->m_Memory.m_nAllocationCount;
        p_m_Vert = (int)&pVert[*v6].m_Vert;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CheckListItem,int>::Grow(this: &tri_list->m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++tri_list->m_Size;
        m_pMemory = tri_list->m_Memory.m_pMemory;
        v10 = tri_list->m_Size - m_Size - 1;
        tri_list->m_pElements = tri_list->m_Memory.m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v10);
        v11 = &tri_list->m_Memory.m_pMemory[m_Size];
        if ( v11 != nullptr )
        {
          *(_QWORD *)&v11->x = *(_QWORD *)p_m_Vert;
          v11->z = *(float *)(p_m_Vert + 8);
        }
        ++v6;
      }
      v12 = v15-- == 1;
      m_RenderIndices = v6;
    }
    while ( !v12 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C7F0
// Name: public: class std::basic_istream<char,struct std::char_traits<char>> __near & std::basic_istream<char,struct std::char_traits<char>>::operator>>(float __near &)
// Source: json
//------------------------------------------------------------------------------
std::istream *__thiscall std::istream::operator>>(std::istream *this, float *_Val)
{
  int v3; // ecx
  const std::locale *v4; // eax
  std::num_get<char,std::istreambuf_iterator<char> > *v5; // ebx
  char *v6; // eax
  std::ios_base *v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v11; // [esp+0h] [ebp-40h] BYREF
  std::istream::sentry _Ok; // [esp+Ch] [ebp-34h]
  std::istreambuf_iterator<char> v13; // [esp+14h] [ebp-2Ch] BYREF
  int v14; // [esp+1Ch] [ebp-24h]
  unsigned int v15; // [esp+20h] [ebp-20h]
  std::locale v16; // [esp+24h] [ebp-1Ch] BYREF
  int _State; // [esp+28h] [ebp-18h] BYREF
  std::istream *v18; // [esp+2Ch] [ebp-14h]
  int *v19; // [esp+30h] [ebp-10h]
  int v20; // [esp+3Ch] [ebp-4h]

  v19 = &v11;
  v18 = this;
  _State = 0;
  _Ok._Myistr = this;
  v3 = *(_DWORD *)&this->gap10[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 40];
  if ( v3 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  v20 = 0;
  _Ok._Ok = std::istream::_Ipfx(this, _Noskip: false);
  v20 = 1;
  if ( _Ok._Ok )
  {
    v4 = std::ios_base::getloc(this: (std::ios_base *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)], result: &v16);
    LOBYTE(v20) = 2;
    v5 = (std::num_get<char,std::istreambuf_iterator<char> > *)std::use_facet<std::num_get<char,std::istreambuf_iterator<char>>>(_Loc: v4);
    LOBYTE(v20) = 1;
    std::locale::~locale(this: &v16);
    LOBYTE(v20) = 3;
    v6 = &this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)];
    v14 = 0;
    LOBYTE(v15) = 1;
    v13._Strbuf = *((std::streambuf **)v6 + 14);
    v13._Got = v13._Strbuf == nullptr;
    std::num_get<char,std::istreambuf_iterator<char>>::get(
      this: v5,
      result: &v13,
      _First: v13,
      _Last: (std::istreambuf_iterator<char>)__PAIR64__(v15, 0),
      _Iosbase: (std::ios_base *)v6,
      &_State,
      _Val);
    v20 = 1;
  }
  v7 = (std::ios_base *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)];
  if ( _State != 0 )
  {
    v8 = _State | v7->_Mystate;
    if ( v7[1].__vftable == nullptr )
      LOBYTE(v8) = v8 | 4;
    std::ios_base::clear(this: v7, _State: v8, _Reraise: false);
  }
  v20 = -1;
  v9 = *(_DWORD *)&this->gap10[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 40];
  if ( v9 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 8))(a1: v9);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011C960
// Name: private: int std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::_Getifld(char __near *,class std::istreambuf_iterator<char,struct std::char_traits<char>> __near &,class std::istreambuf_iterator<char,struct std::char_traits<char>> __near &,int,class std::locale const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __cdecl std::num_get<char,std::istreambuf_iterator<char>>::_Getifld(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        char *_Ac,
        std::istreambuf_iterator<char> *_First,
        std::istreambuf_iterator<char> *_Last,
        __int16 _Basefield,
        const std::locale *_Loc)
{
  std::numpunct<char> *v6; // esi
  std::streambuf *Strbuf; // ecx
  char **IGnext; // eax
  int v9; // eax
  std::istreambuf_iterator<char> *v10; // ecx
  int v11; // eax
  int v12; // ebx
  std::streambuf *v13; // ecx
  char **v14; // eax
  int v15; // eax
  unsigned int v16; // ebx
  int v17; // edi
  std::streambuf *v18; // ecx
  char **v19; // eax
  int v20; // eax
  int v21; // eax
  std::string *Ptr; // eax
  std::string *p_Groups; // eax
  std::string *v24; // eax
  std::streambuf *v25; // ecx
  char **v26; // eax
  int v27; // eax
  std::streambuf *v28; // ecx
  int *IGcount; // eax
  char **v30; // ecx
  char *v31; // eax
  int v32; // eax
  std::string *v33; // eax
  std::string *p_Grouping; // edx
  char *v35; // ebx
  unsigned int Myres; // esi
  char v37; // cl
  std::string *v38; // eax
  std::string *v39; // eax
  char *v40; // eax
  char Val; // [esp-Ch] [ebp-64h]
  std::string _Grouping; // [esp+8h] [ebp-50h] BYREF
  std::string _Groups; // [esp+24h] [ebp-34h] BYREF
  int _Base; // [esp+40h] [ebp-18h]
  char *_Ptr; // [esp+44h] [ebp-14h]
  bool _Nonzero; // [esp+4Ah] [ebp-Eh]
  char _Kseparator; // [esp+4Bh] [ebp-Dh]
  int v49; // [esp+54h] [ebp-4h]
  unsigned __int8 _Seendigit_3; // [esp+73h] [ebp+1Bh]

  v6 = (std::numpunct<char> *)std::use_facet<std::numpunct<char>>(_Loc);
  std::numpunct<char>::grouping(this: v6, result: &_Grouping);
  v49 = 0;
  if ( _Grouping._Mysize != 0 )
    _Kseparator = v6->do_thousands_sep(this: v6);
  else
    _Kseparator = 0;
  _Ptr = _Ac;
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
  {
    if ( !_First->_Got )
    {
      Strbuf = _First->_Strbuf;
      if ( _First->_Strbuf == nullptr
        || (*(IGnext = Strbuf->_IGnext) == nullptr || *Strbuf->_IGcount <= 0
          ? (v9 = Strbuf->underflow(this: Strbuf))
          : (v9 = (unsigned __int8)**IGnext),
            v9 == -1) )
      {
        _First->_Strbuf = nullptr;
      }
      else
      {
        _First->_Val = v9;
      }
      _First->_Got = true;
    }
    v10 = _First;
    if ( _First->_Val == 43 )
    {
      *_Ac = 43;
LABEL_19:
      _Ptr = _Ac + 1;
      std::istreambuf_iterator<char>::operator++(this: v10);
      goto LABEL_20;
    }
    if ( std::istreambuf_iterator<char>::operator*(this: _First) == 45 )
    {
      *_Ac = 45;
      v10 = _First;
      goto LABEL_19;
    }
  }
LABEL_20:
  v11 = _Basefield & 0xE00;
  if ( v11 == 1024 )
  {
    v12 = 8;
    _Base = 8;
  }
  else if ( v11 == 2048 )
  {
    v12 = 16;
    _Base = 16;
  }
  else
  {
    v12 = v11 != 0 ? 0xA : 0;
    _Base = v12;
  }
  _Seendigit_3 = 0;
  _Nonzero = false;
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) != 0 )
    goto LABEL_45;
  if ( !_First->_Got )
  {
    v13 = _First->_Strbuf;
    if ( _First->_Strbuf == nullptr
      || (*(v14 = v13->_IGnext) == nullptr || *v13->_IGcount <= 0
        ? (v15 = v13->underflow(this: v13))
        : (v15 = (unsigned __int8)**v14),
          v15 == -1) )
    {
      _First->_Strbuf = nullptr;
    }
    else
    {
      _First->_Val = v15;
    }
    _First->_Got = true;
  }
  if ( _First->_Val != 48 )
  {
LABEL_45:
    if ( v12 == 0 )
      goto LABEL_48;
  }
  else
  {
    _Seendigit_3 = 1;
    std::istreambuf_iterator<char>::operator++(this: _First);
    if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0
      && (std::istreambuf_iterator<char>::operator*(this: _First) == 120
       || std::istreambuf_iterator<char>::operator*(this: _First) == 88)
      && (v12 == 0 || v12 == 16) )
    {
      _Base = 16;
      _Seendigit_3 = 0;
      std::istreambuf_iterator<char>::operator++(this: _First);
      v16 = 22;
      goto LABEL_49;
    }
    if ( v12 == 0 )
    {
      _Base = 8;
      v16 = 8;
      goto LABEL_49;
    }
  }
  if ( v12 != 10 )
  {
    v16 = v12 != 8 ? 22 : 8;
    goto LABEL_49;
  }
LABEL_48:
  v16 = 10;
LABEL_49:
  v17 = 0;
  _Groups._Myres = 15;
  *(_WORD *)_Groups._Bx._Buf = _Seendigit_3;
  _Groups._Mysize = 1;
  LOBYTE(v49) = 1;
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) != 0 )
    goto LABEL_102;
  do
  {
    if ( !_First->_Got )
    {
      v18 = _First->_Strbuf;
      if ( _First->_Strbuf == nullptr
        || (*(v19 = v18->_IGnext) == nullptr || *v18->_IGcount <= 0
          ? (v20 = v18->underflow(this: v18))
          : (v20 = (unsigned __int8)**v19),
            v20 == -1) )
      {
        _First->_Strbuf = nullptr;
      }
      else
      {
        _First->_Val = v20;
      }
      _First->_Got = true;
    }
    Val = _First->_Val;
    *_Ptr = Val;
    memchr(buf: "0123456789abcdefABCDEF", chr: Val, cnt: v16);
    if ( v21 != 0 )
    {
      if ( (_Nonzero || *_Ptr != 48) && _Ptr < _Ac + 31 )
      {
        ++_Ptr;
        _Nonzero = true;
      }
      Ptr = (std::string *)_Groups._Bx._Ptr;
      _Seendigit_3 = 1;
      if ( _Groups._Myres < 0x10 )
        Ptr = &_Groups;
      if ( Ptr->_Bx._Buf[v17] != 127 )
      {
        p_Groups = (std::string *)_Groups._Bx._Ptr;
        if ( _Groups._Myres < 0x10 )
          p_Groups = &_Groups;
        ++p_Groups->_Bx._Buf[v17];
      }
      goto LABEL_87;
    }
    v24 = (std::string *)_Groups._Bx._Ptr;
    if ( _Groups._Myres < 0x10 )
      v24 = &_Groups;
    if ( v24->_Bx._Buf[v17] == 0 || _Kseparator == 0 )
      break;
    if ( !_First->_Got )
    {
      v25 = _First->_Strbuf;
      if ( _First->_Strbuf == nullptr
        || (*(v26 = v25->_IGnext) == nullptr || *v25->_IGcount <= 0
          ? (v27 = v25->underflow(this: v25))
          : (v27 = (unsigned __int8)**v26),
            v27 == -1) )
      {
        _First->_Strbuf = nullptr;
      }
      else
      {
        _First->_Val = v27;
      }
      _First->_Got = true;
    }
    if ( _First->_Val != _Kseparator )
      break;
    std::string::append(this: &_Groups, _Count: 1u, _Ch: 0);
    ++v17;
LABEL_87:
    v28 = _First->_Strbuf;
    if ( _First->_Strbuf == nullptr
      || (*v28->_IGnext == nullptr || *(IGcount = v28->_IGcount) <= 0
        ? (v32 = v28->uflow(this: v28))
        : (--*IGcount, v30 = v28->_IGnext, v31 = *v30, ++*v30, v32 = (unsigned __int8)*v31),
          v32 == -1) )
    {
      _First->_Strbuf = nullptr;
      _First->_Got = true;
    }
    else
    {
      _First->_Got = false;
    }
  }
  while ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 );
  if ( v17 != 0 )
  {
    v33 = (std::string *)_Groups._Bx._Ptr;
    if ( _Groups._Myres < 0x10 )
      v33 = &_Groups;
    if ( v33->_Bx._Buf[v17] <= 0 )
      _Seendigit_3 = 0;
    else
      ++v17;
  }
LABEL_102:
  p_Grouping = (std::string *)_Grouping._Bx._Ptr;
  if ( _Grouping._Myres < 0x10 )
    p_Grouping = &_Grouping;
  v35 = _Groups._Bx._Ptr;
  Myres = _Groups._Myres;
  if ( _Seendigit_3 != 0 )
  {
    while ( v17 != 0 )
    {
      v37 = p_Grouping->_Bx._Buf[0];
      if ( p_Grouping->_Bx._Buf[0] == 127 )
        break;
      if ( --v17 != 0 )
      {
        v38 = (std::string *)_Groups._Bx._Ptr;
        if ( _Groups._Myres < 0x10 )
          v38 = &_Groups;
        if ( v37 != v38->_Bx._Buf[v17] )
          goto LABEL_119;
      }
      if ( v17 == 0 )
      {
        v39 = (std::string *)_Groups._Bx._Ptr;
        if ( _Groups._Myres < 0x10 )
          v39 = &_Groups;
        if ( v37 < v39->_Bx._Buf[0] )
          goto LABEL_119;
      }
      if ( p_Grouping->_Bx._Buf[1] > 0 )
        p_Grouping = (std::string *)((char *)p_Grouping + 1);
    }
    v40 = _Ptr;
    if ( !_Nonzero )
    {
      *_Ptr = 48;
      ++v40;
    }
  }
  else
  {
LABEL_119:
    v40 = _Ac;
  }
  *v40 = 0;
  LOBYTE(v49) = 0;
  if ( Myres >= 0x10 )
    operator delete(p: v35);
  _Groups._Myres = 15;
  _Groups._Mysize = 0;
  _Groups._Bx._Buf[0] = 0;
  v49 = -1;
  if ( _Grouping._Myres >= 0x10 )
    operator delete(p: _Grouping._Bx._Ptr);
  return _Base;
}

//------------------------------------------------------------------------------
// Address: 0x1011CDE0
// Name: private: int std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::_Getffldx(char __near *,class std::istreambuf_iterator<char,struct std::char_traits<char>> __near &,class std::istreambuf_iterator<char,struct std::char_traits<char>> __near &,class std::ios_base __near &,int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __cdecl std::num_get<char,std::istreambuf_iterator<char>>::_Getffldx(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        char *_Ac,
        std::istreambuf_iterator<char> *_First,
        std::istreambuf_iterator<char> *_Last,
        std::ios_base *_Iosbase,
        int *_Phexexp)
{
  const std::locale *v6; // eax
  std::numpunct<char> *v7; // ebx
  std::locale::_Locimp *Ptr; // edi
  unsigned int Refs; // eax
  int v10; // esi
  void (__thiscall ***v11)(_DWORD, int); // esi
  std::streambuf *Strbuf; // ecx
  char **IGnext; // eax
  int v14; // eax
  std::istreambuf_iterator<char> *v15; // ecx
  char *v16; // eax
  std::streambuf *v17; // ecx
  char **v18; // eax
  int v19; // eax
  std::istreambuf_iterator<char> *v20; // eax
  std::string *p_Grouping; // eax
  std::string *v22; // eax
  unsigned int v23; // ebx
  std::streambuf *v24; // ecx
  char **v25; // eax
  int v26; // eax
  char Val; // al
  int v28; // edi
  int v29; // ebx
  char *v30; // eax
  std::string *v31; // eax
  std::string *v32; // eax
  char *v33; // edi
  std::string *p_Groups; // eax
  char v35; // al
  std::streambuf *v36; // ecx
  int *IGcount; // eax
  char **v38; // ecx
  char *v39; // eax
  int v40; // eax
  char v41; // al
  std::string *v42; // eax
  std::string *v43; // edx
  char v44; // cl
  std::string *v45; // eax
  std::string *v46; // eax
  char *v47; // eax
  std::streambuf *v48; // ecx
  char **v49; // eax
  int v50; // eax
  std::streambuf *v51; // ecx
  char **v52; // eax
  int v53; // eax
  char v54; // al
  int v55; // edi
  int v56; // ebx
  std::streambuf *v57; // ecx
  char **v58; // eax
  int v59; // eax
  char *v60; // eax
  std::streambuf *v61; // ecx
  int *v62; // eax
  char **v63; // ecx
  char *v64; // eax
  int v65; // eax
  char v66; // bl
  char v67; // cl
  char *v68; // eax
  std::streambuf *v69; // ecx
  int *v70; // eax
  char **v71; // ecx
  char *v72; // eax
  int v73; // eax
  int v74; // edi
  char v75; // al
  int v76; // ebx
  std::streambuf *v77; // ecx
  char **v78; // eax
  int v79; // eax
  std::streambuf *v80; // ecx
  int *v81; // edx
  char **v82; // ecx
  char *v83; // eax
  int v84; // eax
  bool v85; // sf
  char *v86; // ebx
  std::streambuf *v87; // ecx
  char **v88; // eax
  int v89; // eax
  char v90; // al
  int v91; // eax
  std::streambuf *v92; // ecx
  int *v93; // eax
  char **v94; // ecx
  char *v95; // eax
  int v96; // eax
  std::streambuf *v97; // ecx
  char **v98; // eax
  int v99; // eax
  std::streambuf *v100; // ecx
  char **v101; // eax
  int v102; // eax
  std::streambuf *v103; // ecx
  int *v104; // edx
  char **v105; // ecx
  char *v106; // eax
  int v107; // eax
  int v108; // edi
  std::streambuf *v109; // ecx
  char **v110; // eax
  int v111; // eax
  std::streambuf *v112; // ecx
  char **v113; // eax
  int v114; // eax
  std::streambuf *v115; // ecx
  int *v116; // edx
  char **v117; // ecx
  char *v118; // eax
  int v119; // eax
  std::streambuf *v120; // ecx
  char **v121; // eax
  int v122; // eax
  std::streambuf *v123; // ecx
  int *v124; // edx
  char **v125; // ecx
  char *v126; // eax
  int v127; // eax
  std::streambuf *v128; // ecx
  char **v129; // eax
  int v130; // eax
  std::streambuf *v131; // ecx
  char **v132; // eax
  int v133; // eax
  std::streambuf *v134; // ecx
  char **v135; // eax
  int v136; // eax
  std::streambuf *v137; // ecx
  int *v138; // edx
  char **v139; // ecx
  char *v140; // eax
  int v141; // eax
  int v142; // edx
  std::string _Grouping; // [esp+Ch] [ebp-60h] BYREF
  std::string _Groups; // [esp+28h] [ebp-44h] BYREF
  const std::numpunct<char> *_Punct_fac; // [esp+44h] [ebp-28h]
  std::locale v147; // [esp+48h] [ebp-24h] BYREF
  unsigned int _Group; // [esp+4Ch] [ebp-20h] BYREF
  int _Significant; // [esp+50h] [ebp-1Ch]
  int _Phex; // [esp+54h] [ebp-18h]
  char *_Ptr; // [esp+58h] [ebp-14h]
  char _Kseparator; // [esp+5Dh] [ebp-Fh]
  bool _Bad; // [esp+5Eh] [ebp-Eh]
  bool _Seendigit; // [esp+5Fh] [ebp-Dh]
  int v155; // [esp+68h] [ebp-4h]

  v6 = std::ios_base::getloc(this: _Iosbase, result: &v147);
  v155 = 0;
  v7 = (std::numpunct<char> *)std::use_facet<std::numpunct<char>>(_Loc: v6);
  _Punct_fac = v7;
  v155 = -1;
  Ptr = v147._Ptr;
  if ( v147._Ptr != nullptr )
  {
    std::_Lockit::_Lockit(this: (std::_Lockit *)&_Group, kind: 0);
    v155 = 1;
    Refs = Ptr->_Refs;
    if ( Refs != 0 && Refs != -1 )
      Ptr->_Refs = Refs - 1;
    v10 = -(Ptr->_Refs == 0);
    v155 = -1;
    std::_Lockit::~_Lockit(this: (std::_Lockit *)&_Group);
    v11 = (void (__thiscall ***)(_DWORD, int))((unsigned int)Ptr & v10);
    if ( v11 != nullptr )
      (**v11)(a1: v11, a2: 1);
  }
  std::numpunct<char>::grouping(this: v7, result: &_Grouping);
  v155 = 2;
  _Ptr = _Ac;
  _Bad = false;
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
  {
    if ( !_First->_Got )
    {
      Strbuf = _First->_Strbuf;
      if ( _First->_Strbuf == nullptr
        || (*(IGnext = Strbuf->_IGnext) == nullptr || *Strbuf->_IGcount <= 0
          ? (v14 = Strbuf->underflow(this: Strbuf))
          : (v14 = (unsigned __int8)**IGnext),
            v14 == -1) )
      {
        _First->_Strbuf = nullptr;
      }
      else
      {
        _First->_Val = v14;
      }
      _First->_Got = true;
    }
    v15 = _First;
    if ( _First->_Val == 43 )
    {
      *_Ac = 43;
    }
    else
    {
      if ( std::istreambuf_iterator<char>::operator*(this: _First) != 45 )
        goto LABEL_23;
      *_Ac = 45;
      v15 = _First;
    }
    _Ptr = _Ac + 1;
    std::istreambuf_iterator<char>::operator++(this: v15);
  }
LABEL_23:
  v16 = _Ptr;
  *(_WORD *)_Ptr = 30768;
  _Ptr = v16 + 2;
  _Seendigit = false;
  _Significant = 0;
  _Phex = 0;
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
  {
    if ( !_First->_Got )
    {
      v17 = _First->_Strbuf;
      if ( _First->_Strbuf == nullptr
        || (*(v18 = v17->_IGnext) == nullptr || *v17->_IGcount <= 0
          ? (v19 = v17->underflow(this: v17))
          : (v19 = (unsigned __int8)**v18),
            v19 == -1) )
      {
        _First->_Strbuf = nullptr;
      }
      else
      {
        _First->_Val = v19;
      }
      _First->_Got = true;
    }
    if ( _First->_Val == 48 )
    {
      v20 = std::istreambuf_iterator<char>::operator++(this: _First);
      if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: v20, _Right: _Last) == 0
        && (std::istreambuf_iterator<char>::operator*(this: _First) == 120
         || std::istreambuf_iterator<char>::operator*(this: _First) == 88) )
      {
        std::istreambuf_iterator<char>::operator++(this: _First);
      }
      else
      {
        _Seendigit = true;
      }
    }
  }
  p_Grouping = (std::string *)_Grouping._Bx._Ptr;
  if ( _Grouping._Myres < 0x10 )
    p_Grouping = &_Grouping;
  if ( p_Grouping->_Bx._Buf[0] != 127 )
  {
    v22 = (std::string *)_Grouping._Bx._Ptr;
    if ( _Grouping._Myres < 0x10 )
      v22 = &_Grouping;
    if ( v22->_Bx._Buf[0] > 0 )
    {
      if ( _Grouping._Mysize != 0 )
        _Kseparator = v7->do_thousands_sep(this: v7);
      else
        _Kseparator = 0;
      v23 = 0;
      _Groups._Myres = 15;
      _Groups._Mysize = 1;
      *(_WORD *)_Groups._Bx._Buf = 0;
      LOBYTE(v155) = 3;
      _Group = 0;
      if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) != 0 )
      {
        v33 = _Groups._Bx._Ptr;
        goto LABEL_104;
      }
      while ( 1 )
      {
        if ( !_First->_Got )
        {
          v24 = _First->_Strbuf;
          if ( _First->_Strbuf == nullptr
            || (*(v25 = v24->_IGnext) == nullptr || *v24->_IGcount <= 0
              ? (v26 = v24->underflow(this: v24))
              : (v26 = (unsigned __int8)**v25),
                v26 == -1) )
          {
            _First->_Strbuf = nullptr;
          }
          else
          {
            _First->_Val = v26;
          }
          _First->_Got = true;
        }
        Val = _First->_Val;
        if ( Val < 48 || Val > 57 )
        {
          if ( Val < 97 || Val > 102 )
          {
            if ( Val < 65 || Val > 70 )
            {
LABEL_81:
              v33 = _Groups._Bx._Ptr;
              p_Groups = (std::string *)_Groups._Bx._Ptr;
              if ( _Groups._Myres < 0x10 )
                p_Groups = &_Groups;
              if ( p_Groups->_Bx._Buf[v23] == 0 )
                goto LABEL_97;
              if ( _Kseparator == 0 )
                goto LABEL_97;
              v35 = std::istreambuf_iterator<char>::operator*(this: _First);
              if ( v35 != _Kseparator )
                goto LABEL_97;
              std::string::append(this: &_Groups, _Count: 1u, _Ch: 0);
              _Group = v23 + 1;
              goto LABEL_87;
            }
            v28 = Val - 55;
          }
          else
          {
            v28 = Val - 87;
          }
        }
        else
        {
          v28 = Val - 48;
        }
        if ( v28 < 0 )
          goto LABEL_81;
        v29 = _Significant;
        _Seendigit = true;
        if ( _Significant < 36 )
        {
          if ( std::istreambuf_iterator<char>::operator*(this: _First) != 48 || v29 != 0 )
          {
            v30 = _Ptr;
            *_Ptr = a0123456789abcd_3[v28];
            _Ptr = v30 + 1;
            _Significant = v29 + 1;
          }
        }
        else
        {
          ++_Phex;
        }
        v31 = (std::string *)_Groups._Bx._Ptr;
        if ( _Groups._Myres < 0x10 )
          v31 = &_Groups;
        if ( v31->_Bx._Buf[_Group] != 127 )
        {
          v32 = (std::string *)_Groups._Bx._Ptr;
          if ( _Groups._Myres < 0x10 )
            v32 = &_Groups;
          ++v32->_Bx._Buf[_Group];
        }
LABEL_87:
        v36 = _First->_Strbuf;
        if ( _First->_Strbuf == nullptr
          || (*v36->_IGnext == nullptr || *(IGcount = v36->_IGcount) <= 0
            ? (v40 = v36->uflow(this: v36))
            : (--*IGcount, v38 = v36->_IGnext, v39 = *v38, ++*v38, v40 = (unsigned __int8)*v39),
              v40 == -1) )
        {
          _First->_Strbuf = nullptr;
          _First->_Got = true;
        }
        else
        {
          _First->_Got = false;
        }
        v41 = std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last);
        v23 = _Group;
        if ( v41 != 0 )
        {
          v33 = _Groups._Bx._Ptr;
LABEL_97:
          if ( v23 != 0 )
          {
            v42 = (std::string *)v33;
            if ( _Groups._Myres < 0x10 )
              v42 = &_Groups;
            if ( v42->_Bx._Buf[v23] <= 0 )
              _Bad = true;
            else
              ++v23;
          }
LABEL_104:
          v43 = (std::string *)_Grouping._Bx._Ptr;
          if ( _Grouping._Myres < 0x10 )
            v43 = &_Grouping;
          if ( !_Bad )
          {
            while ( v23 != 0 )
            {
              v44 = v43->_Bx._Buf[0];
              if ( v43->_Bx._Buf[0] == 127 )
                break;
              if ( --v23 != 0 )
              {
                v45 = (std::string *)v33;
                if ( _Groups._Myres < 0x10 )
                  v45 = &_Groups;
                if ( v44 != v45->_Bx._Buf[v23] )
                  goto LABEL_119;
              }
              if ( v23 == 0 )
              {
                v46 = (std::string *)v33;
                if ( _Groups._Myres < 0x10 )
                  v46 = &_Groups;
                if ( v44 < v46->_Bx._Buf[0] )
                {
LABEL_119:
                  _Bad = true;
                  break;
                }
              }
              if ( v43->_Bx._Buf[1] > 0 )
                v43 = (std::string *)((char *)v43 + 1);
            }
          }
          LOBYTE(v155) = 2;
          if ( _Groups._Myres >= 0x10 )
            operator delete(p: v33);
          _Groups._Myres = 15;
          _Groups._Mysize = 0;
          _Groups._Bx._Buf[0] = 0;
LABEL_123:
          if ( _Seendigit )
            goto LABEL_124;
          goto LABEL_126;
        }
      }
    }
  }
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) != 0 )
    goto LABEL_123;
  do
  {
    if ( !_First->_Got )
    {
      v51 = _First->_Strbuf;
      if ( _First->_Strbuf == nullptr
        || (*(v52 = v51->_IGnext) == nullptr || *v51->_IGcount <= 0
          ? (v53 = v51->underflow(this: v51))
          : (v53 = (unsigned __int8)**v52),
            v53 == -1) )
      {
        _First->_Strbuf = nullptr;
      }
      else
      {
        _First->_Val = v53;
      }
      _First->_Got = true;
    }
    v54 = _First->_Val;
    if ( v54 < 48 || v54 > 57 )
    {
      if ( v54 < 97 || v54 > 102 )
      {
        if ( v54 < 65 || v54 > 70 )
          goto LABEL_123;
        v55 = v54 - 55;
      }
      else
      {
        v55 = v54 - 87;
      }
    }
    else
    {
      v55 = v54 - 48;
    }
    if ( v55 < 0 )
      goto LABEL_123;
    v56 = _Significant;
    if ( _Significant < 36 )
    {
      if ( !_First->_Got )
      {
        v57 = _First->_Strbuf;
        if ( _First->_Strbuf == nullptr
          || (*(v58 = v57->_IGnext) == nullptr || *v57->_IGcount <= 0
            ? (v59 = v57->underflow(this: v57))
            : (v59 = (unsigned __int8)**v58),
              v59 == -1) )
        {
          _First->_Strbuf = nullptr;
        }
        else
        {
          _First->_Val = v59;
        }
        _First->_Got = true;
      }
      if ( _First->_Val != 48 || v56 != 0 )
      {
        v60 = _Ptr;
        *_Ptr = a0123456789abcd_3[v55];
        _Ptr = v60 + 1;
        _Significant = v56 + 1;
      }
    }
    else
    {
      ++_Phex;
    }
    v61 = _First->_Strbuf;
    _Seendigit = true;
    if ( v61 == nullptr
      || (*v61->_IGnext == nullptr || *(v62 = v61->_IGcount) <= 0
        ? (v65 = v61->uflow(this: v61))
        : (--*v62, v63 = v61->_IGnext, v64 = *v63, ++*v63, v65 = (unsigned __int8)*v64),
          v65 == -1) )
    {
      _First->_Strbuf = nullptr;
      _First->_Got = true;
    }
    else
    {
      _First->_Got = false;
    }
  }
  while ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 );
LABEL_124:
  if ( _Significant == 0 )
  {
    v47 = _Ptr;
    *_Ptr = 48;
    _Ptr = v47 + 1;
  }
LABEL_126:
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
  {
    if ( !_First->_Got )
    {
      v48 = _First->_Strbuf;
      if ( _First->_Strbuf == nullptr
        || (*(v49 = v48->_IGnext) == nullptr || *v48->_IGcount <= 0
          ? (v50 = v48->underflow(this: v48))
          : (v50 = (unsigned __int8)**v49),
            v50 == -1) )
      {
        _First->_Strbuf = nullptr;
      }
      else
      {
        _First->_Val = v50;
      }
      _First->_Got = true;
    }
    v66 = _First->_Val;
    if ( v66 == (unsigned __int8)_Punct_fac->do_decimal_point(this: (std::numpunct<char> *)_Punct_fac) )
    {
      v67 = *localeconv()->decimal_point;
      v68 = _Ptr;
      *_Ptr = v67;
      v69 = _First->_Strbuf;
      _Ptr = v68 + 1;
      if ( v69 == nullptr
        || (*v69->_IGnext == nullptr || *(v70 = v69->_IGcount) <= 0
          ? (v73 = v69->uflow(this: v69))
          : (--*v70, v71 = v69->_IGnext, v72 = *v71, ++*v71, v73 = (unsigned __int8)*v72),
            v73 == -1) )
      {
        _First->_Strbuf = nullptr;
        _First->_Got = true;
      }
      else
      {
        _First->_Got = false;
      }
    }
  }
  v74 = _Significant;
  if ( _Significant != 0 )
  {
    v86 = _Ptr;
  }
  else
  {
    v75 = std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last);
    v76 = _Phex;
    if ( v75 == 0 )
    {
      do
      {
        if ( !_First->_Got )
        {
          v77 = _First->_Strbuf;
          if ( _First->_Strbuf == nullptr
            || (*(v78 = v77->_IGnext) == nullptr || *v77->_IGcount <= 0
              ? (v79 = v77->underflow(this: v77))
              : (v79 = (unsigned __int8)**v78),
                v79 == -1) )
          {
            _First->_Strbuf = nullptr;
          }
          else
          {
            _First->_Val = v79;
          }
          _First->_Got = true;
        }
        if ( _First->_Val != 48 )
          break;
        v80 = _First->_Strbuf;
        --v76;
        _Seendigit = true;
        if ( v80 == nullptr
          || (*v80->_IGnext == nullptr || *(v81 = v80->_IGcount) <= 0
            ? (v84 = v80->uflow(this: v80))
            : (--*v81, v82 = v80->_IGnext, v83 = *v82, ++*v82, v84 = (unsigned __int8)*v83),
              v84 == -1) )
        {
          _First->_Strbuf = nullptr;
          _First->_Got = true;
        }
        else
        {
          _First->_Got = false;
        }
      }
      while ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 );
      _Phex = v76;
    }
    v85 = v76 < 0;
    v86 = _Ptr;
    if ( v85 )
    {
      *_Ptr = 48;
      ++v86;
      ++_Phex;
    }
  }
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) != 0 )
  {
LABEL_251:
    if ( !_Seendigit )
      goto LABEL_384;
  }
  else
  {
    do
    {
      if ( !_First->_Got )
      {
        v87 = _First->_Strbuf;
        if ( _First->_Strbuf == nullptr
          || (*(v88 = v87->_IGnext) == nullptr || *v87->_IGcount <= 0
            ? (v89 = v87->underflow(this: v87))
            : (v89 = (unsigned __int8)**v88),
              v89 == -1) )
        {
          _First->_Strbuf = nullptr;
        }
        else
        {
          _First->_Val = v89;
        }
        _First->_Got = true;
      }
      v90 = _First->_Val;
      if ( v90 < 48 || v90 > 57 )
      {
        if ( v90 < 97 || v90 > 102 )
        {
          if ( v90 < 65 || v90 > 70 )
            goto LABEL_251;
          v91 = v90 - 55;
        }
        else
        {
          v91 = v90 - 87;
        }
      }
      else
      {
        v91 = v90 - 48;
      }
      if ( v91 < 0 )
        goto LABEL_251;
      if ( v74 < 36 )
      {
        *v86++ = a0123456789abcd_3[v91];
        ++v74;
      }
      v92 = _First->_Strbuf;
      _Seendigit = true;
      if ( v92 == nullptr
        || (*v92->_IGnext == nullptr || *(v93 = v92->_IGcount) <= 0
          ? (v96 = v92->uflow(this: v92))
          : (--*v93, v94 = v92->_IGnext, v95 = *v94, ++*v94, v96 = (unsigned __int8)*v95),
            v96 == -1) )
      {
        _First->_Strbuf = nullptr;
        _First->_Got = true;
      }
      else
      {
        _First->_Got = false;
      }
    }
    while ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 );
  }
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
  {
    if ( !_First->_Got )
    {
      v97 = _First->_Strbuf;
      if ( _First->_Strbuf == nullptr
        || (*(v98 = v97->_IGnext) == nullptr || *v97->_IGcount <= 0
          ? (v99 = v97->underflow(this: v97))
          : (v99 = (unsigned __int8)**v98),
            v99 == -1) )
      {
        _First->_Strbuf = nullptr;
      }
      else
      {
        _First->_Val = v99;
      }
      _First->_Got = true;
    }
    if ( _First->_Val == 112 )
      goto LABEL_275;
    if ( !_First->_Got )
    {
      v100 = _First->_Strbuf;
      if ( _First->_Strbuf == nullptr
        || (*(v101 = v100->_IGnext) == nullptr || *v100->_IGcount <= 0
          ? (v102 = v100->underflow(this: v100))
          : (v102 = (unsigned __int8)**v101),
            v102 == -1) )
      {
        _First->_Strbuf = nullptr;
      }
      else
      {
        _First->_Val = v102;
      }
      _First->_Got = true;
    }
    if ( _First->_Val == 80 )
    {
LABEL_275:
      *v86 = 112;
      v103 = _First->_Strbuf;
      ++v86;
      if ( _First->_Strbuf == nullptr
        || (*v103->_IGnext == nullptr || *(v104 = v103->_IGcount) <= 0
          ? (v107 = v103->uflow(this: v103))
          : (--*v104, v105 = v103->_IGnext, v106 = *v105, ++*v105, v107 = (unsigned __int8)*v106),
            v107 == -1) )
      {
        _First->_Strbuf = nullptr;
        _First->_Got = true;
      }
      else
      {
        _First->_Got = false;
      }
      _Seendigit = false;
      v108 = 0;
      if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
      {
        if ( !_First->_Got )
        {
          v109 = _First->_Strbuf;
          if ( _First->_Strbuf == nullptr
            || (*(v110 = v109->_IGnext) == nullptr || *v109->_IGcount <= 0
              ? (v111 = v109->underflow(this: v109))
              : (v111 = (unsigned __int8)**v110),
                v111 == -1) )
          {
            _First->_Strbuf = nullptr;
          }
          else
          {
            _First->_Val = v111;
          }
          _First->_Got = true;
        }
        if ( _First->_Val == 43 )
        {
          *v86 = 43;
        }
        else
        {
          if ( !_First->_Got )
          {
            v112 = _First->_Strbuf;
            if ( _First->_Strbuf == nullptr
              || (*(v113 = v112->_IGnext) == nullptr || *v112->_IGcount <= 0
                ? (v114 = v112->underflow(this: v112))
                : (v114 = (unsigned __int8)**v113),
                  v114 == -1) )
            {
              _First->_Strbuf = nullptr;
            }
            else
            {
              _First->_Val = v114;
            }
            _First->_Got = true;
          }
          if ( _First->_Val != 45 )
            goto LABEL_316;
          *v86 = 45;
        }
        v115 = _First->_Strbuf;
        ++v86;
        if ( _First->_Strbuf == nullptr
          || (*v115->_IGnext == nullptr || *(v116 = v115->_IGcount) <= 0
            ? (v119 = v115->uflow(this: v115))
            : (--*v116, v117 = v115->_IGnext, v118 = *v117, ++*v117, v119 = (unsigned __int8)*v118),
              v119 == -1) )
        {
          _First->_Got = true;
          _First->_Strbuf = nullptr;
        }
        else
        {
          _First->_Got = false;
        }
      }
LABEL_316:
      if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
      {
        while ( 1 )
        {
          if ( !_First->_Got )
          {
            v120 = _First->_Strbuf;
            if ( _First->_Strbuf == nullptr
              || (*(v121 = v120->_IGnext) == nullptr || *v120->_IGcount <= 0
                ? (v122 = v120->underflow(this: v120))
                : (v122 = (unsigned __int8)**v121),
                  v122 == -1) )
            {
              _First->_Strbuf = nullptr;
            }
            else
            {
              _First->_Val = v122;
            }
            _First->_Got = true;
          }
          if ( _First->_Val != 48 )
            break;
          v123 = _First->_Strbuf;
          _Seendigit = true;
          if ( v123 == nullptr
            || (*v123->_IGnext == nullptr || *(v124 = v123->_IGcount) <= 0
              ? (v127 = v123->uflow(this: v123))
              : (--*v124, v125 = v123->_IGnext, v126 = *v125, ++*v125, v127 = (unsigned __int8)*v126),
                v127 == -1) )
          {
            _First->_Strbuf = nullptr;
            _First->_Got = true;
          }
          else
          {
            _First->_Got = false;
          }
          if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) != 0 )
            goto LABEL_339;
        }
        if ( !_Seendigit )
          goto LABEL_340;
LABEL_339:
        *v86++ = 48;
      }
LABEL_340:
      while ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
      {
        if ( !_First->_Got )
        {
          v128 = _First->_Strbuf;
          if ( _First->_Strbuf == nullptr
            || (*(v129 = v128->_IGnext) == nullptr || *v128->_IGcount <= 0
              ? (v130 = v128->underflow(this: v128))
              : (v130 = (unsigned __int8)**v129),
                v130 == -1) )
          {
            _First->_Strbuf = nullptr;
          }
          else
          {
            _First->_Val = v130;
          }
          _First->_Got = true;
        }
        if ( _First->_Val < 48 )
          break;
        if ( !_First->_Got )
        {
          v131 = _First->_Strbuf;
          if ( _First->_Strbuf == nullptr
            || (*(v132 = v131->_IGnext) == nullptr || *v131->_IGcount <= 0
              ? (v133 = v131->underflow(this: v131))
              : (v133 = (unsigned __int8)**v132),
                v133 == -1) )
          {
            _First->_Strbuf = nullptr;
          }
          else
          {
            _First->_Val = v133;
          }
          _First->_Got = true;
        }
        if ( _First->_Val > 57 )
          break;
        if ( v108 < 8 )
        {
          if ( !_First->_Got )
          {
            v134 = _First->_Strbuf;
            if ( _First->_Strbuf == nullptr
              || (*(v135 = v134->_IGnext) == nullptr || *v134->_IGcount <= 0
                ? (v136 = v134->underflow(this: v134))
                : (v136 = (unsigned __int8)**v135),
                  v136 == -1) )
            {
              _First->_Strbuf = nullptr;
            }
            else
            {
              _First->_Val = v136;
            }
            _First->_Got = true;
          }
          *v86++ = _First->_Val;
          ++v108;
        }
        v137 = _First->_Strbuf;
        _Seendigit = true;
        if ( v137 == nullptr
          || (*v137->_IGnext == nullptr || *(v138 = v137->_IGcount) <= 0
            ? (v141 = v137->uflow(this: v137))
            : (--*v138, v139 = v137->_IGnext, v140 = *v139, ++*v139, v141 = (unsigned __int8)*v140),
              v141 == -1) )
        {
          _First->_Strbuf = nullptr;
          _First->_Got = true;
        }
        else
        {
          _First->_Got = false;
        }
      }
    }
  }
LABEL_384:
  if ( _Bad || !_Seendigit )
    v86 = _Ac;
  v142 = _Phex;
  *v86 = 0;
  *_Phexexp = v142;
  v155 = -1;
  if ( _Grouping._Myres >= 0x10 )
    operator delete(p: _Grouping._Bx._Ptr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011DA50
// Name: int std::_Getloctxt<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>(class std::istreambuf_iterator<char,struct std::char_traits<char>> __near &,class std::istreambuf_iterator<char,struct std::char_traits<char>> __near &,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl std::_Getloctxt<char,std::istreambuf_iterator<char>>(
        std::istreambuf_iterator<char> *_First,
        std::istreambuf_iterator<char> *_Last,
        unsigned int _Numfields,
        char *_Ptr)
{
  char v5; // al
  const char *v6; // ecx
  int v7; // esi
  int v8; // edi
  char i; // al
  std::string *Ptr; // eax
  std::string *p_Str; // eax
  char v12; // cl
  char v13; // al
  std::istreambuf_iterator<char> *v14; // eax
  std::streambuf *v15; // ecx
  char **v16; // eax
  int v17; // eax
  std::string *v18; // eax
  std::streambuf *Strbuf; // ecx
  int *IGcount; // edx
  char **IGnext; // ecx
  char *v22; // eax
  int v23; // eax
  std::string _Str; // [esp+Ch] [ebp-30h] BYREF
  int _Ans; // [esp+28h] [ebp-14h]
  unsigned int _Column; // [esp+2Ch] [ebp-10h]
  int v28; // [esp+38h] [ebp-4h]
  char _Prefix_3; // [esp+53h] [ebp+17h]

  if ( *_Ptr != 0 )
  {
    v5 = *_Ptr;
    v6 = _Ptr;
    do
    {
      if ( v5 == *_Ptr )
        ++_Numfields;
      v5 = *++v6;
    }
    while ( v5 != 0 );
  }
  _Str._Myres = 15;
  _Str._Mysize = 0;
  _Str._Bx._Buf[0] = 0;
  std::string::assign(this: &_Str, _Count: _Numfields, _Ch: 0);
  v28 = 0;
  _Ans = -2;
  _Column = 1;
LABEL_7:
  v7 = 0;
  v8 = 0;
  _Prefix_3 = 0;
  if ( _Numfields != 0 )
  {
    while ( 1 )
    {
      for ( i = _Ptr[v7]; i != 0; ++v7 )
      {
        if ( i == *_Ptr )
          break;
        i = _Ptr[v7 + 1];
      }
      Ptr = (std::string *)_Str._Bx._Ptr;
      if ( _Str._Myres < 0x10 )
        Ptr = &_Str;
      if ( Ptr->_Bx._Buf[v8] != 0 )
      {
        p_Str = (std::string *)_Str._Bx._Ptr;
        if ( _Str._Myres < 0x10 )
          p_Str = &_Str;
        v7 += p_Str->_Bx._Buf[v8];
        goto LABEL_43;
      }
      v12 = _Column;
      v7 += _Column;
      v13 = _Ptr[v7];
      if ( v13 == *_Ptr || v13 == 0 )
      {
        if ( _Column >= 0x7F )
          v12 = 127;
        v18 = (std::string *)_Str._Bx._Ptr;
        if ( _Str._Myres < 0x10 )
          v18 = &_Str;
        _Ans = v8;
        goto LABEL_42;
      }
      if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) != 0 )
        goto LABEL_33;
      v14 = _First;
      if ( !_First->_Got )
        break;
LABEL_31:
      if ( _Ptr[v7] != v14->_Val )
      {
LABEL_33:
        v12 = _Column;
        if ( _Column >= 0x7F )
          v12 = 127;
        v18 = (std::string *)_Str._Bx._Ptr;
        if ( _Str._Myres < 0x10 )
          v18 = &_Str;
LABEL_42:
        v18->_Bx._Buf[v8] = v12;
        goto LABEL_43;
      }
      _Prefix_3 = 1;
LABEL_43:
      if ( ++v8 >= _Numfields )
      {
        if ( _Prefix_3 != 0 && (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
        {
          Strbuf = _First->_Strbuf;
          ++_Column;
          if ( Strbuf == nullptr
            || (*Strbuf->_IGnext == nullptr || *(IGcount = Strbuf->_IGcount) <= 0
              ? (v23 = Strbuf->uflow(this: Strbuf))
              : (--*IGcount, IGnext = Strbuf->_IGnext, v22 = *IGnext, ++*IGnext, v23 = (unsigned __int8)*v22),
                v23 == -1) )
          {
            _First->_Strbuf = nullptr;
            _First->_Got = true;
            _Ans = -1;
          }
          else
          {
            _First->_Got = false;
            _Ans = -1;
          }
          goto LABEL_7;
        }
        goto LABEL_54;
      }
    }
    v15 = _First->_Strbuf;
    if ( _First->_Strbuf != nullptr )
    {
      v16 = v15->_IGnext;
      if ( *v16 != nullptr && *v15->_IGcount > 0 )
        v17 = (unsigned __int8)**v16;
      else
        v17 = v15->underflow(this: v15);
      if ( v17 != -1 )
      {
        _First->_Val = v17;
        v14 = _First;
LABEL_30:
        v14->_Got = true;
        goto LABEL_31;
      }
      v14 = _First;
    }
    v14->_Strbuf = nullptr;
    goto LABEL_30;
  }
LABEL_54:
  v28 = -1;
  if ( _Str._Myres >= 0x10 )
    operator delete(p: _Str._Bx._Ptr);
  return _Ans;
}

//------------------------------------------------------------------------------
// Address: 0x1011DC90
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
// Address: 0x1011DD90
// Name: public: bool CMapDisp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CMapDisp::Create@<al>(CMapDisp *this@<ecx>, int a2@<ebx>)
{
  if ( CCoreDispInfo::CreateWithoutLOD(this: &this->m_CoreDispInfo) == 0 )
    return 0;
  CMapDisp::PostCreate(this, a2, a3: (int)this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011DDB0
// Name: public: void CMapDisp::UpdateSurfData(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapDisp::UpdateSurfData(CMapDisp *this@<ecx>, int a2@<ebx>, CMapFace *pFace)
{
  CMapDisp::InitDispSurfaceData(this, pFace, bGenerateStartPoint: false);
  if ( CCoreDispInfo::CreateWithoutLOD(this: &this->m_CoreDispInfo) != 0 )
    CMapDisp::PostCreate(this, a2, a3: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x1011DDE0
// Name: public: void CMapDisp::UpdateData(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapDisp::UpdateData(CMapDisp *this@<ecx>, int a2@<ebx>)
{
  if ( CCoreDispInfo::CreateWithoutLOD(this: &this->m_CoreDispInfo) != 0 )
    CMapDisp::PostCreate(this, a2, a3: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x1011DE00
// Name: public: void CMapDisp::InvertAlpha(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapDisp::InvertAlpha(CMapDisp *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  unsigned int v7; // edx
  float *p_m_Alpha; // ecx
  int v9; // ecx
  int v10; // edi
  float *v11; // eax

  v4 = 0;
  v5 = ((1 << this->m_CoreDispInfo.m_Power) + 1) * ((1 << this->m_CoreDispInfo.m_Power) + 1);
  if ( v5 >= 4 )
  {
    v6 = 0;
    v7 = ((unsigned int)(v5 - 4) >> 2) + 1;
    v4 = 4 * v7;
    do
    {
      this->m_CoreDispInfo.m_pVerts[v6].m_Alpha = 255.0 - this->m_CoreDispInfo.m_pVerts[v6].m_Alpha;
      this->m_CoreDispInfo.m_pVerts[v6 + 1].m_Alpha = 255.0 - this->m_CoreDispInfo.m_pVerts[v6 + 1].m_Alpha;
      this->m_CoreDispInfo.m_pVerts[v6 + 2].m_Alpha = 255.0 - this->m_CoreDispInfo.m_pVerts[v6 + 2].m_Alpha;
      p_m_Alpha = &this->m_CoreDispInfo.m_pVerts[v6 + 3].m_Alpha;
      v6 += 4;
      --v7;
      *p_m_Alpha = 255.0 - *p_m_Alpha;
    }
    while ( v7 != 0 );
  }
  if ( v4 < v5 )
  {
    v9 = v4;
    v10 = v5 - v4;
    do
    {
      v11 = &this->m_CoreDispInfo.m_pVerts[v9++].m_Alpha;
      --v10;
      *v11 = 255.0 - *v11;
    }
    while ( v10 != 0 );
  }
  if ( CCoreDispInfo::CreateWithoutLOD(this: &this->m_CoreDispInfo) != 0 )
    CMapDisp::PostCreate(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x1011DF00
// Name: public: void CMapDisp::Resample(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::Resample(CMapDisp *this, int power)
{
  int m_Power; // ebx
  bool v4; // zf
  int v5; // edi
  CMapAtom *v6; // eax
  int v7; // eax
  int delta; // [esp+14h] [ebp+8h]
  int deltaa; // [esp+14h] [ebp+8h]

  m_Power = this->m_CoreDispInfo.m_Power;
  if ( m_Power <= power )
  {
    v5 = 0;
    deltaa = power - m_Power;
    if ( deltaa > 0 )
    {
      do
      {
        this->m_CoreDispInfo.m_Power = v5 + m_Power + 1;
        CMapDisp::UpSample(this, oldPower: v5++ + m_Power);
      }
      while ( v5 < deltaa );
    }
  }
  else if ( m_Power - power > 0 )
  {
    delta = m_Power - power;
    do
    {
      this->m_CoreDispInfo.m_Power = m_Power - 1;
      CMapDisp::DownSample(this, oldPower: m_Power);
      v4 = delta-- == 1;
      --m_Power;
    }
    while ( !v4 );
  }
  if ( CCoreDispInfo::CreateWithoutLOD(this: &this->m_CoreDispInfo) != 0 )
    CMapDisp::PostCreate(this, a2: m_Power, a3: (int)this);
  v6 = this->GetParent(this);
  if ( v6 != nullptr )
  {
    v7 = (int)v6->GetParent(this: v6);
    if ( v7 != 0 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 60))(a1: v7, a2: 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011DFA0
// Name: public: void CMapDisp::Elevate(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapDisp::Elevate(CMapDisp *this@<ecx>, int a2@<ebx>, float elevation)
{
  this->m_CoreDispInfo.m_Elevation = elevation;
  if ( CCoreDispInfo::CreateWithoutLOD(this: &this->m_CoreDispInfo) != 0 )
    CMapDisp::PostCreate(this, a2, a3: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x1011DFD0
// Name: public: void CMapDisp::Scale(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapDisp::Scale(CMapDisp *this@<ecx>, int a2@<ebx>, float scale)
{
  float m_Scale; // xmm2_4
  int v5; // edi
  int v6; // ebx
  float v7; // xmm0_4
  int v8; // eax
  unsigned int v9; // edx
  CoreDispVert_t *m_pVerts; // ecx
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm4_4
  float *p_x; // ecx
  CoreDispVert_t *v15; // ecx
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float *v19; // ecx
  CoreDispVert_t *v20; // ecx
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float *v24; // ecx
  CoreDispVert_t *v25; // ecx
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float *v29; // ecx
  unsigned int v30; // ecx
  int v31; // edx
  CoreDispVert_t *v32; // eax
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm4_4
  float *v36; // eax
  int v37; // ebx
  int v38; // eax
  unsigned int v39; // edx
  CoreDispVert_t *v40; // ecx
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  float *v44; // ecx
  CoreDispVert_t *v45; // ecx
  float v46; // xmm0_4
  float v47; // xmm2_4
  float v48; // xmm3_4
  float *v49; // ecx
  CoreDispVert_t *v50; // ecx
  float v51; // xmm0_4
  float v52; // xmm2_4
  float v53; // xmm3_4
  float *v54; // ecx
  CoreDispVert_t *v55; // ecx
  float v56; // xmm0_4
  float v57; // xmm2_4
  float v58; // xmm3_4
  float *v59; // ecx
  unsigned int v60; // ecx
  int v61; // edi
  CoreDispVert_t *v62; // eax
  float v63; // xmm0_4
  float v64; // xmm2_4
  float v65; // xmm3_4
  float *v66; // eax

  m_Scale = this->m_Scale;
  if ( scale != m_Scale )
  {
    v5 = ((1 << this->m_CoreDispInfo.m_Power) + 1) * ((1 << this->m_CoreDispInfo.m_Power) + 1);
    if ( m_Scale != 1.0 )
    {
      v6 = 0;
      v7 = 1.0 / m_Scale;
      if ( v5 >= 4 )
      {
        v8 = 0;
        v9 = ((unsigned int)(v5 - 4) >> 2) + 1;
        v6 = 4 * v9;
        do
        {
          this->m_CoreDispInfo.m_pVerts[v8].m_FieldDistance = this->m_CoreDispInfo.m_pVerts[v8].m_FieldDistance * v7;
          m_pVerts = this->m_CoreDispInfo.m_pVerts;
          x = m_pVerts[v8].m_SubdivPos.x;
          y = m_pVerts[v8].m_SubdivPos.y;
          z = m_pVerts[v8].m_SubdivPos.z;
          p_x = &m_pVerts[v8].m_SubdivPos.x;
          *p_x = x * v7;
          p_x[1] = y * v7;
          p_x[2] = z * v7;
          this->m_CoreDispInfo.m_pVerts[v8 + 1].m_FieldDistance = this->m_CoreDispInfo.m_pVerts[v8 + 1].m_FieldDistance
                                                                * v7;
          v15 = this->m_CoreDispInfo.m_pVerts;
          v16 = v15[v8 + 1].m_SubdivPos.x;
          v17 = v15[v8 + 1].m_SubdivPos.y;
          v18 = v15[v8 + 1].m_SubdivPos.z;
          v19 = &v15[v8 + 1].m_SubdivPos.x;
          *v19 = v16 * v7;
          v19[1] = v17 * v7;
          v19[2] = v18 * v7;
          this->m_CoreDispInfo.m_pVerts[v8 + 2].m_FieldDistance = this->m_CoreDispInfo.m_pVerts[v8 + 2].m_FieldDistance
                                                                * v7;
          v20 = this->m_CoreDispInfo.m_pVerts;
          v21 = v20[v8 + 2].m_SubdivPos.x;
          v22 = v20[v8 + 2].m_SubdivPos.y;
          v23 = v20[v8 + 2].m_SubdivPos.z;
          v24 = &v20[v8 + 2].m_SubdivPos.x;
          *v24 = v21 * v7;
          v24[1] = v22 * v7;
          v24[2] = v23 * v7;
          this->m_CoreDispInfo.m_pVerts[v8 + 3].m_FieldDistance = v7
                                                                * this->m_CoreDispInfo.m_pVerts[v8 + 3].m_FieldDistance;
          v25 = this->m_CoreDispInfo.m_pVerts;
          v26 = v25[v8 + 3].m_SubdivPos.x;
          v27 = v25[v8 + 3].m_SubdivPos.y;
          v28 = v25[v8 + 3].m_SubdivPos.z;
          v29 = &v25[v8 + 3].m_SubdivPos.x;
          *v29 = v26 * v7;
          v8 += 4;
          --v9;
          v29[1] = v27 * v7;
          v29[2] = v28 * v7;
        }
        while ( v9 != 0 );
      }
      if ( v6 < v5 )
      {
        v30 = v6;
        v31 = v5 - v6;
        do
        {
          this->m_CoreDispInfo.m_pVerts[v30].m_FieldDistance = v7 * this->m_CoreDispInfo.m_pVerts[v30].m_FieldDistance;
          v32 = this->m_CoreDispInfo.m_pVerts;
          v33 = v32[v30].m_SubdivPos.x;
          v34 = v32[v30].m_SubdivPos.y;
          v35 = v32[v30].m_SubdivPos.z;
          v36 = &v32[v30++].m_SubdivPos.x;
          --v31;
          *v36 = v33 * v7;
          v36[1] = v34 * v7;
          v36[2] = v35 * v7;
        }
        while ( v31 != 0 );
      }
    }
    v37 = 0;
    if ( v5 >= 4 )
    {
      v38 = 0;
      v39 = ((unsigned int)(v5 - 4) >> 2) + 1;
      v37 = 4 * v39;
      do
      {
        this->m_CoreDispInfo.m_pVerts[v38].m_FieldDistance = this->m_CoreDispInfo.m_pVerts[v38].m_FieldDistance * scale;
        v40 = this->m_CoreDispInfo.m_pVerts;
        v41 = v40[v38].m_SubdivPos.x;
        v42 = v40[v38].m_SubdivPos.y;
        v43 = v40[v38].m_SubdivPos.z;
        v44 = &v40[v38].m_SubdivPos.x;
        *v44 = v41 * scale;
        v44[1] = v42 * scale;
        v44[2] = v43 * scale;
        this->m_CoreDispInfo.m_pVerts[v38 + 1].m_FieldDistance = this->m_CoreDispInfo.m_pVerts[v38 + 1].m_FieldDistance
                                                               * scale;
        v45 = this->m_CoreDispInfo.m_pVerts;
        v46 = v45[v38 + 1].m_SubdivPos.x;
        v47 = v45[v38 + 1].m_SubdivPos.y;
        v48 = v45[v38 + 1].m_SubdivPos.z;
        v49 = &v45[v38 + 1].m_SubdivPos.x;
        *v49 = v46 * scale;
        v49[1] = v47 * scale;
        v49[2] = v48 * scale;
        this->m_CoreDispInfo.m_pVerts[v38 + 2].m_FieldDistance = scale
                                                               * this->m_CoreDispInfo.m_pVerts[v38 + 2].m_FieldDistance;
        v50 = this->m_CoreDispInfo.m_pVerts;
        v51 = v50[v38 + 2].m_SubdivPos.x;
        v52 = v50[v38 + 2].m_SubdivPos.y;
        v53 = v50[v38 + 2].m_SubdivPos.z;
        v54 = &v50[v38 + 2].m_SubdivPos.x;
        *v54 = v51 * scale;
        v54[1] = v52 * scale;
        v54[2] = v53 * scale;
        this->m_CoreDispInfo.m_pVerts[v38 + 3].m_FieldDistance = this->m_CoreDispInfo.m_pVerts[v38 + 3].m_FieldDistance
                                                               * scale;
        v55 = this->m_CoreDispInfo.m_pVerts;
        v56 = v55[v38 + 3].m_SubdivPos.x;
        v57 = v55[v38 + 3].m_SubdivPos.y;
        v58 = v55[v38 + 3].m_SubdivPos.z;
        v59 = &v55[v38 + 3].m_SubdivPos.x;
        *v59 = v56 * scale;
        v38 += 4;
        --v39;
        v59[1] = v57 * scale;
        v59[2] = v58 * scale;
      }
      while ( v39 != 0 );
    }
    if ( v37 < v5 )
    {
      v60 = v37;
      v61 = v5 - v37;
      do
      {
        this->m_CoreDispInfo.m_pVerts[v60].m_FieldDistance = this->m_CoreDispInfo.m_pVerts[v60].m_FieldDistance * scale;
        v62 = this->m_CoreDispInfo.m_pVerts;
        v63 = v62[v60].m_SubdivPos.x;
        v64 = v62[v60].m_SubdivPos.y;
        v65 = v62[v60].m_SubdivPos.z;
        v66 = &v62[v60++].m_SubdivPos.x;
        --v61;
        *v66 = v63 * scale;
        v66[1] = v64 * scale;
        v66[2] = v65 * scale;
      }
      while ( v61 != 0 );
    }
    this->m_Scale = scale;
    if ( CCoreDispInfo::CreateWithoutLOD(this: &this->m_CoreDispInfo) != 0 )
      CMapDisp::PostCreate(this, a2, a3: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E450
// Name: public: bool CMapDisp::SerializedLoadRMF(class std::basic_fstream<char,struct std::char_traits<char>> __near &,class CMapFace __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapDisp::SerializedLoadRMF(CMapDisp *this, std::fstream *file, CMapFace *pFace, float version)
{
  int v6; // edi
  int v7; // edi
  signed int v8; // ecx
  int v9; // edx
  float *v10; // eax
  CoreDispVert_t *m_pVerts; // edi
  double v12; // st7
  CoreDispVert_t *v13; // edi
  CoreDispVert_t *v14; // edi
  CoreDispVert_t *v15; // edi
  unsigned int v16; // ebx
  float *v17; // edx
  CoreDispVert_t *v18; // eax
  double v19; // st7
  char v21; // [esp+Ch] [ebp-1224h] BYREF
  float v22[865]; // [esp+14h] [ebp-121Ch] BYREF
  char v23[1156]; // [esp+D98h] [ebp-498h] BYREF
  char v24[4]; // [esp+121Ch] [ebp-14h] BYREF
  char v25[4]; // [esp+1220h] [ebp-10h] BYREF
  int v26; // [esp+1224h] [ebp-Ch]
  char _Str[4]; // [esp+1228h] [ebp-8h] BYREF
  int i; // [esp+122Ch] [ebp-4h]
  std::istream *v29; // [esp+1238h] [ebp+8h]

  std::istream::read(this: file, _Str, _Count: 4);
  std::istream::read(this: file, _Str: (char *)this->m_MapAxes, _Count: 12);
  std::istream::read(this: file, _Str: (char *)&this->m_MapAxes[1], _Count: 12);
  std::istream::read(this: file, _Str: v25, _Count: 4);
  std::istream::read(this: file, _Str: v24, _Count: 4);
  v6 = 1 << _Str[0];
  this->m_CoreDispInfo.m_Power = *(_DWORD *)_Str;
  this->m_bHasMappingAxes = true;
  v7 = (v6 + 1) * (v6 + 1);
  v26 = v7;
  if ( v7 > 0 )
  {
    v29 = (std::istream *)&v21;
    for ( i = v7; i != 0; --i )
    {
      std::istream::read(this: file, _Str: v29->gap0, _Count: 12);
      v29 = (std::istream *)((char *)v29 + 12);
    }
  }
  std::istream::read(this: file, _Str: v23, _Count: (unsigned int)(4 * v7));
  v8 = 0;
  if ( v7 >= 4 )
  {
    v9 = 0;
    v10 = v22;
    do
    {
      m_pVerts = this->m_CoreDispInfo.m_pVerts;
      m_pVerts[v9].m_FieldVector.x = *(v10 - 2);
      v8 += 4;
      v12 = *(v10 - 1);
      v10 += 12;
      m_pVerts[v9].m_FieldVector.y = v12;
      m_pVerts[v9].m_FieldVector.z = *(v10 - 12);
      this->m_CoreDispInfo.m_pVerts[v9].m_FieldDistance = v22[v8 + 861];
      v13 = &this->m_CoreDispInfo.m_pVerts[v9 + 1];
      v13->m_FieldVector.x = *(v10 - 11);
      v13->m_FieldVector.y = *(v10 - 10);
      v13->m_FieldVector.z = *(v10 - 9);
      this->m_CoreDispInfo.m_pVerts[v9 + 1].m_FieldDistance = v22[v8 + 862];
      v14 = &this->m_CoreDispInfo.m_pVerts[v9 + 2];
      v14->m_FieldVector.x = *(v10 - 8);
      v9 += 4;
      v14->m_FieldVector.y = *(v10 - 7);
      v14->m_FieldVector.z = *(v10 - 6);
      *((float *)&this->m_CoreDispInfo.m_pVerts[v9 - 1] - 53) = v22[v8 + 863];
      v15 = this->m_CoreDispInfo.m_pVerts;
      v15[v9 - 1].m_FieldVector.x = *(v10 - 5);
      v15[v9 - 1].m_FieldVector.y = *(v10 - 4);
      v15[v9 - 1].m_FieldVector.z = *(v10 - 3);
      this->m_CoreDispInfo.m_pVerts[v9 - 1].m_FieldDistance = v22[v8 + 864];
      v7 = v26;
    }
    while ( v8 < v26 - 3 );
  }
  if ( v8 < v7 )
  {
    v16 = v8;
    v17 = &v22[3 * v8];
    do
    {
      v18 = this->m_CoreDispInfo.m_pVerts;
      v18[v16].m_FieldVector.x = *(v17 - 2);
      ++v8;
      v19 = *(v17 - 1);
      v17 += 3;
      v18[v16++].m_FieldVector.y = v19;
      v18[v16 - 1].m_FieldVector.z = *(v17 - 3);
      this->m_CoreDispInfo.m_pVerts[v16 - 1].m_FieldDistance = v22[v8 + 864];
    }
    while ( v8 < v7 );
  }
  this->SetParent(this, a2: pFace);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011E690
// Name: public: virtual void CMapDisp::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::DoTransform(CMapDisp *this, const VMatrix *matrix)
{
  CMapDisp *v2; // ebx
  CCoreDispSurface *p_m_Surf; // edi
  float *p_x; // edi
  float *v6; // eax
  float *v7; // ecx
  float *v8; // edx
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  __int64 v23; // [esp+8h] [ebp-40h]
  __int64 v24; // [esp+14h] [ebp-34h]
  float v25; // [esp+28h] [ebp-20h]
  CMapFace *pFace; // [esp+38h] [ebp-10h]
  const VMatrix *matrixa; // [esp+50h] [ebp+8h]

  v2 = this;
  p_m_Surf = &this->m_CoreDispInfo.m_Surf;
  pFace = (CMapFace *)((int (*)(void))this->GetParent)();
  if ( pFace != nullptr && p_m_Surf != nullptr )
  {
    if ( (float)((float)(matrix->m[0][0] * matrix->m[1][1]) * matrix->m[2][2]) < 0.0 )
    {
      p_m_Surf->m_PointStartIndex = 3 - p_m_Surf->m_PointStartIndex;
      CMapDisp::Flip(this: v2, flipType: 2);
    }
    if ( ((1 << v2->m_CoreDispInfo.m_Power) + 1) * ((1 << v2->m_CoreDispInfo.m_Power) + 1) > 0 )
    {
      p_x = &v2->m_CoreDispInfo.m_pVerts->m_FieldVector.x;
      v6 = p_x + 9;
      v7 = p_x + 9;
      v8 = p_x + 6;
      matrixa = (const VMatrix *)(((1 << v2->m_CoreDispInfo.m_Power) + 1) * ((1 << v2->m_CoreDispInfo.m_Power) + 1));
      do
      {
        v9 = *(v8 - 5);
        v10 = *(v8 - 4);
        v11 = 1.0
            / (float)((float)((float)((float)(matrix->m[3][0] * *p_x) + (float)(matrix->m[3][1] * v9))
                            + (float)(matrix->m[3][2] * v10))
                    + matrix->m[3][3]);
        v12 = (float)((float)((float)(matrix->m[0][1] * v9) + (float)(matrix->m[0][0] * *p_x))
                    + (float)(v10 * matrix->m[0][2]))
            + matrix->m[0][3];
        v25 = v10;
        v13 = (float)((float)((float)((float)(*p_x * matrix->m[2][0]) + (float)(v9 * matrix->m[2][1]))
                            + (float)(matrix->m[2][2] * v10))
                    + matrix->m[2][3])
            * v11;
        v14 = (float)((float)((float)(matrix->m[1][0] * *p_x) + (float)(v9 * matrix->m[1][1]))
                    + (float)(matrix->m[1][2] * v25))
            + matrix->m[1][3];
        *p_x = v12 * v11;
        *(v7 - 7) = v13;
        *(v7 - 8) = v14 * v11;
        v24 = *((_QWORD *)v7 - 1);
        v15 = 1.0
            / (float)((float)((float)((float)(matrix->m[3][0] * *(float *)&v24)
                                    + (float)(matrix->m[3][1] * *((float *)&v24 + 1)))
                            + (float)(matrix->m[3][2] * *v7))
                    + matrix->m[3][3]);
        v16 = (float)((float)((float)((float)(*((float *)&v24 + 1) * matrix->m[2][1])
                                    + (float)(*(float *)&v24 * matrix->m[2][0]))
                            + (float)(matrix->m[2][2] * *v7))
                    + matrix->m[2][3])
            * v15;
        v17 = (float)((float)((float)(matrix->m[1][0] * *(float *)&v24) + (float)(*((float *)&v24 + 1) * matrix->m[1][1]))
                    + (float)(matrix->m[1][2] * *v7))
            + matrix->m[1][3];
        *(v6 - 2) = (float)((float)((float)((float)(matrix->m[0][1] * *((float *)&v24 + 1))
                                          + (float)(matrix->m[0][0] * *(float *)&v24))
                                  + (float)(*v7 * matrix->m[0][2]))
                          + matrix->m[0][3])
                  * v15;
        *v6 = v16;
        *(v6 - 1) = v17 * v15;
        v18 = *(v6 - 3);
        v23 = *(_QWORD *)(v6 - 5);
        v19 = 1.0
            / (float)((float)((float)((float)(matrix->m[3][0] * *(float *)&v23)
                                    + (float)(matrix->m[3][1] * *((float *)&v23 + 1)))
                            + (float)(matrix->m[3][2] * v18))
                    + matrix->m[3][3]);
        v20 = (float)((float)((float)((float)(matrix->m[0][1] * *((float *)&v23 + 1))
                                    + (float)(matrix->m[0][0] * *(float *)&v23))
                            + (float)(v18 * matrix->m[0][2]))
                    + matrix->m[0][3])
            * v19;
        v21 = (float)((float)((float)((float)(matrix->m[1][0] * *(float *)&v23)
                                    + (float)(*((float *)&v23 + 1) * matrix->m[1][1]))
                            + (float)(matrix->m[1][2] * v18))
                    + matrix->m[1][3])
            * v19;
        v22 = (float)((float)((float)((float)(*((float *)&v23 + 1) * matrix->m[2][1])
                                    + (float)(*(float *)&v23 * matrix->m[2][0]))
                            + (float)(matrix->m[2][2] * v18))
                    + matrix->m[2][3])
            * v19;
        v7 += 56;
        *(v8 - 2) = v20;
        *(v8 - 1) = v21;
        *v8 = v22;
        v6 += 56;
        p_x += 56;
        v8 += 56;
        matrixa = (const VMatrix *)((char *)matrixa - 1);
      }
      while ( matrixa != nullptr );
      v2 = this;
    }
    CMapDisp::InitDispSurfaceData(this: v2, pFace, bGenerateStartPoint: false);
    if ( CCoreDispInfo::CreateWithoutLOD(this: &v2->m_CoreDispInfo) != 0 )
      CMapDisp::PostCreate(this: v2, a2: (int)v2, a3: (int)matrix);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EA50
// Name: public: void CMapDisp::Paint_Update(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::Paint_Update(CMapDisp *this, bool bSplit)
{
  int v3; // esi
  int v4; // ebx
  int m_nType; // eax
  CMapAtom *v6; // eax
  int v7; // eax
  int v8; // [esp+4h] [ebp-8h]
  Vector *m_Values; // [esp+8h] [ebp-4h]

  if ( this->m_Canvas.m_bDirty )
  {
    v3 = 0;
    v4 = ((1 << this->m_CoreDispInfo.m_Power) + 1) * ((1 << this->m_CoreDispInfo.m_Power) + 1);
    if ( v4 > 0 )
    {
      v8 = 0;
      m_Values = this->m_Canvas.m_Values;
      do
      {
        if ( this->m_Canvas.m_bValuesDirty[v3] )
        {
          m_nType = this->m_Canvas.m_nType;
          if ( m_nType != 0 )
          {
            if ( m_nType == 1 )
              this->m_CoreDispInfo.m_pVerts[v8].m_Alpha = m_Values->x;
          }
          else
          {
            CMapDisp::PaintPosition_Update(this, iVert: v3);
          }
        }
        ++m_Values;
        ++v8;
        ++v3;
      }
      while ( v3 < v4 );
    }
    if ( CCoreDispInfo::CreateWithoutLOD(this: &this->m_CoreDispInfo) != 0 )
      CMapDisp::PostCreate(this, a2: v4, a3: v3);
    if ( !bSplit )
    {
      v6 = this->GetParent(this);
      if ( v6 != nullptr )
      {
        v7 = (int)v6->GetParent(this: v6);
        if ( v7 != 0 )
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 60))(a1: v7, a2: 4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EB20
// Name: protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char>> std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::ios_base __near &,int __near &,unsigned short __near &)const
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::num_get<char,std::istreambuf_iterator<char>>::do_get(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        std::istreambuf_iterator<char> *result,
        std::istreambuf_iterator<char> _First,
        std::istreambuf_iterator<char> _Last,
        std::ios_base *_Iosbase,
        int *_State,
        unsigned __int16 *_Val)
{
  std::ios_base *v7; // edi
  const std::locale *v9; // eax
  int v10; // ebx
  unsigned int v11; // edi
  std::ios_base_vtbl *v12; // eax
  int v13; // esi
  void (__thiscall ***v14)(_DWORD, int); // esi
  char *v15; // edi
  unsigned int v16; // esi
  bool v17; // zf
  int *v18; // eax
  std::streambuf *Strbuf; // edx
  char _Ac[32]; // [esp+Ch] [ebp-38h] BYREF
  char *_Ep; // [esp+2Ch] [ebp-18h] BYREF
  std::_Lockit v23; // [esp+30h] [ebp-14h] BYREF
  int _Errno; // [esp+34h] [ebp-10h] BYREF
  int v25; // [esp+40h] [ebp-4h]

  v7 = _Iosbase;
  _Errno = 0;
  v9 = std::ios_base::getloc(this: _Iosbase, result: (std::locale *)&_Iosbase);
  v25 = 0;
  v10 = std::num_get<char,std::istreambuf_iterator<char>>::_Getifld(
          this,
          _Ac,
          &_First,
          &_Last,
          _Basefield: v7->_Fmtfl,
          _Loc: v9);
  v25 = -1;
  v11 = (unsigned int)_Iosbase;
  if ( _Iosbase != nullptr )
  {
    std::_Lockit::_Lockit(this: &v23, kind: 0);
    v25 = 1;
    v12 = *(std::ios_base_vtbl **)(v11 + 4);
    if ( v12 != nullptr && v12 != (std::ios_base_vtbl *)-1 )
      *(_DWORD *)(v11 + 4) = (char *)v12 - 1;
    v13 = -(*(_DWORD *)(v11 + 4) == 0);
    v25 = -1;
    std::_Lockit::~_Lockit(this: &v23);
    v14 = (void (__thiscall ***)(_DWORD, int))(v11 & v13);
    if ( v14 != nullptr )
      (**v14)(a1: v14, a2: 1);
  }
  v15 = &_Ac[1];
  if ( _Ac[0] != 45 )
    v15 = _Ac;
  v16 = _Stoulx(s: v15, endptr: &_Ep, base: v10, perr: &_Errno);
  v17 = (unsigned __int8)std::istreambuf_iterator<char>::equal(this: &_First, _Right: &_Last) == 0;
  v18 = _State;
  if ( !v17 )
    *_State |= 1u;
  if ( _Ep == v15 || _Errno != 0 || v16 > 0xFFFF )
  {
    *v18 |= 2u;
  }
  else
  {
    if ( _Ac[0] == 45 )
      v16 = -v16;
    *_Val = v16;
  }
  Strbuf = _First._Strbuf;
  *(_DWORD *)&result->_Got = *(_DWORD *)&_First._Got;
  result->_Strbuf = Strbuf;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011EC50
// Name: protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char>> std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::ios_base __near &,int __near &,unsigned int __near &)const
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::num_get<char,std::istreambuf_iterator<char>>::do_get(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        std::istreambuf_iterator<char> *result,
        std::istreambuf_iterator<char> _First,
        std::istreambuf_iterator<char> _Last,
        std::ios_base *_Iosbase,
        int *_State,
        unsigned int *_Val)
{
  std::ios_base *v7; // edi
  const std::locale *v9; // eax
  int v10; // ebx
  unsigned int v11; // edi
  std::ios_base_vtbl *v12; // eax
  int v13; // esi
  void (__thiscall ***v14)(_DWORD, int); // esi
  char *v15; // edi
  int v16; // esi
  bool v17; // zf
  int *v18; // eax
  std::streambuf *Strbuf; // edx
  char _Ac[32]; // [esp+Ch] [ebp-38h] BYREF
  char *_Ep; // [esp+2Ch] [ebp-18h] BYREF
  std::_Lockit v23; // [esp+30h] [ebp-14h] BYREF
  int _Errno; // [esp+34h] [ebp-10h] BYREF
  int v25; // [esp+40h] [ebp-4h]

  v7 = _Iosbase;
  _Errno = 0;
  v9 = std::ios_base::getloc(this: _Iosbase, result: (std::locale *)&_Iosbase);
  v25 = 0;
  v10 = std::num_get<char,std::istreambuf_iterator<char>>::_Getifld(
          this,
          _Ac,
          &_First,
          &_Last,
          _Basefield: v7->_Fmtfl,
          _Loc: v9);
  v25 = -1;
  v11 = (unsigned int)_Iosbase;
  if ( _Iosbase != nullptr )
  {
    std::_Lockit::_Lockit(this: &v23, kind: 0);
    v25 = 1;
    v12 = *(std::ios_base_vtbl **)(v11 + 4);
    if ( v12 != nullptr && v12 != (std::ios_base_vtbl *)-1 )
      *(_DWORD *)(v11 + 4) = (char *)v12 - 1;
    v13 = -(*(_DWORD *)(v11 + 4) == 0);
    v25 = -1;
    std::_Lockit::~_Lockit(this: &v23);
    v14 = (void (__thiscall ***)(_DWORD, int))(v11 & v13);
    if ( v14 != nullptr )
      (**v14)(a1: v14, a2: 1);
  }
  v15 = &_Ac[1];
  if ( _Ac[0] != 45 )
    v15 = _Ac;
  v16 = _Stoulx(s: v15, endptr: &_Ep, base: v10, perr: &_Errno);
  v17 = (unsigned __int8)std::istreambuf_iterator<char>::equal(this: &_First, _Right: &_Last) == 0;
  v18 = _State;
  if ( !v17 )
    *_State |= 1u;
  if ( _Ep == v15 || _Errno != 0 )
  {
    *v18 |= 2u;
  }
  else
  {
    if ( _Ac[0] == 45 )
      v16 = -v16;
    *_Val = v16;
  }
  Strbuf = _First._Strbuf;
  *(_DWORD *)&result->_Got = *(_DWORD *)&_First._Got;
  result->_Strbuf = Strbuf;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011ED70
// Name: protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char>> std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::ios_base __near &,int __near &,long __near &)const
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::num_get<char,std::istreambuf_iterator<char>>::do_get(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        std::istreambuf_iterator<char> *result,
        std::istreambuf_iterator<char> _First,
        std::istreambuf_iterator<char> _Last,
        std::ios_base *_Iosbase,
        int *_State,
        int *_Val)
{
  std::ios_base *v7; // edi
  const std::locale *v9; // eax
  int v10; // eax
  unsigned int v11; // edi
  std::ios_base_vtbl *v12; // eax
  int v13; // esi
  void (__thiscall ***v14)(_DWORD, int); // esi
  bool v15; // zf
  int *v16; // eax
  std::streambuf *Strbuf; // edx
  char _Ac[32]; // [esp+8h] [ebp-3Ch] BYREF
  int _Ans; // [esp+28h] [ebp-1Ch]
  char *_Ep; // [esp+2Ch] [ebp-18h] BYREF
  std::_Lockit v22; // [esp+30h] [ebp-14h] BYREF
  int _Errno; // [esp+34h] [ebp-10h] BYREF
  int v24; // [esp+40h] [ebp-4h]

  v7 = _Iosbase;
  _Errno = 0;
  v9 = std::ios_base::getloc(this: _Iosbase, result: (std::locale *)&_Iosbase);
  v24 = 0;
  v10 = std::num_get<char,std::istreambuf_iterator<char>>::_Getifld(
          this,
          _Ac,
          &_First,
          &_Last,
          _Basefield: v7->_Fmtfl,
          _Loc: v9);
  _Ans = _Stolx(s: _Ac, endptr: &_Ep, base: v10, perr: &_Errno);
  v24 = -1;
  v11 = (unsigned int)_Iosbase;
  if ( _Iosbase != nullptr )
  {
    std::_Lockit::_Lockit(this: &v22, kind: 0);
    v24 = 1;
    v12 = *(std::ios_base_vtbl **)(v11 + 4);
    if ( v12 != nullptr && v12 != (std::ios_base_vtbl *)-1 )
      *(_DWORD *)(v11 + 4) = (char *)v12 - 1;
    v13 = -(*(_DWORD *)(v11 + 4) == 0);
    v24 = -1;
    std::_Lockit::~_Lockit(this: &v22);
    v14 = (void (__thiscall ***)(_DWORD, int))(v11 & v13);
    if ( v14 != nullptr )
      (**v14)(a1: v14, a2: 1);
  }
  v15 = (unsigned __int8)std::istreambuf_iterator<char>::equal(this: &_First, _Right: &_Last) == 0;
  v16 = _State;
  if ( !v15 )
    *_State |= 1u;
  if ( _Ep == _Ac || _Errno != 0 )
    *v16 |= 2u;
  else
    *_Val = _Ans;
  Strbuf = _First._Strbuf;
  *(_DWORD *)&result->_Got = *(_DWORD *)&_First._Got;
  result->_Strbuf = Strbuf;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011EE90
// Name: protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char>> std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::ios_base __near &,int __near &,unsigned long __near &)const
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::num_get<char,std::istreambuf_iterator<char>>::do_get(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        std::istreambuf_iterator<char> *result,
        std::istreambuf_iterator<char> _First,
        std::istreambuf_iterator<char> _Last,
        std::ios_base *_Iosbase,
        int *_State,
        unsigned int *_Val)
{
  std::ios_base *v7; // edi
  const std::locale *v9; // eax
  int v10; // eax
  unsigned int v11; // edi
  std::ios_base_vtbl *v12; // eax
  int v13; // esi
  void (__thiscall ***v14)(_DWORD, int); // esi
  bool v15; // zf
  int *v16; // eax
  std::streambuf *Strbuf; // edx
  char _Ac[32]; // [esp+8h] [ebp-3Ch] BYREF
  unsigned int _Ans; // [esp+28h] [ebp-1Ch]
  char *_Ep; // [esp+2Ch] [ebp-18h] BYREF
  std::_Lockit v22; // [esp+30h] [ebp-14h] BYREF
  int _Errno; // [esp+34h] [ebp-10h] BYREF
  int v24; // [esp+40h] [ebp-4h]

  v7 = _Iosbase;
  _Errno = 0;
  v9 = std::ios_base::getloc(this: _Iosbase, result: (std::locale *)&_Iosbase);
  v24 = 0;
  v10 = std::num_get<char,std::istreambuf_iterator<char>>::_Getifld(
          this,
          _Ac,
          &_First,
          &_Last,
          _Basefield: v7->_Fmtfl,
          _Loc: v9);
  _Ans = _Stoulx(s: _Ac, endptr: &_Ep, base: v10, perr: &_Errno);
  v24 = -1;
  v11 = (unsigned int)_Iosbase;
  if ( _Iosbase != nullptr )
  {
    std::_Lockit::_Lockit(this: &v22, kind: 0);
    v24 = 1;
    v12 = *(std::ios_base_vtbl **)(v11 + 4);
    if ( v12 != nullptr && v12 != (std::ios_base_vtbl *)-1 )
      *(_DWORD *)(v11 + 4) = (char *)v12 - 1;
    v13 = -(*(_DWORD *)(v11 + 4) == 0);
    v24 = -1;
    std::_Lockit::~_Lockit(this: &v22);
    v14 = (void (__thiscall ***)(_DWORD, int))(v11 & v13);
    if ( v14 != nullptr )
      (**v14)(a1: v14, a2: 1);
  }
  v15 = (unsigned __int8)std::istreambuf_iterator<char>::equal(this: &_First, _Right: &_Last) == 0;
  v16 = _State;
  if ( !v15 )
    *_State |= 1u;
  if ( _Ep == _Ac || _Errno != 0 )
    *v16 |= 2u;
  else
    *_Val = _Ans;
  Strbuf = _First._Strbuf;
  *(_DWORD *)&result->_Got = *(_DWORD *)&_First._Got;
  result->_Strbuf = Strbuf;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011EFB0
// Name: protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char>> std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::ios_base __near &,int __near &,__int64 __near &)const
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::num_get<char,std::istreambuf_iterator<char>>::do_get(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        std::istreambuf_iterator<char> *result,
        std::istreambuf_iterator<char> _First,
        std::istreambuf_iterator<char> _Last,
        std::ios_base *_Iosbase,
        int *_State,
        __int64 *_Val)
{
  std::ios_base *v7; // edi
  const std::locale *v9; // eax
  int v10; // eax
  unsigned int v11; // edi
  std::ios_base_vtbl *v12; // eax
  int v13; // esi
  void (__thiscall ***v14)(_DWORD, int); // esi
  bool v15; // zf
  int *v16; // eax
  char _Ac[32]; // [esp+8h] [ebp-40h] BYREF
  __int64 _Ans; // [esp+28h] [ebp-20h]
  char *_Ep; // [esp+30h] [ebp-18h] BYREF
  std::_Lockit v21; // [esp+34h] [ebp-14h] BYREF
  int _Errno; // [esp+38h] [ebp-10h] BYREF
  int v23; // [esp+44h] [ebp-4h]

  v7 = _Iosbase;
  _Errno = 0;
  v9 = std::ios_base::getloc(this: _Iosbase, result: (std::locale *)&_Iosbase);
  v23 = 0;
  v10 = std::num_get<char,std::istreambuf_iterator<char>>::_Getifld(
          this,
          _Ac,
          &_First,
          &_Last,
          _Basefield: v7->_Fmtfl,
          _Loc: v9);
  _Ans = _Stollx(s: _Ac, endptr: &_Ep, base: v10, perr: &_Errno);
  v23 = -1;
  v11 = (unsigned int)_Iosbase;
  if ( _Iosbase != nullptr )
  {
    std::_Lockit::_Lockit(this: &v21, kind: 0);
    v23 = 1;
    v12 = *(std::ios_base_vtbl **)(v11 + 4);
    if ( v12 != nullptr && v12 != (std::ios_base_vtbl *)-1 )
      *(_DWORD *)(v11 + 4) = (char *)v12 - 1;
    v13 = -(*(_DWORD *)(v11 + 4) == 0);
    v23 = -1;
    std::_Lockit::~_Lockit(this: &v21);
    v14 = (void (__thiscall ***)(_DWORD, int))(v11 & v13);
    if ( v14 != nullptr )
      (**v14)(a1: v14, a2: 1);
  }
  v15 = (unsigned __int8)std::istreambuf_iterator<char>::equal(this: &_First, _Right: &_Last) == 0;
  v16 = _State;
  if ( !v15 )
    *_State |= 1u;
  if ( _Ep == _Ac || _Errno != 0 )
    *v16 |= 2u;
  else
    *_Val = _Ans;
  *result = _First;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011F0D0
// Name: protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char>> std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::ios_base __near &,int __near &,unsigned __int64 __near &)const
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::num_get<char,std::istreambuf_iterator<char>>::do_get(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        std::istreambuf_iterator<char> *result,
        std::istreambuf_iterator<char> _First,
        std::istreambuf_iterator<char> _Last,
        std::ios_base *_Iosbase,
        int *_State,
        unsigned __int64 *_Val)
{
  std::ios_base *v7; // edi
  const std::locale *v9; // eax
  int v10; // eax
  unsigned int v11; // edi
  std::ios_base_vtbl *v12; // eax
  int v13; // esi
  void (__thiscall ***v14)(_DWORD, int); // esi
  bool v15; // zf
  int *v16; // eax
  char _Ac[32]; // [esp+8h] [ebp-40h] BYREF
  unsigned __int64 _Ans; // [esp+28h] [ebp-20h]
  char *_Ep; // [esp+30h] [ebp-18h] BYREF
  std::_Lockit v21; // [esp+34h] [ebp-14h] BYREF
  int _Errno; // [esp+38h] [ebp-10h] BYREF
  int v23; // [esp+44h] [ebp-4h]

  v7 = _Iosbase;
  _Errno = 0;
  v9 = std::ios_base::getloc(this: _Iosbase, result: (std::locale *)&_Iosbase);
  v23 = 0;
  v10 = std::num_get<char,std::istreambuf_iterator<char>>::_Getifld(
          this,
          _Ac,
          &_First,
          &_Last,
          _Basefield: v7->_Fmtfl,
          _Loc: v9);
  _Ans = _Stoullx(s: _Ac, endptr: &_Ep, base: v10, perr: &_Errno);
  v23 = -1;
  v11 = (unsigned int)_Iosbase;
  if ( _Iosbase != nullptr )
  {
    std::_Lockit::_Lockit(this: &v21, kind: 0);
    v23 = 1;
    v12 = *(std::ios_base_vtbl **)(v11 + 4);
    if ( v12 != nullptr && v12 != (std::ios_base_vtbl *)-1 )
      *(_DWORD *)(v11 + 4) = (char *)v12 - 1;
    v13 = -(*(_DWORD *)(v11 + 4) == 0);
    v23 = -1;
    std::_Lockit::~_Lockit(this: &v21);
    v14 = (void (__thiscall ***)(_DWORD, int))(v11 & v13);
    if ( v14 != nullptr )
      (**v14)(a1: v14, a2: 1);
  }
  v15 = (unsigned __int8)std::istreambuf_iterator<char>::equal(this: &_First, _Right: &_Last) == 0;
  v16 = _State;
  if ( !v15 )
    *_State |= 1u;
  if ( _Ep == _Ac || _Errno != 0 )
    *v16 |= 2u;
  else
    *_Val = _Ans;
  *result = _First;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011F1F0
// Name: protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char>> std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::ios_base __near &,int __near &,void __near * __near &)const
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::num_get<char,std::istreambuf_iterator<char>>::do_get(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        std::istreambuf_iterator<char> *result,
        std::istreambuf_iterator<char> _First,
        std::istreambuf_iterator<char> _Last,
        std::ios_base *_Iosbase,
        int *_State,
        void **_Val)
{
  const std::locale *v8; // eax
  unsigned int v9; // edi
  std::ios_base_vtbl *v10; // eax
  int v11; // esi
  void (__thiscall ***v12)(_DWORD, int); // esi
  void *v13; // esi
  bool v14; // zf
  int *v15; // eax
  char _Ac[32]; // [esp+8h] [ebp-40h] BYREF
  char *_Ep; // [esp+28h] [ebp-20h] BYREF
  int _Base; // [esp+30h] [ebp-18h]
  std::_Lockit v20; // [esp+34h] [ebp-14h] BYREF
  int _Errno; // [esp+38h] [ebp-10h] BYREF
  int v22; // [esp+44h] [ebp-4h]

  _Errno = 0;
  v8 = std::ios_base::getloc(this: _Iosbase, result: (std::locale *)&_Iosbase);
  v22 = 0;
  _Base = std::num_get<char,std::istreambuf_iterator<char>>::_Getifld(
            this,
            _Ac,
            &_First,
            &_Last,
            _Basefield: 2048,
            _Loc: v8);
  v22 = -1;
  v9 = (unsigned int)_Iosbase;
  if ( _Iosbase != nullptr )
  {
    std::_Lockit::_Lockit(this: &v20, kind: 0);
    v22 = 1;
    v10 = *(std::ios_base_vtbl **)(v9 + 4);
    if ( v10 != nullptr && v10 != (std::ios_base_vtbl *)-1 )
      *(_DWORD *)(v9 + 4) = (char *)v10 - 1;
    v11 = -(*(_DWORD *)(v9 + 4) == 0);
    v22 = -1;
    std::_Lockit::~_Lockit(this: &v20);
    v12 = (void (__thiscall ***)(_DWORD, int))(v9 & v11);
    if ( v12 != nullptr )
      (**v12)(a1: v12, a2: 1);
  }
  v13 = (void *)_Stoulx(s: _Ac, endptr: &_Ep, base: _Base, perr: &_Errno);
  _Base = 0;
  v14 = (unsigned __int8)std::istreambuf_iterator<char>::equal(this: &_First, _Right: &_Last) == 0;
  v15 = _State;
  if ( !v14 )
    *_State |= 1u;
  if ( _Ep == _Ac || _Errno != 0 )
    *v15 |= 2u;
  else
    *_Val = v13;
  *result = _First;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011F310
// Name: private: int std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::_Getffld(char __near *,class std::istreambuf_iterator<char,struct std::char_traits<char>> __near &,class std::istreambuf_iterator<char,struct std::char_traits<char>> __near &,class std::ios_base __near &,int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __cdecl std::num_get<char,std::istreambuf_iterator<char>>::_Getffld(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        char *_Ac,
        std::istreambuf_iterator<char> *_First,
        std::istreambuf_iterator<char> *_Last,
        std::ios_base *_Iosbase,
        int *_Phexexp)
{
  const std::locale *v7; // eax
  std::numpunct<char> *v8; // ebx
  char v9; // al
  std::istreambuf_iterator<char> *v10; // ecx
  int v11; // edi
  std::string *Ptr; // eax
  std::string *p_Grouping; // eax
  int v14; // ebx
  unsigned int Myres; // edi
  std::streambuf *Strbuf; // ecx
  char **IGnext; // eax
  int v18; // eax
  char v19; // al
  char *v20; // ecx
  std::string *v21; // eax
  std::string *v22; // eax
  std::string *p_Groups; // eax
  char v24; // al
  std::string *v25; // eax
  std::string *v26; // edx
  char v27; // cl
  std::string *v28; // eax
  std::string *v29; // eax
  char *v30; // ebx
  std::streambuf *v31; // ecx
  char **v32; // eax
  int v33; // eax
  std::streambuf *v34; // ecx
  char **v35; // eax
  int v36; // eax
  std::streambuf *v37; // ecx
  char **v38; // eax
  int v39; // eax
  char Val; // bl
  char v41; // cl
  char *v42; // eax
  std::streambuf *v43; // ecx
  int *IGcount; // eax
  char **v45; // ecx
  char *v46; // eax
  int v47; // eax
  int v48; // edi
  std::streambuf *v49; // ecx
  char **v50; // eax
  int v51; // eax
  std::streambuf *v52; // ecx
  int *v53; // edx
  char **v54; // ecx
  char *v55; // eax
  int v56; // eax
  char *v57; // eax
  int v58; // edi
  std::streambuf *v59; // ecx
  char **v60; // eax
  int v61; // eax
  std::streambuf *v62; // ecx
  char **v63; // eax
  int v64; // eax
  std::streambuf *v65; // ecx
  char **v66; // eax
  int v67; // eax
  char *v68; // ecx
  std::streambuf *v69; // ecx
  int *v70; // edx
  char **v71; // ecx
  char *v72; // eax
  int v73; // eax
  std::streambuf *v74; // ecx
  char **v75; // eax
  int v76; // eax
  std::streambuf *v77; // ecx
  char **v78; // eax
  int v79; // eax
  char *v80; // edi
  std::streambuf *v81; // ecx
  char *v82; // edi
  int *v83; // edx
  char **v84; // ecx
  char *v85; // eax
  int v86; // eax
  std::streambuf *v87; // ecx
  char **v88; // eax
  int v89; // eax
  std::streambuf *v90; // ecx
  int *v91; // edx
  char **v92; // ecx
  char *v93; // eax
  int v94; // eax
  std::streambuf *v95; // ecx
  char **v96; // eax
  int v97; // eax
  int *v98; // edx
  char **v99; // ecx
  char *v100; // eax
  std::streambuf *v101; // ecx
  char **v102; // eax
  int v103; // eax
  std::streambuf *v104; // ecx
  int *v105; // edx
  char **v106; // ecx
  char *v107; // eax
  int v108; // eax
  char *v109; // eax
  char *v110; // edi
  int v111; // ebx
  std::streambuf *v112; // ecx
  char **v113; // eax
  int v114; // eax
  std::streambuf *v115; // ecx
  char **v116; // eax
  int v117; // eax
  std::streambuf *v118; // ecx
  char **v119; // eax
  int v120; // eax
  std::streambuf *v121; // ecx
  int *v122; // edx
  char **v123; // ecx
  char *v124; // eax
  int v125; // eax
  char *v126; // eax
  std::string _Grouping; // [esp+0h] [ebp-5Ch] BYREF
  std::string _Groups; // [esp+1Ch] [ebp-40h] BYREF
  const std::numpunct<char> *_Punct_fac; // [esp+38h] [ebp-24h]
  std::locale v130; // [esp+3Ch] [ebp-20h] BYREF
  int _Pten; // [esp+40h] [ebp-1Ch]
  int _Significant; // [esp+44h] [ebp-18h]
  char *_Ptr; // [esp+48h] [ebp-14h]
  char _Kseparator; // [esp+4Eh] [ebp-Eh]
  bool _Bad; // [esp+4Fh] [ebp-Dh]
  int v136; // [esp+58h] [ebp-4h]
  char _Seendigit_3; // [esp+77h] [ebp+1Bh]

  if ( (_Iosbase->_Fmtfl & 0x3000) == 0x3000 )
    return std::num_get<char,std::istreambuf_iterator<char>>::_Getffldx(this, _Ac, _First, _Last, _Iosbase, _Phexexp);
  v7 = std::ios_base::getloc(this: _Iosbase, result: &v130);
  v136 = 0;
  v8 = (std::numpunct<char> *)std::use_facet<std::numpunct<char>>(_Loc: v7);
  _Punct_fac = v8;
  v136 = -1;
  std::locale::~locale(this: &v130);
  std::numpunct<char>::grouping(this: v8, result: &_Grouping);
  v136 = 1;
  _Ptr = _Ac;
  _Bad = false;
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
  {
    v9 = std::istreambuf_iterator<char>::operator*(this: _First);
    v10 = _First;
    if ( v9 == 43 )
    {
      *_Ac = 43;
    }
    else
    {
      if ( std::istreambuf_iterator<char>::operator*(this: _First) != 45 )
        goto LABEL_9;
      *_Ac = 45;
      v10 = _First;
    }
    _Ptr = _Ac + 1;
    std::istreambuf_iterator<char>::operator++(this: v10);
  }
LABEL_9:
  v11 = 0;
  _Seendigit_3 = 0;
  _Significant = 0;
  _Pten = 0;
  Ptr = (std::string *)_Grouping._Bx._Ptr;
  if ( _Grouping._Myres < 0x10 )
    Ptr = &_Grouping;
  if ( Ptr->_Bx._Buf[0] != 127 )
  {
    p_Grouping = (std::string *)_Grouping._Bx._Ptr;
    if ( _Grouping._Myres < 0x10 )
      p_Grouping = &_Grouping;
    if ( p_Grouping->_Bx._Buf[0] > 0 )
    {
      if ( _Grouping._Mysize != 0 )
        _Kseparator = v8->do_thousands_sep(this: v8);
      else
        _Kseparator = 0;
      v14 = 0;
      Myres = 15;
      _Groups._Myres = 15;
      _Groups._Mysize = 1;
      *(_WORD *)_Groups._Bx._Buf = 0;
      LOBYTE(v136) = 2;
      if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) != 0 )
        goto LABEL_56;
      while ( 1 )
      {
        if ( !_First->_Got )
        {
          Strbuf = _First->_Strbuf;
          if ( _First->_Strbuf == nullptr
            || (*(IGnext = Strbuf->_IGnext) == nullptr || *Strbuf->_IGcount <= 0
              ? (v18 = Strbuf->underflow(this: Strbuf))
              : (v18 = (unsigned __int8)**IGnext),
                v18 == -1) )
          {
            _First->_Strbuf = nullptr;
          }
          else
          {
            _First->_Val = v18;
          }
          _First->_Got = true;
        }
        if ( _First->_Val < 48 || std::istreambuf_iterator<char>::operator*(this: _First) > 57 )
        {
          p_Groups = (std::string *)_Groups._Bx._Ptr;
          if ( Myres < 0x10 )
            p_Groups = &_Groups;
          if ( p_Groups->_Bx._Buf[v14] == 0
            || _Kseparator == 0
            || (v24 = std::istreambuf_iterator<char>::operator*(this: _First)) != _Kseparator )
          {
LABEL_50:
            if ( v14 != 0 )
            {
              v25 = (std::string *)_Groups._Bx._Ptr;
              if ( Myres < 0x10 )
                v25 = &_Groups;
              if ( v25->_Bx._Buf[v14] <= 0 )
                _Bad = true;
              else
                ++v14;
            }
LABEL_56:
            v26 = (std::string *)_Grouping._Bx._Ptr;
            if ( _Grouping._Myres < 0x10 )
              v26 = &_Grouping;
            if ( !_Bad )
            {
              while ( v14 != 0 )
              {
                v27 = v26->_Bx._Buf[0];
                if ( v26->_Bx._Buf[0] == 127 )
                  break;
                if ( --v14 != 0 )
                {
                  v28 = (std::string *)_Groups._Bx._Ptr;
                  if ( Myres < 0x10 )
                    v28 = &_Groups;
                  if ( v27 != v28->_Bx._Buf[v14] )
                    goto LABEL_71;
                }
                if ( v14 == 0 )
                {
                  v29 = (std::string *)_Groups._Bx._Ptr;
                  if ( Myres < 0x10 )
                    v29 = &_Groups;
                  if ( v27 < v29->_Bx._Buf[0] )
                  {
LABEL_71:
                    _Bad = true;
                    break;
                  }
                }
                if ( v26->_Bx._Buf[1] > 0 )
                  v26 = (std::string *)((char *)v26 + 1);
              }
            }
            LOBYTE(v136) = 1;
            if ( Myres >= 0x10 )
              operator delete(p: _Groups._Bx._Ptr);
            v11 = _Significant;
            v30 = _Ptr;
            _Groups._Myres = 15;
            _Groups._Mysize = 0;
            _Groups._Bx._Buf[0] = 0;
LABEL_107:
            if ( _Seendigit_3 != 0 )
              goto LABEL_108;
            goto LABEL_110;
          }
          std::string::append(this: &_Groups, _Count: 1u, _Ch: 0);
          ++v14;
        }
        else
        {
          _Seendigit_3 = 1;
          if ( _Significant < 36 )
          {
            if ( std::istreambuf_iterator<char>::operator*(this: _First) != 48 || _Significant != 0 )
            {
              v19 = std::istreambuf_iterator<char>::operator*(this: _First);
              v20 = _Ptr;
              *_Ptr = v19;
              ++_Significant;
              _Ptr = v20 + 1;
            }
          }
          else
          {
            ++_Pten;
          }
          v21 = (std::string *)_Groups._Bx._Ptr;
          if ( Myres < 0x10 )
            v21 = &_Groups;
          if ( v21->_Bx._Buf[v14] == 127 )
            goto LABEL_49;
          v22 = (std::string *)_Groups._Bx._Ptr;
          if ( Myres < 0x10 )
            v22 = &_Groups;
          ++v22->_Bx._Buf[v14];
        }
        Myres = _Groups._Myres;
LABEL_49:
        std::istreambuf_iterator<char>::operator++(this: _First);
        if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) != 0 )
          goto LABEL_50;
      }
    }
  }
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
  {
    v30 = _Ptr;
    do
    {
      if ( !_First->_Got )
      {
        v31 = _First->_Strbuf;
        if ( _First->_Strbuf == nullptr
          || (*(v32 = v31->_IGnext) == nullptr || *v31->_IGcount <= 0
            ? (v33 = v31->underflow(this: v31))
            : (v33 = (unsigned __int8)**v32),
              v33 == -1) )
        {
          _First->_Strbuf = nullptr;
        }
        else
        {
          _First->_Val = v33;
        }
        _First->_Got = true;
      }
      if ( _First->_Val < 48 )
        goto LABEL_106;
      if ( !_First->_Got )
      {
        v34 = _First->_Strbuf;
        if ( _First->_Strbuf == nullptr
          || (*(v35 = v34->_IGnext) == nullptr || *v34->_IGcount <= 0
            ? (v36 = v34->underflow(this: v34))
            : (v36 = (unsigned __int8)**v35),
              v36 == -1) )
        {
          _First->_Strbuf = nullptr;
        }
        else
        {
          _First->_Val = v36;
        }
        _First->_Got = true;
      }
      if ( _First->_Val > 57 )
      {
LABEL_106:
        _Ptr = v30;
        _Significant = v11;
        goto LABEL_107;
      }
      if ( v11 < 36 )
      {
        if ( std::istreambuf_iterator<char>::operator*(this: _First) != 48 || v11 != 0 )
        {
          *v30++ = std::istreambuf_iterator<char>::operator*(this: _First);
          ++v11;
        }
      }
      else
      {
        ++_Pten;
      }
      _Seendigit_3 = 1;
      std::istreambuf_iterator<char>::operator++(this: _First);
    }
    while ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 );
    _Significant = v11;
    _Ptr = v30;
LABEL_108:
    if ( v11 == 0 )
    {
      *v30 = 48;
      _Ptr = v30 + 1;
    }
  }
LABEL_110:
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
  {
    if ( !_First->_Got )
    {
      v37 = _First->_Strbuf;
      if ( _First->_Strbuf == nullptr
        || (*(v38 = v37->_IGnext) == nullptr || *v37->_IGcount <= 0
          ? (v39 = v37->underflow(this: v37))
          : (v39 = (unsigned __int8)**v38),
            v39 == -1) )
      {
        _First->_Strbuf = nullptr;
      }
      else
      {
        _First->_Val = v39;
      }
      _First->_Got = true;
    }
    Val = _First->_Val;
    if ( Val == (unsigned __int8)_Punct_fac->do_decimal_point(this: (std::numpunct<char> *)_Punct_fac) )
    {
      v41 = *localeconv()->decimal_point;
      v42 = _Ptr;
      *_Ptr = v41;
      v43 = _First->_Strbuf;
      _Ptr = v42 + 1;
      if ( v43 == nullptr
        || (*v43->_IGnext == nullptr || *(IGcount = v43->_IGcount) <= 0
          ? (v47 = v43->uflow(this: v43))
          : (--*IGcount, v45 = v43->_IGnext, v46 = *v45, ++*v45, v47 = (unsigned __int8)*v46),
            v47 == -1) )
      {
        _First->_Strbuf = nullptr;
        _First->_Got = true;
      }
      else
      {
        _First->_Got = false;
      }
    }
  }
  if ( _Significant == 0 )
  {
    if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
    {
      v48 = _Pten;
      do
      {
        if ( !_First->_Got )
        {
          v49 = _First->_Strbuf;
          if ( _First->_Strbuf == nullptr
            || (*(v50 = v49->_IGnext) == nullptr || *v49->_IGcount <= 0
              ? (v51 = v49->underflow(this: v49))
              : (v51 = (unsigned __int8)**v50),
                v51 == -1) )
          {
            _First->_Strbuf = nullptr;
          }
          else
          {
            _First->_Val = v51;
          }
          _First->_Got = true;
        }
        if ( _First->_Val != 48 )
          break;
        v52 = _First->_Strbuf;
        --v48;
        _Seendigit_3 = 1;
        if ( _First->_Strbuf == nullptr
          || (*v52->_IGnext == nullptr || *(v53 = v52->_IGcount) <= 0
            ? (v56 = v52->uflow(this: v52))
            : (--*v53, v54 = v52->_IGnext, v55 = *v54, ++*v54, v56 = (unsigned __int8)*v55),
              v56 == -1) )
        {
          _First->_Strbuf = nullptr;
          _First->_Got = true;
        }
        else
        {
          _First->_Got = false;
        }
      }
      while ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 );
      _Pten = v48;
    }
    if ( _Pten < 0 )
    {
      v57 = _Ptr;
      *_Ptr = 48;
      ++_Pten;
      _Ptr = v57 + 1;
    }
  }
  if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
  {
    v58 = _Significant;
    while ( 1 )
    {
      if ( !_First->_Got )
      {
        v59 = _First->_Strbuf;
        if ( _First->_Strbuf == nullptr
          || (*(v60 = v59->_IGnext) == nullptr || *v59->_IGcount <= 0
            ? (v61 = v59->underflow(this: v59))
            : (v61 = (unsigned __int8)**v60),
              v61 == -1) )
        {
          _First->_Strbuf = nullptr;
        }
        else
        {
          _First->_Val = v61;
        }
        _First->_Got = true;
      }
      if ( _First->_Val < 48 )
        break;
      if ( !_First->_Got )
      {
        v62 = _First->_Strbuf;
        if ( _First->_Strbuf == nullptr
          || (*(v63 = v62->_IGnext) == nullptr || *v62->_IGcount <= 0
            ? (v64 = v62->underflow(this: v62))
            : (v64 = (unsigned __int8)**v63),
              v64 == -1) )
        {
          _First->_Strbuf = nullptr;
        }
        else
        {
          _First->_Val = v64;
        }
        _First->_Got = true;
      }
      if ( _First->_Val > 57 )
        break;
      if ( v58 < 36 )
      {
        if ( !_First->_Got )
        {
          v65 = _First->_Strbuf;
          if ( _First->_Strbuf == nullptr
            || (*(v66 = v65->_IGnext) == nullptr || *v65->_IGcount <= 0
              ? (v67 = v65->underflow(this: v65))
              : (v67 = (unsigned __int8)**v66),
                v67 == -1) )
          {
            _First->_Strbuf = nullptr;
          }
          else
          {
            _First->_Val = v67;
          }
          _First->_Got = true;
        }
        v68 = _Ptr;
        *_Ptr = _First->_Val;
        _Ptr = v68 + 1;
        ++v58;
      }
      v69 = _First->_Strbuf;
      _Seendigit_3 = 1;
      if ( _First->_Strbuf == nullptr
        || (*v69->_IGnext == nullptr || *(v70 = v69->_IGcount) <= 0
          ? (v73 = v69->uflow(this: v69))
          : (--*v70, v71 = v69->_IGnext, v72 = *v71, ++*v71, v73 = (unsigned __int8)*v72),
            v73 == -1) )
      {
        _First->_Strbuf = nullptr;
        _First->_Got = true;
      }
      else
      {
        _First->_Got = false;
      }
      if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) != 0 )
        goto LABEL_203;
    }
  }
  if ( _Seendigit_3 != 0 )
  {
LABEL_203:
    if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
    {
      if ( !_First->_Got )
      {
        v74 = _First->_Strbuf;
        if ( _First->_Strbuf == nullptr
          || (*(v75 = v74->_IGnext) == nullptr || *v74->_IGcount <= 0
            ? (v76 = v74->underflow(this: v74))
            : (v76 = (unsigned __int8)**v75),
              v76 == -1) )
        {
          _First->_Strbuf = nullptr;
        }
        else
        {
          _First->_Val = v76;
        }
        _First->_Got = true;
      }
      if ( _First->_Val == 101 )
        goto LABEL_226;
      if ( !_First->_Got )
      {
        v77 = _First->_Strbuf;
        if ( _First->_Strbuf == nullptr
          || (*(v78 = v77->_IGnext) == nullptr || *v77->_IGcount <= 0
            ? (v79 = v77->underflow(this: v77))
            : (v79 = (unsigned __int8)**v78),
              v79 == -1) )
        {
          _First->_Strbuf = nullptr;
        }
        else
        {
          _First->_Val = v79;
        }
        _First->_Got = true;
      }
      if ( _First->_Val == 69 )
      {
LABEL_226:
        v80 = _Ptr;
        *_Ptr = 101;
        v81 = _First->_Strbuf;
        v82 = v80 + 1;
        _Ptr = v82;
        if ( v81 == nullptr
          || (*v81->_IGnext == nullptr || *(v83 = v81->_IGcount) <= 0
            ? (v86 = v81->uflow(this: v81))
            : (--*v83, v84 = v81->_IGnext, v85 = *v84, ++*v84, v86 = (unsigned __int8)*v85),
              v86 == -1) )
        {
          _First->_Strbuf = nullptr;
          _First->_Got = true;
        }
        else
        {
          _First->_Got = false;
        }
        _Seendigit_3 = 0;
        _Significant = 0;
        if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) != 0 )
          goto LABEL_269;
        if ( !_First->_Got )
        {
          v87 = _First->_Strbuf;
          if ( _First->_Strbuf == nullptr
            || (*(v88 = v87->_IGnext) == nullptr || *v87->_IGcount <= 0
              ? (v89 = v87->underflow(this: v87))
              : (v89 = (unsigned __int8)**v88),
                v89 == -1) )
          {
            _First->_Strbuf = nullptr;
          }
          else
          {
            _First->_Val = v89;
          }
          _First->_Got = true;
        }
        if ( _First->_Val == 43 )
        {
          *v82 = 43;
          v90 = _First->_Strbuf;
          _Ptr = v82 + 1;
          if ( v90 == nullptr )
            goto LABEL_268;
          if ( *v90->_IGnext != nullptr )
          {
            v91 = v90->_IGcount;
            if ( *v91 > 0 )
            {
              --*v91;
              v92 = v90->_IGnext;
              v93 = (*v92)++;
              v94 = (unsigned __int8)*v93;
              goto LABEL_266;
            }
          }
        }
        else
        {
          if ( !_First->_Got )
          {
            v95 = _First->_Strbuf;
            if ( _First->_Strbuf == nullptr
              || (*(v96 = v95->_IGnext) == nullptr || *v95->_IGcount <= 0
                ? (v97 = v95->underflow(this: v95))
                : (v97 = (unsigned __int8)**v96),
                  v97 == -1) )
            {
              _First->_Strbuf = nullptr;
            }
            else
            {
              _First->_Val = v97;
            }
            _First->_Got = true;
          }
          if ( _First->_Val != 45 )
            goto LABEL_269;
          *v82 = 45;
          v90 = _First->_Strbuf;
          _Ptr = v82 + 1;
          if ( v90 == nullptr )
            goto LABEL_268;
          if ( *v90->_IGnext != nullptr )
          {
            v98 = v90->_IGcount;
            if ( *v98 > 0 )
            {
              --*v98;
              v99 = v90->_IGnext;
              v100 = (*v99)++;
              v94 = (unsigned __int8)*v100;
              goto LABEL_266;
            }
          }
        }
        v94 = v90->uflow(this: v90);
LABEL_266:
        if ( v94 != -1 )
        {
          _First->_Got = false;
LABEL_269:
          if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
          {
            while ( 1 )
            {
              if ( !_First->_Got )
              {
                v101 = _First->_Strbuf;
                if ( _First->_Strbuf == nullptr
                  || (*(v102 = v101->_IGnext) == nullptr || *v101->_IGcount <= 0
                    ? (v103 = v101->underflow(this: v101))
                    : (v103 = (unsigned __int8)**v102),
                      v103 == -1) )
                {
                  _First->_Strbuf = nullptr;
                }
                else
                {
                  _First->_Val = v103;
                }
                _First->_Got = true;
              }
              if ( _First->_Val != 48 )
                break;
              v104 = _First->_Strbuf;
              _Seendigit_3 = 1;
              if ( _First->_Strbuf == nullptr
                || (*v104->_IGnext == nullptr || *(v105 = v104->_IGcount) <= 0
                  ? (v108 = v104->uflow(this: v104))
                  : (--*v105, v106 = v104->_IGnext, v107 = *v106, ++*v106, v108 = (unsigned __int8)*v107),
                    v108 == -1) )
              {
                _First->_Strbuf = nullptr;
                _First->_Got = true;
              }
              else
              {
                _First->_Got = false;
              }
              if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) != 0 )
                goto LABEL_292;
            }
            if ( _Seendigit_3 == 0 )
              goto LABEL_293;
LABEL_292:
            v109 = _Ptr;
            *_Ptr = 48;
            _Ptr = v109 + 1;
          }
LABEL_293:
          if ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 )
          {
            v110 = _Ptr;
            v111 = _Significant;
            do
            {
              if ( !_First->_Got )
              {
                v112 = _First->_Strbuf;
                if ( _First->_Strbuf == nullptr
                  || (*(v113 = v112->_IGnext) == nullptr || *v112->_IGcount <= 0
                    ? (v114 = v112->underflow(this: v112))
                    : (v114 = (unsigned __int8)**v113),
                      v114 == -1) )
                {
                  _First->_Strbuf = nullptr;
                }
                else
                {
                  _First->_Val = v114;
                }
                _First->_Got = true;
              }
              if ( _First->_Val < 48 )
                break;
              if ( !_First->_Got )
              {
                v115 = _First->_Strbuf;
                if ( _First->_Strbuf == nullptr
                  || (*(v116 = v115->_IGnext) == nullptr || *v115->_IGcount <= 0
                    ? (v117 = v115->underflow(this: v115))
                    : (v117 = (unsigned __int8)**v116),
                      v117 == -1) )
                {
                  _First->_Strbuf = nullptr;
                }
                else
                {
                  _First->_Val = v117;
                }
                _First->_Got = true;
              }
              if ( _First->_Val > 57 )
                break;
              if ( v111 < 8 )
              {
                if ( !_First->_Got )
                {
                  v118 = _First->_Strbuf;
                  if ( _First->_Strbuf == nullptr
                    || (*(v119 = v118->_IGnext) == nullptr || *v118->_IGcount <= 0
                      ? (v120 = v118->underflow(this: v118))
                      : (v120 = (unsigned __int8)**v119),
                        v120 == -1) )
                  {
                    _First->_Strbuf = nullptr;
                  }
                  else
                  {
                    _First->_Val = v120;
                  }
                  _First->_Got = true;
                }
                *v110++ = _First->_Val;
                ++v111;
              }
              v121 = _First->_Strbuf;
              _Seendigit_3 = 1;
              if ( _First->_Strbuf == nullptr
                || (*v121->_IGnext == nullptr || *(v122 = v121->_IGcount) <= 0
                  ? (v125 = v121->uflow(this: v121))
                  : (--*v122, v123 = v121->_IGnext, v124 = *v123, ++*v123, v125 = (unsigned __int8)*v124),
                    v125 == -1) )
              {
                _First->_Strbuf = nullptr;
                _First->_Got = true;
              }
              else
              {
                _First->_Got = false;
              }
            }
            while ( (unsigned __int8)std::istreambuf_iterator<char>::equal(this: _First, _Right: _Last) == 0 );
            _Ptr = v110;
          }
          goto LABEL_339;
        }
LABEL_268:
        _First->_Got = true;
        _First->_Strbuf = nullptr;
        goto LABEL_269;
      }
    }
  }
LABEL_339:
  if ( !_Bad && _Seendigit_3 != 0 )
    v126 = _Ptr;
  else
    v126 = _Ac;
  *v126 = 0;
  v136 = -1;
  if ( _Grouping._Myres >= 0x10 )
    operator delete(p: _Grouping._Bx._Ptr);
  return _Pten;
}

//------------------------------------------------------------------------------
// Address: 0x1011FE80
// Name: public: class CMapDisp __near * CMapDisp::CopyFrom(class CMapDisp __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapDisp *__thiscall CMapDisp::CopyFrom(CMapDisp *this, CMapDisp *pMapDisp, bool bUpdateDependencies)
{
  CMapDisp *ebx1; // ebx
  int m_PointCount; // ecx
  int v7; // eax
  float *p_z; // eax
  float *p_y; // ebx
  float *v10; // edx
  float *v11; // ecx
  int v12; // xmm1_4
  int v13; // xmm2_4
  int v14; // xmm1_4
  int v15; // xmm2_4
  int v16; // xmm1_4
  int v17; // xmm1_4
  int v18; // xmm1_4
  int v19; // xmm2_4
  int v20; // xmm1_4
  int v21; // xmm2_4
  int v22; // xmm1_4
  int v23; // xmm1_4
  int v24; // xmm1_4
  int v25; // xmm2_4
  int v26; // xmm1_4
  int v27; // xmm2_4
  int v28; // xmm1_4
  int v29; // xmm1_4
  int v30; // xmm1_4
  int v31; // xmm2_4
  int v32; // xmm1_4
  int v33; // xmm2_4
  int v34; // xmm1_4
  int v35; // xmm1_4
  float *v36; // ecx
  CCoreDispSurface *v37; // eax
  float *v38; // edx
  float y; // xmm0_4
  float z; // xmm1_4
  float x; // xmm1_4
  float v42; // xmm2_4
  int v43; // xmm1_4
  int v44; // xmm1_4
  bool v45; // zf
  int m_Power; // ecx
  int v47; // esi
  CoreDispVert_t *m_pVerts; // eax
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  CoreDispVert_t *v52; // eax
  CoreDispVert_t *v53; // edx
  float v54; // xmm1_4
  float v55; // xmm2_4
  CoreDispVert_t *v56; // eax
  CoreDispVert_t *v57; // ecx
  float v58; // xmm1_4
  float v59; // xmm2_4
  CoreDispVert_t *v60; // edx
  CoreDispVert_t *v61; // edx
  float v62; // xmm1_4
  float v63; // xmm2_4
  CoreDispVert_t *v64; // eax
  CoreDispVert_t *v65; // ecx
  float v66; // xmm1_4
  float v67; // xmm2_4
  Vector *p_m_FlatVert; // eax
  int m_RenderIndexCount; // ecx
  int v70; // eax
  int v71; // esi
  CMapAtom *v72; // eax
  int v73; // eax
  Vector4D vBlend; // [esp+8h] [ebp-6Ch] BYREF
  Vector4D vAlphaBlend; // [esp+18h] [ebp-5Ch] BYREF
  Vector vColor1; // [esp+28h] [ebp-4Ch] BYREF
  Vector vColor2; // [esp+34h] [ebp-40h] BYREF
  Vector vColor3; // [esp+40h] [ebp-34h] BYREF
  Vector vColor4; // [esp+4Ch] [ebp-28h] BYREF
  unsigned __int16 v1[2]; // [esp+58h] [ebp-1Ch] BYREF
  unsigned __int16 v3[2]; // [esp+5Ch] [ebp-18h] BYREF
  unsigned int v82; // [esp+60h] [ebp-14h]
  int v83; // [esp+64h] [ebp-10h]
  char *v84; // [esp+68h] [ebp-Ch]
  int i; // [esp+6Ch] [ebp-8h]
  int pointCount; // [esp+70h] [ebp-4h]
  float *nTriCount; // [esp+7Ch] [ebp+8h]
  int nTriCounta; // [esp+7Ch] [ebp+8h]
  int nTriCountb; // [esp+7Ch] [ebp+8h]

  ebx1 = pMapDisp;
  if ( pMapDisp == nullptr )
    return nullptr;
  m_PointCount = pMapDisp->m_CoreDispInfo.m_Surf.m_PointCount;
  pointCount = m_PointCount;
  if ( m_PointCount == 4 )
    this->m_CoreDispInfo.m_Surf.m_PointCount = 4;
  v7 = 0;
  i = 0;
  if ( m_PointCount >= 4 )
  {
    v84 = (char *)((char *)this - (char *)pMapDisp);
    *(_DWORD *)v3 = &pMapDisp->m_CoreDispInfo.m_Surf.m_TexCoords[1].y;
    p_z = &pMapDisp->m_CoreDispInfo.m_Surf.m_Points[0].z;
    p_y = &pMapDisp->m_CoreDispInfo.m_Surf.m_TexCoords[1].y;
    v83 = (char *)pMapDisp - (char *)this;
    v82 = ((unsigned int)(pointCount - 4) >> 2) + 1;
    v10 = &this->m_CoreDispInfo.m_Surf.m_TexCoords[0].y;
    v11 = &this->m_CoreDispInfo.m_Surf.m_Normals[0].y;
    i = 4 * v82;
    do
    {
      v12 = *((_DWORD *)p_z - 1);
      v13 = *(_DWORD *)p_z;
      *(v11 - 13) = *(p_z - 2);
      *((_DWORD *)v11 - 12) = v12;
      *(_DWORD *)((char *)p_z + (_DWORD)v84) = v13;
      v14 = *((_DWORD *)p_z + 11);
      v15 = *((_DWORD *)p_z + 12);
      *(v11 - 1) = p_z[10];
      *(_DWORD *)v11 = v14;
      *((_DWORD *)v11 + 1) = v15;
      v16 = *(_DWORD *)((char *)v10 + v83);
      *(v10 - 1) = *(p_y - 3);
      *(_DWORD *)v10 = v16;
      v17 = *((_DWORD *)p_y + 6);
      v10[7] = p_y[5];
      *((_DWORD *)v10 + 8) = v17;
      v18 = *((_DWORD *)p_z + 2);
      v19 = *((_DWORD *)p_z + 3);
      *(v11 - 10) = p_z[1];
      *((_DWORD *)v11 - 9) = v18;
      *((_DWORD *)v11 - 8) = v19;
      v20 = *((_DWORD *)p_z + 14);
      v21 = *((_DWORD *)p_z + 15);
      v11[2] = p_z[13];
      *((_DWORD *)v11 + 3) = v20;
      *((_DWORD *)v11 + 4) = v21;
      v22 = *(_DWORD *)p_y;
      v10[1] = *(p_y - 1);
      *((_DWORD *)v10 + 2) = v22;
      v23 = *((_DWORD *)p_y + 8);
      v10[9] = p_y[7];
      *((_DWORD *)v10 + 10) = v23;
      v24 = *((_DWORD *)p_z + 5);
      v25 = *((_DWORD *)p_z + 6);
      *(v11 - 7) = p_z[4];
      *((_DWORD *)v11 - 6) = v24;
      *((_DWORD *)v11 - 5) = v25;
      v26 = *((_DWORD *)p_z + 17);
      v27 = *((_DWORD *)p_z + 18);
      v11[5] = p_z[16];
      *((_DWORD *)v11 + 6) = v26;
      *((_DWORD *)v11 + 7) = v27;
      v28 = *((_DWORD *)p_y + 2);
      v10[3] = p_y[1];
      *((_DWORD *)v10 + 4) = v28;
      v29 = *((_DWORD *)p_y + 10);
      v10[11] = p_y[9];
      *((_DWORD *)v10 + 12) = v29;
      v30 = *((_DWORD *)p_z + 8);
      v31 = *((_DWORD *)p_z + 9);
      *(v11 - 4) = p_z[7];
      *((_DWORD *)v11 - 3) = v30;
      *((_DWORD *)v11 - 2) = v31;
      v32 = *((_DWORD *)p_z + 20);
      v33 = *((_DWORD *)p_z + 21);
      v11[8] = p_z[19];
      *((_DWORD *)v11 + 9) = v32;
      *((_DWORD *)v11 + 10) = v33;
      v34 = *((_DWORD *)p_y + 4);
      v10[5] = p_y[3];
      *((_DWORD *)v10 + 6) = v34;
      v35 = *((_DWORD *)p_y + 12);
      v10[13] = p_y[11];
      *((_DWORD *)v10 + 14) = v35;
      v10 += 8;
      p_y += 8;
      p_z += 12;
      v11 += 12;
      --v82;
    }
    while ( v82 != 0 );
    ebx1 = pMapDisp;
    v7 = i;
    m_PointCount = pointCount;
  }
  if ( v7 < m_PointCount )
  {
    *(_DWORD *)v3 = &this->m_CoreDispInfo.m_Surf.m_Normals[v7].y;
    nTriCount = &ebx1->m_CoreDispInfo.m_Surf.m_TexCoords[v7].x;
    v36 = &this->m_CoreDispInfo.m_Surf.m_TexCoords[v7].y;
    v37 = (CCoreDispSurface *)&ebx1->m_CoreDispInfo.m_Surf.m_Points[v7].z;
    v84 = (char *)((char *)this - (char *)ebx1);
    v83 = (char *)ebx1 - (char *)this;
    v82 = pointCount - i;
    v38 = *(float **)v3;
    do
    {
      y = v37[-1].m_PointStart.y;
      z = v37[-1].m_PointStart.z;
      *(_DWORD *)&v84[(_DWORD)v37] = v37->m_Index;
      *(v38 - 13) = y;
      *(v38 - 12) = z;
      x = v37->m_Points[3].x;
      v42 = v37->m_Points[3].y;
      *(v38 - 1) = v37->m_Points[2].z;
      *v38 = x;
      v38[1] = v42;
      v43 = *(_DWORD *)((char *)v36 + v83);
      *(v36 - 1) = *nTriCount;
      *(_DWORD *)v36 = v43;
      v44 = *((_DWORD *)nTriCount + 9);
      v36[7] = nTriCount[8];
      *((_DWORD *)v36 + 8) = v44;
      v36 += 2;
      v37 = (CCoreDispSurface *)((char *)v37 + 12);
      v38 += 3;
      v45 = v82-- == 1;
      nTriCount += 2;
    }
    while ( !v45 );
  }
  this->m_CoreDispInfo.m_Surf.m_Flags = ebx1->m_CoreDispInfo.m_Surf.m_Flags;
  this->m_CoreDispInfo.m_Surf.m_Contents = ebx1->m_CoreDispInfo.m_Surf.m_Contents;
  this->m_CoreDispInfo.m_Surf.m_PointStartIndex = ebx1->m_CoreDispInfo.m_Surf.m_PointStartIndex;
  m_Power = ebx1->m_CoreDispInfo.m_Power;
  this->m_CoreDispInfo.m_Power = m_Power;
  this->m_CoreDispInfo.m_Elevation = ebx1->m_CoreDispInfo.m_Elevation;
  v47 = 0;
  nTriCounta = 0;
  this->m_Scale = ebx1->m_Scale;
  for ( *(_DWORD *)v3 = ((1 << m_Power) + 1) * ((1 << m_Power) + 1); nTriCounta < *(int *)v3; ++nTriCounta )
  {
    m_pVerts = ebx1->m_CoreDispInfo.m_pVerts;
    v49 = m_pVerts[v47].m_FieldVector.x;
    v50 = m_pVerts[v47].m_FieldVector.y;
    v51 = m_pVerts[v47].m_FieldVector.z;
    v52 = this->m_CoreDispInfo.m_pVerts;
    v52[v47].m_FieldVector.x = v49;
    v52[v47].m_FieldVector.y = v50;
    v52[v47].m_FieldVector.z = v51;
    v53 = ebx1->m_CoreDispInfo.m_pVerts;
    v54 = v53[v47].m_SubdivPos.y;
    v55 = v53[v47].m_SubdivPos.z;
    v56 = this->m_CoreDispInfo.m_pVerts;
    v56[v47].m_SubdivPos.x = v53[v47].m_SubdivPos.x;
    v56[v47].m_SubdivPos.y = v54;
    v56[v47].m_SubdivPos.z = v55;
    v57 = ebx1->m_CoreDispInfo.m_pVerts;
    v58 = v57[v47].m_SubdivNormal.y;
    v59 = v57[v47].m_SubdivNormal.z;
    v60 = this->m_CoreDispInfo.m_pVerts;
    v60[v47].m_SubdivNormal.x = v57[v47].m_SubdivNormal.x;
    v60[v47].m_SubdivNormal.y = v58;
    v60[v47].m_SubdivNormal.z = v59;
    this->m_CoreDispInfo.m_pVerts[v47].m_FieldDistance = ebx1->m_CoreDispInfo.m_pVerts[v47].m_FieldDistance;
    v61 = ebx1->m_CoreDispInfo.m_pVerts;
    v62 = v61[v47].m_Vert.y;
    v63 = v61[v47].m_Vert.z;
    v64 = this->m_CoreDispInfo.m_pVerts;
    v64[v47].m_Vert.x = v61[v47].m_Vert.x;
    v64[v47].m_Vert.y = v62;
    v64[v47].m_Vert.z = v63;
    v65 = ebx1->m_CoreDispInfo.m_pVerts;
    v66 = v65[v47].m_FlatVert.y;
    v67 = v65[v47].m_FlatVert.z;
    p_m_FlatVert = &this->m_CoreDispInfo.m_pVerts[v47].m_FlatVert;
    p_m_FlatVert->x = v65[v47].m_FlatVert.x;
    p_m_FlatVert->y = v66;
    p_m_FlatVert->z = v67;
    this->m_CoreDispInfo.m_pVerts[v47].m_Alpha = ebx1->m_CoreDispInfo.m_pVerts[v47].m_Alpha;
    CCoreDispInfo::GetMultiBlend(
      this: &ebx1->m_CoreDispInfo,
      index: nTriCounta,
      &vBlend,
      &vAlphaBlend,
      &vColor1,
      &vColor2,
      &vColor3,
      &vColor4);
    CCoreDispInfo::SetMultiBlend(
      this: &this->m_CoreDispInfo,
      index: nTriCounta,
      &vBlend,
      &vAlphaBlend,
      &vColor1,
      &vColor2,
      &vColor3,
      &vColor4);
    ++v47;
  }
  m_RenderIndexCount = ebx1->m_CoreDispInfo.m_RenderIndexCount;
  v70 = 0;
  for ( this->m_CoreDispInfo.m_RenderIndexCount = m_RenderIndexCount; v70 < m_RenderIndexCount; ++v70 )
    this->m_CoreDispInfo.m_RenderIndices[v70] = ebx1->m_CoreDispInfo.m_RenderIndices[v70];
  v71 = 0;
  nTriCountb = CCoreDispInfo::GetTriCount(this: &this->m_CoreDispInfo);
  if ( nTriCountb > 0 )
  {
    do
    {
      CCoreDispInfo::GetTriIndices(this: &ebx1->m_CoreDispInfo, iTri: v71, v1, v2: &v1[1], v3);
      CCoreDispInfo::SetTriIndices(this: &this->m_CoreDispInfo, iTri: v71, v1: v1[0], v2: v1[1], v3: v3[0]);
      this->m_CoreDispInfo.m_pTris[v71].m_uiTags = ebx1->m_CoreDispInfo.m_pTris[v71].m_uiTags;
      ++v71;
    }
    while ( v71 < nTriCountb );
  }
  this->m_bSubdiv = ebx1->m_bSubdiv;
  this->m_bReSubdiv = ebx1->m_bReSubdiv;
  this->m_HitTexelIndex = -1;
  this->m_HitDispIndex = -1;
  this->m_CoreDispInfo.m_bTouched = false;
  if ( this != (CMapDisp *)-824 )
  {
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[0] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[1] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[2] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[3] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[4] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[5] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[6] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[7] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[8] = -1;
    this->m_CoreDispInfo.m_AllowedVerts.m_Ints[9] = -1;
  }
  if ( bUpdateDependencies )
  {
    if ( CCoreDispInfo::CreateWithoutLOD(this: &this->m_CoreDispInfo) != 0 )
      CMapDisp::PostCreate(this, a2: (int)ebx1, a3: v71);
    v72 = this->GetParent(this);
    if ( v72 != nullptr )
    {
      v73 = (int)v72->GetParent(this: v72);
      if ( v73 != 0 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v73 + 60))(a1: v73, a2: 5);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101204B0
// Name: public: void CMapDisp::Split(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::Split(CMapDisp *this, int hBuilderDisp)
{
  CEditDispMgr *v3; // eax
  int v4; // eax
  CMapDisp *v5; // esi
  int v6; // ebx
  int v7; // ecx
  int v8; // edx
  int v9; // edx
  _DWORD *v10; // eax
  float *p_z; // edi
  CoreDispVert_t *m_pVerts; // eax
  float x; // xmm0_4
  int p_m_Vert; // eax
  float v15; // xmm0_4
  float y; // xmm0_4
  Vector vecNewNormal; // [esp+Ch] [ebp-44h] BYREF
  Vector vecNewVert; // [esp+18h] [ebp-38h] BYREF
  Vector vecVert; // [esp+24h] [ebp-2Ch] BYREF
  Vector2D vecDispUV; // [esp+30h] [ebp-20h] BYREF
  int nVertCount; // [esp+38h] [ebp-18h]
  float flNewAlpha; // [esp+3Ch] [ebp-14h] BYREF
  CCoreDispInfo *p_m_CoreDispInfo; // [esp+40h] [ebp-10h]
  int v24; // [esp+4Ch] [ebp-4h]
  int iVert; // [esp+58h] [ebp+8h]

  v3 = EditDispMgr();
  v4 = (int)v3->GetDisp(this: v3, a2: hBuilderDisp);
  v5 = (CMapDisp *)v4;
  if ( (_S2_6 & 1) == 0 )
  {
    _S2_6 |= 1u;
    v24 = -1;
  }
  vecSurfPoints[0] = this->m_CoreDispInfo.m_Surf.m_Points[0];
  ::v4 = this->m_CoreDispInfo.m_Surf.m_Points[1];
  ::v3 = this->m_CoreDispInfo.m_Surf.m_Points[2];
  v2 = this->m_CoreDispInfo.m_Surf.m_Points[3];
  v6 = 0;
  *(_DWORD *)(v4 + 1216) = 0;
  *(_BYTE *)(v4 + 4977) = 0;
  v7 = 0;
  v8 = (1 << *(_DWORD *)(v4 + 36)) + 1;
  v9 = v8 * v8;
  if ( v9 > 0 )
  {
    v10 = (_DWORD *)(v4 + 1228);
    do
    {
      *(v10 - 2) = 0;
      *(v10 - 1) = 0;
      *v10 = 0;
      v5->m_Canvas.m_bValuesDirty[v7++] = false;
      v10 += 3;
    }
    while ( v7 < v9 );
  }
  iVert = 0;
  nVertCount = ((1 << v5->m_CoreDispInfo.m_Power) + 1) * ((1 << v5->m_CoreDispInfo.m_Power) + 1);
  if ( nVertCount > 0 )
  {
    p_m_CoreDispInfo = &this->m_CoreDispInfo;
    p_z = &v5->m_Canvas.m_Values[0].z;
    do
    {
      m_pVerts = v5->m_CoreDispInfo.m_pVerts;
      x = m_pVerts[v6].m_Vert.x;
      p_m_Vert = (int)&m_pVerts[v6].m_Vert;
      vecVert.x = x;
      vecVert.y = *(float *)(p_m_Vert + 4);
      vecVert.z = *(float *)(p_m_Vert + 8);
      PointInQuadToBarycentric(v1: vecSurfPoints, v2: &v2, v3: &::v3, v4: &::v4, point: &vecVert, uv: &vecDispUV);
      v15 = vecDispUV.x;
      if ( vecDispUV.x >= 0.0 )
      {
        if ( vecDispUV.x > 1.0 )
          v15 = 1.0;
      }
      else
      {
        v15 = 0.0;
      }
      vecDispUV.x = v15;
      y = vecDispUV.y;
      if ( vecDispUV.y >= 0.0 )
      {
        if ( vecDispUV.y > 1.0 )
          y = 1.0;
      }
      else
      {
        y = 0.0;
      }
      vecDispUV.y = y;
      CCoreDispInfo::DispUVToSurf(
        this: p_m_CoreDispInfo,
        dispUV: &vecDispUV,
        vecPoint: &vecNewVert,
        pNormal: &vecNewNormal,
        pAlpha: &flNewAlpha);
      v5->m_CoreDispInfo.m_pVerts[v6].m_Alpha = flNewAlpha;
      *(Vector *)(p_z - 2) = vecNewVert;
      v5->m_Canvas.m_bValuesDirty[iVert] = true;
      ++v6;
      p_z += 3;
      v5->m_Canvas.m_bDirty = true;
      ++iVert;
    }
    while ( iVert < nVertCount );
  }
  CMapDisp::Paint_Update(this: v5, bSplit: true);
}

//------------------------------------------------------------------------------
// Address: 0x10120730
// Name: public: void CMapDisp::ApplyNoise(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::ApplyNoise(CMapDisp *this, float min, float max, float rockiness)
{
  int v5; // ebx
  float v6; // xmm3_4
  float *p_z; // edi
  CoreDispVert_t *m_pVerts; // eax
  double v9; // st7
  float v10; // xmm3_4
  CoreDispVert_t *v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float x; // [esp+18h] [ebp-18h]
  float y; // [esp+1Ch] [ebp-14h]
  float z; // [esp+20h] [ebp-10h]
  int v19; // [esp+24h] [ebp-Ch]
  float v20; // [esp+28h] [ebp-8h]
  float v21; // [esp+2Ch] [ebp-4h]
  int v_8; // [esp+38h] [ebp+8h]
  float size; // [esp+3Ch] [ebp+Ch]

  if ( min == max )
    return;
  v5 = 0;
  CMapDisp::Paint_Init(this, nType: 0);
  v6 = rockiness;
  if ( rockiness < 0.0 )
  {
    v6 = 0.0;
LABEL_6:
    rockiness = v6;
    goto LABEL_7;
  }
  if ( rockiness > 1.0 )
  {
    v6 = 1.0;
    goto LABEL_6;
  }
LABEL_7:
  v21 = (float)(max - min) * 0.5;
  v19 = ((1 << this->m_CoreDispInfo.m_Power) + 1) * ((1 << this->m_CoreDispInfo.m_Power) + 1);
  if ( v19 > 0 )
  {
    v20 = (float)((float)(max - min) * 0.5) + min;
    v_8 = 0;
    p_z = &this->m_Canvas.m_Values[0].z;
    while ( 1 )
    {
      m_pVerts = this->m_CoreDispInfo.m_pVerts;
      y = m_pVerts[v_8].m_Vert.y;
      z = m_pVerts[v_8].m_Vert.z;
      x = m_pVerts[v_8].m_Vert.x;
      v9 = PerlinNoise2D(x: z + x, y: y + z, rockiness: v6);
      if ( v9 >= -1.0 )
      {
        v10 = v9;
        size = v9;
        if ( size > 1.0 )
          v10 = 1.0;
      }
      else
      {
        v10 = -1.0;
      }
      v11 = &this->m_CoreDispInfo.m_pVerts[v_8];
      v12 = v11->m_FieldVector.x;
      v13 = (float)(v10 * v21) + v20;
      v14 = v11->m_FieldVector.y;
      v15 = v11->m_FieldVector.z;
      if ( v11->m_FieldVector.x == 0.0 && v14 == 0.0 && v15 == 0.0 )
      {
        v12 = v11->m_SubdivNormal.x;
        v14 = v11->m_SubdivNormal.y;
        v15 = v11->m_SubdivNormal.z;
      }
      ++v_8;
      *(p_z - 2) = (float)(v12 * v13) + x;
      *(p_z - 1) = (float)(v14 * v13) + y;
      *p_z = (float)(v15 * v13) + z;
      this->m_Canvas.m_bValuesDirty[v5++] = true;
      p_z += 3;
      this->m_Canvas.m_bDirty = true;
      if ( v5 >= v19 )
        break;
      v6 = rockiness;
    }
  }
  CMapDisp::Paint_Update(this, bSplit: false);
}

//------------------------------------------------------------------------------
// Address: 0x10120900
// Name: public: bool CMapDisp::SerializedLoadMAP(class std::basic_fstream<char,struct std::char_traits<char>> __near &,class CMapFace __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapDisp::SerializedLoadMAP(CMapDisp *this, float file, CMapFace *pFace, unsigned int version)
{
  std::fstream *v4; // esi
  int v5; // eax
  char v7; // al
  char v8; // al
  int v9; // eax
  int v10; // eax
  int v11; // ebx
  char v12; // al
  int v13; // ebx
  float v14; // xmm0_4
  char v15; // al
  char v16; // al
  Vector vectorFieldVector; // [esp+0h] [ebp-24h] BYREF
  int size; // [esp+Ch] [ebp-18h]
  int minTess; // [esp+10h] [ebp-14h] BYREF
  float smoothingAngle; // [esp+14h] [ebp-10h] BYREF
  float maxData; // [esp+18h] [ebp-Ch] BYREF
  int i; // [esp+1Ch] [ebp-8h]
  int power; // [esp+20h] [ebp-4h] BYREF

  v4 = (std::fstream *)LODWORD(file);
  v5 = *(_DWORD *)LODWORD(file);
  maxData = 1.0;
  v7 = std::ios::widen(this: (std::ios *)(LODWORD(file) + *(_DWORD *)(v5 + 4)), _Byte: 10);
  std::istream::getline(this: v4, _Str: buf, _Count: 256, _Delim: v7);
  v8 = std::ios::widen(this: (std::ios *)&v4->gap0[*(_DWORD *)(*(_DWORD *)v4->gap0 + 4)], _Byte: 10);
  std::istream::getline(this: v4, _Str: buf, _Count: 256, _Delim: v8);
  if ( version >= 0x15E )
    sscanf(
      string: buf,
      format: "%d [ %f %f %f ] [ %f %f %f ] %d %f",
      &power,
      this->m_MapAxes,
      &this->m_MapAxes[0].y,
      &this->m_MapAxes[0].z,
      &this->m_MapAxes[1],
      &this->m_MapAxes[1].y,
      &this->m_MapAxes[1].z,
      &minTess,
      &smoothingAngle);
  else
    sscanf(
      string: buf,
      format: "%d [ %f %f %f ] [ %f %f %f ] %f %d %f",
      &power,
      this->m_MapAxes,
      &this->m_MapAxes[0].y,
      &this->m_MapAxes[0].z,
      &this->m_MapAxes[1],
      &this->m_MapAxes[1].y,
      &this->m_MapAxes[1].z,
      &maxData,
      &minTess,
      &smoothingAngle);
  v9 = 1 << power;
  this->m_CoreDispInfo.m_Power = power;
  this->m_bHasMappingAxes = true;
  v10 = (v9 + 1) * (v9 + 1);
  size = v10;
  if ( v10 > 0 )
  {
    v11 = 0;
    for ( i = v10; i != 0; --i )
    {
      std::istream::operator>>(this: v4, _Val: &vectorFieldVector.x);
      std::istream::operator>>(this: v4, _Val: &vectorFieldVector.y);
      std::istream::operator>>(this: v4, _Val: &vectorFieldVector.z);
      this->m_CoreDispInfo.m_pVerts[v11++].m_FieldVector = vectorFieldVector;
    }
  }
  v12 = std::ios::widen(this: (std::ios *)&v4->gap0[*(_DWORD *)(*(_DWORD *)v4->gap0 + 4)], _Byte: 10);
  std::istream::getline(this: v4, _Str: buf, _Count: 256, _Delim: v12);
  if ( size > 0 )
  {
    v13 = 0;
    for ( i = size; i != 0; --i )
    {
      if ( version >= 0x15E )
      {
        std::istream::operator>>(this: v4, _Val: &file);
        v14 = file;
      }
      else
      {
        std::istream::operator>>(this: v4, _Val: &file);
        v14 = file * maxData;
        file = file * maxData;
      }
      this->m_CoreDispInfo.m_pVerts[v13++].m_FieldDistance = v14;
    }
  }
  v15 = std::ios::widen(this: (std::ios *)&v4->gap0[*(_DWORD *)(*(_DWORD *)v4->gap0 + 4)], _Byte: 10);
  std::istream::getline(this: v4, _Str: buf, _Count: 256, _Delim: v15);
  v16 = std::ios::widen(this: (std::ios *)&v4->gap0[*(_DWORD *)(*(_DWORD *)v4->gap0 + 4)], _Byte: 10);
  std::istream::getline(this: v4, _Str: buf, _Count: 256, _Delim: v16);
  this->SetParent(this, a2: pFace);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10120B60
// Name: protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char>> std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::ios_base __near &,int __near &,bool __near &)const
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::num_get<char,std::istreambuf_iterator<char>>::do_get(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        std::istreambuf_iterator<char> *result,
        std::istreambuf_iterator<char> _First,
        std::istreambuf_iterator<char> _Last,
        std::ios_base *_Iosbase,
        int *_State,
        bool *_Val)
{
  std::ios_base *v7; // esi
  bool v8; // zf
  std::ios_base *v10; // ecx
  const std::locale *v11; // eax
  std::numpunct<char> *v12; // esi
  const std::string *v13; // eax
  const std::string *v14; // eax
  unsigned int Myres; // esi
  std::string *Ptr; // eax
  int v17; // edi
  const std::locale *v18; // eax
  int v19; // eax
  unsigned int v20; // esi
  int *v21; // eax
  std::streambuf *Strbuf; // edx
  char _Ac[32]; // [esp+Ch] [ebp-54h] BYREF
  std::string _Str; // [esp+2Ch] [ebp-34h] BYREF
  char *_Ep; // [esp+48h] [ebp-18h] BYREF
  std::locale v27; // [esp+4Ch] [ebp-14h] BYREF
  int _Ans; // [esp+50h] [ebp-10h]
  int v29; // [esp+5Ch] [ebp-4h]

  v7 = _Iosbase;
  v8 = (_Iosbase->_Fmtfl & 0x4000) == 0;
  _Ans = -1;
  v10 = _Iosbase;
  if ( v8 )
  {
    _Iosbase = nullptr;
    v18 = std::ios_base::getloc(this: v10, result: &v27);
    v29 = 4;
    v19 = std::num_get<char,std::istreambuf_iterator<char>>::_Getifld(
            this,
            _Ac,
            &_First,
            &_Last,
            _Basefield: v7->_Fmtfl,
            _Loc: v18);
    v20 = _Stoulx(s: _Ac, endptr: &_Ep, base: v19, perr: (int *)&_Iosbase);
    v29 = -1;
    std::locale::~locale(this: &v27);
    if ( _Ep == _Ac || _Iosbase != nullptr || (v17 = v20, v20 > 1) )
      v17 = _Ans;
  }
  else
  {
    v11 = std::ios_base::getloc(this: _Iosbase, result: (std::locale *)&_Iosbase);
    v12 = (std::numpunct<char> *)std::use_facet<std::numpunct<char>>(_Loc: v11);
    std::locale::~locale(this: (std::locale *)&_Iosbase);
    _Str._Myres = 15;
    _Str._Mysize = 1;
    *(_WORD *)_Str._Bx._Buf = 0;
    v29 = 1;
    v13 = std::numpunct<char>::falsename(this: v12, result: (std::string *)&_Ac[4]);
    LOBYTE(v29) = 2;
    std::string::append(this: &_Str, _Right: v13, _Roff: 0, _Count: 0xFFFFFFFF);
    LOBYTE(v29) = 1;
    if ( *(_DWORD *)&_Ac[24] >= 0x10u )
      operator delete(p: *(void **)&_Ac[4]);
    *(_DWORD *)&_Ac[24] = 15;
    *(_DWORD *)&_Ac[20] = 0;
    _Ac[4] = 0;
    std::string::append(this: &_Str, _Count: 1u, _Ch: 0);
    v14 = std::numpunct<char>::truename(this: v12, result: (std::string *)&_Ac[4]);
    LOBYTE(v29) = 3;
    std::string::append(this: &_Str, _Right: v14, _Roff: 0, _Count: 0xFFFFFFFF);
    LOBYTE(v29) = 1;
    if ( *(_DWORD *)&_Ac[24] >= 0x10u )
      operator delete(p: *(void **)&_Ac[4]);
    Myres = _Str._Myres;
    Ptr = (std::string *)_Str._Bx._Ptr;
    *(_DWORD *)&_Ac[24] = 15;
    *(_DWORD *)&_Ac[20] = 0;
    _Ac[4] = 0;
    if ( _Str._Myres < 0x10 )
      Ptr = &_Str;
    v17 = std::_Getloctxt<char,std::istreambuf_iterator<char>>(&_First, &_Last, _Numfields: 2u, _Ptr: Ptr->_Bx._Buf);
    v29 = -1;
    if ( Myres >= 0x10 )
      operator delete(p: _Str._Bx._Ptr);
    _Str._Myres = 15;
    _Str._Mysize = 0;
    _Str._Bx._Buf[0] = 0;
  }
  v8 = (unsigned __int8)std::istreambuf_iterator<char>::equal(this: &_First, _Right: &_Last) == 0;
  v21 = _State;
  if ( !v8 )
    *_State |= 1u;
  if ( v17 >= 0 )
    *_Val = v17 != 0;
  else
    *v21 |= 2u;
  Strbuf = _First._Strbuf;
  *(_DWORD *)&result->_Got = *(_DWORD *)&_First._Got;
  result->_Strbuf = Strbuf;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10120D60
// Name: protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char>> std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::ios_base __near &,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::num_get<char,std::istreambuf_iterator<char>>::do_get(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        std::istreambuf_iterator<char> *result,
        std::istreambuf_iterator<char> _First,
        std::istreambuf_iterator<char> _Last,
        float _Iosbase,
        int *_State,
        float *_Val)
{
  int v7; // eax
  bool v8; // zf
  int *v9; // eax
  std::streambuf *Strbuf; // ecx
  int v12; // edx
  int v13; // edx
  long double x; // [esp+0h] [ebp-48h] BYREF
  char _Ac[60]; // [esp+Ch] [ebp-3Ch] BYREF

  *(_DWORD *)&_Ac[52] = 0;
  *(_DWORD *)&_Ac[56] = 0;
  v7 = std::num_get<char,std::istreambuf_iterator<char>>::_Getffld(
         this,
         _Ac: (char *)&x,
         &_First,
         &_Last,
         _Iosbase: (std::ios_base *)LODWORD(_Iosbase),
         _Phexexp: (int *)&_Ac[56]);
  _Iosbase = _Stofx(s: (const char *)&x, endptr: (char **)&_Ac[48], pten: v7, perr: (int *)&_Ac[52]);
  if ( *(_DWORD *)&_Ac[56] != 0 )
    _Iosbase = ldexp(x: _Iosbase, exp: 4 * *(_DWORD *)&_Ac[56]);
  v8 = (unsigned __int8)std::istreambuf_iterator<char>::equal(this: &_First, _Right: &_Last) == 0;
  v9 = _State;
  if ( !v8 )
    *_State |= 1u;
  if ( *(long double **)&_Ac[48] == &x || *(_DWORD *)&_Ac[52] != 0 )
  {
    *v9 |= 2u;
    v13 = *(_DWORD *)&_First._Got;
    result->_Strbuf = _First._Strbuf;
    *(_DWORD *)&result->_Got = v13;
    return result;
  }
  else
  {
    Strbuf = _First._Strbuf;
    *_Val = _Iosbase;
    v12 = *(_DWORD *)&_First._Got;
    result->_Strbuf = Strbuf;
    *(_DWORD *)&result->_Got = v12;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120E30
// Name: protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char>> std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::ios_base __near &,int __near &,double __near &)const
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::num_get<char,std::istreambuf_iterator<char>>::do_get(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        std::istreambuf_iterator<char> *result,
        std::istreambuf_iterator<char> _First,
        std::istreambuf_iterator<char> _Last,
        std::ios_base *_Iosbase,
        int *_State,
        long double *_Val)
{
  int v7; // eax
  bool v8; // zf
  int *v9; // eax
  std::streambuf *Strbuf; // ecx
  int v12; // edx
  int v13; // edx
  long double x; // [esp+0h] [ebp-4Ch] BYREF
  char _Ac[60]; // [esp+Ch] [ebp-40h] BYREF
  long double _Ans; // [esp+48h] [ebp-4h] BYREF

  *(_DWORD *)&_Ac[56] = 0;
  LODWORD(_Ans) = 0;
  v7 = std::num_get<char,std::istreambuf_iterator<char>>::_Getffld(
         this,
         _Ac: (char *)&x,
         &_First,
         &_Last,
         _Iosbase,
         _Phexexp: (int *)&_Ans);
  *(double *)&_Ac[48] = _Stodx(s: (const char *)&x, endptr: (char **)&_Iosbase, pten: v7, perr: (int *)&_Ac[56]);
  if ( LODWORD(_Ans) != 0 )
    *(double *)&_Ac[48] = ldexp(x: *(long double *)&_Ac[48], exp: 4 * LODWORD(_Ans));
  v8 = (unsigned __int8)std::istreambuf_iterator<char>::equal(this: &_First, _Right: &_Last) == 0;
  v9 = _State;
  if ( !v8 )
    *_State |= 1u;
  if ( _Iosbase == (std::ios_base *)&x || *(_DWORD *)&_Ac[56] != 0 )
  {
    *v9 |= 2u;
    v13 = *(_DWORD *)&_First._Got;
    result->_Strbuf = _First._Strbuf;
    *(_DWORD *)&result->_Got = v13;
    return result;
  }
  else
  {
    Strbuf = _First._Strbuf;
    *_Val = *(long double *)&_Ac[48];
    v12 = *(_DWORD *)&_First._Got;
    result->_Strbuf = Strbuf;
    *(_DWORD *)&result->_Got = v12;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120F00
// Name: protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char>> std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char>>>::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::istreambuf_iterator<char,struct std::char_traits<char>>,class std::ios_base __near &,int __near &,long double __near &)const
// Source: json
//------------------------------------------------------------------------------
std::istreambuf_iterator<char> *__thiscall std::num_get<char,std::istreambuf_iterator<char>>::do_get(
        std::num_get<char,std::istreambuf_iterator<char> > *this,
        std::istreambuf_iterator<char> *result,
        std::istreambuf_iterator<char> _First,
        std::istreambuf_iterator<char> _Last,
        std::ios_base *_Iosbase,
        int *_State,
        long double *_Val)
{
  int v7; // eax
  bool v8; // zf
  int *v9; // eax
  std::streambuf *Strbuf; // ecx
  int v12; // edx
  int v13; // edx
  long double x; // [esp+0h] [ebp-4Ch] BYREF
  char _Ac[60]; // [esp+Ch] [ebp-40h] BYREF
  long double _Ans; // [esp+48h] [ebp-4h] BYREF

  *(_DWORD *)&_Ac[56] = 0;
  LODWORD(_Ans) = 0;
  v7 = std::num_get<char,std::istreambuf_iterator<char>>::_Getffld(
         this,
         _Ac: (char *)&x,
         &_First,
         &_Last,
         _Iosbase,
         _Phexexp: (int *)&_Ans);
  *(double *)&_Ac[48] = _Stoldx(s: (const char *)&x, endptr: (char **)&_Iosbase, pten: v7, perr: (int *)&_Ac[56]);
  if ( LODWORD(_Ans) != 0 )
    *(double *)&_Ac[48] = ldexp(x: *(long double *)&_Ac[48], exp: 4 * LODWORD(_Ans));
  v8 = (unsigned __int8)std::istreambuf_iterator<char>::equal(this: &_First, _Right: &_Last) == 0;
  v9 = _State;
  if ( !v8 )
    *_State |= 1u;
  if ( _Iosbase == (std::ios_base *)&x || *(_DWORD *)&_Ac[56] != 0 )
  {
    *v9 |= 2u;
    v13 = *(_DWORD *)&_First._Got;
    result->_Strbuf = _First._Strbuf;
    *(_DWORD *)&result->_Got = v13;
    return result;
  }
  else
  {
    Strbuf = _First._Strbuf;
    *_Val = *(long double *)&_Ac[48];
    v12 = *(_DWORD *)&_First._Got;
    result->_Strbuf = Strbuf;
    *(_DWORD *)&result->_Got = v12;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120FD0
// Name: public: std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>(char const __near *)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::string(std::string *this, char *_Ptr)
{
  this->_Myres = 15;
  this->_Mysize = 0;
  this->_Bx._Buf[0] = 0;
  std::string::assign(this, _Ptr, _Count: strlen(_Ptr));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10121010
// Name: protected: virtual class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> std::numpunct<char>::do_grouping(void)const
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::numpunct<char>::do_grouping(std::numpunct<char> *this, std::string *result)
{
  char *Grouping; // ecx

  Grouping = (char *)this->_Grouping;
  result->_Myres = 15;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::string::assign(this: result, _Ptr: Grouping, _Count: strlen(Grouping));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10121090
// Name: protected: virtual class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> std::numpunct<char>::do_falsename(void)const
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::numpunct<char>::do_falsename(std::numpunct<char> *this, std::string *result)
{
  char *Falsename; // ecx

  Falsename = (char *)this->_Falsename;
  result->_Myres = 15;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::string::assign(this: result, _Ptr: Falsename, _Count: strlen(Falsename));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10121110
// Name: protected: virtual class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> std::numpunct<char>::do_truename(void)const
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::numpunct<char>::do_truename(std::numpunct<char> *this, std::string *result)
{
  char *Truename; // ecx

  Truename = (char *)this->_Truename;
  result->_Myres = 15;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::string::assign(this: result, _Ptr: Truename, _Count: strlen(Truename));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029FF50
// Name: void std::_Push_heap<struct ParticleRenderData_t __near *,int,struct ParticleRenderData_t,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &)>(struct ParticleRenderData_t __near *,int,int,struct ParticleRenderData_t __near &&,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        ParticleRenderData_t *_First,
        int _Hole,
        int _Top,
        ParticleRenderData_t *_Val,
        bool (__cdecl *_Pred)(const ParticleRenderData_t *, const ParticleRenderData_t *))
{
  int v5; // edi
  int i; // esi
  ParticleRenderData_t *v7; // ebx
  ParticleRenderData_t *v8; // eax

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    v8 = &_First[v5];
    v5 = i;
    *(_QWORD *)&v8->m_flSortKey = *(_QWORD *)&v7->m_flSortKey;
    *(_QWORD *)&v8->m_flRadius = *(_QWORD *)&v7->m_flRadius;
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x1029FFD0
// Name: void std::_Push_heap<struct ParticleFullRenderData_Scalar_View __near * __near *,int,struct ParticleFullRenderData_Scalar_View __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleFullRenderData_Scalar_View __near * __near *,int,int,struct ParticleFullRenderData_Scalar_View __near * __near &&,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<ParticleFullRenderData_Scalar_View * *,int,ParticleFullRenderData_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleFullRenderData_Scalar_View **_First,
        int _Hole,
        int _Top,
        const ParticleFullRenderData_Scalar_View *const *_Val,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v5; // edi
  int v6; // esi
  bool v7; // zf
  ParticleFullRenderData_Scalar_View **v8; // eax

  v5 = _Hole;
  v6 = (_Hole - 1) / 2;
  if ( _Top >= _Hole )
  {
    _First[_Hole] = (ParticleFullRenderData_Scalar_View *)*_Val;
  }
  else
  {
    while ( 1 )
    {
      v7 = !_Pred(a1: &_First[v6], a2: _Val);
      v8 = _First;
      if ( v7 )
        break;
      _First[v5] = _First[v6];
      v5 = v6;
      v6 = (v6 - 1) / 2;
      if ( _Top >= v5 )
      {
        v8 = _First;
        break;
      }
    }
    v8[v5] = (ParticleFullRenderData_Scalar_View *)*_Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A0040
// Name: void std::_Push_heap<struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,int,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,int,int,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near &&,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,int,ParticleRenderDataWithOutlineInformation_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleRenderDataWithNormal_Scalar_View **_First,
        int _Hole,
        int _Top,
        ParticleRenderDataWithNormal_Scalar_View **_Val,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v5; // edi
  int v6; // esi
  ParticleRenderDataWithNormal_Scalar_View **v7; // ebx
  int v8; // edx

  v5 = _Hole;
  v6 = (_Hole - 1) / 2;
  if ( _Top >= _Hole )
  {
    _First[_Hole] = *_Val;
  }
  else
  {
    v7 = _First;
    while ( 1 )
    {
      v8 = (int)v7[v6];
      _First = (ParticleRenderDataWithNormal_Scalar_View **)*_Val;
      _Hole = v8;
      if ( !_Pred(
              a1: (ParticleFullRenderData_Scalar_View *const *)&_Hole,
              a2: (const ParticleFullRenderData_Scalar_View *const *)&_First) )
        break;
      v7[v5] = v7[v6];
      v5 = v6;
      v6 = (v6 - 1) / 2;
      if ( _Top >= v5 )
      {
        v7[v5] = *_Val;
        return;
      }
    }
    v7[v5] = *_Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A08D0
// Name: void std::_Adjust_heap<struct ParticleRenderData_t __near *,int,struct ParticleRenderData_t,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &)>(struct ParticleRenderData_t __near *,int,int,struct ParticleRenderData_t __near &&,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        ParticleRenderData_t *_First,
        int _Hole,
        int _Bottom,
        ParticleRenderData_t *_Val,
        bool (__cdecl *_Pred)(const ParticleRenderData_t *, const ParticleRenderData_t *))
{
  int v5; // ecx
  int v6; // ebx
  int v7; // esi
  bool v8; // zf
  int v9; // ecx
  __int64 v10; // xmm0_8
  int v11; // esi
  const ParticleRenderData_t *v12; // ebx
  int _Holea; // [esp+1Ch] [ebp+Ch]

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      v9 = v6;
      v6 = v7;
      *(_QWORD *)&_First[v9].m_flSortKey = *(_QWORD *)&_First[v7].m_flSortKey;
      v10 = *(_QWORD *)&_First[v7].m_flRadius;
      v7 = 2 * v7 + 2;
      *(_QWORD *)&_First[v9].m_flRadius = v10;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    _First[v6] = _First[v5 - 1];
    v6 = v5 - 1;
  }
  v11 = (v6 - 1) / 2;
  _Holea = v6;
  if ( _Hole < v6 )
  {
    do
    {
      v12 = &_First[v11];
      if ( !_Pred(a1: v12, a2: _Val) )
        break;
      _First[_Holea] = *v12;
      _Holea = v11;
      v11 = (v11 - 1) / 2;
    }
    while ( _Hole < _Holea );
    v6 = _Holea;
  }
  _First[v6] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x102A1BB0
// Name: void std::_Adjust_heap<struct ParticleFullRenderData_Scalar_View __near * __near *,int,struct ParticleFullRenderData_Scalar_View __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleFullRenderData_Scalar_View __near * __near *,int,int,struct ParticleFullRenderData_Scalar_View __near * __near &&,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<ParticleFullRenderData_Scalar_View * *,int,ParticleFullRenderData_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleFullRenderData_Scalar_View **_First,
        int _Hole,
        int _Bottom,
        const ParticleFullRenderData_Scalar_View *const *_Val,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v5; // eax
  int v6; // ebx
  int v7; // esi
  bool v8; // zf
  ParticleFullRenderData_Scalar_View *v9; // edx
  int v10; // esi
  int v11; // ecx
  int _Holeb; // [esp+1Ch] [ebp+Ch]
  int _Holea; // [esp+1Ch] [ebp+Ch]

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: (const ParticleFullRenderData_Scalar_View *const *)&_First[v7 - 1]) )
        --v7;
      v9 = _First[v7];
      _Holeb = v7;
      v7 = 2 * v7 + 2;
      _First[v6] = v9;
      v6 = _Holeb;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    _First[v6] = _First[v5 - 1];
    v6 = v5 - 1;
  }
  v10 = (v6 - 1) / 2;
  _Holea = v6;
  if ( _Hole >= v6 )
  {
    _First[v6] = (ParticleFullRenderData_Scalar_View *)*_Val;
  }
  else
  {
    while ( _Pred(a1: &_First[v10], a2: _Val) )
    {
      _First[_Holea] = _First[v10];
      v11 = v10;
      _Holea = v10;
      v10 = (v10 - 1) / 2;
      if ( _Hole >= _Holea )
      {
        _First[v11] = (ParticleFullRenderData_Scalar_View *)*_Val;
        return;
      }
    }
    _First[_Holea] = (ParticleFullRenderData_Scalar_View *)*_Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A45B0
// Name: void std::_Adjust_heap<struct ParticleRenderDataWithNormal_Scalar_View __near * __near *,int,struct ParticleRenderDataWithNormal_Scalar_View __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleRenderDataWithNormal_Scalar_View __near * __near *,int,int,struct ParticleRenderDataWithNormal_Scalar_View __near * __near &&,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<ParticleRenderDataWithNormal_Scalar_View * *,int,ParticleRenderDataWithNormal_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleRenderDataWithNormal_Scalar_View **_First,
        ParticleRenderDataWithNormal_Scalar_View *_Hole,
        int _Bottom,
        ParticleRenderDataWithNormal_Scalar_View **_Val,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v5; // eax
  int v6; // ebx
  int v7; // esi
  ParticleRenderDataWithNormal_Scalar_View **v8; // edi
  bool v9; // zf
  ParticleRenderDataWithNormal_Scalar_View **v10; // ecx
  ParticleRenderDataWithNormal_Scalar_View *v11; // ecx
  int v12; // esi
  int v13; // edx
  int _Top; // [esp+Ch] [ebp-4h]

  v5 = _Bottom;
  v6 = (int)_Hole;
  v7 = 2 * (_DWORD)_Hole + 2;
  v8 = _First;
  _Top = (int)_Hole;
  v9 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      v10 = (ParticleRenderDataWithNormal_Scalar_View **)v8[v7];
      _Hole = v8[v7 - 1];
      _First = v10;
      if ( _Pred(
             a1: (ParticleFullRenderData_Scalar_View *const *)&_First,
             a2: (const ParticleFullRenderData_Scalar_View *const *)&_Hole) )
      {
        --v7;
      }
      v11 = v8[v7];
      _Hole = (ParticleRenderDataWithNormal_Scalar_View *)v7;
      v7 = 2 * v7 + 2;
      v8[v6] = v11;
      v6 = (int)_Hole;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v9 = v7 == _Bottom;
  }
  if ( v9 )
  {
    v8[v6] = v8[v5 - 1];
    _Hole = (ParticleRenderDataWithNormal_Scalar_View *)(v5 - 1);
    v6 = v5 - 1;
  }
  v12 = (v6 - 1) / 2;
  if ( _Top < v6 )
  {
    while ( 1 )
    {
      v13 = (int)v8[v12];
      _Hole = *_Val;
      _Bottom = v13;
      if ( !_Pred(
              a1: (ParticleFullRenderData_Scalar_View *const *)&_Bottom,
              a2: (const ParticleFullRenderData_Scalar_View *const *)&_Hole) )
        break;
      v8[v6] = v8[v12];
      _Hole = (ParticleRenderDataWithNormal_Scalar_View *)v12;
      v12 = (v12 - 1) / 2;
      if ( _Top >= (int)_Hole )
      {
        v8[(_DWORD)_Hole] = *_Val;
        return;
      }
      v6 = (int)_Hole;
    }
    v8[v6] = *_Val;
  }
  else
  {
    v8[v6] = *_Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A46A0
// Name: void std::_Make_heap<struct ParticleRenderData_t __near *,int,struct ParticleRenderData_t,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &)>(struct ParticleRenderData_t __near *,struct ParticleRenderData_t __near *,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &),int __near *,struct ParticleRenderData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        ParticleRenderData_t *_First,
        ParticleRenderData_t *_Last,
        bool (__cdecl *_Pred)(const ParticleRenderData_t *, const ParticleRenderData_t *))
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  ParticleRenderData_t *i; // edx
  __int64 v8; // xmm0_8
  ParticleRenderData_t *v9; // edx
  int v10; // eax
  int v11; // esi
  __int64 v12; // xmm0_8
  int v13; // ebx
  bool v14; // zf
  int v15; // ecx
  __int64 v16; // xmm0_8
  int v17; // ebx
  ParticleRenderData_t _Val; // [esp+4h] [ebp-18h] BYREF
  int v19; // [esp+14h] [ebp-8h]
  ParticleRenderData_t *v20; // [esp+18h] [ebp-4h]
  int _Hole; // [esp+24h] [ebp+8h]
  int _Bottom; // [esp+28h] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * v5 + 2;
    for ( i = &_First[v5]; ; i = v20 )
    {
      v8 = *(_QWORD *)&i[-1].m_flSortKey;
      v9 = i - 1;
      v10 = v5 - 1;
      v11 = v6 - 2;
      *(_QWORD *)&_Val.m_flSortKey = v8;
      v12 = *(_QWORD *)&v9->m_flRadius;
      _Hole = v10;
      v20 = v9;
      v19 = v11;
      *(_QWORD *)&_Val.m_flRadius = v12;
      v13 = v10;
      v14 = v11 == v4;
      if ( v11 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v11], a2: &_First[v11 - 1]) )
            --v11;
          v15 = v13;
          v13 = v11;
          *(_QWORD *)&_First[v15].m_flSortKey = *(_QWORD *)&_First[v11].m_flSortKey;
          v16 = *(_QWORD *)&_First[v11].m_flRadius;
          v11 = 2 * v11 + 2;
          *(_QWORD *)&_First[v15].m_flRadius = v16;
        }
        while ( v11 < _Bottom );
        v4 = _Bottom;
        v10 = _Hole;
        v14 = v11 == _Bottom;
      }
      if ( v14 )
      {
        v17 = v13;
        *(_QWORD *)&_First[v17].m_flSortKey = *(_QWORD *)&_First[v4 - 1].m_flSortKey;
        *(_QWORD *)&_First[v17].m_flRadius = *(_QWORD *)&_First[v4 - 1].m_flRadius;
        v13 = v4 - 1;
      }
      std::_Push_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        _First,
        _Hole: v13,
        _Top: v10,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v5 = _Hole;
      v4 = _Bottom;
      v6 = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A47B0
// Name: void std::_Make_heap<struct ParticleFullRenderData_Scalar_View __near * __near *,int,struct ParticleFullRenderData_Scalar_View __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleFullRenderData_Scalar_View __near * __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &),int __near *,struct ParticleFullRenderData_Scalar_View __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<ParticleFullRenderData_Scalar_View * *,int,ParticleFullRenderData_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleFullRenderData_Scalar_View **_First,
        ParticleFullRenderData_Scalar_View **_Last,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v4; // ecx
  int v5; // ebx
  int i; // esi
  ParticleFullRenderData_Scalar_View *v7; // eax
  int v8; // esi
  bool v9; // zf
  int v10; // eax
  ParticleFullRenderData_Scalar_View *v11; // edx
  ParticleFullRenderData_Scalar_View *_Val; // [esp+8h] [ebp-8h] BYREF
  int v13; // [esp+Ch] [ebp-4h]
  int _Bottom; // [esp+18h] [ebp+8h]
  int _Lasta; // [esp+1Ch] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    for ( i = 2 * v5 + 2; ; i = v13 )
    {
      v7 = _First[--v5];
      v8 = i - 2;
      v13 = v8;
      _Val = v7;
      _Lasta = v5;
      v9 = v8 == v4;
      if ( v8 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v8], a2: (const ParticleFullRenderData_Scalar_View *const *)&_First[v8 - 1]) )
            --v8;
          v10 = _Lasta;
          v11 = _First[v8];
          _Lasta = v8;
          v8 = 2 * v8 + 2;
          _First[v10] = v11;
        }
        while ( v8 < _Bottom );
        v4 = _Bottom;
        v9 = v8 == _Bottom;
      }
      if ( v9 )
      {
        _First[_Lasta] = _First[v4 - 1];
        _Lasta = v4 - 1;
      }
      std::_Push_heap<ParticleFullRenderData_Scalar_View * *,int,ParticleFullRenderData_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First,
        _Hole: _Lasta,
        _Top: v5,
        (const ParticleFullRenderData_Scalar_View *const *)&_Val,
        _Pred);
      if ( v5 <= 0 )
        break;
      v4 = _Bottom;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4860
// Name: void std::_Make_heap<struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,int,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &),int __near *,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,int,ParticleRenderDataWithOutlineInformation_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleRenderDataWithNormal_Scalar_View **_First,
        ParticleRenderDataWithNormal_Scalar_View **_Last,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v4; // ecx
  int v5; // ebx
  int i; // esi
  ParticleRenderDataWithNormal_Scalar_View *v7; // eax
  int v8; // esi
  bool v9; // zf
  ParticleRenderDataWithNormal_Scalar_View *v10; // edx
  int v11; // eax
  ParticleRenderDataWithNormal_Scalar_View *v12; // edx
  ParticleRenderDataWithNormal_Scalar_View *_Val; // [esp+8h] [ebp-10h] BYREF
  ParticleFullRenderData_Scalar_View *v14; // [esp+Ch] [ebp-Ch] BYREF
  ParticleFullRenderData_Scalar_View *v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h]
  int _Bottom; // [esp+20h] [ebp+8h]
  int _Lasta; // [esp+24h] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    for ( i = 2 * v5 + 2; ; i = v16 )
    {
      v7 = _First[--v5];
      v8 = i - 2;
      v16 = v8;
      _Val = v7;
      _Lasta = v5;
      v9 = v8 == v4;
      if ( v8 < v4 )
      {
        do
        {
          v10 = _First[v8];
          v15 = _First[v8 - 1];
          v14 = v10;
          if ( _Pred(a1: &v14, a2: (const ParticleFullRenderData_Scalar_View *const *)&v15) )
            --v8;
          v11 = _Lasta;
          v12 = _First[v8];
          _Lasta = v8;
          v8 = 2 * v8 + 2;
          _First[v11] = v12;
        }
        while ( v8 < _Bottom );
        v4 = _Bottom;
        v9 = v8 == _Bottom;
      }
      if ( v9 )
      {
        _First[_Lasta] = _First[v4 - 1];
        _Lasta = v4 - 1;
      }
      std::_Push_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,int,ParticleRenderDataWithOutlineInformation_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First,
        _Hole: _Lasta,
        _Top: v5,
        &_Val,
        _Pred);
      if ( v5 <= 0 )
        break;
      v4 = _Bottom;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4C20
// Name: void std::_Sort_heap<struct ParticleRenderData_t __near *,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &)>(struct ParticleRenderData_t __near *,struct ParticleRenderData_t __near *,bool (*)(struct ParticleRenderData_t const __near &,struct ParticleRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<ParticleRenderData_t *,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        ParticleRenderData_t *_First,
        ParticleRenderData_t *_Last,
        bool (__cdecl *_Pred)(const ParticleRenderData_t *, const ParticleRenderData_t *))
{
  int v3; // eax
  ParticleRenderData_t *v4; // esi
  ParticleRenderData_t _Val; // [esp+4h] [ebp-10h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFF0) > 16 )
  {
    v4 = _Last - 1;
    do
    {
      _Val = *v4;
      *v4 = *_First;
      std::_Adjust_heap<ParticleRenderData_t *,int,ParticleRenderData_t,bool (__cdecl *)(ParticleRenderData_t const &,ParticleRenderData_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 16) >> 4,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 16;
    }
    while ( (int)(v3 & 0xFFFFFFF0) > 16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4CA0
// Name: void std::_Sort_heap<struct ParticleFullRenderData_Scalar_View __near * __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleFullRenderData_Scalar_View __near * __near *,struct ParticleFullRenderData_Scalar_View __near * __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<ParticleFullRenderData_Scalar_View * *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleFullRenderData_Scalar_View **_First,
        ParticleFullRenderData_Scalar_View **_Last,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v3; // eax
  bool (__cdecl *v4)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *); // ebx
  ParticleFullRenderData_Scalar_View **v5; // edx
  int v6; // edi

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFFC) > 4 )
  {
    v4 = _Pred;
    do
    {
      v5 = *(ParticleFullRenderData_Scalar_View ***)((char *)_First + v3 - 4);
      v6 = v3 - 4;
      *(ParticleFullRenderData_Scalar_View **)((char *)_First + v3 - 4) = *_First;
      _Last = v5;
      std::_Adjust_heap<ParticleFullRenderData_Scalar_View * *,int,ParticleFullRenderData_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 4) >> 2,
        _Val: (const ParticleFullRenderData_Scalar_View *const *)&_Last,
        _Pred: v4);
      v3 = v6;
    }
    while ( (int)(v6 & 0xFFFFFFFC) > 4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4D00
// Name: void std::_Sort_heap<struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &)>(struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,struct ParticleRenderDataWithOutlineInformation_Scalar_View __near * __near *,bool (*)(struct ParticleFullRenderData_Scalar_View __near * const __near &,struct ParticleFullRenderData_Scalar_View const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<ParticleRenderDataWithOutlineInformation_Scalar_View * *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        ParticleRenderDataWithNormal_Scalar_View **_First,
        ParticleRenderDataWithNormal_Scalar_View **_Last,
        bool (__cdecl *_Pred)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *))
{
  int v3; // eax
  bool (__cdecl *v4)(ParticleFullRenderData_Scalar_View *const *, const ParticleFullRenderData_Scalar_View *const *); // ebx
  ParticleRenderDataWithNormal_Scalar_View **v5; // edx
  int v6; // edi

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFFC) > 4 )
  {
    v4 = _Pred;
    do
    {
      v5 = *(ParticleRenderDataWithNormal_Scalar_View ***)((char *)_First + v3 - 4);
      v6 = v3 - 4;
      *(ParticleRenderDataWithNormal_Scalar_View **)((char *)_First + v3 - 4) = *_First;
      _Last = v5;
      std::_Adjust_heap<ParticleRenderDataWithNormal_Scalar_View * *,int,ParticleRenderDataWithNormal_Scalar_View *,bool (__cdecl *)(ParticleFullRenderData_Scalar_View * const &,ParticleFullRenderData_Scalar_View const * const &)>(
        _First,
        _Hole: nullptr,
        _Bottom: (v3 - 4) >> 2,
        _Val: (ParticleRenderDataWithNormal_Scalar_View **)&_Last,
        _Pred: v4);
      v3 = v6;
    }
    while ( (int)(v6 & 0xFFFFFFFC) > 4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x104607C6
// Name: class std::error_category const __near & std::iostream_category(void)
// Source: json
//------------------------------------------------------------------------------
std::_Iostream_error_category *__cdecl std::iostream_category()
{
  return &Iostream_object;
}

//------------------------------------------------------------------------------
// Address: 0x104607EE
// Name: public: virtual class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> std::_Generic_error_category::message(int)const
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::_Generic_error_category::message(
        std::_Generic_error_category *this,
        std::string *result,
        std::string *_Errcode)
{
  char *v3; // eax

  v3 = strerror(errnum: (int)_Errcode);
  std::string::string(this: result, _Ptr: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10460811
// Name: public: virtual class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> std::_Iostream_error_category::message(int)const
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::_Iostream_error_category::message(
        std::_Iostream_error_category *this,
        std::string *result,
        int _Errcode)
{
  char *v4; // [esp-4h] [ebp-8h]

  if ( _Errcode == 1 )
  {
    std::string::string(this: result, _Ptr: "iostream stream error");
  }
  else
  {
    v4 = strerror(errnum: _Errcode);
    std::string::string(this: result, _Ptr: v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10460953
// Name: bool std::uncaught_exception(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __cdecl std::uncaught_exception()
{
  return __uncaught_exception();
}

//------------------------------------------------------------------------------
// Address: 0x10460A23
// Name: void std::_Xlength_error(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn std::_Xlength_error(const char *_Message)
{
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  std::exception::exception(this: &pExceptionObject, _What: &_Message);
  pExceptionObject.__vftable = (std::exception_vtbl *)&std::length_error::`vftable';
  _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI3_AVlength_error_std__);
}

//------------------------------------------------------------------------------
// Address: 0x10460A70
// Name: void std::_Xout_of_range(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn std::_Xout_of_range(const char *_Message)
{
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  std::exception::exception(this: &pExceptionObject, _What: &_Message);
  pExceptionObject.__vftable = (std::exception_vtbl *)&std::out_of_range::`vftable';
  _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI3_AVout_of_range_std__);
}

//------------------------------------------------------------------------------
// Address: 0x10460B21
// Name: struct _iobuf __near * std::_Xfsopen(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl std::_Xfsopen(const char *filename, int mode, int prot)
{
  return _fsopen(file: filename, mode: mods[mode], shflag: prot);
}

//------------------------------------------------------------------------------
// Address: 0x10460B40
// Name: struct _iobuf __near * std::_Xfiopen<char>(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl std::_Xfiopen<char>(const char *filename, int mode, int prot)
{
  int v3; // ecx
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // esi
  _iobuf *v8; // eax
  _iobuf *v9; // eax
  _iobuf *v10; // esi

  v3 = mode;
  v4 = 1;
  if ( (mode & 0x40) != 0 )
    v3 = mode | 1;
  if ( (v3 & 8) != 0 )
    v3 |= 2u;
  v5 = v3 & 0xFFFFFF3B;
  v6 = 0;
  do
  {
    if ( v4 == v5 )
      break;
    v4 = dword_106AECDC[v6++];
  }
  while ( v4 != 0 );
  if ( `std::_Xfiopen<char>'::`2'::valid[v6] == 0 )
    return nullptr;
  if ( (mode & 0x80) != 0 && (v5 & 0xA) != 0 )
  {
    v8 = std::_Xfsopen(filename, mode: 0, prot);
    if ( v8 != nullptr )
    {
      fclose(stream: v8);
      return nullptr;
    }
  }
  v9 = std::_Xfsopen(filename, mode: v6, prot);
  v10 = v9;
  if ( v9 == nullptr )
    return nullptr;
  if ( (mode & 4) != 0 && fseek(stream: v9, offset: 0, whence: 2) != 0 )
  {
    fclose(stream: v10);
    return nullptr;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10460BE8
// Name: struct _iobuf __near * std::_Fiopen(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl std::_Fiopen(const char *filename, int mode, int prot)
{
  return std::_Xfiopen<char>(filename, mode, prot);
}

//------------------------------------------------------------------------------
// Address: 0x105C59D8
// Name: std::_dynamic_initializer_for__initlocks__
// Source: json
//------------------------------------------------------------------------------
int std::_dynamic_initializer_for__initlocks__()
{
  std::_Init_locks::_Init_locks(this: &initlocks);
  return atexit(func: std::_dynamic_atexit_destructor_for__initlocks__);
}

//------------------------------------------------------------------------------
// Address: 0x105C59EE
// Name: std::_dynamic_initializer_for___Fac_tidy_reg__
// Source: json
//------------------------------------------------------------------------------
int std::_dynamic_initializer_for___Fac_tidy_reg__()
{
  return atexit(func: std::_dynamic_atexit_destructor_for___Fac_tidy_reg__);
}

//------------------------------------------------------------------------------
// Address: 0x105C59FA
// Name: std::_dynamic_initializer_for__classic_locale__
// Source: json
//------------------------------------------------------------------------------
int std::_dynamic_initializer_for__classic_locale__()
{
  return atexit(func: std::_dynamic_atexit_destructor_for__classic_locale__);
}

//------------------------------------------------------------------------------
// Address: 0x105C5A06
// Name: std::_dynamic_initializer_for___Generic_object__
// Source: json
//------------------------------------------------------------------------------
int std::_dynamic_initializer_for___Generic_object__()
{
  return atexit(func: std::_dynamic_atexit_destructor_for___Generic_object__);
}

//------------------------------------------------------------------------------
// Address: 0x105C5A12
// Name: std::_dynamic_initializer_for___Iostream_object__
// Source: json
//------------------------------------------------------------------------------
int std::_dynamic_initializer_for___Iostream_object__()
{
  return atexit(func: std::_dynamic_atexit_destructor_for___Iostream_object__);
}

//------------------------------------------------------------------------------
// Address: 0x105C5A1E
// Name: std::_dynamic_initializer_for___System_object__
// Source: json
//------------------------------------------------------------------------------
int std::_dynamic_initializer_for___System_object__()
{
  return atexit(func: std::_dynamic_atexit_destructor_for___System_object__);
}

//------------------------------------------------------------------------------
// Address: 0x105C5A2A
// Name: std::_dynamic_initializer_for__initlocks___0
// Source: json
//------------------------------------------------------------------------------
int std::_dynamic_initializer_for__initlocks___0()
{
  std::_Init_locks::_Init_locks(this: &initlocks_0);
  return atexit(func: std::_dynamic_atexit_destructor_for__initlocks___0);
}

//------------------------------------------------------------------------------
// Address: 0x105CC8BB
// Name: std::_dynamic_atexit_destructor_for__initlocks__
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_dynamic_atexit_destructor_for__initlocks__()
{
  std::_Init_locks::~_Init_locks(this: &initlocks);
}

//------------------------------------------------------------------------------
// Address: 0x105CC8C5
// Name: std::_dynamic_atexit_destructor_for__classic_locale__
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_dynamic_atexit_destructor_for__classic_locale__()
{
  std::locale::~locale(this: &classic_locale);
}

//------------------------------------------------------------------------------
// Address: 0x105CC8CF
// Name: std::_dynamic_atexit_destructor_for___Fac_tidy_reg__
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_dynamic_atexit_destructor_for___Fac_tidy_reg__()
{
  std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t(this: &Fac_tidy_reg);
}

//------------------------------------------------------------------------------
// Address: 0x105CC8D9
// Name: std::_dynamic_atexit_destructor_for___Generic_object__
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_dynamic_atexit_destructor_for___Generic_object__()
{
  Generic_object.__vftable = (std::_Generic_error_category_vtbl *)&std::error_category::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x105CC8E4
// Name: std::_dynamic_atexit_destructor_for___Iostream_object__
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_dynamic_atexit_destructor_for___Iostream_object__()
{
  Iostream_object.__vftable = (std::_Iostream_error_category_vtbl *)&std::error_category::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x105CC8EF
// Name: std::_dynamic_atexit_destructor_for___System_object__
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_dynamic_atexit_destructor_for___System_object__()
{
  System_object.__vftable = (std::_System_error_category_vtbl *)&std::error_category::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x105CC8FA
// Name: std::_dynamic_atexit_destructor_for__initlocks___0
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_dynamic_atexit_destructor_for__initlocks___0()
{
  std::_Init_locks::~_Init_locks(this: &initlocks_0);
}

//------------------------------------------------------------------------------
// Address: 0x10460841
// Name: __Toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _Toupper(int c, const _Ctypevec *ploc)
{
  const _Ctypevec *v2; // esi
  unsigned int Page; // eax
  int result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  bool v8; // zf
  unsigned int codepage; // [esp+4h] [ebp-10h]
  unsigned int handle; // [esp+8h] [ebp-Ch]
  int v11; // [esp+Ch] [ebp-8h]
  char outbuffer[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = ploc;
  if ( ploc != nullptr )
  {
    handle = ploc->_Hand;
    Page = ploc->_Page;
  }
  else
  {
    handle = ___lc_handle_func()[2];
    Page = ___lc_codepage_func();
  }
  codepage = Page;
  if ( handle == 0 )
  {
    result = c;
    if ( (unsigned int)(c - 97) <= 0x19 )
      return c - 32;
    return result;
  }
  if ( (unsigned int)c < 0x100 )
  {
    if ( v2 == nullptr )
    {
      if ( islower(c) == 0 )
        return c;
      goto LABEL_13;
    }
    if ( (v2->_Table[c] & 2) == 0 )
      return c;
  }
  if ( v2 == nullptr )
  {
LABEL_13:
    v11 = c >> 8;
    v5 = __pctype_func()[BYTE1(c)] & 0x8000;
    goto LABEL_15;
  }
  v11 = c >> 8;
  v5 = v2->_Table[BYTE1(c)] < 0;
LABEL_15:
  if ( v5 != 0 )
  {
    LOBYTE(ploc) = v11;
    *(_WORD *)((char *)&ploc + 1) = (unsigned __int8)c;
    v6 = 2;
  }
  else
  {
    LOWORD(ploc) = (unsigned __int8)c;
    v6 = 1;
  }
  v7 = __crtLCMapStringA(
         plocinfo: nullptr,
         Locale: handle,
         dwMapFlags: 0x200u,
         lpSrcStr: (const char *)&ploc,
         cchSrc: v6,
         lpDestStr: outbuffer,
         cchDest: 3,
         code_page: codepage,
         bError: 1);
  if ( v7 == 0 )
    return c;
  v8 = v7 == 1;
  result = (unsigned __int8)outbuffer[0];
  if ( !v8 )
    return (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10460A53
// Name: public: std::length_error::length_error(class std::length_error const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::length_error *__thiscall std::length_error::length_error(std::length_error *this, const std::length_error *__that)
{
  std::exception::exception(this, _That: __that);
  this->__vftable = (std::length_error_vtbl *)&std::length_error::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10460AA0
// Name: public: std::out_of_range::out_of_range(class std::out_of_range const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::out_of_range *__thiscall std::out_of_range::out_of_range(std::out_of_range *this, const std::out_of_range *__that)
{
  std::exception::exception(this, _That: __that);
  this->__vftable = (std::out_of_range_vtbl *)&std::out_of_range::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10460ADE
// Name: public: std::_Mutex::_Mutex(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::_Mutex *__thiscall std::_Mutex::_Mutex(std::_Mutex *this)
{
  _RTL_CRITICAL_SECTION *v2; // eax

  v2 = (_RTL_CRITICAL_SECTION *)operator new(nSize: 0x18u);
  this->_Mtx = v2;
  _Mtxinit(_Mtx: v2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10460AF8
// Name: public: std::_Mutex::~_Mutex(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall std::_Mutex::~_Mutex(std::_Mutex *this)
{
  _Mtxdst(_Mtx: (_RTL_CRITICAL_SECTION *)this->_Mtx);
  operator delete(p: this->_Mtx);
}

//------------------------------------------------------------------------------
// Address: 0x10460BF3
// Name: __Getcvt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int _Getcvt()
{
  unsigned int v0; // esi

  v0 = ___lc_handle_func()[2];
  ___lc_codepage_func();
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x10460C09
// Name: __Stoulx
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _Stoulx(char *s, char **endptr, int base, int *perr)
{
  int v4; // eax
  char *v5; // esi
  char v6; // al
  char v7; // al
  unsigned __int8 v8; // al
  int v9; // eax
  char v10; // bl
  unsigned __int8 v11; // al
  int v12; // eax
  const char *s2; // [esp+Ch] [ebp-14h]
  const char *s1; // [esp+10h] [ebp-10h]
  unsigned int y; // [esp+14h] [ebp-Ch]
  unsigned int x; // [esp+18h] [ebp-8h]
  char sign; // [esp+1Fh] [ebp-1h]

  if ( perr != nullptr )
    *perr = 0;
  v4 = (unsigned __int8)*s;
  v5 = s;
  while ( isspace(c: v4) != 0 )
    v4 = (unsigned __int8)*++v5;
  if ( *v5 == 45 || *v5 == 43 )
    sign = *v5++;
  else
    sign = 43;
  if ( base < 0 || base == 1 || base > 36 )
  {
    if ( endptr != nullptr )
      *endptr = s;
    return 0;
  }
  if ( base <= 0 )
  {
    if ( *v5 == 48 )
    {
      v7 = v5[1];
      if ( v7 == 120 || v7 == 88 )
      {
        base = 16;
LABEL_25:
        v5 += 2;
        goto LABEL_26;
      }
      base = 8;
    }
    else
    {
      base = 10;
    }
  }
  else if ( base == 16 && *v5 == 48 )
  {
    v6 = v5[1];
    if ( v6 == 120 || v6 == 88 )
      goto LABEL_25;
  }
LABEL_26:
  s1 = v5;
  while ( *v5 == 48 )
    ++v5;
  x = 0;
  s2 = v5;
  y = 0;
  v8 = tolower(c: *v5);
  memchr(buf: "0123456789abcdefghijklmnopqrstuvwxyz", chr: v8, cnt: base);
  if ( v9 != 0 )
  {
    do
    {
      v10 = v9 - (unsigned __int8)"0123456789abcdefghijklmnopqrstuvwxyz";
      y = x;
      x = v10 + base * x;
      v11 = tolower(c: *++v5);
      memchr(buf: "0123456789abcdefghijklmnopqrstuvwxyz", chr: v11, cnt: base);
    }
    while ( v9 != 0 );
  }
  else
  {
    v10 = HIBYTE(base);
  }
  if ( s1 == v5 )
  {
    if ( endptr != nullptr )
      *endptr = s;
    return 0;
  }
  v12 = &v5[-ndigs[base]] - s2;
  if ( v12 >= 0 && (v12 > 0 || x < v10 || (x - v10) / base != y) )
  {
    *_errno() = 34;
    if ( perr != nullptr )
      *perr = 1;
    x = -1;
    sign = 43;
  }
  if ( sign == 45 )
    x = -x;
  if ( endptr != nullptr )
    *endptr = v5;
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x10460DA5
// Name: __Stolx
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _Stolx(char *s, char **endptr, int base, int *perr)
{
  char **p_s; // edi
  char *v5; // ebx
  int v6; // eax
  char *v7; // esi
  unsigned int result; // eax

  p_s = endptr;
  if ( endptr == nullptr )
    p_s = &s;
  v5 = s;
  v6 = (unsigned __int8)*s;
  v7 = s;
  while ( isspace(c: v6) != 0 )
    v6 = (unsigned __int8)*++v7;
  if ( *v7 == 45 || *v7 == 43 )
    HIBYTE(endptr) = *v7++;
  else
    HIBYTE(endptr) = 43;
  result = _Stoulx(s: v7, endptr: p_s, base, perr);
  if ( v7 == *p_s )
    *p_s = v5;
  if ( (v5 != *p_s || result == 0) && (HIBYTE(endptr) != 43 || result <= 0x7FFFFFFF) )
  {
    if ( HIBYTE(endptr) != 45 )
      return result;
    if ( result <= 0x80000000 )
      return -result;
  }
  *_errno() = 34;
  if ( perr != nullptr )
    *perr = 1;
  return (HIBYTE(endptr) == 45) + 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10460E4A
// Name: __Stollx
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __cdecl _Stollx(char *s, char **endptr, int base, int *perr)
{
  char **p_s; // edi
  char *v5; // ebx
  int v6; // eax
  const char *v7; // esi
  unsigned __int64 result; // rax

  p_s = endptr;
  if ( endptr == nullptr )
    p_s = &s;
  v5 = s;
  v6 = (unsigned __int8)*s;
  v7 = s;
  while ( isspace(c: v6) != 0 )
    v6 = *(unsigned __int8 *)++v7;
  if ( *v7 == 45 || *v7 == 43 )
    HIBYTE(endptr) = *v7++;
  else
    HIBYTE(endptr) = 43;
  result = _Stoullx(s: v7, endptr: p_s, base, perr);
  if ( v7 == *p_s )
    *p_s = v5;
  if ( (v5 != *p_s || result == 0) && (HIBYTE(endptr) != 43 || HIDWORD(result) <= 0x7FFFFFFF) )
  {
    if ( HIBYTE(endptr) != 45 )
      return result;
    if ( result <= 0x8000000000000000uLL )
      return -(__int64)result;
  }
  *_errno() = 34;
  if ( perr != nullptr )
    *perr = 1;
  if ( HIBYTE(endptr) == 45 )
    return 0x8000000000000000uLL;
  else
    return 0x7FFFFFFFFFFFFFFFLL;
}

//------------------------------------------------------------------------------
// Address: 0x10460F0D
// Name: __Stoullx
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __cdecl _Stoullx(const char *s, char **endptr, int base, int *perr)
{
  const char *v4; // ebx
  int v5; // eax
  const char *v6; // edi
  char v7; // al
  char v8; // al
  unsigned __int8 v9; // al
  int v10; // eax
  char v11; // cl
  unsigned __int8 v12; // al
  int v13; // eax
  char **v14; // eax
  bool v15; // zf
  int v16; // eax
  unsigned __int64 v17; // kr00_8
  unsigned __int64 y; // [esp+14h] [ebp-20h]
  unsigned __int64 x; // [esp+1Ch] [ebp-18h]
  const char *s2; // [esp+24h] [ebp-10h]
  const char *s1; // [esp+28h] [ebp-Ch]
  char dig; // [esp+32h] [ebp-2h]
  char sign; // [esp+33h] [ebp-1h]

  if ( perr != nullptr )
    *perr = 0;
  v4 = s;
  v5 = *(unsigned __int8 *)s;
  v6 = s;
  while ( isspace(c: v5) != 0 )
    v5 = *(unsigned __int8 *)++v6;
  if ( *v6 == 45 || *v6 == 43 )
    sign = *v6++;
  else
    sign = 43;
  if ( base < 0 || base == 1 || base > 36 )
  {
    v14 = endptr;
    v15 = endptr == nullptr;
    goto LABEL_47;
  }
  if ( base <= 0 )
  {
    if ( *v6 == 48 )
    {
      v8 = v6[1];
      if ( v8 == 120 || v8 == 88 )
      {
        base = 16;
LABEL_25:
        v6 += 2;
        goto LABEL_26;
      }
      base = 8;
    }
    else
    {
      base = 10;
    }
  }
  else if ( base == 16 && *v6 == 48 )
  {
    v7 = v6[1];
    if ( v7 == 120 || v7 == 88 )
      goto LABEL_25;
  }
LABEL_26:
  s1 = v6;
  while ( *v6 == 48 )
    ++v6;
  x = 0;
  s2 = v6;
  y = 0;
  dig = 0;
  v9 = tolower(c: *v6);
  memchr(buf: "0123456789abcdefghijklmnopqrstuvwxyz", chr: v9, cnt: base);
  v11 = v10;
  if ( v10 != 0 )
  {
    do
    {
      y = x;
      dig = v11 - (unsigned __int8)"0123456789abcdefghijklmnopqrstuvwxyz";
      ++v6;
      x = dig + base * x;
      v12 = tolower(c: *v6);
      memchr(buf: "0123456789abcdefghijklmnopqrstuvwxyz", chr: v12, cnt: base);
      v11 = v13;
    }
    while ( v13 != 0 );
    v4 = s;
  }
  if ( s1 == v6 )
  {
    v14 = endptr;
    v15 = endptr == nullptr;
LABEL_47:
    if ( !v15 )
      *v14 = (char *)v4;
    return 0;
  }
  v16 = &v6[-ndigs_0[base]] - s2;
  if ( v16 >= 0 )
  {
    if ( v16 > 0 || (v17 = x - dig, x < v17) || v17 / base != y )
    {
      *_errno() = 34;
      if ( perr != nullptr )
        *perr = 1;
      x = -1;
      sign = 43;
    }
  }
  if ( sign == 45 )
    x = -(__int64)x;
  if ( endptr != nullptr )
    *endptr = (char *)v6;
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x10461111
// Name: __Stofx
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _Stofx(const char *s, char **endptr, char **pten, int *perr)
{
  return (float)_Stodx(s, endptr, (int)pten, perr);
}

//------------------------------------------------------------------------------
// Address: 0x10461133
// Name: __Stodx
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _Stodx(const char *s, char **endptr, int pten, int *perr)
{
  int v4; // esi
  int v6; // eax
  double x; // [esp+4h] [ebp-8h]

  v4 = *_errno();
  *_errno() = 0;
  x = strtod(nptr: s, endptr);
  *perr = *_errno();
  *_errno() = v4;
  while ( pten > 0 )
  {
    --pten;
    x = x * 10.0;
  }
  if ( pten < 0 )
  {
    v6 = -pten;
    do
    {
      --v6;
      x = x / 10.0;
    }
    while ( v6 != 0 );
  }
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x1046119C
// Name: __Stoldx
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _Stoldx(const char *s, char **endptr, int pten, int *perr)
{
  return _Stodx(s, endptr, pten, perr);
}

//------------------------------------------------------------------------------
// Address: 0x104611A7
// Name: __Mtxinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Mtxinit(_RTL_CRITICAL_SECTION *_Mtx)
{
  InitializeCriticalSection(lpCriticalSection: _Mtx);
}

//------------------------------------------------------------------------------
// Address: 0x104611B7
// Name: __Mtxdst
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Mtxdst(_RTL_CRITICAL_SECTION *_Mtx)
{
  DeleteCriticalSection(lpCriticalSection: _Mtx);
}

//------------------------------------------------------------------------------
// Address: 0x104611C7
// Name: __Mtxlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Mtxlock(_RTL_CRITICAL_SECTION *_Mtx)
{
  EnterCriticalSection(lpCriticalSection: _Mtx);
}

//------------------------------------------------------------------------------
// Address: 0x104611D7
// Name: __Mtxunlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Mtxunlock(_RTL_CRITICAL_SECTION *_Mtx)
{
  LeaveCriticalSection(lpCriticalSection: _Mtx);
}

//------------------------------------------------------------------------------
// Address: 0x104611E7
// Name: void _Atexit(void (*)(void))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Atexit(void (__cdecl *pf)())
{
  if ( atcount_cdecl == 0 )
    abort();
  --atcount_cdecl;
  *(&atfuns_cdecl + atcount_cdecl) = EncodePointer(Ptr: pf);
}

//------------------------------------------------------------------------------
// Address: 0x10461219
// Name: public: _Init_atexit::~_Init_atexit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _Init_atexit::~_Init_atexit(_Init_atexit *this)
{
  void *v1; // eax
  void (*v2)(void); // eax

  while ( atcount_cdecl < 0xA )
  {
    v1 = *(&atfuns_cdecl + atcount_cdecl++);
    v2 = (void (*)(void))DecodePointer(Ptr: v1);
    if ( v2 != nullptr )
      v2();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10461244
// Name: _ReleaseCPLocHash
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ReleaseCPLocHash()
{
  volatile LONG *v0; // ebx
  localeinfo_struct **v1; // esi
  localeinfo_struct *v2; // edi

  v0 = &CPLocHash;
  do
  {
    v1 = (localeinfo_struct **)InterlockedExchange(Target: v0, Value: 0);
    if ( v1 != nullptr )
    {
      do
      {
        v2 = *v1;
        _free_locale(plocinfo: v1[2]);
        free(pMem: v1);
        v1 = (localeinfo_struct **)v2;
      }
      while ( v2 != nullptr );
    }
    ++v0;
  }
  while ( (int)v0 < (int)&vec2_origin_394 );
}

//------------------------------------------------------------------------------
// Address: 0x10461284
// Name: _InitCPLocHash
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl InitCPLocHash()
{
  return atexit(func: ReleaseCPLocHash) != 0 ? 0x18 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x10461298
// Name: GdipFree(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipFree(int a1)
{
  return __imp__GdipFree@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1046129E
// Name: GdipAlloc(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipAlloc(int a1)
{
  return __imp__GdipAlloc@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x104612A4
// Name: GdipDeleteGraphics(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipDeleteGraphics(int a1)
{
  return __imp__GdipDeleteGraphics@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x104612AA
// Name: GdipDisposeImage(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipDisposeImage(int a1)
{
  return __imp__GdipDisposeImage@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x104612B0
// Name: GdipCreateBitmapFromHBITMAP(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipCreateBitmapFromHBITMAP(int a1, int a2, int a3)
{
  return __imp__GdipCreateBitmapFromHBITMAP@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x104612B6
// Name: GdiplusStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdiplusStartup(int a1, int a2, int a3)
{
  return __imp__GdiplusStartup@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x104612BC
// Name: GdiplusShutdown(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdiplusShutdown(int a1)
{
  return __imp__GdiplusShutdown@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x104612C2
// Name: GdipCreateFromHDC(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipCreateFromHDC(int a1, int a2)
{
  return __imp__GdipCreateFromHDC@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x104612C8
// Name: GdipSetInterpolationMode(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipSetInterpolationMode(int a1, int a2)
{
  return __imp__GdipSetInterpolationMode@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x104612CE
// Name: GdipDrawImageRectI(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipDrawImageRectI(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return __imp__GdipDrawImageRectI@24(a1, a2, a3, a4, a5, a6);
}

//------------------------------------------------------------------------------
// Address: 0x104612D4
// Name: GdipCloneImage(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipCloneImage(int a1, int a2)
{
  return __imp__GdipCloneImage@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x104612DA
// Name: GdipGetImageWidth(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipGetImageWidth(int a1, int a2)
{
  return __imp__GdipGetImageWidth@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x104612E0
// Name: GdipGetImageHeight(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipGetImageHeight(int a1, int a2)
{
  return __imp__GdipGetImageHeight@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x104612E6
// Name: GdipGetImagePixelFormat(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipGetImagePixelFormat(int a1, int a2)
{
  return __imp__GdipGetImagePixelFormat@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x104612EC
// Name: GdipGetImagePaletteSize(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipGetImagePaletteSize(int a1, int a2)
{
  return __imp__GdipGetImagePaletteSize@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x104612F2
// Name: GdipGetImagePalette(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipGetImagePalette(int a1, int a2, int a3)
{
  return __imp__GdipGetImagePalette@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x104612F8
// Name: GdipCreateBitmapFromStream(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipCreateBitmapFromStream(int a1, int a2)
{
  return __imp__GdipCreateBitmapFromStream@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x104612FE
// Name: GdipCreateBitmapFromScan0(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipCreateBitmapFromScan0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return __imp__GdipCreateBitmapFromScan0@24(a1, a2, a3, a4, a5, a6);
}

//------------------------------------------------------------------------------
// Address: 0x10461304
// Name: GdipBitmapLockBits(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipBitmapLockBits(int a1, int a2, int a3, int a4, int a5)
{
  return __imp__GdipBitmapLockBits@20(a1, a2, a3, a4, a5);
}

//------------------------------------------------------------------------------
// Address: 0x1046130A
// Name: GdipBitmapUnlockBits(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipBitmapUnlockBits(int a1, int a2)
{
  return __imp__GdipBitmapUnlockBits@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10461310
// Name: GdipGetImageGraphicsContext(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipGetImageGraphicsContext(int a1, int a2)
{
  return __imp__GdipGetImageGraphicsContext@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10461316
// Name: GdipDrawImageI(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GdipDrawImageI(int a1, int a2, int a3, int a4)
{
  return __imp__GdipDrawImageI@16(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x1046131C
// Name: CreateStdAccessibleObject(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HRESULT __stdcall CreateStdAccessibleObject(HWND hwnd, LONG idObject, const IID *const riid, void **ppvObject)
{
  return __imp__CreateStdAccessibleObject@16(hwnd, idObject, riid, ppvObject);
}

//------------------------------------------------------------------------------
// Address: 0x10461322
// Name: AccessibleObjectFromWindow(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HRESULT __stdcall AccessibleObjectFromWindow(HWND hwnd, DWORD dwId, const IID *const riid, void **ppvObject)
{
  return __imp__AccessibleObjectFromWindow@16(hwnd, dwId, riid, ppvObject);
}

//------------------------------------------------------------------------------
// Address: 0x10461328
// Name: LresultFromObject(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
LONG_PTR __stdcall LresultFromObject(const IID *const riid, WPARAM wParam, LPUNKNOWN punk)
{
  return __imp__LresultFromObject@12(riid, wParam, punk);
}

//------------------------------------------------------------------------------
// Address: 0x1046132E
// Name: ImmReleaseContext(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall ImmReleaseContext(HWND a1, HIMC a2)
{
  return __imp__ImmReleaseContext@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10461334
// Name: ImmGetOpenStatus(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall ImmGetOpenStatus(HIMC a1)
{
  return __imp__ImmGetOpenStatus@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1046133A
// Name: ImmGetContext(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HIMC __stdcall ImmGetContext(HWND a1)
{
  return __imp__ImmGetContext@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10461340
// Name: ReuseDDElParam(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
LPARAM __stdcall ReuseDDElParam(LPARAM lParam, UINT msgIn, UINT msgOut, UINT_PTR uiLo, UINT_PTR uiHi)
{
  return __imp__ReuseDDElParam@20(lParam, msgIn, msgOut, uiLo, uiHi);
}

//------------------------------------------------------------------------------
// Address: 0x10461346
// Name: UnpackDDElParam(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall UnpackDDElParam(UINT msg, LPARAM lParam, PUINT_PTR puiLo, PUINT_PTR puiHi)
{
  return __imp__UnpackDDElParam@16(msg, lParam, puiLo, puiHi);
}

//------------------------------------------------------------------------------
// Address: 0x1046134C
// Name: GetProcessMemoryInfo(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GetProcessMemoryInfo(int a1, int a2, int a3)
{
  return __imp__GetProcessMemoryInfo@12(a1, a2, a3);
}
