
#include <stdio.h>

#include <talios/TSegment.h>

using namespace Talios; 

static void test_crossing_1(void) {
    TSegment s1(1.0f, 0.0f, 4.0f, 5.0f);
    TSegment s2(0.0f, 2.0f, 10.0f, 4.0f);
    
    fprintf(stderr, "%s, crossing (CURRENT:%d/EXPECTED:%d)\n", __PRETTY_FUNCTION__, s1.isCrossing(s2), 1);
    
}

static void test_crossing_2(void) {
    TSegment s1(1.0f, 0.0f, 0.0f, 5.0f);
    TSegment s2(0.0f, 2.0f, 10.0f, 4.0f);
    
    fprintf(stderr, "%s, crossing (CURRENT:%d/EXPECTED:%d)\n", __PRETTY_FUNCTION__, s1.isCrossing(s2), 1);
    
}

static void test_crossing_3(void) {
    TSegment s1(1.0f, 0.0f, 2.0f, 4.0f);
    TSegment s2(0.0f, 5.0f, 10.0f, 6.0f);
    
    fprintf(stderr, "%s, crossing (CURRENT:%d/EXPECTED:%d)\n", __PRETTY_FUNCTION__, s1.isCrossing(s2), 0);
    
}

static void test_crossing_4(void) {
    TSegment s1(1.0f, 0.0f, 2.0f, 4.0f);
    TSegment s2(3.0f, 5.0f, 10.0f, 6.0f);
    
    fprintf(stderr, "%s, crossing (CURRENT:%d/EXPECTED:%d)\n", __PRETTY_FUNCTION__, s1.isCrossing(s2), 0);
    
}

static void test_crossing_5(void) {
    TSegment s1(2.0f, 4.0f, 1.0f, 0.0f);
    TSegment s2(3.0f, 5.0f, 10.0f, 6.0f);
    
    fprintf(stderr, "%s, crossing (CURRENT:%d/EXPECTED:%d)\n", __PRETTY_FUNCTION__, s1.isCrossing(s2), 0);
    
}


int main(void) {
    test_crossing_1();
    test_crossing_2();
    test_crossing_3();
    test_crossing_4();
    test_crossing_5();
    
    return 0;
}

