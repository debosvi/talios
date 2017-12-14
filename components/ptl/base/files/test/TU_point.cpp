
#include <math.h>

#include <talios/TPoint.h>

using namespace Talios; 

#if 0
static void surface(const TPoint& p1, const TPoint& p2, const TPoint& p3) {
    float surf=TPoint::computeSurface(p1, p2, p3);
    fprintf(stderr, "p1(%0.04f,%0.04f), p2 (%0.04f,%0.04f), p3 (%0.04f,%0.04f) surface (%0.04f)\n", p1.x(), p1.y(), p2.x(), p2.y(), p3.x(), p3.y(), surf);
}

    
int main(void) {
    length(TPoint(0.0f,0.0f), TPoint(0.0f, 1.0f));
    length(TPoint(0.0f,0.0f), TPoint(1.0f, 0.0f));
    length(TPoint(0.0f,0.0f), TPoint(1.0f, 1.0f));
    
    surface(TPoint(0.0f,0.0f), TPoint(0.0f, 1.0f), TPoint(1.0f, 0.0f));
    surface(TPoint(-1.0f,0.0f), TPoint(1.0f, 0.0f), TPoint(0.0f, 1.0f));
    
    return 0;
}
#endif

#include "TU_point.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( TPoint_cppunit );


void TPoint_cppunit::setUp() {}


void TPoint_cppunit::tearDown() {}

void  TPoint_cppunit::length() {
    _length(TPoint(0.0f,0.0f), TPoint(0.0f, 1.0f), 1.0f);
    _length(TPoint(0.0f,0.0f), TPoint(1.0f, 0.0f), 1.0f);
    _length(TPoint(0.0f,0.0f), TPoint(1.0f, 1.0f), 0.707f);
}

void TPoint_cppunit::_length(const TPoint& p1, const TPoint& p2, const float check) {
    float dist=p1.distanceTo(p2);
    CPPUNIT_ASSERT(fabs(dist-check)<C_ERROR_THRESHOLD);    
}
