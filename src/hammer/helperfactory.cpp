// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/helperfactory.cpp
// Functions: 1
// ============================================================

#include "hammer\helperfactory.h"

//------------------------------------------------------------------------------
// Address: 0x10045FA0
// Name: public: static class CMapClass __near * CHelperFactory::CreateHelper(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CHelperFactory::CreateHelper(CHelperInfo *pHelperInfo, CMapEntity *pParent)
{
  int v2; // esi

  v2 = 0;
  while ( _V_stricmp(s1: HelperFactoryMap[v2].pszName, s2: pHelperInfo->m_szName) != 0 )
  {
    if ( (unsigned int)++v2 >= 0x1C )
      return nullptr;
  }
  return HelperFactoryMap[v2].pfnFactory(a1: pHelperInfo, a2: pParent);
}
