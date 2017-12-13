
#include <math.h>

#include <talios/TSquare.h>

namespace Talios {
    
TSquare::TSquare(const float x1, const float y1, const float x2, const float y2) : 
	m_tl(x1,y1), m_tr(x2,y1), m_bl(x1,y2), m_br(x2,y2)
{}
    
TSquare::TSquare(const TPoint &p, const float lg) : 
	m_tl(p.x()-lg/2.0f,p.y()-lg/2.0f), 
	m_tr(p.x()+lg/2.0f,p.y()-lg/2.0f), 
	m_bl(p.x()-lg/2.0f,p.y()+lg/2.0f), 
	m_br(p.x()+lg/2.0f,p.y()+lg/2.0f)
{}
 
TSquare::TSquare(const float cx, const float cy, const float lg)  : 
	m_tl(cx-lg/2.0f,cy-lg/2.0f), 
	m_tr(cx+lg/2.0f,cy-lg/2.0f), 
	m_bl(cx-lg/2.0f,cy+lg/2.0f), 
	m_br(cx+lg/2.0f,cy+lg/2.0f)
{}	
	
TSquare::TSquare(const TSquare &s) : 
	m_tl(s.m_tl), m_tr(s.m_tr), m_bl(s.m_bl), m_br(s.m_br)
{}
      
TSquare::~TSquare() {}

TPoint TSquare::tl() const { return m_tl; }
TPoint TSquare::tr() const { return m_tr; }
TPoint TSquare::bl() const { return m_bl; }
TPoint TSquare::br() const { return m_br; }

bool TSquare::isIn(const TPoint &p) const {
	return true;
}

} // namespace Talios
