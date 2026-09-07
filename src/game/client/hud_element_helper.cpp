// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_element_helper.cpp
// Functions: 2
// ============================================================

#include "game\client\hud_element_helper.h"

//------------------------------------------------------------------------------
// Address: 0x10101B10
// Name: public: CHudElementHelper::CHudElementHelper(class CHudElement __near * (*)(void),int,int)
// Source: json
//------------------------------------------------------------------------------
CHudElementHelper *__thiscall CHudElementHelper::CHudElementHelper(
        CHudElementHelper *this,
        CHudElement *(__cdecl *pfnCreate)(),
        int depth,
        int flags)
{
  CHudElementHelper *result; // eax
  CHudElementHelper *v5; // ecx
  CHudElementHelper *i; // edx

  result = this;
  if ( CHudElementHelper::m_sHelpers != nullptr && depth < CHudElementHelper::m_sHelpers->m_iDepth )
  {
    v5 = CHudElementHelper::m_sHelpers;
    for ( i = CHudElementHelper::m_sHelpers->m_pNext; i != nullptr; i = i->m_pNext )
    {
      if ( depth >= i->m_iDepth )
        break;
      v5 = i;
    }
    v5->m_pNext = result;
    result->m_pNext = i;
    result->m_iDepth = depth;
    result->m_iFlags = flags;
    result->m_pfnCreate = pfnCreate;
  }
  else
  {
    this->m_pNext = CHudElementHelper::m_sHelpers;
    CHudElementHelper::m_sHelpers = this;
    this->m_iDepth = depth;
    this->m_iFlags = flags;
    this->m_pfnCreate = pfnCreate;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10101B70
// Name: public: static void CHudElementHelper::CreateAllElements(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudElementHelper::CreateAllElements()
{
  CHudElementHelper *i; // esi
  int v1; // eax
  CHud *Hud; // eax
  vgui::TreeNode *v3; // [esp-4h] [ebp-8h]

  for ( i = CHudElementHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    v1 = (int)i->m_pfnCreate();
    if ( v1 != 0 )
    {
      v3 = (vgui::TreeNode *)v1;
      Hud = GetHud(nSlot: -1);
      CHud::AddHudElement(this: Hud, pHudElement: v3);
    }
  }
}
