// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/riff.cpp
// Functions: 9
// ============================================================

#include "tier2\riff.h"

//------------------------------------------------------------------------------
// Address: 0x1027A6E0
// Name: public: InFileRIFF::~InFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InFileRIFF::~InFileRIFF(InFileRIFF *this)
{
  this->m_io->close(this: this->m_io, a2: this->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x1027A6F0
// Name: private: void IterateRIFF::ChunkSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateRIFF::ChunkSetup(IterateRIFF *this)
{
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v3; // ecx
  int m_file; // [esp-4h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-4h] BYREF

  this->m_chunkPosition = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: this->m_riff->m_file);
  m_io = this->m_riff->m_io;
  m_file = this->m_riff->m_file;
  v6 = 0;
  m_io->read(this: m_io, a2: &v6, a3: 4, a4: m_file);
  this->m_chunkName = v6;
  v3 = this->m_riff->m_io;
  v5 = this->m_riff->m_file;
  v6 = 0;
  v3->read(this: v3, a2: &v6, a3: 4, a4: v5);
  this->m_chunkSize = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1027A760
// Name: public: bool IterateRIFF::ChunkAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkAvailable(IterateRIFF *this)
{
  int m_chunkSize; // eax

  m_chunkSize = this->m_chunkSize;
  return m_chunkSize != -1 && m_chunkSize < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x1027A780
// Name: public: bool IterateRIFF::ChunkNext(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkNext(IterateRIFF *this)
{
  int m_chunkSize; // eax
  int v3; // edx
  int v5; // esi

  m_chunkSize = this->m_chunkSize;
  if ( m_chunkSize == -1 || m_chunkSize >= 0x10000000 )
    return false;
  v3 = this->m_chunkPosition + (this->m_chunkSize & 1) + m_chunkSize + 8;
  if ( v3 >= this->m_start + this->m_size )
  {
    this->m_chunkSize = -1;
    return false;
  }
  this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: this->m_riff->m_file, a3: v3);
  IterateRIFF::ChunkSetup(this);
  v5 = this->m_chunkSize;
  return v5 != -1 && v5 < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x1027A7E0
// Name: public: int IterateRIFF::ChunkRead(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkRead(IterateRIFF *this, void *pOutput)
{
  return this->m_riff->m_io->read(
           this: this->m_riff->m_io,
           a2: pOutput,
           a3: this->m_chunkSize,
           a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x1027A800
// Name: public: int IterateRIFF::ChunkReadPartial(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkReadPartial(IterateRIFF *this, void *pOutput, int dataSize)
{
  return this->m_riff->m_io->read(this: this->m_riff->m_io, a2: pOutput, a3: dataSize, a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x1027A820
// Name: public: int IterateRIFF::ChunkReadInt(void)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::ChunkReadInt(IterateRIFF *this)
{
  InFileRIFF *m_riff; // eax
  IFileReadBinary *m_io; // ecx
  int m_file; // [esp-4h] [ebp-8h]
  IterateRIFF *v5; // [esp+0h] [ebp-4h] BYREF

  v5 = this;
  m_riff = this->m_riff;
  m_io = this->m_riff->m_io;
  m_file = m_riff->m_file;
  v5 = nullptr;
  m_io->read(this: m_io, a2: &v5, a3: 4, a4: m_file);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1027A850
// Name: public: InFileRIFF::InFileRIFF(char const __near *,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
InFileRIFF *__thiscall InFileRIFF::InFileRIFF(InFileRIFF *this, const char *pFileName, IFileReadBinary *io)
{
  IFileReadBinary *v4; // ecx
  int v5; // eax
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v8; // ecx
  int v9; // eax
  IFileReadBinary *v10; // ecx
  IFileReadBinary *v11; // ecx
  int m_file; // [esp-4h] [ebp-10h]

  v4 = io;
  this->m_io = io;
  v5 = v4->open(this: v4, a2: pFileName);
  this->m_file = v5;
  if ( v5 != 0 )
  {
    m_io = this->m_io;
    io = nullptr;
    m_io->read(this: m_io, a2: &io, a3: 4, a4: v5);
    if ( io == (IFileReadBinary *)1179011410 )
    {
      v8 = this->m_io;
      m_file = this->m_file;
      io = nullptr;
      v8->read(this: v8, a2: &io, a3: 4, a4: m_file);
      v9 = this->m_file;
      this->m_riffSize = (unsigned int)&io[-1];
      v10 = this->m_io;
      io = nullptr;
      v10->read(this: v10, a2: &io, a3: 4, a4: v9);
      v11 = this->m_io;
      this->m_riffName = (unsigned int)io;
      this->m_riffSize = v11->size(this: v11, a2: this->m_file) - 12;
    }
    else
    {
      printf(format: "Not a RIFF File [%s]\n", pFileName);
      this->m_riffSize = 0;
    }
    return this;
  }
  else
  {
    this->m_riffSize = 0;
    this->m_riffName = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027A910
// Name: public: IterateRIFF::IterateRIFF(class InFileRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::IterateRIFF(IterateRIFF *this, InFileRIFF *riff, int size)
{
  this->m_riff = riff;
  this->m_size = size;
  if ( riff->m_riffSize != 0 )
  {
    this->m_start = ((int (__stdcall *)(int))riff->m_io->tell)(a1: riff->m_file);
    IterateRIFF::ChunkSetup(this);
  }
  else
  {
    this->m_chunkSize = -1;
  }
  return this;
}

// ============================================================
// Overlay from choreogen (Missing functions)
// ============================================================
namespace choreogen {

//------------------------------------------------------------------------------
// Address: 0x004184D0
// Name: public: InFileRIFF::~InFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InFileRIFF::~InFileRIFF(InFileRIFF *this)
{
  this->m_io->close(this: this->m_io, a2: this->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x004184E0
// Name: private: void IterateRIFF::ChunkSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateRIFF::ChunkSetup(IterateRIFF *this)
{
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v3; // ecx
  int m_file; // [esp+14h] [ebp-Ch]
  int v5; // [esp+14h] [ebp-Ch]
  unsigned int v6; // [esp+1Ch] [ebp-4h] BYREF

  this->m_chunkPosition = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: this->m_riff->m_file);
  m_io = this->m_riff->m_io;
  m_file = this->m_riff->m_file;
  v6 = 0;
  m_io->read(this: m_io, a2: &v6, a3: 4, a4: m_file);
  this->m_chunkName = v6;
  v3 = this->m_riff->m_io;
  v5 = this->m_riff->m_file;
  v6 = 0;
  v3->read(this: v3, a2: &v6, a3: 4, a4: v5);
  this->m_chunkSize = v6;
}

//------------------------------------------------------------------------------
// Address: 0x00418550
// Name: public: bool IterateRIFF::ChunkAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkAvailable(IterateRIFF *this)
{
  int m_chunkSize; // eax

  m_chunkSize = this->m_chunkSize;
  return m_chunkSize != -1 && m_chunkSize < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x00418570
// Name: public: bool IterateRIFF::ChunkNext(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkNext(IterateRIFF *this)
{
  int m_chunkSize; // eax
  int v3; // edx
  int v5; // esi

  m_chunkSize = this->m_chunkSize;
  if ( m_chunkSize == -1 || m_chunkSize >= 0x10000000 )
    return false;
  v3 = this->m_chunkPosition + (this->m_chunkSize & 1) + m_chunkSize + 8;
  if ( v3 >= this->m_start + this->m_size )
  {
    this->m_chunkSize = -1;
    return false;
  }
  this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: this->m_riff->m_file, a3: v3);
  IterateRIFF::ChunkSetup(this);
  v5 = this->m_chunkSize;
  return v5 != -1 && v5 < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x004185D0
// Name: public: int IterateRIFF::ChunkRead(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkRead(IterateRIFF *this, void *pOutput)
{
  return this->m_riff->m_io->read(
           this: this->m_riff->m_io,
           a2: pOutput,
           a3: this->m_chunkSize,
           a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x004185F0
// Name: public: InFileRIFF::InFileRIFF(char const __near *,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
InFileRIFF *__thiscall InFileRIFF::InFileRIFF(InFileRIFF *this, const char *pFileName, IFileReadBinary *io)
{
  IFileReadBinary *v4; // ecx
  int v5; // eax
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v8; // ecx
  int v9; // eax
  IFileReadBinary *v10; // ecx
  IFileReadBinary *v11; // ecx
  int m_file; // [esp+10h] [ebp-10h]

  v4 = io;
  this->m_io = io;
  v5 = v4->open(this: v4, a2: pFileName);
  this->m_file = v5;
  if ( v5 != 0 )
  {
    m_io = this->m_io;
    io = nullptr;
    m_io->read(this: m_io, a2: &io, a3: 4, a4: v5);
    if ( io == (IFileReadBinary *)1179011410 )
    {
      v8 = this->m_io;
      m_file = this->m_file;
      io = nullptr;
      v8->read(this: v8, a2: &io, a3: 4, a4: m_file);
      v9 = this->m_file;
      this->m_riffSize = (unsigned int)&io[-1];
      v10 = this->m_io;
      io = nullptr;
      v10->read(this: v10, a2: &io, a3: 4, a4: v9);
      v11 = this->m_io;
      this->m_riffName = (unsigned int)io;
      this->m_riffSize = v11->size(this: v11, a2: this->m_file) - 12;
    }
    else
    {
      printf(format: "Not a RIFF File [%s]\n", pFileName);
      this->m_riffSize = 0;
    }
    return this;
  }
  else
  {
    this->m_riffSize = 0;
    this->m_riffName = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004186C0
// Name: public: IterateRIFF::IterateRIFF(class InFileRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::IterateRIFF(IterateRIFF *this, InFileRIFF *riff, int size)
{
  this->m_riff = riff;
  this->m_size = size;
  if ( riff->m_riffSize != 0 )
  {
    this->m_start = ((int (__stdcall *)(int))riff->m_io->tell)(a1: riff->m_file);
    IterateRIFF::ChunkSetup(this);
  }
  else
  {
    this->m_chunkSize = -1;
  }
  return this;
}

} // namespace choreogen

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1027A830
// Name: private: void IterateRIFF::ChunkSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateRIFF::ChunkSetup(IterateRIFF *this)
{
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v3; // ecx
  int m_file; // [esp-4h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-4h] BYREF

  this->m_chunkPosition = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: this->m_riff->m_file);
  m_io = this->m_riff->m_io;
  m_file = this->m_riff->m_file;
  v6 = 0;
  m_io->read(this: m_io, a2: &v6, a3: 4, a4: m_file);
  this->m_chunkName = v6;
  v3 = this->m_riff->m_io;
  v5 = this->m_riff->m_file;
  v6 = 0;
  v3->read(this: v3, a2: &v6, a3: 4, a4: v5);
  this->m_chunkSize = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1027A8A0
// Name: public: bool IterateRIFF::ChunkAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkAvailable(IterateRIFF *this)
{
  int m_chunkSize; // eax

  m_chunkSize = this->m_chunkSize;
  return m_chunkSize != -1 && m_chunkSize < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x1027A8C0
// Name: public: bool IterateRIFF::ChunkNext(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkNext(IterateRIFF *this)
{
  int m_chunkSize; // eax
  int v3; // edx
  int v5; // esi

  m_chunkSize = this->m_chunkSize;
  if ( m_chunkSize == -1 || m_chunkSize >= 0x10000000 )
    return false;
  v3 = this->m_chunkPosition + (this->m_chunkSize & 1) + m_chunkSize + 8;
  if ( v3 >= this->m_start + this->m_size )
  {
    this->m_chunkSize = -1;
    return false;
  }
  this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: this->m_riff->m_file, a3: v3);
  IterateRIFF::ChunkSetup(this);
  v5 = this->m_chunkSize;
  return v5 != -1 && v5 < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x1027A920
// Name: public: int IterateRIFF::ChunkRead(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkRead(IterateRIFF *this, void *pOutput)
{
  return this->m_riff->m_io->read(
           this: this->m_riff->m_io,
           a2: pOutput,
           a3: this->m_chunkSize,
           a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x1027A940
// Name: public: int IterateRIFF::ChunkReadPartial(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkReadPartial(IterateRIFF *this, void *pOutput, int dataSize)
{
  return this->m_riff->m_io->read(this: this->m_riff->m_io, a2: pOutput, a3: dataSize, a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x1027A960
// Name: public: int IterateRIFF::ChunkReadInt(void)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::ChunkReadInt(IterateRIFF *this)
{
  InFileRIFF *m_riff; // eax
  IFileReadBinary *m_io; // ecx
  int m_file; // [esp-4h] [ebp-8h]
  IterateRIFF *v5; // [esp+0h] [ebp-4h] BYREF

  v5 = this;
  m_riff = this->m_riff;
  m_io = this->m_riff->m_io;
  m_file = m_riff->m_file;
  v5 = nullptr;
  m_io->read(this: m_io, a2: &v5, a3: 4, a4: m_file);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1027A990
// Name: public: InFileRIFF::InFileRIFF(char const __near *,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
InFileRIFF *__thiscall InFileRIFF::InFileRIFF(InFileRIFF *this, const char *pFileName, IFileReadBinary *io)
{
  IFileReadBinary *v4; // ecx
  int v5; // eax
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v8; // ecx
  int v9; // eax
  IFileReadBinary *v10; // ecx
  IFileReadBinary *v11; // ecx
  int m_file; // [esp-4h] [ebp-10h]

  v4 = io;
  this->m_io = io;
  v5 = v4->open(this: v4, a2: pFileName);
  this->m_file = v5;
  if ( v5 != 0 )
  {
    m_io = this->m_io;
    io = nullptr;
    m_io->read(this: m_io, a2: &io, a3: 4, a4: v5);
    if ( io == (IFileReadBinary *)1179011410 )
    {
      v8 = this->m_io;
      m_file = this->m_file;
      io = nullptr;
      v8->read(this: v8, a2: &io, a3: 4, a4: m_file);
      v9 = this->m_file;
      this->m_riffSize = (unsigned int)&io[-1];
      v10 = this->m_io;
      io = nullptr;
      v10->read(this: v10, a2: &io, a3: 4, a4: v9);
      v11 = this->m_io;
      this->m_riffName = (unsigned int)io;
      this->m_riffSize = v11->size(this: v11, a2: this->m_file) - 12;
    }
    else
    {
      printf(format: "Not a RIFF File [%s]\n", pFileName);
      this->m_riffSize = 0;
    }
    return this;
  }
  else
  {
    this->m_riffSize = 0;
    this->m_riffName = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027AA50
// Name: public: IterateRIFF::IterateRIFF(class InFileRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::IterateRIFF(IterateRIFF *this, InFileRIFF *riff, int size)
{
  this->m_riff = riff;
  this->m_size = size;
  if ( riff->m_riffSize != 0 )
  {
    this->m_start = ((int (__stdcall *)(int))riff->m_io->tell)(a1: riff->m_file);
    IterateRIFF::ChunkSetup(this);
  }
  else
  {
    this->m_chunkSize = -1;
  }
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004CD1E0
// Name: public: InFileRIFF::~InFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InFileRIFF::~InFileRIFF(InFileRIFF *this)
{
  this->m_io->close(this: this->m_io, a2: this->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x004CD1F0
// Name: private: void IterateRIFF::ChunkSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateRIFF::ChunkSetup(IterateRIFF *this)
{
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v3; // ecx
  int m_file; // [esp-4h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-4h] BYREF

  this->m_chunkPosition = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: this->m_riff->m_file);
  m_io = this->m_riff->m_io;
  m_file = this->m_riff->m_file;
  v6 = 0;
  m_io->read(this: m_io, a2: &v6, a3: 4, a4: m_file);
  this->m_chunkName = v6;
  v3 = this->m_riff->m_io;
  v5 = this->m_riff->m_file;
  v6 = 0;
  v3->read(this: v3, a2: &v6, a3: 4, a4: v5);
  this->m_chunkSize = v6;
}

//------------------------------------------------------------------------------
// Address: 0x004CD260
// Name: public: bool IterateRIFF::ChunkAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkAvailable(IterateRIFF *this)
{
  int m_chunkSize; // eax

  m_chunkSize = this->m_chunkSize;
  return m_chunkSize != -1 && m_chunkSize < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x004CD280
// Name: public: bool IterateRIFF::ChunkNext(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkNext(IterateRIFF *this)
{
  int m_chunkSize; // eax
  int v3; // edx
  int v5; // esi

  m_chunkSize = this->m_chunkSize;
  if ( m_chunkSize == -1 || m_chunkSize >= 0x10000000 )
    return false;
  v3 = this->m_chunkPosition + (this->m_chunkSize & 1) + m_chunkSize + 8;
  if ( v3 >= this->m_start + this->m_size )
  {
    this->m_chunkSize = -1;
    return false;
  }
  this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: this->m_riff->m_file, a3: v3);
  IterateRIFF::ChunkSetup(this);
  v5 = this->m_chunkSize;
  return v5 != -1 && v5 < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x004CD2E0
// Name: public: int IterateRIFF::ChunkRead(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkRead(IterateRIFF *this, void *pOutput)
{
  return this->m_riff->m_io->read(
           this: this->m_riff->m_io,
           a2: pOutput,
           a3: this->m_chunkSize,
           a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x004CD300
// Name: public: int IterateRIFF::ChunkReadPartial(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkReadPartial(IterateRIFF *this, void *pOutput, int dataSize)
{
  return this->m_riff->m_io->read(this: this->m_riff->m_io, a2: pOutput, a3: dataSize, a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x004CD320
// Name: public: int IterateRIFF::ChunkReadInt(void)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::ChunkReadInt(IterateRIFF *this)
{
  InFileRIFF *m_riff; // eax
  IFileReadBinary *m_io; // ecx
  int m_file; // [esp-4h] [ebp-8h]
  IterateRIFF *v5; // [esp+0h] [ebp-4h] BYREF

  v5 = this;
  m_riff = this->m_riff;
  m_io = this->m_riff->m_io;
  m_file = m_riff->m_file;
  v5 = nullptr;
  m_io->read(this: m_io, a2: &v5, a3: 4, a4: m_file);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004CD350
// Name: public: IterateOutputRIFF::IterateOutputRIFF(class OutFileRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
IterateOutputRIFF *__thiscall IterateOutputRIFF::IterateOutputRIFF(IterateOutputRIFF *this, OutFileRIFF *riff)
{
  int m_file; // edx
  int v4; // eax

  this->m_riff = riff;
  m_file = riff->m_file;
  if ( m_file != 0 )
  {
    v4 = riff->m_io->tell(this: riff->m_io, a2: m_file);
    this->m_start = v4;
    this->m_chunkPosition = v4;
    this->m_chunkStart = -1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CD380
// Name: public: void IterateOutputRIFF::ChunkWrite(unsigned int,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkWrite(IterateOutputRIFF *this, unsigned int chunkname, void *pOutput, int size)
{
  int m_file; // edx
  int v6; // eax
  int v7; // edi
  unsigned int v8; // eax
  OutFileRIFF *m_riff; // eax
  int v10; // edx
  OutFileRIFF *v11; // eax
  int v12; // edx
  unsigned int v13; // eax
  int v14; // eax
  OutFileRIFF *v15; // ecx
  int v16; // edx

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    v6 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    v6 = 0;
  v7 = size;
  this->m_chunkPosition = v6;
  v8 = chunkname;
  this->m_chunkName = chunkname;
  chunkname = v8;
  m_riff = this->m_riff;
  this->m_chunkSize = v7;
  v10 = m_riff->m_file;
  if ( v10 != 0 )
    m_riff->m_io->write(this: m_riff->m_io, a2: &chunkname, a3: 4, a4: v10);
  v11 = this->m_riff;
  chunkname = v7;
  v12 = v11->m_file;
  if ( v12 != 0 )
    v11->m_io->write(this: v11->m_io, a2: &chunkname, a3: 4, a4: v12);
  if ( this->m_riff->m_file != 0 )
    this->m_riff->m_io->write(this: this->m_riff->m_io, a2: pOutput, a3: v7, a4: this->m_riff->m_file);
  if ( this->m_riff->m_file != 0 )
    v13 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: this->m_riff->m_file);
  else
    v13 = 0;
  v14 = (v13 & 1) + v13;
  v15 = this->m_riff;
  this->m_chunkPosition = v14;
  v16 = v15->m_file;
  if ( v16 != 0 )
    v15->m_io->seek(this: v15->m_io, a2: v16, a3: v14);
  this->m_chunkStart = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004CD450
// Name: public: void IterateOutputRIFF::ChunkWriteData(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkWriteData(IterateOutputRIFF *this, void *pOutput, int size)
{
  int m_file; // edx

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    this->m_riff->m_io->write(this: this->m_riff->m_io, a2: pOutput, a3: size, a4: m_file);
}

//------------------------------------------------------------------------------
// Address: 0x004CD480
// Name: public: void IterateOutputRIFF::ChunkFinish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkFinish(IterateOutputRIFF *this)
{
  int m_file; // edx
  unsigned int v3; // eax
  int m_chunkStart; // edx
  int v5; // ecx
  unsigned int v6; // edi
  OutFileRIFF *m_riff; // eax
  int v8; // ebx
  int v9; // edi
  OutFileRIFF *v10; // eax
  int v11; // edx
  int v12; // edx
  int v13; // [esp+8h] [ebp-4h] BYREF

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    v3 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    v3 = 0;
  m_chunkStart = this->m_chunkStart;
  v5 = v3 + (v3 & 1);
  v6 = v3;
  m_riff = this->m_riff;
  this->m_chunkPosition = v5;
  v8 = m_riff->m_file;
  v9 = v6 - m_chunkStart - 8;
  if ( v8 != 0 )
    m_riff->m_io->seek(this: m_riff->m_io, a2: v8, a3: m_chunkStart + 4);
  v10 = this->m_riff;
  v13 = v9;
  v11 = v10->m_file;
  if ( v11 != 0 )
    v10->m_io->write(this: v10->m_io, a2: &v13, a3: 4, a4: v11);
  v12 = this->m_riff->m_file;
  if ( v12 != 0 )
    this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: v12, a3: this->m_chunkPosition);
  this->m_chunkStart = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004CD510
// Name: public: void IterateOutputRIFF::ChunkStart(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkStart(IterateOutputRIFF *this, unsigned int chunkname)
{
  int m_file; // edx
  int v4; // eax
  int v5; // edx
  OutFileRIFF *m_riff; // esi

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    v4 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    v4 = 0;
  this->m_chunkStart = v4;
  v5 = this->m_riff->m_file;
  if ( v5 != 0 )
    this->m_riff->m_io->write(this: this->m_riff->m_io, a2: &chunkname, a3: 4, a4: v5);
  m_riff = this->m_riff;
  chunkname = 0;
  if ( m_riff->m_file != 0 )
    m_riff->m_io->write(this: m_riff->m_io, a2: &chunkname, a3: 4, a4: m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x004CD580
// Name: public: unsigned int IterateOutputRIFF::ChunkGetPosition(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall IterateOutputRIFF::ChunkGetPosition(IterateOutputRIFF *this)
{
  int m_file; // edx

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    return this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CD5A0
// Name: public: void IterateOutputRIFF::CopyChunkData(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::CopyChunkData(IterateOutputRIFF *this, IterateRIFF *input)
{
  unsigned int m_chunkSize; // eax
  void *v4; // edi
  int m_file; // edx

  m_chunkSize = input->m_chunkSize;
  if ( m_chunkSize != 0 )
  {
    v4 = operator new(nSize: m_chunkSize);
    input->m_riff->m_io->read(this: input->m_riff->m_io, a2: v4, a3: input->m_chunkSize, a4: input->m_riff->m_file);
    m_file = this->m_riff->m_file;
    if ( m_file != 0 )
      this->m_riff->m_io->write(this: this->m_riff->m_io, a2: v4, a3: input->m_chunkSize, a4: m_file);
    free(pMem: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD600
// Name: public: InFileRIFF::InFileRIFF(char const __near *,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
InFileRIFF *__thiscall InFileRIFF::InFileRIFF(InFileRIFF *this, const char *pFileName, IFileReadBinary *io)
{
  IFileReadBinary *v4; // ecx
  int v5; // eax
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v8; // ecx
  int v9; // eax
  IFileReadBinary *v10; // ecx
  IFileReadBinary *v11; // ecx
  int m_file; // [esp-4h] [ebp-10h]

  v4 = io;
  this->m_io = io;
  v5 = v4->open(this: v4, a2: pFileName);
  this->m_file = v5;
  if ( v5 != 0 )
  {
    m_io = this->m_io;
    io = nullptr;
    m_io->read(this: m_io, a2: &io, a3: 4, a4: v5);
    if ( io == (IFileReadBinary *)1179011410 )
    {
      v8 = this->m_io;
      m_file = this->m_file;
      io = nullptr;
      v8->read(this: v8, a2: &io, a3: 4, a4: m_file);
      v9 = this->m_file;
      this->m_riffSize = (unsigned int)&io[-1];
      v10 = this->m_io;
      io = nullptr;
      v10->read(this: v10, a2: &io, a3: 4, a4: v9);
      v11 = this->m_io;
      this->m_riffName = (unsigned int)io;
      this->m_riffSize = v11->size(this: v11, a2: this->m_file) - 12;
    }
    else
    {
      printf(format: "Not a RIFF File [%s]\n", pFileName);
      this->m_riffSize = 0;
    }
    return this;
  }
  else
  {
    this->m_riffSize = 0;
    this->m_riffName = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD6C0
// Name: public: OutFileRIFF::OutFileRIFF(char const __near *,class IFileWriteBinary __near &)
// Source: json
//------------------------------------------------------------------------------
OutFileRIFF *__thiscall OutFileRIFF::OutFileRIFF(OutFileRIFF *this, int pFileName, int io)
{
  const char *v3; // edx
  int (__thiscall ***v5)(_DWORD, const char *); // ecx
  int v6; // eax
  IFileWriteBinary *m_io; // ecx
  IFileWriteBinary *v8; // ecx
  int m_file; // edx
  int v10; // eax
  int v11; // eax

  v3 = (const char *)pFileName;
  v5 = (int (__thiscall ***)(_DWORD, const char *))io;
  this->m_io = (IFileWriteBinary *)io;
  v6 = (**v5)(a1: v5, a2: v3);
  this->m_file = v6;
  if ( v6 != 0 )
  {
    m_io = this->m_io;
    io = 1179011410;
    m_io->write(this: m_io, a2: &io, a3: 4, a4: v6);
    v8 = this->m_io;
    m_file = this->m_file;
    this->m_riffSize = 0;
    this->m_nNamePos = v8->tell(this: v8, a2: m_file);
    v10 = this->m_file;
    pFileName = 0;
    if ( v10 != 0 )
      this->m_io->write(this: this->m_io, a2: &pFileName, a3: 4, a4: v10);
    v11 = this->m_file;
    pFileName = 1163280727;
    if ( v11 != 0 )
      this->m_io->write(this: this->m_io, a2: &pFileName, a3: 4, a4: v11);
    this->m_bUseIncorrectLISETLength = false;
    this->m_nLISETSize = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CD750
// Name: public: OutFileRIFF::~OutFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OutFileRIFF::~OutFileRIFF(OutFileRIFF *this)
{
  int m_file; // eax
  int v3; // edi
  int v4; // eax
  int v5; // [esp+4h] [ebp-4h] BYREF

  m_file = this->m_file;
  if ( m_file != 0 )
  {
    v3 = ((int (__stdcall *)(int))this->m_io->tell)(a1: m_file) - 8;
    this->m_io->seek(this: this->m_io, a2: this->m_file, a3: this->m_nNamePos);
    if ( this->m_bUseIncorrectLISETLength )
      v3 = this->m_nLISETSize - 8;
    v4 = this->m_file;
    v5 = v3;
    if ( v4 != 0 )
      this->m_io->write(this: this->m_io, a2: &v5, a3: 4, a4: v4);
    this->m_io->close(this: this->m_io, a2: this->m_file);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD7C0
// Name: public: IterateRIFF::IterateRIFF(class InFileRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::IterateRIFF(IterateRIFF *this, InFileRIFF *riff, int size)
{
  this->m_riff = riff;
  this->m_size = size;
  if ( riff->m_riffSize != 0 )
  {
    this->m_start = ((int (__stdcall *)(int))riff->m_io->tell)(a1: riff->m_file);
    IterateRIFF::ChunkSetup(this);
  }
  else
  {
    this->m_chunkSize = -1;
  }
  return this;
}

} // namespace hlfaceposer

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x0042B5E0
// Name: public: InFileRIFF::~InFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InFileRIFF::~InFileRIFF(InFileRIFF *this)
{
  this->m_io->close(this: this->m_io, a2: this->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x0042B5F0
// Name: private: void IterateRIFF::ChunkSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateRIFF::ChunkSetup(IterateRIFF *this)
{
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v3; // ecx
  int m_file; // [esp-4h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-4h] BYREF

  this->m_chunkPosition = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: this->m_riff->m_file);
  m_io = this->m_riff->m_io;
  m_file = this->m_riff->m_file;
  v6 = 0;
  m_io->read(this: m_io, a2: &v6, a3: 4, a4: m_file);
  this->m_chunkName = v6;
  v3 = this->m_riff->m_io;
  v5 = this->m_riff->m_file;
  v6 = 0;
  v3->read(this: v3, a2: &v6, a3: 4, a4: v5);
  this->m_chunkSize = v6;
}

//------------------------------------------------------------------------------
// Address: 0x0042B660
// Name: public: bool IterateRIFF::ChunkAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkAvailable(IterateRIFF *this)
{
  int m_chunkSize; // eax

  m_chunkSize = this->m_chunkSize;
  return m_chunkSize != -1 && m_chunkSize < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x0042B680
// Name: public: bool IterateRIFF::ChunkNext(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkNext(IterateRIFF *this)
{
  int m_chunkSize; // eax
  int v3; // edx
  int v5; // esi

  m_chunkSize = this->m_chunkSize;
  if ( m_chunkSize == -1 || m_chunkSize >= 0x10000000 )
    return false;
  v3 = this->m_chunkPosition + (this->m_chunkSize & 1) + m_chunkSize + 8;
  if ( v3 >= this->m_start + this->m_size )
  {
    this->m_chunkSize = -1;
    return false;
  }
  this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: this->m_riff->m_file, a3: v3);
  IterateRIFF::ChunkSetup(this);
  v5 = this->m_chunkSize;
  return v5 != -1 && v5 < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x0042B6E0
// Name: public: int IterateRIFF::ChunkRead(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkRead(IterateRIFF *this, void *pOutput)
{
  return this->m_riff->m_io->read(
           this: this->m_riff->m_io,
           a2: pOutput,
           a3: this->m_chunkSize,
           a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x0042B700
// Name: public: int IterateRIFF::ChunkReadPartial(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkReadPartial(IterateRIFF *this, void *pOutput, int dataSize)
{
  return this->m_riff->m_io->read(this: this->m_riff->m_io, a2: pOutput, a3: dataSize, a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x0042B720
// Name: public: int IterateRIFF::ChunkReadInt(void)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::ChunkReadInt(IterateRIFF *this)
{
  InFileRIFF *m_riff; // eax
  IFileReadBinary *m_io; // ecx
  int m_file; // [esp-4h] [ebp-8h]
  IterateRIFF *v5; // [esp+0h] [ebp-4h] BYREF

  v5 = this;
  m_riff = this->m_riff;
  m_io = this->m_riff->m_io;
  m_file = m_riff->m_file;
  v5 = nullptr;
  m_io->read(this: m_io, a2: &v5, a3: 4, a4: m_file);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0042B750
// Name: public: IterateOutputRIFF::IterateOutputRIFF(class OutFileRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
IterateOutputRIFF *__thiscall IterateOutputRIFF::IterateOutputRIFF(IterateOutputRIFF *this, OutFileRIFF *riff)
{
  int m_file; // edx
  int v4; // eax

  this->m_riff = riff;
  m_file = riff->m_file;
  if ( m_file != 0 )
  {
    v4 = riff->m_io->tell(this: riff->m_io, a2: m_file);
    this->m_start = v4;
    this->m_chunkPosition = v4;
    this->m_chunkStart = -1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B780
// Name: public: void IterateOutputRIFF::ChunkWrite(unsigned int,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkWrite(IterateOutputRIFF *this, unsigned int chunkname, void *pOutput, int size)
{
  int m_file; // edx
  int v6; // eax
  int v7; // edi
  unsigned int v8; // eax
  OutFileRIFF *m_riff; // eax
  int v10; // edx
  OutFileRIFF *v11; // eax
  int v12; // edx
  unsigned int v13; // eax
  int v14; // eax
  OutFileRIFF *v15; // ecx
  int v16; // edx

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    v6 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    v6 = 0;
  v7 = size;
  this->m_chunkPosition = v6;
  v8 = chunkname;
  this->m_chunkName = chunkname;
  chunkname = v8;
  m_riff = this->m_riff;
  this->m_chunkSize = v7;
  v10 = m_riff->m_file;
  if ( v10 != 0 )
    m_riff->m_io->write(this: m_riff->m_io, a2: &chunkname, a3: 4, a4: v10);
  v11 = this->m_riff;
  chunkname = v7;
  v12 = v11->m_file;
  if ( v12 != 0 )
    v11->m_io->write(this: v11->m_io, a2: &chunkname, a3: 4, a4: v12);
  if ( this->m_riff->m_file != 0 )
    this->m_riff->m_io->write(this: this->m_riff->m_io, a2: pOutput, a3: v7, a4: this->m_riff->m_file);
  if ( this->m_riff->m_file != 0 )
    v13 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: this->m_riff->m_file);
  else
    v13 = 0;
  v14 = (v13 & 1) + v13;
  v15 = this->m_riff;
  this->m_chunkPosition = v14;
  v16 = v15->m_file;
  if ( v16 != 0 )
    v15->m_io->seek(this: v15->m_io, a2: v16, a3: v14);
  this->m_chunkStart = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042B850
// Name: public: void IterateOutputRIFF::ChunkWriteData(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkWriteData(IterateOutputRIFF *this, void *pOutput, int size)
{
  int m_file; // edx

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    this->m_riff->m_io->write(this: this->m_riff->m_io, a2: pOutput, a3: size, a4: m_file);
}

//------------------------------------------------------------------------------
// Address: 0x0042B880
// Name: public: void IterateOutputRIFF::ChunkFinish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkFinish(IterateOutputRIFF *this)
{
  int m_file; // edx
  unsigned int v3; // eax
  int m_chunkStart; // edx
  int v5; // ecx
  unsigned int v6; // edi
  OutFileRIFF *m_riff; // eax
  int v8; // ebx
  int v9; // edi
  OutFileRIFF *v10; // eax
  int v11; // edx
  int v12; // edx
  int v13; // [esp+8h] [ebp-4h] BYREF

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    v3 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    v3 = 0;
  m_chunkStart = this->m_chunkStart;
  v5 = v3 + (v3 & 1);
  v6 = v3;
  m_riff = this->m_riff;
  this->m_chunkPosition = v5;
  v8 = m_riff->m_file;
  v9 = v6 - m_chunkStart - 8;
  if ( v8 != 0 )
    m_riff->m_io->seek(this: m_riff->m_io, a2: v8, a3: m_chunkStart + 4);
  v10 = this->m_riff;
  v13 = v9;
  v11 = v10->m_file;
  if ( v11 != 0 )
    v10->m_io->write(this: v10->m_io, a2: &v13, a3: 4, a4: v11);
  v12 = this->m_riff->m_file;
  if ( v12 != 0 )
    this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: v12, a3: this->m_chunkPosition);
  this->m_chunkStart = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042B910
// Name: public: void IterateOutputRIFF::ChunkStart(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkStart(IterateOutputRIFF *this, unsigned int chunkname)
{
  int m_file; // edx
  int v4; // eax
  int v5; // edx
  OutFileRIFF *m_riff; // esi

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    v4 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    v4 = 0;
  this->m_chunkStart = v4;
  v5 = this->m_riff->m_file;
  if ( v5 != 0 )
    this->m_riff->m_io->write(this: this->m_riff->m_io, a2: &chunkname, a3: 4, a4: v5);
  m_riff = this->m_riff;
  chunkname = 0;
  if ( m_riff->m_file != 0 )
    m_riff->m_io->write(this: m_riff->m_io, a2: &chunkname, a3: 4, a4: m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x0042B980
// Name: public: unsigned int IterateOutputRIFF::ChunkGetPosition(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall IterateOutputRIFF::ChunkGetPosition(IterateOutputRIFF *this)
{
  int m_file; // edx

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    return this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042B9A0
// Name: public: void IterateOutputRIFF::CopyChunkData(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::CopyChunkData(IterateOutputRIFF *this, IterateRIFF *input)
{
  unsigned int m_chunkSize; // eax
  void *v4; // edi
  int m_file; // edx

  m_chunkSize = input->m_chunkSize;
  if ( m_chunkSize != 0 )
  {
    v4 = operator new(nSize: m_chunkSize);
    input->m_riff->m_io->read(this: input->m_riff->m_io, a2: v4, a3: input->m_chunkSize, a4: input->m_riff->m_file);
    m_file = this->m_riff->m_file;
    if ( m_file != 0 )
      this->m_riff->m_io->write(this: this->m_riff->m_io, a2: v4, a3: input->m_chunkSize, a4: m_file);
    free(pMem: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BA00
// Name: public: InFileRIFF::InFileRIFF(char const __near *,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
InFileRIFF *__thiscall InFileRIFF::InFileRIFF(InFileRIFF *this, const char *pFileName, IFileReadBinary *io)
{
  IFileReadBinary *v4; // ecx
  int v5; // eax
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v8; // ecx
  int v9; // eax
  IFileReadBinary *v10; // ecx
  IFileReadBinary *v11; // ecx
  int m_file; // [esp-4h] [ebp-10h]

  v4 = io;
  this->m_io = io;
  v5 = v4->open(this: v4, a2: pFileName);
  this->m_file = v5;
  if ( v5 != 0 )
  {
    m_io = this->m_io;
    io = nullptr;
    m_io->read(this: m_io, a2: &io, a3: 4, a4: v5);
    if ( io == (IFileReadBinary *)1179011410 )
    {
      v8 = this->m_io;
      m_file = this->m_file;
      io = nullptr;
      v8->read(this: v8, a2: &io, a3: 4, a4: m_file);
      v9 = this->m_file;
      this->m_riffSize = (unsigned int)&io[-1];
      v10 = this->m_io;
      io = nullptr;
      v10->read(this: v10, a2: &io, a3: 4, a4: v9);
      v11 = this->m_io;
      this->m_riffName = (unsigned int)io;
      this->m_riffSize = v11->size(this: v11, a2: this->m_file) - 12;
    }
    else
    {
      printf(format: "Not a RIFF File [%s]\n", pFileName);
      this->m_riffSize = 0;
    }
    return this;
  }
  else
  {
    this->m_riffSize = 0;
    this->m_riffName = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BAC0
// Name: public: OutFileRIFF::OutFileRIFF(char const __near *,class IFileWriteBinary __near &)
// Source: json
//------------------------------------------------------------------------------
OutFileRIFF *__thiscall OutFileRIFF::OutFileRIFF(OutFileRIFF *this, int pFileName, int io)
{
  const char *v3; // edx
  int (__thiscall ***v5)(_DWORD, const char *); // ecx
  int v6; // eax
  IFileWriteBinary *m_io; // ecx
  IFileWriteBinary *v8; // ecx
  int m_file; // edx
  int v10; // eax
  int v11; // eax

  v3 = (const char *)pFileName;
  v5 = (int (__thiscall ***)(_DWORD, const char *))io;
  this->m_io = (IFileWriteBinary *)io;
  v6 = (**v5)(a1: v5, a2: v3);
  this->m_file = v6;
  if ( v6 != 0 )
  {
    m_io = this->m_io;
    io = 1179011410;
    m_io->write(this: m_io, a2: &io, a3: 4, a4: v6);
    v8 = this->m_io;
    m_file = this->m_file;
    this->m_riffSize = 0;
    this->m_nNamePos = v8->tell(this: v8, a2: m_file);
    v10 = this->m_file;
    pFileName = 0;
    if ( v10 != 0 )
      this->m_io->write(this: this->m_io, a2: &pFileName, a3: 4, a4: v10);
    v11 = this->m_file;
    pFileName = 1163280727;
    if ( v11 != 0 )
      this->m_io->write(this: this->m_io, a2: &pFileName, a3: 4, a4: v11);
    this->m_bUseIncorrectLISETLength = false;
    this->m_nLISETSize = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042BB50
// Name: public: OutFileRIFF::~OutFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OutFileRIFF::~OutFileRIFF(OutFileRIFF *this)
{
  int m_file; // eax
  int v3; // edi
  int v4; // eax
  int v5; // [esp+4h] [ebp-4h] BYREF

  m_file = this->m_file;
  if ( m_file != 0 )
  {
    v3 = ((int (__stdcall *)(int))this->m_io->tell)(a1: m_file) - 8;
    this->m_io->seek(this: this->m_io, a2: this->m_file, a3: this->m_nNamePos);
    if ( this->m_bUseIncorrectLISETLength )
      v3 = this->m_nLISETSize - 8;
    v4 = this->m_file;
    v5 = v3;
    if ( v4 != 0 )
      this->m_io->write(this: this->m_io, a2: &v5, a3: 4, a4: v4);
    this->m_io->close(this: this->m_io, a2: this->m_file);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BBC0
// Name: public: IterateRIFF::IterateRIFF(class InFileRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::IterateRIFF(IterateRIFF *this, InFileRIFF *riff, int size)
{
  this->m_riff = riff;
  this->m_size = size;
  if ( riff->m_riffSize != 0 )
  {
    this->m_start = ((int (__stdcall *)(int))riff->m_io->tell)(a1: riff->m_file);
    IterateRIFF::ChunkSetup(this);
  }
  else
  {
    this->m_chunkSize = -1;
  }
  return this;
}

} // namespace localization_check

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x005336C0
// Name: public: InFileRIFF::~InFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InFileRIFF::~InFileRIFF(InFileRIFF *this)
{
  this->m_io->close(this: this->m_io, a2: this->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x005336D0
// Name: private: void IterateRIFF::ChunkSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateRIFF::ChunkSetup(IterateRIFF *this)
{
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v3; // ecx
  int m_file; // [esp-4h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-4h] BYREF

  this->m_chunkPosition = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: this->m_riff->m_file);
  m_io = this->m_riff->m_io;
  m_file = this->m_riff->m_file;
  v6 = 0;
  m_io->read(this: m_io, a2: &v6, a3: 4, a4: m_file);
  this->m_chunkName = v6;
  v3 = this->m_riff->m_io;
  v5 = this->m_riff->m_file;
  v6 = 0;
  v3->read(this: v3, a2: &v6, a3: 4, a4: v5);
  this->m_chunkSize = v6;
}

//------------------------------------------------------------------------------
// Address: 0x00533740
// Name: public: bool IterateRIFF::ChunkAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkAvailable(IterateRIFF *this)
{
  int m_chunkSize; // eax

  m_chunkSize = this->m_chunkSize;
  return m_chunkSize != -1 && m_chunkSize < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x00533760
// Name: public: bool IterateRIFF::ChunkNext(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkNext(IterateRIFF *this)
{
  int m_chunkSize; // eax
  int v3; // edx
  int v5; // esi

  m_chunkSize = this->m_chunkSize;
  if ( m_chunkSize == -1 || m_chunkSize >= 0x10000000 )
    return false;
  v3 = this->m_chunkPosition + (this->m_chunkSize & 1) + m_chunkSize + 8;
  if ( v3 >= this->m_start + this->m_size )
  {
    this->m_chunkSize = -1;
    return false;
  }
  this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: this->m_riff->m_file, a3: v3);
  IterateRIFF::ChunkSetup(this);
  v5 = this->m_chunkSize;
  return v5 != -1 && v5 < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x005337D0
// Name: public: int IterateRIFF::ChunkRead(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkRead(IterateRIFF *this, void *pOutput)
{
  return this->m_riff->m_io->read(
           this: this->m_riff->m_io,
           a2: pOutput,
           a3: this->m_chunkSize,
           a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x005337F0
// Name: public: int IterateRIFF::ChunkReadPartial(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkReadPartial(IterateRIFF *this, void *pOutput, int dataSize)
{
  return this->m_riff->m_io->read(this: this->m_riff->m_io, a2: pOutput, a3: dataSize, a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x00533810
// Name: public: int IterateRIFF::ChunkReadInt(void)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::ChunkReadInt(IterateRIFF *this)
{
  InFileRIFF *m_riff; // eax
  IFileReadBinary *m_io; // ecx
  int m_file; // [esp-4h] [ebp-8h]
  IterateRIFF *v5; // [esp+0h] [ebp-4h] BYREF

  v5 = this;
  m_riff = this->m_riff;
  m_io = this->m_riff->m_io;
  m_file = m_riff->m_file;
  v5 = nullptr;
  m_io->read(this: m_io, a2: &v5, a3: 4, a4: m_file);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00533840
// Name: public: InFileRIFF::InFileRIFF(char const __near *,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
InFileRIFF *__thiscall InFileRIFF::InFileRIFF(InFileRIFF *this, const char *pFileName, IFileReadBinary *io)
{
  IFileReadBinary *v4; // ecx
  int v5; // eax
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v8; // ecx
  int v9; // eax
  IFileReadBinary *v10; // ecx
  IFileReadBinary *v11; // ecx
  int m_file; // [esp-4h] [ebp-10h]

  v4 = io;
  this->m_io = io;
  v5 = v4->open(this: v4, a2: pFileName);
  this->m_file = v5;
  if ( v5 != 0 )
  {
    m_io = this->m_io;
    io = nullptr;
    m_io->read(this: m_io, a2: &io, a3: 4, a4: v5);
    if ( io == (IFileReadBinary *)1179011410 )
    {
      v8 = this->m_io;
      m_file = this->m_file;
      io = nullptr;
      v8->read(this: v8, a2: &io, a3: 4, a4: m_file);
      v9 = this->m_file;
      this->m_riffSize = (unsigned int)&io[-1];
      v10 = this->m_io;
      io = nullptr;
      v10->read(this: v10, a2: &io, a3: 4, a4: v9);
      v11 = this->m_io;
      this->m_riffName = (unsigned int)io;
      this->m_riffSize = v11->size(this: v11, a2: this->m_file) - 12;
    }
    else
    {
      printf(format: "Not a RIFF File [%s]\n", pFileName);
      this->m_riffSize = 0;
    }
    return this;
  }
  else
  {
    this->m_riffSize = 0;
    this->m_riffName = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00533900
// Name: public: IterateRIFF::IterateRIFF(class InFileRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::IterateRIFF(IterateRIFF *this, InFileRIFF *riff, int size)
{
  this->m_riff = riff;
  this->m_size = size;
  if ( riff->m_riffSize != 0 )
  {
    this->m_start = ((int (__stdcall *)(int))riff->m_io->tell)(a1: riff->m_file);
    IterateRIFF::ChunkSetup(this);
  }
  else
  {
    this->m_chunkSize = -1;
  }
  return this;
}

} // namespace makegamedata

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x004396B0
// Name: public: unsigned int IterateRIFF::ChunkSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkSize(IterateRIFF *this)
{
  return this->m_chunkSize;
}

//------------------------------------------------------------------------------
// Address: 0x0054F7B0
// Name: public: InFileRIFF::~InFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InFileRIFF::~InFileRIFF(InFileRIFF *this)
{
  this->m_io->close(this: this->m_io, a2: this->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x0054F7C0
// Name: private: void IterateRIFF::ChunkSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateRIFF::ChunkSetup(IterateRIFF *this)
{
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v3; // ecx
  int m_file; // [esp-4h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-4h] BYREF

  this->m_chunkPosition = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: this->m_riff->m_file);
  m_io = this->m_riff->m_io;
  m_file = this->m_riff->m_file;
  v6 = 0;
  m_io->read(this: m_io, a2: &v6, a3: 4, a4: m_file);
  this->m_chunkName = v6;
  v3 = this->m_riff->m_io;
  v5 = this->m_riff->m_file;
  v6 = 0;
  v3->read(this: v3, a2: &v6, a3: 4, a4: v5);
  this->m_chunkSize = v6;
}

//------------------------------------------------------------------------------
// Address: 0x0054F830
// Name: public: bool IterateRIFF::ChunkAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkAvailable(IterateRIFF *this)
{
  int m_chunkSize; // eax

  m_chunkSize = this->m_chunkSize;
  return m_chunkSize != -1 && m_chunkSize < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x0054F850
// Name: public: bool IterateRIFF::ChunkNext(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkNext(IterateRIFF *this)
{
  int m_chunkSize; // eax
  int v3; // edx
  int v5; // esi

  m_chunkSize = this->m_chunkSize;
  if ( m_chunkSize == -1 || m_chunkSize >= 0x10000000 )
    return false;
  v3 = this->m_chunkPosition + (this->m_chunkSize & 1) + m_chunkSize + 8;
  if ( v3 >= this->m_start + this->m_size )
  {
    this->m_chunkSize = -1;
    return false;
  }
  this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: this->m_riff->m_file, a3: v3);
  IterateRIFF::ChunkSetup(this);
  v5 = this->m_chunkSize;
  return v5 != -1 && v5 < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x0054F8C0
// Name: public: int IterateRIFF::ChunkRead(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkRead(IterateRIFF *this, void *pOutput)
{
  return this->m_riff->m_io->read(
           this: this->m_riff->m_io,
           a2: pOutput,
           a3: this->m_chunkSize,
           a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x0054F8E0
// Name: public: IterateOutputRIFF::IterateOutputRIFF(class OutFileRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
IterateOutputRIFF *__thiscall IterateOutputRIFF::IterateOutputRIFF(IterateOutputRIFF *this, OutFileRIFF *riff)
{
  int m_file; // edx
  int v4; // eax

  this->m_riff = riff;
  m_file = riff->m_file;
  if ( m_file != 0 )
  {
    v4 = riff->m_io->tell(this: riff->m_io, a2: m_file);
    this->m_start = v4;
    this->m_chunkPosition = v4;
    this->m_chunkStart = -1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0054F910
// Name: public: void IterateOutputRIFF::ChunkWriteData(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkWriteData(IterateOutputRIFF *this, void *pOutput, int size)
{
  int m_file; // edx

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    this->m_riff->m_io->write(this: this->m_riff->m_io, a2: pOutput, a3: size, a4: m_file);
}

//------------------------------------------------------------------------------
// Address: 0x0054F940
// Name: public: void IterateOutputRIFF::ChunkFinish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkFinish(IterateOutputRIFF *this)
{
  int m_file; // edx
  unsigned int v3; // eax
  int m_chunkStart; // edx
  int v5; // ecx
  unsigned int v6; // edi
  OutFileRIFF *m_riff; // eax
  int v8; // ebx
  int v9; // edi
  OutFileRIFF *v10; // eax
  int v11; // edx
  int v12; // edx
  int v13; // [esp+8h] [ebp-4h] BYREF

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    v3 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    v3 = 0;
  m_chunkStart = this->m_chunkStart;
  v5 = v3 + (v3 & 1);
  v6 = v3;
  m_riff = this->m_riff;
  this->m_chunkPosition = v5;
  v8 = m_riff->m_file;
  v9 = v6 - m_chunkStart - 8;
  if ( v8 != 0 )
    m_riff->m_io->seek(this: m_riff->m_io, a2: v8, a3: m_chunkStart + 4);
  v10 = this->m_riff;
  v13 = v9;
  v11 = v10->m_file;
  if ( v11 != 0 )
    v10->m_io->write(this: v10->m_io, a2: &v13, a3: 4, a4: v11);
  v12 = this->m_riff->m_file;
  if ( v12 != 0 )
    this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: v12, a3: this->m_chunkPosition);
  this->m_chunkStart = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0054F9D0
// Name: public: void IterateOutputRIFF::ChunkStart(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkStart(IterateOutputRIFF *this, unsigned int chunkname)
{
  int m_file; // edx
  int v4; // eax
  int v5; // edx
  OutFileRIFF *m_riff; // esi

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    v4 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    v4 = 0;
  this->m_chunkStart = v4;
  v5 = this->m_riff->m_file;
  if ( v5 != 0 )
    this->m_riff->m_io->write(this: this->m_riff->m_io, a2: &chunkname, a3: 4, a4: v5);
  m_riff = this->m_riff;
  chunkname = 0;
  if ( m_riff->m_file != 0 )
    m_riff->m_io->write(this: m_riff->m_io, a2: &chunkname, a3: 4, a4: m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x0054FA40
// Name: public: void IterateOutputRIFF::CopyChunkData(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::CopyChunkData(IterateOutputRIFF *this, IterateRIFF *input)
{
  unsigned int m_chunkSize; // eax
  void *v4; // edi
  int m_file; // edx

  m_chunkSize = input->m_chunkSize;
  if ( m_chunkSize != 0 )
  {
    v4 = operator new(nSize: m_chunkSize);
    input->m_riff->m_io->read(this: input->m_riff->m_io, a2: v4, a3: input->m_chunkSize, a4: input->m_riff->m_file);
    m_file = this->m_riff->m_file;
    if ( m_file != 0 )
      this->m_riff->m_io->write(this: this->m_riff->m_io, a2: v4, a3: input->m_chunkSize, a4: m_file);
    free(pMem: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054FAA0
// Name: public: InFileRIFF::InFileRIFF(char const __near *,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
InFileRIFF *__thiscall InFileRIFF::InFileRIFF(InFileRIFF *this, const char *pFileName, IFileReadBinary *io)
{
  IFileReadBinary *v4; // ecx
  int v5; // eax
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v8; // ecx
  int v9; // eax
  IFileReadBinary *v10; // ecx
  IFileReadBinary *v11; // ecx
  int m_file; // [esp-4h] [ebp-10h]

  v4 = io;
  this->m_io = io;
  v5 = v4->open(this: v4, a2: pFileName);
  this->m_file = v5;
  if ( v5 != 0 )
  {
    m_io = this->m_io;
    io = nullptr;
    m_io->read(this: m_io, a2: &io, a3: 4, a4: v5);
    if ( io == (IFileReadBinary *)1179011410 )
    {
      v8 = this->m_io;
      m_file = this->m_file;
      io = nullptr;
      v8->read(this: v8, a2: &io, a3: 4, a4: m_file);
      v9 = this->m_file;
      this->m_riffSize = (unsigned int)&io[-1];
      v10 = this->m_io;
      io = nullptr;
      v10->read(this: v10, a2: &io, a3: 4, a4: v9);
      v11 = this->m_io;
      this->m_riffName = (unsigned int)io;
      this->m_riffSize = v11->size(this: v11, a2: this->m_file) - 12;
    }
    else
    {
      printf(format: "Not a RIFF File [%s]\n", pFileName);
      this->m_riffSize = 0;
    }
    return this;
  }
  else
  {
    this->m_riffSize = 0;
    this->m_riffName = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054FB60
// Name: public: OutFileRIFF::OutFileRIFF(char const __near *,class IFileWriteBinary __near &)
// Source: json
//------------------------------------------------------------------------------
OutFileRIFF *__thiscall OutFileRIFF::OutFileRIFF(OutFileRIFF *this, int pFileName, int io)
{
  const char *v3; // edx
  int (__thiscall ***v5)(_DWORD, const char *); // ecx
  int v6; // eax
  IFileWriteBinary *m_io; // ecx
  IFileWriteBinary *v8; // ecx
  int m_file; // edx
  int v10; // eax
  int v11; // eax

  v3 = (const char *)pFileName;
  v5 = (int (__thiscall ***)(_DWORD, const char *))io;
  this->m_io = (IFileWriteBinary *)io;
  v6 = (**v5)(a1: v5, a2: v3);
  this->m_file = v6;
  if ( v6 != 0 )
  {
    m_io = this->m_io;
    io = 1179011410;
    m_io->write(this: m_io, a2: &io, a3: 4, a4: v6);
    v8 = this->m_io;
    m_file = this->m_file;
    this->m_riffSize = 0;
    this->m_nNamePos = v8->tell(this: v8, a2: m_file);
    v10 = this->m_file;
    pFileName = 0;
    if ( v10 != 0 )
      this->m_io->write(this: this->m_io, a2: &pFileName, a3: 4, a4: v10);
    v11 = this->m_file;
    pFileName = 1163280727;
    if ( v11 != 0 )
      this->m_io->write(this: this->m_io, a2: &pFileName, a3: 4, a4: v11);
    this->m_bUseIncorrectLISETLength = false;
    this->m_nLISETSize = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0054FBF0
// Name: public: OutFileRIFF::~OutFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OutFileRIFF::~OutFileRIFF(OutFileRIFF *this)
{
  int m_file; // eax
  int v3; // edi
  int v4; // eax
  int v5; // [esp+4h] [ebp-4h] BYREF

  m_file = this->m_file;
  if ( m_file != 0 )
  {
    v3 = ((int (__stdcall *)(int))this->m_io->tell)(a1: m_file) - 8;
    this->m_io->seek(this: this->m_io, a2: this->m_file, a3: this->m_nNamePos);
    if ( this->m_bUseIncorrectLISETLength )
      v3 = this->m_nLISETSize - 8;
    v4 = this->m_file;
    v5 = v3;
    if ( v4 != 0 )
      this->m_io->write(this: this->m_io, a2: &v5, a3: 4, a4: v4);
    this->m_io->close(this: this->m_io, a2: this->m_file);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054FC60
// Name: public: IterateRIFF::IterateRIFF(class InFileRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::IterateRIFF(IterateRIFF *this, InFileRIFF *riff, int size)
{
  this->m_riff = riff;
  this->m_size = size;
  if ( riff->m_riffSize != 0 )
  {
    this->m_start = ((int (__stdcall *)(int))riff->m_io->tell)(a1: riff->m_file);
    IterateRIFF::ChunkSetup(this);
  }
  else
  {
    this->m_chunkSize = -1;
  }
  return this;
}

} // namespace phogen

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x004321A0
// Name: public: InFileRIFF::~InFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InFileRIFF::~InFileRIFF(InFileRIFF *this)
{
  this->m_io->close(this: this->m_io, a2: this->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x004321B0
// Name: private: void IterateRIFF::ChunkSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateRIFF::ChunkSetup(IterateRIFF *this)
{
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v3; // ecx
  int m_file; // [esp-4h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-4h] BYREF

  this->m_chunkPosition = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: this->m_riff->m_file);
  m_io = this->m_riff->m_io;
  m_file = this->m_riff->m_file;
  v6 = 0;
  m_io->read(this: m_io, a2: &v6, a3: 4, a4: m_file);
  this->m_chunkName = v6;
  v3 = this->m_riff->m_io;
  v5 = this->m_riff->m_file;
  v6 = 0;
  v3->read(this: v3, a2: &v6, a3: 4, a4: v5);
  this->m_chunkSize = v6;
}

//------------------------------------------------------------------------------
// Address: 0x00432220
// Name: public: bool IterateRIFF::ChunkAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkAvailable(IterateRIFF *this)
{
  int m_chunkSize; // eax

  m_chunkSize = this->m_chunkSize;
  return m_chunkSize != -1 && m_chunkSize < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x00432240
// Name: public: bool IterateRIFF::ChunkNext(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkNext(IterateRIFF *this)
{
  int m_chunkSize; // eax
  int v3; // edx
  int v5; // esi

  m_chunkSize = this->m_chunkSize;
  if ( m_chunkSize == -1 || m_chunkSize >= 0x10000000 )
    return false;
  v3 = this->m_chunkPosition + (this->m_chunkSize & 1) + m_chunkSize + 8;
  if ( v3 >= this->m_start + this->m_size )
  {
    this->m_chunkSize = -1;
    return false;
  }
  this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: this->m_riff->m_file, a3: v3);
  IterateRIFF::ChunkSetup(this);
  v5 = this->m_chunkSize;
  return v5 != -1 && v5 < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x004322B0
// Name: public: int IterateRIFF::ChunkRead(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkRead(IterateRIFF *this, void *pOutput)
{
  return this->m_riff->m_io->read(
           this: this->m_riff->m_io,
           a2: pOutput,
           a3: this->m_chunkSize,
           a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x004322D0
// Name: public: int IterateRIFF::ChunkReadPartial(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkReadPartial(IterateRIFF *this, void *pOutput, int dataSize)
{
  return this->m_riff->m_io->read(this: this->m_riff->m_io, a2: pOutput, a3: dataSize, a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x004322F0
// Name: public: int IterateRIFF::ChunkReadInt(void)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::ChunkReadInt(IterateRIFF *this)
{
  InFileRIFF *m_riff; // eax
  IFileReadBinary *m_io; // ecx
  int m_file; // [esp-4h] [ebp-8h]
  IterateRIFF *v5; // [esp+0h] [ebp-4h] BYREF

  v5 = this;
  m_riff = this->m_riff;
  m_io = this->m_riff->m_io;
  m_file = m_riff->m_file;
  v5 = nullptr;
  m_io->read(this: m_io, a2: &v5, a3: 4, a4: m_file);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00432320
// Name: public: IterateOutputRIFF::IterateOutputRIFF(class OutFileRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
IterateOutputRIFF *__thiscall IterateOutputRIFF::IterateOutputRIFF(IterateOutputRIFF *this, OutFileRIFF *riff)
{
  int m_file; // edx
  int v4; // eax

  this->m_riff = riff;
  m_file = riff->m_file;
  if ( m_file != 0 )
  {
    v4 = riff->m_io->tell(this: riff->m_io, a2: m_file);
    this->m_start = v4;
    this->m_chunkPosition = v4;
    this->m_chunkStart = -1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00432350
// Name: public: void IterateOutputRIFF::ChunkWriteData(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkWriteData(IterateOutputRIFF *this, void *pOutput, int size)
{
  int m_file; // edx

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    this->m_riff->m_io->write(this: this->m_riff->m_io, a2: pOutput, a3: size, a4: m_file);
}

//------------------------------------------------------------------------------
// Address: 0x00432380
// Name: public: void IterateOutputRIFF::ChunkFinish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkFinish(IterateOutputRIFF *this)
{
  int m_file; // edx
  unsigned int v3; // eax
  int m_chunkStart; // edx
  int v5; // ecx
  unsigned int v6; // edi
  OutFileRIFF *m_riff; // eax
  int v8; // ebx
  int v9; // edi
  OutFileRIFF *v10; // eax
  int v11; // edx
  int v12; // edx
  int v13; // [esp+8h] [ebp-4h] BYREF

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    v3 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    v3 = 0;
  m_chunkStart = this->m_chunkStart;
  v5 = v3 + (v3 & 1);
  v6 = v3;
  m_riff = this->m_riff;
  this->m_chunkPosition = v5;
  v8 = m_riff->m_file;
  v9 = v6 - m_chunkStart - 8;
  if ( v8 != 0 )
    m_riff->m_io->seek(this: m_riff->m_io, a2: v8, a3: m_chunkStart + 4);
  v10 = this->m_riff;
  v13 = v9;
  v11 = v10->m_file;
  if ( v11 != 0 )
    v10->m_io->write(this: v10->m_io, a2: &v13, a3: 4, a4: v11);
  v12 = this->m_riff->m_file;
  if ( v12 != 0 )
    this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: v12, a3: this->m_chunkPosition);
  this->m_chunkStart = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00432410
// Name: public: void IterateOutputRIFF::ChunkStart(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkStart(IterateOutputRIFF *this, unsigned int chunkname)
{
  int m_file; // edx
  int v4; // eax
  int v5; // edx
  OutFileRIFF *m_riff; // esi

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    v4 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    v4 = 0;
  this->m_chunkStart = v4;
  v5 = this->m_riff->m_file;
  if ( v5 != 0 )
    this->m_riff->m_io->write(this: this->m_riff->m_io, a2: &chunkname, a3: 4, a4: v5);
  m_riff = this->m_riff;
  chunkname = 0;
  if ( m_riff->m_file != 0 )
    m_riff->m_io->write(this: m_riff->m_io, a2: &chunkname, a3: 4, a4: m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x00432480
// Name: public: void IterateOutputRIFF::CopyChunkData(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::CopyChunkData(IterateOutputRIFF *this, IterateRIFF *input)
{
  unsigned int m_chunkSize; // eax
  void *v4; // edi
  int m_file; // edx

  m_chunkSize = input->m_chunkSize;
  if ( m_chunkSize != 0 )
  {
    v4 = operator new(nSize: m_chunkSize);
    input->m_riff->m_io->read(this: input->m_riff->m_io, a2: v4, a3: input->m_chunkSize, a4: input->m_riff->m_file);
    m_file = this->m_riff->m_file;
    if ( m_file != 0 )
      this->m_riff->m_io->write(this: this->m_riff->m_io, a2: v4, a3: input->m_chunkSize, a4: m_file);
    free(pMem: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004324E0
// Name: public: InFileRIFF::InFileRIFF(char const __near *,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
InFileRIFF *__thiscall InFileRIFF::InFileRIFF(InFileRIFF *this, const char *pFileName, IFileReadBinary *io)
{
  IFileReadBinary *v4; // ecx
  int v5; // eax
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v8; // ecx
  int v9; // eax
  IFileReadBinary *v10; // ecx
  IFileReadBinary *v11; // ecx
  int m_file; // [esp-4h] [ebp-10h]

  v4 = io;
  this->m_io = io;
  v5 = v4->open(this: v4, a2: pFileName);
  this->m_file = v5;
  if ( v5 != 0 )
  {
    m_io = this->m_io;
    io = nullptr;
    m_io->read(this: m_io, a2: &io, a3: 4, a4: v5);
    if ( io == (IFileReadBinary *)1179011410 )
    {
      v8 = this->m_io;
      m_file = this->m_file;
      io = nullptr;
      v8->read(this: v8, a2: &io, a3: 4, a4: m_file);
      v9 = this->m_file;
      this->m_riffSize = (unsigned int)&io[-1];
      v10 = this->m_io;
      io = nullptr;
      v10->read(this: v10, a2: &io, a3: 4, a4: v9);
      v11 = this->m_io;
      this->m_riffName = (unsigned int)io;
      this->m_riffSize = v11->size(this: v11, a2: this->m_file) - 12;
    }
    else
    {
      printf(format: "Not a RIFF File [%s]\n", pFileName);
      this->m_riffSize = 0;
    }
    return this;
  }
  else
  {
    this->m_riffSize = 0;
    this->m_riffName = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004325A0
// Name: public: OutFileRIFF::OutFileRIFF(char const __near *,class IFileWriteBinary __near &)
// Source: json
//------------------------------------------------------------------------------
OutFileRIFF *__thiscall OutFileRIFF::OutFileRIFF(OutFileRIFF *this, int pFileName, int io)
{
  const char *v3; // edx
  int (__thiscall ***v5)(_DWORD, const char *); // ecx
  int v6; // eax
  IFileWriteBinary *m_io; // ecx
  IFileWriteBinary *v8; // ecx
  int m_file; // edx
  int v10; // eax
  int v11; // eax

  v3 = (const char *)pFileName;
  v5 = (int (__thiscall ***)(_DWORD, const char *))io;
  this->m_io = (IFileWriteBinary *)io;
  v6 = (**v5)(a1: v5, a2: v3);
  this->m_file = v6;
  if ( v6 != 0 )
  {
    m_io = this->m_io;
    io = 1179011410;
    m_io->write(this: m_io, a2: &io, a3: 4, a4: v6);
    v8 = this->m_io;
    m_file = this->m_file;
    this->m_riffSize = 0;
    this->m_nNamePos = v8->tell(this: v8, a2: m_file);
    v10 = this->m_file;
    pFileName = 0;
    if ( v10 != 0 )
      this->m_io->write(this: this->m_io, a2: &pFileName, a3: 4, a4: v10);
    v11 = this->m_file;
    pFileName = 1163280727;
    if ( v11 != 0 )
      this->m_io->write(this: this->m_io, a2: &pFileName, a3: 4, a4: v11);
    this->m_bUseIncorrectLISETLength = false;
    this->m_nLISETSize = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00432630
// Name: public: OutFileRIFF::~OutFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OutFileRIFF::~OutFileRIFF(OutFileRIFF *this)
{
  int m_file; // eax
  int v3; // edi
  int v4; // eax
  int v5; // [esp+4h] [ebp-4h] BYREF

  m_file = this->m_file;
  if ( m_file != 0 )
  {
    v3 = ((int (__stdcall *)(int))this->m_io->tell)(a1: m_file) - 8;
    this->m_io->seek(this: this->m_io, a2: this->m_file, a3: this->m_nNamePos);
    if ( this->m_bUseIncorrectLISETLength )
      v3 = this->m_nLISETSize - 8;
    v4 = this->m_file;
    v5 = v3;
    if ( v4 != 0 )
      this->m_io->write(this: this->m_io, a2: &v5, a3: 4, a4: v4);
    this->m_io->close(this: this->m_io, a2: this->m_file);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004326A0
// Name: public: IterateRIFF::IterateRIFF(class InFileRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::IterateRIFF(IterateRIFF *this, InFileRIFF *riff, int size)
{
  this->m_riff = riff;
  this->m_size = size;
  if ( riff->m_riffSize != 0 )
  {
    this->m_start = ((int (__stdcall *)(int))riff->m_io->tell)(a1: riff->m_file);
    IterateRIFF::ChunkSetup(this);
  }
  else
  {
    this->m_chunkSize = -1;
  }
  return this;
}

} // namespace scenemanager

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0043A150
// Name: public: unsigned int IterateRIFF::ChunkSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkSize(IterateRIFF *this)
{
  return this->m_chunkSize;
}

//------------------------------------------------------------------------------
// Address: 0x00551550
// Name: public: InFileRIFF::~InFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InFileRIFF::~InFileRIFF(InFileRIFF *this)
{
  this->m_io->close(this: this->m_io, a2: this->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x00551560
// Name: private: void IterateRIFF::ChunkSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateRIFF::ChunkSetup(IterateRIFF *this)
{
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v3; // ecx
  int m_file; // [esp-4h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-4h] BYREF

  this->m_chunkPosition = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: this->m_riff->m_file);
  m_io = this->m_riff->m_io;
  m_file = this->m_riff->m_file;
  v6 = 0;
  m_io->read(this: m_io, a2: &v6, a3: 4, a4: m_file);
  this->m_chunkName = v6;
  v3 = this->m_riff->m_io;
  v5 = this->m_riff->m_file;
  v6 = 0;
  v3->read(this: v3, a2: &v6, a3: 4, a4: v5);
  this->m_chunkSize = v6;
}

//------------------------------------------------------------------------------
// Address: 0x005515D0
// Name: public: bool IterateRIFF::ChunkAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkAvailable(IterateRIFF *this)
{
  int m_chunkSize; // eax

  m_chunkSize = this->m_chunkSize;
  return m_chunkSize != -1 && m_chunkSize < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x005515F0
// Name: public: bool IterateRIFF::ChunkNext(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkNext(IterateRIFF *this)
{
  int m_chunkSize; // eax
  int v3; // edx
  int v5; // esi

  m_chunkSize = this->m_chunkSize;
  if ( m_chunkSize == -1 || m_chunkSize >= 0x10000000 )
    return false;
  v3 = this->m_chunkPosition + (this->m_chunkSize & 1) + m_chunkSize + 8;
  if ( v3 >= this->m_start + this->m_size )
  {
    this->m_chunkSize = -1;
    return false;
  }
  this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: this->m_riff->m_file, a3: v3);
  IterateRIFF::ChunkSetup(this);
  v5 = this->m_chunkSize;
  return v5 != -1 && v5 < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x00551660
// Name: public: int IterateRIFF::ChunkRead(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkRead(IterateRIFF *this, void *pOutput)
{
  return this->m_riff->m_io->read(
           this: this->m_riff->m_io,
           a2: pOutput,
           a3: this->m_chunkSize,
           a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x00551680
// Name: public: IterateOutputRIFF::IterateOutputRIFF(class OutFileRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
IterateOutputRIFF *__thiscall IterateOutputRIFF::IterateOutputRIFF(IterateOutputRIFF *this, OutFileRIFF *riff)
{
  int m_file; // edx
  int v4; // eax

  this->m_riff = riff;
  m_file = riff->m_file;
  if ( m_file != 0 )
  {
    v4 = riff->m_io->tell(this: riff->m_io, a2: m_file);
    this->m_start = v4;
    this->m_chunkPosition = v4;
    this->m_chunkStart = -1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005516B0
// Name: public: void IterateOutputRIFF::ChunkWriteData(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkWriteData(IterateOutputRIFF *this, void *pOutput, int size)
{
  int m_file; // edx

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    this->m_riff->m_io->write(this: this->m_riff->m_io, a2: pOutput, a3: size, a4: m_file);
}

//------------------------------------------------------------------------------
// Address: 0x005516E0
// Name: public: void IterateOutputRIFF::ChunkFinish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkFinish(IterateOutputRIFF *this)
{
  int m_file; // edx
  unsigned int v3; // eax
  int m_chunkStart; // edx
  int v5; // ecx
  unsigned int v6; // edi
  OutFileRIFF *m_riff; // eax
  int v8; // ebx
  int v9; // edi
  OutFileRIFF *v10; // eax
  int v11; // edx
  int v12; // edx
  int v13; // [esp+8h] [ebp-4h] BYREF

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    v3 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    v3 = 0;
  m_chunkStart = this->m_chunkStart;
  v5 = v3 + (v3 & 1);
  v6 = v3;
  m_riff = this->m_riff;
  this->m_chunkPosition = v5;
  v8 = m_riff->m_file;
  v9 = v6 - m_chunkStart - 8;
  if ( v8 != 0 )
    m_riff->m_io->seek(this: m_riff->m_io, a2: v8, a3: m_chunkStart + 4);
  v10 = this->m_riff;
  v13 = v9;
  v11 = v10->m_file;
  if ( v11 != 0 )
    v10->m_io->write(this: v10->m_io, a2: &v13, a3: 4, a4: v11);
  v12 = this->m_riff->m_file;
  if ( v12 != 0 )
    this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: v12, a3: this->m_chunkPosition);
  this->m_chunkStart = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00551770
// Name: public: void IterateOutputRIFF::ChunkStart(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::ChunkStart(IterateOutputRIFF *this, unsigned int chunkname)
{
  int m_file; // edx
  int v4; // eax
  int v5; // edx
  OutFileRIFF *m_riff; // esi

  m_file = this->m_riff->m_file;
  if ( m_file != 0 )
    v4 = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: m_file);
  else
    v4 = 0;
  this->m_chunkStart = v4;
  v5 = this->m_riff->m_file;
  if ( v5 != 0 )
    this->m_riff->m_io->write(this: this->m_riff->m_io, a2: &chunkname, a3: 4, a4: v5);
  m_riff = this->m_riff;
  chunkname = 0;
  if ( m_riff->m_file != 0 )
    m_riff->m_io->write(this: m_riff->m_io, a2: &chunkname, a3: 4, a4: m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x005517E0
// Name: public: void IterateOutputRIFF::CopyChunkData(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateOutputRIFF::CopyChunkData(IterateOutputRIFF *this, IterateRIFF *input)
{
  unsigned int m_chunkSize; // eax
  void *v4; // edi
  int m_file; // edx

  m_chunkSize = input->m_chunkSize;
  if ( m_chunkSize != 0 )
  {
    v4 = operator new(nSize: m_chunkSize);
    input->m_riff->m_io->read(this: input->m_riff->m_io, a2: v4, a3: input->m_chunkSize, a4: input->m_riff->m_file);
    m_file = this->m_riff->m_file;
    if ( m_file != 0 )
      this->m_riff->m_io->write(this: this->m_riff->m_io, a2: v4, a3: input->m_chunkSize, a4: m_file);
    free(pMem: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00551840
// Name: public: InFileRIFF::InFileRIFF(char const __near *,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
InFileRIFF *__thiscall InFileRIFF::InFileRIFF(InFileRIFF *this, const char *pFileName, IFileReadBinary *io)
{
  IFileReadBinary *v4; // ecx
  int v5; // eax
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v8; // ecx
  int v9; // eax
  IFileReadBinary *v10; // ecx
  IFileReadBinary *v11; // ecx
  int m_file; // [esp-4h] [ebp-10h]

  v4 = io;
  this->m_io = io;
  v5 = v4->open(this: v4, a2: pFileName);
  this->m_file = v5;
  if ( v5 != 0 )
  {
    m_io = this->m_io;
    io = nullptr;
    m_io->read(this: m_io, a2: &io, a3: 4, a4: v5);
    if ( io == (IFileReadBinary *)1179011410 )
    {
      v8 = this->m_io;
      m_file = this->m_file;
      io = nullptr;
      v8->read(this: v8, a2: &io, a3: 4, a4: m_file);
      v9 = this->m_file;
      this->m_riffSize = (unsigned int)&io[-1];
      v10 = this->m_io;
      io = nullptr;
      v10->read(this: v10, a2: &io, a3: 4, a4: v9);
      v11 = this->m_io;
      this->m_riffName = (unsigned int)io;
      this->m_riffSize = v11->size(this: v11, a2: this->m_file) - 12;
    }
    else
    {
      printf(format: "Not a RIFF File [%s]\n", pFileName);
      this->m_riffSize = 0;
    }
    return this;
  }
  else
  {
    this->m_riffSize = 0;
    this->m_riffName = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00551900
// Name: public: OutFileRIFF::OutFileRIFF(char const __near *,class IFileWriteBinary __near &)
// Source: json
//------------------------------------------------------------------------------
OutFileRIFF *__thiscall OutFileRIFF::OutFileRIFF(OutFileRIFF *this, int pFileName, int io)
{
  const char *v3; // edx
  int (__thiscall ***v5)(_DWORD, const char *); // ecx
  int v6; // eax
  IFileWriteBinary *m_io; // ecx
  IFileWriteBinary *v8; // ecx
  int m_file; // edx
  int v10; // eax
  int v11; // eax

  v3 = (const char *)pFileName;
  v5 = (int (__thiscall ***)(_DWORD, const char *))io;
  this->m_io = (IFileWriteBinary *)io;
  v6 = (**v5)(a1: v5, a2: v3);
  this->m_file = v6;
  if ( v6 != 0 )
  {
    m_io = this->m_io;
    io = 1179011410;
    m_io->write(this: m_io, a2: &io, a3: 4, a4: v6);
    v8 = this->m_io;
    m_file = this->m_file;
    this->m_riffSize = 0;
    this->m_nNamePos = v8->tell(this: v8, a2: m_file);
    v10 = this->m_file;
    pFileName = 0;
    if ( v10 != 0 )
      this->m_io->write(this: this->m_io, a2: &pFileName, a3: 4, a4: v10);
    v11 = this->m_file;
    pFileName = 1163280727;
    if ( v11 != 0 )
      this->m_io->write(this: this->m_io, a2: &pFileName, a3: 4, a4: v11);
    this->m_bUseIncorrectLISETLength = false;
    this->m_nLISETSize = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00551990
// Name: public: OutFileRIFF::~OutFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OutFileRIFF::~OutFileRIFF(OutFileRIFF *this)
{
  int m_file; // eax
  int v3; // edi
  int v4; // eax
  int v5; // [esp+4h] [ebp-4h] BYREF

  m_file = this->m_file;
  if ( m_file != 0 )
  {
    v3 = ((int (__stdcall *)(int))this->m_io->tell)(a1: m_file) - 8;
    this->m_io->seek(this: this->m_io, a2: this->m_file, a3: this->m_nNamePos);
    if ( this->m_bUseIncorrectLISETLength )
      v3 = this->m_nLISETSize - 8;
    v4 = this->m_file;
    v5 = v3;
    if ( v4 != 0 )
      this->m_io->write(this: this->m_io, a2: &v5, a3: 4, a4: v4);
    this->m_io->close(this: this->m_io, a2: this->m_file);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00551A00
// Name: public: IterateRIFF::IterateRIFF(class InFileRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::IterateRIFF(IterateRIFF *this, InFileRIFF *riff, int size)
{
  this->m_riff = riff;
  this->m_size = size;
  if ( riff->m_riffSize != 0 )
  {
    this->m_start = ((int (__stdcall *)(int))riff->m_io->tell)(a1: riff->m_file);
    IterateRIFF::ChunkSetup(this);
  }
  else
  {
    this->m_chunkSize = -1;
  }
  return this;
}

} // namespace sfmgen

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x00418BB0
// Name: public: InFileRIFF::~InFileRIFF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InFileRIFF::~InFileRIFF(InFileRIFF *this)
{
  this->m_io->close(this: this->m_io, a2: this->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x00418BC0
// Name: private: void IterateRIFF::ChunkSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IterateRIFF::ChunkSetup(IterateRIFF *this)
{
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v3; // ecx
  int m_file; // [esp-4h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-4h] BYREF

  this->m_chunkPosition = this->m_riff->m_io->tell(this: this->m_riff->m_io, a2: this->m_riff->m_file);
  m_io = this->m_riff->m_io;
  m_file = this->m_riff->m_file;
  v6 = 0;
  m_io->read(this: m_io, a2: &v6, a3: 4, a4: m_file);
  this->m_chunkName = v6;
  v3 = this->m_riff->m_io;
  v5 = this->m_riff->m_file;
  v6 = 0;
  v3->read(this: v3, a2: &v6, a3: 4, a4: v5);
  this->m_chunkSize = v6;
}

//------------------------------------------------------------------------------
// Address: 0x00418C30
// Name: public: bool IterateRIFF::ChunkAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkAvailable(IterateRIFF *this)
{
  int m_chunkSize; // eax

  m_chunkSize = this->m_chunkSize;
  return m_chunkSize != -1 && m_chunkSize < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x00418C50
// Name: public: bool IterateRIFF::ChunkNext(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IterateRIFF::ChunkNext(IterateRIFF *this)
{
  int m_chunkSize; // eax
  int v3; // edx
  int v5; // esi

  m_chunkSize = this->m_chunkSize;
  if ( m_chunkSize == -1 || m_chunkSize >= 0x10000000 )
    return false;
  v3 = this->m_chunkPosition + (this->m_chunkSize & 1) + m_chunkSize + 8;
  if ( v3 >= this->m_start + this->m_size )
  {
    this->m_chunkSize = -1;
    return false;
  }
  this->m_riff->m_io->seek(this: this->m_riff->m_io, a2: this->m_riff->m_file, a3: v3);
  IterateRIFF::ChunkSetup(this);
  v5 = this->m_chunkSize;
  return v5 != -1 && v5 < 0x10000000;
}

//------------------------------------------------------------------------------
// Address: 0x00418CC0
// Name: public: int IterateRIFF::ChunkRead(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IterateRIFF::ChunkRead(IterateRIFF *this, void *pOutput)
{
  return this->m_riff->m_io->read(
           this: this->m_riff->m_io,
           a2: pOutput,
           a3: this->m_chunkSize,
           a4: this->m_riff->m_file);
}

//------------------------------------------------------------------------------
// Address: 0x00418CE0
// Name: public: InFileRIFF::InFileRIFF(char const __near *,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
InFileRIFF *__thiscall InFileRIFF::InFileRIFF(InFileRIFF *this, const char *pFileName, IFileReadBinary *io)
{
  IFileReadBinary *v4; // ecx
  int v5; // eax
  IFileReadBinary *m_io; // ecx
  IFileReadBinary *v8; // ecx
  int v9; // eax
  IFileReadBinary *v10; // ecx
  IFileReadBinary *v11; // ecx
  int m_file; // [esp-4h] [ebp-10h]

  v4 = io;
  this->m_io = io;
  v5 = v4->open(this: v4, a2: pFileName);
  this->m_file = v5;
  if ( v5 != 0 )
  {
    m_io = this->m_io;
    io = nullptr;
    m_io->read(this: m_io, a2: &io, a3: 4, a4: v5);
    if ( io == (IFileReadBinary *)1179011410 )
    {
      v8 = this->m_io;
      m_file = this->m_file;
      io = nullptr;
      v8->read(this: v8, a2: &io, a3: 4, a4: m_file);
      v9 = this->m_file;
      this->m_riffSize = (unsigned int)&io[-1];
      v10 = this->m_io;
      io = nullptr;
      v10->read(this: v10, a2: &io, a3: 4, a4: v9);
      v11 = this->m_io;
      this->m_riffName = (unsigned int)io;
      this->m_riffSize = v11->size(this: v11, a2: this->m_file) - 12;
    }
    else
    {
      printf(format: "Not a RIFF File [%s]\n", pFileName);
      this->m_riffSize = 0;
    }
    return this;
  }
  else
  {
    this->m_riffSize = 0;
    this->m_riffName = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418DA0
// Name: public: IterateRIFF::IterateRIFF(class InFileRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall IterateRIFF::IterateRIFF(IterateRIFF *this, InFileRIFF *riff, int size)
{
  this->m_riff = riff;
  this->m_size = size;
  if ( riff->m_riffSize != 0 )
  {
    this->m_start = ((int (__stdcall *)(int))riff->m_io->tell)(a1: riff->m_file);
    IterateRIFF::ChunkSetup(this);
  }
  else
  {
    this->m_chunkSize = -1;
  }
  return this;
}

} // namespace vcdupdate
