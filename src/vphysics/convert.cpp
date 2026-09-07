// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/convert.cpp
// Functions: 11
// ============================================================

#include "vphysics\convert.h"

//------------------------------------------------------------------------------
// Address: 0x100011F0
// Name: public: class IVP_Cache_Object __near * IVP_Real_Object::get_cache_object_no_lock(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Cache_Object *__thiscall IVP_Real_Object::get_cache_object_no_lock(IVP_Real_Object *this)
{
  IVP_Cache_Object *cache_object; // ecx

  if ( this->cache_object == nullptr )
    this->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                           this: this->environment->cache_object_manager,
                           object: this);
  if ( *(_BYTE *)&this->flags >= 8 )
    return this->cache_object;
  cache_object = this->cache_object;
  if ( this->environment->current_time_code > cache_object->valid_until_time_code )
  {
    IVP_Cache_Object::update_cache_object(this: cache_object);
    return this->cache_object;
  }
  return this->cache_object;
}

//------------------------------------------------------------------------------
// Address: 0x10001230
// Name: void ConvertMatrixToIVP(struct matrix3x4_t const __near &,class IVP_U_Matrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertMatrixToIVP(const matrix3x4_t *matrix, IVP_U_Matrix *out)
{
  float v2; // xmm2_4
  float v3; // xmm3_4
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  float left; // [esp+0h] [ebp-Ch]
  float left_4; // [esp+4h] [ebp-8h]

  v2 = matrix->m_flMatVal[2][1];
  v3 = matrix->m_flMatVal[0][2];
  v4 = matrix->m_flMatVal[1][2];
  v5 = matrix->m_flMatVal[2][2];
  v6 = matrix->m_flMatVal[0][0];
  v7 = matrix->m_flMatVal[1][0];
  left = matrix->m_flMatVal[0][1];
  left_4 = matrix->m_flMatVal[1][1];
  out->rows[1].k[0] = -matrix->m_flMatVal[2][0];
  out->rows[0].k[2] = left;
  out->rows[2].k[2] = left_4;
  out->rows[0].k[0] = v6;
  out->rows[2].k[0] = v7;
  out->rows[0].k[1] = -v3;
  out->rows[2].k[1] = -v4;
  out->rows[1].k[2] = -v2;
  out->rows[1].k[1] = -(float)-v5;
  out->vv.k[0] = matrix->m_flMatVal[0][3] * g_PhysicsUnits.unitScaleMeters;
  out->vv.k[1] = -(float)(matrix->m_flMatVal[2][3] * g_PhysicsUnits.unitScaleMeters);
  out->vv.k[2] = matrix->m_flMatVal[1][3] * g_PhysicsUnits.unitScaleMeters;
}

//------------------------------------------------------------------------------
// Address: 0x10001300
// Name: void ConvertRotationToIVP(class QAngle const __near &,class IVP_U_Matrix3 __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertRotationToIVP(const QAngle *angles, IVP_U_Matrix3 *out)
{
  float v2; // xmm3_4
  float v3; // xmm4_4
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float y; // xmm0_4
  Vector forward; // [esp+0h] [ebp-24h] BYREF
  Vector up; // [esp+Ch] [ebp-18h] BYREF
  Vector right; // [esp+18h] [ebp-Ch] BYREF

  AngleVectors(angles, &forward, &right, &up);
  v2 = -right.x;
  v3 = -right.y;
  v4 = -up.x;
  v5 = -up.y;
  v6 = -forward.z;
  v7 = -(float)-right.z;
  v8 = -(float)-up.z;
  out->rows[0].k[0] = forward.x;
  y = forward.y;
  out->rows[1].k[0] = v6;
  out->rows[2].k[0] = y;
  out->rows[0].k[2] = v2;
  out->rows[1].k[2] = v7;
  out->rows[2].k[2] = v3;
  out->rows[0].k[1] = v4;
  out->rows[1].k[1] = v8;
  out->rows[2].k[1] = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100013B0
// Name: void ConvertMatrixToHL(class IVP_U_Matrix const __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertMatrixToHL(const IVP_U_Matrix *in, matrix3x4_t *output)
{
  output->m_flMatVal[0][0] = in->rows[0].k[0];
  output->m_flMatVal[0][2] = -in->rows[0].k[1];
  output->m_flMatVal[0][1] = in->rows[0].k[2];
  output->m_flMatVal[1][0] = in->rows[2].k[0];
  output->m_flMatVal[1][2] = -in->rows[2].k[1];
  output->m_flMatVal[1][1] = in->rows[2].k[2];
  output->m_flMatVal[2][0] = -in->rows[1].k[0];
  output->m_flMatVal[2][2] = in->rows[1].k[1];
  output->m_flMatVal[2][1] = -in->rows[1].k[2];
  output->m_flMatVal[0][3] = in->vv.k[0] * g_PhysicsUnits.unitScaleMetersInv;
  output->m_flMatVal[1][3] = in->vv.k[2] * g_PhysicsUnits.unitScaleMetersInv;
  output->m_flMatVal[2][3] = -(float)(in->vv.k[1] * g_PhysicsUnits.unitScaleMetersInv);
}

//------------------------------------------------------------------------------
// Address: 0x10001450
// Name: void ConvertRotationToHL(class IVP_U_Matrix3 const __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall ConvertRotationToHL(int a1@<esi>, const IVP_U_Matrix3 *in, QAngle *angles)
{
  float v3; // xmm1_4
  float v4; // xmm5_4
  long double v5; // [esp-4h] [ebp-28h]
  long double v6; // [esp-4h] [ebp-28h]
  long double v7; // [esp-4h] [ebp-28h]
  long double v8; // [esp-4h] [ebp-28h]
  long double up_4; // [esp+4h] [ebp-20h]
  long double up_4a; // [esp+4h] [ebp-20h]
  long double up_4b; // [esp+4h] [ebp-20h]
  long double up_4c; // [esp+4h] [ebp-20h]
  float right_8; // [esp+14h] [ebp-10h]
  float forward_8; // [esp+20h] [ebp-4h]

  v3 = in->rows[2].k[0];
  v4 = in->rows[0].k[2];
  forward_8 = -in->rows[1].k[0];
  right_8 = -in->rows[1].k[2];
  *((float *)&up_4 + 1) = -in->rows[1].k[1];
  LODWORD(v5) = a1;
  if ( fsqrt((float)(in->rows[0].k[0] * in->rows[0].k[0]) + (float)(v3 * v3)) <= 0.001 )
  {
    __libm_sse2_atan2(y: v5, x: up_4);
    angles->y = v4 * 57.29578;
    __libm_sse2_atan2(y: v8, x: up_4c);
    angles->x = COERCE_FLOAT(LODWORD(forward_8) ^ _mask__NegFloat_) * 57.29578;
    angles->z = 180.0;
  }
  else
  {
    __libm_sse2_atan2(y: v5, x: up_4);
    angles->y = v3 * 57.29578;
    __libm_sse2_atan2(y: v6, x: up_4a);
    angles->x = COERCE_FLOAT(LODWORD(forward_8) ^ _mask__NegFloat_) * 57.29578;
    __libm_sse2_atan2(y: v7, x: up_4b);
    angles->z = (float)(COERCE_FLOAT(LODWORD(right_8) ^ _mask__NegFloat_) * 57.29578) + 180.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100015B0
// Name: void ConvertRotationToHL(class IVP_U_Quat const __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall ConvertRotationToHL(int a1@<ebp>, int a2@<esi>, IVP_U_Quat *in, QAngle *angles)
{
  float v4; // xmm0_4
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm0_8
  double v8; // xmm0_8
  long double v9; // [esp-1Ch] [ebp-7Ch]
  long double v10; // [esp-1Ch] [ebp-7Ch]
  long double v11; // [esp-1Ch] [ebp-7Ch]
  long double v12; // [esp-1Ch] [ebp-7Ch]
  long double v13; // [esp-14h] [ebp-74h]
  long double v14; // [esp-14h] [ebp-74h]
  long double v15; // [esp-14h] [ebp-74h]
  long double v16; // [esp-14h] [ebp-74h]
  float v17[3]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Matrix3 tmp; // [esp+0h] [ebp-60h]
  float v19; // [esp+34h] [ebp-2Ch]
  float v20; // [esp+40h] [ebp-20h]
  float v21; // [esp+4Ch] [ebp-14h]
  float v22; // [esp+50h] [ebp-10h]
  int v23; // [esp+54h] [ebp-Ch]
  void *v24; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v23 = a1;
  v24 = retaddr;
  LODWORD(v9) = a2;
  IVP_U_Quat::set_matrix(this: in, mat: (IVP_U_Matrix3 *)v17);
  v21 = -tmp.rows[0].k[1];
  v20 = -tmp.rows[0].hesse_val;
  v19 = -tmp.rows[0].k[2];
  v4 = tmp.rows[1].k[1];
  v22 = fsqrt((float)(v4 * v4) + (float)(v17[0] * v17[0]));
  if ( v22 <= 0.001 )
  {
    v7 = v17[2];
    __libm_sse2_atan2(y: v9, x: v13);
    *(float *)&v7 = v7;
    angles->y = *(float *)&v7 * 57.29578;
    v8 = COERCE_FLOAT(LODWORD(v21) ^ _mask__NegFloat_);
    __libm_sse2_atan2(y: v12, x: v16);
    *(float *)&v8 = v8;
    angles->x = *(float *)&v8 * 57.29578;
    angles->z = 180.0;
  }
  else
  {
    __libm_sse2_atan2(y: v9, x: v13);
    angles->y = v4 * 57.29578;
    v5 = COERCE_FLOAT(LODWORD(v21) ^ _mask__NegFloat_);
    __libm_sse2_atan2(y: v10, x: v14);
    *(float *)&v5 = v5;
    angles->x = *(float *)&v5 * 57.29578;
    v6 = COERCE_FLOAT(LODWORD(v20) ^ _mask__NegFloat_);
    __libm_sse2_atan2(y: v11, x: v15);
    *(float *)&v6 = v6;
    angles->z = (float)(*(float *)&v6 * 57.29578) + 180.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001740
// Name: void TransformIVPToLocal(class IVP_U_Point const __near &,class IVP_U_Point __near &,class IVP_Real_Object __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TransformIVPToLocal(
        const IVP_U_Point *pointIn,
        IVP_U_Point *pointOut,
        IVP_Real_Object *pObject,
        bool translate)
{
  IVP_Cache_Object *cache_object; // ecx
  IVP_Cache_Object *v5; // ecx

  if ( pObject->cache_object == nullptr )
    pObject->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                              this: pObject->environment->cache_object_manager,
                              object: pObject);
  if ( *(_BYTE *)&pObject->flags < 8 )
  {
    cache_object = pObject->cache_object;
    if ( pObject->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  v5 = pObject->cache_object;
  if ( translate )
    IVP_Cache_Object::transform_position_to_object_coords(this: v5, P_world: pointIn, P_object_out: pointOut);
  else
    IVP_Cache_Object::transform_vector_to_object_coords(this: v5, P_world: pointIn, P_object_out: pointOut);
}

//------------------------------------------------------------------------------
// Address: 0x100017A0
// Name: void TransformLocalToIVP(class IVP_U_Float_Point const __near &,class IVP_U_Point __near &,class IVP_Real_Object __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall TransformLocalToIVP(
        float a1@<ebp>,
        const IVP_U_Float_Point *pointIn,
        IVP_U_Point *pointOut,
        IVP_Real_Object *pObject,
        bool translate)
{
  IVP_Cache_Object *cache_object; // ecx
  IVP_Cache_Object *v6; // ecx
  _BYTE v7[12]; // [esp-Ch] [ebp-1Ch] BYREF
  IVP_U_Point doublePointIn; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  doublePointIn.k[1] = a1;
  doublePointIn.k[2] = retaddr;
  if ( pObject->cache_object == nullptr )
    pObject->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                              this: pObject->environment->cache_object_manager,
                              object: pObject);
  if ( *(_BYTE *)&pObject->flags < 8 )
  {
    cache_object = pObject->cache_object;
    if ( pObject->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  v6 = pObject->cache_object;
  if ( translate )
  {
    IVP_Cache_Object::transform_position_to_world_coords(this: v6, P_object: pointIn, P_world_out: pointOut);
  }
  else
  {
    qmemcpy(v7, pointIn, sizeof(v7));
    IVP_Cache_Object::transform_vector_to_world_coords(
      this: v6,
      P_object: (const IVP_U_Float_Point *)v7,
      P_world_out: pointOut);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001840
// Name: void TransformLocalToIVP(class IVP_U_Float_Point const __near &,class IVP_U_Float_Point __near &,class IVP_Real_Object __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall TransformLocalToIVP(
        float a1@<ebp>,
        const IVP_U_Float_Point *pointIn,
        IVP_U_Float_Point *pointOut,
        IVP_Real_Object *pObject,
        bool translate)
{
  _BYTE v5[12]; // [esp-Ch] [ebp-1Ch] BYREF
  IVP_U_Point tmpOut; // [esp+0h] [ebp-10h] BYREF
  float retaddr; // [esp+10h] [ebp+0h]

  tmpOut.k[1] = a1;
  tmpOut.k[2] = retaddr;
  TransformLocalToIVP(
    a1: COERCE_FLOAT((IVP_U_Point *)&tmpOut.k[1]),
    pointIn,
    pointOut: (IVP_U_Point *)v5,
    pObject,
    translate);
  qmemcpy(pointOut, v5, 12);
}

//------------------------------------------------------------------------------
// Address: 0x100018A0
// Name: int ConvertCoordinateAxisToIVP(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ConvertCoordinateAxisToIVP(int axisIndex)
{
  if ( axisIndex >= 4 )
    return 0;
  else
    return axisMap[axisIndex];
}

//------------------------------------------------------------------------------
// Address: 0x100018C0
// Name: void ConvertRotationToIVP(class QAngle const __near &,class IVP_U_Quat __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall ConvertRotationToIVP(int a1@<ebp>, const QAngle *angles, IVP_U_Quat *out)
{
  float v3[3]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Matrix3 tmp; // [esp+0h] [ebp-60h]
  Vector v5; // [esp+30h] [ebp-30h] BYREF
  Vector v6; // [esp+3Ch] [ebp-24h] BYREF
  Vector v7; // [esp+48h] [ebp-18h] BYREF
  int v8; // [esp+54h] [ebp-Ch]
  void *v9; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v8 = a1;
  v9 = retaddr;
  AngleVectors(angles, forward: &v5, right: &v7, up: &v6);
  v3[0] = v5.x;
  tmp.rows[0].k[1] = -v5.z;
  tmp.rows[1].k[1] = v5.y;
  v3[2] = -v7.x;
  tmp.rows[0].hesse_val = -(float)-v7.z;
  tmp.rows[1].hesse_val = -v7.y;
  v3[1] = -v6.x;
  tmp.rows[0].k[2] = -(float)-v6.z;
  tmp.rows[1].k[2] = -v6.y;
  IVP_U_Quat::set_quaternion(this: out, mat: (const IVP_U_Matrix3 *)v3);
}
