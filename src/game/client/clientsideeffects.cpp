// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/clientsideeffects.cpp
// Functions: 7
// ============================================================

#include "game\client\clientsideeffects.h"

//------------------------------------------------------------------------------
// Address: 0x100BEAF0
// Name: void SetFXCreationAllowed(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetFXCreationAllowed(bool state)
{
  g_FXCreationAllowed = state;
}

//------------------------------------------------------------------------------
// Address: 0x100BEB00
// Name: public: CClientSideEffect::CClientSideEffect(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CClientSideEffect *__thiscall CClientSideEffect::CClientSideEffect(CClientSideEffect *this, const char *name)
{
  this->__vftable = (CClientSideEffect_vtbl *)&CClientSideEffect::`vftable';
  this->m_pszName = name;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BEB20
// Name: public: virtual CClientSideEffect::~CClientSideEffect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientSideEffect::~CClientSideEffect(CClientSideEffect *this)
{
  this->__vftable = (CClientSideEffect_vtbl *)&CClientSideEffect::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100BEB30
// Name: public: virtual void CClientSideEffect::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientSideEffect::Destroy(CClientSideEffect *this)
{
  this->m_bActive = false;
}

//------------------------------------------------------------------------------
// Address: 0x100BEB40
// Name: public: virtual void CEffectsList::AddEffect(class CClientSideEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsList::AddEffect(CEffectsList *this, CClientSideEffect *effect)
{
  int m_nEffects; // edx
  const char *v3; // eax

  if ( effect != nullptr )
  {
    m_nEffects = this->m_nEffects;
    if ( m_nEffects < 256 )
    {
      this->m_rgEffects[m_nEffects] = effect;
      ++this->m_nEffects;
    }
    else
    {
      v3 = (const char *)((int (*)(void))effect->GetName)();
      _DevWarning(a1: 1, a2: "No room for effect %s\n", v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BEB80
// Name: public: virtual void CEffectsList::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsList::Flush(CEffectsList *this)
{
  int v2; // esi
  CClientSideEffect **v3; // ecx
  CClientSideEffect *v4; // edi
  int m_nEffects; // eax
  int v6; // eax
  CClientSideEffect **v7; // [esp+8h] [ebp-4h]

  v2 = this->m_nEffects - 1;
  if ( v2 >= 0 )
  {
    v3 = &this->m_rgEffects[v2];
    v7 = &this->m_rgEffects[v2];
    do
    {
      v4 = *v3;
      if ( *v3 != nullptr )
      {
        m_nEffects = this->m_nEffects;
        if ( v2 < m_nEffects )
        {
          v6 = m_nEffects - 1;
          this->m_nEffects = v6;
          if ( v6 > 0 && v2 != v6 )
            *v3 = this->m_rgEffects[v6];
          v4->Destroy(this: v4);
          ((void (__thiscall *)(CClientSideEffect *, int))v4->dtr_CClientSideEffect)(a1: v4, a2: 1);
          v3 = v7;
        }
      }
      --v3;
      --v2;
      v7 = v3;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BEC10
// Name: public: virtual void CEffectsList::DrawEffects(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsList::DrawEffects(CEffectsList *this, long double frametime)
{
  int v3; // esi
  CClientSideEffect **v4; // edi
  CClientSideEffect *v5; // ebx
  int m_nEffects; // eax
  CClientSideEffect *v7; // ebx
  int v8; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CEffectsList::DrawEffects",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  v3 = this->m_nEffects - 1;
  if ( v3 >= 0 )
  {
    v4 = &this->m_rgEffects[v3];
    do
    {
      v5 = *v4;
      if ( *v4 != nullptr )
      {
        ((void (__thiscall *)(CClientSideEffect *, _DWORD, _DWORD))v5->Draw)(
          a1: *v4,
          a2: LODWORD(frametime),
          a3: HIDWORD(frametime));
        if ( !v5->IsActive(this: v5) )
        {
          m_nEffects = this->m_nEffects;
          if ( v3 < m_nEffects )
          {
            v7 = *v4;
            v8 = m_nEffects - 1;
            this->m_nEffects = v8;
            if ( v8 > 0 && v3 != v8 )
              *v4 = this->m_rgEffects[v8];
            v7->Destroy(this: v7);
            ((void (__thiscall *)(CClientSideEffect *, int))v7->dtr_CClientSideEffect)(a1: v7, a2: 1);
          }
        }
      }
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}
