
#include "MyIntArray.h"
#include <iostream>

MyIntArray::MyIntArray() {
		cap = 5;
		current_size = 0;
		pi = new int[5];
	}
MyIntArray::MyIntArray(const int x) {
	cap = x;
	current_size = 0;
	pi = new int[x];
}
MyIntArray::MyIntArray(const MyIntArray& rightSide) {
	copyFrom(rightSide);
}
MyIntArray& MyIntArray::operator=(const MyIntArray& rightSide) {
	if (this != &rightSide) {
		if (current_size != 0) {
			delete[]pi;
		}
		copyFrom(rightSide);
	}
	return *this;
}
void MyIntArray::copyFrom(const MyIntArray& rightSide) {
	cap = rightSide.cap;
	current_size = rightSide.current_size;
	pi = new int[cap];
	for (int i = 0; i < current_size; ++i) {
		pi[i] = rightSide.pi[i];
	}
}
	void MyIntArray::push_back(int value) {
		if (current_size < cap) {
			pi[current_size++] = value;
		}
		else {
			MoveToBigSpace();
			pi[current_size++] = value;
		}
	}
	void MyIntArray::MoveToBigSpace() {
		cap *= 2;
		int* pi_copy = new int[cap];
		for (int i = 0; i < current_size; ++i) {
			pi_copy[i] = pi[i];
		}
		delete[] pi;
		pi = pi_copy;
	}
	void MyIntArray::myprint() {
		for (int i = 0; i < current_size; ++i) {
			std::cout << pi[i] << std::endl;
		}
	}
	void MyIntArray::pop_back() {
		if (current_size > 0) {
			--current_size;
		}
	}
