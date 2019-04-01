#pragma warning(disable:4996)
#include "Project.h"

bool search(char* a, char* b){
	if(strlen(a)==strlen(b)){
		for(int i=0; i<strlen(a); i++)
			if(a[i]!=b[i])
				return false;
		return true;
	}
	else
		return false;
}


Project::Project(const char* Name, int Budget, int Duration){
	name = new char[strlen(Name) + 1];
	int i = 0;
	for (i = 0; i < strlen(Name); i++)
		name[i] = Name[i];
	name[i] = '\0';
	budget = Budget;
	duration=Duration;
}

Project::Project(const Project& p){
	name = new char[strlen(p.name) + 1];
	int i = 0;
	for (i = 0; i < strlen(p.name); i++)
		name[i] = p.name[i];
	name[i] = '\0';
	budget=p.budget;
	duration=p.duration;
}

ostream& operator<<(ostream& out, const Project& p){
	out<<"Project Name: "<<p.name<<"	";
	out<<"Budget: "<<p.budget<<"	 ";
	out<<"Duration: "<<p.duration<<endl;
	return out;
}

const Project& Project::operator=(const Project& p) {
	name = new char[strlen(p.name) + 1];
	int i = 0;
	for (i = 0; i < strlen(p.name); i++)
		name[i] = p.name[i];
	name[i] = '\0';
	budget = p.budget;
	duration = p.duration;
	return *this;
}

void Project::setBudget(int b){
	budget=b;
}

bool Project::exists(Project const* p)const {
	return search(name, p->name);
}

Project::~Project(){
	delete name;
}