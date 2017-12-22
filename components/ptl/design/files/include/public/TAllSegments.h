
#ifndef __TALIOS_TALLSEGMENTS_HPP__
#define __TALIOS_TALLSEGMENTS_HPP__

#include <talios/TSegment.h>
#include <talios/TSquare.h>

namespace Talios {

class TAllSegments {
    
public:
    TAllSegments();
    ~TAllSegments();
    
    void reset();
    void addSquare(const TSquare& s);
    int count() const;
    TListSquare squares() const;
    TListSegment split();
    
private:
    TListSquare m_lsq;
    
    bool _present(const TSquare& s);
};
    
} // namespace Talios

#endif // __TALIOS_TALLSEGMENTS_HPP__
