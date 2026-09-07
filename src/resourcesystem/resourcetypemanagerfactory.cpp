// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: resourcesystem/resourcetypemanagerfactory.cpp
// Functions: 1
// ============================================================

#include "resourcesystem\resourcetypemanagerfactory.h"

//------------------------------------------------------------------------------
// Address: 0x10008810
// Name: public: static class CResourceTypeManagerBase __near * CResourceTypeManagerFactoryBase::CreateResourceTypeManager(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CResourceTypeManagerBase *__cdecl CResourceTypeManagerFactoryBase::CreateResourceTypeManager(
        const char *pTypeManagerName)
{
  CResourceTypeManagerFactoryBase *v1; // esi
  const char *v2; // eax
  CResourceTypeManagerBase *v4; // edi

  v1 = CResourceTypeManagerFactoryBase::sm_pFactoryList;
  if ( CResourceTypeManagerFactoryBase::sm_pFactoryList != nullptr )
  {
    while ( 1 )
    {
      v2 = (const char *)v1->GetTypeManagerName(this: v1);
      if ( _V_stricmp(s1: pTypeManagerName, s2: v2) == 0 )
        break;
      v1 = v1->m_pNext;
      if ( v1 == nullptr )
        goto LABEL_4;
    }
    v4 = v1->Create(this: v1);
    CResourceTypeManagerBase::SetFactory(this: v4, pFactory: v1);
    return v4;
  }
  else
  {
LABEL_4:
    _Warning(a1: "Requested unknown resource type manager factory %s\n", pTypeManagerName);
    return nullptr;
  }
}
