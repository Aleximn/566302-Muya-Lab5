#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


//checks that day month and year are all the same
TEST_CASE("Test compiler copy constructor, incrementing original date doesn't affect the copy")
{
	Date date1(10,Month::January, 1992);
	Date date2(10,Month::January, 1992);
	//calls copy constructor
    Date date3{date2};
	//check if equal
	
    CHECK(date1 == date3);
	CHECK(date2 == date3); // original date and it's copy
	//increment date2 shouldn't affect date3
	date2.IncrementDate();
	
    CHECK(date1 == date3);
	CHECK_FALSE(date2 == date3); // original date and it's copy
}
TEST_CASE("Test compiler copy constructor, incrementing copy date doesn't affect the original date")
{
	Date date1(10,Month::January, 1992);
	Date date2(10,Month::January, 1992);
	//calls copy constructor
    Date date3{date2};
	//check if equal
	
    CHECK(date1 == date3);
	CHECK(date2 == date3); // original date and it's copy
	//increment date3 shouldn't affect date2
	date3.IncrementDate();
	
    CHECK_FALSE(date1 == date3);
	CHECK_FALSE(date2 == date3); // original date and it's copy
}