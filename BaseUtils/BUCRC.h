#pragma once
#include <algorithm>
#include <array>
#include <cctype>
#include <cstdint>
#include <string>
#include <unordered_map>

class BUCRCTable
{
public:
    std::unordered_map<uint32_t, std::string> mCRCTable;
};

class BUCRC
{
public:
    // Tested against COLLISIONTESTER in the game, and it matches the CRC32 used in the Resource Header. (0xDDD2C2BD)
    uint32_t Generate(const std::string& _zString) const
    {
        std::string upper(_zString.size(), '\0');
        std::transform(_zString.begin(), _zString.end(), upper.begin(),
            [](unsigned char c) { return static_cast<char>(std::toupper(c)); });
        return GenerateRaw(reinterpret_cast<const uint8_t*>(upper.data()), upper.size());
    }

    uint32_t GenerateRaw(const uint8_t* data, size_t length) const
    {
        const auto& table = GetTable();
        uint32_t crc = 0xFFFFFFFFu;
        for (size_t i = 0; i < length; ++i)
        {
            crc = (crc >> 8) ^ table[(crc ^ data[i]) & 0xFF];
        }
        return crc ^ 0xFFFFFFFFu;
    }

private:
    static const std::array<uint32_t, 256>& GetTable()
    {
        static const std::array<uint32_t, 256> table = []
            {
                std::array<uint32_t, 256> t{};
                for (uint32_t i = 0; i < 256; ++i)
                {
                    uint32_t c = i;
                    for (int k = 0; k < 8; ++k)
                        c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
                    t[i] = c;
                }
                return t;
            }();
        return table;
    }
};