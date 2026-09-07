// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_clustering_longrange.cxx
// Functions: 19
// ============================================================

#include "ivp\ivp_collision\ivp_clustering_longrange.h"

//------------------------------------------------------------------------------
// Address: 0x10095E00
// Name: public: void IVP_OV_Element::add_to_hull_manager(class IVP_Hull_Manager __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Element::add_to_hull_manager(IVP_OV_Element *this, IVP_Hull_Manager *hm, float hull_time)
{
  IVP_Environment *environment; // eax
  IVP_Hull_Manager *hull_manager; // edi
  double seconds; // [esp+10h] [ebp-8h]

  environment = this->real_object->environment;
  hull_manager = this->hull_manager;
  if ( hull_manager != nullptr )
  {
    seconds = environment->current_time.seconds;
    IVP_U_Min_List::remove_minlist_elem(this: &hull_manager->sorted_synapses, index: this->minlist_index);
    this->minlist_index = IVP_U_Min_List::add(
                            this: &hull_manager->sorted_synapses,
                            elem: this,
                            value: (float)((float)((float)(seconds - hull_manager->last_vpsi_time.seconds)
                                          * hull_manager->gradient)
                                  + hull_manager->hull_value_last_vpsi)
                          + hull_time);
  }
  else
  {
    this->hull_manager = hm;
    this->minlist_index = IVP_U_Min_List::add(
                            this: &hm->sorted_synapses,
                            elem: this,
                            value: (float)((float)((float)(environment->current_time.seconds - hm->last_vpsi_time.seconds)
                                          * hm->gradient)
                                  + hm->hull_value_last_vpsi)
                          + hull_time);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095EC0
// Name: protected: virtual void IVP_OV_Element::hull_limit_exceeded_event(class IVP_Hull_Manager __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Element::hull_limit_exceeded_event(IVP_OV_Element *this, IVP_Hull_Manager *hm, float __formal)
{
  IVP_Mindist_Manager::recheck_ov_element(
    this: this->real_object->environment->mindist_manager,
    object: this->real_object);
}

//------------------------------------------------------------------------------
// Address: 0x10095EE0
// Name: private: float IVP_OV_Tree_Manager::calc_optimal_box(class IVP_OV_Element const __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_OV_Tree_Manager::calc_optimal_box(
        IVP_OV_Tree_Manager *this,
        const IVP_OV_Element *element,
        float min_radius,
        float max_radius)
{
  float v4; // xmm7_4
  int v5; // esi
  float *i; // ebx
  __m128 v8; // xmm3
  __m128 v9; // xmm0
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm4
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm3
  __m128 v19; // xmm0
  __m128 v20; // xmm4
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  int v23; // eax
  int v24; // ecx
  __m128 v26; // xmm3
  int v27; // esi
  __m128 v28; // xmm0
  float v29; // xmm5_4
  __m128 v30; // xmm4
  __m128 v31; // xmm2
  __m128 v32; // xmm3
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  __m128 v35; // xmm4
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __m128 v38; // xmm3
  __m128 v39; // xmm0
  __m128 v40; // xmm4
  __m128 v41; // xmm2
  __m128 v42; // xmm3
  int v43; // eax
  int v44; // ecx
  float iraster_dist; // [esp+14h] [ebp-10h]
  int y_min; // [esp+1Ch] [ebp-8h]
  int y_mina; // [esp+1Ch] [ebp-8h]
  int x_min; // [esp+20h] [ebp-4h]
  int x_mina; // [esp+20h] [ebp-4h]

  v4 = min_radius;
  v5 = (unsigned __int8)(COERCE_UNSIGNED_INT(min_radius * 2.0) >> 23) - 126;
  if ( v5 + 40 < 0 )
    v5 = -40;
  for ( i = (float *)((char *)&unk_100FEE5C - 4 * v5); ; --i )
  {
    v8.m128_i32[0] = 1258291200;
    v9 = (__m128)LODWORD(element->center.k[0]);
    v9.m128_f32[0] = (float)(v9.m128_f32[0] - v4) * *i;
    v10 = _mm_and_ps((__m128)0x80000000, v9);
    v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v9, v10), v8).m128_f32[0]) & 0x4B000000
                   | v10.m128_i32[0];
    v11 = v9;
    v11.m128_f32[0] = (float)(v9.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
    v12 = v11;
    v12.m128_f32[0] = v11.m128_f32[0] - v9.m128_f32[0];
    iraster_dist = *i;
    x_min = (int)(float)(v11.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v12, v10).m128_u32[0] & 0x3F800000));
    if ( (int)ceil(X: (float)((float)(element->center.k[0] + v4) * *i)) <= x_min + 2 )
    {
      v13.m128_i32[0] = 1258291200;
      v14 = (__m128)LODWORD(element->center.k[1]);
      v14.m128_f32[0] = (float)(v14.m128_f32[0] - min_radius) * iraster_dist;
      v15 = _mm_and_ps((__m128)0x80000000, v14);
      v13.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v14, v15), v13).m128_f32[0]) & 0x4B000000
                      | v15.m128_i32[0];
      v16 = v14;
      v16.m128_f32[0] = (float)(v14.m128_f32[0] + v13.m128_f32[0]) - v13.m128_f32[0];
      v17 = v16;
      v17.m128_f32[0] = v16.m128_f32[0] - v14.m128_f32[0];
      y_min = (int)(float)(v16.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v15).m128_u32[0] & 0x3F800000));
      if ( (int)ceil(X: (float)((float)(element->center.k[1] + min_radius) * iraster_dist)) <= y_min + 2 )
      {
        v18.m128_i32[0] = 1258291200;
        v19 = (__m128)LODWORD(element->center.k[2]);
        v19.m128_f32[0] = (float)(v19.m128_f32[0] - min_radius) * iraster_dist;
        v20 = _mm_and_ps((__m128)0x80000000, v19);
        v18.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v19, v20), v18).m128_f32[0]) & 0x4B000000
                        | v20.m128_i32[0];
        v21 = v19;
        v21.m128_f32[0] = (float)(v19.m128_f32[0] + v18.m128_f32[0]) - v18.m128_f32[0];
        v22 = v21;
        v22.m128_f32[0] = v21.m128_f32[0] - v19.m128_f32[0];
        v23 = (int)ceil(X: (float)((float)(element->center.k[2] + min_radius) * iraster_dist));
        v24 = (int)(float)(v21.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v22, v20).m128_u32[0] & 0x3F800000));
        if ( v23 <= v24 + 2 )
          break;
      }
    }
    v4 = min_radius;
    ++v5;
  }
  this->search_node.data.x = x_min;
  this->search_node.data.y = y_min;
  this->search_node.data.z = v24;
  this->search_node.data.rasterlevel = v5 - 1;
  this->search_node.data.sizelevel = v5;
  if ( min_radius >= max_radius )
    return min_radius;
  v26.m128_i32[0] = 1258291200;
  v27 = v5 + 1;
  v28 = (__m128)LODWORD(element->center.k[0]);
  v29 = *(float *)&dword_100FEE58[-v27 + 1];
  v28.m128_f32[0] = (float)(v28.m128_f32[0] - max_radius) * v29;
  v30 = _mm_and_ps((__m128)0x80000000, v28);
  v26.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v28, v30), v26).m128_f32[0]) & 0x4B000000
                  | v30.m128_i32[0];
  v31 = v28;
  v31.m128_f32[0] = (float)(v28.m128_f32[0] + v26.m128_f32[0]) - v26.m128_f32[0];
  v32 = v31;
  v32.m128_f32[0] = v31.m128_f32[0] - v28.m128_f32[0];
  x_mina = (int)(float)(v31.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v32, v30).m128_u32[0] & 0x3F800000));
  if ( (int)ceil(X: (float)((float)(element->center.k[0] + max_radius) * v29)) > x_mina + 2 )
    return min_radius;
  v33.m128_i32[0] = 1258291200;
  v34 = (__m128)LODWORD(element->center.k[1]);
  v34.m128_f32[0] = (float)(v34.m128_f32[0] - max_radius) * v29;
  v35 = _mm_and_ps((__m128)0x80000000, v34);
  v33.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v34, v35), v33).m128_f32[0]) & 0x4B000000
                  | v35.m128_i32[0];
  v36 = v34;
  v36.m128_f32[0] = (float)(v34.m128_f32[0] + v33.m128_f32[0]) - v33.m128_f32[0];
  v37 = v36;
  v37.m128_f32[0] = v36.m128_f32[0] - v34.m128_f32[0];
  y_mina = (int)(float)(v36.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v37, v35).m128_u32[0] & 0x3F800000));
  if ( (int)ceil(X: (float)((float)(element->center.k[1] + max_radius) * v29)) > y_mina + 2 )
    return min_radius;
  v38.m128_i32[0] = 1258291200;
  v39 = (__m128)LODWORD(element->center.k[2]);
  v39.m128_f32[0] = (float)(v39.m128_f32[0] - max_radius) * v29;
  v40 = _mm_and_ps((__m128)0x80000000, v39);
  v38.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v39, v40), v38).m128_f32[0]) & 0x4B000000
                  | v40.m128_i32[0];
  v41 = v39;
  v41.m128_f32[0] = (float)(v39.m128_f32[0] + v38.m128_f32[0]) - v38.m128_f32[0];
  v42 = v41;
  v42.m128_f32[0] = v41.m128_f32[0] - v39.m128_f32[0];
  v43 = (int)ceil(X: (float)((float)(element->center.k[2] + max_radius) * v29));
  v44 = (int)(float)(v41.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v42, v40).m128_u32[0] & 0x3F800000));
  if ( v43 > v44 + 2 )
    return min_radius;
  this->search_node.data.rasterlevel = v27 - 1;
  this->search_node.data.sizelevel = v27;
  this->search_node.data.x = x_mina;
  this->search_node.data.y = y_mina;
  this->search_node.data.z = v44;
  return max_radius;
}

//------------------------------------------------------------------------------
// Address: 0x10096350
// Name: private: void IVP_OV_Tree_Manager::get_luf_coordinates_ws(class IVP_OV_Node const __near *,class IVP_U_Float_Point __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Tree_Manager::get_luf_coordinates_ws(
        IVP_OV_Tree_Manager *this,
        const IVP_OV_Node *node,
        IVP_U_Float_Point *p,
        float *cubesize)
{
  p->k[0] = (float)node->data.x * *(float *)&dword_100FEE58[node->data.rasterlevel];
  p->k[1] = (float)node->data.y * *(float *)&dword_100FEE58[node->data.rasterlevel];
  p->k[2] = (float)node->data.z * *(float *)&dword_100FEE58[node->data.rasterlevel];
  *cubesize = *(float *)&dword_100FEE58[node->data.sizelevel];
}

//------------------------------------------------------------------------------
// Address: 0x100963C0
// Name: private: class IVP_OV_Node __near * IVP_OV_Tree_Manager::find_smallest_box(class IVP_OV_Node const __near *,class IVP_OV_Node const __near *)const
// Source: json
//------------------------------------------------------------------------------
IVP_OV_Node *__thiscall IVP_OV_Tree_Manager::find_smallest_box(
        IVP_OV_Tree_Manager *this,
        const IVP_OV_Node *master_node,
        const IVP_OV_Node *sub_node)
{
  const IVP_OV_Node *v3; // ebx
  int v4; // ecx
  __int64 j; // rax
  const IVP_OV_Node *v6; // edi
  int v7; // esi
  int i; // [esp+18h] [ebp-8h]
  int v10; // [esp+1Ch] [ebp-4h]

  v3 = sub_node;
LABEL_2:
  v4 = master_node->data.rasterlevel - sub_node->data.rasterlevel - 1;
  for ( j = (unsigned int)master_node; ; HIDWORD(j) = i + 1 )
  {
    i = HIDWORD(j);
    if ( SHIDWORD(j) >= master_node->children.n_elems )
      break;
    v6 = *(const IVP_OV_Node **)(*(_DWORD *)(j + 28) + 4 * HIDWORD(j));
    v7 = v6->data.x << v4;
    v10 = v6->data.z << v4;
    HIDWORD(j) = (2 << v4) - 2;
    if ( v3->data.x >= v7 )
    {
      if ( v3->data.y < v6->data.y << v4 || (LODWORD(j) = sub_node->data.z, (int)j < v10) )
      {
        v3 = sub_node;
      }
      else
      {
        v3 = sub_node;
        if ( sub_node->data.x <= HIDWORD(j) + v7
          && sub_node->data.y <= HIDWORD(j) + (v6->data.y << v4)
          && (int)j <= v10 + HIDWORD(j) )
        {
          master_node = v6;
          goto LABEL_2;
        }
      }
    }
    LODWORD(j) = master_node;
  }
  return (IVP_OV_Node *)j;
}

//------------------------------------------------------------------------------
// Address: 0x10096460
// Name: public: IVP_OV_Element::IVP_OV_Element(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_OV_Element *__thiscall IVP_OV_Element::IVP_OV_Element(IVP_OV_Element *this, IVP_Real_Object *obj)
{
  this->__vftable = (IVP_OV_Element_vtbl *)&IVP_OV_Element::`vftable';
  *(_DWORD *)&this->collision_fvector.memsize = 16;
  this->collision_fvector.elems = (void **)p_malloc(size: 0x40u);
  this->node = nullptr;
  this->center.k[2] = 0.0;
  this->center.k[1] = 0.0;
  this->center.k[0] = 0.0;
  this->hull_manager = nullptr;
  this->radius = -1.0;
  this->real_object = obj;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100964C0
// Name: public: void IVP_OV_Element::add_oo_collision(class IVP_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Element::add_oo_collision(IVP_OV_Element *this, IVP_Collision *connector)
{
  IVP_U_FVector<IVP_Collision> *p_collision_fvector; // esi
  int n_elems; // ecx

  p_collision_fvector = &this->collision_fvector;
  if ( this->collision_fvector.n_elems >= this->collision_fvector.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->collision_fvector);
  p_collision_fvector->elems[p_collision_fvector->n_elems] = connector;
  n_elems = p_collision_fvector->n_elems;
  if ( connector->fvector_index[0] == -1 )
    connector->fvector_index[0] = n_elems;
  else
    connector->fvector_index[1] = n_elems;
  ++p_collision_fvector->n_elems;
}

//------------------------------------------------------------------------------
// Address: 0x10096510
// Name: private: IVP_OV_Node::~IVP_OV_Node(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Node::~IVP_OV_Node(IVP_OV_Node *this)
{
  IVP_OV_Node *parent; // eax
  IVP_OV_Node **elems; // eax
  IVP_OV_Node *v4; // edi
  void **v5; // eax
  void **v6; // eax

  parent = this->parent;
  if ( parent != nullptr )
    IVP_U_Vector<IVP_OV_Element>::remove(
      this: (IVP_U_Vector<IVP_Listener_Object> *)&parent->children,
      elem: (IVP_Listener_Object *)this);
  while ( this->children.n_elems != 0 )
  {
    elems = (IVP_OV_Node **)this->children.elems;
    v4 = *elems;
    if ( *elems != nullptr )
    {
      IVP_OV_Node::~IVP_OV_Node(this: *elems);
      free(data: v4);
    }
  }
  v5 = this->elements.elems;
  if ( v5 != (void **)(this + 1) )
  {
    if ( v5 != nullptr )
      free(data: this->elements.elems);
    this->elements.elems = nullptr;
    this->elements.memsize = 0;
  }
  this->elements.n_elems = 0;
  v6 = this->children.elems;
  if ( v6 == (void **)&this->elements )
  {
    this->children.n_elems = 0;
  }
  else
  {
    if ( v6 != nullptr )
      free(data: this->children.elems);
    this->children.elems = nullptr;
    *(_DWORD *)&this->children.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100965B0
// Name: public: IVP_OV_Tree_Manager::IVP_OV_Tree_Manager(void)
// Source: json
//------------------------------------------------------------------------------
IVP_OV_Tree_Manager *__thiscall IVP_OV_Tree_Manager::IVP_OV_Tree_Manager(IVP_OV_Tree_Manager *this)
{
  IVP_VHash *v2; // eax
  IVP_ov_tree_hash *v3; // edi
  float v4; // xmm0_4
  float *v5; // ecx
  float v6; // xmm1_4
  float *v7; // eax

  this->search_node.children.elems = nullptr;
  *(_DWORD *)&this->search_node.children.memsize = 0;
  *(_DWORD *)&this->search_node.elements.memsize = 0;
  this->search_node.elements.elems = nullptr;
  this->search_node.parent = nullptr;
  this->environment = nullptr;
  this->root = nullptr;
  v2 = (IVP_VHash *)p_malloc(size: 0x10u);
  v3 = (IVP_ov_tree_hash *)v2;
  if ( v2 != nullptr )
  {
    IVP_VHash::IVP_VHash(this: v2, size_i: 256);
    v3->__vftable = (IVP_ov_tree_hash_vtbl *)&IVP_ov_tree_hash::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v4 = 1.0;
  v5 = (float *)dword_100FEE58;
  this->hash_table = v3;
  v6 = 1.0;
  v7 = (float *)dword_100FEE58;
  do
  {
    *v5 = v4;
    *v7-- = v6;
    ++v5;
    v4 = v4 * 2.0;
    v6 = v6 * 0.5;
  }
  while ( (int)v7 >= (int)IVP_OV_Tree_Manager::powerlist );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10096650
// Name: public: IVP_OV_Tree_Manager::~IVP_OV_Tree_Manager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Tree_Manager::~IVP_OV_Tree_Manager(IVP_OV_Tree_Manager *this)
{
  IVP_ov_tree_hash *hash_table; // ecx

  hash_table = this->hash_table;
  if ( hash_table != nullptr )
    ((void (__thiscall *)(IVP_ov_tree_hash *, int))hash_table->dtr_IVP_VHash)(a1: hash_table, a2: 1);
  this->hash_table = nullptr;
  IVP_OV_Node::~IVP_OV_Node(this: &this->search_node);
}

//------------------------------------------------------------------------------
// Address: 0x10096680
// Name: private: void IVP_OV_Tree_Manager::connect_boxes(class IVP_OV_Node __near *,class IVP_OV_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Tree_Manager::connect_boxes(IVP_OV_Tree_Manager *this, IVP_OV_Node *node, IVP_OV_Node *new_node)
{
  IVP_OV_Node *v3; // ebx
  IVP_OV_Node *v4; // edi
  int v5; // esi
  IVP_OV_Node *v6; // eax
  IVP_OV_Node *v7; // edi
  int x; // eax
  int v9; // eax
  int y; // eax
  int v11; // edx
  int z; // eax
  int v13; // eax
  IVP_ov_tree_hash *hash_table; // esi
  unsigned int v15; // eax
  int nodea; // [esp+1Ch] [ebp+8h]
  int nodeb; // [esp+1Ch] [ebp+8h]

  v3 = node;
  v4 = new_node;
  v5 = node->data.sizelevel - new_node->data.sizelevel;
  if ( v5 != 1 )
  {
    while ( 1 )
    {
      v6 = (IVP_OV_Node *)p_malloc(size: 0x28u);
      v7 = nullptr;
      if ( v6 != nullptr )
      {
        v6->children.elems = nullptr;
        *(_DWORD *)&v6->children.memsize = 0;
        v6->elements.elems = nullptr;
        *(_DWORD *)&v6->elements.memsize = 0;
        v6->parent = nullptr;
        v7 = v6;
      }
      x = v3->data.x;
      if ( new_node->data.x >= (v3->data.x + 1) << v5 )
        break;
      v9 = 2 * x;
      if ( new_node->data.x < (v9 + 1) << (v5 - 1) )
        goto LABEL_6;
      v7->data.x = v9 + 1;
LABEL_7:
      y = v3->data.y;
      v11 = new_node->data.y;
      if ( v11 < (y + 1) << v5 )
      {
        nodea = 2 * y + 1;
        if ( v11 < nodea << (v5 - 1) )
          v7->data.y = 2 * y;
        else
          v7->data.y = nodea;
      }
      else
      {
        v7->data.y = 2 * y + 2;
      }
      z = v3->data.z;
      nodeb = new_node->data.z;
      if ( nodeb < (z + 1) << v5 )
      {
        v13 = 2 * z;
        if ( nodeb >= (v13 + 1) << (v5 - 1) )
        {
          v7->data.z = v13 + 1;
          goto LABEL_17;
        }
      }
      else
      {
        v13 = 2 * z + 2;
      }
      v7->data.z = v13;
LABEL_17:
      v7->data.rasterlevel = v3->data.rasterlevel - 1;
      v7->data.sizelevel = v3->data.sizelevel - 1;
      v7->parent = v3;
      if ( v3->children.n_elems >= v3->children.memsize )
        IVP_U_Vector_Base::increment_mem(this: &v3->children);
      v3->children.elems[v3->children.n_elems++] = v7;
      hash_table = this->hash_table;
      v15 = IVP_ov_tree_hash::node_to_index(this: hash_table, node: v7);
      IVP_VHash::add_elem(this: hash_table, elem: v7, hash_index: v15);
      if ( v3->children.n_elems > 0x1Bu )
        printf(format: "*** ERROR *** Excessive amount of children: %d\n", v3->children.n_elems);
      v5 = v7->data.sizelevel - new_node->data.sizelevel;
      v3 = v7;
      if ( v5 == 1 )
      {
        v4 = new_node;
        goto LABEL_23;
      }
    }
    v9 = 2 * x + 2;
LABEL_6:
    v7->data.x = v9;
    goto LABEL_7;
  }
LABEL_23:
  v4->parent = v3;
  if ( v3->children.n_elems >= v3->children.memsize )
    IVP_U_Vector_Base::increment_mem(this: &v3->children);
  v3->children.elems[v3->children.n_elems++] = v4;
  if ( v3->children.n_elems > 0x1Bu )
    printf(format: "*** ERROR *** Excessive amount of children: %d\n", v3->children.n_elems);
}

//------------------------------------------------------------------------------
// Address: 0x10096840
// Name: private: void IVP_OV_Tree_Manager::expand_tree(class IVP_OV_Node const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Tree_Manager::expand_tree(IVP_OV_Tree_Manager *this, const IVP_OV_Node *new_node)
{
  int sizelevel; // eax
  IVP_OV_Node *root; // edi
  IVP_OV_Node *v5; // eax
  IVP_OV_Node *v6; // esi
  int v7; // ecx
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  int y; // ecx
  int z; // ecx
  IVP_ov_tree_hash *hash_table; // edi
  unsigned int v16; // eax

  sizelevel = this->root->data.sizelevel;
  if ( sizelevel > 40 )
    printf(format: "*** ERROR *** Excessive sizelevel (%d) for element\n", sizelevel);
  root = this->root;
  v5 = (IVP_OV_Node *)p_malloc(size: 0x28u);
  v6 = nullptr;
  if ( v5 != nullptr )
  {
    v5->children.elems = nullptr;
    *(_DWORD *)&v5->children.memsize = 0;
    v5->elements.elems = nullptr;
    *(_DWORD *)&v5->elements.memsize = 0;
    v5->parent = nullptr;
    v6 = v5;
  }
  v7 = root->data.x % 2;
  v8 = root->data.y % 2;
  v9 = root->data.z % 2;
  v6->data.x = root->data.x / 2;
  v6->data.y = root->data.y / 2;
  v6->data.z = root->data.z / 2;
  v10 = root->data.rasterlevel + 1;
  v6->data.rasterlevel = v10;
  v6->data.sizelevel = root->data.sizelevel + 1;
  v11 = *(float *)&dword_100FEE58[v10];
  v12 = *(float *)&dword_100FEE58[new_node->data.rasterlevel];
  if ( v7 == -1 )
  {
    --v6->data.x;
  }
  else if ( v7 == 0 && (float)((float)v6->data.x * v11) > (float)((float)new_node->data.x * v12) )
  {
    --v6->data.x;
  }
  if ( v8 == -1 )
  {
    --v6->data.y;
  }
  else if ( v8 == 0 )
  {
    y = v6->data.y;
    if ( (float)((float)y * v11) > (float)((float)new_node->data.y * v12) )
      v6->data.y = y - 1;
  }
  if ( v9 == -1 )
  {
    --v6->data.z;
  }
  else if ( v9 == 0 )
  {
    z = v6->data.z;
    if ( (float)((float)z * v11) > (float)((float)new_node->data.z * v12) )
      v6->data.z = z - 1;
  }
  if ( v6->children.n_elems >= 0x1Bu )
    printf(format: "*** ERROR *** : Mehr als 27 Kinder *********************************\n");
  if ( v6->children.n_elems >= v6->children.memsize )
    IVP_U_Vector_Base::increment_mem(this: &v6->children);
  v6->children.elems[v6->children.n_elems++] = root;
  root->parent = v6;
  hash_table = this->hash_table;
  v16 = IVP_ov_tree_hash::node_to_index(this: hash_table, node: v6);
  IVP_VHash::add_elem(this: hash_table, elem: v6, hash_index: v16);
  this->root = v6;
}

//------------------------------------------------------------------------------
// Address: 0x100969F0
// Name: private: void IVP_OV_Tree_Manager::collect_subbox_collision_partners(class IVP_OV_Element const __near *,class IVP_OV_Node const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Tree_Manager::collect_subbox_collision_partners(
        IVP_OV_Tree_Manager *this,
        const IVP_OV_Element *elem,
        const IVP_OV_Node *node)
{
  const IVP_OV_Node *v3; // edi
  int v4; // eax
  float *v5; // esi
  IVP_U_Vector<IVP_OV_Element> *collision_partners; // edi
  int v7; // esi
  int i; // [esp+10h] [ebp-4h]

  v3 = node;
  v4 = node->elements.n_elems - 1;
  i = v4;
  if ( node->elements.n_elems != 0 )
  {
    do
    {
      v5 = (float *)v3->elements.elems[v4];
      if ( (float)((float)((float)((float)(v5[5] - elem->center.k[1]) * (float)(v5[5] - elem->center.k[1]))
                         + (float)((float)(v5[4] - elem->center.k[0]) * (float)(v5[4] - elem->center.k[0])))
                 + (float)((float)(v5[6] - elem->center.k[2]) * (float)(v5[6] - elem->center.k[2]))) <= (float)((float)(v5[8] + elem->radius) * (float)(v5[8] + elem->radius)) )
      {
        collision_partners = this->collision_partners;
        if ( collision_partners->n_elems >= collision_partners->memsize )
        {
          IVP_U_Vector_Base::increment_mem(this: this->collision_partners);
          v4 = i;
        }
        collision_partners->elems[collision_partners->n_elems++] = v5;
        v3 = node;
      }
      i = --v4;
    }
    while ( v4 >= 0 );
  }
  v7 = v3->children.n_elems - 1;
  if ( v3->children.n_elems != 0 )
  {
    do
      IVP_OV_Tree_Manager::collect_subbox_collision_partners(
        this,
        elem,
        node: (const IVP_OV_Node *)v3->children.elems[v7--]);
    while ( v7 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096AB0
// Name: private: void IVP_OV_Tree_Manager::collect_collision_partners(class IVP_OV_Element const __near *,class IVP_OV_Node const __near *,class IVP_OV_Node const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Tree_Manager::collect_collision_partners(
        IVP_OV_Tree_Manager *this,
        const IVP_OV_Element *elem,
        const IVP_OV_Node *masternode,
        const IVP_OV_Node *new_node)
{
  const IVP_OV_Node *v4; // edx
  int v5; // ebx
  float *v6; // esi
  const IVP_OV_Element *v7; // ecx
  IVP_U_Vector<IVP_OV_Element> *collision_partners; // edi
  int v10; // eax
  int v11; // edi
  const IVP_OV_Node *v12; // eax
  int v13; // eax
  int v14; // edi
  const IVP_OV_Node *v15; // eax
  int i; // [esp+20h] [ebp+10h]
  int ia; // [esp+20h] [ebp+10h]

  v4 = masternode;
  v5 = masternode->elements.n_elems - 1;
  if ( masternode->elements.n_elems != 0 )
  {
    do
    {
      v6 = (float *)v4->elements.elems[v5];
      v7 = elem;
      if ( (float)((float)((float)((float)(v6[5] - elem->center.k[1]) * (float)(v6[5] - elem->center.k[1]))
                         + (float)((float)(v6[4] - elem->center.k[0]) * (float)(v6[4] - elem->center.k[0])))
                 + (float)((float)(v6[6] - elem->center.k[2]) * (float)(v6[6] - elem->center.k[2]))) <= (float)((float)(v6[8] + elem->radius) * (float)(v6[8] + elem->radius)) )
      {
        collision_partners = this->collision_partners;
        if ( collision_partners->n_elems >= collision_partners->memsize )
        {
          IVP_U_Vector_Base::increment_mem(this: this->collision_partners);
          v4 = masternode;
        }
        collision_partners->elems[collision_partners->n_elems++] = v6;
        v7 = elem;
      }
      --v5;
    }
    while ( v5 >= 0 );
  }
  else
  {
    v7 = elem;
  }
  if ( v4->data.sizelevel - 1 <= new_node->data.sizelevel )
  {
    v13 = 0;
    v14 = new_node->data.rasterlevel - v4->data.rasterlevel + 1;
    ia = 0;
    if ( v4->children.n_elems == 0 )
      return;
    while ( 1 )
    {
      v15 = (const IVP_OV_Node *)v4->children.elems[v13];
      if ( v15 == new_node )
        break;
      if ( v15->data.x + 2 > new_node->data.x << v14 && v15->data.y + 2 > new_node->data.y << v14 )
      {
        if ( v15->data.z + 2 > new_node->data.z << v14
          && v15->data.x < (new_node->data.x + 2) << v14
          && v15->data.y < (new_node->data.y + 2) << v14
          && v15->data.z < (new_node->data.z + 2) << v14 )
        {
          IVP_OV_Tree_Manager::collect_collision_partners(this, elem, masternode: v15, new_node);
        }
        goto LABEL_37;
      }
LABEL_38:
      v13 = ia + 1;
      ia = v13;
      if ( v13 >= v4->children.n_elems )
        return;
      v7 = elem;
    }
    IVP_OV_Tree_Manager::collect_subbox_collision_partners(this, elem: v7, node: v15);
LABEL_37:
    v4 = masternode;
    goto LABEL_38;
  }
  v10 = 0;
  v11 = v4->data.rasterlevel - new_node->data.rasterlevel - 1;
  i = 0;
  if ( v4->children.n_elems != 0 )
  {
    while ( 1 )
    {
      v12 = (const IVP_OV_Node *)v4->children.elems[v10];
      if ( v12 == new_node )
        break;
      if ( new_node->data.x + 2 > v12->data.x << v11
        && new_node->data.y + 2 > v12->data.y << v11
        && new_node->data.z + 2 > v12->data.z << v11
        && new_node->data.x < (v12->data.x + 2) << v11
        && new_node->data.y < (v12->data.y + 2) << v11
        && new_node->data.z < (v12->data.z + 2) << v11 )
      {
        IVP_OV_Tree_Manager::collect_collision_partners(this, elem, masternode: v12, new_node);
        goto LABEL_22;
      }
LABEL_23:
      v10 = i + 1;
      i = v10;
      if ( v10 >= v4->children.n_elems )
        return;
      v7 = elem;
    }
    IVP_OV_Tree_Manager::collect_subbox_collision_partners(this, elem: v7, node: v12);
LABEL_22:
    v4 = masternode;
    goto LABEL_23;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096CD0
// Name: public: float IVP_OV_Tree_Manager::insert_ov_element(class IVP_OV_Element __near *,float,float,class IVP_U_Vector<class IVP_OV_Element> __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_OV_Tree_Manager::insert_ov_element(
        IVP_OV_Tree_Manager *this,
        IVP_OV_Element *element,
        float min_radius,
        float max_radius,
        IVP_U_Vector<IVP_OV_Element> *colliding_balls)
{
  IVP_ov_tree_hash *hash_table; // esi
  unsigned int v8; // eax
  IVP_U_Vector_Base *elem; // eax
  IVP_OV_Node *v10; // esi
  IVP_OV_Node *v11; // eax
  IVP_ov_tree_hash *v12; // ebx
  unsigned int v13; // eax
  IVP_OV_Node *root; // eax
  int rasterlevel; // ecx
  int v16; // edx
  char v17; // cl
  int v18; // edx
  int v19; // edi
  int v20; // eax
  IVP_OV_Node *v21; // eax
  IVP_U_Vector_Base *p_elements; // edi
  IVP_ov_tree_hash *v23; // edi
  unsigned int v24; // eax
  IVP_OV_Node *smallest_box; // eax
  float used_radius; // [esp+20h] [ebp+Ch]
  int max_radiusa; // [esp+24h] [ebp+10h]

  if ( element == nullptr )
    return 0.0;
  used_radius = IVP_OV_Tree_Manager::calc_optimal_box(this, element, min_radius, max_radius);
  element->radius = used_radius;
  hash_table = this->hash_table;
  v8 = IVP_ov_tree_hash::node_to_index(this: hash_table, node: &this->search_node);
  elem = (IVP_U_Vector_Base *)IVP_VHash::find_elem(this: hash_table, elem: this, hash_index: v8);
  v10 = (IVP_OV_Node *)elem;
  if ( elem != nullptr )
  {
    if ( elem[4].n_elems >= elem[4].memsize )
      IVP_U_Vector_Base::increment_mem(this: elem + 4);
    v10->elements.elems[v10->elements.n_elems++] = element;
    element->node = v10;
  }
  else
  {
    v11 = (IVP_OV_Node *)p_malloc(size: 0x28u);
    if ( v11 != nullptr )
    {
      *(_DWORD *)&v11->children.memsize = 0;
      v11->children.elems = nullptr;
      *(_DWORD *)&v11->elements.memsize = 0;
      v11->elements.elems = nullptr;
      v11->parent = nullptr;
      v10 = v11;
    }
    else
    {
      v10 = nullptr;
    }
    v10->data.x = this->search_node.data.x;
    v10->data.y = this->search_node.data.y;
    v10->data.z = this->search_node.data.z;
    v10->data.rasterlevel = this->search_node.data.rasterlevel;
    v10->data.sizelevel = this->search_node.data.sizelevel;
    if ( v10->elements.n_elems >= v10->elements.memsize )
      IVP_U_Vector_Base::increment_mem(this: &v10->elements);
    v10->elements.elems[v10->elements.n_elems++] = element;
    element->node = v10;
    if ( this->root == nullptr )
    {
      this->root = v10;
      v12 = this->hash_table;
      v13 = IVP_ov_tree_hash::node_to_index(this: v12, node: v10);
      IVP_VHash::add_elem(this: v12, elem: v10, hash_index: v13);
      return used_radius;
    }
    while ( 1 )
    {
      root = this->root;
      rasterlevel = root->data.rasterlevel;
      v16 = v10->data.rasterlevel;
      if ( rasterlevel >= v16 )
      {
        v17 = rasterlevel - v16;
        v18 = root->data.x << v17;
        v19 = root->data.y << v17;
        max_radiusa = root->data.z << v17;
        v20 = (2 << v17) - 2;
        if ( v10->data.x >= v18
          && v10->data.y >= v19
          && v10->data.z >= max_radiusa
          && v10->data.x <= v20 + v18
          && v10->data.y <= v20 + v19
          && v10->data.z <= max_radiusa + v20 )
        {
          break;
        }
      }
      IVP_OV_Tree_Manager::expand_tree(this, new_node: v10);
    }
    v21 = this->root;
    if ( v21->data.rasterlevel == v10->data.rasterlevel )
    {
      p_elements = &v21->elements;
      if ( v21->elements.n_elems >= v21->elements.memsize )
        IVP_U_Vector_Base::increment_mem(this: p_elements);
      p_elements->elems[p_elements->n_elems++] = element;
      element->node = this->root;
      IVP_OV_Node::~IVP_OV_Node(this: v10);
      free(data: v10);
      v10 = this->root;
    }
    else
    {
      v23 = this->hash_table;
      v24 = IVP_ov_tree_hash::node_to_index(this: v23, node: v10);
      IVP_VHash::add_elem(this: v23, elem: v10, hash_index: v24);
      smallest_box = IVP_OV_Tree_Manager::find_smallest_box(this, master_node: this->root, sub_node: v10);
      IVP_OV_Tree_Manager::connect_boxes(this, node: smallest_box, new_node: v10);
    }
  }
  this->collision_partners = colliding_balls;
  if ( colliding_balls != nullptr )
    IVP_OV_Tree_Manager::collect_collision_partners(this, elem: element, masternode: this->root, new_node: v10);
  return used_radius;
}

//------------------------------------------------------------------------------
// Address: 0x10096EE0
// Name: public: void IVP_OV_Tree_Manager::remove_ov_element(class IVP_OV_Element __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Tree_Manager::remove_ov_element(IVP_OV_Tree_Manager *this, IVP_Listener_Object *element)
{
  IVP_OV_Node *v2; // esi
  IVP_ov_tree_hash *hash_table; // edi
  int v5; // eax
  IVP_OV_Node *parent; // edi

  v2 = (IVP_OV_Node *)element[2].__vftable;
  if ( v2 != nullptr )
  {
    element[2].__vftable = nullptr;
    IVP_U_Vector<IVP_OV_Element>::remove(this: (IVP_U_Vector<IVP_Listener_Object> *)&v2->elements, elem: element);
    do
    {
      if ( v2->elements.n_elems != 0 || v2->children.n_elems != 0 )
        break;
      if ( v2->parent == nullptr )
        this->root = nullptr;
      hash_table = this->hash_table;
      v5 = IVP_ov_tree_hash::node_to_index(this: hash_table, node: v2);
      IVP_VHash::remove_elem(this: hash_table, elem: v2, hash_index: v5);
      parent = v2->parent;
      IVP_OV_Node::~IVP_OV_Node(this: v2);
      free(data: v2);
      v2 = parent;
    }
    while ( parent != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096F60
// Name: public: void IVP_U_FVector<class IVP_Collision>::remove_allow_resort(class IVP_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_FVector<IVP_Collision>::remove_allow_resort(
        IVP_U_FVector<IVP_Collision> *this,
        IVP_Collision *elem)
{
  int v2; // edx
  int v3; // eax
  void **elems; // esi
  _DWORD *v5; // eax

  v2 = elem->fvector_index[0];
  if ( v2 < 0 || v2 >= this->n_elems || this->elems[v2] != elem )
    v2 = elem->fvector_index[1];
  v3 = --this->n_elems;
  if ( v3 > v2 )
  {
    elems = this->elems;
    v5 = elems[v3];
    elems[v2] = v5;
    if ( v5[3] == this->n_elems )
      v5[3] = v2;
    else
      v5[4] = v2;
  }
  if ( elem->fvector_index[0] == v2 )
    elem->fvector_index[0] = -1;
  else
    elem->fvector_index[1] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10096FD0
// Name: public: virtual IVP_OV_Element::~IVP_OV_Element(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Element::~IVP_OV_Element(IVP_OV_Element *this)
{
  IVP_Hull_Manager *hull_manager; // eax
  IVP_OV_Element *elems; // eax

  hull_manager = this->hull_manager;
  this->__vftable = (IVP_OV_Element_vtbl *)&IVP_OV_Element::`vftable';
  if ( hull_manager != nullptr )
  {
    IVP_U_Min_List::remove_minlist_elem(this: &hull_manager->sorted_synapses, index: this->minlist_index);
    this->hull_manager = nullptr;
  }
  IVP_Environment::fire_object_is_removed_from_collision_detection(
    this: this->real_object->environment,
    obj: this->real_object);
  IVP_OV_Tree_Manager::remove_ov_element(
    this: this->real_object->environment->ov_tree_manager,
    element: (IVP_Listener_Object *)this);
  elems = (IVP_OV_Element *)this->collision_fvector.elems;
  if ( elems == this + 1 )
  {
    this->collision_fvector.n_elems = 0;
  }
  else
  {
    if ( elems != nullptr )
    {
      free(data: this->collision_fvector.elems);
      this->collision_fvector.elems = nullptr;
    }
    *(_DWORD *)&this->collision_fvector.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097040
// Name: public: void IVP_OV_Element::remove_oo_collision(class IVP_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_OV_Element::remove_oo_collision(IVP_OV_Element *this, IVP_Collision *connector)
{
  IVP_U_FVector<IVP_Collision>::remove_allow_resort(this: &this->collision_fvector, elem: connector);
}
