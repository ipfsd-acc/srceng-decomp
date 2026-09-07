// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_physics/ivp_templates.cxx
// Functions: 3
// ============================================================

#include "ivp\ivp_physics\ivp_templates.h"

//------------------------------------------------------------------------------
// Address: 0x1008B840
// Name: public: void IVP_Template_Object::set_name(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Template_Object::set_name(IVP_Template_Object *this, const char *s)
{
  if ( this->name != nullptr )
  {
    free(data: this->name);
    this->name = nullptr;
  }
  this->name = p_strdup(s);
}

//------------------------------------------------------------------------------
// Address: 0x1008B870
// Name: public: IVP_Template_Real_Object::IVP_Template_Real_Object(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Real_Object *__thiscall IVP_Template_Real_Object::IVP_Template_Real_Object(IVP_Template_Real_Object *this)
{
  this->name = nullptr;
  this->name = nullptr;
  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_Template_Real_Object));
  this->mass = 1.0;
  this->rot_inertia_is_factor = IVP_TRUE;
  this->rot_inertia.k[0] = 1.0;
  this->rot_inertia.k[1] = 1.0;
  this->rot_inertia.k[2] = 1.0;
  this->auto_check_rot_inertia = 0.029999999;
  this->speed_damp_factor = 0.0099999998;
  this->rot_speed_damp_factor.k[0] = 0.0099999998;
  this->rot_speed_damp_factor.k[1] = 0.0099999998;
  this->rot_speed_damp_factor.k[2] = 0.0099999998;
  this->pinned = IVP_FALSE;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008B8F0
// Name: public: IVP_Template_Real_Object::~IVP_Template_Real_Object(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Template_Real_Object::~IVP_Template_Real_Object(IVP_Template_Real_Object *this)
{
  if ( this->name != nullptr )
  {
    free(data: this->name);
    this->name = nullptr;
  }
}
