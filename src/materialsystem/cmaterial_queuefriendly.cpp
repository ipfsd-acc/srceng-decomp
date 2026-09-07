// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/cmaterial_queuefriendly.cpp
// Functions: 38
// ============================================================

#include "materialsystem\cmaterial_queuefriendly.h"

//------------------------------------------------------------------------------
// Address: 0x1001DE60
// Name: public: virtual char const __near * CMaterial_QueueFriendly::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMaterial_QueueFriendly::GetName(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetName(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DE70
// Name: public: virtual char const __near * CMaterial_QueueFriendly::GetTextureGroupName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMaterial_QueueFriendly::GetTextureGroupName(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetTextureGroupName(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DE90
// Name: public: virtual int CMaterial_QueueFriendly::GetMappingWidth(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial_QueueFriendly::GetMappingWidth(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetMappingWidth(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DEA0
// Name: public: virtual int CMaterial_QueueFriendly::GetMappingHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial_QueueFriendly::GetMappingHeight(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetMappingHeight(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DEB0
// Name: public: virtual bool CMaterial_QueueFriendly::InMaterialPage(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::InMaterialPage(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->InMaterialPage(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DEC0
// Name: public: virtual void CMaterial_QueueFriendly::GetMaterialOffset(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::GetMaterialOffset(CMaterial_QueueFriendly *this, float *pOffset)
{
  this->m_pRealTimeVersion->GetMaterialOffset(this: this->m_pRealTimeVersion, a2: pOffset);
}

//------------------------------------------------------------------------------
// Address: 0x1001DED0
// Name: public: virtual void CMaterial_QueueFriendly::GetMaterialScale(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::GetMaterialScale(CMaterial_QueueFriendly *this, float *pScale)
{
  this->m_pRealTimeVersion->GetMaterialScale(this: this->m_pRealTimeVersion, a2: pScale);
}

//------------------------------------------------------------------------------
// Address: 0x1001DEE0
// Name: public: virtual class IMaterial __near * CMaterial_QueueFriendly::GetMaterialPage(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CMaterial_QueueFriendly::GetMaterialPage(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetMaterialPage(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DEF0
// Name: public: virtual void CMaterial_QueueFriendly::IncrementReferenceCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::IncrementReferenceCount(CMaterial_QueueFriendly *this)
{
  this->m_pRealTimeVersion->IncrementReferenceCount(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DF00
// Name: public: virtual int CMaterial_QueueFriendly::GetEnumerationID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial_QueueFriendly::GetEnumerationID(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetEnumerationID(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DF20
// Name: public: virtual void CMaterial_QueueFriendly::GetReflectivity(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::GetReflectivity(CMaterial_QueueFriendly *this, Vector *reflect)
{
  this->m_pRealTimeVersion->GetReflectivity(this: this->m_pRealTimeVersion, a2: reflect);
}

//------------------------------------------------------------------------------
// Address: 0x1001DF30
// Name: public: virtual int CMaterial_QueueFriendly::ShaderParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial_QueueFriendly::ShaderParamCount(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->ShaderParamCount(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DF40
// Name: public: virtual bool CMaterial_QueueFriendly::IsErrorMaterial(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::IsErrorMaterial(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->IsErrorMaterial(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DF50
// Name: public: virtual bool CMaterial_QueueFriendly::IsSpriteCard(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::IsSpriteCard(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->IsSpriteCard(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DF80
// Name: public: virtual bool CMaterial_QueueFriendly::NeedsTangentSpace(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::NeedsTangentSpace(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->NeedsTangentSpace(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DF90
// Name: public: virtual int CMaterial_QueueFriendly::GetNumPasses(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial_QueueFriendly::GetNumPasses(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetNumPasses(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DFB0
// Name: public: virtual bool CMaterial_QueueFriendly::NeedsLightmapBlendAlpha(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::NeedsLightmapBlendAlpha(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->NeedsLightmapBlendAlpha(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DFD0
// Name: public: virtual void CMaterial_QueueFriendly::GetLowResColorSample(float,float,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::GetLowResColorSample(
        CMaterial_QueueFriendly *this,
        float s,
        float t,
        float *color)
{
  ((void (__thiscall *)(IMaterialInternal *, _DWORD, _DWORD, float *))this->m_pRealTimeVersion->GetLowResColorSample)(
    a1: this->m_pRealTimeVersion,
    a2: LODWORD(s),
    a3: LODWORD(t),
    a4: color);
}

//------------------------------------------------------------------------------
// Address: 0x1001E000
// Name: public: virtual class IMaterialVar __near * CMaterial_QueueFriendly::FindVar(char const __near *,bool __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IMaterialVar *__thiscall CMaterial_QueueFriendly::FindVar(
        CMaterial_QueueFriendly *this,
        const char *varName,
        bool *found,
        BOOL complain)
{
  return this->m_pRealTimeVersion->FindVar(this: this->m_pRealTimeVersion, a2: varName, a3: found, a4: complain);
}

//------------------------------------------------------------------------------
// Address: 0x1001E010
// Name: public: virtual class IMaterialVar __near * CMaterial_QueueFriendly::FindVarFast(char const __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialVar *__thiscall CMaterial_QueueFriendly::FindVarFast(
        CMaterial_QueueFriendly *this,
        const char *pVarName,
        unsigned int *pToken)
{
  return this->m_pRealTimeVersion->FindVarFast(this: this->m_pRealTimeVersion, a2: pVarName, a3: pToken);
}

//------------------------------------------------------------------------------
// Address: 0x1001E040
// Name: public: virtual bool CMaterial_QueueFriendly::IsTranslucent(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::IsTranslucent(CMaterial_QueueFriendly *this)
{
  return ((bool (__stdcall *)(_DWORD))this->m_pRealTimeVersion->IsTranslucentInternal)(a1: LODWORD(this->m_fAlphaModulationOnQueueCompletion));
}

//------------------------------------------------------------------------------
// Address: 0x1001E0A0
// Name: public: virtual void CMaterial_QueueFriendly::SetShaderAndParams(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::SetShaderAndParams(CMaterial_QueueFriendly *this, KeyValues *pKeyValues)
{
  this->m_pRealTimeVersion->SetShaderAndParams(this: this->m_pRealTimeVersion, a2: pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x1001E0C0
// Name: public: virtual void CMaterial_QueueFriendly::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::Refresh(CMaterial_QueueFriendly *this)
{
  this->m_pRealTimeVersion->Refresh(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001E0E0
// Name: public: virtual float CMaterial_QueueFriendly::GetAlphaModulation(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMaterial_QueueFriendly::GetAlphaModulation(CMaterialDict::MaterialLookup_t *this)
{
  return *((float *)this + 2);
}

//------------------------------------------------------------------------------
// Address: 0x1001E0F0
// Name: public: virtual void CMaterial_QueueFriendly::GetColorModulation(float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::GetColorModulation(
        CMaterial_QueueFriendly *this,
        Vector *r,
        float *g,
        float *b)
{
  *r = this->m_vColorModulationOnQueueCompletion;
}

//------------------------------------------------------------------------------
// Address: 0x1001E120
// Name: public: virtual void CMaterial_QueueFriendly::FindRepresentativeTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::FindRepresentativeTexture(CMaterial_QueueFriendly *this)
{
  this->m_pRealTimeVersion->FindRepresentativeTexture(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001E130
// Name: public: void CMaterial_QueueFriendly::UpdateToRealTime(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::UpdateToRealTime(CMaterial_QueueFriendly *this)
{
  this->m_fAlphaModulationOnQueueCompletion = this->m_pRealTimeVersion->GetAlphaModulation(this: this->m_pRealTimeVersion);
  this->m_pRealTimeVersion->GetColorModulation(
    this: this->m_pRealTimeVersion,
    a2: (float *)&this->m_vColorModulationOnQueueCompletion,
    a3: &this->m_vColorModulationOnQueueCompletion.y,
    a4: &this->m_vColorModulationOnQueueCompletion.z);
}

//------------------------------------------------------------------------------
// Address: 0x1001E260
// Name: public: virtual void CMaterial_QueueFriendly::DecrementReferenceCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::DecrementReferenceCount(CMaterial_QueueFriendly *this)
{
  IMatRenderContext *v2; // eax
  ICallQueue *v3; // edi
  IMaterialInternal *m_pRealTimeVersion; // esi
  CFunctor *v5; // eax

  v2 = materials->GetRenderContext(this: materials);
  v3 = v2->GetCallQueue(this: v2);
  if ( v3 != nullptr )
  {
    m_pRealTimeVersion = this->m_pRealTimeVersion;
    v5 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v5 != nullptr )
    {
      v5[1].m_nUserID = 1;
      v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v5[2].__vftable = (CFunctor_vtbl *) __thiscall IMesh::`vcall'{52,{flat}};
      v5[2].m_nUserID = (unsigned int)m_pRealTimeVersion;
      v3->QueueFunctorInternal(this: v3, a2: v5);
    }
    else
    {
      v3->QueueFunctorInternal(this: v3, a2: nullptr);
    }
  }
  else
  {
    this->m_pRealTimeVersion->DecrementReferenceCount(this: this->m_pRealTimeVersion);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E2E0
// Name: public: virtual void CMaterial_QueueFriendly::DeleteIfUnreferenced(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::DeleteIfUnreferenced(CMaterial_QueueFriendly *this)
{
  IMatRenderContext *v2; // eax
  ICallQueue *v3; // edi
  IMaterialInternal *m_pRealTimeVersion; // esi
  CFunctor *v5; // eax

  v2 = materials->GetRenderContext(this: materials);
  v3 = v2->GetCallQueue(this: v2);
  if ( v3 != nullptr )
  {
    m_pRealTimeVersion = this->m_pRealTimeVersion;
    v5 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v5 != nullptr )
    {
      v5[1].m_nUserID = 1;
      v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v5[2].__vftable = (CFunctor_vtbl *) __thiscall IMaterial::`vcall'{200,{flat}};
      v5[2].m_nUserID = (unsigned int)m_pRealTimeVersion;
      v3->QueueFunctorInternal(this: v3, a2: v5);
    }
    else
    {
      v3->QueueFunctorInternal(this: v3, a2: nullptr);
    }
  }
  else
  {
    this->m_pRealTimeVersion->DeleteIfUnreferenced(this: this->m_pRealTimeVersion);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E360
// Name: public: virtual void CMaterial_QueueFriendly::RecomputeStateSnapshots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::RecomputeStateSnapshots(CMaterial_QueueFriendly *this)
{
  IMatRenderContext *v2; // eax
  ICallQueue *v3; // edi
  IMaterialInternal *m_pRealTimeVersion; // esi
  CFunctor *v5; // eax

  v2 = materials->GetRenderContext(this: materials);
  v3 = v2->GetCallQueue(this: v2);
  if ( v3 != nullptr )
  {
    m_pRealTimeVersion = this->m_pRealTimeVersion;
    v5 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v5 != nullptr )
    {
      v5[1].m_nUserID = 1;
      v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v5[2].__vftable = (CFunctor_vtbl *) __thiscall IMaterial::`vcall'{64,{flat}};
      v5[2].m_nUserID = (unsigned int)m_pRealTimeVersion;
      v3->QueueFunctorInternal(this: v3, a2: v5);
    }
    else
    {
      v3->QueueFunctorInternal(this: v3, a2: nullptr);
    }
  }
  else
  {
    this->m_pRealTimeVersion->RecomputeStateSnapshots(this: this->m_pRealTimeVersion);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E3E0
// Name: public: virtual void CMaterial_QueueFriendly::AlphaModulate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::AlphaModulate(CMaterial_QueueFriendly *this, float alpha)
{
  IMatRenderContext *v3; // eax
  ICallQueue *v4; // edi
  IMaterialInternal *m_pRealTimeVersion; // ebx
  float *v6; // eax

  v3 = materials->GetRenderContext(this: materials);
  v4 = v3->GetCallQueue(this: v3);
  if ( v4 != nullptr )
  {
    m_pRealTimeVersion = this->m_pRealTimeVersion;
    v6 = (float *)MemAlloc_Alloc(nSize: 0x1Cu);
    if ( v6 != nullptr )
    {
      *((_DWORD *)v6 + 3) = 1;
      *(_DWORD *)v6 = &CMemberFunctor1<IMaterialInternal *,void (__thiscall IMaterial::*)(float),float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      *((_DWORD *)v6 + 2) = &CMemberFunctor1<IMaterialInternal *,void (__thiscall IMaterial::*)(float),float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v6 + 4) =  __thiscall IColorCorrectionSystem::`vcall'{108,{flat}};
      *((_DWORD *)v6 + 5) = m_pRealTimeVersion;
      v6[6] = alpha;
    }
    else
    {
      v6 = nullptr;
    }
    v4->QueueFunctorInternal(this: v4, a2: (CFunctor *)v6);
    this->m_fAlphaModulationOnQueueCompletion = alpha;
  }
  else
  {
    ((void (__stdcall *)(_DWORD))this->m_pRealTimeVersion->AlphaModulate)(a1: LODWORD(alpha));
    this->m_fAlphaModulationOnQueueCompletion = alpha;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E490
// Name: public: virtual void CMaterial_QueueFriendly::ColorModulate(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::ColorModulate(CMaterial_QueueFriendly *this, float r, float g, float b)
{
  IMatRenderContext *v5; // eax
  ICallQueue *v6; // edi
  IMaterialInternal *m_pRealTimeVersion; // ebx
  float *v8; // eax

  v5 = materials->GetRenderContext(this: materials);
  v6 = v5->GetCallQueue(this: v5);
  if ( v6 != nullptr )
  {
    m_pRealTimeVersion = this->m_pRealTimeVersion;
    v8 = (float *)MemAlloc_Alloc(nSize: 0x24u);
    if ( v8 != nullptr )
    {
      *((_DWORD *)v8 + 3) = 1;
      *(_DWORD *)v8 = &CMemberFunctor3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      *((_DWORD *)v8 + 2) = &CMemberFunctor3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v8 + 4) =  __thiscall IMaterial::`vcall'{112,{flat}};
      *((_DWORD *)v8 + 5) = m_pRealTimeVersion;
      v8[6] = r;
      v8[7] = g;
      v8[8] = b;
    }
    else
    {
      v8 = nullptr;
    }
    v6->QueueFunctorInternal(this: v6, a2: (CFunctor *)v8);
  }
  else
  {
    ((void (__thiscall *)(IMaterialInternal *, _DWORD, _DWORD, _DWORD))this->m_pRealTimeVersion->ColorModulate)(
      a1: this->m_pRealTimeVersion,
      a2: LODWORD(r),
      a3: LODWORD(g),
      a4: LODWORD(b));
  }
  this->m_vColorModulationOnQueueCompletion.x = r;
  this->m_vColorModulationOnQueueCompletion.y = g;
  this->m_vColorModulationOnQueueCompletion.z = b;
}

//------------------------------------------------------------------------------
// Address: 0x1001E570
// Name: public: virtual void CMaterial_QueueFriendly::SetMaterialVarFlag(enum MaterialVarFlags_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::SetMaterialVarFlag(
        CMaterial_QueueFriendly *this,
        MaterialVarFlags_t flag,
        BOOL on)
{
  IMatRenderContext *v4; // eax
  ICallQueue *v5; // edi
  IMaterialInternal *m_pRealTimeVersion; // esi
  _DWORD *v7; // eax

  v4 = materials->GetRenderContext(this: materials);
  v5 = v4->GetCallQueue(this: v4);
  if ( v5 != nullptr )
  {
    m_pRealTimeVersion = this->m_pRealTimeVersion;
    v7 = MemAlloc_Alloc(nSize: 0x20u);
    if ( v7 != nullptr )
    {
      v7[3] = 1;
      *v7 = &CMemberFunctor2<IMaterialInternal *,void (__thiscall IMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v7[2] = &CMemberFunctor2<IMaterialInternal *,void (__thiscall IMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v7[4] =  __thiscall IMaterial::`vcall'{116,{flat}};
      v7[5] = m_pRealTimeVersion;
      v7[6] = flag;
      *((_BYTE *)v7 + 28) = on;
      v5->QueueFunctorInternal(this: v5, a2: (CFunctor *)v7);
    }
    else
    {
      v5->QueueFunctorInternal(this: v5, a2: nullptr);
    }
  }
  else
  {
    this->m_pRealTimeVersion->SetMaterialVarFlag(this: this->m_pRealTimeVersion, a2: flag, a3: on);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021180
// Name: public: virtual enum PreviewImageRetVal_t CMaterial_QueueFriendly::GetPreviewImage(unsigned char __near *,int,int,enum ImageFormat)const
// Source: json
//------------------------------------------------------------------------------
PreviewImageRetVal_t __thiscall CMaterial_QueueFriendly::GetPreviewImage(
        CMaterial_QueueFriendly *this,
        unsigned __int8 *data,
        int width,
        int height,
        ImageFormat imageFormat)
{
  return this->m_pRealTimeVersion->GetPreviewImage(
           this: this->m_pRealTimeVersion,
           a2: data,
           a3: width,
           a4: height,
           a5: imageFormat);
}

//------------------------------------------------------------------------------
// Address: 0x100211C0
// Name: public: virtual bool CMaterial_QueueFriendly::NeedsSoftwareSkinning(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::NeedsSoftwareSkinning(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->NeedsSoftwareSkinning(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x10021290
// Name: public: virtual bool CMaterial_QueueFriendly::GetMaterialVarFlag(enum MaterialVarFlags_t)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::GetMaterialVarFlag(CMaterial_QueueFriendly *this, MaterialVarFlags_t flag)
{
  return this->m_pRealTimeVersion->GetMaterialVarFlag(this: this->m_pRealTimeVersion, a2: flag);
}

//------------------------------------------------------------------------------
// Address: 0x100212B0
// Name: public: virtual bool CMaterial_QueueFriendly::IsAlphaTested(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::IsAlphaTested(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->IsAlphaTested(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x10021350
// Name: public: virtual char const __near * CMaterial_QueueFriendly::GetShaderName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMaterial_QueueFriendly::GetShaderName(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetShaderName(this: this->m_pRealTimeVersion);
}
