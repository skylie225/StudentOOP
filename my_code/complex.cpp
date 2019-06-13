#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

Complex::Complex(double real, double imag) : real(real), imag(imag) {};

bool operator== (const Complex& c1, const Complex& c2) {
	return (c1.get_real() == c2.get_real()) && (c1.get_imag() == c2.get_imag());
    //return (abs(c1.get_real() - c2.get_real())<0.001) && (abs(c1.get_imag() - c2.get_imag())<0.001);  // temp!
}

ostream& operator<< (ostream& os, const Complex& c) {
	os << setprecision(10) << c.real << showpos << c.imag << "i" << endl;
	return os;
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
	cin >> c.real >> c.imag; 
	return is;
}


Complex::operator bool() const {
	return (real != 0 || imag != 0);
}

Complex& Complex::operator++() {
	++real;
	return *this;
}

Complex Complex::operator++(int dummy) {
	Complex temp = *this;
	real++;
	return temp;
}

Complex& Complex::operator--() {
	--real;
	return *this;
}

Complex Complex::operator--(int dummy) {
	Complex temp = *this;
	real--;
	return temp;
}

Complex Complex::operator-=(const Complex& c) {
	real -= c.get_real();
	imag -= c.get_imag();
	return *this;
}

Complex operator+(const Complex& c1, const Complex& c2) {
	Complex comp_sum = Complex(c1.get_real() + c2.get_real(), c1.get_imag() + c2.get_imag());
	return comp_sum;
}

Complex operator-(const Complex& c1, const Complex& c2) {
	Complex comp_minus = Complex(c1.get_real() - c2.get_real(), c1.get_imag() - c2.get_imag());
	return comp_minus;
}

double Complex::get_real() const {
	return real;
}

double Complex::get_imag() const {
	return imag;
}

Complex Complex::operator*(const int i) {
	Complex scalar_prod(real * i, imag * i);
	return scalar_prod;
}

