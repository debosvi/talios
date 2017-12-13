
#include <math.h>

#include <talios/TSquare.h>

namespace Talios {
    
TSquare::TSquare(const float x1, const float y1, const float x2, const float y2) : 
	m_tl(x1,y1), m_tr(x2,y1), m_bl(x1,y2), m_br(x2,y2)
{}
    
TSquare::TSquare(const TPoint &p, const float lg) : 
	m_tl(p.x()-lg/2.0f,p.y()+lg/2.0f), 
	m_tr(p.x()+lg/2.0f,p.y()+lg/2.0f), 
	m_bl(p.x()-lg/2.0f,p.y()-lg/2.0f), 
	m_br(p.x()+lg/2.0f,p.y()-lg/2.0f)
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
    float sq_surf=this->surface();
    float s1=TPoint::computeSurface(m_tl, m_tr, p);
    float s2=TPoint::computeSurface(m_tl, m_bl, p);
    float s3=TPoint::computeSurface(m_br, m_bl, p);
    float s4=TPoint::computeSurface(m_br, m_tr, p);
    float p_surf=s1+s2+s3+s4;
    if((p_surf-sq_surf)<0.0000001f) return true;
    return false;
}

float TSquare::surface() const {
    return m_tl.distanceTo(m_tr)*m_tl.distanceTo(m_bl);
}

} // namespace Talios
