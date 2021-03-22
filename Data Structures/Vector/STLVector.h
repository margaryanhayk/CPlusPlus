#ifndef _STLVECTOR_H

#define _STLVECTOR_H

#include <iostream>
/// <summary>
/// Random access - constant O(1);
/// Insertion or removal of elements at the end - amortized constant O(1);
/// Insertion or removal of elements - O(n);
/// </summary>
/// <typeparam name="T"></typeparam>

template <typename T>
class Vector {

public:

	Vector();
	Vector(const Vector<T>& rhs);
	Vector<T>& operator=(const Vector<T>& rhs);
	T& operator[](int index);
	~Vector();

public:

	int get_size();
	void push_back(const T& element);
	void print();
	void pop_back();
	void insert(int position, const T& element);
	void erase(int position);
	void erase(int pos1, int pos2);
	void clear();
	void swap(Vector<T>& vec);

private:

	int m_current_size;
	int m_cap;
	T* m_start;
	void resize();
	void copy(const Vector<T>& rhs);
};

#include "STLVector.tpp"
#endif
