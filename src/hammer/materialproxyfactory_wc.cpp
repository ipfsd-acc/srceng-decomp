// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/materialproxyfactory_wc.cpp
// Functions: 9
// ============================================================

#include "hammer\materialproxyfactory_wc.h"

//------------------------------------------------------------------------------
// Address: 0x10086050
// Name: protected: virtual IMaterialProxy::~IMaterialProxy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IMaterialProxy::~IMaterialProxy(IMaterialProxy *this)
{
  this->__vftable = (IMaterialProxy_vtbl *)&IMaterialProxy::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10086090
// Name: public: virtual class IMaterialProxy __near * CMaterialProxyFactory::CreateProxy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__thiscall CMaterialProxyFactory::CreateProxy(CMaterialProxyFactory *this, const char *proxyName)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // esi
  char proxyVersionedName[512]; // [esp+4h] [ebp-200h] BYREF

  FactoryThis = Sys_GetFactoryThis();
  V_snprintf(pDest: proxyVersionedName, maxLen: 512, pFormat: "%s%s", proxyName, "_IMaterialProxy003");
  return (IMaterialProxy *)FactoryThis(a1: proxyVersionedName, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100860E0
// Name: public: virtual void CMaterialProxyFactory::DeleteProxy(class IMaterialProxy __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialProxyFactory::DeleteProxy(CMaterialProxyFactory *this, IMaterialProxy *pProxy)
{
  if ( pProxy != nullptr )
    pProxy->Release(this: pProxy);
}

//------------------------------------------------------------------------------
// Address: 0x10086100
// Name: public: virtual void __near * (*CMaterialProxyFactory::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void *(__cdecl *__thiscall CMaterialProxyFactory::GetFactory(CMaterialProxyFactory *this))(const char *, int *)
{
  return Sys_GetFactoryThis();
}

//------------------------------------------------------------------------------
// Address: 0x10086110
// Name: public: virtual void CWorldDimsProxy::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldDimsProxy::Release(CWorldDimsProxy *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CWorldDimsProxy *, int))this->dtr_IMaterialProxy)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10086120
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
// Address: 0x10086160
// Name: public: virtual void CWorldDimsProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldDimsProxy::OnBind(CWorldDimsProxy *this, void *pC_BaseEntity)
{
  IMaterialVar *m_pMinsVar; // ecx
  float maxs[3]; // [esp+4h] [ebp-18h] BYREF
  float mins[3]; // [esp+10h] [ebp-Ch] BYREF

  if ( this->m_pMinsVar != nullptr && this->m_pMaxsVar != nullptr )
  {
    m_pMinsVar = this->m_pMinsVar;
    mins[0] = -500.0;
    mins[1] = -500.0;
    mins[2] = -500.0;
    maxs[0] = 500.0;
    maxs[1] = 500.0;
    maxs[2] = 500.0;
    m_pMinsVar->SetVecValue_4(this: m_pMinsVar, a2: mins, a3: 3);
    this->m_pMaxsVar->SetVecValue_4(this: this->m_pMaxsVar, a2: maxs, a3: 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100861D0
// Name: public: virtual class IMaterial __near * CWorldDimsProxy::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CWorldDimsProxy::GetMaterial(CWorldDimsProxy *this)
{
  if ( this->m_pMinsVar != nullptr && this->m_pMaxsVar != nullptr )
    return this->m_pMinsVar->GetOwningMaterial(this: this->m_pMinsVar);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10086250
// Name: __CreateCWorldDimsProxy_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl _CreateCWorldDimsProxy_interface()
{
  _DWORD *result; // eax

  result = operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  *result = &IMaterialProxy::`vftable';
  *result = &CWorldDimsProxy::`vftable';
  result[2] = 0;
  result[1] = 0;
  return result;
}
