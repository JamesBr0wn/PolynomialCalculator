#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <map>
#include <string>
#include "Polynomial.h"

class Calculator {
public:
	/*The main process of the calculator
	used for obtaining options from user and call related functions*/
	void mainProcess();
private:
	map<string, Polynomial> storedPoly;	//A map used to store polynomials

	void welcomeMenu()const;	//Print one piece of welcome message when the program is launched
	void helpMenu()const;		//Print the help menu including the functions of the calculator

	void inputPoly();				//The module to input a polynomial
	void polyAdding();				//The module to add up two polynomial 
	void polySubtracting();			//The module to sustract one polynomia from another
	void polyMultipleWithConst();	//The module to multiple a polynomial by a constant value
	void calculateValue();			//The module to calculate the value of a polynomial in a particular point
	void showStoredPoly();			//The module to show all stored polynomials

	void polyMultipleWithPoly();	//The sub module to multiple a polynomial with another
	void polyCompare();				//The sub module to compare whether tow polynomials are equal
	void polyDerivation();			//The sub module to calculate the derivation of a polynomial

	void getOption(int& option);
	void callModule(int option);
	void storePoly(string, const Polynomial&);	//A background service called to store a polynomial with a particular name
	inline Polynomial recognizePoly(string);	//A background service called to translate a string to a valid polynomial
	string nameInput();			//A background service to obtain a valid polynomial name from the user
	bool nameCheck(string);		//A background service to judge whether a polynomial name is valid
};
#endif
