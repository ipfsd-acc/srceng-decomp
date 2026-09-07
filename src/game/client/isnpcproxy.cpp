// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/isnpcproxy.cpp
// Functions: 2
// ============================================================

#include "game\client\isnpcproxy.h"

//------------------------------------------------------------------------------
// Address: 0x10119630
// Name: public: virtual void CProxyIsNPC::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProxyIsNPC::OnBind(CProxyIsNPC *this, int (__thiscall ***pC_BaseEntity)(_DWORD))
{
  C_BaseEntity *v3; // eax
  int result; // [esp+0h] [ebp-8h]

  if ( pC_BaseEntity != nullptr )
  {
    v3 = CResultProxy::BindArgToEntity(this, pArg: pC_BaseEntity);
    if ( v3 != nullptr && v3->IsNPC(this: v3) )
    {
      *(float *)&result = CFloatInput::GetFloat(this: &this->m_Factor);
      CResultProxy::SetFloatResult(this, result);
    }
    else
    {
      CResultProxy::SetFloatResult(this, result: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119690
// Name: CCProxyIsNPCFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCProxyIsNPCFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x18u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CProxyIsNPC::`vftable';
  return (IMaterialProxy *)v1;
}
