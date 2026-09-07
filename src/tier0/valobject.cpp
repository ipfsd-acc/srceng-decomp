// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/valobject.cpp
// Functions: 2
// ============================================================

#include "tier0\valobject.h"

//------------------------------------------------------------------------------
// Address: 0x3F00A930
// Name: public: void CValObject::ClaimMemoryBlock(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CValObject::ClaimMemoryBlock(CValObject *this@<eax>, char a2@<ch>, _BYTE *a3@<ebx>)
{
  *a3 ^= a2;
  JUMPOUT(0x3F00A933);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A970
// Name: public: void CValObject::ClaimChildMemoryBlock(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CValObject::ClaimChildMemoryBlock(
        CValObject *this@<ecx>,
        int a2@<eax>,
        int a3@<edx>,
        int a4@<ebx>,
        int a5@<esi>,
        int cubUser)
{
  do
  {
    this->m_pchType = *(const char **)((char *)&this->m_pchType + a2);
    this = (CValObject *)((char *)this + 4);
    --a3;
  }
  while ( a3 != 0 );
  *(_DWORD *)(a5 + 2352) = *(_DWORD *)(a4 + 2352);
  JUMPOUT(0x3F00A994);
}
