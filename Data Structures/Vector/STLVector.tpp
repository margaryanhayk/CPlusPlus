template <typename T>
Vector<T>::Vector() :
	m_current_size{ 0 },
	m_cap{ 2 },
	m_start{ new T[m_cap] }
{}

template <typename T>
void Vector<T>::resize() {
	m_cap *= 2;
	T* tmp = new T[m_cap];
	for (int ix = 0; ix < m_current_size; ++ix) {
		tmp[ix] = m_start[ix];
	}
	delete[] m_start;
	m_start = tmp;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& rhs) {
	this->copy(rhs);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) {
	if (this != &rhs) {
		delete[] this->m_start;
		this->copy(rhs);
	}
	return *this;
}

template <typename T>
T& Vector<T>::operator[](int index) {
	return this->m_start[index];
}

template <typename T>
void Vector<T>::copy(const Vector<T>& rhs) {
	this->m_current_size = rhs.m_current_size;
	this->m_cap = rhs.m_cap;
	this->m_start = new T[m_cap];
	for (int ix = 0; ix < m_current_size; ++ix) {
		this->m_start[ix] = rhs.m_start[ix];
	}
}

template <typename T>
void Vector<T>::push_back(const T& element) {
	if (m_current_size == m_cap) {
		resize();
	}
	m_start[m_current_size] = element;
	++m_current_size;
}

template <typename T>
void Vector<T>::print() {
	for (int ix = 0; ix < m_current_size; ++ix) {
		std::cout << m_start[ix] << std::endl;
	}
}

template <typename T>
Vector<T>::~Vector<T>() {
	delete[] m_start;
}

template <typename T>
void Vector<T>::pop_back() {
	if (m_current_size != 0) {
		--m_current_size;
	}
}

template <typename T>
int Vector<T>::get_size() {
	return m_current_size;
}

template <typename T>
void Vector<T>::insert(int position, const T& element) {
	if (m_current_size == m_cap) {
		m_cap *= 2;
		T* tmp = new T[m_cap];
		for (int ix = 0; ix < position; ++ix) {
			tmp[ix] = m_start[ix];
		}
		tmp[position] = element;
		for (int ix = position + 1; ix < m_current_size + 1; ++ix) {
			tmp[ix] = m_start[ix - 1];
		}
		delete[] m_start;
		m_start = tmp;
	}
	else {
		for (int ix = m_current_size; ix > position; --ix) {
			m_start[ix] = m_start[ix - 1];
		}
		m_start[position] = element;
	}
	++m_current_size;
}

template <typename T>
void Vector<T>::erase(int position) {
	if (position == m_current_size - 1) {
		pop_back();
		return;
	}
	else if (position > m_current_size - 1) {
		return;
	}
	else {
		for (int ix = position; ix < m_current_size - 1; ++ix) {
			m_start[ix] = m_start[ix + 1];
		}
		--m_current_size;
	}
}

template <typename T>
void Vector<T>::erase(int pos1, int pos2) {
	if ((pos1 > pos2) || (pos1 > m_current_size - 1) || (pos2 > m_current_size - 1)) {
		return;
	}
	else if (pos1 == pos2) {
		erase(pos1);
		return;
	}
	else {
		int count_of_erasen_el = pos2 - pos1 + 1;
		for (int ix = pos1; ix < m_current_size - count_of_erasen_el; ++ix) {
			m_start[ix] = m_start[ix + count_of_erasen_el];
		}
		m_current_size -= count_of_erasen_el;
	}
}

template <typename T>
void Vector<T>::clear() {
	delete[] m_start;
	m_cap = 2;
	m_current_size = 0;
	m_start = new T[m_cap];
}

template <typename T>
void Vector<T>::swap(Vector<T>& vec) {
	int m_cap_tmp = this->m_cap;
	int m_current_size_tmp = this->m_current_size;
	T* m_start_tmp = this->m_start;
	this->m_cap = vec.m_cap;
	this->m_current_size = vec.m_current_size;
	this->m_start = vec.m_start;
	vec.m_cap = m_cap_tmp;
	vec.m_current_size = m_current_size_tmp;
	vec.m_start = m_start_tmp;
}
