//Address.h
#pragma warning(disable:4996)
#include <iostream>
using namespace std;


#ifndef ADDRESS_H
#define ADDRESS_H
class Address
{
	char* house_Number;
	char* street_Name ;
	char * city;
	char* country;

public:
	Address(const char* hn, const char* sn, const char * City, const char* Country);
	// an overloaded constructor
	Address(const Address&);
	//copy constructor
	friend ostream& operator<<(ostream& osObject, const Address&);
	//overloaded insertion operator
	const Address &   operator=(const Address& other);
	//overloaded assignment operator
	~Address();
};
#endif