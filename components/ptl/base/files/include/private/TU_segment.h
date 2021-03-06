#ifndef __TALIOS_TSEGMENT_CPPUNIT_H__
#define __TALIOS_TSEGMENT_CPPUNIT_H__

#include <cppunit/extensions/HelperMacros.h>

#include <talios/TSegment.h>

using namespace Talios;

class TSegment_cppunit : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( TSegment_cppunit );
    CPPUNIT_TEST( integrity );
    CPPUNIT_TEST( onto );
    CPPUNIT_TEST( cross );
    CPPUNIT_TEST( surface );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void surface();
    void integrity();
    void onto();
    void cross();
    
private:
    void _surface(const Talios::TSegment& s, const Talios::TPoint& p, const TDecimal check);
	void _cross(const Talios::TSegment& s,const Talios::TSegment& t, const bool check);
};

#endif  // __TALIOS_TSEGMENT_CPPUNIT_H__
