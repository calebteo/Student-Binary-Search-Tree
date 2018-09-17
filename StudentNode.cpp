#include "StudentNode.h"
using namespace std;

int StudentNode::numStudents = 0; 

StudentNode::StudentNode(double num, string fname, string lname, int n) {
	finalGrade = num; 
	firstName = fname; 
	lastName = lname; 
	left = right = 0; 
	ID = n;
	numStudents++; 
}
void StudentNode::setID(int num) {
	ID = num; 

}
void StudentNode::setName(string name) {
	firstName = name;

}
int StudentNode::getID() {
	return ID;

}
string StudentNode::getfirstName() {
	return firstName; 

}

string StudentNode::getlastName() {
	return lastName;
}

StudentNode* StudentNode::getleft() {
	return left;

}
void StudentNode::setleft(StudentNode* next) {
	left = next;

}

StudentNode* StudentNode::getright() {
	return right;

}
void StudentNode::setright(StudentNode* next) {
	right = next;

}

double StudentNode::getGrade() {
	return finalGrade;

}
void StudentNode::setGrade(int grade) {
	finalGrade = grade;

}
StudentNode::StudentNode(int digits, double num, string name) {
	ID = digits; 
	finalGrade = num;
	firstName = name; 
	left = right = 0;
}
void StudentNode::printMarks() {
	cout << "Student ID: " << ID << endl;
	cout << "Student Name: " << firstName << " " << lastName << endl; 
	cout << "Student Final Grade: " << finalGrade << endl;

}



StudentNode::StudentNode(double num, string fname) {
	finalGrade = num;
	firstName = fname;
	left = right = 0;
	ID = numStudents;
	numStudents++;
}