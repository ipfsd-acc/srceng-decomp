// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/sequencepicker.cpp
// Functions: 49
// ============================================================

#include "vgui2\matsys_controls\sequencepicker.h"

//------------------------------------------------------------------------------
// Address: 0x004BCB50
// Name: public: struct mstudioseqdesc_t __near & CStudioHdr::pSeqdesc(int)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall CStudioHdr::pSeqdesc(CStudioHdr *this, int iSequence)
{
  int v2; // eax
  const studiohdr_t *m_pStudioHdr; // ecx

  if ( this->m_pVModel != nullptr )
    return CStudioHdr::pSeqdesc_Internal(this, i: iSequence);
  v2 = iSequence;
  m_pStudioHdr = this->m_pStudioHdr;
  if ( iSequence < 0 || iSequence >= m_pStudioHdr->numlocalseq )
    v2 = 0;
  return (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v2 + m_pStudioHdr->localseqindex);
}

//------------------------------------------------------------------------------
// Address: 0x004BCB90
// Name: public: static char const __near * CSequencePicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSequencePicker::GetPanelClassName()
{
  return "CSequencePicker";
}

//------------------------------------------------------------------------------
// Address: 0x004BCBA0
// Name: public: static char const __near * CSequencePickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSequencePickerFrame::GetPanelClassName()
{
  return "CSequencePickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004BCBB0
// Name: SequenceSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SequenceSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "sequence", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "sequence", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004BCBF0
// Name: ActivitySortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ActivitySortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "activity", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "activity", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004BCC30
// Name: public: virtual void CSequencePicker::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::PerformLayout(CSequencePicker *this)
{
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pPreviewSplitter, x: 0, y: 0, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x004BCC70
// Name: int CompareSequenceDesc(struct mstudioseqdesc_t __near * const __near *,struct mstudioseqdesc_t __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompareSequenceDesc(mstudioseqdesc_t *const *pDescA, mstudioseqdesc_t *const *pDescB)
{
  int v2; // edx
  const char *v3; // eax

  if ( pDescA != nullptr
    && pDescB != nullptr
    && *pDescA != nullptr
    && (v2 = (int)*pDescB, *pDescB != nullptr)
    && (v3 = (char *)*pDescA + (*pDescA)->szlabelindex) != nullptr
    && v2 + *(_DWORD *)(v2 + 4) != 0 )
  {
    return _V_stricmp(s1: v3, s2: (const char *)(v2 + *(_DWORD *)(v2 + 4)));
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BCCB0
// Name: public: enum CSequencePicker::PickType_t CSequencePicker::GetSelectedSequenceType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSequencePicker::GetSelectedSequenceType(CSequencePicker *this)
{
  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    return 1;
  }
  if ( this->m_pActivitiesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    return 2;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BCD10
// Name: private: void CSequencePicker::PlayActivity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::PlayActivity(CSequencePicker *this, const char *pActivityName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szactivitynameindex, s2: pActivityName) == 0 )
    {
      CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: i);
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BCDB0
// Name: private: int CSequencePicker::FindSequence(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSequencePicker::FindSequence(CSequencePicker *this, const char *pSequenceName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szlabelindex, s2: pSequenceName) == 0 )
      return i;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BCE60
// Name: private: virtual void CSequencePickerFrame::OnSequencePreviewChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePickerFrame::OnSequencePreviewChanged(CSequencePickerFrame *this, KeyValues *pKeyValues)
{
  const char *String; // edi
  int v4; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "sequence", defaultValue: nullptr);
  v4 = (int)KeyValues::GetString(this: pKeyValues, keyName: "activity", defaultValue: nullptr);
  if ( String != nullptr || v4 != 0 )
    v4 = 1;
  else
    LOBYTE(v4) = 0;
  this->m_pOpenButton->SetEnabled(this: this->m_pOpenButton, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004BCEC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSequencePicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSequencePicker::GetMessageMap(CSequencePicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSequencePicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSequencePicker::GetMessageMap'::`2'::s_pMap;
  `CSequencePicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
  `CSequencePicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BCEF0
// Name: public: virtual struct PanelAnimationMap __near * CSequencePicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSequencePicker::GetAnimMap(CSequencePicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CSequencePicker");
}

//------------------------------------------------------------------------------
// Address: 0x004BCF00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSequencePicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSequencePicker::GetKBMap(CSequencePicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSequencePicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSequencePicker::GetKBMap'::`2'::s_pMap;
  `CSequencePicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSequencePicker");
  `CSequencePicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BCFA0
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x004BCFD0
// Name: public: static void CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BD060
// Name: public: static void CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextKillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BD0F0
// Name: public: static void CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextNewLine";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BD180
// Name: public: static void CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BD210
// Name: public: static void CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BD2A0
// Name: public: static void CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BD330
// Name: public: static void CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar'::`2'::bAdded )
  {
    `CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePickerFrame");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SequencePreviewChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BD3C0
// Name: public: CSequencePicker::CSequencePicker(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSequencePicker *__thiscall CSequencePicker::CSequencePicker(CSequencePicker *this, vgui::Panel *pParent, char nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // ebx
  CMDLPanel *v10; // eax
  CMDLPanel *v11; // eax
  vgui::PropertySheet *v12; // eax
  vgui::PropertySheet *v13; // eax
  vgui::PropertyPage *v14; // eax
  vgui::PropertyPage *v15; // eax
  vgui::PropertySheet *m_pViewsSheet; // ecx
  int v17; // ebx
  vgui::Slider **m_pLayerSequenceSliders; // edi
  vgui::ComboBox *v19; // eax
  vgui::ComboBox *v20; // eax
  int v21; // eax
  vgui::Slider *v22; // eax
  vgui::Slider *v23; // eax
  int v24; // ebx
  vgui::TextEntry **m_pPoseValueEntries; // edi
  vgui::Slider *v26; // eax
  vgui::Slider *v27; // eax
  vgui::TextEntry *v28; // eax
  vgui::TextEntry *v29; // eax
  vgui::ComboBox *v30; // eax
  vgui::ComboBox *v31; // eax
  vgui::Button *v32; // eax
  vgui::Button *v33; // eax
  vgui::CheckButton *v34; // eax
  vgui::CheckButton *v35; // eax
  vgui::ListPanel *v36; // eax
  vgui::ListPanel *v37; // eax
  vgui::PropertyPage *v38; // eax
  vgui::PropertyPage *v39; // eax
  vgui::PropertySheet *v40; // ecx
  vgui::ListPanel *v41; // eax
  vgui::ListPanel *v42; // eax
  char controlName[64]; // [esp+Ch] [ebp-40h] BYREF
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF
  vgui::Panel *i; // [esp+54h] [ebp+8h]
  int ia; // [esp+54h] [ebp+8h]
  int ib; // [esp+54h] [ebp+8h]

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "SequencePicker");
  this->__vftable = (CSequencePicker_vtbl *)&CSequencePicker::`vftable';
  if ( `CSequencePicker::ChainToMap'::`2'::chained == 0 )
  {
    `CSequencePicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    v4->pfnClassName = CSequencePicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CSequencePicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSequencePicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSequencePicker");
    v5->pfnClassName = CSequencePicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CSequencePicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSequencePicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSequencePicker");
    v6->pfnClassName = CSequencePicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_Filter);
  this->m_bSequenceParams = (nFlags & 0x11) == 17;
  this->m_hSelectedMDL = -1;
  this->m_pRootMotionCheckBox = nullptr;
  this->m_pPoseDefaultButton = nullptr;
  _V_memset(dest: this->m_pLayerSequenceSelectors, fill: 0, count: 16);
  _V_memset(dest: this->m_pLayerSequenceSliders, fill: 0, count: 16);
  _V_memset(dest: this->m_pPoseValueSliders, fill: 0, count: 24);
  _V_memset(dest: this->m_pPoseValueEntries, fill: 0, count: 24);
  _V_memset(dest: this->m_pPoseParameterName, fill: 0, count: 24);
  _V_memset(dest: this->m_SequenceLayers, fill: 0, count: 32);
  _V_memset(dest: this->m_PoseControlMap, fill: -1, count: 24);
  _V_memset(dest: this->m_PoseParameters, fill: 0, count: 96);
  v7 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "PreviewSplitter",
           mode: SPLITTER_MODE_HORIZONTAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pPreviewSplitter = v8;
  Child = vgui::Panel::GetChild(this: v8, index: 0);
  i = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v10 = (CMDLPanel *)MemAlloc_Alloc(nSize: 0xBE4u);
  if ( v10 != nullptr )
    v11 = CMDLPanel::CMDLPanel(this: v10, pParent: Child, pName: "MDLPreview");
  else
    v11 = nullptr;
  this->m_pMDLPreview = v11;
  vgui::Panel::SetSkipChildDuringPainting(this, child: v11);
  v12 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v12 != nullptr )
    v13 = vgui::PropertySheet::PropertySheet(this: v12, parent: i, panelName: "ViewsSheet", draggableTabs: false);
  else
    v13 = nullptr;
  this->m_pViewsSheet = v13;
  v13->AddActionSignalTarget_2(this: v13, a2: this);
  this->m_pSequencesPage = nullptr;
  this->m_pSequencesList = nullptr;
  if ( (nFlags & 1) != 0 )
  {
    v14 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v14 != nullptr )
      v15 = vgui::PropertyPage::PropertyPage(this: v14, parent: this->m_pViewsSheet, panelName: "SequencesPage");
    else
      v15 = nullptr;
    m_pViewsSheet = this->m_pViewsSheet;
    this->m_pSequencesPage = v15;
    m_pViewsSheet->AddPage(this: m_pViewsSheet, a2: v15, a3: "Sequences", a4: nullptr, a5: false, a6: -1);
    if ( this->m_bSequenceParams )
    {
      ia = 0;
      v17 = 10;
      m_pLayerSequenceSliders = this->m_pLayerSequenceSliders;
      do
      {
        V_snprintf(pDest: controlName, maxLen: 64, pFormat: "LayerSequence%i", ia);
        v19 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
        if ( v19 != nullptr )
          v20 = vgui::ComboBox::ComboBox(
                  this: v19,
                  parent: this->m_pSequencesPage,
                  panelName: controlName,
                  numLines: 32,
                  allowEdit: false);
        else
          v20 = nullptr;
        *(m_pLayerSequenceSliders - 4) = (vgui::Slider *)v20;
        vgui::Panel::SetAutoResize(
          this: v20,
          pinCorner: PIN_TOPLEFT,
          resizeDir: AUTORESIZE_NO,
          nPinOffsetX: 10,
          nPinOffsetY: v17,
          nUnpinnedCornerOffsetX: 0,
          nUnpinnedCornerOffsetY: 0);
        vgui::Panel::SetWide(this: *(m_pLayerSequenceSliders - 4), wide: 180);
        (*(m_pLayerSequenceSliders - 4))->AddActionSignalTarget_2(this: *(m_pLayerSequenceSliders - 4), a2: this);
        v21 = ia;
        if ( ia > 0 )
        {
          v17 += 24;
          V_snprintf(pDest: controlName, maxLen: 64, pFormat: "LayerSequenceWeight%i", ia);
          v22 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
          if ( v22 != nullptr )
            v23 = vgui::Slider::Slider(this: v22, parent: this->m_pSequencesPage, panelName: controlName);
          else
            v23 = nullptr;
          *m_pLayerSequenceSliders = v23;
          vgui::Panel::SetAutoResize(
            this: v23,
            pinCorner: PIN_TOPLEFT,
            resizeDir: AUTORESIZE_NO,
            nPinOffsetX: 10,
            nPinOffsetY: v17,
            nUnpinnedCornerOffsetX: 0,
            nUnpinnedCornerOffsetY: 0);
          vgui::Panel::SetWide(this: *m_pLayerSequenceSliders, wide: 180);
          (*m_pLayerSequenceSliders)->SetRange(this: *m_pLayerSequenceSliders, a2: 0, a3: 100);
          (*m_pLayerSequenceSliders)->AddActionSignalTarget_2(this: *m_pLayerSequenceSliders, a2: this);
          v21 = ia;
        }
        v17 += 40;
        ++m_pLayerSequenceSliders;
        ia = v21 + 1;
      }
      while ( v21 + 1 < 4 );
      ib = 10;
      v24 = 0;
      m_pPoseValueEntries = this->m_pPoseValueEntries;
      do
      {
        V_snprintf(pDest: controlName, maxLen: 64, pFormat: "PoseValueSlider%i", v24);
        v26 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
        if ( v26 != nullptr )
          v27 = vgui::Slider::Slider(this: v26, parent: this->m_pSequencesPage, panelName: controlName);
        else
          v27 = nullptr;
        *(m_pPoseValueEntries - 6) = (vgui::TextEntry *)v27;
        vgui::Panel::SetAutoResize(
          this: v27,
          pinCorner: PIN_TOPLEFT,
          resizeDir: AUTORESIZE_NO,
          nPinOffsetX: 210,
          nPinOffsetY: ib,
          nUnpinnedCornerOffsetX: 0,
          nUnpinnedCornerOffsetY: 0);
        vgui::Panel::SetWide(this: *(m_pPoseValueEntries - 6), wide: 120);
        (*(m_pPoseValueEntries - 6))->GetText(this: *(m_pPoseValueEntries - 6), a2: nullptr, a3: 100);
        (*(m_pPoseValueEntries - 6))->AddActionSignalTarget_2(this: *(m_pPoseValueEntries - 6), a2: this);
        V_snprintf(pDest: controlName, maxLen: 64, pFormat: "PoseValueEntry%i", v24);
        v28 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
        if ( v28 != nullptr )
          v29 = vgui::TextEntry::TextEntry(this: v28, parent: this->m_pSequencesPage, panelName: controlName);
        else
          v29 = nullptr;
        *m_pPoseValueEntries = v29;
        vgui::Panel::SetAutoResize(
          this: v29,
          pinCorner: PIN_TOPLEFT,
          resizeDir: AUTORESIZE_NO,
          nPinOffsetX: 330,
          nPinOffsetY: ib,
          nUnpinnedCornerOffsetX: 0,
          nUnpinnedCornerOffsetY: 0);
        vgui::Panel::SetWide(this: *m_pPoseValueEntries, wide: 40);
        (*m_pPoseValueEntries)->SendNewLine(this: *m_pPoseValueEntries, a2: true);
        (*m_pPoseValueEntries)->AddActionSignalTarget_2(this: *m_pPoseValueEntries, a2: this);
        V_snprintf(pDest: controlName, maxLen: 64, pFormat: "PoseParameterName%i", v24);
        v30 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
        if ( v30 != nullptr )
          v31 = vgui::ComboBox::ComboBox(
                  this: v30,
                  parent: this->m_pSequencesPage,
                  panelName: controlName,
                  numLines: 8,
                  allowEdit: false);
        else
          v31 = nullptr;
        m_pPoseValueEntries[6] = v31;
        vgui::Panel::SetAutoResize(
          this: v31,
          pinCorner: PIN_TOPLEFT,
          resizeDir: AUTORESIZE_NO,
          nPinOffsetX: 380,
          nPinOffsetY: ib,
          nUnpinnedCornerOffsetX: 0,
          nUnpinnedCornerOffsetY: 0);
        vgui::Panel::SetWide(this: m_pPoseValueEntries[6], wide: 120);
        m_pPoseValueEntries[6]->AddActionSignalTarget_2(this: m_pPoseValueEntries[6], a2: this);
        ib += 32;
        ++v24;
        ++m_pPoseValueEntries;
      }
      while ( v24 < 6 );
      v32 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
      if ( v32 != nullptr )
        v33 = vgui::Button::Button(
                this: v32,
                parent: this->m_pSequencesPage,
                panelName: "DefaultsButton",
                text: "#SequencePicker_Defaults",
                pActionSignalTarget: this,
                pCmd: "ResetToDefaults");
      else
        v33 = nullptr;
      this->m_pPoseDefaultButton = v33;
      v33->SetContentAlignment(this: v33, a2: a_center);
      vgui::Panel::SetWide(this: this->m_pPoseDefaultButton, wide: 100);
      vgui::Panel::SetAutoResize(
        this: this->m_pPoseDefaultButton,
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_NO,
        nPinOffsetX: 210,
        nPinOffsetY: ib,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
      this->m_pPoseDefaultButton->SetEnabled(this: this->m_pPoseDefaultButton, a2: false);
      v34 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
      if ( v34 != nullptr )
        v35 = vgui::CheckButton::CheckButton(
                this: v34,
                parent: this->m_pSequencesPage,
                panelName: "RootMotionCheckBox",
                text: "#SequencePicker_RootMotion");
      else
        v35 = nullptr;
      this->m_pRootMotionCheckBox = v35;
      vgui::Panel::SetAutoResize(
        this: v35,
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_NO,
        nPinOffsetX: 324,
        nPinOffsetY: ib,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
      vgui::Panel::SetWide(this: this->m_pRootMotionCheckBox, wide: 150);
      this->m_pRootMotionCheckBox->SetSelected(this: this->m_pRootMotionCheckBox, a2: true);
    }
    else
    {
      v36 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
      if ( v36 != nullptr )
        v37 = vgui::ListPanel::ListPanel(this: v36, parent: this->m_pSequencesPage, panelName: "SequencesList");
      else
        v37 = nullptr;
      this->m_pSequencesList = v37;
      v37->AddColumnHeader(this: v37, a2: 0, a3: "sequence", a4: "sequence", a5: 52, a6: 0);
      this->m_pSequencesList->AddActionSignalTarget_2(this: this->m_pSequencesList, a2: this);
      this->m_pSequencesList->SetSelectIndividualCells(this: this->m_pSequencesList, a2: true);
      this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: ".MDL file contains no activities");
      this->m_pSequencesList->SetDragEnabled(this: this->m_pSequencesList, a2: true);
      vgui::Panel::SetAutoResize(
        this: this->m_pSequencesList,
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_DOWNANDRIGHT,
        nPinOffsetX: 0,
        nPinOffsetY: 0,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
      this->m_pSequencesList->SetSortFunc(this: this->m_pSequencesList, a2: 0, a3: SequenceSortFunc);
      this->m_pSequencesList->SetSortColumn(this: this->m_pSequencesList, a2: 0);
    }
  }
  this->m_pActivitiesPage = nullptr;
  this->m_pActivitiesList = nullptr;
  if ( (nFlags & 2) != 0 )
  {
    v38 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v38 != nullptr )
      v39 = vgui::PropertyPage::PropertyPage(this: v38, parent: this->m_pViewsSheet, panelName: "ActivitiesPage");
    else
      v39 = nullptr;
    v40 = this->m_pViewsSheet;
    this->m_pActivitiesPage = v39;
    v40->AddPage(this: v40, a2: v39, a3: "Activities", a4: nullptr, a5: false, a6: -1);
    v41 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
    if ( v41 != nullptr )
      v42 = vgui::ListPanel::ListPanel(this: v41, parent: this->m_pActivitiesPage, panelName: "ActivitiesList");
    else
      v42 = nullptr;
    this->m_pActivitiesList = v42;
    v42->AddColumnHeader(this: v42, a2: 0, a3: "activity", a4: "activity", a5: 52, a6: 0);
    this->m_pActivitiesList->AddActionSignalTarget_2(this: this->m_pActivitiesList, a2: this);
    this->m_pActivitiesList->SetSelectIndividualCells(this: this->m_pActivitiesList, a2: true);
    this->m_pActivitiesList->SetEmptyListText_2(this: this->m_pActivitiesList, a2: ".MDL file contains no activities");
    this->m_pActivitiesList->SetDragEnabled(this: this->m_pActivitiesList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pActivitiesList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 0,
      nPinOffsetY: 0,
      nUnpinnedCornerOffsetX: 0,
      nUnpinnedCornerOffsetY: 0);
    this->m_pActivitiesList->SetSortFunc(this: this->m_pActivitiesList, a2: 0, a3: ActivitySortFunc);
    this->m_pActivitiesList->SetSortColumn(this: this->m_pActivitiesList, a2: 0);
  }
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/sequencepicker.res",
    dialogID: 0);
  vgui::Panel::MakeReadyForUse(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BDC00
// Name: public: char const __near * CSequencePicker::GetSelectedSequenceName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSequencePicker::GetSelectedSequenceName(CSequencePicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  IMDLCache *v5; // eax
  const studiohdr_t *v6; // eax
  int m_nSequenceIndex; // esi
  int v8; // eax
  mstudioseqdesc_t *v9; // eax
  char *v10; // esi
  int v11; // eax
  KeyValues *v12; // eax
  CStudioHdr studioHdr; // [esp+4h] [ebp-64h] BYREF

  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    if ( this->m_pSequencesList != nullptr )
    {
      v2 = this->m_pSequencesList->GetSelectedItem(this: this->m_pSequencesList, a2: 0);
      if ( v2 >= 0 )
      {
        v3 = this->m_pSequencesList->GetItem(this: this->m_pSequencesList, a2: v2);
        return KeyValues::GetString(this: v3, keyName: "sequence", defaultValue: nullptr);
      }
    }
    else if ( this->m_bSequenceParams )
    {
      v5 = vgui::MDLCache();
      v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
      if ( v6 != nullptr )
      {
        CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v6, mdlcache: nullptr);
        m_nSequenceIndex = this->m_SequenceLayers[0].m_nSequenceIndex;
        if ( m_nSequenceIndex >= 0 )
        {
          v8 = studioHdr.m_pVModel != nullptr
             ? CStudioHdr::GetNumSeq_Internal(this: &studioHdr)
             : studioHdr.m_pStudioHdr->numlocalseq;
          if ( m_nSequenceIndex < v8 )
          {
            v9 = CStudioHdr::pSeqdesc(this: &studioHdr, iSequence: m_nSequenceIndex);
            v10 = (char *)v9 + v9->szlabelindex;
            CStudioHdr::~CStudioHdr(this: &studioHdr);
            return v10;
          }
        }
        CStudioHdr::~CStudioHdr(this: &studioHdr);
      }
    }
  }
  else if ( this->m_pActivitiesPage != nullptr
         && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    v11 = this->m_pActivitiesList->GetSelectedItem(this: this->m_pActivitiesList, a2: 0);
    if ( v11 >= 0 )
    {
      v12 = this->m_pActivitiesList->GetItem(this: this->m_pActivitiesList, a2: v11);
      return KeyValues::GetString(this: v12, keyName: "activity", defaultValue: nullptr);
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004BDD60
// Name: public: void CSequencePicker::GetPoseParameters(class CUtlVector<float,class CUtlMemory<float,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::GetPoseParameters(
        CSequencePicker *this,
        CUtlVector<float,CUtlMemory<float,int> > *poseParameters)
{
  IMDLCache *v3; // eax
  const studiohdr_t *v4; // eax
  int NumPoseParameters; // eax
  float *m_PoseParameters; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  float *m_pMemory; // ecx
  int v11; // eax
  float *v12; // eax
  int *v13; // eax
  int *v14; // eax
  const studiohdr_t **v15; // eax
  CStudioHdr studioHdr; // [esp+8h] [ebp-64h] BYREF
  CUtlVector<float,CUtlMemory<float,int> > *poseParametersa; // [esp+74h] [ebp+8h]

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v4, mdlcache: nullptr);
  NumPoseParameters = CStudioHdr::GetNumPoseParameters(this: &studioHdr);
  if ( NumPoseParameters > 0 )
  {
    m_PoseParameters = this->m_PoseParameters;
    for ( poseParametersa = (CUtlVector<float,CUtlMemory<float,int> > *)NumPoseParameters;
          poseParametersa != nullptr;
          poseParametersa = (CUtlVector<float,CUtlMemory<float,int> > *)((char *)poseParametersa - 1) )
    {
      m_Size = poseParameters->m_Size;
      m_nAllocationCount = poseParameters->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)poseParameters,
          num: m_Size - m_nAllocationCount + 1);
      ++poseParameters->m_Size;
      m_pMemory = poseParameters->m_Memory.m_pMemory;
      v11 = poseParameters->m_Size - m_Size - 1;
      poseParameters->m_pElements = poseParameters->m_Memory.m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
      v12 = &poseParameters->m_Memory.m_pMemory[m_Size];
      if ( v12 != nullptr )
        *v12 = *m_PoseParameters;
      ++m_PoseParameters;
    }
  }
  CStudioHdr::Term(this: &studioHdr);
  v13 = studioHdr.m_boneParent.m_Memory.m_pMemory;
  studioHdr.m_boneParent.m_Size = 0;
  if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneParent.m_Memory.m_pMemory);
      v13 = nullptr;
      studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_boneParent.m_pElements = v13;
  if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v13 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
      studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v14 = studioHdr.m_boneFlags.m_Memory.m_pMemory;
  studioHdr.m_boneFlags.m_Size = 0;
  if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneFlags.m_Memory.m_pMemory);
      v14 = nullptr;
      studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_boneFlags.m_pElements = v14;
  if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v14 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
      studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v15 = studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
  studioHdr.m_pStudioHdrCache.m_Size = 0;
  if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
      v15 = nullptr;
      studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_pStudioHdrCache.m_pElements = v15;
  if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
}

//------------------------------------------------------------------------------
// Address: 0x004BDEF0
// Name: public: void CSequencePicker::GetSeqenceLayers(class CUtlVector<struct MDLSquenceLayer_t,class CUtlMemory<struct MDLSquenceLayer_t,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::GetSeqenceLayers(
        CSequencePicker *this,
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *sequenceLayers)
{
  MDLSquenceLayer_t *v2; // esi
  int i; // edi

  v2 = &this->m_SequenceLayers[1];
  for ( i = 3; i != 0; --i )
  {
    if ( v2->m_nSequenceIndex >= 0 && v2->m_flWeight > 0.0 )
      CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
        this: sequenceLayers,
        elem: sequenceLayers->m_Size,
        src: (const vgui::PropertySheet::Page_t *)v2);
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BDF30
// Name: private: void CSequencePicker::SetPoseParameterValue(float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::SetPoseParameterValue(
        CSequencePicker *this,
        float flPoseParameterValue,
        unsigned int nParameterIndex)
{
  IMDLCache *v5; // eax
  const studiohdr_t *v6; // eax
  const mstudioposeparamdesc_t *v7; // edi
  vgui::Slider **m_pPoseValueSliders; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  CStudioHdr studioHdr; // [esp+20h] [ebp-84h] BYREF
  char valueText[32]; // [esp+84h] [ebp-20h] BYREF
  int nParameterIndexa; // [esp+B0h] [ebp+Ch]

  if ( nParameterIndex <= 0x17 )
  {
    v5 = vgui::MDLCache();
    v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v6, mdlcache: nullptr);
    v7 = CStudioHdr::pPoseParameter(this: &studioHdr, i: nParameterIndex);
    this->m_PoseParameters[nParameterIndex] = flPoseParameterValue;
    CMDLPanel::SetPoseParameters(this: this->m_pMDLPreview, pPoseParameters: this->m_PoseParameters, nCount: 24);
    m_pPoseValueSliders = this->m_pPoseValueSliders;
    for ( nParameterIndexa = 6; nParameterIndexa != 0; --nParameterIndexa )
    {
      if ( m_pPoseValueSliders[26] == (vgui::Slider *)nParameterIndex )
      {
        v9 = (float)(flPoseParameterValue * 2.0) - 1.0;
        if ( v9 < 0.0 )
          LODWORD(v10) = COERCE_UNSIGNED_INT(fsqrt(-v9)) ^ 0x80000000;
        else
          v10 = fsqrt(v9);
        (*m_pPoseValueSliders)->SetValue(
          this: *m_pPoseValueSliders,
          a2: (int)(float)((float)((float)((float)(v10 + 1.0) * 0.5) * 100.0) + 0.5),
          a3: false);
        V_snprintf(
          pDest: valueText,
          maxLen: 32,
          pFormat: "%0.2f",
          (float)((float)((float)(v7->end - v7->start) * flPoseParameterValue) + v7->start));
        ((void (__thiscall *)(vgui::Slider *, char *))m_pPoseValueSliders[6]->SetValue)(
          a1: m_pPoseValueSliders[6],
          a2: valueText);
      }
      ++m_pPoseValueSliders;
    }
    CStudioHdr::Term(this: &studioHdr);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_boneParent);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_boneFlags);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BE0C0
// Name: private: void CSequencePicker::UpdatePoseControlsFromParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::UpdatePoseControlsFromParameters(CSequencePicker *this)
{
  IMDLCache *v2; // eax
  const studiohdr_t *v3; // eax
  signed int v4; // esi
  float *m_PoseParameters; // edi
  int *m_pMemory; // eax
  int *v7; // eax
  const studiohdr_t **v8; // eax
  CStudioHdr studioHdr; // [esp+18h] [ebp-68h] BYREF
  int nNumParams; // [esp+7Ch] [ebp-4h]

  v2 = vgui::MDLCache();
  v3 = v2->GetStudioHdr(this: v2, a2: this->m_hSelectedMDL);
  v4 = 0;
  CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v3, mdlcache: nullptr);
  nNumParams = CStudioHdr::GetNumPoseParameters(this: &studioHdr);
  if ( nNumParams > 0 )
  {
    m_PoseParameters = this->m_PoseParameters;
    do
      CSequencePicker::SetPoseParameterValue(this, flPoseParameterValue: *m_PoseParameters++, nParameterIndex: v4++);
    while ( v4 < nNumParams );
  }
  CStudioHdr::Term(this: &studioHdr);
  m_pMemory = studioHdr.m_boneParent.m_Memory.m_pMemory;
  studioHdr.m_boneParent.m_Size = 0;
  if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneParent.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_boneParent.m_pElements = m_pMemory;
  if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v7 = studioHdr.m_boneFlags.m_Memory.m_pMemory;
  studioHdr.m_boneFlags.m_Size = 0;
  if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneFlags.m_Memory.m_pMemory);
      v7 = nullptr;
      studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_boneFlags.m_pElements = v7;
  if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v8 = studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
  studioHdr.m_pStudioHdrCache.m_Size = 0;
  if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
      v8 = nullptr;
      studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_pStudioHdrCache.m_pElements = v8;
  if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v8 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x004BE210
// Name: private: virtual void CSequencePicker::OnTextKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnTextKillFocus(CSequencePicker *this, KeyValues *pData)
{
  vgui::TextEntry *Ptr; // eax
  int v4; // esi
  vgui::TextEntry **i; // ecx
  IMDLCache *v6; // eax
  const studiohdr_t *v7; // eax
  int v8; // esi
  const mstudioposeparamdesc_t *v9; // eax
  float start; // xmm0_4
  float end; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  int *m_pMemory; // eax
  int *v16; // eax
  const studiohdr_t **v17; // eax
  CStudioHdr studioHdr; // [esp+18h] [ebp-64h] BYREF
  float flValue; // [esp+84h] [ebp+8h]

  Ptr = (vgui::TextEntry *)KeyValues::GetPtr(this: pData, keyName: "panel", defaultValue: nullptr);
  v4 = 0;
  for ( i = this->m_pPoseValueEntries; Ptr != *i; ++i )
  {
    if ( ++v4 >= 6 )
      return;
  }
  if ( v4 >= 0 )
  {
    flValue = this->m_pPoseValueEntries[v4]->GetValueAsFloat(this: this->m_pPoseValueEntries[v4]);
    v6 = vgui::MDLCache();
    v7 = v6->GetStudioHdr(this: v6, a2: this->m_hSelectedMDL);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v7, mdlcache: nullptr);
    v8 = this->m_PoseControlMap[v4];
    v9 = CStudioHdr::pPoseParameter(this: &studioHdr, i: v8);
    start = v9->start;
    end = v9->end;
    if ( end <= start )
      v12 = v9->end;
    else
      v12 = v9->start;
    if ( start > end )
      end = v9->start;
    v13 = flValue;
    if ( v12 <= flValue )
      v14 = flValue;
    else
      v14 = v12;
    if ( v14 <= end )
    {
      if ( v12 > flValue )
        v13 = v12;
    }
    else
    {
      v13 = end;
    }
    CSequencePicker::SetPoseParameterValue(
      this,
      flPoseParameterValue: (float)(v13 - v12) / (float)(end - v12),
      nParameterIndex: v8);
    CStudioHdr::Term(this: &studioHdr);
    m_pMemory = studioHdr.m_boneParent.m_Memory.m_pMemory;
    studioHdr.m_boneParent.m_Size = 0;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneParent.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneParent.m_pElements = m_pMemory;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v16 = studioHdr.m_boneFlags.m_Memory.m_pMemory;
    studioHdr.m_boneFlags.m_Size = 0;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneFlags.m_Memory.m_pMemory);
        v16 = nullptr;
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneFlags.m_pElements = v16;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v16 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v17 = studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
    studioHdr.m_pStudioHdrCache.m_Size = 0;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
        v17 = nullptr;
        studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_pStudioHdrCache.m_pElements = v17;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v17 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BE3E0
// Name: public: CSequencePickerFrame::CSequencePickerFrame(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSequencePickerFrame *__thiscall CSequencePickerFrame::CSequencePickerFrame(
        CSequencePickerFrame *this,
        vgui::Panel *pParent,
        char nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CSequencePicker *v7; // eax
  CSequencePicker *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: "SequencePickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CSequencePickerFrame_vtbl *)&CSequencePickerFrame::`vftable';
  if ( `CSequencePickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CSequencePickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSequencePickerFrame");
    v4->pfnClassName = CSequencePickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CSequencePickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSequencePickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSequencePickerFrame");
    v5->pfnClassName = CSequencePickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CSequencePickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSequencePickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSequencePickerFrame");
    v6->pfnClassName = CSequencePickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CSequencePicker *)MemAlloc_Alloc(nSize: 0x2C0u);
  if ( v7 != nullptr )
    v8 = CSequencePicker::CSequencePicker(this: v7, pParent: this, nFlags);
  else
    v8 = nullptr;
  this->m_pPicker = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OpenButton",
            text: "#FileOpenDialog_Open",
            pActionSignalTarget: this,
            pCmd: "Open");
  else
    v10 = nullptr;
  this->m_pOpenButton = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/sequencepickerframe.res",
    dialogID: 0);
  this->m_pOpenButton->SetEnabled(this: this->m_pOpenButton, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BE580
// Name: public: virtual struct vgui::PanelMessageMap __near * CSequencePickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSequencePickerFrame::GetMessageMap(CSequencePickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSequencePickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSequencePickerFrame::GetMessageMap'::`2'::s_pMap;
  `CSequencePickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSequencePickerFrame");
  `CSequencePickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BE5B0
// Name: public: virtual struct PanelAnimationMap __near * CSequencePickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSequencePickerFrame::GetAnimMap(CSequencePickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CSequencePickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004BE5C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSequencePickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSequencePickerFrame::GetKBMap(CSequencePickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSequencePickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSequencePickerFrame::GetKBMap'::`2'::s_pMap;
  `CSequencePickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSequencePickerFrame");
  `CSequencePickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BE620
// Name: public: virtual void CSequencePickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSequencePickerFrame::OnCommand(CSequencePickerFrame *this@<ecx>, int a2@<ebx>, const char *pCommand)
{
  CSequencePickerFrame *v3; // edi
  int SelectedSequenceType; // eax
  const char *SelectedSequenceName; // ebx
  int v6; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // ebx
  CSequencePicker *m_pPicker; // ecx
  KeyValues *v10; // eax
  KeyValues *v11; // edi
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  float *v13; // eax
  CSequencePicker *v14; // ecx
  int m_Size; // edi
  int i; // esi
  CSequencePickerFrame *v17; // esi
  CSequencePicker *v18; // eax
  bool v19; // al
  KeyValues *v20; // eax
  char poseParameterName[32]; // [esp+14h] [ebp-6Ch] BYREF
  char layerName[32]; // [esp+34h] [ebp-4Ch] BYREF
  CUtlVector<float,CUtlMemory<float,int> > poseParameters; // [esp+54h] [ebp-2Ch] BYREF
  CUtlVector<MDLSquenceLayer_t,CUtlMemory<MDLSquenceLayer_t,int> > sequenceLayers; // [esp+68h] [ebp-18h] BYREF
  CSequencePickerFrame *v26; // [esp+7Ch] [ebp-4h]
  CSequencePicker::PickType_t type; // [esp+88h] [ebp+8h]

  v3 = this;
  v26 = this;
  if ( _V_stricmp(s1: pCommand, s2: "Open") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this: v3, command: pCommand);
    else
      v3->CloseModal(this: v3);
  }
  else
  {
    SelectedSequenceType = CSequencePicker::GetSelectedSequenceType(this: v3->m_pPicker);
    type = SelectedSequenceType;
    if ( SelectedSequenceType == 1 || SelectedSequenceType == 2 )
    {
      SelectedSequenceName = CSequencePicker::GetSelectedSequenceName(this: v3->m_pPicker);
      v6 = 0;
      if ( SelectedSequenceName != nullptr )
      {
        v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( type == PICK_SEQUENCES )
        {
          if ( v7 != nullptr )
            v8 = KeyValues::KeyValues(
                   this: v7,
                   setName: "SequenceSelected",
                   firstKey: "sequence",
                   firstValue: SelectedSequenceName);
          else
            v8 = nullptr;
          m_pPicker = v3->m_pPicker;
          memset(&sequenceLayers, 0, sizeof(sequenceLayers));
          CSequencePicker::GetSeqenceLayers(
            this: m_pPicker,
            (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&sequenceLayers);
          KeyValues::SetInt(this: v8, keyName: "numLayers", value: sequenceLayers.m_Size);
          if ( sequenceLayers.m_Size > 0 )
          {
            do
            {
              V_snprintf(pDest: layerName, maxLen: 32, pFormat: "layer%i", v6);
              v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v10 != nullptr )
                v11 = KeyValues::KeyValues(this: v10, setName: layerName);
              else
                v11 = nullptr;
              KeyValues::SetInt(
                this: v11,
                keyName: "sequence",
                value: sequenceLayers.m_Memory.m_pMemory[v6].m_nSequenceIndex);
              KeyValues::SetFloat(this: v11, keyName: "weight", value: sequenceLayers.m_Memory.m_pMemory[v6].m_flWeight);
              KeyValues::AddSubKey(this: v8, pSubkey: v11);
              ++v6;
            }
            while ( v6 < sequenceLayers.m_Size );
            v3 = v26;
          }
          Alloc_2 = _g_pMemAlloc->Alloc_2;
          poseParameters.m_Memory.m_nAllocationCount = 24;
          poseParameters.m_Memory.m_nGrowSize = 0;
          v13 = (float *)((int (__thiscall *)(IMemAlloc *, int, int))Alloc_2)(a1: _g_pMemAlloc, a2: 96, a3: a2);
          v14 = v3->m_pPicker;
          poseParameters.m_Memory.m_pMemory = v13;
          poseParameters.m_pElements = v13;
          poseParameters.m_Size = 0;
          CSequencePicker::GetPoseParameters(this: v14, &poseParameters);
          m_Size = poseParameters.m_Size;
          KeyValues::SetInt(this: v8, keyName: "numPoseParameters", value: poseParameters.m_Size);
          for ( i = 0; i < m_Size; ++i )
          {
            V_snprintf(pDest: poseParameterName, maxLen: 32, pFormat: "poseParameter%i", i);
            KeyValues::SetFloat(this: v8, keyName: poseParameterName, value: poseParameters.m_Memory.m_pMemory[i]);
          }
          v17 = v26;
          v18 = v26->m_pPicker;
          v19 = v18->m_pRootMotionCheckBox != nullptr
             && v18->m_pRootMotionCheckBox->IsSelected(this: v18->m_pRootMotionCheckBox);
          KeyValues::SetInt(this: v8, keyName: "rootMotion", value: v19);
          ((void (__thiscall *)(CSequencePickerFrame *))v17->PostActionSignal)(a1: v17);
          if ( poseParameters.m_Memory.m_nGrowSize >= 0 && poseParameters.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: poseParameters.m_Memory.m_pMemory);
          if ( sequenceLayers.m_Memory.m_nGrowSize >= 0 && sequenceLayers.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sequenceLayers.m_Memory.m_pMemory);
          v3 = v17;
        }
        else if ( v7 != nullptr )
        {
          v20 = KeyValues::KeyValues(
                  this: v7,
                  setName: "SequenceSelected",
                  firstKey: "activity",
                  firstValue: SelectedSequenceName);
          v3->PostActionSignal(this: v3, a2: v20);
        }
        else
        {
          v3->PostActionSignal(this: v3, a2: nullptr);
        }
        v3->CloseModal(this: v3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BE8E0
// Name: private: void CSequencePicker::UpdateAvailablePoseParmeters(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSequencePicker::UpdateAvailablePoseParmeters(CSequencePicker *this@<ecx>, int a2@<esi>)
{
  CSequencePicker *v2; // ebx
  bool v3; // zf
  IMDLCache *v4; // eax
  const studiohdr_t *v5; // eax
  int *p_m_nSequenceIndex; // esi
  int v7; // edi
  int v8; // eax
  int NumPoseParameters; // esi
  int v10; // edi
  int v11; // eax
  int v12; // eax
  vgui::Slider **m_pPoseValueSliders; // ebx
  vgui::Slider *v14; // ecx
  vgui::ComboBox *v15; // esi
  int v16; // edi
  int v17; // ebx
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  int v20; // eax
  vgui::Slider **v21; // esi
  int v22; // ebx
  vgui::Slider *v23; // ecx
  int *m_pMemory; // eax
  int *v25; // eax
  const studiohdr_t **v26; // eax
  int sequencePoseParameters[24]; // [esp+4h] [ebp-F4h] BYREF
  bool activePoseParameters[24]; // [esp+64h] [ebp-94h] BYREF
  CStudioHdr studioHdr; // [esp+7Ch] [ebp-7Ch] BYREF
  const mstudioposeparamdesc_t *poseParameter; // [esp+E0h] [ebp-18h]
  vgui::Slider **v31; // [esp+E4h] [ebp-14h]
  CSequencePicker *v32; // [esp+E8h] [ebp-10h]
  int nNumSequenceParameters; // [esp+ECh] [ebp-Ch]
  int nNumActiveControls; // [esp+F0h] [ebp-8h]
  int iControl; // [esp+F4h] [ebp-4h]

  v2 = this;
  v3 = !this->m_bSequenceParams;
  v32 = this;
  if ( !v3 )
  {
    v4 = vgui::MDLCache();
    v5 = (const studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, int))v4->GetStudioHdr)(
                                a1: v4,
                                a2: v2->m_hSelectedMDL,
                                a3: a2);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v5, mdlcache: nullptr);
    memset(activePoseParameters, 0, sizeof(activePoseParameters));
    p_m_nSequenceIndex = &v2->m_SequenceLayers[0].m_nSequenceIndex;
    for ( iControl = 4; iControl != 0; --iControl )
    {
      v7 = *p_m_nSequenceIndex;
      if ( *p_m_nSequenceIndex >= 0 )
      {
        v8 = studioHdr.m_pVModel != nullptr
           ? CStudioHdr::GetNumSeq_Internal(this: &studioHdr)
           : studioHdr.m_pStudioHdr->numlocalseq;
        if ( v7 < v8 )
          FindSequencePoseParameters(hdr: &studioHdr, nSequence: v7, pPoseParameters: activePoseParameters, nCount: 24);
      }
      p_m_nSequenceIndex += 2;
    }
    NumPoseParameters = CStudioHdr::GetNumPoseParameters(this: &studioHdr);
    v10 = 0;
    nNumSequenceParameters = 0;
    _V_memset(dest: sequencePoseParameters, fill: 255, count: 96);
    v11 = 0;
    if ( NumPoseParameters <= 0 )
      goto LABEL_16;
    do
    {
      if ( activePoseParameters[v11] )
        sequencePoseParameters[v10++] = v11;
      ++v11;
    }
    while ( v11 < NumPoseParameters );
    nNumSequenceParameters = v10;
    if ( v10 <= 6 )
    {
LABEL_16:
      nNumActiveControls = v10;
      v12 = v10;
    }
    else
    {
      v12 = 6;
      nNumActiveControls = 6;
    }
    iControl = 0;
    if ( v12 > 0 )
    {
      m_pPoseValueSliders = v2->m_pPoseValueSliders;
      v31 = m_pPoseValueSliders;
      while ( 1 )
      {
        v14 = *m_pPoseValueSliders;
        m_pPoseValueSliders[26] = (vgui::Slider *)sequencePoseParameters[iControl];
        v14->SetEnabled(this: v14, a2: true);
        m_pPoseValueSliders[6]->SetEnabled(this: m_pPoseValueSliders[6], a2: true);
        v15 = (vgui::ComboBox *)m_pPoseValueSliders[12];
        v15->SetEnabled(this: v15, a2: true);
        vgui::ComboBox::RemoveAll(this: v15);
        v15->SetNumberOfEditLines(this: v15, a2: v10);
        v16 = 0;
        if ( nNumSequenceParameters > 0 )
        {
          do
          {
            v17 = sequencePoseParameters[v16];
            poseParameter = CStudioHdr::pPoseParameter(this: &studioHdr, i: v17);
            v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v18 != nullptr )
              v19 = KeyValues::KeyValues(this: v18, setName: "ParameterItem", firstKey: "paramIndex", firstValue: v17);
            else
              v19 = nullptr;
            v20 = v15->AddItem_2(this: v15, a2: (const char *)poseParameter + poseParameter->sznameindex, a3: v19);
            if ( v16 == iControl )
              v15->ActivateItem(this: v15, a2: v20);
            ++v16;
          }
          while ( v16 < nNumSequenceParameters );
          m_pPoseValueSliders = v31;
        }
        ++m_pPoseValueSliders;
        ++iControl;
        v31 = m_pPoseValueSliders;
        if ( iControl >= nNumActiveControls )
          break;
        v10 = nNumSequenceParameters;
      }
      v2 = v32;
      v12 = nNumActiveControls;
    }
    if ( v12 < 6 )
    {
      v21 = &v2->m_pPoseValueSliders[v12];
      v22 = 6 - v12;
      do
      {
        v23 = *v21;
        v21[26] = (vgui::Slider *)-1;
        v23->SetEnabled(this: v23, a2: false);
        (*v21)->SetValue(this: *v21, a2: 0, a3: true);
        v21[6]->SetEnabled(this: v21[6], a2: false);
        ((void (__thiscall *)(vgui::Slider *, const char *))v21[6]->SetValue)(a1: v21[6], a2: defaultValue);
        v21[12]->SetEnabled(this: v21[12], a2: false);
        vgui::ComboBox::RemoveAll(this: (vgui::ComboBox *)v21[12]);
        ((void (__thiscall *)(vgui::Slider *, const char *))v21[12]->SetValue)(a1: v21[12], a2: defaultValue);
        ++v21;
        --v22;
      }
      while ( v22 != 0 );
      v2 = v32;
      v12 = nNumActiveControls;
    }
    v2->m_pPoseDefaultButton->SetEnabled(this: v2->m_pPoseDefaultButton, a2: v12 > 0);
    CSequencePicker::UpdatePoseControlsFromParameters(this: v2);
    CStudioHdr::Term(this: &studioHdr);
    m_pMemory = studioHdr.m_boneParent.m_Memory.m_pMemory;
    studioHdr.m_boneParent.m_Size = 0;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneParent.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneParent.m_pElements = m_pMemory;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v25 = studioHdr.m_boneFlags.m_Memory.m_pMemory;
    studioHdr.m_boneFlags.m_Size = 0;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneFlags.m_Memory.m_pMemory);
        v25 = nullptr;
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneFlags.m_pElements = v25;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v25 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v26 = studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
    studioHdr.m_pStudioHdrCache.m_Size = 0;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
        v26 = nullptr;
        studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_pStudioHdrCache.m_pElements = v26;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v26 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v26);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BEC90
// Name: private: void CSequencePicker::ResetPoseParametersToDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::ResetPoseParametersToDefault(CSequencePicker *this)
{
  IMDLCache *v2; // eax
  const studiohdr_t *v3; // eax
  CStudioHdr studioHdr; // [esp+4h] [ebp-64h] BYREF

  v2 = vgui::MDLCache();
  v3 = v2->GetStudioHdr(this: v2, a2: this->m_hSelectedMDL);
  CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v3, mdlcache: nullptr);
  Studio_CalcDefaultPoseParameters(pStudioHdr: &studioHdr, flPoseParameter: this->m_PoseParameters, nCount: 24);
  CSequencePicker::UpdatePoseControlsFromParameters(this);
  CStudioHdr::Term(this: &studioHdr);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x004BED00
// Name: private: void CSequencePicker::UpdatePoseParameterControlsForMdl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::UpdatePoseParameterControlsForMdl(CSequencePicker *this)
{
  vgui::Slider **m_pPoseValueSliders; // esi
  int i; // edi
  vgui::Slider *v4; // ecx
  IMDLCache *v5; // eax
  const studiohdr_t *v6; // eax
  int *m_pMemory; // eax
  int *v8; // eax
  const studiohdr_t **v9; // eax
  CStudioHdr pStudioHdr; // [esp+8h] [ebp-64h] BYREF

  if ( this->m_bSequenceParams )
  {
    m_pPoseValueSliders = this->m_pPoseValueSliders;
    for ( i = 6; i != 0; --i )
    {
      v4 = *m_pPoseValueSliders;
      m_pPoseValueSliders[26] = (vgui::Slider *)-1;
      v4->SetEnabled(this: v4, a2: false);
      m_pPoseValueSliders[6]->SetEnabled(this: m_pPoseValueSliders[6], a2: false);
      m_pPoseValueSliders[12]->SetEnabled(this: m_pPoseValueSliders[12], a2: false);
      ++m_pPoseValueSliders;
    }
  }
  v5 = vgui::MDLCache();
  v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
  CStudioHdr::CStudioHdr(this: &pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
  Studio_CalcDefaultPoseParameters(&pStudioHdr, flPoseParameter: this->m_PoseParameters, nCount: 24);
  CSequencePicker::UpdatePoseControlsFromParameters(this);
  CStudioHdr::Term(this: &pStudioHdr);
  m_pMemory = pStudioHdr.m_boneParent.m_Memory.m_pMemory;
  pStudioHdr.m_boneParent.m_Size = 0;
  if ( pStudioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pStudioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pStudioHdr.m_boneParent.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      pStudioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  pStudioHdr.m_boneParent.m_pElements = m_pMemory;
  if ( pStudioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      pStudioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v8 = pStudioHdr.m_boneFlags.m_Memory.m_pMemory;
  pStudioHdr.m_boneFlags.m_Size = 0;
  if ( pStudioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pStudioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pStudioHdr.m_boneFlags.m_Memory.m_pMemory);
      v8 = nullptr;
      pStudioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  pStudioHdr.m_boneFlags.m_pElements = v8;
  if ( pStudioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      pStudioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v9 = pStudioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
  pStudioHdr.m_pStudioHdrCache.m_Size = 0;
  if ( pStudioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pStudioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pStudioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
      v9 = nullptr;
      pStudioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  pStudioHdr.m_pStudioHdrCache.m_pElements = v9;
  if ( pStudioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v9 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x004BEE80
// Name: private: void CSequencePicker::SetSequenceLayer(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSequencePicker::SetSequenceLayer(
        CSequencePicker *this@<ecx>,
        int a2@<esi>,
        unsigned int nLayerIndex,
        int nSequenceIndex,
        float flWeight)
{
  CSequencePicker *v5; // edi
  IMDLCache *v6; // eax
  studiohdr_t *v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  float v10; // xmm0_4
  vgui::ComboBox *v11; // esi
  mstudioseqdesc_t *v12; // eax
  const char *v13; // ebx
  int v14; // edi
  KeyValues *ItemUserData; // eax
  const char *String; // eax
  vgui::Slider *v17; // ecx
  int v18; // esi
  studiohdr_t *pstudiohdr; // [esp+4h] [ebp-8h]
  int nItems; // [esp+18h] [ebp+Ch]

  v5 = this;
  v6 = vgui::MDLCache();
  v7 = v6->GetStudioHdr(this: v6, a2: v5->m_hSelectedMDL);
  pstudiohdr = v7;
  if ( v7 != nullptr )
  {
    v8 = v7->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v7) : v7->numlocalseq;
    v9 = nLayerIndex;
    if ( nLayerIndex <= 3 && nSequenceIndex < v8 )
    {
      v10 = 0.0;
      v5->m_SequenceLayers[nLayerIndex].m_nSequenceIndex = nSequenceIndex;
      if ( flWeight > 0.0 )
      {
        v10 = 1.0;
        if ( flWeight < 1.0 )
          v10 = flWeight;
      }
      v5->m_SequenceLayers[nLayerIndex].m_flWeight = v10;
      CMDLPanel::SetSequenceLayers(this: v5->m_pMDLPreview, pSequenceLayers: &v5->m_SequenceLayers[1], nCount: 3);
      v11 = v5->m_pLayerSequenceSelectors[nLayerIndex];
      if ( v11 != nullptr )
      {
        if ( nSequenceIndex >= 0 )
        {
          v12 = studiohdr_t::pSeqdesc(this: pstudiohdr, i: nSequenceIndex);
          v13 = (char *)v12 + v12->szlabelindex;
          v14 = 0;
          nItems = v11->GetItemCount(this: v11);
          if ( nItems > 0 )
          {
            do
            {
              ItemUserData = vgui::ComboBox::GetItemUserData(this: v11, itemID: v14);
              if ( ItemUserData != nullptr )
              {
                String = KeyValues::GetString(this: ItemUserData, keyName: "sequence", defaultValue: "invalidItem");
                if ( _V_stricmp(s1: v13, s2: String) == 0 )
                  v11->ActivateItem(this: v11, a2: v14);
              }
              ++v14;
            }
            while ( v14 < nItems );
          }
          v5 = this;
          v9 = nLayerIndex;
        }
        else
        {
          v11->SetText(this: v11, a2: defaultValue);
        }
      }
      v17 = v5->m_pLayerSequenceSliders[v9];
      v18 = a2;
      if ( v17 != nullptr )
        v17->SetValue(this: v17, a2: (int)(float)(v5->m_SequenceLayers[v9].m_flWeight * 100.0), a3: false);
      CSequencePicker::UpdateAvailablePoseParmeters(this: v5, a2: v18);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BF000
// Name: private: void CSequencePicker::UpdateLayerControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::UpdateLayerControls(CSequencePicker *this)
{
  CSequencePicker *v1; // esi
  float *p_m_flWeight; // edi
  IMDLCache *v3; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // ebx
  int v6; // eax
  int v7; // xmm0_4
  vgui::ComboBox *v8; // esi
  mstudioseqdesc_t *v9; // eax
  const char *v10; // ebx
  int v11; // edi
  KeyValues *ItemUserData; // eax
  const char *String; // eax
  float v14; // [esp+Ch] [ebp-18h]
  int i; // [esp+14h] [ebp-10h]
  int ia; // [esp+14h] [ebp-10h]
  float *v18; // [esp+18h] [ebp-Ch]
  int iLayer; // [esp+1Ch] [ebp-8h]
  vgui::Slider **m_pLayerSequenceSliders; // [esp+20h] [ebp-4h]

  v1 = this;
  p_m_flWeight = &this->m_SequenceLayers[0].m_flWeight;
  iLayer = 0;
  v18 = &this->m_SequenceLayers[0].m_flWeight;
  m_pLayerSequenceSliders = this->m_pLayerSequenceSliders;
  do
  {
    v14 = *p_m_flWeight;
    i = *((_DWORD *)p_m_flWeight - 1);
    v3 = vgui::MDLCache();
    v4 = v3->GetStudioHdr(this: v3, a2: v1->m_hSelectedMDL);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
      if ( (unsigned int)iLayer <= 3 && i < v6 )
      {
        v7 = 0;
        *((_DWORD *)p_m_flWeight - 1) = i;
        if ( v14 > 0.0 )
        {
          v7 = 1065353216;
          if ( v14 < 1.0 )
            v7 = LODWORD(v14);
        }
        *(_DWORD *)p_m_flWeight = v7;
        CMDLPanel::SetSequenceLayers(this: v1->m_pMDLPreview, pSequenceLayers: &v1->m_SequenceLayers[1], nCount: 3);
        v8 = (vgui::ComboBox *)*(m_pLayerSequenceSliders - 4);
        if ( v8 != nullptr )
        {
          if ( i >= 0 )
          {
            v9 = studiohdr_t::pSeqdesc(this: v5, i);
            v10 = (char *)v9 + v9->szlabelindex;
            v11 = 0;
            ia = v8->GetItemCount(this: v8);
            if ( ia > 0 )
            {
              do
              {
                ItemUserData = vgui::ComboBox::GetItemUserData(this: v8, itemID: v11);
                if ( ItemUserData != nullptr )
                {
                  String = KeyValues::GetString(this: ItemUserData, keyName: "sequence", defaultValue: "invalidItem");
                  if ( _V_stricmp(s1: v10, s2: String) == 0 )
                    v8->ActivateItem(this: v8, a2: v11);
                }
                ++v11;
              }
              while ( v11 < ia );
            }
            p_m_flWeight = v18;
          }
          else
          {
            v8->SetText(this: v8, a2: defaultValue);
          }
        }
        if ( *m_pLayerSequenceSliders != nullptr )
          (*m_pLayerSequenceSliders)->SetValue(
            this: *m_pLayerSequenceSliders,
            a2: (int)(float)(*p_m_flWeight * 100.0),
            a3: false);
        CSequencePicker::UpdateAvailablePoseParmeters(this, a2: (int)v8);
        v1 = this;
      }
    }
    ++m_pLayerSequenceSliders;
    p_m_flWeight += 2;
    ++iLayer;
    v18 = p_m_flWeight;
  }
  while ( iLayer < 4 );
}

//------------------------------------------------------------------------------
// Address: 0x004BF1B0
// Name: private: void CSequencePicker::ResetLayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::ResetLayers(CSequencePicker *this)
{
  MDLSquenceLayer_t *m_SequenceLayers; // ebx
  signed int i; // edi

  m_SequenceLayers = this->m_SequenceLayers;
  this->m_SequenceLayers[0].m_flWeight = 1.0;
  this->m_SequenceLayers[0].m_nSequenceIndex = 0;
  this->m_SequenceLayers[1].m_nSequenceIndex = -1;
  this->m_SequenceLayers[1].m_flWeight = 0.0;
  this->m_SequenceLayers[2].m_nSequenceIndex = -1;
  this->m_SequenceLayers[2].m_flWeight = 0.0;
  this->m_SequenceLayers[3].m_nSequenceIndex = -1;
  this->m_SequenceLayers[3].m_flWeight = 0.0;
  for ( i = 0; i < 4; ++i )
  {
    CSequencePicker::SetSequenceLayer(
      this,
      a2: (int)this,
      nLayerIndex: i,
      nSequenceIndex: m_SequenceLayers->m_nSequenceIndex,
      flWeight: m_SequenceLayers->m_flWeight);
    ++m_SequenceLayers;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BF230
// Name: private: virtual void CSequencePicker::OnSliderMoved(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnSliderMoved(CSequencePicker *this, KeyValues *pData)
{
  vgui::Slider *Ptr; // eax
  int v4; // esi
  vgui::Slider **m_pLayerSequenceSliders; // ecx
  int v6; // esi
  vgui::Slider **i; // ecx
  int v8; // eax
  int v9; // eax

  Ptr = (vgui::Slider *)KeyValues::GetPtr(this: pData, keyName: "panel", defaultValue: nullptr);
  v4 = 0;
  m_pLayerSequenceSliders = this->m_pLayerSequenceSliders;
  do
  {
    if ( Ptr == *m_pLayerSequenceSliders )
    {
      v8 = this->m_pLayerSequenceSliders[v4]->GetValue(this: this->m_pLayerSequenceSliders[v4]);
      CSequencePicker::SetSequenceLayer(
        this,
        a2: v4,
        nLayerIndex: v4,
        nSequenceIndex: this->m_SequenceLayers[v4].m_nSequenceIndex,
        flWeight: (float)v8 * 0.0099999998);
      return;
    }
    ++v4;
    ++m_pLayerSequenceSliders;
  }
  while ( v4 < 4 );
  v6 = 0;
  for ( i = this->m_pPoseValueSliders; Ptr != *i; ++i )
  {
    if ( ++v6 >= 6 )
      return;
  }
  v9 = this->m_pPoseValueSliders[v6]->GetValue(this: this->m_pPoseValueSliders[v6]);
  CSequencePicker::SetPoseParameterValue(
    this,
    flPoseParameterValue: (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)v9 - 50.0) * 0.02) & _mask__AbsFloat_)
                  * (float)((float)((float)v9 - 50.0) * 0.02))
          + 1.0)
  * 0.5,
    nParameterIndex: this->m_PoseControlMap[v6]);
}

//------------------------------------------------------------------------------
// Address: 0x004BF320
// Name: public: virtual void CSequencePicker::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnCommand(CSequencePicker *this, const char *pCommand)
{
  if ( _V_strcmp(s1: "ResetToDefaults", s2: pCommand) == 0 )
    CSequencePicker::ResetPoseParametersToDefault(this);
}

//------------------------------------------------------------------------------
// Address: 0x004BF350
// Name: private: void CSequencePicker::UpdateActiveSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::UpdateActiveSequence(CSequencePicker *this, const char *pSequenceName)
{
  int Sequence; // eax
  int v4; // edi

  Sequence = CSequencePicker::FindSequence(this, pSequenceName);
  v4 = Sequence;
  if ( Sequence >= 0 )
  {
    if ( this->m_bSequenceParams )
    {
      CSequencePicker::SetSequenceLayer(this, a2: (int)this, nLayerIndex: 0, nSequenceIndex: Sequence, flWeight: 1.0);
      CSequencePicker::UpdateAvailablePoseParmeters(this, a2: (int)this);
    }
    CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BF3A0
// Name: private: virtual void CSequencePicker::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnPageChanged(CSequencePicker *this)
{
  const char *SelectedSequenceName; // eax
  const char *v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  const char *v6; // eax
  const char *v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // eax

  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    SelectedSequenceName = CSequencePicker::GetSelectedSequenceName(this);
    v3 = SelectedSequenceName;
    if ( SelectedSequenceName == nullptr )
      return;
    CSequencePicker::UpdateActiveSequence(this, pSequenceName: SelectedSequenceName);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "SequencePreviewChanged", firstKey: "sequence", firstValue: v3);
      this->PostActionSignal(this, a2: v5);
      return;
    }
LABEL_11:
    this->PostActionSignal(this, a2: nullptr);
    return;
  }
  if ( this->m_pActivitiesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    v6 = CSequencePicker::GetSelectedSequenceName(this);
    v7 = v6;
    if ( v6 != nullptr )
    {
      CSequencePicker::PlayActivity(this, pActivityName: v6);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v9 = KeyValues::KeyValues(this: v8, setName: "SequencePreviewChanged", firstKey: "activity", firstValue: v7);
        this->PostActionSignal(this, a2: v9);
        return;
      }
      goto LABEL_11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BF490
// Name: private: virtual void CSequencePicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnItemSelected(CSequencePicker *this, KeyValues *kv)
{
  vgui::ListPanel *Ptr; // eax
  vgui::ListPanel *m_pSequencesList; // ecx
  const char *SelectedSequenceName; // eax
  const char *v6; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  vgui::ListPanel *m_pActivitiesList; // ecx
  const char *v10; // eax
  const char *v11; // edi
  KeyValues *v12; // eax
  KeyValues *v13; // eax

  Ptr = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pSequencesList = this->m_pSequencesList;
  if ( m_pSequencesList != nullptr && Ptr == m_pSequencesList )
  {
    SelectedSequenceName = CSequencePicker::GetSelectedSequenceName(this);
    v6 = SelectedSequenceName;
    if ( SelectedSequenceName == nullptr )
      return;
    CSequencePicker::UpdateActiveSequence(this, pSequenceName: SelectedSequenceName);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(this: v7, setName: "SequencePreviewChanged", firstKey: "sequence", firstValue: v6);
      this->PostActionSignal(this, a2: v8);
      return;
    }
LABEL_11:
    this->PostActionSignal(this, a2: nullptr);
    return;
  }
  m_pActivitiesList = this->m_pActivitiesList;
  if ( m_pActivitiesList != nullptr && Ptr == m_pActivitiesList )
  {
    v10 = CSequencePicker::GetSelectedSequenceName(this);
    v11 = v10;
    if ( v10 != nullptr )
    {
      CSequencePicker::PlayActivity(this, pActivityName: v10);
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
      {
        v13 = KeyValues::KeyValues(this: v12, setName: "SequencePreviewChanged", firstKey: "activity", firstValue: v11);
        this->PostActionSignal(this, a2: v13);
        return;
      }
      goto LABEL_11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BF570
// Name: private: virtual void CSequencePicker::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnTextChanged(CSequencePicker *this, KeyValues *pData)
{
  vgui::ComboBox *Ptr; // eax
  signed int v4; // edi
  vgui::ComboBox **m_pLayerSequenceSelectors; // ecx
  int v6; // edi
  vgui::ComboBox **i; // ecx
  const char *String; // eax
  int Sequence; // eax
  int v10; // edi
  KeyValues *ActiveItemUserData; // eax
  unsigned int Int; // eax

  Ptr = (vgui::ComboBox *)KeyValues::GetPtr(this: pData, keyName: "panel", defaultValue: nullptr);
  v4 = 0;
  m_pLayerSequenceSelectors = this->m_pLayerSequenceSelectors;
  do
  {
    if ( Ptr == *m_pLayerSequenceSelectors )
    {
      String = KeyValues::GetString(this: pData, keyName: "text", defaultValue: defaultValue);
      Sequence = CSequencePicker::FindSequence(this, pSequenceName: String);
      if ( v4 != 0 )
      {
        CSequencePicker::SetSequenceLayer(
          this,
          a2: (int)this,
          nLayerIndex: v4,
          nSequenceIndex: Sequence,
          flWeight: this->m_SequenceLayers[v4].m_flWeight);
      }
      else
      {
        v10 = Sequence;
        if ( Sequence >= 0 )
        {
          if ( this->m_bSequenceParams )
          {
            CSequencePicker::SetSequenceLayer(
              this,
              a2: (int)this,
              nLayerIndex: 0,
              nSequenceIndex: Sequence,
              flWeight: 1.0);
            CSequencePicker::UpdateAvailablePoseParmeters(this, a2: (int)this);
          }
          CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: v10);
        }
      }
      return;
    }
    ++v4;
    ++m_pLayerSequenceSelectors;
  }
  while ( v4 < 4 );
  v6 = 0;
  for ( i = this->m_pPoseParameterName; Ptr != *i; ++i )
  {
    if ( ++v6 >= 6 )
      return;
  }
  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pPoseParameterName[v6]);
  Int = KeyValues::GetInt(this: ActiveItemUserData, keyName: "paramIndex", defaultValue: -1);
  if ( Int <= 0x17 )
  {
    this->m_PoseControlMap[v6] = Int;
    CSequencePicker::SetPoseParameterValue(
      this,
      flPoseParameterValue: this->m_PoseParameters[Int],
      nParameterIndex: Int);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BF690
// Name: private: void CSequencePicker::RefreshActivitiesAndSequencesList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::RefreshActivitiesAndSequencesList(CSequencePicker *this)
{
  CSequencePicker *v1; // ebx
  bool v2; // zf
  vgui::ComboBox **m_pLayerSequenceSelectors; // esi
  int k; // edi
  IMDLCache *v5; // eax
  studiohdr_t *v6; // eax
  studiohdr_t *v7; // esi
  int NumSeq_Internal; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v9; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  studiohdr_t *v14; // esi
  int v15; // ebx
  int v16; // eax
  mstudioseqdesc_t *v17; // eax
  const char *v18; // edi
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  int v21; // ebx
  KeyValues *v22; // eax
  KeyValues *v23; // esi
  IMDLCache *v24; // eax
  const char *v25; // eax
  int v26; // eax
  mstudioseqdesc_t *v27; // eax
  int v28; // edi
  const char *v29; // esi
  KeyValues *v30; // eax
  KeyValues *v31; // eax
  int v32; // ebx
  KeyValues *v33; // eax
  KeyValues *v34; // esi
  IMDLCache *v35; // eax
  const char *v36; // eax
  int numlocalseq; // ebx
  int v38; // edi
  int v39; // eax
  mstudioseqdesc_t *v40; // ebx
  int m_Size; // esi
  mstudioseqdesc_t **v42; // esi
  vgui::ComboBox **v43; // esi
  int m; // edi
  const char *v45; // esi
  vgui::ComboBox **v46; // edi
  int n; // ebx
  KeyValues *v48; // eax
  KeyValues *v49; // eax
  CUtlDict<int,unsigned short> activityNames; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<mstudioseqdesc_t *,CUtlMemory<mstudioseqdesc_t *,int> > sequenceList; // [esp+28h] [ebp-2Ch] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+3Ch] [ebp-18h] BYREF
  vgui::ComboBox **v53; // [esp+44h] [ebp-10h]
  int i; // [esp+48h] [ebp-Ch]
  int nNumSequences; // [esp+4Ch] [ebp-8h]
  int j; // [esp+50h] [ebp-4h] BYREF

  v1 = this;
  v2 = this->m_pActivitiesList == nullptr;
  nNumSequences = (int)this;
  if ( !v2 )
    this->m_pActivitiesList->RemoveAll(this: this->m_pActivitiesList);
  if ( v1->m_pSequencesList != nullptr )
    v1->m_pSequencesList->RemoveAll(this: v1->m_pSequencesList);
  m_pLayerSequenceSelectors = v1->m_pLayerSequenceSelectors;
  v53 = v1->m_pLayerSequenceSelectors;
  for ( k = 4; k != 0; --k )
  {
    if ( *m_pLayerSequenceSelectors != nullptr )
      vgui::ComboBox::RemoveAll(this: *m_pLayerSequenceSelectors);
    ++m_pLayerSequenceSelectors;
  }
  CMDLPanel::SetSequence(this: v1->m_pMDLPreview, nSequence: 0);
  if ( v1->m_hSelectedMDL != 0xFFFF )
  {
    v5 = vgui::MDLCache();
    v6 = v5->GetStudioHdr(this: v5, a2: v1->m_hSelectedMDL);
    v7 = v6;
    i = (int)v6;
    if ( v6->numincludemodels != 0 )
      NumSeq_Internal = studiohdr_t::GetNumSeq_Internal(this: v6);
    else
      NumSeq_Internal = v6->numlocalseq;
    v9 = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = NumSeq_Internal;
    activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    if ( NumSeq_Internal != 0 )
    {
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 16 * NumSeq_Internal);
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v9;
    }
    v10 = 0;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_FirstFree = -1;
    activityNames.m_Elements.m_Tree.m_pElements = v9;
    activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    for ( j = 0; ; v10 = j )
    {
      v11 = v7->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v7) : v7->numlocalseq;
      if ( v10 >= v11 )
        break;
      if ( v7->numincludemodels != 0 )
      {
        v13 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v10);
      }
      else
      {
        v12 = v10;
        if ( v10 < 0 || v10 >= v7->numlocalseq )
          v12 = 0;
        v13 = (mstudioseqdesc_t *)((char *)v7 + 212 * v12 + v7->localseqindex);
      }
      if ( (v13->flags & 0x400) == 0 )
      {
        v14 = (studiohdr_t *)i;
        v15 = j;
        if ( *(_DWORD *)(i + 336) != 0 )
        {
          v17 = studiohdr_t::pSeqdesc_Internal(this: (studiohdr_t *)i, i: j);
        }
        else
        {
          v16 = j;
          if ( j < 0 || j >= *(_DWORD *)(i + 188) )
            v16 = 0;
          v17 = (mstudioseqdesc_t *)(i + *(_DWORD *)(i + 192) + 212 * v16);
        }
        v18 = (char *)v17 + v17->szactivitynameindex;
        if ( *(_DWORD *)(nNumSequences + 416) != 0 && v18 != nullptr && *v18 != 0 )
        {
          search.key = (char *)v17 + v17->szactivitynameindex;
          if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                 this: &activityNames.m_Elements.m_Tree,
                 &search) == 0xFFFF )
          {
            v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v19 != nullptr )
              v20 = KeyValues::KeyValues(this: v19, setName: "node", firstKey: "activity", firstValue: v18);
            else
              v20 = nullptr;
            v21 = (*(int (__thiscall **)(_DWORD, KeyValues *, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(nNumSequences + 416)
                                                                                     + 916))(
                    a1: *(_DWORD *)(nNumSequences + 416),
                    a2: v20,
                    a3: 0,
                    a4: 0,
                    a5: 0);
            v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v22 != nullptr )
              v23 = KeyValues::KeyValues(this: v22, setName: "drag", firstKey: "text", firstValue: v18);
            else
              v23 = nullptr;
            KeyValues::SetString(this: v23, keyName: "texttype", value: "activityName");
            v24 = vgui::MDLCache();
            v25 = v24->GetModelName(this: v24, a2: *(_WORD *)(nNumSequences + 686));
            KeyValues::SetString(this: v23, keyName: "mdl", value: v25);
            vgui::ListPanel::SetItemDragData(this: *(vgui::ListPanel **)(nNumSequences + 416), itemID: v21, data: v23);
            CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v18, element: &j);
            v14 = (studiohdr_t *)i;
            v15 = j;
          }
        }
        if ( v14->numincludemodels != 0 )
        {
          v27 = studiohdr_t::pSeqdesc_Internal(this: v14, i: v15);
        }
        else
        {
          v26 = v15;
          if ( v15 < 0 || v15 >= v14->numlocalseq )
            v26 = 0;
          v27 = (mstudioseqdesc_t *)((char *)v14 + 212 * v26 + v14->localseqindex);
        }
        v28 = nNumSequences;
        v29 = (char *)v27 + v27->szlabelindex;
        if ( *(_DWORD *)(nNumSequences + 412) != 0 && v29 != nullptr && *v29 != 0 )
        {
          v30 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v30 != nullptr )
            v31 = KeyValues::KeyValues(this: v30, setName: "node", firstKey: "sequence", firstValue: v29);
          else
            v31 = nullptr;
          v32 = (*(int (__thiscall **)(_DWORD, KeyValues *, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(v28 + 412) + 916))(
                  a1: *(_DWORD *)(v28 + 412),
                  a2: v31,
                  a3: 0,
                  a4: 0,
                  a5: 0);
          v33 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v33 != nullptr )
            v34 = KeyValues::KeyValues(this: v33, setName: "drag", firstKey: "text", firstValue: v29);
          else
            v34 = nullptr;
          KeyValues::SetString(this: v34, keyName: "texttype", value: "sequenceName");
          v35 = vgui::MDLCache();
          v36 = v35->GetModelName(this: v35, a2: *(_WORD *)(v28 + 686));
          KeyValues::SetString(this: v34, keyName: "mdl", value: v36);
          vgui::ListPanel::SetItemDragData(this: *(vgui::ListPanel **)(v28 + 412), itemID: v32, data: v34);
        }
      }
      ++j;
      v1 = (CSequencePicker *)nNumSequences;
      v7 = (studiohdr_t *)i;
    }
    if ( v1->m_pSequencesList != nullptr )
      v1->m_pSequencesList->SortList(this: v1->m_pSequencesList);
    if ( v1->m_pActivitiesList != nullptr )
      v1->m_pActivitiesList->SortList(this: v1->m_pActivitiesList);
    if ( v1->m_bSequenceParams )
    {
      if ( v7->numincludemodels != 0 )
      {
        nNumSequences = studiohdr_t::GetNumSeq_Internal(this: v7);
        numlocalseq = nNumSequences;
      }
      else
      {
        numlocalseq = v7->numlocalseq;
        nNumSequences = numlocalseq;
      }
      sequenceList.m_Memory.m_pMemory = nullptr;
      sequenceList.m_Memory.m_nAllocationCount = numlocalseq;
      sequenceList.m_Memory.m_nGrowSize = 0;
      if ( numlocalseq != 0 )
        sequenceList.m_Memory.m_pMemory = (mstudioseqdesc_t **)_g_pMemAlloc->Alloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: 4 * numlocalseq);
      v38 = 0;
      sequenceList.m_Size = 0;
      sequenceList.m_pElements = sequenceList.m_Memory.m_pMemory;
      if ( numlocalseq > 0 )
      {
        while ( 1 )
        {
          if ( v7->numincludemodels != 0 )
          {
            v40 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v38);
          }
          else
          {
            v39 = v38;
            if ( v38 < 0 || v38 >= v7->numlocalseq )
              v39 = 0;
            v40 = (mstudioseqdesc_t *)((char *)v7 + 212 * v39 + v7->localseqindex);
          }
          if ( (v40->flags & 0x400) == 0 )
          {
            m_Size = sequenceList.m_Size;
            if ( sequenceList.m_Size + 1 > sequenceList.m_Memory.m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&sequenceList,
                num: sequenceList.m_Size - sequenceList.m_Memory.m_nAllocationCount + 1);
            ++sequenceList.m_Size;
            sequenceList.m_pElements = sequenceList.m_Memory.m_pMemory;
            if ( sequenceList.m_Size - m_Size - 1 > 0 )
              _V_memmove(
                dest: &sequenceList.m_Memory.m_pMemory[m_Size + 1],
                src: &sequenceList.m_Memory.m_pMemory[m_Size],
                count: 4 * (sequenceList.m_Size - m_Size - 1));
            v42 = &sequenceList.m_Memory.m_pMemory[m_Size];
            if ( v42 != nullptr )
              *v42 = v40;
          }
          if ( ++v38 >= nNumSequences )
            break;
          v7 = (studiohdr_t *)i;
        }
      }
      CUtlVector<mstudioseqdesc_t *,CUtlMemory<mstudioseqdesc_t *,int>>::Sort(
        this: &sequenceList,
        pfnCompare: (int (__cdecl *)(const void *, const void *))CompareSequenceDesc);
      v43 = v53;
      for ( m = 4; m != 0; --m )
      {
        if ( *v43 != nullptr )
          vgui::ComboBox::RemoveAll(this: *v43);
        ++v43;
      }
      for ( i = 0; i < sequenceList.m_Size; ++i )
      {
        v45 = (char *)sequenceList.m_Memory.m_pMemory[i] + sequenceList.m_Memory.m_pMemory[i]->szlabelindex;
        if ( v45 != nullptr )
        {
          v46 = v53;
          for ( n = 4; n != 0; --n )
          {
            if ( *v46 != nullptr )
            {
              v48 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v48 != nullptr )
                v49 = KeyValues::KeyValues(this: v48, setName: "sequenceItem", firstKey: "sequence", firstValue: v45);
              else
                v49 = nullptr;
              (*v46)->AddItem_2(this: *v46, a2: v45, a3: v49);
            }
            ++v46;
          }
        }
      }
      if ( sequenceList.m_Memory.m_nGrowSize >= 0 && sequenceList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sequenceList.m_Memory.m_pMemory);
    }
    CUtlDict<int,unsigned short>::RemoveAll(this: &activityNames);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &activityNames.m_Elements.m_Tree);
    if ( activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && activityNames.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: activityNames.m_Elements.m_Tree.m_Elements.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BFC70
// Name: public: void CSequencePicker::SetMDL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::SetMDL(CSequencePicker *this, const char *pMDLName)
{
  IMDLCache *v3; // eax
  unsigned __int16 v4; // ax
  IMDLCache *v5; // eax

  if ( pMDLName != nullptr )
  {
    v3 = vgui::MDLCache();
    v4 = v3->FindMDL(this: v3, a2: pMDLName);
  }
  else
  {
    v4 = -1;
  }
  this->m_hSelectedMDL = v4;
  v5 = vgui::MDLCache();
  if ( v5->IsErrorModel(this: v5, a2: this->m_hSelectedMDL) )
    this->m_hSelectedMDL = -1;
  this->m_pMDLPreview->SetMDL_2(this: this->m_pMDLPreview, a2: this->m_hSelectedMDL, a3: nullptr);
  CMDLPanel::LookAtMDL(this: this->m_pMDLPreview);
  CSequencePicker::ResetLayers(this);
  CSequencePicker::RefreshActivitiesAndSequencesList(this);
  CSequencePicker::UpdateLayerControls(this);
  CSequencePicker::UpdatePoseParameterControlsForMdl(this);
}

//------------------------------------------------------------------------------
// Address: 0x004BFD10
// Name: public: void CSequencePickerFrame::DoModal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePickerFrame::DoModal(CSequencePickerFrame *this, const char *pMDLName)
{
  CSequencePicker::SetMDL(this: this->m_pPicker, pMDLName);
  vgui::Frame::DoModal(this);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104C9D20
// Name: public: static char const __near * CSequencePicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSequencePicker::GetPanelClassName()
{
  return "CSequencePicker";
}

//------------------------------------------------------------------------------
// Address: 0x104C9D30
// Name: public: static char const __near * CSequencePickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSequencePickerFrame::GetPanelClassName()
{
  return "CSequencePickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x104C9D40
// Name: SequenceSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SequenceSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "sequence", defaultValue: &var);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "sequence", defaultValue: &var);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104C9D80
// Name: ActivitySortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ActivitySortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "activity", defaultValue: &var);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "activity", defaultValue: &var);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104C9DC0
// Name: public: virtual void CSequencePicker::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::PerformLayout(CSequencePicker *this)
{
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pPreviewSplitter, x: 0, y: 0, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x104C9E00
// Name: int CompareSequenceDesc(struct mstudioseqdesc_t __near * const __near *,struct mstudioseqdesc_t __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompareSequenceDesc(mstudioseqdesc_t *const *pDescA, mstudioseqdesc_t *const *pDescB)
{
  int v2; // edx
  const char *v3; // eax

  if ( pDescA != nullptr
    && pDescB != nullptr
    && *pDescA != nullptr
    && (v2 = (int)*pDescB, *pDescB != nullptr)
    && (v3 = (char *)*pDescA + (*pDescA)->szlabelindex) != nullptr
    && v2 + *(_DWORD *)(v2 + 4) != 0 )
  {
    return _V_stricmp(s1: v3, s2: (const char *)(v2 + *(_DWORD *)(v2 + 4)));
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C9E40
// Name: public: enum CSequencePicker::PickType_t CSequencePicker::GetSelectedSequenceType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSequencePicker::GetSelectedSequenceType(CSequencePicker *this)
{
  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    return 1;
  }
  if ( this->m_pActivitiesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    return 2;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104C9EA0
// Name: private: void CSequencePicker::PlayActivity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::PlayActivity(CSequencePicker *this, const char *pActivityName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szactivitynameindex, s2: pActivityName) == 0 )
    {
      CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: i);
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C9F40
// Name: private: int CSequencePicker::FindSequence(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSequencePicker::FindSequence(CSequencePicker *this, const char *pSequenceName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szlabelindex, s2: pSequenceName) == 0 )
      return i;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104C9FE0
// Name: private: virtual void CSequencePickerFrame::OnSequencePreviewChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePickerFrame::OnSequencePreviewChanged(CSequencePickerFrame *this, KeyValues *pKeyValues)
{
  char *String; // edi
  int v4; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "sequence", defaultValue: nullptr);
  v4 = (int)KeyValues::GetString(this: pKeyValues, keyName: "activity", defaultValue: nullptr);
  if ( String != nullptr || v4 != 0 )
    v4 = 1;
  else
    LOBYTE(v4) = 0;
  this->m_pOpenButton->SetEnabled(this: this->m_pOpenButton, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104CA050
// Name: public: virtual struct vgui::PanelMessageMap __near * CSequencePicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSequencePicker::GetMessageMap(CSequencePicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSequencePicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSequencePicker::GetMessageMap'::`2'::s_pMap;
  `CSequencePicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
  `CSequencePicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CA080
// Name: public: virtual struct PanelAnimationMap __near * CSequencePicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSequencePicker::GetAnimMap(CSequencePicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CSequencePicker");
}

//------------------------------------------------------------------------------
// Address: 0x104CA090
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSequencePicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSequencePicker::GetKBMap(CSequencePicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSequencePicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSequencePicker::GetKBMap'::`2'::s_pMap;
  `CSequencePicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSequencePicker");
  `CSequencePicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CA130
// Name: public: static void CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CA1C0
// Name: public: static void CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextKillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CA250
// Name: public: static void CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextNewLine";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CA2E0
// Name: public: static void CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CA370
// Name: public: static void CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CA400
// Name: public: static void CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CA490
// Name: public: static void CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar'::`2'::bAdded )
  {
    `CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePickerFrame");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SequencePreviewChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CA520
// Name: public: CSequencePicker::CSequencePicker(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSequencePicker *__thiscall CSequencePicker::CSequencePicker(CSequencePicker *this, vgui::Panel *pParent, char nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // ebx
  CMDLPanel *v10; // eax
  CMDLPanel *v11; // eax
  vgui::PropertySheet *v12; // eax
  vgui::PropertySheet *v13; // eax
  vgui::PropertyPage *v14; // eax
  vgui::PropertyPage *v15; // eax
  vgui::PropertySheet *m_pViewsSheet; // ecx
  int v17; // ebx
  vgui::Slider **m_pLayerSequenceSliders; // edi
  vgui::ComboBox *v19; // eax
  vgui::ComboBox *v20; // eax
  int v21; // eax
  vgui::Slider *v22; // eax
  vgui::Slider *v23; // eax
  int v24; // ebx
  vgui::TextEntry **m_pPoseValueEntries; // edi
  vgui::Slider *v26; // eax
  vgui::Slider *v27; // eax
  vgui::TextEntry *v28; // eax
  vgui::TextEntry *v29; // eax
  vgui::ComboBox *v30; // eax
  vgui::ComboBox *v31; // eax
  vgui::Button *v32; // eax
  vgui::Button *v33; // eax
  vgui::CheckButton *v34; // eax
  vgui::CheckButton *v35; // eax
  vgui::ListPanel *v36; // eax
  vgui::ListPanel *v37; // eax
  vgui::PropertyPage *v38; // eax
  vgui::PropertyPage *v39; // eax
  vgui::PropertySheet *v40; // ecx
  vgui::ListPanel *v41; // eax
  vgui::ListPanel *v42; // eax
  char controlName[64]; // [esp+Ch] [ebp-40h] BYREF
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF
  vgui::Panel *i; // [esp+54h] [ebp+8h]
  int ia; // [esp+54h] [ebp+8h]
  __int16 ib; // [esp+54h] [ebp+8h]

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "SequencePicker");
  this->__vftable = (CSequencePicker_vtbl *)&CSequencePicker::`vftable';
  if ( `CSequencePicker::ChainToMap'::`2'::chained == 0 )
  {
    `CSequencePicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    v4->pfnClassName = CSequencePicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CSequencePicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSequencePicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSequencePicker");
    v5->pfnClassName = CSequencePicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CSequencePicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSequencePicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSequencePicker");
    v6->pfnClassName = CSequencePicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_Filter);
  this->m_bSequenceParams = (nFlags & 0x11) == 17;
  this->m_hSelectedMDL = -1;
  this->m_pRootMotionCheckBox = nullptr;
  this->m_pPoseDefaultButton = nullptr;
  _V_memset(dest: (unsigned __int8 *)this->m_pLayerSequenceSelectors, fill: 0, count: 0x10u);
  _V_memset(dest: (unsigned __int8 *)this->m_pLayerSequenceSliders, fill: 0, count: 0x10u);
  _V_memset(dest: (unsigned __int8 *)this->m_pPoseValueSliders, fill: 0, count: 0x18u);
  _V_memset(dest: (unsigned __int8 *)this->m_pPoseValueEntries, fill: 0, count: 0x18u);
  _V_memset(dest: (unsigned __int8 *)this->m_pPoseParameterName, fill: 0, count: 0x18u);
  _V_memset(dest: (unsigned __int8 *)this->m_SequenceLayers, fill: 0, count: 0x20u);
  _V_memset(dest: (unsigned __int8 *)this->m_PoseControlMap, fill: 0xFFu, count: 0x18u);
  _V_memset(dest: (unsigned __int8 *)this->m_PoseParameters, fill: 0, count: 0x60u);
  v7 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "PreviewSplitter",
           mode: SPLITTER_MODE_HORIZONTAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pPreviewSplitter = v8;
  Child = vgui::Panel::GetChild(this: v8, index: 0);
  i = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v10 = (CMDLPanel *)operator new(nSize: 0xBE4u);
  if ( v10 != nullptr )
    v11 = CMDLPanel::CMDLPanel(this: v10, pParent: Child, pName: "MDLPreview");
  else
    v11 = nullptr;
  this->m_pMDLPreview = v11;
  vgui::Panel::SetSkipChildDuringPainting(this, child: v11);
  v12 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v12 != nullptr )
    v13 = vgui::PropertySheet::PropertySheet(
            this: v12,
            parent: i,
            panelName: (vgui::Panel *)"ViewsSheet",
            draggableTabs: false);
  else
    v13 = nullptr;
  this->m_pViewsSheet = v13;
  v13->AddActionSignalTarget_2(this: v13, a2: this);
  this->m_pSequencesPage = nullptr;
  this->m_pSequencesList = nullptr;
  if ( (nFlags & 1) != 0 )
  {
    v14 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v14 != nullptr )
      v15 = vgui::PropertyPage::PropertyPage(this: v14, parent: this->m_pViewsSheet, panelName: "SequencesPage");
    else
      v15 = nullptr;
    m_pViewsSheet = this->m_pViewsSheet;
    this->m_pSequencesPage = v15;
    m_pViewsSheet->AddPage(this: m_pViewsSheet, a2: v15, a3: "Sequences", a4: nullptr, a5: false, a6: -1);
    if ( this->m_bSequenceParams )
    {
      ia = 0;
      v17 = 10;
      m_pLayerSequenceSliders = this->m_pLayerSequenceSliders;
      do
      {
        V_snprintf(pDest: controlName, maxLen: 0x40u, pFormat: "LayerSequence%i", ia);
        v19 = (vgui::ComboBox *)operator new(nSize: 0x458u);
        if ( v19 != nullptr )
          v20 = vgui::ComboBox::ComboBox(
                  this: v19,
                  parent: this->m_pSequencesPage,
                  panelName: (vgui::Panel *)controlName,
                  numLines: 32,
                  allowEdit: false);
        else
          v20 = nullptr;
        *(m_pLayerSequenceSliders - 4) = (vgui::Slider *)v20;
        vgui::Panel::SetAutoResize(
          this: v20,
          pinCorner: PIN_TOPLEFT,
          resizeDir: AUTORESIZE_NO,
          nPinOffsetX: 10,
          nPinOffsetY: v17,
          nUnpinnedCornerOffsetX: 0,
          nUnpinnedCornerOffsetY: 0);
        vgui::Panel::SetWide(this: *(m_pLayerSequenceSliders - 4), wide: 180);
        (*(m_pLayerSequenceSliders - 4))->AddActionSignalTarget_2(this: *(m_pLayerSequenceSliders - 4), a2: this);
        v21 = ia;
        if ( ia > 0 )
        {
          v17 += 24;
          V_snprintf(pDest: controlName, maxLen: 0x40u, pFormat: "LayerSequenceWeight%i", ia);
          v22 = (vgui::Slider *)operator new(nSize: 0x1ACu);
          if ( v22 != nullptr )
            v23 = vgui::Slider::Slider(this: v22, parent: this->m_pSequencesPage, panelName: controlName);
          else
            v23 = nullptr;
          *m_pLayerSequenceSliders = v23;
          vgui::Panel::SetAutoResize(
            this: v23,
            pinCorner: PIN_TOPLEFT,
            resizeDir: AUTORESIZE_NO,
            nPinOffsetX: 10,
            nPinOffsetY: v17,
            nUnpinnedCornerOffsetX: 0,
            nUnpinnedCornerOffsetY: 0);
          vgui::Panel::SetWide(this: *m_pLayerSequenceSliders, wide: 180);
          (*m_pLayerSequenceSliders)->SetRange(this: *m_pLayerSequenceSliders, a2: 0, a3: 100);
          (*m_pLayerSequenceSliders)->AddActionSignalTarget_2(this: *m_pLayerSequenceSliders, a2: this);
          v21 = ia;
        }
        v17 += 40;
        ++m_pLayerSequenceSliders;
        ia = v21 + 1;
      }
      while ( v21 + 1 < 4 );
      ib = 10;
      v24 = 0;
      m_pPoseValueEntries = this->m_pPoseValueEntries;
      do
      {
        V_snprintf(pDest: controlName, maxLen: 0x40u, pFormat: "PoseValueSlider%i", v24);
        v26 = (vgui::Slider *)operator new(nSize: 0x1ACu);
        if ( v26 != nullptr )
          v27 = vgui::Slider::Slider(this: v26, parent: this->m_pSequencesPage, panelName: controlName);
        else
          v27 = nullptr;
        *(m_pPoseValueEntries - 6) = (vgui::TextEntry *)v27;
        vgui::Panel::SetAutoResize(
          this: v27,
          pinCorner: PIN_TOPLEFT,
          resizeDir: AUTORESIZE_NO,
          nPinOffsetX: 210,
          nPinOffsetY: ib,
          nUnpinnedCornerOffsetX: 0,
          nUnpinnedCornerOffsetY: 0);
        vgui::Panel::SetWide(this: *(m_pPoseValueEntries - 6), wide: 120);
        (*(m_pPoseValueEntries - 6))->GetText(this: *(m_pPoseValueEntries - 6), a2: nullptr, a3: 100);
        (*(m_pPoseValueEntries - 6))->AddActionSignalTarget_2(this: *(m_pPoseValueEntries - 6), a2: this);
        V_snprintf(pDest: controlName, maxLen: 0x40u, pFormat: "PoseValueEntry%i", v24);
        v28 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
        if ( v28 != nullptr )
          v29 = vgui::TextEntry::TextEntry(
                  this: v28,
                  parent: this->m_pSequencesPage,
                  panelName: (vgui::Panel *)controlName);
        else
          v29 = nullptr;
        *m_pPoseValueEntries = v29;
        vgui::Panel::SetAutoResize(
          this: v29,
          pinCorner: PIN_TOPLEFT,
          resizeDir: AUTORESIZE_NO,
          nPinOffsetX: 330,
          nPinOffsetY: ib,
          nUnpinnedCornerOffsetX: 0,
          nUnpinnedCornerOffsetY: 0);
        vgui::Panel::SetWide(this: *m_pPoseValueEntries, wide: 40);
        (*m_pPoseValueEntries)->SendNewLine(this: *m_pPoseValueEntries, a2: true);
        (*m_pPoseValueEntries)->AddActionSignalTarget_2(this: *m_pPoseValueEntries, a2: this);
        V_snprintf(pDest: controlName, maxLen: 0x40u, pFormat: "PoseParameterName%i", v24);
        v30 = (vgui::ComboBox *)operator new(nSize: 0x458u);
        if ( v30 != nullptr )
          v31 = vgui::ComboBox::ComboBox(
                  this: v30,
                  parent: this->m_pSequencesPage,
                  panelName: (vgui::Panel *)controlName,
                  numLines: 8,
                  allowEdit: false);
        else
          v31 = nullptr;
        m_pPoseValueEntries[6] = v31;
        vgui::Panel::SetAutoResize(
          this: v31,
          pinCorner: PIN_TOPLEFT,
          resizeDir: AUTORESIZE_NO,
          nPinOffsetX: 380,
          nPinOffsetY: ib,
          nUnpinnedCornerOffsetX: 0,
          nUnpinnedCornerOffsetY: 0);
        vgui::Panel::SetWide(this: m_pPoseValueEntries[6], wide: 120);
        m_pPoseValueEntries[6]->AddActionSignalTarget_2(this: m_pPoseValueEntries[6], a2: this);
        ib += 32;
        ++v24;
        ++m_pPoseValueEntries;
      }
      while ( v24 < 6 );
      v32 = (vgui::Button *)operator new(nSize: 0x1F4u);
      if ( v32 != nullptr )
        v33 = vgui::Button::Button(
                this: v32,
                parent: this->m_pSequencesPage,
                panelName: "DefaultsButton",
                text: "#SequencePicker_Defaults",
                pActionSignalTarget: this,
                pCmd: "ResetToDefaults");
      else
        v33 = nullptr;
      this->m_pPoseDefaultButton = v33;
      v33->SetContentAlignment(this: v33, a2: a_center);
      vgui::Panel::SetWide(this: this->m_pPoseDefaultButton, wide: 100);
      vgui::Panel::SetAutoResize(
        this: this->m_pPoseDefaultButton,
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_NO,
        nPinOffsetX: 210,
        nPinOffsetY: ib,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
      this->m_pPoseDefaultButton->SetEnabled(this: this->m_pPoseDefaultButton, a2: false);
      v34 = (vgui::CheckButton *)operator new(nSize: 0x218u);
      if ( v34 != nullptr )
        v35 = vgui::CheckButton::CheckButton(
                this: v34,
                parent: this->m_pSequencesPage,
                panelName: "RootMotionCheckBox",
                text: "#SequencePicker_RootMotion");
      else
        v35 = nullptr;
      this->m_pRootMotionCheckBox = v35;
      vgui::Panel::SetAutoResize(
        this: v35,
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_NO,
        nPinOffsetX: 324,
        nPinOffsetY: ib,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
      vgui::Panel::SetWide(this: this->m_pRootMotionCheckBox, wide: 150);
      this->m_pRootMotionCheckBox->SetSelected(this: this->m_pRootMotionCheckBox, a2: true);
    }
    else
    {
      v36 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
      if ( v36 != nullptr )
        v37 = vgui::ListPanel::ListPanel(this: v36, parent: this->m_pSequencesPage, panelName: "SequencesList");
      else
        v37 = nullptr;
      this->m_pSequencesList = v37;
      v37->AddColumnHeader(this: v37, a2: 0, a3: "sequence", a4: "sequence", a5: 52, a6: 0);
      this->m_pSequencesList->AddActionSignalTarget_2(this: this->m_pSequencesList, a2: this);
      this->m_pSequencesList->SetSelectIndividualCells(this: this->m_pSequencesList, a2: true);
      this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: ".MDL file contains no activities");
      this->m_pSequencesList->SetDragEnabled(this: this->m_pSequencesList, a2: true);
      vgui::Panel::SetAutoResize(
        this: this->m_pSequencesList,
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_DOWNANDRIGHT,
        nPinOffsetX: 0,
        nPinOffsetY: 0,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
      this->m_pSequencesList->SetSortFunc(this: this->m_pSequencesList, a2: 0, a3: SequenceSortFunc);
      this->m_pSequencesList->SetSortColumn(this: this->m_pSequencesList, a2: 0);
    }
  }
  this->m_pActivitiesPage = nullptr;
  this->m_pActivitiesList = nullptr;
  if ( (nFlags & 2) != 0 )
  {
    v38 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v38 != nullptr )
      v39 = vgui::PropertyPage::PropertyPage(this: v38, parent: this->m_pViewsSheet, panelName: "ActivitiesPage");
    else
      v39 = nullptr;
    v40 = this->m_pViewsSheet;
    this->m_pActivitiesPage = v39;
    v40->AddPage(this: v40, a2: v39, a3: "Activities", a4: nullptr, a5: false, a6: -1);
    v41 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
    if ( v41 != nullptr )
      v42 = vgui::ListPanel::ListPanel(this: v41, parent: this->m_pActivitiesPage, panelName: "ActivitiesList");
    else
      v42 = nullptr;
    this->m_pActivitiesList = v42;
    v42->AddColumnHeader(this: v42, a2: 0, a3: "activity", a4: "activity", a5: 52, a6: 0);
    this->m_pActivitiesList->AddActionSignalTarget_2(this: this->m_pActivitiesList, a2: this);
    this->m_pActivitiesList->SetSelectIndividualCells(this: this->m_pActivitiesList, a2: true);
    this->m_pActivitiesList->SetEmptyListText_2(this: this->m_pActivitiesList, a2: ".MDL file contains no activities");
    this->m_pActivitiesList->SetDragEnabled(this: this->m_pActivitiesList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pActivitiesList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 0,
      nPinOffsetY: 0,
      nUnpinnedCornerOffsetX: 0,
      nUnpinnedCornerOffsetY: 0);
    this->m_pActivitiesList->SetSortFunc(this: this->m_pActivitiesList, a2: 0, a3: ActivitySortFunc);
    this->m_pActivitiesList->SetSortColumn(this: this->m_pActivitiesList, a2: 0);
  }
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/sequencepicker.res",
    dialogID: 0);
  vgui::Panel::MakeReadyForUse(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104CAD60
// Name: public: char const __near * CSequencePicker::GetSelectedSequenceName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSequencePicker::GetSelectedSequenceName(CSequencePicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  IMDLCache *v5; // eax
  const studiohdr_t *v6; // eax
  int m_nSequenceIndex; // esi
  int v8; // eax
  mstudioseqdesc_t *v9; // eax
  char *v10; // esi
  int v11; // eax
  KeyValues *v12; // eax
  CStudioHdr studioHdr; // [esp+4h] [ebp-64h] BYREF

  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    if ( this->m_pSequencesList != nullptr )
    {
      v2 = this->m_pSequencesList->GetSelectedItem(this: this->m_pSequencesList, a2: 0);
      if ( v2 >= 0 )
      {
        v3 = this->m_pSequencesList->GetItem(this: this->m_pSequencesList, a2: v2);
        return KeyValues::GetString(this: v3, keyName: "sequence", defaultValue: nullptr);
      }
    }
    else if ( this->m_bSequenceParams )
    {
      v5 = vgui::MDLCache();
      v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
      if ( v6 != nullptr )
      {
        CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v6, mdlcache: nullptr);
        m_nSequenceIndex = this->m_SequenceLayers[0].m_nSequenceIndex;
        if ( m_nSequenceIndex >= 0 )
        {
          v8 = studioHdr.m_pVModel != nullptr
             ? CStudioHdr::GetNumSeq_Internal(this: &studioHdr)
             : studioHdr.m_pStudioHdr->numlocalseq;
          if ( m_nSequenceIndex < v8 )
          {
            v9 = CStudioHdr::pSeqdesc(this: &studioHdr, iSequence: m_nSequenceIndex);
            v10 = (char *)v9 + v9->szlabelindex;
            CStudioHdr::~CStudioHdr(this: &studioHdr);
            return v10;
          }
        }
        CStudioHdr::~CStudioHdr(this: &studioHdr);
      }
    }
  }
  else if ( this->m_pActivitiesPage != nullptr
         && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    v11 = this->m_pActivitiesList->GetSelectedItem(this: this->m_pActivitiesList, a2: 0);
    if ( v11 >= 0 )
    {
      v12 = this->m_pActivitiesList->GetItem(this: this->m_pActivitiesList, a2: v11);
      return KeyValues::GetString(this: v12, keyName: "activity", defaultValue: nullptr);
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104CAEC0
// Name: public: void CSequencePicker::GetPoseParameters(class CUtlVector<float,class CUtlMemory<float,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::GetPoseParameters(
        CSequencePicker *this,
        CUtlMemory<vgui::TreeNode *,int> *poseParameters)
{
  IMDLCache *v3; // eax
  const studiohdr_t *v4; // eax
  int NumPoseParameters; // eax
  float *m_PoseParameters; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  float *v10; // ecx
  int v11; // eax
  float *v12; // eax
  int *v13; // eax
  int *v14; // eax
  const studiohdr_t **v15; // eax
  CStudioHdr studioHdr; // [esp+8h] [ebp-64h] BYREF
  CUtlVector<float,CUtlMemory<float,int> > *poseParametersa; // [esp+74h] [ebp+8h]

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v4, mdlcache: nullptr);
  NumPoseParameters = CStudioHdr::GetNumPoseParameters(this: &studioHdr);
  if ( NumPoseParameters > 0 )
  {
    m_PoseParameters = this->m_PoseParameters;
    for ( poseParametersa = (CUtlVector<float,CUtlMemory<float,int> > *)NumPoseParameters;
          poseParametersa != nullptr;
          poseParametersa = (CUtlVector<float,CUtlMemory<float,int> > *)((char *)poseParametersa - 1) )
    {
      m_pMemory = (int)poseParameters[1].m_pMemory;
      m_nAllocationCount = poseParameters->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: poseParameters, num: m_pMemory - m_nAllocationCount + 1);
      ++poseParameters[1].m_pMemory;
      v10 = (float *)poseParameters->m_pMemory;
      v11 = (int)poseParameters[1].m_pMemory - m_pMemory - 1;
      poseParameters[1].m_nAllocationCount = (int)poseParameters->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v10[m_pMemory + 1],
          src: (unsigned __int8 *)&v10[m_pMemory],
          count: 4 * v11);
      v12 = (float *)&poseParameters->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
        *v12 = *m_PoseParameters;
      ++m_PoseParameters;
    }
  }
  CStudioHdr::Term(this: &studioHdr);
  v13 = studioHdr.m_boneParent.m_Memory.m_pMemory;
  studioHdr.m_boneParent.m_Size = 0;
  if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneParent.m_Memory.m_pMemory);
      v13 = nullptr;
      studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_boneParent.m_pElements = v13;
  if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v13 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
      studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v14 = studioHdr.m_boneFlags.m_Memory.m_pMemory;
  studioHdr.m_boneFlags.m_Size = 0;
  if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneFlags.m_Memory.m_pMemory);
      v14 = nullptr;
      studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_boneFlags.m_pElements = v14;
  if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v14 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
      studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v15 = studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
  studioHdr.m_pStudioHdrCache.m_Size = 0;
  if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
      v15 = nullptr;
      studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_pStudioHdrCache.m_pElements = v15;
  if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
}

//------------------------------------------------------------------------------
// Address: 0x104CB050
// Name: public: void CSequencePicker::GetSeqenceLayers(class CUtlVector<struct MDLSquenceLayer_t,class CUtlMemory<struct MDLSquenceLayer_t,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::GetSeqenceLayers(
        CSequencePicker *this,
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *sequenceLayers)
{
  MDLSquenceLayer_t *v2; // esi
  int i; // edi

  v2 = &this->m_SequenceLayers[1];
  for ( i = 3; i != 0; --i )
  {
    if ( v2->m_nSequenceIndex >= 0 && v2->m_flWeight > 0.0 )
      CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
        this: sequenceLayers,
        elem: sequenceLayers->m_Size,
        src: (const vgui::PropertySheet::Page_t *)v2);
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CB090
// Name: private: void CSequencePicker::SetPoseParameterValue(float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::SetPoseParameterValue(
        CSequencePicker *this,
        float flPoseParameterValue,
        unsigned int nParameterIndex)
{
  IMDLCache *v5; // eax
  const studiohdr_t *v6; // eax
  const mstudioposeparamdesc_t *v7; // edi
  vgui::Slider **m_pPoseValueSliders; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  CStudioHdr v11; // [esp+14h] [ebp-84h] BYREF
  char pDest[24]; // [esp+78h] [ebp-20h] BYREF
  int valueText_20; // [esp+A4h] [ebp+Ch]

  if ( nParameterIndex <= 0x17 )
  {
    v5 = vgui::MDLCache();
    v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
    CStudioHdr::CStudioHdr(this: &v11, pStudioHdr: v6, mdlcache: nullptr);
    v7 = CStudioHdr::pPoseParameter(this: &v11, i: nParameterIndex);
    this->m_PoseParameters[nParameterIndex] = flPoseParameterValue;
    CMDLPanel::SetPoseParameters(this: this->m_pMDLPreview, pPoseParameters: this->m_PoseParameters, nCount: 24);
    m_pPoseValueSliders = this->m_pPoseValueSliders;
    for ( valueText_20 = 6; valueText_20 != 0; --valueText_20 )
    {
      if ( m_pPoseValueSliders[26] == (vgui::Slider *)nParameterIndex )
      {
        v9 = (float)(flPoseParameterValue * 2.0) - 1.0;
        if ( v9 < 0.0 )
          LODWORD(v10) = COERCE_UNSIGNED_INT(fsqrt(-v9)) ^ 0x80000000;
        else
          v10 = fsqrt(v9);
        (*m_pPoseValueSliders)->SetValue(
          this: *m_pPoseValueSliders,
          a2: (int)(float)((float)((float)((float)(v10 + 1.0) * 0.5) * 100.0) + 0.5),
          a3: false);
        V_snprintf(
          pDest,
          maxLen: 0x20u,
          pFormat: "%0.2f",
          (float)((float)((float)(v7->end - v7->start) * flPoseParameterValue) + v7->start));
        ((void (__thiscall *)(vgui::Slider *, char *))m_pPoseValueSliders[6]->SetValue)(
          a1: m_pPoseValueSliders[6],
          a2: pDest);
      }
      ++m_pPoseValueSliders;
    }
    CStudioHdr::Term(this: &v11);
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&v11.m_boneParent);
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&v11.m_boneFlags);
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&v11.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CB220
// Name: private: void CSequencePicker::UpdatePoseControlsFromParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::UpdatePoseControlsFromParameters(CSequencePicker *this)
{
  IMDLCache *v2; // eax
  const studiohdr_t *v3; // eax
  signed int v4; // esi
  float *m_PoseParameters; // edi
  int *m_pMemory; // eax
  int *v7; // eax
  const studiohdr_t **v8; // eax
  CStudioHdr v9; // [esp+14h] [ebp-68h] BYREF
  int NumPoseParameters; // [esp+78h] [ebp-4h]

  v2 = vgui::MDLCache();
  v3 = v2->GetStudioHdr(this: v2, a2: this->m_hSelectedMDL);
  v4 = 0;
  CStudioHdr::CStudioHdr(this: &v9, pStudioHdr: v3, mdlcache: nullptr);
  NumPoseParameters = CStudioHdr::GetNumPoseParameters(this: &v9);
  if ( NumPoseParameters > 0 )
  {
    m_PoseParameters = this->m_PoseParameters;
    do
      CSequencePicker::SetPoseParameterValue(this, flPoseParameterValue: *m_PoseParameters++, nParameterIndex: v4++);
    while ( v4 < NumPoseParameters );
  }
  CStudioHdr::Term(this: &v9);
  m_pMemory = v9.m_boneParent.m_Memory.m_pMemory;
  v9.m_boneParent.m_Size = 0;
  if ( v9.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9.m_boneParent.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      v9.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    v9.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v9.m_boneParent.m_pElements = m_pMemory;
  if ( v9.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      v9.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    v9.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v7 = v9.m_boneFlags.m_Memory.m_pMemory;
  v9.m_boneFlags.m_Size = 0;
  if ( v9.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9.m_boneFlags.m_Memory.m_pMemory);
      v7 = nullptr;
      v9.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    v9.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v9.m_boneFlags.m_pElements = v7;
  if ( v9.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      v9.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    v9.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v8 = v9.m_pStudioHdrCache.m_Memory.m_pMemory;
  v9.m_pStudioHdrCache.m_Size = 0;
  if ( v9.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9.m_pStudioHdrCache.m_Memory.m_pMemory);
      v8 = nullptr;
      v9.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    v9.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  v9.m_pStudioHdrCache.m_pElements = v8;
  if ( v9.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v8 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x104CB370
// Name: private: virtual void CSequencePicker::OnTextKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnTextKillFocus(CSequencePicker *this, KeyValues *pData)
{
  vgui::TextEntry *Ptr; // eax
  int v4; // esi
  vgui::TextEntry **i; // ecx
  IMDLCache *v6; // eax
  const studiohdr_t *v7; // eax
  int v8; // esi
  const mstudioposeparamdesc_t *v9; // eax
  float start; // xmm0_4
  float end; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  int *m_pMemory; // eax
  int *v16; // eax
  const studiohdr_t **v17; // eax
  CStudioHdr v18; // [esp+14h] [ebp-64h] BYREF
  float v19; // [esp+80h] [ebp+8h]

  Ptr = (vgui::TextEntry *)KeyValues::GetPtr(this: pData, keyName: "panel", defaultValue: nullptr);
  v4 = 0;
  for ( i = this->m_pPoseValueEntries; Ptr != *i; ++i )
  {
    if ( ++v4 >= 6 )
      return;
  }
  if ( v4 >= 0 )
  {
    v19 = this->m_pPoseValueEntries[v4]->GetValueAsFloat(this: this->m_pPoseValueEntries[v4]);
    v6 = vgui::MDLCache();
    v7 = v6->GetStudioHdr(this: v6, a2: this->m_hSelectedMDL);
    CStudioHdr::CStudioHdr(this: &v18, pStudioHdr: v7, mdlcache: nullptr);
    v8 = this->m_PoseControlMap[v4];
    v9 = CStudioHdr::pPoseParameter(this: &v18, i: v8);
    start = v9->start;
    end = v9->end;
    if ( end <= start )
      v12 = v9->end;
    else
      v12 = v9->start;
    if ( start > end )
      end = v9->start;
    v13 = v19;
    if ( v12 <= v19 )
      v14 = v19;
    else
      v14 = v12;
    if ( v14 <= end )
    {
      if ( v12 > v19 )
        v13 = v12;
    }
    else
    {
      v13 = end;
    }
    CSequencePicker::SetPoseParameterValue(
      this,
      flPoseParameterValue: (float)(v13 - v12) / (float)(end - v12),
      nParameterIndex: v8);
    CStudioHdr::Term(this: &v18);
    m_pMemory = v18.m_boneParent.m_Memory.m_pMemory;
    v18.m_boneParent.m_Size = 0;
    if ( v18.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v18.m_boneParent.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18.m_boneParent.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        v18.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      v18.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v18.m_boneParent.m_pElements = m_pMemory;
    if ( v18.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        v18.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      v18.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v16 = v18.m_boneFlags.m_Memory.m_pMemory;
    v18.m_boneFlags.m_Size = 0;
    if ( v18.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v18.m_boneFlags.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18.m_boneFlags.m_Memory.m_pMemory);
        v16 = nullptr;
        v18.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      v18.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v18.m_boneFlags.m_pElements = v16;
    if ( v18.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v16 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
        v18.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      v18.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v17 = v18.m_pStudioHdrCache.m_Memory.m_pMemory;
    v18.m_pStudioHdrCache.m_Size = 0;
    if ( v18.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v18.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18.m_pStudioHdrCache.m_Memory.m_pMemory);
        v17 = nullptr;
        v18.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      v18.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    v18.m_pStudioHdrCache.m_pElements = v17;
    if ( v18.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v17 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CB540
// Name: public: CSequencePickerFrame::CSequencePickerFrame(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSequencePickerFrame *__thiscall CSequencePickerFrame::CSequencePickerFrame(
        CSequencePickerFrame *this,
        vgui::Panel *pParent,
        char nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CSequencePicker *v7; // eax
  CSequencePicker *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: "SequencePickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CSequencePickerFrame_vtbl *)&CSequencePickerFrame::`vftable';
  if ( `CSequencePickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CSequencePickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSequencePickerFrame");
    v4->pfnClassName = CSequencePickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CSequencePickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSequencePickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSequencePickerFrame");
    v5->pfnClassName = CSequencePickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CSequencePickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSequencePickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSequencePickerFrame");
    v6->pfnClassName = CSequencePickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CSequencePicker *)operator new(nSize: 0x2C0u);
  if ( v7 != nullptr )
    v8 = CSequencePicker::CSequencePicker(this: v7, pParent: this, nFlags);
  else
    v8 = nullptr;
  this->m_pPicker = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OpenButton",
            text: "#FileOpenDialog_Open",
            pActionSignalTarget: this,
            pCmd: "Open");
  else
    v10 = nullptr;
  this->m_pOpenButton = v10;
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/sequencepickerframe.res",
    dialogID: 0);
  this->m_pOpenButton->SetEnabled(this: this->m_pOpenButton, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104CB6E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSequencePickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSequencePickerFrame::GetMessageMap(CSequencePickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSequencePickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSequencePickerFrame::GetMessageMap'::`2'::s_pMap;
  `CSequencePickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSequencePickerFrame");
  `CSequencePickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CB710
// Name: public: virtual struct PanelAnimationMap __near * CSequencePickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSequencePickerFrame::GetAnimMap(CSequencePickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CSequencePickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x104CB720
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSequencePickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSequencePickerFrame::GetKBMap(CSequencePickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSequencePickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSequencePickerFrame::GetKBMap'::`2'::s_pMap;
  `CSequencePickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSequencePickerFrame");
  `CSequencePickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CB750
// Name: public: virtual void CSequencePickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CSequencePickerFrame::OnCommand(CSequencePickerFrame *this@<ecx>, int a2@<ebx>, char *pCommand)
{
  CSequencePickerFrame *v3; // edi
  int SelectedSequenceType; // eax
  char *SelectedSequenceName; // ebx
  int v6; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // ebx
  CSequencePicker *m_pPicker; // ecx
  KeyValues *v10; // eax
  KeyValues *v11; // edi
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  int v13; // eax
  CSequencePicker *v14; // ecx
  float *m_pMemory; // edi
  int i; // esi
  CSequencePickerFrame *v17; // esi
  int v18; // eax
  char v19; // al
  KeyValues *v20; // eax
  char pDest[12]; // [esp+10h] [ebp-6Ch] BYREF
  char poseParameterName[32]; // [esp+1Ch] [ebp-60h] BYREF
  char layerName[32]; // [esp+3Ch] [ebp-40h] BYREF
  CUtlVector<float,CUtlMemory<float,int> > poseParameters; // [esp+5Ch] [ebp-20h] BYREF
  _BYTE sequenceLayers[12]; // [esp+70h] [ebp-Ch] OVERLAPPED
  char *s1; // [esp+84h] [ebp+8h]

  v3 = this;
  *(_DWORD *)&sequenceLayers[8] = this;
  if ( _V_stricmp(s1: pCommand, s2: "Open") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this: v3, command: pCommand);
    else
      v3->CloseModal(this: v3);
  }
  else
  {
    SelectedSequenceType = CSequencePicker::GetSelectedSequenceType(this: v3->m_pPicker);
    s1 = (char *)SelectedSequenceType;
    if ( SelectedSequenceType == 1 || SelectedSequenceType == 2 )
    {
      SelectedSequenceName = CSequencePicker::GetSelectedSequenceName(this: v3->m_pPicker);
      v6 = 0;
      if ( SelectedSequenceName != nullptr )
      {
        v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( s1 == (char *)1 )
        {
          if ( v7 != nullptr )
            v8 = KeyValues::KeyValues(
                   this: v7,
                   setName: "SequenceSelected",
                   firstKey: "sequence",
                   firstValue: SelectedSequenceName);
          else
            v8 = nullptr;
          m_pPicker = v3->m_pPicker;
          memset(&poseParameters.m_Memory.m_nGrowSize, 0, 12);
          *(_DWORD *)sequenceLayers = 0;
          *(_DWORD *)&sequenceLayers[4] = 0;
          CSequencePicker::GetSeqenceLayers(
            this: m_pPicker,
            sequenceLayers: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&poseParameters.m_Memory.m_nGrowSize);
          KeyValues::SetInt(this: v8, keyName: "numLayers", value: *(int *)sequenceLayers);
          if ( *(int *)sequenceLayers > 0 )
          {
            do
            {
              V_snprintf(pDest: &poseParameterName[20], maxLen: 0x20u, pFormat: "layer%i", v6);
              v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v10 != nullptr )
                v11 = KeyValues::KeyValues(this: v10, setName: &poseParameterName[20]);
              else
                v11 = nullptr;
              KeyValues::SetInt(
                this: v11,
                keyName: "sequence",
                value: *(_DWORD *)(poseParameters.m_Memory.m_nGrowSize + 8 * v6));
              KeyValues::SetFloat(
                this: v11,
                keyName: "weight",
                value: *(float *)(poseParameters.m_Memory.m_nGrowSize + 8 * v6 + 4));
              KeyValues::AddSubKey(this: v8, pSubkey: v11);
              ++v6;
            }
            while ( v6 < *(int *)sequenceLayers );
            v3 = *(CSequencePickerFrame **)&sequenceLayers[8];
          }
          Alloc_2 = _g_pMemAlloc->Alloc_2;
          *(_DWORD *)&layerName[24] = 24;
          *(_DWORD *)&layerName[28] = 0;
          v13 = ((int (__thiscall *)(IMemAlloc *, int, int))Alloc_2)(a1: _g_pMemAlloc, a2: 96, a3: a2);
          v14 = v3->m_pPicker;
          *(_DWORD *)&layerName[20] = v13;
          poseParameters.m_Memory.m_nAllocationCount = v13;
          poseParameters.m_Memory.m_pMemory = nullptr;
          CSequencePicker::GetPoseParameters(
            this: v14,
            poseParameters: (CUtlMemory<vgui::TreeNode *,int> *)&layerName[20]);
          m_pMemory = poseParameters.m_Memory.m_pMemory;
          KeyValues::SetInt(this: v8, keyName: "numPoseParameters", value: (int)poseParameters.m_Memory.m_pMemory);
          for ( i = 0; i < (int)m_pMemory; ++i )
          {
            V_snprintf(pDest, maxLen: 0x20u, pFormat: "poseParameter%i", i);
            KeyValues::SetFloat(this: v8, keyName: pDest, value: *(float *)(*(_DWORD *)&layerName[20] + 4 * i));
          }
          v17 = *(CSequencePickerFrame **)&sequenceLayers[8];
          v18 = *(_DWORD *)(*(_DWORD *)&sequenceLayers[8] + 532);
          if ( *(_DWORD *)(v18 + 452) != 0 )
            v19 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v18 + 452) + 1024))(a1: *(_DWORD *)(v18 + 452));
          else
            v19 = 0;
          KeyValues::SetInt(this: v8, keyName: "rootMotion", value: v19 != 0);
          ((void (__thiscall *)(CSequencePickerFrame *))v17->PostActionSignal)(a1: v17);
          if ( *(int *)&layerName[28] >= 0 && *(_DWORD *)&layerName[20] != 0 )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&layerName[20]);
          if ( (int)poseParameters.m_pElements >= 0 && poseParameters.m_Memory.m_nGrowSize != 0 )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)poseParameters.m_Memory.m_nGrowSize);
          v3 = v17;
        }
        else if ( v7 != nullptr )
        {
          v20 = KeyValues::KeyValues(
                  this: v7,
                  setName: "SequenceSelected",
                  firstKey: "activity",
                  firstValue: SelectedSequenceName);
          v3->PostActionSignal(this: v3, a2: v20);
        }
        else
        {
          v3->PostActionSignal(this: v3, a2: nullptr);
        }
        v3->CloseModal(this: v3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CBA10
// Name: private: void CSequencePicker::UpdateAvailablePoseParmeters(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSequencePicker::UpdateAvailablePoseParmeters(CSequencePicker *this@<ecx>, int a2@<esi>)
{
  CSequencePicker *v2; // ebx
  bool v3; // zf
  IMDLCache *v4; // eax
  const studiohdr_t *v5; // eax
  int *p_m_nSequenceIndex; // esi
  int v7; // edi
  int v8; // eax
  int NumPoseParameters; // esi
  int v10; // edi
  int v11; // eax
  int v12; // eax
  vgui::Slider **m_pPoseValueSliders; // ebx
  vgui::Slider *v14; // ecx
  vgui::ComboBox *v15; // esi
  int v16; // edi
  int v17; // ebx
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  int v20; // eax
  vgui::Slider **v21; // esi
  int v22; // ebx
  vgui::Slider *v23; // ecx
  int *m_pMemory; // eax
  int *v25; // eax
  const studiohdr_t **v26; // eax
  int sequencePoseParameters[24]; // [esp+4h] [ebp-F4h] BYREF
  bool activePoseParameters[24]; // [esp+64h] [ebp-94h] BYREF
  CStudioHdr studioHdr; // [esp+7Ch] [ebp-7Ch] BYREF
  const mstudioposeparamdesc_t *poseParameter; // [esp+E0h] [ebp-18h]
  vgui::Slider **v31; // [esp+E4h] [ebp-14h]
  CSequencePicker *v32; // [esp+E8h] [ebp-10h]
  int nNumSequenceParameters; // [esp+ECh] [ebp-Ch]
  int nNumActiveControls; // [esp+F0h] [ebp-8h]
  int iControl; // [esp+F4h] [ebp-4h]

  v2 = this;
  v3 = !this->m_bSequenceParams;
  v32 = this;
  if ( !v3 )
  {
    v4 = vgui::MDLCache();
    v5 = (const studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, int))v4->GetStudioHdr)(
                                a1: v4,
                                a2: v2->m_hSelectedMDL,
                                a3: a2);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v5, mdlcache: nullptr);
    memset(activePoseParameters, 0, sizeof(activePoseParameters));
    p_m_nSequenceIndex = &v2->m_SequenceLayers[0].m_nSequenceIndex;
    for ( iControl = 4; iControl != 0; --iControl )
    {
      v7 = *p_m_nSequenceIndex;
      if ( *p_m_nSequenceIndex >= 0 )
      {
        v8 = studioHdr.m_pVModel != nullptr
           ? CStudioHdr::GetNumSeq_Internal(this: &studioHdr)
           : studioHdr.m_pStudioHdr->numlocalseq;
        if ( v7 < v8 )
          FindSequencePoseParameters(hdr: &studioHdr, nSequence: v7, pPoseParameters: activePoseParameters, nCount: 24);
      }
      p_m_nSequenceIndex += 2;
    }
    NumPoseParameters = CStudioHdr::GetNumPoseParameters(this: &studioHdr);
    v10 = 0;
    nNumSequenceParameters = 0;
    _V_memset(dest: (unsigned __int8 *)sequencePoseParameters, fill: 0xFFu, count: 0x60u);
    v11 = 0;
    if ( NumPoseParameters <= 0 )
      goto LABEL_16;
    do
    {
      if ( activePoseParameters[v11] )
        sequencePoseParameters[v10++] = v11;
      ++v11;
    }
    while ( v11 < NumPoseParameters );
    nNumSequenceParameters = v10;
    if ( v10 <= 6 )
    {
LABEL_16:
      nNumActiveControls = v10;
      v12 = v10;
    }
    else
    {
      v12 = 6;
      nNumActiveControls = 6;
    }
    iControl = 0;
    if ( v12 > 0 )
    {
      m_pPoseValueSliders = v2->m_pPoseValueSliders;
      v31 = m_pPoseValueSliders;
      while ( 1 )
      {
        v14 = *m_pPoseValueSliders;
        m_pPoseValueSliders[26] = (vgui::Slider *)sequencePoseParameters[iControl];
        v14->SetEnabled(this: v14, a2: true);
        m_pPoseValueSliders[6]->SetEnabled(this: m_pPoseValueSliders[6], a2: true);
        v15 = (vgui::ComboBox *)m_pPoseValueSliders[12];
        v15->SetEnabled(this: v15, a2: true);
        vgui::ComboBox::RemoveAll(this: v15);
        v15->SetNumberOfEditLines(this: v15, a2: v10);
        v16 = 0;
        if ( nNumSequenceParameters > 0 )
        {
          do
          {
            v17 = sequencePoseParameters[v16];
            poseParameter = CStudioHdr::pPoseParameter(this: &studioHdr, i: v17);
            v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v18 != nullptr )
              v19 = KeyValues::KeyValues(this: v18, setName: "ParameterItem", firstKey: "paramIndex", firstValue: v17);
            else
              v19 = nullptr;
            v20 = v15->AddItem_2(this: v15, a2: (const char *)poseParameter + poseParameter->sznameindex, a3: v19);
            if ( v16 == iControl )
              v15->ActivateItem(this: v15, a2: v20);
            ++v16;
          }
          while ( v16 < nNumSequenceParameters );
          m_pPoseValueSliders = v31;
        }
        ++m_pPoseValueSliders;
        ++iControl;
        v31 = m_pPoseValueSliders;
        if ( iControl >= nNumActiveControls )
          break;
        v10 = nNumSequenceParameters;
      }
      v2 = v32;
      v12 = nNumActiveControls;
    }
    if ( v12 < 6 )
    {
      v21 = &v2->m_pPoseValueSliders[v12];
      v22 = 6 - v12;
      do
      {
        v23 = *v21;
        v21[26] = (vgui::Slider *)-1;
        v23->SetEnabled(this: v23, a2: false);
        (*v21)->SetValue(this: *v21, a2: 0, a3: true);
        v21[6]->SetEnabled(this: v21[6], a2: false);
        ((void (__thiscall *)(vgui::Slider *, const char *))v21[6]->SetValue)(a1: v21[6], a2: &var);
        v21[12]->SetEnabled(this: v21[12], a2: false);
        vgui::ComboBox::RemoveAll(this: (vgui::ComboBox *)v21[12]);
        ((void (__thiscall *)(vgui::Slider *, const char *))v21[12]->SetValue)(a1: v21[12], a2: &var);
        ++v21;
        --v22;
      }
      while ( v22 != 0 );
      v2 = v32;
      v12 = nNumActiveControls;
    }
    v2->m_pPoseDefaultButton->SetEnabled(this: v2->m_pPoseDefaultButton, a2: v12 > 0);
    CSequencePicker::UpdatePoseControlsFromParameters(this: v2);
    CStudioHdr::Term(this: &studioHdr);
    m_pMemory = studioHdr.m_boneParent.m_Memory.m_pMemory;
    studioHdr.m_boneParent.m_Size = 0;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneParent.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneParent.m_pElements = m_pMemory;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v25 = studioHdr.m_boneFlags.m_Memory.m_pMemory;
    studioHdr.m_boneFlags.m_Size = 0;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneFlags.m_Memory.m_pMemory);
        v25 = nullptr;
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneFlags.m_pElements = v25;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v25 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v26 = studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
    studioHdr.m_pStudioHdrCache.m_Size = 0;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
        v26 = nullptr;
        studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_pStudioHdrCache.m_pElements = v26;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v26 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v26);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CBDC0
// Name: private: void CSequencePicker::ResetPoseParametersToDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::ResetPoseParametersToDefault(CSequencePicker *this)
{
  IMDLCache *v2; // eax
  const studiohdr_t *v3; // eax
  CStudioHdr studioHdr; // [esp+4h] [ebp-64h] BYREF

  v2 = vgui::MDLCache();
  v3 = v2->GetStudioHdr(this: v2, a2: this->m_hSelectedMDL);
  CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v3, mdlcache: nullptr);
  Studio_CalcDefaultPoseParameters(pStudioHdr: &studioHdr, flPoseParameter: this->m_PoseParameters, nCount: 24);
  CSequencePicker::UpdatePoseControlsFromParameters(this);
  CStudioHdr::Term(this: &studioHdr);
  CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&studioHdr.m_boneParent);
  CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&studioHdr.m_boneFlags);
  CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&studioHdr.m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x104CBE30
// Name: private: void CSequencePicker::UpdatePoseParameterControlsForMdl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::UpdatePoseParameterControlsForMdl(CSequencePicker *this)
{
  vgui::Slider **m_pPoseValueSliders; // esi
  int i; // edi
  vgui::Slider *v4; // ecx
  IMDLCache *v5; // eax
  const studiohdr_t *v6; // eax
  int *m_pMemory; // eax
  int *v8; // eax
  const studiohdr_t **v9; // eax
  CStudioHdr pStudioHdr; // [esp+8h] [ebp-64h] BYREF

  if ( this->m_bSequenceParams )
  {
    m_pPoseValueSliders = this->m_pPoseValueSliders;
    for ( i = 6; i != 0; --i )
    {
      v4 = *m_pPoseValueSliders;
      m_pPoseValueSliders[26] = (vgui::Slider *)-1;
      v4->SetEnabled(this: v4, a2: false);
      m_pPoseValueSliders[6]->SetEnabled(this: m_pPoseValueSliders[6], a2: false);
      m_pPoseValueSliders[12]->SetEnabled(this: m_pPoseValueSliders[12], a2: false);
      ++m_pPoseValueSliders;
    }
  }
  v5 = vgui::MDLCache();
  v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
  CStudioHdr::CStudioHdr(this: &pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
  Studio_CalcDefaultPoseParameters(&pStudioHdr, flPoseParameter: this->m_PoseParameters, nCount: 24);
  CSequencePicker::UpdatePoseControlsFromParameters(this);
  CStudioHdr::Term(this: &pStudioHdr);
  m_pMemory = pStudioHdr.m_boneParent.m_Memory.m_pMemory;
  pStudioHdr.m_boneParent.m_Size = 0;
  if ( pStudioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pStudioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pStudioHdr.m_boneParent.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      pStudioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  pStudioHdr.m_boneParent.m_pElements = m_pMemory;
  if ( pStudioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      pStudioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v8 = pStudioHdr.m_boneFlags.m_Memory.m_pMemory;
  pStudioHdr.m_boneFlags.m_Size = 0;
  if ( pStudioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pStudioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pStudioHdr.m_boneFlags.m_Memory.m_pMemory);
      v8 = nullptr;
      pStudioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  pStudioHdr.m_boneFlags.m_pElements = v8;
  if ( pStudioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      pStudioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v9 = pStudioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
  pStudioHdr.m_pStudioHdrCache.m_Size = 0;
  if ( pStudioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pStudioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pStudioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
      v9 = nullptr;
      pStudioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  pStudioHdr.m_pStudioHdrCache.m_pElements = v9;
  if ( pStudioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v9 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x104CBFB0
// Name: private: void CSequencePicker::SetSequenceLayer(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSequencePicker::SetSequenceLayer(
        CSequencePicker *this@<ecx>,
        int a2@<esi>,
        unsigned int nLayerIndex,
        int nSequenceIndex,
        float flWeight)
{
  CSequencePicker *v5; // edi
  IMDLCache *v6; // eax
  studiohdr_t *v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  float v10; // xmm0_4
  vgui::ComboBox *v11; // esi
  mstudioseqdesc_t *v12; // eax
  const char *v13; // ebx
  int v14; // edi
  KeyValues *ItemUserData; // eax
  char *String; // eax
  vgui::Slider *v17; // ecx
  int v18; // esi
  studiohdr_t *pstudiohdr; // [esp+4h] [ebp-8h]
  int nItems; // [esp+18h] [ebp+Ch]

  v5 = this;
  v6 = vgui::MDLCache();
  v7 = v6->GetStudioHdr(this: v6, a2: v5->m_hSelectedMDL);
  pstudiohdr = v7;
  if ( v7 != nullptr )
  {
    v8 = v7->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v7) : v7->numlocalseq;
    v9 = nLayerIndex;
    if ( nLayerIndex <= 3 && nSequenceIndex < v8 )
    {
      v10 = 0.0;
      v5->m_SequenceLayers[nLayerIndex].m_nSequenceIndex = nSequenceIndex;
      if ( flWeight > 0.0 )
      {
        v10 = 1.0;
        if ( flWeight < 1.0 )
          v10 = flWeight;
      }
      v5->m_SequenceLayers[nLayerIndex].m_flWeight = v10;
      CMDLPanel::SetSequenceLayers(this: v5->m_pMDLPreview, pSequenceLayers: &v5->m_SequenceLayers[1], nCount: 3);
      v11 = v5->m_pLayerSequenceSelectors[nLayerIndex];
      if ( v11 != nullptr )
      {
        if ( nSequenceIndex >= 0 )
        {
          v12 = studiohdr_t::pSeqdesc(this: pstudiohdr, i: nSequenceIndex);
          v13 = (char *)v12 + v12->szlabelindex;
          v14 = 0;
          nItems = v11->GetItemCount(this: v11);
          if ( nItems > 0 )
          {
            do
            {
              ItemUserData = vgui::ComboBox::GetItemUserData(this: v11, itemID: v14);
              if ( ItemUserData != nullptr )
              {
                String = KeyValues::GetString(this: ItemUserData, keyName: "sequence", defaultValue: "invalidItem");
                if ( _V_stricmp(s1: v13, s2: String) == 0 )
                  v11->ActivateItem(this: v11, a2: v14);
              }
              ++v14;
            }
            while ( v14 < nItems );
          }
          v5 = this;
          v9 = nLayerIndex;
        }
        else
        {
          v11->SetText(this: v11, a2: &var);
        }
      }
      v17 = v5->m_pLayerSequenceSliders[v9];
      v18 = a2;
      if ( v17 != nullptr )
        v17->SetValue(this: v17, a2: (int)(float)(v5->m_SequenceLayers[v9].m_flWeight * 100.0), a3: false);
      CSequencePicker::UpdateAvailablePoseParmeters(this: v5, a2: v18);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CC130
// Name: private: void CSequencePicker::UpdateLayerControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::UpdateLayerControls(CSequencePicker *this)
{
  CSequencePicker *v1; // esi
  float *p_m_flWeight; // edi
  IMDLCache *v3; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // ebx
  int v6; // eax
  int v7; // xmm0_4
  vgui::ComboBox *v8; // esi
  mstudioseqdesc_t *v9; // eax
  const char *v10; // ebx
  int v11; // edi
  KeyValues *ItemUserData; // eax
  char *String; // eax
  float v14; // [esp+Ch] [ebp-18h]
  int i; // [esp+14h] [ebp-10h]
  int ia; // [esp+14h] [ebp-10h]
  float *v18; // [esp+18h] [ebp-Ch]
  int iLayer; // [esp+1Ch] [ebp-8h]
  vgui::Slider **m_pLayerSequenceSliders; // [esp+20h] [ebp-4h]

  v1 = this;
  p_m_flWeight = &this->m_SequenceLayers[0].m_flWeight;
  iLayer = 0;
  v18 = &this->m_SequenceLayers[0].m_flWeight;
  m_pLayerSequenceSliders = this->m_pLayerSequenceSliders;
  do
  {
    v14 = *p_m_flWeight;
    i = *((_DWORD *)p_m_flWeight - 1);
    v3 = vgui::MDLCache();
    v4 = v3->GetStudioHdr(this: v3, a2: v1->m_hSelectedMDL);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
      if ( (unsigned int)iLayer <= 3 && i < v6 )
      {
        v7 = 0;
        *((_DWORD *)p_m_flWeight - 1) = i;
        if ( v14 > 0.0 )
        {
          v7 = 1065353216;
          if ( v14 < 1.0 )
            v7 = LODWORD(v14);
        }
        *(_DWORD *)p_m_flWeight = v7;
        CMDLPanel::SetSequenceLayers(this: v1->m_pMDLPreview, pSequenceLayers: &v1->m_SequenceLayers[1], nCount: 3);
        v8 = (vgui::ComboBox *)*(m_pLayerSequenceSliders - 4);
        if ( v8 != nullptr )
        {
          if ( i >= 0 )
          {
            v9 = studiohdr_t::pSeqdesc(this: v5, i);
            v10 = (char *)v9 + v9->szlabelindex;
            v11 = 0;
            ia = v8->GetItemCount(this: v8);
            if ( ia > 0 )
            {
              do
              {
                ItemUserData = vgui::ComboBox::GetItemUserData(this: v8, itemID: v11);
                if ( ItemUserData != nullptr )
                {
                  String = KeyValues::GetString(this: ItemUserData, keyName: "sequence", defaultValue: "invalidItem");
                  if ( _V_stricmp(s1: v10, s2: String) == 0 )
                    v8->ActivateItem(this: v8, a2: v11);
                }
                ++v11;
              }
              while ( v11 < ia );
            }
            p_m_flWeight = v18;
          }
          else
          {
            v8->SetText(this: v8, a2: &var);
          }
        }
        if ( *m_pLayerSequenceSliders != nullptr )
          (*m_pLayerSequenceSliders)->SetValue(
            this: *m_pLayerSequenceSliders,
            a2: (int)(float)(*p_m_flWeight * 100.0),
            a3: false);
        CSequencePicker::UpdateAvailablePoseParmeters(this, a2: (int)v8);
        v1 = this;
      }
    }
    ++m_pLayerSequenceSliders;
    p_m_flWeight += 2;
    ++iLayer;
    v18 = p_m_flWeight;
  }
  while ( iLayer < 4 );
}

//------------------------------------------------------------------------------
// Address: 0x104CC2E0
// Name: private: void CSequencePicker::ResetLayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::ResetLayers(CSequencePicker *this)
{
  MDLSquenceLayer_t *m_SequenceLayers; // ebx
  signed int i; // edi

  m_SequenceLayers = this->m_SequenceLayers;
  this->m_SequenceLayers[0].m_flWeight = 1.0;
  this->m_SequenceLayers[0].m_nSequenceIndex = 0;
  this->m_SequenceLayers[1].m_nSequenceIndex = -1;
  this->m_SequenceLayers[1].m_flWeight = 0.0;
  this->m_SequenceLayers[2].m_nSequenceIndex = -1;
  this->m_SequenceLayers[2].m_flWeight = 0.0;
  this->m_SequenceLayers[3].m_nSequenceIndex = -1;
  this->m_SequenceLayers[3].m_flWeight = 0.0;
  for ( i = 0; i < 4; ++i )
  {
    CSequencePicker::SetSequenceLayer(
      this,
      a2: (int)this,
      nLayerIndex: i,
      nSequenceIndex: m_SequenceLayers->m_nSequenceIndex,
      flWeight: m_SequenceLayers->m_flWeight);
    ++m_SequenceLayers;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CC360
// Name: private: virtual void CSequencePicker::OnSliderMoved(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnSliderMoved(CSequencePicker *this, KeyValues *pData)
{
  vgui::Slider *Ptr; // eax
  int v4; // esi
  vgui::Slider **m_pLayerSequenceSliders; // ecx
  int v6; // esi
  vgui::Slider **i; // ecx
  int v8; // eax
  int v9; // eax

  Ptr = (vgui::Slider *)KeyValues::GetPtr(this: pData, keyName: "panel", defaultValue: nullptr);
  v4 = 0;
  m_pLayerSequenceSliders = this->m_pLayerSequenceSliders;
  do
  {
    if ( Ptr == *m_pLayerSequenceSliders )
    {
      v8 = this->m_pLayerSequenceSliders[v4]->GetValue(this: this->m_pLayerSequenceSliders[v4]);
      CSequencePicker::SetSequenceLayer(
        this,
        a2: v4,
        nLayerIndex: v4,
        nSequenceIndex: this->m_SequenceLayers[v4].m_nSequenceIndex,
        flWeight: (float)v8 * 0.0099999998);
      return;
    }
    ++v4;
    ++m_pLayerSequenceSliders;
  }
  while ( v4 < 4 );
  v6 = 0;
  for ( i = this->m_pPoseValueSliders; Ptr != *i; ++i )
  {
    if ( ++v6 >= 6 )
      return;
  }
  v9 = this->m_pPoseValueSliders[v6]->GetValue(this: this->m_pPoseValueSliders[v6]);
  CSequencePicker::SetPoseParameterValue(
    this,
    flPoseParameterValue: (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)v9 - 50.0) * 0.02) & _mask__AbsFloat_)
                  * (float)((float)((float)v9 - 50.0) * 0.02))
          + 1.0)
  * 0.5,
    nParameterIndex: this->m_PoseControlMap[v6]);
}

//------------------------------------------------------------------------------
// Address: 0x104CC450
// Name: public: virtual void CSequencePicker::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnCommand(CSequencePicker *this, const char *pCommand)
{
  if ( _V_strcmp(s1: "ResetToDefaults", s2: pCommand) == 0 )
    CSequencePicker::ResetPoseParametersToDefault(this);
}

//------------------------------------------------------------------------------
// Address: 0x104CC480
// Name: private: void CSequencePicker::UpdateActiveSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::UpdateActiveSequence(CSequencePicker *this, const char *pSequenceName)
{
  int Sequence; // eax
  int v4; // edi

  Sequence = CSequencePicker::FindSequence(this, pSequenceName);
  v4 = Sequence;
  if ( Sequence >= 0 )
  {
    if ( this->m_bSequenceParams )
    {
      CSequencePicker::SetSequenceLayer(this, a2: (int)this, nLayerIndex: 0, nSequenceIndex: Sequence, flWeight: 1.0);
      CSequencePicker::UpdateAvailablePoseParmeters(this, a2: (int)this);
    }
    CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CC4D0
// Name: private: virtual void CSequencePicker::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnPageChanged(CSequencePicker *this)
{
  char *SelectedSequenceName; // eax
  char *v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  char *v6; // eax
  char *v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // eax

  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    SelectedSequenceName = CSequencePicker::GetSelectedSequenceName(this);
    v3 = SelectedSequenceName;
    if ( SelectedSequenceName == nullptr )
      return;
    CSequencePicker::UpdateActiveSequence(this, pSequenceName: SelectedSequenceName);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "SequencePreviewChanged", firstKey: "sequence", firstValue: v3);
      this->PostActionSignal(this, a2: v5);
      return;
    }
LABEL_11:
    this->PostActionSignal(this, a2: nullptr);
    return;
  }
  if ( this->m_pActivitiesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    v6 = CSequencePicker::GetSelectedSequenceName(this);
    v7 = v6;
    if ( v6 != nullptr )
    {
      CSequencePicker::PlayActivity(this, pActivityName: v6);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v9 = KeyValues::KeyValues(this: v8, setName: "SequencePreviewChanged", firstKey: "activity", firstValue: v7);
        this->PostActionSignal(this, a2: v9);
        return;
      }
      goto LABEL_11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CC5C0
// Name: private: virtual void CSequencePicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnItemSelected(CSequencePicker *this, KeyValues *kv)
{
  vgui::ListPanel *Ptr; // eax
  vgui::ListPanel *m_pSequencesList; // ecx
  char *SelectedSequenceName; // eax
  char *v6; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  vgui::ListPanel *m_pActivitiesList; // ecx
  char *v10; // eax
  char *v11; // edi
  KeyValues *v12; // eax
  KeyValues *v13; // eax

  Ptr = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pSequencesList = this->m_pSequencesList;
  if ( m_pSequencesList != nullptr && Ptr == m_pSequencesList )
  {
    SelectedSequenceName = CSequencePicker::GetSelectedSequenceName(this);
    v6 = SelectedSequenceName;
    if ( SelectedSequenceName == nullptr )
      return;
    CSequencePicker::UpdateActiveSequence(this, pSequenceName: SelectedSequenceName);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(this: v7, setName: "SequencePreviewChanged", firstKey: "sequence", firstValue: v6);
      this->PostActionSignal(this, a2: v8);
      return;
    }
LABEL_11:
    this->PostActionSignal(this, a2: nullptr);
    return;
  }
  m_pActivitiesList = this->m_pActivitiesList;
  if ( m_pActivitiesList != nullptr && Ptr == m_pActivitiesList )
  {
    v10 = CSequencePicker::GetSelectedSequenceName(this);
    v11 = v10;
    if ( v10 != nullptr )
    {
      CSequencePicker::PlayActivity(this, pActivityName: v10);
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
      {
        v13 = KeyValues::KeyValues(this: v12, setName: "SequencePreviewChanged", firstKey: "activity", firstValue: v11);
        this->PostActionSignal(this, a2: v13);
        return;
      }
      goto LABEL_11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CC6A0
// Name: private: virtual void CSequencePicker::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnTextChanged(CSequencePicker *this, KeyValues *pData)
{
  vgui::ComboBox *Ptr; // eax
  signed int v4; // edi
  vgui::ComboBox **m_pLayerSequenceSelectors; // ecx
  int v6; // edi
  vgui::ComboBox **i; // ecx
  char *String; // eax
  int Sequence; // eax
  int v10; // edi
  KeyValues *ActiveItemUserData; // eax
  unsigned int Int; // eax

  Ptr = (vgui::ComboBox *)KeyValues::GetPtr(this: pData, keyName: "panel", defaultValue: nullptr);
  v4 = 0;
  m_pLayerSequenceSelectors = this->m_pLayerSequenceSelectors;
  do
  {
    if ( Ptr == *m_pLayerSequenceSelectors )
    {
      String = KeyValues::GetString(this: pData, keyName: "text", defaultValue: &var);
      Sequence = CSequencePicker::FindSequence(this, pSequenceName: String);
      if ( v4 != 0 )
      {
        CSequencePicker::SetSequenceLayer(
          this,
          a2: (int)this,
          nLayerIndex: v4,
          nSequenceIndex: Sequence,
          flWeight: this->m_SequenceLayers[v4].m_flWeight);
      }
      else
      {
        v10 = Sequence;
        if ( Sequence >= 0 )
        {
          if ( this->m_bSequenceParams )
          {
            CSequencePicker::SetSequenceLayer(
              this,
              a2: (int)this,
              nLayerIndex: 0,
              nSequenceIndex: Sequence,
              flWeight: 1.0);
            CSequencePicker::UpdateAvailablePoseParmeters(this, a2: (int)this);
          }
          CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: v10);
        }
      }
      return;
    }
    ++v4;
    ++m_pLayerSequenceSelectors;
  }
  while ( v4 < 4 );
  v6 = 0;
  for ( i = this->m_pPoseParameterName; Ptr != *i; ++i )
  {
    if ( ++v6 >= 6 )
      return;
  }
  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pPoseParameterName[v6]);
  Int = KeyValues::GetInt(this: ActiveItemUserData, keyName: "paramIndex", defaultValue: -1);
  if ( Int <= 0x17 )
  {
    this->m_PoseControlMap[v6] = Int;
    CSequencePicker::SetPoseParameterValue(
      this,
      flPoseParameterValue: this->m_PoseParameters[Int],
      nParameterIndex: Int);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CC7C0
// Name: private: void CSequencePicker::RefreshActivitiesAndSequencesList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::RefreshActivitiesAndSequencesList(CSequencePicker *this)
{
  CSequencePicker *v1; // ebx
  bool v2; // zf
  vgui::ComboBox **m_pLayerSequenceSelectors; // esi
  int k; // edi
  IMDLCache *v5; // eax
  studiohdr_t *v6; // eax
  studiohdr_t *v7; // esi
  int NumSeq_Internal; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v9; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  studiohdr_t *v14; // esi
  int v15; // ebx
  int v16; // eax
  mstudioseqdesc_t *v17; // eax
  char *v18; // edi
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  int v21; // ebx
  KeyValues *v22; // eax
  KeyValues *v23; // esi
  IMDLCache *v24; // eax
  char *v25; // eax
  int v26; // eax
  mstudioseqdesc_t *v27; // eax
  int v28; // edi
  char *v29; // esi
  KeyValues *v30; // eax
  KeyValues *v31; // eax
  int v32; // ebx
  KeyValues *v33; // eax
  KeyValues *v34; // esi
  IMDLCache *v35; // eax
  char *v36; // eax
  int numlocalseq; // ebx
  int v38; // edi
  int v39; // eax
  mstudioseqdesc_t *v40; // ebx
  int m_Size; // esi
  mstudioseqdesc_t **v42; // esi
  vgui::ComboBox **v43; // esi
  int m; // edi
  char *v45; // esi
  vgui::ComboBox **v46; // edi
  int n; // ebx
  KeyValues *v48; // eax
  KeyValues *v49; // eax
  CUtlDict<int,unsigned short> activityNames; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<mstudioseqdesc_t *,CUtlMemory<mstudioseqdesc_t *,int> > sequenceList; // [esp+28h] [ebp-2Ch] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+3Ch] [ebp-18h] BYREF
  vgui::ComboBox **v53; // [esp+44h] [ebp-10h]
  int i; // [esp+48h] [ebp-Ch]
  int nNumSequences; // [esp+4Ch] [ebp-8h]
  int j; // [esp+50h] [ebp-4h] BYREF

  v1 = this;
  v2 = this->m_pActivitiesList == nullptr;
  nNumSequences = (int)this;
  if ( !v2 )
    this->m_pActivitiesList->RemoveAll(this: this->m_pActivitiesList);
  if ( v1->m_pSequencesList != nullptr )
    v1->m_pSequencesList->RemoveAll(this: v1->m_pSequencesList);
  m_pLayerSequenceSelectors = v1->m_pLayerSequenceSelectors;
  v53 = v1->m_pLayerSequenceSelectors;
  for ( k = 4; k != 0; --k )
  {
    if ( *m_pLayerSequenceSelectors != nullptr )
      vgui::ComboBox::RemoveAll(this: *m_pLayerSequenceSelectors);
    ++m_pLayerSequenceSelectors;
  }
  CMDLPanel::SetSequence(this: v1->m_pMDLPreview, nSequence: 0);
  if ( v1->m_hSelectedMDL != 0xFFFF )
  {
    v5 = vgui::MDLCache();
    v6 = v5->GetStudioHdr(this: v5, a2: v1->m_hSelectedMDL);
    v7 = v6;
    i = (int)v6;
    if ( v6->numincludemodels != 0 )
      NumSeq_Internal = studiohdr_t::GetNumSeq_Internal(this: v6);
    else
      NumSeq_Internal = v6->numlocalseq;
    v9 = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = NumSeq_Internal;
    activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    if ( NumSeq_Internal != 0 )
    {
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 16 * NumSeq_Internal);
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v9;
    }
    v10 = 0;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_FirstFree = -1;
    activityNames.m_Elements.m_Tree.m_pElements = v9;
    activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    for ( j = 0; ; v10 = j )
    {
      v11 = v7->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v7) : v7->numlocalseq;
      if ( v10 >= v11 )
        break;
      if ( v7->numincludemodels != 0 )
      {
        v13 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v10);
      }
      else
      {
        v12 = v10;
        if ( v10 < 0 || v10 >= v7->numlocalseq )
          v12 = 0;
        v13 = (mstudioseqdesc_t *)((char *)v7 + 212 * v12 + v7->localseqindex);
      }
      if ( (v13->flags & 0x400) == 0 )
      {
        v14 = (studiohdr_t *)i;
        v15 = j;
        if ( *(_DWORD *)(i + 336) != 0 )
        {
          v17 = studiohdr_t::pSeqdesc_Internal(this: (studiohdr_t *)i, i: j);
        }
        else
        {
          v16 = j;
          if ( j < 0 || j >= *(_DWORD *)(i + 188) )
            v16 = 0;
          v17 = (mstudioseqdesc_t *)(i + *(_DWORD *)(i + 192) + 212 * v16);
        }
        v18 = (char *)v17 + v17->szactivitynameindex;
        if ( *(_DWORD *)(nNumSequences + 416) != 0 && v18 != nullptr && *v18 != 0 )
        {
          search.key = (char *)v17 + v17->szactivitynameindex;
          if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                 this: &activityNames.m_Elements.m_Tree,
                 &search) == 0xFFFF )
          {
            v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v19 != nullptr )
              v20 = KeyValues::KeyValues(this: v19, setName: "node", firstKey: "activity", firstValue: v18);
            else
              v20 = nullptr;
            v21 = (*(int (__thiscall **)(_DWORD, KeyValues *, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(nNumSequences + 416)
                                                                                     + 916))(
                    a1: *(_DWORD *)(nNumSequences + 416),
                    a2: v20,
                    a3: 0,
                    a4: 0,
                    a5: 0);
            v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v22 != nullptr )
              v23 = KeyValues::KeyValues(this: v22, setName: "drag", firstKey: "text", firstValue: v18);
            else
              v23 = nullptr;
            KeyValues::SetString(this: v23, keyName: "texttype", value: "activityName");
            v24 = vgui::MDLCache();
            v25 = (char *)v24->GetModelName(this: v24, a2: *(_WORD *)(nNumSequences + 686));
            KeyValues::SetString(this: v23, keyName: "mdl", value: v25);
            vgui::ListPanel::SetItemDragData(this: *(vgui::ListPanel **)(nNumSequences + 416), itemID: v21, data: v23);
            CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v18, element: &j);
            v14 = (studiohdr_t *)i;
            v15 = j;
          }
        }
        if ( v14->numincludemodels != 0 )
        {
          v27 = studiohdr_t::pSeqdesc_Internal(this: v14, i: v15);
        }
        else
        {
          v26 = v15;
          if ( v15 < 0 || v15 >= v14->numlocalseq )
            v26 = 0;
          v27 = (mstudioseqdesc_t *)((char *)v14 + 212 * v26 + v14->localseqindex);
        }
        v28 = nNumSequences;
        v29 = (char *)v27 + v27->szlabelindex;
        if ( *(_DWORD *)(nNumSequences + 412) != 0 && v29 != nullptr && *v29 != 0 )
        {
          v30 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v30 != nullptr )
            v31 = KeyValues::KeyValues(this: v30, setName: "node", firstKey: "sequence", firstValue: v29);
          else
            v31 = nullptr;
          v32 = (*(int (__thiscall **)(_DWORD, KeyValues *, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(v28 + 412) + 916))(
                  a1: *(_DWORD *)(v28 + 412),
                  a2: v31,
                  a3: 0,
                  a4: 0,
                  a5: 0);
          v33 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v33 != nullptr )
            v34 = KeyValues::KeyValues(this: v33, setName: "drag", firstKey: "text", firstValue: v29);
          else
            v34 = nullptr;
          KeyValues::SetString(this: v34, keyName: "texttype", value: "sequenceName");
          v35 = vgui::MDLCache();
          v36 = (char *)v35->GetModelName(this: v35, a2: *(_WORD *)(v28 + 686));
          KeyValues::SetString(this: v34, keyName: "mdl", value: v36);
          vgui::ListPanel::SetItemDragData(this: *(vgui::ListPanel **)(v28 + 412), itemID: v32, data: v34);
        }
      }
      ++j;
      v1 = (CSequencePicker *)nNumSequences;
      v7 = (studiohdr_t *)i;
    }
    if ( v1->m_pSequencesList != nullptr )
      v1->m_pSequencesList->SortList(this: v1->m_pSequencesList);
    if ( v1->m_pActivitiesList != nullptr )
      v1->m_pActivitiesList->SortList(this: v1->m_pActivitiesList);
    if ( v1->m_bSequenceParams )
    {
      if ( v7->numincludemodels != 0 )
      {
        nNumSequences = studiohdr_t::GetNumSeq_Internal(this: v7);
        numlocalseq = nNumSequences;
      }
      else
      {
        numlocalseq = v7->numlocalseq;
        nNumSequences = numlocalseq;
      }
      sequenceList.m_Memory.m_pMemory = nullptr;
      sequenceList.m_Memory.m_nAllocationCount = numlocalseq;
      sequenceList.m_Memory.m_nGrowSize = 0;
      if ( numlocalseq != 0 )
        sequenceList.m_Memory.m_pMemory = (mstudioseqdesc_t **)_g_pMemAlloc->Alloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: 4 * numlocalseq);
      v38 = 0;
      sequenceList.m_Size = 0;
      sequenceList.m_pElements = sequenceList.m_Memory.m_pMemory;
      if ( numlocalseq > 0 )
      {
        while ( 1 )
        {
          if ( v7->numincludemodels != 0 )
          {
            v40 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v38);
          }
          else
          {
            v39 = v38;
            if ( v38 < 0 || v38 >= v7->numlocalseq )
              v39 = 0;
            v40 = (mstudioseqdesc_t *)((char *)v7 + 212 * v39 + v7->localseqindex);
          }
          if ( (v40->flags & 0x400) == 0 )
          {
            m_Size = sequenceList.m_Size;
            if ( sequenceList.m_Size + 1 > sequenceList.m_Memory.m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&sequenceList,
                num: sequenceList.m_Size - sequenceList.m_Memory.m_nAllocationCount + 1);
            ++sequenceList.m_Size;
            sequenceList.m_pElements = sequenceList.m_Memory.m_pMemory;
            if ( sequenceList.m_Size - m_Size - 1 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&sequenceList.m_Memory.m_pMemory[m_Size + 1],
                src: (unsigned __int8 *)&sequenceList.m_Memory.m_pMemory[m_Size],
                count: 4 * (sequenceList.m_Size - m_Size - 1));
            v42 = &sequenceList.m_Memory.m_pMemory[m_Size];
            if ( v42 != nullptr )
              *v42 = v40;
          }
          if ( ++v38 >= nNumSequences )
            break;
          v7 = (studiohdr_t *)i;
        }
      }
      CUtlVector<mstudioseqdesc_t *,CUtlMemory<mstudioseqdesc_t *,int>>::Sort(
        this: (CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *)&sequenceList,
        pfnCompare: (int (__cdecl *)(vgui::CConsolePanel::CompletionItem *const *, vgui::CConsolePanel::CompletionItem *const *))CompareSequenceDesc);
      v43 = v53;
      for ( m = 4; m != 0; --m )
      {
        if ( *v43 != nullptr )
          vgui::ComboBox::RemoveAll(this: *v43);
        ++v43;
      }
      for ( i = 0; i < sequenceList.m_Size; ++i )
      {
        v45 = (char *)sequenceList.m_Memory.m_pMemory[i] + sequenceList.m_Memory.m_pMemory[i]->szlabelindex;
        if ( v45 != nullptr )
        {
          v46 = v53;
          for ( n = 4; n != 0; --n )
          {
            if ( *v46 != nullptr )
            {
              v48 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v48 != nullptr )
                v49 = KeyValues::KeyValues(this: v48, setName: "sequenceItem", firstKey: "sequence", firstValue: v45);
              else
                v49 = nullptr;
              (*v46)->AddItem_2(this: *v46, a2: v45, a3: v49);
            }
            ++v46;
          }
        }
      }
      if ( sequenceList.m_Memory.m_nGrowSize >= 0 && sequenceList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sequenceList.m_Memory.m_pMemory);
    }
    CUtlDict<int,unsigned short>::RemoveAll(this: &activityNames);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &activityNames.m_Elements.m_Tree);
    if ( activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && activityNames.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: activityNames.m_Elements.m_Tree.m_Elements.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CCDA0
// Name: public: void CSequencePicker::SetMDL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::SetMDL(CSequencePicker *this, const char *pMDLName)
{
  IMDLCache *v3; // eax
  unsigned __int16 v4; // ax
  IMDLCache *v5; // eax

  if ( pMDLName != nullptr )
  {
    v3 = vgui::MDLCache();
    v4 = v3->FindMDL(this: v3, a2: pMDLName);
  }
  else
  {
    v4 = -1;
  }
  this->m_hSelectedMDL = v4;
  v5 = vgui::MDLCache();
  if ( v5->IsErrorModel(this: v5, a2: this->m_hSelectedMDL) )
    this->m_hSelectedMDL = -1;
  this->m_pMDLPreview->SetMDL_2(this: this->m_pMDLPreview, a2: this->m_hSelectedMDL, a3: nullptr);
  CMDLPanel::LookAtMDL(this: this->m_pMDLPreview);
  CSequencePicker::ResetLayers(this);
  CSequencePicker::RefreshActivitiesAndSequencesList(this);
  CSequencePicker::UpdateLayerControls(this);
  CSequencePicker::UpdatePoseParameterControlsForMdl(this);
}

//------------------------------------------------------------------------------
// Address: 0x104CCE40
// Name: public: void CSequencePickerFrame::DoModal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePickerFrame::DoModal(CSequencePickerFrame *this, const char *pMDLName)
{
  CSequencePicker::SetMDL(this: this->m_pPicker, pMDLName);
  vgui::Frame::DoModal(this);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004D1140
// Name: public: static char const __near * CSequencePicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSequencePicker::GetPanelClassName()
{
  return "CSequencePicker";
}

//------------------------------------------------------------------------------
// Address: 0x004D1150
// Name: public: static char const __near * CSequencePickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSequencePickerFrame::GetPanelClassName()
{
  return "CSequencePickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004D1160
// Name: SequenceSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SequenceSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "sequence", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "sequence", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004D11A0
// Name: ActivitySortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ActivitySortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "activity", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "activity", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004D11E0
// Name: public: virtual void CSequencePicker::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::PerformLayout(CSequencePicker *this)
{
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pPreviewSplitter, x: 0, y: 0, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x004D1220
// Name: int CompareSequenceDesc(struct mstudioseqdesc_t __near * const __near *,struct mstudioseqdesc_t __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompareSequenceDesc(mstudioseqdesc_t *const *pDescA, mstudioseqdesc_t *const *pDescB)
{
  int v2; // edx
  const char *v3; // eax

  if ( pDescA != nullptr
    && pDescB != nullptr
    && *pDescA != nullptr
    && (v2 = (int)*pDescB, *pDescB != nullptr)
    && (v3 = (char *)*pDescA + (*pDescA)->szlabelindex) != nullptr
    && v2 + *(_DWORD *)(v2 + 4) != 0 )
  {
    return _V_stricmp(s1: v3, s2: (const char *)(v2 + *(_DWORD *)(v2 + 4)));
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D1260
// Name: public: enum CSequencePicker::PickType_t CSequencePicker::GetSelectedSequenceType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSequencePicker::GetSelectedSequenceType(CSequencePicker *this)
{
  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    return 1;
  }
  if ( this->m_pActivitiesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    return 2;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D12C0
// Name: private: void CSequencePicker::PlayActivity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::PlayActivity(CSequencePicker *this, const char *pActivityName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szactivitynameindex, s2: pActivityName) == 0 )
    {
      CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: i);
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D1360
// Name: private: int CSequencePicker::FindSequence(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSequencePicker::FindSequence(CSequencePicker *this, const char *pSequenceName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szlabelindex, s2: pSequenceName) == 0 )
      return i;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004D1410
// Name: private: virtual void CSequencePickerFrame::OnSequencePreviewChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePickerFrame::OnSequencePreviewChanged(CSequencePickerFrame *this, KeyValues *pKeyValues)
{
  const char *String; // edi
  int v4; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "sequence", defaultValue: nullptr);
  v4 = (int)KeyValues::GetString(this: pKeyValues, keyName: "activity", defaultValue: nullptr);
  if ( String != nullptr || v4 != 0 )
    v4 = 1;
  else
    LOBYTE(v4) = 0;
  this->m_pOpenButton->SetEnabled(this: this->m_pOpenButton, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004D14F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSequencePicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSequencePicker::GetMessageMap(CSequencePicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSequencePicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSequencePicker::GetMessageMap'::`2'::s_pMap;
  `CSequencePicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
  `CSequencePicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D1520
// Name: public: virtual struct PanelAnimationMap __near * CSequencePicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSequencePicker::GetAnimMap(CSequencePicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CSequencePicker");
}

//------------------------------------------------------------------------------
// Address: 0x004D1530
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSequencePicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSequencePicker::GetKBMap(CSequencePicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSequencePicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSequencePicker::GetKBMap'::`2'::s_pMap;
  `CSequencePicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSequencePicker");
  `CSequencePicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D15D0
// Name: public: static void CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D1660
// Name: public: static void CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextKillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D16F0
// Name: public: static void CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextNewLine";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D1780
// Name: public: static void CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D1810
// Name: public: static void CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D18A0
// Name: public: static void CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D1930
// Name: public: static void CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar'::`2'::bAdded )
  {
    `CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSequencePickerFrame");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SequencePreviewChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D19C0
// Name: public: CSequencePicker::CSequencePicker(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSequencePicker *__thiscall CSequencePicker::CSequencePicker(CSequencePicker *this, vgui::Panel *pParent, char nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // ebx
  CMDLPanel *v10; // eax
  CMDLPanel *v11; // eax
  vgui::PropertySheet *v12; // eax
  vgui::PropertySheet *v13; // eax
  vgui::PropertyPage *v14; // eax
  vgui::PropertyPage *v15; // eax
  vgui::PropertySheet *m_pViewsSheet; // ecx
  int v17; // ebx
  vgui::Slider **m_pLayerSequenceSliders; // edi
  vgui::ComboBox *v19; // eax
  vgui::ComboBox *v20; // eax
  int v21; // eax
  vgui::Slider *v22; // eax
  vgui::Slider *v23; // eax
  int v24; // ebx
  vgui::TextEntry **m_pPoseValueEntries; // edi
  vgui::Slider *v26; // eax
  vgui::Slider *v27; // eax
  vgui::TextEntry *v28; // eax
  vgui::TextEntry *v29; // eax
  vgui::ComboBox *v30; // eax
  vgui::ComboBox *v31; // eax
  vgui::Button *v32; // eax
  vgui::Button *v33; // eax
  vgui::CheckButton *v34; // eax
  vgui::CheckButton *v35; // eax
  vgui::ListPanel *v36; // eax
  vgui::ListPanel *v37; // eax
  vgui::PropertyPage *v38; // eax
  vgui::PropertyPage *v39; // eax
  vgui::PropertySheet *v40; // ecx
  vgui::ListPanel *v41; // eax
  vgui::ListPanel *v42; // eax
  char controlName[64]; // [esp+Ch] [ebp-40h] BYREF
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF
  vgui::Panel *i; // [esp+54h] [ebp+8h]
  int ia; // [esp+54h] [ebp+8h]
  int ib; // [esp+54h] [ebp+8h]

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "SequencePicker");
  this->__vftable = (CSequencePicker_vtbl *)&CSequencePicker::`vftable';
  if ( `CSequencePicker::ChainToMap'::`2'::chained == 0 )
  {
    `CSequencePicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSequencePicker");
    v4->pfnClassName = CSequencePicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CSequencePicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSequencePicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSequencePicker");
    v5->pfnClassName = CSequencePicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CSequencePicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSequencePicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSequencePicker");
    v6->pfnClassName = CSequencePicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CSequencePicker::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnTextKillFocus::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnTextNewLine::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CSequencePicker::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_Filter);
  this->m_bSequenceParams = (nFlags & 0x11) == 17;
  this->m_hSelectedMDL = -1;
  this->m_pRootMotionCheckBox = nullptr;
  this->m_pPoseDefaultButton = nullptr;
  _V_memset(dest: this->m_pLayerSequenceSelectors, fill: 0, count: 16);
  _V_memset(dest: this->m_pLayerSequenceSliders, fill: 0, count: 16);
  _V_memset(dest: this->m_pPoseValueSliders, fill: 0, count: 24);
  _V_memset(dest: this->m_pPoseValueEntries, fill: 0, count: 24);
  _V_memset(dest: this->m_pPoseParameterName, fill: 0, count: 24);
  _V_memset(dest: this->m_SequenceLayers, fill: 0, count: 32);
  _V_memset(dest: this->m_PoseControlMap, fill: -1, count: 24);
  _V_memset(dest: this->m_PoseParameters, fill: 0, count: 96);
  v7 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "PreviewSplitter",
           mode: SPLITTER_MODE_HORIZONTAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pPreviewSplitter = v8;
  Child = vgui::Panel::GetChild(this: v8, index: 0);
  i = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v10 = (CMDLPanel *)MemAlloc_Alloc(nSize: 0xBE4u);
  if ( v10 != nullptr )
    v11 = CMDLPanel::CMDLPanel(this: v10, pParent: Child, pName: "MDLPreview");
  else
    v11 = nullptr;
  this->m_pMDLPreview = v11;
  vgui::Panel::SetSkipChildDuringPainting(this, child: v11);
  v12 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v12 != nullptr )
    v13 = vgui::PropertySheet::PropertySheet(this: v12, parent: i, panelName: "ViewsSheet", draggableTabs: false);
  else
    v13 = nullptr;
  this->m_pViewsSheet = v13;
  v13->AddActionSignalTarget_2(this: v13, a2: this);
  this->m_pSequencesPage = nullptr;
  this->m_pSequencesList = nullptr;
  if ( (nFlags & 1) != 0 )
  {
    v14 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v14 != nullptr )
      v15 = vgui::PropertyPage::PropertyPage(this: v14, parent: this->m_pViewsSheet, panelName: "SequencesPage");
    else
      v15 = nullptr;
    m_pViewsSheet = this->m_pViewsSheet;
    this->m_pSequencesPage = v15;
    m_pViewsSheet->AddPage(this: m_pViewsSheet, a2: v15, a3: "Sequences", a4: nullptr, a5: false, a6: -1);
    if ( this->m_bSequenceParams )
    {
      ia = 0;
      v17 = 10;
      m_pLayerSequenceSliders = this->m_pLayerSequenceSliders;
      do
      {
        V_snprintf(pDest: controlName, maxLen: 64, pFormat: "LayerSequence%i", ia);
        v19 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
        if ( v19 != nullptr )
          v20 = vgui::ComboBox::ComboBox(
                  this: v19,
                  parent: this->m_pSequencesPage,
                  panelName: controlName,
                  numLines: 32,
                  allowEdit: false);
        else
          v20 = nullptr;
        *(m_pLayerSequenceSliders - 4) = (vgui::Slider *)v20;
        vgui::Panel::SetAutoResize(
          this: v20,
          pinCorner: PIN_TOPLEFT,
          resizeDir: AUTORESIZE_NO,
          nPinOffsetX: 10,
          nPinOffsetY: v17,
          nUnpinnedCornerOffsetX: 0,
          nUnpinnedCornerOffsetY: 0);
        vgui::Panel::SetWide(this: *(m_pLayerSequenceSliders - 4), wide: 180);
        (*(m_pLayerSequenceSliders - 4))->AddActionSignalTarget_2(this: *(m_pLayerSequenceSliders - 4), a2: this);
        v21 = ia;
        if ( ia > 0 )
        {
          v17 += 24;
          V_snprintf(pDest: controlName, maxLen: 64, pFormat: "LayerSequenceWeight%i", ia);
          v22 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
          if ( v22 != nullptr )
            v23 = vgui::Slider::Slider(this: v22, parent: this->m_pSequencesPage, panelName: controlName);
          else
            v23 = nullptr;
          *m_pLayerSequenceSliders = v23;
          vgui::Panel::SetAutoResize(
            this: v23,
            pinCorner: PIN_TOPLEFT,
            resizeDir: AUTORESIZE_NO,
            nPinOffsetX: 10,
            nPinOffsetY: v17,
            nUnpinnedCornerOffsetX: 0,
            nUnpinnedCornerOffsetY: 0);
          vgui::Panel::SetWide(this: *m_pLayerSequenceSliders, wide: 180);
          (*m_pLayerSequenceSliders)->SetRange(this: *m_pLayerSequenceSliders, a2: 0, a3: 100);
          (*m_pLayerSequenceSliders)->AddActionSignalTarget_2(this: *m_pLayerSequenceSliders, a2: this);
          v21 = ia;
        }
        v17 += 40;
        ++m_pLayerSequenceSliders;
        ia = v21 + 1;
      }
      while ( v21 + 1 < 4 );
      ib = 10;
      v24 = 0;
      m_pPoseValueEntries = this->m_pPoseValueEntries;
      do
      {
        V_snprintf(pDest: controlName, maxLen: 64, pFormat: "PoseValueSlider%i", v24);
        v26 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
        if ( v26 != nullptr )
          v27 = vgui::Slider::Slider(this: v26, parent: this->m_pSequencesPage, panelName: controlName);
        else
          v27 = nullptr;
        *(m_pPoseValueEntries - 6) = (vgui::TextEntry *)v27;
        vgui::Panel::SetAutoResize(
          this: v27,
          pinCorner: PIN_TOPLEFT,
          resizeDir: AUTORESIZE_NO,
          nPinOffsetX: 210,
          nPinOffsetY: ib,
          nUnpinnedCornerOffsetX: 0,
          nUnpinnedCornerOffsetY: 0);
        vgui::Panel::SetWide(this: *(m_pPoseValueEntries - 6), wide: 120);
        (*(m_pPoseValueEntries - 6))->GetText(this: *(m_pPoseValueEntries - 6), a2: nullptr, a3: 100);
        (*(m_pPoseValueEntries - 6))->AddActionSignalTarget_2(this: *(m_pPoseValueEntries - 6), a2: this);
        V_snprintf(pDest: controlName, maxLen: 64, pFormat: "PoseValueEntry%i", v24);
        v28 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
        if ( v28 != nullptr )
          v29 = vgui::TextEntry::TextEntry(this: v28, parent: this->m_pSequencesPage, panelName: controlName);
        else
          v29 = nullptr;
        *m_pPoseValueEntries = v29;
        vgui::Panel::SetAutoResize(
          this: v29,
          pinCorner: PIN_TOPLEFT,
          resizeDir: AUTORESIZE_NO,
          nPinOffsetX: 330,
          nPinOffsetY: ib,
          nUnpinnedCornerOffsetX: 0,
          nUnpinnedCornerOffsetY: 0);
        vgui::Panel::SetWide(this: *m_pPoseValueEntries, wide: 40);
        (*m_pPoseValueEntries)->SendNewLine(this: *m_pPoseValueEntries, a2: true);
        (*m_pPoseValueEntries)->AddActionSignalTarget_2(this: *m_pPoseValueEntries, a2: this);
        V_snprintf(pDest: controlName, maxLen: 64, pFormat: "PoseParameterName%i", v24);
        v30 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
        if ( v30 != nullptr )
          v31 = vgui::ComboBox::ComboBox(
                  this: v30,
                  parent: this->m_pSequencesPage,
                  panelName: controlName,
                  numLines: 8,
                  allowEdit: false);
        else
          v31 = nullptr;
        m_pPoseValueEntries[6] = v31;
        vgui::Panel::SetAutoResize(
          this: v31,
          pinCorner: PIN_TOPLEFT,
          resizeDir: AUTORESIZE_NO,
          nPinOffsetX: 380,
          nPinOffsetY: ib,
          nUnpinnedCornerOffsetX: 0,
          nUnpinnedCornerOffsetY: 0);
        vgui::Panel::SetWide(this: m_pPoseValueEntries[6], wide: 120);
        m_pPoseValueEntries[6]->AddActionSignalTarget_2(this: m_pPoseValueEntries[6], a2: this);
        ib += 32;
        ++v24;
        ++m_pPoseValueEntries;
      }
      while ( v24 < 6 );
      v32 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
      if ( v32 != nullptr )
        v33 = vgui::Button::Button(
                this: v32,
                parent: this->m_pSequencesPage,
                panelName: "DefaultsButton",
                text: "#SequencePicker_Defaults",
                pActionSignalTarget: this,
                pCmd: "ResetToDefaults");
      else
        v33 = nullptr;
      this->m_pPoseDefaultButton = v33;
      v33->SetContentAlignment(this: v33, a2: a_center);
      vgui::Panel::SetWide(this: this->m_pPoseDefaultButton, wide: 100);
      vgui::Panel::SetAutoResize(
        this: this->m_pPoseDefaultButton,
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_NO,
        nPinOffsetX: 210,
        nPinOffsetY: ib,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
      this->m_pPoseDefaultButton->SetEnabled(this: this->m_pPoseDefaultButton, a2: false);
      v34 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
      if ( v34 != nullptr )
        v35 = vgui::CheckButton::CheckButton(
                this: v34,
                parent: this->m_pSequencesPage,
                panelName: "RootMotionCheckBox",
                text: "#SequencePicker_RootMotion");
      else
        v35 = nullptr;
      this->m_pRootMotionCheckBox = v35;
      vgui::Panel::SetAutoResize(
        this: v35,
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_NO,
        nPinOffsetX: 324,
        nPinOffsetY: ib,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
      vgui::Panel::SetWide(this: this->m_pRootMotionCheckBox, wide: 150);
      this->m_pRootMotionCheckBox->SetSelected(this: this->m_pRootMotionCheckBox, a2: true);
    }
    else
    {
      v36 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
      if ( v36 != nullptr )
        v37 = vgui::ListPanel::ListPanel(this: v36, parent: this->m_pSequencesPage, panelName: "SequencesList");
      else
        v37 = nullptr;
      this->m_pSequencesList = v37;
      v37->AddColumnHeader(this: v37, a2: 0, a3: "sequence", a4: "sequence", a5: 52, a6: 0);
      this->m_pSequencesList->AddActionSignalTarget_2(this: this->m_pSequencesList, a2: this);
      this->m_pSequencesList->SetSelectIndividualCells(this: this->m_pSequencesList, a2: true);
      this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: ".MDL file contains no activities");
      this->m_pSequencesList->SetDragEnabled(this: this->m_pSequencesList, a2: true);
      vgui::Panel::SetAutoResize(
        this: this->m_pSequencesList,
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_DOWNANDRIGHT,
        nPinOffsetX: 0,
        nPinOffsetY: 0,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
      this->m_pSequencesList->SetSortFunc(this: this->m_pSequencesList, a2: 0, a3: SequenceSortFunc);
      this->m_pSequencesList->SetSortColumn(this: this->m_pSequencesList, a2: 0);
    }
  }
  this->m_pActivitiesPage = nullptr;
  this->m_pActivitiesList = nullptr;
  if ( (nFlags & 2) != 0 )
  {
    v38 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v38 != nullptr )
      v39 = vgui::PropertyPage::PropertyPage(this: v38, parent: this->m_pViewsSheet, panelName: "ActivitiesPage");
    else
      v39 = nullptr;
    v40 = this->m_pViewsSheet;
    this->m_pActivitiesPage = v39;
    v40->AddPage(this: v40, a2: v39, a3: "Activities", a4: nullptr, a5: false, a6: -1);
    v41 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
    if ( v41 != nullptr )
      v42 = vgui::ListPanel::ListPanel(this: v41, parent: this->m_pActivitiesPage, panelName: "ActivitiesList");
    else
      v42 = nullptr;
    this->m_pActivitiesList = v42;
    v42->AddColumnHeader(this: v42, a2: 0, a3: "activity", a4: "activity", a5: 52, a6: 0);
    this->m_pActivitiesList->AddActionSignalTarget_2(this: this->m_pActivitiesList, a2: this);
    this->m_pActivitiesList->SetSelectIndividualCells(this: this->m_pActivitiesList, a2: true);
    this->m_pActivitiesList->SetEmptyListText_2(this: this->m_pActivitiesList, a2: ".MDL file contains no activities");
    this->m_pActivitiesList->SetDragEnabled(this: this->m_pActivitiesList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pActivitiesList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 0,
      nPinOffsetY: 0,
      nUnpinnedCornerOffsetX: 0,
      nUnpinnedCornerOffsetY: 0);
    this->m_pActivitiesList->SetSortFunc(this: this->m_pActivitiesList, a2: 0, a3: ActivitySortFunc);
    this->m_pActivitiesList->SetSortColumn(this: this->m_pActivitiesList, a2: 0);
  }
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/sequencepicker.res",
    dialogID: 0);
  vgui::Panel::MakeReadyForUse(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D2200
// Name: public: char const __near * CSequencePicker::GetSelectedSequenceName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSequencePicker::GetSelectedSequenceName(CSequencePicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  IMDLCache *v5; // eax
  const studiohdr_t *v6; // eax
  int m_nSequenceIndex; // esi
  int v8; // eax
  mstudioseqdesc_t *v9; // eax
  char *v10; // esi
  int v11; // eax
  KeyValues *v12; // eax
  CStudioHdr studioHdr; // [esp+4h] [ebp-64h] BYREF

  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    if ( this->m_pSequencesList != nullptr )
    {
      v2 = this->m_pSequencesList->GetSelectedItem(this: this->m_pSequencesList, a2: 0);
      if ( v2 >= 0 )
      {
        v3 = this->m_pSequencesList->GetItem(this: this->m_pSequencesList, a2: v2);
        return KeyValues::GetString(this: v3, keyName: "sequence", defaultValue: nullptr);
      }
    }
    else if ( this->m_bSequenceParams )
    {
      v5 = vgui::MDLCache();
      v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
      if ( v6 != nullptr )
      {
        CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v6, mdlcache: nullptr);
        m_nSequenceIndex = this->m_SequenceLayers[0].m_nSequenceIndex;
        if ( m_nSequenceIndex >= 0 )
        {
          v8 = studioHdr.m_pVModel != nullptr
             ? CStudioHdr::GetNumSeq_Internal(this: &studioHdr)
             : studioHdr.m_pStudioHdr->numlocalseq;
          if ( m_nSequenceIndex < v8 )
          {
            v9 = CStudioHdr::pSeqdesc(this: &studioHdr, iSequence: m_nSequenceIndex);
            v10 = (char *)v9 + v9->szlabelindex;
            CStudioHdr::~CStudioHdr(this: &studioHdr);
            return v10;
          }
        }
        CStudioHdr::~CStudioHdr(this: &studioHdr);
      }
    }
  }
  else if ( this->m_pActivitiesPage != nullptr
         && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    v11 = this->m_pActivitiesList->GetSelectedItem(this: this->m_pActivitiesList, a2: 0);
    if ( v11 >= 0 )
    {
      v12 = this->m_pActivitiesList->GetItem(this: this->m_pActivitiesList, a2: v11);
      return KeyValues::GetString(this: v12, keyName: "activity", defaultValue: nullptr);
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D2360
// Name: public: void CSequencePicker::GetPoseParameters(class CUtlVector<float,class CUtlMemory<float,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::GetPoseParameters(
        CSequencePicker *this,
        CUtlVector<float,CUtlMemory<float,int> > *poseParameters)
{
  IMDLCache *v3; // eax
  const studiohdr_t *v4; // eax
  int NumPoseParameters; // eax
  float *m_PoseParameters; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  float *m_pMemory; // ecx
  int v11; // eax
  float *v12; // eax
  int *v13; // eax
  int *v14; // eax
  const studiohdr_t **v15; // eax
  CStudioHdr studioHdr; // [esp+8h] [ebp-64h] BYREF
  CUtlVector<float,CUtlMemory<float,int> > *poseParametersa; // [esp+74h] [ebp+8h]

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v4, mdlcache: nullptr);
  NumPoseParameters = CStudioHdr::GetNumPoseParameters(this: &studioHdr);
  if ( NumPoseParameters > 0 )
  {
    m_PoseParameters = this->m_PoseParameters;
    for ( poseParametersa = (CUtlVector<float,CUtlMemory<float,int> > *)NumPoseParameters;
          poseParametersa != nullptr;
          poseParametersa = (CUtlVector<float,CUtlMemory<float,int> > *)((char *)poseParametersa - 1) )
    {
      m_Size = poseParameters->m_Size;
      m_nAllocationCount = poseParameters->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)poseParameters,
          num: m_Size - m_nAllocationCount + 1);
      ++poseParameters->m_Size;
      m_pMemory = poseParameters->m_Memory.m_pMemory;
      v11 = poseParameters->m_Size - m_Size - 1;
      poseParameters->m_pElements = poseParameters->m_Memory.m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
      v12 = &poseParameters->m_Memory.m_pMemory[m_Size];
      if ( v12 != nullptr )
        *v12 = *m_PoseParameters;
      ++m_PoseParameters;
    }
  }
  CStudioHdr::Term(this: &studioHdr);
  v13 = studioHdr.m_boneParent.m_Memory.m_pMemory;
  studioHdr.m_boneParent.m_Size = 0;
  if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneParent.m_Memory.m_pMemory);
      v13 = nullptr;
      studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_boneParent.m_pElements = v13;
  if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v13 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
      studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v14 = studioHdr.m_boneFlags.m_Memory.m_pMemory;
  studioHdr.m_boneFlags.m_Size = 0;
  if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneFlags.m_Memory.m_pMemory);
      v14 = nullptr;
      studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_boneFlags.m_pElements = v14;
  if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v14 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
      studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v15 = studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
  studioHdr.m_pStudioHdrCache.m_Size = 0;
  if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
      v15 = nullptr;
      studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_pStudioHdrCache.m_pElements = v15;
  if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
}

//------------------------------------------------------------------------------
// Address: 0x004D24F0
// Name: public: void CSequencePicker::GetSeqenceLayers(class CUtlVector<struct MDLSquenceLayer_t,class CUtlMemory<struct MDLSquenceLayer_t,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::GetSeqenceLayers(
        CSequencePicker *this,
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *sequenceLayers)
{
  MDLSquenceLayer_t *v2; // esi
  int i; // edi

  v2 = &this->m_SequenceLayers[1];
  for ( i = 3; i != 0; --i )
  {
    if ( v2->m_nSequenceIndex >= 0 && v2->m_flWeight > 0.0 )
      CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
        this: sequenceLayers,
        elem: sequenceLayers->m_Size,
        src: (const vgui::PropertySheet::Page_t *)v2);
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D2530
// Name: private: void CSequencePicker::SetPoseParameterValue(float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::SetPoseParameterValue(
        CSequencePicker *this,
        float flPoseParameterValue,
        unsigned int nParameterIndex)
{
  IMDLCache *v5; // eax
  const studiohdr_t *v6; // eax
  const mstudioposeparamdesc_t *v7; // edi
  vgui::Slider **m_pPoseValueSliders; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  CStudioHdr studioHdr; // [esp+20h] [ebp-84h] BYREF
  char valueText[32]; // [esp+84h] [ebp-20h] BYREF
  int nParameterIndexa; // [esp+B0h] [ebp+Ch]

  if ( nParameterIndex <= 0x17 )
  {
    v5 = vgui::MDLCache();
    v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v6, mdlcache: nullptr);
    v7 = CStudioHdr::pPoseParameter(this: &studioHdr, i: nParameterIndex);
    this->m_PoseParameters[nParameterIndex] = flPoseParameterValue;
    CMDLPanel::SetPoseParameters(this: this->m_pMDLPreview, pPoseParameters: this->m_PoseParameters, nCount: 24);
    m_pPoseValueSliders = this->m_pPoseValueSliders;
    for ( nParameterIndexa = 6; nParameterIndexa != 0; --nParameterIndexa )
    {
      if ( m_pPoseValueSliders[26] == (vgui::Slider *)nParameterIndex )
      {
        v9 = (float)(flPoseParameterValue * 2.0) - 1.0;
        if ( v9 < 0.0 )
          LODWORD(v10) = COERCE_UNSIGNED_INT(fsqrt(-v9)) ^ 0x80000000;
        else
          v10 = fsqrt(v9);
        (*m_pPoseValueSliders)->SetValue(
          this: *m_pPoseValueSliders,
          a2: (int)(float)((float)((float)((float)(v10 + 1.0) * 0.5) * 100.0) + 0.5),
          a3: false);
        V_snprintf(
          pDest: valueText,
          maxLen: 32,
          pFormat: "%0.2f",
          (float)((float)((float)(v7->end - v7->start) * flPoseParameterValue) + v7->start));
        ((void (__thiscall *)(vgui::Slider *, char *))m_pPoseValueSliders[6]->SetValue)(
          a1: m_pPoseValueSliders[6],
          a2: valueText);
      }
      ++m_pPoseValueSliders;
    }
    CStudioHdr::Term(this: &studioHdr);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_boneParent);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_boneFlags);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D26C0
// Name: private: void CSequencePicker::UpdatePoseControlsFromParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::UpdatePoseControlsFromParameters(CSequencePicker *this)
{
  IMDLCache *v2; // eax
  const studiohdr_t *v3; // eax
  signed int v4; // esi
  float *m_PoseParameters; // edi
  int *m_pMemory; // eax
  int *v7; // eax
  const studiohdr_t **v8; // eax
  CStudioHdr studioHdr; // [esp+18h] [ebp-68h] BYREF
  int nNumParams; // [esp+7Ch] [ebp-4h]

  v2 = vgui::MDLCache();
  v3 = v2->GetStudioHdr(this: v2, a2: this->m_hSelectedMDL);
  v4 = 0;
  CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v3, mdlcache: nullptr);
  nNumParams = CStudioHdr::GetNumPoseParameters(this: &studioHdr);
  if ( nNumParams > 0 )
  {
    m_PoseParameters = this->m_PoseParameters;
    do
      CSequencePicker::SetPoseParameterValue(this, flPoseParameterValue: *m_PoseParameters++, nParameterIndex: v4++);
    while ( v4 < nNumParams );
  }
  CStudioHdr::Term(this: &studioHdr);
  m_pMemory = studioHdr.m_boneParent.m_Memory.m_pMemory;
  studioHdr.m_boneParent.m_Size = 0;
  if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneParent.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_boneParent.m_pElements = m_pMemory;
  if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v7 = studioHdr.m_boneFlags.m_Memory.m_pMemory;
  studioHdr.m_boneFlags.m_Size = 0;
  if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneFlags.m_Memory.m_pMemory);
      v7 = nullptr;
      studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_boneFlags.m_pElements = v7;
  if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v8 = studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
  studioHdr.m_pStudioHdrCache.m_Size = 0;
  if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
      v8 = nullptr;
      studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    studioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  studioHdr.m_pStudioHdrCache.m_pElements = v8;
  if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v8 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x004D2810
// Name: private: virtual void CSequencePicker::OnTextKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnTextKillFocus(CSequencePicker *this, KeyValues *pData)
{
  vgui::TextEntry *Ptr; // eax
  int v4; // esi
  vgui::TextEntry **i; // ecx
  IMDLCache *v6; // eax
  const studiohdr_t *v7; // eax
  int v8; // esi
  const mstudioposeparamdesc_t *v9; // eax
  float start; // xmm0_4
  float end; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  int *m_pMemory; // eax
  int *v16; // eax
  const studiohdr_t **v17; // eax
  CStudioHdr studioHdr; // [esp+18h] [ebp-64h] BYREF
  float flValue; // [esp+84h] [ebp+8h]

  Ptr = (vgui::TextEntry *)KeyValues::GetPtr(this: pData, keyName: "panel", defaultValue: nullptr);
  v4 = 0;
  for ( i = this->m_pPoseValueEntries; Ptr != *i; ++i )
  {
    if ( ++v4 >= 6 )
      return;
  }
  if ( v4 >= 0 )
  {
    flValue = this->m_pPoseValueEntries[v4]->GetValueAsFloat(this: this->m_pPoseValueEntries[v4]);
    v6 = vgui::MDLCache();
    v7 = v6->GetStudioHdr(this: v6, a2: this->m_hSelectedMDL);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v7, mdlcache: nullptr);
    v8 = this->m_PoseControlMap[v4];
    v9 = CStudioHdr::pPoseParameter(this: &studioHdr, i: v8);
    start = v9->start;
    end = v9->end;
    if ( end <= start )
      v12 = v9->end;
    else
      v12 = v9->start;
    if ( start > end )
      end = v9->start;
    v13 = flValue;
    if ( v12 <= flValue )
      v14 = flValue;
    else
      v14 = v12;
    if ( v14 <= end )
    {
      if ( v12 > flValue )
        v13 = v12;
    }
    else
    {
      v13 = end;
    }
    CSequencePicker::SetPoseParameterValue(
      this,
      flPoseParameterValue: (float)(v13 - v12) / (float)(end - v12),
      nParameterIndex: v8);
    CStudioHdr::Term(this: &studioHdr);
    m_pMemory = studioHdr.m_boneParent.m_Memory.m_pMemory;
    studioHdr.m_boneParent.m_Size = 0;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneParent.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneParent.m_pElements = m_pMemory;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v16 = studioHdr.m_boneFlags.m_Memory.m_pMemory;
    studioHdr.m_boneFlags.m_Size = 0;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneFlags.m_Memory.m_pMemory);
        v16 = nullptr;
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneFlags.m_pElements = v16;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v16 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v17 = studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
    studioHdr.m_pStudioHdrCache.m_Size = 0;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
        v17 = nullptr;
        studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_pStudioHdrCache.m_pElements = v17;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v17 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D29E0
// Name: public: CSequencePickerFrame::CSequencePickerFrame(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSequencePickerFrame *__thiscall CSequencePickerFrame::CSequencePickerFrame(
        CSequencePickerFrame *this,
        vgui::Panel *pParent,
        char nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CSequencePicker *v7; // eax
  CSequencePicker *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: "SequencePickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CSequencePickerFrame_vtbl *)&CSequencePickerFrame::`vftable';
  if ( `CSequencePickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CSequencePickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSequencePickerFrame");
    v4->pfnClassName = CSequencePickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CSequencePickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSequencePickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSequencePickerFrame");
    v5->pfnClassName = CSequencePickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CSequencePickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSequencePickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSequencePickerFrame");
    v6->pfnClassName = CSequencePickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CSequencePickerFrame::PanelMessageFunc_OnSequencePreviewChanged::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CSequencePicker *)MemAlloc_Alloc(nSize: 0x2C0u);
  if ( v7 != nullptr )
    v8 = CSequencePicker::CSequencePicker(this: v7, pParent: this, nFlags);
  else
    v8 = nullptr;
  this->m_pPicker = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OpenButton",
            text: "#FileOpenDialog_Open",
            pActionSignalTarget: this,
            pCmd: "Open");
  else
    v10 = nullptr;
  this->m_pOpenButton = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/sequencepickerframe.res",
    dialogID: 0);
  this->m_pOpenButton->SetEnabled(this: this->m_pOpenButton, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D2B80
// Name: public: virtual struct vgui::PanelMessageMap __near * CSequencePickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSequencePickerFrame::GetMessageMap(CSequencePickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSequencePickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSequencePickerFrame::GetMessageMap'::`2'::s_pMap;
  `CSequencePickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSequencePickerFrame");
  `CSequencePickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D2BB0
// Name: public: virtual struct PanelAnimationMap __near * CSequencePickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSequencePickerFrame::GetAnimMap(CSequencePickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CSequencePickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004D2BC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSequencePickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSequencePickerFrame::GetKBMap(CSequencePickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSequencePickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSequencePickerFrame::GetKBMap'::`2'::s_pMap;
  `CSequencePickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSequencePickerFrame");
  `CSequencePickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D2BF0
// Name: public: virtual void CSequencePickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSequencePickerFrame::OnCommand(CSequencePickerFrame *this@<ecx>, int a2@<ebx>, const char *pCommand)
{
  CSequencePickerFrame *v3; // edi
  int SelectedSequenceType; // eax
  const char *SelectedSequenceName; // ebx
  int v6; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // ebx
  CSequencePicker *m_pPicker; // ecx
  KeyValues *v10; // eax
  KeyValues *v11; // edi
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  float *v13; // eax
  CSequencePicker *v14; // ecx
  int m_Size; // edi
  int i; // esi
  CSequencePickerFrame *v17; // esi
  CSequencePicker *v18; // eax
  bool v19; // al
  KeyValues *v20; // eax
  char poseParameterName[32]; // [esp+14h] [ebp-6Ch] BYREF
  char layerName[32]; // [esp+34h] [ebp-4Ch] BYREF
  CUtlVector<float,CUtlMemory<float,int> > poseParameters; // [esp+54h] [ebp-2Ch] BYREF
  CUtlVector<MDLSquenceLayer_t,CUtlMemory<MDLSquenceLayer_t,int> > sequenceLayers; // [esp+68h] [ebp-18h] BYREF
  CSequencePickerFrame *v26; // [esp+7Ch] [ebp-4h]
  CSequencePicker::PickType_t type; // [esp+88h] [ebp+8h]

  v3 = this;
  v26 = this;
  if ( _V_stricmp(s1: pCommand, s2: "Open") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this: v3, command: pCommand);
    else
      v3->CloseModal(this: v3);
  }
  else
  {
    SelectedSequenceType = CSequencePicker::GetSelectedSequenceType(this: v3->m_pPicker);
    type = SelectedSequenceType;
    if ( SelectedSequenceType == 1 || SelectedSequenceType == 2 )
    {
      SelectedSequenceName = CSequencePicker::GetSelectedSequenceName(this: v3->m_pPicker);
      v6 = 0;
      if ( SelectedSequenceName != nullptr )
      {
        v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( type == PICK_SEQUENCES )
        {
          if ( v7 != nullptr )
            v8 = KeyValues::KeyValues(
                   this: v7,
                   setName: "SequenceSelected",
                   firstKey: "sequence",
                   firstValue: SelectedSequenceName);
          else
            v8 = nullptr;
          m_pPicker = v3->m_pPicker;
          memset(&sequenceLayers, 0, sizeof(sequenceLayers));
          CSequencePicker::GetSeqenceLayers(
            this: m_pPicker,
            (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&sequenceLayers);
          KeyValues::SetInt(this: v8, keyName: "numLayers", value: sequenceLayers.m_Size);
          if ( sequenceLayers.m_Size > 0 )
          {
            do
            {
              V_snprintf(pDest: layerName, maxLen: 32, pFormat: "layer%i", v6);
              v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v10 != nullptr )
                v11 = KeyValues::KeyValues(this: v10, setName: layerName);
              else
                v11 = nullptr;
              KeyValues::SetInt(
                this: v11,
                keyName: "sequence",
                value: sequenceLayers.m_Memory.m_pMemory[v6].m_nSequenceIndex);
              KeyValues::SetFloat(this: v11, keyName: "weight", value: sequenceLayers.m_Memory.m_pMemory[v6].m_flWeight);
              KeyValues::AddSubKey(this: v8, pSubkey: v11);
              ++v6;
            }
            while ( v6 < sequenceLayers.m_Size );
            v3 = v26;
          }
          Alloc_2 = _g_pMemAlloc->Alloc_2;
          poseParameters.m_Memory.m_nAllocationCount = 24;
          poseParameters.m_Memory.m_nGrowSize = 0;
          v13 = (float *)((int (__thiscall *)(IMemAlloc *, int, int))Alloc_2)(a1: _g_pMemAlloc, a2: 96, a3: a2);
          v14 = v3->m_pPicker;
          poseParameters.m_Memory.m_pMemory = v13;
          poseParameters.m_pElements = v13;
          poseParameters.m_Size = 0;
          CSequencePicker::GetPoseParameters(this: v14, &poseParameters);
          m_Size = poseParameters.m_Size;
          KeyValues::SetInt(this: v8, keyName: "numPoseParameters", value: poseParameters.m_Size);
          for ( i = 0; i < m_Size; ++i )
          {
            V_snprintf(pDest: poseParameterName, maxLen: 32, pFormat: "poseParameter%i", i);
            KeyValues::SetFloat(this: v8, keyName: poseParameterName, value: poseParameters.m_Memory.m_pMemory[i]);
          }
          v17 = v26;
          v18 = v26->m_pPicker;
          v19 = v18->m_pRootMotionCheckBox != nullptr
             && v18->m_pRootMotionCheckBox->IsSelected(this: v18->m_pRootMotionCheckBox);
          KeyValues::SetInt(this: v8, keyName: "rootMotion", value: v19);
          ((void (__thiscall *)(CSequencePickerFrame *))v17->PostActionSignal)(a1: v17);
          if ( poseParameters.m_Memory.m_nGrowSize >= 0 && poseParameters.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: poseParameters.m_Memory.m_pMemory);
          if ( sequenceLayers.m_Memory.m_nGrowSize >= 0 && sequenceLayers.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sequenceLayers.m_Memory.m_pMemory);
          v3 = v17;
        }
        else if ( v7 != nullptr )
        {
          v20 = KeyValues::KeyValues(
                  this: v7,
                  setName: "SequenceSelected",
                  firstKey: "activity",
                  firstValue: SelectedSequenceName);
          v3->PostActionSignal(this: v3, a2: v20);
        }
        else
        {
          v3->PostActionSignal(this: v3, a2: nullptr);
        }
        v3->CloseModal(this: v3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D2EB0
// Name: private: void CSequencePicker::UpdateAvailablePoseParmeters(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSequencePicker::UpdateAvailablePoseParmeters(CSequencePicker *this@<ecx>, int a2@<esi>)
{
  CSequencePicker *v2; // ebx
  bool v3; // zf
  IMDLCache *v4; // eax
  const studiohdr_t *v5; // eax
  int *p_m_nSequenceIndex; // esi
  int v7; // edi
  int v8; // eax
  int NumPoseParameters; // esi
  int v10; // edi
  int v11; // eax
  int v12; // eax
  vgui::Slider **m_pPoseValueSliders; // ebx
  vgui::Slider *v14; // ecx
  vgui::ComboBox *v15; // esi
  int v16; // edi
  int v17; // ebx
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  int v20; // eax
  vgui::Slider **v21; // esi
  int v22; // ebx
  vgui::Slider *v23; // ecx
  int *m_pMemory; // eax
  int *v25; // eax
  const studiohdr_t **v26; // eax
  int sequencePoseParameters[24]; // [esp+4h] [ebp-F4h] BYREF
  bool activePoseParameters[24]; // [esp+64h] [ebp-94h] BYREF
  CStudioHdr studioHdr; // [esp+7Ch] [ebp-7Ch] BYREF
  const mstudioposeparamdesc_t *poseParameter; // [esp+E0h] [ebp-18h]
  vgui::Slider **v31; // [esp+E4h] [ebp-14h]
  CSequencePicker *v32; // [esp+E8h] [ebp-10h]
  int nNumSequenceParameters; // [esp+ECh] [ebp-Ch]
  int nNumActiveControls; // [esp+F0h] [ebp-8h]
  int iControl; // [esp+F4h] [ebp-4h]

  v2 = this;
  v3 = !this->m_bSequenceParams;
  v32 = this;
  if ( !v3 )
  {
    v4 = vgui::MDLCache();
    v5 = (const studiohdr_t *)((int (__thiscall *)(IMDLCache *, _DWORD, int))v4->GetStudioHdr)(
                                a1: v4,
                                a2: v2->m_hSelectedMDL,
                                a3: a2);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v5, mdlcache: nullptr);
    memset(activePoseParameters, 0, sizeof(activePoseParameters));
    p_m_nSequenceIndex = &v2->m_SequenceLayers[0].m_nSequenceIndex;
    for ( iControl = 4; iControl != 0; --iControl )
    {
      v7 = *p_m_nSequenceIndex;
      if ( *p_m_nSequenceIndex >= 0 )
      {
        v8 = studioHdr.m_pVModel != nullptr
           ? CStudioHdr::GetNumSeq_Internal(this: &studioHdr)
           : studioHdr.m_pStudioHdr->numlocalseq;
        if ( v7 < v8 )
          FindSequencePoseParameters(hdr: &studioHdr, nSequence: v7, pPoseParameters: activePoseParameters, nCount: 24);
      }
      p_m_nSequenceIndex += 2;
    }
    NumPoseParameters = CStudioHdr::GetNumPoseParameters(this: &studioHdr);
    v10 = 0;
    nNumSequenceParameters = 0;
    _V_memset(dest: sequencePoseParameters, fill: 255, count: 96);
    v11 = 0;
    if ( NumPoseParameters <= 0 )
      goto LABEL_16;
    do
    {
      if ( activePoseParameters[v11] )
        sequencePoseParameters[v10++] = v11;
      ++v11;
    }
    while ( v11 < NumPoseParameters );
    nNumSequenceParameters = v10;
    if ( v10 <= 6 )
    {
LABEL_16:
      nNumActiveControls = v10;
      v12 = v10;
    }
    else
    {
      v12 = 6;
      nNumActiveControls = 6;
    }
    iControl = 0;
    if ( v12 > 0 )
    {
      m_pPoseValueSliders = v2->m_pPoseValueSliders;
      v31 = m_pPoseValueSliders;
      while ( 1 )
      {
        v14 = *m_pPoseValueSliders;
        m_pPoseValueSliders[26] = (vgui::Slider *)sequencePoseParameters[iControl];
        v14->SetEnabled(this: v14, a2: true);
        m_pPoseValueSliders[6]->SetEnabled(this: m_pPoseValueSliders[6], a2: true);
        v15 = (vgui::ComboBox *)m_pPoseValueSliders[12];
        v15->SetEnabled(this: v15, a2: true);
        vgui::ComboBox::RemoveAll(this: v15);
        v15->SetNumberOfEditLines(this: v15, a2: v10);
        v16 = 0;
        if ( nNumSequenceParameters > 0 )
        {
          do
          {
            v17 = sequencePoseParameters[v16];
            poseParameter = CStudioHdr::pPoseParameter(this: &studioHdr, i: v17);
            v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v18 != nullptr )
              v19 = KeyValues::KeyValues(this: v18, setName: "ParameterItem", firstKey: "paramIndex", firstValue: v17);
            else
              v19 = nullptr;
            v20 = v15->AddItem_2(this: v15, a2: (const char *)poseParameter + poseParameter->sznameindex, a3: v19);
            if ( v16 == iControl )
              v15->ActivateItem(this: v15, a2: v20);
            ++v16;
          }
          while ( v16 < nNumSequenceParameters );
          m_pPoseValueSliders = v31;
        }
        ++m_pPoseValueSliders;
        ++iControl;
        v31 = m_pPoseValueSliders;
        if ( iControl >= nNumActiveControls )
          break;
        v10 = nNumSequenceParameters;
      }
      v2 = v32;
      v12 = nNumActiveControls;
    }
    if ( v12 < 6 )
    {
      v21 = &v2->m_pPoseValueSliders[v12];
      v22 = 6 - v12;
      do
      {
        v23 = *v21;
        v21[26] = (vgui::Slider *)-1;
        v23->SetEnabled(this: v23, a2: false);
        (*v21)->SetValue(this: *v21, a2: 0, a3: true);
        v21[6]->SetEnabled(this: v21[6], a2: false);
        ((void (__thiscall *)(vgui::Slider *, const char *))v21[6]->SetValue)(a1: v21[6], a2: defaultValue);
        v21[12]->SetEnabled(this: v21[12], a2: false);
        vgui::ComboBox::RemoveAll(this: (vgui::ComboBox *)v21[12]);
        ((void (__thiscall *)(vgui::Slider *, const char *))v21[12]->SetValue)(a1: v21[12], a2: defaultValue);
        ++v21;
        --v22;
      }
      while ( v22 != 0 );
      v2 = v32;
      v12 = nNumActiveControls;
    }
    v2->m_pPoseDefaultButton->SetEnabled(this: v2->m_pPoseDefaultButton, a2: v12 > 0);
    CSequencePicker::UpdatePoseControlsFromParameters(this: v2);
    CStudioHdr::Term(this: &studioHdr);
    m_pMemory = studioHdr.m_boneParent.m_Memory.m_pMemory;
    studioHdr.m_boneParent.m_Size = 0;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneParent.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneParent.m_pElements = m_pMemory;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v25 = studioHdr.m_boneFlags.m_Memory.m_pMemory;
    studioHdr.m_boneFlags.m_Size = 0;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneFlags.m_Memory.m_pMemory);
        v25 = nullptr;
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneFlags.m_pElements = v25;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v25 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v26 = studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
    studioHdr.m_pStudioHdrCache.m_Size = 0;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
        v26 = nullptr;
        studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_pStudioHdrCache.m_pElements = v26;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v26 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v26);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3260
// Name: private: void CSequencePicker::ResetPoseParametersToDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::ResetPoseParametersToDefault(CSequencePicker *this)
{
  IMDLCache *v2; // eax
  const studiohdr_t *v3; // eax
  CStudioHdr studioHdr; // [esp+4h] [ebp-64h] BYREF

  v2 = vgui::MDLCache();
  v3 = v2->GetStudioHdr(this: v2, a2: this->m_hSelectedMDL);
  CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v3, mdlcache: nullptr);
  Studio_CalcDefaultPoseParameters(pStudioHdr: &studioHdr, flPoseParameter: this->m_PoseParameters, nCount: 24);
  CSequencePicker::UpdatePoseControlsFromParameters(this);
  CStudioHdr::Term(this: &studioHdr);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&studioHdr.m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x004D32D0
// Name: private: void CSequencePicker::UpdatePoseParameterControlsForMdl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::UpdatePoseParameterControlsForMdl(CSequencePicker *this)
{
  vgui::Slider **m_pPoseValueSliders; // esi
  int i; // edi
  vgui::Slider *v4; // ecx
  IMDLCache *v5; // eax
  const studiohdr_t *v6; // eax
  int *m_pMemory; // eax
  int *v8; // eax
  const studiohdr_t **v9; // eax
  CStudioHdr pStudioHdr; // [esp+8h] [ebp-64h] BYREF

  if ( this->m_bSequenceParams )
  {
    m_pPoseValueSliders = this->m_pPoseValueSliders;
    for ( i = 6; i != 0; --i )
    {
      v4 = *m_pPoseValueSliders;
      m_pPoseValueSliders[26] = (vgui::Slider *)-1;
      v4->SetEnabled(this: v4, a2: false);
      m_pPoseValueSliders[6]->SetEnabled(this: m_pPoseValueSliders[6], a2: false);
      m_pPoseValueSliders[12]->SetEnabled(this: m_pPoseValueSliders[12], a2: false);
      ++m_pPoseValueSliders;
    }
  }
  v5 = vgui::MDLCache();
  v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
  CStudioHdr::CStudioHdr(this: &pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
  Studio_CalcDefaultPoseParameters(&pStudioHdr, flPoseParameter: this->m_PoseParameters, nCount: 24);
  CSequencePicker::UpdatePoseControlsFromParameters(this);
  CStudioHdr::Term(this: &pStudioHdr);
  m_pMemory = pStudioHdr.m_boneParent.m_Memory.m_pMemory;
  pStudioHdr.m_boneParent.m_Size = 0;
  if ( pStudioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pStudioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pStudioHdr.m_boneParent.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      pStudioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  pStudioHdr.m_boneParent.m_pElements = m_pMemory;
  if ( pStudioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      pStudioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  v8 = pStudioHdr.m_boneFlags.m_Memory.m_pMemory;
  pStudioHdr.m_boneFlags.m_Size = 0;
  if ( pStudioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pStudioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pStudioHdr.m_boneFlags.m_Memory.m_pMemory);
      v8 = nullptr;
      pStudioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  pStudioHdr.m_boneFlags.m_pElements = v8;
  if ( pStudioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      pStudioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  v9 = pStudioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
  pStudioHdr.m_pStudioHdrCache.m_Size = 0;
  if ( pStudioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pStudioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pStudioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
      v9 = nullptr;
      pStudioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
    }
    pStudioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  pStudioHdr.m_pStudioHdrCache.m_pElements = v9;
  if ( pStudioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v9 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x004D3450
// Name: private: void CSequencePicker::SetSequenceLayer(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSequencePicker::SetSequenceLayer(
        CSequencePicker *this@<ecx>,
        int a2@<esi>,
        unsigned int nLayerIndex,
        int nSequenceIndex,
        float flWeight)
{
  CSequencePicker *v5; // edi
  IMDLCache *v6; // eax
  studiohdr_t *v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  float v10; // xmm0_4
  vgui::ComboBox *v11; // esi
  mstudioseqdesc_t *v12; // eax
  const char *v13; // ebx
  int v14; // edi
  KeyValues *ItemUserData; // eax
  const char *String; // eax
  vgui::Slider *v17; // ecx
  int v18; // esi
  studiohdr_t *pstudiohdr; // [esp+4h] [ebp-8h]
  int nItems; // [esp+18h] [ebp+Ch]

  v5 = this;
  v6 = vgui::MDLCache();
  v7 = v6->GetStudioHdr(this: v6, a2: v5->m_hSelectedMDL);
  pstudiohdr = v7;
  if ( v7 != nullptr )
  {
    v8 = v7->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v7) : v7->numlocalseq;
    v9 = nLayerIndex;
    if ( nLayerIndex <= 3 && nSequenceIndex < v8 )
    {
      v10 = 0.0;
      v5->m_SequenceLayers[nLayerIndex].m_nSequenceIndex = nSequenceIndex;
      if ( flWeight > 0.0 )
      {
        v10 = 1.0;
        if ( flWeight < 1.0 )
          v10 = flWeight;
      }
      v5->m_SequenceLayers[nLayerIndex].m_flWeight = v10;
      CMDLPanel::SetSequenceLayers(this: v5->m_pMDLPreview, pSequenceLayers: &v5->m_SequenceLayers[1], nCount: 3);
      v11 = v5->m_pLayerSequenceSelectors[nLayerIndex];
      if ( v11 != nullptr )
      {
        if ( nSequenceIndex >= 0 )
        {
          v12 = studiohdr_t::pSeqdesc(this: pstudiohdr, i: nSequenceIndex);
          v13 = (char *)v12 + v12->szlabelindex;
          v14 = 0;
          nItems = v11->GetItemCount(this: v11);
          if ( nItems > 0 )
          {
            do
            {
              ItemUserData = vgui::ComboBox::GetItemUserData(this: v11, itemID: v14);
              if ( ItemUserData != nullptr )
              {
                String = KeyValues::GetString(this: ItemUserData, keyName: "sequence", defaultValue: "invalidItem");
                if ( _V_stricmp(s1: v13, s2: String) == 0 )
                  v11->ActivateItem(this: v11, a2: v14);
              }
              ++v14;
            }
            while ( v14 < nItems );
          }
          v5 = this;
          v9 = nLayerIndex;
        }
        else
        {
          v11->SetText(this: v11, a2: defaultValue);
        }
      }
      v17 = v5->m_pLayerSequenceSliders[v9];
      v18 = a2;
      if ( v17 != nullptr )
        v17->SetValue(this: v17, a2: (int)(float)(v5->m_SequenceLayers[v9].m_flWeight * 100.0), a3: false);
      CSequencePicker::UpdateAvailablePoseParmeters(this: v5, a2: v18);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D35D0
// Name: private: void CSequencePicker::UpdateLayerControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::UpdateLayerControls(CSequencePicker *this)
{
  CSequencePicker *v1; // esi
  float *p_m_flWeight; // edi
  IMDLCache *v3; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // ebx
  int v6; // eax
  int v7; // xmm0_4
  vgui::ComboBox *v8; // esi
  mstudioseqdesc_t *v9; // eax
  const char *v10; // ebx
  int v11; // edi
  KeyValues *ItemUserData; // eax
  const char *String; // eax
  float v14; // [esp+Ch] [ebp-18h]
  int i; // [esp+14h] [ebp-10h]
  int ia; // [esp+14h] [ebp-10h]
  float *v18; // [esp+18h] [ebp-Ch]
  int iLayer; // [esp+1Ch] [ebp-8h]
  vgui::Slider **m_pLayerSequenceSliders; // [esp+20h] [ebp-4h]

  v1 = this;
  p_m_flWeight = &this->m_SequenceLayers[0].m_flWeight;
  iLayer = 0;
  v18 = &this->m_SequenceLayers[0].m_flWeight;
  m_pLayerSequenceSliders = this->m_pLayerSequenceSliders;
  do
  {
    v14 = *p_m_flWeight;
    i = *((_DWORD *)p_m_flWeight - 1);
    v3 = vgui::MDLCache();
    v4 = v3->GetStudioHdr(this: v3, a2: v1->m_hSelectedMDL);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
      if ( (unsigned int)iLayer <= 3 && i < v6 )
      {
        v7 = 0;
        *((_DWORD *)p_m_flWeight - 1) = i;
        if ( v14 > 0.0 )
        {
          v7 = 1065353216;
          if ( v14 < 1.0 )
            v7 = LODWORD(v14);
        }
        *(_DWORD *)p_m_flWeight = v7;
        CMDLPanel::SetSequenceLayers(this: v1->m_pMDLPreview, pSequenceLayers: &v1->m_SequenceLayers[1], nCount: 3);
        v8 = (vgui::ComboBox *)*(m_pLayerSequenceSliders - 4);
        if ( v8 != nullptr )
        {
          if ( i >= 0 )
          {
            v9 = studiohdr_t::pSeqdesc(this: v5, i);
            v10 = (char *)v9 + v9->szlabelindex;
            v11 = 0;
            ia = v8->GetItemCount(this: v8);
            if ( ia > 0 )
            {
              do
              {
                ItemUserData = vgui::ComboBox::GetItemUserData(this: v8, itemID: v11);
                if ( ItemUserData != nullptr )
                {
                  String = KeyValues::GetString(this: ItemUserData, keyName: "sequence", defaultValue: "invalidItem");
                  if ( _V_stricmp(s1: v10, s2: String) == 0 )
                    v8->ActivateItem(this: v8, a2: v11);
                }
                ++v11;
              }
              while ( v11 < ia );
            }
            p_m_flWeight = v18;
          }
          else
          {
            v8->SetText(this: v8, a2: defaultValue);
          }
        }
        if ( *m_pLayerSequenceSliders != nullptr )
          (*m_pLayerSequenceSliders)->SetValue(
            this: *m_pLayerSequenceSliders,
            a2: (int)(float)(*p_m_flWeight * 100.0),
            a3: false);
        CSequencePicker::UpdateAvailablePoseParmeters(this, a2: (int)v8);
        v1 = this;
      }
    }
    ++m_pLayerSequenceSliders;
    p_m_flWeight += 2;
    ++iLayer;
    v18 = p_m_flWeight;
  }
  while ( iLayer < 4 );
}

//------------------------------------------------------------------------------
// Address: 0x004D3780
// Name: private: void CSequencePicker::ResetLayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::ResetLayers(CSequencePicker *this)
{
  MDLSquenceLayer_t *m_SequenceLayers; // ebx
  signed int i; // edi

  m_SequenceLayers = this->m_SequenceLayers;
  this->m_SequenceLayers[0].m_flWeight = 1.0;
  this->m_SequenceLayers[0].m_nSequenceIndex = 0;
  this->m_SequenceLayers[1].m_nSequenceIndex = -1;
  this->m_SequenceLayers[1].m_flWeight = 0.0;
  this->m_SequenceLayers[2].m_nSequenceIndex = -1;
  this->m_SequenceLayers[2].m_flWeight = 0.0;
  this->m_SequenceLayers[3].m_nSequenceIndex = -1;
  this->m_SequenceLayers[3].m_flWeight = 0.0;
  for ( i = 0; i < 4; ++i )
  {
    CSequencePicker::SetSequenceLayer(
      this,
      a2: (int)this,
      nLayerIndex: i,
      nSequenceIndex: m_SequenceLayers->m_nSequenceIndex,
      flWeight: m_SequenceLayers->m_flWeight);
    ++m_SequenceLayers;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3800
// Name: private: virtual void CSequencePicker::OnSliderMoved(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnSliderMoved(CSequencePicker *this, KeyValues *pData)
{
  vgui::Slider *Ptr; // eax
  int v4; // esi
  vgui::Slider **m_pLayerSequenceSliders; // ecx
  int v6; // esi
  vgui::Slider **i; // ecx
  int v8; // eax
  int v9; // eax

  Ptr = (vgui::Slider *)KeyValues::GetPtr(this: pData, keyName: "panel", defaultValue: nullptr);
  v4 = 0;
  m_pLayerSequenceSliders = this->m_pLayerSequenceSliders;
  do
  {
    if ( Ptr == *m_pLayerSequenceSliders )
    {
      v8 = this->m_pLayerSequenceSliders[v4]->GetValue(this: this->m_pLayerSequenceSliders[v4]);
      CSequencePicker::SetSequenceLayer(
        this,
        a2: v4,
        nLayerIndex: v4,
        nSequenceIndex: this->m_SequenceLayers[v4].m_nSequenceIndex,
        flWeight: (float)v8 * 0.0099999998);
      return;
    }
    ++v4;
    ++m_pLayerSequenceSliders;
  }
  while ( v4 < 4 );
  v6 = 0;
  for ( i = this->m_pPoseValueSliders; Ptr != *i; ++i )
  {
    if ( ++v6 >= 6 )
      return;
  }
  v9 = this->m_pPoseValueSliders[v6]->GetValue(this: this->m_pPoseValueSliders[v6]);
  CSequencePicker::SetPoseParameterValue(
    this,
    flPoseParameterValue: (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)v9 - 50.0) * 0.02) & _mask__AbsFloat_)
                  * (float)((float)((float)v9 - 50.0) * 0.02))
          + 1.0)
  * 0.5,
    nParameterIndex: this->m_PoseControlMap[v6]);
}

//------------------------------------------------------------------------------
// Address: 0x004D38F0
// Name: public: virtual void CSequencePicker::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnCommand(CSequencePicker *this, const char *pCommand)
{
  if ( _V_strcmp(s1: "ResetToDefaults", s2: pCommand) == 0 )
    CSequencePicker::ResetPoseParametersToDefault(this);
}

//------------------------------------------------------------------------------
// Address: 0x004D3920
// Name: private: void CSequencePicker::UpdateActiveSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::UpdateActiveSequence(CSequencePicker *this, const char *pSequenceName)
{
  int Sequence; // eax
  int v4; // edi

  Sequence = CSequencePicker::FindSequence(this, pSequenceName);
  v4 = Sequence;
  if ( Sequence >= 0 )
  {
    if ( this->m_bSequenceParams )
    {
      CSequencePicker::SetSequenceLayer(this, a2: (int)this, nLayerIndex: 0, nSequenceIndex: Sequence, flWeight: 1.0);
      CSequencePicker::UpdateAvailablePoseParmeters(this, a2: (int)this);
    }
    CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3970
// Name: private: virtual void CSequencePicker::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnPageChanged(CSequencePicker *this)
{
  const char *SelectedSequenceName; // eax
  const char *v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  const char *v6; // eax
  const char *v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // eax

  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    SelectedSequenceName = CSequencePicker::GetSelectedSequenceName(this);
    v3 = SelectedSequenceName;
    if ( SelectedSequenceName == nullptr )
      return;
    CSequencePicker::UpdateActiveSequence(this, pSequenceName: SelectedSequenceName);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "SequencePreviewChanged", firstKey: "sequence", firstValue: v3);
      this->PostActionSignal(this, a2: v5);
      return;
    }
LABEL_11:
    this->PostActionSignal(this, a2: nullptr);
    return;
  }
  if ( this->m_pActivitiesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    v6 = CSequencePicker::GetSelectedSequenceName(this);
    v7 = v6;
    if ( v6 != nullptr )
    {
      CSequencePicker::PlayActivity(this, pActivityName: v6);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v9 = KeyValues::KeyValues(this: v8, setName: "SequencePreviewChanged", firstKey: "activity", firstValue: v7);
        this->PostActionSignal(this, a2: v9);
        return;
      }
      goto LABEL_11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3A60
// Name: private: virtual void CSequencePicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnItemSelected(CSequencePicker *this, KeyValues *kv)
{
  vgui::ListPanel *Ptr; // eax
  vgui::ListPanel *m_pSequencesList; // ecx
  const char *SelectedSequenceName; // eax
  const char *v6; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  vgui::ListPanel *m_pActivitiesList; // ecx
  const char *v10; // eax
  const char *v11; // edi
  KeyValues *v12; // eax
  KeyValues *v13; // eax

  Ptr = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pSequencesList = this->m_pSequencesList;
  if ( m_pSequencesList != nullptr && Ptr == m_pSequencesList )
  {
    SelectedSequenceName = CSequencePicker::GetSelectedSequenceName(this);
    v6 = SelectedSequenceName;
    if ( SelectedSequenceName == nullptr )
      return;
    CSequencePicker::UpdateActiveSequence(this, pSequenceName: SelectedSequenceName);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(this: v7, setName: "SequencePreviewChanged", firstKey: "sequence", firstValue: v6);
      this->PostActionSignal(this, a2: v8);
      return;
    }
LABEL_11:
    this->PostActionSignal(this, a2: nullptr);
    return;
  }
  m_pActivitiesList = this->m_pActivitiesList;
  if ( m_pActivitiesList != nullptr && Ptr == m_pActivitiesList )
  {
    v10 = CSequencePicker::GetSelectedSequenceName(this);
    v11 = v10;
    if ( v10 != nullptr )
    {
      CSequencePicker::PlayActivity(this, pActivityName: v10);
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
      {
        v13 = KeyValues::KeyValues(this: v12, setName: "SequencePreviewChanged", firstKey: "activity", firstValue: v11);
        this->PostActionSignal(this, a2: v13);
        return;
      }
      goto LABEL_11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3B40
// Name: private: virtual void CSequencePicker::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::OnTextChanged(CSequencePicker *this, KeyValues *pData)
{
  vgui::ComboBox *Ptr; // eax
  signed int v4; // edi
  vgui::ComboBox **m_pLayerSequenceSelectors; // ecx
  int v6; // edi
  vgui::ComboBox **i; // ecx
  const char *String; // eax
  int Sequence; // eax
  int v10; // edi
  KeyValues *ActiveItemUserData; // eax
  unsigned int Int; // eax

  Ptr = (vgui::ComboBox *)KeyValues::GetPtr(this: pData, keyName: "panel", defaultValue: nullptr);
  v4 = 0;
  m_pLayerSequenceSelectors = this->m_pLayerSequenceSelectors;
  do
  {
    if ( Ptr == *m_pLayerSequenceSelectors )
    {
      String = KeyValues::GetString(this: pData, keyName: "text", defaultValue: defaultValue);
      Sequence = CSequencePicker::FindSequence(this, pSequenceName: String);
      if ( v4 != 0 )
      {
        CSequencePicker::SetSequenceLayer(
          this,
          a2: (int)this,
          nLayerIndex: v4,
          nSequenceIndex: Sequence,
          flWeight: this->m_SequenceLayers[v4].m_flWeight);
      }
      else
      {
        v10 = Sequence;
        if ( Sequence >= 0 )
        {
          if ( this->m_bSequenceParams )
          {
            CSequencePicker::SetSequenceLayer(
              this,
              a2: (int)this,
              nLayerIndex: 0,
              nSequenceIndex: Sequence,
              flWeight: 1.0);
            CSequencePicker::UpdateAvailablePoseParmeters(this, a2: (int)this);
          }
          CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: v10);
        }
      }
      return;
    }
    ++v4;
    ++m_pLayerSequenceSelectors;
  }
  while ( v4 < 4 );
  v6 = 0;
  for ( i = this->m_pPoseParameterName; Ptr != *i; ++i )
  {
    if ( ++v6 >= 6 )
      return;
  }
  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pPoseParameterName[v6]);
  Int = KeyValues::GetInt(this: ActiveItemUserData, keyName: "paramIndex", defaultValue: -1);
  if ( Int <= 0x17 )
  {
    this->m_PoseControlMap[v6] = Int;
    CSequencePicker::SetPoseParameterValue(
      this,
      flPoseParameterValue: this->m_PoseParameters[Int],
      nParameterIndex: Int);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3C60
// Name: private: void CSequencePicker::RefreshActivitiesAndSequencesList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::RefreshActivitiesAndSequencesList(CSequencePicker *this)
{
  CSequencePicker *v1; // ebx
  bool v2; // zf
  vgui::ComboBox **m_pLayerSequenceSelectors; // esi
  int k; // edi
  IMDLCache *v5; // eax
  studiohdr_t *v6; // eax
  studiohdr_t *v7; // esi
  int NumSeq_Internal; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v9; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  studiohdr_t *v14; // esi
  int v15; // ebx
  int v16; // eax
  mstudioseqdesc_t *v17; // eax
  const char *v18; // edi
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  int v21; // ebx
  KeyValues *v22; // eax
  KeyValues *v23; // esi
  IMDLCache *v24; // eax
  const char *v25; // eax
  int v26; // eax
  mstudioseqdesc_t *v27; // eax
  int v28; // edi
  const char *v29; // esi
  KeyValues *v30; // eax
  KeyValues *v31; // eax
  int v32; // ebx
  KeyValues *v33; // eax
  KeyValues *v34; // esi
  IMDLCache *v35; // eax
  const char *v36; // eax
  int numlocalseq; // ebx
  int v38; // edi
  int v39; // eax
  mstudioseqdesc_t *v40; // ebx
  int m_Size; // esi
  mstudioseqdesc_t **v42; // esi
  vgui::ComboBox **v43; // esi
  int m; // edi
  const char *v45; // esi
  vgui::ComboBox **v46; // edi
  int n; // ebx
  KeyValues *v48; // eax
  KeyValues *v49; // eax
  CUtlDict<int,unsigned short> activityNames; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<mstudioseqdesc_t *,CUtlMemory<mstudioseqdesc_t *,int> > sequenceList; // [esp+28h] [ebp-2Ch] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+3Ch] [ebp-18h] BYREF
  vgui::ComboBox **v53; // [esp+44h] [ebp-10h]
  int i; // [esp+48h] [ebp-Ch]
  int nNumSequences; // [esp+4Ch] [ebp-8h]
  int j; // [esp+50h] [ebp-4h] BYREF

  v1 = this;
  v2 = this->m_pActivitiesList == nullptr;
  nNumSequences = (int)this;
  if ( !v2 )
    this->m_pActivitiesList->RemoveAll(this: this->m_pActivitiesList);
  if ( v1->m_pSequencesList != nullptr )
    v1->m_pSequencesList->RemoveAll(this: v1->m_pSequencesList);
  m_pLayerSequenceSelectors = v1->m_pLayerSequenceSelectors;
  v53 = v1->m_pLayerSequenceSelectors;
  for ( k = 4; k != 0; --k )
  {
    if ( *m_pLayerSequenceSelectors != nullptr )
      vgui::ComboBox::RemoveAll(this: *m_pLayerSequenceSelectors);
    ++m_pLayerSequenceSelectors;
  }
  CMDLPanel::SetSequence(this: v1->m_pMDLPreview, nSequence: 0);
  if ( v1->m_hSelectedMDL != 0xFFFF )
  {
    v5 = vgui::MDLCache();
    v6 = v5->GetStudioHdr(this: v5, a2: v1->m_hSelectedMDL);
    v7 = v6;
    i = (int)v6;
    if ( v6->numincludemodels != 0 )
      NumSeq_Internal = studiohdr_t::GetNumSeq_Internal(this: v6);
    else
      NumSeq_Internal = v6->numlocalseq;
    v9 = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = NumSeq_Internal;
    activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    if ( NumSeq_Internal != 0 )
    {
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 16 * NumSeq_Internal);
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v9;
    }
    v10 = 0;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_FirstFree = -1;
    activityNames.m_Elements.m_Tree.m_pElements = v9;
    activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    for ( j = 0; ; v10 = j )
    {
      v11 = v7->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v7) : v7->numlocalseq;
      if ( v10 >= v11 )
        break;
      if ( v7->numincludemodels != 0 )
      {
        v13 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v10);
      }
      else
      {
        v12 = v10;
        if ( v10 < 0 || v10 >= v7->numlocalseq )
          v12 = 0;
        v13 = (mstudioseqdesc_t *)((char *)v7 + 212 * v12 + v7->localseqindex);
      }
      if ( (v13->flags & 0x400) == 0 )
      {
        v14 = (studiohdr_t *)i;
        v15 = j;
        if ( *(_DWORD *)(i + 336) != 0 )
        {
          v17 = studiohdr_t::pSeqdesc_Internal(this: (studiohdr_t *)i, i: j);
        }
        else
        {
          v16 = j;
          if ( j < 0 || j >= *(_DWORD *)(i + 188) )
            v16 = 0;
          v17 = (mstudioseqdesc_t *)(i + *(_DWORD *)(i + 192) + 212 * v16);
        }
        v18 = (char *)v17 + v17->szactivitynameindex;
        if ( *(_DWORD *)(nNumSequences + 416) != 0 && v18 != nullptr && *v18 != 0 )
        {
          search.key = (char *)v17 + v17->szactivitynameindex;
          if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                 this: &activityNames.m_Elements.m_Tree,
                 &search) == 0xFFFF )
          {
            v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v19 != nullptr )
              v20 = KeyValues::KeyValues(this: v19, setName: "node", firstKey: "activity", firstValue: v18);
            else
              v20 = nullptr;
            v21 = (*(int (__thiscall **)(_DWORD, KeyValues *, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(nNumSequences + 416)
                                                                                     + 916))(
                    a1: *(_DWORD *)(nNumSequences + 416),
                    a2: v20,
                    a3: 0,
                    a4: 0,
                    a5: 0);
            v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v22 != nullptr )
              v23 = KeyValues::KeyValues(this: v22, setName: "drag", firstKey: "text", firstValue: v18);
            else
              v23 = nullptr;
            KeyValues::SetString(this: v23, keyName: "texttype", value: "activityName");
            v24 = vgui::MDLCache();
            v25 = v24->GetModelName(this: v24, a2: *(_WORD *)(nNumSequences + 686));
            KeyValues::SetString(this: v23, keyName: "mdl", value: v25);
            vgui::ListPanel::SetItemDragData(this: *(vgui::ListPanel **)(nNumSequences + 416), itemID: v21, data: v23);
            CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v18, element: &j);
            v14 = (studiohdr_t *)i;
            v15 = j;
          }
        }
        if ( v14->numincludemodels != 0 )
        {
          v27 = studiohdr_t::pSeqdesc_Internal(this: v14, i: v15);
        }
        else
        {
          v26 = v15;
          if ( v15 < 0 || v15 >= v14->numlocalseq )
            v26 = 0;
          v27 = (mstudioseqdesc_t *)((char *)v14 + 212 * v26 + v14->localseqindex);
        }
        v28 = nNumSequences;
        v29 = (char *)v27 + v27->szlabelindex;
        if ( *(_DWORD *)(nNumSequences + 412) != 0 && v29 != nullptr && *v29 != 0 )
        {
          v30 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v30 != nullptr )
            v31 = KeyValues::KeyValues(this: v30, setName: "node", firstKey: "sequence", firstValue: v29);
          else
            v31 = nullptr;
          v32 = (*(int (__thiscall **)(_DWORD, KeyValues *, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(v28 + 412) + 916))(
                  a1: *(_DWORD *)(v28 + 412),
                  a2: v31,
                  a3: 0,
                  a4: 0,
                  a5: 0);
          v33 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v33 != nullptr )
            v34 = KeyValues::KeyValues(this: v33, setName: "drag", firstKey: "text", firstValue: v29);
          else
            v34 = nullptr;
          KeyValues::SetString(this: v34, keyName: "texttype", value: "sequenceName");
          v35 = vgui::MDLCache();
          v36 = v35->GetModelName(this: v35, a2: *(_WORD *)(v28 + 686));
          KeyValues::SetString(this: v34, keyName: "mdl", value: v36);
          vgui::ListPanel::SetItemDragData(this: *(vgui::ListPanel **)(v28 + 412), itemID: v32, data: v34);
        }
      }
      ++j;
      v1 = (CSequencePicker *)nNumSequences;
      v7 = (studiohdr_t *)i;
    }
    if ( v1->m_pSequencesList != nullptr )
      v1->m_pSequencesList->SortList(this: v1->m_pSequencesList);
    if ( v1->m_pActivitiesList != nullptr )
      v1->m_pActivitiesList->SortList(this: v1->m_pActivitiesList);
    if ( v1->m_bSequenceParams )
    {
      if ( v7->numincludemodels != 0 )
      {
        nNumSequences = studiohdr_t::GetNumSeq_Internal(this: v7);
        numlocalseq = nNumSequences;
      }
      else
      {
        numlocalseq = v7->numlocalseq;
        nNumSequences = numlocalseq;
      }
      sequenceList.m_Memory.m_pMemory = nullptr;
      sequenceList.m_Memory.m_nAllocationCount = numlocalseq;
      sequenceList.m_Memory.m_nGrowSize = 0;
      if ( numlocalseq != 0 )
        sequenceList.m_Memory.m_pMemory = (mstudioseqdesc_t **)_g_pMemAlloc->Alloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: 4 * numlocalseq);
      v38 = 0;
      sequenceList.m_Size = 0;
      sequenceList.m_pElements = sequenceList.m_Memory.m_pMemory;
      if ( numlocalseq > 0 )
      {
        while ( 1 )
        {
          if ( v7->numincludemodels != 0 )
          {
            v40 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v38);
          }
          else
          {
            v39 = v38;
            if ( v38 < 0 || v38 >= v7->numlocalseq )
              v39 = 0;
            v40 = (mstudioseqdesc_t *)((char *)v7 + 212 * v39 + v7->localseqindex);
          }
          if ( (v40->flags & 0x400) == 0 )
          {
            m_Size = sequenceList.m_Size;
            if ( sequenceList.m_Size + 1 > sequenceList.m_Memory.m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&sequenceList,
                num: sequenceList.m_Size - sequenceList.m_Memory.m_nAllocationCount + 1);
            ++sequenceList.m_Size;
            sequenceList.m_pElements = sequenceList.m_Memory.m_pMemory;
            if ( sequenceList.m_Size - m_Size - 1 > 0 )
              _V_memmove(
                dest: &sequenceList.m_Memory.m_pMemory[m_Size + 1],
                src: &sequenceList.m_Memory.m_pMemory[m_Size],
                count: 4 * (sequenceList.m_Size - m_Size - 1));
            v42 = &sequenceList.m_Memory.m_pMemory[m_Size];
            if ( v42 != nullptr )
              *v42 = v40;
          }
          if ( ++v38 >= nNumSequences )
            break;
          v7 = (studiohdr_t *)i;
        }
      }
      CUtlVector<mstudioseqdesc_t *,CUtlMemory<mstudioseqdesc_t *,int>>::Sort(
        this: (CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *)&sequenceList,
        pfnCompare: (int (__cdecl *)(const void *, const void *))CompareSequenceDesc);
      v43 = v53;
      for ( m = 4; m != 0; --m )
      {
        if ( *v43 != nullptr )
          vgui::ComboBox::RemoveAll(this: *v43);
        ++v43;
      }
      for ( i = 0; i < sequenceList.m_Size; ++i )
      {
        v45 = (char *)sequenceList.m_Memory.m_pMemory[i] + sequenceList.m_Memory.m_pMemory[i]->szlabelindex;
        if ( v45 != nullptr )
        {
          v46 = v53;
          for ( n = 4; n != 0; --n )
          {
            if ( *v46 != nullptr )
            {
              v48 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v48 != nullptr )
                v49 = KeyValues::KeyValues(this: v48, setName: "sequenceItem", firstKey: "sequence", firstValue: v45);
              else
                v49 = nullptr;
              (*v46)->AddItem_2(this: *v46, a2: v45, a3: v49);
            }
            ++v46;
          }
        }
      }
      if ( sequenceList.m_Memory.m_nGrowSize >= 0 && sequenceList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sequenceList.m_Memory.m_pMemory);
    }
    CUtlDict<int,unsigned short>::RemoveAll(this: &activityNames);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &activityNames.m_Elements.m_Tree);
    if ( activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && activityNames.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: activityNames.m_Elements.m_Tree.m_Elements.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D4240
// Name: public: void CSequencePicker::SetMDL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePicker::SetMDL(CSequencePicker *this, const char *pMDLName)
{
  IMDLCache *v3; // eax
  unsigned __int16 v4; // ax
  IMDLCache *v5; // eax

  if ( pMDLName != nullptr )
  {
    v3 = vgui::MDLCache();
    v4 = v3->FindMDL(this: v3, a2: pMDLName);
  }
  else
  {
    v4 = -1;
  }
  this->m_hSelectedMDL = v4;
  v5 = vgui::MDLCache();
  if ( v5->IsErrorModel(this: v5, a2: this->m_hSelectedMDL) )
    this->m_hSelectedMDL = -1;
  this->m_pMDLPreview->SetMDL_2(this: this->m_pMDLPreview, a2: this->m_hSelectedMDL, a3: nullptr);
  CMDLPanel::LookAtMDL(this: this->m_pMDLPreview, a2: (int)pMDLName);
  CSequencePicker::ResetLayers(this);
  CSequencePicker::RefreshActivitiesAndSequencesList(this);
  CSequencePicker::UpdateLayerControls(this);
  CSequencePicker::UpdatePoseParameterControlsForMdl(this);
}

//------------------------------------------------------------------------------
// Address: 0x004D42E0
// Name: public: void CSequencePickerFrame::DoModal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequencePickerFrame::DoModal(CSequencePickerFrame *this, const char *pMDLName)
{
  CSequencePicker::SetMDL(this: this->m_pPicker, pMDLName);
  vgui::Frame::DoModal(this);
}

} // namespace sceneviewer
