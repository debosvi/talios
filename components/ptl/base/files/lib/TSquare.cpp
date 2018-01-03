
#include <math.h>
#include <cstdio>

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

TSquare::TSquare(const TDecimal cx, const TDecimal cy, const TDecimal lg) : 
    TSquare(TPoint(cx-lg/2.0f,cy+lg/2.0f), TPoint(cx+lg/2.0f,cy-lg/2.0f)) {
}	

TSquare::TSquare(const TPoint &p, const TDecimal lg) : TSquare(p.x(), p.y(), lg) {
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
    TDecimal s2=TPoint::surface(this->tr(), this->br(), p);
    TDecimal s3=TPoint::surface(this->br(), this->bl(), p);
    TDecimal s4=TPoint::surface(this->bl(), this->tl(), p);
    TDecimal p_surf=s1+s2+s3+s4;
//     fprintf(stderr, "%s: step 0\n", __PRETTY_FUNCTION__);	
    if((p_surf-sq_surf)<C_ERROR_THRESHOLD) {
//         fprintf(stderr, "%s: step 1\n", __PRETTY_FUNCTION__);	
        bool b1=TSegment::onSegment(this->tl(), p, this->tr());
        bool b2=TSegment::onSegment(this->tr(), p, this->br());
        bool b3=TSegment::onSegment(this->br(), p, this->bl());
        bool b4=TSegment::onSegment(this->bl(), p, this->tl());
//         fprintf(stderr, "%s: b1(%d), b2(%d), b3(%d), b4(%d)\n", __PRETTY_FUNCTION__, b1, b2, b3, b4);	
        if(b1 || b2 || b3 || b4) {
            return false;
        }
//         fprintf(stderr, "%s: step 1.2\n", __PRETTY_FUNCTION__);	        
        return true;
    }
//     fprintf(stderr, "%s: step 2\n", __PRETTY_FUNCTION__);	
    
    return false;
}

TDecimal TSquare::surface() const {
    return tl().distanceTo(tr())*tl().distanceTo(bl());
}


bool TSquare::operator==(const TSquare& other) const {
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
