// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapentity.cpp
// Functions: 75
// ============================================================

#include "hammer\mapentity.h"

//------------------------------------------------------------------------------
// Address: 0x10121190
// Name: public: virtual char const __near * CMapEntity::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapEntity::GetType(CMapEntity *this)
{
  return CMapEntity::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x101211A0
// Name: public: virtual int CMapEntity::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapEntity::IsMapClass(CMapEntity *this, const char *Type)
{
  return Type == CMapEntity::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x101211C0
// Name: int CompareEntityNames(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompareEntityNames(char *szName1, char *szName2)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax

  v2 = -1;
  strchr(string: szName1, chr: 0x2Au);
  if ( v3 != 0 )
    v2 = v3 - (_DWORD)szName1;
  strchr(string: szName2, chr: 0x2Au);
  if ( v4 != 0 )
  {
    v5 = v4 - (_DWORD)szName2;
    if ( v2 == -1 || v2 >= v5 )
      v2 = v5;
  }
  if ( v2 == -1 )
    return _V_stricmp(s1: szName1, s2: szName2);
  if ( v2 <= 0 )
    return 0;
  return V_strncasecmp(s1: szName1, s2: szName2, n: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10121230
// Name: private: void CMapEntity::AddBoundBoxForClass(class GDclass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapEntity::AddBoundBoxForClass(CMapEntity *this@<ecx>, int a2@<ebx>, GDclass *pClass, bool bLoading)
{
  CMapAlignedBox *v5; // esi
  CMapAlignedBox *v6; // eax
  CMapAlignedBox_vtbl *v7; // ebx
  SelectionState_t v8; // eax
  CMapWorld *WorldObject; // eax
  Vector Mins; // [esp+8h] [ebp-24h] BYREF
  Vector Maxs; // [esp+14h] [ebp-18h] BYREF
  int v12; // [esp+28h] [ebp-4h]

  v5 = nullptr;
  if ( pClass != nullptr && pClass->m_bGotSize )
  {
    GDclass::GetBoundBox(this: pClass, pfMins: &Mins, pfMaxs: &Maxs);
  }
  else
  {
    Mins.z = -8.0;
    Mins.y = -8.0;
    Mins.x = -8.0;
    Maxs.z = 8.0;
    Maxs.y = 8.0;
    Maxs.x = 8.0;
  }
  v6 = (CMapAlignedBox *)operator new(nSize: 0x134u);
  v12 = 0;
  if ( v6 != nullptr )
    v5 = CMapAlignedBox::CMapAlignedBox(this: v6, &Mins, &Maxs);
  v12 = -1;
  ((void (__thiscall *)(CMapAlignedBox *, Vector *, int))v5->SetOrigin)(a1: v5, a2: &this->m_Origin, a3: a2);
  v7 = v5->__vftable;
  v8 = this->GetSelectionState(this);
  v7->SetSelectionState(this: v5, a2: v8);
  WorldObject = CMapClass::GetWorldObject(pStart: this);
  if ( bLoading || WorldObject == nullptr )
    this->AddChild(this, a2: v5);
  else
    CMapWorld::AddObjectToWorld(this: WorldObject, pObject: v5, pParent: (CMapWorld *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10121340
// Name: private: void CMapEntity::AddHelper(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapEntity::AddHelper(CMapEntity *this@<ecx>, int a2@<ebx>, CMapClass *pHelper, bool bLoading)
{
  CMapClass_vtbl *v5; // ebx
  int v6; // eax
  GDclass *m_pClass; // eax
  CMapWorld *WorldObject; // eax
  CMapAnimator *v9; // eax
  Vector vecCenter; // [esp+8h] [ebp-Ch] BYREF

  if ( (this->flags & 1) == 0 )
    BoundBox::GetBoundsCenter(this: &this->m_Render2DBox, ptdest: &vecCenter);
  ((void (__thiscall *)(CMapClass *))pHelper->SetOrigin)(a1: pHelper);
  v5 = pHelper->__vftable;
  v6 = ((int (__thiscall *)(CMapEntity *, int))this->GetSelectionState)(a1: this, a2);
  v5->SetSelectionState(this: pHelper, a2: (SelectionState_t)v6);
  m_pClass = this->m_pClass;
  if ( m_pClass != nullptr )
    ((void (__thiscall *)(CMapClass *, _DWORD))pHelper->SetRenderColor)(
      a1: pHelper,
      a2: *(_DWORD *)&m_pClass->m_rgbColor);
  WorldObject = CMapClass::GetWorldObject(pStart: this);
  if ( bLoading || WorldObject == nullptr )
    this->AddChild(this, a2: pHelper);
  else
    CMapWorld::AddObjectToWorld(this: WorldObject, pObject: pHelper, pParent: (CMapWorld *)this);
  v9 = (CMapAnimator *)__RTDynamicCast(
                         inptr: pHelper,
                         VfDelta: 0,
                         SrcType: &CMapClass `RTTI Type Descriptor',
                         TargetType: &CMapAnimator `RTTI Type Descriptor',
                         isReference: 0);
  if ( v9 != nullptr )
    this->m_pAnimatorChild = v9;
}

//------------------------------------------------------------------------------
// Address: 0x10121400
// Name: public: virtual void CMapEntity::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::CalcBounds(CMapEntity *this, int bFullUpdate)
{
  GDclass *m_pClass; // eax

  CMapClass::CalcBounds(this, bFullUpdate);
  m_pClass = this->m_pClass;
  if ( m_pClass != nullptr && m_pClass->m_bSolid )
    BoundBox::GetBoundsCenter(this: &this->m_Render2DBox, ptdest: &this->m_Origin);
}

//------------------------------------------------------------------------------
// Address: 0x10121430
// Name: public: virtual char const __near * CMapEntity::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapEntity::GetDescription(CMapEntity *this)
{
  const char *Value; // eax
  char *m_szClass; // eax
  char v5; // cl

  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "targetname", piIndex: nullptr);
  if ( Value != nullptr )
  {
    sprintf(string: szBuf, format: "%s - %s", Value, this->m_szClass);
    return szBuf;
  }
  else
  {
    m_szClass = this->m_szClass;
    do
    {
      v5 = *m_szClass;
      m_szClass[szBuf - this->m_szClass] = *m_szClass;
      ++m_szClass;
    }
    while ( v5 != 0 );
    return szBuf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121490
// Name: public: virtual void CMapEntity::GetRenderColor(class CRender2D __near *,unsigned char __near &,unsigned char __near &,unsigned char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::GetRenderColor(
        CMapEntity *this,
        CRender2D *pRender,
        unsigned __int8 *red,
        unsigned __int8 *green,
        unsigned __int8 *blue)
{
  GDclass *m_pClass; // eax
  color32_s m_rgbColor; // eax

  if ( this->IsSelected(this) )
  {
    *red = Options.colors.clrSelection;
    *green = BYTE1(Options.colors.clrSelection);
    *blue = BYTE2(Options.colors.clrSelection);
  }
  else
  {
    m_pClass = this->m_pClass;
    if ( m_pClass != nullptr )
    {
      m_rgbColor = m_pClass->m_rgbColor;
      *red = m_rgbColor.r;
      *green = m_rgbColor.g;
      *blue = m_rgbColor.b;
    }
    else
    {
      *red = Options.colors.clrEntity;
      *green = BYTE1(Options.colors.clrEntity);
      *blue = BYTE2(Options.colors.clrEntity);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121520
// Name: public: virtual struct color32_s CMapEntity::GetRenderColor(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
color32_s __thiscall CMapEntity::GetRenderColor(CMapEntity *this, CRender2D *pRender, CRender2D *pRendera)
{
  this->GetRenderColor(
    this,
    a2: pRendera,
    a3: (unsigned __int8 *)pRender,
    a4: (unsigned __int8 *)&pRender->__vftable + 1,
    a5: (unsigned __int8 *)&pRender->__vftable + 2);
  return (color32_s)pRender;
}

//------------------------------------------------------------------------------
// Address: 0x10121550
// Name: public: virtual unsigned int CMapEntity::GetSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMapEntity::GetSize(CMapEntity *this)
{
  return 388;
}

//------------------------------------------------------------------------------
// Address: 0x10121560
// Name: private: static enum ChunkFileResult_t CMapEntity::LoadEditorKeyCallback(char const __near *,char const __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapEntity::LoadEditorKeyCallback(
        const char *szKey,
        const char *szValue,
        CMapEntity *pMapEntity)
{
  if ( _V_stricmp(s1: szKey, s2: "logicalpos") != 0 )
    return CMapClass::LoadEditorKeyCallback(szKey, szValue, pObject: pMapEntity);
  CChunkFile::ReadKeyValueVector2(pszValue: szValue, vec: &pMapEntity->m_vecLogicalPosition);
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x101215B0
// Name: private: static enum ChunkFileResult_t CMapEntity::LoadEditorCallback(class CChunkFile __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapEntity::LoadEditorCallback(CChunkFile *pFile, CMapEntity *pObject)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapEntity::LoadEditorKeyCallback,
           pData: pObject);
}

//------------------------------------------------------------------------------
// Address: 0x101215D0
// Name: private: static enum ChunkFileResult_t CMapEntity::LoadSolidCallback(class CChunkFile __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapEntity::LoadSolidCallback(CMapDisp *pFile, CMapEntity *pEntity)
{
  CMapSolid *v2; // eax
  CMapSolid *v3; // esi
  ChunkFileResult_t v4; // edi
  bool bValid; // [esp+Fh] [ebp-Dh] BYREF
  int v7; // [esp+18h] [ebp-4h]

  v2 = (CMapSolid *)operator new(nSize: 0x240u);
  v7 = 0;
  if ( v2 != nullptr )
    v3 = CMapSolid::CMapSolid(this: v2, Parent0: nullptr);
  else
    v3 = nullptr;
  v7 = -1;
  v4 = CMapSolid::LoadVMF(this: v3, pFile, &bValid);
  if ( v4 != ChunkFile_Ok || !bValid )
  {
    if ( v3 != nullptr )
      ((void (__thiscall *)(CMapSolid *, int))v3->~CMapClass)(a1: v3, a2: 1);
    return v4;
  }
  else
  {
    pEntity->AddChild(this: pEntity, a2: v3);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121680
// Name: public: virtual void CMapEntity::SetOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::SetOrigin(CMapEntity *this, Vector *o)
{
  Vector vecOrigin; // [esp+4h] [ebp-Ch] BYREF

  this->GetOrigin(this, a2: &vecOrigin);
  if ( o->x != vecOrigin.x || o->y != vecOrigin.y || o->z != vecOrigin.z )
  {
    CMapClass::SetOrigin(this, origin: o);
    if ( (this->flags & 1) != 0 && !CMapClass::s_bLoadingVMF )
    {
      this->CalcBounds(this, a2: 1);
      this->PostUpdate(this, a2: Notify_Changed);
      this->SignalChanged(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121710
// Name: public: void CMapEntity::AssignNodeID(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::AssignNodeID(CMapEntity *this)
{
  int m_nNextNodeID; // ecx
  char szID[80]; // [esp+4h] [ebp-50h] BYREF

  m_nNextNodeID = CMapDoc::m_pMapDoc->m_nNextNodeID;
  CMapDoc::m_pMapDoc->m_nNextNodeID = m_nNextNodeID + 1;
  itoa(val: m_nNextNodeID, buf: szID, radix: 0xAu);
  this->SetKeyValue(this: &this->CEditGameClass, a2: "nodeid", a3: szID);
}

//------------------------------------------------------------------------------
// Address: 0x10121760
// Name: public: void CMapEntity::CalculateTypeFlags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::CalculateTypeFlags(CMapEntity *this)
{
  unsigned int v2; // esi
  char *m_szClass; // ebx

  v2 = 0;
  m_szClass = this->m_szClass;
  this->m_EntityTypeFlags = 0;
  if ( this != (CMapEntity *)-252 )
  {
    do
    {
      if ( _V_stricmp(s1: m_szClass, s2: s_ClassFlagsTable[v2].m_pClassname) == 0 )
        this->m_EntityTypeFlags |= s_ClassFlagsTable[v2].m_nFlagsToOR;
      ++v2;
    }
    while ( v2 < 5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101217B0
// Name: public: virtual void CMapEntity::SignalChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::SignalChanged(CMapEntity *this)
{
  if ( (this->m_EntityTypeFlags & 1) != 0 )
    SignalUpdate(ev: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101217D0
// Name: public: virtual void CMapEntity::PostloadWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::PostloadWorld(CMapEntity *this, CMapWorld *pWorld)
{
  const char *Value; // eax
  const char *v4; // eax
  int v5; // eax
  char *v6; // eax
  char *v7; // edx
  char v8; // cl
  GDclass *m_pClass; // ecx
  GDclass *v10; // eax
  int m_nNextNodeID; // ecx
  char buf[16]; // [esp+8h] [ebp-6Ch] BYREF
  char szClassName[64]; // [esp+18h] [ebp-5Ch] BYREF
  Vector Origin; // [esp+58h] [ebp-1Ch] BYREF
  Vector2D vecLogicalPos; // [esp+64h] [ebp-10h] BYREF
  char *s1; // [esp+6Ch] [ebp-8h]
  int nIndex; // [esp+70h] [ebp-4h] BYREF

  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "origin", piIndex: &nIndex);
  if ( Value != nullptr )
  {
    sscanf(string: Value, format: "%f %f %f", &Origin, &Origin.y, &Origin.z);
    this->SetOrigin(this, a2: &Origin);
  }
  v4 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "angle", piIndex: &nIndex);
  if ( v4 != nullptr )
  {
    v5 = atoi(nptr: v4);
    CEditGameClass::ImportAngle(this: &this->CEditGameClass, nAngle: v5);
    WCKVBase_Dict::RemoveKeyAt(this: &this->m_KeyValues, nIndex);
  }
  v6 = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "classname", piIndex: &nIndex);
  if ( v6 != nullptr )
  {
    v7 = (char *)(szClassName - v6);
    do
    {
      v8 = *v6;
      v6[(_DWORD)v7] = *v6;
      ++v6;
    }
    while ( v8 != 0 );
    this->SetClass(this: &this->CEditGameClass, a2: szClassName, a3: true);
    if ( WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "classname", piIndex: &nIndex) != nullptr )
      WCKVBase_Dict::RemoveKeyAt(this: &this->m_KeyValues, nIndex);
  }
  if ( (this->flags & 1) != 0 )
  {
    m_pClass = this->m_pClass;
    if ( (m_pClass == nullptr || GDclass::VarForName(this: m_pClass, pszName: "origin", piIndex: nullptr) == nullptr)
      && WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "origin", piIndex: &nIndex) != nullptr )
    {
      WCKVBase_Dict::RemoveKeyAt(this: &this->m_KeyValues, nIndex);
    }
  }
  v10 = this->m_pClass;
  if ( v10 != nullptr )
  {
    s1 = v10->m_szName;
    if ( V_strncasecmp(s1: v10->m_szName, s2: "info_node", n: 9) == 0
      && _V_stricmp(s1, s2: "info_node_link") != 0
      && WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "nodeid", piIndex: nullptr) == nullptr )
    {
      m_nNextNodeID = CMapDoc::m_pMapDoc->m_nNextNodeID;
      CMapDoc::m_pMapDoc->m_nNextNodeID = m_nNextNodeID + 1;
      itoa(val: m_nNextNodeID, buf, radix: 0xAu);
      this->SetKeyValue(this: &this->CEditGameClass, a2: "nodeid", a3: buf);
    }
  }
  vecLogicalPos = *this->GetLogicalPosition(this);
  if ( vecLogicalPos.x == 99999.0 )
  {
    CMapDoc::GetDefaultNewLogicalPosition(this: CMapDoc::m_pMapDoc, vecPosition: &vecLogicalPos);
    this->SetLogicalPosition(this, a2: &vecLogicalPos);
  }
  CMapClass::PostloadWorld(this, pWorld);
  CMapEntity::CalculateTypeFlags(this);
}

//------------------------------------------------------------------------------
// Address: 0x10121A00
// Name: private: void CMapEntity::SetMoveParent(class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::SetMoveParent(CMapEntity *this, CMapEntity *pEnt)
{
  CMapEntity *v2; // eax
  int v3; // edx

  v2 = pEnt;
  v3 = 0;
  while ( 1 )
  {
    if ( v2 == nullptr )
    {
LABEL_5:
      this->m_pMoveParent = pEnt;
      return;
    }
    if ( v2 == this )
      break;
    v2 = v2->m_pMoveParent;
    if ( ++v3 >= 300 )
      goto LABEL_5;
  }
  this->m_pMoveParent = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10121A50
// Name: public: virtual void CMapEntity::OnPrePaste(class CMapClass __near *,class CMapWorld __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::OnPrePaste(
        CMapEntity *this,
        CMapClass *pCopy,
        CMapWorld *pSourceWorld,
        CMapWorld *pDestWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  GDclass *m_pClass; // eax
  const char *m_szName; // esi
  int m_nNextNodeID; // ecx
  char buf[80]; // [esp+8h] [ebp-50h] BYREF

  m_pClass = this->m_pClass;
  if ( m_pClass != nullptr )
  {
    m_szName = m_pClass->m_szName;
    if ( V_strncasecmp(s1: m_pClass->m_szName, s2: "info_node", n: 9) == 0
      && _V_stricmp(s1: m_szName, s2: "info_node_link") != 0 )
    {
      m_nNextNodeID = CMapDoc::m_pMapDoc->m_nNextNodeID;
      CMapDoc::m_pMapDoc->m_nNextNodeID = m_nNextNodeID + 1;
      itoa(val: m_nNextNodeID, buf, radix: 0xAu);
      ((void (__thiscall *)(CMapClass *, const char *, char *))pCopy[1].IsSelected)(
        a1: &pCopy[1],
        a2: "nodeid",
        a3: buf);
    }
  }
  CMapClass::OnPrePaste(this, pCopy, pSourceWorld, pDestWorld, OriginalList, NewList);
}

//------------------------------------------------------------------------------
// Address: 0x10121AF0
// Name: public: virtual void CMapEntity::OnRemoveFromWorld(class CMapWorld __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::OnRemoveFromWorld(CMapEntity *this, CMapWorld *pWorld, bool bNotifyChildren)
{
  CEditGameClass::Connections_FixBad(this: &this->CEditGameClass, bRelink: false);
  CEditGameClass::Upstream_FixBad(this: &this->CEditGameClass);
  CMapClass::OnRemoveFromWorld(this, pWorld, bNotifyChildren);
}

//------------------------------------------------------------------------------
// Address: 0x10121B30
// Name: public: virtual void CMapEntity::OnNotifyDependent(class CMapClass __near *,enum Notify_Dependent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::OnNotifyDependent(CMapEntity *this, CMapEntity *pObject, KeyValues *eNotifyType)
{
  CMapWorld *WorldObject; // edi
  char *Value; // eax
  CMapEntity *updated; // eax
  CMapEntity *EntityByName; // [esp-4h] [ebp-10h]

  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: (int)pObject, msg: eNotifyType);
  if ( eNotifyType == (KeyValues *)1 && pObject == this->m_pMoveParent )
  {
    WorldObject = CMapClass::GetWorldObject(pStart: this);
    Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                      this: &this->m_KeyValues,
                      pszKey: "parentname",
                      piIndex: nullptr);
    if ( WorldObject != nullptr && Value != nullptr )
    {
      EntityByName = CMapWorld::FindEntityByName(
                       this: WorldObject,
                       pszName: Value,
                       bVisiblesOnly: false,
                       bSearchInstanceParms: false);
      updated = (CMapEntity *)CMapClass::UpdateDependency(
                                this,
                                pOldAttached: this->m_pMoveParent,
                                pNewAttached: EntityByName);
    }
    else
    {
      updated = (CMapEntity *)CMapClass::UpdateDependency(
                                this,
                                pOldAttached: this->m_pMoveParent,
                                pNewAttached: nullptr);
    }
    CMapEntity::SetMoveParent(this, pEnt: updated);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121BB0
// Name: public: virtual class CMapEntity __near * CMapEntity::FindChildByKeyValue(char const __near *,char const __near *,bool __near *,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__thiscall CMapEntity::FindChildByKeyValue(
        CMapEntity *this,
        const char *key,
        const char *value,
        bool *bIsInInstance,
        VMatrix *InstanceMatrix)
{
  const char *v5; // edi
  const char *v7; // ebx
  const char *v8; // eax

  v5 = key;
  if ( key == nullptr )
    return nullptr;
  v7 = value;
  if ( value == nullptr )
    return nullptr;
  v8 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: key, piIndex: (int *)&key);
  if ( v8 == nullptr || _V_stricmp(s1: v7, s2: v8) != 0 )
    return CMapClass::FindChildByKeyValue(this, key: v5, value: v7, bIsInInstance, InstanceMatrix);
  else
    return this;
}

//------------------------------------------------------------------------------
// Address: 0x10121C20
// Name: public: virtual bool CMapEntity::GetTransformMatrix(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapEntity::GetTransformMatrix(CMapEntity *this, VMatrix *matrix)
{
  CMapEntity *m_pMoveParent; // eax
  char v4; // bl
  CMapAnimator_vtbl *v5; // eax
  const VMatrix *v7; // eax
  VMatrix v8; // [esp+Ch] [ebp-80h] BYREF
  VMatrix animatorMat; // [esp+4Ch] [ebp-40h] BYREF

  m_pMoveParent = this->m_pMoveParent;
  v4 = 0;
  if ( m_pMoveParent != nullptr && m_pMoveParent != this )
    v4 = ((int (__stdcall *)(VMatrix *))m_pMoveParent->GetTransformMatrix)(a1: matrix);
  if ( this->m_pAnimatorChild == nullptr )
    return v4;
  v5 = this->m_pAnimatorChild->__vftable;
  if ( v4 == 0 )
    return ((int (__stdcall *)(VMatrix *))v5->GetTransformMatrix)(a1: matrix);
  if ( ((unsigned __int8 (__stdcall *)(VMatrix *))v5->GetTransformMatrix)(a1: &animatorMat) == 0 )
    return 1;
  v7 = VMatrix::operator*(this: matrix, result: &v8, vm: &animatorMat);
  VMatrix::operator=(this: matrix, mOther: v7);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10121CB0
// Name: public: virtual enum ChunkFileResult_t CMapEntity::SaveEditorData(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CMapEntity::SaveEditorData(CMapEntity *this, CChunkFile *pFile)
{
  vgui::Panel *result; // eax

  result = (vgui::Panel *)CChunkFile::WriteKeyValueVector2(
                            this: pFile,
                            pszKey: "logicalpos",
                            vec: &this->m_vecLogicalPosition);
  if ( result == nullptr )
    return CBaseToolSystem::CreateActionMenu((vgui::Panel *)this, key: (wchar_t)pFile);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10121CE0
// Name: public: virtual bool CMapEntity::UpdateObjectColor(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapEntity::UpdateObjectColor(CMapEntity *this)
{
  GDclass *m_pClass; // eax

  if ( CMapClass::UpdateObjectColor(this) != 0 )
    return 1;
  m_pClass = this->m_pClass;
  if ( m_pClass != nullptr )
  {
    ((void (__thiscall *)(CMapEntity *, _DWORD))this->SetRenderColor)(a1: this, a2: *(_DWORD *)&m_pClass->m_rgbColor);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10121D10
// Name: public: virtual void CMapEntity::UpdateDependencies(class CMapWorld __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::UpdateDependencies(CMapEntity *this, CMapWorld *pWorld, CMapClass *pObject)
{
  char *Value; // eax
  CMapEntity *updated; // eax
  CMapEntity *EntityByName; // [esp-4h] [ebp-8h]

  Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                    this: &this->m_KeyValues,
                    pszKey: "parentname",
                    piIndex: nullptr);
  EntityByName = nullptr;
  if ( Value != nullptr )
    EntityByName = CMapWorld::FindEntityByName(
                     this: pWorld,
                     pszName: Value,
                     bVisiblesOnly: false,
                     bSearchInstanceParms: false);
  updated = (CMapEntity *)CMapClass::UpdateDependency(
                            this,
                            pOldAttached: this->m_pMoveParent,
                            pNewAttached: EntityByName);
  CMapEntity::SetMoveParent(this, pEnt: updated);
  if ( CMapDoc::m_pMapDoc != nullptr && !CMapDoc::m_pMapDoc->m_bLoading )
  {
    CEditGameClass::Connections_FixBad(this: &this->CEditGameClass, bRelink: true);
    CEditGameClass::Upstream_FixBad(this: &this->CEditGameClass);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121D90
// Name: public: virtual void CMapEntity::AlignOnPlane(class Vector __near &,struct PLANE __near *,enum CMapEntity::alignType_e)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapEntity::AlignOnPlane(
        CMapEntity *this@<ecx>,
        int a2@<esi>,
        Vector *pos,
        PLANE *plane,
        CMapEntity::alignType_e align)
{
  float v5; // xmm0_4
  float v7; // xmm0_4
  void (__thiscall *SetOrigin)(CMapPoint *, Vector *); // edx
  Vector vecNewPos; // [esp+0h] [ebp-Ch] BYREF

  v5 = 0.0;
  if ( align != ALIGN_TOP )
  {
    if ( align == ALIGN_BOTTOM )
      v5 = this->m_Origin.z - this->m_Render2DBox.bmins.z;
  }
  else
  {
    v5 = this->m_Render2DBox.bmaxs.z - this->m_Origin.z;
  }
  v7 = v5 + 1.0;
  vecNewPos.x = (float)(plane->normal.x * v7) + pos->x;
  vecNewPos.y = (float)(plane->normal.y * v7) + pos->y;
  SetOrigin = this->SetOrigin;
  vecNewPos.z = (float)(plane->normal.z * v7) + pos->z;
  ((void (__thiscall *)(CMapEntity *, Vector *, int))SetOrigin)(a1: this, a2: &vecNewPos, a3: a2);
  this->SignalChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x10121E20
// Name: public: virtual class CMapClass __near * CMapEntity::PrepareSelection(enum SelectMode_t)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__thiscall CMapEntity::PrepareSelection(CMapEntity *this, SelectMode_t eSelectMode)
{
  CMapClass *v3; // eax

  if ( eSelectMode != selectGroups )
  {
    if ( eSelectMode == selectSolids && (this->flags & 1) == 0 )
      return nullptr;
  }
  else if ( this->m_pParent != nullptr && !IsWorldObject(pObject: this->m_pParent) )
  {
    v3 = this->GetParent(this);
    return (CMapEntity *)v3->PrepareSelection(this: v3, a2: selectGroups);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10121E80
// Name: public: virtual void CMapEntity::GetRenderLogicalBox(class Vector2D __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::GetRenderLogicalBox(CMapEntity *this, Vector2D *mins, Vector2D *maxs)
{
  mins->x = this->m_vecLogicalPosition.x;
  maxs->x = (float)((float)(this->m_vecLogicalPosition.x + 300.0) + 50.0) + 50.0;
  mins->y = this->m_vecLogicalPosition.y;
  maxs->y = this->m_vecLogicalPosition.y + 300.0;
}

//------------------------------------------------------------------------------
// Address: 0x10121EE0
// Name: public: virtual class Vector2D const __near & CMapEntity::GetLogicalPosition(void)
// Source: json
//------------------------------------------------------------------------------
const Vector2D *__thiscall CMapEntity::GetLogicalPosition(CMapEntity *this)
{
  return &this->m_vecLogicalPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10121EF0
// Name: public: virtual void CMapEntity::SetLogicalPosition(class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::SetLogicalPosition(CMapEntity *this, const Vector2D *vecPosition)
{
  this->m_vecLogicalPosition = *vecPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10121F10
// Name: public: void CMapEntity::GetLogicalConnectionPosition(enum LogicalConnection_t,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::GetLogicalConnectionPosition(
        CMapEntity *this,
        LogicalConnection_t i,
        Vector2D *vecPosition)
{
  Vector2D vecMaxs; // [esp+0h] [ebp-10h] BYREF
  Vector2D vecMins; // [esp+8h] [ebp-8h] BYREF

  this->GetRenderLogicalBox(this, a2: &vecMins, a3: &vecMaxs);
  vecPosition->y = (float)(vecMaxs.y + vecMins.y) * 0.5;
  if ( i != LOGICAL_CONNECTION_INPUT )
    vecPosition->x = vecMaxs.x;
  else
    vecPosition->x = vecMins.x;
}

//------------------------------------------------------------------------------
// Address: 0x10121F70
// Name: public: virtual bool CMapEntity::ShouldSnapToHalfGrid(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapEntity::ShouldSnapToHalfGrid(CMapEntity *this)
{
  GDclass *m_pClass; // eax

  m_pClass = this->m_pClass;
  return m_pClass != nullptr && m_pClass->m_bHalfGridSnap;
}

//------------------------------------------------------------------------------
// Address: 0x10121F90
// Name: public: int CMapEntity::GetNodeID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapEntity::GetNodeID(CMapEntity *this)
{
  const char *Value; // eax

  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "nodeid", piIndex: nullptr);
  if ( Value != nullptr )
    return atoi(nptr: Value);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10121FC0
// Name: public: virtual bool CMapEntity::HitTest2D(class CMapView2D __near *,class Vector2D const __near &,struct HitInfo_s __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CMapEntity::HitTest2D(CMapEntity *this, CMapView2D *pView, const Vector2D *point, HitInfo_s *HitData)
{
  GDclass *m_pClass; // eax
  double v8; // st7
  float y; // xmm0_4
  signed int v10; // esi
  Vector2D *i; // ebx
  int v12; // edx
  Vector2D vecEdges[4]; // [esp+4h] [ebp-70h] BYREF
  Vector vecMaxs; // [esp+24h] [ebp-50h] BYREF
  Vector vecMins; // [esp+30h] [ebp-44h] BYREF
  Vector vecViewPoint; // [esp+3Ch] [ebp-38h] BYREF
  Vector vecCenter; // [esp+48h] [ebp-2Ch] BYREF
  Vector2D vecClientCenter; // [esp+54h] [ebp-20h] BYREF
  __int128 vecClientMaxs; // [esp+5Ch] [ebp-18h] OVERLAPPED BYREF
  int x1; // [esp+6Ch] [ebp-8h]
  int y1; // [esp+70h] [ebp-4h]
  int x2; // [esp+7Ch] [ebp+8h]

  if ( (*((_BYTE *)&this->CMapClass + 180) & 2) == 0 )
    return 0;
  if ( CMapClass::HitTest2D(this, pView, point, HitData) != 0 )
    return 1;
  m_pClass = this->m_pClass;
  if ( m_pClass == nullptr || !m_pClass->m_bPoint )
    return 0;
  BoundBox::GetBoundsCenter(this: &this->m_Render2DBox, ptdest: &vecCenter);
  pView->WorldToClient(this: &pView->CMapView, a2: &vecClientCenter, a3: &vecCenter);
  CCamera::GetViewPoint(this: pView->m_pCamera, ViewPoint: &vecViewPoint);
  HitData->pObject = this;
  v8 = *(&vecViewPoint.x + pView->axThird) - *(&vecCenter.x + pView->axThird);
  y1 = HIWORD(pView) | 0xC00;
  *(_QWORD *)&vecClientMaxs = (__int64)v8;
  HitData->nDepth = (__int64)v8;
  if ( CMapView2DBase::CheckDistance(this: pView, vecCheck: point, vecRef: &vecClientCenter, nDist: 4) )
  {
    HitData->uData = 0;
    return 1;
  }
  else if ( Options.view2d.bSelectbyhandles != 0 )
  {
    return 0;
  }
  else
  {
    y = point->y;
    x2 = (int)(float)(point->x + 2.0);
    x1 = (int)(float)(point->x - 2.0);
    y1 = (int)(float)(y - 2.0);
    CMapClass::GetRender2DBox(this, mins: &vecMins, maxs: &vecMaxs);
    pView->WorldToClient(this: &pView->CMapView, a2: (Vector2D *)((char *)&vecClientMaxs + 8), a3: &vecMins);
    pView->WorldToClient(this: &pView->CMapView, a2: (Vector2D *)&vecClientMaxs, a3: &vecMaxs);
    vecEdges[1].y = *((float *)&vecClientMaxs + 3);
    vecEdges[0] = *((Vector2D *)&vecClientMaxs + 1);
    LODWORD(vecEdges[1].x) = vecClientMaxs;
    LODWORD(vecEdges[2].x) = vecClientMaxs;
    *(Vector2D *)&vecEdges[2].y = *(Vector2D *)((char *)&vecClientMaxs + 4);
    vecEdges[3].y = *((float *)&vecClientMaxs + 1);
    v10 = 0;
    for ( i = vecEdges; ; ++i )
    {
      v12 = ++v10 % 4;
      if ( IsLineInside(pt1: i, pt2: &vecEdges[v12], x1, y1, x2, y2: (int)(float)(y + 2.0)) != 0 )
        break;
      if ( v10 >= 4 )
        return 0;
    }
    HitData->uData = v10;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101221D0
// Name: public: virtual bool CMapEntity::HitTestLogical(class CMapViewLogical __near *,class Vector2D const __near &,struct HitInfo_s __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapEntity::HitTestLogical(
        CMapEntity *this,
        CMapViewLogical *pView,
        const Vector2D *vecPoint,
        HitInfo_s *hitData)
{
  Vector2D vecMaxs; // [esp+4h] [ebp-20h] BYREF
  Vector2D vecMins; // [esp+Ch] [ebp-18h] BYREF
  Vector2D vecClientMins; // [esp+14h] [ebp-10h] BYREF
  Vector2D vecClientMaxs; // [esp+1Ch] [ebp-8h] BYREF

  if ( (*((_BYTE *)&this->CMapClass + 180) & 2) == 0 || !this->IsLogical(this) || !this->IsVisibleLogical(this) )
    return 0;
  if ( CMapClass::HitTestLogical(this, pView, point: vecPoint, hitData) )
    return 1;
  this->GetRenderLogicalBox(this, a2: &vecMins, a3: &vecMaxs);
  CMapViewLogical::WorldToClient(this: pView, ptClient: &vecClientMins, vWorld: &vecMins);
  CMapViewLogical::WorldToClient(this: pView, ptClient: &vecClientMaxs, vWorld: &vecMaxs);
  NormalizeBox(mins: &vecClientMins, maxs: &vecClientMaxs);
  if ( IsPointInside(pt: vecPoint, mins: &vecClientMins, maxs: &vecClientMaxs) )
  {
    hitData->pObject = this;
    hitData->uData = 0;
    hitData->nDepth = 0;
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101222C0
// Name: public: bool CMapEntity::NameMatches(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapEntity::NameMatches(CMapEntity *this, char *szName)
{
  char *Value; // eax

  Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                    this: &this->m_KeyValues,
                    pszKey: "targetname",
                    piIndex: nullptr);
  return Value != nullptr && CompareEntityNames(szName1: Value, szName2: szName) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10122300
// Name: public: bool CMapEntity::ClassNameMatches(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapEntity::ClassNameMatches(CMapEntity *this, char *szName)
{
  return this != (CMapEntity *)-252 && CompareEntityNames(szName1: this->m_szClass, szName2: szName) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10122330
// Name: public: CUtlReferenceList<class CMapEntity>::~CUtlReferenceList<class CMapEntity>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlReferenceList<CMapEntity>::~CUtlReferenceList<CMapEntity>(CUtlReferenceList<CMapClass> *this)
{
  CUtlReference<CMapClass> *m_pHead; // eax
  CUtlReference<CMapClass> *m_pNext; // edx

  m_pHead = this->m_pHead;
  if ( this->m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      m_pHead->m_pNext = nullptr;
      m_pHead->m_pPrev = nullptr;
      m_pHead->m_pObject = nullptr;
      m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  this->m_pHead = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10122360
// Name: public: virtual CMapEntity::~CMapEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::~CMapEntity(CMapEntity *this)
{
  CUtlReference<CMapEntity> *m_pHead; // eax
  CUtlReference<CMapEntity> *m_pNext; // ecx

  this->CMapClass::CMapPoint::CMapAtom::__vftable = (CMapEntity_vtbl *)&CMapEntity::`vftable'{for `CMapClass'};
  this->CEditGameClass::__vftable = (CEditGameClass_vtbl *)&CMapEntity::`vftable'{for `CEditGameClass'};
  if ( (this->m_EntityTypeFlags & 1) != 0 )
    SignalUpdate(ev: 1);
  m_pHead = this->m_References.m_pHead;
  if ( m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      m_pHead->m_pNext = nullptr;
      m_pHead->m_pPrev = nullptr;
      m_pHead->m_pObject = nullptr;
      m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  this->m_References.m_pHead = nullptr;
  CEditGameClass::~CEditGameClass(this: &this->CEditGameClass);
  CMapClass::~CMapClass(this);
}

//------------------------------------------------------------------------------
// Address: 0x10122410
// Name: public: virtual class CMapClass __near * CMapEntity::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__thiscall CMapEntity::CopyFrom(CMapEntity *this, CMapClass *pobj, bool bUpdateDependencies)
{
  char *Value; // eax
  char *v5; // edx
  char v6; // cl
  const char *v7; // eax
  char szOldTargetName[256]; // [esp+Ch] [ebp-100h] BYREF

  this->flags = *((_WORD *)&pobj[1].m_Dependents.m_Memory + 4);
  this->m_Origin = pobj->m_Origin;
  this->m_vecLogicalPosition = *(Vector2D *)&pobj[1].m_nID;
  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pobj, bUpdateDependencies);
  Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                    this: &this->m_KeyValues,
                    pszKey: "targetname",
                    piIndex: nullptr);
  if ( Value != nullptr )
  {
    v5 = (char *)(szOldTargetName - Value);
    do
    {
      v6 = *Value;
      Value[(_DWORD)v5] = *Value;
      ++Value;
    }
    while ( v6 != 0 );
  }
  CEditGameClass::CopyFrom(this: &this->CEditGameClass, pFrom: (CEditGameClass *)&pobj[1]);
  v7 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "targetname", piIndex: nullptr);
  if ( bUpdateDependencies && v7 != nullptr && _V_stricmp(s1: szOldTargetName, s2: v7) != 0 )
    CMapClass::UpdateAllDependencies(pObject: this);
  CMapEntity::CalculateTypeFlags(this);
  this->SignalChanged(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10122500
// Name: private: static enum ChunkFileResult_t CMapEntity::LoadKeyCallback(char const __near *,char const __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapEntity::LoadKeyCallback(const char *szKey, const char *szValue, CMapEntity *pEntity)
{
  int m_nNextLoadID; // eax

  if ( _V_stricmp(s1: szKey, s2: "id") != 0 )
  {
    WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &pEntity->m_KeyValues, pszKey: szKey, pszValue: szValue);
  }
  else
  {
    pEntity->m_nID = atoi(nptr: szValue);
    m_nNextLoadID = CMapDoc::m_pMapDoc->m_nNextLoadID;
    CMapDoc::m_pMapDoc->m_nNextLoadID = m_nNextLoadID + 1;
    pEntity->m_nLoadID = m_nNextLoadID;
  }
  CMapEntity::CalculateTypeFlags(this: pEntity);
  pEntity->SignalChanged(this: pEntity);
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x10122570
// Name: private: static enum ChunkFileResult_t CMapEntity::LoadHiddenCallback(class CChunkFile __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapEntity::LoadHiddenCallback(CChunkFile *pFile, CMapEntity *pEntity)
{
  ChunkFileResult_t Chunk; // edi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-18h] BYREF
  int v5; // [esp+1Ch] [ebp-4h]

  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v5 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "solid",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapEntity::LoadSolidCallback,
    pData: pEntity);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "editor",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapEntity::LoadEditorCallback,
    pData: pEntity);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(this: pFile, pfnKeyHandler: nullptr, pData: nullptr);
  CChunkFile::PopHandlers(this: pFile);
  v5 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x10122610
// Name: private: void CMapEntity::EnsureUniqueNodeID(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::EnsureUniqueNodeID(CMapEntity *this, CMapWorld *pWorld)
{
  const char *Value; // eax
  int v4; // ebx
  CMapClass *FirstDescendent; // eax
  CMapEntity *v6; // eax
  const char *v7; // eax
  int v8; // eax
  int m_nNextNodeID; // ecx
  EnumChildrenPos_t pos; // [esp+Ch] [ebp-84h] BYREF

  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "nodeid", piIndex: nullptr);
  if ( Value != nullptr )
  {
    v4 = atoi(nptr: Value);
    if ( v4 != 0 )
    {
      FirstDescendent = CMapClass::GetFirstDescendent(this: pWorld, (CMapClass *)&pos);
      if ( FirstDescendent == nullptr )
        return;
      while ( 1 )
      {
        v6 = (CMapEntity *)__RTDynamicCast(
                             inptr: FirstDescendent,
                             VfDelta: 0,
                             SrcType: &CMapClass `RTTI Type Descriptor',
                             TargetType: &CMapEntity `RTTI Type Descriptor',
                             isReference: 0);
        if ( v6 != nullptr && v6 != this )
        {
          v7 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &v6->m_KeyValues, pszKey: "nodeid", piIndex: nullptr);
          if ( v7 != nullptr )
          {
            v8 = atoi(nptr: v7);
            if ( v8 != 0 && v8 == v4 )
              break;
          }
        }
        FirstDescendent = CMapClass::GetNextDescendent(this: pWorld, (CMapClass *)&pos);
        if ( FirstDescendent == nullptr )
          return;
      }
    }
  }
  m_nNextNodeID = CMapDoc::m_pMapDoc->m_nNextNodeID;
  CMapDoc::m_pMapDoc->m_nNextNodeID = m_nNextNodeID + 1;
  itoa(val: m_nNextNodeID, buf: (char *)&pos.Stack[6].pos, radix: 0xAu);
  this->SetKeyValue(this: &this->CEditGameClass, a2: "nodeid", a3: (const char *)&pos.Stack[6].pos);
}

//------------------------------------------------------------------------------
// Address: 0x10122710
// Name: public: virtual void CMapEntity::OnPreClone(class CMapClass __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::OnPreClone(
        CMapEntity *this,
        CMapClass *pClone,
        CMapWorld *pWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  _DWORD *v6; // edi
  const char *Value; // eax
  GDclass *m_pClass; // esi
  const char *m_szName; // esi
  int m_nNextNodeID; // ecx
  char newName[128]; // [esp+Ch] [ebp-80h] BYREF

  CMapClass::OnPreClone(this, pNewObj: pClone, pWorld, OriginalList, NewList);
  if ( OriginalList->m_Size == 1
    && (_V_stricmp(s1: this->m_szClass, s2: "path_corner") == 0
     || _V_stricmp(s1: this->m_szClass, s2: "path_track") == 0
     || _V_stricmp(s1: this->m_szClass, s2: "info_blob_spit_path") == 0) )
  {
    v6 = __RTDynamicCast(
           inptr: pClone,
           VfDelta: 0,
           SrcType: &CMapClass `RTTI Type Descriptor',
           TargetType: &CMapEntity `RTTI Type Descriptor',
           isReference: 0);
    if ( v6 == nullptr )
      return;
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "targetname", piIndex: nullptr);
    if ( Value == nullptr || *Value == 0 )
      Value = "path";
    CMapWorld::GenerateNewTargetname(
      this: pWorld,
      startName: Value,
      outputName: newName,
      newNameBufferSize: 128,
      bMakeUnique: true,
      szPrefix: nullptr,
      pRoot: nullptr);
    (*(void (__thiscall **)(_DWORD *, const char *, char *))(v6[54] + 4))(a1: v6 + 54, a2: "targetname", a3: newName);
  }
  m_pClass = this->m_pClass;
  if ( m_pClass != nullptr )
  {
    m_szName = m_pClass->m_szName;
    if ( V_strncasecmp(s1: m_szName, s2: "info_node", n: 9) == 0 && _V_stricmp(s1: m_szName, s2: "info_node_link") != 0 )
    {
      m_nNextNodeID = CMapDoc::m_pMapDoc->m_nNextNodeID;
      CMapDoc::m_pMapDoc->m_nNextNodeID = m_nNextNodeID + 1;
      itoa(val: m_nNextNodeID, buf: &newName[48], radix: 0xAu);
      ((void (__thiscall *)(CMapClass *, const char *, char *))pClone[1].IsSelected)(
        a1: &pClone[1],
        a2: "nodeid",
        a3: &newName[48]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10122870
// Name: public: virtual void CMapEntity::OnAddToWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::OnAddToWorld(CMapEntity *this, CMapWorld *pWorld)
{
  GDclass *m_pClass; // eax
  const char *m_szName; // edi

  CMapClass::OnAddToWorld(this, pWorld);
  m_pClass = this->m_pClass;
  if ( m_pClass != nullptr )
  {
    m_szName = m_pClass->m_szName;
    if ( V_strncasecmp(s1: m_pClass->m_szName, s2: "info_node", n: 9) == 0
      && _V_stricmp(s1: m_szName, s2: "info_node_link") != 0 )
    {
      CMapEntity::EnsureUniqueNodeID(this, pWorld);
    }
  }
  if ( WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "targetname", piIndex: nullptr) != nullptr )
    CMapClass::UpdateAllDependencies(pObject: this);
}

//------------------------------------------------------------------------------
// Address: 0x101228F0
// Name: public: virtual enum ChunkFileResult_t CMapEntity::SaveVMF(class CChunkFile __near *,class CSaveInfo __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapEntity::SaveVMF(CMapEntity *this, CChunkFile *pFile, IMapEntity_SaveInfo_t *pSaveInfo)
{
  GDclass *m_pClass; // ecx
  CMapClass *FirstDescendent; // edi
  int v8; // edi
  EnumChildrenPos_t pos; // [esp+24h] [ebp-D4h] BYREF
  char v10[28]; // [esp+A8h] [ebp-50h] BYREF
  int szOrigin_60; // [esp+100h] [ebp+8h]

  if ( !CSaveInfo::ShouldSaveObject(this: pSaveInfo, pObject: this)
    || (this->flags & 1) == 0 && this->m_Children.m_Size == 0 )
  {
    return ChunkFile_Ok;
  }
  if ( (*((_BYTE *)&this->CMapClass + 180) & 2) == 0 )
    CChunkFile::BeginChunk(this: pFile, pszChunkName: "hidden");
  if ( CChunkFile::BeginChunk(this: pFile, pszChunkName: "entity") == ChunkFile_Ok
    && CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "id", nValue: this->m_nID) == ChunkFile_Ok )
  {
    CEditGameClass::SaveVMF(this: &this->CEditGameClass, pFile, pSaveInfo);
  }
  if ( (this->flags & 1) != 0 )
  {
    m_pClass = this->m_pClass;
    if ( m_pClass == nullptr || GDclass::VarForName(this: m_pClass, pszName: "origin", piIndex: nullptr) == nullptr )
    {
      sprintf(string: v10, format: "%g %g %g", this->m_Origin.x, this->m_Origin.y, this->m_Origin.z);
      CChunkFile::WriteKeyValue(this: pFile, pszKey: "origin", pszValue: v10);
    }
  }
  szOrigin_60 = 0;
  FirstDescendent = CMapClass::GetFirstDescendent(this, (CMapClass *)&pos);
  if ( FirstDescendent != nullptr )
  {
    while ( szOrigin_60 == 0 )
    {
      if ( FirstDescendent->ShouldSerialize(this: FirstDescendent) )
        szOrigin_60 = FirstDescendent->SaveVMF(this: FirstDescendent, a2: pFile, a3: pSaveInfo);
      FirstDescendent = CMapClass::GetNextDescendent(this, (CMapClass *)&pos);
      if ( FirstDescendent == nullptr )
      {
        if ( szOrigin_60 != 0 )
          break;
        goto LABEL_20;
      }
    }
  }
  else
  {
LABEL_20:
    CMapClass::SaveVMF(this, pFile, pSaveInfo);
  }
  v8 = VmfSaveVmfEntityHandlers(pFile, pEntity: (IMapEntity_Type_t *)this, pSaveInfo);
  if ( v8 == 0 )
    CChunkFile::EndChunk(this: pFile);
  if ( (*((_BYTE *)&this->CMapClass + 180) & 2) == 0 )
    return CChunkFile::EndChunk(this: pFile);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10122A90
// Name: public: virtual bool CMapEntity::IsLogical(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapEntity::IsLogical(CMapEntity *this)
{
  GDclass *m_pClass; // eax

  m_pClass = this->m_pClass;
  return m_pClass != nullptr && (m_pClass->m_Inputs.m_Size > 0 || m_pClass->m_Outputs.m_Size > 0)
      || this->m_Connections.m_Size != 0
      || this->m_Upstream.m_Size != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10122B00
// Name: public: enum ChunkFileResult_t CMapEntity::LoadVMF(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapEntity::LoadVMF(CMapEntity *this, CChunkFile *pFile)
{
  CEditGameClass *v3; // eax
  ChunkFileResult_t Chunk; // esi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-18h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v7 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "solid",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapEntity::LoadSolidCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "hidden",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapEntity::LoadHiddenCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "editor",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapEntity::LoadEditorCallback,
    pData: this);
  if ( this != nullptr )
    v3 = &this->CEditGameClass;
  else
    v3 = nullptr;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "connections",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CEditGameClass::LoadConnectionsCallback,
    pData: v3);
  VmfAddMapEntityHandlers(pHandlerMap: &Handlers, pEntity: (IMapEntity_Type_t *)this);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapEntity::LoadKeyCallback,
            pData: this);
  CChunkFile::PopHandlers(this: pFile);
  v7 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x10122C40
// Name: public: CMapEntity::CMapEntity(void)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__thiscall CMapEntity::CMapEntity(CMapEntity *this)
{
  CMapClass::CMapClass(this);
  CEditGameClass::CEditGameClass(this: &this->CEditGameClass);
  this->CMapClass::CMapPoint::CMapAtom::__vftable = (CMapEntity_vtbl *)&CMapEntity::`vftable'{for `CMapClass'};
  this->CEditGameClass::__vftable = (CEditGameClass_vtbl *)&CMapEntity::`vftable'{for `CEditGameClass'};
  this->m_References.m_pHead = nullptr;
  this->flags = 0;
  this->m_pMoveParent = nullptr;
  this->m_pAnimatorChild = nullptr;
  this->m_vecLogicalPosition.x = 99999.0;
  this->m_vecLogicalPosition.y = 99999.0;
  CMapEntity::CalculateTypeFlags(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10122CF0
// Name: public: virtual class CMapClass __near * CMapEntity::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__thiscall CMapEntity::Copy(CMapEntity *this, BOOL bUpdateDependencies)
{
  CMapEntity *v3; // eax
  CMapEntity *v4; // esi

  v3 = (CMapEntity *)operator new(nSize: 0x184u);
  v4 = nullptr;
  if ( v3 != nullptr )
    v4 = CMapEntity::CMapEntity(this: v3);
  v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10122D60
// Name: public: void CMapEntity::NotifyChildKeyChanged(class CMapClass __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::NotifyChildKeyChanged(
        CMapEntity *this,
        CMapClass *pChild,
        const char *szKey,
        const char *szValue)
{
  int i; // ebx
  CMapClass *m_pObject; // edi
  unsigned int v7; // edi

  WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_KeyValues, pszKey: szKey, pszValue: szValue);
  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != pChild
      && pChild != nullptr
      && __RTDynamicCast(
           inptr: m_pObject,
           VfDelta: 0,
           SrcType: &CMapClass `RTTI Type Descriptor',
           TargetType: &CMapSolid `RTTI Type Descriptor',
           isReference: 0) == nullptr )
    {
      m_pObject->OnParentKeyChanged(this: m_pObject, a2: szKey, a3: szValue);
    }
  }
  v7 = 0;
  this->CalcBounds(this, a2: 0);
  this->m_EntityTypeFlags = 0;
  if ( this != (CMapEntity *)-252 )
  {
    do
    {
      if ( _V_stricmp(s1: this->m_szClass, s2: s_ClassFlagsTable[v7].m_pClassname) == 0 )
        this->m_EntityTypeFlags |= s_ClassFlagsTable[v7].m_nFlagsToOR;
      ++v7;
    }
    while ( v7 < 5 );
  }
  this->SignalChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x10122E50
// Name: public: bool CMapEntity::HasSolidChildren(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapEntity::HasSolidChildren(CMapEntity *this)
{
  int v2; // esi

  v2 = 0;
  if ( this->m_Children.m_Size <= 0 )
    return 0;
  while ( __RTDynamicCast(
            inptr: this->m_Children.m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v2 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
            VfDelta: 0,
            SrcType: &CMapClass `RTTI Type Descriptor',
            TargetType: &CMapSolid `RTTI Type Descriptor',
            isReference: 0) == nullptr )
  {
    if ( ++v2 >= this->m_Children.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10122EC0
// Name: public: virtual bool CMapEntity::OnApply(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapEntity::OnApply(CMapEntity *this)
{
  int i; // esi
  CMapClass *m_pObject; // ecx

  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
      m_pObject->OnApply(this: m_pObject);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10122F10
// Name: bool MapEntityList_HasInput(class CUtlReferenceVector<class CMapEntity> const __near *,char const __near *,enum InputOutputType_t)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MapEntityList_HasInput(
        const CUtlReferenceVector<CMapEntity> *pList,
        const char *szInput,
        InputOutputType_t eType)
{
  GDclass *v3; // edx
  int v4; // edi
  CMapEntity *m_pObject; // eax
  GDclass *m_pClass; // esi
  CClassInput *Input; // eax

  v3 = nullptr;
  v4 = 0;
  if ( pList->m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    m_pObject = pList->m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&pList->m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&pList->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
      m_pClass = m_pObject->m_pClass;
    else
      m_pClass = nullptr;
    if ( m_pClass != v3 && m_pClass != nullptr )
    {
      Input = GDclass::FindInput(this: m_pClass, szName: szInput);
      if ( Input == nullptr || eType != iotInvalid && Input->m_eType != eType )
        break;
      v3 = m_pClass;
    }
    if ( ++v4 >= pList->m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10122F90
// Name: public: virtual bool CMapEntity::IsIntersectingCordon(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapEntity::IsIntersectingCordon(CMapEntity *this, const Vector *vecMins, const Vector *vecMaxs)
{
  GDclass *m_pClass; // eax
  Vector vecOrigin; // [esp+4h] [ebp-Ch] BYREF

  m_pClass = this->m_pClass;
  if ( m_pClass == nullptr
    || !m_pClass->m_bPoint
    || CMapEntity::GetChildOfType<CMapSweptPlayerHull>(this, ignoredArg: nullptr) != nullptr )
  {
    return this->m_Render2DBox.IsIntersectingBox(this: &this->m_Render2DBox, a2: vecMins, a3: vecMaxs);
  }
  this->GetOrigin(this, a2: &vecOrigin);
  return IsPointInBox(pt: &vecOrigin, boxMin: vecMins, boxMax: vecMaxs);
}

//------------------------------------------------------------------------------
// Address: 0x10123000
// Name: class CMapClass __near * CMapEntity_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__cdecl CMapEntity_CreateObject()
{
  CMapEntity *v0; // eax

  v0 = (CMapEntity *)operator new(nSize: 0x184u);
  if ( v0 != nullptr )
    return CMapEntity::CMapEntity(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10123060
// Name: public: bool CHelperInfo::AddParameter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHelperInfo::AddParameter(CHelperInfo *this, const char *pszParameter)
{
  int v3; // eax
  char *v4; // ebx
  int m_nAllocationCount; // eax
  CUtlMemory<CCullTreeNode *,int> *p_m_Parameters; // esi
  int m_Size; // edi
  CCullTreeNode **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax

  if ( pszParameter == nullptr )
    return 0;
  if ( *pszParameter == 0 )
    return 0;
  v3 = strlen(pszParameter);
  if ( v3 <= 0 )
    return 0;
  v4 = (char *)operator new[](nSize: v3 + 1);
  if ( v4 == nullptr )
    return 0;
  strcpy(v4, pszParameter);
  m_nAllocationCount = this->m_Parameters.m_Memory.m_nAllocationCount;
  p_m_Parameters = (CUtlMemory<CCullTreeNode *,int> *)&this->m_Parameters;
  m_Size = this->m_Parameters.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Parameters[1].m_pMemory;
  m_pMemory = p_m_Parameters->m_pMemory;
  v9 = (int)p_m_Parameters[1].m_pMemory - m_Size - 1;
  p_m_Parameters[1].m_nAllocationCount = (int)p_m_Parameters->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = (char **)&p_m_Parameters->m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10123120
// Name: private: void CMapEntity::AddHelpersForClass(class GDclass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::AddHelpersForClass(CMapEntity *this, GDclass *pClass, bool bLoading)
{
  GDclass *v3; // edi
  CMapEntity *v4; // esi
  GDclass *m_pClass; // ecx
  int m_Size; // eax
  int v7; // edi
  CHelperInfo *Helper; // eax
  CMapClass *v9; // eax
  CMapClass *v10; // esi
  int v11; // edi
  GDinputvariable *VariableAt; // eax
  GDIV_TYPE m_eType; // ecx
  __int32 v14; // ecx
  __int32 v15; // ecx
  const char *m_szName; // edx
  int v17; // eax
  char v18; // cl
  int v19; // eax
  char v20; // cl
  int v21; // eax
  char v22; // cl
  CMapClass *v23; // eax
  CMapClass *v24; // esi
  int v25; // eax
  char v26; // cl
  CMapClass *v27; // eax
  CHelperInfo HelperInfo; // [esp+Ch] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > *p_m_Parameters; // [esp+120h] [ebp-20h]
  int nHelperCount; // [esp+124h] [ebp-1Ch]
  GDclass *v31; // [esp+128h] [ebp-18h]
  CMapEntity *v32; // [esp+12Ch] [ebp-14h]
  bool bAddedOneVisual; // [esp+133h] [ebp-Dh]
  int v34; // [esp+13Ch] [ebp-4h]

  v3 = pClass;
  v4 = this;
  v32 = this;
  bAddedOneVisual = false;
  if ( pClass != nullptr )
  {
    if ( pClass->m_bGotSize )
    {
      CMapEntity::AddBoundBoxForClass(this, a2: 0, pClass, bLoading);
      bAddedOneVisual = true;
    }
    m_pClass = v4->m_pClass;
    m_Size = m_pClass->m_Helpers.m_Size;
    v7 = 0;
    v31 = m_pClass;
    for ( nHelperCount = m_Size; v7 < nHelperCount; ++v7 )
    {
      Helper = GDclass::GetHelper(this: m_pClass, nIndex: v7);
      v9 = CHelperFactory::CreateHelper(pHelperInfo: Helper, pParent: v4);
      v10 = v9;
      if ( v9 != nullptr )
      {
        CMapEntity::AddHelper(this: v32, a2: 0, pHelper: v9, bLoading);
        if ( v10->IsVisualElement(this: v10) )
          bAddedOneVisual = true;
      }
      v4 = v32;
      m_pClass = v31;
    }
    v11 = 0;
    nHelperCount = m_pClass->m_nVariables;
    if ( nHelperCount > 0 )
    {
      p_m_Parameters = &HelperInfo.m_Parameters;
      while ( 1 )
      {
        VariableAt = GDclass::GetVariableAt(this: m_pClass, iIndex: v11);
        m_eType = VariableAt->m_eType;
        memset(&HelperInfo.m_Parameters, 0, sizeof(HelperInfo.m_Parameters));
        HelperInfo.m_szName[0] = 0;
        v34 = 2;
        v14 = m_eType - 23;
        if ( v14 != 0 )
        {
          v15 = v14 - 1;
          if ( v15 != 0 )
          {
            if ( v15 != 1 )
              goto LABEL_27;
            m_szName = VariableAt->m_szName;
            v17 = 0;
            do
            {
              v18 = aAxis[v17];
              HelperInfo.m_szName[v17++] = v18;
            }
            while ( v18 != 0 );
          }
          else
          {
            m_szName = VariableAt->m_szName;
            v19 = 0;
            do
            {
              v20 = aVecline[v19];
              HelperInfo.m_szName[v19++] = v20;
            }
            while ( v20 != 0 );
          }
        }
        else
        {
          m_szName = VariableAt->m_szName;
          v21 = 0;
          do
          {
            v22 = aOrigin[v21];
            HelperInfo.m_szName[v21++] = v22;
          }
          while ( v22 != 0 );
        }
        CHelperInfo::AddParameter(this: &HelperInfo, pszParameter: m_szName);
        v23 = CHelperFactory::CreateHelper(pHelperInfo: &HelperInfo, pParent: v4);
        v24 = v23;
        if ( v23 != nullptr )
        {
          CMapEntity::AddHelper(this: v32, a2: 0, pHelper: v23, bLoading);
          if ( v24->IsVisualElement(this: v24) )
            bAddedOneVisual = true;
        }
        v4 = v32;
LABEL_27:
        v34 = -1;
        CHelperInfo::~CHelperInfo(this: &HelperInfo);
        if ( ++v11 >= nHelperCount )
          break;
        m_pClass = v31;
      }
    }
    v3 = pClass;
  }
  if ( (v4->flags & 1) != 0 )
  {
    if ( v3 == nullptr )
    {
      memset(&HelperInfo.m_Parameters, 0, sizeof(HelperInfo.m_Parameters));
      HelperInfo.m_szName[0] = 0;
      v34 = 5;
      v25 = 0;
      do
      {
        v26 = aIconsprite[v25];
        HelperInfo.m_szName[v25++] = v26;
      }
      while ( v26 != 0 );
      CHelperInfo::AddParameter(this: &HelperInfo, pszParameter: "sprites/obsolete.vmt");
      v27 = CHelperFactory::CreateHelper(pHelperInfo: &HelperInfo, pParent: v4);
      if ( v27 != nullptr )
      {
        CMapEntity::AddHelper(this: v4, a2: 0, pHelper: v27, bLoading);
        bAddedOneVisual = true;
      }
      v34 = -1;
      CHelperInfo::~CHelperInfo(this: &HelperInfo);
    }
    if ( !bAddedOneVisual )
      CMapEntity::AddBoundBoxForClass(this: v4, a2: 0, pClass: v3, bLoading);
  }
  if ( !CMapClass::s_bLoadingVMF )
  {
    v4->CalcBounds(this: v4, a2: 1);
    v4->PostUpdate(this: v4, a2: Notify_Changed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101233D0
// Name: ReplaceNodeIDRecursive
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReplaceNodeIDRecursive(CMapClass *pRoot, int nOldNodeID, int nNewNodeID)
{
  GDclass **v3; // eax
  GDclass **v4; // ebx
  GDclass *v5; // ecx
  int v6; // edi
  GDinputvariable *VariableAt; // eax
  char *m_szName; // esi
  const char *Value; // eax
  int i; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v12; // ecx
  char szValue[100]; // [esp+Ch] [ebp-84h] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+70h] [ebp-20h] BYREF
  CUtlReference<CMapClass> *v15; // [esp+74h] [ebp-1Ch]
  CMapClass *v16; // [esp+78h] [ebp-18h]
  int nVarCount; // [esp+7Ch] [ebp-14h]
  GDclass *pClass; // [esp+80h] [ebp-10h]
  int v19; // [esp+8Ch] [ebp-4h]

  v3 = (GDclass **)__RTDynamicCast(
                     inptr: pRoot,
                     VfDelta: 0,
                     SrcType: &CMapClass `RTTI Type Descriptor',
                     TargetType: &CMapEntity `RTTI Type Descriptor',
                     isReference: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v5 = v3[62];
    pClass = v5;
    if ( v5 != nullptr )
    {
      v6 = 0;
      nVarCount = v5->m_nVariables;
      if ( nVarCount > 0 )
      {
        while ( 1 )
        {
          VariableAt = GDclass::GetVariableAt(this: v5, iIndex: v6);
          if ( VariableAt->m_eType == ivNodeDest )
          {
            m_szName = VariableAt->m_szName;
            Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                      this: (WCKeyValuesT<WCKVBase_Dict> *)(v4 + 55),
                      pszKey: VariableAt->m_szName,
                      piIndex: nullptr);
            if ( Value != nullptr && atoi(nptr: Value) == nOldNodeID )
            {
              itoa(val: nNewNodeID, buf: szValue, radix: 0xAu);
              ((void (__thiscall *)(char *, char *, char *))v4[54]->m_rgbColor)(
                a1: (char *)v4 + 216,
                a2: m_szName,
                a3: szValue);
            }
          }
          if ( ++v6 >= nVarCount )
            break;
          v5 = pClass;
        }
      }
    }
  }
  else
  {
    for ( i = 0; i < pRoot->m_Children.m_Size; ++i )
    {
      m_pObject = pRoot->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pRoot->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pRoot->m_Children.m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        v16 = pRoot->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pRoot->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pRoot->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v12 = m_pObject->m_References.m_pHead;
        if ( v12 != nullptr )
          v12->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v15 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v19 = 0;
      ReplaceNodeIDRecursive(pRoot: v16, nOldNodeID, nNewNodeID);
      v19 = -1;
      if ( v16 != nullptr )
      {
        if ( v15 != nullptr )
        {
          v15->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v15;
        }
        else if ( (CUtlReference<CMapClass> **)v16->m_References.m_pHead == &m_pHead )
        {
          v16->m_References.m_pHead = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v15 = nullptr;
        m_pHead = nullptr;
        v16 = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123590
// Name: ReplaceNodeIDRefs
// Source: json
//------------------------------------------------------------------------------
void __usercall ReplaceNodeIDRefs(CUtlReferenceVector<CMapClass> *newList@<edi>, int nOldNodeID, int nNewNodeID)
{
  int i; // esi

  if ( nOldNodeID != nNewNodeID )
  {
    for ( i = 0; i < newList->m_Size; ++i )
      ReplaceNodeIDRecursive(
        pRoot: newList->m_Memory.m_pMemory[i >> (*((int *)&newList->m_Memory + 2) >> 27)][i
                                                                                 & ((32
                                                                                   * *((_DWORD *)&newList->m_Memory + 2)) >> 5)].m_pObject,
        nOldNodeID,
        nNewNodeID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101235E0
// Name: public: virtual void CMapEntity::AddChild(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::AddChild(CMapEntity *this, CMapClass *pChild)
{
  CMapEntity *v2; // esi
  int Inorder; // ebx
  MDkeyvalue KeyValue; // [esp+8h] [ebp-260h] BYREF
  CMapEntity *v5; // [esp+258h] [ebp-10h]
  int v6; // [esp+264h] [ebp-4h]

  v2 = this;
  v5 = this;
  CMapClass::AddChild(this, pChild);
  if ( __RTDynamicCast(
         inptr: pChild,
         VfDelta: 0,
         SrcType: &CMapClass `RTTI Type Descriptor',
         TargetType: &CMapSolid `RTTI Type Descriptor',
         isReference: 0) == nullptr )
  {
    Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v2->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
    if ( Inorder != 0xFFFF )
    {
      while ( 1 )
      {
        KeyValue = v2->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.elem;
        v6 = 0;
        pChild->OnParentKeyChanged(this: pChild, a2: (const char *)&KeyValue, a3: KeyValue.szValue);
        v6 = -1;
        CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&KeyValue);
        Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                      this: &v5->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                                      i: Inorder);
        if ( Inorder == 0xFFFF )
          break;
        v2 = v5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101236E0
// Name: public: virtual void CMapEntity::Debug(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::Debug(CMapEntity *this)
{
  CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101236F0
// Name: public: virtual void CMapEntity::ReplaceTargetname(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::ReplaceTargetname(CMapEntity *this, char *szOldName, const char *szNewName)
{
  CMapEntity *v3; // esi
  int Inorder; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  unsigned __int16 v11; // ax
  CEntityConnection *v12; // ebx
  char *m_szTargetEntity; // edi
  int v14; // esi
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // esi
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  char *m_szParam; // edi
  int v27; // esi
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  char szTempName[1024]; // [esp+4h] [ebp-668h] BYREF
  MDkeyvalue KeyValue; // [esp+404h] [ebp-268h] BYREF
  int nConnCount; // [esp+654h] [ebp-18h]
  int i; // [esp+658h] [ebp-14h]
  CMapEntity *v37; // [esp+65Ch] [ebp-10h]
  int v38; // [esp+668h] [ebp-4h]

  v3 = this;
  v37 = this;
  if ( _V_strcmp(s1: szOldName, s2: szNewName) != 0 )
  {
    Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v3->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
    if ( Inorder != 0xFFFF )
    {
      do
      {
        KeyValue = v3->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.elem;
        v38 = 0;
        v5 = -1;
        strchr(string: KeyValue.szValue, chr: 0x2Au);
        if ( v6 != 0 )
          v5 = v6 - (_DWORD)KeyValue.szValue;
        strchr(string: szOldName, chr: 0x2Au);
        if ( v7 != 0 )
        {
          v8 = v7 - (_DWORD)szOldName;
          if ( v5 == -1 || v5 >= v8 )
            v5 = v8;
        }
        if ( v5 == -1 )
        {
          v9 = _V_stricmp(s1: KeyValue.szValue, s2: szOldName);
        }
        else
        {
          if ( v5 <= 0 )
            goto LABEL_14;
          v9 = V_strncasecmp(s1: KeyValue.szValue, s2: szOldName, n: v5);
        }
        if ( v9 == 0 )
        {
LABEL_14:
          strcpy(szTempName, szNewName);
          strchr(string: KeyValue.szValue, chr: 0x2Au);
          if ( v10 != 0 )
            *(_WORD *)&szTempName[v10 - (_DWORD)KeyValue.szValue] = 42;
          v37->SetKeyValue(this: &v37->CEditGameClass, a2: KeyValue.szKey, a3: szTempName);
        }
        v38 = -1;
        CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&KeyValue);
        v11 = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &v37->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                i: Inorder);
        v3 = v37;
        LOWORD(Inorder) = v11;
      }
      while ( v11 != 0xFFFF );
    }
    nConnCount = v3->m_Connections.m_Size;
    i = 0;
    if ( nConnCount > 0 )
    {
      while ( 1 )
      {
        v12 = v3->m_Connections.m_Memory.m_pMemory[i];
        m_szTargetEntity = v12->m_szTargetEntity;
        v14 = -1;
        strchr(string: v12->m_szTargetEntity, chr: 0x2Au);
        if ( v15 != 0 )
          v14 = v15 - (_DWORD)m_szTargetEntity;
        strchr(string: szOldName, chr: 0x2Au);
        if ( v16 != 0 )
        {
          v17 = v16 - (_DWORD)szOldName;
          if ( v14 == -1 || v14 >= v17 )
            v14 = v17;
        }
        if ( v14 == -1 )
          break;
        if ( v14 > 0 )
        {
          v18 = V_strncasecmp(s1: v12->m_szTargetEntity, s2: szOldName, n: v14);
          goto LABEL_29;
        }
LABEL_30:
        strcpy(szTempName, szNewName);
        strchr(string: v12->m_szTargetEntity, chr: 0x2Au);
        if ( v19 != 0 )
          *(_WORD *)&szTempName[v19 - (_DWORD)m_szTargetEntity] = 42;
        CEntityConnection::SetTargetName(this: v12, pszName: szTempName);
LABEL_33:
        v20 = -1;
        strchr(string: v12->m_szSourceEntity, chr: 0x2Au);
        if ( v21 != 0 )
          v20 = v21 - (_DWORD)v12;
        strchr(string: szOldName, chr: 0x2Au);
        if ( v22 != 0 )
        {
          v23 = v22 - (_DWORD)szOldName;
          if ( v20 == -1 || v20 >= v23 )
            v20 = v23;
        }
        if ( v20 == -1 )
        {
          v24 = _V_stricmp(s1: v12->m_szSourceEntity, s2: szOldName);
LABEL_43:
          if ( v24 != 0 )
            goto LABEL_47;
          goto LABEL_44;
        }
        if ( v20 > 0 )
        {
          v24 = V_strncasecmp(s1: v12->m_szSourceEntity, s2: szOldName, n: v20);
          goto LABEL_43;
        }
LABEL_44:
        strcpy(szTempName, szNewName);
        strchr(string: v12->m_szSourceEntity, chr: 0x2Au);
        if ( v25 != 0 )
          *(_WORD *)&szTempName[v25 - (_DWORD)v12] = 42;
        CEntityConnection::SetSourceName(this: v12, pszName: szTempName);
LABEL_47:
        m_szParam = v12->m_szParam;
        v27 = -1;
        strchr(string: v12->m_szParam, chr: 0x2Au);
        if ( v28 != 0 )
          v27 = v28 - (_DWORD)m_szParam;
        strchr(string: szOldName, chr: 0x2Au);
        if ( v29 != 0 )
        {
          v30 = v29 - (_DWORD)szOldName;
          if ( v27 == -1 || v27 >= v30 )
            v27 = v30;
        }
        if ( v27 == -1 )
        {
          v31 = _V_stricmp(s1: m_szParam, s2: szOldName);
        }
        else
        {
          if ( v27 <= 0 )
            goto LABEL_58;
          v31 = V_strncasecmp(s1: m_szParam, s2: szOldName, n: v27);
        }
        if ( v31 == 0 )
        {
LABEL_58:
          strcpy(szTempName, szNewName);
          strchr(string: m_szParam, chr: 0x2Au);
          if ( v32 != 0 )
            *(_WORD *)&szTempName[v32 - (_DWORD)m_szParam] = 42;
          lstrcpynA(lpString1: m_szParam, lpString2: szTempName, iMaxLength: 256);
        }
        v3 = v37;
        if ( ++i >= nConnCount )
          goto LABEL_62;
      }
      v18 = _V_stricmp(s1: v12->m_szTargetEntity, s2: szOldName);
LABEL_29:
      if ( v18 != 0 )
        goto LABEL_33;
      goto LABEL_30;
    }
LABEL_62:
    CMapClass::ReplaceTargetname(this: v3, szOldName, szNewName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123AC0
// Name: public: virtual void CMapEntity::OnClone(class CMapClass __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::OnClone(
        CMapEntity *this,
        CMapClass *pClone,
        CMapWorld *pWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  char *v6; // edi
  const char *v7; // ebx
  const char *Value; // eax
  const char *v9; // eax
  GDclass *m_pClass; // eax
  const char *m_szName; // edi
  int v12; // ebx
  const char *v13; // eax
  int v14; // edi
  const char *v15; // eax

  CMapClass::OnClone(this, pNewObj: pClone, pWorld, OriginalList, NewList);
  if ( OriginalList->m_Size == 1
    && (_V_stricmp(s1: this->m_szClass, s2: "path_corner") == 0
     || _V_stricmp(s1: this->m_szClass, s2: "path_track") == 0
     || _V_stricmp(s1: this->m_szClass, s2: "info_blob_spit_path") == 0) )
  {
    v6 = (char *)__RTDynamicCast(
                   inptr: pClone,
                   VfDelta: 0,
                   SrcType: &CMapClass `RTTI Type Descriptor',
                   TargetType: &CMapEntity `RTTI Type Descriptor',
                   isReference: 0);
    if ( v6 == nullptr )
      return;
    v7 = "NextPath";
    if ( _V_stricmp(s1: this->m_szClass, s2: "info_blob_spit_path") != 0 )
      v7 = "target";
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: v7, piIndex: nullptr);
    if ( Value != nullptr )
      (*(void (__thiscall **)(char *, const char *, const char *))(*((_DWORD *)v6 + 54) + 4))(
        a1: v6 + 216,
        a2: v7,
        a3: Value);
    v9 = WCKeyValuesT<WCKVBase_Dict>::GetValue(
           this: (WCKeyValuesT<WCKVBase_Dict> *)(v6 + 220),
           pszKey: "targetname",
           piIndex: nullptr);
    this->SetKeyValue(this: &this->CEditGameClass, a2: v7, a3: v9);
  }
  m_pClass = this->m_pClass;
  if ( m_pClass != nullptr )
  {
    m_szName = m_pClass->m_szName;
    if ( V_strncasecmp(s1: m_pClass->m_szName, s2: "info_node", n: 9) == 0
      && _V_stricmp(s1: m_szName, s2: "info_node_link") != 0 )
    {
      v12 = 0;
      v13 = WCKeyValuesT<WCKVBase_Dict>::GetValue(
              this: (WCKeyValuesT<WCKVBase_Dict> *)&pClone[1].m_nObjectID,
              pszKey: "nodeid",
              piIndex: nullptr);
      if ( v13 != nullptr )
        v12 = atoi(nptr: v13);
      v14 = 0;
      v15 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "nodeid", piIndex: nullptr);
      if ( v15 != nullptr )
        v14 = atoi(nptr: v15);
      ReplaceNodeIDRefs(newList: NewList, nOldNodeID: v14, nNewNodeID: v12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123C50
// Name: public: virtual void CMapEntity::OnPaste(class CMapClass __near *,class CMapWorld __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::OnPaste(
        CMapEntity *this,
        CMapClass *pCopy,
        CMapWorld *pSourceWorld,
        CMapWorld *pDestWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  GDclass *m_pClass; // eax
  const char *m_szName; // edi
  int v9; // ebx
  const char *Value; // eax
  int v11; // edi
  const char *v12; // eax

  m_pClass = this->m_pClass;
  if ( m_pClass != nullptr )
  {
    m_szName = m_pClass->m_szName;
    if ( V_strncasecmp(s1: m_pClass->m_szName, s2: "info_node", n: 9) == 0
      && _V_stricmp(s1: m_szName, s2: "info_node_link") != 0 )
    {
      v9 = 0;
      Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                this: (WCKeyValuesT<WCKVBase_Dict> *)&pCopy[1].m_nObjectID,
                pszKey: "nodeid",
                piIndex: nullptr);
      if ( Value != nullptr )
        v9 = atoi(nptr: Value);
      v11 = 0;
      v12 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "nodeid", piIndex: nullptr);
      if ( v12 != nullptr )
        v11 = atoi(nptr: v12);
      ReplaceNodeIDRefs(newList: NewList, nOldNodeID: v11, nNewNodeID: v9);
    }
  }
  CMapClass::OnPaste(this, pCopy, pSourceWorld, pDestWorld, OriginalList, NewList);
}

//------------------------------------------------------------------------------
// Address: 0x10123D10
// Name: public: virtual void CMapEntity::RenderLogical(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::RenderLogical(CMapEntity *this, CRender2D *pRender)
{
  void (__thiscall *GetRenderLogicalBox)(CMapClass *, Vector2D *, Vector2D *); // eax
  color32_s (__thiscall *GetRenderColor)(CMapEntity *, CRender2D *); // edx
  int v6; // edi
  float x; // ebx
  signed int v8; // edi
  int v9; // eax
  int v10; // ecx
  CMapSprite *v11; // eax
  CMapView *m_pView; // ecx
  CMapView *v13; // ecx
  wchar_t *Value; // eax
  wchar_t *v15; // ebx
  char v16; // [esp+10h] [ebp-90h] BYREF
  float fRadius; // [esp+14h] [ebp-8Ch]
  char v18; // [esp+18h] [ebp-88h] BYREF
  float v19; // [esp+1Ch] [ebp-84h]
  Vector v20; // [esp+20h] [ebp-80h] BYREF
  Vector2D pt; // [esp+2Ch] [ebp-74h] BYREF
  Vector vMaxs; // [esp+34h] [ebp-6Ch] BYREF
  CMapClass *pMapClass; // [esp+40h] [ebp-60h] BYREF
  Vector2D vecMins; // [esp+44h] [ebp-5Ch]
  Vector2D vecInnerMaxs; // [esp+4Ch] [ebp-54h] BYREF
  Vector2D vecInnerMins; // [esp+54h] [ebp-4Ch]
  color32_s rgbEdgeColor; // [esp+5Ch] [ebp-44h]
  Vector v28; // [esp+60h] [ebp-40h] BYREF
  Vector2D vecBoxMins; // [esp+6Ch] [ebp-34h] BYREF
  Vector vStart; // [esp+74h] [ebp-2Ch] BYREF
  color32_s rgbColor; // [esp+80h] [ebp-20h]
  float v32; // [esp+84h] [ebp-1Ch]
  Vector2D vecBoxMaxs; // [esp+88h] [ebp-18h] BYREF
  Vector v34; // [esp+90h] [ebp-10h]
  __int64 vMins; // [esp+9Ch] [ebp-4h]
  float v36; // [esp+A8h] [ebp+8h]
  char v37; // [esp+ABh] [ebp+Bh]

  GetRenderLogicalBox = this->GetRenderLogicalBox;
  LODWORD(pt.x) = this;
  ((void (__stdcall *)(float *, float *))GetRenderLogicalBox)(a1: &pt.y, a2: &vecInnerMaxs.y);
  GetRenderColor = this->GetRenderColor;
  vecInnerMins.y = pt.y + 50.0;
  rgbEdgeColor = (color32_s)LODWORD(vMaxs.x);
  vStart.y = vecInnerMins.x;
  vStart.x = vecInnerMaxs.y - 50.0;
  *(float *)&pMapClass = (float)(pt.y + 50.0) + 10.0;
  vecMins.x = vMaxs.x + 10.0;
  vMaxs.y = (float)(vecInnerMaxs.y - 50.0) - 10.0;
  vMaxs.z = vecInnerMins.x - 10.0;
  ((void (__thiscall *)(CMapEntity *, Vector2D *, CRender2D *))GetRenderColor)(a1: this, a2: &vecBoxMins, a3: pRender);
  v6 = BYTE1(vecBoxMins.x);
  LOBYTE(v28.y) = 5 * LOBYTE(vecBoxMins.x) / 8;
  BYTE1(v28.y) = 5 * BYTE1(vecBoxMins.x) / 8;
  BYTE2(v28.y) = 5 * BYTE2(vecBoxMins.x) / 8;
  LOBYTE(vecMins.y) = 3 * LOBYTE(vecBoxMins.x) / 8;
  BYTE1(vecMins.y) = 3 * BYTE1(vecBoxMins.x) / 8;
  BYTE2(vecMins.y) = 3 * BYTE2(vecBoxMins.x) / 8;
  rgbColor.r = 2 * LOBYTE(vecBoxMins.x) / 8;
  rgbColor.g = 2 * BYTE1(vecBoxMins.x) / 8;
  rgbColor.b = 2 * BYTE2(vecBoxMins.x) / 8;
  CRender::SetDrawColor(
    this: pRender,
    r: 7 * LOBYTE(vecBoxMins.x) / 8,
    g: 7 * BYTE1(vecBoxMins.x) / 8,
    b: 7 * BYTE2(vecBoxMins.x) / 8);
  v20.x = vStart.x;
  v20.y = vStart.y;
  vecBoxMaxs.x = vecInnerMins.y;
  v20.z = 0.0;
  LODWORD(vecBoxMaxs.y) = rgbEdgeColor;
  v34.x = 0.0;
  CRender2D::DrawRectangle(this: pRender, vMins: (const Vector *)&vecBoxMaxs, vMaxs: &v20, bFill: true, extent: 0);
  CRender::SetDrawColor(this: pRender, r: LOBYTE(v28.y), g: BYTE1(v28.y), b: BYTE2(v28.y));
  vecBoxMaxs.x = vStart.x;
  vecBoxMaxs.y = vMaxs.z;
  v34.x = 0.0;
  LODWORD(v28.x) = pMapClass;
  LODWORD(v28.y) = rgbEdgeColor;
  v28.z = 0.0;
  CRender2D::DrawRectangle(this: pRender, vMins: &v28, vMaxs: (const Vector *)&vecBoxMaxs, bFill: true, extent: 0);
  CRender::SetDrawColor(this: pRender, r: LOBYTE(vecMins.y), g: BYTE1(vecMins.y), b: BYTE2(vecMins.y));
  vecBoxMaxs.x = vStart.x;
  vecBoxMaxs.y = vStart.y;
  v28.x = vecInnerMins.y;
  v34.x = 0.0;
  LODWORD(v28.y) = rgbEdgeColor;
  v28.z = 0.0;
  CRender2D::DrawRectangle(this: pRender, vMins: &v28, vMaxs: (const Vector *)&vecBoxMaxs, bFill: false, extent: 0);
  vecBoxMaxs.x = vStart.x;
  vecBoxMaxs.y = vStart.y;
  v28.x = vecInnerMins.y;
  v34.x = 0.0;
  LODWORD(v28.y) = rgbEdgeColor;
  v28.z = 0.0;
  CRender::DrawLine(this: pRender, a2: v6, a3: (int)pRender, vStart: &v28, vEnd: (const Vector *)&vecBoxMaxs);
  vecBoxMaxs.x = vStart.x;
  LODWORD(vecBoxMaxs.y) = rgbEdgeColor;
  v28.x = vecInnerMins.y;
  v34.x = 0.0;
  v28.y = vStart.y;
  v28.z = 0.0;
  CRender::DrawLine(this: pRender, a2: v6, a3: (int)pRender, vStart: &v28, vEnd: (const Vector *)&vecBoxMaxs);
  CRender::SetDrawColor(this: pRender, r: rgbColor.r, g: rgbColor.g, b: rgbColor.b);
  vecBoxMaxs = *(Vector2D *)&vMaxs.y;
  LODWORD(vStart.z) = pMapClass;
  v34.x = 0.0;
  rgbColor = (color32_s)LODWORD(vecMins.x);
  v32 = 0.0;
  CRender2D::DrawRectangle(
    this: pRender,
    vMins: (Vector *)&vStart.z,
    vMaxs: (const Vector *)&vecBoxMaxs,
    bFill: true,
    extent: 0);
  x = pt.x;
  v8 = 0;
  v37 = 0;
  if ( *(int *)(LODWORD(pt.x) + 136) <= 0 )
    goto LABEL_18;
  do
  {
    v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(x) + 124)
                               + 4 * (v8 >> ((unsigned __int64)*(int *)(LODWORD(x) + 132) >> 27)))
                   + 12 * (v8 & ((32 * *(_DWORD *)(LODWORD(x) + 132)) >> 5))
                   + 8);
    if ( v9 != 0 )
    {
      v32 = *(float *)(*(_DWORD *)(*(_DWORD *)(LODWORD(x) + 124)
                                 + 4 * (v8 >> ((unsigned __int64)*(int *)(LODWORD(x) + 132) >> 27)))
                     + 12 * (v8 & ((32 * *(_DWORD *)(LODWORD(x) + 132)) >> 5))
                     + 8);
      vStart.z = *(float *)(v9 + 32);
      v10 = *(_DWORD *)(v9 + 32);
      if ( v10 != 0 )
        *(_DWORD *)(v10 + 4) = &vStart.z;
      rgbColor = 0;
      *(_DWORD *)(v9 + 32) = &vStart.z;
    }
    pt.x = v32;
    LODWORD(vMins) = -1;
    if ( v32 != 0.0 )
    {
      if ( rgbColor != 0 )
      {
        **(float **)&rgbColor = vStart.z;
        if ( LODWORD(vStart.z) != 0 )
          *(color32_s *)(LODWORD(vStart.z) + 4) = rgbColor;
      }
      else if ( *(Vector **)(LODWORD(v32) + 32) == (Vector *)&vStart.z )
      {
        *(float *)(LODWORD(v32) + 32) = vStart.z;
        if ( LODWORD(vStart.z) != 0 )
          *(_DWORD *)(LODWORD(vStart.z) + 4) = 0;
      }
      rgbColor = 0;
      vStart.z = 0.0;
      v32 = 0.0;
    }
    v11 = (CMapSprite *)__RTDynamicCast(
                          inptr: (void *)LODWORD(pt.x),
                          VfDelta: 0,
                          SrcType: &CMapClass `RTTI Type Descriptor',
                          TargetType: &CMapSprite `RTTI Type Descriptor',
                          isReference: 0);
    if ( v11 != nullptr )
    {
      CMapSprite::RenderLogicalAt(
        this: v11,
        pRender,
        vecMins: (const Vector2D *)&pMapClass,
        vecMaxs: (const Vector2D *)&vMaxs.y);
      v37 = 1;
    }
    ++v8;
  }
  while ( v8 < *(_DWORD *)(LODWORD(x) + 136) );
  if ( v37 == 0 )
  {
LABEL_18:
    CRender::SetDrawColor(this: pRender, r: LOBYTE(vecBoxMins.x), g: BYTE1(vecBoxMins.x), b: BYTE2(vecBoxMins.x));
    vecBoxMaxs = *(Vector2D *)&vMaxs.y;
    LODWORD(vStart.z) = pMapClass;
    v34.x = 0.0;
    rgbColor = (color32_s)LODWORD(vecMins.x);
    v32 = 0.0;
    CRender2D::DrawRectangle(
      this: pRender,
      vMins: (Vector *)&vStart.z,
      vMaxs: (const Vector *)&vecBoxMaxs,
      bFill: true,
      extent: 0);
    CRender::SetDrawColor(this: pRender, r: LOBYTE(vecMins.y), g: BYTE1(vecMins.y), b: BYTE2(vecMins.y));
    vecBoxMaxs = *(Vector2D *)&vMaxs.y;
    LODWORD(vStart.z) = pMapClass;
    v34.x = 0.0;
    rgbColor = (color32_s)LODWORD(vecMins.x);
    v32 = 0.0;
    CRender2D::DrawRectangle(
      this: pRender,
      vMins: (Vector *)&vStart.z,
      vMaxs: (const Vector *)&vecBoxMaxs,
      bFill: false,
      extent: 0);
  }
  CRender::SetDrawColor(this: pRender, r: LOBYTE(vecBoxMins.x), g: BYTE1(vecBoxMins.x), b: BYTE2(vecBoxMins.x));
  v36 = (float)(vecInnerMins.x + vMaxs.x) * 0.5;
  vecBoxMaxs.y = v36;
  vecBoxMaxs.x = pt.y + 10.0;
  v34.x = 0.0;
  CRender2D::DrawCircle(this: pRender, a2: LODWORD(x), a3: v8, vCenter: (const Vector *)&vecBoxMaxs, fRadius: 10.0);
  vecBoxMaxs.x = pt.y + 20.0;
  vecBoxMaxs.y = v36;
  v34.x = 0.0;
  CRender2D::MoveTo(this: pRender, vPoint: (const Vector *)&vecBoxMaxs);
  vecBoxMaxs.x = vecInnerMins.y;
  vecBoxMaxs.y = v36;
  v34.x = 0.0;
  CRender2D::DrawLineTo(this: pRender, vPoint: (const Vector *)&vecBoxMaxs);
  vecBoxMaxs.x = vStart.x;
  vecBoxMaxs.y = v36;
  v34.x = 0.0;
  CRender2D::MoveTo(this: pRender, vPoint: (const Vector *)&vecBoxMaxs);
  vecBoxMaxs.x = vecInnerMaxs.y - 25.0;
  vecBoxMaxs.y = v36;
  v34.x = 0.0;
  CRender2D::DrawLineTo(this: pRender, vPoint: (const Vector *)&vecBoxMaxs);
  vecBoxMaxs.x = vecInnerMaxs.y - 25.0;
  vecBoxMaxs.y = v36 + 10.0;
  v34.x = 0.0;
  CRender2D::DrawLineTo(this: pRender, vPoint: (const Vector *)&vecBoxMaxs);
  vecBoxMaxs.x = vecInnerMaxs.y;
  vecBoxMaxs.y = v36;
  v34.x = 0.0;
  CRender2D::DrawLineTo(this: pRender, vPoint: (const Vector *)&vecBoxMaxs);
  vecBoxMaxs.x = vecInnerMaxs.y - 25.0;
  vecBoxMaxs.y = v36 - 10.0;
  v34.x = 0.0;
  CRender2D::DrawLineTo(this: pRender, vPoint: (const Vector *)&vecBoxMaxs);
  vecBoxMaxs.x = vecInnerMaxs.y - 25.0;
  vecBoxMaxs.y = v36;
  v34.x = 0.0;
  CRender2D::DrawLineTo(this: pRender, vPoint: (const Vector *)&vecBoxMaxs);
  m_pView = pRender->m_pView;
  vecBoxMaxs.x = vecInnerMins.y;
  LODWORD(vecBoxMaxs.y) = rgbEdgeColor;
  v34.x = 0.0;
  m_pView->WorldToClient(this: m_pView, a2: (Vector2D *)&v18, a3: (const Vector *)&vecBoxMaxs);
  v13 = pRender->m_pView;
  vecBoxMaxs.x = vStart.x;
  vecBoxMaxs.y = vStart.y;
  v34.x = 0.0;
  v13->WorldToClient(this: v13, a2: (Vector2D *)&v16, a3: (const Vector *)&vecBoxMaxs);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v19 - fRadius) & _mask__AbsFloat_) >= 32.0 )
  {
    CRender::SetTextColor(
      this: pRender,
      r: LOBYTE(vecBoxMins.x),
      g: BYTE1(vecBoxMins.x),
      b: BYTE2(vecBoxMins.x),
      a: 0xFFu);
    Value = (wchar_t *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                         this: (WCKeyValuesT<WCKVBase_Dict> *)(LODWORD(x) + 220),
                         pszKey: "targetname",
                         piIndex: nullptr);
    if ( Value != nullptr )
    {
      vStart.x = (float)(vecInnerMaxs.y + pt.y) * 0.5;
      vStart.y = vecInnerMins.x;
      CRender::DrawTextA(
        this: pRender,
        text: Value,
        vPos: (const Vector2D *)&vStart,
        nOffsetX: 0,
        nOffsetY: -1,
        nFlags: 72);
    }
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v19 - fRadius) & _mask__AbsFloat_) >= 50.0 )
    {
      v15 = (wchar_t *)(LODWORD(x) + 252);
      if ( v15 != nullptr )
      {
        vStart.x = (float)(vecInnerMaxs.y + pt.y) * 0.5;
        vStart.y = vMaxs.x;
        CRender::DrawTextA(
          this: pRender,
          text: v15,
          vPos: (const Vector2D *)&vStart,
          nOffsetX: 0,
          nOffsetY: 1,
          nFlags: 68);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124570
// Name: private: void CMapEntity::RemoveHelpers(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::RemoveHelpers(CMapEntity *this, bool bRemoveSolids)
{
  int v2; // esi
  CUtlReferenceVector<CMapClass> *p_m_Children; // edi

  v2 = this->m_Children.m_Size - 1;
  if ( v2 >= 0 )
  {
    p_m_Children = &this->m_Children;
    do
    {
      if ( bRemoveSolids
        || __RTDynamicCast(
             inptr: p_m_Children->m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&p_m_Children->m_Memory + 2) >> 27)][v2 & ((32 * *((_DWORD *)&p_m_Children->m_Memory + 2)) >> 5)].m_pObject,
             VfDelta: 0,
             SrcType: &CMapClass `RTTI Type Descriptor',
             TargetType: &CMapSolid `RTTI Type Descriptor',
             isReference: 0) == nullptr )
      {
        CUtlReferenceVector<CMapClass>::FastRemove(this: p_m_Children, elem: v2);
      }
      --v2;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101245E0
// Name: private: void CMapEntity::OnKeyValueChanged(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::OnKeyValueChanged(
        CMapEntity *this,
        const char *pszKey,
        const char *pszOldValue,
        char *pszValue)
{
  int i; // edi
  CMapClass *m_pObject; // ecx
  CMapWorld *WorldObject; // eax
  CMapEntity *EntityByName; // eax
  CMapEntity *updated; // eax
  CMapEntity *v10; // ecx
  int v11; // edx
  CMapEntity_vtbl *v12; // edx
  void (__thiscall *SignalChanged)(CMapAtom *); // eax

  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
      m_pObject->OnParentKeyChanged(this: m_pObject, a2: pszKey, a3: pszValue);
  }
  if ( _V_stricmp(s1: pszKey, s2: "parentname") != 0 )
  {
    if ( _V_stricmp(s1: pszKey, s2: "model") != 0 )
    {
      if ( _V_stricmp(s1: pszKey, s2: "targetname") == 0 && _V_stricmp(s1: pszOldValue, s2: pszValue) != 0 )
        CMapClass::UpdateAllDependencies(pObject: this);
    }
    else if ( _V_stricmp(s1: pszOldValue, s2: pszValue) != 0 )
    {
      CMapEntity::RemoveHelpers(this, bRemoveSolids: (this->flags & 1) == 1);
      CMapEntity::AddHelpersForClass(this, pClass: this->m_pClass, bLoading: false);
      this->SignalChanged(this);
      return;
    }
    goto LABEL_19;
  }
  WorldObject = CMapClass::GetWorldObject(pStart: this);
  if ( WorldObject == nullptr )
  {
LABEL_19:
    this->SignalChanged(this);
    return;
  }
  EntityByName = CMapWorld::FindEntityByName(
                   this: WorldObject,
                   pszName: pszValue,
                   bVisiblesOnly: false,
                   bSearchInstanceParms: false);
  updated = (CMapEntity *)CMapClass::UpdateDependency(
                            this,
                            pOldAttached: this->m_pMoveParent,
                            pNewAttached: EntityByName);
  v10 = updated;
  v11 = 0;
  while ( 1 )
  {
    if ( v10 == nullptr )
    {
LABEL_11:
      v12 = this->CMapClass::CMapPoint::CMapAtom::__vftable;
      this->m_pMoveParent = updated;
      v12->SignalChanged(this);
      return;
    }
    if ( v10 == this )
      break;
    v10 = v10->m_pMoveParent;
    if ( ++v11 >= 300 )
      goto LABEL_11;
  }
  SignalChanged = this->SignalChanged;
  this->m_pMoveParent = nullptr;
  SignalChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x10124760
// Name: FindKeyValue
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindKeyValue(CMapEntity *pEntity, MDkeyvalue *pKV)
{
  const char *Value; // eax
  CUtlReference<CMapClass> *m_pHead; // eax
  CUtlReference<CMapClass> src; // [esp+Ch] [ebp-18h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &pEntity->m_KeyValues, pszKey: pKV->szKey, piIndex: nullptr);
  if ( Value != nullptr && _V_stricmp(s1: Value, s2: pKV->szValue) == 0 )
  {
    src.m_pPrev = nullptr;
    src.m_pNext = nullptr;
    src.m_pObject = pEntity;
    if ( pEntity != nullptr )
    {
      m_pHead = pEntity->CMapClass::m_References.m_pHead;
      src.m_pNext = m_pHead;
      if ( m_pHead != nullptr )
        m_pHead->m_pPrev = &src;
      src.m_pPrev = nullptr;
      pEntity->CMapClass::m_References.m_pHead = &src;
    }
    v6 = 0;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
      this: &FoundEntities,
      elem: FoundEntities.m_Size,
      &src);
    v6 = -1;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = src.m_pPrev;
      }
      else if ( src.m_pObject->m_References.m_pHead == &src )
      {
        src.m_pObject->m_References.m_pHead = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
      memset(&src, 0, sizeof(src));
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10124850
// Name: public: virtual void CMapEntity::SetClass(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::SetClass(CMapEntity *this, const char *pszClass, bool bLoading)
{
  char *v4; // esi
  CUtlReference<CMapClass> *m_pHead; // eax
  CUtlReference<CMapClass> *v6; // eax
  const char *v7; // ebx
  const char *Value; // eax
  CMapDoc *v9; // ebx

  if ( pszClass != nullptr )
  {
    if ( this->CMapClass::m_References.m_pHead != nullptr
      && _V_stricmp(s1: pszClass, s2: (const char *)&this->___u2) == 0 )
    {
      return;
    }
  }
  else if ( this->CMapClass::m_References.m_pHead != nullptr )
  {
    return;
  }
  CEditGameClass::SetClass((CEditGameClass *)this, pszClass, bLoading);
  v4 = (char *)this - 216;
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 54) + 100))(a1: (char *)this - 216);
  m_pHead = this->CMapClass::m_References.m_pHead;
  if ( m_pHead != nullptr )
  {
    if ( BYTE1(m_pHead->m_pObject) != 0 )
      *((_WORD *)v4 + 184) &= ~1u;
    else
      *((_WORD *)v4 + 184) |= 1u;
    CEditGameClass::GetDefaultKeys((CEditGameClass *)this);
    v6 = this->CMapClass::m_References.m_pHead;
    if ( v6 != nullptr )
    {
      v7 = (char *)&v6[1].m_pPrev + 3;
      if ( V_strncasecmp(s1: (const char *)&v6[1].m_pPrev + 3, s2: "info_node", n: 9) == 0
        && _V_stricmp(s1: v7, s2: "info_node_link") != 0 )
      {
        Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                  this: (WCKeyValuesT<WCKVBase_Dict> *)&this->m_nObjectID,
                  pszKey: "nodeid",
                  piIndex: nullptr);
        if ( Value == nullptr || atoi(nptr: Value) == 0 )
          CMapEntity::AssignNodeID(this: (CMapEntity *)((char *)this - 216));
      }
    }
  }
  else if ( CMapEntity::HasSolidChildren(this: (CMapEntity *)((char *)this - 216)) != 0 )
  {
    *((_WORD *)v4 + 184) &= ~1u;
  }
  else
  {
    *((_WORD *)v4 + 184) |= 1u;
  }
  CMapEntity::RemoveHelpers(this: (CMapEntity *)((char *)this - 216), bRemoveSolids: (v4[368] & 1) == 1);
  CMapEntity::AddHelpersForClass(this: (CMapEntity *)((char *)this - 216), pClass: *((GDclass **)v4 + 62), bLoading);
  v9 = CMapDoc::m_pMapDoc;
  if ( !CMapDoc::m_pMapDoc->m_bLoading )
  {
    CMapDoc::RemoveFromAutoVisGroups(this: CMapDoc::m_pMapDoc, pObject: (CMapEntity *)((char *)this - 216));
    CMapDoc::AddToAutoVisGroup(this: v9, pObject: (CMapEntity *)((char *)this - 216));
  }
  if ( strcmp(pszClass, "infodecal") == 0
    && WCKeyValuesT<WCKVBase_Dict>::GetValue(
         this: (WCKeyValuesT<WCKVBase_Dict> *)&this->m_nObjectID,
         pszKey: "texture",
         piIndex: nullptr) == nullptr )
  {
    ((void (__thiscall *)(CMapEntity *, const char *, const unsigned __int8 *))this->IsSelected)(
      a1: this,
      a2: "texture",
      a3: "clip");
  }
  CMapEntity::CalculateTypeFlags(this: (CMapEntity *)((char *)this - 216));
  (*(void (__thiscall **)(char *))(*(_DWORD *)v4 + 72))(a1: (char *)this - 216);
}

//------------------------------------------------------------------------------
// Address: 0x10124A20
// Name: public: virtual void CMapEntity::DeleteKeyValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::DeleteKeyValue(CMapEntity *this, const char *pszKey)
{
  char *Value; // eax
  char *v4; // edx
  char v5; // cl
  CMapEntity *v6; // esi
  char szOldValue[512]; // [esp+Ch] [ebp-200h] BYREF

  Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                    this: (WCKeyValuesT<WCKVBase_Dict> *)&this->m_nObjectID,
                    pszKey,
                    piIndex: nullptr);
  if ( Value != nullptr )
  {
    v4 = (char *)(szOldValue - Value);
    do
    {
      v5 = *Value;
      Value[(_DWORD)v4] = *Value;
      ++Value;
    }
    while ( v5 != 0 );
  }
  else
  {
    szOldValue[0] = 0;
  }
  WCKeyValuesT<WCKVBase_Dict>::RemoveKey(this: (WCKeyValuesT<WCKVBase_Dict> *)&this->m_nObjectID, pszKey);
  v6 = (CMapEntity *)((char *)this - 216);
  CMapEntity::OnKeyValueChanged(this: v6, pszKey, pszOldValue: szOldValue, pszValue: (char *)&var);
  CMapEntity::CalculateTypeFlags(this: v6);
  v6->SignalChanged(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10124AA0
// Name: public: virtual void CMapEntity::SetKeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::SetKeyValue(CMapEntity *this, const char *pszKey, char *pszValue)
{
  char *Value; // eax
  char *v5; // edx
  char v6; // cl
  char szOldValue[512]; // [esp+Ch] [ebp-200h] BYREF

  Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                    this: (WCKeyValuesT<WCKVBase_Dict> *)&this->m_nObjectID,
                    pszKey,
                    piIndex: nullptr);
  if ( Value != nullptr )
  {
    v5 = (char *)(szOldValue - Value);
    do
    {
      v6 = *Value;
      Value[(_DWORD)v5] = *Value;
      ++Value;
    }
    while ( v6 != 0 );
  }
  else
  {
    szOldValue[0] = 0;
  }
  WCKeyValuesT<WCKVBase_Dict>::SetValue(this: (WCKeyValuesT<WCKVBase_Dict> *)&this->m_nObjectID, pszKey, pszValue);
  CMapEntity::OnKeyValueChanged(this: (CMapEntity *)((char *)this - 216), pszKey, pszOldValue: szOldValue, pszValue);
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 54) + 72))(a1: (char *)this - 216);
}

//------------------------------------------------------------------------------
// Address: 0x10124B20
// Name: public: virtual void CMapEntity::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntity::Render2D(CMapEntity *this, CRender2D *pRender)
{
  CMapView *m_pView; // eax
  const char *v4; // esi
  CRender2D *v5; // esi
  wchar_t *Value; // eax
  CMapWorld *WorldObject; // esi
  int v8; // eax
  char v9; // cl
  const char *v10; // eax
  int v11; // edx
  char v12; // cl
  int i; // esi
  int v14; // eax
  int v15; // ecx
  float z; // edx
  MDkeyvalue kv; // [esp+Ch] [ebp-2C8h] BYREF
  Vector2D pt2; // [esp+25Ch] [ebp-78h] BYREF
  Vector2D pt; // [esp+264h] [ebp-70h] BYREF
  Vector vecMaxs; // [esp+26Ch] [ebp-68h] BYREF
  Vector vCenter2; // [esp+278h] [ebp-5Ch] BYREF
  Vector vecMins; // [esp+284h] [ebp-50h] BYREF
  Vector vecForward; // [esp+290h] [ebp-44h] BYREF
  QAngle vecAngles; // [esp+29Ch] [ebp-38h] BYREF
  int v25; // [esp+2A8h] [ebp-2Ch]
  int v26; // [esp+2ACh] [ebp-28h]
  color32_s rgbColor; // [esp+2B0h] [ebp-24h] BYREF
  const char *pszTarget; // [esp+2B8h] [ebp-1Ch]
  Vector vecOrigin; // [esp+2BCh] [ebp-18h] BYREF
  int v30; // [esp+2D0h] [ebp-4h]

  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: (int)pRender);
  m_pView = pRender->m_pView;
  if ( m_pView != nullptr )
    pszTarget = (const char *)&m_pView[-4].m_bActive;
  else
    pszTarget = nullptr;
  CMapClass::GetRender2DBox(this, mins: &vecMins, maxs: &vecMaxs);
  if ( pRender->m_bInstanceRendering )
  {
    TransformAABB(
      transform: (const matrix3x4_t *)&pRender->m_CurrentInstanceState.m_InstanceMatrix,
      vecMinsIn: &vecMins,
      vecMaxsIn: &vecMaxs,
      vecMinsOut: &vecOrigin,
      vecMaxsOut: &vecForward);
    vecMins = vecOrigin;
    vecMaxs = vecForward;
  }
  v4 = pszTarget;
  (*(void (__thiscall **)(const char *, Vector2D *, Vector *))(*((_DWORD *)pszTarget + 31) + 40))(
    a1: pszTarget + 124,
    a2: &pt,
    a3: &vecMins);
  (*(void (__thiscall **)(const char *, Vector2D *, Vector *))(*((_DWORD *)v4 + 31) + 40))(
    a1: v4 + 124,
    a2: &pt2,
    a3: &vecMaxs);
  v5 = pRender;
  ((void (__thiscall *)(CMapEntity *, color32_s *, CRender2D *))this->GetRenderColor)(
    a1: this,
    a2: &rgbColor,
    a3: pRender);
  CRender::SetDrawColor(this: pRender, r: rgbColor.r, g: rgbColor.g, b: rgbColor.b);
  if ( CMapEntity::s_bShowEntityNames && *((float *)pszTarget + 56) >= 1.0 )
  {
    CRender::SetTextColor(this: pRender, r: rgbColor.r, g: rgbColor.g, b: rgbColor.b, a: 0xFFu);
    Value = (wchar_t *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                         this: &this->m_KeyValues,
                         pszKey: "targetname",
                         piIndex: nullptr);
    if ( Value != nullptr )
      CRender::DrawTextA(this: pRender, text: Value, x: (int)pt.x, y: (int)(float)(pt.y + 2.0), nFlags: 4);
    if ( this != (CMapEntity *)-252 )
      CRender::DrawTextA(
        this: pRender,
        text: (wchar_t *)this->m_szClass,
        x: (int)pt.x,
        y: (int)(float)(pt2.y - 2.0),
        nFlags: 8);
  }
  if ( CMapEntity::s_bShowEntityConnections )
  {
    pszTarget = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "target", piIndex: nullptr);
    if ( pszTarget != nullptr )
    {
      WorldObject = CMapClass::GetWorldObject(pStart: this);
      kv.szKey[0] = 0;
      kv.szValue[0] = 0;
      v8 = 0;
      do
      {
        v9 = aTargetname[v8];
        kv.szKey[v8++] = v9;
      }
      while ( v9 != 0 );
      v10 = pszTarget;
      v11 = kv.szValue - pszTarget;
      do
      {
        v12 = *v10;
        v10[v11] = *v10;
        ++v10;
      }
      while ( v12 != 0 );
      v30 = 0;
      memset(&vecAngles, 0, sizeof(vecAngles));
      CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
        this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&vecAngles,
        nGrowSize: 0,
        nInitSize: 0);
      v25 = 0;
      v26 = 0;
      LOBYTE(v30) = 4;
      CUtlReferenceVector<CMapClass>::RemoveAll(this: (CUtlReferenceVector<CMapClass> *)&vecAngles);
      CMapClass::EnumChildren(
        this: WorldObject,
        pfn: (int (__cdecl *)(CMapClass *, unsigned int))FindKeyValue,
        dwParam: (unsigned int)&kv,
        Type: CMapEntity::__Type);
      BoundBox::GetBoundsCenter(this: &this->m_Render2DBox, ptdest: &vecForward);
      for ( i = 0; i < v25; ++i )
      {
        v14 = *(_DWORD *)(*(_DWORD *)(LODWORD(vecAngles.x) + 4 * (i >> ((unsigned __int64)SLODWORD(vecAngles.z) >> 27)))
                        + 12 * (i & ((32 * LODWORD(vecAngles.z)) >> 5))
                        + 8);
        if ( v14 != 0 )
        {
          vecOrigin.z = *(float *)(*(_DWORD *)(LODWORD(vecAngles.x)
                                             + 4 * (i >> ((unsigned __int64)SLODWORD(vecAngles.z) >> 27)))
                                 + 12 * (i & ((32 * LODWORD(vecAngles.z)) >> 5))
                                 + 8);
          vecOrigin.x = *(float *)(v14 + 32);
          v15 = *(_DWORD *)(v14 + 32);
          if ( v15 != 0 )
            *(_DWORD *)(v15 + 4) = &vecOrigin;
          vecOrigin.y = 0.0;
          *(_DWORD *)(v14 + 32) = &vecOrigin;
        }
        z = vecOrigin.z;
        LOBYTE(v30) = 4;
        if ( LODWORD(vecOrigin.z) != 0 )
        {
          if ( LODWORD(vecOrigin.y) != 0 )
          {
            *(_DWORD *)LODWORD(vecOrigin.y) = LODWORD(vecOrigin.x);
            if ( LODWORD(vecOrigin.x) != 0 )
              *(float *)(LODWORD(vecOrigin.x) + 4) = vecOrigin.y;
          }
          else if ( *(Vector **)(LODWORD(vecOrigin.z) + 32) == &vecOrigin )
          {
            *(float *)(LODWORD(vecOrigin.z) + 32) = vecOrigin.x;
            if ( LODWORD(vecOrigin.x) != 0 )
              *(_DWORD *)(LODWORD(vecOrigin.x) + 4) = 0;
          }
          memset(&vecOrigin, 0, sizeof(vecOrigin));
        }
        BoundBox::GetBoundsCenter(this: (BoundBox *)(LODWORD(z) + 96), ptdest: &vCenter2);
        CRender::DrawLine(this: pRender, a2: (int)this, a3: i, vStart: &vecForward, vEnd: &vCenter2);
      }
      LOBYTE(v30) = 0;
      CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: (CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)&vecAngles);
      v30 = -1;
      CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&kv);
      v5 = pRender;
    }
  }
  if ( this->GetSelectionState(this) != SELECT_NONE
    && (this == (CMapEntity *)-252 || V_strncasecmp(s1: this->m_szClass, s2: "light_", n: 6) != 0)
    && WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "angles", piIndex: nullptr) != nullptr )
  {
    this->GetOrigin(this, a2: &vecOrigin);
    this->GetAngles(this: &this->CEditGameClass, a2: (QAngle *)&vecAngles.z);
    AngleVectors(angles: (QAngle *)&vecAngles.z, forward: &vecForward);
    CRender::SetDrawColor(this: v5, r: 0xFFu, g: 0xFFu, b: 0);
    vCenter2.y = vecOrigin.y + (float)(vecForward.y * 24.0);
    vCenter2.x = vecOrigin.x + (float)(vecForward.x * 24.0);
    vCenter2.z = vecOrigin.z + (float)(vecForward.z * 24.0);
    CRender::DrawLine(this: v5, a2: (int)this, a3: (int)v5, vStart: &vecOrigin, vEnd: &vCenter2);
  }
}
