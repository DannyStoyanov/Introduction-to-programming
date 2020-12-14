#include<iostream>
void sequence(unsigned n) {
	if (n == 0)return;
	sequence(n - 1);
	std::cout << n;
	sequence(n - 1); 
}
unsigned readNumber() {
	unsigned number;
	do {
		std::cin >> number;
	} while (number <= 0);
	return number;
}
int main() {
	unsigned n = readNumber();
	sequence(n);
	return 0;
}