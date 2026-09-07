// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/bvh/bvhvertexformats.cpp
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040C8C0
// Name: float fabs(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl fabs(float _X)
{
  return fabs(_X);
}

//------------------------------------------------------------------------------
// Address: 0x0040C8D0
// Name: void CrossProduct(class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CrossProduct(const Vector *a, const Vector *b, Vector *result)
{
  result->x = (float)(b->z * a->y) - (float)(a->z * b->y);
  result->y = (float)(a->z * b->x) - (float)(a->x * b->z);
  result->z = (float)(a->x * b->y) - (float)(b->x * a->y);
}

//------------------------------------------------------------------------------
// Address: 0x0040C930
// Name: int GetStrideForInputLayout(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetStrideForInputLayout(int nLayout)
{
  int result; // eax

  switch ( nLayout )
  {
    case 0:
    case 2:
      result = 36;
      break;
    case 1:
    case 3:
      result = 52;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C970
// Name: class CMeshVertexAttribute __near * GetAttributesForInputLayout(int)
// Source: json
//------------------------------------------------------------------------------
CMeshVertexAttribute *__cdecl GetAttributesForInputLayout(int nLayout)
{
  CMeshVertexAttribute *result; // eax

  switch ( nLayout )
  {
    case 0:
    case 2:
      result = g_pPOS3_NORM3_TEX3_Attrib;
      break;
    case 1:
    case 3:
      result = g_pPOS3_NORM3_TEX3_TAN4_Attrib;
      break;
    default:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C9B0
// Name: int GetAttributeCountForInputLayout(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAttributeCountForInputLayout(int nLayout)
{
  int result; // eax

  switch ( nLayout )
  {
    case 0:
    case 2:
      result = 3;
      break;
    case 1:
    case 3:
      result = 4;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C9F0
// Name: struct RenderInputLayoutField_t __near * GetLayoutFields(int)
// Source: json
//------------------------------------------------------------------------------
RenderInputLayoutField_t *__cdecl GetLayoutFields(int nLayout)
{
  RenderInputLayoutField_t *result; // eax

  switch ( nLayout )
  {
    case 0:
      result = g_POS3_NORM3_TEX3_Layout;
      break;
    case 1:
      result = g_POS3_NORM3_TEX3_TAN4_Layout;
      break;
    case 2:
      result = g_POS3_NORM3_TEX3_TRANSFORM3x4_Layout;
      break;
    case 3:
      result = g_POS3_NORM3_TEX3_TAN4_TRANSFORM3x4_Layout;
      break;
    default:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040CA40
// Name: int GetNumFields(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetNumFields(int nLayout)
{
  int result; // eax

  switch ( nLayout )
  {
    case 0:
      result = 3;
      break;
    case 1:
      result = 4;
      break;
    case 2:
      result = 6;
      break;
    case 3:
      result = 7;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040CA90
// Name: char __near * GetNameForInputLayout(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetNameForInputLayout(int nLayout)
{
  return g_szLayoutNames[nLayout];
}
