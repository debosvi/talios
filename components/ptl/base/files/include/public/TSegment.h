
#ifndef __TALIOS_TSEGMENT_HPP__
#define __TALIOS_TSEGMENT_HPP__

#include <list>
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

    bool operator==(const TSegment &other) const;
    bool operator!=(const TSegment &other) const;
    
    bool cross(const TSegment &s) const;
    TPoint intersection(const TSegment &s) const;
    TDecimal surface(const TPoint& p) const;

    static bool onSegment(const TPoint& p, const TPoint& q, const TPoint& r);
        
private:
    TPoint m_p;
    TPoint m_q;    
};

typedef std::list<TSegment> TListSegment;

} // namespace Talios

#endif // __TALIOS_TSEGMENT_HPP__
