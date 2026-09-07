// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/makeparticles.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040DFA0
// Name: bool CreateTargetFile_PCF(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateTargetFile_PCF(const char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  char *formatName; // edi
  IDataModel_vtbl *v5; // esi
  int v6; // eax
  DmxHeader_t header; // [esp+8h] [ebp-BCh] BYREF
  CUtlBuffer binaryBuffer; // [esp+90h] [ebp-34h] BYREF
  CDmElement *pRoot; // [esp+C0h] [ebp-4h] BYREF

  header.nEncodingVersion = -1;
  header.nFormatVersion = -1;
  header.formatName[0] = 0;
  header.encodingName[0] = 0;
  if ( g_pDataModel->RestoreFromFile(
         this: g_pDataModel,
         a2: pSourceName,
         a3: nullptr,
         a4: nullptr,
         a5: &pRoot,
         a6: CR_DELETE_NEW,
         a7: &header) == DMFILEID_INVALID )
  {
    _Warning(a1: "CreateTargetFile_PCF: Error reading file \"%s\"!\n", pSourceName);
    return 0;
  }
  else
  {
    formatName = header.formatName;
    if ( g_pDataModel->FindFormatUpdater(this: g_pDataModel, a2: header.formatName) == nullptr )
      formatName = "dmx";
    CUtlBuffer::CUtlBuffer(this: &binaryBuffer, growSize: 0, initSize: 0, nFlags: 0);
    v5 = g_pDataModel->__vftable;
    v6 = CVTFTexture::MipCount(this: (CVTFTexture *)pRoot);
    if ( v5->Serialize(this: g_pDataModel, a2: &binaryBuffer, a3: "binary", a4: formatName, a5: (DmElementHandle_t)v6) )
    {
      g_pDataModel->RemoveFileId(this: g_pDataModel, a2: pRoot->m_fileId);
      WriteBufferToFile(pTargetName, buffer: &binaryBuffer, bWriteToZip, writeMode: g_WriteModeForConversions);
      if ( binaryBuffer.m_Memory.m_nGrowSize >= 0 && binaryBuffer.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: binaryBuffer.m_Memory.m_pMemory);
      return 1;
    }
    else
    {
      _Warning(a1: "CreateTargetFile_PCF: Error writing buffer\n");
      if ( binaryBuffer.m_Memory.m_nGrowSize >= 0 && binaryBuffer.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: binaryBuffer.m_Memory.m_pMemory);
      return 0;
    }
  }
}
