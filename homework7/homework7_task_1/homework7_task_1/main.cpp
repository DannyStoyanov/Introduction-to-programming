#include <iostream>
#include <stdlib.h>
#include <time.h>
//const long long MAX_VAL = 9223372036854775807;
const long long MAX_VAL = LLONG_MAX;
const long long MIN_VAL = 0;
long long getRandom(long long min = 0, long long max = RAND_MAX)
{
	unsigned long long temp = rand(); // generating a number with max 15 bits(RAND_MAX = 32767 = 15 bits)
	int bits = rand() % 49 + 0;		  // generating random bits
	temp = temp << bits;			  // we move [0,49] bits so at the end we can have max 63 bits
	temp = temp + rand();			  // we add random number to fill our first 15 bits
	return min + max % temp;
}
long long binarySearch(long long key, int &counter)
{
	int checkins = 0;
	unsigned long long left = MIN_VAL, right = MAX_VAL;
	while (left <= right)
	{
		checkins++;
		unsigned long long middle = left + (right - left) / 2; // preventing overflow!
		if (middle == key)
		{
			counter = checkins;
			return middle;
		}
		if (middle < key)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return -1;
}
long long randomizedBinarySearch(long long key, int &counter)
{
	int checkins = 0;
	unsigned long long left = MIN_VAL, right = MAX_VAL;
	while (left < right)
	{
		checkins++;
		unsigned long long middle = getRandom(left, right);
		if (middle == key)
		{
			counter = checkins;
			return middle;
		}
		if (middle < key)
			left = middle + 1;
		else
			right = middle;
	}
	return -1;
}
int isThisTheKey(long long key, long long myGuess, int &counter)
{
	static int visits = 0;
	visits++;
	counter = visits;
	if (myGuess == key)
	{
		std::cout << "You have entered the key correctly!" << std::endl;
		return 0;
	}
	if (myGuess < key)
	{
		std::cout << "The key is bigger than your guess!" << std::endl;
		return 1;
	}
	if (myGuess > key)
	{
		std::cout << "The key is smaller than your guess!" << std::endl;
		return -1;
	}
}
void guessTheNumber(long long key)
{
	long long myGuess;
	int tries = 0;
	std::cout << "Try to find the random generated number:" << std::endl;
	do
	{
		do
		{
			std::cout << "Guess:";
			std::cin >> myGuess;
		} while (myGuess < 0);
		if (isThisTheKey(key, myGuess, tries) == 0)
			break;
	} while (true);
	if (tries != 1)
		std::cout << "You have tryed exactly " << tries << " times!" << std::endl;
	else
		std::cout << "You have tryed exactly " << tries << " time!" << std::endl;
}
int main()
{
	srand(time(NULL));
	long long key = getRandom(MIN_VAL, MAX_VAL);
	std::cout << "Generated key:" << key << std::endl
			  << std::endl;
	//guessTheNumber(key);

	int tries = 0;
	std::cout << "---Classic Binary search:" << std::endl;
	std::cout << "Number:" << binarySearch(key, tries) << std::endl;
	std::cout << "Tries:" << tries << std::endl
			  << std::endl;
	std::cout << "---Randomized Binary search:" << std::endl;
	std::cout << "Number:" << randomizedBinarySearch(key, tries) << std::endl;
	std::cout << "Tries:" << tries << std::endl
			  << std::endl;
	std::cout << std::endl;

	return 0;
}
