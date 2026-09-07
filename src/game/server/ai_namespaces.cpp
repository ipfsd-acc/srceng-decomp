// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_namespaces.cpp
// Functions: 11
// ============================================================

#include "game\server\ai_namespaces.h"

//------------------------------------------------------------------------------
// Address: 0x10062440
// Name: public: CAI_GlobalNamespace::CAI_GlobalNamespace(void)
// Source: json
//------------------------------------------------------------------------------
CAI_GlobalNamespace *__thiscall CAI_GlobalNamespace::CAI_GlobalNamespace(CAI_GlobalNamespace *this)
{
  CStringRegistry *v2; // eax

  v2 = (CStringRegistry *)operator new(nSize: 4u);
  if ( v2 != nullptr )
    this->m_pSymbols = CStringRegistry::CStringRegistry(this: v2);
  else
    this->m_pSymbols = nullptr;
  this->m_NextGlobalBase = 1000000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062480
// Name: public: void CAI_GlobalNamespace::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GlobalNamespace::Clear(CAI_GlobalNamespace *this)
{
  CStringRegistry::ClearStrings(this: this->m_pSymbols);
  this->m_NextGlobalBase = 1000000000;
}

//------------------------------------------------------------------------------
// Address: 0x100624A0
// Name: public: void CAI_GlobalNamespace::AddSymbol(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GlobalNamespace::AddSymbol(CAI_GlobalNamespace *this, const char *pszSymbol, int symbolID)
{
  if ( symbolID != -1 )
  {
    CStringRegistry::AddString(this: this->m_pSymbols, stringText: pszSymbol, stringID: symbolID);
    if ( this->m_NextGlobalBase < symbolID + 1 )
      this->m_NextGlobalBase = symbolID + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100624D0
// Name: public: char const __near * CAI_GlobalNamespace::IdToSymbol(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAI_GlobalNamespace::IdToSymbol(CAI_GlobalNamespace *this, int symbolID)
{
  if ( symbolID == -1 )
    return "<<null>>";
  else
    return CStringRegistry::GetStringText(this: this->m_pSymbols, stringID: symbolID);
}

//------------------------------------------------------------------------------
// Address: 0x100624F0
// Name: public: int CAI_GlobalNamespace::SymbolToId(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_GlobalNamespace::SymbolToId(CAI_GlobalNamespace *this, const char *pszSymbol)
{
  return CStringRegistry::GetStringID(this: this->m_pSymbols, stringText: pszSymbol);
}

//------------------------------------------------------------------------------
// Address: 0x10062500
// Name: public: CAI_LocalIdSpace::CAI_LocalIdSpace(bool)
// Source: json
//------------------------------------------------------------------------------
CAI_LocalIdSpace *__thiscall CAI_LocalIdSpace::CAI_LocalIdSpace(CAI_LocalIdSpace *this, bool fIsRoot)
{
  this->m_pParentIDSpace = nullptr;
  this->m_pGlobalNamespace = nullptr;
  this->m_globalBase = fIsRoot - 1;
  this->m_localBase = fIsRoot ? 0 : 0x270F;
  this->m_localTop = -1;
  this->m_globalTop = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062540
// Name: public: bool CAI_LocalIdSpace::Init(class CAI_GlobalNamespace __near *,class CAI_LocalIdSpace __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_LocalIdSpace::Init(
        CAI_LocalIdSpace *this,
        CAI_GlobalNamespace *pGlobalNamespace,
        CAI_LocalIdSpace *pParentIDSpace)
{
  if ( this->m_globalTop != -1 )
  {
    this->m_localBase = pParentIDSpace != nullptr ? 0x270F : 0;
    this->m_localTop = -1;
    this->m_globalTop = -1;
  }
  this->m_pParentIDSpace = pParentIDSpace;
  this->m_pGlobalNamespace = pGlobalNamespace;
  this->m_globalBase = pGlobalNamespace->m_NextGlobalBase;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10062580
// Name: public: int CAI_LocalIdSpace::GlobalToLocal(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_LocalIdSpace::GlobalToLocal(CAI_LocalIdSpace *this, int globalID)
{
  if ( globalID == -1 )
    return -1;
  while ( this->m_localBase == 9999 || globalID < this->m_globalBase || globalID > this->m_globalTop )
  {
    this = this->m_pParentIDSpace;
    if ( this == nullptr )
      return -1;
  }
  return globalID + this->m_localBase - this->m_globalBase;
}

//------------------------------------------------------------------------------
// Address: 0x100625C0
// Name: public: int CAI_LocalIdSpace::LocalToGlobal(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_LocalIdSpace::LocalToGlobal(CAI_LocalIdSpace *this, int localID)
{
  int m_localBase; // eax

  if ( localID == -1 )
    return -1;
  while ( 1 )
  {
    m_localBase = this->m_localBase;
    if ( m_localBase != 9999 && localID >= m_localBase && localID <= this->m_localTop )
      break;
    this = this->m_pParentIDSpace;
    if ( this == nullptr )
      return -1;
  }
  return localID + this->m_globalBase - this->m_localBase;
}

//------------------------------------------------------------------------------
// Address: 0x10062600
// Name: public: CAI_GlobalNamespace::~CAI_GlobalNamespace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_GlobalNamespace::~CAI_GlobalNamespace(CAI_GlobalNamespace *this)
{
  CStringRegistry *m_pSymbols; // esi

  m_pSymbols = this->m_pSymbols;
  if ( this->m_pSymbols != nullptr )
  {
    CStringRegistry::~CStringRegistry(this: this->m_pSymbols);
    free(pMem: m_pSymbols);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062620
// Name: public: bool CAI_LocalIdSpace::AddSymbol(char const __near *,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_LocalIdSpace::AddSymbol(
        CAI_LocalIdSpace *this,
        const char *pszSymbol,
        int localId,
        const char *pszDebugSymbolType,
        const char *pszDebugOwner)
{
  CAI_GlobalNamespace *m_pGlobalNamespace; // edi
  CAI_LocalIdSpace *m_pParentIDSpace; // edx
  int v8; // edx
  int m_localBase; // edx
  int m_localTop; // esi
  int v11; // esi
  int v12; // esi

  m_pGlobalNamespace = this->m_pGlobalNamespace;
  if ( m_pGlobalNamespace != nullptr )
  {
    if ( this->m_localBase == 9999
      && (m_pParentIDSpace = this->m_pParentIDSpace, this->m_localBase = localId, m_pParentIDSpace != nullptr)
      && (v8 = m_pParentIDSpace->m_localBase) != 9999
      && localId <= v8 )
    {
      DevMsg(a1: "ERROR: Bad %s LOCALID for %s\n", pszDebugSymbolType, pszDebugOwner);
      return 0;
    }
    else
    {
      m_localBase = this->m_localBase;
      if ( localId >= m_localBase )
      {
        m_localTop = this->m_localTop;
        if ( m_localTop == -1 )
        {
          this->m_localTop = m_localBase;
          this->m_globalTop = this->m_globalBase;
        }
        else if ( localId > m_localTop )
        {
          v11 = this->m_globalBase - m_localBase;
          this->m_localTop = localId;
          this->m_globalTop = localId + v11;
        }
        v12 = CAI_LocalIdSpace::LocalToGlobal(this, localID: localId);
        if ( v12 != -1 )
        {
          CStringRegistry::AddString(this: m_pGlobalNamespace->m_pSymbols, stringText: pszSymbol, stringID: v12);
          if ( m_pGlobalNamespace->m_NextGlobalBase < v12 + 1 )
            m_pGlobalNamespace->m_NextGlobalBase = v12 + 1;
        }
        return 1;
      }
      else
      {
        DevMsg(a1: "ERROR: %s First added %s must be first LOCALID!\n", pszDebugSymbolType, pszDebugOwner);
        return 0;
      }
    }
  }
  else
  {
    DevMsg(a1: "ERROR: Adding symbol to uninitialized table %s\n", pszDebugOwner);
    return 0;
  }
}
