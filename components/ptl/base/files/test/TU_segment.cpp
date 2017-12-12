
#include <stdio.h>

#include <talios/TSegment.h>

using namespace Talios; 

static void test_noncrossing_colinear(void) {
    TSegment s1(0.0f, 0.0f, 10.0f, 0.0f);
    TSegment s2(0.0f, 1.0f, 10.0f, 1.0f);
    
    fprintf(stderr, "%s, crossing (%d)\n", __PRETTY_FUNCTION__, s1.isCrossing(s2));
    
}

static void test_noncrossing_endscommon(void) {
    TSegment s1(0.001f, 0.0f, 10.0f, 0.0f);
    TSegment s2(0.0f, 0.0f, 0.0f, 5.0f);
    
    fprintf(stderr, "%s, crossing (%d)\n", __PRETTY_FUNCTION__, s1.isCrossing(s2));
    
}

static void test_noncrossing(void) {
    TSegment s1(0.0f, 0.0f, 10.0f, 0.0f);
    TSegment s2(5.0f, 1.0f, 5.0f, 5.0f);
    
    fprintf(stderr, "%s, crossing (%d)\n", __PRETTY_FUNCTION__, s1.isCrossing(s2));
    
}

static void test_crossing(void) {
    TSegment s1(0.0f, 0.0f, 10.0f, 0.0f);
    TSegment s2(5.0f, -5.0f, 5.0f, 5.0f);
    
    fprintf(stderr, "%s, crossing (%d)\n", __PRETTY_FUNCTION__, s1.isCrossing(s2));
    
}

int main(void) {
    test_noncrossing();
    test_noncrossing_colinear();
    test_noncrossing_endscommon();
    test_crossing();
    
    return 0;
}

