#include <iostream>

struct Node {
	int s_data;
	Node* next;
};

class LinkedList {
private:
	Node* start;
	int size;
public:
	LinkedList();
	LinkedList(int data);
	int getSize();
	void push_back(int data);
	void print();
	void pop_back();
	int find(int value);
	bool insert(int index, int value);
};
