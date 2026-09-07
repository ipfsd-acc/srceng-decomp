// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/maplineoccluder.cpp
// Functions: 11
// ============================================================

#include "hammer\maplineoccluder.h"

//------------------------------------------------------------------------------
// Address: 0x10133380
// Name: public: virtual char const __near * CMapLineOccluder::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapLineOccluder::GetType(CMapLineOccluder *this)
{
  return CMapLineOccluder::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10133390
// Name: public: virtual int CMapLineOccluder::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapLineOccluder::IsMapClass(CMapLineOccluder *this, const char *Type)
{
  return Type == CMapLineOccluder::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x101333B0
// Name: public: virtual char const __near * CMapLineOccluder::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapLineOccluder::GetDescription(CMapLineOccluder *this)
{
  return "FoW Line Occluder helper";
}

//------------------------------------------------------------------------------
// Address: 0x101333C0
// Name: public: virtual void CMapLineOccluder::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLineOccluder::CalcBounds(CMapLineOccluder *this, int bFullUpdate)
{
  CMapClass::CalcBounds(this, bFullUpdate);
  BoundBox::ResetBounds(this: &this->m_Render2DBox);
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, mins: &this->m_vStart, maxs: &this->m_vEnd);
  BoundBox::ResetBounds(this: &this->m_CullBox);
  BoundBox::UpdateBounds(this: &this->m_CullBox, mins: &this->m_vStart, maxs: &this->m_vEnd);
  BoundBox::ResetBounds(this: &this->m_BoundingBox);
}

//------------------------------------------------------------------------------
// Address: 0x10133420
// Name: public: virtual class CMapClass __near * CMapLineOccluder::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapLineOccluder *__thiscall CMapLineOccluder::CopyFrom(
        CMapLineOccluder *this,
        CMapClass *pObject,
        bool bUpdateDependencies)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10133440
// Name: public: virtual void CMapLineOccluder::SetOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLineOccluder::SetOrigin(CMapLineOccluder *this, Vector *vecOrigin)
{
  CMapClass::SetOrigin(this, origin: vecOrigin);
}

//------------------------------------------------------------------------------
// Address: 0x10133450
// Name: protected: virtual void CMapLineOccluder::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLineOccluder::DoTransform(CMapLineOccluder *this, const VMatrix *matrix)
{
  CMapClass::DoTransform(this, matrix);
}

//------------------------------------------------------------------------------
// Address: 0x101334C0
// Name: public: virtual class CMapClass __near * CMapLineOccluder::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapLineOccluder::Copy(CMapLineOccluder *this, BOOL bUpdateDependencies)
{
  CMapClass *v3; // eax
  CMapClass *v4; // esi

  v3 = (CMapClass *)operator new(nSize: 0xF4u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    CMapClass::CMapClass(this: v3);
    v4->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
    v4->__vftable = (CMapClass_vtbl *)&CMapLineOccluder::`vftable';
    *(_WORD *)&v4->r = 255;
    v4->b = 0;
    CMapClass::SetVisible(this: v4, bVisible: true);
    *((_BYTE *)v4 + 180) |= 1u;
    v4[1].__vftable = nullptr;
  }
  else
  {
    v4 = nullptr;
  }
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10133570
// Name: class CMapClass __near * CMapLineOccluder_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CMapLineOccluder_CreateObject()
{
  CMapClass *v0; // eax
  CMapClass *v1; // esi

  v0 = (CMapClass *)operator new(nSize: 0xF4u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CMapClass::CMapClass(this: v0);
  v1->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
  v1->__vftable = (CMapClass_vtbl *)&CMapLineOccluder::`vftable';
  *(_WORD *)&v1->r = 255;
  v1->b = 0;
  CMapClass::SetVisible(this: v1, bVisible: true);
  *((_BYTE *)v1 + 180) |= 1u;
  v1[1].__vftable = nullptr;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10133620
// Name: public: static class CMapClass __near * CMapLineOccluder::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CMapLineOccluder::Create(CHelperInfo *pHelperInfo)
{
  CMapClass *v1; // eax
  CMapClass *v2; // esi
  char **m_pMemory; // ecx
  char **v4; // edx
  CMapClass *chRed; // [esp+8h] [ebp-18h]
  char chGreen; // [esp+Ch] [ebp-14h]
  char chBlue; // [esp+10h] [ebp-10h]

  v1 = (CMapClass *)operator new(nSize: 0xF4u);
  v2 = v1;
  chRed = v1;
  if ( v1 != nullptr )
  {
    CMapClass::CMapClass(this: v1);
    v2->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
    v2->__vftable = (CMapClass_vtbl *)&CMapLineOccluder::`vftable';
    *(_WORD *)&v2->r = 255;
    v2->b = 0;
    CMapClass::SetVisible(this: v2, bVisible: true);
    *((_BYTE *)v2 + 180) |= 1u;
    v2[1].__vftable = nullptr;
  }
  else
  {
    v2 = nullptr;
  }
  if ( v2 != nullptr )
  {
    LOBYTE(chRed) = -1;
    chGreen = -1;
    chBlue = -1;
    if ( pHelperInfo->m_Parameters.m_Size > 1 && *((_DWORD *)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 1) != 0 )
      LOBYTE(chRed) = atoi(nptr: *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 1));
    if ( pHelperInfo->m_Parameters.m_Size > 2 )
    {
      m_pMemory = pHelperInfo->m_Parameters.m_Memory.m_pMemory;
      if ( m_pMemory[2] != nullptr )
        chGreen = atoi(nptr: m_pMemory[2]);
    }
    if ( pHelperInfo->m_Parameters.m_Size > 3 )
    {
      v4 = pHelperInfo->m_Parameters.m_Memory.m_pMemory;
      if ( v4[3] != nullptr )
        chBlue = atoi(nptr: v4[3]);
    }
    v2->SetRenderColor_2(this: v2, a2: (unsigned __int8)chRed, a3: chGreen, a4: chBlue);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10133CC0
// Name: public: virtual enum SelectionState_t CMapLineOccluder::SetSelectionState(enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
SelectionState_t __thiscall CMapLineOccluder::SetSelectionState(
        CMapLineOccluder *this,
        SelectionState_t eSelectionState)
{
  return CMapClass::SetSelectionState(this, eSelectionState);
}
