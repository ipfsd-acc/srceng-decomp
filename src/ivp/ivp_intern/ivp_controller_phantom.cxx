// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_controller_phantom.cxx
// Functions: 17
// ============================================================

#include "ivp\ivp_intern\ivp_controller_phantom.h"

//------------------------------------------------------------------------------
// Address: 0x100764E0
// Name: public: void IVP_Controller_Phantom::add_listener_phantom(class IVP_Listener_Phantom __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Phantom::add_listener_phantom(IVP_Simulation_Unit *this, IVP_Core *add_core)
{
  IVP_Vector_of_Cores_2 *p_sim_unit_cores; // esi

  p_sim_unit_cores = &this->sim_unit_cores;
  if ( this->sim_unit_cores.n_elems >= this->sim_unit_cores.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->sim_unit_cores);
  p_sim_unit_cores->elems[p_sim_unit_cores->n_elems++] = add_core;
}

//------------------------------------------------------------------------------
// Address: 0x10080710
// Name: public: virtual IVP_U_Set_Active<class IVP_Mindist_Base>::~IVP_U_Set_Active<class IVP_Mindist_Base>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Set_Active<IVP_Mindist_Base>::~IVP_U_Set_Active<IVP_Mindist_Base>(
        IVP_U_Set_Active<IVP_Mindist_Base> *this)
{
  bool v2; // sf
  int v3; // edi
  void *v4; // ecx
  IVP_U_Set_Active<IVP_Mindist_Base> *elems; // eax

  v3 = this->listeners.n_elems - 1;
  v2 = this->listeners.n_elems == 0;
  this->__vftable = (IVP_U_Set_Active<IVP_Mindist_Base>_vtbl *)&IVP_U_Set_Active<IVP_Mindist_Base>::`vftable';
  if ( !v2 )
  {
    do
    {
      v4 = this->listeners.elems[v3];
      (*(void (__thiscall **)(void *, IVP_U_Set_Active<IVP_Mindist_Base> *))(*(_DWORD *)v4 + 12))(a1: v4, a2: this);
      --v3;
    }
    while ( v3 >= 0 );
  }
  elems = (IVP_U_Set_Active<IVP_Mindist_Base> *)this->listeners.elems;
  if ( elems != this + 1 )
  {
    if ( elems != nullptr )
      free(data: this->listeners.elems);
    this->listeners.elems = nullptr;
    this->listeners.memsize = 0;
  }
  this->listeners.n_elems = 0;
  this->__vftable = (IVP_U_Set_Active<IVP_Mindist_Base>_vtbl *)&IVP_U_Set<IVP_Mindist_Base>::`vftable';
  IVP_VHash::~IVP_VHash(this);
}

//------------------------------------------------------------------------------
// Address: 0x10085130
// Name: public: IVP_Template_Phantom::IVP_Template_Phantom(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Phantom *__thiscall IVP_Template_Phantom::IVP_Template_Phantom(IVP_Template_Phantom *this)
{
  *(_QWORD *)&this->manage_intruding_objects = 0;
  *(_QWORD *)&this->dont_check_for_unmoveables = 0;
  *(_QWORD *)&this->exit_policy_extra_radius = 0;
  this->exit_policy_extra_radius = 0.5;
  this->exit_policy_extra_time = 0.5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10085160
// Name: public: virtual void IVP_Controller_Phantom::event_object_deleted(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Phantom::event_object_deleted(IVP_Controller_Phantom *this, IVP_Event_Object *pEvent)
{
  this->event_object_revived(this, a2: pEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10085170
// Name: public: void IVP_Controller_Phantom::wake_all_sleeping_objects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Phantom::wake_all_sleeping_objects(IVP_Controller_Phantom *this)
{
  IVP_U_Set<IVP_Core> *set_of_sleeping_cores; // eax
  int size_mm; // esi
  IVP_Real_Object ***elem; // eax
  IVP_U_Set_Active<IVP_Core> *set_of_cores; // eax
  int v6; // esi
  IVP_Real_Object ***v7; // eax

  set_of_sleeping_cores = this->set_of_sleeping_cores;
  if ( set_of_sleeping_cores != nullptr )
  {
    size_mm = set_of_sleeping_cores->size_mm;
    while ( size_mm >= 0 )
    {
      while ( 1 )
      {
        elem = (IVP_Real_Object ***)this->set_of_sleeping_cores->elems[size_mm--].elem;
        if ( elem != nullptr )
          break;
        if ( size_mm < 0 )
          goto LABEL_6;
      }
      IVP_Real_Object::ensure_in_simulation(this: *elem[21]);
    }
  }
LABEL_6:
  set_of_cores = this->set_of_cores;
  if ( set_of_cores != nullptr )
  {
    v6 = set_of_cores->size_mm;
    while ( v6 >= 0 )
    {
      while ( 1 )
      {
        v7 = (IVP_Real_Object ***)this->set_of_cores->elems[v6--].elem;
        if ( v7 != nullptr )
          break;
        if ( v6 < 0 )
          return;
      }
      IVP_Real_Object::ensure_in_simulation(this: *v7[21]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100851E0
// Name: protected: void IVP_Controller_Phantom::fire_event_core_entered(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Phantom::fire_event_core_entered(IVP_Controller_Phantom *this, IVP_Core *pCore)
{
  int v3; // esi
  void *v4; // ecx

  v3 = this->listeners.n_elems - 1;
  if ( this->listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->listeners.elems[v3];
      (*(void (__thiscall **)(void *, IVP_Controller_Phantom *, IVP_Core *))(*(_DWORD *)v4 + 8))(
        a1: v4,
        a2: this,
        a3: pCore);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085210
// Name: protected: void IVP_Controller_Phantom::fire_event_core_left(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Phantom::fire_event_core_left(IVP_Controller_Phantom *this, IVP_Core *pCore)
{
  int v3; // esi
  void *v4; // ecx

  v3 = this->listeners.n_elems - 1;
  if ( this->listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->listeners.elems[v3];
      (*(void (__thiscall **)(void *, IVP_Controller_Phantom *, IVP_Core *))(*(_DWORD *)v4 + 12))(
        a1: v4,
        a2: this,
        a3: pCore);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085240
// Name: public: void IVP_Controller_Phantom::remove_listener_phantom(class IVP_Listener_Phantom __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Phantom::remove_listener_phantom(
        IVP_Controller_Phantom *this,
        IVP_Listener_Phantom *listener)
{
  unsigned __int16 n_elems; // si
  int v3; // eax
  IVP_Listener_Phantom **v4; // edx

  n_elems = this->listeners.n_elems;
  v3 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v4 = (IVP_Listener_Phantom **)&this->listeners.elems[v3];
    do
    {
      if ( *v4 == listener )
        break;
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  for ( this->listeners.n_elems = n_elems - 1; v3 < this->listeners.n_elems; ++v3 )
    this->listeners.elems[v3] = this->listeners.elems[v3 + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10085290
// Name: protected: void IVP_Controller_Phantom::add_sleeping_object(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Phantom::add_sleeping_object(IVP_Controller_Phantom *this, IVP_Real_Object *pObject)
{
  IVP_Real_Object::add_listener_object(this: pObject, listener: this);
  IVP_VHash::add_elem(
    this: this->set_of_sleeping_cores,
    elem: pObject->physical_core,
    hash_index: (75 * (int)pObject->physical_core + ((1001 * (int)pObject->physical_core) >> 16)) | 0x80000000);
}

//------------------------------------------------------------------------------
// Address: 0x100852D0
// Name: protected: void IVP_Controller_Phantom::remove_sleeping_object(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Phantom::remove_sleeping_object(IVP_Controller_Phantom *this, IVP_Real_Object *pObject)
{
  IVP_Real_Object::remove_listener_object(this: pObject, listener: this);
  IVP_VHash::remove_elem(
    this: this->set_of_sleeping_cores,
    elem: pObject->physical_core,
    hash_index: (75 * (int)pObject->physical_core + ((1001 * (int)pObject->physical_core) >> 16)) | 0x80000000);
}

//------------------------------------------------------------------------------
// Address: 0x10085310
// Name: public: virtual void IVP_Controller_Phantom::event_object_revived(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Phantom::event_object_revived(IVP_Controller_Phantom *this, IVP_Event_Object *pEvent)
{
  IVP_Real_Object *real_object; // edi
  IVP_Core *physical_core; // edi

  if ( IVP_VHash::find_elem(
         this: this->set_of_sleeping_cores,
         elem: pEvent->real_object->physical_core,
         hash_index: (75 * (int)pEvent->real_object->physical_core + ((1001 * (int)pEvent->real_object->physical_core) >> 16))
       | 0x80000000) != nullptr )
  {
    real_object = pEvent->real_object;
    IVP_Real_Object::remove_listener_object(this: real_object, listener: this);
    IVP_VHash::remove_elem(
      this: this->set_of_sleeping_cores,
      elem: real_object->physical_core,
      hash_index: (75 * (int)real_object->physical_core + ((1001 * (int)real_object->physical_core) >> 16)) | 0x80000000);
    if ( this->set_of_cores != nullptr )
    {
      physical_core = pEvent->real_object->physical_core;
      if ( IVP_VHash_Store::find_elem(this: this->mindist_core_counter, key_elem: physical_core) == nullptr )
        IVP_Controller_Phantom::fire_event_core_left(this, pCore: physical_core);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100853B0
// Name: public: void IVP_U_Set_Active<class IVP_Core>::remove_element(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Set_Active<IVP_Core>::remove_element(
        IVP_U_Set_Active<IVP_Real_Object> *this,
        IVP_Real_Object *elem)
{
  int v3; // esi
  void *v4; // ecx

  IVP_VHash::remove_elem(this, elem, hash_index: (75 * (_DWORD)elem + ((1001 * (int)elem) >> 16)) | 0x80000000);
  v3 = this->listeners.n_elems - 1;
  if ( this->listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->listeners.elems[v3];
      (*(void (__thiscall **)(void *, IVP_U_Set_Active<IVP_Real_Object> *, IVP_Real_Object *))(*(_DWORD *)v4 + 8))(
        a1: v4,
        a2: this,
        a3: elem);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085400
// Name: public: void IVP_U_Set_Active<class IVP_Core>::add_element(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Set_Active<IVP_Core>::add_element(IVP_U_Set_Active<IVP_Real_Object> *this, IVP_Real_Object *elem)
{
  int v3; // esi
  void *v4; // ecx

  IVP_VHash::add_elem(this, elem, hash_index: (75 * (_DWORD)elem + ((1001 * (int)elem) >> 16)) | 0x80000000);
  v3 = this->listeners.n_elems - 1;
  if ( this->listeners.n_elems != 0 )
  {
    do
    {
      v4 = this->listeners.elems[v3];
      (*(void (__thiscall **)(void *, IVP_U_Set_Active<IVP_Real_Object> *, IVP_Real_Object *))(*(_DWORD *)v4 + 4))(
        a1: v4,
        a2: this,
        a3: elem);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085450
// Name: public: virtual IVP_Controller_Phantom::~IVP_Controller_Phantom(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Phantom::~IVP_Controller_Phantom(IVP_Controller_Phantom *this)
{
  IVP_U_Set_Active<IVP_Core> *set_of_cores; // eax
  int size_mm; // eax
  const void *elem; // edi
  IVP_U_Set<IVP_Core> *set_of_sleeping_cores; // eax
  int index; // eax
  const void *v7; // edi
  int v8; // edi
  void *v9; // ecx
  IVP_VHash_Store *mindist_core_counter; // edi
  IVP_VHash_Store *mindist_object_counter; // edi
  IVP_U_Set_Active<IVP_Real_Object> *set_of_objects; // ecx
  IVP_U_Set<IVP_Core> *v13; // eax
  int v14; // edi
  IVP_Real_Object ***v15; // eax
  IVP_U_Set<IVP_Core> *v16; // ecx
  IVP_U_Set_Active<IVP_Core> *v17; // ecx
  bool v18; // sf
  int v19; // ebx
  void *v20; // ecx
  IVP_Controller_Phantom *elems; // eax
  IVP_Controller_Phantom *v22; // eax
  int v23; // ebx
  void *v24; // ecx
  int v25; // ebx
  void *v26; // ecx
  IVP_U_Set_Enumerator<IVP_Core> setEnum; // [esp+Ch] [ebp-4h]
  IVP_U_Set_Enumerator<IVP_Core> setEnuma; // [esp+Ch] [ebp-4h]

  set_of_cores = this->set_of_cores;
  this->__vftable = (IVP_Controller_Phantom_vtbl *)&IVP_Controller_Phantom::`vftable';
  if ( set_of_cores != nullptr )
  {
    size_mm = set_of_cores->size_mm;
    while ( size_mm >= 0 )
    {
      while ( 1 )
      {
        elem = this->set_of_cores->elems[size_mm--].elem;
        setEnum.index = size_mm;
        if ( elem != nullptr )
          break;
        if ( size_mm < 0 )
          goto LABEL_6;
      }
      v23 = this->listeners.n_elems - 1;
      if ( this->listeners.n_elems != 0 )
      {
        do
        {
          v24 = this->listeners.elems[v23];
          (*(void (__thiscall **)(void *, IVP_Controller_Phantom *, const void *))(*(_DWORD *)v24 + 12))(
            a1: v24,
            a2: this,
            a3: elem);
          --v23;
        }
        while ( v23 >= 0 );
        size_mm = setEnum.index;
      }
    }
  }
LABEL_6:
  set_of_sleeping_cores = this->set_of_sleeping_cores;
  if ( set_of_sleeping_cores != nullptr )
  {
    index = set_of_sleeping_cores->size_mm;
    while ( index >= 0 )
    {
      while ( 1 )
      {
        v7 = this->set_of_sleeping_cores->elems[index--].elem;
        setEnuma.index = index;
        if ( v7 != nullptr )
          break;
        if ( index < 0 )
          goto LABEL_11;
      }
      v25 = this->listeners.n_elems - 1;
      if ( this->listeners.n_elems != 0 )
      {
        do
        {
          v26 = this->listeners.elems[v25];
          (*(void (__thiscall **)(void *, IVP_Controller_Phantom *, const void *))(*(_DWORD *)v26 + 12))(
            a1: v26,
            a2: this,
            a3: v7);
          --v25;
        }
        while ( v25 >= 0 );
        index = setEnuma.index;
      }
    }
  }
LABEL_11:
  v8 = this->listeners.n_elems - 1;
  if ( this->listeners.n_elems != 0 )
  {
    do
    {
      v9 = this->listeners.elems[v8];
      (*(void (__thiscall **)(void *, IVP_Controller_Phantom *))(*(_DWORD *)v9 + 16))(a1: v9, a2: this);
      --v8;
    }
    while ( v8 >= 0 );
  }
  this->object->controller_phantom = nullptr;
  mindist_core_counter = this->mindist_core_counter;
  if ( mindist_core_counter != nullptr )
  {
    IVP_VHash_Store::~IVP_VHash_Store(this: this->mindist_core_counter);
    free(data: mindist_core_counter);
  }
  mindist_object_counter = this->mindist_object_counter;
  this->mindist_core_counter = nullptr;
  if ( mindist_object_counter != nullptr )
  {
    IVP_VHash_Store::~IVP_VHash_Store(this: mindist_object_counter);
    free(data: mindist_object_counter);
  }
  set_of_objects = this->set_of_objects;
  this->mindist_object_counter = nullptr;
  if ( set_of_objects != nullptr )
    ((void (__thiscall *)(IVP_U_Set_Active<IVP_Real_Object> *, int))set_of_objects->dtr_IVP_VHash)(
      a1: set_of_objects,
      a2: 1);
  v13 = this->set_of_sleeping_cores;
  this->set_of_objects = nullptr;
  if ( v13 != nullptr )
  {
    v14 = v13->size_mm;
    while ( v14 >= 0 )
    {
      while ( 1 )
      {
        v15 = (IVP_Real_Object ***)this->set_of_sleeping_cores->elems[v14--].elem;
        if ( v15 != nullptr )
          break;
        if ( v14 < 0 )
          goto LABEL_24;
      }
      IVP_Real_Object::remove_listener_object(this: *v15[21], listener: this);
    }
LABEL_24:
    v16 = this->set_of_sleeping_cores;
    if ( v16 != nullptr )
      ((void (__thiscall *)(IVP_U_Set<IVP_Core> *, int))v16->dtr_IVP_VHash)(a1: v16, a2: 1);
    this->set_of_sleeping_cores = nullptr;
  }
  v17 = this->set_of_cores;
  if ( v17 != nullptr )
    ((void (__thiscall *)(IVP_U_Set_Active<IVP_Core> *, int))v17->dtr_IVP_VHash)(a1: v17, a2: 1);
  this->set_of_cores = nullptr;
  v19 = this->set_of_mindists.listeners.n_elems - 1;
  v18 = this->set_of_mindists.listeners.n_elems == 0;
  this->set_of_mindists.__vftable = (IVP_U_Set_Active<IVP_Mindist_Base>_vtbl *)&IVP_U_Set_Active<IVP_Mindist_Base>::`vftable';
  if ( !v18 )
  {
    do
    {
      v20 = this->set_of_mindists.listeners.elems[v19];
      (*(void (__thiscall **)(void *, IVP_U_Set_Active<IVP_Mindist_Base> *))(*(_DWORD *)v20 + 12))(
        a1: v20,
        a2: &this->set_of_mindists);
      --v19;
    }
    while ( v19 >= 0 );
  }
  elems = (IVP_Controller_Phantom *)this->set_of_mindists.listeners.elems;
  if ( elems != (IVP_Controller_Phantom *)&this->set_of_objects )
  {
    if ( elems != nullptr )
      free(data: this->set_of_mindists.listeners.elems);
    this->set_of_mindists.listeners.elems = nullptr;
    this->set_of_mindists.listeners.memsize = 0;
  }
  this->set_of_mindists.listeners.n_elems = 0;
  this->set_of_mindists.__vftable = (IVP_U_Set_Active<IVP_Mindist_Base>_vtbl *)&IVP_U_Set<IVP_Mindist_Base>::`vftable';
  IVP_VHash::~IVP_VHash(this: &this->set_of_mindists);
  v22 = (IVP_Controller_Phantom *)this->listeners.elems;
  if ( v22 != (IVP_Controller_Phantom *)&this->set_of_mindists )
  {
    if ( v22 != nullptr )
      free(data: this->listeners.elems);
    this->listeners.elems = nullptr;
    this->listeners.memsize = 0;
  }
  this->listeners.n_elems = 0;
  this->__vftable = (IVP_Controller_Phantom_vtbl *)&IVP_Listener_Object::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100856A0
// Name: protected: void IVP_Controller_Phantom::mindist_entered_volume(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Phantom::mindist_entered_volume(IVP_Controller_Phantom *this, IVP_Mindist *mindist)
{
  IVP_U_Set_Active<IVP_Mindist_Base> *p_set_of_mindists; // ebx
  int v4; // edi
  void *v5; // ecx
  IVP_Mindist *v6; // ebx
  IVP_Real_Object *l_obj; // edi
  char *elem; // eax
  IVP_VHash_Store *mindist_object_counter; // ecx
  IVP_Real_Object *v10; // ebx
  IVP_Real_Object *physical_core; // edi
  char *v12; // eax
  IVP_VHash_Store *mindist_core_counter; // ecx
  int v14; // edi
  void (__thiscall ***v15)(void *, IVP_Controller_Phantom *, IVP_Mindist *); // ecx

  p_set_of_mindists = &this->set_of_mindists;
  IVP_VHash::add_elem(
    this: &this->set_of_mindists,
    elem: mindist,
    hash_index: (75 * (_DWORD)mindist + ((1001 * (int)mindist) >> 16)) | 0x80000000);
  v4 = p_set_of_mindists->listeners.n_elems - 1;
  if ( p_set_of_mindists->listeners.n_elems != 0 )
  {
    do
    {
      v5 = p_set_of_mindists->listeners.elems[v4];
      (*(void (__thiscall **)(void *, IVP_U_Set_Active<IVP_Mindist_Base> *, IVP_Mindist *))(*(_DWORD *)v5 + 4))(
        a1: v5,
        a2: p_set_of_mindists,
        a3: mindist);
      --v4;
    }
    while ( v4 >= 0 );
  }
  v6 = mindist;
  if ( this->set_of_objects != nullptr )
  {
    l_obj = mindist->synapse[0].l_obj;
    if ( l_obj == this->object )
      l_obj = mindist->synapse[1].l_obj;
    elem = (char *)IVP_VHash_Store::find_elem(this: this->mindist_object_counter, key_elem: l_obj);
    mindist_object_counter = this->mindist_object_counter;
    if ( elem != nullptr )
    {
      IVP_VHash_Store::change_elem(this: mindist_object_counter, key_elem: l_obj, new_value: elem + 1);
    }
    else
    {
      IVP_VHash_Store::add_elem(this: mindist_object_counter, key_elem: l_obj, elem: (void *)1);
      IVP_U_Set_Active<IVP_Core>::add_element(this: this->set_of_objects, elem: l_obj);
    }
  }
  if ( this->set_of_cores != nullptr )
  {
    if ( mindist->synapse[0].l_obj == this->object )
      v10 = mindist->synapse[1].l_obj;
    else
      v10 = mindist->synapse[0].l_obj;
    physical_core = (IVP_Real_Object *)v10->physical_core;
    v12 = (char *)IVP_VHash_Store::find_elem(this: this->mindist_core_counter, key_elem: physical_core);
    mindist_core_counter = this->mindist_core_counter;
    if ( v12 != nullptr )
    {
      IVP_VHash_Store::change_elem(this: mindist_core_counter, key_elem: physical_core, new_value: v12 + 1);
    }
    else
    {
      IVP_VHash_Store::add_elem(this: mindist_core_counter, key_elem: physical_core, elem: (void *)1);
      IVP_U_Set_Active<IVP_Core>::add_element(
        this: (IVP_U_Set_Active<IVP_Real_Object> *)this->set_of_cores,
        elem: physical_core);
      if ( IVP_VHash::find_elem(
             this: this->set_of_sleeping_cores,
             elem: physical_core,
             hash_index: (75 * (_DWORD)physical_core + ((1001 * (int)physical_core) >> 16)) | 0x80000000) != nullptr )
        IVP_Controller_Phantom::remove_sleeping_object(this, pObject: v10);
      else
        IVP_Controller_Phantom::fire_event_core_entered(this, pCore: (IVP_Core *)physical_core);
    }
    v6 = mindist;
  }
  v14 = this->listeners.n_elems - 1;
  if ( this->listeners.n_elems != 0 )
  {
    do
    {
      v15 = (void (__thiscall ***)(void *, IVP_Controller_Phantom *, IVP_Mindist *))this->listeners.elems[v14];
      (**v15)(a1: v15, a2: this, a3: v6);
      --v14;
    }
    while ( v14 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100857D0
// Name: protected: void IVP_Controller_Phantom::mindist_left_volume(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Phantom::mindist_left_volume(IVP_Controller_Phantom *this, IVP_Mindist *mindist)
{
  IVP_U_Set_Active<IVP_Mindist_Base> *p_set_of_mindists; // ebx
  int v4; // edi
  void *v5; // ecx
  IVP_Mindist *v6; // ebx
  IVP_Real_Object *l_obj; // edi
  int elem; // eax
  IVP_VHash_Store *mindist_object_counter; // ecx
  IVP_Real_Object *v10; // ebx
  IVP_Real_Object *physical_core; // edi
  int v12; // eax
  IVP_VHash_Store *mindist_core_counter; // ecx
  int v14; // edi
  void *v15; // ecx

  p_set_of_mindists = &this->set_of_mindists;
  IVP_VHash::remove_elem(
    this: &this->set_of_mindists,
    elem: mindist,
    hash_index: (75 * (_DWORD)mindist + ((1001 * (int)mindist) >> 16)) | 0x80000000);
  v4 = p_set_of_mindists->listeners.n_elems - 1;
  if ( p_set_of_mindists->listeners.n_elems != 0 )
  {
    do
    {
      v5 = p_set_of_mindists->listeners.elems[v4];
      (*(void (__thiscall **)(void *, IVP_U_Set_Active<IVP_Mindist_Base> *, IVP_Mindist *))(*(_DWORD *)v5 + 8))(
        a1: v5,
        a2: p_set_of_mindists,
        a3: mindist);
      --v4;
    }
    while ( v4 >= 0 );
  }
  v6 = mindist;
  if ( this->set_of_objects != nullptr )
  {
    l_obj = mindist->synapse[0].l_obj;
    if ( l_obj == this->object )
      l_obj = mindist->synapse[1].l_obj;
    elem = (int)IVP_VHash_Store::find_elem(this: this->mindist_object_counter, key_elem: l_obj);
    mindist_object_counter = this->mindist_object_counter;
    if ( elem <= 1 )
    {
      IVP_VHash_Store::remove_elem(this: mindist_object_counter, key_elem: l_obj);
      IVP_U_Set_Active<IVP_Core>::remove_element(this: this->set_of_objects, elem: l_obj);
    }
    else
    {
      IVP_VHash_Store::change_elem(this: mindist_object_counter, key_elem: l_obj, new_value: (void *)(elem - 1));
    }
  }
  if ( this->set_of_cores != nullptr )
  {
    if ( mindist->synapse[0].l_obj == this->object )
      v10 = mindist->synapse[1].l_obj;
    else
      v10 = mindist->synapse[0].l_obj;
    physical_core = (IVP_Real_Object *)v10->physical_core;
    v12 = (int)IVP_VHash_Store::find_elem(this: this->mindist_core_counter, key_elem: physical_core);
    mindist_core_counter = this->mindist_core_counter;
    if ( v12 <= 1 )
    {
      IVP_VHash_Store::remove_elem(this: mindist_core_counter, key_elem: physical_core);
      IVP_U_Set_Active<IVP_Core>::remove_element(
        this: (IVP_U_Set_Active<IVP_Real_Object> *)this->set_of_cores,
        elem: physical_core);
      if ( v10->flags == 8 )
        IVP_Controller_Phantom::add_sleeping_object(this, pObject: v10);
      else
        IVP_Controller_Phantom::fire_event_core_left(this, pCore: (IVP_Core *)physical_core);
    }
    else
    {
      IVP_VHash_Store::change_elem(this: mindist_core_counter, key_elem: physical_core, new_value: (void *)(v12 - 1));
    }
    v6 = mindist;
  }
  v14 = this->listeners.n_elems - 1;
  if ( this->listeners.n_elems != 0 )
  {
    do
    {
      v15 = this->listeners.elems[v14];
      (*(void (__thiscall **)(void *, IVP_Controller_Phantom *, IVP_Mindist *))(*(_DWORD *)v15 + 4))(
        a1: v15,
        a2: this,
        a3: v6);
      --v14;
    }
    while ( v14 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100858E0
// Name: protected: IVP_Controller_Phantom::IVP_Controller_Phantom(class IVP_Real_Object __near *,class IVP_Template_Phantom const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Controller_Phantom *__thiscall IVP_Controller_Phantom::IVP_Controller_Phantom(
        IVP_Controller_Phantom *this,
        IVP_Real_Object *object_in,
        const IVP_Template_Phantom *templat)
{
  IVP_VHash *v4; // eax
  IVP_VHash *v5; // edi
  IVP_VHash_Store *v6; // eax
  IVP_VHash *v7; // eax
  IVP_VHash *v8; // edi
  IVP_VHash_Store *v9; // eax
  IVP_VHash_Store *v10; // eax
  IVP_VHash *v11; // eax
  IVP_U_Set<IVP_Core> *v12; // edi
  IVP_Real_Object *object; // eax
  IVP_Real_Object *v14; // eax
  IVP_Synapse_Real *i; // edi
  int mindist_offset; // esi
  int v17; // ecx
  IVP_Mindist *v18; // esi
  IVP_Synapse_Real *j; // edi
  int v20; // esi
  int v21; // eax
  float *v22; // esi
  unsigned int v23; // eax
  bool v24; // cc
  IVP_Real_Object *v25; // eax
  unsigned int first_element; // esi
  const IVP_Template_Phantom *p_sorted_synapses; // eax
  IVP_BOOL manage_intruding_cores; // edx
  int v29; // esi
  int v30; // edi
  int v31; // ecx
  int v32; // eax
  const IVP_Template_Phantom *templata; // [esp+18h] [ebp+Ch]

  this->__vftable = (IVP_Controller_Phantom_vtbl *)&IVP_Controller_Phantom::`vftable';
  *(_DWORD *)&this->listeners.memsize = 0;
  this->listeners.elems = nullptr;
  IVP_VHash::IVP_VHash(this: &this->set_of_mindists, size_i: 16);
  this->set_of_mindists.__vftable = (IVP_U_Set_Active<IVP_Mindist_Base>_vtbl *)&IVP_U_Set_Active<IVP_Mindist_Base>::`vftable';
  *(_DWORD *)&this->set_of_mindists.listeners.memsize = 0;
  this->set_of_mindists.listeners.elems = nullptr;
  this->object = object_in;
  if ( templat->manage_intruding_objects != IVP_FALSE )
  {
    v4 = (IVP_VHash *)p_malloc(size: 0x18u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      IVP_VHash::IVP_VHash(this: v4, size_i: 16);
      v5->__vftable = (IVP_VHash_vtbl *)&IVP_U_Set_Active<IVP_Mindist_Base>::`vftable';
      v5[1].__vftable = nullptr;
      v5[1].size_mm = 0;
    }
    else
    {
      v5 = nullptr;
    }
    this->set_of_objects = (IVP_U_Set_Active<IVP_Real_Object> *)v5;
    v6 = (IVP_VHash_Store *)p_malloc(size: 0x14u);
    if ( v6 != nullptr )
      this->mindist_object_counter = IVP_VHash_Store::IVP_VHash_Store(this: v6, size_i: 16);
    else
      this->mindist_object_counter = nullptr;
  }
  else
  {
    this->set_of_objects = nullptr;
    this->mindist_object_counter = nullptr;
  }
  if ( templat->manage_intruding_cores != IVP_FALSE )
  {
    v7 = (IVP_VHash *)p_malloc(size: 0x18u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      IVP_VHash::IVP_VHash(this: v7, size_i: 16);
      v8->__vftable = (IVP_VHash_vtbl *)&IVP_U_Set_Active<IVP_Mindist_Base>::`vftable';
      v8[1].__vftable = nullptr;
      v8[1].size_mm = 0;
    }
    else
    {
      v8 = nullptr;
    }
    this->set_of_cores = (IVP_U_Set_Active<IVP_Core> *)v8;
    v9 = (IVP_VHash_Store *)p_malloc(size: 0x14u);
    if ( v9 != nullptr )
      v10 = IVP_VHash_Store::IVP_VHash_Store(this: v9, size_i: 16);
    else
      v10 = nullptr;
    this->mindist_core_counter = v10;
    if ( templat->manage_sleeping_cores != IVP_FALSE )
    {
      v11 = (IVP_VHash *)p_malloc(size: 0x10u);
      v12 = (IVP_U_Set<IVP_Core> *)v11;
      if ( v11 != nullptr )
      {
        IVP_VHash::IVP_VHash(this: v11, size_i: 16);
        v12->__vftable = (IVP_U_Set<IVP_Core>_vtbl *)&IVP_U_Set<IVP_Mindist_Base>::`vftable';
        this->set_of_sleeping_cores = v12;
      }
      else
      {
        this->set_of_sleeping_cores = nullptr;
      }
    }
  }
  else
  {
    this->set_of_cores = nullptr;
    this->set_of_sleeping_cores = nullptr;
    this->mindist_core_counter = nullptr;
  }
  if ( templat->dont_check_for_unmoveables == IVP_FALSE )
  {
    object = this->object;
    if ( object->flags == 16 )
    {
      *(_BYTE *)&object->flags = 9;
      IVP_Mindist_Manager::recheck_ov_element(this: this->object->environment->mindist_manager, object: this->object);
    }
  }
  v14 = this->object;
  this->exit_policy_extra_radius = templat->exit_policy_extra_radius;
  for ( i = v14->invalid_synapses; i != nullptr; i = (IVP_Synapse_Real *)i->next )
  {
    mindist_offset = i->mindist_offset;
    v17 = *(int *)((char *)&i->edge + mindist_offset);
    v18 = (IVP_Mindist *)((char *)i + mindist_offset);
    *((_DWORD *)&v18->IVP_Mindist_Base + 5) = v17 & 0xFFFFCFFF | 0x1000;
    IVP_Controller_Phantom::mindist_entered_volume(this, mindist: v18);
    *((_DWORD *)&v18->IVP_Mindist_Base + 5) = *((_DWORD *)&v18->IVP_Mindist_Base + 5) & 0xFFFFF3FF | 0x400;
  }
  for ( j = this->object->exact_synapses; j != nullptr; j = (IVP_Synapse_Real *)j->next )
  {
    v20 = j->mindist_offset;
    v21 = *(int *)((char *)&j->edge + v20);
    v22 = (float *)((char *)j + v20);
    v23 = v21 & 0xFFFFCFFF | 0x1000;
    v24 = v22[23] >= 0.0;
    *((_DWORD *)v22 + 5) = v23;
    if ( v24 )
    {
      *((_DWORD *)v22 + 5) = v23 & 0xFFFFF3FF;
    }
    else
    {
      IVP_Controller_Phantom::mindist_entered_volume(this, mindist: (IVP_Mindist *)v22);
      *((_DWORD *)v22 + 5) = (_DWORD)v22[5] & 0xFFFFF3FF | 0x400;
    }
  }
  v25 = this->object;
  first_element = v25->hull_manager.sorted_synapses.first_element;
  p_sorted_synapses = (const IVP_Template_Phantom *)&v25->hull_manager.sorted_synapses;
  for ( templata = p_sorted_synapses; first_element != 0xFFFF; p_sorted_synapses = templata )
  {
    manage_intruding_cores = p_sorted_synapses->manage_intruding_cores;
    v29 = 2 * first_element;
    v30 = *(_DWORD *)(manage_intruding_cores + 8 * v29 + 12);
    first_element = *(unsigned __int16 *)(manage_intruding_cores + 8 * v29 + 4);
    if ( v30 == 0 )
      break;
    if ( (**(int (__thiscall ***)(int))v30)(a1: v30) == 0 )
    {
      v31 = *(__int16 *)(v30 + 24);
      v32 = *(_DWORD *)(v31 + v30 + 20);
      if ( (v32 & 0x3000) == 0 )
        *(_DWORD *)(v31 + v30 + 20) = v32 & 0xFFFFCFFF | 0x1000;
    }
  }
  this->client_data = nullptr;
  return this;
}
