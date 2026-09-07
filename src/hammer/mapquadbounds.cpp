// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapquadbounds.cpp
// Functions: 8
// ============================================================

#include "hammer\mapquadbounds.h"

//------------------------------------------------------------------------------
// Address: 0x1013DBA0
// Name: public: virtual char const __near * CMapQuadBounds::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapQuadBounds::GetType(CMapQuadBounds *this)
{
  return CMapQuadBounds::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1013DBB0
// Name: public: virtual int CMapQuadBounds::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapQuadBounds::IsMapClass(CMapQuadBounds *this, const char *Type)
{
  return Type == CMapQuadBounds::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1013DBE0
// Name: public: virtual char const __near * CMapQuadBounds::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapQuadBounds::GetDescription(CMapQuadBounds *this)
{
  return "Quad bounds helper";
}

//------------------------------------------------------------------------------
// Address: 0x1013DBF0
// Name: public: virtual class CMapClass __near * CMapQuadBounds::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapQuadBounds *__thiscall CMapQuadBounds::CopyFrom(CMapQuadBounds *this, CMapClass *pObject, bool bUpdateDependencies)
{
  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pObject, bUpdateDependencies);
  this->m_vLowerLeft.x = *(float *)&pObject[1].__vftable;
  this->m_vLowerLeft.y = *(float *)&pObject[1].m_nObjectID;
  this->m_vLowerLeft.z = *(float *)&pObject[1].m_pParent;
  this->m_vUpperLeft = *(Vector *)&pObject[1].m_eSelectionState;
  this->m_vLowerRight = *(Vector *)&pObject[1].m_Origin.y;
  this->m_vUpperRight.x = *(float *)&pObject[1].dwKept;
  this->m_vUpperRight.y = *(float *)&pObject[1].m_CullBox.__vftable;
  this->m_vUpperRight.z = pObject[1].m_CullBox.bmins.x;
  this->m_nError = LODWORD(pObject[1].m_CullBox.bmins.y);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013DCB0
// Name: public: CMapQuadBounds::CMapQuadBounds(void)
// Source: json
//------------------------------------------------------------------------------
CMapQuadBounds *__thiscall CMapQuadBounds::CMapQuadBounds(CMapQuadBounds *this)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapQuadBounds_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapQuadBounds_vtbl *)&CMapQuadBounds::`vftable';
  this->m_vLowerLeft.x = 0.0;
  this->m_vLowerLeft.y = 0.0;
  this->m_vLowerLeft.z = 0.0;
  this->m_vUpperLeft.x = 0.0;
  this->m_vUpperLeft.y = 0.0;
  this->m_vUpperLeft.z = 0.0;
  this->m_vLowerRight.x = 0.0;
  this->m_vLowerRight.y = 0.0;
  this->m_vLowerRight.z = 0.0;
  this->m_vUpperRight.x = 0.0;
  this->m_vUpperRight.y = 0.0;
  this->m_vUpperRight.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013DDD0
// Name: public: virtual class CMapClass __near * CMapQuadBounds::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapQuadBounds *__thiscall CMapQuadBounds::Copy(CMapQuadBounds *this, BOOL bUpdateDependencies)
{
  CMapQuadBounds *v3; // eax
  CMapQuadBounds *v4; // esi

  v3 = (CMapQuadBounds *)operator new(nSize: 0x10Cu);
  if ( v3 != nullptr )
    v4 = CMapQuadBounds::CMapQuadBounds(this: v3);
  else
    v4 = nullptr;
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1013DE50
// Name: public: static class CMapClass __near * CMapQuadBounds::CreateQuadBounds(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapQuadBounds *__cdecl CMapQuadBounds::CreateQuadBounds()
{
  CMapQuadBounds *v0; // eax

  v0 = (CMapQuadBounds *)operator new(nSize: 0x10Cu);
  if ( v0 != nullptr )
    return CMapQuadBounds::CMapQuadBounds(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013DF10
// Name: public: virtual void CMapQuadBounds::PresaveWorld(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapQuadBounds::PresaveWorld(CMapQuadBounds *this)
{
  CMapClass *v2; // eax
  CMapEntity *v3; // eax
  CMapEntity *v4; // edi
  CMapSolid *ChildOf; // eax
  int v6; // ebx
  BlockArray<CMapFace,6,86> *p_Faces; // edi
  CMapFace *v8; // edi
  float *p_x; // eax
  double v10; // st7
  float *v11; // eax
  float *v12; // eax
  float *v13; // edi
  void (__thiscall *SetKeyValue)(CEditGameClass *, const char *, const char *); // eax
  CEditGameClass *v15; // edi
  char pszName[52]; // [esp+24h] [ebp-118h] BYREF
  _BYTE szCurrentTexture_208[20]; // [esp+128h] [ebp-14h] OVERLAPPED

  v2 = this->GetParent(this);
  v3 = (CMapEntity *)__RTDynamicCast(
                       inptr: v2,
                       VfDelta: 0,
                       SrcType: &CMapClass `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  v4 = v3;
  *(_DWORD *)&szCurrentTexture_208[4] = v3;
  if ( v3 != nullptr )
  {
    ChildOf = CMapEntity::GetChildOfType<CMapSolid>(this: v3, ignoredArg: nullptr);
    if ( ChildOf != nullptr )
    {
      v6 = 0;
      *(_DWORD *)szCurrentTexture_208 = ChildOf->Faces.nCount;
      szCurrentTexture_208[19] = 0;
      if ( *(int *)szCurrentTexture_208 > 0 )
      {
        p_Faces = &ChildOf->Faces;
        for ( *(_DWORD *)&szCurrentTexture_208[12] = &ChildOf->Faces;
              ;
              p_Faces = *(BlockArray<CMapFace,6,86> **)&szCurrentTexture_208[12] )
        {
          if ( v6 >= p_Faces->nCount )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v6, p_Faces->nCount);
            BlockArray<CMapFace,6,86>::SetCount(this: p_Faces, nObjects: v6 + 1);
          }
          v8 = (CMapFace *)(*(_DWORD *)(*(_DWORD *)&szCurrentTexture_208[12] + 4 * (v6 / 6u)) + 444 * (v6 % 6u));
          CMapFace::GetTextureName(this: v8, pszName);
          *(_DWORD *)&szCurrentTexture_208[8] = v8->nPoints;
          if ( _V_stricmp(s1: pszName, s2: "tools/toolsnodraw") != 0 )
          {
            if ( szCurrentTexture_208[19] != 0 )
            {
              this->m_nError = 1;
            }
            else if ( *(_DWORD *)&szCurrentTexture_208[8] == 4 )
            {
              p_x = &v8->Points->x;
              v10 = *p_x;
              szCurrentTexture_208[19] = 1;
              this->m_vLowerLeft.x = v10;
              this->m_vLowerLeft.y = p_x[1];
              this->m_vLowerLeft.z = p_x[2];
              v11 = &v8->Points->x;
              this->m_vLowerRight.x = v11[3];
              this->m_vLowerRight.y = v11[4];
              this->m_vLowerRight.z = v11[5];
              v12 = &v8->Points->x;
              this->m_vUpperRight.x = v12[6];
              this->m_vUpperRight.y = v12[7];
              this->m_vUpperRight.z = v12[8];
              v13 = &v8->Points->x;
              this->m_vUpperLeft.x = v13[9];
              this->m_vUpperLeft.y = v13[10];
              this->m_vUpperLeft.z = v13[11];
              this->m_nError = 0;
            }
            else
            {
              this->m_nError = 2;
            }
          }
          if ( ++v6 >= *(int *)szCurrentTexture_208 )
            break;
        }
        v4 = *(CMapEntity **)&szCurrentTexture_208[4];
      }
      sprintf(string: buf_0, format: "%g %g %g", this->m_vLowerLeft.x, this->m_vLowerLeft.y, this->m_vLowerLeft.z);
      SetKeyValue = v4->SetKeyValue;
      v15 = &v4->CEditGameClass;
      SetKeyValue(this: v15, a2: "lowerleft", a3: buf_0);
      sprintf(string: buf_0, format: "%g %g %g", this->m_vUpperLeft.x, this->m_vUpperLeft.y, this->m_vUpperLeft.z);
      v15->SetKeyValue(this: v15, a2: "upperleft", a3: buf_0);
      sprintf(string: buf_0, format: "%g %g %g", this->m_vLowerRight.x, this->m_vLowerRight.y, this->m_vLowerRight.z);
      v15->SetKeyValue(this: v15, a2: "lowerright", a3: buf_0);
      sprintf(string: buf_0, format: "%g %g %g", this->m_vUpperRight.x, this->m_vUpperRight.y, this->m_vUpperRight.z);
      v15->SetKeyValue(this: v15, a2: "upperright", a3: buf_0);
      sprintf(string: buf_0, format: "%i", this->m_nError);
      v15->SetKeyValue(this: v15, a2: "error", a3: buf_0);
    }
  }
}
