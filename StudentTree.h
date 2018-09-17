#pragma once
#include "StudentNode.h"
#include <string>

class StudentTree {
private: 
	StudentNode *root; 
	StudentNode* findStudent(StudentNode* r, string first, string last);
	int numofComparisons;
public: 
	StudentTree(); 
	StudentNode* findStudent(string first, string last);
	void addStudent(string fname, string lname, int ID, double grade);
	int getnumofComparisons(); 
};