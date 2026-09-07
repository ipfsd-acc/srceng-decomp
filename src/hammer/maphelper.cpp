// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/maphelper.cpp
// Functions: 1
// ============================================================

#include "hammer\maphelper.h"

//------------------------------------------------------------------------------
// Address: 0x1012E990
// Name: public: virtual class CMapClass __near * CMapHelper::PrepareSelection(enum SelectMode_t)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapHelper::PrepareSelection(CMapHelper *this, SelectMode_t eSelectMode)
{
  CMapClass *v3; // eax

  if ( this->m_pParent == nullptr || IsWorldObject(pObject: this->m_pParent) )
    return nullptr;
  v3 = this->GetParent(this);
  return v3->PrepareSelection(this: v3, a2: eSelectMode);
}
