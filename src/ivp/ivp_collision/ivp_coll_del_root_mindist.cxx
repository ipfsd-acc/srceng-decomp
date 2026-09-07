// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_coll_del_root_mindist.cxx
// Functions: 5
// ============================================================

#include "ivp\ivp_collision\ivp_coll_del_root_mindist.h"

//------------------------------------------------------------------------------
// Address: 0x1009A680
// Name: public: virtual void IVP_Collision_Delegator_Root_Mindist::environment_is_going_to_be_deleted_event(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Collision_Delegator_Root_Mindist::environment_is_going_to_be_deleted_event(
        IVP_Collision_Delegator_Root_Mindist *this,
        IVP_Environment *__formal)
{
  if ( this != nullptr )
    ((void (__thiscall *)(IVP_Collision_Delegator_Root_Mindist *, int))this->dtr_IVP_Collision_Delegator)(
      a1: this,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1009A690
// Name: public: virtual void IVP_Collision_Delegator_Root_Mindist::collision_is_going_to_be_deleted_event(class IVP_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Collision_Delegator_Root_Mindist::collision_is_going_to_be_deleted_event(
        IVP_Collision_Delegator_Root_Mindist *this,
        IVP_Collision *t)
{
  IVP_OV_Element *ov_element; // edi
  IVP_Real_Object *objs[2]; // [esp+8h] [ebp-8h] BYREF

  t->get_objects(this: t, a2: objs);
  ov_element = objs[1]->ov_element;
  IVP_OV_Element::remove_oo_collision(this: objs[0]->ov_element, connector: t);
  IVP_OV_Element::remove_oo_collision(this: ov_element, connector: t);
}

//------------------------------------------------------------------------------
// Address: 0x1009A6D0
// Name: public: virtual class IVP_Collision __near * IVP_Collision_Delegator_Root_Mindist::delegate_collisions_for_object(class IVP_Real_Object __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_OO_Watcher *__thiscall IVP_Collision_Delegator_Root_Mindist::delegate_collisions_for_object(
        IVP_Collision_Delegator_Root_Mindist *this,
        IVP_Real_Object *obj0,
        IVP_Real_Object *obj1)
{
  IVP_OO_Watcher *v4; // eax
  IVP_OO_Watcher *v5; // esi
  IVP_OV_Element *ov_element; // edi

  v4 = (IVP_OO_Watcher *)p_malloc(size: 0x40u);
  if ( v4 != nullptr )
    v5 = IVP_OO_Watcher::IVP_OO_Watcher(this: v4, del: this, obj0, obj1);
  else
    v5 = nullptr;
  ov_element = obj1->ov_element;
  IVP_OV_Element::add_oo_collision(this: obj0->ov_element, connector: v5);
  IVP_OV_Element::add_oo_collision(this: ov_element, connector: v5);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1009A720
// Name: public: virtual void IVP_Collision_Delegator_Root_Mindist::object_is_removed_from_collision_detection(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Collision_Delegator_Root_Mindist::object_is_removed_from_collision_detection(
        IVP_Collision_Delegator_Root_Mindist *this,
        IVP_Real_Object *o)
{
  IVP_OV_Element *ov_element; // edi
  int v3; // esi
  void *v5; // ecx

  ov_element = o->ov_element;
  v3 = ov_element->collision_fvector.n_elems - 1;
  if ( ov_element->collision_fvector.n_elems != 0 )
  {
    do
    {
      v5 = ov_element->collision_fvector.elems[v3];
      (*(void (__thiscall **)(void *, IVP_Collision_Delegator_Root_Mindist *))(*(_DWORD *)v5 + 12))(a1: v5, a2: this);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A750
// Name: public: IVP_Collision_Delegator_Root_Mindist::IVP_Collision_Delegator_Root_Mindist(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Collision_Delegator_Root_Mindist *__thiscall IVP_Collision_Delegator_Root_Mindist::IVP_Collision_Delegator_Root_Mindist(
        IVP_Collision_Delegator_Root_Mindist *this)
{
  this->__vftable = (IVP_Collision_Delegator_Root_Mindist_vtbl *)&IVP_Collision_Delegator_Root_Mindist::`vftable';
  return this;
}
