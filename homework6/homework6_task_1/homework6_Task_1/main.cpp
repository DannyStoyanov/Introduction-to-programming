#include<iostream>
const int MAX_SIZE = 100;
void readSize(unsigned& n, unsigned& m) {
	do {
		std::cin >> n;
	} while (n == 0 || n > 100);
	do {
		std::cin >> m;
	} while (m == 0 || m > 100);
}
void readArray(int arr[][MAX_SIZE], unsigned n, unsigned m) {
	for (unsigned row = 0; row < n; row++)
	{
		for (unsigned col = 0; col < m; col++)
		{
			std::cin >> arr[row][col];
		}
	}
}
int rowProduct(int arr[][MAX_SIZE], unsigned row, unsigned m)
{
	int sum = 1;
	for (unsigned i = 0; i < m; i++)
	{
		sum *= arr[row][i];
	}
	return sum;
}

int colProduct(int arr[][MAX_SIZE], unsigned col, unsigned n)
{
	int sum = 1;
	for (unsigned i = 0; i < n; i++)
	{
		sum *= arr[i][col];
	}
	return sum;
}
int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	unsigned n, m;
	readSize(n, m);
	readArray(matrix, n, m);
	int counter = 0;
	for (unsigned row = 0; row < n; row++) {
		for (unsigned col = 0; col < m; col++) {
			if (rowProduct(matrix, row, m) == colProduct(matrix, col, n)) {
				std::cout << row << ", " << col << std::endl;
				counter++;
			}
		}
	}
	if (counter == 0)std::cout << "No match." << std::endl;
	return 0;
}