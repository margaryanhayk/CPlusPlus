#pragma once
class MyIntArray {
public:
	MyIntArray();
	MyIntArray(const int x);
	MyIntArray(const MyIntArray& rightSide);
	MyIntArray& operator=(const MyIntArray& rightSide);
	void push_back(int value);
	void myprint();
	void pop_back();
private:
	void MoveToBigSpace();
	void copyFrom(const MyIntArray& rightSide);
private:
	int cap;
	int current_size;
	int* pi;
};
