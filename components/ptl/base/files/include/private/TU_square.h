#ifndef __TALIOS_TSQUARE_CPPUNIT_H__
#define __TALIOS_TSQUARE_CPPUNIT_H__

#include <cppunit/extensions/HelperMacros.h>

#include <talios/TSquare.h>

class TSquare_cppunit : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( TSquare_cppunit );
    CPPUNIT_TEST( isIn );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void isIn();
    
private:
    void _isIn(const Talios::TSquare& s, const Talios::TPoint& p, const bool check);

};

#endif  // __TALIOS_TSQUARE_CPPUNIT_H__
