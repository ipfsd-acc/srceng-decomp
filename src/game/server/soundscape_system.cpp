// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/soundscape_system.cpp
// Functions: 13
// ============================================================

#include "game\server\soundscape_system.h"

//------------------------------------------------------------------------------
// Address: 0x10220F20
// Name: public: int CSoundscapeSystem::GetSoundscapeIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundscapeSystem::GetSoundscapeIndex(CSoundscapeSystem *this, const char *pName)
{
  return CStringRegistry::GetStringID(this: &this->m_soundscapes, stringText: pName);
}

//------------------------------------------------------------------------------
// Address: 0x10220F30
// Name: public: bool CSoundscapeSystem::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSoundscapeSystem::IsValidIndex(CSoundscapeSystem *this, int index)
{
  return index >= 0 && index < this->m_soundscapeCount;
}

//------------------------------------------------------------------------------
// Address: 0x10220F50
// Name: public: virtual bool CSoundscapeSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundscapeSystem::Init(CSoundscapeSystem *this)
{
  CSoundscapeSystem *v1; // esi
  const char *pszValue; // eax
  const char *v3; // ebx
  KeyValues *v4; // eax
  KeyValues *i; // edi
  const char *Name; // eax
  CSoundscapeSystem_vtbl *v7; // esi
  const char *String; // eax
  const char *v9; // eax
  const char *v10; // eax
  KeyValues *manifest; // [esp+Ch] [ebp-8h]

  v1 = this;
  this->m_soundscapeCount = 0;
  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v3 = nullptr;
  if ( pszValue != nullptr && *pszValue != 0 )
    v3 = UTIL_VarArgs(format: "scripts/soundscapes_%s.txt", pszValue);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    manifest = KeyValues::KeyValues(this: v4, setName: "scripts/soundscapes_manifest.txt");
  else
    manifest = nullptr;
  if ( filesystem->LoadKeyValues(
         this: filesystem,
         a2: manifest,
         a3: TYPE_SOUNDSCAPE,
         a4: "scripts/soundscapes_manifest.txt",
         a5: "GAME") )
  {
    for ( i = KeyValues::GetFirstSubKey(this: manifest); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: Name, s2: "file") != 0 )
      {
        v10 = KeyValues::GetName(this: i);
        _Warning(
          a1: "CSoundscapeSystem::Init:  Manifest '%s' with bogus file type '%s', expecting 'file'\n",
          "scripts/soundscapes_manifest.txt",
          v10);
      }
      else
      {
        v7 = v1->__vftable;
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
        v7->AddSoundscapeFile(this, a2: String);
        if ( v3 != nullptr )
        {
          v9 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
          if ( v9 == v3 || _V_stricmp(s1: v9, s2: v3) == 0 )
            v3 = nullptr;
        }
        v1 = this;
      }
    }
    if ( v3 != nullptr && filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: v3, a3: nullptr) )
      v1->AddSoundscapeFile(this: v1, a2: v3);
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1049EFB4, a2: "scripts/soundscapes_manifest.txt");
  }
  KeyValues::deleteThis(this: manifest);
  v1->m_activeIndex = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102210D0
// Name: soundscape_flush
// Source: json
//------------------------------------------------------------------------------
void __cdecl soundscape_flush()
{
  CBasePlayer *CommandClient; // esi
  bool v1; // zf
  int i; // esi
  CBasePlayer *v3; // eax

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient == nullptr || !CommandClient->IsPlayer(this: CommandClient) )
    CommandClient = nullptr;
  if ( engine->IsDedicatedServer(this: engine) )
  {
    v1 = CommandClient == nullptr;
  }
  else
  {
    if ( CommandClient == nullptr )
      return;
    v1 = CommandClient == UTIL_GetListenServerHost();
  }
  if ( v1 )
  {
    g_SoundscapeSystem.m_soundscapeCount = 0;
    CStringRegistry::ClearStrings(this: &g_SoundscapeSystem.m_soundscapes);
    CSoundscapeSystem::Init(this: &g_SoundscapeSystem);
    if ( engine->IsDedicatedServer(this: engine) )
    {
      for ( i = 1; i <= gpGlobals->maxClients; ++i )
      {
        v3 = UTIL_PlayerByIndex(playerIndex: i);
        if ( v3 != nullptr )
          engine->ClientCommand(this: engine, a2: v3->m_Network.m_pPev, a3: "cl_soundscape_flush\n");
      }
    }
    else
    {
      engine->ClientCommand(this: engine, a2: CommandClient->m_Network.m_pPev, a3: "cl_soundscape_flush\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102211B0
// Name: public: void CSoundscapeSystem::PrintDebugInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundscapeSystem::PrintDebugInfo(CSoundscapeSystem *this)
{
  CSoundscapeSystem *v1; // ebx
  CStringRegistry *p_m_soundscapes; // edi
  int v3; // esi
  int IDForKey; // ebx
  const char *StringForKey; // eax
  int i; // edi
  CEnvSoundscape **m_pMemory; // edx
  CEnvSoundscape *v8; // esi
  const char *pszValue; // eax
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  v1 = this;
  _Msg(a1: "\n------- SERVER SOUNDSCAPES -------\n");
  p_m_soundscapes = &v1->m_soundscapes;
  v3 = CStringRegistry::First(this: &v1->m_soundscapes);
  if ( v3 != GetInvalidWeaponInfoHandle(this: &v1->m_soundscapes) )
  {
    do
    {
      IDForKey = CStringRegistry::GetIDForKey(this: p_m_soundscapes, key: v3);
      StringForKey = CStringRegistry::GetStringForKey(this: p_m_soundscapes, key: v3);
      _Msg(a1: "- %d: %s\n", IDForKey, StringForKey);
      v3 = CStringRegistry::Next(this: p_m_soundscapes, key: v3);
    }
    while ( v3 != GetInvalidWeaponInfoHandle(this: p_m_soundscapes) );
    v1 = this;
  }
  _Msg(a1: "-------- SOUNDSCAPE ENTITIES -----\n");
  for ( i = 0; i < v1->m_soundscapeEntities.m_Size; ++i )
  {
    m_pMemory = v1->m_soundscapeEntities.m_Memory.m_pMemory;
    v8 = m_pMemory[i];
    if ( (v8->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pMemory[i], a2: (int)&savedregs);
    if ( (v8->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v8, a2: (int)&savedregs);
    if ( (v8->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v8, a2: (int)&savedregs);
    pszValue = v8->m_soundscapeName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Msg(
      a1: "- %d: %s x:%.4f y:%.4f z:%.4f\n",
      i,
      pszValue,
      v8->m_vecAbsOrigin.x,
      v8->m_vecAbsOrigin.y,
      v8->m_vecAbsOrigin.z);
  }
  _Msg(a1: "----------------------------------\n\n");
}

//------------------------------------------------------------------------------
// Address: 0x10221300
// Name: public: virtual void CSoundscapeSystem::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSoundscapeSystem::FrameUpdatePostEntityThink(
        CSoundscapeSystem *this@<ecx>,
        Vector *p_playerPosition@<edi>)
{
  int maxClients; // ecx
  int v4; // edx
  CBasePlayer *v5; // eax
  CBasePlayer *v6; // edi
  int m_Value; // eax
  CEnvSoundscape *v8; // ebx
  Vector *(__thiscall *EarPosition)(CBaseEntity *, Vector *); // edx
  int v10; // eax
  int v11; // ebx
  int v12; // edi
  CEnvSoundscape *v13; // ecx
  ss_update_t update; // [esp+4h] [ebp-40h] BYREF
  _BYTE v16[12]; // [esp+24h] [ebp-20h] BYREF
  int i; // [esp+30h] [ebp-14h]
  int maxPlayers; // [esp+34h] [ebp-10h]
  int maxTraces; // [esp+38h] [ebp-Ch]
  int traceCount; // [esp+3Ch] [ebp-8h]
  int playerCount; // [esp+40h] [ebp-4h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  if ( this->m_soundscapeEntities.m_Size > 0 )
  {
    traceCount = 0;
    playerCount = 0;
    maxPlayers = 2;
    maxTraces = 4;
    if ( soundscape_debug.m_pParent != nullptr && soundscape_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      maxTraces = 9999;
      maxPlayers = 64;
    }
    maxClients = gpGlobals->maxClients;
    for ( i = 0; i < maxClients; ++i )
    {
      if ( traceCount > maxTraces || playerCount > maxPlayers )
        break;
      v4 = (this->m_activeIndex + 1) % maxClients;
      this->m_activeIndex = v4;
      v5 = UTIL_PlayerByIndex(playerIndex: v4 + 1);
      v6 = v5;
      if ( v5 != nullptr && v5->IsNetClient(this: v5) )
      {
        m_Value = v6->m_Local.m_audio.entIndex.m_Value;
        v8 = nullptr;
        if ( m_Value > 0 && m_Value <= this->m_soundscapeEntities.m_Size )
          v8 = this->m_soundscapeEntities.m_Memory.m_pMemory[m_Value - 1];
        EarPosition = v6->EarPosition;
        update.pPlayer = v6;
        update.pCurrentSoundscape = v8;
        update.playerPosition = *(Vector *)((int (__thiscall *)(CBasePlayer *, _BYTE *, Vector *))EarPosition)(
                                             a1: v6,
                                             a2: v16,
                                             a3: p_playerPosition);
        memset(&update.currentDistance, 0, 9);
        if ( v8 != nullptr )
          CEnvSoundscape::UpdateForPlayer(this: v8, a2: (IHandleEntity_vtbl *)&savedregs, &update);
        p_playerPosition = &update.playerPosition;
        v10 = ((int (__thiscall *)(IVEngineServer *))engine->GetClusterForOrigin)(a1: engine);
        v11 = v10;
        if ( v10 >= 0 && v10 < this->m_soundscapesInCluster.m_Size )
        {
          v12 = 0;
          if ( this->m_soundscapesInCluster.m_Memory.m_pMemory[v10].soundscapeCount != 0 )
          {
            do
            {
              v13 = this->m_soundscapeEntities.m_Memory.m_pMemory[this->m_soundscapeIndexList.m_Memory.m_pMemory[v12 + this->m_soundscapesInCluster.m_Memory.m_pMemory[v11].firstSoundscape]];
              if ( v13 != update.pCurrentSoundscape )
                CEnvSoundscape::UpdateForPlayer(this: v13, a2: (IHandleEntity_vtbl *)&savedregs, &update);
              ++v12;
            }
            while ( v12 < this->m_soundscapesInCluster.m_Memory.m_pMemory[v11].soundscapeCount );
          }
        }
        ++playerCount;
        traceCount += update.traceCount;
      }
      maxClients = gpGlobals->maxClients;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102214A0
// Name: sv_soundscape_printdebuginfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl sv_soundscape_printdebuginfo()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CSoundscapeSystem::PrintDebugInfo(this: &g_SoundscapeSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10221540
// Name: public: void CSoundscapeSystem::RemoveSoundscapeEntity(class CEnvSoundscape __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundscapeSystem::RemoveSoundscapeEntity(CSoundscapeSystem *this, CEnvSoundscape *pSoundscape)
{
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_soundscapeEntities,
    src: (vgui::TreeNode **)&pSoundscape);
  pSoundscape->m_soundscapeEntityId = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10221560
// Name: public: void CSoundscapeSystem::AddSoundscapeEntity(class CEnvSoundscape __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundscapeSystem::AddSoundscapeEntity(CSoundscapeSystem *this, CEnvSoundscape *pSoundscape)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_soundscapeEntities; // esi
  int m_Size; // ecx
  int v4; // eax
  CEnvSoundscape **m_pMemory; // edx
  int v6; // edi
  int m_nAllocationCount; // ecx
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_soundscapeEntities = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_soundscapeEntities;
  m_Size = this->m_soundscapeEntities.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (CEnvSoundscape **)p_m_soundscapeEntities->m_pMemory;
  while ( *m_pMemory != pSoundscape )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    v6 = m_Size;
    m_nAllocationCount = p_m_soundscapeEntities->m_nAllocationCount;
    if ( v6 + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_soundscapeEntities, num: v6 - m_nAllocationCount + 1);
    ++p_m_soundscapeEntities[1].m_pMemory;
    v8 = p_m_soundscapeEntities->m_pMemory;
    v9 = (int)p_m_soundscapeEntities[1].m_pMemory - v6 - 1;
    p_m_soundscapeEntities[1].m_nAllocationCount = (int)p_m_soundscapeEntities->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v6 + 1], src: &v8[v6], count: 4 * v9);
    v10 = &p_m_soundscapeEntities->m_pMemory[v6];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)pSoundscape;
    pSoundscape->m_soundscapeEntityId = v6 + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102215F0
// Name: public: virtual void CSoundscapeSystem::AddSoundscapeFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundscapeSystem::AddSoundscapeFile(CSoundscapeSystem *this, const char *filename)
{
  KeyValues *v3; // eax
  KeyValues *NextKey; // edi
  unsigned __int8 *Name; // eax
  int v7; // eax
  int m_soundscapeCount; // eax
  const char *StringText; // eax
  const char *v10; // eax
  int v11; // [esp-4h] [ebp-10h]
  KeyValues *pKeyValuesData; // [esp+14h] [ebp+8h]

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    pKeyValuesData = KeyValues::KeyValues(this: v3, setName: filename);
  else
    pKeyValuesData = nullptr;
  NextKey = pKeyValuesData;
  if ( filesystem->LoadKeyValues(this: filesystem, a2: pKeyValuesData, a3: TYPE_SOUNDSCAPE, a4: filename, a5: "GAME")
    && pKeyValuesData != nullptr )
  {
    do
    {
      if ( KeyValues::GetFirstSubKey(this: NextKey) != nullptr )
      {
        if ( g_pDeveloper->m_pParent != nullptr && g_pDeveloper->m_pParent->m_Value.m_nValue != 0 )
        {
          Name = (unsigned __int8 *)KeyValues::GetName(this: NextKey);
          strstr(str1: Name, str2: "{");
          if ( v7 != 0 )
          {
            m_soundscapeCount = this->m_soundscapeCount;
            if ( m_soundscapeCount <= 0 )
              StringText = "FIRST";
            else
              StringText = CStringRegistry::GetStringText(this: &this->m_soundscapes, stringID: m_soundscapeCount - 1);
            _Msg(a1: "Error parsing soundscape file %s after %s\n", filename, StringText);
          }
        }
        v11 = this->m_soundscapeCount;
        v10 = KeyValues::GetName(this: NextKey);
        CStringRegistry::AddString(this: &this->m_soundscapes, stringText: v10, stringID: v11);
        ++this->m_soundscapeCount;
      }
      NextKey = KeyValues::GetNextKey(this: NextKey);
    }
    while ( NextKey != nullptr );
  }
  KeyValues::deleteThis(this: pKeyValuesData);
}

//------------------------------------------------------------------------------
// Address: 0x10221790
// Name: public: virtual void CSoundscapeSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundscapeSystem::Shutdown(CSoundscapeSystem *this)
{
  this->m_soundscapeCount = 0;
  CStringRegistry::ClearStrings(this: &this->m_soundscapes);
  this->m_soundscapeEntities.m_Size = 0;
  this->m_activeIndex = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102217C0
// Name: public: virtual void CSoundscapeSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundscapeSystem::LevelInitPreEntity(CSoundscapeSystem *this)
{
  g_SoundscapeSystem.m_soundscapeCount = 0;
  CStringRegistry::ClearStrings(this: &g_SoundscapeSystem.m_soundscapes);
  g_SoundscapeSystem.m_soundscapeEntities.m_Size = 0;
  g_SoundscapeSystem.m_activeIndex = 0;
  CSoundscapeSystem::Init(this: &g_SoundscapeSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10221800
// Name: public: virtual void CSoundscapeSystem::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundscapeSystem::LevelInitPostEntity(CSoundscapeSystem *this)
{
  CSoundscapeSystem *v1; // edi
  int (__thiscall *GetClusterCount)(IVEngineServer *); // edx
  int v3; // ebx
  int v4; // esi
  int i; // eax
  int v6; // ecx
  CEnvSoundscape **m_pMemory; // eax
  CEnvSoundscape *v8; // esi
  CEnvSoundscape **v9; // ecx
  float m_flRadius; // xmm0_4
  IVEngineServer_vtbl *v11; // esi
  int (__thiscall *GetClusterForOrigin)(IVEngineServer *, const Vector *); // eax
  int v13; // eax
  int v14; // edi
  bbox_t *v15; // esi
  double v16; // st7
  int v17; // esi
  wchar_t *v18; // ecx
  wchar_t *v19; // eax
  bbox_t *v20; // eax
  bbox_t *v21; // esi
  wchar_t *v22; // ecx
  int v23; // eax
  wchar_t *v24; // eax
  const void **p_m_pMemory; // esi
  int m_nAllocationCount; // eax
  char *v27; // edx
  int v28; // eax
  int v29; // edi
  int v30; // edx
  int v31; // eax
  CUtlVector<clusterSoundscapeList_t,CUtlMemory<clusterSoundscapeList_t,int> > *v32; // ecx
  clusterSoundscapeList_t *v33; // ecx
  int soundscapeCount; // ebx
  clusterSoundscapeList_t *v35; // ecx
  wchar_t *v36; // edx
  int v37; // edi
  int v38; // eax
  int v39; // ebx
  clusterSoundscapeList_t *v40; // eax
  int firstSoundscape; // ecx
  _WORD *v42; // eax
  int v43; // ecx
  bool v44; // zf
  _BYTE v45[16384]; // [esp+Ch] [ebp-4060h] BYREF
  Vector point; // [esp+400Ch] [ebp-60h] BYREF
  CUtlVector<bbox_t,CUtlMemory<bbox_t,int> > v47; // [esp+4018h] [ebp-54h] BYREF
  float v48; // [esp+402Ch] [ebp-40h]
  CUtlMemory<wchar_t,int> v49; // [esp+4030h] [ebp-3Ch] BYREF
  int v50; // [esp+403Ch] [ebp-30h]
  wchar_t *v51; // [esp+4040h] [ebp-2Ch]
  CSoundscapeSystem *v52; // [esp+4044h] [ebp-28h]
  int v53; // [esp+4048h] [ebp-24h]
  CUtlMemory<wchar_t,int> v54; // [esp+404Ch] [ebp-20h] BYREF
  bbox_t *v55; // [esp+4058h] [ebp-14h]
  wchar_t *v56; // [esp+405Ch] [ebp-10h]
  int v57; // [esp+4060h] [ebp-Ch]
  bbox_t *v58; // [esp+4064h] [ebp-8h]
  CUtlVector<clusterSoundscapeList_t,CUtlMemory<clusterSoundscapeList_t,int> > *p_m_soundscapesInCluster; // [esp+4068h] [ebp-4h]
  int savedregs; // [esp+406Ch] [ebp+0h] BYREF

  v1 = this;
  GetClusterCount = engine->GetClusterCount;
  v3 = 0;
  v52 = this;
  memset(&v47, 0, sizeof(v47));
  v4 = GetClusterCount(this: engine);
  v53 = v4;
  CUtlVector<bbox_t,CUtlMemory<bbox_t,int>>::InsertMultipleBefore(this: &v47, elem: 0, num: v4);
  engine->GetAllClusterBounds(this: engine, a2: v47.m_Memory.m_pMemory, a3: v4);
  p_m_soundscapesInCluster = &v1->m_soundscapesInCluster;
  v1->m_soundscapesInCluster.m_Size = 0;
  CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)&v1->m_soundscapesInCluster,
    elem: 0,
    num: v4);
  for ( i = 0; i < v4; ++i )
  {
    p_m_soundscapesInCluster->m_Memory.m_pMemory[i].soundscapeCount = 0;
    p_m_soundscapesInCluster->m_Memory.m_pMemory[i].firstSoundscape = 0;
  }
  v6 = 0;
  memset(&v49, 0, sizeof(v49));
  v50 = 0;
  v51 = nullptr;
  memset(&v54, 0, sizeof(v54));
  v55 = nullptr;
  v56 = nullptr;
  v57 = 0;
  if ( v1->m_soundscapeEntities.m_Size > 0 )
  {
    do
    {
      m_pMemory = v1->m_soundscapeEntities.m_Memory.m_pMemory;
      v8 = m_pMemory[v57];
      if ( (v8->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: m_pMemory[v57], a2: (int)&savedregs);
      v9 = v1->m_soundscapeEntities.m_Memory.m_pMemory;
      point = v8->m_vecAbsOrigin;
      m_flRadius = v9[v57]->m_flRadius;
      v11 = engine->__vftable;
      GetClusterForOrigin = engine->GetClusterForOrigin;
      v48 = m_flRadius * m_flRadius;
      v13 = ((int (__thiscall *)(IVEngineServer *, Vector *, int, _BYTE *))GetClusterForOrigin)(
              a1: engine,
              a2: &point,
              a3: 0x4000,
              a4: v45);
      ((void (__thiscall *)(IVEngineServer *, int))v11->GetPVSForCluster)(a1: engine, a2: v13);
      v14 = 0;
      if ( v53 > 0 )
      {
        v15 = v47.m_Memory.m_pMemory;
        v58 = v47.m_Memory.m_pMemory;
        do
        {
          if ( ((unsigned __int8)(1 << (v14 & 7)) & v45[v14 >> 3]) != 0 )
          {
            v16 = CalcSqrDistanceToAABB(mins: &v15->mins, maxs: &v15->maxs, &point);
            if ( v48 > v16 )
            {
              ++p_m_soundscapesInCluster->m_Memory.m_pMemory[v14].soundscapeCount;
              v17 = v3;
              if ( v3 + 1 > v49.m_nAllocationCount )
              {
                CUtlMemory<wchar_t,int>::Grow(this: &v49, num: v3 - v49.m_nAllocationCount + 1);
                v3 = v50;
              }
              v18 = v49.m_pMemory;
              v50 = ++v3;
              v51 = v49.m_pMemory;
              if ( v3 - v17 - 1 > 0 )
              {
                _V_memmove(dest: &v49.m_pMemory[v17 + 1], src: &v49.m_pMemory[v17], count: 2 * (v3 - v17 - 1));
                v18 = v49.m_pMemory;
              }
              v19 = &v18[v17];
              if ( v19 != nullptr )
                *v19 = v14;
              v20 = v55;
              v21 = v55;
              if ( (int)&v55->mins.x + 1 > v54.m_nAllocationCount )
              {
                CUtlMemory<wchar_t,int>::Grow(this: &v54, num: (int)&v55->mins.x - v54.m_nAllocationCount + 1);
                v20 = v55;
              }
              v22 = v54.m_pMemory;
              v55 = (bbox_t *)((char *)&v20->mins.x + 1);
              v23 = (char *)v20 - (char *)v21;
              v56 = v54.m_pMemory;
              if ( v23 > 0 )
              {
                _V_memmove(dest: &v54.m_pMemory[(_DWORD)v21 + 1], src: &v54.m_pMemory[(_DWORD)v21], count: 2 * v23);
                v22 = v54.m_pMemory;
              }
              v24 = &v22[(_DWORD)v21];
              if ( v24 != nullptr )
                *v24 = v57;
            }
          }
          ++v14;
          v15 = ++v58;
        }
        while ( v14 < v53 );
      }
      ++v57;
      v1 = v52;
    }
    while ( v57 < v52->m_soundscapeEntities.m_Size );
    v6 = (int)v55;
  }
  p_m_pMemory = (const void **)&v1->m_soundscapeIndexList.m_Memory.m_pMemory;
  v1->m_soundscapeIndexList.m_Size = 0;
  if ( v6 != 0 )
  {
    m_nAllocationCount = v1->m_soundscapeIndexList.m_Memory.m_nAllocationCount;
    if ( v6 > m_nAllocationCount )
    {
      CUtlMemory<wchar_t,int>::Grow(
        this: (CUtlMemory<wchar_t,int> *)&v1->m_soundscapeIndexList,
        num: v6 - m_nAllocationCount);
      v6 = (int)v55;
    }
    v1->m_soundscapeIndexList.m_Size += v6;
    v27 = (char *)*p_m_pMemory;
    v28 = v1->m_soundscapeIndexList.m_Size - v6;
    v1->m_soundscapeIndexList.m_pElements = v1->m_soundscapeIndexList.m_Memory.m_pMemory;
    if ( v28 > 0 && v6 > 0 )
    {
      _V_memmove(dest: &v27[2 * v6], src: v27, count: 2 * v28);
      v6 = (int)v55;
    }
  }
  v29 = v53;
  v30 = 0;
  v31 = 0;
  if ( v53 > 0 )
  {
    do
    {
      v32 = p_m_soundscapesInCluster;
      p_m_soundscapesInCluster->m_Memory.m_pMemory[v31].firstSoundscape = v30;
      v33 = v32->m_Memory.m_pMemory;
      soundscapeCount = v33[v31].soundscapeCount;
      v35 = &v33[v31];
      v30 += soundscapeCount;
      ++v31;
      v35->soundscapeCount = 0;
    }
    while ( v31 < v29 );
    v6 = (int)v55;
  }
  if ( v6 > 0 )
  {
    v36 = v54.m_pMemory;
    v37 = (char *)v49.m_pMemory - (char *)v54.m_pMemory;
    v58 = v55;
    do
    {
      v38 = *(__int16 *)((char *)v36 + v37);
      v39 = p_m_soundscapesInCluster->m_Memory.m_pMemory[v38].soundscapeCount;
      v40 = &p_m_soundscapesInCluster->m_Memory.m_pMemory[v38];
      firstSoundscape = v40->firstSoundscape;
      ++v40->soundscapeCount;
      v42 = *p_m_pMemory;
      v43 = v39 + firstSoundscape;
      LOWORD(v39) = *v36++;
      v44 = v58 == (bbox_t *)1;
      v58 = (bbox_t *)((char *)v58 - 1);
      v42[v43] = v39;
    }
    while ( !v44 );
  }
  if ( v54.m_nGrowSize >= 0 && v54.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54.m_pMemory);
  if ( v49.m_nGrowSize >= 0 && v49.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v49.m_pMemory);
  if ( v47.m_Memory.m_nGrowSize >= 0 && v47.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v47.m_Memory.m_pMemory);
}
