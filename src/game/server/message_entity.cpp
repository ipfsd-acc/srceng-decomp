// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/message_entity.cpp
// Functions: 11
// ============================================================

#include "game\server\message_entity.h"

//------------------------------------------------------------------------------
// Address: 0x10172510
// Name: public: virtual struct datamap_t __near * CMessageEntity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CMessageEntity::GetDataDescMap(CMessageEntity *this)
{
  return &CMessageEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10172520
// Name: public: void CMessageEntity::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageEntity::InputDisable(CMathCounter *this, inputdata_t *inputdata)
{
  this->m_bDisabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x10172530
// Name: public: void CMessageEntity::DrawOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageEntity::DrawOverlays(CMessageEntity *this)
{
  const char *pszValue; // eax
  char tempstr[512]; // [esp+18h] [ebp-200h] BYREF

  if ( this->m_drawText
    && (!this->m_bDeveloperOnly || g_pDeveloper->m_pParent != nullptr && g_pDeveloper->m_pParent->m_Value.m_nValue != 0)
    && this->m_bEnabled )
  {
    pszValue = this->m_messageText.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "%s", pszValue);
    CBaseEntity::EntityText(this, text_offset: 0, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101725D0
// Name: public: virtual void CMessageEntity::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageEntity::Spawn(CMessageEntity *this)
{
  bool v2; // cl

  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  v2 = (this->m_spawnflags.m_Value & 1) == 0;
  *(_WORD *)&this->m_drawText = 0;
  this->m_bEnabled = v2;
}

//------------------------------------------------------------------------------
// Address: 0x10172610
// Name: public: virtual void CMessageEntity::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMessageEntity::Think(CMessageEntity *this@<ecx>, float a2@<ebp>)
{
  CBasePlayer *LocalPlayer; // eax
  __int128 v4; // xmm0
  __int128 v5; // [esp+18h] [ebp-1Ch] BYREF
  Vector worldTargetPosition; // [esp+28h] [ebp-Ch] BYREF
  float retaddr; // [esp+34h] [ebp+0h]

  worldTargetPosition.x = a2;
  worldTargetPosition.y = retaddr;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  LocalPlayer = UTIL_GetLocalPlayer();
  if ( LocalPlayer != nullptr && (LocalPlayer->m_fFlags.m_Value & 0x10000) == 0 )
  {
    LocalPlayer->EyePosition(this: LocalPlayer, result: (Vector *)((char *)&v5 + 4));
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&worldTargetPosition);
    v4 = 0;
    *(float *)&v4 = fsqrt(
                      (float)((float)((float)(*((float *)&v5 + 2) - this->m_vecAbsOrigin.y)
                                    * (float)(*((float *)&v5 + 2) - this->m_vecAbsOrigin.y))
                            + (float)((float)(*((float *)&v5 + 3) - this->m_vecAbsOrigin.z)
                                    * (float)(*((float *)&v5 + 3) - this->m_vecAbsOrigin.z)))
                    + (float)((float)(*((float *)&v5 + 1) - this->m_vecAbsOrigin.x)
                            * (float)(*((float *)&v5 + 1) - this->m_vecAbsOrigin.x)));
    v5 = v4;
    this->m_drawText = *(float *)&v4 <= (float)this->m_radius;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172710
// Name: void DrawMessageEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawMessageEntities()
{
  int i; // esi
  CHandle<CMessageEntity> *v1; // edx
  unsigned int m_Index; // eax
  CMessageEntity *m_pEntity; // ecx

  for ( i = g_MessageEntities.m_Size - 1; i >= 0; --i )
  {
    v1 = &g_MessageEntities.m_Memory.m_pMemory[i];
    m_Index = v1->m_Index;
    if ( v1->m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && (m_pEntity = (CMessageEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
    {
      CMessageEntity::DrawOverlays(this: m_pEntity);
    }
    else
    {
      if ( g_MessageEntities.m_Size - i - 1 > 0 )
        _V_memmove(
          dest: &g_MessageEntities.m_Memory.m_pMemory[i],
          src: &v1[1],
          count: 4 * (g_MessageEntities.m_Size - i - 1));
      --g_MessageEntities.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101727D0
// Name: public: virtual void CMessageEntity::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageEntity::UpdateOnRemove(CMessageEntity *this)
{
  int v2; // eax
  CHandle<CMessageEntity> h; // [esp+4h] [ebp-4h] BYREF

  CBaseEntity::UpdateOnRemove(this);
  if ( this != nullptr )
    h.m_Index = this->GetRefEHandle(this)->m_Index;
  else
    h.m_Index = -1;
  v2 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&g_MessageEntities,
         src: (CHandle<CBaseEntity> *)&h);
  if ( v2 != -1 )
  {
    if ( g_MessageEntities.m_Size - v2 - 1 > 0 )
      _V_memmove(
        dest: &g_MessageEntities.m_Memory.m_pMemory[v2],
        src: &g_MessageEntities.m_Memory.m_pMemory[v2 + 1],
        count: 4 * (g_MessageEntities.m_Size - v2 - 1));
    --g_MessageEntities.m_Size;
  }
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10172850
// Name: public: virtual void CMessageEntity::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageEntity::Activate(CMessageEntity *this)
{
  unsigned int m_Index; // edi
  int m_Size; // eax
  int v4; // esi
  CHandle<CMessageEntity> *m_pMemory; // ecx
  int v6; // eax
  CHandle<CMessageEntity> *v7; // eax

  CBaseEntity::Activate(this);
  if ( this != nullptr )
    m_Index = this->GetRefEHandle(this)->m_Index;
  else
    m_Index = -1;
  m_Size = g_MessageEntities.m_Size;
  v4 = g_MessageEntities.m_Size;
  if ( g_MessageEntities.m_Size + 1 > g_MessageEntities.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_MessageEntities,
      num: g_MessageEntities.m_Size - g_MessageEntities.m_Memory.m_nAllocationCount + 1);
    m_Size = g_MessageEntities.m_Size;
  }
  m_pMemory = g_MessageEntities.m_Memory.m_pMemory;
  g_MessageEntities.m_Size = m_Size + 1;
  v6 = m_Size - v4;
  g_MessageEntities.m_pElements = g_MessageEntities.m_Memory.m_pMemory;
  if ( v6 > 0 )
  {
    _V_memmove(
      dest: &g_MessageEntities.m_Memory.m_pMemory[v4 + 1],
      src: &g_MessageEntities.m_Memory.m_pMemory[v4],
      count: 4 * v6);
    m_pMemory = g_MessageEntities.m_Memory.m_pMemory;
  }
  v7 = &m_pMemory[v4];
  if ( v7 != nullptr )
    v7->m_Index = m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10405DE0
// Name: CMessageEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMessageEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMessageEntity>(__formal: nullptr);
  CMessageEntity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101728E0
// Name: struct datamap_t __near * DataMapInit<class CMessageEntity>(class CMessageEntity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMessageEntity>()
{
  if ( (_S2_153 & 1) == 0 )
  {
    _S2_153 |= 1u;
    nameHolder_278.m_pszBase = "CMessageEntity";
    nameHolder_278.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_278.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_278.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_278.m_Names.m_Size = 0;
    nameHolder_278.m_Names.m_pElements = nullptr;
    nameHolder_278.m_nLenBase = 14;
    atexit(func: DataMapInit_CMessageEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMessageEntity::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CMessageEntity::m_DataMap.dataNumFields = 7;
  CMessageEntity::m_DataMap.dataDesc = &dataDesc_265[1];
  return &CMessageEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10405DF0
// Name: _dynamic_initializer_for__g_MessageEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MessageEntities__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_MessageEntities__);
}
