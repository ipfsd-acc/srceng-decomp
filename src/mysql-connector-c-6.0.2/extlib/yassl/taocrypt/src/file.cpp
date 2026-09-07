// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/file.cpp
// Functions: 1
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\file.h"

//------------------------------------------------------------------------------
// Address: 0x0044DE90
// Name: public: void TaoCrypt::Source::reset(class TaoCrypt::Block<unsigned char,class TaoCrypt::AllocatorWithCleanup<unsigned char>> __near &)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall TaoCrypt::Source::reset(int *this, int *a2)
{
  int v3; // edx
  int v4; // edx

  v3 = *this;
  *this = *a2;
  *a2 = v3;
  v4 = *(this + 1);
  *(this + 1) = a2[1];
  a2[1] = v4;
  *(this + 3) = 0;
  return a2;
}
