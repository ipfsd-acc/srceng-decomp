// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mappath.cpp
// Functions: 6
// ============================================================

#include "hammer\mappath.h"

//------------------------------------------------------------------------------
// Address: 0x1007B7D0
// Name: public: CMapPathNode::~CMapPathNode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPathNode::~CMapPathNode(CMapPathNode *this)
{
  WCKeyValuesT<WCKVBase_Dict>::~WCKeyValuesT<WCKVBase_Dict>(this: &this->kv);
}

//------------------------------------------------------------------------------
// Address: 0x1007B9A0
// Name: public: CMapPath::CMapPath(void)
// Source: json
//------------------------------------------------------------------------------
CMapPath *__thiscall CMapPath::CMapPath(CMapPath *this)
{
  CMapPath *result; // eax
  CMapPathNode *m_pMemory; // ecx

  result = this;
  this->m_Nodes.m_Memory.m_pMemory = nullptr;
  this->m_Nodes.m_Memory.m_nAllocationCount = 0;
  this->m_Nodes.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Nodes.m_Memory.m_pMemory;
  result->m_Nodes.m_Size = 0;
  result->m_Nodes.m_pElements = m_pMemory;
  result->m_iDirection = 0;
  strcpy(result->m_szName, &var);
  strcpy(result->m_szClass, "path_corner");
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007BA30
// Name: public: CMapPath::~CMapPath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPath::~CMapPath(CMapPath *this)
{
  CUtlVector<CMapPathNode,CUtlMemory<CMapPathNode,int>>::~CUtlVector<CMapPathNode,CUtlMemory<CMapPathNode,int>>(this: &this->m_Nodes);
}

//------------------------------------------------------------------------------
// Address: 0x1007BA70
// Name: public: class CMapPathNode __near & CMapPathNode::operator=(class CMapPathNode const __near &)
// Source: json
//------------------------------------------------------------------------------
CMapPathNode *__thiscall CMapPathNode::operator=(CMapPathNode *this, const CMapPathNode *src)
{
  const CMapPathNode *v2; // esi
  CMapPathNode *v3; // edi
  unsigned __int16 Inorder; // bx
  MDkeyvalue KeyValue; // [esp+Ch] [ebp-260h] BYREF
  CMapPathNode *v7; // [esp+25Ch] [ebp-10h]
  int v8; // [esp+268h] [ebp-4h]

  v2 = src;
  v3 = this;
  v7 = this;
  V_strncpy(pDest: this->szName, pSrc: src->szName, maxLen: 128);
  v3->bSelected = src->bSelected;
  WCKeyValuesT<WCKVBase_Dict>::RemoveAll(this: &v3->kv);
  Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &src->kv.m_KeyValues.m_Elements.m_Tree);
  if ( Inorder != 0xFFFF )
  {
    do
    {
      KeyValue = v2->kv.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      v8 = 0;
      WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &v7->kv, pszKey: KeyValue.szKey, pszValue: KeyValue.szValue);
      v8 = -1;
      CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&KeyValue);
      v2 = src;
      Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                  this: &src->kv.m_KeyValues.m_Elements.m_Tree,
                  i: Inorder);
    }
    while ( Inorder != 0xFFFF );
    v3 = v7;
  }
  v3->pos.x = v2->pos.x;
  v3->pos.y = v2->pos.y;
  v3->pos.z = v2->pos.z;
  v3->dwID = v2->dwID;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1007BBA0
// Name: public: void CMapPath::SerializeMAP(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int,class BoundBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPath::SerializeMAP(CMapPath *this, std::fstream *file, int fIsStoring, BoundBox *pIntersecting)
{
  int m_Size; // eax
  BoundBox *v5; // ebx
  int v6; // esi
  int v7; // edi
  CAfxStringMgr *StringManager; // eax
  int v9; // ebx
  int v10; // edx
  CMapPath *v11; // esi
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // edi
  int v17; // eax
  const char *m_szName; // edx
  int v19; // eax
  const char *v20; // eax
  const char *v21; // esi
  unsigned int v22; // eax
  const char *v23; // eax
  BoundBox *v24; // ecx
  char *v25; // eax
  int v26; // edx
  int v27; // edx
  char v28; // al
  int v29; // eax
  int v30; // ebx
  int szName; // edi
  CMapPathNode *v32; // ecx
  unsigned int v33; // eax
  BoundBox *v34; // ecx
  _BYTE *v35; // edx
  char v36; // al
  char *v37; // edi
  int v38; // ebx
  std::ostream *v39; // eax
  std::ostream *v40; // eax
  int v41; // eax
  char v42; // cl
  char *v43; // eax
  char v44; // cl
  int v45; // edi
  int v46; // eax
  char v47; // cl
  BoundBox *v48; // eax
  int v49; // edx
  char v50; // cl
  char *v51; // ecx
  unsigned int v52; // eax
  char *v53; // edx
  unsigned int v54; // eax
  int v55; // eax
  char v56; // cl
  BoundBox *v57; // ebx
  BoundBox *v58; // eax
  int v59; // edx
  char v60; // cl
  int v61; // eax
  int v62; // ecx
  char v63; // dl
  char *v64; // edx
  char v65; // cl
  int j; // esi
  int v67; // ecx
  int v68; // eax
  bool v69; // zf
  MDkeyvalue *v70; // ecx
  std::ostream *v71; // eax
  std::ostream *v72; // eax
  int v73; // eax
  unsigned __int64 v74; // [esp+10h] [ebp-294h]
  MDkeyvalue v75; // [esp+24h] [ebp-280h] BYREF
  char *m_szClass; // [esp+274h] [ebp-30h]
  int i; // [esp+278h] [ebp-2Ch]
  char *v78; // [esp+27Ch] [ebp-28h]
  int v79; // [esp+280h] [ebp-24h]
  int v80; // [esp+284h] [ebp-20h]
  int v81; // [esp+288h] [ebp-1Ch]
  int v82; // [esp+28Ch] [ebp-18h]
  int v83; // [esp+290h] [ebp-14h]
  CMapPath *v84; // [esp+294h] [ebp-10h]
  int bFirstPass; // [esp+2A0h] [ebp-4h]

  m_Size = this->m_Nodes.m_Size;
  v84 = this;
  if ( m_Size == 0 )
    return;
  v5 = pIntersecting;
  if ( pIntersecting != nullptr )
  {
    v6 = 0;
    if ( m_Size > 0 )
    {
      v7 = 0;
      do
      {
        if ( !BoundBox::ContainsPoint(this: v5, pt: &v84->m_Nodes.m_Memory.m_pMemory[v7].pos) )
          return;
        ++v6;
        ++v7;
      }
      while ( v6 < v84->m_Nodes.m_Size );
    }
  }
  StringManager = AfxGetStringManager();
  v9 = 0;
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  pIntersecting = (BoundBox *)&StringManager->GetNilString(this: StringManager)[1];
  v10 = 1;
  bFirstPass = 2;
  v75.szKey[0] = 0;
  v75.szValue[0] = 0;
  v11 = v84;
  v12 = 0;
  if ( v84->m_Nodes.m_Size > 0 )
  {
    v13 = 0;
    do
    {
      v11->m_Nodes.m_Memory.m_pMemory[v13].nTargets = 0;
      ++v12;
      ++v13;
    }
    while ( v12 < v11->m_Nodes.m_Size );
  }
  v14 = v11->m_Nodes.m_Size - 1;
  v15 = 0;
  v82 = 1;
  v79 = v14;
  v81 = 0;
  v83 = -1;
  while ( 2 )
  {
    v78 = (char *)v10;
    v16 = 436 * v83;
    v17 = 436 * v9;
    v80 = 436 * v9;
    for ( i = 436 * v82; ; v80 += i )
    {
      m_szName = &v11->m_Nodes.m_Memory.m_pMemory->szName[v17];
      if ( *m_szName != 0 )
      {
        if ( m_szName != nullptr )
        {
          v20 = &v11->m_Nodes.m_Memory.m_pMemory->szName[v17];
          v21 = m_szName + 1;
          v22 = (unsigned int)&v20[strlen(v20) + 1];
LABEL_23:
          v19 = v22 - (_DWORD)v21;
          goto LABEL_24;
        }
        v19 = 0;
      }
      else
      {
        if ( v15 != 0 )
        {
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
            this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pIntersecting,
            pszFormat: "%s%02d",
            v11->m_szName,
            v15);
          goto LABEL_25;
        }
        m_szName = v11->m_szName;
        if ( v11 != (CMapPath *)-20 )
        {
          v23 = v11->m_szName;
          v21 = &v11->m_szName[1];
          v22 = (unsigned int)&v23[strlen(v23) + 1];
          goto LABEL_23;
        }
        v19 = 0;
      }
LABEL_24:
      ATL::CSimpleStringT<char,0>::SetString(
        this: (ATL::CSimpleStringT<char,0> *)&pIntersecting,
        pszSrc: m_szName,
        nLength: v19);
LABEL_25:
      if ( v83 != -1 )
      {
        v24 = pIntersecting;
        v25 = &v84->m_Nodes.m_Memory.m_pMemory->szName[v16];
        v26 = (int)&v25[128 * (*((_DWORD *)v25 + 101))++ + 148];
        v27 = v26 - (_DWORD)v24;
        do
        {
          v28 = (char)v24->__vftable;
          *((_BYTE *)&v24->__vftable + v27) = v24->__vftable;
          v24 = (BoundBox *)((char *)v24 + 1);
        }
        while ( v28 != 0 );
      }
      ++v81;
      v11 = v84;
      v83 = v9;
      v16 = v80;
      if ( v9 == v79 )
        break;
      v9 += v82;
      v17 = i + v80;
      v15 = v81;
    }
    v10 = 0;
    if ( v78 != nullptr && v84->m_iDirection == 2 )
    {
      v29 = v84->m_Nodes.m_Size;
      if ( v29 > 2 )
      {
        v15 = v81;
        v82 = -1;
        v9 = v29 - 2;
        v79 = 0;
        continue;
      }
    }
    break;
  }
  if ( v84->m_iDirection == 1 )
  {
    v30 = v9;
    szName = (int)v84->m_Nodes.m_Memory.m_pMemory[v79].szName;
    v32 = &v84->m_Nodes.m_Memory.m_pMemory[v30];
    if ( v32->szName[0] != 0 )
    {
      if ( v32 != nullptr )
      {
        v11 = v84;
        v74 = __PAIR64__(strlen(v84->m_Nodes.m_Memory.m_pMemory[v30].szName), (unsigned int)v32);
      }
      else
      {
        v74 = 0;
      }
    }
    else
    {
      if ( v84 == (CMapPath *)-20 )
      {
        v33 = 0;
      }
      else
      {
        v33 = strlen(v84->m_szName);
        v11 = v84;
      }
      HIDWORD(v74) = v33;
      LODWORD(v74) = v84->m_szName;
    }
    ATL::CSimpleStringT<char,0>::SetString(
      this: (ATL::CSimpleStringT<char,0> *)&pIntersecting,
      pszSrc: (const char *)v74,
      nLength: SHIDWORD(v74));
    v34 = pIntersecting;
    v35 = (_BYTE *)((*(_DWORD *)(szName + 404) << 7) + szName + 148);
    do
    {
      v36 = (char)v34->__vftable;
      *v35 = v34->__vftable;
      v34 = (BoundBox *)((char *)v34 + 1);
      ++v35;
    }
    while ( v36 != 0 );
    ++*(_DWORD *)(szName + 404);
  }
  v79 = v11->m_Nodes.m_Size - 1;
  v37 = (char *)(v75.szValue - v11->m_szClass);
  v82 = 1;
  v83 = 0;
  v81 = 0;
  m_szClass = v11->m_szClass;
  v78 = v37;
  while ( 2 )
  {
    v38 = 436 * v83;
    v80 = 436 * v83;
    i = 436 * v82;
    while ( 2 )
    {
      if ( file != nullptr )
        v39 = (std::ostream *)file->gap10;
      else
        v39 = nullptr;
      HIDWORD(v74) = "\r\n";
      v40 = std::operator<<<std::char_traits<char>>(_Ostr: v39, _Val: "{");
      std::operator<<<std::char_traits<char>>(_Ostr: v40, _Val: (const char *)HIDWORD(v74));
      v41 = 0;
      do
      {
        v42 = aClassname[v41];
        v75.szKey[v41++] = v42;
      }
      while ( v42 != 0 );
      v43 = m_szClass;
      do
      {
        v44 = *v43;
        v37[(_DWORD)v43] = *v43;
        ++v43;
      }
      while ( v44 != 0 );
      MDkeyvalue::SerializeMAP(this: &v75, file, fIsStoring: 1);
      v45 = (int)&v11->m_Nodes.m_Memory.m_pMemory->szName[v38];
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pIntersecting,
        pszFormat: "%.0f %.0f %.0f",
        *(float *)(v45 + 128),
        *(float *)(v45 + 132),
        *(float *)(v45 + 136));
      v46 = 0;
      do
      {
        v47 = aOrigin[v46];
        v75.szKey[v46++] = v47;
      }
      while ( v47 != 0 );
      v48 = pIntersecting;
      v49 = v75.szValue - (char *)pIntersecting;
      do
      {
        v50 = (char)v48->__vftable;
        *((_BYTE *)&v48->__vftable + v49) = v48->__vftable;
        v48 = (BoundBox *)((char *)v48 + 1);
      }
      while ( v50 != 0 );
      MDkeyvalue::SerializeMAP(this: &v75, file, fIsStoring: 1);
      v51 = &v11->m_Nodes.m_Memory.m_pMemory->szName[v38];
      if ( *v51 != 0 )
      {
        if ( v51 != nullptr )
        {
          v52 = (unsigned int)&v11->m_Nodes.m_Memory.m_pMemory->szName[v38
                                                                     + 1
                                                                     + strlen(&v11->m_Nodes.m_Memory.m_pMemory->szName[v38])];
          v11 = v84;
          HIDWORD(v74) = v52 - (_DWORD)(v51 + 1);
          LODWORD(v74) = v51;
        }
        else
        {
          v74 = 0;
        }
        goto LABEL_69;
      }
      if ( v81 != 0 )
      {
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
          this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pIntersecting,
          pszFormat: "%s%02d",
          v11->m_szName,
          v81);
      }
      else
      {
        v53 = v11->m_szName;
        if ( v11 == (CMapPath *)-20 )
        {
          v54 = 0;
        }
        else
        {
          v54 = strlen(v11->m_szName);
          v11 = v84;
        }
        v74 = __PAIR64__(v54, (unsigned int)v53);
LABEL_69:
        ATL::CSimpleStringT<char,0>::SetString(
          this: (ATL::CSimpleStringT<char,0> *)&pIntersecting,
          pszSrc: (const char *)v74,
          nLength: SHIDWORD(v74));
      }
      v55 = 0;
      do
      {
        v56 = aTargetname[v55];
        v75.szKey[v55++] = v56;
      }
      while ( v56 != 0 );
      v57 = pIntersecting;
      v58 = pIntersecting;
      v59 = v75.szValue - (char *)pIntersecting;
      do
      {
        v60 = (char)v58->__vftable;
        *((_BYTE *)&v58->__vftable + v59) = v58->__vftable;
        v58 = (BoundBox *)((char *)v58 + 1);
      }
      while ( v60 != 0 );
      MDkeyvalue::SerializeMAP(this: &v75, file, fIsStoring: 1);
      if ( v83 != v79 || v11->m_iDirection != 0 )
      {
        v61 = v45 + 148;
        if ( v82 != 1 )
          v61 = v45 + 276;
        v62 = 0;
        do
        {
          v63 = aTarget[v62];
          v75.szKey[v62++] = v63;
        }
        while ( v63 != 0 );
        v64 = &v75.szValue[-v61];
        do
        {
          v65 = *(_BYTE *)v61;
          v64[v61] = *(_BYTE *)v61;
          ++v61;
        }
        while ( v65 != 0 );
        MDkeyvalue::SerializeMAP(this: &v75, file, fIsStoring: 1);
      }
      for ( j = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v45 + 408));
            j != 0xFFFF;
            j = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                    this: (CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v45 + 408),
                                    i: j) )
      {
        v67 = *(_DWORD *)(v45 + 412);
        v68 = 604 * (unsigned __int16)j;
        v69 = *(_BYTE *)(v68 + v67 + 12) == 0;
        v70 = (MDkeyvalue *)(v68 + v67 + 12);
        if ( !v69 )
          MDkeyvalue::SerializeMAP(this: v70, file, fIsStoring: 1);
      }
      if ( file != nullptr )
        v71 = (std::ostream *)file->gap10;
      else
        v71 = nullptr;
      HIDWORD(v74) = "\r\n";
      v72 = std::operator<<<std::char_traits<char>>(_Ostr: v71, _Val: "}");
      std::operator<<<std::char_traits<char>>(_Ostr: v72, _Val: (const char *)HIDWORD(v74));
      ++v81;
      if ( v83 != v79 )
      {
        v11 = v84;
        v37 = v78;
        v83 += v82;
        v80 += i;
        v38 = v80;
        continue;
      }
      break;
    }
    if ( v82 == 1 && v84->m_iDirection == 2 )
    {
      v73 = v84->m_Nodes.m_Size;
      if ( v73 > 2 )
      {
        v11 = v84;
        v37 = v78;
        v82 = -1;
        v83 = v73 - 2;
        v79 = 1;
        continue;
      }
    }
    break;
  }
  LOBYTE(bFirstPass) = 1;
  CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&v75);
  bFirstPass = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)&v57[-1].bmaxs.z) <= 0 )
    (*(void (__thiscall **)(_DWORD, float *))(*(_DWORD *)LODWORD(v57[-1].bmins.z) + 4))(
      a1: LODWORD(v57[-1].bmins.z),
      a2: &v57[-1].bmins.z);
}

//------------------------------------------------------------------------------
// Address: 0x1007C250
// Name: public: void CMapPath::SerializeRMF(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPath::SerializeRMF(CMapPath *this, std::fstream *file, int fIsStoring)
{
  CMapPath *v3; // ebx
  std::ostream *v4; // edi
  const char *szName; // esi
  CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short> > *v6; // esi
  unsigned __int16 j; // ax
  unsigned __int16 k; // bx
  MDkeyvalue *p_elem; // ecx
  int v11; // edi
  int v12; // edi
  MDkeyvalue KeyValue; // [esp+Ch] [ebp-41Ch] BYREF
  CMapPathNode node; // [esp+25Ch] [ebp-1CCh] BYREF
  int i; // [esp+410h] [ebp-18h]
  CMapPath *v16; // [esp+414h] [ebp-14h]
  unsigned int v17; // [esp+418h] [ebp-10h]
  int v18; // [esp+424h] [ebp-4h]
  std::fstream *filea; // [esp+430h] [ebp+8h]

  v3 = this;
  v16 = this;
  if ( fIsStoring != 0 )
  {
    v4 = (std::ostream *)file->gap10;
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: this->m_szName, _Count: 128);
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: v3->m_szClass, _Count: 128);
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: (const char *)&v3->m_iDirection, _Count: 4);
    fIsStoring = v3->m_Nodes.m_Size;
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: (const char *)&fIsStoring, _Count: 4);
    i = 0;
    if ( v3->m_Nodes.m_Size > 0 )
    {
      v17 = 0;
      while ( 1 )
      {
        szName = v3->m_Nodes.m_Memory.m_pMemory[v17 / 0x1B4].szName;
        std::ostream::write(this: v4, _Str: szName + 128, _Count: 12);
        std::ostream::write(this: v4, _Str: szName + 140, _Count: 4);
        std::ostream::write(this: v4, _Str: szName, _Count: 128);
        v6 = (CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(szName + 408);
        fIsStoring = 0;
        for ( j = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: v6);
              j != 0xFFFF;
              j = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                    this: v6,
                    i: j) )
        {
          ++fIsStoring;
        }
        std::ostream::write(this: v4, _Str: (const char *)&fIsStoring, _Count: 4);
        for ( k = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: v6);
              k != 0xFFFF;
              k = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                    this: v6,
                    i: k) )
        {
          p_elem = &v6->m_Elements.m_pMemory[k].m_Data.elem;
          if ( p_elem->szKey[0] != 0 )
            MDkeyvalue::SerializeRMF(this: p_elem, file, fIsStoring: 1);
        }
        v17 += 436;
        if ( ++i >= v16->m_Nodes.m_Size )
          break;
        v3 = v16;
      }
    }
  }
  else
  {
    std::istream::read(this: file, _Str: this->m_szName, _Count: 128);
    std::istream::read(this: file, _Str: v3->m_szClass, _Count: 128);
    std::istream::read(this: file, _Str: (char *)&v3->m_iDirection, _Count: 4);
    std::istream::read(this: file, _Str: (char *)&fIsStoring, _Count: 4);
    v11 = fIsStoring;
    CUtlVector<CMapPathNode,CUtlMemory<CMapPathNode,int>>::RemoveAll(this: &v3->m_Nodes);
    if ( v11 > 0 )
    {
      for ( filea = (std::fstream *)v11; filea != nullptr; filea = (std::fstream *)((char *)filea - 1) )
      {
        WCKeyValuesT<WCKVBase_Dict>::WCKeyValuesT<WCKVBase_Dict>(this: &node.kv);
        v12 = 0;
        node.bSelected = 0;
        node.szName[0] = 0;
        v18 = 1;
        std::istream::read(this: file, _Str: (char *)&node.pos, _Count: 12);
        std::istream::read(this: file, _Str: (char *)&node.dwID, _Count: 4);
        if ( GetFileVersion() >= 1.6 )
        {
          std::istream::read(this: file, _Str: node.szName, _Count: 128);
          std::istream::read(this: file, _Str: (char *)&fIsStoring, _Count: 4);
          if ( fIsStoring > 0 )
          {
            do
            {
              KeyValue.szKey[0] = 0;
              KeyValue.szValue[0] = 0;
              LOBYTE(v18) = 2;
              MDkeyvalue::SerializeRMF(this: &KeyValue, file, fIsStoring: 0);
              WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &node.kv, pszKey: KeyValue.szKey, pszValue: KeyValue.szValue);
              LOBYTE(v18) = 1;
              CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&KeyValue);
              ++v12;
            }
            while ( v12 < fIsStoring );
          }
        }
        CUtlVector<CMapPathNode,CUtlMemory<CMapPathNode,int>>::InsertBefore(
          this: &v3->m_Nodes,
          elem: v3->m_Nodes.m_Size,
          src: &node);
        v18 = -1;
        WCKeyValuesT<WCKVBase_Dict>::~WCKeyValuesT<WCKVBase_Dict>(this: &node.kv);
      }
    }
  }
}
