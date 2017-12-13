
#include <math.h>

#include <talios/TPoint.h>

namespace Talios {
    
TPoint::TPoint(const float x, const float y) :
        m_x(x), m_y(y) {
}

TPoint::TPoint(const TPoint &p) : m_x(p.m_x), m_y(p.m_y) { }
        
TPoint::~TPoint() {}

float TPoint::x() const {
    return m_x;
}

float TPoint::y() const {
    return m_y;
}

float TPoint::distanceTo(const TPoint &p) const {
    return sqrt(pow(p.x()-m_x, 2.0f)+pow(p.y()-m_y, 2.0f));
}

TPoint& TPoint::x(const float x) {
    m_x=x;
    return (*this);
}

TPoint& TPoint::y(const float y) {
    m_y=y;
    return (*this);
}

int TPoint::orientation(const TPoint& p, const TPoint& q, const TPoint& r) {
    // See http://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    // int val = (q.y - p.y) * (r.x - q.x) -
    //           (q.x - p.x) * (r.y - q.y);
    float val1 = (q.y() - p.y()) * (r.x() - q.x());
    float val2 = (q.x() - p.x()) * (r.y() - q.y());
    float val = val1-val2;
    
    if (fabs(val)<0.0001f) return ORIENT_COLINEAR;  // colinear
    
    return ((val > 0) ? ORIENT_CLOCKWISE: ORIENT_ANTI_CLOCKWISE); // clock or counterclock wise
}

} // namespace Talios
