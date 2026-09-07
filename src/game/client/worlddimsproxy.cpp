// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/worlddimsproxy.cpp
// Functions: 3
// ============================================================

#include "game\client\worlddimsproxy.h"

//------------------------------------------------------------------------------
// Address: 0x101AE750
// Name: public: virtual bool CWorldDimsProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorldDimsProxy::Init(CWorldDimsProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  this->m_pMinsVar = pMaterial->FindVar(this: pMaterial, a2: "$world_mins", a3: 0, a4: 0);
  this->m_pMaxsVar = pMaterial->FindVar(this: pMaterial, a2: "$world_maxs", a3: 0, a4: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AE790
// Name: public: virtual void CWorldDimsProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldDimsProxy::OnBind(CWorldDimsProxy *this, void *pC_BaseEntity)
{
  C_World *ClientWorldEntity; // edi

  if ( this->m_pMinsVar != nullptr && this->m_pMaxsVar != nullptr )
  {
    ClientWorldEntity = GetClientWorldEntity();
    if ( ClientWorldEntity != nullptr )
    {
      this->m_pMinsVar->SetVecValue_4(this: this->m_pMinsVar, a2: (const float *)&ClientWorldEntity->m_WorldMins, a3: 3);
      this->m_pMaxsVar->SetVecValue_4(this: this->m_pMaxsVar, a2: (const float *)&ClientWorldEntity->m_WorldMaxs, a3: 3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AE7E0
// Name: CCWorldDimsProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCWorldDimsProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CWorldDimsProxy::`vftable';
  result[2].__vftable = nullptr;
  result[1].__vftable = nullptr;
  return result;
}
