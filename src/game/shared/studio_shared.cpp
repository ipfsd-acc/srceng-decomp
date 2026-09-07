// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/studio_shared.cpp
// Functions: 5
// ============================================================

#include "game\shared\studio_shared.h"

//------------------------------------------------------------------------------
// Address: 0x101787D0
// Name: public: struct virtualmodel_t __near * studiohdr_t::GetVirtualModel(void)const
// Source: json
//------------------------------------------------------------------------------
virtualmodel_t *__thiscall studiohdr_t::GetVirtualModel(studiohdr_t *this)
{
  if ( this->numincludemodels != 0 )
    return modelinfo->GetVirtualModel(this: modelinfo, a2: this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101787F0
// Name: public: struct studiohdr_t const __near * virtualgroup_t::GetStudioHdr(void)const
// Source: json
//------------------------------------------------------------------------------
const studiohdr_t *__thiscall virtualgroup_t::GetStudioHdr(virtualgroup_t *this)
{
  return modelinfo->FindModel(this: modelinfo, a2: this->cache);
}

//------------------------------------------------------------------------------
// Address: 0x10178810
// Name: public: unsigned char __near * studiohdr_t::GetAnimBlock(int,bool)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall studiohdr_t::GetAnimBlock(studiohdr_t *this, int iBlock, BOOL preloadIfMissing)
{
  return modelinfo->GetAnimBlock(this: modelinfo, a2: this, a3: iBlock, a4: preloadIfMissing);
}

//------------------------------------------------------------------------------
// Address: 0x10178840
// Name: public: bool studiohdr_t::hasAnimBlockBeenPreloaded(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall studiohdr_t::hasAnimBlockBeenPreloaded(studiohdr_t *this, int i)
{
  return modelinfo->HasAnimBlockBeenPreloaded(this: modelinfo, a2: this, a3: i);
}

//------------------------------------------------------------------------------
// Address: 0x10178860
// Name: public: int studiohdr_t::GetAutoplayList(unsigned short __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall studiohdr_t::GetAutoplayList(studiohdr_t *this, unsigned __int16 **pOut)
{
  return modelinfo->GetAutoplayList(this: modelinfo, a2: this, a3: pOut);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1022B150
// Name: public: struct virtualmodel_t __near * studiohdr_t::GetVirtualModel(void)const
// Source: json
//------------------------------------------------------------------------------
virtualmodel_t *__thiscall studiohdr_t::GetVirtualModel(studiohdr_t *this)
{
  if ( this->numincludemodels != 0 )
    return modelinfo->GetVirtualModel(this: modelinfo, a2: this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1022B170
// Name: public: struct studiohdr_t const __near * virtualgroup_t::GetStudioHdr(void)const
// Source: json
//------------------------------------------------------------------------------
const studiohdr_t *__thiscall virtualgroup_t::GetStudioHdr(virtualgroup_t *this)
{
  return modelinfo->FindModel(this: modelinfo, a2: this->cache);
}

//------------------------------------------------------------------------------
// Address: 0x1022B190
// Name: public: unsigned char __near * studiohdr_t::GetAnimBlock(int,bool)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall studiohdr_t::GetAnimBlock(studiohdr_t *this, int iBlock, BOOL preloadIfMissing)
{
  return modelinfo->GetAnimBlock(this: modelinfo, a2: this, a3: iBlock, a4: preloadIfMissing);
}

//------------------------------------------------------------------------------
// Address: 0x1022B1C0
// Name: public: bool studiohdr_t::hasAnimBlockBeenPreloaded(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall studiohdr_t::hasAnimBlockBeenPreloaded(studiohdr_t *this, int i)
{
  return modelinfo->HasAnimBlockBeenPreloaded(this: modelinfo, a2: this, a3: i);
}

//------------------------------------------------------------------------------
// Address: 0x1022B1E0
// Name: public: int studiohdr_t::GetAutoplayList(unsigned short __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall studiohdr_t::GetAutoplayList(studiohdr_t *this, unsigned __int16 **pOut)
{
  return modelinfo->GetAutoplayList(this: modelinfo, a2: this, a3: pOut);
}

} // namespace server
