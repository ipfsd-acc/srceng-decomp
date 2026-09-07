// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_oo_watcher.cxx
// Functions: 9
// ============================================================

#include "ivp\ivp_collision\ivp_oo_watcher.h"

//------------------------------------------------------------------------------
// Address: 0x100A9F00
// Name: public: void IVP_OO_Watcher::hull_limit_exceeded_event(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OO_Watcher::hull_limit_exceeded_event(IVP_OO_Watcher *this)
{
  IVP_OO_Watcher *v1; // ebx
  IVP_Real_Object *object; // eax
  IVP_Real_Object *v3; // esi
  IVP_Environment *environment; // edi
  IVP_Range_Manager *range_manager; // ecx
  void (__thiscall *get_coll_range_intra_objects)(IVP_Range_Manager *, const IVP_Real_Object *, const IVP_Real_Object *, float *, float *); // edx
  IVP_Synapse_OO *synapses; // edi
  unsigned int v8; // eax
  IVP_Real_Object *v9; // esi
  float v10; // xmm0_4
  IVP_Time t_now; // [esp+38h] [ebp-24h]
  float v12; // [esp+4Ch] [ebp-10h]
  float dist1; // [esp+50h] [ebp-Ch] BYREF
  float dist0; // [esp+54h] [ebp-8h] BYREF
  IVP_Real_Object *obj1; // [esp+58h] [ebp-4h]
  int savedregs; // [esp+5Ch] [ebp+0h] BYREF

  v1 = this;
  object = this->synapses[1].object;
  v3 = this->synapses[0].object;
  environment = v3->environment;
  ++environment->statistic_manager.range_intra_exceeded;
  range_manager = environment->range_manager;
  get_coll_range_intra_objects = range_manager->get_coll_range_intra_objects;
  obj1 = object;
  get_coll_range_intra_objects(this: range_manager, a2: v3, a3: object, a4: &dist0, a5: &dist1);
  IVP_Mindist_Manager::create_exact_mindists(
    a1: (int)&savedregs,
    pop0: v3,
    pop1: obj1,
    scan_radius: dist0 + dist1,
    mindists: &v1->mindists,
    single_ledge0: nullptr,
    single_ledge1: nullptr,
    root_ledge0: nullptr,
    root_ledge1: nullptr,
    oo_watcher: &v1->IVP_Collision_Delegator);
  *(IVP_Time *)&t_now.seconds = environment->current_time;
  synapses = v1->synapses;
  v12 = dist0;
  IVP_U_Min_List::remove_minlist_elem(this: &v3->hull_manager.sorted_synapses, index: v1->synapses[0].minlist_index);
  v8 = IVP_U_Min_List::add(
         this: &v3->hull_manager.sorted_synapses,
         elem: (int)v1->synapses,
         value: (float)((float)((float)(t_now.seconds - v3->hull_manager.last_vpsi_time.seconds) * v3->hull_manager.gradient)
               + v3->hull_manager.hull_value_last_vpsi)
       + v12);
  v9 = obj1;
  v10 = dist1;
  v1 = (IVP_OO_Watcher *)((char *)v1 + 40);
  synapses->minlist_index = v8;
  IVP_U_Min_List::remove_minlist_elem(this: &v9->hull_manager.sorted_synapses, index: v1->index);
  v1->index = IVP_U_Min_List::add(
                this: &v9->hull_manager.sorted_synapses,
                elem: (int)v1,
                value: (float)((float)((float)(t_now.seconds - v9->hull_manager.last_vpsi_time.seconds)
                              * v9->hull_manager.gradient)
                      + v9->hull_manager.hull_value_last_vpsi)
              + v10);
}

//------------------------------------------------------------------------------
// Address: 0x100AA020
// Name: public: virtual enum IVP_HULL_ELEM_TYPE IVP_Synapse_OO::get_type(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Synapse_OO::get_type(IVP_Synapse_OO *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x100AA030
// Name: protected: virtual void IVP_OO_Watcher::get_objects(class IVP_Real_Object __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OO_Watcher::get_objects(IVP_OO_Watcher *this, IVP_Real_Object **objects_out)
{
  *objects_out = this->synapses[0].object;
  objects_out[1] = this->synapses[1].object;
}

//------------------------------------------------------------------------------
// Address: 0x100AA050
// Name: protected: virtual void IVP_OO_Watcher::get_ledges(class IVP_Compact_Ledge const __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OO_Watcher::get_ledges(IVP_OO_Watcher *this, const IVP_Compact_Ledge **ledges_out)
{
  *ledges_out = nullptr;
  ledges_out[1] = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100AA0B0
// Name: public: virtual void IVP_Synapse_OO::hull_limit_exceeded_event(class IVP_Hull_Manager __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Synapse_OO::hull_limit_exceeded_event(
        IVP_Synapse_OO *this,
        IVP_Hull_Manager *__formal,
        float __formala)
{
  IVP_OO_Watcher::hull_limit_exceeded_event(this: this->watcher);
}

//------------------------------------------------------------------------------
// Address: 0x100AA0C0
// Name: public: virtual void IVP_Synapse_OO::hull_manager_is_going_to_be_deleted_event(class IVP_Hull_Manager __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Synapse_OO::hull_manager_is_going_to_be_deleted_event(
        IVP_Synapse_OO *this,
        IVP_Hull_Manager *__formal)
{
  IVP_OO_Watcher *watcher; // ecx

  watcher = this->watcher;
  if ( watcher != nullptr )
    ((void (__thiscall *)(IVP_OO_Watcher *, int))watcher->dtr_IVP_Collision)(a1: watcher, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100AA0E0
// Name: public: IVP_OO_Watcher::IVP_OO_Watcher(class IVP_Collision_Delegator __near *,class IVP_Real_Object __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_OO_Watcher *__thiscall IVP_OO_Watcher::IVP_OO_Watcher(
        IVP_OO_Watcher *this,
        IVP_Collision_Delegator *del,
        IVP_Real_Object *obj0,
        IVP_Real_Object *obj1)
{
  IVP_Synapse_OO *synapses; // edi

  this->delegator = del;
  this->fvector_index[1] = -1;
  this->fvector_index[0] = -1;
  this->IVP_Collision_Delegator::__vftable = (IVP_Collision_Delegator_vtbl *)&IVP_Collision_Delegator::`vftable';
  this->IVP_Collision::IVP_Time_Event::__vftable = (IVP_OO_Watcher_vtbl *)&IVP_OO_Watcher::`vftable'{for `IVP_Collision'};
  this->IVP_Collision_Delegator::__vftable = (IVP_Collision_Delegator_vtbl *)&IVP_OO_Watcher::`vftable'{for `IVP_Collision_Delegator'};
  synapses = this->synapses;
  this->synapses[0].__vftable = (IVP_Synapse_OO_vtbl *)&IVP_Synapse_OO::`vftable';
  this->synapses[1].__vftable = (IVP_Synapse_OO_vtbl *)&IVP_Synapse_OO::`vftable';
  *(_DWORD *)&this->mindists.memsize = 8;
  this->mindists.elems = (void **)p_malloc(size: 0x20u);
  synapses->object = obj0;
  synapses->minlist_index = IVP_U_Min_List::add(
                              this: &obj0->hull_manager.sorted_synapses,
                              elem: (int)synapses,
                              value: (float)((float)((float)(obj0->environment->current_time.seconds
                                                    - obj0->hull_manager.last_vpsi_time.seconds)
                                            * obj0->hull_manager.gradient)
                                    + obj0->hull_manager.hull_value_last_vpsi)
                            + 1.0e20);
  synapses->watcher = this;
  this->synapses[1].object = obj1;
  this->synapses[1].minlist_index = IVP_U_Min_List::add(
                                      this: &obj1->hull_manager.sorted_synapses,
                                      elem: (int)&this->synapses[1],
                                      value: (float)((float)((float)(obj1->environment->current_time.seconds
                                                            - obj1->hull_manager.last_vpsi_time.seconds)
                                                    * obj1->hull_manager.gradient)
                                            + obj1->hull_manager.hull_value_last_vpsi)
                                    + 1.0e20);
  this->synapses[1].watcher = this;
  IVP_OO_Watcher::hull_limit_exceeded_event(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AA200
// Name: public: virtual IVP_OO_Watcher::~IVP_OO_Watcher(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OO_Watcher::~IVP_OO_Watcher(IVP_OO_Watcher *this)
{
  bool v2; // sf
  int v3; // esi
  void *v4; // ecx
  IVP_OO_Watcher *elems; // eax
  IVP_U_FVector<IVP_Collision> *p_mindists; // esi
  int i; // ebx
  void **v8; // ecx
  IVP_U_Min_List *v9; // ecx
  unsigned int v10; // [esp-4h] [ebp-10h]

  v3 = this->mindists.n_elems - 1;
  v2 = this->mindists.n_elems == 0;
  this->IVP_Collision::IVP_Time_Event::__vftable = (IVP_OO_Watcher_vtbl *)&IVP_OO_Watcher::`vftable'{for `IVP_Collision'};
  this->IVP_Collision_Delegator::__vftable = (IVP_Collision_Delegator_vtbl *)&IVP_OO_Watcher::`vftable'{for `IVP_Collision_Delegator'};
  if ( !v2 )
  {
    do
    {
      v4 = this->mindists.elems[v3];
      if ( v4 != nullptr )
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)v4 + 16))(a1: v4, a2: 1);
      --v3;
    }
    while ( v3 >= 0 );
  }
  this->delegator->collision_is_going_to_be_deleted_event(this: this->delegator, a2: this);
  elems = (IVP_OO_Watcher *)this->mindists.elems;
  if ( elems != this + 1 )
  {
    if ( elems != nullptr )
    {
      free(data: this->mindists.elems);
      this->mindists.elems = nullptr;
    }
    this->mindists.memsize = 0;
  }
  this->mindists.n_elems = 0;
  p_mindists = &this->mindists;
  for ( i = 1; i >= 0; --i )
  {
    v8 = p_mindists[-2].elems;
    p_mindists -= 2;
    v10 = (unsigned int)v8;
    v9 = (IVP_U_Min_List *)(*(_DWORD *)&p_mindists[1].memsize + 104);
    *(_DWORD *)&p_mindists->memsize = &IVP_Synapse_OO::`vftable';
    IVP_U_Min_List::remove_minlist_elem(this: v9, index: v10);
  }
  this->IVP_Collision_Delegator::__vftable = (IVP_Collision_Delegator_vtbl *)&IVP_Collision_Delegator::`vftable';
  this->IVP_Collision::IVP_Time_Event::__vftable = (IVP_OO_Watcher_vtbl *)&IVP_Collision::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100AA2A0
// Name: public: virtual void IVP_OO_Watcher::collision_is_going_to_be_deleted_event(class IVP_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OO_Watcher::collision_is_going_to_be_deleted_event(IVP_OO_Watcher *this, IVP_Collision *c)
{
  IVP_U_FVector<IVP_Collision>::remove_allow_resort(
    this: (IVP_U_FVector<IVP_Collision> *)&this->synapses[0].watcher,
    elem: c);
}
