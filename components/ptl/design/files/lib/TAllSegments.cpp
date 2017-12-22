
#include <talios/TAllSegments.h>

namespace Talios {

TAllSegments::TAllSegments()  {
}

        
TAllSegments::~TAllSegments() {}

void TAllSegments::addSquare(const TSquare& s) {
    if(!_present(s))
        m_lsq.push_back(s);
}

void TAllSegments::reset() {
    m_lsq.clear();
}

int TAllSegments::count() const {
    return m_lsq.size();
}

bool TAllSegments::_present(const TSquare& s){
    for (TListSquare::iterator it=m_lsq.begin(); it != m_lsq.end(); ++it) {
        if((*it)==s) return true;
    }
    return false;        
}

TListSegment TAllSegments::split() {
    TListSegment list;
    for (TListSquare::iterator it=m_lsq.begin(); it != m_lsq.end(); ++it) {
        TListSegment local=it->split();
        for (TListSegment::iterator it2=local.begin(); it2 != local.end(); ++it2) {
            list.push_back((*it2));
        }
    }
    return list;
}

TListSquare TAllSegments::squares() const {
    return m_lsq;
}

} // namespace Talios
