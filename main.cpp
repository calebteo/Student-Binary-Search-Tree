/*
Abraham CRONIN - 19
Collin BREE - 15
Etienne HOLOHAN - 21
, AAAA - 10
, ZZZZ - 9
*/

#include "StudentTree.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

void main() {
	ifstream inputFile; 
	inputFile.open("Studentdata.txt"); 
	StudentTree list; 
	string last, first, fsearch, lsearch; 
	int ID; 
	double grade;
	

	for (int i = 0; i < 10000; i++) {

		inputFile >> last >> first >> ID >> grade;
		list.addStudent(first, last, ID, grade);
	}

	cout << "Enter Student to find (or end with zz zz): "; 
	cin >> fsearch >> lsearch; 
	cout << endl;

	while (fsearch != "zz" && lsearch != "zz") {
		
		if (!list.findStudent(fsearch, lsearch)) {
			//cout << "Not found. Number of Comparisons made: " << list.getnumofComparisons() << endl << endl;
		}
		cout << "Enter Student to find (or end with zz zz): ";
		cin >> fsearch >> lsearch;
		cout << endl;
	}
	

	list.findStudent("Abraham", "CRONIN");
	list.findStudent("Collin", "BREE");
	list.findStudent("Etienne", "HOLOHAN");
	list.findStudent("", "AAAA");
	list.findStudent("", "ZZZZ");
	system("pause");
	inputFile.close(); 
}