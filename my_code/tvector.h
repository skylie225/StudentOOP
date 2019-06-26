#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>
#include <string>
#include <algorithm>




const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

template <typename DATA>
class MyVec {
public:

	MyVec() {
		sz = 0;
		capacity = DEF_CAPACITY;
		data = new DATA[DEF_CAPACITY];
	}

	MyVec(int sz, DATA val) {
		capacity = std::max(DEF_CAPACITY, sz * CAPACITY_MULT);
		data = new DATA[capacity];
		for (int i = 0; i < sz; i++) data[i] = val;
	}

	// copy control:
	//copy constructor
	MyVec(const MyVec<DATA>& v2) {
		capacity = v2.capacity;
		sz = v2.size();
		data = new DATA[capacity];
		for (int i = 0; i < size(); i++) {
			data[i] = v2.data[i];
		}
	}

	//destructor
	~MyVec() {
		delete[] data;
	}


	//assignment operator
	MyVec<DATA>& operator=(const MyVec<DATA>& v2) {
		if (&v2 != this) {
			delete[] data;
			capacity = v2.capacity;
			sz = v2.size();
			data = new DATA[capacity];
			for (int i = 0; i < size(); i++) {
				data[i] = v2.data[i];
			}
		}
		return *this;
	}

	void push_back(DATA val) {
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


	int size() const { 
		return sz; 
	}

	DATA operator[](int i) const {
		return data[i];
	}

	DATA& operator[](int i) {
		return data[i];
	}

private:
	DATA* data;
	int sz;
	int capacity;
};

template <typename DATA>
void print_vector(const MyVec<DATA>& v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}


template <typename DATA>
bool operator==(MyVec<DATA>& v1, MyVec<DATA>& v2) {
	if (v1.size() == v2.size() || (v1 == v2)) {
		return true;
	}
	else {
		return false;
	}
}

#endif