
#include <stdio.h>

#include <talios/TSegment.h>

using namespace Talios; 

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

