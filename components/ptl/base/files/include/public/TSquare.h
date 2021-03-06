
#ifndef __TALIOS_TSQUARE_HPP__
#define __TALIOS_TSQUARE_HPP__

#include <talios/TSegment.h>

namespace Talios {
    
class TSquare {
    
public:
    TSquare(const TDecimal x1, const TDecimal y1, const TDecimal x2, const TDecimal y2);
    TSquare(const TPoint &p, const TPoint& q);
    TSquare(const TPoint &p, const TDecimal lg);
    TSquare(const TDecimal cx, const TDecimal cy, const TDecimal lg);
    TSquare(const TSquare &s);
    ~TSquare();
    
    TPoint tl() const;
    TPoint tr() const;
    TPoint bl() const;
    TPoint br() const;
    
    TDecimal surface() const;
    bool operator==(const TSquare &other) const;
    bool operator!=(const TSquare &other) const;
    TListSegment split();
    
    bool in(const TPoint &p) const;
    
private:
    TPoint m_tl;
    TPoint m_br;
};

typedef std::list<TSquare> TListSquare;

} // namespace Talios

#endif // __TALIOS_TSQUARE_HPP__
