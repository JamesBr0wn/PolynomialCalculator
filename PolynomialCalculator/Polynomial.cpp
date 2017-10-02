#include "Polynomial.h"
#include "Exception.h"
#include <cstring>
#include <cmath>
using namespace std;

//Done!
Polynomial::Polynomial(vector<pair<int, double> >& poly) {
	myPoly = poly;
}

//Done!
Polynomial Polynomial::operator+(const Polynomial& other)const {
	Polynomial result;
	int j = 0;
	for (int i = 0; i < other.myPoly.size(); i++) {
		while (j < myPoly.size() && myPoly[j].first < other.myPoly[i].first) {
			result.myPoly.push_back(myPoly[j]);
			j++;
		}
		if (j < myPoly.size() && other.myPoly[i].first == myPoly[j].first) {
			pair<int, double> temp;
			temp.first = myPoly[j].first;
			temp.second = myPoly[j].second + other.myPoly[i].second;
			result.myPoly.push_back(temp);
			j++;
		}
		else {
			result.myPoly.push_back(other.myPoly[i]);
		}
	}
	for (int i = j; i < myPoly.size(); i++) {
		result.myPoly.push_back(myPoly[i]);
	}
	return result;
}

//Done!
Polynomial Polynomial::operator-(const Polynomial& other)const {
	Polynomial result;
	int j = 0;
	for (int i = 0; i < other.myPoly.size(); i++) {
		while (j < myPoly.size() && myPoly[j].first < other.myPoly[i].first) {
			result.myPoly.push_back(myPoly[j]);
			j++;
		}
		if (j < myPoly.size() && other.myPoly[i].first == myPoly[j].first) {
			if (myPoly[j].second != other.myPoly[i].second) {
				pair<int, double> temp;
				temp.first = myPoly[j].first;
				temp.second = myPoly[j].second - other.myPoly[i].second;
				result.myPoly.push_back(temp);
			}
			j++;
		}
		else {
			pair<int, double> temp;
			temp.first = other.myPoly[i].first;
			temp.second = -other.myPoly[i].second;
			result.myPoly.push_back(temp);
		}
	}
	for (int i = j; i < myPoly.size(); i++) {
		result.myPoly.push_back(myPoly[i]);
	}
	return result;
}

//Done!
Polynomial Polynomial::operator*(const Polynomial& other)const {
	Polynomial result;
	for (int i = 0; i < myPoly.size(); i++) {
		vector<pair<int, double> > tempVec;
		pair<int, double> tempPair;
		for (int j = 0; j < other.myPoly.size(); j++) {
			tempPair.first = myPoly[i].first + other.myPoly[j].first;
			tempPair.second = myPoly[i].second * other.myPoly[j].second;
			tempVec.push_back(tempPair);
		}
		result = result + Polynomial(tempVec);
	}
	return result;
}

//Done!
Polynomial Polynomial::operator*(double multiCoffic)const {
	Polynomial result;
	result = *this;
	for (int i = 0; i < myPoly.size(); i++) {
		result.myPoly[i].second *= multiCoffic;
	}
	return result;
}

//Done!
const Polynomial& Polynomial::operator=(const Polynomial& other) {
	myPoly = other.myPoly;
	return *this;
}

//Done!
double Polynomial::operator[](int n)const {
	if (n < 0) {
		throw IndexOutOfBoundsException(n);
	}
	for (int i = 0; i < myPoly.size(); i++) {
		if (myPoly[i].first == n) {
			return myPoly[i].second;
		}
	}
	return 0;
}

//Done!
bool Polynomial::operator==(const Polynomial& other) {
	return myPoly == other.myPoly;
}

//Done!
bool Polynomial::operator!=(const Polynomial& other) {
	return myPoly != other.myPoly;
}

//Done!
Polynomial Polynomial::derivative()const {
	Polynomial result;
	if (myPoly.size() == 0) {
		return result;
	}
	for (int i = 0; i < myPoly.size(); i++) {
		if (myPoly[i].first != 0) {
			pair<int, double> temp;
			temp.first = myPoly[i].first - 1;
			temp.second = myPoly[i].first * myPoly[i].second;
			result.myPoly.push_back(temp);

		}
	}
	return result;
}

//Done!
double Polynomial::value(double base)const {
	double result = 0;
	for (int i = 0; i < myPoly.size(); i++) {
		result += myPoly[i].second * pow(base, myPoly[i].first);
	}
	return result;
}

//Done!
bool Polynomial::empty()const {
	return myPoly.empty();
}

//Done!
string Polynomial::printableString()const {
	if (empty()) {
		return string("0");
	}
	stringstream ss;
	for (int i = myPoly.size() - 1; i >= 0; i--) {
		if (i != myPoly.size() - 1 && myPoly[i].second > 0) {
			ss << "+";
		}
		if (myPoly[i].first == 0 || myPoly[i].second != 1) {
			ss << myPoly[i].second;
		}
		if (myPoly[i].first == 0) {}
		else if (myPoly[i].first == 1) {
			ss << "x";
		}
		else {
			ss << "x^" << myPoly[i].first;
		}
	}
	return ss.str();
}

//Done!
Polynomial operator*(int multiCoffic, const Polynomial& poly) {
	return poly.operator*(multiCoffic);
}
