#include<iostream>
#include<cstring>
void myStrcpy(char* to, char from[])
{
	int pos = 0;
	while (from[pos]) {
		to[pos] = from[pos];
		++pos;
	}
	to[pos] = '\0';
}
unsigned readNumberOfExtensions() {
	std::cout << "Enter number of extensions: ";
	unsigned number;
	do {
		std::cin >> number;
	} while (number < 0);
	return number;
}
void readExtensions(char* ext[],int n) {
	char temp[100];
	for (size_t i = 0; i < n; i++)
	{
		std::cout << "-Enter file extension: ";
		std::cin.getline(temp, 100);
		myStrcpy(ext[i], temp);
	}
}
void print(char** p) {
	for (int i = 0; i < 3; i++)
	{
		std::cout << p[i] << std::endl;
	}
}
int main() {
	unsigned n = readNumberOfExtensions();
	char* extensions[100];
	readExtensions(extensions, n);
	print(extensions);
	return 0;
}