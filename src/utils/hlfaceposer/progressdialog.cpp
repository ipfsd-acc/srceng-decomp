// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/progressdialog.cpp
// Functions: 63
// ============================================================

#include "utils\hlfaceposer\progressdialog.h"

//------------------------------------------------------------------------------
// Address: 0x004774B0
// Name: public: virtual bool CProgressDialog::IsCancelled(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CProgressDialog::IsCancelled(CProgressDialog *this)
{
  return this->m_bShowCancel && this->m_bWantsCancel;
}

//------------------------------------------------------------------------------
// Address: 0x004774D0
// Name: public: virtual void CProgressDialog::Finish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgressDialog::Finish(CProgressDialog *this)
{
  if ( this->m_hwndDlg != nullptr )
  {
    DestroyWindow(hWnd: this->m_hwndDlg);
    this->m_hwndDlg = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004774F0
// Name: private: int CProgressDialog::ProgressDialogProcImpl(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProgressDialog::ProgressDialogProcImpl(
        CProgressDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        __int16 wParam,
        int lParam)
{
  int SystemMetrics; // eax
  const char *v8; // eax
  const char *v9; // eax
  HWND DlgItem; // eax
  HWND v11; // eax
  int v12; // [esp+0h] [ebp-30h]
  int rcParent_8; // [esp+18h] [ebp-18h]
  tagRECT rcDlg; // [esp+20h] [ebp-10h] BYREF

  if ( uMsg == 272 )
  {
    GetWindowRect(hWnd: hwndDlg, lpRect: &rcDlg);
    rcParent_8 = GetSystemMetrics(nIndex: 16);
    SystemMetrics = GetSystemMetrics(nIndex: 17);
    MoveWindow(
      hWnd: hwndDlg,
      X: (rcParent_8 - (rcDlg.right - rcDlg.left)) / 2,
      Y: (SystemMetrics - (rcDlg.bottom - rcDlg.top)) / 2,
      nWidth: rcDlg.right - rcDlg.left,
      nHeight: rcDlg.bottom - rcDlg.top,
      bRepaint: true);
    v8 = CUtlString::operator char const *(this: &this->m_sTitle);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1093, lpString: v8);
    v9 = CUtlString::operator char const *(this: &this->m_sStatus);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1094, lpString: v9);
    DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1092);
    SendMessageA(hWnd: DlgItem, Msg: 0x401u, wParam: 0, lParam: 65536000);
    v12 = this->m_bShowCancel ? 5 : 0;
    v11 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 2);
    ShowWindow(hWnd: v11, nCmdShow: v12);
    ((void (__thiscall *)(CProgressDialog *, _DWORD))this->Update)(a1: this, a2: 0);
  }
  else if ( uMsg == 273 )
  {
    if ( wParam == 2 )
      this->m_bWantsCancel = true;
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004775F0
// Name: public: static int CProgressDialog::ProgressDialogProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CProgressDialog::ProgressDialogProc(HWND__ *hwndDlg, unsigned int uMsg, __int16 wParam, int lParam)
{
  return CProgressDialog::ProgressDialogProcImpl(this: &g_ProgressDialog, hwndDlg, uMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x00477600
// Name: public: virtual void CProgressDialog::Start(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgressDialog::Start(
        CProgressDialog *this,
        const char *pchTitle,
        const char *pchText,
        bool bShowCancel)
{
  HMODULE ModuleHandleA; // eax
  HWND Handle; // [esp-Ch] [ebp-10h]

  if ( this->m_hwndDlg != nullptr )
    this->Finish(this);
  CUtlString::operator=(this: &this->m_sTitle, src: pchTitle);
  CUtlString::operator=(this: &this->m_sStatus, src: pchText);
  this->m_flFraction = 0.0;
  this->m_bShowCancel = bShowCancel;
  this->m_bWantsCancel = false;
  this->m_flStartTime = _Plat_FloatTime();
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  this->m_hwndDlg = CreateDialogParamA(
                      hInstance: ModuleHandleA,
                      lpTemplateName: (LPCSTR)0x87,
                      hWndParent: Handle,
                      lpDialogFunc: (DLGPROC)CProgressDialog::ProgressDialogProc,
                      dwInitParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00477680
// Name: public: virtual void CProgressDialog::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgressDialog::Update(CProgressDialog *this, float flZeroToOneFraction)
{
  float v2; // xmm0_4
  HWND DlgItem; // eax
  signed int v5; // ecx
  HWND v6; // eax
  HWND__ *m_hwndDlg; // [esp-10h] [ebp-10h]

  v2 = 0.0;
  if ( flZeroToOneFraction >= 0.0 )
  {
    v2 = 1.0;
    if ( flZeroToOneFraction <= 1.0 )
      v2 = flZeroToOneFraction;
  }
  m_hwndDlg = this->m_hwndDlg;
  this->m_flFraction = v2;
  DlgItem = GetDlgItem(hDlg: m_hwndDlg, nIDDlgItem: 1092);
  v5 = (int)(float)(flZeroToOneFraction * 1000.0);
  if ( v5 >= 0 )
  {
    if ( v5 > 1000 )
      v5 = 1000;
  }
  else
  {
    v5 = 0;
  }
  SendMessageA(hWnd: DlgItem, Msg: 0x402u, wParam: v5, lParam: 0);
  v6 = GetDlgItem(hDlg: this->m_hwndDlg, nIDDlgItem: 2);
  if ( (SendMessageA(hWnd: v6, Msg: 0xF2u, wParam: 0, lParam: 0) & 4) != 0 )
    this->m_bWantsCancel = true;
  if ( GetAsyncKeyState(vKey: 27) != 0 )
    this->m_bWantsCancel = true;
  mx::check();
}

//------------------------------------------------------------------------------
// Address: 0x00477730
// Name: public: char const __near * CFmtStrN<256>::sprintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *CFmtStrN<256>::sprintf(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  bool v3; // zf
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  this->InitQuietTruncation(this);
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v2->m_szBuf, maxLen: 255, pFormat: pszFormat, params, pbTruncated: (bool *)&this + 3);
  v3 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v3 && !v2->m_bQuietTruncation && `CFmtStrN<256>::sprintf'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::sprintf'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: v2->m_szBuf);
  return v2->m_szBuf;
}

//------------------------------------------------------------------------------
// Address: 0x004777A0
// Name: public: virtual void CProgressDialog::UpdateText(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CProgressDialog::UpdateText(CProgressDialog *this, const char *pchFmt, ...)
{
  const char *v2; // eax
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> *v4; // eax
  double v5; // st7
  float m_flFraction; // xmm1_4
  double v7; // xmm0_8
  int v8; // esi
  int v9; // ecx
  char buf[2048]; // [esp+14h] [ebp-A20h] BYREF
  CFmtStrN<256> v11; // [esp+814h] [ebp-220h] BYREF
  CFmtStrN<256> string; // [esp+920h] [ebp-114h] BYREF
  long double elapsed; // [esp+A2Ch] [ebp-8h]
  va_list params; // [esp+A44h] [ebp+10h] BYREF

  va_start(params, pchFmt);
  V_vsnprintf(pDest: buf, maxLen: 2048, pFormat: pchFmt, params);
  CUtlString::operator=(this: &this->m_sStatus, src: buf);
  v2 = CUtlString::operator char const *(this: &this->m_sStatus);
  v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "%s", v2);
  SetDlgItemTextA(hDlg: this->m_hwndDlg, nIDDlgItem: 1094, lpString: v3->m_szBuf);
  v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "%.2f %%", (float)(this->m_flFraction * 100.0));
  SetDlgItemTextA(hDlg: this->m_hwndDlg, nIDDlgItem: 1095, lpString: v4->m_szBuf);
  v5 = _Plat_FloatTime();
  m_flFraction = this->m_flFraction;
  v7 = 0.0;
  elapsed = v5 - this->m_flStartTime;
  if ( m_flFraction > 0.0 )
    v7 = elapsed / m_flFraction;
  v8 = (int)((float)(1.0 - m_flFraction) * v7);
  v9 = v8 / 60;
  string.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  *(_WORD *)&string.m_bQuietTruncation = 1;
  string.m_nLength = 0;
  if ( v8 / 60 <= 0 || (v8 %= 60, v9 / 60 <= 0) )
    CFmtStrN<256>::sprintf(this: &string, pszFormat: "Time Remaining:  %02i:%02i", v9, v8);
  else
    CFmtStrN<256>::sprintf(this: &string, pszFormat: "Time Remaining:  %2i:%02i:%02i", v9 / 60, v9 % 60, v8);
  SetDlgItemTextA(hDlg: this->m_hwndDlg, nIDDlgItem: 1096, lpString: string.m_szBuf);
}

//------------------------------------------------------------------------------
// Address: 0x004CF8C1
// Name: _sprintf
// Source: json
//------------------------------------------------------------------------------
int sprintf(char *string, const char *format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+38h] [ebp+10h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && string != nullptr )
  {
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    str._flag = 66;
    v3 = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = --str._cnt < 0;
    v5 = v3;
    if ( v4 )
      _flsbuf(ch: 0, &str);
    else
      *str._ptr = 0;
    return v5;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF945
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // edi
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = _fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pMem: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF9B2
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFA26
// Name: __fread_nolock_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fread_nolock_s(
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int cnt; // eax
  unsigned int v9; // edi
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  char *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-20h]
  unsigned int streambufsize; // [esp+10h] [ebp-Ch]
  char *data; // [esp+14h] [ebp-8h]
  unsigned int dataSize; // [esp+18h] [ebp-4h]

  data = (char *)buffer;
  dataSize = bufferSize;
  if ( elementSize == 0 || num == 0 )
    return 0;
  if ( buffer != nullptr )
  {
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
      goto LABEL_13;
    if ( bufferSize != -1 )
      memset(dst: buffer, value: 0, count: bufferSize);
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
    {
LABEL_13:
      v6 = num * elementSize;
      v7 = num * elementSize;
      if ( (stream->_flag & 0x10C) != 0 )
        streambufsize = stream->_bufsiz;
      else
        streambufsize = 4096;
      if ( v6 == 0 )
        return num;
      while ( 1 )
      {
        if ( (stream->_flag & 0x10C) != 0 )
        {
          cnt = stream->_cnt;
          if ( cnt != 0 )
          {
            if ( cnt < 0 )
              goto LABEL_44;
            v9 = v7;
            if ( v7 >= cnt )
              v9 = stream->_cnt;
            if ( v9 > dataSize )
              goto LABEL_41;
            memcpy_s(dst: data, sizeInBytes: dataSize, src: stream->_ptr, count: v9);
            stream->_cnt -= v9;
            stream->_ptr += v9;
            data += v9;
            v7 -= v9;
            dataSize -= v9;
            v6 = num * elementSize;
            goto LABEL_39;
          }
        }
        if ( v7 < streambufsize )
          break;
        if ( streambufsize != 0 )
        {
          if ( v7 <= 0x7FFFFFFF )
          {
            v10 = v7 % streambufsize;
            v11 = v7;
          }
          else
          {
            v10 = 0x7FFFFFFF % streambufsize;
            v11 = 0x7FFFFFFF;
          }
          v12 = v11 - v10;
        }
        else
        {
          v12 = 0x7FFFFFFF;
          if ( v7 <= 0x7FFFFFFF )
            v12 = v7;
        }
        if ( v12 > dataSize )
          goto LABEL_41;
        v17 = v12;
        v13 = _fileno(stream);
        v14 = _read(fh: v13, buf: data, cnt: v17);
        if ( v14 == 0 )
        {
          stream->_flag |= 0x10u;
          return (v6 - v7) / elementSize;
        }
        if ( v14 == -1 )
        {
LABEL_44:
          stream->_flag |= 0x20u;
          return (v6 - v7) / elementSize;
        }
        data += v14;
        v7 -= v14;
        dataSize -= v14;
LABEL_39:
        if ( v7 == 0 )
          return num;
      }
      v15 = _filbuf(str: stream);
      if ( v15 == -1 )
        return (v6 - v7) / elementSize;
      if ( dataSize != 0 )
      {
        v16 = data++;
        *v16 = v15;
        --v7;
        --dataSize;
        streambufsize = stream->_bufsiz;
        goto LABEL_39;
      }
LABEL_41:
      if ( bufferSize != -1 )
        memset(dst: buffer, value: 0, count: bufferSize);
      *_errno() = 34;
LABEL_5:
      _invalid_parameter_noinfo();
      return 0;
    }
  }
  *_errno() = 22;
  goto LABEL_5;
}

//------------------------------------------------------------------------------
// Address: 0x004CFBE2
// Name: _fread_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread_s(
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( elementSize == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    if ( bufferSize != -1 )
      memset(dst: buffer, value: 0, count: bufferSize);
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fread_nolock_s(buffer, bufferSize, elementSize, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004CFC70
// Name: _fread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread(unsigned __int8 *buffer, unsigned int elementSize, unsigned int count, _iobuf *stream)
{
  return fread_s(buffer, bufferSize: 0xFFFFFFFF, elementSize, count, stream);
}

//------------------------------------------------------------------------------
// Address: 0x004CFC8D
// Name: __ftell_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ftell_nolock(_iobuf *str)
{
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int flag; // edx
  char *ptr; // eax
  char *base; // ecx
  char *v9; // ebx
  char *v10; // edx
  int cnt; // edx
  ioinfo **v12; // ebx
  int v13; // esi
  char *v14; // eax
  char *v15; // ecx
  bool v16; // zf
  int bufsiz; // eax
  int v18; // ecx
  unsigned int offset; // [esp+8h] [ebp-Ch]
  int fd; // [esp+Ch] [ebp-8h]
  int filepos; // [esp+10h] [ebp-4h]
  unsigned int rdcnt; // [esp+1Ch] [ebp+8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v3 = _fileno(stream: str);
  v4 = v3;
  fd = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v5 = _lseek(fh: v3, pos: 0, mthd: 1);
  filepos = v5;
  if ( v5 < 0 )
    return -1;
  flag = str->_flag;
  if ( (flag & 0x108) == 0 )
    return v5 - str->_cnt;
  ptr = str->_ptr;
  base = str->_base;
  v9 = (char *)(str->_ptr - base);
  offset = (unsigned int)v9;
  if ( (flag & 3) != 0 )
  {
    if ( __pioinfo[v4 >> 5][v4 & 0x1F].osfile < 0 )
    {
      v10 = str->_base;
      if ( base < ptr )
      {
        do
        {
          if ( *v10 == 10 )
            ++v9;
          ++v10;
        }
        while ( v10 < ptr );
        offset = (unsigned int)v9;
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
  if ( filepos == 0 )
    return (int)v9;
  if ( (str->_flag & 1) == 0 )
    return filepos + offset;
  cnt = str->_cnt;
  if ( cnt != 0 )
  {
    v12 = &__pioinfo[fd >> 5];
    rdcnt = cnt + ptr - base;
    v13 = (fd & 0x1F) << 6;
    if ( *(&(*v12)->osfile + v13) >= 0 )
    {
LABEL_39:
      filepos -= rdcnt;
      return filepos + offset;
    }
    if ( _lseek(fh: fd, pos: 0, mthd: 2) == filepos )
    {
      v14 = str->_base;
      v15 = &v14[rdcnt];
      while ( v14 < v15 )
      {
        if ( *v14 == 10 )
          ++rdcnt;
        ++v14;
      }
      v16 = (str->_flag & 0x2000) == 0;
LABEL_37:
      if ( !v16 )
        ++rdcnt;
      goto LABEL_39;
    }
    if ( _lseek(fh: fd, pos: filepos, mthd: 0) >= 0 )
    {
      bufsiz = 512;
      if ( rdcnt > 0x200 || ((v18 = str->_flag) & 8) == 0 || (v18 & 0x400) != 0 )
        bufsiz = str->_bufsiz;
      rdcnt = bufsiz;
      v16 = (*(&(*v12)->osfile + v13) & 4) == 0;
      goto LABEL_37;
    }
    return -1;
  }
  offset = 0;
  return filepos + offset;
}

//------------------------------------------------------------------------------
// Address: 0x004CFE21
// Name: _ftell
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ftell(_iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ftell_nolock(str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFE86
// Name: __fseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseek_nolock(_iobuf *str, int offset, int whence)
{
  int flag; // eax
  int v5; // eax
  int v6; // eax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftell_nolock(str);
      whence = 0;
    }
    _flush(str);
    v5 = str->_flag;
    if ( (v5 & 0x80u) == 0 )
    {
      if ( (v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v5 & 0xFFFFFFFC;
    }
    v6 = _fileno(stream: str);
    return (_lseek(fh: v6, pos: offset, mthd: whence) != -1) - 1;
  }
  else
  {
    *_errno() = 22;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFF10
// Name: _fseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fseek(_iobuf *stream, int offset, unsigned int whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr && whence <= 2 )
  {
    _lock_file(pf: stream);
    retval = _fseek_nolock(str: stream, offset, whence);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFF8C
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( file == nullptr || mode == nullptr || *mode == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  v5 = _getstream();
  stream = v5;
  if ( v5 == nullptr )
  {
    *_errno() = 24;
    return nullptr;
  }
  ms_exc.registration.TryLevel = 0;
  if ( LOBYTE(file->_ptr) == 0 )
  {
    *_errno() = 22;
    _local_unwind4(a1: &__security_cookie, a2: &ms_exc.registration, a3: -2);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004D0048
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x004D0060
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _alloca_probe_16()
{
  return _chkstk();
}

//------------------------------------------------------------------------------
// Address: 0x004D008C
// Name: __chdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chdir(const char *path)
{
  char *v1; // esi
  signed int CurrentDirectoryA; // eax
  DWORD v4; // edi
  unsigned __int8 *v5; // eax
  char v6; // al
  DWORD LastError; // eax
  int memfree; // [esp+4h] [ebp-118h]
  int retval; // [esp+8h] [ebp-114h]
  char env_var[4]; // [esp+Ch] [ebp-110h] BYREF
  char abspath[264]; // [esp+10h] [ebp-10Ch] BYREF

  memfree = 0;
  retval = -1;
  v1 = abspath;
  if ( path == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( !SetCurrentDirectoryA(lpPathName: path) )
    goto LABEL_14;
  CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: 0x105u, lpBuffer: abspath);
  v4 = CurrentDirectoryA;
  if ( CurrentDirectoryA > 260 )
  {
    v5 = calloc(count: CurrentDirectoryA + 1, size: 1u);
    v1 = (char *)v5;
    if ( v5 == nullptr || (memfree = 1, v4 == 0) )
    {
LABEL_14:
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      goto LABEL_15;
    }
    v4 = GetCurrentDirectoryA(nBufferLength: v4 + 1, lpBuffer: (LPSTR)v5);
  }
  if ( v4 == 0 )
    goto LABEL_14;
  if ( (v6 = *v1, *v1 != 92) && v6 != 47 || v6 != v1[1] )
  {
    env_var[0] = 61;
    env_var[1] = _mbctoupper(c: (unsigned __int8)*v1);
    strcpy(&env_var[2], ":");
    if ( !SetEnvironmentVariableA(lpName: env_var, lpValue: v1) )
      goto LABEL_14;
  }
  retval = 0;
LABEL_15:
  if ( memfree != 0 )
    free(pMem: v1);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004D01B5
// Name: ___libm_sse2_sin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_sin@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(X, 3) & 0x7FF0) != 0x7FF0 )
    return sin(X: *(double *)X.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D0370
// Name: _acos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl acos(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x7F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x4DAE28);
  }
  JUMPOUT(0x4D03FF);
}

//------------------------------------------------------------------------------
// Address: 0x004D03B0
// Name: __CIacos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIacos(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIacos;
  v2 = _mm_getcsr() & 0x7F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIacos_pentium4(a1);
  else
__CIacos:
    _CIacos_default(a1, a2: HIDWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x004D03EB
// Name: __CIacos_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004D04B6
// Name: ___libm_sse2_acos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_acos()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004D0959
// Name: ___libm_sse2_atan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_atan2()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004D0E6F
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // eax
  _tiddata *ptd; // eax

  this->updated = false;
  if ( plocinfo != nullptr )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = _getptd();
    this->ptd = v3;
    this->localeinfo.locinfo = v3->ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( this->localeinfo.locinfo != __ptlocinfo && (__globallocalestatus & v3->_ownlocale) == 0 )
      this->localeinfo.locinfo = __updatetlocinfo();
    if ( this->localeinfo.mbcinfo != __ptmbcinfo && (__globallocalestatus & this->ptd->_ownlocale) == 0 )
      this->localeinfo.mbcinfo = __updatetmbcinfo();
    ptd = this->ptd;
    if ( (ptd->_ownlocale & 2) == 0 )
    {
      ptd->_ownlocale |= 2u;
      this->updated = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D0EF6
// Name: __atof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _atof_l(const char *nptr, localeinfo_struct *plocinfo)
{
  const char *v2; // esi
  long double result; // st7
  int v4; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-2Ch] BYREF
  _flt fltstruct; // [esp+14h] [ebp-1Ch] BYREF

  v2 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( nptr != nullptr )
  {
    while ( 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
         ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v2] & 8
         : _isctype_l(c: *(unsigned __int8 *)v2, mask: 8, plocinfo: &_loc_update.localeinfo);
      if ( v4 == 0 )
        break;
      ++v2;
    }
    result = _fltin2(flt: &fltstruct, str: v2, _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D0FA1
// Name: _atof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl atof(const char *nptr)
{
  return _atof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004D0FB4
// Name: _strtok
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strtok(char *string, const char *control)
{
  char v3; // dl
  char *token; // edx
  char *v5; // ebx
  _tiddata *ptd; // [esp+10h] [ebp-28h]
  unsigned __int8 map[32]; // [esp+14h] [ebp-24h] BYREF

  ptd = _getptd();
  memset(map, 0, sizeof(map));
  do
  {
    v3 = *control;
    map[*(unsigned __int8 *)control >> 3] |= 1 << (*control & 7);
    ++control;
  }
  while ( v3 != 0 );
  token = string;
  if ( string == nullptr )
    token = ptd->_token;
  while ( ((unsigned __int8)(1 << (*token & 7)) & map[(unsigned __int8)*token >> 3]) != 0 && *token != 0 )
    ++token;
  v5 = token;
  while ( *token != 0 )
  {
    if ( ((unsigned __int8)(1 << (*token & 7)) & map[(unsigned __int8)*token >> 3]) != 0 )
    {
      *token++ = 0;
      break;
    }
    ++token;
  }
  ptd->_token = token;
  return token != v5 ? v5 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D1071
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x004D1087
// Name: _atoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atoi(const char *nptr)
{
  return atol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x004D10A0
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( count == 0 )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 != 0 )
      goto main_loop_entrance;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return;
    }
    while ( --v4 != 0 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( --v3 == 0 )
      return;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( --v3 == 0 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( v9 == 0 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        break;
      if ( BYTE1(v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int8)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF0000) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int16)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)dest = v11;
        goto fill_with_EOS_dwords;
      }
    }
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( --v7 == 0 )
      goto tail_loop_start;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 != 0 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop;
}

//------------------------------------------------------------------------------
// Address: 0x004D11C4
// Name: __get_sys_err_msg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _get_sys_err_msg(int m)
{
  int v1; // esi

  v1 = m;
  if ( m < 0 || m >= *__sys_nerr() )
    v1 = *__sys_nerr();
  return __sys_errlist()[v1];
}

//------------------------------------------------------------------------------
// Address: 0x004D11EC
// Name: _strerror
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strerror(int errnum)
{
  _tiddata *v1; // eax
  _tiddata *v2; // esi
  unsigned __int8 *v4; // eax
  char *errmsg; // esi
  char *sys_err_msg; // eax

  v1 = _getptd_noexit();
  v2 = v1;
  if ( v1 == nullptr )
    return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  if ( v1->_errmsg == nullptr )
  {
    v4 = calloc(count: 0x86u, size: 1u);
    v2->_errmsg = (char *)v4;
    if ( v4 == nullptr )
      return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  }
  errmsg = v2->_errmsg;
  sys_err_msg = _get_sys_err_msg(m: errnum);
  if ( strcpy_s(_Dst: errmsg, _SizeInBytes: 0x86u, _Src: sys_err_msg) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return errmsg;
}

//------------------------------------------------------------------------------
// Address: 0x004D1256
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_errno_from_oserr(unsigned int oserrno)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( oserrno == errtable[i].oscode )
      return errtable[i].errnocode;
  }
  if ( oserrno - 19 > 0x11 )
    return oserrno - 188 > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x004D1298
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x004D12AB
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __doserrno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x004D12BE
// Name: __dosmaperr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _dosmaperr(unsigned int oserrno)
{
  int errno_from_oserr; // esi

  *__doserrno() = oserrno;
  errno_from_oserr = _get_errno_from_oserr(oserrno);
  *_errno() = errno_from_oserr;
}

//------------------------------------------------------------------------------
// Address: 0x004D12E1
// Name: __mkdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mkdir(const char *path)
{
  DWORD LastError; // eax

  if ( CreateDirectoryA(lpPathName: path, lpSecurityAttributes: nullptr) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004D1313
// Name: __tempnam
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _tempnam(char *dir, char *pfx)
{
  char *result; // eax
  int v3; // eax
  char *v4; // edi
  unsigned int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v8; // esi
  int v9; // eax
  int v10; // eax
  char *v11; // edi
  int v12; // ebx
  const unsigned __int8 *first; // [esp+14h] [ebp-2Ch]
  unsigned int firsta; // [esp+14h] [ebp-2Ch]
  unsigned int pfxlength; // [esp+1Ch] [ebp-24h]
  char *envbuf; // [esp+20h] [ebp-20h] BYREF
  unsigned int bufsz; // [esp+24h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+28h] [ebp-18h]

  pfxlength = 0;
  envbuf = nullptr;
  result = (char *)_mtinitlocknum(locknum: 2);
  if ( result == nullptr )
    return result;
  v3 = _dupenv_s(pBuffer: &envbuf, pBufferSizeInTChars: nullptr, varname: "TMP");
  if ( v3 != 0 )
  {
    if ( v3 == 22 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  else if ( envbuf != nullptr && _access_s(path: envbuf, amode: 0) == 0 )
  {
    v4 = envbuf;
LABEL_9:
    if ( pfx != nullptr )
    {
      strlen(buf: (unsigned __int8 *)pfx);
      pfxlength = v5;
    }
    strlen(buf: (unsigned __int8 *)v4);
    bufsz = v6 + pfxlength + 12;
    v7 = (char *)calloc(count: bufsz, size: 1u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      *v7 = 0;
      if ( strcat_s(_Dst: v7, _SizeInBytes: bufsz, _Src: v4) != 0 )
LABEL_39:
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      strlen(buf: (unsigned __int8 *)v4);
      first = (const unsigned __int8 *)&v4[v9 - 1];
      if ( *first == 92 )
      {
        if ( first != _mbsrchr(str: (const unsigned __int8 *)v4, c: 0x5Cu)
          && strcat_s(_Dst: v8, _SizeInBytes: bufsz, _Src: "\\") != 0 )
        {
LABEL_16:
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
        }
      }
      else if ( *first != 47 && strcat_s(_Dst: v8, _SizeInBytes: bufsz, _Src: "\\") != 0 )
      {
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      }
      if ( pfx != nullptr && strcat_s(_Dst: v8, _SizeInBytes: bufsz, _Src: pfx) != 0 )
        goto LABEL_16;
      strlen(buf: (unsigned __int8 *)v8);
      v11 = &v8[v10];
      _lock(locknum: 2);
      ms_exc.registration.TryLevel = 0;
      if ( _old_pfxlen < pfxlength )
        _tempoff = 1;
      _old_pfxlen = pfxlength;
      firsta = _tempoff;
      v12 = *_errno();
      do
      {
        if ( ++_tempoff - firsta > 0x7FFFFFFF )
        {
          *_errno() = v12;
          free(pMem: v8);
          v8 = nullptr;
          goto done1;
        }
        if ( _ultoa_s(val: _tempoff, buf: v11, sizeInTChars: (unsigned int)&v8[bufsz - (_DWORD)v11], radix: 10) != 0 )
          goto LABEL_39;
        *_errno() = 0;
      }
      while ( _access_s(path: v8, amode: 0) == 0 || *_errno() == 13 );
      *_errno() = v12;
done1:
      ms_exc.registration.TryLevel = -2;
      _unlock(locknum: 2);
    }
    free(pMem: envbuf);
    free(pMem: nullptr);
    return v8;
  }
  v4 = dir;
  if ( dir == nullptr || _access_s(path: dir, amode: 0) != 0 )
  {
    if ( _access_s(path: "\\", amode: 0) != 0 )
      v4 = ".";
    else
      v4 = "\\";
  }
  goto LABEL_9;
}

//------------------------------------------------------------------------------
// Address: 0x004D157E
// Name: __isdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 4;
  else
    result = _isctype_l(c, mask: 4, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D15CF
// Name: _isdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 4;
}

//------------------------------------------------------------------------------
// Address: 0x004D15FD
// Name: __isxdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isxdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x80;
  else
    result = _isctype_l(c, mask: 128, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D1653
// Name: _isxdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isxdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isxdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x80;
}

//------------------------------------------------------------------------------
// Address: 0x004D1683
// Name: __isspace_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isspace_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 8;
  else
    result = _isctype_l(c, mask: 8, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D16D4
// Name: _isspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isspace(int c)
{
  if ( __locale_changed != 0 )
    return _isspace_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 8;
}

//------------------------------------------------------------------------------
// Address: 0x004D1702
// Name: __ispunct_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ispunct_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x10;
  else
    result = _isctype_l(c, mask: 16, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D1753
// Name: _ispunct
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ispunct(int c)
{
  if ( __locale_changed != 0 )
    return _ispunct_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x004D1781
// Name: __isalnum_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isalnum_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x107;
  else
    result = _isctype_l(c, mask: 263, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D17D7
// Name: _isalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isalnum(int c)
{
  if ( __locale_changed != 0 )
    return _isalnum_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x107;
}

//------------------------------------------------------------------------------
// Address: 0x004D1807
// Name: __findclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findclose(void *hFile)
{
  if ( FindClose(hFindFile: hFile) )
    return 0;
  *_errno() = 22;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004D182D
// Name: ___time64_t_from_ft
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __time64_t_from_ft(_FILETIME *pft)
{
  _FILETIME lft; // [esp+0h] [ebp-1Ch] BYREF
  _SYSTEMTIME st; // [esp+8h] [ebp-14h] BYREF

  if ( (pft->dwLowDateTime != 0 || pft->dwHighDateTime != 0)
    && FileTimeToLocalFileTime(lpFileTime: pft, lpLocalFileTime: &lft)
    && FileTimeToSystemTime(lpFileTime: &lft, lpSystemTime: &st) )
  {
    return __loctotime64_t(
             yr: st.wYear,
             mo: st.wMonth,
             dy: st.wDay,
             hr: st.wHour,
             mn: st.wMinute,
             sc: st.wSecond,
             dstflag: 0);
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D18A9
// Name: __findfirst64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findfirst64i32(const char *szWild, _finddata64i32_t *pfd)
{
  HANDLE FirstFile; // ebx
  DWORD LastError; // eax
  int v5; // edx
  int v6; // edx
  int v7; // edx
  _WIN32_FIND_DATAA wfd; // [esp+8h] [ebp-144h] BYREF

  if ( pfd == nullptr || szWild == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  FirstFile = FindFirstFileExA(
                lpFileName: szWild,
                fInfoLevelId: FindExInfoStandard,
                lpFindFileData: &wfd,
                fSearchOp: FindExSearchNameMatch,
                lpSearchFilter: nullptr,
                dwAdditionalFlags: 0);
  if ( FirstFile == (HANDLE)-1 )
  {
    LastError = GetLastError();
    if ( LastError >= 2 )
    {
      if ( LastError <= 3 )
        goto LABEL_13;
      if ( LastError == 8 )
      {
        *_errno() = 12;
        return -1;
      }
      if ( LastError == 18 )
      {
LABEL_13:
        *_errno() = 2;
        return -1;
      }
    }
    *_errno() = 22;
    return -1;
  }
  pfd->attrib = wfd.dwFileAttributes != 128 ? wfd.dwFileAttributes : 0;
  LODWORD(pfd->time_create) = __time64_t_from_ft(pft: &wfd.ftCreationTime);
  HIDWORD(pfd->time_create) = v5;
  LODWORD(pfd->time_access) = __time64_t_from_ft(pft: &wfd.ftLastAccessTime);
  HIDWORD(pfd->time_access) = v6;
  LODWORD(pfd->time_write) = __time64_t_from_ft(pft: &wfd.ftLastWriteTime);
  pfd->size = wfd.nFileSizeLow;
  HIDWORD(pfd->time_write) = v7;
  if ( strcpy_s(_Dst: pfd->name, _SizeInBytes: 0x104u, _Src: wfd.cFileName) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return (int)FirstFile;
}

//------------------------------------------------------------------------------
// Address: 0x004D19D0
// Name: __findnext64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findnext64i32(void *hFile, _finddata64i32_t *pfd)
{
  int result; // eax
  DWORD LastError; // eax
  int v4; // edx
  int v5; // edx
  int v6; // edx
  _WIN32_FIND_DATAA wfd; // [esp+4h] [ebp-144h] BYREF

  if ( hFile == (void *)-1 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( pfd == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( !FindNextFileA(hFindFile: hFile, lpFindFileData: &wfd) )
  {
    LastError = GetLastError();
    if ( LastError >= 2 )
    {
      if ( LastError <= 3 )
        goto LABEL_14;
      if ( LastError == 8 )
      {
        *_errno() = 12;
        return -1;
      }
      if ( LastError == 18 )
      {
LABEL_14:
        *_errno() = 2;
        return -1;
      }
    }
    *_errno() = 22;
    return -1;
  }
  pfd->attrib = wfd.dwFileAttributes != 128 ? wfd.dwFileAttributes : 0;
  LODWORD(pfd->time_create) = __time64_t_from_ft(pft: &wfd.ftCreationTime);
  HIDWORD(pfd->time_create) = v4;
  LODWORD(pfd->time_access) = __time64_t_from_ft(pft: &wfd.ftLastAccessTime);
  HIDWORD(pfd->time_access) = v5;
  LODWORD(pfd->time_write) = __time64_t_from_ft(pft: &wfd.ftLastWriteTime);
  pfd->size = wfd.nFileSizeLow;
  HIDWORD(pfd->time_write) = v6;
  result = strcpy_s(_Dst: pfd->name, _SizeInBytes: 0x104u, _Src: wfd.cFileName);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D1AFE
// Name: _remove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl remove(const char *path)
{
  DWORD LastError; // eax

  if ( DeleteFileA(lpFileName: path) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004D1B2E
// Name: __unlink
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _unlink(const char *path)
{
  return remove(path);
}

//------------------------------------------------------------------------------
// Address: 0x004D1B39
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  unsigned __int8 v7; // bl
  const char *i; // edi
  int v9; // eax
  unsigned int v10; // eax
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  number = 0;
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v7 = i[1];
    i += 2;
  }
LABEL_32:
  v10 = 0xFFFFFFFF / ibase;
  pctype = locinfo->pctype;
  v16 = 0xFFFFFFFF % ibase;
  while ( 1 )
  {
    if ( (pctype[v7] & 4) != 0 )
    {
      v12 = (char)v7 - 48;
    }
    else
    {
      if ( (pctype[v7] & 0x103) == 0 )
        break;
      v13 = (char)v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v13 = (char)v7 - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v12 <= v16 )
    {
      number = v12 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v14 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v14 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v14;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x004D1D64
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004D1D8F
// Name: __strtod_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _strtod_l(char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  const char *v3; // esi
  int v5; // eax
  _flt *v6; // eax
  _flt *v7; // ecx
  int flags; // eax
  long double v9; // st7
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-34h] BYREF
  long double tmp; // [esp+1Ch] [ebp-24h]
  _flt answerstruct; // [esp+24h] [ebp-1Ch] BYREF

  v3 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  while ( 1 )
  {
    v5 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
       ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v3] & 8
       : _isctype_l(c: *(unsigned __int8 *)v3, mask: 8, plocinfo: &_loc_update.localeinfo);
    if ( v5 == 0 )
      break;
    ++v3;
  }
  v6 = _fltin2(flt: &answerstruct, str: v3, _Locale: &_loc_update.localeinfo);
  v7 = v6;
  if ( endptr != nullptr )
    *endptr = (char *)&v3[v6->nbytes];
  flags = v6->flags;
  if ( (v7->flags & 0x240) != 0 )
  {
    tmp = 0.0;
    if ( endptr != nullptr )
      *endptr = nptr;
    goto LABEL_24;
  }
  if ( (flags & 0x81) != 0 )
  {
    v9 = _HUGE;
    if ( *v3 == 45 )
      v9 = -_HUGE;
  }
  else if ( (flags & 0x100) == 0 || (v9 = 0.0, 0.0 != v7->dval) )
  {
    tmp = v7->dval;
    goto LABEL_24;
  }
  tmp = v9;
  *_errno() = 34;
LABEL_24:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x004D1EB2
// Name: _strtod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl strtod(char *nptr, char **endptr)
{
  return _strtod_l(nptr, endptr, plocinfo: nullptr);
}
