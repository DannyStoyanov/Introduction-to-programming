#include<iostream>
int main() {
	// Task one:

	/*
	unsigned int number;
	std::cin >> number;
	char symbol;
	int thousands = number / 1000;
	int hundreds = (number / 100) % 10;
	int dozens = (number / 10) % 10;
	int units = number % 10;
	if (number == 0 || number > 3000) {
		std::cout << "Invalid number!" << std::endl;
	}
	else {
		switch (thousands) {
		case 1: {
			std::cout << "M";
			break;
		}
		case 2: {
			std::cout << "MM";
			break;
		}
		case 3: {
			std::cout << "MMM";
			break;
		}
		}
		switch (hundreds) {
		case 1: {
			std::cout << "C";
			break;
		}
		case 2: {
			std::cout << "CC";
			break;
		}
		case 3: {
			std::cout << "CCC";
			break;
		}
		case 4: {
			std::cout << "CD";
			break;
		}
		case 5: {
			std::cout << "D";
			break;
		}
		case 6: {
			std::cout << "DC";
			break;
		}
		case 7: {
			std::cout << "DCC";
			break;
		}
		case 8: {
			std::cout << "DCCC";
			break;
		}
		case 9: {
			std::cout << "CM";
			break;
		}
		}
		switch (dozens) {
		case 1: {
			std::cout << "X";
			break;
		}
		case 2: {
			std::cout << "XX";
			break;
		}
		case 3: {
			std::cout << "XXX";
			break;
		}
		case 4: {
			std::cout << "XL";
			break;
		}
		case 5: {
			std::cout << "L";
			break;
		}
		case 6: {
			std::cout << "LX";
			break;
		}
		case 7: {
			std::cout << "LXX";
			break;
		}
		case 8: {
			std::cout << "LXXX";
			break;
		}
		case 9: {
			std::cout << "XC";
			break;
		}
		}
		switch (units) {
		case 1: {
			std::cout << "I";
			break;
		}
		case 2: {
			std::cout << "II";
			break;
		}
		case 3: {
			std::cout << "III";
			break;
		}
		case 4: {
			std::cout << "IV";
			break;
		}
		case 5: {
			std::cout << "V";
			break;
		}
		case 6: {
			std::cout << "VI";
			break;
		}
		case 7: {
			std::cout << "VII";
			break;
		}
		case 8: {
			std::cout << "VIII";
			break;
		}
		case 9: {
			std::cout << "IX";
			break;
		}
		}
	}
	*/

	// Task two:
	const unsigned int KEY_ONE = 0xCAFE, KEY_TWO = 0xBABE, KEY_THREE = 0xC001, KEY_MASK_ONE = 0xC0DE, KEY_MASK_TWO = 0xFACE;
	unsigned int cardNumber;
	unsigned int checkDigit;
	unsigned int lastDigit;

	std::cin >> cardNumber;
	checkDigit = cardNumber % 10;
	lastDigit = checkDigit;
	unsigned int secondDigit = (cardNumber / 10000000) % 10;

	unsigned int i = 0, sumEven = 0, sumOdd = 0;
	// step 1):
	while (cardNumber > 0) {
		unsigned int digit = cardNumber % 10;
		cardNumber = cardNumber / 10;
		if (i % 2 == 0)sumEven += digit;
		else sumOdd += digit;
		i++;
	}
	checkDigit = sumEven * sumOdd;

	int secondBit = 2;
	int thirdBit = 4;
	if (secondDigit >= 0 && secondDigit <= 7) {
		// step 2):
		if ((secondDigit & secondBit) == 1 && (secondDigit & thirdBit) == 1) { // 11[]
			checkDigit = checkDigit | KEY_ONE;
		}
		else if ((secondDigit & secondBit) == 0 && (secondDigit & thirdBit) == 0) {// 00[]
			checkDigit = checkDigit | KEY_TWO;
		}
		else checkDigit = checkDigit | KEY_THREE; // for all left cases - 10[] or 01[]

		int firstBit = 1;
		// step 3):
		if ((secondDigit & firstBit) == 1) { // 1 = 001, 3 = 011, 5 = 101, 7 = 111
			checkDigit = checkDigit ^ KEY_MASK_ONE;
		}
		else if ((secondDigit & firstBit) == 0) { // 0 = 000, 2 = 010, 4 = 100, 6 = 110
			checkDigit = checkDigit ^ KEY_MASK_TWO;
		}

		// step 4):
		// calculating how many bits to move:
		int powerOfTwo = 1;
		int moveBits = 0;
		do {
			if (checkDigit<powerOfTwo || checkDigit >(2 * powerOfTwo) - 1) {
				powerOfTwo = powerOfTwo * 2;
			}
			moveBits++;
		} while (checkDigit >= powerOfTwo * 2);
		moveBits++; // because checkDigit >= powerOfTwo * 2, losing 1 operation++ 

		if (checkDigit >= 16) {
			moveBits = moveBits - 4; // to keep last 4 bits
			checkDigit = checkDigit >> moveBits;
		}
		if (checkDigit > 10)checkDigit = checkDigit % 10;

		if (checkDigit == lastDigit)std::cout << "Authentic" << std::endl;
		else std::cout << "Imitative" << std::endl;
	}
	else {
		std::cout << "Imitative" << std::endl;
	}


	return 0;
}

