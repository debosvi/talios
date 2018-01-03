
#include <math.h>
#include <cstdio>

#include <talios/TPoint.h>

namespace Talios {
    
TPoint::TPoint() : TPoint(0.0f, 0.0f, false) {
    }
    
TPoint::TPoint(const TDecimal x, const TDecimal y, const bool valid) :
    m_x(x), m_y(y), m_valid(valid) {
    }
    
TPoint::TPoint(const TPoint &p) : TPoint(p.m_x, p.m_y) { }
        
TPoint::~TPoint() {}

bool TPoint::valid() const {
	return m_valid;
}

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

TPoint& TPoint::valid(const bool valid) {
	m_valid=valid;
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

TDecimal TPoint::surface(const TPoint& p, const TPoint& q, const TPoint& r) {
    TDecimal a=p.distanceTo(q);
    TDecimal b=p.distanceTo(r);
    TDecimal c=r.distanceTo(q);
    TDecimal s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

bool TPoint::operator<(const TPoint& other) const {
    return (m_x < other.m_x);
}

bool TPoint::operator>(const TPoint& other) const {
    return !((*this)<other);
}

bool TPoint::operator==(const TPoint& other) const {
	bool b1=(fabs(m_x - other.m_x)<C_ERROR_THRESHOLD);
    bool b2=(fabs(m_y - other.m_y)<C_ERROR_THRESHOLD);
    bool b3=(m_valid==other.m_valid);
//     fprintf(stderr, "%s: b1(%d), b2(%d), b3(%d)\n", __PRETTY_FUNCTION__, b1, b2, b3);	
    return (b1 && b2 && b3);
}

bool TPoint::operator!=(const TPoint& other) const {
    return !(other==(*this));
}


} // namespace Talios
