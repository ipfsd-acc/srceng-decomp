// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_vguiscreen.cpp
// Functions: 49
// ============================================================

#include "game\client\c_vguiscreen.h"

//------------------------------------------------------------------------------
// Address: 0x100948E0
// Name: public: virtual void PrecacheEffectVGuiScreenPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectVGuiScreenPrecache::CResourcePrecacher::Cache(
        PrecacheEffectVGuiScreenPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "engine/writez",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10094910
// Name: public: virtual class ClientClass __near * C_VGuiScreen::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_VGuiScreen::GetClientClass(C_VGuiScreen *this)
{
  return &__g_C_VGuiScreenClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10094A50
// Name: public: virtual void C_VGuiScreen::PreDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_VGuiScreen::PreDataUpdate(C_VGuiScreen *this, DataUpdateType_t updateType)
{
  int m_nOldButtonState; // edx

  C_BaseEntity::PreDataUpdate(this, updateType);
  m_nOldButtonState = this->m_nOldButtonState;
  this->m_nOverlayMaterial = LODWORD(this->m_flWidth);
  this->m_fScreenFlags = m_nOldButtonState;
}

//------------------------------------------------------------------------------
// Address: 0x10094A80
// Name: public: bool C_VGuiScreen::IsActive(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_VGuiScreen::IsActive(C_VGuiScreen *this)
{
  return this->m_fScreenFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10094A90
// Name: public: bool C_VGuiScreen::IsAttachedToViewModel(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_VGuiScreen::IsAttachedToViewModel(C_VGuiScreen *this)
{
  return (this->m_fScreenFlags & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10094AA0
// Name: public: bool C_VGuiScreen::AcceptsInput(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_VGuiScreen::AcceptsInput(C_VGuiScreen *this)
{
  return this->m_bAcceptsInput;
}

//------------------------------------------------------------------------------
// Address: 0x10094AB0
// Name: public: virtual enum RenderableTranslucencyType_t C_VGuiScreen::ComputeTranslucencyType(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_VGuiScreen::ComputeTranslucencyType(C_VGuiScreen *this)
{
  return (this->m_fScreenFlags & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10094AC0
// Name: void ActivateVguiScreen(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ActivateVguiScreen(C_BaseEntity *pVguiScreenEnt)
{
  if ( pVguiScreenEnt != nullptr )
  {
    ((void (__thiscall *)(C_BaseEntity *, int))pVguiScreenEnt->SetNextClientThink)(a1: pVguiScreenEnt, a2: -996040704);
    LOBYTE(pVguiScreenEnt[1].m_pfnThink) = 0;
    pVguiScreenEnt[1].m_VarMap.m_Entries.m_Memory.m_nGrowSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094B00
// Name: void SetVGuiScreenButtonState(class C_BaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetVGuiScreenButtonState(C_BaseEntity *pVguiScreenEnt, const char *nButtonState)
{
  if ( pVguiScreenEnt != nullptr )
    pVguiScreenEnt[1].m_iClassname = nButtonState;
}

//------------------------------------------------------------------------------
// Address: 0x10094B20
// Name: void DeactivateVguiScreen(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeactivateVguiScreen(C_BaseEntity *pVguiScreenEnt)
{
  if ( pVguiScreenEnt != nullptr )
  {
    LOBYTE(pVguiScreenEnt[1].m_pfnThink) = 1;
    pVguiScreenEnt[1].m_VarMap.m_Entries.m_Memory.m_nGrowSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094B40
// Name: public: virtual class vgui::Panel __near * CVGuiScreenPanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBitmapPanel *__thiscall CVGuiScreenPanel::CreateControlByName(CVGuiScreenPanel *this, const char *controlName)
{
  CBitmapPanel *v3; // eax
  CBitmapButton *v5; // eax

  if ( V_strncmp(s1: controlName, s2: "MaterialImage", count: 20) == 0 )
  {
    v3 = (CBitmapPanel *)MemAlloc_Alloc(nSize: 0x264u);
    if ( v3 != nullptr )
      return CBitmapPanel::CBitmapPanel(this: v3, pParent: nullptr, pName: "BitmapPanel");
    return nullptr;
  }
  if ( V_strncmp(s1: controlName, s2: "MaterialButton", count: 20) != 0 )
    return (CBitmapPanel *)vgui::EditablePanel::CreateControlByName(this, controlName);
  v5 = (CBitmapButton *)MemAlloc_Alloc(nSize: 0x31Cu);
  if ( v5 == nullptr )
    return nullptr;
  return (CBitmapPanel *)CBitmapButton::CBitmapButton(this: v5, pParent: nullptr, pName: "BitmapButton", pText: prType);
}

//------------------------------------------------------------------------------
// Address: 0x10094BE0
// Name: public: virtual void CVGuiScreenPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiScreenPanel::OnCommand(CVGuiScreenPanel *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "vguicancel") != 0 )
    engine->ClientCmd(this: engine, a2: command);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x10094C20
// Name: public: virtual C_VGuiScreen::~C_VGuiScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_VGuiScreen::~C_VGuiScreen(C_VGuiScreen *this)
{
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_VGuiScreen_vtbl *)&C_VGuiScreen::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_VGuiScreen::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_VGuiScreen::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_VGuiScreen::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_VGuiScreen::`vftable';
  CPanelWrapper::Deactivate(this: &this->m_PanelWrapper);
  CPanelWrapper::Deactivate(this: &this->m_PanelWrapper);
  CMaterialReference::~CMaterialReference(this: &this->m_OverlayMaterial);
  CMaterialReference::~CMaterialReference(this: &this->m_WriteZMaterial);
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10094C80
// Name: public: virtual void C_VGuiScreen::GetAimEntOrigin(class IClientEntity __near *,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_VGuiScreen::GetAimEntOrigin(
        C_VGuiScreen *this,
        IClientEntity *pAttachedTo,
        Vector *pOrigin,
        QAngle *pAngles)
{
  IClientEntity *v4; // ebx
  C_BaseEntity *v6; // edi
  Vector *v7; // ebx
  int v8; // eax
  C_BasePlayer *v9; // esi

  v4 = pAttachedTo;
  v6 = pAttachedTo->GetBaseEntity(this: pAttachedTo);
  if ( v6 != nullptr && this->m_nAttachmentIndex > 0 )
  {
    C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(
      this: (C_BaseAnimating::AutoAllowBoneAccess *)&pAttachedTo + 3,
      bAllowForNormalModels: true,
      bAllowForViewModels: true);
    v7 = pOrigin;
    v6->GetAttachment_2(this: &v6->IClientRenderable, a2: this->m_nAttachmentIndex, a3: pOrigin, a4: pAngles);
    C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: (C_BaseAnimating::AutoAllowBoneAccess *)&pAttachedTo + 3);
    if ( (this->m_fScreenFlags & 4) != 0 )
    {
      v8 = v6->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetEFlags(this: v6);
      v9 = (C_BasePlayer *)v8;
      if ( v8 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 584))(a1: v8) == 0 )
        v9 = nullptr;
      FormatViewModelAttachment(pPlayer: v9, vOrigin: v7, bInverse: true);
    }
  }
  else
  {
    C_BaseEntity::GetAimEntOrigin(this, pAttachedTo: v4, pOrigin, pAngles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094D30
// Name: private: void C_VGuiScreen::CreateVguiScreen(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_VGuiScreen::CreateVguiScreen(C_VGuiScreen *this, const char *pTypeName)
{
  const char *v3; // ecx
  vgui::Panel *Panel; // eax
  int x; // [esp+8h] [ebp-8h] BYREF
  VGuiScreenInitData_t initData; // [esp+Ch] [ebp-4h] BYREF

  CPanelWrapper::Deactivate(this: &this->m_PanelWrapper);
  v3 = pTypeName;
  this->m_iEFlags |= 0x40000u;
  initData.m_pEntity = this;
  CPanelWrapper::Activate(
    this: &this->m_PanelWrapper,
    pMetaClassName: v3,
    pParent: nullptr,
    sortorder: 0,
    pVoidInitData: &initData);
  Panel = CPanelWrapper::GetPanel(this: &this->m_PanelWrapper);
  if ( Panel != nullptr )
  {
    vgui::Panel::GetBounds(
      this: Panel,
      &x,
      y: (int *)&pTypeName,
      wide: &this->m_nPixelWidth,
      tall: &this->m_nPixelHeight);
  }
  else
  {
    this->m_nPixelHeight = 0;
    this->m_nPixelWidth = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094DC0
// Name: public: bool C_VGuiScreen::IntersectWithRay(struct Ray_t const __near &,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_VGuiScreen::IntersectWithRay(C_VGuiScreen *this, const Ray_t *ray, float *u, float *v, float *t)
{
  const Vector *v6; // eax
  __int64 v7; // xmm0_8
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // edx
  const QAngle *v9; // eax
  float m_flWidth; // xmm3_4
  Vector origin; // [esp+4h] [ebp-48h] BYREF
  Vector upt; // [esp+10h] [ebp-3Ch] BYREF
  Vector vpt; // [esp+1Ch] [ebp-30h] BYREF
  Vector forward; // [esp+28h] [ebp-24h] BYREF
  Vector right; // [esp+34h] [ebp-18h] BYREF
  Vector v17; // [esp+40h] [ebp-Ch]

  v6 = this->GetAbsOrigin(this);
  v7 = *(_QWORD *)&v6->x;
  v17.z = v6->z;
  GetAbsAngles = this->GetAbsAngles;
  *(_QWORD *)&v17.x = v7;
  v9 = GetAbsAngles(this);
  AngleVectors(angles: v9, &forward, &right, up: nullptr);
  *(float *)&v7 = this->m_flHeight;
  origin.x = (float)(*(float *)&v7 * (float)(right.x * -1.0)) + v17.x;
  m_flWidth = this->m_flWidth;
  upt.y = (float)(forward.y * m_flWidth) + (float)((float)(*(float *)&v7 * (float)(right.y * -1.0)) + v17.y);
  vpt = v17;
  origin.y = (float)(*(float *)&v7 * (float)(right.y * -1.0)) + v17.y;
  origin.z = (float)(*(float *)&v7 * (float)(right.z * -1.0)) + v17.z;
  upt.x = (float)(forward.x * m_flWidth) + origin.x;
  upt.z = (float)(forward.z * m_flWidth) + origin.z;
  return ComputeIntersectionBarycentricCoordinates(ray, v1: &origin, v2: &upt, v3: &vpt, u, v, t);
}

//------------------------------------------------------------------------------
// Address: 0x10094EE0
// Name: public: bool C_VGuiScreen::IsBackfacing(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_VGuiScreen::IsBackfacing(C_VGuiScreen *this, const Vector *viewOrigin)
{
  const Vector *v3; // eax
  Vector zaxis; // [esp+4h] [ebp-18h] BYREF
  Vector cameraToScreen; // [esp+10h] [ebp-Ch]

  v3 = this->GetAbsOrigin(this);
  cameraToScreen.x = v3->x - viewOrigin->x;
  cameraToScreen.y = v3->y - viewOrigin->y;
  cameraToScreen.z = v3->z - viewOrigin->z;
  C_BaseEntity::GetVectors(this, pForward: nullptr, pRight: nullptr, pUp: &zaxis);
  return (float)((float)((float)(zaxis.x * cameraToScreen.x) + (float)(zaxis.y * cameraToScreen.y))
               + (float)(zaxis.z * cameraToScreen.z)) > 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10094F70
// Name: private: void C_VGuiScreen::ComputePanelToWorld(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_VGuiScreen::ComputePanelToWorld(C_VGuiScreen *this)
{
  const Vector *v2; // eax
  __int64 v3; // xmm0_8
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // edx
  const QAngle *v5; // eax
  const QAngle *(__thiscall *v6)(IClientEntity *); // edx
  float v7; // xmm1_4
  const QAngle *v8; // eax
  Vector forward; // [esp+4h] [ebp-30h] BYREF
  Vector vecOrigin; // [esp+10h] [ebp-24h] BYREF
  Vector right; // [esp+1Ch] [ebp-18h] BYREF
  __int64 v12; // [esp+28h] [ebp-Ch]
  float z; // [esp+30h] [ebp-4h]

  v2 = this->GetAbsOrigin(this);
  v3 = *(_QWORD *)&v2->x;
  z = v2->z;
  GetAbsAngles = this->GetAbsAngles;
  v12 = v3;
  v5 = GetAbsAngles(this);
  AngleVectors(angles: v5, &forward, &right, up: nullptr);
  v6 = this->GetAbsAngles;
  v7 = (float)(this->m_flHeight * (float)(right.y * -1.0)) + *((float *)&v12 + 1);
  *(float *)&v3 = (float)(this->m_flHeight * (float)(right.z * -1.0)) + z;
  vecOrigin.x = (float)(this->m_flHeight * (float)(right.x * -1.0)) + *(float *)&v12;
  vecOrigin.y = v7;
  LODWORD(vecOrigin.z) = v3;
  v8 = v6(this);
  VMatrix::SetupMatrixOrgAngles(this: &this->m_PanelToWorld, origin: &vecOrigin, vAngles: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10095030
// Name: public: virtual bool C_VGuiScreen::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_VGuiScreen::ShouldDraw(C_VGuiScreen *this)
{
  return (*(_DWORD *)&this->m_nWaterType & 0x20) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10095040
// Name: public: class C_BasePlayer __near * C_VGuiScreen::GetPlayerOwner(void)
// Source: json
//------------------------------------------------------------------------------
C_BasePlayer *__thiscall C_VGuiScreen::GetPlayerOwner(C_VGuiScreen *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hPlayerOwner.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10095070
// Name: public: C_VGuiScreen::C_VGuiScreen(void)
// Source: json
//------------------------------------------------------------------------------
C_VGuiScreen *__thiscall C_VGuiScreen::C_VGuiScreen(C_VGuiScreen *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_VGuiScreen_vtbl *)&C_VGuiScreen::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_VGuiScreen::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_VGuiScreen::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_VGuiScreen::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_VGuiScreen::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_WriteZMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CTextureReference::CTextureReference(this: (CTextureReference *)&this->m_PanelWrapper);
  this->m_hPlayerOwner.m_Index = -1;
  this->m_nPanelName = -1;
  this->m_nOldPanelName = -1;
  this->m_nOverlayMaterial = -1;
  this->m_nOldOverlayMaterial = -1;
  this->m_nOldPy = -1;
  this->m_nOldPx = -1;
  this->m_nButtonState = 0;
  *(_WORD *)&this->m_bLoseThinkNextFrame = 256;
  CMaterialReference::Init(
    this: &this->m_WriteZMaterial,
    pMaterialName: "engine/writez",
    pTextureGroupName: "VGUI textures",
    bComplain: true);
  CMaterialReference::Init(this: &this->m_OverlayMaterial, ref: &this->m_WriteZMaterial);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10095160
// Name: public: virtual void C_VGuiScreen::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_VGuiScreen::OnDataChanged(C_VGuiScreen *this, DataUpdateType_t type)
{
  const char *v3; // eax
  const char *MaterialNameFromIndex; // eax
  bool *p_m_bLoseThinkNextFrame; // ecx

  C_BaseEntity::OnDataChanged(this, type);
  if ( type == DATA_UPDATE_CREATED || LODWORD(this->m_flWidth) != this->m_nOverlayMaterial )
  {
    v3 = g_StringTableVguiScreen->GetString(this: g_StringTableVguiScreen, a2: LODWORD(this->m_flWidth));
    C_VGuiScreen::CreateVguiScreen(this: (C_VGuiScreen *)((char *)this - 8), pTypeName: v3);
    this->m_flHeight = 0.0;
  }
  C_BaseEntity::RenderWithViewModels(
    this: (C_VGuiScreen *)((char *)this - 8),
    bEnable: (this->m_nAttachmentIndex & 4) != 0);
  C_BaseEntity::OnTranslucencyTypeChanged(this: (C_VGuiScreen *)((char *)this - 8));
  if ( this->m_fScreenFlags != this->m_nOldButtonState )
  {
    CMaterialReference::Shutdown(this: (CMaterialReference *)&this->m_bLoseThinkNextFrame, bDeleteIfUnreferenced: false);
    MaterialNameFromIndex = GetMaterialNameFromIndex(nIndex: this->m_nOldButtonState);
    p_m_bLoseThinkNextFrame = &this->m_bLoseThinkNextFrame;
    if ( MaterialNameFromIndex != nullptr )
      CMaterialReference::Init(
        this: (CMaterialReference *)p_m_bLoseThinkNextFrame,
        pMaterialName: MaterialNameFromIndex,
        pTextureGroupName: "VGUI textures",
        bComplain: true);
    else
      CMaterialReference::Init(
        this: (CMaterialReference *)p_m_bLoseThinkNextFrame,
        ref: (CMaterialReference *)&this->m_nOldOverlayMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095220
// Name: public: bool C_VGuiScreen::IsVisibleToTeam(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_VGuiScreen::IsVisibleToTeam(C_VGuiScreen *this, const CBaseHandle *nTeam)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  bool result; // al

  result = true;
  if ( (this->m_fScreenFlags & 2) != 0 && (int)nTeam > 0 )
  {
    m_Index = this->m_hOwnerEntity.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr && nTeam != m_pEntity->__vftable[27].GetRefEHandle(this: m_pEntity) )
        return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10095290
// Name: public: virtual void C_VGuiScreen::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_VGuiScreen::ClientThink(C_VGuiScreen *this@<ecx>, float a2@<ebp>)
{
  int m_flWidth_low; // eax
  int v4; // ecx
  C_BasePlayer *LocalPlayer; // edi
  IClientMode *ClientMode; // eax
  int v7; // edi
  float v8; // xmm1_4
  int v9; // ecx
  void (__stdcall *v10)(int); // eax
  IClientMode *v11; // eax
  Vector v12; // [esp+54h] [ebp-9Ch] BYREF
  Ray_t lookDir; // [esp+60h] [ebp-90h] BYREF
  QAngle v14; // [esp+B0h] [ebp-40h] BYREF
  QAngle viewAngles; // [esp+BCh] [ebp-34h] BYREF
  Vector viewDir; // [esp+C8h] [ebp-28h] BYREF
  Vector vecEyePosition; // [esp+D4h] [ebp-1Ch] BYREF
  vgui::Panel *Panel; // [esp+E0h] [ebp-10h]
  float u; // [esp+E4h] [ebp-Ch]
  float v; // [esp+E8h] [ebp-8h]
  float retaddr; // [esp+F0h] [ebp+0h]

  u = a2;
  v = retaddr;
  m_flWidth_low = LODWORD(this->m_flWidth);
  v4 = m_flWidth_low ^ this->m_nButtonReleased;
  this->m_nButtonReleased = m_flWidth_low;
  LODWORD(this->m_flHeight) = v4 & m_flWidth_low;
  this->m_nPanelName = v4 & ~m_flWidth_low;
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  Panel = CPanelWrapper::GetPanel(this: (CPanelWrapper *)&this->m_PanelToWorld.m[3][1]);
  if ( Panel != nullptr )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
    {
      LocalPlayer->EyePosition(this: LocalPlayer, result: &viewDir);
      v14 = *LocalPlayer->EyeAngles(this: LocalPlayer);
      AngleVectors(angles: &v14, forward: (Vector *)&viewAngles);
      lookDir.m_Start.z = (float)((float)(viewAngles.y * 1000.0) + viewDir.y) - viewDir.y;
      lookDir.m_Start.y = (float)((float)(viewAngles.x * 1000.0) + viewDir.x) - viewDir.x;
      lookDir.m_Start.w = (float)((float)(viewAngles.z * 1000.0) + viewDir.z) - viewDir.z;
      BYTE1(lookDir.m_Extents.z) = (float)((float)((float)(lookDir.m_Start.z * lookDir.m_Start.z)
                                                 + (float)(lookDir.m_Start.y * lookDir.m_Start.y))
                                         + (float)(lookDir.m_Start.w * lookDir.m_Start.w)) != 0.0;
      memset(&lookDir.m_StartOffset.y, 0, 12);
      lookDir.m_Extents.y = 0.0;
      LOBYTE(lookDir.m_Extents.z) = 1;
      memset(&lookDir.m_Delta.y, 0, 12);
      v12 = viewDir;
      LODWORD(vecEyePosition.x) = (char *)this - 12;
      if ( C_VGuiScreen::IntersectWithRay(
             this: (C_VGuiScreen *)((char *)this - 12),
             ray: (const Ray_t *)&v12,
             u: &vecEyePosition.y,
             v: &vecEyePosition.z,
             t: nullptr)
        && (vecEyePosition.y >= 0.0 && vecEyePosition.z >= 0.0 && vecEyePosition.y <= 1.0 && vecEyePosition.z <= 1.0
         || LOBYTE(this->m_fScreenFlags) != 0) )
      {
        ClientMode = GetClientMode();
        ClientMode->ActivateInGameVGuiContext(this: ClientMode, a2: Panel);
        v7 = (int)(float)((float)((float)this->m_CalcAbsoluteVelocityMutex.m_depth * vecEyePosition.y) + 0.5);
        v8 = (float)((float)*(int *)&this->m_bIsBlurred * vecEyePosition.z) + 0.5;
        Panel = (vgui::Panel *)(int)v8;
        if ( v7 != this->m_nButtonState || (int)v8 != this->m_nButtonPressed )
        {
          g_InputInternal->InternalCursorMoved(this: g_InputInternal, a2: v7, a3: (int)v8);
          v9 = (int)Panel;
          this->m_nButtonState = v7;
          this->m_nButtonPressed = v9;
        }
        if ( (LODWORD(this->m_flHeight) & 0x21) != 0 )
        {
          g_InputInternal->SetMouseCodeState(this: g_InputInternal, a2: KEY_COUNT, a3: (vgui::MouseCodeState_t)1);
          g_InputInternal->InternalMousePressed(this: g_InputInternal, a2: KEY_COUNT);
        }
        if ( (LODWORD(this->m_flHeight) & 0x800) != 0 )
        {
          g_InputInternal->SetMouseCodeState(this: g_InputInternal, a2: MOUSE_RIGHT, a3: (vgui::MouseCodeState_t)1);
          g_InputInternal->InternalMousePressed(this: g_InputInternal, a2: MOUSE_RIGHT);
        }
        if ( (this->m_nPanelName & 0x21) != 0 || LOBYTE(this->m_fScreenFlags) != 0 )
        {
          g_InputInternal->SetMouseCodeState(this: g_InputInternal, a2: KEY_COUNT, a3: BUTTON_RELEASED);
          g_InputInternal->InternalMouseReleased(this: g_InputInternal, a2: KEY_COUNT);
        }
        if ( (this->m_nPanelName & 0x800) != 0 )
        {
          g_InputInternal->SetMouseCodeState(this: g_InputInternal, a2: MOUSE_RIGHT, a3: BUTTON_RELEASED);
          g_InputInternal->InternalMouseReleased(this: g_InputInternal, a2: MOUSE_RIGHT);
        }
        if ( LOBYTE(this->m_fScreenFlags) == 1 )
        {
          v10 = *(void (__stdcall **)(int))(*(_DWORD *)LODWORD(vecEyePosition.x) + 456);
          LOBYTE(this->m_fScreenFlags) = 0;
          v10(a1: -1082130432);
        }
        v11 = GetClientMode();
        v11->DeactivateInGameVGuiContext(this: v11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095600
// Name: public: CVGuiScreenPanel::CVGuiScreenPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVGuiScreenPanel *__thiscall CVGuiScreenPanel::CVGuiScreenPanel(
        CVGuiScreenPanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (CVGuiScreenPanel_vtbl *)&CVGuiScreenPanel::`vftable';
  this->m_hEntity.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10095630
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10095640
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10095670
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10095680
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100956B0
// Name: public: CVGuiScreenPanel::CVGuiScreenPanel(class vgui::Panel __near *,char const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
CVGuiScreenPanel *__thiscall CVGuiScreenPanel::CVGuiScreenPanel(
        CVGuiScreenPanel *this,
        vgui::Panel *parent,
        const char *panelName,
        unsigned int hScheme)
{
  vgui::EditablePanel::EditablePanel(this, parent, panelName, hScheme);
  this->__vftable = (CVGuiScreenPanel_vtbl *)&CVGuiScreenPanel::`vftable';
  this->m_hEntity.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10095DD0
// Name: private: void C_VGuiScreen::DrawScreenOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_VGuiScreen::DrawScreenOverlay(C_VGuiScreen *this@<ecx>, int a2@<edi>)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // edi
  float *m_pCurrPosition; // eax
  float *v6; // eax
  float *v7; // eax
  float *v8; // eax
  int v9; // xmm0_4
  float *v10; // eax
  float *v11; // eax
  float *v12; // eax
  int v13; // xmm1_4
  float *v14; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1E8h] BYREF

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  ((void (__thiscall *)(IMatRenderContext *, int, int))v3->MatrixMode)(a1: v3, a2: 10, a3: a2);
  v3->PushMatrix(this: v3);
  v3->LoadMatrix_2(this: v3, a2: &this->m_PanelToWorld);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: this->m_OverlayMaterial.m_pMaterial);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
  m_pCurrPosition[1] = 0.0;
  m_pCurrPosition[2] = 0.0;
  v6 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v6[1] = 0.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v7 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = this->m_flWidth;
  v7[1] = 0.0;
  v7[2] = 0.0;
  v8 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v8[1] = 0.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v9 = LODWORD(this->m_flHeight) ^ _mask__NegFloat_;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = this->m_flWidth;
  *((_DWORD *)v10 + 1) = v9;
  v10[2] = 0.0;
  v11 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v11[1] = 1.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v12 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v13 = LODWORD(this->m_flHeight) ^ _mask__NegFloat_;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
  *((_DWORD *)v12 + 1) = v13;
  v12[2] = 0.0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v14[1] = 1.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
  v3->PopMatrix(this: v3);
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10096130
// Name: public: virtual int C_VGuiScreen::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_VGuiScreen::DrawModel(C_VGuiScreen *this, int flags, const RenderableInstance_t *instance)
{
  vgui::Panel *Panel; // eax
  vgui::Panel *v5; // ebx
  C_BasePlayer *LocalPlayer; // eax
  C_VGuiScreen *v8; // edi
  const CBaseHandle *v9; // eax
  const Vector *v10; // eax
  int v11; // eax
  C_BasePlayer *pLocalPlayer; // [esp+1Ch] [ebp-4h]
  C_BasePlayer *pLocalPlayera; // [esp+1Ch] [ebp-4h]

  Panel = CPanelWrapper::GetPanel(this: (CPanelWrapper *)&this->m_PanelToWorld.m[3][3]);
  v5 = Panel;
  if ( Panel == nullptr )
    return 0;
  Panel->SetEnabled(this: Panel, a2: this->m_nOverlayMaterial & 1);
  if ( (this->m_nOverlayMaterial & 1) == 0 )
    return 0;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  pLocalPlayer = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return 0;
  v8 = (C_VGuiScreen *)((char *)this - 4);
  v9 = (const CBaseHandle *)LocalPlayer->GetTeamNumber(this: LocalPlayer);
  if ( !C_VGuiScreen::IsVisibleToTeam(this: (C_VGuiScreen *)((char *)this - 4), nTeam: v9) )
    return 0;
  if ( !v8->IsVisibleToPlayer(this: (C_VGuiScreen *)((char *)this - 4), a2: pLocalPlayer) )
    return 0;
  v10 = CurrentViewOrigin();
  if ( C_VGuiScreen::IsBackfacing(this: (C_VGuiScreen *)((char *)this - 4), viewOrigin: v10) )
    return 0;
  C_VGuiScreen::ComputePanelToWorld(this: (C_VGuiScreen *)((char *)this - 4));
  pLocalPlayera = (C_BasePlayer *)g_pMatSystemSurface->__vftable;
  v11 = ((int (__thiscall *)(vgui::Panel *, CMaterialReference *, _DWORD, int, int, _DWORD))v5->GetVPanel)(
          a1: v5,
          a2: &this->m_OverlayMaterial,
          a3: *((_DWORD *)&this->m_bIsBlurred + 1),
          a4: this->m_nPixelWidth,
          a5: this->m_nPixelHeight,
          a6: LODWORD(this->m_flWidth));
  ((void (__thiscall *)(IMatSystemSurface *, int))pLocalPlayera->m_nLastRecordedFrame)(a1: g_pMatSystemSurface, a2: v11);
  C_VGuiScreen::DrawScreenOverlay(this: v8, a2: (int)v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10096C20
// Name: public: virtual enum IterationRetval_t CVGuiScreenEnumerator::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall CVGuiScreenEnumerator::EnumElement(
        CVGuiScreenEnumerator *this,
        IHandleEntity *pHandleEntity)
{
  CBaseHandle *v3; // eax
  C_BaseEntity *BaseEntityFromHandle; // eax
  void *v5; // edi
  CHandle<C_VGuiScreen> *v6; // esi

  v3 = pHandleEntity->GetRefEHandle(this: pHandleEntity);
  BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                           this: (CClientEntityList *)cl_entitylist.m_Index,
                           hEnt: (CBaseHandle)v3->m_Index);
  if ( BaseEntityFromHandle != nullptr )
  {
    v5 = __RTDynamicCast(
           inptr: BaseEntityFromHandle,
           VfDelta: 0,
           SrcType: &C_BaseEntity `RTTI Type Descriptor',
           TargetType: &C_VGuiScreen `RTTI Type Descriptor',
           isReference: 0);
    if ( v5 != nullptr )
    {
      v6 = &this->m_VguiScreens.m_Memory.m_pMemory[CUtlVector<CHandle<C_VGuiScreen>,CUtlMemory<CHandle<C_VGuiScreen>,int>>::InsertBefore(
                                                     this: &this->m_VguiScreens,
                                                     elem: this->m_VguiScreens.m_Size)];
      v6->m_Index = *(unsigned int *)(*(int (__thiscall **)(void *))(*(_DWORD *)v5 + 8))(a1: v5);
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x10096C90
// Name: class C_BaseEntity __near * FindNearbyVguiScreen(class Vector const __near &,class QAngle const __near &,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
C_BasePlayer *__usercall FindNearbyVguiScreen@<eax>(
        float a1@<ebp>,
        const Vector *viewPosition,
        const QAngle *viewAngle,
        int nTeam)
{
  C_BasePlayer *result; // eax
  int v5; // eax
  unsigned int v6; // ecx
  IHandleEntity *m_pEntity; // esi
  float *v8; // eax
  C_BasePlayer *PlayerOwner; // eax
  float *v10; // eax
  float v11; // xmm0_4
  _BYTE v12[12]; // [esp+1Ch] [ebp-CCh] BYREF
  Ray_t lookRay; // [esp+28h] [ebp-C0h]
  Vector v14; // [esp+78h] [ebp-70h] BYREF
  Vector vecOut; // [esp+84h] [ebp-64h]
  Vector v16; // [esp+90h] [ebp-58h] BYREF
  Vector lookDir; // [esp+9Ch] [ebp-4Ch] BYREF
  CVGuiScreenEnumerator localScreens; // [esp+A8h] [ebp-40h] BYREF
  unsigned int v; // [esp+C0h] [ebp-28h] BYREF
  unsigned __int64 u; // [esp+C4h] [ebp-24h] OVERLAPPED
  char *t; // [esp+CCh] [ebp-1Ch]
  float flBestDist; // [esp+D0h] [ebp-18h] BYREF
  C_VGuiScreen *pBestScreen; // [esp+D4h] [ebp-14h]
  int i; // [esp+D8h] [ebp-10h]
  Vector lookEnd; // [esp+DCh] [ebp-Ch]
  float retaddr; // [esp+E8h] [ebp+0h]

  lookEnd.x = a1;
  lookEnd.y = retaddr;
  result = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  localScreens.m_VguiScreens.m_pElements = (CHandle<C_VGuiScreen> *)result;
  if ( result != nullptr )
  {
    AngleVectors(angles: viewAngle, forward: &v16);
    flBestDist = (float)(v16.x * 160.0) + viewPosition->x;
    *(float *)&pBestScreen = (float)(v16.y * 160.0) + viewPosition->y;
    *(float *)&i = (float)(v16.z * 160.0) + viewPosition->z;
    lookRay.m_Extents.y = 0.0;
    Ray_t::Init(this: (Ray_t *)v12, start: viewPosition, end: (const Vector *)&flBestDist);
    lookDir.y = 0.0;
    lookDir.z = 0.0;
    memset(&localScreens, 0, 12);
    LODWORD(lookDir.x) = &CVGuiScreenEnumerator::`vftable';
    ((void (__thiscall *)(ISpatialPartition *, int, const Vector *, int, _DWORD, Vector *))partition->EnumerateElementsInSphere)(
      a1: partition,
      a2: 128,
      a3: viewPosition,
      a4: 1117782016,
      a5: 0,
      a6: &lookDir);
    v5 = (int)&localScreens.m_VguiScreens.m_Memory.m_pMemory[-1].m_Index + 3;
    u = 0x40000000;
    for ( t = (char *)&localScreens.m_VguiScreens.m_Memory.m_pMemory[-1].m_Index + 3; v5 >= 0; t = (char *)v5 )
    {
      v6 = *(_DWORD *)(LODWORD(lookDir.y) + 4 * v5);
      if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
      if ( ((int)m_pEntity[621].__vftable & 4) == 0 )
      {
        v8 = (float *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[3].SetRefEHandle)(a1: m_pEntity);
        flBestDist = *v8 - viewPosition->x;
        *(float *)&pBestScreen = v8[1] - viewPosition->y;
        *(float *)&i = v8[2] - viewPosition->z;
        C_BaseEntity::GetVectors(
          this: (C_BaseEntity *)m_pEntity,
          pForward: nullptr,
          pRight: nullptr,
          pUp: (Vector *)pBestScreen);
        if ( (float)((float)((float)(vecOut.y * *(float *)&pBestScreen) + (float)(vecOut.x * flBestDist))
                   + (float)(vecOut.z * *(float *)&i)) <= 0.0
          && ((int)m_pEntity[621].__vftable & 1) != 0
          && C_VGuiScreen::IsVisibleToTeam(this: (C_VGuiScreen *)m_pEntity, nTeam)
          && BYTE1(m_pEntity[624].__vftable) != 0
          && (((int)m_pEntity[621].__vftable & 0x10) == 0
           || (PlayerOwner = C_VGuiScreen::GetPlayerOwner(this: (C_VGuiScreen *)m_pEntity)) == (C_BasePlayer *)localScreens.m_VguiScreens.m_pElements) )
        {
          C_BaseEntity::GetVectors(this: (C_BaseEntity *)m_pEntity, pForward: nullptr, pRight: nullptr, pUp: &v14);
          v10 = (float *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[3].SetRefEHandle)(a1: m_pEntity);
          v11 = (float)((float)(v14.y * (float)(viewPosition->y - v10[1]))
                      + (float)(v14.x * (float)(viewPosition->x - *v10)))
              + (float)(v14.z * (float)(viewPosition->z - v10[2]));
          if ( v11 >= 0.0
            && v11 <= 80.0
            && C_VGuiScreen::IntersectWithRay(
                 this: (C_VGuiScreen *)m_pEntity,
                 ray: (const Ray_t *)v12,
                 u: (float *)&localScreens.m_VguiScreens.m_Size,
                 v: (float *)&localScreens.m_VguiScreens.m_Memory.m_nGrowSize,
                 t: (float *)&v)
            && *(float *)&localScreens.m_VguiScreens.m_Size >= 0.0
            && *(float *)&localScreens.m_VguiScreens.m_Memory.m_nGrowSize >= 0.0
            && *(float *)&localScreens.m_VguiScreens.m_Size <= 1.0
            && *(float *)&localScreens.m_VguiScreens.m_Memory.m_nGrowSize <= 1.0
            && *(float *)&u > *(float *)&v )
          {
            u = __PAIR64__((unsigned int)m_pEntity, v);
          }
        }
      }
      v5 = (int)(t - 1);
    }
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&lookDir.y);
    return (C_BasePlayer *)HIDWORD(u);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10096FD0
// Name: void ClearKeyValuesCache(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearKeyValuesCache()
{
  int i; // esi
  int j; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>::FirstInorder(this: &g_KeyValuesCache.m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>::NextInorder(
              this: &g_KeyValuesCache.m_Elements.m_Tree,
              i) )
  {
    KeyValues::deleteThis(this: g_KeyValuesCache.m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem);
  }
  for ( j = CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>::FirstInorder(this: &g_KeyValuesCache.m_Elements.m_Tree);
        j != -1;
        j = CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>::NextInorder(
              this: &g_KeyValuesCache.m_Elements.m_Tree,
              i: j) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)g_KeyValuesCache.m_Elements.m_Tree.m_Elements.m_pMemory[j].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>::RemoveAll(this: &g_KeyValuesCache.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10097140
// Name: class KeyValues __near * CacheKeyValuesForFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl CacheKeyValuesForFile(KeyValues *pFilename)
{
  const char *v1; // esi
  int v2; // eax
  KeyValues *v3; // eax
  char *v4; // edi
  IBaseFileSystem *v5; // eax
  CUtlMap<char const *,KeyValues *,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  v1 = (const char *)pFilename;
  if ( pFilename != nullptr )
  {
    search.key = (const char *)pFilename;
    v2 = CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>::Find(
           this: &g_KeyValuesCache.m_Elements.m_Tree,
           &search);
    if ( v2 != -1 )
      return g_KeyValuesCache.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = (char *)KeyValues::KeyValues(this: v3, setName: v1);
  else
    v4 = nullptr;
  pFilename = (KeyValues *)v4;
  if ( filesystem != nullptr )
    v5 = &filesystem->IBaseFileSystem;
  else
    v5 = nullptr;
  KeyValues::LoadFromFile(
    this: (KeyValues *)v4,
    filesystem: v5,
    resourceName: v1,
    pathID: nullptr,
    pfnEvaluateSymbolProc: nullptr);
  CUtlDict<KeyValues *,int>::Insert(this: &g_KeyValuesCache, pName: v1, element: &pFilename);
  return (KeyValues *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x100971D0
// Name: public: virtual bool CVGuiScreenPanel::Init(class KeyValues __near *,struct VGuiScreenInitData_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVGuiScreenPanel::Init(CVGuiScreenPanel *this, KeyValues *pKeyValues, VGuiScreenInitData_t *pInitData)
{
  KeyValues *String; // eax
  const char *v6; // esi
  KeyValues *v7; // eax
  int Int; // eax
  _BYTE *v9; // esi
  int nWidth; // [esp+Ch] [ebp-4h]
  int nHeight; // [esp+18h] [ebp+8h]

  String = (KeyValues *)KeyValues::GetString(this: pKeyValues, keyName: "resfile", defaultValue: prType);
  v6 = (const char *)String;
  if ( *(_BYTE *)String != 0 )
  {
    v7 = CacheKeyValuesForFile(pFilename: String);
    this->LoadControlSettings(this, a2: v6, a3: nullptr, a4: v7, a5: nullptr);
  }
  nWidth = KeyValues::GetInt(this: pKeyValues, keyName: "pixelswide", defaultValue: 240);
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "pixelshigh", defaultValue: 160);
  nHeight = Int;
  if ( nWidth <= 0 || Int <= 0 )
    return 0;
  if ( pInitData != nullptr )
  {
    if ( pInitData->m_pEntity != nullptr )
      this->m_hEntity.m_Index = pInitData->m_pEntity->GetRefEHandle(this: pInitData->m_pEntity)->m_Index;
    else
      this->m_hEntity.m_Index = -1;
    v9 = __RTDynamicCast(
           inptr: pInitData->m_pEntity,
           VfDelta: 0,
           SrcType: &C_BaseEntity `RTTI Type Descriptor',
           TargetType: &C_VGuiScreen `RTTI Type Descriptor',
           isReference: 0);
    if ( v9 != nullptr )
      v9[2497] = KeyValues::GetInt(this: pKeyValues, keyName: "acceptsinput", defaultValue: 1) != 0;
  }
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: nWidth, tall: nHeight);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103898E0
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x10389B20
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10389FC0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x10414030
// Name: PrecacheEffectVGuiScreenPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectVGuiScreenPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectVGuiScreenPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectVGuiScreenPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10414080
// Name: DT_VGuiScreen::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_VGuiScreen::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_VGuiScreen::g_RecvTable);
  return atexit(func: DT_VGuiScreen::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104140A0
// Name: DT_VGuiScreen::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_VGuiScreen::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_VGuiScreen::ignored>();
  DT_VGuiScreen::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430D50
// Name: DT_VGuiScreen::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_VGuiScreen::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_VGuiScreen::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10414050
// Name: _dynamic_initializer_for__g_KeyValuesCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValuesCache__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_KeyValuesCache__);
}

//------------------------------------------------------------------------------
// Address: 0x10414060
// Name: _dynamic_initializer_for____g_C_VGuiScreenClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_VGuiScreenClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_VGuiScreenClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_VGuiScreenClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104140B0
// Name: _dynamic_initializer_for__g_CVGuiScreenPanelFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CVGuiScreenPanelFactory__()
{
  CPanelMetaClassMgrImp *v0; // eax

  v0 = PanelMetaClassMgr();
  return ((int (__thiscall *)(CPanelMetaClassMgrImp *, const char *, CPanelFactory<CVGuiScreenPanel,VGuiScreenInitData_t> *))v0->InstallPanelType)(
           a1: v0,
           a2: "vgui_screen_panel",
           a3: &g_CVGuiScreenPanelFactory);
}

//------------------------------------------------------------------------------
// Address: 0x104140D0
// Name: _dynamic_initializer_for____g_C_WaterBulletClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WaterBulletClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WaterBulletClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WaterBulletClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430D60
// Name: _dynamic_atexit_destructor_for__g_KeyValuesCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KeyValuesCache__()
{
  CUtlDict<KeyValues *,int>::RemoveAll(this: &g_KeyValuesCache);
  CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,KeyValues *,int>::Node_t,int,CUtlMap<char const *,KeyValues *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,KeyValues *,int>::Node_t,int>,int>>(this: &g_KeyValuesCache.m_Elements.m_Tree);
}
