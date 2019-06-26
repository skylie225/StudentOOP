#include <iostream>
#include "tvector.h"

using namespace std;
template <typename DATA>
void print_vector(const MyVec<DATA>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename DATA>
MyVec<DATA>::MyVec() {
	sz = 0;
	capacity = DEF_CAPACITY;
	data = new int[DEF_CAPACITY];
}

template <typename DATA>
MyVec<DATA>::MyVec(const MyVec<DATA>& v2) {
	capacity = v2.capacity;
	sz = v2.size();
	data = new int[capacity];
	for (int i = 0; i < size(); i++) {
		data[i] = v2.data[i];
	}
}

template <typename DATA>
MyVec<DATA>::~MyVec() {
	delete[] data;
}

template <typename DATA>
MyVec<DATA>& MyVec<DATA>::operator=(const MyVec<DATA>& v2) {
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
template <typename DATA>
bool operator==(MyVec<DATA>& v1, MyVec<DATA>& v2) {
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

template <typename DATA>
void MyVec<DATA>::push_back(DATA val) {
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
template <typename DATA>
DATA MyVec<DATA>::operator[](DATA i) const {
	return data[i];
}



/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
template <typename DATA>
DATA& MyVec<DATA>::operator[](DATA i) {
	return data[i];
}