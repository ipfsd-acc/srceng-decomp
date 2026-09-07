// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: devtools/processgamestats2/util_mysql.cpp
// Functions: 14
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00405E20
// Name: int ExecuteStmt(class IMySQL __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ExecuteStmt(IMySQL *mysql, const char *szStmt)
{
  int result; // eax
  int v3; // esi
  const char *v4; // eax

  result = mysql->Execute(this: mysql, a2: szStmt);
  v3 = result;
  if ( result != 0 )
  {
    printf(format: "Error: sql statement failed.\r\n");
    printf(format: "\tStatement: %s\r\n", szStmt);
    v4 = mysql->GetLastError(this: mysql);
    printf(format: "\tError text: %s\r\n", v4);
    printf(format: "\tError code: %d\r\n", v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405E80
// Name: bool ExecuteStmtGetSingleValue(class IMySQL __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExecuteStmtGetSingleValue(IMySQL *mysql, const char *szStmt, char *szValueBuf, int cValueBuf)
{
  int v4; // edi
  const char *v5; // eax
  IMySQLRowSet *v7; // esi
  const char *v8; // eax
  int m_iColumn; // [esp-8h] [ebp-1Ch]
  CColumnValue value; // [esp+Ch] [ebp-8h] BYREF

  v4 = mysql->Execute(this: mysql, a2: szStmt);
  if ( v4 != 0 )
  {
    printf(format: "Error: sql statement failed.\r\n");
    printf(format: "\tStatement: %s\r\n", szStmt);
    v5 = mysql->GetLastError(this: mysql);
    printf(format: "\tError text: %s\r\n", v5);
    printf(format: "\tError code: %d\r\n", v4);
    return 0;
  }
  v7 = mysql->DuplicateRowSet(this: mysql);
  if ( v7 == nullptr || !v7->NextRow(this: v7) )
    return 0;
  v7->GetColumnValue_2(this: v7, result: &value, a3: 0);
  m_iColumn = value.m_iColumn;
  v8 = (const char *)((int (__thiscall *)(IMySQLRowSet *))value.m_pSQL->GetColumnValue_String)(a1: value.m_pSQL);
  V_strncpy(pDest: szValueBuf, pSrc: v8, maxLen: m_iColumn);
  ((void (__thiscall *)(IMySQLRowSet *, int))v7->Release)(a1: v7, a2: cValueBuf);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405F40
// Name: bool ExecuteStmtGetSingleValue(class IMySQL __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExecuteStmtGetSingleValue(IMySQL *mysql, const char *szStmt, int *pVal)
{
  int v3; // edi
  const char *v4; // eax
  IMySQLRowSet *v6; // esi

  v3 = mysql->Execute(this: mysql, a2: szStmt);
  if ( v3 != 0 )
  {
    printf(format: "Error: sql statement failed.\r\n");
    printf(format: "\tStatement: %s\r\n", szStmt);
    v4 = mysql->GetLastError(this: mysql);
    printf(format: "\tError text: %s\r\n", v4);
    printf(format: "\tError code: %d\r\n", v3);
    return 0;
  }
  v6 = mysql->DuplicateRowSet(this: mysql);
  if ( v6 == nullptr || !v6->NextRow(this: v6) )
    return 0;
  *pVal = v6->GetColumnValue_Int(this: v6, a2: 0);
  v6->Release(this: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405FE0
// Name: class IMySQL __near * ConnectToMySQL(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMySQL *__cdecl ConnectToMySQL(const char *szHost, const char *szUserName, const char *szPassword)
{
  int v3; // esi
  struct CSysModule *Module; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax

  v3 = 0;
  Module = Sys_LoadModule(pModuleName: "mysql_wrapper");
  if ( Module != nullptr )
  {
    Factory = Sys_GetFactory(pModule: Module);
    if ( Factory == nullptr )
    {
      printf(format: "Sys_GetFactory on mysql_wrapper failed\r\n");
      return nullptr;
    }
    v3 = (int)Factory(a1: "MySQLWrapper001", a2: nullptr);
    if ( v3 == 0 )
    {
      printf(format: "Unable to get MYSQL_WRAPPER_VERSION_NAME(%s) from mysql_wrapper\r\n", "MySQLWrapper001");
      return nullptr;
    }
    if ( (*(unsigned __int8 (__thiscall **)(int, const char *, const char *, const char *, const char *))(*(_DWORD *)v3 + 40))(
           a1: v3,
           a2: str,
           a3: szHost,
           a4: szUserName,
           a5: szPassword) == 0 )
    {
      printf(format: "mysql->InitMySQL( %s, %s, [password]) failed\r\n", szHost, szUserName);
      return nullptr;
    }
  }
  else
  {
    printf(format: "Sys_LoadModule( mysql_wrapper ) failed\r\n");
  }
  return (IMySQL *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00406090
// Name: void OverWriteCharsWeHate(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OverWriteCharsWeHate(char *pStr)
{
  char *i; // eax

  for ( i = pStr; *i != 0; ++i )
  {
    switch ( *i )
    {
      case 10:
      case 13:
      case 26:
      case 34:
      case 39:
      case 59:
      case 92:
        *i = 32;
        break;
      default:
        continue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406120
// Name: char const __near * GetCurrentTimeString(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurrentTimeString()
{
  tm localTime; // [esp+0h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: &localTime);
  _Plat_GetTimeString(a1: &localTime, a2: szTime_0, a3: 64);
  return szTime_0;
}

//------------------------------------------------------------------------------
// Address: 0x00406150
// Name: bool CreateDatabase(class IMySQL __near *,class CDatabase __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateDatabase(IMySQL *mysql, CDatabase *database)
{
  int v2; // edi
  const char *v3; // eax

  V_snprintf(pDest: q, maxLen: 0x4000, pFormat: "create database %s", database->m_szName);
  v2 = mysql->Execute(this: mysql, a2: q);
  if ( v2 == 0 )
    return 1;
  printf(format: "Error: sql statement failed.\r\n");
  printf(format: "\tStatement: %s\r\n", q);
  v3 = mysql->GetLastError(this: mysql);
  printf(format: "\tError text: %s\r\n", v3);
  printf(format: "\tError code: %d\r\n", v2);
  printf(format: "Error: Failed to create database '%s'.\r\n", database->m_szName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004061E0
// Name: bool DropTable(class IMySQL __near *,class CDatabase __near &,class CTable __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DropTable(IMySQL *mysql, CDatabase *database, CTable *table)
{
  int v3; // edi
  const char *v4; // eax

  V_snprintf(pDest: q, maxLen: 0x4000, pFormat: "drop table %s;", table->m_szName);
  v3 = mysql->Execute(this: mysql, a2: q);
  if ( v3 == 0 )
    return 1;
  printf(format: "Error: sql statement failed.\r\n");
  printf(format: "\tStatement: %s\r\n", q);
  v4 = mysql->GetLastError(this: mysql);
  printf(format: "\tError text: %s\r\n", v4);
  printf(format: "\tError code: %d\r\n", v3);
  printf(format: "Error: Failed to drop table '%s'.\r\n", table->m_szName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406270
// Name: bool SelectDatabase(class IMySQL __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SelectDatabase(IMySQL *mysql, const char *szDatabase)
{
  char query[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( _V_stricmp(s1: szCurDatabase, s2: szDatabase) != 0 )
  {
    V_snprintf(pDest: query, maxLen: 1024, pFormat: "use %s;", szDatabase);
    if ( ExecuteStmt(mysql, szStmt: query) != 0 )
    {
      printf(format: "Error: failed to find database %s, does it exist?  It must be manually created.\r\n", szDatabase);
      return 0;
    }
    V_strncpy(pDest: szCurDatabase, pSrc: szDatabase, maxLen: 1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004062F0
// Name: bool CreateTable(class IMySQL __near *,class CDatabase __near &,class CTable __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateTable(IMySQL *mysql, CDatabase *database, CTable *table)
{
  CTable *v3; // esi
  int v4; // ebx
  CFmtStrN<256> *v5; // eax
  CFmtStrN<256> *v6; // eax
  int v7; // esi
  int v8; // edi
  const char *v9; // eax
  CFmtStrN<256> v11; // [esp+Ch] [ebp-218h] BYREF
  CColumn column; // [esp+118h] [ebp-10Ch] BYREF
  int iColumn; // [esp+21Ch] [ebp-8h]
  int iCount; // [esp+220h] [ebp-4h]

  v3 = table;
  V_snprintf(pDest: q, maxLen: 0x4000, pFormat: "create table %s (", table->m_szName);
  v4 = 0;
  iCount = table->m_vecColumn.m_Size;
  iColumn = 0;
  if ( iCount > 0 )
  {
    while ( 1 )
    {
      column = v3->m_vecColumn.m_Memory.m_pMemory[v4];
      v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "%s %s", column.m_szName, column.m_szType);
      V_strncat(pDest: q, pSrc: v5->m_szBuf, destBufferSize: 0x4000u, max_chars_to_copy: -1);
      if ( column.m_bAutoIncrement )
        V_strncat(pDest: q, pSrc: " auto_increment", destBufferSize: 0x4000u, max_chars_to_copy: -1);
      if ( column.m_bIndexed )
      {
        v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: ",index(%s)", column.m_szName);
        V_strncat(pDest: q, pSrc: v6->m_szBuf, destBufferSize: 0x4000u, max_chars_to_copy: -1);
      }
      v7 = iColumn;
      if ( iColumn < iCount - 1 )
        V_strncat(pDest: q, pSrc: ",", destBufferSize: 0x4000u, max_chars_to_copy: -1);
      ++v4;
      iColumn = v7 + 1;
      if ( v7 + 1 >= iCount )
        break;
      v3 = table;
    }
  }
  V_strncat(pDest: q, pSrc: ") engine=myisam;", destBufferSize: 0x4000u, max_chars_to_copy: -1);
  v8 = mysql->Execute(this: mysql, a2: q);
  if ( v8 == 0 )
    return 1;
  printf(format: "Error: sql statement failed.\r\n");
  printf(format: "\tStatement: %s\r\n", q);
  v9 = mysql->GetLastError(this: mysql);
  printf(format: "\tError text: %s\r\n", v9);
  printf(format: "\tError code: %d\r\n", v8);
  printf(format: "Error: Failed to create table '%s'.\r\n", table->m_szName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004064A0
// Name: bool DropColumn(class IMySQL __near *,class CDatabase __near &,class CTable __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DropColumn(IMySQL *mysql, CDatabase *database, CTable *table, int iColumn)
{
  CColumn *v4; // esi
  const char *v5; // eax
  int iColumna; // [esp+20h] [ebp+14h]

  v4 = &table->m_vecColumn.m_Memory.m_pMemory[iColumn];
  V_snprintf(pDest: q, maxLen: 0x4000, pFormat: "alter table %s drop column %s;", table->m_szName, v4->m_szName);
  iColumna = mysql->Execute(this: mysql, a2: q);
  if ( iColumna == 0 )
    return 1;
  printf(format: "Error: sql statement failed.\r\n");
  printf(format: "\tStatement: %s\r\n", q);
  v5 = mysql->GetLastError(this: mysql);
  printf(format: "\tError text: %s\r\n", v5);
  printf(format: "\tError code: %d\r\n", iColumna);
  printf(format: "Error: Failed to drop column %s to table %s.\r\n", v4->m_szName, table->m_szName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406550
// Name: bool AddIndex(class IMySQL __near *,class CDatabase __near &,class CTable __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddIndex(IMySQL *mysql, CDatabase *database, CTable *table, int iColumn)
{
  CColumn *v4; // esi
  const char *v5; // eax
  int iColumna; // [esp+20h] [ebp+14h]

  v4 = &table->m_vecColumn.m_Memory.m_pMemory[iColumn];
  V_snprintf(pDest: q, maxLen: 0x4000, pFormat: "alter table %s add index(%s);", table->m_szName, v4->m_szName);
  iColumna = mysql->Execute(this: mysql, a2: q);
  if ( iColumna == 0 )
    return 1;
  printf(format: "Error: sql statement failed.\r\n");
  printf(format: "\tStatement: %s\r\n", q);
  v5 = mysql->GetLastError(this: mysql);
  printf(format: "\tError text: %s\r\n", v5);
  printf(format: "\tError code: %d\r\n", iColumna);
  printf(format: "Error: Failed to add index on column %s on table %s.\r\n", v4->m_szName, table->m_szName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406600
// Name: bool IsTableInList(char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsTableInList(const char *szTable, CUtlVector<char *,CUtlMemory<char *,int> > *vecTables)
{
  int v2; // esi

  v2 = 0;
  if ( vecTables->m_Size <= 0 )
    return 0;
  while ( _V_stricmp(s1: szTable, s2: vecTables->m_Memory.m_pMemory[v2]) != 0 )
  {
    if ( ++v2 >= vecTables->m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406640
// Name: bool AddColumn(class IMySQL __near *,class CDatabase __near &,class CTable __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AddColumn(IMySQL *mysql, CDatabase *database, CTable *table, int iColumn)
{
  CColumn *v4; // esi
  int v5; // ebx
  const char *v6; // eax

  v4 = &table->m_vecColumn.m_Memory.m_pMemory[iColumn];
  V_snprintf(pDest: q, maxLen: 0x4000, pFormat: "alter table %s add %s %s", table->m_szName, v4->m_szName, v4->m_szType);
  if ( v4->m_bAutoIncrement )
    V_strncat(pDest: q, pSrc: " auto_increment", destBufferSize: 0x4000u, max_chars_to_copy: -1);
  V_strncat(pDest: q, pSrc: ";", destBufferSize: 0x4000u, max_chars_to_copy: -1);
  v5 = mysql->Execute(this: mysql, a2: q);
  if ( v5 != 0 )
  {
    printf(format: "Error: sql statement failed.\r\n");
    printf(format: "\tStatement: %s\r\n", q);
    v6 = mysql->GetLastError(this: mysql);
    printf(format: "\tError text: %s\r\n", v6);
    printf(format: "\tError code: %d\r\n", v5);
    printf(format: "Error: Failed to add column %s to table %s.\r\n", v4->m_szName, table->m_szName);
    return false;
  }
  return !v4->m_bIndexed || AddIndex(mysql, database, table, iColumn) != 0;
}
