#pragma warning(disable:4996)
#include "Employee.h"
#include <cstring>
using namespace std;



Employee::Employee(){
	emp_name=nullptr;
	A=nullptr;
	P=nullptr;
	no_of_projects=0;
}

Employee::Employee(const char*name, const Address& a){
	emp_name = new char[strlen(name) + 1];
	int i = 0;
	for (i = 0; i < strlen(name); i++)
		emp_name[i] = name[i];
	emp_name[i] = '\0';
	
	A=new Address(a);
	P=nullptr;
	no_of_projects=0;
}

Employee::Employee(const Employee& e){
	emp_name = new char[strlen(e.emp_name) + 1];
	int i = 0;
	for (i = 0; i < strlen(e.emp_name); i++)
		emp_name[i] = e.emp_name[i];
	emp_name[i] = '\0';
	if(e.A!=nullptr)
		A=new Address(*e.A);
	else 
		A=nullptr;
	no_of_projects=e.no_of_projects;
	if(e.P!=nullptr){
		P=new Project const*[no_of_projects];
		for(int i=0; i<no_of_projects; i++)
			P[i]=e.P[i];
	}
	else
		P=nullptr;
}

ostream& operator<<(ostream& o, const Employee& e){
	o << endl;
	if(e.emp_name!=nullptr)
		o<<"Employee Name: "<<e.emp_name<<endl;
	if(e.A!=nullptr)
		o<<*e.A;
	if(e.P!=nullptr){
		o<<"Projects: "<<endl;
		for(int i=0; i<e.no_of_projects; i++)
			o<<*e.P[i];
	}
	return o;
}

const Employee& Employee::operator=(const Employee& e){
	emp_name=new char(*e.emp_name);
	if(e.A!=nullptr)
		A=new Address(*e.A);
	else 
		A=nullptr;
	no_of_projects=e.no_of_projects;
	if(e.P!=nullptr){
		P=new Project const *[no_of_projects];
		for(int i=0; i<no_of_projects; i++)
			P[i]=e.P[i];
	}
	else
		P=nullptr;
	return *this;
}

void Employee::addProject(Project const* p){
	if(no_of_projects<2){
		bool exists=false;
		for(int i=0; i<no_of_projects; i++){
			if(p->exists(P[i]))
				exists=true;
		}

		if(!exists){
			Project const ** temp=new Project const *[no_of_projects+1];
			for(int i=0; i<no_of_projects; i++)
				temp[i]=P[i];
			temp[no_of_projects]=p;
			no_of_projects++;
			delete P;
			P=temp;
		}
	}
}

void Employee::removeProject(Project const* p) {
	if (no_of_projects > 0) {
		bool exists = false;
		for (int i = 0; i < no_of_projects; i++) {
			if (p->exists(P[i]))
				exists = true;
		}
		if (exists) {
			Project const** temp = new Project const*[no_of_projects - 1];
			int index = 0;
			for (int i = 0; i < no_of_projects; i++) {
				if (!(P[i]->exists(p))) {
					temp[index] = P[i];
					index++;
				}
			}
			delete P;
			P = temp;
			no_of_projects--;
		}
	}
}
Employee::~Employee() {
	delete emp_name;
	delete A;
	delete P;
}