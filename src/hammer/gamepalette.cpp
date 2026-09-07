// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/gamepalette.cpp
// Functions: 68
// ============================================================

#include "hammer\gamepalette.h"

//------------------------------------------------------------------------------
// Address: 0x10038290
// Name: public: void std::basic_ios<char,struct std::char_traits<char>>::setstate(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ios::setstate(std::ios *this, int _State, bool _Reraise)
{
  int v3; // eax

  if ( _State != 0 )
  {
    v3 = _State | this->_Mystate;
    if ( this->_Mystrbuf == nullptr )
      LOBYTE(v3) = v3 | 4;
    std::ios_base::clear(this, _State: v3, _Reraise);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038340
// Name: class std::ctype<char> const __near & std::use_facet<class std::ctype<char>>(class std::locale const __near &)
// Source: json
//------------------------------------------------------------------------------
const std::ctype<char> *__cdecl std::use_facet<std::ctype<char>>(const std::locale *_Loc)
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
  _Psave = std::_Facetptr<std::ctype<char>>::_Psave;
  if ( std::ctype<char>::id._Id == 0 )
  {
    std::_Lockit::_Lockit(this: &v9, kind: 0);
    LOBYTE(v11) = 1;
    if ( std::ctype<char>::id._Id == 0 )
      std::ctype<char>::id._Id = ++std::locale::id::_Id_cnt;
    LOBYTE(v11) = 0;
    std::_Lockit::~_Lockit(this: &v9);
  }
  Id = std::ctype<char>::id._Id;
  Ptr = _Loc->_Ptr;
  if ( std::ctype<char>::id._Id >= _Loc->_Ptr->_Facetcount )
  {
    v3 = nullptr;
  }
  else
  {
    v3 = Ptr->_Facetvec[std::ctype<char>::id._Id];
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
    if ( std::ctype<char>::_Getcat(_Ppf: (std::ctype<char> **)&_Psave, _Ploc: _Loc) == -1 )
    {
      std::bad_cast::bad_cast(this: &pExceptionObject, _Message: "bad cast");
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_cast_std__);
    }
    v5 = (std::locale::facet *)_Psave;
    std::_Facetptr<std::ctype<char>>::_Psave = _Psave;
    std::locale::facet::_Incref(this: (std::locale::facet *)_Psave);
    std::locale::facet::_Facet_Register(_This: v5);
  }
LABEL_17:
  v11 = -1;
  std::_Lockit::~_Lockit(this: &_Lock);
  return (const std::ctype<char> *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10039440
// Name: public: virtual std::codecvt_base::~codecvt_base(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::codecvt_base::~codecvt_base(std::codecvt_base *this)
{
  this->__vftable = (std::codecvt_base_vtbl *)&std::codecvt_base::`vftable';
  this->__vftable = (std::codecvt_base_vtbl *)&std::locale::facet::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100394E0
// Name: public: char std::ctype<char>::widen(char)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall std::ctype<char>::widen(std::ctype<char> *this, int _Byte)
{
  return this->do_widen_2(this, a2: _Byte);
}

//------------------------------------------------------------------------------
// Address: 0x100394F0
// Name: public: bool std::ios_base::eof(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::ios_base::eof(std::ios_base *this)
{
  return this->_Mystate & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10039500
// Name: public: virtual std::ios_base::~ios_base(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ios_base::~ios_base(std::ios_base *this)
{
  this->__vftable = (std::ios_base_vtbl *)&std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(_This: this);
}

//------------------------------------------------------------------------------
// Address: 0x10039540
// Name: public: virtual std::basic_ios<char,struct std::char_traits<char>>::~basic_ios<char,struct std::char_traits<char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ios::~ios<char,std::char_traits<char>>(std::ios *this)
{
  this->__vftable = (std::ios_vtbl *)&std::ios::`vftable';
  this->__vftable = (std::ios_vtbl *)&std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(_This: this);
}

//------------------------------------------------------------------------------
// Address: 0x10039650
// Name: public: void CGamePalette::SetBrightness(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePalette::SetBrightness(CGamePalette *this, float fValue)
{
  int i; // edi
  tagPALETTEENTRY *v4; // eax
  float v5; // xmm0_4
  tagPALETTEENTRY *v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm0_4

  if ( fValue > 0.0 )
  {
    this->fBrightness = fValue;
    if ( fValue == 1.0 )
    {
      memcpy(
        dst: (unsigned __int8 *)this->pPalette,
        src: (unsigned __int8 *)this->pOriginalPalette,
        count: this->uPaletteBytes);
      SetPaletteEntries(
        hpal: (HPALETTE)this->GDIPalette.m_hObject,
        iStart: 0,
        cEntries: 0x100u,
        pPalEntries: this->pPalette->palPalEntry);
    }
    else
    {
      for ( i = 0; i < 256; ++i )
      {
        v4 = &this->pOriginalPalette->palPalEntry[i];
        v5 = (float)v4->peRed * this->fBrightness;
        v6 = &this->pPalette->palPalEntry[i];
        if ( v5 <= 255.0 )
        {
          if ( v5 < 0.0 )
            v5 = 0.0;
        }
        else
        {
          v5 = 255.0;
        }
        v6->peRed = (int)v5;
        v7 = (float)v4->peGreen * this->fBrightness;
        if ( v7 <= 255.0 )
        {
          if ( v7 < 0.0 )
            v7 = 0.0;
        }
        else
        {
          v7 = 255.0;
        }
        v6->peGreen = (int)v7;
        v8 = (float)v4->peBlue * this->fBrightness;
        if ( v8 <= 255.0 )
        {
          if ( v8 < 0.0 )
            v8 = 0.0;
        }
        else
        {
          v8 = 255.0;
        }
        v6->peBlue = (int)v8;
      }
      SetPaletteEntries(
        hpal: (HPALETTE)this->GDIPalette.m_hObject,
        iStart: 0,
        cEntries: 0x100u,
        pPalEntries: this->pPalette->palPalEntry);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039780
// Name: private: void std::basic_filebuf<char,struct std::char_traits<char>>::_Reset_back(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::filebuf::_Reset_back(std::filebuf *this)
{
  char **IGfirst; // edx
  char *Set_egptr; // eax

  IGfirst = this->_IGfirst;
  if ( *IGfirst == &this->_Mychar )
  {
    Set_egptr = this->_Set_egptr;
    *IGfirst = this->_Set_eback;
    *this->_IGnext = Set_egptr;
    *this->_IGcount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100398D0
// Name: protected: virtual int std::codecvt<char,char,int>::do_out(int __near &,char const __near *,char const __near *,char const __near * __near &,char __near *,char __near *,char __near * __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::codecvt<char,char,int>::do_out(
        std::codecvt<char,char,int> *this,
        int *__formal,
        const char *_First1,
        const char *a4,
        const char **_Mid1,
        char *_First2,
        char *a7,
        char **_Mid2)
{
  *_Mid1 = _First1;
  *_Mid2 = _First2;
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x100398F0
// Name: protected: virtual int std::codecvt<char,char,int>::do_unshift(int __near &,char __near *,char __near *,char __near * __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::codecvt<char,char,int>::do_unshift(
        std::codecvt<char,char,int> *this,
        int *__formal,
        char *_First2,
        char *a4,
        char **_Mid2)
{
  *_Mid2 = _First2;
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10039910
// Name: protected: virtual int std::codecvt<char,char,int>::do_length(int const __near &,char const __near *,char const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::codecvt<char,char,int>::do_length(
        std::codecvt<char,char,int> *this,
        const int *__formal,
        const char *_First1,
        const char *_Last1,
        unsigned int _Count)
{
  int result; // eax

  result = _Last1 - _First1;
  if ( _Count < _Last1 - _First1 )
    return _Count;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039990
// Name: protected: void std::ios_base::_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ios_base::_Init(std::ios_base *this)
{
  std::locale *v2; // ebx
  unsigned int Refs; // eax
  std::_Lockit v4; // [esp+Ch] [ebp-14h] BYREF
  std::locale::_Locimp *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  this->_Ploc = nullptr;
  this->_Stdstr = 0;
  this->_Except = 0;
  this->_Fmtfl = 513;
  this->_Prec = 6;
  this->_Wide = 0;
  this->_Arr = nullptr;
  this->_Calls = nullptr;
  std::ios_base::clear(this, _State: 0, _Reraise: false);
  v2 = (std::locale *)operator new(nSize: 4u);
  if ( v2 != nullptr )
  {
    v2->_Ptr = std::locale::_Init();
    v5 = std::locale::_Getgloballocale();
    std::_Lockit::_Lockit(this: &v4, kind: 0);
    v6 = 0;
    Refs = v5->_Refs;
    if ( Refs != -1 )
      v5->_Refs = Refs + 1;
    v6 = -1;
    std::_Lockit::~_Lockit(this: &v4);
    this->_Ploc = v2;
  }
  else
  {
    this->_Ploc = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039D50
// Name: protected: virtual class std::fpos<int> std::basic_streambuf<char,struct std::char_traits<char>>::seekoff(__int64,int,int)
// Source: json
//------------------------------------------------------------------------------
std::fpos<int> *__thiscall std::streambuf::seekoff(
        std::streambuf *this,
        std::fpos<int> *result,
        __int64 __formal,
        int a4,
        int a5)
{
  result->_Myoff = -1;
  result->_Fpos = 0;
  result->_Mystate = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039D80
// Name: protected: virtual class std::fpos<int> std::basic_streambuf<char,struct std::char_traits<char>>::seekpos(class std::fpos<int>,int)
// Source: json
//------------------------------------------------------------------------------
std::fpos<int> *__thiscall std::streambuf::seekpos(
        std::streambuf *this,
        std::fpos<int> *result,
        std::fpos<int> __formal,
        int a4)
{
  result->_Myoff = -1;
  result->_Fpos = 0;
  result->_Mystate = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039E50
// Name: public: char __near * std::allocator<char>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall std::allocator<char>::allocate(std::allocator<char> *this, unsigned int _Count)
{
  char *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-18h] BYREF
  int v4; // [esp+14h] [ebp-4h]

  result = nullptr;
  if ( _Count != 0 )
  {
    result = (char *)operator new(nSize: _Count);
    if ( result == nullptr )
    {
      _Count = 0;
      std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
      pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
      v4 = -1;
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039ED0
// Name: protected: void std::basic_filebuf<char,struct std::char_traits<char>>::_Init(struct _iobuf __near *,enum std::basic_filebuf<char,struct std::char_traits<char>>::_Initfl)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::filebuf::_Init(std::filebuf *this, _iobuf *_File, std::filebuf::_Initfl _Which)
{
  this->_IGfirst = &this->_Gfirst;
  this->_IGnext = &this->_Gnext;
  this->_IPnext = &this->_Pnext;
  this->_Closef = _Which == _Openfl;
  this->_IGcount = &this->_Gcount;
  this->_Wrotesome = false;
  this->_IPfirst = &this->_Pfirst;
  this->_IPcount = &this->_Pcount;
  this->_Pfirst = nullptr;
  *this->_IPnext = nullptr;
  *this->_IPcount = 0;
  *this->_IGfirst = nullptr;
  *this->_IGnext = nullptr;
  *this->_IGcount = 0;
  if ( _File != nullptr )
  {
    this->_IGfirst = &_File->_base;
    this->_IPfirst = &_File->_base;
    this->_IGnext = &_File->_ptr;
    this->_IPnext = &_File->_ptr;
    this->_IGcount = &_File->_cnt;
    this->_IPcount = &_File->_cnt;
  }
  this->_Myfile = _File;
  this->_State = `std::filebuf::_Init'::`2'::_Stinit;
  this->_Pcvt = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003A1B0
// Name: public: virtual void std::basic_filebuf<char,struct std::char_traits<char>>::_Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::filebuf::_Lock(std::filebuf *this)
{
  if ( this->_Myfile != nullptr )
    _lock_file(pf: this->_Myfile);
}

//------------------------------------------------------------------------------
// Address: 0x1003A1C0
// Name: public: virtual void std::basic_filebuf<char,struct std::char_traits<char>>::_Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::filebuf::_Unlock(std::filebuf *this)
{
  if ( this->_Myfile != nullptr )
    _unlock_file(pf: this->_Myfile);
}

//------------------------------------------------------------------------------
// Address: 0x1003A1D0
// Name: bool std::_Fputc<char>(char,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl std::_Fputc<char>(char _Byte, _iobuf *_File)
{
  return fputc(ch: _Byte, str: _File) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A1F0
// Name: protected: virtual int std::basic_filebuf<char,struct std::char_traits<char>>::underflow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::filebuf::underflow(std::filebuf *this)
{
  char *v2; // ecx
  int result; // eax
  int v4; // edi

  v2 = *this->_IGnext;
  if ( v2 != nullptr && v2 < &v2[*this->_IGcount] )
    return (unsigned __int8)*v2;
  result = this->uflow(this);
  v4 = result;
  if ( result != -1 )
  {
    this->pbackfail(this, a2: result);
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A240
// Name: protected: virtual int std::basic_filebuf<char,struct std::char_traits<char>>::sync(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::filebuf::sync(std::filebuf *this)
{
  if ( this->_Myfile == nullptr || this->overflow(this, a2: -1) == -1 || fflush(stream: this->_Myfile) >= 0 )
    return 0;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A270
// Name: private: void std::basic_filebuf<char,struct std::char_traits<char>>::_Set_back(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::filebuf::_Set_back(std::filebuf *this)
{
  char **IGfirst; // edx
  char *p_Mychar; // eax

  IGfirst = this->_IGfirst;
  p_Mychar = &this->_Mychar;
  if ( *IGfirst != &this->_Mychar )
  {
    this->_Set_eback = *IGfirst;
    this->_Set_egptr = &(*this->_IGnext)[*this->_IGcount];
  }
  *IGfirst = p_Mychar;
  *this->_IGnext = p_Mychar;
  *this->_IGcount = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A340
// Name: protected: virtual int std::basic_filebuf<char,struct std::char_traits<char>>::pbackfail(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::filebuf::pbackfail(std::filebuf *this, int _Meta)
{
  char *v3; // eax

  v3 = *this->_IGnext;
  if ( v3 != nullptr && *this->_IGfirst < v3 && (_Meta == -1 || (unsigned __int8)*(v3 - 1) == _Meta) )
  {
    ++*this->_IGcount;
    --*this->_IGnext;
    return _Meta != -1 ? _Meta : 0;
  }
  if ( this->_Myfile != nullptr && _Meta != -1 )
  {
    if ( this->_Pcvt == nullptr && ungetc(ch: (unsigned __int8)_Meta, stream: this->_Myfile) != -1 )
      return _Meta;
    if ( *(std::filebuf **)this->_IGnext != (std::filebuf *)&this->_Mychar )
    {
      this->_Mychar = _Meta;
      std::filebuf::_Set_back(this);
      return _Meta;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A430
// Name: public: char std::basic_ios<char,struct std::char_traits<char>>::widen(char)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall std::ios::widen(std::ios *this, int _Byte)
{
  const std::locale *v2; // eax
  std::locale::_Locimp *Ptr; // edi
  unsigned int Refs; // eax
  int v5; // esi
  void (__thiscall ***v6)(_DWORD, int); // esi
  const std::ctype<char> *_Ctype_fac; // [esp+4h] [ebp-18h]
  std::_Lockit v9; // [esp+8h] [ebp-14h] BYREF
  std::locale v10; // [esp+Ch] [ebp-10h] BYREF
  int v11; // [esp+18h] [ebp-4h]

  v2 = std::ios_base::getloc(this, result: &v10);
  v11 = 0;
  _Ctype_fac = std::use_facet<std::ctype<char>>(_Loc: v2);
  v11 = -1;
  Ptr = v10._Ptr;
  if ( v10._Ptr != nullptr )
  {
    std::_Lockit::_Lockit(this: &v9, kind: 0);
    v11 = 1;
    Refs = Ptr->_Refs;
    if ( Refs != 0 && Refs != -1 )
      Ptr->_Refs = Refs - 1;
    v5 = -(Ptr->_Refs == 0);
    v11 = -1;
    std::_Lockit::~_Lockit(this: &v9);
    v6 = (void (__thiscall ***)(_DWORD, int))((unsigned int)Ptr & v5);
    if ( v6 != nullptr )
      (**v6)(a1: v6, a2: 1);
  }
  return _Ctype_fac->do_widen_2(this: (std::ctype<char> *)_Ctype_fac, a2: _Byte);
}

//------------------------------------------------------------------------------
// Address: 0x1003A4E0
// Name: public: static unsigned int std::codecvt<char,char,int>::_Getcat(class std::locale::facet const __near * __near *,class std::locale const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl std::codecvt<char,char,int>::_Getcat(std::locale::facet **_Ppf, const std::locale *_Ploc)
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
    v3 = (std::locale::facet *)operator new(nSize: 8u);
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
      v3->__vftable = (std::locale::facet_vtbl *)&std::codecvt_base::`vftable';
      v9 = 3;
      v3->__vftable = (std::locale::facet_vtbl *)&std::codecvt<char,char,int>::`vftable';
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
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x1003A760
// Name: class std::codecvt<char,char,int> const __near & std::use_facet<class std::codecvt<char,char,int>>(class std::locale const __near &)
// Source: json
//------------------------------------------------------------------------------
const std::codecvt<char,char,int> *__cdecl std::use_facet<std::codecvt<char,char,int>>(const std::locale *_Loc)
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
  _Psave = std::_Facetptr<std::codecvt<char,char,int>>::_Psave;
  if ( std::codecvt<char,char,int>::id._Id == 0 )
  {
    std::_Lockit::_Lockit(this: &v9, kind: 0);
    LOBYTE(v11) = 1;
    if ( std::codecvt<char,char,int>::id._Id == 0 )
      std::codecvt<char,char,int>::id._Id = ++std::locale::id::_Id_cnt;
    LOBYTE(v11) = 0;
    std::_Lockit::~_Lockit(this: &v9);
  }
  Id = std::codecvt<char,char,int>::id._Id;
  Ptr = _Loc->_Ptr;
  if ( std::codecvt<char,char,int>::id._Id >= _Loc->_Ptr->_Facetcount )
  {
    v3 = nullptr;
  }
  else
  {
    v3 = Ptr->_Facetvec[std::codecvt<char,char,int>::id._Id];
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
    if ( std::codecvt<char,char,int>::_Getcat(_Ppf: (std::locale::facet **)&_Psave, _Ploc: _Loc) == -1 )
    {
      std::bad_cast::bad_cast(this: &pExceptionObject, _Message: "bad cast");
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_cast_std__);
    }
    v5 = (std::locale::facet *)_Psave;
    std::_Facetptr<std::codecvt<char,char,int>>::_Psave = _Psave;
    std::locale::facet::_Incref(this: (std::locale::facet *)_Psave);
    std::locale::facet::_Facet_Register(_This: v5);
  }
LABEL_17:
  v11 = -1;
  std::_Lockit::~_Lockit(this: &_Lock);
  return (const std::codecvt<char,char,int> *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x1003A880
// Name: protected: virtual int std::basic_filebuf<char,struct std::char_traits<char>>::uflow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::filebuf::uflow(std::filebuf *this)
{
  char **IGnext; // esi
  char *v3; // eax
  int result; // eax
  char **IGfirst; // ecx
  char *Set_egptr; // eax
  int i; // eax
  std::string *Ptr; // eax
  std::string *p_Str; // edx
  int v10; // eax
  std::string *v11; // eax
  std::string *v12; // eax
  std::string *v13; // edi
  signed int j; // edi
  int v15; // ecx
  int v16; // esi
  std::string _Str; // [esp+4h] [ebp-34h] BYREF
  char *_Dest; // [esp+20h] [ebp-18h] BYREF
  const char *_Src; // [esp+24h] [ebp-14h] BYREF
  char _Ch; // [esp+2Bh] [ebp-Dh] BYREF
  int v21; // [esp+2Ch] [ebp-Ch] BYREF
  int v22; // [esp+34h] [ebp-4h]

  if ( *this->_IGnext != nullptr && *this->_IGnext < &(*this->_IGnext)[*this->_IGcount] )
  {
    --*this->_IGcount;
    IGnext = this->_IGnext;
    v3 = (*IGnext)++;
    return (unsigned __int8)*v3;
  }
  else if ( this->_Myfile != nullptr )
  {
    IGfirst = this->_IGfirst;
    if ( *IGfirst == &this->_Mychar )
    {
      Set_egptr = this->_Set_egptr;
      *IGfirst = this->_Set_eback;
      *this->_IGnext = Set_egptr;
      *this->_IGcount = 0;
    }
    if ( this->_Pcvt != nullptr )
    {
      _Str._Myres = 15;
      _Str._Mysize = 0;
      _Str._Bx._Buf[0] = 0;
      v22 = 0;
      for ( i = fgetc(stream: this->_Myfile); i != -1; i = fgetc(stream: this->_Myfile) )
      {
        std::string::append(this: &_Str, _Count: 1u, _Ch: i);
        Ptr = (std::string *)_Str._Bx._Ptr;
        p_Str = (std::string *)_Str._Bx._Ptr;
        if ( _Str._Myres < 0x10 )
        {
          p_Str = &_Str;
          Ptr = &_Str;
        }
        v10 = this->_Pcvt->do_in(
                this: this->_Pcvt,
                a2: &this->_State,
                a3: (const char *)Ptr,
                a4: (char *)p_Str + _Str._Mysize,
                a5: &_Src,
                a6: &_Ch,
                a7: (char *)&v21,
                a8: &_Dest);
        if ( v10 < 0 )
          break;
        if ( v10 <= 1 )
        {
          if ( _Dest != &_Ch )
          {
            v13 = (std::string *)_Str._Bx._Ptr;
            if ( _Str._Myres < 0x10 )
              v13 = &_Str;
            for ( j = _Str._Mysize + (char *)v13 - _Src; j > 0; --j )
            {
              v15 = _Src[j - 1];
              ungetc(ch: v15, stream: this->_Myfile);
            }
            goto LABEL_32;
          }
          v12 = (std::string *)_Str._Bx._Ptr;
          if ( _Str._Myres < 0x10 )
            v12 = &_Str;
          std::string::erase(this: &_Str, _Off: 0, _Count: _Src - (const char *)v12);
        }
        else
        {
          if ( v10 != 3 )
            break;
          if ( _Str._Mysize != 0 )
          {
            v11 = (std::string *)_Str._Bx._Ptr;
            if ( _Str._Myres < 0x10 )
              v11 = &_Str;
            memcpy_s(dst: &_Ch, sizeInBytes: 1u, src: v11, count: 1u);
LABEL_32:
            v16 = (unsigned __int8)_Ch;
            v22 = -1;
            std::string::~string(this: &_Str);
            return v16;
          }
        }
      }
      v22 = -1;
      std::string::~string(this: &_Str);
      return -1;
    }
    else
    {
      result = fgetc(stream: this->_Myfile);
      if ( result == -1 )
        return -1;
      else
        return (unsigned __int8)result;
    }
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AAA0
// Name: protected: virtual void std::basic_filebuf<char,struct std::char_traits<char>>::imbue(class std::locale const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::filebuf::imbue(std::filebuf *this, const std::locale *_Loc)
{
  const std::codecvt<char,char,int> *v3; // esi

  v3 = std::use_facet<std::codecvt<char,char,int>>(_Loc);
  if ( v3->do_always_noconv(this: v3) )
  {
    this->_Pcvt = nullptr;
  }
  else
  {
    this->_Pcvt = v3;
    std::streambuf::_Init(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AAE0
// Name: public: class std::basic_filebuf<char,struct std::char_traits<char>> __near * std::basic_filebuf<char,struct std::char_traits<char>>::open(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
std::filebuf *__thiscall std::filebuf::open(std::filebuf *this, const char *_Filename, int _Mode, int _Prot)
{
  _iobuf *v5; // eax
  const std::locale *v6; // eax
  const std::codecvt<char,char,int> *v7; // edi

  if ( this->_Myfile != nullptr )
    return nullptr;
  v5 = std::_Fiopen(filename: _Filename, mode: _Mode, prot: _Prot);
  if ( v5 == nullptr )
    return nullptr;
  std::filebuf::_Init(this, _File: v5, _Which: _Openfl);
  v6 = std::streambuf::getloc(this, result: (std::locale *)&_Prot);
  v7 = std::use_facet<std::codecvt<char,char,int>>(_Loc: v6);
  if ( v7->do_always_noconv(this: v7) )
  {
    this->_Pcvt = nullptr;
  }
  else
  {
    this->_Pcvt = v7;
    std::streambuf::_Init(this);
  }
  std::locale::~locale(this: (std::locale *)&_Prot);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003ABA0
// Name: protected: bool std::basic_filebuf<char,struct std::char_traits<char>>::_Endwrite(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall std::filebuf::_Endwrite(std::filebuf *this)
{
  std::string *Ptr; // eax
  unsigned int Myres; // ebx
  std::string *p_Str; // edx
  int v6; // eax
  int v7; // eax
  std::string *v8; // ecx
  char *v9; // esi
  std::string _Str; // [esp+8h] [ebp-2Ch] BYREF
  char *_Dest; // [esp+24h] [ebp-10h] BYREF
  int v12; // [esp+30h] [ebp-4h]

  if ( this->_Pcvt == nullptr || !this->_Wrotesome )
    return 1;
  if ( this->overflow(this, a2: -1) == -1 )
    return 0;
  _Str._Myres = 15;
  memset(&_Str, 0, 9);
  _Str._Mysize = 8;
  v12 = 0;
LABEL_6:
  Ptr = (std::string *)_Str._Bx._Ptr;
  Myres = _Str._Myres;
  while ( 1 )
  {
    p_Str = Ptr;
    if ( Myres < 0x10 )
    {
      p_Str = &_Str;
      Ptr = &_Str;
    }
    v6 = this->_Pcvt->do_unshift(
           this: this->_Pcvt,
           a2: &this->_State,
           a3: (char *)Ptr,
           a4: (char *)p_Str + _Str._Mysize,
           a5: &_Dest);
    if ( v6 == 0 )
    {
      this->_Wrotesome = false;
      goto LABEL_14;
    }
    v7 = v6 - 1;
    if ( v7 != 0 )
      break;
LABEL_14:
    Myres = _Str._Myres;
    Ptr = (std::string *)_Str._Bx._Ptr;
    v8 = (std::string *)_Str._Bx._Ptr;
    if ( _Str._Myres < 0x10 )
      v8 = &_Str;
    v9 = (char *)(_Dest - (char *)v8);
    if ( _Dest != (char *)v8 )
    {
      if ( _Str._Myres < 0x10 )
        Ptr = &_Str;
      if ( v9 != (char *)fwrite(buffer: Ptr, size: 1u, count: (unsigned int)v9, stream: this->_Myfile) )
        goto LABEL_12;
      Myres = _Str._Myres;
      Ptr = (std::string *)_Str._Bx._Ptr;
    }
    if ( !this->_Wrotesome )
      goto LABEL_24;
    if ( v9 == nullptr )
    {
      std::string::append(this: &_Str, _Count: 8u, _Ch: 0);
      goto LABEL_6;
    }
  }
  if ( v7 != 2 )
  {
LABEL_12:
    v12 = -1;
    std::string::~string(this: &_Str);
    return 0;
  }
LABEL_24:
  v12 = -1;
  std::string::~string(this: &_Str);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003AD20
// Name: public: virtual CPalette::~CPalette(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPalette::~CPalette(CPalette *this)
{
  this->__vftable = (CPalette_vtbl *)&CPalette::`vftable';
  CGdiObject::~CGdiObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003AD60
// Name: public: CGamePalette::CGamePalette(void)
// Source: json
//------------------------------------------------------------------------------
CGamePalette *__thiscall CGamePalette::CGamePalette(CGamePalette *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_strFile; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  tagLOGPALETTE *v4; // edi
  tagLOGPALETTE *pPalette; // eax
  HPALETTE Palette; // eax

  this->GDIPalette.__vftable = (CPalette_vtbl *)&CGdiObject::`vftable';
  this->GDIPalette.m_hObject = nullptr;
  this->GDIPalette.__vftable = (CPalette_vtbl *)&CPalette::`vftable';
  p_strFile = &this->strFile;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  p_strFile->m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  this->fBrightness = 1.0;
  this->uPaletteBytes = 1032;
  v4 = (tagLOGPALETTE *)MemAlloc_Alloc(nSize: 0x408u);
  this->pPalette = v4;
  this->pOriginalPalette = (tagLOGPALETTE *)MemAlloc_Alloc(nSize: 0x408u);
  memset(dst: (unsigned __int8 *)v4, value: 0, count: 0x408u);
  memset(dst: (unsigned __int8 *)this->pOriginalPalette, value: 0, count: this->uPaletteBytes);
  pPalette = this->pPalette;
  if ( pPalette != nullptr && this->pOriginalPalette != nullptr )
  {
    pPalette->palVersion = 768;
    this->pPalette->palNumEntries = 256;
    this->pOriginalPalette->palVersion = 768;
    this->pOriginalPalette->palNumEntries = 256;
    Palette = CreatePalette(plpal: this->pPalette);
    CGdiObject::Attach(this: &this->GDIPalette, hObject: Palette);
  }
  else
  {
    AfxMessageBox(lpszText: "I couldn't allocate memory for the palette.", nType: 0, nIDHelp: 0);
    PostQuitMessage(nExitCode: -1);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003AEB0
// Name: public: CGamePalette::~CGamePalette(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePalette::~CGamePalette(CGamePalette *this)
{
  volatile signed __int32 *v2; // eax

  if ( this->pPalette != nullptr && this->pOriginalPalette != nullptr )
  {
    free(pMem: this->pPalette);
    free(pMem: this->pOriginalPalette);
  }
  v2 = (volatile signed __int32 *)(this->strFile.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  this->GDIPalette.__vftable = (CPalette_vtbl *)&CPalette::`vftable';
  CGdiObject::~CGdiObject(this: &this->GDIPalette);
}

//------------------------------------------------------------------------------
// Address: 0x1003AF60
// Name: protected: virtual int std::basic_filebuf<char,struct std::char_traits<char>>::overflow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::filebuf::overflow(std::filebuf *this, int _Meta)
{
  char *v4; // ecx
  int *IPcount; // eax
  char **IPnext; // esi
  char *v7; // eax
  char **IGfirst; // ecx
  char *Set_egptr; // eax
  std::string *Ptr; // eax
  unsigned int Myres; // ebx
  std::string *p_Str; // edx
  int v13; // eax
  std::string *v14; // ecx
  char *v15; // edi
  int v16; // esi
  std::string _Str; // [esp+8h] [ebp-34h] BYREF
  const char *_Src; // [esp+24h] [ebp-18h] BYREF
  char *_Dest; // [esp+28h] [ebp-14h] BYREF
  int _Ch; // [esp+2Ch] [ebp-10h] BYREF
  int v21; // [esp+38h] [ebp-4h]

  if ( _Meta == -1 )
    return 0;
  v4 = *this->_IPnext;
  if ( v4 != nullptr )
  {
    IPcount = this->_IPcount;
    if ( v4 < &v4[*IPcount] )
    {
      --*IPcount;
      IPnext = this->_IPnext;
      v7 = (*IPnext)++;
      *v7 = _Meta;
      return _Meta;
    }
  }
  if ( this->_Myfile == nullptr )
    return -1;
  IGfirst = this->_IGfirst;
  if ( *IGfirst == &this->_Mychar )
  {
    Set_egptr = this->_Set_egptr;
    *IGfirst = this->_Set_eback;
    *this->_IGnext = Set_egptr;
    *this->_IGcount = 0;
  }
  if ( this->_Pcvt == nullptr )
  {
    if ( fputc(ch: (char)_Meta, str: this->_Myfile) != -1 )
      return _Meta;
    return -1;
  }
  _Str._Myres = 15;
  memset(&_Str, 0, 9);
  LOBYTE(_Ch) = _Meta;
  _Str._Mysize = 8;
  v21 = 0;
LABEL_13:
  Ptr = (std::string *)_Str._Bx._Ptr;
  Myres = _Str._Myres;
  while ( 1 )
  {
    p_Str = Ptr;
    if ( Myres < 0x10 )
    {
      p_Str = &_Str;
      Ptr = &_Str;
    }
    v13 = this->_Pcvt->do_out(
            this: this->_Pcvt,
            a2: &this->_State,
            a3: (const char *)&_Ch,
            a4: (char *)&_Ch + 1,
            a5: &_Src,
            a6: (char *)Ptr,
            a7: (char *)p_Str + _Str._Mysize,
            a8: &_Dest);
    if ( v13 < 0 )
      goto LABEL_35;
    if ( v13 > 1 )
      break;
    Myres = _Str._Myres;
    Ptr = (std::string *)_Str._Bx._Ptr;
    v14 = (std::string *)_Str._Bx._Ptr;
    if ( _Str._Myres < 0x10 )
      v14 = &_Str;
    v15 = (char *)(_Dest - (char *)v14);
    if ( _Dest != (char *)v14 )
    {
      if ( _Str._Myres < 0x10 )
        Ptr = &_Str;
      if ( v15 != (char *)fwrite(buffer: Ptr, size: 1u, count: (unsigned int)v15, stream: this->_Myfile) )
        goto LABEL_35;
      Myres = _Str._Myres;
      Ptr = (std::string *)_Str._Bx._Ptr;
    }
    this->_Wrotesome = true;
    if ( _Src != (const char *)&_Ch )
    {
      v21 = -1;
      std::string::~string(this: &_Str);
      return _Meta;
    }
    if ( v15 == nullptr )
    {
      if ( _Str._Mysize < 0x20 )
      {
        std::string::append(this: &_Str, _Count: 8u, _Ch: 0);
        goto LABEL_13;
      }
      goto LABEL_35;
    }
  }
  if ( v13 != 3 )
  {
LABEL_35:
    v21 = -1;
    std::string::~string(this: &_Str);
    return -1;
  }
  if ( std::_Fputc<char>(_Byte: _Ch, _File: this->_Myfile) )
    v16 = _Meta;
  else
    v16 = -1;
  v21 = -1;
  std::string::~string(this: &_Str);
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x1003B1A0
// Name: protected: virtual class std::fpos<int> std::basic_filebuf<char,struct std::char_traits<char>>::seekoff(__int64,int,int)
// Source: json
//------------------------------------------------------------------------------
std::fpos<int> *__thiscall std::filebuf::seekoff(
        std::filebuf *this,
        std::fpos<int> *result,
        __int64 _Off,
        unsigned int _Way,
        int __formal)
{
  __int64 v6; // kr00_8
  char **IGfirst; // ecx
  char *Set_egptr; // eax
  int v10; // edx
  int State; // ecx

  if ( *(std::filebuf **)this->_IGnext == (std::filebuf *)&this->_Mychar && _Way == 1 && this->_Pcvt == nullptr )
    v6 = _Off - 1;
  else
    v6 = _Off;
  if ( this->_Myfile == nullptr
    || std::filebuf::_Endwrite(this) == 0
    || (v6 != 0 || _Way != 1) && _fseeki64(stream: this->_Myfile, offset: v6, whence: _Way) != 0
    || fgetpos(stream: this->_Myfile, pos: &_Off) != 0 )
  {
    result->_Myoff = -1;
    result->_Fpos = 0;
    result->_Mystate = 0;
    return result;
  }
  else
  {
    IGfirst = this->_IGfirst;
    if ( *IGfirst == &this->_Mychar )
    {
      Set_egptr = this->_Set_egptr;
      *IGfirst = this->_Set_eback;
      *this->_IGnext = Set_egptr;
      *this->_IGcount = 0;
    }
    v10 = HIDWORD(_Off);
    LODWORD(result->_Fpos) = _Off;
    State = this->_State;
    result->_Myoff = 0;
    HIDWORD(result->_Fpos) = v10;
    result->_Mystate = State;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B290
// Name: protected: virtual class std::fpos<int> std::basic_filebuf<char,struct std::char_traits<char>>::seekpos(class std::fpos<int>,int)
// Source: json
//------------------------------------------------------------------------------
std::fpos<int> *__thiscall std::filebuf::seekpos(
        std::filebuf *this,
        std::fpos<int> *result,
        std::fpos<int> _Pos,
        int __formal)
{
  int v6; // edx
  int State; // ecx
  __int64 _Fileposition; // [esp+Ch] [ebp-8h] BYREF

  _Fileposition = _Pos._Fpos;
  if ( this->_Myfile == nullptr
    || std::filebuf::_Endwrite(this) == 0
    || fsetpos(stream: this->_Myfile, pos: &_Fileposition) != 0
    || _Pos._Myoff != 0 && _fseeki64(stream: this->_Myfile, offset: _Pos._Myoff, whence: 1u) != 0
    || fgetpos(stream: this->_Myfile, pos: &_Fileposition) != 0 )
  {
    result->_Myoff = -1;
    result->_Fpos = 0;
    result->_Mystate = 0;
    return result;
  }
  else
  {
    this->_State = _Pos._Mystate;
    std::filebuf::_Reset_back(this);
    v6 = HIDWORD(_Fileposition);
    LODWORD(result->_Fpos) = _Fileposition;
    State = this->_State;
    result->_Myoff = 0;
    HIDWORD(result->_Fpos) = v6;
    result->_Mystate = State;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B370
// Name: public: class std::basic_filebuf<char,struct std::char_traits<char>> __near * std::basic_filebuf<char,struct std::char_traits<char>>::close(void)
// Source: json
//------------------------------------------------------------------------------
std::filebuf *__thiscall std::filebuf::close(std::filebuf *this)
{
  std::filebuf *v2; // edi
  int v3; // ecx

  v2 = this;
  if ( this->_Myfile == nullptr )
    goto LABEL_5;
  if ( std::filebuf::_Endwrite(this) == 0 )
    v2 = nullptr;
  if ( fclose(stream: this->_Myfile) != 0 )
LABEL_5:
    v2 = nullptr;
  this->_IGfirst = &this->_Gfirst;
  this->_Closef = false;
  this->_Wrotesome = false;
  this->_IGnext = &this->_Gnext;
  this->_IPnext = &this->_Pnext;
  this->_IPfirst = &this->_Pfirst;
  this->_IGcount = &this->_Gcount;
  this->_IPcount = &this->_Pcount;
  this->_Pfirst = nullptr;
  *this->_IPnext = nullptr;
  *this->_IPcount = 0;
  *this->_IGfirst = nullptr;
  *this->_IGnext = nullptr;
  *this->_IGcount = 0;
  this->_Myfile = nullptr;
  v3 = `std::filebuf::_Init'::`2'::_Stinit;
  this->_Pcvt = nullptr;
  this->_State = v3;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1003B460
// Name: public: virtual std::basic_filebuf<char,struct std::char_traits<char>>::~basic_filebuf<char,struct std::char_traits<char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::filebuf::~filebuf<char,std::char_traits<char>>(std::filebuf *this)
{
  char **IGfirst; // ecx
  char *Set_egptr; // eax

  this->__vftable = (std::filebuf_vtbl *)&std::filebuf::`vftable';
  if ( this->_Myfile != nullptr )
  {
    IGfirst = this->_IGfirst;
    if ( *IGfirst == &this->_Mychar )
    {
      Set_egptr = this->_Set_egptr;
      *IGfirst = this->_Set_eback;
      *this->_IGnext = Set_egptr;
      *this->_IGcount = 0;
    }
  }
  if ( this->_Closef )
    std::filebuf::close(this);
  std::streambuf::~streambuf<char,std::char_traits<char>>(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003B570
// Name: public: std::basic_ifstream<char,struct std::char_traits<char>>::basic_ifstream<char,struct std::char_traits<char>>(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
std::ifstream *__thiscall std::ifstream::ifstream(
        std::ifstream *this,
        const char *_Filename,
        int _Mode,
        int _Prot,
        int a5)
{
  int v6; // edx
  std::ios *v7; // esi
  int v8; // ecx
  int v9; // eax
  std::ios_base *v10; // ecx
  char v11; // al

  if ( a5 != 0 )
  {
    *(_DWORD *)this->gap0 = &std::ifstream::`vbtable';
    *(_DWORD *)this->gap68 = &std::ios_base::`vftable';
    *(_DWORD *)this->gap68 = &std::ios::`vftable';
  }
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)] = &std::istream::`vftable';
  v6 = *(_DWORD *)this->gap0;
  this->_Chcount = 0;
  v7 = (std::ios *)&this->gap0[*(_DWORD *)(v6 + 4)];
  std::ios_base::_Init(this: v7);
  v7->_Mystrbuf = (std::streambuf *)this->gap10;
  v7->_Tiestr = nullptr;
  v7->_Fillch = std::ios::widen(this: v7, _Byte: 32);
  if ( v7->_Mystrbuf == nullptr )
    std::ios_base::clear(this: v7, _State: LOBYTE(v7->_Mystate) | 4, _Reraise: false);
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)] = &std::ifstream::`vftable';
  std::streambuf::streambuf(this: (std::streambuf *)this->gap10);
  *(_DWORD *)&this->gap10[16] = &this->gap10[8];
  *(_DWORD *)this->gap10 = &std::filebuf::`vftable';
  this->_Filebuffer[8] = 0;
  this->_Filebuffer[1] = 0;
  *(_DWORD *)&this->gap10[32] = &this->gap10[24];
  *(_DWORD *)&this->gap10[36] = &this->gap10[28];
  *(_DWORD *)&this->gap10[20] = &this->gap10[12];
  *(_DWORD *)&this->gap10[48] = &this->gap10[40];
  *(_DWORD *)&this->gap10[52] = &this->gap10[44];
  *(_DWORD *)&this->gap10[12] = 0;
  **(_DWORD **)&this->gap10[36] = 0;
  **(_DWORD **)&this->gap10[52] = 0;
  **(_DWORD **)&this->gap10[16] = 0;
  **(_DWORD **)&this->gap10[32] = 0;
  **(_DWORD **)&this->gap10[48] = 0;
  *(_DWORD *)&this->_Filebuffer[12] = 0;
  *(_DWORD *)&this->_Filebuffer[4] = `std::filebuf::_Init'::`2'::_Stinit;
  *(_DWORD *)&this->gap10[68] = 0;
  if ( std::filebuf::open(this: (std::filebuf *)this->gap10, _Filename, _Mode: _Mode | 1, _Prot) == nullptr )
  {
    v8 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
    v9 = *(_DWORD *)&this->gap0[v8 + 12];
    v10 = (std::ios_base *)&this->gap0[v8];
    v11 = v9 | 2;
    if ( v10[1].__vftable == nullptr )
      v11 |= 4u;
    std::ios_base::clear(this: v10, _State: v11, _Reraise: false);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003B6F0
// Name: public: virtual std::basic_ifstream<char,struct std::char_traits<char>>::~basic_ifstream<char,struct std::char_traits<char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ifstream::~ifstream<char,std::char_traits<char>>(std::ifstream *this)
{
  std::filebuf *v1; // esi
  char **IGfirst; // ecx
  char *Set_egptr; // eax

  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 26) + 4) - 104) = &std::ifstream::`vftable';
  v1 = (std::filebuf *)((char *)this - 88);
  *((_DWORD *)this - 22) = &std::filebuf::`vftable';
  if ( *(_DWORD *)&this->gap10[-20] != 0 )
  {
    IGfirst = v1->_IGfirst;
    if ( *IGfirst == &v1->_Mychar )
    {
      Set_egptr = v1->_Set_egptr;
      *IGfirst = v1->_Set_eback;
      *v1->_IGnext = Set_egptr;
      *v1->_IGcount = 0;
    }
  }
  if ( v1->_Closef )
    std::filebuf::close(this: v1);
  std::streambuf::~streambuf<char,std::char_traits<char>>(this: v1);
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*(_DWORD *)&v1[-1]._Mychar + 4) - 16) = &std::istream::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10187870
// Name: private: static float half::overflow(void)
// Source: json
//------------------------------------------------------------------------------
static double __cdecl half::overflow()
{
  int v0; // eax
  float v2; // [esp-4h] [ebp-4h]

  v0 = 10;
  v2 = 1.0e10;
  do
  {
    --v0;
    v2 = v2 * v2;
  }
  while ( v0 != 0 );
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x103439EA
// Name: public: virtual struct CRuntimeClass __near * CPalette::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPalette::GetRuntimeClass(CPalette *this)
{
  return &CPalette::classCPalette;
}

//------------------------------------------------------------------------------
// Address: 0x103A4B02
// Name: public: int CPalette::GetEntryCount(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __thiscall CPalette::GetEntryCount(CPalette *this)
{
  CPalette *nEntries; // [esp+0h] [ebp-4h] OVERLAPPED BYREF

  nEntries = this;
  GetObjectA(h: this->m_hObject, c: 2, pv: &nEntries);
  return (unsigned __int16)nEntries;
}

//------------------------------------------------------------------------------
// Address: 0x1043A18F
// Name: __close
// Source: json
//------------------------------------------------------------------------------
int __cdecl _close(int fh)
{
  ioinfo **v2; // edi
  int v3; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v2 = &__pioinfo[fh >> 5], v3 = (fh & 0x1F) << 6, (*(&(*v2)->osfile + v3) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v2)->osfile + v3) & 1) != 0 )
  {
    r = _close_nolock(fh);
  }
  else
  {
    *_errno() = 9;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x10460B0F
// Name: public: void std::_Mutex::_Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Mutex::_Lock(std::_Mutex *this)
{
  _Mtxlock(_Mtx: (_RTL_CRITICAL_SECTION *)this->_Mtx);
}

//------------------------------------------------------------------------------
// Address: 0x10460B18
// Name: public: void std::_Mutex::_Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Mutex::_Unlock(std::_Mutex *this)
{
  _Mtxunlock(_Mtx: (_RTL_CRITICAL_SECTION *)this->_Mtx);
}

//------------------------------------------------------------------------------
// Address: 0x101878A0
// Name: private: static short half::convert(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static __int16 __cdecl half::convert(int a1)
{
  int v1; // edx
  int v2; // esi
  int v3; // eax
  int v4; // eax

  v1 = (unsigned __int8)(a1 >> 23) - 112;
  v2 = (a1 >> 16) & 0x8000;
  v3 = a1 & 0x7FFFFF;
  if ( (unsigned __int8)(a1 >> 23) > 0x70u )
  {
    if ( (unsigned __int8)(a1 >> 23) == 255 )
    {
      if ( v3 != 0 )
      {
        LOWORD(v3) = v2 | (v3 >> 13) | (v3 >> 13 == 0) | 0x7C00;
        return v3;
      }
    }
    else
    {
      if ( (a1 & 0x1000) != 0 )
      {
        v3 += 0x2000;
        if ( (v3 & 0x800000) != 0 )
        {
          v3 = 0;
          ++v1;
        }
      }
      if ( v1 <= 30 )
        return v2 | (v1 << 10) | (v3 >> 13);
      half::overflow();
    }
    LOWORD(v3) = v2 | 0x7C00;
    return v3;
  }
  if ( v1 >= -10 )
  {
    v4 = (v3 | 0x800000) >> (1 - v1);
    if ( (v4 & 0x1000) != 0 )
      v4 += 0x2000;
    return v2 | (v4 >> 13);
  }
  else
  {
    LOWORD(v3) = 0;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x103439F0
// Name: public: virtual struct CRuntimeClass __near * CRgn::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CRgn::GetRuntimeClass(CRgn *this)
{
  return &CRgn::classCRgn;
}

//------------------------------------------------------------------------------
// Address: 0x103439F6
// Name: void AfxThrowResourceException(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __noreturn AfxThrowResourceException()
{
  CResourceException *v0; // [esp+0h] [ebp-4h] BYREF

  v0 = &_simpleResourceException;
  _CxxThrowException(pExceptionObject: &v0, pThrowInfo: &_TI5PAVCResourceException__);
}

//------------------------------------------------------------------------------
// Address: 0x10343A12
// Name: void AfxThrowUserException(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __noreturn AfxThrowUserException()
{
  CUserException *v0; // [esp+0h] [ebp-4h] BYREF

  v0 = &_simpleUserException;
  _CxxThrowException(pExceptionObject: &v0, pThrowInfo: &_TI5PAVCUserException__);
}

//------------------------------------------------------------------------------
// Address: 0x103A4B1D
// Name: protected: virtual void CMFCColorButton::OnFillBackground(class CDC __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::OnFillBackground(CMFCColorButton *this, CDC *pDC, const CRect *rectClient)
{
  if ( CMFCColorButton::IsDrawXPTheme(this) != 0 )
    FillRect(hDC: pDC->m_hDC, lprc: rectClient, hbr: (HBRUSH)afxGlobalData.brWindow.m_hObject);
  else
    CMFCButton::OnFillBackground(this, pDC, rectClient);
}

//------------------------------------------------------------------------------
// Address: 0x103A4B57
// Name: protected: virtual void CMFCColorButton::OnShowColorPopup(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::OnShowColorPopup(CMFCColorButton *this)
{
  CMFCColorPopupMenu *m_pPopup; // eax
  CMFCColorPopupMenu *v3; // eax
  CMFCColorPopupMenu *v4; // eax
  int m_bEnabledInCustomizeMode; // ecx
  CMFCPopupMenuBar *v6; // eax
  CObject *v7; // eax
  CMFCColorPopupMenu *v8; // eax
  CMFCPopupMenuBar *v9; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-4Ch]
  tagRECT rectScreen; // [esp+14h] [ebp-30h] BYREF
  tagRECT Rect; // [esp+24h] [ebp-20h] BYREF
  int v13; // [esp+40h] [ebp-4h]

  m_pPopup = this->m_pPopup;
  if ( m_pPopup != nullptr )
  {
    SendMessageA(hWnd: m_pPopup->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
    this->m_pPopup = nullptr;
  }
  else
  {
    if ( this->m_Colors.m_nSize == 0 )
      CMFCColorBar::InitColors(pPalette: nullptr, arColors: &this->m_Colors);
    v3 = (CMFCColorPopupMenu *)operator new(nSize: 0x1EB8u);
    v13 = 0;
    if ( v3 != nullptr )
      v4 = CMFCColorPopupMenu::CMFCColorPopupMenu(
             this: v3,
             pParentBtn: this,
             colors: &this->m_Colors,
             color: this->m_Color,
             lpszAutoColor: this->m_strAutoColorText.m_pszData,
             lpszOtherColor: this->m_strOtherText.m_pszData,
             lpszDocColors: this->m_strDocColorsText.m_pszData,
             lstDocColors: &this->m_lstDocColors,
             nColumns: this->m_nColumns,
             colorAutomatic: this->m_ColorAutomatic);
    else
      v4 = nullptr;
    m_bEnabledInCustomizeMode = this->m_bEnabledInCustomizeMode;
    v13 = -1;
    this->m_pPopup = v4;
    v4->m_bEnabledInCustomizeMode = m_bEnabledInCustomizeMode;
    m_hWnd = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
    if ( this->m_pPopup->Create(
           this: this->m_pPopup,
           a2: this,
           a3: Rect.left,
           a4: Rect.bottom,
           a5: nullptr,
           a6: this->m_bEnabledInCustomizeMode,
           a7: 0) != 0 )
    {
      if ( this->m_bEnabledInCustomizeMode != 0 )
      {
        v6 = this->m_pPopup->GetMenuBar(this: this->m_pPopup);
        v7 = AfxDynamicDownCast(pClass: &CMFCColorBar::classCMFCColorBar, pObject: v6);
        if ( v7 != nullptr )
          v7[866].__vftable = (CObject_vtbl *)1;
      }
      v8 = this->m_pPopup;
      memset(&rectScreen, 0, sizeof(rectScreen));
      GetWindowRect(hWnd: v8->m_hWnd, lpRect: &rectScreen);
      CMFCPopupMenu::UpdateShadow(this: this->m_pPopup, lprectScreen: &rectScreen);
      if ( this->m_bAutoSetFocus != 0 )
      {
        v9 = this->m_pPopup->GetMenuBar(this: this->m_pPopup);
        CWnd::SetFocus(this: v9);
      }
    }
    else
    {
      this->m_pPopup = nullptr;
    }
    if ( this->m_bCaptured != 0 )
    {
      ReleaseCapture();
      this->m_bCaptured = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A4CE1
// Name: protected: void CMFCColorButton::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::OnKeyDown(
        CMFCColorButton *this,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  if ( nChar == 32 || nChar == 40 )
    this->OnShowColorPopup(this);
  else
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A4D05
// Name: protected: void CMFCColorButton::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::OnMouseMove(CMFCColorButton *this, unsigned int nFlags, CPoint point)
{
  CMFCButton::FlatStyle m_nFlatStyle; // edi

  m_nFlatStyle = this->m_nFlatStyle;
  if ( CMFCColorButton::IsDrawXPTheme(this) != 0 )
    this->m_nFlatStyle = BUTTONSTYLE_SEMIFLAT;
  CMFCButton::OnMouseMove(this, nFlags, point);
  this->m_nFlatStyle = m_nFlatStyle;
}

//------------------------------------------------------------------------------
// Address: 0x103A4D3A
// Name: public: void CMFCColorButton::SetColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::SetColor(CMFCColorButton *this, unsigned int color)
{
  HWND__ *m_hWnd; // eax

  this->m_Color = color;
  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
  {
    InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A4D6B
// Name: protected: virtual void CMFCColorButton::UpdateColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::UpdateColor(CMFCColorButton *this, unsigned int color)
{
  HWND Parent; // eax
  CWnd *v4; // ebx
  HWND__ *m_hWnd; // edi
  unsigned __int16 DlgCtrlID; // ax

  CMFCColorButton::SetColor(this, color);
  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  if ( v4 != nullptr )
  {
    m_hWnd = this->m_hWnd;
    DlgCtrlID = CWnd::GetDlgCtrlID(this);
    SendMessageA(hWnd: v4->m_hWnd, Msg: 0x111u, wParam: DlgCtrlID, lParam: (LPARAM)m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A4DB6
// Name: public: CMFCColorButton::CMFCColorButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCColorButton *__thiscall CMFCColorButton::CMFCColorButton(CMFCColorButton *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v3; // eax
  ATL::IAtlStringMgr *v4; // eax

  CMFCButton::CMFCButton(this);
  this->__vftable = (CMFCColorButton_vtbl *)&CMFCColorButton::`vftable';
  this->m_Colors.__vftable = (CArray<unsigned long,unsigned long>_vtbl *)&CArray<unsigned long,unsigned long>::`vftable';
  this->m_Colors.m_pData = nullptr;
  this->m_Colors.m_nGrowBy = 0;
  this->m_Colors.m_nMaxSize = 0;
  this->m_Colors.m_nSize = 0;
  CList<unsigned long,unsigned long>::CList<unsigned long,unsigned long>(this: &this->m_lstDocColors, nBlockSize: 10);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strOtherText, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strDocColorsText, pStringMgr: v3);
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strAutoColorText, pStringMgr: v4);
  this->m_ColorAutomatic = -1;
  this->m_nColumns = -1;
  this->m_Color = 0;
  this->m_pPopup = nullptr;
  this->m_pPalette = nullptr;
  this->m_bEnabledInCustomizeMode = 0;
  this->m_bAltColorDlg = 1;
  this->m_bAutoSetFocus = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A4E65
// Name: public: virtual CMFCColorButton::~CMFCColorButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::~CMFCColorButton(CMFCColorButton *this)
{
  CPalette *m_pPalette; // ecx

  this->__vftable = (CMFCColorButton_vtbl *)&CMFCColorButton::`vftable';
  m_pPalette = this->m_pPalette;
  if ( m_pPalette != nullptr )
    ((void (__thiscall *)(CPalette *, int))m_pPalette->dtr_CObject)(a1: m_pPalette, a2: 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strAutoColorText.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strDocColorsText.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strOtherText.m_pszData - 1);
  this->m_lstDocColors.__vftable = (CList<unsigned long,unsigned long>_vtbl *)&CList<unsigned long,unsigned long>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstDocColors);
  CArray<unsigned long,unsigned long>::~CArray<unsigned long,unsigned long>(this: &this->m_Colors);
  CMFCButton::~CMFCButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A4F14
// Name: protected: void CMFCColorButton::RebuildPalette(class CPalette __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::RebuildPalette(CMFCColorButton *this, CPalette *pPal)
{
  CPalette *m_pPalette; // ecx
  CPalette *v4; // eax
  LOGPALETTE *v5; // esi
  UINT EntryCount; // edi
  CPalette *v7; // ebx
  HPALETTE Palette; // eax
  CClientDC dc; // [esp+10h] [ebp-20h] BYREF
  int v10; // [esp+2Ch] [ebp-4h]

  m_pPalette = this->m_pPalette;
  if ( m_pPalette != nullptr )
    ((void (__thiscall *)(CPalette *, int))m_pPalette->dtr_CObject)(a1: m_pPalette, a2: 1);
  v4 = (CPalette *)operator new(nSize: 8u);
  if ( v4 != nullptr )
  {
    v4->m_hObject = nullptr;
    v4->__vftable = (CPalette_vtbl *)&CPalette::`vftable';
  }
  else
  {
    v4 = nullptr;
  }
  this->m_pPalette = v4;
  CClientDC::CClientDC(this: &dc, pWnd: this);
  v10 = 0;
  if ( pPal != nullptr )
  {
    EntryCount = CPalette::GetEntryCount(this: pPal);
    v5 = (LOGPALETTE *)operator new(nSize: 4 * EntryCount + 8);
    GetPaletteEntries(hpal: (HPALETTE)pPal->m_hObject, iStart: 0, cEntries: EntryCount, pPalEntries: v5->palPalEntry);
    v5->palVersion = 768;
    v5->palNumEntries = EntryCount;
  }
  else
  {
    v5 = (LOGPALETTE *)operator new(nSize: 0x408u);
    GetSystemPaletteEntries(hdc: dc.m_hDC, iStart: 0, cEntries: 0x100u, pPalEntries: v5->palPalEntry);
    *(_DWORD *)&v5->palVersion = 16777984;
  }
  v7 = this->m_pPalette;
  Palette = CreatePalette(plpal: v5);
  CGdiObject::Attach(this: v7, hObject: Palette);
  operator delete(p: v5);
  v10 = -1;
  CClientDC::~CClientDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x103A4FF7
// Name: protected: void CMFCColorButton::OnSysColorChange(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::OnSysColorChange(CMFCColorButton *this)
{
  CWnd::OnSysColorChange(this);
  CMFCColorButton::RebuildPalette(this, pPal: nullptr);
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x103A5022
// Name: protected: virtual void CMFCColorButton::OnDraw(class CDC __near *,class CRect const __near &,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::OnDraw(CMFCColorButton *this, CDC *pDC, CRect *rect, char uiState)
{
  bool v5; // zf
  CPalette *v6; // eax
  CMFCColorButton *v7; // edi
  unsigned int m_Color; // eax
  CBrush_vtbl *right; // ecx
  CMFCColorButton *v10; // esi
  CMFCColorButton_vtbl *v11; // eax
  CFont *v12; // edi
  CMFCVisualManager *Instance; // eax
  HDC__ *m_hDC; // [esp-4h] [ebp-68h]
  CSize sizeArrow; // [esp+Ch] [ebp-58h] BYREF
  CPalette *pCurPalette; // [esp+14h] [ebp-50h]
  CMFCColorButton *v17; // [esp+18h] [ebp-4Ch]
  unsigned int color; // [esp+1Ch] [ebp-48h]
  CRect rectArrowWinXP; // [esp+20h] [ebp-44h] BYREF
  CRect rectArrow; // [esp+30h] [ebp-34h] BYREF
  CRect rectColor; // [esp+40h] [ebp-24h] BYREF
  CBrush br; // [esp+50h] [ebp-14h] BYREF
  CBrush v23; // [esp+58h] [ebp-Ch] BYREF

  v5 = this->m_pPalette == nullptr;
  v17 = this;
  v23.m_hObject = rect;
  if ( v5 )
    CMFCColorButton::RebuildPalette(this, pPal: nullptr);
  v6 = CDC::SelectPalette(this: pDC, pPalette: this->m_pPalette, bForceBackground: false);
  m_hDC = pDC->m_hDC;
  pCurPalette = v6;
  RealizePalette(hdc: m_hDC);
  CMenuImages::Size(result: &sizeArrow);
  rectColor = *rect;
  rectArrow = *(CRect *)v23.m_hObject;
  rectColor.right += -8 - sizeArrow.cx;
  v7 = v17;
  m_Color = v17->m_Color;
  right = (CBrush_vtbl *)rectColor.right;
  rectArrow.left = rectColor.right;
  color = m_Color;
  if ( m_Color == -1 )
  {
    color = v17->m_ColorAutomatic;
    if ( *((_DWORD *)v17->m_strAutoColorText.m_pszData - 3) != 0 )
    {
      br = *(CBrush *)v23.m_hObject;
      v23 = *((CBrush *)v23.m_hObject + 1);
      v10 = v17;
      rectColor.right = rectColor.left + rectColor.bottom - rectColor.top;
      br.__vftable = (CBrush_vtbl *)rectColor.right;
      v11 = v17->__vftable;
      v23.__vftable = right;
      v12 = v11->SelectFont(this: v17, a2: pDC);
      if ( v12 == nullptr )
        AfxThrowInvalidArgException();
      CDC::SetBkMode(this: pDC, nBkMode: 1);
      pDC->SetTextColor(this: pDC, a2: afxGlobalData.clrBtnText);
      pDC->DrawTextA(
        this: pDC,
        a2: v10->m_strAutoColorText.m_pszData,
        a3: *((_DWORD *)v10->m_strAutoColorText.m_pszData - 3),
        a4: (tagRECT *)&br,
        a5: 32805u);
      pDC->SelectObject(this: pDC, a2: v12);
      v7 = v17;
    }
  }
  InflateRect(lprc: &rectColor, dx: -2, dy: -2);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectColor,
    clrTopLeft: afxGlobalData.clrBtnHilite,
    clrBottomRight: afxGlobalData.clrBtnHilite);
  InflateRect(lprc: &rectColor, dx: -1, dy: -1);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectColor,
    clrTopLeft: afxGlobalData.clrBtnDkShadow,
    clrBottomRight: afxGlobalData.clrBtnDkShadow);
  InflateRect(lprc: &rectColor, dx: -1, dy: -1);
  if ( color != -1 && (uiState & 4) == 0 )
  {
    if ( afxGlobalData.m_nBitsPerPixel == 8 )
      color = (unsigned __int16)GetNearestPaletteIndex(h: (HPALETTE)v7->m_pPalette->m_hObject, color) | 0x1000000;
    CBrush::CBrush(this: &v23, crColor: color);
    FillRect(hDC: pDC->m_hDC, lprc: &rectColor, hbr: (HBRUSH)v23.m_hObject);
    v23.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
    CGdiObject::~CGdiObject(this: &v23);
  }
  rectArrowWinXP = rectArrow;
  InflateRect(lprc: &rectArrowWinXP, dx: -2, dy: -2);
  if ( CMFCButton::m_bWinXPTheme == 0
    || (Instance = CMFCVisualManager::GetInstance(),
        ((int (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, int, int, int))Instance->DrawComboDropButtonWinXP)(
          a1: Instance,
          a2: pDC,
          a3: rectArrowWinXP.left,
          a4: rectArrowWinXP.top,
          a5: rectArrowWinXP.right,
          a6: rectArrowWinXP.bottom,
          a7: uiState & 4,
          a8: v17->m_bPushed,
          a9: v17->m_bHighlighted) == 0) )
  {
    FillRect(hDC: pDC->m_hDC, lprc: &rectArrow, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
    v23.__vftable = nullptr;
    v23.m_hObject = nullptr;
    CMenuImages::Draw(
      pDC,
      id: IdArrowDownLarge,
      rectImage: &rectArrow,
      state: (CMenuImages::IMAGE_STATE)((uiState & 4) != 0),
      sizeImageDest: (const CSize *)&v23);
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rectArrow,
      clrTopLeft: afxGlobalData.clrBtnLight,
      clrBottomRight: afxGlobalData.clrBtnDkShadow);
    InflateRect(lprc: &rectArrow, dx: -1, dy: -1);
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rectArrow,
      clrTopLeft: afxGlobalData.clrBtnHilite,
      clrBottomRight: afxGlobalData.clrBtnShadow);
  }
  if ( pCurPalette != nullptr )
    CDC::SelectPalette(this: pDC, pPalette: pCurPalette, bForceBackground: false);
}

//------------------------------------------------------------------------------
// Address: 0x103A52C2
// Name: public: void CMFCColorButton::EnableAutomaticButton(char const __near *,unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::EnableAutomaticButton(
        CMFCColorButton *this,
        const char *lpszLabel,
        unsigned int colorAutomatic,
        int bEnable)
{
  const char *v4; // eax

  v4 = lpszLabel;
  if ( bEnable != 0 && lpszLabel == nullptr )
    v4 = &var;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strAutoColorText, pszSrc: v4);
  this->m_ColorAutomatic = colorAutomatic;
}

//------------------------------------------------------------------------------
// Address: 0x103A52F6
// Name: public: void CMFCColorButton::EnableOtherButton(char const __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::EnableOtherButton(
        CMFCColorButton *this,
        const char *lpszLabel,
        int bAltColorDlg,
        int bEnable)
{
  const char *v4; // eax

  v4 = lpszLabel;
  if ( bEnable != 0 && lpszLabel == nullptr )
    v4 = &var;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strOtherText, pszSrc: v4);
  this->m_bAltColorDlg = bAltColorDlg;
}

//------------------------------------------------------------------------------
// Address: 0x103A532A
// Name: protected: long CMFCColorButton::OnInitControl(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorButton::OnInitControl(CMFCColorButton *this, unsigned int wParam, const char *lParam)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v5; // eax
  int v6; // eax
  CTagManager tagManager; // [esp+10h] [ebp-24h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDst; // [esp+18h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strColumnsCount; // [esp+1Ch] [ebp-18h] BYREF
  int bEnableAutomaticButton; // [esp+20h] [ebp-14h] BYREF
  int bEnableOtherButton[3]; // [esp+24h] [ebp-10h] BYREF
  int v13; // [esp+30h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strDst, pStringMgr: StringManager);
  v13 = 0;
  CMFCControlContainer::UTF8ToString(lpSrc: lParam, &strDst, nLength: wParam);
  CTagManager::CTagManager(this: &tagManager, lpszBuffer: strDst.m_pszData);
  LOBYTE(v13) = 1;
  bEnableOtherButton[0] = 0;
  if ( CMFCControlContainer::ReadBoolProp(
         &tagManager,
         lpszTag: "MFCColorButton_EnableOtherButton",
         bMember: bEnableOtherButton) != 0 )
  {
    if ( bEnableOtherButton[0] != 0 )
      CMFCColorButton::EnableOtherButton(this, lpszLabel: "Other", bAltColorDlg: 1, bEnable: bEnableOtherButton[0]);
    else
      CMFCColorButton::EnableOtherButton(this, lpszLabel: nullptr, bAltColorDlg: 1, bEnable: 0);
  }
  bEnableAutomaticButton = 0;
  if ( CMFCControlContainer::ReadBoolProp(
         &tagManager,
         lpszTag: "MFCColorButton_EnableAutomaticButton",
         bMember: &bEnableAutomaticButton) != 0 )
  {
    if ( bEnableAutomaticButton != 0 )
      CMFCColorButton::EnableAutomaticButton(
        this,
        lpszLabel: "Automatic",
        colorAutomatic: 0,
        bEnable: bEnableAutomaticButton);
    else
      CMFCColorButton::EnableAutomaticButton(this, lpszLabel: nullptr, colorAutomatic: 0, bEnable: 0);
  }
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strColumnsCount, pStringMgr: v5);
  LOBYTE(v13) = 2;
  if ( CTagManager::ExcludeTag(
         this: &tagManager,
         lpszTag: "MFCColorButton_ColumnsCount",
         strTag: &strColumnsCount,
         bIsCharsList: 0) != 0
    && *((_DWORD *)strColumnsCount.m_pszData - 3) != 0 )
  {
    v6 = atoi(nptr: strColumnsCount.m_pszData);
    if ( v6 > 0 )
      this->m_nColumns = v6;
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)strColumnsCount.m_pszData - 1);
  LOBYTE(v13) = 0;
  CTagManager::~CTagManager(this: &tagManager);
  ATL::CStringData::Release(this: (ATL::CStringData *)strDst.m_pszData - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A543D
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCColorButton::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCColorButton::GetMessageMap(CMFCColorButton *this)
{
  return (const AFX_MSGMAP *)&off_1068048C;
}

//------------------------------------------------------------------------------
// Address: 0x103A5443
// Name: public: virtual struct CRuntimeClass __near * CMFCButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCButton::GetRuntimeClass(CMFCButton *this)
{
  return &CMFCButton::classCMFCButton;
}

//------------------------------------------------------------------------------
// Address: 0x1043A253
// Name: __read_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _read_nolock(int fh, char *inputbuf, unsigned int cnt)
{
  unsigned int v3; // edx
  int result; // eax
  ioinfo **v5; // edi
  ioinfo *v6; // eax
  int v7; // esi
  char v8; // cl
  char *v9; // ebx
  char *v10; // ecx
  char *v11; // eax
  char v12; // cl
  bool v13; // zf
  ioinfo *v14; // ecx
  char v15; // cl
  ioinfo *v16; // ecx
  char v17; // cl
  ioinfo *v18; // ecx
  ioinfo *v19; // eax
  char *v20; // eax
  char *v21; // ebx
  char v22; // al
  char *v23; // eax
  char *v24; // ebx
  int v25; // ecx
  int v26; // eax
  char v27; // dl
  char *v28; // ebx
  int v29; // ebx
  DWORD LastError; // eax
  ioinfo *v31; // edx
  BOOL v32; // ecx
  char *v33; // ebx
  int v34; // ecx
  char *v35; // esi
  __int16 v36; // [esp-Ch] [ebp-2Ch]
  unsigned int inputsize; // [esp+4h] [ebp-1Ch]
  int os_read; // [esp+8h] [ebp-18h] BYREF
  int retval; // [esp+Ch] [ebp-14h]
  void *buf; // [esp+10h] [ebp-10h]
  int bytes_read; // [esp+14h] [ebp-Ch]
  wchar_t wpeekchr; // [esp+18h] [ebp-8h] BYREF
  char tmode; // [esp+1Eh] [ebp-2h]
  char peekchr; // [esp+1Fh] [ebp-1h] BYREF
  char *p; // [esp+30h] [ebp+10h]
  char *pa; // [esp+30h] [ebp+10h]

  v3 = cnt;
  retval = -2;
  inputsize = cnt;
  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  v5 = &__pioinfo[fh >> 5];
  v6 = *v5;
  v7 = (fh & 0x1F) << 6;
  v8 = *(&(*v5)->osfile + v7);
  if ( (v8 & 1) == 0 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_19:
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
    goto LABEL_18;
  bytes_read = 0;
  if ( cnt == 0 || (v8 & 2) != 0 )
    return 0;
  if ( inputbuf == nullptr )
    goto LABEL_18;
  tmode = (char)(2 * *((_BYTE *)v6 + v7 + 36)) >> 1;
  if ( tmode != 1 )
  {
    if ( tmode != 2 )
    {
LABEL_16:
      v9 = inputbuf;
      buf = inputbuf;
      goto LABEL_26;
    }
    if ( (cnt & 1) == 0 )
    {
      cnt &= ~1u;
      goto LABEL_16;
    }
LABEL_18:
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_19;
  }
  if ( (cnt & 1) != 0 )
    goto LABEL_18;
  cnt = 4;
  if ( v3 >> 1 >= 4 )
    cnt = v3 >> 1;
  v9 = (char *)MemAlloc_Alloc(nSize: cnt);
  buf = v9;
  if ( v9 == nullptr )
  {
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  *(_QWORD *)&(*v5)->pipech2[v7 + 3] = _lseeki64_nolock(fh, pos: 0, mthd: 1);
LABEL_26:
  v10 = (char *)*v5 + v7;
  v11 = v9;
  if ( (v10[4] & 0x48) != 0 )
  {
    v12 = v10[5];
    if ( v12 != 10 && cnt != 0 )
    {
      --cnt;
      v13 = tmode == 0;
      *v9 = v12;
      v14 = *v5;
      v11 = v9 + 1;
      bytes_read = 1;
      *(&v14->pipech + v7) = 10;
      if ( !v13 )
      {
        v15 = (*v5)->pipech2[v7];
        if ( v15 != 10 && cnt != 0 )
        {
          *v11 = v15;
          v16 = *v5;
          v11 = v9 + 2;
          --cnt;
          v13 = tmode == 1;
          bytes_read = 2;
          v16->pipech2[v7] = 10;
          if ( v13 )
          {
            v17 = (*v5)->pipech2[v7 + 1];
            if ( v17 != 10 && cnt != 0 )
            {
              *v11 = v17;
              v18 = *v5;
              v11 = v9 + 3;
              --cnt;
              bytes_read = 3;
              v18->pipech2[v7 + 1] = 10;
            }
          }
        }
      }
    }
  }
  if ( !ReadFile(
          hFile: *(HANDLE *)((char *)&(*v5)->osfhnd + v7),
          lpBuffer: v11,
          nNumberOfBytesToRead: cnt,
          lpNumberOfBytesRead: (LPDWORD)&os_read,
          lpOverlapped: nullptr)
    || os_read < 0
    || os_read > cnt )
  {
    LastError = GetLastError();
    if ( LastError == 5 )
    {
      *_errno() = 9;
      *__doserrno() = 5;
      goto LABEL_93;
    }
    if ( LastError == 109 )
    {
      retval = 0;
      goto error_return;
    }
    goto LABEL_92;
  }
  v19 = *v5;
  bytes_read += os_read;
  v20 = &v19->osfile + v7;
  if ( *v20 < 0 )
  {
    if ( tmode != 2 )
    {
      if ( os_read != 0 && *v9 == 10 )
        *v20 |= 4u;
      else
        *v20 &= ~4u;
      v21 = (char *)buf;
      p = (char *)buf;
      bytes_read += (int)buf;
      if ( (unsigned int)buf < bytes_read )
      {
        do
        {
          v22 = *p;
          if ( *p == 26 )
          {
            v23 = &(*v5)->osfile + v7;
            if ( (*v23 & 0x40) != 0 )
              *v21++ = *p;
            else
              *v23 |= 2u;
            break;
          }
          if ( v22 == 13 )
          {
            if ( (unsigned int)p < bytes_read - 1 )
            {
              if ( p[1] == 10 )
              {
                p += 2;
                goto LABEL_52;
              }
              ++p;
LABEL_63:
              *v21 = 13;
LABEL_64:
              ++v21;
              continue;
            }
            ++p;
            if ( !ReadFile(
                    hFile: *(HANDLE *)((char *)&(*v5)->osfhnd + v7),
                    lpBuffer: &peekchr,
                    nNumberOfBytesToRead: 1u,
                    lpNumberOfBytesRead: (LPDWORD)&os_read,
                    lpOverlapped: nullptr)
              && GetLastError() != 0
              || os_read == 0 )
            {
              goto LABEL_63;
            }
            if ( (*(&(*v5)->osfile + v7) & 0x48) != 0 )
            {
              if ( peekchr != 10 )
              {
                *v21 = 13;
                *(&(*v5)->pipech + v7) = peekchr;
                goto LABEL_64;
              }
LABEL_52:
              *v21 = 10;
              goto LABEL_64;
            }
            if ( v21 == buf && peekchr == 10 )
              goto LABEL_52;
            _lseeki64_nolock(fh, pos: -1, mthd: 1);
            if ( peekchr != 10 )
              goto LABEL_63;
          }
          else
          {
            *v21++ = v22;
            ++p;
          }
        }
        while ( (unsigned int)p < bytes_read );
      }
      bytes_read = v21 - (_BYTE *)buf;
      if ( tmode != 1 || v21 == buf )
        goto error_return;
      v24 = v21 - 1;
      LOBYTE(v25) = *v24;
      if ( *v24 < 0 )
      {
        v26 = 1;
        v25 = (unsigned __int8)v25;
        while ( _lookuptrailbytes[v25] == 0 && v26 <= 4 && v24 >= buf )
        {
          v25 = (unsigned __int8)*--v24;
          ++v26;
        }
        v27 = *v24;
        if ( _lookuptrailbytes[(unsigned __int8)*v24] == 0 )
        {
          *_errno() = 42;
LABEL_93:
          retval = -1;
          goto error_return;
        }
        if ( _lookuptrailbytes[(unsigned __int8)*v24] + 1 == v26 )
        {
          v24 += v26;
        }
        else if ( (*(&(*v5)->osfile + v7) & 0x48) != 0 )
        {
          v28 = v24 + 1;
          *(&(*v5)->pipech + v7) = v27;
          if ( v26 >= 2 )
            (*v5)->pipech2[v7] = *v28++;
          if ( v26 == 3 )
            (*v5)->pipech2[v7 + 1] = *v28++;
          v24 = &v28[-v26];
        }
        else
        {
          _lseeki64_nolock(fh, pos: -v26, mthd: 1);
        }
      }
      else
      {
        ++v24;
      }
      v29 = v24 - (_BYTE *)buf;
      bytes_read = MultiByteToWideChar(
                     CodePage: 0xFDE9u,
                     dwFlags: 0,
                     lpMultiByteStr: (LPCCH)buf,
                     cbMultiByte: v29,
                     lpWideCharStr: (LPWSTR)inputbuf,
                     cchWideChar: inputsize >> 1);
      if ( bytes_read != 0 )
      {
        v31 = *v5;
        v32 = bytes_read != v29;
        bytes_read *= 2;
        *(int *)((char *)&v31->utf8translations + v7) = v32;
        goto error_return;
      }
      LastError = GetLastError();
LABEL_92:
      _dosmaperr(oserrno: LastError);
      goto LABEL_93;
    }
    if ( os_read != 0 && *(_WORD *)v9 == 10 )
      *v20 |= 4u;
    else
      *v20 &= ~4u;
    v33 = (char *)buf;
    pa = (char *)buf;
    bytes_read += (int)buf;
    if ( (unsigned int)buf >= bytes_read )
    {
LABEL_129:
      bytes_read = v33 - (_BYTE *)buf;
      goto error_return;
    }
    while ( 1 )
    {
      v34 = *(unsigned __int16 *)pa;
      if ( v34 == 26 )
      {
        v35 = &(*v5)->osfile + v7;
        if ( (*v35 & 0x40) != 0 )
        {
          *(_WORD *)v33 = *(_WORD *)pa;
          v33 += 2;
        }
        else
        {
          *v35 |= 2u;
        }
        goto LABEL_129;
      }
      if ( v34 == 13 )
      {
        if ( (unsigned int)pa < bytes_read - 2 )
        {
          if ( *((_WORD *)pa + 1) == 10 )
          {
            pa += 4;
            goto LABEL_110;
          }
          pa += 2;
LABEL_121:
          v36 = 13;
LABEL_122:
          *(_WORD *)v33 = v36;
          goto LABEL_123;
        }
        pa += 2;
        if ( !ReadFile(
                hFile: *(HANDLE *)((char *)&(*v5)->osfhnd + v7),
                lpBuffer: &wpeekchr,
                nNumberOfBytesToRead: 2u,
                lpNumberOfBytesRead: (LPDWORD)&os_read,
                lpOverlapped: nullptr)
          && GetLastError() != 0
          || os_read == 0 )
        {
          goto LABEL_121;
        }
        if ( (*(&(*v5)->osfile + v7) & 0x48) != 0 )
        {
          if ( wpeekchr != 10 )
          {
            *(_WORD *)v33 = 13;
            *(&(*v5)->pipech + v7) = wpeekchr;
            (*v5)->pipech2[v7] = HIBYTE(wpeekchr);
            (*v5)->pipech2[v7 + 1] = 10;
LABEL_123:
            v33 += 2;
            goto LABEL_124;
          }
LABEL_110:
          v36 = 10;
          goto LABEL_122;
        }
        if ( v33 == buf && wpeekchr == 10 )
          goto LABEL_110;
        _lseeki64_nolock(fh, pos: -2, mthd: 1);
        if ( wpeekchr != 10 )
          goto LABEL_121;
      }
      else
      {
        *(_WORD *)v33 = v34;
        v33 += 2;
        pa += 2;
      }
LABEL_124:
      if ( (unsigned int)pa >= bytes_read )
        goto LABEL_129;
    }
  }
error_return:
  if ( buf != inputbuf )
    free(pMem: buf);
  result = retval;
  if ( retval == -2 )
    return bytes_read;
  return result;
}
