#include<iostream>
int readSize() {
	int n;
	do {
		std::cin >> n;
	} while (n < 0 || n>1001);
	return n + 1;
}
void readPolynom(double arr[], const int size) {
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}
double derivative(double coef, int power) {
	if (power == 0)return 0;
	return power * coef;
}
void calculateDerivative(double arr[], int& size) {
	for (int i = 0; i < size; i++)
	{
		int power = size - i - 1; // first coef is with highest power
		arr[i] = derivative(arr[i], power);
	}
	size = size - 1; // first derivative of constant is 0, so we lower the size of the array
}
double myAbs(double number) {
	if (number < 0)return -number;
	return number;
}
void printPolynom(double arr[], const int size) {
	const double eps = 0.000000001;
	for (int i = 0; i < size; i++)
	{
		int power = size - i - 1;
		if (myAbs(arr[i]) < eps)continue;
		if (power == 0)std::cout << arr[i];
		else if(power==1){
			std::cout << arr[i] << "*X + ";
		}
		else {
			std::cout << arr[i] << "*X^"<<power<< " + ";
		}
	}
}

int main() {
	int size;
	int nthDerivative;
	double polynom[1000];
	size = readSize();
	readPolynom(polynom, size);
	do{
	std::cin >> nthDerivative;
	} while (nthDerivative < 0);
	if (nthDerivative >= size)std::cout << 0;
	else {
		for (int i = 0; i < nthDerivative; i++)
		{
			calculateDerivative(polynom, size);
		}
		printPolynom(polynom, size);
	}
	return 0;
}