// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_controller/ivp_constraint_local.cxx
// Functions: 22
// ============================================================

#include "ivp\ivp_controller\ivp_constraint_local.h"

//------------------------------------------------------------------------------
// Address: 0x100A6C00
// Name: private: void IVP_Constraint_Local::sort_translation_mapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Local::sort_translation_mapping(IVP_Constraint_Local *this)
{
  int v1; // edx
  __int16 v2; // ax
  IVP_CONSTRAINT_AXIS_TYPE *fixed; // esi
  __int16 v4; // ax
  IVP_CONSTRAINT_AXIS_TYPE *v5; // esi
  __int16 v6; // ax
  IVP_CONSTRAINT_AXIS_TYPE *v7; // esi
  IVP_CONSTRAINT_AXIS_TYPE v8; // eax
  IVP_CONSTRAINT_AXIS_TYPE v9; // eax
  IVP_CONSTRAINT_AXIS_TYPE v10; // eax

  v1 = 0;
  v2 = 0;
  fixed = this->fixed;
  do
  {
    if ( *fixed == IVP_CONSTRAINT_AXIS_FIXED )
      this->mapping_uRfs_f_Rfs.k[(__int16)v1++] = v2;
    ++v2;
    ++fixed;
  }
  while ( v2 < 3 );
  v4 = 0;
  v5 = this->fixed;
  do
  {
    if ( *v5 == IVP_CONSTRAINT_AXIS_LIMITED )
      this->mapping_uRfs_f_Rfs.k[(__int16)v1++] = v4;
    ++v4;
    ++v5;
  }
  while ( v4 < 3 );
  v6 = 0;
  v7 = this->fixed;
  do
  {
    if ( *v7 == IVP_CONSTRAINT_AXIS_FREE )
      this->mapping_uRfs_f_Rfs.k[(__int16)v1++] = v6;
    ++v6;
    ++v7;
  }
  while ( v6 < 3 );
  v8 = this->fixed[0];
  this->limitedtrans_dim = 0;
  this->fixedtrans_dim = 0;
  if ( v8 == IVP_CONSTRAINT_AXIS_FIXED )
    this->fixedtrans_dim = 1;
  if ( (v8 & 2) != 0 )
    this->limitedtrans_dim = 1;
  v9 = this->fixed[1];
  if ( v9 == IVP_CONSTRAINT_AXIS_FIXED )
    ++this->fixedtrans_dim;
  if ( (v9 & 2) != 0 )
    ++this->limitedtrans_dim;
  v10 = this->fixed[2];
  if ( v10 == IVP_CONSTRAINT_AXIS_FIXED )
    ++this->fixedtrans_dim;
  if ( (v10 & 2) != 0 )
    ++this->limitedtrans_dim;
  this->matrix_size = this->limitedtrans_dim + this->fixedtrans_dim + this->fixedrot_dim + this->limitedrot_dim;
}

//------------------------------------------------------------------------------
// Address: 0x100A6CF0
// Name: private: void IVP_Constraint_Local::sort_rotation_mapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Local::sort_rotation_mapping(IVP_Constraint_Local *this)
{
  int v1; // edx
  int v2; // eax
  IVP_CONSTRAINT_AXIS_TYPE *v3; // esi
  int v4; // eax
  IVP_CONSTRAINT_AXIS_TYPE *v5; // esi
  int v6; // eax
  IVP_CONSTRAINT_AXIS_TYPE *v7; // esi
  IVP_CONSTRAINT_AXIS_TYPE v8; // eax
  IVP_CONSTRAINT_AXIS_TYPE v9; // eax
  IVP_CONSTRAINT_AXIS_TYPE v10; // eax

  v1 = 0;
  v2 = 0;
  v3 = &this->fixed[3];
  do
  {
    if ( *v3 == IVP_CONSTRAINT_AXIS_FIXED )
      this->mapping_uRrs_f_Rrs.k[v1++] = v2;
    ++v2;
    ++v3;
  }
  while ( v2 < 3 );
  v4 = 0;
  v5 = &this->fixed[3];
  do
  {
    if ( *v5 == IVP_CONSTRAINT_AXIS_LIMITED )
      this->mapping_uRrs_f_Rrs.k[v1++] = v4;
    ++v4;
    ++v5;
  }
  while ( v4 < 3 );
  v6 = 0;
  v7 = &this->fixed[3];
  do
  {
    if ( *v7 == IVP_CONSTRAINT_AXIS_FREE )
      this->mapping_uRrs_f_Rrs.k[v1++] = v6;
    ++v6;
    ++v7;
  }
  while ( v6 < 3 );
  v8 = this->fixed[3];
  this->limitedrot_dim = 0;
  this->fixedrot_dim = 0;
  if ( v8 == IVP_CONSTRAINT_AXIS_FIXED )
    this->fixedrot_dim = 1;
  if ( (v8 & 2) != 0 )
    this->limitedrot_dim = 1;
  v9 = this->fixed[4];
  if ( v9 == IVP_CONSTRAINT_AXIS_FIXED )
    ++this->fixedrot_dim;
  if ( (v9 & 2) != 0 )
    ++this->limitedrot_dim;
  v10 = this->fixed[5];
  if ( v10 == IVP_CONSTRAINT_AXIS_FIXED )
    ++this->fixedrot_dim;
  if ( (v10 & 2) != 0 )
    ++this->limitedrot_dim;
  this->matrix_size = this->limitedrot_dim + this->fixedrot_dim + this->fixedtrans_dim + this->limitedtrans_dim;
}

//------------------------------------------------------------------------------
// Address: 0x100A6DD0
// Name: public: virtual IVP_Constraint_Local::~IVP_Constraint_Local(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Local::~IVP_Constraint_Local(IVP_Constraint_Local *this)
{
  IVP_Constraint_Local_MaxImpulse *maxforce; // eax

  maxforce = this->maxforce;
  this->__vftable = (IVP_Constraint_Local_vtbl *)&IVP_Constraint_Local::`vftable';
  if ( maxforce != nullptr )
  {
    free(data: maxforce);
    this->maxforce = nullptr;
  }
  if ( this->m_Rfs_f_Rcs.rot != nullptr )
  {
    free(data: this->m_Rfs_f_Rcs.rot);
    this->m_Rfs_f_Rcs.rot = nullptr;
  }
  if ( this->m_Afs_f_Acs.rot != nullptr )
  {
    free(data: this->m_Afs_f_Acs.rot);
    this->m_Afs_f_Acs.rot = nullptr;
  }
  IVP_Constraint::~IVP_Constraint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A6E50
// Name: public: virtual void IVP_Constraint_Local::fix_translation_axis(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Local::fix_translation_axis(IVP_Constraint_Local *this, IVP_COORDINATE_INDEX which)
{
  IVP_Real_Object *object; // ecx

  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  this->fixed[which] = IVP_CONSTRAINT_AXIS_FIXED;
  IVP_Constraint_Local::sort_translation_mapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A6E90
// Name: public: virtual void IVP_Constraint_Local::free_translation_axis(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Local::free_translation_axis(IVP_Constraint_Local *this, IVP_COORDINATE_INDEX which)
{
  IVP_Real_Object *object; // ecx

  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  this->fixed[which] = IVP_CONSTRAINT_AXIS_FREE;
  IVP_Constraint_Local::sort_translation_mapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A6ED0
// Name: public: virtual void IVP_Constraint_Local::limit_translation_axis(enum IVP_COORDINATE_INDEX,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Local::limit_translation_axis(
        IVP_Constraint_Local *this,
        IVP_COORDINATE_INDEX which,
        float border_left,
        float border_right)
{
  IVP_Real_Object *object; // ecx

  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  this->borderleft_Rfs[which] = border_left;
  this->fixed[which] = IVP_CONSTRAINT_AXIS_LIMITED;
  this->borderright_Rfs[which] = border_right;
  IVP_Constraint_Local::sort_translation_mapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A6F20
// Name: public: virtual void IVP_Constraint_Local::change_max_translation_impulse(enum IVP_CONSTRAINT_FORCE_EXCEED,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Local::change_max_translation_impulse(
        IVP_Constraint_Local *this,
        IVP_CONSTRAINT_FORCE_EXCEED impulsetype,
        float impulse)
{
  IVP_Real_Object *object; // ecx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // edi

  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  if ( this->maxforce == nullptr )
  {
    v5 = (unsigned __int8 *)p_malloc(size: 0x30u);
    v6 = v5;
    if ( v5 != nullptr )
      memset(dst: v5, value: 0, count: 0x30u);
    else
      v6 = nullptr;
    this->maxforce = (IVP_Constraint_Local_MaxImpulse *)v6;
    *((_DWORD *)v6 + 11) = 0;
    this->maxforce->type[4] = IVP_CFE_NONE;
    this->maxforce->type[3] = IVP_CFE_NONE;
  }
  this->maxforce->halfimpulse[2] = impulse;
  this->maxforce->halfimpulse[1] = impulse;
  this->maxforce->halfimpulse[0] = impulse;
  this->maxforce->type[2] = impulsetype;
  this->maxforce->type[1] = impulsetype;
  this->maxforce->type[0] = impulsetype;
}

//------------------------------------------------------------------------------
// Address: 0x100A6FC0
// Name: public: virtual void IVP_Constraint_Local::fix_rotation_axis(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Local::fix_rotation_axis(IVP_Constraint_Local *this, IVP_COORDINATE_INDEX which)
{
  IVP_Real_Object *object; // ecx

  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  this->fixed[which + 3] = IVP_CONSTRAINT_AXIS_FIXED;
  IVP_Constraint_Local::sort_rotation_mapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A7000
// Name: public: virtual void IVP_Constraint_Local::free_rotation_axis(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Local::free_rotation_axis(IVP_Constraint_Local *this, IVP_COORDINATE_INDEX which)
{
  IVP_Real_Object *object; // ecx

  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  this->fixed[which + 3] = IVP_CONSTRAINT_AXIS_FREE;
  IVP_Constraint_Local::sort_rotation_mapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A7040
// Name: public: virtual void IVP_Constraint_Local::limit_rotation_axis(enum IVP_COORDINATE_INDEX,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Local::limit_rotation_axis(
        IVP_Constraint_Local *this,
        IVP_COORDINATE_INDEX which,
        float border_left,
        float border_right)
{
  IVP_Real_Object *object; // ecx

  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  this->borderleft_Rfs[which + 3] = border_left;
  this->fixed[which + 3] = IVP_CONSTRAINT_AXIS_LIMITED;
  this->borderright_Rfs[which + 3] = border_right;
  IVP_Constraint_Local::sort_rotation_mapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A7090
// Name: public: virtual void IVP_Constraint_Local::change_max_rotation_impulse(enum IVP_CONSTRAINT_FORCE_EXCEED,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Local::change_max_rotation_impulse(
        IVP_Constraint_Local *this,
        IVP_CONSTRAINT_FORCE_EXCEED impulsetype,
        float impulse)
{
  IVP_Real_Object *object; // ecx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // edi

  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  if ( this->maxforce == nullptr )
  {
    v5 = (unsigned __int8 *)p_malloc(size: 0x30u);
    v6 = v5;
    if ( v5 != nullptr )
      memset(dst: v5, value: 0, count: 0x30u);
    else
      v6 = nullptr;
    this->maxforce = (IVP_Constraint_Local_MaxImpulse *)v6;
    *((_DWORD *)v6 + 8) = 0;
    this->maxforce->type[1] = IVP_CFE_NONE;
    this->maxforce->type[0] = IVP_CFE_NONE;
  }
  this->maxforce->halfimpulse[5] = impulse;
  this->maxforce->halfimpulse[4] = impulse;
  this->maxforce->halfimpulse[3] = impulse;
  this->maxforce->type[5] = impulsetype;
  this->maxforce->type[4] = impulsetype;
  this->maxforce->type[3] = impulsetype;
}

//------------------------------------------------------------------------------
// Address: 0x100A7160
// Name: protected: virtual void IVP_Constraint_Local::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Constraint_Local::do_simulation_controller(
        IVP_Constraint_Local *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  float delta_time; // xmm0_4
  IVP_Real_Object *object; // eax
  IVP_Core *v9; // edi
  IVP_Real_Object *v10; // eax
  IVP_U_Matrix3 *rot; // eax
  __int64 v12; // xmm0_8
  IVP_U_Matrix3 *v13; // eax
  int fixedrot_dim; // ecx
  __int64 v15; // xmm0_8
  int v16; // eax
  IVP_U_Matrix3 *v17; // edi
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  IVP_COORDINATE_INDEX v23; // eax
  int v24; // edx
  int v25; // edi
  float v26; // xmm0_4
  double v27; // xmm0_8
  float v28; // xmm1_4
  float v29; // xmm0_4
  IVP_CONSTRAINT_AXIS_TYPE *v30; // ecx
  int v31; // eax
  int v32; // eax
  int v33; // edi
  float v34; // xmm1_4
  int v35; // eax
  int v36; // xmm0_4
  float v37; // eax
  double v38; // xmm0_8
  IVP_U_Matrix *v39; // edi
  IVP_Core *v40; // edi
  float v41; // xmm5_4
  float v42; // xmm3_4
  IVP_CONSTRAINT_AXIS_TYPE v43; // eax
  float v44; // xmm7_4
  float v45; // xmm2_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  float v48; // xmm2_4
  float v49; // xmm6_4
  float v50; // xmm4_4
  float v51; // xmm2_4
  IVP_CONSTRAINT_AXIS_TYPE v52; // eax
  IVP_CONSTRAINT_AXIS_TYPE v53; // eax
  float v54; // xmm0_4
  IVP_CONSTRAINT_AXIS_TYPE v55; // eax
  IVP_CONSTRAINT_AXIS_TYPE v56; // eax
  float v57; // xmm0_4
  IVP_CONSTRAINT_AXIS_TYPE v58; // eax
  float v59; // xmm0_4
  float v60; // xmm0_4
  float v61; // xmm1_4
  float v62; // xmm7_4
  float v63; // xmm7_4
  IVP_CONSTRAINT_AXIS_TYPE v64; // eax
  float v65; // xmm6_4
  float v66; // xmm0_4
  float v67; // xmm3_4
  float v68; // xmm2_4
  float v69; // xmm1_4
  float v70; // xmm0_4
  float v71; // xmm3_4
  float v72; // xmm2_4
  float v73; // xmm1_4
  float v74; // xmm0_4
  IVP_CONSTRAINT_AXIS_TYPE v75; // eax
  IVP_CONSTRAINT_AXIS_TYPE v76; // eax
  float v77; // xmm4_4
  IVP_CONSTRAINT_AXIS_TYPE v78; // eax
  IVP_CONSTRAINT_AXIS_TYPE v79; // eax
  float v80; // xmm4_4
  IVP_CONSTRAINT_AXIS_TYPE v81; // eax
  float force_factor; // xmm0_4
  unsigned __int8 v83; // al
  float v84; // xmm0_4
  unsigned __int8 v85; // cl
  unsigned __int8 v86; // al
  unsigned __int8 v87; // cl
  bool v88; // zf
  float v89; // xmm0_4
  float v90; // xmm1_4
  float v91; // xmm0_4
  float v92; // xmm1_4
  float v93; // xmm0_4
  unsigned int v94; // edi
  IVP_U_Matrix3 *v95; // ecx
  IVP_CONSTRAINT_AXIS_TYPE *v96; // eax
  unsigned int i; // edi
  float v98; // xmm0_4
  float v99; // xmm4_4
  IVP_Core *v100; // eax
  float v101; // xmm1_4
  float v102; // xmm5_4
  IVP_U_Matrix3 *v103; // ecx
  int matrix_size; // eax
  void *v105; // esp
  void *v106; // esp
  void *v107; // esp
  float v108; // edx
  int v109; // eax
  char *v110; // ecx
  char *v111; // ecx
  int v112; // ecx
  int v113; // edi
  IVP_CONSTRAINT_AXIS_TYPE *v114; // eax
  float v115; // xmm0_4
  int v116; // eax
  __int32 v117; // ecx
  float v118; // xmm3_4
  __int32 v119; // ecx
  float v120; // xmm6_4
  __int32 v121; // ecx
  float v122; // xmm5_4
  __int32 v123; // ecx
  __int32 v124; // ecx
  float v125; // xmm2_4
  IVP_Constraint_Local_MaxImpulse *maxforce; // eax
  int v127; // ecx
  float v128; // xmm3_4
  float v129; // xmm2_4
  float v130; // xmm0_4
  float v131; // xmm0_4
  float v132; // xmm2_4
  bool v133; // cc
  float *v134; // eax
  float v135; // xmm2_4
  int *v136; // edi
  int j; // edx
  float v138; // xmm0_4
  float v139; // xmm4_4
  IVP_Environment *environment; // eax
  float v141; // xmm4_4
  IVP_Core *v142; // esi
  IVP_Core *v143; // esi
  long double v144; // [esp+8h] [ebp-51Ch] BYREF
  long double v145; // [esp+10h] [ebp-514h]
  IVP_U_Matrix v146; // [esp+18h] [ebp-50Ch] BYREF
  IVP_U_Float_Point v147[7]; // [esp+58h] [ebp-4CCh] BYREF
  IVP_U_Matrix3 v148; // [esp+C8h] [ebp-45Ch] BYREF
  IVP_U_Matrix3 v149; // [esp+F8h] [ebp-42Ch] BYREF
  IVP_U_Matrix3 v150; // [esp+128h] [ebp-3FCh] BYREF
  IVP_U_Float_Point v151; // [esp+158h] [ebp-3CCh] BYREF
  IVP_U_Float_Point v152; // [esp+168h] [ebp-3BCh] BYREF
  IVP_U_Float_Point v153; // [esp+178h] [ebp-3ACh] BYREF
  IVP_U_Float_Point v154; // [esp+188h] [ebp-39Ch] BYREF
  IVP_U_Float_Point v155; // [esp+198h] [ebp-38Ch] BYREF
  IVP_U_Float_Point v156; // [esp+1A8h] [ebp-37Ch] BYREF
  IVP_U_Matrix3 v157; // [esp+1B8h] [ebp-36Ch] BYREF
  IVP_U_Float_Point v158; // [esp+1E8h] [ebp-33Ch] BYREF
  IVP_U_Matrix3 v159; // [esp+1F8h] [ebp-32Ch] BYREF
  IVP_U_Float_Point v160; // [esp+228h] [ebp-2FCh] BYREF
  IVP_U_Matrix3 v161; // [esp+238h] [ebp-2ECh] BYREF
  IVP_U_Matrix3 v162; // [esp+268h] [ebp-2BCh] BYREF
  IVP_U_Float_Point v163; // [esp+298h] [ebp-28Ch] BYREF
  IVP_U_Float_Point v164; // [esp+2A8h] [ebp-27Ch] BYREF
  IVP_U_Float_Point v165; // [esp+2B8h] [ebp-26Ch] BYREF
  IVP_U_Float_Point v166; // [esp+2C8h] [ebp-25Ch] BYREF
  float v167[5]; // [esp+2D8h] [ebp-24Ch] BYREF
  _BYTE v168[44]; // [esp+2ECh] [ebp-238h] BYREF
  IVP_U_Matrix3 v169; // [esp+318h] [ebp-20Ch] BYREF
  IVP_U_Float_Point v170; // [esp+348h] [ebp-1DCh] BYREF
  IVP_U_Float_Point v171; // [esp+358h] [ebp-1CCh] BYREF
  float v172[4]; // [esp+368h] [ebp-1BCh]
  IVP_U_Float_Point v173; // [esp+378h] [ebp-1ACh] BYREF
  IVP_U_Float_Point v174; // [esp+388h] [ebp-19Ch] BYREF
  IVP_U_Float_Point v175; // [esp+398h] [ebp-18Ch] BYREF
  IVP_U_Float_Point v176; // [esp+3A8h] [ebp-17Ch] BYREF
  IVP_U_Float_Point v177; // [esp+3B8h] [ebp-16Ch] BYREF
  IVP_U_Float_Point v178; // [esp+3C8h] [ebp-15Ch] BYREF
  IVP_Great_Matrix_Many_Zero v179; // [esp+3E0h] [ebp-144h] BYREF
  IVP_U_Float_Point v180; // [esp+3F8h] [ebp-12Ch] BYREF
  IVP_U_Float_Point v181; // [esp+408h] [ebp-11Ch] BYREF
  int v182; // [esp+420h] [ebp-104h]
  float v183; // [esp+424h] [ebp-100h]
  IVP_U_Float_Point v184; // [esp+428h] [ebp-FCh] BYREF
  IVP_U_Float_Point v185; // [esp+438h] [ebp-ECh] BYREF
  IVP_U_Float_Point v186; // [esp+448h] [ebp-DCh] BYREF
  IVP_Constraint_Local_Anchor *p_m_Rfs_f_Rcs; // [esp+460h] [ebp-C4h]
  float v188; // [esp+464h] [ebp-C0h]
  IVP_U_Float_Point v189; // [esp+468h] [ebp-BCh] BYREF
  IVP_U_Float_Point v190; // [esp+478h] [ebp-ACh] BYREF
  IVP_U_Matrix3 *v191; // [esp+494h] [ebp-90h]
  IVP_U_Float_Point v192; // [esp+498h] [ebp-8Ch] BYREF
  IVP_U_Matrix *v193; // [esp+4B0h] [ebp-74h]
  float i_delta_time; // [esp+4B4h] [ebp-70h]
  IVP_U_Float_Point v195; // [esp+4B8h] [ebp-6Ch] BYREF
  IVP_U_Float_Point v196; // [esp+4C8h] [ebp-5Ch] BYREF
  char v197; // [esp+4DFh] [ebp-45h] BYREF
  IVP_CONSTRAINT_AXIS_TYPE *aligned_row_len; // [esp+4E4h] [ebp-40h]
  float v199; // [esp+4E8h] [ebp-3Ch]
  int v200; // [esp+4ECh] [ebp-38h] BYREF
  int v201; // [esp+4F0h] [ebp-34h]
  __int16 v202; // [esp+4F4h] [ebp-30h]
  IVP_U_Matrix *p_m_world_f_core_last_psi; // [esp+500h] [ebp-24h]
  float v204; // [esp+504h] [ebp-20h]
  IVP_U_Float_Point *v205; // [esp+508h] [ebp-1Ch]
  IVP_Core *physical_core; // [esp+50Ch] [ebp-18h]
  IVP_Core *v207; // [esp+510h] [ebp-14h]
  IVP_CONSTRAINT_AXIS_TYPE *fixed; // [esp+514h] [ebp-10h]
  _DWORD v209[3]; // [esp+518h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+524h] [ebp+0h]

  v209[0] = a2;
  v209[1] = retaddr;
  delta_time = es->delta_time;
  HIDWORD(v144) = a4;
  object = this->m_Rfs_f_Rcs.object;
  LODWORD(v144) = a3;
  v9 = nullptr;
  v188 = delta_time;
  if ( object != nullptr )
    physical_core = object->physical_core;
  else
    physical_core = nullptr;
  v10 = this->m_Afs_f_Acs.object;
  if ( v10 != nullptr )
    v9 = v10->physical_core;
  v207 = v9;
  IVP_U_Matrix::init(this: &v146);
  if ( physical_core != nullptr )
    p_m_world_f_core_last_psi = &physical_core->m_world_f_core_last_psi;
  else
    p_m_world_f_core_last_psi = &v146;
  if ( v9 != nullptr )
    v193 = &v9->m_world_f_core_last_psi;
  else
    v193 = &v146;
  p_m_Rfs_f_Rcs = &this->m_Rfs_f_Rcs;
  IVP_U_Matrix3::mi2mult3(this: &this->m_Rfs_f_Rcs, mb: p_m_world_f_core_last_psi, m_out: &v159);
  IVP_U_Matrix3::mmult3(this: &v159, mb: v193, m_out: &v150);
  rot = this->m_Rfs_f_Rcs.rot;
  if ( rot == nullptr )
  {
    v169 = this->m_Rfs_f_Rcs.IVP_U_Matrix3;
    rot = &v169;
  }
  v162.rows[0] = rot->rows[0];
  v162.rows[1] = rot->rows[1];
  *(_QWORD *)v162.rows[2].k = *(_QWORD *)rot->rows[2].k;
  v12 = *(_QWORD *)&rot->rows[2].k[2];
  v13 = this->m_Afs_f_Acs.rot;
  *(_QWORD *)&v162.rows[2].k[2] = v12;
  if ( v13 == nullptr )
  {
    v169 = this->m_Afs_f_Acs.IVP_U_Matrix3;
    v13 = &v169;
  }
  fixedrot_dim = this->fixedrot_dim;
  v161.rows[0] = v13->rows[0];
  v161.rows[1] = v13->rows[1];
  *(_QWORD *)v161.rows[2].k = *(_QWORD *)v13->rows[2].k;
  v15 = *(_QWORD *)&v13->rows[2].k[2];
  v16 = fixedrot_dim + this->limitedrot_dim;
  *(_QWORD *)&v161.rows[2].k[2] = v15;
  v191 = &v162;
  if ( v16 == 1 )
  {
    v17 = v193;
    v18 = v161.rows[0].k[4 * this->mapping_uRrs_f_Rrs.k[0] + 1];
    v19 = v161.rows[0].k[4 * this->mapping_uRrs_f_Rrs.k[0] + 2];
    v20 = v161.rows[this->mapping_uRrs_f_Rrs.k[0]].k[0];
    v191 = &v149;
    v190.k[0] = v20;
    v190.k[1] = v18;
    v190.k[2] = v19;
    IVP_U_Matrix3::vmult3(this: v193, p_in: &v190, p_out: &v174);
    IVP_U_Matrix3::vimult3(this: p_m_world_f_core_last_psi, p_in: &v174, p_out: &v196);
    v21 = v162.rows[0].k[4 * this->mapping_uRrs_f_Rrs.k[0] + 1];
    v22 = v162.rows[0].k[4 * this->mapping_uRrs_f_Rrs.k[0] + 2];
    v195.k[0] = v162.rows[this->mapping_uRrs_f_Rrs.k[0]].k[0];
    v195.k[1] = v21;
    v195.k[2] = v22;
    IVP_U_Float_Point::calc_cross_product(this: &v176, v1: &v196, v2: &v195);
    v23 = this->mapping_uRrs_f_Rrs.k[0];
    v184.k[0] = v196.k[0] + v195.k[0];
    v184.k[1] = v196.k[1] + v195.k[1];
    v184.k[2] = v196.k[2] + v195.k[2];
    IVP_U_Matrix3::init_normized3_col(this: &v149, a2: (int)v209, vp: (const IVP_U_Point *)&v184, coordinate: v23);
    IVP_U_Matrix3::transpose3(this: &v149);
    IVP_U_Matrix3::mi2mult3(this: &v149, mb: p_m_world_f_core_last_psi, m_out: &v148);
    IVP_U_Matrix3::mmult3(this: &v148, mb: v17, m_out: &v157);
    IVP_U_Matrix3::vmult3(this: &v162, p_in: &v176, p_out: &v180);
    v24 = this->mapping_uRrs_f_Rrs.k[2];
    v204 = v180.k[this->mapping_uRrs_f_Rrs.k[1]];
    i_delta_time = v180.k[v24];
    IVP_U_Matrix3::vmult3(this: p_m_world_f_core_last_psi, p_in: &v176, p_out: &v175);
    IVP_U_Matrix3::vimult3(this: v17, p_in: &v175, p_out: &v189);
    IVP_U_Matrix3::vmult3(this: &v161, p_in: &v189, p_out: &v177);
    v25 = this->mapping_uRrs_f_Rrs.k[1];
    v26 = v177.k[v25];
    fixed = (IVP_CONSTRAINT_AXIS_TYPE *)(4 * this->mapping_uRrs_f_Rrs.k[2]);
    __libm_sse2_atan2(y: v144, x: v145);
    *(float *)&aligned_row_len = v26;
    v27 = v204;
    __libm_sse2_atan2(y: v144, x: v145);
    v28 = v27;
    v29 = *(float *)&aligned_row_len - v28;
    if ( (float)(*(float *)&aligned_row_len - v28) > 3.1415927 )
      v29 = v29 - 6.2831855;
    if ( v29 < -3.1415927 )
      v29 = v29 + 6.2831855;
    v30 = fixed;
    *(&v199 + this->mapping_uRrs_f_Rrs.k[0]) = v29;
    *(float *)((char *)&v199 + v25 * 4) = 0.0;
    *(float *)((char *)&v199 + (_DWORD)v30) = 0.0;
  }
  else
  {
    IVP_U_Matrix3::mi2mult3(this: &v162, mb: p_m_world_f_core_last_psi, m_out: &v148);
    IVP_U_Matrix3::mmult3(this: &v148, mb: v193, m_out: &v157);
  }
  v31 = this->fixedrot_dim + this->limitedrot_dim;
  switch ( v31 )
  {
    case 3:
      IVP_U_Matrix3::mi2mult3(this: &v157, mb: &v161, m_out: &v169);
      IVP_U_Quat::set_quaternion(this: (IVP_U_Quat *)&v195, mat: &v169);
      v199 = (float)((float)((float)((float)(v195.k[0] * (float)(v195.k[0] * v195.k[0])) * (float)(v195.k[0] * v195.k[0]))
                           * 0.28999999)
                   + (float)((float)((float)(v195.k[0] * (float)(v195.k[0] * v195.k[0])) * 0.12) + v195.k[0]))
           * 2.0;
      *(float *)&v200 = (float)((float)((float)((float)(v195.k[1] * (float)(v195.k[1] * v195.k[1]))
                                              * (float)(v195.k[1] * v195.k[1]))
                                      * 0.28999999)
                              + (float)((float)((float)(v195.k[1] * (float)(v195.k[1] * v195.k[1])) * 0.12) + v195.k[1]))
                      * 2.0;
      *(float *)&v201 = (float)((float)((float)((float)(v195.k[2] * (float)(v195.k[2] * v195.k[2]))
                                              * (float)(v195.k[2] * v195.k[2]))
                                      * 0.28999999)
                              + (float)((float)((float)(v195.k[2] * (float)(v195.k[2] * v195.k[2])) * 0.12) + v195.k[2]))
                      * 2.0;
      if ( v195.hesse_val < 0.0 )
      {
        v199 = (float)((float)((float)((float)((float)(v195.k[0] * (float)(v195.k[0] * v195.k[0]))
                                             * (float)(v195.k[0] * v195.k[0]))
                                     * 0.28999999)
                             + (float)((float)((float)(v195.k[0] * (float)(v195.k[0] * v195.k[0])) * 0.12) + v195.k[0]))
                     * 2.0)
             * -1.0;
        *(float *)&v200 = (float)((float)((float)((float)((float)(v195.k[1] * (float)(v195.k[1] * v195.k[1]))
                                                        * (float)(v195.k[1] * v195.k[1]))
                                                * 0.28999999)
                                        + (float)((float)((float)(v195.k[1] * (float)(v195.k[1] * v195.k[1])) * 0.12)
                                                + v195.k[1]))
                                * 2.0)
                        * -1.0;
        *(float *)&v201 = (float)((float)((float)((float)((float)(v195.k[2] * (float)(v195.k[2] * v195.k[2]))
                                                        * (float)(v195.k[2] * v195.k[2]))
                                                * 0.28999999)
                                        + (float)((float)((float)(v195.k[2] * (float)(v195.k[2] * v195.k[2])) * 0.12)
                                                + v195.k[2]))
                                * 2.0)
                        * -1.0;
      }
      break;
    case 2:
      IVP_U_Matrix3::mi2mult3(this: &v157, mb: &v161, m_out: &v169);
      v32 = this->mapping_uRrs_f_Rrs.k[2];
      v33 = this->mapping_uRrs_f_Rrs.k[1];
      v196.k[0] = v169.rows[0].k[v32];
      v196.k[1] = v169.rows[1].k[v32];
      v196.k[2] = v169.rows[2].k[v32];
      v34 = v196.k[v32];
      v35 = 2 * this->mapping_uRrs_f_Rrs.k[0];
      *(float *)&v201 = 0.0;
      *(float *)&v200 = 0.0;
      v199 = 0.0;
      v33 *= 4;
      v36 = *(_DWORD *)((char *)v196.k + v33);
      i_delta_time = v34;
      LODWORD(v204) = 2 * v35;
      __libm_sse2_atan2(y: v144, x: v145);
      v37 = v204;
      *(_DWORD *)((char *)&v199 + LODWORD(v204)) = v36 ^ _mask__NegFloat_;
      v38 = *(float *)((char *)v196.k + LODWORD(v37));
      __libm_sse2_atan2(y: v144, x: v145);
      *(float *)&v38 = v38;
      *(float *)((char *)&v199 + v33) = *(float *)&v38;
      break;
    case 0:
      *(float *)&v201 = 0.0;
      *(float *)&v200 = 0.0;
      v199 = 0.0;
      break;
    default:
      break;
  }
  memset(&v171, 0, 12);
  IVP_U_Matrix::vimult4(this: p_m_Rfs_f_Rcs, p_in: &v171, p_out: &v178);
  IVP_U_Matrix::vimult4(this: &this->m_Afs_f_Acs, p_in: &v171, p_out: &v173);
  IVP_U_Matrix::vmult4(this: p_m_world_f_core_last_psi, p_in: &v178, p_out: &v170);
  v39 = v193;
  IVP_U_Matrix::vmult4(this: v193, p_in: &v173, p_out: &v165);
  IVP_U_Matrix::vimult4(this: v39, p_in: &v170, p_out: v147);
  v40 = physical_core;
  i_delta_time = es->i_delta_time;
  if ( physical_core != nullptr )
    IVP_Core::get_surface_speed_on_test(
      this: physical_core,
      point_cs: &v178,
      center_speed_ws: &physical_core->speed,
      rot_speed_cs: &physical_core->rot_speed,
      speed_out_ws: &v196);
  else
    memset(&v196, 0, 12);
  if ( v207 != nullptr )
    IVP_Core::get_surface_speed_on_test(
      this: v207,
      point_cs: &v173,
      center_speed_ws: &v207->speed,
      rot_speed_cs: &v207->rot_speed,
      speed_out_ws: &v189);
  else
    memset(&v189, 0, 12);
  IVP_U_Matrix3::vmult3(this: &v159, p_in: &v196, p_out: &v175);
  IVP_U_Matrix3::vmult3(this: &v159, p_in: &v189, p_out: &v184);
  v190.k[0] = v165.k[0] - v170.k[0];
  v190.k[1] = v165.k[1] - v170.k[1];
  v190.k[2] = v165.k[2] - v170.k[2];
  IVP_U_Matrix3::vmult3(this: &v159, p_in: &v190, p_out: &v192);
  v41 = v188;
  v42 = v184.k[1] - v175.k[1];
  v43 = this->fixed[0];
  v44 = v192.k[1];
  v45 = v188 * this->damp_factor_div_force;
  v172[0] = (float)((float)(v184.k[0] - v175.k[0]) * v45) + v192.k[0];
  v180.k[2] = v184.k[2] - v175.k[2];
  v46 = (float)(v184.k[1] - v175.k[1]) * v45;
  v47 = (float)(v184.k[2] - v175.k[2]) * v45;
  v48 = v192.k[2];
  v49 = v46 + v192.k[1];
  v50 = v47 + v192.k[2];
  if ( (v43 & 2) != 0 )
  {
    v51 = this->borderleft_Rfs[0];
    if ( v51 > v172[0] || (v51 = this->borderright_Rfs[0], v172[0] > v51) )
    {
      v172[0] = (float)((float)(v192.k[0] - v51) * this->limited_axis_stiffness)
              + (float)((float)(v184.k[0] - v175.k[0]) * v188);
      v52 = v43 | 1;
    }
    else
    {
      v52 = v43 & 0xFFFFFFFE;
    }
    v48 = v192.k[2];
    v44 = v192.k[1];
    this->fixed[0] = v52;
  }
  v53 = this->fixed[1];
  if ( (v53 & 2) != 0 )
  {
    v54 = this->borderleft_Rfs[1];
    if ( v54 > v49 || (v54 = this->borderright_Rfs[1], v49 > v54) )
    {
      v49 = (float)((float)(v44 - v54) * this->limited_axis_stiffness) + (float)(v42 * v41);
      v55 = v53 | 1;
    }
    else
    {
      v55 = v53 & 0xFFFFFFFE;
    }
    this->fixed[1] = v55;
  }
  v56 = this->fixed[2];
  if ( (v56 & 2) != 0 )
  {
    v57 = this->borderleft_Rfs[2];
    if ( v57 > v50 || (v57 = this->borderright_Rfs[2], v50 > v57) )
    {
      v50 = (float)((float)(v48 - v57) * this->limited_axis_stiffness) + (float)(v180.k[2] * v41);
      v58 = v56 | 1;
    }
    else
    {
      v58 = v56 & 0xFFFFFFFE;
    }
    this->fixed[2] = v58;
  }
  LODWORD(v59) = COERCE_UNSIGNED_INT(this->force_factor * i_delta_time) ^ _mask__NegFloat_;
  v172[0] = v172[0] * v59;
  v172[1] = v49 * v59;
  v172[2] = v50 * v59;
  if ( v40 != nullptr )
  {
    IVP_U_Matrix3::vmult3(this: v191, p_in: &v40->rot_speed, p_out: &v195);
    v41 = v188;
    v60 = 0.0;
  }
  else
  {
    v60 = 0.0;
    memset(&v195, 0, 12);
  }
  if ( v207 != nullptr )
  {
    IVP_U_Matrix3::vmult3(this: &v157, p_in: &v207->rot_speed, p_out: &v185);
    v60 = v185.k[2];
    v61 = v185.k[1];
    v62 = v185.k[0];
    v41 = v188;
  }
  else
  {
    v61 = 0.0;
    v62 = 0.0;
  }
  v63 = v62 - v195.k[0];
  v64 = this->fixed[3];
  v65 = *(float *)&v200;
  v196.k[1] = v61 - v195.k[1];
  v196.k[2] = v60 - v195.k[2];
  v66 = v41 * this->damp_factor_div_force;
  v67 = v63 * v66;
  v68 = (float)(v61 - v195.k[1]) * v66;
  v69 = v196.k[2] * v66;
  v70 = *(float *)&v201;
  v71 = v67 + v199;
  v72 = v68 + *(float *)&v200;
  v73 = v69 + *(float *)&v201;
  if ( (v64 & 2) != 0 )
  {
    v74 = this->borderleft_Rfs[3];
    if ( v74 > v71 || (v74 = this->borderright_Rfs[3], v71 > v74) )
    {
      v71 = (float)((float)(v199 - v74) * this->limited_axis_stiffness) + (float)(v63 * v41);
      v75 = v64 | 1;
    }
    else
    {
      v75 = v64 & 0xFFFFFFFE;
    }
    v70 = *(float *)&v201;
    this->fixed[3] = v75;
  }
  v76 = this->fixed[4];
  if ( (v76 & 2) != 0 )
  {
    v77 = this->borderleft_Rfs[4];
    if ( v77 > v72 || (v77 = this->borderright_Rfs[4], v72 > v77) )
    {
      v72 = (float)((float)(v65 - v77) * this->limited_axis_stiffness) + (float)(v196.k[1] * v41);
      v78 = v76 | 1;
    }
    else
    {
      v78 = v76 & 0xFFFFFFFE;
    }
    this->fixed[4] = v78;
  }
  v79 = this->fixed[5];
  if ( (v79 & 2) != 0 )
  {
    v80 = this->borderleft_Rfs[5];
    if ( v80 > v73 || (v80 = this->borderright_Rfs[5], v73 > v80) )
    {
      v73 = (float)((float)(v70 - v80) * this->limited_axis_stiffness) + (float)(v196.k[2] * v41);
      v81 = v79 | 1;
    }
    else
    {
      v81 = v79 & 0xFFFFFFFE;
    }
    this->fixed[5] = v81;
  }
  force_factor = this->force_factor;
  this->matrix_size = 0;
  this->matrix_size += this->fixed[0] & 1;
  v83 = this->matrix_size + (this->fixed[1] & 1);
  v84 = -(float)(force_factor * i_delta_time);
  this->matrix_size = v83;
  v85 = v83 + (this->fixed[2] & 1);
  this->matrix_size = v85;
  v86 = v85 + (this->fixed[3] & 1);
  this->matrix_size = v86;
  v87 = v86 + (this->fixed[4] & 1);
  this->matrix_size = v87;
  this->matrix_size = v87 + (this->fixed[5] & 1);
  v88 = this->fixedrot_dim == 1;
  v199 = v71 * v84;
  *(float *)&v200 = v72 * v84;
  *(float *)&v201 = v73 * v84;
  if ( v88 )
  {
    v89 = v161.rows[0].k[4 * this->mapping_uRrs_f_Rrs.k[0] + 1];
    v90 = v161.rows[0].k[4 * this->mapping_uRrs_f_Rrs.k[0] + 2];
    v190.k[0] = v161.rows[this->mapping_uRrs_f_Rrs.k[0]].k[0];
    v190.k[1] = v89;
    v190.k[2] = v90;
    IVP_U_Matrix3::vmult3(this: v193, p_in: &v190, p_out: &v180);
    IVP_U_Matrix3::vimult3(this: p_m_world_f_core_last_psi, p_in: &v180, p_out: &v184);
    v91 = (float)((float)(v162.rows[this->mapping_uRrs_f_Rrs.k[0]].k[0] * v184.k[0])
                + (float)(v184.k[1] * v162.rows[0].k[4 * this->mapping_uRrs_f_Rrs.k[0] + 1]))
        + (float)(v184.k[2] * v162.rows[0].k[4 * this->mapping_uRrs_f_Rrs.k[0] + 2]);
    if ( v91 < 1.0 )
    {
      __libm_sse2_acos(x: v144);
      v92 = v91;
    }
    else
    {
      v92 = 0.0;
    }
    v93 = 3.1415927 - COERCE_FLOAT(LODWORD(v92) & _mask__AbsFloat_);
    if ( v93 < 1.0 )
    {
      v199 = v93 * v199;
      *(float *)&v200 = *(float *)&v200 * v93;
      *(float *)&v201 = *(float *)&v201 * v93;
    }
  }
  v94 = 0;
  fixed = this->fixed;
  v205 = &v192;
  do
  {
    if ( (*(_BYTE *)fixed & 1) != 0 )
    {
      memset(&v192, 0, 12);
      v205->k[0] = 1.0;
      v195.k[0] = -v192.k[0];
      v195.k[1] = -v192.k[1];
      v195.k[2] = -v192.k[2];
      IVP_U_Matrix3::vimult3(this: p_m_Rfs_f_Rcs, p_in: &v192, p_out: &v154);
      IVP_U_Matrix3::vimult3(this: &v150, p_in: &v195, p_out: &v166);
      IVP_U_Matrix3::vimult3(this: &v159, p_in: &v192, p_out: &v152);
      IVP_U_Matrix3::vimult3(this: &v159, p_in: &v195, p_out: &v164);
      if ( physical_core == nullptr || (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) != 0 )
      {
        memset(&v185, 0, 12);
        memset(&v196, 0, 12);
      }
      else
      {
        IVP_Core::test_push_core(
          this: physical_core,
          point_cs: &v178,
          impulse_in_core: &v154,
          impulse_in_world: &v152,
          speed_out: &v185,
          rot_out: &v196);
      }
      if ( v207 == nullptr || (*(_BYTE *)&v207->IVP_Core_Fast_Static & 2) != 0 )
      {
        memset(&v175, 0, 12);
        memset(&v189, 0, 12);
      }
      else
      {
        IVP_Core::test_push_core(
          this: v207,
          point_cs: &v173,
          impulse_in_core: &v166,
          impulse_in_world: &v164,
          speed_out: &v175,
          rot_out: &v189);
      }
      if ( physical_core != nullptr )
        IVP_Core::get_surface_speed_on_test(
          this: physical_core,
          point_cs: &v178,
          center_speed_ws: &v185,
          rot_speed_cs: &v196,
          speed_out_ws: &v184);
      else
        memset(&v184, 0, 12);
      if ( v207 != nullptr )
        IVP_Core::get_surface_speed_on_test(
          this: v207,
          point_cs: &v173,
          center_speed_ws: &v175,
          rot_speed_cs: &v189,
          speed_out_ws: &v190);
      else
        memset(&v190, 0, 12);
      IVP_U_Matrix3::vmult3(this: &v159, p_in: &v184, p_out: &v177);
      IVP_U_Matrix3::vmult3(this: &v159, p_in: &v190, p_out: &v174);
      v95 = v191;
      v167[v94 / 4 + 4] = v174.k[0] - v177.k[0];
      *(float *)&v168[v94] = v174.k[1] - v177.k[1];
      *(float *)&v168[v94 + 4] = v174.k[2] - v177.k[2];
      IVP_U_Matrix3::vmult3(this: v95, p_in: &v196, p_out: &v180);
      IVP_U_Matrix3::vmult3(this: &v157, p_in: &v189, p_out: &v176);
      v147[v94 / 0x10 + 1].k[0] = v176.k[0] - v180.k[0];
      v147[v94 / 0x10 + 1].k[1] = v176.k[1] - v180.k[1];
      v147[v94 / 0x10 + 1].k[2] = v176.k[2] - v180.k[2];
    }
    ++fixed;
    v205 = (IVP_U_Float_Point *)((char *)v205 + 4);
    v94 += 16;
  }
  while ( (int)v94 < 48 );
  fixed = (IVP_CONSTRAINT_AXIS_TYPE *)&v185;
  v96 = &this->fixed[3];
  aligned_row_len = &this->fixed[3];
  for ( i = 0; (int)i < 48; i += 16 )
  {
    if ( (*(_BYTE *)v96 & 1) != 0 )
    {
      memset(&v185, 0, 12);
      *fixed = 1065353216;
      v180.k[0] = -v185.k[0];
      v180.k[1] = -v185.k[1];
      v180.k[2] = -v185.k[2];
      IVP_U_Matrix3::vimult3(this: v191, p_in: &v185, p_out: &v166);
      IVP_U_Matrix3::vimult3(this: &v157, p_in: &v180, p_out: &v164);
      if ( physical_core == nullptr || (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) != 0 )
      {
        v98 = 0.0;
        v99 = 0.0;
        memset(&v192, 0, 12);
      }
      else
      {
        IVP_Core::test_rot_push_core_multiple_cs(
          this: physical_core,
          normized_core_axis: &v166,
          rot_impulse: 1.0,
          delta_rot_speed_out: &v192);
        v98 = v192.k[2];
        v99 = v192.k[1];
      }
      v100 = v207;
      if ( v207 == nullptr || (*(_BYTE *)&v207->IVP_Core_Fast_Static & 2) != 0 )
      {
        v101 = 0.0;
        v102 = 0.0;
        memset(&v195, 0, 12);
      }
      else
      {
        IVP_Core::test_rot_push_core_multiple_cs(
          this: v207,
          normized_core_axis: &v164,
          rot_impulse: 1.0,
          delta_rot_speed_out: &v195);
        v98 = v192.k[2];
        v99 = v192.k[1];
        v101 = v195.k[2];
        v102 = v195.k[1];
        v100 = v207;
      }
      if ( physical_core != nullptr )
      {
        v189.k[0] = (float)(v178.k[2] * v99) - (float)(v178.k[1] * v98);
        v189.k[1] = (float)(v98 * v178.k[0]) - (float)(v178.k[2] * v192.k[0]);
        v189.k[2] = (float)(v178.k[1] * v192.k[0]) - (float)(v99 * v178.k[0]);
      }
      else
      {
        memset(&v189, 0, 12);
      }
      if ( v100 != nullptr )
      {
        v196.k[0] = (float)(v173.k[2] * v102) - (float)(v173.k[1] * v101);
        v196.k[1] = (float)(v101 * v173.k[0]) - (float)(v173.k[2] * v195.k[0]);
        v196.k[2] = (float)(v173.k[1] * v195.k[0]) - (float)(v102 * v173.k[0]);
      }
      else
      {
        memset(&v196, 0, 12);
      }
      IVP_U_Matrix3::vmult3(this: p_m_Rfs_f_Rcs, p_in: &v189, p_out: &v177);
      IVP_U_Matrix3::vmult3(this: &v150, p_in: &v196, p_out: &v176);
      v169.rows[i / 0x10].k[0] = v176.k[0] - v177.k[0];
      v169.rows[0].k[i / 4 + 1] = v176.k[1] - v177.k[1];
      v103 = v191;
      v169.rows[0].k[i / 4 + 2] = v176.k[2] - v177.k[2];
      IVP_U_Matrix3::vmult3(this: v103, p_in: &v192, p_out: &v190);
      IVP_U_Matrix3::vmult3(this: &v157, p_in: &v195, p_out: &v174);
      v147[i / 0x10 + 4].k[0] = v174.k[0] - v190.k[0];
      v147[i / 0x10 + 4].k[1] = v174.k[1] - v190.k[1];
      v147[i / 0x10 + 4].k[2] = v174.k[2] - v190.k[2];
    }
    ++fixed;
    v96 = ++aligned_row_len;
  }
  IVP_Great_Matrix_Many_Zero::IVP_Great_Matrix_Many_Zero(this: &v179);
  matrix_size = this->matrix_size;
  v179.columns = matrix_size;
  v179.aligned_row_len = (matrix_size + 3) & 0xFFFFFFFC;
  aligned_row_len = (IVP_CONSTRAINT_AXIS_TYPE *)v179.aligned_row_len;
  v179.MATRIX_EPS = 9.9999997e-10;
  v105 = alloca(4 * v179.aligned_row_len * matrix_size + 12);
  v179.matrix_values = (float *)&v144;
  v182 = 4 * v179.aligned_row_len;
  v106 = alloca(4 * v179.aligned_row_len);
  v179.result_vector = (float *)&v144;
  v107 = alloca(4 * v179.aligned_row_len);
  v179.desired_vector = (float *)&v144;
  IVP_Great_Matrix_Many_Zero::align_matrix_values(this: &v179);
  v108 = 0.0;
  v205 = nullptr;
  v204 = 0.0;
  fixed = (IVP_CONSTRAINT_AXIS_TYPE *)v168;
  v183 = COERCE_FLOAT(&v197);
  do
  {
    if ( (this->fixed[LODWORD(v108)] & 1) != 0 )
    {
      v109 = 0;
      if ( (this->fixed[0] & 1) != 0 )
      {
        v179.matrix_values[(_DWORD)v205] = *((float *)fixed - 1);
        v109 = 1;
      }
      if ( (this->fixed[1] & 1) != 0 )
      {
        v110 = (char *)v205 + (_DWORD)aligned_row_len * v109++;
        v179.matrix_values[(_DWORD)v110] = *(float *)fixed;
      }
      if ( (this->fixed[2] & 1) != 0 )
      {
        v111 = (char *)v205 + (_DWORD)aligned_row_len * v109++;
        v179.matrix_values[(_DWORD)v111] = *((float *)fixed + 1);
      }
      v112 = 3;
      v113 = 4 * ((_DWORD)v205 + (_DWORD)aligned_row_len * v109);
      v114 = &this->fixed[3];
      do
      {
        if ( (*(_BYTE *)v114 & 1) != 0 )
        {
          *(float *)((char *)v179.matrix_values + v113) = v147[LODWORD(v108)].k[v112 + 1];
          v113 += v182;
          v108 = v204;
        }
        ++v112;
        ++v114;
      }
      while ( v112 < 6 );
      if ( SLODWORD(v108) >= 3 )
        v179.desired_vector[(_DWORD)v205] = *(float *)(LODWORD(v183) + 4 * LODWORD(v108) - 3);
      else
        v179.desired_vector[(_DWORD)v205] = v172[LODWORD(v108)];
      v205 = (IVP_U_Float_Point *)((char *)v205 + 1);
    }
    fixed += 4;
    ++LODWORD(v108);
    v204 = v108;
  }
  while ( SLODWORD(v108) < 6 );
  if ( IVP_Great_Matrix_Many_Zero::solve_great_matrix_many_zero(this: &v179) != 0 )
  {
    v115 = 0.0;
    v116 = 0;
    v117 = this->fixed[0] & 1;
    if ( v117 != 0 )
      v118 = *v179.result_vector;
    else
      v118 = 0.0;
    v181.k[0] = v118;
    if ( v117 != 0 )
      v116 = 1;
    v119 = this->fixed[1] & 1;
    if ( v119 != 0 )
      v120 = v179.result_vector[v116];
    else
      v120 = 0.0;
    v181.k[1] = v120;
    if ( v119 != 0 )
      ++v116;
    v121 = this->fixed[2] & 1;
    if ( v121 != 0 )
      v122 = v179.result_vector[v116];
    else
      v122 = 0.0;
    v181.k[2] = v122;
    if ( v121 != 0 )
      ++v116;
    v123 = this->fixed[3] & 1;
    if ( v123 != 0 )
      v186.k[0] = v179.result_vector[v116];
    else
      v186.k[0] = 0.0;
    if ( v123 != 0 )
      ++v116;
    v124 = this->fixed[4] & 1;
    if ( v124 != 0 )
      v125 = v179.result_vector[v116];
    else
      v125 = 0.0;
    v186.k[1] = v125;
    if ( v124 != 0 )
      ++v116;
    if ( (this->fixed[5] & 1) != 0 )
      v115 = v179.result_vector[v116];
    maxforce = this->maxforce;
    v186.k[2] = v115;
    memset(&v179.matrix_values, 0, 12);
    if ( maxforce == nullptr )
      goto LABEL_194;
    v127 = *((char *)this + 300);
    v182 = v127;
    v128 = fabs(v118);
    if ( v127 != 0 )
    {
      if ( v127 == 1 )
      {
        v131 = fabs(v120);
        v132 = fabs(v122);
        v183 = (float)((float)((float)(v131 / maxforce->halfimpulse[1]) * (float)(v131 / maxforce->halfimpulse[1]))
                     + (float)((float)(v128 / maxforce->halfimpulse[0]) * (float)(v128 / maxforce->halfimpulse[0])))
             + (float)((float)(v132 / maxforce->halfimpulse[2]) * (float)(v132 / maxforce->halfimpulse[2]));
        v133 = (float)((float)(v183 * i_delta_time) * i_delta_time) >= 1.0;
        goto LABEL_177;
      }
      if ( maxforce->halfimpulse[0] <= v128
        || maxforce->halfimpulse[1] <= fabs(v120)
        || maxforce->halfimpulse[2] <= fabs(v122)
        || maxforce->halfimpulse[3] <= fabs(v186.k[0])
        || maxforce->halfimpulse[4] <= fabs(v125) )
      {
LABEL_178:
        v134 = &maxforce->halfimpulse[3];
        v135 = 1.0;
        v200 = 0x10000;
        v201 = 2;
        v202 = 1;
        v136 = &v200;
        for ( j = 0; j < 3; ++j )
        {
          v204 = 1.0;
          if ( v182 != 0 )
          {
            if ( v182 == 1 )
            {
              v138 = (float)((float)(fabs(v181.k[*((__int16 *)v136 + 1)]) * 0.41493773) + fabs(v181.k[*(__int16 *)v136]))
                   + (float)(fabs(v181.k[*((__int16 *)v136 + 2)]) * 0.41493773);
            }
            else
            {
              v138 = fabs(v181.k[j]);
              v204 = fabs(v186.k[j]);
            }
          }
          else
          {
            v138 = (float)(fabs(v120) + v128) + fabs(v122);
          }
          v139 = *(v134 - 3);
          if ( v138 > v139 )
          {
            if ( *((_DWORD *)v134 + 3) == 1 )
            {
              v141 = (float)(v139 * v188) / v138;
              if ( v135 > v141 )
                v135 = v141;
            }
            else if ( *((_DWORD *)v134 + 3) == 2 )
            {
              goto LABEL_187;
            }
          }
          if ( (float)(*v134 / v204) < 1.0 && *((_DWORD *)v134 + 6) == 2 )
          {
LABEL_187:
            environment = IVP_Constraint::get_environment(this);
            IVP_Environment::fire_event_constraint_broken(this: environment, constraint: this);
            IVP_Constraint::deactivate(this);
            return;
          }
          v136 = (int *)((char *)v136 + 2);
          ++v134;
        }
        v181.k[0] = v135 * v181.k[0];
        v120 = v120 * v135;
        v122 = v122 * v135;
        v186.k[0] = v135 * v186.k[0];
        v181.k[1] = v120;
        v181.k[2] = v122;
        v186.k[1] = v135 * v186.k[1];
        v186.k[2] = v135 * v186.k[2];
        goto LABEL_194;
      }
      v129 = maxforce->halfimpulse[5];
      v130 = fabs(v115);
    }
    else
    {
      v130 = (float)((float)(fabs(v120) / maxforce->halfimpulse[1]) + (float)(v128 / maxforce->halfimpulse[0]))
           + (float)(fabs(v122) / maxforce->halfimpulse[2]);
      v129 = 3.0;
    }
    v133 = v129 <= v130;
LABEL_177:
    if ( v133 )
      goto LABEL_178;
LABEL_194:
    v163.k[0] = -v181.k[0];
    v167[0] = -v186.k[0];
    v167[1] = -v186.k[1];
    v163.k[1] = -v120;
    v163.k[2] = -v122;
    v167[2] = -v186.k[2];
    IVP_U_Matrix3::vimult3(this: p_m_Rfs_f_Rcs, p_in: &v181, p_out: &v160);
    IVP_U_Matrix3::vimult3(this: &v150, p_in: &v163, p_out: &v158);
    IVP_U_Matrix3::vmult3(this: p_m_world_f_core_last_psi, p_in: &v160, p_out: &v153);
    IVP_U_Matrix3::vmult3(this: v193, p_in: &v158, p_out: &v155);
    IVP_U_Matrix3::vimult3(this: v191, p_in: &v186, p_out: &v151);
    IVP_U_Matrix3::vimult3(this: &v157, p_in: (const IVP_U_Float_Point *)v167, p_out: &v156);
    v142 = physical_core;
    if ( physical_core != nullptr && (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) == 0 )
    {
      IVP_Core::push_core(this: physical_core, point_cs: &v178, impulse_in_core: &v160, impulse_in_world: &v153);
      IVP_Core::rot_push_core_cs(this: v142, rot_impulse_cs: &v151);
    }
    v143 = v207;
    if ( v207 != nullptr && (*(_BYTE *)&v207->IVP_Core_Fast_Static & 2) == 0 )
    {
      IVP_Core::push_core(this: v207, point_cs: &v173, impulse_in_core: &v158, impulse_in_world: &v155);
      IVP_Core::rot_push_core_cs(this: v143, rot_impulse_cs: &v156);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8C30
// Name: public: virtual void IVP_Constraint_Local::change_fixing_point_Ros(class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Constraint_Local::change_fixing_point_Ros(
        IVP_Constraint_Local *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Point *anchor)
{
  IVP_Real_Object *object; // ecx
  IVP_Real_Object *v5; // ecx
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  _BYTE v10[12]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Matrix m_Rcs_f_Ros; // [esp+0h] [ebp-60h] BYREF
  IVP_U_Point point_Rcs_f_nRfs; // [esp+40h] [ebp-20h] BYREF
  IVP_U_Point point_Rfs_f_nRfs; // [esp+50h] [ebp-10h]
  float retaddr; // [esp+60h] [ebp+0h]

  point_Rfs_f_nRfs.k[1] = a2;
  point_Rfs_f_nRfs.k[2] = retaddr;
  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  v5 = this->m_Rfs_f_Rcs.object;
  if ( v5 != nullptr )
    IVP_Real_Object::calc_m_core_f_object(this: v5, m_core_f_object: (IVP_U_Matrix *)v10);
  else
    IVP_U_Matrix::init(this: (IVP_U_Matrix *)v10);
  IVP_U_Matrix::vmult4(this: (IVP_U_Matrix *)v10, p_in: anchor, p_out: (IVP_U_Float_Point *)&m_Rcs_f_Ros.vv.k[1]);
  IVP_U_Matrix::vmult4(
    this: &this->m_Rfs_f_Rcs,
    p_in: (const IVP_U_Float_Point *)&m_Rcs_f_Ros.vv.k[1],
    p_out: (IVP_U_Point *)&point_Rcs_f_nRfs.k[1]);
  v6 = this->m_Rfs_f_Rcs.vv.k[0] - point_Rcs_f_nRfs.k[1];
  v7 = this->m_Rfs_f_Rcs.vv.k[1] - point_Rcs_f_nRfs.k[2];
  this->m_Rfs_f_Rcs.vv.k[2] = this->m_Rfs_f_Rcs.vv.k[2] - point_Rcs_f_nRfs.hesse_val;
  this->m_Rfs_f_Rcs.vv.k[0] = v6;
  this->m_Rfs_f_Rcs.vv.k[1] = v7;
  v8 = this->m_Afs_f_Acs.vv.k[0] - point_Rcs_f_nRfs.k[1];
  this->m_Afs_f_Acs.vv.k[1] = this->m_Afs_f_Acs.vv.k[1] - point_Rcs_f_nRfs.k[2];
  v9 = this->m_Afs_f_Acs.vv.k[2] - point_Rcs_f_nRfs.hesse_val;
  this->m_Afs_f_Acs.vv.k[0] = v8;
  this->m_Afs_f_Acs.vv.k[2] = v9;
}

//------------------------------------------------------------------------------
// Address: 0x100A8D30
// Name: public: virtual void IVP_Constraint_Local::change_target_fixing_point_Ros(class IVP_U_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Constraint_Local::change_target_fixing_point_Ros(
        IVP_Constraint_Local *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Point *anchor)
{
  IVP_Real_Object *object; // ecx
  IVP_Real_Object *v5; // ecx
  _BYTE v6[12]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Matrix m_Rcs_f_Ros; // [esp+0h] [ebp-60h] BYREF
  IVP_U_Point point_Rcs_f_nRfs; // [esp+40h] [ebp-20h] BYREF
  IVP_U_Point point_Rfs_f_nRfs; // [esp+50h] [ebp-10h]
  float retaddr; // [esp+60h] [ebp+0h]

  point_Rfs_f_nRfs.k[1] = a2;
  point_Rfs_f_nRfs.k[2] = retaddr;
  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  v5 = this->m_Rfs_f_Rcs.object;
  if ( v5 != nullptr )
    IVP_Real_Object::calc_m_core_f_object(this: v5, m_core_f_object: (IVP_U_Matrix *)v6);
  else
    IVP_U_Matrix::init(this: (IVP_U_Matrix *)v6);
  IVP_U_Matrix::vmult4(this: (IVP_U_Matrix *)v6, p_in: anchor, p_out: (IVP_U_Float_Point *)&m_Rcs_f_Ros.vv.k[1]);
  IVP_U_Matrix::vmult4(
    this: &this->m_Rfs_f_Rcs,
    p_in: (const IVP_U_Float_Point *)&m_Rcs_f_Ros.vv.k[1],
    p_out: (IVP_U_Point *)&point_Rcs_f_nRfs.k[1]);
  this->m_Rfs_f_Rcs.vv.k[0] = this->m_Rfs_f_Rcs.vv.k[0] - point_Rcs_f_nRfs.k[1];
  this->m_Rfs_f_Rcs.vv.k[1] = this->m_Rfs_f_Rcs.vv.k[1] - point_Rcs_f_nRfs.k[2];
  this->m_Rfs_f_Rcs.vv.k[2] = this->m_Rfs_f_Rcs.vv.k[2] - point_Rcs_f_nRfs.hesse_val;
}

//------------------------------------------------------------------------------
// Address: 0x100A8DF0
// Name: public: virtual void IVP_Constraint_Local::change_translation_axes_Ros(class IVP_U_Matrix3 const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge IVP_Constraint_Local::change_translation_axes_Ros(
        IVP_Constraint_Local *this@<ecx>,
        int a2@<ebp>,
        const IVP_U_Matrix3 *trans_axes)
{
  IVP_Real_Object *object; // ecx
  IVP_Real_Object *v5; // ecx
  IVP_Constraint_Local_Anchor *p_m_Afs_f_Acs; // esi
  IVP_U_Point *p_vv; // edi
  _BYTE v8[12]; // [esp-Ch] [ebp-ECh] BYREF
  IVP_U_Matrix3 m_Rfs_f_nRfs; // [esp+0h] [ebp-E0h] BYREF
  IVP_U_Matrix m_Rcs_f_Ros; // [esp+30h] [ebp-B0h] BYREF
  IVP_U_Matrix3 m_Rcs_f_nRfs; // [esp+70h] [ebp-70h] BYREF
  _BYTE tmp_4[56]; // [esp+A4h] [ebp-3Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+E0h] [ebp+0h]

  *(_DWORD *)&tmp_4[48] = a2;
  *(_DWORD *)&tmp_4[52] = retaddr;
  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  v5 = this->m_Rfs_f_Rcs.object;
  if ( v5 != nullptr )
    IVP_Real_Object::calc_m_core_f_object(this: v5, m_core_f_object: (IVP_U_Matrix *)&m_Rfs_f_nRfs.rows[2].k[1]);
  else
    IVP_U_Matrix::init(this: (IVP_U_Matrix *)&m_Rfs_f_nRfs.rows[2].k[1]);
  IVP_U_Matrix3::mmult3(
    this: (IVP_U_Matrix3 *)&m_Rfs_f_nRfs.rows[2].k[1],
    mb: trans_axes,
    m_out: (IVP_U_Matrix *)&m_Rcs_f_Ros.vv.k[1]);
  IVP_U_Matrix3::mmult3(this: &this->m_Rfs_f_Rcs, mb: (IVP_U_Matrix *)&m_Rcs_f_Ros.vv.k[1], m_out: (IVP_U_Matrix3 *)v8);
  IVP_U_Matrix3::set_transpose3(this: &this->m_Rfs_f_Rcs, in: (IVP_U_Matrix *)&m_Rcs_f_Ros.vv.k[1]);
  p_m_Afs_f_Acs = &this->m_Afs_f_Acs;
  IVP_U_Matrix3::mimult3(this: (IVP_U_Matrix3 *)v8, mb: &this->m_Afs_f_Acs, m_out: (IVP_U_Matrix3 *)tmp_4);
  p_vv = &this->m_Afs_f_Acs.vv;
  IVP_U_Matrix3::vimult3(this: p_m_Afs_f_Acs, p_in: p_vv, p_out: (IVP_U_Float_Point *)&m_Rcs_f_nRfs.rows[2].k[1]);
  IVP_U_Matrix3::vmult3(
    this: (IVP_U_Matrix3 *)tmp_4,
    p_in: (const IVP_U_Float_Point *)&m_Rcs_f_nRfs.rows[2].k[1],
    p_out: p_vv);
  qmemcpy(p_m_Afs_f_Acs, tmp_4, 48);
}

//------------------------------------------------------------------------------
// Address: 0x100A8F00
// Name: public: virtual void IVP_Constraint_Local::change_target_translation_axes_Ros(class IVP_U_Matrix3 const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Constraint_Local::change_target_translation_axes_Ros(
        IVP_Constraint_Local *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Matrix3 *trans_axes)
{
  IVP_Real_Object *object; // ecx
  IVP_Real_Object *v5; // ecx
  _BYTE v6[12]; // [esp-Ch] [ebp-7Ch] BYREF
  IVP_U_Matrix m_Rcs_f_Ros; // [esp+0h] [ebp-70h] BYREF
  IVP_U_Matrix3 m_Rcs_f_nRfs; // [esp+40h] [ebp-30h]
  float retaddr; // [esp+70h] [ebp+0h]

  m_Rcs_f_nRfs.rows[2].k[1] = a2;
  m_Rcs_f_nRfs.rows[2].k[2] = retaddr;
  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  v5 = this->m_Rfs_f_Rcs.object;
  if ( v5 != nullptr )
    IVP_Real_Object::calc_m_core_f_object(this: v5, m_core_f_object: (IVP_U_Matrix *)v6);
  else
    IVP_U_Matrix::init(this: (IVP_U_Matrix *)v6);
  IVP_U_Matrix3::mmult3(this: (IVP_U_Matrix3 *)v6, mb: trans_axes, m_out: (IVP_U_Matrix *)&m_Rcs_f_Ros.vv.k[1]);
  IVP_U_Matrix3::set_transpose3(this: &this->m_Rfs_f_Rcs, in: (IVP_U_Matrix *)&m_Rcs_f_Ros.vv.k[1]);
}

//------------------------------------------------------------------------------
// Address: 0x100A8F80
// Name: public: virtual void IVP_Constraint_Local::change_rotation_axes_Ros(class IVP_U_Matrix3 const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge IVP_Constraint_Local::change_rotation_axes_Ros(
        IVP_Constraint_Local *this@<ecx>,
        int a2@<ebp>,
        const IVP_U_Matrix3 *rot_axes)
{
  IVP_Real_Object *object; // ecx
  IVP_U_Matrix3 *v5; // eax
  IVP_Real_Object *v6; // ecx
  IVP_U_Matrix3 *rot; // eax
  _BYTE v8[12]; // [esp-Ch] [ebp-10Ch] BYREF
  IVP_U_Matrix3 m_Rcs_f_nRrs; // [esp+0h] [ebp-100h] BYREF
  IVP_U_Matrix m_Rcs_f_Ros; // [esp+30h] [ebp-D0h] BYREF
  _BYTE m_Rrs_f_nRrs_36[104]; // [esp+94h] [ebp-6Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+100h] [ebp+0h]

  *(_DWORD *)&m_Rrs_f_nRrs_36[96] = a2;
  *(_DWORD *)&m_Rrs_f_nRrs_36[100] = retaddr;
  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  if ( this->m_Rfs_f_Rcs.rot == nullptr )
  {
    v5 = (IVP_U_Matrix3 *)p_malloc(size: 0x30u);
    this->m_Rfs_f_Rcs.rot = v5;
    IVP_U_Matrix3::init3(this: v5);
  }
  v6 = this->m_Rfs_f_Rcs.object;
  if ( v6 != nullptr )
    IVP_Real_Object::calc_m_core_f_object(this: v6, m_core_f_object: (IVP_U_Matrix *)&m_Rcs_f_nRrs.rows[2].k[1]);
  else
    IVP_U_Matrix::init(this: (IVP_U_Matrix *)&m_Rcs_f_nRrs.rows[2].k[1]);
  IVP_U_Matrix3::mmult3(this: (IVP_U_Matrix3 *)&m_Rcs_f_nRrs.rows[2].k[1], mb: rot_axes, m_out: (IVP_U_Matrix3 *)v8);
  IVP_U_Matrix3::mmult3(
    this: this->m_Rfs_f_Rcs.rot,
    mb: (const IVP_U_Matrix3 *)v8,
    m_out: (IVP_U_Matrix *)&m_Rcs_f_Ros.vv.k[1]);
  IVP_U_Matrix3::mimult3(
    this: (IVP_U_Matrix *)&m_Rcs_f_Ros.vv.k[1],
    mb: this->m_Rfs_f_Rcs.rot,
    m_out: (IVP_U_Matrix3 *)&m_Rrs_f_nRrs_36[48]);
  rot = this->m_Rfs_f_Rcs.rot;
  *(_QWORD *)rot->rows[0].k = *(_QWORD *)&m_Rrs_f_nRrs_36[48];
  *(_QWORD *)&rot->rows[0].k[2] = *(_QWORD *)&m_Rrs_f_nRrs_36[56];
  *(_QWORD *)rot->rows[1].k = *(_QWORD *)&m_Rrs_f_nRrs_36[64];
  *(_QWORD *)&rot->rows[1].k[2] = *(_QWORD *)&m_Rrs_f_nRrs_36[72];
  *(_QWORD *)rot->rows[2].k = *(_QWORD *)&m_Rrs_f_nRrs_36[80];
  *(_QWORD *)&rot->rows[2].k[2] = *(_QWORD *)&m_Rrs_f_nRrs_36[88];
  IVP_U_Matrix3::mimult3(
    this: (IVP_U_Matrix *)&m_Rcs_f_Ros.vv.k[1],
    mb: this->m_Afs_f_Acs.rot,
    m_out: (IVP_U_Matrix3 *)m_Rrs_f_nRrs_36);
  qmemcpy(this->m_Afs_f_Acs.rot, m_Rrs_f_nRrs_36, sizeof(IVP_U_Matrix3));
}

//------------------------------------------------------------------------------
// Address: 0x100A90E0
// Name: public: virtual void IVP_Constraint_Local::change_target_rotation_axes_Ros(class IVP_U_Matrix3 const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge IVP_Constraint_Local::change_target_rotation_axes_Ros(
        IVP_Constraint_Local *this@<ecx>,
        int a2@<ebp>,
        const IVP_U_Matrix3 *rot_axes)
{
  IVP_Real_Object *object; // ecx
  IVP_Real_Object *v5; // ecx
  _BYTE v6[12]; // [esp-Ch] [ebp-7Ch] BYREF
  _BYTE m_Rcs_f_Ros_52[56]; // [esp+34h] [ebp-3Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+70h] [ebp+0h]

  *(_DWORD *)&m_Rcs_f_Ros_52[48] = a2;
  *(_DWORD *)&m_Rcs_f_Ros_52[52] = retaddr;
  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  if ( this->m_Rfs_f_Rcs.rot == nullptr )
    this->m_Rfs_f_Rcs.rot = (IVP_U_Matrix3 *)p_malloc(size: 0x30u);
  v5 = this->m_Rfs_f_Rcs.object;
  if ( v5 != nullptr )
    IVP_Real_Object::calc_m_core_f_object(this: v5, m_core_f_object: (IVP_U_Matrix *)v6);
  else
    IVP_U_Matrix::init(this: (IVP_U_Matrix *)v6);
  IVP_U_Matrix3::mmult3(this: (IVP_U_Matrix3 *)v6, mb: rot_axes, m_out: (IVP_U_Matrix3 *)m_Rcs_f_Ros_52);
  qmemcpy(this->m_Rfs_f_Rcs.rot, m_Rcs_f_Ros_52, sizeof(IVP_U_Matrix3));
  IVP_U_Matrix3::transpose3(this: this->m_Rfs_f_Rcs.rot);
}

//------------------------------------------------------------------------------
// Address: 0x100A91B0
// Name: public: virtual void IVP_Constraint_Local::change_Aos_to_relaxe_constraint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall IVP_Constraint_Local::change_Aos_to_relaxe_constraint(IVP_Constraint_Local *this@<ecx>, float a2@<ebp>)
{
  IVP_Real_Object *object; // ecx
  IVP_U_Matrix3 *rot; // ecx
  _BYTE v5[12]; // [esp-Ch] [ebp-4Ch] BYREF
  IVP_U_Matrix m_Rcs_f_Acs; // [esp+0h] [ebp-40h]
  float retaddr; // [esp+40h] [ebp+0h]

  m_Rcs_f_Acs.vv.k[1] = a2;
  m_Rcs_f_Acs.vv.k[2] = retaddr;
  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  IVP_U_Matrix::mimult4(
    this: &this->m_Rfs_f_Rcs.object->physical_core->m_world_f_core_last_psi,
    mb: &this->m_Afs_f_Acs.object->physical_core->m_world_f_core_last_psi,
    m_out: (IVP_U_Matrix *)v5);
  IVP_U_Matrix::mmult4(this: &this->m_Rfs_f_Rcs, mb: (const IVP_U_Matrix *)v5, m_out: &this->m_Afs_f_Acs);
  rot = this->m_Rfs_f_Rcs.rot;
  if ( rot != nullptr )
    IVP_U_Matrix3::mmult3(this: rot, mb: (const IVP_U_Matrix3 *)v5, m_out: this->m_Afs_f_Acs.rot);
  else
    this->m_Afs_f_Acs.rot = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A9260
// Name: public: virtual void IVP_Constraint_Local::change_Ros_to_relaxe_constraint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall IVP_Constraint_Local::change_Ros_to_relaxe_constraint(IVP_Constraint_Local *this@<ecx>, float a2@<ebp>)
{
  IVP_Real_Object *object; // ecx
  IVP_U_Matrix3 *rot; // ecx
  _BYTE v5[12]; // [esp-Ch] [ebp-4Ch] BYREF
  IVP_U_Matrix m_Acs_f_Rcs; // [esp+0h] [ebp-40h]
  float retaddr; // [esp+40h] [ebp+0h]

  m_Acs_f_Rcs.vv.k[1] = a2;
  m_Acs_f_Rcs.vv.k[2] = retaddr;
  object = this->m_Rfs_f_Rcs.object;
  if ( object == nullptr )
    object = this->m_Afs_f_Acs.object;
  IVP_Real_Object::ensure_in_simulation(this: object);
  IVP_U_Matrix::mimult4(
    this: &this->m_Afs_f_Acs.object->physical_core->m_world_f_core_last_psi,
    mb: &this->m_Rfs_f_Rcs.object->physical_core->m_world_f_core_last_psi,
    m_out: (IVP_U_Matrix *)v5);
  IVP_U_Matrix::mmult4(this: &this->m_Afs_f_Acs, mb: (const IVP_U_Matrix *)v5, m_out: &this->m_Rfs_f_Rcs);
  rot = this->m_Afs_f_Acs.rot;
  if ( rot != nullptr )
    IVP_U_Matrix3::mmult3(this: rot, mb: (const IVP_U_Matrix3 *)v5, m_out: this->m_Rfs_f_Rcs.rot);
  else
    this->m_Rfs_f_Rcs.rot = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A9310
// Name: private: void IVP_Constraint_Local::init(class IVP_Template_Constraint const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge IVP_Constraint_Local::init(
        IVP_Constraint_Local *this@<ecx>,
        IVP_Real_Object *a2@<ebp>,
        const IVP_Template_Constraint *tmpl)
{
  IVP_Constraint_Local *v3; // esi
  const IVP_Template_Constraint *v4; // edi
  IVP_Real_Object *v5; // ecx
  IVP_Real_Object *v6; // edx
  IVP_U_Matrix3 *physical_core; // eax
  bool v8; // zf
  IVP_U_Matrix3 *v9; // eax
  IVP_U_Matrix *m_Ros_f_Rfs; // eax
  const IVP_U_Matrix *m_Aos_f_Afs; // eax
  IVP_U_Matrix3 *v12; // eax
  IVP_U_Matrix3 *v13; // eax
  IVP_Real_Object *v14; // edx
  IVP_Constraint_Local *v15; // ecx
  float force_factor; // xmm0_4
  BOOL v17; // eax
  unsigned __int8 *v18; // eax
  IVP_Constraint_Local_MaxImpulse *v19; // eax
  int v20; // edx
  float *maximpulse_type; // eax
  _BYTE v22[12]; // [esp+14h] [ebp-20Ch] BYREF
  IVP_U_Matrix m_Rcs_f_Acs; // [esp+20h] [ebp-200h] BYREF
  IVP_U_Matrix m_Rcs_f_Aos; // [esp+60h] [ebp-1C0h] BYREF
  IVP_U_Matrix m_Ros_f_Aos; // [esp+A0h] [ebp-180h] BYREF
  IVP_U_Matrix3 m_fs_f_rs; // [esp+E0h] [ebp-140h] BYREF
  IVP_U_Matrix m_ws_f_Aos; // [esp+110h] [ebp-110h] BYREF
  IVP_U_Matrix m_ws_f_Ros; // [esp+150h] [ebp-D0h] BYREF
  _BYTE m_Acs_f_Aos_52[76]; // [esp+1C4h] [ebp-5Ch] OVERLAPPED BYREF
  int p_m_Rfs_f_Rcs; // [esp+210h] [ebp-10h]
  IVP_Real_Object *objectR; // [esp+214h] [ebp-Ch]
  IVP_Real_Object *objectA; // [esp+218h] [ebp-8h]
  IVP_Real_Object *retaddr; // [esp+220h] [ebp+0h]

  objectR = a2;
  objectA = retaddr;
  v3 = this;
  v4 = tmpl;
  *((_BYTE *)this + 300) = 2;
  v5 = tmpl->objectR;
  v6 = tmpl->objectA;
  *(_DWORD *)&m_Acs_f_Aos_52[64] = v3;
  *(_DWORD *)&m_Acs_f_Aos_52[68] = v5;
  *(_DWORD *)&m_Acs_f_Aos_52[72] = v6;
  if ( v5 != nullptr )
  {
    physical_core = (IVP_U_Matrix3 *)v5->physical_core;
    v8 = (LOBYTE(physical_core->rows[0].k[0]) & 2) == 0;
    p_m_Rfs_f_Rcs = (int)physical_core;
    if ( v8 )
    {
      if ( v3->cores_of_constraint_system.n_elems >= v3->cores_of_constraint_system.memsize )
      {
        IVP_U_Vector_Base::increment_mem(this: &v3->cores_of_constraint_system);
        physical_core = (IVP_U_Matrix3 *)p_m_Rfs_f_Rcs;
      }
      v3->cores_of_constraint_system.elems[v3->cores_of_constraint_system.n_elems++] = physical_core;
      v6 = *(IVP_Real_Object **)&m_Acs_f_Aos_52[72];
      v5 = *(IVP_Real_Object **)&m_Acs_f_Aos_52[68];
    }
  }
  if ( v6 != nullptr )
  {
    v9 = (IVP_U_Matrix3 *)v6->physical_core;
    v8 = (LOBYTE(v9->rows[0].k[0]) & 2) == 0;
    p_m_Rfs_f_Rcs = (int)v9;
    if ( v8 )
    {
      if ( v3->cores_of_constraint_system.n_elems >= v3->cores_of_constraint_system.memsize )
      {
        IVP_U_Vector_Base::increment_mem(this: &v3->cores_of_constraint_system);
        v9 = (IVP_U_Matrix3 *)p_m_Rfs_f_Rcs;
      }
      v3->cores_of_constraint_system.elems[v3->cores_of_constraint_system.n_elems++] = v9;
      v6 = *(IVP_Real_Object **)&m_Acs_f_Aos_52[72];
      v5 = *(IVP_Real_Object **)&m_Acs_f_Aos_52[68];
    }
  }
  if ( tmpl->m_Aos_f_Afs != nullptr )
  {
    if ( v5 == nullptr )
      v5 = v6;
    IVP_Real_Object::ensure_in_simulation(this: v5);
    v5 = *(IVP_Real_Object **)&m_Acs_f_Aos_52[68];
  }
  if ( v5 != nullptr )
    IVP_Real_Object::get_m_world_f_object_AT(this: v5, m_world_f_object_out: (IVP_U_Matrix *)&m_ws_f_Aos.vv.k[1]);
  else
    IVP_U_Matrix::init(this: (IVP_U_Matrix *)&m_ws_f_Aos.vv.k[1]);
  if ( *(_DWORD *)&m_Acs_f_Aos_52[72] != 0 )
    IVP_Real_Object::get_m_world_f_object_AT(
      this: *(IVP_Real_Object **)&m_Acs_f_Aos_52[72],
      m_world_f_object_out: (IVP_U_Matrix *)&m_fs_f_rs.rows[2].k[1]);
  else
    IVP_U_Matrix::init(this: (IVP_U_Matrix *)&m_fs_f_rs.rows[2].k[1]);
  IVP_U_Matrix::mimult4(
    this: (IVP_U_Matrix *)&m_ws_f_Aos.vv.k[1],
    mb: (const IVP_U_Matrix *)&m_fs_f_rs.rows[2].k[1],
    m_out: (IVP_U_Matrix *)&m_Rcs_f_Aos.vv.k[1]);
  if ( *(_DWORD *)&m_Acs_f_Aos_52[68] != 0 )
    IVP_Real_Object::calc_m_core_f_object(
      this: *(IVP_Real_Object **)&m_Acs_f_Aos_52[68],
      m_core_f_object: (IVP_U_Matrix *)m_Acs_f_Aos_52);
  else
    IVP_U_Matrix::init(this: (IVP_U_Matrix *)m_Acs_f_Aos_52);
  if ( *(_DWORD *)&m_Acs_f_Aos_52[72] != 0 )
    IVP_Real_Object::calc_m_core_f_object(
      this: *(IVP_Real_Object **)&m_Acs_f_Aos_52[72],
      m_core_f_object: (IVP_U_Matrix *)&m_ws_f_Ros.vv.k[1]);
  else
    IVP_U_Matrix::init(this: (IVP_U_Matrix *)&m_ws_f_Ros.vv.k[1]);
  IVP_U_Matrix::mmult4(
    this: (IVP_U_Matrix *)m_Acs_f_Aos_52,
    mb: (IVP_U_Matrix *)&m_Rcs_f_Aos.vv.k[1],
    m_out: (IVP_U_Matrix *)&m_Rcs_f_Acs.vv.k[1]);
  IVP_U_Matrix::mi2mult4(
    this: (IVP_U_Matrix *)&m_Rcs_f_Acs.vv.k[1],
    mb: (IVP_U_Matrix *)&m_ws_f_Ros.vv.k[1],
    m_out: (IVP_U_Matrix *)v22);
  m_Ros_f_Rfs = tmpl->m_Ros_f_Rfs;
  if ( m_Ros_f_Rfs != nullptr )
  {
    p_m_Rfs_f_Rcs = (int)&v3->m_Rfs_f_Rcs;
    IVP_U_Matrix::mmult4(this: (IVP_U_Matrix *)m_Acs_f_Aos_52, mb: m_Ros_f_Rfs, m_out: &v3->m_Rfs_f_Rcs);
    IVP_U_Matrix::real_invert(this: (IVP_U_Matrix *)p_m_Rfs_f_Rcs, epsilon: 1.0e-10);
  }
  else
  {
    qmemcpy(&v3->m_Rfs_f_Rcs, m_Acs_f_Aos_52, 64);
    p_m_Rfs_f_Rcs = (int)&v3->m_Rfs_f_Rcs;
    IVP_U_Matrix::real_invert(this: &v3->m_Rfs_f_Rcs, epsilon: 1.0e-10);
    v3 = *(IVP_Constraint_Local **)&m_Acs_f_Aos_52[64];
    v4 = tmpl;
  }
  m_Aos_f_Afs = v4->m_Aos_f_Afs;
  if ( m_Aos_f_Afs != nullptr )
  {
    IVP_U_Matrix::mmult4(this: (IVP_U_Matrix *)&m_ws_f_Ros.vv.k[1], mb: m_Aos_f_Afs, m_out: &v3->m_Afs_f_Acs);
    IVP_U_Matrix::real_invert(this: &v3->m_Afs_f_Acs, epsilon: 1.0e-10);
  }
  else
  {
    IVP_U_Matrix::mmult4(this: (IVP_U_Matrix *)p_m_Rfs_f_Rcs, mb: (const IVP_U_Matrix *)v22, m_out: &v3->m_Afs_f_Acs);
  }
  if ( v4->m_Ros_f_Rrs != nullptr )
  {
    v12 = (IVP_U_Matrix3 *)p_malloc(size: 0x30u);
    v3->m_Rfs_f_Rcs.rot = v12;
    IVP_U_Matrix3::mmult3(this: (IVP_U_Matrix3 *)m_Acs_f_Aos_52, mb: v4->m_Ros_f_Rrs, m_out: v12);
    IVP_U_Matrix3::transpose3(this: v3->m_Rfs_f_Rcs.rot);
    IVP_U_Matrix3::mi2mult3(
      this: (IVP_U_Matrix3 *)p_m_Rfs_f_Rcs,
      mb: v3->m_Rfs_f_Rcs.rot,
      m_out: (IVP_U_Matrix *)&m_Ros_f_Aos.vv.k[1]);
    v13 = (IVP_U_Matrix3 *)p_malloc(size: 0x30u);
    v3->m_Afs_f_Acs.rot = v13;
    IVP_U_Matrix3::mimult3(this: (IVP_U_Matrix *)&m_Ros_f_Aos.vv.k[1], mb: &v3->m_Afs_f_Acs, m_out: v13);
  }
  else
  {
    v3->m_Rfs_f_Rcs.rot = nullptr;
    v3->m_Afs_f_Acs.rot = nullptr;
  }
  v14 = *(IVP_Real_Object **)&m_Acs_f_Aos_52[72];
  v3->m_Rfs_f_Rcs.object = *(IVP_Real_Object **)&m_Acs_f_Aos_52[68];
  v3->m_Afs_f_Acs.object = v14;
  v3->fixed[0] = v4->axis_type[0];
  v3->fixed[1] = v4->axis_type[1];
  v3->fixed[2] = v4->axis_type[2];
  v3->fixed[3] = v4->axis_type[3];
  v3->fixed[4] = v4->axis_type[4];
  v3->fixed[5] = v4->axis_type[5];
  *(_DWORD *)&v3->fixedtrans_dim = 0;
  IVP_Constraint_Local::sort_translation_mapping(this: v3);
  IVP_Constraint_Local::sort_rotation_mapping(this: v15);
  force_factor = v4->force_factor;
  v3->force_factor = force_factor;
  v3->damp_factor_div_force = v4->damp_factor / force_factor;
  v3->limited_axis_stiffness = v4->limited_axis_stiffness;
  v3->borderright_Rfs[0] = v4->borderright_Rfs[0];
  v3->borderleft_Rfs[0] = v4->borderleft_Rfs[0];
  v17 = v4->maximpulse_type[0] != IVP_CFE_NONE;
  v3->borderright_Rfs[1] = v4->borderright_Rfs[1];
  v3->borderleft_Rfs[1] = v4->borderleft_Rfs[1];
  if ( v4->maximpulse_type[1] != IVP_CFE_NONE )
    v17 = true;
  v3->borderright_Rfs[2] = v4->borderright_Rfs[2];
  v3->borderleft_Rfs[2] = v4->borderleft_Rfs[2];
  if ( v4->maximpulse_type[2] != IVP_CFE_NONE )
    v17 = true;
  v3->borderright_Rfs[3] = v4->borderright_Rfs[3];
  v3->borderleft_Rfs[3] = v4->borderleft_Rfs[3];
  if ( v4->maximpulse_type[3] != IVP_CFE_NONE )
    v17 = true;
  v3->borderright_Rfs[4] = v4->borderright_Rfs[4];
  v3->borderleft_Rfs[4] = v4->borderleft_Rfs[4];
  if ( v4->maximpulse_type[4] != IVP_CFE_NONE )
    v17 = true;
  v3->borderright_Rfs[5] = v4->borderright_Rfs[5];
  v3->borderleft_Rfs[5] = v4->borderleft_Rfs[5];
  if ( v4->maximpulse_type[5] != IVP_CFE_NONE || v17 )
  {
    v18 = (unsigned __int8 *)p_malloc(size: 0x30u);
    *(_DWORD *)&m_Acs_f_Aos_52[64] = v18;
    if ( v18 != nullptr )
    {
      memset(dst: v18, value: 0, count: 0x30u);
      v19 = *(IVP_Constraint_Local_MaxImpulse **)&m_Acs_f_Aos_52[64];
    }
    else
    {
      v19 = nullptr;
    }
    v20 = -312 - (_DWORD)v4;
    v3->maxforce = v19;
    maximpulse_type = (float *)v4->maximpulse_type;
    *(_DWORD *)&m_Acs_f_Aos_52[64] = -312 - (_DWORD)v4;
    p_m_Rfs_f_Rcs = 6;
    while ( 1 )
    {
      *(float *)((char *)v3->maxforce->halfimpulse + v20 + (unsigned int)maximpulse_type) = maximpulse_type[6];
      *(float *)((char *)v3->maxforce[-6].halfimpulse + (unsigned int)maximpulse_type - (_DWORD)v4) = *maximpulse_type;
      ++maximpulse_type;
      if ( --p_m_Rfs_f_Rcs == 0 )
        break;
      v20 = *(_DWORD *)&m_Acs_f_Aos_52[64];
    }
    *((_DWORD *)&v3->IVP_Constraint + 1) &= 0xFFFFFFFC;
  }
  else
  {
    *((_DWORD *)&v3->IVP_Constraint + 1) &= 0xFFFFFFFC;
    v3->maxforce = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A97A0
// Name: public: IVP_Constraint_Local::IVP_Constraint_Local(class IVP_Template_Constraint const __near &)
// Source: json
//------------------------------------------------------------------------------
IVP_Constraint_Local *__thiscall IVP_Constraint_Local::IVP_Constraint_Local(
        IVP_Constraint_Local *this,
        const IVP_Template_Constraint *tmpl)
{
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  IVP_Constraint::IVP_Constraint(this);
  this->__vftable = (IVP_Constraint_Local_vtbl *)&IVP_Constraint_Local::`vftable';
  this->m_Rfs_f_Rcs.rot = nullptr;
  this->m_Afs_f_Acs.rot = nullptr;
  *(_DWORD *)this->mapping_uRfs_f_Rfs.k = 131328;
  *(_WORD *)&this->mapping_uRrs_f_Rrs.k[1] = 513;
  IVP_Constraint_Local::init(this, a2: (IVP_Real_Object *)&savedregs, tmpl);
  IVP_Constraint::activate(this);
  return this;
}
