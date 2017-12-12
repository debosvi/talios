
#include <math.h>

#include <talios/TSegment.h>

namespace Talios {
    
TSegment::TSegment(const float x1, const float y1, const float x2, const float y2) : m_p(x1,y1), m_q(x2,y2) {}
    
TSegment::TSegment(const TPoint &p, const TPoint &q) : m_p(p), m_q(q) {}

TSegment::TSegment(const TSegment &s) : m_p(s.m_p), m_q(s.m_q) { }
        
TSegment::~TSegment() {}

TPoint TSegment::getP() const { return m_p; }
TPoint TSegment::getQ() const { return m_q; }

TSegment& TSegment::setP(const TPoint& p) {
    m_p = p;
    return (*this);
}

TSegment& TSegment::setQ(const TPoint& q) {
    m_q = q;
    return (*this);
}

bool TSegment::isCrossing(const TSegment &s) const {
    // Find the four orientations needed for general and
    // special cases
    int o1 = TPoint::orientation(m_p, m_q, s.getP());
    int o2 = TPoint::orientation(m_p, m_q, s.getQ());
    int o3 = TPoint::orientation(s.getP(), s.getQ(), m_p);
    int o4 = TPoint::orientation(s.getP(), s.getQ(), m_q);
    
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
    
    // Special Cases
    // p, m_q and q are colinear and q lies on segment pm_q
    if ((o1 == TPoint::ORIENT_COLINEAR) && onSegment(m_p, s.getP(), m_q)) return true;
    
    // m_p, m_q and s.getP() are colinear and s.getQ() lies on segment m_pm_q
    if ((o2 == TPoint::ORIENT_COLINEAR) && onSegment(m_p, s.getQ(), m_q)) return true;
    
    // s.getP(), s.getQ() and m_p are colinear and m_p lies on segment s.getP()s.getQ()
    if ((o3 == TPoint::ORIENT_COLINEAR) && onSegment(s.getP(), m_p, s.getQ())) return true;
    
    // s.getP(), s.getQ() and m_q are colinear and m_q lies on segment s.getP()s.getQ()
    if ((o4 == TPoint::ORIENT_COLINEAR) && onSegment(s.getP(), m_q, s.getQ())) return true;
    
    return false; // Doesn't fall in any of the above cases}
}

bool TSegment::onSegment(const TPoint& p, const TPoint& q, const TPoint& r) {
    if (q.getX() <= fmax(p.getX(), r.getX()) && q.getX() >= fmin(p.getX(), r.getX()) &&
        q.getY() <= fmax(p.getY(), r.getY()) && q.getY() >= fmin(p.getY(), r.getY()))
        return true;
    
    return false;
}


} // namespace Talios
