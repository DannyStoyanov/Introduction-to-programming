#include<iostream>
bool isPowerOfTwo(int number) {
	if (number != 0 && (number & (number - 1)) == 0) {
		return true;
	}
	return false;
}
int* allocateArray(int size)
{
	return new (std::nothrow) int[size];
}
void fillArray(int*& arr, unsigned size) {
	for (unsigned i = 0; i < size; i++)
	{
		do {
			std::cin >> arr[i];
		} while (arr[i] < 2 || arr[i]>256 || !isPowerOfTwo(arr[i]));
	}
}
int* readArray(unsigned& len) {
	unsigned size;
	do {
		std::cin >> size;
	} while (size < 4 || size>1024);
	int* arr = allocateArray(size);
	if (!arr) {
		return nullptr;
	}
	fillArray(arr, size);
	len = size;
	return arr;
}
int findIndexMaxElement(int*& arr, unsigned size) {
	int max = 0;
	for (unsigned i = 1; i < size; i++)
	{
		if (arr[max] < arr[i])max = i;
	}
	return max;
}
bool isThereMoreSpace(int*& arr, unsigned size) {
	for (unsigned i = 0; i < size; i++)
	{
		if (arr[i] != 2)return true;
	}
	return false;
}
void insertAt(int*& arr, unsigned& size, int& element, unsigned pos) {
	int* newArr = new(std::nothrow) int[size + 1];
	if (!newArr) {
		return;
	}
	++size;
	for (unsigned i = 0; i < pos; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[pos] = element;
	newArr[pos + 1] = element;
	for (unsigned i = pos + 2; i < size; i++)
		newArr[i] = arr[i - 1];
	delete[] arr;
	arr = newArr;
}
void commandE() {
	exit(0);
}
void commandP(int*& arr, unsigned size) {
	std::cout << "[";
	for (unsigned i = 0; i < size; i++)
	{
		if (i == size - 1)std::cout << arr[i];
		else std::cout << arr[i] << ", ";
	}
	std::cout << "]" << std::endl;
}
void commandA(int*& arr, unsigned& size, int number) {
	for (int i = 0; i < number; i++)
	{
		if (isThereMoreSpace(arr, size)) {
			unsigned max = findIndexMaxElement(arr, size);
			int newElement = arr[max] / 2;
			insertAt(arr, size, newElement, max);
		}
		else {
			std::cout << "Try again after Hoth." << std::endl;
		}
	}
}
int main() {
	unsigned size;
	int* data = readArray(size);
	if (!data) {
		std::cerr << "No memory!" << std::endl;
		return 1;
	}
	char command;
	do {
		std::cin >> command;
		switch (command) {
		case 'A': {
			int number;
			std::cin >> number;
			commandA(data, size, number);
			break;
		}
		case 'P': {
			commandP(data, size);
			break;
		}
		case 'E': {
			commandE();
			break;
		}
		default: {
			std::cout << "Invalid command!" << std::endl;
		}
		}
	} while (true);
	delete[] data;
	return 0;
}