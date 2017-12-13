
#include <stdio.h>

#include <talios/TPoint.h>

using namespace Talios; 

static void surface(const TPoint& p1, const TPoint& p2, const TPoint& p3) {
    float surf=TPoint::computeSurface(p1, p2, p3);
    fprintf(stderr, "p1(%0.04f,%0.04f), p2 (%0.04f,%0.04f), p3 (%0.04f,%0.04f) surface (%0.04f)\n", p1.x(), p1.y(), p2.x(), p2.y(), p3.x(), p3.y(), surf);
}

static void length(const TPoint& p1, const TPoint& p2) {
    float dist=p1.distanceTo(p2);
    fprintf(stderr, "p1(%0.04f,%0.04f) to p2 (%0.04f,%0.04f) distance (%0.04f)\n", p1.x(), p1.y(), p2.x(), p2.y(), dist);
    
}
    
int main(void) {
    length(TPoint(0.0f,0.0f), TPoint(0.0f, 1.0f));
    length(TPoint(0.0f,0.0f), TPoint(1.0f, 0.0f));
    length(TPoint(0.0f,0.0f), TPoint(1.0f, 1.0f));
    
    surface(TPoint(0.0f,0.0f), TPoint(0.0f, 1.0f), TPoint(1.0f, 0.0f));
    surface(TPoint(-1.0f,0.0f), TPoint(1.0f, 0.0f), TPoint(0.0f, 1.0f));
    
    return 0;
}

