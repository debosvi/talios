
#include <math.h>

#include <private/TU_square.h>

using namespace Talios;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TSquare_cppunit);

void TSquare_cppunit::setUp() {
}


void TSquare_cppunit::tearDown() {
}

void TSquare_cppunit::integrity() {
	TPoint bl(0.0f,0.0f);
	TPoint br(1.0f,0.0f);
	TPoint tl(0.0f,1.0f);
	TPoint tr(1.0f,1.0f);
	TSquare s1;
	TSquare s2(tl,br);
	TSquare s3(br,tl);
	TSquare s4(tl.x(), tl.y(), br.x(), br.y());
	
    // check s1
    CPPUNIT_ASSERT(s1.tl().x()==0.0f);
    CPPUNIT_ASSERT(s1.tl().y()==0.0f);
    CPPUNIT_ASSERT(s1.br().x()==0.0f);
    CPPUNIT_ASSERT(s1.br().y()==0.0f);
    // check s2
    CPPUNIT_ASSERT(s2.tl()==tl);
    CPPUNIT_ASSERT(s2.br()==br);
    CPPUNIT_ASSERT(s2.tr()==tr);
    CPPUNIT_ASSERT(s2.bl()==bl);
    // check s3
    CPPUNIT_ASSERT(s3.tl()==tl);
    CPPUNIT_ASSERT(s3.br()==br);
    CPPUNIT_ASSERT(s3.tr()==tr);
    CPPUNIT_ASSERT(s3.bl()==bl);
    // check s4
    CPPUNIT_ASSERT(s4.tl()==tl);
    CPPUNIT_ASSERT(s4.br()==br);
    CPPUNIT_ASSERT(s4.tr()==tr);
    CPPUNIT_ASSERT(s4.bl()==bl);
}

void TSquare_cppunit::isIn() {
    TPoint p1(1.0f, 2.0f);
    TPoint p2(10.0f, 2.0f);
    TPoint p3(-0.5f, 2.0f);
    TPoint p4(-0.5001f, 2.0f);
    TPoint p5(-0.4999f, 2.0f);
    TPoint c(1.0f, 2.0f);
    TSquare sq(c, 3.0f);

    _isIn(sq, p1, true);
    _isIn(sq, p2, false);
    _isIn(sq, p3, false);
    _isIn(sq, p4, false);
    _isIn(sq, p5, true);
}

void TSquare_cppunit::split() {
    TPoint c(1.0f, 2.0f);
    TSquare sq(c, 6.0f);
    
    TListSegment ls=sq.split();
    CPPUNIT_ASSERT(ls.size()==4);
}

void TSquare_cppunit::_isIn(const Talios::TSquare& s, const Talios::TPoint& p, const bool check) {
    bool res = s.in(p);
    CPPUNIT_ASSERT(res==check);
}
