#pragma once

class RZAnimMap {
    void* mpuiMap;
    uint8_t muiMapCount;
    uint32_t muiResourceCRC;
    RZAnimMap* mpNextMap;
};

class RZAnimMapHandler {
    RZAnimMap* mpFirstBonesMap;
    RZAnimMap* mpFirstMorphsMap;
};