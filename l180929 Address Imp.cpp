#pragma warning(disable:4996)
#include "Address.h"


Address::Address(const char* hn, const char* sn, const char * City, const char* Country){
	house_Number = new char[strlen(hn)+1];
	street_Name = new char[strlen(sn) + 1];
	city = new char[strlen(City) + 1];
	country = new char[strlen(Country) + 1];
	int i = 0;
	for (i = 0; i < strlen(hn); i++)
		house_Number[i] = hn[i];
	house_Number[i] = '\0';
	for (i = 0; i < strlen(sn); i++)
		street_Name[i] = sn[i];
	street_Name[i] = '\0';
	for (i = 0; i < strlen(City); i++)
		city[i] = City[i];
	city[i] = '\0';
	for (i = 0; i < strlen(Country); i++)
		country[i] = Country[i];
	country[i] = '\0';
}

Address::Address(const Address& a){
	house_Number = new char[strlen(a.house_Number) + 1];
	street_Name = new char[strlen(a.street_Name) + 1];
	city = new char[strlen(a.city) + 1];
	country = new char[strlen(a.country) + 1];
	int i = 0;
	for (i = 0; i < strlen(a.house_Number); i++)
		house_Number[i] = a.house_Number[i];
	house_Number[i] = '\0';
	for (i = 0; i < strlen(a.street_Name); i++)
		street_Name[i] = a.street_Name[i];
	street_Name[i] = '\0';
	for (i = 0; i < strlen(a.city); i++)
		city[i] = a.city[i];
	city[i] = '\0';
	for (i = 0; i < strlen(a.country); i++)
		country[i] = a.country[i];
	country[i] = '\0';
}

ostream& operator<<(ostream& out, const Address& a){
	out<<"Address: ";
	out<<a.house_Number<<", "<<a.street_Name<<", "<<a.city<<", "<<a.country<<endl;
	return out;
}

const Address& Address::operator=(const Address& a){
	house_Number = new char[strlen(a.house_Number) + 1];
	street_Name = new char[strlen(a.street_Name) + 1];
	city = new char[strlen(a.city) + 1];
	country = new char[strlen(a.country) + 1];
	int i = 0;
	for (i = 0; i < strlen(a.house_Number); i++)
		house_Number[i] = a.house_Number[i];
	house_Number[i] = '\0';
	for (i = 0; i < strlen(a.street_Name); i++)
		street_Name[i] = a.street_Name[i];
	street_Name[i] = '\0';
	for (i = 0; i < strlen(a.city); i++)
		city[i] = a.city[i];
	city[i] = '\0';
	for (i = 0; i < strlen(a.country); i++)
		country[i] = a.country[i];
	country[i] = '\0';
	return *this;
}

Address::~Address(){
	delete house_Number;
	delete street_Name;
	delete city;
	delete country;
}