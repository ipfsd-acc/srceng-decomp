// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/src/buffer.cpp
// Functions: 220
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\src\buffer.h"

//------------------------------------------------------------------------------
// Address: 0x00422A60
// Name: public: yaSSL::input_buffer::~input_buffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::input_buffer::~input_buffer(CUtlString *this)
{
  yaSSL::ysArrayDelete<unsigned char>(ptr: (unsigned __int8 *)this->m_Storage.m_Memory.m_nGrowSize);
}

//------------------------------------------------------------------------------
// Address: 0x0042BEF0
// Name: public: void yaSSL::output_buffer::set_current(unsigned int)
// Source: json
//------------------------------------------------------------------------------
QueuedPacket_t **__thiscall yaSSL::output_buffer::set_current(
        CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *this,
        QueuedPacket_t **c)
{
  this->m_Memory.m_pMemory = c;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x0043B960
// Name: public: yaSSL::input_buffer::input_buffer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall yaSSL::input_buffer::input_buffer(int this, const CSplitScreenAddedConVar *result)
{
  CSplitScreenAddedConVar *v3; // eax

  *(_DWORD *)this = 0;
  *(_DWORD *)(this + 4) = 0;
  v3 = operator new[](sz: (const CSplitScreenAddedConVar *)this, sza: result);
  *(_DWORD *)(this + 8) = v3;
  *(_DWORD *)(this + 12) = (char *)v3 + (_DWORD)result;
  return (const CUtlString *)this;
}

//------------------------------------------------------------------------------
// Address: 0x0043B9A0
// Name: public: void yaSSL::input_buffer::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::input_buffer::allocate(CUtlString *this@<ecx>, const char *s, int a3)
{
  int v4; // eax

  v4 = (int)operator new[](sz: (const CSplitScreenAddedConVar *)this, sza: (const CSplitScreenAddedConVar *)s);
  this->m_Storage.m_Memory.m_nGrowSize = v4;
  this->m_Storage.m_nActualLength = (int)&s[v4];
}

//------------------------------------------------------------------------------
// Address: 0x0043B9D0
// Name: public: unsigned int yaSSL::input_buffer::get_capacity(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::input_buffer::get_capacity(CUtlString *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0043B9E0
// Name: public: unsigned int yaSSL::input_buffer::get_remaining(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::input_buffer::get_remaining(CUtlString *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0043B9F0
// Name: public: unsigned char const __near & yaSSL::input_buffer::operator[](unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall yaSSL::input_buffer::operator[](_DWORD *this, CUtlString *result)
{
  int v2; // edx
  CUtlString *v3; // eax

  v2 = *(this + 1);
  v3 = (CUtlString *)(v2 + *(this + 2));
  *(this + 1) = v2 + 1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0043BA00
// Name: public: bool yaSSL::input_buffer::eof(void)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall yaSSL::input_buffer::eof(CUtlString *this)
{
  return (CUtlString *)((unsigned __int8 *)this->m_Storage.m_Memory.m_nAllocationCount >= this->m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0043BA10
// Name: public: unsigned char yaSSL::input_buffer::peek(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall yaSSL::input_buffer::peek(CUtlString *this)
{
  return *(_BYTE *)(this->m_Storage.m_Memory.m_nGrowSize + this->m_Storage.m_Memory.m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x0043BA20
// Name: public: void yaSSL::input_buffer::read(unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::input_buffer::read(CUtlString *this, char *dst, unsigned int length)
{
  memcpy(
    (unsigned __int8 *)dst,
    src: (unsigned __int8 *)(this->m_Storage.m_Memory.m_nAllocationCount + this->m_Storage.m_Memory.m_nGrowSize),
    count: length);
  this->m_Storage.m_Memory.m_nAllocationCount += length;
}

//------------------------------------------------------------------------------
// Address: 0x0043BA50
// Name: public: yaSSL::output_buffer::output_buffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::output_buffer::output_buffer(
        CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *this)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043BA60
// Name: public: yaSSL::output_buffer::output_buffer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CSplitScreenAddedConVar *__thiscall yaSSL::output_buffer::output_buffer(
        const CSplitScreenAddedConVar *this,
        const CSplitScreenAddedConVar *a2)
{
  CSplitScreenAddedConVar *v3; // eax

  this->ConVar::ConCommandBase::__vftable = nullptr;
  v3 = operator new[](sz: this, sza: a2);
  this->m_pNext = v3;
  *(_DWORD *)&this->m_bRegistered = (char *)v3 + (_DWORD)a2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043BA90
// Name: public: unsigned int yaSSL::output_buffer::get_capacity(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::output_buffer::get_capacity(CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *this)
{
  return this->m_Memory.m_nGrowSize - this->m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x0043BAA0
// Name: public: void yaSSL::output_buffer::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall yaSSL::output_buffer::allocate(
        CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *this,
        QueuedPacket_t *const *s)
{
  CSplitScreenAddedConVar *v3; // eax
  char *result; // eax

  v3 = operator new[](sz: (const CSplitScreenAddedConVar *)this, sza: (const CSplitScreenAddedConVar *)s);
  this->m_Memory.m_nAllocationCount = (int)v3;
  result = (char *)v3 + (_DWORD)s;
  this->m_Memory.m_nGrowSize = (int)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BAD0
// Name: public: unsigned char __near & yaSSL::output_buffer::operator[](unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::output_buffer::operator[](QueuedPacket_t *const *this, QueuedPacket_t *const *i)
{
  return (int)(*this)++ + *((_DWORD *)this + 1);
}

//------------------------------------------------------------------------------
// Address: 0x0043BAE0
// Name: public: void yaSSL::output_buffer::write(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::output_buffer::write(yaSSL::output_buffer *this, unsigned __int8 *src, unsigned int count)
{
  memcpy(dst: (unsigned __int8 *)(*(_DWORD *)this + *((_DWORD *)this + 1)), src, count);
  *(_DWORD *)this += count;
}

//------------------------------------------------------------------------------
// Address: 0x0043BB10
// Name: public: void yaSSL::input_buffer::add_size(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::input_buffer::add_size(CUtlString *this@<ecx>, const char *i, int a3)
{
  this->m_Storage.m_Memory.m_pMemory += (unsigned int)i;
}

//------------------------------------------------------------------------------
// Address: 0x0043BB20
// Name: public: void yaSSL::input_buffer::assign(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0043BB60
// Name: public: yaSSL::input_buffer::input_buffer(unsigned int,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall yaSSL::input_buffer::input_buffer(
        CUtlString *this,
        const CSplitScreenAddedConVar *s,
        const unsigned __int8 *t,
        unsigned int len)
{
  CSplitScreenAddedConVar *v5; // eax

  this->m_Storage.m_Memory.m_pMemory = nullptr;
  this->m_Storage.m_Memory.m_nAllocationCount = 0;
  v5 = operator new[](sz: (const CSplitScreenAddedConVar *)this, sza: s);
  this->m_Storage.m_Memory.m_nGrowSize = (int)v5;
  this->m_Storage.m_nActualLength = (int)v5 + (_DWORD)s;
  yaSSL::input_buffer::assign((yaSSL::input_buffer *)this, src: t, a3: len);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046A6AA
// Name: __write
// Source: json
//------------------------------------------------------------------------------
int __cdecl _write(int fh, const void *buf, unsigned int cnt)
{
  ioinfo **v4; // edi
  int v5; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _write_nolock(a1: (CUtlCharConversion_vtbl *)fh, fh, buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x0046A77E
// Name: __commit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl _commit(int filedes)
{
  ioinfo **v2; // edi
  int v3; // esi
  void *osfhandle; // eax
  DWORD retval; // [esp+14h] [ebp-1Ch]

  if ( filedes == -2 )
  {
    *_errno() = 9;
    return -1;
  }
  if ( filedes < 0
    || filedes >= _nhandle
    || (v2 = &__pioinfo[filedes >> 5], (*(&(*v2)->osfile + (v3 = (filedes & 0x1F) << 6)) & 1) == 0) )
  {
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh: filedes);
  if ( (*(&(*v2)->osfile + v3) & 1) != 0 )
  {
    osfhandle = (void *)_get_osfhandle(fh: filedes);
    if ( FlushFileBuffers(hFile: osfhandle) )
      retval = 0;
    else
      retval = GetLastError();
    if ( retval == 0 )
      goto good;
    *__doserrno() = retval;
  }
  *_errno() = 9;
  retval = -1;
good:
  _unlock_fhandle(fh: filedes);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0046A857
// Name: ___loctotime64_t
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __loctotime64_t(int yr, int mo, int dy, unsigned int hr, unsigned int mn, unsigned int sc, int dstflag)
{
  int v7; // ebx
  int v8; // esi
  int *v9; // eax
  int v10; // ecx
  unsigned int v11; // edi
  int timezone; // [esp+Ch] [ebp-40h] BYREF
  int dstbias; // [esp+10h] [ebp-3Ch] BYREF
  int v15; // [esp+14h] [ebp-38h]
  int daylight; // [esp+18h] [ebp-34h] BYREF
  int v17; // [esp+1Ch] [ebp-30h]
  int tmpdays; // [esp+20h] [ebp-2Ch]
  tm tb; // [esp+24h] [ebp-28h] BYREF

  v7 = mo;
  v8 = yr - 1900;
  v15 = mo;
  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( yr - 1900 < 70
    || v8 > 1100
    || (unsigned int)(mo - 1) > 0xB
    || hr > 0x17
    || mn > 0x3B
    || sc > 0x3B
    || dy < 1
    || (v9 = &_days[mo], v10 = *(v9 - 1), *v9 - v10 < dy)
    && ((v8 % 4 != 0 || v8 % 100 == 0) && yr % 400 != 0 || (v7 = v15, v15 != 2) || dy > 29) )
  {
    *_errno() = 22;
    return -1;
  }
  else
  {
    tmpdays = dy + v10;
    if ( (v8 % 4 == 0 && v8 % 100 != 0 || yr % 400 == 0) && v7 > 2 )
      ++tmpdays;
    __tzset();
    if ( _get_daylight(_Daylight: &daylight) != 0
      || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0
      || _get_timezone(_Timezone: &timezone) != 0 )
    {
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    }
    v17 = (unsigned __int64)(365 * (v8 - 70LL) + (yr - 1900 + 299) / 400 - (yr - 1901) / 100 + (yr - 1901) / 4 - 17) >> 32;
    tb.tm_yday = tmpdays;
    v11 = sc
        + timezone
        + 60
        * (mn
         + 60
         * (hr + 24 * (tmpdays + 365 * (yr - 1970) + (yr - 1900 + 299) / 400 - (yr - 1901) / 100 + (yr - 1901) / 4 - 17)));
    tb.tm_year = yr - 1900;
    tb.tm_mon = v15 - 1;
    tb.tm_hour = hr;
    tb.tm_min = mn;
    tb.tm_sec = sc;
    if ( dstflag == 1 || dstflag == -1 && daylight != 0 && _isindst(&tb) != 0 )
      v11 += dstbias;
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046AB08
// Name: __SEH_epilog4_GS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _SEH_epilog4_GS()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0046AB17
// Name: __fullpath
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _fullpath(char *UserBuf, const char *path, DWORD maxlen)
{
  DWORD FullPathNameA; // eax
  DWORD LastError; // eax
  unsigned int v6; // edi
  unsigned __int8 *v7; // eax
  char *v8; // ebx
  DWORD v9; // eax
  char *pfname; // [esp+Ch] [ebp-4h] BYREF

  if ( path == nullptr || *path == 0 )
    return _getcwd(pnbuf: UserBuf, maxlen);
  if ( UserBuf != nullptr )
  {
    v6 = maxlen;
    if ( maxlen == 0 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    v8 = UserBuf;
  }
  else
  {
    FullPathNameA = GetFullPathNameA(lpFileName: path, nBufferLength: 0, lpBuffer: nullptr, lpFilePart: nullptr);
    if ( FullPathNameA == 0 )
    {
LABEL_5:
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      return nullptr;
    }
    v6 = maxlen;
    if ( maxlen <= FullPathNameA )
      v6 = FullPathNameA;
    v7 = calloc(count: v6, size: 1u);
    v8 = (char *)v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      return nullptr;
    }
  }
  v9 = GetFullPathNameA(lpFileName: path, nBufferLength: v6, lpBuffer: v8, lpFilePart: &pfname);
  if ( v9 >= v6 )
  {
    if ( UserBuf == nullptr )
      free(pMem: v8);
    *_errno() = 34;
    return nullptr;
  }
  if ( v9 == 0 )
  {
    if ( UserBuf == nullptr )
      free(pMem: v8);
    goto LABEL_5;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0046AC0E
// Name: ___dtoxmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __dtoxmode(char attr, const char *name)
{
  const char *v2; // ecx
  char v3; // dl
  int v4; // edi
  unsigned int v5; // edi
  const unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // esi

  v2 = name;
  if ( name[1] == 58 )
    v2 = name + 2;
  v3 = *v2;
  if ( (*v2 == 92 || v3 == 47) && v2[1] == 0 || (attr & 0x10) != 0 || (v4 = 0x8000, v3 == 0) )
    v4 = 16448;
  v5 = ~(attr << 7) & 0x80 | 0x100 | v4;
  v6 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x2Eu);
  v7 = v6;
  if ( v6 != nullptr
    && (_mbsicmp(s1: v6, s2: ".exe") == 0
     || _mbsicmp(s1: v7, s2: ".cmd") == 0
     || _mbsicmp(s1: v7, s2: ".bat") == 0
     || _mbsicmp(s1: v7, s2: ".com") == 0) )
  {
    v5 |= 0x40u;
  }
  return (v5 >> 3) & 0x38 | v5 | (((v5 >> 3) & 0x38 | v5) >> 6) & 7;
}

//------------------------------------------------------------------------------
// Address: 0x0046ACCB
// Name: __getdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _getdrive()
{
  wchar_t *v0; // ebx
  signed int CurrentDirectoryW; // esi
  unsigned __int8 *v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // eax
  int memfree; // [esp+10h] [ebp-214h]
  wchar_t curdirstr[262]; // [esp+14h] [ebp-210h] BYREF

  memfree = 0;
  v0 = curdirstr;
  CurrentDirectoryW = GetCurrentDirectoryW(nBufferLength: 0x105u, lpBuffer: curdirstr);
  if ( CurrentDirectoryW > 260 )
  {
    v2 = calloc(count: CurrentDirectoryW + 1, size: 2u);
    v0 = (wchar_t *)v2;
    if ( v2 != nullptr )
    {
      memfree = 1;
      CurrentDirectoryW = GetCurrentDirectoryW(nBufferLength: CurrentDirectoryW + 1, lpBuffer: (LPWSTR)v2);
    }
    else
    {
      *_errno() = 12;
      CurrentDirectoryW = 0;
    }
  }
  v3 = 0;
  if ( CurrentDirectoryW != 0 )
  {
    if ( v0[1] == 58 )
    {
      v4 = *v0;
      if ( v4 >= 0x61 && v4 <= 0x7A )
        v4 -= 32;
      v3 = v4 - 64;
    }
  }
  else
  {
    *_errno() = 12;
  }
  if ( memfree != 0 )
    free(pMem: v0);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0046AD99
// Name: __mbctolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  unsigned __int8 ret[4]; // [esp+14h] [ebp-8h] BYREF
  char val[4]; // [esp+18h] [ebp-4h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c <= 0xFF )
  {
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[c + 1] & 0x10) != 0 )
      result = _loc_update.localeinfo.mbcinfo->mbcasemap[c];
    else
      result = c;
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  val[0] = BYTE1(c);
  val[1] = c;
  if ( (_loc_update.localeinfo.mbcinfo->mbctype[BYTE1(c) + 1] & 4) != 0
    && __crtLCMapStringA(
         plocinfo: &_loc_update.localeinfo,
         Locale: _loc_update.localeinfo.mbcinfo->mblcid,
         dwMapFlags: 0x100u,
         lpSrcStr: val,
         cchSrc: 2,
         lpDestStr: (char *)ret,
         cchDest: 2,
         code_page: _loc_update.localeinfo.mbcinfo->mbcodepage,
         bError: 1) != 0 )
  {
    result = ret[1] + (ret[0] << 8);
    goto LABEL_11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x0046AE3F
// Name: __mbctolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctolower(unsigned int c)
{
  return _mbctolower_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0046AE52
// Name: __mbspbrk_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbspbrk_l(unsigned __int8 *string, unsigned __int8 *charset, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // ecx
  unsigned __int8 *i; // eax
  unsigned __int8 v5; // dl
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    strpbrk(string, control: charset);
LABEL_22:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v3 = string;
  if ( string != nullptr && charset != nullptr )
  {
    if ( *string != 0 )
    {
      do
      {
        for ( i = charset; *i != 0; ++i )
        {
          v5 = *i;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[*i + 1] & 4) != 0 )
          {
            if ( v5 == *v3 && i[1] == v3[1] || i[1] == 0 )
              break;
            ++i;
          }
          else if ( v5 == *v3 )
          {
            break;
          }
        }
        if ( *i != 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[*v3 + 1] & 4) != 0 && *++v3 == 0 )
          break;
        ++v3;
      }
      while ( *v3 != 0 );
    }
    goto LABEL_22;
  }
  *_errno() = 22;
  _invalid_parameter_noinfo();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x0046AF17
// Name: __mbspbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbspbrk(unsigned __int8 *string, unsigned __int8 *charset)
{
  _mbspbrk_l(string, charset, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0046AF30
// Name: __CIpow_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIpow_pentium4()
{
  JUMPOUT(0x46AF49);
}

//------------------------------------------------------------------------------
// Address: 0x0046BAA1
// Name: __fFEXP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fFEXP@<eax>(__int16 a1@<cx>, int a2@<ebp>)
{
  *(_BYTE *)(a2 - 144) = -2;
  HIBYTE(a1) = 0;
  _ffexpm1(a1);
  return _rttospop();
}

//------------------------------------------------------------------------------
// Address: 0x0046BAF8
// Name: __rtinfpopse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtinfpopse@<eax>(double a1@<st0>)
{
  return _rtinfnpopse(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0046BAFA
// Name: __rtinfnpopse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _rtinfnpopse@<st0>(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 144) = 2;
  return INFINITY;
}

//------------------------------------------------------------------------------
// Address: 0x0046BB0A
// Name: __fFLN
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _fFLN@<st0>(int a1@<ebp>, long double a2@<st0>)
{
  __int16 v2; // fps
  long double result; // st7
  bool v5; // c0
  char v6; // c2
  bool v7; // c3

  result = 0.6931471805599453094;
  v5 = a2 < 0.0;
  v6 = 0;
  v7 = a2 == 0.0;
  *(_WORD *)(a1 - 160) = v2;
  if ( (*(_BYTE *)(a1 - 159) & 0x41) == 0 )
    return __FYL2X__(a2, 0.6931471805599453094);
  _rtindfpop();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046BB67
// Name: zerotoxdone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void zerotoxdone()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0046BBBF
// Name: __rtinfpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtinfpop@<eax>(double a1@<st0>)
{
  return _rtinfnpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0046BBC1
// Name: __rtinfnpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _rtinfnpop@<st0>(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 144) = 3;
  return INFINITY;
}

//------------------------------------------------------------------------------
// Address: 0x0046BBD1
// Name: _rtforexpinf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __fastcall rtforexpinf(char a1)
{
  double result; // st7

  if ( a1 == 0 )
    return INFINITY;
  _rtzeronpop();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046BBDE
// Name: __ffexpm1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _ffexpm1@<eax>(char a1@<ch>, int _EBP@<ebp>)
{
  int result; // eax
  int v3; // [esp-4h] [ebp-4h]

  __asm
  {
    fld     st
    fabs
    fld     ds:_log2max
    fcompp
    fstsw   word ptr [ebp-0A0h]
  }
  if ( (*(_BYTE *)(_EBP - 159) & 0x41) != 0 )
  {
    result = v3;
    __asm
    {
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    if ( (*(_BYTE *)(_EBP - 159) & 1) != 0 )
    {
      *(_BYTE *)(_EBP - 144) = 4;
      return _rtzeronpop();
    }
    else
    {
      __asm
      {
        fstp    st
        fld     ds:__infinity
      }
      if ( a1 != 0 )
        __asm { fchs }
    }
  }
  else
  {
    __asm
    {
      fld     st
      frndint
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    __asm
    {
      fxch    st(1)
      fsub    st, st(1)
      ftst
      fstsw   word ptr [ebp-0A0h]
      fabs
      f2xm1
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046BC21
// Name: _isintTOS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall isintTOS@<eax>(long double a1@<st0>)
{
  if ( rint(a1) != a1 )
    return notanint();
  if ( rint(a1 * 0.5) == a1 * 0.5 )
    return evenint();
  return isintTOSret();
}

//------------------------------------------------------------------------------
// Address: 0x0046BC46
// Name: _isintTOSret
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void isintTOSret()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0046BC47
// Name: notanint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void notanint()
{
  isintTOSret();
}

//------------------------------------------------------------------------------
// Address: 0x0046BC4E
// Name: evenint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void evenint()
{
  isintTOSret();
}

//------------------------------------------------------------------------------
// Address: 0x0046BC55
// Name: _usepowhlp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall usepowhlp@<st0>(long double y@<st1>, long double x@<st0>)
{
  int v3; // eax
  long double result; // st7
  long double *v5; // [esp+10h] [ebp-7Ch]
  long double v6[15]; // [esp+14h] [ebp-78h] BYREF

  _ESI = v6;
  v5 = v6;
  __asm { fsave   byte ptr [esi+8] }
  v3 = _powhlp(x, y, result: v6);
  __asm { frstor  byte ptr [esi+8] }
  result = v6[0];
  if ( v3 != 0 )
    _rttosnpopde();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046BC90
// Name: __trandisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _trandisp1@<eax>(int a1@<edx>, __int16 a2@<cx>, int a3@<ebp>, __int16 a4@<fpstat>, double _ST7@<st0>)
{
  __int16 v5; // bx

  if ( *(_BYTE *)(a1 + 14) == 5 )
  {
    HIBYTE(v5) = HIBYTE(*(_WORD *)(a3 - 164)) & 0xFC | 2;
    LOBYTE(v5) = 63;
  }
  else
  {
    v5 = 4927;
  }
  *(_WORD *)(a3 - 162) = v5;
  _EBX = &XAMtoTagTab;
  __asm { fxam }
  *(_DWORD *)(a3 - 148) = a1;
  *(_WORD *)(a3 - 160) = a4;
  *(_BYTE *)(a3 - 144) = 0;
  LOBYTE(a2) = __ROL1__((char)(2 * *(_BYTE *)(a3 - 159)) >> 1, 1);
  _AL = a2 & 0xF;
  __asm { xlat }
  return (*(int (__thiscall **)(int))(_AL + a1 + 16))(a1: a2 & 0x404);
}

//------------------------------------------------------------------------------
// Address: 0x0046BCF7
// Name: __trandisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _trandisp2@<eax>(int a1@<edx>, int a2@<ebp>, __int16 a3@<fpstat>, double _ST6@<st1>, double a5@<st0>)
{
  __int16 v5; // bx
  __int16 v7; // fps
  char v9; // cl
  __int16 v10; // cx
  char v13; // ah

  if ( *(_BYTE *)(a1 + 14) == 5 )
  {
    HIBYTE(v5) = HIBYTE(*(_WORD *)(a2 - 164)) & 0xFC | 2;
    LOBYTE(v5) = 63;
  }
  else
  {
    v5 = 4927;
  }
  *(_WORD *)(a2 - 162) = v5;
  _EBX = &XAMtoTagTab;
  __asm { fxam }
  *(_DWORD *)(a2 - 148) = a1;
  *(_WORD *)(a2 - 160) = a3;
  *(_BYTE *)(a2 - 144) = 0;
  _ST6 = a5;
  v9 = *(_BYTE *)(a2 - 159);
  __asm { fxam }
  *(_WORD *)(a2 - 160) = v7;
  HIBYTE(v10) = __ROL1__((char)(2 * *(_BYTE *)(a2 - 159)) >> 1, 1);
  _AL = HIBYTE(v10) & 0xF;
  __asm { xlat }
  v13 = _AL;
  LOBYTE(v10) = __ROL1__((char)(2 * v9) >> 1, 1);
  _AL = v10 & 0xF;
  __asm { xlat }
  return (*(int (__thiscall **)(int))((char)((4 * v13) | _AL) + a1 + 16))(a1: v10 & 0x404);
}

//------------------------------------------------------------------------------
// Address: 0x0046BD83
// Name: __rttospopde
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int _rttospopde()
{
  _rttosnpopde();
  return _rttospop();
}

//------------------------------------------------------------------------------
// Address: 0x0046BD88
// Name: __rttospop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _rttospop()
{
  return _rtnospop();
}

//------------------------------------------------------------------------------
// Address: 0x0046BD8A
// Name: __rtnospop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _rtnospop()
{
  JUMPOUT(0x46BD8C);
}

//------------------------------------------------------------------------------
// Address: 0x0046BD8D
// Name: __rtnospopde
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _rtnospopde()
{
  _rttosnpopde();
  _rtnospop();
}

//------------------------------------------------------------------------------
// Address: 0x0046BD94
// Name: __rtzeropop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtzeropop@<eax>(double a1@<st0>)
{
  return _rtzeronpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0046BD96
// Name: __rtzeronpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double _rtzeronpop()
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x0046BD9B
// Name: __rtonepop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtonepop@<eax>(double a1@<st0>)
{
  return _rtonenpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0046BD9D
// Name: __rtonenpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double _rtonenpop()
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0046BDA2
// Name: __tosnan1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _tosnan1@<st0>(int a1@<ebp>, double a2@<st0>)
{
  double result; // st7

  *(double *)(a1 - 158) = a2;
  result = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0 )
  {
    *(_BYTE *)(a1 - 144) = 7;
  }
  else
  {
    *(_BYTE *)(a1 - 144) = 1;
    return result + 1.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046BDCD
// Name: __nosnan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _nosnan2()
{
  return _tosnan2();
}

//------------------------------------------------------------------------------
// Address: 0x0046BDCF
// Name: __tosnan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _tosnan2@<st0>(int a1@<ebp>, double a2@<st1>, double a3@<st0>)
{
  double v3; // st6

  *(double *)(a1 - 158) = a2;
  v3 = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0 )
    *(_BYTE *)(a1 - 144) = 7;
  else
    *(_BYTE *)(a1 - 144) = 1;
  return a3 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x0046BDF7
// Name: __nan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _nan2@<st0>(int a1@<ebp>, double a2@<st1>, double a3@<st0>)
{
  double v3; // st6
  double v4; // rt0
  double v5; // st6

  *(double *)(a1 - 158) = a2;
  v3 = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0
    && (v4 = v3,
        v5 = a3,
        a3 = v4,
        *(double *)(a1 - 158) = v5,
        v3 = *(double *)(a1 - 158),
        (*(_BYTE *)(a1 - 151) & 0x40) != 0) )
  {
    *(_BYTE *)(a1 - 144) = 7;
  }
  else
  {
    *(_BYTE *)(a1 - 144) = 1;
  }
  return a3 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x0046BE36
// Name: __rtindfpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtindfpop@<eax>(double a1@<st0>)
{
  return _rtindfnpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0046BE38
// Name: __rtindfnpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtindfnpop@<eax>(int a1@<ebp>)
{
  if ( *(char *)(a1 - 144) > 0 )
    JUMPOUT(0x46BE50);
  return _rttosnpopde();
}

//------------------------------------------------------------------------------
// Address: 0x0046BE49
// Name: __rttosnpopde
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _rttosnpopde(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 144) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046BE53
// Name: __rtchsifneg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _rtchsifneg@<st0>(char a1@<cl>, double result@<st0>)
{
  if ( a1 != 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046BE60
// Name: __startTwoArgErrorHandling
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _startTwoArgErrorHandling()
{
  JUMPOUT(0x46BE80);
}

//------------------------------------------------------------------------------
// Address: 0x0046BE77
// Name: __startOneArgErrorHandling
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _startOneArgErrorHandling(
        unsigned int a1@<eax>,
        int a2@<edx>,
        unsigned int a3@<ecx>,
        __int16 savCW,
        unsigned int ret_addr,
        unsigned __int64 param1)
{
  _exception exc; // [esp+0h] [ebp-20h] BYREF

  exc.typ = a1;
  __asm { fstp    [ebp+exc.retval] }
  exc.nam = a3;
  exc.arg1 = param1;
  _87except(opcode: a2, &exc, pcw16: (unsigned __int16 *)&savCW);
  __asm { fld     [ebp+exc.retval] }
  if ( savCW != 639 )
    __asm { fldcw   word ptr [ebp+savCW] }
}

//------------------------------------------------------------------------------
// Address: 0x0046BEC0
// Name: __twoToTOS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _twoToTOS@<st0>(long double a1@<st0>)
{
  long double v1; // rt0

  v1 = rint(a1);
  return __FSCALE__(__F2XM1__(-(v1 - a1)) + 1.0, v1);
}

//------------------------------------------------------------------------------
// Address: 0x0046BED5
// Name: __load_CW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _load_CW()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0046BEEC
// Name: __convertTOStoQNaN
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _convertTOStoQNaN@<st0>(int a1@<eax>, double result@<st0>)
{
  if ( (a1 & 0x80000) == 0 )
    return result + 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046BF05
// Name: __fload_withFB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __fastcall _fload_withFB(int a1, _DWORD *a2)
{
  double result; // st7

  if ( (a2[1] & 0x7FF00000) != 0x7FF00000 )
    return *(double *)a2;
  *(_QWORD *)&result = *(_QWORD *)a2 << 11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046BF48
// Name: __checkTOS_withFB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _checkTOS_withFB(int a1, int a2)
{
  int result; // eax

  result = a2 & 0x7FF00000;
  if ( (a2 & 0x7FF00000) == 0x7FF00000 )
    return a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046BF5E
// Name: __fast_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _fast_exit()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0046BF6B
// Name: __math_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0046BF95
// Name: __check_overflow_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _check_overflow_exit()
{
  JUMPOUT(0x46BFBD);
}

//------------------------------------------------------------------------------
// Address: 0x0046BFA9
// Name: __check_range_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0046C04C
// Name: __d_inttype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _d_inttype(long double y)
{
  if ( (_fpclass(x: y) & 0x90) != 0 || y != _frnd(x: y) )
    return 0;
  if ( y * 0.5 == _frnd(x: y * 0.5) )
    return 2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046C0B6
// Name: __powhlp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _powhlp(long double x, long double y, long double *result)
{
  long double v3; // st7
  int v4; // esi
  long double dbl; // st7
  bool v6; // c3
  double *v7; // eax
  int v8; // eax

  v3 = fabs(x);
  v4 = 0;
  if ( HIDWORD(y) == 2146435072 )
  {
    if ( LODWORD(y) == 0 )
    {
      if ( v3 <= 1.0 )
      {
        v6 = 1.0 == v3;
        dbl = 1.0;
        v7 = result;
        if ( !v6 )
          dbl = 0.0;
        goto LABEL_27;
      }
      goto LABEL_4;
    }
  }
  else if ( y == -INFINITY )
  {
    if ( v3 <= 1.0 )
    {
      v7 = result;
      if ( v3 >= 1.0 )
      {
        dbl = _d_ind.dbl;
        v4 = 1;
      }
      else
      {
        dbl = _d_inf.dbl;
      }
      goto LABEL_27;
    }
    dbl = 0.0;
LABEL_26:
    v7 = result;
LABEL_27:
    *v7 = dbl;
    return v4;
  }
  if ( HIDWORD(x) == 2146435072 )
  {
    if ( LODWORD(x) == 0 )
    {
      dbl = 0.0;
      if ( y <= 0.0 )
      {
        v7 = result;
        if ( y >= 0.0 )
          dbl = 1.0;
        goto LABEL_27;
      }
LABEL_4:
      dbl = _d_inf.dbl;
      goto LABEL_26;
    }
  }
  else if ( x == -INFINITY )
  {
    v8 = _d_inttype(y);
    dbl = 0.0;
    if ( y <= 0.0 )
    {
      if ( y >= 0.0 )
      {
        dbl = 1.0;
      }
      else if ( v8 == 1 )
      {
        dbl = _d_mzero.dbl;
      }
    }
    else
    {
      dbl = _d_inf.dbl;
      if ( v8 == 1 )
        dbl = -_d_inf.dbl;
    }
    goto LABEL_26;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0046C1F0
// Name: __CIlog_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _CIlog_pentium4(double a1@<st0>)
{
  double v2; // [esp+10h] [ebp-8h]

  v2 = a1;
  __asm { movq    xmm0, [esp+8+var_8] }
  JUMPOUT(0x46C20E);
}

//------------------------------------------------------------------------------
// Address: 0x0046C460
// Name: _fwprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int fwprintf(_iobuf *str, const wchar_t *format, ...)
{
  int v3; // ebx
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+3Ch] [ebp+10h] BYREF

  va_start(argptr, format);
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    v3 = _stbuf(str);
    retval = _woutput_l(stream: str, format, plocinfo: nullptr, argptr);
    _ftbuf(flag: v3, str);
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046C4EC
// Name: _setvbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl setvbuf(_iobuf *str, char *buffer, int type, unsigned int size)
{
  unsigned int v5; // edi
  int v6; // edi
  int flag; // ecx
  int v8; // ecx
  char *p_charbuf; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str == nullptr )
    goto LABEL_2;
  if ( type != 4 )
  {
    if ( type == 0 )
      goto LABEL_7;
    if ( type != 64 )
    {
LABEL_2:
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( type != 64 )
  {
    v5 = size;
    goto LABEL_10;
  }
LABEL_7:
  v5 = size;
  if ( size - 2 > 0x7FFFFFFD )
    goto LABEL_2;
LABEL_10:
  v6 = v5 & 0xFFFFFFFE;
  _lock_file(pf: str);
  _flush(str);
  _freebuf(stream: str);
  str->_flag &= 0xFFFFC2F3;
  flag = str->_flag;
  if ( (type & 4) != 0 )
  {
    v8 = flag | 4;
    p_charbuf = (char *)&str->_charbuf;
    v6 = 2;
LABEL_17:
    str->_flag = v8;
    goto LABEL_18;
  }
  p_charbuf = buffer;
  if ( buffer != nullptr )
  {
    v8 = flag | 0x500;
    goto LABEL_17;
  }
  p_charbuf = (char *)operator new(nSize: v6);
  if ( p_charbuf != nullptr )
  {
    str->_flag |= 0x408u;
LABEL_18:
    str->_bufsiz = v6;
    str->_base = p_charbuf;
    str->_ptr = p_charbuf;
    str->_cnt = 0;
    goto done_1;
  }
  ++_cflush;
  retval = -1;
done_1:
  _unlock_file(pf: str);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0046C5E2
// Name: ___crtMessageBoxW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtMessageBoxW(const wchar_t *lpText, const wchar_t *lpCaption, unsigned int uType)
{
  HMODULE LibraryW; // eax
  HMODULE v4; // ebx
  int (__stdcall *MessageBoxW)(HWND, LPCWSTR, LPCWSTR, UINT); // eax
  HWND (__stdcall *GetActiveWindow)(); // eax
  HWND (__stdcall *GetLastActivePopup)(HWND); // eax
  BOOL (__stdcall *GetUserObjectInformationW)(HANDLE, int, PVOID, DWORD, LPDWORD); // eax
  HWINSTA (__stdcall *GetProcessWindowStation)(); // eax
  int (*v10)(void); // edi
  int (__stdcall *v11)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // eax
  int (__stdcall *v12)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // ebx
  int v13; // eax
  int (*v14)(void); // eax
  int (__stdcall *v15)(HWND__ *); // eax
  int (__stdcall *v16)(HWND__ *, const wchar_t *, const wchar_t *, unsigned int); // eax
  unsigned int nDummy; // [esp+Ch] [ebp-24h] BYREF
  const wchar_t *v19; // [esp+10h] [ebp-20h]
  const wchar_t *v20; // [esp+14h] [ebp-1Ch]
  void *enull; // [esp+18h] [ebp-18h]
  HWND__ *hWndParent; // [esp+1Ch] [ebp-14h]
  tagUSEROBJECTFLAGS uof; // [esp+20h] [ebp-10h] BYREF

  v19 = lpText;
  v20 = lpCaption;
  hWndParent = nullptr;
  enull = _encoded_null();
  if ( pfnMessageBox == nullptr )
  {
    LibraryW = LoadLibraryW(lpLibFileName: L"USER32.DLL");
    v4 = LibraryW;
    if ( LibraryW == nullptr )
      return 0;
    MessageBoxW = (int (__stdcall *)(HWND, LPCWSTR, LPCWSTR, UINT))GetProcAddress(
                                                                     hModule: LibraryW,
                                                                     lpProcName: "MessageBoxW");
    if ( MessageBoxW == nullptr )
      return 0;
    pfnMessageBox = EncodePointer(Ptr: MessageBoxW);
    GetActiveWindow = (HWND (__stdcall *)())GetProcAddress(hModule: v4, lpProcName: "GetActiveWindow");
    pfnGetActiveWindow = EncodePointer(Ptr: GetActiveWindow);
    GetLastActivePopup = (HWND (__stdcall *)(HWND))GetProcAddress(hModule: v4, lpProcName: "GetLastActivePopup");
    pfnGetLastActivePopup = EncodePointer(Ptr: GetLastActivePopup);
    GetUserObjectInformationW = (BOOL (__stdcall *)(HANDLE, int, PVOID, DWORD, LPDWORD))GetProcAddress(
                                                                                          hModule: v4,
                                                                                          lpProcName: "GetUserObjectInformationW");
    pfnGetUserObjectInformation = EncodePointer(Ptr: GetUserObjectInformationW);
    if ( pfnGetUserObjectInformation != nullptr )
    {
      GetProcessWindowStation = (HWINSTA (__stdcall *)())GetProcAddress(
                                                           hModule: v4,
                                                           lpProcName: "GetProcessWindowStation");
      pfnGetProcessWindowStation = EncodePointer(Ptr: GetProcessWindowStation);
    }
  }
  if ( pfnGetProcessWindowStation == enull
    || pfnGetUserObjectInformation == enull
    || (v10 = (int (*)(void))DecodePointer(Ptr: pfnGetProcessWindowStation),
        v11 = (int (__stdcall *)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *))DecodePointer(Ptr: pfnGetUserObjectInformation),
        v12 = v11,
        v10 == nullptr)
    || v11 == nullptr
    || (v13 = v10()) != 0 && v12(a1: v13, a2: 1, a3: &uof, a4: 12, a5: &nDummy) != 0 && (uof.dwFlags & 1) != 0 )
  {
    if ( pfnGetActiveWindow != enull )
    {
      v14 = (int (*)(void))DecodePointer(Ptr: pfnGetActiveWindow);
      if ( v14 != nullptr )
      {
        hWndParent = (HWND__ *)v14();
        if ( hWndParent != nullptr && pfnGetLastActivePopup != enull )
        {
          v15 = (int (__stdcall *)(HWND__ *))DecodePointer(Ptr: pfnGetLastActivePopup);
          if ( v15 != nullptr )
            hWndParent = (HWND__ *)v15(a1: hWndParent);
        }
      }
    }
  }
  else
  {
    uType |= 0x200000u;
  }
  v16 = (int (__stdcall *)(HWND__ *, const wchar_t *, const wchar_t *, unsigned int))DecodePointer(Ptr: pfnMessageBox);
  if ( v16 != nullptr )
    return v16(a1: hWndParent, a2: v19, a3: v20, a4: uType);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046C74E
// Name: xtow_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge xtow_s@<eax>(
        unsigned int val@<eax>,
        unsigned __int16 *buf@<ecx>,
        unsigned int sizeInTChars,
        unsigned int radix,
        int is_neg)
{
  unsigned __int16 *v5; // esi
  unsigned int v6; // ebx
  int *v8; // eax
  int v9; // esi
  unsigned __int16 *v10; // edi
  __int16 v11; // dx
  unsigned int v12; // et2
  unsigned __int16 v13; // dx
  unsigned __int16 *v14; // ecx
  unsigned __int16 v15; // ax
  int v16; // [esp-8h] [ebp-10h]

  v5 = buf;
  v6 = 0;
  if ( buf == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  if ( sizeInTChars != 0 )
  {
    *buf = 0;
    if ( sizeInTChars <= (unsigned int)(is_neg != 0) + 1 )
    {
      v8 = _errno();
      v16 = 34;
      goto LABEL_5;
    }
    if ( radix - 2 <= 0x22 )
    {
      if ( is_neg != 0 )
      {
        *buf = 45;
        v6 = 1;
        ++buf;
        val = -val;
      }
      v10 = buf;
      do
      {
        v12 = val % radix;
        val /= radix;
        v11 = v12;
        if ( v12 <= 9 )
          v13 = v11 + 48;
        else
          v13 = v11 + 87;
        *buf++ = v13;
        ++v6;
      }
      while ( val != 0 && v6 < sizeInTChars );
      if ( v6 >= sizeInTChars )
      {
        *v5 = 0;
        *_errno() = 34;
        v9 = 34;
        goto LABEL_6;
      }
      *buf = 0;
      v14 = buf - 1;
      do
      {
        v15 = *v14;
        *v14 = *v10;
        *v10 = v15;
        --v14;
        ++v10;
      }
      while ( v10 < v14 );
      return 0;
    }
  }
  v8 = _errno();
  v16 = 22;
LABEL_5:
  v9 = v16;
  *v8 = v16;
LABEL_6:
  _invalid_parameter_noinfo();
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x0046C82D
// Name: __itow_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _itow_s(int val, unsigned __int16 *buf, unsigned int sizeInTChars, unsigned int radix)
{
  if ( radix == 10 && val < 0 )
    return xtow_s(val, buf, sizeInTChars, radix: 0xAu, is_neg: 1);
  else
    return xtow_s(val, buf, sizeInTChars, radix, is_neg: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0046C857
// Name: _wcsncat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcsncat_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src, unsigned int _Count)
{
  unsigned int v4; // ebx
  unsigned int v6; // edi
  int v7; // esi
  const wchar_t *v8; // edx
  unsigned __int16 *v9; // eax
  int v10; // eax
  wchar_t v11; // cx
  char *v12; // edx
  unsigned __int16 v13; // cx

  v4 = _Count;
  if ( _Count != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      v7 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter_noinfo();
      return v7;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInWords == 0 )
      return 0;
    goto LABEL_7;
  }
  v6 = _SizeInWords;
  if ( _SizeInWords == 0 )
    goto LABEL_7;
  v8 = _Src;
  if ( _Count == 0 || _Src != nullptr )
  {
    v9 = _Dst;
    do
    {
      if ( *v9 == 0 )
        break;
      ++v9;
      --v6;
    }
    while ( v6 != 0 );
    if ( v6 != 0 )
    {
      if ( _Count == -1 )
      {
        v10 = (char *)v9 - (char *)_Src;
        do
        {
          v11 = *v8;
          *(const wchar_t *)((char *)v8 + v10) = *v8;
          ++v8;
          if ( v11 == 0 )
            break;
          --v6;
        }
        while ( v6 != 0 );
      }
      else
      {
        if ( _Count == 0 )
          goto LABEL_27;
        v12 = (char *)((char *)_Src - (char *)v9);
        do
        {
          v13 = *(unsigned __int16 *)((char *)v9 + (_DWORD)v12);
          *v9++ = v13;
          if ( v13 == 0 )
            break;
          if ( --v6 == 0 )
            break;
          --v4;
        }
        while ( v4 != 0 );
        if ( v4 == 0 )
LABEL_27:
          *v9 = 0;
      }
      if ( v6 != 0 )
        return 0;
      if ( v4 != -1 )
      {
        *_Dst = 0;
        *_errno() = 34;
        v7 = 34;
        goto LABEL_8;
      }
      _Dst[_SizeInWords - 1] = 0;
      return 80;
    }
  }
  *_Dst = 0;
  goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x0046C92D
// Name: _wcsncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcsncpy_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src, unsigned int _Count)
{
  unsigned int v4; // ebx
  unsigned int v6; // edi
  int v7; // esi
  const wchar_t *v8; // ecx
  unsigned __int16 *v9; // eax
  wchar_t v10; // ax
  unsigned __int16 v11; // cx

  v4 = _Count;
  if ( _Count != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      v7 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter_noinfo();
      return v7;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInWords == 0 )
      return 0;
    goto LABEL_7;
  }
  v6 = _SizeInWords;
  if ( _SizeInWords == 0 )
    goto LABEL_7;
  if ( _Count == 0 )
  {
    *_Dst = 0;
    return 0;
  }
  v8 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
    goto LABEL_7;
  }
  v9 = _Dst;
  if ( _Count == -1 )
  {
    do
    {
      v10 = *v8;
      *(const wchar_t *)((char *)v8 + (char *)_Dst - (char *)_Src) = *v8;
      ++v8;
      if ( v10 == 0 )
        break;
      --v6;
    }
    while ( v6 != 0 );
  }
  else
  {
    do
    {
      v11 = *(unsigned __int16 *)((char *)v9 + (char *)_Src - (char *)_Dst);
      *v9++ = v11;
      if ( v11 == 0 )
        break;
      if ( --v6 == 0 )
        break;
      --v4;
    }
    while ( v4 != 0 );
    if ( v4 == 0 )
      *v9 = 0;
  }
  if ( v6 != 0 )
    return 0;
  if ( v4 != -1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v7 = 34;
    goto LABEL_8;
  }
  _Dst[_SizeInWords - 1] = 0;
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x0046C9FA
// Name: _wcslen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcslen(const wchar_t *wcs)
{
  const wchar_t *v1; // eax
  __int16 v2; // cx

  v1 = wcs;
  do
    v2 = *v1++;
  while ( v2 != 0 );
  return v1 - wcs - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046CA15
// Name: _wcscat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcscat_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  int result; // eax
  const wchar_t *v6; // ecx
  unsigned __int16 *v7; // edx
  int v8; // edx
  wchar_t v9; // ax

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInWords;
  if ( _SizeInWords == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src != nullptr )
  {
    v7 = _Dst;
    do
    {
      if ( *v7 == 0 )
        break;
      ++v7;
      --v3;
    }
    while ( v3 != 0 );
    if ( v3 != 0 )
    {
      v8 = (char *)v7 - (char *)_Src;
      do
      {
        v9 = *v6;
        *(const wchar_t *)((char *)v6 + v8) = *v6;
        ++v6;
        if ( v9 == 0 )
          break;
        --v3;
      }
      while ( v3 != 0 );
      result = 0;
      if ( v3 == 0 )
      {
        *_Dst = 0;
        *_errno() = 34;
        v4 = 34;
        goto LABEL_4;
      }
      return result;
    }
  }
  *_Dst = 0;
LABEL_3:
  v4 = 22;
  *_errno() = 22;
LABEL_4:
  _invalid_parameter_noinfo();
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0046CA8A
// Name: _wcscpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcscpy_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  int result; // eax
  const wchar_t *v6; // eax
  wchar_t v7; // cx

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInWords;
  if ( _SizeInWords == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter_noinfo();
    return v4;
  }
  do
  {
    v7 = *v6;
    *(const wchar_t *)((char *)v6 + (char *)_Dst - (char *)_Src) = *v6;
    ++v6;
    if ( v7 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  result = 0;
  if ( v3 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046CAED
// Name: __set_error_mode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _set_error_mode(int em)
{
  int result; // eax

  if ( em >= 0 )
  {
    if ( em <= 2 )
    {
      result = __error_mode;
      __error_mode = em;
      return result;
    }
    if ( em == 3 )
      return __error_mode;
  }
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046CB2C
// Name: _wcsnlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl wcsnlen(const wchar_t *wcs, unsigned int maxsize)
{
  unsigned int result; // eax

  for ( result = 0; result < maxsize; ++wcs )
  {
    if ( *wcs == 0 )
      break;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046CB4C
// Name: __crtLCMapStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtLCMapStringA_stat(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        UINT code_page,
        int bError)
{
  const char *v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // edi
  unsigned int v15; // eax
  void *v16; // esp
  wchar_t *v17; // eax
  unsigned int v18; // eax
  void *v19; // esp
  WCHAR *v20; // edi
  WCHAR *v21; // eax
  int v22; // eax
  _DWORD v23[2]; // [esp+0h] [ebp-1Ch] BYREF
  int v24; // [esp+8h] [ebp-14h] BYREF
  int inbuff_size; // [esp+Ch] [ebp-10h]
  wchar_t *inwbuffer; // [esp+10h] [ebp-Ch]
  int retval; // [esp+14h] [ebp-8h]

  if ( cchSrc > 0 )
  {
    v9 = lpSrcStr;
    v10 = cchSrc;
    while ( 1 )
    {
      --v10;
      if ( *v9 == 0 )
        break;
      ++v9;
      if ( v10 == 0 )
      {
        v10 = -1;
        break;
      }
    }
    v11 = cchSrc - v10 - 1;
    if ( v11 < cchSrc )
      v11 = cchSrc - v10;
    cchSrc = v11;
  }
  retval = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  v12 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 8 * (bError != 0) + 1,
          lpMultiByteStr: lpSrcStr,
          cbMultiByte: cchSrc,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  v13 = v12;
  inbuff_size = v12;
  if ( v12 == 0 )
    return 0;
  if ( v12 > 0 && 0xFFFFFFE0 / v12 >= 2 )
  {
    v15 = 2 * v12 + 8;
    if ( v15 > 0x400 )
    {
      v17 = (wchar_t *)operator new(nSize: 2 * v13 + 8);
      if ( v17 != nullptr )
      {
        *(_DWORD *)v17 = 56797;
        goto LABEL_20;
      }
    }
    else
    {
      v16 = alloca(v15);
      v17 = (wchar_t *)v23;
      if ( v23 != nullptr )
      {
        v23[0] = 52428;
LABEL_20:
        v17 += 4;
      }
    }
    inwbuffer = v17;
    goto LABEL_23;
  }
  inwbuffer = nullptr;
LABEL_23:
  if ( inwbuffer == nullptr )
    return 0;
  if ( MultiByteToWideChar(
         CodePage: code_page,
         dwFlags: 1u,
         lpMultiByteStr: lpSrcStr,
         cbMultiByte: cchSrc,
         lpWideCharStr: inwbuffer,
         cchWideChar: v13) != 0 )
  {
    retval = LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v13, lpDestStr: nullptr, cchDest: 0);
    if ( retval != 0 )
    {
      if ( (dwMapFlags & 0x400) != 0 )
      {
        if ( cchDest != 0 && retval <= cchDest )
          LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v13, (LPWSTR)lpDestStr, cchDest);
        goto LABEL_46;
      }
      if ( retval <= 0 || 0xFFFFFFE0 / retval < 2 )
      {
        v20 = nullptr;
LABEL_39:
        if ( v20 != nullptr )
        {
          if ( LCMapStringW(
                 Locale,
                 dwMapFlags,
                 lpSrcStr: inwbuffer,
                 cchSrc: inbuff_size,
                 lpDestStr: v20,
                 cchDest: retval) != 0 )
          {
            if ( cchDest != 0 )
              v22 = WideCharToMultiByte(
                      CodePage: code_page,
                      dwFlags: 0,
                      lpWideCharStr: v20,
                      cchWideChar: retval,
                      lpMultiByteStr: lpDestStr,
                      cbMultiByte: cchDest,
                      lpDefaultChar: nullptr,
                      lpUsedDefaultChar: nullptr);
            else
              v22 = WideCharToMultiByte(
                      CodePage: code_page,
                      dwFlags: 0,
                      lpWideCharStr: v20,
                      cchWideChar: retval,
                      lpMultiByteStr: nullptr,
                      cbMultiByte: 0,
                      lpDefaultChar: nullptr,
                      lpUsedDefaultChar: nullptr);
            retval = v22;
          }
          _freea(_Memory: v20);
        }
        goto LABEL_46;
      }
      v18 = 2 * retval + 8;
      if ( v18 > 0x400 )
      {
        v21 = (WCHAR *)operator new(nSize: 2 * retval + 8);
        if ( v21 != nullptr )
        {
          *(_DWORD *)v21 = 56797;
          v21 += 4;
        }
        v20 = v21;
        goto LABEL_39;
      }
      v19 = alloca(v18);
      if ( v23 != nullptr )
      {
        v23[0] = 52428;
        v20 = (WCHAR *)&v24;
        goto LABEL_39;
      }
    }
  }
LABEL_46:
  _freea(_Memory: inwbuffer);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0046CD33
// Name: ___crtLCMapStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtLCMapStringA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        UINT code_page,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtLCMapStringA_stat(
             plocinfo: &_loc_update.localeinfo,
             Locale,
             dwMapFlags,
             lpSrcStr,
             cchSrc,
             lpDestStr,
             cchDest,
             code_page,
             bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046CD79
// Name: _iswctype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswctype(unsigned __int16 c, unsigned __int16 mask)
{
  unsigned __int16 v3; // ax
  int d; // [esp+0h] [ebp-4h] BYREF

  if ( c == 0xFFFF )
    return 0;
  if ( c >= 0x100u )
  {
    if ( !GetStringTypeW(dwInfoType: 1u, lpSrcStr: &c, cchSrc: 1, lpCharType: (LPWORD)&d) )
      d = 0;
    v3 = d;
  }
  else
  {
    v3 = _pwctype[c];
  }
  return mask & v3;
}

//------------------------------------------------------------------------------
// Address: 0x0046CDCE
// Name: write_char_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_char_0(_iobuf *f@<eax>, int *pnumwritten@<esi>, wchar_t ch)
{
  if ( ((f->_flag & 0x40) == 0 || f->_base != nullptr) && _fputwc_nolock(ch, str: f) == 0xFFFF )
    *pnumwritten = -1;
  else
    ++*pnumwritten;
}

//------------------------------------------------------------------------------
// Address: 0x0046CDFD
// Name: write_string_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string_0(wchar_t *string@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, int len)
{
  if ( (f->_flag & 0x40) == 0 || f->_base != nullptr )
  {
    while ( len > 0 )
    {
      --len;
      write_char_0(f, pnumwritten, ch: *string++);
      if ( *pnumwritten == -1 )
      {
        if ( *_errno() != 42 )
          return;
        write_char_0(f, pnumwritten, ch: 0x3Fu);
      }
    }
  }
  else
  {
    *pnumwritten += len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CE50
// Name: __woutput_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _woutput_l(_iobuf *stream, const wchar_t *format, localeinfo_struct *plocinfo, char *argptr)
{
  const wchar_t *v4; // esi
  int *v5; // edi
  bool v6; // zf
  int v8; // edx
  STATE v9; // ecx
  const wchar_t *v10; // esi
  int v11; // eax
  int v12; // eax
  _woutput_l::__l2::<unnamed_type_buffer> *p_buffer; // edi
  int v14; // ebx
  _woutput_l::__l2::<unnamed_type_text> v15; // edi
  unsigned __int8 *j; // esi
  int v17; // eax
  __int16 *v18; // eax
  _woutput_l::__l2::<unnamed_type_text> v19; // ecx
  int v20; // eax
  int v21; // eax
  _WORD *v22; // esi
  __int64 v23; // rax
  int *v24; // edi
  int v25; // esi
  char *v26; // eax
  int v27; // ecx
  void (__cdecl *v28)(_CRT_DOUBLE *, _woutput_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *); // eax
  int v29; // ebx
  void (__cdecl *v30)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  void (__cdecl *v31)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  unsigned int v32; // ebx
  unsigned int v33; // edi
  char *i; // esi
  int v35; // eax
  int v36; // ecx
  unsigned __int64 v37; // kr08_8
  char *v38; // eax
  _BYTE *v39; // esi
  char *sz; // eax
  int v41; // ebx
  int v42; // edi
  int v43; // edi
  const char *v44; // edi
  int v45; // ebx
  int v46; // edi
  int v47; // eax
  int v48; // [esp-14h] [ebp-494h]
  int v49; // [esp-10h] [ebp-490h]
  int v50; // [esp-Ch] [ebp-48Ch]
  int v51; // [esp-8h] [ebp-488h]
  wchar_t v52; // [esp-4h] [ebp-484h]
  int padding; // [esp+10h] [ebp-470h]
  _CRT_DOUBLE tmp; // [esp+14h] [ebp-46Ch] BYREF
  int wchar; // [esp+1Ch] [ebp-464h] BYREF
  int capexp; // [esp+20h] [ebp-460h]
  STATE state; // [esp+24h] [ebp-45Ch]
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-458h] BYREF
  int no_output; // [esp+38h] [ebp-448h]
  int hexadd; // [esp+3Ch] [ebp-444h]
  const wchar_t *v61; // [esp+40h] [ebp-440h]
  char *heapbuf; // [esp+44h] [ebp-43Ch]
  char tempchar[4]; // [esp+48h] [ebp-438h] BYREF
  wchar_t prefix[2]; // [esp+4Ch] [ebp-434h] BYREF
  int fldwidth; // [esp+50h] [ebp-430h]
  int bufferiswide; // [esp+54h] [ebp-42Ch]
  int prefixlen; // [esp+58h] [ebp-428h]
  _iobuf *f; // [esp+5Ch] [ebp-424h]
  int retval; // [esp+60h] [ebp-420h]
  char *v70; // [esp+64h] [ebp-41Ch]
  int charsout; // [esp+68h] [ebp-418h] BYREF
  int textlen; // [esp+6Ch] [ebp-414h]
  _woutput_l::__l2::<unnamed_type_text> text; // [esp+70h] [ebp-410h]
  int precision; // [esp+74h] [ebp-40Ch]
  int flags; // [esp+78h] [ebp-408h]
  _woutput_l::__l2::<unnamed_type_buffer> buffer; // [esp+7Ch] [ebp-404h] BYREF

  v4 = format;
  v5 = (int *)argptr;
  f = stream;
  v70 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( f == nullptr || format == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    v6 = !_loc_update.updated;
    goto LABEL_3;
  }
  v8 = *format;
  v9 = ST_NORMAL;
  charsout = 0;
  textlen = 0;
  heapbuf = nullptr;
  retval = v8;
  if ( (_WORD)v8 == 0 )
  {
LABEL_217:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  while ( 2 )
  {
    v10 = v4 + 1;
    v61 = v10;
    if ( charsout < 0 )
      goto LABEL_217;
    if ( (unsigned __int16)(v8 - 32) > 0x58u )
      v11 = 0;
    else
      v11 = byte_485D88[(unsigned __int16)v8] & 0xF;
    state = __lookuptable[8 * v11 + v9] >> 4;
    switch ( state )
    {
      case ST_NORMAL:
        goto NORMAL_STATE_1;
      case ST_PERCENT:
        precision = -1;
        capexp = 0;
        no_output = 0;
        fldwidth = 0;
        prefixlen = 0;
        flags = 0;
        bufferiswide = 0;
        goto LABEL_214;
      case ST_FLAG:
        switch ( (unsigned __int16)v8 )
        {
          case ' ':
            flags |= 2u;
            break;
          case '#':
            flags |= 0x80u;
            break;
          case '+':
            flags |= 1u;
            break;
          case '-':
            flags |= 4u;
            break;
          case '0':
            flags |= 8u;
            break;
          default:
            break;
        }
        goto LABEL_214;
      case ST_WIDTH:
        if ( (_WORD)v8 == 42 )
        {
          v70 = (char *)(v5 + 1);
          fldwidth = *v5;
          if ( fldwidth < 0 )
          {
            flags |= 4u;
            fldwidth = -fldwidth;
          }
        }
        else
        {
          fldwidth = 10 * fldwidth + (unsigned __int16)v8 - 48;
        }
        goto LABEL_214;
      case ST_DOT:
        precision = 0;
        goto LABEL_214;
      case ST_PRECIS:
        if ( (_WORD)v8 == 42 )
        {
          v70 = (char *)(v5 + 1);
          precision = *v5;
          if ( precision < 0 )
            precision = -1;
        }
        else
        {
          precision = 10 * precision + (unsigned __int16)v8 - 48;
        }
        goto LABEL_214;
      case ST_SIZE:
        switch ( (unsigned __int16)v8 )
        {
          case 'I':
            v12 = *v10;
            if ( v12 == 54 && v10[1] == 52 )
            {
              flags |= 0x8000u;
              v61 = v10 + 2;
            }
            else if ( v12 == 51 && v10[1] == 50 )
            {
              flags &= ~0x8000u;
              v61 = v10 + 2;
            }
            else if ( v12 != 100 && v12 != 105 && v12 != 111 && v12 != 117 && v12 != 120 && v12 != 88 )
            {
              state = ST_NORMAL;
NORMAL_STATE_1:
              bufferiswide = 1;
              write_char_0(f, pnumwritten: &charsout, ch: v8);
            }
            break;
          case 'h':
            flags |= 0x20u;
            break;
          case 'l':
            if ( *v10 == 108 )
            {
              flags |= 0x1000u;
              v61 = v10 + 1;
            }
            else
            {
              flags |= 0x10u;
            }
            break;
          case 'w':
            flags |= 0x800u;
            break;
          default:
            break;
        }
        goto LABEL_214;
      case ST_TYPE:
        if ( (unsigned __int16)v8 <= 0x64u )
        {
          if ( (unsigned __int16)v8 == 100 )
            goto LABEL_111;
          if ( (unsigned __int16)v8 > 0x53u )
          {
            if ( (unsigned __int16)v8 != 88 )
            {
              if ( (unsigned __int16)v8 == 90 )
              {
                v18 = (__int16 *)*v5;
                v70 = (char *)(v5 + 1);
                if ( v18 != nullptr && (v19.sz = *(char **)(v18 + 2), v19.sz != nullptr) )
                {
                  v20 = *v18;
                  text.sz = v19.sz;
                  if ( (flags & 0x800) != 0 )
                  {
                    v21 = v20 - (v20 >> 31);
                    bufferiswide = 1;
LABEL_179:
                    v20 = v21 >> 1;
                    goto LABEL_180;
                  }
                  bufferiswide = 0;
                }
                else
                {
                  text.sz = __nullstring;
                  strlen(buf: __nullstring);
                }
LABEL_180:
                textlen = v20;
                goto LABEL_181;
              }
              if ( (unsigned __int16)v8 == 97 )
                goto LABEL_65;
              if ( (unsigned __int16)v8 != 99 )
                goto LABEL_181;
              goto LABEL_86;
            }
LABEL_134:
            hexadd = 7;
COMMON_HEX_1:
            retval = 16;
            if ( (flags & 0x80u) != 0 )
            {
              prefix[0] = 48;
              prefix[1] = hexadd + 81;
              prefixlen = 2;
            }
COMMON_INT_1:
            if ( (flags & 0x8000) != 0 || (flags & 0x1000) != 0 )
            {
              v23 = *(_QWORD *)v5;
              v24 = v5 + 2;
            }
            else
            {
              v24 = v5 + 1;
              if ( (flags & 0x20) != 0 )
              {
                v70 = (char *)v24;
                if ( (flags & 0x40) != 0 )
                  LODWORD(v23) = *((__int16 *)v24 - 2);
                else
                  LODWORD(v23) = *((unsigned __int16 *)v24 - 2);
                v23 = (int)v23;
LABEL_151:
                if ( (flags & 0x40) != 0 && v23 < 0 )
                {
                  v23 = -v23;
                  flags |= 0x100u;
                }
                v32 = HIDWORD(v23);
                v33 = v23;
                if ( (flags & 0x9000) == 0 )
                  v32 = 0;
                if ( precision >= 0 )
                {
                  flags &= ~8u;
                  if ( precision > 512 )
                    precision = 512;
                }
                else
                {
                  precision = 1;
                }
                if ( (v32 | (unsigned int)v23) == 0 )
                  prefixlen = 0;
                for ( i = &buffer.sz[511]; ; --i )
                {
                  v35 = precision--;
                  if ( v35 <= 0 && (v32 | v33) == 0 )
                    break;
                  v36 = __PAIR64__(v32, v33) % retval + 48;
                  v37 = __PAIR64__(v32, v33) / retval;
                  v32 = HIDWORD(v37);
                  v33 = v37;
                  if ( v36 > 57 )
                    LOBYTE(v36) = hexadd + v36;
                  *i = v36;
                }
                v38 = (char *)((char *)&buffer.wz[255] + 1 - i);
                v39 = i + 1;
                textlen = (int)v38;
                text.sz = v39;
                if ( (flags & 0x200) != 0 && (v38 == nullptr || *v39 != 48) )
                {
                  *--text.sz = 48;
                  v20 = (int)(v38 + 1);
                  goto LABEL_180;
                }
                goto LABEL_181;
              }
              LODWORD(v23) = *(v24 - 1);
              if ( (flags & 0x40) != 0 )
                v23 = (int)v23;
              else
                HIDWORD(v23) = 0;
            }
            v70 = (char *)v24;
            goto LABEL_151;
          }
          switch ( (unsigned __int16)v8 )
          {
            case 'S':
              if ( (flags & 0x830) == 0 )
                flags |= 0x20u;
LABEL_71:
              v14 = precision;
              if ( precision == -1 )
                v14 = 0x7FFFFFFF;
              v70 = (char *)(v5 + 1);
              v15.sz = (char *)*v5;
              text.sz = v15.sz;
              if ( (flags & 0x20) == 0 )
              {
                if ( v15.sz == nullptr )
                  text.sz = (char *)__wnullstring;
                sz = text.sz;
                bufferiswide = 1;
                while ( v14 != 0 )
                {
                  --v14;
                  if ( *(_WORD *)sz == 0 )
                    break;
                  sz += 2;
                }
                v21 = sz - text.sz;
                goto LABEL_179;
              }
              if ( v15.sz == nullptr )
                text.sz = __nullstring;
              textlen = 0;
              for ( j = (unsigned __int8 *)text.sz; textlen < v14; ++textlen )
              {
                if ( *j == 0 )
                  break;
                if ( _isleadbyte_l(c: *j, plocinfo: &_loc_update.localeinfo) != 0 )
                  ++j;
                ++j;
              }
              break;
            case 'A':
              goto LABEL_64;
            case 'C':
              if ( (flags & 0x830) == 0 )
                flags |= 0x20u;
LABEL_86:
              v17 = *(unsigned __int16 *)v5;
              bufferiswide = 1;
              v70 = (char *)(v5 + 1);
              wchar = v17;
              if ( (flags & 0x20) != 0 )
              {
                tempchar[0] = v17;
                tempchar[1] = 0;
                if ( _mbtowc_l(
                       pwc: (wchar_t *)&buffer,
                       s: tempchar,
                       n: _loc_update.localeinfo.locinfo->mb_cur_max,
                       plocinfo: &_loc_update.localeinfo) < 0 )
                  no_output = 1;
              }
              else
              {
                buffer.wz[0] = v17;
              }
              text.sz = (char *)&buffer;
              textlen = 1;
              break;
            case 'E':
            case 'G':
LABEL_64:
              v8 += 32;
              capexp = 1;
              retval = v8;
LABEL_65:
              flags |= 0x40u;
              p_buffer = &buffer;
              text.sz = (char *)&buffer;
              textlen = 512;
              if ( precision >= 0 )
              {
                if ( precision != 0 )
                {
                  if ( precision > 512 )
                    precision = 512;
                  if ( precision <= 163 )
                  {
                    LOBYTE(v8) = retval;
                  }
                  else
                  {
                    v25 = precision + 349;
                    v26 = (char *)operator new(nSize: precision + 349);
                    LOBYTE(v8) = retval;
                    heapbuf = v26;
                    if ( v26 != nullptr )
                    {
                      text.sz = v26;
                      textlen = v25;
                      p_buffer = (_woutput_l::__l2::<unnamed_type_buffer> *)v26;
                    }
                    else
                    {
                      precision = 163;
                    }
                  }
                }
                else
                {
                  precision = (_WORD)v8 == 103;
                }
              }
              else
              {
                precision = 6;
              }
              v27 = *(_DWORD *)v70;
              v70 += 8;
              HIDWORD(tmp.x) = *((_DWORD *)v70 - 1);
              v51 = capexp;
              v50 = precision;
              LODWORD(tmp.x) = v27;
              v49 = (char)v8;
              v48 = textlen;
              v28 = (void (__cdecl *)(_CRT_DOUBLE *, _woutput_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *))DecodePointer(Ptr: off_5A5FCC);
              v28(a1: &tmp, a2: p_buffer, a3: v48, a4: v49, a5: v50, a6: v51, a7: &_loc_update);
              v29 = flags & 0x80;
              if ( (flags & 0x80) != 0 && precision == 0 )
              {
                v30 = (void (__cdecl *)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_5A5FD8);
                v30(a1: p_buffer, a2: &_loc_update);
              }
              if ( (_WORD)retval == 103 && v29 == 0 )
              {
                v31 = (void (__cdecl *)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_5A5FD4);
                v31(a1: p_buffer, a2: &_loc_update);
              }
              if ( p_buffer->sz[0] == 45 )
              {
                flags |= 0x100u;
                p_buffer = (_woutput_l::__l2::<unnamed_type_buffer> *)((char *)p_buffer + 1);
                text.sz = (char *)p_buffer;
              }
              strlen(buf: p_buffer->sz);
              goto LABEL_180;
            default:
              break;
          }
LABEL_181:
          if ( no_output != 0 )
            goto LABEL_212;
          if ( (flags & 0x40) != 0 )
          {
            if ( (flags & 0x100) != 0 )
            {
              v52 = 45;
            }
            else if ( (flags & 1) != 0 )
            {
              v52 = 43;
            }
            else
            {
              if ( (flags & 2) == 0 )
                goto LABEL_190;
              v52 = 32;
            }
            prefix[0] = v52;
            prefixlen = 1;
          }
LABEL_190:
          v41 = fldwidth - textlen - prefixlen;
          padding = v41;
          if ( (flags & 0xC) == 0 )
          {
            v42 = fldwidth - textlen - prefixlen;
            if ( v41 > 0 )
            {
              do
              {
                --v42;
                write_char_0(f, pnumwritten: &charsout, ch: 0x20u);
              }
              while ( charsout != -1 && v42 > 0 );
            }
          }
          write_string_0(string: prefix, f, pnumwritten: &charsout, len: prefixlen);
          if ( (flags & 8) != 0 && (flags & 4) == 0 )
          {
            v43 = v41;
            if ( v41 > 0 )
            {
              do
              {
                --v43;
                write_char_0(f, pnumwritten: &charsout, ch: 0x30u);
              }
              while ( charsout != -1 && v43 > 0 );
            }
          }
          if ( bufferiswide != 0 || textlen <= 0 )
          {
            write_string_0(string: text.wz, f, pnumwritten: &charsout, len: textlen);
          }
          else
          {
            v44 = text.sz;
            v45 = textlen;
            while ( 1 )
            {
              --v45;
              retval = _mbtowc_l(
                         pwc: (wchar_t *)&wchar,
                         s: v44,
                         n: _loc_update.localeinfo.locinfo->mb_cur_max,
                         plocinfo: &_loc_update.localeinfo);
              if ( retval <= 0 )
                break;
              write_char_0(f, pnumwritten: &charsout, ch: wchar);
              v44 += retval;
              if ( v45 <= 0 )
                goto LABEL_207;
            }
            charsout = -1;
          }
LABEL_207:
          if ( charsout >= 0 && (flags & 4) != 0 )
          {
            v46 = padding;
            do
            {
              if ( v46 <= 0 )
                break;
              --v46;
              write_char_0(f, pnumwritten: &charsout, ch: 0x20u);
            }
            while ( charsout != -1 );
          }
LABEL_212:
          if ( heapbuf != nullptr )
          {
            free(pMem: heapbuf);
            heapbuf = nullptr;
          }
LABEL_214:
          v4 = v61;
          v47 = *v61;
          retval = v47;
          if ( (_WORD)v47 == 0 )
            goto LABEL_217;
          v9 = state;
          v5 = (int *)v70;
          v8 = v47;
          continue;
        }
        if ( (unsigned __int16)v8 > 0x70u )
        {
          if ( (unsigned __int16)v8 != 115 )
          {
            if ( (unsigned __int16)v8 != 117 )
            {
              if ( (unsigned __int16)v8 != 120 )
                goto LABEL_181;
              hexadd = 39;
              goto COMMON_HEX_1;
            }
            goto LABEL_112;
          }
          goto LABEL_71;
        }
        if ( (unsigned __int16)v8 == 112 )
        {
          precision = 8;
          goto LABEL_134;
        }
        if ( (unsigned __int16)v8 < 0x65u )
          goto LABEL_181;
        if ( (unsigned __int16)v8 <= 0x67u )
          goto LABEL_65;
        if ( (unsigned __int16)v8 == 105 )
        {
LABEL_111:
          flags |= 0x40u;
LABEL_112:
          retval = 10;
          goto COMMON_INT_1;
        }
        if ( (unsigned __int16)v8 != 110 )
        {
          if ( (unsigned __int16)v8 != 111 )
            goto LABEL_181;
          retval = 8;
          if ( (flags & 0x80u) != 0 )
            flags |= 0x200u;
          goto COMMON_INT_1;
        }
        v22 = (_WORD *)*v5;
        v70 = (char *)(v5 + 1);
        if ( _get_printf_count_output(a1: 7) != 0 )
        {
          if ( (flags & 0x20) != 0 )
            *v22 = charsout;
          else
            *(_DWORD *)v22 = charsout;
          no_output = 1;
          goto LABEL_212;
        }
        *_errno() = 22;
        _invalid_parameter_noinfo();
        v6 = !_loc_update.updated;
LABEL_3:
        if ( !v6 )
          _loc_update.ptd->_ownlocale &= ~2u;
        return -1;
      default:
        goto LABEL_214;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DA20
// Name: __fltin2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_flt *__cdecl _fltin2(_flt *flt, const char *str, localeinfo_struct *_Locale)
{
  int v3; // ebx
  INTRNCVT_STATUS v4; // eax
  const char *EndPtr; // [esp+Ch] [ebp-24h] BYREF
  const char *v7; // [esp+10h] [ebp-20h]
  _CRT_DOUBLE x; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int flags; // [esp+1Ch] [ebp-14h]
  _LDBL12 ld12; // [esp+20h] [ebp-10h] BYREF

  v7 = str;
  v3 = 0;
  flags = __strgtold12_l(pld12: &ld12, p_end_ptr: &EndPtr, str, mult12: 0, scale: 0, decpt: 0, implicit_E: 0, _Locale);
  if ( (flags & 4) != 0 )
  {
    v3 = 512;
    *(_CRT_DOUBLE *)&x.x = 0;
  }
  else
  {
    v4 = _ld12tod(pld12: &ld12, d: &x);
    if ( (flags & 2) != 0 || v4 == INTRNCVT_OVERFLOW )
      v3 = 128;
    if ( (flags & 1) != 0 || v4 == INTRNCVT_UNDERFLOW )
      v3 |= 0x100u;
  }
  flt->nbytes = EndPtr - v7;
  flt->dval = x.x;
  flt->flags = v3;
  return flt;
}

//------------------------------------------------------------------------------
// Address: 0x0046DAC7
// Name: wcstoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcstoxl(const wchar_t *nptr, const wchar_t **endptr, unsigned int ibase, int flags)
{
  const wchar_t *v4; // edi
  wchar_t v6; // si
  int v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // eax
  int v11; // eax
  const wchar_t *v12; // edi
  unsigned __int16 v13; // [esp-10h] [ebp-1Ch]
  unsigned int number; // [esp+8h] [ebp-4h]

  v4 = nptr;
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  number = 0;
  do
  {
    v6 = *v4;
    v13 = *v4++;
  }
  while ( iswctype(c: v13, mask: 8u) != 0 );
  if ( v6 == 45 )
  {
    flags |= 2u;
  }
  else if ( v6 != 43 )
  {
    goto LABEL_14;
  }
  v6 = *v4++;
LABEL_14:
  if ( ibase != 0 )
    goto LABEL_21;
  if ( _wchartodigit(ch: v6) == 0 )
  {
    v7 = *v4;
    if ( v7 != 120 && v7 != 88 )
    {
      ibase = 8;
      goto LABEL_26;
    }
    ibase = 16;
LABEL_21:
    if ( ibase == 16 && _wchartodigit(ch: v6) == 0 )
    {
      v8 = *v4;
      if ( v8 == 120 || v8 == 88 )
      {
        v6 = v4[1];
        v4 += 2;
      }
    }
    goto LABEL_26;
  }
  ibase = 10;
LABEL_26:
  v9 = 0xFFFFFFFF / ibase;
  while ( 1 )
  {
    v10 = _wchartodigit(ch: v6);
    if ( v10 == -1 )
    {
      if ( (v6 < 0x41u || v6 > 0x5Au) && (unsigned __int16)(v6 - 97) > 0x19u )
        break;
      v11 = v6;
      if ( (unsigned __int16)(v6 - 97) <= 0x19u )
        v11 = v6 - 32;
      v10 = v11 - 55;
    }
    if ( v10 >= ibase )
      break;
    flags |= 8u;
    if ( number < v9 || number == v9 && v10 <= 0xFFFFFFFF % ibase )
    {
      number = v10 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v6 = *v4++;
  }
  v12 = v4 - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v12 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v12;
  if ( (flags & 2) != 0 )
    return -number;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x0046DC89
// Name: _wcstol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcstol(const wchar_t *nptr, wchar_t **endptr, unsigned int ibase)
{
  return wcstoxl(nptr, (const wchar_t **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0046DCA3
// Name: __check_float_string_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _check_float_string_0@<eax>(
        unsigned int *pnFloatStrSz@<esi>,
        wchar_t **pFloatStr@<edi>,
        unsigned int nFloatStrUsed,
        wchar_t *floatstring,
        int *pmalloc_FloatStrFlag)
{
  unsigned int v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v8; // eax

  v5 = *pnFloatStrSz;
  if ( nFloatStrUsed == *pnFloatStrSz )
  {
    if ( *pFloatStr == floatstring )
    {
      v6 = calloc(count: v5, size: 4u);
      *pFloatStr = (wchar_t *)v6;
      if ( v6 == nullptr )
        return 0;
      *pmalloc_FloatStrFlag = 1;
      memcpy(dst: (unsigned __int8 *)*pFloatStr, src: (unsigned __int8 *)floatstring, count: 2 * *pnFloatStrSz);
    }
    else
    {
      v8 = _recalloc_crt(ptr: *pFloatStr, count: v5, size: 4u);
      if ( v8 == nullptr )
        return 0;
      *pFloatStr = (wchar_t *)v8;
    }
    *pnFloatStrSz *= 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046DCFD
// Name: _hextodec_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl hextodec_0(wchar_t chr)
{
  if ( (chr & 0xFF00) != 0 || isdigit(c: (unsigned __int8)chr) == 0 )
    return (chr & 0xFFDF) - 7;
  else
    return chr;
}

//------------------------------------------------------------------------------
// Address: 0x0046DD33
// Name: _un_inc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl un_inc(unsigned __int16 chr, _iobuf *fileptr)
{
  if ( chr != 0xFFFF )
    _ungetwc_nolock(ch: chr, str: fileptr);
}

//------------------------------------------------------------------------------
// Address: 0x0046DD4B
// Name: _whiteout_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __usercall whiteout_0@<ax>(int *counter@<esi>, _iobuf *fileptr)
{
  unsigned __int16 v2; // di

  do
  {
    ++*counter;
    v2 = _fgetwc_nolock(stream: fileptr);
  }
  while ( v2 != 0xFFFF && iswctype(c: v2, mask: 8u) != 0 );
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0046DD7D
// Name: __winput_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _winput_l(_iobuf *stream, const wchar_t *format, localeinfo_struct *plocinfo, char *arglist)
{
  int result; // eax
  unsigned __int16 v5; // ax
  unsigned __int16 *v6; // edi
  unsigned __int16 v7; // ax
  _QWORD *v8; // esi
  int v9; // ebx
  int v10; // ecx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // edi
  int v15; // ebx
  unsigned int v16; // ebx
  int v17; // eax
  wchar_t v18; // si
  int v19; // eax
  int v20; // eax
  int v21; // eax
  unsigned __int16 v22; // ax
  int v23; // eax
  int v24; // eax
  unsigned int v25; // esi
  char *v26; // edi
  int v27; // eax
  void (__cdecl *v28)(int, void *, char *, _LocaleUpdate *); // eax
  _QWORD *v29; // edi
  int v30; // eax
  unsigned __int16 v31; // ax
  const wchar_t *v32; // edi
  unsigned __int8 *v33; // esi
  char *v34; // eax
  unsigned __int16 v35; // dx
  int v36; // ecx
  unsigned __int16 v37; // ax
  unsigned int v38; // ebx
  unsigned __int16 v39; // ax
  unsigned __int16 v40; // ax
  int v41; // eax
  unsigned int v42; // esi
  int v43; // edi
  unsigned __int16 v44; // ax
  unsigned __int16 v45; // cx
  int v46; // [esp-14h] [ebp-354h]
  void *v47; // [esp-10h] [ebp-350h]
  _iobuf *v48; // [esp-8h] [ebp-348h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-338h] BYREF
  int prevchar; // [esp+18h] [ebp-328h]
  char *arglistsave; // [esp+1Ch] [ebp-324h]
  int malloc_flag; // [esp+20h] [ebp-320h]
  char *v53; // [esp+24h] [ebp-31Ch]
  char *table; // [esp+28h] [ebp-318h]
  unsigned int nFloatStrSz; // [esp+2Ch] [ebp-314h] BYREF
  int malloc_FloatStrFlag; // [esp+30h] [ebp-310h] BYREF
  int count; // [esp+34h] [ebp-30Ch]
  void *pointer; // [esp+38h] [ebp-308h]
  const wchar_t *v59; // [esp+3Ch] [ebp-304h]
  int integer64; // [esp+40h] [ebp-300h]
  unsigned __int64 num64; // [esp+44h] [ebp-2FCh]
  int widthset; // [esp+4Ch] [ebp-2F4h]
  int temp; // [esp+50h] [ebp-2F0h] BYREF
  char reject; // [esp+57h] [ebp-2E9h]
  int comchr; // [esp+58h] [ebp-2E8h]
  int started; // [esp+5Ch] [ebp-2E4h]
  wchar_t *pFloatStr; // [esp+60h] [ebp-2E0h] BYREF
  char negative; // [esp+65h] [ebp-2DBh]
  char match; // [esp+66h] [ebp-2DAh]
  char fl_wchar_arg; // [esp+67h] [ebp-2D9h]
  _iobuf *fileptr; // [esp+68h] [ebp-2D8h]
  char suppress; // [esp+6Dh] [ebp-2D3h]
  char longone; // [esp+6Eh] [ebp-2D2h]
  char widechar; // [esp+6Fh] [ebp-2D1h]
  int width; // [esp+70h] [ebp-2D0h]
  unsigned __int16 chr[2]; // [esp+74h] [ebp-2CCh]
  int charcount; // [esp+78h] [ebp-2C8h] BYREF
  char done_flag; // [esp+7Fh] [ebp-2C1h]
  wchar_t floatstring[350]; // [esp+80h] [ebp-2C0h] BYREF

  v53 = arglist;
  fileptr = stream;
  v59 = format;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  table = nullptr;
  malloc_flag = 0;
  *(_DWORD *)chr = 0;
  if ( format == nullptr || stream == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v5 = *format;
  match = 0;
  charcount = 0;
  count = 0;
  if ( v5 == 0 )
    goto LABEL_276;
  v6 = (unsigned __int16 *)v59;
  while ( 2 )
  {
    if ( iswctype(c: v5, mask: 8u) != 0 )
    {
      v48 = fileptr;
      --charcount;
      v7 = whiteout_0(counter: &charcount, fileptr);
      un_inc(chr: v7, fileptr: v48);
      do
        ++v6;
      while ( iswctype(c: *v6, mask: 8u) != 0 );
      goto LABEL_262;
    }
    if ( *v6 != 37 )
      goto LABEL_257;
    if ( v6[1] == 37 )
    {
      ++v6;
LABEL_257:
      ++charcount;
      v44 = _fgetwc_nolock(stream: fileptr);
      v45 = *v6++;
      *(_DWORD *)chr = v44;
      v59 = v6;
      if ( v45 == v44 )
        goto LABEL_258;
      goto LABEL_265;
    }
    temp = 0;
    prevchar = 0;
    started = 0;
    widthset = 0;
    width = 0;
    integer64 = 0;
    reject = 0;
    negative = 0;
    suppress = 0;
    done_flag = 0;
    fl_wchar_arg = 0;
    widechar = 0;
    longone = 1;
    v8 = nullptr;
    do
    {
      v9 = *++v6;
      if ( (v9 & 0xFF00) == 0 && isdigit(c: (unsigned __int8)v9) != 0 )
      {
        ++widthset;
        width = 10 * width + v9 - 48;
        continue;
      }
      if ( v9 > 78 )
      {
        if ( v9 == 104 )
        {
          --longone;
          --widechar;
        }
        else
        {
          if ( v9 == 108 )
          {
            if ( v6[1] == 108 )
            {
              ++v6;
              goto LABEL_26;
            }
            ++longone;
          }
          else if ( v9 != 119 )
          {
            goto DEFAULT_LABEL_0;
          }
          ++widechar;
        }
      }
      else
      {
        switch ( v9 )
        {
          case 'N':
            continue;
          case '*':
            ++suppress;
            continue;
          case 'F':
            continue;
          default:
            break;
        }
        if ( v9 != 73 )
        {
          if ( v9 == 76 )
          {
            ++longone;
            continue;
          }
DEFAULT_LABEL_0:
          ++done_flag;
          continue;
        }
        v10 = v6[1];
        if ( v10 == 54 && v6[2] == 52 )
        {
          v6 += 2;
LABEL_26:
          ++integer64;
          num64 = 0;
          continue;
        }
        if ( v10 == 51 && v6[2] == 50 )
        {
          v6 += 2;
          continue;
        }
        if ( v10 != 100 && v10 != 105 && v10 != 111 && v10 != 120 && v10 != 88 )
          goto DEFAULT_LABEL_0;
      }
    }
    while ( done_flag == 0 );
    v59 = v6;
    if ( suppress == 0 )
    {
      v8 = *(_QWORD **)v53;
      arglistsave = v53;
      v53 += 4;
    }
    pointer = v8;
    done_flag = 0;
    if ( widechar == 0 )
    {
      v11 = *v6;
      if ( v11 == 83 || (widechar = 1, v11 == 67) )
        widechar = -1;
    }
    v12 = *v6 | 0x20;
    comchr = v12;
    if ( v12 != 110 )
    {
      if ( v12 == 99 || v12 == 123 )
      {
        ++charcount;
        v13 = _fgetwc_nolock(stream: fileptr);
      }
      else
      {
        v13 = whiteout_0(counter: &charcount, fileptr);
      }
      *(_DWORD *)chr = v13;
      if ( v13 == 0xFFFF )
        goto error_return_1;
      v8 = pointer;
      v6 = (unsigned __int16 *)v59;
    }
    if ( widthset != 0 && width == 0 )
      goto LABEL_265;
    if ( v12 <= 111 )
    {
      if ( v12 == 111 )
        goto LABEL_200;
      if ( v12 != 99 )
      {
        if ( v12 != 100 )
        {
          if ( v12 <= 100 )
            goto LABEL_141;
          if ( v12 > 103 )
          {
            if ( v12 != 105 )
            {
              if ( v12 == 110 )
              {
                v14 = charcount;
                if ( suppress != 0 )
                  goto LABEL_255;
                goto assign_num_0;
              }
LABEL_141:
              if ( *v6 == chr[0] )
              {
                --match;
                if ( suppress == 0 )
                  v53 = arglistsave;
                goto LABEL_255;
              }
LABEL_265:
              un_inc(chr: chr[0], fileptr);
              goto error_return_1;
            }
            comchr = 100;
LABEL_73:
            LOWORD(v15) = chr[0];
            if ( chr[0] == 45 )
            {
              negative = 1;
              goto x_incwidth_0;
            }
            if ( chr[0] == 43 )
            {
x_incwidth_0:
              if ( --width != 0 || widthset == 0 )
              {
                ++charcount;
                LOWORD(v15) = _fgetwc_nolock(stream: fileptr);
                *(_DWORD *)chr = (unsigned __int16)v15;
              }
              else
              {
                done_flag = 1;
              }
            }
            if ( (_WORD)v15 == 48 )
            {
              ++charcount;
              v40 = _fgetwc_nolock(stream: fileptr);
              LOWORD(v15) = v40;
              *(_DWORD *)chr = v40;
              if ( v40 == 120 || v40 == 88 )
              {
                ++charcount;
                LOWORD(v15) = _fgetwc_nolock(stream: fileptr);
                *(_DWORD *)chr = (unsigned __int16)v15;
                if ( widthset != 0 )
                {
                  width -= 2;
                  if ( width < 1 )
                    ++done_flag;
                }
                comchr = 120;
                goto getnum_0;
              }
              started = 1;
              if ( comchr != 120 )
              {
                if ( widthset != 0 && --width == 0 )
                  ++done_flag;
                comchr = 111;
                goto getnum_0;
              }
              --charcount;
              un_inc(chr: v40, fileptr);
              v15 = 48;
LABEL_207:
              *(_DWORD *)chr = v15;
            }
            goto getnum_0;
          }
          v16 = 0;
          if ( chr[0] == 45 )
          {
            *pFloatStr = 45;
            v16 = 1;
            goto f_incwidth_0;
          }
          if ( chr[0] == 43 )
          {
f_incwidth_0:
            --width;
            ++charcount;
            *(_DWORD *)chr = _fgetwc_nolock(stream: fileptr);
          }
          if ( widthset == 0 )
            width = -1;
          for ( ; (chr[0] & 0xFF00) == 0; *(_DWORD *)chr = _fgetwc_nolock(stream: fileptr) )
          {
            if ( isdigit(c: LOBYTE(chr[0])) == 0 )
              break;
            v17 = width--;
            if ( v17 == 0 )
              break;
            ++started;
            pFloatStr[v16++] = SLOBYTE(chr[0]);
            if ( _check_float_string_0(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: v16,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_1;
            ++charcount;
          }
          v18 = *_loc_update.localeinfo.locinfo->lconv->_W_decimal_point;
          if ( v18 == SLOBYTE(chr[0]) )
          {
            v19 = width--;
            if ( v19 != 0 )
            {
              ++charcount;
              *(_DWORD *)chr = _fgetwc_nolock(stream: fileptr);
              pFloatStr[v16++] = v18;
              if ( _check_float_string_0(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: v16,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_1;
              for ( ; (chr[0] & 0xFF00) == 0; *(_DWORD *)chr = _fgetwc_nolock(stream: fileptr) )
              {
                if ( isdigit(c: LOBYTE(chr[0])) == 0 )
                  break;
                v20 = width--;
                if ( v20 == 0 )
                  break;
                ++started;
                pFloatStr[v16++] = chr[0];
                if ( _check_float_string_0(
                       pnFloatStrSz: &nFloatStrSz,
                       &pFloatStr,
                       nFloatStrUsed: v16,
                       floatstring,
                       pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                  goto error_return_1;
                ++charcount;
              }
            }
          }
          if ( started != 0 && (chr[0] == 101 || chr[0] == 69) )
          {
            v21 = width--;
            if ( v21 != 0 )
            {
              pFloatStr[v16++] = 101;
              if ( _check_float_string_0(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: v16,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_1;
              ++charcount;
              v22 = _fgetwc_nolock(stream: fileptr);
              *(_DWORD *)chr = v22;
              if ( v22 == 45 )
              {
                pFloatStr[v16++] = 45;
                if ( _check_float_string_0(
                       pnFloatStrSz: &nFloatStrSz,
                       &pFloatStr,
                       nFloatStrUsed: v16,
                       floatstring,
                       pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                  goto error_return_1;
f_incwidth2_0:
                v23 = width--;
                if ( v23 != 0 )
                {
                  ++charcount;
                  *(_DWORD *)chr = _fgetwc_nolock(stream: fileptr);
                }
                else
                {
                  width = 0;
                }
              }
              else if ( chr[0] == 43 )
              {
                goto f_incwidth2_0;
              }
              for ( ; (chr[0] & 0xFF00) == 0; *(_DWORD *)chr = _fgetwc_nolock(stream: fileptr) )
              {
                if ( isdigit(c: LOBYTE(chr[0])) == 0 )
                  break;
                v24 = width--;
                if ( v24 == 0 )
                  break;
                ++started;
                pFloatStr[v16++] = chr[0];
                if ( _check_float_string_0(
                       pnFloatStrSz: &nFloatStrSz,
                       &pFloatStr,
                       nFloatStrUsed: v16,
                       floatstring,
                       pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                  goto error_return_1;
                ++charcount;
              }
            }
          }
          --charcount;
          un_inc(chr: chr[0], fileptr);
          if ( started != 0 )
          {
            if ( suppress != 0 )
              goto LABEL_255;
            ++count;
            v25 = 2 * nFloatStrSz + 2;
            pFloatStr[v16] = 0;
            v26 = (char *)operator new(nSize: v25);
            if ( v26 != nullptr )
            {
              v27 = wcstombs_s(pConvertedChars: nullptr, dst: v26, sizeInBytes: v25, src: pFloatStr, n: v25 - 1);
              if ( v27 != 0 && (v27 == 22 || v27 == 34) )
                _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
              v47 = pointer;
              v46 = longone - 1;
              v28 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))DecodePointer(Ptr: Ptr);
              v28(a1: v46, a2: v47, a3: v26, a4: &_loc_update);
              free(pMem: v26);
              goto LABEL_255;
            }
          }
          goto error_return_1;
        }
LABEL_200:
        LOWORD(v15) = chr[0];
        if ( chr[0] == 45 )
        {
          negative = 1;
        }
        else if ( chr[0] != 43 )
        {
          goto getnum_0;
        }
        if ( --width != 0 || widthset == 0 )
        {
          ++charcount;
          v15 = _fgetwc_nolock(stream: fileptr);
          goto LABEL_207;
        }
        done_flag = 1;
getnum_0:
        if ( integer64 != 0 )
        {
          if ( done_flag == 0 )
          {
            while ( 1 )
            {
              if ( comchr == 120 || comchr == 112 )
              {
                if ( (v15 & 0xFF00) != 0 || isxdigit(c: (unsigned __int8)v15) == 0 )
                {
LABEL_224:
                  --charcount;
                  un_inc(chr: v15, fileptr);
                  break;
                }
                v42 = 16 * num64;
                HIDWORD(num64) = num64 >> 28;
                LOWORD(v15) = hextodec_0(chr: v15);
                *(_DWORD *)chr = (unsigned __int16)v15;
              }
              else
              {
                if ( (v15 & 0xFF00) != 0 || isdigit(c: (unsigned __int8)v15) == 0 )
                  goto LABEL_224;
                if ( comchr == 111 )
                {
                  if ( (unsigned __int16)v15 >= 0x38u )
                    goto LABEL_224;
                  v42 = 8 * num64;
                  HIDWORD(num64) = num64 >> 29;
                }
                else
                {
                  HIDWORD(num64) = (10 * num64) >> 32;
                  v42 = 10 * num64;
                }
              }
              ++started;
              num64 = (unsigned __int16)v15 - 48 + __PAIR64__(HIDWORD(num64), v42);
              if ( widthset != 0 && --width == 0 )
                break;
              ++charcount;
              LOWORD(v15) = _fgetwc_nolock(stream: fileptr);
              *(_DWORD *)chr = (unsigned __int16)v15;
            }
          }
          v14 = temp;
          if ( negative != 0 )
            num64 = -(__int64)num64;
        }
        else
        {
          v14 = temp;
          if ( done_flag == 0 )
          {
            while ( 1 )
            {
              if ( comchr == 120 || comchr == 112 )
              {
                if ( (v15 & 0xFF00) != 0 || isxdigit(c: (unsigned __int8)v15) == 0 )
                {
LABEL_242:
                  --charcount;
                  un_inc(chr: v15, fileptr);
                  break;
                }
                v43 = 16 * v14;
                LOWORD(v15) = hextodec_0(chr: v15);
                *(_DWORD *)chr = (unsigned __int16)v15;
              }
              else
              {
                if ( (v15 & 0xFF00) != 0 || isdigit(c: (unsigned __int8)v15) == 0 )
                  goto LABEL_242;
                if ( comchr == 111 )
                {
                  if ( (unsigned __int16)v15 >= 0x38u )
                    goto LABEL_242;
                  v43 = 8 * v14;
                }
                else
                {
                  v43 = 10 * v14;
                }
              }
              ++started;
              v14 = v43 + (unsigned __int16)v15 - 48;
              if ( widthset != 0 && --width == 0 )
                break;
              ++charcount;
              LOWORD(v15) = _fgetwc_nolock(stream: fileptr);
              *(_DWORD *)chr = (unsigned __int16)v15;
            }
          }
          if ( negative != 0 )
            v14 = -v14;
        }
        if ( comchr == 70 )
          started = 0;
        if ( started == 0 )
          goto error_return_1;
        if ( suppress != 0 )
          goto LABEL_255;
        ++count;
        v8 = pointer;
assign_num_0:
        if ( integer64 != 0 )
        {
          *v8 = num64;
        }
        else if ( longone != 0 )
        {
          *(_DWORD *)v8 = v14;
        }
        else
        {
          *(_WORD *)v8 = v14;
        }
        goto LABEL_255;
      }
      if ( widthset == 0 )
      {
        ++width;
        widthset = 1;
      }
LABEL_120:
      if ( widechar > 0 )
        fl_wchar_arg = 1;
scanit_0:
      --charcount;
      v29 = v8;
      un_inc(chr: chr[0], fileptr);
      while ( 1 )
      {
        if ( widthset != 0 )
        {
          v30 = width--;
          if ( v30 == 0 )
            break;
        }
        ++charcount;
        v31 = _fgetwc_nolock(stream: fileptr);
        *(_DWORD *)chr = v31;
        if ( v31 == 0xFFFF )
          goto LABEL_192;
        if ( v12 != 99 )
        {
          if ( v12 != 115 )
            goto LABEL_281;
          if ( v31 >= 9u && v31 <= 0xDu )
          {
LABEL_192:
            --charcount;
            un_inc(chr: v31, fileptr);
            break;
          }
          if ( v31 == 32 )
          {
LABEL_281:
            if ( v12 != 123 )
              goto LABEL_192;
            v12 = comchr;
            if ( ((1 << (v31 & 7)) & (reject ^ table[v31 >> 3])) == 0 )
              goto LABEL_192;
          }
        }
        if ( suppress != 0 )
        {
          v29 = (_QWORD *)((char *)v29 + 2);
          continue;
        }
        if ( fl_wchar_arg != 0 )
        {
          *(_WORD *)v8 = v31;
          v8 = (_QWORD *)((char *)v8 + 2);
LABEL_190:
          pointer = v8;
          continue;
        }
        temp = 0;
        v41 = wctomb_s(pRetValue: &temp, dst: (char *)v8, sizeInBytes: 5u, wchar: v31);
        if ( v41 == 0 )
        {
          v8 = (_QWORD *)((char *)v8 + temp);
          goto LABEL_190;
        }
        if ( v41 == 22 || v41 == 34 )
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      }
      if ( v29 == v8 )
        goto error_return_1;
      if ( suppress == 0 )
      {
        ++count;
        if ( v12 != 99 )
        {
          if ( fl_wchar_arg != 0 )
            *(_WORD *)pointer = 0;
          else
            *(_BYTE *)pointer = 0;
        }
      }
LABEL_255:
      ++match;
      v6 = (unsigned __int16 *)++v59;
LABEL_258:
      if ( chr[0] == 0xFFFF )
      {
        if ( *v6 == 37 && v59[1] == 110 )
        {
          v6 = (unsigned __int16 *)v59;
          goto LABEL_262;
        }
        goto error_return_1;
      }
LABEL_262:
      v5 = *v6;
      if ( *v6 == 0 )
        goto error_return_1;
      continue;
    }
    break;
  }
  switch ( v12 )
  {
    case 'p':
      longone = 1;
      goto LABEL_200;
    case 's':
      goto LABEL_120;
    case 'u':
      goto LABEL_200;
    case 'x':
      goto LABEL_73;
    default:
      break;
  }
  if ( v12 != 123 )
    goto LABEL_141;
  if ( widechar > 0 )
    fl_wchar_arg = 1;
  v32 = v6 + 1;
  if ( *v32 == 94 )
  {
    ++v32;
    reject = -1;
  }
  v33 = (unsigned __int8 *)table;
  if ( table == nullptr )
  {
    v34 = (char *)operator new(nSize: 0x2000u);
    table = v34;
    if ( v34 == nullptr )
      goto error_return_1;
    malloc_flag = 1;
    v33 = (unsigned __int8 *)v34;
  }
  memset(dst: v33, value: 0, count: 0x2000u);
  if ( *v32 == 93 )
  {
    v35 = 93;
    ++v32;
    v33[11] = 32;
  }
  else
  {
    v35 = prevchar;
  }
  while ( 1 )
  {
    v39 = *v32;
    if ( *v32 == 93 )
      break;
    ++v32;
    if ( v39 == 45 && v35 != 0 && (_WORD)(v36 = *v32) != 93 )
    {
      v37 = *v32++;
      if ( v35 >= (unsigned __int16)v36 )
      {
        v36 = v35;
        v35 = v37;
      }
      temp = v36;
      if ( v35 < (unsigned __int16)v36 )
      {
        v38 = v35;
        integer64 = (unsigned __int16)(v36 - v35);
        do
        {
          v33[v38 >> 3] |= 1 << (v38 & 7);
          ++v38;
          --integer64;
        }
        while ( integer64 != 0 );
      }
      v33[(unsigned __int16)temp >> 3] |= 1 << (temp & 7);
      v35 = 0;
    }
    else
    {
      v35 = v39;
      v33[v39 >> 3] |= 1 << (v39 & 7);
    }
  }
  if ( *v32 != 0 )
  {
    v8 = pointer;
    v12 = comchr;
    v59 = v32;
    goto scanit_0;
  }
error_return_1:
  if ( malloc_flag == 1 )
    free(pMem: table);
  if ( malloc_FloatStrFlag == 1 )
    free(pMem: pFloatStr);
  if ( chr[0] == 0xFFFF )
  {
    result = count;
    if ( count == 0 && match == 0 )
      result = -1;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
LABEL_276:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x0046EE52
// Name: __wfltin2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_flt *__cdecl _wfltin2(_flt *flt, const wchar_t *str, localeinfo_struct *_Locale)
{
  int v3; // ebx
  INTRNCVT_STATUS v4; // eax
  const wchar_t *EndPtr; // [esp+Ch] [ebp-24h] BYREF
  const wchar_t *v7; // [esp+10h] [ebp-20h]
  _CRT_DOUBLE x; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int flags; // [esp+1Ch] [ebp-14h]
  _LDBL12 ld12; // [esp+20h] [ebp-10h] BYREF

  v7 = str;
  v3 = 0;
  flags = __wstrgtold12_l(pld12: &ld12, p_end_ptr: &EndPtr, str, mult12: 0, scale: 0, decpt: 0, implicit_E: 0, _Locale);
  if ( (flags & 4) != 0 )
  {
    v3 = 512;
    *(_CRT_DOUBLE *)&x.x = 0;
  }
  else
  {
    v4 = _ld12tod(pld12: &ld12, d: &x);
    if ( (flags & 2) != 0 || v4 == INTRNCVT_OVERFLOW )
      v3 = 128;
    if ( (flags & 1) != 0 || v4 == INTRNCVT_UNDERFLOW )
      v3 |= 0x100u;
  }
  flt->nbytes = EndPtr - v7;
  flt->dval = x.x;
  flt->flags = v3;
  return flt;
}

//------------------------------------------------------------------------------
// Address: 0x0046EEFB
// Name: ___wstrgtold12_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __wstrgtold12_l(
        _LDBL12 *pld12,
        const wchar_t **p_end_ptr,
        const wchar_t *str,
        int mult12,
        int scale,
        int decpt,
        int implicit_E,
        localeinfo_struct *_Locale)
{
  int v8; // ecx
  const wchar_t *v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  const wchar_t *v15; // edx
  char *v16; // ecx
  char *v17; // ecx
  int v18; // eax
  int v19; // eax
  bool v20; // zf
  int v21; // eax
  char *v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // eax
  _LDBL12 *v26; // ecx
  char v27; // al
  _LDBL12 *v28; // ecx
  int v29; // eax
  _LDBL12 *v30; // ebx
  __int16 v31; // ax
  __int16 v32; // si
  unsigned __int16 v33; // cx
  int v34; // eax
  _WORD *v35; // edi
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // esi
  __int16 v39; // cx
  unsigned int v40; // eax
  int v41; // esi
  int v42; // eax
  int v43; // esi
  int v44; // eax
  int v45; // edi
  int v46; // eax
  __int16 v47; // cx
  int v48; // esi
  unsigned int v49; // edx
  __int16 v50; // ax
  int v51; // [esp-Ch] [ebp-8Ch]
  int v52; // [esp-Ch] [ebp-8Ch]
  _LDBL12 *v53; // [esp+8h] [ebp-78h]
  __int16 man_sign; // [esp+Ch] [ebp-74h]
  unsigned int result_flags; // [esp+10h] [ebp-70h]
  int found_decpoint; // [esp+14h] [ebp-6Ch]
  unsigned __int8 *found_decpointa; // [esp+14h] [ebp-6Ch]
  int pow; // [esp+18h] [ebp-68h]
  int powa; // [esp+18h] [ebp-68h]
  int exp_sign; // [esp+1Ch] [ebp-64h]
  int exp_signa; // [esp+1Ch] [ebp-64h]
  int found_exponent; // [esp+20h] [ebp-60h]
  unsigned __int8 *found_exponenta; // [esp+20h] [ebp-60h]
  int found_digit; // [esp+24h] [ebp-5Ch]
  int found_digita; // [esp+24h] [ebp-5Ch]
  char *manp; // [esp+28h] [ebp-58h]
  char *manpa; // [esp+28h] [ebp-58h]
  const wchar_t *savedp; // [esp+2Ch] [ebp-54h]
  int savedpa; // [esp+2Ch] [ebp-54h]
  int exp_adj; // [esp+30h] [ebp-50h]
  int exp_adja; // [esp+30h] [ebp-50h]
  unsigned int manlen; // [esp+34h] [ebp-4Ch]
  __int16 manlena; // [esp+34h] [ebp-4Ch]
  __int64 v74; // [esp+38h] [ebp-48h] BYREF
  int v75; // [esp+40h] [ebp-40h]
  _LDBL12 tmpld12; // [esp+44h] [ebp-3Ch] BYREF
  _BYTE v77[12]; // [esp+54h] [ebp-2Ch] BYREF
  char buf[28]; // [esp+60h] [ebp-20h] BYREF

  v8 = 0;
  manp = buf;
  man_sign = 0;
  exp_sign = 1;
  manlen = 0;
  found_digit = 0;
  found_decpoint = 0;
  found_exponent = 0;
  pow = 0;
  exp_adj = 0;
  result_flags = 0;
  if ( _Locale == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v10 = str;
  savedp = str;
  while ( 1 )
  {
    v11 = *v10;
    if ( v11 != 32 && v11 != 9 && v11 != 10 && v11 != 13 )
      break;
    ++v10;
  }
  while ( 2 )
  {
    v12 = *v10++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_11;
        if ( v12 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_14;
        v13 = v12 - 43;
        if ( v13 == 0 )
        {
          man_sign = 0;
          v8 = 2;
          continue;
        }
        v14 = v13 - 2;
        if ( v14 == 0 )
        {
          v8 = 2;
          man_sign = 0x8000;
          continue;
        }
        if ( v14 != 3 )
          goto LABEL_74;
        goto LABEL_19;
      case 1:
        found_digit = 1;
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_11;
        if ( v12 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_24;
        if ( v12 == 43 || v12 == 45 )
          goto LABEL_32;
        if ( v12 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v12 <= 67 || v12 > 69 && (unsigned int)(v12 - 100) > 1 )
          goto LABEL_74;
        v52 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int16)(v12 - 49) <= 8u )
        {
LABEL_11:
          v51 = 3;
LABEL_12:
          v8 = v51;
          --v10;
        }
        else
        {
          if ( v12 == *_Locale->locinfo->lconv->decimal_point )
          {
LABEL_14:
            v52 = 5;
            goto LABEL_15;
          }
          if ( v12 != 48 )
          {
LABEL_36:
            v15 = savedp;
            goto LABEL_81;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        found_digit = 1;
        while ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
        {
          if ( manlen >= 0x19 )
          {
            ++exp_adj;
          }
          else
          {
            v16 = manp;
            ++manlen;
            ++manp;
            *v16 = v12 - 48;
          }
          LOWORD(v12) = *v10++;
        }
        v12 = (unsigned __int16)v12;
        if ( (unsigned __int16)v12 != *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_45;
LABEL_24:
        v52 = 4;
        goto LABEL_15;
      case 4:
        found_digit = 1;
        found_decpoint = 1;
        if ( manlen == 0 )
        {
          while ( (_WORD)v12 == 48 )
          {
            --exp_adj;
            LOWORD(v12) = *v10++;
          }
        }
        while ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
        {
          if ( manlen < 0x19 )
          {
            ++manlen;
            v17 = manp++;
            --exp_adj;
            *v17 = v12 - 48;
          }
          LOWORD(v12) = *v10++;
        }
        v12 = (unsigned __int16)v12;
LABEL_45:
        if ( v12 != 43 && v12 != 45 )
          goto LABEL_28;
LABEL_32:
        --v10;
        v52 = 11;
        goto LABEL_15;
      case 5:
        found_decpoint = 1;
        if ( (unsigned __int16)(v12 - 48) > 9u )
          goto LABEL_36;
        v51 = 4;
        goto LABEL_12;
      case 6:
        savedp = v10 - 2;
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_62;
        v18 = v12 - 43;
        if ( v18 == 0 )
          goto LABEL_69;
        v19 = v18 - 2;
        if ( v19 == 0 )
          goto LABEL_68;
        v20 = v19 == 3;
LABEL_66:
        if ( !v20 )
          goto LABEL_36;
        v52 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_62;
        v20 = (_WORD)v12 == 48;
        goto LABEL_66;
      case 8:
        found_exponent = 1;
        while ( (_WORD)v12 == 48 )
          LOWORD(v12) = *v10++;
        if ( (unsigned __int16)(v12 - 49) > 8u )
          goto LABEL_74;
LABEL_62:
        v51 = 9;
        goto LABEL_12;
      case 9:
        found_exponent = 1;
        v23 = 0;
        while ( 2 )
        {
          if ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
          {
            v23 = 10 * v23 + (unsigned __int16)v12 - 48;
            if ( v23 <= 5200 )
            {
              LOWORD(v12) = *v10++;
              continue;
            }
            v23 = 5201;
          }
          break;
        }
        pow = v23;
        while ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
          LOWORD(v12) = *v10++;
LABEL_74:
        v15 = v10 - 1;
        goto LABEL_81;
      case 11:
        if ( implicit_E != 0 )
        {
          v21 = v12 - 43;
          savedp = v10 - 1;
          if ( v21 != 0 )
          {
            if ( v21 != 2 )
            {
              v15 = v10 - 1;
              goto LABEL_81;
            }
LABEL_68:
            exp_sign = -1;
            v8 = 7;
          }
          else
          {
LABEL_69:
            v52 = 7;
LABEL_15:
            v8 = v52;
          }
          continue;
        }
        v15 = v10 - 1;
LABEL_81:
        *p_end_ptr = v15;
        if ( found_digit == 0 )
        {
          result_flags = 4;
LABEL_177:
          v47 = 0;
          v50 = 0;
          v49 = 0;
          v48 = 0;
          goto LABEL_178;
        }
        if ( manlen <= 0x18 )
        {
          v22 = manp;
        }
        else
        {
          if ( buf[23] >= 5 )
            ++buf[23];
          manlen = 24;
          v22 = manp - 1;
          ++exp_adj;
        }
        if ( manlen == 0 )
          goto LABEL_177;
        while ( *--v22 == 0 )
        {
          --manlen;
          ++exp_adj;
        }
        __mtold12(manptr: buf, manlen, ld12: &tmpld12);
        v24 = pow;
        if ( exp_sign < 0 )
          v24 = -pow;
        v25 = exp_adj + v24;
        if ( found_exponent == 0 )
          v25 += scale;
        if ( found_decpoint == 0 )
          v25 -= decpt;
        if ( v25 > 5200 )
        {
          v48 = 0;
          v50 = 0x7FFF;
          v49 = 0x80000000;
          v47 = 0;
          result_flags = 2;
          goto LABEL_178;
        }
        if ( v25 < -5200 )
        {
          result_flags = 1;
          goto LABEL_177;
        }
        v26 = &_pow10pos[-8];
        savedpa = v25;
        if ( v25 != 0 )
        {
          if ( v25 < 0 )
          {
            savedpa = -v25;
            v26 = &_pow10neg[-8];
          }
          if ( mult12 == 0 )
            *(_WORD *)tmpld12.ld12 = 0;
          if ( savedpa != 0 )
          {
            while ( 1 )
            {
              v27 = savedpa;
              savedpa >>= 3;
              v28 = v26 + 7;
              v29 = v27 & 7;
              v53 = v28;
              if ( v29 == 0 )
                goto LABEL_172;
              v30 = &v28[v29];
              if ( *(_WORD *)v30->ld12 >= 0x8000u )
              {
                v74 = *(_QWORD *)v30->ld12;
                v75 = *(_DWORD *)&v30->ld12[8];
                --*(_DWORD *)((char *)&v74 + 2);
                v30 = (_LDBL12 *)&v74;
              }
              manpa = nullptr;
              memset(v77, 0, sizeof(v77));
              v31 = *(_WORD *)&v30->ld12[10] & 0x7FFF;
              v32 = (*(_WORD *)&tmpld12.ld12[10] ^ *(_WORD *)&v30->ld12[10]) & 0x8000;
              manlena = v32;
              v33 = v31 + (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF);
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) == 0x7FFF
                || (*(_WORD *)&v30->ld12[10] & 0x7FFF) == 0x7FFF
                || v33 > 0xBFFDu )
              {
                break;
              }
              if ( v33 <= 0x3FBFu )
              {
                v34 = 0;
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                *(_DWORD *)tmpld12.ld12 = 0;
LABEL_171:
                *(_DWORD *)&tmpld12.ld12[8] = v34;
                goto LABEL_172;
              }
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) != 0
                || (++v33, (*(_DWORD *)&tmpld12.ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&tmpld12.ld12[4] != 0
                || *(_DWORD *)tmpld12.ld12 != 0 )
              {
                if ( v31 != 0
                  || (++v33, (*(_DWORD *)&v30->ld12[8] & 0x7FFFFFFF) != 0)
                  || *(_DWORD *)&v30->ld12[4] != 0
                  || *(_DWORD *)v30->ld12 != 0 )
                {
                  exp_signa = 0;
                  v35 = &v77[4];
                  for ( found_digita = 5; found_digita > 0; --found_digita )
                  {
                    powa = found_digita;
                    found_decpointa = &tmpld12.ld12[2 * exp_signa];
                    found_exponenta = &v30->ld12[8];
                    do
                    {
                      exp_adja = 0;
                      v36 = *(unsigned __int16 *)found_exponenta * *(unsigned __int16 *)found_decpointa;
                      v37 = *((_DWORD *)v35 - 1);
                      v38 = v37 + v36;
                      if ( v37 + v36 < v37 || v38 < v36 )
                        exp_adja = 1;
                      *((_DWORD *)v35 - 1) = v38;
                      if ( exp_adja != 0 )
                        ++*v35;
                      found_decpointa += 2;
                      found_exponenta -= 2;
                      --powa;
                    }
                    while ( powa > 0 );
                    ++v35;
                    ++exp_signa;
                  }
                  v39 = v33 - 16382;
                  if ( v39 <= 0 )
                    goto LABEL_181;
                  do
                  {
                    if ( *(int *)&v77[8] < 0 )
                      break;
                    v40 = *(_DWORD *)v77;
                    *(_DWORD *)v77 *= 2;
                    v41 = (v40 >> 31) | (2 * *(_DWORD *)&v77[4]);
                    v42 = *(__int64 *)&v77[4] >> 31;
                    --v39;
                    *(_DWORD *)&v77[4] = v41;
                    *(_DWORD *)&v77[8] = v42;
                  }
                  while ( v39 > 0 );
                  if ( v39 <= 0 )
                  {
LABEL_181:
                    if ( --v39 < 0 )
                    {
                      v43 = (unsigned __int16)-v39;
                      v39 = 0;
                      do
                      {
                        if ( (v77[0] & 1) != 0 )
                          ++manpa;
                        v44 = *(_DWORD *)&v77[8];
                        *(_DWORD *)&v77[8] >>= 1;
                        v45 = (v44 << 31) | (*(_DWORD *)&v77[4] >> 1);
                        v46 = *(__int64 *)v77 >> 1;
                        --v43;
                        *(_DWORD *)&v77[4] = v45;
                        *(_DWORD *)v77 = v46;
                      }
                      while ( v43 != 0 );
                      if ( manpa != nullptr )
                        *(_WORD *)v77 |= 1u;
                    }
                  }
                  if ( *(_WORD *)v77 > 0x8000u || (*(_DWORD *)v77 & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)&v77[2] == -1 )
                    {
                      *(_DWORD *)&v77[2] = 0;
                      if ( *(_DWORD *)&v77[6] == -1 )
                      {
                        *(_DWORD *)&v77[6] = 0;
                        if ( *(_WORD *)&v77[10] == 0xFFFF )
                        {
                          *(_WORD *)&v77[10] = 0x8000;
                          ++v39;
                        }
                        else
                        {
                          ++*(_WORD *)&v77[10];
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)&v77[6];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v77[2];
                    }
                  }
                  if ( (unsigned __int16)v39 < 0x7FFFu )
                  {
                    *(_WORD *)tmpld12.ld12 = *(_WORD *)&v77[2];
                    *(_DWORD *)&tmpld12.ld12[2] = *(_DWORD *)&v77[4];
                    *(_DWORD *)&tmpld12.ld12[6] = *(_DWORD *)&v77[8];
                    *(_WORD *)&tmpld12.ld12[10] = manlena | v39;
                  }
                  else
                  {
                    *(_DWORD *)&tmpld12.ld12[4] = 0;
                    *(_DWORD *)tmpld12.ld12 = 0;
                    *(_DWORD *)&tmpld12.ld12[8] = manlena == 0 ? 2147450880 : -32768;
                  }
                }
                else
                {
                  memset(&tmpld12, 0, sizeof(tmpld12));
                }
              }
              else
              {
                *(_WORD *)&tmpld12.ld12[10] = 0;
              }
LABEL_172:
              if ( savedpa == 0 )
                goto LABEL_173;
              v26 = v53;
            }
            *(_DWORD *)&tmpld12.ld12[4] = 0;
            v34 = v32 == 0 ? 2147450880 : -32768;
            *(_DWORD *)tmpld12.ld12 = 0;
            goto LABEL_171;
          }
        }
LABEL_173:
        v47 = *(_WORD *)tmpld12.ld12;
        v48 = *(_DWORD *)&tmpld12.ld12[2];
        v49 = *(_DWORD *)&tmpld12.ld12[6];
        v50 = *(_WORD *)&tmpld12.ld12[10];
LABEL_178:
        *(_DWORD *)&pld12->ld12[2] = v48;
        *(_WORD *)&pld12->ld12[10] = man_sign | v50;
        *(_WORD *)pld12->ld12 = v47;
        *(_DWORD *)&pld12->ld12[6] = v49;
        return result_flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F63B
// Name: ___strgtold12_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __strgtold12_l(
        _LDBL12 *pld12,
        const char **p_end_ptr,
        const char *str,
        int mult12,
        int scale,
        int decpt,
        int implicit_E,
        localeinfo_struct *_Locale)
{
  int v8; // ecx
  char *v9; // edi
  const char *v11; // edx
  char v12; // al
  char v13; // al
  int v14; // eax
  int v15; // eax
  const char *v16; // edx
  int v17; // eax
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  _LDBL12 *v24; // ecx
  char v25; // al
  _LDBL12 *v26; // ecx
  int v27; // eax
  _LDBL12 *v28; // ebx
  __int16 v29; // ax
  __int16 v30; // si
  unsigned __int16 v31; // cx
  int v32; // eax
  _WORD *v33; // edi
  unsigned int v34; // eax
  unsigned int v35; // edx
  unsigned int v36; // esi
  __int16 v37; // cx
  unsigned int v38; // eax
  int v39; // esi
  int v40; // eax
  int v41; // esi
  int v42; // eax
  int v43; // edi
  int v44; // eax
  __int16 v45; // cx
  int v46; // esi
  unsigned int v47; // edx
  __int16 v48; // ax
  int v49; // [esp-8h] [ebp-8Ch]
  int v50; // [esp-8h] [ebp-8Ch]
  _LDBL12 *v51; // [esp+8h] [ebp-7Ch]
  __int16 man_sign; // [esp+10h] [ebp-74h]
  __int16 v53; // [esp+14h] [ebp-70h]
  unsigned int result_flags; // [esp+18h] [ebp-6Ch]
  int exp_sign; // [esp+1Ch] [ebp-68h]
  int exp_signa; // [esp+1Ch] [ebp-68h]
  int pow; // [esp+20h] [ebp-64h]
  int powa; // [esp+20h] [ebp-64h]
  int found_exponent; // [esp+24h] [ebp-60h]
  unsigned __int8 *found_exponenta; // [esp+24h] [ebp-60h]
  int found_decpoint; // [esp+28h] [ebp-5Ch]
  unsigned __int8 *found_decpointa; // [esp+28h] [ebp-5Ch]
  int found_digit; // [esp+2Ch] [ebp-58h]
  int found_digita; // [esp+2Ch] [ebp-58h]
  const char *savedp; // [esp+30h] [ebp-54h]
  int savedpa; // [esp+30h] [ebp-54h]
  int exp_adj; // [esp+34h] [ebp-50h]
  int exp_adja; // [esp+34h] [ebp-50h]
  unsigned int manlen; // [esp+38h] [ebp-4Ch]
  unsigned int manlena; // [esp+38h] [ebp-4Ch]
  __int64 v71; // [esp+3Ch] [ebp-48h] BYREF
  int v72; // [esp+44h] [ebp-40h]
  _LDBL12 tmpld12; // [esp+48h] [ebp-3Ch] BYREF
  _BYTE v74[12]; // [esp+58h] [ebp-2Ch] BYREF
  char buf[28]; // [esp+64h] [ebp-20h] BYREF

  v8 = 0;
  v9 = buf;
  man_sign = 0;
  exp_sign = 1;
  manlen = 0;
  found_digit = 0;
  found_decpoint = 0;
  found_exponent = 0;
  pow = 0;
  exp_adj = 0;
  result_flags = 0;
  if ( _Locale == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v11 = str;
  savedp = str;
  while ( 1 )
  {
    v12 = *v11;
    if ( *v11 != 32 && v12 != 9 && v12 != 10 && v12 != 13 )
      break;
    ++v11;
  }
  while ( 2 )
  {
    v13 = *v11++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_14;
        v14 = v13 - 43;
        if ( v14 == 0 )
        {
          man_sign = 0;
          v8 = 2;
          continue;
        }
        v15 = v14 - 2;
        if ( v15 == 0 )
        {
          v8 = 2;
          man_sign = 0x8000;
          continue;
        }
        if ( v15 != 3 )
          goto LABEL_74;
        goto LABEL_19;
      case 1:
        found_digit = 1;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_24;
        if ( v13 == 43 || v13 == 45 )
          goto LABEL_32;
        if ( v13 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v13 <= 67 || v13 > 69 && (unsigned __int8)(v13 - 100) > 1u )
          goto LABEL_74;
        v50 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
        {
LABEL_11:
          v49 = 3;
LABEL_12:
          v8 = v49;
          --v11;
        }
        else
        {
          if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          {
LABEL_14:
            v50 = 5;
            goto LABEL_15;
          }
          if ( v13 != 48 )
          {
LABEL_36:
            v16 = savedp;
            goto LABEL_81;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        found_digit = 1;
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen >= 0x19 )
          {
            ++exp_adj;
          }
          else
          {
            ++manlen;
            *v9++ = v13 - 48;
          }
          v13 = *v11++;
        }
        if ( v13 != *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_45;
LABEL_24:
        v50 = 4;
        goto LABEL_15;
      case 4:
        found_digit = 1;
        found_decpoint = 1;
        if ( manlen == 0 )
        {
          while ( v13 == 48 )
          {
            --exp_adj;
            v13 = *v11++;
          }
        }
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen < 0x19 )
          {
            ++manlen;
            *v9++ = v13 - 48;
            --exp_adj;
          }
          v13 = *v11++;
        }
LABEL_45:
        if ( v13 != 43 && v13 != 45 )
          goto LABEL_28;
LABEL_32:
        --v11;
        v50 = 11;
        goto LABEL_15;
      case 5:
        found_decpoint = 1;
        if ( (unsigned __int8)(v13 - 48) > 9u )
          goto LABEL_36;
        v49 = 4;
        goto LABEL_12;
      case 6:
        savedp = v11 - 2;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_62;
        v17 = v13 - 43;
        if ( v17 == 0 )
          goto LABEL_69;
        v18 = v17 - 2;
        if ( v18 == 0 )
          goto LABEL_68;
        v19 = v18 == 3;
LABEL_66:
        if ( !v19 )
          goto LABEL_36;
        v50 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_62;
        v19 = v13 == 48;
        goto LABEL_66;
      case 8:
        found_exponent = 1;
        while ( v13 == 48 )
          v13 = *v11++;
        if ( (unsigned __int8)(v13 - 49) > 8u )
          goto LABEL_74;
LABEL_62:
        v49 = 9;
        goto LABEL_12;
      case 9:
        found_exponent = 1;
        v21 = 0;
        while ( 2 )
        {
          if ( v13 >= 48 && v13 <= 57 )
          {
            v21 = 10 * v21 + v13 - 48;
            if ( v21 <= 5200 )
            {
              v13 = *v11++;
              continue;
            }
            v21 = 5201;
          }
          break;
        }
        pow = v21;
        while ( v13 >= 48 && v13 <= 57 )
          v13 = *v11++;
LABEL_74:
        v16 = v11 - 1;
        goto LABEL_81;
      case 11:
        if ( implicit_E != 0 )
        {
          v20 = v13 - 43;
          savedp = v11 - 1;
          if ( v20 != 0 )
          {
            if ( v20 != 2 )
            {
              v16 = v11 - 1;
              goto LABEL_81;
            }
LABEL_68:
            exp_sign = -1;
            v8 = 7;
          }
          else
          {
LABEL_69:
            v50 = 7;
LABEL_15:
            v8 = v50;
          }
          continue;
        }
        v16 = v11 - 1;
LABEL_81:
        *p_end_ptr = v16;
        if ( found_digit == 0 )
        {
          result_flags = 4;
LABEL_176:
          v45 = 0;
          v48 = 0;
          v47 = 0;
          v46 = 0;
          goto LABEL_177;
        }
        if ( manlen > 0x18 )
        {
          if ( buf[23] >= 5 )
            ++buf[23];
          --v9;
          ++exp_adj;
          manlen = 24;
        }
        if ( manlen == 0 )
          goto LABEL_176;
        while ( *--v9 == 0 )
        {
          --manlen;
          ++exp_adj;
        }
        __mtold12(manptr: buf, manlen, ld12: &tmpld12);
        v22 = pow;
        if ( exp_sign < 0 )
          v22 = -pow;
        v23 = exp_adj + v22;
        if ( found_exponent == 0 )
          v23 += scale;
        if ( found_decpoint == 0 )
          v23 -= decpt;
        if ( v23 > 5200 )
        {
          v46 = 0;
          v48 = 0x7FFF;
          v47 = 0x80000000;
          v45 = 0;
          result_flags = 2;
          goto LABEL_177;
        }
        if ( v23 < -5200 )
        {
          result_flags = 1;
          goto LABEL_176;
        }
        v24 = &_pow10pos[-8];
        savedpa = v23;
        if ( v23 != 0 )
        {
          if ( v23 < 0 )
          {
            savedpa = -v23;
            v24 = &_pow10neg[-8];
          }
          if ( mult12 == 0 )
            *(_WORD *)tmpld12.ld12 = 0;
          if ( savedpa != 0 )
          {
            while ( 1 )
            {
              v25 = savedpa;
              savedpa >>= 3;
              v26 = v24 + 7;
              v27 = v25 & 7;
              v51 = v26;
              if ( v27 == 0 )
                goto LABEL_171;
              v28 = &v26[v27];
              if ( *(_WORD *)v28->ld12 >= 0x8000u )
              {
                v71 = *(_QWORD *)v28->ld12;
                v72 = *(_DWORD *)&v28->ld12[8];
                --*(_DWORD *)((char *)&v71 + 2);
                v28 = (_LDBL12 *)&v71;
              }
              exp_adja = 0;
              memset(v74, 0, sizeof(v74));
              v29 = *(_WORD *)&v28->ld12[10] & 0x7FFF;
              v30 = (*(_WORD *)&tmpld12.ld12[10] ^ *(_WORD *)&v28->ld12[10]) & 0x8000;
              v53 = v30;
              v31 = v29 + (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF);
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) == 0x7FFF
                || (*(_WORD *)&v28->ld12[10] & 0x7FFF) == 0x7FFF
                || v31 > 0xBFFDu )
              {
                break;
              }
              if ( v31 <= 0x3FBFu )
              {
                v32 = 0;
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                *(_DWORD *)tmpld12.ld12 = 0;
LABEL_170:
                *(_DWORD *)&tmpld12.ld12[8] = v32;
                goto LABEL_171;
              }
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) != 0
                || (++v31, (*(_DWORD *)&tmpld12.ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&tmpld12.ld12[4] != 0
                || *(_DWORD *)tmpld12.ld12 != 0 )
              {
                if ( v29 != 0
                  || (++v31, (*(_DWORD *)&v28->ld12[8] & 0x7FFFFFFF) != 0)
                  || *(_DWORD *)&v28->ld12[4] != 0
                  || *(_DWORD *)v28->ld12 != 0 )
                {
                  exp_signa = 0;
                  v33 = &v74[4];
                  for ( found_digita = 5; found_digita > 0; --found_digita )
                  {
                    powa = found_digita;
                    found_decpointa = &tmpld12.ld12[2 * exp_signa];
                    found_exponenta = &v28->ld12[8];
                    do
                    {
                      manlena = 0;
                      v34 = *(unsigned __int16 *)found_decpointa * *(unsigned __int16 *)found_exponenta;
                      v35 = *((_DWORD *)v33 - 1);
                      v36 = v35 + v34;
                      if ( v35 + v34 < v35 || v36 < v34 )
                        manlena = 1;
                      *((_DWORD *)v33 - 1) = v36;
                      if ( manlena != 0 )
                        ++*v33;
                      found_decpointa += 2;
                      found_exponenta -= 2;
                      --powa;
                    }
                    while ( powa > 0 );
                    ++v33;
                    ++exp_signa;
                  }
                  v37 = v31 - 16382;
                  if ( v37 <= 0 )
                    goto LABEL_180;
                  do
                  {
                    if ( *(int *)&v74[8] < 0 )
                      break;
                    v38 = *(_DWORD *)v74;
                    *(_DWORD *)v74 *= 2;
                    v39 = (v38 >> 31) | (2 * *(_DWORD *)&v74[4]);
                    v40 = *(__int64 *)&v74[4] >> 31;
                    --v37;
                    *(_DWORD *)&v74[4] = v39;
                    *(_DWORD *)&v74[8] = v40;
                  }
                  while ( v37 > 0 );
                  if ( v37 <= 0 )
                  {
LABEL_180:
                    if ( --v37 < 0 )
                    {
                      v41 = (unsigned __int16)-v37;
                      v37 = 0;
                      do
                      {
                        if ( (v74[0] & 1) != 0 )
                          ++exp_adja;
                        v42 = *(_DWORD *)&v74[8];
                        *(_DWORD *)&v74[8] >>= 1;
                        v43 = (v42 << 31) | (*(_DWORD *)&v74[4] >> 1);
                        v44 = *(__int64 *)v74 >> 1;
                        --v41;
                        *(_DWORD *)&v74[4] = v43;
                        *(_DWORD *)v74 = v44;
                      }
                      while ( v41 != 0 );
                      if ( exp_adja != 0 )
                        *(_WORD *)v74 |= 1u;
                    }
                  }
                  if ( *(_WORD *)v74 > 0x8000u || (*(_DWORD *)v74 & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)&v74[2] == -1 )
                    {
                      *(_DWORD *)&v74[2] = 0;
                      if ( *(_DWORD *)&v74[6] == -1 )
                      {
                        *(_DWORD *)&v74[6] = 0;
                        if ( *(_WORD *)&v74[10] == 0xFFFF )
                        {
                          *(_WORD *)&v74[10] = 0x8000;
                          ++v37;
                        }
                        else
                        {
                          ++*(_WORD *)&v74[10];
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)&v74[6];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v74[2];
                    }
                  }
                  if ( (unsigned __int16)v37 < 0x7FFFu )
                  {
                    *(_WORD *)tmpld12.ld12 = *(_WORD *)&v74[2];
                    *(_DWORD *)&tmpld12.ld12[2] = *(_DWORD *)&v74[4];
                    *(_DWORD *)&tmpld12.ld12[6] = *(_DWORD *)&v74[8];
                    *(_WORD *)&tmpld12.ld12[10] = v53 | v37;
                  }
                  else
                  {
                    *(_DWORD *)&tmpld12.ld12[4] = 0;
                    *(_DWORD *)tmpld12.ld12 = 0;
                    *(_DWORD *)&tmpld12.ld12[8] = v53 == 0 ? 2147450880 : -32768;
                  }
                }
                else
                {
                  memset(&tmpld12, 0, sizeof(tmpld12));
                }
              }
              else
              {
                *(_WORD *)&tmpld12.ld12[10] = 0;
              }
LABEL_171:
              if ( savedpa == 0 )
                goto LABEL_172;
              v24 = v51;
            }
            *(_DWORD *)&tmpld12.ld12[4] = 0;
            v32 = v30 == 0 ? 2147450880 : -32768;
            *(_DWORD *)tmpld12.ld12 = 0;
            goto LABEL_170;
          }
        }
LABEL_172:
        v45 = *(_WORD *)tmpld12.ld12;
        v46 = *(_DWORD *)&tmpld12.ld12[2];
        v47 = *(_DWORD *)&tmpld12.ld12[6];
        v48 = *(_WORD *)&tmpld12.ld12[10];
LABEL_177:
        *(_WORD *)pld12->ld12 = v45;
        *(_WORD *)&pld12->ld12[10] = man_sign | v48;
        *(_DWORD *)&pld12->ld12[2] = v46;
        *(_DWORD *)&pld12->ld12[6] = v47;
        return result_flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FD17
// Name: __atodbl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atodbl_l(_CRT_DOUBLE *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  const char *EndPtr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-24h] BYREF
  unsigned int retval1; // [esp+20h] [ebp-14h]
  _LDBL12 ld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  retval1 = __strgtold12_l(
              pld12: &ld12,
              p_end_ptr: &EndPtr,
              str,
              mult12: 0,
              scale: 0,
              decpt: 0,
              implicit_E: 0,
              _Locale: &_loc_update.localeinfo);
  v3 = _ld12tod(pld12: &ld12, d);
  if ( (retval1 & 3) != 0 )
  {
    if ( (retval1 & 1) != 0 )
      goto LABEL_8;
    if ( (retval1 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046FDBF
// Name: __atoflt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atoflt_l(_CRT_FLOAT *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  const char *EndPtr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-24h] BYREF
  unsigned int retval1; // [esp+20h] [ebp-14h]
  _LDBL12 ld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  retval1 = __strgtold12_l(
              pld12: &ld12,
              p_end_ptr: &EndPtr,
              str,
              mult12: 0,
              scale: 0,
              decpt: 0,
              implicit_E: 0,
              _Locale: &_loc_update.localeinfo);
  v3 = _ld12tof(pld12: &ld12, f: d);
  if ( (retval1 & 3) != 0 )
  {
    if ( (retval1 & 1) != 0 )
      goto LABEL_8;
    if ( (retval1 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046FE67
// Name: __fptostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fptostr(char *buf, unsigned int sizeInBytes, int digits, _strflt *pflt)
{
  _strflt *v4; // ecx
  char *mantissa; // ebx
  int v6; // eax
  int v7; // esi
  int v9; // edx
  char *v10; // eax
  char v11; // cl
  int v12; // eax

  v4 = pflt;
  mantissa = pflt->mantissa;
  v6 = 0;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v7 = 22;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter_noinfo();
    return v7;
  }
  v9 = digits;
  *buf = 0;
  if ( digits > 0 )
    v6 = digits;
  if ( sizeInBytes <= v6 + 1 )
  {
    *_errno() = 34;
    v7 = 34;
    goto LABEL_3;
  }
  *buf = 48;
  v10 = buf + 1;
  if ( digits > 0 )
  {
    do
    {
      v11 = *mantissa;
      if ( *mantissa != 0 )
        ++mantissa;
      else
        v11 = 48;
      *v10++ = v11;
      --v9;
    }
    while ( v9 > 0 );
    v4 = pflt;
  }
  *v10 = 0;
  if ( v9 >= 0 && *mantissa >= 53 )
  {
    while ( *--v10 == 57 )
      *v10 = 48;
    ++*v10;
  }
  if ( *buf == 49 )
  {
    ++v4->decpt;
  }
  else
  {
    strlen(buf: buf + 1);
    memmove(dst: (unsigned __int8 *)buf, src: (unsigned __int8 *)buf + 1, count: v12 + 1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046FF1A
// Name: ___dtold
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __dtold(_LDOUBLE *pld, long double *px)
{
  int v3; // ebx
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  __int16 v7; // bx
  __int16 v8; // di
  _LDOUBLE *v9; // eax
  __int16 v10; // cx
  int v11; // edx
  int v12; // ecx
  unsigned int msb; // [esp+Ch] [ebp-4h]
  __int16 sign; // [esp+1Ch] [ebp+Ch]

  v3 = (*((unsigned __int16 *)px + 3) >> 4) & 0x7FF;
  sign = *((_WORD *)px + 3) & 0x8000;
  v4 = *((_DWORD *)px + 1);
  v5 = *(_DWORD *)px;
  v6 = v4 & 0xFFFFF;
  msb = 0x80000000;
  if ( (_WORD)v3 != 0 )
  {
    if ( (unsigned __int16)v3 == 2047 )
    {
      v8 = 0x7FFF;
      goto LABEL_10;
    }
    v7 = v3 + 15360;
  }
  else
  {
    if ( v6 == 0 && v5 == 0 )
    {
      v9 = pld;
      v10 = sign;
      *(_DWORD *)&pld->ld[4] = 0;
      *(_DWORD *)pld->ld = 0;
      goto LABEL_14;
    }
    v7 = 15361;
    msb = 0;
  }
  v8 = v7;
LABEL_10:
  v11 = msb | (v6 << 11) | (v5 >> 21);
  v9 = pld;
  v12 = v5 << 11;
  while ( 1 )
  {
    *(_DWORD *)pld->ld = v12;
    *(_DWORD *)&pld->ld[4] = v11;
    if ( v11 < 0 )
      break;
    v11 = (*(_DWORD *)pld->ld >> 31) | (2 * v11);
    v12 = 2 * *(_DWORD *)pld->ld;
    --v8;
  }
  v10 = v8 | sign;
LABEL_14:
  *(_WORD *)&v9->ld[8] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x0046FFCD
// Name: __fltout2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_strflt *__cdecl _fltout2(_CRT_DOUBLE x, _strflt *flt, char *resultstr, unsigned int resultsize)
{
  _strflt *v4; // ebx
  int v5; // eax
  char *v6; // esi
  _LDOUBLE ld; // [esp+Ch] [ebp-30h] BYREF
  char *_Dst; // [esp+18h] [ebp-24h]
  _FloatOutStruct autofos; // [esp+1Ch] [ebp-20h] BYREF

  v4 = flt;
  _Dst = resultstr;
  __dtold(pld: &ld, px: &x.x);
  v5 = _I10_OUTPUT(ld, ndigits: 17, output_flags: 0, fos: &autofos);
  v6 = _Dst;
  v4->flag = v5;
  v4->sign = autofos.sign;
  v4->decpt = autofos.exp;
  if ( strcpy_s(_Dst: v6, _SizeInBytes: resultsize, _Src: autofos.man) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  v4->mantissa = v6;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00470060
// Name: __alldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldvrm(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  int v5; // esi
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax
  int result; // eax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v5 = v7 / (unsigned int)v6;
    v8 = (unsigned int)v5 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v5, HIDWORD(v8))
      || (HIDWORD(v8) = (a2 * (unsigned __int64)(unsigned int)v5) >> 32, v8 > a1) )
    {
      --v5;
    }
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    v5 = v4 / (unsigned int)a2;
  }
  result = v5;
  if ( v2 == 1 )
    return -v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047013F
// Name: __fptrap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn _fptrap()
{
  _amsg_exit(rterrnum: 2);
}

//------------------------------------------------------------------------------
// Address: 0x00470148
// Name: __controlfp_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _controlfp_s(unsigned int *_CurrentState, unsigned int newctrl, unsigned int mask)
{
  unsigned int v4; // [esp-4h] [ebp-8h]

  if ( (mask & 0xFFF7FFFF & newctrl & 0xFCF0FCE0) != 0 )
  {
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl: 0, mask: 0);
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  else
  {
    v4 = mask & 0xFFF7FFFF;
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl, mask: v4);
    else
      _control87(newctrl, mask: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004701A7
// Name: __ungetc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ungetc_nolock(int ch, _iobuf *str)
{
  int v2; // eax
  ioinfo *v3; // ecx
  ioinfo *v4; // eax
  int flag; // eax
  char *v7; // eax
  int v8; // eax

  if ( (str->_flag & 0x40) == 0 )
  {
    v2 = fileno(stream: str);
    if ( v2 == -1 || v2 == -2 )
      v3 = &__badioinfo;
    else
      v3 = &__pioinfo[v2 >> 5][v2 & 0x1F];
    if ( (*((_BYTE *)v3 + 36) & 0x7F) != 0
      || (v2 == -1 || v2 == -2 ? (v4 = &__badioinfo) : (v4 = &__pioinfo[v2 >> 5][v2 & 0x1F]), *((char *)v4 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( ch == -1 )
    return -1;
  flag = str->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( str->_base == nullptr )
    _getbuf(str);
  if ( str->_ptr == str->_base )
  {
    if ( str->_cnt != 0 )
      return -1;
    ++str->_ptr;
  }
  v7 = --str->_ptr;
  if ( (str->_flag & 0x40) != 0 )
  {
    if ( *v7 != (_BYTE)ch )
    {
      str->_ptr = v7 + 1;
      return -1;
    }
  }
  else
  {
    *v7 = ch;
  }
  v8 = str->_flag;
  ++str->_cnt;
  str->_flag = v8 & 0xFFFFFFEE | 1;
  return (unsigned __int8)ch;
}

//------------------------------------------------------------------------------
// Address: 0x0047028A
// Name: _ungetc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ungetc(int ch, _iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ungetc_nolock(ch, str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004702F3
// Name: __mbtowc_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbtowc_l(wchar_t *pwc, const char *s, signed int n, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // eax
  int mb_cur_max; // ecx
  bool v7; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  if ( s == nullptr || n == 0 )
    return 0;
  if ( *s == 0 )
  {
    if ( pwc != nullptr )
      *pwc = 0;
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( pwc != nullptr )
      *pwc = *(unsigned __int8 *)s;
    goto LABEL_11;
  }
  if ( _isleadbyte_l(c: *s, plocinfo: &_loc_update.localeinfo) != 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    mb_cur_max = _loc_update.localeinfo.locinfo->mb_cur_max;
    if ( mb_cur_max > 1
      && n >= mb_cur_max
      && (v7 = MultiByteToWideChar(
                 CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
                 dwFlags: 9u,
                 lpMultiByteStr: s,
                 cbMultiByte: mb_cur_max,
                 lpWideCharStr: pwc,
                 cchWideChar: pwc != nullptr) == 0,
          locinfo = _loc_update.localeinfo.locinfo,
          !v7)
      || (unsigned int)n >= locinfo->mb_cur_max && s[1] != 0 )
    {
      result = locinfo->mb_cur_max;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  else if ( MultiByteToWideChar(
              CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
              dwFlags: 9u,
              lpMultiByteStr: s,
              cbMultiByte: 1,
              lpWideCharStr: pwc,
              cchWideChar: pwc != nullptr) != 0 )
  {
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 1;
  }
  *_errno() = 42;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00470409
// Name: _mbtowc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl mbtowc(wchar_t *pwc, const char *s, unsigned int n)
{
  return _mbtowc_l(pwc, s, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00470423
// Name: __getbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _getbuf(_iobuf *str)
{
  char *v1; // eax
  char *base; // eax

  ++_cflush;
  v1 = (char *)operator new(nSize: 0x1000u);
  str->_base = v1;
  if ( v1 != nullptr )
  {
    str->_flag |= 8u;
    str->_bufsiz = 4096;
  }
  else
  {
    str->_flag |= 4u;
    str->_base = (char *)&str->_charbuf;
    str->_bufsiz = 2;
  }
  base = str->_base;
  str->_cnt = 0;
  str->_ptr = base;
}

//------------------------------------------------------------------------------
// Address: 0x0047046C
// Name: __isatty
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isatty(int fh)
{
  if ( fh == -2 )
  {
    *_errno() = 9;
    return 0;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return 0;
  }
  return __pioinfo[fh >> 5][fh & 0x1F].osfile & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x004704C2
// Name: __wctomb_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wctomb_s_l(
        int *pRetValue,
        char *dst,
        unsigned int sizeInBytes,
        wchar_t wchar,
        localeinfo_struct *plocinfo)
{
  unsigned __int8 *v5; // esi
  unsigned int v6; // edi
  int result; // eax
  int v8; // esi
  int v9; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v5 = (unsigned __int8 *)dst;
  v6 = sizeInBytes;
  if ( dst == nullptr && sizeInBytes != 0 )
  {
    if ( pRetValue != nullptr )
      *pRetValue = 0;
    return 0;
  }
  if ( pRetValue != nullptr )
    *pRetValue = -1;
  if ( v6 > 0x7FFFFFFF )
  {
    v8 = 22;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return v8;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( wchar > 0xFFu )
    {
      if ( v5 != nullptr && v6 != 0 )
        memset(dst: v5, value: 0, count: v6);
      goto LABEL_16;
    }
    if ( v5 != nullptr )
    {
      if ( v6 == 0 )
      {
LABEL_21:
        v8 = 34;
        *_errno() = 34;
        _invalid_parameter_noinfo();
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return v8;
      }
      *v5 = wchar;
    }
    if ( pRetValue != nullptr )
      *pRetValue = 1;
LABEL_26:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  dst = nullptr;
  v9 = WideCharToMultiByte(
         CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
         dwFlags: 0,
         lpWideCharStr: &wchar,
         cchWideChar: 1,
         lpMultiByteStr: (LPSTR)v5,
         cbMultiByte: v6,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: (LPBOOL)&dst);
  if ( v9 != 0 )
  {
    if ( dst == nullptr )
    {
      if ( pRetValue != nullptr )
        *pRetValue = v9;
      goto LABEL_26;
    }
  }
  else if ( GetLastError() == 122 )
  {
    if ( v5 != nullptr && v6 != 0 )
      memset(dst: v5, value: 0, count: v6);
    goto LABEL_21;
  }
LABEL_16:
  *_errno() = 42;
  result = *_errno();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470617
// Name: _wctomb_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wctomb_s(int *pRetValue, char *dst, unsigned int sizeInBytes, wchar_t wchar)
{
  return _wctomb_s_l(pRetValue, dst, sizeInBytes, wchar, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00470634
// Name: __chsize_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chsize_nolock(int filedes, __int64 size)
{
  doubleint v2; // rax
  int v3; // edi
  unsigned int v4; // esi
  HANDLE ProcessHeap; // eax
  unsigned int v7; // eax
  int v8; // eax
  bool v9; // of
  unsigned int v10; // kr08_4
  int v11; // esi
  HANDLE v12; // eax
  doubleint v13; // rax
  void *osfhandle; // eax
  unsigned int *v15; // esi
  doubleint v16; // rax
  __int64 place; // [esp+Ch] [ebp-18h]
  __int64 retval; // [esp+14h] [ebp-10h]
  int oldmode; // [esp+1Ch] [ebp-8h]
  char *v20; // [esp+20h] [ebp-4h]

  HIDWORD(retval) = 0;
  place = _lseeki64_nolock(fh: filedes, pos: 0, mthd: 1u).bigint;
  if ( (HIDWORD(place) & (unsigned int)place) == 0xFFFFFFFF )
    return *_errno();
  v2.bigint = _lseeki64_nolock(fh: filedes, pos: 0, mthd: 2u).bigint;
  if ( (v2.twoints.upperhalf & v2.twoints.lowerhalf) == -1 )
    return *_errno();
  v3 = (unsigned __int64)(size - v2.bigint) >> 32;
  v4 = size - v2.twoints.lowerhalf;
  if ( v3 >= 0 && (size >= v2.bigint && (unsigned __int64)(size - v2.bigint) >> 32 != 0 || v4 != 0) )
  {
    ProcessHeap = GetProcessHeap();
    v20 = (char *)HeapAlloc(hHeap: ProcessHeap, dwFlags: 8u, dwBytes: 0x1000u);
    if ( v20 == nullptr )
    {
      *_errno() = 12;
      return *_errno();
    }
    oldmode = _setmode_nolock(fh: filedes, mode: 0x8000);
    while ( 1 )
    {
      v7 = v3 < 0 || v3 <= 0 && v4 < 0x1000 ? v4 : 4096;
      v8 = _write_nolock(a1: (CUtlCharConversion_vtbl *)0x1000, fh: filedes, buf: v20, cnt: v7);
      if ( v8 == -1 )
        break;
      v9 = __OFSUB__(__PAIR64__(v3, v4), v8);
      v10 = v4 - v8;
      v3 = (__PAIR64__(v3, v4) - v8) >> 32;
      v4 -= v8;
      if ( v3 < 0 || (v3 < 0) ^ v9 | (v3 == 0) && v10 == 0 )
      {
        v11 = 0;
        goto LABEL_20;
      }
    }
    if ( *__doserrno() == 5 )
      *_errno() = 13;
    v11 = -1;
    HIDWORD(retval) = -1;
LABEL_20:
    _setmode_nolock(fh: filedes, mode: oldmode);
    v12 = GetProcessHeap();
    HeapFree(hHeap: v12, dwFlags: 0, lpMem: v20);
    goto LABEL_28;
  }
  if ( v3 < 0 )
  {
    v13.bigint = _lseeki64_nolock(fh: filedes, pos: size, mthd: 0).bigint;
    if ( (v13.twoints.upperhalf & v13.twoints.lowerhalf) == -1 )
      return *_errno();
    osfhandle = (void *)_get_osfhandle(fh: filedes);
    retval = SetEndOfFile(hFile: osfhandle) - 1;
    if ( (HIDWORD(retval) & (unsigned int)retval) == 0xFFFFFFFF )
    {
      *_errno() = 13;
      v15 = __doserrno();
      *v15 = GetLastError();
      v11 = retval;
LABEL_28:
      if ( (HIDWORD(retval) & v11) == 0xFFFFFFFF )
        return *_errno();
    }
  }
  v16.bigint = _lseeki64_nolock(fh: filedes, pos: place, mthd: 0).bigint;
  if ( (v16.twoints.upperhalf & v16.twoints.lowerhalf) == -1 )
    return *_errno();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004707EA
// Name: __setmode_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmode_nolock(int fh, int mode)
{
  ioinfo **v2; // edx
  int v3; // esi
  char *v4; // ecx
  int v5; // edi
  int v6; // eax
  _BYTE *v7; // ecx
  char v8; // dl

  v2 = &__pioinfo[fh >> 5];
  v3 = (fh & 0x1F) << 6;
  v4 = (char *)*v2 + v3;
  v5 = v4[4] & 0x80;
  v6 = (char)(2 * v4[36]) >> 1;
  if ( mode == 0x4000 )
  {
    v4[4] |= 0x80u;
    *((_BYTE *)*v2 + v3 + 36) &= 0x80u;
  }
  else if ( mode == 0x8000 )
  {
    v4[4] &= ~0x80u;
  }
  else
  {
    if ( mode == 0x10000 || mode == 0x20000 )
    {
      v4[4] |= 0x80u;
      v7 = (char *)*v2 + v3 + 36;
      v8 = *v7 & 0x80 | 2;
    }
    else
    {
      if ( mode != 0x40000 )
        goto LABEL_11;
      v4[4] |= 0x80u;
      v7 = (char *)*v2 + v3 + 36;
      v8 = *v7 & 0x80 | 1;
    }
    *v7 = v8;
  }
LABEL_11:
  if ( v5 != 0 )
    return v6 != 0 ? 0x10000 : 0x4000;
  else
    return 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x004708A5
// Name: __get_fmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_fmode(int *pMode)
{
  if ( pMode != nullptr )
  {
    *pMode = _fmode;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004708D2
// Name: __mbsnbicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicmp_l(
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  const unsigned __int8 *v5; // edi
  int v6; // ecx
  bool v7; // zf
  int v8; // ecx
  unsigned __int16 v9; // si
  unsigned __int8 v10; // dl
  int v11; // ecx
  char *v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  char *v16; // ecx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  int c1; // [esp+14h] [ebp-8h]
  int c2; // [esp+18h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( n == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = _strnicmp(dst: (const char *)s1, src: (const char *)s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v5 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  while ( 1 )
  {
    v6 = *s1;
    --n;
    ++s1;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) == 0;
    c1 = v6;
    if ( v7 )
    {
      v12 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v12[29] & 0x10) != 0 )
        v13 = (unsigned __int8)v12[285];
      else
        v13 = (unsigned __int16)c1;
      c1 = v13;
      goto LABEL_32;
    }
    if ( n == 0 )
    {
      v8 = *v5;
      v7 = (_loc_update.localeinfo.mbcinfo->mbctype[v8 + 1] & 4) == 0;
      c1 = 0;
      if ( !v7 )
        goto LABEL_51;
      v9 = 0;
      goto LABEL_46;
    }
    if ( *s1 == 0 )
    {
      c1 = 0;
LABEL_32:
      v9 = c1;
      goto LABEL_33;
    }
    v10 = *s1++;
    v11 = (unsigned __int16)(v10 | (unsigned __int16)((_WORD)v6 << 8));
    v9 = v11;
    c1 = v11;
    if ( (unsigned __int16)v11 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v11 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v11 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v11 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v11;
      }
    }
    else
    {
      v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v11;
    }
LABEL_33:
    v14 = *v5++;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v14 + 1] & 4) == 0;
    c2 = v14;
    if ( v7 )
    {
      v16 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c2;
      if ( (v16[29] & 0x10) != 0 )
        v8 = (unsigned __int8)v16[285];
      else
        v8 = (unsigned __int16)c2;
LABEL_46:
      c2 = v8;
      goto LABEL_47;
    }
    if ( n == 0 || (--n, *v5 == 0) )
    {
      c2 = 0;
LABEL_47:
      LOWORD(v15) = c2;
      goto test;
    }
    v15 = (unsigned __int16)(*v5++ | (unsigned __int16)((_WORD)v14 << 8));
    c2 = v15;
    if ( (unsigned __int16)v15 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v15 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v15 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v15 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        LOWORD(v15) = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v15;
      }
    }
    else
    {
      LOWORD(v15) = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v15;
    }
test:
    if ( (_WORD)v15 != v9 )
      break;
    if ( v9 == 0 || n == 0 )
    {
LABEL_51:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
  }
  result = (unsigned __int16)v15 < v9 ? 1 : -1;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470AD6
// Name: __mbsnbicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicmp(const unsigned __int8 *s1, const unsigned __int8 *s2, unsigned int n)
{
  return _mbsnbicmp_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00470AF0
// Name: __mbsnbcmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbcmp_l(
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  const unsigned __int8 *v5; // ebx
  const unsigned __int8 *v6; // esi
  unsigned __int16 v7; // cx
  int v8; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  if ( n == 0 )
    return 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = strncmp(first: (const char *)s1, last: (const char *)s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  v5 = s1;
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v6 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  while ( 1 )
  {
    v7 = *v5;
    --n;
    ++v5;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v7 + 1] & 4) == 0 )
      goto LABEL_24;
    if ( n != 0 )
    {
      if ( *v5 != 0 )
        v7 = *v5++ | (unsigned __int16)(v7 << 8);
      else
        v7 = 0;
LABEL_24:
      LOWORD(v8) = *v6++;
      if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v8 + 1] & 4) != 0 )
      {
        if ( n != 0 && (--n, *v6 != 0) )
          LOWORD(v8) = *v6++ | (unsigned __int16)((_WORD)v8 << 8);
        else
          LOWORD(v8) = 0;
      }
      goto test_0;
    }
    v8 = *v6;
    v7 = 0;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[v8 + 1] & 4) != 0 )
      goto LABEL_17;
test_0:
    if ( (_WORD)v8 != v7 )
      break;
    if ( v7 == 0 || n == 0 )
    {
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
  }
  result = (unsigned __int16)v8 < v7 ? 1 : -1;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470C3C
// Name: __mbsnbcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbcmp(const unsigned __int8 *s1, const unsigned __int8 *s2, unsigned int n)
{
  return _mbsnbcmp_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00470C60
// Name: __global_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _global_unwind2(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &gu_return, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00470C80
// Name: __unwind_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _unwind_handler(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind2(a1: *(_DWORD *)(a5 + 36), a2: *(_DWORD *)(a5 + 40));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470CC5
// Name: __local_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind2(int a1, unsigned int a2)
{
  int result; // eax
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ecx
  int v7; // [esp-4h] [ebp-24h]
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+0h] [ebp-20h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a1;
    v3 = *(_DWORD *)(a1 + 8);
    v4 = *(_DWORD *)(a1 + 12);
    if ( v4 == -1 || a2 != -1 && v4 <= a2 )
      break;
    v5 = 3 * v4;
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v3 + 4 * v5);
    if ( *(_DWORD *)(v3 + 4 * v5 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: v6, a2: v7, a3: ExceptionList);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470D49
// Name: __abnormal_termination
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _abnormal_termination()
{
  int result; // eax
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ecx

  result = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( (int (__cdecl *)(int, int, int, _DWORD *, int))ExceptionList->Handler == _unwind_handler )
    return ExceptionList[1].Next == *((_EXCEPTION_REGISTRATION_RECORD **)ExceptionList[1].Handler + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470D6C
// Name: __NLG_Notify1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _NLG_Notify1(int a1)
{
  JUMPOUT(0x470D80);
}

//------------------------------------------------------------------------------
// Address: 0x00470D75
// Name: __NLG_Notify
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __userpurge _NLG_Notify@<eax>(unsigned int result@<eax>, unsigned int a2@<ebp>, unsigned int a3)
{
  _NLG_Destination.dwCode = a3;
  _NLG_Destination.uoffDestination = result;
  _NLG_Destination.uoffFramePointer = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470D94
// Name: __NLG_Call
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _NLG_Call@<eax>(int (*a1)(void)@<eax>)
{
  return a1();
}

//------------------------------------------------------------------------------
// Address: 0x00470D97
// Name: x_ismbbtype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl x_ismbbtype_l(localeinfo_struct *plocinfo, unsigned __int8 tst, int cmask, unsigned __int8 kmask)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( (kmask & _loc_update.localeinfo.mbcinfo->mbctype[tst + 1]) != 0
    || (cmask == 0 ? (result = 0) : (result = (unsigned __int16)(cmask & _loc_update.localeinfo.locinfo->pctype[tst])),
        result != 0) )
  {
    result = 1;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470DEA
// Name: __ismbblead
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbblead(unsigned __int8 tst)
{
  return x_ismbbtype_l(plocinfo: nullptr, tst, cmask: 0, kmask: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x00470E02
// Name: __crtCompareStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _crtCompareStringA_stat(
        localeinfo_struct *plocinfo,
        const char *lpString2,
        LCID Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        int cchCount2,
        UINT code_page)
{
  const char *v8; // eax
  int v9; // edi
  int v11; // ecx
  int v12; // esi
  int v13; // ecx
  const char *v14; // eax
  unsigned __int8 *LeadByte; // eax
  unsigned __int8 v17; // dl
  unsigned __int8 *i; // eax
  unsigned __int8 v19; // dl
  int v20; // eax
  int v21; // ebx
  unsigned int v22; // eax
  void *v23; // esp
  wchar_t *v24; // eax
  int v25; // eax
  int v26; // ebx
  unsigned int v27; // eax
  void *v28; // esp
  WCHAR *v29; // eax
  WCHAR *v30; // edi
  _DWORD v32[3]; // [esp+0h] [ebp-38h] BYREF
  int buff_size1; // [esp+Ch] [ebp-2Ch]
  int retcode; // [esp+10h] [ebp-28h]
  LPCCH lpMultiByteStr; // [esp+14h] [ebp-24h]
  LPCCH v36; // [esp+18h] [ebp-20h]
  wchar_t *wbuffer1; // [esp+1Ch] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+20h] [ebp-18h] BYREF

  v8 = lpString1;
  v9 = cchCount1;
  lpMultiByteStr = lpString1;
  v36 = lpString2;
  if ( cchCount1 <= 0 )
  {
    if ( cchCount1 < -1 )
      return 0;
  }
  else
  {
    v11 = cchCount1;
    while ( 1 )
    {
      --v11;
      if ( *v8 == 0 )
        break;
      ++v8;
      if ( v11 == 0 )
      {
        v11 = -1;
        break;
      }
    }
    v9 = -1 - v11 + cchCount1;
    cchCount1 = v9;
  }
  v12 = cchCount2;
  if ( cchCount2 <= 0 )
  {
    if ( cchCount2 < -1 )
      return 0;
  }
  else
  {
    v13 = cchCount2;
    v14 = lpString2;
    while ( 1 )
    {
      --v13;
      if ( *v14 == 0 )
        break;
      ++v14;
      if ( v13 == 0 )
      {
        v13 = -1;
        break;
      }
    }
    v12 = -1 - v13 + cchCount2;
    cchCount2 = v12;
  }
  retcode = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  if ( v9 != 0 && v12 != 0 )
    goto LABEL_44;
  if ( v9 == v12 )
    return 2;
  if ( v12 > 1 )
    return 1;
  if ( v9 > 1 )
    return 3;
  if ( !GetCPInfo(CodePage: code_page, &lpCPInfo) )
    return 0;
  if ( v9 > 0 )
  {
    if ( lpCPInfo.MaxCharSize >= 2 )
    {
      LeadByte = lpCPInfo.LeadByte;
      if ( lpCPInfo.LeadByte[0] != 0 )
      {
        while ( 1 )
        {
          v17 = LeadByte[1];
          if ( v17 == 0 )
            break;
          if ( (unsigned int)*lpMultiByteStr >= *LeadByte && (unsigned int)*lpMultiByteStr <= v17 )
            return 2;
          LeadByte += 2;
          if ( *LeadByte == 0 )
            return 3;
        }
      }
    }
    return 3;
  }
  if ( v12 > 0 )
  {
    if ( lpCPInfo.MaxCharSize >= 2 )
    {
      for ( i = lpCPInfo.LeadByte; *i != 0; i += 2 )
      {
        v19 = i[1];
        if ( v19 == 0 )
          break;
        if ( (unsigned int)*v36 >= *i && (unsigned int)*v36 <= v19 )
          return 2;
      }
    }
    return 1;
  }
LABEL_44:
  v20 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 9u,
          lpMultiByteStr,
          cbMultiByte: v9,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  v21 = v20;
  buff_size1 = v20;
  if ( v20 == 0 )
    return 0;
  if ( v20 > 0 && 0xFFFFFFE0 / v20 >= 2 )
  {
    v22 = 2 * v20 + 8;
    if ( v22 > 0x400 )
    {
      v24 = (wchar_t *)operator new(nSize: 2 * v21 + 8);
      if ( v24 != nullptr )
      {
        *(_DWORD *)v24 = 56797;
        goto LABEL_52;
      }
    }
    else
    {
      v23 = alloca(v22);
      v24 = (wchar_t *)v32;
      if ( v32 != nullptr )
      {
        v32[0] = 52428;
LABEL_52:
        v24 += 4;
      }
    }
    wbuffer1 = v24;
    goto LABEL_55;
  }
  wbuffer1 = nullptr;
LABEL_55:
  if ( wbuffer1 == nullptr )
    return 0;
  if ( MultiByteToWideChar(
         CodePage: code_page,
         dwFlags: 1u,
         lpMultiByteStr,
         cbMultiByte: cchCount1,
         lpWideCharStr: wbuffer1,
         cchWideChar: v21) != 0 )
  {
    v25 = MultiByteToWideChar(
            CodePage: code_page,
            dwFlags: 9u,
            lpMultiByteStr: v36,
            cbMultiByte: cchCount2,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    v26 = v25;
    if ( v25 != 0 )
    {
      if ( v25 <= 0 || 0xFFFFFFE0 / v25 < 2 )
      {
        v30 = nullptr;
LABEL_68:
        if ( v30 != nullptr )
        {
          if ( MultiByteToWideChar(
                 CodePage: code_page,
                 dwFlags: 1u,
                 lpMultiByteStr: v36,
                 cbMultiByte: cchCount2,
                 lpWideCharStr: v30,
                 cchWideChar: v26) != 0 )
            retcode = CompareStringW(
                        Locale,
                        dwCmpFlags,
                        lpString1: wbuffer1,
                        cchCount1: buff_size1,
                        lpString2: v30,
                        cchCount2: v26);
          _freea(_Memory: v30);
        }
        goto error_cleanup_0;
      }
      v27 = 2 * v25 + 8;
      if ( v27 > 0x400 )
      {
        v29 = (WCHAR *)operator new(nSize: 2 * v26 + 8);
        if ( v29 != nullptr )
        {
          *(_DWORD *)v29 = 56797;
          goto LABEL_65;
        }
      }
      else
      {
        v28 = alloca(v27);
        v29 = (WCHAR *)v32;
        if ( v32 != nullptr )
        {
          v32[0] = 52428;
LABEL_65:
          v29 += 4;
        }
      }
      v30 = v29;
      goto LABEL_68;
    }
  }
error_cleanup_0:
  _freea(_Memory: wbuffer1);
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x00471070
// Name: ___crtCompareStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        const char *lpString2,
        int cchCount2,
        UINT code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtCompareStringA_stat(
             plocinfo: &_loc_update.localeinfo,
             lpString2,
             Locale,
             dwCmpFlags,
             lpString1,
             cchCount1,
             cchCount2,
             code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004710B2
// Name: __strnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strnicoll_l(const char *_string1, const char *_string2, unsigned int count, localeinfo_struct *plocinfo)
{
  int result; // eax
  LCID v5; // ecx
  int v6; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( count == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( _string1 != nullptr && _string2 != nullptr )
  {
    if ( count > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
LABEL_16:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    v5 = _loc_update.localeinfo.locinfo->lc_handle[1];
    if ( v5 != 0 )
    {
      v6 = __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: v5,
             dwCmpFlags: 0x1001u,
             lpString1: _string1,
             cchCount1: count,
             lpString2: _string2,
             cchCount2: count,
             code_page: _loc_update.localeinfo.locinfo->lc_collate_cp);
      if ( v6 == 0 )
      {
        *_errno() = 22;
        goto LABEL_16;
      }
      result = v6 - 2;
    }
    else
    {
      result = _strnicmp_l(dst: _string1, src: _string2, count, plocinfo: &_loc_update.localeinfo);
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047119C
// Name: findenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall findenv@<eax>(unsigned int len@<edi>, const char *name)
{
  const unsigned __int8 **i; // esi
  unsigned __int8 v3; // al

  for ( i = (const unsigned __int8 **)_environ; ; ++i )
  {
    if ( *i == nullptr )
      return -(((char *)i - (char *)_environ) >> 2);
    if ( _mbsnbicoll(s1: (const unsigned __int8 *)name, s2: *i, n: len) == 0 )
    {
      v3 = (*i)[len];
      if ( v3 == 61 || v3 == 0 )
        break;
    }
  }
  return ((char *)i - (char *)_environ) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x004711EE
// Name: copy_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__usercall copy_environ@<eax>(char **oldenviron@<eax>)
{
  char **result; // eax
  char **v3; // ecx
  unsigned __int8 *v4; // esi
  char *v5; // eax
  int v6; // edi
  char **newenviron; // [esp+4h] [ebp-4h]

  result = nullptr;
  v3 = oldenviron;
  if ( oldenviron != nullptr )
  {
    if ( *oldenviron != nullptr )
    {
      do
      {
        ++v3;
        result = (char **)((char *)result + 1);
      }
      while ( *v3 != nullptr );
    }
    v4 = calloc(count: (unsigned int)result + 1, size: 4u);
    newenviron = (char **)v4;
    if ( v4 == nullptr )
      _amsg_exit(rterrnum: 9);
    v5 = *oldenviron;
    if ( *oldenviron != nullptr )
    {
      v6 = (char *)oldenviron - (char *)v4;
      do
      {
        *(_DWORD *)v4 = _strdup(string: v5);
        v4 += 4;
        v5 = *(char **)&v4[v6];
      }
      while ( v5 != nullptr );
    }
    *(_DWORD *)v4 = 0;
    return newenviron;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047124E
// Name: ___crtsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtsetenv(char **poption, int primary)
{
  const unsigned __int8 *v3; // esi
  const unsigned __int8 *v4; // eax
  const unsigned __int8 *v5; // edi
  char **v6; // eax
  char **v7; // eax
  unsigned __int16 **v8; // eax
  char **v9; // esi
  int v10; // eax
  unsigned int v11; // edi
  char **v12; // esi
  unsigned __int8 *v13; // eax
  char **v14; // ecx
  int v15; // eax
  unsigned __int8 *v16; // edi
  int v17; // eax
  const char *v18; // eax
  const char *equal; // [esp+4h] [ebp-14h]
  char **env; // [esp+8h] [ebp-10h]
  int retval; // [esp+Ch] [ebp-Ch]
  BOOL remove; // [esp+10h] [ebp-8h]
  char *option; // [esp+14h] [ebp-4h]

  retval = 0;
  if ( poption == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v3 = (const unsigned __int8 *)*poption;
  option = *poption;
  if ( *poption == nullptr )
    goto LABEL_12;
  v4 = _mbschr(string: v3, c: 0x3Du);
  v5 = v4;
  equal = (const char *)v4;
  if ( v4 == nullptr || v3 == v4 )
    goto LABEL_12;
  remove = v4[1] == 0;
  v6 = _environ;
  if ( _environ == __initenv )
  {
    v6 = copy_environ(oldenviron: _environ);
    _environ = v6;
  }
  if ( v6 == nullptr )
  {
    if ( primary != 0 && _wenviron != nullptr )
    {
      if ( __wtomb_environ() != 0 )
      {
LABEL_12:
        *_errno() = 22;
        return -1;
      }
    }
    else
    {
      if ( remove )
        return 0;
      v7 = (char **)operator new(nSize: 4u);
      _environ = v7;
      if ( v7 == nullptr )
        return -1;
      *v7 = nullptr;
      if ( _wenviron == nullptr )
      {
        v8 = (unsigned __int16 **)operator new(nSize: 4u);
        _wenviron = v8;
        if ( v8 == nullptr )
          return -1;
        *v8 = nullptr;
      }
    }
  }
  v9 = _environ;
  env = _environ;
  if ( _environ == nullptr )
    return -1;
  v10 = findenv(len: v5 - (const unsigned __int8 *)option, name: option);
  v11 = v10;
  if ( v10 < 0 || *v9 == nullptr )
  {
    if ( !remove )
    {
      if ( v10 < 0 )
        v11 = -v10;
      if ( (int)(v11 + 2) <= (int)v11 )
        return -1;
      if ( v11 + 2 >= 0x3FFFFFFF )
        return -1;
      v13 = _recalloc_crt(ptr: _environ, count: 4u, size: v11 + 2);
      if ( v13 == nullptr )
        return -1;
      v14 = (char **)&v13[4 * v11];
      *v14 = option;
      v14[1] = nullptr;
      *poption = nullptr;
      goto LABEL_37;
    }
    free(pMem: option);
    *poption = nullptr;
    return 0;
  }
  v12 = &v9[v10];
  free(pMem: *v12);
  if ( !remove )
  {
    *v12 = option;
    *poption = nullptr;
    goto LABEL_38;
  }
  while ( *v12 != nullptr )
  {
    *v12 = v12[1];
    v12 = &env[++v11];
  }
  if ( v11 < 0x3FFFFFFF )
  {
    v13 = _recalloc_crt(ptr: _environ, count: v11, size: 4u);
    if ( v13 == nullptr )
      goto LABEL_38;
LABEL_37:
    _environ = (char **)v13;
  }
LABEL_38:
  if ( primary != 0 )
  {
    strlen(buf: option);
    v16 = calloc(count: v15 + 2, size: 1u);
    if ( v16 != nullptr )
    {
      strlen(buf: option);
      if ( strcpy_s(_Dst: (char *)v16, _SizeInBytes: v17 + 2, _Src: option) != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      v18 = &equal[v16 - (unsigned __int8 *)option];
      *v18 = 0;
      if ( !SetEnvironmentVariableA(lpName: (LPCSTR)v16, lpValue: !remove ? v18 + 1 : nullptr) )
      {
        retval = -1;
        *_errno() = 42;
      }
      free(pMem: v16);
    }
  }
  if ( remove )
  {
    free(pMem: option);
    *poption = nullptr;
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00471490
// Name: __matherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _matherr()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00471493
// Name: __raise_exc_ex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _raise_exc_ex(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        float *parg1,
        float *presult,
        int isfloat)
{
  char v7; // cl
  unsigned int *v8; // esi
  char v9; // al
  int v10; // eax
  _FPIEEE_RECORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _FPIEEE_RECORD *v14; // eax
  unsigned int v15; // ecx
  float *v16; // edi
  _FPIEEE_RECORD *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned int v24; // eax

  v7 = flags;
  prec->Cause = 0;
  prec->Enable = 0;
  prec->Status = 0;
  if ( (v7 & 0x10) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 1u;
    flags = -1073741681;
  }
  if ( (v7 & 2) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 2u;
    flags = -1073741677;
  }
  if ( (v7 & 1) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 4u;
    flags = -1073741679;
  }
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 8u;
    flags = -1073741682;
  }
  if ( (v7 & 8) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 0x10u;
    flags = -1073741680;
  }
  v8 = pcw;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(16 * *pcw)) & 0x10;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(2 * *v8)) & 8;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 1)) & 4;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 3)) & 2;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 5)) & 1;
  v9 = _statfp();
  if ( (v9 & 1) != 0 )
    *(_DWORD *)&prec->Status |= 0x10u;
  if ( (v9 & 4) != 0 )
    *(_DWORD *)&prec->Status |= 8u;
  if ( (v9 & 8) != 0 )
    *(_DWORD *)&prec->Status |= 4u;
  if ( (v9 & 0x10) != 0 )
    *(_DWORD *)&prec->Status |= 2u;
  if ( (v9 & 0x20) != 0 )
    *(_DWORD *)&prec->Status |= 1u;
  v10 = *v8 & 0xC00;
  switch ( v10 )
  {
    case 0:
      *(_DWORD *)prec &= 0xFFFFFFFC;
      break;
    case 1024:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 1;
      goto LABEL_27;
    case 2048:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 2;
LABEL_27:
      *(_DWORD *)v11 = v12;
      break;
    case 3072:
      *(_DWORD *)prec |= 3u;
      break;
    default:
      break;
  }
  v13 = *v8 & 0x300;
  switch ( v13 )
  {
    case 0:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 8;
      goto LABEL_36;
    case 512:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 4;
LABEL_36:
      *(_DWORD *)v14 = v15;
      break;
    case 768:
      *(_DWORD *)prec &= 0xFFFFFFE3;
      break;
    default:
      break;
  }
  *(_DWORD *)prec ^= (*(_DWORD *)prec ^ (32 * opcode)) & 0x1FFE0;
  *((_DWORD *)&prec->Operand1 + 4) |= 1u;
  v16 = presult;
  if ( isfloat != 0 )
  {
    *((_DWORD *)&prec->Operand1 + 4) &= 0xFFFFFFE1;
    prec->Operand1.Value.Fp32Value = *parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) &= 0xFFFFFFE1;
    prec->Result.Value.Fp32Value = *v16;
  }
  else
  {
    *((_DWORD *)&prec->Operand1 + 4) = *((_DWORD *)&prec->Operand1 + 4) & 0xFFFFFFE1 | 2;
    prec->Operand1.Value.Fp64Value = *(double *)parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) = *((_DWORD *)&prec->Result + 4) & 0xFFFFFFE1 | 2;
    prec->Result.Value.Fp64Value = *(double *)v16;
  }
  _clrfp();
  RaiseException(
    dwExceptionCode: flags,
    dwExceptionFlags: 0,
    nNumberOfArguments: 1u,
    lpArguments: (const ULONG_PTR *)&prec);
  v17 = prec;
  if ( (*(_BYTE *)&prec->Enable & 0x10) != 0 )
    *v8 &= ~1u;
  if ( (*(_BYTE *)&v17->Enable & 8) != 0 )
    *v8 &= ~4u;
  if ( (*(_BYTE *)&v17->Enable & 4) != 0 )
    *v8 &= ~8u;
  if ( (*(_BYTE *)&v17->Enable & 2) != 0 )
    *v8 &= ~0x10u;
  if ( (*(_BYTE *)&v17->Enable & 1) != 0 )
    *v8 &= ~0x20u;
  v18 = *(_DWORD *)v17 & 3;
  if ( v18 == 0 )
  {
    *v8 &= 0xFFFFF3FF;
    goto LABEL_59;
  }
  v19 = v18 - 1;
  if ( v19 == 0 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x400;
    goto LABEL_56;
  }
  v20 = v19 - 1;
  if ( v20 == 0 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x800;
LABEL_56:
    *v8 = v21;
    goto LABEL_59;
  }
  if ( v20 == 1 )
    *v8 |= 0xC00u;
LABEL_59:
  v22 = (*(_DWORD *)v17 >> 2) & 7;
  if ( v22 == 0 )
  {
    v24 = *v8 & 0xFFFFF0FF | 0x300;
    goto LABEL_65;
  }
  v23 = v22 - 1;
  if ( v23 == 0 )
  {
    v24 = *v8 & 0xFFFFF1FF | 0x200;
LABEL_65:
    *v8 = v24;
    goto LABEL_66;
  }
  if ( v23 == 1 )
    *v8 &= 0xFFFFF3FF;
LABEL_66:
  if ( isfloat != 0 )
    *v16 = v17->Result.Value.Fp32Value;
  else
    *(double *)v16 = v17->Result.Value.Fp64Value;
}

//------------------------------------------------------------------------------
// Address: 0x0047176F
// Name: __raise_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _raise_exc(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        long double *parg1,
        long double *presult)
{
  _raise_exc_ex(prec, pcw, flags, opcode, (float *)parg1, (float *)presult, isfloat: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00471792
// Name: __handle_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _handle_exc(char flags, long double *presult, __int16 cw)
{
  int v3; // esi
  int v4; // eax
  double *v5; // ecx
  long double dbl; // st7
  BOOL v7; // esi
  int v8; // ecx
  double v9; // st7
  BOOL v10; // edx
  int v11; // eax
  double v13; // [esp+18h] [ebp-14h]
  int expn; // [esp+24h] [ebp-8h] BYREF
  int flags_p; // [esp+28h] [ebp-4h]

  v3 = flags & 0x1F;
  flags_p = v3;
  if ( (flags & 8) != 0 && (cw & 1) != 0 )
  {
    _set_statfp(sw: 1u);
    v3 = flags & 0x17;
    goto LABEL_46;
  }
  if ( (flags & 4) != 0 && (cw & 4) != 0 )
  {
    _set_statfp(sw: 4u);
    v3 = flags & 0x1B;
    goto LABEL_46;
  }
  if ( (flags & 1) != 0 && (cw & 8) != 0 )
  {
    _set_statfp(sw: 8u);
    v4 = cw & 0xC00;
    if ( (cw & 0xC00) != 0 )
    {
      if ( v4 != 1024 )
      {
        if ( v4 != 2048 )
        {
          if ( v4 != 3072 )
          {
LABEL_24:
            v3 = flags & 0x1E;
            goto LABEL_46;
          }
          v5 = presult;
          dbl = _d_max.dbl;
          if ( *presult <= 0.0 )
            goto LABEL_22;
LABEL_23:
          *v5 = dbl;
          goto LABEL_24;
        }
        v5 = presult;
        if ( *presult <= 0.0 )
        {
          dbl = _d_max.dbl;
LABEL_22:
          dbl = -dbl;
          goto LABEL_23;
        }
LABEL_20:
        dbl = _d_inf.dbl;
        goto LABEL_23;
      }
      v5 = presult;
      if ( *presult > 0.0 )
      {
        dbl = _d_max.dbl;
        goto LABEL_23;
      }
    }
    else
    {
      v5 = presult;
      if ( *presult > 0.0 )
        goto LABEL_20;
    }
    dbl = _d_inf.dbl;
    goto LABEL_22;
  }
  if ( (flags & 2) != 0 && (cw & 0x10) != 0 )
  {
    v7 = (flags & 0x10) != 0;
    if ( 0.0 == *presult )
    {
      v7 = true;
      goto LABEL_43;
    }
    v13 = _decomp(x: *presult, pexp: &expn);
    v8 = expn - 1536;
    if ( expn - 1536 >= -1074 )
    {
      v10 = v13 < 0.0;
      HIWORD(v13) = BYTE6(v13) & 0xF | 0x10;
      if ( v8 < -1021 )
      {
        v11 = -1021 - v8;
        do
        {
          if ( (LOBYTE(v13) & 1) != 0 && !v7 )
            v7 = true;
          LODWORD(v13) >>= 1;
          if ( (BYTE4(v13) & 1) != 0 )
            LODWORD(v13) |= 0x80000000;
          HIDWORD(v13) >>= 1;
          --v11;
        }
        while ( v11 != 0 );
      }
      if ( !v10 )
        goto LABEL_41;
      v9 = -v13;
    }
    else
    {
      v7 = true;
      v9 = v13 * 0.0;
    }
    v13 = v9;
LABEL_41:
    *presult = v13;
LABEL_43:
    if ( v7 )
      _set_statfp(sw: 0x10u);
    flags_p &= ~2u;
    v3 = flags_p;
  }
LABEL_46:
  if ( (flags & 0x10) != 0 && (cw & 0x20) != 0 )
  {
    _set_statfp(sw: 0x20u);
    v3 &= ~0x10u;
  }
  return v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00471976
// Name: __set_errno_from_matherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_errno_from_matherr(int matherrtype)
{
  if ( matherrtype == 1 )
  {
    *_errno() = 33;
  }
  else if ( matherrtype > 1 && matherrtype <= 3 )
  {
    *_errno() = 34;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004719A3
// Name: __errcode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _errcode(char flags)
{
  if ( (flags & 0x20) != 0 )
    return 5;
  if ( (flags & 8) != 0 )
    return 1;
  if ( (flags & 4) != 0 )
    return 2;
  if ( (flags & 1) != 0 )
    return 3;
  return 2 * (flags & 2);
}

//------------------------------------------------------------------------------
// Address: 0x004719D7
// Name: __umatherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _umatherr(
        int type,
        unsigned int opcode,
        long double arg1,
        long double arg2,
        long double retval,
        unsigned int cw)
{
  int v6; // eax
  char *v7; // eax

  v6 = 0;
  while ( dword_5A6AC8[2 * v6] != opcode )
  {
    if ( ++v6 >= 29 )
    {
      v7 = nullptr;
      goto LABEL_5;
    }
  }
  v7 = (&off_5A6ACC)[2 * v6];
LABEL_5:
  if ( v7 != nullptr )
  {
    _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
    if ( _matherr() == 0 )
      _set_errno_from_matherr(matherrtype: type);
    return retval;
  }
  else
  {
    _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
    _set_errno_from_matherr(matherrtype: type);
    return retval;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471A77
// Name: __handle_qnan1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _handle_qnan1(unsigned int opcode, long double x, unsigned int savedcw)
{
  if ( _matherr_flag == 0 )
    return _umatherr(type: 1, opcode, arg1: x, arg2: 0.0, retval: x, cw: savedcw);
  *_errno() = 33;
  _ctrlfp(newctrl: savedcw, _mask: 0xFFFFu);
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x00471ACC
// Name: __except1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _except1@<st0>(
        int a1@<ebp>,
        int flags,
        int opcode,
        long double arg,
        long double result,
        unsigned int cw)
{
  int v6; // eax
  int v8; // [esp+1Ch] [ebp-8Ch] BYREF
  _FPIEEE_RECORD rec; // [esp+28h] [ebp-80h]
  int v10; // [esp+9Ch] [ebp-Ch]
  void *v11; // [esp+A0h] [ebp-8h]
  void *retaddr; // [esp+A8h] [ebp+0h]

  v10 = a1;
  v11 = retaddr;
  if ( !_handle_exc(flags, presult: &result, cw) )
  {
    rec.Operand2.Value.Fp128Value.W[1] &= ~1u;
    _raise_exc_ex(
      prec: (_FPIEEE_RECORD *)&v8,
      pcw: &cw,
      flags,
      opcode,
      parg1: (float *)&arg,
      presult: (float *)&result,
      isfloat: 0);
  }
  v6 = _errcode(flags);
  if ( _matherr_flag == 0 && v6 != 0 )
    return _umatherr(type: v6, opcode, arg1: arg, arg2: 0.0, retval: result, cw);
  _set_errno_from_matherr(matherrtype: v6);
  _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00471B96
// Name: __frnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _frnd(long double x)
{
  return rint(x);
}

//------------------------------------------------------------------------------
// Address: 0x00471BAA
// Name: __set_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _set_exp(long double x, __int16 exp)
{
  long double retval; // [esp+0h] [ebp-8h]

  retval = x;
  HIWORD(retval) = HIWORD(x) & 0x800F | (16 * (exp + 1022));
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00471BD7
// Name: __sptype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sptype(long double x)
{
  if ( HIDWORD(x) == 2146435072 )
  {
    if ( LODWORD(x) == 0 )
      return 1;
  }
  else if ( x == -INFINITY )
  {
    return 2;
  }
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF8 )
    return 3;
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF0 && ((HIDWORD(x) & 0x7FFFF) != 0 || LODWORD(x) != 0) )
    return 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00471C3D
// Name: __decomp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _decomp(long double x, int *pexp)
{
  long double result; // st7
  int v3; // edx
  int v4; // edx
  BOOL v5; // eax

  result = 0.0;
  if ( 0.0 == x )
  {
    v3 = 0;
  }
  else if ( (HIWORD(x) & 0x7FF0) == 0 && ((HIDWORD(x) & 0xFFFFF) != 0 || LODWORD(x) != 0) )
  {
    v4 = -1021;
    v5 = x < 0.0;
    while ( (BYTE6(x) & 0x10) == 0 )
    {
      HIDWORD(x) *= 2;
      if ( SLODWORD(x) < 0 )
        HIDWORD(x) |= 1u;
      LODWORD(x) *= 2;
      --v4;
    }
    HIWORD(x) &= ~0x10u;
    if ( v5 )
      HIWORD(x) |= 0x8000u;
    result = _set_exp(x, exp: 0);
  }
  else
  {
    result = _set_exp(x, exp: 0);
    v3 = ((HIWORD(x) >> 4) & 0x7FF) - 1022;
  }
  *pexp = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00471D00
// Name: __statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _statfp@<eax>(__int16 a1@<fpstat>)
{
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00471D10
// Name: __clrfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _clrfp@<eax>(__int16 a1@<fpstat>)
{
  __asm { fnclex }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00471D21
// Name: __ctrlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _ctrlfp()
{
  __int16 oldCw; // [esp+0h] [ebp-4h]

  return oldCw;
}

//------------------------------------------------------------------------------
// Address: 0x00471D4C
// Name: __set_statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_statfp()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00471DA4
// Name: ___set_fpsr_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __set_fpsr_sse2(unsigned int newMXCSR)
{
  if ( __sse2_available != 0 )
  {
    if ( (newMXCSR & 0x40) != 0 && _DAZ_ENABLED != 0 )
      _mm_setcsr(newMXCSR);
    else
      _mm_setcsr(newMXCSR & 0xFFFFFFBF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471E16
// Name: __crtGetStringTypeA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtGetStringTypeA_stat(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        UINT code_page,
        int bError)
{
  unsigned __int8 *v7; // ebx
  int v8; // eax
  int v9; // edi
  unsigned int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // eax
  _DWORD v15[3]; // [esp+0h] [ebp-14h] BYREF
  int retval2; // [esp+Ch] [ebp-8h]

  v7 = nullptr;
  retval2 = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  v8 = MultiByteToWideChar(
         CodePage: code_page,
         dwFlags: 8 * (bError != 0) + 1,
         lpMultiByteStr: lpSrcStr,
         cbMultiByte: cchSrc,
         lpWideCharStr: nullptr,
         cchWideChar: 0);
  v9 = v8;
  if ( v8 == 0 )
    return 0;
  if ( v8 > 0 && (unsigned int)v8 <= 0x7FFFFFF0 )
  {
    v11 = 2 * v8 + 8;
    if ( v11 > 0x400 )
    {
      v13 = (unsigned __int8 *)operator new(nSize: 2 * v9 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_12;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_12:
        v13 += 8;
      }
    }
    v7 = v13;
  }
  if ( v7 == nullptr )
    return 0;
  memset(dst: v7, value: 0, count: 2 * v9);
  v14 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 1u,
          lpMultiByteStr: lpSrcStr,
          cbMultiByte: cchSrc,
          lpWideCharStr: (LPWSTR)v7,
          cchWideChar: v9);
  if ( v14 != 0 )
    retval2 = GetStringTypeW(dwInfoType, lpSrcStr: (LPCWCH)v7, cchSrc: v14, lpCharType);
  _freea(_Memory: v7);
  return retval2;
}

//------------------------------------------------------------------------------
// Address: 0x00471EFD
// Name: ___crtGetStringTypeA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetStringTypeA(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        UINT code_page,
        int lcid,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtGetStringTypeA_stat(
             plocinfo: &_loc_update.localeinfo,
             dwInfoType,
             lpSrcStr,
             cchSrc,
             lpCharType,
             code_page,
             bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00471F3D
// Name: ___free_lc_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lc_time(__lc_time_data *lc_time)
{
  if ( lc_time != nullptr )
  {
    free(pMem: lc_time->wday_abbr[1]);
    free(pMem: lc_time->wday_abbr[2]);
    free(pMem: lc_time->wday_abbr[3]);
    free(pMem: lc_time->wday_abbr[4]);
    free(pMem: lc_time->wday_abbr[5]);
    free(pMem: lc_time->wday_abbr[6]);
    free(pMem: lc_time->wday_abbr[0]);
    free(pMem: lc_time->wday[1]);
    free(pMem: lc_time->wday[2]);
    free(pMem: lc_time->wday[3]);
    free(pMem: lc_time->wday[4]);
    free(pMem: lc_time->wday[5]);
    free(pMem: lc_time->wday[6]);
    free(pMem: lc_time->wday[0]);
    free(pMem: lc_time->month_abbr[0]);
    free(pMem: lc_time->month_abbr[1]);
    free(pMem: lc_time->month_abbr[2]);
    free(pMem: lc_time->month_abbr[3]);
    free(pMem: lc_time->month_abbr[4]);
    free(pMem: lc_time->month_abbr[5]);
    free(pMem: lc_time->month_abbr[6]);
    free(pMem: lc_time->month_abbr[7]);
    free(pMem: lc_time->month_abbr[8]);
    free(pMem: lc_time->month_abbr[9]);
    free(pMem: lc_time->month_abbr[10]);
    free(pMem: lc_time->month_abbr[11]);
    free(pMem: lc_time->month[0]);
    free(pMem: lc_time->month[1]);
    free(pMem: lc_time->month[2]);
    free(pMem: lc_time->month[3]);
    free(pMem: lc_time->month[4]);
    free(pMem: lc_time->month[5]);
    free(pMem: lc_time->month[6]);
    free(pMem: lc_time->month[7]);
    free(pMem: lc_time->month[8]);
    free(pMem: lc_time->month[9]);
    free(pMem: lc_time->month[10]);
    free(pMem: lc_time->month[11]);
    free(pMem: lc_time->ampm[0]);
    free(pMem: lc_time->ampm[1]);
    free(pMem: lc_time->ww_sdatefmt);
    free(pMem: lc_time->ww_ldatefmt);
    free(pMem: lc_time->ww_timefmt);
    free(pMem: lc_time->_W_wday_abbr[1]);
    free(pMem: lc_time->_W_wday_abbr[2]);
    free(pMem: lc_time->_W_wday_abbr[3]);
    free(pMem: lc_time->_W_wday_abbr[4]);
    free(pMem: lc_time->_W_wday_abbr[5]);
    free(pMem: lc_time->_W_wday_abbr[6]);
    free(pMem: lc_time->_W_wday_abbr[0]);
    free(pMem: lc_time->_W_wday[1]);
    free(pMem: lc_time->_W_wday[2]);
    free(pMem: lc_time->_W_wday[3]);
    free(pMem: lc_time->_W_wday[4]);
    free(pMem: lc_time->_W_wday[5]);
    free(pMem: lc_time->_W_wday[6]);
    free(pMem: lc_time->_W_wday[0]);
    free(pMem: lc_time->_W_month_abbr[0]);
    free(pMem: lc_time->_W_month_abbr[1]);
    free(pMem: lc_time->_W_month_abbr[2]);
    free(pMem: lc_time->_W_month_abbr[3]);
    free(pMem: lc_time->_W_month_abbr[4]);
    free(pMem: lc_time->_W_month_abbr[5]);
    free(pMem: lc_time->_W_month_abbr[6]);
    free(pMem: lc_time->_W_month_abbr[7]);
    free(pMem: lc_time->_W_month_abbr[8]);
    free(pMem: lc_time->_W_month_abbr[9]);
    free(pMem: lc_time->_W_month_abbr[10]);
    free(pMem: lc_time->_W_month_abbr[11]);
    free(pMem: lc_time->_W_month[0]);
    free(pMem: lc_time->_W_month[1]);
    free(pMem: lc_time->_W_month[2]);
    free(pMem: lc_time->_W_month[3]);
    free(pMem: lc_time->_W_month[4]);
    free(pMem: lc_time->_W_month[5]);
    free(pMem: lc_time->_W_month[6]);
    free(pMem: lc_time->_W_month[7]);
    free(pMem: lc_time->_W_month[8]);
    free(pMem: lc_time->_W_month[9]);
    free(pMem: lc_time->_W_month[10]);
    free(pMem: lc_time->_W_month[11]);
    free(pMem: lc_time->_W_ampm[0]);
    free(pMem: lc_time->_W_ampm[1]);
    free(pMem: lc_time->_W_ww_sdatefmt);
    free(pMem: lc_time->_W_ww_ldatefmt);
    free(pMem: lc_time->_W_ww_timefmt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004722B4
// Name: ___free_lconv_num
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_num(lconv *l)
{
  wchar_t *W_thousands_sep; // esi

  if ( l != nullptr )
  {
    if ( l->decimal_point != __lconv_c.decimal_point )
      free(pMem: l->decimal_point);
    if ( l->thousands_sep != __lconv_c.thousands_sep )
      free(pMem: l->thousands_sep);
    if ( l->grouping != __lconv_c.grouping )
      free(pMem: l->grouping);
    if ( l->_W_decimal_point != __lconv_c._W_decimal_point )
      free(pMem: l->_W_decimal_point);
    W_thousands_sep = l->_W_thousands_sep;
    if ( W_thousands_sep != __lconv_c._W_thousands_sep )
      free(pMem: W_thousands_sep);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047231D
// Name: ___free_lconv_mon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_mon(lconv *l)
{
  wchar_t *W_negative_sign; // esi

  if ( l != nullptr )
  {
    if ( l->int_curr_symbol != __lconv_c.int_curr_symbol )
      free(pMem: l->int_curr_symbol);
    if ( l->currency_symbol != __lconv_c.currency_symbol )
      free(pMem: l->currency_symbol);
    if ( l->mon_decimal_point != __lconv_c.mon_decimal_point )
      free(pMem: l->mon_decimal_point);
    if ( l->mon_thousands_sep != __lconv_c.mon_thousands_sep )
      free(pMem: l->mon_thousands_sep);
    if ( l->mon_grouping != __lconv_c.mon_grouping )
      free(pMem: l->mon_grouping);
    if ( l->positive_sign != __lconv_c.positive_sign )
      free(pMem: l->positive_sign);
    if ( l->negative_sign != __lconv_c.negative_sign )
      free(pMem: l->negative_sign);
    if ( l->_W_int_curr_symbol != __lconv_c._W_int_curr_symbol )
      free(pMem: l->_W_int_curr_symbol);
    if ( l->_W_currency_symbol != __lconv_c._W_currency_symbol )
      free(pMem: l->_W_currency_symbol);
    if ( l->_W_mon_decimal_point != __lconv_c._W_mon_decimal_point )
      free(pMem: l->_W_mon_decimal_point);
    if ( l->_W_mon_thousands_sep != __lconv_c._W_mon_thousands_sep )
      free(pMem: l->_W_mon_thousands_sep);
    if ( l->_W_positive_sign != __lconv_c._W_positive_sign )
      free(pMem: l->_W_positive_sign);
    W_negative_sign = l->_W_negative_sign;
    if ( W_negative_sign != __lconv_c._W_negative_sign )
      free(pMem: W_negative_sign);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472420
// Name: _strcspn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcspn(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  int v5; // ecx
  signed __int32 v6[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v6, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v6, v2);
  }
  v5 = -1;
  do
  {
    ++v5;
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v6, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x00472470
// Name: _strpbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strpbrk(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  signed __int32 v5[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v5, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v5, v2);
  }
  do
  {
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v5, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x004724B0
// Name: __putwch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _putwch_nolock(wchar_t ch)
{
  unsigned int cchWritten; // [esp+0h] [ebp-4h] BYREF

  if ( _confh == (HANDLE)-2 )
    __initconout();
  if ( _confh == (HANDLE)-1
    || !WriteConsoleW(
          hConsoleOutput: _confh,
          lpBuffer: &ch,
          nNumberOfCharsToWrite: 1u,
          lpNumberOfCharsWritten: &cchWritten,
          lpReserved: nullptr) )
  {
    return -1;
  }
  else
  {
    return ch;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004724F2
// Name: __mbsicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsicmp_l(const unsigned __int8 *s1, const unsigned __int8 *s2, localeinfo_struct *plocinfo)
{
  const unsigned __int8 *v3; // edx
  int result; // eax
  const unsigned __int8 *v5; // ebx
  threadmbcinfostruct *mbcinfo; // eax
  int v7; // ecx
  const unsigned __int8 *v8; // edx
  unsigned __int16 v9; // si
  int v10; // eax
  __int16 v11; // dx
  char *v12; // ecx
  int v13; // ecx
  unsigned __int16 v14; // cx
  int v15; // eax
  unsigned __int16 v16; // dx
  char *v17; // ecx
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  unsigned __int8 szResult[4]; // [esp+10h] [ebp-4h] BYREF
  const unsigned __int8 *s1a; // [esp+1Ch] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = s1;
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v5 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  mbcinfo = _loc_update.localeinfo.mbcinfo;
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = _stricmp_l(dst: (const char *)s1, src: (const char *)s2, plocinfo: &_loc_update.localeinfo);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  while ( 1 )
  {
    v7 = *v3;
    v8 = v3 + 1;
    s1a = v8;
    if ( (mbcinfo->mbctype[(unsigned __int8)v7 + 1] & 4) != 0 )
    {
      if ( *v8 != 0 )
      {
        v10 = __crtLCMapStringA(
                plocinfo: &_loc_update.localeinfo,
                Locale: mbcinfo->mblcid,
                dwMapFlags: 0x200u,
                lpSrcStr: (const char *)v8 - 1,
                cchSrc: 2,
                lpDestStr: (char *)szResult,
                cchDest: 2,
                code_page: mbcinfo->mbcodepage,
                bError: 1);
        if ( v10 == 1 )
        {
          v9 = szResult[0];
        }
        else
        {
          if ( v10 != 2 )
            goto LABEL_37;
          v9 = szResult[1] + (szResult[0] << 8);
        }
        ++s1a;
        mbcinfo = _loc_update.localeinfo.mbcinfo;
      }
      else
      {
        v9 = 0;
      }
    }
    else
    {
      v11 = v7;
      v12 = (char *)mbcinfo + v7;
      v9 = (v12[29] & 0x10) != 0 ? (unsigned __int8)v12[285] : v11;
    }
    v13 = *v5++;
    if ( (mbcinfo->mbctype[(unsigned __int8)v13 + 1] & 4) != 0 )
      break;
    v16 = v13;
    v17 = (char *)mbcinfo + v13;
    if ( (v17[29] & 0x10) != 0 )
      v14 = (unsigned __int8)v17[285];
    else
      v14 = v16;
LABEL_34:
    if ( v14 != v9 )
    {
      result = v14 < v9 ? 1 : -1;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( v9 == 0 )
    {
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
    v3 = s1a;
  }
  if ( *v5 == 0 )
  {
    v14 = 0;
    goto LABEL_34;
  }
  v15 = __crtLCMapStringA(
          plocinfo: &_loc_update.localeinfo,
          Locale: mbcinfo->mblcid,
          dwMapFlags: 0x200u,
          lpSrcStr: (const char *)v5 - 1,
          cchSrc: 2,
          lpDestStr: (char *)szResult,
          cchDest: 2,
          code_page: mbcinfo->mbcodepage,
          bError: 1);
  if ( v15 == 1 )
  {
    v14 = szResult[0];
LABEL_30:
    mbcinfo = _loc_update.localeinfo.mbcinfo;
    ++v5;
    goto LABEL_34;
  }
  if ( v15 == 2 )
  {
    v14 = szResult[1] + (szResult[0] << 8);
    goto LABEL_30;
  }
LABEL_37:
  *_errno() = 22;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x004726E9
// Name: __mbsicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsicmp(const unsigned __int8 *s1, const unsigned __int8 *s2)
{
  return _mbsicmp_l(s1, s2, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00472700
// Name: __mbsrchr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsrchr_l(unsigned __int8 *str, unsigned int c, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 *v4; // ecx
  unsigned __int8 v5; // dl
  int v6; // eax
  bool v7; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  v3 = nullptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v4 = str;
  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    strrchr(string: str, chr: c);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  do
  {
    v5 = *v4;
    v6 = *v4;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[v6 + 1] & 4) != 0 )
    {
      v5 = *++v4;
      if ( *v4 != 0 )
      {
        if ( c == (v5 | (v6 << 8)) )
          v3 = v4 - 1;
        goto LABEL_16;
      }
      v7 = v3 == nullptr;
    }
    else
    {
      v7 = c == v6;
    }
    if ( v7 )
      v3 = v4;
LABEL_16:
    ++v4;
  }
  while ( v5 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x004727AA
// Name: __mbsrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsrchr(unsigned __int8 *str, unsigned int c)
{
  _mbsrchr_l(str, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004727C1
// Name: __87except
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _87except(int a1@<ebp>, int opcode, _exception *exc, unsigned __int16 *pcw16)
{
  __int16 v4; // cx
  bool v5; // zf
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // [esp-Ch] [ebp-94h] BYREF
  DWORD v13; // [esp-8h] [ebp-90h]
  int v14; // [esp-4h] [ebp-8Ch] BYREF
  _FPIEEE_RECORD rec; // [esp+8h] [ebp-80h]
  int v16; // [esp+7Ch] [ebp-Ch]
  void *v17; // [esp+80h] [ebp-8h]
  void *retaddr; // [esp+88h] [ebp+0h]

  v16 = a1;
  v17 = retaddr;
  v4 = *pcw16;
  v6 = exc->typ - 1;
  v5 = exc->typ == 1;
  v12 = *pcw16;
  if ( v5 )
    goto LABEL_13;
  v7 = v6 - 1;
  if ( v7 == 0 )
  {
    v13 = 4;
    goto LABEL_14;
  }
  v8 = v7 - 1;
  if ( v8 == 0 )
  {
    v13 = 17;
    goto LABEL_14;
  }
  v9 = v8 - 1;
  if ( v9 == 0 )
  {
    v13 = 18;
    goto LABEL_14;
  }
  v10 = v9 - 1;
  if ( v10 == 0 )
  {
LABEL_13:
    v13 = 8;
LABEL_14:
    if ( !_handle_exc(flags: v13, presult: (long double *)&exc->retval, cw: v4) )
    {
      if ( opcode == 16 || opcode == 22 || opcode == 29 )
      {
        *(double *)((char *)&rec.Operand1 + 20) = *(double *)&exc->arg2;
        rec.Operand2.Value.Fp128Value.W[1] = rec.Operand2.Value.Fp128Value.W[1] & 0xFFFFFFE0 | 3;
      }
      else
      {
        rec.Operand2.Value.Fp128Value.W[1] &= ~1u;
      }
      _raise_exc(
        prec: (_FPIEEE_RECORD *)&v14,
        pcw: &v12,
        flags: v13,
        opcode,
        parg1: (long double *)&exc->arg1,
        presult: (long double *)&exc->retval);
    }
    goto LABEL_21;
  }
  v11 = v10 - 2;
  if ( v11 == 0 )
  {
    exc->typ = 1;
    goto LABEL_21;
  }
  if ( v11 == 1 )
  {
    v13 = 16;
    goto LABEL_14;
  }
LABEL_21:
  _ctrlfp();
  if ( exc->typ == 8 || _matherr_flag != 0 || _matherr() == 0 )
    _set_errno_from_matherr(matherrtype: exc->typ);
}

//------------------------------------------------------------------------------
// Address: 0x00472900
// Name: __fpclass
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fpclass(long double x)
{
  int v1; // eax
  int v2; // eax
  int v4; // ecx

  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v1 = _sptype(x) - 1;
    if ( v1 != 0 )
    {
      v2 = v1 - 1;
      if ( v2 == 0 )
        return 4;
      if ( v2 != 1 )
        return 1;
      return 2;
    }
    else
    {
      return 512;
    }
  }
  else
  {
    v4 = HIWORD(x) & 0x8000;
    if ( (HIWORD(x) & 0x7FF0) == 0 && ((HIDWORD(x) & 0xFFFFF) != 0 || LODWORD(x) != 0) )
    {
      return v4 != 0 ? 16 : 128;
    }
    else if ( 0.0 == x )
    {
      return v4 != 0 ? 32 : 64;
    }
    else
    {
      return v4 != 0 ? 8 : 256;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047299D
// Name: __fputwc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _fputwc_nolock(wchar_t ch, _iobuf *str)
{
  ioinfo **v2; // edi
  ioinfo *v3; // eax
  ioinfo **v4; // edi
  ioinfo *v5; // eax
  ioinfo **v6; // edi
  ioinfo *v7; // eax
  int v9; // edi
  bool v10; // sf
  int v11; // eax
  int size; // [esp+Ch] [ebp-10h] BYREF
  char mbc[8]; // [esp+10h] [ebp-Ch] BYREF

  if ( (str->_flag & 0x40) != 0
    || (fileno(stream: str) == -1 || fileno(stream: str) == -2
      ? (v3 = &__badioinfo)
      : (v2 = &__pioinfo[fileno(stream: str) >> 5], v3 = &(*v2)[fileno(stream: str) & 0x1F]),
        (*((_BYTE *)v3 + 36) & 0x7F) == 2
     || (fileno(stream: str) == -1 || fileno(stream: str) == -2
       ? (v5 = &__badioinfo)
       : (v4 = &__pioinfo[fileno(stream: str) >> 5], v5 = &(*v4)[fileno(stream: str) & 0x1F]),
         (*((_BYTE *)v5 + 36) & 0x7F) == 1
      || (fileno(stream: str) == -1 || fileno(stream: str) == -2
        ? (v7 = &__badioinfo)
        : (v6 = &__pioinfo[fileno(stream: str) >> 5], v7 = &(*v6)[fileno(stream: str) & 0x1F]),
          v7->osfile >= 0))) )
  {
    v10 = str->_cnt - 2 < 0;
    str->_cnt -= 2;
    if ( v10 )
    {
      return _flswbuf(ch, str);
    }
    else
    {
      *(_WORD *)str->_ptr = ch;
      str->_ptr += 2;
      return ch;
    }
  }
  else
  {
    if ( wctomb_s(pRetValue: &size, dst: mbc, sizeInBytes: 5u, wchar: ch) != 0 )
      return -1;
    v9 = 0;
    if ( size > 0 )
    {
      while ( 1 )
      {
        v10 = --str->_cnt < 0;
        if ( v10 )
        {
          v11 = _flsbuf(ch: mbc[v9], (int)str);
        }
        else
        {
          *str->_ptr = mbc[v9];
          v11 = *(unsigned __int8 *)str->_ptr++;
        }
        if ( v11 == -1 )
          break;
        if ( ++v9 >= size )
          return ch;
      }
      return -1;
    }
    return ch;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472B24
// Name: __ld12tod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
INTRNCVT_STATUS __cdecl _ld12tod(_LDBL12 *pld12, _CRT_DOUBLE *d)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // edi
  unsigned int *v9; // esi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // edi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  int v20; // edx
  unsigned int *v21; // ecx
  int v22; // esi
  int v23; // eax
  unsigned int *v24; // ebx
  bool n; // zf
  int v26; // eax
  unsigned int v27; // edx
  unsigned int *v28; // ecx
  unsigned int v29; // edi
  int ii; // ecx
  unsigned int *v31; // ecx
  unsigned int v32; // esi
  int v33; // edi
  int v34; // eax
  int v35; // edx
  int *v36; // ebx
  int v37; // edx
  unsigned int *v38; // ecx
  int v39; // eax
  int v40; // edx
  int *v41; // ebx
  int v42; // edx
  unsigned int *v43; // ecx
  int v44; // eax
  int v45; // edx
  int v46; // edx
  unsigned int *v47; // ecx
  unsigned int v48; // ebx
  int v49; // edx
  int v50; // [esp+8h] [ebp-38h]
  char v51; // [esp+10h] [ebp-30h]
  int v52; // [esp+10h] [ebp-30h]
  int v53; // [esp+14h] [ebp-2Ch]
  int v54; // [esp+14h] [ebp-2Ch]
  char v55; // [esp+14h] [ebp-2Ch]
  int v56; // [esp+14h] [ebp-2Ch]
  int v57; // [esp+14h] [ebp-2Ch]
  int v58; // [esp+14h] [ebp-2Ch]
  int v59; // [esp+18h] [ebp-28h]
  int v60; // [esp+18h] [ebp-28h]
  int v61; // [esp+18h] [ebp-28h]
  int v62; // [esp+18h] [ebp-28h]
  int v63; // [esp+18h] [ebp-28h]
  int v64; // [esp+18h] [ebp-28h]
  int v65; // [esp+1Ch] [ebp-24h]
  unsigned int v66; // [esp+20h] [ebp-20h]
  int m; // [esp+20h] [ebp-20h]
  int jj; // [esp+20h] [ebp-20h]
  int k; // [esp+20h] [ebp-20h]
  int j; // [esp+20h] [ebp-20h]
  unsigned int v71; // [esp+24h] [ebp-1Ch]
  int v72; // [esp+28h] [ebp-18h]
  int v73; // [esp+2Ch] [ebp-14h]
  unsigned int v74; // [esp+30h] [ebp-10h] BYREF
  int v75; // [esp+34h] [ebp-Ch]
  int v76; // [esp+38h] [ebp-8h] BYREF

  v2 = *(_WORD *)&pld12->ld12[10];
  v50 = v2 & 0x8000;
  v74 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v75 = *(_DWORD *)&pld12->ld12[2];
  v76 = v4;
  if ( v3 != -16383 )
  {
    v65 = 0;
    v71 = v74;
    v72 = v75;
    v73 = v76;
    v8 = DoubleFormat.precision - 1;
    v53 = v3;
    v59 = DoubleFormat.precision / 32;
    v9 = &v74 + DoubleFormat.precision / 32;
    v51 = 31 - DoubleFormat.precision % 32;
    if ( ((1 << v51) & *v9) != 0 )
    {
      v10 = DoubleFormat.precision / 32;
      for ( i = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v74 + v59)) == 0; i; i = *(&v74 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_21;
      }
      v12 = v8 / 32;
      v65 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v74 + v8 / 32;
      v66 = v13 + *v14;
      if ( v66 >= *v14 )
      {
        v15 = v66 < v13;
        goto LABEL_18;
      }
LABEL_19:
      v65 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = v66;
        if ( v12 < 0 || v65 == 0 )
          break;
        v65 = 0;
        v14 = &v74 + v12;
        v16 = *v14 + 1;
        v66 = v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
    }
LABEL_21:
    *v9 &= -1 << v51;
    if ( v59 + 1 < 3 )
      memset(&v74 + v59 + 1, 0, 4 * (3 - (v59 + 1)));
    if ( v65 != 0 )
      ++v3;
    if ( v3 >= DoubleFormat.min_exp - DoubleFormat.precision )
    {
      if ( v3 > DoubleFormat.min_exp )
      {
        if ( v3 < DoubleFormat.max_exp )
        {
          v5 = DoubleFormat.bias + v3;
          v74 &= ~0x80000000;
          v44 = DoubleFormat.exp_width / 32;
          v45 = DoubleFormat.exp_width % 32;
          v64 = 0;
          for ( j = 0; j < 3; ++j )
          {
            v58 = ~(-1 << v45) & *(&v74 + j);
            *(&v74 + j) = v64 | (*(&v74 + j) >> v45);
            v64 = v58 << (32 - v45);
          }
          v46 = 2;
          v47 = (unsigned int *)(&v76 - v44);
          do
          {
            if ( v46 < v44 )
              *(&v74 + v46) = 0;
            else
              *(&v74 + v46) = *v47;
            --v47;
            --v46;
          }
          while ( v46 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v75 = 0;
          v76 = 0;
          v74 = 0x80000000;
          v39 = DoubleFormat.exp_width / 32;
          v40 = DoubleFormat.exp_width % 32;
          v63 = 0;
          for ( k = 0; k < 3; ++k )
          {
            v41 = (int *)(&v74 + k);
            v57 = ~(-1 << v40) & *v41;
            *v41 = v63 | ((unsigned int)*v41 >> v40);
            v63 = v57 << (32 - v40);
          }
          v42 = 2;
          v43 = (unsigned int *)(&v76 - v39);
          do
          {
            if ( v42 < v39 )
              *(&v74 + v42) = 0;
            else
              *(&v74 + v42) = *v43;
            --v43;
            --v42;
          }
          while ( v42 >= 0 );
          v5 = DoubleFormat.max_exp + DoubleFormat.bias;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_78;
      }
      v74 = v71;
      v75 = v72;
      v17 = (DoubleFormat.min_exp - v53) / 32;
      v76 = v73;
      v18 = (DoubleFormat.min_exp - v53) % 32;
      v60 = 0;
      for ( m = 0; m < 3; ++m )
      {
        v19 = (int *)(&v74 + m);
        v54 = ~(-1 << v18) & *v19;
        *v19 = v60 | ((unsigned int)*v19 >> v18);
        v60 = v54 << (32 - v18);
      }
      v20 = 2;
      v21 = (unsigned int *)(&v76 - v17);
      do
      {
        if ( v20 < v17 )
          *(&v74 + v20) = 0;
        else
          *(&v74 + v20) = *v21;
        --v21;
        --v20;
      }
      while ( v20 >= 0 );
      v22 = DoubleFormat.precision - 1;
      v23 = DoubleFormat.precision / 32;
      v52 = DoubleFormat.precision / 32;
      v24 = &v74 + DoubleFormat.precision / 32;
      v55 = 31 - DoubleFormat.precision % 32;
      if ( ((1 << v55) & *v24) != 0 )
      {
        for ( n = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v74 + v23)) == 0; n; n = *(&v74 + v23) == 0 )
        {
          if ( ++v23 >= 3 )
            goto LABEL_51;
        }
        v26 = v22 / 32;
        v61 = 0;
        v27 = 1 << (31 - v22 % 32);
        v28 = &v74 + v22 / 32;
        v29 = *v28 + v27;
        if ( v29 < *v28 || v29 < v27 )
          v61 = 1;
        *v28 = v29;
        for ( ii = v61; --v26 >= 0 && ii != 0; ii = v33 )
        {
          v31 = &v74 + v26;
          v32 = *v31 + 1;
          v33 = 0;
          if ( v32 < *v31 || *v31 == -1 )
            v33 = 1;
          *v31 = v32;
        }
      }
LABEL_51:
      *v24 &= -1 << v55;
      if ( v52 + 1 < 3 )
        memset(&v74 + v52 + 1, 0, 4 * (3 - (v52 + 1)));
      v34 = (DoubleFormat.exp_width + 1) / 32;
      v35 = (DoubleFormat.exp_width + 1) % 32;
      v62 = 0;
      for ( jj = 0; jj < 3; ++jj )
      {
        v36 = (int *)(&v74 + jj);
        v56 = ~(-1 << v35) & *v36;
        *v36 = v62 | ((unsigned int)*v36 >> v35);
        v62 = v56 << (32 - v35);
      }
      v37 = 2;
      v38 = (unsigned int *)(&v76 - v34);
      do
      {
        if ( v37 < v34 )
          *(&v74 + v37) = 0;
        else
          *(&v74 + v37) = *v38;
        --v38;
        --v37;
      }
      while ( v37 >= 0 );
    }
    else
    {
      v74 = 0;
      v75 = 0;
      v76 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_78;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v74 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_78;
    }
  }
  v74 = 0;
  v75 = 0;
  v76 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_78:
  v48 = v74 | (v50 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(DoubleFormat.exp_width)));
  if ( DoubleFormat.format_width == 64 )
  {
    v49 = v75;
    HIDWORD(d->x) = v48;
    LODWORD(d->x) = v49;
  }
  else if ( DoubleFormat.format_width == 32 )
  {
    LODWORD(d->x) = v48;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473075
// Name: __ld12tof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
INTRNCVT_STATUS __cdecl _ld12tof(_LDBL12 *pld12, _CRT_FLOAT *f)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // edi
  unsigned int *v9; // esi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // edi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  int v20; // edx
  unsigned int *v21; // ecx
  int v22; // esi
  int v23; // eax
  unsigned int *v24; // ebx
  bool n; // zf
  int v26; // eax
  unsigned int v27; // edx
  unsigned int *v28; // ecx
  unsigned int v29; // edi
  int ii; // ecx
  unsigned int *v31; // ecx
  unsigned int v32; // esi
  int v33; // edi
  int v34; // eax
  int v35; // edx
  int *v36; // ebx
  int v37; // edx
  unsigned int *v38; // ecx
  int v39; // eax
  int v40; // edx
  int *v41; // ebx
  int v42; // edx
  unsigned int *v43; // ecx
  int v44; // eax
  int v45; // edx
  int v46; // edx
  unsigned int *v47; // ecx
  float v48; // ebx
  float v49; // edx
  int v50; // [esp+8h] [ebp-38h]
  char v51; // [esp+10h] [ebp-30h]
  int v52; // [esp+10h] [ebp-30h]
  int v53; // [esp+14h] [ebp-2Ch]
  int v54; // [esp+14h] [ebp-2Ch]
  char v55; // [esp+14h] [ebp-2Ch]
  int v56; // [esp+14h] [ebp-2Ch]
  int v57; // [esp+14h] [ebp-2Ch]
  int v58; // [esp+14h] [ebp-2Ch]
  int v59; // [esp+18h] [ebp-28h]
  int v60; // [esp+18h] [ebp-28h]
  int v61; // [esp+18h] [ebp-28h]
  int v62; // [esp+18h] [ebp-28h]
  int v63; // [esp+18h] [ebp-28h]
  int v64; // [esp+18h] [ebp-28h]
  int v65; // [esp+1Ch] [ebp-24h]
  unsigned int v66; // [esp+20h] [ebp-20h]
  int m; // [esp+20h] [ebp-20h]
  int jj; // [esp+20h] [ebp-20h]
  int k; // [esp+20h] [ebp-20h]
  int j; // [esp+20h] [ebp-20h]
  unsigned int v71; // [esp+24h] [ebp-1Ch]
  float v72; // [esp+28h] [ebp-18h]
  int v73; // [esp+2Ch] [ebp-14h]
  unsigned int v74; // [esp+30h] [ebp-10h] BYREF
  float v75; // [esp+34h] [ebp-Ch]
  int v76; // [esp+38h] [ebp-8h] BYREF

  v2 = *(_WORD *)&pld12->ld12[10];
  v50 = v2 & 0x8000;
  v74 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v75 = *(float *)&pld12->ld12[2];
  v76 = v4;
  if ( v3 != -16383 )
  {
    v65 = 0;
    v71 = v74;
    v72 = v75;
    v73 = v76;
    v8 = FloatFormat.precision - 1;
    v53 = v3;
    v59 = FloatFormat.precision / 32;
    v9 = &v74 + FloatFormat.precision / 32;
    v51 = 31 - FloatFormat.precision % 32;
    if ( ((1 << v51) & *v9) != 0 )
    {
      v10 = FloatFormat.precision / 32;
      for ( i = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v74 + v59)) == 0; i; i = *(&v74 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_21;
      }
      v12 = v8 / 32;
      v65 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v74 + v8 / 32;
      v66 = v13 + *v14;
      if ( v66 >= *v14 )
      {
        v15 = v66 < v13;
        goto LABEL_18;
      }
LABEL_19:
      v65 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = v66;
        if ( v12 < 0 || v65 == 0 )
          break;
        v65 = 0;
        v14 = &v74 + v12;
        v16 = *v14 + 1;
        v66 = v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
    }
LABEL_21:
    *v9 &= -1 << v51;
    if ( v59 + 1 < 3 )
      memset(&v74 + v59 + 1, 0, 4 * (3 - (v59 + 1)));
    if ( v65 != 0 )
      ++v3;
    if ( v3 >= FloatFormat.min_exp - FloatFormat.precision )
    {
      if ( v3 > FloatFormat.min_exp )
      {
        if ( v3 < FloatFormat.max_exp )
        {
          v5 = FloatFormat.bias + v3;
          v74 &= ~0x80000000;
          v44 = FloatFormat.exp_width / 32;
          v45 = FloatFormat.exp_width % 32;
          v64 = 0;
          for ( j = 0; j < 3; ++j )
          {
            v58 = ~(-1 << v45) & *(&v74 + j);
            *(&v74 + j) = v64 | (*(&v74 + j) >> v45);
            v64 = v58 << (32 - v45);
          }
          v46 = 2;
          v47 = (unsigned int *)(&v76 - v44);
          do
          {
            if ( v46 < v44 )
              *(&v74 + v46) = 0;
            else
              *(&v74 + v46) = *v47;
            --v47;
            --v46;
          }
          while ( v46 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v75 = 0.0;
          v76 = 0;
          v74 = 0x80000000;
          v39 = FloatFormat.exp_width / 32;
          v40 = FloatFormat.exp_width % 32;
          v63 = 0;
          for ( k = 0; k < 3; ++k )
          {
            v41 = (int *)(&v74 + k);
            v57 = ~(-1 << v40) & *v41;
            *v41 = v63 | ((unsigned int)*v41 >> v40);
            v63 = v57 << (32 - v40);
          }
          v42 = 2;
          v43 = (unsigned int *)(&v76 - v39);
          do
          {
            if ( v42 < v39 )
              *(&v74 + v42) = 0;
            else
              *(&v74 + v42) = *v43;
            --v43;
            --v42;
          }
          while ( v42 >= 0 );
          v5 = FloatFormat.max_exp + FloatFormat.bias;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_78;
      }
      v74 = v71;
      v75 = v72;
      v17 = (FloatFormat.min_exp - v53) / 32;
      v76 = v73;
      v18 = (FloatFormat.min_exp - v53) % 32;
      v60 = 0;
      for ( m = 0; m < 3; ++m )
      {
        v19 = (int *)(&v74 + m);
        v54 = ~(-1 << v18) & *v19;
        *v19 = v60 | ((unsigned int)*v19 >> v18);
        v60 = v54 << (32 - v18);
      }
      v20 = 2;
      v21 = (unsigned int *)(&v76 - v17);
      do
      {
        if ( v20 < v17 )
          *(&v74 + v20) = 0;
        else
          *(&v74 + v20) = *v21;
        --v21;
        --v20;
      }
      while ( v20 >= 0 );
      v22 = FloatFormat.precision - 1;
      v23 = FloatFormat.precision / 32;
      v52 = FloatFormat.precision / 32;
      v24 = &v74 + FloatFormat.precision / 32;
      v55 = 31 - FloatFormat.precision % 32;
      if ( ((1 << v55) & *v24) != 0 )
      {
        for ( n = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v74 + v23)) == 0; n; n = *(&v74 + v23) == 0 )
        {
          if ( ++v23 >= 3 )
            goto LABEL_51;
        }
        v26 = v22 / 32;
        v61 = 0;
        v27 = 1 << (31 - v22 % 32);
        v28 = &v74 + v22 / 32;
        v29 = *v28 + v27;
        if ( v29 < *v28 || v29 < v27 )
          v61 = 1;
        *v28 = v29;
        for ( ii = v61; --v26 >= 0 && ii != 0; ii = v33 )
        {
          v31 = &v74 + v26;
          v32 = *v31 + 1;
          v33 = 0;
          if ( v32 < *v31 || *v31 == -1 )
            v33 = 1;
          *v31 = v32;
        }
      }
LABEL_51:
      *v24 &= -1 << v55;
      if ( v52 + 1 < 3 )
        memset(&v74 + v52 + 1, 0, 4 * (3 - (v52 + 1)));
      v34 = (FloatFormat.exp_width + 1) / 32;
      v35 = (FloatFormat.exp_width + 1) % 32;
      v62 = 0;
      for ( jj = 0; jj < 3; ++jj )
      {
        v36 = (int *)(&v74 + jj);
        v56 = ~(-1 << v35) & *v36;
        *v36 = v62 | ((unsigned int)*v36 >> v35);
        v62 = v56 << (32 - v35);
      }
      v37 = 2;
      v38 = (unsigned int *)(&v76 - v34);
      do
      {
        if ( v37 < v34 )
          *(&v74 + v37) = 0;
        else
          *(&v74 + v37) = *v38;
        --v38;
        --v37;
      }
      while ( v37 >= 0 );
    }
    else
    {
      v74 = 0;
      v75 = 0.0;
      v76 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_78;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v74 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_78;
    }
  }
  v74 = 0;
  v75 = 0.0;
  v76 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_78:
  LODWORD(v48) = v74 | (v50 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(FloatFormat.exp_width)));
  if ( FloatFormat.format_width == 64 )
  {
    v49 = v75;
    f[1].f = v48;
    f->f = v49;
  }
  else if ( FloatFormat.format_width == 32 )
  {
    f->f = v48;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004735C6
// Name: __wchartodigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wchartodigit(wchar_t ch)
{
  int v2; // ecx
  wchar_t v3; // dx

  if ( ch < 0x30u )
    return -1;
  if ( ch < 0x3Au )
    return ch - 48;
  v2 = 65296;
  if ( ch >= 0xFF10u )
  {
    v3 = -230;
LABEL_39:
    if ( ch < v3 )
      return ch - v2;
    return -1;
  }
  v2 = 1632;
  if ( ch >= 0x660u )
  {
    if ( ch < 0x66Au )
      return ch - v2;
    v2 = 1776;
    if ( ch >= 0x6F0u )
    {
      if ( ch < 0x6FAu )
        return ch - v2;
      v2 = 2406;
      if ( ch >= 0x966u )
      {
        if ( ch < 0x970u )
          return ch - v2;
        v2 = 2534;
        if ( ch >= 0x9E6u )
        {
          if ( ch < 0x9F0u )
            return ch - v2;
          v2 = 2662;
          if ( ch >= 0xA66u )
          {
            if ( ch < 0xA70u )
              return ch - v2;
            v2 = 2790;
            if ( ch >= 0xAE6u )
            {
              if ( ch < 0xAF0u )
                return ch - v2;
              v2 = 2918;
              if ( ch >= 0xB66u )
              {
                if ( ch < 0xB70u )
                  return ch - v2;
                v2 = 3174;
                if ( ch >= 0xC66u )
                {
                  if ( ch < 0xC70u )
                    return ch - v2;
                  v2 = 3302;
                  if ( ch >= 0xCE6u )
                  {
                    if ( ch < 0xCF0u )
                      return ch - v2;
                    v2 = 3430;
                    if ( ch >= 0xD66u )
                    {
                      if ( ch < 0xD70u )
                        return ch - v2;
                      v2 = 3664;
                      if ( ch >= 0xE50u )
                      {
                        if ( ch < 0xE5Au )
                          return ch - v2;
                        v2 = 3792;
                        if ( ch >= 0xED0u )
                        {
                          if ( ch < 0xEDAu )
                            return ch - v2;
                          v2 = 3872;
                          if ( ch >= 0xF20u )
                          {
                            if ( ch < 0xF2Au )
                              return ch - v2;
                            v2 = 4160;
                            if ( ch >= 0x1040u )
                            {
                              if ( ch < 0x104Au )
                                return ch - v2;
                              v2 = 6112;
                              if ( ch >= 0x17E0u )
                              {
                                if ( ch < 0x17EAu )
                                  return ch - v2;
                                v2 = 6160;
                                if ( ch >= 0x1810u )
                                {
                                  v3 = 6170;
                                  goto LABEL_39;
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
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00473766
// Name: __fgetwc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __cdecl _fgetwc_nolock(_iobuf *stream)
{
  unsigned __int16 **v1; // esi
  ioinfo **v2; // edi
  ioinfo *v3; // eax
  bool v4; // sf
  int v5; // eax
  int v7; // eax
  ioinfo **v8; // edi
  ioinfo *v9; // eax
  unsigned int v10; // edi
  int v11; // eax
  int v12; // eax
  char mbc[4]; // [esp+Ch] [ebp-4h] BYREF

  v1 = (unsigned __int16 **)stream;
  if ( (stream->_flag & 0x40) == 0 )
  {
    if ( fileno(stream) == -1 || fileno(stream: (_iobuf *)v1) == -2 )
    {
      v3 = &__badioinfo;
    }
    else
    {
      v2 = &__pioinfo[fileno(stream: (_iobuf *)v1) >> 5];
      v3 = &(*v2)[fileno(stream: (_iobuf *)v1) & 0x1F];
    }
    if ( (*((_BYTE *)v3 + 36) & 0x7F) != 0 )
    {
      v4 = (int)v1[1] - 1 < 0;
      v1[1] = (unsigned __int16 *)((char *)v1[1] - 1);
      if ( v4 )
      {
        v5 = _filbuf(str: (_iobuf *)v1);
      }
      else
      {
        v5 = *(unsigned __int8 *)*v1;
        *v1 = (unsigned __int16 *)((char *)*v1 + 1);
      }
      if ( v5 != -1 )
      {
        v4 = (int)v1[1] - 1 < 0;
        v1[1] = (unsigned __int16 *)((char *)v1[1] - 1);
        LOBYTE(stream) = v5;
        if ( v4 )
        {
          v7 = _filbuf(str: (_iobuf *)v1);
        }
        else
        {
          v7 = *(unsigned __int8 *)*v1;
          *v1 = (unsigned __int16 *)((char *)*v1 + 1);
        }
        if ( v7 != -1 )
        {
          BYTE1(stream) = v7;
          return (unsigned __int16)stream;
        }
      }
      return -1;
    }
    if ( ((_BYTE)v1[3] & 0x40) == 0 )
    {
      if ( fileno(stream: (_iobuf *)v1) == -1 || fileno(stream: (_iobuf *)v1) == -2 )
      {
        v9 = &__badioinfo;
      }
      else
      {
        v8 = &__pioinfo[fileno(stream: (_iobuf *)v1) >> 5];
        v9 = &(*v8)[fileno(stream: (_iobuf *)v1) & 0x1F];
      }
      if ( v9->osfile < 0 )
      {
        v10 = 1;
        v4 = (int)v1[1] - 1 < 0;
        v1[1] = (unsigned __int16 *)((char *)v1[1] - 1);
        if ( v4 )
        {
          v11 = _filbuf(str: (_iobuf *)v1);
        }
        else
        {
          v11 = *(unsigned __int8 *)*v1;
          *v1 = (unsigned __int16 *)((char *)*v1 + 1);
        }
        if ( v11 == -1 )
          return -1;
        mbc[0] = v11;
        if ( isleadbyte(c: v11) != 0 )
        {
          v4 = (int)v1[1] - 1 < 0;
          v1[1] = (unsigned __int16 *)((char *)v1[1] - 1);
          if ( v4 )
          {
            v12 = _filbuf(str: (_iobuf *)v1);
          }
          else
          {
            v12 = *(unsigned __int8 *)*v1;
            *v1 = (unsigned __int16 *)((char *)*v1 + 1);
          }
          if ( v12 == -1 )
          {
            ungetc(ch: mbc[0], stream: (_iobuf *)v1);
            return -1;
          }
          mbc[1] = v12;
          v10 = 2;
        }
        if ( mbtowc(pwc: (wchar_t *)&stream, s: mbc, n: v10) != -1 )
          return (unsigned __int16)stream;
        *_errno() = 42;
        return -1;
      }
    }
  }
  v4 = (int)--v1[1] < 0;
  if ( v4 )
    return _filwbuf(str: (_iobuf *)v1);
  return *(*v1)++;
}

//------------------------------------------------------------------------------
// Address: 0x00473911
// Name: __ungetwc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _ungetwc_nolock(wchar_t ch, _iobuf *str)
{
  wchar_t v2; // bx
  int flag; // eax
  ioinfo **v4; // edi
  ioinfo *v5; // eax
  ioinfo **v6; // edi
  ioinfo *v7; // eax
  wchar_t v8; // dx
  int v9; // eax
  char *v10; // ecx
  int v11; // ecx
  char *v13; // eax
  char *ptr; // eax
  int v15; // eax
  int size; // [esp+Ch] [ebp-10h] BYREF
  char mbc[8]; // [esp+10h] [ebp-Ch] BYREF

  v2 = ch;
  if ( ch == 0xFFFF )
    return -1;
  flag = str->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( str->_base == nullptr )
    _getbuf(str);
  if ( (str->_flag & 0x40) != 0 )
  {
LABEL_30:
    v13 = str->_base + 2;
    if ( str->_ptr < v13 )
    {
      if ( str->_cnt != 0 || str->_bufsiz < 2u )
        return -1;
      str->_ptr = v13;
    }
    str->_ptr -= 2;
    ptr = str->_ptr;
    if ( (str->_flag & 0x40) != 0 )
    {
      if ( *(_WORD *)ptr != v2 )
      {
        str->_ptr = ptr + 2;
        return -1;
      }
    }
    else
    {
      *(_WORD *)ptr = v2;
    }
    v15 = str->_flag;
    str->_cnt += 2;
    str->_flag = v15 & 0xFFFFFFEE | 1;
    return v2;
  }
  if ( fileno(stream: str) == -1 || fileno(stream: str) == -2 )
  {
    v5 = &__badioinfo;
  }
  else
  {
    v4 = &__pioinfo[fileno(stream: str) >> 5];
    v5 = &(*v4)[fileno(stream: str) & 0x1F];
  }
  if ( v5->osfile >= 0 )
  {
    v2 = ch;
    goto LABEL_30;
  }
  if ( fileno(stream: str) == -1 || fileno(stream: str) == -2 )
  {
    v7 = &__badioinfo;
  }
  else
  {
    v6 = &__pioinfo[fileno(stream: str) >> 5];
    v7 = &(*v6)[fileno(stream: str) & 0x1F];
  }
  if ( (*((_BYTE *)v7 + 36) & 0x7F) != 0 )
  {
    v8 = ch;
    v9 = 2;
    *(_WORD *)mbc = ch;
    size = 2;
  }
  else
  {
    if ( wctomb_s(pRetValue: &size, dst: mbc, sizeInBytes: 5u, wchar: ch) != 0 )
      return -1;
    v9 = size;
    v8 = ch;
  }
  v10 = &str->_base[v9];
  if ( str->_ptr < v10 )
  {
    if ( str->_cnt == 0 && v9 <= str->_bufsiz )
    {
      str->_ptr = v10;
      goto LABEL_25;
    }
    return -1;
  }
LABEL_25:
  v11 = v9 - 1;
  if ( v9 - 1 >= 0 )
  {
    do
      *--str->_ptr = mbc[v11--];
    while ( v11 >= 0 );
    v9 = size;
  }
  str->_cnt += v9;
  str->_flag = str->_flag & 0xFFFFFFEE | 1;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00473ACB
// Name: __wcstombs_l_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _wcstombs_l_helper(char *s, const wchar_t *pwcs, unsigned int n, localeinfo_struct *plocinfo)
{
  const wchar_t *v4; // esi
  unsigned int result; // eax
  threadlocaleinfostruct *locinfo; // edi
  __int16 v7; // cx
  unsigned int v8; // ecx
  const wchar_t *v9; // eax
  unsigned int v10; // eax
  int v11; // edx
  int v12; // ecx
  char v13; // cl
  WCHAR v14; // cx
  const wchar_t *v15; // edx
  int retval; // [esp+Ch] [ebp-30h]
  int i; // [esp+10h] [ebp-2Ch]
  unsigned int count; // [esp+18h] [ebp-24h]
  _LocaleUpdate _loc_update; // [esp+1Ch] [ebp-20h] BYREF
  int defused; // [esp+2Ch] [ebp-10h] BYREF
  char buffer[8]; // [esp+30h] [ebp-Ch] BYREF

  v4 = pwcs;
  defused = 0;
  if ( s != nullptr && n == 0 )
    return 0;
  if ( pwcs == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( s == nullptr )
  {
    if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
    {
      v14 = *pwcs;
      result = 0;
      v15 = pwcs;
      while ( v14 != 0 )
      {
        if ( v14 > 0xFFu )
          goto LABEL_50;
        ++result;
        v14 = *++v15;
      }
      goto LABEL_12;
    }
    result = WideCharToMultiByte(
               CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
               dwFlags: 0,
               lpWideCharStr: pwcs,
               cchWideChar: -1,
               lpMultiByteStr: nullptr,
               cbMultiByte: 0,
               lpDefaultChar: nullptr,
               lpUsedDefaultChar: &defused);
    if ( result == 0 )
      goto LABEL_50;
    goto LABEL_27;
  }
  locinfo = _loc_update.localeinfo.locinfo;
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    result = 0;
    if ( n != 0 )
    {
      while ( *v4 <= 0xFFu )
      {
        s[result] = *(_BYTE *)v4;
        v7 = *v4++;
        if ( v7 != 0 && ++result < n )
          continue;
        goto LABEL_12;
      }
      goto LABEL_50;
    }
    goto LABEL_12;
  }
  if ( _loc_update.localeinfo.locinfo->mb_cur_max == 1 )
  {
    v8 = n;
    if ( n != 0 )
    {
      v9 = pwcs;
      do
      {
        if ( *v9 == 0 )
          break;
        ++v9;
        --v8;
      }
      while ( v8 != 0 );
      if ( v8 != 0 && *v9 == 0 )
        n = v9 - pwcs + 1;
    }
    result = WideCharToMultiByte(
               CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
               dwFlags: 0,
               lpWideCharStr: pwcs,
               cchWideChar: n,
               lpMultiByteStr: s,
               cbMultiByte: n,
               lpDefaultChar: nullptr,
               lpUsedDefaultChar: &defused);
    if ( result != 0 && defused == 0 )
    {
      if ( s[result - 1] != 0 )
        goto LABEL_12;
      goto LABEL_28;
    }
    goto LABEL_50;
  }
  result = WideCharToMultiByte(
             CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
             dwFlags: 0,
             lpWideCharStr: pwcs,
             cchWideChar: -1,
             lpMultiByteStr: s,
             cbMultiByte: n,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused);
  count = result;
  if ( result != 0 )
  {
LABEL_27:
    if ( defused == 0 )
    {
LABEL_28:
      --result;
LABEL_12:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
LABEL_50:
    *_errno() = 42;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return -1;
  }
  if ( defused != 0 || GetLastError() != 122 )
    goto LABEL_50;
  if ( n != 0 )
  {
    do
    {
      v10 = WideCharToMultiByte(
              CodePage: locinfo->lc_codepage,
              dwFlags: 0,
              lpWideCharStr: v4,
              cchWideChar: 1,
              lpMultiByteStr: buffer,
              cbMultiByte: locinfo->mb_cur_max,
              lpDefaultChar: nullptr,
              lpUsedDefaultChar: &defused);
      v11 = v10;
      retval = v10;
      if ( v10 == 0 || defused != 0 || v10 > 5 )
        goto LABEL_50;
      result = count;
      if ( v11 + count > n )
        goto LABEL_12;
      v12 = 0;
      i = 0;
      if ( v11 > 0 )
      {
        do
        {
          v13 = buffer[v12];
          s[result] = v13;
          if ( v13 == 0 )
            goto LABEL_12;
          v12 = i + 1;
          ++result;
          i = v12;
          count = result;
        }
        while ( v12 < retval );
      }
      ++v4;
    }
    while ( result < n );
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x00473D32
// Name: __wcstombs_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcstombs_s_l(
        unsigned int *pConvertedChars,
        char *dst,
        unsigned int sizeInBytes,
        const wchar_t *src,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  unsigned int v6; // eax
  unsigned int v7; // eax
  int *v9; // eax
  unsigned int v10; // eax
  int v11; // [esp-4h] [ebp-14h]
  int retvalue; // [esp+Ch] [ebp-4h]

  retvalue = 0;
  if ( dst != nullptr )
  {
    if ( sizeInBytes != 0 )
      goto LABEL_3;
LABEL_15:
    v9 = _errno();
    v11 = 22;
LABEL_16:
    *v9 = v11;
    _invalid_parameter_noinfo();
    return v11;
  }
  if ( sizeInBytes != 0 )
    goto LABEL_15;
LABEL_3:
  if ( dst != nullptr )
    *dst = 0;
  if ( pConvertedChars != nullptr )
    *pConvertedChars = 0;
  v6 = n;
  if ( n > sizeInBytes )
    v6 = sizeInBytes;
  if ( v6 > 0x7FFFFFFF )
    goto LABEL_15;
  v7 = _wcstombs_l_helper(s: dst, pwcs: src, n: v6, plocinfo);
  if ( v7 == -1 )
  {
    if ( dst != nullptr )
      *dst = 0;
    return *_errno();
  }
  v10 = v7 + 1;
  if ( dst != nullptr )
  {
    if ( v10 > sizeInBytes )
    {
      if ( n != -1 )
      {
        *dst = 0;
        if ( sizeInBytes <= v10 )
        {
          v9 = _errno();
          v11 = 34;
          goto LABEL_16;
        }
      }
      v10 = sizeInBytes;
      retvalue = 80;
    }
    dst[v10 - 1] = 0;
  }
  if ( pConvertedChars != nullptr )
    *pConvertedChars = v10;
  return retvalue;
}

//------------------------------------------------------------------------------
// Address: 0x00473DE4
// Name: _wcstombs_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcstombs_s(
        unsigned int *pConvertedChars,
        char *dst,
        unsigned int sizeInBytes,
        const wchar_t *src,
        unsigned int n)
{
  return _wcstombs_s_l(pConvertedChars, dst, sizeInBytes, src, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00473E04
// Name: ___mtold12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __mtold12(char *manptr, unsigned int manlen, _LDBL12 *ld12)
{
  __int64 v4; // rcx
  _LDBL12 *v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // ebx
  int v8; // edx
  unsigned int v9; // edi
  unsigned int v10; // esi
  int v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  int v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // esi
  unsigned int v17; // esi
  int v18; // edx
  unsigned int v19; // edx
  unsigned int v20; // edi
  int v21; // ecx
  int v22; // edi
  unsigned int v23; // ecx
  __int64 v24; // kr10_8
  unsigned int tmp; // [esp+Ch] [ebp-18h]
  unsigned int tmp_4; // [esp+10h] [ebp-14h]
  int tmp_8; // [esp+14h] [ebp-10h]
  int v28; // [esp+18h] [ebp-Ch]
  unsigned int v29; // [esp+1Ch] [ebp-8h]
  int v30; // [esp+1Ch] [ebp-8h]
  __int16 expn; // [esp+20h] [ebp-4h]
  _LDBL12 *ld12a; // [esp+34h] [ebp+10h]
  int ld12b; // [esp+34h] [ebp+10h]
  int ld12c; // [esp+34h] [ebp+10h]
  int ld12d; // [esp+34h] [ebp+10h]

  HIDWORD(v4) = 0;
  expn = 16462;
  *(_DWORD *)ld12->ld12 = 0;
  *(_DWORD *)&ld12->ld12[4] = 0;
  *(_DWORD *)&ld12->ld12[8] = 0;
  if ( manlen != 0 )
  {
    ld12a = nullptr;
    do
    {
      tmp = *(_DWORD *)ld12->ld12;
      __SET_PAIR__(tmp_4, v4, *(_QWORD *)ld12->ld12);
      tmp_8 = *(_DWORD *)&ld12->ld12[8];
      v5 = ld12a;
      ld12b = 0;
      v6 = HIDWORD(v4);
      v7 = v4 >> 31;
      v8 = (v6 >> 31) | (2 * (_DWORD)v5);
      v9 = __SPAIR64__(v7, 2 * *(_DWORD *)ld12->ld12) >> 31;
      v29 = v9;
      v10 = 4 * *(_DWORD *)ld12->ld12;
      v11 = (v7 >> 31) | (2 * v8);
      v12 = 5 * *(_DWORD *)ld12->ld12;
      *(_DWORD *)ld12->ld12 = v10;
      *(_DWORD *)&ld12->ld12[4] = v9;
      *(_DWORD *)&ld12->ld12[8] = v11;
      if ( v12 < v10 || v12 < tmp )
        ld12b = 1;
      *(_DWORD *)ld12->ld12 = v12;
      if ( ld12b != 0 )
      {
        ld12c = 0;
        ++v9;
        if ( v29 + 1 < v29 || v29 == -1 )
          ld12c = 1;
        *(_DWORD *)&ld12->ld12[4] = v9;
        if ( ld12c != 0 )
          *(_DWORD *)&ld12->ld12[8] = ++v11;
      }
      ld12d = 0;
      v13 = v9 + tmp_4;
      if ( v9 + tmp_4 < v9 || v13 < tmp_4 )
        ld12d = 1;
      *(_DWORD *)&ld12->ld12[4] = v13;
      if ( ld12d != 0 )
        *(_DWORD *)&ld12->ld12[8] = ++v11;
      v30 = 0;
      v14 = (v13 >> 31) | (2 * (tmp_8 + v11));
      __SET_PAIR__(v16, v15, 2LL * v12);
      HIDWORD(v4) = v16 | (2 * v13);
      *(_DWORD *)&ld12->ld12[8] = v14;
      v28 = v14;
      ld12a = (_LDBL12 *)v14;
      *(_DWORD *)ld12->ld12 = v15;
      *(_DWORD *)&ld12->ld12[4] = HIDWORD(v4);
      v17 = *manptr;
      LODWORD(v4) = v15 + v17;
      if ( v15 + v17 < v15 || (unsigned int)v4 < v17 )
        v30 = 1;
      *(_DWORD *)ld12->ld12 = v4;
      if ( v30 != 0 )
      {
        LODWORD(v4) = HIDWORD(v4) + 1;
        v18 = 0;
        if ( (unsigned int)(HIDWORD(v4) + 1) < HIDWORD(v4) || HIDWORD(v4) == -1 )
          v18 = 1;
        ++HIDWORD(v4);
        *(_DWORD *)&ld12->ld12[4] = v4;
        if ( v18 != 0 )
        {
          ld12a = (_LDBL12 *)(v28 + 1);
          *(_DWORD *)&ld12->ld12[8] = v28 + 1;
        }
      }
      --manlen;
      ++manptr;
      *(_DWORD *)&ld12->ld12[4] = HIDWORD(v4);
      *(_DWORD *)&ld12->ld12[8] = ld12a;
    }
    while ( manlen != 0 );
  }
  if ( *(_DWORD *)&ld12->ld12[8] == 0 )
  {
    v19 = *(_DWORD *)&ld12->ld12[4];
    do
    {
      expn -= 16;
      v20 = HIWORD(v19);
      v19 = HIWORD(*(_DWORD *)ld12->ld12) | (v19 << 16);
      v21 = *(_DWORD *)ld12->ld12 << 16;
      *(_DWORD *)&ld12->ld12[4] = v19;
      *(_DWORD *)ld12->ld12 = v21;
    }
    while ( v20 == 0 );
    *(_DWORD *)&ld12->ld12[8] = v20;
  }
  v22 = *(_DWORD *)&ld12->ld12[8];
  if ( (v22 & 0x8000) == 0 )
  {
    v23 = *(_DWORD *)&ld12->ld12[4];
    do
    {
      --expn;
      v22 = (v23 >> 31) | (2 * v22);
      v24 = 2LL * *(unsigned int *)ld12->ld12;
      v23 = HIDWORD(v24) | (2 * v23);
      *(_DWORD *)ld12->ld12 = v24;
      *(_DWORD *)&ld12->ld12[4] = v23;
      *(_DWORD *)&ld12->ld12[8] = v22;
    }
    while ( (v22 & 0x8000) == 0 );
  }
  *(_WORD *)&ld12->ld12[10] = expn;
}

//------------------------------------------------------------------------------
// Address: 0x00473FE8
// Name: _$I10_OUTPUT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _I10_OUTPUT(_LDOUBLE ld, int ndigits, char output_flags, _FloatOutStruct *fos)
{
  unsigned __int16 v4; // dx
  int v6; // eax
  int v7; // eax
  __int16 v8; // ax
  int v9; // ebx
  bool v10; // zf
  char v11; // cl
  int v12; // ecx
  _LDBL12 *p_tmp12; // eax
  unsigned __int8 *v14; // esi
  __int16 v15; // cx
  unsigned __int16 v16; // di
  _WORD *v17; // esi
  unsigned int v18; // edx
  unsigned int v19; // ecx
  unsigned int v20; // eax
  __int16 v21; // di
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  unsigned int v25; // ecx
  int v26; // esi
  int v27; // ecx
  unsigned __int16 v28; // si
  int v29; // eax
  _WORD *v30; // edi
  unsigned __int8 *v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ebx
  __int16 v35; // si
  unsigned int v36; // ecx
  unsigned int v37; // edx
  int v38; // eax
  unsigned int v39; // ecx
  int v40; // edi
  int v41; // ecx
  int v42; // edi
  int v43; // esi
  unsigned int v44; // eax
  int v45; // ebx
  int v46; // eax
  int v47; // esi
  int v48; // eax
  int v49; // ebx
  int v50; // eax
  char *man; // ebx
  unsigned int v52; // edx
  unsigned int v53; // edi
  unsigned int v54; // ecx
  int v55; // esi
  int v56; // ecx
  unsigned int v57; // esi
  unsigned int v58; // edi
  int v59; // edx
  unsigned int v60; // edx
  char v61; // al
  char *v62; // ebx
  _FloatOutStruct *v63; // eax
  char v64; // bl
  unsigned __int8 *v65; // [esp+10h] [ebp-70h]
  unsigned __int8 *v66; // [esp+14h] [ebp-6Ch]
  _LDBL12 *v67; // [esp+18h] [ebp-68h]
  __int16 sign; // [esp+20h] [ebp-60h]
  int v69; // [esp+24h] [ebp-5Ch]
  __int16 v70; // [esp+24h] [ebp-5Ch]
  __int16 v71; // [esp+28h] [ebp-58h]
  unsigned __int8 *v72; // [esp+28h] [ebp-58h]
  int v73; // [esp+2Ch] [ebp-54h]
  int v74; // [esp+2Ch] [ebp-54h]
  int v75; // [esp+30h] [ebp-50h]
  int v76; // [esp+30h] [ebp-50h]
  __int16 digcount; // [esp+34h] [ebp-4Ch]
  int digcounta; // [esp+34h] [ebp-4Ch]
  int v79; // [esp+38h] [ebp-48h]
  int v80; // [esp+38h] [ebp-48h]
  _LDBL12 *v81; // [esp+3Ch] [ebp-44h]
  int v82; // [esp+3Ch] [ebp-44h]
  int v83; // [esp+3Ch] [ebp-44h]
  unsigned int v84; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  int j; // [esp+40h] [ebp-40h]
  char *v87; // [esp+40h] [ebp-40h]
  _LDBL12 tmp12; // [esp+44h] [ebp-3Ch] BYREF
  _LDBL12 ld12_one_tenth; // [esp+50h] [ebp-30h] BYREF
  _LDBL12 ld12; // [esp+60h] [ebp-20h] BYREF
  _BYTE v91[12]; // [esp+70h] [ebp-10h] BYREF

  sign = *(_WORD *)&ld.ld[8] & 0x8000;
  v4 = *(_WORD *)&ld.ld[8] & 0x7FFF;
  memset(&ld12_one_tenth, 204, 8);
  *(_DWORD *)&ld12_one_tenth.ld12[8] = 1073466572;
  if ( *(__int16 *)&ld.ld[8] >= 0 )
    fos->sign = 32;
  else
    fos->sign = 45;
  if ( v4 != 0 )
  {
    if ( v4 != 0x7FFF )
      goto LABEL_28;
    fos->exp = 1;
    if ( (*(_DWORD *)&ld.ld[4] != 0x80000000 || *(_DWORD *)ld.ld != 0) && (*(_DWORD *)&ld.ld[4] & 0x40000000) == 0 )
    {
      v6 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#SNAN");
      goto LABEL_25;
    }
    if ( sign != 0 && *(_DWORD *)&ld.ld[4] == -1073741824 )
    {
      if ( *(_DWORD *)ld.ld == 0 )
      {
        v7 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#IND");
        goto LABEL_22;
      }
    }
    else if ( *(_DWORD *)&ld.ld[4] == 0x80000000 && *(_DWORD *)ld.ld == 0 )
    {
      v7 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#INF");
LABEL_22:
      if ( v7 == 0 )
      {
        fos->ManLen = 5;
        return 0;
      }
LABEL_14:
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    }
    v6 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#QNAN");
LABEL_25:
    if ( v6 == 0 )
    {
      fos->ManLen = 6;
      return 0;
    }
    goto LABEL_14;
  }
  if ( *(_DWORD *)&ld.ld[4] == 0 && *(_DWORD *)ld.ld == 0 )
  {
    fos->exp = 0;
    fos->sign = sign != -32768 ? 32 : 45;
    *(_WORD *)&fos->ManLen = 12289;
    fos->man[1] = 0;
    return 1;
  }
LABEL_28:
  v8 = (77 * (HIBYTE(v4) + 2 * ld.ld[7]) + 19728 * (unsigned int)v4 - 323162868) >> 16;
  *(_WORD *)ld12.ld12 = 0;
  v9 = -v8;
  digcount = v8;
  *(_WORD *)&ld12.ld12[10] = *(_WORD *)&ld.ld[8] & 0x7FFF;
  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&ld.ld[4];
  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)ld.ld;
  v67 = &_pow10pos[-8];
  if ( v8 != 0 )
  {
    v10 = v8 == 0;
    if ( v8 > 0 )
    {
      v9 = v8;
      v67 = &_pow10neg[-8];
      v10 = v8 == 0;
    }
    if ( !v10 )
    {
      do
      {
        v67 += 7;
        v11 = v9;
        v9 >>= 3;
        v12 = v11 & 7;
        if ( v12 != 0 )
        {
          p_tmp12 = &v67[v12];
          v81 = p_tmp12;
          if ( *(_WORD *)p_tmp12->ld12 >= 0x8000u )
          {
            *(_DWORD *)tmp12.ld12 = *(_DWORD *)p_tmp12->ld12;
            *(_DWORD *)&tmp12.ld12[4] = *(_DWORD *)&p_tmp12->ld12[4];
            v14 = &p_tmp12->ld12[8];
            p_tmp12 = &tmp12;
            *(_DWORD *)&tmp12.ld12[8] = *(_DWORD *)v14;
            --*(_DWORD *)&tmp12.ld12[2];
            v81 = &tmp12;
          }
          v79 = 0;
          memset(v91, 0, sizeof(v91));
          v71 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&p_tmp12->ld12[10]) & 0x8000;
          v15 = *(_WORD *)&p_tmp12->ld12[10] & 0x7FFF;
          v16 = v15 + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
          if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
            || (*(_WORD *)&p_tmp12->ld12[10] & 0x7FFF) == 0x7FFF
            || v16 > 0xBFFDu )
          {
            *(_DWORD *)&ld12.ld12[8] = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&p_tmp12->ld12[10]) & 0x8000u) == 0
                                     ? 2147450880
                                     : -32768;
          }
          else
          {
            if ( v16 > 0x3FBFu )
            {
              if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
              {
                ++v16;
                if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0
                  && *(_DWORD *)&ld12.ld12[4] == 0
                  && *(_DWORD *)ld12.ld12 == 0 )
                {
                  *(_WORD *)&ld12.ld12[10] = 0;
                  continue;
                }
              }
              if ( v15 != 0
                || (++v16, (*(_DWORD *)&p_tmp12->ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&p_tmp12->ld12[4] != 0
                || *(_DWORD *)p_tmp12->ld12 != 0 )
              {
                v73 = 0;
                v17 = &v91[4];
                for ( i = 5; i > 0; --i )
                {
                  v75 = i;
                  v65 = &ld12.ld12[2 * v73];
                  v66 = &p_tmp12->ld12[8];
                  do
                  {
                    v18 = *((_DWORD *)v17 - 1);
                    v19 = *(unsigned __int16 *)v66 * *(unsigned __int16 *)v65;
                    v69 = 0;
                    v20 = v18 + v19;
                    if ( v18 + v19 < v18 || v20 < v19 )
                      v69 = 1;
                    *((_DWORD *)v17 - 1) = v20;
                    if ( v69 != 0 )
                      ++*v17;
                    v65 += 2;
                    v66 -= 2;
                    --v75;
                  }
                  while ( v75 > 0 );
                  p_tmp12 = v81;
                  ++v17;
                  ++v73;
                }
                v21 = v16 - 16382;
                if ( v21 <= 0 )
                  goto LABEL_172;
                do
                {
                  if ( *(int *)&v91[8] < 0 )
                    break;
                  v22 = *(_DWORD *)v91;
                  *(_DWORD *)v91 *= 2;
                  v23 = *(_DWORD *)&v91[4];
                  *(_DWORD *)&v91[4] = (v22 >> 31) | (2 * *(_DWORD *)&v91[4]);
                  --v21;
                  *(_DWORD *)&v91[8] = (v23 >> 31) | (2 * *(_DWORD *)&v91[8]);
                }
                while ( v21 > 0 );
                if ( v21 <= 0 )
                {
LABEL_172:
                  if ( --v21 < 0 )
                  {
                    v24 = (unsigned __int16)-v21;
                    v21 = 0;
                    do
                    {
                      if ( (v91[0] & 1) != 0 )
                        ++v79;
                      v25 = *(_DWORD *)&v91[8];
                      *(_DWORD *)&v91[8] >>= 1;
                      v26 = __SPAIR64__(v25, *(unsigned int *)&v91[4]) >> 1;
                      v27 = *(__int64 *)v91 >> 1;
                      --v24;
                      *(_DWORD *)&v91[4] = v26;
                      *(_DWORD *)v91 = v27;
                    }
                    while ( v24 != 0 );
                    if ( v79 != 0 )
                      *(_WORD *)v91 |= 1u;
                  }
                }
                if ( *(_WORD *)v91 > 0x8000u || (*(_DWORD *)v91 & 0x1FFFF) == 0x18000 )
                {
                  if ( *(_DWORD *)&v91[2] == -1 )
                  {
                    *(_DWORD *)&v91[2] = 0;
                    if ( *(_DWORD *)&v91[6] == -1 )
                    {
                      *(_DWORD *)&v91[6] = 0;
                      if ( *(_WORD *)&v91[10] == 0xFFFF )
                      {
                        *(_WORD *)&v91[10] = 0x8000;
                        ++v21;
                      }
                      else
                      {
                        ++*(_WORD *)&v91[10];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v91[6];
                    }
                  }
                  else
                  {
                    ++*(_DWORD *)&v91[2];
                  }
                }
                if ( (unsigned __int16)v21 < 0x7FFFu )
                {
                  *(_WORD *)ld12.ld12 = *(_WORD *)&v91[2];
                  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v91[4];
                  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v91[8];
                  *(_WORD *)&ld12.ld12[10] = v71 | v21;
                }
                else
                {
                  *(_DWORD *)&ld12.ld12[4] = 0;
                  *(_DWORD *)ld12.ld12 = 0;
                  *(_DWORD *)&ld12.ld12[8] = v71 == 0 ? 2147450880 : -32768;
                }
                continue;
              }
            }
            *(_DWORD *)&ld12.ld12[8] = 0;
          }
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
        }
      }
      while ( v9 != 0 );
    }
  }
  if ( *(_WORD *)&ld12.ld12[10] < 0x3FFFu )
    goto LABEL_134;
  ++digcount;
  v76 = 0;
  memset(v91, 0, sizeof(v91));
  v70 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000;
  v28 = (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
  if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
    || (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) == 0x7FFF
    || v28 > 0xBFFDu )
  {
    *(_DWORD *)&ld12.ld12[4] = 0;
    v29 = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000u) == 0 ? 2147450880 : -32768;
    *(_DWORD *)ld12.ld12 = 0;
  }
  else
  {
    if ( v28 > 0x3FBFu )
    {
      v29 = 0;
      if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
      {
        ++v28;
        if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0 && *(_DWORD *)&ld12.ld12[4] == 0 && *(_DWORD *)ld12.ld12 == 0 )
        {
          *(_WORD *)&ld12.ld12[10] = 0;
          goto LABEL_134;
        }
      }
      if ( (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) != 0
        || (++v28, (*(_DWORD *)&ld12_one_tenth.ld12[8] & 0x7FFFFFFF) != 0)
        || *(_DWORD *)&ld12_one_tenth.ld12[4] != 0
        || *(_DWORD *)ld12_one_tenth.ld12 != 0 )
      {
        v74 = 0;
        v30 = &v91[4];
        for ( j = 5; j > 0; --j )
        {
          v80 = j;
          v72 = &ld12_one_tenth.ld12[8];
          v31 = &ld12.ld12[2 * v74];
          do
          {
            v82 = 0;
            v32 = *(unsigned __int16 *)v31 * *(unsigned __int16 *)v72;
            v33 = *((_DWORD *)v30 - 1);
            v34 = v33 + v32;
            if ( v33 + v32 < v33 || v34 < v32 )
              v82 = 1;
            *((_DWORD *)v30 - 1) = v34;
            if ( v82 != 0 )
              ++*v30;
            v72 -= 2;
            v31 += 2;
            --v80;
          }
          while ( v80 > 0 );
          ++v30;
          ++v74;
        }
        v35 = v28 - 16382;
        if ( v35 <= 0 )
          goto LABEL_173;
        do
        {
          if ( *(int *)&v91[8] < 0 )
            break;
          v36 = *(_DWORD *)v91;
          *(_DWORD *)v91 *= 2;
          v37 = *(_DWORD *)&v91[4];
          *(_DWORD *)&v91[4] = (v36 >> 31) | (2 * *(_DWORD *)&v91[4]);
          --v35;
          *(_DWORD *)&v91[8] = (v37 >> 31) | (2 * *(_DWORD *)&v91[8]);
        }
        while ( v35 > 0 );
        if ( v35 <= 0 )
        {
LABEL_173:
          if ( --v35 < 0 )
          {
            v38 = (unsigned __int16)-v35;
            v35 = 0;
            do
            {
              if ( (v91[0] & 1) != 0 )
                ++v76;
              v39 = *(_DWORD *)&v91[8];
              *(_DWORD *)&v91[8] >>= 1;
              v40 = __SPAIR64__(v39, *(unsigned int *)&v91[4]) >> 1;
              v41 = *(__int64 *)v91 >> 1;
              --v38;
              *(_DWORD *)&v91[4] = v40;
              *(_DWORD *)v91 = v41;
            }
            while ( v38 != 0 );
            if ( v76 != 0 )
              *(_WORD *)v91 |= 1u;
          }
        }
        if ( *(_WORD *)v91 > 0x8000u || (*(_DWORD *)v91 & 0x1FFFF) == 0x18000 )
        {
          if ( *(_DWORD *)&v91[2] == -1 )
          {
            *(_DWORD *)&v91[2] = 0;
            if ( *(_DWORD *)&v91[6] == -1 )
            {
              *(_DWORD *)&v91[6] = 0;
              if ( *(_WORD *)&v91[10] == 0xFFFF )
              {
                *(_WORD *)&v91[10] = 0x8000;
                ++v35;
              }
              else
              {
                ++*(_WORD *)&v91[10];
              }
            }
            else
            {
              ++*(_DWORD *)&v91[6];
            }
          }
          else
          {
            ++*(_DWORD *)&v91[2];
          }
        }
        if ( (unsigned __int16)v35 < 0x7FFFu )
        {
          *(_WORD *)ld12.ld12 = *(_WORD *)&v91[2];
          *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v91[4];
          *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v91[8];
          *(_WORD *)&ld12.ld12[10] = v70 | v35;
        }
        else
        {
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
          *(_DWORD *)&ld12.ld12[8] = v70 == 0 ? 2147450880 : -32768;
        }
        goto LABEL_134;
      }
    }
    else
    {
      v29 = 0;
    }
    *(_DWORD *)&ld12.ld12[4] = 0;
    *(_DWORD *)ld12.ld12 = 0;
  }
  *(_DWORD *)&ld12.ld12[8] = v29;
LABEL_134:
  v42 = ndigits;
  fos->exp = digcount;
  if ( (output_flags & 1) != 0 )
  {
    v42 = digcount + ndigits;
    if ( v42 <= 0 )
    {
      fos->exp = 0;
      *(_WORD *)&fos->ManLen = 12289;
      fos->sign = sign != -32768 ? 32 : 45;
      fos->man[1] = 0;
      return 1;
    }
  }
  if ( v42 > 21 )
    v42 = 21;
  v43 = *(unsigned __int16 *)&ld12.ld12[10] - 16382;
  *(_WORD *)&ld12.ld12[10] = 0;
  v83 = 8;
  do
  {
    v44 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v45 = (v44 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v46 = *(__int64 *)&ld12.ld12[4] >> 31;
    v10 = v83-- == 1;
    *(_DWORD *)&ld12.ld12[4] = v45;
    *(_DWORD *)&ld12.ld12[8] = v46;
  }
  while ( !v10 );
  if ( v43 < 0 )
  {
    v47 = (unsigned __int8)-(char)v43;
    if ( v47 != 0 )
    {
      do
      {
        v48 = *(_DWORD *)&ld12.ld12[8];
        *(_DWORD *)&ld12.ld12[8] >>= 1;
        v49 = (v48 << 31) | (*(_DWORD *)&ld12.ld12[4] >> 1);
        v50 = *(__int64 *)ld12.ld12 >> 1;
        --v47;
        *(_DWORD *)&ld12.ld12[4] = v49;
        *(_DWORD *)ld12.ld12 = v50;
      }
      while ( v47 > 0 );
    }
  }
  man = fos->man;
  v87 = fos->man;
  for ( digcounta = v42 + 1; digcounta > 0; ld12.ld12[11] = 0 )
  {
    v52 = *(_DWORD *)ld12.ld12;
    tmp12 = ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v53 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v54 = (v52 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v55 = 2 * v54;
    v56 = (v54 >> 31) | (2 * (*(__int64 *)&ld12.ld12[4] >> 31));
    v57 = (v53 >> 31) | v55;
    v58 = *(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12;
    if ( (unsigned int)(*(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12) < *(_DWORD *)ld12.ld12
      || v58 < *(_DWORD *)tmp12.ld12 )
    {
      v59 = 0;
      if ( v57 + 1 < v57 || v57 == -1 )
        v59 = 1;
      ++v57;
      if ( v59 != 0 )
        ++v56;
    }
    v60 = *(_DWORD *)&tmp12.ld12[4] + v57;
    v84 = *(_DWORD *)&tmp12.ld12[4] + v57;
    if ( *(_DWORD *)&tmp12.ld12[4] + v57 < v57 || v60 < *(_DWORD *)&tmp12.ld12[4] )
      ++v56;
    *(_DWORD *)ld12.ld12 = 2 * v58;
    *(_DWORD *)&ld12.ld12[8] = (v60 >> 31) | (2 * (*(_DWORD *)&tmp12.ld12[8] + v56));
    *man++ = ld12.ld12[11] + 48;
    --digcounta;
    *(_DWORD *)&ld12.ld12[4] = (v58 >> 31) | (2 * v84);
  }
  v61 = *(man - 1);
  v62 = man - 2;
  if ( v61 >= 53 )
  {
    while ( v62 >= v87 && *v62 == 57 )
      *v62-- = 48;
    v63 = fos;
    if ( v62 < v87 )
    {
      ++v62;
      ++fos->exp;
    }
    ++*v62;
  }
  else
  {
    while ( v62 >= v87 && *v62 == 48 )
      --v62;
    v63 = fos;
    if ( v62 < v87 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = sign != -32768 ? 32 : 45;
      *v87 = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  v64 = (_BYTE)v62 - (_BYTE)v63 - 3;
  v63->ManLen = v64;
  v63->man[v64] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004748E0
// Name: _hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall hw_cw@<eax>(unsigned int abstr@<ebx>)
{
  int result; // eax
  unsigned int v2; // ecx

  result = (abstr & 0x10) != 0;
  if ( (abstr & 8) != 0 )
    result |= 4u;
  if ( (abstr & 4) != 0 )
    result |= 8u;
  if ( (abstr & 2) != 0 )
    result |= 0x10u;
  if ( (abstr & 1) != 0 )
    result |= 0x20u;
  if ( (abstr & 0x80000) != 0 )
    result |= 2u;
  v2 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v2 )
    {
      case 0x100u:
        result |= 0x400u;
        break;
      case 0x200u:
        result |= 0x800u;
        break;
      case 0x300u:
        result |= 0xC00u;
        break;
      default:
        break;
    }
  }
  if ( (abstr & 0x30000) != 0 )
  {
    if ( (abstr & 0x30000) == 0x10000 )
      result |= 0x200u;
  }
  else
  {
    result |= 0x300u;
  }
  if ( (abstr & 0x40000) != 0 )
    return result | 0x1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047496E
// Name: __hw_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall _hw_cw_sse2(int a1, unsigned int abstr)
{
  unsigned int result; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx

  result = 0;
  if ( (abstr & 0x10) != 0 )
    result = 128;
  if ( (abstr & 8) != 0 )
    result |= 0x200u;
  if ( (abstr & 4) != 0 )
    result |= 0x400u;
  if ( (abstr & 2) != 0 )
    result |= 0x800u;
  if ( (abstr & 1) != 0 )
    result |= 0x1000u;
  if ( (abstr & 0x80000) != 0 )
    result |= 0x100u;
  v3 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v3 )
    {
      case 0x100u:
        result |= 0x2000u;
        break;
      case 0x200u:
        result |= 0x4000u;
        break;
      case 0x300u:
        result |= 0x6000u;
        break;
      default:
        break;
    }
  }
  v4 = abstr & 0x3000000;
  switch ( v4 )
  {
    case 0x1000000u:
      result |= 0x8040u;
      break;
    case 0x2000000u:
      result |= 0x40u;
      break;
    case 0x3000000u:
      result |= 0x8000u;
      break;
    default:
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00474A0E
// Name: __control87
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _control87(unsigned int newctrl, unsigned int mask)
{
  int v2; // edx
  int v3; // eax
  unsigned int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // esi
  __int16 v11; // ax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  __int16 v17; // cx
  int v18; // edx
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  unsigned int v23; // [esp+14h] [ebp-Ch]
  __int16 oldCw; // [esp+1Ch] [ebp-4h]
  unsigned int newabs; // [esp+2Ch] [ebp+Ch]

  v2 = 0;
  if ( (oldCw & 1) != 0 )
    v2 = 16;
  if ( (oldCw & 4) != 0 )
    v2 |= 8u;
  if ( (oldCw & 8) != 0 )
    v2 |= 4u;
  if ( (oldCw & 0x10) != 0 )
    v2 |= 2u;
  if ( (oldCw & 0x20) != 0 )
    v2 |= 1u;
  if ( (oldCw & 2) != 0 )
    v2 |= 0x80000u;
  v3 = oldCw & 0xC00;
  if ( (oldCw & 0xC00) != 0 )
  {
    switch ( v3 )
    {
      case 1024:
        v2 |= 0x100u;
        break;
      case 2048:
        v2 |= 0x200u;
        break;
      case 3072:
        v2 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (oldCw & 0x300) != 0 )
  {
    if ( (oldCw & 0x300) == 0x200 )
      v2 |= 0x10000u;
  }
  else
  {
    v2 |= 0x20000u;
  }
  if ( (oldCw & 0x1000) != 0 )
    v2 |= 0x40000u;
  result = mask & newctrl | v2 & ~mask;
  newabs = result;
  if ( result != v2 )
  {
    v6 = hw_cw(abstr: result);
    v7 = v6;
    v8 = 0;
    if ( (v6 & 1) != 0 )
      v8 = 16;
    if ( (v6 & 4) != 0 )
      v8 |= 8u;
    if ( (v6 & 8) != 0 )
      v8 |= 4u;
    if ( (v6 & 0x10) != 0 )
      v8 |= 2u;
    if ( (v6 & 0x20) != 0 )
      v8 |= 1u;
    if ( (v6 & 2) != 0 )
      v8 |= 0x80000u;
    v9 = v6 & 0xC00;
    if ( (v7 & 0xC00) != 0 )
    {
      switch ( v9 )
      {
        case 1024:
          v8 |= 0x100u;
          break;
        case 2048:
          v8 |= 0x200u;
          break;
        case 3072:
          v8 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v7 & 0x300) != 0 )
    {
      if ( (v7 & 0x300) == 0x200 )
        v8 |= 0x10000u;
    }
    else
    {
      v8 |= 0x20000u;
    }
    if ( (v7 & 0x1000) != 0 )
      v8 |= 0x40000u;
    newabs = v8;
    result = v8;
  }
  v10 = 0;
  if ( __sse2_available != 0 )
  {
    v11 = _mm_getcsr();
    if ( (v11 & 0x80u) != 0 )
      v10 = 16;
    if ( (v11 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v11 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v11 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v11 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v11 & 0x100) != 0 )
      v10 |= 0x80000u;
    v12 = v11 & 0x6000;
    if ( (v11 & 0x6000) != 0 )
    {
      switch ( v12 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v13 = (v11 & 0x8040) - 64;
    if ( v13 != 0 )
    {
      v14 = v13 - 32704;
      if ( v14 != 0 )
      {
        if ( v14 == 64 )
          v10 |= 0x1000000u;
      }
      else
      {
        v10 |= 0x3000000u;
      }
    }
    else
    {
      v10 |= 0x2000000u;
    }
    v15 = newctrl & mask & 0x308031F | v10 & ~(mask & 0x308031F);
    if ( v15 == v10 )
    {
      v16 = v10;
    }
    else
    {
      v23 = _hw_cw_sse2(a1: v12, abstr: v15);
      __set_fpsr_sse2(newMXCSR: v23);
      v17 = _mm_getcsr();
      v18 = 0;
      if ( (v17 & 0x80u) != 0 )
        v18 = 16;
      if ( (v17 & 0x200) != 0 )
        v18 |= 8u;
      if ( (v17 & 0x400) != 0 )
        v18 |= 4u;
      if ( (v17 & 0x800) != 0 )
        v18 |= 2u;
      if ( (v17 & 0x1000) != 0 )
        v18 |= 1u;
      if ( (v17 & 0x100) != 0 )
        v18 |= 0x80000u;
      v19 = v17 & 0x6000;
      if ( (v17 & 0x6000) != 0 )
      {
        switch ( v19 )
        {
          case 8192:
            v18 |= 0x100u;
            break;
          case 16384:
            v18 |= 0x200u;
            break;
          case 24576:
            v18 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v20 = (v17 & 0x8040) - 64;
      if ( v20 != 0 )
      {
        v21 = v20 - 32704;
        if ( v21 != 0 )
        {
          if ( v21 == 64 )
            v18 |= 0x1000000u;
        }
        else
        {
          v18 |= 0x3000000u;
        }
      }
      else
      {
        v18 |= 0x2000000u;
      }
      v16 = v18;
    }
    v22 = newabs ^ v16;
    result = newabs | v16;
    if ( (v22 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00474D20
// Name: __strnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp_l(char *dst, char *src, unsigned int count, localeinfo_struct *plocinfo)
{
  char *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  if ( count != 0 )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    if ( dst != nullptr && (v4 = src, src != nullptr) )
    {
      if ( count <= 0x7FFFFFFF )
      {
        if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
        {
          do
          {
            v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
            v6 = _tolower_l(c: (unsigned __int8)*v4++, plocinfo: &_loc_update.localeinfo);
            --count;
          }
          while ( count != 0 && v5 != 0 && v5 == v6 );
        }
        else
        {
          __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
        }
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
      else
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474E02
// Name: __strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp(char *dst, char *src, unsigned int count)
{
  if ( __locale_changed != 0 )
  {
    _strnicmp_l(dst, src, count, plocinfo: nullptr);
  }
  else if ( dst != nullptr && src != nullptr && count <= 0x7FFFFFFF )
  {
    __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474E55
// Name: __mbschr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbschr_l(unsigned __int8 *string, unsigned int c, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // eax
  unsigned __int16 v4; // cx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = string;
  if ( string != nullptr )
  {
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      while ( 1 )
      {
        v4 = *v3;
        if ( *v3 == 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v4 + 1] & 4) != 0 )
        {
          if ( *++v3 == 0 )
            goto LABEL_17;
          if ( c == (*v3 | (v4 << 8)) )
            goto LABEL_15;
        }
        else if ( c == *v3 )
        {
          break;
        }
        ++v3;
      }
      if ( c == *v3 )
        goto LABEL_15;
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      strchr(string, chr: c);
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474F05
// Name: __mbschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbschr(unsigned __int8 *string, unsigned int c)
{
  _mbschr_l(string, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00474F1C
// Name: ___ascii_stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __ascii_stricmp(const char *dst, const char *src)
{
  int v4; // eax
  int v5; // ecx

  do
  {
    v4 = *(unsigned __int8 *)dst++;
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
    v5 = *(unsigned __int8 *)src++;
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      v5 += 32;
  }
  while ( v4 != 0 && v4 == v5 );
  return v4 - v5;
}

//------------------------------------------------------------------------------
// Address: 0x00474F55
// Name: __stricmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _stricmp_l(const char *dst, const char *src, localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  const char *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( dst != nullptr )
  {
    v4 = src;
    if ( src != nullptr )
    {
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
          v6 = _tolower_l(c: *(unsigned __int8 *)v4++, plocinfo: &_loc_update.localeinfo);
        }
        while ( v5 != 0 && v5 == v6 );
        result = v5 - v6;
      }
      else
      {
        result = __ascii_stricmp(dst, src);
      }
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00475015
// Name: __stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _stricmp(const char *dst, const char *src)
{
  if ( __locale_changed != 0 )
    return _stricmp_l(dst, src, plocinfo: nullptr);
  if ( dst != nullptr && src != nullptr )
    return __ascii_stricmp(dst, src);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x0047505C
// Name: ___initconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0047507B
// Name: ___termconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconout()
{
  HANDLE result; // eax

  result = _confh;
  if ( _confh != (HANDLE)-1 && _confh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _confh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00475092
// Name: __flswbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flswbuf(unsigned __int16 ch, _iobuf *str)
{
  int flag; // eax
  int v5; // eax
  unsigned int v6; // eax
  char *base; // eax
  char *ptr; // edi
  signed int v9; // edi
  ioinfo *v10; // eax
  doubleint v11; // rax
  unsigned __int16 v12; // bx
  char mbc[4]; // [esp+4h] [ebp-4h] BYREF
  int fh; // [esp+14h] [ebp+Ch]

  fh = fileno(stream: str);
  flag = str->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    str->_flag |= 0x20u;
    return 0xFFFF;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    str->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      str->_flag = flag | 0x20;
      return 0xFFFF;
    }
    str->_ptr = str->_base;
    str->_flag = flag & 0xFFFFFFFE;
  }
  v5 = str->_flag;
  str->_cnt = 0;
  *(_DWORD *)mbc = 0;
  v6 = v5 & 0xFFFFFFED | 2;
  str->_flag = v6;
  if ( (v6 & 0x10C) == 0 && (str != &__iob_func()[1] && str != &__iob_func()[2] || _isatty(fh) == 0) )
    _getbuf(str);
  if ( (str->_flag & 0x108) != 0 )
  {
    base = str->_base;
    ptr = str->_ptr;
    str->_ptr = base + 2;
    v9 = ptr - base;
    str->_cnt = str->_bufsiz - 2;
    if ( v9 <= 0 )
    {
      if ( fh == -1 || fh == -2 )
        v10 = &__badioinfo;
      else
        v10 = &__pioinfo[fh >> 5][fh & 0x1F];
      if ( (v10->osfile & 0x20) != 0 )
      {
        v11.bigint = _lseeki64(fh, pos: 0, mthd: 2u).bigint;
        if ( (v11.twoints.upperhalf & v11.twoints.lowerhalf) == -1 )
          goto LABEL_28;
      }
    }
    else
    {
      *(_DWORD *)mbc = _write(fh, buf: base, cnt: v9);
    }
    v12 = ch;
    *(_WORD *)str->_base = ch;
  }
  else
  {
    v9 = 2;
    v12 = ch;
    *(_WORD *)mbc = ch;
    *(_DWORD *)mbc = _write(fh, buf: mbc, cnt: 2u);
  }
  if ( *(_DWORD *)mbc != v9 )
  {
LABEL_28:
    str->_flag |= 0x20u;
    return 0xFFFF;
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x00475206
// Name: __filwbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _filwbuf(_iobuf *str)
{
  int flag; // eax
  int v2; // eax
  int v3; // eax
  unsigned int v4; // eax
  ioinfo **v5; // edi
  ioinfo *v6; // eax
  int v7; // eax
  char *ptr; // ecx
  int result; // eax
  char *base; // [esp-8h] [ebp-Ch]
  unsigned int bufsiz; // [esp-4h] [ebp-8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0xFFFF;
  }
  flag = str->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return 0xFFFF;
  if ( (flag & 2) != 0 )
  {
    str->_flag = flag | 0x20;
    return 0xFFFF;
  }
  v2 = flag | 1;
  str->_flag = v2;
  if ( (v2 & 0x10C) != 0 )
    str->_ptr = str->_base;
  else
    _getbuf(str);
  bufsiz = str->_bufsiz;
  base = str->_base;
  v3 = fileno(stream: str);
  v4 = _read(fh: v3, buf: base, cnt: bufsiz);
  str->_cnt = v4;
  if ( v4 < 2 || v4 == -1 )
  {
    str->_flag |= v4 != 0 ? 32 : 16;
    str->_cnt = 0;
    return 0xFFFF;
  }
  if ( (str->_flag & 0x82) == 0 )
  {
    if ( fileno(stream: str) == -1 || fileno(stream: str) == -2 )
    {
      v6 = &__badioinfo;
    }
    else
    {
      v5 = &__pioinfo[fileno(stream: str) >> 5];
      v6 = &(*v5)[fileno(stream: str) & 0x1F];
    }
    if ( (v6->osfile & 0x82) == 0x82 )
      str->_flag |= 0x2000u;
  }
  if ( str->_bufsiz == 512 )
  {
    v7 = str->_flag;
    if ( (v7 & 8) != 0 && (v7 & 0x400) == 0 )
      str->_bufsiz = 4096;
  }
  ptr = str->_ptr;
  str->_cnt -= 2;
  result = *(unsigned __int16 *)ptr;
  str->_ptr = ptr + 2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00475340
// Name: ___ascii_strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __ascii_strnicmp(unsigned __int8 *first, unsigned __int8 *last, unsigned int count)
{
  unsigned int i; // ecx
  unsigned __int8 v6; // ah
  unsigned __int8 v7; // al

  for ( i = count; i != 0; --i )
  {
    v6 = *first;
    v7 = *last;
    if ( *first == 0 || v7 == 0 )
      break;
    ++first;
    ++last;
    if ( v6 >= 0x41u && v6 <= 0x5Au )
      v6 += 32;
    if ( v7 >= 0x41u && v7 <= 0x5Au )
      v7 += 32;
    if ( v6 != v7 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004753A2
// Name: RtlUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  __imp__RtlUnwind@16(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

//------------------------------------------------------------------------------
// Address: 0x004753A8
// Name: __WSAFDIsSet(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall __WSAFDIsSet(SOCKET fd, fd_set *a2)
{
  return __imp____WSAFDIsSet@8(fd, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004753AE
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)operator new(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0047552C
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00475560
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strlwr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 65 && v3 <= 90 )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004755BD
// Name: _putenv_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl putenv_helper(char *name, const char *value)
{
  const CHAR *v3; // edi
  int v4; // eax
  int v5; // eax
  unsigned int v6; // esi
  unsigned __int8 *v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // esi
  unsigned __int8 *v11; // eax
  int v12; // edi
  int v13; // eax
  unsigned __int8 *v14; // eax
  int v15; // eax
  char *newoption; // [esp+4h] [ebp-8h] BYREF
  unsigned __int16 *woption; // [esp+8h] [ebp-4h] BYREF

  newoption = nullptr;
  if ( __env_initialized == 0 )
    return -1;
  v3 = name;
  if ( name == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( value != nullptr )
  {
    v8 = strnlen(str: name, maxsize: 0x7FFFu);
    v9 = strnlen(str: value, maxsize: 0x7FFFu);
    if ( v8 < 0x7FFF && v9 < 0x7FFF )
    {
      v10 = v9 + v8 + 2;
      v11 = calloc(count: v10, size: 1u);
      newoption = (char *)v11;
      if ( v11 != nullptr )
      {
        strcpy_s(_Dst: (char *)v11, _SizeInBytes: v10, _Src: name);
        newoption[v8] = 61;
        strcpy_s(_Dst: &newoption[v8 + 1], _SizeInBytes: v10 - (v8 + 1), _Src: value);
        v3 = name;
        goto LABEL_16;
      }
      return -1;
    }
LABEL_13:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _mbschr(string: (unsigned __int8 *)name, c: 0x3Du);
  if ( v4 != 0 && (v4 - (int)name >= 0x7FFF || strnlen(str: (const char *)(v4 + 1), maxsize: 0x7FFFu) >= 0x7FFF) )
    goto LABEL_13;
  strlen(buf: name);
  v6 = v5 + 1;
  v7 = calloc(count: v5 + 1, size: 1u);
  newoption = (char *)v7;
  if ( v7 == nullptr )
    return -1;
  strcpy_s(_Dst: (char *)v7, _SizeInBytes: v6, _Src: name);
LABEL_16:
  if ( __crtsetenv(poption: &newoption, primary: 1) != 0 )
  {
    if ( newoption != nullptr )
      free(pMem: newoption);
    return -1;
  }
  if ( _wenviron == nullptr )
    return 0;
  woption = nullptr;
  v12 = MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: v3,
          cbMultiByte: -1,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  if ( v12 == 0 )
    goto LABEL_29;
  if ( value != nullptr )
  {
    v13 = MultiByteToWideChar(
            CodePage: 0,
            dwFlags: 0,
            lpMultiByteStr: value,
            cbMultiByte: -1,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    if ( v13 == 0 )
    {
LABEL_29:
      *_errno() = 42;
      return -1;
    }
    v12 += v13 + 1;
  }
  v14 = calloc(count: v12, size: 2u);
  woption = (unsigned __int16 *)v14;
  if ( v14 == nullptr )
    return -1;
  if ( MultiByteToWideChar(
         CodePage: 0,
         dwFlags: 0,
         lpMultiByteStr: name,
         cbMultiByte: -1,
         lpWideCharStr: (LPWSTR)v14,
         cchWideChar: v12) == 0
    || value != nullptr
    && (v15 = wcslen(wcs: woption),
        woption[v15] = 61,
        MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: value,
          cbMultiByte: -1,
          lpWideCharStr: &woption[v15 + 1],
          cchWideChar: v12 - (v15 + 1)) == 0) )
  {
    free(pMem: woption);
    goto LABEL_29;
  }
  if ( __crtwsetenv(poption: &woption, primary: 0) != 0 )
  {
    if ( woption != nullptr )
      free(pMem: woption);
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004757BA
// Name: __putenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _putenv(char *option)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = putenv_helper(name: option, value: nullptr);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004757FF
// Name: wfindenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall wfindenv@<eax>(unsigned int len@<edi>, const wchar_t *name)
{
  const wchar_t **i; // esi
  int v3; // eax

  for ( i = (const wchar_t **)_wenviron; ; ++i )
  {
    if ( *i == nullptr )
      return -(((char *)i - (char *)_wenviron) >> 2);
    if ( _wcsnicoll(_string1: name, _string2: *i, count: len) == 0 )
    {
      v3 = (*i)[len];
      if ( v3 == 61 || (_WORD)v3 == 0 )
        break;
    }
  }
  return ((char *)i - (char *)_wenviron) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x00475854
// Name: copy_environ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 **__usercall copy_environ_0@<eax>(unsigned __int16 **oldenviron@<eax>)
{
  unsigned __int16 **result; // eax
  unsigned __int16 **v3; // ecx
  unsigned __int8 *v4; // esi
  ConVar *v5; // ecx
  unsigned __int16 *v6; // eax
  int v7; // edi
  ConVar *v8; // [esp-8h] [ebp-10h]
  ConVar *v9; // [esp-8h] [ebp-10h]
  unsigned __int16 **newenviron; // [esp+4h] [ebp-4h]

  result = nullptr;
  v3 = oldenviron;
  if ( oldenviron != nullptr )
  {
    if ( *oldenviron != nullptr )
    {
      do
      {
        ++v3;
        result = (unsigned __int16 **)((char *)result + 1);
      }
      while ( *v3 != nullptr );
    }
    v4 = calloc(count: (unsigned int)result + 1, size: 4u);
    v5 = v8;
    newenviron = (unsigned __int16 **)v4;
    if ( v4 == nullptr )
      _amsg_exit(rterrnum: 9);
    v6 = *oldenviron;
    if ( *oldenviron != nullptr )
    {
      v7 = (char *)oldenviron - (char *)v4;
      do
      {
        v9 = (ConVar *)v6;
        *(_DWORD *)v4 = yaSSL::RC4::get_ivSize(this: v5);
        v4 += 4;
        v6 = *(unsigned __int16 **)&v4[v7];
        v5 = v9;
      }
      while ( v6 != nullptr );
    }
    *(_DWORD *)v4 = 0;
    return newenviron;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004758B4
// Name: ___crtwsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtwsetenv(unsigned __int16 **poption, int primary)
{
  const wchar_t *v3; // ebx
  unsigned __int16 *v4; // eax
  unsigned __int16 *v5; // edi
  unsigned __int16 **v6; // eax
  char **v7; // eax
  unsigned __int16 **v8; // eax
  unsigned __int16 **v9; // ebx
  int v10; // eax
  unsigned int v11; // edi
  unsigned __int16 **v12; // esi
  int v13; // eax
  unsigned __int8 *v14; // edi
  int v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // eax
  unsigned __int8 *v18; // eax
  unsigned __int16 **v19; // ecx
  unsigned int v20; // [esp+4h] [ebp-10h]
  int retval; // [esp+8h] [ebp-Ch]
  BOOL remove; // [esp+Ch] [ebp-8h]
  unsigned __int16 *option; // [esp+10h] [ebp-4h]

  retval = 0;
  if ( poption == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v3 = *poption;
  option = *poption;
  if ( *poption == nullptr )
    goto LABEL_13;
  v4 = wcschr(string: v3, ch: 0x3Du);
  v5 = v4;
  if ( v4 == nullptr || v3 == v4 )
    goto LABEL_13;
  remove = v4[1] == 0;
  v6 = _wenviron;
  if ( _wenviron == __winitenv )
  {
    v6 = copy_environ_0(oldenviron: _wenviron);
    _wenviron = v6;
  }
  if ( v6 == nullptr )
  {
    if ( primary != 0 && _environ != nullptr )
    {
      _wenvptr = (wchar_t *)__crtGetEnvironmentStringsW();
      if ( _wsetenvp() < 0 && __mbtow_environ() != 0 )
      {
LABEL_13:
        *_errno() = 22;
        return -1;
      }
    }
    else
    {
      if ( remove )
        return 0;
      if ( _environ != nullptr )
        goto LABEL_20;
      v7 = (char **)operator new(nSize: 4u);
      _environ = v7;
      if ( v7 == nullptr )
        return -1;
      *v7 = nullptr;
      if ( _wenviron == nullptr )
      {
LABEL_20:
        v8 = (unsigned __int16 **)operator new(nSize: 4u);
        _wenviron = v8;
        if ( v8 == nullptr )
          return -1;
        *v8 = nullptr;
      }
    }
  }
  v9 = _wenviron;
  if ( _wenviron == nullptr )
    return -1;
  v20 = v5 - option;
  v10 = wfindenv(len: v20, name: option);
  v11 = v10;
  if ( v10 >= 0 && *v9 != nullptr )
  {
    v12 = &v9[v10];
    free(pMem: *v12);
    if ( remove )
    {
      while ( *v12 != nullptr )
      {
        ++v11;
        *v12 = v12[1];
        v12 = &v9[v11];
      }
      if ( v11 < 0x3FFFFFFF )
      {
        v17 = _recalloc_crt(ptr: _wenviron, count: v11, size: 4u);
        if ( v17 != nullptr )
          _wenviron = (unsigned __int16 **)v17;
      }
    }
    else
    {
      *v12 = option;
      *poption = nullptr;
    }
    goto LABEL_27;
  }
  if ( remove )
  {
    free(pMem: option);
    *poption = nullptr;
    return 0;
  }
  if ( v10 < 0 )
    v11 = -v10;
  if ( (int)(v11 + 2) <= (int)v11 )
    return -1;
  if ( v11 + 2 >= 0x3FFFFFFF )
    return -1;
  v18 = _recalloc_crt(ptr: _wenviron, count: 4u, size: v11 + 2);
  if ( v18 == nullptr )
    return -1;
  v19 = (unsigned __int16 **)&v18[4 * v11];
  *v19 = option;
  v19[1] = nullptr;
  *poption = nullptr;
  _wenviron = (unsigned __int16 **)v18;
LABEL_27:
  if ( primary != 0 )
  {
    v13 = wcslen(wcs: option);
    v14 = calloc(count: v13 + 2, size: 2u);
    if ( v14 != nullptr )
    {
      v15 = wcslen(wcs: option);
      if ( wcscpy_s(_Dst: (unsigned __int16 *)v14, _SizeInWords: v15 + 2, _Src: option) != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      v16 = &v14[2 * v20];
      *(_WORD *)v16 = 0;
      if ( !SetEnvironmentVariableW(lpName: (LPCWSTR)v14, lpValue: !remove ? (LPCWSTR)v16 + 1 : nullptr) )
      {
        retval = -1;
        *_errno() = 42;
      }
      free(pMem: v14);
    }
  }
  if ( remove )
  {
    free(pMem: option);
    *poption = nullptr;
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00475B34
// Name: __wcsnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsnicoll_l(
        const wchar_t *_string1,
        const wchar_t *_string2,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  unsigned int v4; // ebx
  int result; // eax
  const wchar_t *v6; // esi
  unsigned int v7; // eax
  int v8; // edx
  unsigned int v9; // eax
  unsigned __int16 v10; // cx
  unsigned int v11; // eax
  int v12; // eax
  int *v13; // eax
  bool v14; // zf
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  v4 = count;
  if ( count == 0 )
    return 0;
  if ( _string1 == nullptr || (v6 = _string2, _string2 == nullptr) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
  if ( count > 0x7FFFFFFF )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v7 = _loc_update.localeinfo.locinfo->lc_handle[1];
  if ( v7 != 0 )
  {
    v12 = __crtCompareStringW(
            Locale: v7,
            dwCmpFlags: 0x1001u,
            lpString1: _string1,
            cchCount1: count,
            lpString2: _string2,
            cchCount2: count);
    if ( v12 == 0 )
    {
      v13 = _errno();
      v14 = !_loc_update.updated;
      *v13 = 22;
      if ( !v14 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    result = v12 - 2;
  }
  else
  {
    v8 = (char *)_string1 - (char *)_string2;
    do
    {
      v9 = *(const wchar_t *)((char *)v6 + v8);
      if ( v9 < 0x41 || v9 > 0x5A )
        v10 = *(const wchar_t *)((char *)v6 + v8);
      else
        v10 = v9 + 32;
      v11 = *v6;
      if ( v11 >= 0x41 && v11 <= 0x5A )
        LOWORD(v11) = v11 + 32;
      ++v6;
      --v4;
    }
    while ( v4 != 0 && v10 != 0 && v10 == (_WORD)v11 );
    result = v10 - (unsigned __int16)v11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00475C54
// Name: __wcsnicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsnicoll(const wchar_t *_string1, const wchar_t *_string2, unsigned int count)
{
  const wchar_t *v3; // ecx
  int v5; // esi
  unsigned int v6; // eax
  unsigned __int16 v7; // dx
  unsigned int v8; // eax

  if ( __locale_changed != 0 )
    return _wcsnicoll_l(_string1, _string2, count, plocinfo: nullptr);
  if ( _string1 != nullptr && (v3 = _string2, _string2 != nullptr) && count <= 0x7FFFFFFF )
  {
    v5 = (char *)_string1 - (char *)_string2;
    do
    {
      v6 = *(const wchar_t *)((char *)v3 + v5);
      if ( v6 < 0x41 || v6 > 0x5A )
        v7 = *(const wchar_t *)((char *)v3 + v5);
      else
        v7 = v6 + 32;
      v8 = *v3;
      if ( v8 >= 0x41 && v8 <= 0x5A )
        LOWORD(v8) = v8 + 32;
      ++v3;
      --count;
    }
    while ( count != 0 && v7 != 0 && v7 == (_WORD)v8 );
    return v7 - (unsigned __int16)v8;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475D0E
// Name: ___mbtow_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __mbtow_environ()
{
  LPCCH *v0; // esi
  const CHAR *v1; // eax
  unsigned int v2; // eax
  unsigned __int8 *v3; // eax
  int size; // [esp+Ch] [ebp-8h]
  unsigned __int16 *wenvp; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCCH *)_environ;
  wenvp = nullptr;
  v1 = *_environ;
  if ( *_environ == nullptr )
    return 0;
  while ( 1 )
  {
    v2 = MultiByteToWideChar(
           CodePage: 0,
           dwFlags: 0,
           lpMultiByteStr: v1,
           cbMultiByte: -1,
           lpWideCharStr: nullptr,
           cchWideChar: 0);
    size = v2;
    if ( v2 == 0 )
      return -1;
    v3 = calloc(count: v2, size: 2u);
    wenvp = (unsigned __int16 *)v3;
    if ( v3 == nullptr )
      return -1;
    if ( MultiByteToWideChar(
           CodePage: 0,
           dwFlags: 0,
           lpMultiByteStr: *v0,
           cbMultiByte: -1,
           lpWideCharStr: (LPWSTR)v3,
           cchWideChar: size) == 0 )
      goto LABEL_10;
    if ( __crtwsetenv(poption: &wenvp, primary: 0) < 0 )
    {
      if ( wenvp == nullptr )
        return -1;
LABEL_10:
      free(pMem: wenvp);
      return -1;
    }
    v1 = *++v0;
    if ( *v0 == nullptr )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475D95
// Name: __wsetenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wsetenvp()
{
  wchar_t *v0; // esi
  int v1; // edi
  unsigned __int8 *v3; // ebx
  wchar_t *i; // esi
  int v5; // eax
  unsigned int v6; // edi
  unsigned __int8 *v7; // eax

  v0 = _wenvptr;
  v1 = 0;
  if ( _wenvptr == nullptr )
    return -1;
  while ( *v0 != 0 )
  {
    if ( *v0 != 61 )
      ++v1;
    v0 += wcslen(wcs: v0) + 1;
  }
  v3 = calloc(count: v1 + 1, size: 4u);
  _wenviron = (unsigned __int16 **)v3;
  if ( v3 == nullptr )
    return -1;
  for ( i = _wenvptr; ; i += v6 )
  {
    if ( *i == 0 )
    {
      free(pMem: _wenvptr);
      _wenvptr = nullptr;
      *(_DWORD *)v3 = 0;
      __env_initialized = 1;
      return 0;
    }
    v5 = wcslen(wcs: i);
    v6 = v5 + 1;
    if ( *i != 61 )
      break;
LABEL_14:
    ;
  }
  v7 = calloc(count: v5 + 1, size: 2u);
  *(_DWORD *)v3 = v7;
  if ( v7 != nullptr )
  {
    if ( wcscpy_s(_Dst: (unsigned __int16 *)v7, _SizeInWords: v6, _Src: i) != 0 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    v3 += 4;
    goto LABEL_14;
  }
  free(pMem: _wenviron);
  _wenviron = nullptr;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475E71
// Name: ___crtGetEnvironmentStringsW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl __crtGetEnvironmentStringsW()
{
  LPWCH EnvironmentStringsW; // eax
  unsigned __int8 *v1; // esi
  unsigned int v3; // ebx
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // edi

  EnvironmentStringsW = GetEnvironmentStringsW();
  v1 = (unsigned __int8 *)EnvironmentStringsW;
  if ( EnvironmentStringsW == nullptr )
    return nullptr;
  for ( ; *EnvironmentStringsW != 0; ++EnvironmentStringsW )
  {
    do
      ++EnvironmentStringsW;
    while ( *EnvironmentStringsW != 0 );
  }
  v3 = (char *)EnvironmentStringsW - (char *)v1 + 2;
  v4 = (unsigned __int8 *)operator new(nSize: v3);
  v5 = v4;
  if ( v4 != nullptr )
    memcpy(dst: v4, src: v1, count: v3);
  FreeEnvironmentStringsW(penv: (LPWCH)v1);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00475EC9
// Name: _wcschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcschr(const wchar_t *string, wchar_t ch)
{
  unsigned __int16 *result; // eax

  for ( result = (unsigned __int16 *)string; *result != 0; ++result )
  {
    if ( *result == ch )
      return result;
  }
  if ( *result != ch )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00475EF0
// Name: ___crtCompareStringW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringW(
        LCID Locale,
        DWORD dwCmpFlags,
        const wchar_t *lpString1,
        int cchCount1,
        const wchar_t *lpString2,
        int cchCount2)
{
  int v6; // esi
  int v7; // eax

  v6 = cchCount1;
  if ( cchCount1 > 0 )
    v6 = wcsnlen(wcs: lpString1, maxsize: cchCount1);
  v7 = cchCount2;
  if ( cchCount2 > 0 )
    v7 = wcsnlen(wcs: lpString2, maxsize: cchCount2);
  if ( v6 != 0 && v7 != 0 )
    return CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1: v6, lpString2, cchCount2: v7);
  if ( v6 == v7 )
    return 2;
  return 2 * (v6 - v7 >= 0) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00475F60
// Name: _dynamic_initializer_for__QueuedPacket_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__QueuedPacket_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &QueuedPacket_t::s_Allocator,
    blockSize: 32,
    numElements: 2048,
    growMode: 1,
    pszAllocOwner: "QueuedPacket_t pool",
    nAlignment: 0);
  QueuedPacket_t::s_Allocator.m_mutex.m_ownerID = 0;
  QueuedPacket_t::s_Allocator.m_mutex.m_depth = 0;
  return atexit(func: dynamic_atexit_destructor_for__QueuedPacket_t::s_Allocator__);
}
