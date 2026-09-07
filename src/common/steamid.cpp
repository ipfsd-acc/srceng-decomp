// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/steamid.cpp
// Functions: 1
// ============================================================

#include "common\steamid.h"

//------------------------------------------------------------------------------
// Address: 0x101E2180
// Name: public: char const __near * CSteamID::Render(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSteamID::Render(CSteamID *this)
{
  char *v1; // esi
  int m_unAll64Bits_high; // eax
  int v3; // edx
  int v5; // eax

  v1 = rgchBuf[nBuf];
  nBuf = (nBuf + 1) % 4;
  m_unAll64Bits_high = HIDWORD(this->m_steamid.m_unAll64Bits);
  v3 = ((unsigned int)m_unAll64Bits_high >> 20) & 0xF;
  switch ( v3 )
  {
    case 4:
      V_snprintf(
        pDest: v1,
        maxLen: 255,
        pFormat: "[A:%u:%u(%u)]",
        m_unAll64Bits_high >> 24,
        *(_DWORD *)&this->m_steamid.m_comp,
        m_unAll64Bits_high & 0xFFFFF);
      return v1;
    case 3:
      V_snprintf(
        pDest: v1,
        maxLen: 255,
        pFormat: "[G:%u:%u]",
        m_unAll64Bits_high >> 24,
        *(_DWORD *)&this->m_steamid.m_comp);
      return v1;
    case 2:
      V_snprintf(
        pDest: v1,
        maxLen: 255,
        pFormat: "[M:%u:%u(%u%)]",
        m_unAll64Bits_high >> 24,
        *(_DWORD *)&this->m_steamid.m_comp,
        m_unAll64Bits_high & 0xFFFFF);
      return v1;
    case 5:
      V_snprintf(
        pDest: v1,
        maxLen: 255,
        pFormat: "[P:%u:%u]",
        m_unAll64Bits_high >> 24,
        *(_DWORD *)&this->m_steamid.m_comp);
      return v1;
    case 6:
      V_snprintf(
        pDest: v1,
        maxLen: 255,
        pFormat: "[C-%u:%u]",
        m_unAll64Bits_high >> 24,
        *(_DWORD *)&this->m_steamid.m_comp);
      return v1;
    case 7:
      V_snprintf(
        pDest: v1,
        maxLen: 255,
        pFormat: "[g:%u:%u]",
        m_unAll64Bits_high >> 24,
        *(_DWORD *)&this->m_steamid.m_comp);
      return v1;
    case 8:
      if ( (m_unAll64Bits_high & 0x80000) != 0 )
      {
        V_snprintf(
          pDest: v1,
          maxLen: 255,
          pFormat: "[c:%u:%u]",
          m_unAll64Bits_high >> 24,
          *(_DWORD *)&this->m_steamid.m_comp);
        return v1;
      }
      else
      {
        if ( (m_unAll64Bits_high & 0x40000) != 0 )
          V_snprintf(
            pDest: v1,
            maxLen: 255,
            pFormat: "[L:%u:%u]",
            m_unAll64Bits_high >> 24,
            *(_DWORD *)&this->m_steamid.m_comp);
        else
          V_snprintf(
            pDest: v1,
            maxLen: 255,
            pFormat: "[T:%u:%u]",
            m_unAll64Bits_high >> 24,
            *(_DWORD *)&this->m_steamid.m_comp);
        return v1;
      }
    default:
      v5 = m_unAll64Bits_high >> 24;
      if ( v3 != 0 )
        V_snprintf(pDest: v1, maxLen: 255, pFormat: "[U:%u:%u]", v5, *(_DWORD *)&this->m_steamid.m_comp);
      else
        V_snprintf(pDest: v1, maxLen: 255, pFormat: "[I:%u:%u]", v5, *(_DWORD *)&this->m_steamid.m_comp);
      return v1;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101E2490
// Name: public: char const __near * CSteamID::Render(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSteamID::Render(CSteamID *this)
{
  char *v1; // esi
  int m_unAll64Bits_high; // eax
  int v3; // edx
  int v5; // eax

  v1 = rgchBuf[nBuf];
  nBuf = (nBuf + 1) % 4;
  m_unAll64Bits_high = HIDWORD(this->m_steamid.m_unAll64Bits);
  v3 = ((unsigned int)m_unAll64Bits_high >> 20) & 0xF;
  switch ( v3 )
  {
    case 4:
      V_snprintf(
        pDest: v1,
        maxLen: 255,
        pFormat: "[A:%u:%u(%u)]",
        m_unAll64Bits_high >> 24,
        *(_DWORD *)&this->m_steamid.m_comp,
        m_unAll64Bits_high & 0xFFFFF);
      return v1;
    case 3:
      V_snprintf(
        pDest: v1,
        maxLen: 255,
        pFormat: "[G:%u:%u]",
        m_unAll64Bits_high >> 24,
        *(_DWORD *)&this->m_steamid.m_comp);
      return v1;
    case 2:
      V_snprintf(
        pDest: v1,
        maxLen: 255,
        pFormat: "[M:%u:%u(%u%)]",
        m_unAll64Bits_high >> 24,
        *(_DWORD *)&this->m_steamid.m_comp,
        m_unAll64Bits_high & 0xFFFFF);
      return v1;
    case 5:
      V_snprintf(
        pDest: v1,
        maxLen: 255,
        pFormat: "[P:%u:%u]",
        m_unAll64Bits_high >> 24,
        *(_DWORD *)&this->m_steamid.m_comp);
      return v1;
    case 6:
      V_snprintf(
        pDest: v1,
        maxLen: 255,
        pFormat: "[C-%u:%u]",
        m_unAll64Bits_high >> 24,
        *(_DWORD *)&this->m_steamid.m_comp);
      return v1;
    case 7:
      V_snprintf(
        pDest: v1,
        maxLen: 255,
        pFormat: "[g:%u:%u]",
        m_unAll64Bits_high >> 24,
        *(_DWORD *)&this->m_steamid.m_comp);
      return v1;
    case 8:
      if ( (m_unAll64Bits_high & 0x80000) != 0 )
      {
        V_snprintf(
          pDest: v1,
          maxLen: 255,
          pFormat: "[c:%u:%u]",
          m_unAll64Bits_high >> 24,
          *(_DWORD *)&this->m_steamid.m_comp);
        return v1;
      }
      else
      {
        if ( (m_unAll64Bits_high & 0x40000) != 0 )
          V_snprintf(
            pDest: v1,
            maxLen: 255,
            pFormat: "[L:%u:%u]",
            m_unAll64Bits_high >> 24,
            *(_DWORD *)&this->m_steamid.m_comp);
        else
          V_snprintf(
            pDest: v1,
            maxLen: 255,
            pFormat: "[T:%u:%u]",
            m_unAll64Bits_high >> 24,
            *(_DWORD *)&this->m_steamid.m_comp);
        return v1;
      }
    default:
      v5 = m_unAll64Bits_high >> 24;
      if ( v3 != 0 )
        V_snprintf(pDest: v1, maxLen: 255, pFormat: "[U:%u:%u]", v5, *(_DWORD *)&this->m_steamid.m_comp);
      else
        V_snprintf(pDest: v1, maxLen: 255, pFormat: "[I:%u:%u]", v5, *(_DWORD *)&this->m_steamid.m_comp);
      return v1;
  }
}

} // namespace engine_xlsp
