// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/scaleformuihighlevelimpl.cpp
// Functions: 17
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\scaleformuihighlevelimpl.h"

//------------------------------------------------------------------------------
// Address: 0x1000DA60
// Name: void __near * MemAlloc_Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_Alloc(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1000DA80
// Name: public: char const __near * ScaleformUIImpl::CorrectFlashFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall ScaleformUIImpl::CorrectFlashFileName(ScaleformUIImpl *this, char *name)
{
  int v4; // eax
  char *v5; // eax
  const char *v7; // eax
  char *m_cTemporaryBuffer; // ebx
  const char *pFirstEXTChar; // [esp+8h] [ebp-4h]
  int len; // [esp+14h] [ebp+8h]

  v4 = _V_strlen(str: name);
  len = v4;
  if ( (unsigned int)(v4 - 4) > 0xFF1 )
    return name;
  v5 = _V_strstr(s1: ".swf.gfx", search: &name[v4 - 4]);
  if ( v5 == nullptr )
    return name;
  v7 = v5 + 1;
  pFirstEXTChar = v7;
  if ( this->m_bTrySWFFirst )
  {
    if ( *v7 == 115 )
    {
      m_cTemporaryBuffer = name;
    }
    else
    {
      m_cTemporaryBuffer = this->m_cTemporaryBuffer;
      V_strncpy(pDest: this->m_cTemporaryBuffer, pSrc: name, maxLen: 4086);
      _V_strcpy(dest: (char *)&this->m_iLastMouseY + len + 1, src: "swf");
    }
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: m_cTemporaryBuffer, a3: "GAME") )
      return m_cTemporaryBuffer;
    v7 = pFirstEXTChar;
  }
  if ( *v7 == 103 )
    return name;
  m_cTemporaryBuffer = this->m_cTemporaryBuffer;
  V_strncpy(pDest: this->m_cTemporaryBuffer, pSrc: name, maxLen: 4086);
  _V_strcpy(dest: (char *)&this->m_iLastMouseY + len + 1, src: "gfx");
  return m_cTemporaryBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x1000DB70
// Name: public: virtual void ScaleformUIImpl::SendUIEvent(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::SendUIEvent(
        ScaleformUIImpl *this,
        const char *action,
        const char *eventData,
        int slot)
{
  IGameEvent *v5; // esi

  v5 = this->m_pGameEventManager->CreateEventA(
         this: this->m_pGameEventManager,
         a2: &stru_10290234.m_pElements,
         a3: 0,
         a4: 0);
  if ( v5 != nullptr )
  {
    v5->SetString(this: v5, a2: (const char *)&stru_10290234.m_Memory.m_nGrowSize, a3: action);
    v5->SetString(this: v5, a2: (const char *)&stru_10290234, a3: eventData);
    v5->SetInt(this: v5, a2: "slot", a3: slot);
    this->m_pGameEventManager->FireEventClientSide(this: this->m_pGameEventManager, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DBE0
// Name: public: virtual float ScaleformUIImpl::GetJoyValue(int,int,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ScaleformUIImpl::GetJoyValue(ScaleformUIImpl *this, int slot, int stickIndex, int axis)
{
  return this->m_fJoyValues[4 * slot + 2 * stickIndex + axis];
}

//------------------------------------------------------------------------------
// Address: 0x1000DC00
// Name: public: void ScaleformUIImpl::SetScreenSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::SetScreenSize(ScaleformUIImpl *this, int x, int y)
{
  this->SetSlotViewport(this, a2: 1, a3: 0, a4: 0, a5: x, a6: y);
}

//------------------------------------------------------------------------------
// Address: 0x1000DC20
// Name: protected: bool ScaleformUIImpl::DistributeEvent(class GFxEvent __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::DistributeEvent(
        ScaleformUIImpl *this,
        GFxEvent *event,
        int slotNumber,
        bool toAllSlots)
{
  BaseSlot *v5; // eax
  int v6; // edi
  BaseSlot *v7; // eax
  BaseSlot *v8; // esi
  bool result; // al
  int slots[2]; // [esp+Ch] [ebp-Ch]
  bool v11; // [esp+17h] [ebp-1h]
  int i; // [esp+24h] [ebp+Ch]

  v11 = false;
  v5 = ScaleformUIImpl::LockSlotPtr(this, slot: 0);
  if ( v5 != nullptr )
    v5->m_pMovieView->HandleEvent(this: v5->m_pMovieView, a2: event);
  ScaleformUIImpl::UnlockSlotPtr(this, slotID: 0);
  slots[0] = 1;
  slots[1] = slotNumber + 2;
  i = 0;
  while ( 1 )
  {
    v6 = slots[i];
    v7 = ScaleformUIImpl::LockSlotPtr(this, slot: v6);
    v8 = v7;
    if ( v7 != nullptr
      && v7->ConsumesInputEvents(this: v7)
      && (v8->m_pMovieView->HandleEvent(this: v8->m_pMovieView, a2: event) & 2) != 0 )
    {
      v11 = true;
    }
    ScaleformUIImpl::UnlockSlotPtr(this, slotID: v6);
    result = v11;
    if ( v11 && !toAllSlots )
      break;
    if ( ++i >= 2 )
      return v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000DCE0
// Name: protected: bool ScaleformUIImpl::DistributeKeyEvent(bool,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ScaleformUIImpl::DistributeKeyEvent(
        ScaleformUIImpl *this,
        bool keyDown,
        int code,
        int slotNumber,
        bool toAllSlots)
{
  char v5; // bl
  int v6; // edi
  BaseSlot *v7; // eax
  BaseSlot *v8; // esi
  int slots[2]; // [esp+Ch] [ebp-10h]
  ScaleformUIImpl *v11; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v5 = 0;
  v11 = this;
  slots[0] = 1;
  slots[1] = slotNumber + 2;
  for ( i = 0; i < 2; ++i )
  {
    v6 = slots[i];
    v7 = ScaleformUIImpl::LockSlotPtr(this: v11, slot: v6);
    v8 = v7;
    if ( v7 != nullptr && v7->ConsumesInputEvents(this: v7) )
    {
      BaseSlot::HandleKeyEvent(this: v8, keyDown, code, slot: slotNumber);
      v5 = 1;
    }
    ScaleformUIImpl::UnlockSlotPtr(this: v11, slotID: v6);
    if ( v5 != 0 && !toAllSlots )
      break;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD70
// Name: protected: bool ScaleformUIImpl::HitTest(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::HitTest(ScaleformUIImpl *this, int x, int y)
{
  bool result; // al
  int i; // edi
  BaseSlot *v6; // esi
  bool v7; // [esp+1Fh] [ebp-1h]

  result = false;
  v7 = false;
  for ( i = 1; i < 4; ++i )
  {
    if ( result )
      break;
    v6 = ScaleformUIImpl::LockSlotPtr(this, slot: i);
    if ( v6 != nullptr
      && v6->ConsumesInputEvents(this: v6)
      && v6->m_pMovieView->HitTest(this: v6->m_pMovieView, a2: (float)x, a3: (float)y, a4: HitTest_Shapes, a5: 0) )
    {
      v7 = true;
    }
    ScaleformUIImpl::UnlockSlotPtr(this, slotID: i);
    result = v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000DE00
// Name: public: virtual bool ScaleformUIImpl::HandleInputEvent(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::HandleInputEvent(ScaleformUIImpl *this, const InputEvent_t *event)
{
  bool v3; // zf
  int m_nData; // eax
  bool v6; // bl
  bool result; // al
  int m_nType; // eax
  int v9; // eax
  int m_nData3; // edi
  ButtonCode_t v11; // eax
  ScaleformUIImpl_vtbl *v12; // edi
  unsigned int v13; // eax
  int v14; // eax
  ButtonCode_t v15; // eax
  ScaleformUIImpl_vtbl *v16; // edi
  unsigned int v17; // eax
  int v18; // eax
  GFxMouseEvent mevent; // [esp+Ch] [ebp-24h] BYREF
  ButtonCode_t code; // [esp+24h] [ebp-Ch] BYREF
  int slot; // [esp+28h] [ebp-8h] BYREF
  bool v22; // [esp+2Fh] [ebp-1h]
  bool consumesEvents_3; // [esp+3Bh] [ebp+Bh]

  v3 = event->m_nType == 3;
  v22 = false;
  v6 = false;
  if ( v3 )
  {
    m_nData = event->m_nData;
    if ( m_nData >= 4 && m_nData <= 27 )
      v6 = true;
  }
  consumesEvents_3 = this->ConsumesInputEvents(this);
  if ( !consumesEvents_3 && !v6 )
    return false;
  m_nType = event->m_nType;
  v3 = event->m_nType == 0;
  slot = 0;
  if ( v3 )
  {
    this->m_CurrentKey = event->m_nData2;
    ScaleformUIImpl::DecodeButtonandSlotFromButtonCode(
      this,
      inCode: (ButtonCode_t)event->m_nData2,
      outCode: &code,
      outSlot: &slot);
    v15 = code;
    if ( (unsigned int)code <= KEY_SCROLLLOCKTOGGLE || (unsigned int)(code - 114) <= 0xBF )
    {
      if ( (unsigned int)(code - 258) > 0x2F
        || (v3 = !ScaleformUIImpl::AnalogStickNavigationDisabled(this, slot: slot + 2), v15 = code, v3) )
      {
        v16 = this->__vftable;
        v17 = ScaleformUIImpl::ValveButtonCodeToVirtualKey(this, code: v15);
        v18 = v16->TranslateKeyCode(this, a2: v17);
        v22 = ScaleformUIImpl::DistributeKeyEvent(this, keyDown: true, code: v18, slotNumber: slot, toAllSlots: false);
        v15 = code;
      }
      else
      {
        v22 = false;
      }
    }
    if ( (unsigned int)(v15 - 107) <= 6
      && ScaleformUIImpl::HitTest(this, x: this->m_iLastMouseX, y: this->m_iLastMouseY) )
    {
      mevent.x = (float)this->m_iLastMouseX;
      mevent.y = (float)this->m_iLastMouseY;
      mevent.Type = MouseDown;
      memset(&mevent.ScrollDelta, 0, 12);
      v22 = ScaleformUIImpl::DistributeEvent(this, event: &mevent, slotNumber: 0, toAllSlots: false);
    }
  }
  else
  {
    v9 = m_nType - 1;
    if ( v9 != 0 )
    {
      if ( v9 == 2 )
      {
        switch ( event->m_nData )
        {
          case 0:
            this->m_iLastMouseX = event->m_nData2;
            break;
          case 1:
            this->m_iLastMouseY = event->m_nData2;
            break;
          case 2:
            this->m_iLastMouseX = event->m_nData2;
            m_nData3 = event->m_nData3;
            mevent.x = (float)this->m_iLastMouseX;
            mevent.Type = MouseMove;
            mevent.y = (float)m_nData3;
            this->m_iLastMouseY = m_nData3;
            memset(&mevent.ScrollDelta, 0, 12);
            ScaleformUIImpl::DistributeEvent(this, event: &mevent, slotNumber: 0, toAllSlots: false);
            break;
          case 4:
            this->m_fJoyValues[0] = (float)event->m_nData2 * 0.000030517578;
            break;
          case 5:
            this->m_fJoyValues[1] = (float)event->m_nData2 * 0.000030517578;
            break;
          case 7:
            this->m_fJoyValues[3] = (float)event->m_nData2 * 0.000030517578;
            break;
          case 8:
            this->m_fJoyValues[2] = (float)event->m_nData2 * 0.000030517578;
            break;
          case 0xA:
            this->m_fJoyValues[4] = (float)event->m_nData2 * 0.000030517578;
            slot = 1;
            break;
          case 0xB:
            this->m_fJoyValues[5] = (float)event->m_nData2 * 0.000030517578;
            slot = 1;
            break;
          case 0xD:
            this->m_fJoyValues[7] = (float)event->m_nData2 * 0.000030517578;
            slot = 1;
            break;
          case 0xE:
            this->m_fJoyValues[6] = (float)event->m_nData2 * 0.000030517578;
            slot = 1;
            break;
          default:
            break;
        }
      }
    }
    else
    {
      ScaleformUIImpl::DecodeButtonandSlotFromButtonCode(
        this,
        inCode: (ButtonCode_t)event->m_nData2,
        outCode: &code,
        outSlot: &slot);
      v11 = code;
      if ( (unsigned int)code <= KEY_SCROLLLOCKTOGGLE || (unsigned int)(code - 114) <= 0xBF )
      {
        if ( (unsigned int)(code - 258) > 0x2F
          || (v3 = !ScaleformUIImpl::AnalogStickNavigationDisabled(this, slot: slot + 2), v11 = code, v3) )
        {
          v12 = this->__vftable;
          v13 = ScaleformUIImpl::ValveButtonCodeToVirtualKey(this, code: v11);
          v14 = v12->TranslateKeyCode(this, a2: v13);
          v22 = ScaleformUIImpl::DistributeKeyEvent(
                  this,
                  keyDown: false,
                  code: v14,
                  slotNumber: slot,
                  toAllSlots: false);
          v11 = code;
        }
        else
        {
          v22 = false;
        }
      }
      if ( (unsigned int)(v11 - 107) <= 6 )
      {
        mevent.x = (float)this->m_iLastMouseX;
        mevent.y = (float)this->m_iLastMouseY;
        mevent.Type = MouseUp;
        memset(&mevent.ScrollDelta, 0, 12);
        ScaleformUIImpl::DistributeEvent(this, event: &mevent, slotNumber: 0, toAllSlots: false);
      }
    }
  }
  if ( !consumesEvents_3 )
    return false;
  v3 = !this->SlotDeniesInputToGame(this, a2: slot + 2);
  result = true;
  if ( v3 )
    return v22;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E200
// Name: public: static bool CDefOps<unsigned __int64>::LessFunc(unsigned __int64 const __near &,unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<unsigned __int64>::LessFunc(const unsigned __int64 *lhs, const unsigned __int64 *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x1000E230
// Name: protected: void ScaleformUIImpl::ShutdownHighLevelImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ShutdownHighLevelImpl(ScaleformUIImpl *this)
{
  ScaleformUIAvatarImage *m_pDefaultAvatarImage; // edi

  if ( this->m_pDefaultAvatarTexture != nullptr )
  {
    DestroyVTFTexture(pTexture: this->m_pDefaultAvatarTexture);
    this->m_pDefaultAvatarTexture = nullptr;
  }
  m_pDefaultAvatarImage = this->m_pDefaultAvatarImage;
  if ( m_pDefaultAvatarImage != nullptr )
  {
    ScaleformUIAvatarImage::~ScaleformUIAvatarImage(this: this->m_pDefaultAvatarImage);
    free(pMem: m_pDefaultAvatarImage);
    this->m_pDefaultAvatarImage = nullptr;
  }
  this->m_CurrentKey = BUTTON_CODE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x1000F000
// Name: protected: void ScaleformUIImpl::InitHighLevelImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::InitHighLevelImpl(ScaleformUIImpl *this)
{
  bool (__thiscall *ReadFile)(IBaseFileSystem *, const char *, const char *, CUtlBuffer *, int, int, void *(__cdecl *)(const char *, unsigned int)); // edx
  IVTFTexture *VTFTexture; // eax
  bool v4; // sf
  CUtlBuffer bufFile; // [esp+8h] [ebp-3Ch] BYREF
  int v6; // [esp+40h] [ebp-4h]

  this->m_iLastMouseX = -1;
  this->m_iLastMouseY = -1;
  _V_memset(dest: this->m_fJoyValues, fill: 0, count: 32);
  if ( this->m_mapUserXuidToAvatar.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_mapUserXuidToAvatar.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned __int64 *, const unsigned __int64 *))CDefOps<unsigned __int64>::LessFunc;
  CUtlBuffer::CUtlBuffer(this: &bufFile, growSize: 0, initSize: 0, nFlags: 0);
  ReadFile = g_pFullFileSystem->ReadFile;
  v6 = 0;
  if ( ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: cDefaultAvatarImageFileName,
         a3: nullptr,
         a4: &bufFile,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    VTFTexture = CreateVTFTexture();
    this->m_pDefaultAvatarTexture = VTFTexture;
    if ( !VTFTexture->Unserialize(this: VTFTexture, a2: &bufFile, a3: false, a4: 0) )
    {
      _Warning(a1: "Invalid or corrupt default avatar image (%s)\n", cDefaultAvatarImageFileName);
      DestroyVTFTexture(pTexture: this->m_pDefaultAvatarTexture);
      this->m_pDefaultAvatarTexture = nullptr;
    }
  }
  else
  {
    _Warning(a1: "Failed to read the default avatar image file (%s)\n", cDefaultAvatarImageFileName);
  }
  v4 = bufFile.m_Memory.m_nGrowSize < 0;
  this->m_CurrentKey = BUTTON_CODE_INVALID;
  v6 = -1;
  if ( !v4 && bufFile.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufFile.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1000FC30
// Name: public: void ScaleformUIImpl::UpdateAvatarImages(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ScaleformUIImpl::UpdateAvatarImages(
        ScaleformUIImpl *this@<ecx>,
        void *(__cdecl **a2)(const char *, int *)@<ebx>)
{
  int v3; // edi
  int *v4; // edx
  void *(__cdecl **v5)(const char *, int *); // [esp-4h] [ebp-Ch]
  int v6; // [esp+0h] [ebp-8h]

  v3 = 0;
  if ( LOWORD(this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_nAllocationCount) != 0 )
  {
    v5 = a2;
    do
    {
      if ( (unsigned __int16)v3 < this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_nAllocationCount
        && (unsigned __int16)v3 <= this->m_mapUserXuidToAvatar.m_Tree.m_LastAlloc.index )
      {
        if ( (`CUtlRBTree<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1033AD4C = 0x1FFFF;
        }
        if ( (_WORD)v3 == 0xFFFF )
          v4 = &`CUtlRBTree<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v4 = (int *)&this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v3];
        if ( *(_WORD *)v4 != (_WORD)v3 )
          CDummyMaterialSystem::EndBatch(pFactoryList: v5, nFactoryCount: v6);
      }
      ++v3;
    }
    while ( v3 < LOWORD(this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_nAllocationCount) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FD00
// Name: public: class ScaleformUIAvatarImage __near * ScaleformUIImpl::GetAvatarImage(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
ScaleformUIAvatarImage *__thiscall ScaleformUIImpl::GetAvatarImage(ScaleformUIImpl *this, unsigned __int64 playerID)
{
  unsigned __int16 v3; // ax
  ScaleformUIAvatarImage *result; // eax
  ScaleformRenderer *pObject; // ebx
  IVTFTexture *m_pDefaultAvatarTexture; // esi
  const unsigned __int8 *v7; // eax
  ScaleformUIAvatarImage *v8; // eax
  ScaleformUIAvatarImage *v9; // eax
  ImageFormat v10; // [esp-Ch] [ebp-38h]
  int v11; // [esp-8h] [ebp-34h]
  int v12; // [esp-4h] [ebp-30h]
  CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t search; // [esp+Ch] [ebp-20h] BYREF
  int v14; // [esp+28h] [ebp-4h]
  ScaleformUIAvatarImage *playerID_4; // [esp+38h] [ebp+Ch]

  if ( playerID != 0 )
  {
    search.key = playerID;
    v3 = CUtlRBTree<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_mapUserXuidToAvatar.m_Tree,
           &search);
    if ( v3 == 0xFFFF )
    {
      _Warning(a1: "Error getting avatar image: playerID(%llu), iIndex(%d)\n", playerID, 0xFFFF);
    }
    else
    {
      result = this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
      if ( result != nullptr )
        return result;
    }
  }
  if ( this->m_pDefaultAvatarImage == nullptr )
  {
    pObject = (ScaleformRenderer *)this->m_pRenderer.pObject;
    if ( this->m_pDefaultAvatarTexture != nullptr )
    {
      playerID_4 = (ScaleformUIAvatarImage *)MemAlloc_Alloc(nSize: 0x98u);
      v14 = 0;
      if ( playerID_4 != nullptr )
      {
        m_pDefaultAvatarTexture = this->m_pDefaultAvatarTexture;
        v12 = m_pDefaultAvatarTexture->Height(this: m_pDefaultAvatarTexture);
        v11 = m_pDefaultAvatarTexture->Width(this: m_pDefaultAvatarTexture);
        v10 = m_pDefaultAvatarTexture->Format(this: m_pDefaultAvatarTexture);
        v7 = m_pDefaultAvatarTexture->ImageData_3(this: m_pDefaultAvatarTexture);
        v8 = ScaleformUIAvatarImage::ScaleformUIAvatarImage(
               this: playerID_4,
               pRenderer: pObject,
               xuid: 0,
               defaultRgba: v7,
               defaultFormat: v10,
               defaultWidth: v11,
               defaultHeight: v12);
LABEL_12:
        this->m_pDefaultAvatarImage = v8;
        return this->m_pDefaultAvatarImage;
      }
    }
    else
    {
      v9 = (ScaleformUIAvatarImage *)MemAlloc_Alloc(nSize: 0x98u);
      v14 = 1;
      if ( v9 != nullptr )
      {
        v8 = ScaleformUIAvatarImage::ScaleformUIAvatarImage(
               this: v9,
               pRenderer: pObject,
               xuid: 0,
               defaultRgba: FLOAT_0_0,
               defaultFormat: IMAGE_FORMAT_A8,
               defaultWidth: 2,
               defaultHeight: 2);
        goto LABEL_12;
      }
    }
    v8 = nullptr;
    goto LABEL_12;
  }
  return this->m_pDefaultAvatarImage;
}

//------------------------------------------------------------------------------
// Address: 0x100100C0
// Name: public: virtual void ScaleformUIImpl::RunFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge ScaleformUIImpl::RunFrame(
        ScaleformUIImpl *this@<ecx>,
        void *(__cdecl **a2)(const char *, int *)@<ebx>,
        float time)
{
  int i; // esi

  ScaleformUIImpl::UpdateAvatarImages(this, a2);
  for ( i = 0; i < 4; ++i )
    ScaleformUIImpl::AdvanceSlot(this, slot: i, time);
}

//------------------------------------------------------------------------------
// Address: 0x10010170
// Name: public: virtual void ScaleformUIImpl::AvatarImageAddRef(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::AvatarImageAddRef(ScaleformUIImpl *this, unsigned __int64 playerID)
{
  unsigned int v2; // ebx
  unsigned __int16 v4; // ax
  bool v5; // zf
  ScaleformRenderer *pObject; // edi
  int (*Height)(void); // edx
  IVTFTexture *m_pDefaultAvatarTexture; // esi
  const unsigned __int8 *v9; // eax
  ScaleformUIAvatarImage *v10; // eax
  ScaleformUIAvatarImage *v11; // eax
  ScaleformUIAvatarImage *elem; // esi
  int v13; // edi
  ImageFormat v14; // [esp-Ch] [ebp-50h]
  int v15; // [esp-8h] [ebp-4Ch]
  int v16; // [esp-4h] [ebp-48h]
  CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t search; // [esp+Ch] [ebp-38h] BYREF
  CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t insert; // [esp+1Ch] [ebp-28h] BYREF
  CUtlRBTree<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_Tree; // [esp+2Ch] [ebp-18h]
  ScaleformUIAvatarImage *v20; // [esp+30h] [ebp-14h]
  ScaleformRenderer *pRenderer; // [esp+34h] [ebp-10h]
  int v22; // [esp+40h] [ebp-4h]

  v2 = playerID;
  search.key = playerID;
  p_m_Tree = &this->m_mapUserXuidToAvatar.m_Tree;
  v4 = CUtlRBTree<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_mapUserXuidToAvatar.m_Tree,
         &search);
  if ( v4 != 0xFFFF )
  {
    elem = this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
    goto LABEL_13;
  }
  v5 = this->m_pDefaultAvatarTexture == nullptr;
  pObject = (ScaleformRenderer *)this->m_pRenderer.pObject;
  pRenderer = pObject;
  if ( v5 )
  {
    v11 = (ScaleformUIAvatarImage *)MemAlloc_Alloc(nSize: 0x98u);
    v20 = v11;
    v22 = 1;
    if ( v11 != nullptr )
    {
      v10 = ScaleformUIAvatarImage::ScaleformUIAvatarImage(
              this: v11,
              pRenderer: pObject,
              xuid: playerID,
              defaultRgba: FLOAT_0_0,
              defaultFormat: IMAGE_FORMAT_A8,
              defaultWidth: 2,
              defaultHeight: 2);
      goto LABEL_8;
    }
LABEL_7:
    v10 = nullptr;
    goto LABEL_8;
  }
  v20 = (ScaleformUIAvatarImage *)MemAlloc_Alloc(nSize: 0x98u);
  v22 = 0;
  if ( v20 == nullptr )
    goto LABEL_7;
  Height = (int (*)(void))this->m_pDefaultAvatarTexture->Height;
  m_pDefaultAvatarTexture = this->m_pDefaultAvatarTexture;
  v16 = Height();
  v15 = m_pDefaultAvatarTexture->Width(this: m_pDefaultAvatarTexture);
  v14 = m_pDefaultAvatarTexture->Format(this: m_pDefaultAvatarTexture);
  v9 = m_pDefaultAvatarTexture->ImageData_3(this: m_pDefaultAvatarTexture);
  v10 = ScaleformUIAvatarImage::ScaleformUIAvatarImage(
          this: v20,
          pRenderer,
          xuid: playerID,
          defaultRgba: v9,
          defaultFormat: v14,
          defaultWidth: v15,
          defaultHeight: v16);
  v2 = playerID;
LABEL_8:
  elem = v10;
  v22 = -1;
  if ( !ScaleformUIAvatarImage::LoadAvatarImage(this: v10) )
  {
    _Warning(a1: "We failed to load the avatar image for user %llX\n", __PAIR64__(HIDWORD(playerID), v2));
    if ( elem != nullptr )
    {
      ScaleformUIAvatarImage::~ScaleformUIAvatarImage(this: elem);
      free(pMem: elem);
    }
    return;
  }
  insert.key = __PAIR64__(HIDWORD(playerID), v2);
  insert.elem = elem;
  CUtlRBTree<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: p_m_Tree,
    &insert);
LABEL_13:
  v13 = ++elem->m_nRefcount;
  if ( v13 <= 0 )
    ScaleformUIAvatarImage::OnFinalRelease(this: elem);
  DevMsg(a1: "Avatar image for user %llX cached [refcount=%d]\n", __PAIR64__(HIDWORD(playerID), v2), v13);
}

//------------------------------------------------------------------------------
// Address: 0x10010320
// Name: public: virtual void ScaleformUIImpl::AvatarImageRelease(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::AvatarImageRelease(ScaleformUIImpl *this, unsigned __int64 playerID)
{
  CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short> *p_m_mapUserXuidToAvatar; // esi
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // di
  int v5; // ebx
  ScaleformUIAvatarImage *elem; // ecx
  CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t search; // [esp+8h] [ebp-14h] BYREF
  ScaleformUIImpl *v8; // [esp+18h] [ebp-4h]

  search.key = playerID;
  p_m_mapUserXuidToAvatar = &this->m_mapUserXuidToAvatar;
  v8 = this;
  v3 = CUtlRBTree<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_mapUserXuidToAvatar.m_Tree,
         &search);
  v4 = v3;
  if ( v3 != 0xFFFF )
  {
    v5 = v3;
    elem = v8->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
    v8 = (ScaleformUIImpl *)--elem->m_nRefcount;
    if ( (int)v8 <= 0 )
    {
      ScaleformUIAvatarImage::OnFinalRelease(this: elem);
      if ( v4 != 0xFFFF )
      {
        CUtlRBTree<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
          this: &p_m_mapUserXuidToAvatar->m_Tree,
          elem: v4);
        p_m_mapUserXuidToAvatar->m_Tree.m_Elements.m_pMemory[v5].m_Left = v4;
        p_m_mapUserXuidToAvatar->m_Tree.m_Elements.m_pMemory[v5].m_Right = p_m_mapUserXuidToAvatar->m_Tree.m_FirstFree;
        --p_m_mapUserXuidToAvatar->m_Tree.m_NumElements;
        p_m_mapUserXuidToAvatar->m_Tree.m_FirstFree = v4;
      }
    }
    DevMsg(a1: "Avatar image for user %llX released [refcount=%d]\n", playerID, v8);
  }
}
