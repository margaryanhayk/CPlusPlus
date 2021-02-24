#pragma once
#include "LinkedList.h"

LinkedList::LinkedList() {
	start = nullptr;
	size = 0;
}

LinkedList::LinkedList(int data) {
	Node* newNode = new Node;
	newNode->s_data = data;
	newNode->next = nullptr;
	start = newNode;
	size = 1;
}

int LinkedList::getSize() {
	return size;
}

void LinkedList::push_back(int data) {
	Node* newNode = new Node;
	newNode->s_data = data;
	newNode->next = nullptr;
	if (size == 0) {
		start = newNode;
		++size;
	}
	else {
		Node* tmp = start;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
		++size;
	}
}

void LinkedList::print() {
	if (size) {
		Node* tmp = start;
		while (tmp->next != nullptr) {
			std::cout << tmp->s_data << std::endl;
			tmp = tmp->next;
		}
		std::cout << tmp->s_data << std::endl;
	}
}

void LinkedList::pop_back() {
	if (start == nullptr) {
		return;
	}
	else if (size == 1) {
		delete start;
		start = nullptr;
		size = 0;
	}
	else {
		int k = 1;
		Node* tmp = start;
		while (k != size - 1) {
			tmp = tmp->next;
			++k;
		}
		Node* tmp2 = tmp;
		tmp2 = tmp2->next;
		delete tmp2;
		tmp->next = nullptr;
		--size;
	}
}

int LinkedList::find(int value) {
	Node* tmp = start;
	int index = 0;
	while (tmp->next != nullptr) {
		++index;
		if (tmp->s_data == value) {
			return index;
		}
		else {
			tmp = tmp->next;
		}
	}
	++index;
	if (tmp->s_data == value) {
		return index;
	}
	else {
		return 0;
	}
}

bool LinkedList::insert(int index, int value) {
	if (index > size + 1) {
		return 0;
	}
	else if (index == size + 1) {
		push_back(value);
		return 1;
	}
	else if (index == 0) {
		return 0;
	}
	else {
		int _index = 1;
		Node* new_node = new Node;
		new_node->s_data = value;
		Node* tmp = start;
		if (_index == index) {
			Node* tmp1 = start;
			start = new_node;
			new_node->next = tmp1;
			++size;
			return 1;
		}
		while (_index != index - 1) {
			tmp = tmp->next;
			++_index;
		}
		Node* tmp1 = tmp->next;
		tmp->next = new_node;
		new_node->next = tmp1;
		++size;
		return 1;
	}
}



