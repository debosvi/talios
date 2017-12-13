
#include <math.h>

#include <talios/TSegment.h>

namespace Talios {
    
TSegment::TSegment(const TDecimal x1, const TDecimal y1, const TDecimal x2, const TDecimal y2) : m_p(x1,y1), m_q(x2,y2) {}
    
TSegment::TSegment(const TPoint &p, const TPoint &q) : m_p(p), m_q(q) {}

TSegment::TSegment(const TSegment &s) : m_p(s.m_p), m_q(s.m_q) { }
        
TSegment::~TSegment() {}

TPoint TSegment::p() const { return m_p; }
TPoint TSegment::q() const { return m_q; }

TSegment& TSegment::p(const TPoint& p) {
    m_p = p;
    return (*this);
}

TSegment& TSegment::q(const TPoint& q) {
    m_q = q;
    return (*this);
}

bool TSegment::isCrossing(const TSegment &s) const {
    // Find the four orientations needed for general and
    // special cases
    int o1 = TPoint::orientation(m_p, m_q, s.p());
    int o2 = TPoint::orientation(m_p, m_q, s.q());
    int o3 = TPoint::orientation(s.p(), s.q(), m_p);
    int o4 = TPoint::orientation(s.p(), s.q(), m_q);
    
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
    
    // Special Cases
    // p, m_q and q are colinear and q lies on segment pm_q
    if ((o1 == TPoint::ORIENT_COLINEAR) && onSegment(m_p, s.p(), m_q)) return true;
    
    // m_p, m_q and s.p() are colinear and s.q() lies on segment m_pm_q
    if ((o2 == TPoint::ORIENT_COLINEAR) && onSegment(m_p, s.q(), m_q)) return true;
    
    // s.p(), s.q() and m_p are colinear and m_p lies on segment s.p()s.q()
    if ((o3 == TPoint::ORIENT_COLINEAR) && onSegment(s.p(), m_p, s.q())) return true;
    
    // s.p(), s.q() and m_q are colinear and m_q lies on segment s.p()s.q()
    if ((o4 == TPoint::ORIENT_COLINEAR) && onSegment(s.p(), m_q, s.q())) return true;
    
    return false; // Doesn't fall in any of the above cases}
}

bool TSegment::onSegment(const TPoint& p, const TPoint& q, const TPoint& r) {
    if (q.x() <= fmax(p.x(), r.x()) && q.x() >= fmin(p.x(), r.x()) &&
        q.y() <= fmax(p.y(), r.y()) && q.y() >= fmin(p.y(), r.y()))
        return true;
    
    return false;
}

TDecimal TSegment::computeSurface(const TPoint& p) const {
    return TPoint::computeSurface(m_p, m_q, p);
}

} // namespace Talios
