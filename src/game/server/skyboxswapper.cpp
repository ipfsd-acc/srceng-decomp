// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/skyboxswapper.cpp
// Functions: 7
// ============================================================

#include "game\server\skyboxswapper.h"

//------------------------------------------------------------------------------
// Address: 0x10213CC0
// Name: public: virtual struct datamap_t __near * CSkyboxSwapper::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSkyboxSwapper::GetDataDescMap(CSkyboxSwapper *this)
{
  return &CSkyboxSwapper::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10213CE0
// Name: public: virtual void CSkyboxSwapper::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSkyboxSwapper::Precache(CSkyboxSwapper *this)
{
  const char *pszValue; // eax
  const char *v3; // eax
  int i; // esi
  const char *v5; // eax
  char name[260]; // [esp+4h] [ebp-11Ch] BYREF
  char *skyboxsuffix[6]; // [esp+108h] [ebp-18h]

  pszValue = this->m_iszSkyboxName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( _V_strlen(str: pszValue) != 0 )
  {
    skyboxsuffix[0] = "rt";
    skyboxsuffix[1] = "bk";
    skyboxsuffix[2] = "lf";
    skyboxsuffix[3] = "ft";
    skyboxsuffix[4] = "up";
    skyboxsuffix[5] = "dn";
    for ( i = 0; i < 6; ++i )
    {
      v5 = this->m_iszSkyboxName.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      V_snprintf(pDest: name, maxLen: 260, pFormat: "skybox/%s%s", v5, skyboxsuffix[i]);
      PrecacheMaterial(pMaterialName: name);
    }
  }
  else
  {
    v3 = this->m_iName.m_Value.pszValue;
    if ( v3 == nullptr )
      v3 = locale;
    _Warning(a1: "skybox_swapper (%s) has no skybox specified!\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213DB0
// Name: public: void CSkyboxSwapper::InputTrigger(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSkyboxSwapper::InputTrigger(CSkyboxSwapper *this, inputdata_t *inputdata)
{
  const char *v3; // esi
  const char *pszValue; // esi

  if ( (_S3_114 & 1) == 0 )
  {
    _S3_114 |= 1u;
    ConVarRef::ConVarRef(this: &skyname, pName: "sv_skyname", bIgnoreMissing: false);
  }
  if ( ConVarRef::IsValid(this: &skyname) )
  {
    pszValue = this->m_iszSkyboxName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    skyname.m_pConVar->SetValue_4(this: skyname.m_pConVar, a2: pszValue);
  }
  else
  {
    v3 = this->m_iName.m_Value.pszValue;
    if ( v3 == nullptr )
      v3 = locale;
    _Warning(a1: "skybox_swapper (%s) trigger input failed - cannot find 'sv_skyname' convar!\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10409D90
// Name: _dynamic_initializer_for__skybox_swapper__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__skybox_swapper__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSkyboxSwapper> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &skybox_swapper,
           a3: "skybox_swapper");
}

//------------------------------------------------------------------------------
// Address: 0x10409DB0
// Name: CSkyboxSwapper_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSkyboxSwapper_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSkyboxSwapper>();
  CSkyboxSwapper_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409DC0
// Name: _dynamic_initializer_for__g_SkyList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SkyList__()
{
  CBaseEntityClassList::CBaseEntityClassList(this: &g_SkyList);
  g_SkyList.__vftable = (CEntityClassList<CSkyCamera>_vtbl *)&CEntityClassList<CSkyCamera>::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_SkyList__);
}

//------------------------------------------------------------------------------
// Address: 0x10409DE0
// Name: _dynamic_initializer_for__sky_camera__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sky_camera__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSkyCamera> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &sky_camera,
           a3: "sky_camera");
}
