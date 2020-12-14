#include<iostream>
int divide(int number, int divider) {
	while (number % divider == 0) {
		number = number / divider;
	}
	return number;
}
bool isHammingNumber(int number) {
	const int DIVIDER_TWO = 2, DIVIDER_THREE = 3, DIVIDER_FIVE = 5;
	number = divide(number, DIVIDER_TWO);
	number = divide(number, DIVIDER_THREE);
	number = divide(number, DIVIDER_FIVE);
	if (number == 1)return true;
	else return false;
}
unsigned int getID(unsigned int number) {
	return number; // potentially to be changed for future
}
int main() {
	// Task one:
	/*
	unsigned int number;
	// Validating input:
	do {
		std::cin >> number;
	} while (number == 0);
	for (unsigned int i = 1; i <= number; i++)
	{
		if (isHammingNumber(i)) {
			std::cout << i << " ";
		}
	}
	*/

	// Task two:
	unsigned int number;
	int id;
	int i = 0;
	// Validating input:
	do {
		std::cin >> number;
	} while (number == 0 || number > 31);

	int MASK = 1; // first bit set to 1
	unsigned int median = 0;
	std::cin >> id;
	int previous = getID(id);
	// using unsigned long because 2^32 = 2^31 - 1, which is 4294967295, the exact maximum of unsigned long 
	unsigned long binNumber = 1; // In this bin number I will safe my 0 or 1 depending on id(0)<id(1), ...
	// first bit (id(0)) is always set to 1
	for (unsigned int i = 1; i < number; i++)
	{
		binNumber = binNumber << 1;
		std::cin >> id;
		id = getID(id);
		if (previous <= id) {
			binNumber = binNumber | MASK;
			++median;
		}
		else if (previous > id) {
			MASK = ~MASK; // in order to set 1st bit to 0
			binNumber = binNumber & MASK;
			MASK = 1; // to be ready for next step if previous<=id
		}
		previous = id;
	}
	//std::cout << "binNumber:" << binNumber << std::endl;
	if (median % 2 == 0)median /= 2;
	else (median /= 2) + 1;

	MASK = 1; // I will check every first bit of binNumber from now on
	unsigned int leftZeros = 0;
	unsigned int rightZeros = 0;
	unsigned int counter = 0; // with counter im checking wether it is left/right side of median
	for (int i = number - 1; i >= 0; --i)
	{
		int temp = binNumber >> i;
		temp = temp & MASK;
		if (temp == 1) {
			counter++;
		}
		else {
			if (counter <= median) {
				++leftZeros;
			}
			else if (counter > median) {
				++rightZeros;
			}
		}
	}
	// Output:
	std::cout << std::endl;
	if (leftZeros == rightZeros)std::cout << "Both sides:" << leftZeros << std::endl;
	else if (leftZeros > rightZeros)std::cout << "Left side:" << leftZeros << std::endl;
	else std::cout << "Right side:" << rightZeros << std::endl;
	return 0;
}