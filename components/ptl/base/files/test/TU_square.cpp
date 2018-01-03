
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

    TSquare s2(tl,br);
	TSquare s3(br,tl);
	TSquare s4(tl.x(), tl.y(), br.x(), br.y());
	
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
    TPoint c(1.0f, 2.0f);
    TDecimal size=3.0f;
    TSquare sq(c, size);

    TPoint p1(c);
    TPoint p2(10.0f, 2.0f);
    TPoint p3(sq.tl().x(), sq.tl().y());
    TPoint p4(sq.tl().x()-0.0001f, sq.tl().y()-0.001f);
    TPoint p5(sq.tl().x()+0.0001f, sq.tl().y()-0.001f);

    _isIn(sq, p1, true, "test 1");
    _isIn(sq, p2, false, "test 2");
    _isIn(sq, p3, false, "test 3");
    _isIn(sq, p4, false, "test 4");
    _isIn(sq, p5, true, "test 5");
}

void TSquare_cppunit::split() {
    TPoint c(1.0f, 2.0f);
    TSquare sq(c, 6.0f);
    
    TListSegment ls=sq.split();
    CPPUNIT_ASSERT(ls.size()==4);
}

void TSquare_cppunit::_isIn(const Talios::TSquare& s, const Talios::TPoint& p, const bool check, const std::string& msg) {
    fprintf(stderr, "%s: msg(%s)\n", __PRETTY_FUNCTION__, msg.c_str());	
    bool res = s.in(p);
    CPPUNIT_ASSERT_MESSAGE(msg, res==check);
}
