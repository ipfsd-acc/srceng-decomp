// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_physics/ivp_material.cxx
// Functions: 11
// ============================================================

#include "ivp\ivp_physics\ivp_material.h"

//------------------------------------------------------------------------------
// Address: 0x1008B650
// Name: public: IVP_Material_Manager::IVP_Material_Manager(enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
IVP_Material_Manager *__thiscall IVP_Material_Manager::IVP_Material_Manager(
        IVP_Material_Manager *this,
        IVP_BOOL delete_on_env_delete_in)
{
  this->__vftable = (IVP_Material_Manager_vtbl *)&IVP_Material_Manager::`vftable';
  this->delete_on_env_delete = delete_on_env_delete_in;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008B670
// Name: public: virtual IVP_Material::~IVP_Material(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Material::~IVP_Material(IVP_Material *this)
{
  this->__vftable = (IVP_Material_vtbl *)&IVP_Material::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1008B680
// Name: public: virtual float IVP_Material_Manager::get_friction_factor(struct IVP_Contact_Situation __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Material_Manager::get_friction_factor(IVP_Material_Manager *this, IVP_Contact_Situation *sit)
{
  IVP_Material *v2; // esi
  float sita; // [esp+Ch] [ebp+8h]

  v2 = sit->materials[1];
  sita = sit->materials[0]->get_friction_factor(this: sit->materials[0]);
  return ((double (__thiscall *)(IVP_Material *))v2->get_friction_factor)(a1: v2) * sita;
}

//------------------------------------------------------------------------------
// Address: 0x1008B6B0
// Name: public: virtual float IVP_Material_Manager::get_elasticity(struct IVP_Contact_Situation __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Material_Manager::get_elasticity(IVP_Material_Manager *this, IVP_Contact_Situation *sit)
{
  IVP_Material *v2; // esi
  float sita; // [esp+Ch] [ebp+8h]

  v2 = sit->materials[1];
  sita = sit->materials[0]->get_elasticity(this: sit->materials[0]);
  return ((double (__thiscall *)(IVP_Material *))v2->get_elasticity)(a1: v2) * sita;
}

//------------------------------------------------------------------------------
// Address: 0x1008B6E0
// Name: public: virtual float IVP_Material_Manager::get_damping(struct IVP_Contact_Situation __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Material_Manager::get_damping(IVP_Material_Manager *this, IVP_Contact_Situation *sit)
{
  IVP_Material *v2; // esi
  float sita; // [esp+Ch] [ebp+8h]

  v2 = sit->materials[1];
  sita = sit->materials[0]->get_damping(this: sit->materials[0]);
  return ((double (__thiscall *)(IVP_Material *))v2->get_damping)(a1: v2) + sita;
}

//------------------------------------------------------------------------------
// Address: 0x1008B710
// Name: public: virtual float IVP_Material_Manager::get_adhesion(struct IVP_Contact_Situation __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Material_Manager::get_adhesion(IVP_Material_Manager *this, IVP_Contact_Situation *sit)
{
  IVP_Material *v2; // esi
  float sita; // [esp+Ch] [ebp+8h]

  v2 = sit->materials[1];
  sita = sit->materials[0]->get_adhesion(this: sit->materials[0]);
  return ((double (__thiscall *)(IVP_Material *))v2->get_adhesion)(a1: v2) + sita;
}

//------------------------------------------------------------------------------
// Address: 0x1008B750
// Name: public: virtual float IVP_Material_Simple::get_friction_factor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Material_Simple::get_friction_factor(IVP_Material_Simple *this)
{
  return this->friction_value;
}

//------------------------------------------------------------------------------
// Address: 0x1008B770
// Name: public: virtual float IVP_Material_Simple::get_damping(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Material_Simple::get_damping(IVP_Material_Simple *this)
{
  return this->damping;
}

//------------------------------------------------------------------------------
// Address: 0x1008B780
// Name: public: virtual float IVP_Material_Simple::get_adhesion(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Material_Simple::get_adhesion(IVP_Material_Simple *this)
{
  return this->adhesion;
}

//------------------------------------------------------------------------------
// Address: 0x1008B790
// Name: public: virtual char const __near * IVP_Material_Simple::get_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IVP_Material_Simple::get_name(IVP_Material_Simple *this)
{
  return "Simple material";
}

//------------------------------------------------------------------------------
// Address: 0x1008B7A0
// Name: public: virtual class IVP_Material __near * IVP_Material_Manager::get_material_by_index(class IVP_Real_Object __near *,class IVP_U_Point const __near *,int)
// Source: json
//------------------------------------------------------------------------------
IVP_Material_Simple *__thiscall IVP_Material_Manager::get_material_by_index(
        IVP_Material_Manager *this,
        IVP_Real_Object *__formal,
        IVP_Real_Object *__formala,
        int a4)
{
  IVP_Material_Simple *result; // eax

  if ( (_S1_7 & 1) != 0 )
    return simple;
  _S1_7 |= 1u;
  result = (IVP_Material_Simple *)p_malloc(size: 0x20u);
  if ( result != nullptr )
  {
    result->friction_value = 0.5;
    result->elasticity = 0.5;
    result->second_friction_x_enabled = IVP_FALSE;
    result->__vftable = (IVP_Material_Simple_vtbl *)&IVP_Material_Simple::`vftable';
    result->damping = 0.0;
    result->adhesion = 0.0;
    simple = result;
  }
  else
  {
    simple = nullptr;
    return nullptr;
  }
  return result;
}
