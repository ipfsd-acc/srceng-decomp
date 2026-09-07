// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_friction.cpp
// Functions: 14
// ============================================================

#include "vphysics\physics_friction.h"

//------------------------------------------------------------------------------
// Address: 0x100169D0
// Name: public: virtual bool CFrictionSnapshot::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFrictionSnapshot::IsValid(CFrictionSnapshot *this)
{
  return this->m_pFriction != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100169E0
// Name: public: virtual class IPhysicsObject __near * CFrictionSnapshot::GetObject(int)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall CFrictionSnapshot::GetObject(CFrictionSnapshot *this, int index)
{
  if ( index == 1 )
    return (IPhysicsObject *)this->m_pContactPoint->synapse[this->m_synapseIndex == 0].l_obj->client_data;
  else
    return (IPhysicsObject *)this->m_pFriction->l_obj->client_data;
}

//------------------------------------------------------------------------------
// Address: 0x10016A20
// Name: public: virtual int CFrictionSnapshot::GetMaterial(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFrictionSnapshot::GetMaterial(CFrictionSnapshot *this, int index)
{
  IVP_Material *ivpMats[2]; // [esp+4h] [ebp-8h] BYREF

  IVP_Contact_Point::get_material_info(this: this->m_pContactPoint, mtl: ivpMats);
  return physprops->GetIVPMaterialIndex(this: physprops, a2: ivpMats[this->m_synapseIndex ^ index]);
}

//------------------------------------------------------------------------------
// Address: 0x10016A60
// Name: public: virtual float CFrictionSnapshot::GetFrictionCoefficient(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CFrictionSnapshot::GetFrictionCoefficient(CFrictionSnapshot *this)
{
  return this->m_pContactPoint->real_friction_factor;
}

//------------------------------------------------------------------------------
// Address: 0x10016A70
// Name: public: virtual void CFrictionSnapshot::RecomputeFriction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrictionSnapshot::RecomputeFriction(CFrictionSnapshot *this)
{
  IVP_Contact_Point::recompute_friction(this: this->m_pContactPoint);
}

//------------------------------------------------------------------------------
// Address: 0x10016A80
// Name: public: virtual void CFrictionSnapshot::ClearFrictionForce(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrictionSnapshot::ClearFrictionForce(CFrictionSnapshot *this)
{
  IVP_Contact_Point::set_friction_to_neutral(this: this->m_pContactPoint);
}

//------------------------------------------------------------------------------
// Address: 0x10016A90
// Name: public: virtual void CFrictionSnapshot::NextFrictionData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrictionSnapshot::NextFrictionData(CFrictionSnapshot *this)
{
  IVP_Synapse_Friction *next; // eax
  IVP_Contact_Point *v2; // edx

  next = this->m_pFriction->next;
  if ( next != nullptr )
  {
    this->m_pFriction = next;
    v2 = (IVP_Contact_Point *)((char *)next + next->contact_point_offset);
    this->m_pContactPoint = v2;
    this->m_synapseIndex = next != v2->synapse;
  }
  else
  {
    this->m_pFriction = nullptr;
    this->m_pContactPoint = nullptr;
    this->m_synapseIndex = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016AF0
// Name: public: virtual void CFrictionSnapshot::GetContactPoint(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrictionSnapshot::GetContactPoint(CFrictionSnapshot *this, Vector *out)
{
  IVP_Contact_Point *m_pContactPoint; // eax
  float v3; // xmm0_4

  m_pContactPoint = this->m_pContactPoint;
  v3 = m_pContactPoint->last_contact_point_ws.k[2] * g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(out->z) = COERCE_UNSIGNED_INT(m_pContactPoint->last_contact_point_ws.k[1] * g_PhysicsUnits.unitScaleMetersInv)
                  ^ _mask__NegFloat_;
  out->y = v3;
  out->x = m_pContactPoint->last_contact_point_ws.k[0] * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x10016B40
// Name: public: virtual void CFrictionSnapshot::GetSurfaceNormal(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFrictionSnapshot::GetSurfaceNormal(CFrictionSnapshot *this@<ecx>, int a2@<ebp>, Vector *out)
{
  IVP_Contact_Point *m_pContactPoint; // ecx
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  _DWORD v8[3]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Float_Point normal; // [esp+0h] [ebp-20h]
  int v10; // [esp+10h] [ebp-10h]
  int v11; // [esp+14h] [ebp-Ch]
  float sign[2]; // [esp+18h] [ebp-8h]
  float retaddr; // [esp+20h] [ebp+0h]

  v11 = a2;
  sign[0] = retaddr;
  m_pContactPoint = this->m_pContactPoint;
  normal.hesse_val = 1.0;
  v10 = -1082130432;
  IVP_Contact_Point_API::get_surface_normal_ws(friction_handle: m_pContactPoint, pOut: (IVP_U_Float_Point *)v8);
  LODWORD(out->z) = v8[1] ^ _mask__NegFloat_;
  LODWORD(out->y) = v8[2];
  LODWORD(out->x) = v8[0];
  v5 = normal.k[this->m_synapseIndex + 3];
  out->x = out->x * v5;
  v6 = out->y * v5;
  v7 = v5 * out->z;
  out->y = v6;
  out->z = v7;
  VectorNormalize(vec: out);
}

//------------------------------------------------------------------------------
// Address: 0x10016BF0
// Name: public: virtual float CFrictionSnapshot::GetNormalForce(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CFrictionSnapshot::GetNormalForce(CFrictionSnapshot *this)
{
  return IVP_Contact_Point_API::get_vert_force(friction_handle: this->m_pContactPoint)
       * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x10016C10
// Name: public: virtual float CFrictionSnapshot::GetEnergyAbsorbed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CFrictionSnapshot::GetEnergyAbsorbed(CFrictionSnapshot *this)
{
  return IVP_Contact_Point_API::get_eliminated_energy(friction_handle: this->m_pContactPoint) * 1550.0032;
}

//------------------------------------------------------------------------------
// Address: 0x10016C30
// Name: class IPhysicsFrictionSnapshot __near * CreateFrictionSnapshot(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsFrictionSnapshot *__cdecl CreateFrictionSnapshot(IVP_Real_Object *pObject)
{
  IPhysicsFrictionSnapshot *result; // eax
  IVP_Synapse_Friction *friction_synapses; // ecx
  IPhysicsFrictionSnapshot_vtbl *v3; // edx

  result = (IPhysicsFrictionSnapshot *)p_malloc(size: 0x18u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IPhysicsFrictionSnapshot_vtbl *)&CFrictionSnapshot::`vftable';
  result[2].__vftable = (IPhysicsFrictionSnapshot_vtbl *)pObject;
  result[1].__vftable = nullptr;
  friction_synapses = pObject->friction_synapses;
  if ( friction_synapses != nullptr )
  {
    result[3].__vftable = (IPhysicsFrictionSnapshot_vtbl *)friction_synapses;
    v3 = (IPhysicsFrictionSnapshot_vtbl *)((char *)friction_synapses + friction_synapses->contact_point_offset);
    result[4].__vftable = v3;
    result[5].__vftable = (IPhysicsFrictionSnapshot_vtbl *)(friction_synapses != (IVP_Synapse_Friction *)&v3->GetObject);
  }
  else
  {
    result[3].__vftable = nullptr;
    result[4].__vftable = nullptr;
    result[5].__vftable = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016C90
// Name: public: virtual void CFrictionSnapshot::DeleteAllMarkedContacts(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrictionSnapshot::DeleteAllMarkedContacts(CFrictionSnapshot *this, bool wakeObjects)
{
  CUtlVector<IVP_Real_Object *,CUtlMemory<IVP_Real_Object *,int> > *m_pDeleteList; // eax
  int v4; // edi

  m_pDeleteList = this->m_pDeleteList;
  if ( m_pDeleteList != nullptr )
  {
    v4 = 0;
    if ( m_pDeleteList->m_Size > 0 )
    {
      do
      {
        if ( wakeObjects )
          IVP_Real_Object::ensure_in_simulation(this: this->m_pDeleteList->m_Memory.m_pMemory[v4]);
        IVP_Real_Object::unlink_contact_points_for_object(
          this: this->m_pObject,
          pOtherObject: this->m_pDeleteList->m_Memory.m_pMemory[v4++]);
      }
      while ( v4 < this->m_pDeleteList->m_Size );
    }
    this->m_pFriction = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016CF0
// Name: public: virtual void CFrictionSnapshot::MarkContactForDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrictionSnapshot::MarkContactForDelete(CFrictionSnapshot *this)
{
  CUtlVector<IVP_Real_Object *,CUtlMemory<IVP_Real_Object *,int> > *v2; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *m_pDeleteList; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  CUtlSymbolTable::StringPool_t **v6; // ecx
  int v7; // eax
  IVP_Real_Object **v8; // eax
  IVP_Real_Object *pObject; // [esp+8h] [ebp-4h]

  pObject = this->m_pContactPoint->synapse[this->m_synapseIndex == 0].l_obj;
  if ( pObject != this->m_pObject )
  {
    if ( this->m_pDeleteList == nullptr )
    {
      v2 = (CUtlVector<IVP_Real_Object *,CUtlMemory<IVP_Real_Object *,int> > *)p_malloc(size: 0x14u);
      if ( v2 != nullptr )
      {
        v2->m_Memory.m_pMemory = nullptr;
        v2->m_Memory.m_nAllocationCount = 0;
        v2->m_Memory.m_nGrowSize = 0;
        v2->m_Size = 0;
        v2->m_pElements = nullptr;
      }
      else
      {
        v2 = nullptr;
      }
      this->m_pDeleteList = v2;
    }
    m_pDeleteList = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this->m_pDeleteList;
    m_nAllocationCount = m_pDeleteList->m_nAllocationCount;
    m_pMemory = m_pDeleteList[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CPredictedPhysicsObject *,int>::Grow(this: m_pDeleteList, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pDeleteList[1].m_pMemory;
    v6 = m_pDeleteList->m_pMemory;
    v7 = (char *)m_pDeleteList[1].m_pMemory - (char *)m_pMemory - 1;
    m_pDeleteList[1].m_nAllocationCount = (int)m_pDeleteList->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[(_DWORD)m_pMemory + 1], src: &v6[(_DWORD)m_pMemory], count: 4 * v7);
    v8 = (IVP_Real_Object **)&m_pDeleteList->m_pMemory[(_DWORD)m_pMemory];
    if ( v8 != nullptr )
      *v8 = pObject;
  }
}
