// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_controller/ivp_template_constraint.cxx
// Functions: 6
// ============================================================

#include "ivp\ivp_controller\ivp_template_constraint.h"

//------------------------------------------------------------------------------
// Address: 0x100938C0
// Name: public: void IVP_Template_Constraint::set_attached_object(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Template_Constraint::set_attached_object(IVP_Template_Constraint *this, IVP_Real_Object *objA)
{
  this->objectA = objA;
}

//------------------------------------------------------------------------------
// Address: 0x100938D0
// Name: public: void IVP_Template_Constraint::free_translation_axis(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Template_Constraint::free_translation_axis(
        IVP_Template_Constraint *this,
        IVP_COORDINATE_INDEX which)
{
  this->axis_type[which] = IVP_CONSTRAINT_AXIS_FREE;
}

//------------------------------------------------------------------------------
// Address: 0x100938F0
// Name: public: void IVP_Template_Constraint::fix_rotation_axis(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Template_Constraint::fix_rotation_axis(IVP_Template_Constraint *this, IVP_COORDINATE_INDEX which)
{
  this->axis_type[which + 3] = IVP_CONSTRAINT_AXIS_FIXED;
}

//------------------------------------------------------------------------------
// Address: 0x10093910
// Name: public: void IVP_Template_Constraint::free_rotation_axis(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Template_Constraint::free_rotation_axis(IVP_Template_Constraint *this, IVP_COORDINATE_INDEX which)
{
  this->axis_type[which + 3] = IVP_CONSTRAINT_AXIS_FREE;
}

//------------------------------------------------------------------------------
// Address: 0x10093930
// Name: public: class IVP_Constraint __near * IVP_Environment::create_constraint(class IVP_Template_Constraint const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Constraint_Local *__thiscall IVP_Environment::create_constraint(
        IVP_Environment *this,
        const IVP_Template_Constraint *tmpl)
{
  IVP_Constraint_Local *v2; // eax

  if ( (tmpl->objectR != nullptr || tmpl->objectA != nullptr)
    && (v2 = (IVP_Constraint_Local *)p_malloc(size: 0x130u)) != nullptr )
  {
    return IVP_Constraint_Local::IVP_Constraint_Local(this: v2, tmpl);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093970
// Name: public: IVP_Template_Constraint::IVP_Template_Constraint(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Constraint *__thiscall IVP_Template_Constraint::IVP_Template_Constraint(IVP_Template_Constraint *this)
{
  this->force_factor = 1.0;
  this->damp_factor = 1.0;
  this->objectR = nullptr;
  this->objectA = nullptr;
  this->m_Ros_f_Rfs = nullptr;
  this->m_Ros_f_Rrs = nullptr;
  this->m_Aos_f_Afs = nullptr;
  IVP_U_Matrix::init(this: &this->mm_Ros_f_Rfs);
  IVP_U_Matrix3::init3(this: &this->mm_Ros_f_Rrs);
  IVP_U_Matrix::init(this: &this->mm_Aos_f_Afs);
  this->axis_type[5] = IVP_CONSTRAINT_AXIS_FREE;
  this->axis_type[4] = IVP_CONSTRAINT_AXIS_FREE;
  this->axis_type[3] = IVP_CONSTRAINT_AXIS_FREE;
  this->borderleft_Rfs[5] = 0.0;
  this->borderleft_Rfs[4] = 0.0;
  this->borderleft_Rfs[3] = 0.0;
  this->borderleft_Rfs[2] = 0.0;
  this->borderleft_Rfs[1] = 0.0;
  this->borderleft_Rfs[0] = 0.0;
  this->borderright_Rfs[5] = 0.0;
  this->borderright_Rfs[4] = 0.0;
  this->borderright_Rfs[3] = 0.0;
  this->borderright_Rfs[2] = 0.0;
  this->borderright_Rfs[1] = 0.0;
  this->borderright_Rfs[0] = 0.0;
  this->maximpulse[5] = 0.0;
  this->maximpulse[4] = 0.0;
  this->maximpulse[3] = 0.0;
  this->maximpulse[2] = 0.0;
  this->maximpulse[1] = 0.0;
  this->maximpulse[0] = 0.0;
  this->maximpulse_type[5] = IVP_CFE_NONE;
  this->maximpulse_type[4] = IVP_CFE_NONE;
  this->maximpulse_type[3] = IVP_CFE_NONE;
  this->maximpulse_type[2] = IVP_CFE_NONE;
  this->maximpulse_type[1] = IVP_CFE_NONE;
  this->maximpulse_type[0] = IVP_CFE_NONE;
  this->axis_type[2] = IVP_CONSTRAINT_AXIS_FIXED;
  this->axis_type[1] = IVP_CONSTRAINT_AXIS_FIXED;
  this->axis_type[0] = IVP_CONSTRAINT_AXIS_FIXED;
  this->limited_axis_stiffness = 0.30000001;
  return this;
}
