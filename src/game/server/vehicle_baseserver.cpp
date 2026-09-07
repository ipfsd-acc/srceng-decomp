// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/vehicle_baseserver.cpp
// Functions: 142
// ============================================================

#include "game\server\vehicle_baseserver.h"

//------------------------------------------------------------------------------
// Address: 0x10014340
// Name: public: virtual void CUtlVectorDataOps<class CAI_InterestTarget,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CAI_InterestTarget,10>::Save(
        CUtlVectorDataOps<CAI_InterestTarget,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CAI_InterestTarget *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CAI_InterestTarget *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CAI_InterestTarget *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &CAI_InterestTarget_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100178E0
// Name: public: virtual void CUtlVectorDataOps<class CAI_InterestTarget,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CAI_InterestTarget,10>::Restore(
        CUtlVectorDataOps<CAI_InterestTarget,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<CAI_InterestTarget_t,CUtlMemory<CAI_InterestTarget_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<CAI_InterestTarget_t,CUtlMemory<CAI_InterestTarget_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &CAI_InterestTarget_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<CAI_InterestTarget_t,CUtlMemory<CAI_InterestTarget_t,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E7F0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct UnreachableEnt_t,class CUtlMemory<struct UnreachableEnt_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &UnreachableEnt_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E8B0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct ScriptedNPCInteraction_t,class CUtlMemory<struct ScriptedNPCInteraction_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &ScriptedNPCInteraction_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037AE0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct UnreachableEnt_t,class CUtlMemory<struct UnreachableEnt_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &UnreachableEnt_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037BA0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct ScriptedNPCInteraction_t,class CUtlMemory<struct ScriptedNPCInteraction_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &ScriptedNPCInteraction_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037C60
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct AIChannelScheduleState_t,class CUtlMemory<struct AIChannelScheduleState_t,int>>,10>::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int>>,10>::MakeEmpty(
        CUtlVectorDataOps<CAI_InterestTarget,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  *((_DWORD *)fieldInfo->pField + 3) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100416B0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct AIChannelScheduleState_t,class CUtlMemory<struct AIChannelScheduleState_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &AIChannelScheduleState_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041B20
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct AIChannelScheduleState_t,class CUtlMemory<struct AIChannelScheduleState_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &AIChannelScheduleState_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066B70
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct AI_Waypoint_t,class CUtlMemory<struct AI_Waypoint_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &AI_Waypoint_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100692E0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct AI_Waypoint_t,class CUtlMemory<struct AI_Waypoint_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  int v3; // ebx
  CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> > *pField; // edi
  int (__thiscall *ReadInt)(IRestore *); // eax
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  v3 = 0;
  dataMap.dataDesc = &dataDesc;
  pField = (CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> > *)fieldInfo->pField;
  ReadInt = pRestore->ReadInt;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &AI_Waypoint_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>::RemoveAll(this: pField);
  CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>::InsertMultipleBefore(
    this: pField,
    elem: pField->m_Size,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v3++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100693B0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct AI_Waypoint_t,class CUtlMemory<struct AI_Waypoint_t,int>>,10>::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>,10>::MakeEmpty(
        CUtlVectorDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>::RemoveAll(this: (CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> > *)fieldInfo->pField);
}

//------------------------------------------------------------------------------
// Address: 0x10083650
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<class CAI_ScriptConditionsElement,class CUtlMemory<class CAI_ScriptConditionsElement,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &CAI_ScriptConditionsElement::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085690
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<class CAI_ScriptConditionsElement,class CUtlMemory<class CAI_ScriptConditionsElement,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &CAI_ScriptConditionsElement::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B810
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct AISquadEnemyInfo_t,class CUtlMemory<struct AISquadEnemyInfo_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  _DWORD *pField; // ebx
  int v4; // esi
  ISave *v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF

  pField = fieldInfo->pField;
  v4 = 0;
  v5 = pSave;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &AISquadEnemyInfo_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  fieldInfo = (const SaveRestoreFieldInfo_t *)pField[3];
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    do
      v5->WriteAll(this: v5, a2: (const void *)(*pField + 8 * v4++), a3: &dataMap);
    while ( v4 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008CA90
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct AISquadEnemyInfo_t,class CUtlMemory<struct AISquadEnemyInfo_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int> > *pField; // ebx
  int v4; // esi
  int (__thiscall *ReadInt)(IRestore *); // eax
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int> > *)fieldInfo->pField;
  v4 = 0;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &AISquadEnemyInfo_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v4++], a3: &dataMap);
    while ( v4 < nElems );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F6D0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<class CAnimationLayer,class CUtlMemory<class CAnimationLayer,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &CAnimationLayer::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1490
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<class CAnimationLayer,class CUtlMemory<class CAnimationLayer,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &CAnimationLayer::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>::InsertMultipleBefore(this: pField, elem: 0, num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4EE0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct Relationship_t,class CUtlMemory<struct Relationship_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &Relationship_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9940
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct Relationship_t,class CUtlMemory<struct Relationship_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &Relationship_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7220
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct ResponseContext_t,class CUtlMemory<struct ResponseContext_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &ResponseContext_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8DC0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct thinkfunc_t,class CUtlMemory<struct thinkfunc_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &thinkfunc_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C2200
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct ResponseContext_t,class CUtlMemory<struct ResponseContext_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &ResponseContext_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::InsertMultipleBefore(this: pField, elem: 0, num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4680
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct thinkfunc_t,class CUtlMemory<struct thinkfunc_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &thinkfunc_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>::InsertMultipleBefore(this: pField, elem: 0, num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F68C0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct modifiedconvars_t,class CUtlMemory<struct modifiedconvars_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &modifiedconvars_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7C00
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct modifiedconvars_t,class CUtlMemory<struct modifiedconvars_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &modifiedconvars_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A390
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<class CHandle<class CSceneEntity>,class CUtlMemory<class CHandle<class CSceneEntity>,int>>,13>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>,13>::Restore(
        CUtlVectorDataOps<CUtlVector<CHandle<CAI_BaseNPC>,CUtlMemory<CHandle<CAI_BaseNPC>,int> >,13> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // esi
  int (__thiscall *ReadFields)(IRestore *, const char *, void *, datamap_t *, typedescription_t *, int); // edx
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF

  pField = (CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  dataDesc.fieldType = FIELD_EHANDLE;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 16);
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  v5 = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<CHandle<CFish>,CUtlMemory<CHandle<CFish>,int>>::InsertMultipleBefore(this: pField, elem: 0, num: v5);
  if ( v5 != 0 )
  {
    dataDesc.fieldSizeInBytes = 4 * v5;
    ReadFields = pRestore->ReadFields;
    dataDesc.fieldSize = v5;
    ReadFields(this: pRestore, a2: "elems", a3: pField->m_Memory.m_pMemory, a4: &dataMap, a5: &dataDesc, a6: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159160
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct globalentity_t,class CUtlMemory<struct globalentity_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &globalentity_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159590
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct globalentity_t,class CUtlMemory<struct globalentity_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &globalentity_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>::InsertMultipleBefore(this: pField, elem: 0, num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D800
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct physfollower_t,class CUtlMemory<struct physfollower_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  _DWORD *pField; // ebx
  int v4; // esi
  ISave *v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF

  pField = fieldInfo->pField;
  v4 = 0;
  v5 = pSave;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &physfollower_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  fieldInfo = (const SaveRestoreFieldInfo_t *)pField[3];
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    do
      v5->WriteAll(this: v5, a2: (const void *)(*pField + 8 * v4++), a3: &dataMap);
    while ( v4 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018E2D0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct physfollower_t,class CUtlMemory<struct physfollower_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int> > *pField; // ebx
  int v4; // esi
  int (__thiscall *ReadInt)(IRestore *); // eax
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int> > *)fieldInfo->pField;
  v4 = 0;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &physfollower_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<magnetted_objects_t,CUtlMemory<magnetted_objects_t,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v4++], a3: &dataMap);
    while ( v4 < nElems );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B0400
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct magnetted_objects_t,class CUtlMemory<struct magnetted_objects_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<magnetted_objects_t,CUtlMemory<magnetted_objects_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<magnetted_objects_t,CUtlMemory<magnetted_objects_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  _DWORD *pField; // ebx
  int v4; // esi
  ISave *v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF

  pField = fieldInfo->pField;
  v4 = 0;
  v5 = pSave;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &magnetted_objects_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  fieldInfo = (const SaveRestoreFieldInfo_t *)pField[3];
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    do
      v5->WriteAll(this: v5, a2: (const void *)(*pField + 8 * v4++), a3: &dataMap);
    while ( v4 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B20B0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct magnetted_objects_t,class CUtlMemory<struct magnetted_objects_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<magnetted_objects_t,CUtlMemory<magnetted_objects_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<magnetted_objects_t,CUtlMemory<magnetted_objects_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int> > *pField; // ebx
  int v4; // esi
  int (__thiscall *ReadInt)(IRestore *); // eax
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int> > *)fieldInfo->pField;
  v4 = 0;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &magnetted_objects_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<magnetted_objects_t,CUtlMemory<magnetted_objects_t,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v4++], a3: &dataMap);
    while ( v4 < nElems );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6D70
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<class CBaseEntity __near *,class CUtlMemory<class CBaseEntity __near *,int>>,12>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int>>,12>::Save(
        CUtlVectorDataOps<CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> >,12> *this,
        int fieldInfo,
        ISave *pSave)
{
  const void **v3; // ebx
  ISave *v4; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  int (__thiscall *WriteFields)(ISave *, const char *, const void *, datamap_t *, typedescription_t *, int); // edx
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF

  v3 = *(const void ***)fieldInfo;
  v4 = pSave;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_CLASSPTR;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 16);
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  fieldInfo = (int)v3[3];
  WriteInt_2(this: pSave, a2: &fieldInfo, a3: 1);
  if ( fieldInfo != 0 )
  {
    WriteFields = v4->WriteFields;
    dataDesc.fieldSize = fieldInfo;
    dataDesc.fieldSizeInBytes = 4 * fieldInfo;
    WriteFields(this: v4, a2: "elems", a3: *v3, a4: &dataMap, a5: &dataDesc, a6: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6E30
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct template_t,class CUtlMemory<struct template_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<template_t,CUtlMemory<template_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<template_t,CUtlMemory<template_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<template_t,CUtlMemory<template_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<template_t,CUtlMemory<template_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<template_t,CUtlMemory<template_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &template_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7820
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<class CBaseEntity __near *,class CUtlMemory<class CBaseEntity __near *,int>>,12>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int>>,12>::Restore(
        CUtlVectorDataOps<CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> >,12> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // esi
  int (__thiscall *ReadFields)(IRestore *, const char *, void *, datamap_t *, typedescription_t *, int); // edx
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF

  pField = (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  dataDesc.fieldType = FIELD_CLASSPTR;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 16);
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  v5 = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: v5);
  if ( v5 != 0 )
  {
    dataDesc.fieldSizeInBytes = 4 * v5;
    ReadFields = pRestore->ReadFields;
    dataDesc.fieldSize = v5;
    ReadFields(this: pRestore, a2: "elems", a3: pField->m_Memory.m_pMemory, a4: &dataMap, a5: &dataDesc, a6: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D78E0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct template_t,class CUtlMemory<struct template_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<template_t,CUtlMemory<template_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<template_t,CUtlMemory<template_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<template_t,CUtlMemory<template_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<template_t,CUtlMemory<template_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &template_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<template_t,CUtlMemory<template_t,int>>::InsertMultipleBefore(this: pField, elem: 0, num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FCDC0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct SaveRestoreBlockHeader_t,class CUtlMemory<struct SaveRestoreBlockHeader_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &SaveRestoreBlockHeader_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD190
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct SaveRestoreBlockHeader_t,class CUtlMemory<struct SaveRestoreBlockHeader_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &SaveRestoreBlockHeader_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200180
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<class CHandle<class CBasePlayer>,class CUtlMemory<class CHandle<class CBasePlayer>,int>>,13>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int>>,13>::Save(
        CUtlVectorDataOps<CUtlVector<CHandle<CAI_BaseNPC>,CUtlMemory<CHandle<CAI_BaseNPC>,int> >,13> *this,
        int fieldInfo,
        ISave *pSave)
{
  const void **v3; // ebx
  ISave *v4; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  int (__thiscall *WriteFields)(ISave *, const char *, const void *, datamap_t *, typedescription_t *, int); // edx
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF

  v3 = *(const void ***)fieldInfo;
  v4 = pSave;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EHANDLE;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 16);
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  fieldInfo = (int)v3[3];
  WriteInt_2(this: pSave, a2: &fieldInfo, a3: 1);
  if ( fieldInfo != 0 )
  {
    WriteFields = v4->WriteFields;
    dataDesc.fieldSize = fieldInfo;
    dataDesc.fieldSizeInBytes = 4 * fieldInfo;
    WriteFields(this: v4, a2: "elems", a3: *v3, a4: &dataMap, a5: &dataDesc, a6: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D850
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<int,class CUtlMemory<int,int>>,5>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<int,CUtlMemory<int,int>>,5>::Save(
        CUtlVectorDataOps<CUtlVector<int,CUtlMemory<int,int> >,5> *this,
        int fieldInfo,
        ISave *pSave)
{
  const void **v3; // ebx
  ISave *v4; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  int (__thiscall *WriteFields)(ISave *, const char *, const void *, datamap_t *, typedescription_t *, int); // edx
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF

  v3 = *(const void ***)fieldInfo;
  v4 = pSave;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_INTEGER;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 16);
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  fieldInfo = (int)v3[3];
  WriteInt_2(this: pSave, a2: &fieldInfo, a3: 1);
  if ( fieldInfo != 0 )
  {
    WriteFields = v4->WriteFields;
    dataDesc.fieldSize = fieldInfo;
    dataDesc.fieldSizeInBytes = 4 * fieldInfo;
    WriteFields(this: v4, a2: "elems", a3: *v3, a4: &dataMap, a5: &dataDesc, a6: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021F3E0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<int,class CUtlMemory<int,int>>,5>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<int,CUtlMemory<int,int>>,5>::Restore(
        CUtlVectorDataOps<CUtlVector<int,CUtlMemory<int,int> >,5> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // esi
  int (__thiscall *ReadFields)(IRestore *, const char *, void *, datamap_t *, typedescription_t *, int); // edx
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF

  pField = (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  dataDesc.fieldType = FIELD_INTEGER;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 16);
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  v5 = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: v5);
  if ( v5 != 0 )
  {
    dataDesc.fieldSizeInBytes = 4 * v5;
    ReadFields = pRestore->ReadFields;
    dataDesc.fieldSize = v5;
    ReadFields(this: pRestore, a2: "elems", a3: pField->m_Memory.m_pMemory, a4: &dataMap, a5: &dataDesc, a6: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256210
// Name: public: virtual struct datamap_t __near * vehicle_gear_t::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall vehicle_gear_t::GetDataDescMap(vehicle_gear_t *this)
{
  return &vehicle_gear_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10256220
// Name: public: virtual struct datamap_t __near * vehicle_crashsound_t::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall vehicle_crashsound_t::GetDataDescMap(vehicle_crashsound_t *this)
{
  return &vehicle_crashsound_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10256230
// Name: public: virtual struct datamap_t __near * vehiclesounds_t::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall vehiclesounds_t::GetDataDescMap(vehiclesounds_t *this)
{
  return &vehiclesounds_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10256240
// Name: public: bool CBaseServerVehicle::Initialize(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServerVehicle::Initialize(CBaseServerVehicle *this, const char *pScriptName)
{
  bool result; // al

  result = PhysFindOrAddVehicleScript(pScriptName, pParams: nullptr, pSounds: &this->m_vehicleSounds);
  if ( result )
  {
    this->Precache(this);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10256280
// Name: public: virtual void CBaseServerVehicle::SetVehicle(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::SetVehicle(CBaseServerVehicle *this, CBaseEntity *pVehicle)
{
  this->m_pVehicle = pVehicle;
  this->m_pDrivableVehicle = (IDrivableVehicle *)__RTDynamicCast(
                                                   inptr: pVehicle,
                                                   VfDelta: 0,
                                                   SrcType: &CBaseEntity `RTTI Type Descriptor',
                                                   TargetType: &IDrivableVehicle `RTTI Type Descriptor',
                                                   isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102562B0
// Name: public: virtual class CBaseEntity __near * CBaseServerVehicle::GetDriver(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseServerVehicle::GetDriver(CBaseServerVehicle *this)
{
  return this->GetPassenger(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102562C0
// Name: public: virtual class CBaseCombatCharacter __near * CBaseServerVehicle::GetPassenger(int)
// Source: json
//------------------------------------------------------------------------------
CBaseCombatCharacter *__thiscall CBaseServerVehicle::GetPassenger(CBaseServerVehicle *this, int nRole)
{
  CBaseCombatCharacter *result; // eax

  result = (CBaseCombatCharacter *)this->m_pDrivableVehicle->GetDriver(this: this->m_pDrivableVehicle);
  if ( result != nullptr )
    return result->MyCombatCharacterPointer(this: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102562E0
// Name: public: virtual int CBaseServerVehicle::GetPassengerRole(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServerVehicle::GetPassengerRole(CBaseServerVehicle *this, CBaseCombatCharacter *pPassenger)
{
  return -((int)this->m_pDrivableVehicle->GetDriver(this: this->m_pDrivableVehicle) != (_DWORD)pPassenger);
}

//------------------------------------------------------------------------------
// Address: 0x10256300
// Name: public: virtual bool CBaseServerVehicle::NPC_GetPassengerSeatPosition(class CBaseCombatCharacter __near *,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServerVehicle::NPC_GetPassengerSeatPosition(
        CBaseServerVehicle *this,
        CBaseCombatCharacter *pPassenger,
        Vector *vecResultPos,
        QAngle *vecResultAngles)
{
  int v5; // edi
  CBaseAnimating *v7; // eax
  QAngle vecAngles; // [esp+8h] [ebp-18h] BYREF
  Vector vecPos; // [esp+14h] [ebp-Ch] BYREF

  v5 = this->NPC_GetPassengerSeatAttachment(this, a2: pPassenger);
  if ( v5 == -1 )
    return 0;
  v7 = (CBaseAnimating *)__RTDynamicCast(
                           inptr: this->m_pVehicle,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CBaseAnimating `RTTI Type Descriptor',
                           isReference: 0);
  if ( v7 == nullptr )
    return 0;
  CBaseAnimating::GetAttachment(this: v7, iAttachment: v5, absOrigin: &vecPos, absAngles: &vecAngles);
  if ( vecResultPos != nullptr )
    *vecResultPos = vecPos;
  if ( vecResultAngles != nullptr )
    *vecResultAngles = vecAngles;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102563B0
// Name: public: virtual bool CBaseServerVehicle::NPC_GetPassengerSeatPositionLocal(class CBaseCombatCharacter __near *,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServerVehicle::NPC_GetPassengerSeatPositionLocal(
        CBaseServerVehicle *this,
        CBaseCombatCharacter *pPassenger,
        Vector *vecResultPos,
        QAngle *vecResultAngles)
{
  int v5; // edi
  CBaseAnimating *v7; // esi
  QAngle vecAngles; // [esp+8h] [ebp-18h] BYREF
  Vector vecPos; // [esp+14h] [ebp-Ch] BYREF

  v5 = this->NPC_GetPassengerSeatAttachment(this, a2: pPassenger);
  if ( v5 == -1 )
    return 0;
  v7 = this->m_pVehicle->GetBaseAnimating(this: this->m_pVehicle);
  if ( v7 == nullptr )
    return 0;
  v7->InvalidateBoneCache(this: v7);
  CBaseAnimating::GetAttachmentLocal(this: v7, iAttachment: v5, origin: &vecPos, angles: &vecAngles);
  if ( vecResultPos != nullptr )
    *vecResultPos = vecPos;
  if ( vecResultAngles != nullptr )
    *vecResultAngles = vecAngles;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10256460
// Name: int SeatPrioritySort(class CPassengerSeatTransition const __near *,class CPassengerSeatTransition const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SeatPrioritySort(const CPassengerSeatTransition *s1, const CPassengerSeatTransition *s2)
{
  return s1->m_nPriority > s2->m_nPriority;
}

//------------------------------------------------------------------------------
// Address: 0x10256480
// Name: public: virtual void CBaseServerVehicle::SetupMove(class CBasePlayer __near *,class CUserCmd __near *,class IMoveHelper __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::SetupMove(
        CBaseServerVehicle *this,
        CBasePlayer *player,
        CUserCmd *ucmd,
        IMoveHelper *pHelper,
        CMoveData *move)
{
  this->m_pDrivableVehicle->SetupMove(this: this->m_pDrivableVehicle, a2: player, a3: ucmd, a4: pHelper, a5: move);
}

//------------------------------------------------------------------------------
// Address: 0x10256490
// Name: public: virtual void CBaseServerVehicle::FinishMove(class CBasePlayer __near *,class CUserCmd __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::FinishMove(
        CBaseServerVehicle *this,
        CBasePlayer *player,
        CUserCmd *ucmd,
        CMoveData *move)
{
  this->m_pDrivableVehicle->FinishMove(this: this->m_pDrivableVehicle, a2: player, a3: ucmd, a4: move);
}

//------------------------------------------------------------------------------
// Address: 0x102564A0
// Name: public: virtual void CBaseServerVehicle::ItemPostFrame(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::ItemPostFrame(CBaseServerVehicle *this, CBasePlayer *player)
{
  this->m_pDrivableVehicle->ItemPostFrame(this: this->m_pDrivableVehicle, a2: player);
  if ( (player->m_afButtonPressed & 0x20) != 0
    && this->m_pDrivableVehicle->CanExitVehicle(this: this->m_pDrivableVehicle, a2: player)
    && !this->HandlePassengerExit(this, a2: player) )
  {
    player->PlayUseDenySound(this: player);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102564F0
// Name: public: virtual void CBaseServerVehicle::NPC_ThrottleForward(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::NPC_ThrottleForward(CBaseServerVehicle *this)
{
  this->m_nNPCButtons = this->m_nNPCButtons & 0xFFFFFFE5 | 8;
}

//------------------------------------------------------------------------------
// Address: 0x10256500
// Name: public: virtual void CBaseServerVehicle::NPC_ThrottleReverse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::NPC_ThrottleReverse(CBaseServerVehicle *this)
{
  this->m_nNPCButtons = this->m_nNPCButtons & 0xFFFFFFE5 | 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x10256510
// Name: public: virtual void CBaseServerVehicle::NPC_ThrottleCenter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::NPC_ThrottleCenter(CBaseServerVehicle *this)
{
  this->m_nNPCButtons &= 0xFFFFFFE5;
}

//------------------------------------------------------------------------------
// Address: 0x10256520
// Name: public: virtual void CBaseServerVehicle::NPC_Brake(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::NPC_Brake(CBaseServerVehicle *this)
{
  this->m_nNPCButtons = this->m_nNPCButtons & 0xFFFFFFE5 | 2;
}

//------------------------------------------------------------------------------
// Address: 0x10256530
// Name: public: virtual void CBaseServerVehicle::NPC_TurnLeft(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::NPC_TurnLeft(CBaseServerVehicle *this, float flDegrees)
{
  this->m_nNPCButtons = this->m_nNPCButtons & 0xFFFFF9FF | 0x200;
  LODWORD(this->m_flTurnDegrees) = LODWORD(flDegrees) ^ _mask__NegFloat_;
}

//------------------------------------------------------------------------------
// Address: 0x10256560
// Name: public: virtual void CBaseServerVehicle::NPC_TurnRight(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::NPC_TurnRight(CBaseServerVehicle *this, float flDegrees)
{
  this->m_nNPCButtons = this->m_nNPCButtons & 0xFFFFF9FF | 0x400;
  this->m_flTurnDegrees = flDegrees;
}

//------------------------------------------------------------------------------
// Address: 0x10256590
// Name: public: virtual void CBaseServerVehicle::NPC_TurnCenter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::NPC_TurnCenter(CBaseServerVehicle *this)
{
  this->m_nNPCButtons &= 0xFFFFF9FF;
}

//------------------------------------------------------------------------------
// Address: 0x102565A0
// Name: public: virtual void CBaseServerVehicle::NPC_PrimaryFire(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::NPC_PrimaryFire(CBaseServerVehicle *this)
{
  this->m_nNPCButtons |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x102565B0
// Name: public: virtual void CBaseServerVehicle::NPC_SecondaryFire(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::NPC_SecondaryFire(CBaseServerVehicle *this)
{
  this->m_nNPCButtons |= 0x800u;
}

//------------------------------------------------------------------------------
// Address: 0x102565C0
// Name: public: virtual void CBaseServerVehicle::Weapon_SecondaryRanges(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::Weapon_SecondaryRanges(
        CBaseServerVehicle *this,
        float *flMinRange,
        float *flMaxRange)
{
  *flMinRange = 64.0;
  *flMaxRange = 1024.0;
}

//------------------------------------------------------------------------------
// Address: 0x102565F0
// Name: private: void CBaseServerVehicle::PlaySound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::PlaySound(CBaseServerVehicle *this, const char *pSound)
{
  if ( pSound != nullptr && *pSound != 0 )
  {
    if ( g_debug_vehiclesound.m_pParent != nullptr && g_debug_vehiclesound.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "Playing non-looping vehicle sound: %s\n", pSound);
    CBaseEntity::EmitSound(this: this->m_pVehicle, soundname: pSound, soundtime: 0.0, duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256640
// Name: private: void CBaseServerVehicle::StopLoopingSound(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::StopLoopingSound(CBaseServerVehicle *this, float fadeTime)
{
  CSoundEnvelopeController *Controller; // edi
  CSoundPatch *m_pStateSound; // eax

  Controller = CSoundEnvelopeController::GetController();
  if ( this->m_pStateSoundFade != nullptr )
  {
    Controller->SoundDestroy(this: Controller, a2: this->m_pStateSoundFade);
    this->m_pStateSoundFade = nullptr;
  }
  m_pStateSound = this->m_pStateSound;
  if ( m_pStateSound != nullptr )
  {
    this->m_pStateSoundFade = m_pStateSound;
    this->m_pStateSound = nullptr;
    ((void (__thiscall *)(CSoundEnvelopeController *, CSoundPatch *, _DWORD, _DWORD))Controller->SoundFadeOut)(
      a1: Controller,
      a2: m_pStateSound,
      a3: LODWORD(fadeTime),
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102566B0
// Name: MapGearToState
// Source: json
//------------------------------------------------------------------------------
sound_states __usercall MapGearToState@<eax>(int gear@<eax>, vbs_sound_update_t *params)
{
  sound_states result; // eax

  switch ( gear )
  {
    case 0:
      result = params->bReverse ? SS_REVERSE : SS_GEAR_0;
      break;
    case 1:
      result = SS_GEAR_1;
      break;
    case 2:
      result = SS_GEAR_2;
      break;
    case 3:
      result = SS_GEAR_3;
      break;
    default:
      result = SS_GEAR_4;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10256700
// Name: MapGearToMidState
// Source: json
//------------------------------------------------------------------------------
sound_states __usercall MapGearToMidState@<eax>(int gear@<eax>, vbs_sound_update_t *params)
{
  sound_states result; // eax

  switch ( gear )
  {
    case 0:
      result = params->bReverse ? SS_REVERSE : SS_GEAR_0_RESUME;
      break;
    case 1:
      result = SS_GEAR_1_RESUME;
      break;
    case 2:
      result = SS_GEAR_2_RESUME;
      break;
    case 3:
      result = SS_GEAR_3_RESUME;
      break;
    default:
      result = SS_GEAR_4_RESUME;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10256750
// Name: public: virtual void CBaseServerVehicle::SoundShutdown(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::SoundShutdown(CBaseServerVehicle *this, float flFadeTime)
{
  vehiclesound *v3; // edi
  CSoundEnvelopeController *Controller; // edi
  CSoundPatch *m_pStateSoundFade; // eax
  CSoundPatch *m_pStateSound; // eax

  this->StopEngineRumble(this);
  v3 = g_iSoundsToStopOnExit;
  do
    this->StopSound(this, a2: *v3++);
  while ( (int)v3 < (int)vehiclesound_parsenames );
  Controller = CSoundEnvelopeController::GetController();
  m_pStateSoundFade = this->m_pStateSoundFade;
  if ( m_pStateSoundFade != nullptr )
  {
    ((void (__thiscall *)(CSoundEnvelopeController *, CSoundPatch *, _DWORD, int))Controller->SoundFadeOut)(
      a1: Controller,
      a2: m_pStateSoundFade,
      a3: LODWORD(flFadeTime),
      a4: 1);
    this->m_pStateSoundFade = nullptr;
  }
  m_pStateSound = this->m_pStateSound;
  if ( m_pStateSound != nullptr )
  {
    ((void (__thiscall *)(CSoundEnvelopeController *, CSoundPatch *, _DWORD, int))Controller->SoundFadeOut)(
      a1: Controller,
      a2: m_pStateSound,
      a3: LODWORD(flFadeTime),
      a4: 1);
    this->m_pStateSound = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102567F0
// Name: public: virtual bool CBaseServerVehicle::NPC_HasAvailableSeat(struct string_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServerVehicle::NPC_HasAvailableSeat(CBaseServerVehicle *this, string_t strRoleName)
{
  return ((int (__thiscall *)(CBaseServerVehicle *, _DWORD, const char *, _DWORD))this->NPC_GetAvailableSeat)(
           a1: this,
           a2: 0,
           a3: strRoleName.pszValue,
           a4: 0) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10256810
// Name: protected: virtual void CBaseServerVehicle::ReloadScript(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::ReloadScript(CBaseServerVehicle *this)
{
  IPhysicsVehicleController *v2; // eax
  IPhysicsVehicleController *v3; // edi
  vehicleparams_t *v4; // eax
  const char *pszValue; // ecx
  string_t script; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_pDrivableVehicle != nullptr )
  {
    ((void (__thiscall *)(IDrivableVehicle *, string_t *))this->m_pDrivableVehicle->GetVehicleScriptName)(
      a1: this->m_pDrivableVehicle,
      a2: &script);
    v2 = this->GetVehicleController(this);
    v3 = v2;
    if ( v2 != nullptr )
      v4 = v2->GetVehicleParamsForChange(this: v2);
    else
      v4 = nullptr;
    pszValue = script.pszValue;
    if ( script.pszValue == nullptr )
      pszValue = locale;
    PhysFindOrAddVehicleScript(pScriptName: pszValue, pParams: v4, pSounds: &this->m_vehicleSounds);
    if ( v3 != nullptr )
      v3->VehicleDataReload(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256880
// Name: public: virtual bool CBaseServerVehicle::PassengerShouldReceiveDamage(class CTakeDamageInfo __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServerVehicle::PassengerShouldReceiveDamage(CBaseServerVehicle *this, CTakeDamageInfo *info)
{
  IDrivableVehicle *m_pDrivableVehicle; // ecx

  m_pDrivableVehicle = this->m_pDrivableVehicle;
  return m_pDrivableVehicle == nullptr
      || m_pDrivableVehicle->PassengerShouldReceiveDamage(this: m_pDrivableVehicle, a2: info);
}

//------------------------------------------------------------------------------
// Address: 0x102568A0
// Name: public: virtual void CBaseServerVehicle::GetVehicleViewPosition(int,class Vector __near *,class QAngle __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::GetVehicleViewPosition(
        CBaseServerVehicle *this,
        int nRole,
        Vector *pAbsOrigin,
        QAngle *pAbsAngles,
        float *pFOV)
{
  CBasePlayer *v5; // esi
  Vector v6; // [esp+4h] [ebp-Ch] BYREF

  v5 = (CBasePlayer *)this->GetPassenger(this, a2: 0);
  if ( v5 != nullptr && v5->IsPlayer(this: v5) )
  {
    if ( pAbsOrigin != nullptr )
      *pAbsOrigin = *v5->EyePosition(this: v5, result: &v6);
    if ( pAbsAngles != nullptr )
      *pAbsAngles = *v5->EyeAngles(this: v5);
    if ( pFOV != nullptr )
      *pFOV = (float)CBasePlayer::GetFOV(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256940
// Name: private: void CBaseServerVehicle::PlayLoopingSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::PlayLoopingSound(CBaseServerVehicle *this, const char *pSoundName)
{
  CSoundEnvelopeController *Controller; // eax
  CBaseEntity *m_pVehicle; // ebx
  CSoundEnvelopeController *v5; // esi
  const Vector *v6; // eax
  CSoundPatch *m_pStateSound; // ebx
  edict_t *m_pPev; // eax
  const char *v9; // eax
  const char *v10; // eax
  CSoundEnvelopeController *v11; // ecx
  CSoundPatch *m_pStateSoundFade; // eax
  CSoundPatch *v13; // eax
  CPASAttenuationFilter filter; // [esp+48h] [ebp-34h] BYREF
  float attenuation[3]; // [esp+68h] [ebp-14h] BYREF
  _BYTE v16[4]; // [esp+74h] [ebp-8h] BYREF
  const Vector *origin; // [esp+78h] [ebp-4h] BYREF
  int savedregs; // [esp+7Ch] [ebp+0h] BYREF
  const char *pStopSoundb; // [esp+84h] [ebp+8h]
  const char *pStopSound; // [esp+84h] [ebp+8h]
  const char *pStopSounda; // [esp+84h] [ebp+8h]

  Controller = CSoundEnvelopeController::GetController();
  m_pVehicle = this->m_pVehicle;
  v5 = Controller;
  origin = (const Vector *)((int (__thiscall *)(CBaseEntity *))m_pVehicle->GetSoundEmissionOrigin)(a1: m_pVehicle);
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin);
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  v6 = (const Vector *)((int (__thiscall *)(CBaseEntity *, float *, int))m_pVehicle->GetSoundEmissionOrigin)(
                         a1: m_pVehicle,
                         a2: attenuation,
                         a3: 1061997773);
  CPASAttenuationFilter::Filter(this: &filter, a2: (int)&savedregs, origin: v6, attenuation: COERCE_FLOAT(attenuation));
  m_pStateSound = nullptr;
  if ( pSoundName != nullptr && *pSoundName != 0 )
  {
    m_pPev = this->m_pVehicle->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    m_pStateSound = (CSoundPatch *)((int (__thiscall *)(CSoundEnvelopeController *, CPASAttenuationFilter *, edict_t *, int, const char *, int, int))v5->SoundCreate_4)(
                                     a1: v5,
                                     a2: &filter,
                                     a3: m_pPev,
                                     a4: 6,
                                     a5: pSoundName,
                                     a6: 1061997773,
                                     a7: 1065353216);
  }
  if ( this->m_pStateSound != nullptr
    && m_pStateSound != nullptr
    && (pStopSoundb = (const char *)((int (__thiscall *)(CSoundEnvelopeController *, const Vector **, CSoundPatch *))v5->SoundGetName)(
                                      a1: v5,
                                      a2: &origin,
                                      a3: this->m_pStateSound),
        *(_DWORD *)((int (__thiscall *)(CSoundEnvelopeController *, _BYTE *, CSoundPatch *))v5->SoundGetName)(
                     a1: v5,
                     a2: v16,
                     a3: m_pStateSound) == *(_DWORD *)pStopSoundb) )
  {
    v5->SoundDestroy(this: v5, a2: m_pStateSound);
    m_pStateSound = this->m_pStateSound;
    ((void (__thiscall *)(CSoundEnvelopeController *, CSoundPatch *, int, _DWORD))v5->SoundChangeVolume)(
      a1: v5,
      a2: m_pStateSound,
      a3: 1065353216,
      a4: 0);
    this->m_pStateSound = nullptr;
  }
  else if ( g_debug_vehiclesound.m_pParent != nullptr && g_debug_vehiclesound.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( this->m_pStateSound != nullptr )
    {
      v9 = *(const char **)((int (__thiscall *)(CSoundEnvelopeController *, _BYTE *, CSoundPatch *))v5->SoundGetName)(
                             a1: v5,
                             a2: v16,
                             a3: this->m_pStateSound);
      if ( v9 != nullptr )
        pStopSound = v9;
      else
        pStopSound = locale;
    }
    else
    {
      pStopSound = "NULL";
    }
    if ( m_pStateSound != nullptr )
    {
      v10 = *(const char **)((int (__thiscall *)(CSoundEnvelopeController *, const Vector **, CSoundPatch *))v5->SoundGetName)(
                              a1: v5,
                              a2: &origin,
                              a3: m_pStateSound);
      if ( v10 == nullptr )
        v10 = locale;
    }
    else
    {
      v10 = "NULL";
    }
    _Msg(a1: "Stop %s, start %s\n", pStopSound, v10);
  }
  v11 = CSoundEnvelopeController::GetController();
  m_pStateSoundFade = this->m_pStateSoundFade;
  pStopSounda = (const char *)v11;
  if ( m_pStateSoundFade != nullptr )
  {
    v11->SoundDestroy(this: v11, a2: m_pStateSoundFade);
    v11 = (CSoundEnvelopeController *)pStopSounda;
    this->m_pStateSoundFade = nullptr;
  }
  v13 = this->m_pStateSound;
  if ( v13 != nullptr )
  {
    this->m_pStateSoundFade = v13;
    this->m_pStateSound = nullptr;
    ((void (__thiscall *)(CSoundEnvelopeController *, CSoundPatch *, int, _DWORD))v11->SoundFadeOut)(
      a1: v11,
      a2: v13,
      a3: 1048576000,
      a4: 0);
  }
  this->m_pStateSound = m_pStateSound;
  if ( m_pStateSound != nullptr )
    ((void (__thiscall *)(CSoundEnvelopeController *, CSoundPatch *, int, int, _DWORD))v5->Play)(
      a1: v5,
      a2: m_pStateSound,
      a3: 1065353216,
      a4: 1120403456,
      a5: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10256BA0
// Name: private: void CBaseServerVehicle::SoundState_OnNewState(enum sound_states)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::SoundState_OnNewState(CBaseServerVehicle *this, sound_states lastState)
{
  sound_states m_soundState; // eax
  sound_states v4; // ecx
  sound_states v5; // eax
  const char *pszValue; // eax
  const char *v7; // eax

  if ( g_debug_vehiclesound.m_pParent != nullptr && g_debug_vehiclesound.m_pParent->m_Value.m_nValue != 0 )
  {
    m_soundState = this->m_soundState;
    if ( m_soundState >= SS_NONE )
    {
      v4 = SS_REVERSE;
      if ( m_soundState <= SS_REVERSE )
        v4 = this->m_soundState;
    }
    else
    {
      v4 = SS_NONE;
    }
    _Msg(a1: "Switched to state: %d (%s)\n", m_soundState, pSoundStateNames[v4]);
  }
  v5 = this->m_soundState;
  switch ( v5 )
  {
    case SS_SHUTDOWN:
    case SS_SHUTDOWN_WATER:
    case SS_START_WATER:
      CBaseServerVehicle::StopLoopingSound(this, fadeTime: 0.25);
      pszValue = this->m_vehicleSounds.iszStateSounds[this->m_soundState].pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      CBaseServerVehicle::PlaySound(this, pSound: pszValue);
      this->m_soundStateStartTime = gpGlobals->curtime;
      return;
    case SS_START_IDLE:
    case SS_GEAR_0:
    case SS_GEAR_1:
    case SS_GEAR_2:
    case SS_GEAR_3:
    case SS_GEAR_4:
    case SS_GEAR_0_RESUME:
    case SS_GEAR_1_RESUME:
    case SS_GEAR_2_RESUME:
    case SS_GEAR_3_RESUME:
    case SS_GEAR_4_RESUME:
    case SS_TURBO:
    case SS_REVERSE:
      goto $LN5_44;
    case SS_IDLE:
      this->m_lastSpeed = -1.0;
$LN5_44:
      v7 = this->m_vehicleSounds.iszStateSounds[v5].pszValue;
      goto LABEL_17;
    case SS_SLOWDOWN:
    case SS_SLOWDOWN_HIGHSPEED:
      if ( this->m_iSoundGear >= 2 )
        v7 = this->m_vehicleSounds.iszStateSounds[12].pszValue;
      else
        v7 = this->m_vehicleSounds.iszStateSounds[11].pszValue;
LABEL_17:
      if ( v7 == nullptr )
        v7 = locale;
      CBaseServerVehicle::PlayLoopingSound(this, pSoundName: v7);
      break;
    default:
      break;
  }
  this->m_soundStateStartTime = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10256CD0
// Name: public: virtual void CBaseServerVehicle::StopSound(enum vehiclesound)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::StopSound(CBaseServerVehicle *this, vehiclesound iSound)
{
  const char *pszValue; // edx
  edict_t *m_pPev; // eax

  pszValue = this->m_vehicleSounds.iszSound[iSound].pszValue;
  if ( pszValue != nullptr )
  {
    m_pPev = this->m_pVehicle->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEntity::StopSound(
        iEntIndex: m_pPev - gpGlobals->pEdicts,
        iChannel: 2,
        pSample: pszValue,
        bIsStoppingSpeakerSound: false);
    else
      CBaseEntity::StopSound(iEntIndex: 0, iChannel: 2, pSample: pszValue, bIsStoppingSpeakerSound: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256D20
// Name: public: CVehicleSoundsParser::CVehicleSoundsParser(void)
// Source: json
//------------------------------------------------------------------------------
CVehicleSoundsParser *__thiscall CVehicleSoundsParser::CVehicleSoundsParser(CVehicleSoundsParser *this)
{
  this->__vftable = (CVehicleSoundsParser_vtbl *)&CVehicleSoundsParser::`vftable';
  this->m_iCurrentGear = -1;
  this->m_iCurrentState = -1;
  this->m_iCurrentCrashSound = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10256D40
// Name: public: void CUtlMemory<struct CBaseServerVehicle::exitanim_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CBaseServerVehicle::exitanim_t,int>::Grow(
        CUtlMemory<CBaseServerVehicle::exitanim_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBaseServerVehicle::exitanim_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 156 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CBaseServerVehicle::exitanim_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CBaseServerVehicle::exitanim_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256DE0
// Name: public: virtual void CBaseServerVehicle::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::Precache(CBaseServerVehicle *this)
{
  string_t *iszSound; // esi
  int i; // ebx
  int v4; // esi
  vehicle_crashsound_t *m_pMemory; // eax
  bool v6; // zf
  const char **p_pszValue; // eax
  const char *v8; // eax
  string_t *iszStateSounds; // esi
  int j; // edi

  iszSound = this->m_vehicleSounds.iszSound;
  for ( i = 9; i != 0; --i )
  {
    if ( iszSound->pszValue != nullptr )
      CBaseEntity::PrecacheScriptSound(soundname: iszSound->pszValue);
    ++iszSound;
  }
  if ( this->m_vehicleSounds.crashSounds.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      m_pMemory = this->m_vehicleSounds.crashSounds.m_Memory.m_pMemory;
      v6 = m_pMemory[v4].iszCrashSound.pszValue == nullptr;
      p_pszValue = &m_pMemory[v4].iszCrashSound.pszValue;
      if ( !v6 )
      {
        v8 = *p_pszValue;
        if ( v8 == nullptr )
          v8 = locale;
        CBaseEntity::PrecacheScriptSound(soundname: v8);
      }
      ++i;
      ++v4;
    }
    while ( i < this->m_vehicleSounds.crashSounds.m_Size );
  }
  iszStateSounds = this->m_vehicleSounds.iszStateSounds;
  for ( j = 20; j != 0; --j )
  {
    if ( iszStateSounds->pszValue != nullptr )
      CBaseEntity::PrecacheScriptSound(soundname: iszStateSounds->pszValue);
    ++iszStateSounds;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256E70
// Name: public: virtual bool CBaseServerVehicle::NPC_RemovePassenger(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServerVehicle::NPC_RemovePassenger(CBaseServerVehicle *this, CBaseCombatCharacter *pPassenger)
{
  int m_Size; // ebx
  int v4; // edx
  CHandle<CBaseCombatCharacter> *i; // edi
  unsigned int m_Index; // eax
  CBaseCombatCharacter *m_pEntity; // ecx
  CPassengerInfo *m_pMemory; // [esp+4h] [ebp-4h]

  if ( pPassenger == nullptr || pPassenger->IsPlayer(this: pPassenger) )
    return 0;
  m_Size = this->m_PassengerInfo.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_PassengerInfo.m_Memory.m_pMemory;
  for ( i = &m_pMemory->m_hPassenger; ; i += 5 )
  {
    m_Index = i->m_Index;
    if ( i->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseCombatCharacter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == pPassenger )
      break;
    if ( ++v4 >= m_Size )
      return 0;
  }
  m_pMemory[v4].m_hPassenger.m_Index = -1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10256F10
// Name: public: virtual int CBaseServerVehicle::NPC_GetPassengerSeatAttachment(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServerVehicle::NPC_GetPassengerSeatAttachment(
        CBaseServerVehicle *this,
        CBaseCombatCharacter *pPassenger)
{
  int m_Size; // ebx
  int v3; // esi
  CHandle<CBaseCombatCharacter> *i; // edi
  unsigned int m_Index; // eax
  CBaseCombatCharacter *m_pEntity; // edx

  m_Size = this->m_PassengerInfo.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = &this->m_PassengerInfo.m_Memory.m_pMemory->m_hPassenger; ; i += 5 )
  {
    m_Index = i->m_Index;
    if ( i->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseCombatCharacter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == pPassenger )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return this->m_PassengerRoles.m_Memory.m_pMemory[this->m_PassengerInfo.m_Memory.m_pMemory[v3].m_nRole].m_PassengerSeats.m_Memory.m_pMemory[this->m_PassengerInfo.m_Memory.m_pMemory[v3].m_nSeat].m_nAttachmentID;
}

//------------------------------------------------------------------------------
// Address: 0x10257050
// Name: public: virtual void CBaseServerVehicle::SetPassenger(int,class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseServerVehicle::SetPassenger(
        CBaseServerVehicle *this@<ecx>,
        int a2@<ebx>,
        int nRole,
        CBasePlayer *pPassenger)
{
  const Vector *v5; // eax
  void (__thiscall *SetViewOffset)(CBaseEntity *, const Vector *); // edx
  int v7; // eax
  CBasePlayer *v8; // edi
  unsigned int m_Index; // esi

  if ( pPassenger != nullptr )
  {
    if ( pPassenger->IsPlayer(this: pPassenger) && pPassenger->IsPlayer(this: pPassenger) )
    {
      v5 = pPassenger->GetViewOffset(this: pPassenger);
      this->m_savedViewOffset.x = v5->x;
      this->m_savedViewOffset.y = v5->y;
      SetViewOffset = pPassenger->SetViewOffset;
      this->m_savedViewOffset.z = v5->z;
      SetViewOffset(this: pPassenger, a2: &vec3_origin);
      if ( !this->IsPassengerUsingStandardWeapons(this, a2: nRole) )
        CBasePlayer::ShowCrosshair(this: pPassenger, bShow: false);
      this->m_pDrivableVehicle->EnterVehicle(this: this->m_pDrivableVehicle, a2: pPassenger);
    }
  }
  else
  {
    v7 = ((int (__thiscall *)(CBaseServerVehicle *, int))this->GetDriver)(a1: this, a2);
    v8 = (CBasePlayer *)v7;
    if ( v7 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 336))(a1: v7) != 0 )
    {
      v8->SetViewOffset(this: v8, a2: &this->m_savedViewOffset);
      if ( !this->IsPassengerUsingStandardWeapons(this, a2: nRole) )
        CBasePlayer::ShowCrosshair(this: v8, bShow: true);
    }
    ((void (__thiscall *)(IDrivableVehicle *))this->m_pDrivableVehicle->ExitVehicle)(a1: this->m_pDrivableVehicle);
    this->m_pDrivableVehicle->SetVehicleEntryAnim(this: this->m_pDrivableVehicle, a2: false);
    m_Index = this->m_hExitBlocker.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      UTIL_Remove(oldObj: nullptr);
    else
      UTIL_Remove(oldObj: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102571A0
// Name: public: virtual bool CBaseServerVehicle::CheckExitPoint(float,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServerVehicle::CheckExitPoint(
        CBaseServerVehicle *this,
        float yaw,
        int distance,
        Vector *pEndPoint)
{
  CBaseEntity *m_pVehicle; // esi
  float z; // edx
  CBaseEntity *v7; // eax
  float v8; // xmm2_4
  float v9; // xmm0_4
  const CViewVectors *v10; // eax
  Vector *p_m_vHullMax; // [esp-14h] [ebp-94h]
  const IHandleEntity *v13; // [esp-Ch] [ebp-8Ch]
  CGameTrace tr; // [esp+8h] [ebp-78h] BYREF
  QAngle vehicleAngles; // [esp+5Ch] [ebp-24h] BYREF
  Vector vecDir; // [esp+68h] [ebp-18h] BYREF
  Vector vecStart; // [esp+74h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+80h] [ebp+0h] BYREF

  m_pVehicle = this->m_pVehicle;
  vehicleAngles = (QAngle)m_pVehicle->m_angRotation;
  if ( (m_pVehicle->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pVehicle);
  z = m_pVehicle->m_vecAbsOrigin.z;
  *(_QWORD *)&vecStart.x = *(_QWORD *)&m_pVehicle->m_vecAbsOrigin.x;
  vecStart.z = z + 12.0;
  vehicleAngles.y = vehicleAngles.y + yaw;
  AngleVectors(angles: &vehicleAngles, forward: nullptr, right: &vecDir, up: nullptr);
  v7 = this->m_pVehicle;
  vecDir.x = vecDir.x * -1.0;
  vecDir.z = vecDir.z * -1.0;
  vecDir.y = vecDir.y * -1.0;
  v8 = (float)(vecDir.z * (float)distance) + vecStart.z;
  v9 = vecStart.y + (float)(vecDir.y * (float)distance);
  pEndPoint->x = vecStart.x + (float)(vecDir.x * (float)distance);
  pEndPoint->y = v9;
  pEndPoint->z = v8;
  v13 = v7;
  p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
  v10 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)pEndPoint,
    vecAbsStart: &vecStart,
    vecAbsEnd: pEndPoint,
    hullMin: &v10->m_vHullMin,
    hullMax: p_m_vHullMax,
    mask: 0x201400Bu,
    ignore: v13,
    collisionGroup: 0,
    ptr: &tr);
  return tr.fraction >= 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102572F0
// Name: public: virtual int CBaseServerVehicle::GetEntryAnimForPoint(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServerVehicle::GetEntryAnimForPoint(CBaseServerVehicle *this, const Vector *vecEyePoint)
{
  CBaseAnimating *v4; // eax
  CBaseAnimating *v5; // esi
  CStudioHdr *m_pStudioHdr; // esi
  int v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // edx
  int v11; // esi
  int m_Size; // edx
  int v13; // eax
  int v14; // esi
  CBaseServerVehicle::entryanim_t *m_pMemory; // ecx
  matrix3x4_t fRotateMatrix; // [esp+4h] [ebp-60h] BYREF
  Vector localEyePoint; // [esp+34h] [ebp-30h] BYREF
  QAngle vecAngles; // [esp+40h] [ebp-24h] BYREF
  Vector vecPosition; // [esp+4Ch] [ebp-18h] BYREF
  CBaseAnimating *pAnimating; // [esp+58h] [ebp-Ch]
  int i; // [esp+5Ch] [ebp-8h]
  int v22; // [esp+60h] [ebp-4h]

  if ( !this->m_bParsedAnimations )
  {
    this->ParseEntryExitAnims(this);
    this->m_bParsedAnimations = true;
  }
  if ( this->m_EntryAnimations.m_Size == 0 )
    return 0;
  v4 = (CBaseAnimating *)__RTDynamicCast(
                           inptr: this->m_pVehicle,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CBaseAnimating `RTTI Type Descriptor',
                           isReference: 0);
  v5 = v4;
  pAnimating = v4;
  if ( v4 == nullptr )
    return 0;
  if ( v4->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: v4) != nullptr )
    CBaseAnimating::LockStudioHdr(this: v5);
  m_pStudioHdr = v5->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0;
  v7 = (int)m_pStudioHdr->m_pStudioHdr
     + 12 * FindHitboxSetByName(pstudiohdr: m_pStudioHdr, name: "entryboxes")
     + m_pStudioHdr->m_pStudioHdr->hitboxsetindex;
  if ( v7 == 0 )
    return 0;
  v8 = *(_DWORD *)(v7 + 4);
  if ( v8 == 0 )
    return 0;
  i = 0;
  if ( v8 <= 0 )
    return -1;
  v22 = 0;
  while ( 1 )
  {
    v9 = v22 + *(_DWORD *)(v7 + 8);
    v10 = *(_DWORD *)(v9 + v7);
    v11 = v7 + v9;
    CBaseAnimating::GetBonePosition(this: pAnimating, iBone: v10, origin: &vecPosition, angles: &vecAngles);
    AngleMatrix(angles: &vecAngles, position: &vecPosition, matrix: &fRotateMatrix);
    VectorITransform(in1: &vecEyePoint->x, in2: &fRotateMatrix, out: &localEyePoint.x);
    if ( IsPointInBox(pt: &localEyePoint, boxMin: (const Vector *)(v11 + 8), boxMax: (const Vector *)(v11 + 20)) )
    {
      m_Size = this->m_EntryAnimations.m_Size;
      v13 = 0;
      if ( m_Size > 0 )
        break;
    }
LABEL_21:
    v22 += 68;
    if ( ++i >= *(_DWORD *)(v7 + 4) )
      return -1;
  }
  v14 = *(_DWORD *)(v11 + 4);
  m_pMemory = this->m_EntryAnimations.m_Memory.m_pMemory;
  while ( m_pMemory->iHitboxGroup != v14 )
  {
    ++v13;
    ++m_pMemory;
    if ( v13 >= m_Size )
      goto LABEL_21;
  }
  return CBaseAnimating::LookupSequence(
           this: pAnimating,
           label: this->m_EntryAnimations.m_Memory.m_pMemory[v13].szAnimName);
}

//------------------------------------------------------------------------------
// Address: 0x10257470
// Name: public: virtual int CBaseServerVehicle::GetExitAnimToUse(class Vector __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServerVehicle::GetExitAnimToUse(
        CBaseServerVehicle *this,
        Vector *vecEyeExitEndpoint,
        bool *bAllPointsBlocked)
{
  CBaseAnimating *v5; // eax
  CBaseAnimating *v6; // esi
  CStudioHdr *m_pStudioHdr; // eax
  bool v8; // al
  CBaseServerVehicle_vtbl *v9; // edx
  int v10; // eax
  CBasePlayer *v11; // esi
  int v12; // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  int v14; // ebx
  int m_Size; // eax
  int v16; // eax
  bool *v17; // eax
  const CViewVectors *v18; // eax
  float x; // xmm0_4
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // eax
  float y; // xmm0_4
  const CViewVectors *(__thiscall *v22)(CGameRules *); // eax
  int v23; // eax
  const CViewVectors *(__thiscall *v24)(CGameRules *); // edx
  const Vector *v25; // eax
  ConVar *m_pParent; // eax
  float v27; // xmm0_4
  const CViewVectors *(__thiscall *v28)(CGameRules *); // eax
  float v29; // xmm0_4
  const CViewVectors *(__thiscall *v30)(CGameRules *); // eax
  const CViewVectors *v31; // eax
  const CViewVectors *v32; // eax
  const CViewVectors *v33; // eax
  bool bEscapeExit; // al
  const CViewVectors *v35; // eax
  const CViewVectors *v36; // eax
  float v37; // xmm1_4
  float v38; // xmm2_4
  CBaseAnimating *v39; // ecx
  Vector *p_m_vHullMin; // [esp+Ch] [ebp-128h]
  Vector *v41; // [esp+Ch] [ebp-128h]
  Vector *size; // [esp+10h] [ebp-124h]
  Vector *sizea; // [esp+10h] [ebp-124h]
  Vector *sizeb; // [esp+10h] [ebp-124h]
  Vector *sizec; // [esp+10h] [ebp-124h]
  Vector *p_m_vHullMax; // [esp+14h] [ebp-120h]
  CGameTrace tr; // [esp+34h] [ebp-100h] BYREF
  Vector hullMax; // [esp+88h] [ebp-ACh] BYREF
  Vector vecEnd; // [esp+94h] [ebp-A0h] BYREF
  Vector maxs; // [esp+A0h] [ebp-94h] BYREF
  Vector vecStart; // [esp+ACh] [ebp-88h] BYREF
  QAngle vehicleExitAngles; // [esp+B8h] [ebp-7Ch] BYREF
  int iCount; // [esp+C4h] [ebp-70h]
  int nRole; // [esp+C8h] [ebp-6Ch]
  float flCosAngleDelta; // [esp+CCh] [ebp-68h]
  float v56; // [esp+D0h] [ebp-64h]
  float v57; // [esp+D4h] [ebp-60h]
  Vector vecViewDirection; // [esp+D8h] [ebp-5Ch] BYREF
  Vector vecViewOrigin; // [esp+E4h] [ebp-50h] BYREF
  Vector vecExitEndPoint; // [esp+F0h] [ebp-44h] BYREF
  Vector vecDelta; // [esp+FCh] [ebp-38h] BYREF
  float flMaxCosAngleDelta; // [esp+108h] [ebp-2Ch]
  Vector vecBestExitPoint; // [esp+10Ch] [ebp-28h] BYREF
  int i; // [esp+118h] [ebp-1Ch]
  Vector vehicleExitOrigin; // [esp+11Ch] [ebp-18h] BYREF
  CBaseAnimating *pAnimating; // [esp+128h] [ebp-Ch]
  unsigned int v67; // [esp+12Ch] [ebp-8h]
  bool bUpright; // [esp+132h] [ebp-2h]
  bool bBestExitIsEscapePoint; // [esp+133h] [ebp-1h]
  IHandleEntity savedregs; // [esp+134h] [ebp+0h] BYREF

  *bAllPointsBlocked = false;
  if ( !this->m_bParsedAnimations )
  {
    this->ParseEntryExitAnims(this);
    this->m_bParsedAnimations = true;
  }
  if ( this->m_ExitAnimations.m_Size == 0 )
    return -1;
  v5 = (CBaseAnimating *)__RTDynamicCast(
                           inptr: this->m_pVehicle,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CBaseAnimating `RTTI Type Descriptor',
                           isReference: 0);
  v6 = v5;
  pAnimating = v5;
  if ( v5 != nullptr )
  {
    if ( v5->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: v5) != nullptr )
      CBaseAnimating::LockStudioHdr(this: v6);
    m_pStudioHdr = v6->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      v8 = this->IsVehicleUpright(this);
      v9 = this->__vftable;
      bUpright = v8;
      v10 = (int)v9->GetDriver(this);
      v11 = (CBasePlayer *)v10;
      if ( v10 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 336))(a1: v10) != 0 )
      {
        v12 = this->GetPassengerRole(this, a2: v11);
        EyePosition = v11->EyePosition;
        nRole = v12;
        v14 = -1;
        bBestExitIsEscapePoint = true;
        memset((void *)&vecBestExitPoint, 0, sizeof(vecBestExitPoint));
        vecViewOrigin = *EyePosition(this: v11, result: &maxs);
        CBasePlayer::EyeVectors(this: v11, pForward: &vecViewDirection, pRight: nullptr, pUp: nullptr);
        vecViewDirection.z = 0.0;
        VectorNormalize(vec: &vecViewDirection);
        m_Size = this->m_ExitAnimations.m_Size;
        flMaxCosAngleDelta = -2.0;
        iCount = m_Size;
        i = 0;
        if ( m_Size <= 0 )
          goto LABEL_54;
        v16 = 0;
        v67 = 0;
        do
        {
          v17 = &this->m_ExitAnimations.m_Memory.m_pMemory->bUpright + v16;
          if ( *v17 != bUpright || !bBestExitIsEscapePoint && v17[1] )
            goto LABEL_48;
          if ( this->m_bUseLegacyExitChecks )
          {
            CBaseAnimating::GetAttachment(
              this: pAnimating,
              szName: (const char *)v17 + 2,
              absOrigin: &vehicleExitOrigin,
              absAngles: &vehicleExitAngles);
          }
          else
          {
            vehicleExitOrigin = *(Vector *)(v17 + 11);
            vehicleExitAngles = *(QAngle *)(v17 + 12);
            UTIL_ParentToWorldSpace(pEntity: pAnimating, vecPosition: &vehicleExitOrigin, vecAngles: &vehicleExitAngles);
          }
          vecDelta.x = vehicleExitOrigin.x - vecViewOrigin.x;
          vecDelta.y = vehicleExitOrigin.y - vecViewOrigin.y;
          vecDelta.z = 0.0;
          VectorNormalize(vec: &vecDelta);
          flCosAngleDelta = (float)((float)(vecDelta.x * vecViewDirection.x) + (float)(vecViewDirection.y * vecDelta.y))
                          + (float)(vecDelta.z * vecViewDirection.z);
          if ( (!bBestExitIsEscapePoint || this->m_ExitAnimations.m_Memory.m_pMemory[v67 / 0x9C].bEscapeExit)
            && flMaxCosAngleDelta > (float)((float)((float)(vecDelta.x * vecViewDirection.x)
                                                  + (float)(vecViewDirection.y * vecDelta.y))
                                          + (float)(vecDelta.z * vecViewDirection.z)) )
          {
            goto LABEL_48;
          }
          v18 = g_pGameRules->GetViewVectors(this: g_pGameRules);
          vehicleExitOrigin.x = vehicleExitOrigin.x - v18->m_vView.x;
          vehicleExitOrigin.y = vehicleExitOrigin.y - v18->m_vView.y;
          vehicleExitOrigin.z = vehicleExitOrigin.z - v18->m_vView.z;
          vecStart.x = vehicleExitOrigin.x;
          vecStart.y = vehicleExitOrigin.y;
          vecStart.z = vehicleExitOrigin.z + 64.0;
          vecEnd.x = vehicleExitOrigin.x;
          vecEnd.y = vehicleExitOrigin.y;
          vecEnd.z = vehicleExitOrigin.z - 64.0;
          x = g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax.x;
          GetViewVectors = g_pGameRules->GetViewVectors;
          hullMax.x = x;
          y = GetViewVectors(this: g_pGameRules)->m_vHullMax.y;
          v22 = g_pGameRules->GetViewVectors;
          hullMax.y = y;
          v23 = (int)v22(this: g_pGameRules);
          v24 = g_pGameRules->GetViewVectors;
          hullMax.z = *(float *)(v23 + 20);
          v25 = (const Vector *)v24(this: g_pGameRules);
          UTIL_TraceHull(
            a1: &savedregs,
            a2: (int)v11,
            vecAbsStart: &vecStart,
            vecAbsEnd: &vecEnd,
            hullMin: v25 + 1,
            &hullMax,
            mask: 0x201400Bu,
            ignore: nullptr,
            collisionGroup: 0,
            ptr: &tr);
          m_pParent = g_debug_vehicleexit.m_pParent;
          if ( g_debug_vehicleexit.m_pParent != nullptr && g_debug_vehicleexit.m_pParent->m_Value.m_nValue != 0 )
          {
            v27 = g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax.x;
            v28 = g_pGameRules->GetViewVectors;
            v57 = v27;
            v29 = v28(this: g_pGameRules)->m_vHullMax.y;
            v30 = g_pGameRules->GetViewVectors;
            v56 = v29;
            maxs.z = v30(this: g_pGameRules)->m_vHullMin.y;
            maxs.x = v57;
            maxs.y = v56;
            v31 = g_pGameRules->GetViewVectors(this: g_pGameRules);
            NDebugOverlay::SweptBox(
              start: &vecStart,
              end: &vecEnd,
              mins: &v31->m_vHullMin,
              &maxs,
              angles: &vec3_angle,
              r: 255,
              g: 255,
              b: 255,
              a: 8,
              flDuration: 20.0);
            m_pParent = g_debug_vehicleexit.m_pParent;
          }
          if ( tr.fraction < 1.0 )
          {
            p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
            v32 = g_pGameRules->GetViewVectors(this: g_pGameRules);
            UTIL_TraceHull(
              a1: &savedregs,
              a2: (int)v11,
              vecAbsStart: &tr.endpos,
              vecAbsEnd: &tr.endpos,
              hullMin: &v32->m_vHullMin,
              hullMax: p_m_vHullMax,
              mask: 0x201400Bu,
              ignore: nullptr,
              collisionGroup: 0,
              ptr: &tr);
            if ( tr.startsolid )
            {
              if ( g_debug_vehicleexit.m_pParent != nullptr && g_debug_vehicleexit.m_pParent->m_Value.m_nValue != 0 )
              {
                size = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
                p_m_vHullMin = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
                NDebugOverlay::Box(
                  origin: &tr.endpos,
                  mins: p_m_vHullMin,
                  maxs: size,
                  r: 255,
                  g: 0,
                  b: 0,
                  a: 8,
                  flDuration: 20.0);
              }
              goto LABEL_48;
            }
            if ( g_debug_vehicleexit.m_pParent != nullptr && g_debug_vehicleexit.m_pParent->m_Value.m_nValue != 0 )
            {
              sizea = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
              v33 = g_pGameRules->GetViewVectors(this: g_pGameRules);
              NDebugOverlay::Box(
                origin: &tr.endpos,
                mins: &v33->m_vHullMin,
                maxs: sizea,
                r: 0,
                g: 255,
                b: 0,
                a: 8,
                flDuration: 20.0);
            }
LABEL_39:
            vecExitEndPoint = tr.endpos;
            UTIL_TraceLine(
              a1: &savedregs,
              a2: (int)v11,
              vecAbsStart: &vecViewOrigin,
              vecAbsEnd: &vecExitEndPoint,
              mask: 0x201400Bu,
              ignore: pAnimating,
              collisionGroup: 0,
              ptr: &tr);
            if ( tr.fraction == 1.0 )
            {
              bEscapeExit = this->m_ExitAnimations.m_Memory.m_pMemory[v67 / 0x9C].bEscapeExit;
              v14 = i;
              vecBestExitPoint = vecExitEndPoint;
              bBestExitIsEscapePoint = bEscapeExit;
              flMaxCosAngleDelta = flCosAngleDelta;
            }
            else if ( g_debug_vehicleexit.m_pParent != nullptr && g_debug_vehicleexit.m_pParent->m_Value.m_nValue != 0 )
            {
              NDebugOverlay::Line(
                origin: &vecViewOrigin,
                target: &vecExitEndPoint,
                r: 255,
                g: 0,
                b: 0,
                noDepthTest: true,
                duration: 10.0);
            }
            goto LABEL_48;
          }
          if ( !tr.allsolid )
          {
            if ( tr.fraction != 1.0
              || this->m_pDrivableVehicle->AllowMidairExit(this: this->m_pDrivableVehicle, a2: v11, a3: nRole) )
            {
              goto LABEL_39;
            }
            m_pParent = g_debug_vehicleexit.m_pParent;
          }
          if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
          {
            sizeb = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
            v41 = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
            NDebugOverlay::Box(origin: &tr.endpos, mins: v41, maxs: sizeb, r: 255, g: 0, b: 0, a: 64, flDuration: 10.0);
          }
LABEL_48:
          v16 = v67 + 156;
          ++i;
          v67 += 156;
        }
        while ( i < iCount );
        if ( v14 < 0 )
        {
LABEL_54:
          *bAllPointsBlocked = true;
          return -1;
        }
        this->m_vecCurrentExitEndPoint = vecBestExitPoint;
        if ( g_debug_vehicleexit.m_pParent != nullptr && g_debug_vehicleexit.m_pParent->m_Value.m_nValue != 0 )
        {
          NDebugOverlay::Cross3D(
            position: &this->m_vecCurrentExitEndPoint,
            size: 16.0,
            r: 0,
            g: 255,
            b: 0,
            noDepthTest: true,
            flDuration: 10.0);
          sizec = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
          v35 = g_pGameRules->GetViewVectors(this: g_pGameRules);
          NDebugOverlay::Box(
            origin: &this->m_vecCurrentExitEndPoint,
            mins: &v35->m_vHullMin,
            maxs: sizec,
            r: 255,
            g: 255,
            b: 255,
            a: 8,
            flDuration: 10.0);
        }
        v36 = g_pGameRules->GetViewVectors(this: g_pGameRules);
        v37 = v36->m_vView.y + vecBestExitPoint.y;
        v38 = v36->m_vView.z + vecBestExitPoint.z;
        v39 = pAnimating;
        vecEyeExitEndpoint->x = v36->m_vView.x + vecBestExitPoint.x;
        vecEyeExitEndpoint->y = v37;
        vecEyeExitEndpoint->z = v38;
        this->m_iCurrentExitAnim = v14;
        return CBaseAnimating::LookupSequence(
                 this: v39,
                 label: this->m_ExitAnimations.m_Memory.m_pMemory[v14].szAnimName);
      }
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10257C70
// Name: public: virtual void CBaseServerVehicle::ProcessMovement(class CBasePlayer __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::ProcessMovement(
        CBaseServerVehicle *this,
        CBasePlayer *pPlayer,
        CMoveData *pMoveData)
{
  int m_iEFlags; // edx
  CBaseEntity *v5; // eax
  IPhysicsSurfaceProps *v6; // eax
  char material; // bl
  CGameTrace tr; // [esp+8h] [ebp-60h] BYREF
  Vector vecAbsEnd; // [esp+5Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+68h] [ebp+0h] BYREF

  this->m_pDrivableVehicle->ProcessMovement(this: this->m_pDrivableVehicle, a2: pPlayer, a3: pMoveData);
  if ( (pPlayer->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pPlayer);
  m_iEFlags = pPlayer->m_iEFlags;
  vecAbsEnd.x = pPlayer->m_vecAbsOrigin.x;
  vecAbsEnd.y = pPlayer->m_vecAbsOrigin.y;
  vecAbsEnd.z = pPlayer->m_vecAbsOrigin.z - 256.0;
  if ( (m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pPlayer);
  v5 = this->GetVehicleEnt(this);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &pPlayer->m_vecAbsOrigin,
    &vecAbsEnd,
    mask: 0x201400Bu,
    ignore: v5,
    collisionGroup: 0,
    ptr: &tr);
  v6 = IMoveHelper::sm_pSingleton->GetSurfaceProps(this: IMoveHelper::sm_pSingleton);
  material = v6->GetSurfaceData(this: v6, a2: tr.surface.surfaceProps)->game.material;
  if ( this->m_chPreviousTextureType != material )
    CEnvPlayerSurfaceTrigger::SetPlayerSurface(pPlayer, gameMaterial: material);
  this->m_chPreviousTextureType = material;
}

//------------------------------------------------------------------------------
// Address: 0x10257D50
// Name: private: bool CBaseServerVehicle::PlayCrashSound(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServerVehicle::PlayCrashSound(CBaseServerVehicle *this, float speed)
{
  float v2; // xmm3_4
  float v4; // xmm1_4
  CBaseEntity *v5; // esi
  int m_Size; // esi
  int v7; // ecx
  vehicle_crashsound_t *m_pMemory; // eax
  int gearLimit; // edx
  int v10; // eax
  vehicle_crashsound_t *i; // ecx
  const char *pszValue; // esi
  float delta; // [esp+28h] [ebp-4h]
  float rumble; // [esp+34h] [ebp+8h]

  v2 = 0.0;
  v4 = fabs(this->m_lastSpeed);
  delta = 0.0;
  if ( v4 > fabs(speed) )
  {
    v2 = fabs(this->m_lastSpeed - speed);
    delta = v2;
  }
  rumble = v2 * 0.125;
  if ( (float)(v2 * 0.125) <= 60.0 )
  {
    if ( (float)(v2 * 0.125) <= 5.0 )
      goto LABEL_11;
  }
  else
  {
    rumble = 60.0;
  }
  if ( this->GetDriver(this) != nullptr )
  {
    v5 = this->GetDriver(this);
    if ( (v5->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v5);
    UTIL_ScreenShake(
      center: &v5->m_vecAbsOrigin,
      amplitude: rumble,
      frequency: 150.0,
      duration: 1.0,
      radius: 240.0,
      eCommand: SHAKE_START_RUMBLEONLY,
      bAirShake: true,
      ignore: nullptr);
  }
  v2 = delta;
LABEL_11:
  m_Size = this->m_vehicleSounds.crashSounds.m_Size;
  v7 = 0;
  if ( m_Size <= 0 )
  {
LABEL_18:
    v10 = m_Size - 1;
    if ( m_Size - 1 < 0 )
      return 0;
    for ( i = &this->m_vehicleSounds.crashSounds.m_Memory.m_pMemory[v10];
          v2 <= i->flMinDeltaSpeed || v4 <= i->flMinSpeed;
          --i )
    {
      if ( --v10 < 0 )
        return 0;
    }
    pszValue = i->iszCrashSound.pszValue;
  }
  else
  {
    m_pMemory = this->m_vehicleSounds.crashSounds.m_Memory.m_pMemory;
    while ( 1 )
    {
      gearLimit = m_pMemory->gearLimit;
      if ( gearLimit != 0
        && this->m_iSoundGear <= gearLimit
        && v2 > m_pMemory->flMinDeltaSpeed
        && v4 > m_pMemory->flMinSpeed )
      {
        break;
      }
      ++v7;
      ++m_pMemory;
      if ( v7 >= m_Size )
        goto LABEL_18;
    }
    pszValue = m_pMemory->iszCrashSound.pszValue;
  }
  if ( pszValue != nullptr && *pszValue != 0 )
  {
    if ( g_debug_vehiclesound.m_pParent != nullptr && g_debug_vehiclesound.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "Playing non-looping vehicle sound: %s\n", pszValue);
    CBaseEntity::EmitSound(this: this->m_pVehicle, soundname: pszValue, soundtime: 0.0, duration: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10257F10
// Name: private: bool CBaseServerVehicle::CheckCrash(struct vbs_sound_update_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServerVehicle::CheckCrash(CBaseServerVehicle *this, vbs_sound_update_t *params)
{
  char v4; // bl

  if ( params->bVehicleInWater )
    return 0;
  v4 = CBaseServerVehicle::PlayCrashSound(this, speed: params->flWorldSpaceSpeed);
  if ( v4 != 0 && g_debug_vehiclesound.m_pParent != nullptr && g_debug_vehiclesound.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Crashed!: speed %.2f, lastSpeed %.2f\n", params->flWorldSpaceSpeed, this->m_lastSpeed);
  this->m_lastSpeed = params->flWorldSpaceSpeed;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10257F90
// Name: private: enum sound_states CBaseServerVehicle::SoundState_ChooseState(struct vbs_sound_update_t __near &)
// Source: json
//------------------------------------------------------------------------------
sound_states __thiscall CBaseServerVehicle::SoundState_ChooseState(
        CBaseServerVehicle *this,
        vbs_sound_update_t *params)
{
  sound_states result; // eax
  bool v4; // bl
  int m_iSoundGear; // edi
  bool v6; // zf
  int v7; // edi
  sound_states stateOut; // [esp+Ch] [ebp-4h]

  result = this->m_soundState;
  v4 = (float)(gpGlobals->curtime - this->m_soundStateStartTime) > this->m_vehicleSounds.minStateTime[result];
  stateOut = result;
  if ( params->bExitVehicle )
  {
    if ( (unsigned int)result > SS_SHUTDOWN_WATER )
      return SS_SHUTDOWN;
  }
  else
  {
    switch ( result )
    {
      case SS_SHUTDOWN_WATER:
      case SS_START_WATER:
        if ( params->bVehicleInWater )
          goto LABEL_15;
        return SS_START_IDLE;
      case SS_IDLE:
        if ( !params->bVehicleInWater )
          goto LABEL_15;
        return SS_SHUTDOWN_WATER;
      case SS_GEAR_0:
      case SS_GEAR_1:
      case SS_GEAR_2:
      case SS_GEAR_3:
      case SS_GEAR_4:
      case SS_SLOWDOWN:
      case SS_SLOWDOWN_HIGHSPEED:
      case SS_GEAR_0_RESUME:
      case SS_GEAR_1_RESUME:
      case SS_GEAR_2_RESUME:
      case SS_GEAR_3_RESUME:
      case SS_GEAR_4_RESUME:
      case SS_REVERSE:
        if ( params->bVehicleInWater )
          return SS_SHUTDOWN_WATER;
        if ( params->bTurbo )
        {
LABEL_14:
          result = SS_TURBO;
        }
        else
        {
LABEL_8:
          if ( CBaseServerVehicle::CheckCrash(this, params) != 0 )
          {
LABEL_9:
            result = SS_IDLE;
          }
          else
          {
LABEL_15:
            switch ( this->m_soundState )
            {
              case SS_NONE:
                return !params->bVehicleInWater + 3;
              case SS_START_IDLE:
                if ( !v4 && !params->bThrottleDown )
                  goto LABEL_53;
                return SS_IDLE;
              case SS_IDLE:
                if ( !v4 || !params->bThrottleDown )
                  goto LABEL_53;
                if ( params->bTurbo )
                  goto LABEL_14;
                return params->bReverse ? 19 : 6;
              case SS_GEAR_0:
              case SS_GEAR_0_RESUME:
                if ( v4 && !params->bThrottleDown || params->bReverse )
                  goto LABEL_9;
                if ( this->m_iSoundGear <= 0 )
                  goto LABEL_53;
                return SS_GEAR_1;
              case SS_GEAR_1:
              case SS_GEAR_1_RESUME:
                if ( v4 && !params->bThrottleDown )
                  goto LABEL_45;
                m_iSoundGear = this->m_iSoundGear;
                v6 = m_iSoundGear == 1;
                goto LABEL_31;
              case SS_GEAR_2:
              case SS_GEAR_2_RESUME:
                if ( !v4 )
                  goto LABEL_53;
                if ( !params->bThrottleDown )
                  goto LABEL_45;
                m_iSoundGear = this->m_iSoundGear;
                v6 = m_iSoundGear == 2;
                goto LABEL_31;
              case SS_GEAR_3:
              case SS_GEAR_3_RESUME:
                if ( !v4 )
                  goto LABEL_53;
                if ( !params->bThrottleDown )
                  goto LABEL_45;
                m_iSoundGear = this->m_iSoundGear;
                v6 = m_iSoundGear == 3;
LABEL_31:
                if ( v6 )
                  goto LABEL_53;
                result = MapGearToState(gear: m_iSoundGear, params);
                break;
              case SS_GEAR_4:
              case SS_GEAR_4_RESUME:
                if ( v4 && !params->bThrottleDown )
                  goto LABEL_45;
                v7 = this->m_iSoundGear;
                if ( v7 == 4 )
                  goto LABEL_53;
                return MapGearToMidState(gear: v7, params);
              case SS_SLOWDOWN:
              case SS_SLOWDOWN_HIGHSPEED:
                if ( params->bThrottleDown )
                  return MapGearToMidState(gear: this->m_iSoundGear, params);
                if ( this->m_iSoundGear != 0 )
                  goto LABEL_53;
                return SS_IDLE;
              case SS_TURBO:
                if ( !v4 || params->bTurbo )
                  goto LABEL_53;
                return MapGearToMidState(gear: this->m_iSoundGear, params);
              case SS_REVERSE:
                if ( !v4 || params->bReverse )
                  goto LABEL_53;
LABEL_45:
                result = SS_SLOWDOWN;
                break;
              default:
LABEL_53:
                result = stateOut;
                break;
            }
          }
        }
        break;
      case SS_TURBO:
        if ( !params->bVehicleInWater )
          goto LABEL_8;
        return SS_SHUTDOWN_WATER;
      default:
        goto LABEL_15;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10258270
// Name: public: virtual void CBaseServerVehicle::SoundStart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::SoundStart(CBaseServerVehicle *this)
{
  CBaseServerVehicle_vtbl *v2; // edx
  bool (__thiscall *IsVehicleBodyInWater)(CBaseServerVehicle *); // eax
  sound_states v4; // eax
  sound_states m_soundState; // [esp-4h] [ebp-1Ch]
  vbs_sound_update_t params; // [esp+4h] [ebp-14h] BYREF

  this->StartEngineRumble(this);
  v2 = this->__vftable;
  this->m_soundState = SS_NONE;
  params.flFrameTime = gpGlobals->frametime;
  params.bExitVehicle = false;
  IsVehicleBodyInWater = v2->IsVehicleBodyInWater;
  memset(&params.flCurrentSpeedFraction, 0, 11);
  params.bVehicleInWater = IsVehicleBodyInWater(this);
  v4 = CBaseServerVehicle::SoundState_ChooseState(this, &params);
  if ( v4 != this->m_soundState )
  {
    m_soundState = this->m_soundState;
    this->m_soundState = v4;
    CBaseServerVehicle::SoundState_OnNewState(this, lastState: m_soundState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102582F0
// Name: public: virtual void CBaseServerVehicle::SoundStartDisabled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::SoundStartDisabled(CBaseServerVehicle *this)
{
  CBaseServerVehicle_vtbl *v2; // edx
  int (*IsVehicleBodyInWater)(void); // eax
  const char *pszValue; // edi
  vbs_sound_update_t params; // [esp+14h] [ebp-14h] BYREF

  v2 = this->__vftable;
  this->m_soundState = SS_NONE;
  IsVehicleBodyInWater = (int (*)(void))v2->IsVehicleBodyInWater;
  params.flFrameTime = gpGlobals->frametime;
  memset(&params.flCurrentSpeedFraction, 0, 11);
  params.bExitVehicle = false;
  params.bVehicleInWater = IsVehicleBodyInWater();
  if ( CBaseServerVehicle::SoundState_ChooseState(this, &params) == SS_START_WATER )
  {
    pszValue = this->m_vehicleSounds.iszStateSounds[3].pszValue;
    if ( pszValue != nullptr && *pszValue != 0 )
    {
      if ( g_debug_vehiclesound.m_pParent != nullptr && g_debug_vehiclesound.m_pParent->m_Value.m_nValue != 0 )
        _Msg(a1: "Playing non-looping vehicle sound: %s\n", this->m_vehicleSounds.iszStateSounds[3].pszValue);
      CBaseEntity::EmitSound(this: this->m_pVehicle, soundname: pszValue, soundtime: 0.0, duration: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258390
// Name: public: virtual void CBaseServerVehicle::SoundUpdate(struct vbs_sound_update_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::SoundUpdate(CBaseServerVehicle *this, vbs_sound_update_t *params)
{
  ConVar *m_pParent; // eax
  const char *v4; // ecx
  const char *v5; // eax
  float flCurrentSpeedFraction; // xmm3_4
  float m_flSpeedPercentage; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  int v10; // xmm0_4
  sound_states v11; // eax
  sound_states m_soundState; // [esp+4h] [ebp-10h]

  m_pParent = g_debug_vehiclesound.m_pParent;
  if ( g_debug_vehiclesound.m_pParent != nullptr && g_debug_vehiclesound.m_pParent->m_Value.m_nValue > 1 )
  {
    v4 = "on";
    if ( !params->bReverse )
      v4 = "off";
    v5 = "on";
    if ( !params->bThrottleDown )
      v5 = "off";
    _Msg(a1: "Throttle: %s, Reverse: %s\n", v5, v4);
    m_pParent = g_debug_vehiclesound.m_pParent;
  }
  flCurrentSpeedFraction = params->flCurrentSpeedFraction;
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue > 1 )
    _Msg(a1: "CurrentSpeed: %.3f  ", flCurrentSpeedFraction);
  if ( this->m_vehicleSounds.pGears.m_Size > 0 )
  {
    m_flSpeedPercentage = this->m_flSpeedPercentage;
    if ( flCurrentSpeedFraction > m_flSpeedPercentage )
    {
      if ( !params->bThrottleDown )
        flCurrentSpeedFraction = this->m_flSpeedPercentage;
      v8 = this->m_vehicleSounds.pGears.m_Memory.m_pMemory[this->m_iSoundGear].flSpeedApproachFactor
         * params->flFrameTime;
      if ( (float)(flCurrentSpeedFraction - m_flSpeedPercentage) <= v8 )
      {
        if ( COERCE_FLOAT(LODWORD(v8) ^ _mask__NegFloat_) <= (float)(flCurrentSpeedFraction - m_flSpeedPercentage) )
          v9 = flCurrentSpeedFraction;
        else
          v9 = m_flSpeedPercentage - v8;
      }
      else
      {
        v9 = v8 + m_flSpeedPercentage;
      }
      flCurrentSpeedFraction = v9;
    }
  }
  v10 = 0;
  if ( flCurrentSpeedFraction < 0.0 || (v10 = 1065353216, flCurrentSpeedFraction > 1.0) )
    flCurrentSpeedFraction = *(float *)&v10;
  this->m_flSpeedPercentage = flCurrentSpeedFraction;
  if ( g_debug_vehiclesound.m_pParent != nullptr && g_debug_vehiclesound.m_pParent->m_Value.m_nValue > 1 )
    _Msg(a1: "Sound Speed: %.3f\n", flCurrentSpeedFraction);
  this->RecalculateSoundGear(this, a2: params);
  v11 = CBaseServerVehicle::SoundState_ChooseState(this, params);
  if ( v11 != this->m_soundState )
  {
    m_soundState = this->m_soundState;
    this->m_soundState = v11;
    CBaseServerVehicle::SoundState_OnNewState(this, lastState: m_soundState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258500
// Name: public: virtual void CBaseServerVehicle::RecalculateSoundGear(struct vbs_sound_update_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::RecalculateSoundGear(CBaseServerVehicle *this, vbs_sound_update_t *params)
{
  int v2; // eax
  float *p_flMinSpeed; // edx

  v2 = this->m_vehicleSounds.pGears.m_Size - 1;
  if ( v2 >= 0 )
  {
    p_flMinSpeed = &this->m_vehicleSounds.pGears.m_Memory.m_pMemory[v2].flMinSpeed;
    while ( this->m_flSpeedPercentage <= *p_flMinSpeed )
    {
      p_flMinSpeed -= 4;
      if ( --v2 < 0 )
        goto LABEL_7;
    }
    this->m_iSoundGear = v2;
  }
LABEL_7:
  if ( params->bReverse )
    this->m_iSoundGear = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10258550
// Name: public: virtual class CBaseCombatCharacter __near * CBaseServerVehicle::NPC_GetPassengerInSeat(int,int)
// Source: json
//------------------------------------------------------------------------------
CBaseCombatCharacter *__thiscall CBaseServerVehicle::NPC_GetPassengerInSeat(
        CBaseServerVehicle *this,
        int nRoleID,
        int nSeatID)
{
  int m_Size; // edx
  int v4; // eax
  CPassengerInfo *m_pMemory; // esi
  CPassengerInfo *i; // ecx
  unsigned int m_Index; // eax

  m_Size = this->m_PassengerInfo.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_PassengerInfo.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_nSeat != nSeatID || i->m_nRole != nRoleID; ++i )
  {
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  m_Index = m_pMemory[v4].m_hPassenger.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseCombatCharacter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x102585C0
// Name: protected: int CBaseServerVehicle::NPC_GetAvailableSeat_Any(class CBaseCombatCharacter __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServerVehicle::NPC_GetAvailableSeat_Any(
        CBaseServerVehicle *this,
        CBaseCombatCharacter *pPassenger,
        int nRoleID)
{
  int v3; // eax
  int v5; // edi
  CBaseCombatCharacter *v7; // eax

  v3 = nRoleID;
  v5 = 0;
  if ( this->m_PassengerRoles.m_Memory.m_pMemory[nRoleID].m_PassengerSeats.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v7 = this->NPC_GetPassengerInSeat(this, a2: v3, a3: v5);
    if ( v7 == nullptr || v7 == pPassenger )
      break;
    if ( ++v5 >= this->m_PassengerRoles.m_Memory.m_pMemory[nRoleID].m_PassengerSeats.m_Size )
      return -1;
    v3 = nRoleID;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10258630
// Name: protected: int CBaseServerVehicle::FindRoleIndexByName(struct string_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServerVehicle::FindRoleIndexByName(CBaseServerVehicle *this, string_t strRoleName)
{
  int v3; // ebx
  int i; // edi
  const char *pszValue; // ecx
  const char *v6; // eax

  v3 = 0;
  if ( this->m_PassengerRoles.m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    pszValue = strRoleName.pszValue;
    if ( strRoleName.pszValue == nullptr )
      pszValue = locale;
    v6 = this->m_PassengerRoles.m_Memory.m_pMemory[i].m_strName.pszValue;
    if ( v6 == nullptr )
      v6 = locale;
    if ( v6 == pszValue || _V_stricmp(s1: v6, s2: pszValue) == 0 )
      break;
    if ( ++v3 >= this->m_PassengerRoles.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10258690
// Name: protected: int CBaseServerVehicle::FindSeatIndexByName(int,struct string_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServerVehicle::FindSeatIndexByName(CBaseServerVehicle *this, int nRoleIndex, string_t strSeatName)
{
  int result; // eax
  CBaseEntity *v5; // eax
  CBaseAnimating *v6; // eax
  const char *pszValue; // ecx
  int v8; // eax
  CPassengerRole *v9; // edx
  int m_Size; // ecx
  int v11; // ebx
  int *i; // edx

  if ( nRoleIndex < 0 )
    return -1;
  if ( nRoleIndex >= this->m_PassengerRoles.m_Size )
    return -1;
  v5 = this->GetVehicleEnt(this);
  v6 = (CBaseAnimating *)__RTDynamicCast(
                           inptr: v5,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CBaseAnimating `RTTI Type Descriptor',
                           isReference: 0);
  if ( v6 == nullptr )
    return -1;
  pszValue = strSeatName.pszValue;
  if ( strSeatName.pszValue == nullptr )
    pszValue = locale;
  v8 = CBaseAnimating::LookupAttachment(this: v6, szName: pszValue);
  v9 = &this->m_PassengerRoles.m_Memory.m_pMemory[nRoleIndex];
  m_Size = v9->m_PassengerSeats.m_Size;
  v11 = v8;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = &v9->m_PassengerSeats.m_Memory.m_pMemory->m_nAttachmentID; *i != v11; i += 12 )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10258720
// Name: public: virtual void CBaseServerVehicle::RestorePassengerInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::RestorePassengerInfo(CBaseServerVehicle *this)
{
  int v2; // ebx
  int RoleIndexByName; // eax
  int v4; // edi
  int SeatIndexByName; // eax
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  if ( this->m_PassengerInfo.m_Size != 0 && !this->m_bParsedAnimations )
  {
    this->ParseEntryExitAnims(this);
    this->m_bParsedAnimations = true;
  }
  for ( i = 0; i < this->m_PassengerInfo.m_Size; ++i )
  {
    RoleIndexByName = CBaseServerVehicle::FindRoleIndexByName(
                        this,
                        strRoleName: this->m_PassengerInfo.m_Memory.m_pMemory[v2].m_strRoleName);
    v4 = RoleIndexByName;
    if ( RoleIndexByName >= 0 && RoleIndexByName < this->m_PassengerRoles.m_Size )
    {
      this->m_PassengerInfo.m_Memory.m_pMemory[v2].m_nRole = RoleIndexByName;
      SeatIndexByName = CBaseServerVehicle::FindSeatIndexByName(
                          this,
                          nRoleIndex: RoleIndexByName,
                          strSeatName: this->m_PassengerInfo.m_Memory.m_pMemory[v2].m_strSeatName);
      if ( SeatIndexByName >= 0
        && SeatIndexByName < this->m_PassengerRoles.m_Memory.m_pMemory[v4].m_PassengerSeats.m_Size )
      {
        this->m_PassengerInfo.m_Memory.m_pMemory[v2].m_nSeat = SeatIndexByName;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102587B0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct vehicle_gear_t,class CUtlMemory<struct vehicle_gear_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &vehicle_gear_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258870
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct vehicle_crashsound_t,class CUtlMemory<struct vehicle_crashsound_t,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &vehicle_crashsound_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258930
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<class CPassengerInfo,class CUtlMemory<class CPassengerInfo,int>>,10>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int>>,10>::Save(
        CUtlVectorDataOps<CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int> > *pField; // eax
  ISave *v4; // esi
  int v5; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const SaveRestoreFieldInfo_t *m_Size; // ecx
  int v8; // ebx
  typedescription_t dataDesc; // [esp+8h] [ebp-58h] BYREF
  datamap_t dataMap; // [esp+44h] [ebp-1Ch] BYREF
  CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int> > *pUtlVector; // [esp+5Ch] [ebp-4h]

  pField = (CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int> > *)fieldInfo->pField;
  v4 = pSave;
  v5 = 0;
  dataMap.dataDesc = &dataDesc;
  WriteInt_2 = pSave->WriteInt_2;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &CPassengerInfo::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  m_Size = (const SaveRestoreFieldInfo_t *)pField->m_Size;
  pUtlVector = pField;
  fieldInfo = m_Size;
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  dataDesc.fieldSizeInBytes = 0;
  if ( (int)fieldInfo > 0 )
  {
    v8 = 0;
    do
    {
      v4->WriteAll(this: v4, a2: &pUtlVector->m_Memory.m_pMemory[v8], a3: &dataMap);
      ++v5;
      ++v8;
    }
    while ( v5 < (int)fieldInfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258AA0
// Name: public: virtual bool CBaseServerVehicle::NPC_AddPassenger(class CBaseCombatCharacter __near *,struct string_t,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServerVehicle::NPC_AddPassenger(
        CBaseServerVehicle *this,
        CBaseCombatCharacter *pPassenger,
        string_t strRoleName,
        int nSeat)
{
  int RoleIndexByName; // edi
  CBaseCombatCharacter *v6; // eax
  int m_Size; // edx
  CPassengerInfo *m_pMemory; // esi
  CPassengerInfo *i; // ecx

  if ( pPassenger != nullptr && !pPassenger->IsPlayer(this: pPassenger) )
  {
    RoleIndexByName = CBaseServerVehicle::FindRoleIndexByName(this, strRoleName);
    if ( RoleIndexByName != -1 )
    {
      v6 = this->NPC_GetPassengerInSeat(this, a2: RoleIndexByName, a3: nSeat);
      if ( v6 == pPassenger )
        return 1;
      if ( v6 == nullptr )
      {
        m_Size = this->m_PassengerInfo.m_Size;
        if ( m_Size > 0 )
        {
          m_pMemory = this->m_PassengerInfo.m_Memory.m_pMemory;
          for ( i = m_pMemory; i->m_nSeat != nSeat || i->m_nRole != RoleIndexByName; ++i )
          {
            v6 = (CBaseCombatCharacter *)((char *)v6 + 1);
            if ( (int)v6 >= m_Size )
              return 0;
          }
          CHandle<CBaseEntity>::operator=(
            this: (CHandle<CBaseEntity> *)&m_pMemory[(_DWORD)v6].m_hPassenger,
            val: pPassenger);
          return 1;
        }
      }
    }
    return 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10258B40
// Name: public: virtual bool CBaseServerVehicle::GetPassengerExitPoint(int,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServerVehicle::GetPassengerExitPoint(
        CBaseServerVehicle *this,
        int nRole,
        Vector *pExitPoint,
        QAngle *pAngles)
{
  CBaseAnimating *v5; // eax
  CBaseEntity *m_pVehicle; // ecx
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // eax
  const CViewVectors *v8; // eax
  float v10; // xmm0_4
  CBaseEntity *v11; // esi
  const Vector *v12; // eax
  Vector *p_m_vHullMin; // [esp+14h] [ebp-108h]
  Vector *v14; // [esp+18h] [ebp-104h]
  const Vector *p_m_vHullMax; // [esp+20h] [ebp-FCh]
  const IHandleEntity *v16; // [esp+28h] [ebp-F4h]
  CGameTrace tr; // [esp+38h] [ebp-E4h] BYREF
  CGameTrace ptr; // [esp+8Ch] [ebp-90h] BYREF
  Vector vecWorldMins; // [esp+E0h] [ebp-3Ch] BYREF
  Vector vecAbsStart; // [esp+ECh] [ebp-30h] BYREF
  QAngle vehicleExitAngles; // [esp+F8h] [ebp-24h] BYREF
  Vector vecWorldMaxs; // [esp+104h] [ebp-18h] BYREF
  Vector vehicleExitOrigin; // [esp+110h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+11Ch] [ebp+0h] BYREF

  v5 = (CBaseAnimating *)__RTDynamicCast(
                           inptr: this->m_pVehicle,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CBaseAnimating `RTTI Type Descriptor',
                           isReference: 0);
  if ( v5 == nullptr )
    goto LABEL_8;
  if ( !CBaseAnimating::GetAttachment(
          this: v5,
          szName: "vehicle_driver_exit",
          absOrigin: &vehicleExitOrigin,
          absAngles: &vehicleExitAngles) )
    goto LABEL_8;
  m_pVehicle = this->m_pVehicle;
  vecAbsStart.x = vehicleExitOrigin.x;
  v16 = m_pVehicle;
  GetViewVectors = g_pGameRules->GetViewVectors;
  vecAbsStart.y = vehicleExitOrigin.y;
  vecAbsStart.z = vehicleExitOrigin.z + 12.0;
  p_m_vHullMax = &GetViewVectors(this: g_pGameRules)->m_vHullMax;
  v8 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)this,
    &vecAbsStart,
    vecAbsEnd: &vehicleExitOrigin,
    hullMin: &v8->m_vHullMin,
    hullMax: p_m_vHullMax,
    mask: 0x201400Bu,
    ignore: v16,
    collisionGroup: 0,
    &ptr);
  if ( !ptr.startsolid )
  {
    *pAngles = vehicleExitAngles;
    *pExitPoint = ptr.endpos;
    return true;
  }
  else
  {
LABEL_8:
    if ( ((unsigned __int8 (__thiscall *)(CBaseServerVehicle *, int, int, Vector *))this->CheckExitPoint)(
           a1: this,
           a2: 1119092736,
           a3: 90,
           a4: pExitPoint) != 0
      || ((unsigned __int8 (__thiscall *)(CBaseServerVehicle *, int, int, Vector *))this->CheckExitPoint)(
           a1: this,
           a2: -1028390912,
           a3: 90,
           a4: pExitPoint) != 0
      || ((unsigned __int8 (__thiscall *)(CBaseServerVehicle *, _DWORD, int, Vector *))this->CheckExitPoint)(
           a1: this,
           a2: 0,
           a3: 100,
           a4: pExitPoint) != 0
      || ((unsigned __int8 (__thiscall *)(CBaseServerVehicle *, int, int, Vector *))this->CheckExitPoint)(
           a1: this,
           a2: 1127481344,
           a3: 170,
           a4: pExitPoint) != 0 )
    {
      return true;
    }
    else
    {
      CCollisionProperty::CollisionAABBToWorldAABB(
        this: &this->m_pVehicle->m_Collision,
        entityMins: &this->m_pVehicle->m_Collision.m_vecMins.m_Value,
        entityMaxs: &this->m_pVehicle->m_Collision.m_vecMaxs.m_Value,
        pWorldMins: &vecWorldMins,
        pWorldMaxs: &vecWorldMaxs);
      v10 = vecWorldMaxs.z + 50.0;
      v11 = this->m_pVehicle;
      pExitPoint->x = (float)(vecWorldMaxs.x + vecWorldMins.x) * 0.5;
      pExitPoint->y = (float)(vecWorldMaxs.y + vecWorldMins.y) * 0.5;
      pExitPoint->z = v10;
      v14 = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
      p_m_vHullMin = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
      v12 = CCollisionProperty::WorldSpaceCenter(this: &v11->m_Collision);
      UTIL_TraceHull(
        a1: &savedregs,
        a2: (int)v11,
        vecAbsStart: v12,
        vecAbsEnd: pExitPoint,
        hullMin: p_m_vHullMin,
        hullMax: v14,
        mask: 0x201400Bu,
        ignore: v11,
        collisionGroup: 0,
        ptr: &tr);
      return !tr.startsolid;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258D90
// Name: public: virtual int CBaseServerVehicle::NPC_GetAvailableSeat(class CBaseCombatCharacter __near *,struct string_t,enum VehicleSeatQuery_e)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServerVehicle::NPC_GetAvailableSeat(
        CBaseServerVehicle *this,
        CBaseCombatCharacter *pPassenger,
        string_t strRoleName,
        VehicleSeatQuery_e nQueryType)
{
  int RoleIndexByName; // eax

  if ( !this->m_bParsedAnimations )
  {
    this->ParseEntryExitAnims(this);
    this->m_bParsedAnimations = true;
  }
  RoleIndexByName = CBaseServerVehicle::FindRoleIndexByName(this, strRoleName);
  if ( RoleIndexByName < 0 || RoleIndexByName >= this->m_PassengerRoles.m_Size || nQueryType != VEHICLE_SEAT_ANY )
    return -1;
  else
    return CBaseServerVehicle::NPC_GetAvailableSeat_Any(this, pPassenger, nRoleID: RoleIndexByName);
}

//------------------------------------------------------------------------------
// Address: 0x10258F40
// Name: private: bool CBaseServerVehicle::GetLocalAttachmentAtTime(int,int,float,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServerVehicle::GetLocalAttachmentAtTime(
        CBaseServerVehicle *this,
        int nQuerySequence,
        int nAttachmentIndex,
        float flCyclePoint,
        Vector *vecOriginOut,
        QAngle *vecAnglesOut)
{
  CBaseAnimating *v6; // esi
  int m_Value; // ebx
  CBaseEdict *v9; // ecx
  CBaseEdict *v10; // ecx
  QAngle vecAngles; // [esp+4h] [ebp-1Ch] BYREF
  Vector vecOrigin; // [esp+10h] [ebp-10h] BYREF
  float flOldCycle; // [esp+1Ch] [ebp-4h]

  v6 = this->m_pVehicle->GetBaseAnimating(this: this->m_pVehicle);
  if ( v6 == nullptr )
    return 0;
  m_Value = v6->m_nSequence.m_Value;
  flOldCycle = v6->m_flCycle.m_Value;
  CBaseAnimating::SetSequence(this: v6, nSequence: nQuerySequence);
  if ( v6->m_flCycle.m_Value != flCyclePoint )
  {
    if ( v6->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v6->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = &v6->m_Network.m_pPev->CBaseEdict;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: v9, offset: 0x3ACu);
    }
    v6->m_flCycle.m_Value = flCyclePoint;
  }
  v6->InvalidateBoneCache(this: v6);
  CBaseAnimating::GetAttachmentLocal(this: v6, iAttachment: nAttachmentIndex, origin: &vecOrigin, angles: &vecAngles);
  if ( vecOriginOut != nullptr )
    *vecOriginOut = vecOrigin;
  if ( vecAnglesOut != nullptr )
    *vecAnglesOut = vecAngles;
  CBaseAnimating::SetSequence(this: v6, nSequence: m_Value);
  if ( v6->m_flCycle.m_Value != flOldCycle )
  {
    if ( v6->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v6->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = &v6->m_Network.m_pPev->CBaseEdict;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: v10, offset: 0x3ACu);
    }
    v6->m_flCycle.m_Value = flOldCycle;
  }
  v6->InvalidateBoneCache(this: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10259090
// Name: private: void CBaseServerVehicle::CacheEntryExitPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::CacheEntryExitPoints(CBaseServerVehicle *this)
{
  CBaseAnimating *v2; // eax
  int v3; // ebx
  CBaseServerVehicle::exitanim_t *v4; // edi
  CBaseAnimating *v5; // eax
  int v6; // eax
  CBaseServerVehicle::exitanim_t *m_pMemory; // eax
  __int64 v8; // xmm0_8
  QAngle *v9; // eax
  QAngle vecExitAngles; // [esp+18h] [ebp-3Ch] BYREF
  Vector mins; // [esp+24h] [ebp-30h] BYREF
  Vector maxs; // [esp+30h] [ebp-24h] BYREF
  Vector vecExitPoint; // [esp+3Ch] [ebp-18h] BYREF
  CBaseAnimating *pAnimating; // [esp+48h] [ebp-Ch]
  int nAttachment; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]

  v2 = this->m_pVehicle->GetBaseAnimating(this: this->m_pVehicle);
  v3 = 0;
  pAnimating = v2;
  if ( v2 != nullptr )
  {
    nAttachment = CBaseAnimating::LookupAttachment(this: v2, szName: "vehicle_driver_eyes");
    for ( i = 0; i < this->m_ExitAnimations.m_Size; ++i )
    {
      v4 = &this->m_ExitAnimations.m_Memory.m_pMemory[v3];
      v5 = this->m_pVehicle->GetBaseAnimating(this: this->m_pVehicle);
      if ( v5 == nullptr
        || (v6 = CBaseAnimating::LookupSequence(this: v5, label: v4->szAnimName)) < 0
        || CBaseServerVehicle::GetLocalAttachmentAtTime(
             this,
             nQuerySequence: v6,
             nAttachmentIndex: nAttachment,
             flCyclePoint: 1.0,
             vecOriginOut: &v4->vecExitPointLocal,
             vecAnglesOut: &v4->vecExitAnglesLocal) == 0 )
      {
        _Warning(
          a1: "Exit animation %s failed to cache target points properly!\n",
          this->m_ExitAnimations.m_Memory.m_pMemory[v3].szAnimName);
      }
      if ( g_debug_vehicleexit.m_pParent != nullptr && g_debug_vehicleexit.m_pParent->m_Value.m_nValue != 0 )
      {
        m_pMemory = this->m_ExitAnimations.m_Memory.m_pMemory;
        v8 = *(_QWORD *)&m_pMemory[v3].vecExitPointLocal.x;
        v9 = (QAngle *)&m_pMemory[v3];
        *(_QWORD *)&vecExitPoint.x = v8;
        vecExitPoint.z = v9[11].z;
        vecExitAngles = v9[12];
        UTIL_ParentToWorldSpace(pEntity: pAnimating, vecPosition: &vecExitPoint, vecAngles: &vecExitAngles);
        maxs.x = 8.0;
        maxs.y = 8.0;
        maxs.z = 8.0;
        mins.x = -8.0;
        mins.y = -8.0;
        mins.z = -8.0;
        NDebugOverlay::Box(origin: &vecExitPoint, &mins, &maxs, r: 0, g: 255, b: 0, a: 0, flDuration: 20.0);
        NDebugOverlay::Axis(
          position: &vecExitPoint,
          angles: &vecExitAngles,
          size: 8.0,
          noDepthTest: true,
          flDuration: 20.0);
      }
      ++v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10259240
// Name: public: virtual void CBaseServerVehicle::HandlePassengerEntry(class CBaseCombatCharacter __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::HandlePassengerEntry(
        CBaseServerVehicle *this,
        CBasePlayer *pPassenger,
        bool bAllowEntryOutsideZone)
{
  CBaseServerVehicle_vtbl *v5; // esi
  Vector *v6; // eax
  CBaseAnimating *v7; // esi
  CBaseEdict *v8; // ecx
  _BYTE v9[12]; // [esp+1Ch] [ebp-Ch] BYREF
  int iEntryAnim; // [esp+30h] [ebp+8h]
  float *bAllowEntryOutsideZonea; // [esp+34h] [ebp+Ch]

  if ( pPassenger != nullptr && pPassenger->IsPlayer(this: pPassenger) )
  {
    v5 = this->__vftable;
    v6 = pPassenger->EyePosition(this: pPassenger, result: v9);
    iEntryAnim = v5->GetEntryAnimForPoint(this, a2: v6);
    v7 = (CBaseAnimating *)__RTDynamicCast(
                             inptr: this->m_pVehicle,
                             VfDelta: 0,
                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                             TargetType: &CBaseAnimating `RTTI Type Descriptor',
                             isReference: 0);
    if ( v7 != nullptr )
    {
      if ( iEntryAnim == -1 )
      {
        if ( !bAllowEntryOutsideZone )
          return;
        iEntryAnim = CBaseAnimating::LookupSequence(
                       this: v7,
                       label: this->m_EntryAnimations.m_Memory.m_pMemory->szAnimName);
      }
      if ( this->m_pDrivableVehicle->CanEnterVehicle(this: this->m_pDrivableVehicle, a2: pPassenger)
        && CBasePlayer::CanEnterVehicle(this: pPassenger, pVehicle: this, nRole: 0) )
      {
        CBaseAnimating::SetCycle(this: v7, flCycle: 0.0);
        bAllowEntryOutsideZonea = &gpGlobals->curtime;
        if ( v7->m_flAnimTime.m_Value != gpGlobals->curtime )
        {
          if ( v7->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v7->m_Network + 76) |= 1u;
          }
          else
          {
            v8 = &v7->m_Network.m_pPev->CBaseEdict;
            if ( v8 != nullptr )
              CBaseEdict::StateChanged(this: v8, offset: 0x64u);
          }
          v7->m_flAnimTime.m_Value = *bAllowEntryOutsideZonea;
        }
        CBaseAnimating::ResetSequence(this: v7, nSequence: iEntryAnim);
        CBaseAnimating::ResetClientsideFrame(this: v7);
        v7->InvalidateBoneCache(this: v7);
        this->m_pDrivableVehicle->SetVehicleEntryAnim(this: this->m_pDrivableVehicle, a2: true);
        pPassenger->GetInVehicle(this: pPassenger, a2: this, a3: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10259390
// Name: public: virtual bool CBaseServerVehicle::HandlePassengerExit(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServerVehicle::HandlePassengerExit(CBaseServerVehicle *this, CBaseCombatCharacter *pPassenger)
{
  CBaseCombatCharacter *v2; // esi
  bool (__thiscall *IsVehicleBodyInWater)(CBaseServerVehicle *); // eax
  sound_states v5; // eax
  float z; // ecx
  unsigned int v7; // edx
  CBaseServerVehicle_vtbl *v8; // edx
  int (__thiscall *GetPassengerRole)(struct CBaseServerVehicle *, CBaseCombatCharacter *); // eax
  int v10; // ebx
  CBaseAnimating *v11; // eax
  CBaseAnimating *v12; // ebx
  bool v13; // zf
  CBaseEdict *v14; // ecx
  CBaseCombatWeapon *ActiveWeapon; // eax
  const CViewVectors *v16; // eax
  const CViewVectors *v17; // eax
  CEntityBlocker *v18; // eax
  Vector *p_m_vHullMax; // [esp+28h] [ebp-58h]
  sound_states flCycle; // [esp+30h] [ebp-50h]
  Vector vecNewPos; // [esp+40h] [ebp-40h] BYREF
  QAngle angNewAngles; // [esp+4Ch] [ebp-34h] BYREF
  Vector vecExitFeetPoint; // [esp+58h] [ebp-28h] BYREF
  float v25; // [esp+64h] [ebp-1Ch]
  float v26; // [esp+68h] [ebp-18h]
  Vector vecExitPoint; // [esp+6Ch] [ebp-14h] BYREF
  float *p_curtime; // [esp+78h] [ebp-8h]
  int iSequence; // [esp+7Ch] [ebp-4h]

  v2 = pPassenger;
  if ( pPassenger != nullptr && pPassenger->IsPlayer(this: pPassenger) )
  {
    UTIL_HudHintText(pEntity: v2, pMessage: locale);
    IsVehicleBodyInWater = this->IsVehicleBodyInWater;
    vecExitFeetPoint.x = gpGlobals->frametime;
    vecExitFeetPoint.y = 0.0;
    vecExitFeetPoint.z = 0.0;
    LOWORD(v25) = 0;
    BYTE2(v25) = 0;
    HIBYTE(v25) = IsVehicleBodyInWater(this);
    LOBYTE(v26) = 1;
    v5 = CBaseServerVehicle::SoundState_ChooseState(this, params: (vbs_sound_update_t *)&vecExitFeetPoint);
    if ( v5 != this->m_soundState )
    {
      flCycle = this->m_soundState;
      this->m_soundState = v5;
      CBaseServerVehicle::SoundState_OnNewState(this, lastState: flCycle);
    }
    iSequence = this->GetExitAnimToUse(this, a2: &vecExitPoint, a3: (bool *)&pPassenger + 3);
    if ( (v2->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v2);
    z = v2->m_vecAbsOrigin.z;
    v7 = (unsigned int)v2->m_iEFlags >> 11;
    *(_QWORD *)&vecNewPos.x = *(_QWORD *)&v2->m_vecAbsOrigin.x;
    vecNewPos.z = z;
    if ( (v7 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v2);
    v8 = this->__vftable;
    angNewAngles.z = v2->m_angAbsRotation.z;
    GetPassengerRole = v8->GetPassengerRole;
    *(_QWORD *)&angNewAngles.x = *(_QWORD *)&v2->m_angAbsRotation.x;
    v10 = GetPassengerRole(this, a2: v2);
    if ( HIBYTE(pPassenger) == 0 && iSequence != -1 )
      goto LABEL_14;
    if ( this->GetPassengerExitPoint(this, a2: v10, a3: &vecNewPos, a4: &angNewAngles)
      || this->m_pDrivableVehicle->AllowBlockedExit(this: this->m_pDrivableVehicle, a2: v2, a3: v10) )
    {
      this->HandleEntryExitFinish(this, a2: false, a3: true);
LABEL_14:
      this->m_pDrivableVehicle->PreExitVehicle(this: this->m_pDrivableVehicle, a2: v2, a3: v10);
      if ( iSequence > -1
        && (v11 = (CBaseAnimating *)__RTDynamicCast(
                                      inptr: this->m_pVehicle,
                                      VfDelta: 0,
                                      SrcType: &CBaseEntity `RTTI Type Descriptor',
                                      TargetType: &CBaseAnimating `RTTI Type Descriptor',
                                      isReference: 0),
            v12 = v11,
            v11 != nullptr) )
      {
        CBaseAnimating::SetCycle(this: v11, flCycle: 0.0);
        v13 = v12->m_flAnimTime.m_Value == gpGlobals->curtime;
        p_curtime = &gpGlobals->curtime;
        if ( !v13 )
        {
          if ( v12->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v12->m_Network + 76) |= 1u;
          }
          else
          {
            v14 = &v12->m_Network.m_pPev->CBaseEdict;
            if ( v14 != nullptr )
              CBaseEdict::StateChanged(this: v14, offset: 0x64u);
          }
          v12->m_flAnimTime.m_Value = *p_curtime;
        }
        CBaseAnimating::ResetSequence(this: v12, nSequence: iSequence);
        CBaseAnimating::ResetClientsideFrame(this: v12);
        ((void (__thiscall *)(IDrivableVehicle *, int, _DWORD, _DWORD, _DWORD))this->m_pDrivableVehicle->SetVehicleExitAnim)(
          a1: this->m_pDrivableVehicle,
          a2: 1,
          a3: LODWORD(vecExitPoint.x),
          a4: LODWORD(vecExitPoint.y),
          a5: LODWORD(vecExitPoint.z));
        if ( v2->IsAlive(this: v2) && CBaseCombatCharacter::GetActiveWeapon(this: v2) != nullptr )
        {
          ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v2);
          ActiveWeapon->Deploy(this: ActiveWeapon);
          CBasePlayer::ShowCrosshair(this: (CBasePlayer *)v2, bShow: true);
        }
        v16 = g_pGameRules->GetViewVectors(this: g_pGameRules);
        vecExitFeetPoint.z = vecExitPoint.x - v16->m_vView.x;
        v25 = vecExitPoint.y - v16->m_vView.y;
        v26 = vecExitPoint.z - v16->m_vView.z;
        p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
        v17 = g_pGameRules->GetViewVectors(this: g_pGameRules);
        v18 = CEntityBlocker::Create(
                origin: (Vector *)&vecExitFeetPoint.z,
                mins: &v17->m_vHullMin,
                maxs: p_m_vHullMax,
                pOwner: v2,
                bBlockPhysics: true);
        if ( v18 != nullptr )
          this->m_hExitBlocker.m_Index = v18->GetRefEHandle(this: v18)->m_Index;
        else
          this->m_hExitBlocker.m_Index = -1;
        CBaseEntity::SetAbsOrigin(this: v2, absOrigin: (Vector *)&vecExitFeetPoint.z);
        v2->SetParent(this: v2, a2: nullptr, a3: -1);
        return 1;
      }
      else
      {
        ((void (__thiscall *)(CBaseCombatCharacter *, Vector *, QAngle *))v2->__vftable[1].IsPlayer)(
          a1: v2,
          a2: &vecNewPos,
          a3: &angNewAngles);
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102596B0
// Name: public: virtual void CBaseServerVehicle::HandleEntryExitFinish(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::HandleEntryExitFinish(CBaseServerVehicle *this, bool bExitAnimOn, bool bResetAnim)
{
  CBaseAnimating *v4; // ebx
  CBaseEntity *v5; // edi
  int m_iCurrentExitAnim; // eax
  CBaseServerVehicle::exitanim_t *m_pMemory; // ecx
  int v8; // eax
  float x; // xmm0_4
  QAngle *v10; // eax
  float *p_curtime; // edx
  CBaseEdict *v12; // ecx
  Vector mins; // [esp+18h] [ebp-30h] BYREF
  Vector maxs; // [esp+24h] [ebp-24h] BYREF
  QAngle vecEyeAng; // [esp+30h] [ebp-18h] BYREF
  Vector vecEyes; // [esp+3Ch] [ebp-Ch] BYREF
  float *bExitAnimOna; // [esp+50h] [ebp+8h]
  int iSequence; // [esp+54h] [ebp+Ch]

  if ( !this->m_bParsedAnimations )
  {
    this->ParseEntryExitAnims(this);
    this->m_bParsedAnimations = true;
  }
  v4 = this->m_pVehicle->GetBaseAnimating(this: this->m_pVehicle);
  if ( v4 != nullptr )
  {
    if ( bExitAnimOn )
    {
      v5 = this->GetDriver(this);
      if ( v5 != nullptr && v5->IsPlayer(this: v5) )
      {
        m_iCurrentExitAnim = this->m_iCurrentExitAnim;
        if ( m_iCurrentExitAnim < 0 || m_iCurrentExitAnim >= this->m_ExitAnimations.m_Size )
        {
          CBaseAnimating::GetAttachment(
            this: v4,
            szName: "vehicle_driver_eyes",
            absOrigin: &vecEyes,
            absAngles: &vecEyeAng);
        }
        else
        {
          m_pMemory = this->m_ExitAnimations.m_Memory.m_pMemory;
          v8 = m_iCurrentExitAnim;
          x = m_pMemory[v8].vecExitPointLocal.x;
          v10 = (QAngle *)&m_pMemory[v8];
          vecEyes.x = x;
          vecEyes.y = v10[11].y;
          vecEyes.z = v10[11].z;
          vecEyeAng = v10[12];
          UTIL_ParentToWorldSpace(pEntity: v4, vecPosition: &vecEyes, vecAngles: &vecEyeAng);
          vecEyes = this->m_vecCurrentExitEndPoint;
        }
        if ( g_debug_vehicleexit.m_pParent != nullptr && g_debug_vehicleexit.m_pParent->m_Value.m_nValue != 0 )
        {
          maxs.x = 2.0;
          maxs.y = 2.0;
          maxs.z = 2.0;
          mins.x = -2.0;
          mins.y = -2.0;
          mins.z = -2.0;
          NDebugOverlay::Box(origin: &vecEyes, &mins, &maxs, r: 255, g: 0, b: 0, a: 64, flDuration: 10.0);
        }
        ((void (__thiscall *)(CBaseEntity *, Vector *, QAngle *))v5->__vftable[2].GetKeyValue)(
          a1: v5,
          a2: &vecEyes,
          a3: &vecEyeAng);
      }
    }
    if ( bResetAnim )
    {
      iSequence = CBaseAnimating::SelectWeightedSequence(this: v4, activity: ACT_IDLE);
      if ( iSequence > -1 )
      {
        CBaseAnimating::SetCycle(this: v4, flCycle: 0.0);
        p_curtime = &gpGlobals->curtime;
        bExitAnimOna = &gpGlobals->curtime;
        if ( v4->m_flAnimTime.m_Value != gpGlobals->curtime )
        {
          if ( v4->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v4->m_Network + 76) |= 1u;
          }
          else
          {
            v12 = &v4->m_Network.m_pPev->CBaseEdict;
            if ( v12 != nullptr )
            {
              CBaseEdict::StateChanged(this: v12, offset: 0x64u);
              p_curtime = bExitAnimOna;
            }
          }
          v4->m_flAnimTime.m_Value = *p_curtime;
        }
        CBaseAnimating::ResetSequence(this: v4, nSequence: iSequence);
        CBaseAnimating::ResetClientsideFrame(this: v4);
      }
    }
    this->m_pDrivableVehicle->SetVehicleEntryAnim(this: this->m_pDrivableVehicle, a2: false);
    ((void (__thiscall *)(IDrivableVehicle *, _DWORD, _DWORD, _DWORD, _DWORD))this->m_pDrivableVehicle->SetVehicleExitAnim)(
      a1: this->m_pDrivableVehicle,
      a2: 0,
      a3: LODWORD(vec3_origin.x),
      a4: LODWORD(vec3_origin.y),
      a5: LODWORD(vec3_origin.z));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10259910
// Name: public: virtual void CVehicleSoundsParser::SetDefaults(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleSoundsParser::SetDefaults(CVehicleSoundsParser *this, vehiclesounds_t *pData)
{
  vehiclesounds_t::Init(this: pData);
}

//------------------------------------------------------------------------------
// Address: 0x10259920
// Name: public: virtual void CBaseServerVehicle::GetPassengerSeatPoint(int,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::GetPassengerSeatPoint(
        CBaseServerVehicle *this,
        int nRole,
        Vector *pPoint,
        QAngle *pAngles)
{
  CBaseAnimating *v5; // esi
  int v6; // edi
  int v7; // eax
  CBaseEntity *m_pVehicle; // esi
  CBaseEntity *v9; // esi
  char pAttachmentName[32]; // [esp+18h] [ebp-38h] BYREF
  QAngle vecAngles; // [esp+38h] [ebp-18h] BYREF
  Vector vecOrigin; // [esp+44h] [ebp-Ch] BYREF

  v5 = (CBaseAnimating *)__RTDynamicCast(
                           inptr: this->m_pVehicle,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CBaseAnimating `RTTI Type Descriptor',
                           isReference: 0);
  if ( v5 != nullptr
    && (V_snprintf(pDest: pAttachmentName, maxLen: 32, pFormat: "vehicle_feet_passenger%d", nRole),
        v6 = CBaseAnimating::LookupAttachment(this: v5, szName: pAttachmentName),
        v7 = CBaseAnimating::SelectWeightedSequence(this: v5, activity: ACT_IDLE),
        v6 > 0)
    && v7 != -1
    && CBaseServerVehicle::GetLocalAttachmentAtTime(
         this,
         nQuerySequence: v7,
         nAttachmentIndex: v6,
         flCyclePoint: 0.0,
         vecOriginOut: &vecOrigin,
         vecAnglesOut: &vecAngles) != 0 )
  {
    UTIL_ParentToWorldSpace(pEntity: v5, vecPosition: &vecOrigin, &vecAngles);
    if ( pPoint != nullptr )
      *pPoint = vecOrigin;
    if ( pAngles != nullptr )
      *pAngles = vecAngles;
  }
  else
  {
    if ( pPoint != nullptr )
    {
      m_pVehicle = this->m_pVehicle;
      if ( (m_pVehicle->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: this->m_pVehicle);
      *pPoint = m_pVehicle->m_vecAbsOrigin;
    }
    if ( pAngles != nullptr )
    {
      v9 = this->m_pVehicle;
      if ( (v9->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: this->m_pVehicle);
      *pAngles = v9->m_angAbsRotation;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10259A90
// Name: public: void CBaseServerVehicle::ParseExitAnim(class KeyValues __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::ParseExitAnim(CBaseServerVehicle *this, KeyValues *pkvExitList, bool bEscapeExit)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBaseServerVehicle::exitanim_t *m_pMemory; // ecx
  int v7; // eax
  int v8; // edi
  CBaseServerVehicle::exitanim_t *v9; // ebx
  const char *Name; // eax
  const char *String; // eax
  KeyValues *pkvExitAnim; // [esp+Ch] [ebp+8h]

  for ( pkvExitAnim = KeyValues::GetFirstSubKey(this: pkvExitList);
        pkvExitAnim != nullptr;
        pkvExitAnim = KeyValues::GetNextKey(this: pkvExitAnim) )
  {
    m_Size = this->m_ExitAnimations.m_Size;
    m_nAllocationCount = this->m_ExitAnimations.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CBaseServerVehicle::exitanim_t,int>::Grow(
        this: &this->m_ExitAnimations.m_Memory,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ExitAnimations.m_Size;
    m_pMemory = this->m_ExitAnimations.m_Memory.m_pMemory;
    v7 = this->m_ExitAnimations.m_Size - m_Size - 1;
    this->m_ExitAnimations.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 156 * v7);
    v8 = m_Size;
    v9 = &this->m_ExitAnimations.m_Memory.m_pMemory[v8];
    Name = KeyValues::GetName(this: pkvExitAnim);
    V_strncpy(pDest: v9->szAnimName, pSrc: Name, maxLen: 128);
    this->m_ExitAnimations.m_Memory.m_pMemory[v8].bEscapeExit = bEscapeExit;
    String = KeyValues::GetString(this: pkvExitAnim, keyName: nullptr, defaultValue: locale);
    this->m_ExitAnimations.m_Memory.m_pMemory[v8].bUpright = V_strncmp(s1: String, s2: "upsidedown", count: 10) != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10259B80
// Name: private: void CBaseServerVehicle::ParseNPCPassengerSeat(class KeyValues __near *,class CPassengerSeat __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::ParseNPCPassengerSeat(
        CBaseServerVehicle *this,
        KeyValues *pSetKeyValues,
        CPassengerSeat *pSeat)
{
  KeyValues *v3; // ebx
  CBaseAnimating *m_pVehicle; // esi
  const char *String; // edi
  int v6; // eax
  CPassengerSeat *v7; // esi
  KeyValues *FirstSubKey; // edi
  const char *Name; // ebx
  int v10; // ebx
  int v11; // eax
  CPassengerSeatTransition *v12; // ecx
  int v13; // eax
  int v14; // ebx
  CPassengerSeatTransition *v15; // eax
  CPassengerSeatTransition *v16; // esi
  const char *p_pSetKeyValues; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CPassengerSeatTransition *m_pMemory; // ecx
  int v21; // eax
  CPassengerSeatTransition *v22; // eax
  char v23; // [esp+Ch] [ebp-4h] BYREF

  v3 = pSetKeyValues;
  m_pVehicle = (CBaseAnimating *)this->m_pVehicle;
  String = KeyValues::GetString(this: pSetKeyValues, keyName: "target_attachment", defaultValue: locale);
  v6 = CBaseAnimating::LookupAttachment(this: m_pVehicle, szName: String);
  v7 = pSeat;
  pSeat->m_nAttachmentID = v6;
  v7->m_strSeatName.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&pSetKeyValues).pszValue;
  FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      if ( _V_stricmp(s1: Name, s2: "entry") == 0 )
        break;
      if ( _V_stricmp(s1: Name, s2: "exit") == 0 )
      {
        m_Size = v7->m_ExitTransitions.m_Size;
        m_nAllocationCount = v7->m_ExitTransitions.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
            this: (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)&v7->m_ExitTransitions,
            num: m_Size - m_nAllocationCount + 1);
        ++v7->m_ExitTransitions.m_Size;
        m_pMemory = v7->m_ExitTransitions.m_Memory.m_pMemory;
        v21 = v7->m_ExitTransitions.m_Size - m_Size - 1;
        v7->m_ExitTransitions.m_pElements = m_pMemory;
        if ( v21 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v21);
        v14 = m_Size;
        v22 = &v7->m_ExitTransitions.m_Memory.m_pMemory[v14];
        if ( v22 != nullptr )
        {
          v22->m_strAnimationName.pszValue = nullptr;
          v22->m_nPriority = -1;
        }
        v16 = v7->m_ExitTransitions.m_Memory.m_pMemory;
        KeyValues::GetString(this: FirstSubKey, keyName: "animation", defaultValue: locale);
        p_pSetKeyValues = &v23;
        goto LABEL_18;
      }
LABEL_19:
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
        goto LABEL_20;
    }
    v10 = v7->m_EntryTransitions.m_Size;
    v11 = v7->m_EntryTransitions.m_Memory.m_nAllocationCount;
    if ( v10 + 1 > v11 )
      CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
        this: (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)&v7->m_EntryTransitions,
        num: v10 - v11 + 1);
    ++v7->m_EntryTransitions.m_Size;
    v12 = v7->m_EntryTransitions.m_Memory.m_pMemory;
    v13 = v7->m_EntryTransitions.m_Size - v10 - 1;
    v7->m_EntryTransitions.m_pElements = v12;
    if ( v13 > 0 )
      _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 8 * v13);
    v14 = v10;
    v15 = &v7->m_EntryTransitions.m_Memory.m_pMemory[v14];
    if ( v15 != nullptr )
    {
      v15->m_strAnimationName.pszValue = nullptr;
      v15->m_nPriority = -1;
    }
    v16 = v7->m_EntryTransitions.m_Memory.m_pMemory;
    KeyValues::GetString(this: FirstSubKey, keyName: "animation", defaultValue: locale);
    p_pSetKeyValues = (const char *)&pSetKeyValues;
LABEL_18:
    v16[v14].m_strAnimationName.pszValue = *(const char **)AllocPooledString(pszValue: p_pSetKeyValues).pszValue;
    v16[v14].m_nPriority = KeyValues::GetInt(this: FirstSubKey, keyName: "priority", defaultValue: 0);
    v7 = pSeat;
    goto LABEL_19;
  }
LABEL_20:
  CUtlVector<CPassengerSeatTransition,CUtlMemory<CPassengerSeatTransition,int>>::Sort(
    this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&v7->m_EntryTransitions,
    pfnCompare: (int (__cdecl *)(const AI_NamespaceAddInfo_t *, const AI_NamespaceAddInfo_t *))SeatPrioritySort);
  CUtlVector<CPassengerSeatTransition,CUtlMemory<CPassengerSeatTransition,int>>::Sort(
    this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&v7->m_ExitTransitions,
    pfnCompare: (int (__cdecl *)(const AI_NamespaceAddInfo_t *, const AI_NamespaceAddInfo_t *))SeatPrioritySort);
}

//------------------------------------------------------------------------------
// Address: 0x10259D50
// Name: public: virtual void CVehicleSoundsParser::ParseKeyValue(void __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleSoundsParser::ParseKeyValue(
        CVehicleSoundsParser *this,
        char *pData,
        const char *pKey,
        const char *pValue)
{
  const char *v4; // edi
  char *v6; // edi
  int v7; // eax
  int v8; // ecx
  char *v9; // edi
  int v10; // eax
  int v11; // esi
  int v12; // esi
  bool v13; // sf
  const char *v14; // ebx
  int v15; // edi
  char *v16; // eax
  int v17; // edx
  long double v18; // st7
  int v19; // esi
  int v20; // esi
  int v21; // esi
  int v22; // esi
  int v23; // esi
  string_t v24; // eax

  v4 = pKey;
  if ( _V_stricmp(s1: pKey, s2: "gear") == 0 )
  {
    v6 = pData;
    v7 = CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>::InsertBefore(
           this: (CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *)(pData + 4),
           elem: *((_DWORD *)pData + 4));
    v8 = 2 * v7;
    *(_DWORD *)(*((_DWORD *)v6 + 1) + 8 * v8 + 8) = 0;
    *(_DWORD *)(*((_DWORD *)v6 + 1) + 8 * v8 + 12) = 1065353216;
    if ( v7 != 0 )
    {
      *(float *)(*((_DWORD *)v6 + 1) + 16 * v7 + 4) = *(float *)(*((_DWORD *)v6 + 1) + 16 * v7 - 8);
      this->m_iCurrentGear = v7;
    }
    else
    {
      *(_DWORD *)(*((_DWORD *)v6 + 1) + 4) = 0;
      this->m_iCurrentGear = 0;
    }
    return;
  }
  if ( _V_stricmp(s1: v4, s2: "state") == 0 )
  {
    this->m_iCurrentState = 0;
    return;
  }
  if ( _V_stricmp(s1: v4, s2: "crashsound") == 0 )
  {
    v9 = pData;
    v10 = CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>::InsertBefore(
            this: (CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *)(pData + 24),
            elem: *((_DWORD *)pData + 9));
    this->m_iCurrentCrashSound = v10;
    *(_DWORD *)(*((_DWORD *)v9 + 6) + 20 * v10 + 4) = 0;
    *(_DWORD *)(*((_DWORD *)v9 + 6) + 20 * this->m_iCurrentCrashSound + 8) = 0;
    *(_DWORD *)(*((_DWORD *)v9 + 6) + 20 * this->m_iCurrentCrashSound + 16) = 0;
    return;
  }
  if ( this->m_iCurrentGear >= 0 )
  {
    if ( _V_stricmp(s1: v4, s2: "max_speed") == 0 )
    {
      v11 = *((_DWORD *)pData + 1) + 16 * this->m_iCurrentGear;
      *(float *)(v11 + 8) = atof(nptr: pValue);
      return;
    }
    if ( _V_stricmp(s1: v4, s2: "speed_approach_factor") == 0 )
    {
      v12 = *((_DWORD *)pData + 1) + 16 * this->m_iCurrentGear;
      *(float *)(v12 + 12) = atof(nptr: pValue);
      return;
    }
  }
  v13 = this->m_iCurrentState < 0;
  this->m_iCurrentGear = -1;
  if ( !v13 )
  {
    if ( _V_stricmp(s1: v4, s2: "name") == 0 )
    {
      v14 = pValue;
      v15 = 0;
      while ( _V_stricmp(s1: pSoundStateNames[v15], s2: v14) != 0 )
      {
        if ( ++v15 >= 20 )
        {
          v15 = -1;
          break;
        }
      }
      v16 = pData;
      this->m_iCurrentState = v15;
      *(_DWORD *)&v16[4 * v15 + 80] = 0;
      *(_DWORD *)&v16[4 * this->m_iCurrentState + 160] = 0;
      return;
    }
    if ( _V_stricmp(s1: v4, s2: "sound") == 0 )
    {
      v17 = *(_DWORD *)AllocPooledString(pszValue: (const char *)&pValue).pszValue;
      *(_DWORD *)&pData[4 * this->m_iCurrentState + 80] = v17;
      return;
    }
    if ( _V_stricmp(s1: v4, s2: "min_time") == 0 )
    {
      v18 = atof(nptr: pValue);
      *(float *)&pData[4 * this->m_iCurrentState + 160] = v18;
      return;
    }
  }
  v13 = this->m_iCurrentCrashSound < 0;
  this->m_iCurrentState = -1;
  if ( v13 )
    goto LABEL_34;
  if ( _V_stricmp(s1: v4, s2: "min_speed") == 0 )
  {
    v19 = *((_DWORD *)pData + 6) + 20 * this->m_iCurrentCrashSound;
    *(float *)(v19 + 4) = atof(nptr: pValue);
    return;
  }
  if ( _V_stricmp(s1: v4, s2: "sound") == 0 )
  {
    v20 = *((_DWORD *)pData + 6) + 20 * this->m_iCurrentCrashSound;
    *(_DWORD *)(v20 + 16) = *(_DWORD *)AllocPooledString(pszValue: (const char *)&pData).pszValue;
    return;
  }
  if ( _V_stricmp(s1: v4, s2: "min_speed_change") == 0 )
  {
    v21 = *((_DWORD *)pData + 6) + 20 * this->m_iCurrentCrashSound;
    *(float *)(v21 + 8) = atof(nptr: pValue);
    return;
  }
  if ( _V_stricmp(s1: v4, s2: "gear_limit") != 0 )
  {
LABEL_34:
    this->m_iCurrentCrashSound = -1;
    v23 = 0;
    while ( _V_stricmp(s1: v4, s2: vehiclesound_parsenames[v23]) != 0 )
    {
      if ( ++v23 >= 9 )
        return;
    }
    v24.pszValue = AllocPooledString(pszValue: (const char *)&pValue).pszValue;
    *(_DWORD *)&pData[4 * v23 + 44] = *(_DWORD *)v24.pszValue;
  }
  else
  {
    v22 = *((_DWORD *)pData + 6) + 20 * this->m_iCurrentCrashSound;
    *(_DWORD *)(v22 + 12) = atoi(nptr: pValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025A0C0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct vehicle_gear_t,class CUtlMemory<struct vehicle_gear_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &vehicle_gear_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>::InsertMultipleBefore(this: pField, elem: 0, num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025A180
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct vehicle_crashsound_t,class CUtlMemory<struct vehicle_crashsound_t,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &vehicle_crashsound_t::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>::InsertMultipleBefore(
    this: pField,
    elem: 0,
    num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025A240
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<class CPassengerInfo,class CUtlMemory<class CPassengerInfo,int>>,10>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int>>,10>::Restore(
        CUtlVectorDataOps<CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int> > *pField; // ebx
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // edi
  typedescription_t dataDesc; // [esp+Ch] [ebp-54h] BYREF
  datamap_t dataMap; // [esp+48h] [ebp-18h] BYREF
  int nElems; // [esp+68h] [ebp+8h]

  pField = (CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int> > *)fieldInfo->pField;
  dataMap.dataDesc = &dataDesc;
  ReadInt = pRestore->ReadInt;
  v5 = 0;
  dataDesc.fieldType = FIELD_EMBEDDED;
  dataDesc.fieldName = "elems";
  dataDesc.fieldOffset = 0;
  *(_DWORD *)&dataDesc.fieldSize = 131073;
  memset(&dataDesc.externalName, 0, 12);
  dataDesc.td = &CPassengerInfo::m_DataMap;
  dataDesc.fieldSizeInBytes = -1;
  memset(&dataDesc.override_field, 0, 24);
  dataMap.dataNumFields = 1;
  dataMap.dataClassName = "uv";
  memset(&dataMap.baseMap, 0, 12);
  nElems = ReadInt(this: pRestore);
  pField->m_Size = 0;
  CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int>>::InsertMultipleBefore(this: pField, elem: 0, num: nElems);
  dataDesc.fieldSizeInBytes = 0;
  if ( nElems > 0 )
  {
    do
    {
      pRestore->ReadAll(this: pRestore, a2: &pField->m_Memory.m_pMemory[v5++], a3: &dataMap);
      --nElems;
    }
    while ( nElems != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025ACA0
// Name: public: virtual void CBaseServerVehicle::PlaySound(enum vehiclesound)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::PlaySound(CBaseServerVehicle *this, vehiclesound iSound)
{
  CBaseEntity *m_pVehicle; // esi
  const Vector *v4; // eax
  const char *pszValue; // eax
  CBaseEntity *v6; // eax
  edict_t *m_pPev; // eax
  signed int v8; // eax
  EmitSound_t ep; // [esp+14h] [ebp-78h] BYREF
  CPASAttenuationFilter filter; // [esp+5Ch] [ebp-30h] BYREF
  float attenuation[3]; // [esp+7Ch] [ebp-10h] BYREF
  const Vector *origin; // [esp+88h] [ebp-4h]
  int savedregs; // [esp+8Ch] [ebp+0h] BYREF

  if ( this->m_vehicleSounds.iszSound[iSound].pszValue != nullptr )
  {
    m_pVehicle = this->m_pVehicle;
    origin = (const Vector *)((int (__thiscall *)(CBaseEntity *))m_pVehicle->GetSoundEmissionOrigin)(a1: m_pVehicle);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v4 = (const Vector *)((int (__thiscall *)(CBaseEntity *, float *, int))m_pVehicle->GetSoundEmissionOrigin)(
                           a1: m_pVehicle,
                           a2: attenuation,
                           a3: 1061997773);
    CPASAttenuationFilter::Filter(
      this: &filter,
      a2: (int)&savedregs,
      origin: v4,
      attenuation: COERCE_FLOAT(attenuation));
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_nSoundEntryVersion = 1;
    pszValue = this->m_vehicleSounds.iszSound[iSound].pszValue;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    memset(&ep.m_pOrigin, 0, 12);
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_hSoundScriptHandle = -1;
    ep.m_nChannel = 2;
    ep.m_pSoundName = pszValue;
    if ( pszValue == nullptr )
      ep.m_pSoundName = locale;
    v6 = this->m_pVehicle;
    ep.m_flVolume = this->m_flVehicleVolume;
    ep.m_SoundLevel = SNDLVL_NORM;
    m_pPev = v6->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      v8 = m_pPev - gpGlobals->pEdicts;
    else
      v8 = 0;
    CBaseEntity::EmitSound(&filter, iEntIndex: v8, params: &ep);
    if ( g_debug_vehiclesound.m_pParent != nullptr && g_debug_vehiclesound.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "Playing vehicle sound: %s\n", ep.m_pSoundName);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025AF90
// Name: protected: class CPassengerRole __near * CBaseServerVehicle::FindOrCreatePassengerRole(struct string_t,int __near *)
// Source: json
//------------------------------------------------------------------------------
CPassengerRole *__thiscall CBaseServerVehicle::FindOrCreatePassengerRole(
        CBaseServerVehicle *this,
        string_t strName,
        int *nIndex)
{
  int v4; // edi
  int v5; // ebx
  const char *pszValue; // ecx
  const char *v7; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CPassengerRole *m_pMemory; // ecx
  int v11; // eax
  int v12; // ecx
  CPassengerRole *v13; // eax

  v4 = 0;
  if ( this->m_PassengerRoles.m_Size <= 0 )
  {
LABEL_10:
    m_Size = this->m_PassengerRoles.m_Size;
    m_nAllocationCount = this->m_PassengerRoles.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<bbox_t,int>::Grow(
        this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_PassengerRoles,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_PassengerRoles.m_Size;
    m_pMemory = this->m_PassengerRoles.m_Memory.m_pMemory;
    v11 = this->m_PassengerRoles.m_Size - m_Size - 1;
    this->m_PassengerRoles.m_pElements = m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v11);
    v12 = m_Size;
    v13 = &this->m_PassengerRoles.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
    {
      v13->m_strName.pszValue = nullptr;
      v13->m_PassengerSeats.m_Memory.m_pMemory = nullptr;
      v13->m_PassengerSeats.m_Memory.m_nAllocationCount = 0;
      v13->m_PassengerSeats.m_Memory.m_nGrowSize = 0;
      v13->m_PassengerSeats.m_Size = 0;
      v13->m_PassengerSeats.m_pElements = nullptr;
    }
    this->m_PassengerRoles.m_Memory.m_pMemory[v12].m_strName = strName;
    if ( nIndex != nullptr )
      *nIndex = m_Size;
    return &this->m_PassengerRoles.m_Memory.m_pMemory[v12];
  }
  else
  {
    v5 = 0;
    while ( 1 )
    {
      pszValue = strName.pszValue;
      if ( strName.pszValue == nullptr )
        pszValue = locale;
      v7 = this->m_PassengerRoles.m_Memory.m_pMemory[v5].m_strName.pszValue;
      if ( v7 == nullptr )
        v7 = locale;
      if ( v7 == pszValue || _V_stricmp(s1: v7, s2: pszValue) == 0 )
        break;
      ++v4;
      ++v5;
      if ( v4 >= this->m_PassengerRoles.m_Size )
        goto LABEL_10;
    }
    if ( nIndex != nullptr )
      *nIndex = v4;
    return &this->m_PassengerRoles.m_Memory.m_pMemory[v4];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025B090
// Name: private: void CBaseServerVehicle::ParseNPCRoles(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::ParseNPCRoles(CBaseServerVehicle *this, KeyValues *pkvPassengerList)
{
  CBaseAnimating *v3; // eax
  CBaseAnimating *v4; // esi
  CStudioHdr *m_pStudioHdr; // esi
  KeyValues *FirstSubKey; // esi
  CPassengerRole *v7; // eax
  CUtlVector<CPassengerSeat,CUtlMemory<CPassengerSeat,int> > *p_m_PassengerSeats; // ebx
  int v9; // eax
  CPassengerSeat *m_pMemory; // edx
  int v11; // eax
  int v12; // esi
  KeyValues *v13; // esi
  char *v14; // eax
  int v15; // ecx
  const char *v16; // eax
  char *v17; // eax
  bool v18; // cc
  int v19; // eax
  int v20; // esi
  CPassengerSeat *v21; // eax
  CPassengerSeatTransition *v22; // edx
  const char *pszValue; // ecx
  int v24; // eax
  int v25; // eax
  const char *v26; // ecx
  CPassengerRole *v27; // ecx
  int ia; // [esp+8h] [ebp-10h]
  int i; // [esp+8h] [ebp-10h]
  int j; // [esp+Ch] [ebp-Ch] BYREF
  int v31; // [esp+10h] [ebp-8h]
  int nExits; // [esp+14h] [ebp-4h] BYREF
  KeyValues *pkvPassengerKey; // [esp+20h] [ebp+8h]
  KeyValues *pkvPassengerKeya; // [esp+20h] [ebp+8h]

  if ( pkvPassengerList != nullptr )
  {
    v3 = (CBaseAnimating *)__RTDynamicCast(
                             inptr: this->m_pVehicle,
                             VfDelta: 0,
                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                             TargetType: &CBaseAnimating `RTTI Type Descriptor',
                             isReference: 0);
    v4 = v3;
    if ( v3 != nullptr )
    {
      if ( v3->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: v3) != nullptr )
        CBaseAnimating::LockStudioHdr(this: v4);
      m_pStudioHdr = v4->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
      {
        FirstSubKey = KeyValues::GetFirstSubKey(this: pkvPassengerList);
        pkvPassengerKey = FirstSubKey;
        while ( FirstSubKey != nullptr )
        {
          KeyValues::GetName(this: FirstSubKey);
          AllocPooledString(pszValue: (const char *)&nExits);
          v7 = CBaseServerVehicle::FindOrCreatePassengerRole(this, strName: (string_t)nExits, nIndex: &j);
          if ( v7 != nullptr )
          {
            p_m_PassengerSeats = &v7->m_PassengerSeats;
            v9 = CUtlVector<CPassengerSeat,CUtlMemory<CPassengerSeat,int>>::InsertBefore(
                   this: &v7->m_PassengerSeats,
                   elem: v7->m_PassengerSeats.m_Size);
            m_pMemory = p_m_PassengerSeats->m_Memory.m_pMemory;
            ia = v9;
            v31 = 48 * v9;
            CBaseServerVehicle::ParseNPCPassengerSeat(this, pSetKeyValues: FirstSubKey, pSeat: &m_pMemory[v9]);
            v11 = CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int>>::InsertBefore(
                    this: &this->m_PassengerInfo,
                    elem: this->m_PassengerInfo.m_Size);
            v12 = v31;
            v11 *= 20;
            *(unsigned int *)((char *)&this->m_PassengerInfo.m_Memory.m_pMemory->m_hPassenger.m_Index + v11) = -1;
            *(int *)((char *)&this->m_PassengerInfo.m_Memory.m_pMemory->m_nSeat + v11) = ia;
            *(int *)((char *)&this->m_PassengerInfo.m_Memory.m_pMemory->m_nRole + v11) = j;
            *(const char **)((char *)&this->m_PassengerInfo.m_Memory.m_pMemory->m_strRoleName.pszValue + v11) = (const char *)nExits;
            *(const char **)((char *)&this->m_PassengerInfo.m_Memory.m_pMemory->m_strSeatName.pszValue + v11) = *(const char **)((char *)&p_m_PassengerSeats->m_Memory.m_pMemory->m_strSeatName.pszValue + v12);
            pkvPassengerKey = KeyValues::GetNextKey(this: pkvPassengerKey);
            FirstSubKey = pkvPassengerKey;
          }
        }
        if ( g_debug_npc_vehicle_roles.m_pParent != nullptr
          && g_debug_npc_vehicle_roles.m_pParent->m_Value.m_nValue != 0 )
        {
          _Msg(a1: "Passenger Roles Parsed:\t%d\n\n", this->m_PassengerRoles.m_Size);
          v13 = nullptr;
          i = 0;
          if ( this->m_PassengerRoles.m_Size > 0 )
          {
            pkvPassengerKeya = nullptr;
            do
            {
              v14 = (char *)v13 + (unsigned int)this->m_PassengerRoles.m_Memory.m_pMemory;
              v15 = *((_DWORD *)v14 + 4);
              v16 = *(const char **)v14;
              if ( v16 == nullptr )
                v16 = locale;
              _Msg(a1: "\tPassenger Role:\t%s (%d seats)\n", v16, v15);
              v17 = (char *)v13 + (unsigned int)this->m_PassengerRoles.m_Memory.m_pMemory;
              v18 = *((_DWORD *)v17 + 4) <= 0;
              j = 0;
              if ( !v18 )
              {
                v19 = *((_DWORD *)v17 + 1);
                v20 = 0;
                while ( 1 )
                {
                  _Msg(a1: "\t\tAttachment: %d\n", *(_DWORD *)(v20 + v19 + 4));
                  _Msg(
                    a1: "\t\tEntries:\t%d\n",
                    *(_DWORD *)&(*(char **)((char *)&pkvPassengerKeya->m_sValue
                                          + (unsigned int)this->m_PassengerRoles.m_Memory.m_pMemory))[v20 + 20]);
                  _Msg(a1: "\t\t=====================\n");
                  v21 = (CPassengerSeat *)&(*(char **)((char *)&pkvPassengerKeya->m_sValue
                                                     + (unsigned int)this->m_PassengerRoles.m_Memory.m_pMemory))[v20];
                  v18 = v21->m_EntryTransitions.m_Size <= 0;
                  nExits = 0;
                  if ( !v18 )
                  {
                    do
                    {
                      v22 = v21->m_EntryTransitions.m_Memory.m_pMemory;
                      pszValue = v22[nExits].m_strAnimationName.pszValue;
                      if ( pszValue == nullptr )
                        pszValue = locale;
                      _Msg(a1: "\t\t\tAnimation:\t%s\t(Priority %d)\n", pszValue, v22[nExits].m_nPriority);
                      v21 = (CPassengerSeat *)&(*(char **)((char *)&pkvPassengerKeya->m_sValue
                                                         + (unsigned int)this->m_PassengerRoles.m_Memory.m_pMemory))[v20];
                      ++nExits;
                    }
                    while ( nExits < v21->m_EntryTransitions.m_Size );
                  }
                  _Msg(a1: "\n");
                  _Msg(
                    a1: "\t\tExits:\t%d\n",
                    *(_DWORD *)&(*(char **)((char *)&pkvPassengerKeya->m_sValue
                                          + (unsigned int)this->m_PassengerRoles.m_Memory.m_pMemory))[v20 + 40]);
                  _Msg(a1: "\t\t=====================\n");
                  v24 = *(int *)((char *)&pkvPassengerKeya->m_sValue
                               + (unsigned int)this->m_PassengerRoles.m_Memory.m_pMemory);
                  v18 = *(_DWORD *)(v24 + v20 + 40) <= 0;
                  nExits = 0;
                  v31 = v24;
                  if ( !v18 )
                  {
                    do
                    {
                      v25 = *(_DWORD *)(v24 + v20 + 28) + 8 * nExits;
                      v26 = *(const char **)v25;
                      if ( *(_DWORD *)v25 == 0 )
                        v26 = locale;
                      _Msg(a1: "\t\t\tAnimation:\t%s\t(Priority %d)\n", v26, *(_DWORD *)(v25 + 4));
                      v24 = *(int *)((char *)&pkvPassengerKeya->m_sValue
                                   + (unsigned int)this->m_PassengerRoles.m_Memory.m_pMemory);
                      ++nExits;
                      v31 = v24;
                    }
                    while ( nExits < *(_DWORD *)(v24 + v20 + 40) );
                  }
                  v27 = this->m_PassengerRoles.m_Memory.m_pMemory;
                  v20 += 48;
                  if ( ++j >= *(int *)((char *)&v27->m_PassengerSeats.m_Size + (_DWORD)pkvPassengerKeya) )
                    break;
                  v19 = v31;
                }
                v13 = pkvPassengerKeya;
              }
              _Msg(a1: "\n");
              v13 = (KeyValues *)((char *)v13 + 24);
              ++i;
              pkvPassengerKeya = v13;
            }
            while ( i < this->m_PassengerRoles.m_Size );
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025B3A0
// Name: public: virtual void CBaseServerVehicle::ParseEntryExitAnims(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::ParseEntryExitAnims(CBaseServerVehicle *this)
{
  KeyValues *v1; // eax
  KeyValues *v2; // esi
  IVModelInfo_vtbl *v3; // edi
  IVModelInfo_vtbl *v4; // ebx
  int v5; // eax
  CBaseServerVehicle *v6; // edi
  model_t *v7; // eax
  const char *v8; // eax
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // ebx
  CUtlMemory<ikcontextikrule_t,int> *p_m_EntryAnimations; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ikcontextikrule_t *m_pMemory; // ecx
  int v15; // eax
  int v16; // edi
  const char *Name; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  int v21; // [esp-14h] [ebp-2Ch]
  const char *Model; // [esp-10h] [ebp-28h]
  ikcontextikrule_t *v23; // [esp+Ch] [ebp-Ch]
  ikcontextikrule_t *v24; // [esp+Ch] [ebp-Ch]
  KeyValues *modelKeyValues; // [esp+14h] [ebp-4h]

  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
  {
    v2 = KeyValues::KeyValues(this: v1, setName: locale);
    modelKeyValues = v2;
  }
  else
  {
    modelKeyValues = nullptr;
    v2 = nullptr;
  }
  v3 = modelinfo->__vftable;
  v4 = modelinfo->__vftable;
  Model = (const char *)CBaseEntity::GetModel(this: this->m_pVehicle);
  v5 = ((int (__thiscall *)(IVModelInfo *))v3->GetModelKeyValueText)(a1: modelinfo);
  v6 = this;
  v21 = v5;
  v7 = CBaseEntity::GetModel(this: this->m_pVehicle);
  v8 = (const char *)((int (__thiscall *)(IVModelInfo *, model_t *, int))v4->GetModelName)(
                       a1: modelinfo,
                       a2: v7,
                       a3: v21);
  if ( KeyValues::LoadFromBuffer(
         this: v2,
         resourceName: v8,
         pBuffer: Model,
         pFileSystem: nullptr,
         pPathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    Key = KeyValues::FindKey(this: v2, keyName: "vehicle_entry", bCreate: false);
    if ( Key != nullptr )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
      if ( FirstSubKey != nullptr )
      {
        p_m_EntryAnimations = (CUtlMemory<ikcontextikrule_t,int> *)&this->m_EntryAnimations;
        do
        {
          m_Size = this->m_EntryAnimations.m_Size;
          m_nAllocationCount = this->m_EntryAnimations.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ikcontextikrule_t,int>::Grow(this: p_m_EntryAnimations, num: m_Size - m_nAllocationCount + 1);
          ++this->m_EntryAnimations.m_Size;
          m_pMemory = p_m_EntryAnimations->m_pMemory;
          v15 = this->m_EntryAnimations.m_Size - m_Size - 1;
          this->m_EntryAnimations.m_pElements = this->m_EntryAnimations.m_Memory.m_pMemory;
          if ( v15 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 132 * v15);
          v16 = m_Size;
          v23 = &p_m_EntryAnimations->m_pMemory[v16];
          Name = KeyValues::GetName(this: FirstSubKey);
          V_strncpy(pDest: (char *)&v23->type, pSrc: Name, maxLen: 128);
          v24 = &p_m_EntryAnimations->m_pMemory[v16];
          v24->index = KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        }
        while ( FirstSubKey != nullptr );
        v2 = modelKeyValues;
        v6 = this;
      }
    }
    v18 = KeyValues::FindKey(this: v2, keyName: "vehicle_exit", bCreate: false);
    if ( v18 != nullptr )
      CBaseServerVehicle::ParseExitAnim(this: v6, pkvExitList: v18, bEscapeExit: false);
    v19 = KeyValues::FindKey(this: v2, keyName: "vehicle_escape_exit", bCreate: false);
    if ( v19 != nullptr )
      CBaseServerVehicle::ParseExitAnim(this: v6, pkvExitList: v19, bEscapeExit: true);
    v20 = KeyValues::FindKey(this: v2, keyName: "vehicle_npc_passengers", bCreate: false);
    if ( v20 != nullptr )
      CBaseServerVehicle::ParseNPCRoles(this: v6, pkvPassengerList: v20);
  }
  KeyValues::deleteThis(this: v2);
  CBaseServerVehicle::CacheEntryExitPoints(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1025B5C0
// Name: public: CBaseServerVehicle::CBaseServerVehicle(void)
// Source: json
//------------------------------------------------------------------------------
CBaseServerVehicle *__thiscall CBaseServerVehicle::CBaseServerVehicle(CBaseServerVehicle *this)
{
  this->__vftable = (CBaseServerVehicle_vtbl *)&CBaseServerVehicle::`vftable';
  this->m_PassengerInfo.m_Memory.m_pMemory = nullptr;
  this->m_PassengerInfo.m_Memory.m_nAllocationCount = 0;
  this->m_PassengerInfo.m_Memory.m_nGrowSize = 0;
  this->m_PassengerInfo.m_Size = 0;
  this->m_PassengerInfo.m_pElements = nullptr;
  this->m_PassengerRoles.m_Memory.m_pMemory = nullptr;
  this->m_PassengerRoles.m_Memory.m_nAllocationCount = 0;
  this->m_PassengerRoles.m_Memory.m_nGrowSize = 0;
  this->m_PassengerRoles.m_Size = 0;
  this->m_PassengerRoles.m_pElements = nullptr;
  this->m_EntryAnimations.m_Memory.m_pMemory = nullptr;
  this->m_EntryAnimations.m_Memory.m_nAllocationCount = 0;
  this->m_EntryAnimations.m_Memory.m_nGrowSize = 0;
  this->m_EntryAnimations.m_Size = 0;
  this->m_EntryAnimations.m_pElements = nullptr;
  this->m_ExitAnimations.m_Memory.m_pMemory = nullptr;
  this->m_ExitAnimations.m_Memory.m_nAllocationCount = 0;
  this->m_ExitAnimations.m_Memory.m_nGrowSize = 0;
  this->m_ExitAnimations.m_Size = 0;
  this->m_ExitAnimations.m_pElements = nullptr;
  this->m_hExitBlocker.m_Index = -1;
  this->m_vehicleSounds.__vftable = (vehiclesounds_t_vtbl *)&vehiclesounds_t::`vftable';
  this->m_vehicleSounds.pGears.m_Memory.m_pMemory = nullptr;
  this->m_vehicleSounds.pGears.m_Memory.m_nAllocationCount = 0;
  this->m_vehicleSounds.pGears.m_Memory.m_nGrowSize = 0;
  this->m_vehicleSounds.pGears.m_Size = 0;
  this->m_vehicleSounds.pGears.m_pElements = nullptr;
  this->m_vehicleSounds.crashSounds.m_Memory.m_pMemory = nullptr;
  this->m_vehicleSounds.crashSounds.m_Memory.m_nAllocationCount = 0;
  this->m_vehicleSounds.crashSounds.m_Memory.m_nGrowSize = 0;
  this->m_vehicleSounds.crashSounds.m_Size = 0;
  this->m_vehicleSounds.crashSounds.m_pElements = nullptr;
  this->m_pVehicle = nullptr;
  this->m_pDrivableVehicle = nullptr;
  this->m_nNPCButtons = 0;
  this->m_nPrevNPCButtons = 0;
  this->m_flTurnDegrees = 0.0;
  this->m_bParsedAnimations = false;
  this->m_iCurrentExitAnim = 0;
  this->m_vecCurrentExitEndPoint = vec3_origin;
  this->m_flVehicleVolume = 0.5;
  this->m_iSoundGear = 0;
  this->m_pStateSound = nullptr;
  this->m_pStateSoundFade = nullptr;
  this->m_soundState = SS_NONE;
  this->m_flSpeedPercentage = 0.0;
  this->m_bUseLegacyExitChecks = false;
  vehiclesounds_t::Init(this: &this->m_vehicleSounds);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1025B6E0
// Name: public: CBaseServerVehicle::~CBaseServerVehicle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServerVehicle::~CBaseServerVehicle(CBaseServerVehicle *this)
{
  this->__vftable = (CBaseServerVehicle_vtbl *)&CBaseServerVehicle::`vftable';
  CBaseServerVehicle::SoundShutdown(this, flFadeTime: 0.0);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_vehicleSounds.crashSounds);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_vehicleSounds.pGears);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ExitAnimations);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_EntryAnimations);
  CUtlVector<CPassengerRole,CUtlMemory<CPassengerRole,int>>::~CUtlVector<CPassengerRole,CUtlMemory<CPassengerRole,int>>(this: &this->m_PassengerRoles);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_PassengerInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1040C690
// Name: vehicle_gear_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vehicle_gear_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vehicle_gear_t>();
  vehicle_gear_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C6A0
// Name: vehicle_crashsound_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vehicle_crashsound_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vehicle_crashsound_t>();
  vehicle_crashsound_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C6B0
// Name: vehiclesounds_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vehiclesounds_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vehiclesounds_t>();
  vehiclesounds_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C6C0
// Name: CPassengerInfo_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPassengerInfo_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPassengerInfo>();
  CPassengerInfo_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C6D0
// Name: CBaseServerVehicle_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseServerVehicle_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseServerVehicle>();
  CBaseServerVehicle_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E970
// Name: struct ScriptedNPCInteraction_t __near * Construct<struct ScriptedNPCInteraction_t>(struct ScriptedNPCInteraction_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ScriptedNPCInteraction_t *__cdecl Construct<ScriptedNPCInteraction_t>(ScriptedNPCInteraction_t *pMemory)
{
  ScriptedNPCInteraction_t *result; // eax

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  pMemory->iszInteractionName.pszValue = nullptr;
  pMemory->iFlags = 0;
  pMemory->iTriggerMethod = 0;
  pMemory->iLoopBreakTriggerMethod = 0;
  pMemory->vecRelativeOrigin = vec3_origin;
  pMemory->flDelay = 5.0;
  pMemory->flDistSqr = 36.0;
  pMemory->bValidOnCurrentEnemy = false;
  pMemory->flNextAttemptTime = 0.0;
  pMemory->iszMyWeapon.pszValue = nullptr;
  pMemory->iszTheirWeapon.pszValue = nullptr;
  pMemory->sPhases[0].iszSequence.pszValue = nullptr;
  pMemory->sPhases[0].iActivity = -1;
  pMemory->sPhases[1].iszSequence.pszValue = nullptr;
  pMemory->sPhases[1].iActivity = -1;
  pMemory->sPhases[2].iszSequence.pszValue = nullptr;
  pMemory->sPhases[2].iActivity = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100693D0
// Name: struct datamap_t __near * DataMapInit<class CAI_Navigator>(class CAI_Navigator __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_Navigator>()
{
  if ( (_S2_25 & 1) == 0 )
  {
    _S2_25 |= 1u;
    nameHolder_54.m_pszBase = "CAI_Navigator";
    nameHolder_54.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_54.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_54.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_54.m_Names.m_Size = 0;
    nameHolder_54.m_Names.m_pElements = nullptr;
    nameHolder_54.m_nLenBase = 13;
    atexit(func: DataMapInit_CAI_Navigator__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_Navigator::m_DataMap.baseMap = nullptr;
  CAI_Navigator::m_DataMap.dataNumFields = 19;
  CAI_Navigator::m_DataMap.dataDesc = &dataDesc_52[1];
  return &CAI_Navigator::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100A9A00
// Name: struct datamap_t __near * DataMapInit<class CBaseCombatCharacter>(class CBaseCombatCharacter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseCombatCharacter>()
{
  if ( (_S2_47 & 1) == 0 )
  {
    _S2_47 |= 1u;
    nameHolder_86.m_pszBase = "CBaseCombatCharacter";
    nameHolder_86.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_86.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_86.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_86.m_Names.m_Size = 0;
    nameHolder_86.m_Names.m_pElements = nullptr;
    nameHolder_86.m_nLenBase = 20;
    atexit(func: DataMapInit_CBaseCombatCharacter__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseCombatCharacter::m_DataMap.baseMap = &CBaseFlex::m_DataMap;
  if ( (_S2_47 & 2) == 0 )
  {
    _S2_47 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    dataDesc_83[2].flags = 2;
    dataDesc_83[3].fieldSize = 1;
    dataDesc_83[4].fieldSize = 1;
    *(_QWORD *)dataDesc_83[2].flatOffset = 0;
    dataDesc_83[4].flags = 6;
    *(_QWORD *)dataDesc_83[3].flatOffset = 0;
    dataDesc_83[2].fieldSize = 1;
    dataDesc_83[3].flags = 2;
    dataDesc_83[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_83[1].td = 0;
    *(_QWORD *)&dataDesc_83[1].override_field = 0;
    *(_QWORD *)&dataDesc_83[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_83[1].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_83[4].flatOffset = 0;
    dataDesc_83[1].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_83[1].inputFunc = nullptr;
    dataDesc_83[2].fieldType = FIELD_EHANDLE;
    dataDesc_83[2].fieldName = "m_hLastFogTrigger";
    dataDesc_83[2].fieldOffset = 1808;
    dataDesc_83[2].externalName = nullptr;
    dataDesc_83[2].pSaveRestoreOps = nullptr;
    dataDesc_83[2].inputFunc = nullptr;
    dataDesc_83[2].td = nullptr;
    dataDesc_83[2].fieldSizeInBytes = 4;
    dataDesc_83[2].override_field = nullptr;
    dataDesc_83[2].override_count = 0;
    dataDesc_83[2].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_83[2].flatGroup = 0;
    dataDesc_83[3].fieldType = FIELD_TIME;
    dataDesc_83[3].fieldName = "m_flNextAttack";
    dataDesc_83[3].fieldOffset = 1668;
    dataDesc_83[3].externalName = nullptr;
    dataDesc_83[3].pSaveRestoreOps = nullptr;
    dataDesc_83[3].inputFunc = nullptr;
    dataDesc_83[3].td = nullptr;
    dataDesc_83[3].fieldSizeInBytes = 4;
    dataDesc_83[3].override_field = nullptr;
    dataDesc_83[3].override_count = 0;
    dataDesc_83[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_83[3].flatGroup = 0;
    dataDesc_83[4].fieldType = FIELD_INTEGER;
    dataDesc_83[4].fieldName = "m_eHull";
    dataDesc_83[4].fieldOffset = 1672;
    dataDesc_83[4].externalName = "HullType";
    dataDesc_83[4].pSaveRestoreOps = nullptr;
    dataDesc_83[4].inputFunc = nullptr;
    dataDesc_83[4].td = nullptr;
    dataDesc_83[4].fieldSizeInBytes = 4;
    dataDesc_83[4].override_field = nullptr;
    dataDesc_83[4].override_count = 0;
    dataDesc_83[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_83[4].flatGroup = 0;
    dataDesc_83[5].fieldType = FIELD_INTEGER;
    dataDesc_83[5].fieldName = "m_bloodColor";
    dataDesc_83[5].fieldOffset = 1676;
    dataDesc_83[5].flags = 6;
    dataDesc_83[5].externalName = "BloodColor";
    dataDesc_83[5].pSaveRestoreOps = nullptr;
    dataDesc_83[5].inputFunc = nullptr;
    dataDesc_83[5].td = nullptr;
    dataDesc_83[5].fieldSizeInBytes = 4;
    dataDesc_83[5].override_field = nullptr;
    dataDesc_83[5].override_count = 0;
    dataDesc_83[5].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_83[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_83[5].flatGroup = 0;
    dataDesc_83[6].fieldType = FIELD_INTEGER;
    dataDesc_83[6].fieldSize = 1;
    dataDesc_83[6].flags = 2;
    dataDesc_83[7].fieldSize = 1;
    dataDesc_83[7].flags = 2;
    dataDesc_83[8].fieldSize = 1;
    dataDesc_83[8].flags = 2;
    dataDesc_83[9].fieldType = FIELD_STRING;
    dataDesc_83[9].fieldSize = 1;
    *(_QWORD *)dataDesc_83[6].flatOffset = 0;
    dataDesc_83[9].flags = 6;
    *(_QWORD *)dataDesc_83[7].flatOffset = 0;
    dataDesc_83[10].fieldSize = 1;
    *(_QWORD *)dataDesc_83[8].flatOffset = 0;
    dataDesc_83[6].fieldName = "m_iDamageCount";
    dataDesc_83[6].fieldOffset = 1756;
    dataDesc_83[6].externalName = nullptr;
    dataDesc_83[6].pSaveRestoreOps = nullptr;
    dataDesc_83[6].inputFunc = nullptr;
    dataDesc_83[6].td = nullptr;
    dataDesc_83[6].fieldSizeInBytes = 4;
    dataDesc_83[6].override_field = nullptr;
    dataDesc_83[6].override_count = 0;
    dataDesc_83[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_83[6].flatGroup = 0;
    dataDesc_83[7].fieldType = FIELD_FLOAT;
    dataDesc_83[7].fieldName = "m_flFieldOfView";
    dataDesc_83[7].fieldOffset = 1680;
    dataDesc_83[7].externalName = nullptr;
    dataDesc_83[7].pSaveRestoreOps = nullptr;
    dataDesc_83[7].inputFunc = nullptr;
    dataDesc_83[7].td = nullptr;
    dataDesc_83[7].fieldSizeInBytes = 4;
    dataDesc_83[7].override_field = nullptr;
    dataDesc_83[7].override_count = 0;
    dataDesc_83[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_83[7].flatGroup = 0;
    dataDesc_83[8].fieldType = FIELD_VECTOR;
    dataDesc_83[8].fieldName = "m_HackedGunPos";
    dataDesc_83[8].fieldOffset = 1684;
    dataDesc_83[8].externalName = nullptr;
    dataDesc_83[8].pSaveRestoreOps = nullptr;
    dataDesc_83[8].inputFunc = nullptr;
    dataDesc_83[8].td = nullptr;
    dataDesc_83[8].fieldSizeInBytes = 12;
    dataDesc_83[8].override_field = nullptr;
    dataDesc_83[8].override_count = 0;
    dataDesc_83[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_83[8].flatGroup = 0;
    dataDesc_83[9].fieldName = "m_RelationshipString";
    dataDesc_83[9].fieldOffset = 1696;
    dataDesc_83[9].externalName = "Relationship";
    dataDesc_83[9].pSaveRestoreOps = nullptr;
    dataDesc_83[9].inputFunc = nullptr;
    dataDesc_83[9].td = nullptr;
    dataDesc_83[9].fieldSizeInBytes = 4;
    dataDesc_83[9].override_field = nullptr;
    dataDesc_83[9].override_count = 0;
    dataDesc_83[9].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_83[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_83[9].flatGroup = 0;
    dataDesc_83[10].fieldType = FIELD_INTEGER;
    dataDesc_83[10].fieldName = "m_LastHitGroup";
    dataDesc_83[10].fieldOffset = 1748;
    dataDesc_83[10].flags = 2;
    dataDesc_83[10].externalName = nullptr;
    dataDesc_83[10].pSaveRestoreOps = nullptr;
    dataDesc_83[10].inputFunc = nullptr;
    dataDesc_83[11].fieldSize = 1;
    dataDesc_83[11].flags = 2;
    dataDesc_83[12].fieldSize = 1;
    dataDesc_83[12].flags = 14;
    dataDesc_83[13].fieldSize = 1;
    *(_QWORD *)dataDesc_83[10].flatOffset = 0;
    dataDesc_83[13].flags = 2;
    *(_QWORD *)dataDesc_83[11].flatOffset = 0;
    dataDesc_83[14].fieldSize = 1;
    *(_QWORD *)&dataDesc_83[12].override_field = 0;
    *(_QWORD *)&dataDesc_83[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_83[12].flatOffset[1] = 0;
    dataDesc_83[10].td = nullptr;
    dataDesc_83[10].fieldSizeInBytes = 4;
    dataDesc_83[10].override_field = nullptr;
    dataDesc_83[10].override_count = 0;
    dataDesc_83[10].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_83[10].flatGroup = 0;
    dataDesc_83[11].fieldType = FIELD_FLOAT;
    dataDesc_83[11].fieldName = "m_flDamageAccumulator";
    dataDesc_83[11].fieldOffset = 1752;
    dataDesc_83[11].externalName = nullptr;
    dataDesc_83[11].pSaveRestoreOps = nullptr;
    dataDesc_83[11].inputFunc = nullptr;
    dataDesc_83[11].td = nullptr;
    dataDesc_83[11].fieldSizeInBytes = 4;
    dataDesc_83[11].override_field = nullptr;
    dataDesc_83[11].override_count = 0;
    dataDesc_83[11].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_83[11].flatGroup = 0;
    dataDesc_83[12].fieldType = FIELD_FLOAT;
    dataDesc_83[12].fieldName = "m_impactEnergyScale";
    dataDesc_83[12].fieldOffset = 1700;
    dataDesc_83[12].externalName = "physdamagescale";
    dataDesc_83[12].pSaveRestoreOps = nullptr;
    dataDesc_83[12].inputFunc = nullptr;
    dataDesc_83[12].td = nullptr;
    dataDesc_83[12].fieldSizeInBytes = 4;
    dataDesc_83[13].fieldType = FIELD_INTEGER;
    dataDesc_83[13].fieldName = "m_CurrentWeaponProficiency";
    dataDesc_83[13].fieldOffset = 1760;
    dataDesc_83[13].externalName = nullptr;
    dataDesc_83[13].pSaveRestoreOps = nullptr;
    dataDesc_83[13].inputFunc = nullptr;
    dataDesc_83[13].td = nullptr;
    dataDesc_83[13].fieldSizeInBytes = 4;
    dataDesc_83[13].override_field = nullptr;
    dataDesc_83[13].override_count = 0;
    dataDesc_83[13].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_83[13].flatOffset = 0;
    *(_DWORD *)&dataDesc_83[13].flatGroup = 0;
    dataDesc_83[14].fieldType = FIELD_CUSTOM;
    dataDesc_83[14].fieldName = "m_Relationship";
    dataDesc_83[14].fieldOffset = 1764;
    dataDesc_83[14].flags = 2;
    dataDesc_83[14].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int>>,10>::`vftable';
    }
    *(_QWORD *)&dataDesc_83[14].td = 0;
    *(_QWORD *)&dataDesc_83[14].override_field = 0;
    *(_QWORD *)&dataDesc_83[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_83[14].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_83[15].flatOffset = 0;
    *(_QWORD *)dataDesc_83[16].flatOffset = 0;
    dataDesc_83[15].fieldType = FIELD_INTEGER;
    dataDesc_83[15].fieldSize = 1;
    dataDesc_83[15].fieldSizeInBytes = 4;
    dataDesc_83[16].fieldType = FIELD_INTEGER;
    dataDesc_83[18].fieldSizeInBytes = 4;
    *(_QWORD *)dataDesc_83[17].flatOffset = 0;
    dataDesc_83[14].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int>>>'::`2'::ops;
    dataDesc_83[14].inputFunc = nullptr;
    dataDesc_83[15].fieldName = "m_nFaction";
    dataDesc_83[15].fieldOffset = 1784;
    dataDesc_83[15].flags = 2;
    dataDesc_83[15].externalName = nullptr;
    dataDesc_83[15].pSaveRestoreOps = nullptr;
    dataDesc_83[15].inputFunc = nullptr;
    dataDesc_83[15].td = nullptr;
    dataDesc_83[15].override_field = nullptr;
    dataDesc_83[15].override_count = 0;
    dataDesc_83[15].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_83[15].flatGroup = 0;
    dataDesc_83[16].fieldName = "m_iAmmo";
    dataDesc_83[16].fieldOffset = 1812;
    *(_DWORD *)&dataDesc_83[16].fieldSize = 131104;
    dataDesc_83[16].externalName = nullptr;
    dataDesc_83[16].pSaveRestoreOps = nullptr;
    dataDesc_83[16].inputFunc = nullptr;
    dataDesc_83[16].td = nullptr;
    dataDesc_83[16].fieldSizeInBytes = 128;
    dataDesc_83[16].override_field = nullptr;
    dataDesc_83[16].override_count = 0;
    dataDesc_83[16].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_83[16].flatGroup = 0;
    dataDesc_83[17].fieldType = FIELD_EHANDLE;
    dataDesc_83[17].fieldName = "m_hMyWeapons";
    dataDesc_83[17].fieldOffset = 1940;
    *(_DWORD *)&dataDesc_83[17].fieldSize = 131136;
    dataDesc_83[17].externalName = nullptr;
    dataDesc_83[17].pSaveRestoreOps = nullptr;
    dataDesc_83[17].inputFunc = nullptr;
    dataDesc_83[17].td = nullptr;
    dataDesc_83[17].fieldSizeInBytes = 256;
    dataDesc_83[17].override_field = nullptr;
    dataDesc_83[17].override_count = 0;
    dataDesc_83[17].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_83[17].flatGroup = 0;
    dataDesc_83[18].fieldType = FIELD_EHANDLE;
    dataDesc_83[18].fieldName = "m_hActiveWeapon";
    dataDesc_83[18].fieldOffset = 2196;
    dataDesc_83[18].fieldSize = 1;
    dataDesc_83[18].flags = 2;
    dataDesc_83[18].externalName = nullptr;
    dataDesc_83[18].pSaveRestoreOps = nullptr;
    dataDesc_83[18].inputFunc = nullptr;
    dataDesc_83[18].td = nullptr;
    dataDesc_83[18].override_field = nullptr;
    dataDesc_83[18].override_count = 0;
    dataDesc_83[18].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_83[18].flatOffset = 0;
    *(_DWORD *)&dataDesc_83[18].flatGroup = 0;
    dataDesc_83[19].fieldType = FIELD_BOOLEAN;
    dataDesc_83[19].fieldName = "m_bForceServerRagdoll";
    dataDesc_83[19].fieldOffset = 1664;
    dataDesc_83[19].fieldSize = 1;
    dataDesc_83[19].flags = 2;
    dataDesc_83[19].externalName = nullptr;
    dataDesc_83[19].pSaveRestoreOps = nullptr;
    dataDesc_83[19].inputFunc = nullptr;
    dataDesc_83[19].fieldTolerance = 0.0;
    dataDesc_83[20].fieldTolerance = 0.0;
    dataDesc_83[20].fieldType = FIELD_BOOLEAN;
    *(_QWORD *)dataDesc_83[20].flatOffset = 0;
    dataDesc_83[19].td = nullptr;
    dataDesc_83[19].fieldSizeInBytes = 1;
    dataDesc_83[19].override_field = nullptr;
    dataDesc_83[19].override_count = 0;
    *(_QWORD *)dataDesc_83[19].flatOffset = 0;
    *(_DWORD *)&dataDesc_83[19].flatGroup = 0;
    dataDesc_83[20].fieldName = "m_bPreventWeaponPickup";
    dataDesc_83[20].fieldOffset = 1665;
    dataDesc_83[20].fieldSize = 1;
    dataDesc_83[20].flags = 2;
    dataDesc_83[20].externalName = nullptr;
    dataDesc_83[20].pSaveRestoreOps = nullptr;
    dataDesc_83[20].inputFunc = nullptr;
    dataDesc_83[20].td = nullptr;
    dataDesc_83[20].fieldSizeInBytes = 1;
    dataDesc_83[20].override_field = nullptr;
    dataDesc_83[20].override_count = 0;
    *(_DWORD *)&dataDesc_83[20].flatGroup = 0;
    dataDesc_83[21].fieldType = FIELD_VOID;
    dataDesc_83[21].fieldName = "InputKilledNPC";
    dataDesc_83[21].fieldOffset = 0;
    *(_DWORD *)&dataDesc_83[21].fieldSize = 524289;
    dataDesc_83[21].externalName = "KilledNPC";
    dataDesc_83[21].pSaveRestoreOps = nullptr;
    dataDesc_83[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseCombatCharacter::InputKilledNPC;
    *(_QWORD *)&dataDesc_83[21].td = 0;
    *(_QWORD *)&dataDesc_83[21].override_field = 0;
    *(_QWORD *)&dataDesc_83[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_83[21].flatOffset[1] = 0;
  }
  CBaseCombatCharacter::m_DataMap.dataNumFields = 21;
  CBaseCombatCharacter::m_DataMap.dataDesc = &dataDesc_83[1];
  return &CBaseCombatCharacter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1012A450
// Name: struct datamap_t __near * DataMapInit<class CFish>(class CFish __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFish>()
{
  if ( (_S2_105 & 1) == 0 )
  {
    _S2_105 |= 1u;
    nameHolder_201.m_pszBase = "CFish";
    nameHolder_201.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_201.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_201.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_201.m_Names.m_Size = 0;
    nameHolder_201.m_Names.m_pElements = nullptr;
    nameHolder_201.m_nLenBase = 5;
    atexit(func: DataMapInit_CFish__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFish::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  CFish::m_DataMap.dataNumFields = 14;
  CFish::m_DataMap.dataDesc = &dataDesc_191[1];
  return &CFish::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1012A4D0
// Name: struct datamap_t __near * DataMapInit<class CFishPool>(class CFishPool __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFishPool>()
{
  if ( (_S4_32 & 1) == 0 )
  {
    _S4_32 |= 1u;
    nameHolder_202.m_pszBase = "CFishPool";
    nameHolder_202.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_202.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_202.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_202.m_Names.m_Size = 0;
    nameHolder_202.m_Names.m_pElements = nullptr;
    nameHolder_202.m_nLenBase = 9;
    atexit(func: DataMapInit_CFishPool__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFishPool::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S4_32 & 2) == 0 )
  {
    _S4_32 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CFish>,CUtlMemory<CHandle<CFish>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CFish>,CUtlMemory<CHandle<CFish>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CFish>,CUtlMemory<CHandle<CFish>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CFish>,CUtlMemory<CHandle<CFish>,int>>,13>::`vftable';
    }
    dataDesc_192[6].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CFish>,CUtlMemory<CHandle<CFish>,int>>>'::`2'::ops;
    dataDesc_192[6].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_192[6].td = 0;
    *(_QWORD *)&dataDesc_192[6].override_field = 0;
    *(_QWORD *)&dataDesc_192[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_192[6].flatOffset[1] = 0;
    dataDesc_192[7].fieldType = FIELD_VOID;
    dataDesc_192[7].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_202,
                                  pszIdentifier: "Update");
    dataDesc_192[7].fieldOffset = 0;
    *(_DWORD *)&dataDesc_192[7].fieldSize = 2097153;
    dataDesc_192[7].externalName = nullptr;
    dataDesc_192[7].pSaveRestoreOps = nullptr;
    dataDesc_192[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFishPool::Update;
    *(_QWORD *)&dataDesc_192[7].td = 0;
    *(_QWORD *)&dataDesc_192[7].override_field = 0;
    *(_QWORD *)&dataDesc_192[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_192[7].flatOffset[1] = 0;
  }
  CFishPool::m_DataMap.dataNumFields = 7;
  CFishPool::m_DataMap.dataDesc = &dataDesc_192[1];
  return &CFishPool::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10159690
// Name: struct datamap_t __near * DataMapInit<class CGlobalState>(class CGlobalState __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGlobalState>()
{
  if ( (_S2_133 & 1) == 0 )
  {
    _S2_133 |= 1u;
    nameHolder_231.m_pszBase = "CGlobalState";
    nameHolder_231.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_231.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_231.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_231.m_Names.m_Size = 0;
    nameHolder_231.m_Names.m_pElements = nullptr;
    nameHolder_231.m_nLenBase = 12;
    atexit(func: DataMapInit_CGlobalState__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGlobalState::m_DataMap.baseMap = nullptr;
  if ( (_S2_133 & 2) == 0 )
  {
    _S2_133 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>,10>::`vftable';
    }
    dataDesc_218[1].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>>'::`2'::ops;
    dataDesc_218[1].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_218[1].td = 0;
    *(_QWORD *)&dataDesc_218[1].override_field = 0;
    *(_QWORD *)&dataDesc_218[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_218[1].flatOffset[1] = 0;
  }
  CGlobalState::m_DataMap.dataNumFields = 1;
  CGlobalState::m_DataMap.dataDesc = &dataDesc_218[1];
  return &CGlobalState::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B2170
// Name: struct datamap_t __near * DataMapInit<class CPhysicsSpring>(class CPhysicsSpring __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysicsSpring>()
{
  ISaveRestoreOps *PhysObjSaveRestoreOps; // eax

  if ( (_S2_170 & 1) == 0 )
  {
    _S2_170 |= 1u;
    nameHolder_316.m_pszBase = "CPhysicsSpring";
    nameHolder_316.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_316.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_316.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_316.m_Names.m_Size = 0;
    nameHolder_316.m_Names.m_pElements = nullptr;
    nameHolder_316.m_nLenBase = 14;
    atexit(func: DataMapInit_CPhysicsSpring__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysicsSpring::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_170 & 2) == 0 )
  {
    _S2_170 |= 2u;
    PhysObjSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSSPRING);
    *(_QWORD *)dataDesc_303[2].flatOffset = 0;
    dataDesc_303[1].pSaveRestoreOps = PhysObjSaveRestoreOps;
    *(_QWORD *)dataDesc_303[3].flatOffset = 0;
    dataDesc_303[2].fieldSize = 1;
    *(_QWORD *)&dataDesc_303[1].td = 0;
    *(_QWORD *)&dataDesc_303[1].override_field = 0;
    *(_QWORD *)&dataDesc_303[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_303[1].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_303[4].flatOffset = 0;
    dataDesc_303[1].inputFunc = nullptr;
    dataDesc_303[2].fieldType = FIELD_FLOAT;
    dataDesc_303[2].fieldName = "m_tempConstant";
    dataDesc_303[2].fieldOffset = 860;
    dataDesc_303[2].flags = 6;
    dataDesc_303[2].externalName = "constant";
    dataDesc_303[2].pSaveRestoreOps = nullptr;
    dataDesc_303[2].inputFunc = nullptr;
    dataDesc_303[2].td = nullptr;
    dataDesc_303[2].fieldSizeInBytes = 4;
    dataDesc_303[2].override_field = nullptr;
    dataDesc_303[2].override_count = 0;
    dataDesc_303[2].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_303[2].flatGroup = 0;
    dataDesc_303[3].fieldType = FIELD_FLOAT;
    dataDesc_303[3].fieldName = "m_tempLength";
    dataDesc_303[3].fieldOffset = 864;
    dataDesc_303[3].fieldSize = 1;
    dataDesc_303[3].flags = 6;
    dataDesc_303[3].externalName = "length";
    dataDesc_303[3].pSaveRestoreOps = nullptr;
    dataDesc_303[3].inputFunc = nullptr;
    dataDesc_303[3].td = nullptr;
    dataDesc_303[3].fieldSizeInBytes = 4;
    dataDesc_303[3].override_field = nullptr;
    dataDesc_303[3].override_count = 0;
    dataDesc_303[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_303[3].flatGroup = 0;
    dataDesc_303[4].fieldType = FIELD_FLOAT;
    dataDesc_303[4].fieldName = "m_tempDamping";
    dataDesc_303[4].fieldOffset = 868;
    dataDesc_303[4].fieldSize = 1;
    dataDesc_303[4].flags = 6;
    dataDesc_303[4].externalName = "damping";
    dataDesc_303[4].pSaveRestoreOps = nullptr;
    dataDesc_303[4].inputFunc = nullptr;
    dataDesc_303[4].td = nullptr;
    dataDesc_303[4].fieldSizeInBytes = 4;
    dataDesc_303[4].override_field = nullptr;
    dataDesc_303[4].override_count = 0;
    dataDesc_303[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_303[4].flatGroup = 0;
    dataDesc_303[5].fieldType = FIELD_FLOAT;
    dataDesc_303[5].fieldName = "m_tempRelativeDamping";
    dataDesc_303[5].fieldOffset = 872;
    dataDesc_303[5].fieldSize = 1;
    dataDesc_303[5].flags = 6;
    dataDesc_303[5].externalName = "relativedamping";
    dataDesc_303[5].pSaveRestoreOps = nullptr;
    dataDesc_303[5].inputFunc = nullptr;
    dataDesc_303[5].td = nullptr;
    dataDesc_303[5].fieldSizeInBytes = 4;
    dataDesc_303[5].override_field = nullptr;
    dataDesc_303[5].override_count = 0;
    dataDesc_303[5].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_303[5].flatOffset = 0;
    dataDesc_303[6].fieldSizeInBytes = 4;
    dataDesc_303[7].fieldSizeInBytes = 4;
    *(_QWORD *)dataDesc_303[6].flatOffset = 0;
    dataDesc_303[6].flags = 6;
    dataDesc_303[7].flags = 6;
    dataDesc_303[8].flags = 2;
    *(_QWORD *)dataDesc_303[7].flatOffset = 0;
    dataDesc_303[6].fieldSize = 1;
    dataDesc_303[7].fieldSize = 1;
    dataDesc_303[8].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_303[8].fieldSize = 1;
    dataDesc_303[8].fieldSizeInBytes = 12;
    dataDesc_303[9].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_303[9].fieldSizeInBytes = 12;
    *(_QWORD *)dataDesc_303[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_303[5].flatGroup = 0;
    dataDesc_303[6].fieldType = FIELD_STRING;
    dataDesc_303[6].fieldName = "m_nameAttachStart";
    dataDesc_303[6].fieldOffset = 876;
    dataDesc_303[6].externalName = "attach1";
    dataDesc_303[6].pSaveRestoreOps = nullptr;
    dataDesc_303[6].inputFunc = nullptr;
    dataDesc_303[6].td = nullptr;
    dataDesc_303[6].override_field = nullptr;
    dataDesc_303[6].override_count = 0;
    dataDesc_303[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_303[6].flatGroup = 0;
    dataDesc_303[7].fieldType = FIELD_STRING;
    dataDesc_303[7].fieldName = "m_nameAttachEnd";
    dataDesc_303[7].fieldOffset = 880;
    dataDesc_303[7].externalName = "attach2";
    dataDesc_303[7].pSaveRestoreOps = nullptr;
    dataDesc_303[7].inputFunc = nullptr;
    dataDesc_303[7].td = nullptr;
    dataDesc_303[7].override_field = nullptr;
    dataDesc_303[7].override_count = 0;
    dataDesc_303[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_303[7].flatGroup = 0;
    dataDesc_303[8].fieldName = "m_start";
    dataDesc_303[8].fieldOffset = 884;
    dataDesc_303[8].externalName = nullptr;
    dataDesc_303[8].pSaveRestoreOps = nullptr;
    dataDesc_303[8].inputFunc = nullptr;
    dataDesc_303[8].td = nullptr;
    dataDesc_303[8].override_field = nullptr;
    dataDesc_303[8].override_count = 0;
    dataDesc_303[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_303[8].flatGroup = 0;
    dataDesc_303[9].fieldName = "m_end";
    dataDesc_303[9].fieldOffset = 896;
    dataDesc_303[9].fieldSize = 1;
    dataDesc_303[9].flags = 6;
    dataDesc_303[9].externalName = "springaxis";
    dataDesc_303[9].pSaveRestoreOps = nullptr;
    dataDesc_303[9].inputFunc = nullptr;
    dataDesc_303[9].td = nullptr;
    dataDesc_303[9].override_field = nullptr;
    dataDesc_303[9].override_count = 0;
    dataDesc_303[9].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_303[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_303[9].flatGroup = 0;
    dataDesc_303[10].fieldType = FIELD_BOOLEAN;
    dataDesc_303[10].fieldName = "m_isLocal";
    dataDesc_303[10].fieldOffset = 856;
    dataDesc_303[10].fieldSize = 1;
    dataDesc_303[10].flags = 2;
    dataDesc_303[10].externalName = nullptr;
    dataDesc_303[10].pSaveRestoreOps = nullptr;
    dataDesc_303[10].inputFunc = nullptr;
    dataDesc_303[10].td = nullptr;
    dataDesc_303[10].fieldSizeInBytes = 1;
    dataDesc_303[10].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_303[10].flatOffset = 0;
    *(_QWORD *)&dataDesc_303[11].td = 0;
    *(_QWORD *)&dataDesc_303[11].override_field = 0;
    *(_QWORD *)&dataDesc_303[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_303[11].flatOffset[1] = 0;
    dataDesc_303[11].fieldSize = 1;
    *(_QWORD *)&dataDesc_303[12].td = 0;
    *(_QWORD *)&dataDesc_303[12].override_field = 0;
    *(_QWORD *)&dataDesc_303[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_303[12].flatOffset[1] = 0;
    dataDesc_303[10].override_field = nullptr;
    dataDesc_303[10].override_count = 0;
    *(_DWORD *)&dataDesc_303[10].flatGroup = 0;
    dataDesc_303[11].fieldType = FIELD_FLOAT;
    dataDesc_303[11].fieldName = "InputSetSpringConstant";
    dataDesc_303[11].fieldOffset = 0;
    dataDesc_303[11].flags = 8;
    dataDesc_303[11].externalName = "SetSpringConstant";
    dataDesc_303[11].pSaveRestoreOps = nullptr;
    dataDesc_303[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysicsSpring::InputSetSpringConstant;
    dataDesc_303[12].fieldType = FIELD_FLOAT;
    dataDesc_303[12].fieldName = "InputSetSpringLength";
    dataDesc_303[12].fieldOffset = 0;
    dataDesc_303[12].fieldSize = 1;
    dataDesc_303[12].flags = 8;
    dataDesc_303[12].externalName = "SetSpringLength";
    dataDesc_303[12].pSaveRestoreOps = nullptr;
    dataDesc_303[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysicsSpring::InputSetSpringLength;
    dataDesc_303[13].fieldType = FIELD_FLOAT;
    dataDesc_303[13].fieldName = "InputSetSpringDamping";
    dataDesc_303[13].fieldOffset = 0;
    *(_DWORD *)&dataDesc_303[13].fieldSize = 524289;
    dataDesc_303[13].externalName = "SetSpringDamping";
    dataDesc_303[13].pSaveRestoreOps = nullptr;
    dataDesc_303[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysicsSpring::InputSetSpringDamping;
    *(_QWORD *)&dataDesc_303[13].td = 0;
    *(_QWORD *)&dataDesc_303[13].override_field = 0;
    *(_QWORD *)&dataDesc_303[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_303[13].flatOffset[1] = 0;
  }
  CPhysicsSpring::m_DataMap.dataNumFields = 13;
  CPhysicsSpring::m_DataMap.dataDesc = &dataDesc_303[1];
  return &CPhysicsSpring::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B2770
// Name: struct datamap_t __near * DataMapInit<class CPhysBox>(class CPhysBox __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysBox>()
{
  char *Name; // eax

  if ( (_S4_46 & 1) == 0 )
  {
    _S4_46 |= 1u;
    nameHolder_317.m_pszBase = "CPhysBox";
    nameHolder_317.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_317.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_317.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_317.m_Names.m_Size = 0;
    nameHolder_317.m_Names.m_pElements = nullptr;
    nameHolder_317.m_nLenBase = 8;
    atexit(func: DataMapInit_CPhysBox__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysBox::m_DataMap.baseMap = &CBreakable::m_DataMap;
  if ( (_S4_46 & 2) == 0 )
  {
    _S4_46 |= 2u;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_317, pszIdentifier: "BreakTouch");
    dataDesc_304[20].fieldSize = 1;
    dataDesc_304[21].fieldSize = 1;
    dataDesc_304[21].flags = 22;
    dataDesc_304[19].fieldName = Name;
    *(_QWORD *)&dataDesc_304[19].td = 0;
    *(_QWORD *)&dataDesc_304[19].override_field = 0;
    *(_QWORD *)&dataDesc_304[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_304[19].flatOffset[1] = 0;
    dataDesc_304[22].fieldSize = 1;
    *(_QWORD *)&dataDesc_304[20].inputFunc = 0;
    *(_QWORD *)&dataDesc_304[20].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_304[20].override_count = 0;
    *(_QWORD *)dataDesc_304[20].flatOffset = 0;
    dataDesc_304[19].fieldSize = 1;
    dataDesc_304[22].flags = 22;
    *(_QWORD *)&dataDesc_304[21].inputFunc = 0;
    *(_QWORD *)&dataDesc_304[21].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_304[21].override_count = 0;
    *(_QWORD *)dataDesc_304[21].flatOffset = 0;
    dataDesc_304[19].flags = 32;
    dataDesc_304[20].flags = 22;
    dataDesc_304[23].fieldSize = 1;
    *(_QWORD *)&dataDesc_304[22].inputFunc = 0;
    *(_QWORD *)&dataDesc_304[22].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_304[22].override_count = 0;
    *(_QWORD *)dataDesc_304[22].flatOffset = 0;
    dataDesc_304[19].fieldOffset = 0;
    dataDesc_304[19].externalName = nullptr;
    dataDesc_304[19].pSaveRestoreOps = nullptr;
    dataDesc_304[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBreakable::BreakTouch;
    dataDesc_304[20].fieldType = FIELD_CUSTOM;
    dataDesc_304[20].fieldName = "m_OnDamaged";
    dataDesc_304[20].fieldOffset = 1068;
    dataDesc_304[20].externalName = "OnDamaged";
    dataDesc_304[20].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_304[20].flatGroup = 0;
    dataDesc_304[21].fieldType = FIELD_CUSTOM;
    dataDesc_304[21].fieldName = "m_OnAwakened";
    dataDesc_304[21].fieldOffset = 1092;
    dataDesc_304[21].externalName = "OnAwakened";
    dataDesc_304[21].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_304[21].flatGroup = 0;
    dataDesc_304[22].fieldType = FIELD_CUSTOM;
    dataDesc_304[22].fieldName = "m_OnMotionEnabled";
    dataDesc_304[22].fieldOffset = 1116;
    dataDesc_304[22].externalName = "OnMotionEnabled";
    dataDesc_304[22].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_304[22].flatGroup = 0;
    dataDesc_304[23].fieldType = FIELD_CUSTOM;
    dataDesc_304[23].fieldName = "m_OnPhysGunPickup";
    dataDesc_304[23].fieldOffset = 1140;
    dataDesc_304[23].flags = 22;
    dataDesc_304[23].externalName = "OnPhysGunPickup";
    dataDesc_304[23].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_304[23].inputFunc = 0;
    *(_QWORD *)&dataDesc_304[23].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_304[23].override_count = 0;
    *(_QWORD *)dataDesc_304[23].flatOffset = 0;
    *(_DWORD *)&dataDesc_304[23].flatGroup = 0;
    dataDesc_304[24].fieldType = FIELD_CUSTOM;
    dataDesc_304[24].fieldName = "m_OnPhysGunPunt";
    dataDesc_304[24].fieldSize = 1;
    dataDesc_304[24].flags = 22;
    dataDesc_304[25].fieldSize = 1;
    *(_QWORD *)&dataDesc_304[24].inputFunc = 0;
    *(_QWORD *)&dataDesc_304[24].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_304[24].override_count = 0;
    *(_QWORD *)dataDesc_304[24].flatOffset = 0;
    dataDesc_304[25].flags = 22;
    *(_QWORD *)&dataDesc_304[25].inputFunc = 0;
    *(_QWORD *)&dataDesc_304[25].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_304[25].override_count = 0;
    *(_QWORD *)dataDesc_304[25].flatOffset = 0;
    dataDesc_304[26].fieldSize = 1;
    *(_QWORD *)&dataDesc_304[26].inputFunc = 0;
    *(_QWORD *)&dataDesc_304[26].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_304[26].override_count = 0;
    *(_QWORD *)dataDesc_304[26].flatOffset = 0;
    dataDesc_304[24].fieldOffset = 1164;
    dataDesc_304[24].externalName = "OnPhysGunPunt";
    dataDesc_304[24].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_304[24].flatGroup = 0;
    dataDesc_304[25].fieldType = FIELD_CUSTOM;
    dataDesc_304[25].fieldName = "m_OnPhysGunOnlyPickup";
    dataDesc_304[25].fieldOffset = 1188;
    dataDesc_304[25].externalName = "OnPhysGunOnlyPickup";
    dataDesc_304[25].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_304[25].flatGroup = 0;
    dataDesc_304[26].fieldType = FIELD_CUSTOM;
    dataDesc_304[26].fieldName = "m_OnPhysGunDrop";
    dataDesc_304[26].fieldOffset = 1212;
    dataDesc_304[26].flags = 22;
    dataDesc_304[26].externalName = "OnPhysGunDrop";
    dataDesc_304[26].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_304[26].flatGroup = 0;
    dataDesc_304[27].fieldType = FIELD_CUSTOM;
    dataDesc_304[27].fieldName = "m_OnPlayerUse";
    dataDesc_304[27].fieldOffset = 1236;
    *(_DWORD *)&dataDesc_304[27].fieldSize = 1441793;
    dataDesc_304[27].externalName = "OnPlayerUse";
    dataDesc_304[27].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_304[27].inputFunc = 0;
    *(_QWORD *)&dataDesc_304[27].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_304[27].override_count = 0;
    *(_QWORD *)dataDesc_304[27].flatOffset = 0;
    *(_DWORD *)&dataDesc_304[27].flatGroup = 0;
  }
  CPhysBox::m_DataMap.dataNumFields = 27;
  CPhysBox::m_DataMap.dataDesc = &dataDesc_304[1];
  return &CPhysBox::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B2BB0
// Name: struct datamap_t __near * DataMapInit<class CPhysExplosion>(class CPhysExplosion __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysExplosion>()
{
  if ( (_S5_24 & 1) == 0 )
  {
    _S5_24 |= 1u;
    nameHolder_318.m_pszBase = "CPhysExplosion";
    nameHolder_318.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_318.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_318.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_318.m_Names.m_Size = 0;
    nameHolder_318.m_Names.m_pElements = nullptr;
    nameHolder_318.m_nLenBase = 14;
    atexit(func: DataMapInit_CPhysExplosion__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysExplosion::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S5_24 & 2) == 0 )
  {
    _S5_24 |= 2u;
    dataDesc_305[7].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_305[7].inputFunc = 0;
    *(_QWORD *)&dataDesc_305[7].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_305[7].override_count = 0;
    *(_QWORD *)dataDesc_305[7].flatOffset = 0;
    *(_DWORD *)&dataDesc_305[7].flatGroup = 0;
  }
  CPhysExplosion::m_DataMap.dataNumFields = 7;
  CPhysExplosion::m_DataMap.dataDesc = &dataDesc_305[1];
  return &CPhysExplosion::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B2C80
// Name: struct datamap_t __near * DataMapInit<class CPhysImpact>(class CPhysImpact __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysImpact>()
{
  if ( (_S6_18 & 1) == 0 )
  {
    _S6_18 |= 1u;
    nameHolder_319.m_pszBase = "CPhysImpact";
    nameHolder_319.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_319.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_319.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_319.m_Names.m_Size = 0;
    nameHolder_319.m_Names.m_pElements = nullptr;
    nameHolder_319.m_nLenBase = 11;
    atexit(func: DataMapInit_CPhysImpact__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysImpact::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S6_18 & 2) == 0 )
  {
    _S6_18 |= 2u;
    dataDesc_306[4].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_319,
                                  pszIdentifier: "PointAtEntity");
    *(_QWORD *)&dataDesc_306[4].td = 0;
    *(_QWORD *)&dataDesc_306[4].override_field = 0;
    *(_QWORD *)&dataDesc_306[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_306[4].flatOffset[1] = 0;
    dataDesc_306[4].fieldOffset = 0;
    dataDesc_306[4].fieldSize = 1;
    dataDesc_306[4].flags = 32;
    dataDesc_306[4].externalName = nullptr;
    dataDesc_306[4].pSaveRestoreOps = nullptr;
    dataDesc_306[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysImpact::PointAtEntity;
    dataDesc_306[5].fieldType = FIELD_VOID;
    dataDesc_306[5].fieldName = "InputImpact";
    dataDesc_306[5].fieldOffset = 0;
    *(_DWORD *)&dataDesc_306[5].fieldSize = 524289;
    dataDesc_306[5].externalName = "Impact";
    dataDesc_306[5].pSaveRestoreOps = nullptr;
    dataDesc_306[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysImpact::InputImpact;
    *(_QWORD *)&dataDesc_306[5].td = 0;
    *(_QWORD *)&dataDesc_306[5].override_field = 0;
    *(_QWORD *)&dataDesc_306[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_306[5].flatOffset[1] = 0;
  }
  CPhysImpact::m_DataMap.dataNumFields = 5;
  CPhysImpact::m_DataMap.dataDesc = &dataDesc_306[1];
  return &CPhysImpact::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B2DE0
// Name: struct datamap_t __near * DataMapInit<class CPhysConvert>(class CPhysConvert __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysConvert>()
{
  if ( (_S7_10 & 1) == 0 )
  {
    _S7_10 |= 1u;
    nameHolder_320.m_pszBase = "CPhysConvert";
    nameHolder_320.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_320.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_320.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_320.m_Names.m_Size = 0;
    nameHolder_320.m_Names.m_pElements = nullptr;
    nameHolder_320.m_nLenBase = 12;
    atexit(func: DataMapInit_CPhysConvert__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysConvert::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S7_10 & 2) == 0 )
  {
    _S7_10 |= 2u;
    dataDesc_307[4].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_307[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_307[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_307[4].override_count = 0;
    *(_QWORD *)dataDesc_307[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_307[4].flatGroup = 0;
  }
  CPhysConvert::m_DataMap.dataNumFields = 4;
  CPhysConvert::m_DataMap.dataDesc = &dataDesc_307[1];
  return &CPhysConvert::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040C6E0
// Name: _dynamic_initializer_for__g_debug_npc_vehicle_roles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_npc_vehicle_roles__()
{
  ConVar::ConVar(this: &g_debug_npc_vehicle_roles, pName: "g_debug_npc_vehicle_roles", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_debug_npc_vehicle_roles__);
}
