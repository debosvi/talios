
#ifndef __TALIOS_TSEGMENT_HPP__
#define __TALIOS_TSEGMENT_HPP__

#include <talios/TPoint.h>

namespace Talios {
    
class TSegment {
    
public:
    TSegment(const TDecimal p1=0.0f, const TDecimal q1=0.0f, const TDecimal p2=0.0f, const TDecimal q2=0.0f);
    TSegment(const TPoint &p, const TPoint &q);
    TSegment(const TSegment &s);
    ~TSegment();
    
    TPoint p() const;
    TPoint q() const;
    TSegment& p(const TPoint& p);
    TSegment& q(const TPoint& q);
    
    bool isCrossing(const TSegment &s) const;
    TDecimal computeSurface(const TPoint& p) const;

    static bool onSegment(const TPoint& p, const TPoint& q, const TPoint& r);
        
private:
    TPoint m_p;
    TPoint m_q;
};
    
} // namespace Talios

#endif // __TALIOS_TSEGMENT_HPP__
