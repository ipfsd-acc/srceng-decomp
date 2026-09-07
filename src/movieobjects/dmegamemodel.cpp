// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmegamemodel.cpp
// Functions: 53
// ============================================================

#include "movieobjects\dmegamemodel.h"

//------------------------------------------------------------------------------
// Address: 0x00498880
// Name: protected: virtual int CDmeGameSprite::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::AllocatedSize(CDmeVertexDeltaData *this)
{
  return 192;
}

//------------------------------------------------------------------------------
// Address: 0x005587D0
// Name: protected: virtual int CDmeGamePortal::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::AllocatedSize(CDmeSpotLight *this)
{
  return 208;
}

//------------------------------------------------------------------------------
// Address: 0x00558AD0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Operate(CDmeGlobalFlexControllerOperator *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // edx
  void *m_pData; // ebx
  DmAttributeType_t v5; // esi
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_pAttribute = this->m_flexWeight.m_pAttribute;
    m_pData = m_pAttribute->m_pData;
    v5 = m_pAttribute->m_nFlags & 0x1F;
    if ( (v2->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v2, valueType: v5, pValue: m_pData);
    }
    else if ( this->m_nFlexControllerIndex != -1 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v2);
      CDmrGenericArray::Set(this: &array, i: this->m_nFlexControllerIndex, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00558B50
// Name: public: void CDmeGlobalFlexControllerOperator::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::SetupToAttribute(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
    if ( Attribute != nullptr )
      this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: Attribute, bCreate: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00558B90
// Name: public: virtual void CDmeGameModel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnAttributeChanged(CDmeGameModel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_modelName.m_pAttribute )
    this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x00558BB0
// Name: protected: void CDmeGameModel::UpdateHMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::UpdateHMDL(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // di

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  v3 = -1;
  if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
    v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( this->m_hMDL != 0xFFFF )
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_hMDL);
  this->m_hMDL = v3;
  this->m_bHMDLDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00558C10
// Name: protected: void CDmeGameSprite::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::OnConstruction(CDmeGameSprite *this)
{
  this->m_modelName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "modelName",
                                     type: AT_STRING,
                                     pMemory: &this->m_modelName);
  this->m_frame.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "frame",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_frame);
  this->m_rendermode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "rendermode",
                                      type: AT_INT,
                                      pMemory: &this->m_rendermode);
  this->m_renderfx.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "renderfx",
                                    type: AT_INT,
                                    pMemory: &this->m_renderfx);
  this->m_renderscale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "renderscale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_renderscale);
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  this->m_proxyRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "proxyRadius",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_proxyRadius);
}

//------------------------------------------------------------------------------
// Address: 0x00558CC0
// Name: protected: void CDmeGamePortal::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::OnConstruction(CDmeGamePortal *this)
{
  this->m_flStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "staticAmount",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flStaticAmount);
  this->m_flSecondaryStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "secondaryStaticAmount",
                                                   type: AT_FLOAT,
                                                   pMemory: &this->m_flSecondaryStaticAmount);
  this->m_flOpenAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "openAmount",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flOpenAmount);
  this->m_flHalfWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "halfWidth",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flHalfWidth);
  this->m_flHalfHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "halfHeight",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flHalfHeight);
  this->m_nPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "portalId",
                                     type: AT_INT,
                                     pMemory: &this->m_nPortalId);
  this->m_nLinkedPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "linkedPortalId",
                                           type: AT_INT,
                                           pMemory: &this->m_nLinkedPortalId);
  this->m_bIsPortal2.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isPortal2",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsPortal2);
  this->m_PortalType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "portalType",
                                      type: AT_STRING,
                                      pMemory: &this->m_PortalType);
}

//------------------------------------------------------------------------------
// Address: 0x00558DA0
// Name: protected: void CDmeGlobalFlexControllerOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_flexWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "flexWeight",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flexWeight);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_gameModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "gameModel",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_gameModel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_gameModel.m_pAttribute, typeSymbol: CDmeGameModel::m_classType);
  this->m_gameModel.m_pAttribute->m_nFlags |= 0x1100u;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_nFlexControllerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00558E10
// Name: protected: void CDmeGameModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnConstruction(CDmeGameModel *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_flexWeights,
    pOwner: this,
    pAttributeName: "flexWeights",
    nFlags: 0);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "modelName", type: AT_STRING, pMemory: &this->m_modelName);
  this->m_modelName.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  this->m_skin.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "skin",
                                type: AT_INT,
                                pMemory: &this->m_skin);
  this->m_body.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "body",
                                type: AT_INT,
                                pMemory: &this->m_body);
  this->m_sequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "sequence",
                                    type: AT_INT,
                                    pMemory: &this->m_sequence);
  this->m_flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_flags);
  this->m_bones.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "bones",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_bones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_bones.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  this->m_globalFlexControllers.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "globalFlexControllers",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_globalFlexControllers);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_globalFlexControllers.m_pAttribute,
    typeSymbol: CDmeGlobalFlexControllerOperator::m_classType);
  this->m_bComputeBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "computeBounds",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bComputeBounds);
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "evaluateProceduralBones",
         type: AT_BOOL,
         pMemory: &this->m_bEvaluateProceduralBones);
  this->m_bEvaluateProceduralBones.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_hMDL = -1;
  this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x00558F60
// Name: public: void CDmeGameModel::SetNumFlexWeights(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::SetNumFlexWeights(CDmeGameModel *this, unsigned int nFlexWeights)
{
  unsigned int m_Size; // eax
  unsigned int v4; // edi

  m_Size = this->m_flexWeights.m_Storage.m_Size;
  v4 = nFlexWeights;
  if ( m_Size >= nFlexWeights )
  {
    if ( m_Size > nFlexWeights )
    {
      do
      {
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
          this: &this->m_flexWeights,
          elem: m_Size - 1);
        m_Size = this->m_flexWeights.m_Storage.m_Size;
      }
      while ( m_Size > v4 );
    }
  }
  else
  {
    do
    {
      nFlexWeights = 0;
      CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &this->m_flexWeights,
        src: (float *)&nFlexWeights);
    }
    while ( this->m_flexWeights.m_Storage.m_Size < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00558FC0
// Name: private: int CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(void)const
// Source: json
//------------------------------------------------------------------------------
DmAttributeHandle_t __thiscall CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(
        CDmeGlobalFlexControllerOperator *this)
{
  CDmeGameModel *v1; // eax
  CDmeGameModel *v2; // esi
  int m_hMDL; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // edi
  int j; // ebx
  char *v7; // esi
  const char *m_pAsString; // ecx
  DmAttributeHandle_t v10; // edi
  CDmeGameModel *v11; // eax
  int fc; // [esp+8h] [ebp-Ch]
  LocalFlexController_t i; // [esp+10h] [ebp-4h]

  v1 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  v2 = v1;
  if ( v1->m_bHMDLDirty )
    CDmeGameModel::UpdateHMDL(this: v1);
  m_hMDL = v2->m_hMDL;
  if ( (_WORD)m_hMDL == 0xFFFF )
    return DMATTRIBUTE_HANDLE_INVALID;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: m_hMDL);
  v5 = v4;
  if ( v4 == nullptr )
    return DMATTRIBUTE_HANDLE_INVALID;
  fc = v4->numflexcontrollers;
  i = DUMMY_NULL_FLEX_CONTROLLER;
  if ( fc <= 0 )
    return DMATTRIBUTE_HANDLE_INVALID;
  for ( j = 0; ; j += 20 )
  {
    v7 = (char *)v5 + j + v5->flexcontrollerindex;
    if ( *((_DWORD *)v7 + 2) == -1 && g_pGlobalFlexController != nullptr )
      *((_DWORD *)v7 + 2) = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v7[*((_DWORD *)v7 + 1)]);
    m_pAsString = var;
    if ( this->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
      m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( _V_stricmp(s1: &v7[*((_DWORD *)v7 + 1)], s2: m_pAsString) == 0 )
      break;
    if ( ++i >= fc )
      return DMATTRIBUTE_HANDLE_INVALID;
  }
  v10 = *((_DWORD *)v7 + 2);
  if ( (unsigned int)v10 >= g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle)[2].m_ref.m_attributes.m_hAttribute )
  {
    v11 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
    CDmeGameModel::SetNumFlexWeights(this: v11, nFlexWeights: *((_DWORD *)v7 + 2) + 1);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00559100
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Resolve(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  if ( this->m_ToAttributeHandle < 0 )
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  if ( this->m_gameModel.m_pAttribute == (CDmAttribute *)-1 )
  {
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute);
    if ( v2 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
      if ( Attribute != nullptr )
        this->m_gameModel.m_pAttribute = (CDmAttribute *)CDmAttribute::GetHandle(this: Attribute, bCreate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00559150
// Name: public: virtual void CDmeGlobalFlexControllerOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnAttributeChanged(
        CDmeGlobalFlexControllerOperator *this,
        CDmAttribute *pAttribute)
{
  if ( g_pGlobalFlexController != nullptr
    && pAttribute == (CDmAttribute *)this->m_gameModel.m_Storage.m_ElementType.u.m_Id
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute) != nullptr )
  {
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
    CDmeGlobalFlexControllerOperator::SetupToAttribute(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x005591A0
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&this->m_boneParent);
  CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&this->m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x005591D0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *v2; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v6 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00559300
// Name: public: virtual bool CDmeGlobalFlexControllerOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGlobalFlexControllerOperator::IsA(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00559330
// Name: public: virtual int CDmeGlobalFlexControllerOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGlobalFlexControllerOperator::GetInheritanceDepth(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00559400
// Name: protected: virtual void CDmeGlobalFlexControllerOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::PerformConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  CDmeGlobalFlexControllerOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00559540
// Name: protected: CDmeGameModel::CDmeGameModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CDmeGameModel::CDmeGameModel(
        CDmeGameModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeGameModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_globalFlexControllers);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_flexWeights);
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_skin.m_pAttribute = nullptr;
  this->m_skin.m_Storage = 0;
  this->m_body.m_pAttribute = nullptr;
  this->m_body.m_Storage = 0;
  this->m_sequence.m_pAttribute = nullptr;
  this->m_sequence.m_Storage = 0;
  this->m_flags.m_pAttribute = nullptr;
  this->m_flags.m_Storage = 0;
  this->m_bComputeBounds.m_pAttribute = nullptr;
  this->m_bComputeBounds.m_Storage = false;
  this->m_bEvaluateProceduralBones.m_pAttribute = nullptr;
  this->m_bEvaluateProceduralBones.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_bones);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00559620
// Name: public: virtual bool CDmeGameModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameModel::IsA(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00559650
// Name: public: virtual int CDmeGameModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::GetInheritanceDepth(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005596A0
// Name: protected: virtual void CDmeGameModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformDestruction(CDmeGameModel *this)
{
  int m_hMDL; // eax

  m_hMDL = this->m_hMDL;
  if ( (_WORD)m_hMDL != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: m_hMDL);
    this->m_hMDL = -1;
  }
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005596E0
// Name: protected: virtual int CDmeGameModel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::AllocatedSize(CDmeGameModel *this)
{
  return 276;
}

//------------------------------------------------------------------------------
// Address: 0x005596F0
// Name: protected: virtual void CDmeGameModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformConstruction(CDmeGameModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00559770
// Name: protected: CDmeGameSprite::CDmeGameSprite(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSprite *__thiscall CDmeGameSprite::CDmeGameSprite(
        CDmeGameSprite *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeGameSprite::`vftable';
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_frame.m_pAttribute = nullptr;
  this->m_frame.m_Storage = 0.0;
  this->m_rendermode.m_pAttribute = nullptr;
  this->m_rendermode.m_Storage = 0;
  this->m_renderfx.m_pAttribute = nullptr;
  this->m_renderfx.m_Storage = 0;
  this->m_renderscale.m_pAttribute = nullptr;
  this->m_renderscale.m_Storage = 0.0;
  this->m_color.m_pAttribute = nullptr;
  this->m_color.m_Storage = (Color)-16777216;
  this->m_proxyRadius.m_pAttribute = nullptr;
  this->m_proxyRadius.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00559840
// Name: public: virtual bool CDmeGameSprite::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSprite::IsA(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00559870
// Name: public: virtual int CDmeGameSprite::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::GetInheritanceDepth(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005598C0
// Name: protected: virtual void CDmeGameSprite::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::PerformConstruction(CDmeGameSprite *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameSprite::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00559920
// Name: protected: CDmeGamePortal::CDmeGamePortal(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGamePortal *__thiscall CDmeGamePortal::CDmeGamePortal(
        CDmeGamePortal *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeGamePortal::`vftable';
  this->m_nPortalId.m_pAttribute = nullptr;
  this->m_nPortalId.m_Storage = 0;
  this->m_nLinkedPortalId.m_pAttribute = nullptr;
  this->m_nLinkedPortalId.m_Storage = 0;
  this->m_flStaticAmount.m_pAttribute = nullptr;
  this->m_flStaticAmount.m_Storage = 0.0;
  this->m_flSecondaryStaticAmount.m_pAttribute = nullptr;
  this->m_flSecondaryStaticAmount.m_Storage = 0.0;
  this->m_flOpenAmount.m_pAttribute = nullptr;
  this->m_flOpenAmount.m_Storage = 0.0;
  this->m_flHalfWidth.m_pAttribute = nullptr;
  this->m_flHalfWidth.m_Storage = 0.0;
  this->m_flHalfHeight.m_pAttribute = nullptr;
  this->m_flHalfHeight.m_Storage = 0.0;
  this->m_bIsPortal2.m_pAttribute = nullptr;
  this->m_bIsPortal2.m_Storage = false;
  this->m_PortalType.m_Storage.u.m_Id = -1;
  this->m_PortalType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00559A00
// Name: public: virtual bool CDmeGamePortal::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGamePortal::IsA(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00559A30
// Name: public: virtual int CDmeGamePortal::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::GetInheritanceDepth(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00559A80
// Name: protected: virtual void CDmeGamePortal::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::PerformConstruction(CDmeGamePortal *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGamePortal::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005ADAD0
// Name: _dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGlobalFlexControllerOperator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGlobalFlexControllerOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADB30
// Name: _dynamic_initializer_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameModel::s_Allocator,
    blockSize: 276,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADB90
// Name: _dynamic_initializer_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSprite::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSprite pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADBF0
// Name: _dynamic_initializer_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGamePortal::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGamePortal pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B04F0
// Name: _dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGlobalFlexControllerOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0500
// Name: _dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0510
// Name: _dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSprite::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0520
// Name: _dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGamePortal::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ADB00
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADB10
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGlobalFlexControllerOperator_Helper,
           classname: "DmeGlobalFlexControllerOperator",
           pFactory: &g_CDmeGlobalFlexControllerOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ADB60
// Name: _dynamic_initializer_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADB70
// Name: _dynamic_initializer_for__g_CDmeGameModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameModel_Helper,
           classname: "DmeGameModel",
           pFactory: &g_CDmeGameModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ADBC0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSprite_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADBD0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSprite_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSprite_Helper,
           classname: "DmeGameSprite",
           pFactory: &g_CDmeGameSprite_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ADC20
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGamePortal_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADC30
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGamePortal_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGamePortal_Helper,
           classname: "DmeGamePortal",
           pFactory: &g_CDmeGamePortal_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0530
// Name: _dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0540
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSprite_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0550
// Name: _dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGamePortal_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0560
// Name: _dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGlobalFlexControllerOperator_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004FA800
// Name: protected: virtual int CDmeGameSprite::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::AllocatedSize(CDmeVertexDeltaData *this)
{
  return 192;
}

//------------------------------------------------------------------------------
// Address: 0x005AFC20
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Operate(CDmeGlobalFlexControllerOperator *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // edx
  void *m_pData; // ebx
  DmAttributeType_t v5; // esi
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_pAttribute = this->m_flexWeight.m_pAttribute;
    m_pData = m_pAttribute->m_pData;
    v5 = m_pAttribute->m_nFlags & 0x1F;
    if ( (v2->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v2, valueType: v5, pValue: m_pData);
    }
    else if ( this->m_nFlexControllerIndex != -1 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v2);
      CDmrGenericArray::Set(this: &array, i: this->m_nFlexControllerIndex, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AFCA0
// Name: public: void CDmeGlobalFlexControllerOperator::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::SetupToAttribute(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
    if ( Attribute != nullptr )
      this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: Attribute, bCreate: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AFCE0
// Name: public: virtual void CDmeGameModel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnAttributeChanged(CDmeGameModel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_modelName.m_pAttribute )
    this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x005AFD00
// Name: protected: void CDmeGameModel::UpdateHMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::UpdateHMDL(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // di

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  v3 = -1;
  if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
    v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( this->m_hMDL != 0xFFFF )
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_hMDL);
  this->m_hMDL = v3;
  this->m_bHMDLDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x005AFD60
// Name: protected: void CDmeGameSprite::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::OnConstruction(CDmeGameSprite *this)
{
  this->m_modelName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "modelName",
                                     type: AT_STRING,
                                     pMemory: &this->m_modelName);
  this->m_frame.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "frame",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_frame);
  this->m_rendermode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "rendermode",
                                      type: AT_INT,
                                      pMemory: &this->m_rendermode);
  this->m_renderfx.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "renderfx",
                                    type: AT_INT,
                                    pMemory: &this->m_renderfx);
  this->m_renderscale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "renderscale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_renderscale);
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  this->m_proxyRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "proxyRadius",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_proxyRadius);
}

//------------------------------------------------------------------------------
// Address: 0x005AFE10
// Name: protected: void CDmeGamePortal::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::OnConstruction(CDmeGamePortal *this)
{
  this->m_flStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "staticAmount",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flStaticAmount);
  this->m_flSecondaryStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "secondaryStaticAmount",
                                                   type: AT_FLOAT,
                                                   pMemory: &this->m_flSecondaryStaticAmount);
  this->m_flOpenAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "openAmount",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flOpenAmount);
  this->m_flHalfWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "halfWidth",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flHalfWidth);
  this->m_flHalfHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "halfHeight",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flHalfHeight);
  this->m_nPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "portalId",
                                     type: AT_INT,
                                     pMemory: &this->m_nPortalId);
  this->m_nLinkedPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "linkedPortalId",
                                           type: AT_INT,
                                           pMemory: &this->m_nLinkedPortalId);
  this->m_bIsPortal2.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isPortal2",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsPortal2);
  this->m_PortalType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "portalType",
                                      type: AT_STRING,
                                      pMemory: &this->m_PortalType);
}

//------------------------------------------------------------------------------
// Address: 0x005AFEF0
// Name: protected: void CDmeGlobalFlexControllerOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_flexWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "flexWeight",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flexWeight);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_gameModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "gameModel",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_gameModel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_gameModel.m_pAttribute, typeSymbol: CDmeGameModel::m_classType);
  this->m_gameModel.m_pAttribute->m_nFlags |= 0x1100u;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_nFlexControllerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AFF60
// Name: protected: void CDmeGameModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnConstruction(CDmeGameModel *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_flexWeights,
    pOwner: this,
    pAttributeName: "flexWeights",
    nFlags: 0);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "modelName", type: AT_STRING, pMemory: &this->m_modelName);
  this->m_modelName.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  this->m_skin.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "skin",
                                type: AT_INT,
                                pMemory: &this->m_skin);
  this->m_body.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "body",
                                type: AT_INT,
                                pMemory: &this->m_body);
  this->m_sequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "sequence",
                                    type: AT_INT,
                                    pMemory: &this->m_sequence);
  this->m_flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_flags);
  this->m_bones.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "bones",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_bones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_bones.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  this->m_globalFlexControllers.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "globalFlexControllers",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_globalFlexControllers);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_globalFlexControllers.m_pAttribute,
    typeSymbol: CDmeGlobalFlexControllerOperator::m_classType);
  this->m_bComputeBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "computeBounds",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bComputeBounds);
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "evaluateProceduralBones",
         type: AT_BOOL,
         pMemory: &this->m_bEvaluateProceduralBones);
  this->m_bEvaluateProceduralBones.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_hMDL = -1;
  this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x005B00B0
// Name: public: void CDmeGameModel::SetNumFlexWeights(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::SetNumFlexWeights(CDmeGameModel *this, unsigned int nFlexWeights)
{
  unsigned int m_Size; // eax
  unsigned int v4; // edi

  m_Size = this->m_flexWeights.m_Storage.m_Size;
  v4 = nFlexWeights;
  if ( m_Size >= nFlexWeights )
  {
    if ( m_Size > nFlexWeights )
    {
      do
      {
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
          this: &this->m_flexWeights,
          elem: m_Size - 1);
        m_Size = this->m_flexWeights.m_Storage.m_Size;
      }
      while ( m_Size > v4 );
    }
  }
  else
  {
    do
    {
      nFlexWeights = 0;
      CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &this->m_flexWeights,
        src: (float *)&nFlexWeights);
    }
    while ( this->m_flexWeights.m_Storage.m_Size < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B0110
// Name: private: int CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(void)const
// Source: json
//------------------------------------------------------------------------------
DmAttributeHandle_t __thiscall CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(
        CDmeGlobalFlexControllerOperator *this)
{
  CDmeGameModel *v1; // eax
  CDmeGameModel *v2; // esi
  int m_hMDL; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // edi
  int j; // ebx
  char *v7; // esi
  const char *m_pAsString; // ecx
  DmAttributeHandle_t v10; // edi
  CDmeGameModel *v11; // eax
  int fc; // [esp+8h] [ebp-Ch]
  LocalFlexController_t i; // [esp+10h] [ebp-4h]

  v1 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  v2 = v1;
  if ( v1->m_bHMDLDirty )
    CDmeGameModel::UpdateHMDL(this: v1);
  m_hMDL = v2->m_hMDL;
  if ( (_WORD)m_hMDL == 0xFFFF )
    return DMATTRIBUTE_HANDLE_INVALID;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: m_hMDL);
  v5 = v4;
  if ( v4 == nullptr )
    return DMATTRIBUTE_HANDLE_INVALID;
  fc = v4->numflexcontrollers;
  i = DUMMY_NULL_FLEX_CONTROLLER;
  if ( fc <= 0 )
    return DMATTRIBUTE_HANDLE_INVALID;
  for ( j = 0; ; j += 20 )
  {
    v7 = (char *)v5 + j + v5->flexcontrollerindex;
    if ( *((_DWORD *)v7 + 2) == -1 && g_pGlobalFlexController != nullptr )
      *((_DWORD *)v7 + 2) = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v7[*((_DWORD *)v7 + 1)]);
    m_pAsString = defaultValue;
    if ( this->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
      m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( _V_stricmp(s1: &v7[*((_DWORD *)v7 + 1)], s2: m_pAsString) == 0 )
      break;
    if ( ++i >= fc )
      return DMATTRIBUTE_HANDLE_INVALID;
  }
  v10 = *((_DWORD *)v7 + 2);
  if ( (unsigned int)v10 >= g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle)[2].m_ref.m_attributes.m_hAttribute )
  {
    v11 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
    CDmeGameModel::SetNumFlexWeights(this: v11, nFlexWeights: *((_DWORD *)v7 + 2) + 1);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x005B0250
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Resolve(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  if ( this->m_ToAttributeHandle < 0 )
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  if ( this->m_gameModel.m_pAttribute == (CDmAttribute *)-1 )
  {
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute);
    if ( v2 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
      if ( Attribute != nullptr )
        this->m_gameModel.m_pAttribute = (CDmAttribute *)CDmAttribute::GetHandle(this: Attribute, bCreate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B02A0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnAttributeChanged(
        CDmeGlobalFlexControllerOperator *this,
        CDmAttribute *pAttribute)
{
  if ( g_pGlobalFlexController != nullptr
    && pAttribute == (CDmAttribute *)this->m_gameModel.m_Storage.m_ElementType.u.m_Id
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute) != nullptr )
  {
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
    CDmeGlobalFlexControllerOperator::SetupToAttribute(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B02F0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *v2; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v5 = (CDmAttribute **)attrs->m_pMemory;
    v6 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &v5[m_pMemory + 1], src: &v5[m_pMemory], count: 4 * v6);
    v7 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B0420
// Name: public: virtual bool CDmeGlobalFlexControllerOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGlobalFlexControllerOperator::IsA(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B0450
// Name: public: virtual int CDmeGlobalFlexControllerOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGlobalFlexControllerOperator::GetInheritanceDepth(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B0660
// Name: protected: CDmeGameModel::CDmeGameModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CDmeGameModel::CDmeGameModel(
        CDmeGameModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeGameModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_globalFlexControllers);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_flexWeights);
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_skin.m_pAttribute = nullptr;
  this->m_skin.m_Storage = 0;
  this->m_body.m_pAttribute = nullptr;
  this->m_body.m_Storage = 0;
  this->m_sequence.m_pAttribute = nullptr;
  this->m_sequence.m_Storage = 0;
  this->m_flags.m_pAttribute = nullptr;
  this->m_flags.m_Storage = 0;
  this->m_bComputeBounds.m_pAttribute = nullptr;
  this->m_bComputeBounds.m_Storage = false;
  this->m_bEvaluateProceduralBones.m_pAttribute = nullptr;
  this->m_bEvaluateProceduralBones.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_bones);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B0740
// Name: public: virtual bool CDmeGameModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameModel::IsA(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B0770
// Name: public: virtual int CDmeGameModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::GetInheritanceDepth(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B07C0
// Name: protected: virtual void CDmeGameModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformDestruction(CDmeGameModel *this)
{
  int m_hMDL; // eax

  m_hMDL = this->m_hMDL;
  if ( (_WORD)m_hMDL != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: m_hMDL);
    this->m_hMDL = -1;
  }
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005B0810
// Name: protected: virtual void CDmeGameModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformConstruction(CDmeGameModel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeGameModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005B0890
// Name: protected: CDmeGameSprite::CDmeGameSprite(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSprite *__thiscall CDmeGameSprite::CDmeGameSprite(
        CDmeGameSprite *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeGameSprite::`vftable';
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_frame.m_pAttribute = nullptr;
  this->m_frame.m_Storage = 0.0;
  this->m_rendermode.m_pAttribute = nullptr;
  this->m_rendermode.m_Storage = 0;
  this->m_renderfx.m_pAttribute = nullptr;
  this->m_renderfx.m_Storage = 0;
  this->m_renderscale.m_pAttribute = nullptr;
  this->m_renderscale.m_Storage = 0.0;
  this->m_color.m_pAttribute = nullptr;
  this->m_color.m_Storage = (Color)-16777216;
  this->m_proxyRadius.m_pAttribute = nullptr;
  this->m_proxyRadius.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B0960
// Name: public: virtual bool CDmeGameSprite::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSprite::IsA(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B0990
// Name: public: virtual int CDmeGameSprite::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::GetInheritanceDepth(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B09E0
// Name: protected: virtual void CDmeGameSprite::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::PerformConstruction(CDmeGameSprite *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeGameSprite::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005B0A40
// Name: protected: CDmeGamePortal::CDmeGamePortal(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGamePortal *__thiscall CDmeGamePortal::CDmeGamePortal(
        CDmeGamePortal *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeGamePortal::`vftable';
  this->m_nPortalId.m_pAttribute = nullptr;
  this->m_nPortalId.m_Storage = 0;
  this->m_nLinkedPortalId.m_pAttribute = nullptr;
  this->m_nLinkedPortalId.m_Storage = 0;
  this->m_flStaticAmount.m_pAttribute = nullptr;
  this->m_flStaticAmount.m_Storage = 0.0;
  this->m_flSecondaryStaticAmount.m_pAttribute = nullptr;
  this->m_flSecondaryStaticAmount.m_Storage = 0.0;
  this->m_flOpenAmount.m_pAttribute = nullptr;
  this->m_flOpenAmount.m_Storage = 0.0;
  this->m_flHalfWidth.m_pAttribute = nullptr;
  this->m_flHalfWidth.m_Storage = 0.0;
  this->m_flHalfHeight.m_pAttribute = nullptr;
  this->m_flHalfHeight.m_Storage = 0.0;
  this->m_bIsPortal2.m_pAttribute = nullptr;
  this->m_bIsPortal2.m_Storage = false;
  this->m_PortalType.m_Storage.u.m_Id = -1;
  this->m_PortalType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B0B20
// Name: public: virtual bool CDmeGamePortal::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGamePortal::IsA(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B0B50
// Name: public: virtual int CDmeGamePortal::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::GetInheritanceDepth(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B0BA0
// Name: protected: virtual int CDmeGamePortal::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::AllocatedSize(CDmeSpotLight *this)
{
  return 208;
}

//------------------------------------------------------------------------------
// Address: 0x005B0BB0
// Name: protected: virtual void CDmeGamePortal::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::PerformConstruction(CDmeGamePortal *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeGamePortal::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0067F2C0
// Name: _dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGlobalFlexControllerOperator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGlobalFlexControllerOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F320
// Name: _dynamic_initializer_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameModel::s_Allocator,
    blockSize: 276,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F380
// Name: _dynamic_initializer_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSprite::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSprite pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F3E0
// Name: _dynamic_initializer_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGamePortal::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGamePortal pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682A00
// Name: _dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGlobalFlexControllerOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682A10
// Name: _dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682A20
// Name: _dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSprite::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682A30
// Name: _dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGamePortal::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067F2F0
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F300
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGlobalFlexControllerOperator_Helper,
           classname: "DmeGlobalFlexControllerOperator",
           pFactory: &g_CDmeGlobalFlexControllerOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F350
// Name: _dynamic_initializer_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F360
// Name: _dynamic_initializer_for__g_CDmeGameModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameModel_Helper,
           classname: "DmeGameModel",
           pFactory: &g_CDmeGameModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F3B0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSprite_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F3C0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSprite_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSprite_Helper,
           classname: "DmeGameSprite",
           pFactory: &g_CDmeGameSprite_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F410
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGamePortal_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F420
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGamePortal_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGamePortal_Helper,
           classname: "DmeGamePortal",
           pFactory: &g_CDmeGamePortal_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682A40
// Name: _dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeGameModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682A50
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeGameSprite_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682A60
// Name: _dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeGamePortal_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682A70
// Name: _dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeGlobalFlexControllerOperator_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10599A90
// Name: protected: virtual int CDmeGameSprite::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::AllocatedSize(CDmeVertexDeltaData *this)
{
  return 192;
}

//------------------------------------------------------------------------------
// Address: 0x1059A800
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Operate(CDmeGlobalFlexControllerOperator *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // edx
  void *m_pData; // ebx
  DmAttributeType_t v5; // esi
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_pAttribute = this->m_flexWeight.m_pAttribute;
    m_pData = m_pAttribute->m_pData;
    v5 = m_pAttribute->m_nFlags & 0x1F;
    if ( (v2->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v2, valueType: v5, pValue: m_pData);
    }
    else if ( this->m_nFlexControllerIndex != -1 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v2);
      CDmrGenericArray::Set(this: &array, i: this->m_nFlexControllerIndex, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059A880
// Name: public: void CDmeGlobalFlexControllerOperator::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::SetupToAttribute(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
    if ( Attribute != nullptr )
      this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: Attribute, bCreate: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059A8C0
// Name: public: virtual void CDmeGameModel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnAttributeChanged(CDmeGameModel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_modelName.m_pAttribute )
    this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x1059A8E0
// Name: protected: void CDmeGameModel::UpdateHMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::UpdateHMDL(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // di

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  v3 = -1;
  if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
    v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( this->m_hMDL != 0xFFFF )
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_hMDL);
  this->m_hMDL = v3;
  this->m_bHMDLDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x1059A940
// Name: protected: void CDmeGameSprite::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::OnConstruction(CDmeGameSprite *this)
{
  this->m_modelName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "modelName",
                                     type: AT_STRING,
                                     pMemory: &this->m_modelName);
  this->m_frame.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "frame",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_frame);
  this->m_rendermode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "rendermode",
                                      type: AT_INT,
                                      pMemory: &this->m_rendermode);
  this->m_renderfx.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "renderfx",
                                    type: AT_INT,
                                    pMemory: &this->m_renderfx);
  this->m_renderscale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "renderscale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_renderscale);
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  this->m_proxyRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "proxyRadius",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_proxyRadius);
}

//------------------------------------------------------------------------------
// Address: 0x1059A9F0
// Name: protected: void CDmeGamePortal::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::OnConstruction(CDmeGamePortal *this)
{
  this->m_flStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "staticAmount",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flStaticAmount);
  this->m_flSecondaryStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "secondaryStaticAmount",
                                                   type: AT_FLOAT,
                                                   pMemory: &this->m_flSecondaryStaticAmount);
  this->m_flOpenAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "openAmount",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flOpenAmount);
  this->m_flHalfWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "halfWidth",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flHalfWidth);
  this->m_flHalfHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "halfHeight",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flHalfHeight);
  this->m_nPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "portalId",
                                     type: AT_INT,
                                     pMemory: &this->m_nPortalId);
  this->m_nLinkedPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "linkedPortalId",
                                           type: AT_INT,
                                           pMemory: &this->m_nLinkedPortalId);
  this->m_bIsPortal2.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isPortal2",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsPortal2);
  this->m_PortalType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "portalType",
                                      type: AT_STRING,
                                      pMemory: &this->m_PortalType);
}

//------------------------------------------------------------------------------
// Address: 0x1059AAD0
// Name: protected: void CDmeGlobalFlexControllerOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_flexWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "flexWeight",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flexWeight);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_gameModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "gameModel",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_gameModel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_gameModel.m_pAttribute, typeSymbol: CDmeGameModel::m_classType);
  this->m_gameModel.m_pAttribute->m_nFlags |= 0x1100u;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_nFlexControllerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059AB40
// Name: protected: void CDmeGameModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnConstruction(CDmeGameModel *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_flexWeights,
    pOwner: this,
    pAttributeName: "flexWeights",
    nFlags: 0);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "modelName", type: AT_STRING, pMemory: &this->m_modelName);
  this->m_modelName.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  this->m_skin.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "skin",
                                type: AT_INT,
                                pMemory: &this->m_skin);
  this->m_body.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "body",
                                type: AT_INT,
                                pMemory: &this->m_body);
  this->m_sequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "sequence",
                                    type: AT_INT,
                                    pMemory: &this->m_sequence);
  this->m_flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_flags);
  this->m_bones.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "bones",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_bones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_bones.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  this->m_globalFlexControllers.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "globalFlexControllers",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_globalFlexControllers);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_globalFlexControllers.m_pAttribute,
    typeSymbol: CDmeGlobalFlexControllerOperator::m_classType);
  this->m_bComputeBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "computeBounds",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bComputeBounds);
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "evaluateProceduralBones",
         type: AT_BOOL,
         pMemory: &this->m_bEvaluateProceduralBones);
  this->m_bEvaluateProceduralBones.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_hMDL = -1;
  this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x1059AC90
// Name: public: void CDmeGameModel::SetNumFlexWeights(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::SetNumFlexWeights(CDmeGameModel *this, unsigned int nFlexWeights)
{
  unsigned int m_Size; // eax
  unsigned int v4; // edi

  m_Size = this->m_flexWeights.m_Storage.m_Size;
  v4 = nFlexWeights;
  if ( m_Size >= nFlexWeights )
  {
    if ( m_Size > nFlexWeights )
    {
      do
      {
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
          this: &this->m_flexWeights,
          elem: m_Size - 1);
        m_Size = this->m_flexWeights.m_Storage.m_Size;
      }
      while ( m_Size > v4 );
    }
  }
  else
  {
    do
    {
      nFlexWeights = 0;
      CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &this->m_flexWeights,
        src: (const float *)&nFlexWeights);
    }
    while ( this->m_flexWeights.m_Storage.m_Size < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059ACF0
// Name: private: int CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(void)const
// Source: json
//------------------------------------------------------------------------------
DmAttributeHandle_t __thiscall CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(
        CDmeGlobalFlexControllerOperator *this)
{
  CDmeGameModel *v1; // eax
  CDmeGameModel *v2; // esi
  int m_hMDL; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // edi
  int j; // ebx
  char *v7; // esi
  const char *m_pAsString; // ecx
  DmAttributeHandle_t v10; // edi
  CDmeGameModel *v11; // eax
  int fc; // [esp+8h] [ebp-Ch]
  LocalFlexController_t i; // [esp+10h] [ebp-4h]

  v1 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  v2 = v1;
  if ( v1->m_bHMDLDirty )
    CDmeGameModel::UpdateHMDL(this: v1);
  m_hMDL = v2->m_hMDL;
  if ( (_WORD)m_hMDL == 0xFFFF )
    return DMATTRIBUTE_HANDLE_INVALID;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: m_hMDL);
  v5 = v4;
  if ( v4 == nullptr )
    return DMATTRIBUTE_HANDLE_INVALID;
  fc = v4->numflexcontrollers;
  i = DUMMY_NULL_FLEX_CONTROLLER;
  if ( fc <= 0 )
    return DMATTRIBUTE_HANDLE_INVALID;
  for ( j = 0; ; j += 20 )
  {
    v7 = (char *)v5 + j + v5->flexcontrollerindex;
    if ( *((_DWORD *)v7 + 2) == -1 && g_pGlobalFlexController != nullptr )
      *((_DWORD *)v7 + 2) = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v7[*((_DWORD *)v7 + 1)]);
    m_pAsString = &var;
    if ( this->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
      m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( _V_stricmp(s1: &v7[*((_DWORD *)v7 + 1)], s2: m_pAsString) == 0 )
      break;
    if ( ++i >= fc )
      return DMATTRIBUTE_HANDLE_INVALID;
  }
  v10 = *((_DWORD *)v7 + 2);
  if ( (unsigned int)v10 >= g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle)[2].m_ref.m_attributes.m_hAttribute )
  {
    v11 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
    CDmeGameModel::SetNumFlexWeights(this: v11, nFlexWeights: *((_DWORD *)v7 + 2) + 1);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1059AE30
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Resolve(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  if ( this->m_ToAttributeHandle < 0 )
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  if ( this->m_gameModel.m_pAttribute == (CDmAttribute *)-1 )
  {
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute);
    if ( v2 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
      if ( Attribute != nullptr )
        this->m_gameModel.m_pAttribute = (CDmAttribute *)CDmAttribute::GetHandle(this: Attribute, bCreate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059AE80
// Name: public: virtual void CDmeGlobalFlexControllerOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnAttributeChanged(
        CDmeGlobalFlexControllerOperator *this,
        CDmAttribute *pAttribute)
{
  if ( g_pGlobalFlexController != nullptr
    && pAttribute == (CDmAttribute *)this->m_gameModel.m_Storage.m_ElementType.u.m_Id
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute) != nullptr )
  {
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
    CDmeGlobalFlexControllerOperator::SetupToAttribute(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059AF30
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *v2; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v5 = (CDmAttribute **)attrs->m_pMemory;
    v6 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v5[m_pMemory + 1], src: (unsigned __int8 *)&v5[m_pMemory], count: 4 * v6);
    v7 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059B060
// Name: public: virtual bool CDmeGlobalFlexControllerOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGlobalFlexControllerOperator::IsA(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059B090
// Name: public: virtual int CDmeGlobalFlexControllerOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGlobalFlexControllerOperator::GetInheritanceDepth(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059B170
// Name: protected: virtual void CDmeGlobalFlexControllerOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::PerformConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  CDmeGlobalFlexControllerOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x1059B2B0
// Name: protected: CDmeGameModel::CDmeGameModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CDmeGameModel::CDmeGameModel(
        CDmeGameModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeGameModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_globalFlexControllers);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_flexWeights);
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_skin.m_pAttribute = nullptr;
  this->m_skin.m_Storage = 0;
  this->m_body.m_pAttribute = nullptr;
  this->m_body.m_Storage = 0;
  this->m_sequence.m_pAttribute = nullptr;
  this->m_sequence.m_Storage = 0;
  this->m_flags.m_pAttribute = nullptr;
  this->m_flags.m_Storage = 0;
  this->m_bComputeBounds.m_pAttribute = nullptr;
  this->m_bComputeBounds.m_Storage = false;
  this->m_bEvaluateProceduralBones.m_pAttribute = nullptr;
  this->m_bEvaluateProceduralBones.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_bones);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1059B390
// Name: public: virtual bool CDmeGameModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameModel::IsA(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059B3C0
// Name: public: virtual int CDmeGameModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::GetInheritanceDepth(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059B410
// Name: protected: virtual void CDmeGameModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformDestruction(CDmeGameModel *this)
{
  int m_hMDL; // eax

  m_hMDL = this->m_hMDL;
  if ( (_WORD)m_hMDL != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: m_hMDL);
    this->m_hMDL = -1;
  }
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1059B450
// Name: protected: virtual void CDmeGameModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformConstruction(CDmeGameModel *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeDag::OnConstruction(this);
  CDmeGameModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x1059B4D0
// Name: protected: CDmeGameSprite::CDmeGameSprite(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSprite *__thiscall CDmeGameSprite::CDmeGameSprite(
        CDmeGameSprite *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeGameSprite::`vftable';
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_frame.m_pAttribute = nullptr;
  this->m_frame.m_Storage = 0.0;
  this->m_rendermode.m_pAttribute = nullptr;
  this->m_rendermode.m_Storage = 0;
  this->m_renderfx.m_pAttribute = nullptr;
  this->m_renderfx.m_Storage = 0;
  this->m_renderscale.m_pAttribute = nullptr;
  this->m_renderscale.m_Storage = 0.0;
  this->m_color.m_pAttribute = nullptr;
  this->m_color.m_Storage = (Color)-16777216;
  this->m_proxyRadius.m_pAttribute = nullptr;
  this->m_proxyRadius.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1059B5A0
// Name: public: virtual bool CDmeGameSprite::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSprite::IsA(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059B5D0
// Name: public: virtual int CDmeGameSprite::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::GetInheritanceDepth(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059B620
// Name: protected: virtual void CDmeGameSprite::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::PerformConstruction(CDmeGameSprite *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeDag::OnConstruction(this);
  CDmeGameSprite::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x1059B680
// Name: protected: CDmeGamePortal::CDmeGamePortal(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGamePortal *__thiscall CDmeGamePortal::CDmeGamePortal(
        CDmeGamePortal *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeGamePortal::`vftable';
  this->m_nPortalId.m_pAttribute = nullptr;
  this->m_nPortalId.m_Storage = 0;
  this->m_nLinkedPortalId.m_pAttribute = nullptr;
  this->m_nLinkedPortalId.m_Storage = 0;
  this->m_flStaticAmount.m_pAttribute = nullptr;
  this->m_flStaticAmount.m_Storage = 0.0;
  this->m_flSecondaryStaticAmount.m_pAttribute = nullptr;
  this->m_flSecondaryStaticAmount.m_Storage = 0.0;
  this->m_flOpenAmount.m_pAttribute = nullptr;
  this->m_flOpenAmount.m_Storage = 0.0;
  this->m_flHalfWidth.m_pAttribute = nullptr;
  this->m_flHalfWidth.m_Storage = 0.0;
  this->m_flHalfHeight.m_pAttribute = nullptr;
  this->m_flHalfHeight.m_Storage = 0.0;
  this->m_bIsPortal2.m_pAttribute = nullptr;
  this->m_bIsPortal2.m_Storage = false;
  this->m_PortalType.m_Storage.u.m_Id = -1;
  this->m_PortalType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1059B760
// Name: public: virtual bool CDmeGamePortal::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGamePortal::IsA(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059B790
// Name: public: virtual int CDmeGamePortal::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::GetInheritanceDepth(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059B7E0
// Name: protected: virtual int CDmeGamePortal::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::AllocatedSize(CDmeGamePortal *this)
{
  return 208;
}

//------------------------------------------------------------------------------
// Address: 0x1059B7F0
// Name: protected: virtual void CDmeGamePortal::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::PerformConstruction(CDmeGamePortal *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeDag::OnConstruction(this);
  CDmeGamePortal::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C9DE0
// Name: _dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGlobalFlexControllerOperator::s_Allocator,
    blockSize: 0x68u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGlobalFlexControllerOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9E40
// Name: _dynamic_initializer_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameModel::s_Allocator,
    blockSize: 0x114u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9EA0
// Name: _dynamic_initializer_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSprite::s_Allocator,
    blockSize: 0xC0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSprite pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9F00
// Name: _dynamic_initializer_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGamePortal::s_Allocator,
    blockSize: 0xD0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGamePortal pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDCF0
// Name: _dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGlobalFlexControllerOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CDD00
// Name: _dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CDD10
// Name: _dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSprite::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CDD20
// Name: _dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGamePortal::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9E10
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9E20
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGlobalFlexControllerOperator_Helper,
           classname: "DmeGlobalFlexControllerOperator",
           pFactory: &g_CDmeGlobalFlexControllerOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C9E70
// Name: _dynamic_initializer_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9E80
// Name: _dynamic_initializer_for__g_CDmeGameModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameModel_Helper,
           classname: "DmeGameModel",
           pFactory: &g_CDmeGameModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C9ED0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSprite_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9EE0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSprite_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSprite_Helper,
           classname: "DmeGameSprite",
           pFactory: &g_CDmeGameSprite_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C9F30
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGamePortal_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9F40
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGamePortal_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGamePortal_Helper,
           classname: "DmeGamePortal",
           pFactory: &g_CDmeGamePortal_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDD30
// Name: _dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeGameModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CDD40
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeGameSprite_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CDD50
// Name: _dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeGamePortal_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CDD60
// Name: _dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeGlobalFlexControllerOperator_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056B6B0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Operate(CDmeGlobalFlexControllerOperator *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // edx
  void *m_pData; // ebx
  DmAttributeType_t v5; // esi
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_pAttribute = this->m_flexWeight.m_pAttribute;
    m_pData = m_pAttribute->m_pData;
    v5 = m_pAttribute->m_nFlags & 0x1F;
    if ( (v2->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v2, valueType: v5, pValue: m_pData);
    }
    else if ( this->m_nFlexControllerIndex != -1 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v2);
      CDmrGenericArray::Set(this: &array, i: this->m_nFlexControllerIndex, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056B730
// Name: public: void CDmeGlobalFlexControllerOperator::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::SetupToAttribute(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_gameModel.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
    if ( Attribute != nullptr )
      this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: Attribute, bCreate: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056B770
// Name: public: virtual void CDmeGameModel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnAttributeChanged(CDmeGameModel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_modelName.m_pAttribute )
    this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x0056B790
// Name: protected: void CDmeGameModel::UpdateHMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::UpdateHMDL(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // di

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  v3 = -1;
  if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
    v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( this->m_hMDL != 0xFFFF )
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_hMDL);
  this->m_hMDL = v3;
  this->m_bHMDLDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x0056B7F0
// Name: protected: void CDmeGameSprite::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::OnConstruction(CDmeGameSprite *this)
{
  this->m_modelName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "modelName",
                                     type: AT_STRING,
                                     pMemory: &this->m_modelName);
  this->m_frame.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "frame",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_frame);
  this->m_rendermode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "rendermode",
                                      type: AT_INT,
                                      pMemory: &this->m_rendermode);
  this->m_renderfx.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "renderfx",
                                    type: AT_INT,
                                    pMemory: &this->m_renderfx);
  this->m_renderscale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "renderscale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_renderscale);
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  this->m_proxyRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "proxyRadius",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_proxyRadius);
}

//------------------------------------------------------------------------------
// Address: 0x0056B8A0
// Name: protected: void CDmeGamePortal::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::OnConstruction(CDmeGamePortal *this)
{
  this->m_flStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "staticAmount",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flStaticAmount);
  this->m_flSecondaryStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "secondaryStaticAmount",
                                                   type: AT_FLOAT,
                                                   pMemory: &this->m_flSecondaryStaticAmount);
  this->m_flOpenAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "openAmount",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flOpenAmount);
  this->m_flHalfWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "halfWidth",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flHalfWidth);
  this->m_flHalfHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "halfHeight",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flHalfHeight);
  this->m_nPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "portalId",
                                     type: AT_INT,
                                     pMemory: &this->m_nPortalId);
  this->m_nLinkedPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "linkedPortalId",
                                           type: AT_INT,
                                           pMemory: &this->m_nLinkedPortalId);
  this->m_bIsPortal2.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isPortal2",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsPortal2);
  this->m_PortalType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "portalType",
                                      type: AT_STRING,
                                      pMemory: &this->m_PortalType);
}

//------------------------------------------------------------------------------
// Address: 0x0056B980
// Name: protected: void CDmeGlobalFlexControllerOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_flexWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "flexWeight",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flexWeight);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_gameModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "gameModel",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_gameModel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_gameModel.m_pAttribute, typeSymbol: CDmeGameModel::m_classType);
  this->m_gameModel.m_pAttribute->m_nFlags |= 0x1100u;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_nFlexControllerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056B9F0
// Name: protected: void CDmeGameModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnConstruction(CDmeGameModel *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_flexWeights,
    pOwner: this,
    pAttributeName: "flexWeights",
    nFlags: 0);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "modelName", type: AT_STRING, pMemory: &this->m_modelName);
  this->m_modelName.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  this->m_skin.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "skin",
                                type: AT_INT,
                                pMemory: &this->m_skin);
  this->m_body.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "body",
                                type: AT_INT,
                                pMemory: &this->m_body);
  this->m_sequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "sequence",
                                    type: AT_INT,
                                    pMemory: &this->m_sequence);
  this->m_flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_flags);
  this->m_bones.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "bones",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_bones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_bones.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  this->m_globalFlexControllers.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "globalFlexControllers",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_globalFlexControllers);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_globalFlexControllers.m_pAttribute,
    typeSymbol: CDmeGlobalFlexControllerOperator::m_classType);
  this->m_bComputeBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "computeBounds",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bComputeBounds);
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "evaluateProceduralBones",
         type: AT_BOOL,
         pMemory: &this->m_bEvaluateProceduralBones);
  this->m_bEvaluateProceduralBones.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_hMDL = -1;
  this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x0056BB40
// Name: public: void CDmeGameModel::SetNumFlexWeights(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::SetNumFlexWeights(CDmeGameModel *this, unsigned int nFlexWeights)
{
  unsigned int m_Size; // eax
  unsigned int v4; // edi

  m_Size = this->m_flexWeights.m_Storage.m_Size;
  v4 = nFlexWeights;
  if ( m_Size >= nFlexWeights )
  {
    if ( m_Size > nFlexWeights )
    {
      do
      {
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
          this: &this->m_flexWeights,
          elem: m_Size - 1);
        m_Size = this->m_flexWeights.m_Storage.m_Size;
      }
      while ( m_Size > v4 );
    }
  }
  else
  {
    do
    {
      nFlexWeights = 0;
      CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &this->m_flexWeights,
        src: (float *)&nFlexWeights);
    }
    while ( this->m_flexWeights.m_Storage.m_Size < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056BBA0
// Name: private: int CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(
        CDmeGlobalFlexControllerOperator *this)
{
  CDmeGameModel *v1; // eax
  CDmeGameModel *v2; // esi
  int m_hMDL; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // edi
  int j; // ebx
  char *v7; // esi
  const char *m_pAsString; // ecx
  unsigned int v10; // edi
  CDmeGameModel *v11; // eax
  int fc; // [esp+8h] [ebp-Ch]
  LocalFlexController_t i; // [esp+10h] [ebp-4h]

  v1 = (CDmeGameModel *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_gameModel.m_Storage.m_Handle);
  v2 = v1;
  if ( v1->m_bHMDLDirty )
    CDmeGameModel::UpdateHMDL(this: v1);
  m_hMDL = v2->m_hMDL;
  if ( (_WORD)m_hMDL == 0xFFFF )
    return -1;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: m_hMDL);
  v5 = v4;
  if ( v4 == nullptr )
    return -1;
  fc = v4->numflexcontrollers;
  i = DUMMY_NULL_FLEX_CONTROLLER;
  if ( fc <= 0 )
    return -1;
  for ( j = 0; ; j += 20 )
  {
    v7 = (char *)v5 + j + v5->flexcontrollerindex;
    if ( *((_DWORD *)v7 + 2) == -1 && g_pGlobalFlexController != nullptr )
      *((_DWORD *)v7 + 2) = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v7[*((_DWORD *)v7 + 1)]);
    m_pAsString = WindowName;
    if ( this->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
      m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( _V_stricmp(s1: &v7[*((_DWORD *)v7 + 1)], s2: m_pAsString) == 0 )
      break;
    if ( ++i >= fc )
      return -1;
  }
  v10 = *((_DWORD *)v7 + 2);
  if ( v10 >= *(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: this->m_gameModel.m_Storage.m_Handle)
                        + 176) )
  {
    v11 = (CDmeGameModel *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_gameModel.m_Storage.m_Handle);
    CDmeGameModel::SetNumFlexWeights(this: v11, nFlexWeights: *((_DWORD *)v7 + 2) + 1);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0056BCE0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Resolve(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  if ( this->m_ToAttributeHandle < 0 )
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  if ( this->m_gameModel.m_pAttribute == (CDmAttribute *)-1 )
  {
    v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_flexWeight.m_pAttribute);
    if ( v2 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
      if ( Attribute != nullptr )
        this->m_gameModel.m_pAttribute = (CDmAttribute *)CDmAttribute::GetHandle(this: Attribute, bCreate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056BD30
// Name: public: virtual void CDmeGlobalFlexControllerOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnAttributeChanged(
        CDmeGlobalFlexControllerOperator *this,
        CDmAttribute *pAttribute)
{
  if ( g_pGlobalFlexController != nullptr
    && pAttribute == (CDmAttribute *)this->m_gameModel.m_Storage.m_ElementType.u.m_Id
    && (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_flexWeight.m_pAttribute) != 0 )
  {
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
    CDmeGlobalFlexControllerOperator::SetupToAttribute(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056BD80
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetInputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_flexWeight.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
  m_pMemory = (int)attrs[1].m_pMemory;
  if ( m_pMemory + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
  ++attrs[1].m_pMemory;
  v5 = (CDmAttribute **)attrs->m_pMemory;
  v6 = (int)attrs[1].m_pMemory - m_pMemory - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &v5[m_pMemory + 1], src: &v5[m_pMemory], count: 4 * v6);
  v7 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
  if ( v7 != nullptr )
    *v7 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0056BDE0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int v2; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 336))(
         a1: g_pDataModel.u,
         a2: this->m_ToAttributeHandle);
  if ( v2 != 0 )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v5 = (CDmAttribute **)attrs->m_pMemory;
    v6 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &v5[m_pMemory + 1], src: &v5[m_pMemory], count: 4 * v6);
    v7 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (CDmAttribute *)v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056BF40
// Name: public: virtual bool CDmeGlobalFlexControllerOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGlobalFlexControllerOperator::IsA(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056BF70
// Name: public: virtual int CDmeGlobalFlexControllerOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGlobalFlexControllerOperator::GetInheritanceDepth(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056C040
// Name: protected: virtual void CDmeGlobalFlexControllerOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::PerformConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  CDmeGlobalFlexControllerOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0056C180
// Name: protected: CDmeGameModel::CDmeGameModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CDmeGameModel::CDmeGameModel(
        CDmeGameModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeGameModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_globalFlexControllers);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_flexWeights);
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_skin.m_pAttribute = nullptr;
  this->m_skin.m_Storage = 0;
  this->m_body.m_pAttribute = nullptr;
  this->m_body.m_Storage = 0;
  this->m_sequence.m_pAttribute = nullptr;
  this->m_sequence.m_Storage = 0;
  this->m_flags.m_pAttribute = nullptr;
  this->m_flags.m_Storage = 0;
  this->m_bComputeBounds.m_pAttribute = nullptr;
  this->m_bComputeBounds.m_Storage = false;
  this->m_bEvaluateProceduralBones.m_pAttribute = nullptr;
  this->m_bEvaluateProceduralBones.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_bones);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056C260
// Name: public: virtual bool CDmeGameModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameModel::IsA(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056C290
// Name: public: virtual int CDmeGameModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::GetInheritanceDepth(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056C2E0
// Name: protected: virtual void CDmeGameModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformDestruction(CDmeGameModel *this)
{
  int m_hMDL; // eax

  m_hMDL = this->m_hMDL;
  if ( (_WORD)m_hMDL != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: m_hMDL);
    this->m_hMDL = -1;
  }
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0056C320
// Name: protected: virtual int CDmeGameModel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::AllocatedSize(CDmeGameModel *this)
{
  return 276;
}

//------------------------------------------------------------------------------
// Address: 0x0056C330
// Name: protected: virtual void CDmeGameModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformConstruction(CDmeGameModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056C3B0
// Name: protected: CDmeGameSprite::CDmeGameSprite(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSprite *__thiscall CDmeGameSprite::CDmeGameSprite(
        CDmeGameSprite *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeGameSprite::`vftable';
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_frame.m_pAttribute = nullptr;
  this->m_frame.m_Storage = 0.0;
  this->m_rendermode.m_pAttribute = nullptr;
  this->m_rendermode.m_Storage = 0;
  this->m_renderfx.m_pAttribute = nullptr;
  this->m_renderfx.m_Storage = 0;
  this->m_renderscale.m_pAttribute = nullptr;
  this->m_renderscale.m_Storage = 0.0;
  this->m_color.m_pAttribute = nullptr;
  this->m_color.m_Storage = (Color)-16777216;
  this->m_proxyRadius.m_pAttribute = nullptr;
  this->m_proxyRadius.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056C480
// Name: public: virtual bool CDmeGameSprite::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSprite::IsA(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056C4B0
// Name: public: virtual int CDmeGameSprite::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::GetInheritanceDepth(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056C500
// Name: protected: virtual int CDmeGameSprite::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::AllocatedSize(CDmeVertexDeltaData *this)
{
  return 192;
}

//------------------------------------------------------------------------------
// Address: 0x0056C510
// Name: protected: virtual void CDmeGameSprite::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::PerformConstruction(CDmeGameSprite *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameSprite::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056C570
// Name: protected: CDmeGamePortal::CDmeGamePortal(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGamePortal *__thiscall CDmeGamePortal::CDmeGamePortal(
        CDmeGamePortal *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeGamePortal::`vftable';
  this->m_nPortalId.m_pAttribute = nullptr;
  this->m_nPortalId.m_Storage = 0;
  this->m_nLinkedPortalId.m_pAttribute = nullptr;
  this->m_nLinkedPortalId.m_Storage = 0;
  this->m_flStaticAmount.m_pAttribute = nullptr;
  this->m_flStaticAmount.m_Storage = 0.0;
  this->m_flSecondaryStaticAmount.m_pAttribute = nullptr;
  this->m_flSecondaryStaticAmount.m_Storage = 0.0;
  this->m_flOpenAmount.m_pAttribute = nullptr;
  this->m_flOpenAmount.m_Storage = 0.0;
  this->m_flHalfWidth.m_pAttribute = nullptr;
  this->m_flHalfWidth.m_Storage = 0.0;
  this->m_flHalfHeight.m_pAttribute = nullptr;
  this->m_flHalfHeight.m_Storage = 0.0;
  this->m_bIsPortal2.m_pAttribute = nullptr;
  this->m_bIsPortal2.m_Storage = false;
  this->m_PortalType.m_Storage.u.m_Id = -1;
  this->m_PortalType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056C650
// Name: public: virtual bool CDmeGamePortal::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGamePortal::IsA(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056C680
// Name: public: virtual int CDmeGamePortal::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::GetInheritanceDepth(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056C6D0
// Name: protected: virtual int CDmeGamePortal::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::AllocatedSize(CDmeGamePortal *this)
{
  return 208;
}

//------------------------------------------------------------------------------
// Address: 0x0056C6E0
// Name: protected: virtual void CDmeGamePortal::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::PerformConstruction(CDmeGamePortal *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGamePortal::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059D6C0
// Name: _dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGlobalFlexControllerOperator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGlobalFlexControllerOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D720
// Name: _dynamic_initializer_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameModel::s_Allocator,
    blockSize: 276,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D780
// Name: _dynamic_initializer_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSprite::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSprite pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D7E0
// Name: _dynamic_initializer_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGamePortal::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGamePortal pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059FA20
// Name: _dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGlobalFlexControllerOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059FA30
// Name: _dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059FA40
// Name: _dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSprite::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059FA50
// Name: _dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGamePortal::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059D6F0
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D700
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGlobalFlexControllerOperator_Helper,
           classname: "DmeGlobalFlexControllerOperator",
           pFactory: &g_CDmeGlobalFlexControllerOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059D750
// Name: _dynamic_initializer_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D760
// Name: _dynamic_initializer_for__g_CDmeGameModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameModel_Helper,
           classname: "DmeGameModel",
           pFactory: &g_CDmeGameModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059D7B0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSprite_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D7C0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSprite_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSprite_Helper,
           classname: "DmeGameSprite",
           pFactory: &g_CDmeGameSprite_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059D810
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGamePortal_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D820
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGamePortal_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGamePortal_Helper,
           classname: "DmeGamePortal",
           pFactory: &g_CDmeGamePortal_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059D840
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D860
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0059D870
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0059D8D0
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0059D900
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D910
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D930
// Name: _dynamic_initializer_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_static_p4_factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_static_p4_factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D940
// Name: _DebugDrawModelVertColocation_::_2_::_dynamic_atexit_destructor_for__sortedVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugDrawModelVertColocation_::_2_::_dynamic_atexit_destructor_for__sortedVector__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sortedVector);
}

//------------------------------------------------------------------------------
// Address: 0x0059D950
// Name: _DebugDrawModelBadVerts_::_2_::_dynamic_atexit_destructor_for__tris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugDrawModelBadVerts_::_2_::_dynamic_atexit_destructor_for__tris__()
{
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(this: &tris.m_MaterialBatches);
}

//------------------------------------------------------------------------------
// Address: 0x0059D960
// Name: _DebugDrawModelWireframe_::_2_::_dynamic_atexit_destructor_for__tris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugDrawModelWireframe_::_2_::_dynamic_atexit_destructor_for__tris__()
{
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(this: &tris_0.m_MaterialBatches);
}

//------------------------------------------------------------------------------
// Address: 0x0059D970
// Name: _DebugDrawModelBoneWeights_::_2_::_dynamic_atexit_destructor_for__tris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugDrawModelBoneWeights_::_2_::_dynamic_atexit_destructor_for__tris__()
{
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(this: &tris_1.m_MaterialBatches);
}

//------------------------------------------------------------------------------
// Address: 0x0059D980
// Name: _DebugDrawModelVertColocation_::_2_::_dynamic_atexit_destructor_for__tris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugDrawModelVertColocation_::_2_::_dynamic_atexit_destructor_for__tris__()
{
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(this: &tris_2.m_MaterialBatches);
}

//------------------------------------------------------------------------------
// Address: 0x0059D990
// Name: _DebugDrawModelTexCoord_::_2_::_dynamic_atexit_destructor_for__tris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugDrawModelTexCoord_::_2_::_dynamic_atexit_destructor_for__tris__()
{
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(this: &tris_3.m_MaterialBatches);
}

//------------------------------------------------------------------------------
// Address: 0x0059D9A0
// Name: _DebugModelVertExtents_::_2_::_dynamic_atexit_destructor_for__tris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugModelVertExtents_::_2_::_dynamic_atexit_destructor_for__tris__()
{
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(this: &tris_4.m_MaterialBatches);
}

//------------------------------------------------------------------------------
// Address: 0x0059D9B0
// Name: _dynamic_atexit_destructor_for__JiggleBoneDebug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__JiggleBoneDebug__()
{
  ConVar::~ConVar(this: &JiggleBoneDebug);
}

//------------------------------------------------------------------------------
// Address: 0x0059D9C0
// Name: _dynamic_atexit_destructor_for__JiggleBoneDebugYawConstraints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__JiggleBoneDebugYawConstraints__()
{
  ConVar::~ConVar(this: &JiggleBoneDebugYawConstraints);
}

//------------------------------------------------------------------------------
// Address: 0x0059D9D0
// Name: _dynamic_atexit_destructor_for__JiggleBoneDebugPitchConstraints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__JiggleBoneDebugPitchConstraints__()
{
  ConVar::~ConVar(this: &JiggleBoneDebugPitchConstraints);
}

//------------------------------------------------------------------------------
// Address: 0x0059D9E0
// Name: _dynamic_atexit_destructor_for__JiggleBoneInvert__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__JiggleBoneInvert__()
{
  ConVar::~ConVar(this: &JiggleBoneInvert);
}

//------------------------------------------------------------------------------
// Address: 0x0059D9F0
// Name: _dynamic_atexit_destructor_for__JiggleBoneSanity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__JiggleBoneSanity__()
{
  ConVar::~ConVar(this: &JiggleBoneSanity);
}

//------------------------------------------------------------------------------
// Address: 0x0059DA00
// Name: _dynamic_atexit_destructor_for__mat_bumpmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_bumpmap__()
{
  ConVar::~ConVar(this: &mat_bumpmap);
}

//------------------------------------------------------------------------------
// Address: 0x0059DA10
// Name: _dynamic_atexit_destructor_for__mat_specular__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_specular__()
{
  ConVar::~ConVar(this: &mat_specular);
}

//------------------------------------------------------------------------------
// Address: 0x0059DA20
// Name: _dynamic_atexit_destructor_for__mat_parallaxmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_parallaxmap__()
{
  ConVar::~ConVar(this: &mat_parallaxmap);
}

//------------------------------------------------------------------------------
// Address: 0x0059DA30
// Name: _dynamic_atexit_destructor_for__mat_displacementmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_displacementmap__()
{
  ConVar::~ConVar(this: &mat_displacementmap);
}

//------------------------------------------------------------------------------
// Address: 0x0059DA40
// Name: _dynamic_atexit_destructor_for__mat_tessellationlevel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_tessellationlevel__()
{
  ConVar::~ConVar(this: &mat_tessellationlevel);
}

//------------------------------------------------------------------------------
// Address: 0x0059DA50
// Name: _dynamic_atexit_destructor_for__g_HlmvIpcClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_HlmvIpcClient__()
{
  if ( g_HlmvIpcClient.m_szServerUID != nullptr )
  {
    if ( g_HlmvIpcClient.m_hClientPipe != nullptr )
    {
      CloseHandle(hObject: g_HlmvIpcClient.m_hClientPipe);
      g_HlmvIpcClient.m_hClientPipe = nullptr;
    }
    if ( g_HlmvIpcClient.m_szServerUID != nullptr )
    {
      RpcStringFreeA(String: &g_HlmvIpcClient.m_szServerUID);
      g_HlmvIpcClient.m_szServerUID = nullptr;
    }
  }
  if ( g_HlmvIpcClient.m_szServerName != nullptr )
  {
    free(pMem: g_HlmvIpcClient.m_szServerName);
    g_HlmvIpcClient.m_szServerName = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0059DAB0
// Name: _dynamic_atexit_destructor_for__g_HlmvIpcServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_HlmvIpcServer__()
{
  CHlmvIpcServer::~CHlmvIpcServer(this: &g_HlmvIpcServer);
}

//------------------------------------------------------------------------------
// Address: 0x0059DAC0
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x0059DAD0
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x0059DAE0
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x0059DAF0
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0059DB00
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&emptyMapping.m_ActToSeqHash);
}

//------------------------------------------------------------------------------
// Address: 0x0059DB40
// Name: _dynamic_atexit_destructor_for__g_DrawModelResults__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DrawModelResults__()
{
  g_DrawModelResults.m_Materials.m_Size = 0;
  g_DrawModelResults.m_Materials.m_pElements = (IMaterial **)&g_DrawModelResults.m_Materials;
}

//------------------------------------------------------------------------------
// Address: 0x0059DB60
// Name: _dynamic_atexit_destructor_for__g_studioModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_studioModel__()
{
  StudioModel::~StudioModel(this: &g_studioModel);
}

//------------------------------------------------------------------------------
// Address: 0x0059DB70
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x0059DB80
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x0059DB90
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x0059DBA0
// Name: _dynamic_atexit_destructor_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioBoneCache__()
{
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_StudioBoneCache.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_StudioBoneCache);
    *((_WORD *)&g_StudioBoneCache.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_StudioBoneCache);
}

//------------------------------------------------------------------------------
// Address: 0x0059DBD0
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x0059DBE0
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x0059DBF0
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x0059FA60
// Name: _dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059FA70
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSprite_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059FA80
// Name: _dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGamePortal_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059FA90
// Name: _dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGlobalFlexControllerOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059FAA0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x0059FAB0
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0059FAF0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0059FB40
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x0050B550
// Name: protected: virtual int CDmeGameSprite::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::AllocatedSize(CDmeVertexDeltaData *this)
{
  return 192;
}

//------------------------------------------------------------------------------
// Address: 0x005B46F0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Operate(CDmeGlobalFlexControllerOperator *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // edx
  void *m_pData; // ebx
  DmAttributeType_t v5; // esi
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_pAttribute = this->m_flexWeight.m_pAttribute;
    m_pData = m_pAttribute->m_pData;
    v5 = m_pAttribute->m_nFlags & 0x1F;
    if ( (v2->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v2, valueType: v5, pValue: m_pData);
    }
    else if ( this->m_nFlexControllerIndex != -1 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v2);
      CDmrGenericArray::Set(this: &array, i: this->m_nFlexControllerIndex, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B4770
// Name: public: void CDmeGlobalFlexControllerOperator::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::SetupToAttribute(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_gameModel.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
    if ( Attribute != nullptr )
      this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: Attribute, bCreate: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B47B0
// Name: public: virtual void CDmeGameModel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnAttributeChanged(CDmeGameModel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_modelName.m_pAttribute )
    this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x005B47D0
// Name: protected: void CDmeGameModel::UpdateHMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::UpdateHMDL(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // di

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  v3 = -1;
  if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
    v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( this->m_hMDL != 0xFFFF )
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_hMDL);
  this->m_hMDL = v3;
  this->m_bHMDLDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x005B4830
// Name: protected: void CDmeGameSprite::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::OnConstruction(CDmeGameSprite *this)
{
  this->m_modelName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "modelName",
                                     type: AT_STRING,
                                     pMemory: &this->m_modelName);
  this->m_frame.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "frame",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_frame);
  this->m_rendermode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "rendermode",
                                      type: AT_INT,
                                      pMemory: &this->m_rendermode);
  this->m_renderfx.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "renderfx",
                                    type: AT_INT,
                                    pMemory: &this->m_renderfx);
  this->m_renderscale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "renderscale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_renderscale);
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  this->m_proxyRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "proxyRadius",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_proxyRadius);
}

//------------------------------------------------------------------------------
// Address: 0x005B48E0
// Name: protected: void CDmeGamePortal::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::OnConstruction(CDmeGamePortal *this)
{
  this->m_flStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "staticAmount",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flStaticAmount);
  this->m_flSecondaryStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "secondaryStaticAmount",
                                                   type: AT_FLOAT,
                                                   pMemory: &this->m_flSecondaryStaticAmount);
  this->m_flOpenAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "openAmount",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flOpenAmount);
  this->m_flHalfWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "halfWidth",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flHalfWidth);
  this->m_flHalfHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "halfHeight",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flHalfHeight);
  this->m_nPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "portalId",
                                     type: AT_INT,
                                     pMemory: &this->m_nPortalId);
  this->m_nLinkedPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "linkedPortalId",
                                           type: AT_INT,
                                           pMemory: &this->m_nLinkedPortalId);
  this->m_bIsPortal2.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isPortal2",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsPortal2);
  this->m_PortalType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "portalType",
                                      type: AT_STRING,
                                      pMemory: &this->m_PortalType);
}

//------------------------------------------------------------------------------
// Address: 0x005B49C0
// Name: protected: void CDmeGlobalFlexControllerOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_flexWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "flexWeight",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flexWeight);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_gameModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "gameModel",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_gameModel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_gameModel.m_pAttribute, typeSymbol: CDmeGameModel::m_classType);
  this->m_gameModel.m_pAttribute->m_nFlags |= 0x1100u;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_nFlexControllerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4A30
// Name: protected: void CDmeGameModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnConstruction(CDmeGameModel *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_flexWeights,
    pOwner: this,
    pAttributeName: "flexWeights",
    nFlags: 0);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "modelName", type: AT_STRING, pMemory: &this->m_modelName);
  this->m_modelName.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  this->m_skin.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "skin",
                                type: AT_INT,
                                pMemory: &this->m_skin);
  this->m_body.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "body",
                                type: AT_INT,
                                pMemory: &this->m_body);
  this->m_sequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "sequence",
                                    type: AT_INT,
                                    pMemory: &this->m_sequence);
  this->m_flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_flags);
  this->m_bones.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "bones",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_bones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_bones.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  this->m_globalFlexControllers.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "globalFlexControllers",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_globalFlexControllers);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_globalFlexControllers.m_pAttribute,
    typeSymbol: CDmeGlobalFlexControllerOperator::m_classType);
  this->m_bComputeBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "computeBounds",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bComputeBounds);
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "evaluateProceduralBones",
         type: AT_BOOL,
         pMemory: &this->m_bEvaluateProceduralBones);
  this->m_bEvaluateProceduralBones.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_hMDL = -1;
  this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x005B4B80
// Name: public: void CDmeGameModel::SetNumFlexWeights(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::SetNumFlexWeights(CDmeGameModel *this, unsigned int nFlexWeights)
{
  unsigned int m_Size; // eax
  unsigned int v4; // edi

  m_Size = this->m_flexWeights.m_Storage.m_Size;
  v4 = nFlexWeights;
  if ( m_Size >= nFlexWeights )
  {
    if ( m_Size > nFlexWeights )
    {
      do
      {
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
          this: &this->m_flexWeights,
          elem: m_Size - 1);
        m_Size = this->m_flexWeights.m_Storage.m_Size;
      }
      while ( m_Size > v4 );
    }
  }
  else
  {
    do
    {
      nFlexWeights = 0;
      CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &this->m_flexWeights,
        src: (float *)&nFlexWeights);
    }
    while ( this->m_flexWeights.m_Storage.m_Size < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B4BE0
// Name: private: int CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(
        CDmeGlobalFlexControllerOperator *this)
{
  CDmeGameModel *v1; // eax
  CDmeGameModel *v2; // esi
  int m_hMDL; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // edi
  int j; // ebx
  char *v7; // esi
  const char *m_pAsString; // ecx
  unsigned int v10; // edi
  CDmeGameModel *v11; // eax
  int fc; // [esp+8h] [ebp-Ch]
  LocalFlexController_t i; // [esp+10h] [ebp-4h]

  v1 = (CDmeGameModel *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_gameModel.m_Storage.m_Handle);
  v2 = v1;
  if ( v1->m_bHMDLDirty )
    CDmeGameModel::UpdateHMDL(this: v1);
  m_hMDL = v2->m_hMDL;
  if ( (_WORD)m_hMDL == 0xFFFF )
    return -1;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: m_hMDL);
  v5 = v4;
  if ( v4 == nullptr )
    return -1;
  fc = v4->numflexcontrollers;
  i = DUMMY_NULL_FLEX_CONTROLLER;
  if ( fc <= 0 )
    return -1;
  for ( j = 0; ; j += 20 )
  {
    v7 = (char *)v5 + j + v5->flexcontrollerindex;
    if ( *((_DWORD *)v7 + 2) == -1 && g_pGlobalFlexController != nullptr )
      *((_DWORD *)v7 + 2) = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v7[*((_DWORD *)v7 + 1)]);
    m_pAsString = pDeltaStateName;
    if ( this->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
      m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( _V_stricmp(s1: &v7[*((_DWORD *)v7 + 1)], s2: m_pAsString) == 0 )
      break;
    if ( ++i >= fc )
      return -1;
  }
  v10 = *((_DWORD *)v7 + 2);
  if ( v10 >= *(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: this->m_gameModel.m_Storage.m_Handle)
                        + 176) )
  {
    v11 = (CDmeGameModel *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_gameModel.m_Storage.m_Handle);
    CDmeGameModel::SetNumFlexWeights(this: v11, nFlexWeights: *((_DWORD *)v7 + 2) + 1);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x005B4D20
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Resolve(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  if ( this->m_ToAttributeHandle < 0 )
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  if ( this->m_gameModel.m_pAttribute == (CDmAttribute *)-1 )
  {
    v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_flexWeight.m_pAttribute);
    if ( v2 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
      if ( Attribute != nullptr )
        this->m_gameModel.m_pAttribute = (CDmAttribute *)CDmAttribute::GetHandle(this: Attribute, bCreate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B4D70
// Name: public: virtual void CDmeGlobalFlexControllerOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnAttributeChanged(
        CDmeGlobalFlexControllerOperator *this,
        CDmAttribute *pAttribute)
{
  if ( g_pGlobalFlexController != nullptr
    && pAttribute == (CDmAttribute *)this->m_gameModel.m_Storage.m_ElementType.u.m_Id
    && (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_flexWeight.m_pAttribute) != 0 )
  {
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
    CDmeGlobalFlexControllerOperator::SetupToAttribute(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B4E20
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int v2; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 336))(
         a1: g_pDataModel.u,
         a2: this->m_ToAttributeHandle);
  if ( v2 != 0 )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v5 = (CDmAttribute **)attrs->m_pMemory;
    v6 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &v5[m_pMemory + 1], src: &v5[m_pMemory], count: 4 * v6);
    v7 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (CDmAttribute *)v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B4F50
// Name: public: virtual bool CDmeGlobalFlexControllerOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGlobalFlexControllerOperator::IsA(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4F80
// Name: public: virtual int CDmeGlobalFlexControllerOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGlobalFlexControllerOperator::GetInheritanceDepth(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B5050
// Name: protected: virtual void CDmeGlobalFlexControllerOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::PerformConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  CDmeGlobalFlexControllerOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005B5190
// Name: protected: CDmeGameModel::CDmeGameModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CDmeGameModel::CDmeGameModel(
        CDmeGameModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeGameModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_globalFlexControllers);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_flexWeights);
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_skin.m_pAttribute = nullptr;
  this->m_skin.m_Storage = 0;
  this->m_body.m_pAttribute = nullptr;
  this->m_body.m_Storage = 0;
  this->m_sequence.m_pAttribute = nullptr;
  this->m_sequence.m_Storage = 0;
  this->m_flags.m_pAttribute = nullptr;
  this->m_flags.m_Storage = 0;
  this->m_bComputeBounds.m_pAttribute = nullptr;
  this->m_bComputeBounds.m_Storage = false;
  this->m_bEvaluateProceduralBones.m_pAttribute = nullptr;
  this->m_bEvaluateProceduralBones.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_bones);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B5270
// Name: public: virtual bool CDmeGameModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameModel::IsA(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B52A0
// Name: public: virtual int CDmeGameModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::GetInheritanceDepth(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B52F0
// Name: protected: virtual void CDmeGameModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformDestruction(CDmeGameModel *this)
{
  int m_hMDL; // eax

  m_hMDL = this->m_hMDL;
  if ( (_WORD)m_hMDL != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: m_hMDL);
    this->m_hMDL = -1;
  }
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005B5330
// Name: protected: virtual int CDmeGameModel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::AllocatedSize(CDmeGameModel *this)
{
  return 276;
}

//------------------------------------------------------------------------------
// Address: 0x005B5340
// Name: protected: virtual void CDmeGameModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformConstruction(CDmeGameModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005B53C0
// Name: protected: CDmeGameSprite::CDmeGameSprite(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSprite *__thiscall CDmeGameSprite::CDmeGameSprite(
        CDmeGameSprite *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeGameSprite::`vftable';
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_frame.m_pAttribute = nullptr;
  this->m_frame.m_Storage = 0.0;
  this->m_rendermode.m_pAttribute = nullptr;
  this->m_rendermode.m_Storage = 0;
  this->m_renderfx.m_pAttribute = nullptr;
  this->m_renderfx.m_Storage = 0;
  this->m_renderscale.m_pAttribute = nullptr;
  this->m_renderscale.m_Storage = 0.0;
  this->m_color.m_pAttribute = nullptr;
  this->m_color.m_Storage = (Color)-16777216;
  this->m_proxyRadius.m_pAttribute = nullptr;
  this->m_proxyRadius.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B5490
// Name: public: virtual bool CDmeGameSprite::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSprite::IsA(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B54C0
// Name: public: virtual int CDmeGameSprite::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::GetInheritanceDepth(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B5510
// Name: protected: virtual void CDmeGameSprite::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::PerformConstruction(CDmeGameSprite *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameSprite::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005B5570
// Name: protected: CDmeGamePortal::CDmeGamePortal(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGamePortal *__thiscall CDmeGamePortal::CDmeGamePortal(
        CDmeGamePortal *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeGamePortal::`vftable';
  this->m_nPortalId.m_pAttribute = nullptr;
  this->m_nPortalId.m_Storage = 0;
  this->m_nLinkedPortalId.m_pAttribute = nullptr;
  this->m_nLinkedPortalId.m_Storage = 0;
  this->m_flStaticAmount.m_pAttribute = nullptr;
  this->m_flStaticAmount.m_Storage = 0.0;
  this->m_flSecondaryStaticAmount.m_pAttribute = nullptr;
  this->m_flSecondaryStaticAmount.m_Storage = 0.0;
  this->m_flOpenAmount.m_pAttribute = nullptr;
  this->m_flOpenAmount.m_Storage = 0.0;
  this->m_flHalfWidth.m_pAttribute = nullptr;
  this->m_flHalfWidth.m_Storage = 0.0;
  this->m_flHalfHeight.m_pAttribute = nullptr;
  this->m_flHalfHeight.m_Storage = 0.0;
  this->m_bIsPortal2.m_pAttribute = nullptr;
  this->m_bIsPortal2.m_Storage = false;
  this->m_PortalType.m_Storage.u.m_Id = -1;
  this->m_PortalType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B5650
// Name: public: virtual bool CDmeGamePortal::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGamePortal::IsA(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B5680
// Name: public: virtual int CDmeGamePortal::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::GetInheritanceDepth(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B56D0
// Name: protected: virtual int CDmeGamePortal::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::AllocatedSize(CDmeGamePortal *this)
{
  return 208;
}

//------------------------------------------------------------------------------
// Address: 0x005B56E0
// Name: protected: virtual void CDmeGamePortal::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::PerformConstruction(CDmeGamePortal *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGamePortal::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F2360
// Name: _dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGlobalFlexControllerOperator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGlobalFlexControllerOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F23C0
// Name: _dynamic_initializer_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameModel::s_Allocator,
    blockSize: 276,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F2420
// Name: _dynamic_initializer_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSprite::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSprite pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F2480
// Name: _dynamic_initializer_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGamePortal::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGamePortal pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4D30
// Name: _dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGlobalFlexControllerOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4D40
// Name: _dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4D50
// Name: _dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSprite::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4D60
// Name: _dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGamePortal::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F2390
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F23A0
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGlobalFlexControllerOperator_Helper,
           classname: "DmeGlobalFlexControllerOperator",
           pFactory: &g_CDmeGlobalFlexControllerOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F23F0
// Name: _dynamic_initializer_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F2400
// Name: _dynamic_initializer_for__g_CDmeGameModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameModel_Helper,
           classname: "DmeGameModel",
           pFactory: &g_CDmeGameModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F2450
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSprite_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F2460
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSprite_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSprite_Helper,
           classname: "DmeGameSprite",
           pFactory: &g_CDmeGameSprite_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F24B0
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGamePortal_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F24C0
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGamePortal_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGamePortal_Helper,
           classname: "DmeGamePortal",
           pFactory: &g_CDmeGamePortal_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F24E0
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F2500
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005F2510
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x005F2520
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F2580
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F25B0
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x005F25D0
// Name: _dynamic_initializer_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_static_p4_factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_static_p4_factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4D70
// Name: _dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4D80
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSprite_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4D90
// Name: _dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGamePortal_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4DA0
// Name: _dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGlobalFlexControllerOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4DB0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4DC0
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005F4E00
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x005F4E50
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x004677E0
// Name: protected: virtual int CDmeGameSprite::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::AllocatedSize(CDmeVertexDeltaData *this)
{
  return 192;
}

//------------------------------------------------------------------------------
// Address: 0x0051A000
// Name: protected: virtual int CDmeGamePortal::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::AllocatedSize(CDmeSpotLight *this)
{
  return 208;
}

//------------------------------------------------------------------------------
// Address: 0x0051A310
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Operate(CDmeGlobalFlexControllerOperator *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // edx
  void *m_pData; // ebx
  DmAttributeType_t v5; // esi
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_pAttribute = this->m_flexWeight.m_pAttribute;
    m_pData = m_pAttribute->m_pData;
    v5 = m_pAttribute->m_nFlags & 0x1F;
    if ( (v2->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v2, valueType: v5, pValue: m_pData);
    }
    else if ( this->m_nFlexControllerIndex != -1 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v2);
      CDmrGenericArray::Set(this: &array, i: this->m_nFlexControllerIndex, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051A390
// Name: public: void CDmeGlobalFlexControllerOperator::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::SetupToAttribute(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
    if ( Attribute != nullptr )
      this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: Attribute, bCreate: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051A3D0
// Name: public: virtual void CDmeGameModel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnAttributeChanged(CDmeGameModel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_modelName.m_pAttribute )
    this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x0051A3F0
// Name: protected: void CDmeGameModel::UpdateHMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::UpdateHMDL(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // di

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  v3 = -1;
  if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
    v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( this->m_hMDL != 0xFFFF )
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_hMDL);
  this->m_hMDL = v3;
  this->m_bHMDLDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x0051A450
// Name: protected: void CDmeGameSprite::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::OnConstruction(CDmeGameSprite *this)
{
  this->m_modelName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "modelName",
                                     type: AT_STRING,
                                     pMemory: &this->m_modelName);
  this->m_frame.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "frame",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_frame);
  this->m_rendermode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "rendermode",
                                      type: AT_INT,
                                      pMemory: &this->m_rendermode);
  this->m_renderfx.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "renderfx",
                                    type: AT_INT,
                                    pMemory: &this->m_renderfx);
  this->m_renderscale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "renderscale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_renderscale);
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  this->m_proxyRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "proxyRadius",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_proxyRadius);
}

//------------------------------------------------------------------------------
// Address: 0x0051A500
// Name: protected: void CDmeGamePortal::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::OnConstruction(CDmeGamePortal *this)
{
  this->m_flStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "staticAmount",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flStaticAmount);
  this->m_flSecondaryStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "secondaryStaticAmount",
                                                   type: AT_FLOAT,
                                                   pMemory: &this->m_flSecondaryStaticAmount);
  this->m_flOpenAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "openAmount",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flOpenAmount);
  this->m_flHalfWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "halfWidth",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flHalfWidth);
  this->m_flHalfHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "halfHeight",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flHalfHeight);
  this->m_nPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "portalId",
                                     type: AT_INT,
                                     pMemory: &this->m_nPortalId);
  this->m_nLinkedPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "linkedPortalId",
                                           type: AT_INT,
                                           pMemory: &this->m_nLinkedPortalId);
  this->m_bIsPortal2.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isPortal2",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsPortal2);
  this->m_PortalType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "portalType",
                                      type: AT_STRING,
                                      pMemory: &this->m_PortalType);
}

//------------------------------------------------------------------------------
// Address: 0x0051A5E0
// Name: protected: void CDmeGlobalFlexControllerOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_flexWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "flexWeight",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flexWeight);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_gameModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "gameModel",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_gameModel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_gameModel.m_pAttribute, typeSymbol: CDmeGameModel::m_classType);
  this->m_gameModel.m_pAttribute->m_nFlags |= 0x1100u;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_nFlexControllerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051A650
// Name: protected: void CDmeGameModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnConstruction(CDmeGameModel *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_flexWeights,
    pOwner: this,
    pAttributeName: "flexWeights",
    nFlags: 0);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "modelName", type: AT_STRING, pMemory: &this->m_modelName);
  this->m_modelName.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  this->m_skin.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "skin",
                                type: AT_INT,
                                pMemory: &this->m_skin);
  this->m_body.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "body",
                                type: AT_INT,
                                pMemory: &this->m_body);
  this->m_sequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "sequence",
                                    type: AT_INT,
                                    pMemory: &this->m_sequence);
  this->m_flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_flags);
  this->m_bones.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "bones",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_bones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_bones.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  this->m_globalFlexControllers.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "globalFlexControllers",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_globalFlexControllers);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_globalFlexControllers.m_pAttribute,
    typeSymbol: CDmeGlobalFlexControllerOperator::m_classType);
  this->m_bComputeBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "computeBounds",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bComputeBounds);
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "evaluateProceduralBones",
         type: AT_BOOL,
         pMemory: &this->m_bEvaluateProceduralBones);
  this->m_bEvaluateProceduralBones.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_hMDL = -1;
  this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x0051A7A0
// Name: public: void CDmeGameModel::SetNumFlexWeights(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::SetNumFlexWeights(CDmeGameModel *this, unsigned int nFlexWeights)
{
  unsigned int m_Size; // eax
  unsigned int v4; // edi

  m_Size = this->m_flexWeights.m_Storage.m_Size;
  v4 = nFlexWeights;
  if ( m_Size >= nFlexWeights )
  {
    if ( m_Size > nFlexWeights )
    {
      do
      {
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
          this: &this->m_flexWeights,
          elem: m_Size - 1);
        m_Size = this->m_flexWeights.m_Storage.m_Size;
      }
      while ( m_Size > v4 );
    }
  }
  else
  {
    do
    {
      nFlexWeights = 0;
      CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &this->m_flexWeights,
        src: (float *)&nFlexWeights);
    }
    while ( this->m_flexWeights.m_Storage.m_Size < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051A800
// Name: private: int CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(void)const
// Source: json
//------------------------------------------------------------------------------
DmAttributeHandle_t __thiscall CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(
        CDmeGlobalFlexControllerOperator *this)
{
  CDmeGameModel *v1; // eax
  CDmeGameModel *v2; // esi
  int m_hMDL; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // edi
  int j; // ebx
  char *v7; // esi
  const char *m_pAsString; // ecx
  DmAttributeHandle_t v10; // edi
  CDmeGameModel *v11; // eax
  int fc; // [esp+8h] [ebp-Ch]
  LocalFlexController_t i; // [esp+10h] [ebp-4h]

  v1 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  v2 = v1;
  if ( v1->m_bHMDLDirty )
    CDmeGameModel::UpdateHMDL(this: v1);
  m_hMDL = v2->m_hMDL;
  if ( (_WORD)m_hMDL == 0xFFFF )
    return DMATTRIBUTE_HANDLE_INVALID;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: m_hMDL);
  v5 = v4;
  if ( v4 == nullptr )
    return DMATTRIBUTE_HANDLE_INVALID;
  fc = v4->numflexcontrollers;
  i = DUMMY_NULL_FLEX_CONTROLLER;
  if ( fc <= 0 )
    return DMATTRIBUTE_HANDLE_INVALID;
  for ( j = 0; ; j += 20 )
  {
    v7 = (char *)v5 + j + v5->flexcontrollerindex;
    if ( *((_DWORD *)v7 + 2) == -1 && g_pGlobalFlexController != nullptr )
      *((_DWORD *)v7 + 2) = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v7[*((_DWORD *)v7 + 1)]);
    m_pAsString = str;
    if ( this->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
      m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( _V_stricmp(s1: &v7[*((_DWORD *)v7 + 1)], s2: m_pAsString) == 0 )
      break;
    if ( ++i >= fc )
      return DMATTRIBUTE_HANDLE_INVALID;
  }
  v10 = *((_DWORD *)v7 + 2);
  if ( (unsigned int)v10 >= g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle)[2].m_ref.m_attributes.m_hAttribute )
  {
    v11 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
    CDmeGameModel::SetNumFlexWeights(this: v11, nFlexWeights: *((_DWORD *)v7 + 2) + 1);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0051A940
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Resolve(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  if ( this->m_ToAttributeHandle < 0 )
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  if ( this->m_gameModel.m_pAttribute == (CDmAttribute *)-1 )
  {
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute);
    if ( v2 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
      if ( Attribute != nullptr )
        this->m_gameModel.m_pAttribute = (CDmAttribute *)CDmAttribute::GetHandle(this: Attribute, bCreate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051A990
// Name: public: virtual void CDmeGlobalFlexControllerOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnAttributeChanged(
        CDmeGlobalFlexControllerOperator *this,
        CDmAttribute *pAttribute)
{
  if ( g_pGlobalFlexController != nullptr
    && pAttribute == (CDmAttribute *)this->m_gameModel.m_Storage.m_ElementType.u.m_Id
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute) != nullptr )
  {
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
    CDmeGlobalFlexControllerOperator::SetupToAttribute(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051A9E0
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x0051AA10
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute *v2; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v5 = (CDmAttribute **)attrs->m_pMemory;
    v6 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &v5[m_pMemory + 1], src: &v5[m_pMemory], count: 4 * v6);
    v7 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051AB70
// Name: public: virtual bool CDmeGlobalFlexControllerOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGlobalFlexControllerOperator::IsA(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051ABA0
// Name: public: virtual int CDmeGlobalFlexControllerOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGlobalFlexControllerOperator::GetInheritanceDepth(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051AC70
// Name: protected: virtual void CDmeGlobalFlexControllerOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::PerformConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  CDmeGlobalFlexControllerOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0051ADB0
// Name: protected: CDmeGameModel::CDmeGameModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CDmeGameModel::CDmeGameModel(
        CDmeGameModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeGameModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_globalFlexControllers);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_flexWeights);
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_skin.m_pAttribute = nullptr;
  this->m_skin.m_Storage = 0;
  this->m_body.m_pAttribute = nullptr;
  this->m_body.m_Storage = 0;
  this->m_sequence.m_pAttribute = nullptr;
  this->m_sequence.m_Storage = 0;
  this->m_flags.m_pAttribute = nullptr;
  this->m_flags.m_Storage = 0;
  this->m_bComputeBounds.m_pAttribute = nullptr;
  this->m_bComputeBounds.m_Storage = false;
  this->m_bEvaluateProceduralBones.m_pAttribute = nullptr;
  this->m_bEvaluateProceduralBones.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_bones);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051AE90
// Name: public: virtual bool CDmeGameModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameModel::IsA(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051AEC0
// Name: public: virtual int CDmeGameModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::GetInheritanceDepth(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051AF10
// Name: protected: virtual void CDmeGameModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformDestruction(CDmeGameModel *this)
{
  int m_hMDL; // eax

  m_hMDL = this->m_hMDL;
  if ( (_WORD)m_hMDL != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: m_hMDL);
    this->m_hMDL = -1;
  }
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0051AF50
// Name: protected: virtual int CDmeGameModel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::AllocatedSize(CDmeGameModel *this)
{
  return 276;
}

//------------------------------------------------------------------------------
// Address: 0x0051AF60
// Name: protected: virtual void CDmeGameModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformConstruction(CDmeGameModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0051AFE0
// Name: protected: CDmeGameSprite::CDmeGameSprite(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSprite *__thiscall CDmeGameSprite::CDmeGameSprite(
        CDmeGameSprite *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeGameSprite::`vftable';
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_frame.m_pAttribute = nullptr;
  this->m_frame.m_Storage = 0.0;
  this->m_rendermode.m_pAttribute = nullptr;
  this->m_rendermode.m_Storage = 0;
  this->m_renderfx.m_pAttribute = nullptr;
  this->m_renderfx.m_Storage = 0;
  this->m_renderscale.m_pAttribute = nullptr;
  this->m_renderscale.m_Storage = 0.0;
  this->m_color.m_pAttribute = nullptr;
  this->m_color.m_Storage = (Color)-16777216;
  this->m_proxyRadius.m_pAttribute = nullptr;
  this->m_proxyRadius.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051B0B0
// Name: public: virtual bool CDmeGameSprite::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSprite::IsA(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051B0E0
// Name: public: virtual int CDmeGameSprite::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::GetInheritanceDepth(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051B130
// Name: protected: virtual void CDmeGameSprite::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::PerformConstruction(CDmeGameSprite *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameSprite::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0051B190
// Name: protected: CDmeGamePortal::CDmeGamePortal(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGamePortal *__thiscall CDmeGamePortal::CDmeGamePortal(
        CDmeGamePortal *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeGamePortal::`vftable';
  this->m_nPortalId.m_pAttribute = nullptr;
  this->m_nPortalId.m_Storage = 0;
  this->m_nLinkedPortalId.m_pAttribute = nullptr;
  this->m_nLinkedPortalId.m_Storage = 0;
  this->m_flStaticAmount.m_pAttribute = nullptr;
  this->m_flStaticAmount.m_Storage = 0.0;
  this->m_flSecondaryStaticAmount.m_pAttribute = nullptr;
  this->m_flSecondaryStaticAmount.m_Storage = 0.0;
  this->m_flOpenAmount.m_pAttribute = nullptr;
  this->m_flOpenAmount.m_Storage = 0.0;
  this->m_flHalfWidth.m_pAttribute = nullptr;
  this->m_flHalfWidth.m_Storage = 0.0;
  this->m_flHalfHeight.m_pAttribute = nullptr;
  this->m_flHalfHeight.m_Storage = 0.0;
  this->m_bIsPortal2.m_pAttribute = nullptr;
  this->m_bIsPortal2.m_Storage = false;
  this->m_PortalType.m_Storage.u.m_Id = -1;
  this->m_PortalType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051B270
// Name: public: virtual bool CDmeGamePortal::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGamePortal::IsA(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051B2A0
// Name: public: virtual int CDmeGamePortal::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::GetInheritanceDepth(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051B2F0
// Name: protected: virtual void CDmeGamePortal::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::PerformConstruction(CDmeGamePortal *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGamePortal::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056BEA0
// Name: _dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGlobalFlexControllerOperator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGlobalFlexControllerOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BF00
// Name: _dynamic_initializer_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameModel::s_Allocator,
    blockSize: 276,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BF60
// Name: _dynamic_initializer_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSprite::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSprite pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BFC0
// Name: _dynamic_initializer_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGamePortal::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGamePortal pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056EBE0
// Name: _dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGlobalFlexControllerOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EBF0
// Name: _dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EC00
// Name: _dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSprite::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EC10
// Name: _dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGamePortal::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056BED0
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BEE0
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGlobalFlexControllerOperator_Helper,
           classname: "DmeGlobalFlexControllerOperator",
           pFactory: &g_CDmeGlobalFlexControllerOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056BF30
// Name: _dynamic_initializer_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BF90
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSprite_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BFA0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSprite_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSprite_Helper,
           classname: "DmeGameSprite",
           pFactory: &g_CDmeGameSprite_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056BFF0
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGamePortal_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C000
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGamePortal_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGamePortal_Helper,
           classname: "DmeGamePortal",
           pFactory: &g_CDmeGamePortal_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056EC20
// Name: _dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EC30
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSprite_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EC40
// Name: _dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGamePortal_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EC50
// Name: _dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGlobalFlexControllerOperator_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0046AB70
// Name: protected: virtual int CDmeGameSprite::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::AllocatedSize(CDmeVertexDeltaData *this)
{
  return 192;
}

//------------------------------------------------------------------------------
// Address: 0x0051FCD0
// Name: public: int CDmeGlobalFlexControllerOperator::GetGlobalIndex(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeGlobalFlexControllerOperator::GetGlobalIndex(CDmeTransform *this)
{
  return this->m_Orientation.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0051FCE0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Operate(CDmeGlobalFlexControllerOperator *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // edx
  void *m_pData; // ebx
  DmAttributeType_t v5; // esi
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_pAttribute = this->m_flexWeight.m_pAttribute;
    m_pData = m_pAttribute->m_pData;
    v5 = m_pAttribute->m_nFlags & 0x1F;
    if ( (v2->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v2, valueType: v5, pValue: m_pData);
    }
    else if ( this->m_nFlexControllerIndex != -1 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v2);
      CDmrGenericArray::Set(this: &array, i: this->m_nFlexControllerIndex, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051FD60
// Name: public: void CDmeGlobalFlexControllerOperator::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::SetupToAttribute(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
    if ( Attribute != nullptr )
      this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: Attribute, bCreate: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051FDA0
// Name: public: virtual void CDmeGameModel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnAttributeChanged(CDmeGameModel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_modelName.m_pAttribute )
    this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x0051FDC0
// Name: public: int CDmeGameModel::FindBone(class CDmeTransform __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::FindBone(CDmeGameModel *this, CDmeTransform *pTransform)
{
  if ( pTransform == nullptr )
    return -1;
  pTransform = (CDmeTransform *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pTransform);
  return CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
           this: &this->m_bones,
           value: (const DmElementHandle_t *)&pTransform);
}

//------------------------------------------------------------------------------
// Address: 0x0051FE00
// Name: public: char const __near * CDmeGameModel::GetModelName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeGameModel::GetModelName(CDmeGameModel *this)
{
  const char *result; // eax

  result = this->m_modelName.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return &pParentName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0051FE20
// Name: protected: void CDmeGameModel::UpdateHMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::UpdateHMDL(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // di

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  v3 = -1;
  if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
    v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( this->m_hMDL != 0xFFFF )
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_hMDL);
  this->m_hMDL = v3;
  this->m_bHMDLDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x0051FE80
// Name: protected: void CDmeGameSprite::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::OnConstruction(CDmeGameSprite *this)
{
  this->m_modelName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "modelName",
                                     type: AT_STRING,
                                     pMemory: &this->m_modelName);
  this->m_frame.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "frame",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_frame);
  this->m_rendermode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "rendermode",
                                      type: AT_INT,
                                      pMemory: &this->m_rendermode);
  this->m_renderfx.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "renderfx",
                                    type: AT_INT,
                                    pMemory: &this->m_renderfx);
  this->m_renderscale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "renderscale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_renderscale);
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  this->m_proxyRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "proxyRadius",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_proxyRadius);
}

//------------------------------------------------------------------------------
// Address: 0x0051FF30
// Name: protected: void CDmeGamePortal::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::OnConstruction(CDmeGamePortal *this)
{
  this->m_flStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "staticAmount",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flStaticAmount);
  this->m_flSecondaryStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "secondaryStaticAmount",
                                                   type: AT_FLOAT,
                                                   pMemory: &this->m_flSecondaryStaticAmount);
  this->m_flOpenAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "openAmount",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flOpenAmount);
  this->m_flHalfWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "halfWidth",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flHalfWidth);
  this->m_flHalfHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "halfHeight",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flHalfHeight);
  this->m_nPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "portalId",
                                     type: AT_INT,
                                     pMemory: &this->m_nPortalId);
  this->m_nLinkedPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "linkedPortalId",
                                           type: AT_INT,
                                           pMemory: &this->m_nLinkedPortalId);
  this->m_bIsPortal2.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isPortal2",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsPortal2);
  this->m_PortalType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "portalType",
                                      type: AT_STRING,
                                      pMemory: &this->m_PortalType);
}

//------------------------------------------------------------------------------
// Address: 0x00520010
// Name: protected: void CDmeGlobalFlexControllerOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_flexWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "flexWeight",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flexWeight);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_gameModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "gameModel",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_gameModel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_gameModel.m_pAttribute, typeSymbol: CDmeGameModel::m_classType);
  this->m_gameModel.m_pAttribute->m_nFlags |= 0x1100u;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_nFlexControllerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520080
// Name: protected: void CDmeGameModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnConstruction(CDmeGameModel *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_flexWeights,
    pOwner: this,
    pAttributeName: "flexWeights",
    nFlags: 0);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "modelName", type: AT_STRING, pMemory: &this->m_modelName);
  this->m_modelName.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  this->m_skin.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "skin",
                                type: AT_INT,
                                pMemory: &this->m_skin);
  this->m_body.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "body",
                                type: AT_INT,
                                pMemory: &this->m_body);
  this->m_sequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "sequence",
                                    type: AT_INT,
                                    pMemory: &this->m_sequence);
  this->m_flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_flags);
  this->m_bones.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "bones",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_bones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_bones.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  this->m_globalFlexControllers.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "globalFlexControllers",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_globalFlexControllers);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_globalFlexControllers.m_pAttribute,
    typeSymbol: CDmeGlobalFlexControllerOperator::m_classType);
  this->m_bComputeBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "computeBounds",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bComputeBounds);
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "evaluateProceduralBones",
         type: AT_BOOL,
         pMemory: &this->m_bEvaluateProceduralBones);
  this->m_bEvaluateProceduralBones.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_hMDL = -1;
  this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x005201D0
// Name: public: struct studiohdr_t __near * CDmeGameModel::GetStudioHdr(void)const
// Source: json
//------------------------------------------------------------------------------
studiohdr_t *__thiscall CDmeGameModel::GetStudioHdr(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v2; // ax

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    return nullptr;
  if ( m_pAsString == nullptr )
    return nullptr;
  if ( *m_pAsString == 0 )
    return nullptr;
  v2 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( v2 == 0xFFFF )
    return nullptr;
  else
    return g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00520220
// Name: public: bool CDmeGameModel::GetBoneDefaultPosition(int,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeGameModel::GetBoneDefaultPosition(CDmeGameModel *this, int nBoneIndex, Vector *position)
{
  const char *m_pAsString; // eax
  unsigned __int16 v4; // ax
  studiohdr_t *v5; // eax
  char *v6; // ecx

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    return 0;
  if ( m_pAsString == nullptr )
    return 0;
  if ( *m_pAsString == 0 )
    return 0;
  v4 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( v4 == 0xFFFF )
    return 0;
  v5 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v4);
  if ( v5 == nullptr )
    return 0;
  if ( nBoneIndex < 0 )
    return 0;
  if ( nBoneIndex >= v5->numbones )
    return 0;
  v6 = (char *)v5 + 216 * nBoneIndex + v5->boneindex;
  if ( v6 == nullptr )
    return 0;
  *position = *(Vector *)(v6 + 32);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005202B0
// Name: public: bool CDmeGameModel::GetBoneDefaultOrientation(int,class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeGameModel::GetBoneDefaultOrientation(CDmeGameModel *this, int nBoneIndex, Quaternion *orientation)
{
  const char *m_pAsString; // eax
  unsigned __int16 v4; // ax
  studiohdr_t *v5; // eax
  char *v6; // ecx

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    return 0;
  if ( m_pAsString == nullptr )
    return 0;
  if ( *m_pAsString == 0 )
    return 0;
  v4 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( v4 == 0xFFFF )
    return 0;
  v5 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v4);
  if ( v5 == nullptr )
    return 0;
  if ( nBoneIndex < 0 )
    return 0;
  if ( nBoneIndex >= v5->numbones )
    return 0;
  v6 = (char *)v5 + 216 * nBoneIndex + v5->boneindex;
  if ( v6 == nullptr )
    return 0;
  *orientation = *(Quaternion *)(v6 + 44);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00520340
// Name: public: int CDmeGameModel::NumGlobalFlexControllers(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::NumGlobalFlexControllers(CDmeGameModel *this)
{
  return this->m_globalFlexControllers.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00520350
// Name: public: unsigned int CDmeGameModel::NumBones(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::NumBones(CDmeGameModel *this)
{
  return this->m_bones.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00520360
// Name: public: void CDmeGameModel::SetNumFlexWeights(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::SetNumFlexWeights(CDmeGameModel *this, unsigned int nFlexWeights)
{
  unsigned int m_Size; // eax
  unsigned int v4; // edi

  m_Size = this->m_flexWeights.m_Storage.m_Size;
  v4 = nFlexWeights;
  if ( m_Size >= nFlexWeights )
  {
    if ( m_Size > nFlexWeights )
    {
      do
      {
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
          this: &this->m_flexWeights,
          elem: m_Size - 1);
        m_Size = this->m_flexWeights.m_Storage.m_Size;
      }
      while ( m_Size > v4 );
    }
  }
  else
  {
    do
    {
      nFlexWeights = 0;
      CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &this->m_flexWeights,
        src: (const float *)&nFlexWeights);
    }
    while ( this->m_flexWeights.m_Storage.m_Size < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005203C0
// Name: private: int CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(void)const
// Source: json
//------------------------------------------------------------------------------
DmAttributeHandle_t __thiscall CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(
        CDmeGlobalFlexControllerOperator *this)
{
  CDmeGameModel *v1; // eax
  CDmeGameModel *v2; // esi
  int m_hMDL; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // edi
  int j; // ebx
  char *v7; // esi
  const char *m_pAsString; // ecx
  DmAttributeHandle_t v10; // edi
  CDmeGameModel *v11; // eax
  int fc; // [esp+8h] [ebp-Ch]
  LocalFlexController_t i; // [esp+10h] [ebp-4h]

  v1 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  v2 = v1;
  if ( v1->m_bHMDLDirty )
    CDmeGameModel::UpdateHMDL(this: v1);
  m_hMDL = v2->m_hMDL;
  if ( (_WORD)m_hMDL == 0xFFFF )
    return DMATTRIBUTE_HANDLE_INVALID;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: m_hMDL);
  v5 = v4;
  if ( v4 == nullptr )
    return DMATTRIBUTE_HANDLE_INVALID;
  fc = v4->numflexcontrollers;
  i = DUMMY_NULL_FLEX_CONTROLLER;
  if ( fc <= 0 )
    return DMATTRIBUTE_HANDLE_INVALID;
  for ( j = 0; ; j += 20 )
  {
    v7 = (char *)v5 + j + v5->flexcontrollerindex;
    if ( *((_DWORD *)v7 + 2) == -1 && g_pGlobalFlexController != nullptr )
      *((_DWORD *)v7 + 2) = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v7[*((_DWORD *)v7 + 1)]);
    m_pAsString = &pParentName;
    if ( this->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
      m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( _V_stricmp(s1: &v7[*((_DWORD *)v7 + 1)], s2: m_pAsString) == 0 )
      break;
    if ( ++i >= fc )
      return DMATTRIBUTE_HANDLE_INVALID;
  }
  v10 = *((_DWORD *)v7 + 2);
  if ( (unsigned int)v10 >= g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle)[2].m_ref.m_attributes.m_hAttribute )
  {
    v11 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
    CDmeGameModel::SetNumFlexWeights(this: v11, nFlexWeights: *((_DWORD *)v7 + 2) + 1);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00520500
// Name: public: class CDmeGlobalFlexControllerOperator __near * CDmeGameModel::AddGlobalFlexController(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CDmeGlobalFlexControllerOperator *__thiscall CDmeGameModel::AddGlobalFlexController(
        CDmeGameModel *this,
        const char *controllerName,
        DmAttributeHandle_t globalIndex)
{
  int v3; // edi
  CDmaElementArray<CDmeGlobalFlexControllerOperator> *p_m_globalFlexControllers; // ebx
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  const char *m_pAsString; // eax
  DmElementHandle_t v8; // eax
  CDmElement *v9; // eax
  CDmElement *v10; // esi
  char *v11; // esi
  CDmElement *v13; // eax
  DmAttributeHandle_t v14; // edi
  CDmElement *v15; // esi
  char *v16; // ebx
  DmElementHandle_t v17; // eax
  CDmeGameModel *v18; // eax
  const char *v19; // eax
  CDmAttribute *v20; // ecx
  unsigned int m_Size; // eax
  unsigned __int32 v22; // esi
  int c; // [esp+Ch] [ebp-8h]
  CDmeGameModel *v24; // [esp+10h] [ebp-4h]

  v3 = 0;
  v24 = this;
  c = this->m_globalFlexControllers.m_Storage.m_Size;
  if ( c > 0 )
  {
    p_m_globalFlexControllers = &this->m_globalFlexControllers;
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_globalFlexControllers->m_Storage.m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr
        && v5->IsA(this: v5, a2: CDmeGlobalFlexControllerOperator::m_classType)
        && v6 != (CDmElement *)4 )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &pParentName;
        if ( _V_stricmp(s1: m_pAsString, s2: controllerName) == 0 )
          break;
      }
      if ( ++v3 >= c )
        goto LABEL_12;
    }
    if ( v3 < c )
      goto LABEL_18;
LABEL_12:
    this = v24;
  }
  v8 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeGlobalFlexControllerOperator::m_classType.u.m_Id,
         a3: controllerName,
         a4: this->m_fileId,
         a5: nullptr);
  v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8);
  v10 = v9;
  if ( v9 == nullptr )
    return nullptr;
  if ( !v9->IsA(this: v9, a2: CDmeGlobalFlexControllerOperator::m_classType) )
    return nullptr;
  v11 = (char *)&v10[-1] + 64;
  if ( v11 == nullptr )
    return nullptr;
  p_m_globalFlexControllers = &v24->m_globalFlexControllers;
  controllerName = (const char *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(v11 + 4));
  v3 = CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
         this: &v24->m_globalFlexControllers,
         src: (DmElementHandle_t *)&controllerName);
LABEL_18:
  v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_globalFlexControllers->m_Storage.m_Memory.m_pMemory[v3]);
  v14 = globalIndex;
  v15 = v13;
  if ( v13 != nullptr && v13->IsA(this: v13, a2: CDmeGlobalFlexControllerOperator::m_classType) )
  {
    v16 = (char *)&v15[-1] + 64;
    if ( v15 != (CDmElement *)4 )
    {
      v17 = *((_DWORD *)v16 + 21);
      *((_DWORD *)v16 + 25) = v14;
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: v17) != nullptr
        && (unsigned int)v14 >= g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v16 + 21))[2].m_ref.m_attributes.m_hAttribute )
      {
        v18 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v16 + 21));
        CDmeGameModel::SetNumFlexWeights(this: v18, nFlexWeights: v14 + 1);
      }
      v19 = (const char *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v24);
      v20 = *((CDmAttribute **)v16 + 23);
      controllerName = v19;
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: v20, value: (DmElementHandle_t *)&controllerName);
    }
  }
  else
  {
    v16 = nullptr;
  }
  m_Size = v24->m_flexWeights.m_Storage.m_Size;
  if ( v14 < m_Size )
    return (CDmeGlobalFlexControllerOperator *)v16;
  v22 = v14 + 1;
  if ( m_Size >= v14 + 1 )
  {
    if ( m_Size > v14 + 1 )
    {
      do
      {
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
          this: &v24->m_flexWeights,
          elem: m_Size - 1);
        m_Size = v24->m_flexWeights.m_Storage.m_Size;
      }
      while ( m_Size > v22 );
    }
    return (CDmeGlobalFlexControllerOperator *)v16;
  }
  do
  {
    controllerName = nullptr;
    CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
      this: &v24->m_flexWeights,
      src: (const float *)&controllerName);
  }
  while ( v24->m_flexWeights.m_Storage.m_Size < v22 );
  return (CDmeGlobalFlexControllerOperator *)v16;
}

//------------------------------------------------------------------------------
// Address: 0x00520730
// Name: public: class CDmeGlobalFlexControllerOperator __near * CDmeGameModel::FindGlobalFlexController(int)
// Source: json
//------------------------------------------------------------------------------
CDmeGlobalFlexControllerOperator *__thiscall CDmeGameModel::FindGlobalFlexController(
        CDmeGameModel *this,
        int nGlobalIndex)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmeGlobalFlexControllerOperator *result; // eax
  int c; // [esp+Ch] [ebp-4h]

  v3 = 0;
  c = this->m_globalFlexControllers.m_Storage.m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(
           this: g_pDataModel,
           a2: this->m_globalFlexControllers.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeGlobalFlexControllerOperator::m_classType) )
    {
      result = (CDmeGlobalFlexControllerOperator *)((char *)&v5[-1] + 64);
      if ( v5 != (CDmElement *)4 && result->m_nFlexControllerIndex == nGlobalIndex )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005207B0
// Name: public: class CDmeGlobalFlexControllerOperator __near * CDmeGameModel::GetGlobalFlexController(int)
// Source: json
//------------------------------------------------------------------------------
CDmeGlobalFlexControllerOperator *__thiscall CDmeGameModel::GetGlobalFlexController(
        CDmeGameModel *this,
        int localIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(
         this: g_pDataModel,
         a2: this->m_globalFlexControllers.m_Storage.m_Memory.m_pMemory[localIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeGlobalFlexControllerOperator::m_classType) )
    return (CDmeGlobalFlexControllerOperator *)((char *)&v3[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00520800
// Name: public: void CDmeGameModel::RemoveGlobalFlexController(class CDmeGlobalFlexControllerOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::RemoveGlobalFlexController(
        CDmeGameModel *this,
        CDmeGlobalFlexControllerOperator *controller)
{
  int v2; // edi
  CDmaElementArray<CDmeGlobalFlexControllerOperator> *p_m_globalFlexControllers; // ebx
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmeGlobalFlexControllerOperator *v6; // eax
  int c; // [esp+Ch] [ebp-4h]

  v2 = 0;
  c = this->m_globalFlexControllers.m_Storage.m_Size;
  if ( c > 0 )
  {
    p_m_globalFlexControllers = &this->m_globalFlexControllers;
    while ( 1 )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_globalFlexControllers->m_Storage.m_Memory.m_pMemory[v2]);
      v5 = v4;
      if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeGlobalFlexControllerOperator::m_classType) )
        v6 = (CDmeGlobalFlexControllerOperator *)((char *)&v5[-1] + 64);
      else
        v6 = nullptr;
      if ( v6 == controller )
        break;
      if ( ++v2 >= c )
        return;
    }
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
      this: p_m_globalFlexControllers,
      elem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520880
// Name: public: class CDmeTransform __near * CDmeGameModel::GetBone(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeGameModel::GetBone(CDmeGameModel *this, unsigned int index)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_bones.m_Storage.m_Memory.m_pMemory[index]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005208D0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Resolve(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  if ( this->m_ToAttributeHandle < 0 )
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  if ( this->m_gameModel.m_pAttribute == (CDmAttribute *)-1 )
  {
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute);
    if ( v2 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
      if ( Attribute != nullptr )
        this->m_gameModel.m_pAttribute = (CDmAttribute *)CDmAttribute::GetHandle(this: Attribute, bCreate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520920
// Name: public: virtual void CDmeGlobalFlexControllerOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnAttributeChanged(
        CDmeGlobalFlexControllerOperator *this,
        CDmAttribute *pAttribute)
{
  if ( g_pGlobalFlexController != nullptr
    && pAttribute == (CDmAttribute *)this->m_gameModel.m_Storage.m_ElementType.u.m_Id
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute) != nullptr )
  {
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
    CDmeGlobalFlexControllerOperator::SetupToAttribute(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520970
// Name: protected: void CDmeGameModel::PopulateExistingDagList(class CDmeDag __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PopulateExistingDagList(CDmeGameModel *this, CDmeDag **pDags, int nCount)
{
  int v4; // edi
  CDmElement *v5; // eax
  CDmeTransform *v6; // esi
  CDmeDag *Dag; // eax
  int nCurrentBoneCount; // [esp+Ch] [ebp-4h]

  v4 = 0;
  for ( nCurrentBoneCount = this->m_bones.m_Storage.m_Size; v4 < nCount; ++v4 )
  {
    if ( v4 < nCurrentBoneCount )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_bones.m_Storage.m_Memory.m_pMemory[v4]);
      v6 = (CDmeTransform *)v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransform::m_classType) )
        Dag = CDmeTransform::GetDag(this: v6);
      else
        Dag = nullptr;
      pDags[v4] = Dag;
    }
    else
    {
      pDags[v4] = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520A00
// Name: public: void CDmeGameModel::AddBones(struct studiohdr_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::AddBones(CDmeGameModel *this, studiohdr_t *pStudioHdr, int nFirstBone, int nCount)
{
  int numbones; // eax
  int v5; // esi
  void *v6; // esp
  int v7; // edi
  int v8; // ebx
  const char *v9; // eax
  int v10; // ecx
  DmElementHandle_t v11; // eax
  CDmElement *v12; // eax
  CDmeDag *v13; // esi
  CDmeTransform *Transform; // esi
  CDmeDag *v15[3]; // [esp+0h] [ebp-124h] BYREF
  char name[256]; // [esp+Ch] [ebp-118h] BYREF
  DmElementHandle_t src; // [esp+10Ch] [ebp-18h] BYREF
  CUtlSymbolLarge value; // [esp+110h] [ebp-14h] BYREF
  CDmeDag **pDags; // [esp+114h] [ebp-10h]
  CDmeDag *pParent; // [esp+118h] [ebp-Ch]
  CDmeDag **v21; // [esp+11Ch] [ebp-8h]
  CDmeGameModel *v22; // [esp+120h] [ebp-4h]

  numbones = pStudioHdr->numbones;
  v5 = nFirstBone;
  v22 = this;
  if ( nFirstBone + nCount <= numbones || (nCount = numbones - nFirstBone, numbones - nFirstBone > 0) )
  {
    v6 = alloca(4 * numbones);
    pDags = v15;
    CDmeGameModel::PopulateExistingDagList(this, pDags: v15, nCount: nFirstBone);
    v7 = 0;
    if ( nCount > 0 )
    {
      v8 = 216 * nFirstBone;
      v21 = &pDags[nFirstBone];
      while ( 1 )
      {
        v9 = (char *)pStudioHdr + v8 + pStudioHdr->boneindex;
        v10 = *((_DWORD *)v9 + 1);
        pParent = v10 >= 0 ? pDags[v10] : v22;
        V_snprintf(pDest: name, maxLen: 256, pFormat: "bone %d (%s)", v7 + v5, &v9[*(_DWORD *)v9]);
        v11 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
                a1: g_pDataModel,
                a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id,
                a3: name,
                a4: v22->m_fileId,
                a5: nullptr);
        v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: v11);
        v13 = (CDmeDag *)v12;
        if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmeDag::m_classType) )
          v13 = nullptr;
        *v21 = v13;
        CDmeDag::AddChild(this: pParent, pDag: v13);
        Transform = CDmeDag::GetTransform(this: v13);
        g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: name);
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: Transform->m_Name.m_pAttribute, &value);
        src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)Transform);
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &v22->m_bones,
          &src);
        ++v21;
        ++v7;
        v8 += 216;
        if ( v7 >= nCount )
          break;
        v5 = nFirstBone;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520B90
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x00520BC0
// Name: public: int CDmeGameModel::FindAttachment(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::FindAttachment(CDmeGameModel *this, const char *pchAttachmentName)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // ax
  const studiohdr_t *v4; // eax
  int Attachment; // esi
  CStudioHdr studioHdr; // [esp+0h] [ebp-64h] BYREF

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    return 0;
  if ( m_pAsString == nullptr )
    return 0;
  if ( *m_pAsString == 0 )
    return 0;
  v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( v3 == 0xFFFF )
    return 0;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v3);
  if ( v4 == nullptr )
    return 0;
  CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v4, mdlcache: nullptr);
  Attachment = Studio_FindAttachment(pStudioHdr: &studioHdr, pAttachmentName: pchAttachmentName);
  CStudioHdr::Term(this: &studioHdr);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&studioHdr.m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&studioHdr.m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&studioHdr.m_pStudioHdrCache);
  return Attachment + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00520C60
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *v2; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v6 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520D90
// Name: public: virtual bool CDmeGlobalFlexControllerOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGlobalFlexControllerOperator::IsA(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520DC0
// Name: public: virtual int CDmeGlobalFlexControllerOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGlobalFlexControllerOperator::GetInheritanceDepth(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520E90
// Name: protected: virtual void CDmeGlobalFlexControllerOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::PerformConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  CDmeGlobalFlexControllerOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00520FD0
// Name: protected: CDmeGameModel::CDmeGameModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CDmeGameModel::CDmeGameModel(
        CDmeGameModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeGameModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_globalFlexControllers);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_flexWeights);
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_skin.m_pAttribute = nullptr;
  this->m_skin.m_Storage = 0;
  this->m_body.m_pAttribute = nullptr;
  this->m_body.m_Storage = 0;
  this->m_sequence.m_pAttribute = nullptr;
  this->m_sequence.m_Storage = 0;
  this->m_flags.m_pAttribute = nullptr;
  this->m_flags.m_Storage = 0;
  this->m_bComputeBounds.m_pAttribute = nullptr;
  this->m_bComputeBounds.m_Storage = false;
  this->m_bEvaluateProceduralBones.m_pAttribute = nullptr;
  this->m_bEvaluateProceduralBones.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_bones);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005210B0
// Name: public: virtual bool CDmeGameModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameModel::IsA(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005210E0
// Name: public: virtual int CDmeGameModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::GetInheritanceDepth(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00521130
// Name: protected: virtual void CDmeGameModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformDestruction(CDmeGameModel *this)
{
  int m_hMDL; // eax

  m_hMDL = this->m_hMDL;
  if ( (_WORD)m_hMDL != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: m_hMDL);
    this->m_hMDL = -1;
  }
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00521170
// Name: protected: virtual int CDmeGameModel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::AllocatedSize(CDmeGameModel *this)
{
  return 276;
}

//------------------------------------------------------------------------------
// Address: 0x00521180
// Name: protected: virtual void CDmeGameModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformConstruction(CDmeGameModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00521200
// Name: protected: CDmeGameSprite::CDmeGameSprite(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSprite *__thiscall CDmeGameSprite::CDmeGameSprite(
        CDmeGameSprite *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeGameSprite::`vftable';
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_frame.m_pAttribute = nullptr;
  this->m_frame.m_Storage = 0.0;
  this->m_rendermode.m_pAttribute = nullptr;
  this->m_rendermode.m_Storage = 0;
  this->m_renderfx.m_pAttribute = nullptr;
  this->m_renderfx.m_Storage = 0;
  this->m_renderscale.m_pAttribute = nullptr;
  this->m_renderscale.m_Storage = 0.0;
  this->m_color.m_pAttribute = nullptr;
  this->m_color.m_Storage = (Color)-16777216;
  this->m_proxyRadius.m_pAttribute = nullptr;
  this->m_proxyRadius.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005212D0
// Name: public: virtual bool CDmeGameSprite::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSprite::IsA(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00521300
// Name: public: virtual int CDmeGameSprite::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::GetInheritanceDepth(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00521350
// Name: protected: virtual void CDmeGameSprite::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::PerformConstruction(CDmeGameSprite *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameSprite::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005213B0
// Name: protected: CDmeGamePortal::CDmeGamePortal(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGamePortal *__thiscall CDmeGamePortal::CDmeGamePortal(
        CDmeGamePortal *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeGamePortal::`vftable';
  this->m_nPortalId.m_pAttribute = nullptr;
  this->m_nPortalId.m_Storage = 0;
  this->m_nLinkedPortalId.m_pAttribute = nullptr;
  this->m_nLinkedPortalId.m_Storage = 0;
  this->m_flStaticAmount.m_pAttribute = nullptr;
  this->m_flStaticAmount.m_Storage = 0.0;
  this->m_flSecondaryStaticAmount.m_pAttribute = nullptr;
  this->m_flSecondaryStaticAmount.m_Storage = 0.0;
  this->m_flOpenAmount.m_pAttribute = nullptr;
  this->m_flOpenAmount.m_Storage = 0.0;
  this->m_flHalfWidth.m_pAttribute = nullptr;
  this->m_flHalfWidth.m_Storage = 0.0;
  this->m_flHalfHeight.m_pAttribute = nullptr;
  this->m_flHalfHeight.m_Storage = 0.0;
  this->m_bIsPortal2.m_pAttribute = nullptr;
  this->m_bIsPortal2.m_Storage = false;
  this->m_PortalType.m_Storage.u.m_Id = -1;
  this->m_PortalType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00521490
// Name: public: virtual bool CDmeGamePortal::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGamePortal::IsA(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005214C0
// Name: public: virtual int CDmeGamePortal::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::GetInheritanceDepth(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00521510
// Name: protected: virtual int CDmeGamePortal::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::AllocatedSize(CDmeSpotLight *this)
{
  return 208;
}

//------------------------------------------------------------------------------
// Address: 0x00521520
// Name: protected: virtual void CDmeGamePortal::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::PerformConstruction(CDmeGamePortal *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGamePortal::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057BFB0
// Name: _dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGlobalFlexControllerOperator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGlobalFlexControllerOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C020
// Name: _dynamic_initializer_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameModel::s_Allocator,
    blockSize: 276,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C080
// Name: _dynamic_initializer_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSprite::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSprite pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C0E0
// Name: _dynamic_initializer_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGamePortal::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGamePortal pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED10
// Name: _dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGlobalFlexControllerOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED20
// Name: _dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED30
// Name: _dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSprite::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED40
// Name: _dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGamePortal::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BFE0
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C000
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGlobalFlexControllerOperator_Helper,
           classname: "DmeGlobalFlexControllerOperator",
           pFactory: &g_CDmeGlobalFlexControllerOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C050
// Name: _dynamic_initializer_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C060
// Name: _dynamic_initializer_for__g_CDmeGameModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameModel_Helper,
           classname: "DmeGameModel",
           pFactory: &g_CDmeGameModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C0B0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSprite_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C0C0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSprite_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSprite_Helper,
           classname: "DmeGameSprite",
           pFactory: &g_CDmeGameSprite_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C110
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGamePortal_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C120
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGamePortal_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGamePortal_Helper,
           classname: "DmeGamePortal",
           pFactory: &g_CDmeGamePortal_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED50
// Name: _dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED60
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSprite_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED70
// Name: _dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGamePortal_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED80
// Name: _dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGlobalFlexControllerOperator_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005DD180
// Name: protected: virtual int CDmeGamePortal::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::AllocatedSize(CDmeSpotLight *this)
{
  return 208;
}

//------------------------------------------------------------------------------
// Address: 0x005DD490
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Operate(CDmeGlobalFlexControllerOperator *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // edx
  void *m_pData; // ebx
  DmAttributeType_t v5; // esi
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_pAttribute = this->m_flexWeight.m_pAttribute;
    m_pData = m_pAttribute->m_pData;
    v5 = m_pAttribute->m_nFlags & 0x1F;
    if ( (v2->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v2, valueType: v5, pValue: m_pData);
    }
    else if ( this->m_nFlexControllerIndex != -1 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v2);
      CDmrGenericArray::Set(this: &array, i: this->m_nFlexControllerIndex, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DD510
// Name: public: void CDmeGlobalFlexControllerOperator::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::SetupToAttribute(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_gameModel.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
    if ( Attribute != nullptr )
      this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: Attribute, bCreate: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DD550
// Name: public: virtual void CDmeGameModel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnAttributeChanged(CDmeGameModel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_modelName.m_pAttribute )
    this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x005DD570
// Name: protected: void CDmeGameModel::UpdateHMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::UpdateHMDL(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // di

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  v3 = -1;
  if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
    v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( this->m_hMDL != 0xFFFF )
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_hMDL);
  this->m_hMDL = v3;
  this->m_bHMDLDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x005DD5D0
// Name: protected: void CDmeGameSprite::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::OnConstruction(CDmeGameSprite *this)
{
  this->m_modelName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "modelName",
                                     type: AT_STRING,
                                     pMemory: &this->m_modelName);
  this->m_frame.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "frame",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_frame);
  this->m_rendermode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "rendermode",
                                      type: AT_INT,
                                      pMemory: &this->m_rendermode);
  this->m_renderfx.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "renderfx",
                                    type: AT_INT,
                                    pMemory: &this->m_renderfx);
  this->m_renderscale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "renderscale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_renderscale);
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  this->m_proxyRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "proxyRadius",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_proxyRadius);
}

//------------------------------------------------------------------------------
// Address: 0x005DD680
// Name: protected: void CDmeGamePortal::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::OnConstruction(CDmeGamePortal *this)
{
  this->m_flStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "staticAmount",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flStaticAmount);
  this->m_flSecondaryStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "secondaryStaticAmount",
                                                   type: AT_FLOAT,
                                                   pMemory: &this->m_flSecondaryStaticAmount);
  this->m_flOpenAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "openAmount",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flOpenAmount);
  this->m_flHalfWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "halfWidth",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flHalfWidth);
  this->m_flHalfHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "halfHeight",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flHalfHeight);
  this->m_nPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "portalId",
                                     type: AT_INT,
                                     pMemory: &this->m_nPortalId);
  this->m_nLinkedPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "linkedPortalId",
                                           type: AT_INT,
                                           pMemory: &this->m_nLinkedPortalId);
  this->m_bIsPortal2.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isPortal2",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsPortal2);
  this->m_PortalType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "portalType",
                                      type: AT_STRING,
                                      pMemory: &this->m_PortalType);
}

//------------------------------------------------------------------------------
// Address: 0x005DD760
// Name: protected: void CDmeGlobalFlexControllerOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_flexWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "flexWeight",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flexWeight);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_gameModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "gameModel",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_gameModel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_gameModel.m_pAttribute, typeSymbol: CDmeGameModel::m_classType);
  this->m_gameModel.m_pAttribute->m_nFlags |= 0x1100u;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_nFlexControllerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DD7D0
// Name: protected: void CDmeGameModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnConstruction(CDmeGameModel *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_flexWeights,
    pOwner: this,
    pAttributeName: "flexWeights",
    nFlags: 0);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "modelName", type: AT_STRING, pMemory: &this->m_modelName);
  this->m_modelName.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  this->m_skin.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "skin",
                                type: AT_INT,
                                pMemory: &this->m_skin);
  this->m_body.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "body",
                                type: AT_INT,
                                pMemory: &this->m_body);
  this->m_sequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "sequence",
                                    type: AT_INT,
                                    pMemory: &this->m_sequence);
  this->m_flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_flags);
  this->m_bones.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "bones",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_bones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_bones.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  this->m_globalFlexControllers.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "globalFlexControllers",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_globalFlexControllers);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_globalFlexControllers.m_pAttribute,
    typeSymbol: CDmeGlobalFlexControllerOperator::m_classType);
  this->m_bComputeBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "computeBounds",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bComputeBounds);
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "evaluateProceduralBones",
         type: AT_BOOL,
         pMemory: &this->m_bEvaluateProceduralBones);
  this->m_bEvaluateProceduralBones.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_hMDL = -1;
  this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x005DD920
// Name: public: void CDmeGameModel::SetNumFlexWeights(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::SetNumFlexWeights(CDmeGameModel *this, unsigned int nFlexWeights)
{
  unsigned int m_Size; // eax
  unsigned int v4; // edi

  m_Size = this->m_flexWeights.m_Storage.m_Size;
  v4 = nFlexWeights;
  if ( m_Size >= nFlexWeights )
  {
    if ( m_Size > nFlexWeights )
    {
      do
      {
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
          this: &this->m_flexWeights,
          elem: m_Size - 1);
        m_Size = this->m_flexWeights.m_Storage.m_Size;
      }
      while ( m_Size > v4 );
    }
  }
  else
  {
    do
    {
      nFlexWeights = 0;
      CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &this->m_flexWeights,
        src: (const float *)&nFlexWeights);
    }
    while ( this->m_flexWeights.m_Storage.m_Size < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DD980
// Name: private: int CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(
        CDmeGlobalFlexControllerOperator *this)
{
  CDmeGameModel *v1; // eax
  CDmeGameModel *v2; // esi
  int m_hMDL; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // edi
  int j; // ebx
  char *v7; // esi
  const char *m_pAsString; // ecx
  unsigned int v10; // edi
  CDmeGameModel *v11; // eax
  int fc; // [esp+8h] [ebp-Ch]
  LocalFlexController_t i; // [esp+10h] [ebp-4h]

  v1 = (CDmeGameModel *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_gameModel.m_Storage.m_Handle);
  v2 = v1;
  if ( v1->m_bHMDLDirty )
    CDmeGameModel::UpdateHMDL(this: v1);
  m_hMDL = v2->m_hMDL;
  if ( (_WORD)m_hMDL == 0xFFFF )
    return -1;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: m_hMDL);
  v5 = v4;
  if ( v4 == nullptr )
    return -1;
  fc = v4->numflexcontrollers;
  i = DUMMY_NULL_FLEX_CONTROLLER;
  if ( fc <= 0 )
    return -1;
  for ( j = 0; ; j += 20 )
  {
    v7 = (char *)v5 + j + v5->flexcontrollerindex;
    if ( *((_DWORD *)v7 + 2) == -1 && g_pGlobalFlexController != nullptr )
      *((_DWORD *)v7 + 2) = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v7[*((_DWORD *)v7 + 1)]);
    m_pAsString = defaultValue;
    if ( this->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
      m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( _V_stricmp(s1: &v7[*((_DWORD *)v7 + 1)], s2: m_pAsString) == 0 )
      break;
    if ( ++i >= fc )
      return -1;
  }
  v10 = *((_DWORD *)v7 + 2);
  if ( v10 >= *(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: this->m_gameModel.m_Storage.m_Handle)
                        + 176) )
  {
    v11 = (CDmeGameModel *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_gameModel.m_Storage.m_Handle);
    CDmeGameModel::SetNumFlexWeights(this: v11, nFlexWeights: *((_DWORD *)v7 + 2) + 1);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x005DDAC0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Resolve(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  if ( this->m_ToAttributeHandle < 0 )
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  if ( this->m_gameModel.m_pAttribute == (CDmAttribute *)-1 )
  {
    v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_flexWeight.m_pAttribute);
    if ( v2 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
      if ( Attribute != nullptr )
        this->m_gameModel.m_pAttribute = (CDmAttribute *)CDmAttribute::GetHandle(this: Attribute, bCreate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DDB10
// Name: public: virtual void CDmeGlobalFlexControllerOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnAttributeChanged(
        CDmeGlobalFlexControllerOperator *this,
        CDmAttribute *pAttribute)
{
  if ( g_pGlobalFlexController != nullptr
    && pAttribute == (CDmAttribute *)this->m_gameModel.m_Storage.m_ElementType.u.m_Id
    && (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_flexWeight.m_pAttribute) != 0 )
  {
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
    CDmeGlobalFlexControllerOperator::SetupToAttribute(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DDB60
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int v2; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 336))(
         a1: g_pDataModel.u,
         a2: this->m_ToAttributeHandle);
  if ( v2 != 0 )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v5 = (CDmAttribute **)attrs->m_pMemory;
    v6 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &v5[m_pMemory + 1], src: &v5[m_pMemory], count: 4 * v6);
    v7 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (CDmAttribute *)v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DDC90
// Name: public: virtual bool CDmeGlobalFlexControllerOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGlobalFlexControllerOperator::IsA(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DDCC0
// Name: public: virtual int CDmeGlobalFlexControllerOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGlobalFlexControllerOperator::GetInheritanceDepth(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DDDB0
// Name: protected: virtual void CDmeGlobalFlexControllerOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::PerformConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  CDmeGlobalFlexControllerOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005DDEF0
// Name: protected: CDmeGameModel::CDmeGameModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CDmeGameModel::CDmeGameModel(
        CDmeGameModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeGameModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_globalFlexControllers);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_flexWeights);
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_skin.m_pAttribute = nullptr;
  this->m_skin.m_Storage = 0;
  this->m_body.m_pAttribute = nullptr;
  this->m_body.m_Storage = 0;
  this->m_sequence.m_pAttribute = nullptr;
  this->m_sequence.m_Storage = 0;
  this->m_flags.m_pAttribute = nullptr;
  this->m_flags.m_Storage = 0;
  this->m_bComputeBounds.m_pAttribute = nullptr;
  this->m_bComputeBounds.m_Storage = false;
  this->m_bEvaluateProceduralBones.m_pAttribute = nullptr;
  this->m_bEvaluateProceduralBones.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_bones);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005DDFD0
// Name: public: virtual bool CDmeGameModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameModel::IsA(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DE000
// Name: public: virtual int CDmeGameModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::GetInheritanceDepth(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DE050
// Name: protected: virtual void CDmeGameModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformDestruction(CDmeGameModel *this)
{
  int m_hMDL; // eax

  m_hMDL = this->m_hMDL;
  if ( (_WORD)m_hMDL != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: m_hMDL);
    this->m_hMDL = -1;
  }
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005DE090
// Name: protected: virtual void CDmeGameModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformConstruction(CDmeGameModel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeGameModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005DE110
// Name: protected: CDmeGameSprite::CDmeGameSprite(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSprite *__thiscall CDmeGameSprite::CDmeGameSprite(
        CDmeGameSprite *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeGameSprite::`vftable';
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_frame.m_pAttribute = nullptr;
  this->m_frame.m_Storage = 0.0;
  this->m_rendermode.m_pAttribute = nullptr;
  this->m_rendermode.m_Storage = 0;
  this->m_renderfx.m_pAttribute = nullptr;
  this->m_renderfx.m_Storage = 0;
  this->m_renderscale.m_pAttribute = nullptr;
  this->m_renderscale.m_Storage = 0.0;
  this->m_color.m_pAttribute = nullptr;
  this->m_color.m_Storage = (Color)-16777216;
  this->m_proxyRadius.m_pAttribute = nullptr;
  this->m_proxyRadius.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005DE1E0
// Name: public: virtual bool CDmeGameSprite::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSprite::IsA(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DE210
// Name: public: virtual int CDmeGameSprite::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::GetInheritanceDepth(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DE260
// Name: protected: virtual int CDmeGameSprite::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::AllocatedSize(CDmeVertexDeltaData *this)
{
  return 192;
}

//------------------------------------------------------------------------------
// Address: 0x005DE270
// Name: protected: virtual void CDmeGameSprite::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::PerformConstruction(CDmeGameSprite *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeGameSprite::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005DE2D0
// Name: protected: CDmeGamePortal::CDmeGamePortal(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGamePortal *__thiscall CDmeGamePortal::CDmeGamePortal(
        CDmeGamePortal *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeGamePortal::`vftable';
  this->m_nPortalId.m_pAttribute = nullptr;
  this->m_nPortalId.m_Storage = 0;
  this->m_nLinkedPortalId.m_pAttribute = nullptr;
  this->m_nLinkedPortalId.m_Storage = 0;
  this->m_flStaticAmount.m_pAttribute = nullptr;
  this->m_flStaticAmount.m_Storage = 0.0;
  this->m_flSecondaryStaticAmount.m_pAttribute = nullptr;
  this->m_flSecondaryStaticAmount.m_Storage = 0.0;
  this->m_flOpenAmount.m_pAttribute = nullptr;
  this->m_flOpenAmount.m_Storage = 0.0;
  this->m_flHalfWidth.m_pAttribute = nullptr;
  this->m_flHalfWidth.m_Storage = 0.0;
  this->m_flHalfHeight.m_pAttribute = nullptr;
  this->m_flHalfHeight.m_Storage = 0.0;
  this->m_bIsPortal2.m_pAttribute = nullptr;
  this->m_bIsPortal2.m_Storage = false;
  this->m_PortalType.m_Storage.u.m_Id = -1;
  this->m_PortalType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005DE3B0
// Name: public: virtual bool CDmeGamePortal::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGamePortal::IsA(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DE3E0
// Name: public: virtual int CDmeGamePortal::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::GetInheritanceDepth(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DE430
// Name: protected: virtual void CDmeGamePortal::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::PerformConstruction(CDmeGamePortal *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeGamePortal::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B1110
// Name: _dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGlobalFlexControllerOperator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGlobalFlexControllerOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1170
// Name: _dynamic_initializer_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameModel::s_Allocator,
    blockSize: 276,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B11D0
// Name: _dynamic_initializer_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSprite::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSprite pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1230
// Name: _dynamic_initializer_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGamePortal::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGamePortal pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5500
// Name: _dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGlobalFlexControllerOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5510
// Name: _dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5520
// Name: _dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSprite::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5530
// Name: _dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGamePortal::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B1140
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1150
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGlobalFlexControllerOperator_Helper,
           classname: "DmeGlobalFlexControllerOperator",
           pFactory: &g_CDmeGlobalFlexControllerOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B11A0
// Name: _dynamic_initializer_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B11B0
// Name: _dynamic_initializer_for__g_CDmeGameModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameModel_Helper,
           classname: "DmeGameModel",
           pFactory: &g_CDmeGameModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1200
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSprite_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1210
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSprite_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSprite_Helper,
           classname: "DmeGameSprite",
           pFactory: &g_CDmeGameSprite_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1260
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGamePortal_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1270
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGamePortal_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGamePortal_Helper,
           classname: "DmeGamePortal",
           pFactory: &g_CDmeGamePortal_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5540
// Name: _dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeGameModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5550
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeGameSprite_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5560
// Name: _dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeGamePortal_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5570
// Name: _dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeGlobalFlexControllerOperator_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0046A2A0
// Name: public: int CDmeGlobalFlexControllerOperator::GetGlobalIndex(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeGlobalFlexControllerOperator::GetGlobalIndex(CDmeTransform *this)
{
  return this->m_Orientation.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x00520AF0
// Name: protected: virtual int CDmeGamePortal::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::AllocatedSize(CDmeSpotLight *this)
{
  return 208;
}

//------------------------------------------------------------------------------
// Address: 0x00520E10
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Operate(CDmeGlobalFlexControllerOperator *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // edx
  void *m_pData; // ebx
  DmAttributeType_t v5; // esi
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_pAttribute = this->m_flexWeight.m_pAttribute;
    m_pData = m_pAttribute->m_pData;
    v5 = m_pAttribute->m_nFlags & 0x1F;
    if ( (v2->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v2, valueType: v5, pValue: m_pData);
    }
    else if ( this->m_nFlexControllerIndex != -1 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v2);
      CDmrGenericArray::Set(this: &array, i: this->m_nFlexControllerIndex, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520ED0
// Name: public: virtual void CDmeGameModel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnAttributeChanged(CDmeGameModel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_modelName.m_pAttribute )
    this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x00520EF0
// Name: public: int CDmeGameModel::FindBone(class CDmeTransform __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::FindBone(CDmeGameModel *this, CDmeTransform *pTransform)
{
  if ( pTransform == nullptr )
    return -1;
  pTransform = (CDmeTransform *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pTransform);
  return CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
           this: &this->m_bones,
           value: (const DmElementHandle_t *)&pTransform);
}

//------------------------------------------------------------------------------
// Address: 0x00520F30
// Name: public: char const __near * CDmeGameModel::GetModelName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeGameModel::GetModelName(CDmeGameModel *this)
{
  const char *result; // eax

  result = this->m_modelName.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return &pch;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00520F50
// Name: protected: void CDmeGameModel::UpdateHMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::UpdateHMDL(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // di

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  v3 = -1;
  if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
    v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( this->m_hMDL != 0xFFFF )
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_hMDL);
  this->m_hMDL = v3;
  this->m_bHMDLDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00520FB0
// Name: protected: void CDmeGameSprite::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::OnConstruction(CDmeGameSprite *this)
{
  this->m_modelName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "modelName",
                                     type: AT_STRING,
                                     pMemory: &this->m_modelName);
  this->m_frame.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "frame",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_frame);
  this->m_rendermode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "rendermode",
                                      type: AT_INT,
                                      pMemory: &this->m_rendermode);
  this->m_renderfx.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "renderfx",
                                    type: AT_INT,
                                    pMemory: &this->m_renderfx);
  this->m_renderscale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "renderscale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_renderscale);
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  this->m_proxyRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "proxyRadius",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_proxyRadius);
}

//------------------------------------------------------------------------------
// Address: 0x00521060
// Name: protected: void CDmeGamePortal::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::OnConstruction(CDmeGamePortal *this)
{
  this->m_flStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "staticAmount",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flStaticAmount);
  this->m_flSecondaryStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "secondaryStaticAmount",
                                                   type: AT_FLOAT,
                                                   pMemory: &this->m_flSecondaryStaticAmount);
  this->m_flOpenAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "openAmount",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flOpenAmount);
  this->m_flHalfWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "halfWidth",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flHalfWidth);
  this->m_flHalfHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "halfHeight",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flHalfHeight);
  this->m_nPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "portalId",
                                     type: AT_INT,
                                     pMemory: &this->m_nPortalId);
  this->m_nLinkedPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "linkedPortalId",
                                           type: AT_INT,
                                           pMemory: &this->m_nLinkedPortalId);
  this->m_bIsPortal2.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isPortal2",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsPortal2);
  this->m_PortalType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "portalType",
                                      type: AT_STRING,
                                      pMemory: &this->m_PortalType);
}

//------------------------------------------------------------------------------
// Address: 0x00521140
// Name: protected: void CDmeGlobalFlexControllerOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_flexWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "flexWeight",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flexWeight);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_gameModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "gameModel",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_gameModel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_gameModel.m_pAttribute, typeSymbol: CDmeGameModel::m_classType);
  this->m_gameModel.m_pAttribute->m_nFlags |= 0x1100u;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_nFlexControllerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x005211B0
// Name: protected: void CDmeGameModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnConstruction(CDmeGameModel *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_flexWeights,
    pOwner: this,
    pAttributeName: "flexWeights",
    nFlags: 0);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "modelName", type: AT_STRING, pMemory: &this->m_modelName);
  this->m_modelName.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  this->m_skin.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "skin",
                                type: AT_INT,
                                pMemory: &this->m_skin);
  this->m_body.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "body",
                                type: AT_INT,
                                pMemory: &this->m_body);
  this->m_sequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "sequence",
                                    type: AT_INT,
                                    pMemory: &this->m_sequence);
  this->m_flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_flags);
  this->m_bones.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "bones",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_bones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_bones.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  this->m_globalFlexControllers.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "globalFlexControllers",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_globalFlexControllers);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_globalFlexControllers.m_pAttribute,
    typeSymbol: CDmeGlobalFlexControllerOperator::m_classType);
  this->m_bComputeBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "computeBounds",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bComputeBounds);
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "evaluateProceduralBones",
         type: AT_BOOL,
         pMemory: &this->m_bEvaluateProceduralBones);
  this->m_bEvaluateProceduralBones.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_hMDL = -1;
  this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x005213E0
// Name: public: bool CDmeGameModel::GetBoneDefaultOrientation(int,class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeGameModel::GetBoneDefaultOrientation(CDmeGameModel *this, int nBoneIndex, Quaternion *orientation)
{
  const char *m_pAsString; // eax
  unsigned __int16 v4; // ax
  studiohdr_t *v5; // eax
  char *v6; // ecx

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    return 0;
  if ( m_pAsString == nullptr )
    return 0;
  if ( *m_pAsString == 0 )
    return 0;
  v4 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( v4 == 0xFFFF )
    return 0;
  v5 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v4);
  if ( v5 == nullptr )
    return 0;
  if ( nBoneIndex < 0 )
    return 0;
  if ( nBoneIndex >= v5->numbones )
    return 0;
  v6 = (char *)v5 + 216 * nBoneIndex + v5->boneindex;
  if ( v6 == nullptr )
    return 0;
  *orientation = *(Quaternion *)(v6 + 44);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00521470
// Name: public: int CDmeGameModel::NumGlobalFlexControllers(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::NumGlobalFlexControllers(CDmeGameModel *this)
{
  return this->m_globalFlexControllers.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00521480
// Name: public: unsigned int CDmeGameModel::NumBones(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::NumBones(CDmeGameModel *this)
{
  return this->m_bones.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005214F0
// Name: private: int CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(void)const
// Source: json
//------------------------------------------------------------------------------
DmAttributeHandle_t __thiscall CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(
        CDmeGlobalFlexControllerOperator *this)
{
  CDmeGameModel *v1; // eax
  CDmeGameModel *v2; // esi
  int m_hMDL; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // edi
  int j; // ebx
  char *v7; // esi
  const char *m_pAsString; // ecx
  DmAttributeHandle_t v10; // edi
  CDmeGameModel *v11; // eax
  int fc; // [esp+8h] [ebp-Ch]
  LocalFlexController_t i; // [esp+10h] [ebp-4h]

  v1 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  v2 = v1;
  if ( v1->m_bHMDLDirty )
    CDmeGameModel::UpdateHMDL(this: v1);
  m_hMDL = v2->m_hMDL;
  if ( (_WORD)m_hMDL == 0xFFFF )
    return DMATTRIBUTE_HANDLE_INVALID;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: m_hMDL);
  v5 = v4;
  if ( v4 == nullptr )
    return DMATTRIBUTE_HANDLE_INVALID;
  fc = v4->numflexcontrollers;
  i = DUMMY_NULL_FLEX_CONTROLLER;
  if ( fc <= 0 )
    return DMATTRIBUTE_HANDLE_INVALID;
  for ( j = 0; ; j += 20 )
  {
    v7 = (char *)v5 + j + v5->flexcontrollerindex;
    if ( *((_DWORD *)v7 + 2) == -1 && g_pGlobalFlexController != nullptr )
      *((_DWORD *)v7 + 2) = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v7[*((_DWORD *)v7 + 1)]);
    m_pAsString = &pch;
    if ( this->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
      m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( _V_stricmp(s1: &v7[*((_DWORD *)v7 + 1)], s2: m_pAsString) == 0 )
      break;
    if ( ++i >= fc )
      return DMATTRIBUTE_HANDLE_INVALID;
  }
  v10 = *((_DWORD *)v7 + 2);
  if ( (unsigned int)v10 >= g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle)[2].m_ref.m_attributes.m_hAttribute )
  {
    v11 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
    CDmeGameModel::SetNumFlexWeights(this: v11, nFlexWeights: *((_DWORD *)v7 + 2) + 1);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00521630
// Name: public: class CDmeGlobalFlexControllerOperator __near * CDmeGameModel::AddGlobalFlexController(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CDmeGlobalFlexControllerOperator *__thiscall CDmeGameModel::AddGlobalFlexController(
        CDmeGameModel *this,
        const char *controllerName,
        DmAttributeHandle_t globalIndex)
{
  int v3; // edi
  CDmaElementArray<CDmeGlobalFlexControllerOperator> *p_m_globalFlexControllers; // ebx
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  const char *m_pAsString; // eax
  DmElementHandle_t v8; // eax
  CDmElement *v9; // eax
  CDmElement *v10; // esi
  char *v11; // esi
  CDmElement *v13; // eax
  DmAttributeHandle_t v14; // edi
  CDmElement *v15; // esi
  char *v16; // ebx
  DmElementHandle_t v17; // eax
  CDmeGameModel *v18; // eax
  const char *v19; // eax
  CDmAttribute *v20; // ecx
  unsigned int m_Size; // eax
  unsigned __int32 v22; // esi
  int c; // [esp+Ch] [ebp-8h]
  CDmeGameModel *v24; // [esp+10h] [ebp-4h]

  v3 = 0;
  v24 = this;
  c = this->m_globalFlexControllers.m_Storage.m_Size;
  if ( c > 0 )
  {
    p_m_globalFlexControllers = &this->m_globalFlexControllers;
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_globalFlexControllers->m_Storage.m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr
        && v5->IsA(this: v5, a2: CDmeGlobalFlexControllerOperator::m_classType)
        && v6 != (CDmElement *)4 )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &pch;
        if ( _V_stricmp(s1: m_pAsString, s2: controllerName) == 0 )
          break;
      }
      if ( ++v3 >= c )
        goto LABEL_12;
    }
    if ( v3 < c )
      goto LABEL_18;
LABEL_12:
    this = v24;
  }
  v8 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeGlobalFlexControllerOperator::m_classType.u.m_Id,
         a3: controllerName,
         a4: this->m_fileId,
         a5: nullptr);
  v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8);
  v10 = v9;
  if ( v9 == nullptr )
    return nullptr;
  if ( !v9->IsA(this: v9, a2: CDmeGlobalFlexControllerOperator::m_classType) )
    return nullptr;
  v11 = (char *)&v10[-1] + 64;
  if ( v11 == nullptr )
    return nullptr;
  p_m_globalFlexControllers = &v24->m_globalFlexControllers;
  controllerName = (const char *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(v11 + 4));
  v3 = CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
         this: &v24->m_globalFlexControllers,
         src: (const DmElementHandle_t *)&controllerName);
LABEL_18:
  v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_globalFlexControllers->m_Storage.m_Memory.m_pMemory[v3]);
  v14 = globalIndex;
  v15 = v13;
  if ( v13 != nullptr && v13->IsA(this: v13, a2: CDmeGlobalFlexControllerOperator::m_classType) )
  {
    v16 = (char *)&v15[-1] + 64;
    if ( v15 != (CDmElement *)4 )
    {
      v17 = *((_DWORD *)v16 + 21);
      *((_DWORD *)v16 + 25) = v14;
      if ( g_pDataModel->GetElement(this: g_pDataModel, a2: v17) != nullptr
        && (unsigned int)v14 >= g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v16 + 21))[2].m_ref.m_attributes.m_hAttribute )
      {
        v18 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v16 + 21));
        CDmeGameModel::SetNumFlexWeights(this: v18, nFlexWeights: v14 + 1);
      }
      v19 = (const char *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v24);
      v20 = *((CDmAttribute **)v16 + 23);
      controllerName = v19;
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: v20, value: (DmElementHandle_t *)&controllerName);
    }
  }
  else
  {
    v16 = nullptr;
  }
  m_Size = v24->m_flexWeights.m_Storage.m_Size;
  if ( v14 < m_Size )
    return (CDmeGlobalFlexControllerOperator *)v16;
  v22 = v14 + 1;
  if ( m_Size >= v14 + 1 )
  {
    if ( m_Size > v14 + 1 )
    {
      do
      {
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
          this: &v24->m_flexWeights,
          elem: m_Size - 1);
        m_Size = v24->m_flexWeights.m_Storage.m_Size;
      }
      while ( m_Size > v22 );
    }
    return (CDmeGlobalFlexControllerOperator *)v16;
  }
  do
  {
    controllerName = nullptr;
    CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
      this: &v24->m_flexWeights,
      src: (const float *)&controllerName);
  }
  while ( v24->m_flexWeights.m_Storage.m_Size < v22 );
  return (CDmeGlobalFlexControllerOperator *)v16;
}

//------------------------------------------------------------------------------
// Address: 0x00521860
// Name: public: class CDmeGlobalFlexControllerOperator __near * CDmeGameModel::FindGlobalFlexController(int)
// Source: json
//------------------------------------------------------------------------------
CDmeGlobalFlexControllerOperator *__thiscall CDmeGameModel::FindGlobalFlexController(
        CDmeGameModel *this,
        int nGlobalIndex)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmeGlobalFlexControllerOperator *result; // eax
  int c; // [esp+Ch] [ebp-4h]

  v3 = 0;
  c = this->m_globalFlexControllers.m_Storage.m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(
           this: g_pDataModel,
           a2: this->m_globalFlexControllers.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeGlobalFlexControllerOperator::m_classType) )
    {
      result = (CDmeGlobalFlexControllerOperator *)((char *)&v5[-1] + 64);
      if ( v5 != (CDmElement *)4 && result->m_nFlexControllerIndex == nGlobalIndex )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005218E0
// Name: public: class CDmeGlobalFlexControllerOperator __near * CDmeGameModel::GetGlobalFlexController(int)
// Source: json
//------------------------------------------------------------------------------
CDmeGlobalFlexControllerOperator *__thiscall CDmeGameModel::GetGlobalFlexController(
        CDmeGameModel *this,
        int localIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(
         this: g_pDataModel,
         a2: this->m_globalFlexControllers.m_Storage.m_Memory.m_pMemory[localIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeGlobalFlexControllerOperator::m_classType) )
    return (CDmeGlobalFlexControllerOperator *)((char *)&v3[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00521930
// Name: public: void CDmeGameModel::RemoveGlobalFlexController(class CDmeGlobalFlexControllerOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::RemoveGlobalFlexController(
        CDmeGameModel *this,
        CDmeGlobalFlexControllerOperator *controller)
{
  int v2; // edi
  CDmaElementArray<CDmeGlobalFlexControllerOperator> *p_m_globalFlexControllers; // ebx
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmeGlobalFlexControllerOperator *v6; // eax
  int c; // [esp+Ch] [ebp-4h]

  v2 = 0;
  c = this->m_globalFlexControllers.m_Storage.m_Size;
  if ( c > 0 )
  {
    p_m_globalFlexControllers = &this->m_globalFlexControllers;
    while ( 1 )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_globalFlexControllers->m_Storage.m_Memory.m_pMemory[v2]);
      v5 = v4;
      if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeGlobalFlexControllerOperator::m_classType) )
        v6 = (CDmeGlobalFlexControllerOperator *)((char *)&v5[-1] + 64);
      else
        v6 = nullptr;
      if ( v6 == controller )
        break;
      if ( ++v2 >= c )
        return;
    }
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
      this: p_m_globalFlexControllers,
      elem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005219B0
// Name: public: class CDmeTransform __near * CDmeGameModel::GetBone(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeGameModel::GetBone(CDmeGameModel *this, unsigned int index)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_bones.m_Storage.m_Memory.m_pMemory[index]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00521A00
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Resolve(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  if ( this->m_ToAttributeHandle < 0 )
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  if ( this->m_gameModel.m_pAttribute == (CDmAttribute *)-1 )
  {
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute);
    if ( v2 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
      if ( Attribute != nullptr )
        this->m_gameModel.m_pAttribute = (CDmAttribute *)CDmAttribute::GetHandle(this: Attribute, bCreate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00521A50
// Name: public: virtual void CDmeGlobalFlexControllerOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnAttributeChanged(
        CDmeGlobalFlexControllerOperator *this,
        CDmAttribute *pAttribute)
{
  if ( g_pGlobalFlexController != nullptr
    && pAttribute == (CDmAttribute *)this->m_gameModel.m_Storage.m_ElementType.u.m_Id
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute) != nullptr )
  {
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
    CDmeGlobalFlexControllerOperator::SetupToAttribute(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x00521AA0
// Name: protected: void CDmeGameModel::PopulateExistingDagList(class CDmeDag __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PopulateExistingDagList(CDmeGameModel *this, CDmeDag **pDags, int nCount)
{
  int v4; // edi
  CDmElement *v5; // eax
  CDmeTransform *v6; // esi
  CDmeDag *Dag; // eax
  int nCurrentBoneCount; // [esp+Ch] [ebp-4h]

  v4 = 0;
  for ( nCurrentBoneCount = this->m_bones.m_Storage.m_Size; v4 < nCount; ++v4 )
  {
    if ( v4 < nCurrentBoneCount )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_bones.m_Storage.m_Memory.m_pMemory[v4]);
      v6 = (CDmeTransform *)v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransform::m_classType) )
        Dag = CDmeTransform::GetDag(this: v6);
      else
        Dag = nullptr;
      pDags[v4] = Dag;
    }
    else
    {
      pDags[v4] = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00521B30
// Name: public: void CDmeGameModel::AddBones(struct studiohdr_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::AddBones(CDmeGameModel *this, studiohdr_t *pStudioHdr, int nFirstBone, int nCount)
{
  int numbones; // eax
  int v5; // esi
  void *v6; // esp
  int v7; // edi
  int v8; // ebx
  const char *v9; // eax
  int v10; // ecx
  DmElementHandle_t v11; // eax
  CDmElement *v12; // eax
  CDmeDag *v13; // esi
  CDmeTransform *Transform; // esi
  CDmeDag *v15[3]; // [esp+0h] [ebp-124h] BYREF
  char name[256]; // [esp+Ch] [ebp-118h] BYREF
  DmElementHandle_t src; // [esp+10Ch] [ebp-18h] BYREF
  CUtlSymbolLarge value; // [esp+110h] [ebp-14h] BYREF
  CDmeDag **pDags; // [esp+114h] [ebp-10h]
  CDmeDag *pParent; // [esp+118h] [ebp-Ch]
  CDmeDag **v21; // [esp+11Ch] [ebp-8h]
  CDmeGameModel *v22; // [esp+120h] [ebp-4h]

  numbones = pStudioHdr->numbones;
  v5 = nFirstBone;
  v22 = this;
  if ( nFirstBone + nCount <= numbones || (nCount = numbones - nFirstBone, numbones - nFirstBone > 0) )
  {
    v6 = alloca(4 * numbones);
    pDags = v15;
    CDmeGameModel::PopulateExistingDagList(this, pDags: v15, nCount: nFirstBone);
    v7 = 0;
    if ( nCount > 0 )
    {
      v8 = 216 * nFirstBone;
      v21 = &pDags[nFirstBone];
      while ( 1 )
      {
        v9 = (char *)pStudioHdr + v8 + pStudioHdr->boneindex;
        v10 = *((_DWORD *)v9 + 1);
        pParent = v10 >= 0 ? pDags[v10] : v22;
        V_snprintf(pDest: name, maxLen: 256, pFormat: "bone %d (%s)", v7 + v5, &v9[*(_DWORD *)v9]);
        v11 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
                a1: g_pDataModel,
                a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id,
                a3: name,
                a4: v22->m_fileId,
                a5: nullptr);
        v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: v11);
        v13 = (CDmeDag *)v12;
        if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmeDag::m_classType) )
          v13 = nullptr;
        *v21 = v13;
        CDmeDag::AddChild(this: pParent, pDag: v13);
        Transform = CDmeDag::GetTransform(this: v13);
        g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: name);
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: Transform->m_Name.m_pAttribute, &value);
        src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)Transform);
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &v22->m_bones,
          &src);
        ++v21;
        ++v7;
        v8 += 216;
        if ( v7 >= nCount )
          break;
        v5 = nFirstBone;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00521CC0
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x00521CF0
// Name: public: int CDmeGameModel::FindAttachment(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::FindAttachment(CDmeGameModel *this, const char *pchAttachmentName)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // ax
  const studiohdr_t *v4; // eax
  int Attachment; // esi
  CStudioHdr studioHdr; // [esp+0h] [ebp-64h] BYREF

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    return 0;
  if ( m_pAsString == nullptr )
    return 0;
  if ( *m_pAsString == 0 )
    return 0;
  v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( v3 == 0xFFFF )
    return 0;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v3);
  if ( v4 == nullptr )
    return 0;
  CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v4, mdlcache: nullptr);
  Attachment = Studio_FindAttachment(pStudioHdr: &studioHdr, pAttachmentName: pchAttachmentName);
  CStudioHdr::Term(this: &studioHdr);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&studioHdr.m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&studioHdr.m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&studioHdr.m_pStudioHdrCache);
  return Attachment + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00521D90
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *v2; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v6 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00521EC0
// Name: public: virtual bool CDmeGlobalFlexControllerOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGlobalFlexControllerOperator::IsA(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00521EF0
// Name: public: virtual int CDmeGlobalFlexControllerOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGlobalFlexControllerOperator::GetInheritanceDepth(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00521FD0
// Name: protected: virtual void CDmeGlobalFlexControllerOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::PerformConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  CDmeGlobalFlexControllerOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00522110
// Name: protected: CDmeGameModel::CDmeGameModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CDmeGameModel::CDmeGameModel(
        CDmeGameModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeGameModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_globalFlexControllers);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_flexWeights);
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_skin.m_pAttribute = nullptr;
  this->m_skin.m_Storage = 0;
  this->m_body.m_pAttribute = nullptr;
  this->m_body.m_Storage = 0;
  this->m_sequence.m_pAttribute = nullptr;
  this->m_sequence.m_Storage = 0;
  this->m_flags.m_pAttribute = nullptr;
  this->m_flags.m_Storage = 0;
  this->m_bComputeBounds.m_pAttribute = nullptr;
  this->m_bComputeBounds.m_Storage = false;
  this->m_bEvaluateProceduralBones.m_pAttribute = nullptr;
  this->m_bEvaluateProceduralBones.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_bones);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005221F0
// Name: public: virtual bool CDmeGameModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameModel::IsA(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522220
// Name: public: virtual int CDmeGameModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::GetInheritanceDepth(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522270
// Name: protected: virtual void CDmeGameModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformDestruction(CDmeGameModel *this)
{
  int m_hMDL; // eax

  m_hMDL = this->m_hMDL;
  if ( (_WORD)m_hMDL != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: m_hMDL);
    this->m_hMDL = -1;
  }
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005222B0
// Name: protected: virtual int CDmeGameModel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::AllocatedSize(CDmeGameModel *this)
{
  return 276;
}

//------------------------------------------------------------------------------
// Address: 0x005222C0
// Name: protected: virtual void CDmeGameModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformConstruction(CDmeGameModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00522340
// Name: protected: CDmeGameSprite::CDmeGameSprite(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSprite *__thiscall CDmeGameSprite::CDmeGameSprite(
        CDmeGameSprite *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeGameSprite::`vftable';
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_frame.m_pAttribute = nullptr;
  this->m_frame.m_Storage = 0.0;
  this->m_rendermode.m_pAttribute = nullptr;
  this->m_rendermode.m_Storage = 0;
  this->m_renderfx.m_pAttribute = nullptr;
  this->m_renderfx.m_Storage = 0;
  this->m_renderscale.m_pAttribute = nullptr;
  this->m_renderscale.m_Storage = 0.0;
  this->m_color.m_pAttribute = nullptr;
  this->m_color.m_Storage = (Color)-16777216;
  this->m_proxyRadius.m_pAttribute = nullptr;
  this->m_proxyRadius.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00522410
// Name: public: virtual bool CDmeGameSprite::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSprite::IsA(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522440
// Name: public: virtual int CDmeGameSprite::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::GetInheritanceDepth(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522490
// Name: protected: virtual int CDmeGameSprite::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::AllocatedSize(CDmeVertexDeltaData *this)
{
  return 192;
}

//------------------------------------------------------------------------------
// Address: 0x005224A0
// Name: protected: virtual void CDmeGameSprite::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::PerformConstruction(CDmeGameSprite *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameSprite::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00522500
// Name: protected: CDmeGamePortal::CDmeGamePortal(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGamePortal *__thiscall CDmeGamePortal::CDmeGamePortal(
        CDmeGamePortal *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeGamePortal::`vftable';
  this->m_nPortalId.m_pAttribute = nullptr;
  this->m_nPortalId.m_Storage = 0;
  this->m_nLinkedPortalId.m_pAttribute = nullptr;
  this->m_nLinkedPortalId.m_Storage = 0;
  this->m_flStaticAmount.m_pAttribute = nullptr;
  this->m_flStaticAmount.m_Storage = 0.0;
  this->m_flSecondaryStaticAmount.m_pAttribute = nullptr;
  this->m_flSecondaryStaticAmount.m_Storage = 0.0;
  this->m_flOpenAmount.m_pAttribute = nullptr;
  this->m_flOpenAmount.m_Storage = 0.0;
  this->m_flHalfWidth.m_pAttribute = nullptr;
  this->m_flHalfWidth.m_Storage = 0.0;
  this->m_flHalfHeight.m_pAttribute = nullptr;
  this->m_flHalfHeight.m_Storage = 0.0;
  this->m_bIsPortal2.m_pAttribute = nullptr;
  this->m_bIsPortal2.m_Storage = false;
  this->m_PortalType.m_Storage.u.m_Id = -1;
  this->m_PortalType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005225E0
// Name: public: virtual bool CDmeGamePortal::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGamePortal::IsA(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522610
// Name: public: virtual int CDmeGamePortal::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::GetInheritanceDepth(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522660
// Name: protected: virtual void CDmeGamePortal::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::PerformConstruction(CDmeGamePortal *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGamePortal::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057DF90
// Name: _dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGlobalFlexControllerOperator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGlobalFlexControllerOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DFF0
// Name: _dynamic_initializer_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameModel::s_Allocator,
    blockSize: 276,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E050
// Name: _dynamic_initializer_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSprite::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSprite pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E0B0
// Name: _dynamic_initializer_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGamePortal::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGamePortal pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580CF0
// Name: _dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGlobalFlexControllerOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580D00
// Name: _dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580D10
// Name: _dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSprite::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580D20
// Name: _dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGamePortal::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DFC0
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DFD0
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGlobalFlexControllerOperator_Helper,
           classname: "DmeGlobalFlexControllerOperator",
           pFactory: &g_CDmeGlobalFlexControllerOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E020
// Name: _dynamic_initializer_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E030
// Name: _dynamic_initializer_for__g_CDmeGameModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameModel_Helper,
           classname: "DmeGameModel",
           pFactory: &g_CDmeGameModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E080
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSprite_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E090
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSprite_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSprite_Helper,
           classname: "DmeGameSprite",
           pFactory: &g_CDmeGameSprite_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E0E0
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGamePortal_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E0F0
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGamePortal_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGamePortal_Helper,
           classname: "DmeGamePortal",
           pFactory: &g_CDmeGamePortal_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580D30
// Name: _dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580D40
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSprite_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580D50
// Name: _dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGamePortal_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580D60
// Name: _dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGlobalFlexControllerOperator_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005AD670
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Operate(CDmeGlobalFlexControllerOperator *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // edx
  void *m_pData; // ebx
  DmAttributeType_t v5; // esi
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v2 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_pAttribute = this->m_flexWeight.m_pAttribute;
    m_pData = m_pAttribute->m_pData;
    v5 = m_pAttribute->m_nFlags & 0x1F;
    if ( (v2->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v2, valueType: v5, pValue: m_pData);
    }
    else if ( this->m_nFlexControllerIndex != -1 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v2);
      CDmrGenericArray::Set(this: &array, i: this->m_nFlexControllerIndex, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AD6F0
// Name: public: void CDmeGlobalFlexControllerOperator::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::SetupToAttribute(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_gameModel.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
    if ( Attribute != nullptr )
      this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: Attribute, bCreate: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AD730
// Name: public: virtual void CDmeGameModel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnAttributeChanged(CDmeGameModel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_modelName.m_pAttribute )
    this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x005AD750
// Name: protected: void CDmeGameModel::UpdateHMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::UpdateHMDL(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // di

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  v3 = -1;
  if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
    v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( this->m_hMDL != 0xFFFF )
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_hMDL);
  this->m_hMDL = v3;
  this->m_bHMDLDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x005AD7B0
// Name: protected: void CDmeGameSprite::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::OnConstruction(CDmeGameSprite *this)
{
  this->m_modelName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "modelName",
                                     type: AT_STRING,
                                     pMemory: &this->m_modelName);
  this->m_frame.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "frame",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_frame);
  this->m_rendermode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "rendermode",
                                      type: AT_INT,
                                      pMemory: &this->m_rendermode);
  this->m_renderfx.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "renderfx",
                                    type: AT_INT,
                                    pMemory: &this->m_renderfx);
  this->m_renderscale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "renderscale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_renderscale);
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  this->m_proxyRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "proxyRadius",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_proxyRadius);
}

//------------------------------------------------------------------------------
// Address: 0x005AD860
// Name: protected: void CDmeGamePortal::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::OnConstruction(CDmeGamePortal *this)
{
  this->m_flStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "staticAmount",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flStaticAmount);
  this->m_flSecondaryStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "secondaryStaticAmount",
                                                   type: AT_FLOAT,
                                                   pMemory: &this->m_flSecondaryStaticAmount);
  this->m_flOpenAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "openAmount",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flOpenAmount);
  this->m_flHalfWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "halfWidth",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flHalfWidth);
  this->m_flHalfHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "halfHeight",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flHalfHeight);
  this->m_nPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "portalId",
                                     type: AT_INT,
                                     pMemory: &this->m_nPortalId);
  this->m_nLinkedPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "linkedPortalId",
                                           type: AT_INT,
                                           pMemory: &this->m_nLinkedPortalId);
  this->m_bIsPortal2.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isPortal2",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsPortal2);
  this->m_PortalType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "portalType",
                                      type: AT_STRING,
                                      pMemory: &this->m_PortalType);
}

//------------------------------------------------------------------------------
// Address: 0x005AD940
// Name: protected: void CDmeGlobalFlexControllerOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_flexWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "flexWeight",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flexWeight);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_gameModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "gameModel",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_gameModel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_gameModel.m_pAttribute, typeSymbol: CDmeGameModel::m_classType);
  this->m_gameModel.m_pAttribute->m_nFlags |= 0x1100u;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_nFlexControllerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD9B0
// Name: protected: void CDmeGameModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnConstruction(CDmeGameModel *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_flexWeights,
    pOwner: this,
    pAttributeName: "flexWeights",
    nFlags: 0);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "modelName", type: AT_STRING, pMemory: &this->m_modelName);
  this->m_modelName.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  this->m_skin.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "skin",
                                type: AT_INT,
                                pMemory: &this->m_skin);
  this->m_body.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "body",
                                type: AT_INT,
                                pMemory: &this->m_body);
  this->m_sequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "sequence",
                                    type: AT_INT,
                                    pMemory: &this->m_sequence);
  this->m_flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_flags);
  this->m_bones.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "bones",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_bones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_bones.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  this->m_globalFlexControllers.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "globalFlexControllers",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_globalFlexControllers);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_globalFlexControllers.m_pAttribute,
    typeSymbol: CDmeGlobalFlexControllerOperator::m_classType);
  this->m_bComputeBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "computeBounds",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bComputeBounds);
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "evaluateProceduralBones",
         type: AT_BOOL,
         pMemory: &this->m_bEvaluateProceduralBones);
  this->m_bEvaluateProceduralBones.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_hMDL = -1;
  this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x005ADCA0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Resolve(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  if ( this->m_ToAttributeHandle < 0 )
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  if ( this->m_gameModel.m_pAttribute == (CDmAttribute *)-1 )
  {
    v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_flexWeight.m_pAttribute);
    if ( v2 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
      if ( Attribute != nullptr )
        this->m_gameModel.m_pAttribute = (CDmAttribute *)CDmAttribute::GetHandle(this: Attribute, bCreate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005ADCF0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnAttributeChanged(
        CDmeGlobalFlexControllerOperator *this,
        CDmAttribute *pAttribute)
{
  if ( g_pGlobalFlexController != nullptr
    && pAttribute == (CDmAttribute *)this->m_gameModel.m_Storage.m_ElementType.u.m_Id
    && (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_flexWeight.m_pAttribute) != 0 )
  {
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
    CDmeGlobalFlexControllerOperator::SetupToAttribute(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x005ADD40
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int v2; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 336))(
         a1: g_pDataModel.u,
         a2: this->m_ToAttributeHandle);
  if ( v2 != 0 )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v5 = (CDmAttribute **)attrs->m_pMemory;
    v6 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &v5[m_pMemory + 1], src: &v5[m_pMemory], count: 4 * v6);
    v7 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (CDmAttribute *)v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005ADE70
// Name: public: virtual bool CDmeGlobalFlexControllerOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGlobalFlexControllerOperator::IsA(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005ADEA0
// Name: public: virtual int CDmeGlobalFlexControllerOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGlobalFlexControllerOperator::GetInheritanceDepth(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005ADF70
// Name: protected: virtual void CDmeGlobalFlexControllerOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::PerformConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  CDmeGlobalFlexControllerOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005AE0B0
// Name: protected: CDmeGameModel::CDmeGameModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CDmeGameModel::CDmeGameModel(
        CDmeGameModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeGameModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_globalFlexControllers);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_flexWeights);
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_skin.m_pAttribute = nullptr;
  this->m_skin.m_Storage = 0;
  this->m_body.m_pAttribute = nullptr;
  this->m_body.m_Storage = 0;
  this->m_sequence.m_pAttribute = nullptr;
  this->m_sequence.m_Storage = 0;
  this->m_flags.m_pAttribute = nullptr;
  this->m_flags.m_Storage = 0;
  this->m_bComputeBounds.m_pAttribute = nullptr;
  this->m_bComputeBounds.m_Storage = false;
  this->m_bEvaluateProceduralBones.m_pAttribute = nullptr;
  this->m_bEvaluateProceduralBones.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_bones);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AE190
// Name: public: virtual bool CDmeGameModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameModel::IsA(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE1C0
// Name: public: virtual int CDmeGameModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::GetInheritanceDepth(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE210
// Name: protected: virtual void CDmeGameModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformDestruction(CDmeGameModel *this)
{
  int m_hMDL; // eax

  m_hMDL = this->m_hMDL;
  if ( (_WORD)m_hMDL != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: m_hMDL);
    this->m_hMDL = -1;
  }
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005AE250
// Name: protected: virtual int CDmeGameModel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::AllocatedSize(CDmeGameModel *this)
{
  return 276;
}

//------------------------------------------------------------------------------
// Address: 0x005AE260
// Name: protected: virtual void CDmeGameModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformConstruction(CDmeGameModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AE2E0
// Name: protected: CDmeGameSprite::CDmeGameSprite(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSprite *__thiscall CDmeGameSprite::CDmeGameSprite(
        CDmeGameSprite *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeGameSprite::`vftable';
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_frame.m_pAttribute = nullptr;
  this->m_frame.m_Storage = 0.0;
  this->m_rendermode.m_pAttribute = nullptr;
  this->m_rendermode.m_Storage = 0;
  this->m_renderfx.m_pAttribute = nullptr;
  this->m_renderfx.m_Storage = 0;
  this->m_renderscale.m_pAttribute = nullptr;
  this->m_renderscale.m_Storage = 0.0;
  this->m_color.m_pAttribute = nullptr;
  this->m_color.m_Storage = (Color)-16777216;
  this->m_proxyRadius.m_pAttribute = nullptr;
  this->m_proxyRadius.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AE3B0
// Name: public: virtual bool CDmeGameSprite::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSprite::IsA(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE3E0
// Name: public: virtual int CDmeGameSprite::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::GetInheritanceDepth(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE430
// Name: protected: virtual int CDmeGameSprite::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::AllocatedSize(CDmeVertexDeltaData *this)
{
  return 192;
}

//------------------------------------------------------------------------------
// Address: 0x005AE440
// Name: protected: virtual void CDmeGameSprite::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::PerformConstruction(CDmeGameSprite *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGameSprite::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AE4A0
// Name: protected: CDmeGamePortal::CDmeGamePortal(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGamePortal *__thiscall CDmeGamePortal::CDmeGamePortal(
        CDmeGamePortal *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeGamePortal::`vftable';
  this->m_nPortalId.m_pAttribute = nullptr;
  this->m_nPortalId.m_Storage = 0;
  this->m_nLinkedPortalId.m_pAttribute = nullptr;
  this->m_nLinkedPortalId.m_Storage = 0;
  this->m_flStaticAmount.m_pAttribute = nullptr;
  this->m_flStaticAmount.m_Storage = 0.0;
  this->m_flSecondaryStaticAmount.m_pAttribute = nullptr;
  this->m_flSecondaryStaticAmount.m_Storage = 0.0;
  this->m_flOpenAmount.m_pAttribute = nullptr;
  this->m_flOpenAmount.m_Storage = 0.0;
  this->m_flHalfWidth.m_pAttribute = nullptr;
  this->m_flHalfWidth.m_Storage = 0.0;
  this->m_flHalfHeight.m_pAttribute = nullptr;
  this->m_flHalfHeight.m_Storage = 0.0;
  this->m_bIsPortal2.m_pAttribute = nullptr;
  this->m_bIsPortal2.m_Storage = false;
  this->m_PortalType.m_Storage.u.m_Id = -1;
  this->m_PortalType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AE580
// Name: public: virtual bool CDmeGamePortal::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGamePortal::IsA(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE5B0
// Name: public: virtual int CDmeGamePortal::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::GetInheritanceDepth(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE600
// Name: protected: virtual int CDmeGamePortal::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::AllocatedSize(CDmeGamePortal *this)
{
  return 208;
}

//------------------------------------------------------------------------------
// Address: 0x005AE610
// Name: protected: virtual void CDmeGamePortal::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::PerformConstruction(CDmeGamePortal *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeGamePortal::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EB200
// Name: _dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGlobalFlexControllerOperator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGlobalFlexControllerOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB260
// Name: _dynamic_initializer_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameModel::s_Allocator,
    blockSize: 276,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB2C0
// Name: _dynamic_initializer_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSprite::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSprite pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB320
// Name: _dynamic_initializer_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGamePortal::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGamePortal pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDBD0
// Name: _dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGlobalFlexControllerOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDBE0
// Name: _dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDBF0
// Name: _dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSprite::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDC00
// Name: _dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGamePortal::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EB230
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB240
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGlobalFlexControllerOperator_Helper,
           classname: "DmeGlobalFlexControllerOperator",
           pFactory: &g_CDmeGlobalFlexControllerOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EB290
// Name: _dynamic_initializer_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB2A0
// Name: _dynamic_initializer_for__g_CDmeGameModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameModel_Helper,
           classname: "DmeGameModel",
           pFactory: &g_CDmeGameModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EB2F0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSprite_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB300
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSprite_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSprite_Helper,
           classname: "DmeGameSprite",
           pFactory: &g_CDmeGameSprite_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EB350
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGamePortal_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB360
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGamePortal_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGamePortal_Helper,
           classname: "DmeGamePortal",
           pFactory: &g_CDmeGamePortal_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EB380
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB3A0
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005EB3B0
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB3C0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EB420
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EB450
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB470
// Name: _dynamic_initializer_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_static_p4_factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_static_p4_factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDC10
// Name: _dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EDC20
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSprite_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EDC30
// Name: _dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGamePortal_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EDC40
// Name: _dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGlobalFlexControllerOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EDC50
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDC60
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005EDCA0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x005EDCF0
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0047E320
// Name: protected: virtual int CDmeGameSprite::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::AllocatedSize(CDmeVertexDeltaData *this)
{
  return 192;
}

//------------------------------------------------------------------------------
// Address: 0x005288F0
// Name: protected: virtual int CDmeGamePortal::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::AllocatedSize(CDmeSpotLight *this)
{
  return 208;
}

//------------------------------------------------------------------------------
// Address: 0x00528C00
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Operate(CDmeGlobalFlexControllerOperator *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // edx
  void *m_pData; // ebx
  DmAttributeType_t v5; // esi
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_pAttribute = this->m_flexWeight.m_pAttribute;
    m_pData = m_pAttribute->m_pData;
    v5 = m_pAttribute->m_nFlags & 0x1F;
    if ( (v2->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v2, valueType: v5, pValue: m_pData);
    }
    else if ( this->m_nFlexControllerIndex != -1 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v2);
      CDmrGenericArray::Set(this: &array, i: this->m_nFlexControllerIndex, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00528C80
// Name: public: void CDmeGlobalFlexControllerOperator::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::SetupToAttribute(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
    if ( Attribute != nullptr )
      this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: Attribute, bCreate: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00528CC0
// Name: public: virtual void CDmeGameModel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnAttributeChanged(CDmeGameModel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_modelName.m_pAttribute )
    this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x00528CE0
// Name: protected: void CDmeGameModel::UpdateHMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::UpdateHMDL(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // di

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  v3 = -1;
  if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
    v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( this->m_hMDL != 0xFFFF )
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_hMDL);
  this->m_hMDL = v3;
  this->m_bHMDLDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00528D40
// Name: protected: void CDmeGameSprite::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::OnConstruction(CDmeGameSprite *this)
{
  this->m_modelName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "modelName",
                                     type: AT_STRING,
                                     pMemory: &this->m_modelName);
  this->m_frame.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "frame",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_frame);
  this->m_rendermode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "rendermode",
                                      type: AT_INT,
                                      pMemory: &this->m_rendermode);
  this->m_renderfx.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "renderfx",
                                    type: AT_INT,
                                    pMemory: &this->m_renderfx);
  this->m_renderscale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "renderscale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_renderscale);
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  this->m_proxyRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "proxyRadius",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_proxyRadius);
}

//------------------------------------------------------------------------------
// Address: 0x00528DF0
// Name: protected: void CDmeGamePortal::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::OnConstruction(CDmeGamePortal *this)
{
  this->m_flStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "staticAmount",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flStaticAmount);
  this->m_flSecondaryStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "secondaryStaticAmount",
                                                   type: AT_FLOAT,
                                                   pMemory: &this->m_flSecondaryStaticAmount);
  this->m_flOpenAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "openAmount",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flOpenAmount);
  this->m_flHalfWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "halfWidth",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flHalfWidth);
  this->m_flHalfHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "halfHeight",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flHalfHeight);
  this->m_nPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "portalId",
                                     type: AT_INT,
                                     pMemory: &this->m_nPortalId);
  this->m_nLinkedPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "linkedPortalId",
                                           type: AT_INT,
                                           pMemory: &this->m_nLinkedPortalId);
  this->m_bIsPortal2.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isPortal2",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsPortal2);
  this->m_PortalType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "portalType",
                                      type: AT_STRING,
                                      pMemory: &this->m_PortalType);
}

//------------------------------------------------------------------------------
// Address: 0x00528ED0
// Name: protected: void CDmeGlobalFlexControllerOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_flexWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "flexWeight",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flexWeight);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_gameModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "gameModel",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_gameModel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_gameModel.m_pAttribute, typeSymbol: CDmeGameModel::m_classType);
  this->m_gameModel.m_pAttribute->m_nFlags |= 0x1100u;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_nFlexControllerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00528F40
// Name: protected: void CDmeGameModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnConstruction(CDmeGameModel *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_flexWeights,
    pOwner: this,
    pAttributeName: "flexWeights",
    nFlags: 0);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "modelName", type: AT_STRING, pMemory: &this->m_modelName);
  this->m_modelName.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  this->m_skin.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "skin",
                                type: AT_INT,
                                pMemory: &this->m_skin);
  this->m_body.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "body",
                                type: AT_INT,
                                pMemory: &this->m_body);
  this->m_sequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "sequence",
                                    type: AT_INT,
                                    pMemory: &this->m_sequence);
  this->m_flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_flags);
  this->m_bones.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "bones",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_bones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_bones.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  this->m_globalFlexControllers.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "globalFlexControllers",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_globalFlexControllers);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_globalFlexControllers.m_pAttribute,
    typeSymbol: CDmeGlobalFlexControllerOperator::m_classType);
  this->m_bComputeBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "computeBounds",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bComputeBounds);
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "evaluateProceduralBones",
         type: AT_BOOL,
         pMemory: &this->m_bEvaluateProceduralBones);
  this->m_bEvaluateProceduralBones.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_hMDL = -1;
  this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x00529090
// Name: public: void CDmeGameModel::SetNumFlexWeights(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::SetNumFlexWeights(CDmeGameModel *this, unsigned int nFlexWeights)
{
  unsigned int m_Size; // eax
  unsigned int v4; // edi

  m_Size = this->m_flexWeights.m_Storage.m_Size;
  v4 = nFlexWeights;
  if ( m_Size >= nFlexWeights )
  {
    if ( m_Size > nFlexWeights )
    {
      do
      {
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
          this: &this->m_flexWeights,
          elem: m_Size - 1);
        m_Size = this->m_flexWeights.m_Storage.m_Size;
      }
      while ( m_Size > v4 );
    }
  }
  else
  {
    do
    {
      nFlexWeights = 0;
      CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &this->m_flexWeights,
        src: (const float *)&nFlexWeights);
    }
    while ( this->m_flexWeights.m_Storage.m_Size < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005290F0
// Name: private: int CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(void)const
// Source: json
//------------------------------------------------------------------------------
DmAttributeHandle_t __thiscall CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(
        CDmeGlobalFlexControllerOperator *this)
{
  CDmeGameModel *v1; // eax
  CDmeGameModel *v2; // esi
  int m_hMDL; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // edi
  int j; // ebx
  char *v7; // esi
  const char *m_pAsString; // ecx
  DmAttributeHandle_t v10; // edi
  CDmeGameModel *v11; // eax
  int fc; // [esp+8h] [ebp-Ch]
  LocalFlexController_t i; // [esp+10h] [ebp-4h]

  v1 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  v2 = v1;
  if ( v1->m_bHMDLDirty )
    CDmeGameModel::UpdateHMDL(this: v1);
  m_hMDL = v2->m_hMDL;
  if ( (_WORD)m_hMDL == 0xFFFF )
    return DMATTRIBUTE_HANDLE_INVALID;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: m_hMDL);
  v5 = v4;
  if ( v4 == nullptr )
    return DMATTRIBUTE_HANDLE_INVALID;
  fc = v4->numflexcontrollers;
  i = DUMMY_NULL_FLEX_CONTROLLER;
  if ( fc <= 0 )
    return DMATTRIBUTE_HANDLE_INVALID;
  for ( j = 0; ; j += 20 )
  {
    v7 = (char *)v5 + j + v5->flexcontrollerindex;
    if ( *((_DWORD *)v7 + 2) == -1 && g_pGlobalFlexController != nullptr )
      *((_DWORD *)v7 + 2) = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v7[*((_DWORD *)v7 + 1)]);
    m_pAsString = Ptr;
    if ( this->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
      m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( _V_stricmp(s1: &v7[*((_DWORD *)v7 + 1)], s2: m_pAsString) == 0 )
      break;
    if ( ++i >= fc )
      return DMATTRIBUTE_HANDLE_INVALID;
  }
  v10 = *((_DWORD *)v7 + 2);
  if ( (unsigned int)v10 >= g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle)[2].m_ref.m_attributes.m_hAttribute )
  {
    v11 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
    CDmeGameModel::SetNumFlexWeights(this: v11, nFlexWeights: *((_DWORD *)v7 + 2) + 1);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00529230
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Resolve(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  if ( this->m_ToAttributeHandle < 0 )
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  if ( this->m_gameModel.m_pAttribute == (CDmAttribute *)-1 )
  {
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute);
    if ( v2 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
      if ( Attribute != nullptr )
        this->m_gameModel.m_pAttribute = (CDmAttribute *)CDmAttribute::GetHandle(this: Attribute, bCreate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00529280
// Name: public: virtual void CDmeGlobalFlexControllerOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnAttributeChanged(
        CDmeGlobalFlexControllerOperator *this,
        CDmAttribute *pAttribute)
{
  if ( g_pGlobalFlexController != nullptr
    && pAttribute == (CDmAttribute *)this->m_gameModel.m_Storage.m_ElementType.u.m_Id
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute) != nullptr )
  {
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
    CDmeGlobalFlexControllerOperator::SetupToAttribute(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x005292D0
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x00529360
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *v2; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v6 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00529490
// Name: public: virtual bool CDmeGlobalFlexControllerOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGlobalFlexControllerOperator::IsA(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005294C0
// Name: public: virtual int CDmeGlobalFlexControllerOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGlobalFlexControllerOperator::GetInheritanceDepth(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529590
// Name: protected: virtual void CDmeGlobalFlexControllerOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::PerformConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  CDmeGlobalFlexControllerOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005296D0
// Name: protected: CDmeGameModel::CDmeGameModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CDmeGameModel::CDmeGameModel(
        CDmeGameModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeGameModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_globalFlexControllers);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_flexWeights);
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_skin.m_pAttribute = nullptr;
  this->m_skin.m_Storage = 0;
  this->m_body.m_pAttribute = nullptr;
  this->m_body.m_Storage = 0;
  this->m_sequence.m_pAttribute = nullptr;
  this->m_sequence.m_Storage = 0;
  this->m_flags.m_pAttribute = nullptr;
  this->m_flags.m_Storage = 0;
  this->m_bComputeBounds.m_pAttribute = nullptr;
  this->m_bComputeBounds.m_Storage = false;
  this->m_bEvaluateProceduralBones.m_pAttribute = nullptr;
  this->m_bEvaluateProceduralBones.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_bones);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005297B0
// Name: public: virtual bool CDmeGameModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameModel::IsA(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005297E0
// Name: public: virtual int CDmeGameModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::GetInheritanceDepth(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529830
// Name: protected: virtual void CDmeGameModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformDestruction(CDmeGameModel *this)
{
  int m_hMDL; // eax

  m_hMDL = this->m_hMDL;
  if ( (_WORD)m_hMDL != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: m_hMDL);
    this->m_hMDL = -1;
  }
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00529870
// Name: protected: virtual int CDmeGameModel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::AllocatedSize(CDmeGameModel *this)
{
  return 276;
}

//------------------------------------------------------------------------------
// Address: 0x00529880
// Name: protected: virtual void CDmeGameModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformConstruction(CDmeGameModel *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  CDmeGameModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00529900
// Name: protected: CDmeGameSprite::CDmeGameSprite(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSprite *__thiscall CDmeGameSprite::CDmeGameSprite(
        CDmeGameSprite *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeGameSprite::`vftable';
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_frame.m_pAttribute = nullptr;
  this->m_frame.m_Storage = 0.0;
  this->m_rendermode.m_pAttribute = nullptr;
  this->m_rendermode.m_Storage = 0;
  this->m_renderfx.m_pAttribute = nullptr;
  this->m_renderfx.m_Storage = 0;
  this->m_renderscale.m_pAttribute = nullptr;
  this->m_renderscale.m_Storage = 0.0;
  this->m_color.m_pAttribute = nullptr;
  this->m_color.m_Storage = (Color)-16777216;
  this->m_proxyRadius.m_pAttribute = nullptr;
  this->m_proxyRadius.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005299D0
// Name: public: virtual bool CDmeGameSprite::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSprite::IsA(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529A00
// Name: public: virtual int CDmeGameSprite::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::GetInheritanceDepth(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529A60
// Name: protected: virtual void CDmeGameSprite::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::PerformConstruction(CDmeGameSprite *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  CDmeGameSprite::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00529AC0
// Name: protected: CDmeGamePortal::CDmeGamePortal(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGamePortal *__thiscall CDmeGamePortal::CDmeGamePortal(
        CDmeGamePortal *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeGamePortal::`vftable';
  this->m_nPortalId.m_pAttribute = nullptr;
  this->m_nPortalId.m_Storage = 0;
  this->m_nLinkedPortalId.m_pAttribute = nullptr;
  this->m_nLinkedPortalId.m_Storage = 0;
  this->m_flStaticAmount.m_pAttribute = nullptr;
  this->m_flStaticAmount.m_Storage = 0.0;
  this->m_flSecondaryStaticAmount.m_pAttribute = nullptr;
  this->m_flSecondaryStaticAmount.m_Storage = 0.0;
  this->m_flOpenAmount.m_pAttribute = nullptr;
  this->m_flOpenAmount.m_Storage = 0.0;
  this->m_flHalfWidth.m_pAttribute = nullptr;
  this->m_flHalfWidth.m_Storage = 0.0;
  this->m_flHalfHeight.m_pAttribute = nullptr;
  this->m_flHalfHeight.m_Storage = 0.0;
  this->m_bIsPortal2.m_pAttribute = nullptr;
  this->m_bIsPortal2.m_Storage = false;
  this->m_PortalType.m_Storage.u.m_Id = -1;
  this->m_PortalType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00529BA0
// Name: public: virtual bool CDmeGamePortal::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGamePortal::IsA(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529BD0
// Name: public: virtual int CDmeGamePortal::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::GetInheritanceDepth(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529C20
// Name: protected: virtual void CDmeGamePortal::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::PerformConstruction(CDmeGamePortal *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  CDmeGamePortal::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057B7E0
// Name: _dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGlobalFlexControllerOperator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGlobalFlexControllerOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B840
// Name: _dynamic_initializer_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameModel::s_Allocator,
    blockSize: 276,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B8A0
// Name: _dynamic_initializer_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSprite::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSprite pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B900
// Name: _dynamic_initializer_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGamePortal::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGamePortal pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3E0
// Name: _dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGlobalFlexControllerOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3F0
// Name: _dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E400
// Name: _dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSprite::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E410
// Name: _dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGamePortal::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057B810
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B820
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGlobalFlexControllerOperator_Helper,
           classname: "DmeGlobalFlexControllerOperator",
           pFactory: &g_CDmeGlobalFlexControllerOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057B870
// Name: _dynamic_initializer_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B880
// Name: _dynamic_initializer_for__g_CDmeGameModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameModel_Helper,
           classname: "DmeGameModel",
           pFactory: &g_CDmeGameModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057B8D0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSprite_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B8E0
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSprite_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSprite_Helper,
           classname: "DmeGameSprite",
           pFactory: &g_CDmeGameSprite_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057B930
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGamePortal_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B940
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGamePortal_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGamePortal_Helper,
           classname: "DmeGamePortal",
           pFactory: &g_CDmeGamePortal_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E420
// Name: _dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E430
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSprite_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E440
// Name: _dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGamePortal_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E450
// Name: _dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGlobalFlexControllerOperator_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00578D40
// Name: protected: virtual int CDmeGameSprite::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::AllocatedSize(CDmeVertexDeltaData *this)
{
  return 192;
}

//------------------------------------------------------------------------------
// Address: 0x0062B980
// Name: protected: virtual int CDmeGamePortal::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::AllocatedSize(CDmeSpotLight *this)
{
  return 208;
}

//------------------------------------------------------------------------------
// Address: 0x0062BC80
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Operate(CDmeGlobalFlexControllerOperator *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // edx
  void *m_pData; // ebx
  DmAttributeType_t v5; // esi
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_pAttribute = this->m_flexWeight.m_pAttribute;
    m_pData = m_pAttribute->m_pData;
    v5 = m_pAttribute->m_nFlags & 0x1F;
    if ( (v2->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v2, valueType: v5, pValue: m_pData);
    }
    else if ( this->m_nFlexControllerIndex != -1 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v2);
      CDmrGenericArray::Set(this: &array, i: this->m_nFlexControllerIndex, valueType: v5, pValue: m_pData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062BD00
// Name: public: void CDmeGlobalFlexControllerOperator::SetupToAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::SetupToAttribute(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
    if ( Attribute != nullptr )
      this->m_ToAttributeHandle = CDmAttribute::GetHandle(this: Attribute, bCreate: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062BD40
// Name: public: virtual void CDmeGameModel::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnAttributeChanged(CDmeGameModel *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_modelName.m_pAttribute )
    this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x0062BD60
// Name: protected: void CDmeGameModel::UpdateHMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::UpdateHMDL(CDmeGameModel *this)
{
  const char *m_pAsString; // eax
  unsigned __int16 v3; // di

  m_pAsString = this->m_modelName.m_Storage.u.m_pAsString;
  v3 = -1;
  if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
    v3 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: m_pAsString);
  if ( this->m_hMDL != 0xFFFF )
    g_pMDLCache->Release(this: g_pMDLCache, a2: this->m_hMDL);
  this->m_hMDL = v3;
  this->m_bHMDLDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x0062BDC0
// Name: protected: void CDmeGameSprite::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::OnConstruction(CDmeGameSprite *this)
{
  this->m_modelName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "modelName",
                                     type: AT_STRING,
                                     pMemory: &this->m_modelName);
  this->m_frame.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "frame",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_frame);
  this->m_rendermode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "rendermode",
                                      type: AT_INT,
                                      pMemory: &this->m_rendermode);
  this->m_renderfx.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "renderfx",
                                    type: AT_INT,
                                    pMemory: &this->m_renderfx);
  this->m_renderscale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "renderscale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_renderscale);
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  this->m_proxyRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "proxyRadius",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_proxyRadius);
}

//------------------------------------------------------------------------------
// Address: 0x0062BE70
// Name: protected: void CDmeGamePortal::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::OnConstruction(CDmeGamePortal *this)
{
  this->m_flStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "staticAmount",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flStaticAmount);
  this->m_flSecondaryStaticAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "secondaryStaticAmount",
                                                   type: AT_FLOAT,
                                                   pMemory: &this->m_flSecondaryStaticAmount);
  this->m_flOpenAmount.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "openAmount",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flOpenAmount);
  this->m_flHalfWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "halfWidth",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flHalfWidth);
  this->m_flHalfHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "halfHeight",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flHalfHeight);
  this->m_nPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "portalId",
                                     type: AT_INT,
                                     pMemory: &this->m_nPortalId);
  this->m_nLinkedPortalId.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "linkedPortalId",
                                           type: AT_INT,
                                           pMemory: &this->m_nLinkedPortalId);
  this->m_bIsPortal2.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isPortal2",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsPortal2);
  this->m_PortalType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "portalType",
                                      type: AT_STRING,
                                      pMemory: &this->m_PortalType);
}

//------------------------------------------------------------------------------
// Address: 0x0062BF50
// Name: protected: void CDmeGlobalFlexControllerOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_flexWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "flexWeight",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flexWeight);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_gameModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "gameModel",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_gameModel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_gameModel.m_pAttribute, typeSymbol: CDmeGameModel::m_classType);
  this->m_gameModel.m_pAttribute->m_nFlags |= 0x1100u;
  this->m_ToAttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  this->m_nFlexControllerIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062BFC0
// Name: protected: void CDmeGameModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::OnConstruction(CDmeGameModel *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_flexWeights,
    pOwner: this,
    pAttributeName: "flexWeights",
    nFlags: 0);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "modelName", type: AT_STRING, pMemory: &this->m_modelName);
  this->m_modelName.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  this->m_skin.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "skin",
                                type: AT_INT,
                                pMemory: &this->m_skin);
  this->m_body.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "body",
                                type: AT_INT,
                                pMemory: &this->m_body);
  this->m_sequence.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "sequence",
                                    type: AT_INT,
                                    pMemory: &this->m_sequence);
  this->m_flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_flags);
  this->m_bones.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "bones",
                                 type: AT_FIRST_ARRAY_TYPE,
                                 pMemory: &this->m_bones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_bones.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  this->m_globalFlexControllers.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "globalFlexControllers",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_globalFlexControllers);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_globalFlexControllers.m_pAttribute,
    typeSymbol: CDmeGlobalFlexControllerOperator::m_classType);
  this->m_bComputeBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "computeBounds",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bComputeBounds);
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "evaluateProceduralBones",
         type: AT_BOOL,
         pMemory: &this->m_bEvaluateProceduralBones);
  this->m_bEvaluateProceduralBones.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_hMDL = -1;
  this->m_bHMDLDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x0062C110
// Name: public: void CDmeGameModel::SetNumFlexWeights(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::SetNumFlexWeights(CDmeGameModel *this, unsigned int nFlexWeights)
{
  unsigned int m_Size; // eax
  unsigned int v4; // edi

  m_Size = this->m_flexWeights.m_Storage.m_Size;
  v4 = nFlexWeights;
  if ( m_Size >= nFlexWeights )
  {
    if ( m_Size > nFlexWeights )
    {
      do
      {
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
          this: &this->m_flexWeights,
          elem: m_Size - 1);
        m_Size = this->m_flexWeights.m_Storage.m_Size;
      }
      while ( m_Size > v4 );
    }
  }
  else
  {
    do
    {
      nFlexWeights = 0;
      CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
        this: &this->m_flexWeights,
        src: (const float *)&nFlexWeights);
    }
    while ( this->m_flexWeights.m_Storage.m_Size < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062C170
// Name: private: int CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(void)const
// Source: json
//------------------------------------------------------------------------------
DmAttributeHandle_t __thiscall CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(
        CDmeGlobalFlexControllerOperator *this)
{
  CDmeGameModel *v1; // eax
  CDmeGameModel *v2; // esi
  int m_hMDL; // eax
  studiohdr_t *v4; // eax
  studiohdr_t *v5; // edi
  int j; // ebx
  char *v7; // esi
  const char *m_pAsString; // ecx
  DmAttributeHandle_t v10; // edi
  CDmeGameModel *v11; // eax
  int fc; // [esp+8h] [ebp-Ch]
  LocalFlexController_t i; // [esp+10h] [ebp-4h]

  v1 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
  v2 = v1;
  if ( v1->m_bHMDLDirty )
    CDmeGameModel::UpdateHMDL(this: v1);
  m_hMDL = v2->m_hMDL;
  if ( (_WORD)m_hMDL == 0xFFFF )
    return DMATTRIBUTE_HANDLE_INVALID;
  v4 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: m_hMDL);
  v5 = v4;
  if ( v4 == nullptr )
    return DMATTRIBUTE_HANDLE_INVALID;
  fc = v4->numflexcontrollers;
  i = DUMMY_NULL_FLEX_CONTROLLER;
  if ( fc <= 0 )
    return DMATTRIBUTE_HANDLE_INVALID;
  for ( j = 0; ; j += 20 )
  {
    v7 = (char *)v5 + j + v5->flexcontrollerindex;
    if ( *((_DWORD *)v7 + 2) == -1 && g_pGlobalFlexController != nullptr )
      *((_DWORD *)v7 + 2) = g_pGlobalFlexController->FindGlobalFlexController(
                              this: g_pGlobalFlexController,
                              a2: &v7[*((_DWORD *)v7 + 1)]);
    m_pAsString = var;
    if ( this->m_Name.m_Storage.u.CDmeOperator::CDmElement::m_Id != -1 )
      m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( _V_stricmp(s1: &v7[*((_DWORD *)v7 + 1)], s2: m_pAsString) == 0 )
      break;
    if ( ++i >= fc )
      return DMATTRIBUTE_HANDLE_INVALID;
  }
  v10 = *((_DWORD *)v7 + 2);
  if ( (unsigned int)v10 >= g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle)[2].m_ref.m_attributes.m_hAttribute )
  {
    v11 = (CDmeGameModel *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_gameModel.m_Storage.m_Handle);
    CDmeGameModel::SetNumFlexWeights(this: v11, nFlexWeights: *((_DWORD *)v7 + 2) + 1);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0062C2B0
// Name: public: virtual void CDmeGlobalFlexControllerOperator::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::Resolve(CDmeGlobalFlexControllerOperator *this)
{
  CDmElement *v2; // eax
  CDmAttribute *Attribute; // eax

  if ( this->m_ToAttributeHandle < 0 )
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  if ( this->m_gameModel.m_pAttribute == (CDmAttribute *)-1 )
  {
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute);
    if ( v2 != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "flexWeights");
      if ( Attribute != nullptr )
        this->m_gameModel.m_pAttribute = (CDmAttribute *)CDmAttribute::GetHandle(this: Attribute, bCreate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062C300
// Name: public: virtual void CDmeGlobalFlexControllerOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::OnAttributeChanged(
        CDmeGlobalFlexControllerOperator *this,
        CDmAttribute *pAttribute)
{
  if ( g_pGlobalFlexController != nullptr
    && pAttribute == (CDmAttribute *)this->m_gameModel.m_Storage.m_ElementType.u.m_Id
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_flexWeight.m_pAttribute) != nullptr )
  {
    this->m_ToAttributeHandle = CDmeGlobalFlexControllerOperator::FindGlobalFlexControllerIndex(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
    CDmeGlobalFlexControllerOperator::SetupToAttribute(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062C350
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_boneParent);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_boneFlags);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x0062C380
// Name: public: virtual void CDmeGlobalFlexControllerOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *v2; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_ToAttributeHandle);
  if ( v2 != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v6 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062C4B0
// Name: public: virtual bool CDmeGlobalFlexControllerOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGlobalFlexControllerOperator::IsA(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062C4E0
// Name: public: virtual int CDmeGlobalFlexControllerOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGlobalFlexControllerOperator::GetInheritanceDepth(
        CDmeGlobalFlexControllerOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGlobalFlexControllerOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062C5B0
// Name: protected: virtual void CDmeGlobalFlexControllerOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGlobalFlexControllerOperator::PerformConstruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
  CDmeGlobalFlexControllerOperator::OnConstruction(this: (CDmeGlobalFlexControllerOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0062C6F0
// Name: protected: CDmeGameModel::CDmeGameModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CDmeGameModel::CDmeGameModel(
        CDmeGameModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameModel_vtbl *)&CDmeGameModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_globalFlexControllers);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_flexWeights);
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_skin.m_pAttribute = nullptr;
  this->m_skin.m_Storage = 0;
  this->m_body.m_pAttribute = nullptr;
  this->m_body.m_Storage = 0;
  this->m_sequence.m_pAttribute = nullptr;
  this->m_sequence.m_Storage = 0;
  this->m_flags.m_pAttribute = nullptr;
  this->m_flags.m_Storage = 0;
  this->m_bComputeBounds.m_pAttribute = nullptr;
  this->m_bComputeBounds.m_Storage = false;
  this->m_bEvaluateProceduralBones.m_pAttribute = nullptr;
  this->m_bEvaluateProceduralBones.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_bones);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062C7D0
// Name: public: virtual bool CDmeGameModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameModel::IsA(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062C800
// Name: public: virtual int CDmeGameModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::GetInheritanceDepth(CDmeGameModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062C850
// Name: protected: virtual void CDmeGameModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformDestruction(CDmeGameModel *this)
{
  int m_hMDL; // eax

  m_hMDL = this->m_hMDL;
  if ( (_WORD)m_hMDL != 0xFFFF )
  {
    g_pMDLCache->Release(this: g_pMDLCache, a2: m_hMDL);
    this->m_hMDL = -1;
  }
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0062C890
// Name: protected: virtual int CDmeGameModel::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameModel::AllocatedSize(CDmeGameModel *this)
{
  return 276;
}

//------------------------------------------------------------------------------
// Address: 0x0062C8A0
// Name: protected: virtual void CDmeGameModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameModel::PerformConstruction(CDmeGameModel *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  CDmeGameModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0062C920
// Name: protected: CDmeGameSprite::CDmeGameSprite(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSprite *__thiscall CDmeGameSprite::CDmeGameSprite(
        CDmeGameSprite *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGameSprite_vtbl *)&CDmeGameSprite::`vftable';
  this->m_modelName.m_pAttribute = nullptr;
  this->m_modelName.m_Storage.u.m_Id = -1;
  this->m_frame.m_pAttribute = nullptr;
  this->m_frame.m_Storage = 0.0;
  this->m_rendermode.m_pAttribute = nullptr;
  this->m_rendermode.m_Storage = 0;
  this->m_renderfx.m_pAttribute = nullptr;
  this->m_renderfx.m_Storage = 0;
  this->m_renderscale.m_pAttribute = nullptr;
  this->m_renderscale.m_Storage = 0.0;
  this->m_color.m_pAttribute = nullptr;
  this->m_color.m_Storage = (Color)-16777216;
  this->m_proxyRadius.m_pAttribute = nullptr;
  this->m_proxyRadius.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062C9F0
// Name: public: virtual bool CDmeGameSprite::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSprite::IsA(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062CA20
// Name: public: virtual int CDmeGameSprite::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSprite::GetInheritanceDepth(CDmeGameSprite *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSprite::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062CA70
// Name: protected: virtual void CDmeGameSprite::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSprite::PerformConstruction(CDmeGameSprite *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  CDmeGameSprite::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0062CAD0
// Name: protected: CDmeGamePortal::CDmeGamePortal(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGamePortal *__thiscall CDmeGamePortal::CDmeGamePortal(
        CDmeGamePortal *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeGamePortal_vtbl *)&CDmeGamePortal::`vftable';
  this->m_nPortalId.m_pAttribute = nullptr;
  this->m_nPortalId.m_Storage = 0;
  this->m_nLinkedPortalId.m_pAttribute = nullptr;
  this->m_nLinkedPortalId.m_Storage = 0;
  this->m_flStaticAmount.m_pAttribute = nullptr;
  this->m_flStaticAmount.m_Storage = 0.0;
  this->m_flSecondaryStaticAmount.m_pAttribute = nullptr;
  this->m_flSecondaryStaticAmount.m_Storage = 0.0;
  this->m_flOpenAmount.m_pAttribute = nullptr;
  this->m_flOpenAmount.m_Storage = 0.0;
  this->m_flHalfWidth.m_pAttribute = nullptr;
  this->m_flHalfWidth.m_Storage = 0.0;
  this->m_flHalfHeight.m_pAttribute = nullptr;
  this->m_flHalfHeight.m_Storage = 0.0;
  this->m_bIsPortal2.m_pAttribute = nullptr;
  this->m_bIsPortal2.m_Storage = false;
  this->m_PortalType.m_Storage.u.m_Id = -1;
  this->m_PortalType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062CBB0
// Name: public: virtual bool CDmeGamePortal::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGamePortal::IsA(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062CBE0
// Name: public: virtual int CDmeGamePortal::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGamePortal::GetInheritanceDepth(CDmeGamePortal *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGamePortal::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062CC30
// Name: protected: virtual void CDmeGamePortal::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGamePortal::PerformConstruction(CDmeGamePortal *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  CDmeGamePortal::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B9750
// Name: _dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGlobalFlexControllerOperator::s_Allocator,
    blockSize: 0x68u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGlobalFlexControllerOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B97B0
// Name: _dynamic_initializer_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameModel::s_Allocator,
    blockSize: 0x114u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9810
// Name: _dynamic_initializer_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSprite::s_Allocator,
    blockSize: 0xC0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSprite pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9870
// Name: _dynamic_initializer_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGamePortal::s_Allocator,
    blockSize: 0xD0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGamePortal pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD200
// Name: _dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGlobalFlexControllerOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGlobalFlexControllerOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD210
// Name: _dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD220
// Name: _dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSprite::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSprite::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD230
// Name: _dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGamePortal::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGamePortal::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B9780
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9790
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGlobalFlexControllerOperator_Helper,
           classname: "DmeGlobalFlexControllerOperator",
           pFactory: &g_CDmeGlobalFlexControllerOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B97E0
// Name: _dynamic_initializer_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B97F0
// Name: _dynamic_initializer_for__g_CDmeGameModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameModel_Helper,
           classname: "DmeGameModel",
           pFactory: &g_CDmeGameModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9840
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSprite_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9850
// Name: _dynamic_initializer_for__g_CDmeGameSprite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSprite_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSprite_Helper,
           classname: "DmeGameSprite",
           pFactory: &g_CDmeGameSprite_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B98A0
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGamePortal_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B98B0
// Name: _dynamic_initializer_for__g_CDmeGamePortal_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGamePortal_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGamePortal_Helper,
           classname: "DmeGamePortal",
           pFactory: &g_CDmeGamePortal_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD240
// Name: _dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameModel_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeGameModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD250
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSprite_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeGameSprite_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD260
// Name: _dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGamePortal_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeGamePortal_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD270
// Name: _dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGlobalFlexControllerOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeGlobalFlexControllerOperator_Factory.m_CallBackList);
}

} // namespace vmap
