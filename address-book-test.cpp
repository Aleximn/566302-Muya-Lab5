#include "address-book.h"
#include "Person.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Original is Independent Of Copy using copy constructor") {

	Person Alex{"Alexis",22};
	AddressBookEntry myEntry1 {Alex,"Image.png"};
	AddressBookEntry myEntry2 {myEntry1};
	//Change Person details of myEntry1
	Person Alexander{"Alexander",23};
	myEntry1.setPerson(Alexander);
    //Expect no Change in details of myEntry2
	CHECK_FALSE(myEntry1.getPerson().name() == myEntry2.getPerson().name());
	CHECK_FALSE(myEntry1.getPerson().age() == myEntry2.getPerson().age());
    //Change the image of myEntry1
	myEntry1.setImageName( "NewImage.png");
    //Expect no change in myEntry2 image
	CHECK_FALSE(myEntry1.getImageName() == myEntry2.getImageName());
}
TEST_CASE("Original is Independent Of Copy using assignment") {

	Person Alex{"Alexis",22};
	AddressBookEntry myEntry1 {Alex,"Image.png"};
	AddressBookEntry myEntry2 = myEntry1 ;
	//Change Person details of myEntry1
	Person Alexander{"Alexander",23};
	myEntry1.setPerson(Alexander);
    //Expect no Change in details of myEntry2
	CHECK_FALSE(myEntry1.getPerson().name() == myEntry2.getPerson().name());
	CHECK_FALSE(myEntry1.getPerson().age() == myEntry2.getPerson().age());
    //Change the image of myEntry1
	myEntry1.setImageName( "NewImage.png");
    //Expect no change in myEntry2 image
	CHECK_FALSE(myEntry1.getImageName() == myEntry2.getImageName());
}