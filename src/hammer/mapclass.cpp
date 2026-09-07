// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapclass.cpp
// Functions: 83
// ============================================================

#include "hammer\mapclass.h"

//------------------------------------------------------------------------------
// Address: 0x10049020
// Name: public: virtual bool CMapClass::IsIntersectingCordon(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapClass::IsIntersectingCordon(CMapClass *this, const Vector *vecMins, const Vector *vecMaxs)
{
  return this->m_Render2DBox.IsIntersectingBox(this: &this->m_Render2DBox, a2: vecMins, a3: vecMaxs);
}

//------------------------------------------------------------------------------
// Address: 0x1010DEF0
// Name: public: void CMapClass::GetCullBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::GetCullBox(CMapClass *this, Vector *mins, Vector *maxs)
{
  *mins = this->m_CullBox.bmins;
  *maxs = this->m_CullBox.bmaxs;
}

//------------------------------------------------------------------------------
// Address: 0x1010DF20
// Name: public: void CMapClass::GetBoundingBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::GetBoundingBox(CMapClass *this, Vector *mins, Vector *maxs)
{
  *mins = this->m_BoundingBox.bmins;
  *maxs = this->m_BoundingBox.bmaxs;
}

//------------------------------------------------------------------------------
// Address: 0x1010DF50
// Name: public: void CMapClass::GetRender2DBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::GetRender2DBox(CMapClass *this, Vector *mins, Vector *maxs)
{
  *mins = this->m_Render2DBox.bmins;
  *maxs = this->m_Render2DBox.bmaxs;
}

//------------------------------------------------------------------------------
// Address: 0x1010DF80
// Name: public: char const __near * CMapClass::GetEditorKeyValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapClass::GetEditorKeyValue(CMapClass *this, const char *szKey)
{
  WCKeyValuesT<WCKVBase_Vector> *m_pEditorKeys; // ecx

  m_pEditorKeys = this->m_pEditorKeys;
  if ( m_pEditorKeys != nullptr )
    return WCKeyValuesT<WCKVBase_Vector>::GetValue(this: m_pEditorKeys, pszKey: szKey, piIndex: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1010DFB0
// Name: public: static class CMapWorld __near * CMapClass::GetWorldObject(class CMapAtom __near *)
// Source: json
//------------------------------------------------------------------------------
CMapWorld *__cdecl CMapClass::GetWorldObject(CMapAtom *pStart)
{
  CMapAtom *v1; // esi

  v1 = pStart;
  if ( pStart == nullptr )
    return nullptr;
  while ( !IsWorldObject(pObject: v1) )
  {
    v1 = v1->GetParent(this: v1);
    if ( v1 == nullptr )
      return nullptr;
  }
  return (CMapWorld *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1010DFF0
// Name: public: virtual bool CMapClass::UpdateObjectColor(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapClass::UpdateObjectColor(CMapClass *this)
{
  CVisGroup *m_pColorVisGroup; // eax
  color32_s rgbColor; // [esp+4h] [ebp-4h] BYREF

  m_pColorVisGroup = this->m_pColorVisGroup;
  if ( m_pColorVisGroup != nullptr )
  {
    ((void (__thiscall *)(CMapClass *, _DWORD))this->SetRenderColor)(
      a1: this,
      a2: *(_DWORD *)&m_pColorVisGroup->m_rgbColor);
    return 1;
  }
  else if ( this->m_pParent == nullptr || IsWorldObject(pObject: this->m_pParent) )
  {
    return 0;
  }
  else
  {
    ((void (__thiscall *)(CMapAtom *, color32_s *))this->m_pParent->GetRenderColor)(a1: this->m_pParent, a2: &rgbColor);
    ((void (__thiscall *)(_DWORD, _DWORD))this->SetRenderColor)(a1: this, a2: rgbColor);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E060
// Name: public: void CMapClass::SetColorVisGroup(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::SetColorVisGroup(CMapClass *this, CVisGroup *pVisGroup)
{
  CMapClass_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pColorVisGroup = pVisGroup;
  ((void (*)(void))v2->UpdateObjectColor)();
}

//------------------------------------------------------------------------------
// Address: 0x1010E080
// Name: public: virtual class CMapClass __near * CMapClass::PrepareSelection(enum SelectMode_t)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapClass::PrepareSelection(CMapClass *this, SelectMode_t eSelectMode)
{
  CMapClass *v3; // eax

  if ( eSelectMode != selectGroups || this->m_pParent == nullptr || IsWorldObject(pObject: this->m_pParent) )
    return this;
  v3 = this->GetParent(this);
  return v3->PrepareSelection(this: v3, a2: selectGroups);
}

//------------------------------------------------------------------------------
// Address: 0x1010E0D0
// Name: public: virtual void CMapClass::GetRenderLogicalBox(class Vector2D __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::GetRenderLogicalBox(CMapClass *this, Vector2D *mins, Vector2D *maxs)
{
  mins->x = 99999.0;
  mins->y = 99999.0;
  maxs->x = 99999.0;
  maxs->y = 99999.0;
}

//------------------------------------------------------------------------------
// Address: 0x1010E100
// Name: public: virtual class Vector2D const __near & CMapClass::GetLogicalPosition(void)
// Source: json
//------------------------------------------------------------------------------
const Vector2D *__thiscall CMapClass::GetLogicalPosition(CMapClass *this)
{
  if ( (_S1_20 & 1) == 0 )
  {
    _S1_20 |= 1u;
    pos.x = 99999.0;
    pos.y = 99999.0;
  }
  return &pos;
}

//------------------------------------------------------------------------------
// Address: 0x1010E170
// Name: public: virtual unsigned int CMapClass::GetSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMapClass::GetSize(CMapClass *this)
{
  return 216;
}

//------------------------------------------------------------------------------
// Address: 0x1010E180
// Name: public: virtual void CMapClass::UpdateChild(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::UpdateChild(CMapClass *this, CMapClass *pChild)
{
  CMapClass *v3; // eax

  if ( this->m_pParent != nullptr )
  {
    v3 = this->GetParent(this);
    v3->UpdateChild(this: v3, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E1A0
// Name: public: virtual bool CMapClass::GetTransformMatrix(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapClass::GetTransformMatrix(CMapClass *this, VMatrix *matrix)
{
  CMapAtom *m_pParent; // ecx

  m_pParent = this->m_pParent;
  return m_pParent != nullptr && m_pParent->GetTransformMatrix(this: m_pParent, a2: matrix);
}

//------------------------------------------------------------------------------
// Address: 0x1010E1C0
// Name: public: void CMapClass::RemoveEditorKeys(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::RemoveEditorKeys(CMapClass *this)
{
  WCKeyValuesT<WCKVBase_Vector> *m_pEditorKeys; // esi

  m_pEditorKeys = this->m_pEditorKeys;
  if ( m_pEditorKeys != nullptr )
  {
    WCKeyValuesT<WCKVBase_Vector>::~WCKeyValuesT<WCKVBase_Vector>(this: this->m_pEditorKeys);
    operator delete(p: m_pEditorKeys);
  }
  this->m_pEditorKeys = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1010E1F0
// Name: protected: void CMapClass::UpdateParent(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::UpdateParent(CMapClass *this, CMapClass *pNewParent)
{
  CMapClass *v3; // eax
  bool (__thiscall *UpdateObjectColor)(CMapClass *); // eax

  v3 = this->GetParent(this);
  if ( v3 != pNewParent )
  {
    if ( v3 != nullptr )
      v3->RemoveChild(this: v3, a2: this, a3: true);
    if ( pNewParent != nullptr )
      pNewParent->AddChild(this: pNewParent, a2: this);
    UpdateObjectColor = this->UpdateObjectColor;
    this->m_pParent = pNewParent;
    UpdateObjectColor(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E240
// Name: public: void CMapClass::SetEditorKeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::SetEditorKeyValue(CMapClass *this, const char *szKey, const char *szValue)
{
  WCKeyValuesT<WCKVBase_Vector> *v4; // eax
  WCKeyValuesT<WCKVBase_Vector> *v5; // eax

  if ( this->m_pEditorKeys == nullptr )
  {
    v4 = (WCKeyValuesT<WCKVBase_Vector> *)operator new(nSize: 0x14u);
    if ( v4 != nullptr )
      v5 = WCKeyValuesT<WCKVBase_Vector>::WCKeyValuesT<WCKVBase_Vector>(this: v4);
    else
      v5 = nullptr;
    this->m_pEditorKeys = v5;
  }
  WCKVBase_Vector::AddKeyValue(this: this->m_pEditorKeys, pszKey: szKey, pszValue: szValue);
}

//------------------------------------------------------------------------------
// Address: 0x1010E2C0
// Name: public: virtual bool CMapClass::IsEditable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapClass::IsEditable(CMapClass *this)
{
  CMapClass *v2; // eax

  if ( this->GetParent(this) == nullptr )
    return true;
  v2 = this->GetParent(this);
  return v2->IsEditable(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1010E2F0
// Name: public: int CMapClass::GetEditorKeyCount(void)
// Source: json
//------------------------------------------------------------------------------
WCKeyValuesT<WCKVBase_Vector> *__thiscall CMapClass::GetEditorKeyCount(CMapClass *this)
{
  WCKeyValuesT<WCKVBase_Vector> *result; // eax

  result = this->m_pEditorKeys;
  if ( result != nullptr )
    return (WCKeyValuesT<WCKVBase_Vector> *)result->m_KeyValues.m_Size;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010E300
// Name: public: int CMapClass::GetVisGroupCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapClass::GetVisGroupCount(CMapClass *this)
{
  return this->m_VisGroups.m_List.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1010E310
// Name: protected: static enum ChunkFileResult_t CMapClass::LoadEditorKeyCallback(char const __near *,char const __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapClass::LoadEditorKeyCallback(const char *szKey, const char *szValue, CMapClass *pObject)
{
  int m_nNextLoadID; // eax
  CEditGameClass *v5; // eax

  if ( _V_stricmp(s1: szKey, s2: "color") == 0 )
  {
    CChunkFile::ReadKeyValueColor(pszValue: szValue, chRed: &pObject->r, chGreen: &pObject->g, chBlue: &pObject->b);
    return ChunkFile_Ok;
  }
  if ( _V_stricmp(s1: szKey, s2: "id") == 0 )
  {
    CChunkFile::ReadKeyValueInt(pszValue: szValue, nInt: &pObject->m_nID);
    m_nNextLoadID = CMapDoc::m_pMapDoc->m_nNextLoadID;
    CMapDoc::m_pMapDoc->m_nNextLoadID = m_nNextLoadID + 1;
    pObject->m_nLoadID = m_nNextLoadID;
    return ChunkFile_Ok;
  }
  if ( _V_stricmp(s1: szKey, s2: "comments") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "visgroupshown") == 0 )
    {
      CChunkFile::ReadKeyValueBool(pszValue: szValue, bBool: &pObject->m_bVisGroupShown);
      return ChunkFile_Ok;
    }
    if ( _V_stricmp(s1: szKey, s2: "visgroupautoshown") == 0 )
    {
      CChunkFile::ReadKeyValueBool(pszValue: szValue, bBool: &pObject->m_bVisGroupAutoShown);
      return ChunkFile_Ok;
    }
    CMapClass::SetEditorKeyValue(this: pObject, szKey, szValue);
  }
  else
  {
    v5 = (CEditGameClass *)__RTDynamicCast(
                             inptr: pObject,
                             VfDelta: 0,
                             SrcType: &CMapClass `RTTI Type Descriptor',
                             TargetType: &CEditGameClass `RTTI Type Descriptor',
                             isReference: 0);
    if ( v5 != nullptr )
    {
      CEditGameClass::SetComments(this: v5, pszComments: szValue);
      return ChunkFile_Ok;
    }
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x1010E440
// Name: protected: void CMapClass::NotifyDependents(enum Notify_Dependent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::NotifyDependents(CMapClass *this, CUtlReference<CSheet> *eNotifyType)
{
  if ( this->m_Dependents.m_Size != 0 && CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::NotifyDependents(this: CMapDoc::m_pMapDoc, pObject: this, eNotifyType);
}

//------------------------------------------------------------------------------
// Address: 0x1010E510
// Name: public: static class CMapClass __near * CMapClassManager::CreateObject(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CMapClassManager::CreateObject(const char *Type)
{
  unsigned int v1; // kr00_4
  int v2; // edi
  const char *v3; // ecx
  const char *v4; // esi
  unsigned int v5; // eax
  MCMSTRUCT *i; // [esp+0h] [ebp-4h]

  v1 = strlen(Type);
  v2 = s_Classes.m_Size - 1;
  if ( s_Classes.m_Size - 1 < 0 )
    return nullptr;
  for ( i = &s_Classes.m_Memory.m_pMemory[v2]; ; --i )
  {
    v3 = Type;
    v4 = i->Type;
    v5 = v1 + 1;
    if ( v1 + 1 >= 4 )
    {
      while ( *(_DWORD *)v4 == *(_DWORD *)v3 )
      {
        v5 -= 4;
        v3 += 4;
        v4 += 4;
        if ( v5 < 4 )
          goto LABEL_6;
      }
      goto LABEL_12;
    }
LABEL_6:
    if ( v5 == 0 || *v3 == *v4 && (v5 <= 1 || v3[1] == v4[1] && (v5 <= 2 || v3[2] == v4[2])) )
      break;
LABEL_12:
    if ( --v2 < 0 )
      return nullptr;
  }
  return i->pfnNew();
}

//------------------------------------------------------------------------------
// Address: 0x1010E5B0
// Name: protected: void CMapClass::SetBoxFromFaceList(class CMapFaceList __near *,class BoundBox __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::SetBoxFromFaceList(CMapClass *this, CMapFaceList *pFaces, BoundBox *Box)
{
  CMapFaceList *v5; // ebx
  int v6; // ecx
  CMapFace *v7; // edx
  __int128 x_low; // xmm6
  __int128 y_low; // xmm5
  __int128 z_low; // xmm4
  __int128 v11; // xmm3
  __int128 v12; // xmm2
  float z; // xmm0_4
  int v14; // ecx
  int nPoints; // ebx
  int v16; // eax
  __int128 v17; // xmm1
  __int128 v18; // xmm0
  __int128 v19; // xmm0
  __int128 v20; // xmm0
  __int128 v21; // xmm0
  __int128 v22; // xmm0
  Vector point; // [esp+Ch] [ebp-1Ch]
  unsigned int v24; // [esp+18h] [ebp-10h]
  unsigned int v25; // [esp+1Ch] [ebp-Ch]
  unsigned int v26; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]
  BoundBox *Boxa; // [esp+34h] [ebp+Ch]

  BoundBox::ResetBounds(this: Box);
  v5 = pFaces;
  v6 = 0;
  for ( i = 0; v6 < v5->m_Size; i = v6 )
  {
    v7 = v5->m_Memory.m_pMemory[v6];
    if ( v7->nPoints > 0 )
    {
      x_low = LODWORD(Box->bmins.x);
      y_low = LODWORD(Box->bmins.y);
      z_low = LODWORD(Box->bmins.z);
      v11 = LODWORD(Box->bmaxs.x);
      v12 = LODWORD(Box->bmaxs.y);
      z = Box->bmaxs.z;
      v14 = 0;
      nPoints = v7->nPoints;
      while ( 1 )
      {
        point = v7->Points[v14];
        v16 = 0;
        *(float *)&Boxa = z;
        do
        {
          v17 = *((unsigned int *)&point.x + v16);
          v18 = LODWORD(this->m_Origin.x);
          *(float *)&v18 = *(float *)&v18 - *(float *)&v17;
          if ( *(float *)&v18 > *(float *)&x_low )
            v18 = x_low;
          x_low = v18;
          LODWORD(Box->bmins.x) = v18;
          v19 = LODWORD(this->m_Origin.y);
          *(float *)&v19 = *(float *)&v19 - *(float *)&v17;
          v26 = x_low;
          if ( *(float *)&v19 > *(float *)&y_low )
            v19 = y_low;
          y_low = v19;
          LODWORD(Box->bmins.y) = v19;
          v20 = LODWORD(this->m_Origin.z);
          *(float *)&v20 = *(float *)&v20 - *(float *)&v17;
          v25 = y_low;
          if ( *(float *)&v20 > *(float *)&z_low )
            v20 = z_low;
          z_low = v20;
          LODWORD(Box->bmins.z) = v20;
          v21 = v17;
          *(float *)&v21 = *(float *)&v17 + this->m_Origin.x;
          v24 = z_low;
          if ( *(float *)&v11 > *(float *)&v21 )
            v21 = v11;
          v11 = v21;
          LODWORD(Box->bmaxs.x) = v21;
          v22 = LODWORD(this->m_Origin.y);
          *(float *)&v22 = *(float *)&v22 + *(float *)&v17;
          if ( *(float *)&v12 > *(float *)&v22 )
            v22 = v12;
          v12 = v22;
          LODWORD(Box->bmaxs.y) = v22;
          z = this->m_Origin.z + *(float *)&v17;
          if ( *(float *)&Boxa > z )
            z = *(float *)&Boxa;
          ++v16;
          *(float *)&Boxa = z;
          Box->bmaxs.z = z;
        }
        while ( v16 < 3 );
        ++v14;
        if ( --nPoints == 0 )
          break;
        x_low = v26;
        y_low = v25;
        z_low = v24;
      }
      v5 = pFaces;
      v6 = i;
    }
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E750
// Name: public: class CVisGroup __near * CMapClass::GetVisGroup(int)
// Source: json
//------------------------------------------------------------------------------
CVisGroup *__thiscall CMapClass::GetVisGroup(CMapClass *this, int nIndex)
{
  return this->m_VisGroups.m_List.m_Memory.m_pMemory[nIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1010E770
// Name: protected: static enum ChunkFileResult_t CMapClass::LoadEditorCallback(class CChunkFile __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapClass::LoadEditorCallback(CChunkFile *pFile, CMapClass *pObject)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapClass::LoadEditorKeyCallback,
           pData: pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1010E790
// Name: public: virtual void CMapClass::PostUpdate(enum Notify_Dependent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::PostUpdate(CMapClass *this, CUtlReference<CSheet> *eNotifyType)
{
  void (__thiscall *UpdateChild)(CMapClass *, CMapClass *); // eax

  if ( this->m_pParent != nullptr )
  {
    UpdateChild = this->GetParent(this)->UpdateChild;
    ((void (__stdcall *)(CMapClass *))UpdateChild)(a1: this);
  }
  else if ( eNotifyType != (CUtlReference<CSheet> *)1 )
  {
    ((void (__stdcall *)(int))this->CalcBounds)(a1: 1);
  }
  if ( this->m_Dependents.m_Size != 0 && CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::NotifyDependents(this: CMapDoc::m_pMapDoc, pObject: this, eNotifyType);
}

//------------------------------------------------------------------------------
// Address: 0x1010E7F0
// Name: public: virtual enum ChunkFileResult_t CMapClass::SaveVMF(class CChunkFile __near *,class CSaveInfo __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapClass::SaveVMF(CMapClass *this, CChunkFile *pFile, CSaveInfo *pSaveInfo)
{
  CChunkFile *v3; // edi
  ChunkFileResult_t v5; // esi
  _DWORD *v6; // eax
  int m_Size; // eax
  CVisGroup *v8; // edi
  void *v9; // eax
  const char *v10; // edx
  const char *v11; // eax
  ChunkFileResult_t result; // eax
  int i; // [esp+Ch] [ebp-4h]

  v3 = pFile;
  v5 = CChunkFile::BeginChunk(this: pFile, pszChunkName: "editor");
  if ( v5 == ChunkFile_Ok )
  {
    v5 = CChunkFile::WriteKeyValueColor(this: pFile, pszKey: "color", r: this->r, g: this->g, b: this->b);
    if ( v5 == ChunkFile_Ok )
    {
      v6 = __RTDynamicCast(
             inptr: this->m_pParent,
             VfDelta: 0,
             SrcType: &CMapAtom `RTTI Type Descriptor',
             TargetType: &CMapGroup `RTTI Type Descriptor',
             isReference: 0);
      if ( v6 != nullptr )
        v5 = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "groupid", nValue: v6[41]);
    }
  }
  m_Size = this->m_VisGroups.m_List.m_Size;
  if ( m_Size == 0 )
  {
LABEL_12:
    if ( v5 != ChunkFile_Ok )
      goto LABEL_16;
    goto LABEL_13;
  }
  if ( v5 == ChunkFile_Ok )
  {
    i = 0;
    if ( m_Size <= 0 )
    {
LABEL_13:
      v5 = CChunkFile::WriteKeyValueBool(this: v3, pszKey: "visgroupshown", bValue: this->m_bVisGroupShown);
      if ( v5 == ChunkFile_Ok )
        v5 = CChunkFile::WriteKeyValueBool(this: v3, pszKey: "visgroupautoshown", bValue: this->m_bVisGroupAutoShown);
      goto LABEL_16;
    }
    while ( 1 )
    {
      v8 = this->m_VisGroups.m_List.m_Memory.m_pMemory[i];
      if ( !CParticleOperatorDefinition<C_INIT_RandomTrailLength>::IsObsolete(this: (CParticleOperatorDefinition<C_OP_RenderProjected> *)v8) )
      {
        v5 = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "visgroupid", nValue: v8->m_dwID);
        if ( v5 != ChunkFile_Ok )
          break;
      }
      if ( ++i >= this->m_VisGroups.m_List.m_Size )
      {
        v3 = pFile;
        goto LABEL_12;
      }
    }
    v3 = pFile;
  }
LABEL_16:
  v9 = __RTDynamicCast(
         inptr: this,
         VfDelta: 0,
         SrcType: &CMapClass `RTTI Type Descriptor',
         TargetType: &CEditGameClass `RTTI Type Descriptor',
         isReference: 0);
  if ( v9 != nullptr )
  {
    if ( v5 != ChunkFile_Ok )
      return v5;
    v10 = *((const char **)v9 + 25);
    v11 = CEditGameClass::g_pszEmpty;
    if ( v10 != nullptr )
      v11 = v10;
    if ( strlen(v11) == 0 )
      goto LABEL_25;
    if ( v10 == nullptr )
      v10 = CEditGameClass::g_pszEmpty;
    v5 = CChunkFile::WriteKeyValue(this: v3, pszKey: "comments", pszValue: v10);
  }
  if ( v5 != ChunkFile_Ok )
    return v5;
LABEL_25:
  result = this->SaveEditorData(this, a2: v3);
  if ( result == ChunkFile_Ok )
    return CChunkFile::EndChunk(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010E990
// Name: public: virtual CMapClassManager::~CMapClassManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClassManager::~CMapClassManager(CMapClassManager *this)
{
  this->__vftable = (CMapClassManager_vtbl *)&CMapClassManager::`vftable';
  s_Classes.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1010E9B0
// Name: public: void CMapClass::SetCullBoxFromFaceList(class CMapFaceList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::SetCullBoxFromFaceList(CMapClass *this, CMapFaceList *pFaces)
{
  CMapClass::SetBoxFromFaceList(this, pFaces, Box: &this->m_CullBox);
}

//------------------------------------------------------------------------------
// Address: 0x1010E9D0
// Name: public: char const __near * CMapClass::GetEditorKey(int)
// Source: json
//------------------------------------------------------------------------------
MDkeyvalue *__thiscall CMapClass::GetEditorKey(CMapClass *this, int nIndex)
{
  WCKeyValuesT<WCKVBase_Vector> *m_pEditorKeys; // ecx

  m_pEditorKeys = this->m_pEditorKeys;
  if ( m_pEditorKeys != nullptr )
    return &m_pEditorKeys->m_KeyValues.m_Memory.m_pMemory[nIndex];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1010EA00
// Name: public: char const __near * CMapClass::GetEditorKeyValue(int)
// Source: json
//------------------------------------------------------------------------------
WCKeyValuesT<WCKVBase_Vector> *__thiscall CMapClass::GetEditorKeyValue(CMapClass *this, int nIndex)
{
  WCKeyValuesT<WCKVBase_Vector> *result; // eax

  result = this->m_pEditorKeys;
  if ( result != nullptr )
    return (WCKeyValuesT<WCKVBase_Vector> *)result->m_KeyValues.m_Memory.m_pMemory[nIndex].szValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010EA30
// Name: public: class CMapClass __near * CMapClass::GetNextDescendent(struct EnumChildrenPos_t __near &)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapClass::GetNextDescendent(CMapClass *this, CMapClass *pos)
{
  int v3; // ecx
  int v4; // edi
  CMapClass *result; // eax
  int v6; // ecx
  int v7; // esi
  int *v8; // ecx
  int v9; // ecx
  bool v10; // sf
  int m_nBlocks; // eax
  CMapClass *pParent; // [esp+14h] [ebp+8h]

  if ( pos->m_Children.m_Memory.m_nBlocks < 0 )
    return nullptr;
  while ( *(&pos->m_nObjectID + 2 * pos->m_Children.m_Memory.m_nBlocks) == -1 )
  {
LABEL_11:
    v10 = --pos->m_Children.m_Memory.m_nBlocks < 0;
    m_nBlocks = pos->m_Children.m_Memory.m_nBlocks;
    if ( !v10 )
      return *((CMapClass **)&pos->m_pParent + 2 * m_nBlocks);
    if ( m_nBlocks < 0 )
      return nullptr;
  }
  while ( 1 )
  {
    v3 = pos->m_Children.m_Memory.m_nBlocks;
    v4 = *(&pos->m_nObjectID + 2 * v3);
    pParent = *((CMapClass **)&pos->__vftable + 2 * v3);
    result = pParent->m_Children.m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&pParent->m_Children.m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&pParent->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    *(&pos->m_nObjectID + 2 * v3) = v4 + 1;
    v6 = pos->m_Children.m_Memory.m_nBlocks;
    v7 = *(&pos->m_nObjectID + 2 * v6);
    v8 = &pos->m_nObjectID + 2 * v6;
    if ( v7 == pParent->m_Children.m_Size )
      *v8 = -1;
    if ( result == nullptr || result->m_Children.m_Size == 0 )
      return result;
    v9 = ++pos->m_Children.m_Memory.m_nBlocks;
    if ( v9 >= 16 )
    {
      pos->m_Children.m_Memory.m_nBlocks = v9 - 1;
    }
    else
    {
      *((_DWORD *)&pos->__vftable + 2 * v9) = result;
      *(&pos->m_nObjectID + 2 * pos->m_Children.m_Memory.m_nBlocks) = 0;
    }
    if ( *(&pos->m_nObjectID + 2 * pos->m_Children.m_Memory.m_nBlocks) == -1 )
      goto LABEL_11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EB40
// Name: public: int CMapClass::IsInVisGroup(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapClass::IsInVisGroup(CMapClass *this, CVisGroup *pVisGroup)
{
  int result; // eax
  int m_Size; // edx
  CVisGroup **i; // ecx

  result = 0;
  if ( pVisGroup != nullptr )
  {
    m_Size = this->m_VisGroups.m_List.m_Size;
    if ( m_Size <= 0 )
      return 0;
    for ( i = this->m_VisGroups.m_List.m_Memory.m_pMemory; *i != pVisGroup; ++i )
    {
      if ( ++result >= m_Size )
        return 0;
    }
    return result != -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010EB90
// Name: public: virtual void CMapClass::CopyChildrenFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::CopyChildrenFrom(CMapClass *this, CMapClass *pobj, BOOL bUpdateDependencies)
{
  CMapClass *v3; // edx
  int v4; // esi
  CMapClass *m_pObject; // edi
  CMapClass *v6; // ebx

  v3 = pobj;
  v4 = 0;
  if ( pobj->m_Children.m_Size > 0 )
  {
    while ( 1 )
    {
      m_pObject = v3->m_Children.m_Memory.m_pMemory[v4 >> (*((int *)&v3->m_Children.m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&v3->m_Children.m_Memory + 2)) >> 5)].m_pObject;
      v6 = m_pObject->Copy(this: m_pObject, a2: bUpdateDependencies);
      v6->CopyChildrenFrom(this: v6, a2: m_pObject, a3: bUpdateDependencies);
      this->AddChild(this, a2: v6);
      if ( ++v4 >= pobj->m_Children.m_Size )
        break;
      v3 = pobj;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EC20
// Name: public: virtual void CMapClass::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::CalcBounds(CMapClass *this, int bFullUpdate)
{
  int i; // ebx
  CMapClass *m_pObject; // esi

  if ( !CMapClass::s_bLoadingVMF )
  {
    BoundBox::ResetBounds(this: &this->m_CullBox);
    BoundBox::ResetBounds(this: &this->m_BoundingBox);
    BoundBox::ResetBounds(this: &this->m_Render2DBox);
    for ( i = 0; i < this->m_Children.m_Size; ++i )
    {
      m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        if ( bFullUpdate != 0 )
          m_pObject->CalcBounds(this: m_pObject, a2: 1);
        BoundBox::UpdateBounds(this: &this->m_CullBox, pBox: &m_pObject->m_CullBox);
        BoundBox::UpdateBounds(this: &this->m_BoundingBox, pBox: &m_pObject->m_BoundingBox);
        BoundBox::UpdateBounds(this: &this->m_Render2DBox, pBox: &m_pObject->m_Render2DBox);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010ECD0
// Name: public: virtual void CMapClass::SetRenderColor(struct color32_s)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::SetRenderColor(CMapClass *this, color32_s rgbColor)
{
  color32_s v2; // edx
  int v4; // edi
  CMapClass *m_pObject; // ecx

  v2 = rgbColor;
  v4 = 0;
  this->r = rgbColor.r;
  this->g = rgbColor.g;
  for ( this->b = rgbColor.b; v4 < this->m_Children.m_Size; ++v4 )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      m_pObject->SetRenderColor(this: m_pObject, a2: v2);
      v2 = rgbColor;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010ED50
// Name: public: virtual void CMapClass::SetRenderColor(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::SetRenderColor(CMapClass *this, int uchRed, int uchGreen, int uchBlue)
{
  int v5; // edi
  CMapClass *m_pObject; // ecx

  v5 = 0;
  this->r = uchRed;
  this->g = uchGreen;
  for ( this->b = uchBlue; v5 < this->m_Children.m_Size; ++v5 )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
      m_pObject->SetRenderColor_2(this: m_pObject, a2: uchRed, a3: uchGreen, a4: uchBlue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EDC0
// Name: public: int CMapClass::EnumChildren(int (*)(class CMapClass __near *,unsigned int),unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapClass::EnumChildren(
        CMapClass *this,
        int (__cdecl *pfn)(CMapClass *, unsigned int),
        unsigned int dwParam,
        const char *Type)
{
  int v5; // edi
  CMapClass *m_pObject; // esi

  v5 = 0;
  if ( this->m_Children.m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr
      && ((Type == nullptr || m_pObject->IsMapClass(this: m_pObject, a2: Type) != 0)
       && pfn(a1: m_pObject, a2: dwParam) == 0
       || CMapClass::EnumChildren(this: m_pObject, pfn, dwParam, Type) == 0) )
    {
      break;
    }
    if ( ++v5 >= this->m_Children.m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1010EE60
// Name: public: int CMapClass::EnumChildrenAndInstances(int (*)(class CMapClass __near *,unsigned int),unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapClass::EnumChildrenAndInstances(
        CMapClass *this,
        int (__cdecl *pfn)(CMapClass *, unsigned int),
        unsigned int dwParam,
        const char *Type)
{
  CMapClass *v4; // edx
  int v5; // ebx
  CMapEntity *m_pObject; // esi
  CMapInstance *ChildOf; // eax
  CMapDoc *m_pInstancedMap; // eax

  v4 = this;
  v5 = 0;
  if ( this->m_Children.m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    m_pObject = (CMapEntity *)v4->m_Children.m_Memory.m_pMemory[v5 >> (*((int *)&v4->m_Children.m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&v4->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    if ( (Type == nullptr || m_pObject->IsMapClass(this: m_pObject, a2: Type) != 0)
      && pfn(a1: m_pObject, a2: dwParam) == 0 )
    {
      break;
    }
    if ( CMapClass::EnumChildren(this: m_pObject, pfn, dwParam, Type) == 0 )
      break;
    if ( m_pObject->IsMapClass(this: m_pObject, a2: CMapEntity::__Type) != 0
      && m_pObject != (CMapEntity *)-252
      && _V_stricmp(s1: m_pObject->m_szClass, s2: "func_instance") == 0 )
    {
      ChildOf = CMapEntity::GetChildOfType<CMapInstance>(this: m_pObject, ignoredArg: nullptr);
      if ( ChildOf != nullptr )
      {
        m_pInstancedMap = ChildOf->m_pInstancedMap;
        if ( m_pInstancedMap != nullptr
          && CMapClass::EnumChildren(this: m_pInstancedMap->m_pWorld, pfn, dwParam, Type) == 0 )
        {
          break;
        }
      }
    }
    if ( ++v5 >= this->m_Children.m_Size )
      return 1;
    v4 = this;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1010EF80
// Name: public: int CMapClass::EnumChildrenRecurseGroupsOnly(int (*)(class CMapClass __near *,unsigned int),unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapClass::EnumChildrenRecurseGroupsOnly(
        CMapClass *this,
        int (__cdecl *pfn)(CMapClass *, unsigned int),
        unsigned int dwParam,
        const char *Type)
{
  int v5; // edi
  CMapClass *m_pObject; // esi

  v5 = 0;
  if ( this->m_Children.m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    if ( (Type == nullptr || m_pObject->IsMapClass(this: m_pObject, a2: Type) != 0)
      && pfn(a1: m_pObject, a2: dwParam) == 0 )
    {
      break;
    }
    if ( m_pObject->IsGroup(this: m_pObject)
      && CMapClass::EnumChildrenRecurseGroupsOnly(this: m_pObject, pfn, dwParam, Type) == 0 )
    {
      break;
    }
    if ( ++v5 >= this->m_Children.m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1010F030
// Name: public: virtual class CMapEntity __near * CMapClass::FindChildByKeyValue(char const __near *,char const __near *,bool __near *,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__thiscall CMapClass::FindChildByKeyValue(
        CMapClass *this,
        const char *key,
        const char *value,
        bool *bIsInInstance,
        VMatrix *InstanceMatrix)
{
  int v6; // esi
  CMapClass *m_pObject; // ecx
  CMapEntity *result; // eax

  if ( key == nullptr || value == nullptr )
    return nullptr;
  v6 = 0;
  if ( this->m_Children.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[v6 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v6 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      result = m_pObject->FindChildByKeyValue(
                 this: m_pObject,
                 a2: key,
                 a3: value,
                 a4: bIsInInstance,
                 a5: InstanceMatrix);
      if ( result != nullptr )
        break;
    }
    if ( ++v6 >= this->m_Children.m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010F0B0
// Name: public: virtual void CMapClass::OnAddToWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::OnAddToWorld(CMapClass *this, CMapWorld *pWorld)
{
  int i; // esi
  CMapClass *m_pObject; // ecx

  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    m_pObject->OnAddToWorld(this: m_pObject, a2: pWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F110
// Name: public: virtual void CMapClass::OnClone(class CMapClass __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::OnClone(
        CMapClass *this,
        CMapClass *pNewObj,
        CMapWorld *pWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  int i; // esi

  for ( i = 0; i < this->m_Children.m_Size; ++i )
    this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject->OnClone(
      this: this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      a2: pNewObj->m_Children.m_Memory.m_pMemory[i >> (*((int *)&pNewObj->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pNewObj->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      a3: pWorld,
      a4: OriginalList,
      a5: NewList);
}

//------------------------------------------------------------------------------
// Address: 0x1010F1A0
// Name: public: virtual void CMapClass::OnPreClone(class CMapClass __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::OnPreClone(
        CMapClass *this,
        CMapClass *pNewObj,
        CMapWorld *pWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  int i; // esi

  for ( i = 0; i < this->m_Children.m_Size; ++i )
    this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject->OnPreClone(
      this: this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      a2: pNewObj->m_Children.m_Memory.m_pMemory[i >> (*((int *)&pNewObj->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pNewObj->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      a3: pWorld,
      a4: OriginalList,
      a5: NewList);
}

//------------------------------------------------------------------------------
// Address: 0x1010F230
// Name: public: virtual void CMapClass::OnPrePaste(class CMapClass __near *,class CMapWorld __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::OnPrePaste(
        CMapClass *this,
        CMapClass *pCopy,
        CMapWorld *pSourceWorld,
        CMapWorld *pDestWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  int i; // esi

  for ( i = 0; i < this->m_Children.m_Size; ++i )
    this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject->OnPrePaste(
      this: this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      a2: pCopy->m_Children.m_Memory.m_pMemory[i >> (*((int *)&pCopy->m_Children.m_Memory + 2) >> 27)][i
                                                                                                 & ((32 * *((_DWORD *)&pCopy->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      a3: pSourceWorld,
      a4: pDestWorld,
      a5: OriginalList,
      a6: NewList);
}

//------------------------------------------------------------------------------
// Address: 0x1010F2D0
// Name: public: virtual void CMapClass::OnPaste(class CMapClass __near *,class CMapWorld __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::OnPaste(
        CMapClass *this,
        CMapClass *pCopy,
        CMapWorld *pSourceWorld,
        CMapWorld *pDestWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  int i; // esi

  for ( i = 0; i < this->m_Children.m_Size; ++i )
    this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject->OnPaste(
      this: this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      a2: pCopy->m_Children.m_Memory.m_pMemory[i >> (*((int *)&pCopy->m_Children.m_Memory + 2) >> 27)][i
                                                                                                 & ((32 * *((_DWORD *)&pCopy->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      a3: pSourceWorld,
      a4: pDestWorld,
      a5: OriginalList,
      a6: NewList);
}

//------------------------------------------------------------------------------
// Address: 0x1010F370
// Name: public: virtual void CMapClass::PostloadWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::PostloadWorld(CMapClass *this, CMapWorld *pWorld)
{
  int i; // esi
  CMapClass *m_pObject; // ecx

  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    m_pObject->PostloadWorld(this: m_pObject, a2: pWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F3D0
// Name: public: virtual bool CMapClass::RenderPreload(class CRender3D __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapClass::RenderPreload(CMapClass *this, CRender3D *pRender, BOOL bNewContext)
{
  int i; // esi
  CMapClass *m_pObject; // ecx

  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    m_pObject->RenderPreload(this: m_pObject, a2: pRender, a3: bNewContext);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010F430
// Name: protected: virtual void CMapClass::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::DoTransform(CMapClass *this, const VMatrix *matrix)
{
  int i; // edi
  CMapClass *m_pObject; // esi

  CMapPoint::DoTransform(this, matrix);
  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    m_pObject->DoTransform(this: m_pObject, a2: matrix);
    m_pObject->PostUpdate(this: m_pObject, a2: Notify_Transform);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F4A0
// Name: public: virtual bool CMapClass::HitTest2D(class CMapView2D __near *,class Vector2D const __near &,struct HitInfo_s __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapClass::HitTest2D(CMapClass *this, CMapView2D *pView, const Vector2D *point, HitInfo_s *HitData)
{
  double v6; // st7
  int i; // edi
  CMapClass *m_pObject; // ecx
  CMapClass *pObject; // ecx
  unsigned int uData; // edx
  HitInfo_s testHitData; // [esp+4h] [ebp-54h] BYREF
  __int64 v13; // [esp+50h] [ebp-8h]
  char bFoundHit_3; // [esp+6Bh] [ebp+13h]

  HitData->pObject = nullptr;
  v6 = g_MAX_MAP_COORD;
  HitData->uData = 0;
  v13 = (__int64)(v6 * 3.0);
  HitData->nDepth = v13;
  bFoundHit_3 = 0;
  if ( (*((_BYTE *)this + 180) & 2) == 0 )
    return 0;
  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> (*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject->HitTest2D(this: m_pObject, a2: pView, a3: point, a4: &testHitData)
      && testHitData.nDepth < HitData->nDepth )
    {
      pObject = testHitData.pObject;
      uData = testHitData.uData;
      HitData->nDepth = testHitData.nDepth;
      HitData->pObject = pObject;
      HitData->uData = uData;
      VMatrix::operator=(this: &HitData->m_LocalMatrix, mOther: &testHitData.m_LocalMatrix);
      bFoundHit_3 = 1;
    }
  }
  return bFoundHit_3;
}

//------------------------------------------------------------------------------
// Address: 0x1010F580
// Name: public: virtual bool CMapClass::HitTestLogical(class CMapViewLogical __near *,class Vector2D const __near &,struct HitInfo_s __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapClass::HitTestLogical(
        CMapClass *this,
        CMapViewLogical *pView,
        const Vector2D *point,
        HitInfo_s *hitData)
{
  bool result; // al
  int v6; // esi
  CMapClass *m_pObject; // ecx

  result = this->IsVisibleLogical(this);
  if ( result )
  {
    v6 = 0;
    if ( this->m_Children.m_Size <= 0 )
    {
      return false;
    }
    else
    {
      while ( 1 )
      {
        m_pObject = this->m_Children.m_Memory.m_pMemory[v6 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v6 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        if ( m_pObject->HitTestLogical(this: m_pObject, a2: pView, a3: point, a4: hitData) )
          break;
        if ( ++v6 >= this->m_Children.m_Size )
          return false;
      }
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010F610
// Name: public: virtual enum SelectionState_t CMapClass::SetSelectionState(enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
SelectionState_t __thiscall CMapClass::SetSelectionState(CMapClass *this, SelectionState_t eSelectionState)
{
  int i; // esi
  CMapClass *m_pObject; // ecx
  SelectionState_t result; // eax

  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    m_pObject->SetSelectionState(this: m_pObject, a2: eSelectionState);
  }
  result = this->m_eSelectionState;
  this->m_eSelectionState = eSelectionState;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010F670
// Name: public: virtual void CMapClass::ReplaceTargetname(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::ReplaceTargetname(CMapClass *this, const char *szOldName, const char *szNewName)
{
  int i; // esi
  CMapClass *m_pObject; // ecx

  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    m_pObject->ReplaceTargetname(this: m_pObject, a2: szOldName, a3: szNewName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F6D0
// Name: public: virtual void CMapClass::SetOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::SetOrigin(CMapClass *this, Vector *origin)
{
  int i; // esi
  CMapClass *m_pObject; // ecx

  CMapPoint::SetOrigin(this, Origin: origin);
  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    m_pObject->SetOrigin(this: m_pObject, a2: origin);
  }
  this->PostUpdate(this, a2: Notify_Changed);
}

//------------------------------------------------------------------------------
// Address: 0x1010F740
// Name: public: void CMapClass::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::SetVisible(CMapClass *this, bool bVisible)
{
  int i; // edi
  CMapClass *m_pObject; // ecx

  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
      CMapClass::SetVisible(this: m_pObject, bVisible);
  }
  *((_BYTE *)this + 180) ^= (*((_BYTE *)this + 180) ^ (2 * bVisible)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x1010F7B0
// Name: public: void CMapClass::VisGroupShow(bool,enum VisGroupSelection)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::VisGroupShow(CMapClass *this, bool bShow, VisGroupSelection eVisGroup)
{
  int i; // esi

  for ( i = 0; i < this->m_Children.m_Size; ++i )
    CMapClass::VisGroupShow(
      this: this->m_Children.m_Memory.m_pMemory[i >> (*((int *)&this->m_Children.m_Memory + 2) >> 27)][i
                                                                                               & ((32
                                                                                                 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      bShow,
      eVisGroup);
  if ( eVisGroup != AUTO )
  {
    if ( eVisGroup == USER )
    {
      if ( bShow )
        this->m_bVisGroupAutoShown = bShow;
      this->m_bVisGroupShown = bShow;
    }
  }
  else
  {
    this->m_bVisGroupAutoShown = bShow;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F830
// Name: public: bool CMapClass::CheckVisibility(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapClass::CheckVisibility(CMapClass *this, bool bLoading)
{
  int m_Size; // ebx
  int v4; // edi
  int i; // edi
  int j; // edi
  CMapDoc *pDoc; // [esp+Ch] [ebp-8h]
  bool bInUser; // [esp+12h] [ebp-2h]
  bool bInAuto; // [esp+13h] [ebp-1h]

  m_Size = this->m_VisGroups.m_List.m_Size;
  v4 = 0;
  bInUser = false;
  bInAuto = false;
  pDoc = CMapDoc::m_pMapDoc;
  if ( m_Size <= 0 )
    goto LABEL_7;
  do
  {
    if ( CParticleOperatorDefinition<C_INIT_RandomTrailLength>::IsObsolete(this: (CParticleOperatorDefinition<C_OP_RenderProjected> *)this->m_VisGroups.m_List.m_Memory.m_pMemory[v4]) )
      bInAuto = true;
    else
      bInUser = true;
    ++v4;
  }
  while ( v4 < m_Size );
  if ( !bInAuto )
  {
LABEL_7:
    if ( !this->m_bVisGroupAutoShown )
      CMapClass::VisGroupShow(this, bShow: true, eVisGroup: AUTO);
  }
  if ( bInUser || this->m_bVisGroupShown )
    return 0;
  for ( i = 0; i < this->m_Children.m_Size; ++i )
    CMapClass::VisGroupShow(
      this: this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      bShow: true,
      eVisGroup: USER);
  *(_WORD *)&this->m_bVisGroupShown = 257;
  if ( !bLoading || !CMapDoc::VisGroups_ObjectCanBelongToVisGroup(this: pDoc, pObject: this) )
    return 0;
  for ( j = 0; j < this->m_Children.m_Size; ++j )
    CMapClass::VisGroupShow(
      this: this->m_Children.m_Memory.m_pMemory[j >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      bShow: false,
      eVisGroup: USER);
  this->m_bVisGroupShown = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010FA20
// Name: public: class CMapClass __near * CMapClass::GetFirstDescendent(struct EnumChildrenPos_t __near &)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapClass::GetFirstDescendent(CMapClass *this, CMapClass *pos)
{
  pos->m_Children.m_Memory.m_nBlocks = 0;
  pos->__vftable = (CMapClass_vtbl *)this;
  if ( this->m_Children.m_Size != 0 )
  {
    pos->m_nObjectID = 0;
    return CMapClass::GetNextDescendent(this, pos);
  }
  else
  {
    pos->m_nObjectID = -1;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FA60
// Name: public: void CMapClass::RemoveVisGroup(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::RemoveVisGroup(CMapClass *this, CVisGroup *pVisGroup)
{
  int m_Size; // esi
  int v3; // eax
  CVisGroup **i; // edx

  m_Size = this->m_VisGroups.m_List.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_VisGroups.m_List.m_Memory.m_pMemory; *i != pVisGroup; ++i )
    {
      if ( ++v3 >= m_Size )
        return;
    }
    if ( v3 != -1 )
    {
      if ( v3 != m_Size - 1 )
        this->m_VisGroups.m_List.m_Memory.m_pMemory[v3] = this->m_VisGroups.m_List.m_Memory.m_pMemory[m_Size - 1];
      --this->m_VisGroups.m_List.m_Size;
      CMapClass::CheckVisibility(this, bLoading: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FAD0
// Name: public: void CMapClass::RemoveAllVisGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::RemoveAllVisGroups(CMapClass *this)
{
  int v1; // edi
  int i; // edi

  v1 = 0;
  for ( this->m_VisGroups.m_List.m_Size = 0; v1 < this->m_Children.m_Size; ++v1 )
    CMapClass::RemoveAllVisGroups(this: this->m_Children.m_Memory.m_pMemory[v1 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v1 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject);
  for ( i = 0; i < this->m_Children.m_Size; ++i )
    CMapClass::VisGroupShow(
      this: this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      bShow: true,
      eVisGroup: USER);
  *(_WORD *)&this->m_bVisGroupShown = 257;
}

//------------------------------------------------------------------------------
// Address: 0x1010FB80
// Name: public: bool CMapClass::PostloadVisGroups(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapClass::PostloadVisGroups(CMapClass *this, bool bLoading)
{
  int i; // esi

  for ( i = 0; i < this->m_Children.m_Size; ++i )
    CMapClass::PostloadVisGroups(
      this: this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
      bLoading);
  return CMapClass::CheckVisibility(this, bLoading);
}

//------------------------------------------------------------------------------
// Address: 0x1010FBE0
// Name: public: static void CMapClass::UpdateAllDependencies(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapClass::UpdateAllDependencies(CMapClass *pObject)
{
  CMapWorld *WorldObject; // esi
  bool v2; // zf
  CMapClass *i; // eax
  EnumChildrenPos_t pos; // [esp+8h] [ebp-84h] BYREF

  if ( pObject != nullptr )
  {
    WorldObject = CMapClass::GetWorldObject(pStart: pObject);
  }
  else
  {
    if ( CMapDoc::m_pMapDoc == nullptr || CMapDoc::m_pMapDoc->m_bLoading )
      return;
    WorldObject = CMapDoc::m_pMapDoc->m_pWorld;
  }
  if ( WorldObject != nullptr )
  {
    CMapWorld::UpdateAllDependencies(this: WorldObject, pObject);
    v2 = WorldObject->m_Children.m_Size == 0;
    pos.nDepth = 0;
    pos.Stack[0].pParent = WorldObject;
    if ( !v2 )
    {
      pos.Stack[0].pos = 0;
      for ( i = CMapClass::GetNextDescendent(this: WorldObject, (CMapClass *)&pos);
            i != nullptr;
            i = CMapClass::GetNextDescendent(this: WorldObject, (CMapClass *)&pos) )
      {
        i->UpdateDependencies(this: i, a2: WorldObject, a3: pObject);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FCE0
// Name: public: CMapClassManager::CMapClassManager(char const __near *,class CMapClass __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
CMapClassManager *__thiscall CMapClassManager::CMapClassManager(
        CMapClassManager *this,
        const char *Type,
        CMapClass *(__cdecl *pfnNew)())
{
  MCMSTRUCT mcms; // [esp+4h] [ebp-8h] BYREF

  this->__vftable = (CMapClassManager_vtbl *)&CMapClassManager::`vftable';
  mcms.Type = Type;
  mcms.pfnNew = pfnNew;
  CUtlVector<UsedTexture_t,CUtlMemory<UsedTexture_t,int>>::InsertBefore(
    this: &s_Classes,
    elem: s_Classes.m_Size,
    src: &mcms);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010FD20
// Name: public: virtual void CMapClass::AddVisGroup(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::AddVisGroup(CMapClass *this, CVisGroup *pVisGroup)
{
  int m_Size; // edx
  vgui::Dar<unsigned long> *p_m_VisGroups; // ecx
  int v4; // eax
  CVisGroup **m_pMemory; // esi

  m_Size = this->m_VisGroups.m_List.m_Size;
  p_m_VisGroups = (vgui::Dar<unsigned long> *)&this->m_VisGroups;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (CVisGroup **)p_m_VisGroups->m_Memory.m_pMemory;
  while ( *m_pMemory != pVisGroup )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
LABEL_7:
    vgui::Dar<unsigned long>::AddElement(this: p_m_VisGroups, elem: (unsigned int)pVisGroup);
}

//------------------------------------------------------------------------------
// Address: 0x1010FD70
// Name: public: virtual void CMapClass::RemoveChild(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::RemoveChild(CMapClass *this, CMapClass *pChild, bool bUpdateBounds)
{
  CUtlReference<CMapClass> *m_pHead; // eax
  CUtlReferenceVector<CMapClass> *p_m_Children; // esi
  int v5; // eax
  CUtlReference<CMapClass> src; // [esp+Ch] [ebp-1Ch] BYREF
  CMapClass *v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+24h] [ebp-4h]

  v7 = this;
  src.m_pPrev = nullptr;
  src.m_pNext = nullptr;
  src.m_pObject = pChild;
  if ( pChild != nullptr )
  {
    m_pHead = pChild->m_References.m_pHead;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pChild->m_References.m_pHead = &src;
  }
  v8 = 0;
  p_m_Children = &this->m_Children;
  v5 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
         this: &this->m_Children,
         &src);
  v8 = -1;
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
  if ( v5 == -1 )
  {
    pChild->m_pParent = nullptr;
  }
  else
  {
    CUtlReferenceVector<CMapClass>::FastRemove(this: p_m_Children, elem: v5);
    pChild->m_pParent = nullptr;
    if ( bUpdateBounds )
      v7->PostUpdate(this: v7, a2: Notify_Removed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FE70
// Name: protected: void CMapClass::RemoveDependent(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::RemoveDependent(CMapClass *this, CMapClass *pDependent)
{
  CUtlReference<CMapClass> *m_pHead; // edx
  CUtlReferenceVector<CMapClass> *p_m_Dependents; // edi
  int v4; // eax
  CUtlReference<CMapClass> src; // [esp+8h] [ebp-18h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  src.m_pPrev = nullptr;
  src.m_pNext = nullptr;
  src.m_pObject = pDependent;
  if ( pDependent != nullptr )
  {
    m_pHead = pDependent->m_References.m_pHead;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pDependent->m_References.m_pHead = &src;
  }
  v6 = 0;
  p_m_Dependents = &this->m_Dependents;
  v4 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
         this: &this->m_Dependents,
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
  if ( v4 != -1 )
    CUtlReferenceVector<CMapClass>::FastRemove(this: p_m_Dependents, elem: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1010FF40
// Name: protected: void CMapClass::AddDependent(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::AddDependent(CMapClass *this, CMapClass *pDependent)
{
  CUtlReference<CMapClass> *m_pHead; // eax
  CUtlReferenceVector<CMapClass> *p_m_Dependents; // ebx
  int v4; // eax
  CMapClass *v5; // eax
  CUtlReference<CMapClass> *v6; // eax
  CUtlReference<CMapClass> src; // [esp+8h] [ebp-1Ch] BYREF
  CMapClass *v8; // [esp+14h] [ebp-10h]
  int v9; // [esp+20h] [ebp-4h]

  v8 = this;
  if ( pDependent != nullptr && pDependent != this )
  {
    m_pHead = pDependent->m_References.m_pHead;
    src.m_pPrev = nullptr;
    src.m_pObject = pDependent;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pDependent->m_References.m_pHead = &src;
    v9 = 0;
    p_m_Dependents = &this->m_Dependents;
    v4 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
           this: &this->m_Dependents,
           &src);
    v9 = -1;
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
    if ( v4 == -1 )
    {
      v5 = v8->GetParent(this: v8);
      if ( v5 != nullptr )
      {
        while ( v5 != pDependent )
        {
          v5 = v5->GetParent(this: v5);
          if ( v5 == nullptr )
            goto LABEL_17;
        }
      }
      else
      {
LABEL_17:
        v6 = pDependent->m_References.m_pHead;
        src.m_pPrev = nullptr;
        src.m_pObject = pDependent;
        src.m_pNext = v6;
        if ( v6 != nullptr )
          v6->m_pPrev = &src;
        src.m_pPrev = nullptr;
        pDependent->m_References.m_pHead = &src;
        v9 = 1;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
          this: p_m_Dependents,
          elem: p_m_Dependents->m_Size,
          &src);
        v9 = -1;
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
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101100C0
// Name: public: virtual class CMapClass __near * CMapClass::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapClass::CopyFrom(CMapClass *this, CVisGroup *pFrom, bool bUpdateDependencies)
{
  int v5; // ebx
  CMapClass *v6; // eax
  CMapAtom *v7; // edi
  CMapClass *v8; // eax
  bool (__thiscall *UpdateObjectColor)(CMapClass *); // eax
  int nVisGroupCount; // [esp+Ch] [ebp-4h]
  CVisGroup *pVisGroup; // [esp+18h] [ebp+8h]

  this->m_Origin = *(Vector *)&pFrom->m_pParent;
  v5 = 0;
  nVisGroupCount = *(_DWORD *)&pFrom[1].m_szName[3];
  if ( nVisGroupCount > 0 )
  {
    do
    {
      pVisGroup = pFrom[1].m_Children.m_pElements[v5];
      if ( !CParticleOperatorDefinition<C_INIT_RandomTrailLength>::IsObsolete(this: (CParticleOperatorDefinition<C_OP_RenderProjected> *)pVisGroup) )
        this->AddVisGroup(this, a2: pVisGroup);
      ++v5;
    }
    while ( v5 < nVisGroupCount );
  }
  this->m_bTemporary = pFrom[1].m_Children.m_Memory.m_nAllocationCount;
  *((_BYTE *)this + 180) ^= (*((_BYTE *)this + 180) ^ LOBYTE(pFrom[1].m_Children.m_Size)) & 1;
  this->m_nRenderFrame = pFrom[1].m_Children.m_Memory.m_nGrowSize;
  this->m_CullBox.bmins.x = *(float *)&pFrom->m_szName[19];
  this->m_CullBox.bmins.y = *(float *)&pFrom->m_szName[23];
  this->m_CullBox.bmins.z = *(float *)&pFrom->m_szName[27];
  this->m_CullBox.bmaxs.x = *(float *)&pFrom->m_szName[31];
  this->m_CullBox.bmaxs.y = *(float *)&pFrom->m_szName[35];
  this->m_CullBox.bmaxs.z = *(float *)&pFrom->m_szName[39];
  this->m_BoundingBox.bmins.x = *(float *)&pFrom->m_szName[47];
  this->m_BoundingBox.bmins.y = *(float *)&pFrom->m_szName[51];
  this->m_BoundingBox.bmins.z = *(float *)&pFrom->m_szName[55];
  this->m_BoundingBox.bmaxs.x = *(float *)&pFrom->m_szName[59];
  this->m_BoundingBox.bmaxs.y = *(float *)&pFrom->m_szName[63];
  this->m_BoundingBox.bmaxs.z = *(float *)&pFrom->m_szName[67];
  this->m_Render2DBox.bmins.x = *(float *)&pFrom->m_szName[75];
  this->m_Render2DBox.bmins.y = *(float *)&pFrom->m_szName[79];
  this->m_Render2DBox.bmins.z = *(float *)&pFrom->m_szName[83];
  this->m_Render2DBox.bmaxs.x = *(float *)&pFrom->m_szName[87];
  this->m_Render2DBox.bmaxs.y = *(float *)&pFrom->m_szName[91];
  this->m_Render2DBox.bmaxs.z = *(float *)&pFrom->m_szName[95];
  this->r = (unsigned __int8)pFrom->m_Children.m_pElements;
  this->g = BYTE1(pFrom->m_Children.m_pElements);
  this->b = BYTE2(pFrom->m_Children.m_pElements);
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_Dependents);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::AddVectorToTail(
    this: &this->m_Dependents,
    src: (const CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)&pFrom->m_szName[119]);
  v6 = (CMapClass *)(*((int (__thiscall **)(CVisGroup *))pFrom->m_Children.m_Memory.m_pMemory + 31))(a1: pFrom);
  if ( !bUpdateDependencies )
  {
    this->m_pParent = v6;
    return this;
  }
  v7 = v6;
  v8 = this->GetParent(this);
  if ( v8 == v7 )
    return this;
  if ( v8 != nullptr )
    v8->RemoveChild(this: v8, a2: this, a3: true);
  if ( v7 != nullptr )
    ((void (__thiscall *)(CMapAtom *, CMapClass *))v7->__vftable[1].GetRenderColor)(a1: v7, a2: this);
  UpdateObjectColor = this->UpdateObjectColor;
  this->m_pParent = v7;
  UpdateObjectColor(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10110250
// Name: public: virtual void CMapClass::AddChild(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::AddChild(CMapClass *this, CMapClass *pChild)
{
  CUtlReference<CMapClass> *m_pHead; // eax
  bool v4; // dl
  CUtlReference<CMapClass> *v5; // eax
  CMapClass *v6; // eax
  Vector vecMins; // [esp+Ch] [ebp-30h] BYREF
  Vector vecMaxs; // [esp+18h] [ebp-24h] BYREF
  CUtlReference<CMapClass> src; // [esp+24h] [ebp-18h] BYREF
  int v10; // [esp+38h] [ebp-4h]

  src.m_pPrev = nullptr;
  src.m_pNext = nullptr;
  src.m_pObject = pChild;
  if ( pChild != nullptr )
  {
    m_pHead = pChild->m_References.m_pHead;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pChild->m_References.m_pHead = &src;
  }
  v10 = 0;
  v4 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
         this: &this->m_Children,
         &src) != -1;
  v10 = -1;
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
  if ( v4 )
  {
    pChild->m_pParent = this;
  }
  else
  {
    src.m_pPrev = nullptr;
    src.m_pNext = nullptr;
    src.m_pObject = pChild;
    if ( pChild != nullptr )
    {
      v5 = pChild->m_References.m_pHead;
      src.m_pNext = v5;
      if ( v5 != nullptr )
        v5->m_pPrev = &src;
      src.m_pPrev = nullptr;
      pChild->m_References.m_pHead = &src;
    }
    v10 = 1;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
      this: &this->m_Children,
      elem: this->m_Children.m_Size,
      &src);
    v10 = -1;
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
    pChild->SetParent(this: pChild, a2: this);
    vecMins = pChild->m_CullBox.bmins;
    vecMaxs = pChild->m_CullBox.bmaxs;
    BoundBox::UpdateBounds(this: &this->m_CullBox, mins: &vecMins, maxs: &vecMaxs);
    vecMins = pChild->m_BoundingBox.bmins;
    vecMaxs = pChild->m_BoundingBox.bmaxs;
    BoundBox::UpdateBounds(this: &this->m_BoundingBox, mins: &vecMins, maxs: &vecMaxs);
    vecMins = pChild->m_Render2DBox.bmins;
    vecMaxs = pChild->m_Render2DBox.bmaxs;
    BoundBox::UpdateBounds(this: &this->m_Render2DBox, mins: &vecMins, maxs: &vecMaxs);
    if ( this->m_pParent != nullptr )
    {
      v6 = this->GetParent(this);
      v6->UpdateChild(this: v6, a2: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101104C0
// Name: public: virtual void CMapClass::RemoveAllChildren(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::RemoveAllChildren(CMapClass *this)
{
  int i; // edx
  CMapClass *m_pObject; // eax

  for ( i = 0; i < this->m_Children.m_Size; m_pObject->m_pParent = nullptr )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    ++i;
  }
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_Children);
}

//------------------------------------------------------------------------------
// Address: 0x10110510
// Name: public: virtual void CMapClass::OnRemoveFromWorld(class CMapWorld __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::OnRemoveFromWorld(CMapClass *this, CMapWorld *pWorld, bool bNotifyChildren)
{
  int i; // esi
  CMapClass *m_pObject; // ecx

  if ( this->m_Dependents.m_Size != 0 && CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::NotifyDependents(this: CMapDoc::m_pMapDoc, pObject: this, eNotifyType: (CUtlReference<CSheet> *)1);
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_Dependents);
  if ( bNotifyChildren )
  {
    for ( i = 0; i < this->m_Children.m_Size; ++i )
    {
      m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
      m_pObject->OnRemoveFromWorld(this: m_pObject, a2: pWorld, a3: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101105A0
// Name: protected: class CMapClass __near * CMapClass::UpdateDependency(class CMapClass __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapClass::UpdateDependency(CMapClass *this, CMapClass *pOldAttached, CMapClass *pNewAttached)
{
  if ( pOldAttached != pNewAttached )
  {
    if ( pOldAttached != nullptr )
      CMapClass::RemoveDependent(this: pOldAttached, pDependent: this);
    if ( pNewAttached != nullptr )
      CMapClass::AddDependent(this: pNewAttached, pDependent: this);
  }
  return pNewAttached;
}

//------------------------------------------------------------------------------
// Address: 0x101105D0
// Name: public: virtual CMapClass::~CMapClass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::~CMapClass(CMapClass *this)
{
  WCKeyValuesT<WCKVBase_Vector> *m_pEditorKeys; // ecx
  CUtlReference<CMapClass> *m_pHead; // eax
  CUtlReference<CMapClass> *m_pNext; // ecx
  WCKeyValuesT<WCKVBase_Vector> *p; // [esp+10h] [ebp-10h]

  this->__vftable = (CMapClass_vtbl *)&CMapClass::`vftable';
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_Children);
  m_pEditorKeys = this->m_pEditorKeys;
  p = m_pEditorKeys;
  if ( m_pEditorKeys != nullptr )
  {
    WCKeyValuesT<WCKVBase_Vector>::~WCKeyValuesT<WCKVBase_Vector>(this: m_pEditorKeys);
    operator delete(p);
  }
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&this->m_VisGroups);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &this->m_Dependents);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &this->m_Children);
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
}

//------------------------------------------------------------------------------
// Address: 0x101106A0
// Name: public: CMapClass::CMapClass(void)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapClass::CMapClass(CMapClass *this)
{
  CVisGroup **m_pMemory; // ecx
  int m_nNextMapObjectID; // ecx

  CMapPoint::CMapPoint(this);
  this->__vftable = (CMapClass_vtbl *)&CMapClass::`vftable';
  this->m_References.m_pHead = nullptr;
  BoundBox::BoundBox(this: &this->m_CullBox);
  BoundBox::BoundBox(this: &this->m_BoundingBox);
  BoundBox::BoundBox(this: &this->m_Render2DBox);
  this->m_Children.m_Memory.m_pMemory = nullptr;
  this->m_Children.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->m_Children.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &this->m_Children.m_Memory, nGrowSize: 0, nInitSize: 0);
  this->m_Children.m_Size = 0;
  this->m_Children.m_pElements = nullptr;
  this->m_Dependents.m_Memory.m_pMemory = nullptr;
  this->m_Dependents.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->m_Dependents.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &this->m_Dependents.m_Memory, nGrowSize: 0, nInitSize: 0);
  this->m_Dependents.m_Size = 0;
  this->m_Dependents.m_pElements = nullptr;
  this->m_VisGroups.m_List.m_Memory.m_pMemory = nullptr;
  this->m_VisGroups.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_VisGroups.m_List.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_VisGroups.m_List.m_Memory.m_pMemory;
  this->m_VisGroups.m_List.m_Size = 0;
  this->m_VisGroups.m_List.m_pElements = m_pMemory;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    m_nNextMapObjectID = CMapDoc::m_pMapDoc->m_nNextMapObjectID;
    CMapDoc::m_pMapDoc->m_nNextMapObjectID = m_nNextMapObjectID + 1;
    this->m_nID = m_nNextMapObjectID;
  }
  else
  {
    this->m_nID = 0;
  }
  *((_BYTE *)this + 180) |= 3u;
  this->m_nLoadID = 0;
  this->dwKept = 0;
  this->m_bTemporary = false;
  *(_WORD *)&this->m_bVisGroupShown = 257;
  this->m_pColorVisGroup = nullptr;
  *(_WORD *)&this->g = -8996;
  this->r = -36;
  this->m_pParent = nullptr;
  this->m_nRenderFrame = 0;
  this->m_pEditorKeys = nullptr;
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_Dependents);
  this->m_nDropTraceMarker = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F8911
// Name: public: virtual int CPaneDivider::CheckVisibility(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::CheckVisibility(CPaneDivider *this)
{
  int v2; // edi

  if ( this->m_bDefaultDivider == 0 || this->IsAutoHideMode(this) != 0 || this->m_pContainerManager == nullptr )
    return 0;
  v2 = this->m_pContainerManager->IsRootPaneContainerVisible(this: this->m_pContainerManager);
  CWnd::ShowWindow(this, nCmdShow: v2 != 0 ? 5 : 0);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x103F895B
// Name: public: virtual int CPaneDivider::DoesContainFloatingPane(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::DoesContainFloatingPane(CPaneDivider *this)
{
  if ( this->m_pContainerManager != nullptr )
    return this->m_pContainerManager->DoesContainFloatingPane(this: this->m_pContainerManager);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103F8974
// Name: public: virtual int CPaneDivider::DoesAllowDynInsertBefore(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::DoesAllowDynInsertBefore(CPaneDivider *this)
{
  if ( this->m_pContainerManager != nullptr )
    return this->m_pContainerManager->DoesAllowDynInsertBefore(this: this->m_pContainerManager);
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103F898E
// Name: public: virtual void CPaneDivider::CalcExpectedDockedRect(class CWnd __near *,class CPoint,class CRect __near &,int __near &,class CDockablePane __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::CalcExpectedDockedRect(
        CPaneDivider *this,
        CWnd *pWndToDock,
        CPoint ptMouse,
        CRect *rectResult,
        int *bDrawTab,
        CDockablePane **ppTargetBar)
{
  CPaneContainerManager *m_pContainerManager; // eax
  CGlobalUtils globalUtilsLocal; // [esp+10h] [ebp-18h] BYREF
  int v9; // [esp+24h] [ebp-4h]

  CGlobalUtils::CGlobalUtils(this: &globalUtilsLocal);
  m_pContainerManager = this->m_pContainerManager;
  v9 = 0;
  if ( m_pContainerManager != nullptr )
    CGlobalUtils::CalcExpectedDockedRect(
      this: &globalUtilsLocal,
      barContainerManager: m_pContainerManager,
      pWndToDock,
      ptMouse,
      rectResult,
      bDrawTab,
      ppTargetBar);
  v9 = -1;
  CGlobalUtils::~CGlobalUtils(this: &globalUtilsLocal);
}

//------------------------------------------------------------------------------
// Address: 0x103F89E1
// Name: public: virtual void CPaneDivider::NotifyAboutRelease(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::NotifyAboutRelease(CPaneDivider *this)
{
  if ( CPaneContainerManager::IsEmpty(this: this->m_pContainerManager)
    && CPaneContainerManager::GetTotalRefCount(this: this->m_pContainerManager) == 0 )
  {
    CBasePane::RemovePaneFromDockManager(
      this,
      pBar: this,
      bDestroy: 1,
      bAdjustLayout: 0,
      bAutoHide: this->m_bAutoHideMode,
      pBarReplacement: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F8A1A
// Name: public: void CPaneDivider::GetPanes(class CObList __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::GetPanes(CPaneDivider *this, CObList *lstBars)
{
  CPaneContainerManager *m_pContainerManager; // ecx

  m_pContainerManager = this->m_pContainerManager;
  if ( m_pContainerManager != nullptr )
    CPaneContainerManager::AddPanesToList(this: m_pContainerManager, plstControlBars: lstBars, plstSliders: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103F8A37
// Name: public: class CRect CPaneDivider::GetRootContainerRect(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRect *__thiscall CPaneDivider::GetRootContainerRect(CPaneDivider *this, CRect *result)
{
  result->left = 0;
  result->top = 0;
  result->right = 0;
  result->bottom = 0;
  SetRectEmpty(lprc: result);
  if ( this->m_pContainerManager != nullptr )
    this->m_pContainerManager->GetWindowRect(this: this->m_pContainerManager, a2: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F8A77
// Name: public: CPaneDivider::CPaneDivider(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneDivider *__thiscall CPaneDivider::CPaneDivider(CPaneDivider *this)
{
  CBasePane::CBasePane(this);
  this->__vftable = (CPaneDivider_vtbl *)&CPaneDivider::`vftable';
  this->m_rectLastDragRect.left = 0;
  this->m_rectLastDragRect.top = 0;
  this->m_rectLastDragRect.right = 0;
  this->m_rectLastDragRect.bottom = 0;
  this->m_rectDragBounds.left = 0;
  this->m_rectDragBounds.top = 0;
  this->m_rectDragBounds.right = 0;
  this->m_rectDragBounds.bottom = 0;
  this->m_ptHotTotal.x = 0;
  this->m_ptHotTotal.y = 0;
  this->m_ptHotDrag.x = 0;
  this->m_ptHotDrag.y = 0;
  CPaneDivider::Init(this, bDefaultSlider: 0, pParentWnd: nullptr);
  return this;
}
