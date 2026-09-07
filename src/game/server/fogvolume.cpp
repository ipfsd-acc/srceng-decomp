// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/fogvolume.cpp
// Functions: 11
// ============================================================

#include "game\server\fogvolume.h"

//------------------------------------------------------------------------------
// Address: 0x1012CA90
// Name: private: virtual struct datamap_t __near * CFogVolume::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFogVolume::GetDataDescMap(CFogVolume *this)
{
  return &CFogVolume::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1012CAA0
// Name: public: virtual void CFogVolume::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogVolume::Spawn(CFogVolume *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+8h] [ebp-4h] BYREF

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: 4u);
  v2 = *(const char **)((int (__thiscall *)(CFogVolume *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1012CB60
// Name: public: static class CFogVolume __near * CFogVolume::FindFogVolumeForPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CFogVolume *__cdecl CFogVolume::FindFogVolumeForPosition(const Vector *position)
{
  CFogVolume *v1; // edi
  unsigned __int8 m_Value; // al
  float *v3; // eax
  const matrix3x4_t *v4; // eax
  float *v5; // eax
  const Vector *v6; // eax
  const char *pszValue; // eax
  const char *v8; // esi
  const char *v9; // edx
  const Vector *v11; // [esp+18h] [ebp-128h]
  char fogVolumeName[256]; // [esp+30h] [ebp-110h] BYREF
  Vector vecRelativeCenter; // [esp+130h] [ebp-10h] BYREF
  int i; // [esp+13Ch] [ebp-4h]

  v1 = nullptr;
  for ( i = 0; i < TheFogVolumes.m_Size; ++i )
  {
    v1 = TheFogVolumes.m_Memory.m_pMemory[i];
    if ( (v1->m_Collision.m_usSolidFlags.m_Value & 0x40) != 0
      || (m_Value = v1->m_Collision.m_nSolidType.m_Value) == 2
      || m_Value == 0
      || (v3 = (float *)v1->m_Collision.GetCollisionAngles(this: &v1->m_Collision), vec3_angle.x == *v3)
      && vec3_angle.y == v3[1]
      && vec3_angle.z == v3[2] )
    {
      v5 = (float *)v1->m_Collision.GetCollisionOrigin(this: &v1->m_Collision);
      vecRelativeCenter.x = position->x - *v5;
      vecRelativeCenter.y = position->y - v5[1];
      vecRelativeCenter.z = position->z - v5[2];
    }
    else
    {
      v4 = v1->m_Collision.CollisionToWorldTransform(this: &v1->m_Collision);
      VectorITransform(in1: &position->x, in2: v4, out: &vecRelativeCenter.x);
    }
    v11 = v1->m_Collision.OBBMaxs(this: &v1->m_Collision);
    v6 = v1->m_Collision.OBBMins(this: &v1->m_Collision);
    if ( IsBoxIntersectingSphere(boxMin: v6, boxMax: v11, center: &vecRelativeCenter, radius: 1.0) )
      break;
    v1 = nullptr;
  }
  if ( fog_volume_debug.m_pParent == nullptr || fog_volume_debug.m_pParent->m_Value.m_nValue == 0 )
    return v1;
  if ( v1 == nullptr )
  {
    engine->Con_NPrintf(
      this: engine,
      a2: 0,
      a3: "No Fog Volume found at given position (%f %f %f)",
      position->x,
      position->y,
      position->z);
    return v1;
  }
  v1->GetKeyValue(this: v1, a2: "targetname", a3: fogVolumeName, a4: 256);
  engine->Con_NPrintf(
    this: engine,
    a2: 0,
    a3: "Fog Volume %s found at position (%f %f %f)",
    fogVolumeName,
    position->x,
    position->y,
    position->z);
  pszValue = v1->m_colorCorrectionName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v8 = v1->m_postProcessName.pszValue;
  if ( v8 == nullptr )
    v8 = locale;
  v9 = v1->m_fogName.pszValue;
  if ( v9 == nullptr )
    v9 = locale;
  engine->Con_NPrintf(this: engine, a2: 1, a3: "Fog: %s, post process: %s, color correct: %s", v9, v8, pszValue);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1012CDF0
// Name: public: void CFogVolume::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogVolume::InputDisable(CFogVolume *this, inputdata_t *data)
{
  bool v3; // zf
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  v3 = !this->m_bInFogVolumesList;
  this->m_bDisabled = true;
  if ( !v3 )
  {
    src = (vgui::TreeNode *)this;
    CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&TheFogVolumes,
      &src);
    this->m_bInFogVolumesList = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012CE30
// Name: private: void CFogVolume::AddToGlobalList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogVolume::AddToGlobalList(CFogVolume *this)
{
  int m_Size; // eax
  int v3; // esi
  CFogVolume **m_pMemory; // ecx
  int v5; // eax
  CFogVolume **v6; // eax

  if ( !this->m_bInFogVolumesList )
  {
    m_Size = TheFogVolumes.m_Size;
    v3 = TheFogVolumes.m_Size;
    if ( TheFogVolumes.m_Size + 1 > TheFogVolumes.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&TheFogVolumes,
        num: TheFogVolumes.m_Size - TheFogVolumes.m_Memory.m_nAllocationCount + 1);
      m_Size = TheFogVolumes.m_Size;
    }
    m_pMemory = TheFogVolumes.m_Memory.m_pMemory;
    TheFogVolumes.m_Size = m_Size + 1;
    v5 = m_Size - v3;
    TheFogVolumes.m_pElements = TheFogVolumes.m_Memory.m_pMemory;
    if ( v5 > 0 )
    {
      _V_memmove(
        dest: &TheFogVolumes.m_Memory.m_pMemory[v3 + 1],
        src: &TheFogVolumes.m_Memory.m_pMemory[v3],
        count: 4 * v5);
      m_pMemory = TheFogVolumes.m_Memory.m_pMemory;
    }
    v6 = &m_pMemory[v3];
    if ( v6 != nullptr )
      *v6 = this;
    this->m_bInFogVolumesList = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012CEB0
// Name: public: void CFogVolume::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogVolume::InputEnable(CFogVolume *this, inputdata_t *data)
{
  this->m_bDisabled = false;
  CFogVolume::AddToGlobalList(this);
}

//------------------------------------------------------------------------------
// Address: 0x1012CEC0
// Name: public: virtual void CFogVolume::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogVolume::Activate(CFogVolume *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  void *v4; // eax
  const char *v5; // eax
  CBasePlayer *v6; // eax
  void *v7; // eax
  const char *v8; // eax
  CBasePlayer *v9; // eax
  void *v10; // eax

  CBaseEntity::Activate(this);
  pszValue = this->m_fogName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  v4 = __RTDynamicCast(
         inptr: EntityByName,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CFogController `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
    this->m_hFogController.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
  else
    this->m_hFogController.m_Index = -1;
  v5 = this->m_postProcessName.pszValue;
  if ( v5 == nullptr )
    v5 = locale;
  v6 = CGlobalEntityList::FindEntityByName(
         this: &gEntList,
         pStartEntity: nullptr,
         szName: v5,
         pSearchingEntity: nullptr,
         pActivator: nullptr,
         pCaller: nullptr,
         pFilter: nullptr);
  v7 = __RTDynamicCast(
         inptr: v6,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CPostProcessController `RTTI Type Descriptor',
         isReference: 0);
  if ( v7 != nullptr )
    this->m_hPostProcessController.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 8))(a1: v7);
  else
    this->m_hPostProcessController.m_Index = -1;
  v8 = this->m_colorCorrectionName.pszValue;
  if ( v8 == nullptr )
    v8 = locale;
  v9 = CGlobalEntityList::FindEntityByName(
         this: &gEntList,
         pStartEntity: nullptr,
         szName: v8,
         pSearchingEntity: nullptr,
         pActivator: nullptr,
         pCaller: nullptr,
         pFilter: nullptr);
  v10 = __RTDynamicCast(
          inptr: v9,
          VfDelta: 0,
          SrcType: &CBaseEntity `RTTI Type Descriptor',
          TargetType: &CColorCorrection `RTTI Type Descriptor',
          isReference: 0);
  if ( v10 != nullptr )
    this->m_hColorCorrectionController.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 8))(a1: v10);
  else
    this->m_hColorCorrectionController.m_Index = -1;
  if ( !this->m_bDisabled )
    CFogVolume::AddToGlobalList(this);
}

//------------------------------------------------------------------------------
// Address: 0x10403740
// Name: CFogVolume_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFogVolume_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFogVolume>(__formal: nullptr);
  CFogVolume_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012CAF0
// Name: class CFogVolume __near * _CreateEntityTemplate<class CFogVolume>(class CFogVolume __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFogVolume *__cdecl _CreateEntityTemplate<CFogVolume>(CFogVolume *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x370u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3->__vftable = (CBaseEntity_vtbl *)&CFogVolume::`vftable';
    v3[1].m_Network.__vftable = (CServerNetworkProperty_vtbl *)-1;
    v3[1].m_Network.__vftable = (IEventRegisterCallback_vtbl *)-1;
    v3[1].m_Network.m_pOuter = (CBaseEntity *)-1;
    LOWORD(v3[1].m_Network.m_pPev) = 0;
    v3->PostConstructor(this: v3, a2: className);
    return (CFogVolume *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D000
// Name: struct datamap_t __near * DataMapInit<class CFogVolume>(class CFogVolume __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFogVolume>()
{
  if ( (_S2_108 & 1) == 0 )
  {
    _S2_108 |= 1u;
    nameHolder_206.m_pszBase = "CFogVolume";
    nameHolder_206.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_206.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_206.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_206.m_Names.m_Size = 0;
    nameHolder_206.m_Names.m_pElements = nullptr;
    nameHolder_206.m_nLenBase = 10;
    atexit(func: DataMapInit_CFogVolume__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFogVolume::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFogVolume::m_DataMap.dataNumFields = 9;
  CFogVolume::m_DataMap.dataDesc = &dataDesc_196[1];
  return &CFogVolume::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10403750
// Name: _dynamic_initializer_for__g_CTEFoundryHelpers_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEFoundryHelpers_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEFoundryHelpers_ClassReg,
           pNetworkName: "CTEFoundryHelpers",
           pTable: &DT_TEFoundryHelpers::g_SendTable);
}
