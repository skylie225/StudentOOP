#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}


MyVec::MyVec() {
	sz = 0;
	capacity = DEF_CAPACITY;
	data = new int[DEF_CAPACITY];
}

MyVec::MyVec(const MyVec& v2) {
	capacity = v2.capacity;
	sz = v2.size();
	data = new int[capacity];
	for (int i = 0; i < size(); i++) {
		data[i] = v2.data[i];
	}
}

MyVec::~MyVec() {
	delete[] data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
	if (&v2 != this) {
		delete[] data;
		capacity = v2.capacity;
		sz = v2.size();
		data = new int[capacity];
		for (int i = 0; i < size(); i++) {
			data[i] = v2.data[i];
		}
	}
	return *this;
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
	if (v1.size() == v2.size() || (v1 == v2)) {
		return true;
	}
	else {
		return false;
	}
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
	if (sz == capacity) {
			// increase capacity*2

			capacity *= 2;
			int* new_data = new int[capacity];

			//copy over existing data

			for (int i = 0; i < size(); i++) {
				new_data[i] = data[i];
			}

		// delete old array

		delete[] data;

		// set pointer to a new array

		data = new_data;
	}
	data[sz++] = val;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
	return data[i];
}



/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
	return data[i];
}


// WITH ITERATOR

//
//#include <iostream>
//#include <algorithm>
//#include "vector.h"
//
//using namespace std;
//
//void print_vector(const MyVec& v) {
//	for (int i : v) cout << i << " ";
//	cout << endl;
//}
//
//
//MyVec::MyVec() : sz(0) {
//	capacity = DEF_CAPACITY;
//	data = new int[DEF_CAPACITY];
//}
//
//
//MyVec::MyVec(int sz, int val) {
//	capacity = max(DEF_CAPACITY, sz * CAPACITY_MULT);
//	data = new int[capacity];
//	for (int i = 0; i < sz; i++) data[i] = val;
//}
//
//
//MyVec::MyVec(const MyVec& v2) {
//	copy(v2);
//}
//
//MyVec::~MyVec() {
//	delete[] data;
//}
//
//MyVec& MyVec::operator=(const MyVec& v2) {
//	if (this != &v2) {
//		delete[] data;
//		copy(v2);
//	}
//	return *this;
//}
//
//MyVec::Iterator MyVec::begin() const {
//	return MyVec::Iterator(data);
//}
//
//MyVec::Iterator MyVec::end() const {
//	return MyVec::Iterator(data + size());
//}
//
//
///*
// * == is true when every element of the vectors are the same in
// * the same order. (Thus they must be the same size.)
// * */
//bool operator==(MyVec& v1, MyVec& v2) {
//	return true;
//}
//
///*
// * Puts an element at the back of a vector.
// * */
//void MyVec::push_back(int val) {
//	sz++;
//	if (sz > capacity) {
//		cout << "Increasing capacity\n";
//		int* old_data = data;
//		data = new int[capacity * CAPACITY_MULT];
//		for (int i = 0; i < sz; i++) {
//			data[i] = old_data[i];
//		}
//		capacity *= CAPACITY_MULT;
//		delete[] old_data;
//	}
//	data[sz - 1] = val;
//}
//
///*
// * this [] is for reading items from the MyVec:
// * It returns the i-th element.
// * */
//int MyVec::operator[](int i) const {
//	return data[i];
//}
//
///*
// * this [] allows write access to items in the MyVec:
// * It returns a reference to the i-th element.
// * */
//int& MyVec::operator[](int i) {
//	return data[i];
//}
//
//void MyVec::copy(const MyVec& v2) {
//	sz = v2.sz;
//	capacity = v2.capacity;
//	data = new int[capacity];
//	for (int i = 0; i < sz; i++) {
//		data[i] = v2.data[i];
//	}
//}
