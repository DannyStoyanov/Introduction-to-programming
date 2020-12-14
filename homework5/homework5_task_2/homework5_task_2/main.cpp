#include<iostream>
#include<cstdlib>
#include <time.h> 
void readArray(bool arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}
void generateMap(bool arr[], int size) {
	srand(time(NULL));
	arr[0] = 1; // we cant start from hole
	for (int i = 1; i < size; i++)
	{
		arr[i] = rand() % 2; // generating random number 0 or 1
	}
}
void printMap(bool arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
int holeWidth(bool arr[], int size, int from) {
	int i = from;
	int counter = 0;
	while (arr[i] == 0) {
		counter++;
		i++;
	}
	return counter;
}
void setStatus(int& max, int curr, int& startPos, int currPos) { // to simplify longestPath and longestPlatform functions
	if (curr > max) {
		max = curr;
		startPos = currPos;
	}
}
int findNextPlatform(bool arr[], int size, int from) {
	for (int i = from; i < size; i++)
	{
		if (arr[i] == 1)return i - 1;
	}
	return -1;
}
int longestPath(bool arr[], int size, int& length) {
	length = 0;
	int startPosition = 0;
	int currentStartPosition = 0;
	int max = 1;
	int current = 1;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] == 1) {
			current++;
		}
		else {
			int jump = holeWidth(arr, size, i);
			if (holeWidth(arr, size, i) <= 3) {
				i = findNextPlatform(arr, size, i);
				if (i == -1) {
					setStatus(max, current, startPosition, currentStartPosition);
					length = max;
					return startPosition;
				}
				current = current + jump;
			}
			else {
				setStatus(max, current, startPosition, currentStartPosition);
				i = findNextPlatform(arr, size, i);
				if (i == -1) {
					length = max;
					return startPosition;
				}
				currentStartPosition = i + 1;
				current = 0;
			}
		}
	}
	setStatus(max, current, startPosition, currentStartPosition);
	length = max;
	return startPosition;
}
int longestPlatform(bool arr[], int size, int& length) {
	length = 0;
	int startPosition = 0;
	int currentPosition = 0;
	int current = 1; // we always start on a platform
	int max = 1;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] == 1) {
			current++;
		}
		else if (arr[i] == 0) {
			setStatus(max, current, startPosition, currentPosition);
			current = 0;
			i = findNextPlatform(arr, size, i);
			if (i == -1) {
				length = max;
				return startPosition;
			}
			currentPosition = i + 1;
		}
	}
	setStatus(max, current, startPosition, currentPosition);
	length = max;
	return startPosition;
}
bool isPrime(int number) {
	if (number <= 1) {
		return false;
	}
	if (number % 2 == 0) {
		return number == 2;
	}
	for (int div = 3; div * div <= number; div += 2)
	{
		if (number % div == 0) {
			return false;
		}
	}
	return true;
}
int primePlatforms(bool arr[], int sizeOfMap, int len[], int startPos[], int& length) {
	length = 0;
	int current = 0;
	int index = 0;
	startPos[index] = 0;
	for (int i = 0; i < sizeOfMap; i++)
	{
		while (arr[i] == 1 && i < sizeOfMap) {
			++current;
			++i;
		}
		if (arr[i] == 0) {
			if (isPrime(current)) {
				len[index] = current;
				index++;
				length = index;
				i = findNextPlatform(arr, sizeOfMap, i);
				if (i == -1)break;
				startPos[index] = i + 1;
			}
			current = 0;
			i = findNextPlatform(arr, sizeOfMap, i);
			if (i == -1)break;
		}
	}
	if (isPrime(current))
	{
		len[index] = current;
		length = index + 1;
	}
	return length;
}
int additionalPlatforms(bool arr[], int size, int& _totalLength) {
	_totalLength = 0;
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0) {
			int jump = holeWidth(arr, size, i);
			int additional = 0;
			if (jump > 3 && jump < 8) {
				additional = 1;
				counter++;
			}
			else if (jump >= 8) {
				additional = jump - 6; // first and last 3 zeros
				counter++;
			}
			_totalLength += additional;
			int temp = i;
			i = findNextPlatform(arr, size, i);
			if (i == -1) {
				if (jump > 3 && jump < 8) {
					_totalLength += 1;
				}
				else {
					_totalLength += jump - 3;
				}
				return counter;
			}
		}
		else {
			continue;
		}
	}
	return counter;
}
int main() {
	const int MAX_SIZE = 10000;
	//bool myMap[MAX_SIZE] = { 1,1,0,0,1,0,0,0,0,1,1,1,1,0,0,1,1,0,1,1 };
	bool myMap[MAX_SIZE] = { 1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0 };
	bool map[MAX_SIZE];
	int platformLen[MAX_SIZE];
	int platformStartPos[MAX_SIZE];
	int myMapSize = 36;
	int size;
	std::cin >> size;
	if (size > 0 && size < 10000) {
		readArray(map, size);
	}
	else if (size == 0) {
		for (unsigned i = 0; i < myMapSize; i++)
		{
			map[i] = myMap[i];
		}
		size = myMapSize;
		printMap(map, size);
	}
	else if (size < 0) {
		srand(time(NULL));
		size = rand() % 40 + 10;
		generateMap(map, size);
		printMap(map, size);
	}

	int steps = 0;
	int bestStartPosition = longestPath(map, size, steps);
	std::cout << "Best starting position is " << bestStartPosition << " and the run length is " << steps << "." << std::endl;

	int length = 0;
	int longest = longestPlatform(map, size, length);
	std::cout << "Longest platform starts from position " << longest << " and has length of " << length << " steps." << std::endl;

	int capacity;
	int platforms = primePlatforms(map, size, platformLen, platformStartPos, capacity);
	std::cout << "There are " << platforms << "  prime-length platforms." << "Their lengths: ";
	if (capacity == 0) {
		std::cout << "0." << std::endl;
	}
	else {
		for (int i = 0; i < capacity; i++)
		{
			if (isPrime(platformLen[i])) {
				std::cout << platformLen[i] << " ";
			}
		}
		std::cout << "." << std::endl;
	}

	int totalLength = 0;
	int neededPlatforms = additionalPlatforms(map, size, totalLength);
	std::cout << "Mario needs " << additionalPlatforms(map, size, totalLength) << " new platforms with total length " << totalLength << "." << std::endl;


	return 0;
}