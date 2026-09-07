// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeparticlesystemdefinition.cpp
// Functions: 65
// ============================================================

#include "movieobjects\dmeparticlesystemdefinition.h"

//------------------------------------------------------------------------------
// Address: 0x00513870
// Name: protected: virtual int CDmeParticleOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleOperator::AllocatedSize(CDmeParticleOperator *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x005B0800
// Name: protected: virtual int CDmeParticleSystemDefinition::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleSystemDefinition::AllocatedSize(CDmeParticleSystemDefinition *this)
{
  return 276;
}

//------------------------------------------------------------------------------
// Address: 0x005C3700
// Name: protected: virtual int CDmeParticleFunction::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleFunction::AllocatedSize(CDmeSound *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x005C40D0
// Name: public: virtual void CDmeParticleFunction::OnElementUnserialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleFunction::OnElementUnserialized(CDmeParticleFunction *this)
{
  this->m_bSkipNextResolve = true;
}

//------------------------------------------------------------------------------
// Address: 0x005C40E0
// Name: RemoveObsoleteAttributes
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveObsoleteAttributes(CDmElement *pElement, const DmxElementUnpackStructure_t *pUnpack)
{
  CDmAttribute *Attribute; // edi
  CDmAttribute *m_pNext; // ebx
  const DmxElementUnpackStructure_t *v4; // esi
  const char *Name; // eax

  Attribute = CDmElement::FirstAttribute(this: pElement);
  if ( Attribute != nullptr )
  {
    do
    {
      m_pNext = Attribute->m_pNext;
      if ( !CDmAttribute::IsStandard(this: Attribute) && (Attribute->m_nFlags & 0x200) == 0 )
      {
        v4 = pUnpack;
        if ( pUnpack->m_pAttributeName != nullptr )
        {
          while ( 1 )
          {
            Name = CDmAttribute::GetName(this: Attribute);
            if ( _V_stricmp(s1: v4->m_pAttributeName, s2: Name) == 0 )
              break;
            ++v4;
            if ( v4->m_pAttributeName == nullptr )
              goto LABEL_7;
          }
        }
        else
        {
LABEL_7:
          CDmElement::RemoveAttributeByPtr(this: pElement, pAttribute: Attribute);
        }
      }
      Attribute = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C4150
// Name: public: virtual char const __near * CDmeParticleOperator::GetFunctionType(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeParticleOperator::GetFunctionType(CDmeParticleOperator *this)
{
  const char *result; // eax

  result = this->m_FunctionName.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C4160
// Name: public: virtual char const __near * CDmeParticleChild::GetFunctionType(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeParticleChild::GetFunctionType(CDmeParticleChild *this)
{
  CDmElement *v1; // eax
  const char *result; // eax

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Child.m_Storage.m_Handle);
  if ( v1 == nullptr )
    return defaultValue;
  result = v1->m_Name.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C4370
// Name: CreateEditorAttributeInfo
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateEditorAttributeInfo(
        const char *pAttributeName@<edi>,
        const char *pWidgetInfo@<eax>,
        CDmeEditorType *pEditorType)
{
  CDmeEditorAttributeInfo *v4; // esi
  const char *v5; // eax
  CDmeEditorBoolChoicesInfo *v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  CCommand parse; // [esp+8h] [ebp-50Ch] BYREF
  CUtlSymbolLarge value; // [esp+510h] [ebp-4h] BYREF

  if ( pWidgetInfo != nullptr )
  {
    CCommand::CCommand(this: &parse);
    CCommand::Tokenize(this: &parse, pCommand: pWidgetInfo, pBreakSet: nullptr);
    if ( parse.m_nArgc == 1 )
    {
      v4 = CreateElement<CDmeEditorAttributeInfo>(
             pObjectName: "field info",
             fileid: DMFILEID_INVALID,
             pObjectID: nullptr);
      CDmeEditorType::AddAttributeInfo(this: pEditorType, (int)pAttributeName, pInfo: (CExpressionCalculator *)v4);
      v5 = defaultValue;
      if ( parse.m_nArgc > 0 )
        v5 = parse.m_ppArgv[0];
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: v5);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v4->m_Widget.m_pAttribute, &value);
    }
    else if ( parse.m_nArgc == 2 )
    {
      v6 = nullptr;
      if ( _V_stricmp(s1: parse.m_ppArgv[0], s2: "intchoice") == 0 )
        v6 = (CDmeEditorBoolChoicesInfo *)CreateElement<CDmeEditorIntChoicesInfo>(
                                            pObjectName: "field info",
                                            fileid: DMFILEID_INVALID,
                                            pObjectID: nullptr);
      v7 = defaultValue;
      if ( parse.m_nArgc > 0 )
        v7 = parse.m_ppArgv[0];
      if ( _V_stricmp(s1: v7, s2: "boolchoice") == 0 )
        v6 = CreateElement<CDmeEditorBoolChoicesInfo>(
               pObjectName: "field info",
               fileid: DMFILEID_INVALID,
               pObjectID: nullptr);
      v8 = defaultValue;
      if ( parse.m_nArgc > 0 )
        v8 = parse.m_ppArgv[0];
      if ( _V_stricmp(s1: v8, s2: "stringchoice") == 0 )
        v6 = (CDmeEditorBoolChoicesInfo *)CreateElement<CDmeEditorStringChoicesInfo>(
                                            pObjectName: "field info",
                                            fileid: DMFILEID_INVALID,
                                            pObjectID: nullptr);
      v9 = defaultValue;
      if ( parse.m_nArgc > 0 )
        v9 = parse.m_ppArgv[0];
      if ( _V_stricmp(s1: v9, s2: "elementchoice") == 0 )
        v6 = (CDmeEditorBoolChoicesInfo *)CreateElement<CDmeEditorChoicesInfo>(
                                            pObjectName: "field info",
                                            fileid: DMFILEID_INVALID,
                                            pObjectID: nullptr);
      if ( v6 != nullptr )
      {
        v10 = defaultValue;
        if ( parse.m_nArgc > 1 )
          v10 = parse.m_ppArgv[1];
        CDmeEditorChoicesInfo::SetChoiceType(this: v6, pChoiceType: v10);
        CDmeEditorType::AddAttributeInfo(this: pEditorType, (int)pAttributeName, pInfo: (CExpressionCalculator *)v6);
        v11 = defaultValue;
        if ( parse.m_nArgc > 0 )
          v11 = parse.m_ppArgv[0];
        CDmaString::operator=(this: &v6->m_Widget, src: v11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C4530
// Name: protected: void CDmeParticleSystemDefinition::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::OnConstruction(CDmeParticleSystemDefinition *this)
{
  CDmaElementArray<CDmeParticleFunction> *m_ParticleFunction; // edi
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // edi
  CExpressionCalculator *v6; // ecx
  CDmeHandle<CDmeEditorTypeDictionary,0> *p_m_hTypeDictionary; // ebx
  DmElementHandle_t BufferType; // eax
  DmElementHandle_t v9; // eax
  CDmElement *v10; // eax
  CDmeEditorType *v11; // edi
  bool v12; // al
  const DmxElementUnpackStructure_t *ParticleSystemDefinitionUnpackStructure; // eax
  const char **p_m_pDefaultString; // ebx
  const char *v15; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v17; // edi
  int v18; // eax
  CDmeEditorTypeDictionary *v19; // eax
  CExpressionCalculator *v20; // [esp-4h] [ebp-4Ch]
  CUtlBuffer bufParse; // [esp+Ch] [ebp-3Ch] BYREF
  CDmeHandle<CDmeEditorTypeDictionary,0> *v22; // [esp+3Ch] [ebp-Ch]
  DmAttributeType_t type; // [esp+40h] [ebp-8h]
  CDmeEditorType *pEditorType; // [esp+44h] [ebp-4h]

  m_ParticleFunction = this->m_ParticleFunction;
  this->m_ParticleFunction[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "renderers",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: this->m_ParticleFunction);
  CDmAttribute::SetElementTypeSymbol(
    this: m_ParticleFunction->m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "operators",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[1]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[1].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[2].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "initializers",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[2]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[2].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[3].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "emitters",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[3]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[3].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[4].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "children",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[4]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[4].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[5].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "forces",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[5]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[5].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[6].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "constraints",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[6]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[6].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_bPreventNameBasedLookup.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "preventNameBasedLookup",
                                                   type: AT_BOOL,
                                                   pMemory: &this->m_bPreventNameBasedLookup);
  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorTypeDictionary::m_classType.u.m_Id,
         a3: "particleSystemDefinitionDict",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeEditorTypeDictionary::m_classType) )
    v6 = (CExpressionCalculator *)v5;
  else
    v6 = nullptr;
  p_m_hTypeDictionary = &this->m_hTypeDictionary;
  v22 = &this->m_hTypeDictionary;
  if ( v6 != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeEditorTypeDictionary,0>::Set(this: &this->m_hTypeDictionary, h: BufferType);
  v9 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorType::m_classType.u.m_Id,
         a3: "DmeParticleSystemDefinition",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9);
  v11 = (CDmeEditorType *)v10;
  if ( v10 == nullptr || (v12 = v10->IsA(this: v10, a2: CDmeEditorType::m_classType), pEditorType = v11, !v12) )
    pEditorType = nullptr;
  ParticleSystemDefinitionUnpackStructure = CParticleSystemMgr::GetParticleSystemDefinitionUnpackStructure(this: g_pParticleSystemMgr);
  if ( ParticleSystemDefinitionUnpackStructure->m_pAttributeName != nullptr )
  {
    p_m_pDefaultString = &ParticleSystemDefinitionUnpackStructure->m_pDefaultString;
    do
    {
      CreateEditorAttributeInfo(
        pAttributeName: *(p_m_pDefaultString - 1),
        pWidgetInfo: p_m_pDefaultString[6],
        pEditorType);
      v15 = *(p_m_pDefaultString - 1);
      type = (DmAttributeType_t)p_m_pDefaultString[1];
      Attribute = CDmElement::FindAttribute(this, pAttributeName: v15);
      if ( Attribute != nullptr )
        v17 = type == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr;
      else
        v17 = CDmElement::CreateAttribute(this, pAttributeName: v15, type);
      if ( *p_m_pDefaultString != nullptr )
      {
        if ( _V_strlen(str: *p_m_pDefaultString) >= 1 )
          v18 = _V_strlen(str: *p_m_pDefaultString);
        else
          v18 = 1;
        CUtlBuffer::CUtlBuffer(this: &bufParse, pBuffer: (unsigned __int8 *)*p_m_pDefaultString, nSize: v18, nFlags: 9u);
        CDmAttribute::Unserialize(this: v17, buf: &bufParse);
        if ( bufParse.m_Memory.m_nGrowSize >= 0 && bufParse.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufParse.m_Memory.m_pMemory);
      }
      p_m_pDefaultString += 11;
    }
    while ( *(p_m_pDefaultString - 1) != nullptr );
    p_m_hTypeDictionary = v22;
  }
  v20 = (CExpressionCalculator *)pEditorType;
  v19 = (CDmeEditorTypeDictionary *)g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_hTypeDictionary->m_handle);
  CDmeEditorTypeDictionary::AddEditorType(this: v19, pEditorType: v20);
}

//------------------------------------------------------------------------------
// Address: 0x005C4830
// Name: public: void CDmeParticleSystemDefinition::RecompileParticleSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::RecompileParticleSystem(CDmeParticleSystemDefinition *this)
{
  const char *v2; // esi
  bool v3; // al
  IDataModel_vtbl *v4; // ebx
  int BufferType; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-30h] BYREF

  v2 = g_pDataModel->GetDefaultEncoding(this: g_pDataModel, a2: "pcf");
  v3 = g_pDataModel->IsEncodingBinary(this: g_pDataModel, a2: v2);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: !v3);
  v4 = g_pDataModel->__vftable;
  BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
  if ( v4->Serialize(this: g_pDataModel, a2: &buf, a3: v2, a4: "pcf", a5: (DmElementHandle_t)BufferType) )
    CParticleSystemMgr::ReadParticleConfigFile(
      this: g_pParticleSystemMgr,
      &buf,
      bPrecache: true,
      bDecommitTempMemory: true,
      pFileName: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x005C48E0
// Name: public: void CDmeParticleFunction::AddMissingFields(struct DmxElementUnpackStructure_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleFunction::AddMissingFields(
        CDmeParticleFunction *this,
        const DmxElementUnpackStructure_t *pUnpack)
{
  CDmeParticleFunction *v2; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmAttribute *v4; // eax
  DmElementHandle_t v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // edi
  CExpressionCalculator *v8; // ecx
  const char *m_pAsString; // eax
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  DmElementHandle_t v12; // edi
  bool v13; // al
  const char **p_m_pDefaultString; // ebx
  const char *v15; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v17; // esi
  int v18; // eax
  CDmeEditorTypeDictionary *v19; // eax
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-48h]
  CUtlBuffer bufParse; // [esp+Ch] [ebp-38h] BYREF
  CDmeParticleFunction *v22; // [esp+3Ch] [ebp-8h]
  DmElementHandle_t value; // [esp+40h] [ebp-4h] BYREF
  const DmxElementUnpackStructure_t *pUnpacka; // [esp+4Ch] [ebp+8h]

  v2 = this;
  GetElement = g_pDataModel->GetElement;
  m_Handle = this->m_hTypeDictionary.m_Storage.m_Handle;
  v22 = this;
  v4 = (CDmAttribute *)GetElement(this: g_pDataModel, a2: m_Handle);
  DestroyElement(pElement: v4, depth: TD_DEEP);
  v5 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorTypeDictionary::m_classType.u.m_Id,
         a3: "particleFunctionDict",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  v7 = v6;
  if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeEditorTypeDictionary::m_classType) )
    v8 = (CExpressionCalculator *)v7;
  else
    v8 = nullptr;
  if ( v8 != nullptr )
    value = CCodecBuffer_Block::GetBufferType(this: v8);
  else
    value = DMELEMENT_HANDLE_INVALID;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: v2->m_hTypeDictionary.m_pAttribute, &value);
  m_pAsString = v2->m_Type.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  v10 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
          a1: g_pDataModel,
          a2: (CUtlSymbolLarge)CDmeEditorType::m_classType.u.m_Id,
          a3: m_pAsString,
          a4: DMFILEID_INVALID,
          a5: nullptr);
  v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
  v12 = (DmElementHandle_t)v11;
  if ( v11 == nullptr || (v13 = v11->IsA(this: v11, a2: CDmeEditorType::m_classType), value = v12, !v13) )
    value = 0;
  if ( pUnpack->m_pAttributeName != nullptr )
  {
    p_m_pDefaultString = &pUnpack->m_pDefaultString;
    do
    {
      CreateEditorAttributeInfo(
        pAttributeName: *(p_m_pDefaultString - 1),
        pWidgetInfo: p_m_pDefaultString[6],
        pEditorType: (CDmeEditorType *)value);
      if ( !CDmElement::HasAttribute(this: v2, pAttributeName: *(p_m_pDefaultString - 1), type: AT_UNKNOWN) )
      {
        v15 = *(p_m_pDefaultString - 1);
        pUnpacka = (const DmxElementUnpackStructure_t *)p_m_pDefaultString[1];
        Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: v15);
        if ( Attribute != nullptr )
          v17 = pUnpacka == (const DmxElementUnpackStructure_t *)(Attribute->m_nFlags & 0x1F) ? Attribute : nullptr;
        else
          v17 = CDmElement::CreateAttribute(this: v2, pAttributeName: v15, type: (DmAttributeType_t)pUnpacka);
        if ( *p_m_pDefaultString != nullptr )
        {
          v18 = _V_strlen(str: *p_m_pDefaultString);
          CUtlBuffer::CUtlBuffer(
            this: &bufParse,
            pBuffer: (unsigned __int8 *)*p_m_pDefaultString,
            nSize: v18,
            nFlags: 9u);
          CDmAttribute::Unserialize(this: v17, buf: &bufParse);
          if ( bufParse.m_Memory.m_nGrowSize >= 0 && bufParse.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufParse.m_Memory.m_pMemory);
        }
        v2 = v22;
      }
      p_m_pDefaultString += 11;
    }
    while ( *(p_m_pDefaultString - 1) != nullptr );
  }
  v19 = (CDmeEditorTypeDictionary *)g_pDataModel->GetElement(
                                      this: g_pDataModel,
                                      a2: v2->m_hTypeDictionary.m_Storage.m_Handle);
  CDmeEditorTypeDictionary::AddEditorType(this: v19, pEditorType: (CExpressionCalculator *)value);
}

//------------------------------------------------------------------------------
// Address: 0x005C4AD0
// Name: public: virtual void CDmeParticleFunction::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleFunction::Resolve(CDmeParticleFunction *this)
{
  CDmAttribute *Attribute; // eax
  IDataModel_vtbl *v3; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t i; // edi
  CDmElement *m_pOwner; // esi

  if ( this->m_bSkipNextResolve )
  {
    this->m_bSkipNextResolve = false;
  }
  else
  {
    Attribute = CDmElement::FirstAttribute(this);
    if ( Attribute != nullptr )
    {
      while ( SLOBYTE(Attribute->m_nFlags) >= 0 )
      {
        Attribute = Attribute->m_pNext;
        if ( Attribute == nullptr )
          return;
      }
      v3 = g_pDataModel->__vftable;
      BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
      for ( i = v3->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
            i != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
            i = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: i) )
      {
        m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: i)->m_pOwner;
        if ( m_pOwner != nullptr
          && m_pOwner->IsA(this: m_pOwner, a2: CDmeParticleSystemDefinition::m_classType)
          && m_pOwner->m_fileId == this->m_fileId )
        {
          CDmeParticleSystemDefinition::RecompileParticleSystem(this: (CDmeParticleSystemDefinition *)m_pOwner);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C4B90
// Name: public: virtual void CDmeParticleSystemDefinition::OnElementUnserialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::OnElementUnserialized(CDmeParticleSystemDefinition *this)
{
  CDmeParticleSystemDefinition *v1; // edi
  const DmxElementUnpackStructure_t *ParticleSystemDefinitionUnpackStructure; // eax
  ParticleFunctionType_t v3; // esi
  CParticleSystemMgr *AvailableParticleOperatorList; // ebx
  char *v5; // eax
  int v6; // ecx
  CDmElement *v7; // eax
  CDmeParticleFunction *v8; // edi
  const DmxElementUnpackStructure_t *v9; // eax
  IParticleOperatorDefinition *v10; // ecx
  IParticleOperatorDefinition_vtbl *v11; // edx
  int v12; // esi
  const char *Name; // eax
  const DmxElementUnpackStructure_t *v14; // eax
  IParticleOperatorDefinition *v15; // esi
  const DmxElementUnpackStructure_t *v16; // eax
  const char *v17; // [esp-4h] [ebp-28h]
  int nCount; // [esp+10h] [ebp-14h]
  char *v20; // [esp+14h] [ebp-10h]
  int j; // [esp+18h] [ebp-Ch]
  int nAvailType; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v1 = this;
  ParticleSystemDefinitionUnpackStructure = CParticleSystemMgr::GetParticleSystemDefinitionUnpackStructure(this: g_pParticleSystemMgr);
  RemoveObsoleteAttributes(pElement: v1, pUnpack: ParticleSystemDefinitionUnpackStructure);
  v3 = FUNCTION_RENDERER;
  i = 0;
  do
  {
    AvailableParticleOperatorList = CParticleSystemMgr::GetAvailableParticleOperatorList(
                                      this: g_pParticleSystemMgr,
                                      nWhichList: v3);
    nAvailType = AvailableParticleOperatorList->m_ParticleOperators[0].m_Size;
    v5 = (char *)v1 + 28 * v3;
    v6 = 0;
    v20 = v5;
    nCount = *((_DWORD *)v5 + 20);
    j = 0;
    if ( nCount <= 0 )
      goto LABEL_18;
    while ( 1 )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*((_DWORD *)v5 + 17) + 4 * v6));
      v8 = (CDmeParticleFunction *)v7;
      if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmeParticleFunction::m_classType) )
        v8 = nullptr;
      if ( v3 == FUNCTION_CHILDREN )
      {
        v9 = (const DmxElementUnpackStructure_t *)(*(int (__thiscall **)(IParticleOperatorDefinition *))(**(_DWORD **)AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory + 8))(a1: *AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory);
        RemoveObsoleteAttributes(pElement: v8, pUnpack: v9);
        v10 = *AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory;
        v11 = v10->__vftable;
      }
      else
      {
        v12 = 0;
        if ( nAvailType <= 0 )
          goto LABEL_16;
        while ( 1 )
        {
          v17 = AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory[v12]->GetName(this: AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory[v12]);
          Name = CDmAttribute::GetName(this: (CDmAttribute *)v8);
          if ( _V_stricmp(s1: Name, s2: v17) == 0 )
            break;
          if ( ++v12 >= nAvailType )
            goto LABEL_16;
        }
        v14 = AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory[v12]->GetUnpackStructure(this: AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory[v12]);
        RemoveObsoleteAttributes(pElement: v8, pUnpack: v14);
        v15 = AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory[v12];
        v11 = v15->__vftable;
        v10 = v15;
      }
      v16 = (const DmxElementUnpackStructure_t *)((int (__fastcall *)(IParticleOperatorDefinition *))v11->GetUnpackStructure)(a1: v10);
      CDmeParticleFunction::AddMissingFields(this: v8, pUnpack: v16);
LABEL_16:
      v3 = i;
      v6 = j + 1;
      j = v6;
      if ( v6 >= nCount )
        break;
      v5 = v20;
    }
    v1 = this;
LABEL_18:
    i = ++v3;
  }
  while ( v3 < PARTICLE_FUNCTION_COUNT );
}

//------------------------------------------------------------------------------
// Address: 0x005C4CE0
// Name: public: virtual void CDmeParticleSystemDefinition::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::Resolve(CDmeParticleSystemDefinition *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FirstAttribute(this);
  if ( Attribute != nullptr )
  {
    while ( SLOBYTE(Attribute->m_nFlags) >= 0 )
    {
      Attribute = Attribute->m_pNext;
      if ( Attribute == nullptr )
        return;
    }
    CDmeParticleSystemDefinition::RecompileParticleSystem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C4DB0
// Name: public: virtual bool CDmeParticleFunction::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeParticleFunction::IsA(CDmeParticleFunction *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C4DE0
// Name: public: virtual int CDmeParticleFunction::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleFunction::GetInheritanceDepth(CDmeParticleFunction *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C4E80
// Name: protected: virtual void CDmeParticleFunction::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleFunction::PerformConstruction(CDmeParticleFunction *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_bSkipNextResolve = false;
  this->m_hTypeDictionary.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "type_dictionary",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_hTypeDictionary);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_hTypeDictionary.m_pAttribute,
    typeSymbol: CDmeEditorTypeDictionary::m_classType);
  this->m_hTypeDictionary.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x005C4F60
// Name: public: virtual bool CDmeParticleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeParticleOperator::IsA(CDmeParticleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeParticleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C4F90
// Name: public: virtual int CDmeParticleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleOperator::GetInheritanceDepth(CDmeParticleOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeParticleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C5050
// Name: protected: virtual void CDmeParticleOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleOperator::PerformConstruction(CDmeParticleOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_bSkipNextResolve = false;
  this->m_hTypeDictionary.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "type_dictionary",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_hTypeDictionary);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_hTypeDictionary.m_pAttribute,
    typeSymbol: CDmeEditorTypeDictionary::m_classType);
  this->m_hTypeDictionary.m_pAttribute->m_nFlags |= 0x8040u;
  this->m_FunctionName.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "functionName",
                                        type: AT_STRING,
                                        pMemory: &this->m_FunctionName);
}

//------------------------------------------------------------------------------
// Address: 0x005C5140
// Name: public: virtual bool CDmeParticleChild::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeParticleChild::IsA(CDmeParticleChild *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeParticleChild::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C5170
// Name: public: virtual int CDmeParticleChild::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleChild::GetInheritanceDepth(CDmeParticleChild *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeParticleChild::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C5230
// Name: protected: virtual void CDmeParticleChild::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleChild::PerformConstruction(CDmeParticleChild *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_bSkipNextResolve = false;
  this->m_hTypeDictionary.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "type_dictionary",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_hTypeDictionary);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_hTypeDictionary.m_pAttribute,
    typeSymbol: CDmeEditorTypeDictionary::m_classType);
  this->m_hTypeDictionary.m_pAttribute->m_nFlags |= 0x8040u;
  this->m_Child.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "child",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Child);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_Child.m_pAttribute,
    typeSymbol: CDmeParticleSystemDefinition::m_classType);
  this->m_Child.m_pAttribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x005C5310
// Name: protected: CDmeParticleSystemDefinition::CDmeParticleSystemDefinition(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeParticleSystemDefinition *__thiscall CDmeParticleSystemDefinition::CDmeParticleSystemDefinition(
        CDmeParticleSystemDefinition *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaElementArray<CDmeParticleFunction> *m_ParticleFunction; // esi
  int i; // ebx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeParticleSystemDefinition_vtbl *)&CDmeParticleSystemDefinition::`vftable';
  m_ParticleFunction = this->m_ParticleFunction;
  for ( i = 6; i >= 0; --i )
    CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: m_ParticleFunction++);
  this->m_bPreventNameBasedLookup.m_pAttribute = nullptr;
  this->m_bPreventNameBasedLookup.m_Storage = false;
  this->m_hTypeDictionary.m_handle = DMELEMENT_HANDLE_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005C5370
// Name: public: virtual bool CDmeParticleSystemDefinition::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeParticleSystemDefinition::IsA(CDmeParticleSystemDefinition *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeParticleSystemDefinition::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C53A0
// Name: public: virtual int CDmeParticleSystemDefinition::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleSystemDefinition::GetInheritanceDepth(
        CDmeParticleSystemDefinition *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeParticleSystemDefinition::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C53E0
// Name: protected: virtual void CDmeParticleSystemDefinition::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::PerformDestruction(CDmeParticleSystemDefinition *this)
{
  CDmAttribute *v2; // eax

  v2 = (CDmAttribute *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hTypeDictionary.m_handle);
  DestroyElement(pElement: v2, depth: TD_DEEP);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005C5410
// Name: protected: virtual void CDmeParticleSystemDefinition::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::PerformConstruction(CDmeParticleSystemDefinition *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeParticleSystemDefinition::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005C5420
// Name: protected: virtual CDmeParticleSystemDefinition::~CDmeParticleSystemDefinition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::~CDmeParticleSystemDefinition(CDmeParticleSystemDefinition *this)
{
  CDmeElementRefHelper *p_m_hTypeDictionary; // ecx
  CDmaVar<bool> *p_m_bPreventNameBasedLookup; // esi
  void *v4; // eax
  int i; // [esp+Ch] [ebp-4h]

  this->__vftable = (CDmeParticleSystemDefinition_vtbl *)&CDmeParticleSystemDefinition::`vftable';
  p_m_hTypeDictionary = &this->m_hTypeDictionary;
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: p_m_hTypeDictionary,
      hElement: *(_DWORD *)p_m_hTypeDictionary,
      handleType: HT_WEAK);
  p_m_bPreventNameBasedLookup = &this->m_bPreventNameBasedLookup;
  for ( i = 6; i >= 0; --i )
  {
    p_m_bPreventNameBasedLookup = (CDmaVar<bool> *)((char *)p_m_bPreventNameBasedLookup - 28);
    p_m_bPreventNameBasedLookup[1].m_pAttribute = nullptr;
    if ( *(int *)&p_m_bPreventNameBasedLookup[1].m_Storage >= 0 )
    {
      if ( *(_DWORD *)&p_m_bPreventNameBasedLookup->m_Storage != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&p_m_bPreventNameBasedLookup->m_Storage);
        *(_DWORD *)&p_m_bPreventNameBasedLookup->m_Storage = 0;
      }
      p_m_bPreventNameBasedLookup->m_pAttribute = nullptr;
    }
    v4 = *(void **)&p_m_bPreventNameBasedLookup->m_Storage;
    *(_DWORD *)&p_m_bPreventNameBasedLookup[2].m_Storage = *(_DWORD *)&p_m_bPreventNameBasedLookup->m_Storage;
    if ( *(int *)&p_m_bPreventNameBasedLookup[1].m_Storage >= 0 )
    {
      if ( v4 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
        *(_DWORD *)&p_m_bPreventNameBasedLookup->m_Storage = 0;
      }
      p_m_bPreventNameBasedLookup->m_pAttribute = nullptr;
    }
  }
  CDmElement::~CDmElement(this);
}

//------------------------------------------------------------------------------
// Address: 0x00680880
// Name: _dynamic_initializer_for__CDmeParticleFunction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeParticleFunction::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeParticleFunction::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeParticleFunction pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeParticleFunction::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006808E0
// Name: _dynamic_initializer_for__CDmeParticleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeParticleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeParticleOperator::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeParticleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeParticleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00680940
// Name: _dynamic_initializer_for__CDmeParticleChild::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeParticleChild::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeParticleChild::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeParticleChild pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeParticleChild::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006809A0
// Name: _dynamic_initializer_for__CDmeParticleSystemDefinition::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeParticleSystemDefinition::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeParticleSystemDefinition::s_Allocator,
    blockSize: 276,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeParticleSystemDefinition pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeParticleSystemDefinition::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00683140
// Name: _dynamic_atexit_destructor_for__CDmeParticleFunction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeParticleFunction::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeParticleFunction::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00683150
// Name: _dynamic_atexit_destructor_for__CDmeParticleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeParticleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeParticleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00683160
// Name: _dynamic_atexit_destructor_for__CDmeParticleChild::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeParticleChild::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeParticleChild::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00683170
// Name: _dynamic_atexit_destructor_for__CDmeParticleSystemDefinition::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeParticleSystemDefinition::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeParticleSystemDefinition::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005C4190
// Name: class CDmeEditorAttributeInfo __near * CreateElement<class CDmeEditorAttributeInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *__cdecl CreateElement<CDmeEditorAttributeInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorAttributeInfo::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeEditorAttributeInfo::m_classType) )
    return (CDmeEditorAttributeInfo *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005C41F0
// Name: class CDmeEditorIntChoicesInfo __near * CreateElement<class CDmeEditorIntChoicesInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorIntChoicesInfo *__cdecl CreateElement<CDmeEditorIntChoicesInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorIntChoicesInfo::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeEditorIntChoicesInfo::m_classType) )
    return (CDmeEditorIntChoicesInfo *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005C4250
// Name: class CDmeEditorBoolChoicesInfo __near * CreateElement<class CDmeEditorBoolChoicesInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorBoolChoicesInfo *__cdecl CreateElement<CDmeEditorBoolChoicesInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorBoolChoicesInfo::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeEditorBoolChoicesInfo::m_classType) )
    return (CDmeEditorBoolChoicesInfo *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005C42B0
// Name: class CDmeEditorStringChoicesInfo __near * CreateElement<class CDmeEditorStringChoicesInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorStringChoicesInfo *__cdecl CreateElement<CDmeEditorStringChoicesInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorStringChoicesInfo::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeEditorStringChoicesInfo::m_classType) )
    return (CDmeEditorStringChoicesInfo *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005C4310
// Name: class CDmeEditorChoicesInfo __near * CreateElement<class CDmeEditorChoicesInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *__cdecl CreateElement<CDmeEditorChoicesInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorChoicesInfo::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeEditorChoicesInfo::m_classType) )
    return (CDmeEditorChoicesInfo *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x006808B0
// Name: _dynamic_initializer_for__g_CDmeParticleFunction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeParticleFunction_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeParticleFunction_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006808C0
// Name: _dynamic_initializer_for__g_CDmeParticleFunction_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeParticleFunction_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeParticleFunction_Helper,
           classname: "DmeParticleFunction",
           pFactory: &g_CDmeParticleFunction_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x00680910
// Name: _dynamic_initializer_for__g_CDmeParticleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeParticleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeParticleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680920
// Name: _dynamic_initializer_for__g_CDmeParticleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeParticleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeParticleOperator_Helper,
           classname: "DmeParticleOperator",
           pFactory: &g_CDmeParticleOperator_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x00680970
// Name: _dynamic_initializer_for__g_CDmeParticleChild_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeParticleChild_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeParticleChild_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680980
// Name: _dynamic_initializer_for__g_CDmeParticleChild_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeParticleChild_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeParticleChild_Helper,
           classname: "DmeParticleChild",
           pFactory: &g_CDmeParticleChild_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006809D0
// Name: _dynamic_initializer_for__g_CDmeParticleSystemDefinition_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeParticleSystemDefinition_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeParticleSystemDefinition_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006809E0
// Name: _dynamic_initializer_for__g_CDmeParticleSystemDefinition_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeParticleSystemDefinition_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeParticleSystemDefinition_Helper,
           classname: "DmeParticleSystemDefinition",
           pFactory: &g_CDmeParticleSystemDefinition_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x00680A00
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x00680A30
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x00680A60
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00680A80
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x00680AD0
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x00680AE0
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00683180
// Name: _dynamic_atexit_destructor_for__g_CDmeParticleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeParticleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeParticleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00683190
// Name: _dynamic_atexit_destructor_for__g_CDmeParticleChild_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeParticleChild_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeParticleChild_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006831A0
// Name: _dynamic_atexit_destructor_for__g_CDmeParticleSystemDefinition_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeParticleSystemDefinition_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeParticleSystemDefinition_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006831B0
// Name: _dynamic_atexit_destructor_for__g_CDmeParticleFunction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeParticleFunction_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeParticleFunction_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006831C0
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x006831D0
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x006831E0
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x006831F0
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00683200
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
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&emptyMapping.m_ActToSeqHash);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104D35A0
// Name: public: virtual void CDmeParticleFunction::OnElementUnserialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleFunction::OnElementUnserialized(CDmeParticleFunction *this)
{
  this->m_bSkipNextResolve = true;
}

//------------------------------------------------------------------------------
// Address: 0x104D35B0
// Name: RemoveObsoleteAttributes
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveObsoleteAttributes(CDmElement *pElement, const DmxElementUnpackStructure_t *pUnpack)
{
  CDmAttribute *Attribute; // edi
  CDmAttribute *m_pNext; // ebx
  const DmxElementUnpackStructure_t *v4; // esi
  const char *Name; // eax

  Attribute = CDmElement::FirstAttribute(this: pElement);
  if ( Attribute != nullptr )
  {
    do
    {
      m_pNext = Attribute->m_pNext;
      if ( !CDmAttribute::IsStandard(this: Attribute) && (Attribute->m_nFlags & 0x200) == 0 )
      {
        v4 = pUnpack;
        if ( pUnpack->m_pAttributeName != nullptr )
        {
          while ( 1 )
          {
            Name = CDmAttribute::GetName(this: Attribute);
            if ( _V_stricmp(s1: v4->m_pAttributeName, s2: Name) == 0 )
              break;
            ++v4;
            if ( v4->m_pAttributeName == nullptr )
              goto LABEL_7;
          }
        }
        else
        {
LABEL_7:
          CDmElement::RemoveAttributeByPtr(this: pElement, pAttribute: Attribute);
        }
      }
      Attribute = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D3620
// Name: public: virtual char const __near * CDmeParticleOperator::GetFunctionType(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeParticleOperator::GetFunctionType(CDmeParticleOperator *this)
{
  const char *result; // eax

  result = this->m_FunctionName.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return &var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D3630
// Name: public: virtual char const __near * CDmeParticleChild::GetFunctionType(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeParticleChild::GetFunctionType(CDmeParticleChild *this)
{
  CDmElement *v1; // eax
  const char *result; // eax

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Child.m_Storage.m_Handle);
  if ( v1 == nullptr )
    return &var;
  result = v1->m_Name.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return &var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D3840
// Name: CreateEditorAttributeInfo
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateEditorAttributeInfo(
        const char *pAttributeName@<edi>,
        char *pWidgetInfo@<eax>,
        CDmeEditorType *pEditorType)
{
  CDmeEditorAttributeInfo *v4; // esi
  const char *v5; // eax
  CDmeEditorBoolChoicesInfo *v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  CCommand parse; // [esp+8h] [ebp-50Ch] BYREF
  CUtlSymbolLarge value; // [esp+510h] [ebp-4h] BYREF

  if ( pWidgetInfo != nullptr )
  {
    CCommand::CCommand(this: &parse);
    CCommand::Tokenize(this: &parse, pCommand: pWidgetInfo, pBreakSet: nullptr);
    if ( parse.m_nArgc == 1 )
    {
      v4 = CreateElement<CDmeEditorAttributeInfo>(
             pObjectName: "field info",
             fileid: DMFILEID_INVALID,
             pObjectID: nullptr);
      CDmeEditorType::AddAttributeInfo(this: pEditorType, pAttributeName, pInfo: v4);
      v5 = &var;
      if ( parse.m_nArgc > 0 )
        v5 = parse.m_ppArgv[0];
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: v5);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v4->m_Widget.m_pAttribute, &value);
    }
    else if ( parse.m_nArgc == 2 )
    {
      v6 = nullptr;
      if ( _V_stricmp(s1: parse.m_ppArgv[0], s2: "intchoice") == 0 )
        v6 = (CDmeEditorBoolChoicesInfo *)CreateElement<CDmeEditorIntChoicesInfo>(
                                            pObjectName: "field info",
                                            fileid: DMFILEID_INVALID,
                                            pObjectID: nullptr);
      v7 = &var;
      if ( parse.m_nArgc > 0 )
        v7 = parse.m_ppArgv[0];
      if ( _V_stricmp(s1: v7, s2: "boolchoice") == 0 )
        v6 = CreateElement<CDmeEditorBoolChoicesInfo>(
               pObjectName: "field info",
               fileid: DMFILEID_INVALID,
               pObjectID: nullptr);
      v8 = &var;
      if ( parse.m_nArgc > 0 )
        v8 = parse.m_ppArgv[0];
      if ( _V_stricmp(s1: v8, s2: "stringchoice") == 0 )
        v6 = (CDmeEditorBoolChoicesInfo *)CreateElement<CDmeEditorStringChoicesInfo>(
                                            pObjectName: "field info",
                                            fileid: DMFILEID_INVALID,
                                            pObjectID: nullptr);
      v9 = &var;
      if ( parse.m_nArgc > 0 )
        v9 = parse.m_ppArgv[0];
      if ( _V_stricmp(s1: v9, s2: "elementchoice") == 0 )
        v6 = (CDmeEditorBoolChoicesInfo *)CreateElement<CDmeEditorChoicesInfo>(
                                            pObjectName: "field info",
                                            fileid: DMFILEID_INVALID,
                                            pObjectID: nullptr);
      if ( v6 != nullptr )
      {
        v10 = &var;
        if ( parse.m_nArgc > 1 )
          v10 = parse.m_ppArgv[1];
        CDmeEditorChoicesInfo::SetChoiceType(this: v6, pChoiceType: v10);
        CDmeEditorType::AddAttributeInfo(this: pEditorType, pAttributeName, pInfo: v6);
        v11 = &var;
        if ( parse.m_nArgc > 0 )
          v11 = parse.m_ppArgv[0];
        CDmaString::operator=(this: &v6->m_Widget, src: v11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D3A00
// Name: protected: void CDmeParticleSystemDefinition::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::OnConstruction(CDmeParticleSystemDefinition *this)
{
  CDmaElementArray<CDmeParticleFunction> *m_ParticleFunction; // edi
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // edi
  CExpressionCalculator *v6; // ecx
  CDmeHandle<CDmeEditorTypeDictionary,0> *p_m_hTypeDictionary; // ebx
  DmElementHandle_t BufferType; // eax
  DmElementHandle_t v9; // eax
  CDmElement *v10; // eax
  CDmeEditorType *v11; // edi
  bool v12; // al
  const DmxElementUnpackStructure_t *ParticleSystemDefinitionUnpackStructure; // eax
  const char **p_m_pDefaultString; // ebx
  const char *v15; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v17; // edi
  unsigned int v18; // eax
  CDmeEditorTypeDictionary *v19; // eax
  CDmeEditorType *v20; // [esp-4h] [ebp-4Ch]
  CUtlBuffer bufParse; // [esp+Ch] [ebp-3Ch] BYREF
  CDmeHandle<CDmeEditorTypeDictionary,0> *v22; // [esp+3Ch] [ebp-Ch]
  DmAttributeType_t type; // [esp+40h] [ebp-8h]
  CDmeEditorType *pEditorType; // [esp+44h] [ebp-4h]

  m_ParticleFunction = this->m_ParticleFunction;
  this->m_ParticleFunction[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "renderers",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: this->m_ParticleFunction);
  CDmAttribute::SetElementTypeSymbol(
    this: m_ParticleFunction->m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "operators",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[1]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[1].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[2].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "initializers",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[2]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[2].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[3].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "emitters",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[3]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[3].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[4].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "children",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[4]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[4].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[5].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "forces",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[5]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[5].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[6].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "constraints",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[6]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[6].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_bPreventNameBasedLookup.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "preventNameBasedLookup",
                                                   type: AT_BOOL,
                                                   pMemory: &this->m_bPreventNameBasedLookup);
  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorTypeDictionary::m_classType.u.m_Id,
         a3: "particleSystemDefinitionDict",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeEditorTypeDictionary::m_classType) )
    v6 = (CExpressionCalculator *)v5;
  else
    v6 = nullptr;
  p_m_hTypeDictionary = &this->m_hTypeDictionary;
  v22 = &this->m_hTypeDictionary;
  if ( v6 != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeEditorTypeDictionary,0>::Set(this: &this->m_hTypeDictionary, h: BufferType);
  v9 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorType::m_classType.u.m_Id,
         a3: "DmeParticleSystemDefinition",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9);
  v11 = (CDmeEditorType *)v10;
  if ( v10 == nullptr || (v12 = v10->IsA(this: v10, a2: CDmeEditorType::m_classType), pEditorType = v11, !v12) )
    pEditorType = nullptr;
  ParticleSystemDefinitionUnpackStructure = CParticleSystemMgr::GetParticleSystemDefinitionUnpackStructure(this: g_pParticleSystemMgr);
  if ( ParticleSystemDefinitionUnpackStructure->m_pAttributeName != nullptr )
  {
    p_m_pDefaultString = &ParticleSystemDefinitionUnpackStructure->m_pDefaultString;
    do
    {
      CreateEditorAttributeInfo(
        pAttributeName: *(p_m_pDefaultString - 1),
        pWidgetInfo: (char *)p_m_pDefaultString[6],
        pEditorType);
      v15 = *(p_m_pDefaultString - 1);
      type = (DmAttributeType_t)p_m_pDefaultString[1];
      Attribute = CDmElement::FindAttribute(this, pAttributeName: v15);
      if ( Attribute != nullptr )
        v17 = type == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr;
      else
        v17 = CDmElement::CreateAttribute(this, pAttributeName: v15, type);
      if ( *p_m_pDefaultString != nullptr )
      {
        if ( (int)std::char_traits<char>::length(str: *p_m_pDefaultString) >= 1 )
          v18 = std::char_traits<char>::length(str: *p_m_pDefaultString);
        else
          v18 = 1;
        CUtlBuffer::CUtlBuffer(this: &bufParse, pBuffer: (unsigned __int8 *)*p_m_pDefaultString, nSize: v18, nFlags: 9u);
        CDmAttribute::Unserialize(this: v17, buf: &bufParse);
        if ( bufParse.m_Memory.m_nGrowSize >= 0 && bufParse.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufParse.m_Memory.m_pMemory);
      }
      p_m_pDefaultString += 11;
    }
    while ( *(p_m_pDefaultString - 1) != nullptr );
    p_m_hTypeDictionary = v22;
  }
  v20 = pEditorType;
  v19 = (CDmeEditorTypeDictionary *)g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_hTypeDictionary->m_handle);
  CDmeEditorTypeDictionary::AddEditorType(this: v19, pEditorType: v20);
}

//------------------------------------------------------------------------------
// Address: 0x104D3D00
// Name: public: void CDmeParticleSystemDefinition::RecompileParticleSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::RecompileParticleSystem(CDmeParticleSystemDefinition *this)
{
  const char *v2; // esi
  bool v3; // al
  IDataModel_vtbl *v4; // ebx
  int BufferType; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-30h] BYREF

  v2 = g_pDataModel->GetDefaultEncoding(this: g_pDataModel, a2: "pcf");
  v3 = g_pDataModel->IsEncodingBinary(this: g_pDataModel, a2: v2);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: !v3);
  v4 = g_pDataModel->__vftable;
  BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
  if ( v4->Serialize(this: g_pDataModel, a2: &buf, a3: v2, a4: "pcf", a5: (DmElementHandle_t)BufferType) )
    CParticleSystemMgr::ReadParticleConfigFile(
      this: g_pParticleSystemMgr,
      &buf,
      bPrecache: true,
      bDecommitTempMemory: true,
      pFileName: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x104D3DB0
// Name: public: void CDmeParticleFunction::AddMissingFields(struct DmxElementUnpackStructure_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleFunction::AddMissingFields(
        CDmeParticleFunction *this,
        const DmxElementUnpackStructure_t *pUnpack)
{
  CDmeParticleFunction *v2; // esi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmAttribute *v4; // eax
  DmElementHandle_t v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // edi
  CExpressionCalculator *v8; // ecx
  const char *m_pAsString; // eax
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  DmElementHandle_t v12; // edi
  bool v13; // al
  const char **p_m_pDefaultString; // ebx
  const char *v15; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v17; // esi
  unsigned int v18; // eax
  CDmeEditorTypeDictionary *v19; // eax
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-48h]
  CUtlBuffer bufParse; // [esp+Ch] [ebp-38h] BYREF
  CDmeParticleFunction *v22; // [esp+3Ch] [ebp-8h]
  DmElementHandle_t value; // [esp+40h] [ebp-4h] BYREF
  const DmxElementUnpackStructure_t *pUnpacka; // [esp+4Ch] [ebp+8h]

  v2 = this;
  GetElement = g_pDataModel->GetElement;
  m_Handle = this->m_hTypeDictionary.m_Storage.m_Handle;
  v22 = this;
  v4 = (CDmAttribute *)GetElement(this: g_pDataModel, a2: m_Handle);
  DestroyElement(pElement: v4, depth: TD_DEEP);
  v5 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorTypeDictionary::m_classType.u.m_Id,
         a3: "particleFunctionDict",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  v7 = v6;
  if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeEditorTypeDictionary::m_classType) )
    v8 = (CExpressionCalculator *)v7;
  else
    v8 = nullptr;
  if ( v8 != nullptr )
    value = CCodecBuffer_Block::GetBufferType(this: v8);
  else
    value = DMELEMENT_HANDLE_INVALID;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: v2->m_hTypeDictionary.m_pAttribute, &value);
  m_pAsString = v2->m_Type.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  v10 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
          a1: g_pDataModel,
          a2: (CUtlSymbolLarge)CDmeEditorType::m_classType.u.m_Id,
          a3: m_pAsString,
          a4: DMFILEID_INVALID,
          a5: nullptr);
  v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
  v12 = (DmElementHandle_t)v11;
  if ( v11 == nullptr || (v13 = v11->IsA(this: v11, a2: CDmeEditorType::m_classType), value = v12, !v13) )
    value = 0;
  if ( pUnpack->m_pAttributeName != nullptr )
  {
    p_m_pDefaultString = &pUnpack->m_pDefaultString;
    do
    {
      CreateEditorAttributeInfo(
        pAttributeName: *(p_m_pDefaultString - 1),
        pWidgetInfo: (char *)p_m_pDefaultString[6],
        pEditorType: (CDmeEditorType *)value);
      if ( !CDmElement::HasAttribute(this: v2, pAttributeName: *(p_m_pDefaultString - 1), type: AT_UNKNOWN) )
      {
        v15 = *(p_m_pDefaultString - 1);
        pUnpacka = (const DmxElementUnpackStructure_t *)p_m_pDefaultString[1];
        Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: v15);
        if ( Attribute != nullptr )
          v17 = pUnpacka == (const DmxElementUnpackStructure_t *)(Attribute->m_nFlags & 0x1F) ? Attribute : nullptr;
        else
          v17 = CDmElement::CreateAttribute(this: v2, pAttributeName: v15, type: (DmAttributeType_t)pUnpacka);
        if ( *p_m_pDefaultString != nullptr )
        {
          v18 = std::char_traits<char>::length(str: *p_m_pDefaultString);
          CUtlBuffer::CUtlBuffer(
            this: &bufParse,
            pBuffer: (unsigned __int8 *)*p_m_pDefaultString,
            nSize: v18,
            nFlags: 9u);
          CDmAttribute::Unserialize(this: v17, buf: &bufParse);
          if ( bufParse.m_Memory.m_nGrowSize >= 0 && bufParse.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufParse.m_Memory.m_pMemory);
        }
        v2 = v22;
      }
      p_m_pDefaultString += 11;
    }
    while ( *(p_m_pDefaultString - 1) != nullptr );
  }
  v19 = (CDmeEditorTypeDictionary *)g_pDataModel->GetElement(
                                      this: g_pDataModel,
                                      a2: v2->m_hTypeDictionary.m_Storage.m_Handle);
  CDmeEditorTypeDictionary::AddEditorType(this: v19, pEditorType: (CDmeEditorType *)value);
}

//------------------------------------------------------------------------------
// Address: 0x104D3FA0
// Name: public: virtual void CDmeParticleFunction::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleFunction::Resolve(CDmeParticleFunction *this)
{
  CDmAttribute *Attribute; // eax
  IDataModel_vtbl *v3; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t i; // edi
  CDmElement *m_pOwner; // esi

  if ( this->m_bSkipNextResolve )
  {
    this->m_bSkipNextResolve = false;
  }
  else
  {
    Attribute = CDmElement::FirstAttribute(this);
    if ( Attribute != nullptr )
    {
      while ( SLOBYTE(Attribute->m_nFlags) >= 0 )
      {
        Attribute = Attribute->m_pNext;
        if ( Attribute == nullptr )
          return;
      }
      v3 = g_pDataModel->__vftable;
      BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
      for ( i = v3->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
            i != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
            i = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: i) )
      {
        m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: i)->m_pOwner;
        if ( m_pOwner != nullptr
          && m_pOwner->IsA(this: m_pOwner, a2: CDmeParticleSystemDefinition::m_classType)
          && m_pOwner->m_fileId == this->m_fileId )
        {
          CDmeParticleSystemDefinition::RecompileParticleSystem(this: (CDmeParticleSystemDefinition *)m_pOwner);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D4060
// Name: public: virtual void CDmeParticleSystemDefinition::OnElementUnserialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::OnElementUnserialized(CDmeParticleSystemDefinition *this)
{
  CDmeParticleSystemDefinition *v1; // edi
  const DmxElementUnpackStructure_t *ParticleSystemDefinitionUnpackStructure; // eax
  ParticleFunctionType_t v3; // esi
  CUtlVector<IParticleOperatorDefinition *,CUtlMemory<IParticleOperatorDefinition *,int> > *AvailableParticleOperatorList; // ebx
  char *v5; // eax
  int v6; // ecx
  CDmElement *v7; // eax
  CDmeParticleFunction *v8; // edi
  const DmxElementUnpackStructure_t *v9; // eax
  IParticleOperatorDefinition *v10; // ecx
  IParticleOperatorDefinition_vtbl *v11; // edx
  int v12; // esi
  const char *Name; // eax
  const DmxElementUnpackStructure_t *v14; // eax
  IParticleOperatorDefinition *v15; // esi
  const DmxElementUnpackStructure_t *v16; // eax
  const char *v17; // [esp-4h] [ebp-28h]
  int nCount; // [esp+10h] [ebp-14h]
  char *v20; // [esp+14h] [ebp-10h]
  int j; // [esp+18h] [ebp-Ch]
  int nAvailType; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v1 = this;
  ParticleSystemDefinitionUnpackStructure = CParticleSystemMgr::GetParticleSystemDefinitionUnpackStructure(this: g_pParticleSystemMgr);
  RemoveObsoleteAttributes(pElement: v1, pUnpack: ParticleSystemDefinitionUnpackStructure);
  v3 = FUNCTION_RENDERER;
  i = 0;
  do
  {
    AvailableParticleOperatorList = CParticleSystemMgr::GetAvailableParticleOperatorList(
                                      this: g_pParticleSystemMgr,
                                      nWhichList: v3);
    nAvailType = AvailableParticleOperatorList->m_Size;
    v5 = (char *)v1 + 28 * v3;
    v6 = 0;
    v20 = v5;
    nCount = *((_DWORD *)v5 + 20);
    j = 0;
    if ( nCount <= 0 )
      goto LABEL_18;
    while ( 1 )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*((_DWORD *)v5 + 17) + 4 * v6));
      v8 = (CDmeParticleFunction *)v7;
      if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmeParticleFunction::m_classType) )
        v8 = nullptr;
      if ( v3 == FUNCTION_CHILDREN )
      {
        v9 = (const DmxElementUnpackStructure_t *)(*(int (__thiscall **)(IParticleOperatorDefinition *))(**(_DWORD **)AvailableParticleOperatorList->m_Memory.m_pMemory + 8))(a1: *AvailableParticleOperatorList->m_Memory.m_pMemory);
        RemoveObsoleteAttributes(pElement: v8, pUnpack: v9);
        v10 = *AvailableParticleOperatorList->m_Memory.m_pMemory;
        v11 = v10->__vftable;
      }
      else
      {
        v12 = 0;
        if ( nAvailType <= 0 )
          goto LABEL_16;
        while ( 1 )
        {
          v17 = AvailableParticleOperatorList->m_Memory.m_pMemory[v12]->GetName(this: AvailableParticleOperatorList->m_Memory.m_pMemory[v12]);
          Name = CDmAttribute::GetName(this: (CDmAttribute *)v8);
          if ( _V_stricmp(s1: Name, s2: v17) == 0 )
            break;
          if ( ++v12 >= nAvailType )
            goto LABEL_16;
        }
        v14 = AvailableParticleOperatorList->m_Memory.m_pMemory[v12]->GetUnpackStructure(this: AvailableParticleOperatorList->m_Memory.m_pMemory[v12]);
        RemoveObsoleteAttributes(pElement: v8, pUnpack: v14);
        v15 = AvailableParticleOperatorList->m_Memory.m_pMemory[v12];
        v11 = v15->__vftable;
        v10 = v15;
      }
      v16 = (const DmxElementUnpackStructure_t *)((int (__fastcall *)(IParticleOperatorDefinition *))v11->GetUnpackStructure)(a1: v10);
      CDmeParticleFunction::AddMissingFields(this: v8, pUnpack: v16);
LABEL_16:
      v3 = i;
      v6 = j + 1;
      j = v6;
      if ( v6 >= nCount )
        break;
      v5 = v20;
    }
    v1 = this;
LABEL_18:
    i = ++v3;
  }
  while ( v3 < PARTICLE_FUNCTION_COUNT );
}

//------------------------------------------------------------------------------
// Address: 0x104D41B0
// Name: public: virtual void CDmeParticleSystemDefinition::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::Resolve(CDmeParticleSystemDefinition *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FirstAttribute(this);
  if ( Attribute != nullptr )
  {
    while ( SLOBYTE(Attribute->m_nFlags) >= 0 )
    {
      Attribute = Attribute->m_pNext;
      if ( Attribute == nullptr )
        return;
    }
    CDmeParticleSystemDefinition::RecompileParticleSystem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D4270
// Name: public: virtual bool CDmeParticleFunction::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeParticleFunction::IsA(CDmeParticleFunction *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D42A0
// Name: public: virtual int CDmeParticleFunction::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleFunction::GetInheritanceDepth(CDmeParticleFunction *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D4340
// Name: protected: virtual void CDmeParticleFunction::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleFunction::PerformConstruction(CDmeParticleFunction *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->m_bSkipNextResolve = false;
  this->m_hTypeDictionary.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "type_dictionary",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_hTypeDictionary);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_hTypeDictionary.m_pAttribute,
    typeSymbol: CDmeEditorTypeDictionary::m_classType);
  this->m_hTypeDictionary.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x104D4420
// Name: public: virtual bool CDmeParticleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeParticleOperator::IsA(CDmeParticleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeParticleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D4450
// Name: public: virtual int CDmeParticleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleOperator::GetInheritanceDepth(CDmeParticleOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeParticleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D4510
// Name: protected: virtual void CDmeParticleOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleOperator::PerformConstruction(CDmeParticleOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->m_bSkipNextResolve = false;
  this->m_hTypeDictionary.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "type_dictionary",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_hTypeDictionary);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_hTypeDictionary.m_pAttribute,
    typeSymbol: CDmeEditorTypeDictionary::m_classType);
  this->m_hTypeDictionary.m_pAttribute->m_nFlags |= 0x8040u;
  this->m_FunctionName.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "functionName",
                                        type: AT_STRING,
                                        pMemory: &this->m_FunctionName);
}

//------------------------------------------------------------------------------
// Address: 0x104D4600
// Name: public: virtual bool CDmeParticleChild::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeParticleChild::IsA(CDmeParticleChild *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeParticleChild::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D4630
// Name: public: virtual int CDmeParticleChild::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleChild::GetInheritanceDepth(CDmeParticleChild *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeParticleChild::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D46F0
// Name: protected: virtual void CDmeParticleChild::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleChild::PerformConstruction(CDmeParticleChild *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->m_bSkipNextResolve = false;
  this->m_hTypeDictionary.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "type_dictionary",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_hTypeDictionary);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_hTypeDictionary.m_pAttribute,
    typeSymbol: CDmeEditorTypeDictionary::m_classType);
  this->m_hTypeDictionary.m_pAttribute->m_nFlags |= 0x8040u;
  this->m_Child.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "child",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Child);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_Child.m_pAttribute,
    typeSymbol: CDmeParticleSystemDefinition::m_classType);
  this->m_Child.m_pAttribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x104D47D0
// Name: protected: CDmeParticleSystemDefinition::CDmeParticleSystemDefinition(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeParticleSystemDefinition *__thiscall CDmeParticleSystemDefinition::CDmeParticleSystemDefinition(
        CDmeParticleSystemDefinition *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaElementArray<CDmeParticleFunction> *m_ParticleFunction; // esi
  int i; // ebx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeParticleSystemDefinition_vtbl *)&CDmeParticleSystemDefinition::`vftable';
  m_ParticleFunction = this->m_ParticleFunction;
  for ( i = 6; i >= 0; --i )
    CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: m_ParticleFunction++);
  this->m_bPreventNameBasedLookup.m_pAttribute = nullptr;
  this->m_bPreventNameBasedLookup.m_Storage = false;
  this->m_hTypeDictionary.m_handle = DMELEMENT_HANDLE_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104D4830
// Name: public: virtual bool CDmeParticleSystemDefinition::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeParticleSystemDefinition::IsA(CDmeParticleSystemDefinition *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeParticleSystemDefinition::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D4860
// Name: public: virtual int CDmeParticleSystemDefinition::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleSystemDefinition::GetInheritanceDepth(
        CDmeParticleSystemDefinition *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeParticleSystemDefinition::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D48A0
// Name: protected: virtual int CDmeParticleSystemDefinition::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleSystemDefinition::AllocatedSize(CDmeParticleSystemDefinition *this)
{
  return 276;
}

//------------------------------------------------------------------------------
// Address: 0x104D48B0
// Name: protected: virtual void CDmeParticleSystemDefinition::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::PerformDestruction(CDmeParticleSystemDefinition *this)
{
  CDmAttribute *v2; // eax

  v2 = (CDmAttribute *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hTypeDictionary.m_handle);
  DestroyElement(pElement: v2, depth: TD_DEEP);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x104D48E0
// Name: protected: virtual void CDmeParticleSystemDefinition::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::PerformConstruction(CDmeParticleSystemDefinition *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeParticleSystemDefinition::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x104D48F0
// Name: protected: virtual CDmeParticleSystemDefinition::~CDmeParticleSystemDefinition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::~CDmeParticleSystemDefinition(CDmeParticleSystemDefinition *this)
{
  CDmeElementRefHelper *p_m_hTypeDictionary; // ecx
  CDmaVar<bool> *p_m_bPreventNameBasedLookup; // esi
  void *v4; // eax
  int i; // [esp+Ch] [ebp-4h]

  this->__vftable = (CDmeParticleSystemDefinition_vtbl *)&CDmeParticleSystemDefinition::`vftable';
  p_m_hTypeDictionary = &this->m_hTypeDictionary;
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: p_m_hTypeDictionary,
      hElement: *(_DWORD *)p_m_hTypeDictionary,
      handleType: HT_WEAK);
  p_m_bPreventNameBasedLookup = &this->m_bPreventNameBasedLookup;
  for ( i = 6; i >= 0; --i )
  {
    p_m_bPreventNameBasedLookup = (CDmaVar<bool> *)((char *)p_m_bPreventNameBasedLookup - 28);
    p_m_bPreventNameBasedLookup[1].m_pAttribute = nullptr;
    if ( *(int *)&p_m_bPreventNameBasedLookup[1].m_Storage >= 0 )
    {
      if ( *(_DWORD *)&p_m_bPreventNameBasedLookup->m_Storage != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&p_m_bPreventNameBasedLookup->m_Storage);
        *(_DWORD *)&p_m_bPreventNameBasedLookup->m_Storage = 0;
      }
      p_m_bPreventNameBasedLookup->m_pAttribute = nullptr;
    }
    v4 = *(void **)&p_m_bPreventNameBasedLookup->m_Storage;
    *(_DWORD *)&p_m_bPreventNameBasedLookup[2].m_Storage = *(_DWORD *)&p_m_bPreventNameBasedLookup->m_Storage;
    if ( *(int *)&p_m_bPreventNameBasedLookup[1].m_Storage >= 0 )
    {
      if ( v4 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
        *(_DWORD *)&p_m_bPreventNameBasedLookup->m_Storage = 0;
      }
      p_m_bPreventNameBasedLookup->m_pAttribute = nullptr;
    }
  }
  CDmElement::~CDmElement(this);
}

//------------------------------------------------------------------------------
// Address: 0x104F0790
// Name: protected: virtual int CDmeParticleFunction::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleFunction::AllocatedSize(CDmeSound *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x104F6020
// Name: protected: virtual int CDmeParticleOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleOperator::AllocatedSize(CDmeParticleOperator *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x105C6AB0
// Name: _dynamic_initializer_for__CDmeParticleFunction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeParticleFunction::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeParticleFunction::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeParticleFunction pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeParticleFunction::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6B10
// Name: _dynamic_initializer_for__CDmeParticleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeParticleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeParticleOperator::s_Allocator,
    blockSize: 0x5Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeParticleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeParticleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6B70
// Name: _dynamic_initializer_for__CDmeParticleChild::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeParticleChild::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeParticleChild::s_Allocator,
    blockSize: 0x60u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeParticleChild pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeParticleChild::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6BD0
// Name: _dynamic_initializer_for__CDmeParticleSystemDefinition::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeParticleSystemDefinition::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeParticleSystemDefinition::s_Allocator,
    blockSize: 0x114u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeParticleSystemDefinition pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeParticleSystemDefinition::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCBB0
// Name: _dynamic_atexit_destructor_for__CDmeParticleFunction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeParticleFunction::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeParticleFunction::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCBC0
// Name: _dynamic_atexit_destructor_for__CDmeParticleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeParticleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeParticleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCBD0
// Name: _dynamic_atexit_destructor_for__CDmeParticleChild::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeParticleChild::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeParticleChild::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCBE0
// Name: _dynamic_atexit_destructor_for__CDmeParticleSystemDefinition::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeParticleSystemDefinition::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeParticleSystemDefinition::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x104D3660
// Name: class CDmeEditorAttributeInfo __near * CreateElement<class CDmeEditorAttributeInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *__cdecl CreateElement<CDmeEditorAttributeInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorAttributeInfo::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeEditorAttributeInfo::m_classType) )
    return (CDmeEditorAttributeInfo *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104D36C0
// Name: class CDmeEditorIntChoicesInfo __near * CreateElement<class CDmeEditorIntChoicesInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorIntChoicesInfo *__cdecl CreateElement<CDmeEditorIntChoicesInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorIntChoicesInfo::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeEditorIntChoicesInfo::m_classType) )
    return (CDmeEditorIntChoicesInfo *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104D3720
// Name: class CDmeEditorBoolChoicesInfo __near * CreateElement<class CDmeEditorBoolChoicesInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorBoolChoicesInfo *__cdecl CreateElement<CDmeEditorBoolChoicesInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorBoolChoicesInfo::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeEditorBoolChoicesInfo::m_classType) )
    return (CDmeEditorBoolChoicesInfo *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104D3780
// Name: class CDmeEditorStringChoicesInfo __near * CreateElement<class CDmeEditorStringChoicesInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorStringChoicesInfo *__cdecl CreateElement<CDmeEditorStringChoicesInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorStringChoicesInfo::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeEditorStringChoicesInfo::m_classType) )
    return (CDmeEditorStringChoicesInfo *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104D37E0
// Name: class CDmeEditorChoicesInfo __near * CreateElement<class CDmeEditorChoicesInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *__cdecl CreateElement<CDmeEditorChoicesInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeEditorChoicesInfo::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeEditorChoicesInfo::m_classType) )
    return (CDmeEditorChoicesInfo *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x105C6AE0
// Name: _dynamic_initializer_for__g_CDmeParticleFunction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeParticleFunction_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeParticleFunction_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6AF0
// Name: _dynamic_initializer_for__g_CDmeParticleFunction_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeParticleFunction_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeParticleFunction_Helper,
           classname: "DmeParticleFunction",
           pFactory: &g_CDmeParticleFunction_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x105C6B40
// Name: _dynamic_initializer_for__g_CDmeParticleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeParticleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeParticleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6B50
// Name: _dynamic_initializer_for__g_CDmeParticleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeParticleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeParticleOperator_Helper,
           classname: "DmeParticleOperator",
           pFactory: &g_CDmeParticleOperator_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x105C6BA0
// Name: _dynamic_initializer_for__g_CDmeParticleChild_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeParticleChild_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeParticleChild_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6BB0
// Name: _dynamic_initializer_for__g_CDmeParticleChild_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeParticleChild_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeParticleChild_Helper,
           classname: "DmeParticleChild",
           pFactory: &g_CDmeParticleChild_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x105C6C00
// Name: _dynamic_initializer_for__g_CDmeParticleSystemDefinition_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeParticleSystemDefinition_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeParticleSystemDefinition_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6C10
// Name: _dynamic_initializer_for__g_CDmeParticleSystemDefinition_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeParticleSystemDefinition_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeParticleSystemDefinition_Helper,
           classname: "DmeParticleSystemDefinition",
           pFactory: &g_CDmeParticleSystemDefinition_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x105CCBF0
// Name: _dynamic_atexit_destructor_for__g_CDmeParticleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeParticleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeParticleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCC00
// Name: _dynamic_atexit_destructor_for__g_CDmeParticleChild_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeParticleChild_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeParticleChild_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCC10
// Name: _dynamic_atexit_destructor_for__g_CDmeParticleSystemDefinition_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeParticleSystemDefinition_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeParticleSystemDefinition_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCC20
// Name: _dynamic_atexit_destructor_for__g_CDmeParticleFunction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeParticleFunction_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeParticleFunction_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050FD00
// Name: protected: virtual int CDmeParticleFunction::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleFunction::AllocatedSize(CDmeSound *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x005F18A0
// Name: public: virtual void CDmeParticleFunction::OnElementUnserialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleFunction::OnElementUnserialized(CDmeParticleFunction *this)
{
  this->m_bSkipNextResolve = true;
}

//------------------------------------------------------------------------------
// Address: 0x005F18B0
// Name: RemoveObsoleteAttributes
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveObsoleteAttributes(CDmElement *pElement, const DmxElementUnpackStructure_t *pUnpack)
{
  CDmAttribute *Attribute; // edi
  CDmAttribute *m_pNext; // ebx
  const DmxElementUnpackStructure_t *v4; // esi
  const char *Name; // eax

  Attribute = CDmElement::FirstAttribute(this: pElement);
  if ( Attribute != nullptr )
  {
    do
    {
      m_pNext = Attribute->m_pNext;
      if ( !CDmAttribute::IsStandard(this: Attribute) && (Attribute->m_nFlags & 0x200) == 0 )
      {
        v4 = pUnpack;
        if ( pUnpack->m_pAttributeName != nullptr )
        {
          while ( 1 )
          {
            Name = CDmAttribute::GetName(this: Attribute);
            if ( _V_stricmp(s1: v4->m_pAttributeName, s2: Name) == 0 )
              break;
            ++v4;
            if ( v4->m_pAttributeName == nullptr )
              goto LABEL_7;
          }
        }
        else
        {
LABEL_7:
          CDmElement::RemoveAttributeByPtr(this: pElement, pAttribute: Attribute);
        }
      }
      Attribute = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F1920
// Name: public: virtual char const __near * CDmeParticleOperator::GetFunctionType(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeParticleOperator::GetFunctionType(CDmeParticleOperator *this)
{
  const char *result; // eax

  result = this->m_FunctionName.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F1930
// Name: public: virtual char const __near * CDmeParticleChild::GetFunctionType(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeParticleChild::GetFunctionType(CDmeParticleChild *this)
{
  int v1; // eax
  const char *result; // eax

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Child.m_Storage.m_Handle);
  if ( v1 == 0 )
    return defaultValue;
  result = *(const char **)(v1 + 20);
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F1B40
// Name: CreateEditorAttributeInfo
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateEditorAttributeInfo(
        const char *pAttributeName@<edi>,
        const char *pWidgetInfo@<eax>,
        CDmeEditorType *pEditorType)
{
  CDmeEditorAttributeInfo *v4; // esi
  const char *v5; // eax
  CDmeEditorBoolChoicesInfo *v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  CCommand parse; // [esp+8h] [ebp-50Ch] BYREF
  CUtlSymbolLarge value; // [esp+510h] [ebp-4h] BYREF

  if ( pWidgetInfo != nullptr )
  {
    CCommand::CCommand(this: &parse);
    CCommand::Tokenize(this: &parse, pCommand: pWidgetInfo, pBreakSet: nullptr);
    if ( parse.m_nArgc == 1 )
    {
      v4 = CreateElement<CDmeEditorAttributeInfo>(
             pObjectName: "field info",
             fileid: DMFILEID_INVALID,
             pObjectID: nullptr);
      CDmeEditorType::AddAttributeInfo(this: pEditorType, pAttributeName, pInfo: v4);
      v5 = defaultValue;
      if ( parse.m_nArgc > 0 )
        v5 = parse.m_ppArgv[0];
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 200))(
        a1: g_pDataModel.u,
        a2: &value,
        a3: v5);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v4->m_Widget.m_pAttribute, &value);
    }
    else if ( parse.m_nArgc == 2 )
    {
      v6 = nullptr;
      if ( _V_stricmp(s1: parse.m_ppArgv[0], s2: "intchoice") == 0 )
        v6 = (CDmeEditorBoolChoicesInfo *)CreateElement<CDmeEditorIntChoicesInfo>(
                                            pObjectName: "field info",
                                            fileid: DMFILEID_INVALID,
                                            pObjectID: nullptr);
      v7 = defaultValue;
      if ( parse.m_nArgc > 0 )
        v7 = parse.m_ppArgv[0];
      if ( _V_stricmp(s1: v7, s2: "boolchoice") == 0 )
        v6 = CreateElement<CDmeEditorBoolChoicesInfo>(
               pObjectName: "field info",
               fileid: DMFILEID_INVALID,
               pObjectID: nullptr);
      v8 = defaultValue;
      if ( parse.m_nArgc > 0 )
        v8 = parse.m_ppArgv[0];
      if ( _V_stricmp(s1: v8, s2: "stringchoice") == 0 )
        v6 = (CDmeEditorBoolChoicesInfo *)CreateElement<CDmeEditorStringChoicesInfo>(
                                            pObjectName: "field info",
                                            fileid: DMFILEID_INVALID,
                                            pObjectID: nullptr);
      v9 = defaultValue;
      if ( parse.m_nArgc > 0 )
        v9 = parse.m_ppArgv[0];
      if ( _V_stricmp(s1: v9, s2: "elementchoice") == 0 )
        v6 = (CDmeEditorBoolChoicesInfo *)CreateElement<CDmeEditorChoicesInfo>(
                                            pObjectName: "field info",
                                            fileid: DMFILEID_INVALID,
                                            pObjectID: nullptr);
      if ( v6 != nullptr )
      {
        v10 = defaultValue;
        if ( parse.m_nArgc > 1 )
          v10 = parse.m_ppArgv[1];
        CDmeEditorChoicesInfo::SetChoiceType(this: v6, pChoiceType: v10);
        CDmeEditorType::AddAttributeInfo(this: pEditorType, pAttributeName, pInfo: v6);
        v11 = defaultValue;
        if ( parse.m_nArgc > 0 )
          v11 = parse.m_ppArgv[0];
        CDmaString::operator=(this: &v6->m_Widget, src: v11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F1D00
// Name: protected: void CDmeParticleSystemDefinition::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::OnConstruction(CDmeParticleSystemDefinition *this)
{
  CDmaElementArray<CDmeParticleFunction> *m_ParticleFunction; // edi
  int v3; // eax
  int v4; // eax
  CExpressionCalculator *v5; // edi
  CExpressionCalculator *v6; // ecx
  CDmeHandle<CDmeEditorTypeDictionary,0> *p_m_hTypeDictionary; // ebx
  DmElementHandle_t BufferType; // eax
  int v9; // eax
  int v10; // eax
  CDmeEditorType *v11; // edi
  char v12; // al
  const DmxElementUnpackStructure_t *ParticleSystemDefinitionUnpackStructure; // eax
  const char **p_m_pDefaultString; // ebx
  const char *v15; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v17; // edi
  int v18; // eax
  CDmeEditorTypeDictionary *v19; // eax
  CDmeEditorType *v20; // [esp-4h] [ebp-4Ch]
  CUtlBuffer bufParse; // [esp+Ch] [ebp-3Ch] BYREF
  CDmeHandle<CDmeEditorTypeDictionary,0> *v22; // [esp+3Ch] [ebp-Ch]
  DmAttributeType_t type; // [esp+40h] [ebp-8h]
  CDmeEditorType *pEditorType; // [esp+44h] [ebp-4h]

  m_ParticleFunction = this->m_ParticleFunction;
  this->m_ParticleFunction[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "renderers",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: this->m_ParticleFunction);
  CDmAttribute::SetElementTypeSymbol(
    this: m_ParticleFunction->m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "operators",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[1]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[1].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[2].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "initializers",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[2]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[2].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[3].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "emitters",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[3]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[3].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[4].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "children",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[4]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[4].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[5].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "forces",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[5]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[5].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_ParticleFunction[6].m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "constraints",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_ParticleFunction[6]);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ParticleFunction[6].m_pAttribute,
    typeSymbol: CDmeParticleFunction::m_classType);
  this->m_bPreventNameBasedLookup.m_pAttribute = CDmElement::AddExternalAttribute(
                                                   this,
                                                   pAttributeName: "preventNameBasedLookup",
                                                   type: AT_BOOL,
                                                   pMemory: &this->m_bPreventNameBasedLookup);
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeEditorTypeDictionary::m_classType.u,
         a3: "particleSystemDefinitionDict",
         a4: -1,
         a5: 0);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3);
  v5 = (CExpressionCalculator *)v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeEditorTypeDictionary::m_classType.u) != 0 )
  {
    v6 = v5;
  }
  else
  {
    v6 = nullptr;
  }
  p_m_hTypeDictionary = &this->m_hTypeDictionary;
  v22 = &this->m_hTypeDictionary;
  if ( v6 != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeEditorTypeDictionary,0>::Set(this: &this->m_hTypeDictionary, h: BufferType);
  v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeEditorType::m_classType.u,
         a3: "DmeParticleSystemDefinition",
         a4: -1,
         a5: 0);
  v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: v9);
  v11 = (CDmeEditorType *)v10;
  if ( v10 == 0
    || (v12 = (*(int (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                a1: v10,
                a2: CDmeEditorType::m_classType.u),
        pEditorType = v11,
        v12 == 0) )
  {
    pEditorType = nullptr;
  }
  ParticleSystemDefinitionUnpackStructure = CParticleSystemMgr::GetParticleSystemDefinitionUnpackStructure(this: g_pParticleSystemMgr);
  if ( ParticleSystemDefinitionUnpackStructure->m_pAttributeName != nullptr )
  {
    p_m_pDefaultString = &ParticleSystemDefinitionUnpackStructure->m_pDefaultString;
    do
    {
      CreateEditorAttributeInfo(
        pAttributeName: *(p_m_pDefaultString - 1),
        pWidgetInfo: p_m_pDefaultString[6],
        pEditorType);
      v15 = *(p_m_pDefaultString - 1);
      type = (DmAttributeType_t)p_m_pDefaultString[1];
      Attribute = CDmElement::FindAttribute(this, pAttributeName: v15);
      if ( Attribute != nullptr )
        v17 = type == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr;
      else
        v17 = CDmElement::CreateAttribute(this, pAttributeName: v15, type);
      if ( *p_m_pDefaultString != nullptr )
      {
        if ( _V_strlen(str: *p_m_pDefaultString) >= 1 )
          v18 = _V_strlen(str: *p_m_pDefaultString);
        else
          v18 = 1;
        CUtlBuffer::CUtlBuffer(this: &bufParse, pBuffer: *p_m_pDefaultString, nSize: v18, nFlags: 9);
        CDmAttribute::Unserialize(this: v17, buf: &bufParse);
        if ( bufParse.m_Memory.m_nGrowSize >= 0 && bufParse.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufParse.m_Memory.m_pMemory);
      }
      p_m_pDefaultString += 11;
    }
    while ( *(p_m_pDefaultString - 1) != nullptr );
    p_m_hTypeDictionary = v22;
  }
  v20 = pEditorType;
  v19 = (CDmeEditorTypeDictionary *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                      a1: g_pDataModel.u,
                                      a2: p_m_hTypeDictionary->m_handle);
  CDmeEditorTypeDictionary::AddEditorType(this: v19, pEditorType: v20);
}

//------------------------------------------------------------------------------
// Address: 0x005F2000
// Name: public: void CDmeParticleSystemDefinition::RecompileParticleSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::RecompileParticleSystem(CDmeParticleSystemDefinition *this)
{
  int v2; // esi
  char v3; // al
  int v4; // ebx
  int BufferType; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-30h] BYREF

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 124))(
         a1: g_pDataModel.u,
         a2: "pcf");
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 136))(
         a1: g_pDataModel.u,
         a2: v2);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: v3 == 0);
  v4 = *(_DWORD *)g_pDataModel.u.m_Id;
  BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlBuffer *, int, const char *, int))(v4 + 156))(
         a1: g_pDataModel.u,
         a2: &buf,
         a3: v2,
         a4: "pcf",
         a5: BufferType) != 0 )
    CParticleSystemMgr::ReadParticleConfigFile(
      this: g_pParticleSystemMgr,
      &buf,
      bPrecache: true,
      bDecommitTempMemory: true,
      pFileName: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x005F20B0
// Name: public: void CDmeParticleFunction::AddMissingFields(struct DmxElementUnpackStructure_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleFunction::AddMissingFields(
        CDmeParticleFunction *this,
        const DmxElementUnpackStructure_t *pUnpack)
{
  CDmeParticleFunction *v2; // esi
  int (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  CDmAttribute *v4; // eax
  int v5; // eax
  int v6; // eax
  CExpressionCalculator *v7; // edi
  CExpressionCalculator *v8; // ecx
  const char *m_pAsString; // eax
  int v10; // eax
  int v11; // eax
  DmElementHandle_t v12; // edi
  char v13; // al
  const char **p_m_pDefaultString; // ebx
  const char *v15; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v17; // esi
  int v18; // eax
  CDmeEditorTypeDictionary *v19; // eax
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-48h]
  CUtlBuffer bufParse; // [esp+Ch] [ebp-38h] BYREF
  CDmeParticleFunction *v22; // [esp+3Ch] [ebp-8h]
  DmElementHandle_t value; // [esp+40h] [ebp-4h] BYREF
  const DmxElementUnpackStructure_t *pUnpacka; // [esp+4Ch] [ebp+8h]

  v2 = this;
  v3 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
  m_Handle = this->m_hTypeDictionary.m_Storage.m_Handle;
  v22 = this;
  v4 = (CDmAttribute *)((int (__thiscall *)(_DWORD, _DWORD))v3)(
                         a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                         a2: m_Handle);
  DestroyElement(pElement: v4, depth: TD_DEEP);
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeEditorTypeDictionary::m_classType.u,
         a3: "particleFunctionDict",
         a4: -1,
         a5: 0);
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v5);
  v7 = (CExpressionCalculator *)v6;
  if ( v6 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
         a1: v6,
         a2: CDmeEditorTypeDictionary::m_classType.u) != 0 )
  {
    v8 = v7;
  }
  else
  {
    v8 = nullptr;
  }
  if ( v8 != nullptr )
    value = CCodecBuffer_Block::GetBufferType(this: v8);
  else
    value = DMELEMENT_HANDLE_INVALID;
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: v2->m_hTypeDictionary.m_pAttribute, &value);
  m_pAsString = v2->m_Type.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
          a1: g_pDataModel.u,
          a2: CDmeEditorType::m_classType.u,
          a3: m_pAsString,
          a4: -1,
          a5: 0);
  v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: v10);
  v12 = v11;
  if ( v11 == 0
    || (v13 = (*(int (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
                a1: v11,
                a2: CDmeEditorType::m_classType.u),
        value = v12,
        v13 == 0) )
  {
    value = 0;
  }
  if ( pUnpack->m_pAttributeName != nullptr )
  {
    p_m_pDefaultString = &pUnpack->m_pDefaultString;
    do
    {
      CreateEditorAttributeInfo(
        pAttributeName: *(p_m_pDefaultString - 1),
        pWidgetInfo: p_m_pDefaultString[6],
        pEditorType: (CDmeEditorType *)value);
      if ( !CDmElement::HasAttribute(this: v2, pAttributeName: *(p_m_pDefaultString - 1), type: AT_UNKNOWN) )
      {
        v15 = *(p_m_pDefaultString - 1);
        pUnpacka = (const DmxElementUnpackStructure_t *)p_m_pDefaultString[1];
        Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: v15);
        if ( Attribute != nullptr )
          v17 = pUnpacka == (const DmxElementUnpackStructure_t *)(Attribute->m_nFlags & 0x1F) ? Attribute : nullptr;
        else
          v17 = CDmElement::CreateAttribute(this: v2, pAttributeName: v15, type: (DmAttributeType_t)pUnpacka);
        if ( *p_m_pDefaultString != nullptr )
        {
          v18 = _V_strlen(str: *p_m_pDefaultString);
          CUtlBuffer::CUtlBuffer(this: &bufParse, pBuffer: *p_m_pDefaultString, nSize: v18, nFlags: 9);
          CDmAttribute::Unserialize(this: v17, buf: &bufParse);
          if ( bufParse.m_Memory.m_nGrowSize >= 0 && bufParse.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufParse.m_Memory.m_pMemory);
        }
        v2 = v22;
      }
      p_m_pDefaultString += 11;
    }
    while ( *(p_m_pDefaultString - 1) != nullptr );
  }
  v19 = (CDmeEditorTypeDictionary *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                      a1: g_pDataModel.u,
                                      a2: v2->m_hTypeDictionary.m_Storage.m_Handle);
  CDmeEditorTypeDictionary::AddEditorType(this: v19, pEditorType: (CDmeEditorType *)value);
}

//------------------------------------------------------------------------------
// Address: 0x005F22A0
// Name: public: virtual void CDmeParticleFunction::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleFunction::Resolve(CDmeParticleFunction *this)
{
  CDmAttribute *Attribute; // eax
  int v3; // esi
  int BufferType; // eax
  int i; // edi
  int v6; // esi

  if ( this->m_bSkipNextResolve )
  {
    this->m_bSkipNextResolve = false;
  }
  else
  {
    Attribute = CDmElement::FirstAttribute(this);
    if ( Attribute != nullptr )
    {
      while ( SLOBYTE(Attribute->m_nFlags) >= 0 )
      {
        Attribute = Attribute->m_pNext;
        if ( Attribute == nullptr )
          return;
      }
      v3 = *(_DWORD *)g_pDataModel.u.m_Id;
      BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
      for ( i = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v3 + 436))(
                  a1: g_pDataModel.u,
                  a2: BufferType);
            i != 0;
            i = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                  a1: g_pDataModel.u,
                  a2: i) )
      {
        v6 = *(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 332))(
                           a1: g_pDataModel.u,
                           a2: i)
                       + 8);
        if ( v6 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeParticleSystemDefinition::m_classType.u) != 0
          && *(_DWORD *)(v6 + 56) == this->m_fileId )
        {
          CDmeParticleSystemDefinition::RecompileParticleSystem(this: (CDmeParticleSystemDefinition *)v6);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F2360
// Name: public: virtual void CDmeParticleSystemDefinition::OnElementUnserialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::OnElementUnserialized(CDmeParticleSystemDefinition *this)
{
  CDmeParticleSystemDefinition *v1; // edi
  const DmxElementUnpackStructure_t *ParticleSystemDefinitionUnpackStructure; // eax
  ParticleFunctionType_t v3; // esi
  CParticleSystemMgr *AvailableParticleOperatorList; // ebx
  char *v5; // eax
  int v6; // ecx
  int v7; // eax
  CDmeParticleFunction *v8; // edi
  const DmxElementUnpackStructure_t *v9; // eax
  IParticleOperatorDefinition *v10; // ecx
  IParticleOperatorDefinition_vtbl *v11; // edx
  int v12; // esi
  const char *Name; // eax
  const DmxElementUnpackStructure_t *v14; // eax
  IParticleOperatorDefinition *v15; // esi
  const DmxElementUnpackStructure_t *v16; // eax
  const char *v17; // [esp-4h] [ebp-28h]
  int nCount; // [esp+10h] [ebp-14h]
  char *v20; // [esp+14h] [ebp-10h]
  int j; // [esp+18h] [ebp-Ch]
  int nAvailType; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v1 = this;
  ParticleSystemDefinitionUnpackStructure = CParticleSystemMgr::GetParticleSystemDefinitionUnpackStructure(this: g_pParticleSystemMgr);
  RemoveObsoleteAttributes(pElement: v1, pUnpack: ParticleSystemDefinitionUnpackStructure);
  v3 = FUNCTION_RENDERER;
  i = 0;
  do
  {
    AvailableParticleOperatorList = CParticleSystemMgr::GetAvailableParticleOperatorList(
                                      this: g_pParticleSystemMgr,
                                      nWhichList: v3);
    nAvailType = AvailableParticleOperatorList->m_ParticleOperators[0].m_Size;
    v5 = (char *)v1 + 28 * v3;
    v6 = 0;
    v20 = v5;
    nCount = *((_DWORD *)v5 + 20);
    j = 0;
    if ( nCount <= 0 )
      goto LABEL_18;
    while ( 1 )
    {
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(*((_DWORD *)v5 + 17) + 4 * v6));
      v8 = (CDmeParticleFunction *)v7;
      if ( v7 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeParticleFunction::m_classType.u) == 0 )
      {
        v8 = nullptr;
      }
      if ( v3 == FUNCTION_CHILDREN )
      {
        v9 = (const DmxElementUnpackStructure_t *)(*(int (__thiscall **)(IParticleOperatorDefinition *))(**(_DWORD **)AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory + 8))(a1: *AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory);
        RemoveObsoleteAttributes(pElement: v8, pUnpack: v9);
        v10 = *AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory;
        v11 = v10->__vftable;
      }
      else
      {
        v12 = 0;
        if ( nAvailType <= 0 )
          goto LABEL_16;
        while ( 1 )
        {
          v17 = AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory[v12]->GetName(this: AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory[v12]);
          Name = CDmAttribute::GetName(this: (CDmAttribute *)v8);
          if ( _V_stricmp(s1: Name, s2: v17) == 0 )
            break;
          if ( ++v12 >= nAvailType )
            goto LABEL_16;
        }
        v14 = AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory[v12]->GetUnpackStructure(this: AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory[v12]);
        RemoveObsoleteAttributes(pElement: v8, pUnpack: v14);
        v15 = AvailableParticleOperatorList->m_ParticleOperators[0].m_Memory.m_pMemory[v12];
        v11 = v15->__vftable;
        v10 = v15;
      }
      v16 = (const DmxElementUnpackStructure_t *)((int (__fastcall *)(IParticleOperatorDefinition *))v11->GetUnpackStructure)(a1: v10);
      CDmeParticleFunction::AddMissingFields(this: v8, pUnpack: v16);
LABEL_16:
      v3 = i;
      v6 = j + 1;
      j = v6;
      if ( v6 >= nCount )
        break;
      v5 = v20;
    }
    v1 = this;
LABEL_18:
    i = ++v3;
  }
  while ( v3 < PARTICLE_FUNCTION_COUNT );
}

//------------------------------------------------------------------------------
// Address: 0x005F24B0
// Name: public: virtual void CDmeParticleSystemDefinition::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::Resolve(CDmeParticleSystemDefinition *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FirstAttribute(this);
  if ( Attribute != nullptr )
  {
    while ( SLOBYTE(Attribute->m_nFlags) >= 0 )
    {
      Attribute = Attribute->m_pNext;
      if ( Attribute == nullptr )
        return;
    }
    CDmeParticleSystemDefinition::RecompileParticleSystem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F2570
// Name: public: virtual bool CDmeParticleFunction::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeParticleFunction::IsA(CDmeParticleFunction *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F25A0
// Name: public: virtual int CDmeParticleFunction::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleFunction::GetInheritanceDepth(CDmeParticleFunction *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F2640
// Name: protected: virtual void CDmeParticleFunction::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleFunction::PerformConstruction(CDmeParticleFunction *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_bSkipNextResolve = false;
  this->m_hTypeDictionary.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "type_dictionary",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_hTypeDictionary);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_hTypeDictionary.m_pAttribute,
    typeSymbol: CDmeEditorTypeDictionary::m_classType);
  this->m_hTypeDictionary.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x005F2720
// Name: public: virtual bool CDmeParticleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeParticleOperator::IsA(CDmeParticleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeParticleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F2750
// Name: public: virtual int CDmeParticleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleOperator::GetInheritanceDepth(CDmeParticleOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeParticleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F2810
// Name: protected: virtual void CDmeParticleOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleOperator::PerformConstruction(CDmeParticleOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_bSkipNextResolve = false;
  this->m_hTypeDictionary.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "type_dictionary",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_hTypeDictionary);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_hTypeDictionary.m_pAttribute,
    typeSymbol: CDmeEditorTypeDictionary::m_classType);
  this->m_hTypeDictionary.m_pAttribute->m_nFlags |= 0x8040u;
  this->m_FunctionName.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "functionName",
                                        type: AT_STRING,
                                        pMemory: &this->m_FunctionName);
}

//------------------------------------------------------------------------------
// Address: 0x005F2900
// Name: public: virtual bool CDmeParticleChild::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeParticleChild::IsA(CDmeParticleChild *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeParticleChild::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F2930
// Name: public: virtual int CDmeParticleChild::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleChild::GetInheritanceDepth(CDmeParticleChild *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeParticleChild::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeParticleFunction::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F29F0
// Name: protected: virtual void CDmeParticleChild::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleChild::PerformConstruction(CDmeParticleChild *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_bSkipNextResolve = false;
  this->m_hTypeDictionary.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "type_dictionary",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_hTypeDictionary);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_hTypeDictionary.m_pAttribute,
    typeSymbol: CDmeEditorTypeDictionary::m_classType);
  this->m_hTypeDictionary.m_pAttribute->m_nFlags |= 0x8040u;
  this->m_Child.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "child",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Child);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_Child.m_pAttribute,
    typeSymbol: CDmeParticleSystemDefinition::m_classType);
  this->m_Child.m_pAttribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x005F2AD0
// Name: protected: CDmeParticleSystemDefinition::CDmeParticleSystemDefinition(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeParticleSystemDefinition *__thiscall CDmeParticleSystemDefinition::CDmeParticleSystemDefinition(
        CDmeParticleSystemDefinition *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaElementArray<CDmeParticleFunction> *m_ParticleFunction; // esi
  int i; // ebx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeParticleSystemDefinition_vtbl *)&CDmeParticleSystemDefinition::`vftable';
  m_ParticleFunction = this->m_ParticleFunction;
  for ( i = 6; i >= 0; --i )
    CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: m_ParticleFunction++);
  this->m_bPreventNameBasedLookup.m_pAttribute = nullptr;
  this->m_bPreventNameBasedLookup.m_Storage = false;
  this->m_hTypeDictionary.m_handle = DMELEMENT_HANDLE_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005F2B30
// Name: public: virtual bool CDmeParticleSystemDefinition::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeParticleSystemDefinition::IsA(CDmeParticleSystemDefinition *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeParticleSystemDefinition::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F2B60
// Name: public: virtual int CDmeParticleSystemDefinition::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleSystemDefinition::GetInheritanceDepth(
        CDmeParticleSystemDefinition *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeParticleSystemDefinition::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F2BA0
// Name: protected: virtual int CDmeParticleSystemDefinition::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeParticleSystemDefinition::AllocatedSize(CDmeParticleSystemDefinition *this)
{
  return 276;
}

//------------------------------------------------------------------------------
// Address: 0x005F2BB0
// Name: protected: virtual void CDmeParticleSystemDefinition::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::PerformDestruction(CDmeParticleSystemDefinition *this)
{
  CDmAttribute *v2; // eax

  v2 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hTypeDictionary.m_handle);
  DestroyElement(pElement: v2, depth: TD_DEEP);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005F2BE0
// Name: protected: virtual void CDmeParticleSystemDefinition::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::PerformConstruction(CDmeParticleSystemDefinition *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeParticleSystemDefinition::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F2BF0
// Name: protected: virtual CDmeParticleSystemDefinition::~CDmeParticleSystemDefinition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeParticleSystemDefinition::~CDmeParticleSystemDefinition(CDmeParticleSystemDefinition *this)
{
  CDmeElementRefHelper *p_m_hTypeDictionary; // ecx
  CDmaVar<bool> *p_m_bPreventNameBasedLookup; // esi
  void *v4; // eax
  int i; // [esp+Ch] [ebp-4h]

  this->__vftable = (CDmeParticleSystemDefinition_vtbl *)&CDmeParticleSystemDefinition::`vftable';
  p_m_hTypeDictionary = &this->m_hTypeDictionary;
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(
      this: p_m_hTypeDictionary,
      hElement: *(_DWORD *)p_m_hTypeDictionary,
      handleType: HT_WEAK);
  p_m_bPreventNameBasedLookup = &this->m_bPreventNameBasedLookup;
  for ( i = 6; i >= 0; --i )
  {
    p_m_bPreventNameBasedLookup = (CDmaVar<bool> *)((char *)p_m_bPreventNameBasedLookup - 28);
    p_m_bPreventNameBasedLookup[1].m_pAttribute = nullptr;
    if ( *(int *)&p_m_bPreventNameBasedLookup[1].m_Storage >= 0 )
    {
      if ( *(_DWORD *)&p_m_bPreventNameBasedLookup->m_Storage != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&p_m_bPreventNameBasedLookup->m_Storage);
        *(_DWORD *)&p_m_bPreventNameBasedLookup->m_Storage = 0;
      }
      p_m_bPreventNameBasedLookup->m_pAttribute = nullptr;
    }
    v4 = *(void **)&p_m_bPreventNameBasedLookup->m_Storage;
    *(_DWORD *)&p_m_bPreventNameBasedLookup[2].m_Storage = *(_DWORD *)&p_m_bPreventNameBasedLookup->m_Storage;
    if ( *(int *)&p_m_bPreventNameBasedLookup[1].m_Storage >= 0 )
    {
      if ( v4 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
        *(_DWORD *)&p_m_bPreventNameBasedLookup->m_Storage = 0;
      }
      p_m_bPreventNameBasedLookup->m_pAttribute = nullptr;
    }
  }
  CDmElement::~CDmElement(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B26E0
// Name: _dynamic_initializer_for__CDmeParticleFunction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeParticleFunction::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeParticleFunction::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeParticleFunction pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeParticleFunction::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2740
// Name: _dynamic_initializer_for__CDmeParticleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeParticleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeParticleOperator::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeParticleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeParticleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B27A0
// Name: _dynamic_initializer_for__CDmeParticleChild::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeParticleChild::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeParticleChild::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeParticleChild pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeParticleChild::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2800
// Name: _dynamic_initializer_for__CDmeParticleSystemDefinition::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeParticleSystemDefinition::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeParticleSystemDefinition::s_Allocator,
    blockSize: 276,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeParticleSystemDefinition pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeParticleSystemDefinition::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5C40
// Name: _dynamic_atexit_destructor_for__CDmeParticleFunction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeParticleFunction::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeParticleFunction::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5C50
// Name: _dynamic_atexit_destructor_for__CDmeParticleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeParticleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeParticleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5C60
// Name: _dynamic_atexit_destructor_for__CDmeParticleChild::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeParticleChild::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeParticleChild::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5C70
// Name: _dynamic_atexit_destructor_for__CDmeParticleSystemDefinition::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeParticleSystemDefinition::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeParticleSystemDefinition::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F1960
// Name: class CDmeEditorAttributeInfo __near * CreateElement<class CDmeEditorAttributeInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *__cdecl CreateElement<CDmeEditorAttributeInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, const UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeEditorAttributeInfo::m_classType.u,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeEditorAttributeInfo::m_classType.u) != 0 )
  {
    return (CDmeEditorAttributeInfo *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F19C0
// Name: class CDmeEditorIntChoicesInfo __near * CreateElement<class CDmeEditorIntChoicesInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorIntChoicesInfo *__cdecl CreateElement<CDmeEditorIntChoicesInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, const UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeEditorIntChoicesInfo::m_classType.u,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeEditorIntChoicesInfo::m_classType.u) != 0 )
  {
    return (CDmeEditorIntChoicesInfo *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F1A20
// Name: class CDmeEditorBoolChoicesInfo __near * CreateElement<class CDmeEditorBoolChoicesInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorBoolChoicesInfo *__cdecl CreateElement<CDmeEditorBoolChoicesInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, const UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeEditorBoolChoicesInfo::m_classType.u,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeEditorBoolChoicesInfo::m_classType.u) != 0 )
  {
    return (CDmeEditorBoolChoicesInfo *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F1A80
// Name: class CDmeEditorStringChoicesInfo __near * CreateElement<class CDmeEditorStringChoicesInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorStringChoicesInfo *__cdecl CreateElement<CDmeEditorStringChoicesInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, const UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeEditorStringChoicesInfo::m_classType.u,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeEditorStringChoicesInfo::m_classType.u) != 0 )
  {
    return (CDmeEditorStringChoicesInfo *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F1AE0
// Name: class CDmeEditorChoicesInfo __near * CreateElement<class CDmeEditorChoicesInfo>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *__cdecl CreateElement<CDmeEditorChoicesInfo>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, const UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeEditorChoicesInfo::m_classType.u,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeEditorChoicesInfo::m_classType.u) != 0 )
  {
    return (CDmeEditorChoicesInfo *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B2710
// Name: _dynamic_initializer_for__g_CDmeParticleFunction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeParticleFunction_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeParticleFunction_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2720
// Name: _dynamic_initializer_for__g_CDmeParticleFunction_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeParticleFunction_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeParticleFunction_Helper,
           classname: "DmeParticleFunction",
           pFactory: &g_CDmeParticleFunction_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006B2770
// Name: _dynamic_initializer_for__g_CDmeParticleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeParticleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeParticleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2780
// Name: _dynamic_initializer_for__g_CDmeParticleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeParticleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeParticleOperator_Helper,
           classname: "DmeParticleOperator",
           pFactory: &g_CDmeParticleOperator_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006B27D0
// Name: _dynamic_initializer_for__g_CDmeParticleChild_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeParticleChild_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeParticleChild_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B27E0
// Name: _dynamic_initializer_for__g_CDmeParticleChild_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeParticleChild_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeParticleChild_Helper,
           classname: "DmeParticleChild",
           pFactory: &g_CDmeParticleChild_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006B2830
// Name: _dynamic_initializer_for__g_CDmeParticleSystemDefinition_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeParticleSystemDefinition_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeParticleSystemDefinition_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2840
// Name: _dynamic_initializer_for__g_CDmeParticleSystemDefinition_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeParticleSystemDefinition_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeParticleSystemDefinition_Helper,
           classname: "DmeParticleSystemDefinition",
           pFactory: &g_CDmeParticleSystemDefinition_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006B5C80
// Name: _dynamic_atexit_destructor_for__g_CDmeParticleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeParticleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeParticleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5C90
// Name: _dynamic_atexit_destructor_for__g_CDmeParticleChild_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeParticleChild_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeParticleChild_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5CA0
// Name: _dynamic_atexit_destructor_for__g_CDmeParticleSystemDefinition_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeParticleSystemDefinition_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeParticleSystemDefinition_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5CB0
// Name: _dynamic_atexit_destructor_for__g_CDmeParticleFunction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeParticleFunction_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeParticleFunction_Factory.m_CallBackList);
}

} // namespace sceneviewer
