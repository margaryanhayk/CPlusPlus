#pragma once
#include <iostream>

class bestVector
{
public:

	bestVector();
	bestVector(const bestVector& vec);
	bestVector(const int x);
	bestVector& operator=(const bestVector& right_side);
	void push(const int x);
	void print();
	void pop();
	void print_size();

private:

	int cap;
	int size;
	int* buffer;
	void moveSpace();

};
