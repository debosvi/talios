#ifndef __TALIOS_TPOINT_CPPUNIT_H__
#define __TALIOS_TPOINT_CPPUNIT_H__

#include <cppunit/extensions/HelperMacros.h>
#include <talios/TPoint.h>

class TPoint_cppunit : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( TPoint_cppunit );
    CPPUNIT_TEST( length );
    CPPUNIT_TEST( distance_to );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void length();
    void distance_to();
    
private:
    void _length(const TPoint& p1, const TPoint& p2, const float check);

};

#endif  // __TALIOS_TPOINT_CPPUNIT_H__
