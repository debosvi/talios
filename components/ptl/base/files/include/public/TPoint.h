
#ifndef __TALIOS_TPOINT_HPP__
#define __TALIOS_TPOINT_HPP__

namespace Talios {
    
class TPoint {
    
public:
    TPoint(const float x=0.0f, const float y=0.0f);
    TPoint(const TPoint &p);
    ~TPoint();
    
    float getX() const;
    float getY() const;
    TPoint& setX(const float x);
    TPoint& setY(const float y);
    float distanceTo(const TPoint&p) const;
    static int orientation(const TPoint& p, const TPoint& q, const TPoint& r);

    static const int ORIENT_COLINEAR = 0;
    static const int ORIENT_CLOCKWISE = 1;
    static const int ORIENT_ANTI_CLOCKWISE = 2;
        
private:
    float m_x;
    float m_y;
};
    
} // namespace Talios

#endif // __TALIOS_TPOINT_HPP__
