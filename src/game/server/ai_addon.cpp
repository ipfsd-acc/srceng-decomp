// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_addon.cpp
// Functions: 20
// ============================================================

#include "game\server\ai_addon.h"

//------------------------------------------------------------------------------
// Address: 0x10010CF0
// Name: public: bool CAI_ClassScheduleIdSpace::Init(char const __near *,class CAI_GlobalScheduleNamespace __near *,class CAI_ClassScheduleIdSpace __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_ClassScheduleIdSpace::Init(
        CAI_ClassScheduleIdSpace *this,
        const char *pszClassName,
        CAI_GlobalScheduleNamespace *pGlobalNamespace,
        CAI_ClassScheduleIdSpace *pParentIDSpace)
{
  CAI_LocalIdSpace *p_m_ScheduleIds; // eax
  CAI_LocalIdSpace *v6; // eax
  CAI_LocalIdSpace *v7; // eax
  BOOL result; // eax

  this->m_pszClassName = pszClassName;
  if ( pParentIDSpace != nullptr )
    p_m_ScheduleIds = &pParentIDSpace->m_ScheduleIds;
  else
    p_m_ScheduleIds = nullptr;
  result = false;
  if ( CAI_LocalIdSpace::Init(
         this: &this->m_ScheduleIds,
         pGlobalNamespace: &pGlobalNamespace->m_ScheduleNamespace,
         pParentIDSpace: p_m_ScheduleIds) )
  {
    v6 = pParentIDSpace != nullptr ? &pParentIDSpace->m_TaskIds : nullptr;
    if ( CAI_LocalIdSpace::Init(
           this: &this->m_TaskIds,
           pGlobalNamespace: &pGlobalNamespace->m_TaskNamespace,
           pParentIDSpace: v6) )
    {
      v7 = pParentIDSpace != nullptr ? &pParentIDSpace->m_ConditionIds : nullptr;
      if ( CAI_LocalIdSpace::Init(
             this: &this->m_ConditionIds,
             pGlobalNamespace: &pGlobalNamespace->m_ConditionNamespace,
             pParentIDSpace: v7) )
      {
        return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010D70
// Name: public: bool Vector::operator==(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Vector::operator==(Vector *this, const Vector *src)
{
  return src->x == this->x && src->y == this->y && src->z == this->z;
}

//------------------------------------------------------------------------------
// Address: 0x10010DB0
// Name: public: void CBaseEdict::StateChanged(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEdict::StateChanged(CBaseEdict *this, unsigned __int16 offset)
{
  IChangeInfoAccessor *v3; // eax
  CEdictChangeInfo *v4; // ecx
  unsigned __int16 v5; // dx
  int m_nChangeOffsets; // edx
  int m_nChangeInfos; // ecx
  CEdictChangeInfo *v8; // eax

  if ( (this->m_fStateFlags & 0x100) == 0 )
  {
    this->m_fStateFlags |= 1u;
    v3 = CBaseEdict::GetChangeAccessor(this);
    if ( v3->m_iChangeInfoSerialNumber == g_pSharedChangeInfo->m_iSerialNumber )
    {
      v4 = &g_pSharedChangeInfo->m_ChangeInfos[v3->m_iChangeInfo];
      v5 = 0;
      if ( g_pSharedChangeInfo->m_ChangeInfos[v3->m_iChangeInfo].m_nChangeOffsets != 0 )
      {
        while ( v4->m_ChangeOffsets[v5] != offset )
        {
          if ( ++v5 >= g_pSharedChangeInfo->m_ChangeInfos[v3->m_iChangeInfo].m_nChangeOffsets )
            goto LABEL_6;
        }
      }
      else
      {
LABEL_6:
        m_nChangeOffsets = g_pSharedChangeInfo->m_ChangeInfos[v3->m_iChangeInfo].m_nChangeOffsets;
        if ( m_nChangeOffsets == 19 )
        {
          v3->m_iChangeInfoSerialNumber = 0;
          this->m_fStateFlags |= 0x100u;
        }
        else
        {
          v4->m_ChangeOffsets[m_nChangeOffsets] = offset;
          ++v4->m_nChangeOffsets;
        }
      }
    }
    else
    {
      m_nChangeInfos = g_pSharedChangeInfo->m_nChangeInfos;
      if ( m_nChangeInfos == 100 )
      {
        v3->m_iChangeInfoSerialNumber = 0;
        this->m_fStateFlags |= 0x100u;
      }
      else
      {
        v3->m_iChangeInfo = m_nChangeInfos;
        ++g_pSharedChangeInfo->m_nChangeInfos;
        v3->m_iChangeInfoSerialNumber = g_pSharedChangeInfo->m_iSerialNumber;
        v8 = &g_pSharedChangeInfo->m_ChangeInfos[v3->m_iChangeInfo];
        v8->m_ChangeOffsets[0] = offset;
        v8->m_nChangeOffsets = 1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010E90
// Name: public: char const __near * variant_t::String(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall variant_t::String(variant_t *this)
{
  const char *result; // eax

  if ( this->fieldType != FIELD_STRING )
    return variant_t::ToString(this);
  result = (const char *)this->iVal;
  if ( this->iVal == 0 )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010EB0
// Name: public: class Vector const __near & CBaseEntity::GetAbsOrigin(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseEntity::GetAbsOrigin(CBaseEntity *this)
{
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  return &this->m_vecAbsOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x10010ED0
// Name: public: class QAngle const __near & CBaseEntity::GetAbsAngles(void)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CBaseEntity::GetAbsAngles(CBaseEntity *this)
{
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  return &this->m_angAbsRotation;
}

//------------------------------------------------------------------------------
// Address: 0x10010EF0
// Name: public: class Vector const __near & CBaseEntity::GetAbsVelocity(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseEntity::GetAbsVelocity(CBaseEntity *this)
{
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this);
  return &this->m_vecAbsVelocity;
}

//------------------------------------------------------------------------------
// Address: 0x10010F10
// Name: public: int CBaseEntity::GetSolidFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::GetSolidFlags(CBaseEntity *this)
{
  return this->m_Collision.GetSolidFlags(this: &this->m_Collision);
}

//------------------------------------------------------------------------------
// Address: 0x10010F60
// Name: public: void CAI_AddOn::InputInstall(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_AddOn::InputInstall(CAI_AddOn *this, inputdata_t *data)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  CAI_BaseNPC *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // [esp-4h] [ebp-Ch]

  if ( data->value.fieldType == FIELD_STRING )
  {
    pszValue = data->value.iszVal.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
  }
  else
  {
    pszValue = variant_t::ToString(this: &data->value);
  }
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  v5 = (CAI_BaseNPC *)__RTDynamicCast(
                        inptr: EntityByName,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CAI_BaseNPC `RTTI Type Descriptor',
                        isReference: 0);
  if ( v5 != nullptr )
  {
    this->Install(this, a2: v5, a3: true);
  }
  else
  {
    if ( data->value.fieldType == FIELD_STRING )
    {
      v6 = data->value.iszVal.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
    }
    else
    {
      v6 = variant_t::ToString(this: &data->value);
    }
    v7 = (const char *)((int (__thiscall *)(CAI_Agent *, const char *))this->GetDebugName)(a1: &this->CAI_Agent, a2: v6);
    DevMsg(a1: " AddOn: %s couldn't find Host %s\n", v7, v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011010
// Name: public: void CAI_AddOn::DispatchAddOnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_AddOn::DispatchAddOnThink(CAI_AddOn *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax
  float thinkTime; // [esp+0h] [ebp-10h]

  m_Index = this->m_hNPCHost.m_Index;
  if ( m_Index == -1
    || (v3 = (unsigned __int16)m_Index,
        v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v5 = HIWORD(m_Index),
        v4->m_SerialNumber != v5)
    || v4->m_pEntity == nullptr
    || ((v6 = v3, v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5,
                  v8 = &g_pEntityList->m_EntPtrArray[v6],
                  !v7)
      ? (m_pEntity = nullptr)
      : (m_pEntity = v8->m_pEntity),
        m_pEntity->__vftable[22].GetRefEHandle(this: m_pEntity) != nullptr) )
  {
    CAI_Agent::Think(this: &this->CAI_Agent);
    thinkTime = ((double (__thiscall *)(CAI_AddOn *))this->GetThinkInterval)(a1: this) + gpGlobals->curtime;
    CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  }
  else
  {
    this->EjectFromHost(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100110B0
// Name: public: void CAI_AddOn::InputRemove(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_AddOn::InputRemove(CAI_AddOn *this, inputdata_t *data)
{
  this->Remove(this);
  this->m_hNPCHost.m_Index = -1;
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  this->SetParent(this, a2: nullptr, a3: -1);
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x10011100
// Name: public: CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(CDatadescGeneratedNameHolder *this)
{
  int i; // edi
  char **m_pMemory; // eax

  for ( i = 0; i < this->m_Names.m_Size; ++i )
    free(pMem: this->m_Names.m_Memory.m_pMemory[i]);
  this->m_Names.m_Size = 0;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Names.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Names.m_Memory.m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Names.m_Memory.m_pMemory;
  this->m_Names.m_pElements = m_pMemory;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011180
// Name: public: void CBaseEntity::SetMoveCollide(enum MoveCollide_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetMoveCollide(CBaseEntity *this, MoveCollide_t val)
{
  CNetworkVarBase<unsigned char,CBaseEntity::NetworkVar_m_MoveCollide> *p_m_MoveCollide; // esi
  edict_t *m_pPev; // ecx

  p_m_MoveCollide = &this->m_MoveCollide;
  if ( this->m_MoveCollide.m_Value != (_BYTE)val )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_MoveCollide->m_Value = val;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xD7u);
      p_m_MoveCollide->m_Value = val;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100111D0
// Name: public: void CBaseEntity::RemoveEffects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::RemoveEffects(CBaseEntity *this, int nEffects)
{
  int m_Value; // eax
  int v4; // esi
  edict_t *m_pPev; // ecx

  m_Value = this->m_fEffects.m_Value;
  v4 = m_Value & ~nEffects;
  if ( m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v4;
  }
  if ( (nEffects & 0x20) != 0 )
  {
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011240
// Name: public: char const __near * CDatadescGeneratedNameHolder::GenerateName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDatadescGeneratedNameHolder::GenerateName(CDatadescGeneratedNameHolder *this, char *pszIdentifier)
{
  char *v4; // eax
  const char *m_pszBase; // ecx
  char *v6; // edi
  char *v7; // edx
  char v8; // al
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v12; // eax
  char **v13; // eax
  char *pBuf; // [esp+14h] [ebp+8h]

  v4 = (char *)operator new(nSize: this->m_nLenBase + strlen(pszIdentifier) + 1);
  m_pszBase = this->m_pszBase;
  v6 = v4;
  pBuf = v4;
  v7 = v4;
  do
  {
    v8 = *m_pszBase;
    *v7++ = *m_pszBase++;
  }
  while ( v8 != 0 );
  strcat(v6, pszIdentifier);
  m_Size = this->m_Names.m_Size;
  m_nAllocationCount = this->m_Names.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Names,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Names.m_Size;
  m_pMemory = this->m_Names.m_Memory.m_pMemory;
  v12 = this->m_Names.m_Size - m_Size - 1;
  this->m_Names.m_pElements = m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
  v13 = &this->m_Names.m_Memory.m_pMemory[m_Size];
  if ( v13 != nullptr )
    *v13 = pBuf;
  return pBuf;
}

//------------------------------------------------------------------------------
// Address: 0x103FA570
// Name: CAI_AddOn_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_AddOn_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_AddOn>(__formal: nullptr);
  CAI_AddOn_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011310
// Name: struct datamap_t __near * DataMapInit<class CAI_AddOn>(class CAI_AddOn __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_AddOn>()
{
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    nameHolder.m_pszBase = "CAI_AddOn";
    nameHolder.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder.m_Names.m_Size = 0;
    nameHolder.m_Names.m_pElements = nullptr;
    nameHolder.m_nLenBase = 9;
    atexit(func: DataMapInit_CAI_AddOn__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_AddOn::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S2 & 2) == 0 )
  {
    _S2 |= 2u;
    dataDesc[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                              this: &nameHolder,
                              pszIdentifier: "DispatchAddOnThink");
    dataDesc[2].flags = 32;
    dataDesc[3].fieldSize = 1;
    dataDesc[4].fieldSize = 1;
    dataDesc[2].fieldSize = 1;
    dataDesc[4].fieldType = FIELD_INTEGER;
    dataDesc[4].flags = 2;
    dataDesc[5].fieldType = FIELD_INTEGER;
    dataDesc[5].flags = 2;
    *(_QWORD *)dataDesc[3].flatOffset = 0;
    dataDesc[3].flags = 2;
    dataDesc[5].fieldSize = 1;
    dataDesc[6].fieldSize = 1;
    *(_QWORD *)&dataDesc[2].td = 0;
    *(_QWORD *)&dataDesc[2].override_field = 0;
    *(_QWORD *)&dataDesc[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc[2].flatOffset[1] = 0;
    *(_QWORD *)dataDesc[4].flatOffset = 0;
    dataDesc[2].fieldOffset = 0;
    dataDesc[2].externalName = nullptr;
    dataDesc[2].pSaveRestoreOps = nullptr;
    dataDesc[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_AddOn::DispatchAddOnThink;
    dataDesc[3].fieldType = FIELD_EHANDLE;
    dataDesc[3].fieldName = "m_hPhysReplacement";
    dataDesc[3].fieldOffset = 1384;
    dataDesc[3].externalName = nullptr;
    dataDesc[3].pSaveRestoreOps = nullptr;
    dataDesc[3].inputFunc = nullptr;
    dataDesc[3].td = nullptr;
    dataDesc[3].fieldSizeInBytes = 4;
    dataDesc[3].override_field = nullptr;
    dataDesc[3].override_count = 0;
    dataDesc[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc[3].flatGroup = 0;
    dataDesc[4].fieldName = "m_iPhysReplacementSolidFlags";
    dataDesc[4].fieldOffset = 1388;
    dataDesc[4].externalName = nullptr;
    dataDesc[4].pSaveRestoreOps = nullptr;
    dataDesc[4].inputFunc = nullptr;
    dataDesc[4].td = nullptr;
    dataDesc[4].fieldSizeInBytes = 4;
    dataDesc[4].override_field = nullptr;
    dataDesc[4].override_count = 0;
    dataDesc[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc[4].flatGroup = 0;
    dataDesc[5].fieldName = "m_iPhysReplacementMoveType";
    dataDesc[5].fieldOffset = 1392;
    dataDesc[5].externalName = nullptr;
    dataDesc[5].pSaveRestoreOps = nullptr;
    dataDesc[5].inputFunc = nullptr;
    dataDesc[5].td = nullptr;
    dataDesc[5].fieldSizeInBytes = 4;
    dataDesc[5].override_field = nullptr;
    dataDesc[5].override_count = 0;
    dataDesc[5].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc[5].flatOffset = 0;
    *(_DWORD *)&dataDesc[5].flatGroup = 0;
    dataDesc[6].fieldType = FIELD_VECTOR;
    dataDesc[6].fieldName = "m_angPhysReplacementLocalOrientation";
    dataDesc[6].fieldOffset = 1396;
    dataDesc[6].flags = 2;
    *(_QWORD *)dataDesc[6].flatOffset = 0;
    *(_QWORD *)dataDesc[7].flatOffset = 0;
    dataDesc[7].fieldType = FIELD_VECTOR;
    dataDesc[9].fieldSizeInBytes = 4;
    dataDesc[10].fieldSizeInBytes = 4;
    dataDesc[6].fieldTolerance = 0.0;
    dataDesc[7].fieldTolerance = 0.0;
    dataDesc[8].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc[8].flatOffset = 0;
    dataDesc[9].fieldTolerance = 0.0;
    dataDesc[10].fieldTolerance = 0.0;
    dataDesc[6].externalName = nullptr;
    dataDesc[6].pSaveRestoreOps = nullptr;
    dataDesc[6].inputFunc = nullptr;
    dataDesc[6].td = nullptr;
    dataDesc[6].fieldSizeInBytes = 12;
    dataDesc[6].override_field = nullptr;
    dataDesc[6].override_count = 0;
    *(_DWORD *)&dataDesc[6].flatGroup = 0;
    dataDesc[7].fieldName = "m_vecPhysReplacementDetatchForce";
    dataDesc[7].fieldOffset = 1408;
    dataDesc[7].fieldSize = 1;
    dataDesc[7].flags = 2;
    dataDesc[7].externalName = nullptr;
    dataDesc[7].pSaveRestoreOps = nullptr;
    dataDesc[7].inputFunc = nullptr;
    dataDesc[7].td = nullptr;
    dataDesc[7].fieldSizeInBytes = 12;
    dataDesc[7].override_field = nullptr;
    dataDesc[7].override_count = 0;
    *(_DWORD *)&dataDesc[7].flatGroup = 0;
    dataDesc[8].fieldType = FIELD_BOOLEAN;
    dataDesc[8].fieldName = "m_bWasAttached";
    dataDesc[8].fieldOffset = 1420;
    dataDesc[8].fieldSize = 1;
    dataDesc[8].flags = 2;
    dataDesc[8].externalName = nullptr;
    dataDesc[8].pSaveRestoreOps = nullptr;
    dataDesc[8].inputFunc = nullptr;
    dataDesc[8].td = nullptr;
    dataDesc[8].fieldSizeInBytes = 1;
    dataDesc[8].override_field = nullptr;
    dataDesc[8].override_count = 0;
    *(_DWORD *)&dataDesc[8].flatGroup = 0;
    dataDesc[9].fieldType = FIELD_TIME;
    dataDesc[9].fieldName = "m_flWaitFinished";
    dataDesc[9].fieldOffset = 1424;
    dataDesc[9].fieldSize = 1;
    dataDesc[9].flags = 2;
    dataDesc[9].externalName = nullptr;
    dataDesc[9].pSaveRestoreOps = nullptr;
    dataDesc[9].inputFunc = nullptr;
    dataDesc[9].td = nullptr;
    dataDesc[9].override_field = nullptr;
    dataDesc[9].override_count = 0;
    *(_QWORD *)dataDesc[9].flatOffset = 0;
    *(_DWORD *)&dataDesc[9].flatGroup = 0;
    dataDesc[10].fieldType = FIELD_FLOAT;
    dataDesc[10].fieldName = "m_flNextAttachTime";
    dataDesc[10].fieldOffset = 1432;
    dataDesc[10].fieldSize = 1;
    dataDesc[10].flags = 2;
    dataDesc[10].externalName = nullptr;
    dataDesc[10].pSaveRestoreOps = nullptr;
    dataDesc[10].inputFunc = nullptr;
    dataDesc[10].td = nullptr;
    dataDesc[10].override_field = nullptr;
    dataDesc[10].override_count = 0;
    *(_QWORD *)dataDesc[10].flatOffset = 0;
    *(_DWORD *)&dataDesc[10].flatGroup = 0;
    dataDesc[11].fieldType = FIELD_STRING;
    dataDesc[11].fieldName = "InputInstall";
    dataDesc[11].fieldOffset = 0;
    dataDesc[11].fieldSize = 1;
    *(_QWORD *)&dataDesc[11].td = 0;
    *(_QWORD *)&dataDesc[11].override_field = 0;
    *(_QWORD *)&dataDesc[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc[11].flatOffset[1] = 0;
    dataDesc[11].flags = 8;
    dataDesc[11].externalName = "Install";
    dataDesc[11].pSaveRestoreOps = nullptr;
    dataDesc[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_AddOn::InputInstall;
    dataDesc[12].fieldType = FIELD_VOID;
    dataDesc[12].fieldName = "InputRemove";
    dataDesc[12].fieldOffset = 0;
    *(_DWORD *)&dataDesc[12].fieldSize = 524289;
    dataDesc[12].externalName = "Remove";
    dataDesc[12].pSaveRestoreOps = nullptr;
    dataDesc[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_AddOn::InputRemove;
    *(_QWORD *)&dataDesc[12].td = 0;
    *(_QWORD *)&dataDesc[12].override_field = 0;
    *(_QWORD *)&dataDesc[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc[12].flatOffset[1] = 0;
  }
  CAI_AddOn::m_DataMap.dataNumFields = 12;
  CAI_AddOn::m_DataMap.dataDesc = &dataDesc[1];
  return &CAI_AddOn::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FA580
// Name: _dynamic_initializer_for__CAI_AddOn::gm_ClassScheduleIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_AddOn::gm_ClassScheduleIdSpace__()
{
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_AddOn::gm_ClassScheduleIdSpace.m_ScheduleIds, fIsRoot: false);
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_AddOn::gm_ClassScheduleIdSpace.m_TaskIds, fIsRoot: false);
  return CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_AddOn::gm_ClassScheduleIdSpace.m_ConditionIds, fIsRoot: false);
}

//------------------------------------------------------------------------------
// Address: 0x103FA5B0
// Name: _dynamic_initializer_for__CAI_Agent::gm_ClassScheduleIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_Agent::gm_ClassScheduleIdSpace__()
{
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_Agent::gm_ClassScheduleIdSpace.m_ScheduleIds, fIsRoot: true);
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_Agent::gm_ClassScheduleIdSpace.m_TaskIds, fIsRoot: true);
  return CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_Agent::gm_ClassScheduleIdSpace.m_ConditionIds, fIsRoot: true);
}

//------------------------------------------------------------------------------
// Address: 0x103FA5E0
// Name: _dynamic_initializer_for__CAI_Agent::gm_SchedulingSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CAI_Agent::gm_SchedulingSymbols__()
{
  CAI_GlobalNamespace::CAI_GlobalNamespace(this: &CAI_Agent::gm_SchedulingSymbols.m_ScheduleNamespace);
  CAI_GlobalNamespace::CAI_GlobalNamespace(this: &CAI_Agent::gm_SchedulingSymbols.m_TaskNamespace);
  CAI_GlobalNamespace::CAI_GlobalNamespace(this: &CAI_Agent::gm_SchedulingSymbols.m_ConditionNamespace);
  return atexit(func: dynamic_atexit_destructor_for__CAI_Agent::gm_SchedulingSymbols__);
}
