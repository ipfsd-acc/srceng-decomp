// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapcheckdlg.cpp
// Functions: 47
// ============================================================

#include "hammer\mapcheckdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100D08D0
// Name: protected: void CMapCheckDlg::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCheckDlg::OnPaint(CMapCheckDlg *this)
{
  CPaintDC dc; // [esp+0h] [ebp-54h] BYREF

  CPaintDC::CPaintDC(this: &dc, pWnd: this);
  CPaintDC::~CPaintDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x100D08F0
// Name: FindPlayer
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindPlayer(CMapEntity *pObject)
{
  int result; // eax

  if ( Options.general.bCheckVisibleMapErrors != 0 && (*((_BYTE *)&pObject->CMapClass + 180) & 2) == 0 )
    return 1;
  if ( (pObject->flags & 1) == 0 )
    return 1;
  if ( pObject->m_pClass == nullptr )
    return 1;
  result = _V_stricmp(s1: "info_player_start", s2: pObject->m_szClass);
  if ( result != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D0940
// Name: bool FindDuplicateNodeID(class CMapEntity __near *,class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindDuplicateNodeID(CMapEntity *pNode, CMapWorld *pWorld)
{
  CMapClass *FirstDescendent; // eax
  CMapEntity *v4; // eax
  CMapEntity *v5; // esi
  GDclass *m_pClass; // eax
  const char *m_szName; // edi
  int NodeID; // edi
  int v9; // eax
  EnumChildrenPos_t pos; // [esp+4h] [ebp-84h] BYREF

  if ( Options.general.bCheckVisibleMapErrors != 0 && (*((_BYTE *)&pNode->CMapClass + 180) & 2) == 0 )
    return 0;
  FirstDescendent = CMapClass::GetFirstDescendent(this: pWorld, (CMapClass *)&pos);
  if ( FirstDescendent == nullptr )
    return 0;
  while ( 1 )
  {
    v4 = (CMapEntity *)__RTDynamicCast(
                         inptr: FirstDescendent,
                         VfDelta: 0,
                         SrcType: &CMapClass `RTTI Type Descriptor',
                         TargetType: &CMapEntity `RTTI Type Descriptor',
                         isReference: 0);
    v5 = v4;
    if ( v4 != nullptr
      && (Options.general.bCheckVisibleMapErrors == 0 || (*((_BYTE *)&v4->CMapClass + 180) & 2) != 0)
      && v4 != pNode )
    {
      m_pClass = v4->m_pClass;
      if ( m_pClass != nullptr )
      {
        m_szName = m_pClass->m_szName;
        if ( V_strncasecmp(s1: m_pClass->m_szName, s2: "info_node", n: 9) == 0
          && _V_stricmp(s1: m_szName, s2: "info_node_link") != 0 )
        {
          NodeID = CMapEntity::GetNodeID(this: pNode);
          v9 = CMapEntity::GetNodeID(this: v5);
          if ( NodeID != 0 && v9 != 0 && NodeID == v9 )
            break;
        }
      }
    }
    FirstDescendent = CMapClass::GetNextDescendent(this: pWorld, (CMapClass *)&pos);
    if ( FirstDescendent == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D0A30
// Name: FixEmptyEntity
// Source: json
//------------------------------------------------------------------------------
void __usercall FixEmptyEntity(MapError *pError@<eax>)
{
  CMapClass *v1; // esi
  CHistory *History; // eax
  int v3; // eax

  v1 = pError->pObjects[0];
  if ( pError->pObjects[0]->GetParent(this: pError->pObjects[0]) != nullptr )
  {
    History = GetHistory();
    CHistory::KeepForDestruction(this: History, pObject: v1);
    v3 = (int)v1->GetParent(this: v1);
    (*(void (__thiscall **)(int, CMapClass *, int))(*(_DWORD *)v3 + 116))(a1: v3, a2: v1, a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0A70
// Name: protected: void CMapCheckDlg::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCheckDlg::OnDestroy(CMapCheckDlg *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CMapCheckDlg *, int))this->dtr_CObject)(a1: this, a2: 1);
  s_pDlg = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100D0AB0
// Name: private: CMapCheckDlg::CMapCheckDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CMapCheckDlg *__thiscall CMapCheckDlg::CMapCheckDlg(CMapCheckDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0xCAu, pParentWnd: pParent);
  this->__vftable = (CMapCheckDlg_vtbl *)&CMapCheckDlg::`vftable';
  CWnd::CWnd(this: &this->m_cFixAll);
  this->m_cFixAll.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_Fix);
  this->m_Fix.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_Go);
  this->m_Go.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_Description);
  this->m_Description.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_Errors);
  this->m_Errors.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  this->m_bCheckVisible = 0;
  this->m_bCheckVisible = Options.general.bCheckVisibleMapErrors;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D0BC0
// Name: public: virtual CMapCheckDlg::~CMapCheckDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCheckDlg::~CMapCheckDlg(CMapCheckDlg *this)
{
  CListBox::~CListBox(this: &this->m_Errors);
  CEdit::~CEdit(this: &this->m_Description);
  CButton::~CButton(this: &this->m_Go);
  CButton::~CButton(this: &this->m_Fix);
  CButton::~CButton(this: &this->m_cFixAll);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D0C80
// Name: protected: virtual void CMapCheckDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCheckDlg::DoDataExchange(CMapCheckDlg *this, CDataExchange *pDX)
{
  int *p_m_bCheckVisible; // esi

  DDX_Control(pDX, nIDC: (HWND__ *)0x4FE, rControl: (HWND__ *)&this->m_cFixAll);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4FD, rControl: (HWND__ *)&this->m_Fix);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4A3, rControl: (HWND__ *)&this->m_Go);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_Description);
  DDX_Control(pDX, nIDC: (HWND__ *)0x462, rControl: (HWND__ *)&this->m_Errors);
  p_m_bCheckVisible = &this->m_bCheckVisible;
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x635, value: p_m_bCheckVisible);
  if ( pDX->m_bSaveAndValidate != 0 )
    Options.general.bCheckVisibleMapErrors = *p_m_bCheckVisible;
}

//------------------------------------------------------------------------------
// Address: 0x100D0D10
// Name: private: void CMapCheckDlg::KillErrorList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCheckDlg::KillErrorList(CMapCheckDlg *this)
{
  LRESULT v2; // ebx
  signed int i; // esi
  void *v4; // eax

  v2 = SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
  for ( i = 0; i < v2; ++i )
  {
    v4 = (void *)SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x199u, wParam: i, lParam: 0);
    operator delete(p: v4);
  }
  SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100D0D70
// Name: HasVisGroupHiddenChildren
// Source: json
//------------------------------------------------------------------------------
char __usercall HasVisGroupHiddenChildren@<al>(CMapClass *pObject@<eax>)
{
  int v1; // edx
  CUtlReference<CMapClass> **m_pMemory; // edi
  int v3; // ecx
  int v4; // esi
  int v5; // ecx
  int v6; // esi
  CMapClass *m_pObject; // eax
  int m_Size; // [esp+Ch] [ebp-4h]

  v1 = 0;
  m_Size = pObject->m_Children.m_Size;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = pObject->m_Children.m_Memory.m_pMemory;
  v3 = *((_DWORD *)&pObject->m_Children.m_Memory + 2);
  v4 = 32 * v3;
  v5 = v3 >> 27;
  v6 = v4 >> 5;
  while ( 1 )
  {
    m_pObject = m_pMemory[v1 >> v5][v1 & v6].m_pObject;
    if ( !m_pObject->m_bVisGroupShown || !m_pObject->m_bVisGroupAutoShown )
      break;
    if ( ++v1 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D0DE0
// Name: HasVisGroupShownChildren
// Source: json
//------------------------------------------------------------------------------
char __usercall HasVisGroupShownChildren@<al>(CMapClass *pObject@<eax>)
{
  int v1; // edx
  CUtlReference<CMapClass> **m_pMemory; // edi
  int v3; // ecx
  int v4; // esi
  int v5; // ecx
  int v6; // esi
  CMapClass *m_pObject; // eax
  int m_Size; // [esp+Ch] [ebp-4h]

  v1 = 0;
  m_Size = pObject->m_Children.m_Size;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = pObject->m_Children.m_Memory.m_pMemory;
  v3 = *((_DWORD *)&pObject->m_Children.m_Memory + 2);
  v4 = 32 * v3;
  v5 = v3 >> 27;
  v6 = v4 >> 5;
  while ( 1 )
  {
    m_pObject = m_pMemory[v1 >> v5][v1 & v6].m_pObject;
    if ( m_pObject->m_bVisGroupShown && m_pObject->m_bVisGroupAutoShown )
      break;
    if ( ++v1 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D0E50
// Name: int DoesContainDuplicates(class CMapSolid __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DoesContainDuplicates(CMapSolid *pSolid)
{
  const char *v2; // edi
  int v3; // ecx
  unsigned int v4; // esi
  PLANE *p_plane; // edi
  const char *v6; // esi
  int v7; // ecx
  unsigned int v8; // edi
  CMapFace *v9; // eax
  int v10; // edx
  const char *v11; // eax
  Vector *pts1; // [esp+10h] [ebp-8h]
  int iFaces; // [esp+14h] [ebp-4h]
  int i; // [esp+20h] [ebp+8h]

  v2 = nullptr;
  iFaces = pSolid->Faces.nCount;
  i = 0;
  if ( iFaces <= 0 )
    return 0;
LABEL_2:
  if ( (int)v2 >= pSolid->Faces.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v2, pSolid->Faces.nCount);
    v3 = (int)(v2 + 1);
    if ( v2 + 1 != (const char *)pSolid->Faces.nCount )
    {
      v4 = v3 / 6;
      if ( 6 * (v3 / 6) < v3 )
        ++v4;
      if ( v4 != pSolid->Faces.nBlocks )
      {
        if ( v4 > 0x57 )
          _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
        BlockArray<CMapFace,6,86>::GetBlocks(this: &pSolid->Faces, nNewBlocks: v4);
      }
      pSolid->Faces.nCount = (_WORD)v2 + 1;
    }
  }
  p_plane = &pSolid->Faces.Blocks[(int)v2 / 6][(int)v2 % 6].plane;
  pts1 = &p_plane->normal;
  v6 = nullptr;
  while ( 1 )
  {
    if ( v6 != (const char *)i )
    {
      if ( (int)v6 >= pSolid->Faces.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v6, pSolid->Faces.nCount);
        v7 = (int)(v6 + 1);
        if ( v6 + 1 != (const char *)pSolid->Faces.nCount )
        {
          v8 = v7 / 6;
          if ( 6 * (v7 / 6) < v7 )
            ++v8;
          if ( v8 != pSolid->Faces.nBlocks )
          {
            if ( v8 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: &pSolid->Faces, nNewBlocks: v8);
          }
          p_plane = (PLANE *)pts1;
          pSolid->Faces.nCount = (_WORD)v6 + 1;
        }
      }
      v9 = pSolid->Faces.Blocks[(int)v6 / 6];
      v10 = (int)v6 % 6;
      if ( v9[v10].plane.normal.x == p_plane->normal.x
        && v9[v10].plane.normal.y == p_plane->normal.y
        && v9[v10].plane.normal.z == p_plane->normal.z )
      {
        return 1;
      }
    }
    if ( (int)++v6 >= iFaces )
    {
      v11 = (const char *)(i + 1);
      i = (int)v11;
      if ( (int)v11 >= iFaces )
        return 0;
      v2 = v11;
      goto LABEL_2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1040
// Name: FixDuplicatePlanes
// Source: json
//------------------------------------------------------------------------------
void __usercall FixDuplicatePlanes(MapError *pError@<eax>)
{
  int v1; // edi
  int v2; // ecx
  unsigned int v3; // esi
  const char *v4; // esi
  float *p_x; // edi
  int v6; // ecx
  unsigned int v7; // edi
  CMapFace *v8; // edx
  int v9; // ecx
  float x; // xmm0_4
  int p_plane; // ecx
  Vector *pts1; // [esp+10h] [ebp-10h]
  CMapSolid *pSolid; // [esp+14h] [ebp-Ch]
  int iFaces; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  pSolid = (CMapSolid *)pError->pObjects[0];
ReStart:
  v1 = 0;
  iFaces = pSolid->Faces.nCount;
  i = 0;
  while ( v1 < iFaces )
  {
    if ( v1 >= pSolid->Faces.nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v1, pSolid->Faces.nCount);
      v2 = v1 + 1;
      if ( v1 + 1 != pSolid->Faces.nCount )
      {
        v3 = v2 / 6;
        if ( 6 * (v2 / 6) < v2 )
          ++v3;
        if ( v3 != pSolid->Faces.nBlocks )
        {
          if ( v3 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: &pSolid->Faces, nNewBlocks: v3);
        }
        pSolid->Faces.nCount = v1 + 1;
      }
    }
    v4 = nullptr;
    p_x = &pSolid->Faces.Blocks[v1 / 6][v1 % 6].plane.normal.x;
    pts1 = (Vector *)p_x;
    if ( iFaces > 0 )
    {
      while ( 1 )
      {
        if ( v4 != (const char *)i )
        {
          if ( (int)v4 >= pSolid->Faces.nCount )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v4, pSolid->Faces.nCount);
            v6 = (int)(v4 + 1);
            if ( v4 + 1 != (const char *)pSolid->Faces.nCount )
            {
              v7 = v6 / 6;
              if ( 6 * (v6 / 6) < v6 )
                ++v7;
              if ( v7 != pSolid->Faces.nBlocks )
              {
                if ( v7 > 0x57 )
                  _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
                BlockArray<CMapFace,6,86>::GetBlocks(this: &pSolid->Faces, nNewBlocks: v7);
              }
              p_x = &pts1->x;
              pSolid->Faces.nCount = (_WORD)v4 + 1;
            }
          }
          v8 = pSolid->Faces.Blocks[(int)v4 / 6];
          v9 = (int)v4 % 6;
          x = v8[v9].plane.normal.x;
          p_plane = (int)&v8[v9].plane;
          if ( x == *p_x && *(float *)(p_plane + 4) == p_x[1] && *(float *)(p_plane + 8) == p_x[2] )
            break;
        }
        if ( (int)++v4 >= iFaces )
          goto LABEL_28;
      }
      CMapSolid::DeleteFace(this: pSolid, iIndex: v4);
      goto ReStart;
    }
LABEL_28:
    v1 = ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1240
// Name: FixSolidStructure
// Source: json
//------------------------------------------------------------------------------
void __usercall FixSolidStructure(MapError *pError@<eax>)
{
  CMapSolid *v1; // ebx
  int v2; // edi
  int v3; // esi
  unsigned int v4; // esi
  CMapFace *v5; // esi
  int i; // [esp+Ch] [ebp-4h]

  v1 = (CMapSolid *)pError->pObjects[0];
  v2 = *((__int16 *)&pError->pObjects[0][2].m_Children.m_Memory + 4) - 1;
  if ( v2 >= 0 )
  {
    v3 = *((__int16 *)&pError->pObjects[0][2].m_Children.m_Memory + 4);
    for ( i = v3; ; v3 = i )
    {
      if ( v2 >= v1->Faces.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v2, v1->Faces.nCount);
        if ( v3 != v1->Faces.nCount )
        {
          v4 = v3 / 6;
          if ( (int)(6 * v4) < i )
            ++v4;
          if ( v4 != v1->Faces.nBlocks )
          {
            if ( v4 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: &v1->Faces, nNewBlocks: v4);
          }
          v1->Faces.nCount = i;
        }
      }
      v5 = &v1->Faces.Blocks[v2 / 6u][v2 % 6u];
      if ( CMapFace::CheckFace(this: v5, pInfo: nullptr) == 0 )
        CMapFace::Fix(this: v5);
      if ( v5->nPoints == 0 )
        CMapSolid::DeleteFace(this: v1, iIndex: (const char *)v2);
      --i;
      if ( --v2 < 0 )
        break;
    }
  }
  CMapSolid::CreateFromPlanes(this: v1, dwFlags: 0);
  v1->PostUpdate(this: v1, a2: Notify_Changed);
}

//------------------------------------------------------------------------------
// Address: 0x100D1350
// Name: FixInvalidTexture
// Source: json
//------------------------------------------------------------------------------
void __usercall FixInvalidTexture(MapError *pError@<eax>)
{
  CMapClass *v1; // eax
  int v2; // edi
  BlockArray<CMapFace,6,86> *v3; // esi
  int v4; // ebx
  unsigned int v5; // esi
  CMapFace *v6; // esi
  IEditorTexture *m_pTexture; // ecx
  const char *DefaultTextureName; // eax
  int nFaces; // [esp+8h] [ebp-8h]
  BlockArray<CMapFace,6,86> *i; // [esp+Ch] [ebp-4h]

  v1 = pError->pObjects[0];
  v2 = 0;
  nFaces = *((__int16 *)&v1[2].m_Children.m_Memory + 4);
  if ( nFaces > 0 )
  {
    v3 = (BlockArray<CMapFace,6,86> *)&v1[1];
    for ( i = (BlockArray<CMapFace,6,86> *)&v1[1]; ; v3 = i )
    {
      if ( v2 >= v3->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v2, v3->nCount);
        v4 = v2 + 1;
        if ( v2 + 1 != v3->nCount )
        {
          v5 = v4 / 6;
          if ( 6 * (v4 / 6) < v4 )
            ++v5;
          if ( v5 != i->nBlocks )
          {
            if ( v5 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: i, nNewBlocks: v5);
          }
          i->nCount = v4;
        }
      }
      v6 = &i->Blocks[v2 / 6u][v2 % 6u];
      if ( v6 != nullptr )
      {
        m_pTexture = v6->m_pTexture;
        if ( m_pTexture != nullptr && m_pTexture->IsDummy(this: m_pTexture) )
        {
          DefaultTextureName = GetDefaultTextureName();
          CMapFace::SetTexture(this: v6, pszNewTex: DefaultTextureName, bRescaleTextureCoordinates: false);
        }
      }
      if ( ++v2 >= nFaces )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1460
// Name: FixInvalidTextureAxes
// Source: json
//------------------------------------------------------------------------------
void __usercall FixInvalidTextureAxes(MapError *pError@<eax>)
{
  CMapClass *v1; // eax
  int v2; // edi
  BlockArray<CMapFace,6,86> *v3; // esi
  int v4; // ebx
  unsigned int v5; // esi
  CMapFace *v6; // esi
  TextureAlignment_t Id; // eax
  int nFaces; // [esp+8h] [ebp-8h]
  BlockArray<CMapFace,6,86> *i; // [esp+Ch] [ebp-4h]

  v1 = pError->pObjects[0];
  v2 = 0;
  nFaces = *((__int16 *)&v1[2].m_Children.m_Memory + 4);
  if ( nFaces > 0 )
  {
    v3 = (BlockArray<CMapFace,6,86> *)&v1[1];
    for ( i = (BlockArray<CMapFace,6,86> *)&v1[1]; ; v3 = i )
    {
      if ( v2 >= v3->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v2, v3->nCount);
        v4 = v2 + 1;
        if ( v2 + 1 != v3->nCount )
        {
          v5 = v4 / 6;
          if ( 6 * (v4 / 6) < v4 )
            ++v5;
          if ( v5 != i->nBlocks )
          {
            if ( v5 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: i, nNewBlocks: v5);
          }
          i->nCount = v4;
        }
      }
      v6 = &i->Blocks[v2 / 6u][v2 % 6u];
      if ( CMapFace::IsTextureAxisValid(this: v6) == 0 )
      {
        Id = CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&Options);
        CMapFace::InitializeTextureAxes(this: v6, eAlignment: Id, dwFlags: 3u);
      }
      if ( ++v2 >= nFaces )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1560
// Name: FixInvalidContents
// Source: json
//------------------------------------------------------------------------------
void __usercall FixInvalidContents(MapError *pError@<eax>)
{
  CMapClass *v1; // esi
  __int16 v2; // ax
  BlockArray<CMapFace,6,86> *v3; // ebx
  int v4; // edi
  int v5; // esi
  int v6; // ecx
  unsigned int v7; // edi
  CMapFace *v8; // edx
  unsigned int v9; // ecx
  unsigned int dwContents; // [esp+10h] [ebp-8h]
  int nFaces; // [esp+14h] [ebp-4h]

  v1 = pError->pObjects[0];
  v2 = *((_WORD *)&pError->pObjects[0][2].m_Children.m_Memory + 4);
  v3 = (BlockArray<CMapFace,6,86> *)&v1[1];
  if ( v2 <= 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: nullptr, v2);
    BlockArray<CMapFace,6,86>::SetCount(this: (BlockArray<CMapFace,6,86> *)&v1[1], nObjects: 1);
  }
  v4 = *((__int16 *)&v1[2].m_Children.m_Memory + 4);
  v5 = 1;
  dwContents = v3->Blocks[0]->texture.q2contents;
  for ( nFaces = v4; v5 < v4; v8[v9].texture.q2contents = dwContents )
  {
    if ( v5 >= v3->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v5, v3->nCount);
      v6 = v5 + 1;
      if ( v5 + 1 != v3->nCount )
      {
        v7 = v6 / 6;
        if ( 6 * (v6 / 6) < v6 )
          ++v7;
        if ( v7 != v3->nBlocks )
        {
          if ( v7 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: v3, nNewBlocks: v7);
        }
        v4 = nFaces;
        v3->nCount = v5 + 1;
      }
    }
    v8 = v3->Blocks[v5 / 6u];
    v9 = v5++ % 6u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1680
// Name: protected: void CMapCheckDlg::OnSelchangeErrors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCheckDlg::OnSelchangeErrors(CMapCheckDlg *this)
{
  WPARAM v2; // edi
  CAfxStringMgr *StringManager; // eax
  CMapClass **v4; // edi
  int v5; // eax
  unsigned int v6; // ebx
  HINSTANCE__ *StringResourceHandle; // eax
  CMapClass *v8; // eax
  int v9; // eax
  CMapDoc *v10; // esi
  CMapClass *v11; // edi
  char *v12; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+Ch] [ebp-10h] BYREF
  int v14; // [esp+18h] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  if ( v2 == -1 )
  {
    CWnd::EnableWindow(this: &this->m_Fix, bEnable: 0);
    CWnd::EnableWindow(this: &this->m_cFixAll, bEnable: 0);
    CWnd::EnableWindow(this: &this->m_Go, bEnable: 0);
  }
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v14 = 1;
  v4 = (CMapClass **)SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
  v5 = (int)v4[3];
  if ( v5 >= 0 )
  {
    if ( (unsigned int)v5 > 0x15 )
      v5 = 21;
  }
  else
  {
    v5 = 0;
  }
  v6 = nID[2 * v5];
  StringResourceHandle = AfxFindStringResourceHandle(__formal: v6);
  if ( StringResourceHandle != nullptr )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: &str,
      hInstance: StringResourceHandle,
      nID: v6);
  CWnd::SetWindowTextA(this: &this->m_Description, lpszString: str.m_pszData);
  CWnd::EnableWindow(this: &this->m_Go, bEnable: *v4 != nullptr);
  CWnd::EnableWindow(this: &this->m_Fix, bEnable: v4[5] == (CMapClass *)1);
  CWnd::EnableWindow(this: &this->m_cFixAll, bEnable: v4[5] != nullptr);
  v8 = v4[5];
  if ( v8 != nullptr )
  {
    v9 = (int)&v8[-1].m_nDropTraceMarker + 3;
    if ( v9 != 0 )
    {
      if ( v9 == 1 )
        CWnd::SetWindowTextA(this: &this->m_Fix, lpszString: "(fixed)");
    }
    else
    {
      CWnd::SetWindowTextA(this: &this->m_Fix, lpszString: "&Fix");
    }
  }
  else
  {
    CWnd::SetWindowTextA(this: &this->m_Fix, lpszString: "Can't fix");
  }
  v10 = CMapDoc::m_pMapDoc;
  CSelection::SetMode(this: CMapDoc::m_pMapDoc->m_pSelection, eNewSelectMode: selectObjects);
  v11 = *v4;
  if ( v11 != nullptr )
    CMapDoc::SelectObject(this: v10, pObj: v11, cmd: 1042);
  else
    CMapDoc::SelectObject(this: v10, pObj: nullptr, cmd: 1040);
  v14 = -1;
  v12 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v12 + 4))(a1: v12);
}

//------------------------------------------------------------------------------
// Address: 0x100D1840
// Name: AddErrorToListBox
// Source: json
//------------------------------------------------------------------------------
void __usercall AddErrorToListBox(MapError *pError@<edi>, CListBox *pList)
{
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // esi
  MapErrorType Type; // eax
  unsigned int m_StrResourceID; // ebx
  HINSTANCE__ *StringResourceHandle; // eax
  int v7; // eax
  const char *v8; // esi
  WPARAM v9; // eax
  ATL::CStringData *v10; // [esp-Ch] [ebp-20h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+4h] [ebp-10h] BYREF
  int v12; // [esp+10h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  str.m_pszData = m_pszData;
  v12 = 1;
  Type = pError->Type;
  if ( Type >= ErrorNoPlayerStart )
  {
    if ( (unsigned int)Type > ErrorOverlayFaceList )
      Type = ErrorOverlayFaceList;
  }
  else
  {
    Type = ErrorNoPlayerStart;
  }
  m_StrResourceID = g_MapErrorStrings[Type].m_StrResourceID;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: m_StrResourceID);
  if ( StringResourceHandle != nullptr )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: &str,
      hInstance: StringResourceHandle,
      nID: m_StrResourceID);
    m_pszData = str.m_pszData;
  }
  if ( *((int *)m_pszData - 3) > 0 )
  {
    _mbschr(string: m_pszData, c: 0x25u);
    if ( v7 != 0 && v7 - (_DWORD)m_pszData != -1 )
    {
      v10 = (ATL::CStringData *)(m_pszData - 16);
      if ( pError->Type == ErrorUnusedKeyvalues )
      {
        v8 = (const char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: v10)[1];
        LOBYTE(v12) = 3;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
          this: &str,
          pszFormat: v8,
          &pError->pObjects[0][1].___u2,
          pError->dwExtra);
      }
      else
      {
        v8 = (const char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: v10)[1];
        LOBYTE(v12) = 6;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &str, pszFormat: v8, pError->dwExtra);
      }
      LOBYTE(v12) = 1;
      if ( _InterlockedDecrement((volatile signed __int32 *)v8 - 1) <= 0 )
        (*(void (__thiscall **)(_DWORD, const char *))(**((_DWORD **)v8 - 4) + 4))(a1: *((_DWORD *)v8 - 4), a2: v8 - 16);
      m_pszData = str.m_pszData;
    }
  }
  v9 = SendMessageA(hWnd: pList->m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)m_pszData);
  SendMessageA(hWnd: pList->m_hWnd, Msg: 0x19Au, wParam: v9, lParam: (LPARAM)pError);
  v12 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**((_DWORD **)m_pszData - 4) + 4))(a1: m_pszData - 16);
}

//------------------------------------------------------------------------------
// Address: 0x100D19C0
// Name: AddError
// Source: json
//------------------------------------------------------------------------------
void __usercall AddError(int Type@<esi>, CListBox *pList, unsigned int dwExtra, CMapClass *a4, unsigned int a5)
{
  MapError *v5; // eax

  v5 = (MapError *)operator new(nSize: 0x18u);
  *(_QWORD *)v5->pObjects = 0;
  *(_QWORD *)&v5->pObjects[2] = 0;
  *(_QWORD *)&v5->dwExtra = 0;
  v5->dwExtra = dwExtra;
  v5->Type = Type;
  v5->Fix = CantFix;
  switch ( Type )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 21:
      v5->pObjects[0] = a4;
      break;
    case 20:
      v5->pObjects[0] = a4;
      v5->dwExtra = a5;
      break;
    default:
      break;
  }
  if ( Type >= 2 && Type <= 21 )
    v5->Fix = NeedsFix;
  AddErrorToListBox(pError: v5, pList);
}

//------------------------------------------------------------------------------
// Address: 0x100D1BC0
// Name: CheckDuplicateNodeIDs
// Source: json
//------------------------------------------------------------------------------
void __usercall CheckDuplicateNodeIDs(unsigned int a1@<edi>, CListBox *pList, CMapWorld *pWorld)
{
  CMapClass *FirstDescendent; // eax
  CMapEntity *v4; // eax
  CMapEntity *v5; // esi
  GDclass *m_pClass; // eax
  const char *m_szName; // edi
  unsigned int v8; // [esp-8h] [ebp-90h]
  EnumChildrenPos_t pos; // [esp+4h] [ebp-84h] BYREF

  FirstDescendent = CMapClass::GetFirstDescendent(this: pWorld, (CMapClass *)&pos);
  if ( FirstDescendent != nullptr )
  {
    v8 = a1;
    do
    {
      v4 = (CMapEntity *)__RTDynamicCast(
                           inptr: FirstDescendent,
                           VfDelta: 0,
                           SrcType: &CMapClass `RTTI Type Descriptor',
                           TargetType: &CMapEntity `RTTI Type Descriptor',
                           isReference: 0);
      v5 = v4;
      if ( v4 != nullptr )
      {
        m_pClass = v4->m_pClass;
        if ( m_pClass != nullptr )
        {
          m_szName = m_pClass->m_szName;
          if ( V_strncasecmp(s1: m_pClass->m_szName, s2: "info_node", n: 9) == 0
            && _V_stricmp(s1: m_szName, s2: "info_node_link") != 0
            && FindDuplicateNodeID(pNode: v5, pWorld) != 0 )
          {
            AddError(Type: 12, pList, dwExtra: (unsigned int)pWorld, a4: v5, a5: v8);
          }
        }
      }
      FirstDescendent = CMapClass::GetNextDescendent(this: pWorld, (CMapClass *)&pos);
    }
    while ( FirstDescendent != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1C80
// Name: _CheckDuplicateFaceIDs
// Source: json
//------------------------------------------------------------------------------
int __cdecl CheckDuplicateFaceIDs(CMapSolid *pSolid, CUtlMemory<CCullTreeNode *,int> *pData)
{
  int v2; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // ebx
  int v4; // ecx
  unsigned int v5; // esi
  unsigned int v6; // edi
  int m_pMemory; // esi
  int v8; // edx
  int v9; // eax
  CMapFace **v10; // ecx
  int m_nAllocationCount; // eax
  CMapFace **v12; // ecx
  int v13; // eax
  CMapFace **v14; // esi
  CUtlMemory<CCullTreeNode *,int> *v16; // esi
  int v17; // eax
  CCullTreeNode **v18; // ecx
  int m_nGrowSize; // ebx
  int v20; // eax
  CCullTreeNode **v21; // ecx
  int v22; // eax
  unsigned int *v23; // ebx
  int nFaceCount; // [esp+4h] [ebp-10h]
  CMapFace **v25; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( Options.general.bCheckVisibleMapErrors != 0 && (*((_BYTE *)&pSolid->CMapClass + 180) & 2) == 0 )
    return 1;
  v2 = 0;
  nFaceCount = pSolid->Faces.nCount;
  i = 0;
  if ( nFaceCount <= 0 )
    return 1;
  p_Faces = &pSolid->Faces;
  while ( 2 )
  {
    if ( v2 >= p_Faces->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v2, p_Faces->nCount);
      v4 = v2 + 1;
      if ( v2 + 1 != p_Faces->nCount )
      {
        v5 = v4 / 6;
        if ( 6 * (v4 / 6) < v4 )
          ++v5;
        if ( v5 != p_Faces->nBlocks )
        {
          if ( v5 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: p_Faces, nNewBlocks: v5);
        }
        p_Faces->nCount = v2 + 1;
      }
    }
    v6 = (unsigned int)&p_Faces->Blocks[v2 / 6u][v2 % 6u];
    m_pMemory = (int)pData[1].m_pMemory;
    v8 = *(_DWORD *)(v6 + 412);
    v9 = 0;
    if ( m_pMemory <= 0 )
    {
LABEL_21:
      m_nAllocationCount = pData->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CVisGroup *,int>::Grow(this: pData, num: m_pMemory - m_nAllocationCount + 1);
      ++pData[1].m_pMemory;
      v12 = (CMapFace **)pData->m_pMemory;
      v13 = (int)pData[1].m_pMemory - m_pMemory - 1;
      pData[1].m_nAllocationCount = (int)pData->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 4 * v13);
      v14 = (CMapFace **)&pData->m_pMemory[m_pMemory];
      if ( v14 != nullptr )
        *v14 = (CMapFace *)v6;
      goto LABEL_27;
    }
    v10 = (CMapFace **)pData->m_pMemory;
    v25 = (CMapFace **)pData->m_pMemory;
    while ( *v10 == nullptr )
    {
LABEL_20:
      ++v9;
      v25 = ++v10;
      if ( v9 >= m_pMemory )
        goto LABEL_21;
    }
    if ( (*v10)->m_nFaceID != v8 )
    {
      v10 = v25;
      goto LABEL_20;
    }
    if ( v9 == -1 )
      goto LABEL_21;
    v16 = (CUtlMemory<CCullTreeNode *,int> *)((char *)pData + 20);
    v17 = 0;
    if ( pData[2].m_nGrowSize > 0 )
    {
      v18 = v16->m_pMemory;
      while ( *v18 == nullptr || LODWORD((*v18)[6].bmins.x) != v8 )
      {
        ++v17;
        ++v18;
        if ( v17 >= pData[2].m_nGrowSize )
          goto LABEL_27;
      }
      if ( v17 != -1 )
      {
        m_nGrowSize = pData[2].m_nGrowSize;
        v20 = (int)pData[2].m_pMemory;
        if ( m_nGrowSize + 1 > v20 )
          CUtlMemory<CVisGroup *,int>::Grow(this: v16, num: m_nGrowSize - v20 + 1);
        ++pData[2].m_nGrowSize;
        v21 = v16->m_pMemory;
        v22 = pData[2].m_nGrowSize - m_nGrowSize - 1;
        pData[3].m_pMemory = (CCullTreeNode **)pData[1].m_nGrowSize;
        if ( v22 > 0 )
          _V_memmove(dest: &v21[m_nGrowSize + 1], src: &v21[m_nGrowSize], count: 4 * v22);
        v23 = (unsigned int *)&v16->m_pMemory[m_nGrowSize];
        if ( v23 != nullptr )
          *v23 = v6;
      }
    }
LABEL_27:
    if ( ++i < nFaceCount )
    {
      p_Faces = &pSolid->Faces;
      v2 = i;
      continue;
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1E90
// Name: public: FindDuplicateFaceIDs_t::~FindDuplicateFaceIDs_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FindDuplicateFaceIDs_t::~FindDuplicateFaceIDs_t(FindDuplicateFaceIDs_t *this)
{
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&this->Duplicates);
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>((TextureWindowTexList *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100D24A0
// Name: CheckDuplicateFaceIDs
// Source: json
//------------------------------------------------------------------------------
void __usercall CheckDuplicateFaceIDs(unsigned int a1@<esi>, CListBox *pList, CMapWorld *pWorld)
{
  int v3; // edi
  CMapFace *v4; // esi
  CMapClass *v5; // eax
  CMapFace **m_pMemory; // eax
  CMapFace **v7; // eax
  unsigned int v8; // [esp-4h] [ebp-44h]
  FindDuplicateFaceIDs_t Lists; // [esp+8h] [ebp-38h] BYREF
  CMapFaceList *p_Duplicates; // [esp+30h] [ebp-10h]
  int v11; // [esp+3Ch] [ebp-4h]

  Lists.All.m_Memory.m_pMemory = nullptr;
  Lists.All.m_Memory.m_nAllocationCount = 0;
  memset(&Lists.All.m_Size, 0, 16);
  p_Duplicates = &Lists.Duplicates;
  Lists.Duplicates.m_Size = 0;
  Lists.Duplicates.m_pElements = nullptr;
  v11 = 6;
  Lists.All.m_Memory.m_nGrowSize = 128;
  Lists.Duplicates.m_Memory.m_nGrowSize = 128;
  CMapClass::EnumChildren(
    this: pWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CheckDuplicateFaceIDs,
    dwParam: (unsigned int)&Lists,
    Type: CMapSolid::__Type);
  v3 = 0;
  if ( Lists.Duplicates.m_Size > 0 )
  {
    v8 = a1;
    do
    {
      v4 = Lists.Duplicates.m_Memory.m_pMemory[v3];
      v5 = (CMapClass *)v4->GetParent(this: v4);
      AddError(Type: 11, pList, dwExtra: (unsigned int)v4, a4: v5, a5: v8);
      ++v3;
    }
    while ( v3 < Lists.Duplicates.m_Size );
  }
  v11 = 10;
  p_Duplicates = &Lists.Duplicates;
  m_pMemory = Lists.Duplicates.m_Memory.m_pMemory;
  Lists.Duplicates.m_Size = 0;
  if ( Lists.Duplicates.m_Memory.m_nGrowSize >= 0 )
  {
    if ( Lists.Duplicates.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: Lists.Duplicates.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      Lists.Duplicates.m_Memory.m_pMemory = nullptr;
    }
    Lists.Duplicates.m_Memory.m_nAllocationCount = 0;
  }
  Lists.Duplicates.m_pElements = m_pMemory;
  LOBYTE(v11) = 7;
  if ( Lists.Duplicates.m_Memory.m_nGrowSize >= 0 )
  {
    if ( Lists.Duplicates.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: Lists.Duplicates.m_Memory.m_pMemory);
      Lists.Duplicates.m_Memory.m_pMemory = nullptr;
    }
    Lists.Duplicates.m_Memory.m_nAllocationCount = 0;
  }
  v11 = 12;
  v7 = Lists.All.m_Memory.m_pMemory;
  Lists.All.m_Size = 0;
  if ( Lists.All.m_Memory.m_nGrowSize >= 0 )
  {
    if ( Lists.All.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: Lists.All.m_Memory.m_pMemory);
      v7 = nullptr;
      Lists.All.m_Memory.m_pMemory = nullptr;
    }
    Lists.All.m_Memory.m_nAllocationCount = 0;
  }
  Lists.All.m_pElements = v7;
  v11 = -1;
  if ( Lists.All.m_Memory.m_nGrowSize >= 0 && Lists.All.m_Memory.m_pMemory != nullptr )
    free(pMem: Lists.All.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100D2840
// Name: FixUnusedKeyvalues
// Source: json
//------------------------------------------------------------------------------
void __usercall FixUnusedKeyvalues(MapError *pError@<eax>)
{
  CMapClass *v1; // edi
  unsigned __int16 Inorder; // si
  unsigned __int16 v3; // ax
  int v4; // esi
  int v5; // ebx
  GDclass *pClass; // [esp+4h] [ebp-4h]

  v1 = pError->pObjects[0];
  pClass = (GDclass *)pError->pObjects[0][1].m_References.m_pHead;
  if ( pClass != nullptr )
  {
    Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v1[1].m_nObjectID);
    if ( Inorder != 0xFFFF )
    {
      do
      {
        v3 = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
               this: (CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v1[1].m_nObjectID,
               i: Inorder);
        v4 = 604 * Inorder;
        v5 = v3;
        if ( GDclass::VarForName(
               this: pClass,
               pszName: (const char *)&v1[1].m_pParent->CMapPoint::m_eSelectionState + v4,
               piIndex: nullptr) == nullptr )
          ((void (__thiscall *)(CMapClass *, int))v1[1].GetSelectionState)(
            a1: &v1[1],
            a2: (int)&v1[1].m_pParent->CMapPoint::m_eSelectionState + v4);
        Inorder = v5;
      }
      while ( v5 != 0xFFFF );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D28D0
// Name: FixOverlayFaceList
// Source: json
//------------------------------------------------------------------------------
void __cdecl FixOverlayFaceList(MapError *pError)
{
  CMapClass *v1; // esi
  int v2; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v4; // ecx
  void *v5; // edx
  CHistory *History; // eax
  CUtlReference<CMapClass> *m_pHead; // [esp+8h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v8; // [esp+Ch] [ebp-14h]
  void *inptr; // [esp+10h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-4h]

  v1 = pError->pObjects[0];
  if ( pError->pObjects[0] != nullptr )
  {
    v2 = 0;
    if ( v1->m_Children.m_Size > 0 )
    {
      while ( 1 )
      {
        m_pObject = v1->m_Children.m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&v1->m_Children.m_Memory + 2) >> 27)][v2 & ((32 * *((_DWORD *)&v1->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr )
        {
          inptr = v1->m_Children.m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&v1->m_Children.m_Memory + 2) >> 27)][v2 & ((32 * *((_DWORD *)&v1->m_Children.m_Memory + 2)) >> 5)].m_pObject;
          m_pHead = m_pObject->m_References.m_pHead;
          v4 = m_pObject->m_References.m_pHead;
          if ( v4 != nullptr )
            v4->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
          v8 = nullptr;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
        }
        v5 = inptr;
        v10 = -1;
        if ( inptr != nullptr )
        {
          if ( v8 != nullptr )
          {
            v8->m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = v8;
          }
          else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
          {
            *((_DWORD *)inptr + 8) = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = nullptr;
          }
          v8 = nullptr;
          m_pHead = nullptr;
          inptr = nullptr;
        }
        if ( __RTDynamicCast(
               inptr: v5,
               VfDelta: 0,
               SrcType: &CMapClass `RTTI Type Descriptor',
               TargetType: &CMapOverlay `RTTI Type Descriptor',
               isReference: 0) != nullptr )
          break;
        if ( ++v2 >= v1->m_Children.m_Size )
          return;
      }
      CMapDoc::RemoveObjectFromWorld(this: CMapDoc::m_pMapDoc, pObject: v1, bRemoveChildren: true);
      History = GetHistory();
      CHistory::KeepForDestruction(this: History, pObject: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2A10
// Name: void FixHiddenObject(struct MapError __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FixHiddenObject(MapError *pError)
{
  CMapClass *v1; // esi
  CUtlReference<CMapClass> *m_pHead; // eax
  MapErrorType Type; // eax
  CUtlReferenceVector<CMapClass> Objects; // [esp+8h] [ebp-2Ch] BYREF
  CUtlReference<CMapClass> src; // [esp+1Ch] [ebp-18h] BYREF
  int v6; // [esp+30h] [ebp-4h]

  v1 = pError->pObjects[0];
  *(_WORD *)&v1->m_bVisGroupShown = 257;
  v1->m_VisGroups.m_List.m_Size = 0;
  memset(&Objects, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &Objects.m_Memory, nGrowSize: 0, nInitSize: 0);
  Objects.m_Size = 0;
  Objects.m_pElements = nullptr;
  v6 = 3;
  m_pHead = v1->m_References.m_pHead;
  src.m_pPrev = nullptr;
  src.m_pObject = v1;
  src.m_pNext = m_pHead;
  if ( m_pHead != nullptr )
    m_pHead->m_pPrev = &src;
  src.m_pPrev = nullptr;
  v1->m_References.m_pHead = &src;
  LOBYTE(v6) = 4;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
    this: &Objects,
    elem: Objects.m_Size,
    &src);
  LOBYTE(v6) = 3;
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
  Type = pError->Type;
  if ( Type == ErrorHiddenGroupHiddenChildren || Type == ErrorHiddenObjectNoVisGroup )
  {
    CMapDoc::VisGroups_CreateNamedVisGroup(
      this: CMapDoc::m_pMapDoc,
      &Objects,
      szName: "_hidden by Check for Problems",
      bHide: true,
      bRemoveFromOtherVisGroups: false);
  }
  else if ( Type != ErrorIllegallyHiddenObject )
  {
    CMapDoc::VisGroups_CreateNamedVisGroup(
      this: CMapDoc::m_pMapDoc,
      &Objects,
      szName: "found by Check for Problems",
      bHide: false,
      bRemoveFromOtherVisGroups: false);
  }
  v6 = -1;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &Objects);
}

//------------------------------------------------------------------------------
// Address: 0x100D2B40
// Name: private: void CMapCheckDlg::GotoSelectedErrors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCheckDlg::GotoSelectedErrors(CMapCheckDlg *this)
{
  CToolManager *v2; // eax
  signed int i; // esi
  CMapClass **v4; // eax
  CMapClass *v5; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  CMapDoc *v7; // esi
  int j; // esi
  CUtlReferenceVector<CMapClass> Objects; // [esp+8h] [ebp-2Ch] BYREF
  CUtlReference<CMapClass> src; // [esp+1Ch] [ebp-18h] BYREF
  int v11; // [esp+30h] [ebp-4h]

  if ( SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0) != -1 )
  {
    v2 = ToolManager();
    CToolManager::SetTool(this: v2, eNewTool: TOOL_POINTER);
    memset(&Objects, 0, 12);
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &Objects.m_Memory, nGrowSize: 0, nInitSize: 0);
    Objects.m_Size = 0;
    Objects.m_pElements = nullptr;
    v11 = 3;
    for ( i = 0; i < SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0); ++i )
    {
      if ( SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x187u, wParam: i, lParam: 0) > 0 )
      {
        v4 = (CMapClass **)SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x199u, wParam: i, lParam: 0);
        if ( v4 != nullptr )
        {
          v5 = *v4;
          src.m_pPrev = nullptr;
          src.m_pNext = nullptr;
          src.m_pObject = v5;
          if ( v5 != nullptr )
          {
            src.m_pNext = v5->m_References.m_pHead;
            m_pHead = v5->m_References.m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = &src;
            src.m_pPrev = nullptr;
            v5->m_References.m_pHead = &src;
          }
          LOBYTE(v11) = 4;
          CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
            this: &Objects,
            elem: Objects.m_Size,
            &src);
          LOBYTE(v11) = 3;
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
      }
    }
    v7 = CMapDoc::m_pMapDoc;
    CMapDoc::SelectObjectList(this: CMapDoc::m_pMapDoc, pList: &Objects, cmd: 1042);
    CMapDoc::CenterViewsOnSelection(this: v7);
    v11 = 7;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &Objects);
    if ( Objects.m_Memory.m_pMemory != nullptr )
    {
      for ( j = 0; j < Objects.m_Memory.m_nBlocks; ++j )
        free(pMem: Objects.m_Memory.m_pMemory[j]);
      Objects.m_Memory.m_nBlocks = 0;
      free(pMem: Objects.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2D60
// Name: private: void CMapCheckDlg::Fix(struct MapError __near *,class UpdateBox __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCheckDlg::Fix(CMapCheckDlg *this, MapError *pError, UpdateBox *ub)
{
  int i; // edi
  CMapClass *v4; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  int j; // edi
  CMapClass *v7; // ecx
  Vector mins; // [esp+4h] [ebp-30h] BYREF
  Vector maxs; // [esp+10h] [ebp-24h] BYREF
  CUtlReference<CMapClass> src; // [esp+1Ch] [ebp-18h] BYREF
  int v11; // [esp+30h] [ebp-4h]

  CMapDoc::m_pMapDoc->SetModifiedFlag(this: CMapDoc::m_pMapDoc, a2: 1);
  if ( pError->Fix == NeedsFix )
  {
    for ( i = 0; i < 2; ++i )
    {
      v4 = pError->pObjects[i];
      if ( v4 != nullptr )
      {
        src.m_pNext = nullptr;
        src.m_pPrev = nullptr;
        src.m_pObject = v4;
        src.m_pNext = v4->m_References.m_pHead;
        m_pHead = v4->m_References.m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &src;
        src.m_pPrev = nullptr;
        v4->m_References.m_pHead = &src;
        v11 = 0;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
          this: ub->Objects,
          elem: ub->Objects->m_Size,
          &src);
        v11 = -1;
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
        CMapClass::GetRender2DBox(this: pError->pObjects[i], &mins, &maxs);
        BoundBox::UpdateBounds(this: &ub->Box, &mins, &maxs);
      }
    }
    switch ( pError->Type )
    {
      case ErrorDuplicatePlanes:
      case ErrorDuplicateFaceIDs:
        FixDuplicatePlanes(pError);
        break;
      case ErrorMissingTarget:
        ((void (__thiscall *)(CMapClass *, unsigned int, _DWORD))pError->pObjects[0][1].IsSelected)(
          a1: &pError->pObjects[0][1],
          a2: pError->dwExtra,
          a3: 0);
        break;
      case ErrorInvalidTexture:
        FixInvalidTexture(pError);
        break;
      case ErrorSolidStructure:
        FixSolidStructure(pError);
        break;
      case ErrorUnusedKeyvalues:
        FixUnusedKeyvalues(pError);
        break;
      case ErrorEmptyEntity:
        FixEmptyEntity(pError);
        break;
      case ErrorSolidContents:
        FixInvalidContents(pError);
        break;
      case ErrorInvalidTextureAxes:
        FixInvalidTextureAxes(pError);
        break;
      case ErrorDuplicateNodeIDs:
        CMapEntity::AssignNodeID(this: (CMapEntity *)pError->pObjects[0]);
        break;
      case ErrorBadConnections:
        CEntityConnection::FixBadConnections(
          pEntity: (CMapEntity *)pError->pObjects[0],
          bVisibilityCheck: Options.general.bCheckVisibleMapErrors == 1);
        break;
      case ErrorHiddenGroupHiddenChildren:
      case ErrorHiddenGroupVisibleChildren:
      case ErrorHiddenGroupMixedChildren:
      case ErrorHiddenObjectNoVisGroup:
      case ErrorHiddenChildOfEntity:
      case ErrorIllegallyHiddenObject:
        FixHiddenObject(pError);
        break;
      case ErrorKillInputRaceCondition:
        *(float *)&pError->pObjects[1][5].m_pEditorKeys = *(float *)&pError->pObjects[1][5].m_pEditorKeys + 0.01;
        break;
      case ErrorOverlayFaceList:
        FixOverlayFaceList(pError);
        break;
      default:
        break;
    }
    pError->Fix = Fixed;
    for ( j = 0; j < 2; ++j )
    {
      v7 = pError->pObjects[j];
      if ( v7 != nullptr )
      {
        CMapClass::GetRender2DBox(this: v7, mins: &maxs, maxs: &mins);
        BoundBox::UpdateBounds(this: &ub->Box, mins: &maxs, maxs: &mins);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2FD0
// Name: protected: void CMapCheckDlg::OnFixall(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCheckDlg::OnFixall(CMapCheckDlg *this)
{
  LRESULT v1; // ebx
  WPARAM v3; // eax
  LRESULT v4; // eax
  signed int j; // ebx
  LRESULT v6; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-68h]
  HWND__ *v8; // [esp-10h] [ebp-68h]
  UpdateBox ub; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlReferenceVector<CMapClass> Objects; // [esp+30h] [ebp-28h] BYREF
  MapError *pError; // [esp+44h] [ebp-14h]
  int i; // [esp+48h] [ebp-10h]
  int v13; // [esp+54h] [ebp-4h]

  v1 = 0;
  v3 = SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  if ( v3 != -1 && *(_DWORD *)(SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x199u, wParam: v3, lParam: 0) + 20) != 0 )
  {
    ub.__vftable = (UpdateBox_vtbl *)&UpdateBox::`vftable';
    BoundBox::BoundBox(this: &ub.Box);
    ub.Objects = nullptr;
    memset(&Objects, 0, 12);
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &Objects.m_Memory, nGrowSize: 0, nInitSize: 0);
    Objects.m_Size = 0;
    Objects.m_pElements = nullptr;
    v13 = 3;
    m_hWnd = this->m_Errors.m_hWnd;
    ub.Objects = &Objects;
    i = 0;
    if ( SendMessageA(hWnd: m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) > 0 )
    {
      do
      {
        if ( SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x187u, wParam: v1, lParam: 0) > 0 )
        {
          v4 = SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x199u, wParam: v1, lParam: 0);
          pError = (MapError *)v4;
          if ( v4 != 0 && *(_DWORD *)(v4 + 20) == 1 )
          {
            for ( j = 0; j < SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0); ++j )
            {
              v6 = SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x199u, wParam: j, lParam: 0);
              if ( *(_DWORD *)(v6 + 12) == pError->Type && *(_DWORD *)(v6 + 20) == 1 )
                CMapCheckDlg::Fix(this, pError: (MapError *)v6, &ub);
            }
            v1 = i;
          }
        }
        ++v1;
        v8 = this->m_Errors.m_hWnd;
        i = v1;
      }
      while ( v1 < SendMessageA(hWnd: v8, Msg: 0x18Bu, wParam: 0, lParam: 0) );
    }
    CMapCheckDlg::OnSelchangeErrors(this);
    CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 1, ub: nullptr);
    v13 = -1;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &Objects);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3170
// Name: protected: void CMapCheckDlg::OnGo(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMapCheckDlg::OnGo(CMapCheckDlg *this)
{
  CMapCheckDlg::GotoSelectedErrors(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D3180
// Name: protected: void CMapCheckDlg::OnFix(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCheckDlg::OnFix(CMapCheckDlg *this)
{
  signed int v1; // edi
  MapError *v3; // eax
  int i; // esi
  HWND__ *m_hWnd; // [esp-10h] [ebp-60h]
  UpdateBox ub; // [esp+Ch] [ebp-44h] BYREF
  CUtlReferenceVector<CMapClass> Objects; // [esp+30h] [ebp-20h] BYREF
  int v8; // [esp+4Ch] [ebp-4h]

  v1 = 0;
  if ( SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0) != -1 )
  {
    ub.__vftable = (UpdateBox_vtbl *)&UpdateBox::`vftable';
    BoundBox::BoundBox(this: &ub.Box);
    ub.Objects = nullptr;
    memset(&Objects, 0, 12);
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &Objects.m_Memory, nGrowSize: 0, nInitSize: 0);
    Objects.m_Size = 0;
    Objects.m_pElements = nullptr;
    v8 = 3;
    m_hWnd = this->m_Errors.m_hWnd;
    ub.Objects = &Objects;
    if ( SendMessageA(hWnd: m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) > 0 )
    {
      do
      {
        if ( SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x187u, wParam: v1, lParam: 0) > 0 )
        {
          v3 = (MapError *)SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x199u, wParam: v1, lParam: 0);
          if ( v3 != nullptr )
            CMapCheckDlg::Fix(this, pError: v3, &ub);
        }
        ++v1;
      }
      while ( v1 < SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) );
    }
    CMapCheckDlg::OnSelchangeErrors(this);
    CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 1, ub: nullptr);
    v8 = 6;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &Objects);
    if ( Objects.m_Memory.m_pMemory != nullptr )
    {
      for ( i = 0; i < Objects.m_Memory.m_nBlocks; ++i )
        free(pMem: Objects.m_Memory.m_pMemory[i]);
      Objects.m_Memory.m_nBlocks = 0;
      free(pMem: Objects.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3310
// Name: CheckValidTarget
// Source: json
//------------------------------------------------------------------------------
void __usercall CheckValidTarget(
        char *pTargetName@<ecx>,
        unsigned int a2@<edi>,
        CMapEntity *pEntity,
        const char *pFieldName,
        CListBox *pList,
        bool bCheckClassNames)
{
  CMapDoc *v7; // edi
  CUtlReferenceVector<CMapEntity> Found; // [esp+4h] [ebp-20h] BYREF
  int v10; // [esp+20h] [ebp-4h]

  if ( pTargetName != nullptr
    && _V_stricmp(s1: pTargetName, s2: "!activator") != 0
    && _V_stricmp(s1: pTargetName, s2: "!caller") != 0
    && _V_stricmp(s1: pTargetName, s2: "!player") != 0
    && _V_stricmp(s1: pTargetName, s2: "!self") != 0 )
  {
    v7 = CMapDoc::m_pMapDoc;
    CUtlReferenceVector<CMapEntity>::CUtlReferenceVector<CMapEntity>(this: &Found);
    v10 = 0;
    if ( !CMapDoc::FindEntitiesByName(
            this: v7,
            &Found,
            pszName: pTargetName,
            bVisiblesOnly: Options.general.bCheckVisibleMapErrors == 1)
      && (!bCheckClassNames
       || !CMapDoc::FindEntitiesByClassName(
             this: v7,
             &Found,
             pszClassName: pTargetName,
             bVisiblesOnly: Options.general.bCheckVisibleMapErrors == 1)) )
    {
      AddError(Type: 3, pList, dwExtra: (unsigned int)pFieldName, a4: pEntity, a5: a2);
    }
    v10 = -1;
    CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &Found);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3500
// Name: private: bool CMapCheckDlg::DoCheck(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapCheckDlg::DoCheck(CMapCheckDlg *this)
{
  CMapWorld *ActiveWorld; // edi
  CGameConfig *m_pGame; // eax
  CMapClass *v5; // [esp+0h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-8h]

  ActiveWorld = GetActiveWorld();
  CMapCheckDlg::KillErrorList(this);
  if ( CMapClass::EnumChildren(
         this: ActiveWorld,
         pfn: (int (__cdecl *)(CMapClass *, unsigned int))FindPlayer,
         dwParam: 0,
         Type: CMapEntity::__Type) != 0 )
    AddError(Type: 0, pList: &this->m_Errors, dwExtra: 0, a4: v5, a5: v6);
  CMapClass::EnumChildren(
    this: ActiveWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CheckMixedFaces,
    dwParam: (unsigned int)&this->m_Errors,
    Type: CMapSolid::__Type);
  CheckDuplicateFaceIDs(a1: (unsigned int)&this->m_Errors, pList: &this->m_Errors, pWorld: ActiveWorld);
  CheckDuplicateNodeIDs(a1: (unsigned int)ActiveWorld, pList: &this->m_Errors, pWorld: ActiveWorld);
  CMapClass::EnumChildren(
    this: ActiveWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CheckSolidIntegrity,
    dwParam: (unsigned int)&this->m_Errors,
    Type: CMapSolid::__Type);
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    m_pGame = CMapDoc::m_pMapDoc->m_pGame;
    if ( m_pGame != nullptr && m_pGame->mapformat == mfQuake2 )
      CMapClass::EnumChildren(
        this: ActiveWorld,
        pfn: (int (__cdecl *)(CMapClass *, unsigned int))CheckSolidContents,
        dwParam: (unsigned int)&this->m_Errors,
        Type: CMapSolid::__Type);
  }
  CMapClass::EnumChildren(
    this: ActiveWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CheckInvalidTextures,
    dwParam: (unsigned int)&this->m_Errors,
    Type: CMapSolid::__Type);
  CMapClass::EnumChildren(
    this: ActiveWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CheckUnusedKeyvalues,
    dwParam: (unsigned int)&this->m_Errors,
    Type: CMapEntity::__Type);
  CMapClass::EnumChildren(
    this: ActiveWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CheckEmptyEntities,
    dwParam: (unsigned int)&this->m_Errors,
    Type: CMapEntity::__Type);
  CMapClass::EnumChildren(
    this: ActiveWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CheckMissingTargets,
    dwParam: (unsigned int)&this->m_Errors,
    Type: CMapEntity::__Type);
  CMapClass::EnumChildren(
    this: ActiveWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CheckBadConnections,
    dwParam: (unsigned int)&this->m_Errors,
    Type: CMapEntity::__Type);
  CMapClass::EnumChildrenRecurseGroupsOnly(
    this: ActiveWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CheckVisGroups,
    dwParam: (unsigned int)&this->m_Errors,
    Type: nullptr);
  CMapClass::EnumChildren(
    this: ActiveWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CheckOverlayFaceList,
    dwParam: (unsigned int)&this->m_Errors,
    Type: CMapEntity::__Type);
  if ( SendMessageA(hWnd: this->m_Errors.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) != 0 )
    return 0;
  AfxMessageBox(lpszText: "No errors were found.", nType: 0, nIDHelp: 0);
  CDialog::EndDialog(this, nResult: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D3670
// Name: public: static void CMapCheckDlg::CheckForProblems(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapCheckDlg::CheckForProblems(CWnd *pwndParent)
{
  CMapCheckDlg *v1; // eax
  CMapCheckDlg *v2; // eax

  if ( s_pDlg == nullptr )
  {
    v1 = (CMapCheckDlg *)operator new(nSize: 0x2DCu);
    if ( v1 != nullptr )
      v2 = CMapCheckDlg::CMapCheckDlg(this: v1, pParent: nullptr);
    else
      v2 = nullptr;
    s_pDlg = v2;
    v2->Create(this: v2, a2: 202u, a3: pwndParent);
  }
  if ( CMapCheckDlg::DoCheck(this: s_pDlg) == 0 )
    CWnd::ShowWindow(this: s_pDlg, nCmdShow: 5);
}

//------------------------------------------------------------------------------
// Address: 0x100D3710
// Name: protected: void CMapCheckDlg::OnCheckVisibleOnly(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCheckDlg::OnCheckVisibleOnly(CMapCheckDlg *this)
{
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  CMapCheckDlg::DoCheck(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D3730
// Name: protected: virtual struct AFX_MSGMAP const __near * CMapCheckDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMapCheckDlg::GetMessageMap(CMapCheckDlg *this)
{
  return (const AFX_MSGMAP *)&off_105EC70C;
}

//------------------------------------------------------------------------------
// Address: 0x100D1A60
// Name: _CheckMixedFaces
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CheckMixedFaces@<eax>(unsigned int a1@<edi>, CMapSolid *pSolid, CListBox *pList)
{
  CMapSolid *v4; // ecx
  int nCount; // eax
  const char *v6; // esi
  BlockArray<CMapFace,6,86> *p_Faces; // edi
  int v8; // ebx
  unsigned int v9; // edi
  char v10; // al
  bool v11; // zf
  int iFaces; // [esp+4h] [ebp-8h]
  int iSolid; // [esp+8h] [ebp-4h]

  if ( Options.general.bCheckVisibleMapErrors != 0 && (*((_BYTE *)&pSolid->CMapClass + 180) & 2) == 0 )
    return 1;
  v4 = pSolid;
  nCount = pSolid->Faces.nCount;
  v6 = nullptr;
  iFaces = nCount;
  iSolid = 2;
  if ( nCount > 0 )
  {
    p_Faces = &pSolid->Faces;
    while ( 1 )
    {
      if ( (int)v6 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v6, p_Faces->nCount);
        v8 = (int)(v6 + 1);
        if ( v6 + 1 != (const char *)p_Faces->nCount )
        {
          v9 = v8 / 6;
          if ( 6 * (v8 / 6) < v8 )
            ++v9;
          if ( v9 != pSolid->Faces.nBlocks )
          {
            if ( v9 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: &pSolid->Faces, nNewBlocks: v9);
          }
          pSolid->Faces.nCount = v8;
        }
      }
      v4 = pSolid;
      v10 = pSolid->Faces.Blocks[(unsigned int)v6 / 6][(unsigned int)v6 % 6].texture.texture[0];
      p_Faces = &pSolid->Faces;
      v11 = v10 == 42 ? iSolid == 1 : iSolid == 0;
      if ( v11 )
        break;
      v11 = v10 == 42;
      nCount = iFaces;
      ++v6;
      iSolid = !v11;
      if ( (int)v6 >= iFaces )
        goto LABEL_22;
    }
    nCount = iFaces;
  }
LABEL_22:
  if ( v6 != (const char *)nCount )
    AddError(Type: 1, pList, dwExtra: 0, a4: v4, a5: a1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D1EE0
// Name: _CheckSolidIntegrity
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CheckSolidIntegrity@<eax>(unsigned int a1@<ebx>, CMapSolid *pSolid, CListBox *pList)
{
  int nCount; // eax
  int v4; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v6; // ebx
  unsigned int v7; // esi
  CMapFace *v8; // ecx
  CCheckFaceInfo cfi; // [esp+0h] [ebp-8Ch] BYREF
  int v12; // [esp+84h] [ebp-8h]
  int nFaces; // [esp+88h] [ebp-4h]

  if ( Options.general.bCheckVisibleMapErrors == 0 || (*((_BYTE *)&pSolid->CMapClass + 180) & 2) != 0 )
  {
    nCount = pSolid->Faces.nCount;
    v4 = 0;
    cfi.iPoint = -1;
    nFaces = nCount;
    if ( nCount > 0 )
    {
      p_Faces = &pSolid->Faces;
      while ( 1 )
      {
        if ( v4 >= p_Faces->nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, p_Faces->nCount);
          v6 = v4 + 1;
          if ( v4 + 1 != p_Faces->nCount )
          {
            v7 = v6 / 6;
            if ( 6 * (v6 / 6) < v6 )
              ++v7;
            if ( v7 != pSolid->Faces.nBlocks )
            {
              if ( v7 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: &pSolid->Faces, nNewBlocks: v7);
            }
            pSolid->Faces.nCount = v6;
          }
        }
        v8 = &pSolid->Faces.Blocks[v4 / 6][v4 % 6];
        p_Faces = &pSolid->Faces;
        cfi.iPoint = -1;
        if ( CMapFace::CheckFace(this: v8, pInfo: &cfi) == 0 )
          break;
        v12 = ++v4;
        if ( v4 >= nFaces )
          return 1;
      }
      AddError(Type: 5, pList, dwExtra: 0, a4: pSolid, a5: a1);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D2030
// Name: _CheckSolidContents
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CheckSolidContents@<eax>(unsigned int a1@<edi>, CMapSolid *pSolid, CListBox *pList)
{
  __int16 nCount; // ax
  int v4; // esi
  int v5; // edi
  int v6; // ecx
  unsigned int v7; // esi
  unsigned int dwContents; // [esp+8h] [ebp-8h]
  int nFaces; // [esp+Ch] [ebp-4h]

  if ( Options.general.bCheckVisibleMapErrors == 0 || (*((_BYTE *)&pSolid->CMapClass + 180) & 2) != 0 )
  {
    nCount = pSolid->Faces.nCount;
    v4 = nCount;
    nFaces = nCount;
    if ( nCount <= 0 )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: nullptr, nCount);
      BlockArray<CMapFace,6,86>::SetCount(this: &pSolid->Faces, nObjects: 1);
    }
    v5 = 1;
    dwContents = pSolid->Faces.Blocks[0]->texture.q2contents;
    if ( v4 > 1 )
    {
      while ( 1 )
      {
        if ( v5 >= pSolid->Faces.nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v5, pSolid->Faces.nCount);
          v6 = v5 + 1;
          if ( v5 + 1 != pSolid->Faces.nCount )
          {
            v7 = v6 / 6;
            if ( 6 * (v6 / 6) < v6 )
              ++v7;
            if ( v7 != pSolid->Faces.nBlocks )
            {
              if ( v7 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: &pSolid->Faces, nNewBlocks: v7);
            }
            v4 = nFaces;
            pSolid->Faces.nCount = v5 + 1;
          }
        }
        if ( pSolid->Faces.Blocks[v5 / 6][v5 % 6].texture.q2contents != dwContents )
          break;
        if ( ++v5 >= v4 )
          return 1;
      }
      AddError(Type: 9, pList, dwExtra: 0, a4: pSolid, a5: a1);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D21A0
// Name: _CheckInvalidTextures
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CheckInvalidTextures@<eax>(unsigned int a1@<edi>, CMapSolid *pSolid, CListBox *pList)
{
  signed int v3; // edi
  int v4; // ebx
  unsigned int v5; // esi
  CMapFace *v6; // esi
  int nFaces; // [esp+4h] [ebp-4h]

  if ( Options.general.bCheckVisibleMapErrors == 0 || (*((_BYTE *)&pSolid->CMapClass + 180) & 2) != 0 )
  {
    v3 = 0;
    nFaces = pSolid->Faces.nCount;
    if ( nFaces > 0 )
    {
      while ( 1 )
      {
        if ( v3 >= pSolid->Faces.nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, pSolid->Faces.nCount);
          v4 = v3 + 1;
          if ( v3 + 1 != pSolid->Faces.nCount )
          {
            v5 = v4 / 6;
            if ( 6 * (v4 / 6) < v4 )
              ++v5;
            if ( v5 != pSolid->Faces.nBlocks )
            {
              if ( v5 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: &pSolid->Faces, nNewBlocks: v5);
            }
            pSolid->Faces.nCount = v4;
          }
        }
        v6 = &pSolid->Faces.Blocks[v3 / 6][v3 % 6];
        if ( v6->m_pTexture->IsDummy(this: v6->m_pTexture) )
        {
          AddError(Type: 4, pList, dwExtra: (unsigned int)&v6->texture, a4: pSolid, a5: a1);
          return 1;
        }
        if ( CMapFace::IsTextureAxisValid(this: v6) == 0 )
          break;
        if ( ++v3 >= nFaces )
          return 1;
      }
      AddError(Type: 10, pList, dwExtra: v3, a4: pSolid, a5: a1);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D2310
// Name: _CheckEmptyEntities
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CheckEmptyEntities@<eax>(unsigned int a1@<esi>, CMapEntity *pEntity, CListBox *pList)
{
  if ( (Options.general.bCheckVisibleMapErrors == 0 || (*((_BYTE *)&pEntity->CMapClass + 180) & 2) != 0)
    && (pEntity->flags & 1) == 0
    && pEntity->m_Children.m_Size == 0 )
  {
    AddError(Type: 7, pList, dwExtra: (unsigned int)pEntity->m_szClass, a4: pEntity, a5: a1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D2360
// Name: _CheckBadConnections
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl CheckBadConnections(CMapEntity *pEntity, CListBox *pList)
{
  unsigned int v3; // [esp+0h] [ebp-4h]

  if ( (Options.general.bCheckVisibleMapErrors == 0 || (*((_BYTE *)&pEntity->CMapClass + 180) & 2) != 0)
    && CEntityConnection::ValidateOutputConnections(
         pEntity,
         bVisibilityCheck: Options.general.bCheckVisibleMapErrors == 1,
         bIgnoreHiddenTargets: false,
         CheckAllDocuments: false) == 2 )
  {
    AddError(Type: 13, pList, dwExtra: (unsigned int)pEntity->m_szClass, a4: pEntity, a5: v3);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D23C0
// Name: _CheckVisGroups
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl CheckVisGroups(CMapClass *pObject, CListBox *pList)
{
  CMapDoc *v2; // edi
  char v3; // bl
  char v4; // al
  unsigned int v6; // [esp+0h] [ebp-8h]

  v2 = CMapDoc::m_pMapDoc;
  if ( !pObject->m_bVisGroupShown || !pObject->m_bVisGroupAutoShown )
  {
    if ( pObject->IsGroup(this: pObject) )
    {
      v3 = HasVisGroupHiddenChildren(pObject);
      v4 = HasVisGroupShownChildren(pObject);
      if ( v3 != 0 )
      {
        if ( v4 == 0 )
        {
          AddError(Type: 14, pList, dwExtra: 0, a4: pObject, a5: v6);
          return 1;
        }
        goto LABEL_9;
      }
      if ( v4 == 0 )
      {
LABEL_9:
        AddError(Type: 16, pList, dwExtra: 0, a4: pObject, a5: v6);
        return 1;
      }
      AddError(Type: 15, pList, dwExtra: 0, a4: pObject, a5: v6);
    }
    else
    {
      if ( !CMapDoc::VisGroups_ObjectCanBelongToVisGroup(this: v2, pObject) )
      {
        AddError(Type: 19, pList, dwExtra: 0, a4: pObject, a5: v6);
        return 1;
      }
      if ( CMapClass::GetVisGroupCount(this: pObject) == 0 )
        AddError(Type: 17, pList, dwExtra: 0, a4: pObject, a5: v6);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D2600
// Name: _CheckUnusedKeyvalues
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CheckUnusedKeyvalues@<eax>(unsigned int a1@<esi>, CMapEntity *pEntity, CListBox *pList)
{
  GDclass *m_pClass; // ebx
  unsigned __int16 Inorder; // si

  if ( (Options.general.bCheckVisibleMapErrors == 0 || (*((_BYTE *)&pEntity->CMapClass + 180) & 2) != 0)
    && pEntity->m_pClass != nullptr
    && _V_stricmp(s1: "multi_manager", s2: pEntity->m_szClass) != 0 )
  {
    m_pClass = pEntity->m_pClass;
    Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
    if ( Inorder != 0xFFFF )
    {
      while ( GDclass::VarForName(
                this: m_pClass,
                pszName: pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem.szKey,
                piIndex: nullptr) != nullptr )
      {
        Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                    this: &pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                    i: Inorder);
        if ( Inorder == 0xFFFF )
          return 1;
      }
      AddError(
        Type: 6,
        pList,
        dwExtra: (unsigned int)&pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem,
        a4: pEntity,
        a5: a1);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D26F0
// Name: _CheckOverlayFaceList
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CheckOverlayFaceList@<eax>(unsigned int a1@<esi>, CMapEntity *pEntity, CListBox *pList)
{
  int v3; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v5; // ecx
  void *v6; // edx
  int *v7; // eax
  CUtlReference<CMapClass> *m_pHead; // [esp+8h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v11; // [esp+Ch] [ebp-14h]
  void *inptr; // [esp+10h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-4h]

  if ( Options.general.bCheckVisibleMapErrors == 0 || (*((_BYTE *)&pEntity->CMapClass + 180) & 2) != 0 )
  {
    v3 = 0;
    if ( pEntity->m_Children.m_Size > 0 )
    {
      while ( 1 )
      {
        m_pObject = pEntity->m_Children.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&pEntity->m_Children.m_Memory
                                                                                    + 2) >> 27)][v3
                                                                                               & ((32
                                                                                                 * *((_DWORD *)&pEntity->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr )
        {
          inptr = pEntity->m_Children.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&pEntity->m_Children.m_Memory
                                                                                  + 2) >> 27)][v3
                                                                                             & ((32
                                                                                               * *((_DWORD *)&pEntity->m_Children.m_Memory
                                                                                                 + 2)) >> 5)].m_pObject;
          m_pHead = m_pObject->m_References.m_pHead;
          v5 = m_pObject->m_References.m_pHead;
          if ( v5 != nullptr )
            v5->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
          v11 = nullptr;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
        }
        v6 = inptr;
        v13 = -1;
        if ( inptr != nullptr )
        {
          if ( v11 != nullptr )
          {
            v11->m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = v11;
          }
          else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
          {
            *((_DWORD *)inptr + 8) = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = nullptr;
          }
          v11 = nullptr;
          m_pHead = nullptr;
          inptr = nullptr;
        }
        v7 = (int *)__RTDynamicCast(
                      inptr: v6,
                      VfDelta: 0,
                      SrcType: &CMapClass `RTTI Type Descriptor',
                      TargetType: &CMapOverlay `RTTI Type Descriptor',
                      isReference: 0);
        if ( v7 != nullptr && v7[77] <= 0 )
          break;
        if ( ++v3 >= pEntity->m_Children.m_Size )
          return 1;
      }
      AddError(Type: 21, pList, dwExtra: 0, a4: pEntity, a5: a1);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D3420
// Name: _CheckMissingTargets
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CheckMissingTargets@<eax>(unsigned int a1@<edi>, CMapEntity *pEntity, CListBox *pList)
{
  GDclass *m_pClass; // ecx
  char *Value; // eax
  int v6; // edi
  GDinputvariable *VariableAt; // esi
  GDIV_TYPE m_eType; // eax
  char *v9; // eax
  GDclass *pClass; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( Options.general.bCheckVisibleMapErrors == 0 || (*((_BYTE *)&pEntity->CMapClass + 180) & 2) != 0 )
  {
    m_pClass = pEntity->m_pClass;
    pClass = m_pClass;
    if ( m_pClass == nullptr )
    {
      Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                        this: &pEntity->m_KeyValues,
                        pszKey: pszTarget,
                        piIndex: nullptr);
      CheckValidTarget(pTargetName: Value, a2: a1, pEntity, pFieldName: pszTarget, pList, bCheckClassNames: false);
      return 1;
    }
    v6 = 0;
    i = 0;
    if ( m_pClass->m_nVariables > 0 )
    {
      while ( 1 )
      {
        VariableAt = GDclass::GetVariableAt(this: m_pClass, iIndex: v6);
        m_eType = VariableAt->m_eType;
        if ( m_eType == ivTargetDest || m_eType == ivTargetNameOrClass )
        {
          v9 = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                         this: &pEntity->m_KeyValues,
                         pszKey: VariableAt->m_szName,
                         piIndex: nullptr);
          CheckValidTarget(
            pTargetName: v9,
            a2: (unsigned int)VariableAt->m_szName,
            pEntity,
            pFieldName: VariableAt->m_szName,
            pList,
            bCheckClassNames: VariableAt->m_eType == ivTargetNameOrClass);
          v6 = i;
        }
        i = ++v6;
        if ( v6 >= pClass->m_nVariables )
          break;
        m_pClass = pClass;
      }
    }
  }
  return 1;
}
