// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/axes2.cpp
// Functions: 1
// ============================================================

#include "hammer\axes2.h"

//------------------------------------------------------------------------------
// Address: 0x100015B0
// Name: public: void Axes2::SetAxes(int,bool,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Axes2::SetAxes(Axes2 *this, int h, bool bInvertH, int v, bool bInvertV)
{
  this->bInvertHorz = bInvertH;
  this->bInvertVert = bInvertV;
  this->axHorz = h;
  this->axVert = v;
  if ( h != 0 && v != 0 )
    this->axThird = 0;
  if ( h != 1 && v != 1 )
    this->axThird = 1;
  if ( h != 2 && v != 2 )
    this->axThird = 2;
}
