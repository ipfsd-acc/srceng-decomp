// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: devtools/statsmap/statsmap.cpp
// Functions: 11
// ============================================================

#include "devtools\statsmap\statsmap.h"

//------------------------------------------------------------------------------
// Address: 0x00402BE0
// Name: public: void std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::_Copy(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::string::_Copy(std::string *this, unsigned int _Newsize, unsigned int _Oldlen)
{
  unsigned int v3; // esi
  std::string *v4; // edi
  unsigned int Myres; // ebx
  unsigned int v6; // ecx
  unsigned __int8 *v7; // eax
  unsigned __int8 *Ptr; // eax
  int v9; // [esp+0h] [ebp-34h] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-28h] BYREF
  char *_What[6]; // [esp+1Ch] [ebp-18h] BYREF
  unsigned __int8 *_Ptr; // [esp+3Ch] [ebp+8h]

  v3 = _Newsize | 0xF;
  v4 = this;
  _What[2] = (char *)&v9;
  _What[1] = (char *)this;
  if ( (_Newsize | 0xF) == 0xFFFFFFFF )
  {
    v3 = _Newsize;
  }
  else
  {
    Myres = this->_Myres;
    v6 = Myres >> 1;
    if ( Myres >> 1 > v3 / 3 )
    {
      v3 = v6 + Myres;
      if ( Myres > -2 - v6 )
        v3 = -2;
    }
  }
  v7 = nullptr;
  _What[5] = nullptr;
  if ( v3 != -1 )
  {
    v7 = (unsigned __int8 *)operator new(nSize: v3 + 1);
    if ( v7 == nullptr )
    {
      _What[0] = nullptr;
      std::exception::exception(this: &pExceptionObject, (const char *const *)_What);
      pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
    }
  }
  _Ptr = v7;
  if ( _Oldlen != 0 )
  {
    if ( v4->_Myres < 0x10 )
      Ptr = (unsigned __int8 *)v4;
    else
      Ptr = (unsigned __int8 *)v4->_Bx._Ptr;
    memcpy(dst: _Ptr, src: Ptr, count: _Oldlen);
  }
  if ( v4->_Myres >= 0x10 )
    free(pMem: v4->_Bx._Ptr);
  v4->_Bx._Buf[0] = 0;
  v4->_Bx._Ptr = (char *)_Ptr;
  v4->_Myres = v3;
  v4->_Mysize = _Oldlen;
  if ( v3 >= 0x10 )
    v4 = (std::string *)_Ptr;
  v4->_Bx._Buf[_Oldlen] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00402D40
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::insert(unsigned int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::insert(
        std::string *this,
        unsigned int _Off,
        const std::string *_Right,
        unsigned int _Roff,
        unsigned int _Count)
{
  unsigned int Mysize; // ecx
  unsigned int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // ebx
  unsigned int Myres; // eax
  unsigned int v12; // eax
  std::string *Ptr; // ecx
  std::string *v15; // eax
  const std::string *v16; // ecx
  unsigned int v17; // edx
  unsigned int v18; // eax
  std::string *v19; // ecx
  std::string *v20; // eax
  bool v21; // cf
  unsigned int _Num; // [esp+1Ch] [ebp+14h]

  Mysize = this->_Mysize;
  if ( Mysize < _Off || (v7 = _Right->_Mysize) < _Roff )
    std::_Xout_of_range(_Message: "invalid string position");
  v8 = _Count;
  v9 = v7 - _Roff;
  if ( v9 < _Count )
    v8 = v9;
  if ( -1 - Mysize <= v8 )
    std::_Xlength_error(_Message: "string too long");
  if ( v8 == 0 )
    return this;
  v10 = Mysize + v8;
  _Num = Mysize + v8;
  if ( Mysize + v8 == -1 )
    std::_Xlength_error(_Message: "string too long");
  Myres = this->_Myres;
  if ( Myres < v10 )
  {
    std::string::_Copy(this, _Newsize: Mysize + v8, _Oldlen: Mysize);
    if ( v10 != 0 )
    {
LABEL_12:
      v12 = this->_Myres;
      if ( v12 < 0x10 )
        Ptr = this;
      else
        Ptr = (std::string *)this->_Bx._Ptr;
      if ( v12 < 0x10 )
        v15 = this;
      else
        v15 = (std::string *)this->_Bx._Ptr;
      memmove(
        dst: (unsigned __int8 *)&v15->_Bx._Buf[_Off + v8],
        src: (unsigned __int8 *)&Ptr->_Bx._Buf[_Off],
        count: this->_Mysize - _Off);
      v16 = _Right;
      if ( this == _Right )
      {
        v17 = _Roff + v8;
        if ( _Off >= _Roff )
          v17 = _Roff;
        v18 = this->_Myres;
        if ( v18 < 0x10 )
          v19 = this;
        else
          v19 = (std::string *)this->_Bx._Ptr;
        if ( v18 < 0x10 )
          memmove(dst: (unsigned __int8 *)&this->_Bx._Buf[_Off], src: (unsigned __int8 *)&v19->_Bx._Buf[v17], count: v8);
        else
          memmove(dst: (unsigned __int8 *)&this->_Bx._Ptr[_Off], src: (unsigned __int8 *)&v19->_Bx._Buf[v17], count: v8);
      }
      else
      {
        if ( _Right->_Myres >= 0x10 )
          v16 = (const std::string *)_Right->_Bx._Ptr;
        if ( this->_Myres < 0x10 )
          v20 = this;
        else
          v20 = (std::string *)this->_Bx._Ptr;
        memcpy(dst: (unsigned __int8 *)&v20->_Bx._Buf[_Off], src: (unsigned __int8 *)&v16->_Bx._Buf[_Roff], count: v8);
      }
      v21 = this->_Myres < 0x10;
      this->_Mysize = _Num;
      if ( !v21 )
      {
        this->_Bx._Ptr[_Num] = 0;
        return this;
      }
      this->_Bx._Buf[_Num] = 0;
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
// Address: 0x00402EC0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::insert(unsigned int,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::insert(std::string *this, unsigned int _Off, char *_Ptr, unsigned int _Count)
{
  std::string *v4; // esi
  unsigned int Myres; // edx
  std::string *v6; // ecx
  std::string *Ptr; // ecx
  unsigned int Mysize; // eax
  unsigned int v10; // edi
  unsigned int v11; // ecx
  unsigned int v12; // eax
  std::string *v13; // ecx
  std::string *v14; // eax
  std::string *v15; // eax
  bool v16; // cf

  v4 = this;
  if ( _Ptr != nullptr )
  {
    Myres = this->_Myres;
    if ( Myres >= 0x10 )
      this = (std::string *)this->_Bx._Ptr;
    if ( _Ptr >= (char *)this )
    {
      v6 = Myres < 0x10 ? v4 : (std::string *)v4->_Bx._Ptr;
      if ( (char *)v6 + v4->_Mysize > _Ptr )
      {
        if ( Myres < 0x10 )
          Ptr = v4;
        else
          Ptr = (std::string *)v4->_Bx._Ptr;
        return std::string::insert(this: v4, _Off, _Right: v4, _Roff: _Ptr - (char *)Ptr, _Count);
      }
    }
  }
  Mysize = v4->_Mysize;
  if ( Mysize < _Off )
    std::_Xout_of_range(_Message: "invalid string position");
  if ( -1 - Mysize <= _Count )
    std::_Xlength_error(_Message: "string too long");
  if ( _Count == 0 )
    return v4;
  v10 = Mysize + _Count;
  if ( Mysize + _Count == -1 )
    std::_Xlength_error(_Message: "string too long");
  v11 = v4->_Myres;
  if ( v11 < v10 )
  {
    std::string::_Copy(this: v4, _Newsize: v10, _Oldlen: Mysize);
    if ( v10 != 0 )
    {
LABEL_22:
      v12 = v4->_Myres;
      if ( v12 < 0x10 )
        v13 = v4;
      else
        v13 = (std::string *)v4->_Bx._Ptr;
      if ( v12 < 0x10 )
        v14 = v4;
      else
        v14 = (std::string *)v4->_Bx._Ptr;
      memmove(
        dst: (unsigned __int8 *)&v14->_Bx._Buf[_Off + _Count],
        src: (unsigned __int8 *)&v13->_Bx._Buf[_Off],
        count: v4->_Mysize - _Off);
      if ( v4->_Myres < 0x10 )
        v15 = v4;
      else
        v15 = (std::string *)v4->_Bx._Ptr;
      memcpy(dst: (unsigned __int8 *)&v15->_Bx._Buf[_Off], src: (unsigned __int8 *)_Ptr, count: _Count);
      v16 = v4->_Myres < 0x10;
      v4->_Mysize = v10;
      if ( !v16 )
      {
        v4->_Bx._Ptr[v10] = 0;
        return v4;
      }
      v4->_Bx._Buf[v10] = 0;
    }
    return v4;
  }
  if ( v10 != 0 )
    goto LABEL_22;
  v4->_Mysize = 0;
  if ( v11 < 0x10 )
    v4->_Bx._Buf[0] = 0;
  else
    *v4->_Bx._Ptr = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004031C0
// Name: class CStatsMap __near * StatsMap(void)
// Source: json
//------------------------------------------------------------------------------
CStatsMap *__cdecl StatsMap()
{
  return &g_StatsConfig;
}

//------------------------------------------------------------------------------
// Address: 0x004031D0
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
// Address: 0x00403260
// Name: public: std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::~basic_string<char,struct std::char_traits<char>,class std::allocator<char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::string::~string(std::string *this)
{
  if ( this->_Myres >= 0x10 )
    free(pMem: this->_Bx._Ptr);
  this->_Myres = 15;
  this->_Mysize = 0;
  this->_Bx._Buf[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403290
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
// Address: 0x00403380
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
// Address: 0x00403480
// Name: public: bool CStatsMap::ProcessGraph(class CProduct __near *,class COverviewMap __near *,class CGraph __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStatsMap::ProcessGraph(CStatsMap *this, CProduct *pProduct, COverviewMap *pMap, CGraph *pGraph)
{
  char *m_szMapName; // ebx
  int m_iPosY; // edx
  float m_flScale; // xmm0_4
  CHeatMap *v8; // eax
  char result; // al
  char *m_szColumnY; // ebx
  std::string *Ptr; // eax
  IMySQL *pMySQL; // esi
  int v13; // edi
  int v14; // ebx
  const char *v15; // eax
  float strength; // xmm0_4
  char q[512]; // [esp+24h] [ebp-354h] BYREF
  char szDateClause[128]; // [esp+224h] [ebp-154h] BYREF
  char szLimitClause[128]; // [esp+2A4h] [ebp-D4h] BYREF
  int hour; // [esp+324h] [ebp-54h] BYREF
  int dayOfWeek; // [esp+328h] [ebp-50h] BYREF
  int minute; // [esp+32Ch] [ebp-4Ch] BYREF
  int second; // [esp+330h] [ebp-48h] BYREF
  CStatsMap *v24; // [esp+334h] [ebp-44h]
  std::string mapname; // [esp+338h] [ebp-40h] BYREF
  int month; // [esp+354h] [ebp-24h] BYREF
  int year; // [esp+358h] [ebp-20h] BYREF
  int map_x; // [esp+35Ch] [ebp-1Ch]
  int day; // [esp+360h] [ebp-18h] BYREF
  float map_scale; // [esp+364h] [ebp-14h]
  int map_y; // [esp+368h] [ebp-10h]
  int v32; // [esp+374h] [ebp-4h]
  char *scalar; // [esp+380h] [ebp+8h]
  float scalara; // [esp+380h] [ebp+8h]
  bool bHasScalar_3; // [esp+387h] [ebp+Fh]
  CHeatMap *pGrapha; // [esp+388h] [ebp+10h]

  m_szMapName = pMap->m_szMapName;
  v24 = this;
  _Msg(a1: "Processing %s (%s)\n", pGraph->m_szTitle, pMap->m_szMapName);
  m_iPosY = pMap->m_iPosY;
  m_flScale = pMap->m_flScale;
  map_x = pMap->m_iPosX;
  map_y = m_iPosY;
  map_scale = m_flScale;
  v8 = (CHeatMap *)operator new(nSize: 0x34Cu);
  v32 = 0;
  if ( v8 != nullptr )
    pGrapha = CHeatMap::CHeatMap(
                this: v8,
                a2: (int)m_szMapName,
                a3: 0,
                a4: (int)pGraph,
                pszProductName: pProduct->m_szProductName,
                pszMapName: m_szMapName,
                pszOutputName: pGraph->m_szOutputImageName,
                map_x,
                map_y,
                map_scale);
  else
    pGrapha = nullptr;
  v32 = -1;
  result = CHeatMap::ResetImage(this: pGrapha);
  if ( result != 0 )
  {
    mapname._Myres = 15;
    mapname._Mysize = 0;
    mapname._Bx._Buf[0] = 0;
    v32 = 1;
    std::string::assign(this: &mapname, _Ptr: m_szMapName, _Count: strlen(m_szMapName));
    v_escape_string(s: &mapname);
    scalar = "X";
    m_szColumnY = "Y";
    if ( pGraph->m_szColumnX[0] != 0 )
      scalar = pGraph->m_szColumnX;
    if ( pGraph->m_szColumnY[0] != 0 )
      m_szColumnY = pGraph->m_szColumnY;
    bHasScalar_3 = pGraph->m_szColumnScalar[0] != 0;
    System_GetCurrentTimeAndDate(&year, &month, &dayOfWeek, &day, &hour, &minute, &second);
    SubtractDays(iDaysToSubtract: pGraph->m_iDays, &year, &month, &day);
    V_snprintf(pDest: szDateClause, maxLen: 128, pFormat: "AND TimeSubmitted >= %d/%d/%d", month, day, year);
    if ( pGraph->m_iResultLimit <= 0 )
      szLimitClause[0] = 0;
    else
      V_snprintf(
        pDest: szLimitClause,
        maxLen: 128,
        pFormat: "ORDER BY TimeSubmitted DESC LIMIT %d ",
        pGraph->m_iResultLimit);
    Ptr = (std::string *)mapname._Bx._Ptr;
    if ( bHasScalar_3 )
    {
      if ( mapname._Myres < 0x10 )
        Ptr = &mapname;
      V_snprintf(
        pDest: q,
        maxLen: 512,
        pFormat: "select %s as X, %s as Y, %s as Scalar from %s where MapName = '%s' %s %s %s %s;",
        scalar,
        m_szColumnY,
        pGraph->m_szColumnScalar,
        pGraph->m_szTable,
        Ptr->_Bx._Buf,
        szDateClause,
        pGraph->m_szAdditionalWhere,
        g_StatsConfig.m_szWhereClause,
        szLimitClause);
    }
    else
    {
      if ( mapname._Myres < 0x10 )
        Ptr = &mapname;
      V_snprintf(
        pDest: q,
        maxLen: 512,
        pFormat: "select %s as X, %s as Y from %s where MapName = '%s' %s %s %s %s;",
        scalar,
        m_szColumnY,
        pGraph->m_szTable,
        Ptr->_Bx._Buf,
        szDateClause,
        pGraph->m_szAdditionalWhere,
        g_StatsConfig.m_szWhereClause,
        szLimitClause);
    }
    if ( v24->m_bVerbose )
      _Msg(a1: "  Executing query: %s\n", q);
    pMySQL = g_StatsConfig.pMySQL;
    if ( g_StatsConfig.pMySQL->Execute(this: g_StatsConfig.pMySQL, a2: q) != 0 )
    {
      printf(format: "Query %s failed\n", q);
    }
    else
    {
      _Msg(a1: "  Adding points\n");
      if ( pMySQL->SeekToFirstRow(this: pMySQL) )
      {
        while ( pMySQL->NextRow(this: pMySQL) )
        {
          v13 = pMySQL->GetColumnValue_Int(this: pMySQL, a2: 0);
          v14 = pMySQL->GetColumnValue_Int(this: pMySQL, a2: 1);
          if ( bHasScalar_3 )
          {
            v15 = pMySQL->GetColumnValue_String(this: pMySQL, a2: 2);
            scalara = atof(nptr: v15);
            strength = scalara;
          }
          else
          {
            strength = 1.0;
          }
          CHeatMap::AddPoint(
            this: pGrapha,
            x: (float)(v13 - map_x) / map_scale,
            y: (float)(v14 - map_y) * (float)(-1.0 / map_scale),
            strength);
        }
      }
      _Msg(a1: "  Generating image:\n");
      CHeatMap::GenerateAndSaveImage(this: pGrapha);
      ++g_StatsConfig.m_iProcessed;
    }
    if ( mapname._Myres >= 0x10 )
      free(pMem: mapname._Bx._Ptr);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403840
// Name: public: void CStatsMap::ProcessMaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatsMap::ProcessMaps(CStatsMap *this)
{
  CStatsMap *v1; // edi
  CProduct **m_pMemory; // ecx
  int v3; // eax
  CProduct *v4; // esi
  bool v5; // bl
  const char *v6; // eax
  const char *v7; // eax
  int v8; // eax
  CProduct *v9; // ebx
  bool v10; // zf
  const char *m_szProduct; // edi
  int v12; // eax
  int v13; // edi
  CGraph *v14; // ebx
  int v15; // ebx
  CGraph *v16; // edi
  double v17; // st7
  char db[128]; // [esp+Ch] [ebp-C4h] BYREF
  CMySQL_Connect sql; // [esp+8Ch] [ebp-44h] BYREF
  float st; // [esp+A4h] [ebp-2Ch]
  CProduct *pCommonProduct; // [esp+A8h] [ebp-28h]
  COverviewMap *pMap; // [esp+ACh] [ebp-24h]
  int i; // [esp+B0h] [ebp-20h]
  CStatsMap *v24; // [esp+B4h] [ebp-1Ch]
  int p; // [esp+B8h] [ebp-18h]
  int m; // [esp+BCh] [ebp-14h]
  bool bCommon; // [esp+C3h] [ebp-Dh]
  int v28; // [esp+CCh] [ebp-4h]

  v1 = this;
  v24 = this;
  st = _Plat_FloatTime(a1: this);
  v3 = 0;
  i = 0;
  while ( v3 < v1->m_Products.m_Size )
  {
    m_pMemory = v1->m_Products.m_Memory.m_pMemory;
    v4 = m_pMemory[v3];
    if ( v4->m_szProductName[0] != 0 )
    {
      bCommon = _V_stricmp(s1: v4->m_szProductName, s2: "common") == 0;
      if ( _V_stricmp(s1: v1->m_szProduct, s2: "all") == 0
        || _V_stricmp(s1: v1->m_szProduct, s2: v4->m_szProductName) == 0 )
      {
        v5 = bCommon;
LABEL_8:
        if ( v5 )
        {
          v6 = "common_beta";
          if ( !v1->m_bSteamBeta )
            v6 = "common";
          V_snprintf(pDest: db, maxLen: 128, pFormat: v6);
        }
        else
        {
          v7 = "gamestats_%s_beta";
          if ( !v1->m_bSteamBeta )
            v7 = "gamestats_%s";
          V_snprintf(pDest: db, maxLen: 128, pFormat: v7, v4);
        }
        CMySQL_Connect::CMySQL_Connect(
          this: &sql,
          pszDatabase: db,
          pszHost: g_StatsConfig.m_szServer,
          pszUser: g_StatsConfig.m_szUser,
          pszPassword: g_StatsConfig.m_szPassword);
        v8 = 0;
        v28 = 0;
        g_StatsConfig.pMySQL = sql.m_bSqlOkay ? sql.m_mysql : nullptr;
        if ( v5 )
        {
          p = 0;
          if ( v1->m_Products.m_Size > 0 )
          {
            do
            {
              v9 = v1->m_Products.m_Memory.m_pMemory[v8];
              v10 = v9->m_szProductName[0] == 0;
              pCommonProduct = v9;
              if ( !v10 && _V_stricmp(s1: v9->m_szProductName, s2: "common") != 0 )
              {
                m_szProduct = v1->m_szProduct;
                if ( _V_stricmp(s1: m_szProduct, s2: "all") == 0
                  || _V_stricmp(s1: m_szProduct, s2: v9->m_szProductName) == 0 )
                {
                  v12 = 0;
                  for ( m = 0; v12 < v9->m_Maps.m_Size; m = v12 )
                  {
                    v13 = 0;
                    pMap = v9->m_Maps.m_Memory.m_pMemory[v12];
                    if ( v4->m_Graphs.m_Size > 0 )
                    {
                      do
                      {
                        v14 = v4->m_Graphs.m_Memory.m_pMemory[v13];
                        if ( v14->m_szMapName[0] == 0 || _V_stricmp(s1: v14->m_szMapName, s2: pMap->m_szMapName) == 0 )
                          CStatsMap::ProcessGraph(this: v24, pProduct: pCommonProduct, pMap, pGraph: v14);
                        ++v13;
                      }
                      while ( v13 < v4->m_Graphs.m_Size );
                      v12 = m;
                      v9 = pCommonProduct;
                    }
                    ++v12;
                  }
                }
                v1 = v24;
              }
              v8 = p + 1;
              p = v8;
            }
            while ( v8 < v1->m_Products.m_Size );
          }
        }
        else
        {
          m = 0;
          if ( v4->m_Maps.m_Size > 0 )
          {
            do
            {
              v15 = 0;
              p = (int)v4->m_Maps.m_Memory.m_pMemory[v8];
              if ( v4->m_Graphs.m_Size > 0 )
              {
                do
                {
                  v16 = v4->m_Graphs.m_Memory.m_pMemory[v15];
                  if ( v16->m_szMapName[0] == 0 || _V_stricmp(s1: v16->m_szMapName, s2: (const char *)(p + 12)) == 0 )
                    CStatsMap::ProcessGraph(this: v24, pProduct: v4, pMap: (COverviewMap *)p, pGraph: v16);
                  ++v15;
                }
                while ( v15 < v4->m_Graphs.m_Size );
                v8 = m;
                v1 = v24;
              }
              m = ++v8;
            }
            while ( v8 < v4->m_Maps.m_Size );
          }
        }
        v28 = -1;
        CMySQL_Connect::~CMySQL_Connect(this: &sql);
        goto LABEL_41;
      }
      v5 = bCommon;
      if ( bCommon )
        goto LABEL_8;
    }
LABEL_41:
    v3 = i + 1;
    i = v3;
  }
  v17 = _Plat_FloatTime(a1: m_pMemory);
  _Msg(a1: "\nFinished.  Processed %d maps in %f seconds\n", v1->m_iProcessed, v17 - st);
}

//------------------------------------------------------------------------------
// Address: 0x00403B50
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  void (__thiscall ***v3)(_DWORD, int, const char **); // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  bool v7; // bl
  int v8; // eax
  const char *v9; // eax
  int v10; // eax
  const char *v11; // eax
  int v12; // eax
  const char *v13; // eax
  int v14; // eax
  const char *v15; // eax
  int v16; // eax
  const char *v17; // eax
  int v18; // eax
  const char *v19; // eax
  int v20; // eax
  const char *v21; // eax
  int v22; // eax
  const char *v23; // eax
  int v24; // eax
  const char *v25; // eax
  int v26; // eax
  int v27; // eax
  CXMLConfig v29; // [esp+8h] [ebp-10h] BYREF

  v3 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  InitDefaultFileSystem();
  v4 = _CommandLine();
  v7 = true;
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "/?") == 0 )
  {
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-h") == 0 )
    {
      v6 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "--help") == 0 )
        v7 = false;
    }
  }
  v8 = _CommandLine();
  v9 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v8 + 32))(
                       a1: v8,
                       a2: "-server",
                       a3: "gamestats");
  V_snprintf(pDest: g_StatsConfig.m_szServer, maxLen: 128, pFormat: "%s", v9);
  v10 = _CommandLine();
  v11 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v10 + 32))(
                        a1: v10,
                        a2: "-user",
                        a3: "stats");
  V_snprintf(pDest: g_StatsConfig.m_szUser, maxLen: 128, pFormat: "%s", v11);
  v12 = _CommandLine();
  v13 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v12 + 32))(
                        a1: v12,
                        a2: "-password",
                        a3: "gamestats");
  V_snprintf(pDest: g_StatsConfig.m_szPassword, maxLen: 128, pFormat: "%s", v13);
  v14 = _CommandLine();
  v15 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v14 + 32))(
                        a1: v14,
                        a2: "-overviewdir",
                        a3: "./images");
  V_snprintf(pDest: g_StatsConfig.m_szImageInputDir, maxLen: 260, pFormat: "%s", v15);
  v16 = _CommandLine();
  v17 = (const char *)(*(int (__thiscall **)(int, const char *, void *))(*(_DWORD *)v16 + 32))(
                        a1: v16,
                        a2: "-outputdir",
                        a3: &unk_41FA6B);
  V_snprintf(pDest: g_StatsConfig.m_szImageOutputDir, maxLen: 260, pFormat: "%s", v17);
  v18 = _CommandLine();
  v19 = (const char *)(*(int (__thiscall **)(int, const char *, void *))(*(_DWORD *)v18 + 32))(
                        a1: v18,
                        a2: "-xmldir",
                        a3: &unk_41FA6B);
  V_snprintf(pDest: g_StatsConfig.m_szXMLDir, maxLen: 260, pFormat: "%s", v19);
  v20 = _CommandLine();
  v21 = (const char *)(*(int (__thiscall **)(int, const char *, void *))(*(_DWORD *)v20 + 32))(
                        a1: v20,
                        a2: "-where",
                        a3: &unk_41FA6B);
  V_snprintf(pDest: g_StatsConfig.m_szWhereClause, maxLen: 1024, pFormat: "%s", v21);
  v22 = _CommandLine();
  v23 = (const char *)(*(int (__thiscall **)(int, const char *, void *))(*(_DWORD *)v22 + 32))(
                        a1: v22,
                        a2: "-product",
                        a3: &unk_41FA6B);
  V_snprintf(pDest: g_StatsConfig.m_szProduct, maxLen: 64, pFormat: "%s", v23);
  v24 = _CommandLine();
  v25 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v24 + 32))(
                        a1: v24,
                        a2: "-scale",
                        a3: "1.0");
  g_StatsConfig.m_flScale = atof(nptr: v25);
  v26 = _CommandLine();
  g_StatsConfig.m_bSteamBeta = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v26 + 40))(
                                 a1: v26,
                                 a2: "-steambeta") != 0;
  v27 = _CommandLine();
  g_StatsConfig.m_bVerbose = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v27 + 40))(a1: v27, a2: "-verbose") != 0;
  if ( g_StatsConfig.m_szImageOutputDir[0] != 0 && !v7 && g_StatsConfig.m_szProduct[0] != 0 )
  {
    CXMLConfig::CXMLConfig(this: &v29);
    CXMLConfig::ReadXMLFile(this: &v29, a2: v7);
    CStatsMap::ProcessMaps(this: &g_StatsConfig);
    CHeatMap::DeleteLookup();
    return 0;
  }
  else
  {
    _Msg(
      a1: "\n"
      " Version = 1.2\n"
      " Date [ Dec 28 2010 16:57:41 ]\n"
      " Copyright Valve 2008.  All rights reserved.\n"
      " \n"
      " Required parameters:\n"
      "  -outputdir <imagedir>     { directory for output jpgs }\n"
      "  -product <productname>    { name of product to create images for (use\n"
      "                              product's shortname from gamestatsweb.xml.\n"
      "                              Use 'all' to build all products }\n"
      " \n"
      " Optional parameters:\n"
      "  -overviewdir <imagedir>   { directory where overview bmps are located }  -xmldir <xmldir>          { directory t"
      "o load gamestatsweb.xml from }\n"
      "  -scale <imagescalefactor> { scales output images }\n"
      "  -steambeta                { use beta databases }\n"
      "  -verbose                  { show queries and progress bars }\n"
      "  -server <sqldbhost>\n"
      "  -user <sqluser>\n"
      "  -password <sqlpw>\n"
      "  -where <additional where clause>\n");
    return -1;
  }
}
