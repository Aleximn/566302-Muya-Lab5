// address_book.cpp
// Implementation of the AddressBookEntry class
#include "address-book.h"
#include <memory>
using std::make_shared;

// AddressBookEntry Constructor
AddressBookEntry::AddressBookEntry(	const Person& person,
								   const string& image_filename)
								   :_person(person)
{
	// dynamically allocate memory for the image
	if (image_filename != "") {
		// ignore (for now) what will happen if there is a memory allocation failure
        _image_ptr = make_shared<Image>(image_filename);
	}
}

string AddressBookEntry::getImageName() const
{
	if (_image_ptr != nullptr)
		return _image_ptr->name();
	else return "No image!";
}

void AddressBookEntry::setImageName(string newname)
{
	if (_image_ptr != nullptr) _image_ptr->name(newname);
}
///Exercice 4.3
AddressBookEntry::AddressBookEntry(const AddressBookEntry& rhs):_person(rhs._person)
{
    if(rhs._image_ptr != nullptr)
        _image_ptr.reset(new Image(rhs.getImageName()));
}
///Exercice 4.4
AddressBookEntry& AddressBookEntry::operator=(const AddressBookEntry& rhs)
{
	//Create a temporary
	AddressBookEntry temp{rhs};
	//Swap data members
	swap(temp);

	return *this;
}
void AddressBookEntry::swap(AddressBookEntry& tmp)
{
	//swap name and age
    std::swap(_person,tmp._person);

    if(tmp._image_ptr != nullptr)
        _image_ptr.swap(tmp._image_ptr);
}
