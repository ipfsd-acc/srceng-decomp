// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_controller/ivp_constraint.cxx
// Functions: 17
// ============================================================

#include "ivp\ivp_controller\ivp_constraint.h"

//------------------------------------------------------------------------------
// Address: 0x100AA2E0
// Name: public: virtual void IVP_Constraint::change_fixing_point_Ros(class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::change_fixing_point_Ros(IVP_Constraint *this, const IVP_U_Point *__formal)
{
  printf(format: "You are changing the fixing point of a constraint which does not exist.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100AA2F0
// Name: public: virtual void IVP_Constraint::change_translation_axes_Ros(class IVP_U_Matrix3 const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::change_translation_axes_Ros(IVP_Constraint *this, const IVP_U_Matrix3 *m_Ros_f_Rfs)
{
  printf(format: "You are changing the translation axes of a constraint which does not exist.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100AA300
// Name: public: virtual void IVP_Constraint::fix_translation_axis(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::fix_translation_axis(IVP_Constraint *this, IVP_COORDINATE_INDEX which)
{
  printf(format: "You are fixing a translation axis of a constraint which does not exist.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100AA310
// Name: public: virtual void IVP_Constraint::free_translation_axis(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::free_translation_axis(IVP_Constraint *this, IVP_COORDINATE_INDEX which)
{
  printf(format: "You are freeing a translation axis of a constraint which does not exist.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100AA320
// Name: public: virtual void IVP_Constraint::limit_translation_axis(enum IVP_COORDINATE_INDEX,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::limit_translation_axis(
        IVP_Constraint *this,
        IVP_COORDINATE_INDEX which,
        float border_left,
        float border_right)
{
  printf(format: "You are limiting a translation axis of a constraint which does not exist.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100AA330
// Name: public: virtual void IVP_Constraint::change_max_translation_impulse(enum IVP_CONSTRAINT_FORCE_EXCEED,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::change_max_translation_impulse(
        IVP_Constraint *this,
        IVP_CONSTRAINT_FORCE_EXCEED forcetype,
        float force)
{
  printf(format: "You are changing a maxforce define of a constraint which does not exist.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100AA340
// Name: public: virtual void IVP_Constraint::change_rotation_axes_Ros(class IVP_U_Matrix3 const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::change_rotation_axes_Ros(IVP_Constraint *this, const IVP_U_Matrix3 *rot_axes)
{
  printf(format: "You are changing the rotation axes of a constraint which does not exist.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100AA350
// Name: public: virtual void IVP_Constraint::fix_rotation_axis(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::fix_rotation_axis(IVP_Constraint *this, IVP_COORDINATE_INDEX which)
{
  printf(format: "You are fixing a rotation axis of a constraint which does not exist.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100AA360
// Name: public: virtual void IVP_Constraint::free_rotation_axis(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::free_rotation_axis(IVP_Constraint *this, IVP_COORDINATE_INDEX which)
{
  printf(format: "You are freeing a rotation axis of a constraint which does not exist.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100AA370
// Name: public: virtual void IVP_Constraint::limit_rotation_axis(enum IVP_COORDINATE_INDEX,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::limit_rotation_axis(
        IVP_Constraint *this,
        IVP_COORDINATE_INDEX which,
        float border_left,
        float border_right)
{
  printf(format: "You are limiting a rotation axis of a constraint which does not exist.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100AA380
// Name: public: virtual void IVP_Constraint::change_max_rotation_impulse(enum IVP_CONSTRAINT_FORCE_EXCEED,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::change_max_rotation_impulse(
        IVP_Constraint *this,
        IVP_CONSTRAINT_FORCE_EXCEED forcetype,
        float force)
{
  printf(format: "You are changing a maxtorque define of a constraint which does not exist.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100AA390
// Name: public: virtual void IVP_Constraint::change_Ros_to_relaxe_constraint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::change_Ros_to_relaxe_constraint(IVP_Constraint *this)
{
  printf(format: "You are repositioning a constraint which does not exist.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100AA3A0
// Name: protected: class IVP_Environment __near * IVP_Constraint::get_environment(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Environment *__thiscall IVP_Constraint::get_environment(IVP_Constraint *this)
{
  return *((IVP_Environment **)*this->cores_of_constraint_system.elems + 3);
}

//------------------------------------------------------------------------------
// Address: 0x100AA3B0
// Name: public: void IVP_Constraint::activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::activate(IVP_Constraint *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 1);
  if ( (v1 & 3) == 0 )
  {
    *((_DWORD *)this + 1) = v1 & 0xFFFFFFFC | 1;
    IVP_Controller_Manager::announce_controller_to_environment(
      this: *(IVP_Controller_Manager **)(*((_DWORD *)*this->cores_of_constraint_system.elems + 3) + 52),
      cntrl: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA3E0
// Name: public: void IVP_Constraint::deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::deactivate(IVP_Constraint *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 1);
  if ( (v1 & 3) != 0 )
  {
    *((_DWORD *)this + 1) = v1 & 0xFFFFFFFC;
    IVP_Controller_Manager::remove_controller_from_environment(cntrl: this, silently: IVP_FALSE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA400
// Name: public: virtual IVP_Constraint::~IVP_Constraint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint::~IVP_Constraint(IVP_Constraint *this)
{
  bool v2; // zf
  IVP_Constraint *elems; // eax

  v2 = (*((_BYTE *)this + 4) & 3) == 0;
  this->__vftable = (IVP_Constraint_vtbl *)&IVP_Constraint::`vftable';
  if ( !v2 )
    IVP_Controller_Manager::remove_controller_from_environment(cntrl: this, silently: IVP_TRUE);
  elems = (IVP_Constraint *)this->cores_of_constraint_system.elems;
  if ( elems != (IVP_Constraint *)this->cores_of_constraint_system.elem_buffer )
  {
    if ( elems != nullptr )
      free(data: this->cores_of_constraint_system.elems);
    this->cores_of_constraint_system.elems = nullptr;
    this->cores_of_constraint_system.memsize = 0;
  }
  this->cores_of_constraint_system.n_elems = 0;
  this->__vftable = (IVP_Constraint_vtbl *)&IVP_Controller_Dependent::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100AA450
// Name: public: IVP_Constraint::IVP_Constraint(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Constraint *__thiscall IVP_Constraint::IVP_Constraint(IVP_Constraint *this)
{
  this->__vftable = (IVP_Constraint_vtbl *)&IVP_Constraint::`vftable';
  this->cores_of_constraint_system.elems = (void **)this->cores_of_constraint_system.elem_buffer;
  *(_DWORD *)&this->cores_of_constraint_system.memsize = 2;
  *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFFFC | 1;
  return this;
}
