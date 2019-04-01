#pragma warning(disable:4996)
#include <iostream>
#include "Address.h"
#include "Project.h"

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee
{
	char* emp_name; 
	//Add Data Members here
	Address* A;
	Project const ** P;
	int no_of_projects;
	
public:
	Employee();
	Employee(const char* name, const Address&);
	//overloaded constructor
	Employee(const Employee&);
	//copy constructor
	friend ostream& operator<<(ostream& osObject, const Employee&);
	//overloaded insertion operator
	const Employee &   operator=(const Employee& p);
	//overloaded assignment operator

	void addProject(Project const * );
	void removeProject(Project const * ); 

	~Employee();

}; 
#endif