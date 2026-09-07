// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: devtools/statsmap/mysql_helpers.cpp
// Functions: 4
// ============================================================

#include "devtools\statsmap\mysql_helpers.h"

//------------------------------------------------------------------------------
// Address: 0x004029D0
// Name: public: CMySQL_Connect::CMySQL_Connect(char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMySQL_Connect *__thiscall CMySQL_Connect::CMySQL_Connect(
        CMySQL_Connect *this,
        const char *pszDatabase,
        const char *pszHost,
        const char *pszUser,
        const char *pszPassword)
{
  struct CSysModule *Module; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IMySQL *v8; // eax

  this->__vftable = (CMySQL_Connect_vtbl *)&CMySQL_Connect::`vftable';
  this->m_sql = nullptr;
  this->m_factory = nullptr;
  this->m_mysql = nullptr;
  this->m_bSqlOkay = false;
  Module = Sys_LoadModule(pModuleName: "mysql_wrapper");
  this->m_sql = Module;
  if ( Module != nullptr )
  {
    Factory = Sys_GetFactory(pModule: Module);
    this->m_factory = Factory;
    if ( Factory != nullptr )
    {
      v8 = (IMySQL *)Factory(a1: "MySQLWrapper001", a2: nullptr);
      this->m_mysql = v8;
      if ( v8 != nullptr )
      {
        if ( v8->InitMySQL(this: v8, a2: pszDatabase, a3: pszHost, a4: pszUser, a5: pszPassword) )
        {
          this->m_bSqlOkay = true;
          _Msg(a1: "Successfully connected to database %s on host %s, user %s\n", pszDatabase, pszHost, pszUser);
        }
        else
        {
          _Msg(a1: "m_mysql->InitMySQL( %s, %s, %s, [password]) failed\n", pszDatabase, pszHost, pszUser);
        }
        return this;
      }
      else
      {
        _Msg(a1: "Unable to get MYSQL_WRAPPER_VERSION_NAME(%s) from mysql_wrapper\n", "MySQLWrapper001");
        return this;
      }
    }
    else
    {
      _Msg(a1: "Sys_GetFactory on mysql_wrapper failed\n");
      return this;
    }
  }
  else
  {
    _Msg(a1: "Sys_LoadModule( mysql_wrapper ) failed\n");
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402AD0
// Name: public: virtual CMySQL_Connect::~CMySQL_Connect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMySQL_Connect::~CMySQL_Connect(CMySQL_Connect *this)
{
  bool v2; // zf
  IMySQL *m_mysql; // ecx

  v2 = !this->m_bSqlOkay;
  this->__vftable = (CMySQL_Connect_vtbl *)&CMySQL_Connect::`vftable';
  if ( !v2 )
  {
    m_mysql = this->m_mysql;
    if ( m_mysql != nullptr )
    {
      m_mysql->Release(this: m_mysql);
      this->m_mysql = nullptr;
    }
    if ( this->m_sql != nullptr )
    {
      Sys_UnloadModule(pModule: this->m_sql);
      this->m_sql = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402B90
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
    result = (char *)operator new(nSize: _Count);
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
// Address: 0x00403010
// Name: void v_escape_string(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl v_escape_string(std::string *s)
{
  unsigned int v1; // esi
  unsigned int v2; // ebx
  unsigned int Myres; // eax
  std::string *Ptr; // ecx
  std::string *v5; // eax
  const char *v6; // [esp-10h] [ebp-14h]

  if ( s->_Mysize != 0 )
  {
    v1 = 0;
    v2 = 1;
    do
    {
      Myres = s->_Myres;
      if ( Myres < 0x10 )
        Ptr = s;
      else
        Ptr = (std::string *)s->_Bx._Ptr;
      switch ( Ptr->_Bx._Buf[v1] )
      {
        case 0:
          if ( Myres < 0x10 )
            v5 = s;
          else
            v5 = (std::string *)s->_Bx._Ptr;
          v6 = "0";
          goto LABEL_35;
        case 0xA:
          if ( Myres < 0x10 )
            v5 = s;
          else
            v5 = (std::string *)s->_Bx._Ptr;
          v6 = "n";
          goto LABEL_35;
        case 0xD:
          if ( Myres < 0x10 )
            v5 = s;
          else
            v5 = (std::string *)s->_Bx._Ptr;
          v6 = "r";
          goto LABEL_35;
        case 0x1A:
          if ( Myres < 0x10 )
            v5 = s;
          else
            v5 = (std::string *)s->_Bx._Ptr;
          v6 = "Z";
          goto LABEL_35;
        case 0x22:
          if ( Myres < 0x10 )
            v5 = s;
          else
            v5 = (std::string *)s->_Bx._Ptr;
          v6 = "\"";
          goto LABEL_35;
        case 0x27:
          if ( Myres < 0x10 )
            v5 = s;
          else
            v5 = (std::string *)s->_Bx._Ptr;
          v6 = "'";
          goto LABEL_35;
        case 0x5C:
          if ( Myres < 0x10 )
            v5 = s;
          else
            v5 = (std::string *)s->_Bx._Ptr;
          v6 = "\\";
LABEL_35:
          v5->_Bx._Buf[v1] = 92;
          std::string::insert(this: s, _Off: v2, _Ptr: v6, _Count: 1u);
          ++v1;
          ++v2;
          break;
        default:
          break;
      }
      ++v1;
      ++v2;
    }
    while ( v1 < s->_Mysize );
  }
}
