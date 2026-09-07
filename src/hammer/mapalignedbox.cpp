// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapalignedbox.cpp
// Functions: 15
// ============================================================

#include "hammer\mapalignedbox.h"

//------------------------------------------------------------------------------
// Address: 0x1010C040
// Name: public: virtual char const __near * CMapAlignedBox::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapAlignedBox::GetType(CMapAlignedBox *this)
{
  return CMapAlignedBox::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1010C050
// Name: public: virtual int CMapAlignedBox::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapAlignedBox::IsMapClass(CMapAlignedBox *this, const char *Type)
{
  return Type == CMapAlignedBox::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1010C070
// Name: public: virtual CMapHelper::~CMapHelper(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapHelper::~CMapHelper(CMapHelper *this)
{
  CMapClass::~CMapClass(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010C0B0
// Name: public: CMapAlignedBox::CMapAlignedBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
CMapAlignedBox *__thiscall CMapAlignedBox::CMapAlignedBox(CMapAlignedBox *this, Vector *Mins, Vector *Maxs)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapAlignedBox_vtbl *)&CMapHelper::`vftable';
  *(_WORD *)&this->m_bWireframe = 0;
  this->__vftable = (CMapAlignedBox_vtbl *)&CMapAlignedBox::`vftable';
  this->m_Mins = *Mins;
  this->m_Maxs = *Maxs;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010C150
// Name: public: virtual bool CMapAlignedBox::IsVisualElement(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapAlignedBox::IsVisualElement(CMapAlignedBox *this)
{
  return !this->m_bWireframe;
}

//------------------------------------------------------------------------------
// Address: 0x1010C160
// Name: public: virtual char const __near * CMapAlignedBox::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapAlignedBox::GetDescription(CMapAlignedBox *this)
{
  return "Aligned box";
}

//------------------------------------------------------------------------------
// Address: 0x1010C170
// Name: public: CMapAlignedBox::CMapAlignedBox(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMapAlignedBox *__thiscall CMapAlignedBox::CMapAlignedBox(CMapAlignedBox *this, char *pMinsKeyName, char *pMaxsKeyName)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapAlignedBox_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapAlignedBox_vtbl *)&CMapAlignedBox::`vftable';
  *(_WORD *)&this->m_bWireframe = 256;
  strncpy(dest: (unsigned __int8 *)this->m_MinsKeyName, source: (unsigned __int8 *)pMinsKeyName, count: 0x1Fu);
  strncpy(dest: (unsigned __int8 *)this->m_MaxsKeyName, source: (unsigned __int8 *)pMaxsKeyName, count: 0x1Fu);
  this->m_MinsKeyName[31] = 0;
  this->m_MaxsKeyName[31] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010C210
// Name: public: virtual class CMapClass __near * CMapAlignedBox::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapAlignedBox *__thiscall CMapAlignedBox::CopyFrom(CMapAlignedBox *this, CMapClass *pObject, bool bUpdateDependencies)
{
  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pObject, bUpdateDependencies);
  *(_WORD *)&this->m_bWireframe = pObject[1].__vftable;
  strncpy(
    dest: (unsigned __int8 *)this->m_MinsKeyName,
    source: (unsigned __int8 *)&pObject[1].__vftable + 2,
    count: 0x1Fu);
  strncpy(
    dest: (unsigned __int8 *)this->m_MaxsKeyName,
    source: (unsigned __int8 *)&pObject[1].m_References.m_pHead + 2,
    count: 0x1Fu);
  this->m_MinsKeyName[31] = 0;
  this->m_MaxsKeyName[31] = 0;
  this->m_Mins.x = *(float *)&pObject[1].m_BoundingBox.__vftable;
  *(Vector *)&this->m_Mins.y = pObject[1].m_BoundingBox.bmins;
  this->m_Maxs.y = pObject[1].m_BoundingBox.bmaxs.x;
  this->m_Maxs.z = pObject[1].m_BoundingBox.bmaxs.y;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010C2D0
// Name: public: virtual void CMapAlignedBox::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAlignedBox::Render2D(CMapAlignedBox *this, CRender2D *pRender)
{
  unsigned __int8 b; // cl
  unsigned __int8 g; // dl
  unsigned __int8 clrSelection; // al
  Vector vCenter; // [esp+8h] [ebp-34h] BYREF
  Vector vecMins; // [esp+14h] [ebp-28h] BYREF
  Vector vecMaxs; // [esp+20h] [ebp-1Ch] BYREF
  Vector2D pt2; // [esp+2Ch] [ebp-10h] BYREF
  Vector2D pt; // [esp+34h] [ebp-8h] BYREF

  CMapClass::GetRender2DBox(this, mins: &vecMins, maxs: &vecMaxs);
  if ( this->IsSelected(this) )
  {
    CRender::SetDrawColor(
      this: pRender,
      r: Options.colors.clrSelection,
      g: BYTE1(Options.colors.clrSelection),
      b: BYTE2(Options.colors.clrSelection));
    b = BYTE2(Options.colors.clrSelection);
    g = BYTE1(Options.colors.clrSelection);
    clrSelection = Options.colors.clrSelection;
  }
  else
  {
    CRender::SetDrawColor(this: pRender, r: this->r, g: this->g, b: this->b);
    b = this->b;
    g = this->g;
    clrSelection = this->r;
  }
  CRender::SetHandleColor(this: pRender, r: clrSelection, g, b);
  pRender->DrawBox(this: pRender, a2: &vecMins, a3: &vecMaxs, a4: false);
  if ( CRender::IsActiveView(this: pRender) )
  {
    CRender::TransformPoint(this: pRender, vClient: &pt, vWorld: &vecMins);
    CRender::TransformPoint(this: pRender, vClient: &pt2, vWorld: &vecMaxs);
    if ( (int)(float)(fabs(pt.x - pt2.x) + 1.0) > 6 && (int)(float)(fabs(pt.y - pt2.y) + 1.0) > 6 )
    {
      CRender::SetHandleStyle(this: pRender, size: 4, type: 4);
      vCenter.x = (float)(vecMaxs.x + vecMins.x) * 0.5;
      vCenter.y = (float)(vecMins.y + vecMaxs.y) * 0.5;
      vCenter.z = (float)(vecMaxs.z + vecMins.z) * 0.5;
      CRender::DrawHandle(this: pRender, &vCenter, vOffset: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C440
// Name: public: virtual void CMapAlignedBox::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAlignedBox::Render3D(CMapAlignedBox *this, CRender3D *pRender)
{
  SelectionState_t v3; // eax

  if ( this->m_bWireframe )
  {
    if ( this->GetSelectionState(this) != SELECT_NONE )
      pRender->RenderWireframeBox(
        this: pRender,
        a2: &this->m_CullBox.bmins,
        a3: &this->m_CullBox.bmaxs,
        a4: 255u,
        a5: 255u,
        a6: 0);
  }
  else
  {
    CRender3D::BeginRenderHitTarget(this: pRender, pObject: (CMapInstance *)this, uHandle: 0);
    v3 = this->GetSelectionState(this);
    CRender3D::RenderBox(
      this: pRender,
      Mins: &this->m_CullBox.bmins,
      Maxs: &this->m_CullBox.bmaxs,
      chRed: this->r,
      chGreen: this->g,
      chBlue: this->b,
      eBoxSelectionState: v3);
    CRender3D::EndRenderHitTarget(this: pRender, a2: (int)pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C4C0
// Name: public: virtual void CMapAlignedBox::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAlignedBox::OnParentKeyChanged(CMapAlignedBox *this, const char *key, const char *value)
{
  if ( this->m_bUseKeyName )
  {
    if ( _V_stricmp(s1: key, s2: this->m_MinsKeyName) != 0 )
    {
      if ( _V_stricmp(s1: key, s2: this->m_MaxsKeyName) == 0 )
        sscanf(string: value, format: "%f %f %f", &this->m_Maxs, &this->m_Maxs.y, &this->m_Maxs.z);
    }
    else
    {
      sscanf(string: value, format: "%f %f %f", &this->m_Mins, &this->m_Mins.y, &this->m_Mins.z);
    }
    this->PostUpdate(this, a2: Notify_Changed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C5C0
// Name: public: virtual void CMapAlignedBox::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAlignedBox::CalcBounds(CMapAlignedBox *this, int bFullUpdate)
{
  float x; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  Vector AbsMins; // [esp+4h] [ebp-18h] BYREF
  Vector AbsMaxs; // [esp+10h] [ebp-Ch] BYREF

  x = this->m_Origin.x;
  v4 = this->m_Mins.y + this->m_Origin.y;
  v5 = this->m_Mins.z + this->m_Origin.z;
  v6 = this->m_Mins.x + x;
  AbsMaxs.x = x + this->m_Maxs.x;
  AbsMaxs.y = this->m_Maxs.y + this->m_Origin.y;
  v7 = this->m_Maxs.z + this->m_Origin.z;
  AbsMins.x = v6;
  AbsMins.y = v4;
  AbsMins.z = v5;
  AbsMaxs.z = v7;
  BoundBox::ResetBounds(this: &this->m_Render2DBox);
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, mins: &AbsMins, maxs: &AbsMaxs);
  this->m_CullBox.bmins = this->m_Render2DBox.bmins;
  this->m_CullBox.bmaxs = this->m_Render2DBox.bmaxs;
  this->m_BoundingBox.bmins = this->m_Render2DBox.bmins;
  this->m_BoundingBox.bmaxs = this->m_Render2DBox.bmaxs;
}

//------------------------------------------------------------------------------
// Address: 0x1010C6A0
// Name: public: virtual class CMapClass __near * CMapAlignedBox::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapAlignedBox::Copy(CMapAlignedBox *this, BOOL bUpdateDependencies)
{
  CMapClass *v3; // eax
  CMapClass *v4; // esi

  v3 = (CMapClass *)operator new(nSize: 0x134u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    CMapClass::CMapClass(this: v3);
    v4->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
    v4->__vftable = (CMapClass_vtbl *)&CMapAlignedBox::`vftable';
    LOWORD(v4[1].__vftable) = 0;
    v4[1].m_BoundingBox.__vftable = nullptr;
    v4[1].m_BoundingBox.bmins.x = 0.0;
    v4[1].m_BoundingBox.bmins.y = 0.0;
    v4[1].m_BoundingBox.bmins.z = 0.0;
    v4[1].m_BoundingBox.bmaxs.x = 0.0;
    v4[1].m_BoundingBox.bmaxs.y = 0.0;
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
// Address: 0x1010C770
// Name: class CMapClass __near * CMapAlignedBox_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CMapAlignedBox_CreateObject()
{
  CMapClass *v0; // eax
  CMapClass *v1; // esi

  v0 = (CMapClass *)operator new(nSize: 0x134u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CMapClass::CMapClass(this: v0);
  v1->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
  v1->__vftable = (CMapClass_vtbl *)&CMapAlignedBox::`vftable';
  LOWORD(v1[1].__vftable) = 0;
  v1[1].m_BoundingBox.__vftable = nullptr;
  v1[1].m_BoundingBox.bmins.x = 0.0;
  v1[1].m_BoundingBox.bmins.y = 0.0;
  v1[1].m_BoundingBox.bmins.z = 0.0;
  v1[1].m_BoundingBox.bmaxs.x = 0.0;
  v1[1].m_BoundingBox.bmaxs.y = 0.0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1010C830
// Name: public: static class CMapClass __near * CMapAlignedBox::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapAlignedBox *__cdecl CMapAlignedBox::Create(CHelperInfo *pHelperInfo)
{
  int v1; // ecx
  char **m_pMemory; // eax
  char *v3; // edi
  char *v4; // esi
  CMapAlignedBox *v5; // eax
  CMapAlignedBox *result; // eax
  int m_Size; // ebx
  int i; // esi
  const char *v9; // eax
  CMapAlignedBox *v10; // eax
  Vector Mins; // [esp+8h] [ebp-28h] BYREF
  Vector Maxs; // [esp+14h] [ebp-1Ch] BYREF
  CMapAlignedBox *v13; // [esp+20h] [ebp-10h]
  int v14; // [esp+2Ch] [ebp-4h]

  if ( _V_stricmp(s1: pHelperInfo->m_szName, s2: "wirebox") != 0 )
  {
    m_Size = pHelperInfo->m_Parameters.m_Size;
    for ( i = 0; i < m_Size; ++i )
    {
      if ( i < pHelperInfo->m_Parameters.m_Size )
        v9 = pHelperInfo->m_Parameters.m_Memory.m_pMemory[i];
      else
        v9 = nullptr;
      if ( i >= 3 )
      {
        if ( i >= 6 )
          break;
        *(&Maxs.x + i % 3) = atof(nptr: v9);
      }
      else
      {
        *(&Mins.x + i) = atof(nptr: v9);
      }
    }
    result = nullptr;
    if ( i >= 6 )
    {
      v10 = (CMapAlignedBox *)operator new(nSize: 0x134u);
      v13 = v10;
      v14 = 1;
      if ( v10 != nullptr )
        return CMapAlignedBox::CMapAlignedBox(this: v10, &Mins, &Maxs);
      else
        return nullptr;
    }
  }
  else
  {
    v1 = pHelperInfo->m_Parameters.m_Size;
    if ( v1 > 0
      && (m_pMemory = pHelperInfo->m_Parameters.m_Memory.m_pMemory, v3 = *m_pMemory, *m_pMemory != nullptr)
      && v1 > 1
      && (v4 = m_pMemory[1]) != nullptr )
    {
      v5 = (CMapAlignedBox *)operator new(nSize: 0x134u);
      v13 = v5;
      v14 = 0;
      if ( v5 != nullptr )
      {
        result = CMapAlignedBox::CMapAlignedBox(this: v5, pMinsKeyName: v3, pMaxsKeyName: v4);
        v14 = -1;
        result->m_bWireframe = true;
      }
      else
      {
        v14 = -1;
        MEMORY[0xD8] = 1;
        return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}
