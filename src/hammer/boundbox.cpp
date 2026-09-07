// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/boundbox.cpp
// Functions: 17
// ============================================================

#include "hammer\boundbox.h"

//------------------------------------------------------------------------------
// Address: 0x10001600
// Name: public: class Vector __near & Vector::operator=(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator=(Vector *this, const Vector *vOther)
{
  *this = *vOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001620
// Name: public: float __near & Vector::operator[](int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator[](Vector *this, int i)
{
  return (Vector *)((char *)this + 4 * i);
}

//------------------------------------------------------------------------------
// Address: 0x10001630
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
// Address: 0x10001670
// Name: public: BoundBox::BoundBox(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BoundBox *__thiscall BoundBox::BoundBox(BoundBox *this, const Vector *mins, const Vector *maxs)
{
  double x; // st7

  x = mins->x;
  this->__vftable = (BoundBox_vtbl *)&BoundBox::`vftable';
  this->bmins.x = x;
  this->bmins.y = mins->y;
  this->bmins.z = mins->z;
  this->bmaxs = *maxs;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100016B0
// Name: public: void BoundBox::ResetBounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BoundBox::ResetBounds(BoundBox *this)
{
  this->bmins.z = 99999.0;
  this->bmins.y = 99999.0;
  this->bmins.x = 99999.0;
  this->bmaxs.z = -99999.0;
  this->bmaxs.y = -99999.0;
  this->bmaxs.x = -99999.0;
}

//------------------------------------------------------------------------------
// Address: 0x100016E0
// Name: public: void BoundBox::UpdateBounds(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BoundBox::UpdateBounds(BoundBox *this, const Vector *pt)
{
  float y; // xmm0_4
  float z; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4

  if ( this->bmins.x > pt->x )
    this->bmins.x = pt->x;
  y = pt->y;
  if ( this->bmins.y > y )
    this->bmins.y = y;
  z = pt->z;
  if ( this->bmins.z > z )
    this->bmins.z = z;
  if ( pt->x > this->bmaxs.x )
    this->bmaxs.x = pt->x;
  v4 = pt->y;
  if ( v4 > this->bmaxs.y )
    this->bmaxs.y = v4;
  v5 = pt->z;
  if ( v5 > this->bmaxs.z )
    this->bmaxs.z = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10001760
// Name: public: void BoundBox::UpdateBounds(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BoundBox::UpdateBounds(BoundBox *this, const Vector *mins, const Vector *maxs)
{
  float y; // xmm0_4
  float z; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4

  if ( this->bmins.x > mins->x )
    this->bmins.x = mins->x;
  y = mins->y;
  if ( this->bmins.y > y )
    this->bmins.y = y;
  z = mins->z;
  if ( this->bmins.z > z )
    this->bmins.z = z;
  if ( maxs->x > this->bmaxs.x )
    this->bmaxs.x = maxs->x;
  v5 = maxs->y;
  if ( v5 > this->bmaxs.y )
    this->bmaxs.y = v5;
  v6 = maxs->z;
  if ( v6 > this->bmaxs.z )
    this->bmaxs.z = v6;
}

//------------------------------------------------------------------------------
// Address: 0x100017E0
// Name: public: void BoundBox::UpdateBounds(class BoundBox const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BoundBox::UpdateBounds(BoundBox *this, const BoundBox *pBox)
{
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  x = pBox->bmins.x;
  if ( this->bmins.x > x )
    this->bmins.x = x;
  y = pBox->bmins.y;
  if ( this->bmins.y > y )
    this->bmins.y = y;
  z = pBox->bmins.z;
  if ( this->bmins.z > z )
    this->bmins.z = z;
  v5 = pBox->bmaxs.x;
  if ( v5 > this->bmaxs.x )
    this->bmaxs.x = v5;
  v6 = pBox->bmaxs.y;
  if ( v6 > this->bmaxs.y )
    this->bmaxs.y = v6;
  v7 = pBox->bmaxs.z;
  if ( v7 > this->bmaxs.z )
    this->bmaxs.z = v7;
}

//------------------------------------------------------------------------------
// Address: 0x10001860
// Name: public: void BoundBox::GetBoundsCenter(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BoundBox::GetBoundsCenter(BoundBox *this, Vector *ptdest)
{
  float v2; // xmm1_4
  float v3; // xmm2_4

  v2 = (float)(this->bmaxs.y + this->bmins.y) * 0.5;
  v3 = (float)(this->bmaxs.z + this->bmins.z) * 0.5;
  ptdest->x = (float)(this->bmaxs.x + this->bmins.x) * 0.5;
  ptdest->y = v2;
  ptdest->z = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100018B0
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
// Address: 0x100018F0
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
// Address: 0x10001950
// Name: public: bool BoundBox::IsInsideBox(class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall BoundBox::IsInsideBox(BoundBox *this, const Vector *pfMins, const Vector *pfMaxs)
{
  return pfMins->x <= this->bmins.x
      && this->bmaxs.x <= pfMaxs->x
      && pfMins->y <= this->bmins.y
      && this->bmaxs.y <= pfMaxs->y
      && pfMins->z <= this->bmins.z
      && this->bmaxs.z <= pfMaxs->z;
}

//------------------------------------------------------------------------------
// Address: 0x100019B0
// Name: public: bool BoundBox::IsValidBox(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall BoundBox::IsValidBox(BoundBox *this)
{
  int v1; // eax
  Vector *i; // ecx

  v1 = 0;
  for ( i = &this->bmaxs; i[-1].x <= i->x; i = (Vector *)((char *)i + 4) )
  {
    if ( ++v1 >= 3 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100019D0
// Name: public: void BoundBox::GetBoundsSize(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BoundBox::GetBoundsSize(BoundBox *this, Vector *size)
{
  size->x = this->bmaxs.x - this->bmins.x;
  size->y = this->bmaxs.y - this->bmins.y;
  size->z = this->bmaxs.z - this->bmins.z;
}

//------------------------------------------------------------------------------
// Address: 0x10001A10
// Name: public: void BoundBox::SnapToGrid(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BoundBox::SnapToGrid(BoundBox *this, int iGridSize)
{
  Vector *p_bmins; // esi
  float v3; // xmm1_4
  int v4; // edi
  double v5; // st7
  float v6; // xmm0_4
  float v7; // xmm1_4
  Vector size; // [esp+Ch] [ebp-10h]
  float v9; // [esp+18h] [ebp-4h]
  int iGridSizea; // [esp+24h] [ebp+8h]

  size.x = this->bmaxs.x - this->bmins.x;
  p_bmins = &this->bmins;
  size.y = this->bmaxs.y - this->bmins.y;
  size.z = this->bmaxs.z - this->bmins.z;
  v3 = 1.0 / (float)iGridSize;
  v4 = 0;
  v9 = (float)iGridSize;
  for ( *(float *)&iGridSizea = v3; ; v3 = *(float *)&iGridSizea )
  {
    v5 = rint(f: v3 * p_bmins->x);
    v6 = (float)(int)(v5 * v9);
    v7 = *(&size.x + v4) + v6;
    p_bmins->x = v6;
    p_bmins[1].x = v7;
    ++v4;
    p_bmins = (Vector *)((char *)p_bmins + 4);
    if ( v4 >= 3 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001AC0
// Name: public: void BoundBox::Rotate90(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BoundBox::Rotate90(BoundBox *this, int axis)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  int v4; // eax
  int v5; // edx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  Vector center; // [esp+0h] [ebp-Ch]

  v2 = this->bmaxs.y + this->bmins.y;
  v3 = this->bmaxs.z + this->bmins.z;
  v4 = 0;
  v5 = 1;
  center.x = (float)(this->bmaxs.x + this->bmins.x) * 0.5;
  center.y = v2 * 0.5;
  center.z = v3 * 0.5;
  if ( axis == 0 )
  {
    v4 = 1;
    goto LABEL_5;
  }
  if ( axis == 1 )
  {
    v4 = 0;
LABEL_5:
    v5 = 2;
  }
  v6 = *(&center.x + v5);
  v7 = *(&center.x + v4);
  v8 = *(&this->bmins.x + v4);
  v9 = *(&this->bmaxs.x + v4);
  *(&this->bmins.x + v4) = (float)(*(&this->bmins.x + v5) - v6) + v7;
  *(&this->bmaxs.x + v4) = (float)(*(&this->bmaxs.x + v5) - v6) + v7;
  *(&this->bmins.x + v5) = (float)(v8 - v7) + v6;
  *(&this->bmaxs.x + v5) = (float)(v9 - v7) + v6;
}

//------------------------------------------------------------------------------
// Address: 0x10001B90
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
