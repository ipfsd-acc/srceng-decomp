// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gamelayer.cpp
// Functions: 17
// ============================================================

#include "vgui2\game_controls\gamelayer.h"

//------------------------------------------------------------------------------
// Address: 0x004224E0
// Name: public: bool CGameLayer::HasGraphic(class CGameGraphic __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameLayer::HasGraphic(CGameLayer *this, CGameGraphic *pGraphic)
{
  int m_Size; // edx
  int v3; // eax
  CGameGraphic **i; // ecx

  m_Size = this->m_LayerGraphics.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_LayerGraphics.m_Memory.m_pMemory; pGraphic != *i; ++i )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00422510
// Name: public: void CGameLayer::StartPlaying(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameLayer::StartPlaying(CGameLayer *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_LayerGraphics.m_Size;
  for ( i = 0; i < m_Size; ++i )
    this->m_LayerGraphics.m_Memory.m_pMemory[i]->StartPlaying(this: this->m_LayerGraphics.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x00422540
// Name: public: void CGameLayer::StopPlaying(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameLayer::StopPlaying(CGameLayer *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_LayerGraphics.m_Size;
  for ( i = 0; i < m_Size; ++i )
    this->m_LayerGraphics.m_Memory.m_pMemory[i]->StopPlaying(this: this->m_LayerGraphics.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x00422570
// Name: public: void CGameLayer::AdvanceState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameLayer::AdvanceState(CGameLayer *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_LayerGraphics.m_Size;
  for ( i = 0; i < m_Size; ++i )
    this->m_LayerGraphics.m_Memory.m_pMemory[i]->AdvanceState(this: this->m_LayerGraphics.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x004225A0
// Name: public: void CGameLayer::InitAnims(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameLayer::InitAnims(CGameLayer *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_LayerGraphics.m_Size;
  for ( i = 0; i < m_Size; ++i )
    this->m_LayerGraphics.m_Memory.m_pMemory[i]->SetState(
      this: this->m_LayerGraphics.m_Memory.m_pMemory[i],
      a2: "default",
      a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x004225D0
// Name: public: class CGameGraphic __near * CGameLayer::GetGraphic(int,int)
// Source: json
//------------------------------------------------------------------------------
CGameGraphic *__thiscall CGameLayer::GetGraphic(CGameLayer *this, int x, int y)
{
  int v4; // edi
  CGameGraphic *v5; // esi

  v4 = this->m_LayerGraphics.m_Size - 1;
  if ( v4 < 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = this->m_LayerGraphics.m_Memory.m_pMemory[v4];
    if ( v5->HitTest(this: v5, a2: x, a3: y) )
      break;
    if ( --v4 < 0 )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00422620
// Name: public: class CGameGraphic __near * CGameLayer::GetMouseFocus(int,int)
// Source: json
//------------------------------------------------------------------------------
CGameGraphic *__thiscall CGameLayer::GetMouseFocus(CGameLayer *this, int x, int y)
{
  int v4; // edi
  CGameGraphic *v5; // esi

  v4 = this->m_LayerGraphics.m_Size - 1;
  if ( v4 < 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = this->m_LayerGraphics.m_Memory.m_pMemory[v4];
    if ( v5->m_bCanAcceptInput && v5->HitTest(this: v5, a2: x, a3: y) )
      break;
    if ( --v4 < 0 )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00422670
// Name: public: class CGameGraphic __near * CGameLayer::GetNextFocus(bool __near &,class CGameGraphic __near *)
// Source: json
//------------------------------------------------------------------------------
CGameGraphic *__thiscall CGameLayer::GetNextFocus(CGameLayer *this, bool *bGetNext, CGameGraphic *pCurrentGraphic)
{
  int m_Size; // edi
  int v4; // edx
  CGameGraphic *result; // eax

  m_Size = this->m_LayerGraphics.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = this->m_LayerGraphics.m_Memory.m_pMemory[v4];
    if ( *bGetNext && result->m_bCanAcceptInput )
      break;
    if ( pCurrentGraphic == result )
      *bGetNext = true;
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004226B0
// Name: public: void CGameLayer::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameLayer::Shutdown(CGameLayer *this)
{
  int m_Size; // ebx
  int v3; // esi
  CGameGraphic *v4; // ecx

  m_Size = this->m_LayerGraphics.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
    this->m_LayerGraphics.m_Size = 0;
  }
  else
  {
    do
    {
      v4 = this->m_LayerGraphics.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
        ((void (__thiscall *)(CGameGraphic *, int))v4->dtr_CGameGraphic)(a1: v4, a2: 1);
      this->m_LayerGraphics.m_Memory.m_pMemory[v3++] = nullptr;
    }
    while ( v3 < m_Size );
    this->m_LayerGraphics.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422700
// Name: CreateTextureFromVTFFile
// Source: json
//------------------------------------------------------------------------------
const ResourceBinding_t<CTextureBits> *__usercall CreateTextureFromVTFFile@<eax>(
        const char *pFileName@<edx>,
        CSheet **ppSheet)
{
  CVTFTexture *VTFTexture; // esi
  const ResourceBinding_t<CTextureBits> *v4; // ebp
  IRenderContext *v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  const void *v9; // eax
  CSheet *v10; // eax
  CSheet *v11; // eax
  bool v12; // sf
  TextureHeader_t spec; // [esp+64h] [ebp-194h] BYREF
  CUtlBuffer fBuf; // [esp+80h] [ebp-178h] BYREF
  char pResourceName[16]; // [esp+B0h] [ebp-148h] BYREF
  CUtlBuffer bufLoad; // [esp+C0h] [ebp-138h] BYREF
  char pTemp[264]; // [esp+F0h] [ebp-108h] BYREF

  *ppSheet = nullptr;
  V_ComposeFileName(path: "materials/", filename: pFileName, dest: &pTemp[4], destSize: 260);
  V_SetExtension(path: &pTemp[4], extension: "vtf", pathStringLength: 260);
  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&fBuf.m_Memory.m_nAllocationCount, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: &pTemp[4],
         a3: "GAME",
         a4: (CUtlBuffer *)&fBuf.m_Memory.m_nAllocationCount,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    VTFTexture = CreateVTFTexture();
    VTFTexture->Unserialize(this: VTFTexture, a2: (CUtlBuffer *)&fBuf.m_Memory.m_nAllocationCount, a3: false, a4: 0);
    memset(&spec.m_nDepth, 0, 24);
    fBuf.m_Memory.m_pMemory = nullptr;
    spec.m_nDepth = VTFTexture->Width(this: VTFTexture);
    *(_WORD *)&spec.m_nImageFormat = VTFTexture->Height(this: VTFTexture);
    HIBYTE(spec.m_nFlags) = 1;
    spec.m_nMultisampleType = VTFTexture->Depth(this: VTFTexture);
    LOBYTE(spec.m_nFlags) = VTFTexture->Format(this: VTFTexture);
    V_snprintf(pDest: &pResourceName[4], maxLen: 16, pFormat: "%d", s_UniqueID);
    v4 = g_pRenderDevice->FindOrCreateTexture(
           this: g_pRenderDevice,
           a2: "gamelayer",
           a3: &pResourceName[4],
           a4: &spec.m_nDepth);
    _InterlockedExchangeAdd(&v4->m_nRefCount.m_value, 1u);
    ++s_UniqueID;
    v5 = g_pRenderDevice->GetRenderContext(this: g_pRenderDevice);
    v6 = ((int (__thiscall *)(CVTFTexture *, int, _DWORD))VTFTexture->IsPreTiled)(a1: VTFTexture, a2: -1, a3: 0);
    v7 = ((int (__thiscall *)(CVTFTexture *, int))VTFTexture->ComputeTotalSize)(a1: VTFTexture, a2: v6);
    v8 = ((int (__thiscall *)(CVTFTexture *, _DWORD, _DWORD, _DWORD, int))VTFTexture->ImageData_2)(
           a1: VTFTexture,
           a2: 0,
           a3: 0,
           a4: 0,
           a5: v7);
    (*(void (__thiscall **)(IRenderContext *, const ResourceBinding_t<CTextureBits> *, float *, int))(LODWORD(spec.m_Reflectivity.x) + 104))(
      a1: v5,
      a2: v4,
      a3: &spec.m_Reflectivity.z,
      a4: v8);
    v5->Submit(this: v5);
    g_pRenderDevice->ReleaseRenderContext(this: g_pRenderDevice, a2: v5);
    _InterlockedExchangeAdd(&v4->m_nRefCount.m_value, 0xFFFFFFFF);
    v9 = VTFTexture->GetResourceData(this: VTFTexture, a2: 16u, a3: (unsigned int *)&spec.m_nWidth);
    if ( v9 != nullptr )
    {
      CUtlBuffer::CUtlBuffer(
        this: (CUtlBuffer *)&bufLoad.m_Memory.m_nAllocationCount,
        pBuffer: v9,
        nSize: *(int *)&spec.m_nWidth,
        nFlags: 8);
      v10 = (CSheet *)MemAlloc_Alloc(nSize: 0x18u);
      v11 = v10 != nullptr
          ? CSheet::CSheet(this: v10, buf: (CUtlBuffer *)&bufLoad.m_Memory.m_nAllocationCount)
          : nullptr;
      v12 = bufLoad.m_Get < 0;
      *ppSheet = v11;
      if ( !v12 && bufLoad.m_Memory.m_nAllocationCount != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)bufLoad.m_Memory.m_nAllocationCount);
    }
    DestroyVTFTexture(pTexture: VTFTexture);
    if ( fBuf.m_Get >= 0 && fBuf.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)fBuf.m_Memory.m_nAllocationCount);
    return v4;
  }
  else
  {
    _Warning(a1: "Unable to read texture file %s\n", &pTemp[4]);
    if ( fBuf.m_Get >= 0 && fBuf.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)fBuf.m_Memory.m_nAllocationCount);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004229B0
// Name: private: class CSheet __near * CGameLayer::LoadSheet(char const __near *,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
CSheet *__thiscall CGameLayer::LoadSheet(CGameLayer *this, const char *pszFname, ITexture *pTexture)
{
  CSheet *v3; // esi
  const void *v4; // eax
  CSheet *v5; // eax
  CUtlBuffer bufLoad; // [esp+4h] [ebp-34h] BYREF

  v3 = nullptr;
  v4 = pTexture->GetResourceData(this: pTexture, a2: 16, a3: &pTexture);
  if ( v4 != nullptr )
  {
    CUtlBuffer::CUtlBuffer(
      this: (CUtlBuffer *)&bufLoad.m_Memory.m_nAllocationCount,
      pBuffer: v4,
      nSize: (int)pTexture,
      nFlags: 8);
    v5 = (CSheet *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v5 != nullptr )
      v3 = CSheet::CSheet(this: v5, buf: (CUtlBuffer *)&bufLoad.m_Memory.m_nAllocationCount);
    else
      v3 = nullptr;
    if ( bufLoad.m_Get >= 0 && bufLoad.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)bufLoad.m_Memory.m_nAllocationCount);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00422AB0
// Name: public: CGameLayer::CGameLayer(enum SublayerTypes_t)
// Source: json
//------------------------------------------------------------------------------
CGameLayer *__thiscall CGameLayer::CGameLayer(CGameLayer *this, SublayerTypes_t layerType)
{
  CUtlString *p_m_pName; // ebp
  const ResourceBinding_t<CTextureBits> *m_pBinding; // eax
  CSheet *m_pObject; // ecx

  p_m_pName = &this->m_pName;
  this->m_LayerGraphics.m_Memory.m_pMemory = nullptr;
  this->m_LayerGraphics.m_Memory.m_nAllocationCount = 0;
  this->m_LayerGraphics.m_Memory.m_nGrowSize = 0;
  this->m_LayerGraphics.m_Size = 0;
  this->m_LayerGraphics.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_pName);
  CUtlString::CUtlString(this: &this->m_pTextureName);
  this->m_hTexture.m_pBinding = nullptr;
  CMaterialReference::CMaterialReference(
    this: &this->m_Material,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_Sheet.m_pPrev = nullptr;
  this->m_Sheet.m_pNext = nullptr;
  this->m_Sheet.m_pObject = nullptr;
  this->m_SheetSymbol.m_Id = -1;
  CUtlString::operator=(this: p_m_pName, src: defaultValue);
  this->m_LayerType = layerType;
  CUtlString::operator=(this: &this->m_pTextureName, src: defaultValue);
  m_pBinding = this->m_hTexture.m_pBinding;
  if ( m_pBinding != nullptr )
  {
    _InterlockedExchangeAdd(&m_pBinding->m_nRefCount.m_value, 0xFFFFFFFF);
    this->m_hTexture.m_pBinding = nullptr;
  }
  this->m_hTexture.m_pBinding = nullptr;
  CMaterialReference::CMaterialReference(
    this: (CMaterialReference *)&layerType,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::operator=(this: &this->m_Material, ref: (const CMaterialReference *)&layerType);
  CMaterialReference::~CMaterialReference(this: (CMaterialReference *)&layerType);
  m_pObject = this->m_Sheet.m_pObject;
  if ( m_pObject != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CSheet>>::RemoveNode(this: &m_pObject->m_References, which: &this->m_Sheet);
    this->m_Sheet.m_pObject = nullptr;
  }
  this->m_SheetSymbol.m_Id = -1;
  this->m_bSheetSymbolCached = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00422B80
// Name: public: CGameLayer::~CGameLayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameLayer::~CGameLayer(CGameLayer *this)
{
  CMaterialReference *p_m_Material; // ebp
  CSheet *m_pObject; // ecx
  const ResourceBinding_t<CTextureBits> *m_pBinding; // eax
  bool v5; // sf

  p_m_Material = &this->m_Material;
  if ( this->m_Material.m_pMaterial != nullptr )
    CMaterialReference::Shutdown(this: &this->m_Material, bDeleteIfUnreferenced: true);
  m_pObject = this->m_Sheet.m_pObject;
  if ( m_pObject != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CSheet>>::RemoveNode(this: &m_pObject->m_References, which: &this->m_Sheet);
    this->m_Sheet.m_pObject = nullptr;
  }
  CMaterialReference::~CMaterialReference(this: p_m_Material);
  m_pBinding = this->m_hTexture.m_pBinding;
  if ( m_pBinding != nullptr )
  {
    _InterlockedExchangeAdd(&m_pBinding->m_nRefCount.m_value, 0xFFFFFFFF);
    this->m_hTexture.m_pBinding = nullptr;
  }
  v5 = this->m_pTextureName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_pTextureName.m_Storage.m_nActualLength = 0;
  if ( !v5 )
  {
    if ( this->m_pTextureName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pTextureName.m_Storage.m_Memory.m_pMemory);
      this->m_pTextureName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pTextureName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_pName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_pName.m_Storage.m_nActualLength = 0;
  if ( !v5 )
  {
    if ( this->m_pName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pName.m_Storage.m_Memory.m_pMemory);
      this->m_pName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00422C20
// Name: public: bool CGameLayer::InitSheetTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameLayer::InitSheetTexture(CGameLayer *this, const char *pBaseTextureName)
{
  SublayerTypes_t m_LayerType; // eax
  __int32 v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // ebp
  CSheet *Sheet; // eax
  CSheet *v8; // ecx
  CUtlReference<CSheet> *v9; // esi
  CSheet *v10; // edi
  const ResourceBinding_t<CTextureBits> *v12; // eax
  const ResourceBinding_t<CTextureBits> *m_pBinding; // ecx
  CSheet *m_pObject; // ecx
  CSheet *v15; // edi
  CUtlReference<CSheet> *p_m_Sheet; // esi
  CSheet *ppSheet; // [esp+Ch] [ebp-120h] BYREF
  CUtlString v18; // [esp+10h] [ebp-11Ch] BYREF
  CFmtStrN<256> v19; // [esp+20h] [ebp-10Ch] BYREF

  CUtlString::operator=(this: &this->m_pTextureName, src: pBaseTextureName);
  if ( g_pRenderDevice != nullptr )
  {
    CUtlString::CUtlString(this: &v18);
    if ( this->m_LayerType == SUBLAYER_STATIC )
    {
      v12 = CreateTextureFromVTFFile(pFileName: pBaseTextureName, &ppSheet);
      m_pBinding = this->m_hTexture.m_pBinding;
      if ( m_pBinding != nullptr )
      {
        _InterlockedExchangeAdd(&m_pBinding->m_nRefCount.m_value, 0xFFFFFFFF);
        this->m_hTexture.m_pBinding = nullptr;
      }
      this->m_hTexture.m_pBinding = v12;
      if ( v12 != nullptr )
        _InterlockedExchangeAdd(&v12->m_nRefCount.m_value, 1u);
      m_pObject = this->m_Sheet.m_pObject;
      v15 = ppSheet;
      p_m_Sheet = &this->m_Sheet;
      if ( m_pObject != ppSheet )
      {
        if ( m_pObject != nullptr )
        {
          CUtlIntrusiveDList<CUtlReference<CSheet>>::RemoveNode(this: &m_pObject->m_References, which: p_m_Sheet);
          p_m_Sheet->m_pObject = nullptr;
        }
        p_m_Sheet->m_pObject = v15;
        if ( v15 != nullptr )
        {
          p_m_Sheet->m_pNext = v15->m_References.m_pHead;
          if ( v15->m_References.m_pHead != nullptr )
            v15->m_References.m_pHead->m_pPrev = p_m_Sheet;
          p_m_Sheet->m_pPrev = nullptr;
          v15->m_References.m_pHead = p_m_Sheet;
        }
      }
    }
    v18.m_Storage.m_nActualLength = 0;
    if ( v18.m_Storage.m_Memory.m_nGrowSize >= 0 && v18.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18.m_Storage.m_Memory.m_pMemory);
    return 1;
  }
  m_LayerType = this->m_LayerType;
  v19.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v19.m_bQuietTruncation = true;
  v19.m_szBuf[0] = 0;
  v19.m_nLength = 0;
  if ( m_LayerType != SUBLAYER_STATIC )
  {
    v4 = m_LayerType - 1;
    if ( v4 != 0 )
    {
      if ( v4 == 1 )
        CFmtStrN<256>::sprintf(this: &v19, pszFormat: "fonttx_%s", pBaseTextureName);
    }
    else
    {
      CFmtStrN<256>::sprintf(this: &v19, pszFormat: "dynamictx_%s", pBaseTextureName);
    }
  }
  else
  {
    CFmtStrN<256>::sprintf(this: &v19, pszFormat: "statictx_%s", pBaseTextureName);
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "GameControls");
  else
    v6 = nullptr;
  KeyValues::SetString(this: v6, keyName: "$basetexture", value: pBaseTextureName);
  CMaterialReference::Init(
    this: &this->m_Material,
    pMaterialName: v19.m_szBuf,
    pTextureGroupName: "Other textures",
    pVMTKeyValues: v6);
  this->m_Material.m_pMaterial->Refresh(this: this->m_Material.m_pMaterial);
  Sheet = CTGARenderer::LoadSheet(this, pMaterial: this->m_Material.m_pMaterial);
  v8 = this->m_Sheet.m_pObject;
  v9 = &this->m_Sheet;
  v10 = Sheet;
  if ( v8 == Sheet )
    return 1;
  if ( v8 != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CSheet>>::RemoveNode(this: &v8->m_References, which: v9);
    v9->m_pObject = nullptr;
  }
  v9->m_pObject = v10;
  if ( v10 == nullptr )
    return 1;
  v9->m_pNext = v10->m_References.m_pHead;
  if ( v10->m_References.m_pHead != nullptr )
    v10->m_References.m_pHead->m_pPrev = v9;
  v9->m_pPrev = nullptr;
  v10->m_References.m_pHead = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00422DF0
// Name: public: int CGameLayer::AddGraphic(class CGameGraphic __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameLayer::AddGraphic(CGameLayer *this, CGameGraphic *pGraphic)
{
  return CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
           (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this,
           elem: this->m_LayerGraphics.m_Size,
           src: (vgui::TreeNode **)&pGraphic);
}

//------------------------------------------------------------------------------
// Address: 0x00422E10
// Name: public: bool CGameLayer::Unserialize(class CDmxElement __near *,class CUtlDict<class CGameGraphic __near *,int> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameLayer::Unserialize(
        CGameLayer *this,
        CDmxElement *pLayer,
        CUtlDict<CGameGraphic *,int> *unserializedGraphicMapping)
{
  CDmxElement *v3; // edi
  CGameLayer *v4; // esi
  SublayerTypes_t m_LayerType; // eax
  int v6; // ebp
  CDmxAttribute *v7; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v8; // ebx
  int v9; // edi
  const CDmxAttribute *v10; // eax
  const char *v11; // esi
  CGameRect *v12; // eax
  CDynamicRect *v13; // esi
  const UniqueId_t *v14; // eax
  CHitArea *v15; // eax
  const UniqueId_t *v16; // eax
  CDmxAttribute *v17; // eax
  CDmxAttribute *Attribute; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v20; // ebx
  const CDmxAttribute *v21; // eax
  const char *v22; // eax
  CDynamicRect *v23; // eax
  const UniqueId_t *Id; // eax
  CDmxAttribute *v25; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v26; // ebx
  vgui::TreeNode *v27; // esi
  const CDmxAttribute *v28; // eax
  const char *v29; // eax
  CGameText *v30; // eax
  const UniqueId_t *v31; // eax
  int v32; // [esp-8h] [ebp-1B8h]
  int v33; // [esp-8h] [ebp-1B8h]
  int m_Size; // [esp-8h] [ebp-1B8h]
  int v35; // [esp-8h] [ebp-1B8h]
  vgui::TreeNode *v36; // [esp+10h] [ebp-1A0h] BYREF
  vgui::TreeNode *src; // [esp+14h] [ebp-19Ch] BYREF
  CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *v38; // [esp+18h] [ebp-198h]
  CUtlMap<char const *,CGameGraphic *,int>::Node_t v39; // [esp+1Ch] [ebp-194h] BYREF
  int v40; // [esp+24h] [ebp-18Ch]
  CUtlMap<char const *,CGameGraphic *,int>::Node_t insert; // [esp+28h] [ebp-188h] BYREF
  char pBuf[252]; // [esp+30h] [ebp-180h] BYREF
  char textureName[132]; // [esp+12Ch] [ebp-84h] BYREF

  v3 = pLayer;
  v4 = this;
  v38 = (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this;
  CDmxElement::UnpackIntoStructure(this: pLayer, pData: this, pUnpack: s_GameLayerUnpack);
  m_LayerType = v4->m_LayerType;
  v6 = 0;
  if ( m_LayerType != SUBLAYER_STATIC )
  {
    if ( m_LayerType == SUBLAYER_DYNAMIC )
    {
      Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this: pLayer, pAttributeName: "dynamicGraphics");
      v20 = CDmxAttribute::GetArray<CDmxElement *>(this: Attribute);
      if ( v20->m_Size > 0 )
      {
        do
        {
          v21 = CDmxElement::GetAttribute(this: v20->m_Memory.m_pMemory[v6], pAttributeName: "classtype");
          if ( v21 != nullptr && v21->m_Type == AT_STRING )
            v22 = CUtlString::operator char const *(this: (CUtlString *)v21->m_pData);
          else
            v22 = defaultValue;
          if ( _V_stricmp(s1: v22, s2: "CDmeDynamicRectGeometry") != 0 )
          {
            _Warning(a1: "CGameUIDefinition: Warning unknown static graphic type\n");
          }
          else
          {
            v23 = (CDynamicRect *)MemAlloc_Alloc(nSize: 0x190u);
            if ( v23 != nullptr )
              v13 = CDynamicRect::CDynamicRect(this: v23, pName: defaultValue);
            else
              v13 = nullptr;
            if ( !CDynamicRect::Unserialize(this: v13, pGraphic: v20->m_Memory.m_pMemory[v6]) )
              goto LABEL_26;
            m_Size = v38->m_Size;
            v36 = (vgui::TreeNode *)v13;
            CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
              this: v38,
              elem: m_Size,
              src: &v36);
            Id = CDmxElement::GetId(this: v20->m_Memory.m_pMemory[v6]);
            UniqueIdToString(id: Id, pBuf, nMaxLen: 255);
            v39.key = MemAlloc_StrDup(pString: pBuf);
            v39.elem = v13;
            CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::Insert(
              this: &unserializedGraphicMapping->m_Elements.m_Tree,
              insert: &v39);
          }
          ++v6;
        }
        while ( v6 < v20->m_Size );
        return 1;
      }
    }
    else if ( m_LayerType == SUBLAYER_FONT )
    {
      v25 = (CDmxAttribute *)CDmxElement::GetAttribute(this: pLayer, pAttributeName: "fontGraphics");
      v26 = CDmxAttribute::GetArray<CDmxElement *>(this: v25);
      src = (vgui::TreeNode *)v26->m_Size;
      v27 = src;
      if ( (int)src > 0 )
      {
        do
        {
          v28 = CDmxElement::GetAttribute(this: v26->m_Memory.m_pMemory[v6], pAttributeName: "classtype");
          if ( v28 != nullptr && v28->m_Type == AT_STRING )
            v29 = CUtlString::operator char const *(this: (CUtlString *)v28->m_pData);
          else
            v29 = defaultValue;
          if ( _V_stricmp(s1: v29, s2: "CDmeTextGeometry") != 0 )
          {
            _Warning(a1: "CGameUIDefinition: Warning unknown font graphic type in gui file.\n");
          }
          else
          {
            v30 = (CGameText *)MemAlloc_Alloc(nSize: 0x1A4u);
            if ( v30 != nullptr )
              v13 = (CDynamicRect *)CGameText::CGameText(this: v30, pName: defaultValue);
            else
              v13 = nullptr;
            if ( CGameText::Unserialize(this: (CGameText *)v13, pGraphic: v26->m_Memory.m_pMemory[v6]) == 0 )
            {
LABEL_26:
              if ( v13 != nullptr )
                ((void (__thiscall *)(CDynamicRect *, int))v13->dtr_CGameGraphic)(a1: v13, a2: 1);
              return 0;
            }
            v35 = v38->m_Size;
            v36 = (vgui::TreeNode *)v13;
            CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
              this: v38,
              elem: v35,
              src: &v36);
            v31 = CDmxElement::GetId(this: v26->m_Memory.m_pMemory[v6]);
            UniqueIdToString(id: v31, pBuf, nMaxLen: 255);
            CDmxElement::GetId(this: v26->m_Memory.m_pMemory[v6]);
            v39.key = MemAlloc_StrDup(pString: pBuf);
            v39.elem = v13;
            CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::Insert(
              this: &unserializedGraphicMapping->m_Elements.m_Tree,
              insert: &v39);
            v27 = src;
          }
          ++v6;
        }
        while ( v6 < (int)v27 );
      }
    }
    return 1;
  }
  v7 = (CDmxAttribute *)CDmxElement::GetAttribute(this: pLayer, pAttributeName: "staticGraphics");
  v8 = CDmxAttribute::GetArray<CDmxElement *>(this: v7);
  v36 = (vgui::TreeNode *)v8->m_Size;
  v40 = 0;
  if ( (int)v36 > 0 )
  {
    do
    {
      v9 = v40;
      v10 = CDmxElement::GetAttribute(this: v8->m_Memory.m_pMemory[v40], pAttributeName: "classtype");
      if ( v10 != nullptr )
      {
        if ( v10->m_Type == AT_STRING )
          v11 = CUtlString::operator char const *(this: (CUtlString *)v10->m_pData);
        else
          v11 = defaultValue;
      }
      else
      {
        v11 = defaultValue;
      }
      if ( _V_stricmp(s1: v11, s2: "CDmeRectGeometry") != 0 )
      {
        if ( _V_stricmp(s1: v11, s2: "CDmeHitAreaGeometry") != 0 )
        {
          _Warning(a1: "CGameUIDefinition: Warning unknown static graphic type\n");
        }
        else
        {
          v15 = (CHitArea *)MemAlloc_Alloc(nSize: 0x1A4u);
          if ( v15 != nullptr )
            v13 = (CDynamicRect *)CHitArea::CHitArea(this: v15, pName: defaultValue);
          else
            v13 = nullptr;
          if ( CHitArea::Unserialize(this: (CHitArea *)v13, pGraphic: v8->m_Memory.m_pMemory[v9]) == 0 )
            goto LABEL_26;
          v33 = v38->m_Size;
          src = (vgui::TreeNode *)v13;
          CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(this: v38, elem: v33, &src);
          v16 = CDmxElement::GetId(this: v8->m_Memory.m_pMemory[v9]);
          UniqueIdToString(id: v16, pBuf, nMaxLen: 255);
          v39.key = MemAlloc_StrDup(pString: pBuf);
          v39.elem = v13;
          CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::Insert(
            this: &unserializedGraphicMapping->m_Elements.m_Tree,
            insert: &v39);
        }
      }
      else
      {
        v12 = (CGameRect *)MemAlloc_Alloc(nSize: 0x180u);
        if ( v12 != nullptr )
          v13 = (CDynamicRect *)CGameRect::CGameRect(this: v12, pName: defaultValue);
        else
          v13 = nullptr;
        if ( !CGameRect::Unserialize(this: v13, pGraphic: v8->m_Memory.m_pMemory[v9]) )
          goto LABEL_26;
        v32 = v38->m_Size;
        src = (vgui::TreeNode *)v13;
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(this: v38, elem: v32, &src);
        v14 = CDmxElement::GetId(this: v8->m_Memory.m_pMemory[v9]);
        UniqueIdToString(id: v14, pBuf, nMaxLen: 255);
        insert.key = MemAlloc_StrDup(pString: pBuf);
        insert.elem = v13;
        CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::Insert(
          this: &unserializedGraphicMapping->m_Elements.m_Tree,
          &insert);
      }
      ++v40;
    }
    while ( v40 < (int)v36 );
    v4 = (CGameLayer *)v38;
    v3 = pLayer;
  }
  v17 = (CDmxAttribute *)CDmxElement::GetAttribute(this: v3, pAttributeName: "statictexture");
  if ( v17 == nullptr || v17->m_Type != AT_STRING )
    return 0;
  CDmxAttribute::GetValueAsString(this: v17, pBuffer: &textureName[4], nBufLen: 0x80u);
  CGameLayer::InitSheetTexture(this: v4, pBaseTextureName: &textureName[4]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00423370
// Name: public: void CGameLayer::UpdateRenderData(class CGameUIDefinition __near &,struct color32_s,class CUtlVector<struct LayerRenderLists_t,class CUtlMemory<struct LayerRenderLists_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameLayer::UpdateRenderData(
        CGameLayer *this@<ecx>,
        CGameUIDefinition *a2@<ebx>,
        char *a3@<ebp>,
        int a4@<edi>,
        CGameUIDefinition *gameUIDef,
        color32_s parentColor,
        IMaterial *renderLists)
{
  int m_Size; // ecx
  SublayerTypes_t m_LayerType; // eax
  int v10; // ebp
  unsigned int v11; // edi
  const char *v12; // eax
  IMaterial *ImageAliasMaterial; // eax
  CGameUIDefinition *v14; // eax
  int v16; // edi
  LayerRenderLists_t *v17; // ebx
  int j; // edi
  int v20; // edi
  LayerRenderLists_t *v21; // ebx
  int i; // edi
  int listIndex; // [esp+Ch] [ebp-Ch]
  IMaterial *pAliasMaterial; // [esp+24h] [ebp+Ch]
  IMaterial *pAliasMateriala; // [esp+24h] [ebp+Ch]
  IMaterial *v29; // [esp+30h] [ebp+18h]

  m_Size = this->m_LayerGraphics.m_Size;
  listIndex = m_Size;
  if ( m_Size != 0 )
  {
    m_LayerType = this->m_LayerType;
    if ( m_LayerType == SUBLAYER_DYNAMIC )
    {
      v10 = 0;
      if ( m_Size > 0 )
      {
        v11 = -36;
        do
        {
          v12 = (const char *)((int (__thiscall *)(CGameGraphic *, int, char *, CGameUIDefinition *))this->m_LayerGraphics.m_Memory.m_pMemory[v10]->GetMaterialAlias)(
                                a1: this->m_LayerGraphics.m_Memory.m_pMemory[v10],
                                a2: a4,
                                a3,
                                a4: a2);
          ImageAliasMaterial = CGameUISystemMgr::GetImageAliasMaterial(this: g_pGameUISystemMgrImpl, pAlias: v12);
          v29 = ImageAliasMaterial;
          if ( v10 == 0 || *(IMaterial **)((char *)&renderLists->GetNumAnimationFrames + v11) != ImageAliasMaterial )
          {
            v11 = 36
                * CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int>>::InsertBefore(
                    this: (CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > *)renderLists,
                    elem: (int)renderLists[3].__vftable);
            v14 = (CGameUIDefinition *)CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,int>>::InsertBefore(
                                         this: (CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *)((char *)renderLists->__vftable + v11),
                                         elem: *(int *)((char *)&renderLists->GetPreviewImage + v11));
            *(int (__thiscall **)(IMaterial *))((char *)&renderLists->GetMappingHeight + v11) = (int (__thiscall *)(IMaterial *))this->m_LayerType;
            gameUIDef = v14;
            *(int (__thiscall **)(IMaterial *))((char *)&renderLists->GetNumAnimationFrames + v11) = (int (__thiscall *)(IMaterial *))v29;
            *(bool (__thiscall **)(IMaterial *))((char *)&renderLists->InMaterialPage + v11) = nullptr;
            *(void (__thiscall **)(IMaterial *, float *))((char *)&renderLists->GetMaterialOffset + v11) = (void (__thiscall *)(IMaterial *, float *))this->m_hTexture.m_pBinding;
          }
          a2 = gameUIDef;
          a3 = (char *)renderLists->__vftable + v11;
          a4 = *(_DWORD *)(*(_DWORD *)&parentColor + 384);
          ((void (__thiscall *)(CGameGraphic *))this->m_LayerGraphics.m_Memory.m_pMemory[v10]->UpdateRenderData)(a1: this->m_LayerGraphics.m_Memory.m_pMemory[v10]);
          ++v10;
        }
        while ( v10 < listIndex );
      }
    }
    else if ( m_LayerType != SUBLAYER_STATIC )
    {
      if ( m_LayerType == SUBLAYER_FONT )
      {
        v20 = 36
            * CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int>>::InsertBefore(
                this: (CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > *)renderLists,
                elem: (int)renderLists[3].__vftable);
        pAliasMateriala = (IMaterial *)CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,int>>::InsertBefore(
                                         this: (CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *)((char *)renderLists->__vftable + v20),
                                         elem: *(int *)((char *)&renderLists->GetPreviewImage + v20));
        *(int (__thiscall **)(IMaterial *))((char *)&renderLists->GetMappingHeight + v20) = (int (__thiscall *)(IMaterial *))this->m_LayerType;
        *(int (__thiscall **)(IMaterial *))((char *)&renderLists->GetNumAnimationFrames + v20) = (int (__thiscall *)(IMaterial *))this->m_Material.m_pMaterial;
        *(bool (__thiscall **)(IMaterial *))((char *)&renderLists->InMaterialPage + v20) = (bool (__thiscall *)(IMaterial *))this->m_Sheet.m_pObject;
        *(void (__thiscall **)(IMaterial *, float *))((char *)&renderLists->GetMaterialOffset + v20) = (void (__thiscall *)(IMaterial *, float *))this->m_hTexture.m_pBinding;
        v21 = (LayerRenderLists_t *)((char *)renderLists->__vftable + v20);
        for ( i = 0; i < listIndex; ++i )
          ((void (__thiscall *)(CGameGraphic *, _DWORD, LayerRenderLists_t *, IMaterial *))this->m_LayerGraphics.m_Memory.m_pMemory[i]->UpdateRenderData)(
            a1: this->m_LayerGraphics.m_Memory.m_pMemory[i],
            a2: *(_DWORD *)&this->m_LayerGraphics.m_Memory.m_pMemory[i]->m_pGroup->m_ResultantColor,
            a3: v21,
            a4: pAliasMateriala);
      }
    }
    else
    {
      v16 = 36
          * CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int>>::InsertBefore(
              this: (CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > *)renderLists,
              elem: (int)renderLists[3].__vftable);
      pAliasMaterial = (IMaterial *)CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,int>>::InsertBefore(
                                      this: (CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *)((char *)renderLists->__vftable + v16),
                                      elem: *(int *)((char *)&renderLists->GetPreviewImage + v16));
      *(int (__thiscall **)(IMaterial *))((char *)&renderLists->GetMappingHeight + v16) = (int (__thiscall *)(IMaterial *))this->m_LayerType;
      *(int (__thiscall **)(IMaterial *))((char *)&renderLists->GetNumAnimationFrames + v16) = (int (__thiscall *)(IMaterial *))this->m_Material.m_pMaterial;
      *(bool (__thiscall **)(IMaterial *))((char *)&renderLists->InMaterialPage + v16) = (bool (__thiscall *)(IMaterial *))this->m_Sheet.m_pObject;
      *(void (__thiscall **)(IMaterial *, float *))((char *)&renderLists->GetMaterialOffset + v16) = (void (__thiscall *)(IMaterial *, float *))this->m_hTexture.m_pBinding;
      v17 = (LayerRenderLists_t *)((char *)renderLists->__vftable + v16);
      for ( j = 0; j < listIndex; ++j )
        ((void (__thiscall *)(CGameGraphic *, _DWORD, LayerRenderLists_t *, IMaterial *))this->m_LayerGraphics.m_Memory.m_pMemory[j]->UpdateRenderData)(
          a1: this->m_LayerGraphics.m_Memory.m_pMemory[j],
          a2: *(_DWORD *)&this->m_LayerGraphics.m_Memory.m_pMemory[j]->m_pGroup->m_ResultantColor,
          a3: v17,
          a4: pAliasMaterial);
    }
  }
}
