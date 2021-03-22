#ifndef _STACK_H
#define _STACK_H

/// <summary>
/// Array-based implementation
/// </summary>
/// <typeparam name="T"></typeparam>

const int max_size = 1000;
template <typename T>
class Stack {
public:
	Stack() = default;
	//Stack(const Stack& rhs);
	~Stack() = default;
public:
	bool push(T x);
	bool pop();
	T peek();
	bool is_empty();
private:
	T array[max_size];
	int m_top_index = -1;
};
#include "stack.tpp"
#endif
