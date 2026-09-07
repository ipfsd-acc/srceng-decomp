// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gl_draw.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100C32F0
// Name: void GL_UnloadMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GL_UnloadMaterial(IMaterial *pMaterial)
{
  if ( pMaterial != nullptr )
    pMaterial->DecrementReferenceCount(this: pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x100C3310
// Name: class IMaterial __near * GL_LoadMaterial(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl GL_LoadMaterial(const char *pName, const char *pTextureGroupName, bool bPrecache)
{
  IMaterial *v3; // esi

  if ( mat_loadtextures.m_pParent != nullptr && mat_loadtextures.m_pParent->m_Value.m_nValue != 0 )
    v3 = materials->FindMaterial(this: materials, a2: pName, a3: pTextureGroupName, a4: 1, a5: 0);
  else
    v3 = g_materialEmpty;
  if ( v3 != nullptr )
  {
    v3->IncrementReferenceCount(this: v3);
    if ( bPrecache )
      v3->GetMappingWidth(this: v3);
  }
  return v3;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100C2F20
// Name: void GL_UnloadMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GL_UnloadMaterial(IMaterial *pMaterial)
{
  if ( pMaterial != nullptr )
    pMaterial->DecrementReferenceCount(this: pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x100C2F40
// Name: class IMaterial __near * GL_LoadMaterial(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl GL_LoadMaterial(const char *pName, const char *pTextureGroupName, bool bPrecache)
{
  IMaterial *v3; // esi

  if ( mat_loadtextures.m_pParent != nullptr && mat_loadtextures.m_pParent->m_Value.m_nValue != 0 )
    v3 = materials->FindMaterial(this: materials, a2: pName, a3: pTextureGroupName, a4: 1, a5: 0);
  else
    v3 = g_materialEmpty;
  if ( v3 != nullptr )
  {
    v3->IncrementReferenceCount(this: v3);
    if ( bPrecache )
      v3->GetMappingWidth(this: v3);
  }
  return v3;
}

} // namespace engine_xlsp
