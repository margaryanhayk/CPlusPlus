#include <iostream>
#include "Header.h"

bestVector::bestVector() {
	cap = 5;
	size = 0;
	buffer = new int[cap];
}
bestVector::bestVector(const bestVector& vec) {
	size = vec.size;
	cap = vec.cap;
	buffer = new int[vec.cap];
	for (int i = 0; i < size; ++i) {
		buffer[i] = vec.buffer[i];
	}
}
bestVector::bestVector(const int x) {
	cap = 5;
	size = 1;
	buffer = new int[cap];
	buffer[0] = x;
}
bestVector& bestVector::operator=(const bestVector& right_side) {
	if (this != &right_side) {
			delete[] buffer;
			size = right_side.size;
			cap = right_side.cap;
			buffer = new int[right_side.cap];
			for (int i = 0; i < size; ++i) {
				buffer[i] = right_side.buffer[i];
			}
	}
	return *this;
}
void bestVector::moveSpace() {
	cap *= 2;
	int* new_ptr = new int[cap];
	for (int i = 0; i < size; ++i) {
		new_ptr[i] = buffer[i];
	}
	delete[] buffer;
	buffer = new_ptr;
} 
void bestVector::push(const int x) {
	if(size==cap) { moveSpace();}
	buffer[size++] = x;
}
void bestVector::print() {
	for (int i = 0; i < size; ++i) {
		std::cout << buffer[i] << std::endl;
	}
}
void bestVector::pop() {
	if (size != 0) {
		--size;
	}
}
void bestVector::print_size() {
	std::cout<< size<<std::endl;
}

