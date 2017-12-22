
#include <math.h>

#include <private/TU_point.h>

using namespace Talios;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TPoint_cppunit);

void TPoint_cppunit::setUp() {
}


void TPoint_cppunit::tearDown() {
}

void TPoint_cppunit::distance() {
    _distance(TPoint(0.0f, 0.0f), TPoint(0.0f, 1.0f), 1.0f);
    _distance(TPoint(0.0f, 0.0f), TPoint(1.0f, 0.0f), 1.0f);
    _distance(TPoint(0.0f, 0.0f), TPoint(1.0f, 1.0f), sqrt(2));
}

void TPoint_cppunit::orientation() {
    _orientation(TPoint(0.0f, 0.0f), TPoint(0.0f, 1.0f), TPoint(0.0f, 2.0f), TPoint::ORIENT_COLINEAR);
    _orientation(TPoint(0.0f, 0.0f), TPoint(0.0f, 1.0f), TPoint(0.0f, 1.0f), TPoint::ORIENT_COLINEAR);
    _orientation(TPoint(0.0f, 0.0f), TPoint(1.0f, 1.0f), TPoint(1.0f, 1.0f), TPoint::ORIENT_COLINEAR);
    _orientation(TPoint(0.0f, 0.0f), TPoint(1.0f, 1.0f), TPoint(2.0f, 2.0f), TPoint::ORIENT_COLINEAR);
    _orientation(TPoint(0.0f, 0.0f), TPoint(1.0f, 0.0f), TPoint(2.0f, 0.0f), TPoint::ORIENT_COLINEAR);
    _orientation(TPoint(0.0f, 0.0f), TPoint(2.0f, 0.0f), TPoint(1.0f, -1.0f), TPoint::ORIENT_CLOCKWISE);
    _orientation(TPoint(0.0f, 0.0f), TPoint(2.0f, 0.0f), TPoint(1.0f, 1.0f), TPoint::ORIENT_ANTI_CLOCKWISE);
}

void TPoint_cppunit::surface() {
    _surface(TPoint(0.0f, 0.0f), TPoint(0.0f, 1.0f), TPoint(0.0f, 2.0f), 0.0f);
    _surface(TPoint(0.0f, 0.0f), TPoint(0.0f, 2.0f), TPoint(1.0f, 0.0f), 1.0f);
    _surface(TPoint(0.0f, 0.0f), TPoint(2.0f, 0.0f), TPoint(0.0f, 1.0f), 1.0f);
    _surface(TPoint(0.0f, 0.0f), TPoint(1.0f, 1.0f), TPoint(1.0f, 0.0f), 1.0f/2.0f);
    _surface(TPoint(-1.0f, 1.0f), TPoint(1.0f, 1.0f), TPoint(0.0f, -1.0f), 2.0f);
}

void TPoint_cppunit::_distance(const TPoint &p1, const TPoint &p2, const TDecimal check) {
    TDecimal res = p1.distanceTo(p2);
    CPPUNIT_ASSERT(fabs(res - check) < C_ERROR_THRESHOLD);
}

void TPoint_cppunit::_orientation(const TPoint &p1, const TPoint &p2, const TPoint &p3, const int check) {
    TDecimal res = TPoint::orientation(p1, p2, p3);
    CPPUNIT_ASSERT(res==check);
}

void TPoint_cppunit::_surface(const TPoint &p1, const TPoint &p2, const TPoint &p3, const TDecimal check) {
    TDecimal res = TPoint::surface(p1, p2, p3);
    CPPUNIT_ASSERT(fabs(res - check) < C_ERROR_THRESHOLD);
}
