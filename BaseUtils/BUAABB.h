#pragma once
#include <algorithm>
#include "BUMath.h"

class BUAABB
{
public:
    BUVector3 mMin;
    BUVector3 mMax;

    bool Contain(const BUAABB& _otherAabb) const // not entirely accurate.. but still good enough
    {
        return mMin.x <= _otherAabb.mMin.x &&
            mMin.y <= _otherAabb.mMin.y &&
            mMin.z <= _otherAabb.mMin.z &&
            _otherAabb.mMax.x <= mMax.x &&
            _otherAabb.mMax.y <= mMax.y &&
            _otherAabb.mMax.z <= mMax.z;
    }

    void Include(const BUAABB& _box)
    {
        mMax.Max(_box.mMax);
        mMin.Min(_box.mMin);
    }

    void Expand(const BUVector3& _Expansion)
    {
        mMin -= _Expansion;
        mMax += _Expansion;
    }
};