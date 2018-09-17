#include "StudentTree.h"
#include <iostream>
#include <string>

//PRIVATE
StudentNode* StudentTree::findStudent(StudentNode* r, string first, string last) {
	if (r == 0) {
		numofComparisons++;
		return 0;
	}

	if (r->getlastName() == last && r->getfirstName() == first) {
		numofComparisons++;
		return r;
	}
	if (r->getlastName() == last) {
		if (first < r->getfirstName()) {
			r = r->getleft();
			numofComparisons++;
			return findStudent(r, first, last);
		}
		else {
			r = r->getright();
			numofComparisons++;
			return findStudent(r, first, last);
		}
	}
	else {
		if (last < r->getlastName()) {
			r = r->getleft();
			numofComparisons++;
			return findStudent(r, first, last);
		}
		else {
			r = r->getright();
			numofComparisons++;
			return findStudent(r, first, last);
		}
	}
	
	return 0;
}



//PUBLIC
StudentTree :: StudentTree() {
	root = 0; 
	numofComparisons = 0;
}

StudentNode* StudentTree::findStudent(string first, string last) {
	StudentNode* curr = root;
	numofComparisons = 0;
	StudentNode* s = findStudent(curr, first, last);
	if (s) {
		s->printMarks();
		cout << "No. of Comparison: " << numofComparisons << endl << endl;
	}
	else {
		cout << first << " " << last << " not found. Number of Comparisons made: " << numofComparisons << endl << endl;
	}
	
	return s;

}

void StudentTree:: addStudent(string fname, string lname, int ID, double grade) {
	StudentNode* s0 = new StudentNode(grade, fname, lname, ID);
	StudentNode* curr = root; 
	StudentNode* prev = root;
	
		if (root == 0) {
			root = s0;
			return;
		}
		
		while (curr != 0) {
			prev = curr;
			if (curr->getlastName() == s0->getlastName()) {
				if (s0->getfirstName() < curr->getfirstName()) {
					curr = curr->getleft(); 
				}
				else curr = curr->getright();
			}
			else {
				if (s0->getlastName() < curr->getlastName()) {
					curr = curr->getleft(); 
				}
				else curr = curr->getright();
				}
		}

	if (prev->getlastName() == s0->getlastName()) {
		if (s0->getfirstName() < prev->getfirstName()) {
			prev->setleft(s0);
			
		}
		else {
			prev->setright(s0);
			
		}
	}
	else {
		if (s0->getlastName() < prev->getlastName()) {
			prev->setleft(s0);
			
		}
		else {
			prev->setright(s0);
			
		}
	}

	
}

int StudentTree :: getnumofComparisons() {
	return numofComparisons;
}