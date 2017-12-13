
#include <stdio.h>

#include <talios/TPoint.h>

using namespace Talios; 
    
int main(void) {
    TPoint src, dest(1.0f, 10.0f);
    
    float dist=src.x(1.0f).distanceTo(dest);
    
    fprintf(stderr, "src (%0.02f,%0.02f)\n", src.x(), src.y());
    fprintf(stderr, "dest (%0.02f,%0.02f)\n", dest.x(), dest.y());
    fprintf(stderr, "src to dest distance (%0.02f)\n", dist);
    
    
    
    return 0;
}

