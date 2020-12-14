#include<iostream>
void readArray(int** arr, size_t rows, size_t cols) {
	std::cout << "Enter elements:" << std::endl;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}
int** readArrayDynamic(size_t* rows, size_t* cols) {
	size_t n, m;
	std::cout << "n=";
	std::cin >> n;
	std::cout << "m=";
	std::cin >> m;

	int** arr = new(std::nothrow) int* [n];
	if (!arr) {
		return nullptr;
	}
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = new(std::nothrow) int[m];
		if (!arr[i]) {
			for (size_t j = 0; j <= i; j++)
			{
				delete[] arr[i];
			}
			delete[] arr;
			return nullptr;
		}
	}
	readArray(arr, n, m);
	*rows = n;
	*cols = m;
	return arr;
}
void printMatrix(int** arr, size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void swap(int* first_arr, int* second_arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		int temp = first_arr[i];
		first_arr[i] = second_arr[i];
		second_arr[i] = temp;
	}
}
int findSum(int* arr, size_t size) {
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int minFrom(int** arr, size_t from, size_t to, size_t cols) {
	int index = from;
	int min = findSum(arr[from], cols);
	for (size_t i = from; i < to; i++)
	{
		int currentSum = findSum(arr[i], cols);
		if (min > currentSum) {
			min = currentSum;
			index = i;
		}
	}
	return index;
}
void sortMatrixBySums(int** arr, size_t rows, size_t cols) {
	for (unsigned i = 0; i < rows - 1; ++i) {
		int m = minFrom(arr, i, rows, cols);
		swap(arr[m], arr[i], cols);
		//printMatrix(arr, rows, cols); // Testing step by step
		std::cout << std::endl;
	}
}
void clearMatrix(int** matrix, size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
int main() {
	size_t n, m;
	int** matrix = nullptr;
	matrix = readArrayDynamic(&n, &m);
	if (!matrix) {
		std::cout << "Not enough memory!" << std::endl;
		return 0;
	}
	std::cout << "Initial:" << std::endl;
	printMatrix(matrix, n, m);
	std::cout << std::endl;
	sortMatrixBySums(matrix, n, m);
	std::cout << "Sorted:" << std::endl;
	printMatrix(matrix, n, m);
	clearMatrix(matrix, n);

	return 0;
}