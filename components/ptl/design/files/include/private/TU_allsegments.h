#ifndef __TALIOS_TALLSEGMENTS_CPPUNIT_H__
#define __TALIOS_TALLSEGMENTS_CPPUNIT_H__

#include <cppunit/extensions/HelperMacros.h>

#include <talios/TAllSegments.h>

using namespace Talios;

class TAllSegments_cppunit : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( TAllSegments_cppunit );
    CPPUNIT_TEST( reset );
    CPPUNIT_TEST( add_one_elem );
    CPPUNIT_TEST( add_same_elem );
    CPPUNIT_TEST( add_two_elems );
    CPPUNIT_TEST( split );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void reset();
    void add_one_elem();
    void add_same_elem();
    void add_two_elems();
    void split();
    
private:
    void _check_count(const int check);
    
    TAllSegments m_as;    
};

#endif  // __TALIOS_TALLSEGMENTS_CPPUNIT_H__
