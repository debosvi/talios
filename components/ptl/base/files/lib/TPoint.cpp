
#include <math.h>

#include <talios/TPoint.h>

namespace Talios {
    
TPoint::TPoint(const TDecimal x, const TDecimal y) :
        m_x(x), m_y(y) {
}

TPoint::TPoint(const TPoint &p) : m_x(p.m_x), m_y(p.m_y) { }
        
TPoint::~TPoint() {}

TDecimal TPoint::x() const {
    return m_x;
}

TDecimal TPoint::y() const {
    return m_y;
}

TDecimal TPoint::distanceTo(const TPoint &p) const {
    return sqrt(pow(p.x()-m_x, 2.0f)+pow(p.y()-m_y, 2.0f));
}

TPoint& TPoint::x(const TDecimal x) {
    m_x=x;
    return (*this);
}

TPoint& TPoint::y(const TDecimal y) {
    m_y=y;
    return (*this);
}

int TPoint::orientation(const TPoint& p, const TPoint& q, const TPoint& r) {
    // See http://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    // int val = (q.y - p.y) * (r.x - q.x) -
    //           (q.x - p.x) * (r.y - q.y);
    TDecimal val1 = (q.y() - p.y()) * (r.x() - q.x());
    TDecimal val2 = (q.x() - p.x()) * (r.y() - q.y());
    TDecimal val = val1-val2;
    
    if (fabs(val)<C_ERROR_THRESHOLD) return ORIENT_COLINEAR;  // colinear
    
    return ((val > 0) ? ORIENT_CLOCKWISE: ORIENT_ANTI_CLOCKWISE); // clock or counterclock wise
}

TDecimal TPoint::computeSurface(const TPoint& p, const TPoint& q, const TPoint& r) {
    TDecimal a=p.distanceTo(q);
    TDecimal b=p.distanceTo(r);
    TDecimal c=r.distanceTo(q);
    TDecimal s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

} // namespace Talios
