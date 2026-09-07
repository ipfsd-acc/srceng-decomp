// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapcylinder.cpp
// Functions: 19
// ============================================================

#include "hammer\mapcylinder.h"

//------------------------------------------------------------------------------
// Address: 0x10110820
// Name: public: virtual char const __near * CMapCylinder::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapCylinder::GetType(CMapCylinder *this)
{
  return CMapCylinder::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10110830
// Name: public: virtual int CMapCylinder::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapCylinder::IsMapClass(CMapCylinder *this, const char *Type)
{
  return Type == CMapCylinder::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10110850
// Name: public: virtual char const __near * CMapCylinder::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapCylinder::GetDescription(CMapCylinder *this)
{
  return "Cylinder helper";
}

//------------------------------------------------------------------------------
// Address: 0x10110860
// Name: protected: void CMapCylinder::BuildCylinder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCylinder::BuildCylinder(CMapCylinder *this)
{
  void (__thiscall *SetOrigin)(CMapPoint *, Vector *); // edx
  float v3[3]; // [esp+4h] [ebp-24h] BYREF
  Vector Start; // [esp+10h] [ebp-18h] BYREF
  Vector End; // [esp+1Ch] [ebp-Ch] BYREF

  if ( this->m_pStartEntity != nullptr && this->m_pEndEntity != nullptr )
  {
    this->m_pStartEntity->GetOrigin(this: this->m_pStartEntity, a2: &Start);
    this->m_pEndEntity->GetOrigin(this: this->m_pEndEntity, a2: &End);
    SetOrigin = this->SetOrigin;
    v3[0] = (float)(End.x + Start.x) * 0.5;
    v3[1] = (float)(Start.y + End.y) * 0.5;
    v3[2] = (float)(End.z + Start.z) * 0.5;
    SetOrigin(this, a2: (Vector *)v3);
  }
  this->CalcBounds(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10110900
// Name: public: virtual class CMapClass __near * CMapCylinder::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapCylinder *__thiscall CMapCylinder::CopyFrom(CMapCylinder *this, CVisGroup *pObject, bool bUpdateDependencies)
{
  char *v4; // edi
  CMapEntity *updated; // eax
  CMapEntity *m_pEndEntity; // edx
  char *v7; // eax
  char v8; // cl
  char *v9; // eax
  char v10; // cl
  char *v11; // eax
  char v12; // cl
  char *v13; // eax
  char v14; // cl
  char *v15; // eax
  char v16; // cl
  char *v17; // eax
  char v18; // cl

  v4 = (char *)__RTDynamicCast(
                 inptr: pObject,
                 VfDelta: 0,
                 SrcType: &CMapClass `RTTI Type Descriptor',
                 TargetType: &CMapCylinder `RTTI Type Descriptor',
                 isReference: 0);
  if ( v4 != nullptr )
  {
    CMapClass::CopyFrom(this, pFrom: pObject, bUpdateDependencies);
    if ( bUpdateDependencies )
    {
      updated = (CMapEntity *)CMapClass::UpdateDependency(
                                this,
                                pOldAttached: this->m_pStartEntity,
                                pNewAttached: *((CMapClass **)v4 + 174));
      m_pEndEntity = this->m_pEndEntity;
      this->m_pStartEntity = updated;
      this->m_pEndEntity = (CMapEntity *)CMapClass::UpdateDependency(
                                           this,
                                           pOldAttached: m_pEndEntity,
                                           pNewAttached: *((CMapClass **)v4 + 175));
    }
    else
    {
      this->m_pStartEntity = *((CMapEntity **)v4 + 174);
      this->m_pEndEntity = *((CMapEntity **)v4 + 175);
    }
    v7 = v4 + 216;
    this->m_flStartRadius = *((float *)v4 + 176);
    this->m_flEndRadius = *((float *)v4 + 177);
    do
    {
      v8 = *v7;
      v7[(char *)this - v4] = *v7;
      ++v7;
    }
    while ( v8 != 0 );
    v9 = v4 + 296;
    do
    {
      v10 = *v9;
      v9[(char *)this - v4] = *v9;
      ++v9;
    }
    while ( v10 != 0 );
    v11 = v4 + 376;
    do
    {
      v12 = *v11;
      v11[(char *)this - v4] = *v11;
      ++v11;
    }
    while ( v12 != 0 );
    v13 = v4 + 456;
    do
    {
      v14 = *v13;
      v13[(char *)this - v4] = *v13;
      ++v13;
    }
    while ( v14 != 0 );
    v15 = v4 + 536;
    do
    {
      v16 = *v15;
      v15[(char *)this - v4] = *v15;
      ++v15;
    }
    while ( v16 != 0 );
    v17 = v4 + 616;
    do
    {
      v18 = *v17;
      v17[(char *)this - v4] = *v17;
      ++v17;
    }
    while ( v18 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10110A80
// Name: public: virtual void CMapCylinder::OnRemoveFromWorld(class CMapWorld __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCylinder::OnRemoveFromWorld(CMapCylinder *this, CMapWorld *pWorld, bool bNotifyChildren)
{
  CMapClass::OnRemoveFromWorld(this, pWorld, bNotifyChildren);
  this->m_pStartEntity = (CMapEntity *)CMapClass::UpdateDependency(
                                         this,
                                         pOldAttached: this->m_pStartEntity,
                                         pNewAttached: nullptr);
  this->m_pEndEntity = (CMapEntity *)CMapClass::UpdateDependency(
                                       this,
                                       pOldAttached: this->m_pEndEntity,
                                       pNewAttached: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10110AD0
// Name: public: virtual void CMapCylinder::OnNotifyDependent(class CMapClass __near *,enum Notify_Dependent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCylinder::OnNotifyDependent(CMapCylinder *this, CMapClass *pObject, KeyValues *eNotifyType)
{
  CMapWorld *WorldObject; // eax

  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: (int)pObject, msg: eNotifyType);
  WorldObject = CMapClass::GetWorldObject(pStart: this);
  this->UpdateDependencies(this, a2: WorldObject, a3: pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10110B10
// Name: public: virtual void CMapCylinder::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCylinder::OnParentKeyChanged(CMapCylinder *this, const char *key, const char *value)
{
  CMapWorld *WorldObject; // edi
  CMapClass *v5; // eax
  CMapClass *v6; // eax
  const char *v7; // eax
  double v8; // xmm0_8
  const char *v9; // eax
  double v10; // xmm0_8

  WorldObject = CMapClass::GetWorldObject(pStart: this);
  if ( WorldObject == nullptr )
    return;
  if ( _V_stricmp(s1: key, s2: this->m_szStartValueKey) != 0 )
  {
    if ( _V_stricmp(s1: key, s2: this->m_szEndValueKey) != 0 )
      goto LABEL_7;
    v6 = WorldObject->FindChildByKeyValue(this: WorldObject, a2: this->m_szEndKey, a3: value, a4: nullptr, a5: nullptr);
    this->m_pEndEntity = (CMapEntity *)CMapClass::UpdateDependency(
                                         this,
                                         pOldAttached: this->m_pEndEntity,
                                         pNewAttached: v6);
  }
  else
  {
    v5 = WorldObject->FindChildByKeyValue(
           this: WorldObject,
           a2: this->m_szStartKey,
           a3: value,
           a4: nullptr,
           a5: nullptr);
    this->m_pStartEntity = (CMapEntity *)CMapClass::UpdateDependency(
                                           this,
                                           pOldAttached: this->m_pStartEntity,
                                           pNewAttached: v5);
  }
  CMapCylinder::BuildCylinder(this);
LABEL_7:
  if ( this->m_pStartEntity != nullptr && _V_stricmp(s1: key, s2: this->m_szStartRadiusKey) == 0 )
  {
    v7 = WCKeyValuesT<WCKVBase_Dict>::GetValue(
           this: &this->m_pStartEntity->m_KeyValues,
           pszKey: this->m_szStartRadiusKey,
           piIndex: nullptr);
    if ( v7 != nullptr )
      v8 = atof(nptr: v7);
    else
      v8 = 0.0;
    this->m_flStartRadius = v8;
    CMapCylinder::BuildCylinder(this);
  }
  if ( this->m_pEndEntity != nullptr && _V_stricmp(s1: key, s2: this->m_szEndRadiusKey) == 0 )
  {
    v9 = WCKeyValuesT<WCKVBase_Dict>::GetValue(
           this: &this->m_pEndEntity->m_KeyValues,
           pszKey: this->m_szEndRadiusKey,
           piIndex: nullptr);
    if ( v9 != nullptr )
      v10 = atof(nptr: v9);
    else
      v10 = 0.0;
    this->m_flEndRadius = v10;
    CMapCylinder::BuildCylinder(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110C90
// Name: protected: void CMapCylinder::ComputeCylinderPoints(int,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapCylinder::ComputeCylinderPoints(
        CMapCylinder *this@<ecx>,
        double a2@<esi:edi>,
        int nCount,
        Vector *pStartVerts,
        Vector *pEndVerts)
{
  Vector *v6; // edi
  float *p_z; // esi
  float x; // xmm5_4
  float y; // xmm4_4
  int v10; // eax
  float v11; // xmm0_4
  float z; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm6_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  long double v20; // [esp-8h] [ebp-54h]
  long double v21; // [esp-8h] [ebp-54h]
  Vector xvec; // [esp+4h] [ebp-48h] BYREF
  Vector yvec; // [esp+10h] [ebp-3Ch] BYREF
  Vector vecEnd; // [esp+1Ch] [ebp-30h] BYREF
  Vector vecStart; // [esp+28h] [ebp-24h] BYREF
  Vector zvec; // [esp+34h] [ebp-18h] BYREF
  int v27; // [esp+40h] [ebp-Ch]
  float flDAngle; // [esp+44h] [ebp-8h]
  int i; // [esp+48h] [ebp-4h]
  float pEndVertsa; // [esp+5Ch] [ebp+10h]

  this->m_pStartEntity->GetOrigin(this: this->m_pStartEntity, a2: &vecStart);
  this->m_pEndEntity->GetOrigin(this: this->m_pEndEntity, a2: &vecEnd);
  zvec.x = vecEnd.x - vecStart.x;
  zvec.y = vecEnd.y - vecStart.y;
  zvec.z = vecEnd.z - vecStart.z;
  if ( VectorNormalize(vec: &zvec) < 0.001 )
  {
    zvec.x = 0.0;
    zvec.y = 0.0;
    zvec.z = 1.0;
  }
  VectorVectors(forward: &zvec, right: &xvec, up: &yvec);
  i = 0;
  flDAngle = 6.283185307179586 / (double)nCount;
  if ( nCount > 0 )
  {
    v20 = a2;
    v6 = pEndVerts;
    p_z = &pStartVerts->z;
    v27 = (char *)pEndVerts - (char *)pStartVerts;
    do
    {
      pEndVertsa = (float)i * flDAngle;
      __libm_sse2_cos(x: v20);
      __libm_sse2_sin(x: v21);
      x = xvec.x;
      y = xvec.y;
      v10 = v27;
      v11 = pEndVertsa * this->m_flStartRadius;
      *(p_z - 2) = (float)(xvec.x * v11) + vecStart.x;
      *(p_z - 1) = (float)(y * v11) + vecStart.y;
      z = xvec.z;
      *p_z = (float)(xvec.z * v11) + vecStart.z;
      v13 = pEndVertsa * this->m_flStartRadius;
      *(p_z - 2) = (float)(yvec.x * v13) + *(p_z - 2);
      *(p_z - 1) = (float)(yvec.y * v13) + *(p_z - 1);
      v14 = yvec.z;
      *p_z = (float)(yvec.z * v13) + *p_z;
      v15 = pEndVertsa * this->m_flEndRadius;
      v16 = (float)(x * v15) + vecEnd.x;
      v17 = (float)(y * v15) + vecEnd.y;
      v18 = yvec.x;
      *(float *)((char *)p_z + v10) = (float)(z * v15) + vecEnd.z;
      v6->x = v16;
      v6->y = v17;
      v19 = pEndVertsa * this->m_flEndRadius;
      v6->x = (float)(v18 * v19) + v16;
      v6->y = (float)(yvec.y * v19) + v6->y;
      *(float *)((char *)p_z + v10) = (float)(v14 * v19) + *(float *)((char *)p_z + v10);
      p_z += 3;
      ++v6;
      ++i;
    }
    while ( i < nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110ED0
// Name: public: virtual void CMapCylinder::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapCylinder::Render2D(CMapCylinder *this@<ecx>, double a2@<esi:edi>, CRender2D *pRender)
{
  int v3; // esi
  int v4; // edi
  Vector pStartVerts[8]; // [esp+4h] [ebp-D8h] BYREF
  Vector pEndVerts[8]; // [esp+64h] [ebp-78h] BYREF
  Vector End; // [esp+C4h] [ebp-18h] BYREF
  Vector Start; // [esp+D0h] [ebp-Ch] BYREF

  HIDWORD(a2) = this;
  if ( this->m_pStartEntity != nullptr && this->m_pEndEntity != nullptr )
  {
    if ( !this->IsSelected(this)
      || *(float *)(HIDWORD(a2) + 704) == 0.0 && *(float *)(HIDWORD(a2) + 708) == 0.0
      || !COptions::GetShowHelpers(this: &Options) )
    {
      CRender::SetDrawColor(
        this: pRender,
        r: *(_BYTE *)(HIDWORD(a2) + 16),
        g: *(_BYTE *)(HIDWORD(a2) + 17),
        b: *(_BYTE *)(HIDWORD(a2) + 18));
      (*(void (__thiscall **)(_DWORD, Vector *))(**(_DWORD **)(HIDWORD(a2) + 696) + 80))(
        a1: *(_DWORD *)(HIDWORD(a2) + 696),
        a2: &Start);
      (*(void (__thiscall **)(_DWORD, Vector *))(**(_DWORD **)(HIDWORD(a2) + 700) + 80))(
        a1: *(_DWORD *)(HIDWORD(a2) + 700),
        a2: &End);
      CRender::DrawLine(this: pRender, a2: (int)pRender, a3: SHIDWORD(a2), vStart: &Start, vEnd: &End);
    }
    else
    {
      CRender::SetDrawColor(this: pRender, r: 0xDCu, g: 0, b: 0);
      CMapCylinder::ComputeCylinderPoints(this: (CMapCylinder *)HIDWORD(a2), a2, nCount: 8, pStartVerts, pEndVerts);
      v3 = 0;
      v4 = 84;
      do
      {
        CRender::DrawLine(
          this: pRender,
          a2: v4,
          a3: v3 * 12,
          vStart: &pStartVerts[v3],
          vEnd: (Vector *)((char *)pStartVerts + v4));
        CRender::DrawLine(
          this: pRender,
          a2: v4,
          a3: v3 * 12,
          vStart: &pEndVerts[v3],
          vEnd: (Vector *)((char *)pEndVerts + v4));
        CRender::DrawLine(this: pRender, a2: v4, a3: v3 * 12, vStart: &pStartVerts[v3], vEnd: &pEndVerts[v3]);
        v4 = v3 * 12;
        ++v3;
      }
      while ( v3 < 8 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111020
// Name: protected: virtual void CMapCylinder::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCylinder::DoTransform(CMapCylinder *this, const VMatrix *matrix)
{
  CMapClass::DoTransform(this, matrix);
  CMapCylinder::BuildCylinder(this);
}

//------------------------------------------------------------------------------
// Address: 0x10111040
// Name: public: virtual void CMapCylinder::UpdateDependencies(class CMapWorld __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCylinder::UpdateDependencies(CMapCylinder *this, CMapWorld *pWorld, CMapEntity *pObject)
{
  char *v4; // eax
  WCKeyValuesT<WCKVBase_Dict> *v5; // ebx
  const char *Value; // eax
  CMapEntity *v7; // eax
  CMapEntity *updated; // eax
  bool v9; // zf
  const char *v10; // eax
  CMapEntity *m_pStartEntity; // eax
  const char *v12; // eax
  double v13; // xmm0_8
  CMapEntity *m_pEndEntity; // eax
  const char *v15; // eax
  double v16; // xmm0_8
  CMapEntity *v17; // [esp-8h] [ebp-18h]

  if ( pWorld != nullptr )
  {
    v4 = (char *)__RTDynamicCast(
                   inptr: this->m_pParent,
                   VfDelta: 0,
                   SrcType: &CMapAtom `RTTI Type Descriptor',
                   TargetType: &CMapEntity `RTTI Type Descriptor',
                   isReference: 0);
    if ( v4 != nullptr )
    {
      v5 = (WCKeyValuesT<WCKVBase_Dict> *)(v4 + 220);
      Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                this: (WCKeyValuesT<WCKVBase_Dict> *)(v4 + 220),
                pszKey: this->m_szStartValueKey,
                piIndex: nullptr);
      v7 = pWorld->FindChildByKeyValue(this: pWorld, a2: this->m_szStartKey, a3: Value, a4: 0, a5: 0);
      updated = (CMapEntity *)CMapClass::UpdateDependency(this, pOldAttached: this->m_pStartEntity, pNewAttached: v7);
      v9 = this->m_szEndValueKey[0] == 0;
      this->m_pStartEntity = updated;
      if ( v9 )
      {
        v17 = (CMapEntity *)this->GetParent(this);
      }
      else
      {
        v10 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: v5, pszKey: this->m_szEndValueKey, piIndex: nullptr);
        v17 = pWorld->FindChildByKeyValue(this: pWorld, a2: this->m_szEndKey, a3: v10, a4: 0, a5: 0);
      }
      this->m_pEndEntity = (CMapEntity *)CMapClass::UpdateDependency(
                                           this,
                                           pOldAttached: this->m_pEndEntity,
                                           pNewAttached: v17);
      m_pStartEntity = this->m_pStartEntity;
      if ( pObject == m_pStartEntity )
      {
        this->m_flStartRadius = 0.0;
        if ( m_pStartEntity != nullptr && this->m_szStartRadiusKey[0] != 0 )
        {
          v12 = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                  this: &m_pStartEntity->m_KeyValues,
                  pszKey: this->m_szStartRadiusKey,
                  piIndex: nullptr);
          if ( v12 != nullptr )
            v13 = atof(nptr: v12);
          else
            v13 = 0.0;
          this->m_flStartRadius = v13;
        }
      }
      m_pEndEntity = this->m_pEndEntity;
      if ( pObject == m_pEndEntity )
      {
        this->m_flEndRadius = 0.0;
        if ( m_pEndEntity != nullptr && this->m_szEndRadiusKey[0] != 0 )
        {
          v15 = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                  this: &m_pEndEntity->m_KeyValues,
                  pszKey: this->m_szEndRadiusKey,
                  piIndex: nullptr);
          if ( v15 != nullptr )
            v16 = atof(nptr: v15);
          else
            v16 = 0.0;
          this->m_flEndRadius = v16;
        }
      }
      CMapCylinder::BuildCylinder(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101111E0
// Name: public: CMapCylinder::CMapCylinder(void)
// Source: json
//------------------------------------------------------------------------------
CMapCylinder *__thiscall CMapCylinder::CMapCylinder(CMapCylinder *this)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapCylinder_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapCylinder_vtbl *)&CMapCylinder::`vftable';
  this->m_szStartKey[0] = 0;
  this->m_szStartValueKey[0] = 0;
  this->m_szStartRadiusKey[0] = 0;
  this->m_szEndKey[0] = 0;
  this->m_szEndValueKey[0] = 0;
  this->m_szEndRadiusKey[0] = 0;
  this->m_pStartEntity = nullptr;
  this->m_pEndEntity = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101112D0
// Name: public: CMapCylinder::CMapCylinder(char const __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMapCylinder *__thiscall CMapCylinder::CMapCylinder(
        CMapCylinder *this,
        const char *pszStartKey,
        const char *pszStartValueKey,
        const char *pszStartRadiusKey,
        const char *pszEndKey,
        const char *pszEndValueKey,
        const char *pszEndRadiusKey)
{
  const char *v8; // eax
  char v9; // cl
  const char *v10; // ecx
  const char *v11; // eax
  char v12; // dl
  char v13; // cl
  const char *v14; // eax
  char v15; // cl

  CMapClass::CMapClass(this);
  this->__vftable = (CMapCylinder_vtbl *)&CMapHelper::`vftable';
  this->m_szStartKey[0] = 0;
  this->m_szStartValueKey[0] = 0;
  this->m_szStartRadiusKey[0] = 0;
  this->m_szEndKey[0] = 0;
  this->m_szEndValueKey[0] = 0;
  this->m_szEndRadiusKey[0] = 0;
  this->m_pStartEntity = nullptr;
  this->m_pEndEntity = nullptr;
  this->__vftable = (CMapCylinder_vtbl *)&CMapCylinder::`vftable';
  strcpy(this->m_szStartKey, pszStartKey);
  strcpy(this->m_szStartValueKey, pszStartValueKey);
  v8 = pszStartRadiusKey;
  if ( pszStartRadiusKey != nullptr )
  {
    do
    {
      v9 = *v8;
      v8[this->m_szStartRadiusKey - pszStartRadiusKey] = *v8;
      ++v8;
    }
    while ( v9 != 0 );
  }
  v10 = pszEndKey;
  if ( pszEndKey != nullptr )
  {
    v11 = pszEndValueKey;
    if ( pszEndValueKey != nullptr )
    {
      do
      {
        v12 = *v10;
        v10[this->m_szEndKey - pszEndKey] = *v10;
        ++v10;
      }
      while ( v12 != 0 );
      do
      {
        v13 = *v11;
        v11[this->m_szEndValueKey - pszEndValueKey] = *v11;
        ++v11;
      }
      while ( v13 != 0 );
      v14 = pszEndRadiusKey;
      if ( pszEndRadiusKey != nullptr )
      {
        do
        {
          v15 = *v14;
          v14[this->m_szEndRadiusKey - pszEndRadiusKey] = *v14;
          ++v14;
        }
        while ( v15 != 0 );
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101113F0
// Name: public: virtual void CMapCylinder::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapCylinder::CalcBounds(CMapCylinder *this@<ecx>, double a2@<esi:edi>, int bFullUpdate)
{
  int i; // esi
  Vector pEndVerts[16]; // [esp+4h] [ebp-180h] BYREF
  Vector pStartVerts[16]; // [esp+C4h] [ebp-C0h] BYREF

  CMapClass::CalcBounds(this, bFullUpdate);
  if ( this->m_pStartEntity != nullptr && this->m_pEndEntity != nullptr )
  {
    CMapCylinder::ComputeCylinderPoints(this, a2, nCount: 16, pStartVerts, pEndVerts);
    for ( i = 0; i < 16; ++i )
    {
      BoundBox::UpdateBounds(this: &this->m_CullBox, pt: &pStartVerts[i]);
      BoundBox::UpdateBounds(this: &this->m_CullBox, pt: &pEndVerts[i]);
    }
    this->m_BoundingBox.bmins.x = this->m_CullBox.bmins.x;
    this->m_BoundingBox.bmins.y = this->m_CullBox.bmins.y;
    this->m_BoundingBox.bmins.z = this->m_CullBox.bmins.z;
    this->m_BoundingBox.bmaxs.x = this->m_CullBox.bmaxs.x;
    this->m_BoundingBox.bmaxs.y = this->m_CullBox.bmaxs.y;
    this->m_BoundingBox.bmaxs.z = this->m_CullBox.bmaxs.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111490
// Name: public: virtual class CMapClass __near * CMapCylinder::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapCylinder *__thiscall CMapCylinder::Copy(CMapCylinder *this, BOOL bUpdateDependencies)
{
  CMapCylinder *v3; // eax
  CMapCylinder *v4; // esi

  v3 = (CMapCylinder *)operator new(nSize: 0x2C8u);
  if ( v3 != nullptr )
    v4 = CMapCylinder::CMapCylinder(this: v3);
  else
    v4 = nullptr;
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10111510
// Name: class CMapClass __near * CMapCylinder_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapCylinder *__cdecl CMapCylinder_CreateObject()
{
  CMapCylinder *v0; // eax

  v0 = (CMapCylinder *)operator new(nSize: 0x2C8u);
  if ( v0 != nullptr )
    return CMapCylinder::CMapCylinder(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10111570
// Name: public: static class CMapClass __near * CMapCylinder::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapCylinder *__cdecl CMapCylinder::Create(CHelperInfo *pHelperInfo, CMapEntity *pParent)
{
  const char *v3; // edi
  char **m_pMemory; // ecx
  char **v5; // edx
  int m_Size; // eax
  const char *v7; // ebx
  const char *v8; // esi
  CMapCylinder *v9; // eax
  CMapCylinder *v10; // esi
  char chRed; // [esp+10h] [ebp-20h]
  char chGreen; // [esp+14h] [ebp-1Ch]
  char chBlue; // [esp+18h] [ebp-18h]
  const char *pszStartRadiusKey; // [esp+1Ch] [ebp-14h]
  const char *pszStartKey; // [esp+20h] [ebp-10h]
  const char *pszStartValueKey; // [esp+38h] [ebp+8h]

  v3 = nullptr;
  chRed = -1;
  chGreen = -1;
  chBlue = -1;
  if ( pHelperInfo->m_Parameters.m_Size > 0 && *pHelperInfo->m_Parameters.m_Memory.m_pMemory != nullptr )
    chRed = atoi(nptr: *(const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory);
  if ( pHelperInfo->m_Parameters.m_Size > 1 )
  {
    m_pMemory = pHelperInfo->m_Parameters.m_Memory.m_pMemory;
    if ( m_pMemory[1] != nullptr )
      chGreen = atoi(nptr: m_pMemory[1]);
  }
  if ( pHelperInfo->m_Parameters.m_Size > 2 )
  {
    v5 = pHelperInfo->m_Parameters.m_Memory.m_pMemory;
    if ( v5[2] != nullptr )
      chBlue = atoi(nptr: v5[2]);
  }
  m_Size = pHelperInfo->m_Parameters.m_Size;
  if ( m_Size > 3 )
    pszStartKey = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 3);
  else
    pszStartKey = nullptr;
  if ( m_Size > 4 )
    pszStartValueKey = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 4);
  else
    pszStartValueKey = nullptr;
  if ( m_Size > 5 )
    pszStartRadiusKey = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 5);
  else
    pszStartRadiusKey = nullptr;
  if ( m_Size > 6 )
    v7 = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 6);
  else
    v7 = nullptr;
  if ( m_Size > 7 )
    v3 = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 7);
  if ( m_Size > 8 )
    v8 = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 8);
  else
    v8 = nullptr;
  if ( pszStartKey == nullptr || pszStartValueKey == nullptr )
    return nullptr;
  v9 = (CMapCylinder *)operator new(nSize: 0x2C8u);
  if ( v9 != nullptr )
    v10 = CMapCylinder::CMapCylinder(
            this: v9,
            pszStartKey,
            pszStartValueKey,
            pszStartRadiusKey,
            pszEndKey: v7,
            pszEndValueKey: v3,
            pszEndRadiusKey: v8);
  else
    v10 = nullptr;
  v10->SetRenderColor_2(this: v10, a2: chRed, a3: chGreen, a4: chBlue);
  if ( v7 == nullptr || v3 == nullptr )
    v10->m_pEndEntity = pParent;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10111720
// Name: public: virtual void CMapCylinder::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapCylinder::Render3D(CMapCylinder *this@<ecx>, double a2@<esi:edi>, CRender3D *pRender)
{
  int v3; // ebx
  char v4; // cl
  char v5; // dl
  unsigned __int8 (__thiscall *v6)(_DWORD); // edx
  unsigned int v7; // esi
  int v8; // edi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float *m_pCurrPosition; // eax
  int v13; // xmm0_4
  int v14; // xmm1_4
  int v15; // xmm2_4
  float *v16; // eax
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float *v20; // eax
  int v21; // xmm0_4
  int v22; // xmm1_4
  int v23; // xmm2_4
  float *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float *v28; // eax
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float *v32; // eax
  int v33; // eax
  unsigned int v34; // edi
  int m_nVertexCount; // eax
  int v36; // esi
  Vector pStartVerts[16]; // [esp+8h] [ebp-3B0h] BYREF
  Vector pEndVerts[16]; // [esp+C8h] [ebp-2F0h] BYREF
  CMeshBuilder meshBuilder; // [esp+188h] [ebp-230h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+370h] [ebp-48h]
  Vector Start; // [esp+374h] [ebp-44h] BYREF
  Vector End; // [esp+380h] [ebp-38h] BYREF
  float v43; // [esp+38Ch] [ebp-2Ch]
  float v44; // [esp+390h] [ebp-28h]
  float v45; // [esp+394h] [ebp-24h]
  float v46; // [esp+398h] [ebp-20h]
  float v47; // [esp+39Ch] [ebp-1Ch]
  int v48; // [esp+3A0h] [ebp-18h]
  IMesh *pMesh; // [esp+3A4h] [ebp-14h]
  float color; // [esp+3A8h] [ebp-10h]
  int v51; // [esp+3B4h] [ebp-4h]

  LODWORD(a2) = this;
  v3 = 0;
  if ( this->m_pStartEntity != nullptr && this->m_pEndEntity != nullptr )
  {
    CRender3D::BeginRenderHitTarget(this: pRender, pObject: (CMapInstance *)this, uHandle: 0);
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
    (*(void (__thiscall **)(_DWORD, Vector *, _DWORD))(**(_DWORD **)(LODWORD(a2) + 696) + 80))(
      a1: *(_DWORD *)(LODWORD(a2) + 696),
      a2: &Start,
      a3: HIDWORD(a2));
    (*(void (__thiscall **)(_DWORD, Vector *))(**(_DWORD **)(LODWORD(a2) + 700) + 80))(
      a1: *(_DWORD *)(LODWORD(a2) + 700),
      a2: &End);
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(a2) + 4))(a1: LODWORD(a2)) != 0 )
    {
      LOWORD(color) = -1;
      BYTE2(color) = 0;
    }
    else
    {
      v4 = *(_BYTE *)(LODWORD(a2) + 17);
      v5 = *(_BYTE *)(LODWORD(a2) + 18);
      LOBYTE(color) = *(_BYTE *)(LODWORD(a2) + 16);
      BYTE1(color) = v4;
      BYTE2(color) = v5;
    }
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v51 = 0;
    HIDWORD(a2) = materials->GetRenderContext(this: materials);
    v48 = HIDWORD(a2);
    pRenderContext.m_pObject = (IMatRenderContext *)HIDWORD(a2);
    LOBYTE(v51) = 1;
    if ( HIDWORD(a2) != 0 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(a2) + 8))(a1: HIDWORD(a2));
    LOBYTE(v51) = 2;
    HIDWORD(a2) = (*(int (__thiscall **)(_DWORD, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)HIDWORD(a2) + 228))(
                    a1: HIDWORD(a2),
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    v6 = *(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(a2) + 4);
    pMesh = (IMesh *)HIDWORD(a2);
    if ( v6(a1: LODWORD(a2)) == 0
      || *(float *)(LODWORD(a2) + 704) == 0.0 && *(float *)(LODWORD(a2) + 708) == 0.0
      || !COptions::GetShowHelpers(this: &Options) )
    {
      meshBuilder.m_pMesh = (IMesh *)HIDWORD(a2);
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)HIDWORD(a2) + 40))(a1: HIDWORD(a2), a2: 1);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 2, a3: 2, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = (IIndexBuffer *)(HIDWORD(a2) + 4);
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::AttachBegin(
        this: &meshBuilder.m_VertexBuilder,
        pMesh: (IMesh *)HIDWORD(a2),
        nMaxVertexCount: 2,
        desc: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      v34 = BYTE2(color) | ((BYTE1(color) | ((LOBYTE(color) | 0xFFFFFF00) << 8)) << 8);
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v34;
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = Start;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v34;
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = End;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      if ( meshBuilder.m_bGenerateIndices )
      {
        switch ( meshBuilder.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
            break;
          case MATERIAL_POLYGON:
            m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
            break;
          case MATERIAL_INSTANCED_QUADS:
            m_nVertexCount = 0;
            break;
          default:
            m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
            break;
        }
        CIndexBuilder::GenerateIndices(
          this: &meshBuilder.m_IndexBuilder,
          primitiveType: meshBuilder.m_Type,
          nIndexCount: m_nVertexCount);
      }
      meshBuilder.m_pMesh->UnlockMesh(
        this: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
        a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
        a4: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_pMesh = nullptr;
    }
    else
    {
      CMapCylinder::ComputeCylinderPoints(this: (CMapCylinder *)LODWORD(a2), a2, nCount: 16, pStartVerts, pEndVerts);
      meshBuilder.m_pMesh = (IMesh *)HIDWORD(a2);
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)HIDWORD(a2) + 40))(a1: HIDWORD(a2), a2: 1);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 96, a3: 96, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = (IIndexBuffer *)(HIDWORD(a2) + 4);
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 96;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::AttachBegin(
        this: &meshBuilder.m_VertexBuilder,
        pMesh: (IMesh *)HIDWORD(a2),
        nMaxVertexCount: 96,
        desc: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      v7 = BYTE2(color) | ((BYTE1(color) | ((LOBYTE(color) | 0xFFFFFF00) << 8)) << 8);
      v8 = 180;
      do
      {
        x = pStartVerts[v3].x;
        y = pStartVerts[v3].y;
        z = pStartVerts[v3].z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v7;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = x;
        m_pCurrPosition[1] = y;
        color = x;
        v47 = y;
        v43 = z;
        m_pCurrPosition[2] = z;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v13 = *(_DWORD *)((char *)&pStartVerts[0].x + v8);
        v14 = *(_DWORD *)((char *)&pStartVerts[0].y + v8);
        v15 = *(_DWORD *)((char *)&pStartVerts[0].z + v8);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v7;
        v16 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v13;
        *((_DWORD *)v16 + 1) = v14;
        *((_DWORD *)v16 + 2) = v15;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v17 = pEndVerts[v3].x;
        v18 = pEndVerts[v3].y;
        v19 = pEndVerts[v3].z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v7;
        v20 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
        v20[1] = v18;
        v44 = v17;
        v45 = v18;
        v46 = v19;
        v20[2] = v19;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v21 = *(_DWORD *)((char *)&pEndVerts[0].x + v8);
        v22 = *(_DWORD *)((char *)&pEndVerts[0].y + v8);
        v23 = *(_DWORD *)((char *)&pEndVerts[0].z + v8);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v7;
        v24 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v21;
        *((_DWORD *)v24 + 1) = v22;
        *((_DWORD *)v24 + 2) = v23;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v25 = color;
        v26 = v47;
        v27 = v43;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v7;
        v28 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v25;
        v28[1] = v26;
        v28[2] = v27;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v29 = v44;
        v30 = v45;
        v31 = v46;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v7;
        v32 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
        v32[1] = v30;
        v32[2] = v31;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v8 = v3 * 12;
        ++v3;
      }
      while ( v3 < 16 );
      if ( meshBuilder.m_bGenerateIndices )
      {
        switch ( meshBuilder.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            v33 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            v33 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
            break;
          case MATERIAL_POLYGON:
            v33 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            v33 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
            break;
          case MATERIAL_INSTANCED_QUADS:
            v33 = 0;
            break;
          default:
            v33 = meshBuilder.m_VertexBuilder.m_nVertexCount;
            break;
        }
        CIndexBuilder::GenerateIndices(
          this: &meshBuilder.m_IndexBuilder,
          primitiveType: meshBuilder.m_Type,
          nIndexCount: v33);
      }
      meshBuilder.m_pMesh->UnlockMesh(
        this: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
        a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
        a4: &meshBuilder);
      HIDWORD(a2) = pMesh;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_pMesh = nullptr;
    }
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)HIDWORD(a2) + 48))(a1: HIDWORD(a2), a2: -1);
    CRender::PopRenderMode(this: pRender);
    CRender3D::EndRenderHitTarget(this: pRender, a2: -1);
    LOBYTE(v51) = 3;
    v36 = v48;
    (*(void (__thiscall **)(int))(*(_DWORD *)v48 + 12))(a1: v48);
    LOBYTE(v51) = 0;
    (*(void (__thiscall **)(int))(*(_DWORD *)v36 + 4))(a1: v36);
    v51 = -1;
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
  }
}
