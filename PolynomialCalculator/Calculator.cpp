#include <cstdio>
#include <cctype>
#include <sstream>
#include "Calculator.h"

using namespace std;

void Calculator::mainProcess() {
	welcomeMenu();
	helpMenu();
	int option;
	getOption(option);
	while (option != 9) {
		callModule(option);
		helpMenu();
		getOption(option);
	}
	cout << "Exiting";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 100000000; j++) {
		}
		cout << ".";
	}
	cout << endl << "Exit successfully!" << endl;
}

void Calculator::welcomeMenu()const {
	cout << "Polynomial Calculator " << "Ver.1.2" << endl;
	cout << "--Made by WuChenkang,SYSU" << endl;
}

void Calculator::helpMenu()const {
	cout << "Func List" << endl;
	cout << "1.Input a polynomial;" << endl;
	cout << "2.Show stored polynomial;" << endl;
	cout << "3.Polynomial adding;" << endl;
	cout << "4.Polynomial subtracting;" << endl;
	cout << "5.Polynomial multiplication with polynomial;" << endl;
	cout << "6.Polynomial comparison;" << endl;
	cout << "7.Polynomial derivation;" << endl;
	cout << "8.Polynomial evaluation;" << endl;
	cout << "9.Exiting system;" << endl;
	cout << "0.Help menu;" << endl;
}

void Calculator::inputPoly() {
	cin.sync();
	string polyName;
	char deal;
	deal = getchar();
	while (deal != '=' && deal != '(' && deal != '\n') {
		polyName = polyName + deal;
		deal = getchar();
	}
	if (deal == '\n') {
		cout << "Invalid input! No polynomial recognized!" << endl;
		return;
	}
	else if (deal == '(' && polyName != string()) {
		cout << "Invalid input! No polynomial recognized!" << endl;
		return;
	}
	else if (deal == '=' && polyName == string()) {
		cout << "Invalid input! No polynomial recognized!" << endl;
		return;
	}
	string poly;
	getline(cin, poly);
	if (deal == '(') {
		poly = deal + poly;
	}
	Polynomial inputPoly(recognizePoly(poly));
	if (inputPoly.empty()) {
		cout << "Invalid input! No polynomial recognized!" << endl;
		return;
	}
	else {
		if (polyName == string()) {
			cout << "Polynomial:	";
			cout << inputPoly.printableString() << endl;
			cout << endl;
			cout << "Store this polynomial? (Y/N)" << endl;
			char option;
			cin >> option;
			if (option != 'y' && option != 'Y') {
				return;
			}
		}
		while (polyName == string() || !nameCheck(polyName)) {
			cout << "Please inpyt a valid polynomial name." << endl;
			polyName = nameInput();
		}
		cout << "Name:	" << polyName << endl;
		cout << "Polynomial:	";
		cout << inputPoly.printableString() << endl;
		putchar('\n');
		cout << "Sure to store this polynomial? (Y/N)" << endl;
		char option;
		cin >> option;
		if (option != 'y' && option != 'Y') {
			return;
		}
		else {
			storePoly(polyName, inputPoly);
			return;
		}
	}
}

void Calculator::polyAdding() {
	string s1, s2;
	Polynomial poly1, poly2;
	cout << "Please enter the first polynomial:" << endl;
	cin >> s1;
	poly1 = recognizePoly(s1);
	while (poly1.empty()) {
		cout << "Not a valid polynomial, please try again!" << endl;
		cin >> s1;
		poly1 = recognizePoly(s1);
	}

	cout << "Please enter the second polynomial" << endl;
	cin >> s2;
	poly2 = recognizePoly(s2);
	while (poly2.empty()) {
		cout << "Not a valid polynomial, please try again!" << endl;
		cin >> s2;
		poly2 = recognizePoly(s2);
	}

	Polynomial result = poly1 + poly2;
	cout << "(" << poly1.printableString() << ") + (" << poly2.printableString() << ") = " << result.printableString() << endl;

	cout << "Do you want to store this result?(Y/N)" << endl;
	char option;
	cin >> option;
	if (option == 'Y' || option == 'y') {
		cout << "Please enter the name of the polynomial" << endl;
		string polyName = nameInput();
		while (!nameCheck(polyName)) {
			cout << "Please enter a valid polynomial name!" << endl;
			polyName = nameInput();
		}
		storePoly(polyName, result);
	}
	else {
		return;
	}
}

void Calculator::polySubtracting() {
	string s1, s2;
	Polynomial poly1, poly2;
	cout << "Please enter the first polynomial:" << endl;
	cin >> (s1);
	poly1 = recognizePoly(s1);
	while (poly1.empty()) {
		cout << "Not a valid polynomial, please try again!" << endl;
		cin >> s1;
		poly1 = recognizePoly(s1);
	}

	cout << "Please enter the second polynomial" << endl;
	cin >> s2;
	poly2 = recognizePoly(s2);
	while (poly2.empty()) {
		cout << "Not a valid polynomial, please try again!" << endl;
		cin >> s2;
		poly2 = recognizePoly(s2);
	}

	Polynomial result = poly1 - poly2;
	cout << "(" << poly1.printableString() << ") - (" << poly2.printableString() << ") = " << result.printableString() << endl;

	cout << "Do you want to store this result?(Y/N)" << endl;
	char option;
	cin >> option;
	if (option == 'Y' || option == 'y') {
		cout << "Please enter the name of the polynomial" << endl;
		string polyName = nameInput();
		while (!nameCheck(polyName)) {
			cout << "Please enter a valid polynomial name!" << endl;
			polyName = nameInput();
		}
		storePoly(polyName, result);
	}
	else {
		return;
	}
}

void Calculator::polyMultipleWithConst() {
	string s;
	Polynomial poly;
	double consT;

	cout << "Please enter the const" << endl;
	cin >> consT;

	cout << "Please enter the polynomial:" << endl;
	cin >> s;
	poly = recognizePoly(s);
	while (poly.empty()) {
		cout << "Not a valid polynomial, please try again!" << endl;
		cin >> s;
		poly = recognizePoly(s);
	}

	Polynomial result = consT * poly;
	cout << consT << " * ";
	cout << poly.printableString();
	cout << " = ";
	cout << result.printableString() << endl;

	cout << "Do you want to store this result?(Y/N)" << endl;
	char option;
	cin >> option;
	if (option == 'Y' || option == 'y') {
		cout << "Please enter the name of the polynomial" << endl;
		string polyName = nameInput();
		while (!nameCheck(polyName)) {
			cout << "Please enter a valid polynomial name!" << endl;
			polyName = nameInput();
		}
		storePoly(polyName, result);
	}
	else {
		return;
	}
}

void Calculator::calculateValue() {
	string s;
	Polynomial poly;
	double x;

	cout << "Please enter the value of x!" << endl;
	cin >> x;

	cout << "Please enter the polynomial:" << endl;
	cin >> s;
	poly = recognizePoly(s);
	while (poly.empty()) {
		cout << "Not a valid polynomial, please try again!" << endl;
		cin >> s;
		poly = recognizePoly(s);
	}

	cout << "Polynomial:	";
	cout << poly.printableString() << endl;
	cout << "Value(x = " << x << "):	" << poly.value(x) << endl;

}

void Calculator::showStoredPoly() {
	cout << "Stored polynomial:" << endl;
	map<string, Polynomial>::iterator iter;
	for (iter = storedPoly.begin(); iter != storedPoly.end(); iter++) {
		cout << "Name:	" << iter->first << endl;
		cout << "Polynomial:	";
		cout << iter->second.printableString() << endl;
		cout << endl;
	}
}

void Calculator::polyMultipleWithPoly() {
	string s1, s2;
	Polynomial poly1, poly2;
	cout << "Please enter the first polynomial:" << endl;
	cin >> s1;
	poly1 = recognizePoly(s1);
	while (poly1.empty()) {
		cout << "Not a valid polynomial, please try again!" << endl;
		cin >> s1;
		poly1 = recognizePoly(s1);
	}

	cout << "Please enter the second polynomial" << endl;
	cin >> s2;
	poly2 = recognizePoly(s2);
	while (poly2.empty()) {
		cout << "Not a valid polynomial, please try again!" << endl;
		cin >> s2;
		poly2 = recognizePoly(s2);
	}

	Polynomial result = poly1 * poly2;
	cout << "(" << poly1.printableString() << ")*(" << poly2.printableString() << ") = " << result.printableString() << endl;

	cout << "Do you want to store this result?(Y/N)" << endl;
	char option;
	cin >> option;
	if (option == 'Y' || option == 'y') {
		cout << "Please enter the name of the polynomial" << endl;
		string polyName = nameInput();
		while (!nameCheck(polyName)) {
			cout << "Please enter a valid polynomial name!" << endl;
			polyName = nameInput();
		}
		storePoly(polyName, result);
	}
	else {
		return;
	}
}

void Calculator::polyCompare() {
	string s1, s2;
	Polynomial poly1, poly2;
	cout << "Please enter the first polynomial:" << endl;
	cin >> s1;
	poly1 = recognizePoly(s1);
	while (poly1.empty()) {
		cout << "Not a valid polynomial, please try again!" << endl;
		cin >> s1;
		poly1 = recognizePoly(s1);
	}

	cout << "Please enter the second polynomial" << endl;
	cin >> s2;
	poly2 = recognizePoly(s2);
	while (poly2.empty()) {
		cout << "Not a valid polynomial, please try again!" << endl;
		cin >> s2;
		poly2 = recognizePoly(s2);
	}

	cout << poly1.printableString();
	cout << " and ";
	cout << poly2.printableString();
	cout << " are ";
	if (poly1 != poly2) {
		cout << "not ";
	}
	cout << "equal." << endl;
	return;
}

void Calculator::polyDerivation() {
	string s;
	Polynomial poly;
	cout << "Please enter the polynomial:" << endl;
	cin >> s;
	poly = recognizePoly(s);
	while (poly.empty()) {
		cout << "Not a valid polynomial, please try again!" << endl;
		cin >> s;
		poly = recognizePoly(s);
	}

	Polynomial result = poly.derivative();
	cout << "Polynomial:	";
	cout << poly.printableString() << endl;
	cout << "Derivative:	";
	cout << result.printableString() << endl;

	cout << "Do you want to store this result?(Y/N)" << endl;
	char option;
	cin >> option;
	if (option == 'Y' || option == 'y') {
		cout << "Please enter the name of the polynomial" << endl;
		string polyName = nameInput();
		while (!nameCheck(polyName)) {
			cout << "Please enter a valid polynomial name!" << endl;
			polyName = nameInput();
		}
		storePoly(polyName, result);
	}
	else {
		return;
	}
}

void Calculator::getOption(int & option) {
	cin.sync();
	cin >> option;
	while (cin.fail() || getchar() != '\n' || option < 0 || option > 9) {
		cout << "Invalid option, please try again!" << endl;
		cin.clear();
		cin.sync();
		cin >> option;
	}
}

void Calculator::callModule(int option) {
	switch (option) {
	case 1:
		cout << "Func 1" << endl;
		inputPoly();
		break;
	case 2:
		cout << "Func 2" << endl;
		showStoredPoly();
		break;
	case 3:
		cout << "Func 3" << endl;
		polyAdding();
		break;
	case 4:
		cout << "Func 4" << endl;
		polySubtracting();
		break;
	case 5:
		cout << "Func 5" << endl;
		polyMultipleWithPoly();
		break;
	case 6:
		cout << "Func 6" << endl;
		polyCompare();
		break;
	case 7:
		cout << "Func 7" << endl;
		polyDerivation();
		break;
	case 8:
		cout << "Func 8" << endl;
		calculateValue();
		break;
	case 0:
		cout << "Func 0" << endl;
		helpMenu();
		break;
	default:
		break;
	}
}

void Calculator::storePoly(string polyName, const Polynomial& poly) {
	storedPoly[polyName] = poly;
	cout << "Name:	" << polyName << endl;
	cout << "Polynomial:	";
	cout << poly.printableString();
	putchar('\n');
}

inline Polynomial Calculator::recognizePoly(string poly) {
	if (nameCheck(poly)) {
		map<string, Polynomial>::iterator iter;
		for (iter = storedPoly.begin(); iter != storedPoly.end(); iter++) {
			if (poly == iter->first) {
				return iter->second;
			}
		}
		return Polynomial();
	}
	else {
		stringstream in(poly);
		int pow;
		double coffic;
		vector<pair<int, double> > poly;
		char deal;
		while ((in >> deal)) {
			if (deal != '(') {
				return Polynomial();
			}
			in >> coffic;
			in >> deal;
			if (deal != ',') {
				return Polynomial();
			}
			in >> pow;
			in >> deal;
			if (deal != ')') {
				return Polynomial();
			}
			poly.push_back(pair<int, double>(pow, coffic));

		}
		return Polynomial(poly);
	}
}

string Calculator::nameInput() {
	cout << "*A valid polynomial name should have 1 to 8 characters*" << endl;
	cout << "*with the first character a letter  and others numbers*" << endl;
	cout << "*or letters.                                          *" << endl;
	string result;
	cin >> result;
	while (!nameCheck(result)) {
		cout << "Invaild polynomial name, please try again!" << endl;
		cin >> result;
	}
	return result;
}

bool Calculator::nameCheck(string name) {
	if (name.length() == 0 || name.length() > 8) {
		return false;
	}
	if (!isalpha(name[0])) {
		return false;
	}
	for (int i = 1; i < name.length(); i++) {
		if (!isalpha(name[i]) && !isdigit(name[i])) {
			return false;
		}
	}
	return true;
}

