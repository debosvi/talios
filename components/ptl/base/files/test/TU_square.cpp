
#include <math.h>

#include <private/TU_square.h>

using namespace Talios;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TSquare_cppunit);

void TSquare_cppunit::setUp() {
}


void TSquare_cppunit::tearDown() {
}

void TSquare_cppunit::isIn() {
    TPoint p1(1.0f, 2.0f);
    TPoint p2(10.0f, 2.0f);
    TPoint p3(-0.5f, 2.0f);
    TPoint p4(-0.5001f, 2.0f);
    TPoint p5(-0.4999f, 2.0f);
    TPoint c(1.0f, 2.0f);
    TSquare sq(c, 3.0f);

    _isIn(sq, p1, true);
    _isIn(sq, p2, false);
    _isIn(sq, p3, false);
    _isIn(sq, p4, false);
    _isIn(sq, p5, true);
}

void TSquare_cppunit::split() {
    TPoint c(1.0f, 2.0f);
    TSquare sq(c, 6.0f);
    
    TListSegment ls=sq.split();
    CPPUNIT_ASSERT(ls.size()==4);
}

void TSquare_cppunit::_isIn(const Talios::TSquare& s, const Talios::TPoint& p, const bool check) {
    bool res = s.isIn(p);
    CPPUNIT_ASSERT(res==check);
}
