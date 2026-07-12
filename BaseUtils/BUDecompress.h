#pragma once
#include <cstdint>
#include <zlib.h> // TO-DO: Include ZLIB header for z_stream_s
#include <vector>

struct BUCompressHeader
{
    uint32_t uiMagicNumber;
    uint32_t uiSectorSize;
    uint32_t uiTotalHeaderSize;
    uint32_t uiBigChunkSize;
    uint64_t uiCompDataSize;
    uint64_t uiUncompFileSize;
    uint32_t uiNbSectorsCompData;
    uint32_t uiPadding;
};

class BUDecompress
{
public:
    BUCompressHeader mCompHeader;
    uint32_t muiNbSectors;
    uint64_t* mpuiSectorTable;
    uint32_t* mpuiLookup;
    std::vector<uint8_t> *mpDecompBuffer;
    uint32_t muiDecompSize;
    bool mbCopy;
    z_stream_s mzStrm;

    uint32_t GetNbSectors() const
    {
        return muiNbSectors;
    }
    const uint64_t* GetSectorTable() const
    {
        return mpuiSectorTable;
    }
    uint32_t GetDecompSize() const
    {
        return muiDecompSize;
    }
    bool GetCopy() const
    {
        return mbCopy;
    }
    const z_stream_s& GetStream() const
    {
        return mzStrm;
    }

    void Decompress()
    {
        if (mCompHeader.uiMagicNumber == 0xBABEB1B0)
        {
            // Handle decompression logic
            // zlib should be the only library necessary..?
            return;
        }
    }
};
