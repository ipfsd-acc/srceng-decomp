// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/guntarget.cpp
// Functions: 15
// ============================================================

#include "game\server\guntarget.h"

//------------------------------------------------------------------------------
// Address: 0x101597F0
// Name: public: virtual struct datamap_t __near * CGunTarget::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CGunTarget::GetDataDescMap(CGunTarget *this)
{
  return &CGunTarget::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10159800
// Name: public: virtual void CGunTarget::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGunTarget::Activate(CGunTarget *this)
{
  CBaseEntity *NextTarget; // esi
  CGunTarget_vtbl *v3; // eax
  __int64 v4; // xmm0_8
  void (__thiscall *Teleport)(CBaseEntity *, const Vector *, const QAngle *, const Vector *, bool); // edx
  Vector nextPos; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  CBaseEntity::Activate(this);
  NextTarget = CBaseEntity::GetNextTarget(this);
  if ( NextTarget != nullptr )
  {
    this->m_hTargetEnt.m_Index = NextTarget->GetRefEHandle(this: NextTarget)->m_Index;
    if ( (NextTarget->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: NextTarget, a2: (int)&savedregs);
    v3 = this->__vftable;
    v4 = *(_QWORD *)&NextTarget->m_vecAbsOrigin.x;
    nextPos.z = NextTarget->m_vecAbsOrigin.z;
    Teleport = v3->Teleport;
    *(_QWORD *)&nextPos.x = v4;
    Teleport(this, a2: &nextPos, a3: nullptr, a4: nullptr, a5: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159890
// Name: public: virtual class Vector CGunTarget::BodyTarget(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CGunTarget::BodyTarget(CGunTarget *this, Vector *result, const Vector *posSrc, bool bNoisy)
{
  float z; // ecx
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&result->x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10159900
// Name: public: virtual int CGunTarget::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGunTarget::OnTakeDamage(CGunTarget *this, const CTakeDamageInfo *info)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // esi
  int v4; // edi
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax

  p_m_iHealth = &this->m_iHealth;
  if ( this->m_iHealth.m_Value > 0 )
  {
    v4 = p_m_iHealth->m_Value - (int)info->m_flDamage;
    if ( p_m_iHealth->m_Value != v4 )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      p_m_iHealth->m_Value = v4;
    }
    if ( p_m_iHealth->m_Value <= 0 )
    {
      if ( p_m_iHealth->m_Value != 0 )
      {
        (*(void (__thiscall **)(CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *, CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *))(p_m_iHealth[-132].m_Value + 732))(
          a1: p_m_iHealth - 132,
          a2: p_m_iHealth);
        p_m_iHealth->m_Value = 0;
      }
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
      CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
      if ( this->m_takedamage.m_Value != 0 )
      {
        this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
        this->m_takedamage.m_Value = 0;
      }
      m_Index = info->m_hInflictor.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      COutputEvent::FireOutput(this: &this->m_OnDeath, pActivator: m_pEntity, pCaller: this, fDelay: 0.0);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10159A00
// Name: public: void CGunTarget::InputStop(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGunTarget::InputStop(CGunTarget *this, inputdata_t *inputdata)
{
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // esi

  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
  p_m_takedamage = &this->m_takedamage;
  if ( p_m_takedamage->m_Value != 0 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *, CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *))(*(_DWORD *)&p_m_takedamage[-554].m_Value + 756))(
      a1: p_m_takedamage - 554,
      a2: p_m_takedamage);
    p_m_takedamage->m_Value = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159AC0
// Name: protected: void CGunTarget::Wait(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGunTarget::Wait(CGunTarget *this)
{
  unsigned int m_Index; // eax
  const char ***v3; // ecx
  const char **v4; // edi
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // esi
  double v6; // st7
  float flDelay; // [esp+44h] [ebp-4h]

  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index != -1
    && (v3 = (const char ***)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (v4 = *v3, *v3 != nullptr) )
  {
    (*((void (__thiscall **)(const char **, const char *, CGunTarget *, CGunTarget *, _DWORD))*v4 + 39))(
      a1: v4,
      a2: "InPass",
      a3: this,
      a4: this,
      a5: 0);
    v6 = ((double (__thiscall *)(const char **))*((_DWORD *)*v4 + 77))(a1: v4);
    this->m_flWait = v6;
    this->m_target.pszValue = v4[44];
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CGunTarget::Next;
    if ( v6 == 0.0 )
    {
      CGunTarget::Next(this);
    }
    else
    {
      flDelay = v6;
      CBaseEntity::SetMoveDoneTime(this, flDelay);
    }
  }
  else
  {
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
    CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
    p_m_takedamage = &this->m_takedamage;
    if ( p_m_takedamage->m_Value != 0 )
    {
      (*(void (__thiscall **)(CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *, CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *))(*(_DWORD *)&p_m_takedamage[-554].m_Value + 756))(
        a1: p_m_takedamage - 554,
        a2: p_m_takedamage);
      p_m_takedamage->m_Value = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159C20
// Name: protected: void CGunTarget::Next(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGunTarget::Next(CGunTarget *this@<ecx>, int a2@<ebp>)
{
  CBaseEntity *NextTarget; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // esi
  float flDelay; // [esp+4h] [ebp-8h]

  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  NextTarget = CBaseEntity::GetNextTarget(this);
  if ( NextTarget != nullptr )
    this->m_hTargetEnt.m_Index = NextTarget->GetRefEHandle(this: NextTarget)->m_Index;
  else
    this->m_hTargetEnt.m_Index = -1;
  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    flDelay = this->m_flSpeed;
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CGunTarget::Wait;
    CBaseToggle::LinearMove(this, a2, vecDest: (const Vector *)&m_pEntity[175], flSpeed: flDelay);
  }
  else
  {
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
    CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
    p_m_takedamage = &this->m_takedamage;
    if ( p_m_takedamage->m_Value != 0 )
    {
      (*(void (__thiscall **)(CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *, CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *))(*(_DWORD *)&p_m_takedamage[-554].m_Value + 756))(
        a1: p_m_takedamage - 554,
        a2: p_m_takedamage);
      p_m_takedamage->m_Value = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159D00
// Name: protected: void CGunTarget::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGunTarget::Start(CGunTarget *this@<ecx>, int a2@<ebp>)
{
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // edi
  CBaseEntity *NextTarget; // eax
  unsigned int m_Index; // eax

  p_m_takedamage = &this->m_takedamage;
  if ( this->m_takedamage.m_Value != 2 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    p_m_takedamage->m_Value = 2;
  }
  CBaseEntity::AddFlag(this, flags: 0x20000);
  NextTarget = CBaseEntity::GetNextTarget(this);
  if ( NextTarget != nullptr )
    this->m_hTargetEnt.m_Index = NextTarget->GetRefEHandle(this: NextTarget)->m_Index;
  else
    this->m_hTargetEnt.m_Index = -1;
  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( this->m_iHealth.m_Value != this->m_iMaxHealth.m_Value )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      this->m_iHealth.m_Value = this->m_iMaxHealth.m_Value;
    }
    CGunTarget::Next(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159DD0
// Name: public: void CGunTarget::InputStart(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __userpurge CGunTarget::InputStart(CGunTarget *this@<ecx>, int a2@<ebp>, inputdata_t *inputdata)
{
  CGunTarget::Start(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10159DE0
// Name: public: void CGunTarget::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGunTarget::InputToggle(CGunTarget *this@<ecx>, int a2@<ebp>, inputdata_t *inputdata)
{
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // esi

  if ( this->m_on )
  {
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
    CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
    p_m_takedamage = &this->m_takedamage;
    if ( p_m_takedamage->m_Value != 0 )
    {
      (*(void (__thiscall **)(CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *, CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *))(*(_DWORD *)&p_m_takedamage[-554].m_Value + 756))(
        a1: p_m_takedamage - 554,
        a2: p_m_takedamage);
      p_m_takedamage->m_Value = 0;
    }
  }
  else
  {
    CGunTarget::Start(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015A1E0
// Name: public: virtual void CGunTarget::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGunTarget::Spawn(CGunTarget *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+18h] [ebp-4h] BYREF

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CGunTarget *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  if ( this->m_flSpeed == 0.0 )
    this->m_flSpeed = 100.0;
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 0;
  }
  CBaseEntity::AddFlag(this, flags: 0x4000);
  this->m_on = false;
  if ( this->m_iMaxHealth.m_Value != this->m_iHealth.m_Value )
  {
    this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
    this->m_iMaxHealth.m_Value = this->m_iHealth.m_Value;
  }
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CGunTarget::Start;
    CBaseEntity::SetMoveDoneTime(this, flDelay: 0.30000001);
  }
  this->CreateVPhysics(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A2DD0
// Name: public: virtual int CGunTarget::BloodColor(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGunTarget::BloodColor(vgui::TreeView *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10405150
// Name: CGunTarget_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGunTarget_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGunTarget>(__formal: nullptr);
  CGunTarget_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10159A50
// Name: class CGunTarget __near * _CreateEntityTemplate<class CGunTarget>(class CGunTarget __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGunTarget *__cdecl _CreateEntityTemplate<CGunTarget>(CGunTarget *newEnt, const char *className)
{
  CBaseToggle *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseToggle *)CBaseEntity::operator new(stAllocateBlock: 0x3ECu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseToggle::CBaseToggle(this: v2);
    *v3 = &CGunTarget::`vftable';
    v3[244] = -1;
    v3[245] = 0;
    v3[248] = -1;
    v3[249] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CGunTarget *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159E60
// Name: struct datamap_t __near * DataMapInit<class CGunTarget>(class CGunTarget __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGunTarget>()
{
  if ( (_S2_134 & 1) == 0 )
  {
    _S2_134 |= 1u;
    nameHolder_233.m_pszBase = "CGunTarget";
    nameHolder_233.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_233.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_233.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_233.m_Names.m_Size = 0;
    nameHolder_233.m_Names.m_pElements = nullptr;
    nameHolder_233.m_nLenBase = 10;
    atexit(func: DataMapInit_CGunTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGunTarget::m_DataMap.baseMap = &CBaseToggle::m_DataMap;
  if ( (_S2_134 & 2) == 0 )
  {
    _S2_134 |= 2u;
    dataDesc_220[3].fieldName = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_233, pszIdentifier: "Next");
    dataDesc_220[3].flags = 32;
    dataDesc_220[3].fieldOffset = 0;
    dataDesc_220[3].fieldSize = 1;
    dataDesc_220[3].externalName = nullptr;
    dataDesc_220[3].pSaveRestoreOps = nullptr;
    dataDesc_220[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CGunTarget::Next;
    *(_QWORD *)&dataDesc_220[3].td = 0;
    *(_QWORD *)&dataDesc_220[3].override_field = 0;
    *(_QWORD *)&dataDesc_220[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_220[3].flatOffset[1] = 0;
    dataDesc_220[4].fieldType = FIELD_VOID;
    dataDesc_220[4].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_233,
                                  pszIdentifier: "Start");
    dataDesc_220[4].fieldOffset = 0;
    dataDesc_220[4].fieldSize = 1;
    dataDesc_220[4].flags = 32;
    dataDesc_220[4].externalName = nullptr;
    dataDesc_220[4].pSaveRestoreOps = nullptr;
    dataDesc_220[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CGunTarget::Start;
    *(_QWORD *)&dataDesc_220[4].td = 0;
    *(_QWORD *)&dataDesc_220[4].override_field = 0;
    *(_QWORD *)&dataDesc_220[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_220[4].flatOffset[1] = 0;
    dataDesc_220[5].fieldType = FIELD_VOID;
    dataDesc_220[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_233, pszIdentifier: "Wait");
    dataDesc_220[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_220[5].td = 0;
    *(_QWORD *)&dataDesc_220[5].override_field = 0;
    *(_QWORD *)&dataDesc_220[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_220[5].flatOffset[1] = 0;
    dataDesc_220[5].flags = 32;
    dataDesc_220[6].fieldSize = 1;
    *(_QWORD *)&dataDesc_220[6].td = 0;
    *(_QWORD *)&dataDesc_220[6].override_field = 0;
    *(_QWORD *)&dataDesc_220[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_220[6].flatOffset[1] = 0;
    dataDesc_220[5].fieldOffset = 0;
    dataDesc_220[5].externalName = nullptr;
    dataDesc_220[5].pSaveRestoreOps = nullptr;
    dataDesc_220[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CGunTarget::Wait;
    dataDesc_220[6].fieldType = FIELD_VOID;
    dataDesc_220[6].fieldName = "InputStart";
    dataDesc_220[6].fieldOffset = 0;
    dataDesc_220[6].flags = 8;
    dataDesc_220[6].externalName = "Start";
    dataDesc_220[6].pSaveRestoreOps = nullptr;
    dataDesc_220[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CGunTarget::InputStart;
    dataDesc_220[7].fieldType = FIELD_VOID;
    dataDesc_220[7].fieldName = "InputStop";
    dataDesc_220[7].fieldOffset = 0;
    dataDesc_220[7].fieldSize = 1;
    dataDesc_220[7].flags = 8;
    dataDesc_220[7].externalName = "Stop";
    dataDesc_220[7].pSaveRestoreOps = nullptr;
    dataDesc_220[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CGunTarget::InputStop;
    *(_QWORD *)&dataDesc_220[7].td = 0;
    *(_QWORD *)&dataDesc_220[7].override_field = 0;
    *(_QWORD *)&dataDesc_220[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_220[7].flatOffset[1] = 0;
    dataDesc_220[8].fieldSize = 1;
    *(_QWORD *)&dataDesc_220[8].td = 0;
    *(_QWORD *)&dataDesc_220[8].override_field = 0;
    *(_QWORD *)&dataDesc_220[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_220[8].flatOffset[1] = 0;
    dataDesc_220[8].fieldType = FIELD_VOID;
    dataDesc_220[8].fieldName = "InputToggle";
    dataDesc_220[8].fieldOffset = 0;
    dataDesc_220[8].flags = 8;
    dataDesc_220[8].externalName = "Toggle";
    dataDesc_220[8].pSaveRestoreOps = nullptr;
    dataDesc_220[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CGunTarget::InputToggle;
    dataDesc_220[9].fieldType = FIELD_CUSTOM;
    dataDesc_220[9].fieldName = "m_OnDeath";
    dataDesc_220[9].fieldOffset = 980;
    *(_DWORD *)&dataDesc_220[9].fieldSize = 1441793;
    dataDesc_220[9].externalName = "OnDeath";
    dataDesc_220[9].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_220[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_220[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_220[9].override_count = 0;
    *(_QWORD *)dataDesc_220[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_220[9].flatGroup = 0;
  }
  CGunTarget::m_DataMap.dataNumFields = 9;
  CGunTarget::m_DataMap.dataDesc = &dataDesc_220[1];
  return &CGunTarget::m_DataMap;
}
