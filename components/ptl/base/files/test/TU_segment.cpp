
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

void TSegment_cppunit::_surface(const Talios::TSegment& s, const Talios::TPoint& p, const float check) {
    float res = s.surface(p);
    CPPUNIT_ASSERT(fabs(res - check) < C_ERROR_THRESHOLD);
}


#if 0

static void test_crossing(const TSegment &s1, const TSegment& s2, const bool expected) {
    fprintf(stderr, "crossing (CURRENT:%d/EXPECTED:%d)\n", s1.isCrossing(s2), expected);
}

int main(void) {
	TSegment s1;
    test_crossing(TSegment(1.0f, 0.0f, 4.0f, 5.0f), TSegment(0.0f, 2.0f, 10.0f, 4.0f), 1);
    test_crossing(TSegment(1.0f, 0.0f, 0.0f, 5.0f), TSegment(0.0f, 2.0f, 10.0f, 4.0f), 1);
    test_crossing(TSegment(1.0f, 0.0f, 2.0f, 4.0f), TSegment(0.0f, 5.0f, 10.0f, 6.0f), 0);
    test_crossing(TSegment(1.0f, 0.0f, 2.0f, 4.0f), TSegment(3.0f, 5.0f, 10.0f, 6.0f), 0);
    test_crossing(TSegment(2.0f, 4.0f, 1.0f, 0.0f), TSegment(3.0f, 5.0f, 10.0f, 6.0f), 0);
    
    return 0;
}

#endif
