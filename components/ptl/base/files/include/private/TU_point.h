#ifndef __TALIOS_TPOINT_CPPUNIT_H__
#define __TALIOS_TPOINT_CPPUNIT_H__

#include <cppunit/extensions/HelperMacros.h>

#include <talios/TPoint.h>

using namespace Talios;

class TPoint_cppunit : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( TPoint_cppunit );
    CPPUNIT_TEST( distance );
    CPPUNIT_TEST( orientation );
    CPPUNIT_TEST( surface );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void distance();
    void orientation();
    void surface();
    
private:
    void _distance(const Talios::TPoint& p1, const Talios::TPoint& p2, const TDecimal check);
    void _orientation(const Talios::TPoint& p1, const Talios::TPoint& p2, const Talios::TPoint& p3, const int check);
    void _surface(const Talios::TPoint& p1, const Talios::TPoint& p2, const Talios::TPoint& p3, const TDecimal check);
};

#endif  // __TALIOS_TPOINT_CPPUNIT_H__
