
#include <math.h>

#include <private/TU_segment.h>

using namespace Talios;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TSegment_cppunit);

void TSegment_cppunit::setUp() {
}


void TSegment_cppunit::tearDown() {
}

void TSegment_cppunit::surface() {
    _surface(TSegment(0.0f, 0.0f, 2.0f, 0.0f), TPoint(1.0f, 1.0f), 1.0f);
}

void TSegment_cppunit::integrity() {
    TPoint p(0.0f,1.0f);
    TPoint q(0.0f,1.0f);
    TSegment s1(p,q);
    TSegment s2(q,p);
    TSegment s3;
    TSegment s4(0.0f, 1.0f, 1.0f, 1.0f);
    TSegment s5(1.0f, 1.0f, 0.0f, 1.0f);
    CPPUNIT_ASSERT(s1.p()==p);
    CPPUNIT_ASSERT(s2.p()==q);
    CPPUNIT_ASSERT(s3.p().x()==0.0f);
    CPPUNIT_ASSERT(s4.p().x()==0.0f);
    CPPUNIT_ASSERT(s5.p().x()==0.0f);
}

void TSegment_cppunit::onto() {
    TPoint zero;
    TPoint p(0.0f,0.1f);
    TPoint q(0.0f,1.0f);
    TPoint r(0.0f,2.0f);
    TSegment s1(p,q);
    CPPUNIT_ASSERT(TSegment::onSegment(p,zero,r)==false);
    CPPUNIT_ASSERT(TSegment::onSegment(p,q,r)==true);
    CPPUNIT_ASSERT(TSegment::onSegment(p,p,q)==true);
    CPPUNIT_ASSERT(TSegment::onSegment(p,q,q)==true);
}

void TSegment_cppunit::cross() {
    _cross(TSegment(1.0f, 0.0f, 4.0f, 5.0f), TSegment(0.0f, 2.0f, 10.0f, 4.0f), 1);
    _cross(TSegment(1.0f, 0.0f, 0.0f, 5.0f), TSegment(0.0f, 2.0f, 10.0f, 4.0f), 1);
    _cross(TSegment(1.0f, 0.0f, 2.0f, 4.0f), TSegment(0.0f, 5.0f, 10.0f, 6.0f), 0);
    _cross(TSegment(1.0f, 0.0f, 2.0f, 4.0f), TSegment(3.0f, 5.0f, 10.0f, 6.0f), 0);
    _cross(TSegment(2.0f, 4.0f, 1.0f, 0.0f), TSegment(3.0f, 5.0f, 10.0f, 6.0f), 0);
    _cross(TSegment(0.0f, 0.0f, 1.0f, 0.0f), TSegment(1.0f, 0.0f, 1.0f, 1.0f), 0);
    _cross(TSegment(0.0f, 0.0f, 1.0f, 0.0f), TSegment(1.0f, 0.0f, 1.0f, -1.0f), 0);
}

void TSegment_cppunit::_cross(const Talios::TSegment& s,const Talios::TSegment& t, const bool check) {
    bool res=s.cross(t);
    CPPUNIT_ASSERT(res==check);
}

void TSegment_cppunit::_surface(const Talios::TSegment& s, const Talios::TPoint& p, const TDecimal check) {
    TDecimal res = s.surface(p);
    CPPUNIT_ASSERT(fabs(res - check) < C_ERROR_THRESHOLD);
}

