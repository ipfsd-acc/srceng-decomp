// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/prefabs.cpp
// Functions: 85
// ============================================================

#include "hammer\prefabs.h"

//------------------------------------------------------------------------------
// Address: 0x100372C0
// Name: public: std::basic_ostream<char,struct std::char_traits<char>>::sentry::operator int __near std::_Bool_struct::*(void)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall std::ostream::sentry::operator int std::_Bool_struct::*(std::ostream::sentry *this)
{
  return (int *)(this->_Ok - 1);
}

//------------------------------------------------------------------------------
// Address: 0x100372D0
// Name: public: std::basic_ostream<char,struct std::char_traits<char>>::_Sentry_base::~_Sentry_base(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ostream::_Sentry_base::~_Sentry_base(std::ostream::_Sentry_base *this)
{
  int v1; // eax

  v1 = *(_DWORD *)&this->_Myostr->gap0[*(_DWORD *)(*(_DWORD *)this->_Myostr + 4) + 56];
  if ( v1 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10038460
// Name: public: class std::basic_ostream<char,struct std::char_traits<char>> __near & std::basic_ostream<char,struct std::char_traits<char>>::flush(void)
// Source: json
//------------------------------------------------------------------------------
std::ostream *__thiscall std::ostream::flush(std::ostream *this)
{
  int v2; // eax
  int v3; // edi
  std::ios_base *v4; // ecx
  int v5; // eax

  v2 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
  v3 = 0;
  if ( (this->gap0[v2 + 12] & 6) == 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this->gap0[v2 + 56] + 52))(a1: *(_DWORD *)&this->gap0[v2 + 56]) == -1 )
  {
    v3 = 4;
  }
  v4 = (std::ios_base *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)];
  if ( v3 != 0 )
  {
    v5 = v3 | v4->_Mystate;
    if ( v4[1].__vftable == nullptr )
      LOBYTE(v5) = v5 | 4;
    std::ios_base::clear(this: v4, _State: v5, _Reraise: false);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10038610
// Name: public: std::basic_ostream<char,struct std::char_traits<char>>::sentry::sentry(class std::basic_ostream<char,struct std::char_traits<char>> __near &)
// Source: json
//------------------------------------------------------------------------------
std::ostream::sentry *__thiscall std::ostream::sentry::sentry(std::ostream::sentry *this, std::ostream *_Ostr)
{
  int v3; // ecx
  int v4; // eax
  std::ostream *v5; // eax

  this->_Myostr = _Ostr;
  v3 = *(_DWORD *)&_Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4) + 56];
  if ( v3 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  v4 = *(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4);
  if ( *(_DWORD *)&_Ostr->gap0[v4 + 12] == 0 )
  {
    v5 = *(std::ostream **)&_Ostr->gap0[v4 + 60];
    if ( v5 != nullptr )
      std::ostream::flush(this: v5);
  }
  this->_Ok = *(_DWORD *)&_Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4) + 12] == 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100386A0
// Name: public: void std::basic_ostream<char,struct std::char_traits<char>>::_Osfx(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ostream::_Osfx(std::ostream *this)
{
  _DWORD v1[7]; // [esp+0h] [ebp-1Ch] BYREF

  v1[3] = v1;
  v1[6] = 0;
  if ( (this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 20] & 2) != 0 )
    std::ostream::flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x10038A40
// Name: public: std::basic_ostream<char,struct std::char_traits<char>>::sentry::~sentry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ostream::sentry::~sentry(std::ostream::sentry *this)
{
  int v2; // eax

  if ( !std::uncaught_exception() )
    std::ostream::_Osfx(this: this->_Myostr);
  v2 = *(_DWORD *)&this->_Myostr->gap0[*(_DWORD *)(*(_DWORD *)this->_Myostr + 4) + 56];
  if ( v2 != 0 )
    (*(void (__thiscall **)(int, std::ostream::sentry *))(*(_DWORD *)v2 + 8))(a1: v2, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10038E80
// Name: public: class std::basic_ostream<char,struct std::char_traits<char>> __near & std::basic_ostream<char,struct std::char_traits<char>>::write(char const __near *,__int64)
// Source: json
//------------------------------------------------------------------------------
std::ostream *__thiscall std::ostream::write(std::ostream *this, const char *_Str, __int64 _Count)
{
  int v4; // ecx
  int v5; // eax
  std::ostream *v6; // eax
  int v7; // edx
  std::ios_base *v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v12; // [esp+0h] [ebp-2Ch] BYREF
  std::ostream::sentry _Ok; // [esp+Ch] [ebp-20h]
  std::ostream *v14; // [esp+14h] [ebp-18h]
  int _State; // [esp+18h] [ebp-14h]
  int *v16; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+28h] [ebp-4h]

  v16 = &v12;
  v14 = this;
  _State = 0;
  _Ok._Myostr = this;
  v4 = *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 56];
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  v17 = 0;
  v5 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
  if ( *(_DWORD *)&this->gap0[v5 + 12] == 0 )
  {
    v6 = *(std::ostream **)&this->gap0[v5 + 60];
    if ( v6 != nullptr )
      std::ostream::flush(this: v6);
  }
  _Ok._Ok = *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 12] == 0;
  v17 = 1;
  if ( _Ok._Ok )
  {
    LOBYTE(v17) = 2;
    if ( std::streambuf::sputn(
           this: (std::streambuf *)*(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 56],
           _Ptr: _Str,
           _Count) != _Count )
      _State = 4;
    v17 = 1;
    v7 = _State;
  }
  else
  {
    v7 = 4;
  }
  v8 = (std::ios_base *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)];
  if ( v7 != 0 )
  {
    v9 = v7 | v8->_Mystate;
    if ( v8[1].__vftable == nullptr )
      LOBYTE(v9) = v9 | 4;
    std::ios_base::clear(this: v8, _State: v9, _Reraise: false);
  }
  v17 = 4;
  if ( !std::uncaught_exception() )
    std::ostream::_Osfx(this);
  v17 = -1;
  v10 = *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 56];
  if ( v10 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003E1C0
// Name: public: virtual std::basic_ostream<char,struct std::char_traits<char>>::~basic_ostream<char,struct std::char_traits<char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ostream::~ostream<char,std::char_traits<char>>(std::ostream *this)
{
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 2) + 4) - 8) = &std::ostream::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10049890
// Name: class std::basic_ostream<char,struct std::char_traits<char>> __near & std::operator<<<struct std::char_traits<char>>(class std::basic_ostream<char,struct std::char_traits<char>> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
std::ostream *__cdecl std::operator<<<std::char_traits<char>>(std::ostream *_Ostr, const char *_Val)
{
  __int64 v2; // rax
  std::streambuf *v3; // eax
  vgui::TreeView *v4; // ecx
  std::streambuf *v5; // eax
  vgui::TreeView *v6; // ecx
  unsigned __int8 v8; // [esp-4h] [ebp-E4h]
  unsigned __int8 v9; // [esp-4h] [ebp-E4h]
  int v10; // [esp+0h] [ebp-E0h] BYREF
  __int64 v11; // [esp+Ch] [ebp-D4h]
  __int64 v12; // [esp+14h] [ebp-CCh]
  __int64 v13; // [esp+1Ch] [ebp-C4h]
  __int64 v14; // [esp+24h] [ebp-BCh]
  unsigned __int8 v15; // [esp+8Fh] [ebp-51h]
  int v16; // [esp+90h] [ebp-50h]
  unsigned __int8 v17; // [esp+9Bh] [ebp-45h]
  std::ostream *v18; // [esp+9Ch] [ebp-44h]
  DmElementHandle_t v19; // [esp+A0h] [ebp-40h] BYREF
  DmElementHandle_t v20; // [esp+A4h] [ebp-3Ch] BYREF
  DmElementHandle_t a; // [esp+A8h] [ebp-38h] BYREF
  DmElementHandle_t b; // [esp+ACh] [ebp-34h] BYREF
  std::ostream::sentry _Ok; // [esp+B0h] [ebp-30h] BYREF
  __int64 _Pad; // [esp+B8h] [ebp-28h]
  __int64 _Count; // [esp+C0h] [ebp-20h]
  int _State; // [esp+CCh] [ebp-14h]
  int *v27; // [esp+D0h] [ebp-10h]
  int v28; // [esp+DCh] [ebp-4h]

  v27 = &v10;
  _State = 0;
  _Count = std::char_traits<char>::length(str: _Val);
  v14 = std::ios_base::width(this: (std::ios_base *)&_Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4)]);
  if ( v14 <= 0
    || (v13 = std::ios_base::width(this: (std::ios_base *)&_Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4)])) <= _Count )
  {
    v12 = 0;
  }
  else
  {
    v2 = std::ios_base::width(this: (std::ios_base *)&_Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4)]);
    v12 = v2 - _Count;
  }
  _Pad = v12;
  std::ostream::sentry::sentry(this: &_Ok, _Ostr);
  v28 = 0;
  if ( std::ostream::sentry::operator int std::_Bool_struct::*(this: &_Ok) == (int *)-1 )
  {
    _State |= 4u;
  }
  else
  {
    LOBYTE(v28) = 1;
    if ( (CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&_Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4)])
        & 0x1C0) != 0x40 )
    {
      while ( _Pad > 0 )
      {
        v17 = _Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4) + 64];
        v8 = v17;
        v3 = (std::streambuf *)std::ios::rdbuf(this: (CDataModel *)&_Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4)]);
        b = std::streambuf::sputc(this: v3, _Ch: v8);
        a = std::streambuf::underflow(this: v4);
        if ( std::char_traits<char>::eq_int_type(&a, &b) )
        {
          _State |= 4u;
          break;
        }
        --_Pad;
      }
    }
    if ( _State == 0 )
    {
      v16 = std::ios::rdbuf(this: (CDataModel *)&_Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4)]);
      v11 = ((__int64 (__thiscall *)(int, const char *, _DWORD, _DWORD))*(_DWORD *)(*(_DWORD *)v16 + 36))(
              a1: v16,
              a2: _Val,
              a3: _Count,
              a4: HIDWORD(_Count));
      if ( v11 != _Count )
        _State |= 4u;
    }
    if ( _State == 0 )
    {
      while ( _Pad > 0 )
      {
        v15 = _Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4) + 64];
        v9 = v15;
        v5 = (std::streambuf *)std::ios::rdbuf(this: (CDataModel *)&_Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4)]);
        v20 = std::streambuf::sputc(this: v5, _Ch: v9);
        v19 = std::streambuf::underflow(this: v6);
        if ( std::char_traits<char>::eq_int_type(a: &v19, b: &v20) )
        {
          _State |= 4u;
          break;
        }
        --_Pad;
      }
    }
    std::ios_base::width(this: (std::ios_base *)&_Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4)], _Newwidth: 0);
    v28 = 0;
  }
  std::ios::setstate(this: (std::ios *)&_Ostr->gap0[*(_DWORD *)(*(_DWORD *)_Ostr->gap0 + 4)], _State, _Reraise: false);
  v18 = _Ostr;
  v28 = -1;
  std::ostream::sentry::~sentry(this: &_Ok);
  return v18;
}

//------------------------------------------------------------------------------
// Address: 0x10055E30
// Name: public: std::basic_fstream<char,struct std::char_traits<char>>::basic_fstream<char,struct std::char_traits<char>>(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
std::fstream *__thiscall std::fstream::fstream(std::fstream *this, const char *_Filename, int _Mode, int _Prot, int a5)
{
  int v6; // ecx
  int v7; // eax
  std::ios_base *v8; // ecx
  char v9; // al

  if ( a5 != 0 )
  {
    *(_DWORD *)this->gap0 = &std::fstream::`vbtable'{for `std::istream'};
    *(_DWORD *)this->gap10 = &std::fstream::`vbtable'{for `std::ostream'};
    *(_DWORD *)this->gap70 = &std::ios_base::`vftable';
    *(_DWORD *)this->gap70 = &std::ios::`vftable';
  }
  std::iostream::iostream(this, _Strbuf: (std::streambuf *)&this->gap10[8]);
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)] = &std::fstream::`vftable';
  std::streambuf::streambuf(this: (std::streambuf *)&this->gap10[8]);
  *(_DWORD *)&this->gap10[24] = &this->gap10[16];
  *(_DWORD *)&this->gap10[8] = &std::filebuf::`vftable';
  this->_Filebuffer[8] = 0;
  this->_Filebuffer[1] = 0;
  *(_DWORD *)&this->gap10[40] = &this->gap10[32];
  *(_DWORD *)&this->gap10[44] = &this->gap10[36];
  *(_DWORD *)&this->gap10[28] = &this->gap10[20];
  *(_DWORD *)&this->gap10[56] = &this->gap10[48];
  *(_DWORD *)&this->gap10[60] = &this->gap10[52];
  *(_DWORD *)&this->gap10[20] = 0;
  **(_DWORD **)&this->gap10[44] = 0;
  **(_DWORD **)&this->gap10[60] = 0;
  **(_DWORD **)&this->gap10[24] = 0;
  **(_DWORD **)&this->gap10[40] = 0;
  **(_DWORD **)&this->gap10[56] = 0;
  *(_DWORD *)&this->_Filebuffer[12] = 0;
  *(_DWORD *)&this->_Filebuffer[4] = `std::filebuf::_Init'::`2'::_Stinit;
  *(_DWORD *)&this->_bytes_58[4] = 0;
  if ( std::filebuf::open(this: (std::filebuf *)&this->gap10[8], _Filename, _Mode, _Prot) == nullptr )
  {
    v6 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
    v7 = *(_DWORD *)&this->gap0[v6 + 12];
    v8 = (std::ios_base *)&this->gap0[v6];
    v9 = v7 | 2;
    if ( v8[1].__vftable == nullptr )
      v9 |= 4u;
    std::ios_base::clear(this: v8, _State: v9, _Reraise: false);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10055F70
// Name: public: virtual std::basic_fstream<char,struct std::char_traits<char>>::~basic_fstream<char,struct std::char_traits<char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::fstream::~fstream<char,std::char_traits<char>>(std::fstream *this)
{
  std::filebuf *v1; // esi
  char **IGfirst; // ecx
  char *Set_egptr; // eax

  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 28) + 4) - 112) = &std::fstream::`vftable';
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
  *(_DWORD *)((char *)v1 + *((_DWORD *)v1[-1]._Set_egptr + 1) - 24) = &std::iostream::`vftable';
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*(_DWORD *)&v1[-1]._Closef + 4) - 8) = &std::ostream::`vftable';
  *(_DWORD *)((char *)v1 + *((_DWORD *)v1[-1]._Set_egptr + 1) - 24) = &std::istream::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10070CF0
// Name: public: std::basic_fstream<char,struct std::char_traits<char>>::basic_fstream<char,struct std::char_traits<char>>(void)
// Source: json
//------------------------------------------------------------------------------
std::fstream *__thiscall std::fstream::fstream(std::fstream *this, int a2)
{
  _DWORD *v3; // esi

  if ( a2 != 0 )
  {
    *(_DWORD *)this->gap0 = &std::fstream::`vbtable'{for `std::istream'};
    *(_DWORD *)this->gap10 = &std::fstream::`vbtable'{for `std::ostream'};
    *(_DWORD *)this->gap70 = &std::ios_base::`vftable';
    *(_DWORD *)this->gap70 = &std::ios::`vftable';
  }
  v3 = &this->gap10[8];
  std::iostream::iostream(this, _Strbuf: (std::streambuf *)&this->gap10[8]);
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)] = &std::fstream::`vftable';
  std::streambuf::streambuf(this: (std::streambuf *)&this->gap10[8]);
  *(_DWORD *)&this->gap10[24] = &this->gap10[16];
  *v3 = &std::filebuf::`vftable';
  this->_Filebuffer[8] = 0;
  this->_Filebuffer[1] = 0;
  *(_DWORD *)&this->gap10[40] = &this->gap10[32];
  *(_DWORD *)&this->gap10[44] = &this->gap10[36];
  *(_DWORD *)&this->gap10[28] = &this->gap10[20];
  *(_DWORD *)&this->gap10[56] = &this->gap10[48];
  *(_DWORD *)&this->gap10[60] = &this->gap10[52];
  *(_DWORD *)&this->gap10[20] = 0;
  **(_DWORD **)&this->gap10[44] = 0;
  **(_DWORD **)&this->gap10[60] = 0;
  **(_DWORD **)&this->gap10[24] = 0;
  **(_DWORD **)&this->gap10[40] = 0;
  **(_DWORD **)&this->gap10[56] = 0;
  *(_DWORD *)&this->_Filebuffer[12] = 0;
  *(_DWORD *)&this->_Filebuffer[4] = `std::filebuf::_Init'::`2'::_Stinit;
  *(_DWORD *)&this->_bytes_58[4] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008E5C0
// Name: public: virtual CPrefab::~CPrefab(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefab::~CPrefab(CPrefab *this)
{
  __POSITION *v2; // eax
  __POSITION *v3; // eax

  this->__vftable = (CPrefab_vtbl *)&CPrefab::`vftable';
  v2 = CPtrList::Find(this: (CObList *)&CPrefab::PrefabList, searchValue: (CObject *)this, startAfter: nullptr);
  if ( v2 != nullptr )
    CPtrList::RemoveAt(this: (CObList *)&CPrefab::PrefabList, position: v2);
  v3 = CPtrList::Find(this: (CObList *)&CPrefab::MRU, searchValue: (CObject *)this, startAfter: nullptr);
  if ( v3 != nullptr )
    CPtrList::RemoveAt(this: (CObList *)&CPrefab::MRU, position: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1008E610
// Name: public: static void CPrefab::EnableCaching(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CPrefab::EnableCaching(int b)
{
  CPrefab::bCacheEnabled = b;
}

//------------------------------------------------------------------------------
// Address: 0x1008E620
// Name: SortPrefabs
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortPrefabs(CPrefab *a, CPrefab *b)
{
  return _V_stricmp(s1: a->szName, s2: b->szName);
}

//------------------------------------------------------------------------------
// Address: 0x1008E640
// Name: public: void CPrefabLibrary::SetNameFromFilename(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabLibrary::SetNameFromFilename(CPrefabLibrary *this, char *pszFilename)
{
  int v3; // eax
  char *v4; // eax
  char *m_szName; // esi
  int v6; // edx
  char v7; // cl
  _BYTE *v8; // eax

  strrchr(string: (unsigned __int8 *)pszFilename, chr: 0x5Cu);
  if ( v3 != 0 )
    v4 = (char *)(v3 + 1);
  else
    v4 = pszFilename;
  m_szName = this->m_szName;
  v6 = m_szName - v4;
  do
  {
    v7 = *v4;
    v4[v6] = *v4;
    ++v4;
  }
  while ( v7 != 0 );
  strchr(string: m_szName, chr: 0x2Eu);
  if ( v8 != nullptr )
    *v8 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008E690
// Name: public: void CPrefabLibrary::Remove(class CPrefab __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabLibrary::Remove(CPrefabLibrary *this, CObject *pPrefab)
{
  __POSITION *v3; // eax

  v3 = CPtrList::Find(this: (CObList *)&this->Prefabs, searchValue: pPrefab, startAfter: nullptr);
  if ( v3 != nullptr )
    CPtrList::RemoveAt(this: (CObList *)&this->Prefabs, position: v3);
  if ( pPrefab[135].__vftable == (CObject_vtbl *)this->dwID )
    pPrefab[135].__vftable = (CObject_vtbl *)0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1008E6E0
// Name: public: virtual bool CPrefabLibraryVMF::IsFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPrefabLibraryVMF::IsFile(CPrefabLibraryVMF *this, const char *szFilename)
{
  return _V_stricmp(s1: this->m_szFolderName, s2: szFilename) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008E700
// Name: public: virtual int CPrefabLibraryVMF::Save(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabLibraryVMF::Save(CPrefabVMF *this, const char *pszFilename, const char *dwFlags)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008E710
// Name: public: virtual int CPrefabLibraryVMF::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabLibraryVMF::SetName(CPrefabLibraryVMF *this, const char *pszName)
{
  const char *v2; // eax
  int v3; // edx
  char v4; // cl

  v2 = pszName;
  v3 = this->m_szName - pszName;
  do
  {
    v4 = *v2;
    v2[v3] = *v2;
    ++v2;
  }
  while ( v4 != 0 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008E740
// Name: public: void __near * __near & CPtrList::GetNext(struct __POSITION __near * __near &)
// Source: json
//------------------------------------------------------------------------------
__POSITION **__thiscall CPtrList::GetNext(CPtrList *this, __POSITION **rPosition)
{
  __POSITION **v2; // eax

  v2 = (__POSITION **)*rPosition;
  if ( *rPosition == nullptr )
    AfxThrowInvalidArgException();
  *rPosition = *v2;
  return v2 + 2;
}

//------------------------------------------------------------------------------
// Address: 0x1008E760
// Name: public: CPrefab::CPrefab(void)
// Source: json
//------------------------------------------------------------------------------
CPrefab *__thiscall CPrefab::CPrefab(CPrefab *this)
{
  unsigned int v1; // eax

  v1 = dwRunningID;
  this->dwID = dwRunningID;
  this->__vftable = (CPrefab_vtbl *)&CPrefab::`vftable';
  dwRunningID = v1 + 1;
  CPtrList::AddTail(this: (CObList *)&CPrefab::PrefabList, newElement: (CObject *)this);
  this->szNotes[0] = 0;
  this->szName[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008E800
// Name: public: void CPrefabLibrary::Add(class CPrefab __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabLibrary::Add(CPrefabLibrary *this, CObject *pPrefab)
{
  if ( CPtrList::Find(this: (CObList *)&this->Prefabs, searchValue: pPrefab, startAfter: nullptr) == nullptr )
    CPtrList::AddTail(this: (CObList *)&this->Prefabs, newElement: pPrefab);
  pPrefab[135].__vftable = (CObject_vtbl *)this->dwID;
}

//------------------------------------------------------------------------------
// Address: 0x1008E850
// Name: public: virtual bool CPrefabLibraryRMF::IsFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPrefabLibraryRMF::IsFile(CPrefabLibraryRMF *this, const char *szFilename)
{
  return _V_stricmp(s1: this->m_strOpenFileName.m_pszData, s2: szFilename) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008E870
// Name: public: virtual bool CPrefabLibraryRMF::DeleteFileA(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPrefabLibraryRMF::DeleteFileA(CPrefabLibraryRMF *this)
{
  return remove(path: this->m_strOpenFileName.m_pszData) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008E890
// Name: public: static class CPrefab __near * CPrefab::FindID(unsigned long)
// Source: json
//------------------------------------------------------------------------------
CPrefab *__cdecl CPrefab::FindID(unsigned int dwID)
{
  CPtrList::CNode *m_pNodeHead; // ecx
  CPrefab *result; // eax

  m_pNodeHead = CPrefab::PrefabList.m_pNodeHead;
  if ( CPrefab::PrefabList.m_pNodeHead == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( m_pNodeHead == nullptr )
      AfxThrowInvalidArgException();
    result = (CPrefab *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( result->dwID == dwID )
      break;
    if ( m_pNodeHead == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008E8C0
// Name: public: static void CPrefab::AddMRU(class CPrefab __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CPrefab::AddMRU(CObject *pPrefab)
{
  __POSITION *v1; // eax
  __POSITION *m_pNodeTail; // esi

  if ( CPrefab::bCacheEnabled != 0 )
  {
    v1 = CPtrList::Find(this: (CObList *)&CPrefab::MRU, searchValue: pPrefab, startAfter: nullptr);
    if ( v1 != nullptr )
    {
      CPtrList::RemoveAt(this: (CObList *)&CPrefab::MRU, position: v1);
      CObList::AddHead(this: (CObList *)&CPrefab::MRU, newElement: pPrefab);
    }
    else
    {
      if ( CPrefab::MRU.m_nCount == 5 )
      {
        m_pNodeTail = (__POSITION *)CPrefab::MRU.m_pNodeTail;
        if ( CPrefab::MRU.m_pNodeTail != nullptr )
        {
          (*(void (__thiscall **)(void *))(*(_DWORD *)CPrefab::MRU.m_pNodeTail->data + 20))(a1: CPrefab::MRU.m_pNodeTail->data);
          CPtrList::RemoveAt(this: (CObList *)&CPrefab::MRU, position: m_pNodeTail);
        }
      }
      CObList::AddHead(this: (CObList *)&CPrefab::MRU, newElement: pPrefab);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E940
// Name: public: static void CPrefab::FreeAllData(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1008E970
// Name: public: class CPrefab __near * CPrefabLibrary::EnumPrefabs(struct __POSITION __near * __near &)
// Source: json
//------------------------------------------------------------------------------
CPrefab *__thiscall CPrefabLibrary::EnumPrefabs(CPrefabLibrary *this, __POSITION **p)
{
  CPrefab *result; // eax

  if ( *p == (__POSITION *)1 )
    *p = (__POSITION *)this->Prefabs.m_pNodeHead;
  result = (CPrefab *)*p;
  if ( *p != nullptr )
  {
    *p = (__POSITION *)result->__vftable;
    return *(CPrefab **)&result->szName[4];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008E9A0
// Name: public: static class CPrefabLibrary __near * CPrefabLibrary::FindID(unsigned long)
// Source: json
//------------------------------------------------------------------------------
CPrefabLibrary *__cdecl CPrefabLibrary::FindID(unsigned int dwID)
{
  CPtrList::CNode *m_pNodeHead; // ecx
  CPrefabLibrary *result; // eax

  m_pNodeHead = CPrefabLibrary::PrefabLibraryList.m_pNodeHead;
  if ( CPrefabLibrary::PrefabLibraryList.m_pNodeHead == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( m_pNodeHead == nullptr )
      AfxThrowInvalidArgException();
    result = (CPrefabLibrary *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( result->dwID == dwID )
      break;
    if ( m_pNodeHead == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008E9D0
// Name: public: static class CPrefabLibrary __near * CPrefabLibrary::EnumLibraries(struct __POSITION __near * __near &,enum LibraryType_t)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1008EA20
// Name: public: virtual int CPrefabLibraryVMF::Load(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabLibraryVMF::Load(CPrefabLibraryVMF *this, char *pszFilename)
{
  CPtrList::CNode *m_pNodeHead; // esi
  void (__thiscall ***data)(_DWORD, int); // ecx
  int v4; // eax
  char *v5; // eax
  char *m_szName; // esi
  int v7; // edx
  char v8; // cl
  _BYTE *v9; // eax
  CPrefabLibraryVMF *v10; // esi
  char *v11; // eax
  int v12; // edx
  char v13; // cl
  char *v14; // eax
  char v15; // cl
  HANDLE FirstFileA; // esi
  _BYTE *v17; // eax
  int v18; // eax
  char v19; // cl
  unsigned int v20; // eax
  char *v21; // edi
  char v22; // cl
  CPrefabVMF *v23; // eax
  CPrefabVMF *v24; // esi
  CPrefabLibraryVMF *v25; // edi
  char v27; // [esp+7h] [ebp-35Dh] BYREF
  char szFile[260]; // [esp+8h] [ebp-35Ch] BYREF
  _WIN32_FIND_DATAA fd; // [esp+10Ch] [ebp-258h] BYREF
  char szDir[260]; // [esp+24Ch] [ebp-118h] BYREF
  CPrefabVMF *v31; // [esp+350h] [ebp-14h]
  CPrefabLibraryVMF *v32; // [esp+354h] [ebp-10h]
  int v33; // [esp+360h] [ebp-4h]
  void *hnd; // [esp+36Ch] [ebp+8h]

  m_pNodeHead = this->Prefabs.m_pNodeHead;
  v32 = this;
  while ( m_pNodeHead != nullptr )
  {
    data = (void (__thiscall ***)(_DWORD, int))m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data != nullptr )
      (**data)(a1: data, a2: 1);
  }
  strrchr(string: (unsigned __int8 *)pszFilename, chr: 0x5Cu);
  if ( v4 != 0 )
    v5 = (char *)(v4 + 1);
  else
    v5 = pszFilename;
  m_szName = v32->m_szName;
  v7 = v32->m_szName - v5;
  do
  {
    v8 = *v5;
    v5[v7] = *v5;
    ++v5;
  }
  while ( v8 != 0 );
  strchr(string: m_szName, chr: 0x2Eu);
  if ( v9 != nullptr )
    *v9 = 0;
  v10 = v32;
  v11 = pszFilename;
  v12 = v32->m_szFolderName - pszFilename;
  do
  {
    v13 = *v11;
    v11[v12] = *v11;
    ++v11;
  }
  while ( v13 != 0 );
  v10->m_eType = LibType_HalfLife2;
  strcpy(szDir, pszFilename);
  v14 = &fd.cAlternateFileName[15];
  do
    v15 = *++v14;
  while ( v15 != 0 );
  strcpy(v14, "\\*.vmf");
  FirstFileA = FindFirstFileA(lpFileName: szDir, lpFindFileData: &fd);
  hnd = FirstFileA;
  if ( FirstFileA != (HANDLE)-1 )
  {
    strrchr(string: (unsigned __int8 *)szDir, chr: 0x2Au);
    *v17 = 0;
    do
    {
      if ( fd.cFileName[0] != 46 )
      {
        v18 = 0;
        do
        {
          v19 = szDir[v18];
          szFile[v18++] = v19;
        }
        while ( v19 != 0 );
        v20 = strlen(fd.cFileName) + 1;
        v21 = &v27;
        do
          v22 = *++v21;
        while ( v22 != 0 );
        qmemcpy(v21, fd.cFileName, v20);
        v23 = (CPrefabVMF *)operator new(nSize: 0x334u);
        v31 = v23;
        v33 = 0;
        if ( v23 != nullptr )
          v24 = CPrefabVMF::CPrefabVMF(this: v23);
        else
          v24 = nullptr;
        v33 = -1;
        CPrefabVMF::SetFilename(this: v24, szFilename: szFile);
        v25 = v32;
        if ( CPtrList::Find(this: (CObList *)&v32->Prefabs, searchValue: (CObject *)v24, startAfter: nullptr) == nullptr )
          CPtrList::AddTail(this: (CObList *)&v25->Prefabs, newElement: (CObject *)v24);
        v24->dwLibID = v25->dwID;
        FirstFileA = hnd;
      }
    }
    while ( FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &fd) );
    FindClose(hFindFile: FirstFileA);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008EC50
// Name: public: CPrefabLibrary::~CPrefabLibrary(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabLibrary::~CPrefabLibrary(CPrefabLibrary *this)
{
  CPtrList::CNode *m_pNodeHead; // esi
  void (__thiscall ***data)(_DWORD, int); // ecx

  this->__vftable = (CPrefabLibrary_vtbl *)&CPrefabLibrary::`vftable';
  m_pNodeHead = this->Prefabs.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = (void (__thiscall ***)(_DWORD, int))m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data != nullptr )
      (**data)(a1: data, a2: 1);
  }
  CPtrList::~CPtrList(this: &this->Prefabs);
}

//------------------------------------------------------------------------------
// Address: 0x1008ECD0
// Name: public: void CPrefabLibrary::Sort(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabLibrary::Sort(CPrefabLibrary *this)
{
  signed int m_nCount; // ebx
  char *v3; // esi
  CPtrList::CNode *m_pNodeHead; // eax
  void *data; // ecx
  char *v6; // edx
  signed int i; // esi
  CPrefab **TmpPrefabArray; // [esp+8h] [ebp-4h]

  m_nCount = this->Prefabs.m_nCount;
  if ( m_nCount >= 2 )
  {
    v3 = (char *)operator new[](nSize: 4 * m_nCount);
    m_pNodeHead = this->Prefabs.m_pNodeHead;
    TmpPrefabArray = (CPrefab **)v3;
    if ( m_pNodeHead != nullptr )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
    }
    else
    {
      data = nullptr;
    }
    if ( data != nullptr )
    {
      v6 = v3;
      do
      {
        *(_DWORD *)v6 = data;
        v6 += 4;
        if ( m_pNodeHead == (CPtrList::CNode *)1 )
          m_pNodeHead = this->Prefabs.m_pNodeHead;
        if ( m_pNodeHead == nullptr )
          break;
        data = m_pNodeHead->data;
        m_pNodeHead = m_pNodeHead->pNext;
      }
      while ( data != nullptr );
    }
    qsort(base: v3, num: m_nCount, width: 4u, comp: (int (__cdecl *)(const void *, const void *))SortPrefabs);
    CObList::RemoveAll(this: (CObList *)&this->Prefabs);
    for ( i = 0; i < m_nCount; ++i )
      CPtrList::AddTail(this: (CObList *)&this->Prefabs, newElement: (CObject *)TmpPrefabArray[i]);
    operator delete(p: TmpPrefabArray);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008ED90
// Name: public: static class CPrefabLibrary __near * CPrefabLibrary::FindOpenLibrary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPrefabLibrary *__cdecl CPrefabLibrary::FindOpenLibrary(const char *pszFilename)
{
  void *data; // edi
  CPtrList::CNode *pNext; // esi

  if ( CPrefabLibrary::PrefabLibraryList.m_pNodeHead == nullptr )
    return nullptr;
  data = CPrefabLibrary::PrefabLibraryList.m_pNodeHead->data;
  pNext = CPrefabLibrary::PrefabLibraryList.m_pNodeHead->pNext;
  if ( data == nullptr )
    return nullptr;
  while ( (*(unsigned __int8 (__thiscall **)(void *, const char *))(*(_DWORD *)data + 12))(a1: data, a2: pszFilename) == 0 )
  {
    if ( pNext == (CPtrList::CNode *)1 )
      pNext = CPrefabLibrary::PrefabLibraryList.m_pNodeHead;
    if ( pNext != nullptr )
    {
      data = pNext->data;
      pNext = pNext->pNext;
      if ( data != nullptr )
        continue;
    }
    return nullptr;
  }
  return (CPrefabLibrary *)data;
}

//------------------------------------------------------------------------------
// Address: 0x1008EDF0
// Name: public: CPrefabLibraryVMF::CPrefabLibraryVMF(void)
// Source: json
//------------------------------------------------------------------------------
CPrefabLibraryVMF *__thiscall CPrefabLibraryVMF::CPrefabLibraryVMF(CPrefabLibraryVMF *this)
{
  CTypedPtrList<CPtrList,CPrefab *> *p_Prefabs; // edi
  int v3; // eax

  p_Prefabs = &this->Prefabs;
  this->__vftable = (CPrefabLibraryVMF_vtbl *)&CPrefabLibrary::`vftable';
  CPtrList::CPtrList(this: &this->Prefabs, nBlockSize: 10);
  p_Prefabs->__vftable = (CTypedPtrList<CPtrList,CPrefab *>_vtbl *)&_CTypedPtrList<CPtrList,CPrefab *>::`vftable';
  p_Prefabs->__vftable = (CTypedPtrList<CPtrList,CPrefab *>_vtbl *)&CTypedPtrList<CPtrList,CPrefab *>::`vftable';
  v3 = dword_1072E860;
  this->dwID = dword_1072E860;
  dword_1072E860 = v3 + 1;
  this->m_szName[0] = 0;
  this->szNotes[0] = 0;
  this->__vftable = (CPrefabLibraryVMF_vtbl *)&CPrefabLibraryVMF::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008EE90
// Name: public: class std::basic_ostream<char,struct std::char_traits<char>> __near & std::basic_ostream<char,struct std::char_traits<char>>::seekp(class std::fpos<int>)
// Source: json
//------------------------------------------------------------------------------
std::ostream *__thiscall std::ostream::seekp(std::ostream *this, std::fpos<int> _Pos)
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
    (*(void (__thiscall **)(_DWORD, __int64 *, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int))(**(_DWORD **)&this->gap0[v3 + 56]
                                                                                                + 44))(
      a1: *(_DWORD *)&this->gap0[v3 + 56],
      a2: &v9,
      a3: _Pos._Myoff,
      a4: HIDWORD(_Pos._Myoff),
      a5: _Pos._Fpos,
      a6: HIDWORD(_Pos._Fpos),
      a7: _Pos._Mystate,
      a8: *(&_Pos._Mystate + 1),
      a9: 2);
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
// Address: 0x1008EF20
// Name: public: class std::basic_ostream<char,struct std::char_traits<char>> __near & std::basic_ostream<char,struct std::char_traits<char>>::seekp(__int64,int)
// Source: json
//------------------------------------------------------------------------------
std::ostream *__thiscall std::ostream::seekp(std::ostream *this, __int64 _Off, int _Way)
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
    (*(void (__thiscall **)(_DWORD, __int64 *, _DWORD, _DWORD, int, int))(**(_DWORD **)&this->gap0[v4 + 56] + 40))(
      a1: *(_DWORD *)&this->gap0[v4 + 56],
      a2: &v10,
      a3: _Off,
      a4: HIDWORD(_Off),
      a5: _Way,
      a6: 2);
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
// Address: 0x1008EFA0
// Name: public: static void CPrefabLibrary::FreeAllLibraries(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1008F050
// Name: public: void std::basic_fstream<char,struct std::char_traits<char>>::open(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::fstream::open(std::fstream *this, const char *_Filename, int _Mode, int _Prot)
{
  int v5; // ecx
  int v6; // eax
  std::ios_base *v7; // ecx
  char v8; // al
  int v9; // ecx
  int v10; // eax

  if ( std::filebuf::open(this: (std::filebuf *)&this->gap10[8], _Filename, _Mode, _Prot) != nullptr )
  {
    v9 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
    v10 = *(_DWORD *)&this->gap10[v9 + 40];
    v7 = (std::ios_base *)&this->gap0[v9];
    v8 = v10 != 0 ? 0 : 4;
  }
  else
  {
    v5 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
    v6 = *(_DWORD *)&this->gap0[v5 + 12];
    v7 = (std::ios_base *)&this->gap0[v5];
    v8 = v6 | 2;
    if ( v7[1].__vftable == nullptr )
    {
      std::ios_base::clear(this: v7, _State: v8 | 4, _Reraise: false);
      return;
    }
  }
  std::ios_base::clear(this: v7, _State: v8, _Reraise: false);
}

//------------------------------------------------------------------------------
// Address: 0x1008F0C0
// Name: public: virtual int CPrefabLibraryRMF::Load(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabLibraryRMF::Load(CPrefabLibraryRMF *this, char *pszFilename)
{
  CPtrList::CNode *m_pNodeHead; // esi
  void (__thiscall ***data)(_DWORD, int); // ecx
  std::fstream *p_m_file; // esi
  int v6; // ecx
  int v7; // eax
  std::ios_base *v8; // ecx
  char v9; // al
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  PrefabHeader *v14; // eax
  unsigned int dwDirOffset; // ecx
  CPrefabLibraryRMF *v16; // edx
  char *v17; // edi
  std::istream *v18; // esi
  char *v19; // edi
  CPrefabRMF *v20; // eax
  CPrefabRMF *v21; // esi
  char *v22; // eax
  char v23; // cl
  char *v24; // eax
  char v25; // cl
  CPrefabLibraryRMF *v26; // ecx
  unsigned int v27; // eax
  std::fpos<int> v28; // [esp-18h] [ebp-2C0h] BYREF
  PrefabLibraryHeader plh; // [esp+Ch] [ebp-29Ch] BYREF
  char szBuf[128]; // [esp+210h] [ebp-98h] BYREF
  PrefabHeader *ph; // [esp+290h] [ebp-18h]
  std::fpos<int> *v32; // [esp+294h] [ebp-14h]
  CPrefabLibraryRMF *v33; // [esp+298h] [ebp-10h]
  int v34; // [esp+2A4h] [ebp-4h]
  unsigned int i; // [esp+2B0h] [ebp+8h]

  m_pNodeHead = this->Prefabs.m_pNodeHead;
  v33 = this;
  while ( m_pNodeHead != nullptr )
  {
    data = (void (__thiscall ***)(_DWORD, int))m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data != nullptr )
      (**data)(a1: data, a2: 1);
  }
  *(&v28._Mystate + 1) = 64;
  v28._Mystate = 33;
  p_m_file = &this->m_file;
  HIDWORD(v28._Fpos) = pszFilename;
  this->m_eType = LibType_HalfLife;
  if ( std::filebuf::open(
         this: (std::filebuf *)&this->m_file.gap10[8],
         _Filename: (const char *)HIDWORD(v28._Fpos),
         _Mode: v28._Mystate,
         _Prot: *(&v28._Mystate + 1)) != nullptr )
  {
    v10 = *(_DWORD *)(*(_DWORD *)p_m_file->gap0 + 4);
    v11 = *(_DWORD *)&p_m_file->gap10[v10 + 40];
    v8 = (std::ios_base *)&p_m_file->gap0[v10];
    v9 = v11 != 0 ? 0 : 4;
  }
  else
  {
    v6 = *(_DWORD *)(*(_DWORD *)p_m_file->gap0 + 4);
    v7 = *(_DWORD *)&p_m_file->gap0[v6 + 12];
    v8 = (std::ios_base *)&p_m_file->gap0[v6];
    v9 = v7 | 2;
    if ( v8[1].__vftable == nullptr )
      v9 |= 4u;
  }
  std::ios_base::clear(this: v8, _State: v9, _Reraise: false);
  if ( pszFilename != nullptr )
    v12 = strlen(pszFilename);
  else
    v12 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strOpenFileName, pszSrc: pszFilename, nLength: v12);
  if ( *(_DWORD *)&this->m_file._Filebuffer[12] == 0 )
    return -1;
  std::istream::read(this: &this->m_file, _Str: szBuf, _Count: strlen(pLibHeader));
  if ( strncmp(first: szBuf, last: pLibHeader, count: strlen(pLibHeader)) != 0 )
    return -1;
  std::istream::read(this: &this->m_file, _Str: (char *)&plh, _Count: 516);
  strcpy(this->szNotes, plh.szNotes);
  CPrefabLibrary::SetNameFromFilename(this, pszFilename);
  v14 = (PrefabHeader *)operator new[](nSize: 544 * plh.dwNumEntries);
  dwDirOffset = plh.dwDirOffset;
  v16 = v33;
  v33->m_dwDirOffset = plh.dwDirOffset;
  v17 = (char *)v14;
  v18 = &v16->m_file;
  v28._Myoff = dwDirOffset;
  ph = v14;
  memset(&v28._Fpos, 0, 12);
  std::istream::seekg(this: &v16->m_file, _Pos: v28);
  std::istream::read(this: v18, _Str: v17, _Count: 544 * plh.dwNumEntries);
  i = 0;
  if ( plh.dwNumEntries != 0 )
  {
    v19 = v17 + 39;
    do
    {
      v20 = (CPrefabRMF *)operator new(nSize: 0x22Cu);
      v32 = (std::fpos<int> *)v20;
      v34 = 0;
      if ( v20 != nullptr )
        v21 = CPrefabRMF::CPrefabRMF(this: v20);
      else
        v21 = nullptr;
      v34 = -1;
      v28._Myoff = *(unsigned int *)(v19 - 39);
      v32 = &v28;
      memset(&v28._Fpos, 0, 12);
      std::istream::seekg(this: &v33->m_file, _Pos: v28);
      CPrefabRMF::Init(this: v21, file: &v33->m_file, bLoadNow: 0, dwFlags: 0);
      v22 = v19 - 31;
      do
      {
        v23 = *v22;
        v22[(char *)v21 - (v19 - 31) + 4] = *v22;
        ++v22;
      }
      while ( v23 != 0 );
      v24 = v19;
      do
      {
        v25 = *v24;
        v24[(char *)v21 - v19 + 35] = *v24;
        ++v24;
      }
      while ( v25 != 0 );
      v26 = v33;
      v21->dwFileSize = *(_DWORD *)(v19 - 35);
      v27 = *(_DWORD *)(v19 - 39);
      *(&v28._Mystate + 1) = 0;
      v28._Mystate = (int)v21;
      v21->dwFileOffset = v27;
      if ( CPtrList::Find(
             this: (CObList *)&v26->Prefabs,
             searchValue: (CObject *)v28._Mystate,
             startAfter: *((__POSITION **)&v28._Mystate + 1)) == nullptr )
        CPtrList::AddTail(this: (CObList *)&v33->Prefabs, newElement: (CObject *)v21);
      v21->dwLibID = v33->dwID;
      v19 += 544;
      ++i;
    }
    while ( i < plh.dwNumEntries );
    v17 = (char *)ph;
  }
  operator delete(p: v17);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008F3C0
// Name: public: virtual int CPrefabLibraryRMF::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabLibraryRMF::SetName(CPrefabLibraryRMF *this, const char *pszName)
{
  const char *v3; // eax
  int v4; // edx
  char v5; // cl
  AFX_MODULE_STATE *ModuleState; // eax
  std::fstream *p_m_file; // esi
  int v8; // ecx
  int v9; // eax
  std::ios_base *v10; // ecx
  char v11; // al
  std::fstream *v12; // esi
  int v13; // ecx
  int v14; // eax
  std::ios_base *v15; // ecx
  char v16; // al
  int v18; // ecx
  int v19; // eax
  char szNewFilename[260]; // [esp+8h] [ebp-104h] BYREF

  v3 = pszName;
  v4 = this->m_szName - pszName;
  do
  {
    v5 = *v3;
    v3[v4] = *v3;
    ++v3;
  }
  while ( v5 != 0 );
  ModuleState = AfxGetModuleState();
  CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PREFABS, p: szNewFilename);
  sprintf(string: &szNewFilename[strlen(szNewFilename)], format: "\\%s.ol", pszName);
  if ( *(_DWORD *)&this->m_file._Filebuffer[12] != 0 )
  {
    p_m_file = &this->m_file;
    if ( std::filebuf::close(this: (std::filebuf *)&this->m_file.gap10[8]) == nullptr )
    {
      v8 = *(_DWORD *)(*(_DWORD *)p_m_file->gap0 + 4);
      v9 = *(_DWORD *)&p_m_file->gap0[v8 + 12];
      v10 = (std::ios_base *)&p_m_file->gap0[v8];
      v11 = v9 | 2;
      if ( v10[1].__vftable == nullptr )
        v11 |= 4u;
      std::ios_base::clear(this: v10, _State: v11, _Reraise: false);
    }
  }
  else if ( GetFileAttributesA(lpFileName: szNewFilename) != -1 )
  {
    return 0;
  }
  rename(oldname: this->m_strOpenFileName.m_pszData, newname: szNewFilename);
  ATL::CSimpleStringT<char,0>::SetString(
    this: &this->m_strOpenFileName,
    pszSrc: szNewFilename,
    nLength: strlen(szNewFilename));
  v12 = &this->m_file;
  if ( std::filebuf::open(
         this: (std::filebuf *)&this->m_file.gap10[8],
         _Filename: this->m_strOpenFileName.m_pszData,
         _Mode: 33,
         _Prot: 64) != nullptr )
  {
    v18 = *(_DWORD *)(*(_DWORD *)v12->gap0 + 4);
    v19 = *(_DWORD *)&v12->gap10[v18 + 40];
    v15 = (std::ios_base *)&v12->gap0[v18];
    v16 = v19 != 0 ? 0 : 4;
  }
  else
  {
    v13 = *(_DWORD *)(*(_DWORD *)v12->gap0 + 4);
    v14 = *(_DWORD *)&v12->gap0[v13 + 12];
    v15 = (std::ios_base *)&v12->gap0[v13];
    v16 = v14 | 2;
    if ( v15[1].__vftable == nullptr )
      v16 |= 4u;
  }
  std::ios_base::clear(this: v15, _State: v16, _Reraise: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008F520
// Name: public: CPrefabLibraryRMF::CPrefabLibraryRMF(void)
// Source: json
//------------------------------------------------------------------------------
CPrefabLibraryRMF *__thiscall CPrefabLibraryRMF::CPrefabLibraryRMF(CPrefabLibraryRMF *this)
{
  CTypedPtrList<CPtrList,CPrefab *> *p_Prefabs; // edi
  int v3; // eax
  ATL::IAtlStringMgr *StringManager; // eax

  p_Prefabs = &this->Prefabs;
  this->__vftable = (CPrefabLibraryRMF_vtbl *)&CPrefabLibrary::`vftable';
  CPtrList::CPtrList(this: &this->Prefabs, nBlockSize: 10);
  p_Prefabs->__vftable = (CTypedPtrList<CPtrList,CPrefab *>_vtbl *)&_CTypedPtrList<CPtrList,CPrefab *>::`vftable';
  p_Prefabs->__vftable = (CTypedPtrList<CPtrList,CPrefab *>_vtbl *)&CTypedPtrList<CPtrList,CPrefab *>::`vftable';
  v3 = dword_1072E860;
  this->dwID = dword_1072E860;
  dword_1072E860 = v3 + 1;
  this->m_szName[0] = 0;
  this->szNotes[0] = 0;
  this->__vftable = (CPrefabLibraryRMF_vtbl *)&CPrefabLibraryRMF::`vftable';
  std::fstream::fstream(this: &this->m_file, a2: 1);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strOpenFileName.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008F600
// Name: public: virtual int CPrefabLibraryRMF::Save(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabLibraryRMF::Save(CPrefabLibraryRMF *this, __POSITION *pszFilename, int bIndexOnly)
{
  CPrefabLibraryRMF *v3; // esi
  std::fstream *p_m_file; // ebx
  int v5; // ecx
  int v6; // eax
  std::ios_base *v7; // ecx
  char v8; // al
  int v9; // ebx
  int m_nCount; // ecx
  char *szNotes; // eax
  char v12; // cl
  const char *v13; // eax
  CPtrList::CNode *m_pNodeHead; // ebx
  const char *v15; // edi
  char *v16; // edi
  char *data; // ecx
  char *v18; // eax
  char v19; // dl
  char *v20; // eax
  char v21; // dl
  int v22; // ecx
  int v23; // eax
  std::ios_base *v24; // ecx
  char v25; // al
  AFX_MODULE_STATE *ModuleState; // eax
  char *m_pszData; // ecx
  char *v28; // edx
  char v29; // al
  __POSITION *v30; // eax
  __POSITION *v31; // eax
  int v32; // edx
  __POSITION v33; // cl
  _BYTE *v34; // eax
  int v35; // ecx
  int v36; // eax
  std::ios_base *v37; // ecx
  char v38; // al
  int v39; // ecx
  int v40; // eax
  int v41; // eax
  int v42; // ecx
  _BYTE *v43; // eax
  int v44; // eax
  char *v45; // eax
  char v46; // cl
  PrefabHeader *v47; // ebx
  int v48; // ebx
  CPrefabRMF *v49; // edi
  int v50; // eax
  bool v51; // zf
  _BYTE *v52; // eax
  int v53; // eax
  char *szName; // eax
  char v55; // cl
  char *v56; // eax
  char v57; // cl
  int v58; // esi
  unsigned int dwFileSize; // eax
  CPrefabRMF *v60; // ebx
  int v61; // eax
  _BYTE *v62; // eax
  int v63; // ecx
  unsigned int v64; // eax
  bool v65; // cf
  unsigned int v66; // eax
  unsigned int v67; // eax
  __int64 v68; // xmm0_8
  _BYTE *v69; // eax
  int v70; // eax
  unsigned int v71; // eax
  unsigned int v72; // ecx
  int v73; // ecx
  int v74; // eax
  std::ios_base *v75; // ecx
  char v76; // al
  std::fstream *v77; // ebx
  int v78; // ecx
  int v79; // eax
  std::ios_base *v80; // ecx
  char v81; // al
  ATL::CSimpleStringT<char,0> *v82; // esi
  int v83; // ecx
  int v84; // eax
  std::ios_base *v85; // ecx
  char v86; // al
  int v87; // ecx
  int v88; // eax
  char *v89; // eax
  std::fpos<int> v91; // [esp-18h] [ebp-640h] BYREF
  char _Str[4]; // [esp+Ch] [ebp-61Ch] BYREF
  unsigned int m_dwDirOffset; // [esp+10h] [ebp-618h]
  int v94; // [esp+14h] [ebp-614h]
  _BYTE v95[504]; // [esp+18h] [ebp-610h] BYREF
  PrefabLibraryHeader plh; // [esp+210h] [ebp-418h] BYREF
  char szNewFilename[260]; // [esp+414h] [ebp-214h] BYREF
  std::fstream file; // [esp+518h] [ebp-110h] BYREF
  std::fpos<int> *v99; // [esp+5D0h] [ebp-58h]
  int v100; // [esp+5D4h] [ebp-54h] BYREF
  int v101; // [esp+5D8h] [ebp-50h]
  __int64 v102; // [esp+5DCh] [ebp-4Ch]
  __int64 v103; // [esp+5E4h] [ebp-44h]
  unsigned int dwBinaryHeaderOffset; // [esp+5ECh] [ebp-3Ch]
  PrefabHeader *ph; // [esp+5F0h] [ebp-38h]
  CPrefabRMF *pPrefab; // [esp+5F4h] [ebp-34h]
  __int64 v107; // [esp+5F8h] [ebp-30h] BYREF
  __int64 v108; // [esp+600h] [ebp-28h]
  __int64 v109; // [esp+608h] [ebp-20h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTempFileName; // [esp+610h] [ebp-18h] BYREF
  char *pCopyBuf; // [esp+614h] [ebp-14h]
  CPrefabLibraryRMF *v112; // [esp+618h] [ebp-10h]
  int v113; // [esp+624h] [ebp-4h]
  std::fstream *p; // [esp+630h] [ebp+8h]
  __POSITION *pa; // [esp+630h] [ebp+8h]
  int bIndexOnlya; // [esp+634h] [ebp+Ch]
  int bIndexOnlyb; // [esp+634h] [ebp+Ch]

  v3 = this;
  v112 = this;
  if ( bIndexOnly != 0 && *(_DWORD *)&this->m_file._Filebuffer[12] != 0 )
  {
    p_m_file = &this->m_file;
    p = &this->m_file;
    if ( std::filebuf::close(this: (std::filebuf *)&this->m_file.gap10[8]) == nullptr )
    {
      v5 = *(_DWORD *)(*(_DWORD *)p_m_file->gap0 + 4);
      v6 = *(_DWORD *)&p_m_file->gap0[v5 + 12];
      v7 = (std::ios_base *)&p_m_file->gap0[v5];
      v8 = v6 | 2;
      if ( v7[1].__vftable == nullptr )
        v8 |= 4u;
      std::ios_base::clear(this: v7, _State: v8, _Reraise: false);
    }
    if ( v3->Prefabs.m_nCount != 0 )
    {
      v9 = _open(path: v3->m_strOpenFileName.m_pszData, oflag: 32769, pmode: 0);
      _chsize(filedes: v9, size: v3->m_dwDirOffset);
      _close(fh: v9);
    }
    std::fstream::fstream(
      this: (std::fstream *)&szNewFilename[76],
      _Filename: v3->m_strOpenFileName.m_pszData,
      _Mode: 34,
      _Prot: 64,
      a5: 1);
    v113 = 0;
    std::operator<<<std::char_traits<char>>(_Ostr: (std::ostream *)&szNewFilename[92], _Val: pLibHeader);
    m_nCount = v3->Prefabs.m_nCount;
    m_dwDirOffset = v3->m_dwDirOffset;
    szNotes = v3->szNotes;
    v94 = m_nCount;
    *(float *)_Str = fLibVersion;
    do
    {
      v12 = *szNotes;
      szNotes[v95 - v3->szNotes] = *szNotes;
      ++szNotes;
    }
    while ( v12 != 0 );
    std::ostream::write(this: (std::ostream *)&szNewFilename[92], _Str, _Count: 516);
    v13 = (const char *)operator new[](nSize: 544 * v3->Prefabs.m_nCount);
    m_pNodeHead = v3->Prefabs.m_pNodeHead;
    v15 = v13;
    bIndexOnlya = (int)v13;
    if ( m_pNodeHead != nullptr )
    {
      v16 = (char *)(v13 + 8);
      do
      {
        data = (char *)m_pNodeHead->data;
        m_pNodeHead = m_pNodeHead->pNext;
        *((_DWORD *)v16 - 2) = *((_DWORD *)data + 136);
        v18 = data + 4;
        *((_DWORD *)v16 - 1) = *((_DWORD *)data + 137);
        do
        {
          v19 = *v18;
          v18[v16 - (data + 4)] = *v18;
          ++v18;
        }
        while ( v19 != 0 );
        v20 = data + 35;
        do
        {
          v21 = *v20;
          v20[v16 - (data + 35) + 31] = *v20;
          ++v20;
        }
        while ( v21 != 0 );
        *((_DWORD *)v16 + 133) = (*(int (__thiscall **)(char *))(*(_DWORD *)data + 16))(a1: data);
        v16 += 544;
      }
      while ( m_pNodeHead != nullptr );
      v3 = v112;
      v15 = (const char *)bIndexOnlya;
    }
    v91._Myoff = v3->m_dwDirOffset;
    memset(&v91._Fpos, 0, 12);
    std::ostream::seekp(this: (std::ostream *)&szNewFilename[92], _Pos: v91);
    std::ostream::write(
      this: (std::ostream *)&szNewFilename[92],
      _Str: v15,
      _Count: (unsigned int)(544 * v3->Prefabs.m_nCount));
    if ( std::filebuf::close(this: (std::filebuf *)&szNewFilename[100]) == nullptr )
    {
      v22 = *(_DWORD *)(*(_DWORD *)&szNewFilename[76] + 4);
      v23 = *(_DWORD *)&szNewFilename[v22 + 88];
      v24 = (std::ios_base *)&szNewFilename[v22 + 76];
      v25 = v23 | 2;
      if ( v24[1].__vftable == nullptr )
        v25 |= 4u;
      std::ios_base::clear(this: v24, _State: v25, _Reraise: false);
    }
    std::fstream::open(this: p, _Filename: v3->m_strOpenFileName.m_pszData, _Mode: 33, _Prot: 64);
    v113 = -1;
    std::fstream::~fstream<char,std::char_traits<char>>(this: (std::fstream *)&szNewFilename[188]);
    v113 = -1;
    *(_DWORD *)&szNewFilename[188] = &std::ios_base::`vftable';
    std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)&szNewFilename[188]);
  }
  else
  {
    if ( pszFilename != nullptr )
    {
      strcpy(szFile, (const char *)pszFilename);
      strrchr(string: (unsigned __int8 *)pszFilename, chr: 0x5Cu);
      if ( v30 != nullptr )
        v31 = v30 + 1;
      else
        v31 = pszFilename;
      v32 = v3->m_szName - (char *)v31;
      do
      {
        v33 = *v31;
        v31[v32] = *v31;
        ++v31;
      }
      while ( v33 != 0 );
      strchr(string: v3->m_szName, chr: 0x2Eu);
      if ( v34 != nullptr )
        *v34 = 0;
    }
    else
    {
      if ( *((_DWORD *)this->m_strOpenFileName.m_pszData - 3) == 0 )
      {
        ModuleState = AfxGetModuleState();
        CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PREFABS, p: szNewFilename);
        sprintf(string: &szNewFilename[strlen(szNewFilename)], format: "\\%s.ol", v3->m_szName);
        ATL::CSimpleStringT<char,0>::SetString(
          this: &v3->m_strOpenFileName,
          pszSrc: szNewFilename,
          nLength: strlen(szNewFilename));
      }
      m_pszData = v3->m_strOpenFileName.m_pszData;
      v28 = szFile;
      do
      {
        v29 = *m_pszData;
        *v28++ = *m_pszData++;
      }
      while ( v29 != 0 );
    }
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &strTempFileName,
      pszSrc: "Temporary Prefab Library.$$$");
    v113 = 2;
    std::fstream::fstream(this: &file, a2: 1);
    LOBYTE(v113) = 3;
    if ( std::filebuf::open(
           this: (std::filebuf *)&file.gap10[8],
           _Filename: strTempFileName.m_pszData,
           _Mode: 34,
           _Prot: 64) != nullptr )
    {
      v39 = *(_DWORD *)(*(_DWORD *)file.gap0 + 4);
      v40 = *(_DWORD *)&file.gap10[v39 + 40];
      v37 = (std::ios_base *)&file.gap0[v39];
      v38 = v40 != 0 ? 0 : 4;
    }
    else
    {
      v35 = *(_DWORD *)(*(_DWORD *)file.gap0 + 4);
      v36 = *(_DWORD *)((char *)&file._Chcount + v35 + 4);
      v37 = (std::ios_base *)&file.gap0[v35];
      v38 = v36 | 2;
      if ( v37[1].__vftable == nullptr )
        v38 |= 4u;
    }
    std::ios_base::clear(this: v37, _State: v38, _Reraise: false);
    std::operator<<<std::char_traits<char>>(_Ostr: (std::ostream *)file.gap10, _Val: pLibHeader);
    v41 = *(_DWORD *)(*(_DWORD *)file.gap10 + 4);
    v42 = *(_DWORD *)&file.gap10[v41 + 12];
    v43 = &file.gap10[v41];
    if ( (v42 & 6) != 0 )
    {
      v44 = -1;
      HIDWORD(v107) = -1;
      v108 = 0;
    }
    else
    {
      (*(void (__thiscall **)(_DWORD, __int64 *, _DWORD, _DWORD, int, int))(**((_DWORD **)v43 + 14) + 40))(
        a1: *((_DWORD *)v43 + 14),
        a2: &v107,
        a3: 0,
        a4: 0,
        a5: 1,
        a6: 2);
      v44 = v107;
    }
    dwBinaryHeaderOffset = v108 + v44;
    plh.dwNumEntries = v3->Prefabs.m_nCount;
    v45 = v3->szNotes;
    plh.fVersion = fLibVersion;
    do
    {
      v46 = *v45;
      v45[plh.szNotes - v3->szNotes] = *v45;
      ++v45;
    }
    while ( v46 != 0 );
    std::ostream::write(this: (std::ostream *)file.gap10, _Str: (const char *)&plh, _Count: 516);
    v47 = (PrefabHeader *)operator new[](nSize: 544 * plh.dwNumEntries);
    ph = v47;
    pCopyBuf = (char *)operator new[](nSize: 0xFA00u);
    pa = (__POSITION *)v3->Prefabs.m_pNodeHead;
    if ( pa != nullptr )
    {
      bIndexOnlyb = (int)v47->szNotes;
      do
      {
        v48 = 0;
        v49 = *(CPrefabRMF **)&pa[8];
        v50 = *(_DWORD *)(*(_DWORD *)file.gap10 + 4);
        v51 = (file.gap10[v50 + 12] & 6) == 0;
        v52 = &file.gap10[v50];
        pa = *(__POSITION **)pa;
        pPrefab = v49;
        if ( v51 )
        {
          (*(void (__thiscall **)(_DWORD, __int64 *, _DWORD, _DWORD, int, int))(**((_DWORD **)v52 + 14) + 40))(
            a1: *((_DWORD *)v52 + 14),
            a2: &v107,
            a3: 0,
            a4: 0,
            a5: 1,
            a6: 2);
          v53 = v107;
        }
        else
        {
          v53 = -1;
          HIDWORD(v107) = -1;
          v108 = 0;
        }
        *(_DWORD *)(bIndexOnlyb - 39) = v108 + v53;
        szName = v49->szName;
        do
        {
          v55 = *szName;
          szName[bIndexOnlyb - (_DWORD)v49->szName - 31] = *szName;
          ++szName;
        }
        while ( v55 != 0 );
        v56 = v49->szNotes;
        do
        {
          v57 = *v56;
          v56[bIndexOnlyb - (_DWORD)v49->szNotes] = *v56;
          ++v56;
        }
        while ( v57 != 0 );
        *(_DWORD *)(bIndexOnlyb + 501) = v49->GetType(this: v49);
        if ( v49->IsLoaded(this: v49) )
        {
          CPrefabRMF::Save(this: v49, &file, dwFlags: 4u);
        }
        else
        {
          v91._Myoff = v49->dwFileOffset;
          v99 = &v91;
          memset(&v91._Fpos, 0, 12);
          std::istream::seekg(this: &v112->m_file, _Pos: v91);
          v58 = 64000;
          while ( 1 )
          {
            dwFileSize = v49->dwFileSize;
            if ( v48 + 64000 > dwFileSize )
              v58 = dwFileSize - v48;
            std::istream::read(this: &v112->m_file, _Str: pCopyBuf, _Count: (unsigned int)v58);
            std::ostream::write(this: (std::ostream *)file.gap10, _Str: pCopyBuf, _Count: (unsigned int)v58);
            v48 += v58;
            if ( v58 != 64000 )
              break;
            v49 = pPrefab;
          }
        }
        v60 = pPrefab;
        pPrefab->dwFileOffset = *(_DWORD *)(bIndexOnlyb - 39);
        v61 = *(_DWORD *)(*(_DWORD *)file.gap10 + 4);
        v51 = (file.gap10[v61 + 12] & 6) == 0;
        v62 = &file.gap10[v61];
        if ( v51 )
        {
          (*(void (__thiscall **)(_DWORD, __int64 *, _DWORD, _DWORD, int, int))(**((_DWORD **)v62 + 14) + 40))(
            a1: *((_DWORD *)v62 + 14),
            a2: &v107,
            a3: 0,
            a4: 0,
            a5: 1,
            a6: 2);
          v63 = HIDWORD(v107);
          v64 = v107;
        }
        else
        {
          v64 = -1;
          v63 = -1;
          v107 = -1;
          v108 = 0;
          LODWORD(v109) = 0;
        }
        v65 = v64 < *(_DWORD *)(bIndexOnlyb - 39);
        v66 = v64 - *(_DWORD *)(bIndexOnlyb - 39);
        v100 = v107;
        v102 = v108;
        v67 = v108 + v66;
        v68 = v109;
        v60->dwFileSize = v67;
        *(_DWORD *)(bIndexOnlyb - 35) = v67;
        v103 = v68;
        v101 = v63 - v65;
        bIndexOnlyb += 544;
      }
      while ( pa != nullptr );
      v47 = ph;
      v3 = v112;
    }
    operator delete(p: pCopyBuf);
    v69 = &file.gap10[*(_DWORD *)(*(_DWORD *)file.gap10 + 4)];
    if ( (v69[12] & 6) != 0 )
    {
      v70 = -1;
      v101 = -1;
      v102 = 0;
    }
    else
    {
      (*(void (__thiscall **)(_DWORD, int *, _DWORD, _DWORD, int, int))(**((_DWORD **)v69 + 14) + 40))(
        a1: *((_DWORD *)v69 + 14),
        a2: &v100,
        a3: 0,
        a4: 0,
        a5: 1,
        a6: 2);
      v70 = v100;
    }
    v71 = v102 + v70;
    v72 = dwBinaryHeaderOffset;
    v3->m_dwDirOffset = v71;
    plh.dwDirOffset = v71;
    v91._Myoff = v72;
    memset(&v91._Fpos, 0, 12);
    std::ostream::seekp(this: (std::ostream *)file.gap10, _Pos: v91);
    std::ostream::write(this: (std::ostream *)file.gap10, _Str: (const char *)&plh, _Count: 516);
    std::ostream::seekp(this: (std::ostream *)file.gap10, _Off: 0, _Way: 2);
    std::ostream::write(this: (std::ostream *)file.gap10, _Str: (const char *)v47, _Count: 544 * plh.dwNumEntries);
    if ( std::filebuf::close(this: (std::filebuf *)&file.gap10[8]) == nullptr )
    {
      v73 = *(_DWORD *)(*(_DWORD *)file.gap0 + 4);
      v74 = *(_DWORD *)((char *)&file._Chcount + v73 + 4);
      v75 = (std::ios_base *)&file.gap0[v73];
      v76 = v74 | 2;
      if ( v75[1].__vftable == nullptr )
        v76 |= 4u;
      std::ios_base::clear(this: v75, _State: v76, _Reraise: false);
    }
    v77 = &v3->m_file;
    if ( std::filebuf::close(this: (std::filebuf *)&v3->m_file.gap10[8]) == nullptr )
    {
      v78 = *(_DWORD *)(*(_DWORD *)v77->gap0 + 4);
      v79 = *(_DWORD *)&v77->gap0[v78 + 12];
      v80 = (std::ios_base *)&v77->gap0[v78];
      v81 = v79 | 2;
      if ( v80[1].__vftable == nullptr )
        v81 |= 4u;
      std::ios_base::clear(this: v80, _State: v81, _Reraise: false);
    }
    v82 = (ATL::CSimpleStringT<char,0> *)v112;
    remove(path: v112->m_strOpenFileName.m_pszData);
    ATL::CSimpleStringT<char,0>::SetString(this: v82 + 191, pszSrc: szFile, nLength: strlen(szFile));
    rename(oldname: strTempFileName.m_pszData, newname: v82[191].m_pszData);
    if ( std::filebuf::open(this: (std::filebuf *)&v77->gap10[8], _Filename: v82[191].m_pszData, _Mode: 33, _Prot: 64) != nullptr )
    {
      v87 = *(_DWORD *)(*(_DWORD *)v77->gap0 + 4);
      v88 = *(_DWORD *)&v77->gap10[v87 + 40];
      v85 = (std::ios_base *)&v77->gap0[v87];
      v86 = v88 != 0 ? 0 : 4;
    }
    else
    {
      v83 = *(_DWORD *)(*(_DWORD *)v77->gap0 + 4);
      v84 = *(_DWORD *)&v77->gap0[v83 + 12];
      v85 = (std::ios_base *)&v77->gap0[v83];
      v86 = v84 | 2;
      if ( v85[1].__vftable == nullptr )
        v86 |= 4u;
    }
    std::ios_base::clear(this: v85, _State: v86, _Reraise: false);
    LOBYTE(v113) = 2;
    std::fstream::~fstream<char,std::char_traits<char>>(this: (std::fstream *)file.gap70);
    LOBYTE(v113) = 2;
    *(_DWORD *)file.gap70 = &std::ios_base::`vftable';
    std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)file.gap70);
    v113 = -1;
    v89 = strTempFileName.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)strTempFileName.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v89 + 4))(a1: v89);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008FF20
// Name: class CPrefabLibrary __near * CreatePrefabLibrary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPrefabLibrary *__cdecl CreatePrefabLibrary(const char *szFile)
{
  CPrefabLibraryVMF *v1; // eax
  CPrefabLibraryRMF *v2; // eax
  CPrefabLibraryRMF *v3; // eax
  CPrefabLibrary *v4; // esi

  if ( _V_stricmp(s1: &szFile[strlen(szFile) - 2], s2: ".ol") != 0 )
  {
    v1 = (CPrefabLibraryVMF *)operator new(nSize: 0x340u);
    if ( v1 != nullptr )
    {
      v2 = (CPrefabLibraryRMF *)CPrefabLibraryVMF::CPrefabLibraryVMF(this: v1);
      goto LABEL_7;
    }
  }
  else
  {
    v3 = (CPrefabLibraryRMF *)operator new(nSize: 0x300u);
    if ( v3 != nullptr )
    {
      v2 = CPrefabLibraryRMF::CPrefabLibraryRMF(this: v3);
      goto LABEL_7;
    }
  }
  v2 = nullptr;
LABEL_7:
  v4 = v2;
  if ( v2->Load(this: v2, a2: szFile) != -1 )
    return v4;
  CPrefabLibrary::~CPrefabLibrary(this: v4);
  operator delete(p: v4);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10090000
// Name: public: static enum CPrefab::pfiletype_t CPrefab::CheckFileType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CPrefab::CheckFileType(char *pszFilename)
{
  const char *v1; // eax
  const char *v2; // esi
  int v4; // esi
  char v5; // al
  char szBuf[255]; // [esp+8h] [ebp-1C8h] BYREF
  std::fstream file; // [esp+108h] [ebp-C8h] BYREF
  _BYTE *v8; // [esp+1C0h] [ebp-10h]
  int v9; // [esp+1CCh] [ebp-4h]

  strrchr(string: (unsigned __int8 *)pszFilename, chr: 0x2Eu);
  v2 = v1;
  if ( v1 != nullptr )
  {
    if ( _V_stricmp(s1: v1, s2: ".rmf") == 0 )
      return 1;
    if ( _V_stricmp(s1: v2, s2: ".map") == 0 )
      return 2;
    if ( _V_stricmp(s1: v2, s2: ".os") == 0 )
      return 3;
  }
  std::fstream::fstream(this: &file, _Filename: pszFilename, _Mode: 33, _Prot: 64, a5: 1);
  v9 = 0;
  std::istream::read(this: &file, _Str: szBuf, _Count: 16);
  if ( *(float *)szBuf > 0.69999999 && strncmp(first: &szBuf[4], last: "RMF", count: 3u) != 0 )
  {
    if ( V_strncasecmp(s1: szBuf, s2: "[Script", n: 7) == 0 )
    {
      v9 = -1;
      std::fstream::`vbase destructor'(this: &file);
      return 3;
    }
    v4 = 500;
    while ( 1 )
    {
      --v4;
      std::ws(_Istr: &file);
      v5 = std::ios::widen(this: (std::ios *)&file.gap0[*(_DWORD *)(*(_DWORD *)file.gap0 + 4)], _Byte: 10);
      std::istream::getline(this: &file, _Str: szBuf, _Count: 255, _Delim: v5);
      if ( szBuf[0] == 123 )
        break;
      if ( (*((_BYTE *)&file._Chcount + *(_DWORD *)(*(_DWORD *)file.gap0 + 4) + 4) & 1) != 0 || v4 == 0 )
      {
        v9 = -1;
        std::fstream::`vbase destructor'(this: &file);
        return 0;
      }
    }
    v9 = -1;
    std::fstream::`vbase destructor'(this: &file);
    return 2;
  }
  v9 = -1;
  std::fstream::~fstream<char,std::char_traits<char>>(this: (std::fstream *)file.gap70);
  v8 = file.gap70;
  v9 = -1;
  *(_DWORD *)file.gap70 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)file.gap70);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090220
// Name: public: static void CPrefabLibrary::LoadAllLibraries(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPrefabLibrary::LoadAllLibraries()
{
  AFX_MODULE_STATE *ModuleState; // eax
  CPrefabLibrary *OpenLibrary; // eax
  CObject *PrefabLibrary; // eax
  char *v3; // eax
  char v4; // cl
  HANDLE FirstFileA; // esi
  _BYTE *v6; // eax
  CPrefabLibrary *v7; // eax
  CObject *v8; // eax
  char szFile[260]; // [esp+0h] [ebp-348h] BYREF
  _WIN32_FIND_DATAA fd; // [esp+104h] [ebp-244h] BYREF
  char szDir[260]; // [esp+244h] [ebp-104h] BYREF

  ModuleState = AfxGetModuleState();
  CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PREFABS, p: szDir);
  OpenLibrary = CPrefabLibrary::FindOpenLibrary(pszFilename: szDir);
  if ( OpenLibrary != nullptr )
  {
    OpenLibrary->Load(this: OpenLibrary, a2: szDir);
  }
  else
  {
    PrefabLibrary = (CObject *)CreatePrefabLibrary(szFile: szDir);
    if ( PrefabLibrary != nullptr )
      CPtrList::AddTail(this: (CObList *)&CPrefabLibrary::PrefabLibraryList, newElement: PrefabLibrary);
  }
  v3 = &fd.cAlternateFileName[15];
  do
    v4 = *++v3;
  while ( v4 != 0 );
  strcpy(v3, "\\*.*");
  FirstFileA = FindFirstFileA(lpFileName: szDir, lpFindFileData: &fd);
  strrchr(string: (unsigned __int8 *)szDir, chr: 0x5Cu);
  *v6 = 0;
  if ( FirstFileA != (HANDLE)-1 )
  {
    do
    {
      if ( (fd.dwFileAttributes & 0x10) != 0 && fd.cFileName[0] != 46 )
      {
        sprintf(string: szFile, format: "%s\\%s", szDir, fd.cFileName);
        v7 = CPrefabLibrary::FindOpenLibrary(pszFilename: szFile);
        if ( v7 != nullptr )
        {
          v7->Load(this: v7, a2: szDir);
        }
        else
        {
          v8 = (CObject *)CreatePrefabLibrary(szFile);
          if ( v8 != nullptr )
            CPtrList::AddTail(this: (CObList *)&CPrefabLibrary::PrefabLibraryList, newElement: v8);
        }
      }
    }
    while ( FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &fd) );
    FindClose(hFindFile: FirstFileA);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033F7B4
// Name: public: void const __near * CPtrList::GetNext(struct __POSITION __near * __near &)const
// Source: json
//------------------------------------------------------------------------------
const void *__thiscall CPtrList::GetNext(CPtrList *this, __POSITION **rPosition)
{
  int v2; // eax

  v2 = (int)*rPosition;
  if ( *rPosition == nullptr )
    AfxThrowInvalidArgException();
  *rPosition = *(__POSITION **)v2;
  return *(const void **)(v2 + 8);
}

//------------------------------------------------------------------------------
// Address: 0x10351D57
// Name: public: virtual struct CRuntimeClass __near * CPtrList::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPtrList::GetRuntimeClass(CPtrList *this)
{
  return &CPtrList::classCPtrList;
}

//------------------------------------------------------------------------------
// Address: 0x10351D5D
// Name: public: CPtrList::CPtrList(int)
// Source: json
//------------------------------------------------------------------------------
CPtrList *__thiscall CPtrList::CPtrList(CPtrList *this, int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CPtrList_vtbl *)&CPtrList::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10351D85
// Name: public: virtual CPtrList::~CPtrList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPtrList::~CPtrList(CPtrList *this)
{
  this->__vftable = (CPtrList_vtbl *)&CPtrList::`vftable';
  CObList::RemoveAll((CObList *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10351E17
// Name: public: struct __POSITION __near * CPtrList::AddTail(void __near *)
// Source: json
//------------------------------------------------------------------------------
CObList::CNode *__thiscall CPtrList::AddTail(CObList *this, CObject *newElement)
{
  CObList::CNode *result; // eax
  CObList::CNode *m_pNodeTail; // ecx

  result = CObList::NewNode(this, pPrev: this->m_pNodeTail, pNext: nullptr);
  result->data = newElement;
  m_pNodeTail = this->m_pNodeTail;
  if ( m_pNodeTail != nullptr )
    m_pNodeTail->pNext = result;
  else
    this->m_pNodeHead = result;
  this->m_pNodeTail = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036997C
// Name: public: int ATL::CAtlTransactionManager::DeleteFileA(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall ATL::CAtlTransactionManager::DeleteFileA(ATL::CAtlTransactionManager *this, const char *lpFileName)
{
  HMODULE ModuleHandleA; // eax
  BOOL (__stdcall *DeleteFileTransactedA)(LPCSTR, HANDLE); // eax

  if ( this->m_hTransaction != nullptr )
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "kernel32.dll");
    if ( ModuleHandleA != nullptr )
    {
      DeleteFileTransactedA = (BOOL (__stdcall *)(LPCSTR, HANDLE))GetProcAddress(
                                                                    hModule: ModuleHandleA,
                                                                    lpProcName: "DeleteFileTransactedA");
      if ( DeleteFileTransactedA != nullptr )
        return DeleteFileTransactedA(lpFileName, hTransaction: this->m_hTransaction);
    }
  }
  else if ( this->m_bFallback != 0 )
  {
    return DeleteFileA(lpFileName);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x103E2863
// Name: public: void CPtrList::RemoveAt(struct __POSITION __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPtrList::RemoveAt(CObList *this, __POSITION *position)
{
  if ( position == nullptr )
    AfxThrowInvalidArgException();
  if ( position == (__POSITION *)this->m_pNodeHead )
    this->m_pNodeHead = *(CObList::CNode **)position;
  else
    **(_DWORD **)&position[4] = *(_DWORD *)position;
  if ( position == (__POSITION *)this->m_pNodeTail )
    this->m_pNodeTail = *(CObList::CNode **)&position[4];
  else
    *(_DWORD *)(*(_DWORD *)position + 4) = *(_DWORD *)&position[4];
  CObList::FreeNode(this, pNode: (CObList::CNode *)position);
}

//------------------------------------------------------------------------------
// Address: 0x103E28A8
// Name: public: struct __POSITION __near * CPtrList::Find(void __near *,struct __POSITION __near *)const
// Source: json
//------------------------------------------------------------------------------
CObList::CNode *__thiscall CPtrList::Find(CObList *this, CObject *searchValue, __POSITION *startAfter)
{
  CObList::CNode *result; // eax

  result = (CObList::CNode *)startAfter;
  if ( startAfter != nullptr )
    goto LABEL_4;
  for ( result = this->m_pNodeHead; result != nullptr && result->data != searchValue; result = result->pNext )
LABEL_4:
    ;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C0770
// Name: _dynamic_initializer_for__CPrefab::PrefabList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CPrefab::PrefabList__()
{
  CPtrList::CPtrList(this: &CPrefab::PrefabList, nBlockSize: 10);
  CPrefab::PrefabList.__vftable = (CTypedPtrList<CPtrList,CPrefab *>_vtbl *)&CTypedPtrList<CPtrList,CPrefab *>::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__CPrefab::PrefabList__);
}

//------------------------------------------------------------------------------
// Address: 0x105C07E0
// Name: _dynamic_initializer_for__CPrefab::MRU__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CPrefab::MRU__()
{
  CPtrList::CPtrList(this: &CPrefab::MRU, nBlockSize: 10);
  CPrefab::MRU.__vftable = (CTypedPtrList<CPtrList,CPrefab *>_vtbl *)&CTypedPtrList<CPtrList,CPrefab *>::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__CPrefab::MRU__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0850
// Name: _dynamic_initializer_for__CPrefabLibrary::PrefabLibraryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CPrefabLibrary::PrefabLibraryList__()
{
  CPtrList::CPtrList(this: &CPrefabLibrary::PrefabLibraryList, nBlockSize: 10);
  CPrefabLibrary::PrefabLibraryList.__vftable = (CTypedPtrList<CPtrList,CPrefabLibrary *>_vtbl *)&CTypedPtrList<CPtrList,CPrefabLibrary *>::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__CPrefabLibrary::PrefabLibraryList__);
}

//------------------------------------------------------------------------------
// Address: 0x105CA9E0
// Name: _dynamic_atexit_destructor_for__CPrefab::MRU__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CPrefab::MRU__()
{
  CPtrList::~CPtrList(this: &CPrefab::MRU);
}

//------------------------------------------------------------------------------
// Address: 0x105CAA20
// Name: _dynamic_atexit_destructor_for__CPrefab::PrefabList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CPrefab::PrefabList__()
{
  CPtrList::~CPtrList(this: &CPrefab::PrefabList);
}

//------------------------------------------------------------------------------
// Address: 0x105CAA60
// Name: _dynamic_atexit_destructor_for__CPrefabLibrary::PrefabLibraryList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CPrefabLibrary::PrefabLibraryList__()
{
  CPtrList::~CPtrList(this: &CPrefabLibrary::PrefabLibraryList);
}

//------------------------------------------------------------------------------
// Address: 0x10351D90
// Name: protected: struct CObList::CNode __near * CObList::NewNode(struct CObList::CNode __near *,struct CObList::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CObList::CNode *__thiscall CObList::NewNode(CObList *this, CObList::CNode *pPrev, CObList::CNode *pNext)
{
  CPlex *v4; // eax
  int v5; // ecx
  CObList::CNode *i; // eax
  CObList::CNode *result; // eax

  if ( this->m_pNodeFree == nullptr )
  {
    v4 = CPlex::Create(pHead: &this->m_pBlocks, nMax: this->m_nBlockSize, cbElement: 0xCu);
    v5 = this->m_nBlockSize - 1;
    for ( i = (CObList::CNode *)&v4[3 * this->m_nBlockSize - 2]; v5 >= 0; --v5 )
    {
      i->pNext = this->m_pNodeFree;
      this->m_pNodeFree = i--;
    }
  }
  result = this->m_pNodeFree;
  this->m_pNodeFree = result->pNext;
  result->pPrev = pPrev;
  result->pNext = pNext;
  ++this->m_nCount;
  result->data = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10351DE8
// Name: public: struct __POSITION __near * CObList::AddHead(class CObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CObList::CNode *__thiscall CObList::AddHead(CObList *this, CObject *newElement)
{
  CObList::CNode *result; // eax
  CObList::CNode *m_pNodeHead; // ecx

  result = CObList::NewNode(this, pPrev: nullptr, pNext: this->m_pNodeHead);
  result->data = newElement;
  m_pNodeHead = this->m_pNodeHead;
  if ( m_pNodeHead != nullptr )
    m_pNodeHead->pPrev = result;
  else
    this->m_pNodeTail = result;
  this->m_pNodeHead = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10351E6C
// Name: public: virtual struct CRuntimeClass __near * CDockState::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CDockState::GetRuntimeClass(CDockState *this)
{
  return &CDockState::classCDockState;
}

//------------------------------------------------------------------------------
// Address: 0x10351E72
// Name: class CArchive __near & operator>>(class CArchive __near &,struct tagPOINT __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CArchive *__stdcall operator>>(CArchive *ar, tagPOINT *point)
{
  if ( CArchive::Read(this: ar, lpBuf: point, nMax: 8u) != 8 )
    AfxThrowArchiveException(cause: 3, lpszArchiveName: nullptr);
  return ar;
}

//------------------------------------------------------------------------------
// Address: 0x10351E99
// Name: class CArchive __near & operator>>(class CArchive __near &,struct tagRECT __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CArchive *__stdcall operator>>(CArchive *ar, tagRECT *rect)
{
  if ( CArchive::Read(this: ar, lpBuf: rect, nMax: 0x10u) != 16 )
    AfxThrowArchiveException(cause: 3, lpszArchiveName: nullptr);
  return ar;
}

//------------------------------------------------------------------------------
// Address: 0x10351EC0
// Name: public: CControlBarInfo::CControlBarInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CControlBarInfo *__thiscall CControlBarInfo::CControlBarInfo(CControlBarInfo *this)
{
  CRect *p_m_rectMRUDockPos; // ebx

  this->m_pointPos.x = 0;
  this->m_pointPos.y = 0;
  p_m_rectMRUDockPos = &this->m_rectMRUDockPos;
  this->m_rectMRUDockPos.left = 0;
  this->m_rectMRUDockPos.top = 0;
  this->m_rectMRUDockPos.right = 0;
  this->m_rectMRUDockPos.bottom = 0;
  this->m_ptMRUFloatPos.x = 0;
  this->m_ptMRUFloatPos.y = 0;
  CUIntArray::CUIntArray(this: &this->m_arrBarID);
  this->m_pointPos.y = -1;
  this->m_pointPos.x = -1;
  this->m_nBarID = 0;
  this->m_bDocking = 0;
  this->m_bHorz = 0;
  this->m_bFloating = 0;
  this->m_bVisible = 0;
  this->m_bDockBar = 0;
  this->m_pBar = nullptr;
  this->m_nMRUWidth = 0x7FFF;
  this->m_uMRUDockID = 0;
  SetRectEmpty(lprc: p_m_rectMRUDockPos);
  this->m_dwMRUFloatStyle = 0;
  this->m_ptMRUFloatPos.y = 0;
  this->m_ptMRUFloatPos.x = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10351F2C
// Name: public: int CControlBarInfo::SaveState(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CControlBarInfo::SaveState(CControlBarInfo *this, const char *lpszProfileName, int nIndex)
{
  int v4; // ebx
  int *v5; // eax
  CWinApp *m_pCurrentWinApp; // edi
  int v7; // ebx
  char szSection[256]; // [esp+Ch] [ebp-114h] BYREF
  char buf[16]; // [esp+10Ch] [ebp-14h] BYREF

  v4 = *_errno();
  *_errno() = 0;
  _snprintf_s(string: szSection, sizeInBytes: 0x100u, count: 0xFFu, format: "%s-Bar%d", lpszProfileName, nIndex);
  if ( *_errno() != 0 )
  {
    v5 = _errno();
    ATL::AtlCrtErrorCheck(nError: *v5);
  }
  else
  {
    *_errno() = v4;
  }
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  v7 = 0;
  m_pCurrentWinApp->WriteProfileStringA(this: m_pCurrentWinApp, a2: szSection, a3: nullptr, a4: nullptr);
  if ( this->m_bDockBar != 0
    && this->m_bVisible != 0
    && this->m_bFloating == 0
    && this->m_pointPos.x == -1
    && this->m_pointPos.y == -1
    && this->m_arrBarID.m_nSize <= 1 )
  {
    return 0;
  }
  m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: szSection, a3: "BarID", a4: this->m_nBarID);
  if ( this->m_bVisible == 0 )
    m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: szSection, a3: "Visible", a4: 0);
  if ( this->m_bFloating != 0 )
  {
    m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: szSection, a3: "Horz", a4: this->m_bHorz);
    m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: szSection, a3: "Floating", a4: this->m_bFloating);
  }
  if ( this->m_pointPos.x != -1 )
    m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: szSection, a3: "XPos", a4: this->m_pointPos.x);
  if ( this->m_pointPos.y != -1 )
    m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: szSection, a3: "YPos", a4: this->m_pointPos.y);
  if ( this->m_nMRUWidth != 0x7FFF )
    m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: szSection, a3: "MRUWidth", a4: this->m_nMRUWidth);
  if ( this->m_bDocking != 0 )
  {
    m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: szSection, a3: "Docking", a4: this->m_bDocking);
    m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: szSection, a3: "MRUDockID", a4: this->m_uMRUDockID);
    m_pCurrentWinApp->WriteProfileInt(
      this: m_pCurrentWinApp,
      a2: szSection,
      a3: "MRUDockLeftPos",
      a4: this->m_rectMRUDockPos.left);
    m_pCurrentWinApp->WriteProfileInt(
      this: m_pCurrentWinApp,
      a2: szSection,
      a3: "MRUDockTopPos",
      a4: this->m_rectMRUDockPos.top);
    m_pCurrentWinApp->WriteProfileInt(
      this: m_pCurrentWinApp,
      a2: szSection,
      a3: "MRUDockRightPos",
      a4: this->m_rectMRUDockPos.right);
    m_pCurrentWinApp->WriteProfileInt(
      this: m_pCurrentWinApp,
      a2: szSection,
      a3: "MRUDockBottomPos",
      a4: this->m_rectMRUDockPos.bottom);
    m_pCurrentWinApp->WriteProfileInt(
      this: m_pCurrentWinApp,
      a2: szSection,
      a3: "MRUFloatStyle",
      a4: this->m_dwMRUFloatStyle);
    m_pCurrentWinApp->WriteProfileInt(
      this: m_pCurrentWinApp,
      a2: szSection,
      a3: "MRUFloatXPos",
      a4: this->m_ptMRUFloatPos.x);
    m_pCurrentWinApp->WriteProfileInt(
      this: m_pCurrentWinApp,
      a2: szSection,
      a3: "MRUFloatYPos",
      a4: this->m_ptMRUFloatPos.y);
  }
  if ( this->m_arrBarID.m_nSize > 1 )
  {
    m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: szSection, a3: "Bars", a4: this->m_arrBarID.m_nSize);
    if ( this->m_arrBarID.m_nSize > 0 )
    {
      do
      {
        sprintf_s(string: buf, sizeInBytes: 0x10u, format: "Bar#%d", v7);
        if ( v7 < 0 || v7 >= this->m_arrBarID.m_nSize )
          AfxThrowInvalidArgException();
        m_pCurrentWinApp->WriteProfileInt(
          this: m_pCurrentWinApp,
          a2: szSection,
          a3: buf,
          a4: this->m_arrBarID.m_pData[v7++]);
      }
      while ( v7 < this->m_arrBarID.m_nSize );
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1035220F
// Name: public: CDockState::CDockState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockState *__thiscall CDockState::CDockState(CDockState *this)
{
  int v2; // ebx

  this->__vftable = (CDockState_vtbl *)&CDockState::`vftable';
  CPtrArray::CPtrArray(this: &this->m_arrBarInfo);
  this->m_rectDevice.right = 0;
  this->m_rectDevice.bottom = 0;
  this->m_rectClip.left = 0;
  this->m_rectClip.top = 0;
  this->m_rectClip.right = 0;
  this->m_rectClip.bottom = 0;
  this->m_sizeLogical.cx = 0;
  this->m_sizeLogical.cy = 0;
  this->m_dwVersion = 2;
  this->m_bScaling = 0;
  this->m_rectDevice.left = 0;
  this->m_rectDevice.top = 0;
  this->m_rectDevice.right = GetSystemMetrics(nIndex: 0);
  this->m_rectDevice.bottom = GetSystemMetrics(nIndex: 1);
  this->m_rectClip.left = GetSystemMetrics(nIndex: 76);
  this->m_rectClip.top = GetSystemMetrics(nIndex: 77);
  this->m_rectClip.right = GetSystemMetrics(nIndex: 78);
  this->m_rectClip.bottom = GetSystemMetrics(nIndex: 79);
  this->m_rectClip.right -= GetSystemMetrics(nIndex: 11);
  v2 = this->m_rectClip.bottom - GetSystemMetrics(nIndex: 12);
  this->m_rectClip.bottom = v2 - GetSystemMetrics(nIndex: 51);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1035229C
// Name: public: void CDockState::Clear(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockState::Clear(CDockState *this)
{
  int i; // edi
  char *v3; // ebx

  for ( i = 0; i < this->m_arrBarInfo.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arrBarInfo.m_nSize )
      AfxThrowInvalidArgException();
    v3 = (char *)this->m_arrBarInfo.m_pData[i];
    if ( v3 != nullptr )
    {
      CUIntArray::~CUIntArray(this: (CUIntArray *)(v3 + 68));
      operator delete(p: v3);
    }
  }
  CUIntArray::SetSize(this: &this->m_arrBarInfo, nNewSize: 0, nGrowBy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x103522E8
// Name: public: void CDockState::ScalePoint(class CPoint __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockState::ScalePoint(CDockState *this, CPoint *pt)
{
  int v3; // ebx
  int right; // eax
  int bottom; // esi

  if ( this->m_bScaling != 0 )
  {
    v3 = this->m_rectDevice.bottom - this->m_rectDevice.top;
    pt->x = MulDiv(
              nNumber: pt->x,
              nNumerator: this->m_rectDevice.right - this->m_rectDevice.left,
              nDenominator: this->m_sizeLogical.cx);
    pt->y = MulDiv(nNumber: pt->y, nNumerator: v3, nDenominator: this->m_sizeLogical.cy);
  }
  right = this->m_rectClip.right;
  if ( pt->x > right )
    pt->x = right;
  bottom = this->m_rectClip.bottom;
  if ( pt->y > bottom )
    pt->y = bottom;
}

//------------------------------------------------------------------------------
// Address: 0x10352340
// Name: public: void CDockState::ScaleRectPos(class CRect __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockState::ScaleRectPos(CDockState *this, CRect *rect)
{
  int v3; // ebx
  int v4; // eax
  int left; // ecx
  int right; // eax
  int v7; // edx
  int v8; // ebx
  int top; // ecx
  int bottom; // eax
  int v11; // esi
  int pt; // [esp+Ch] [ebp-8h]
  int pt_4; // [esp+10h] [ebp-4h]

  if ( this->m_bScaling != 0 )
  {
    v3 = this->m_rectDevice.bottom - this->m_rectDevice.top;
    pt_4 = rect->top;
    pt = MulDiv(
           nNumber: rect->left,
           nNumerator: this->m_rectDevice.right - this->m_rectDevice.left,
           nDenominator: this->m_sizeLogical.cx)
       - rect->left;
    v4 = MulDiv(nNumber: pt_4, nNumerator: v3, nDenominator: this->m_sizeLogical.cy);
    OffsetRect(lprc: rect, dx: pt, dy: v4 - rect->top);
  }
  left = rect->left;
  right = this->m_rectClip.right;
  v7 = 0;
  v8 = 0;
  if ( rect->left > right || (right = this->m_rectClip.left, left < right) )
    v8 = right - left;
  top = rect->top;
  bottom = this->m_rectClip.bottom;
  if ( top <= bottom )
  {
    v11 = this->m_rectClip.top;
    if ( top < v11 )
      v7 = v11 - top;
  }
  else
  {
    v7 = bottom - top;
  }
  if ( v8 != 0 || v7 != 0 )
    OffsetRect(lprc: rect, dx: v8, dy: v7);
}

//------------------------------------------------------------------------------
// Address: 0x103523DF
// Name: public: void CDockState::SetScreenSize(class CSize __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockState::SetScreenSize(CDockState *this, CSize *size)
{
  tagPOINT v3; // [esp-8h] [ebp-Ch]

  this->m_sizeLogical = *size;
  v3.y = this->m_rectDevice.bottom - this->m_rectDevice.top;
  v3.x = this->m_rectDevice.right - this->m_rectDevice.left;
  this->m_bScaling = CPoint::operator!=(this: (CPoint *)size, point: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10352410
// Name: public: void CDockBar::GetBarInfo(class CControlBarInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockBar::GetBarInfo(CDockBar *this, CControlBarInfo *pInfo)
{
  int v3; // ebx
  HWND *v4; // eax
  void *DlgCtrlID; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-28h]
  CRect rect; // [esp+Ch] [ebp-14h] BYREF

  pInfo->m_bDockBar = 1;
  v3 = 0;
  pInfo->m_bFloating = this->m_bFloating;
  if ( this->m_bFloating != 0 )
  {
    m_hWnd = this->m_hWnd;
    memset(&rect, 0, sizeof(rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
    pInfo->m_pointPos.x = rect.left;
    pInfo->m_pointPos.y = rect.top;
  }
  pInfo->m_bHorz = (this->m_dwStyle & 0xA000) != 0;
  if ( this->m_arrBars.m_nSize > 0 )
  {
    do
    {
      if ( v3 < 0 || v3 >= this->m_arrBars.m_nSize )
        AfxThrowInvalidArgException();
      v4 = (HWND *)this->m_arrBars.m_pData[v3];
      if ( v4 != nullptr )
      {
        if ( (unsigned int)v4 > 0xFFFF )
          DlgCtrlID = (void *)GetDlgCtrlID(hWnd: v4[8]);
        else
          DlgCtrlID = (void *)((unsigned __int16)v4 | 0x10000);
      }
      else
      {
        DlgCtrlID = nullptr;
      }
      CUIntArray::SetAtGrow(
        this: (CPtrArray *)&pInfo->m_arrBarID,
        nIndex: pInfo->m_arrBarID.m_nSize,
        newElement: DlgCtrlID);
      ++v3;
    }
    while ( v3 < this->m_arrBars.m_nSize );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103524E8
// Name: public: static class CObject __near * CDockState::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockState *__stdcall CDockState::CreateObject()
{
  CDockState *v0; // ecx
  CDockState *result; // eax

  v0 = (CDockState *)operator new(nSize: 0x48u);
  result = nullptr;
  if ( v0 != nullptr )
    return CDockState::CDockState(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103699C6
// Name: public: int ATL::CAtlTransactionManager::MoveFileA(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall ATL::CAtlTransactionManager::MoveFileA(
        ATL::CAtlTransactionManager *this,
        const char *lpOldFileName,
        const char *lpNewFileName)
{
  HMODULE ModuleHandleA; // eax
  BOOL (__stdcall *MoveFileTransactedA)(LPCSTR, LPCSTR, LPPROGRESS_ROUTINE, LPVOID, DWORD, HANDLE); // eax

  if ( this->m_hTransaction != nullptr )
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "kernel32.dll");
    if ( ModuleHandleA != nullptr )
    {
      MoveFileTransactedA = (BOOL (__stdcall *)(LPCSTR, LPCSTR, LPPROGRESS_ROUTINE, LPVOID, DWORD, HANDLE))GetProcAddress(hModule: ModuleHandleA, lpProcName: "MoveFileTransactedA");
      if ( MoveFileTransactedA != nullptr )
        return MoveFileTransactedA(
                 lpExistingFileName: lpOldFileName,
                 lpNewFileName,
                 lpProgressRoutine: nullptr,
                 lpData: nullptr,
                 dwFlags: 2,
                 hTransaction: this->m_hTransaction);
    }
  }
  else if ( this->m_bFallback != 0 )
  {
    return MoveFileA(lpExistingFileName: lpOldFileName, lpNewFileName);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10369A19
// Name: public: virtual unsigned int CFile::Read(void __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __thiscall CFile::Read(CFile *this, void *lpBuf, DWORD nCount)
{
  DWORD LastError; // eax
  char *m_pszData; // [esp-4h] [ebp-8h]

  if ( nCount == 0 )
    return 0;
  if ( !ReadFile(
          hFile: this->m_hFile,
          lpBuffer: lpBuf,
          nNumberOfBytesToRead: nCount,
          lpNumberOfBytesRead: &nCount,
          lpOverlapped: nullptr) )
  {
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
  return nCount;
}

//------------------------------------------------------------------------------
// Address: 0x103E28CB
// Name: public: virtual struct CRuntimeClass __near * CObList::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CObList::GetRuntimeClass(CObList *this)
{
  return &CObList::classCObList;
}

//------------------------------------------------------------------------------
// Address: 0x103E28D1
// Name: public: CObList::CObList(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CObList *__thiscall CObList::CObList(CObList *this, int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CObList_vtbl *)&CObList::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103E28F9
// Name: public: virtual CObList::~CObList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CObList::~CObList(CObList *this)
{
  this->__vftable = (CObList_vtbl *)&CObList::`vftable';
  CObList::RemoveAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x103E2904
// Name: public: void CObList::AddTail(class CObList __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CObList::AddTail(CObList *this, CObList *pNewList)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // [esp-4h] [ebp-Ch]

  if ( pNewList == nullptr )
    AfxThrowInvalidArgException();
  m_pNodeHead = pNewList->m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    CPtrList::AddTail(this, newElement: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E293A
// Name: public: struct __POSITION __near * CObList::InsertBefore(struct __POSITION __near *,class CObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CObList::CNode *__thiscall CObList::InsertBefore(CObList *this, __POSITION *position, CObject *newElement)
{
  CObList::CNode *result; // eax
  CObList::CNode **v5; // ecx

  if ( position == nullptr )
    return CObList::AddHead(this, newElement);
  result = CObList::NewNode(this, pPrev: *(CObList::CNode **)&position[4], pNext: (CObList::CNode *)position);
  result->data = newElement;
  v5 = *(CObList::CNode ***)&position[4];
  if ( v5 != nullptr )
    *v5 = result;
  else
    this->m_pNodeHead = result;
  *(_DWORD *)&position[4] = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103E297A
// Name: public: struct __POSITION __near * CObList::InsertAfter(struct __POSITION __near *,class CObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CObList::CNode *__thiscall CObList::InsertAfter(CObList *this, __POSITION *position, CObject *newElement)
{
  CObList::CNode *result; // eax

  if ( position == nullptr )
    return CPtrList::AddTail(this, newElement);
  result = CObList::NewNode(this, pPrev: (CObList::CNode *)position, pNext: *(CObList::CNode **)position);
  result->data = newElement;
  if ( *(_DWORD *)position != 0 )
    *(_DWORD *)(*(_DWORD *)position + 4) = result;
  else
    this->m_pNodeTail = result;
  *(_DWORD *)position = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C08C0
// Name: _dynamic_initializer_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_definevariable__()
{
  g_definevariable.m_Size = 0;
  g_definevariable.m_pElements = g_definevariable.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__g_definevariable__);
}

//------------------------------------------------------------------------------
// Address: 0x105CAAA0
// Name: _dynamic_atexit_destructor_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_definevariable__()
{
  variable_t *m_pMemory; // eax

  m_pMemory = g_definevariable.m_Memory.m_pMemory;
  g_definevariable.m_Size = 0;
  if ( g_definevariable.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_definevariable.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_definevariable.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_definevariable.m_Memory.m_pMemory = nullptr;
    }
    g_definevariable.m_Memory.m_nAllocationCount = 0;
  }
  g_definevariable.m_pElements = m_pMemory;
  if ( g_definevariable.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_definevariable.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_definevariable.m_Memory.m_pMemory);
      g_definevariable.m_Memory.m_pMemory = nullptr;
    }
    g_definevariable.m_Memory.m_nAllocationCount = 0;
  }
}
