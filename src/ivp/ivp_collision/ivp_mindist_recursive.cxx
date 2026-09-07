// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_mindist_recursive.cxx
// Functions: 11
// ============================================================

#include "ivp\ivp_collision\ivp_mindist_recursive.h"

//------------------------------------------------------------------------------
// Address: 0x10039970
// Name: public: virtual enum IVP_BOOL IVP_Mindist_Recursive::is_recursive(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Mindist_Recursive::is_recursive(IVP_SurfaceManager_Ball *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A3E50
// Name: public: virtual void IVP_Mindist_Recursive::change_spawned_mindist_count(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Recursive::change_spawned_mindist_count(IVP_Mindist_Recursive *this, int change)
{
  this->fvector_index[1] += change;
  (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this - 30) + 8))(a1: *((_DWORD *)this - 30), a2: change);
}

//------------------------------------------------------------------------------
// Address: 0x100A3E70
// Name: public: virtual int IVP_Mindist_Recursive::get_spawned_mindist_count(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Mindist_Recursive::get_spawned_mindist_count(IVP_Mindist_Recursive *this)
{
  if ( (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this - 30) + 12))(a1: *((_DWORD *)this - 30)) <= 0 )
    return this->fvector_index[1];
  else
    return (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this - 30) + 12))(a1: *((_DWORD *)this - 30));
}

//------------------------------------------------------------------------------
// Address: 0x100A3EA0
// Name: private: void IVP_Mindist_Recursive::delete_all_children(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Recursive::delete_all_children(IVP_Mindist_Recursive *this)
{
  int n_elems; // ebx
  int v3; // edi
  void *v4; // ecx
  IVP_Mindist_Recursive *elems; // eax

  n_elems = this->mindists.n_elems;
  v3 = n_elems - 1;
  if ( this->mindists.n_elems != 0 )
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
  this->change_spawned_mindist_count(this: &this->IVP_Collision_Delegator, a2: -n_elems);
  elems = (IVP_Mindist_Recursive *)this->mindists.elems;
  if ( elems == (IVP_Mindist_Recursive *)&this->recursive_status )
  {
    this->mindists.n_elems = 0;
  }
  else
  {
    if ( elems != nullptr )
    {
      free(data: this->mindists.elems);
      this->mindists.elems = nullptr;
    }
    *(_DWORD *)&this->mindists.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3F20
// Name: public: IVP_Mindist_Recursive::IVP_Mindist_Recursive(class IVP_Environment __near *,class IVP_Collision_Delegator __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Mindist_Recursive *__thiscall IVP_Mindist_Recursive::IVP_Mindist_Recursive(
        IVP_Mindist_Recursive *this,
        IVP_Environment *env,
        IVP_Collision_Delegator *del)
{
  IVP_Mindist::IVP_Mindist(this, my_env: env, del);
  this->IVP_Collision_Delegator::__vftable = (IVP_Collision_Delegator_vtbl *)&IVP_Collision_Delegator::`vftable';
  this->IVP_Mindist::IVP_Mindist_Base::IVP_Collision::IVP_Time_Event::__vftable = (IVP_Mindist_Recursive_vtbl *)&IVP_Mindist_Recursive::`vftable'{for `IVP_Mindist'};
  this->IVP_Collision_Delegator::__vftable = (IVP_Collision_Delegator_vtbl *)&IVP_Mindist_Recursive::`vftable'{for `IVP_Collision_Delegator'};
  this->mindists.elems = nullptr;
  *(_DWORD *)&this->mindists.memsize = 0;
  this->spawned_mindist_count = 0;
  this->recursive_status = IVP_MR_NORMAL;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A3F90
// Name: public: virtual IVP_Mindist_Recursive::~IVP_Mindist_Recursive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Recursive::~IVP_Mindist_Recursive(IVP_Mindist_Recursive *this)
{
  IVP_Mindist_Recursive *elems; // eax

  this->IVP_Mindist::IVP_Mindist_Base::IVP_Collision::IVP_Time_Event::__vftable = (IVP_Mindist_Recursive_vtbl *)&IVP_Mindist_Recursive::`vftable'{for `IVP_Mindist'};
  this->IVP_Collision_Delegator::__vftable = (IVP_Collision_Delegator_vtbl *)&IVP_Mindist_Recursive::`vftable'{for `IVP_Collision_Delegator'};
  IVP_Mindist_Recursive::delete_all_children(this);
  elems = (IVP_Mindist_Recursive *)this->mindists.elems;
  if ( elems != (IVP_Mindist_Recursive *)&this->recursive_status )
  {
    if ( elems != nullptr )
    {
      free(data: this->mindists.elems);
      this->mindists.elems = nullptr;
    }
    this->mindists.memsize = 0;
  }
  this->mindists.n_elems = 0;
  this->IVP_Collision_Delegator::__vftable = (IVP_Collision_Delegator_vtbl *)&IVP_Collision_Delegator::`vftable';
  IVP_Mindist::~IVP_Mindist(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A4000
// Name: private: void IVP_Mindist_Recursive::recheck_recursive_childs(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Recursive::recheck_recursive_childs(IVP_Mindist_Recursive *this, float dist_intra)
{
  IVP_Real_Object *l_obj; // eax
  IVP_Real_Object *v4; // ecx
  IVP_Collision_Delegator_vtbl *v5; // edx
  int (__thiscall *get_spawned_mindist_count)(IVP_Collision_Delegator *); // eax
  IVP_MINDIST_RECURSIVE_TYPES recursive_status; // edx
  IVP_MINDIST_RECURSIVE_TYPES v8; // ecx
  _DWORD *v9; // eax
  int n_elems; // ebx
  const IVP_Compact_Ledge *v11; // eax
  const IVP_Compact_Ledge *v12; // ecx
  const IVP_Compact_Ledge *sl[2]; // [esp+28h] [ebp-18h]
  const IVP_Compact_Ledge *rl[2]; // [esp+30h] [ebp-10h]
  IVP_Real_Object *obj0; // [esp+38h] [ebp-8h]
  IVP_Real_Object *obj1; // [esp+3Ch] [ebp-4h]

  l_obj = this->synapse[0].l_obj;
  v4 = this->synapse[1].l_obj;
  v5 = this->IVP_Collision_Delegator::__vftable;
  obj0 = l_obj;
  get_spawned_mindist_count = v5->get_spawned_mindist_count;
  obj1 = v4;
  if ( get_spawned_mindist_count(this: &this->IVP_Collision_Delegator) <= ivp_mindist_settings.max_spawned_mindist_count )
  {
    recursive_status = this->recursive_status;
    sl[1] = nullptr;
    rl[1] = nullptr;
    rl[0] = nullptr;
    v8 = recursive_status;
    v9 = (_DWORD *)((int)this->synapse[-recursive_status + 1].edge & 0xFFFFFFF0);
    recursive_status *= 4;
    *(const IVP_Compact_Ledge **)((char *)&sl[1] - recursive_status) = (const IVP_Compact_Ledge *)&v9[-4 * (*v9 & 0xFFF) - 4];
    n_elems = this->mindists.n_elems;
    v11 = (const IVP_Compact_Ledge *)(((int)this->synapse[v8].edge & 0xFFFFFFF0)
                                    - 16 * ((*(_DWORD *)((int)this->synapse[v8].edge & 0xFFFFFFF0) & 0xFFF) + 1));
    v12 = sl[1];
    *(const IVP_Compact_Ledge **)((char *)rl + recursive_status) = v11;
    IVP_Mindist_Manager::create_exact_mindists(
      pop0: obj0,
      pop1: obj1,
      scan_radius: dist_intra,
      mindists: &this->mindists,
      single_ledge0: nullptr,
      single_ledge1: v12,
      root_ledge0: rl[0],
      root_ledge1: rl[1],
      oo_watcher: &this->IVP_Collision_Delegator);
    this->change_spawned_mindist_count(this: &this->IVP_Collision_Delegator, a2: this->mindists.n_elems - n_elems);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A40F0
// Name: public: void IVP_Mindist_Recursive::rec_hull_limit_exceeded_event(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Recursive::rec_hull_limit_exceeded_event(IVP_Mindist_Recursive *this)
{
  IVP_Mindist_Manager *mindist_manager; // esi
  IVP_Real_Object *l_obj; // edi
  IVP_Environment *environment; // esi
  unsigned int v5; // eax
  float v6; // xmm0_4
  IVP_Time t_now; // [esp+20h] [ebp-24h]
  float v8; // [esp+34h] [ebp-10h]
  IVP_Real_Object *obj1; // [esp+38h] [ebp-Ch]
  float dist1; // [esp+3Ch] [ebp-8h] BYREF
  float dist0; // [esp+40h] [ebp-4h] BYREF

  IVP_Mindist::recalc_invalid_mindist(this);
  if ( (*((_DWORD *)&this->IVP_Mindist_Base + 5) & 0xC000) != 0
    || this->len_numerator <= ivp_mindist_settings.friction_dist )
  {
    l_obj = this->synapse[0].l_obj;
    environment = l_obj->environment;
    obj1 = this->synapse[1].l_obj;
    environment->range_manager->get_coll_range_intra_objects(
      this: environment->range_manager,
      a2: l_obj,
      a3: obj1,
      a4: &dist0,
      a5: &dist1);
    ++environment->statistic_manager.range_intra_exceeded;
    IVP_Mindist_Recursive::recheck_recursive_childs(this, dist_intra: dist0 + dist1);
    *(IVP_Time *)&t_now.seconds = environment->current_time;
    v8 = dist0;
    IVP_U_Min_List::remove_minlist_elem(
      this: &l_obj->hull_manager.sorted_synapses,
      index: this->synapse[0].minlist_index);
    v5 = IVP_U_Min_List::add(
           this: &l_obj->hull_manager.sorted_synapses,
           elem: this->synapse,
           value: (float)((float)((float)(t_now.seconds - l_obj->hull_manager.last_vpsi_time.seconds)
                         * l_obj->hull_manager.gradient)
                 + l_obj->hull_manager.hull_value_last_vpsi)
         + v8);
    v6 = dist1;
    this->synapse[0].minlist_index = v5;
    IVP_U_Min_List::remove_minlist_elem(
      this: &obj1->hull_manager.sorted_synapses,
      index: this->synapse[1].minlist_index);
    this->synapse[1].minlist_index = IVP_U_Min_List::add(
                                       this: &obj1->hull_manager.sorted_synapses,
                                       elem: &this->synapse[1],
                                       value: (float)((float)((float)(t_now.seconds - obj1->hull_manager.last_vpsi_time.seconds)
                                                     * obj1->hull_manager.gradient)
                                             + obj1->hull_manager.hull_value_last_vpsi)
                                     + v6);
  }
  else
  {
    IVP_Mindist_Recursive::delete_all_children(this);
    mindist_manager = this->synapse[0].l_obj->environment->mindist_manager;
    IVP_Mindist_Manager::remove_hull_mindist(this: mindist_manager, del_mindist: this);
    IVP_Mindist_Manager::insert_exact_mindist(this: mindist_manager, new_mindist: this);
    *((_DWORD *)&this->IVP_Mindist_Base + 5) &= 0xFFFFCFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4240
// Name: public: virtual void IVP_Mindist_Recursive::do_impact(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Recursive::do_impact(IVP_Mindist_Recursive *this)
{
  int (__thiscall *get_spawned_mindist_count)(IVP_Collision_Delegator *); // eax
  bool v3; // zf
  const IVP_Compact_Edge *edge; // ecx
  const IVP_Compact_Edge *v5; // eax
  float v6; // xmm0_4
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // edx
  unsigned int v10; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  IVP_Environment *dist1; // [esp+1Ch] [ebp-8h] BYREF
  float dist0; // [esp+20h] [ebp-4h] BYREF

  get_spawned_mindist_count = this->get_spawned_mindist_count;
  dist1 = this->synapse[0].l_obj->environment;
  if ( get_spawned_mindist_count(this: &this->IVP_Collision_Delegator) > ivp_mindist_settings.max_spawned_mindist_count )
  {
do_impact:
    IVP_Mindist::do_impact(this);
  }
  else
  {
    switch ( this->synapse[0].status )
    {
      case 0:
      case 3:
        switch ( this->synapse[1].status )
        {
          case 0:
          case 3:
            goto do_impact;
          case 1:
            v3 = *(int *)this->synapse[1].edge >= 0;
            break;
          case 2:
            v3 = *(_DWORD *)((int)this->synapse[1].edge & 0xFFFFFFF0) >= 0;
            break;
          default:
            _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_recursive.cxx", 50);
            goto LABEL_29;
        }
        if ( v3 )
          goto do_impact;
        this->recursive_status = IVP_MR_SECOND_SYNAPSE_RECURSIVE;
        goto LABEL_29;
      case 1:
        switch ( this->synapse[1].status )
        {
          case 0:
            goto LABEL_23;
          case 1:
            edge = this->synapse[1].edge;
            v5 = this->synapse[0].edge;
            if ( *(_DWORD *)edge < 0 )
            {
              if ( *(_DWORD *)v5 >= 0 )
                goto LABEL_15;
              v6 = 9.9999999e14;
              v7 = ((unsigned int)v5 & 0xFFFFFFF0) - 16 * ((*(_DWORD *)((unsigned int)v5 & 0xFFFFFFF0) & 0xFFF) + 1);
              v8 = ((unsigned int)edge & 0xFFFFFFF0) - 16 * ((*(_DWORD *)((unsigned int)edge & 0xFFFFFFF0) & 0xFFF) + 1);
              v9 = v7 + *(_DWORD *)(v7 + 4);
              v10 = v8 + *(_DWORD *)(v8 + 4);
              if ( v9 != 0 )
                v11 = *(float *)(v9 + 20);
              else
                v11 = 9.9999999e14;
              if ( v10 != 0 )
                v6 = *(float *)(v10 + 20);
              if ( v11 <= v6 )
LABEL_15:
                this->recursive_status = IVP_MR_SECOND_SYNAPSE_RECURSIVE;
              else
                this->recursive_status = IVP_MR_FIRST_SYNAPSE_RECURSIVE;
              goto LABEL_29;
            }
            break;
          case 3:
LABEL_23:
            v5 = (const IVP_Compact_Edge *)((int)this->synapse[0].edge & 0xFFFFFFF0);
            break;
          default:
            _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_recursive.cxx", 93);
            goto LABEL_29;
        }
        if ( *(_DWORD *)v5 >= 0 )
          goto do_impact;
LABEL_25:
        this->recursive_status = IVP_MR_FIRST_SYNAPSE_RECURSIVE;
LABEL_29:
        IVP_Mindist_Manager::remove_exact_mindist(this: dist1->mindist_manager, del_mindist: this);
        dist1->range_manager->get_coll_range_intra_objects(
          this: dist1->range_manager,
          a2: this->synapse[0].l_obj,
          a3: this->synapse[1].l_obj,
          a4: &dist0,
          a5: (float *)&dist1);
        IVP_Mindist_Manager::insert_lazy_hull_mindist(md: this, hull_time: dist0 + *(float *)&dist1);
        v12 = dist0 + *(float *)&dist1;
        *((_DWORD *)&this->IVP_Mindist_Base + 5) = *((_DWORD *)&this->IVP_Mindist_Base + 5) & 0xFFC3FFFF | 0x100000;
        IVP_Mindist_Recursive::recheck_recursive_childs(this, dist_intra: v12);
        break;
      case 2:
        if ( *(int *)((int)this->synapse[0].edge & 0xFFFFFFF0) >= 0 )
          goto do_impact;
        goto LABEL_25;
      default:
        _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_recursive.cxx", 101);
        goto LABEL_29;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4440
// Name: public: virtual void IVP_Mindist_Recursive::exact_mindist_went_invalid(class IVP_Mindist_Manager __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Recursive::exact_mindist_went_invalid(IVP_Mindist_Recursive *this, IVP_Mindist_Manager *mm)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx
  float v5; // xmm0_4
  unsigned int v6; // edx
  unsigned int v7; // eax
  float v8; // xmm1_4
  float v9; // xmm0_4
  float dist1; // [esp+1Ch] [ebp-8h] BYREF
  float dist0; // [esp+20h] [ebp-4h] BYREF

  if ( this->get_spawned_mindist_count(this: &this->IVP_Collision_Delegator) <= ivp_mindist_settings.max_spawned_mindist_count )
  {
    if ( (*(_BYTE *)(((int)this->synapse[0].edge & 0xFFFFFFF0)
                   - 16 * ((*(_DWORD *)((int)this->synapse[0].edge & 0xFFFFFFF0) & 0xFFF) + 1)
                   + 8)
        & 3) == 0 )
      goto LABEL_12;
    if ( (*(_BYTE *)(((int)this->synapse[1].edge & 0xFFFFFFF0)
                   - 16 * ((*(_DWORD *)((int)this->synapse[1].edge & 0xFFFFFFF0) & 0xFFF) + 1)
                   + 8)
        & 3) == 0 )
      goto LABEL_11;
    v5 = 9.9999999e14;
    v3 = ((int)this->synapse[0].edge & 0xFFFFFFF0)
       - 16 * ((*(_DWORD *)((int)this->synapse[0].edge & 0xFFFFFFF0) & 0xFFF) + 1);
    v6 = v3 + *(_DWORD *)(v3 + 4);
    v4 = ((int)this->synapse[1].edge & 0xFFFFFFF0)
       - 16 * ((*(_DWORD *)((int)this->synapse[1].edge & 0xFFFFFFF0) & 0xFFF) + 1);
    v7 = v4 + *(_DWORD *)(v4 + 4);
    v8 = v6 != 0 ? *(float *)(v6 + 20) : 9.9999999e14;
    if ( v7 != 0 )
      v5 = *(float *)(v7 + 20);
    if ( v8 <= v5 )
LABEL_12:
      this->recursive_status = IVP_MR_SECOND_SYNAPSE_RECURSIVE;
    else
LABEL_11:
      this->recursive_status = IVP_MR_FIRST_SYNAPSE_RECURSIVE;
    IVP_Mindist_Manager::remove_exact_mindist(this: mm, del_mindist: this);
    this->synapse[0].l_obj->environment->range_manager->get_coll_range_intra_objects(
      this: this->synapse[0].l_obj->environment->range_manager,
      a2: this->synapse[0].l_obj,
      a3: this->synapse[1].l_obj,
      a4: &dist0,
      a5: &dist1);
    IVP_Mindist_Manager::insert_lazy_hull_mindist(md: this, hull_time: dist0 + dist1);
    v9 = dist0 + dist1;
    *((_DWORD *)&this->IVP_Mindist_Base + 5) = *((_DWORD *)&this->IVP_Mindist_Base + 5) & 0xFFC3FFFF | 0x100000;
    IVP_Mindist_Recursive::recheck_recursive_childs(this, dist_intra: v9);
  }
  else
  {
    IVP_Mindist_Manager::remove_exact_mindist(this: mm, del_mindist: this);
    IVP_Mindist_Manager::insert_invalid_mindist(this: mm, new_mindist: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A45A0
// Name: private: virtual void IVP_Mindist_Recursive::collision_is_going_to_be_deleted_event(class IVP_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Recursive::collision_is_going_to_be_deleted_event(
        IVP_Mindist_Recursive *this,
        IVP_Collision *c)
{
  IVP_U_FVector<IVP_Collision>::remove_allow_resort(this: (IVP_U_FVector<IVP_Collision> *)&this->index, elem: c);
}
