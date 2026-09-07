// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_fluid.cpp
// Functions: 16
// ============================================================

#include "vphysics\physics_fluid.h"

//------------------------------------------------------------------------------
// Address: 0x10016220
// Name: public: virtual void CPhysicsFluidController::SetGameData(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsFluidController::SetGameData(CPhysicsFluidController *this, void *pGameData)
{
  this->m_pGameData = pGameData;
}

//------------------------------------------------------------------------------
// Address: 0x10016230
// Name: public: virtual float CPhysicsFluidController::GetDensity(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsFluidController::GetDensity(CPhysicsFluidController *this)
{
  return this->m_pBuoyancy->m_density;
}

//------------------------------------------------------------------------------
// Address: 0x10016240
// Name: public: virtual int CPhysicsFluidController::GetContents(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPhysicsFluidController::GetContents(ConCommandBase *this)
{
  return this->m_pszHelpString;
}

//------------------------------------------------------------------------------
// Address: 0x100162B0
// Name: public: virtual void CPhysicsFluidController::WakeAllSleepingObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsFluidController::WakeAllSleepingObjects(CPhysicsFluidController *this)
{
  IVP_Controller_Phantom::wake_all_sleeping_objects(this: this->m_pObject->m_pObject->controller_phantom);
}

//------------------------------------------------------------------------------
// Address: 0x100162C0
// Name: public: virtual class IVP_Template_Buoyancy __near * CBuoyancyAttacher::get_parameters_per_core(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Buoyancy *__thiscall CBuoyancyAttacher::get_parameters_per_core(CBuoyancyAttacher *this, IVP_Core *pCore)
{
  int v3; // esi
  float ratio; // [esp+Ch] [ebp+8h]

  if ( pCore != nullptr )
  {
    v3 = *((_DWORD *)*pCore->objects.elems + 40);
    ratio = *(float *)(v3 + 64);
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 284))(a1: v3) != 0 || (*(_WORD *)(v3 + 28) & 0x1000) == 0 )
    {
      this->template_buoyancy.medium_density = 0.0;
      return &this->template_buoyancy;
    }
    else
    {
      this->template_buoyancy.medium_density = this->m_density * ratio;
      return &this->template_buoyancy;
    }
  }
  else
  {
    this->template_buoyancy.medium_density = this->m_density;
    return &this->template_buoyancy;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016380
// Name: public: virtual void CPhysicsFluidController::GetSurfacePlane(class Vector __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsFluidController::GetSurfacePlane(
        CPhysicsFluidController *this@<ecx>,
        float a2@<ebp>,
        int a3@<esi>,
        Vector *pNormal,
        float *pDist)
{
  IVP_Core *physical_core; // eax
  int v6; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Float_Point abs_speed_of_current; // [esp+0h] [ebp-20h] BYREF
  IVP_U_Float_Hesse surface; // [esp+10h] [ebp-10h]
  float retaddr; // [esp+20h] [ebp+0h]

  surface.k[1] = a2;
  surface.k[2] = retaddr;
  physical_core = this->m_pObject->m_pObject->physical_core;
  ((void (__thiscall *)(IVP_Liquid_Surface_Descriptor *, IVP_Environment *, IVP_Core *, float *, int *, int))this->m_pLiquidSurface->calc_liquid_surface)(
    a1: this->m_pLiquidSurface,
    a2: physical_core->environment,
    a3: physical_core,
    a4: &abs_speed_of_current.k[1],
    a5: &v6,
    a6: a3);
  if ( pNormal != nullptr )
  {
    pNormal->z = -abs_speed_of_current.k[2];
    pNormal->y = abs_speed_of_current.hesse_val;
    pNormal->x = abs_speed_of_current.k[1];
  }
  if ( pDist != nullptr )
    *pDist = -(float)(g_PhysicsUnits.unitScaleMetersInv * surface.k[0]);
  if ( pNormal != nullptr )
  {
    pNormal->x = pNormal->x * -1.0;
    pNormal->y = pNormal->y * -1.0;
    pNormal->z = pNormal->z * -1.0;
  }
  if ( pDist != nullptr )
    *pDist = *pDist * -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10016460
// Name: public: CLiquidSurfaceDescriptor::CLiquidSurfaceDescriptor(class CPhysicsObject __near *,class Vector4D const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CLiquidSurfaceDescriptor *__userpurge CLiquidSurfaceDescriptor::CLiquidSurfaceDescriptor@<eax>(
        CLiquidSurfaceDescriptor *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CPhysicsObject *pFluidObject,
        const Vector4D *plane,
        const Vector *current)
{
  float w; // xmm0_4
  void (__thiscall *GetPositionMatrix)(IPhysicsObject *, matrix3x4_t *); // edx
  matrix3x4_t matObjectToWorld; // [esp+0h] [ebp-5Ch] BYREF
  cplane_t worldPlane; // [esp+30h] [ebp-2Ch] BYREF
  Vector out; // [esp+44h] [ebp-18h] BYREF
  float v15[3]; // [esp+50h] [ebp-Ch] BYREF

  worldPlane.normal.x = plane->x;
  worldPlane.normal.y = plane->y;
  worldPlane.normal.z = plane->z;
  w = plane->w;
  this->__vftable = (CLiquidSurfaceDescriptor_vtbl *)&CLiquidSurfaceDescriptor::`vftable';
  GetPositionMatrix = pFluidObject->GetPositionMatrix;
  worldPlane.dist = w;
  ((void (__thiscall *)(CPhysicsObject *, matrix3x4_t *, int, int, int))GetPositionMatrix)(
    a1: pFluidObject,
    a2: &matObjectToWorld,
    a3,
    a4,
    a5: a2);
  MatrixGetColumn(in: &matObjectToWorld, column: 3, &out);
  VectorIRotate(in1: &out.x, in2: &matObjectToWorld, out: v15);
  VectorIRotate(in1: &worldPlane.normal.x, in2: &matObjectToWorld, out: &this->m_objectSpacePlane.normal.x);
  this->m_objectSpacePlane.dist = (float)((float)((float)((float)(this->m_objectSpacePlane.normal.x
                                                                * this->m_objectSpacePlane.normal.x)
                                                        + (float)(this->m_objectSpacePlane.normal.y
                                                                * this->m_objectSpacePlane.normal.y))
                                                + (float)(this->m_objectSpacePlane.normal.z
                                                        * this->m_objectSpacePlane.normal.z))
                                        * worldPlane.dist)
                                - (float)((float)((float)(this->m_objectSpacePlane.normal.x * v15[0])
                                                + (float)(this->m_objectSpacePlane.normal.y * v15[1]))
                                        + (float)(this->m_objectSpacePlane.normal.z * v15[2]));
  VectorIRotate(in1: &current->x, in2: &matObjectToWorld, out: &this->m_vecObjectSpaceCurrent.x);
  this->m_pFluidObject = pFluidObject;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016560
// Name: public: virtual void CLiquidSurfaceDescriptor::calc_liquid_surface(class IVP_Environment __near *,class IVP_Core __near *,class IVP_U_Float_Hesse __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLiquidSurfaceDescriptor::calc_liquid_surface(
        CLiquidSurfaceDescriptor *this,
        IVP_Environment *__formal,
        IVP_Core *a3,
        IVP_U_Float_Hesse *surface_normal_out,
        IVP_U_Float_Point *abs_speed_of_current_out)
{
  float v6; // xmm3_4
  float v7; // xmm2_4
  float z; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float x; // xmm1_4
  float y; // xmm0_4
  matrix3x4_t matObjectToWorld; // [esp+8h] [ebp-50h] BYREF
  cplane_t worldPlane; // [esp+38h] [ebp-20h] BYREF
  Vector worldSpaceCurrent; // [esp+4Ch] [ebp-Ch] BYREF

  this->m_pFluidObject->GetPositionMatrix(this: this->m_pFluidObject, a2: &matObjectToWorld);
  VectorRotate(in1: &this->m_objectSpacePlane.normal.x, in2: &matObjectToWorld, out: &worldPlane.normal.x);
  v6 = worldPlane.normal.x * -1.0;
  v7 = worldPlane.normal.y * -1.0;
  v9 = (float)((float)((float)((float)(matObjectToWorld.m_flMatVal[1][3] * worldPlane.normal.y)
                             + (float)(matObjectToWorld.m_flMatVal[0][3] * worldPlane.normal.x))
                     + (float)(matObjectToWorld.m_flMatVal[2][3] * worldPlane.normal.z))
             + (float)((float)((float)((float)(worldPlane.normal.y * worldPlane.normal.y)
                                     + (float)(worldPlane.normal.x * worldPlane.normal.x))
                             + (float)(worldPlane.normal.z * worldPlane.normal.z))
                     * this->m_objectSpacePlane.dist))
     * -1.0;
  worldPlane.normal.z = worldPlane.normal.z * -1.0;
  z = worldPlane.normal.z;
  v10 = g_PhysicsUnits.unitScaleMeters * v9;
  surface_normal_out->k[0] = worldPlane.normal.x * -1.0;
  LODWORD(surface_normal_out->k[1]) = LODWORD(z) ^ _mask__NegFloat_;
  surface_normal_out->k[2] = v7;
  LODWORD(surface_normal_out->hesse_val) = LODWORD(v10) ^ _mask__NegFloat_;
  worldPlane.normal.x = v6;
  worldPlane.normal.y = v7;
  worldPlane.dist = v9;
  VectorRotate(in1: &this->m_vecObjectSpaceCurrent.x, in2: &matObjectToWorld, out: &worldSpaceCurrent.x);
  x = worldSpaceCurrent.x;
  LODWORD(abs_speed_of_current_out->k[1]) = LODWORD(worldSpaceCurrent.z) ^ _mask__NegFloat_;
  y = worldSpaceCurrent.y;
  abs_speed_of_current_out->k[0] = x;
  abs_speed_of_current_out->k[2] = y;
}

//------------------------------------------------------------------------------
// Address: 0x10016690
// Name: protected: virtual IVP_Attacher_To_Cores<class IVP_Controller_Buoyancy>::~IVP_Attacher_To_Cores<class IVP_Controller_Buoyancy>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>::~IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>(
        IVP_Attacher_To_Cores<IVP_Controller_Buoyancy> *this)
{
  IVP_U_Set_Active<IVP_Core> *set_of_cores; // ecx
  unsigned __int16 n_elems; // di
  int v4; // eax
  IVP_Attacher_To_Cores<IVP_Controller_Buoyancy> **v5; // edx

  set_of_cores = this->set_of_cores;
  this->__vftable = (IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>_vtbl *)&IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>::`vftable';
  n_elems = set_of_cores->listeners.n_elems;
  v4 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v5 = (IVP_Attacher_To_Cores<IVP_Controller_Buoyancy> **)&set_of_cores->listeners.elems[v4];
    do
    {
      if ( *v5 == this )
        break;
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  for ( set_of_cores->listeners.n_elems = n_elems - 1; v4 < set_of_cores->listeners.n_elems; ++v4 )
    set_of_cores->listeners.elems[v4] = set_of_cores->listeners.elems[v4 + 1];
  IVP_VHash_Store::~IVP_VHash_Store(this: &this->core_to_attachment_hash);
  this->__vftable = (IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>_vtbl *)&IVP_Listener_Set_Active<IVP_Core>::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10016700
// Name: protected: virtual void IVP_Attacher_To_Cores<class IVP_Controller_Buoyancy>::element_added(class IVP_U_Set_Active<class IVP_Core> __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>::element_added(
        IVP_Attacher_To_Cores<IVP_Controller_Buoyancy> *this,
        IVP_U_Set_Active<IVP_Core> *__formal,
        IVP_Core *elem)
{
  IVP_Controller_Buoyancy *v4; // eax
  IVP_Controller_Buoyancy *v5; // eax

  v4 = (IVP_Controller_Buoyancy *)p_malloc(size: 0x40u);
  if ( v4 != nullptr )
  {
    v5 = IVP_Controller_Buoyancy::IVP_Controller_Buoyancy(this: v4, attacher_buoyancy_: this, core_: elem);
    IVP_VHash_Store::add_elem(this: &this->core_to_attachment_hash, key_elem: elem, elem: v5);
  }
  else
  {
    IVP_VHash_Store::add_elem(this: &this->core_to_attachment_hash, key_elem: elem, elem: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016750
// Name: protected: virtual void IVP_Attacher_To_Cores<class IVP_Controller_Buoyancy>::element_removed(class IVP_U_Set_Active<class IVP_Core> __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>::element_removed(
        IVP_Attacher_To_Cores<IVP_Controller_Buoyancy> *this,
        IVP_U_Set_Active<IVP_Core> *__formal,
        IVP_Core *elem)
{
  void *v3; // eax

  v3 = IVP_VHash_Store::find_elem(this: &this->core_to_attachment_hash, key_elem: elem);
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)v3 + 28))(a1: v3, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10016780
// Name: protected: virtual void IVP_Attacher_To_Cores<class IVP_Controller_Buoyancy>::pset_is_going_to_be_deleted(class IVP_U_Set_Active<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>::pset_is_going_to_be_deleted(
        IVP_Attacher_To_Cores<IVP_Controller_Buoyancy> *this,
        IVP_U_Set_Active<IVP_Core> *set)
{
  int size_mm; // esi
  IVP_Core *elem; // eax

  size_mm = set->size_mm;
  while ( size_mm >= 0 )
  {
    while ( 1 )
    {
      elem = (IVP_Core *)set->elems[size_mm--].elem;
      if ( elem != nullptr )
        break;
      if ( size_mm < 0 )
        goto LABEL_5;
    }
    this->element_removed(this, a2: nullptr, a3: elem);
  }
LABEL_5:
  if ( this != nullptr )
    ((void (__thiscall *)(IVP_Attacher_To_Cores<IVP_Controller_Buoyancy> *, int))this->dtr_IVP_Listener_Set_Active<IVP_Core>)(
      a1: this,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100167D0
// Name: public: virtual class IVP_SurfaceManager __near * IVP_Attacher_To_Cores_Buoyancy::get_buoyancy_surface(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_SurfaceManager *__thiscall IVP_Attacher_To_Cores_Buoyancy::get_buoyancy_surface(
        IVP_Attacher_To_Cores_Buoyancy *this,
        IVP_Real_Object *obj)
{
  return obj->surface_manager;
}

//------------------------------------------------------------------------------
// Address: 0x10016810
// Name: class CPhysicsFluidController __near * CreateFluidController(class IVP_Environment __near *,class CPhysicsObject __near *,struct fluidparams_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysicsFluidController *__usercall CreateFluidController@<eax>(
        int a1@<ebx>,
        IVP_Environment *pEnvironment,
        CPhysicsObject *pFluidObject,
        fluidparams_t *pParams)
{
  CLiquidSurfaceDescriptor *v6; // eax
  int v7; // eax
  float density; // xmm2_4
  float damping; // xmm1_4
  IVP_Attacher_To_Cores_Buoyancy *v10; // esi
  _DWORD *v11; // eax
  int contents; // ecx
  void *v13; // esi
  IVP_Template_Buoyancy buoyancy_input; // [esp+8h] [ebp-50h] BYREF
  IVP_Controller_Phantom *pPhantom; // [esp+54h] [ebp-4h]
  CLiquidSurfaceDescriptor *lsd; // [esp+64h] [ebp+Ch]

  pFluidObject->BecomeTrigger(this: pFluidObject);
  pPhantom = pFluidObject->m_pObject->controller_phantom;
  if ( pPhantom == nullptr )
    return nullptr;
  v6 = (CLiquidSurfaceDescriptor *)p_malloc(size: 0x28u);
  if ( v6 != nullptr )
    lsd = CLiquidSurfaceDescriptor::CLiquidSurfaceDescriptor(
            this: v6,
            a2: (int)pParams,
            a3: (int)pFluidObject,
            a4: 0,
            pFluidObject,
            plane: &pParams->surfacePlane,
            current: &pParams->currentVelocity);
  else
    lsd = nullptr;
  v7 = ((int (__thiscall *)(CPhysicsObject *, int))pFluidObject->GetMaterialIndex)(a1: pFluidObject, a2: a1);
  density = physprops->GetSurfaceData(this: physprops, a2: v7)->physics.density;
  buoyancy_input.friction_damp_factor = 0.050000001;
  buoyancy_input.buoyancy_eps = 1.0e-10;
  buoyancy_input.mi_weights.weight_current_speed = 1.0;
  buoyancy_input.mi_weights.weight_surface = 1.0;
  buoyancy_input.mi_weights.weight_rot_speed = 1.0;
  damping = pParams->damping;
  buoyancy_input.ball_rot_dampening_factor = 0.0099999998;
  buoyancy_input.max_res = 0.0099999998;
  buoyancy_input.pressure_damp_factor = damping;
  buoyancy_input.torque_factor = 0.0099999998;
  buoyancy_input.simulate_wing_behavior = IVP_FALSE;
  buoyancy_input.use_interpolation = IVP_FALSE;
  buoyancy_input.max_interpolation_tries = 10;
  buoyancy_input.max_tries_nr_of_vectors_involved = 15;
  buoyancy_input.use_stochastic_insertion = IVP_TRUE;
  buoyancy_input.insert_extrapol_only = IVP_TRUE;
  buoyancy_input.nr_future_psi_for_extrapolation = 1;
  buoyancy_input.medium_density = density;
  buoyancy_input.viscosity_factor = 0.0;
  buoyancy_input.viscosity_input_factor = 0.1;
  v10 = (IVP_Attacher_To_Cores_Buoyancy *)p_malloc(size: 0x74u);
  if ( v10 != nullptr )
  {
    IVP_Attacher_To_Cores_Buoyancy::IVP_Attacher_To_Cores_Buoyancy(
      this: v10,
      templ: &buoyancy_input,
      set_of_cores_: pPhantom->set_of_cores,
      liquid_surface_descriptor_: lsd);
    v10->__vftable = (IVP_Attacher_To_Cores_Buoyancy_vtbl *)&CBuoyancyAttacher::`vftable';
    v10[1].__vftable = (IVP_Attacher_To_Cores_Buoyancy_vtbl *)LODWORD(buoyancy_input.medium_density);
  }
  else
  {
    v10 = nullptr;
  }
  v11 = p_malloc(size: 0x18u);
  if ( v11 != nullptr )
  {
    contents = pParams->contents;
    v11[1] = v10;
    *v11 = &CPhysicsFluidController::`vftable';
    v11[2] = lsd;
    v11[3] = pFluidObject;
    v11[4] = contents;
    v13 = v11;
  }
  else
  {
    v13 = nullptr;
  }
  (*(void (__thiscall **)(void *, void *))(*(_DWORD *)v13 + 4))(a1: v13, a2: pParams->pGameData);
  pPhantom->client_data = v13;
  return (CPhysicsFluidController *)v13;
}

//------------------------------------------------------------------------------
// Address: 0x1001E760
// Name: bool SavePhysicsFluidController(struct physsaveparams_t const __near &,class CPhysicsFluidController __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SavePhysicsFluidController(ConVar *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10080F70
// Name: public: IVP_Attacher_To_Cores<class IVP_Controller_Buoyancy>::IVP_Attacher_To_Cores<class IVP_Controller_Buoyancy>(class IVP_U_Set_Active<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Attacher_To_Cores<IVP_Controller_Buoyancy> *__thiscall IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>::IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>(
        IVP_Attacher_To_Cores<IVP_Controller_Buoyancy> *this,
        IVP_U_Set_Active<IVP_Core> *set_of_cores_in)
{
  int size_mm; // edi
  IVP_U_Set_Active<IVP_Core> *set_of_cores; // eax
  IVP_Core *elem; // esi
  IVP_U_Set_Active<IVP_Core> *v6; // esi
  IVP_Controller_Buoyancy *v8; // eax
  IVP_Controller_Buoyancy *v9; // eax

  this->__vftable = (IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>_vtbl *)&IVP_Attacher_To_Cores<IVP_Controller_Buoyancy>::`vftable';
  IVP_VHash_Store::IVP_VHash_Store(this: &this->core_to_attachment_hash, size_i: 16);
  this->set_of_cores = set_of_cores_in;
  size_mm = set_of_cores_in->size_mm;
  while ( 1 )
  {
    set_of_cores = this->set_of_cores;
    if ( size_mm < 0 )
      break;
    while ( 1 )
    {
      elem = (IVP_Core *)set_of_cores->elems[size_mm--].elem;
      if ( elem != nullptr )
        break;
      if ( size_mm < 0 )
        goto LABEL_5;
    }
    v8 = (IVP_Controller_Buoyancy *)p_malloc(size: 0x40u);
    if ( v8 != nullptr )
    {
      v9 = IVP_Controller_Buoyancy::IVP_Controller_Buoyancy(this: v8, attacher_buoyancy_: this, core_: elem);
      IVP_VHash_Store::add_elem(this: &this->core_to_attachment_hash, key_elem: elem, elem: v9);
    }
    else
    {
      IVP_VHash_Store::add_elem(this: &this->core_to_attachment_hash, key_elem: elem, elem: nullptr);
    }
  }
LABEL_5:
  v6 = this->set_of_cores;
  if ( set_of_cores->listeners.n_elems >= v6->listeners.memsize )
    IVP_U_Vector_Base::increment_mem(this: &v6->listeners);
  v6->listeners.elems[v6->listeners.n_elems++] = this;
  return this;
}
