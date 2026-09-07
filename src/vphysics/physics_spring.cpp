// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_spring.cpp
// Functions: 13
// ============================================================

#include "vphysics\physics_spring.h"

//------------------------------------------------------------------------------
// Address: 0x10022E70
// Name: public: virtual void CPhysicsSpring::SetSpringConstant(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::SetSpringConstant(CPhysicsSpring *this, float flSpringConstant)
{
  IVP_Actuator_Spring *m_pSpring; // ecx

  m_pSpring = this->m_pSpring;
  if ( m_pSpring != nullptr && m_pSpring->spring_constant != flSpringConstant )
    IVP_Actuator_Spring::set_constant(this: m_pSpring, c: flSpringConstant);
}

//------------------------------------------------------------------------------
// Address: 0x10022EA0
// Name: public: virtual void CPhysicsSpring::SetSpringDamping(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::SetSpringDamping(CPhysicsSpring *this, float flSpringDamping)
{
  IVP_Actuator_Spring *m_pSpring; // ecx

  m_pSpring = this->m_pSpring;
  if ( m_pSpring != nullptr )
    IVP_Actuator_Spring::set_damp(this: m_pSpring, c: flSpringDamping);
}

//------------------------------------------------------------------------------
// Address: 0x10022EC0
// Name: public: virtual void CPhysicsSpring::event_object_deleted(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::event_object_deleted(CPhysicsSpring *this, IVP_Event_Object *__formal)
{
  IVP_Actuator_Spring *m_pSpring; // eax
  CPhysicsObject *m_pObjStart; // eax

  m_pSpring = this->m_pSpring;
  if ( (*(_WORD *)(&m_pSpring->anchors[0].l_anchor_object + 1) & 0x200) == 0 )
    IVP_Real_Object::remove_listener_object(
      this: (IVP_Real_Object *)m_pSpring->actuator_controlled_cores.elems,
      listener: (IVP_Listener_Object *)this);
  m_pObjStart = this->m_pObjStart;
  if ( (m_pObjStart->m_callbacks & 0x200) == 0 )
    IVP_Real_Object::remove_listener_object(this: m_pObjStart->m_pObject, listener: (IVP_Listener_Object *)this);
  this->m_pSpring = nullptr;
  this->m_pObjStart = nullptr;
  this->IVP_Listener_Object::__vftable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10022F00
// Name: public: virtual void CPhysicsSpring::GetEndpoints(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::GetEndpoints(
        CPhysicsSpring *this,
        Vector *worldPositionStart,
        Vector *worldPositionEnd)
{
  IVP_Actuator_Spring *m_pSpring; // eax
  float v5; // xmm2_4
  CPhysicsObject *m_pObjStart; // ecx
  float *v7; // eax
  CPhysicsObject *m_pObjEnd; // ecx
  float v9; // xmm1_4
  Vector localHL; // [esp+4h] [ebp-Ch] BYREF

  m_pSpring = this->m_pSpring;
  if ( m_pSpring != nullptr )
  {
    if ( worldPositionStart != nullptr )
    {
      v5 = m_pSpring->anchors[0].object_pos.k[1];
      m_pObjStart = this->m_pObjStart;
      localHL.y = m_pSpring->anchors[0].object_pos.k[2] * g_PhysicsUnits.unitScaleMetersInv;
      LODWORD(localHL.z) = COERCE_UNSIGNED_INT(v5 * g_PhysicsUnits.unitScaleMetersInv) ^ _mask__NegFloat_;
      localHL.x = m_pSpring->anchors[0].object_pos.k[0] * g_PhysicsUnits.unitScaleMetersInv;
      m_pObjStart->LocalToWorld(this: m_pObjStart, a2: worldPositionStart, a3: &localHL);
    }
    if ( worldPositionEnd != nullptr )
    {
      v7 = (float *)this->m_pSpring;
      m_pObjEnd = this->m_pObjEnd;
      v9 = v7[26] * g_PhysicsUnits.unitScaleMetersInv;
      LODWORD(localHL.z) = COERCE_UNSIGNED_INT(v7[25] * g_PhysicsUnits.unitScaleMetersInv) ^ _mask__NegFloat_;
      localHL.y = v9;
      localHL.x = g_PhysicsUnits.unitScaleMetersInv * v7[24];
      m_pObjEnd->LocalToWorld(this: m_pObjEnd, a2: worldPositionEnd, a3: &localHL);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022FC0
// Name: public: virtual void CPhysicsSpring::SetSpringLength(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::SetSpringLength(CPhysicsSpring *this, float flSpringLength)
{
  IVP_Actuator_Spring *m_pSpring; // ecx

  m_pSpring = this->m_pSpring;
  if ( m_pSpring != nullptr
    && (float)(g_PhysicsUnits.unitScaleMeters * 0.001) <= COERCE_FLOAT(
                                                            COERCE_UNSIGNED_INT(
                                                              (float)(g_PhysicsUnits.unitScaleMeters * flSpringLength)
                                                            - m_pSpring->spring_len)
                                                          & _mask__AbsFloat_) )
  {
    IVP_Actuator_Spring::set_len(this: m_pSpring, len: g_PhysicsUnits.unitScaleMeters * flSpringLength);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023010
// Name: public: void CPhysicsSpring::WriteToTemplate(struct vphysics_save_cphysicsspring_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::WriteToTemplate(CPhysicsSpring *this, vphysics_save_cphysicsspring_t *params)
{
  IVP_Actuator_Spring *m_pSpring; // edx
  float v3; // xmm2_4
  float *v4; // edx
  float v5; // xmm3_4

  if ( this->m_pSpring != nullptr )
  {
    params->constant = this->m_pSpring->spring_constant;
    params->naturalLength = this->m_pSpring->spring_len * g_PhysicsUnits.unitScaleMetersInv;
    params->damping = this->m_pSpring->spring_damp;
    params->relativeDamping = this->m_pSpring->rel_pos_damp;
    m_pSpring = this->m_pSpring;
    v3 = m_pSpring->anchors[0].object_pos.k[1] * g_PhysicsUnits.unitScaleMetersInv;
    params->startPosition.y = m_pSpring->anchors[0].object_pos.k[2] * g_PhysicsUnits.unitScaleMetersInv;
    params->startPosition.z = -v3;
    params->startPosition.x = m_pSpring->anchors[0].object_pos.k[0] * g_PhysicsUnits.unitScaleMetersInv;
    v4 = (float *)this->m_pSpring;
    v5 = v4[25] * g_PhysicsUnits.unitScaleMetersInv;
    params->endPosition.y = v4[26] * g_PhysicsUnits.unitScaleMetersInv;
    params->endPosition.z = -v5;
    params->endPosition.x = v4[24] * g_PhysicsUnits.unitScaleMetersInv;
    params->useLocalPositions = true;
    params->onlyStretch = this->m_pSpring->spring_force_only_on_stretch != IVP_FALSE;
    params->pObjStart = this->m_pObjStart;
    params->pObjEnd = this->m_pObjEnd;
  }
  else
  {
    memset(dst: (unsigned __int8 *)params, value: 0, count: sizeof(vphysics_save_cphysicsspring_t));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023110
// Name: bool RestorePhysicsSpring(struct physrestoreparams_t const __near &,class CPhysicsSpring __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RestorePhysicsSpring(const physrestoreparams_t *params, CPhysicsSpring **ppSpring)
{
  vphysics_save_cphysicsspring_t springTemplate; // [esp+4h] [ebp-34h] BYREF

  memset(dst: (unsigned __int8 *)&springTemplate, value: 0, count: sizeof(springTemplate));
  params->pRestore->ReadAll(this: params->pRestore, a2: &springTemplate, a3: &vphysics_save_cphysicsspring_t::m_DataMap);
  if ( springTemplate.pObjStart != nullptr && springTemplate.pObjEnd != nullptr )
  {
    *ppSpring = (CPhysicsSpring *)params->pEnvironment->CreateSpring(
                                    this: params->pEnvironment,
                                    a2: springTemplate.pObjStart,
                                    a3: springTemplate.pObjEnd,
                                    a4: &springTemplate);
    return 1;
  }
  else
  {
    DevMsg(a1: "Failed to restore spring enpoints\n");
    *ppSpring = nullptr;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023190
// Name: public: CPhysicsSpring::CPhysicsSpring(class CPhysicsObject __near *,class CPhysicsObject __near *,class IVP_Actuator_Spring __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysicsSpring *__thiscall CPhysicsSpring::CPhysicsSpring(
        CPhysicsSpring *this,
        CPhysicsObject *pObjectStart,
        CPhysicsObject *pObjectEnd,
        IVP_Actuator_Spring *pSpring)
{
  CPhysicsObject *m_pObjEnd; // eax

  this->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&IVP_Listener_Object::`vftable';
  this->m_pSpring = pSpring;
  this->IPhysicsSpring::__vftable = (CPhysicsSpring_vtbl *)&CPhysicsSpring::`vftable'{for `IPhysicsSpring'};
  this->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&CPhysicsSpring::`vftable'{for `IVP_Listener_Object'};
  this->m_pObjStart = pObjectStart;
  this->m_pObjEnd = pObjectEnd;
  if ( (pObjectStart->m_callbacks & 0x200) == 0 )
    IVP_Real_Object::add_listener_object(this: pObjectStart->m_pObject, listener: &this->IVP_Listener_Object);
  m_pObjEnd = this->m_pObjEnd;
  if ( (m_pObjEnd->m_callbacks & 0x200) == 0 )
    IVP_Real_Object::add_listener_object(this: m_pObjEnd->m_pObject, listener: &this->IVP_Listener_Object);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10023210
// Name: public: virtual CPhysicsSpring::~CPhysicsSpring(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::~CPhysicsSpring(CPhysicsSpring *this)
{
  IVP_Actuator_Spring *m_pSpring; // ecx
  CPhysicsObject *m_pObjStart; // eax
  CPhysicsObject *m_pObjEnd; // eax

  m_pSpring = this->m_pSpring;
  this->IPhysicsSpring::__vftable = (CPhysicsSpring_vtbl *)&CPhysicsSpring::`vftable'{for `IPhysicsSpring'};
  this->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&CPhysicsSpring::`vftable'{for `IVP_Listener_Object'};
  if ( m_pSpring != nullptr )
  {
    ((void (__thiscall *)(IVP_Actuator_Spring *, int))m_pSpring->dtr_IVP_Controller)(a1: m_pSpring, a2: 1);
    m_pObjStart = this->m_pObjStart;
    if ( (m_pObjStart->m_callbacks & 0x200) == 0 )
      IVP_Real_Object::remove_listener_object(this: m_pObjStart->m_pObject, listener: &this->IVP_Listener_Object);
    m_pObjEnd = this->m_pObjEnd;
    if ( (m_pObjEnd->m_callbacks & 0x200) == 0 )
      IVP_Real_Object::remove_listener_object(this: m_pObjEnd->m_pObject, listener: &this->IVP_Listener_Object);
    this->m_pObjStart = nullptr;
    this->m_pObjEnd = nullptr;
    this->m_pSpring = nullptr;
  }
  this->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&IVP_Listener_Object::`vftable';
  this->IPhysicsSpring::__vftable = (CPhysicsSpring_vtbl *)&IPhysicsConstraintGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10023290
// Name: class IPhysicsSpring __near * CreateSpring(class IVP_Environment __near *,class CPhysicsObject __near *,class CPhysicsObject __near *,struct springparams_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysicsSpring *__usercall CreateSpring@<eax>(
        float a1@<ebp>,
        IVP_Environment *pEnvironment,
        CPhysicsObject *pObjectStart,
        CPhysicsObject *pObjectEnd,
        springparams_t *pParams)
{
  float naturalLength; // xmm1_4
  bool v6; // zf
  float unitScaleMeters; // xmm0_4
  BOOL v8; // eax
  float relativeDamping; // xmm1_4
  void (__thiscall *WorldToLocal)(IPhysicsObject *, Vector *, const Vector *); // edx
  float hesse_val; // xmm1_4
  float z; // xmm2_4
  IVP_Actuator_Spring *spring; // esi
  CPhysicsSpring *v14; // eax
  IVP_Real_Object *m_pObject; // [esp-24h] [ebp-D4h]
  _BYTE v17[12]; // [esp-Ch] [ebp-BCh] BYREF
  IVP_Template_Anchor anchorTemplateObjectEnd; // [esp+0h] [ebp-B0h] BYREF
  IVP_Template_Anchor anchorTemplateObjectStart; // [esp+20h] [ebp-90h] BYREF
  _BYTE *v20; // [esp+40h] [ebp-70h]
  IVP_Template_Spring spring_template; // [esp+44h] [ebp-6Ch] BYREF
  IVP_U_Float_Point ivpPosStart; // [esp+80h] [ebp-30h] BYREF
  IVP_U_Float_Point ivpPosEnd; // [esp+90h] [ebp-20h] BYREF
  float v24; // [esp+A0h] [ebp-10h]
  Vector local; // [esp+A4h] [ebp-Ch]
  float retaddr; // [esp+B0h] [ebp+0h]

  local.x = a1;
  local.y = retaddr;
  IVP_Template_Spring::IVP_Template_Spring(this: (IVP_Template_Spring *)&anchorTemplateObjectStart.coords_world.k[2]);
  naturalLength = pParams->naturalLength;
  v6 = !pParams->onlyStretch;
  spring_template.spring_len = pParams->constant;
  unitScaleMeters = g_PhysicsUnits.unitScaleMeters;
  v8 = !v6;
  v6 = !pParams->useLocalPositions;
  *(float *)&spring_template.client_data = naturalLength * g_PhysicsUnits.unitScaleMeters;
  spring_template.spring_values_are_relative = LODWORD(pParams->damping);
  relativeDamping = pParams->relativeDamping;
  spring_template.anchors[0] = nullptr;
  *(float *)&spring_template.spring_force_only_on_stretch = relativeDamping;
  spring_template.anchors[1] = (IVP_Template_Anchor *)v8;
  if ( v6 )
  {
    pObjectStart->WorldToLocal(this: pObjectStart, a2: (Vector *)&ivpPosEnd.k[2], a3: &pParams->startPosition);
    WorldToLocal = pObjectEnd->WorldToLocal;
    *(float *)&spring_template.active_float_spring_constant = ivpPosEnd.k[2] * g_PhysicsUnits.unitScaleMeters;
    spring_template.active_float_spring_damp = (IVP_U_Active_Float *)(COERCE_UNSIGNED_INT(v24 * g_PhysicsUnits.unitScaleMeters)
                                                                    ^ _mask__NegFloat_);
    *(float *)&spring_template.active_float_spring_rel_pos_damp = ivpPosEnd.hesse_val * g_PhysicsUnits.unitScaleMeters;
    WorldToLocal(this: pObjectEnd, a2: (Vector *)&ivpPosEnd.k[2], a3: &pParams->endPosition);
    unitScaleMeters = g_PhysicsUnits.unitScaleMeters;
    ivpPosStart.k[1] = ivpPosEnd.k[2] * g_PhysicsUnits.unitScaleMeters;
    LODWORD(ivpPosStart.k[2]) = COERCE_UNSIGNED_INT(v24 * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
    hesse_val = ivpPosEnd.hesse_val;
  }
  else
  {
    spring_template.active_float_spring_damp = (IVP_U_Active_Float *)(COERCE_UNSIGNED_INT(
                                                                        pParams->startPosition.z
                                                                      * g_PhysicsUnits.unitScaleMeters)
                                                                    ^ _mask__NegFloat_);
    *(float *)&spring_template.active_float_spring_rel_pos_damp = pParams->startPosition.y
                                                                * g_PhysicsUnits.unitScaleMeters;
    ivpPosStart.k[1] = g_PhysicsUnits.unitScaleMeters * pParams->endPosition.x;
    z = pParams->endPosition.z;
    *(float *)&spring_template.active_float_spring_constant = g_PhysicsUnits.unitScaleMeters * pParams->startPosition.x;
    hesse_val = pParams->endPosition.y;
    LODWORD(ivpPosStart.k[2]) = COERCE_UNSIGNED_INT(z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  }
  m_pObject = pObjectStart->m_pObject;
  ivpPosStart.hesse_val = hesse_val * unitScaleMeters;
  IVP_Template_Anchor::set_anchor_position_os(
    this: (IVP_Template_Anchor *)&anchorTemplateObjectEnd.coords_world.k[1],
    obj: m_pObject,
    coords_os: (const IVP_U_Float_Point *)&spring_template.active_float_spring_constant);
  IVP_Template_Anchor::set_anchor_position_os(
    this: (IVP_Template_Anchor *)v17,
    obj: pObjectEnd->m_pObject,
    coords_os: (IVP_U_Float_Point *)&ivpPosStart.k[1]);
  LODWORD(anchorTemplateObjectStart.coords_world.hesse_val) = &anchorTemplateObjectEnd.coords_world.k[1];
  v20 = v17;
  spring = IVP_Environment::create_spring(
             this: pEnvironment,
             templ: (IVP_Template_Spring *)&anchorTemplateObjectStart.coords_world.k[2]);
  v14 = (CPhysicsSpring *)p_malloc(size: 0x14u);
  if ( v14 != nullptr )
    return CPhysicsSpring::CPhysicsSpring(this: v14, pObjectStart, pObjectEnd, pSpring: spring);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10023480
// Name: bool SavePhysicsSpring(struct physsaveparams_t const __near &,class CPhysicsSpring __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SavePhysicsSpring(const physsaveparams_t *params, CPhysicsSpring *pSpring)
{
  vphysics_save_cphysicsspring_t springTemplate; // [esp+0h] [ebp-34h] BYREF

  memset(dst: (unsigned __int8 *)&springTemplate, value: 0, count: sizeof(springTemplate));
  CPhysicsSpring::WriteToTemplate(this: pSpring, params: &springTemplate);
  params->pSave->WriteAll(this: params->pSave, a2: &springTemplate, a3: &vphysics_save_cphysicsspring_t::m_DataMap);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C6AF0
// Name: vphysics_save_cphysicsspring_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_cphysicsspring_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_cphysicsspring_t>(__formal: nullptr);
  vphysics_save_cphysicsspring_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100234F0
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_cphysicsspring_t>(struct vphysics_save_cphysicsspring_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_cphysicsspring_t>()
{
  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    nameHolder_16.m_pszBase = "vphysics_save_cphysicsspring_t";
    nameHolder_16.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_16.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_16.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_16.m_Names.m_Size = 0;
    nameHolder_16.m_Names.m_pElements = nullptr;
    nameHolder_16.m_nLenBase = 30;
    atexit(func: DataMapInit_vphysics_save_cphysicsspring_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_cphysicsspring_t::m_DataMap.baseMap = nullptr;
  vphysics_save_cphysicsspring_t::m_DataMap.dataNumFields = 10;
  vphysics_save_cphysicsspring_t::m_DataMap.dataDesc = &dataDesc_16[1];
  return &vphysics_save_cphysicsspring_t::m_DataMap;
}
