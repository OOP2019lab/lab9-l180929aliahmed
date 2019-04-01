#pragma warning(disable:4996)
#include <iostream>
using namespace std;

#ifndef PROJECT_H
#define PROJECT_H
class Project
{
	char* name;
	int budget;
	int duration; //estimate duration of project in weeks

public: 
	Project(const char* Name, int Budget, int Duration);
	// an overloaded constructor
	Project(const Project&);
	//copy constructor
	friend ostream& operator<<(ostream& osObject, const Project&);
	//overloaded insertion operator
	const Project & operator=(const Project& other);
	//overloaded assignment operator
	void setBudget(int); 
	bool exists(Project const*)const;
	~Project();
}; 
#endif	