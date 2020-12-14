#include<iostream>
// Task one functions:
bool input(unsigned long long& number) {
	unsigned long long MAX_VAL = 1;
	MAX_VAL = MAX_VAL << 32;
	while ((number == 0) || (number > MAX_VAL)) {
		std::cin >> number;
		if (number % 2 != 0) {
			std::cout << "Are you joking with me, Euler? This number is not even!" << std::endl;
			return false;
		}
	}
	return true;
}
bool isPrimeNumber(unsigned long long number) {
	if (number < 2) {
		return false;
	}
	if (number % 2 == 0) {
		return number == 2;
	}
	for (unsigned long long i = 3; i * i <= number; i += 2)
	{
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}
void printPairs(unsigned long long number) {
	for (unsigned long long i = 2; i <= number / 2; i++)
	{
		if (isPrimeNumber(i) == true) {
			if (isPrimeNumber(number - i) == true) {
				if (i + (number - i) == number) {
					std::cout << "(" << i << ", " << number - i << ")" << " ";
				}
			}
		}
	}
}

// Task two functions:
// getting last digit of a number, depending on base
short getLastDigit(long number, short base = 10) {
	return number % base;
}
// returning sum of digits of a number
unsigned int sumOfDigits(long number, short base = 10) {
	int sum = 0;
	while (number > 0) {
		short digit = getLastDigit(number, base);
		number /= base;
		sum += digit;
	}
	return sum;
}
void swap(long& first, long& second) {
	long temp = first;
	first = second;
	second = temp;
}
unsigned int greatestCommonDivisor(long firstNumb, long secondNumb) {
	if (isPrimeNumber(firstNumb) == true || isPrimeNumber(secondNumb) == true) {
		if (firstNumb == secondNumb)return firstNumb;
		else return 1;
	}
	else if (firstNumb > secondNumb) {
		swap(firstNumb, secondNumb);
	}
	for (long div = secondNumb / 2; div > 1; div--) {
		if ((firstNumb % div == 0) && (secondNumb % div == 0)) {
			return div;
		}
	}
}
unsigned long long powerOfNumber(long number, unsigned short  power) {
	long multiplier = number;
	for (unsigned short i = 1; i < power; i++)
	{
		number *= multiplier;
	}
	return number;
}
bool isGreenNumber(long number) {
	const short POWER = 3;
	long cloning = number;
	unsigned long long sum = 0;
	while (number > 0) {
		short digit = getLastDigit(number); // max 9^3 = 729
		digit = powerOfNumber(digit, POWER);
		number /= 10;
		sum += digit;
	}
	return sum == cloning;
}
long long sumOfGreenNumbers(long min, long max) {
	long long sum = 0;
	if (min > max) {
		swap(min, max);
	}
	for (long i = min; i <= max; i++)
	{
		if (isGreenNumber(i) == true) {
			sum += i;
		}
	}
	return sum;
}
bool isRedNumber(long number) {
	long cloning = number;
	short sum = sumOfDigits(number);
	return cloning % sum == 0;
}
long long sumOfRedNumbers(long min, long max) {
	long long sum = 0;
	if (min > max) {
		swap(min, max);
	}
	for (long i = min; i <= max; i++)
	{
		if (isRedNumber(i) == true) {
			sum += i;
		}
	}
	return sum;
}
long greenMinusRedNumbers(long min, long max) {
	long result = 0;
	if (min > max) {
		swap(min, max);
	}
	result = sumOfGreenNumbers(min, max) - sumOfRedNumbers(min, max);
	return result;
}
int factorial(int number) {
	int result = 1;
	for (int i = 2; i <= number; i++)
	{
		result = result * i;
	}
	return result;
}
// calculating cosine
double sumOfSequence(double number, long long order) {
	double sum = 1;
	bool sign = false;
	for (double i = 2; i <= (2 * order); i += 2)
	{
		if (sign == true) {
			unsigned long long temp = powerOfNumber(number, i);
			double divisor = factorial(i);
			sum += temp / divisor;
			sign = false;
		}
		else {
			unsigned long long temp = powerOfNumber(number, i);
			double divisor = factorial(i);
			sum -= temp / divisor;
			sign = true;
		}
	}
	return sum;
}
double getCosine() {
	const int NUMB = 2;
	const int ORDER_OF_COSINE_SEQUENCE = 10;
	double myCosine = sumOfSequence(NUMB, ORDER_OF_COSINE_SEQUENCE);
	return myCosine;
}
double getSine() {
	double mySine = 0.0;
	mySine = 1 - (getCosine() * getCosine());
	mySine = sqrt(mySine);
	return mySine;
}
double getTangent() {
	double myTangent = getSine() / getCosine();
	return myTangent;
}
double getCotangent() {
	double myCotangent = 1 / getTangent();
	return myCotangent;
}
int main() {
	// Task one:
	/*
	unsigned long long positiveNumber; // because unsigned long max_val= 2^32 - 1
	if (input(positiveNumber) == true) {
		printPairs(positiveNumber);
	}
	*/

	// Task two:
	std::cout << "Sine:" << getSine() << std::endl;
	std::cout << "Cosine:" << getCosine() << std::endl;
	std::cout << "Tangent:" << getTangent() << std::endl;
	std::cout << "Cotangent:" << getCotangent() << std::endl;
	return 0;
}