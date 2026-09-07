// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties.cpp
// Functions: 18
// ============================================================

#include "utils\hlfaceposer\eventproperties.h"

//------------------------------------------------------------------------------
// Address: 0x0043D520
// Name: bool StringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StringLessThan(const char **lhs, const char **rhs)
{
  int v3; // kr00_4

  if ( *lhs == nullptr )
    return false;
  if ( *rhs == nullptr )
    return true;
  v3 = strcmp(*lhs, *rhs);
  return v3 != 0 && -(v3 < 0) - ((v3 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043D580
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x0043D5B0
// Name: protected: void CBaseEventPropertiesDialog::PopulateTagList(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEventPropertiesDialog::PopulateTagList(CBaseEventPropertiesDialog *this, CEventParams *params)
{
  HWND DlgItem; // eax
  HWND v3; // esi
  char *v4; // eax
  CChoreoScene *v5; // esi
  int v6; // edi
  CChoreoActor *Actor; // eax
  CChoreoActor *v8; // ebx
  int v9; // esi
  CChoreoChannel *Channel; // eax
  CChoreoChannel *v11; // edi
  int v12; // esi
  CChoreoEvent *Event; // eax
  CChoreoEvent *v14; // esi
  int v15; // ebx
  CEventAbsoluteTag *RelativeTag; // edi
  const char *Name; // eax
  char *v18; // eax
  const char *Parameters; // [esp-Ch] [ebp-28h]
  CChoreoActor *a; // [esp+4h] [ebp-18h]
  CChoreoChannel *c; // [esp+8h] [ebp-14h]
  HWND__ *control; // [esp+Ch] [ebp-10h]
  CChoreoScene *scene; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]
  int k; // [esp+24h] [ebp+8h]

  scene = params->m_pScene;
  if ( scene != nullptr )
  {
    DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1027);
    v3 = DlgItem;
    control = DlgItem;
    if ( DlgItem != nullptr )
    {
      SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
      v4 = va(fmt: "\"%s\" \"%s\"", params->m_szTagName, params->m_szTagWav);
      SendMessageA(hWnd: v3, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v4);
      v5 = scene;
      v6 = 0;
      for ( i = 0; v6 < CChoreoScene::GetNumActors(this: scene); i = v6 )
      {
        Actor = CChoreoScene::GetActor(this: v5, actor: v6);
        v8 = Actor;
        a = Actor;
        if ( Actor != nullptr )
        {
          v9 = 0;
          j = 0;
          if ( CChoreoActor::GetNumChannels(this: Actor) > 0 )
          {
            do
            {
              Channel = CChoreoActor::GetChannel(this: v8, channel: v9);
              v11 = Channel;
              c = Channel;
              if ( Channel != nullptr )
              {
                v12 = 0;
                k = 0;
                if ( CChoreoChannel::GetNumEvents(this: Channel) > 0 )
                {
                  do
                  {
                    Event = CChoreoChannel::GetEvent(this: v11, event: v12);
                    v14 = Event;
                    if ( Event != nullptr && CChoreoEvent::GetNumRelativeTags(this: Event) > 0 )
                    {
                      v15 = 0;
                      if ( CChoreoEvent::GetNumRelativeTags(this: v14) > 0 )
                      {
                        do
                        {
                          RelativeTag = (CEventAbsoluteTag *)CChoreoEvent::GetRelativeTag(this: v14, tagnum: v15);
                          if ( RelativeTag != nullptr )
                          {
                            Parameters = CChoreoEvent::GetParameters(this: v14);
                            Name = CEventAbsoluteTag::GetName(this: RelativeTag);
                            v18 = va(fmt: "\"%s\" \"%s\"", Name, Parameters);
                            SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v18);
                          }
                          ++v15;
                        }
                        while ( v15 < CChoreoEvent::GetNumRelativeTags(this: v14) );
                        v11 = c;
                      }
                    }
                    v12 = ++k;
                  }
                  while ( k < CChoreoChannel::GetNumEvents(this: v11) );
                  v8 = a;
                }
              }
              v9 = ++j;
            }
            while ( j < CChoreoActor::GetNumChannels(this: v8) );
            v6 = i;
          }
        }
        v5 = scene;
        ++v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D780
// Name: protected: void CBaseEventPropertiesDialog::SetDialogTitle(class CEventParams __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEventPropertiesDialog::SetDialogTitle(
        CBaseEventPropertiesDialog *this,
        CEventParams *params,
        const char *eventname,
        const char *desc)
{
  char sz[256]; // [esp+Ch] [ebp-100h] BYREF

  V_snprintf(pDest: sz, maxLen: 256, pFormat: " : %s", eventname);
  V_strncat(pDest: params->m_szDialogTitle, pSrc: sz, destBufferSize: 0x80u, max_chars_to_copy: -1);
  V_snprintf(pDest: sz, maxLen: 256, pFormat: "%s:", desc);
  SetWindowTextA(hWnd: this->m_hDialog, lpString: params->m_szDialogTitle);
  SetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1008, lpString: sz);
  SetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: params->m_szName);
}

//------------------------------------------------------------------------------
// Address: 0x0043D820
// Name: public: virtual void CBaseEventPropertiesDialog::ShowControlsForEventType(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEventPropertiesDialog::ShowControlsForEventType(
        CBaseEventPropertiesDialog *this,
        CEventParams *params)
{
  HWND DlgItem; // eax
  HWND v4; // eax
  HWND v5; // eax

  if ( !params->m_bHasEndTime )
  {
    DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
    ShowWindow(hWnd: DlgItem, nCmdShow: 0);
  }
  if ( params->m_bFixedLength )
  {
    v4 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
    ShowWindow(hWnd: v4, nCmdShow: 0);
    v5 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
    ShowWindow(hWnd: v5, nCmdShow: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D890
// Name: public: virtual void CBaseEventPropertiesDialog::InitControlData(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEventPropertiesDialog::InitControlData(CBaseEventPropertiesDialog *this, CEventParams *params)
{
  const char *v3; // eax
  const char *v4; // eax
  HWND DlgItem; // eax
  HWND v6; // eax
  HWND v7; // eax

  v3 = va(fmt: "%f", params->m_flStartTime);
  SetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: v3);
  v4 = va(fmt: "%f", params->m_flEndTime);
  SetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: v4);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
  SendMessageA(hWnd: DlgItem, Msg: 0xF1u, wParam: params->m_bHasEndTime, lParam: 0);
  if ( GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018) != nullptr )
  {
    v6 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
    SendMessageA(hWnd: v6, Msg: 0xF1u, wParam: params->m_bResumeCondition, lParam: 0);
  }
  v7 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1090);
  SendMessageA(hWnd: v7, Msg: 0xF1u, wParam: params->m_bDisabled, lParam: 0);
  CBaseEventPropertiesDialog::PopulateTagList(this, params);
}

//------------------------------------------------------------------------------
// Address: 0x0043D990
// Name: protected: virtual int CBaseEventPropertiesDialog::InternalHandleMessage(class CEventParams __near *,struct HWND__ __near *,unsigned int,unsigned int,long,bool __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEventPropertiesDialog::InternalHandleMessage(
        CBaseEventPropertiesDialog *this,
        CEventParams *params,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        __int16 wParam,
        int lParam,
        bool *handled)
{
  HWND DlgItem; // eax

  *handled = false;
  if ( uMsg != 273 || wParam != 1090 )
    return 0;
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1090);
  params->m_bDisabled = SendMessageA(hWnd: DlgItem, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
  *handled = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043D9F0
// Name: protected: void CBaseEventPropertiesDialog::ParseTags(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEventPropertiesDialog::ParseTags(CBaseEventPropertiesDialog *this, CEventParams *params)
{
  bool v3; // zf
  HWND DlgItem; // eax
  int v5; // eax
  char v6; // cl
  int v7; // eax
  char v8; // cl
  HWND__ *m_hDialog; // [esp-8h] [ebp-310h]
  char tagname[256]; // [esp+8h] [ebp-300h] BYREF
  char wavename[256]; // [esp+108h] [ebp-200h] BYREF
  char v12[256]; // [esp+208h] [ebp-100h] BYREF
  CEventParams *paramsa; // [esp+310h] [ebp+8h]

  v3 = !params->m_bUsesTag;
  params->m_szTagName[0] = 0;
  paramsa = (CEventParams *)params->m_szTagWav;
  paramsa->m_szDialogTitle[0] = 0;
  if ( !v3 )
  {
    m_hDialog = this->m_hDialog;
    wavename[0] = 0;
    DlgItem = GetDlgItem(hDlg: m_hDialog, nIDDlgItem: 1027);
    if ( DlgItem != nullptr )
      SendMessageA(hWnd: DlgItem, Msg: 0xDu, wParam: 0x200u, lParam: (LPARAM)wavename);
    ParseFromMemory(buffer: wavename, size: strlen(wavename));
    if ( TokenAvailable() == 0 )
      goto LABEL_11;
    GetToken(crossline: 0);
    v5 = 0;
    do
    {
      v6 = token[v5];
      tagname[v5++] = v6;
    }
    while ( v6 != 0 );
    if ( TokenAvailable() != 0 )
    {
      GetToken(crossline: 0);
      v7 = 0;
      do
      {
        v8 = token[v7];
        v12[v7++] = v8;
      }
      while ( v8 != 0 );
      strcpy(params->m_szTagName, tagname);
      strcpy(paramsa->m_szDialogTitle, v12);
    }
    else
    {
LABEL_11:
      params->m_bUsesTag = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DB30
// Name: protected: void CBaseEventPropertiesDialog::UpdateTagRadioButtons(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEventPropertiesDialog::UpdateTagRadioButtons(
        CBaseEventPropertiesDialog *this,
        CEventParams *params)
{
  HWND DlgItem; // eax
  HWND v4; // eax
  HWND v5; // eax

  if ( params->m_bUsesTag )
  {
    DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1026);
    SendMessageA(hWnd: DlgItem, Msg: 0xF1u, wParam: 1u, lParam: 0);
    v4 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1025);
  }
  else
  {
    v5 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1025);
    SendMessageA(hWnd: v5, Msg: 0xF1u, wParam: 1u, lParam: 0);
    v4 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1026);
  }
  SendMessageA(hWnd: v4, Msg: 0xF1u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043DBC0
// Name: protected: void CBaseEventPropertiesDialog::GetSplineRect(struct HWND__ __near *,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEventPropertiesDialog::GetSplineRect(
        CBaseEventPropertiesDialog *this,
        HWND__ *placeholder,
        tagRECT *rcOut)
{
  tagRECT rcDlg; // [esp+Ch] [ebp-10h] BYREF

  GetWindowRect(hWnd: placeholder, lpRect: rcOut);
  GetWindowRect(hWnd: this->m_hDialog, lpRect: &rcDlg);
  OffsetRect(lprc: rcOut, dx: -rcDlg.left, dy: -rcDlg.top);
}

//------------------------------------------------------------------------------
// Address: 0x0043DC10
// Name: protected: void CBaseEventPropertiesDialog::DrawSpline(struct HDC__ __near *,struct HWND__ __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEventPropertiesDialog::DrawSpline(
        CBaseEventPropertiesDialog *this,
        HDC hdc,
        HWND placeholder,
        CChoreoEvent *e)
{
  DWORD SysColor; // eax
  HBRUSH SolidBrush; // ebx
  DWORD v9; // eax
  HPEN Pen; // eax
  HPEN__ *v11; // eax
  CChoreoEvent_vtbl *v12; // edx
  int v13; // edi
  double v14; // st7
  DWORD v15; // eax
  HBRUSH v16; // edi
  tagRECT Rect; // [esp+10h] [ebp-2Ch] BYREF
  tagRECT rcOut; // [esp+20h] [ebp-1Ch] BYREF
  HPEN__ *oldPen; // [esp+30h] [ebp-Ch]
  int v20; // [esp+34h] [ebp-8h]
  float starttime; // [esp+38h] [ebp-4h]
  float height; // [esp+44h] [ebp+8h]
  float heighta; // [esp+44h] [ebp+8h]
  float range; // [esp+48h] [ebp+Ch]
  float duration; // [esp+4Ch] [ebp+10h]

  GetWindowRect(hWnd: placeholder, lpRect: &rcOut);
  GetWindowRect(hWnd: this->m_hDialog, lpRect: &Rect);
  OffsetRect(lprc: &rcOut, dx: -Rect.left, dy: -Rect.top);
  SysColor = GetSysColor(nIndex: 15);
  SolidBrush = CreateSolidBrush(color: SysColor);
  FillRect(hDC: hdc, lprc: &rcOut, hbr: SolidBrush);
  DeleteObject(ho: SolidBrush);
  if ( e != nullptr )
  {
    range = (float)(rcOut.right - rcOut.left);
    if ( range > 1.0 )
    {
      height = (float)(rcOut.bottom - rcOut.top);
      v9 = GetSysColor(nIndex: 18);
      Pen = CreatePen(iStyle: 0, cWidth: 1, color: v9);
      v11 = (HPEN__ *)SelectObject(hdc, h: Pen);
      v12 = e->__vftable;
      oldPen = v11;
      duration = v12->GetDuration(this: e);
      starttime = CChoreoEvent::GetStartTime(this: e);
      v13 = 0;
      v20 = (int)range;
      if ( (int)range > 0 )
      {
        heighta = height - 1.0;
        do
        {
          v14 = (1.0
               - CChoreoEvent::GetIntensity(
                   this: e,
                   scenetime: (float)((float)((float)v13 / (float)(range - 1.0)) * duration) + starttime))
              * heighta;
          if ( v13 != 0 )
            LineTo(hdc, x: v13 + rcOut.left, y: rcOut.top + (int)v14);
          else
            MoveToEx(hdc, x: rcOut.left, y: rcOut.top + (int)v14, lppt: nullptr);
          ++v13;
        }
        while ( v13 < v20 );
      }
      SelectObject(hdc, h: oldPen);
      v15 = GetSysColor(nIndex: 16);
      v16 = CreateSolidBrush(color: v15);
      InflateRect(lprc: &rcOut, dx: 1, dy: 1);
      FrameRect(hDC: hdc, lprc: &rcOut, hbr: v16);
      DeleteObject(ho: v16);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DDC0
// Name: int EventProperties(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EventProperties(CEventParams *params)
{
  int result; // eax

  switch ( params->m_nType )
  {
    case 2:
      result = EventProperties_Expression(params);
      break;
    case 3:
      result = EventProperties_LookAt(params);
      break;
    case 4:
      result = EventProperties_MoveTo(params);
      break;
    case 5:
      result = EventProperties_Speak(params);
      break;
    case 6:
      result = EventProperties_Gesture(params);
      break;
    case 7:
      result = EventProperties_Sequence(params);
      break;
    case 8:
      result = EventProperties_Face(params);
      break;
    case 9:
      result = EventProperties_FireTrigger(params);
      break;
    case 0xA:
      result = EventProperties_FlexAnimation(params);
      break;
    case 0xB:
      result = EventProperties_SubScene(params);
      break;
    case 0xD:
      result = EventProperties_Interrupt(params);
      break;
    case 0xF:
      result = EventProperties_PermitResponses(params);
      break;
    case 0x10:
      result = EventProperties_Generic(params);
      break;
    case 0x11:
      result = EventProperties_Camera(params);
      break;
    default:
      result = 1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043E650
// Name: public: virtual int CMapEntities::Count(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapEntities::Count(CMapEntities *this)
{
  return this->m_Entities.m_Elements.m_Tree.m_NumElements;
}

//------------------------------------------------------------------------------
// Address: 0x0043EEA0
// Name: public: virtual char const __near * CMapEntities::GetName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapEntities::GetName(CMapEntities *this, int number)
{
  if ( number < 0 || number >= this->m_Entities.m_Elements.m_Tree.m_NumElements )
    return nullptr;
  else
    return this->m_Entities.m_Elements.m_Tree.m_Elements.m_pMemory[number].m_Data.key;
}

//------------------------------------------------------------------------------
// Address: 0x0043EFF0
// Name: public: int CMapEntities::FindNamedEntity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapEntities::FindNamedEntity(CMapEntities *this, const char *name)
{
  char lowername[128]; // [esp+4h] [ebp-9Ch] BYREF
  CUtlMap<char const *,CMapEntityData,int>::Node_t search; // [esp+84h] [ebp-1Ch] BYREF

  strcpy(lowername, name);
  strlwr(string: lowername);
  search.key = lowername;
  memset(&search.elem, 0, sizeof(search.elem));
  return CUtlRBTree<CUtlMap<char const *,CMapEntityData,int>::Node_t,int,CUtlMap<char const *,CMapEntityData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapEntityData,int>::Node_t,int>,int>>::Find(
           this: &this->m_Entities.m_Elements.m_Tree,
           &search);
}

//------------------------------------------------------------------------------
// Address: 0x0043F100
// Name: public: virtual bool CMapEntities::LookupOrigin(char const __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapEntities::LookupOrigin(CMapEntities *this, const char *name, Vector *origin, QAngle *angles)
{
  int v5; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CMapEntityData,int>::Node_t,int> *m_pMemory; // ecx
  int v8; // eax
  double x; // st7
  QAngle *p_elem; // eax
  char string[128]; // [esp+4h] [ebp-9Ch] BYREF
  CUtlMap<char const *,CMapEntityData,int>::Node_t search; // [esp+84h] [ebp-1Ch] BYREF

  strcpy(string, name);
  strlwr(string);
  search.key = string;
  memset(&search.elem, 0, sizeof(search.elem));
  v5 = CUtlRBTree<CUtlMap<char const *,CMapEntityData,int>::Node_t,int,CUtlMap<char const *,CMapEntityData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapEntityData,int>::Node_t,int>,int>>::Find(
         this: &this->m_Entities.m_Elements.m_Tree,
         &search);
  if ( v5 == -1 )
  {
    origin->x = 0.0;
    origin->y = 0.0;
    origin->z = 0.0;
    angles->x = 0.0;
    angles->y = 0.0;
    angles->z = 0.0;
    return 0;
  }
  else
  {
    m_pMemory = this->m_Entities.m_Elements.m_Tree.m_Elements.m_pMemory;
    v8 = v5;
    x = m_pMemory[v8].m_Data.elem.origin.x;
    p_elem = (QAngle *)&m_pMemory[v8].m_Data.elem;
    origin->x = x;
    origin->y = p_elem->y;
    origin->z = p_elem->z;
    *angles = p_elem[1];
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F290
// Name: public: virtual void CMapEntities::CheckUpdateMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapEntities::CheckUpdateMap(CMapEntities *this@<ecx>, int a2@<esi>, const char *mapname)
{
  char *m_szCurrentMap; // esi
  void *v4; // esi
  void *v5; // edi
  const char *v7; // [esp-4h] [ebp-940h]
  BSPHeader_t header; // [esp+8h] [ebp-934h] BYREF
  char angles[256]; // [esp+414h] [ebp-528h] BYREF
  char origin[256]; // [esp+514h] [ebp-428h] BYREF
  char value[256]; // [esp+614h] [ebp-328h] BYREF
  char key[256]; // [esp+714h] [ebp-228h] BYREF
  char name[256]; // [esp+814h] [ebp-128h] BYREF
  CMapEntityData ent; // [esp+914h] [ebp-28h] BYREF
  CMapEntities *v15; // [esp+92Ch] [ebp-10h]
  Vector org; // [esp+930h] [ebp-Ch] BYREF

  v15 = this;
  if ( mapname != nullptr && *mapname != 0 )
  {
    m_szCurrentMap = this->m_szCurrentMap;
    if ( _V_stricmp(s1: mapname, s2: this->m_szCurrentMap) != 0 )
    {
      V_strncpy(pDest: m_szCurrentMap, pSrc: mapname, maxLen: 1024);
      CUtlDict<CMapEntityData,int>::RemoveAll(this: &v15->m_Entities);
      v4 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: mapname, a3: "rb", a4: 0);
      if ( v4 != nullptr )
      {
        ((void (__thiscall *)(IBaseFileSystem *, BSPHeader_t *, int, void *, int))filesystem->Read)(
          a1: &filesystem->IBaseFileSystem,
          a2: &header,
          a3: 1036,
          a4: v4,
          a5: a2);
        if ( header.ident == 1347633750 && (unsigned int)(header.m_nVersion - 19) <= 2 )
        {
          if ( header.lumps[0].filelen > 0 )
          {
            v7 = nullptr;
            ((void (__thiscall *)(IBaseFileSystem *, void *, int))filesystem->Seek)(
              a1: &filesystem->IBaseFileSystem,
              a2: v4,
              a3: header.lumps[0].fileofs);
            v5 = operator new(nSize: header.lumps[0].filelen + 1);
            filesystem->Read(this: &filesystem->IBaseFileSystem, a2: v5, a3: header.lumps[0].filelen, a4: v4);
            filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v4);
            *((_BYTE *)v5 + header.lumps[0].filelen) = 0;
            ParseFromMemory(buffer: (char *)v5, size: header.lumps[0].filelen);
            while ( GetToken(crossline: 1) != 0 )
            {
              if ( _V_stricmp(s1: token, s2: "{") != 0 )
                _Error(this: (ISceneTokenProcessor *)&stru_4F25A4, a2: v7);
              name[0] = 0;
              origin[0] = 0;
              angles[0] = 0;
              while ( 1 )
              {
                if ( GetToken(crossline: 1) == 0 )
                  _Error(this: (ISceneTokenProcessor *)&stru_4F257C, a2: v7);
                if ( _V_stricmp(s1: token, s2: "}") == 0 )
                  break;
                V_strncpy(pDest: key, pSrc: token, maxLen: 256);
                GetToken(crossline: 0);
                V_strncpy(pDest: value, pSrc: token, maxLen: 256);
                if ( _V_stricmp(s1: key, s2: "name") == 0 )
                  V_strncpy(pDest: name, pSrc: value, maxLen: 256);
                if ( _V_stricmp(s1: key, s2: "targetname") == 0 )
                  V_strncpy(pDest: name, pSrc: value, maxLen: 256);
                if ( _V_stricmp(s1: key, s2: "origin") == 0 )
                  V_strncpy(pDest: origin, pSrc: value, maxLen: 256);
                if ( _V_stricmp(s1: key, s2: "angles") == 0 )
                  V_strncpy(pDest: angles, pSrc: value, maxLen: 256);
              }
              if ( name[0] != 0 && CMapEntities::FindNamedEntity(this: v15, name) == -1 )
              {
                memset(&ent, 0, sizeof(ent));
                if ( origin[0] != 0 && sscanf(string: origin, format: "%f %f %f", &org, &org.y, &org.z) == 3 )
                  ent.origin = org;
                if ( angles[0] != 0 && sscanf(string: angles, format: "%f %f %f", &org, &org.y, &org.z) == 3 )
                  ent.angles = (QAngle)org;
                CUtlDict<CMapEntityData,int>::Insert(this: &v15->m_Entities, pName: name, element: &ent);
              }
            }
            free(pMem: v5);
          }
          else
          {
            Con_ErrorPrintf(fmt: "BSP file %s is missing entity lump\n", mapname);
            ((void (__thiscall *)(IBaseFileSystem *))filesystem->Close)(a1: &filesystem->IBaseFileSystem);
          }
        }
        else
        {
          Con_ErrorPrintf(fmt: "BSP file %s is wrong version (%i), expected (%i)\n", mapname, header.m_nVersion, 21);
          ((void (__thiscall *)(IBaseFileSystem *))filesystem->Close)(a1: &filesystem->IBaseFileSystem);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F6B0
// Name: protected: void CBaseEventPropertiesDialog::PopulateNamedActorList(struct HWND__ __near *,class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEventPropertiesDialog::PopulateNamedActorList(
        CBaseEventPropertiesDialog *this,
        HWND__ *wnd,
        CEventParams *params)
{
  CChoreoScene *m_pScene; // ecx
  const char *Mapname; // eax
  int m_NumElements; // eax
  int v6; // ebx
  const char *v7; // eax
  int v8; // eax
  UtlRBTreeNode_t<char const *,int> *m_pMemory; // ecx
  int v10; // edx
  int v11; // esi
  int v12; // edx
  int i; // ebx
  CChoreoActor *Actor; // eax
  CChoreoActor *v15; // esi
  int v16; // eax
  UtlRBTreeNode_t<char const *,int> *v17; // ecx
  const char *v18; // edx
  unsigned int v19; // esi
  int v20; // edx
  const char **p_m_Data; // esi
  int j; // ebx
  const char *m_Data; // eax
  CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > m_SortedNames; // [esp+Ch] [ebp-34h] BYREF
  const char *name; // [esp+30h] [ebp-10h] BYREF
  int parent; // [esp+34h] [ebp-Ch] BYREF
  char *search; // [esp+38h] [ebp-8h] BYREF
  bool leftchild; // [esp+3Fh] [ebp-1h] BYREF

  m_pScene = params->m_pScene;
  Mapname = nullptr;
  if ( m_pScene != nullptr )
    Mapname = CChoreoScene::GetMapname(this: m_pScene);
  m_SortedNames.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))NameLessFunc;
  memset(&m_SortedNames.m_Elements, 0, sizeof(m_SortedNames.m_Elements));
  m_SortedNames.m_Root = -1;
  m_SortedNames.m_NumElements = 0;
  m_SortedNames.m_FirstFree = -1;
  m_SortedNames.m_LastAlloc.index = -1;
  m_SortedNames.m_pElements = nullptr;
  if ( Mapname != nullptr )
  {
    CMapEntities::CheckUpdateMap(this: &g_MapEntities, a2: -1, mapname: Mapname);
    m_NumElements = g_MapEntities.m_Entities.m_Elements.m_Tree.m_NumElements;
    v6 = 0;
    if ( g_MapEntities.m_Entities.m_Elements.m_Tree.m_NumElements > 0 )
    {
      search = nullptr;
      do
      {
        if ( v6 < 0 || v6 >= m_NumElements )
          v7 = nullptr;
        else
          v7 = *(const char **)&search[(unsigned int)g_MapEntities.m_Entities.m_Elements.m_Tree.m_Elements.m_pMemory
                                     + 16];
        name = v7;
        if ( v7 != nullptr && *v7 != 0 )
        {
          parent = -1;
          leftchild = false;
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FindInsertionPosition(
            this: &m_SortedNames,
            insert: &name,
            &parent,
            &leftchild);
          v8 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode(
                 this: &m_SortedNames,
                 a2: nullptr);
          m_pMemory = m_SortedNames.m_Elements.m_pMemory;
          v10 = parent;
          v11 = v8;
          m_SortedNames.m_Elements.m_pMemory[v11].m_Parent = parent;
          m_pMemory[v11].m_Right = -1;
          m_pMemory[v11].m_Left = -1;
          m_pMemory[v11].m_Tag = 0;
          if ( v10 == -1 )
          {
            m_SortedNames.m_Root = v8;
          }
          else
          {
            v12 = v10;
            if ( leftchild )
              m_pMemory[v12].m_Left = v8;
            else
              m_pMemory[v12].m_Right = v8;
          }
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::InsertRebalance(
            this: &m_SortedNames,
            elem: v8);
          ++m_SortedNames.m_NumElements;
          if ( &m_SortedNames.m_Elements.m_pMemory[v11] != (UtlRBTreeNode_t<char const *,int> *)-16 )
            m_SortedNames.m_Elements.m_pMemory[v11].m_Data = name;
        }
        m_NumElements = g_MapEntities.m_Entities.m_Elements.m_Tree.m_NumElements;
        search += 44;
        ++v6;
      }
      while ( v6 < g_MapEntities.m_Entities.m_Elements.m_Tree.m_NumElements );
    }
  }
  for ( i = 0; i < CChoreoScene::GetNumActors(this: params->m_pScene); ++i )
  {
    Actor = CChoreoScene::GetActor(this: params->m_pScene, actor: i);
    v15 = Actor;
    if ( Actor != nullptr
      && CChoreoActor::GetName(this: Actor) != nullptr
      && CChoreoActor::GetName(this: v15)->m_szName[0] != 0 )
    {
      search = (char *)CChoreoActor::GetName(this: v15);
      if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Find(
             this: &m_SortedNames,
             (const char *const *)&search) == -1 )
      {
        parent = (int)CChoreoActor::GetName(this: v15);
        name = (const char *)-1;
        leftchild = false;
        CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FindInsertionPosition(
          this: &m_SortedNames,
          insert: (const char *const *)&parent,
          parent: (int *)&name,
          &leftchild);
        v16 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode(
                this: &m_SortedNames,
                a2: nullptr);
        v17 = m_SortedNames.m_Elements.m_pMemory;
        v18 = name;
        v19 = v16;
        m_SortedNames.m_Elements.m_pMemory[v19].m_Parent = (int)name;
        v17[v19].m_Right = -1;
        v17[v19].m_Left = -1;
        v17[v19].m_Tag = 0;
        if ( v18 == (const char *)-1 )
        {
          m_SortedNames.m_Root = v16;
        }
        else
        {
          v20 = (int)v18;
          if ( leftchild )
            v17[v20].m_Left = v16;
          else
            v17[v20].m_Right = v16;
        }
        CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::InsertRebalance(
          this: &m_SortedNames,
          elem: v16);
        ++m_SortedNames.m_NumElements;
        p_m_Data = &m_SortedNames.m_Elements.m_pMemory[v19].m_Data;
        if ( p_m_Data != nullptr )
          *p_m_Data = (const char *)parent;
      }
    }
  }
  for ( j = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FirstInorder(this: &m_SortedNames);
        j != -1;
        j = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NextInorder(
              this: &m_SortedNames,
              i: j) )
  {
    m_Data = m_SortedNames.m_Elements.m_pMemory[j].m_Data;
    if ( m_Data != nullptr && *m_Data != 0 )
      SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)m_SortedNames.m_Elements.m_pMemory[j].m_Data);
  }
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!player");
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!enemy");
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!self");
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!friend");
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!speechtarget");
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!target1");
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!target2");
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!target3");
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!target4");
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!target5");
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!target6");
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!target7");
  SendMessageA(hWnd: wnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"!target8");
  CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RemoveAll(this: &m_SortedNames);
  if ( m_SortedNames.m_Elements.m_nGrowSize >= 0 && m_SortedNames.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_SortedNames.m_Elements.m_pMemory);
}
