#include<iostream>
#include <time.h> 
#include<cstdlib>
const int SIZE = 52;
void readDeck(int arr[], unsigned size) {
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}
void printDeck(int arr[], unsigned size) {
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}
int getSuit(int number) {
	return number / 100;
}
int getCardValue(int number) {
	int result;
	int units = number % 10;
	int dozens = (number / 10) % 10;
	result = dozens * 10 + units;
	return result;
}
void swapValue(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
void swapByIndex(int arr[], unsigned x, unsigned y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
int generateCard() {
	int hundreds = rand() % 4 + 1;
	int value = rand() % 13 + 1;
	int dozens = value / 10;
	int units = value % 10;
	return hundreds * 100 + dozens * 10 + units;
}
int createCard(int suit, int value) {
	return suit * 100 + value;
}
void messUpDeck(int deck[], size_t size) {
	for (int i = 0; i < size; i++)
	{
		int randomPosition = rand() % (size - 1) + 0;
		swapByIndex(deck, i, randomPosition);
	}
}
void newDeck(int arr[], size_t size) {
	const int SUITS = 4;
	const int CARD_MAX_VALUE = 14;
	const int CARD_MIN_VALUE = 2;
	int index = 0;
	for (int i = CARD_MIN_VALUE; i < CARD_MAX_VALUE; i++)
	{
		for (int j = SUITS; j >= 1; j--)
		{
			arr[index] = createCard(j, i);
			++index;
		}
	}
	for (int j = SUITS; j >= 1; j--)
	{
		arr[index] = createCard(j, 1);
		++index;
	}
}
bool compareAndSwap(int arr[], int pos) {
	if (getCardValue(arr[pos]) == 1 && getCardValue(arr[pos - 1]) != 1) {
		return false;
	}
	else if (getCardValue(arr[pos]) != 1 && getCardValue(arr[pos - 1]) == 1) {
		swapByIndex(arr, pos, pos - 1);
		return true;
	}
	else if (getCardValue(arr[pos]) == getCardValue(arr[pos - 1])) {
		if (getSuit(arr[pos]) > getSuit(arr[pos - 1])) {
			swapByIndex(arr, pos, pos - 1);
			return true;
		}
	}
	else if (getCardValue(arr[pos]) < getCardValue(arr[pos - 1])) {
		swapByIndex(arr, pos, pos - 1);
		return true;
	}
}
bool compareCards(int firstCard, int secondCard) {
	if (getCardValue(firstCard) == 1 && getCardValue(secondCard) != 1) {
		return true;
	}
	else if (getCardValue(firstCard) != 1 && getCardValue(secondCard) == 1) {
		return false;
	}
	else if (getCardValue(firstCard) == getCardValue(secondCard)) {
		if (getSuit(firstCard) > getSuit(secondCard)) {
			return false;
		}
	}
	else if (getCardValue(firstCard) < getCardValue(secondCard)) {
		return false;
	}
	return true;
}
void insertSorted(int arr[], int card, size_t size) {
	int i = size;
	while (i > 0 && compareCards(arr[i - 1], card)) {
		arr[i] = arr[i - 1];
		--i;
	}
	arr[i] = card;
}
void insertionSortDeck(int arr[], size_t size) {
	for (unsigned i = 1; i < size; ++i)
		insertSorted(arr, arr[i], i);
}
void sortDeck(int arr[], size_t size) {
	bool changed = false;
	unsigned sorted = 0;
	do {
		changed = false;
		for (unsigned pos = size - 1; pos > sorted; --pos) {
			changed = compareAndSwap(arr, pos);
		}
		++sorted;
	} while (changed);
}
void showSortDeckBySteps(int arr[], size_t size) {
	bool changed = false;
	unsigned sorted = 0;
	do {
		changed = false;
		for (unsigned pos = size - 1; pos > sorted; --pos) {
			if (getCardValue(arr[pos]) == 1 && getCardValue(arr[pos - 1]) != 1) {
				changed = false;
			}
			else if (getCardValue(arr[pos]) != 1 && getCardValue(arr[pos - 1]) == 1) {
				std::cout << "Card " << arr[pos] << " with card " << arr[pos - 1] << " were swapped!" << std::endl;
				swapByIndex(arr, pos, pos - 1);
				changed = true;
			}
			else if (getCardValue(arr[pos]) == getCardValue(arr[pos - 1])) {
				if (getSuit(arr[pos]) > getSuit(arr[pos - 1])) {
					std::cout << "Card " << arr[pos] << " with card " << arr[pos - 1] << " were swapped!" << std::endl;
					swapByIndex(arr, pos, pos - 1);
					changed = true;
				}
			}
			else if (getCardValue(arr[pos]) < getCardValue(arr[pos - 1])) {
				std::cout << "Card " << arr[pos] << " with card " << arr[pos - 1] << " were swapped!" << std::endl;
				swapByIndex(arr, pos, pos - 1);
				changed = true;
			}
		}
		++sorted;
	} while (changed);
}
int main() {
	srand(time(NULL));
	int deck[SIZE];

	std::cout << "Enter deck:" << std::endl;
	readDeck(deck, SIZE);
	//newDeck(deck, SIZE);
	//messUpDeck(deck, SIZE);
	std::cout << std::endl;
	std::cout << std::endl;
	insertionSortDeck(deck, SIZE);
	printDeck(deck, SIZE);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Brand new(sorted) deck:" << std::endl;
	newDeck(deck, SIZE);
	printDeck(deck, SIZE);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Let's mess up the deck:" << std::endl;
	messUpDeck(deck, SIZE);
	printDeck(deck, SIZE);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Let's sort it:" << std::endl;
	sortDeck(deck, SIZE);
	printDeck(deck, SIZE);
	std::cout << std::endl;
	std::cout << std::endl;

	/*
	std::cout << "Sorting deck with steps:" << std::endl;
	messUpDeck(deck, SIZE);
	showSortDeckBySteps(deck, SIZE);
	std::cout << std::endl;
	std::cout << std::endl;
	*/
	return 0;
} 
/*
При въвеждане на тестето карти от потребителя използвам Insertion Sort, защото при въвеждаже на
нов елемент веднага намираме мястото му в масива. След това използвам същия масив за да го разбъркам и чрез Bubble Sort го сортирам отново с възможно най-малко сравнения. В случая не ми е нужен допълнителен масив, понеже в задачата не е описано използването на два различни масива по едно и също време, а последователни операции с един масив.
*/
