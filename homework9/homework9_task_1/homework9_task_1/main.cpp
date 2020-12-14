#include<iostream>
#include<cstring>
#include <time.h>
// FIXED ARRAYS
typedef const bool object_subject[2];
const char EXCLAMATION[50][50] = { "SHOK","Nechuvana naglost", "SKANDAL" };
const char OBJECT_SUBJECT[50][50] = { "riapa","baba", "kmet","bager","sklad" };
const object_subject IS_SUBJECT[50] = { {1,1},{1,1},{1,1},{1,1},{0,1} };
const char ACTION[50][50] = { "sgazi","zadiga", "namiga na", "precakva", "tarashi" };
const size_t EXCLS_SIZE = 3;
const size_t OBJECTS_SIZE = 5;
const size_t ACTIONS_SIZE = 5;

size_t myStrlen(const char* str)
{
	size_t len = 0;
	while (str[len]) {
		++len;
	}
	return len;
}
void myStrcpy(char* to, const char* from)
{
	int pos = 0;
	while (from[pos]) {
		to[pos] = from[pos];
		++pos;
	}
	to[pos] = '\0';
}
void myStrcat(char* to, const char* from)
{
	while (*to) {
		++to;
	}
	myStrcpy(to, from);
}
char* makeFirstLetterBig(const char* str) {
	char* result = new(std::nothrow) char[myStrlen(str)];
	if (!result)return nullptr;
	myStrcpy(result, str);
	if (*result >= 'a' && *result <= 'z') {
		*result -= 'a' - 'A';
	}
	return result;
}
unsigned readNumberOfTitles() {
	unsigned number;
	do {
		std::cin >> number;
	} while (number <= 0);
	return number;
}
char* dynamicConcat(char* str1, const char* str2) {
	unsigned len1 = myStrlen(str1);
	unsigned len2 = myStrlen(str2);

	char* temp = new(std::nothrow) char[len2 + 2];
	if (!temp) {
		return nullptr;
	}
	myStrcpy(temp, str2);
	myStrcat(temp, " ");
	temp[len2 + 1] = '\0';

	char* result = new(std::nothrow) char[len1 + len2 + 1];
	if (result) {
		myStrcpy(result, str1);
		myStrcat(result, temp);
	}
	delete[] temp;
	return result;
}
const char* generateRandom(const char arr[][50], const size_t size) {
	unsigned randIndex = rand() % size;
	const char* result = *(arr + randIndex);
	return result;
}
const char* generateRandomObjectSubject(const char arr[][50], const size_t size, bool isSubject) {
	unsigned randIndex;
	if (isSubject == true) {
		do {
			randIndex = rand() % size;
		} while (IS_SUBJECT[randIndex][1] != true);
		const char* result = *(arr + randIndex);
		return result;
	}
	else {
		do {
			randIndex = rand() % size;
		} while (IS_SUBJECT[randIndex][0] != true);
		const char* result = *(arr + randIndex);
		return result;
	}

}
char* generateRandomExcl() {
	unsigned randNumber = rand() % ((10 + 1) - 3) + 3; // because we want from 3 to 10 - '!' symbols
	char* result = new(std::nothrow) char[randNumber];
	if (!result) {
		return nullptr;
	}
	for (size_t i = 0; i < randNumber; i++)
	{
		*(result + i) = '!';
	}
	result[randNumber - 1] = '\0';
	return result;
}
void randomTitle(char* str) {
	str = dynamicConcat(str, generateRandom(EXCLAMATION, EXCLS_SIZE));
	str = dynamicConcat(str, generateRandomExcl());
	str = dynamicConcat(str, makeFirstLetterBig(generateRandomObjectSubject(OBJECT_SUBJECT, OBJECTS_SIZE, 0)));
	str = dynamicConcat(str, generateRandom(ACTION, ACTIONS_SIZE));
	str = dynamicConcat(str, generateRandomObjectSubject(OBJECT_SUBJECT, OBJECTS_SIZE, 1));
	std::cout << str;
}
int main() {
	srand(time(NULL));
	unsigned n = readNumberOfTitles();
	char* title = new (std::nothrow) char[1];
	if (title) {
		title[0] = '\0';
		for (size_t i = 0; i < n; i++)
		{
			randomTitle(title);
			std::cout << std::endl;

		}
		delete[] title;
	}
	return 0;
}