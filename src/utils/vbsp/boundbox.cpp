// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/boundbox.cpp
// Functions: 7
// ============================================================

#include "utils\vbsp\boundbox.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: class Vector __near & Vector::operator=(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator=(Vector *this, const Vector *vOther)
{
  *this = *vOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401020
// Name: public: float __near & Vector::operator[](int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator[](Vector *this, int i)
{
  return (Vector *)((char *)this + 4 * i);
}

//------------------------------------------------------------------------------
// Address: 0x00401030
// Name: public: float Vector::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall Vector::operator[](Vector *this, int i)
{
  return *(&this->x + i);
}

//------------------------------------------------------------------------------
// Address: 0x00401070
// Name: public: class Vector Vector::operator+(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator+(Vector *this, Vector *result, const Vector *v)
{
  result->x = v->x + this->x;
  result->y = v->y + this->y;
  result->z = v->z + this->z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004010B0
// Name: public: bool BoundBox::ContainsPoint(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall BoundBox::ContainsPoint(BoundBox *this, const Vector *pt)
{
  int v2; // eax
  Vector *i; // ecx
  float v4; // xmm0_4

  v2 = 0;
  for ( i = &this->bmaxs; ; i = (Vector *)((char *)i + 4) )
  {
    v4 = *(&pt->x + v2);
    if ( i[-1].x > v4 || v4 > i->x )
      break;
    if ( ++v2 >= 3 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004010F0
// Name: public: virtual bool BoundBox::IsIntersectingBox(class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall BoundBox::IsIntersectingBox(BoundBox *this, const Vector *pfMins, const Vector *pfMaxs)
{
  return this->bmins.x < pfMaxs->x
      && pfMins->x < this->bmaxs.x
      && this->bmins.y < pfMaxs->y
      && pfMins->y < this->bmaxs.y
      && this->bmins.z < pfMaxs->z
      && pfMins->z < this->bmaxs.z;
}

//------------------------------------------------------------------------------
// Address: 0x00401150
// Name: public: BoundBox::BoundBox(void)
// Source: json
//------------------------------------------------------------------------------
BoundBox *__thiscall BoundBox::BoundBox(BoundBox *this)
{
  this->__vftable = (BoundBox_vtbl *)&BoundBox::`vftable';
  this->bmins.z = 99999.0;
  this->bmins.y = 99999.0;
  this->bmins.x = 99999.0;
  this->bmaxs.z = -99999.0;
  this->bmaxs.y = -99999.0;
  this->bmaxs.x = -99999.0;
  return this;
}
