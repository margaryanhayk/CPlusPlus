
template <typename T>
Vector<T>::Vector() :
	current_size{ 0 },
	cap{ 2 },
	start{ new T[cap] }
{}

template <typename T>
void Vector<T>::resize() {
	cap *= 2;
	T* tmp = new T[cap];
	for (int ix = 0; ix < current_size; ++ix) {
		tmp[ix] = start[ix];
	}
	delete[] start;
	start = tmp;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& rhs) {
	this->copy(rhs);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) {
	if (this != &rhs) {
		delete[] this->start;
		this->copy(rhs);
	}
	return *this;
}

template <typename T>
T& Vector<T>::operator[](int index) {
	return this->start[index];
}

template <typename T>
void Vector<T>::copy(const Vector<T>& rhs) {
	this->current_size = rhs.current_size;
	this->cap = rhs.cap;
	this->start = new T[cap];
	for (int ix = 0; ix < current_size; ++ix) {
		this->start[ix] = rhs.start[ix];
	}
}

template <typename T>
void Vector<T>::push_back(const T& element) {
	if (current_size == cap) {
		resize();
	}
	start[current_size] = element;
	++current_size;
}

template <typename T>
void Vector<T>::print() {
	for (int ix = 0; ix < current_size; ++ix) {
		std::cout << start[ix] << std::endl;
	}
}

template <typename T>
Vector<T>::~Vector<T>() {
	for (int ix = 0; ix < current_size; ++ix) {
		start[ix].~T();
	}
	delete[] start;
}

template <typename T>
void Vector<T>::pop_back() {
	if (current_size != 0) {
		--current_size;
		start[current_size].~T();
	}
}

template <typename T>
int Vector<T>::get_size() {
	return current_size;
}

template <typename T>
void Vector<T>::insert(int position, const T& element) {
	if (current_size == cap) {
		cap *= 2;
		T* tmp = new T[cap];
		for (int ix = 0; ix < position; ++ix) {
			tmp[ix] = start[ix];
		}
		tmp[position] = element;
		for (int ix = position + 1; ix < current_size + 1; ++ix) {
			tmp[ix] = start[ix - 1];
		}
		delete[] start;
		start = tmp;
	}
	else {
		for (int ix = current_size; ix > position; --ix) {
			start[ix] = start[ix - 1];
		}
		start[position] = element;
	}
	++current_size;
}

template <typename T>
void Vector<T>::erase(int position) {
	if (position == current_size - 1) {
		pop_back();
		return;
	}
	else if (position > current_size - 1) {
		return;
	}
	else {
		for (int ix = position; ix < current_size - 1; ++ix) {
			start[ix] = start[ix + 1];
		}
		--current_size;
		start[current_size].~T();
	}
}

template <typename T>
void Vector<T>::erase(int pos1, int pos2) {
	if ((pos1 > pos2) || (pos1 > current_size -1) || (pos2 > current_size - 1) ){
		return;
	}
	else if (pos1 == pos2) {
		erase(pos1);
		return;
	}
	else {
		int count_of_erasen_el = pos2 - pos1 + 1;
		for (int ix = pos1; ix < current_size - count_of_erasen_el; ++ix) {
			start[ix] = start[ix + count_of_erasen_el];
		}
		current_size -= count_of_erasen_el;
	}
}

template <typename T>
void Vector<T>::clear() {
	for (int ix = 0; ix < current_size; ++ix) {
		start[ix].~T();
	}
	delete[] start;
	cap = 2;
	current_size = 0;
	start = new T[cap];
}

template <typename T>
void Vector<T>::swap(Vector<T> & vec) {
	int cap_tmp = this->cap;
	int current_size_tmp = this->current_size;
	T* start_tmp = this->start;
	this->cap = vec.cap;
	this->current_size = vec.current_size;
	this->start = vec.start;
	vec.cap = cap_tmp;
	vec.current_size = current_size_tmp;
	vec.start = start_tmp;
}
