// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxstringbuiltins.cpp
// Functions: 3
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxstringbuiltins.h"

//------------------------------------------------------------------------------
// Address: 0x1010A8B0
// Name: public: GASStringBuiltinManager::~GASStringBuiltinManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringBuiltinManager::~GASStringBuiltinManager(vc_attributes::PreBoundAttribute *this)
{
  unsigned int i; // esi
  int v3; // ecx
  IShaderAPI *v5; // ecx

  for ( i = 0; i < 0x9D; ++i )
  {
    v3 = *(&this->Deref + i);
    if ( (*(_DWORD *)(v3 + 8))-- == 1 )
      GASStringNode::ReleaseNode(a1: v3);
    *(&this->Deref + i) = 0;
  }
  v5 = *((IShaderAPI **)this + 157);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1010A8F0
// Name: private: void GASStringBuiltinManager::InitBuiltins(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringBuiltinManager::InitBuiltins(vc_attributes::PreBoundAttribute *this)
{
  unsigned int i; // edi
  int *ConstStringNode; // esi
  int v5; // [esp+Ch] [ebp-4h]

  v5 = (char *)this - (char *)&GFx_pASBuiltinTable;
  for ( i = 0; i < 0x274; i += 4 )
  {
    ConstStringNode = (int *)GASStringManager::CreateConstStringNode(
                               this: *((GASStringManager **)this + 157),
                               result: *(CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > **)((char *)&GFx_pASBuiltinTable + i),
                               a3: strlen(*(const char **)((char *)&GFx_pASBuiltinTable + i)),
                               a4: 0x80000000);
    ++ConstStringNode[2];
    *(_DWORD *)((char *)&GFx_pASBuiltinTable + v5 + i) = ConstStringNode;
    ++ConstStringNode[2];
    GASStringNode::ResolveLowercase_Impl(a1: ConstStringNode);
    if ( ConstStringNode[2]-- == 1 )
      GASStringNode::ReleaseNode(a1: (int)ConstStringNode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A970
// Name: public: GASStringBuiltinManager::GASStringBuiltinManager(class GASStringManager __near *)
// Source: json
//------------------------------------------------------------------------------
GASStringBuiltinManager *__thiscall GASStringBuiltinManager::GASStringBuiltinManager(
        GASStringBuiltinManager *this,
        IShaderDevice *a2)
{
  if ( a2 != nullptr )
    GRefCountImpl::AddRef(this: a2);
  *((_DWORD *)this + 157) = a2;
  GASStringBuiltinManager::InitBuiltins((vc_attributes::PreBoundAttribute *)this);
  return this;
}
