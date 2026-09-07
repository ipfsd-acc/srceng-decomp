// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/cs_shareddefs.cpp
// Functions: 2
// ============================================================

#include "game\shared\cstrike15\cs_shareddefs.h"

//------------------------------------------------------------------------------
// Address: 0x101C9B70
// Name: public: static char const __near * PlayerModelInfo::GetTViewModelPath(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl PlayerModelInfo::GetTViewModelPath()
{
  return g_defaultTViewModel;
}

//------------------------------------------------------------------------------
// Address: 0x101C9B80
// Name: public: static char const __near * PlayerModelInfo::GetCTViewModelPath(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl PlayerModelInfo::GetCTViewModelPath()
{
  return g_defaultCTViewModel;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10297A00
// Name: public: static char const __near * PlayerModelInfo::GetTViewModelPath(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl PlayerModelInfo::GetTViewModelPath()
{
  return g_defaultTViewModel;
}

//------------------------------------------------------------------------------
// Address: 0x10297A10
// Name: public: static char const __near * PlayerModelInfo::GetCTViewModelPath(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl PlayerModelInfo::GetCTViewModelPath()
{
  return g_defaultCTViewModel;
}

//------------------------------------------------------------------------------
// Address: 0x10297A20
// Name: public: bool PlayerModelInfo::IsTClass(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall PlayerModelInfo::IsTClass(PlayerModelInfo *this, int i)
{
  return i >= 1 && i <= this->m_NumTModels;
}

//------------------------------------------------------------------------------
// Address: 0x10297A50
// Name: public: bool PlayerModelInfo::IsCTClass(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall PlayerModelInfo::IsCTClass(PlayerModelInfo *this, int i)
{
  int m_NumTModels; // eax

  m_NumTModels = this->m_NumTModels;
  return i >= m_NumTModels + 1 && i <= m_NumTModels + this->m_NumCTModels;
}

//------------------------------------------------------------------------------
// Address: 0x10297A80
// Name: public: char const __near * PlayerModelInfo::GetClassModelPath(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall PlayerModelInfo::GetClassModelPath(PlayerModelInfo *this, int classID)
{
  return (char *)this + 256 * classID - 256;
}

//------------------------------------------------------------------------------
// Address: 0x10297AA0
// Name: public: int PlayerModelInfo::GetNextClassForTeam(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall PlayerModelInfo::GetNextClassForTeam(PlayerModelInfo *this, int team)
{
  int m_NumTModels; // eax
  int m_NumCTModels; // edx

  if ( team == 2 )
  {
    if ( this->m_nNextClassT == -1 )
      this->m_nNextClassT = _RandomInt((IUniformRandomStream *)this, a2: 1, a3: this->m_NumTModels);
    if ( ++this->m_nNextClassT > this->m_NumTModels )
      this->m_nNextClassT = 1;
    return this->m_nNextClassT;
  }
  else if ( team == 3 )
  {
    if ( this->m_nNextClassCT == -1 )
      this->m_nNextClassCT = _RandomInt(
                               this: (IUniformRandomStream *)(this->m_NumTModels + 1),
                               a2: this->m_NumTModels + 1,
                               a3: this->m_NumTModels + this->m_NumCTModels);
    m_NumTModels = this->m_NumTModels;
    m_NumCTModels = this->m_NumCTModels;
    if ( ++this->m_nNextClassCT > m_NumTModels + m_NumCTModels )
      this->m_nNextClassCT = m_NumTModels + 1;
    return this->m_nNextClassCT;
  }
  else
  {
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10297B60
// Name: private: void PlayerModelInfo::AddModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerModelInfo::AddModel(PlayerModelInfo *this, const char *modelName)
{
  unsigned int m_NumModels; // eax

  if ( modelName != nullptr && *modelName != 0 )
  {
    m_NumModels = this->m_NumModels;
    if ( m_NumModels > 9 )
    {
      _Warning(
        a1: "PlayerModelInfo: model count has exceeded the maximum (%d) for map \"%s\". Ignoring model %s.\n",
        10,
        this->m_mapName,
        modelName);
    }
    else
    {
      _V_strcpy(dest: this->m_ClassNames[m_NumModels], src: modelName);
      V_snprintf(
        pDest: this->m_ClassModelPaths[this->m_NumModels],
        maxLen: 256,
        pFormat: "models/player/%s.mdl",
        modelName);
      ++this->m_NumModels;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10297BE0
// Name: public: void PlayerModelInfo::InitializeForCurrentMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerModelInfo::InitializeForCurrentMap(PlayerModelInfo *this)
{
  const char *pszValue; // ebx
  const CUtlStringList *v3; // eax
  const CUtlStringList *v4; // edi
  int v5; // ebx
  const CUtlStringList *v6; // eax
  const CUtlStringList *v7; // edi
  int v8; // ebx
  const char *v9; // ebx
  unsigned int m_NumModels; // ecx

  if ( gpGlobals != nullptr )
  {
    pszValue = gpGlobals->mapname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( _V_stricmp(s1: this->m_mapName, s2: pszValue) == 0 )
      return;
    _V_strcpy(dest: this->m_mapName, src: pszValue);
  }
  else
  {
    this->m_mapName[0] = 0;
  }
  this->m_NumTModels = 0;
  this->m_NumCTModels = 0;
  this->m_NumModels = 0;
  v3 = g_pGameTypes->GetTModelsForMap(this: g_pGameTypes, a2: this->m_mapName);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v5 = 0;
    if ( v3->m_Size > 0 )
    {
      do
      {
        if ( v4->m_Memory.m_pMemory[v5] != nullptr )
          PlayerModelInfo::AddModel(this, modelName: v4->m_Memory.m_pMemory[v5]);
        ++v5;
      }
      while ( v5 < v4->m_Size );
    }
    this->m_NumTModels = this->m_NumModels;
  }
  if ( this->m_NumTModels == 0 )
  {
    _Warning(
      a1: "PlayerModelInfo: missing terrorist models for map %s. Adding the default model %s.\n",
      this->m_mapName,
      g_defaultTModel);
    PlayerModelInfo::AddModel(this, modelName: g_defaultTModel);
    this->m_NumTModels = 1;
  }
  v6 = g_pGameTypes->GetCTModelsForMap(this: g_pGameTypes, a2: this->m_mapName);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v8 = 0;
    if ( v6->m_Size > 0 )
    {
      do
      {
        if ( v7->m_Memory.m_pMemory[v8] != nullptr )
          PlayerModelInfo::AddModel(this, modelName: v7->m_Memory.m_pMemory[v8]);
        ++v8;
      }
      while ( v8 < v7->m_Size );
    }
    this->m_NumCTModels = this->m_NumModels - this->m_NumTModels;
  }
  if ( this->m_NumCTModels == 0 )
  {
    _Warning(
      a1: "PlayerModelInfo: missing counter-terrorist models for map %s. Adding the default model %s.\n",
      this->m_mapName,
      g_defaultCTModel);
    v9 = g_defaultCTModel;
    if ( g_defaultCTModel != nullptr && *g_defaultCTModel != 0 )
    {
      m_NumModels = this->m_NumModels;
      if ( m_NumModels <= 9 )
      {
        _V_strcpy(dest: this->m_ClassNames[m_NumModels], src: g_defaultCTModel);
        V_snprintf(pDest: this->m_ClassModelPaths[this->m_NumModels], maxLen: 256, pFormat: "models/player/%s.mdl", v9);
        ++this->m_NumModels;
        this->m_NumCTModels = 1;
        return;
      }
      _Warning(
        a1: "PlayerModelInfo: model count has exceeded the maximum (%d) for map \"%s\". Ignoring model %s.\n",
        10,
        this->m_mapName,
        g_defaultCTModel);
    }
    this->m_NumCTModels = 1;
  }
}

} // namespace server
