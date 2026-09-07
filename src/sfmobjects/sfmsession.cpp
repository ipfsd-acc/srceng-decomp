// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: sfmobjects/sfmsession.cpp
// Functions: 10
// ============================================================

#include "sfmobjects\sfmsession.h"

//------------------------------------------------------------------------------
// Address: 0x00538E10
// Name: public: CSFMSession::CSFMSession(void)
// Source: json
//------------------------------------------------------------------------------
CSFMSession *__thiscall CSFMSession::CSFMSession(CSFMSession *this)
{
  this->m_hRoot.m_handle = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hRoot, h: DMELEMENT_HANDLE_INVALID);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00538E30
// Name: public: void CSFMSession::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::Shutdown(CSFMSession *this)
{
  CDmElement *v2; // eax

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle) != nullptr
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle)->m_fileId != DMFILEID_INVALID )
  {
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
    g_pDataModel->RemoveFileId(this: g_pDataModel, a2: v2->m_fileId);
    CDmeHandle<CDmElement,0>::Set(this: &this->m_hRoot, h: DMELEMENT_HANDLE_INVALID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00538E90
// Name: public: class CDmeGameModel __near * CSFMSession::CreateEditorGameModel(struct studiohdr_t __near *,class Vector const __near &,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CSFMSession::CreateEditorGameModel(
        CSFMSession *this,
        studiohdr_t *hdr,
        const Vector *vecOrigin,
        Quaternion *qOrientation)
{
  studiohdr_t *v4; // ebx
  char *name; // edi
  CDmElement *v7; // eax
  DmElementHandle_t v8; // eax
  CDmElement *v9; // eax
  CDmeGameModel *v10; // esi
  CDmAttribute *Attribute; // eax
  CDmeTransform *Transform; // eax
  CDmeTransform *v13; // edi
  char pRelativeModelsFileName[260]; // [esp+Ch] [ebp-304h] BYREF
  char pBaseName[256]; // [esp+110h] [ebp-200h] BYREF
  char pGameModelName[256]; // [esp+210h] [ebp-100h] BYREF

  v4 = hdr;
  name = hdr->name;
  V_FileBase(in: hdr->name, out: pBaseName, maxlen: 256);
  V_snprintf(pDest: pGameModelName, maxLen: 256, pFormat: "%s_GameModel", pBaseName);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
  v8 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeGameModel::m_classType.u.m_Id,
         a3: pGameModelName,
         a4: v7->m_fileId,
         a5: nullptr);
  v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8);
  v10 = (CDmeGameModel *)v9;
  if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmeGameModel::m_classType) )
    v10 = nullptr;
  V_ComposeFileName(path: "models", filename: name, dest: pRelativeModelsFileName, destSize: 260);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&hdr, a3: pRelativeModelsFileName);
  Attribute = CDmElement::FindAttribute(this: v10, pAttributeName: "modelName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v10, pAttributeName: "modelName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&hdr);
  }
  Transform = CDmeDag::GetTransform(this: v10);
  v13 = Transform;
  if ( Transform != nullptr )
  {
    CDmeTransform::SetPosition(this: Transform, vecPosition: vecOrigin);
    CDmeTransform::SetOrientation(this: v13, orientation: qOrientation);
  }
  CDmeGameModel::AddBones(this: v10, pStudioHdr: v4, nFirstBone: 0, nCount: v4->numbones);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00538FE0
// Name: private: void CSFMSession::CreateProgressiveRefinementSettings(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::CreateProgressiveRefinementSettings(CSFMSession *this, int pRenderSettings)
{
  int v2; // edi
  CExpressionCalculator *Value; // esi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax
  CDmAttribute *v16; // eax

  v2 = pRenderSettings;
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmElement>(
                                     this: (CDmElement *)pRenderSettings,
                                     pAttributeName: "ProgressiveRefinement");
  if ( Value == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
           a3: "ProgressiveRefinementSettings",
           a4: *(DmFileId_t *)(v2 + 56),
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    Value = (CExpressionCalculator *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
      Value = nullptr;
    if ( Value != nullptr )
      pRenderSettings = CExpressionCalculator::VariableCount(this: Value);
    else
      pRenderSettings = -1;
    Attribute = CDmElement::FindAttribute(this: (CDmElement *)v2, pAttributeName: "ProgressiveRefinement");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(
                        this: (CDmElement *)v2,
                        pAttributeName: "ProgressiveRefinement",
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pRenderSettings);
    }
  }
  HIBYTE(pRenderSettings) = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "on") == nullptr )
  {
    v7 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "on");
    if ( v7 != nullptr
      || (v7 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "on", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v7, value: (const bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "useDepthOfField") == nullptr )
  {
    v8 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "useDepthOfField");
    if ( v8 != nullptr
      || (v8 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "useDepthOfField", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v8, value: (const bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideDepthOfFieldQuality") == nullptr )
  {
    v9 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideDepthOfFieldQuality");
    if ( v9 != nullptr
      || (v9 = CDmElement::CreateAttribute(
                 this: (CDmElement *)Value,
                 pAttributeName: "overrideDepthOfFieldQuality",
                 type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v9, value: (const bool *)&pRenderSettings + 3);
    }
  }
  pRenderSettings = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideDepthOfFieldQualityValue") == nullptr )
  {
    v10 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideDepthOfFieldQualityValue");
    if ( v10 != nullptr
      || (v10 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "overrideDepthOfFieldQualityValue",
                  type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v10, value: &pRenderSettings);
    }
  }
  HIBYTE(pRenderSettings) = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "useMotionBlur") == nullptr )
  {
    v11 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "useMotionBlur");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "useMotionBlur", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v11, value: (const bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideMotionBlurQuality") == nullptr )
  {
    v12 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideMotionBlurQuality");
    if ( v12 != nullptr
      || (v12 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "overrideMotionBlurQuality",
                  type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v12, value: (const bool *)&pRenderSettings + 3);
    }
  }
  pRenderSettings = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideMotionBlurQualityValue") == nullptr )
  {
    v13 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideMotionBlurQualityValue");
    if ( v13 != nullptr
      || (v13 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "overrideMotionBlurQualityValue",
                  type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v13, value: &pRenderSettings);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "useAntialiasing") == nullptr )
  {
    v14 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "useAntialiasing");
    if ( v14 != nullptr
      || (v14 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "useAntialiasing", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v14, value: (const bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideShutterSpeed") == nullptr )
  {
    v15 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideShutterSpeed");
    if ( v15 != nullptr
      || (v15 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "overrideShutterSpeed",
                  type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v15, value: (const bool *)&pRenderSettings + 3);
    }
  }
  pRenderSettings = 1017817771;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideShutterSpeedValue") == nullptr )
  {
    v16 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideShutterSpeedValue");
    if ( v16 != nullptr
      || (v16 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "overrideShutterSpeedValue",
                  type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v16, value: (const float *)&pRenderSettings);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00539330
// Name: private: void CSFMSession::CreatePosterSettings(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::CreatePosterSettings(CSFMSession *this, int pRenderSettings)
{
  int v2; // edi
  CExpressionCalculator *Value; // esi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax

  v2 = pRenderSettings;
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmElement>(
                                     this: (CDmElement *)pRenderSettings,
                                     pAttributeName: "posterSettings");
  if ( Value == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
           a3: "posterSettings",
           a4: *(DmFileId_t *)(v2 + 56),
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    Value = (CExpressionCalculator *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
      Value = nullptr;
    if ( Value != nullptr )
      pRenderSettings = CExpressionCalculator::VariableCount(this: Value);
    else
      pRenderSettings = -1;
    Attribute = CDmElement::FindAttribute(this: (CDmElement *)v2, pAttributeName: "posterSettings");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(
                        this: (CDmElement *)v2,
                        pAttributeName: "posterSettings",
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pRenderSettings);
    }
  }
  pRenderSettings = 1920;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "width") == nullptr )
  {
    v7 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "width");
    if ( v7 != nullptr
      || (v7 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "width", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v7, value: &pRenderSettings);
    }
  }
  pRenderSettings = 1080;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "height") == nullptr )
  {
    v8 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "height");
    if ( v8 != nullptr
      || (v8 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "height", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v8, value: &pRenderSettings);
    }
  }
  pRenderSettings = 300;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "DPI") == nullptr )
  {
    v9 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "DPI");
    if ( v9 != nullptr
      || (v9 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "DPI", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v9, value: &pRenderSettings);
    }
  }
  HIBYTE(pRenderSettings) = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "constrainAspect") == nullptr )
  {
    v10 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "constrainAspect");
    if ( v10 != nullptr
      || (v10 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "constrainAspect", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v10, value: (const bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "heightInPixels") == nullptr )
  {
    v11 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "heightInPixels");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "heightInPixels", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v11, value: (const bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "widthInPixels") == nullptr )
  {
    v12 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "widthInPixels");
    if ( v12 != nullptr
      || (v12 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "widthInPixels", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v12, value: (const bool *)&pRenderSettings + 3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00539580
// Name: private: void CSFMSession::CreateMovieSettings(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::CreateMovieSettings(CSFMSession *this, int pRenderSettings)
{
  int v2; // edi
  CExpressionCalculator *Value; // esi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax

  v2 = pRenderSettings;
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmElement>(
                                     this: (CDmElement *)pRenderSettings,
                                     pAttributeName: "movieSettings");
  if ( Value == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
           a3: "movieSettings",
           a4: *(DmFileId_t *)(v2 + 56),
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    Value = (CExpressionCalculator *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
      Value = nullptr;
    if ( Value != nullptr )
      pRenderSettings = CExpressionCalculator::VariableCount(this: Value);
    else
      pRenderSettings = -1;
    Attribute = CDmElement::FindAttribute(this: (CDmElement *)v2, pAttributeName: "movieSettings");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(
                        this: (CDmElement *)v2,
                        pAttributeName: "movieSettings",
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pRenderSettings);
    }
  }
  pRenderSettings = 2;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "videoTarget") == nullptr )
  {
    v7 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "videoTarget");
    if ( v7 != nullptr
      || (v7 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "videoTarget", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v7, value: &pRenderSettings);
    }
  }
  pRenderSettings = 2;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "audioTarget") == nullptr )
  {
    v8 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "audioTarget");
    if ( v8 != nullptr
      || (v8 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "audioTarget", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v8, value: &pRenderSettings);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "stereoscopic") == nullptr )
  {
    v9 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "stereoscopic");
    if ( v9 != nullptr
      || (v9 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "stereoscopic", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v9, value: (const bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "stereoSingleFile") == nullptr )
  {
    v10 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "stereoSingleFile");
    if ( v10 != nullptr
      || (v10 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "stereoSingleFile",
                  type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v10, value: (const bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "clearDecals") == nullptr )
  {
    v11 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "clearDecals");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "clearDecals", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v11, value: (const bool *)&pRenderSettings + 3);
    }
  }
  pRenderSettings = 1280;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "width") == nullptr )
  {
    v12 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "width");
    if ( v12 != nullptr
      || (v12 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "width", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v12, value: &pRenderSettings);
    }
  }
  pRenderSettings = 720;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "height") == nullptr )
  {
    v13 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "height");
    if ( v13 != nullptr
      || (v13 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "height", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v13, value: &pRenderSettings);
    }
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pRenderSettings, a3: &pParentName);
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "filename") == nullptr )
  {
    v14 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "filename");
    if ( v14 != nullptr
      || (v14 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "filename", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: (const CUtlSymbolLarge *)&pRenderSettings);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00539860
// Name: private: void CSFMSession::CreateSharedPresetGroupSettings(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::CreateSharedPresetGroupSettings(CSFMSession *this, int pRenderSettings)
{
  int v2; // edi
  CExpressionCalculator *Value; // esi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax

  v2 = pRenderSettings;
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmElement>(
                                     this: (CDmElement *)pRenderSettings,
                                     pAttributeName: "sharedPresetGroupSettings");
  if ( Value == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
           a3: "sharedPresetGroupSettings",
           a4: *(DmFileId_t *)(v2 + 56),
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    Value = (CExpressionCalculator *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
      Value = nullptr;
    if ( Value != nullptr )
      pRenderSettings = CExpressionCalculator::VariableCount(this: Value);
    else
      pRenderSettings = -1;
    Attribute = CDmElement::FindAttribute(this: (CDmElement *)v2, pAttributeName: "sharedPresetGroupSettings");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(
                        this: (CDmElement *)v2,
                        pAttributeName: "sharedPresetGroupSettings",
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pRenderSettings);
    }
  }
  v7 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "presetGroupInfos");
  if ( v7 != nullptr )
    v8 = (v7->m_nFlags & 0x1F) != 15 ? nullptr : v7;
  else
    v8 = CDmElement::CreateAttribute(
           this: (CDmElement *)Value,
           pAttributeName: "presetGroupInfos",
           type: AT_FIRST_ARRAY_TYPE);
  if ( v8 != nullptr )
    CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmePresetGroupInfo::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00539960
// Name: private: void CSFMSession::CreateRenderSettings(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::CreateRenderSettings(CSFMSession *this, int pSettings)
{
  int v2; // edi
  CExpressionCalculator *Value; // esi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax

  v2 = pSettings;
  if ( CDmElement::FindAttribute(this: (CDmElement *)pSettings, pAttributeName: "renderSettings") == nullptr )
    CDmElement::CreateAttribute(this: (CDmElement *)v2, pAttributeName: "renderSettings", type: AT_FIRST_VALUE_TYPE);
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmElement>(
                                     this: (CDmElement *)v2,
                                     pAttributeName: "renderSettings");
  if ( Value == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
           a3: "renderSettings",
           a4: *(DmFileId_t *)(v2 + 56),
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    Value = (CExpressionCalculator *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
      Value = nullptr;
    if ( Value != nullptr )
      pSettings = CExpressionCalculator::VariableCount(this: Value);
    else
      pSettings = -1;
    Attribute = CDmElement::FindAttribute(this: (CDmElement *)v2, pAttributeName: "renderSettings");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(
                        this: (CDmElement *)v2,
                        pAttributeName: "renderSettings",
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pSettings);
    }
  }
  pSettings = 1103101952;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "frameRate") == nullptr )
  {
    v7 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "frameRate");
    if ( v7 != nullptr
      || (v7 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "frameRate", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v7, value: (const float *)&pSettings);
    }
  }
  pSettings = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "lightAverage") == nullptr )
  {
    v8 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "lightAverage");
    if ( v8 != nullptr
      || (v8 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "lightAverage", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v8, value: &pSettings);
    }
  }
  pSettings = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "modelLod") == nullptr )
  {
    v9 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "modelLod");
    if ( v9 != nullptr
      || (v9 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "modelLod", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v9, value: &pSettings);
    }
  }
  HIBYTE(pSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "engineCameraEffects") == nullptr )
  {
    v10 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "engineCameraEffects");
    if ( v10 != nullptr
      || (v10 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "engineCameraEffects",
                  type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v10, value: (const bool *)&pSettings + 3);
    }
  }
  pSettings = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "ambientOcclusionMode") == nullptr )
  {
    v11 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "ambientOcclusionMode");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "ambientOcclusionMode",
                  type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v11, value: &pSettings);
    }
  }
  pSettings = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "showAmbientOcclusion") == nullptr )
  {
    v12 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "showAmbientOcclusion");
    if ( v12 != nullptr
      || (v12 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "showAmbientOcclusion",
                  type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v12, value: &pSettings);
    }
  }
  pSettings = 216;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "drawGameRenderablesMask") == nullptr )
  {
    v13 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "drawGameRenderablesMask");
    if ( v13 != nullptr
      || (v13 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "drawGameRenderablesMask",
                  type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v13, value: &pSettings);
    }
  }
  pSettings = 15;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "drawToolRenderablesMask") == nullptr )
  {
    v14 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "drawToolRenderablesMask");
    if ( v14 != nullptr
      || (v14 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "drawToolRenderablesMask",
                  type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v14, value: &pSettings);
    }
  }
  pSettings = 1065353216;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "toneMapScale") == nullptr )
  {
    v15 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "toneMapScale");
    if ( v15 != nullptr
      || (v15 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "toneMapScale", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v15, value: (const float *)&pSettings);
    }
  }
  CSFMSession::CreateProgressiveRefinementSettings(this, pRenderSettings: (int)Value);
}

//------------------------------------------------------------------------------
// Address: 0x00539CB0
// Name: public: void CSFMSession::CreateSessionSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::CreateSessionSettings(CSFMSession *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmElement *v4; // eax
  CDmElement *v5; // ebx
  CDmAttribute *Attribute; // eax
  CDmElement *v7; // eax
  CExpressionCalculator *v8; // eax
  CDmAttribute *v9; // eax
  CDmElement *v10; // eax
  CExpressionCalculator *v11; // eax
  CDmAttribute *v12; // eax
  CDmElement *v13; // eax
  CExpressionCalculator *v14; // eax
  CDmAttribute *v15; // eax
  DmElementHandle_t value; // [esp+4h] [ebp-4h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle) != nullptr )
  {
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
    v3 = CDmElement::GetValueElement<CDmElement>(this: v2, pAttributeName: "settings");
    if ( v3 == nullptr )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
      v3 = CreateElement<CDmElement>(pObjectName: "sessionSettings", fileid: v4->m_fileId, pObjectID: nullptr);
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
      value = v3 != nullptr
            ? CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3)
            : DMELEMENT_HANDLE_INVALID;
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "settings");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: v5, pAttributeName: "settings", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, &value);
      }
    }
    if ( !CDmElement::HasAttribute(this: v3, pAttributeName: "timeSelection", type: AT_UNKNOWN) )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
      v8 = (CExpressionCalculator *)CreateElement<CDmeTimeSelection>(
                                      pObjectName: "timeSelection",
                                      fileid: v7->m_fileId,
                                      pObjectID: nullptr);
      value = v8 != nullptr ? CExpressionCalculator::VariableCount(this: v8) : DMELEMENT_HANDLE_INVALID;
      v9 = CDmElement::FindAttribute(this: v3, pAttributeName: "timeSelection");
      if ( v9 != nullptr
        || (v9 = CDmElement::CreateAttribute(this: v3, pAttributeName: "timeSelection", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: v9, &value);
      }
    }
    if ( !CDmElement::HasAttribute(this: v3, pAttributeName: "graphEditorState", type: AT_UNKNOWN) )
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
      v11 = (CExpressionCalculator *)CreateElement<CDmeGraphEditorState>(
                                       pObjectName: "graphEditorState",
                                       fileid: v10->m_fileId,
                                       pObjectID: nullptr);
      value = v11 != nullptr ? CExpressionCalculator::VariableCount(this: v11) : DMELEMENT_HANDLE_INVALID;
      v12 = CDmElement::FindAttribute(this: v3, pAttributeName: "graphEditorState");
      if ( v12 != nullptr
        || (v12 = CDmElement::CreateAttribute(this: v3, pAttributeName: "graphEditorState", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: v12, &value);
      }
    }
    if ( !CDmElement::HasAttribute(this: v3, pAttributeName: "proceduralPresets", type: AT_UNKNOWN) )
    {
      v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
      v14 = (CExpressionCalculator *)CreateElement<CDmeProceduralPresetSettings>(
                                       pObjectName: "proceduralPresets",
                                       fileid: v13->m_fileId,
                                       pObjectID: nullptr);
      if ( v14 != nullptr )
        value = CExpressionCalculator::VariableCount(this: v14);
      else
        value = DMELEMENT_HANDLE_INVALID;
      v15 = CDmElement::FindAttribute(this: v3, pAttributeName: "proceduralPresets");
      if ( v15 != nullptr
        || (v15 = CDmElement::CreateAttribute(this: v3, pAttributeName: "proceduralPresets", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: v15, &value);
      }
    }
    CSFMSession::CreateRenderSettings(this, pSettings: (int)v3);
    CSFMSession::CreatePosterSettings(this, pRenderSettings: (int)v3);
    CSFMSession::CreateMovieSettings(this, pRenderSettings: (int)v3);
    CSFMSession::CreateSharedPresetGroupSettings(this, pRenderSettings: (int)v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00539F00
// Name: public: void CSFMSession::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::Init(CSFMSession *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CExpressionCalculator *v4; // esi
  DmElementHandle_t v5; // eax
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v7; // eax
  CDmElement *v8; // eax
  CDmeFilmClip *v9; // edi
  int v10; // eax
  CDmeTrack *FilmTrack; // ebx
  DmElementHandle_t v12; // eax
  CDmElement *v13; // eax
  CDmeFilmClip *v14; // edi
  int v15; // eax
  CExpressionCalculator *m_Id; // ebx
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmrElementArray<CDmElement> clipBin; // [esp+5Ch] [ebp-10h] BYREF
  CSFMSession *v26; // [esp+64h] [ebp-8h]
  CUtlSymbolLarge value; // [esp+68h] [ebp-4h] BYREF

  v26 = this;
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hRoot, h: DMELEMENT_HANDLE_INVALID);
  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
         a3: "session",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = (CExpressionCalculator *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmElement::m_classType) )
  {
    v5 = CExpressionCalculator::VariableCount(this: v4);
    CDmeHandle<CDmElement,0>::Set(this: &this->m_hRoot, h: v5);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "ifm");
    Attribute = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: (CDmElement *)v4, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v7 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeFilmClip::m_classType.u.m_Id,
           a3: "sequence",
           a4: (DmFileId_t)v4->m_stack.m_Memory.m_pMemory,
           a5: nullptr);
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7);
    v9 = (CDmeFilmClip *)v8;
    if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeFilmClip::m_classType) )
    {
      value.u.m_Id = (int)v9;
    }
    else
    {
      value.u.m_Id = 0;
      v9 = nullptr;
    }
    v10 = DmeTime_t::RoundSecondsToTMS(sec: 0x42700000u);
    CDmeClip::SetDuration(this: v9, t: (DmeTime_t)v10);
    CDmeFilmClip::CreateBookmarkSet(this: v9, pName: (int)"default set");
    FilmTrack = CDmeFilmClip::FindOrCreateFilmTrack(this: v9);
    v12 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
            a1: g_pDataModel,
            a2: (CUtlSymbolLarge)CDmeFilmClip::m_classType.u.m_Id,
            a3: "shot",
            a4: (DmFileId_t)v4->m_stack.m_Memory.m_pMemory,
            a5: nullptr);
    v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12);
    v14 = (CDmeFilmClip *)v13;
    if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmeFilmClip::m_classType) )
      v14 = nullptr;
    CDmeTrack::AddClip(this: FilmTrack, clip: v14);
    v15 = DmeTime_t::RoundSecondsToTMS(sec: 0x42700000u);
    CDmeClip::SetDuration(this: v14, t: (DmeTime_t)v15);
    CDmeFilmClip::CreateBookmarkSet(this: v14, pName: (int)"default set");
    m_Id = (CExpressionCalculator *)value.u.m_Id;
    if ( value.u.m_Id != 0 )
      value.u.m_Id = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)value.u.m_Id);
    else
      value.u.m_Id = -1;
    v17 = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "activeClip");
    if ( v17 != nullptr
      || (v17 = CDmElement::CreateAttribute(
                  this: (CDmElement *)v4,
                  pAttributeName: "activeClip",
                  type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: v17, (DmElementHandle_t *)&value);
    }
    v18 = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "miscBin");
    if ( v18 != nullptr )
      v19 = (v18->m_nFlags & 0x1F) != 15 ? nullptr : v18;
    else
      v19 = CDmElement::CreateAttribute(this: (CDmElement *)v4, pAttributeName: "miscBin", type: AT_FIRST_ARRAY_TYPE);
    if ( v19 != nullptr )
      CDmAttribute::SetElementTypeSymbol(this: v19, typeSymbol: CDmElement::m_classType);
    v20 = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "cameraBin");
    if ( v20 != nullptr )
      v21 = (v20->m_nFlags & 0x1F) != 15 ? nullptr : v20;
    else
      v21 = CDmElement::CreateAttribute(this: (CDmElement *)v4, pAttributeName: "cameraBin", type: AT_FIRST_ARRAY_TYPE);
    if ( v21 != nullptr )
      CDmAttribute::SetElementTypeSymbol(this: v21, typeSymbol: CDmeCamera::m_classType);
    v22 = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "clipBin");
    if ( v22 != nullptr )
      v23 = (v22->m_nFlags & 0x1F) != 15 ? nullptr : v22;
    else
      v23 = CDmElement::CreateAttribute(this: (CDmElement *)v4, pAttributeName: "clipBin", type: AT_FIRST_ARRAY_TYPE);
    if ( v23 != nullptr )
      CDmAttribute::SetElementTypeSymbol(this: v23, typeSymbol: CDmeClip::m_classType);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&clipBin);
    v24 = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "clipBin");
    if ( v24 != nullptr && (v24->m_nFlags & 0x1F) == 0xF )
    {
      clipBin.m_pAttribute = v24;
      clipBin.m_pStorage = (DmElementArray_t *)v24->m_pData;
    }
    else
    {
      clipBin.m_pAttribute = nullptr;
      clipBin.m_pStorage = nullptr;
    }
    if ( m_Id != nullptr )
      value.u.m_Id = CExpressionCalculator::VariableCount(this: m_Id);
    else
      value.u.m_Id = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &clipBin,
      src: (DmElementHandle_t *)&value);
    CSFMSession::CreateSessionSettings(this: v26);
  }
}

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0053F050
// Name: public: CSFMSession::CSFMSession(void)
// Source: json
//------------------------------------------------------------------------------
CSFMSession *__thiscall CSFMSession::CSFMSession(CSFMSession *this)
{
  this->m_hRoot.m_handle = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hRoot, h: DMELEMENT_HANDLE_INVALID);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0053F070
// Name: public: void CSFMSession::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::Shutdown(CSFMSession *this)
{
  CDmElement *v2; // eax

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle) != nullptr
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle)->m_fileId != DMFILEID_INVALID )
  {
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
    g_pDataModel->RemoveFileId(this: g_pDataModel, a2: v2->m_fileId);
    CDmeHandle<CDmElement,0>::Set(this: &this->m_hRoot, h: DMELEMENT_HANDLE_INVALID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053F0D0
// Name: public: class CDmeCamera __near * CSFMSession::CreateCamera(struct DmeCameraParams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CSFMSession::CreateCamera(CSFMSession *this, const DmeCameraParams_t *params)
{
  CDmElement *v2; // eax
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmeCamera *v5; // esi
  CDmeTransform *Transform; // eax
  matrix3x4_t txform; // [esp+28h] [ebp-30h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeCamera::m_classType.u.m_Id,
         a3: (const char *)params,
         a4: v2->m_fileId,
         a5: nullptr);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = (CDmeCamera *)v4;
  if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeCamera::m_classType) )
    v5 = nullptr;
  AngleMatrix(angles: &params->angles, position: &params->origin, matrix: &txform);
  Transform = CDmeDag::GetTransform(this: v5);
  if ( Transform != nullptr )
    CDmeTransform::SetTransform(this: Transform, transform: &txform);
  CDmeCamera::SetFOVx(this: v5, fov: params->fov);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0053F190
// Name: public: class CDmeGameModel __near * CSFMSession::CreateEditorGameModel(struct studiohdr_t __near *,class Vector const __near &,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
CDmeGameModel *__thiscall CSFMSession::CreateEditorGameModel(
        CSFMSession *this,
        studiohdr_t *hdr,
        const Vector *vecOrigin,
        Quaternion *qOrientation)
{
  studiohdr_t *v4; // ebx
  char *name; // edi
  CDmElement *v7; // eax
  DmElementHandle_t v8; // eax
  CDmElement *v9; // eax
  CDmeGameModel *v10; // esi
  CDmAttribute *Attribute; // eax
  CDmeTransform *Transform; // eax
  CDmeTransform *v13; // edi
  char pRelativeModelsFileName[260]; // [esp+Ch] [ebp-304h] BYREF
  char pBaseName[256]; // [esp+110h] [ebp-200h] BYREF
  char pGameModelName[256]; // [esp+210h] [ebp-100h] BYREF

  v4 = hdr;
  name = hdr->name;
  V_FileBase(in: hdr->name, out: pBaseName, maxlen: 256);
  V_snprintf(pDest: pGameModelName, maxLen: 256, pFormat: "%s_GameModel", pBaseName);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
  v8 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeGameModel::m_classType.u.m_Id,
         a3: pGameModelName,
         a4: v7->m_fileId,
         a5: nullptr);
  v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8);
  v10 = (CDmeGameModel *)v9;
  if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmeGameModel::m_classType) )
    v10 = nullptr;
  V_ComposeFileName(path: "models", filename: name, dest: pRelativeModelsFileName, destSize: 260);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&hdr, a3: pRelativeModelsFileName);
  Attribute = CDmElement::FindAttribute(this: v10, pAttributeName: "modelName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v10, pAttributeName: "modelName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&hdr);
  }
  Transform = CDmeDag::GetTransform(this: v10);
  v13 = Transform;
  if ( Transform != nullptr )
  {
    CDmeTransform::SetPosition(this: Transform, vecPosition: vecOrigin);
    CDmeTransform::SetOrientation(this: v13, orientation: qOrientation);
  }
  CDmeGameModel::AddBones(this: v10, pStudioHdr: v4, nFirstBone: 0, nCount: v4->numbones);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0053F2E0
// Name: private: void CSFMSession::CreateProgressiveRefinementSettings(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::CreateProgressiveRefinementSettings(CSFMSession *this, int pRenderSettings)
{
  int v2; // edi
  CExpressionCalculator *Value; // esi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax
  CDmAttribute *v16; // eax

  v2 = pRenderSettings;
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmElement>(
                                     this: (CDmElement *)pRenderSettings,
                                     pAttributeName: "ProgressiveRefinement");
  if ( Value == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
           a3: "ProgressiveRefinementSettings",
           a4: *(DmFileId_t *)(v2 + 56),
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    Value = (CExpressionCalculator *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
      Value = nullptr;
    if ( Value != nullptr )
      pRenderSettings = CExpressionCalculator::VariableCount(this: Value);
    else
      pRenderSettings = -1;
    Attribute = CDmElement::FindAttribute(this: (CDmElement *)v2, pAttributeName: "ProgressiveRefinement");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(
                        this: (CDmElement *)v2,
                        pAttributeName: "ProgressiveRefinement",
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pRenderSettings);
    }
  }
  HIBYTE(pRenderSettings) = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "on") == nullptr )
  {
    v7 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "on");
    if ( v7 != nullptr
      || (v7 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "on", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v7, value: (bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "useDepthOfField") == nullptr )
  {
    v8 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "useDepthOfField");
    if ( v8 != nullptr
      || (v8 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "useDepthOfField", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v8, value: (bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideDepthOfFieldQuality") == nullptr )
  {
    v9 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideDepthOfFieldQuality");
    if ( v9 != nullptr
      || (v9 = CDmElement::CreateAttribute(
                 this: (CDmElement *)Value,
                 pAttributeName: "overrideDepthOfFieldQuality",
                 type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v9, value: (bool *)&pRenderSettings + 3);
    }
  }
  pRenderSettings = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideDepthOfFieldQualityValue") == nullptr )
  {
    v10 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideDepthOfFieldQualityValue");
    if ( v10 != nullptr
      || (v10 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "overrideDepthOfFieldQualityValue",
                  type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v10, value: &pRenderSettings);
    }
  }
  HIBYTE(pRenderSettings) = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "useMotionBlur") == nullptr )
  {
    v11 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "useMotionBlur");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "useMotionBlur", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v11, value: (bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideMotionBlurQuality") == nullptr )
  {
    v12 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideMotionBlurQuality");
    if ( v12 != nullptr
      || (v12 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "overrideMotionBlurQuality",
                  type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v12, value: (bool *)&pRenderSettings + 3);
    }
  }
  pRenderSettings = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideMotionBlurQualityValue") == nullptr )
  {
    v13 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideMotionBlurQualityValue");
    if ( v13 != nullptr
      || (v13 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "overrideMotionBlurQualityValue",
                  type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v13, value: &pRenderSettings);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "useAntialiasing") == nullptr )
  {
    v14 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "useAntialiasing");
    if ( v14 != nullptr
      || (v14 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "useAntialiasing", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v14, value: (bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideShutterSpeed") == nullptr )
  {
    v15 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideShutterSpeed");
    if ( v15 != nullptr
      || (v15 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "overrideShutterSpeed",
                  type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v15, value: (bool *)&pRenderSettings + 3);
    }
  }
  pRenderSettings = 1017817771;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideShutterSpeedValue") == nullptr )
  {
    v16 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "overrideShutterSpeedValue");
    if ( v16 != nullptr
      || (v16 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "overrideShutterSpeedValue",
                  type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v16, value: (const float *)&pRenderSettings);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053F630
// Name: private: void CSFMSession::CreatePosterSettings(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::CreatePosterSettings(CSFMSession *this, int pRenderSettings)
{
  int v2; // edi
  CExpressionCalculator *Value; // esi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax

  v2 = pRenderSettings;
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmElement>(
                                     this: (CDmElement *)pRenderSettings,
                                     pAttributeName: "posterSettings");
  if ( Value == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
           a3: "posterSettings",
           a4: *(DmFileId_t *)(v2 + 56),
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    Value = (CExpressionCalculator *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
      Value = nullptr;
    if ( Value != nullptr )
      pRenderSettings = CExpressionCalculator::VariableCount(this: Value);
    else
      pRenderSettings = -1;
    Attribute = CDmElement::FindAttribute(this: (CDmElement *)v2, pAttributeName: "posterSettings");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(
                        this: (CDmElement *)v2,
                        pAttributeName: "posterSettings",
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pRenderSettings);
    }
  }
  pRenderSettings = 1920;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "width") == nullptr )
  {
    v7 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "width");
    if ( v7 != nullptr
      || (v7 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "width", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v7, value: &pRenderSettings);
    }
  }
  pRenderSettings = 1080;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "height") == nullptr )
  {
    v8 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "height");
    if ( v8 != nullptr
      || (v8 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "height", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v8, value: &pRenderSettings);
    }
  }
  pRenderSettings = 300;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "DPI") == nullptr )
  {
    v9 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "DPI");
    if ( v9 != nullptr
      || (v9 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "DPI", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v9, value: &pRenderSettings);
    }
  }
  HIBYTE(pRenderSettings) = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "constrainAspect") == nullptr )
  {
    v10 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "constrainAspect");
    if ( v10 != nullptr
      || (v10 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "constrainAspect", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v10, value: (bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "heightInPixels") == nullptr )
  {
    v11 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "heightInPixels");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "heightInPixels", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v11, value: (bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 1;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "widthInPixels") == nullptr )
  {
    v12 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "widthInPixels");
    if ( v12 != nullptr
      || (v12 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "widthInPixels", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v12, value: (bool *)&pRenderSettings + 3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053F880
// Name: private: void CSFMSession::CreateMovieSettings(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::CreateMovieSettings(CSFMSession *this, int pRenderSettings)
{
  int v2; // edi
  CExpressionCalculator *Value; // esi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax

  v2 = pRenderSettings;
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmElement>(
                                     this: (CDmElement *)pRenderSettings,
                                     pAttributeName: "movieSettings");
  if ( Value == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
           a3: "movieSettings",
           a4: *(DmFileId_t *)(v2 + 56),
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    Value = (CExpressionCalculator *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
      Value = nullptr;
    if ( Value != nullptr )
      pRenderSettings = CExpressionCalculator::VariableCount(this: Value);
    else
      pRenderSettings = -1;
    Attribute = CDmElement::FindAttribute(this: (CDmElement *)v2, pAttributeName: "movieSettings");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(
                        this: (CDmElement *)v2,
                        pAttributeName: "movieSettings",
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pRenderSettings);
    }
  }
  pRenderSettings = 2;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "videoTarget") == nullptr )
  {
    v7 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "videoTarget");
    if ( v7 != nullptr
      || (v7 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "videoTarget", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v7, value: &pRenderSettings);
    }
  }
  pRenderSettings = 2;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "audioTarget") == nullptr )
  {
    v8 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "audioTarget");
    if ( v8 != nullptr
      || (v8 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "audioTarget", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v8, value: &pRenderSettings);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "stereoscopic") == nullptr )
  {
    v9 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "stereoscopic");
    if ( v9 != nullptr
      || (v9 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "stereoscopic", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v9, value: (bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "stereoSingleFile") == nullptr )
  {
    v10 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "stereoSingleFile");
    if ( v10 != nullptr
      || (v10 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "stereoSingleFile",
                  type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v10, value: (bool *)&pRenderSettings + 3);
    }
  }
  HIBYTE(pRenderSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "clearDecals") == nullptr )
  {
    v11 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "clearDecals");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "clearDecals", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v11, value: (bool *)&pRenderSettings + 3);
    }
  }
  pRenderSettings = 1280;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "width") == nullptr )
  {
    v12 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "width");
    if ( v12 != nullptr
      || (v12 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "width", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v12, value: &pRenderSettings);
    }
  }
  pRenderSettings = 720;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "height") == nullptr )
  {
    v13 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "height");
    if ( v13 != nullptr
      || (v13 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "height", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v13, value: &pRenderSettings);
    }
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pRenderSettings, a3: &pch);
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "filename") == nullptr )
  {
    v14 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "filename");
    if ( v14 != nullptr
      || (v14 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "filename", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: (const CUtlSymbolLarge *)&pRenderSettings);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053FB60
// Name: private: void CSFMSession::CreateSharedPresetGroupSettings(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::CreateSharedPresetGroupSettings(CSFMSession *this, int pRenderSettings)
{
  int v2; // edi
  CExpressionCalculator *Value; // esi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax

  v2 = pRenderSettings;
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmElement>(
                                     this: (CDmElement *)pRenderSettings,
                                     pAttributeName: "sharedPresetGroupSettings");
  if ( Value == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
           a3: "sharedPresetGroupSettings",
           a4: *(DmFileId_t *)(v2 + 56),
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    Value = (CExpressionCalculator *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
      Value = nullptr;
    if ( Value != nullptr )
      pRenderSettings = CExpressionCalculator::VariableCount(this: Value);
    else
      pRenderSettings = -1;
    Attribute = CDmElement::FindAttribute(this: (CDmElement *)v2, pAttributeName: "sharedPresetGroupSettings");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(
                        this: (CDmElement *)v2,
                        pAttributeName: "sharedPresetGroupSettings",
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pRenderSettings);
    }
  }
  v7 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "presetGroupInfos");
  if ( v7 != nullptr )
    v8 = (v7->m_nFlags & 0x1F) != 15 ? nullptr : v7;
  else
    v8 = CDmElement::CreateAttribute(
           this: (CDmElement *)Value,
           pAttributeName: "presetGroupInfos",
           type: AT_FIRST_ARRAY_TYPE);
  if ( v8 != nullptr )
    CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmePresetGroupInfo::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0053FC60
// Name: private: void CSFMSession::CreateRenderSettings(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::CreateRenderSettings(CSFMSession *this, int pSettings)
{
  int v2; // edi
  CExpressionCalculator *Value; // esi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax

  v2 = pSettings;
  if ( CDmElement::FindAttribute(this: (CDmElement *)pSettings, pAttributeName: "renderSettings") == nullptr )
    CDmElement::CreateAttribute(this: (CDmElement *)v2, pAttributeName: "renderSettings", type: AT_FIRST_VALUE_TYPE);
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmElement>(
                                     this: (CDmElement *)v2,
                                     pAttributeName: "renderSettings");
  if ( Value == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
           a3: "renderSettings",
           a4: *(DmFileId_t *)(v2 + 56),
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    Value = (CExpressionCalculator *)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmElement::m_classType) )
      Value = nullptr;
    if ( Value != nullptr )
      pSettings = CExpressionCalculator::VariableCount(this: Value);
    else
      pSettings = -1;
    Attribute = CDmElement::FindAttribute(this: (CDmElement *)v2, pAttributeName: "renderSettings");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(
                        this: (CDmElement *)v2,
                        pAttributeName: "renderSettings",
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pSettings);
    }
  }
  pSettings = 1103101952;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "frameRate") == nullptr )
  {
    v7 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "frameRate");
    if ( v7 != nullptr
      || (v7 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "frameRate", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v7, value: (const float *)&pSettings);
    }
  }
  pSettings = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "lightAverage") == nullptr )
  {
    v8 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "lightAverage");
    if ( v8 != nullptr
      || (v8 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "lightAverage", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v8, value: &pSettings);
    }
  }
  pSettings = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "modelLod") == nullptr )
  {
    v9 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "modelLod");
    if ( v9 != nullptr
      || (v9 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "modelLod", type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v9, value: &pSettings);
    }
  }
  HIBYTE(pSettings) = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "engineCameraEffects") == nullptr )
  {
    v10 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "engineCameraEffects");
    if ( v10 != nullptr
      || (v10 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "engineCameraEffects",
                  type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: v10, value: (bool *)&pSettings + 3);
    }
  }
  pSettings = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "ambientOcclusionMode") == nullptr )
  {
    v11 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "ambientOcclusionMode");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "ambientOcclusionMode",
                  type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v11, value: &pSettings);
    }
  }
  pSettings = 0;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "showAmbientOcclusion") == nullptr )
  {
    v12 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "showAmbientOcclusion");
    if ( v12 != nullptr
      || (v12 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "showAmbientOcclusion",
                  type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v12, value: &pSettings);
    }
  }
  pSettings = 216;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "drawGameRenderablesMask") == nullptr )
  {
    v13 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "drawGameRenderablesMask");
    if ( v13 != nullptr
      || (v13 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "drawGameRenderablesMask",
                  type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v13, value: &pSettings);
    }
  }
  pSettings = 15;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "drawToolRenderablesMask") == nullptr )
  {
    v14 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "drawToolRenderablesMask");
    if ( v14 != nullptr
      || (v14 = CDmElement::CreateAttribute(
                  this: (CDmElement *)Value,
                  pAttributeName: "drawToolRenderablesMask",
                  type: AT_INT)) != nullptr )
    {
      CDmAttribute::SetValue<int>(this: v14, value: &pSettings);
    }
  }
  pSettings = 1065353216;
  if ( CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "toneMapScale") == nullptr )
  {
    v15 = CDmElement::FindAttribute(this: (CDmElement *)Value, pAttributeName: "toneMapScale");
    if ( v15 != nullptr
      || (v15 = CDmElement::CreateAttribute(this: (CDmElement *)Value, pAttributeName: "toneMapScale", type: AT_FLOAT)) != nullptr )
    {
      CDmAttribute::SetValue<float>(this: v15, value: (const float *)&pSettings);
    }
  }
  CSFMSession::CreateProgressiveRefinementSettings(this, pRenderSettings: (int)Value);
}

//------------------------------------------------------------------------------
// Address: 0x0053FFB0
// Name: public: void CSFMSession::CreateSessionSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::CreateSessionSettings(CSFMSession *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmElement *v4; // eax
  CDmElement *v5; // ebx
  CDmAttribute *Attribute; // eax
  CDmElement *v7; // eax
  CExpressionCalculator *v8; // eax
  CDmAttribute *v9; // eax
  CDmElement *v10; // eax
  CExpressionCalculator *v11; // eax
  CDmAttribute *v12; // eax
  CDmElement *v13; // eax
  CExpressionCalculator *v14; // eax
  CDmAttribute *v15; // eax
  DmElementHandle_t value; // [esp+4h] [ebp-4h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle) != nullptr )
  {
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
    v3 = CDmElement::GetValueElement<CDmElement>(this: v2, pAttributeName: "settings");
    if ( v3 == nullptr )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
      v3 = CreateElement<CDmElement>(pObjectName: "sessionSettings", fileid: v4->m_fileId, pObjectID: nullptr);
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
      value = v3 != nullptr
            ? CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3)
            : DMELEMENT_HANDLE_INVALID;
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "settings");
      if ( Attribute != nullptr
        || (Attribute = CDmElement::CreateAttribute(this: v5, pAttributeName: "settings", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, &value);
      }
    }
    if ( !CDmElement::HasAttribute(this: v3, pAttributeName: "timeSelection", type: AT_UNKNOWN) )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
      v8 = (CExpressionCalculator *)CreateElement<CDmeTimeSelection>(
                                      pObjectName: "timeSelection",
                                      fileid: v7->m_fileId,
                                      pObjectID: nullptr);
      value = v8 != nullptr ? CExpressionCalculator::VariableCount(this: v8) : DMELEMENT_HANDLE_INVALID;
      v9 = CDmElement::FindAttribute(this: v3, pAttributeName: "timeSelection");
      if ( v9 != nullptr
        || (v9 = CDmElement::CreateAttribute(this: v3, pAttributeName: "timeSelection", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: v9, &value);
      }
    }
    if ( !CDmElement::HasAttribute(this: v3, pAttributeName: "graphEditorState", type: AT_UNKNOWN) )
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
      v11 = (CExpressionCalculator *)CreateElement<CDmeGraphEditorState>(
                                       pObjectName: "graphEditorState",
                                       fileid: v10->m_fileId,
                                       pObjectID: nullptr);
      value = v11 != nullptr ? CExpressionCalculator::VariableCount(this: v11) : DMELEMENT_HANDLE_INVALID;
      v12 = CDmElement::FindAttribute(this: v3, pAttributeName: "graphEditorState");
      if ( v12 != nullptr
        || (v12 = CDmElement::CreateAttribute(this: v3, pAttributeName: "graphEditorState", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: v12, &value);
      }
    }
    if ( !CDmElement::HasAttribute(this: v3, pAttributeName: "proceduralPresets", type: AT_UNKNOWN) )
    {
      v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hRoot.m_handle);
      v14 = (CExpressionCalculator *)CreateElement<CDmeProceduralPresetSettings>(
                                       pObjectName: "proceduralPresets",
                                       fileid: v13->m_fileId,
                                       pObjectID: nullptr);
      if ( v14 != nullptr )
        value = CExpressionCalculator::VariableCount(this: v14);
      else
        value = DMELEMENT_HANDLE_INVALID;
      v15 = CDmElement::FindAttribute(this: v3, pAttributeName: "proceduralPresets");
      if ( v15 != nullptr
        || (v15 = CDmElement::CreateAttribute(this: v3, pAttributeName: "proceduralPresets", type: AT_FIRST_VALUE_TYPE)) != nullptr )
      {
        CDmAttribute::SetValue<enum DmElementHandle_t>(this: v15, &value);
      }
    }
    CSFMSession::CreateRenderSettings(this, pSettings: (int)v3);
    CSFMSession::CreatePosterSettings(this, pRenderSettings: (int)v3);
    CSFMSession::CreateMovieSettings(this, pRenderSettings: (int)v3);
    CSFMSession::CreateSharedPresetGroupSettings(this, pRenderSettings: (int)v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00540200
// Name: public: void CSFMSession::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSFMSession::Init(CSFMSession *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CExpressionCalculator *v4; // esi
  DmElementHandle_t v5; // eax
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v7; // eax
  CDmElement *v8; // eax
  CDmeFilmClip *v9; // edi
  int v10; // eax
  CDmeTrack *FilmTrack; // ebx
  DmElementHandle_t v12; // eax
  CDmElement *v13; // eax
  CDmeFilmClip *v14; // edi
  int v15; // eax
  CExpressionCalculator *m_Id; // ebx
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmrElementArray<CDmElement> clipBin; // [esp+5Ch] [ebp-10h] BYREF
  CSFMSession *v26; // [esp+64h] [ebp-8h]
  CUtlSymbolLarge value; // [esp+68h] [ebp-4h] BYREF

  v26 = this;
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hRoot, h: DMELEMENT_HANDLE_INVALID);
  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
         a3: "session",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = (CExpressionCalculator *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmElement::m_classType) )
  {
    v5 = CExpressionCalculator::VariableCount(this: v4);
    CDmeHandle<CDmElement,0>::Set(this: &this->m_hRoot, h: v5);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "ifm");
    Attribute = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: (CDmElement *)v4, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v7 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeFilmClip::m_classType.u.m_Id,
           a3: "sequence",
           a4: (DmFileId_t)v4->m_stack.m_Memory.m_pMemory,
           a5: nullptr);
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7);
    v9 = (CDmeFilmClip *)v8;
    if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeFilmClip::m_classType) )
    {
      value.u.m_Id = (int)v9;
    }
    else
    {
      value.u.m_Id = 0;
      v9 = nullptr;
    }
    v10 = DmeTime_t::RoundSecondsToTMS(sec: 0x42700000u);
    CDmeClip::SetDuration(this: v9, t: (DmeTime_t)v10);
    CDmeFilmClip::CreateBookmarkSet(this: v9, pName: (int)"default set");
    FilmTrack = CDmeFilmClip::FindOrCreateFilmTrack(this: v9);
    v12 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
            a1: g_pDataModel,
            a2: (CUtlSymbolLarge)CDmeFilmClip::m_classType.u.m_Id,
            a3: "shot",
            a4: (DmFileId_t)v4->m_stack.m_Memory.m_pMemory,
            a5: nullptr);
    v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12);
    v14 = (CDmeFilmClip *)v13;
    if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmeFilmClip::m_classType) )
      v14 = nullptr;
    CDmeTrack::AddClip(this: FilmTrack, clip: v14);
    v15 = DmeTime_t::RoundSecondsToTMS(sec: 0x42700000u);
    CDmeClip::SetDuration(this: v14, t: (DmeTime_t)v15);
    CDmeFilmClip::CreateBookmarkSet(this: v14, pName: (int)"default set");
    m_Id = (CExpressionCalculator *)value.u.m_Id;
    if ( value.u.m_Id != 0 )
      value.u.m_Id = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)value.u.m_Id);
    else
      value.u.m_Id = -1;
    v17 = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "activeClip");
    if ( v17 != nullptr
      || (v17 = CDmElement::CreateAttribute(
                  this: (CDmElement *)v4,
                  pAttributeName: "activeClip",
                  type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: v17, (DmElementHandle_t *)&value);
    }
    v18 = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "miscBin");
    if ( v18 != nullptr )
      v19 = (v18->m_nFlags & 0x1F) != 15 ? nullptr : v18;
    else
      v19 = CDmElement::CreateAttribute(this: (CDmElement *)v4, pAttributeName: "miscBin", type: AT_FIRST_ARRAY_TYPE);
    if ( v19 != nullptr )
      CDmAttribute::SetElementTypeSymbol(this: v19, typeSymbol: CDmElement::m_classType);
    v20 = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "cameraBin");
    if ( v20 != nullptr )
      v21 = (v20->m_nFlags & 0x1F) != 15 ? nullptr : v20;
    else
      v21 = CDmElement::CreateAttribute(this: (CDmElement *)v4, pAttributeName: "cameraBin", type: AT_FIRST_ARRAY_TYPE);
    if ( v21 != nullptr )
      CDmAttribute::SetElementTypeSymbol(this: v21, typeSymbol: CDmeCamera::m_classType);
    v22 = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "clipBin");
    if ( v22 != nullptr )
      v23 = (v22->m_nFlags & 0x1F) != 15 ? nullptr : v22;
    else
      v23 = CDmElement::CreateAttribute(this: (CDmElement *)v4, pAttributeName: "clipBin", type: AT_FIRST_ARRAY_TYPE);
    if ( v23 != nullptr )
      CDmAttribute::SetElementTypeSymbol(this: v23, typeSymbol: CDmeClip::m_classType);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&clipBin);
    v24 = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "clipBin");
    if ( v24 != nullptr && (v24->m_nFlags & 0x1F) == 0xF )
    {
      clipBin.m_pAttribute = v24;
      clipBin.m_pStorage = (DmElementArray_t *)v24->m_pData;
    }
    else
    {
      clipBin.m_pAttribute = nullptr;
      clipBin.m_pStorage = nullptr;
    }
    if ( m_Id != nullptr )
      value.u.m_Id = CExpressionCalculator::VariableCount(this: m_Id);
    else
      value.u.m_Id = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &clipBin,
      src: (const DmElementHandle_t *)&value);
    CSFMSession::CreateSessionSettings(this: v26);
  }
}

} // namespace sfmgen
