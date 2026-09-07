// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_mindist_minimize.cxx
// Functions: 31
// ============================================================

#include "ivp\ivp_collision\ivp_mindist_minimize.h"

//------------------------------------------------------------------------------
// Address: 0x10091090
// Name: protected: void IVP_Mindist_Minimize_Solver::sort_synapses(class IVP_Synapse __near *,class IVP_Synapse __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist_Minimize_Solver::sort_synapses(
        IVP_Mindist_Minimize_Solver *this,
        IVP_Synapse *a,
        IVP_Synapse *__formal)
{
  IVP_Mindist *mindist; // ecx

  mindist = this->mindist;
  if ( a != &mindist->synapse[(*((_DWORD *)&mindist->IVP_Mindist_Base + 5) >> 8) & 3] )
    *((_DWORD *)&mindist->IVP_Mindist_Base + 5) ^= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x100910C0
// Name: protected: enum IVP_BOOL IVP_Mindist_Minimize_Solver::check_loop_hash(enum IVP_SYNAPSE_POLYGON_STATUS,class IVP_Compact_Edge const __near *,enum IVP_SYNAPSE_POLYGON_STATUS,class IVP_Compact_Edge const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Mindist_Minimize_Solver::check_loop_hash(
        IVP_Mindist_Minimize_Solver *this,
        IVP_SYNAPSE_POLYGON_STATUS i_s0,
        const IVP_Compact_Edge *i_e0,
        IVP_SYNAPSE_POLYGON_STATUS i_s1,
        const IVP_Compact_Edge *i_e1)
{
  unsigned __int32 v5; // edx
  unsigned __int32 v6; // esi
  int loop_hash_size; // ebx
  int v8; // edi
  float *v9; // eax

  v5 = (unsigned int)i_e0 | i_s0;
  v6 = (unsigned int)i_e1 | i_s1;
  if ( (int)((unsigned int)i_e0 | i_s0) < (int)((unsigned int)i_e1 | i_s1) )
  {
    v5 = (unsigned int)i_e1 | i_s1;
    v6 = (unsigned int)i_e0 | i_s0;
  }
  loop_hash_size = this->loop_hash_size;
  v8 = loop_hash_size - 1;
  v9 = &this->pos_opposite_BacksideOs.k[2 * loop_hash_size + 2];
  if ( loop_hash_size - 1 < 0 )
  {
LABEL_7:
    if ( loop_hash_size < 256 )
    {
      this->loop_hash[loop_hash_size].a = v5;
      this->loop_hash[this->loop_hash_size++].b = v6;
      return 0;
    }
  }
  else
  {
    while ( *(_DWORD *)v9 != v5 || *((_DWORD *)v9 + 1) != v6 )
    {
      v9 -= 2;
      if ( --v8 < 0 )
        goto LABEL_7;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091130
// Name: protected: virtual void IVP_Mindist::mindist_rescue_push(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mindist::mindist_rescue_push(IVP_Mindist *this)
{
  IVP_Real_Object *l_obj; // edi
  IVP_Anomaly_Manager *anomaly_manager; // ebx
  float v4; // [esp+8h] [ebp-18h]
  IVP_Anomaly_Manager_vtbl *v5; // [esp+18h] [ebp-8h]
  IVP_Real_Object *obj1; // [esp+1Ch] [ebp-4h]

  l_obj = this->synapse[0].l_obj;
  anomaly_manager = l_obj->environment->anomaly_manager;
  v5 = anomaly_manager->__vftable;
  obj1 = this->synapse[1].l_obj;
  v4 = anomaly_manager->get_push_speed_penetration(this: anomaly_manager, a2: l_obj, a3: obj1);
  ((void (__thiscall *)(IVP_Anomaly_Manager *, IVP_Mindist *, IVP_Real_Object *, IVP_Real_Object *, _DWORD))v5->inter_penetration)(
    a1: anomaly_manager,
    a2: this,
    a3: l_obj,
    a4: obj1,
    a5: LODWORD(v4));
}

//------------------------------------------------------------------------------
// Address: 0x10091180
// Name: protected: static enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::minimize_B_POLY(class IVP_Mindist_Minimize_Solver __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __cdecl IVP_Mindist_Minimize_Solver::minimize_B_POLY(IVP_Mindist_Minimize_Solver *mms)
{
  IVP_Real_Object *l_obj; // esi
  IVP_Synapse *synapse; // edi
  IVP_Cache_Object *cache_object; // ecx
  IVP_Cache_Object *v4; // ecx
  IVP_Mindist *mindist; // esi
  const IVP_Compact_Edge *edge; // edx
  IVP_Real_Object *v7; // edi
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v8; // esi
  const IVP_Compact_Ledge *v9; // ebx
  bool v10; // zf
  IVP_Cache_Object *v11; // eax
  IVP_Cache_Object *v12; // ecx
  IVP_MRC_TYPE v13; // esi
  IVP_MRC_TYPE v14; // eax
  IVP_Cache_Ledge_Point m_cache_P; // [esp+Ch] [ebp-24h] BYREF
  IVP_Cache_Ball m_cache_B; // [esp+20h] [ebp-10h] BYREF
  const IVP_Compact_Edge *P; // [esp+2Ch] [ebp-4h]

  l_obj = mms->mindist->synapse[0].l_obj;
  synapse = mms->mindist->synapse;
  m_cache_B.object = (IVP_Ball *)l_obj;
  if ( l_obj->cache_object == nullptr )
    l_obj->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                            this: l_obj->environment->cache_object_manager,
                            object: l_obj);
  ++l_obj->cache_object->reference_count;
  if ( *(_BYTE *)&l_obj->flags < 8 )
  {
    cache_object = l_obj->cache_object;
    if ( l_obj->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  v4 = l_obj->cache_object;
  mindist = mms->mindist;
  m_cache_B.cache_object = v4;
  m_cache_B.tmp.synapse = (IVP_Synapse_Real *)synapse;
  edge = mindist->synapse[1].edge;
  v7 = mindist->synapse[1].l_obj;
  v8.synapse = (IVP_Synapse_Real *)&mindist->synapse[1];
  v9 = (const IVP_Compact_Ledge *)(((unsigned int)edge & 0xFFFFFFF0)
                                 - 16 * ((*(_DWORD *)((unsigned int)edge & 0xFFFFFFF0) & 0xFFF) + 1));
  m_cache_P.compact_ledge = v9;
  v10 = v7->cache_object == nullptr;
  P = edge;
  if ( v10 )
  {
    v11 = IVP_Cache_Object_Manager::get_cache_object(this: v7->environment->cache_object_manager, object: v7);
    edge = P;
    v7->cache_object = v11;
  }
  ++v7->cache_object->reference_count;
  if ( *(_BYTE *)&v7->flags < 8 )
  {
    v12 = v7->cache_object;
    if ( v7->environment->current_time_code > v12->valid_until_time_code )
    {
      IVP_Cache_Object::update_cache_object(this: v12);
      edge = P;
    }
  }
  m_cache_P.clp_cache_object = v7->cache_object;
  m_cache_P.clp_object = v7;
  m_cache_P.compact_poly_points = (const IVP_Compact_Poly_Point *)((char *)v9 + v9->c_point_offset);
  m_cache_P.tmp = v8;
  switch ( v8.synapse->status )
  {
    case 0:
      v14 = IVP_Mindist_Minimize_Solver::p_minimize_BP(this: mms, m_cache_ball: &m_cache_B, P: edge, &m_cache_P);
      goto LABEL_18;
    case 1:
      v14 = IVP_Mindist_Minimize_Solver::p_minimize_BK(this: mms, &m_cache_B, K: edge, m_cache_K: &m_cache_P);
      goto LABEL_18;
    case 2:
      v14 = IVP_Mindist_Minimize_Solver::p_minimize_BF(this: mms, &m_cache_B, F: edge, m_cache_F: &m_cache_P);
LABEL_18:
      v13 = v14;
      goto LABEL_19;
    default:
      break;
  }
  v13 = IVP_MRC_UNINITIALIZED;
  _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_minimize.cxx", 707);
LABEL_19:
  --m_cache_P.clp_cache_object->reference_count;
  --m_cache_B.cache_object->reference_count;
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x100912D0
// Name: protected: static enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::minimize_KB(class IVP_Mindist_Minimize_Solver __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __cdecl IVP_Mindist_Minimize_Solver::minimize_KB(IVP_Mindist_Minimize_Solver *mms)
{
  _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_minimize.cxx", 717);
  *((_DWORD *)&mms->mindist->IVP_Mindist_Base + 5) ^= 0x100u;
  return IVP_Mindist_Minimize_Solver::minimize_B_POLY(mms);
}

//------------------------------------------------------------------------------
// Address: 0x10091310
// Name: protected: static enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::minimize_FB(class IVP_Mindist_Minimize_Solver __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __cdecl IVP_Mindist_Minimize_Solver::minimize_FB(IVP_Mindist_Minimize_Solver *mms)
{
  _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_minimize.cxx", 723);
  *((_DWORD *)&mms->mindist->IVP_Mindist_Base + 5) ^= 0x100u;
  return IVP_Mindist_Minimize_Solver::minimize_B_POLY(mms);
}

//------------------------------------------------------------------------------
// Address: 0x10091350
// Name: protected: static enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::minimize_BB(class IVP_Mindist_Minimize_Solver __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IVP_Mindist_Minimize_Solver::minimize_BB(IVP_Mindist_Minimize_Solver *mms)
{
  IVP_Real_Object *l_obj; // esi
  IVP_Cache_Object *cache_object; // ecx
  IVP_Real_Object *v3; // edi
  IVP_Cache_Object *v4; // esi
  IVP_Cache_Object *v5; // ecx
  IVP_Cache_Object *v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm2_4
  IVP_Mindist *mindist; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  IVP_Mindist *v12; // eax

  l_obj = mms->mindist->synapse[0].l_obj;
  if ( l_obj->cache_object == nullptr )
    l_obj->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                            this: l_obj->environment->cache_object_manager,
                            object: mms->mindist->synapse[0].l_obj);
  ++l_obj->cache_object->reference_count;
  if ( *(_BYTE *)&l_obj->flags < 8 )
  {
    cache_object = l_obj->cache_object;
    if ( l_obj->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  v3 = mms->mindist->synapse[1].l_obj;
  v4 = l_obj->cache_object;
  if ( v3->cache_object == nullptr )
    v3->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                         this: v3->environment->cache_object_manager,
                         object: v3);
  ++v3->cache_object->reference_count;
  if ( *(_BYTE *)&v3->flags < 8 )
  {
    v5 = v3->cache_object;
    if ( v3->environment->current_time_code > v5->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: v5);
  }
  v6 = v3->cache_object;
  v7 = v4->m_world_f_object.vv.k[1] - v6->m_world_f_object.vv.k[1];
  v8 = v4->m_world_f_object.vv.k[0] - v6->m_world_f_object.vv.k[0];
  mindist = mms->mindist;
  mindist->contact_plane.k[2] = v4->m_world_f_object.vv.k[2] - v6->m_world_f_object.vv.k[2];
  mindist->contact_plane.k[1] = v7;
  mindist->contact_plane.k[0] = v8;
  v10 = (float)((float)(v8 * v8) + (float)(v7 * v7))
      + (float)(mindist->contact_plane.k[2] * mindist->contact_plane.k[2]);
  v11 = 1.0;
  if ( COERCE_FLOAT(LODWORD(v10) & _mask__AbsFloat_) > 1.0e-10 )
    v11 = 1.0 / fsqrt(v10);
  mindist->len_numerator = (float)(v11 * v10) - mindist->sum_extra_radius;
  v12 = mms->mindist;
  v12->contact_plane.k[0] = mms->mindist->contact_plane.k[0] * v11;
  v12->contact_plane.k[1] = v12->contact_plane.k[1] * v11;
  v12->contact_plane.k[2] = v12->contact_plane.k[2] * v11;
  v12->contact_dot_diff_center = (float)((float)(v12->contact_plane.k[1] * (float)(v4->core_pos.k[1] - v6->core_pos.k[1]))
                                       + (float)((float)(v4->core_pos.k[0] - v6->core_pos.k[0]) * v12->contact_plane.k[0]))
                               + (float)(v12->contact_plane.k[2] * (float)(v4->core_pos.k[2] - v6->core_pos.k[2]));
  --v4->reference_count;
  --v6->reference_count;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100914E0
// Name: public: static class IVP_Compact_Edge const __near * IVP_Compact_Ledge_Solver::minimize_on_other_side(class IVP_Compact_Edge const __near *,class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
const IVP_Compact_Edge *__cdecl IVP_Compact_Ledge_Solver::minimize_on_other_side(
        const IVP_Compact_Ledge *edge,
        const IVP_U_Point *partner_os)
{
  unsigned int v3; // ebx
  void *v4; // esp
  int v5; // esi
  _DWORD *v6; // eax
  int i; // ecx
  unsigned __int8 v9[12]; // [esp+0h] [ebp-1Ch] BYREF
  IVP_Unscaled_QR_Result qr; // [esp+Ch] [ebp-10h] BYREF
  const IVP_Compact_Ledge *c_ledge; // [esp+24h] [ebp+8h]

  v3 = *(__int16 *)(((unsigned int)edge & 0xFFFFFFF0)
                  - 16 * ((*(_DWORD *)((unsigned int)edge & 0xFFFFFFF0) & 0xFFF) + 1)
                  + 0xC);
  c_ledge = (const IVP_Compact_Ledge *)(((unsigned int)edge & 0xFFFFFFF0)
                                      - 16 * ((*(_DWORD *)((unsigned int)edge & 0xFFFFFFF0) & 0xFFF) + 1));
  v4 = alloca(v3);
  memset(dst: v9, value: 0, count: v3);
  v5 = (int)&c_ledge[((*(_DWORD *)((unsigned int)edge & 0xFFFFFFF0) >> 12) & 0xFFF) + 1].___u1;
LABEL_2:
  v9[*(_DWORD *)(v5 & 0xFFFFFFF0) & 0xFFF] = 1;
  IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(c_ledge, tri: v5, p_object: partner_os, result: &qr);
  v6 = (_DWORD *)v5;
  for ( i = 0; i < 3; ++i )
  {
    if ( qr.checks[i] <= 0.0 && v9[*(_DWORD *)((unsigned int)&v6[(2 * *v6) >> 17] & 0xFFFFFFF0) & 0xFFF] == 0 )
    {
      v5 = (int)&v6[(2 * *v6) >> 17];
      goto LABEL_2;
    }
    v6 = (_DWORD *)((char *)v6 + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v6 & 0xC)));
  }
  return (const IVP_Compact_Edge *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x100915B0
// Name: protected: static enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::minimize_illegal(class IVP_Mindist_Minimize_Solver __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IVP_Mindist_Minimize_Solver::minimize_illegal()
{
  _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_minimize.cxx", 828);
  return 5;
}

//------------------------------------------------------------------------------
// Address: 0x100915D0
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x100915E0
// Name: public: enum IVP_MRC_TYPE IVP_Mindist::recalc_invalid_mindist(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall IVP_Mindist::recalc_invalid_mindist@<eax>(IVP_Mindist *this@<ecx>, int a2@<ebp>)
{
  IVP_Mindist *v2; // esi
  int current_time_code; // eax
  IVP_Mindist *v5; // edx
  IVP_MRC_TYPE v6; // eax
  IVP_MRC_TYPE v7; // edi
  __int32 v8; // eax
  int v9; // ecx
  int v10; // esi
  int v11; // eax
  _DWORD v12[3]; // [esp-Ch] [ebp-84Ch] BYREF
  IVP_Mindist_Minimize_Solver mms; // [esp+0h] [ebp-840h] BYREF
  IVP_Mindist *v14; // [esp+830h] [ebp-10h]
  int v15; // [esp+834h] [ebp-Ch]
  int pierce_counter; // [esp+838h] [ebp-8h]
  int retaddr; // [esp+840h] [ebp+0h]

  v15 = a2;
  pierce_counter = retaddr;
  v2 = this;
  current_time_code = this->synapse[0].l_obj->environment->current_time_code;
  v14 = this;
  if ( this->recalc_time_stamp == current_time_code )
    return 4;
  this->recalc_time_stamp = current_time_code;
  v5 = this;
  v12[0] = this;
  mms.loop_hash[254].b = 0;
  v12[1] = 0;
  *(&mms.loop_hash_size + 3) = 0;
  while ( 1 )
  {
    _mm_prefetch((const char *)v5->synapse[0].edge, 2);
    _mm_prefetch((const char *)v5->synapse[1].edge, 2);
    v6 = IVP_Mindist_Minimize_Solver::mms_function_table[v5->synapse[(*((_DWORD *)&v5->IVP_Mindist_Base + 5) >> 8) & 3].status][v5->synapse[((*((_DWORD *)&v5->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3].status](a1: (IVP_Mindist_Minimize_Solver *)v12);
    v7 = v6;
    if ( v6 == IVP_MRC_OK )
    {
      *((_DWORD *)&v2->IVP_Mindist_Base + 5) &= 0xFFFF3FFF;
      return 1;
    }
    v8 = v6 - 2;
    *((_DWORD *)&v2->IVP_Mindist_Base + 5) = *((_DWORD *)&v2->IVP_Mindist_Base + 5) & 0xFFFF3FFF | 0x4000;
    if ( v8 == 0 )
      break;
    if ( v8 == 1 )
    {
      v9 = (*(_DWORD *)(v12[0] + 20) >> 8) & 3;
      v10 = v12[0] + 28 * v9 + 24;
      if ( *(_WORD *)(v12[0] + 28 * v9 + 50) != 5 )
        v10 = v12[0] + 28 * (((*(_DWORD *)(v12[0] + 20) ^ 0x100u) >> 8) & 3) + 24;
      *(_DWORD *)(v10 + 20) = IVP_Compact_Ledge_Solver::minimize_on_other_side(
                                edge: *(const IVP_Compact_Ledge **)(v10 + 20),
                                partner_os: (const IVP_U_Point *)&mms.P_Finish_Counter);
      *(_WORD *)(v10 + 26) = 2;
      v2 = v14;
      if ( ++*(&mms.loop_hash_size + 3) >= 2 )
        break;
      v5 = (IVP_Mindist *)v12[0];
    }
    else
    {
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_minimize.cxx", 235);
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_minimize.cxx", 238);
      v5 = (IVP_Mindist *)v12[0];
    }
  }
  v11 = *((_DWORD *)&v2->IVP_Mindist_Base + 5);
  if ( (v11 & 0x3000) != 0x1000 && (v11 & 0x3C0000) != 0x100000 )
    v2->mindist_rescue_push(this: v2);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100917C0
// Name: public: enum IVP_MRC_TYPE IVP_Mindist::recalc_mindist(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall IVP_Mindist::recalc_mindist@<eax>(IVP_Mindist *this@<ecx>, int a2@<ebp>)
{
  IVP_Mindist *v2; // esi
  int current_time_code; // eax
  IVP_Mindist *v5; // edx
  IVP_MRC_TYPE v6; // eax
  IVP_MRC_TYPE v7; // edi
  __int32 v8; // eax
  int v9; // ecx
  int v10; // esi
  int v11; // eax
  _DWORD v12[3]; // [esp-Ch] [ebp-84Ch] BYREF
  IVP_Mindist_Minimize_Solver mms; // [esp+0h] [ebp-840h] BYREF
  IVP_Mindist *v14; // [esp+830h] [ebp-10h]
  int v15; // [esp+834h] [ebp-Ch]
  int pierce_counter; // [esp+838h] [ebp-8h]
  int retaddr; // [esp+840h] [ebp+0h]

  v15 = a2;
  pierce_counter = retaddr;
  v2 = this;
  current_time_code = this->synapse[0].l_obj->environment->current_time_code;
  v14 = this;
  if ( this->recalc_time_stamp == current_time_code )
    return 4;
  this->recalc_time_stamp = current_time_code;
  v5 = this;
  v12[0] = this;
  mms.loop_hash[254].b = 0;
  v12[1] = 20;
  *(&mms.loop_hash_size + 3) = 0;
  while ( 1 )
  {
    _mm_prefetch((const char *)v5->synapse[0].edge, 2);
    _mm_prefetch((const char *)v5->synapse[1].edge, 2);
    v6 = IVP_Mindist_Minimize_Solver::mms_function_table[v5->synapse[(*((_DWORD *)&v5->IVP_Mindist_Base + 5) >> 8) & 3].status][v5->synapse[((*((_DWORD *)&v5->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3].status](a1: (IVP_Mindist_Minimize_Solver *)v12);
    v7 = v6;
    if ( v6 == IVP_MRC_OK )
    {
      *((_DWORD *)&v2->IVP_Mindist_Base + 5) &= 0xFFFF3FFF;
      return 1;
    }
    v8 = v6 - 2;
    *((_DWORD *)&v2->IVP_Mindist_Base + 5) = *((_DWORD *)&v2->IVP_Mindist_Base + 5) & 0xFFFF3FFF | 0x4000;
    if ( v8 == 0 )
      break;
    if ( v8 == 1 )
    {
      v9 = (*(_DWORD *)(v12[0] + 20) >> 8) & 3;
      v10 = v12[0] + 28 * v9 + 24;
      if ( *(_WORD *)(v12[0] + 28 * v9 + 50) != 5 )
        v10 = v12[0] + 28 * (((*(_DWORD *)(v12[0] + 20) ^ 0x100u) >> 8) & 3) + 24;
      *(_DWORD *)(v10 + 20) = IVP_Compact_Ledge_Solver::minimize_on_other_side(
                                edge: *(const IVP_Compact_Ledge **)(v10 + 20),
                                partner_os: (const IVP_U_Point *)&mms.P_Finish_Counter);
      *(_WORD *)(v10 + 26) = 2;
      v2 = v14;
      if ( ++*(&mms.loop_hash_size + 3) >= 2 )
        break;
      v5 = (IVP_Mindist *)v12[0];
    }
    else
    {
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_minimize.cxx", 310);
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_minimize.cxx", 313);
      v5 = (IVP_Mindist *)v12[0];
    }
  }
  v11 = *((_DWORD *)&v2->IVP_Mindist_Base + 5);
  if ( (v11 & 0x3000) != 0x1000 && (v11 & 0x3C0000) != 0x100000 )
    v2->mindist_rescue_push(this: v2);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100919A0
// Name: protected: static enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::minimize_PB(class IVP_Mindist_Minimize_Solver __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_MRC_TYPE __cdecl IVP_Mindist_Minimize_Solver::minimize_PB(IVP_Mindist_Minimize_Solver *mms)
{
  _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_minimize.cxx", 669);
  *((_DWORD *)&mms->mindist->IVP_Mindist_Base + 5) ^= 0x100u;
  return IVP_Mindist_Minimize_Solver::minimize_B_POLY(mms);
}

//------------------------------------------------------------------------------
// Address: 0x100919E0
// Name: public: char const __near * CFmtStrN<256>::sprintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *CFmtStrN<256>::sprintf(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  bool v3; // zf
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  this->InitQuietTruncation(this);
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v2->m_szBuf, maxLen: 255, pFormat: pszFormat, params, pbTruncated: (bool *)&this + 3);
  v3 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v3 && !v2->m_bQuietTruncation && `CFmtStrN<256>::sprintf'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::sprintf'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: v2->m_szBuf);
  return v2->m_szBuf;
}

//------------------------------------------------------------------------------
// Address: 0x10091A50
// Name: protected: enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::p_minimize_FF(class IVP_Compact_Edge const __near *,class IVP_Compact_Edge const __near *,class IVP_Cache_Ledge_Point __near *,class IVP_Cache_Ledge_Point __near *)
// Source: json
//------------------------------------------------------------------------------
const IVP_Compact_Edge *__userpurge IVP_Mindist_Minimize_Solver::p_minimize_FF@<eax>(
        IVP_Mindist_Minimize_Solver *this@<ecx>,
        IVP_Cache_Ledge_Point *a2@<ebp>,
        IVP_Cache_Ledge_Point *A,
        const IVP_Compact_Edge *B,
        IVP_Cache_Ledge_Point *m_cache_A,
        IVP_Cache_Ledge_Point *m_cache_B)
{
  IVP_Cache_Ledge_Point *v6; // edi
  const IVP_Compact_Edge *v7; // esi
  float v8; // xmm0_4
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v9; // eax
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v10; // eax
  int v11; // esi
  IVP_Cache_Ledge_Point *v12; // edi
  const IVP_Compact_Ledge *compact_ledge; // edx
  const IVP_Compact_Edge *v14; // esi
  float v15; // xmm0_4
  float v16; // xmm0_4
  IVP_Compact_Edge v17; // eax
  IVP_Compact_Edge *v18; // edx
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v19; // eax
  const IVP_Compact_Edge *v20; // eax
  const IVP_Compact_Edge *v21; // ecx
  const IVP_Compact_Edge *v22; // edx
  IVP_Cache_Ledge_Point *v23; // edi
  IVP_Cache_Ledge_Point *v24; // eax
  const IVP_Compact_Edge *v25; // esi
  double v26; // st7
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v27; // eax
  IVP_Compact_Edge *v28; // edx
  float v29; // xmm0_4
  int v30; // ecx
  IVP_Compact_Edge v31; // eax
  const IVP_Compact_Edge *v32; // eax
  bool v33; // zf
  IVP_Cache_Ledge_Point *v34; // edi
  const IVP_Compact_Edge *v35; // esi
  double v36; // st7
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v37; // eax
  float v38; // xmm0_4
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v39; // eax
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v40; // esi
  IVP_Cache_Ledge_Point::<unnamed_type_tmp> v41; // edx
  const IVP_Compact_Edge *edge; // ecx
  int status; // edi
  const IVP_Compact_Edge *result; // eax
  IVP_Real_Object *l_obj; // edx
  void (*v46)(const char *, ...); // esi
  IVP_Real_Object *v47; // edx
  IVP_Real_Object *v48; // edx
  IVP_Real_Object *v49; // edx
  _BYTE v50[12]; // [esp+28h] [ebp-32Ch] BYREF
  IVP_KK_Input kkin; // [esp+34h] [ebp-320h] BYREF
  CFmtStrN<256> obj0; // [esp+A4h] [ebp-2B0h] BYREF
  CFmtStrN<256> obj1; // [esp+1B4h] [ebp-1A0h] BYREF
  int v54; // [esp+2C0h] [ebp-94h]
  _DWORD v55[2]; // [esp+2D4h] [ebp-80h]
  const IVP_Compact_Edge *v56; // [esp+2DCh] [ebp-78h]
  IVP_Cache_Ledge_Point *cc_A[2]; // [esp+2E0h] [ebp-74h]
  IVP_Cache_Ledge_Point *v58; // [esp+2E8h] [ebp-6Ch]
  const IVP_Compact_Edge *tabB[2]; // [esp+2ECh] [ebp-68h]
  const IVP_Compact_Edge *tabA[2]; // [esp+2F4h] [ebp-60h] BYREF
  IVP_Cache_Ledge_Point *cc_B[2]; // [esp+2FCh] [ebp-58h] BYREF
  IVP_Unscaled_S_Result sr; // [esp+304h] [ebp-50h] BYREF
  float v63; // [esp+30Ch] [ebp-48h]
  float v64; // [esp+310h] [ebp-44h]
  IVP_Unscaled_KK_Result kkr; // [esp+314h] [ebp-40h]
  IVP_Mindist_Minimize_Solver *v66; // [esp+324h] [ebp-30h]
  int synapse; // [esp+328h] [ebp-2Ch]
  int i; // [esp+32Ch] [ebp-28h]
  int v69; // [esp+330h] [ebp-24h]
  IVP_Compact_Edge *qdist; // [esp+334h] [ebp-20h]
  float v71; // [esp+338h] [ebp-1Ch]
  int distanceCase; // [esp+33Ch] [ebp-18h]
  const IVP_Compact_Edge *pB; // [esp+340h] [ebp-14h]
  int min_qdist; // [esp+344h] [ebp-10h]
  IVP_Cache_Ledge_Point *m_cache_0; // [esp+348h] [ebp-Ch] BYREF
  const IVP_Compact_Edge *e1; // [esp+34Ch] [ebp-8h]
  const IVP_Compact_Edge *retaddr; // [esp+354h] [ebp+0h]

  m_cache_0 = a2;
  e1 = retaddr;
  v6 = A;
  v66 = this;
  v71 = 1.0e20;
  v69 = -1;
  for ( min_qdist = 3; min_qdist != 0; --min_qdist )
  {
    v7 = B;
    for ( pB = (const IVP_Compact_Edge *)3; pB != nullptr; pB = (const IVP_Compact_Edge *)((char *)pB - 1) )
    {
      IVP_Compact_Ledge_Solver::give_world_coords_AT(edge: v7, clp: m_cache_B, p_ws_out: (IVP_U_Point *)&tabA[1]);
      IVP_Compact_Ledge_Solver::give_world_coords_AT(
        edge: (const IVP_Compact_Edge *)v6,
        clp: m_cache_A,
        p_ws_out: (IVP_U_Point *)&sr.checks[1]);
      v8 = (float)((float)((float)(v63 - *(float *)cc_B) * (float)(v63 - *(float *)cc_B))
                 + (float)((float)(sr.checks[1] - *(float *)&tabA[1]) * (float)(sr.checks[1] - *(float *)&tabA[1])))
         + (float)((float)(v64 - *(float *)&cc_B[1]) * (float)(v64 - *(float *)&cc_B[1]));
      if ( v71 > v8 )
      {
        v9.synapse = (IVP_Synapse_Real *)m_cache_A->tmp;
        v9.synapse->edge = (const IVP_Compact_Edge *)v6;
        v9.synapse->status = 0;
        v10.synapse = (IVP_Synapse_Real *)m_cache_B->tmp;
        v10.synapse->edge = v7;
        v10.synapse->status = 0;
        v71 = v8;
        v69 = 0;
      }
      v7 = (const IVP_Compact_Edge *)((char *)v7
                                    + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v7 & 0xC)));
    }
    v6 = (IVP_Cache_Ledge_Point *)((char *)v6
                                 + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v6 & 0xC)));
  }
  v55[0] = m_cache_A;
  v55[1] = m_cache_B;
  tabB[1] = (const IVP_Compact_Edge *)m_cache_B;
  tabA[0] = (const IVP_Compact_Edge *)m_cache_A;
  v11 = 0;
  v58 = A;
  tabB[0] = B;
  cc_A[0] = (IVP_Cache_Ledge_Point *)B;
  cc_A[1] = A;
  for ( min_qdist = 0; ; v11 = min_qdist )
  {
    v12 = *(IVP_Cache_Ledge_Point **)((char *)&tabB[1] + v11);
    compact_ledge = v12->compact_ledge;
    qdist = *(IVP_Compact_Edge **)((char *)cc_A + v11);
    IVP_Compact_Ledge_Solver::calc_hesse_object(
      edge: qdist,
      ledge: compact_ledge,
      hesse_out_os: (IVP_U_Hesse *)&sr.checks[1]);
    v14 = *(const IVP_Compact_Edge **)((char *)&tabB[-1] + v11);
    pB = *(const IVP_Compact_Edge **)((char *)v55 + min_qdist);
    for ( distanceCase = 3; distanceCase != 0; --distanceCase )
    {
      IVP_Compact_Ledge_Solver::calc_pos_other_space(
        P: v14,
        m_cache_P: (IVP_Cache_Ledge_Point *)pB,
        m_cache_other_space: v12,
        res: (IVP_U_Point *)&tabA[1]);
      IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
        c_ledge: v12->compact_ledge,
        tri: (int)qdist,
        p_object: (const IVP_U_Point *)&tabA[1],
        result: (IVP_Unscaled_QR_Result *)&obj1.m_szBuf[255]);
      if ( (*(_DWORD *)&obj1.m_szBuf[255] | obj1.m_nLength | v54) >= 0 )
      {
        v15 = (float)((float)((float)(*(float *)cc_B * v63) + (float)(*(float *)&tabA[1] * sr.checks[1]))
                    + (float)(*(float *)&cc_B[1] * v64))
            + kkr.checks_K[0];
        v16 = v15 * v15;
        if ( v71 > (float)(v16 * 1.000001) )
        {
          v17 = pB[4];
          v18 = qdist;
          *(_WORD *)(*(_DWORD *)&v17 + 26) = 0;
          *(_DWORD *)(*(_DWORD *)&v17 + 20) = v14;
          v19.synapse = (IVP_Synapse_Real *)v12->tmp;
          v19.synapse->edge = v18;
          v19.synapse->status = 2;
          v71 = v16;
          v69 = 1;
        }
      }
      v14 = (const IVP_Compact_Edge *)((char *)v14
                                     + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v14 & 0xC)));
    }
    min_qdist += 4;
    if ( min_qdist >= 8 )
      break;
  }
  v20 = nullptr;
  for ( pB = nullptr; ; v20 = pB )
  {
    v21 = *(const IVP_Compact_Edge **)((char *)cc_A + (_DWORD)v20);
    v22 = *(const IVP_Compact_Edge **)((char *)&tabB[-1] + (_DWORD)v20);
    v23 = *(IVP_Cache_Ledge_Point **)((char *)v55 + (_DWORD)v20);
    v24 = *(IVP_Cache_Ledge_Point **)((char *)&tabB[1] + (_DWORD)v20);
    min_qdist = (int)v21;
    v56 = v22;
    qdist = (IVP_Compact_Edge *)v24;
    i = 3;
    do
    {
      IVP_Compact_Ledge_Solver::calc_pos_other_space(
        P: (const IVP_Compact_Edge *)min_qdist,
        m_cache_P: (IVP_Cache_Ledge_Point *)qdist,
        m_cache_other_space: v23,
        res: (IVP_U_Point *)&obj1.m_szBuf[255]);
      v25 = v56;
      for ( distanceCase = 3; distanceCase != 0; --distanceCase )
      {
        IVP_Compact_Ledge_Solver::calc_unscaled_s_val_K_space(
          c_ledge: v23->compact_ledge,
          edge: v25,
          p_object: (const IVP_U_Point *)&obj1.m_szBuf[255],
          result: (IVP_Unscaled_S_Result *)&cc_B[1]);
        if ( ((int)cc_B[1] | LODWORD(sr.checks[0])) >= 0 )
        {
          v26 = IVP_Compact_Ledge_Solver::quad_dist_edge_to_point_K_space(
                  ledge_K: v23->compact_ledge,
                  K: v25,
                  object_pos: (const IVP_U_Point *)&obj1.m_szBuf[255]);
          *(float *)&synapse = v26;
          if ( v71 > v26 * 1.000001 )
          {
            v27.synapse = (IVP_Synapse_Real *)v23->tmp;
            v28 = qdist;
            v29 = *(float *)&synapse;
            v27.synapse->status = 1;
            v30 = min_qdist;
            v27.synapse->edge = v25;
            v31 = v28[4];
            *(_DWORD *)(*(_DWORD *)&v31 + 20) = v30;
            *(_WORD *)(*(_DWORD *)&v31 + 26) = 0;
            v71 = v29;
            v69 = 2;
          }
        }
        v25 = (const IVP_Compact_Edge *)((char *)v25
                                       + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v25 & 0xC)));
      }
      v32 = (const IVP_Compact_Edge *)(*(int *)((char *)IVP_Compact_Edge::next_table + (min_qdist & 0xC)) + min_qdist);
      v33 = i-- == 1;
      min_qdist = (int)v32;
    }
    while ( !v33 );
    if ( (int)++pB >= 8 )
      break;
  }
  v34 = A;
  for ( pB = (const IVP_Compact_Edge *)3; pB != nullptr; pB = (const IVP_Compact_Edge *)((char *)pB - 1) )
  {
    v35 = B;
    for ( i = 3; i != 0; --i )
    {
      IVP_KK_Input::IVP_KK_Input(
        this: (IVP_KK_Input *)v50,
        K_in: (const IVP_Compact_Edge *)v34,
        L_in: v35,
        m_cache_K: m_cache_A,
        m_cache_L: m_cache_B);
      IVP_Compact_Ledge_Solver::calc_unscaled_KK_vals(
        a1: (int)&m_cache_0,
        in: (const IVP_KK_Input *)v50,
        result: (IVP_Unscaled_KK_Result *)&sr.checks[1]);
      if ( (LODWORD(sr.checks[1]) | LODWORD(v63)) >= 0 && (LODWORD(v64) | LODWORD(kkr.checks_K[0])) >= 0 )
      {
        v36 = IVP_KK_Input::calc_quad_distance_edge_edge(this: (IVP_KK_Input *)v50);
        *(float *)&synapse = v36;
        if ( v71 > v36 * 1.000001 )
        {
          v37.synapse = (IVP_Synapse_Real *)m_cache_A->tmp;
          v38 = *(float *)&synapse;
          v37.synapse->edge = (const IVP_Compact_Edge *)v34;
          v37.synapse->status = 1;
          v39.synapse = (IVP_Synapse_Real *)m_cache_B->tmp;
          v39.synapse->edge = v35;
          v39.synapse->status = 1;
          v71 = v38;
          v69 = 3;
        }
      }
      v35 = (const IVP_Compact_Edge *)((char *)v35
                                     + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v35 & 0xC)));
    }
    v34 = (IVP_Cache_Ledge_Point *)((char *)v34
                                  + *(int *)((char *)IVP_Compact_Edge::next_table + ((unsigned __int8)v34 & 0xC)));
  }
  v40.synapse = (IVP_Synapse_Real *)m_cache_B->tmp;
  v41.synapse = (IVP_Synapse_Real *)m_cache_A->tmp;
  distanceCase = (int)m_cache_A;
  qdist = (IVP_Compact_Edge *)m_cache_B;
  if ( v40.synapse->status == 0 && v41.synapse->status != 0 )
  {
    synapse = (int)v41.synapse;
    v41.synapse = v40.synapse;
    v40.synapse = (IVP_Synapse_Real *)synapse;
    distanceCase = (int)m_cache_B;
    qdist = (IVP_Compact_Edge *)m_cache_A;
  }
  i = (int)v66->mindist;
  if ( *(_DWORD *)(distanceCase + 16) != i + 28 * ((*(_DWORD *)(i + 20) >> 8) & 3) + 24 )
    *(_DWORD *)(i + 20) ^= 0x100u;
  edge = v41.synapse->edge;
  pB = v40.synapse->edge;
  status = v41.synapse->status;
  min_qdist = 0;
  switch ( status )
  {
    case 0:
      if ( v40.synapse->status != 0 )
      {
        if ( v40.synapse->status == 1 )
        {
          result = (const IVP_Compact_Edge *)IVP_Mindist_Minimize_Solver::p_minimize_PK(
                                               this: v66,
                                               P: edge,
                                               K: pB,
                                               m_cache_P: (IVP_Cache_Ledge_Point *)distanceCase,
                                               m_cache_K: (IVP_Cache_Ledge_Point *)qdist);
          min_qdist = (int)result;
        }
        else if ( v40.synapse->status == 2 )
        {
          result = (const IVP_Compact_Edge *)IVP_Mindist_Minimize_Solver::p_minimize_PF(
                                               this: v66,
                                               P: edge,
                                               F: pB,
                                               m_cache_P: (IVP_Cache_Ledge_Point *)distanceCase,
                                               m_cache_F: (IVP_Cache_Ledge_Point *)qdist);
          min_qdist = (int)result;
        }
        else
        {
          _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_minimize.cxx", 469);
          return (const IVP_Compact_Edge *)min_qdist;
        }
      }
      else
      {
        result = (const IVP_Compact_Edge *)IVP_Mindist_Minimize_Solver::p_minimize_PP(
                                             this: v66,
                                             A: edge,
                                             B: pB,
                                             m_cache_A: (IVP_Cache_Ledge_Point *)distanceCase,
                                             m_cache_B: (IVP_Cache_Ledge_Point *)qdist);
        min_qdist = (int)result;
      }
      return result;
    case 1:
      if ( v40.synapse->status != 1 )
      {
        l_obj = v41.synapse->l_obj;
        LOWORD(kkin.cross_KL_Los.k[2]) = 1;
        *(_DWORD *)&obj0.m_szBuf[247] = 0;
        LOWORD(obj0.m_nLength) = 1;
        *(_DWORD *)&obj1.m_szBuf[247] = 0;
        LODWORD(kkin.cross_KL_Los.k[1]) = &CFmtStrN<256>::`vftable';
        *(_DWORD *)&obj0.m_szBuf[255] = &CFmtStrN<256>::`vftable';
        CFmtStrN<256>::sprintf(
          this: (CFmtStrN<256> *)&kkin.cross_KL_Los.k[1],
          pszFormat: "%s (%d) at %.1f %.1f %.1f",
          l_obj->name,
          1,
          l_obj->physical_core->m_world_f_core_last_psi.vv.k[0],
          l_obj->physical_core->m_world_f_core_last_psi.vv.k[1],
          l_obj->physical_core->m_world_f_core_last_psi.vv.k[2]);
        CFmtStrN<256>::sprintf(
          this: (CFmtStrN<256> *)&obj0.m_szBuf[255],
          pszFormat: "%s (%d) at %.1f %.1f %.1f",
          v40.synapse->l_obj->name,
          v40.synapse->status,
          v40.synapse->l_obj->physical_core->m_world_f_core_last_psi.vv.k[0],
          v40.synapse->l_obj->physical_core->m_world_f_core_last_psi.vv.k[1],
          v40.synapse->l_obj->physical_core->m_world_f_core_last_psi.vv.k[2]);
        v46 = (void (*)(const char *, ...))_Error;
        _Error(
          a1: "%s in contact with %s, crash. dist = %d, minq = %lf\n",
          (const char *)&kkin.cross_KL_Los.k[2] + 1,
          (const char *)&obj0.m_nLength + 1,
          v69,
          v71);
        synapse = 486;
        goto LABEL_52;
      }
      result = (const IVP_Compact_Edge *)IVP_Mindist_Minimize_Solver::p_minimize_KK(
                                           this: v66,
                                           K: edge,
                                           L: pB,
                                           m_cache_K: (IVP_Cache_Ledge_Point *)distanceCase,
                                           m_cache_L: (IVP_Cache_Ledge_Point *)qdist);
      min_qdist = (int)result;
      return result;
    case 2:
      v47 = v41.synapse->l_obj;
      LOWORD(obj0.m_nLength) = 1;
      *(_DWORD *)&obj1.m_szBuf[247] = 0;
      LOWORD(kkin.cross_KL_Los.k[2]) = 1;
      *(_DWORD *)&obj0.m_szBuf[247] = 0;
      *(_DWORD *)&obj0.m_szBuf[255] = &CFmtStrN<256>::`vftable';
      LODWORD(kkin.cross_KL_Los.k[1]) = &CFmtStrN<256>::`vftable';
      CFmtStrN<256>::sprintf(
        this: (CFmtStrN<256> *)&obj0.m_szBuf[255],
        pszFormat: "%s (%d) at %.1f %.1f %.1f",
        v47->name,
        2,
        v47->physical_core->m_world_f_core_last_psi.vv.k[0],
        v47->physical_core->m_world_f_core_last_psi.vv.k[1],
        v47->physical_core->m_world_f_core_last_psi.vv.k[2]);
      CFmtStrN<256>::sprintf(
        this: (CFmtStrN<256> *)&kkin.cross_KL_Los.k[1],
        pszFormat: "%s (%d) at %.1f %.1f %.1f",
        v40.synapse->l_obj->name,
        v40.synapse->status,
        v40.synapse->l_obj->physical_core->m_world_f_core_last_psi.vv.k[0],
        v40.synapse->l_obj->physical_core->m_world_f_core_last_psi.vv.k[1],
        v40.synapse->l_obj->physical_core->m_world_f_core_last_psi.vv.k[2]);
      v46 = (void (*)(const char *, ...))_Error;
      _Error(
        a1: "%s in contact with %s, crash. dist = %d, minq = %lf\n",
        (const char *)&obj0.m_nLength + 1,
        (const char *)&kkin.cross_KL_Los.k[2] + 1,
        v69,
        v71);
      synapse = 499;
      goto LABEL_52;
    case 3:
      v48 = v41.synapse->l_obj;
      *(_DWORD *)&obj1.m_szBuf[247] = 0;
      *(_DWORD *)&obj0.m_szBuf[247] = 0;
      LOWORD(obj0.m_nLength) = 1;
      LOWORD(kkin.cross_KL_Los.k[2]) = 1;
      *(_DWORD *)&obj0.m_szBuf[255] = &CFmtStrN<256>::`vftable';
      LODWORD(kkin.cross_KL_Los.k[1]) = &CFmtStrN<256>::`vftable';
      CFmtStrN<256>::sprintf(
        this: (CFmtStrN<256> *)&obj0.m_szBuf[255],
        pszFormat: "%s (%d) at %.1f %.1f %.1f",
        v48->name,
        3,
        v48->physical_core->m_world_f_core_last_psi.vv.k[0],
        v48->physical_core->m_world_f_core_last_psi.vv.k[1],
        v48->physical_core->m_world_f_core_last_psi.vv.k[2]);
      CFmtStrN<256>::sprintf(
        this: (CFmtStrN<256> *)&kkin.cross_KL_Los.k[1],
        pszFormat: "%s (%d) at %.1f %.1f %.1f",
        v40.synapse->l_obj->name,
        v40.synapse->status,
        v40.synapse->l_obj->physical_core->m_world_f_core_last_psi.vv.k[0],
        v40.synapse->l_obj->physical_core->m_world_f_core_last_psi.vv.k[1],
        v40.synapse->l_obj->physical_core->m_world_f_core_last_psi.vv.k[2]);
      v46 = (void (*)(const char *, ...))_Error;
      _Error(
        a1: "%s in contact with %s, crash. dist = %d, minq = %lf\n",
        (const char *)&obj0.m_nLength + 1,
        (const char *)&kkin.cross_KL_Los.k[2] + 1,
        v69,
        v71);
      synapse = 509;
      goto LABEL_52;
    default:
      v49 = v41.synapse->l_obj;
      *(_DWORD *)&obj1.m_szBuf[247] = 0;
      *(_DWORD *)&obj0.m_szBuf[247] = 0;
      LOWORD(obj0.m_nLength) = 1;
      LOWORD(kkin.cross_KL_Los.k[2]) = 1;
      *(_DWORD *)&obj0.m_szBuf[255] = &CFmtStrN<256>::`vftable';
      LODWORD(kkin.cross_KL_Los.k[1]) = &CFmtStrN<256>::`vftable';
      CFmtStrN<256>::sprintf(
        this: (CFmtStrN<256> *)&obj0.m_szBuf[255],
        pszFormat: "%s (%d) at %.1f %.1f %.1f",
        v49->name,
        status,
        v49->physical_core->m_world_f_core_last_psi.vv.k[0],
        v49->physical_core->m_world_f_core_last_psi.vv.k[1],
        v49->physical_core->m_world_f_core_last_psi.vv.k[2]);
      CFmtStrN<256>::sprintf(
        this: (CFmtStrN<256> *)&kkin.cross_KL_Los.k[1],
        pszFormat: "%s (%d) at %.1f %.1f %.1f",
        v40.synapse->l_obj->name,
        v40.synapse->status,
        v40.synapse->l_obj->physical_core->m_world_f_core_last_psi.vv.k[0],
        v40.synapse->l_obj->physical_core->m_world_f_core_last_psi.vv.k[1],
        v40.synapse->l_obj->physical_core->m_world_f_core_last_psi.vv.k[2]);
      v46 = (void (*)(const char *, ...))_Error;
      _Error(
        a1: "%s in contact with %s, crash. dist = %d, minq = %lf\n",
        (const char *)&obj0.m_nLength + 1,
        (const char *)&kkin.cross_KL_Los.k[2] + 1,
        v69,
        v71);
      synapse = 519;
LABEL_52:
      v46(a1: "IVP Failed at %s %d\n", "..\\ivp_collision\\ivp_mindist_minimize.cxx", synapse);
      return (const IVP_Compact_Edge *)min_qdist;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092420
// Name: protected: static enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::minimize_default_poly_poly(class IVP_Mindist_Minimize_Solver __near *)
// Source: json
//------------------------------------------------------------------------------
const IVP_Compact_Edge *__cdecl IVP_Mindist_Minimize_Solver::minimize_default_poly_poly(
        IVP_Mindist_Minimize_Solver *mms)
{
  IVP_Real_Object *l_obj; // esi
  IVP_Synapse_Real *v2; // edx
  IVP_Compact_Edge *edge; // ecx
  IVP_Real_Object *v4; // edi
  const IVP_Compact_Edge *v5; // edx
  const IVP_Compact_Ledge *v6; // ebx
  bool v7; // zf
  IVP_Cache_Object *cache_object; // eax
  IVP_Cache_Object *v9; // eax
  const IVP_Compact_Ledge *v10; // esi
  IVP_Cache_Object *v11; // eax
  const IVP_Compact_Edge *result; // eax
  IVP_Cache_Ledge_Point m_cache_1; // [esp+Ch] [ebp-38h] BYREF
  IVP_Cache_Ledge_Point m_cache_0; // [esp+20h] [ebp-24h] BYREF
  IVP_Synapse_Real *syn1; // [esp+34h] [ebp-10h]
  IVP_Synapse_Real *syn0; // [esp+38h] [ebp-Ch]
  const IVP_Compact_Edge *e0; // [esp+3Ch] [ebp-8h]
  const IVP_Compact_Edge *e1; // [esp+40h] [ebp-4h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  l_obj = mms->mindist->synapse[(*((_DWORD *)&mms->mindist->IVP_Mindist_Base + 5) >> 8) & 3].l_obj;
  v2 = (IVP_Synapse_Real *)&mms->mindist->synapse[(*((_DWORD *)&mms->mindist->IVP_Mindist_Base + 5) >> 8) & 3];
  edge = (IVP_Compact_Edge *)mms->mindist->synapse[(*((_DWORD *)&mms->mindist->IVP_Mindist_Base + 5) >> 8) & 3].edge;
  syn1 = (IVP_Synapse_Real *)&mms->mindist->synapse[((*((_DWORD *)&mms->mindist->IVP_Mindist_Base + 5) ^ 0x100u) >> 8)
                                                  & 3];
  v4 = syn1->l_obj;
  syn0 = v2;
  v5 = syn1->edge;
  v6 = (const IVP_Compact_Ledge *)(((unsigned int)edge & 0xFFFFFFF0)
                                 - 16 * ((*(_DWORD *)((unsigned int)edge & 0xFFFFFFF0) & 0xFFF) + 1));
  m_cache_0.compact_ledge = v6;
  v7 = l_obj->cache_object == nullptr;
  e0 = edge;
  e1 = v5;
  if ( v7 )
  {
    cache_object = IVP_Cache_Object_Manager::get_cache_object(
                     this: l_obj->environment->cache_object_manager,
                     object: l_obj);
    v5 = e1;
    edge = (IVP_Compact_Edge *)e0;
    l_obj->cache_object = cache_object;
  }
  ++l_obj->cache_object->reference_count;
  if ( *(_BYTE *)&l_obj->flags < 8 )
  {
    v9 = l_obj->cache_object;
    if ( l_obj->environment->current_time_code > v9->valid_until_time_code )
    {
      IVP_Cache_Object::update_cache_object(this: v9);
      edge = (IVP_Compact_Edge *)e0;
    }
    v5 = e1;
  }
  m_cache_0.clp_cache_object = l_obj->cache_object;
  m_cache_0.clp_object = l_obj;
  m_cache_0.compact_poly_points = (const IVP_Compact_Poly_Point *)((char *)v6 + v6->c_point_offset);
  v10 = (const IVP_Compact_Ledge *)(((unsigned int)v5 & 0xFFFFFFF0)
                                  - 16 * ((*(_DWORD *)((unsigned int)v5 & 0xFFFFFFF0) & 0xFFF) + 1));
  m_cache_1.compact_ledge = v10;
  if ( v4->cache_object == nullptr )
  {
    v11 = IVP_Cache_Object_Manager::get_cache_object(this: v4->environment->cache_object_manager, object: v4);
    v5 = e1;
    edge = (IVP_Compact_Edge *)e0;
    v4->cache_object = v11;
  }
  ++v4->cache_object->reference_count;
  if ( *(_BYTE *)&v4->flags < 8 && v4->environment->current_time_code > v4->cache_object->valid_until_time_code )
  {
    IVP_Cache_Object::update_cache_object(this: v4->cache_object);
    v5 = e1;
    edge = (IVP_Compact_Edge *)e0;
  }
  m_cache_1.clp_cache_object = v4->cache_object;
  m_cache_1.clp_object = v4;
  m_cache_1.compact_poly_points = (const IVP_Compact_Poly_Point *)((char *)v10 + v10->c_point_offset);
  m_cache_0.tmp.synapse = syn0;
  m_cache_1.tmp.synapse = syn1;
  switch ( syn1->status + 4 * syn0->status )
  {
    case 0:
      result = (const IVP_Compact_Edge *)IVP_Mindist_Minimize_Solver::p_minimize_PP(
                                           this: mms,
                                           A: edge,
                                           B: v5,
                                           m_cache_A: &m_cache_0,
                                           m_cache_B: &m_cache_1);
      --m_cache_0.clp_cache_object->reference_count;
      --m_cache_1.clp_cache_object->reference_count;
      break;
    case 1:
      result = (const IVP_Compact_Edge *)IVP_Mindist_Minimize_Solver::p_minimize_PK(
                                           this: mms,
                                           P: edge,
                                           K: v5,
                                           m_cache_P: &m_cache_0,
                                           m_cache_K: &m_cache_1);
      --m_cache_0.clp_cache_object->reference_count;
      --m_cache_1.clp_cache_object->reference_count;
      break;
    case 2:
      result = (const IVP_Compact_Edge *)IVP_Mindist_Minimize_Solver::p_minimize_PF(
                                           this: mms,
                                           P: edge,
                                           F: v5,
                                           m_cache_P: &m_cache_0,
                                           m_cache_F: &m_cache_1);
      --m_cache_0.clp_cache_object->reference_count;
      --m_cache_1.clp_cache_object->reference_count;
      break;
    case 5:
      result = (const IVP_Compact_Edge *)IVP_Mindist_Minimize_Solver::p_minimize_KK(
                                           this: mms,
                                           K: edge,
                                           L: v5,
                                           m_cache_K: &m_cache_0,
                                           m_cache_L: &m_cache_1);
      --m_cache_0.clp_cache_object->reference_count;
      --m_cache_1.clp_cache_object->reference_count;
      break;
    default:
      result = IVP_Mindist_Minimize_Solver::p_minimize_FF(
                 this: mms,
                 a2: (IVP_Cache_Ledge_Point *)&savedregs,
                 A: (IVP_Cache_Ledge_Point *)edge,
                 B: v5,
                 m_cache_A: &m_cache_0,
                 m_cache_B: &m_cache_1);
      --m_cache_0.clp_cache_object->reference_count;
      --m_cache_1.clp_cache_object->reference_count;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10092660
// Name: protected: static enum IVP_MRC_TYPE IVP_Mindist_Minimize_Solver::minimize_swapped_poly_poly(class IVP_Mindist_Minimize_Solver __near *)
// Source: json
//------------------------------------------------------------------------------
const IVP_Compact_Edge *__cdecl IVP_Mindist_Minimize_Solver::minimize_swapped_poly_poly(
        IVP_Mindist_Minimize_Solver *mms)
{
  *((_DWORD *)&mms->mindist->IVP_Mindist_Base + 5) ^= 0x100u;
  return IVP_Mindist_Minimize_Solver::minimize_default_poly_poly(mms);
}

//------------------------------------------------------------------------------
// Address: 0x10092680
// Name: public: static void IVP_Mindist_Minimize_Solver::init_mms_function_table(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IVP_Mindist_Minimize_Solver::init_mms_function_table()
{
  int *v0; // eax

  v0 = &dword_100FED24;
  do
  {
    *(v0 - 1) = (int)IVP_Mindist_Minimize_Solver::minimize_illegal;
    *v0 = (int)IVP_Mindist_Minimize_Solver::minimize_illegal;
    v0[1] = (int)IVP_Mindist_Minimize_Solver::minimize_illegal;
    v0[2] = (int)IVP_Mindist_Minimize_Solver::minimize_illegal;
    v0 += 4;
  }
  while ( (int)v0 < (int)&vec2_origin_92.y );
  IVP_Mindist_Minimize_Solver::mms_function_table[0][0] = (IVP_MRC_TYPE (__cdecl *)(IVP_Mindist_Minimize_Solver *))IVP_Mindist_Minimize_Solver::minimize_default_poly_poly;
  dword_100FED24 = (int)IVP_Mindist_Minimize_Solver::minimize_default_poly_poly;
  dword_100FED28 = (int)IVP_Mindist_Minimize_Solver::minimize_default_poly_poly;
  dword_100FED34 = (int)IVP_Mindist_Minimize_Solver::minimize_default_poly_poly;
  dword_100FED48 = (int)IVP_Mindist_Minimize_Solver::minimize_default_poly_poly;
  dword_100FED2C = (int)IVP_Mindist_Minimize_Solver::minimize_PB;
  dword_100FED30 = (int)IVP_Mindist_Minimize_Solver::minimize_swapped_poly_poly;
  dword_100FED38 = (int)IVP_Mindist_Minimize_Solver::minimize_illegal;
  dword_100FED3C = (int)IVP_Mindist_Minimize_Solver::minimize_KB;
  dword_100FED40 = (int)IVP_Mindist_Minimize_Solver::minimize_swapped_poly_poly;
  dword_100FED44 = (int)IVP_Mindist_Minimize_Solver::minimize_illegal;
  dword_100FED4C = (int)IVP_Mindist_Minimize_Solver::minimize_FB;
  dword_100FED50 = (int)IVP_Mindist_Minimize_Solver::minimize_B_POLY;
  dword_100FED54 = (int)IVP_Mindist_Minimize_Solver::minimize_B_POLY;
  dword_100FED58 = (int)IVP_Mindist_Minimize_Solver::minimize_B_POLY;
  dword_100FED5C = (int)IVP_Mindist_Minimize_Solver::minimize_BB;
}

//------------------------------------------------------------------------------
// Address: 0x100B290D
// Name: _sprintf
// Source: json
//------------------------------------------------------------------------------
int sprintf(char *string, const char *format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+38h] [ebp+10h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && string != nullptr )
  {
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    str._flag = 66;
    v3 = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = --str._cnt < 0;
    v5 = v3;
    if ( v4 )
      _flsbuf(ch: 0, &str);
    else
      *str._ptr = 0;
    return v5;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2991
// Name: _fprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int fprintf(_iobuf *str, const char *format, ...)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  int v6; // esi
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+3Ch] [ebp+10h] BYREF

  va_start(argptr, format);
  retval = 0;
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v3 = _fileno(stream: str);
      if ( v3 == -1 || v3 == -2 )
        v4 = &__badioinfo;
      else
        v4 = &__pioinfo[v3 >> 5][v3 & 0x1F];
      if ( (*((_BYTE *)v4 + 36) & 0x7F) != 0
        || (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = &__pioinfo[v3 >> 5][v3 & 0x1F]), *((char *)v5 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      v6 = _stbuf(str);
      retval = _output_l(stream: str, format, plocinfo: nullptr, argptr);
      _ftbuf(flag: v6, str);
    }
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2AA0
// Name: _strrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strrchr(unsigned __int8 *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v2 = strlen((const char *)string) + 1;
  v3 = &string[v2 - 1];
  do
  {
    if ( v2 == 0 )
      break;
    v4 = *v3-- == chr;
    --v2;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x100B2AD0
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x100B53E6);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2B56
// Name: __time64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __cdecl _time64(__int64 *timeptr)
{
  __int64 result; // rax
  FT nt_time; // [esp+0h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: (LPFILETIME)&nt_time);
  result = (nt_time.ft_scalar - 116444736000000000LL) / 0x989680;
  if ( result > 0x793406FFFLL )
    result = -1;
  if ( timeptr != nullptr )
    *timeptr = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B2BA7
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleW; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"mscoree.dll");
  if ( ModuleHandleW != nullptr )
  {
    CorExitProcess = GetProcAddress(hModule: ModuleHandleW, lpProcName: "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__stdcall *)(int))CorExitProcess)(a1: status);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2BD2
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(uExitCode: status);
}

//------------------------------------------------------------------------------
// Address: 0x100B2BEA
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _lockexit()
{
  _lock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x100B2BF3
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unlockexit()
{
  _unlock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x100B2BFC
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _init_pointers()
{
  void *v0; // esi

  v0 = (void *)_encoded_null();
  _initp_heap_handler(enull: v0);
  _initp_misc_invarg(enull: v0);
  _initp_misc_purevirt(enull: v0);
  _initp_misc_rand_s(enull: v0);
  _initp_misc_winsig(enull: v0);
  _initp_eh_hooks(enull: v0);
}

//------------------------------------------------------------------------------
// Address: 0x100B2C2F
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _initterm_e(int (__cdecl **pfbegin)(), int (__cdecl **pfend)())
{
  int result; // eax

  result = 0;
  while ( pfbegin < pfend && result == 0 )
  {
    if ( *pfbegin != nullptr )
      result = (*pfbegin)();
    ++pfbegin;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B2C53
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // edi

  if ( _fpmath != nullptr && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_FPinit) != 0 )
    _fpmath(initPrecision: initFloatingPrecision);
  _initp_misc_cfltcvt_tab();
  result = _initterm_e(pfbegin: __xi_a, pfend: __xi_z);
  if ( result == 0 )
  {
    atexit(func: _RTC_Terminate);
    for ( i = __xc_a; i < __xc_z; ++i )
    {
      if ( *i != nullptr )
        (*i)();
    }
    if ( __dyn_tls_init_callback != nullptr
      && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&__dyn_tls_init_callback) != 0 )
    {
      __dyn_tls_init_callback(a1: nullptr, a2: 2u, a3: nullptr);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B2CEA
// Name: doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl doexit(int code, int quick, int retcaller)
{
  PVOID *v3; // ebx
  PVOID *v4; // edi
  void (*v5)(void); // ebx
  void (__cdecl **v6)(); // ebx
  void (__cdecl **v7)(); // eax
  void (__cdecl **onexitbegin)(); // [esp+10h] [ebp-30h]
  void (__cdecl **onexitend_saved)(); // [esp+18h] [ebp-28h]
  void (__cdecl **onexitbegin_saved)(); // [esp+1Ch] [ebp-24h]
  void (**j)(void); // [esp+20h] [ebp-20h]
  void (**i)(void); // [esp+24h] [ebp-1Ch]

  _lock(locknum: 8);
  if ( _C_Exit_Done != 1 )
  {
    _C_Termination_Done = 1;
    _exitflag = retcaller;
    if ( quick == 0 )
    {
      v3 = (PVOID *)DecodePointer(Ptr: __onexitbegin);
      onexitbegin = (void (__cdecl **)())v3;
      if ( v3 != nullptr )
      {
        v4 = (PVOID *)DecodePointer(Ptr: __onexitend);
        onexitbegin_saved = (void (__cdecl **)())v3;
        onexitend_saved = (void (__cdecl **)())v4;
        while ( --v4 >= v3 )
        {
          if ( *v4 != (PVOID)_encoded_null() )
          {
            if ( v4 < v3 )
              break;
            v5 = (void (*)(void))DecodePointer(Ptr: *v4);
            *v4 = (PVOID)_encoded_null();
            v5();
            v6 = (void (__cdecl **)())DecodePointer(Ptr: __onexitbegin);
            v7 = (void (__cdecl **)())DecodePointer(Ptr: __onexitend);
            if ( onexitbegin_saved != v6 || onexitend_saved != v7 )
            {
              onexitbegin_saved = v6;
              onexitbegin = v6;
              onexitend_saved = v7;
              v4 = (PVOID *)v7;
            }
            v3 = (PVOID *)onexitbegin;
          }
        }
      }
      for ( i = __xp_a; i < __xp_z; ++i )
      {
        if ( *i != nullptr )
          (*i)();
      }
    }
    for ( j = __xt_a; j < __xt_z; ++j )
    {
      if ( *j != nullptr )
        (*j)();
    }
  }
  if ( retcaller != 0 )
    _unlock(locknum: 8);
  if ( retcaller == 0 )
  {
    _C_Exit_Done = 1;
    _unlock(locknum: 8);
    __crtExitProcess(status: code);
  }
}
