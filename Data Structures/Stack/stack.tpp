template <typename T>
bool Stack<T>::push(T x){
	if(m_top_index + 1 == max_size){
		std::cout<<"Your stack is limited"<<std::endl;
		return 0;
	}
	++m_top_index;
	array[m_top_index] = x;
	return 1;
}

template <typename T>
bool Stack<T>::pop(){
	if(m_top_index == -1){
		std::cout<<"Your stack is initial"<<std::endl;		
		return 0;
	}
	--m_top_index;
	return 1;
}

template <typename T>
T Stack<T>::peek(){
	if(m_top_index == -1){
		std::cout<<"Your stack is initial"<<std::endl;		
		return 0;
	}
	return array[m_top_index];
}

template <typename T>
bool Stack<T>::is_empty(){
	if (m_top_index == -1){
		return 1;
	}
	return 0;
}
