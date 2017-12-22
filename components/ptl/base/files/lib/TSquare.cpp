
#include <math.h>

#include <talios/TSquare.h>

namespace Talios {
    
TSquare::TSquare(const TDecimal x1, const TDecimal y1, const TDecimal x2, const TDecimal y2) : 
        m_tl(x1,y1), m_br(x2,y2) {
}

TSquare::TSquare(const TPoint &p, const TPoint& q) : 
        m_tl(p), m_br(q) { 
    if(m_tl>m_br) {
        TPoint aux=m_tl;
        m_tl=m_br;
        m_br=aux;
    }
}

TSquare::TSquare(const TPoint &p, const TDecimal lg) : 
		m_tl(p.x()-lg/2.0f,p.y()+lg/2.0f), 
		m_br(p.x()+lg/2.0f,p.y()-lg/2.0f) {
}

TSquare::TSquare(const TDecimal cx, const TDecimal cy, const TDecimal lg)  : 
		m_tl(cx-lg/2.0f,cy-lg/2.0f), 
		m_br(cx+lg/2.0f,cy+lg/2.0f) {
}	
	
TSquare::TSquare(const TSquare &s) : 
    	m_tl(s.m_tl), m_br(s.m_br) {
}
      
TSquare::~TSquare() {}

TPoint TSquare::tl() const { return m_tl; }
TPoint TSquare::br() const { return m_br; }
TPoint TSquare::tr() const { return TPoint(m_br.x(), m_tl.y()); }
TPoint TSquare::bl() const { return TPoint(m_tl.x(), m_br.y()); }

bool TSquare::in(const TPoint &p) const {
    TDecimal sq_surf=this->surface();
    TDecimal s1=TPoint::surface(this->tl(), this->tr(), p);
    TDecimal s2=TPoint::surface(this->tl(), this->br(), p);
    TDecimal s3=TPoint::surface(this->bl(), this->tr(), p);
    TDecimal s4=TPoint::surface(this->bl(), this->br(), p);
    TDecimal p_surf=s1+s2+s3+s4;
    if((p_surf-sq_surf)<C_ERROR_THRESHOLD) return true;
    return false;
}

TDecimal TSquare::surface() const {
    return tl().distanceTo(tr())*tl().distanceTo(bl());
}


bool TSquare::operator ==(const TSquare& other) const {
    bool b1=(tl()==other.tl());
    bool b2=(br()==other.br());
    return b1&&b2;
}

bool TSquare::operator!=(const TSquare& other) const {
    return !(other==(*this));
}

TListSegment TSquare::split() {
    TListSegment list;
    list.push_back(TSegment(tl(),tr()));
    list.push_back(TSegment(tl(),bl()));
    list.push_back(TSegment(tr(),br()));
    list.push_back(TSegment(bl(),br()));
    return list;
}


} // namespace Talios
