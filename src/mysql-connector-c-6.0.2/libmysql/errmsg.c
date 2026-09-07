// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/libmysql/errmsg.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040FE10
// Name: _init_client_errs
// Source: json
//------------------------------------------------------------------------------
int init_client_errs()
{
  return my_error_register(a1: &client_errors, a2: 2000, a3: 2058);
}
