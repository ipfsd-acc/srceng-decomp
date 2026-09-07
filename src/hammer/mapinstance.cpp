// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapinstance.cpp
// Functions: 26
// ============================================================

#include "hammer\mapinstance.h"

//------------------------------------------------------------------------------
// Address: 0x1012E9D0
// Name: public: virtual char const __near * CMapInstance::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapInstance::GetType(CMapInstance *this)
{
  return CMapInstance::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1012E9E0
// Name: public: virtual int CMapInstance::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapInstance::IsMapClass(CMapInstance *this, const char *Type)
{
  return Type == CMapInstance::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1012EA00
// Name: public: static void CMapInstance::SetInstancePath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapInstance::SetInstancePath(const char *pszInstancePath)
{
  strcpy(CMapInstance::m_InstancePath, pszInstancePath);
  _V_strlower(start: CMapInstance::m_InstancePath);
  V_FixSlashes(pname: CMapInstance::m_InstancePath, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x1012EA40
// Name: public: virtual char const __near * CMapInstance::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapInstance::GetDescription(CMapInstance *this)
{
  return "Instance";
}

//------------------------------------------------------------------------------
// Address: 0x1012EA50
// Name: public: virtual void CMapInstance::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInstance::CalcBounds(CMapInstance *this, int bFullUpdate)
{
  CMapClass *v3; // eax
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm4_4
  matrix3x4_t Instance3x4Matrix; // [esp+4h] [ebp-60h] BYREF
  Vector vecMins; // [esp+34h] [ebp-30h] BYREF
  Vector vecMaxs; // [esp+40h] [ebp-24h] BYREF
  Vector vecExpandedMaxs; // [esp+4Ch] [ebp-18h] BYREF
  Vector vecExpandedMins; // [esp+58h] [ebp-Ch] BYREF

  CMapClass::CalcBounds(this, bFullUpdate);
  if ( this->m_pInstancedMap != nullptr
    && this->GetParent(this) != nullptr
    && this->m_pInstancedMap->m_pWorld != nullptr )
  {
    v3 = this->GetParent(this);
    v3->GetOrigin(this: v3, a2: &this->m_Origin);
    AngleMatrix(angles: &this->m_Angles, position: &this->m_Origin, matrix: &Instance3x4Matrix);
    this->m_pInstancedMap->m_pWorld->CalcBounds(this: this->m_pInstancedMap->m_pWorld, a2: 1);
    CMapClass::GetBoundingBox(this: this->m_pInstancedMap->m_pWorld, mins: &vecMins, maxs: &vecMaxs);
    TransformAABB(
      transform: &Instance3x4Matrix,
      vecMinsIn: &vecMins,
      vecMaxsIn: &vecMaxs,
      vecMinsOut: &vecExpandedMins,
      vecMaxsOut: &vecExpandedMaxs);
    BoundBox::UpdateBounds(this: &this->m_CullBox, mins: &vecExpandedMins, maxs: &vecExpandedMaxs);
    BoundBox::UpdateBounds(this: &this->m_BoundingBox, mins: &vecExpandedMins, maxs: &vecExpandedMaxs);
    BoundBox::UpdateBounds(this: &this->m_Render2DBox, mins: &vecExpandedMins, maxs: &vecExpandedMaxs);
  }
  else
  {
    x = this->m_Origin.x;
    vecExpandedMaxs.x = x - 32.0;
    y = this->m_Origin.y;
    vecExpandedMaxs.y = y - 32.0;
    z = this->m_Origin.z;
    vecExpandedMaxs.z = z - 32.0;
    vecExpandedMins.x = x + 32.0;
    vecExpandedMins.y = y + 32.0;
    vecExpandedMins.z = z + 32.0;
    BoundBox::UpdateBounds(this: &this->m_CullBox, mins: &vecExpandedMaxs, maxs: &vecExpandedMins);
    BoundBox::UpdateBounds(this: &this->m_BoundingBox, mins: &vecExpandedMaxs, maxs: &vecExpandedMins);
    BoundBox::UpdateBounds(this: &this->m_Render2DBox, mins: &vecExpandedMaxs, maxs: &vecExpandedMins);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012EBD0
// Name: public: virtual void CMapInstance::UpdateChild(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInstance::UpdateChild(CMapInstance *this, CMapClass *pChild)
{
  this->CalcBounds(this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1012EBE0
// Name: public: virtual class CMapEntity __near * CMapInstance::FindChildByKeyValue(char const __near *,char const __near *,bool __near *,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__thiscall CMapInstance::FindChildByKeyValue(
        CMapInstance *this,
        const char *key,
        const char *value,
        bool *bIsInInstance,
        VMatrix *InstanceMatrix)
{
  CMapDoc *m_pInstancedMap; // eax
  int v6; // ebx
  const VMatrix *v7; // eax
  VMatrix v9; // [esp+4h] [ebp-C4h] BYREF
  VMatrix Result; // [esp+44h] [ebp-84h] BYREF
  VMatrix LocalInstanceMatrix; // [esp+84h] [ebp-44h] BYREF
  CMapInstance *v12; // [esp+C4h] [ebp-4h]

  m_pInstancedMap = this->m_pInstancedMap;
  v12 = this;
  if ( m_pInstancedMap != nullptr && bIsInInstance != nullptr )
  {
    v6 = (int)m_pInstancedMap->m_pWorld->FindChildByKeyValue(
                this: m_pInstancedMap->m_pWorld,
                a2: key,
                a3: value,
                a4: nullptr,
                a5: nullptr);
    if ( v6 != 0 )
    {
      if ( *bIsInInstance )
        goto LABEL_7;
      *bIsInInstance = true;
      if ( InstanceMatrix != nullptr )
      {
        MatrixSetIdentity(dst: InstanceMatrix);
LABEL_7:
        if ( InstanceMatrix != nullptr )
        {
          MatrixSetIdentity(dst: &LocalInstanceMatrix);
          AngleMatrix(angles: &v12->m_Angles, position: &v12->m_Origin, matrix: (matrix3x4_t *)&LocalInstanceMatrix);
          v7 = VMatrix::operator*(this: InstanceMatrix, result: &v9, vm: &LocalInstanceMatrix);
          VMatrix::operator=(this: &Result, mOther: v7);
          VMatrix::operator=(this: InstanceMatrix, mOther: &Result);
        }
      }
    }
    return (CMapEntity *)v6;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1012ECB0
// Name: public: virtual void CMapInstance::InstanceMoved(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInstance::InstanceMoved(CMapInstance *this)
{
  CMapDoc *m_pInstancedMap; // ecx

  m_pInstancedMap = this->m_pInstancedMap;
  if ( m_pInstancedMap != nullptr )
    CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)m_pInstancedMap);
}

//------------------------------------------------------------------------------
// Address: 0x1012ECC0
// Name: public: virtual class CMapClass __near * CMapInstance::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapInstance *__thiscall CMapInstance::CopyFrom(CMapInstance *this, CVisGroup *pObject, bool bUpdateDependencies)
{
  char *v4; // edi
  char *v5; // eax
  char v6; // cl
  CMapDoc *v7; // ecx

  v4 = (char *)__RTDynamicCast(
                 inptr: pObject,
                 VfDelta: 0,
                 SrcType: &CMapClass `RTTI Type Descriptor',
                 TargetType: &CMapInstance `RTTI Type Descriptor',
                 isReference: 0);
  if ( pObject != nullptr )
  {
    CMapClass::CopyFrom(this, pFrom: pObject, bUpdateDependencies);
    this->m_Angles.x = *((float *)v4 + 54);
    v5 = v4 + 228;
    this->m_Angles.y = *((float *)v4 + 55);
    this->m_Angles.z = *((float *)v4 + 56);
    do
    {
      v6 = *v5;
      v5[(char *)this - v4] = *v5;
      ++v5;
    }
    while ( v6 != 0 );
    v7 = *((CMapDoc **)v4 + 122);
    this->m_pInstancedMap = v7;
    if ( v7 != nullptr )
    {
      CMapDoc::AddReference(this: v7);
      this->m_pInstancedMap->Update(this: this->m_pInstancedMap);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012ED60
// Name: public: virtual void CMapInstance::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInstance::Render3D(CMapInstance *this, CRender3D *pRender)
{
  CMapDoc *m_pInstancedMap; // eax

  m_pInstancedMap = this->m_pInstancedMap;
  if ( m_pInstancedMap != nullptr )
    CRender3D::RenderInstanceMapClass(
      this: pRender,
      pInstanceClass: this,
      pMapClass: m_pInstancedMap->m_pWorld,
      InstanceOrigin: &this->m_Origin,
      InstanceAngles: &this->m_Angles);
}

//------------------------------------------------------------------------------
// Address: 0x1012ED90
// Name: public: void CMapInstance::SwitchTo(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapInstance::SwitchTo(CMapInstance *this@<ecx>, int a2@<ebx>)
{
  void *v2; // edi
  CMapDoc *m_pInstancedMap; // ecx
  float v4; // esi
  float v5; // eax
  int v6; // ecx
  void *v7; // eax
  _DWORD *v8; // esi
  float *v9; // ebx
  void *v10; // eax
  int v11; // ecx
  void *v12; // eax
  void *v13; // edi
  CCamera **v14; // eax
  CCamera *v15; // esi
  float v16; // xmm1_4
  float v17; // xmm2_4
  CMapView3D *v18; // esi
  CCamera **v19; // esi
  matrix3x4_t out; // [esp+10h] [ebp-100h] BYREF
  matrix3x4_t matrix; // [esp+40h] [ebp-D0h] BYREF
  matrix3x4_t in1; // [esp+70h] [ebp-A0h] BYREF
  VMatrix v24; // [esp+A0h] [ebp-70h] BYREF
  CCamera **v25; // [esp+E0h] [ebp-30h]
  QAngle InstanceAngles; // [esp+E4h] [ebp-2Ch] BYREF
  CMapDoc *pCurrentDoc; // [esp+F0h] [ebp-20h] BYREF
  CMapView3D *pViewNew3D; // [esp+F4h] [ebp-1Ch]
  QAngle CameraAngles; // [esp+F8h] [ebp-18h] BYREF
  __POSITION *PositionNewView; // [esp+104h] [ebp-Ch]
  float v31; // [esp+108h] [ebp-8h]
  CMapView3D *pViewCurrent3D; // [esp+10Ch] [ebp-4h]

  v2 = this;
  m_pInstancedMap = this->m_pInstancedMap;
  pViewNew3D = (CMapView3D *)v2;
  if ( m_pInstancedMap != nullptr )
  {
    v4 = *(float *)&CMapDoc::m_pMapDoc;
    LODWORD(v24.m[3][3]) = CMapDoc::m_pMapDoc;
    CMapDoc::ShowWindow(this: m_pInstancedMap, bIsVisible: true);
    CMapDoc::ActivateMapDoc(pDoc: *((__POSITION **)v2 + 122));
    v5 = COERCE_FLOAT((*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v4) + 104))(a1: COERCE_FLOAT(LODWORD(v4))));
    v6 = *((_DWORD *)v2 + 122);
    CameraAngles.y = v5;
    pCurrentDoc = (CMapDoc *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 104))(a1: v6);
    if ( LODWORD(CameraAngles.y) != 0 )
    {
      while ( pCurrentDoc != nullptr )
      {
        v7 = (void *)(*(int (__thiscall **)(float, float *, _DWORD))(*(_DWORD *)LODWORD(v4) + 108))(
                       a1: COERCE_FLOAT(LODWORD(v4)),
                       a2: &CameraAngles.y,
                       a3: 0);
        v8 = __RTDynamicCast(
               inptr: v7,
               VfDelta: (int)&CView `RTTI Type Descriptor',
               SrcType: &CMapView `RTTI Type Descriptor',
               TargetType: nullptr,
               isReference: a2);
        v9 = (float *)__RTDynamicCast(
                        inptr: v8,
                        VfDelta: 0,
                        SrcType: &CMapView `RTTI Type Descriptor',
                        TargetType: &CMapView2D `RTTI Type Descriptor',
                        isReference: 0);
        v10 = __RTDynamicCast(
                inptr: v8,
                VfDelta: 0,
                SrcType: &CMapView `RTTI Type Descriptor',
                TargetType: &CMapView3D `RTTI Type Descriptor',
                isReference: 0);
        v11 = *((_DWORD *)v2 + 122);
        a2 = 0;
        LODWORD(CameraAngles.x) = v10;
        v12 = (void *)(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 108))(a1: v11);
        v13 = __RTDynamicCast(
                inptr: v12,
                VfDelta: (int)&pCurrentDoc,
                SrcType: nullptr,
                TargetType: &CView `RTTI Type Descriptor',
                isReference: (int)&CMapView `RTTI Type Descriptor');
        *(float *)&pViewCurrent3D = COERCE_FLOAT(
                                      __RTDynamicCast(
                                        inptr: v13,
                                        VfDelta: 0,
                                        SrcType: &CMapView `RTTI Type Descriptor',
                                        TargetType: &CMapView2D `RTTI Type Descriptor',
                                        isReference: 0));
        v14 = (CCamera **)__RTDynamicCast(
                            inptr: v13,
                            VfDelta: 0,
                            SrcType: &CMapView `RTTI Type Descriptor',
                            TargetType: &CMapView3D `RTTI Type Descriptor',
                            isReference: 0);
        v25 = v14;
        if ( v9 != nullptr && *(float *)&pViewCurrent3D != 0.0 || LODWORD(CameraAngles.x) != 0 && v14 != nullptr )
        {
          v15 = (CCamera *)v8[4];
          CCamera::GetViewPoint(this: v15, ViewPoint: (Vector *)&CameraAngles.z);
          if ( v9 != nullptr )
          {
            v16 = *(float *)&PositionNewView - *(float *)&pViewNew3D->m_xConnPtContainer.m_vtbl;
            v17 = v31 - *(float *)&pViewNew3D->m_pModuleState;
            v18 = pViewCurrent3D;
            CameraAngles.z = CameraAngles.z - *(float *)&pViewNew3D->m_bResultExpected;
            *(float *)&PositionNewView = v16;
            v31 = v17;
            CCamera::SetViewPoint(this: pViewCurrent3D->m_pCamera, ViewPoint: (const Vector *)&CameraAngles.z);
            CCamera::SetZoom(this: v18->m_pCamera, fScale: v9[56]);
          }
          else
          {
            CameraAngles.x = CCamera::GetPitch(this: v15);
            *(float *)&pViewCurrent3D = CCamera::GetYaw(this: v15);
            InstanceAngles.z = CCamera::GetRoll(this: v15);
            InstanceAngles.x = CameraAngles.x;
            LODWORD(InstanceAngles.y) = pViewCurrent3D;
            *(_QWORD *)&v24.m[3][1] = (unsigned int)pViewNew3D->m_pwndTitle;
            v24.m[3][0] = 0.0;
            AngleMatrix(
              angles: (const QAngle *)v24.m[3],
              position: (const Vector *)&pViewNew3D->m_bResultExpected,
              matrix: &in1);
            MatrixInvert(in: &in1, &out);
            AngleMatrix(angles: &InstanceAngles, position: (const Vector *)&CameraAngles.z, &matrix);
            ConcatTransforms(in1: &out, in2: &matrix, out: (matrix3x4_t *)&v24);
            CameraAngles.z = v24.m[0][3];
            PositionNewView = (__POSITION *)LODWORD(v24.m[1][3]);
            v31 = v24.m[2][3];
            ConcatTransforms(&in1, in2: &matrix, out: (matrix3x4_t *)&v24);
            MatrixAngles(src: &v24, vAngles: &InstanceAngles);
            v19 = v25;
            CCamera::SetViewPoint(this: v25[35], ViewPoint: (const Vector *)&CameraAngles.z);
            CCamera::SetPitch(this: v19[35], fDegrees: InstanceAngles.x);
            CCamera::SetYaw(this: v19[35], fDegrees: InstanceAngles.y);
          }
          (*(void (__thiscall **)(void *, int))(*(_DWORD *)v13 + 20))(a1: v13, a2: 256);
        }
        if ( LODWORD(CameraAngles.y) == 0 )
          break;
        v4 = v24.m[3][3];
        v2 = pViewNew3D;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F090
// Name: protected: virtual void CMapInstance::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInstance::DoTransform(CMapInstance *this, const matrix3x4_t *matrix)
{
  CMapClass *v3; // eax
  CMapEntity *v4; // ebx
  char string[32]; // [esp+20h] [ebp-B4h] BYREF
  char szValue[80]; // [esp+40h] [ebp-94h] BYREF
  matrix3x4_t fCurrentMatrix; // [esp+90h] [ebp-44h] BYREF

  v3 = this->GetParent(this);
  v3->GetOrigin(this: v3, a2: &this->m_Origin);
  AngleMatrix(angles: &this->m_Angles, matrix: (matrix3x4_t *)&szValue[52]);
  ConcatTransforms(
    in1: matrix,
    in2: (const matrix3x4_t *)&szValue[52],
    out: (matrix3x4_t *)&fCurrentMatrix.m_flMatVal[1][1]);
  MatrixAngles(src: (const VMatrix *)&fCurrentMatrix.m_flMatVal[1][1], vAngles: &this->m_Angles);
  v4 = (CMapEntity *)__RTDynamicCast(
                       inptr: this->m_pParent,
                       VfDelta: 0,
                       SrcType: &CMapAtom `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  if ( v4 != nullptr )
  {
    sprintf(string: &string[4], format: "%g %g %g", this->m_Angles.x, this->m_Angles.y, this->m_Angles.z);
    CMapEntity::NotifyChildKeyChanged(this: v4, pChild: this, szKey: "angles", szValue: &string[4]);
  }
  this->InstanceMoved(this);
}

//------------------------------------------------------------------------------
// Address: 0x1012F170
// Name: public: virtual void CMapInstance::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInstance::OnParentKeyChanged(CMapInstance *this, const char *szKey, const char *szValue)
{
  if ( _V_stricmp(s1: szKey, s2: "angles") == 0 )
  {
    sscanf(string: szValue, format: "%f %f %f", &this->m_Angles, &this->m_Angles.y, &this->m_Angles.z);
    this->PostUpdate(this, a2: Notify_Changed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F1D0
// Name: public: virtual void CMapInstance::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInstance::Render2D(CMapInstance *this, CRender2D *pRender)
{
  CMapView *m_pView; // eax
  CMapView2D *p_m_bActive; // ecx
  CMapDoc *m_pInstancedMap; // eax
  unsigned __int8 b; // cl
  unsigned __int8 g; // dl
  unsigned __int8 clrSelection; // al
  Vector vCenter; // [esp+8h] [ebp-34h] BYREF
  Vector vecMins; // [esp+14h] [ebp-28h] BYREF
  Vector vecMaxs; // [esp+20h] [ebp-1Ch] BYREF
  Vector2D pt2; // [esp+2Ch] [ebp-10h] BYREF
  Vector2D pt; // [esp+34h] [ebp-8h] BYREF

  m_pView = pRender->m_pView;
  if ( m_pView != nullptr )
    p_m_bActive = (CMapView2D *)&m_pView[-4].m_bActive;
  else
    p_m_bActive = nullptr;
  m_pInstancedMap = this->m_pInstancedMap;
  if ( m_pInstancedMap != nullptr )
    CMapView2D::RenderInstance(
      this: p_m_bActive,
      pInstanceClass: this,
      pMapClass: m_pInstancedMap->m_pWorld,
      InstanceOrigin: &this->m_Origin,
      InstanceAngles: &this->m_Angles);
  if ( this->m_pManifestMap == nullptr )
  {
    CMapClass::GetRender2DBox(this, mins: &vecMins, maxs: &vecMaxs);
    CRender::TransformPoint(this: pRender, vClient: &pt, vWorld: &vecMins);
    CRender::TransformPoint(this: pRender, vClient: &pt2, vWorld: &vecMaxs);
    if ( this->IsSelected(this) )
    {
      CRender::SetDrawColor(
        this: pRender,
        r: Options.colors.clrSelection,
        g: BYTE1(Options.colors.clrSelection),
        b: BYTE2(Options.colors.clrSelection));
      b = BYTE2(Options.colors.clrSelection);
      g = BYTE1(Options.colors.clrSelection);
      clrSelection = Options.colors.clrSelection;
    }
    else
    {
      CRender::SetDrawColor(this: pRender, r: this->r, g: this->g, b: this->b);
      b = this->b;
      g = this->g;
      clrSelection = this->r;
    }
    CRender::SetHandleColor(this: pRender, r: clrSelection, g, b);
    pRender->DrawBox(this: pRender, a2: &vecMins, a3: &vecMaxs, a4: false);
    if ( CRender::IsActiveView(this: pRender)
      && (int)(float)(fabs(pt.x - pt2.x) + 1.0) > 6
      && (int)(float)(fabs(pt.y - pt2.y) + 1.0) > 6 )
    {
      CRender::SetHandleStyle(this: pRender, size: 4, type: 4);
      vCenter.x = (float)(vecMaxs.x + vecMins.x) * 0.5;
      vCenter.y = (float)(vecMins.y + vecMaxs.y) * 0.5;
      vCenter.z = (float)(vecMaxs.z + vecMins.z) * 0.5;
      CRender::DrawHandle(this: pRender, &vCenter, vOffset: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F380
// Name: public: virtual bool CMapInstance::IsEditable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapInstance::IsEditable(CMapInstance *this)
{
  CManifestMap *m_pManifestMap; // ecx

  m_pManifestMap = this->m_pManifestMap;
  return m_pManifestMap != nullptr && CManifestMap::IsEditable(this: m_pManifestMap);
}

//------------------------------------------------------------------------------
// Address: 0x1012F3A0
// Name: public: bool CMapInstance::IsInstanceVisible(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapInstance::IsInstanceVisible(CMapInstance *this)
{
  CManifestMap *m_pManifestMap; // eax

  m_pManifestMap = this->m_pManifestMap;
  if ( m_pManifestMap != nullptr )
  {
    if ( !m_pManifestMap->m_bVisible )
      return 0;
  }
  else if ( CMapDoc::m_pMapDoc != nullptr && CMapDoc::m_pMapDoc->m_tShowInstance == INSTANCES_HIDE )
  {
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012F3D0
// Name: public: void CMapInstance::UpdateInstanceMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInstance::UpdateInstanceMap(CMapInstance *this)
{
  this->CalcBounds(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1012F460
// Name: public: CMapInstance::CMapInstance(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMapInstance *__thiscall CMapInstance::CMapInstance(
        CMapInstance *this,
        const char *pszBaseFileName,
        const char *pszInstanceFileName)
{
  bool IsNewDocumentVisible; // al
  CMapDoc *v5; // ebx
  AFX_MODULE_STATE *ModuleState; // eax
  CMapDoc *v7; // eax
  bool bSaveVisible; // [esp+24h] [ebp+Ch]

  CMapClass::CMapClass(this);
  this->__vftable = (CMapInstance_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapInstance_vtbl *)&CMapInstance::`vftable';
  this->m_Angles.x = 0.0;
  this->m_Angles.y = 0.0;
  this->m_Angles.z = 0.0;
  this->m_pInstancedMap = nullptr;
  this->m_FileName[0] = 0;
  this->m_pManifestMap = nullptr;
  if ( *pszInstanceFileName == 0
    || CInstancingHelper::ResolveInstancePath(
         pFileSystem: g_pFullFileSystem,
         pBaseFilename: pszBaseFileName,
         pInstanceFilename: pszInstanceFileName,
         pInstanceDirectory: CMapInstance::m_InstancePath,
         pResolvedInstanceFilename: this->m_FileName,
         nBufferSize: 260) == 0 )
  {
    return this;
  }
  IsNewDocumentVisible = CHammer::IsNewDocumentVisible();
  v5 = CMapDoc::m_pMapDoc;
  bSaveVisible = IsNewDocumentVisible;
  CHammer::SetIsNewDocumentVisible(bIsVisible: false);
  ModuleState = AfxGetModuleState();
  v7 = (CMapDoc *)((int (__thiscall *)(CWinApp *, char *))ModuleState->m_pCurrentWinApp->__vftable[1].GetRuntimeClass)(
                    a1: ModuleState->m_pCurrentWinApp,
                    a2: this->m_FileName);
  this->m_pInstancedMap = v7;
  if ( v7 != nullptr )
  {
    CMapDoc::AddReference(this: v7);
    this->m_pInstancedMap->Update(this: this->m_pInstancedMap);
  }
  CMapDoc::SetActiveMapDoc(pDoc: v5);
  CHammer::SetIsNewDocumentVisible(bIsVisible: bSaveVisible);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012F5A0
// Name: public: virtual class CMapClass __near * CMapInstance::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapInstance::Copy(CMapInstance *this, BOOL bUpdateDependencies)
{
  CMapClass *v3; // eax
  CMapClass *v4; // esi

  v3 = (CMapClass *)operator new(nSize: 0x1F0u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    CMapClass::CMapClass(this: v3);
    v4->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
    v4->__vftable = (CMapClass_vtbl *)&CMapInstance::`vftable';
    v4[1].__vftable = nullptr;
    v4[1].m_nObjectID = 0;
    v4[1].m_pParent = nullptr;
    v4[2].m_CullBox.bmaxs.x = 0.0;
    LOBYTE(v4[1].m_eSelectionState) = 0;
    v4[2].m_CullBox.bmaxs.y = 0.0;
  }
  else
  {
    v4 = nullptr;
  }
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1012F660
// Name: public: void CMapInstance::SetManifest(class CManifestMap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInstance::SetManifest(CMapInstance *this, CManifestMap *pManifestMap)
{
  char *m_FileName; // edx
  char *m_pszData; // ecx
  char v4; // al

  this->m_Angles.x = 0.0;
  this->m_Angles.y = 0.0;
  this->m_Angles.z = 0.0;
  m_FileName = this->m_FileName;
  this->m_pInstancedMap = nullptr;
  this->m_FileName[0] = 0;
  this->m_pManifestMap = pManifestMap;
  this->m_pInstancedMap = pManifestMap->m_Map;
  m_pszData = pManifestMap->m_AbsoluteMapFileName.m_pszData;
  do
  {
    v4 = *m_pszData;
    *m_FileName++ = *m_pszData++;
  }
  while ( v4 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1012F6C0
// Name: class CMapClass __near * CMapInstance_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CMapInstance_CreateObject()
{
  CMapClass *v0; // eax
  CMapClass *v1; // esi

  v0 = (CMapClass *)operator new(nSize: 0x1F0u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CMapClass::CMapClass(this: v0);
  v1->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
  v1->__vftable = (CMapClass_vtbl *)&CMapInstance::`vftable';
  v1[1].__vftable = nullptr;
  v1[1].m_nObjectID = 0;
  v1[1].m_pParent = nullptr;
  v1[2].m_CullBox.bmaxs.x = 0.0;
  LOBYTE(v1[1].m_eSelectionState) = 0;
  v1[2].m_CullBox.bmaxs.y = 0.0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1012F780
// Name: public: static class CMapClass __near * CMapInstance::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapInstance *__cdecl CMapInstance::Create(CHelperInfo *pHelperInfo, CMapEntity *pParent)
{
  const char *Value; // eax
  CMapDoc *v3; // edi
  char *v4; // eax
  char *v5; // edx
  char v6; // cl
  CMapInstance *v7; // eax
  char FileName[260]; // [esp+8h] [ebp-110h] BYREF
  int v10; // [esp+114h] [ebp-4h]

  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &pParent->m_KeyValues, pszKey: "file", piIndex: nullptr);
  v3 = CMapDoc::m_pMapDoc;
  if ( Value != nullptr )
  {
    v4 = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &pParent->m_KeyValues, pszKey: "file", piIndex: nullptr);
    v5 = (char *)(FileName - v4);
    do
    {
      v6 = *v4;
      v4[(_DWORD)v5] = *v4;
      ++v4;
    }
    while ( v6 != 0 );
  }
  else
  {
    FileName[0] = 0;
  }
  v7 = (CMapInstance *)operator new(nSize: 0x1F0u);
  v10 = 0;
  if ( v7 != nullptr )
    return CMapInstance::CMapInstance(
             this: v7,
             pszBaseFileName: v3->m_strPathName.m_pszData,
             pszInstanceFileName: FileName);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1012F840
// Name: public: virtual void CMapInstance::ReplaceTargetname(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInstance::ReplaceTargetname(CMapInstance *this, const char *szOldName, const char *szNewName)
{
  CMapClass *v4; // eax
  CMapEntity *v5; // esi
  unsigned __int16 Inorder; // di
  UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v8; // eax
  char *szValue; // ebx
  int v10; // eax
  int v11; // esi
  unsigned int v12; // esi
  void *v13; // esp
  const char *v14; // eax
  char v15; // cl
  unsigned __int8 v16[12]; // [esp+0h] [ebp-18h] BYREF
  const char *pInstanceKey; // [esp+Ch] [ebp-Ch]
  int j; // [esp+10h] [ebp-8h]
  CMapEntity *pEntity; // [esp+14h] [ebp-4h]

  CMapClass::ReplaceTargetname(this, szOldName, szNewName);
  v4 = this->GetParent(this);
  v5 = (CMapEntity *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CMapClass `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  pEntity = v5;
  Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v5->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
  j = Inorder;
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = v5->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory;
      v8 = Inorder;
      pInstanceKey = m_pMemory[v8].m_Data.elem.szKey;
      szValue = m_pMemory[v8].m_Data.elem.szValue;
      if ( V_strncasecmp(s1: pInstanceKey, s2: "replace", n: 7) == 0 )
      {
        strchr(string: szValue, chr: 0x20u);
        v11 = v10;
        if ( v10 != 0 && strcmp(szOldName, (const char *)(v10 + 1)) == 0 )
        {
          v12 = v11 - (_DWORD)szValue + 1;
          v13 = alloca(strlen(szNewName) + v12 + 1);
          strncpy(dest: v16, source: (unsigned __int8 *)szValue, count: v12);
          v14 = szNewName;
          do
          {
            v15 = *v14;
            v14[v12 + v16 - (unsigned __int8 *)szNewName] = *v14;
            ++v14;
          }
          while ( v15 != 0 );
          pEntity->SetKeyValue(this: &pEntity->CEditGameClass, a2: pInstanceKey, a3: (const char *)v16);
          Inorder = j;
        }
        v5 = pEntity;
      }
      j = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                              this: &v5->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                              i: Inorder);
      if ( j == 0xFFFF )
        break;
      Inorder = j;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F9B0
// Name: public: virtual bool CMapInstance::OnApply(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapInstance::OnApply(CMapInstance *this)
{
  CAfxStringMgr *StringManager; // eax
  CMapClass *v3; // eax
  char *v4; // eax
  CMapDoc *m_pInstancedMap; // ecx
  char *v6; // edi
  const char *Value; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  CMapDoc *v9; // eax
  CMapDoc *v10; // ecx
  CMainFrame *MainWnd; // eax
  char *v12; // eax
  bool v14; // [esp-8h] [ebp-128h]
  char FileName[260]; // [esp+4h] [ebp-11Ch] BYREF
  CMapDoc *activeDoc; // [esp+108h] [ebp-18h]
  BOOL bSaveVisible; // [esp+10Ch] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > MapFileName; // [esp+110h] [ebp-10h] BYREF
  int v19; // [esp+11Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  MapFileName.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v19 = 1;
  activeDoc = CMapDoc::m_pMapDoc;
  ATL::CSimpleStringT<char,0>::operator=(
    this: &MapFileName,
    strSrc: (ATL::CStringData *)&CMapDoc::m_pMapDoc->m_strPathName);
  v3 = this->GetParent(this);
  v4 = (char *)__RTDynamicCast(
                 inptr: v3,
                 VfDelta: 0,
                 SrcType: &CMapClass `RTTI Type Descriptor',
                 TargetType: &CMapEntity `RTTI Type Descriptor',
                 isReference: 0);
  m_pInstancedMap = this->m_pInstancedMap;
  v6 = v4;
  if ( m_pInstancedMap != nullptr )
    CMapDoc::RemoveReference(this: m_pInstancedMap);
  if ( v6 != nullptr
    && WCKeyValuesT<WCKVBase_Dict>::GetValue(
         this: (WCKeyValuesT<WCKVBase_Dict> *)(v6 + 220),
         pszKey: "file",
         piIndex: nullptr) != nullptr )
  {
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
              this: (WCKeyValuesT<WCKVBase_Dict> *)(v6 + 220),
              pszKey: "file",
              piIndex: nullptr);
    CInstancingHelper::ResolveInstancePath(
      pFileSystem: g_pFullFileSystem,
      pBaseFilename: MapFileName.m_pszData,
      pInstanceFilename: Value,
      pInstanceDirectory: CMapInstance::m_InstancePath,
      pResolvedInstanceFilename: FileName,
      nBufferSize: 260);
    if ( _V_stricmp(s1: FileName, s2: this->m_FileName) != 0 )
    {
      LOBYTE(bSaveVisible) = CHammer::IsNewDocumentVisible();
      CHammer::SetIsNewDocumentVisible(bIsVisible: false);
      strcpy(this->m_FileName, FileName);
      ModuleState = AfxGetModuleState();
      v9 = (CMapDoc *)((int (__thiscall *)(CWinApp *, char *))ModuleState->m_pCurrentWinApp->__vftable[1].GetRuntimeClass)(
                        a1: ModuleState->m_pCurrentWinApp,
                        a2: this->m_FileName);
      v14 = bSaveVisible;
      this->m_pInstancedMap = v9;
      CHammer::SetIsNewDocumentVisible(bIsVisible: v14);
    }
  }
  else
  {
    this->m_pInstancedMap = nullptr;
  }
  v10 = this->m_pInstancedMap;
  if ( v10 != nullptr )
  {
    CMapDoc::AddReference(this: v10);
    this->m_pInstancedMap->Update(this: this->m_pInstancedMap);
  }
  else
  {
    this->m_FileName[0] = 0;
  }
  MainWnd = GetMainWnd();
  CObjectProperties::MarkDataDirty(this: MainWnd->pObjectProperties);
  CMapDoc::ActivateMapDoc(pDoc: (__POSITION *)activeDoc);
  v19 = -1;
  v12 = MapFileName.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)MapFileName.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v12 + 4))(a1: v12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012FB90
// Name: public: enum GDIV_TYPE CMapInstance::GetFieldType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapInstance::GetFieldType(CMapInstance *this, char *pInstanceValue)
{
  CMapEntity *m_pObject; // ebx
  int v5; // eax
  unsigned __int16 Inorder; // si
  UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v8; // eax
  char *szValue; // edi
  const char *v10; // eax
  GDIV_TYPE TypeFromToken; // esi
  GDinputvariable TempVar; // [esp+8h] [ebp-218h] BYREF
  int len; // [esp+1F8h] [ebp-28h]
  const char *InstanceParmsPos; // [esp+1FCh] [ebp-24h]
  CUtlReferenceVector<CMapEntity> entityList; // [esp+200h] [ebp-20h] BYREF
  int v16; // [esp+21Ch] [ebp-4h]

  memset(&entityList, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
    this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&entityList,
    nGrowSize: 0,
    nInitSize: 0);
  entityList.m_Size = 0;
  entityList.m_pElements = nullptr;
  v16 = 3;
  GDinputvariable::GDinputvariable(this: &TempVar);
  LOBYTE(v16) = 4;
  CMapDoc::FindEntitiesByClassName(
    this: this->m_pInstancedMap,
    Found: &entityList,
    pszClassName: "func_instance_parms",
    bVisiblesOnly: false);
  if ( entityList.m_Size == 1
    && (m_pObject = (*entityList.m_Memory.m_pMemory)->m_pObject, strchr(string: pInstanceValue, chr: 0x20u), v5 != 0)
    && (len = v5 - (_DWORD)pInstanceValue,
        (Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &m_pObject->m_KeyValues.m_KeyValues.m_Elements.m_Tree)) != 0xFFFF) )
  {
    while ( 1 )
    {
      m_pMemory = m_pObject->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory;
      v8 = Inorder;
      szValue = m_pMemory[v8].m_Data.elem.szValue;
      if ( V_strncasecmp(s1: m_pMemory[v8].m_Data.elem.szKey, s2: "parm", n: 4) == 0 )
      {
        strchr(string: szValue, chr: 0x20u);
        InstanceParmsPos = v10;
        if ( v10 != nullptr && V_strncasecmp(s1: pInstanceValue, s2: szValue, n: len) == 0 )
          break;
      }
      Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                  this: &m_pObject->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                  i: Inorder);
      if ( Inorder == 0xFFFF )
        goto LABEL_2;
    }
    TypeFromToken = GDinputvariable::GetTypeFromToken(this: &TempVar, pszToken: InstanceParmsPos + 1);
    LOBYTE(v16) = 3;
    GDinputvariable::~GDinputvariable(this: &TempVar);
    v16 = -1;
    CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &entityList);
    return TypeFromToken;
  }
  else
  {
LABEL_2:
    LOBYTE(v16) = 3;
    GDinputvariable::~GDinputvariable(this: &TempVar);
    v16 = -1;
    CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &entityList);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FD80
// Name: public: virtual void CMapInstance::FindTargetNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInstance::FindTargetNames(
        CMapInstance *this,
        CUtlVector<char const *,CUtlMemory<char const *,int> > *Names)
{
  void *v2; // eax
  CMapEntity *v3; // ebx
  unsigned __int16 Inorder; // ax
  int v5; // eax
  char *v6; // esi
  int FieldType; // eax
  int v8; // eax
  const char *v9; // esi
  char *v10; // ebx
  int m_Size; // esi
  int m_nAllocationCount; // eax
  const char **m_pMemory; // ecx
  int v14; // eax
  const char **v15; // eax
  CMapEntity *pEntity; // [esp+8h] [ebp-8h]
  int j; // [esp+Ch] [ebp-4h]

  v2 = (void *)((int (__fastcall *)(CMapInstance *))this->GetParent)(a1: this);
  v3 = (CMapEntity *)__RTDynamicCast(
                       inptr: v2,
                       VfDelta: 0,
                       SrcType: &CMapClass `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  pEntity = v3;
  Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v3->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
  LOWORD(j) = Inorder;
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      v5 = (int)&v3->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder];
      v6 = (char *)(v5 + 92);
      if ( V_strncasecmp(s1: (const char *)(v5 + 12), s2: "replace", n: 7) == 0 )
      {
        FieldType = CMapInstance::GetFieldType(this, pInstanceValue: v6);
        if ( FieldType == 6 || FieldType == 1 || FieldType == 2 || FieldType == 3 )
        {
          strchr(string: v6, chr: 0x20u);
          if ( v8 != 0 )
          {
            v9 = (const char *)(v8 + 1);
            v10 = (char *)operator new[](nSize: strlen((const char *)(v8 + 1)) + 1);
            strcpy(v10, v9);
            m_Size = Names->m_Size;
            m_nAllocationCount = Names->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CVisGroup *,int>::Grow(
                this: (CUtlMemory<CCullTreeNode *,int> *)Names,
                num: m_Size - m_nAllocationCount + 1);
            ++Names->m_Size;
            m_pMemory = Names->m_Memory.m_pMemory;
            v14 = Names->m_Size - m_Size - 1;
            Names->m_pElements = Names->m_Memory.m_pMemory;
            if ( v14 > 0 )
              _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
            v15 = &Names->m_Memory.m_pMemory[m_Size];
            if ( v15 != nullptr )
              *v15 = v10;
            v3 = pEntity;
          }
        }
      }
      j = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                              this: &v3->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                              i: j);
      if ( j == 0xFFFF )
        break;
      Inorder = j;
    }
  }
}
