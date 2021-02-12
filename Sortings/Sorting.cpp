#include <iostream>
#include <vector>

void BubbleSort(int arr[], int length) {
	//complecity is n(n-1)/2
	bool check;
	for (int i = length - 1; i > 0; --i) {
		check = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				check = 1;
			}
		}
		if (!check) {
			return;
		}
	}
}

void SelectionSort(int arr[], int length) {
	for (int i = 0; i < length - 1; ++i) {
		int min_value = arr[i];
		int min_index = i;
		for (int j = i+1; j < length ; ++j) {
			if (arr[j] < min_value) {
				min_value = arr[j];
				min_index = j;
			}
		}
		std::swap(arr[i], arr[min_index]);
	}
}

void InsertionSort(int arr[], int length) {
	for (int i = 1; i < length; ++i) {
		int current_value = arr[i];
		int j = i - 1; 
		while ( j >= 0) {
			if ((current_value < arr[j]) && (j != 0)) {
				arr[j + 1] = arr[j];
				--j;
			}
			else if ((current_value < arr[j]) && (j == 0)) {
				arr[j+1] = arr[j];
				arr[j] = current_value;
				--j;
			}
			else {
				arr[j + 1] = current_value;
				break;
			}
		}
	}
}

void print(int arr[], int length) {
	for (int i = 0; i < length; ++i) {
		std::cout << arr[i]<< " ";
	}
	std::cout<<""<<std::endl;
}

void  MergeVector(std::vector<int> & arr, int l, int m, int r){
	std::vector<int> left;
	std::vector<int> right;
	for (int i = l; i <= m; ++i) {
		left.push_back(arr[i]);
	}
	for (int i = m +1; i <= r; ++i) {
		right.push_back(arr[i]);
	}
	int i = 0, j = 0;
	while  (i <= m - l&& j  < r-m) {
		if (left[i] < right[j]) {
			arr[l + i + j] = left[i];
			++i;
		}
		else {
			arr[l +  i + j] = right[j];
			++j;
		}
	}
	while (j < r-m) {
		arr[l + i + j] = right[j];
		++j;
	}
	while (i + l <= m) {
		arr[l + i + j] = left[i];
		++i;
	}
}

void  MergeSortVector(std::vector<int> & arr, int l, int r) {
	if (l >=r) {
		return;
	}
	else {
		int m =(r + l) / 2;
		MergeSortVector(arr, l, m);
		MergeSortVector(arr, m + 1, r);
		MergeVector(arr, l, m, r);;
	}
}

int PartitionForQuickSort(std::vector<int>& arr, int l, int r) {
	int pivot = arr[r-1];
	int i = l, j = r - 2;
	while (i < j) {
		while ((arr[i] < pivot) && (i < j)) {
			++i;
		}
		while ((arr[j] > pivot) && (i < j)) {
			--j;
		}
		if (i != j) {
			std::swap(arr[i], arr[j]);
			++i, --j;
		}
	}
	if (i == j &&  arr[i] < pivot) {
		++i;
	}
	std::swap(arr[i], arr[r-1]);
	return i;
}

void QuickSortVector(std::vector<int> & arr, int l, int r) {
	if (l < r) {
		int m = PartitionForQuickSort(arr, l, r);
		QuickSortVector(arr, l, m);
		QuickSortVector(arr, m+1, r);
	}
	else {
		return;
	}
}
