// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/toggletextureproxy.cpp
// Functions: 4
// ============================================================

#include "game\client\toggletextureproxy.h"

//------------------------------------------------------------------------------
// Address: 0x1017A3E0
// Name: public: virtual bool CBaseToggleTextureProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseToggleTextureProxy::Init(
        CBaseToggleTextureProxy *this,
        IMaterial *pMaterial,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  char *String; // eax
  IMaterialVar *v7; // eax
  bool v8; // zf
  char *v9; // eax
  IMaterialVar *v10; // eax

  v3 = pKeyValues;
  String = KeyValues::GetString(this: pKeyValues, keyName: "toggleTextureVar", defaultValue: prType);
  if ( String == nullptr )
    return 0;
  v7 = pMaterial->FindVar(this: pMaterial, a2: String, a3: (char *)&pKeyValues + 3, a4: 0);
  v8 = HIBYTE(pKeyValues) == 0;
  this->m_TextureVar = v7;
  if ( v8 )
    return 0;
  v9 = KeyValues::GetString(this: v3, keyName: "toggleTextureFrameNumVar", defaultValue: prType);
  if ( v9 == nullptr )
    return 0;
  v10 = pMaterial->FindVar(this: pMaterial, a2: v9, a3: (char *)&pKeyValues + 3, a4: 0);
  v8 = HIBYTE(pKeyValues) == 0;
  this->m_TextureFrameNumVar = v10;
  if ( v8 )
    return 0;
  this->m_WrapAnimation = KeyValues::GetInt(this: v3, keyName: "toggleShouldWrap", defaultValue: 1) != 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017A480
// Name: public: virtual void CBaseToggleTextureProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseToggleTextureProxy::OnBind(
        CBaseToggleTextureProxy *this@<ecx>,
        int a2@<esi>,
        int (__thiscall ***pC_BaseEntity)(_DWORD))
{
  IMaterialVar *m_TextureVar; // eax
  int v5; // esi
  int v6; // eax
  C_BaseEntity *v7; // edi
  int v8; // esi
  int TextureFrameIndex; // ecx
  int v10; // edx

  if ( pC_BaseEntity != nullptr )
  {
    m_TextureVar = this->m_TextureVar;
    if ( (*((_BYTE *)m_TextureVar + 28) & 0xF) == 3 )
    {
      v5 = ((int (*)(void))m_TextureVar->GetTextureValue)();
      if ( v5 != 0 )
      {
        v6 = (**pC_BaseEntity)(a1: pC_BaseEntity);
        v7 = (C_BaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 28))(a1: v6);
        if ( v7 != nullptr )
        {
          v8 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 20))(a1: v5, a2);
          TextureFrameIndex = C_BaseEntity::GetTextureFrameIndex(this: v7);
          v10 = TextureFrameIndex % v8;
          if ( !this->m_WrapAnimation && TextureFrameIndex > v8 )
            v10 = v8;
          this->m_TextureFrameNumVar->SetIntValue(this: this->m_TextureFrameNumVar, a2: v10);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A500
// Name: public: virtual class IMaterial __near * CBaseToggleTextureProxy::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CBaseToggleTextureProxy::GetMaterial(CBaseToggleTextureProxy *this)
{
  return this->m_TextureFrameNumVar->GetOwningMaterial(this: this->m_TextureFrameNumVar);
}

//------------------------------------------------------------------------------
// Address: 0x1017A510
// Name: CCBaseToggleTextureProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCBaseToggleTextureProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0x10u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CBaseToggleTextureProxy::`vftable';
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  return result;
}
