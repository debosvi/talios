
#include <stdio.h>

#include <talios/TSquare.h>

using namespace Talios; 



int main(void) {
    TSquare sq1;
    TPoint c(1.0f, 2.0f);
    TPoint p1(1.0f, 2.0f);
    TPoint p2(10.0f, 2.0f);
    TSquare sq2(c, 3.0f);
    
    fprintf(stderr, "p1 is in square (CURRENT:%d, EXPECTED:%d)\n", sq2.isIn(p1), 1);
    fprintf(stderr, "p2 is in square (CURRENT:%d, EXPECTED:%d)\n", sq2.isIn(p2), 0);
    
    
    return 0;
}

