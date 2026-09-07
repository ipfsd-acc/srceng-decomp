// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/soundenvelope.cpp
// Functions: 80
// ============================================================

#include "game\shared\soundenvelope.h"

//------------------------------------------------------------------------------
// Address: 0x100EEDA0
// Name: public: void CUtlPriorityQueue<class CHudElement __near *,class CDefUtlPriorityQueueLessFunc<class CHudElement __near *>,class CUtlMemory<class CHudElement __near *,int>>::RemoveAt(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CHudElement *,CDefUtlPriorityQueueLessFunc<CHudElement *>,CUtlMemory<CHudElement *,int>>::RemoveAt(
        CUtlPriorityQueue<CHudElement *,CDefUtlPriorityQueueLessFunc<CHudElement *>,CUtlMemory<CHudElement *,int> > *this,
        int index)
{
  int m_Size; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  bool v8; // al
  int v9; // ebx
  bool v10; // al
  CHudElement *v11; // edx
  int half; // [esp+4h] [ebp-8h]
  int count; // [esp+8h] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  v4 = index;
  if ( m_Size > 0 )
  {
    if ( index != m_Size - 1 )
      this->m_heap.m_Memory.m_pMemory[index] = this->m_heap.m_Memory.m_pMemory[m_Size - 1];
    --this->m_heap.m_Size;
  }
  v5 = this->m_heap.m_Size;
  count = v5;
  if ( v5 != 0 )
  {
    half = v5 / 2;
    v6 = index;
    if ( index < v5 / 2 )
    {
      while ( 1 )
      {
        v7 = 2 * v4 + 1;
        if ( v7 < count )
        {
          v8 = this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v4], a2: &this->m_heap.m_Memory.m_pMemory[v7]);
          v4 = index;
          if ( v8 )
            v6 = v7;
        }
        v9 = v7 + 1;
        if ( v9 < count )
        {
          v10 = this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v6], a2: &this->m_heap.m_Memory.m_pMemory[v9]);
          v4 = index;
          if ( v10 )
            v6 = v9;
        }
        if ( v6 == v4 )
          break;
        v11 = this->m_heap.m_Memory.m_pMemory[v4];
        this->m_heap.m_Memory.m_pMemory[v4] = this->m_heap.m_Memory.m_pMemory[v6];
        this->m_heap.m_Memory.m_pMemory[v6] = v11;
        index = v6;
        if ( v6 >= half )
          break;
        v4 = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F17F0
// Name: public: void CUtlPriorityQueue<struct SoundCommand_t __near *,class CDefUtlPriorityQueueLessFunc<struct SoundCommand_t __near *>,class CUtlMemory<struct SoundCommand_t __near *,int>>::Insert(struct SoundCommand_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<SoundCommand_t *,CDefUtlPriorityQueueLessFunc<SoundCommand_t *>,CUtlMemory<SoundCommand_t *,int>>::Insert(
        CUtlPriorityQueue<CHudElement *,CDefUtlPriorityQueueLessFunc<CHudElement *>,CUtlMemory<CHudElement *,int> > *this,
        CHudElement *const *element)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CHudElement **m_pMemory; // ecx
  int v6; // eax
  int v7; // esi
  CHudElement *v8; // ecx

  m_Size = this->m_heap.m_Size;
  m_nAllocationCount = this->m_heap.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_heap.m_Size;
  m_pMemory = this->m_heap.m_Memory.m_pMemory;
  v6 = this->m_heap.m_Size - m_Size - 1;
  this->m_heap.m_pElements = this->m_heap.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  this->m_heap.m_Memory.m_pMemory[m_Size] = *element;
  if ( m_Size != 0 )
  {
    do
    {
      v7 = (m_Size + 1) / 2 - 1;
      if ( this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[m_Size], a2: &this->m_heap.m_Memory.m_pMemory[v7]) )
        break;
      v8 = this->m_heap.m_Memory.m_pMemory[v7];
      this->m_heap.m_Memory.m_pMemory[v7] = this->m_heap.m_Memory.m_pMemory[m_Size];
      this->m_heap.m_Memory.m_pMemory[m_Size] = v8;
      m_Size = (m_Size + 1) / 2 - 1;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10144260
// Name: protected: void CUtlPriorityQueue<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,class CDefUtlPriorityQueueLessFunc<struct CPhysSaveRestoreBlockHandler::QueuedItem_t>,class CUtlMemory<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Swap(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Swap(
        CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> > *this,
        int index1,
        int index2)
{
  CPhysSaveRestoreBlockHandler::QueuedItem_t *v3; // eax
  PhysInterfaceId_t type; // ebx
  __int64 v5; // xmm0_8
  CPhysSaveRestoreBlockHandler::QueuedItem_t *v6; // eax
  unsigned int tmp_4; // [esp+Ch] [ebp-34h]
  const char *tmp_8; // [esp+10h] [ebp-30h]
  int tmp_12; // [esp+14h] [ebp-2Ch]
  const char *tmp_16; // [esp+18h] [ebp-28h]
  __int64 tmp_20; // [esp+1Ch] [ebp-24h]
  __int64 tmp_28; // [esp+24h] [ebp-1Ch]
  float tmp_44; // [esp+34h] [ebp-Ch]
  int tmp_48; // [esp+38h] [ebp-8h]
  void **tmp_52; // [esp+3Ch] [ebp-4h]

  v3 = &this->m_heap.m_Memory.m_pMemory[index1];
  type = v3->header.type;
  tmp_4 = v3->header.hEntity.m_Index;
  tmp_8 = v3->header.fieldName;
  tmp_12 = v3->header.nObjects;
  tmp_16 = v3->header.modelName;
  tmp_44 = v3->header.sphere.radius;
  tmp_48 = v3->header.iCollide;
  tmp_52 = v3->ppPhysObj;
  tmp_20 = *(_QWORD *)&v3->header.bbox.mins.x;
  tmp_28 = *(_QWORD *)&v3->header.bbox.mins.z;
  v5 = *(_QWORD *)&v3->header.bbox.maxs.y;
  *v3 = this->m_heap.m_Memory.m_pMemory[index2];
  v6 = &this->m_heap.m_Memory.m_pMemory[index2];
  v6->header.hEntity.m_Index = tmp_4;
  v6->header.fieldName = tmp_8;
  v6->header.type = type;
  v6->header.nObjects = tmp_12;
  v6->header.modelName = tmp_16;
  *(_QWORD *)&v6->header.bbox.mins.x = tmp_20;
  *(_QWORD *)&v6->header.bbox.mins.z = tmp_28;
  *(_QWORD *)&v6->header.bbox.maxs.y = v5;
  v6->header.sphere.radius = tmp_44;
  v6->header.iCollide = tmp_48;
  v6->ppPhysObj = tmp_52;
}

//------------------------------------------------------------------------------
// Address: 0x101449A0
// Name: public: void CUtlPriorityQueue<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,class CDefUtlPriorityQueueLessFunc<struct CPhysSaveRestoreBlockHandler::QueuedItem_t>,class CUtlMemory<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Insert(struct CPhysSaveRestoreBlockHandler::QueuedItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Insert(
        CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> > *this,
        const CPhysSaveRestoreBlockHandler::QueuedItem_t *element)
{
  int v3; // edi
  int v4; // esi

  v3 = CUtlVector<CPhysSaveRestoreBlockHandler::QueuedItem_t,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::InsertBefore(
         this: &this->m_heap,
         elem: this->m_heap.m_Size);
  this->m_heap.m_Memory.m_pMemory[v3] = *element;
  if ( v3 != 0 )
  {
    do
    {
      v4 = (v3 + 1) / 2 - 1;
      if ( this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v3], a2: &this->m_heap.m_Memory.m_pMemory[v4]) )
        break;
      CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Swap(
        this,
        index1: (v3 + 1) / 2 - 1,
        index2: v3);
      v3 = (v3 + 1) / 2 - 1;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101489C0
// Name: public: void CUtlPriorityQueue<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,class CDefUtlPriorityQueueLessFunc<struct CPhysSaveRestoreBlockHandler::QueuedItem_t>,class CUtlMemory<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::RemoveAtHead(
        CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> > *this)
{
  int m_Size; // eax
  int v3; // eax
  int v4; // edi
  int v5; // esi
  int v6; // esi
  int half; // [esp+Ch] [ebp-Ch]
  int count; // [esp+10h] [ebp-8h]
  int index; // [esp+14h] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  if ( m_Size > 0 )
  {
    if ( m_Size != 1 )
      qmemcpy(
        this->m_heap.m_Memory.m_pMemory,
        &this->m_heap.m_Memory.m_pMemory[m_Size - 1],
        sizeof(CPhysSaveRestoreBlockHandler::QueuedItem_t));
    --this->m_heap.m_Size;
  }
  v3 = this->m_heap.m_Size;
  v4 = 0;
  index = 0;
  count = v3;
  if ( v3 != 0 )
  {
    half = v3 / 2;
    if ( v3 / 2 > 0 )
    {
      do
      {
        v5 = 2 * index + 1;
        if ( v5 < count
          && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[index], a2: &this->m_heap.m_Memory.m_pMemory[v5]) )
        {
          v4 = 2 * index + 1;
        }
        v6 = 2 * index + 2;
        if ( v6 < count
          && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v4], a2: &this->m_heap.m_Memory.m_pMemory[v6]) )
        {
          v4 = 2 * index + 2;
        }
        if ( v4 == index )
          break;
        CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Swap(
          this,
          index1: index,
          index2: v4);
        index = v4;
      }
      while ( v4 < half );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168B60
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
// Address: 0x10168F30
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
// Address: 0x10168FF0
// Name: public: virtual void CUtlVectorDataOps<class CUtlVector<struct SaveRestoreBlockHeader_t,class CUtlMemory<struct SaveRestoreBlockHeader_t,int>>,10>::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>,10>::MakeEmpty(
        CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  *((_DWORD *)fieldInfo->pField + 3) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016C8B0
// Name: cl_report_soundpatch
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_report_soundpatch()
{
  _Msg(a1: "Current sound patches: %d\n", CSoundPatch::g_SoundPatchCount);
}

//------------------------------------------------------------------------------
// Address: 0x1016C8D0
// Name: bool SoundCommandLessFunc(struct SoundCommand_t __near * const __near &,struct SoundCommand_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SoundCommandLessFunc(SoundCommand_t *const *lhs, SoundCommand_t *const *rhs)
{
  return (*lhs)->m_time > (*rhs)->m_time;
}

//------------------------------------------------------------------------------
// Address: 0x1016C900
// Name: public: virtual int CSoundControllerImp::SoundGetGuid(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundControllerImp::SoundGetGuid(CSoundControllerImp *this, CSoundPatch *pSound)
{
  return pSound->m_guid;
}

//------------------------------------------------------------------------------
// Address: 0x1016C910
// Name: public: virtual float CSoundControllerImp::SoundGetElapsedTime(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSoundControllerImp::SoundGetElapsedTime(CSoundControllerImp *this, CSoundPatch *pSound)
{
  return ((double (__thiscall *)(IEngineSound *, int))enginesound->GetElapsedTimeByGuid)(
           a1: enginesound,
           a2: pSound->m_guid)
       * 0.01;
}

//------------------------------------------------------------------------------
// Address: 0x1016C940
// Name: public: virtual bool CSoundControllerImp::SoundIsStillPlaying(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSoundControllerImp::SoundIsStillPlaying(CSoundControllerImp *this, CSoundPatch *pSound)
{
  return enginesound->IsSoundStillPlaying(this: enginesound, a2: pSound->m_guid);
}

//------------------------------------------------------------------------------
// Address: 0x1016C960
// Name: public: virtual float CSoundControllerImp::SoundGetPitch(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSoundControllerImp::SoundGetPitch(CSoundControllerImp *this, CSoundPatch *pSound)
{
  return pSound->m_pitch.m_current;
}

//------------------------------------------------------------------------------
// Address: 0x1016C970
// Name: public: virtual float CSoundControllerImp::SoundGetVolume(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSoundControllerImp::SoundGetVolume(CSoundControllerImp *this, CSoundPatch *pSound)
{
  return pSound->m_volume.m_current;
}

//------------------------------------------------------------------------------
// Address: 0x1016C980
// Name: public: virtual float CSoundControllerImp::SoundPlayEnvelope(class CSoundPatch __near *,enum soundcommands_t,struct envelopePoint_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CSoundControllerImp::SoundPlayEnvelope@<st0>(
        CSoundControllerImp *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CSoundPatch *pSound,
        soundcommands_t soundCommand,
        envelopePoint_t *points,
        int numPoints)
{
  int i; // edi
  float amplitudeMin; // xmm0_4
  envelopePoint_t *v10; // esi
  float durationMin; // xmm0_4
  float amplitude; // [esp+30h] [ebp-Ch]
  float duration; // [esp+34h] [ebp-8h]
  float totalDuration; // [esp+38h] [ebp-4h]

  amplitude = 0.0;
  duration = 0.0;
  totalDuration = 0.0;
  ((void (__thiscall *)(CSoundControllerImp *, CSoundPatch *, int, int))this->CommandClear)(
    a1: this,
    a2: pSound,
    a3,
    a4: a2);
  for ( i = 0; i < numPoints; totalDuration = totalDuration + duration )
  {
    amplitudeMin = points[i].amplitudeMin;
    v10 = &points[i];
    if ( amplitudeMin == -1.0 && v10->amplitudeMax == -1.0 )
    {
      if ( i == 0 )
        _Msg(a1: "Invalid starting amplitude value in envelope!  (Cannot be -1)\n");
    }
    else
    {
      amplitude = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                    a1: random,
                    a2: LODWORD(amplitudeMin),
                    a3: LODWORD(v10->amplitudeMax));
    }
    durationMin = v10->durationMin;
    if ( durationMin == -1.0 && v10->durationMax == -1.0 )
    {
      if ( i == 0 )
        _Msg(a1: "Invalid starting duration value in envelope! (Cannot be -1)\n");
    }
    else
    {
      duration = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                   a1: random,
                   a2: LODWORD(durationMin),
                   a3: LODWORD(v10->durationMax));
    }
    ((void (__thiscall *)(CSoundControllerImp *, CSoundPatch *, _DWORD, soundcommands_t, _DWORD, _DWORD))this->CommandAdd)(
      a1: this,
      a2: pSound,
      a3: LODWORD(totalDuration),
      a4: soundCommand,
      a5: LODWORD(duration),
      a6: LODWORD(amplitude));
    ++i;
  }
  return totalDuration;
}

//------------------------------------------------------------------------------
// Address: 0x1016CAE0
// Name: public: virtual float CSoundControllerImp::SoundPlayEnvelope(class CSoundPatch __near *,enum soundcommands_t,struct envelopeDescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CSoundControllerImp::SoundPlayEnvelope(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        soundcommands_t soundCommand,
        envelopeDescription_t *envelope)
{
  return this->SoundPlayEnvelope_2(this, a2: pSound, a3: soundCommand, a4: envelope->pPoints, a5: envelope->nNumPoints);
}

//------------------------------------------------------------------------------
// Address: 0x1016CB10
// Name: public: static class CSoundEnvelopeController __near & CSoundEnvelopeController::GetController(void)
// Source: json
//------------------------------------------------------------------------------
CSoundControllerImp *__cdecl CSoundEnvelopeController::GetController()
{
  return &g_Controller;
}

//------------------------------------------------------------------------------
// Address: 0x1016CB20
// Name: class ISaveRestoreOps __near * GetSoundSaveRestoreOps(void)
// Source: json
//------------------------------------------------------------------------------
CSoundPatchSaveRestoreOps *__cdecl GetSoundSaveRestoreOps()
{
  return &s_SoundPatchSaveRestoreOps;
}

//------------------------------------------------------------------------------
// Address: 0x1016CB60
// Name: public: void CSoundPatch::ChangePitch(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPatch::ChangePitch(CSoundPatch *this, float pitchTarget, float deltaTime)
{
  float v3; // xmm0_4
  float v4; // xmm0_4
  double v5; // xmm1_8

  this->m_flags |= 2u;
  v3 = pitchTarget - this->m_pitch.m_current;
  if ( v3 == 0.0 || deltaTime <= 0.0 )
  {
    if ( pitchTarget != this->m_pitch.m_current )
      this->m_pitch.m_forceupdate = true;
    if ( this->m_pitch.m_target != pitchTarget )
      this->m_pitch.m_forceupdate = true;
    this->m_pitch.m_target = pitchTarget;
    this->m_pitch.m_current = pitchTarget;
    this->m_pitch.m_rate = 0.0;
  }
  else
  {
    this->m_pitch.m_target = pitchTarget;
    v4 = fabs(v3 / deltaTime);
    v5 = 0.1;
    if ( v4 >= 0.1 )
      v5 = v4;
    this->m_pitch.m_rate = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CC00
// Name: public: void CSoundPatch::ChangeVolume(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPatch::ChangeVolume(CSoundPatch *this, float volumeTarget, float deltaTime)
{
  float v3; // xmm1_4
  float m_current; // xmm2_4
  float v5; // xmm0_4
  double v6; // xmm1_8

  v3 = volumeTarget;
  this->m_flags |= 1u;
  if ( volumeTarget > 1.0 )
    v3 = 1.0;
  m_current = this->m_volume.m_current;
  if ( (float)(v3 - m_current) == 0.0 || deltaTime <= 0.0 )
  {
    if ( v3 != m_current )
      this->m_volume.m_forceupdate = true;
    if ( this->m_volume.m_target != v3 )
      this->m_volume.m_forceupdate = true;
    this->m_volume.m_target = v3;
    this->m_volume.m_current = v3;
    this->m_volume.m_rate = 0.0;
  }
  else
  {
    this->m_volume.m_target = v3;
    v5 = fabs((float)(v3 - m_current) / deltaTime);
    v6 = 0.1;
    if ( v5 >= 0.1 )
      v6 = v5;
    this->m_volume.m_rate = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CCB0
// Name: public: virtual void CSoundControllerImp::SoundChangePitch(class CSoundPatch __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SoundChangePitch(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        float pitchTarget,
        float deltaTime)
{
  float v4; // xmm0_4
  float v5; // xmm0_4
  double v6; // xmm1_8

  pSound->m_flags |= 2u;
  v4 = pitchTarget - pSound->m_pitch.m_current;
  if ( v4 == 0.0 || deltaTime <= 0.0 )
  {
    if ( pitchTarget != pSound->m_pitch.m_current )
      pSound->m_pitch.m_forceupdate = true;
    if ( pSound->m_pitch.m_target != pitchTarget )
      pSound->m_pitch.m_forceupdate = true;
    pSound->m_pitch.m_target = pitchTarget;
    pSound->m_pitch.m_current = pitchTarget;
    pSound->m_pitch.m_rate = 0.0;
  }
  else
  {
    pSound->m_pitch.m_target = pitchTarget;
    v5 = fabs(v4 / deltaTime);
    v6 = 0.1;
    if ( v5 >= 0.1 )
      v6 = v5;
    pSound->m_pitch.m_rate = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CD50
// Name: public: virtual void CSoundControllerImp::SoundChangeVolume(class CSoundPatch __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SoundChangeVolume(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        float volumeTarget,
        float deltaTime)
{
  float v4; // xmm1_4
  float m_current; // xmm2_4
  float v6; // xmm0_4
  double v7; // xmm1_8

  v4 = volumeTarget;
  pSound->m_flags |= 1u;
  if ( volumeTarget > 1.0 )
    v4 = 1.0;
  m_current = pSound->m_volume.m_current;
  if ( (float)(v4 - m_current) == 0.0 || deltaTime <= 0.0 )
  {
    if ( v4 != m_current )
      pSound->m_volume.m_forceupdate = true;
    if ( pSound->m_volume.m_target != v4 )
      pSound->m_volume.m_forceupdate = true;
    pSound->m_volume.m_target = v4;
    pSound->m_volume.m_current = v4;
    pSound->m_volume.m_rate = 0.0;
  }
  else
  {
    pSound->m_volume.m_target = v4;
    v6 = fabs((float)(v4 - m_current) / deltaTime);
    v7 = 0.1;
    if ( v6 >= 0.1 )
      v7 = v6;
    pSound->m_volume.m_rate = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CE10
// Name: public: virtual void CSoundControllerImp::SoundFadeOut(class CSoundPatch __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SoundFadeOut(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        float deltaTime,
        bool destroyOnFadeout)
{
  float m_current; // xmm2_4
  float v5; // xmm0_4
  double v6; // xmm2_8

  if ( destroyOnFadeout && deltaTime == 0.0 )
  {
    this->SoundDestroy(this, a2: pSound);
  }
  else
  {
    pSound->m_flags |= 1u;
    m_current = pSound->m_volume.m_current;
    if ( COERCE_FLOAT(LODWORD(m_current) ^ _mask__NegFloat_) == 0.0 || deltaTime <= 0.0 )
    {
      if ( m_current != 0.0 )
        pSound->m_volume.m_forceupdate = true;
      if ( pSound->m_volume.m_target != 0.0 )
        pSound->m_volume.m_forceupdate = true;
      pSound->m_volume.m_target = 0.0;
      pSound->m_volume.m_current = 0.0;
      pSound->m_volume.m_rate = 0.0;
    }
    else
    {
      pSound->m_volume.m_target = 0.0;
      v5 = fabs(COERCE_FLOAT(LODWORD(m_current) ^ _mask__NegFloat_) / deltaTime);
      v6 = 0.1;
      if ( v5 >= 0.1 )
        v6 = v5;
      pSound->m_volume.m_rate = v6;
    }
    if ( destroyOnFadeout )
      ((void (__stdcall *)(CSoundPatch *, _DWORD, int, _DWORD, _DWORD))this->CommandAdd)(
        a1: pSound,
        a2: LODWORD(deltaTime),
        a3: 3,
        a4: 0,
        a5: 0);
    else
      pSound->m_shutdownTime = ((double (__thiscall *)(IEffects *))g_pEffects->Time)(a1: g_pEffects) + deltaTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CF10
// Name: public: int CSoundPatch::EntIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundPatch::EntIndex(CSoundPatch *this)
{
  unsigned int m_Index; // ecx
  int v2; // eax
  CEntInfo *v3; // edx
  unsigned int v4; // ecx
  int v5; // eax
  bool v6; // zf
  CEntInfo *v7; // eax
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hEnt.m_Index;
  if ( m_Index == -1 )
    return -1;
  v2 = (unsigned __int16)m_Index;
  v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v4 = HIWORD(m_Index);
  if ( v3->m_SerialNumber != v4 || v3->m_pEntity == nullptr )
    return -1;
  v5 = v2;
  v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4;
  v7 = &g_pEntityList->m_EntPtrArray[v5];
  if ( v6 )
    m_pEntity = v7->m_pEntity;
  else
    m_pEntity = nullptr;
  return ((int (__thiscall *)(IHandleEntity *))m_pEntity[2].__vftable[3].SetRefEHandle)(a1: &m_pEntity[2]);
}

//------------------------------------------------------------------------------
// Address: 0x1016CF60
// Name: public: void CSoundPatch::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPatch::Shutdown(CSoundPatch *this)
{
  unsigned int m_Index; // ecx
  int m_soundEntityIndex; // eax

  if ( this->m_isPlaying != 0 )
  {
    m_Index = this->m_hEnt.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      m_soundEntityIndex = CSoundPatch::EntIndex(this);
    }
    else
    {
      m_soundEntityIndex = this->m_soundEntityIndex;
    }
    if ( m_soundEntityIndex >= 0 )
    {
      if ( this->m_hSoundScriptHandle > -1 )
      {
        C_BaseEntity::StopSound(iEntIndex: m_soundEntityIndex, soundname: this->m_iszSoundScriptName);
        this->m_isPlaying = 0;
        return;
      }
      C_BaseEntity::StopSound(
        iEntIndex: m_soundEntityIndex,
        iChannel: this->m_entityChannel,
        pSample: this->m_iszSoundName,
        bIsStoppingSpeakerSound: false);
    }
    this->m_isPlaying = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016CFE0
// Name: public: virtual bool CClassPtrSaveRestoreOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClassPtrSaveRestoreOps::IsEmpty(CPhysObjSaveRestoreOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  int v2; // eax

  v2 = 0;
  if ( fieldInfo->pTypeDesc->fieldSize == 0 )
    return 1;
  while ( *((_DWORD *)fieldInfo->pField + v2) == 0 )
  {
    if ( ++v2 >= fieldInfo->pTypeDesc->fieldSize )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016D040
// Name: public: void CUtlPriorityQueue<struct SoundCommand_t __near *,class CDefUtlPriorityQueueLessFunc<struct SoundCommand_t __near *>,class CUtlMemory<struct SoundCommand_t __near *,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<SoundCommand_t *,CDefUtlPriorityQueueLessFunc<SoundCommand_t *>,CUtlMemory<SoundCommand_t *,int>>::RemoveAtHead(
        CUtlPriorityQueue<SoundCommand_t *,CDefUtlPriorityQueueLessFunc<SoundCommand_t *>,CUtlMemory<SoundCommand_t *,int> > *this)
{
  int m_Size; // eax
  int v3; // edi
  int v4; // eax
  int v5; // ebx
  int v6; // ebx
  SoundCommand_t *v7; // ecx
  int half; // [esp+8h] [ebp-Ch]
  int count; // [esp+Ch] [ebp-8h]
  int index; // [esp+10h] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    if ( m_Size != 1 )
      *this->m_heap.m_Memory.m_pMemory = this->m_heap.m_Memory.m_pMemory[m_Size - 1];
    --this->m_heap.m_Size;
  }
  v4 = this->m_heap.m_Size;
  index = 0;
  count = v4;
  if ( v4 != 0 )
  {
    half = v4 / 2;
    if ( v4 / 2 > 0 )
    {
      do
      {
        v5 = 2 * index + 1;
        if ( v5 < count
          && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[index], a2: &this->m_heap.m_Memory.m_pMemory[v5]) )
        {
          v3 = 2 * index + 1;
        }
        v6 = 2 * index + 2;
        if ( v6 < count
          && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v3], a2: &this->m_heap.m_Memory.m_pMemory[v6]) )
        {
          v3 = 2 * index + 2;
        }
        if ( v3 == index )
          break;
        v7 = this->m_heap.m_Memory.m_pMemory[index];
        this->m_heap.m_Memory.m_pMemory[index] = this->m_heap.m_Memory.m_pMemory[v3];
        this->m_heap.m_Memory.m_pMemory[v3] = v7;
        index = v3;
      }
      while ( v3 < half );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D0F0
// Name: public: virtual bool CUtlVectorDataOps<class CUtlVector<struct SaveRestoreBlockHeader_t,class CUtlMemory<struct SaveRestoreBlockHeader_t,int>>,10>::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>,10>::IsEmpty(
        CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> >,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  return *((_DWORD *)fieldInfo->pField + 3) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016D110
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
// Address: 0x1016D1D0
// Name: public: virtual void CSoundControllerImp::CommandClear(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::CommandClear(CSoundControllerImp *this, CSoundPatch *pSound)
{
  int v3; // edi
  SoundCommand_t *v4; // ebx
  int m_Size; // eax
  int v6; // eax
  int v7; // ebx
  int v8; // ebx
  SoundCommand_t **m_pMemory; // eax
  SoundCommand_t *v10; // ecx
  SoundCommand_t *pCmd; // [esp+8h] [ebp-14h]
  int v12; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  v3 = this->m_commandList.m_heap.m_Size - 1;
  for ( i = v3; v3 >= 0; i = v3 )
  {
    v4 = this->m_commandList.m_heap.m_Memory.m_pMemory[v3];
    pCmd = v4;
    if ( v4->m_pPatch == pSound )
    {
      m_Size = this->m_commandList.m_heap.m_Size;
      v15 = v3;
      if ( m_Size > 0 )
      {
        if ( v3 != m_Size - 1 )
          this->m_commandList.m_heap.m_Memory.m_pMemory[v3] = this->m_commandList.m_heap.m_Memory.m_pMemory[m_Size - 1];
        --this->m_commandList.m_heap.m_Size;
      }
      v6 = this->m_commandList.m_heap.m_Size;
      v14 = v6;
      if ( v6 != 0 )
      {
        v12 = v6 / 2;
        if ( v3 < v6 / 2 )
        {
          do
          {
            v7 = 2 * v15 + 1;
            if ( v7 < v14
              && this->m_commandList.m_LessFunc(
                   a1: &this->m_commandList.m_heap.m_Memory.m_pMemory[v15],
                   a2: &this->m_commandList.m_heap.m_Memory.m_pMemory[v7]) )
            {
              v3 = 2 * v15 + 1;
            }
            v8 = 2 * v15 + 2;
            if ( v8 < v14
              && this->m_commandList.m_LessFunc(
                   a1: &this->m_commandList.m_heap.m_Memory.m_pMemory[v3],
                   a2: &this->m_commandList.m_heap.m_Memory.m_pMemory[v8]) )
            {
              v3 = 2 * v15 + 2;
            }
            if ( v3 == v15 )
              break;
            m_pMemory = this->m_commandList.m_heap.m_Memory.m_pMemory;
            v10 = m_pMemory[v15];
            m_pMemory[v15] = m_pMemory[v3];
            this->m_commandList.m_heap.m_Memory.m_pMemory[v3] = v10;
            v15 = v3;
          }
          while ( v3 < v12 );
          v4 = pCmd;
          v3 = i;
        }
      }
      CUtlMemoryPool::Free(this: &SoundCommand_t::s_Allocator, memBlock: v4);
    }
    --v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D2D0
// Name: public: virtual void CSoundPatchSaveRestoreOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSoundPatchSaveRestoreOps::Save(
        CSoundPatchSaveRestoreOps *this@<ecx>,
        ISave **p_pSave@<edi>,
        CSoundPatch **fieldInfo,
        ISave *pSave)
{
  ISave *v4; // esi
  int v5; // eax
  CSoundPatch *v6; // edi
  int v7; // eax
  int i; // ebx
  SoundCommand_t *v9; // edi
  int v11; // [esp+0h] [ebp-10h]
  CSoundPatch *v12; // [esp+8h] [ebp-8h]
  int nSoundPatchCount; // [esp+Ch] [ebp-4h]
  CSoundPatch **ppSoundPatch; // [esp+18h] [ebp+8h]

  v4 = pSave;
  pSave->StartBlock(this: pSave);
  v5 = *(unsigned __int16 *)&fieldInfo[2]->m_pitch.m_forceupdate - 1;
  ppSoundPatch = (CSoundPatch **)*fieldInfo;
  for ( nSoundPatchCount = v5; nSoundPatchCount >= 0; --nSoundPatchCount )
  {
    v6 = *ppSoundPatch;
    v12 = *ppSoundPatch;
    ((void (__thiscall *)(ISave *, ISave **))v4->StartBlock)(a1: v4, a2: p_pSave);
    v4->WriteAll(this: v4, a2: v6, a3: &CSoundPatch::m_DataMap);
    v4->EndBlock(this: v4);
    v7 = g_Controller.m_commandList.m_heap.m_Size - 1;
    for ( pSave = nullptr; v7 >= 0; --v7 )
    {
      if ( g_Controller.m_commandList.m_heap.m_Memory.m_pMemory[v7]->m_pPatch == v6 )
        pSave = (ISave *)((char *)pSave + 1);
    }
    ((void (__thiscall *)(ISave *, int))v4->StartBlock)(a1: v4, a2: v11);
    v11 = 1;
    p_pSave = &pSave;
    ((void (__thiscall *)(ISave *))v4->WriteInt_2)(a1: v4);
    for ( i = g_Controller.m_commandList.m_heap.m_Size - 1; i >= 0; --i )
    {
      v9 = g_Controller.m_commandList.m_heap.m_Memory.m_pMemory[i];
      if ( v9->m_pPatch == v12 )
      {
        v4->StartBlock(this: v4);
        v4->WriteAll(this: v4, a2: v9, a3: &SoundCommand_t::m_DataMap);
        v4->EndBlock(this: v4);
      }
    }
    v4->EndBlock(this: v4);
    ++ppSoundPatch;
  }
  v4->EndBlock(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1016D3E0
// Name: public: virtual bool CCopyRecipientFilter::IsReliable(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCopyRecipientFilter::IsReliable(CCopyRecipientFilter *this)
{
  return (this->m_Flags & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016D3F0
// Name: public: virtual bool CCopyRecipientFilter::IsInitMessage(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCopyRecipientFilter::IsInitMessage(CCopyRecipientFilter *this)
{
  return (this->m_Flags & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016D400
// Name: public: virtual int CCopyRecipientFilter::GetRecipientIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCopyRecipientFilter::GetRecipientIndex(CCopyRecipientFilter *this, int slot)
{
  return this->m_Recipients.m_Memory.m_pMemory[slot];
}

//------------------------------------------------------------------------------
// Address: 0x1016D410
// Name: public: CSoundPatch::CSoundPatch(void)
// Source: json
//------------------------------------------------------------------------------
CSoundPatch *__thiscall CSoundPatch::CSoundPatch(CSoundPatch *this)
{
  this->m_pitch.m_current = 0.0;
  this->m_pitch.m_target = 0.0;
  this->m_pitch.m_rate = 0.0;
  this->m_pitch.m_forceupdate = false;
  this->m_volume.m_current = 0.0;
  this->m_volume.m_target = 0.0;
  this->m_volume.m_rate = 0.0;
  this->m_volume.m_forceupdate = false;
  this->m_hEnt.m_Index = -1;
  this->m_Filter.__vftable = (CCopyRecipientFilter_vtbl *)&CCopyRecipientFilter::`vftable';
  this->m_Filter.m_Flags = 0;
  this->m_Filter.m_Recipients.m_Memory.m_pMemory = nullptr;
  this->m_Filter.m_Recipients.m_Memory.m_nAllocationCount = 0;
  this->m_Filter.m_Recipients.m_Memory.m_nGrowSize = 0;
  this->m_Filter.m_Recipients.m_Size = 0;
  this->m_Filter.m_Recipients.m_pElements = nullptr;
  ++CSoundPatch::g_SoundPatchCount;
  this->m_iszSoundName = nullptr;
  this->m_iszSoundScriptName = nullptr;
  this->m_flCloseCaptionDuration = soundpatch_captionlength.m_pParent->m_Value.m_fValue;
  this->m_soundOrigin.x = 0.0;
  this->m_soundOrigin.y = 0.0;
  this->m_soundOrigin.z = 0.0;
  this->m_soundEntityIndex = -1;
  this->m_guid = -1;
  this->m_hSoundScriptHandle = -1;
  this->m_nSoundEntryVersion = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016D4A0
// Name: public: virtual void CSoundControllerImp::SystemReset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SystemReset(CSoundControllerImp *this)
{
  int i; // edi

  for ( i = this->m_soundList.m_Size - 1; i >= 0; --i )
    CSoundPatch::Shutdown(this: this->m_soundList.m_Memory.m_pMemory[i]);
  this->m_soundList.m_Size = 0;
  if ( this->m_soundList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_soundList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_soundList.m_Memory.m_pMemory);
      this->m_soundList.m_Memory.m_pMemory = nullptr;
    }
    this->m_soundList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_soundList.m_pElements = this->m_soundList.m_Memory.m_pMemory;
  this->m_commandList.m_heap.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016D500
// Name: public: virtual void CSoundControllerImp::Shutdown(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::Shutdown(CSoundControllerImp *this, CSoundPatch *pSound)
{
  CSoundPatch *v2; // esi

  v2 = pSound;
  if ( pSound != nullptr )
  {
    CSoundPatch::Shutdown(this: pSound);
    this->CommandClear(this, a2: v2);
    pSound = v2;
    CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_soundList,
      src: (vgui::TreeNode **)&pSound);
    CSoundPatch::Shutdown(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D540
// Name: public: virtual void CSoundControllerImp::SoundDestroy(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SoundDestroy(CSoundControllerImp *this, CSoundPatch *pSound)
{
  if ( pSound != nullptr )
  {
    this->Shutdown(this, a2: pSound);
    --CSoundPatch::g_SoundPatchCount;
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pSound->m_Filter.m_Recipients);
    pSound->m_Filter.__vftable = (CCopyRecipientFilter_vtbl *)&IRecipientFilter::`vftable';
    CUtlMemoryPool::Free(this: &CSoundPatch::s_Allocator, memBlock: pSound);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D5B0
// Name: public: bool CSoundPatch::Update(float,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundPatch::Update(CSoundPatch *this, float time, float deltaTime)
{
  float m_shutdownTime; // xmm0_4
  unsigned int m_Index; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  IHandleEntity *m_pEntity; // eax
  float m_target; // xmm3_4
  float m_current; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  int m_flags; // eax
  soundlevel_t m_soundlevel; // eax
  const char *m_iszSoundName; // edx
  float v24; // xmm0_4
  int m_nSoundEntryVersion; // ecx
  int v26; // edx
  int v27; // eax
  EmitSound_t ep; // [esp+4h] [ebp-48h] BYREF

  m_shutdownTime = this->m_shutdownTime;
  if ( m_shutdownTime != 0.0 && time > m_shutdownTime )
  {
    CSoundPatch::Shutdown(this);
    return 0;
  }
  m_Index = this->m_hEnt.m_Index;
  if ( m_Index == -1
    || (v7 = (unsigned __int16)m_Index,
        v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v9 = HIWORD(m_Index),
        v8->m_SerialNumber != v9)
    || v8->m_pEntity == nullptr
    || ((v10 = v7,
         v11 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v9,
         v12 = &g_pEntityList->m_EntPtrArray[v10],
         !v11)
      ? (m_pEntity = nullptr)
      : (m_pEntity = v12->m_pEntity),
        ((int (__thiscall *)(IHandleEntity *))m_pEntity[2].__vftable[3].SetRefEHandle)(a1: &m_pEntity[2]) < 0) )
  {
    DevWarning(a1: "CSoundPatch::Update:  Removing CSoundPatch (%s) with NULL EHandle\n", this->m_iszSoundName);
    return 0;
  }
  if ( this->m_pitch.m_forceupdate )
  {
    this->m_pitch.m_forceupdate = false;
  }
  else if ( this->m_pitch.m_current == this->m_pitch.m_target )
  {
    this->m_flags &= ~2u;
    goto LABEL_21;
  }
  m_target = this->m_pitch.m_target;
  m_current = this->m_pitch.m_current;
  v16 = this->m_pitch.m_rate * deltaTime;
  v17 = m_target - this->m_pitch.m_current;
  if ( v17 <= v16 )
  {
    this->m_flags |= 2u;
    if ( (float)-v16 <= v17 )
      this->m_pitch.m_current = m_target;
    else
      this->m_pitch.m_current = m_current - v16;
  }
  else
  {
    this->m_flags |= 2u;
    this->m_pitch.m_current = m_current + v16;
  }
LABEL_21:
  if ( this->m_volume.m_forceupdate )
  {
    this->m_volume.m_forceupdate = false;
  }
  else if ( this->m_volume.m_current == this->m_volume.m_target )
  {
    this->m_flags &= ~1u;
LABEL_31:
    m_flags = this->m_flags;
    if ( m_flags != 0 )
    {
      this->m_flags = m_flags | 1;
      EmitSound_t::EmitSound_t(this: &ep);
      m_soundlevel = this->m_soundlevel;
      m_iszSoundName = this->m_iszSoundName;
      v24 = this->m_flScriptVolume * this->m_volume.m_current;
      ep.m_nChannel = this->m_entityChannel;
      ep.m_nFlags = this->m_flags;
      m_nSoundEntryVersion = this->m_nSoundEntryVersion;
      ep.m_SoundLevel = m_soundlevel;
      LOWORD(m_soundlevel) = this->m_hSoundScriptHandle;
      ep.m_pSoundName = m_iszSoundName;
      v26 = (int)this->m_pitch.m_current;
      ep.m_nSoundEntryVersion = m_nSoundEntryVersion;
      ep.m_flVolume = v24;
      ep.m_nPitch = v26;
      ep.m_hSoundScriptHandle = m_soundlevel;
      if ( CSoundPatch::EntIndex(this) == 0 )
        ep.m_pOrigin = &this->m_soundOrigin;
      v27 = CSoundPatch::EntIndex(this);
      C_BaseEntity::EmitSound(filter: &this->m_Filter, iEntIndex: v27, params: &ep);
      this->m_flags = 0;
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    }
    return 1;
  }
  v18 = this->m_volume.m_current;
  v19 = this->m_volume.m_rate * deltaTime;
  v20 = this->m_volume.m_target - v18;
  if ( v20 <= v19 )
  {
    if ( (float)-v19 <= v20 )
      this->m_volume.m_current = this->m_volume.m_target;
    else
      this->m_volume.m_current = v18 - v19;
    this->m_flags |= 1u;
  }
  else
  {
    this->m_volume.m_current = v18 + v19;
    this->m_flags |= 1u;
  }
  goto LABEL_31;
}

//------------------------------------------------------------------------------
// Address: 0x1016D7E0
// Name: public: void CSoundPatch::StartSound(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPatch::StartSound(CSoundPatch *this, float flStartTime)
{
  bool v3; // zf
  int m_entityChannel; // eax
  soundlevel_t m_soundlevel; // edx
  int m_nSoundEntryVersion; // ecx
  float v7; // xmm0_4
  const char *v8; // ecx
  int m_baseFlags; // eax
  int m_current; // ecx
  int v11; // eax
  int v12; // eax
  float duration; // xmm0_4
  const char *m_iszSoundScriptName; // ecx
  int v15; // eax
  const char *v16; // [esp-8h] [ebp-64h]
  EmitSound_t ep; // [esp+14h] [ebp-48h] BYREF

  v3 = (this->m_Filter.m_Flags & 1) == 0;
  this->m_flags = 0;
  if ( !v3 )
  {
    m_entityChannel = this->m_entityChannel;
    m_soundlevel = this->m_soundlevel;
    ep.m_pSoundName = this->m_iszSoundName;
    m_nSoundEntryVersion = this->m_nSoundEntryVersion;
    v7 = this->m_flScriptVolume * this->m_volume.m_current;
    ep.m_nChannel = m_entityChannel;
    LOWORD(m_entityChannel) = this->m_hSoundScriptHandle;
    ep.m_nSoundEntryVersion = m_nSoundEntryVersion;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    memset(&ep.m_pOrigin, 0, 12);
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_flVolume = v7;
    ep.m_SoundLevel = m_soundlevel;
    ep.m_hSoundScriptHandle = m_entityChannel;
    if ( CSoundPatch::EntIndex(this) == 0 )
      ep.m_pOrigin = &this->m_soundOrigin;
    v3 = V_stristr(a1: v8, a2: nullptr, pStr: this->m_iszSoundName, pSearch: "music") == nullptr;
    m_baseFlags = this->m_baseFlags;
    if ( v3 )
      m_baseFlags |= 1u;
    m_current = (int)this->m_pitch.m_current;
    ep.m_nFlags = m_baseFlags | 0x1000;
    ep.m_nPitch = m_current;
    ep.m_bEmitCloseCaption = false;
    if ( flStartTime != 0.0 )
      ep.m_flSoundTime = flStartTime;
    v11 = CSoundPatch::EntIndex(this);
    v12 = C_BaseEntity::EmitSound(filter: &this->m_Filter, iEntIndex: v11, params: &ep);
    duration = this->m_flCloseCaptionDuration;
    m_iszSoundScriptName = this->m_iszSoundScriptName;
    this->m_guid = v12;
    v16 = m_iszSoundScriptName;
    v15 = CSoundPatch::EntIndex(this);
    C_BaseEntity::EmitCloseCaption(
      filter: &this->m_Filter,
      entindex: v15,
      token: v16,
      soundorigin: &ep.m_UtlVecSoundOrigin,
      duration,
      warnifmissing: true);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
  }
  this->m_isPlaying = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016D920
// Name: public: void CSoundControllerImp::ProcessCommand(struct SoundCommand_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::ProcessCommand(CSoundControllerImp *this, CSoundPatch *pCmd)
{
  SoundCommand_t *v2; // esi
  CSoundPatch *v3; // edi
  CSoundPatch *m_pPatch; // edi

  v2 = (SoundCommand_t *)pCmd;
  switch ( *(_DWORD *)&pCmd->m_pitch.m_forceupdate )
  {
    case 0:
      CSoundPatch::ChangeVolume(
        this: (CSoundPatch *)LODWORD(pCmd->m_pitch.m_current),
        volumeTarget: pCmd->m_volume.m_current,
        deltaTime: pCmd->m_pitch.m_rate);
      break;
    case 1:
      CSoundPatch::ChangePitch(
        this: (CSoundPatch *)LODWORD(pCmd->m_pitch.m_current),
        pitchTarget: pCmd->m_volume.m_current,
        deltaTime: pCmd->m_pitch.m_rate);
      break;
    case 2:
      CSoundPatch::Shutdown(this: (CSoundPatch *)LODWORD(pCmd->m_pitch.m_current));
      break;
    case 3:
      pCmd = (CSoundPatch *)LODWORD(pCmd->m_pitch.m_current);
      v3 = pCmd;
      CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_soundList,
        src: (vgui::TreeNode **)&pCmd);
      CSoundPatch::Shutdown(this: v3);
      m_pPatch = v2->m_pPatch;
      if ( v2->m_pPatch != nullptr )
      {
        --CSoundPatch::g_SoundPatchCount;
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pPatch->m_Filter.m_Recipients);
        m_pPatch->m_Filter.__vftable = (CCopyRecipientFilter_vtbl *)&IRecipientFilter::`vftable';
        CUtlMemoryPool::Free(this: &CSoundPatch::s_Allocator, memBlock: m_pPatch);
      }
      v2->m_pPatch = nullptr;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D9F0
// Name: public: virtual void CSoundControllerImp::Play(class CSoundPatch __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::Play(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        float volume,
        float pitch,
        float flStartTime)
{
  float v5; // xmm0_4
  bool v6; // zf
  int m_nAllocationCount; // eax
  int m_Size; // ebx
  CUtlMemory<vgui::TreeNode *,int> *p_m_soundList; // esi
  vgui::TreeNode **m_pMemory; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // ebx

  v5 = volume;
  pSound->m_flags |= 1u;
  pSound->m_shutdownTime = 0.0;
  if ( volume > 1.0 )
    v5 = 1.0;
  if ( v5 != pSound->m_volume.m_current )
    pSound->m_volume.m_forceupdate = true;
  if ( pSound->m_volume.m_target != v5 )
    pSound->m_volume.m_forceupdate = true;
  pSound->m_volume.m_target = v5;
  pSound->m_volume.m_current = v5;
  pSound->m_volume.m_rate = 0.0;
  pSound->m_flags |= 2u;
  if ( pitch != pSound->m_pitch.m_current )
    pSound->m_pitch.m_forceupdate = true;
  if ( pSound->m_pitch.m_target != pitch )
    pSound->m_pitch.m_forceupdate = true;
  v6 = pSound->m_isPlaying == 0;
  pSound->m_pitch.m_target = pitch;
  pSound->m_pitch.m_current = pitch;
  pSound->m_pitch.m_rate = 0.0;
  if ( v6 )
  {
    m_nAllocationCount = this->m_soundList.m_Memory.m_nAllocationCount;
    m_Size = this->m_soundList.m_Size;
    p_m_soundList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_soundList;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_soundList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_soundList[1].m_pMemory;
    m_pMemory = p_m_soundList->m_pMemory;
    v11 = (int)p_m_soundList[1].m_pMemory - m_Size - 1;
    p_m_soundList[1].m_nAllocationCount = (int)p_m_soundList->m_pMemory;
    if ( v11 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v11);
    v12 = &p_m_soundList->m_pMemory[m_Size];
    if ( v12 != nullptr )
      *v12 = (vgui::TreeNode *)pSound;
    CSoundPatch::StartSound(this: pSound, flStartTime);
  }
  else
  {
    this->CommandClear(this, a2: pSound);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016DB00
// Name: public: virtual void CSoundControllerImp::SystemUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SystemUpdate(CSoundControllerImp *this)
{
  bool v2; // zf
  SoundCommand_t **m_pMemory; // eax
  CSoundPatch *v4; // edi
  int i; // edi
  CSoundPatch *v6; // ebx
  int m_Size; // eax
  float deltaTime; // [esp+14h] [ebp-8h]
  float time; // [esp+18h] [ebp-4h]

  time = g_pEffects->Time(this: g_pEffects);
  deltaTime = time - this->m_flLastTime;
  if ( deltaTime < 0.0 )
    deltaTime = 0.0;
  v2 = this->m_commandList.m_heap.m_Size == 0;
  this->m_flLastTime = time;
  if ( !v2 )
  {
    do
    {
      m_pMemory = this->m_commandList.m_heap.m_Memory.m_pMemory;
      v4 = (CSoundPatch *)*m_pMemory;
      if ( time < (*m_pMemory)->m_time )
        break;
      CUtlPriorityQueue<SoundCommand_t *,CDefUtlPriorityQueueLessFunc<SoundCommand_t *>,CUtlMemory<SoundCommand_t *,int>>::RemoveAtHead(this: &this->m_commandList);
      CSoundControllerImp::ProcessCommand(this, pCmd: v4);
      CUtlMemoryPool::Free(this: &SoundCommand_t::s_Allocator, memBlock: v4);
    }
    while ( this->m_commandList.m_heap.m_Size != 0 );
  }
  for ( i = this->m_soundList.m_Size - 1; i >= 0; --i )
  {
    v6 = this->m_soundList.m_Memory.m_pMemory[i];
    if ( !CSoundPatch::Update(this: v6, time, deltaTime) )
    {
      v6->m_shutdownTime = 0.0;
      m_Size = this->m_soundList.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_soundList.m_Memory.m_pMemory[i] = this->m_soundList.m_Memory.m_pMemory[m_Size - 1];
        --this->m_soundList.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016DBE0
// Name: public: virtual void CSoundControllerImp::CheckLoopingSoundsForPlayer(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::CheckLoopingSoundsForPlayer(CSoundControllerImp *this, C_BasePlayer *pPlayer)
{
  int v2; // eax
  CSoundPatch *v3; // esi
  soundlevel_t m_soundlevel; // eax
  const char *m_iszSoundName; // edx
  float v6; // xmm0_4
  unsigned int m_Index; // ecx
  int m_current; // edx
  CBaseEntityList *v9; // edx
  int v10; // eax
  CEntInfo *v11; // edi
  unsigned int v12; // ecx
  int v13; // eax
  bool v14; // zf
  CEntInfo *v15; // eax
  IHandleEntity *m_pEntity; // eax
  unsigned int v17; // ecx
  int v18; // eax
  CEntInfo *v19; // esi
  unsigned int v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  EmitSound_t params; // [esp+0h] [ebp-70h] BYREF
  C_RecipientFilter v25; // [esp+48h] [ebp-28h] BYREF
  CSoundControllerImp *v26; // [esp+68h] [ebp-8h]
  int i; // [esp+6Ch] [ebp-4h]

  v2 = this->m_soundList.m_Size - 1;
  v26 = this;
  i = v2;
  if ( v2 >= 0 )
  {
    while ( 1 )
    {
      v3 = this->m_soundList.m_Memory.m_pMemory[v2];
      if ( (v3->m_Filter.m_Flags & 1) == 0 || !v3->m_Filter.AddRecipient(this: &v3->m_Filter, a2: pPlayer) )
        goto LABEL_23;
      C_RecipientFilter::C_RecipientFilter(this: &v25);
      v25.__vftable = (C_RecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
      C_RecipientFilter::AddRecipient(this: &v25, player: pPlayer);
      m_soundlevel = v3->m_soundlevel;
      m_iszSoundName = v3->m_iszSoundName;
      params.m_nChannel = v3->m_entityChannel;
      params.m_nFlags = v3->m_baseFlags | 1;
      v6 = v3->m_flScriptVolume * v3->m_volume.m_current;
      params.m_nSoundEntryVersion = v3->m_nSoundEntryVersion;
      m_Index = v3->m_hEnt.m_Index;
      params.m_SoundLevel = m_soundlevel;
      LOWORD(m_soundlevel) = v3->m_hSoundScriptHandle;
      params.m_pSoundName = m_iszSoundName;
      m_current = (int)v3->m_pitch.m_current;
      memset(&params.m_pOrigin, 0, 12);
      *(_WORD *)&params.m_bEmitCloseCaption = 1;
      params.m_bWarnOnDirectWaveReference = false;
      params.m_nSpeakerEntity = -1;
      memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
      params.m_flVolume = v6;
      params.m_nPitch = m_current;
      params.m_hSoundScriptHandle = m_soundlevel;
      if ( m_Index != -1 )
      {
        v9 = g_pEntityList;
        v10 = (unsigned __int16)m_Index;
        v11 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        v12 = HIWORD(m_Index);
        if ( v11->m_SerialNumber != v12 || v11->m_pEntity == nullptr )
          goto LABEL_15;
        v13 = v10;
        v14 = g_pEntityList->m_EntPtrArray[v13].m_SerialNumber == v12;
        v15 = &g_pEntityList->m_EntPtrArray[v13];
        if ( v14 )
          m_pEntity = v15->m_pEntity;
        else
          m_pEntity = nullptr;
        if ( ((int (__thiscall *)(IHandleEntity *))m_pEntity[2].__vftable[3].SetRefEHandle)(a1: &m_pEntity[2]) == 0 )
          params.m_pOrigin = &v3->m_soundOrigin;
      }
      v9 = g_pEntityList;
LABEL_15:
      v17 = v3->m_hEnt.m_Index;
      if ( v17 != -1
        && (v18 = (unsigned __int16)v17,
            v19 = &v9->m_EntPtrArray[(unsigned __int16)v17],
            v20 = HIWORD(v17),
            v19->m_SerialNumber == v20)
        && v19->m_pEntity != nullptr )
      {
        v21 = v18;
        v14 = v9->m_EntPtrArray[v21].m_SerialNumber == v20;
        v22 = (int)&v9->m_EntPtrArray[v21];
        if ( v14 )
          v23 = (*(int (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)v22 + 8) + 40))(a1: *(_DWORD *)v22 + 8);
        else
          v23 = (*(int (__thiscall **)(int))(MEMORY[8] + 40))(a1: 8);
      }
      else
      {
        v23 = -1;
      }
      C_BaseEntity::EmitSound(filter: &v25, iEntIndex: v23, &params);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
      C_RecipientFilter::~C_RecipientFilter(this: &v25);
LABEL_23:
      v2 = --i;
      if ( i < 0 )
        return;
      this = v26;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016DD90
// Name: public: virtual void CSoundControllerImp::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::OnRestore(CSoundControllerImp *this)
{
  int i; // edi
  const char *m_pszName; // eax
  int v4; // esi
  __int32 v5; // eax
  const char *v6; // edx
  float v7; // xmm0_4
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  EmitSound_t params; // [esp+8h] [ebp-48h] BYREF

  for ( i = this->m_soundList.m_Memory.m_nGrowSize - 1; i >= 0; --i )
  {
    m_pszName = this->m_pszName;
    v4 = *(_DWORD *)&m_pszName[4 * i];
    if ( v4 != 0 && *(_DWORD *)(v4 + 92) != 0 && (*(_BYTE *)(v4 + 104) & 1) != 0 )
    {
      if ( CSoundPatch::EntIndex(this: *(CSoundPatch **)&m_pszName[4 * i]) < 0 )
      {
        DevWarning(
          a1: "CSoundPatch::ResumeSound: Lost EHAndle on restore - destroy the sound patch in your entity's StopLoopingSounds! (%s)\n",
          *(const char **)(v4 + 44));
      }
      else
      {
        EmitSound_t::EmitSound_t(this: &params);
        v5 = *(_DWORD *)(v4 + 36);
        v6 = *(const char **)(v4 + 44);
        v7 = *(float *)(v4 + 96) * *(float *)(v4 + 16);
        params.m_nChannel = *(_DWORD *)(v4 + 64);
        params.m_nFlags = *(_DWORD *)(v4 + 88) | 3;
        v8 = *(_DWORD *)(v4 + 56);
        params.m_SoundLevel = v5;
        LOWORD(v5) = *(_WORD *)(v4 + 52);
        params.m_pSoundName = v6;
        v9 = (int)*(float *)v4;
        params.m_nSoundEntryVersion = v8;
        params.m_flVolume = v7;
        params.m_nPitch = v9;
        params.m_hSoundScriptHandle = v5;
        if ( CSoundPatch::EntIndex(this: (CSoundPatch *)v4) == 0 )
          params.m_pOrigin = (const Vector *)(v4 + 72);
        v10 = CSoundPatch::EntIndex(this: (CSoundPatch *)v4);
        C_BaseEntity::EmitSound(filter: (IRecipientFilter *)(v4 + 100), iEntIndex: v10, &params);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016DEF0
// Name: public: void CCopyRecipientFilter::Init(class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCopyRecipientFilter::Init(CCopyRecipientFilter *this, IRecipientFilter *pSrc)
{
  CCopyRecipientFilter *v3; // esi
  int v4; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // ecx
  int *v10; // eax
  int index; // [esp+Ch] [ebp-8h]
  int i; // [esp+1Ch] [ebp+8h]

  v3 = this;
  this->m_Flags = 1;
  if ( pSrc->IsReliable(this: pSrc) )
    v3->m_Flags |= 2u;
  if ( pSrc->IsInitMessage(this: pSrc) )
    v3->m_Flags |= 4u;
  v4 = 0;
  for ( i = 0; i < pSrc->GetRecipientCount(this: pSrc); v4 = i )
  {
    index = pSrc->GetRecipientIndex(this: pSrc, a2: v4);
    if ( index >= 0 )
    {
      m_Size = v3->m_Recipients.m_Size;
      m_nAllocationCount = v3->m_Recipients.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&v3->m_Recipients,
          num: m_Size - m_nAllocationCount + 1);
      ++v3->m_Recipients.m_Size;
      m_pMemory = v3->m_Recipients.m_Memory.m_pMemory;
      v8 = v3->m_Recipients.m_Size - m_Size - 1;
      v3->m_Recipients.m_pElements = m_pMemory;
      if ( v8 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v8);
      v9 = v3->m_Recipients.m_Memory.m_pMemory;
      v3 = this;
      v10 = &v9[m_Size];
      if ( v10 != nullptr )
        *v10 = index;
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016DFD0
// Name: public: virtual bool CCopyRecipientFilter::AddRecipient(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCopyRecipientFilter::AddRecipient(CCopyRecipientFilter *this, C_BasePlayer *player)
{
  int v3; // ebx
  int m_Size; // ecx
  int v6; // eax
  int *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  int *v10; // ecx
  int v11; // eax
  int *v12; // eax

  v3 = player->entindex(this: &player->IClientNetworkable);
  if ( v3 < 0 )
    return 0;
  m_Size = this->m_Recipients.m_Size;
  v6 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_Recipients.m_Memory.m_pMemory;
    while ( *m_pMemory != v3 )
    {
      ++v6;
      ++m_pMemory;
      if ( v6 >= m_Size )
        goto LABEL_9;
    }
    if ( v6 != -1 )
      return 0;
  }
LABEL_9:
  m_nAllocationCount = this->m_Recipients.m_Memory.m_nAllocationCount;
  v9 = this->m_Recipients.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Recipients,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Recipients.m_Size;
  v10 = this->m_Recipients.m_Memory.m_pMemory;
  v11 = this->m_Recipients.m_Size - v9 - 1;
  this->m_Recipients.m_pElements = v10;
  if ( v11 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v10[v9 + 1], src: (unsigned __int8 *)&v10[v9], count: 4 * v11);
  v12 = &this->m_Recipients.m_Memory.m_pMemory[v9];
  if ( v12 != nullptr )
    *v12 = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016E1D0
// Name: public: void CSoundPatch::Init(class IRecipientFilter __near *,class C_BaseEntity __near *,int,char const __near *,enum soundlevel_t,class Vector const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPatch::Init(
        CSoundPatch *this,
        IRecipientFilter *pFilter,
        C_BaseEntity *pEnt,
        const char *channel,
        char *pSoundName,
        soundlevel_t soundlevel,
        const Vector *pSoundOrigin,
        float scriptVolume)
{
  char *soundname; // edi
  const char *v10; // ecx
  const char *v11; // eax
  __int16 m_hSoundScriptHandle; // cx
  int m_nSoundEntryVersion; // edx
  soundlevel_t v14; // eax
  bool v15; // cc
  CSoundParameters params; // [esp+Ch] [ebp-B4h] BYREF

  if ( pEnt != nullptr )
  {
    this->m_hEnt.m_Index = pEnt->GetRefEHandle(this: pEnt)->m_Index;
    this->m_soundEntityIndex = pEnt->entindex(this: &pEnt->IClientNetworkable);
  }
  else
  {
    this->m_hEnt.m_Index = -1;
  }
  soundname = pSoundName;
  this->m_entityChannel = (int)channel;
  params.channel = 0;
  params.volume = 1.0;
  params.pitch = 100;
  params.pitchlow = 100;
  params.pitchhigh = 100;
  params.soundlevel = SNDLVL_NORM;
  params.soundname[0] = 0;
  params.play_to_owner_only = false;
  params.count = 0;
  params.delay_msec = 0;
  params.m_nSoundEntryVersion = 1;
  params.m_hSoundScriptHandle = -1;
  params.m_pOperatorsKV = nullptr;
  params.m_nRandomSeed = -1;
  if ( V_stristr(a1: channel, a2: nullptr, pStr: pSoundName, pSearch: ".wav") != nullptr
    || V_stristr(a1: v10, a2: nullptr, pStr: pSoundName, pSearch: ".mp3") != nullptr
    || !C_BaseEntity::GetParametersForSound(soundname: pSoundName, &params, actormodel: nullptr) )
  {
    this->m_iszSoundScriptName = AllocPooledString(pszValue: pSoundName);
    this->m_flScriptVolume = scriptVolume;
    this->m_soundlevel = soundlevel;
  }
  else
  {
    this->m_flScriptVolume = params.volume;
    v11 = AllocPooledString(pszValue: pSoundName);
    m_hSoundScriptHandle = params.m_hSoundScriptHandle;
    m_nSoundEntryVersion = params.m_nSoundEntryVersion;
    this->m_iszSoundScriptName = v11;
    v14 = params.soundlevel;
    v15 = this->m_entityChannel < 135;
    this->m_hSoundScriptHandle = m_hSoundScriptHandle;
    this->m_nSoundEntryVersion = m_nSoundEntryVersion;
    soundname = params.soundname;
    this->m_soundlevel = v14;
    if ( v15 )
      this->m_entityChannel = params.channel;
  }
  this->m_iszSoundName = AllocPooledString(pszValue: soundname);
  if ( this->m_volume.m_target != 0.0 )
    this->m_volume.m_forceupdate = true;
  this->m_volume.m_target = 0.0;
  this->m_volume.m_current = 0.0;
  this->m_volume.m_rate = 0.0;
  if ( this->m_pitch.m_target != 0.0 )
    this->m_pitch.m_forceupdate = true;
  *(_QWORD *)&this->m_pitch.m_current = 0;
  this->m_pitch.m_rate = 0.0;
  this->m_isPlaying = 0;
  this->m_shutdownTime = 0.0;
  CCopyRecipientFilter::Init(this: &this->m_Filter, pSrc: pFilter);
  this->m_baseFlags = 0;
  if ( pSoundOrigin != nullptr )
    this->m_soundOrigin = *pSoundOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x1016E430
// Name: public: virtual char const __near * CSoundControllerImp::SoundGetName(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSoundControllerImp::SoundGetName(CSoundControllerImp *this, CSoundPatch *pSound)
{
  return pSound->m_iszSoundName;
}

//------------------------------------------------------------------------------
// Address: 0x1016E440
// Name: public: virtual char const __near * CSoundControllerImp::SoundGetScriptName(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSoundControllerImp::SoundGetScriptName(CSoundControllerImp *this, CSoundPatch *pSound)
{
  return pSound->m_iszSoundScriptName;
}

//------------------------------------------------------------------------------
// Address: 0x1016E450
// Name: public: virtual void CSoundControllerImp::SoundSetCloseCaptionDuration(class CSoundPatch __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SoundSetCloseCaptionDuration(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        float flDuration)
{
  pSound->m_flCloseCaptionDuration = flDuration;
}

//------------------------------------------------------------------------------
// Address: 0x1016E470
// Name: public: virtual void CSoundControllerImp::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::Update(CSoundControllerImp *this, float frametime)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 4))(a1: (char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x1016E480
// Name: public: virtual void CSoundControllerImp::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::LevelShutdownPreEntity(CSoundControllerImp *this)
{
  (**((void (__thiscall ***)(char *))this - 1))(a1: (char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x1016E4E0
// Name: public: virtual void CSoundControllerImp::CommandAdd(class CSoundPatch __near *,float,enum soundcommands_t,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::CommandAdd(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        float executeDeltaTime,
        soundcommands_t command,
        float commandTime,
        float commandValue)
{
  float v7; // esi
  double v8; // st7
  float v9; // xmm0_4
  soundcommands_t v10; // ecx
  float v11; // xmm0_4

  v7 = COERCE_FLOAT(CUtlMemoryPool::Alloc(this: &SoundCommand_t::s_Allocator, amount: 0x18u));
  if ( v7 == 0.0 )
  {
    v7 = 0.0;
  }
  else
  {
    v8 = ((double (__thiscall *)(IEffects *))g_pEffects->Time)(a1: g_pEffects);
    v9 = commandTime;
    v10 = command;
    *(float *)(LODWORD(v7) + 4) = v8 + executeDeltaTime;
    *(float *)(LODWORD(v7) + 8) = v9;
    v11 = commandValue;
    *(_DWORD *)LODWORD(v7) = pSound;
    *(_DWORD *)(LODWORD(v7) + 12) = v10;
    *(float *)(LODWORD(v7) + 16) = v11;
  }
  executeDeltaTime = v7;
  CUtlPriorityQueue<SoundCommand_t *,CDefUtlPriorityQueueLessFunc<SoundCommand_t *>,CUtlMemory<SoundCommand_t *,int>>::Insert(
    this: (CUtlPriorityQueue<CHudElement *,CDefUtlPriorityQueueLessFunc<CHudElement *>,CUtlMemory<CHudElement *,int> > *)&this->m_commandList,
    element: (CHudElement *const *)&executeDeltaTime);
}

//------------------------------------------------------------------------------
// Address: 0x1016E550
// Name: public: virtual class CSoundPatch __near * CSoundControllerImp::SoundCreate(class IRecipientFilter __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSoundPatch *__thiscall CSoundControllerImp::SoundCreate(
        CSoundControllerImp *this,
        IRecipientFilter *filter,
        int nEntIndex,
        const char *pSoundName)
{
  CSoundPatch *v4; // eax
  CSoundPatch *v5; // esi
  C_BaseEntity *m_pEntity; // eax
  unsigned int nEntIndexa; // [esp+14h] [ebp+Ch]

  v4 = (CSoundPatch *)CUtlMemoryPool::Alloc(this: &CSoundPatch::s_Allocator, amount: 0x84u);
  if ( v4 != nullptr )
    v5 = CSoundPatch::CSoundPatch(this: v4);
  else
    v5 = nullptr;
  if ( nEntIndex == -1 )
  {
    nEntIndexa = 0;
  }
  else if ( g_pEntityList->m_EntPtrArray[nEntIndex].m_pEntity != nullptr )
  {
    nEntIndexa = nEntIndex | (g_pEntityList->m_EntPtrArray[nEntIndex].m_SerialNumber << 16);
  }
  else
  {
    nEntIndexa = -1;
  }
  if ( nEntIndexa == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_SerialNumber != HIWORD(nEntIndexa) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_pEntity;
  }
  CSoundPatch::Init(
    this: v5,
    pFilter: filter,
    pEnt: m_pEntity,
    channel: 0,
    pSoundName,
    soundlevel: SNDLVL_NORM,
    pSoundOrigin: nullptr,
    scriptVolume: 1.0);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1016E600
// Name: public: virtual class CSoundPatch __near * CSoundControllerImp::SoundCreate(class IRecipientFilter __near &,int,int,char const __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
CSoundPatch *__thiscall CSoundControllerImp::SoundCreate(
        CSoundControllerImp *this,
        IRecipientFilter *filter,
        int nEntIndex,
        int channel,
        const char *pSoundName,
        float attenuation,
        float scriptVolume)
{
  CSoundPatch *v7; // eax
  CSoundPatch *v8; // esi
  float v9; // xmm0_4
  C_BaseEntity *m_pEntity; // eax
  unsigned int nEntIndexa; // [esp+14h] [ebp+Ch]

  v7 = (CSoundPatch *)CUtlMemoryPool::Alloc(this: &CSoundPatch::s_Allocator, amount: 0x84u);
  if ( v7 != nullptr )
    v8 = CSoundPatch::CSoundPatch(this: v7);
  else
    v8 = nullptr;
  if ( nEntIndex == -1 )
  {
    nEntIndexa = 0;
  }
  else if ( g_pEntityList->m_EntPtrArray[nEntIndex].m_pEntity != nullptr )
  {
    nEntIndexa = nEntIndex | (g_pEntityList->m_EntPtrArray[nEntIndex].m_SerialNumber << 16);
  }
  else
  {
    nEntIndexa = -1;
  }
  v9 = 0.0;
  if ( attenuation != 0.0 )
    v9 = (float)(20.0 / attenuation) + 50.0;
  if ( nEntIndexa == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_SerialNumber != HIWORD(nEntIndexa) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_pEntity;
  }
  CSoundPatch::Init(
    this: v8,
    pFilter: filter,
    pEnt: m_pEntity,
    channel,
    pSoundName,
    soundlevel: (soundlevel_t)v9,
    pSoundOrigin: nullptr,
    scriptVolume);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1016E6E0
// Name: public: virtual class CSoundPatch __near * CSoundControllerImp::SoundCreate(class IRecipientFilter __near &,int,int,char const __near *,float,class Vector const __near *,float)
// Source: json
//------------------------------------------------------------------------------
CSoundPatch *__thiscall CSoundControllerImp::SoundCreate(
        CSoundControllerImp *this,
        IRecipientFilter *filter,
        int nEntIndex,
        int channel,
        const char *pSoundName,
        float attenuation,
        const Vector *pSoundOrigin,
        float scriptVolume)
{
  CSoundPatch *v8; // eax
  CSoundPatch *v9; // esi
  float v10; // xmm0_4
  C_BaseEntity *m_pEntity; // eax
  unsigned int nEntIndexa; // [esp+14h] [ebp+Ch]

  v8 = (CSoundPatch *)CUtlMemoryPool::Alloc(this: &CSoundPatch::s_Allocator, amount: 0x84u);
  if ( v8 != nullptr )
    v9 = CSoundPatch::CSoundPatch(this: v8);
  else
    v9 = nullptr;
  if ( nEntIndex == -1 )
  {
    nEntIndexa = 0;
  }
  else if ( g_pEntityList->m_EntPtrArray[nEntIndex].m_pEntity != nullptr )
  {
    nEntIndexa = nEntIndex | (g_pEntityList->m_EntPtrArray[nEntIndex].m_SerialNumber << 16);
  }
  else
  {
    nEntIndexa = -1;
  }
  v10 = 0.0;
  if ( attenuation != 0.0 )
    v10 = (float)(20.0 / attenuation) + 50.0;
  if ( nEntIndexa == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_SerialNumber != HIWORD(nEntIndexa) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_pEntity;
  }
  CSoundPatch::Init(
    this: v9,
    pFilter: filter,
    pEnt: m_pEntity,
    channel,
    pSoundName,
    soundlevel: (soundlevel_t)v10,
    pSoundOrigin,
    scriptVolume);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1016E7C0
// Name: public: virtual class CSoundPatch __near * CSoundControllerImp::SoundCreate(class IRecipientFilter __near &,int,int,char const __near *,enum soundlevel_t)
// Source: json
//------------------------------------------------------------------------------
CSoundPatch *__thiscall CSoundControllerImp::SoundCreate(
        CSoundControllerImp *this,
        IRecipientFilter *filter,
        int nEntIndex,
        int channel,
        const char *pSoundName,
        soundlevel_t soundlevel)
{
  CSoundPatch *v6; // eax
  CSoundPatch *v7; // esi
  C_BaseEntity *m_pEntity; // eax
  unsigned int nEntIndexa; // [esp+14h] [ebp+Ch]

  v6 = (CSoundPatch *)CUtlMemoryPool::Alloc(this: &CSoundPatch::s_Allocator, amount: 0x84u);
  if ( v6 != nullptr )
    v7 = CSoundPatch::CSoundPatch(this: v6);
  else
    v7 = nullptr;
  if ( nEntIndex == -1 )
  {
    nEntIndexa = 0;
  }
  else if ( g_pEntityList->m_EntPtrArray[nEntIndex].m_pEntity != nullptr )
  {
    nEntIndexa = nEntIndex | (g_pEntityList->m_EntPtrArray[nEntIndex].m_SerialNumber << 16);
  }
  else
  {
    nEntIndexa = -1;
  }
  if ( nEntIndexa == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_SerialNumber != HIWORD(nEntIndexa) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_pEntity;
  }
  CSoundPatch::Init(
    this: v7,
    pFilter: filter,
    pEnt: m_pEntity,
    channel,
    pSoundName,
    soundlevel,
    pSoundOrigin: nullptr,
    scriptVolume: 1.0);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1016E870
// Name: public: virtual class CSoundPatch __near * CSoundControllerImp::SoundCreate(class IRecipientFilter __near &,int,struct EmitSound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CSoundPatch *__thiscall CSoundControllerImp::SoundCreate(
        CSoundControllerImp *this,
        IRecipientFilter *filter,
        int nEntIndex,
        const EmitSound_t *es)
{
  CSoundPatch *v4; // eax
  CSoundPatch *v5; // esi
  C_BaseEntity *m_pEntity; // eax
  float m_flVolume; // xmm0_4
  __m128i v8; // xmm0
  float v9; // xmm0_4
  CSoundPatch *result; // eax
  unsigned int nEntIndexa; // [esp+18h] [ebp+Ch]

  v4 = (CSoundPatch *)CUtlMemoryPool::Alloc(this: &CSoundPatch::s_Allocator, amount: 0x84u);
  if ( v4 != nullptr )
    v5 = CSoundPatch::CSoundPatch(this: v4);
  else
    v5 = nullptr;
  if ( nEntIndex == -1 )
  {
    nEntIndexa = 0;
  }
  else if ( g_pEntityList->m_EntPtrArray[nEntIndex].m_pEntity != nullptr )
  {
    nEntIndexa = nEntIndex | (g_pEntityList->m_EntPtrArray[nEntIndex].m_SerialNumber << 16);
  }
  else
  {
    nEntIndexa = -1;
  }
  if ( nEntIndexa == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_SerialNumber != HIWORD(nEntIndexa) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_pEntity;
  }
  CSoundPatch::Init(
    this: v5,
    pFilter: filter,
    pEnt: m_pEntity,
    channel: es->m_nChannel,
    pSoundName: es->m_pSoundName,
    soundlevel: es->m_SoundLevel,
    pSoundOrigin: es->m_pOrigin,
    scriptVolume: 1.0);
  m_flVolume = es->m_flVolume;
  v5->m_flags |= 1u;
  if ( m_flVolume > 1.0 )
    m_flVolume = 1.0;
  if ( m_flVolume != v5->m_volume.m_current )
    v5->m_volume.m_forceupdate = true;
  if ( v5->m_volume.m_target != m_flVolume )
    v5->m_volume.m_forceupdate = true;
  v5->m_volume.m_target = m_flVolume;
  v5->m_volume.m_current = m_flVolume;
  v5->m_volume.m_rate = 0.0;
  v8 = _mm_cvtsi32_si128(es->m_nPitch);
  v5->m_flags |= 2u;
  v9 = _mm_cvtepi32_ps(v8).m128_f32[0];
  if ( v9 != v5->m_pitch.m_current )
    v5->m_pitch.m_forceupdate = true;
  if ( v5->m_pitch.m_target != v9 )
    v5->m_pitch.m_forceupdate = true;
  v5->m_pitch.m_target = v9;
  v5->m_pitch.m_current = v9;
  v5->m_pitch.m_rate = 0.0;
  result = v5;
  if ( SLOBYTE(es->m_nFlags) < 0 )
    v5->m_baseFlags = 128;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016E9C0
// Name: public: virtual void CSoundPatchSaveRestoreOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPatchSaveRestoreOps::Restore(
        CSoundPatchSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  IRestore *v3; // esi
  const SaveRestoreFieldInfo_t *v4; // eax
  int v5; // eax
  void (__thiscall *EndBlock)(IRestore *); // edx
  int m_Size; // eax
  int v8; // edi
  CSoundPatch **m_pMemory; // ecx
  int v10; // eax
  const SaveRestoreFieldInfo_t **v11; // eax
  IRestore *v12; // eax
  IRestore *v13; // edi
  bool v14; // sf
  int nSoundPatchCount; // [esp+8h] [ebp-Ch]
  CSoundPatch **ppSoundPatch; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h] BYREF
  const SaveRestoreFieldInfo_t *fieldInfoa; // [esp+1Ch] [ebp+8h]

  v3 = pRestore;
  pRestore->StartBlock(this: pRestore);
  ppSoundPatch = (CSoundPatch **)fieldInfo->pField;
  nSoundPatchCount = fieldInfo->pTypeDesc->fieldSize - 1;
  if ( nSoundPatchCount >= 0 )
  {
    do
    {
      v4 = (const SaveRestoreFieldInfo_t *)CUtlMemoryPool::Alloc(this: &CSoundPatch::s_Allocator, amount: 0x84u);
      if ( v4 != nullptr )
      {
        v4->pField = nullptr;
        v4->pOwner = nullptr;
        v4->pTypeDesc = nullptr;
        LOBYTE(v4[1].pField) = 0;
        v4[1].pOwner = nullptr;
        v4[1].pTypeDesc = nullptr;
        v4[2].pField = nullptr;
        LOBYTE(v4[2].pOwner) = 0;
        v4[5].pField = (void *)-1;
        v4[8].pOwner = &CCopyRecipientFilter::`vftable';
        v4[8].pTypeDesc = nullptr;
        v4[9].pField = nullptr;
        v4[9].pOwner = nullptr;
        v4[9].pTypeDesc = nullptr;
        v4[10].pField = nullptr;
        v4[10].pOwner = nullptr;
        ++CSoundPatch::g_SoundPatchCount;
        v4[3].pTypeDesc = nullptr;
        v4[4].pField = nullptr;
        fieldInfoa = v4;
        *(float *)&v4[10].pTypeDesc = soundpatch_captionlength.m_pParent->m_Value.m_fValue;
        v4[6].pField = nullptr;
        v4[6].pOwner = nullptr;
        v4[6].pTypeDesc = nullptr;
        v4[5].pTypeDesc = (typedescription_t *)-1;
        v4[2].pTypeDesc = (typedescription_t *)-1;
        LOWORD(v4[4].pOwner) = -1;
        v4[4].pTypeDesc = (typedescription_t *)1;
      }
      else
      {
        fieldInfoa = nullptr;
      }
      v3->StartBlock(this: v3);
      v5 = v3->ReadAll(this: v3, a2: (void *)fieldInfoa, a3: &CSoundPatch::m_DataMap);
      EndBlock = v3->EndBlock;
      HIBYTE(pRestore) = v5 != 0;
      EndBlock(this: v3);
      if ( HIBYTE(pRestore) != 0 && fieldInfoa[7].pTypeDesc != nullptr )
      {
        m_Size = g_Controller.m_soundList.m_Size;
        HIBYTE(pRestore) = 1;
        v8 = g_Controller.m_soundList.m_Size;
        if ( g_Controller.m_soundList.m_Size + 1 > g_Controller.m_soundList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&g_Controller.m_soundList,
            num: g_Controller.m_soundList.m_Size - g_Controller.m_soundList.m_Memory.m_nAllocationCount + 1);
          m_Size = g_Controller.m_soundList.m_Size;
        }
        m_pMemory = g_Controller.m_soundList.m_Memory.m_pMemory;
        g_Controller.m_soundList.m_Size = m_Size + 1;
        v10 = m_Size - v8;
        g_Controller.m_soundList.m_pElements = g_Controller.m_soundList.m_Memory.m_pMemory;
        if ( v10 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&g_Controller.m_soundList.m_Memory.m_pMemory[v8 + 1],
            src: (unsigned __int8 *)&g_Controller.m_soundList.m_Memory.m_pMemory[v8],
            count: 4 * v10);
          m_pMemory = g_Controller.m_soundList.m_Memory.m_pMemory;
        }
        v11 = (const SaveRestoreFieldInfo_t **)&m_pMemory[v8];
        if ( v11 != nullptr )
          *v11 = fieldInfoa;
      }
      else
      {
        HIBYTE(pRestore) = 0;
      }
      v3->StartBlock(this: v3);
      if ( HIBYTE(pRestore) != 0 )
      {
        v3->ReadInt_2(this: v3, a2: &v17, a3: 1, a4: 0);
        if ( --v17 >= 0 )
        {
          do
          {
            v12 = (IRestore *)CUtlMemoryPool::Alloc(this: &SoundCommand_t::s_Allocator, amount: 0x18u);
            if ( v12 != nullptr )
            {
              *(_QWORD *)&v12->__vftable = 0;
              *(_QWORD *)&v12[2].__vftable = 0;
              *(_QWORD *)&v12[4].__vftable = 0;
              v13 = v12;
            }
            else
            {
              v13 = nullptr;
            }
            v3->StartBlock(this: v3);
            if ( v3->ReadAll(this: v3, a2: v13, a3: &SoundCommand_t::m_DataMap) != 0 )
            {
              v13->__vftable = (IRestore_vtbl *)fieldInfoa;
              pRestore = v13;
              CUtlPriorityQueue<SoundCommand_t *,CDefUtlPriorityQueueLessFunc<SoundCommand_t *>,CUtlMemory<SoundCommand_t *,int>>::Insert(
                this: (CUtlPriorityQueue<CHudElement *,CDefUtlPriorityQueueLessFunc<CHudElement *>,CUtlMemory<CHudElement *,int> > *)&g_Controller.m_commandList,
                element: (CHudElement *const *)&pRestore);
            }
            v3->EndBlock(this: v3);
            --v17;
          }
          while ( v17 >= 0 );
        }
      }
      v3->EndBlock(this: v3);
      *ppSoundPatch = (CSoundPatch *)fieldInfoa;
      v14 = --nSoundPatchCount < 0;
      ++ppSoundPatch;
    }
    while ( !v14 );
  }
  v3->EndBlock(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1016EC10
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
  CUtlVector<IKeyBindingListener *,CUtlMemory<IKeyBindingListener *,int>>::InsertMultipleBefore(
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
// Address: 0x1041C590
// Name: CSoundEnvelope_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSoundEnvelope_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSoundEnvelope>();
  CSoundEnvelope_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C5A0
// Name: CCopyRecipientFilter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CCopyRecipientFilter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CCopyRecipientFilter>();
  CCopyRecipientFilter_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C5E0
// Name: _dynamic_initializer_for__CSoundPatch::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CSoundPatch::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CSoundPatch::s_Allocator,
    blockSize: 0x84u,
    numElements: 64,
    growMode: 1,
    pszAllocOwner: "CSoundPatch pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CSoundPatch::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C610
// Name: CSoundPatch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSoundPatch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSoundPatch>();
  CSoundPatch_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C650
// Name: SoundCommand_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *SoundCommand_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<SoundCommand_t>();
  SoundCommand_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10433AB0
// Name: _dynamic_atexit_destructor_for__CSoundPatch::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CSoundPatch::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CSoundPatch::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x1016DE70
// Name: struct datamap_t __near * DataMapInit<class CSoundEnvelope>(class CSoundEnvelope __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSoundEnvelope>()
{
  if ( (_S5_117 & 1) == 0 )
  {
    _S5_117 |= 1u;
    nameHolder_25.m_pszBase = "CSoundEnvelope";
    nameHolder_25.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_25.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_25.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_25.m_Names.m_Size = 0;
    nameHolder_25.m_Names.m_pElements = nullptr;
    nameHolder_25.m_nLenBase = 14;
    atexit(func: DataMapInit_CSoundEnvelope__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSoundEnvelope::m_DataMap.baseMap = nullptr;
  CSoundEnvelope::m_DataMap.dataNumFields = 4;
  CSoundEnvelope::m_DataMap.dataDesc = &dataDesc_24[1];
  return &CSoundEnvelope::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016E070
// Name: struct datamap_t __near * DataMapInit<class CCopyRecipientFilter>(class CCopyRecipientFilter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CCopyRecipientFilter>()
{
  if ( (_S6_39 & 1) == 0 )
  {
    _S6_39 |= 1u;
    nameHolder_26.m_pszBase = "CCopyRecipientFilter";
    nameHolder_26.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_26.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_26.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_26.m_Names.m_Size = 0;
    nameHolder_26.m_Names.m_pElements = nullptr;
    nameHolder_26.m_nLenBase = 20;
    atexit(func: DataMapInit_CCopyRecipientFilter__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CCopyRecipientFilter::m_DataMap.baseMap = nullptr;
  if ( (_S6_39 & 2) == 0 )
  {
    _S6_39 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<5>::GetDataOps<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<5>::GetDataOps<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<5>::GetDataOps<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<int,CUtlMemory<int,int>>,5>::`vftable';
    }
    dataDesc_25[2].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<5>::GetDataOps<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::ops;
    dataDesc_25[2].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_25[2].td = 0;
    *(_QWORD *)&dataDesc_25[2].override_field = 0;
    *(_QWORD *)&dataDesc_25[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_25[2].flatOffset[1] = 0;
  }
  CCopyRecipientFilter::m_DataMap.dataNumFields = 2;
  CCopyRecipientFilter::m_DataMap.dataDesc = &dataDesc_25[1];
  return &CCopyRecipientFilter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016E150
// Name: struct datamap_t __near * DataMapInit<class CSoundPatch>(class CSoundPatch __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSoundPatch>()
{
  if ( (_S7_14 & 1) == 0 )
  {
    _S7_14 |= 1u;
    nameHolder_27.m_pszBase = "CSoundPatch";
    nameHolder_27.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_27.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_27.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_27.m_Names.m_Size = 0;
    nameHolder_27.m_Names.m_pElements = nullptr;
    nameHolder_27.m_nLenBase = 11;
    atexit(func: DataMapInit_CSoundPatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSoundPatch::m_DataMap.baseMap = nullptr;
  CSoundPatch::m_DataMap.dataNumFields = 16;
  CSoundPatch::m_DataMap.dataDesc = &dataDesc_26[1];
  return &CSoundPatch::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1041C5B0
// Name: _dynamic_initializer_for__cl_report_soundpatch_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_report_soundpatch_command__()
{
  ConCommand::ConCommand(
    this: &cl_report_soundpatch_command,
    pName: "cl_report_soundpatch",
    callback: cl_report_soundpatch,
    pHelpString: "reports client-side sound patch count",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_report_soundpatch_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C620
// Name: _dynamic_initializer_for__SoundCommand_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__SoundCommand_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &SoundCommand_t::s_Allocator,
    blockSize: 0x18u,
    numElements: 32,
    growMode: 1,
    pszAllocOwner: "SoundCommand_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__SoundCommand_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C660
// Name: _dynamic_initializer_for__g_Controller__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Controller__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(
    this: &g_Controller.CAutoGameSystemPerFrame,
    name: "CSoundControllerImp");
  g_Controller.CSoundEnvelopeController::__vftable = (CSoundControllerImp_vtbl *)&CSoundControllerImp::`vftable'{for `CSoundEnvelopeController'};
  g_Controller.CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CAutoGameSystemPerFrame_vtbl *)&CSoundControllerImp::`vftable'{for `CAutoGameSystemPerFrame'};
  g_Controller.m_soundList.m_Memory.m_pMemory = nullptr;
  g_Controller.m_soundList.m_Memory.m_nAllocationCount = 0;
  g_Controller.m_soundList.m_Memory.m_nGrowSize = 0;
  g_Controller.m_soundList.m_Size = 0;
  g_Controller.m_soundList.m_pElements = nullptr;
  g_Controller.m_commandList.m_heap.m_Memory.m_pMemory = nullptr;
  g_Controller.m_commandList.m_heap.m_Memory.m_nAllocationCount = 0;
  g_Controller.m_commandList.m_heap.m_Memory.m_nGrowSize = 0;
  g_Controller.m_commandList.m_heap.m_Size = 0;
  g_Controller.m_commandList.m_heap.m_pElements = nullptr;
  g_Controller.m_commandList.m_LessFunc = (bool (__cdecl *)(SoundCommand_t *const *, SoundCommand_t *const *))SoundCommandLessFunc;
  return atexit(func: dynamic_atexit_destructor_for__g_Controller__);
}

//------------------------------------------------------------------------------
// Address: 0x10433AC0
// Name: _dynamic_atexit_destructor_for__SoundCommand_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__SoundCommand_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &SoundCommand_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x10433AD0
// Name: _DataMapInit_CSoundEnvelope__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSoundEnvelope__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_25);
}

//------------------------------------------------------------------------------
// Address: 0x10433AE0
// Name: _DataMapInit_CCopyRecipientFilter__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CCopyRecipientFilter__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_26);
}

//------------------------------------------------------------------------------
// Address: 0x10433AF0
// Name: _DataMapInit_CSoundPatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSoundPatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_27);
}

//------------------------------------------------------------------------------
// Address: 0x10433B00
// Name: _DataMapInit_SoundCommand_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_SoundCommand_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_28);
}

//------------------------------------------------------------------------------
// Address: 0x10433B10
// Name: _dynamic_atexit_destructor_for__g_Controller__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Controller__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Controller.m_commandList);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Controller.m_soundList);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_Controller.CAutoGameSystemPerFrame);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1021D100
// Name: report_soundpatch
// Source: json
//------------------------------------------------------------------------------
void __cdecl report_soundpatch()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    _Msg(a1: "Current sound patches: %d\n", CSoundPatch::g_SoundPatchCount);
}

//------------------------------------------------------------------------------
// Address: 0x1021D120
// Name: public: virtual float CSoundControllerImp::SoundGetPitch(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSoundControllerImp::SoundGetPitch(CSoundControllerImp *this, CSoundPatch *pSound)
{
  return pSound->m_pitch.m_current;
}

//------------------------------------------------------------------------------
// Address: 0x1021D130
// Name: public: virtual float CSoundControllerImp::SoundGetVolume(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSoundControllerImp::SoundGetVolume(CSoundControllerImp *this, CSoundPatch *pSound)
{
  return pSound->m_volume.m_current;
}

//------------------------------------------------------------------------------
// Address: 0x1021D140
// Name: public: virtual float CSoundControllerImp::SoundPlayEnvelope(class CSoundPatch __near *,enum soundcommands_t,struct envelopePoint_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CSoundControllerImp::SoundPlayEnvelope@<st0>(
        CSoundControllerImp *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CSoundPatch *pSound,
        soundcommands_t soundCommand,
        envelopePoint_t *points,
        int numPoints)
{
  int i; // edi
  float amplitudeMin; // xmm0_4
  envelopePoint_t *v10; // esi
  float durationMin; // xmm0_4
  float amplitude; // [esp+30h] [ebp-Ch]
  float duration; // [esp+34h] [ebp-8h]
  float totalDuration; // [esp+38h] [ebp-4h]

  amplitude = 0.0;
  duration = 0.0;
  totalDuration = 0.0;
  ((void (__thiscall *)(CSoundControllerImp *, CSoundPatch *, int, int))this->CommandClear)(
    a1: this,
    a2: pSound,
    a3,
    a4: a2);
  for ( i = 0; i < numPoints; totalDuration = totalDuration + duration )
  {
    amplitudeMin = points[i].amplitudeMin;
    v10 = &points[i];
    if ( amplitudeMin == -1.0 && v10->amplitudeMax == -1.0 )
    {
      if ( i == 0 )
        _Msg(a1: "Invalid starting amplitude value in envelope!  (Cannot be -1)\n");
    }
    else
    {
      amplitude = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                    a1: random,
                    a2: LODWORD(amplitudeMin),
                    a3: LODWORD(v10->amplitudeMax));
    }
    durationMin = v10->durationMin;
    if ( durationMin == -1.0 && v10->durationMax == -1.0 )
    {
      if ( i == 0 )
        _Msg(a1: "Invalid starting duration value in envelope! (Cannot be -1)\n");
    }
    else
    {
      duration = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                   a1: random,
                   a2: LODWORD(durationMin),
                   a3: LODWORD(v10->durationMax));
    }
    ((void (__thiscall *)(CSoundControllerImp *, CSoundPatch *, _DWORD, soundcommands_t, _DWORD, _DWORD))this->CommandAdd)(
      a1: this,
      a2: pSound,
      a3: LODWORD(totalDuration),
      a4: soundCommand,
      a5: LODWORD(duration),
      a6: LODWORD(amplitude));
    ++i;
  }
  return totalDuration;
}

//------------------------------------------------------------------------------
// Address: 0x1021D2A0
// Name: public: virtual float CSoundControllerImp::SoundPlayEnvelope(class CSoundPatch __near *,enum soundcommands_t,struct envelopeDescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CSoundControllerImp::SoundPlayEnvelope(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        soundcommands_t soundCommand,
        envelopeDescription_t *envelope)
{
  return this->SoundPlayEnvelope_2(this, a2: pSound, a3: soundCommand, a4: envelope->pPoints, a5: envelope->nNumPoints);
}

//------------------------------------------------------------------------------
// Address: 0x1021D2D0
// Name: public: static class CSoundEnvelopeController __near & CSoundEnvelopeController::GetController(void)
// Source: json
//------------------------------------------------------------------------------
CSoundControllerImp *__cdecl CSoundEnvelopeController::GetController()
{
  return &g_Controller;
}

//------------------------------------------------------------------------------
// Address: 0x1021D2E0
// Name: class ISaveRestoreOps __near * GetSoundSaveRestoreOps(void)
// Source: json
//------------------------------------------------------------------------------
CSoundPatchSaveRestoreOps *__cdecl GetSoundSaveRestoreOps()
{
  return &s_SoundPatchSaveRestoreOps;
}

//------------------------------------------------------------------------------
// Address: 0x1021D2F0
// Name: public: void CSoundPatch::ChangePitch(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPatch::ChangePitch(CSoundPatch *this, float pitchTarget, float deltaTime)
{
  float v3; // xmm0_4
  float v4; // xmm0_4
  double v5; // xmm1_8

  this->m_flags |= 2u;
  v3 = pitchTarget - this->m_pitch.m_current;
  if ( v3 == 0.0 || deltaTime <= 0.0 )
  {
    if ( pitchTarget != this->m_pitch.m_current )
      this->m_pitch.m_forceupdate = true;
    if ( this->m_pitch.m_target != pitchTarget )
      this->m_pitch.m_forceupdate = true;
    this->m_pitch.m_target = pitchTarget;
    this->m_pitch.m_current = pitchTarget;
    this->m_pitch.m_rate = 0.0;
  }
  else
  {
    this->m_pitch.m_target = pitchTarget;
    v4 = fabs(v3 / deltaTime);
    v5 = 0.1;
    if ( v4 >= 0.1 )
      v5 = v4;
    this->m_pitch.m_rate = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D390
// Name: public: void CSoundPatch::ChangeVolume(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPatch::ChangeVolume(CSoundPatch *this, float volumeTarget, float deltaTime)
{
  float v3; // xmm1_4
  float m_current; // xmm2_4
  float v5; // xmm0_4
  double v6; // xmm1_8

  v3 = volumeTarget;
  this->m_flags |= 1u;
  if ( volumeTarget > 1.0 )
    v3 = 1.0;
  m_current = this->m_volume.m_current;
  if ( (float)(v3 - m_current) == 0.0 || deltaTime <= 0.0 )
  {
    if ( v3 != m_current )
      this->m_volume.m_forceupdate = true;
    if ( this->m_volume.m_target != v3 )
      this->m_volume.m_forceupdate = true;
    this->m_volume.m_target = v3;
    this->m_volume.m_current = v3;
    this->m_volume.m_rate = 0.0;
  }
  else
  {
    this->m_volume.m_target = v3;
    v5 = fabs((float)(v3 - m_current) / deltaTime);
    v6 = 0.1;
    if ( v5 >= 0.1 )
      v6 = v5;
    this->m_volume.m_rate = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D440
// Name: public: virtual void CSoundControllerImp::SoundChangePitch(class CSoundPatch __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SoundChangePitch(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        float pitchTarget,
        float deltaTime)
{
  float v4; // xmm0_4
  float v5; // xmm0_4
  double v6; // xmm1_8

  pSound->m_flags |= 2u;
  v4 = pitchTarget - pSound->m_pitch.m_current;
  if ( v4 == 0.0 || deltaTime <= 0.0 )
  {
    if ( pitchTarget != pSound->m_pitch.m_current )
      pSound->m_pitch.m_forceupdate = true;
    if ( pSound->m_pitch.m_target != pitchTarget )
      pSound->m_pitch.m_forceupdate = true;
    pSound->m_pitch.m_target = pitchTarget;
    pSound->m_pitch.m_current = pitchTarget;
    pSound->m_pitch.m_rate = 0.0;
  }
  else
  {
    pSound->m_pitch.m_target = pitchTarget;
    v5 = fabs(v4 / deltaTime);
    v6 = 0.1;
    if ( v5 >= 0.1 )
      v6 = v5;
    pSound->m_pitch.m_rate = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D4E0
// Name: public: virtual void CSoundControllerImp::SoundChangeVolume(class CSoundPatch __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SoundChangeVolume(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        float volumeTarget,
        float deltaTime)
{
  float v4; // xmm1_4
  float m_current; // xmm2_4
  float v6; // xmm0_4
  double v7; // xmm1_8

  v4 = volumeTarget;
  pSound->m_flags |= 1u;
  if ( volumeTarget > 1.0 )
    v4 = 1.0;
  m_current = pSound->m_volume.m_current;
  if ( (float)(v4 - m_current) == 0.0 || deltaTime <= 0.0 )
  {
    if ( v4 != m_current )
      pSound->m_volume.m_forceupdate = true;
    if ( pSound->m_volume.m_target != v4 )
      pSound->m_volume.m_forceupdate = true;
    pSound->m_volume.m_target = v4;
    pSound->m_volume.m_current = v4;
    pSound->m_volume.m_rate = 0.0;
  }
  else
  {
    pSound->m_volume.m_target = v4;
    v6 = fabs((float)(v4 - m_current) / deltaTime);
    v7 = 0.1;
    if ( v6 >= 0.1 )
      v7 = v6;
    pSound->m_volume.m_rate = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D5A0
// Name: public: virtual void CSoundControllerImp::SoundFadeOut(class CSoundPatch __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SoundFadeOut(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        float deltaTime,
        bool destroyOnFadeout)
{
  float m_current; // xmm2_4
  float v5; // xmm0_4
  double v6; // xmm2_8

  if ( destroyOnFadeout && deltaTime == 0.0 )
  {
    this->SoundDestroy(this, a2: pSound);
  }
  else
  {
    pSound->m_flags |= 1u;
    m_current = pSound->m_volume.m_current;
    if ( COERCE_FLOAT(LODWORD(m_current) ^ _mask__NegFloat_) == 0.0 || deltaTime <= 0.0 )
    {
      if ( m_current != 0.0 )
        pSound->m_volume.m_forceupdate = true;
      if ( pSound->m_volume.m_target != 0.0 )
        pSound->m_volume.m_forceupdate = true;
      pSound->m_volume.m_target = 0.0;
      pSound->m_volume.m_current = 0.0;
      pSound->m_volume.m_rate = 0.0;
    }
    else
    {
      pSound->m_volume.m_target = 0.0;
      v5 = fabs(COERCE_FLOAT(LODWORD(m_current) ^ _mask__NegFloat_) / deltaTime);
      v6 = 0.1;
      if ( v5 >= 0.1 )
        v6 = v5;
      pSound->m_volume.m_rate = v6;
    }
    if ( destroyOnFadeout )
      ((void (__stdcall *)(CSoundPatch *, _DWORD, int, _DWORD, _DWORD))this->CommandAdd)(
        a1: pSound,
        a2: LODWORD(deltaTime),
        a3: 3,
        a4: 0,
        a5: 0);
    else
      pSound->m_shutdownTime = ((double (__thiscall *)(IEffects *))g_pEffects->Time)(a1: g_pEffects) + deltaTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D6A0
// Name: public: int CSoundPatch::EntIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundPatch::EntIndex(CSoundPatch *this)
{
  unsigned int m_Index; // ecx
  int v2; // eax
  CEntInfo *v3; // edx
  unsigned int v4; // ecx
  int v5; // eax
  bool v6; // zf
  CEntInfo *v7; // eax
  IHandleEntity *m_pEntity; // eax
  int result; // eax

  m_Index = this->m_hEnt.m_Index;
  if ( m_Index == -1 )
    return -1;
  v2 = (unsigned __int16)m_Index;
  v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v4 = HIWORD(m_Index);
  if ( v3->m_SerialNumber != v4 || v3->m_pEntity == nullptr )
    return -1;
  v5 = v2;
  v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4;
  v7 = &g_pEntityList->m_EntPtrArray[v5];
  if ( v6 )
    m_pEntity = v7->m_pEntity;
  else
    m_pEntity = nullptr;
  result = (int)m_pEntity[6].__vftable;
  if ( result != 0 )
    return (signed int)(result - (unsigned int)gpGlobals->pEdicts) >> 4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021D700
// Name: public: void CSoundPatch::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPatch::Shutdown(CSoundPatch *this)
{
  unsigned int m_Index; // eax
  int m_soundEntityIndex; // eax
  const char *v4; // ecx
  const char *pszValue; // ecx

  if ( this->m_isPlaying == 0 )
    return;
  m_Index = this->m_hEnt.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    m_soundEntityIndex = CSoundPatch::EntIndex(this);
  }
  else
  {
    m_soundEntityIndex = this->m_soundEntityIndex;
  }
  if ( m_soundEntityIndex < 0 )
  {
LABEL_15:
    this->m_isPlaying = 0;
    return;
  }
  if ( this->m_hSoundScriptHandle <= -1 )
  {
    pszValue = this->m_iszSoundName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CBaseEntity::StopSound(
      iEntIndex: m_soundEntityIndex,
      iChannel: this->m_entityChannel,
      pSample: pszValue,
      bIsStoppingSpeakerSound: 0);
    goto LABEL_15;
  }
  v4 = this->m_iszSoundScriptName.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  CBaseEntity::StopSound(iEntIndex: m_soundEntityIndex, soundname: v4);
  this->m_isPlaying = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021D910
// Name: public: virtual void CSoundControllerImp::CommandClear(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::CommandClear(CSoundControllerImp *this, CSoundPatch *pSound)
{
  int v3; // edi
  SoundCommand_t *v4; // ebx
  int m_Size; // eax
  int v6; // eax
  int v7; // ebx
  int v8; // ebx
  SoundCommand_t **m_pMemory; // eax
  SoundCommand_t *v10; // ecx
  SoundCommand_t *pCmd; // [esp+8h] [ebp-14h]
  int v12; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  v3 = this->m_commandList.m_heap.m_Size - 1;
  for ( i = v3; v3 >= 0; i = v3 )
  {
    v4 = this->m_commandList.m_heap.m_Memory.m_pMemory[v3];
    pCmd = v4;
    if ( v4->m_pPatch == pSound )
    {
      m_Size = this->m_commandList.m_heap.m_Size;
      v15 = v3;
      if ( m_Size > 0 )
      {
        if ( v3 != m_Size - 1 )
          this->m_commandList.m_heap.m_Memory.m_pMemory[v3] = this->m_commandList.m_heap.m_Memory.m_pMemory[m_Size - 1];
        --this->m_commandList.m_heap.m_Size;
      }
      v6 = this->m_commandList.m_heap.m_Size;
      v14 = v6;
      if ( v6 != 0 )
      {
        v12 = v6 / 2;
        if ( v3 < v6 / 2 )
        {
          do
          {
            v7 = 2 * v15 + 1;
            if ( v7 < v14
              && this->m_commandList.m_LessFunc(
                   a1: &this->m_commandList.m_heap.m_Memory.m_pMemory[v15],
                   a2: &this->m_commandList.m_heap.m_Memory.m_pMemory[v7]) )
            {
              v3 = 2 * v15 + 1;
            }
            v8 = 2 * v15 + 2;
            if ( v8 < v14
              && this->m_commandList.m_LessFunc(
                   a1: &this->m_commandList.m_heap.m_Memory.m_pMemory[v3],
                   a2: &this->m_commandList.m_heap.m_Memory.m_pMemory[v8]) )
            {
              v3 = 2 * v15 + 2;
            }
            if ( v3 == v15 )
              break;
            m_pMemory = this->m_commandList.m_heap.m_Memory.m_pMemory;
            v10 = m_pMemory[v15];
            m_pMemory[v15] = m_pMemory[v3];
            this->m_commandList.m_heap.m_Memory.m_pMemory[v3] = v10;
            v15 = v3;
          }
          while ( v3 < v12 );
          v4 = pCmd;
          v3 = i;
        }
      }
      CUtlMemoryPool::Free(this: &SoundCommand_t::s_Allocator, memBlock: v4);
    }
    --v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021DA10
// Name: public: virtual void CSoundPatchSaveRestoreOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSoundPatchSaveRestoreOps::Save(
        CSoundPatchSaveRestoreOps *this@<ecx>,
        ISave **p_pSave@<edi>,
        CSoundPatch **fieldInfo,
        ISave *pSave)
{
  ISave *v4; // esi
  int v5; // eax
  CSoundPatch *v6; // edi
  int v7; // eax
  int i; // ebx
  SoundCommand_t *v9; // edi
  int v11; // [esp+0h] [ebp-10h]
  CSoundPatch *v12; // [esp+8h] [ebp-8h]
  int nSoundPatchCount; // [esp+Ch] [ebp-4h]
  CSoundPatch **ppSoundPatch; // [esp+18h] [ebp+8h]

  v4 = pSave;
  pSave->StartBlock(this: pSave);
  v5 = *(unsigned __int16 *)&fieldInfo[2]->m_pitch.m_forceupdate - 1;
  ppSoundPatch = (CSoundPatch **)*fieldInfo;
  for ( nSoundPatchCount = v5; nSoundPatchCount >= 0; --nSoundPatchCount )
  {
    v6 = *ppSoundPatch;
    v12 = *ppSoundPatch;
    ((void (__thiscall *)(ISave *, ISave **))v4->StartBlock)(a1: v4, a2: p_pSave);
    v4->WriteAll(this: v4, a2: v6, a3: &CSoundPatch::m_DataMap);
    v4->EndBlock(this: v4);
    v7 = g_Controller.m_commandList.m_heap.m_Size - 1;
    for ( pSave = nullptr; v7 >= 0; --v7 )
    {
      if ( g_Controller.m_commandList.m_heap.m_Memory.m_pMemory[v7]->m_pPatch == v6 )
        pSave = (ISave *)((char *)pSave + 1);
    }
    ((void (__thiscall *)(ISave *, int))v4->StartBlock)(a1: v4, a2: v11);
    v11 = 1;
    p_pSave = &pSave;
    ((void (__thiscall *)(ISave *))v4->WriteInt_2)(a1: v4);
    for ( i = g_Controller.m_commandList.m_heap.m_Size - 1; i >= 0; --i )
    {
      v9 = g_Controller.m_commandList.m_heap.m_Memory.m_pMemory[i];
      if ( v9->m_pPatch == v12 )
      {
        v4->StartBlock(this: v4);
        v4->WriteAll(this: v4, a2: v9, a3: &SoundCommand_t::m_DataMap);
        v4->EndBlock(this: v4);
      }
    }
    v4->EndBlock(this: v4);
    ++ppSoundPatch;
  }
  v4->EndBlock(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1021DB20
// Name: public: virtual bool CCopyRecipientFilter::IsReliable(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCopyRecipientFilter::IsReliable(CCopyRecipientFilter *this)
{
  return (this->m_Flags & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021DB30
// Name: public: virtual bool CCopyRecipientFilter::IsInitMessage(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCopyRecipientFilter::IsInitMessage(CCopyRecipientFilter *this)
{
  return (this->m_Flags & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021DB40
// Name: public: virtual int CCopyRecipientFilter::GetRecipientIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCopyRecipientFilter::GetRecipientIndex(CCopyRecipientFilter *this, int slot)
{
  return this->m_Recipients.m_Memory.m_pMemory[slot];
}

//------------------------------------------------------------------------------
// Address: 0x1021DB50
// Name: public: CSoundPatch::CSoundPatch(void)
// Source: json
//------------------------------------------------------------------------------
CSoundPatch *__thiscall CSoundPatch::CSoundPatch(CSoundPatch *this)
{
  this->m_pitch.m_current = 0.0;
  this->m_pitch.m_target = 0.0;
  this->m_pitch.m_rate = 0.0;
  this->m_pitch.m_forceupdate = false;
  this->m_volume.m_current = 0.0;
  this->m_volume.m_target = 0.0;
  this->m_volume.m_rate = 0.0;
  this->m_volume.m_forceupdate = false;
  this->m_hEnt.m_Index = -1;
  this->m_Filter.__vftable = (CCopyRecipientFilter_vtbl *)&CCopyRecipientFilter::`vftable';
  this->m_Filter.m_Flags = 0;
  this->m_Filter.m_Recipients.m_Memory.m_pMemory = nullptr;
  this->m_Filter.m_Recipients.m_Memory.m_nAllocationCount = 0;
  this->m_Filter.m_Recipients.m_Memory.m_nGrowSize = 0;
  this->m_Filter.m_Recipients.m_Size = 0;
  this->m_Filter.m_Recipients.m_pElements = nullptr;
  ++CSoundPatch::g_SoundPatchCount;
  this->m_iszSoundName.pszValue = nullptr;
  this->m_iszSoundScriptName.pszValue = nullptr;
  this->m_flCloseCaptionDuration = soundpatch_captionlength.m_pParent->m_Value.m_fValue;
  this->m_soundOrigin.x = 0.0;
  this->m_soundOrigin.y = 0.0;
  this->m_soundOrigin.z = 0.0;
  this->m_soundEntityIndex = -1;
  this->m_guid = -1;
  this->m_hSoundScriptHandle = -1;
  this->m_nSoundEntryVersion = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1021DBE0
// Name: public: virtual void CSoundControllerImp::SystemReset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SystemReset(CSoundControllerImp *this)
{
  int i; // edi

  for ( i = this->m_soundList.m_Size - 1; i >= 0; --i )
    CSoundPatch::Shutdown(this: this->m_soundList.m_Memory.m_pMemory[i]);
  this->m_soundList.m_Size = 0;
  if ( this->m_soundList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_soundList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_soundList.m_Memory.m_pMemory);
      this->m_soundList.m_Memory.m_pMemory = nullptr;
    }
    this->m_soundList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_soundList.m_pElements = this->m_soundList.m_Memory.m_pMemory;
  this->m_commandList.m_heap.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1021DC40
// Name: public: virtual void CSoundControllerImp::Shutdown(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::Shutdown(CSoundControllerImp *this, CSoundPatch *pSound)
{
  CSoundPatch *v2; // esi

  v2 = pSound;
  if ( pSound != nullptr )
  {
    CSoundPatch::Shutdown(this: pSound);
    this->CommandClear(this, a2: v2);
    pSound = v2;
    CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_soundList,
      src: (vgui::TreeNode **)&pSound);
    CSoundPatch::Shutdown(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021DC80
// Name: public: virtual void CSoundControllerImp::SoundDestroy(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SoundDestroy(CSoundControllerImp *this, CSoundPatch *pSound)
{
  if ( pSound != nullptr )
  {
    this->Shutdown(this, a2: pSound);
    --CSoundPatch::g_SoundPatchCount;
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pSound->m_Filter.m_Recipients);
    pSound->m_Filter.__vftable = (CCopyRecipientFilter_vtbl *)&IRecipientFilter::`vftable';
    CUtlMemoryPool::Free(this: &CSoundPatch::s_Allocator, memBlock: pSound);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021DCF0
// Name: public: void CSoundControllerImp::ProcessCommand(struct SoundCommand_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::ProcessCommand(CSoundControllerImp *this, CSoundPatch *pCmd)
{
  SoundCommand_t *v2; // esi
  CSoundPatch *v3; // edi
  CSoundPatch *m_pPatch; // edi

  v2 = (SoundCommand_t *)pCmd;
  switch ( *(_DWORD *)&pCmd->m_pitch.m_forceupdate )
  {
    case 0:
      CSoundPatch::ChangeVolume(
        this: (CSoundPatch *)LODWORD(pCmd->m_pitch.m_current),
        volumeTarget: pCmd->m_volume.m_current,
        deltaTime: pCmd->m_pitch.m_rate);
      break;
    case 1:
      CSoundPatch::ChangePitch(
        this: (CSoundPatch *)LODWORD(pCmd->m_pitch.m_current),
        pitchTarget: pCmd->m_volume.m_current,
        deltaTime: pCmd->m_pitch.m_rate);
      break;
    case 2:
      CSoundPatch::Shutdown(this: (CSoundPatch *)LODWORD(pCmd->m_pitch.m_current));
      break;
    case 3:
      pCmd = (CSoundPatch *)LODWORD(pCmd->m_pitch.m_current);
      v3 = pCmd;
      CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_soundList,
        src: (vgui::TreeNode **)&pCmd);
      CSoundPatch::Shutdown(this: v3);
      m_pPatch = v2->m_pPatch;
      if ( v2->m_pPatch != nullptr )
      {
        --CSoundPatch::g_SoundPatchCount;
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pPatch->m_Filter.m_Recipients);
        m_pPatch->m_Filter.__vftable = (CCopyRecipientFilter_vtbl *)&IRecipientFilter::`vftable';
        CUtlMemoryPool::Free(this: &CSoundPatch::s_Allocator, memBlock: m_pPatch);
      }
      v2->m_pPatch = nullptr;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021DE40
// Name: public: void CCopyRecipientFilter::Init(class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCopyRecipientFilter::Init(CCopyRecipientFilter *this, IRecipientFilter *pSrc)
{
  CCopyRecipientFilter *v3; // esi
  int v4; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // ecx
  int *v10; // eax
  int index; // [esp+Ch] [ebp-8h]
  int i; // [esp+1Ch] [ebp+8h]

  v3 = this;
  this->m_Flags = 1;
  if ( pSrc->IsReliable(this: pSrc) )
    v3->m_Flags |= 2u;
  if ( pSrc->IsInitMessage(this: pSrc) )
    v3->m_Flags |= 4u;
  v4 = 0;
  for ( i = 0; i < pSrc->GetRecipientCount(this: pSrc); v4 = i )
  {
    index = pSrc->GetRecipientIndex(this: pSrc, a2: v4);
    if ( index >= 0 )
    {
      m_Size = v3->m_Recipients.m_Size;
      m_nAllocationCount = v3->m_Recipients.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&v3->m_Recipients,
          num: m_Size - m_nAllocationCount + 1);
      ++v3->m_Recipients.m_Size;
      m_pMemory = v3->m_Recipients.m_Memory.m_pMemory;
      v8 = v3->m_Recipients.m_Size - m_Size - 1;
      v3->m_Recipients.m_pElements = m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
      v9 = v3->m_Recipients.m_Memory.m_pMemory;
      v3 = this;
      v10 = &v9[m_Size];
      if ( v10 != nullptr )
        *v10 = index;
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021DF20
// Name: public: virtual bool CCopyRecipientFilter::AddRecipient(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCopyRecipientFilter::AddRecipient(CCopyRecipientFilter *this, CBasePlayer *player)
{
  edict_t *m_pPev; // eax
  signed int v3; // ebx
  CUtlMemory<vgui::TreeNode *,int> *p_m_Recipients; // esi
  int m_Size; // ecx
  int v6; // eax
  vgui::TreeNode **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  signed int *v12; // eax

  m_pPev = player->m_Network.m_pPev;
  if ( m_pPev != nullptr )
  {
    v3 = m_pPev - gpGlobals->pEdicts;
    if ( v3 < 0 )
      return 0;
  }
  else
  {
    v3 = 0;
  }
  p_m_Recipients = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Recipients;
  m_Size = this->m_Recipients.m_Size;
  v6 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = p_m_Recipients->m_pMemory;
    while ( *m_pMemory != (vgui::TreeNode *)v3 )
    {
      ++v6;
      ++m_pMemory;
      if ( v6 >= m_Size )
        goto LABEL_7;
    }
    if ( v6 != -1 )
      return 0;
  }
LABEL_7:
  m_nAllocationCount = p_m_Recipients->m_nAllocationCount;
  v9 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Recipients, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Recipients[1].m_pMemory;
  v10 = p_m_Recipients->m_pMemory;
  v11 = (int)p_m_Recipients[1].m_pMemory - v9 - 1;
  p_m_Recipients[1].m_nAllocationCount = (int)p_m_Recipients->m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &v10[v9 + 1], src: &v10[v9], count: 4 * v11);
  v12 = (signed int *)&p_m_Recipients->m_pMemory[v9];
  if ( v12 != nullptr )
    *v12 = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021E150
// Name: public: void CSoundPatch::Init(class IRecipientFilter __near *,class CBaseEntity __near *,int,char const __near *,enum soundlevel_t,class Vector const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPatch::Init(
        CSoundPatch *this,
        IRecipientFilter *pFilter,
        CBaseEntity *pEnt,
        int channel,
        char *pSoundName,
        soundlevel_t soundlevel,
        const Vector *pSoundOrigin,
        float scriptVolume)
{
  CBaseEntity *v8; // edi
  edict_t *m_pPev; // eax
  signed int v11; // eax
  char *soundname; // edi
  string_t v13; // eax
  __int16 m_hSoundScriptHandle; // cx
  int m_nSoundEntryVersion; // edx
  soundlevel_t v16; // eax
  bool v17; // cc
  string_t v18; // eax
  soundlevel_t v19; // ecx
  float v20; // xmm0_4
  const Vector *v21; // eax
  const char *v22; // [esp-8h] [ebp-C8h]
  CSoundParameters params; // [esp+Ch] [ebp-B4h] BYREF

  v8 = pEnt;
  if ( pEnt != nullptr )
  {
    this->m_hEnt.m_Index = pEnt->GetRefEHandle(this: pEnt)->m_Index;
    m_pPev = v8->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      v11 = m_pPev - gpGlobals->pEdicts;
    else
      v11 = 0;
    this->m_soundEntityIndex = v11;
  }
  else
  {
    this->m_hEnt.m_Index = -1;
  }
  soundname = pSoundName;
  params.pitch = 100;
  params.pitchlow = 100;
  params.pitchhigh = 100;
  v22 = pSoundName;
  this->m_entityChannel = channel;
  params.channel = 0;
  params.volume = 1.0;
  params.soundlevel = SNDLVL_NORM;
  params.soundname[0] = 0;
  params.play_to_owner_only = false;
  params.count = 0;
  params.delay_msec = 0;
  params.m_nSoundEntryVersion = 1;
  params.m_hSoundScriptHandle = -1;
  params.m_pOperatorsKV = nullptr;
  params.m_nRandomSeed = -1;
  if ( V_stristr(pStr: v22, pSearch: ".wav") != nullptr
    || V_stristr(pStr: soundname, pSearch: ".mp3") != nullptr
    || !CBaseEntity::GetParametersForSound(soundname, &params, actormodel: nullptr) )
  {
    v18.pszValue = AllocPooledString(pszValue: (char *)&pEnt, pszValuea: soundname).pszValue;
    v19 = soundlevel;
    v20 = scriptVolume;
    this->m_iszSoundScriptName.pszValue = *(const char **)v18.pszValue;
    this->m_flScriptVolume = v20;
    this->m_soundlevel = v19;
  }
  else
  {
    this->m_flScriptVolume = params.volume;
    v13.pszValue = AllocPooledString(pszValue: (char *)&pEnt, pszValuea: soundname).pszValue;
    m_hSoundScriptHandle = params.m_hSoundScriptHandle;
    m_nSoundEntryVersion = params.m_nSoundEntryVersion;
    this->m_iszSoundScriptName.pszValue = *(const char **)v13.pszValue;
    v16 = params.soundlevel;
    v17 = this->m_entityChannel < 135;
    this->m_hSoundScriptHandle = m_hSoundScriptHandle;
    this->m_nSoundEntryVersion = m_nSoundEntryVersion;
    soundname = params.soundname;
    this->m_soundlevel = v16;
    if ( v17 )
      this->m_entityChannel = params.channel;
  }
  this->m_iszSoundName.pszValue = *(const char **)AllocPooledString(pszValue: (char *)&pEnt, pszValuea: soundname).pszValue;
  if ( this->m_volume.m_target != 0.0 )
    this->m_volume.m_forceupdate = true;
  this->m_volume.m_target = 0.0;
  this->m_volume.m_current = 0.0;
  this->m_volume.m_rate = 0.0;
  if ( this->m_pitch.m_target != 0.0 )
    this->m_pitch.m_forceupdate = true;
  *(_QWORD *)&this->m_pitch.m_current = 0;
  this->m_pitch.m_rate = 0.0;
  this->m_isPlaying = 0;
  this->m_shutdownTime = 0.0;
  CCopyRecipientFilter::Init(this: &this->m_Filter, pSrc: pFilter);
  v21 = pSoundOrigin;
  this->m_baseFlags = 0;
  if ( v21 != nullptr )
  {
    this->m_soundOrigin.x = v21->x;
    this->m_soundOrigin.y = v21->y;
    this->m_soundOrigin.z = v21->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021E340
// Name: public: bool CSoundPatch::Update(float,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundPatch::Update(CSoundPatch *this, float time, float deltaTime)
{
  float m_shutdownTime; // xmm0_4
  const char *pszValue; // esi
  float m_target; // xmm3_4
  float m_current; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  int m_flags; // eax
  int v15; // edx
  float v16; // xmm0_4
  int v17; // eax
  __int16 m_hSoundScriptHandle; // cx
  int m_nSoundEntryVersion; // edx
  int v20; // eax
  EmitSound_t ep; // [esp+4h] [ebp-48h] BYREF

  m_shutdownTime = this->m_shutdownTime;
  if ( m_shutdownTime != 0.0 && time > m_shutdownTime )
  {
    CSoundPatch::Shutdown(this);
    return 0;
  }
  if ( CSoundPatch::EntIndex(this) < 0 )
  {
    pszValue = this->m_iszSoundName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    DevWarning(a1: "CSoundPatch::Update:  Removing CSoundPatch (%s) with NULL EHandle\n", pszValue);
    return 0;
  }
  if ( this->m_pitch.m_forceupdate )
  {
    this->m_pitch.m_forceupdate = false;
  }
  else if ( this->m_pitch.m_current == this->m_pitch.m_target )
  {
    this->m_flags &= ~2u;
    goto LABEL_17;
  }
  m_target = this->m_pitch.m_target;
  m_current = this->m_pitch.m_current;
  v9 = this->m_pitch.m_rate * deltaTime;
  v10 = m_target - this->m_pitch.m_current;
  if ( v10 <= v9 )
  {
    this->m_flags |= 2u;
    if ( (float)-v9 <= v10 )
      this->m_pitch.m_current = m_target;
    else
      this->m_pitch.m_current = m_current - v9;
  }
  else
  {
    this->m_flags |= 2u;
    this->m_pitch.m_current = m_current + v9;
  }
LABEL_17:
  if ( this->m_volume.m_forceupdate )
  {
    this->m_volume.m_forceupdate = false;
  }
  else if ( this->m_volume.m_current == this->m_volume.m_target )
  {
    this->m_flags &= ~1u;
LABEL_27:
    m_flags = this->m_flags;
    if ( m_flags != 0 )
    {
      this->m_flags = m_flags | 1;
      EmitSound_t::EmitSound_t(this: &ep);
      ep.m_nChannel = this->m_entityChannel;
      ep.m_pSoundName = this->m_iszSoundName.pszValue;
      if ( ep.m_pSoundName == nullptr )
        ep.m_pSoundName = locale;
      v15 = this->m_flags;
      v16 = this->m_flScriptVolume * this->m_volume.m_current;
      v17 = (int)this->m_pitch.m_current;
      ep.m_SoundLevel = this->m_soundlevel;
      m_hSoundScriptHandle = this->m_hSoundScriptHandle;
      ep.m_nFlags = v15;
      m_nSoundEntryVersion = this->m_nSoundEntryVersion;
      ep.m_hSoundScriptHandle = m_hSoundScriptHandle;
      ep.m_flVolume = v16;
      ep.m_nPitch = v17;
      ep.m_nSoundEntryVersion = m_nSoundEntryVersion;
      if ( CSoundPatch::EntIndex(this) == 0 )
        ep.m_pOrigin = &this->m_soundOrigin;
      v20 = CSoundPatch::EntIndex(this);
      CBaseEntity::EmitSound(filter: (CRecipientFilter *)&this->m_Filter, iEntIndex: v20, params: &ep);
      this->m_flags = 0;
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    }
    return 1;
  }
  v11 = this->m_volume.m_current;
  v12 = this->m_volume.m_rate * deltaTime;
  v13 = this->m_volume.m_target - v11;
  if ( v13 <= v12 )
  {
    if ( (float)-v12 <= v13 )
      this->m_volume.m_current = this->m_volume.m_target;
    else
      this->m_volume.m_current = v11 - v12;
    this->m_flags |= 1u;
  }
  else
  {
    this->m_volume.m_current = v11 + v12;
    this->m_flags |= 1u;
  }
  goto LABEL_27;
}

//------------------------------------------------------------------------------
// Address: 0x1021E540
// Name: public: void CSoundPatch::StartSound(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPatch::StartSound(CSoundPatch *this, float flStartTime)
{
  bool v3; // zf
  int m_entityChannel; // eax
  const char *pszValue; // edi
  __int16 m_hSoundScriptHandle; // dx
  int m_nSoundEntryVersion; // eax
  float v8; // xmm0_4
  int m_baseFlags; // eax
  int m_current; // edx
  int v11; // eax
  const char *v12; // eax
  int v13; // eax
  const char *v14; // [esp-8h] [ebp-64h]
  float duration; // [esp+0h] [ebp-5Ch]
  EmitSound_t ep; // [esp+14h] [ebp-48h] BYREF

  v3 = (this->m_Filter.m_Flags & 1) == 0;
  this->m_flags = 0;
  if ( !v3 )
  {
    m_entityChannel = this->m_entityChannel;
    pszValue = this->m_iszSoundName.pszValue;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    memset(&ep.m_pOrigin, 0, 12);
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_nChannel = m_entityChannel;
    ep.m_pSoundName = pszValue;
    if ( pszValue == nullptr )
      ep.m_pSoundName = locale;
    m_hSoundScriptHandle = this->m_hSoundScriptHandle;
    m_nSoundEntryVersion = this->m_nSoundEntryVersion;
    v8 = this->m_flScriptVolume * this->m_volume.m_current;
    ep.m_SoundLevel = this->m_soundlevel;
    ep.m_flVolume = v8;
    ep.m_hSoundScriptHandle = m_hSoundScriptHandle;
    ep.m_nSoundEntryVersion = m_nSoundEntryVersion;
    if ( CSoundPatch::EntIndex(this) == 0 )
      ep.m_pOrigin = &this->m_soundOrigin;
    if ( pszValue == nullptr )
      pszValue = locale;
    v3 = V_stristr(pStr: pszValue, pSearch: "music") == nullptr;
    m_baseFlags = this->m_baseFlags;
    if ( v3 )
      m_baseFlags |= 1u;
    m_current = (int)this->m_pitch.m_current;
    ep.m_nFlags = m_baseFlags | 0x1000;
    ep.m_nPitch = m_current;
    ep.m_bEmitCloseCaption = false;
    if ( flStartTime != 0.0 )
      ep.m_flSoundTime = flStartTime;
    v11 = CSoundPatch::EntIndex(this);
    CBaseEntity::EmitSound(filter: (CRecipientFilter *)&this->m_Filter, iEntIndex: v11, params: &ep);
    v12 = this->m_iszSoundScriptName.pszValue;
    if ( v12 == nullptr )
      v12 = locale;
    duration = this->m_flCloseCaptionDuration;
    v14 = v12;
    v13 = CSoundPatch::EntIndex(this);
    CBaseEntity::EmitCloseCaption(
      filter: (CRecipientFilter *)&this->m_Filter,
      entindex: v13,
      token: v14,
      soundorigin: &ep.m_UtlVecSoundOrigin,
      duration,
      warnifmissing: true);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
  }
  this->m_isPlaying = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021E710
// Name: public: virtual struct string_t CSoundControllerImp::SoundGetName(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
string_t __thiscall CSoundControllerImp::SoundGetName(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        CSoundPatch *pSounda)
{
  LODWORD(pSound->m_pitch.m_current) = pSounda->m_iszSoundName.pszValue;
  return (string_t)pSound;
}

//------------------------------------------------------------------------------
// Address: 0x1021E730
// Name: public: virtual struct string_t CSoundControllerImp::SoundGetScriptName(class CSoundPatch __near *)
// Source: json
//------------------------------------------------------------------------------
string_t __thiscall CSoundControllerImp::SoundGetScriptName(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        CSoundPatch *pSounda)
{
  LODWORD(pSound->m_pitch.m_current) = pSounda->m_iszSoundScriptName.pszValue;
  return (string_t)pSound;
}

//------------------------------------------------------------------------------
// Address: 0x1021E750
// Name: public: virtual void CSoundControllerImp::SoundSetCloseCaptionDuration(class CSoundPatch __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SoundSetCloseCaptionDuration(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        float flDuration)
{
  pSound->m_flCloseCaptionDuration = flDuration;
}

//------------------------------------------------------------------------------
// Address: 0x1021E770
// Name: public: virtual void CSoundControllerImp::PreClientUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::PreClientUpdate(CSoundControllerImp *this)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 4))(a1: (char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x1021E780
// Name: public: virtual void CSoundControllerImp::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::LevelShutdownPreEntity(CSoundControllerImp *this)
{
  (**((void (__thiscall ***)(char *))this - 1))(a1: (char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x1021E7E0
// Name: public: virtual void CSoundControllerImp::Play(class CSoundPatch __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::Play(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        float volume,
        float pitch,
        float flStartTime)
{
  float v5; // xmm0_4
  bool v6; // zf
  int m_nAllocationCount; // eax
  int m_Size; // ebx
  CUtlMemory<vgui::TreeNode *,int> *p_m_soundList; // esi
  vgui::TreeNode **m_pMemory; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // ebx

  v5 = volume;
  pSound->m_flags |= 1u;
  pSound->m_shutdownTime = 0.0;
  if ( volume > 1.0 )
    v5 = 1.0;
  if ( v5 != pSound->m_volume.m_current )
    pSound->m_volume.m_forceupdate = true;
  if ( pSound->m_volume.m_target != v5 )
    pSound->m_volume.m_forceupdate = true;
  pSound->m_volume.m_target = v5;
  pSound->m_volume.m_current = v5;
  pSound->m_volume.m_rate = 0.0;
  pSound->m_flags |= 2u;
  if ( pitch != pSound->m_pitch.m_current )
    pSound->m_pitch.m_forceupdate = true;
  if ( pSound->m_pitch.m_target != pitch )
    pSound->m_pitch.m_forceupdate = true;
  v6 = pSound->m_isPlaying == 0;
  pSound->m_pitch.m_target = pitch;
  pSound->m_pitch.m_current = pitch;
  pSound->m_pitch.m_rate = 0.0;
  if ( v6 )
  {
    m_nAllocationCount = this->m_soundList.m_Memory.m_nAllocationCount;
    m_Size = this->m_soundList.m_Size;
    p_m_soundList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_soundList;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_soundList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_soundList[1].m_pMemory;
    m_pMemory = p_m_soundList->m_pMemory;
    v11 = (int)p_m_soundList[1].m_pMemory - m_Size - 1;
    p_m_soundList[1].m_nAllocationCount = (int)p_m_soundList->m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
    v12 = &p_m_soundList->m_pMemory[m_Size];
    if ( v12 != nullptr )
      *v12 = (vgui::TreeNode *)pSound;
    CSoundPatch::StartSound(this: pSound, flStartTime);
  }
  else
  {
    this->CommandClear(this, a2: pSound);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021E8F0
// Name: public: virtual void CSoundControllerImp::CommandAdd(class CSoundPatch __near *,float,enum soundcommands_t,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::CommandAdd(
        CSoundControllerImp *this,
        CSoundPatch *pSound,
        float executeDeltaTime,
        soundcommands_t command,
        float commandTime,
        float commandValue)
{
  float v7; // esi
  double v8; // st7
  float v9; // xmm0_4
  soundcommands_t v10; // ecx
  float v11; // xmm0_4

  v7 = COERCE_FLOAT(CUtlMemoryPool::Alloc(this: &SoundCommand_t::s_Allocator, amount: 0x18u));
  if ( v7 == 0.0 )
  {
    v7 = 0.0;
  }
  else
  {
    v8 = ((double (__thiscall *)(IEffects *))g_pEffects->Time)(a1: g_pEffects);
    v9 = commandTime;
    v10 = command;
    *(float *)(LODWORD(v7) + 4) = v8 + executeDeltaTime;
    *(float *)(LODWORD(v7) + 8) = v9;
    v11 = commandValue;
    *(_DWORD *)LODWORD(v7) = pSound;
    *(_DWORD *)(LODWORD(v7) + 12) = v10;
    *(float *)(LODWORD(v7) + 16) = v11;
  }
  executeDeltaTime = v7;
  CUtlPriorityQueue<CEventRegister *,CDefUtlPriorityQueueLessFunc<CEventRegister *>,CUtlMemory<CEventRegister *,int>>::Insert(
    this: &this->m_commandList,
    element: (SoundCommand_t *const *)&executeDeltaTime);
}

//------------------------------------------------------------------------------
// Address: 0x1021E960
// Name: public: virtual void CSoundControllerImp::SystemUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::SystemUpdate(CSoundControllerImp *this)
{
  bool v2; // zf
  SoundCommand_t **m_pMemory; // eax
  CSoundPatch *v4; // edi
  int i; // edi
  CSoundPatch *v6; // ebx
  int m_Size; // eax
  float deltaTime; // [esp+14h] [ebp-8h]
  float time; // [esp+18h] [ebp-4h]

  time = g_pEffects->Time(this: g_pEffects);
  deltaTime = time - this->m_flLastTime;
  if ( deltaTime < 0.0 )
    deltaTime = 0.0;
  v2 = this->m_commandList.m_heap.m_Size == 0;
  this->m_flLastTime = time;
  if ( !v2 )
  {
    do
    {
      m_pMemory = this->m_commandList.m_heap.m_Memory.m_pMemory;
      v4 = (CSoundPatch *)*m_pMemory;
      if ( time < (*m_pMemory)->m_time )
        break;
      CUtlPriorityQueue<CEventRegister *,CDefUtlPriorityQueueLessFunc<CEventRegister *>,CUtlMemory<CEventRegister *,int>>::RemoveAtHead(this: &this->m_commandList);
      CSoundControllerImp::ProcessCommand(this, pCmd: v4);
      CUtlMemoryPool::Free(this: &SoundCommand_t::s_Allocator, memBlock: v4);
    }
    while ( this->m_commandList.m_heap.m_Size != 0 );
  }
  for ( i = this->m_soundList.m_Size - 1; i >= 0; --i )
  {
    v6 = this->m_soundList.m_Memory.m_pMemory[i];
    if ( CSoundPatch::Update(this: v6, time, deltaTime) == 0 )
    {
      v6->m_shutdownTime = 0.0;
      m_Size = this->m_soundList.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_soundList.m_Memory.m_pMemory[i] = this->m_soundList.m_Memory.m_pMemory[m_Size - 1];
        --this->m_soundList.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021EA40
// Name: public: virtual class CSoundPatch __near * CSoundControllerImp::SoundCreate(class IRecipientFilter __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSoundPatch *__thiscall CSoundControllerImp::SoundCreate(
        CSoundControllerImp *this,
        IRecipientFilter *filter,
        int nEntIndex,
        char *pSoundName)
{
  CSoundPatch *v4; // eax
  CSoundPatch *v5; // esi
  CBaseEntity *m_pEntity; // ecx
  unsigned int nEntIndexa; // [esp+14h] [ebp+Ch]

  v4 = (CSoundPatch *)CUtlMemoryPool::Alloc(this: &CSoundPatch::s_Allocator, amount: 0x84u);
  if ( v4 != nullptr )
    v5 = CSoundPatch::CSoundPatch(this: v4);
  else
    v5 = nullptr;
  if ( nEntIndex == -1 )
  {
    nEntIndexa = 0;
  }
  else if ( g_pEntityList->m_EntPtrArray[nEntIndex].m_pEntity != nullptr )
  {
    nEntIndexa = nEntIndex | (g_pEntityList->m_EntPtrArray[nEntIndex].m_SerialNumber << 16);
  }
  else
  {
    nEntIndexa = -1;
  }
  if ( nEntIndexa == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_SerialNumber != HIWORD(nEntIndexa) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_pEntity;
  }
  CSoundPatch::Init(
    this: v5,
    pFilter: filter,
    pEnt: m_pEntity,
    channel: 0,
    pSoundName,
    soundlevel: SNDLVL_NORM,
    pSoundOrigin: nullptr,
    scriptVolume: 1.0);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1021EAF0
// Name: public: virtual class CSoundPatch __near * CSoundControllerImp::SoundCreate(class IRecipientFilter __near &,int,int,char const __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
CSoundPatch *__thiscall CSoundControllerImp::SoundCreate(
        CSoundControllerImp *this,
        IRecipientFilter *filter,
        int nEntIndex,
        int channel,
        char *pSoundName,
        float attenuation,
        float scriptVolume)
{
  CSoundPatch *v7; // eax
  CSoundPatch *v8; // esi
  float v9; // xmm0_4
  CBaseEntity *m_pEntity; // eax
  unsigned int nEntIndexa; // [esp+14h] [ebp+Ch]

  v7 = (CSoundPatch *)CUtlMemoryPool::Alloc(this: &CSoundPatch::s_Allocator, amount: 0x84u);
  if ( v7 != nullptr )
    v8 = CSoundPatch::CSoundPatch(this: v7);
  else
    v8 = nullptr;
  if ( nEntIndex == -1 )
  {
    nEntIndexa = 0;
  }
  else if ( g_pEntityList->m_EntPtrArray[nEntIndex].m_pEntity != nullptr )
  {
    nEntIndexa = nEntIndex | (g_pEntityList->m_EntPtrArray[nEntIndex].m_SerialNumber << 16);
  }
  else
  {
    nEntIndexa = -1;
  }
  v9 = 0.0;
  if ( attenuation != 0.0 )
    v9 = (float)(20.0 / attenuation) + 50.0;
  if ( nEntIndexa == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_SerialNumber != HIWORD(nEntIndexa) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_pEntity;
  }
  CSoundPatch::Init(
    this: v8,
    pFilter: filter,
    pEnt: m_pEntity,
    channel,
    pSoundName,
    soundlevel: (soundlevel_t)v9,
    pSoundOrigin: nullptr,
    scriptVolume);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1021EBD0
// Name: public: virtual class CSoundPatch __near * CSoundControllerImp::SoundCreate(class IRecipientFilter __near &,int,int,char const __near *,float,class Vector const __near *,float)
// Source: json
//------------------------------------------------------------------------------
CSoundPatch *__thiscall CSoundControllerImp::SoundCreate(
        CSoundControllerImp *this,
        IRecipientFilter *filter,
        int nEntIndex,
        int channel,
        char *pSoundName,
        float attenuation,
        const Vector *pSoundOrigin,
        float scriptVolume)
{
  CSoundPatch *v8; // eax
  CSoundPatch *v9; // esi
  float v10; // xmm0_4
  CBaseEntity *m_pEntity; // eax
  unsigned int nEntIndexa; // [esp+14h] [ebp+Ch]

  v8 = (CSoundPatch *)CUtlMemoryPool::Alloc(this: &CSoundPatch::s_Allocator, amount: 0x84u);
  if ( v8 != nullptr )
    v9 = CSoundPatch::CSoundPatch(this: v8);
  else
    v9 = nullptr;
  if ( nEntIndex == -1 )
  {
    nEntIndexa = 0;
  }
  else if ( g_pEntityList->m_EntPtrArray[nEntIndex].m_pEntity != nullptr )
  {
    nEntIndexa = nEntIndex | (g_pEntityList->m_EntPtrArray[nEntIndex].m_SerialNumber << 16);
  }
  else
  {
    nEntIndexa = -1;
  }
  v10 = 0.0;
  if ( attenuation != 0.0 )
    v10 = (float)(20.0 / attenuation) + 50.0;
  if ( nEntIndexa == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_SerialNumber != HIWORD(nEntIndexa) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_pEntity;
  }
  CSoundPatch::Init(
    this: v9,
    pFilter: filter,
    pEnt: m_pEntity,
    channel,
    pSoundName,
    soundlevel: (soundlevel_t)v10,
    pSoundOrigin,
    scriptVolume);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1021ECB0
// Name: public: virtual class CSoundPatch __near * CSoundControllerImp::SoundCreate(class IRecipientFilter __near &,int,int,char const __near *,enum soundlevel_t)
// Source: json
//------------------------------------------------------------------------------
CSoundPatch *__thiscall CSoundControllerImp::SoundCreate(
        CSoundControllerImp *this,
        IRecipientFilter *filter,
        int nEntIndex,
        int channel,
        char *pSoundName,
        soundlevel_t soundlevel)
{
  CSoundPatch *v6; // eax
  CSoundPatch *v7; // esi
  CBaseEntity *m_pEntity; // ecx
  unsigned int nEntIndexa; // [esp+14h] [ebp+Ch]

  v6 = (CSoundPatch *)CUtlMemoryPool::Alloc(this: &CSoundPatch::s_Allocator, amount: 0x84u);
  if ( v6 != nullptr )
    v7 = CSoundPatch::CSoundPatch(this: v6);
  else
    v7 = nullptr;
  if ( nEntIndex == -1 )
  {
    nEntIndexa = 0;
  }
  else if ( g_pEntityList->m_EntPtrArray[nEntIndex].m_pEntity != nullptr )
  {
    nEntIndexa = nEntIndex | (g_pEntityList->m_EntPtrArray[nEntIndex].m_SerialNumber << 16);
  }
  else
  {
    nEntIndexa = -1;
  }
  if ( nEntIndexa == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_SerialNumber != HIWORD(nEntIndexa) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_pEntity;
  }
  CSoundPatch::Init(
    this: v7,
    pFilter: filter,
    pEnt: m_pEntity,
    channel,
    pSoundName,
    soundlevel,
    pSoundOrigin: nullptr,
    scriptVolume: 1.0);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1021ED70
// Name: public: virtual class CSoundPatch __near * CSoundControllerImp::SoundCreate(class IRecipientFilter __near &,int,struct EmitSound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CSoundPatch *__thiscall CSoundControllerImp::SoundCreate(
        CSoundControllerImp *this,
        IRecipientFilter *filter,
        int nEntIndex,
        const EmitSound_t *es)
{
  CSoundPatch *v4; // eax
  CSoundPatch *v5; // esi
  CBaseEntity *m_pEntity; // eax
  float m_flVolume; // xmm0_4
  __m128i v8; // xmm0
  float v9; // xmm0_4
  CSoundPatch *result; // eax
  unsigned int nEntIndexa; // [esp+18h] [ebp+Ch]

  v4 = (CSoundPatch *)CUtlMemoryPool::Alloc(this: &CSoundPatch::s_Allocator, amount: 0x84u);
  if ( v4 != nullptr )
    v5 = CSoundPatch::CSoundPatch(this: v4);
  else
    v5 = nullptr;
  if ( nEntIndex == -1 )
  {
    nEntIndexa = 0;
  }
  else if ( g_pEntityList->m_EntPtrArray[nEntIndex].m_pEntity != nullptr )
  {
    nEntIndexa = nEntIndex | (g_pEntityList->m_EntPtrArray[nEntIndex].m_SerialNumber << 16);
  }
  else
  {
    nEntIndexa = -1;
  }
  if ( nEntIndexa == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_SerialNumber != HIWORD(nEntIndexa) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)nEntIndexa].m_pEntity;
  }
  CSoundPatch::Init(
    this: v5,
    pFilter: filter,
    pEnt: m_pEntity,
    channel: es->m_nChannel,
    pSoundName: (char *)es->m_pSoundName,
    soundlevel: es->m_SoundLevel,
    pSoundOrigin: es->m_pOrigin,
    scriptVolume: 1.0);
  m_flVolume = es->m_flVolume;
  v5->m_flags |= 1u;
  if ( m_flVolume > 1.0 )
    m_flVolume = 1.0;
  if ( m_flVolume != v5->m_volume.m_current )
    v5->m_volume.m_forceupdate = true;
  if ( v5->m_volume.m_target != m_flVolume )
    v5->m_volume.m_forceupdate = true;
  v5->m_volume.m_target = m_flVolume;
  v5->m_volume.m_current = m_flVolume;
  v5->m_volume.m_rate = 0.0;
  v8 = _mm_cvtsi32_si128(es->m_nPitch);
  v5->m_flags |= 2u;
  v9 = _mm_cvtepi32_ps(v8).m128_f32[0];
  if ( v9 != v5->m_pitch.m_current )
    v5->m_pitch.m_forceupdate = true;
  if ( v5->m_pitch.m_target != v9 )
    v5->m_pitch.m_forceupdate = true;
  v5->m_pitch.m_target = v9;
  v5->m_pitch.m_current = v9;
  v5->m_pitch.m_rate = 0.0;
  result = v5;
  if ( SLOBYTE(es->m_nFlags) < 0 )
    v5->m_baseFlags = 128;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021EEC0
// Name: public: virtual void CSoundControllerImp::CheckLoopingSoundsForPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::CheckLoopingSoundsForPlayer(CSoundControllerImp *this, CBasePlayer *pPlayer)
{
  int v2; // ebx
  CSoundPatch *v3; // esi
  const char *pszValue; // eax
  int m_entityChannel; // ecx
  __int32 m_soundlevel; // edx
  float v7; // xmm0_4
  int v8; // eax
  unsigned int m_Index; // ecx
  int m_nSoundEntryVersion; // eax
  IHandleEntity *v11; // eax
  IHandleEntity_vtbl *v12; // eax
  int v13; // eax
  CEntInfo *v14; // edx
  unsigned int v15; // ecx
  int v16; // eax
  bool v17; // zf
  CEntInfo *v18; // eax
  IHandleEntity *m_pEntity; // eax
  IHandleEntity_vtbl *v20; // eax
  signed int v21; // eax
  EmitSound_t params; // [esp+4h] [ebp-70h] BYREF
  CRecipientFilter v23; // [esp+4Ch] [ebp-28h] BYREF
  CSoundControllerImp *v24; // [esp+6Ch] [ebp-8h]
  int i; // [esp+70h] [ebp-4h]

  v2 = this->m_soundList.m_Size - 1;
  v24 = this;
  i = v2;
  if ( v2 >= 0 )
  {
    while ( 1 )
    {
      v3 = this->m_soundList.m_Memory.m_pMemory[v2];
      if ( (v3->m_Filter.m_Flags & 1) != 0 && v3->m_Filter.AddRecipient(this: &v3->m_Filter, a2: pPlayer) )
      {
        CRecipientFilter::CRecipientFilter(this: &v23);
        v23.__vftable = (CRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
        CRecipientFilter::AddRecipient(this: &v23, player: pPlayer);
        pszValue = v3->m_iszSoundName.pszValue;
        m_entityChannel = v3->m_entityChannel;
        memset(&params.m_pOrigin, 0, 12);
        *(_WORD *)&params.m_bEmitCloseCaption = 1;
        params.m_bWarnOnDirectWaveReference = false;
        params.m_nSpeakerEntity = -1;
        memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
        params.m_nChannel = m_entityChannel;
        params.m_pSoundName = pszValue;
        if ( pszValue == nullptr )
          params.m_pSoundName = locale;
        m_soundlevel = v3->m_soundlevel;
        v7 = v3->m_flScriptVolume * v3->m_volume.m_current;
        v8 = v3->m_baseFlags | 1;
        params.m_nPitch = (int)v3->m_pitch.m_current;
        m_Index = v3->m_hEnt.m_Index;
        params.m_SoundLevel = m_soundlevel;
        LOWORD(m_soundlevel) = v3->m_hSoundScriptHandle;
        params.m_nFlags = v8;
        m_nSoundEntryVersion = v3->m_nSoundEntryVersion;
        params.m_flVolume = v7;
        params.m_hSoundScriptHandle = m_soundlevel;
        params.m_nSoundEntryVersion = m_nSoundEntryVersion;
        if ( m_Index == -1 )
          goto LABEL_25;
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
          && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
        {
          v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
              ? g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity
              : nullptr;
          v12 = v11[6].__vftable;
          if ( v12 == nullptr || ((char *)v12 - (char *)gpGlobals->pEdicts) >> 4 == 0 )
            params.m_pOrigin = &v3->m_soundOrigin;
        }
        v13 = (unsigned __int16)m_Index;
        v14 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        v15 = HIWORD(m_Index);
        if ( v14->m_SerialNumber == v15 && v14->m_pEntity != nullptr )
        {
          v16 = v13;
          v17 = g_pEntityList->m_EntPtrArray[v16].m_SerialNumber == v15;
          v18 = &g_pEntityList->m_EntPtrArray[v16];
          if ( v17 )
            m_pEntity = v18->m_pEntity;
          else
            m_pEntity = nullptr;
          v20 = m_pEntity[6].__vftable;
          if ( v20 != nullptr )
            v21 = ((char *)v20 - (char *)gpGlobals->pEdicts) >> 4;
          else
            v21 = 0;
        }
        else
        {
LABEL_25:
          v21 = -1;
        }
        CBaseEntity::EmitSound(filter: &v23, iEntIndex: v21, &params);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
        CRecipientFilter::~CRecipientFilter(this: &v23);
        v2 = i;
      }
      i = --v2;
      if ( v2 < 0 )
        break;
      this = v24;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021F090
// Name: public: virtual void CSoundControllerImp::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundControllerImp::OnRestore(CSoundControllerImp *this)
{
  int i; // edi
  const char *m_pszName; // eax
  int v4; // esi
  const char *v5; // eax
  int v6; // ecx
  float v7; // xmm0_4
  int v8; // eax
  __int16 v9; // dx
  int v10; // eax
  int v11; // eax
  const char *v12; // esi
  EmitSound_t params; // [esp+8h] [ebp-48h] BYREF

  for ( i = this->m_soundList.m_Memory.m_nGrowSize - 1; i >= 0; --i )
  {
    m_pszName = this->m_pszName;
    v4 = *(_DWORD *)&m_pszName[4 * i];
    if ( v4 != 0 && *(_DWORD *)(v4 + 92) != 0 && (*(_BYTE *)(v4 + 104) & 1) != 0 )
    {
      if ( CSoundPatch::EntIndex(this: *(CSoundPatch **)&m_pszName[4 * i]) < 0 )
      {
        v12 = *(const char **)(v4 + 44);
        if ( v12 == nullptr )
          v12 = locale;
        DevWarning(
          a1: "CSoundPatch::ResumeSound: Lost EHAndle on restore - destroy the sound patch in your entity's StopLoopingSounds! (%s)\n",
          v12);
      }
      else
      {
        EmitSound_t::EmitSound_t(this: &params);
        v5 = *(const char **)(v4 + 44);
        params.m_nChannel = *(_DWORD *)(v4 + 64);
        params.m_pSoundName = v5;
        if ( v5 == nullptr )
          params.m_pSoundName = locale;
        v6 = (int)*(float *)v4;
        v7 = *(float *)(v4 + 96) * *(float *)(v4 + 16);
        v8 = *(_DWORD *)(v4 + 88) | 3;
        params.m_SoundLevel = *(_DWORD *)(v4 + 36);
        v9 = *(_WORD *)(v4 + 52);
        params.m_nFlags = v8;
        v10 = *(_DWORD *)(v4 + 56);
        params.m_nPitch = v6;
        params.m_flVolume = v7;
        params.m_hSoundScriptHandle = v9;
        params.m_nSoundEntryVersion = v10;
        if ( CSoundPatch::EntIndex(this: (CSoundPatch *)v4) == 0 )
          params.m_pOrigin = (const Vector *)(v4 + 72);
        v11 = CSoundPatch::EntIndex(this: (CSoundPatch *)v4);
        CBaseEntity::EmitSound(filter: (CRecipientFilter *)(v4 + 100), iEntIndex: v11, &params);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021F190
// Name: public: virtual void CSoundPatchSaveRestoreOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundPatchSaveRestoreOps::Restore(
        CSoundPatchSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  IRestore *v3; // esi
  const SaveRestoreFieldInfo_t *v4; // eax
  int v5; // eax
  void (__thiscall *EndBlock)(IRestore *); // edx
  int m_Size; // eax
  int v8; // edi
  CSoundPatch **m_pMemory; // ecx
  int v10; // eax
  const SaveRestoreFieldInfo_t **v11; // eax
  IRestore *v12; // eax
  IRestore *v13; // edi
  bool v14; // sf
  int nSoundPatchCount; // [esp+8h] [ebp-Ch]
  CSoundPatch **ppSoundPatch; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h] BYREF
  const SaveRestoreFieldInfo_t *fieldInfoa; // [esp+1Ch] [ebp+8h]

  v3 = pRestore;
  pRestore->StartBlock(this: pRestore);
  ppSoundPatch = (CSoundPatch **)fieldInfo->pField;
  nSoundPatchCount = fieldInfo->pTypeDesc->fieldSize - 1;
  if ( nSoundPatchCount >= 0 )
  {
    do
    {
      v4 = (const SaveRestoreFieldInfo_t *)CUtlMemoryPool::Alloc(this: &CSoundPatch::s_Allocator, amount: 0x84u);
      if ( v4 != nullptr )
      {
        v4->pField = nullptr;
        v4->pOwner = nullptr;
        v4->pTypeDesc = nullptr;
        LOBYTE(v4[1].pField) = 0;
        v4[1].pOwner = nullptr;
        v4[1].pTypeDesc = nullptr;
        v4[2].pField = nullptr;
        LOBYTE(v4[2].pOwner) = 0;
        v4[5].pField = (void *)-1;
        v4[8].pOwner = &CCopyRecipientFilter::`vftable';
        v4[8].pTypeDesc = nullptr;
        v4[9].pField = nullptr;
        v4[9].pOwner = nullptr;
        v4[9].pTypeDesc = nullptr;
        v4[10].pField = nullptr;
        v4[10].pOwner = nullptr;
        ++CSoundPatch::g_SoundPatchCount;
        v4[3].pTypeDesc = nullptr;
        v4[4].pField = nullptr;
        fieldInfoa = v4;
        *(float *)&v4[10].pTypeDesc = soundpatch_captionlength.m_pParent->m_Value.m_fValue;
        v4[6].pField = nullptr;
        v4[6].pOwner = nullptr;
        v4[6].pTypeDesc = nullptr;
        v4[5].pTypeDesc = (typedescription_t *)-1;
        v4[2].pTypeDesc = (typedescription_t *)-1;
        LOWORD(v4[4].pOwner) = -1;
        v4[4].pTypeDesc = (typedescription_t *)1;
      }
      else
      {
        fieldInfoa = nullptr;
      }
      v3->StartBlock(this: v3);
      v5 = v3->ReadAll(this: v3, a2: (void *)fieldInfoa, a3: &CSoundPatch::m_DataMap);
      EndBlock = v3->EndBlock;
      HIBYTE(pRestore) = v5 != 0;
      EndBlock(this: v3);
      if ( HIBYTE(pRestore) != 0 && fieldInfoa[7].pTypeDesc != nullptr )
      {
        m_Size = g_Controller.m_soundList.m_Size;
        HIBYTE(pRestore) = 1;
        v8 = g_Controller.m_soundList.m_Size;
        if ( g_Controller.m_soundList.m_Size + 1 > g_Controller.m_soundList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&g_Controller.m_soundList,
            num: g_Controller.m_soundList.m_Size - g_Controller.m_soundList.m_Memory.m_nAllocationCount + 1);
          m_Size = g_Controller.m_soundList.m_Size;
        }
        m_pMemory = g_Controller.m_soundList.m_Memory.m_pMemory;
        g_Controller.m_soundList.m_Size = m_Size + 1;
        v10 = m_Size - v8;
        g_Controller.m_soundList.m_pElements = g_Controller.m_soundList.m_Memory.m_pMemory;
        if ( v10 > 0 )
        {
          _V_memmove(
            dest: &g_Controller.m_soundList.m_Memory.m_pMemory[v8 + 1],
            src: &g_Controller.m_soundList.m_Memory.m_pMemory[v8],
            count: 4 * v10);
          m_pMemory = g_Controller.m_soundList.m_Memory.m_pMemory;
        }
        v11 = (const SaveRestoreFieldInfo_t **)&m_pMemory[v8];
        if ( v11 != nullptr )
          *v11 = fieldInfoa;
      }
      else
      {
        HIBYTE(pRestore) = 0;
      }
      v3->StartBlock(this: v3);
      if ( HIBYTE(pRestore) != 0 )
      {
        v3->ReadInt_2(this: v3, a2: &v17, a3: 1, a4: 0);
        if ( --v17 >= 0 )
        {
          do
          {
            v12 = (IRestore *)CUtlMemoryPool::Alloc(this: &SoundCommand_t::s_Allocator, amount: 0x18u);
            if ( v12 != nullptr )
            {
              *(_QWORD *)&v12->__vftable = 0;
              *(_QWORD *)&v12[2].__vftable = 0;
              *(_QWORD *)&v12[4].__vftable = 0;
              v13 = v12;
            }
            else
            {
              v13 = nullptr;
            }
            v3->StartBlock(this: v3);
            if ( v3->ReadAll(this: v3, a2: v13, a3: &SoundCommand_t::m_DataMap) != 0 )
            {
              v13->__vftable = (IRestore_vtbl *)fieldInfoa;
              pRestore = v13;
              CUtlPriorityQueue<CEventRegister *,CDefUtlPriorityQueueLessFunc<CEventRegister *>,CUtlMemory<CEventRegister *,int>>::Insert(
                this: &g_Controller.m_commandList,
                element: (SoundCommand_t *const *)&pRestore);
            }
            v3->EndBlock(this: v3);
            --v17;
          }
          while ( v17 >= 0 );
        }
      }
      v3->EndBlock(this: v3);
      *ppSoundPatch = (CSoundPatch *)fieldInfoa;
      v14 = --nSoundPatchCount < 0;
      ++ppSoundPatch;
    }
    while ( !v14 );
  }
  v3->EndBlock(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1040A190
// Name: CSoundEnvelope_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSoundEnvelope_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSoundEnvelope>(__formal: nullptr);
  CSoundEnvelope_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A1A0
// Name: CCopyRecipientFilter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CCopyRecipientFilter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CCopyRecipientFilter>(__formal: nullptr);
  CCopyRecipientFilter_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A1E0
// Name: _dynamic_initializer_for__CSoundPatch::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CSoundPatch::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CSoundPatch::s_Allocator,
    blockSize: 132,
    numElements: 64,
    growMode: 1,
    pszAllocOwner: "CSoundPatch pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CSoundPatch::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A210
// Name: CSoundPatch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSoundPatch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSoundPatch>(__formal: nullptr);
  CSoundPatch_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A250
// Name: SoundCommand_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *SoundCommand_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<SoundCommand_t>();
  SoundCommand_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041DFE0
// Name: _dynamic_atexit_destructor_for__CSoundPatch::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CSoundPatch::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CSoundPatch::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x1021DDC0
// Name: struct datamap_t __near * DataMapInit<class CSoundEnvelope>(class CSoundEnvelope __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSoundEnvelope>()
{
  if ( (_S2_206 & 1) == 0 )
  {
    _S2_206 |= 1u;
    nameHolder_390.m_pszBase = "CSoundEnvelope";
    nameHolder_390.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_390.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_390.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_390.m_Names.m_Size = 0;
    nameHolder_390.m_Names.m_pElements = nullptr;
    nameHolder_390.m_nLenBase = 14;
    atexit(func: DataMapInit_CSoundEnvelope__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSoundEnvelope::m_DataMap.baseMap = nullptr;
  CSoundEnvelope::m_DataMap.dataNumFields = 4;
  CSoundEnvelope::m_DataMap.dataDesc = &dataDesc_373[1];
  return &CSoundEnvelope::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1021DFF0
// Name: struct datamap_t __near * DataMapInit<class CCopyRecipientFilter>(class CCopyRecipientFilter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CCopyRecipientFilter>()
{
  if ( (_S3_117 & 1) == 0 )
  {
    _S3_117 |= 1u;
    nameHolder_391.m_pszBase = "CCopyRecipientFilter";
    nameHolder_391.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_391.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_391.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_391.m_Names.m_Size = 0;
    nameHolder_391.m_Names.m_pElements = nullptr;
    nameHolder_391.m_nLenBase = 20;
    atexit(func: DataMapInit_CCopyRecipientFilter__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CCopyRecipientFilter::m_DataMap.baseMap = nullptr;
  if ( (_S3_117 & 2) == 0 )
  {
    _S3_117 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<5>::GetDataOps<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<5>::GetDataOps<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<5>::GetDataOps<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<int,CUtlMemory<int,int>>,5>::`vftable';
    }
    dataDesc_374[2].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<5>::GetDataOps<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::ops;
    dataDesc_374[2].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_374[2].td = 0;
    *(_QWORD *)&dataDesc_374[2].override_field = 0;
    *(_QWORD *)&dataDesc_374[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_374[2].flatOffset[1] = 0;
  }
  CCopyRecipientFilter::m_DataMap.dataNumFields = 2;
  CCopyRecipientFilter::m_DataMap.dataDesc = &dataDesc_374[1];
  return &CCopyRecipientFilter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1021E0D0
// Name: struct datamap_t __near * DataMapInit<class CSoundPatch>(class CSoundPatch __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSoundPatch>()
{
  if ( (_S4_55 & 1) == 0 )
  {
    _S4_55 |= 1u;
    nameHolder_392.m_pszBase = "CSoundPatch";
    nameHolder_392.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_392.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_392.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_392.m_Names.m_Size = 0;
    nameHolder_392.m_Names.m_pElements = nullptr;
    nameHolder_392.m_nLenBase = 11;
    atexit(func: DataMapInit_CSoundPatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSoundPatch::m_DataMap.baseMap = nullptr;
  CSoundPatch::m_DataMap.dataNumFields = 16;
  CSoundPatch::m_DataMap.dataDesc = &dataDesc_375[1];
  return &CSoundPatch::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040A1B0
// Name: _dynamic_initializer_for__report_soundpatch_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__report_soundpatch_command__()
{
  ConCommand::ConCommand(
    this: &report_soundpatch_command,
    pName: "report_soundpatch",
    callback: report_soundpatch,
    pHelpString: "reports sound patch count",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__report_soundpatch_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A220
// Name: _dynamic_initializer_for__SoundCommand_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__SoundCommand_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &SoundCommand_t::s_Allocator,
    blockSize: 24,
    numElements: 32,
    growMode: 1,
    pszAllocOwner: "SoundCommand_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__SoundCommand_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A260
// Name: _dynamic_initializer_for__g_Controller__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Controller__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(
    this: &g_Controller.CAutoGameSystemPerFrame,
    name: "CSoundControllerImp");
  g_Controller.CSoundEnvelopeController::__vftable = (CSoundControllerImp_vtbl *)&CSoundControllerImp::`vftable'{for `CSoundEnvelopeController'};
  g_Controller.CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CAutoGameSystemPerFrame_vtbl *)&CSoundControllerImp::`vftable'{for `CAutoGameSystemPerFrame'};
  g_Controller.m_soundList.m_Memory.m_pMemory = nullptr;
  g_Controller.m_soundList.m_Memory.m_nAllocationCount = 0;
  g_Controller.m_soundList.m_Memory.m_nGrowSize = 0;
  g_Controller.m_soundList.m_Size = 0;
  g_Controller.m_soundList.m_pElements = nullptr;
  g_Controller.m_commandList.m_heap.m_Memory.m_pMemory = nullptr;
  g_Controller.m_commandList.m_heap.m_Memory.m_nAllocationCount = 0;
  g_Controller.m_commandList.m_heap.m_Memory.m_nGrowSize = 0;
  g_Controller.m_commandList.m_heap.m_Size = 0;
  g_Controller.m_commandList.m_heap.m_pElements = nullptr;
  g_Controller.m_commandList.m_LessFunc = (bool (__cdecl *)(SoundCommand_t *const *, SoundCommand_t *const *))TimedEventMgr_LessFunc;
  return atexit(func: dynamic_atexit_destructor_for__g_Controller__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DFF0
// Name: _dynamic_atexit_destructor_for__SoundCommand_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__SoundCommand_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &SoundCommand_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x1041E000
// Name: _DataMapInit_CSoundEnvelope__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSoundEnvelope__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_390);
}

//------------------------------------------------------------------------------
// Address: 0x1041E010
// Name: _DataMapInit_CCopyRecipientFilter__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CCopyRecipientFilter__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_391);
}

//------------------------------------------------------------------------------
// Address: 0x1041E020
// Name: _DataMapInit_CSoundPatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSoundPatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_392);
}

//------------------------------------------------------------------------------
// Address: 0x1041E030
// Name: _DataMapInit_SoundCommand_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_SoundCommand_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_393);
}

//------------------------------------------------------------------------------
// Address: 0x1041E040
// Name: _dynamic_atexit_destructor_for__g_Controller__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Controller__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Controller.m_commandList);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Controller.m_soundList);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_Controller.CAutoGameSystemPerFrame);
}

} // namespace server
