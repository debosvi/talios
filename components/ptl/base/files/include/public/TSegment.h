
#ifndef __TALIOS_TSEGMENT_HPP__
#define __TALIOS_TSEGMENT_HPP__

#include <talios/TPoint.h>

namespace Talios {
    
class TSegment {
    
public:
    TSegment(const float p1, const float q1, const float p2, const float q2);
    TSegment(const TPoint &p, const TPoint &q);
    TSegment(const TSegment &s);
    ~TSegment();
    
    TPoint getP() const;
    TPoint getQ() const;
    TSegment& setP(const TPoint& p);
    TSegment& setQ(const TPoint& q);
    
    bool isCrossing(const TSegment &s) const;

    static bool onSegment(const TPoint& p, const TPoint& q, const TPoint& r);
        
private:
    TPoint m_p;
    TPoint m_q;
};
    
} // namespace Talios

#endif // __TALIOS_TSEGMENT_HPP__
