
#ifndef __TALIOS_TSQUARE_HPP__
#define __TALIOS_TSQUARE_HPP__

#include <talios/TSegment.h>

namespace Talios {
    
class TSquare {
    
public:
    TSquare(const float x1=0.0f, const float y1=0.0f, const float x2=0.0f, const float y2=0.0f);
    TSquare(const TPoint &p, const float lg);
    TSquare(const float cx, const float cy, const float lg);
    TSquare(const TSquare &s);
    ~TSquare();
    
    TPoint tl() const;
    TPoint tr() const;
    TPoint bl() const;
    TPoint br() const;
    
    float surface() const;
    
    bool isIn(const TPoint &p) const;
        
private:
    TPoint m_tl;
    TPoint m_tr;
    TPoint m_bl;
    TPoint m_br;
};
    
} // namespace Talios

#endif // __TALIOS_TSQUARE_HPP__
