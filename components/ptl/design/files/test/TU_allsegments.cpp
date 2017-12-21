
#include <private/TU_allsegments.h>

using namespace Talios;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TAllSegments_cppunit);

void TAllSegments_cppunit::setUp() {
}


void TAllSegments_cppunit::tearDown() {
}

void TAllSegments_cppunit::reset() {
    m_as.reset();
    _check_count(0);
}

void TAllSegments_cppunit::add_one_elem() {
    TPoint c(1.0f, 2.0f);
    TSquare sq(c, 3.0f);
    
    m_as.addSquare(sq);
    _check_count(1);
}

void TAllSegments_cppunit::add_same_elem() {
    TPoint c(1.0f, 2.0f);
    TSquare sq(c, 3.0f);
    
    m_as.addSquare(sq);
    m_as.addSquare(sq);
    _check_count(1);
}

void TAllSegments_cppunit::add_two_elems() {
    TPoint c1(1.0f, 2.0f);
    TPoint c2(1.1f, 2.0f);
    TSquare sq1(c1, 3.0f);
    TSquare sq2(c1, 3.0001f);
    TSquare sq3(c2, 3.0f);
    
    m_as.addSquare(sq1);
    m_as.addSquare(sq2);
    _check_count(2);
    m_as.addSquare(sq3);
    _check_count(3);
}

void TAllSegments_cppunit::split() {
    TPoint c1(1.0f, 2.0f);
    TPoint c2(1.1f, 2.0f);
    TSquare sq1(c1, 3.0f);
    TSquare sq2(c2, 6.0f);
    
    m_as.addSquare(sq1);
    m_as.addSquare(sq2);
    _check_count(2);
    
    TListSegment ls=m_as.split();
    CPPUNIT_ASSERT(ls.size()==8);
}

void TAllSegments_cppunit::_check_count(const int check) {
    CPPUNIT_ASSERT(m_as.count()==check);
}
