
#include <math.h>

#include <private/TU_point.h>

using namespace Talios;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TPoint_cppunit);

void TPoint_cppunit::setUp() {
}


void TPoint_cppunit::tearDown() {
}

void TPoint_cppunit::length() {
    _length(TPoint(0.0f, 0.0f), TPoint(0.0f, 1.0f), 1.0f);
    _length(TPoint(0.0f, 0.0f), TPoint(1.0f, 0.0f), 1.0f);
    _length(TPoint(0.0f, 0.0f), TPoint(1.0f, 1.0f), sqrt(2));
}

void TPoint_cppunit::_length(const TPoint & p1, const TPoint & p2,
                             const float check) {
    float dist = p1.distanceTo(p2);
    CPPUNIT_ASSERT(fabs(dist - check) < C_ERROR_THRESHOLD);
}

void TPoint_cppunit::distance_to() {
    CPPUNIT_ASSERT(true);
}
