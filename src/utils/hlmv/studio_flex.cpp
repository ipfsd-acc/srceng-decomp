// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/studio_flex.cpp
// Functions: 1
// ============================================================

#include "utils\hlmv\studio_flex.h"

//------------------------------------------------------------------------------
// Address: 0x00415160
// Name: public: virtual void StudioModel::RunFlexRules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::RunFlexRules(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // ecx
  const studiohdr_t *v3; // eax
  const studiohdr_t *v4; // eax
  int v5; // edi
  int v6; // esi
  char *v7; // edx
  unsigned int v8; // eax
  float src[384]; // [esp+8h] [ebp-604h] BYREF
  float *m_flexweight; // [esp+608h] [ebp-4h]

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  v4 = m_pStudioHdr->m_pStudioHdr;
  v5 = 0;
  if ( m_pStudioHdr->m_pStudioHdr->numflexcontrollers > 0 )
  {
    v6 = 0;
    m_flexweight = this->m_flexweight;
    do
    {
      v7 = (char *)v4 + v6 + v4->flexcontrollerindex;
      v8 = *((_DWORD *)v7 + 2);
      if ( v8 <= 0x17F )
        src[v8] = (float)((float)(*((float *)v7 + 4) - *((float *)v7 + 3)) * *m_flexweight) + *((float *)v7 + 3);
      v4 = m_pStudioHdr->m_pStudioHdr;
      ++m_flexweight;
      ++v5;
      v6 += 20;
    }
    while ( v5 < v4->numflexcontrollers );
  }
  CStudioHdr::RunFlexRules(this: m_pStudioHdr, src, dest: g_flexdescweight);
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0041F9E0
// Name: public: virtual void StudioModel::RunFlexRules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::RunFlexRules(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // ecx
  const studiohdr_t *v3; // eax
  const studiohdr_t *v4; // eax
  int v5; // edi
  int v6; // esi
  char *v7; // edx
  unsigned int v8; // eax
  float src[384]; // [esp+8h] [ebp-604h] BYREF
  float *m_flexweight; // [esp+608h] [ebp-4h]

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  v4 = m_pStudioHdr->m_pStudioHdr;
  v5 = 0;
  if ( m_pStudioHdr->m_pStudioHdr->numflexcontrollers > 0 )
  {
    v6 = 0;
    m_flexweight = this->m_flexweight;
    do
    {
      v7 = (char *)v4 + v6 + v4->flexcontrollerindex;
      v8 = *((_DWORD *)v7 + 2);
      if ( v8 <= 0x17F )
        src[v8] = (float)((float)(*((float *)v7 + 4) - *((float *)v7 + 3)) * *m_flexweight) + *((float *)v7 + 3);
      v4 = m_pStudioHdr->m_pStudioHdr;
      ++m_flexweight;
      ++v5;
      v6 += 20;
    }
    while ( v5 < v4->numflexcontrollers );
  }
  CStudioHdr::RunFlexRules(this: m_pStudioHdr, src, dest: g_flexdescweight);
}

} // namespace hlmv
