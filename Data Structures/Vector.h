#pragma once
#include <iostream>
/// <summary>
/// Random access - constant O(1);
/// Insertion or removal of elements at the end - amortized constant O(1);
/// Insertion or removal of elements - O(n);
/// </summary>
/// <typeparam name="T"></typeparam>

template <typename T>
class Vector {
private:
	int current_size;
	int cap;
	T* start;
	void resize();
	void copy(const Vector<T>& rhs);
public:
	Vector();
	Vector(const Vector<T>& rhs);
	Vector<T>& operator=(const Vector<T>& rhs);
	T& operator[](int index);
	void push_back(const T& element);
	void print();
	void pop_back();
	int get_size();
	void insert(int position, const T& element);
	void erase(int position);
	void erase(int pos1, int pos2);
	void clear();
	void swap(Vector<T> & vec);
	~Vector();

};

#include "STLVector.tpp"
