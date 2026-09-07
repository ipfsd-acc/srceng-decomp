// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/materialproxydict.cpp
// Functions: 3
// ============================================================

#include "game\client\materialproxydict.h"

//------------------------------------------------------------------------------
// Address: 0x1011C650
// Name: public: virtual class IMaterialProxy __near * CMaterialProxyDict::CreateProxy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__thiscall CMaterialProxyDict::CreateProxy(CMaterialProxyDict *this, const char *pMaterialProxyName)
{
  int m_Id; // eax

  m_Id = CUtlSymbolTable::Find(
           this: &this->m_StringToProxyFactoryMap.m_SymbolTable,
           result: (CUtlSymbol *)&pMaterialProxyName + 1,
           pString: pMaterialProxyName)->m_Id;
  if ( (_WORD)m_Id == 0xFFFF )
    return nullptr;
  else
    return this->m_StringToProxyFactoryMap.m_Vector.m_Memory.m_pMemory[m_Id]();
}

//------------------------------------------------------------------------------
// Address: 0x1011C6D0
// Name: public: virtual void CMaterialProxyDict::Add(char const __near *,class IMaterialProxy __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialProxyDict::Add(
        CMaterialProxyDict *this,
        const char *pMaterialProxyName,
        IMaterialProxy *(__cdecl *pMaterialProxyFactory)())
{
  CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *p_m_StringToProxyFactoryMap; // esi
  int v4; // edi
  int m_Size; // ecx

  p_m_StringToProxyFactoryMap = (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)&this->m_StringToProxyFactoryMap;
  CUtlSymbolTable::AddString(
    this: &this->m_StringToProxyFactoryMap.m_SymbolTable,
    result: (CUtlSymbol *)&pMaterialProxyName,
    pString: pMaterialProxyName);
  v4 = (unsigned __int16)pMaterialProxyName;
  m_Size = p_m_StringToProxyFactoryMap->m_Size;
  if ( m_Size > (unsigned __int16)pMaterialProxyName )
  {
    p_m_StringToProxyFactoryMap->m_Memory.m_pMemory[(unsigned __int16)pMaterialProxyName] = (CParticleSystemDefinition *)pMaterialProxyFactory;
  }
  else if ( m_Size >= (unsigned __int16)pMaterialProxyName + 1 )
  {
    p_m_StringToProxyFactoryMap->m_Memory.m_pMemory[(unsigned __int16)pMaterialProxyName] = (CParticleSystemDefinition *)pMaterialProxyFactory;
  }
  else
  {
    CUtlVector<IKeyBindingListener *,CUtlMemory<IKeyBindingListener *,int>>::InsertMultipleBefore(
      this: p_m_StringToProxyFactoryMap,
      elem: m_Size,
      num: (unsigned __int16)pMaterialProxyName + 1 - m_Size);
    p_m_StringToProxyFactoryMap->m_Memory.m_pMemory[v4] = (CParticleSystemDefinition *)pMaterialProxyFactory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C730
// Name: class IMaterialProxyDict __near & GetMaterialProxyDict(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialProxyDict *__cdecl GetMaterialProxyDict()
{
  if ( (_S5_104 & 1) == 0 )
  {
    _S5_104 |= 1u;
    g_MaterialProxyDict.__vftable = (CMaterialProxyDict_vtbl *)&CMaterialProxyDict::`vftable';
    g_MaterialProxyDict.m_StringToProxyFactoryMap.m_Vector.m_Memory.m_pMemory = nullptr;
    g_MaterialProxyDict.m_StringToProxyFactoryMap.m_Vector.m_Memory.m_nAllocationCount = 0;
    g_MaterialProxyDict.m_StringToProxyFactoryMap.m_Vector.m_Memory.m_nGrowSize = 32;
    g_MaterialProxyDict.m_StringToProxyFactoryMap.m_Vector.m_Size = 0;
    g_MaterialProxyDict.m_StringToProxyFactoryMap.m_Vector.m_pElements = nullptr;
    CUtlSymbolTable::CUtlSymbolTable(
      this: &g_MaterialProxyDict.m_StringToProxyFactoryMap.m_SymbolTable,
      growSize: 0,
      initSize: 32,
      caseInsensitive: true);
    atexit(func: GetMaterialProxyDict_::_2_::_dynamic_atexit_destructor_for__g_MaterialProxyDict__);
  }
  return &g_MaterialProxyDict;
}
