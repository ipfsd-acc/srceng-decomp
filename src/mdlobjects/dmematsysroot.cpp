// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmematsysroot.cpp
// Functions: 64
// ============================================================

#include "mdlobjects\dmematsysroot.h"

//------------------------------------------------------------------------------
// Address: 0x004A5910
// Name: protected: virtual void CDmeMatSysDMXDag::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysDMXDag::PerformDestruction(CDmeRig *this)
{
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004A7820
// Name: private: virtual int IDmeMatSysModel::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IDmeMatSysModel::SelectSequence(IDmeMatSysModel *this, const char *pszSequenceName)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A7830
// Name: public: virtual void CDmeMatSysMPPDag::SetFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::SetFrame(CDmeMatSysMPPDag *this, float flFrame)
{
  int v3; // eax

  v3 = DmeTime_t::RoundSecondsToTMS(sec: COERCE_UNSIGNED_INT(flFrame * 0.033333335));
  ((void (__thiscall *)(CDmeMatSysMPPDag *, int))this->SetTime)(a1: this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004A7930
// Name: protected: void CDmeMatSysPanelSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysPanelSettings::OnConstruction(CDmeMatSysPanelSettings *this)
{
  CDmaVar<Color> *p_m_cBackgroundColor; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v8; // [esp+13h] [ebp-1h] BYREF

  p_m_cBackgroundColor = &this->m_cBackgroundColor;
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backgroundColor",
         type: AT_COLOR,
         pMemory: &this->m_cBackgroundColor);
  p_m_cBackgroundColor->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "ambientColor",
         type: AT_COLOR,
         pMemory: &this->m_cAmbientColor);
  this->m_cAmbientColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v8 = true;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "drawGroundPlane",
         type: AT_BOOL,
         pMemory: &this->m_bDrawGroundPlane);
  this->m_bDrawGroundPlane.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v8);
  v8 = true;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "drawOriginAxis",
         type: AT_BOOL,
         pMemory: &this->m_bDrawOriginAxis);
  this->m_bDrawOriginAxis.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v8);
}

//------------------------------------------------------------------------------
// Address: 0x004A79E0
// Name: public: virtual void CDmeMatSysMPPDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMatSysMPPDag::Draw(CDmeMatSysMPPDag *this@<ecx>, int a2@<esi>, CDmeDrawSettings *pDrawSettings)
{
  int v4; // esi

  if ( *((_BYTE *)&this->CDmElement + 64) != 0 )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 160))(a1: v4, a2: 1);
    CDmeDag::Draw((CDmeDag *)this, pDrawSettings);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 160))(a1: v4, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7A50
// Name: public: struct studiohdr_t __near * CDmeMatSysMDLDag::GetStudioHdr(void)const
// Source: json
//------------------------------------------------------------------------------
studiohdr_t *__thiscall CDmeMatSysMDLDag::GetStudioHdr(CDmeMatSysMDLDag *this)
{
  int v1; // eax
  CDmeMDL *v2; // esi
  unsigned __int16 MDL; // ax
  int v4; // esi

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v2 = (CDmeMDL *)v1;
  if ( v1 == 0 )
    return nullptr;
  if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmeMDL::m_classType.u) == 0 )
    return nullptr;
  MDL = CDmeMDL::GetMDL(this: v2);
  v4 = MDL;
  if ( MDL == 0xFFFF || g_pMDLCache->IsErrorModel(this: g_pMDLCache, a2: MDL) )
    return nullptr;
  else
    return g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004A7AC0
// Name: public: virtual void CDmeMatSysMDLDag::SetTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::SetTime(CDmeMatSysMDLDag *this, DmeTime_t dmeTime)
{
  int v2; // eax
  int v3; // esi
  CDmAttribute *v4; // ecx
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v4 = *(CDmAttribute **)(v3 + 128);
    value = (float)dmeTime.m_tms * 0.000099999997;
    CDmAttribute::SetValue<float>(this: v4, &value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7B20
// Name: public: virtual void CDmeMatSysMDLDag::SetFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::SetFrame(CDmeMatSysMDLDag *this, float flFrame)
{
  int v2; // eax
  int v3; // esi
  CDmAttribute *v4; // ecx

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v4 = *(CDmAttribute **)(v3 + 128);
    flFrame = flFrame / *(float *)(v3 + 116);
    CDmAttribute::SetValue<float>(this: v4, value: &flFrame);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7B80
// Name: protected: void CDmeMatSysMDLDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::OnConstruction(CDmeMatSysMDLDag *this)
{
  const char *m_pAsString; // eax
  DmFileId_t m_fileId; // esi
  CUtlString *v4; // eax
  CUtlString *v5; // eax
  const char *v6; // eax
  int v7; // eax
  int v8; // eax
  CDmeMDL *v9; // esi
  CUtlString v10; // [esp+Ch] [ebp-20h] BYREF
  CUtlString result; // [esp+1Ch] [ebp-10h] BYREF

  m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
  m_fileId = this->m_fileId;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = WindowName;
  v4 = CUtlString::CUtlString(this: &v10, pString: m_pAsString);
  v5 = CUtlString::operator+(this: v4, &result, pOther: "Shape");
  v6 = CUtlString::operator char const *(this: v5);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeMDL::m_classType.u,
         a3: v6,
         a4: m_fileId,
         a5: 0);
  v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v7);
  v9 = (CDmeMDL *)v8;
  if ( v8 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
         a1: v8,
         a2: CDmeMDL::m_classType.u) == 0 )
  {
    v9 = nullptr;
  }
  result.m_Storage.m_nActualLength = 0;
  if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( result.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
      result.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    result.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v10.m_Storage.m_nActualLength = 0;
  if ( v10.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v10.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10.m_Storage.m_Memory.m_pMemory);
      v10.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v10.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( v9 != nullptr )
  {
    CDmeMDL::DrawInEngine(this: v9, bDrawInEngine: true);
    CDmeDag::SetShape(this: &this->CDmeDag, pShape: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7C70
// Name: public: virtual void CDmeMatSysMPPDag::SetTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::SetTime(CDmeMatSysMPPDag *this, DmeTime_t dmeTime)
{
  int v3; // eax
  CDmeSequence *v4; // esi
  CDmeDag *v5; // ebx
  CDmeDag **m_pMemory; // edi
  int m_Size; // esi
  CDmeDag *v8; // ecx
  int i; // ebx
  CDmeDag *v10; // ebx
  const char *m_pAsString; // eax
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > depthFirstStack; // [esp+Ch] [ebp-1Ch] BYREF
  CDmeDag *Child; // [esp+20h] [ebp-8h]
  CDmeDag *pDmeDag; // [esp+24h] [ebp-4h]

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hDmeSequence);
  v4 = (CDmeSequence *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeSequence::m_classType.u) != 0 )
  {
    CDmeSequence::UpdateChannels(this: v4, dmeOperatorList: &this->m_dmeOperatorList, nClipTime: dmeTime);
    memset(&depthFirstStack, 0, sizeof(depthFirstStack));
    v5 = &this->CDmeDag;
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depthFirstStack,
      num: 1);
    m_pMemory = depthFirstStack.m_Memory.m_pMemory;
    m_Size = depthFirstStack.m_Size + 1;
    depthFirstStack.m_pElements = depthFirstStack.m_Memory.m_pMemory;
    if ( &depthFirstStack.m_Memory.m_pMemory[depthFirstStack.m_Size + 1] != (CDmeDag **)4 )
      depthFirstStack.m_Memory.m_pMemory[depthFirstStack.m_Size] = v5;
    while ( m_Size > 0 )
    {
      v8 = m_pMemory[--m_Size];
      pDmeDag = v8;
      depthFirstStack.m_Size = m_Size;
      if ( v8 != nullptr )
      {
        for ( i = CDmElementFramework::GetPhase(this: v8) - 1; i >= 0; --i )
        {
          Child = CDmeDag::GetChild(this: pDmeDag, i);
          if ( m_Size >= depthFirstStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depthFirstStack,
              num: 1);
            m_Size = depthFirstStack.m_Size;
            m_pMemory = depthFirstStack.m_Memory.m_pMemory;
          }
          depthFirstStack.m_Size = ++m_Size;
          depthFirstStack.m_pElements = m_pMemory;
          if ( &m_pMemory[m_Size] != (CDmeDag **)4 )
            m_pMemory[m_Size - 1] = Child;
        }
        v10 = pDmeDag;
        m_pAsString = pDmeDag->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = WindowName;
        if ( _V_stricmp(s1: m_pAsString, s2: "root") == 0 )
          CDmeDag::GetTransform(this: v10);
      }
    }
    if ( depthFirstStack.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7EB0
// Name: public: virtual int CDmeMatSysMDLDag::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMDLDag::SelectSequence(CDmeMatSysMDLDag *this, const char *pszSequenceName)
{
  int v3; // eax
  int v4; // esi
  int v5; // ebx
  studiohdr_t *StudioHdr; // esi
  CDmAttribute *v7; // ecx
  int j; // eax
  bool v9; // zf
  int numlocalseq; // ecx
  mstudioseqdesc_t *v11; // eax
  CDmAttribute *v12; // ecx
  int v14; // esi
  float flPoseParameter[24]; // [esp+Ch] [ebp-C8h] BYREF
  CStudioHdr cStudioHdr; // [esp+6Ch] [ebp-68h] BYREF
  int i; // [esp+D0h] [ebp-4h] BYREF

  if ( pszSequenceName == nullptr || *pszSequenceName == 0 )
    return -1;
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v4 = v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  StudioHdr = CDmeMatSysMDLDag::GetStudioHdr(this);
  if ( StudioHdr == nullptr )
    return -1;
  v7 = *(CDmAttribute **)(v5 + 104);
  i = -1;
  CDmAttribute::SetValue<int>(this: v7, value: &i);
  for ( j = 0; ; j = i + 1 )
  {
    v9 = StudioHdr->numincludemodels == 0;
    i = j;
    if ( v9 )
    {
      numlocalseq = StudioHdr->numlocalseq;
    }
    else
    {
      numlocalseq = studiohdr_t::GetNumSeq_Internal(this: StudioHdr);
      j = i;
    }
    if ( j >= numlocalseq )
      break;
    if ( StudioHdr->numincludemodels != 0 )
    {
      v11 = studiohdr_t::pSeqdesc_Internal(this: StudioHdr, i: j);
    }
    else
    {
      if ( j < 0 || j >= StudioHdr->numlocalseq )
        j = 0;
      v11 = (mstudioseqdesc_t *)((char *)StudioHdr + 212 * j + StudioHdr->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v11 + v11->szlabelindex, s2: pszSequenceName) == 0 )
    {
      CDmAttribute::SetValue<int>(this: *(CDmAttribute **)(v5 + 104), value: &i);
      break;
    }
  }
  if ( *(int *)(v5 + 100) < 0 )
  {
    v12 = *(CDmAttribute **)(v5 + 104);
    pszSequenceName = nullptr;
    CDmAttribute::SetValue<int>(this: v12, value: (int *)&pszSequenceName);
    return -1;
  }
  CStudioHdr::CStudioHdr(this: &cStudioHdr, pStudioHdr: StudioHdr, mdlcache: g_pMDLCache);
  Studio_CalcDefaultPoseParameters(pStudioHdr: &cStudioHdr, flPoseParameter, nCount: 24);
  v14 = Studio_MaxFrame(pStudioHdr: &cStudioHdr, iSequence: *(_DWORD *)(v5 + 100), poseParameter: flPoseParameter);
  if ( v14 == 0 )
    v14 = 1;
  CStudioHdr::Term(this: &cStudioHdr);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&cStudioHdr.m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&cStudioHdr.m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&cStudioHdr.m_pStudioHdrCache);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x004A8040
// Name: public: virtual int CDmeMatSysMPPDag::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMPPDag::SelectSequence(CDmeMatSysMPPDag *this, const char *pszSequenceName)
{
  int v3; // ebx
  CDmElement *v4; // eax
  CDmeSequenceList *Value; // eax
  CDmeSequenceList *v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmeSequence *v10; // eax
  CDmeSequence *v11; // esi
  DmeFramerate_t v13; // ecx
  CDmeChannelsClip *FrameCount; // esi
  DmeFramerate_t v15; // [esp-8h] [ebp-30h] BYREF
  int v16; // [esp-4h] [ebp-2Ch]
  CUtlVector<CDmeSequenceBase *,CUtlMemory<CDmeSequenceBase *,int> > sortedSequenceList; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *dmeOperatorList; // [esp+20h] [ebp-8h]
  CDmeMatSysMPPDag *v19; // [esp+24h] [ebp-4h]

  v3 = 0;
  this->m_hDmeSequence = DMELEMENT_HANDLE_INVALID;
  dmeOperatorList = &this->m_dmeOperatorList;
  this->m_dmeOperatorList.m_Size = 0;
  v19 = this;
  if ( pszSequenceName == nullptr )
    return -1;
  if ( *pszSequenceName == 0 )
    return -1;
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eMppRoot.m_Storage.m_Handle) == 0 )
    return -1;
  v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_eMppRoot.m_Storage.m_Handle);
  Value = CDmElement::GetValueElement<CDmeSequenceList>(this: v4, pAttributeName: "sequenceList");
  v6 = Value;
  if ( Value == nullptr )
    return -1;
  memset(&sortedSequenceList, 0, sizeof(sortedSequenceList));
  if ( Value->m_Sequences.m_Storage.m_Size <= 0 )
  {
LABEL_13:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedSequenceList);
    return -1;
  }
  while ( 1 )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v6->m_Sequences.m_Storage.m_Memory.m_pMemory[v3]);
    v8 = (CDmElement *)v7;
    if ( v7 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmeSequenceBase::m_classType.u) != 0 )
    {
      m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = WindowName;
      if ( _V_stricmp(s1: pszSequenceName, s2: m_pAsString) == 0 )
      {
        v10 = CastElement<CDmeSequence>(pElement: v8);
        v11 = v10;
        if ( v10 != nullptr )
          break;
      }
    }
    if ( ++v3 >= v6->m_Sequences.m_Storage.m_Size )
      goto LABEL_13;
  }
  v19->m_hDmeSequence = CDmElement::GetHandle(this: v10);
  CDmeSequence::PrepareChannels(this: v11, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)dmeOperatorList);
  v16 = 0;
  v15 = v13;
  DmeFramerate_t::DmeFramerate_t(this: &v15, fps: 0x1Eu);
  FrameCount = CDmeSequence::GetFrameCount(this: v11, fallbackFrameRate: v15, bForceFallback: v16);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedSequenceList);
  return (int)FrameCount;
}

//------------------------------------------------------------------------------
// Address: 0x004A8200
// Name: public: virtual void CDmeMatSysMDLDag::GetSequenceList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::GetSequenceList(
        CDmeMatSysMDLDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  studiohdr_t *StudioHdr; // esi
  int i; // edi
  int v5; // eax
  int v6; // eax
  mstudioseqdesc_t *v7; // eax
  int v8; // eax
  mstudioseqdesc_t *v9; // eax
  const char *v10; // ecx
  CUtlString src; // [esp+8h] [ebp-10h] BYREF

  if ( pOutList != nullptr )
  {
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: pOutList);
    StudioHdr = CDmeMatSysMDLDag::GetStudioHdr(this);
    if ( StudioHdr != nullptr )
    {
      for ( i = 0; ; ++i )
      {
        v5 = StudioHdr->numincludemodels != 0
           ? studiohdr_t::GetNumSeq_Internal(this: StudioHdr)
           : StudioHdr->numlocalseq;
        if ( i >= v5 )
          break;
        if ( StudioHdr->numincludemodels != 0 )
        {
          v7 = studiohdr_t::pSeqdesc_Internal(this: StudioHdr, i);
        }
        else
        {
          v6 = i;
          if ( i < 0 || i >= StudioHdr->numlocalseq )
            v6 = 0;
          v7 = (mstudioseqdesc_t *)((char *)StudioHdr + 212 * v6 + StudioHdr->localseqindex);
        }
        if ( (v7->flags & 0x400) == 0 )
        {
          if ( StudioHdr->numincludemodels != 0 )
          {
            v9 = studiohdr_t::pSeqdesc_Internal(this: StudioHdr, i);
          }
          else
          {
            v8 = i;
            if ( i < 0 || i >= StudioHdr->numlocalseq )
              v8 = 0;
            v9 = (mstudioseqdesc_t *)((char *)StudioHdr + 212 * v8 + StudioHdr->localseqindex);
          }
          v10 = (char *)v9 + v9->szlabelindex;
          if ( v10 != nullptr && *v10 != 0 )
          {
            CUtlString::CUtlString(this: &src, pString: v10);
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
              this: pOutList,
              elem: pOutList->m_Size,
              &src);
            src.m_Storage.m_nActualLength = 0;
            if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                src.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              src.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A8320
// Name: public: virtual void CDmeMatSysMPPDag::GetSequenceList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::GetSequenceList(
        CDmeMatSysMPPDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  CDmElement *v3; // eax
  CDmeSequenceList *Value; // eax
  int v5; // ebx
  const char *m_pAsString; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v10; // eax
  CUtlString *v11; // ecx
  CUtlVector<CDmeSequenceBase *,CUtlMemory<CDmeSequenceBase *,int> > sortedSequenceList; // [esp+8h] [ebp-24h] BYREF
  CUtlString string; // [esp+1Ch] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: pOutList);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eMppRoot.m_Storage.m_Handle) != 0 )
  {
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_eMppRoot.m_Storage.m_Handle);
    Value = CDmElement::GetValueElement<CDmeSequenceList>(this: v3, pAttributeName: "sequenceList");
    v5 = 0;
    if ( Value != nullptr )
    {
      memset(&sortedSequenceList, 0, sizeof(sortedSequenceList));
      CDmeSequenceList::GetSortedSequenceList(
        this: Value,
        (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&sortedSequenceList);
      if ( sortedSequenceList.m_Size > 0 )
      {
        do
        {
          m_pAsString = sortedSequenceList.m_Memory.m_pMemory[v5]->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = WindowName;
          CUtlString::CUtlString(this: &string, pString: m_pAsString);
          m_Size = pOutList->m_Size;
          m_nAllocationCount = pOutList->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)pOutList,
              num: m_Size - m_nAllocationCount + 1);
          ++pOutList->m_Size;
          m_pMemory = pOutList->m_Memory.m_pMemory;
          v10 = pOutList->m_Size - m_Size - 1;
          pOutList->m_pElements = pOutList->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v10);
          v11 = &pOutList->m_Memory.m_pMemory[m_Size];
          if ( v11 != nullptr )
            CUtlString::CUtlString(this: v11, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          ++v5;
        }
        while ( v5 < sortedSequenceList.m_Size );
      }
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedSequenceList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A84F0
// Name: public: virtual bool CDmeMatSysPanelSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysPanelSettings::IsA(CDmeMatSysPanelSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysPanelSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A8520
// Name: public: virtual int CDmeMatSysPanelSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysPanelSettings::GetInheritanceDepth(CDmeMatSysPanelSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysPanelSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A85D0
// Name: protected: virtual void CDmeMatSysPanelSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysPanelSettings::PerformConstruction(CDmeMatSysPanelSettings *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMatSysPanelSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A8760
// Name: public: virtual void CDmeMatSysMDLDag::GetActivityList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::GetActivityList(
        CDmeMatSysMDLDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  studiohdr_t *StudioHdr; // eax
  studiohdr_t *v4; // esi
  int v5; // ebx
  int NumSeq_Internal; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v7; // ecx
  bool v8; // zf
  int v9; // eax
  int v10; // eax
  mstudioseqdesc_t *v11; // eax
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  const char *v14; // edi
  CUtlDict<int,unsigned short> activityNames; // [esp+8h] [ebp-38h] BYREF
  CUtlString src; // [esp+24h] [ebp-1Ch] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+34h] [ebp-Ch] BYREF
  int j; // [esp+3Ch] [ebp-4h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: pOutList);
  StudioHdr = CDmeMatSysMDLDag::GetStudioHdr(this);
  v4 = StudioHdr;
  v5 = 0;
  if ( StudioHdr != nullptr )
  {
    if ( StudioHdr->numincludemodels != 0 )
      NumSeq_Internal = studiohdr_t::GetNumSeq_Internal(this: StudioHdr);
    else
      NumSeq_Internal = StudioHdr->numlocalseq;
    v7 = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = NumSeq_Internal;
    activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    if ( NumSeq_Internal != 0 )
    {
      v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 16 * NumSeq_Internal);
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v7;
    }
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_FirstFree = -1;
    activityNames.m_Elements.m_Tree.m_pElements = v7;
    activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    while ( 1 )
    {
      v8 = v4->numincludemodels == 0;
      j = v5;
      v9 = v8 ? v4->numlocalseq : studiohdr_t::GetNumSeq_Internal(this: v4);
      if ( v5 >= v9 )
        break;
      if ( v4->numincludemodels != 0 )
      {
        v11 = studiohdr_t::pSeqdesc_Internal(this: v4, i: v5);
      }
      else
      {
        v10 = v5;
        if ( v5 < 0 || v5 >= v4->numlocalseq )
          v10 = 0;
        v11 = (mstudioseqdesc_t *)((char *)v4 + 212 * v10 + v4->localseqindex);
      }
      if ( (v11->flags & 0x400) == 0 )
      {
        if ( v4->numincludemodels != 0 )
        {
          v13 = studiohdr_t::pSeqdesc_Internal(this: v4, i: v5);
        }
        else
        {
          v12 = v5;
          if ( v5 < 0 || v5 >= v4->numlocalseq )
            v12 = 0;
          v13 = (mstudioseqdesc_t *)((char *)v4 + 212 * v12 + v4->localseqindex);
        }
        v14 = (char *)v13 + v13->szactivitynameindex;
        if ( v14 != nullptr && *v14 != 0 )
        {
          search.key = (char *)v13 + v13->szactivitynameindex;
          if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                 this: &activityNames.m_Elements.m_Tree,
                 &search) == 0xFFFF )
          {
            CUtlString::CUtlString(this: &src, pString: v14);
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
              this: pOutList,
              elem: pOutList->m_Size,
              &src);
            src.m_Storage.m_nActualLength = 0;
            if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                src.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              src.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
            CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v14, element: &j);
          }
        }
      }
      ++v5;
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
// Address: 0x004A8940
// Name: public: virtual void CDmeMatSysMPPDag::GetActivityList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::GetActivityList(
        CDmeMatSysMPPDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  CDmElement *v3; // eax
  CDmeSequenceList *Value; // eax
  int m_Size; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v6; // eax
  int v7; // edi
  const char *v8; // esi
  CUtlDict<int,unsigned short> activityNames; // [esp+4h] [ebp-4Ch] BYREF
  CUtlVector<CDmeSequenceBase *,CUtlMemory<CDmeSequenceBase *,int> > sortedSequenceList; // [esp+20h] [ebp-30h] BYREF
  CUtlString src; // [esp+34h] [ebp-1Ch] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+44h] [ebp-Ch] BYREF
  int i; // [esp+4Ch] [ebp-4h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: pOutList);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eMppRoot.m_Storage.m_Handle) != 0 )
  {
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_eMppRoot.m_Storage.m_Handle);
    Value = CDmElement::GetValueElement<CDmeSequenceList>(this: v3, pAttributeName: "sequenceList");
    if ( Value != nullptr )
    {
      memset(&sortedSequenceList, 0, sizeof(sortedSequenceList));
      CDmeSequenceList::GetSortedSequenceList(
        this: Value,
        (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&sortedSequenceList);
      m_Size = sortedSequenceList.m_Size;
      v6 = nullptr;
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
      activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = sortedSequenceList.m_Size;
      activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
      if ( sortedSequenceList.m_Size != 0 )
      {
        v6 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                   this: _g_pMemAlloc,
                                                                                                   a2: 16
                                                                                                 * sortedSequenceList.m_Size);
        m_Size = sortedSequenceList.m_Size;
        activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v6;
      }
      activityNames.m_Elements.m_Tree.m_Root = -1;
      activityNames.m_Elements.m_Tree.m_NumElements = 0;
      v7 = 0;
      activityNames.m_Elements.m_Tree.m_FirstFree = -1;
      activityNames.m_Elements.m_Tree.m_LastAlloc.index = -1;
      activityNames.m_Elements.m_Tree.m_pElements = v6;
      activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
      i = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v8 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: sortedSequenceList.m_Memory.m_pMemory[v7]->m_eActivity.m_Storage.m_Handle)
                              + 20);
          if ( v8 != (const char *)-1 && v8 != nullptr && *v8 != 0 )
          {
            search.key = v8;
            if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                   this: &activityNames.m_Elements.m_Tree,
                   &search) == 0xFFFF )
            {
              CUtlString::CUtlString(this: &src, pString: v8);
              CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
                this: pOutList,
                elem: pOutList->m_Size,
                &src);
              src.m_Storage.m_nActualLength = 0;
              if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
              {
                if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
                {
                  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                  src.m_Storage.m_Memory.m_pMemory = nullptr;
                }
                src.m_Storage.m_Memory.m_nAllocationCount = 0;
              }
              CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v8, element: &i);
            }
          }
          i = ++v7;
        }
        while ( v7 < sortedSequenceList.m_Size );
      }
      CUtlDict<int,unsigned short>::RemoveAll(this: &activityNames);
      CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &activityNames.m_Elements.m_Tree);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedSequenceList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A8AD0
// Name: protected: CDmeMatSysRoot::CDmeMatSysRoot(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysRoot *__thiscall CDmeMatSysRoot::CDmeMatSysRoot(
        CDmeMatSysRoot *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMatSysRoot_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeMatSysRoot_vtbl *)&CDmeMatSysRoot::`vftable';
  this->m_Settings.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Settings.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Settings.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A8B50
// Name: public: virtual bool CDmeMatSysRoot::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysRoot::IsA(CDmeMatSysRoot *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysRoot::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A8B80
// Name: public: virtual int CDmeMatSysRoot::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysRoot::GetInheritanceDepth(CDmeMatSysRoot *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysRoot::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A8BD0
// Name: protected: virtual int CDmeMatSysRoot::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysRoot::AllocatedSize(CDmeTrackGroup *this)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x004A8BE0
// Name: protected: virtual void CDmeMatSysRoot::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysRoot::PerformConstruction(CDmeMatSysRoot *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmaElement<CDmeMatSysPanelSettings>::InitAndCreate(
    this: &this->m_Settings,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"settings",
    pElementName: nullptr,
    flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004A8C50
// Name: protected: CDmeMatSysMDLDag::CDmeMatSysMDLDag(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysMDLDag *__thiscall CDmeMatSysMDLDag::CDmeMatSysMDLDag(
        CDmeMatSysMDLDag *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMDLDag_vtbl *)&IDmeMatSysModel::`vftable';
  CDmElement::CDmElement(this: &this->CDmeDag, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMDLDag_vtbl *)&CDmeMatSysMDLDag::`vftable'{for `IDmeMatSysModel'};
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeMatSysMDLDag::`vftable'{for `CDmeDag'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A8CD0
// Name: public: virtual bool CDmeMatSysMDLDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysMDLDag::IsA(CDmeMatSysMDLDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysMDLDag::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A8D00
// Name: public: virtual int CDmeMatSysMDLDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMDLDag::GetInheritanceDepth(CDmeMatSysMDLDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysMDLDag::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A8D50
// Name: protected: virtual void CDmeMatSysMDLDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::PerformConstruction(CDmeMatSysMDLDag *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction((CDmeDag *)this);
  CDmeMatSysMDLDag::OnConstruction(this: (CDmeMatSysMDLDag *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x004A8DC0
// Name: protected: CDmeMatSysDMXDag::CDmeMatSysDMXDag(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysDMXDag *__thiscall CDmeMatSysDMXDag::CDmeMatSysDMXDag(
        CDmeMatSysDMXDag *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->IDmeMatSysModel::__vftable = (CDmeMatSysDMXDag_vtbl *)&IDmeMatSysModel::`vftable';
  CDmElement::CDmElement(this: &this->CDmeDag, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->IDmeMatSysModel::__vftable = (CDmeMatSysDMXDag_vtbl *)&CDmeMatSysDMXDag::`vftable'{for `IDmeMatSysModel'};
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeMatSysDMXDag::`vftable'{for `CDmeDag'};
  this->m_eDmxRoot.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eDmxRoot.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eDmxRoot.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A8E60
// Name: public: virtual bool CDmeMatSysDMXDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysDMXDag::IsA(CDmeMatSysDMXDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysDMXDag::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A8E90
// Name: public: virtual int CDmeMatSysDMXDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysDMXDag::GetInheritanceDepth(CDmeMatSysDMXDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysDMXDag::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A8EE0
// Name: protected: virtual void CDmeMatSysDMXDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysDMXDag::PerformConstruction(CDmeMatSysDMXDag *this)
{
  bool v2; // zf
  CDmeMatSysDMXDag *v3; // esi
  CDmElement *v4; // ecx
  CDmAttribute *v5; // eax
  DmElementHandle_t value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction((CDmeDag *)this);
  v2 = this == (CDmeMatSysDMXDag *)4;
  v3 = (CDmeMatSysDMXDag *)((char *)this - 4);
  value = DMELEMENT_HANDLE_INVALID;
  if ( v2 )
    v4 = nullptr;
  else
    v4 = &v3->CDmeDag;
  v5 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "dmxRoot",
         type: AT_FIRST_VALUE_TYPE,
         pMemory: &v3->m_eDmxRoot);
  v3->m_eDmxRoot.m_pAttribute = v5;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: v5, &value);
  v3->m_hDmxModel = DMELEMENT_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x004A8F90
// Name: protected: CDmeMatSysMPPDag::CDmeMatSysMPPDag(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysMPPDag *__thiscall CDmeMatSysMPPDag::CDmeMatSysMPPDag(
        CDmeMatSysMPPDag *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMPPDag_vtbl *)&IDmeMatSysModel::`vftable';
  CDmElement::CDmElement(this: &this->CDmeDag, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMPPDag_vtbl *)&CDmeMatSysMPPDag::`vftable'{for `IDmeMatSysModel'};
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeMatSysMPPDag::`vftable'{for `CDmeDag'};
  this->m_eMppRoot.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eMppRoot.m_pAttribute = nullptr;
  this->m_eMppRoot.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_hChildren.m_Memory.m_pMemory = nullptr;
  this->m_hChildren.m_Memory.m_nAllocationCount = 0;
  this->m_hChildren.m_Memory.m_nGrowSize = 0;
  this->m_hChildren.m_Size = 0;
  this->m_hChildren.m_pElements = nullptr;
  this->m_dmeOperatorList.m_Memory.m_pMemory = nullptr;
  this->m_dmeOperatorList.m_Memory.m_nAllocationCount = 0;
  this->m_dmeOperatorList.m_Memory.m_nGrowSize = 0;
  this->m_dmeOperatorList.m_Size = 0;
  this->m_dmeOperatorList.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A9070
// Name: public: virtual bool CDmeMatSysMPPDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysMPPDag::IsA(CDmeMatSysMPPDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysMPPDag::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A90A0
// Name: public: virtual int CDmeMatSysMPPDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMPPDag::GetInheritanceDepth(CDmeMatSysMPPDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysMPPDag::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A90F0
// Name: protected: virtual int CDmeMatSysMPPDag::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMPPDag::AllocatedSize(CDmeLog *this)
{
  return 204;
}

//------------------------------------------------------------------------------
// Address: 0x004A9100
// Name: protected: virtual void CDmeMatSysMPPDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::PerformConstruction(CDmeMatSysMPPDag *this)
{
  bool v2; // zf
  CDmeMatSysMPPDag *v3; // esi
  CDmElement *v4; // ecx
  CDmAttribute *v5; // eax
  DmElementHandle_t value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction((CDmeDag *)this);
  v2 = this == (CDmeMatSysMPPDag *)4;
  v3 = (CDmeMatSysMPPDag *)((char *)this - 4);
  value = DMELEMENT_HANDLE_INVALID;
  if ( v2 )
    v4 = nullptr;
  else
    v4 = &v3->CDmeDag;
  v5 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "mppRoot",
         type: AT_FIRST_VALUE_TYPE,
         pMemory: &v3->m_eMppRoot);
  v3->m_eMppRoot.m_pAttribute = v5;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: v5, &value);
  v3->m_hDmeBodyGroupList = DMELEMENT_HANDLE_INVALID;
  v3->m_hDmeSequenceList = DMELEMENT_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0056B160
// Name: protected: virtual int CDmeMatSysDMXDag::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysDMXDag::AllocatedSize(CDmeTimeSelection *this)
{
  return 156;
}

//------------------------------------------------------------------------------
// Address: 0x0059A260
// Name: _dynamic_initializer_for__CDmeMatSysPanelSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysPanelSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysPanelSettings::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysPanelSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysPanelSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A2C0
// Name: _dynamic_initializer_for__CDmeMatSysRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysRoot::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysRoot::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysRoot pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysRoot::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A320
// Name: _dynamic_initializer_for__CDmeMatSysMDLDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysMDLDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysMDLDag::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysMDLDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysMDLDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A380
// Name: _dynamic_initializer_for__CDmeMatSysDMXDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysDMXDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysDMXDag::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysDMXDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysDMXDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A3E0
// Name: _dynamic_initializer_for__CDmeMatSysMPPDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysMPPDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysMPPDag::s_Allocator,
    blockSize: 204,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysMPPDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysMPPDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E880
// Name: _dynamic_atexit_destructor_for__CDmeMatSysPanelSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysPanelSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysPanelSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E890
// Name: _dynamic_atexit_destructor_for__CDmeMatSysRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysRoot::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysRoot::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E8A0
// Name: _dynamic_atexit_destructor_for__CDmeMatSysMDLDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysMDLDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysMDLDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E8B0
// Name: _dynamic_atexit_destructor_for__CDmeMatSysDMXDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysDMXDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysDMXDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E8C0
// Name: _dynamic_atexit_destructor_for__CDmeMatSysMPPDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysMPPDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysMPPDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004A7860
// Name: class CDmeSequence __near * CastElement<class CDmeSequence>(class CDmElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequence *__cdecl CastElement<CDmeSequence>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeSequence::m_classType.u.m_Id) )
  {
    return (CDmeSequence *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0059A290
// Name: _dynamic_initializer_for__g_CDmeMatSysPanelSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysPanelSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysPanelSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A2A0
// Name: _dynamic_initializer_for__g_CDmeMatSysPanelSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysPanelSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysPanelSettings_Helper,
           classname: "DmeMatSysPanelSettings",
           pFactory: &g_CDmeMatSysPanelSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A2F0
// Name: _dynamic_initializer_for__g_CDmeMatSysRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysRoot_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysRoot_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A300
// Name: _dynamic_initializer_for__g_CDmeMatSysRoot_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysRoot_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysRoot_Helper,
           classname: "DmeMatSysRoot",
           pFactory: &g_CDmeMatSysRoot_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A350
// Name: _dynamic_initializer_for__g_CDmeMatSysMDLDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysMDLDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysMDLDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A360
// Name: _dynamic_initializer_for__g_CDmeMatSysMDLDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysMDLDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysMDLDag_Helper,
           classname: "DmeMatSysMDLDag",
           pFactory: &g_CDmeMatSysMDLDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A3B0
// Name: _dynamic_initializer_for__g_CDmeMatSysDMXDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysDMXDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysDMXDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A3C0
// Name: _dynamic_initializer_for__g_CDmeMatSysDMXDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysDMXDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysDMXDag_Helper,
           classname: "DmeMatSysDMXDag",
           pFactory: &g_CDmeMatSysDMXDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A410
// Name: _dynamic_initializer_for__g_CDmeMatSysMPPDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysMPPDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysMPPDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A420
// Name: _dynamic_initializer_for__g_CDmeMatSysMPPDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysMPPDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysMPPDag_Helper,
           classname: "DmeMatSysMPPDag",
           pFactory: &g_CDmeMatSysMPPDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E8D0
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysRoot_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysRoot_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E8E0
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysMDLDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysMDLDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysMDLDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E8F0
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysDMXDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysDMXDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysDMXDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E900
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysMPPDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysMPPDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysMPPDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E910
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysPanelSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysPanelSettings_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysPanelSettings_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004ED0F0
// Name: private: virtual int IDmeMatSysModel::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IDmeMatSysModel::SelectSequence(IDmeMatSysModel *this, const char *pszSequenceName)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ED100
// Name: public: virtual void CDmeMatSysMPPDag::SetFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::SetFrame(CDmeMatSysMPPDag *this, float flFrame)
{
  int v3; // eax

  v3 = DmeTime_t::RoundSecondsToTMS(sec: COERCE_UNSIGNED_INT(flFrame * 0.033333335));
  ((void (__thiscall *)(CDmeMatSysMPPDag *, int))this->SetTime)(a1: this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004ED130
// Name: public: CMatRenderContextPtr::~CMatRenderContextPtr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextPtr::~CMatRenderContextPtr(CMatRenderContextPtr *this)
{
  IMatRenderContext *m_pObject; // ecx

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    if ( this->m_pObject != nullptr )
      this->m_pObject->Release(this: this->m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ED1F0
// Name: public: CMatRenderContextPtr::CMatRenderContextPtr(class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CMatRenderContextPtr *__thiscall CMatRenderContextPtr::CMatRenderContextPtr(
        CMatRenderContextPtr *this,
        IMaterialSystem *pFrom)
{
  IMatRenderContext *v3; // eax

  v3 = pFrom->GetRenderContext(this: pFrom);
  this->m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004ED220
// Name: protected: void CDmeMatSysPanelSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysPanelSettings::OnConstruction(CDmeMatSysPanelSettings *this)
{
  CDmaVar<Color> *p_m_cBackgroundColor; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v8; // [esp+13h] [ebp-1h] BYREF

  p_m_cBackgroundColor = &this->m_cBackgroundColor;
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backgroundColor",
         type: AT_COLOR,
         pMemory: &this->m_cBackgroundColor);
  p_m_cBackgroundColor->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "ambientColor",
         type: AT_COLOR,
         pMemory: &this->m_cAmbientColor);
  this->m_cAmbientColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v8 = true;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "drawGroundPlane",
         type: AT_BOOL,
         pMemory: &this->m_bDrawGroundPlane);
  this->m_bDrawGroundPlane.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v8);
  v8 = true;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "drawOriginAxis",
         type: AT_BOOL,
         pMemory: &this->m_bDrawOriginAxis);
  this->m_bDrawOriginAxis.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v8);
}

//------------------------------------------------------------------------------
// Address: 0x004ED2D0
// Name: public: virtual void CDmeMatSysMPPDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMatSysMPPDag::Draw(CDmeMatSysMPPDag *this@<ecx>, int a2@<esi>, CDmeDrawSettings *pDrawSettings)
{
  int v4; // esi

  if ( *((_BYTE *)&this->CDmElement + 64) != 0 )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 160))(a1: v4, a2: 1);
    CDmeDag::Draw((CDmeDag *)this, pDrawSettings);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 160))(a1: v4, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ED340
// Name: public: struct studiohdr_t __near * CDmeMatSysMDLDag::GetStudioHdr(void)const
// Source: json
//------------------------------------------------------------------------------
studiohdr_t *__thiscall CDmeMatSysMDLDag::GetStudioHdr(CDmeMatSysMDLDag *this)
{
  int v1; // eax
  CDmeMDL *v2; // esi
  unsigned __int16 MDL; // ax
  int v4; // esi

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v2 = (CDmeMDL *)v1;
  if ( v1 == 0 )
    return nullptr;
  if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmeMDL::m_classType.u) == 0 )
    return nullptr;
  MDL = CDmeMDL::GetMDL(this: v2);
  v4 = MDL;
  if ( MDL == 0xFFFF || g_pMDLCache->IsErrorModel(this: g_pMDLCache, a2: MDL) )
    return nullptr;
  else
    return g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004ED3B0
// Name: public: virtual void CDmeMatSysMDLDag::SetTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::SetTime(CDmeMatSysMDLDag *this, DmeTime_t dmeTime)
{
  int v2; // eax
  int v3; // esi
  CDmAttribute *v4; // ecx
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v4 = *(CDmAttribute **)(v3 + 128);
    value = (float)dmeTime.m_tms * 0.000099999997;
    CDmAttribute::SetValue<float>(this: v4, &value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ED410
// Name: public: virtual void CDmeMatSysMDLDag::SetFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::SetFrame(CDmeMatSysMDLDag *this, float flFrame)
{
  int v2; // eax
  int v3; // esi
  CDmAttribute *v4; // ecx

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v4 = *(CDmAttribute **)(v3 + 128);
    flFrame = flFrame / *(float *)(v3 + 116);
    CDmAttribute::SetValue<float>(this: v4, value: &flFrame);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ED470
// Name: protected: void CDmeMatSysMDLDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::OnConstruction(CDmeMatSysMDLDag *this)
{
  const char *m_pAsString; // eax
  DmFileId_t m_fileId; // esi
  CUtlString *v4; // eax
  CUtlString *v5; // eax
  const char *v6; // eax
  int v7; // eax
  int v8; // eax
  CDmeMDL *v9; // esi
  CUtlString v10; // [esp+Ch] [ebp-20h] BYREF
  CUtlString result; // [esp+1Ch] [ebp-10h] BYREF

  m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
  m_fileId = this->m_fileId;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  v4 = CUtlString::CUtlString(this: &v10, pString: m_pAsString);
  v5 = CUtlString::operator+(this: v4, &result, pOther: "Shape");
  v6 = CUtlString::operator char const *(this: v5);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeMDL::m_classType.u,
         a3: v6,
         a4: m_fileId,
         a5: 0);
  v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v7);
  v9 = (CDmeMDL *)v8;
  if ( v8 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
         a1: v8,
         a2: CDmeMDL::m_classType.u) == 0 )
  {
    v9 = nullptr;
  }
  result.m_Storage.m_nActualLength = 0;
  if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( result.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
      result.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    result.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v10.m_Storage.m_nActualLength = 0;
  if ( v10.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v10.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10.m_Storage.m_Memory.m_pMemory);
      v10.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v10.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( v9 != nullptr )
  {
    CDmeMDL::DrawInEngine(this: v9, bDrawInEngine: true);
    CDmeDag::SetShape(this: &this->CDmeDag, pShape: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ED560
// Name: public: virtual void CDmeMatSysMPPDag::SetTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::SetTime(CDmeMatSysMPPDag *this, DmeTime_t dmeTime)
{
  int v3; // eax
  CDmeSequence *v4; // esi
  CDmeDag *v5; // ebx
  CDmeDag **m_pMemory; // edi
  int m_Size; // esi
  CDmeDag *v8; // ecx
  int i; // ebx
  CDmeDag *v10; // ebx
  const char *m_pAsString; // eax
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > depthFirstStack; // [esp+Ch] [ebp-1Ch] BYREF
  CDmeDag *Child; // [esp+20h] [ebp-8h]
  CDmeDag *pDmeDag; // [esp+24h] [ebp-4h]

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hDmeSequence);
  v4 = (CDmeSequence *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeSequence::m_classType.u) != 0 )
  {
    CDmeSequence::UpdateChannels(this: v4, dmeOperatorList: &this->m_dmeOperatorList, nClipTime: dmeTime);
    memset(&depthFirstStack, 0, sizeof(depthFirstStack));
    v5 = &this->CDmeDag;
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depthFirstStack,
      num: 1);
    m_pMemory = depthFirstStack.m_Memory.m_pMemory;
    m_Size = depthFirstStack.m_Size + 1;
    depthFirstStack.m_pElements = depthFirstStack.m_Memory.m_pMemory;
    if ( &depthFirstStack.m_Memory.m_pMemory[depthFirstStack.m_Size + 1] != (CDmeDag **)4 )
      depthFirstStack.m_Memory.m_pMemory[depthFirstStack.m_Size] = v5;
    while ( m_Size > 0 )
    {
      v8 = m_pMemory[--m_Size];
      pDmeDag = v8;
      depthFirstStack.m_Size = m_Size;
      if ( v8 != nullptr )
      {
        for ( i = CDmElementFramework::GetPhase(this: v8) - 1; i >= 0; --i )
        {
          Child = CDmeDag::GetChild(this: pDmeDag, i);
          if ( m_Size >= depthFirstStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depthFirstStack,
              num: 1);
            m_Size = depthFirstStack.m_Size;
            m_pMemory = depthFirstStack.m_Memory.m_pMemory;
          }
          depthFirstStack.m_Size = ++m_Size;
          depthFirstStack.m_pElements = m_pMemory;
          if ( &m_pMemory[m_Size] != (CDmeDag **)4 )
            m_pMemory[m_Size - 1] = Child;
        }
        v10 = pDmeDag;
        m_pAsString = pDmeDag->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = pDeltaStateName;
        if ( _V_stricmp(s1: m_pAsString, s2: "root") == 0 )
          CDmeDag::GetTransform(this: v10);
      }
    }
    if ( depthFirstStack.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ED6A0
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneParent);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneFlags);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x004ED6D0
// Name: public: virtual int CDmeMatSysMDLDag::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMDLDag::SelectSequence(CDmeMatSysMDLDag *this, const char *pszSequenceName)
{
  int v3; // eax
  int v4; // esi
  int v5; // ebx
  studiohdr_t *StudioHdr; // esi
  CDmAttribute *v7; // ecx
  int j; // eax
  bool v9; // zf
  int numlocalseq; // ecx
  mstudioseqdesc_t *v11; // eax
  CDmAttribute *v12; // ecx
  int v14; // esi
  float flPoseParameter[24]; // [esp+Ch] [ebp-C8h] BYREF
  CStudioHdr cStudioHdr; // [esp+6Ch] [ebp-68h] BYREF
  int i; // [esp+D0h] [ebp-4h] BYREF

  if ( pszSequenceName == nullptr || *pszSequenceName == 0 )
    return -1;
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v4 = v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  StudioHdr = CDmeMatSysMDLDag::GetStudioHdr(this);
  if ( StudioHdr == nullptr )
    return -1;
  v7 = *(CDmAttribute **)(v5 + 104);
  i = -1;
  CDmAttribute::SetValue<int>(this: v7, value: &i);
  for ( j = 0; ; j = i + 1 )
  {
    v9 = StudioHdr->numincludemodels == 0;
    i = j;
    if ( v9 )
    {
      numlocalseq = StudioHdr->numlocalseq;
    }
    else
    {
      numlocalseq = studiohdr_t::GetNumSeq_Internal(this: StudioHdr);
      j = i;
    }
    if ( j >= numlocalseq )
      break;
    if ( StudioHdr->numincludemodels != 0 )
    {
      v11 = studiohdr_t::pSeqdesc_Internal(this: StudioHdr, i: j);
    }
    else
    {
      if ( j < 0 || j >= StudioHdr->numlocalseq )
        j = 0;
      v11 = (mstudioseqdesc_t *)((char *)StudioHdr + 212 * j + StudioHdr->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v11 + v11->szlabelindex, s2: pszSequenceName) == 0 )
    {
      CDmAttribute::SetValue<int>(this: *(CDmAttribute **)(v5 + 104), value: &i);
      break;
    }
  }
  if ( *(int *)(v5 + 100) < 0 )
  {
    v12 = *(CDmAttribute **)(v5 + 104);
    pszSequenceName = nullptr;
    CDmAttribute::SetValue<int>(this: v12, value: (int *)&pszSequenceName);
    return -1;
  }
  CStudioHdr::CStudioHdr(this: &cStudioHdr, pStudioHdr: StudioHdr, mdlcache: g_pMDLCache);
  Studio_CalcDefaultPoseParameters(pStudioHdr: &cStudioHdr, flPoseParameter, nCount: 24);
  v14 = Studio_MaxFrame(pStudioHdr: &cStudioHdr, iSequence: *(_DWORD *)(v5 + 100), poseParameter: flPoseParameter);
  if ( v14 == 0 )
    v14 = 1;
  CStudioHdr::Term(this: &cStudioHdr);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&cStudioHdr.m_boneParent);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&cStudioHdr.m_boneFlags);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&cStudioHdr.m_pStudioHdrCache);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x004ED860
// Name: public: virtual int CDmeMatSysMPPDag::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMPPDag::SelectSequence(CDmeMatSysMPPDag *this, const char *pszSequenceName)
{
  int v3; // ebx
  CDmElement *v4; // eax
  CDmeSequenceList *Value; // eax
  CDmeSequenceList *v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CExpressionCalculator *v10; // eax
  CDmeSequence *v11; // esi
  DmeFramerate_t v13; // ecx
  CDmeChannelsClip *FrameCount; // esi
  DmeFramerate_t v15; // [esp-8h] [ebp-30h] BYREF
  int v16; // [esp-4h] [ebp-2Ch]
  CUtlVector<CDmeSequenceBase *,CUtlMemory<CDmeSequenceBase *,int> > sortedSequenceList; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *dmeOperatorList; // [esp+20h] [ebp-8h]
  CDmeMatSysMPPDag *v19; // [esp+24h] [ebp-4h]

  v3 = 0;
  this->m_hDmeSequence = DMELEMENT_HANDLE_INVALID;
  dmeOperatorList = &this->m_dmeOperatorList;
  this->m_dmeOperatorList.m_Size = 0;
  v19 = this;
  if ( pszSequenceName == nullptr )
    return -1;
  if ( *pszSequenceName == 0 )
    return -1;
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eMppRoot.m_Storage.m_Handle) == 0 )
    return -1;
  v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_eMppRoot.m_Storage.m_Handle);
  Value = CDmElement::GetValueElement<CDmeSequenceList>(this: v4, pAttributeName: "sequenceList");
  v6 = Value;
  if ( Value == nullptr )
    return -1;
  memset(&sortedSequenceList, 0, sizeof(sortedSequenceList));
  if ( Value->m_Sequences.m_Storage.m_Size <= 0 )
  {
LABEL_13:
    CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedSequenceList);
    return -1;
  }
  while ( 1 )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v6->m_Sequences.m_Storage.m_Memory.m_pMemory[v3]);
    v8 = (CDmElement *)v7;
    if ( v7 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmeSequenceBase::m_classType.u) != 0 )
    {
      m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      if ( _V_stricmp(s1: pszSequenceName, s2: m_pAsString) == 0 )
      {
        v10 = (CExpressionCalculator *)CastElement<CDmeSequence>(pElement: v8);
        v11 = (CDmeSequence *)v10;
        if ( v10 != nullptr )
          break;
      }
    }
    if ( ++v3 >= v6->m_Sequences.m_Storage.m_Size )
      goto LABEL_13;
  }
  v19->m_hDmeSequence = CExpressionCalculator::VariableCount(this: v10);
  CDmeSequence::PrepareChannels(this: v11, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)dmeOperatorList);
  v16 = 0;
  v15 = v13;
  DmeFramerate_t::DmeFramerate_t(this: &v15, fps: 0x1Eu);
  FrameCount = CDmeSequence::GetFrameCount(this: v11, fallbackFrameRate: v15, bForceFallback: v16);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedSequenceList);
  return (int)FrameCount;
}

//------------------------------------------------------------------------------
// Address: 0x004ED9B0
// Name: public: virtual void CDmeMatSysMDLDag::GetSequenceList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::GetSequenceList(
        CDmeMatSysMDLDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  studiohdr_t *StudioHdr; // esi
  int i; // edi
  int v5; // eax
  int v6; // eax
  mstudioseqdesc_t *v7; // eax
  int v8; // eax
  mstudioseqdesc_t *v9; // eax
  const char *v10; // ecx
  CUtlString src; // [esp+8h] [ebp-10h] BYREF

  if ( pOutList != nullptr )
  {
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)pOutList);
    StudioHdr = CDmeMatSysMDLDag::GetStudioHdr(this);
    if ( StudioHdr != nullptr )
    {
      for ( i = 0; ; ++i )
      {
        v5 = StudioHdr->numincludemodels != 0
           ? studiohdr_t::GetNumSeq_Internal(this: StudioHdr)
           : StudioHdr->numlocalseq;
        if ( i >= v5 )
          break;
        if ( StudioHdr->numincludemodels != 0 )
        {
          v7 = studiohdr_t::pSeqdesc_Internal(this: StudioHdr, i);
        }
        else
        {
          v6 = i;
          if ( i < 0 || i >= StudioHdr->numlocalseq )
            v6 = 0;
          v7 = (mstudioseqdesc_t *)((char *)StudioHdr + 212 * v6 + StudioHdr->localseqindex);
        }
        if ( (v7->flags & 0x400) == 0 )
        {
          if ( StudioHdr->numincludemodels != 0 )
          {
            v9 = studiohdr_t::pSeqdesc_Internal(this: StudioHdr, i);
          }
          else
          {
            v8 = i;
            if ( i < 0 || i >= StudioHdr->numlocalseq )
              v8 = 0;
            v9 = (mstudioseqdesc_t *)((char *)StudioHdr + 212 * v8 + StudioHdr->localseqindex);
          }
          v10 = (char *)v9 + v9->szlabelindex;
          if ( v10 != nullptr && *v10 != 0 )
          {
            CUtlString::CUtlString(this: &src, pString: v10);
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
              this: pOutList,
              elem: pOutList->m_Size,
              &src);
            src.m_Storage.m_nActualLength = 0;
            if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                src.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              src.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EDAD0
// Name: public: virtual void CDmeMatSysMPPDag::GetSequenceList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::GetSequenceList(
        CDmeMatSysMPPDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  CDmElement *v3; // eax
  CDmeSequenceList *Value; // eax
  int v5; // ebx
  const char *m_pAsString; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v10; // eax
  CUtlString *v11; // ecx
  CUtlVector<CDmeSequenceBase *,CUtlMemory<CDmeSequenceBase *,int> > sortedSequenceList; // [esp+8h] [ebp-24h] BYREF
  CUtlString string; // [esp+1Ch] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)pOutList);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eMppRoot.m_Storage.m_Handle) != 0 )
  {
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_eMppRoot.m_Storage.m_Handle);
    Value = CDmElement::GetValueElement<CDmeSequenceList>(this: v3, pAttributeName: "sequenceList");
    v5 = 0;
    if ( Value != nullptr )
    {
      memset(&sortedSequenceList, 0, sizeof(sortedSequenceList));
      CDmeSequenceList::GetSortedSequenceList(
        this: Value,
        (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&sortedSequenceList);
      if ( sortedSequenceList.m_Size > 0 )
      {
        do
        {
          m_pAsString = sortedSequenceList.m_Memory.m_pMemory[v5]->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = pDeltaStateName;
          CUtlString::CUtlString(this: &string, pString: m_pAsString);
          m_Size = pOutList->m_Size;
          m_nAllocationCount = pOutList->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)pOutList,
              num: m_Size - m_nAllocationCount + 1);
          ++pOutList->m_Size;
          m_pMemory = pOutList->m_Memory.m_pMemory;
          v10 = pOutList->m_Size - m_Size - 1;
          pOutList->m_pElements = pOutList->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v10);
          v11 = &pOutList->m_Memory.m_pMemory[m_Size];
          if ( v11 != nullptr )
            CUtlString::CUtlString(this: v11, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          ++v5;
        }
        while ( v5 < sortedSequenceList.m_Size );
      }
      CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedSequenceList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EDCA0
// Name: public: virtual bool CDmeMatSysPanelSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysPanelSettings::IsA(CDmeMatSysPanelSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysPanelSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EDCD0
// Name: public: virtual int CDmeMatSysPanelSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysPanelSettings::GetInheritanceDepth(CDmeMatSysPanelSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysPanelSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EDD90
// Name: protected: virtual void CDmeMatSysPanelSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysPanelSettings::PerformConstruction(CDmeMatSysPanelSettings *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMatSysPanelSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004EDF20
// Name: public: virtual void CDmeMatSysMDLDag::GetActivityList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::GetActivityList(
        CDmeMatSysMDLDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  studiohdr_t *StudioHdr; // eax
  studiohdr_t *v4; // esi
  int v5; // ebx
  int NumSeq_Internal; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v7; // ecx
  bool v8; // zf
  int v9; // eax
  int v10; // eax
  mstudioseqdesc_t *v11; // eax
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  const char *v14; // edi
  CUtlDict<int,unsigned short> activityNames; // [esp+8h] [ebp-38h] BYREF
  CUtlString src; // [esp+24h] [ebp-1Ch] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+34h] [ebp-Ch] BYREF
  int j; // [esp+3Ch] [ebp-4h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)pOutList);
  StudioHdr = CDmeMatSysMDLDag::GetStudioHdr(this);
  v4 = StudioHdr;
  v5 = 0;
  if ( StudioHdr != nullptr )
  {
    if ( StudioHdr->numincludemodels != 0 )
      NumSeq_Internal = studiohdr_t::GetNumSeq_Internal(this: StudioHdr);
    else
      NumSeq_Internal = StudioHdr->numlocalseq;
    v7 = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = NumSeq_Internal;
    activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    if ( NumSeq_Internal != 0 )
    {
      v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 16 * NumSeq_Internal);
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v7;
    }
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_FirstFree = -1;
    activityNames.m_Elements.m_Tree.m_pElements = v7;
    activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    while ( 1 )
    {
      v8 = v4->numincludemodels == 0;
      j = v5;
      v9 = v8 ? v4->numlocalseq : studiohdr_t::GetNumSeq_Internal(this: v4);
      if ( v5 >= v9 )
        break;
      if ( v4->numincludemodels != 0 )
      {
        v11 = studiohdr_t::pSeqdesc_Internal(this: v4, i: v5);
      }
      else
      {
        v10 = v5;
        if ( v5 < 0 || v5 >= v4->numlocalseq )
          v10 = 0;
        v11 = (mstudioseqdesc_t *)((char *)v4 + 212 * v10 + v4->localseqindex);
      }
      if ( (v11->flags & 0x400) == 0 )
      {
        if ( v4->numincludemodels != 0 )
        {
          v13 = studiohdr_t::pSeqdesc_Internal(this: v4, i: v5);
        }
        else
        {
          v12 = v5;
          if ( v5 < 0 || v5 >= v4->numlocalseq )
            v12 = 0;
          v13 = (mstudioseqdesc_t *)((char *)v4 + 212 * v12 + v4->localseqindex);
        }
        v14 = (char *)v13 + v13->szactivitynameindex;
        if ( v14 != nullptr && *v14 != 0 )
        {
          search.key = (char *)v13 + v13->szactivitynameindex;
          if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                 this: &activityNames.m_Elements.m_Tree,
                 &search) == 0xFFFF )
          {
            CUtlString::CUtlString(this: &src, pString: v14);
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
              this: pOutList,
              elem: pOutList->m_Size,
              &src);
            src.m_Storage.m_nActualLength = 0;
            if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                src.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              src.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
            CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v14, element: &j);
          }
        }
      }
      ++v5;
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
// Address: 0x004EE100
// Name: public: virtual void CDmeMatSysMPPDag::GetActivityList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::GetActivityList(
        CDmeMatSysMPPDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  CDmElement *v3; // eax
  CDmeSequenceList *Value; // eax
  int m_Size; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v6; // eax
  int v7; // edi
  const char *v8; // esi
  CUtlDict<int,unsigned short> activityNames; // [esp+4h] [ebp-4Ch] BYREF
  CUtlVector<CDmeSequenceBase *,CUtlMemory<CDmeSequenceBase *,int> > sortedSequenceList; // [esp+20h] [ebp-30h] BYREF
  CUtlString src; // [esp+34h] [ebp-1Ch] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+44h] [ebp-Ch] BYREF
  int i; // [esp+4Ch] [ebp-4h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)pOutList);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eMppRoot.m_Storage.m_Handle) != 0 )
  {
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_eMppRoot.m_Storage.m_Handle);
    Value = CDmElement::GetValueElement<CDmeSequenceList>(this: v3, pAttributeName: "sequenceList");
    if ( Value != nullptr )
    {
      memset(&sortedSequenceList, 0, sizeof(sortedSequenceList));
      CDmeSequenceList::GetSortedSequenceList(
        this: Value,
        (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&sortedSequenceList);
      m_Size = sortedSequenceList.m_Size;
      v6 = nullptr;
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
      activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = sortedSequenceList.m_Size;
      activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
      if ( sortedSequenceList.m_Size != 0 )
      {
        v6 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                   this: _g_pMemAlloc,
                                                                                                   a2: 16
                                                                                                 * sortedSequenceList.m_Size);
        m_Size = sortedSequenceList.m_Size;
        activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v6;
      }
      activityNames.m_Elements.m_Tree.m_Root = -1;
      activityNames.m_Elements.m_Tree.m_NumElements = 0;
      v7 = 0;
      activityNames.m_Elements.m_Tree.m_FirstFree = -1;
      activityNames.m_Elements.m_Tree.m_LastAlloc.index = -1;
      activityNames.m_Elements.m_Tree.m_pElements = v6;
      activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
      i = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v8 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: sortedSequenceList.m_Memory.m_pMemory[v7]->m_eActivity.m_Storage.m_Handle)
                              + 20);
          if ( v8 != (const char *)-1 && v8 != nullptr && *v8 != 0 )
          {
            search.key = v8;
            if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                   this: &activityNames.m_Elements.m_Tree,
                   &search) == 0xFFFF )
            {
              CUtlString::CUtlString(this: &src, pString: v8);
              CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
                this: pOutList,
                elem: pOutList->m_Size,
                &src);
              src.m_Storage.m_nActualLength = 0;
              if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
              {
                if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
                {
                  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                  src.m_Storage.m_Memory.m_pMemory = nullptr;
                }
                src.m_Storage.m_Memory.m_nAllocationCount = 0;
              }
              CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v8, element: &i);
            }
          }
          i = ++v7;
        }
        while ( v7 < sortedSequenceList.m_Size );
      }
      CUtlDict<int,unsigned short>::RemoveAll(this: &activityNames);
      CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &activityNames.m_Elements.m_Tree);
      CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedSequenceList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EE290
// Name: protected: CDmeMatSysRoot::CDmeMatSysRoot(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysRoot *__thiscall CDmeMatSysRoot::CDmeMatSysRoot(
        CDmeMatSysRoot *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMatSysRoot_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeMatSysRoot_vtbl *)&CDmeMatSysRoot::`vftable';
  this->m_Settings.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Settings.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Settings.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EE310
// Name: public: virtual bool CDmeMatSysRoot::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysRoot::IsA(CDmeMatSysRoot *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysRoot::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EE340
// Name: public: virtual int CDmeMatSysRoot::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysRoot::GetInheritanceDepth(CDmeMatSysRoot *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysRoot::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EE390
// Name: protected: virtual int CDmeMatSysRoot::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysRoot::AllocatedSize(CDmeTrackGroup *this)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x004EE3A0
// Name: protected: virtual void CDmeMatSysRoot::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysRoot::PerformConstruction(CDmeMatSysRoot *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmaElement<CDmeMatSysPanelSettings>::InitAndCreate(
    this: &this->m_Settings,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"settings",
    pElementName: nullptr,
    flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004EE410
// Name: protected: CDmeMatSysMDLDag::CDmeMatSysMDLDag(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysMDLDag *__thiscall CDmeMatSysMDLDag::CDmeMatSysMDLDag(
        CDmeMatSysMDLDag *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMDLDag_vtbl *)&IDmeMatSysModel::`vftable';
  CDmElement::CDmElement(this: &this->CDmeDag, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMDLDag_vtbl *)&CDmeMatSysMDLDag::`vftable'{for `IDmeMatSysModel'};
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeMatSysMDLDag::`vftable'{for `CDmeDag'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EE490
// Name: public: virtual bool CDmeMatSysMDLDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysMDLDag::IsA(CDmeMatSysMDLDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysMDLDag::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EE4C0
// Name: public: virtual int CDmeMatSysMDLDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMDLDag::GetInheritanceDepth(CDmeMatSysMDLDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysMDLDag::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EE510
// Name: protected: virtual void CDmeMatSysMDLDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::PerformConstruction(CDmeMatSysMDLDag *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction((CDmeDag *)this);
  CDmeMatSysMDLDag::OnConstruction(this: (CDmeMatSysMDLDag *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x004EE580
// Name: protected: CDmeMatSysDMXDag::CDmeMatSysDMXDag(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysDMXDag *__thiscall CDmeMatSysDMXDag::CDmeMatSysDMXDag(
        CDmeMatSysDMXDag *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->IDmeMatSysModel::__vftable = (CDmeMatSysDMXDag_vtbl *)&IDmeMatSysModel::`vftable';
  CDmElement::CDmElement(this: &this->CDmeDag, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->IDmeMatSysModel::__vftable = (CDmeMatSysDMXDag_vtbl *)&CDmeMatSysDMXDag::`vftable'{for `IDmeMatSysModel'};
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeMatSysDMXDag::`vftable'{for `CDmeDag'};
  this->m_eDmxRoot.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eDmxRoot.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eDmxRoot.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EE620
// Name: public: virtual bool CDmeMatSysDMXDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysDMXDag::IsA(CDmeMatSysDMXDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysDMXDag::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EE650
// Name: public: virtual int CDmeMatSysDMXDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysDMXDag::GetInheritanceDepth(CDmeMatSysDMXDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysDMXDag::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EE6A0
// Name: protected: virtual int CDmeMatSysDMXDag::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysDMXDag::AllocatedSize(CDmeTimeSelection *this)
{
  return 156;
}

//------------------------------------------------------------------------------
// Address: 0x004EE6B0
// Name: protected: virtual void CDmeMatSysDMXDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysDMXDag::PerformConstruction(CDmeMatSysDMXDag *this)
{
  bool v2; // zf
  CDmeMatSysDMXDag *v3; // esi
  CDmElement *v4; // ecx
  CDmAttribute *v5; // eax
  DmElementHandle_t value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction((CDmeDag *)this);
  v2 = this == (CDmeMatSysDMXDag *)4;
  v3 = (CDmeMatSysDMXDag *)((char *)this - 4);
  value = DMELEMENT_HANDLE_INVALID;
  if ( v2 )
    v4 = nullptr;
  else
    v4 = &v3->CDmeDag;
  v5 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "dmxRoot",
         type: AT_FIRST_VALUE_TYPE,
         pMemory: &v3->m_eDmxRoot);
  v3->m_eDmxRoot.m_pAttribute = v5;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: v5, &value);
  v3->m_hDmxModel = DMELEMENT_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x004EE760
// Name: protected: CDmeMatSysMPPDag::CDmeMatSysMPPDag(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysMPPDag *__thiscall CDmeMatSysMPPDag::CDmeMatSysMPPDag(
        CDmeMatSysMPPDag *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMPPDag_vtbl *)&IDmeMatSysModel::`vftable';
  CDmElement::CDmElement(this: &this->CDmeDag, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMPPDag_vtbl *)&CDmeMatSysMPPDag::`vftable'{for `IDmeMatSysModel'};
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeMatSysMPPDag::`vftable'{for `CDmeDag'};
  this->m_eMppRoot.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eMppRoot.m_pAttribute = nullptr;
  this->m_eMppRoot.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_hChildren.m_Memory.m_pMemory = nullptr;
  this->m_hChildren.m_Memory.m_nAllocationCount = 0;
  this->m_hChildren.m_Memory.m_nGrowSize = 0;
  this->m_hChildren.m_Size = 0;
  this->m_hChildren.m_pElements = nullptr;
  this->m_dmeOperatorList.m_Memory.m_pMemory = nullptr;
  this->m_dmeOperatorList.m_Memory.m_nAllocationCount = 0;
  this->m_dmeOperatorList.m_Memory.m_nGrowSize = 0;
  this->m_dmeOperatorList.m_Size = 0;
  this->m_dmeOperatorList.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EE840
// Name: public: virtual bool CDmeMatSysMPPDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysMPPDag::IsA(CDmeMatSysMPPDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysMPPDag::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EE870
// Name: public: virtual int CDmeMatSysMPPDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMPPDag::GetInheritanceDepth(CDmeMatSysMPPDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysMPPDag::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EE8C0
// Name: protected: virtual void CDmeMatSysDMXDag::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysDMXDag::PerformDestruction(CDmeRig *this)
{
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004EE8D0
// Name: protected: virtual void CDmeMatSysMPPDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::PerformConstruction(CDmeMatSysMPPDag *this)
{
  bool v2; // zf
  CDmeMatSysMPPDag *v3; // esi
  CDmElement *v4; // ecx
  CDmAttribute *v5; // eax
  DmElementHandle_t value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction((CDmeDag *)this);
  v2 = this == (CDmeMatSysMPPDag *)4;
  v3 = (CDmeMatSysMPPDag *)((char *)this - 4);
  value = DMELEMENT_HANDLE_INVALID;
  if ( v2 )
    v4 = nullptr;
  else
    v4 = &v3->CDmeDag;
  v5 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "mppRoot",
         type: AT_FIRST_VALUE_TYPE,
         pMemory: &v3->m_eMppRoot);
  v3->m_eMppRoot.m_pAttribute = v5;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: v5, &value);
  v3->m_hDmeBodyGroupList = DMELEMENT_HANDLE_INVALID;
  v3->m_hDmeSequenceList = DMELEMENT_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x005AA120
// Name: protected: virtual int CDmeMatSysMPPDag::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMPPDag::AllocatedSize(CDmeLog *this)
{
  return 204;
}

//------------------------------------------------------------------------------
// Address: 0x005EEDE0
// Name: _dynamic_initializer_for__CDmeMatSysPanelSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysPanelSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysPanelSettings::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysPanelSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysPanelSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEE40
// Name: _dynamic_initializer_for__CDmeMatSysRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysRoot::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysRoot::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysRoot pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysRoot::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEEA0
// Name: _dynamic_initializer_for__CDmeMatSysMDLDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysMDLDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysMDLDag::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysMDLDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysMDLDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEF00
// Name: _dynamic_initializer_for__CDmeMatSysDMXDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysDMXDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysDMXDag::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysDMXDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysDMXDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEF60
// Name: _dynamic_initializer_for__CDmeMatSysMPPDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysMPPDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysMPPDag::s_Allocator,
    blockSize: 204,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysMPPDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysMPPDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3B30
// Name: _dynamic_atexit_destructor_for__CDmeMatSysPanelSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysPanelSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysPanelSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3B40
// Name: _dynamic_atexit_destructor_for__CDmeMatSysRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysRoot::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysRoot::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3B50
// Name: _dynamic_atexit_destructor_for__CDmeMatSysMDLDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysMDLDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysMDLDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3B60
// Name: _dynamic_atexit_destructor_for__CDmeMatSysDMXDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysDMXDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysDMXDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3B70
// Name: _dynamic_atexit_destructor_for__CDmeMatSysMPPDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysMPPDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysMPPDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EEE10
// Name: _dynamic_initializer_for__g_CDmeMatSysPanelSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysPanelSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysPanelSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEE20
// Name: _dynamic_initializer_for__g_CDmeMatSysPanelSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysPanelSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysPanelSettings_Helper,
           classname: "DmeMatSysPanelSettings",
           pFactory: &g_CDmeMatSysPanelSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EEE70
// Name: _dynamic_initializer_for__g_CDmeMatSysRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysRoot_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysRoot_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEE80
// Name: _dynamic_initializer_for__g_CDmeMatSysRoot_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysRoot_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysRoot_Helper,
           classname: "DmeMatSysRoot",
           pFactory: &g_CDmeMatSysRoot_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EEED0
// Name: _dynamic_initializer_for__g_CDmeMatSysMDLDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysMDLDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysMDLDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEEE0
// Name: _dynamic_initializer_for__g_CDmeMatSysMDLDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysMDLDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysMDLDag_Helper,
           classname: "DmeMatSysMDLDag",
           pFactory: &g_CDmeMatSysMDLDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EEF30
// Name: _dynamic_initializer_for__g_CDmeMatSysDMXDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysDMXDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysDMXDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEF40
// Name: _dynamic_initializer_for__g_CDmeMatSysDMXDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysDMXDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysDMXDag_Helper,
           classname: "DmeMatSysDMXDag",
           pFactory: &g_CDmeMatSysDMXDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EEF90
// Name: _dynamic_initializer_for__g_CDmeMatSysMPPDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysMPPDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysMPPDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEFA0
// Name: _dynamic_initializer_for__g_CDmeMatSysMPPDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysMPPDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysMPPDag_Helper,
           classname: "DmeMatSysMPPDag",
           pFactory: &g_CDmeMatSysMPPDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3B80
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysRoot_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysRoot_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3B90
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysMDLDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysMDLDag_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysMDLDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3BA0
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysDMXDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysDMXDag_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysDMXDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3BB0
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysMPPDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysMPPDag_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysMPPDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3BC0
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysPanelSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysPanelSettings_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysPanelSettings_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00514130
// Name: protected: virtual int CDmeMatSysRoot::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysRoot::AllocatedSize(CDmeTrackGroup *this)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x00517350
// Name: private: virtual int IDmeMatSysModel::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IDmeMatSysModel::SelectSequence(IDmeMatSysModel *this, const char *pszSequenceName)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00517360
// Name: public: virtual void CDmeMatSysMPPDag::SetFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::SetFrame(CDmeMatSysMPPDag *this, float flFrame)
{
  int v3; // eax

  v3 = DmeTime_t::RoundSecondsToTMS(sec: COERCE_UNSIGNED_INT(flFrame * 0.033333335));
  ((void (__thiscall *)(CDmeMatSysMPPDag *, int))this->SetTime)(a1: this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00517460
// Name: protected: void CDmeMatSysPanelSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysPanelSettings::OnConstruction(CDmeMatSysPanelSettings *this)
{
  CDmaVar<Color> *p_m_cBackgroundColor; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v8; // [esp+13h] [ebp-1h] BYREF

  p_m_cBackgroundColor = &this->m_cBackgroundColor;
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backgroundColor",
         type: AT_COLOR,
         pMemory: &this->m_cBackgroundColor);
  p_m_cBackgroundColor->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "ambientColor",
         type: AT_COLOR,
         pMemory: &this->m_cAmbientColor);
  this->m_cAmbientColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v8 = true;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "drawGroundPlane",
         type: AT_BOOL,
         pMemory: &this->m_bDrawGroundPlane);
  this->m_bDrawGroundPlane.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v8);
  v8 = true;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "drawOriginAxis",
         type: AT_BOOL,
         pMemory: &this->m_bDrawOriginAxis);
  this->m_bDrawOriginAxis.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v8);
}

//------------------------------------------------------------------------------
// Address: 0x00517510
// Name: public: virtual void CDmeMatSysMPPDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMatSysMPPDag::Draw(CDmeMatSysMPPDag *this@<ecx>, int a2@<esi>, CDmeDrawSettings *pDrawSettings)
{
  int v4; // esi

  if ( *((_BYTE *)&this->CDmElement + 64) != 0 )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 160))(a1: v4, a2: 1);
    CDmeDag::Draw((CDmeDag *)this, pDrawSettings);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 160))(a1: v4, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00517580
// Name: public: struct studiohdr_t __near * CDmeMatSysMDLDag::GetStudioHdr(void)const
// Source: json
//------------------------------------------------------------------------------
studiohdr_t *__thiscall CDmeMatSysMDLDag::GetStudioHdr(CDmeMatSysMDLDag *this)
{
  int v1; // eax
  CDmeMDL *v2; // esi
  unsigned __int16 MDL; // ax
  int v4; // esi

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v2 = (CDmeMDL *)v1;
  if ( v1 == 0 )
    return nullptr;
  if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmeMDL::m_classType.u) == 0 )
    return nullptr;
  MDL = CDmeMDL::GetMDL(this: v2);
  v4 = MDL;
  if ( MDL == 0xFFFF || g_pMDLCache->IsErrorModel(this: g_pMDLCache, a2: MDL) )
    return nullptr;
  else
    return g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x005175F0
// Name: public: virtual void CDmeMatSysMDLDag::SetTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::SetTime(CDmeMatSysMDLDag *this, DmeTime_t dmeTime)
{
  int v2; // eax
  int v3; // esi
  CDmAttribute *v4; // ecx
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v4 = *(CDmAttribute **)(v3 + 128);
    value = (float)dmeTime.m_tms * 0.000099999997;
    CDmAttribute::SetValue<float>(this: v4, &value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00517650
// Name: public: virtual void CDmeMatSysMDLDag::SetFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::SetFrame(CDmeMatSysMDLDag *this, float flFrame)
{
  int v2; // eax
  int v3; // esi
  CDmAttribute *v4; // ecx

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v4 = *(CDmAttribute **)(v3 + 128);
    flFrame = flFrame / *(float *)(v3 + 116);
    CDmAttribute::SetValue<float>(this: v4, value: &flFrame);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005176B0
// Name: protected: void CDmeMatSysMDLDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::OnConstruction(CDmeMatSysMDLDag *this)
{
  const char *m_pAsString; // eax
  DmFileId_t m_fileId; // esi
  CUtlString *v4; // eax
  CUtlString *v5; // eax
  const char *v6; // eax
  int v7; // eax
  int v8; // eax
  CDmeMDL *v9; // esi
  CUtlString v10; // [esp+Ch] [ebp-20h] BYREF
  CUtlString result; // [esp+1Ch] [ebp-10h] BYREF

  m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
  m_fileId = this->m_fileId;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  v4 = CUtlString::CUtlString(this: &v10, pString: m_pAsString);
  v5 = CUtlString::operator+(this: v4, &result, pOther: "Shape");
  v6 = CUtlString::operator char const *(this: v5);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeMDL::m_classType.u,
         a3: v6,
         a4: m_fileId,
         a5: 0);
  v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v7);
  v9 = (CDmeMDL *)v8;
  if ( v8 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
         a1: v8,
         a2: CDmeMDL::m_classType.u) == 0 )
  {
    v9 = nullptr;
  }
  result.m_Storage.m_nActualLength = 0;
  if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( result.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
      result.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    result.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v10.m_Storage.m_nActualLength = 0;
  if ( v10.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v10.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10.m_Storage.m_Memory.m_pMemory);
      v10.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v10.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( v9 != nullptr )
  {
    CDmeMDL::DrawInEngine(this: v9, bDrawInEngine: true);
    CDmeDag::SetShape(this: &this->CDmeDag, pShape: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005177A0
// Name: public: virtual void CDmeMatSysMPPDag::SetTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::SetTime(CDmeMatSysMPPDag *this, DmeTime_t dmeTime)
{
  int v3; // eax
  CDmeSequence *v4; // esi
  CDmeDag *v5; // ebx
  CDmeDag **m_pMemory; // edi
  int m_Size; // esi
  CDmeDag *v8; // ecx
  int i; // ebx
  CDmeDag *v10; // ebx
  const char *m_pAsString; // eax
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > depthFirstStack; // [esp+Ch] [ebp-1Ch] BYREF
  CDmeDag *Child; // [esp+20h] [ebp-8h]
  CDmeDag *pDmeDag; // [esp+24h] [ebp-4h]

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hDmeSequence);
  v4 = (CDmeSequence *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeSequence::m_classType.u) != 0 )
  {
    CDmeSequence::UpdateChannels(this: v4, dmeOperatorList: &this->m_dmeOperatorList, nClipTime: dmeTime);
    memset(&depthFirstStack, 0, sizeof(depthFirstStack));
    v5 = &this->CDmeDag;
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&depthFirstStack, num: 1);
    m_pMemory = depthFirstStack.m_Memory.m_pMemory;
    m_Size = depthFirstStack.m_Size + 1;
    depthFirstStack.m_pElements = depthFirstStack.m_Memory.m_pMemory;
    if ( &depthFirstStack.m_Memory.m_pMemory[depthFirstStack.m_Size + 1] != (CDmeDag **)4 )
      depthFirstStack.m_Memory.m_pMemory[depthFirstStack.m_Size] = v5;
    while ( m_Size > 0 )
    {
      v8 = m_pMemory[--m_Size];
      pDmeDag = v8;
      depthFirstStack.m_Size = m_Size;
      if ( v8 != nullptr )
      {
        for ( i = CDmElementFramework::GetPhase(this: v8) - 1; i >= 0; --i )
        {
          Child = CDmeDag::GetChild(this: pDmeDag, i);
          if ( m_Size >= depthFirstStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&depthFirstStack, num: 1);
            m_Size = depthFirstStack.m_Size;
            m_pMemory = depthFirstStack.m_Memory.m_pMemory;
          }
          depthFirstStack.m_Size = ++m_Size;
          depthFirstStack.m_pElements = m_pMemory;
          if ( &m_pMemory[m_Size] != (CDmeDag **)4 )
            m_pMemory[m_Size - 1] = Child;
        }
        v10 = pDmeDag;
        m_pAsString = pDmeDag->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        if ( _V_stricmp(s1: m_pAsString, s2: "root") == 0 )
          CDmeDag::GetTransform(this: v10);
      }
    }
    if ( depthFirstStack.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00517970
// Name: public: virtual int CDmeMatSysMDLDag::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMDLDag::SelectSequence(CDmeMatSysMDLDag *this, const char *pszSequenceName)
{
  int v3; // eax
  int v4; // esi
  int v5; // ebx
  studiohdr_t *StudioHdr; // esi
  CDmAttribute *v7; // ecx
  int j; // eax
  bool v9; // zf
  int numlocalseq; // ecx
  mstudioseqdesc_t *v11; // eax
  CDmAttribute *v12; // ecx
  int v14; // esi
  float flPoseParameter[24]; // [esp+Ch] [ebp-C8h] BYREF
  CStudioHdr cStudioHdr; // [esp+6Ch] [ebp-68h] BYREF
  int i; // [esp+D0h] [ebp-4h] BYREF

  if ( pszSequenceName == nullptr || *pszSequenceName == 0 )
    return -1;
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v4 = v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  StudioHdr = CDmeMatSysMDLDag::GetStudioHdr(this);
  if ( StudioHdr == nullptr )
    return -1;
  v7 = *(CDmAttribute **)(v5 + 104);
  i = -1;
  CDmAttribute::SetValue<int>(this: v7, value: &i);
  for ( j = 0; ; j = i + 1 )
  {
    v9 = StudioHdr->numincludemodels == 0;
    i = j;
    if ( v9 )
    {
      numlocalseq = StudioHdr->numlocalseq;
    }
    else
    {
      numlocalseq = studiohdr_t::GetNumSeq_Internal(this: StudioHdr);
      j = i;
    }
    if ( j >= numlocalseq )
      break;
    if ( StudioHdr->numincludemodels != 0 )
    {
      v11 = studiohdr_t::pSeqdesc_Internal(this: StudioHdr, i: j);
    }
    else
    {
      if ( j < 0 || j >= StudioHdr->numlocalseq )
        j = 0;
      v11 = (mstudioseqdesc_t *)((char *)StudioHdr + 212 * j + StudioHdr->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v11 + v11->szlabelindex, s2: pszSequenceName) == 0 )
    {
      CDmAttribute::SetValue<int>(this: *(CDmAttribute **)(v5 + 104), value: &i);
      break;
    }
  }
  if ( *(int *)(v5 + 100) < 0 )
  {
    v12 = *(CDmAttribute **)(v5 + 104);
    pszSequenceName = nullptr;
    CDmAttribute::SetValue<int>(this: v12, value: (const int *)&pszSequenceName);
    return -1;
  }
  CStudioHdr::CStudioHdr(this: &cStudioHdr, pStudioHdr: StudioHdr, mdlcache: g_pMDLCache);
  Studio_CalcDefaultPoseParameters(pStudioHdr: &cStudioHdr, flPoseParameter, nCount: 24);
  v14 = Studio_MaxFrame(pStudioHdr: &cStudioHdr, iSequence: *(_DWORD *)(v5 + 100), poseParameter: flPoseParameter);
  if ( v14 == 0 )
    v14 = 1;
  CStudioHdr::Term(this: &cStudioHdr);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&cStudioHdr.m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&cStudioHdr.m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&cStudioHdr.m_pStudioHdrCache);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x00517B00
// Name: public: virtual int CDmeMatSysMPPDag::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMPPDag::SelectSequence(CDmeMatSysMPPDag *this, const char *pszSequenceName)
{
  int v3; // ebx
  CDmElement *v4; // eax
  CDmeSequenceList *Value; // eax
  CDmeSequenceList *v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CExpressionCalculator *v10; // eax
  CDmeSequence *v11; // esi
  DmeFramerate_t v13; // ecx
  CDmeChannelsClip *FrameCount; // esi
  DmeFramerate_t v15; // [esp-8h] [ebp-30h] BYREF
  int v16; // [esp-4h] [ebp-2Ch]
  CUtlVector<CDmeSequenceBase *,CUtlMemory<CDmeSequenceBase *,int> > sortedSequenceList; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *dmeOperatorList; // [esp+20h] [ebp-8h]
  CDmeMatSysMPPDag *v19; // [esp+24h] [ebp-4h]

  v3 = 0;
  this->m_hDmeSequence = DMELEMENT_HANDLE_INVALID;
  dmeOperatorList = &this->m_dmeOperatorList;
  this->m_dmeOperatorList.m_Size = 0;
  v19 = this;
  if ( pszSequenceName == nullptr )
    return -1;
  if ( *pszSequenceName == 0 )
    return -1;
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eMppRoot.m_Storage.m_Handle) == 0 )
    return -1;
  v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_eMppRoot.m_Storage.m_Handle);
  Value = CDmElement::GetValueElement<CDmeSequenceList>(this: v4, pAttributeName: "sequenceList");
  v6 = Value;
  if ( Value == nullptr )
    return -1;
  memset(&sortedSequenceList, 0, sizeof(sortedSequenceList));
  if ( Value->m_Sequences.m_Storage.m_Size <= 0 )
  {
LABEL_13:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&sortedSequenceList);
    return -1;
  }
  while ( 1 )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v6->m_Sequences.m_Storage.m_Memory.m_pMemory[v3]);
    v8 = (CDmElement *)v7;
    if ( v7 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmeSequenceBase::m_classType.u) != 0 )
    {
      m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      if ( _V_stricmp(s1: pszSequenceName, s2: m_pAsString) == 0 )
      {
        v10 = (CExpressionCalculator *)CastElement<CDmeSequence>(pElement: v8);
        v11 = (CDmeSequence *)v10;
        if ( v10 != nullptr )
          break;
      }
    }
    if ( ++v3 >= v6->m_Sequences.m_Storage.m_Size )
      goto LABEL_13;
  }
  v19->m_hDmeSequence = CCodecBuffer_Block::GetBufferType(this: v10);
  CDmeSequence::PrepareChannels(this: v11, (CUtlMemory<vgui::TreeNode *,int> *)dmeOperatorList);
  v16 = 0;
  v15 = v13;
  DmeFramerate_t::DmeFramerate_t(this: &v15, fps: 0x1Eu);
  FrameCount = CDmeSequence::GetFrameCount(this: v11, fallbackFrameRate: v15, bForceFallback: v16);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&sortedSequenceList);
  return (int)FrameCount;
}

//------------------------------------------------------------------------------
// Address: 0x00517C50
// Name: public: virtual void CDmeMatSysMDLDag::GetSequenceList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::GetSequenceList(
        CDmeMatSysMDLDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  studiohdr_t *StudioHdr; // esi
  int i; // edi
  int v5; // eax
  int v6; // eax
  mstudioseqdesc_t *v7; // eax
  int v8; // eax
  mstudioseqdesc_t *v9; // eax
  const char *v10; // ecx
  CUtlString src; // [esp+8h] [ebp-10h] BYREF

  if ( pOutList != nullptr )
  {
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: pOutList);
    StudioHdr = CDmeMatSysMDLDag::GetStudioHdr(this);
    if ( StudioHdr != nullptr )
    {
      for ( i = 0; ; ++i )
      {
        v5 = StudioHdr->numincludemodels != 0
           ? studiohdr_t::GetNumSeq_Internal(this: StudioHdr)
           : StudioHdr->numlocalseq;
        if ( i >= v5 )
          break;
        if ( StudioHdr->numincludemodels != 0 )
        {
          v7 = studiohdr_t::pSeqdesc_Internal(this: StudioHdr, i);
        }
        else
        {
          v6 = i;
          if ( i < 0 || i >= StudioHdr->numlocalseq )
            v6 = 0;
          v7 = (mstudioseqdesc_t *)((char *)StudioHdr + 212 * v6 + StudioHdr->localseqindex);
        }
        if ( (v7->flags & 0x400) == 0 )
        {
          if ( StudioHdr->numincludemodels != 0 )
          {
            v9 = studiohdr_t::pSeqdesc_Internal(this: StudioHdr, i);
          }
          else
          {
            v8 = i;
            if ( i < 0 || i >= StudioHdr->numlocalseq )
              v8 = 0;
            v9 = (mstudioseqdesc_t *)((char *)StudioHdr + 212 * v8 + StudioHdr->localseqindex);
          }
          v10 = (char *)v9 + v9->szlabelindex;
          if ( v10 != nullptr && *v10 != 0 )
          {
            CUtlString::CUtlString(this: &src, pString: v10);
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
              this: pOutList,
              elem: pOutList->m_Size,
              &src);
            src.m_Storage.m_nActualLength = 0;
            if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                src.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              src.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00517D60
// Name: public: virtual void CDmeMatSysMPPDag::GetSequenceList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::GetSequenceList(
        CDmeMatSysMPPDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  CDmElement *v3; // eax
  CDmeSequenceList *Value; // eax
  int v5; // ebx
  const char *m_pAsString; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v10; // eax
  CUtlString *v11; // ecx
  CUtlVector<CDmeSequenceBase *,CUtlMemory<CDmeSequenceBase *,int> > sortedSequenceList; // [esp+8h] [ebp-24h] BYREF
  CUtlString string; // [esp+1Ch] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: pOutList);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eMppRoot.m_Storage.m_Handle) != 0 )
  {
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_eMppRoot.m_Storage.m_Handle);
    Value = CDmElement::GetValueElement<CDmeSequenceList>(this: v3, pAttributeName: "sequenceList");
    v5 = 0;
    if ( Value != nullptr )
    {
      memset(&sortedSequenceList, 0, sizeof(sortedSequenceList));
      CDmeSequenceList::GetSortedSequenceList(this: Value, (CUtlMemory<vgui::TreeNode *,int> *)&sortedSequenceList);
      if ( sortedSequenceList.m_Size > 0 )
      {
        do
        {
          m_pAsString = sortedSequenceList.m_Memory.m_pMemory[v5]->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = defaultValue;
          CUtlString::CUtlString(this: &string, pString: m_pAsString);
          m_Size = pOutList->m_Size;
          m_nAllocationCount = pOutList->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)pOutList,
              num: m_Size - m_nAllocationCount + 1);
          ++pOutList->m_Size;
          m_pMemory = pOutList->m_Memory.m_pMemory;
          v10 = pOutList->m_Size - m_Size - 1;
          pOutList->m_pElements = pOutList->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v10);
          v11 = &pOutList->m_Memory.m_pMemory[m_Size];
          if ( v11 != nullptr )
            CUtlString::CUtlString(this: v11, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          ++v5;
        }
        while ( v5 < sortedSequenceList.m_Size );
      }
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&sortedSequenceList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00517F30
// Name: public: virtual bool CDmeMatSysPanelSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysPanelSettings::IsA(CDmeMatSysPanelSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysPanelSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00517F60
// Name: public: virtual int CDmeMatSysPanelSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysPanelSettings::GetInheritanceDepth(CDmeMatSysPanelSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysPanelSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00518010
// Name: protected: virtual void CDmeMatSysPanelSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysPanelSettings::PerformConstruction(CDmeMatSysPanelSettings *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeMatSysPanelSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005181D0
// Name: public: virtual void CDmeMatSysMDLDag::GetActivityList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::GetActivityList(
        CDmeMatSysMDLDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  studiohdr_t *StudioHdr; // eax
  studiohdr_t *v4; // esi
  int v5; // ebx
  int NumSeq_Internal; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v7; // ecx
  bool v8; // zf
  int v9; // eax
  int v10; // eax
  mstudioseqdesc_t *v11; // eax
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  const char *v14; // edi
  CUtlDict<int,unsigned short> activityNames; // [esp+8h] [ebp-38h] BYREF
  CUtlString src; // [esp+24h] [ebp-1Ch] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+34h] [ebp-Ch] BYREF
  int j; // [esp+3Ch] [ebp-4h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: pOutList);
  StudioHdr = CDmeMatSysMDLDag::GetStudioHdr(this);
  v4 = StudioHdr;
  v5 = 0;
  if ( StudioHdr != nullptr )
  {
    if ( StudioHdr->numincludemodels != 0 )
      NumSeq_Internal = studiohdr_t::GetNumSeq_Internal(this: StudioHdr);
    else
      NumSeq_Internal = StudioHdr->numlocalseq;
    v7 = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = NumSeq_Internal;
    activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    if ( NumSeq_Internal != 0 )
    {
      v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 16 * NumSeq_Internal);
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v7;
    }
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_FirstFree = -1;
    activityNames.m_Elements.m_Tree.m_pElements = v7;
    activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    while ( 1 )
    {
      v8 = v4->numincludemodels == 0;
      j = v5;
      v9 = v8 ? v4->numlocalseq : studiohdr_t::GetNumSeq_Internal(this: v4);
      if ( v5 >= v9 )
        break;
      if ( v4->numincludemodels != 0 )
      {
        v11 = studiohdr_t::pSeqdesc_Internal(this: v4, i: v5);
      }
      else
      {
        v10 = v5;
        if ( v5 < 0 || v5 >= v4->numlocalseq )
          v10 = 0;
        v11 = (mstudioseqdesc_t *)((char *)v4 + 212 * v10 + v4->localseqindex);
      }
      if ( (v11->flags & 0x400) == 0 )
      {
        if ( v4->numincludemodels != 0 )
        {
          v13 = studiohdr_t::pSeqdesc_Internal(this: v4, i: v5);
        }
        else
        {
          v12 = v5;
          if ( v5 < 0 || v5 >= v4->numlocalseq )
            v12 = 0;
          v13 = (mstudioseqdesc_t *)((char *)v4 + 212 * v12 + v4->localseqindex);
        }
        v14 = (char *)v13 + v13->szactivitynameindex;
        if ( v14 != nullptr && *v14 != 0 )
        {
          search.key = (char *)v13 + v13->szactivitynameindex;
          if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                 this: &activityNames.m_Elements.m_Tree,
                 &search) == 0xFFFF )
          {
            CUtlString::CUtlString(this: &src, pString: v14);
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
              this: pOutList,
              elem: pOutList->m_Size,
              &src);
            src.m_Storage.m_nActualLength = 0;
            if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                src.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              src.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
            CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v14, element: &j);
          }
        }
      }
      ++v5;
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
// Address: 0x005183B0
// Name: public: virtual void CDmeMatSysMPPDag::GetActivityList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::GetActivityList(
        CDmeMatSysMPPDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  CDmElement *v3; // eax
  CDmeSequenceList *Value; // eax
  int m_Size; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v6; // eax
  int v7; // edi
  const char *v8; // esi
  CUtlDict<int,unsigned short> activityNames; // [esp+4h] [ebp-4Ch] BYREF
  CUtlVector<CDmeSequenceBase *,CUtlMemory<CDmeSequenceBase *,int> > sortedSequenceList; // [esp+20h] [ebp-30h] BYREF
  CUtlString src; // [esp+34h] [ebp-1Ch] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+44h] [ebp-Ch] BYREF
  int i; // [esp+4Ch] [ebp-4h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: pOutList);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eMppRoot.m_Storage.m_Handle) != 0 )
  {
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_eMppRoot.m_Storage.m_Handle);
    Value = CDmElement::GetValueElement<CDmeSequenceList>(this: v3, pAttributeName: "sequenceList");
    if ( Value != nullptr )
    {
      memset(&sortedSequenceList, 0, sizeof(sortedSequenceList));
      CDmeSequenceList::GetSortedSequenceList(this: Value, (CUtlMemory<vgui::TreeNode *,int> *)&sortedSequenceList);
      m_Size = sortedSequenceList.m_Size;
      v6 = nullptr;
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
      activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = sortedSequenceList.m_Size;
      activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
      if ( sortedSequenceList.m_Size != 0 )
      {
        v6 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                   this: _g_pMemAlloc,
                                                                                                   a2: 16
                                                                                                 * sortedSequenceList.m_Size);
        m_Size = sortedSequenceList.m_Size;
        activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v6;
      }
      activityNames.m_Elements.m_Tree.m_Root = -1;
      activityNames.m_Elements.m_Tree.m_NumElements = 0;
      v7 = 0;
      activityNames.m_Elements.m_Tree.m_FirstFree = -1;
      activityNames.m_Elements.m_Tree.m_LastAlloc.index = -1;
      activityNames.m_Elements.m_Tree.m_pElements = v6;
      activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
      i = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v8 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: sortedSequenceList.m_Memory.m_pMemory[v7]->m_eActivity.m_Storage.m_Handle)
                              + 20);
          if ( v8 != (const char *)-1 && v8 != nullptr && *v8 != 0 )
          {
            search.key = v8;
            if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                   this: &activityNames.m_Elements.m_Tree,
                   &search) == 0xFFFF )
            {
              CUtlString::CUtlString(this: &src, pString: v8);
              CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
                this: pOutList,
                elem: pOutList->m_Size,
                &src);
              src.m_Storage.m_nActualLength = 0;
              if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
              {
                if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
                {
                  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                  src.m_Storage.m_Memory.m_pMemory = nullptr;
                }
                src.m_Storage.m_Memory.m_nAllocationCount = 0;
              }
              CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v8, element: &i);
            }
          }
          i = ++v7;
        }
        while ( v7 < sortedSequenceList.m_Size );
      }
      CUtlDict<int,unsigned short>::RemoveAll(this: &activityNames);
      CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &activityNames.m_Elements.m_Tree);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&sortedSequenceList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00518540
// Name: protected: CDmeMatSysRoot::CDmeMatSysRoot(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysRoot *__thiscall CDmeMatSysRoot::CDmeMatSysRoot(
        CDmeMatSysRoot *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMatSysRoot_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeMatSysRoot_vtbl *)&CDmeMatSysRoot::`vftable';
  this->m_Settings.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Settings.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Settings.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005185C0
// Name: public: virtual bool CDmeMatSysRoot::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysRoot::IsA(CDmeMatSysRoot *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysRoot::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005185F0
// Name: public: virtual int CDmeMatSysRoot::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysRoot::GetInheritanceDepth(CDmeMatSysRoot *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysRoot::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00518640
// Name: protected: virtual void CDmeMatSysRoot::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysRoot::PerformConstruction(CDmeMatSysRoot *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmaElement<CDmeMatSysPanelSettings>::InitAndCreate(
    this: &this->m_Settings,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"settings",
    pElementName: nullptr,
    flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005186B0
// Name: protected: CDmeMatSysMDLDag::CDmeMatSysMDLDag(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysMDLDag *__thiscall CDmeMatSysMDLDag::CDmeMatSysMDLDag(
        CDmeMatSysMDLDag *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMDLDag_vtbl *)&IDmeMatSysModel::`vftable';
  CDmElement::CDmElement(this: &this->CDmeDag, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMDLDag_vtbl *)&CDmeMatSysMDLDag::`vftable'{for `IDmeMatSysModel'};
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeMatSysMDLDag::`vftable'{for `CDmeDag'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00518730
// Name: public: virtual bool CDmeMatSysMDLDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysMDLDag::IsA(CDmeMatSysMDLDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysMDLDag::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00518760
// Name: public: virtual int CDmeMatSysMDLDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMDLDag::GetInheritanceDepth(CDmeMatSysMDLDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysMDLDag::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005187B0
// Name: protected: virtual void CDmeMatSysMDLDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::PerformConstruction(CDmeMatSysMDLDag *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction((CDmeDag *)this);
  CDmeMatSysMDLDag::OnConstruction(this: (CDmeMatSysMDLDag *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00518820
// Name: protected: CDmeMatSysDMXDag::CDmeMatSysDMXDag(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysDMXDag *__thiscall CDmeMatSysDMXDag::CDmeMatSysDMXDag(
        CDmeMatSysDMXDag *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->IDmeMatSysModel::__vftable = (CDmeMatSysDMXDag_vtbl *)&IDmeMatSysModel::`vftable';
  CDmElement::CDmElement(this: &this->CDmeDag, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->IDmeMatSysModel::__vftable = (CDmeMatSysDMXDag_vtbl *)&CDmeMatSysDMXDag::`vftable'{for `IDmeMatSysModel'};
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeMatSysDMXDag::`vftable'{for `CDmeDag'};
  this->m_eDmxRoot.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eDmxRoot.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eDmxRoot.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005188C0
// Name: public: virtual bool CDmeMatSysDMXDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysDMXDag::IsA(CDmeMatSysDMXDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysDMXDag::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005188F0
// Name: public: virtual int CDmeMatSysDMXDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysDMXDag::GetInheritanceDepth(CDmeMatSysDMXDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysDMXDag::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00518940
// Name: protected: virtual int CDmeMatSysDMXDag::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysDMXDag::AllocatedSize(CDmeTimeSelection *this)
{
  return 156;
}

//------------------------------------------------------------------------------
// Address: 0x00518950
// Name: protected: virtual void CDmeMatSysDMXDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysDMXDag::PerformConstruction(CDmeMatSysDMXDag *this)
{
  bool v2; // zf
  CDmeMatSysDMXDag *v3; // esi
  CDmElement *v4; // ecx
  CDmAttribute *v5; // eax
  DmElementHandle_t value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction((CDmeDag *)this);
  v2 = this == (CDmeMatSysDMXDag *)4;
  v3 = (CDmeMatSysDMXDag *)((char *)this - 4);
  value = DMELEMENT_HANDLE_INVALID;
  if ( v2 )
    v4 = nullptr;
  else
    v4 = &v3->CDmeDag;
  v5 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "dmxRoot",
         type: AT_FIRST_VALUE_TYPE,
         pMemory: &v3->m_eDmxRoot);
  v3->m_eDmxRoot.m_pAttribute = v5;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: v5, &value);
  v3->m_hDmxModel = DMELEMENT_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x00518A00
// Name: protected: CDmeMatSysMPPDag::CDmeMatSysMPPDag(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysMPPDag *__thiscall CDmeMatSysMPPDag::CDmeMatSysMPPDag(
        CDmeMatSysMPPDag *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMPPDag_vtbl *)&IDmeMatSysModel::`vftable';
  CDmElement::CDmElement(this: &this->CDmeDag, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMPPDag_vtbl *)&CDmeMatSysMPPDag::`vftable'{for `IDmeMatSysModel'};
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeMatSysMPPDag::`vftable'{for `CDmeDag'};
  this->m_eMppRoot.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eMppRoot.m_pAttribute = nullptr;
  this->m_eMppRoot.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_hChildren.m_Memory.m_pMemory = nullptr;
  this->m_hChildren.m_Memory.m_nAllocationCount = 0;
  this->m_hChildren.m_Memory.m_nGrowSize = 0;
  this->m_hChildren.m_Size = 0;
  this->m_hChildren.m_pElements = nullptr;
  this->m_dmeOperatorList.m_Memory.m_pMemory = nullptr;
  this->m_dmeOperatorList.m_Memory.m_nAllocationCount = 0;
  this->m_dmeOperatorList.m_Memory.m_nGrowSize = 0;
  this->m_dmeOperatorList.m_Size = 0;
  this->m_dmeOperatorList.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00518AE0
// Name: public: virtual bool CDmeMatSysMPPDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysMPPDag::IsA(CDmeMatSysMPPDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysMPPDag::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00518B10
// Name: public: virtual int CDmeMatSysMPPDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMPPDag::GetInheritanceDepth(CDmeMatSysMPPDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysMPPDag::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00518B60
// Name: protected: virtual int CDmeMatSysMPPDag::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMPPDag::AllocatedSize(CDmeLog *this)
{
  return 204;
}

//------------------------------------------------------------------------------
// Address: 0x00518B70
// Name: protected: virtual void CDmeMatSysMPPDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::PerformConstruction(CDmeMatSysMPPDag *this)
{
  bool v2; // zf
  CDmeMatSysMPPDag *v3; // esi
  CDmElement *v4; // ecx
  CDmAttribute *v5; // eax
  DmElementHandle_t value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction((CDmeDag *)this);
  v2 = this == (CDmeMatSysMPPDag *)4;
  v3 = (CDmeMatSysMPPDag *)((char *)this - 4);
  value = DMELEMENT_HANDLE_INVALID;
  if ( v2 )
    v4 = nullptr;
  else
    v4 = &v3->CDmeDag;
  v5 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "mppRoot",
         type: AT_FIRST_VALUE_TYPE,
         pMemory: &v3->m_eMppRoot);
  v3->m_eMppRoot.m_pAttribute = v5;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: v5, &value);
  v3->m_hDmeBodyGroupList = DMELEMENT_HANDLE_INVALID;
  v3->m_hDmeSequenceList = DMELEMENT_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x005DCD80
// Name: protected: virtual void CDmeMatSysDMXDag::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysDMXDag::PerformDestruction(CDmeRigHandle *this)
{
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x006AE660
// Name: _dynamic_initializer_for__CDmeMatSysPanelSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysPanelSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysPanelSettings::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysPanelSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysPanelSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE6C0
// Name: _dynamic_initializer_for__CDmeMatSysRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysRoot::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysRoot::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysRoot pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysRoot::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE720
// Name: _dynamic_initializer_for__CDmeMatSysMDLDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysMDLDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysMDLDag::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysMDLDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysMDLDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE780
// Name: _dynamic_initializer_for__CDmeMatSysDMXDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysDMXDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysDMXDag::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysDMXDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysDMXDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE7E0
// Name: _dynamic_initializer_for__CDmeMatSysMPPDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysMPPDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysMPPDag::s_Allocator,
    blockSize: 204,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysMPPDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysMPPDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4650
// Name: _dynamic_atexit_destructor_for__CDmeMatSysPanelSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysPanelSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysPanelSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4660
// Name: _dynamic_atexit_destructor_for__CDmeMatSysRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysRoot::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysRoot::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4670
// Name: _dynamic_atexit_destructor_for__CDmeMatSysMDLDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysMDLDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysMDLDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4680
// Name: _dynamic_atexit_destructor_for__CDmeMatSysDMXDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysDMXDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysDMXDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4690
// Name: _dynamic_atexit_destructor_for__CDmeMatSysMPPDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysMPPDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysMPPDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00517390
// Name: class CDmeSequence __near * CastElement<class CDmeSequence>(class CDmElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequence *__cdecl CastElement<CDmeSequence>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeSequence::m_classType.u.m_Id) )
  {
    return (CDmeSequence *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006AE690
// Name: _dynamic_initializer_for__g_CDmeMatSysPanelSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysPanelSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysPanelSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE6A0
// Name: _dynamic_initializer_for__g_CDmeMatSysPanelSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysPanelSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysPanelSettings_Helper,
           classname: "DmeMatSysPanelSettings",
           pFactory: &g_CDmeMatSysPanelSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AE6F0
// Name: _dynamic_initializer_for__g_CDmeMatSysRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysRoot_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysRoot_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE700
// Name: _dynamic_initializer_for__g_CDmeMatSysRoot_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysRoot_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysRoot_Helper,
           classname: "DmeMatSysRoot",
           pFactory: &g_CDmeMatSysRoot_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AE750
// Name: _dynamic_initializer_for__g_CDmeMatSysMDLDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysMDLDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysMDLDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE760
// Name: _dynamic_initializer_for__g_CDmeMatSysMDLDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysMDLDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysMDLDag_Helper,
           classname: "DmeMatSysMDLDag",
           pFactory: &g_CDmeMatSysMDLDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AE7B0
// Name: _dynamic_initializer_for__g_CDmeMatSysDMXDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysDMXDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysDMXDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE7C0
// Name: _dynamic_initializer_for__g_CDmeMatSysDMXDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysDMXDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysDMXDag_Helper,
           classname: "DmeMatSysDMXDag",
           pFactory: &g_CDmeMatSysDMXDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AE810
// Name: _dynamic_initializer_for__g_CDmeMatSysMPPDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysMPPDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysMPPDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE820
// Name: _dynamic_initializer_for__g_CDmeMatSysMPPDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysMPPDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysMPPDag_Helper,
           classname: "DmeMatSysMPPDag",
           pFactory: &g_CDmeMatSysMPPDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B46A0
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysRoot_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMatSysRoot_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B46B0
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysMDLDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysMDLDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMatSysMDLDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B46C0
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysDMXDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysDMXDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMatSysDMXDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B46D0
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysMPPDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysMPPDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMatSysMPPDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B46E0
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysPanelSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysPanelSettings_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMatSysPanelSettings_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E6170
// Name: private: virtual int IDmeMatSysModel::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IDmeMatSysModel::SelectSequence(IDmeMatSysModel *this, const char *pszSequenceName)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6180
// Name: public: virtual void CDmeMatSysMPPDag::SetFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::SetFrame(CDmeMatSysMPPDag *this, float flFrame)
{
  int v3; // eax

  v3 = DmeTime_t::RoundSecondsToTMS(sec: COERCE_UNSIGNED_INT(flFrame * 0.033333335));
  ((void (__thiscall *)(CDmeMatSysMPPDag *, int))this->SetTime)(a1: this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004E61E0
// Name: public: CMatRenderContextPtr::~CMatRenderContextPtr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextPtr::~CMatRenderContextPtr(CMatRenderContextPtr *this)
{
  IMatRenderContext *m_pObject; // ecx

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    if ( this->m_pObject != nullptr )
      this->m_pObject->Release(this: this->m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E62A0
// Name: public: CMatRenderContextPtr::CMatRenderContextPtr(class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CMatRenderContextPtr *__thiscall CMatRenderContextPtr::CMatRenderContextPtr(
        CMatRenderContextPtr *this,
        IMaterialSystem *pFrom)
{
  IMatRenderContext *v3; // eax

  v3 = pFrom->GetRenderContext(this: pFrom);
  this->m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E62D0
// Name: protected: void CDmeMatSysPanelSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysPanelSettings::OnConstruction(CDmeMatSysPanelSettings *this)
{
  CDmaVar<Color> *p_m_cBackgroundColor; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v8; // [esp+13h] [ebp-1h] BYREF

  p_m_cBackgroundColor = &this->m_cBackgroundColor;
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backgroundColor",
         type: AT_COLOR,
         pMemory: &this->m_cBackgroundColor);
  p_m_cBackgroundColor->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "ambientColor",
         type: AT_COLOR,
         pMemory: &this->m_cAmbientColor);
  this->m_cAmbientColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v8 = true;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "drawGroundPlane",
         type: AT_BOOL,
         pMemory: &this->m_bDrawGroundPlane);
  this->m_bDrawGroundPlane.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v8);
  v8 = true;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "drawOriginAxis",
         type: AT_BOOL,
         pMemory: &this->m_bDrawOriginAxis);
  this->m_bDrawOriginAxis.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v8);
}

//------------------------------------------------------------------------------
// Address: 0x004E6380
// Name: public: virtual void CDmeMatSysMPPDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMatSysMPPDag::Draw(CDmeMatSysMPPDag *this@<ecx>, int a2@<esi>, CDmeDrawSettings *pDrawSettings)
{
  int v4; // esi

  if ( *((_BYTE *)&this->CDmElement + 64) != 0 )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 160))(a1: v4, a2: 1);
    CDmeDag::Draw((CDmeDag *)this, pDrawSettings);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 160))(a1: v4, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E63F0
// Name: public: struct studiohdr_t __near * CDmeMatSysMDLDag::GetStudioHdr(void)const
// Source: json
//------------------------------------------------------------------------------
studiohdr_t *__thiscall CDmeMatSysMDLDag::GetStudioHdr(CDmeMatSysMDLDag *this)
{
  int v1; // eax
  CDmeMDL *v2; // esi
  unsigned __int16 MDL; // ax
  int v4; // esi

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v2 = (CDmeMDL *)v1;
  if ( v1 == 0 )
    return nullptr;
  if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmeMDL::m_classType.u) == 0 )
    return nullptr;
  MDL = CDmeMDL::GetMDL(this: v2);
  v4 = MDL;
  if ( MDL == 0xFFFF || g_pMDLCache->IsErrorModel(this: g_pMDLCache, a2: MDL) )
    return nullptr;
  else
    return g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004E6460
// Name: public: virtual void CDmeMatSysMDLDag::SetTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::SetTime(CDmeMatSysMDLDag *this, DmeTime_t dmeTime)
{
  int v2; // eax
  int v3; // esi
  CDmAttribute *v4; // ecx
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v4 = *(CDmAttribute **)(v3 + 128);
    value = (float)dmeTime.m_tms * 0.000099999997;
    CDmAttribute::SetValue<float>(this: v4, &value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E64C0
// Name: public: virtual void CDmeMatSysMDLDag::SetFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::SetFrame(CDmeMatSysMDLDag *this, float flFrame)
{
  int v2; // eax
  int v3; // esi
  CDmAttribute *v4; // ecx

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v4 = *(CDmAttribute **)(v3 + 128);
    flFrame = flFrame / *(float *)(v3 + 116);
    CDmAttribute::SetValue<float>(this: v4, value: &flFrame);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E6520
// Name: protected: void CDmeMatSysMDLDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::OnConstruction(CDmeMatSysMDLDag *this)
{
  const char *m_pAsString; // eax
  DmFileId_t m_fileId; // esi
  CUtlString *v4; // eax
  CUtlString *v5; // eax
  const char *v6; // eax
  int v7; // eax
  int v8; // eax
  CDmeMDL *v9; // esi
  CUtlString v10; // [esp+Ch] [ebp-20h] BYREF
  CUtlString result; // [esp+1Ch] [ebp-10h] BYREF

  m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
  m_fileId = this->m_fileId;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  v4 = CUtlString::CUtlString(this: &v10, pString: m_pAsString);
  v5 = CUtlString::operator+(this: v4, &result, pOther: "Shape");
  v6 = CUtlString::operator char const *(this: v5);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeMDL::m_classType.u,
         a3: v6,
         a4: m_fileId,
         a5: 0);
  v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v7);
  v9 = (CDmeMDL *)v8;
  if ( v8 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
         a1: v8,
         a2: CDmeMDL::m_classType.u) == 0 )
  {
    v9 = nullptr;
  }
  result.m_Storage.m_nActualLength = 0;
  if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( result.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
      result.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    result.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v10.m_Storage.m_nActualLength = 0;
  if ( v10.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v10.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10.m_Storage.m_Memory.m_pMemory);
      v10.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v10.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( v9 != nullptr )
  {
    CDmeMDL::DrawInEngine(this: v9, bDrawInEngine: true);
    CDmeDag::SetShape(this: &this->CDmeDag, pShape: (int)v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E6610
// Name: public: virtual void CDmeMatSysMPPDag::SetTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::SetTime(CDmeMatSysMPPDag *this, DmeTime_t dmeTime)
{
  int v3; // eax
  CDmeSequence *v4; // esi
  CDmeDag *v5; // ebx
  CDmeDag **m_pMemory; // edi
  int m_Size; // esi
  CDmeDag *v8; // ecx
  int i; // ebx
  CDmeDag *v10; // ebx
  const char *m_pAsString; // eax
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > depthFirstStack; // [esp+Ch] [ebp-1Ch] BYREF
  CDmeDag *Child; // [esp+20h] [ebp-8h]
  CDmeDag *pDmeDag; // [esp+24h] [ebp-4h]

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hDmeSequence);
  v4 = (CDmeSequence *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeSequence::m_classType.u) != 0 )
  {
    CDmeSequence::UpdateChannels(this: v4, dmeOperatorList: &this->m_dmeOperatorList, nClipTime: dmeTime);
    memset(&depthFirstStack, 0, sizeof(depthFirstStack));
    v5 = &this->CDmeDag;
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depthFirstStack,
      num: 1);
    m_pMemory = depthFirstStack.m_Memory.m_pMemory;
    m_Size = depthFirstStack.m_Size + 1;
    depthFirstStack.m_pElements = depthFirstStack.m_Memory.m_pMemory;
    if ( &depthFirstStack.m_Memory.m_pMemory[depthFirstStack.m_Size + 1] != (CDmeDag **)4 )
      depthFirstStack.m_Memory.m_pMemory[depthFirstStack.m_Size] = v5;
    while ( m_Size > 0 )
    {
      v8 = m_pMemory[--m_Size];
      pDmeDag = v8;
      depthFirstStack.m_Size = m_Size;
      if ( v8 != nullptr )
      {
        for ( i = CDmElementFramework::GetPhase(this: v8) - 1; i >= 0; --i )
        {
          Child = CDmeDag::GetChild(this: pDmeDag, i);
          if ( m_Size >= depthFirstStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depthFirstStack,
              num: 1);
            m_Size = depthFirstStack.m_Size;
            m_pMemory = depthFirstStack.m_Memory.m_pMemory;
          }
          depthFirstStack.m_Size = ++m_Size;
          depthFirstStack.m_pElements = m_pMemory;
          if ( &m_pMemory[m_Size] != (CDmeDag **)4 )
            m_pMemory[m_Size - 1] = Child;
        }
        v10 = pDmeDag;
        m_pAsString = pDmeDag->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = pDeltaStateName;
        if ( _V_stricmp(s1: m_pAsString, s2: "root") == 0 )
          CDmeDag::GetTransform(this: v10);
      }
    }
    if ( depthFirstStack.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E67E0
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneParent);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneFlags);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x004E6810
// Name: public: virtual int CDmeMatSysMDLDag::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMDLDag::SelectSequence(CDmeMatSysMDLDag *this, const char *pszSequenceName)
{
  int v3; // eax
  int v4; // esi
  int v5; // ebx
  studiohdr_t *StudioHdr; // esi
  CDmAttribute *v7; // ecx
  int j; // eax
  bool v9; // zf
  int numlocalseq; // ecx
  mstudioseqdesc_t *v11; // eax
  CDmAttribute *v12; // ecx
  int v14; // esi
  float flPoseParameter[24]; // [esp+Ch] [ebp-C8h] BYREF
  CStudioHdr cStudioHdr; // [esp+6Ch] [ebp-68h] BYREF
  int i; // [esp+D0h] [ebp-4h] BYREF

  if ( pszSequenceName == nullptr || *pszSequenceName == 0 )
    return -1;
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  v4 = v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  StudioHdr = CDmeMatSysMDLDag::GetStudioHdr(this);
  if ( StudioHdr == nullptr )
    return -1;
  v7 = *(CDmAttribute **)(v5 + 104);
  i = -1;
  CDmAttribute::SetValue<int>(this: v7, value: &i);
  for ( j = 0; ; j = i + 1 )
  {
    v9 = StudioHdr->numincludemodels == 0;
    i = j;
    if ( v9 )
    {
      numlocalseq = StudioHdr->numlocalseq;
    }
    else
    {
      numlocalseq = studiohdr_t::GetNumSeq_Internal(this: StudioHdr);
      j = i;
    }
    if ( j >= numlocalseq )
      break;
    if ( StudioHdr->numincludemodels != 0 )
    {
      v11 = studiohdr_t::pSeqdesc_Internal(this: StudioHdr, i: j);
    }
    else
    {
      if ( j < 0 || j >= StudioHdr->numlocalseq )
        j = 0;
      v11 = (mstudioseqdesc_t *)((char *)StudioHdr + 212 * j + StudioHdr->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v11 + v11->szlabelindex, s2: pszSequenceName) == 0 )
    {
      CDmAttribute::SetValue<int>(this: *(CDmAttribute **)(v5 + 104), value: &i);
      break;
    }
  }
  if ( *(int *)(v5 + 100) < 0 )
  {
    v12 = *(CDmAttribute **)(v5 + 104);
    pszSequenceName = nullptr;
    CDmAttribute::SetValue<int>(this: v12, value: (int *)&pszSequenceName);
    return -1;
  }
  CStudioHdr::CStudioHdr(this: &cStudioHdr, pStudioHdr: StudioHdr, mdlcache: g_pMDLCache);
  Studio_CalcDefaultPoseParameters(pStudioHdr: &cStudioHdr, flPoseParameter, nCount: 24);
  v14 = Studio_MaxFrame(pStudioHdr: &cStudioHdr, iSequence: *(_DWORD *)(v5 + 100), poseParameter: flPoseParameter);
  if ( v14 == 0 )
    v14 = 1;
  CStudioHdr::Term(this: &cStudioHdr);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&cStudioHdr.m_boneParent);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&cStudioHdr.m_boneFlags);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&cStudioHdr.m_pStudioHdrCache);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x004E69A0
// Name: public: virtual int CDmeMatSysMPPDag::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMPPDag::SelectSequence(CDmeMatSysMPPDag *this, const char *pszSequenceName)
{
  int v3; // ebx
  CDmElement *v4; // eax
  CDmeSequenceList *Value; // eax
  CDmeSequenceList *v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CExpressionCalculator *v10; // eax
  CDmeSequence *v11; // esi
  DmeFramerate_t v13; // ecx
  CDmeChannelsClip *FrameCount; // esi
  DmeFramerate_t v15; // [esp-8h] [ebp-30h] BYREF
  int v16; // [esp-4h] [ebp-2Ch]
  CUtlVector<CDmeSequenceBase *,CUtlMemory<CDmeSequenceBase *,int> > sortedSequenceList; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *dmeOperatorList; // [esp+20h] [ebp-8h]
  CDmeMatSysMPPDag *v19; // [esp+24h] [ebp-4h]

  v3 = 0;
  this->m_hDmeSequence = DMELEMENT_HANDLE_INVALID;
  dmeOperatorList = &this->m_dmeOperatorList;
  this->m_dmeOperatorList.m_Size = 0;
  v19 = this;
  if ( pszSequenceName == nullptr )
    return -1;
  if ( *pszSequenceName == 0 )
    return -1;
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eMppRoot.m_Storage.m_Handle) == 0 )
    return -1;
  v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_eMppRoot.m_Storage.m_Handle);
  Value = CDmElement::GetValueElement<CDmeSequenceList>(this: v4, pAttributeName: "sequenceList");
  v6 = Value;
  if ( Value == nullptr )
    return -1;
  memset(&sortedSequenceList, 0, sizeof(sortedSequenceList));
  if ( Value->m_Sequences.m_Storage.m_Size <= 0 )
  {
LABEL_13:
    CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedSequenceList);
    return -1;
  }
  while ( 1 )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v6->m_Sequences.m_Storage.m_Memory.m_pMemory[v3]);
    v8 = (CDmElement *)v7;
    if ( v7 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmeSequenceBase::m_classType.u) != 0 )
    {
      m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      if ( _V_stricmp(s1: pszSequenceName, s2: m_pAsString) == 0 )
      {
        v10 = (CExpressionCalculator *)CastElement<CDmeSequence>(pElement: v8);
        v11 = (CDmeSequence *)v10;
        if ( v10 != nullptr )
          break;
      }
    }
    if ( ++v3 >= v6->m_Sequences.m_Storage.m_Size )
      goto LABEL_13;
  }
  v19->m_hDmeSequence = CExpressionCalculator::VariableCount(this: v10);
  CDmeSequence::PrepareChannels(this: v11, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)dmeOperatorList);
  v16 = 0;
  v15 = v13;
  DmeFramerate_t::DmeFramerate_t(this: &v15, fps: 0x1Eu);
  FrameCount = CDmeSequence::GetFrameCount(this: v11, fallbackFrameRate: v15, bForceFallback: v16);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedSequenceList);
  return (int)FrameCount;
}

//------------------------------------------------------------------------------
// Address: 0x004E6AF0
// Name: public: virtual void CDmeMatSysMDLDag::GetSequenceList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::GetSequenceList(
        CDmeMatSysMDLDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  studiohdr_t *StudioHdr; // esi
  int i; // edi
  int v5; // eax
  int v6; // eax
  mstudioseqdesc_t *v7; // eax
  int v8; // eax
  mstudioseqdesc_t *v9; // eax
  const char *v10; // ecx
  CUtlString src; // [esp+8h] [ebp-10h] BYREF

  if ( pOutList != nullptr )
  {
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)pOutList);
    StudioHdr = CDmeMatSysMDLDag::GetStudioHdr(this);
    if ( StudioHdr != nullptr )
    {
      for ( i = 0; ; ++i )
      {
        v5 = StudioHdr->numincludemodels != 0
           ? studiohdr_t::GetNumSeq_Internal(this: StudioHdr)
           : StudioHdr->numlocalseq;
        if ( i >= v5 )
          break;
        if ( StudioHdr->numincludemodels != 0 )
        {
          v7 = studiohdr_t::pSeqdesc_Internal(this: StudioHdr, i);
        }
        else
        {
          v6 = i;
          if ( i < 0 || i >= StudioHdr->numlocalseq )
            v6 = 0;
          v7 = (mstudioseqdesc_t *)((char *)StudioHdr + 212 * v6 + StudioHdr->localseqindex);
        }
        if ( (v7->flags & 0x400) == 0 )
        {
          if ( StudioHdr->numincludemodels != 0 )
          {
            v9 = studiohdr_t::pSeqdesc_Internal(this: StudioHdr, i);
          }
          else
          {
            v8 = i;
            if ( i < 0 || i >= StudioHdr->numlocalseq )
              v8 = 0;
            v9 = (mstudioseqdesc_t *)((char *)StudioHdr + 212 * v8 + StudioHdr->localseqindex);
          }
          v10 = (char *)v9 + v9->szlabelindex;
          if ( v10 != nullptr && *v10 != 0 )
          {
            CUtlString::CUtlString(this: &src, pString: v10);
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
              this: pOutList,
              elem: pOutList->m_Size,
              &src);
            src.m_Storage.m_nActualLength = 0;
            if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                src.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              src.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E6C10
// Name: public: virtual void CDmeMatSysMPPDag::GetSequenceList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::GetSequenceList(
        CDmeMatSysMPPDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  CDmElement *v3; // eax
  CDmeSequenceList *Value; // eax
  int v5; // ebx
  const char *m_pAsString; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v10; // eax
  CUtlString *v11; // ecx
  CUtlVector<CDmeSequenceBase *,CUtlMemory<CDmeSequenceBase *,int> > sortedSequenceList; // [esp+8h] [ebp-24h] BYREF
  CUtlString string; // [esp+1Ch] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)pOutList);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eMppRoot.m_Storage.m_Handle) != 0 )
  {
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_eMppRoot.m_Storage.m_Handle);
    Value = CDmElement::GetValueElement<CDmeSequenceList>(this: v3, pAttributeName: "sequenceList");
    v5 = 0;
    if ( Value != nullptr )
    {
      memset(&sortedSequenceList, 0, sizeof(sortedSequenceList));
      CDmeSequenceList::GetSortedSequenceList(
        this: Value,
        (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&sortedSequenceList);
      if ( sortedSequenceList.m_Size > 0 )
      {
        do
        {
          m_pAsString = sortedSequenceList.m_Memory.m_pMemory[v5]->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = pDeltaStateName;
          CUtlString::CUtlString(this: &string, pString: m_pAsString);
          m_Size = pOutList->m_Size;
          m_nAllocationCount = pOutList->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)pOutList,
              num: m_Size - m_nAllocationCount + 1);
          ++pOutList->m_Size;
          m_pMemory = pOutList->m_Memory.m_pMemory;
          v10 = pOutList->m_Size - m_Size - 1;
          pOutList->m_pElements = pOutList->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v10);
          v11 = &pOutList->m_Memory.m_pMemory[m_Size];
          if ( v11 != nullptr )
            CUtlString::CUtlString(this: v11, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          ++v5;
        }
        while ( v5 < sortedSequenceList.m_Size );
      }
      CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedSequenceList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E6DE0
// Name: public: virtual bool CDmeMatSysPanelSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysPanelSettings::IsA(CDmeMatSysPanelSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysPanelSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6E10
// Name: public: virtual int CDmeMatSysPanelSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysPanelSettings::GetInheritanceDepth(CDmeMatSysPanelSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysPanelSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6EC0
// Name: protected: virtual void CDmeMatSysPanelSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysPanelSettings::PerformConstruction(CDmeMatSysPanelSettings *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMatSysPanelSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E7050
// Name: public: virtual void CDmeMatSysMDLDag::GetActivityList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::GetActivityList(
        CDmeMatSysMDLDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  studiohdr_t *StudioHdr; // eax
  studiohdr_t *v4; // esi
  int v5; // ebx
  int NumSeq_Internal; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v7; // ecx
  bool v8; // zf
  int v9; // eax
  int v10; // eax
  mstudioseqdesc_t *v11; // eax
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  const char *v14; // edi
  CUtlDict<int,unsigned short> activityNames; // [esp+8h] [ebp-38h] BYREF
  CUtlString src; // [esp+24h] [ebp-1Ch] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+34h] [ebp-Ch] BYREF
  int j; // [esp+3Ch] [ebp-4h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)pOutList);
  StudioHdr = CDmeMatSysMDLDag::GetStudioHdr(this);
  v4 = StudioHdr;
  v5 = 0;
  if ( StudioHdr != nullptr )
  {
    if ( StudioHdr->numincludemodels != 0 )
      NumSeq_Internal = studiohdr_t::GetNumSeq_Internal(this: StudioHdr);
    else
      NumSeq_Internal = StudioHdr->numlocalseq;
    v7 = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = NumSeq_Internal;
    activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    if ( NumSeq_Internal != 0 )
    {
      v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 16 * NumSeq_Internal);
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v7;
    }
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_FirstFree = -1;
    activityNames.m_Elements.m_Tree.m_pElements = v7;
    activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    while ( 1 )
    {
      v8 = v4->numincludemodels == 0;
      j = v5;
      v9 = v8 ? v4->numlocalseq : studiohdr_t::GetNumSeq_Internal(this: v4);
      if ( v5 >= v9 )
        break;
      if ( v4->numincludemodels != 0 )
      {
        v11 = studiohdr_t::pSeqdesc_Internal(this: v4, i: v5);
      }
      else
      {
        v10 = v5;
        if ( v5 < 0 || v5 >= v4->numlocalseq )
          v10 = 0;
        v11 = (mstudioseqdesc_t *)((char *)v4 + 212 * v10 + v4->localseqindex);
      }
      if ( (v11->flags & 0x400) == 0 )
      {
        if ( v4->numincludemodels != 0 )
        {
          v13 = studiohdr_t::pSeqdesc_Internal(this: v4, i: v5);
        }
        else
        {
          v12 = v5;
          if ( v5 < 0 || v5 >= v4->numlocalseq )
            v12 = 0;
          v13 = (mstudioseqdesc_t *)((char *)v4 + 212 * v12 + v4->localseqindex);
        }
        v14 = (char *)v13 + v13->szactivitynameindex;
        if ( v14 != nullptr && *v14 != 0 )
        {
          search.key = (char *)v13 + v13->szactivitynameindex;
          if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                 this: &activityNames.m_Elements.m_Tree,
                 &search) == 0xFFFF )
          {
            CUtlString::CUtlString(this: &src, pString: v14);
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
              this: pOutList,
              elem: pOutList->m_Size,
              &src);
            src.m_Storage.m_nActualLength = 0;
            if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                src.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              src.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
            CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v14, element: &j);
          }
        }
      }
      ++v5;
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
// Address: 0x004E7230
// Name: public: virtual void CDmeMatSysMPPDag::GetActivityList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::GetActivityList(
        CDmeMatSysMPPDag *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pOutList)
{
  CDmElement *v3; // eax
  CDmeSequenceList *Value; // eax
  int m_Size; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v6; // eax
  int v7; // edi
  const char *v8; // esi
  CUtlDict<int,unsigned short> activityNames; // [esp+4h] [ebp-4Ch] BYREF
  CUtlVector<CDmeSequenceBase *,CUtlMemory<CDmeSequenceBase *,int> > sortedSequenceList; // [esp+20h] [ebp-30h] BYREF
  CUtlString src; // [esp+34h] [ebp-1Ch] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+44h] [ebp-Ch] BYREF
  int i; // [esp+4Ch] [ebp-4h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)pOutList);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eMppRoot.m_Storage.m_Handle) != 0 )
  {
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_eMppRoot.m_Storage.m_Handle);
    Value = CDmElement::GetValueElement<CDmeSequenceList>(this: v3, pAttributeName: "sequenceList");
    if ( Value != nullptr )
    {
      memset(&sortedSequenceList, 0, sizeof(sortedSequenceList));
      CDmeSequenceList::GetSortedSequenceList(
        this: Value,
        (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&sortedSequenceList);
      m_Size = sortedSequenceList.m_Size;
      v6 = nullptr;
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
      activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = sortedSequenceList.m_Size;
      activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
      if ( sortedSequenceList.m_Size != 0 )
      {
        v6 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                   this: _g_pMemAlloc,
                                                                                                   a2: 16
                                                                                                 * sortedSequenceList.m_Size);
        m_Size = sortedSequenceList.m_Size;
        activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v6;
      }
      activityNames.m_Elements.m_Tree.m_Root = -1;
      activityNames.m_Elements.m_Tree.m_NumElements = 0;
      v7 = 0;
      activityNames.m_Elements.m_Tree.m_FirstFree = -1;
      activityNames.m_Elements.m_Tree.m_LastAlloc.index = -1;
      activityNames.m_Elements.m_Tree.m_pElements = v6;
      activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
      i = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v8 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: sortedSequenceList.m_Memory.m_pMemory[v7]->m_eActivity.m_Storage.m_Handle)
                              + 20);
          if ( v8 != (const char *)-1 && v8 != nullptr && *v8 != 0 )
          {
            search.key = v8;
            if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                   this: &activityNames.m_Elements.m_Tree,
                   &search) == 0xFFFF )
            {
              CUtlString::CUtlString(this: &src, pString: v8);
              CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
                this: pOutList,
                elem: pOutList->m_Size,
                &src);
              src.m_Storage.m_nActualLength = 0;
              if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
              {
                if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
                {
                  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                  src.m_Storage.m_Memory.m_pMemory = nullptr;
                }
                src.m_Storage.m_Memory.m_nAllocationCount = 0;
              }
              CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v8, element: &i);
            }
          }
          i = ++v7;
        }
        while ( v7 < sortedSequenceList.m_Size );
      }
      CUtlDict<int,unsigned short>::RemoveAll(this: &activityNames);
      CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &activityNames.m_Elements.m_Tree);
      CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedSequenceList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E73C0
// Name: protected: CDmeMatSysRoot::CDmeMatSysRoot(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysRoot *__thiscall CDmeMatSysRoot::CDmeMatSysRoot(
        CDmeMatSysRoot *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMatSysRoot_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeMatSysRoot_vtbl *)&CDmeMatSysRoot::`vftable';
  this->m_Settings.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Settings.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Settings.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E7440
// Name: public: virtual bool CDmeMatSysRoot::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysRoot::IsA(CDmeMatSysRoot *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysRoot::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7470
// Name: public: virtual int CDmeMatSysRoot::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysRoot::GetInheritanceDepth(CDmeMatSysRoot *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysRoot::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E74C0
// Name: protected: virtual int CDmeMatSysRoot::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysRoot::AllocatedSize(CDmeTrackGroup *this)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x004E74D0
// Name: protected: virtual void CDmeMatSysRoot::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysRoot::PerformConstruction(CDmeMatSysRoot *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmaElement<CDmeMatSysPanelSettings>::InitAndCreate(
    this: &this->m_Settings,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"settings",
    pElementName: nullptr,
    flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004E7540
// Name: protected: CDmeMatSysMDLDag::CDmeMatSysMDLDag(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysMDLDag *__thiscall CDmeMatSysMDLDag::CDmeMatSysMDLDag(
        CDmeMatSysMDLDag *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMDLDag_vtbl *)&IDmeMatSysModel::`vftable';
  CDmElement::CDmElement(this: &this->CDmeDag, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMDLDag_vtbl *)&CDmeMatSysMDLDag::`vftable'{for `IDmeMatSysModel'};
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeMatSysMDLDag::`vftable'{for `CDmeDag'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E75C0
// Name: public: virtual bool CDmeMatSysMDLDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysMDLDag::IsA(CDmeMatSysMDLDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysMDLDag::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E75F0
// Name: public: virtual int CDmeMatSysMDLDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMDLDag::GetInheritanceDepth(CDmeMatSysMDLDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysMDLDag::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7650
// Name: protected: virtual void CDmeMatSysMDLDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMDLDag::PerformConstruction(CDmeMatSysMDLDag *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction((CDmeDag *)this);
  CDmeMatSysMDLDag::OnConstruction(this: (CDmeMatSysMDLDag *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x004E76C0
// Name: protected: CDmeMatSysDMXDag::CDmeMatSysDMXDag(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysDMXDag *__thiscall CDmeMatSysDMXDag::CDmeMatSysDMXDag(
        CDmeMatSysDMXDag *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->IDmeMatSysModel::__vftable = (CDmeMatSysDMXDag_vtbl *)&IDmeMatSysModel::`vftable';
  CDmElement::CDmElement(this: &this->CDmeDag, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->IDmeMatSysModel::__vftable = (CDmeMatSysDMXDag_vtbl *)&CDmeMatSysDMXDag::`vftable'{for `IDmeMatSysModel'};
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeMatSysDMXDag::`vftable'{for `CDmeDag'};
  this->m_eDmxRoot.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eDmxRoot.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eDmxRoot.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E7760
// Name: public: virtual bool CDmeMatSysDMXDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysDMXDag::IsA(CDmeMatSysDMXDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysDMXDag::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7790
// Name: public: virtual int CDmeMatSysDMXDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysDMXDag::GetInheritanceDepth(CDmeMatSysDMXDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysDMXDag::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E77E0
// Name: protected: virtual int CDmeMatSysDMXDag::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysDMXDag::AllocatedSize(CDmeTimeSelection *this)
{
  return 156;
}

//------------------------------------------------------------------------------
// Address: 0x004E77F0
// Name: protected: virtual void CDmeMatSysDMXDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysDMXDag::PerformConstruction(CDmeMatSysDMXDag *this)
{
  bool v2; // zf
  CDmeMatSysDMXDag *v3; // esi
  CDmElement *v4; // ecx
  CDmAttribute *v5; // eax
  DmElementHandle_t value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction((CDmeDag *)this);
  v2 = this == (CDmeMatSysDMXDag *)4;
  v3 = (CDmeMatSysDMXDag *)((char *)this - 4);
  value = DMELEMENT_HANDLE_INVALID;
  if ( v2 )
    v4 = nullptr;
  else
    v4 = &v3->CDmeDag;
  v5 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "dmxRoot",
         type: AT_FIRST_VALUE_TYPE,
         pMemory: &v3->m_eDmxRoot);
  v3->m_eDmxRoot.m_pAttribute = v5;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: v5, &value);
  v3->m_hDmxModel = DMELEMENT_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x004E78A0
// Name: protected: CDmeMatSysMPPDag::CDmeMatSysMPPDag(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMatSysMPPDag *__thiscall CDmeMatSysMPPDag::CDmeMatSysMPPDag(
        CDmeMatSysMPPDag *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMPPDag_vtbl *)&IDmeMatSysModel::`vftable';
  CDmElement::CDmElement(this: &this->CDmeDag, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->IDmeMatSysModel::__vftable = (CDmeMatSysMPPDag_vtbl *)&CDmeMatSysMPPDag::`vftable'{for `IDmeMatSysModel'};
  this->CDmeDag::CDmElement::__vftable = (CDmeDag_vtbl *)&CDmeMatSysMPPDag::`vftable'{for `CDmeDag'};
  this->m_eMppRoot.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eMppRoot.m_pAttribute = nullptr;
  this->m_eMppRoot.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_hChildren.m_Memory.m_pMemory = nullptr;
  this->m_hChildren.m_Memory.m_nAllocationCount = 0;
  this->m_hChildren.m_Memory.m_nGrowSize = 0;
  this->m_hChildren.m_Size = 0;
  this->m_hChildren.m_pElements = nullptr;
  this->m_dmeOperatorList.m_Memory.m_pMemory = nullptr;
  this->m_dmeOperatorList.m_Memory.m_nAllocationCount = 0;
  this->m_dmeOperatorList.m_Memory.m_nGrowSize = 0;
  this->m_dmeOperatorList.m_Size = 0;
  this->m_dmeOperatorList.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E7980
// Name: public: virtual bool CDmeMatSysMPPDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMatSysMPPDag::IsA(CDmeMatSysMPPDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMatSysMPPDag::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E79B0
// Name: public: virtual int CDmeMatSysMPPDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMPPDag::GetInheritanceDepth(CDmeMatSysMPPDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMatSysMPPDag::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7A00
// Name: protected: virtual void CDmeMatSysMPPDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysMPPDag::PerformConstruction(CDmeMatSysMPPDag *this)
{
  bool v2; // zf
  CDmeMatSysMPPDag *v3; // esi
  CDmElement *v4; // ecx
  CDmAttribute *v5; // eax
  DmElementHandle_t value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction((CDmeDag *)this);
  v2 = this == (CDmeMatSysMPPDag *)4;
  v3 = (CDmeMatSysMPPDag *)((char *)this - 4);
  value = DMELEMENT_HANDLE_INVALID;
  if ( v2 )
    v4 = nullptr;
  else
    v4 = &v3->CDmeDag;
  v5 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "mppRoot",
         type: AT_FIRST_VALUE_TYPE,
         pMemory: &v3->m_eMppRoot);
  v3->m_eMppRoot.m_pAttribute = v5;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: v5, &value);
  v3->m_hDmeBodyGroupList = DMELEMENT_HANDLE_INVALID;
  v3->m_hDmeSequenceList = DMELEMENT_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x005A3060
// Name: protected: virtual int CDmeMatSysMPPDag::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMatSysMPPDag::AllocatedSize(CDmeLog *this)
{
  return 204;
}

//------------------------------------------------------------------------------
// Address: 0x005A7810
// Name: protected: virtual void CDmeMatSysDMXDag::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMatSysDMXDag::PerformDestruction(CDmeRig *this)
{
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005E7C80
// Name: _dynamic_initializer_for__CDmeMatSysPanelSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysPanelSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysPanelSettings::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysPanelSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysPanelSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7CE0
// Name: _dynamic_initializer_for__CDmeMatSysRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysRoot::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysRoot::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysRoot pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysRoot::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7D40
// Name: _dynamic_initializer_for__CDmeMatSysMDLDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysMDLDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysMDLDag::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysMDLDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysMDLDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7DA0
// Name: _dynamic_initializer_for__CDmeMatSysDMXDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysDMXDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysDMXDag::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysDMXDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysDMXDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7E00
// Name: _dynamic_initializer_for__CDmeMatSysMPPDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMatSysMPPDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMatSysMPPDag::s_Allocator,
    blockSize: 204,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMatSysMPPDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMatSysMPPDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC9D0
// Name: _dynamic_atexit_destructor_for__CDmeMatSysPanelSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysPanelSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysPanelSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC9E0
// Name: _dynamic_atexit_destructor_for__CDmeMatSysRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysRoot::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysRoot::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC9F0
// Name: _dynamic_atexit_destructor_for__CDmeMatSysMDLDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysMDLDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysMDLDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECA00
// Name: _dynamic_atexit_destructor_for__CDmeMatSysDMXDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysDMXDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysDMXDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECA10
// Name: _dynamic_atexit_destructor_for__CDmeMatSysMPPDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMatSysMPPDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMatSysMPPDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004E61B0
// Name: class CDmeSequence __near * CastElement<class CDmeSequence>(class CDmElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSequence *__cdecl CastElement<CDmeSequence>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeSequence::m_classType.u.m_Id) )
  {
    return (CDmeSequence *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E7CB0
// Name: _dynamic_initializer_for__g_CDmeMatSysPanelSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysPanelSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysPanelSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7CC0
// Name: _dynamic_initializer_for__g_CDmeMatSysPanelSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysPanelSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysPanelSettings_Helper,
           classname: "DmeMatSysPanelSettings",
           pFactory: &g_CDmeMatSysPanelSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7D10
// Name: _dynamic_initializer_for__g_CDmeMatSysRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysRoot_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysRoot_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7D20
// Name: _dynamic_initializer_for__g_CDmeMatSysRoot_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysRoot_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysRoot_Helper,
           classname: "DmeMatSysRoot",
           pFactory: &g_CDmeMatSysRoot_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7D70
// Name: _dynamic_initializer_for__g_CDmeMatSysMDLDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysMDLDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysMDLDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7D80
// Name: _dynamic_initializer_for__g_CDmeMatSysMDLDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysMDLDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysMDLDag_Helper,
           classname: "DmeMatSysMDLDag",
           pFactory: &g_CDmeMatSysMDLDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7DD0
// Name: _dynamic_initializer_for__g_CDmeMatSysDMXDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysDMXDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysDMXDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7DE0
// Name: _dynamic_initializer_for__g_CDmeMatSysDMXDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysDMXDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysDMXDag_Helper,
           classname: "DmeMatSysDMXDag",
           pFactory: &g_CDmeMatSysDMXDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7E30
// Name: _dynamic_initializer_for__g_CDmeMatSysMPPDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMatSysMPPDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMatSysMPPDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7E40
// Name: _dynamic_initializer_for__g_CDmeMatSysMPPDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMatSysMPPDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMatSysMPPDag_Helper,
           classname: "DmeMatSysMPPDag",
           pFactory: &g_CDmeMatSysMPPDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ECA20
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysRoot_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysRoot_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ECA30
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysMDLDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysMDLDag_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysMDLDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ECA40
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysDMXDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysDMXDag_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysDMXDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ECA50
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysMPPDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysMPPDag_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysMPPDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ECA60
// Name: _dynamic_atexit_destructor_for__g_CDmeMatSysPanelSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMatSysPanelSettings_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMatSysPanelSettings_Factory.m_CallBackList);
}

} // namespace studiomdl
