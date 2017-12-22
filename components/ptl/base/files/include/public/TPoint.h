
#ifndef __TALIOS_TPOINT_HPP__
#define __TALIOS_TPOINT_HPP__

#include <talios/TBase.h>

namespace Talios {
    
class TPoint {
    
public:
    TPoint(const TDecimal x=0.0f, const TDecimal y=0.0f, const bool valid=false);
    TPoint(const TPoint &p);
    ~TPoint();
    
    bool valid() const;
    TDecimal x() const;
    TDecimal y() const;
    TPoint& x(const TDecimal x);
    TPoint& y(const TDecimal y);
    TPoint& valid(const bool valid);
    TDecimal distanceTo(const TPoint&p) const;
    
    bool operator<(const TPoint &other) const;
    bool operator>(const TPoint &other) const;
    bool operator==(const TPoint &other) const;
    bool operator!=(const TPoint &other) const;
    
    static int orientation(const TPoint& p, const TPoint& q, const TPoint& r);
    static TDecimal surface(const TPoint& p, const TPoint& q, const TPoint& r);

    static const int ORIENT_COLINEAR = 0;
    static const int ORIENT_CLOCKWISE = 1;
    static const int ORIENT_ANTI_CLOCKWISE = 2;
        
private:
    TDecimal m_x;
    TDecimal m_y;
    bool m_valid;
};
    
} // namespace Talios

#endif // __TALIOS_TPOINT_HPP__
