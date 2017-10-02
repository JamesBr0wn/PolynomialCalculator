#pragma once
#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
public:
	//Constructor of the class Polynomial
	Polynomial::Polynomial() {}
	Polynomial(vector<pair<int, double> >& poly);

	//The operator overloading of polynomial adding subtracting and multipling
	Polynomial operator+(const Polynomial&)const;
	Polynomial operator-(const Polynomial&)const;
	Polynomial operator*(const Polynomial&)const;
	Polynomial operator*(double multiCoffic)const;

	//The overloading of operator "=" on the polynomial class 
	const Polynomial& operator=(const Polynomial&);

	//The overloading of operator "[]" to get the cofficient for power i of the polynomial class 
	double operator[](int i)const;

	//The operator overloading to judge whether two polynomials are equal
	bool operator==(const Polynomial&);
	bool operator!=(const Polynomial&);

	Polynomial derivative()const;	//The function to calculate the derivative of the polynomial
	double value(double base)const;	//The function to calculate the value of the polynomial in a particular point
	bool empty()const;	//The function to judge whether the polynomial is a zero polynomial
	string printableString()const;	//The function to return a printable string representing this polynomial
private:
	vector<pair<int, double> > myPoly;	//The array to store the cofficients of the polynomial
};

//The operator overloading to calculate a polynomial multiple a constant value
Polynomial operator*(int multiCoffic, const Polynomial&);

#endif 
