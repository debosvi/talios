
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <cstdio>

#include <talios/TAllSegments.h>

using namespace std;
using namespace Talios;

static char* iname=0;
static TAllSegments squares;

/******************************************************************************/
/******************************************************************************/
static void usage(char *prog) {
	fprintf(stderr, "%s input_file\n", prog);
	exit(EXIT_FAILURE);
}

/******************************************************************************/
/******************************************************************************/
static int get_conf() {
	int _ret=0;
	ifstream infile(iname);
	
	while (infile) {
		int type=-1;
		int step=0;
		int count=0;
		TDecimal cx,cy;
		TDecimal larg;
		string s;
    	if (!getline( infile, s )) break;

    	istringstream ss( s );

    	while (ss && (step>=0) && (step<100)) {
	      	string s;
      		if (!getline( ss, s, ',' )) break;
      		switch(step) {
      		case 0: // square type
      			if(!s.compare("c")) { type=0; step=1; count++; }
      			else step=-1;
      			break;
      			
      		case 1: // centre x
      			cx=stof(s);
      			step=2;
      			count++;
      			break;
      			
      		case 2: // centre y
      			cy=stof(s);
      			step=3;
      			break;
      			
      		case 3: // largeur 
      			larg=stof(s);
      			step=100;
      			count++;
      			break;
      		}
      		
    	}

    	if(step==100) {
    		if(type==0) {
    			if(count==3) {
    				squares.addSquare(TSquare(TPoint(cx,cy), larg));
    			}
    		}
    	}
  	}
  	
  	if (!infile.eof()) _ret=1;
  	return _ret;
}

/******************************************************************************/
/******************************************************************************/
static TListSegment split_all(TListSegment& in) {
	TListSegment out=in;
    unsigned count=0;
	
	while(1) {
		bool changed=0;
		for (TListSegment::iterator it=out.begin(); it != out.end(); ++it) {
			for (TListSegment::iterator it2=std::next(it,1); it2 != out.end(); ++it2) {
				TPoint p=(*it2).intersection(*it);
				if(p.valid()==true) {
					TSegment s1(it->p(), p);
					TSegment s2(it->q(), p);
					TSegment s3(it2->p(), p);
					TSegment s4(it2->q(), p);
					out.remove(*it);
					out.remove(*it2);
					out.push_back(s1);
					out.push_back(s2);
					out.push_back(s3);
					out.push_back(s4);
					changed=1;
					break;
				}
			}
			if(changed) break;
		}		
		count++;
		if(!changed) break;
	}
	
	return out;
}

/******************************************************************************/
/******************************************************************************/
static TListSegment remove_internal(TListSegment& in) {
	TListSegment out=in;
    	
	return out;
}

/******************************************************************************/
/******************************************************************************/
int main(int argc, char **argv) {
	if(argc<2) usage(argv[0]);
	
	iname=argv[1];
	
	if(get_conf()) exit(EXIT_FAILURE);
	
	fprintf(stderr, "nb squares (%d)\n", squares.count());	
	TListSegment allsegs=squares.split();
	fprintf(stderr, "\noriginal nb segments (%d)\n", allsegs.size());	
	
	for (TListSegment::iterator it=allsegs.begin(); it != allsegs.end(); ++it) {
		TPoint p=it->p();
		TPoint q=it->q();
		
		fprintf(stderr, "segment from (%0.04f,%0.04f) to (%0.04f,%0.04f)\n", p.x(), p.y(), q.x(), q.y());
	}
	
	TListSegment splitsegs=split_all(allsegs);
	
	fprintf(stderr, "\nsplit nb segments (%d)\n", splitsegs.size());	
	
	for (TListSegment::iterator it=splitsegs.begin(); it != splitsegs.end(); ++it) {
		TPoint p=it->p();
		TPoint q=it->q();
		
		fprintf(stderr, "segment from (%0.04f,%0.04f) to (%0.04f,%0.04f)\n", p.x(), p.y(), q.x(), q.y());
	}
	
	TListSegment finalsegs=remove_internal(splitsegs);
	
	fprintf(stderr, "\nsplit nb segments (%d)\n", finalsegs.size());	
	
	for (TListSegment::iterator it=finalsegs.begin(); it != finalsegs.end(); ++it) {
		TPoint p=it->p();
		TPoint q=it->q();
		
		fprintf(stderr, "segment from (%0.04f,%0.04f) to (%0.04f,%0.04f)\n", p.x(), p.y(), q.x(), q.y());
	}
	
    exit(EXIT_SUCCESS);
}
