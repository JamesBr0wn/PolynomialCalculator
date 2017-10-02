#pragma once
#ifndef EXCEP_H
#define EXCEP_H
#include <exception>
#include <string>
#include <sstream>
using namespace std;

class IndexOutOfBoundsException : public out_of_range {
public:
	IndexOutOfBoundsException(int n) :out_of_range("Index out of Bounds"), index(n) {}
	string what() {
		stringstream ss;
		ss << "IndexOutOfBoundsException with index " << index;
		return ss.str();
	}
private:
	int index;
};

#endif

