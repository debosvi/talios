
#include <math.h>

#include <talios/TSegment.h>

namespace Talios {
    
TSegment::TSegment(const TDecimal X1, const TDecimal Y1, const TDecimal X2, const TDecimal Y2) : 
    TSegment(TPoint(X1,Y1), TPoint(X2,Y2)) {}
    
TSegment::TSegment(const TPoint &p, const TPoint &q) :  
        m_p(p), m_q(q) {
    if(m_p>m_q) {
        TPoint aux=m_p;
        m_p=m_q;
        m_q=aux;
    }
}


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


bool TSegment::operator==(const TSegment& other) const {
    bool b1=(m_p.x() == other.m_p.x()) && (m_p.y() == other.m_p.y());
    bool b2=(m_q.x() == other.m_q.x()) && (m_q.y() == other.m_q.y());
    return (b1&&b2);
}

bool TSegment::operator!=(const TSegment& other) const {
    return !((*this)==other);
}


bool TSegment::cross(const TSegment &s) const {
    // Find the four orientations needed for general and
    // special cases
    int o1 = TPoint::orientation(m_p, m_q, s.p());
    int o2 = TPoint::orientation(m_p, m_q, s.q());
    int o3 = TPoint::orientation(s.p(), s.q(), m_p);
    int o4 = TPoint::orientation(s.p(), s.q(), m_q);
        
    if(m_p==s.p()) return false;
    if(m_p==s.q()) return false;
    if(m_q==s.p()) return false;
    if(m_q==s.q()) return false;
    
    // General case
    if ((o1 != o2) && (o3 != o4))
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

#define X1	(this->p().x())
#define X2	(this->q().x())
#define Y1	(this->p().y())
#define Y2	(this->q().y())
#define U1	(s.p().x())
#define U2	(s.q().x())
#define V1	(s.p().y())
#define V2	(s.q().y())

TPoint TSegment::intersection(const TSegment &s) const {
	bool b=cross(s);
	TPoint p;
	if(b) {
		TDecimal xnum = ((X1-X2)*((U1*V2)-(U2*V1))) - ((U2-U1)*((X2*Y1)-(X1*Y2)));
		TDecimal xden = ((V1-V2)*(X1-X2)) - ((U2-U1)*(Y2-Y1));
		TDecimal x = -1.0f*xnum/xden;
		
		TDecimal ynum =  (U1*V2*Y1) - (U1*V2*Y2) - (U2*V1*Y1) + (U2*V1*Y2) - (V1*X1*Y2) + (V1*X2*Y1) + (V2*X1*Y2) - (V2*X2*Y1);
		TDecimal yden =  (-1.0f*U1*Y1) + (U1*Y2) + (U2*Y1) - (U2*Y2) + (V1*X1) - (V1*X2) - (V2*X1) + (V2*X2);
		TDecimal y = -1.0*ynum/yden;	
		
		p.x(x);
		p.y(y);	
		p.valid(true);	
	}
	return p;
}

bool TSegment::onSegment(const TPoint& p, const TPoint& q, const TPoint& r) {
    if(p==q) return false;
    if(q==r) return false;
    
    if (q.x() <= fmax(p.x(), r.x()) && q.x() >= fmin(p.x(), r.x()) &&
        q.y() <= fmax(p.y(), r.y()) && q.y() >= fmin(p.y(), r.y())) 
        return true;
    
    return false;
}

TDecimal TSegment::surface(const TPoint& p) const {
    return TPoint::surface(m_p, m_q, p);
}

} // namespace Talios
