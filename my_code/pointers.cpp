#include <iostream>
#include "pointers.h"

using namespace std;

void inc_by_value(int n) {
	++n;
}


void inc_with_pointer(int* iptr) {
	++(*iptr);
}


void inc_with_reference(int& n) {
	++n;
}


Thing** create_array_of_things(int n) {
	Thing** new_array = new Thing*[n];
	for (int i = 0; i < n; i++) {
		new_array[i] = new Thing(i);
	}
    return new_array;
}

void print_all_things(Thing** things, int n) {
	for (int i = 0; i < n; i++) {
		cout << things[i]-> val << " ";
	}
	cout << endl;
}

void double_all_things(Thing** things, int n) {
	for (int i = 0; i < n; i++) {
		things[i]->val *= 2;
	}
}

void delete_all_things(Thing** things, int n) {
	for (int i = 0; i < n; i++) {
		delete things[i];
	}
	delete[] things;
}


void assignTA(Student* s, Student* ta) {
	s->ta = ta;
}

void printTAs(vector<Student*>& students) {
	for (Student* student : students) {
		if (student->ta == nullptr) {
			cout << student->name << " has no TA " << endl;
		}
		else {
			cout << student->name << " has a TA " << student->ta->name << endl;
		}
	}
}

