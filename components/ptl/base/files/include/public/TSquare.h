
#ifndef __TALIOS_TSQUARE_HPP__
#define __TALIOS_TSQUARE_HPP__

#include <talios/TSegment.h>

namespace Talios {
    
class TSquare {
    
public:
    TSquare(const TDecimal x1=0.0f, const TDecimal y1=0.0f, const TDecimal x2=0.0f, const TDecimal y2=0.0f);
    TSquare(const TPoint &p, const TDecimal lg);
    TSquare(const TDecimal cx, const TDecimal cy, const TDecimal lg);
    TSquare(const TSquare &s);
    ~TSquare();
    
    TPoint tl() const;
    TPoint tr() const;
    TPoint bl() const;
    TPoint br() const;
    
    TDecimal surface() const;
    
    bool isIn(const TPoint &p) const;
        
private:
    TPoint m_tl;
    TPoint m_tr;
    TPoint m_bl;
    TPoint m_br;
};
    
} // namespace Talios

#endif // __TALIOS_TSQUARE_HPP__
