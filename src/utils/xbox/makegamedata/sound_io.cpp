// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/sound_io.cpp
// Functions: 6
// ============================================================

#include "utils\xbox\makegamedata\sound_io.h"

//------------------------------------------------------------------------------
// Address: 0x0041C000
// Name: public: virtual int COM_IOReadBinary::open(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COM_IOReadBinary::open(COM_IOReadBinary *this, const char *pFileName)
{
  int hFile; // [esp+0h] [ebp-4h] BYREF

  hFile = -1;
  _sopen_s(pfh: &hFile, path: pFileName, oflag: 0x8000, shflag: 32, pmode: 256);
  return hFile;
}

//------------------------------------------------------------------------------
// Address: 0x0041C030
// Name: public: virtual int COM_IOReadBinary::read(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COM_IOReadBinary::read(COM_IOReadBinary *this, void *pOutput, unsigned int size, int file)
{
  return _read(fh: file, buf: pOutput, cnt: size);
}

//------------------------------------------------------------------------------
// Address: 0x0041C050
// Name: public: virtual void COM_IOReadBinary::seek(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COM_IOReadBinary::seek(COM_IOReadBinary *this, int file, int pos)
{
  _lseek(fh: file, pos, mthd: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0041C070
// Name: public: virtual unsigned int COM_IOReadBinary::tell(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COM_IOReadBinary::tell(COM_IOReadBinary *this, int file)
{
  return _lseek(fh: file, pos: 0, mthd: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0041C090
// Name: public: virtual unsigned int COM_IOReadBinary::size(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COM_IOReadBinary::size(COM_IOReadBinary *this, int file)
{
  int v2; // edi
  int v3; // ebx

  v2 = _lseek(fh: file, pos: 0, mthd: 1);
  v3 = _lseek(fh: file, pos: 0, mthd: 2);
  _lseek(fh: file, pos: v2, mthd: 0);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0041C0D0
// Name: public: virtual void COM_IOReadBinary::close(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COM_IOReadBinary::close(COM_IOReadBinary *this, int file)
{
  _close(fh: file);
}
