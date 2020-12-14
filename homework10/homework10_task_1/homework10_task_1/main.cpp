#include<iostream>
bool checkDigit(int number, int digit) {
	if (number == 0)return false;
	if (number % 10 == digit)return true;
	return checkDigit(number / 10, digit);
}
bool isUnique(int number) {
	if (number <= 9)return false;
	return checkDigit(number / 10, number % 10) || isUnique(number / 10);
}
int myAbs(int n) {
	if (n < 0)return -n;
}
int main() {
	int n;
	std::cin >> n;
	if (isUnique(myAbs(n))) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	return 0;
}