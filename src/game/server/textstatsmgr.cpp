// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/textstatsmgr.cpp
// Functions: 2
// ============================================================

#include "game\server\textstatsmgr.h"

//------------------------------------------------------------------------------
// Address: 0x10234050
// Name: public: void CTextStatsMgr::SetStatsFilename(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextStatsMgr::SetStatsFilename(CTextStatsMgr *this, char *sFilename)
{
  V_strncpy(pDest: this->m_szStatFilename, pSrc: sFilename, maxLen: 260);
}

//------------------------------------------------------------------------------
// Address: 0x10234070
// Name: public: bool CTextStatsMgr::WriteFile(class IFileSystem __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTextStatsMgr::WriteFile(CTextStatsMgr *this, IFileSystem *pFileSys, CTextStatsMgr *pFilename)
{
  CTextStatsMgr *v3; // eax
  void *v4; // ebx
  int i; // esi
  CTextStatFile *j; // esi

  v3 = pFilename;
  if ( pFilename == nullptr )
    v3 = this;
  v4 = pFileSys->Open(this: &pFileSys->IBaseFileSystem, a2: v3, a3: "wt", a4: "LOGDIR");
  if ( v4 == nullptr )
    return 0;
  if ( (_S2_226 & 1) == 0 )
  {
    _S2_226 |= 1u;
    dword_10657DA8 = (int)&dword_10657DA4;
    dword_10657DA4 = (int)&dword_10657DA4;
    atexit(func: CTextStat::GetTextStatsList_::_2_::_dynamic_atexit_destructor_for__theList__);
  }
  for ( i = dword_10657DA8; (int *)i != &dword_10657DA4; i = *(_DWORD *)(i + 4) )
  {
    if ( *(CTextStatsMgr **)(i + 8) == this )
      (*(void (__cdecl **)(IFileSystem *, void *, _DWORD))(i + 12))(a1: pFileSys, a2: v4, a3: *(_DWORD *)(i + 16));
  }
  pFileSys->Close(this: &pFileSys->IBaseFileSystem, a2: v4);
  for ( j = CTextStatFile::s_pHead; j != nullptr; j = j->m_pNext )
    j->m_pFn();
  return 1;
}
