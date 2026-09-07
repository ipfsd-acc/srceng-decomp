// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/asw_npcs.cpp
// Functions: 10
// ============================================================

#include "missionchooser\asw_npcs.h"

//------------------------------------------------------------------------------
// Address: 0x10007810
// Name: float VectorLength(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl VectorLength(const Vector *v)
{
  return fsqrt((float)((float)(v->x * v->x) + (float)(v->y * v->y)) + (float)(v->z * v->z));
}

//------------------------------------------------------------------------------
// Address: 0x10007870
// Name: public: class Vector Vector::operator+(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator+(Vector *this, Vector *result, const Vector *v)
{
  result->x = v->x + this->x;
  result->y = v->y + this->y;
  result->z = v->z + this->z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100078B0
// Name: public: class Vector Vector::operator*(float)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator*(Vector *this, Vector *result, float fl)
{
  result->x = this->x * fl;
  result->y = this->y * fl;
  result->z = this->z * fl;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100078F0
// Name: public: class Vector __near & Vector::operator=(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator=(Vector *this, const Vector *vOther)
{
  *this = *vOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10007910
// Name: public: virtual class Vector const __near & CASW_Encounter::GetEncounterPosition(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CASW_Encounter::GetEncounterPosition(CASW_Encounter *this)
{
  return &this->m_vecPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10007920
// Name: public: virtual float CASW_Encounter::GetEncounterRadius(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CASW_Encounter::GetEncounterRadius(CASW_Encounter *this)
{
  return this->m_flEncounterRadius;
}

//------------------------------------------------------------------------------
// Address: 0x10007930
// Name: public: virtual void CASW_Encounter::SetEncounterPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Encounter::SetEncounterPosition(CASW_Encounter *this, const Vector *vecSrc)
{
  this->m_vecPosition = *vecSrc;
}

//------------------------------------------------------------------------------
// Address: 0x10007950
// Name: public: virtual void CASW_Encounter::SetEncounterRadius(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Encounter::SetEncounterRadius(CASW_Encounter *this, float flRadius)
{
  this->m_flEncounterRadius = flRadius;
}

//------------------------------------------------------------------------------
// Address: 0x10007970
// Name: public: static void CASWMissionChooserNPCs::PushEncountersApart(class CMapLayout __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CASWMissionChooserNPCs::PushEncountersApart(float a1@<ebp>, float *p_y@<edi>, CMapLayout *pLayout)
{
  CRoom **m_pMemory; // esi
  CRoom *v4; // edi
  int (__thiscall *GetSpawnWeight)(struct CRoom *); // eax
  CRoom **v6; // edi
  float x; // ecx
  float *v8; // edi
  CASW_Encounter **v9; // ecx
  CASW_Encounter *v10; // esi
  float v11; // eax
  CASW_Encounter *v12; // edi
  float *v13; // eax
  float (__thiscall *GetEncounterRadius)(struct CASW_Encounter *); // eax
  double v15; // st7
  float (__thiscall *v16)(struct CASW_Encounter *); // eax
  double v17; // st7
  double v18; // st7
  float *v19; // eax
  void (__thiscall *SetEncounterPosition)(CASW_Encounter *, const Vector *); // edx
  const Vector *(__thiscall *GetEncounterPosition)(struct CASW_Encounter *); // edx
  int v22; // edi
  int v23; // eax
  void (__stdcall *v24)(Vector *, float *); // edx
  float y; // xmm0_4
  float z; // xmm0_4
  float v28; // [esp-1Ch] [ebp-ACh]
  float v29[3]; // [esp-Ch] [ebp-9Ch] BYREF
  float v30[3]; // [esp+0h] [ebp-90h] BYREF
  float v31[3]; // [esp+Ch] [ebp-84h] BYREF
  float v32[3]; // [esp+18h] [ebp-78h] BYREF
  Vector vecMaxs; // [esp+24h] [ebp-6Ch] BYREF
  Vector vecMins; // [esp+30h] [ebp-60h] BYREF
  Vector dir; // [esp+3Ch] [ebp-54h] BYREF
  float flClosestDist; // [esp+48h] [ebp-48h]
  Vector pos; // [esp+4Ch] [ebp-44h] BYREF
  CUtlVector<CRoom *,CUtlMemory<CRoom *,int> > candidates; // [esp+58h] [ebp-38h]
  Vector vecPush; // [esp+6Ch] [ebp-24h]
  int k; // [esp+78h] [ebp-18h]
  CRoom *pRoom; // [esp+7Ch] [ebp-14h]
  int iEncounters; // [esp+80h] [ebp-10h]
  float flMinDistance; // [esp+84h] [ebp-Ch]
  float dist; // [esp+88h] [ebp-8h]
  float retaddr; // [esp+90h] [ebp+0h]

  flMinDistance = a1;
  dist = retaddr;
  m_pMemory = nullptr;
  LODWORD(vecPush.z) = pLayout->m_PlacedRooms.m_Size;
  memset(&pos, 0, sizeof(pos));
  candidates.m_Memory.m_pMemory = nullptr;
  candidates.m_Memory.m_nAllocationCount = 0;
  for ( iEncounters = 0; iEncounters < SLODWORD(vecPush.z); ++iEncounters )
  {
    v4 = pLayout->m_PlacedRooms.m_Memory.m_pMemory[iEncounters];
    GetSpawnWeight = v4->GetSpawnWeight;
    LODWORD(vecPush.y) = v4;
    if ( GetSpawnWeight(this: v4) > 0
      && !CRoomTemplate::IsEscapeRoom(this: (CRoomTemplate *)v4->m_pRoomTemplate)
      && !CRoomTemplate::IsStartRoom(this: (CRoomTemplate *)v4->m_pRoomTemplate)
      && !CRoomTemplate::IsBorderRoom(this: (CRoomTemplate *)v4->m_pRoomTemplate)
      && v4->m_pRoomTemplate->m_nTilesX * v4->m_pRoomTemplate->m_nTilesY > 1 )
    {
      v4->GetSpawnWeight(this: v4);
      v6 = m_pMemory;
      if ( (int)m_pMemory + 1 > SLODWORD(pos.y) )
      {
        CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&pos,
          num: (int)m_pMemory - LODWORD(pos.y) + 1);
        m_pMemory = candidates.m_Memory.m_pMemory;
      }
      x = pos.x;
      m_pMemory = (CRoom **)((char *)m_pMemory + 1);
      candidates.m_Memory.m_pMemory = m_pMemory;
      candidates.m_Memory.m_nAllocationCount = LODWORD(pos.x);
      if ( (char *)m_pMemory - (char *)v6 - 1 > 0 )
      {
        _V_memmove(
          dest: (void *)(LODWORD(pos.x) + 4 * (_DWORD)v6 + 4),
          src: (const void *)(LODWORD(pos.x) + 4 * (_DWORD)v6),
          count: 4 * ((char *)m_pMemory - (char *)v6 - 1));
        x = pos.x;
      }
      v8 = (float *)(LODWORD(x) + 4 * (_DWORD)v6);
      if ( v8 != nullptr )
        *v8 = vecPush.y;
    }
  }
  LODWORD(vecPush.y) = 6;
  do
  {
    LODWORD(vecPush.z) = pLayout->m_Encounters.m_Size;
    for ( iEncounters = 0; iEncounters < SLODWORD(vecPush.z); ++iEncounters )
    {
      v9 = pLayout->m_Encounters.m_Memory.m_pMemory;
      candidates.m_pElements = (CRoom **)LODWORD(vec3_origin.z);
      v10 = v9[iEncounters];
      v11 = 0.0;
      *(_QWORD *)&candidates.m_Memory.m_nGrowSize = *(_QWORD *)&vec3_origin.x;
      vecPush.x = 0.0;
      do
      {
        if ( iEncounters != LODWORD(v11) )
        {
          v12 = pLayout->m_Encounters.m_Memory.m_pMemory[LODWORD(v11)];
          *(float *)&pRoom = COERCE_FLOAT(v12->GetEncounterPosition(this: v12));
          v13 = (float *)v10->GetEncounterPosition(this: v10);
          vecMins.x = *v13 - *(float *)&pRoom->__vftable;
          vecMins.y = v13[1] - *(float *)&pRoom->m_iPosX;
          vecMins.z = v13[2] - *(float *)&pRoom->m_iPosY;
          *(float *)&pRoom = VectorNormalize(vec: &vecMins);
          GetEncounterRadius = v10->GetEncounterRadius;
          k = SLODWORD(asw_encounters_distance_min.m_pParent->m_Value.m_fValue);
          v15 = ((double (__thiscall *)(CASW_Encounter *))GetEncounterRadius)(a1: v10);
          v16 = v12->GetEncounterRadius;
          *(float *)&k = v15 + *(float *)&k;
          v17 = ((double (__thiscall *)(CASW_Encounter *))v16)(a1: v12);
          v18 = v17 + *(float *)&k;
          v11 = vecPush.x;
          *(float *)&k = v18;
          if ( v18 > *(float *)&pRoom )
          {
            *(float *)&candidates.m_Size = *(float *)&candidates.m_Size
                                         + (float)(vecMins.y * (float)(*(float *)&k - *(float *)&pRoom));
            *(float *)&candidates.m_Memory.m_nGrowSize = (float)(vecMins.x * (float)(*(float *)&k - *(float *)&pRoom))
                                                       + *(float *)&candidates.m_Memory.m_nGrowSize;
            *(float *)&candidates.m_pElements = *(float *)&candidates.m_pElements
                                              + (float)(vecMins.z * (float)(*(float *)&k - *(float *)&pRoom));
          }
        }
        ++LODWORD(v11);
        vecPush.x = v11;
      }
      while ( SLODWORD(v11) < SLODWORD(vecPush.z) );
      v19 = (float *)v10->GetEncounterPosition(this: v10);
      SetEncounterPosition = v10->SetEncounterPosition;
      v31[0] = *v19 + *(float *)&candidates.m_Memory.m_nGrowSize;
      v31[1] = v19[1] + *(float *)&candidates.m_Size;
      v31[2] = v19[2] + *(float *)&candidates.m_pElements;
      SetEncounterPosition(this: v10, a2: (const Vector *)v31);
      GetEncounterPosition = v10->GetEncounterPosition;
      v22 = 0;
      *(float *)&pRoom = 0.0;
      dir.x = 65535.0;
      v23 = (int)GetEncounterPosition(this: v10);
      *(_QWORD *)&dir.y = *(_QWORD *)v23;
      flClosestDist = *(float *)(v23 + 8);
      if ( (int)candidates.m_Memory.m_pMemory > 0 )
      {
        while ( 1 )
        {
          v24 = *(void (__stdcall **)(Vector *, float *))(**(_DWORD **)(LODWORD(pos.x) + 4 * v22) + 60);
          k = *(int *)(LODWORD(pos.x) + 4 * v22);
          v24(a1: &vecMaxs, a2: v32);
          if ( dir.y >= vecMaxs.x && v32[0] >= dir.y && dir.z >= vecMaxs.y && v32[1] >= dir.z )
            break;
          v28 = fsqrt(
                  (float)((float)((float)((float)((float)(v32[1] + vecMaxs.y) * 0.5) - dir.z)
                                * (float)((float)((float)(v32[1] + vecMaxs.y) * 0.5) - dir.z))
                        + (float)((float)((float)((float)(v32[2] + vecMaxs.z) * 0.5) - flClosestDist)
                                * (float)((float)((float)(v32[2] + vecMaxs.z) * 0.5) - flClosestDist)))
                + (float)((float)((float)((float)(v32[0] + vecMaxs.x) * 0.5) - dir.y)
                        * (float)((float)((float)(v32[0] + vecMaxs.x) * 0.5) - dir.y)));
          if ( dir.x > v28 )
          {
            dir.x = v28;
            pRoom = (CRoom *)k;
          }
          if ( ++v22 >= (int)candidates.m_Memory.m_pMemory )
          {
            if ( *(float *)&pRoom != 0.0 )
            {
              ((void (__thiscall *)(CRoom *, float *, float *, float *))pRoom->GetWorldBounds)(
                a1: pRoom,
                a2: v29,
                a3: v30,
                a4: p_y);
              y = v29[0];
              if ( v29[0] <= dir.y )
              {
                y = v30[0];
                if ( dir.y <= v30[0] )
                  y = dir.y;
              }
              dir.y = y;
              z = v29[1];
              if ( v29[1] <= dir.z )
              {
                z = v30[1];
                if ( dir.z <= v30[1] )
                  z = dir.z;
              }
              dir.z = z;
              p_y = &dir.y;
              ((void (__thiscall *)(CASW_Encounter *))v10->SetEncounterPosition)(a1: v10);
            }
            break;
          }
        }
      }
    }
    --LODWORD(vecPush.y);
  }
  while ( LODWORD(vecPush.y) != 0 );
  if ( pos.z >= 0.0 && LODWORD(pos.x) != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(pos.x));
}

//------------------------------------------------------------------------------
// Address: 0x10007DD0
// Name: public: static void CASWMissionChooserNPCs::InitFixedSpawns(class CLayoutSystem __near *,class CMapLayout __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CASWMissionChooserNPCs::InitFixedSpawns(CLayoutSystem *pLayoutSystem, CMapLayout *pLayout)
{
  CMapLayout *v2; // esi
  KeyValues *m_pGenerationOptions; // ecx
  int v4; // edi
  const char *String; // eax
  const char *v6; // ebx
  CASW_Spawn_Selection *v7; // eax
  CASW_Spawn_Selection *v8; // eax
  CASW_Spawn_Selection_vtbl *v9; // ebx
  int Int; // eax
  int m_Size; // ecx
  int v12; // eax
  int m_iMaxEncounters; // esi
  CASW_Spawn_Set *v14; // eax
  int v15; // eax
  int v16; // esi
  CRoom *v17; // edi
  int (__thiscall *GetSpawnWeight)(struct CRoom *); // eax
  int v19; // eax
  int v20; // edi
  float x; // ecx
  CRoom **v22; // edi
  int v23; // esi
  int v24; // eax
  _DWORD *v25; // esi
  CRoomTemplate *v26; // ecx
  CASW_Encounter *v27; // eax
  float (__thiscall *RandomFloat)(struct CUniformRandomStream *, float, float); // edx
  int m_iMaxSpawnsPerEncounter; // esi
  CASW_Spawn_Set *v30; // eax
  int v31; // eax
  int j; // esi
  CASW_Spawn_Set *v33; // eax
  CASW_Spawn_Definition *SpawnDef; // eax
  float v35; // ecx
  int m_nAllocationCount; // eax
  CASW_Encounter **m_pMemory; // edx
  int v38; // eax
  CASW_Encounter **v39; // ecx
  CASW_Encounter *v40; // eax
  CASW_Encounter *v41; // edi
  int v42; // esi
  CASW_Spawn_Set *v43; // eax
  int v44; // eax
  int k; // esi
  CASW_Spawn_Set *v46; // eax
  CASW_Spawn_Definition *v47; // eax
  int v48; // ecx
  int v49; // eax
  CASW_Encounter **v50; // edx
  int v51; // eax
  CASW_Encounter **v52; // ecx
  Vector vecWorldMaxs; // [esp+44h] [ebp-50h] BYREF
  Vector vecPos; // [esp+50h] [ebp-44h] BYREF
  float v55; // [esp+5Ch] [ebp-38h] BYREF
  float v56; // [esp+60h] [ebp-34h]
  Vector vecWorldMins; // [esp+68h] [ebp-2Ch] BYREF
  float v58; // [esp+74h] [ebp-20h]
  float v59; // [esp+78h] [ebp-1Ch]
  int iEncounters; // [esp+7Ch] [ebp-18h]
  CRoom *pRoom; // [esp+80h] [ebp-14h]
  float flTotalWeight; // [esp+84h] [ebp-10h]
  int flChosen; // [esp+88h] [ebp-Ch]
  int i; // [esp+8Ch] [ebp-8h]
  bool bAlienEncounterTag; // [esp+93h] [ebp-1h]
  int savedregs; // [esp+94h] [ebp+0h] BYREF

  v2 = pLayout;
  m_pGenerationOptions = pLayout->m_pGenerationOptions;
  v4 = 0;
  flTotalWeight = *(float *)&m_pGenerationOptions;
  if ( *(float *)&m_pGenerationOptions == 0.0 )
  {
    _Warning(a1: "Error placed fixed alien spawns, no generation options in this layout.");
  }
  else
  {
    String = KeyValues::GetString(this: m_pGenerationOptions, keyName: "AlienSpawnSet", defaultValue: szDescription);
    v6 = String;
    if ( String == nullptr || *String == 0 || (v7 = SpawnSelection(), !v7->SetCurrentSpawnSet(this: v7, a2: v6)) )
    {
      *(float *)&v8 = COERCE_FLOAT(SpawnSelection());
      v9 = v8->__vftable;
      flChosen = (int)v8;
      Int = KeyValues::GetInt(this: (KeyValues *)LODWORD(flTotalWeight), keyName: "Difficulty", defaultValue: 5);
      v9->SetCurrentSpawnSet_2(this: (struct CASW_Spawn_Selection *)flChosen, a2: Int);
    }
    m_Size = pLayout->m_PlacedRooms.m_Size;
    v12 = 0;
    bAlienEncounterTag = false;
    flChosen = m_Size;
    i = 0;
    if ( m_Size <= 0 )
      goto LABEL_8;
    while ( 1 )
    {
      v25 = &v2->m_PlacedRooms.m_Memory.m_pMemory[v12]->__vftable;
      if ( v25 != nullptr )
      {
        v26 = (CRoomTemplate *)v25[3];
        if ( v26 != nullptr && CRoomTemplate::HasTag(this: v26, szTag: "AlienEncounter") )
        {
          bAlienEncounterTag = true;
          v27 = (CASW_Encounter *)operator new(nSize: 0x28u);
          if ( v27 != nullptr )
          {
            v27->__vftable = (CASW_Encounter_vtbl *)&CASW_Encounter::`vftable';
            v27->m_SpawnDefs.m_Memory.m_pMemory = nullptr;
            v27->m_SpawnDefs.m_Memory.m_nAllocationCount = 0;
            v27->m_SpawnDefs.m_Memory.m_nGrowSize = 0;
            v27->m_SpawnDefs.m_Size = 0;
            v27->m_SpawnDefs.m_pElements = nullptr;
            v4 = (int)v27;
          }
          (*(void (__thiscall **)(_DWORD *, float *, Vector *))(*v25 + 60))(
            a1: v25,
            a2: &vecWorldMins.z,
            a3: &vecWorldMaxs);
          RandomFloat = pLayoutSystem->m_Random.RandomFloat;
          v55 = vecWorldMaxs.x - vecWorldMins.z;
          v56 = vecWorldMaxs.y - v58;
          flTotalWeight = ((double (__thiscall *)(CLayoutSystem *, _DWORD, int))RandomFloat)(
                            a1: pLayoutSystem,
                            a2: 0,
                            a3: 1065353216);
          vecPos.x = (float)(v55 * flTotalWeight) + vecWorldMins.z;
          vecPos.y = (float)(v56 * flTotalWeight) + v58;
          vecPos.z = 0.0;
          (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v4 + 16))(a1: v4, a2: &vecPos);
          flTotalWeight = ((double (__thiscall *)(CLayoutSystem *, _DWORD, _DWORD))pLayoutSystem->m_Random.RandomFloat)(
                            a1: pLayoutSystem,
                            a2: LODWORD(asw_encounter_radius_min.m_pParent->m_Value.m_fValue),
                            a3: LODWORD(asw_encounter_radius_max.m_pParent->m_Value.m_fValue));
          (*(void (__thiscall **)(int, float))(*(_DWORD *)v4 + 24))(a1: v4, a2: COERCE_FLOAT(LODWORD(flTotalWeight)));
          m_iMaxSpawnsPerEncounter = CurrentSpawnSet()->m_iMaxSpawnsPerEncounter;
          v30 = CurrentSpawnSet();
          v31 = pLayoutSystem->m_Random.RandomInt(
                  this: (struct CUniformRandomStream *)pLayoutSystem,
                  a2: v30->m_iMinSpawnsPerEncounter,
                  a3: m_iMaxSpawnsPerEncounter);
          if ( v31 > 0 )
          {
            for ( j = v31; j != 0; --j )
            {
              v33 = CurrentSpawnSet();
              SpawnDef = CASW_Spawn_Set::GetSpawnDef(this: v33, nType: 1);
              if ( SpawnDef != nullptr )
                (*(void (__thiscall **)(int, CASW_Spawn_Definition *))(*(_DWORD *)v4 + 20))(a1: v4, a2: SpawnDef);
            }
          }
          m_nAllocationCount = pLayout->m_Encounters.m_Memory.m_nAllocationCount;
          flTotalWeight = *(float *)&pLayout->m_Encounters.m_Size;
          v35 = flTotalWeight;
          if ( LODWORD(flTotalWeight) + 1 > m_nAllocationCount )
          {
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&pLayout->m_Encounters,
              num: LODWORD(flTotalWeight) - m_nAllocationCount + 1);
            v35 = flTotalWeight;
          }
          ++pLayout->m_Encounters.m_Size;
          m_pMemory = pLayout->m_Encounters.m_Memory.m_pMemory;
          v38 = pLayout->m_Encounters.m_Size - LODWORD(v35) - 1;
          pLayout->m_Encounters.m_pElements = m_pMemory;
          if ( v38 > 0 )
          {
            _V_memmove(dest: &m_pMemory[LODWORD(v35) + 1], src: &m_pMemory[LODWORD(v35)], count: 4 * v38);
            v35 = flTotalWeight;
          }
          v39 = &pLayout->m_Encounters.m_Memory.m_pMemory[LODWORD(v35)];
          if ( v39 != nullptr )
            *v39 = (CASW_Encounter *)v4;
          v4 = 0;
        }
      }
      v12 = i + 1;
      i = v12;
      if ( v12 >= flChosen )
        break;
      v2 = pLayout;
    }
    if ( bAlienEncounterTag )
    {
      CMapLayout::MarkEncounterRooms(this: pLayout);
    }
    else
    {
LABEL_8:
      m_iMaxEncounters = CurrentSpawnSet()->m_iMaxEncounters;
      v14 = CurrentSpawnSet();
      *(float *)&v15 = COERCE_FLOAT(
                         pLayoutSystem->m_Random.RandomInt(
                           this: (struct CUniformRandomStream *)pLayoutSystem,
                           a2: v14->m_iMinEncounters,
                           a3: m_iMaxEncounters));
      *(float *)&v16 = 0.0;
      iEncounters = v15;
      memset(&vecWorldMins, 0, sizeof(vecWorldMins));
      v58 = 0.0;
      v59 = 0.0;
      flTotalWeight = 0.0;
      i = 0;
      if ( flChosen > 0 )
      {
        do
        {
          v17 = pLayout->m_PlacedRooms.m_Memory.m_pMemory[i];
          GetSpawnWeight = v17->GetSpawnWeight;
          pRoom = v17;
          if ( GetSpawnWeight(this: v17) > 0
            && !CRoomTemplate::IsEscapeRoom(this: (CRoomTemplate *)v17->m_pRoomTemplate)
            && !CRoomTemplate::IsStartRoom(this: (CRoomTemplate *)v17->m_pRoomTemplate)
            && !CRoomTemplate::IsBorderRoom(this: (CRoomTemplate *)v17->m_pRoomTemplate) )
          {
            v19 = v17->GetSpawnWeight(this: v17);
            flTotalWeight = (float)v19 + flTotalWeight;
            v20 = v16;
            if ( v16 + 1 > SLODWORD(vecWorldMins.y) )
            {
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&vecWorldMins,
                num: v16 - LODWORD(vecWorldMins.y) + 1);
              *(float *)&v16 = v58;
            }
            x = vecWorldMins.x;
            ++v16;
            v58 = *(float *)&v16;
            v59 = vecWorldMins.x;
            if ( v16 - v20 - 1 > 0 )
            {
              _V_memmove(
                dest: (void *)(LODWORD(vecWorldMins.x) + 4 * v20 + 4),
                src: (const void *)(LODWORD(vecWorldMins.x) + 4 * v20),
                count: 4 * (v16 - v20 - 1));
              x = vecWorldMins.x;
            }
            v22 = (CRoom **)(LODWORD(x) + 4 * v20);
            if ( v22 != nullptr )
              *v22 = pRoom;
          }
          ++i;
        }
        while ( i < flChosen );
        v15 = iEncounters;
        v4 = 0;
      }
      if ( v15 > 0 )
      {
        for ( i = v15; i != 0; --i )
        {
          *(float *)&flChosen = ((double (__thiscall *)(CLayoutSystem *, _DWORD, _DWORD))pLayoutSystem->m_Random.RandomFloat)(
                                  a1: pLayoutSystem,
                                  a2: 0,
                                  a3: LODWORD(flTotalWeight));
          if ( v16 > 0 )
          {
            while ( 1 )
            {
              v23 = *(_DWORD *)(LODWORD(vecWorldMins.x) + 4 * v4);
              v24 = (*(int (__thiscall **)(int))(*(_DWORD *)v23 + 12))(a1: v23);
              *(float *)&flChosen = *(float *)&flChosen - (float)v24;
              if ( *(float *)&flChosen <= 0.0 )
                break;
              if ( ++v4 >= SLODWORD(v58) )
                goto LABEL_61;
            }
            v40 = (CASW_Encounter *)operator new(nSize: 0x28u);
            v41 = nullptr;
            if ( v40 != nullptr )
            {
              v40->__vftable = (CASW_Encounter_vtbl *)&CASW_Encounter::`vftable';
              v40->m_SpawnDefs.m_Memory.m_pMemory = nullptr;
              v40->m_SpawnDefs.m_Memory.m_nAllocationCount = 0;
              v40->m_SpawnDefs.m_Memory.m_nGrowSize = 0;
              v40->m_SpawnDefs.m_Size = 0;
              v40->m_SpawnDefs.m_pElements = nullptr;
              v41 = v40;
            }
            (*(void (__thiscall **)(int, float *, Vector *))(*(_DWORD *)v23 + 60))(a1: v23, a2: &v55, a3: &vecWorldMaxs);
            vecPos.x = (float)(vecWorldMaxs.x + v55) * 0.5;
            vecPos.y = (float)(vecWorldMaxs.y + v56) * 0.5;
            vecPos.z = 0.0;
            v41->SetEncounterPosition(this: v41, a2: &vecPos);
            *(float *)&iEncounters = ((double (__thiscall *)(CLayoutSystem *, _DWORD, _DWORD))pLayoutSystem->m_Random.RandomFloat)(
                                       a1: pLayoutSystem,
                                       a2: LODWORD(asw_encounter_radius_min.m_pParent->m_Value.m_fValue),
                                       a3: LODWORD(asw_encounter_radius_max.m_pParent->m_Value.m_fValue));
            ((void (__thiscall *)(CASW_Encounter *, int))v41->SetEncounterRadius)(a1: v41, a2: iEncounters);
            v42 = CurrentSpawnSet()->m_iMaxSpawnsPerEncounter;
            v43 = CurrentSpawnSet();
            v44 = pLayoutSystem->m_Random.RandomInt(
                    this: (struct CUniformRandomStream *)pLayoutSystem,
                    a2: v43->m_iMinSpawnsPerEncounter,
                    a3: v42);
            if ( v44 > 0 )
            {
              for ( k = v44; k != 0; --k )
              {
                v46 = CurrentSpawnSet();
                v47 = CASW_Spawn_Set::GetSpawnDef(this: v46, nType: 1);
                if ( v47 != nullptr )
                  v41->AddSpawnDef(this: v41, a2: v47);
              }
            }
            v49 = pLayout->m_Encounters.m_Memory.m_nAllocationCount;
            flChosen = pLayout->m_Encounters.m_Size;
            v48 = flChosen;
            if ( flChosen + 1 > v49 )
            {
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&pLayout->m_Encounters,
                num: flChosen - v49 + 1);
              v48 = flChosen;
            }
            ++pLayout->m_Encounters.m_Size;
            v50 = pLayout->m_Encounters.m_Memory.m_pMemory;
            v51 = pLayout->m_Encounters.m_Size - v48 - 1;
            pLayout->m_Encounters.m_pElements = v50;
            if ( v51 > 0 )
            {
              _V_memmove(dest: &v50[v48 + 1], src: &v50[v48], count: 4 * v51);
              v48 = flChosen;
            }
            v52 = &pLayout->m_Encounters.m_Memory.m_pMemory[v48];
            if ( v52 != nullptr )
              *v52 = v41;
LABEL_61:
            *(float *)&v16 = v58;
          }
          v4 = 0;
        }
      }
      CASWMissionChooserNPCs::PushEncountersApart(a1: COERCE_FLOAT(&savedregs), p_y: nullptr, pLayout);
      CMapLayout::MarkEncounterRooms(this: pLayout);
      if ( vecWorldMins.z >= 0.0 && LODWORD(vecWorldMins.x) != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(vecWorldMins.x));
    }
  }
}
