#include<iostream>
int main() {

	// Task one:
	/*
	int x1, y1, r1, x2, y2, r2;
	std::cout << "x1=";
	std::cin >> x1;
	std::cout << "y1=";
	std::cin >> y1;
	std::cout << "r1=";
	std::cin >> r1;
	std::cout << "x2=";
	std::cin >> x2;
	std::cout << "y2=";
	std::cin >> y2;
	std::cout << "r2=";
	std::cin >> r2;
	int line = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	if ((abs(r1 - r2) * abs(r1 - r2) < line) && ((r1 + r2) * (r1 + r2) > line))std::cout << "Circles intersect at two points." << std::endl;
	else if (((r1 + r2) * (r1 + r2) == line) || (abs(r1 - r2) * (abs(r1 - r2)) == line))std::cout << "Circles intersect at one point." << std::endl;
	else if ((r1 + r2) * (r1 + r2) < line || abs(r1 - r2) * (abs(r1 - r2)) > line) std::cout << "Circles do not intersect." << std::endl;
	else if (line == 0 && r1 == r2)std::cout << "Equal circles." << std::endl;
	else std::cout << "Error!" << std::endl;
	*/



	/*  Version using sqrt() function
		here line=sqrt(-----||-----);...
		if ((abs(r1 - r2) < line) && (r1 + r2 > line))std::cout << "Circles intersect at two points." << std::endl;
		else if ((r1 + r2 == line) || (abs(r1 - r2) == line))std::cout << "Circles intersect at one point." << std::endl;
		else if (r1 + r2 < line || abs(r1 - r2) > line) std::cout << "Circles do not intersect." << std::endl;
		else if (line == 0 && r1 == r2)std::cout << "Equal circles." << std::endl;
		else std::cout << "Error!" << std::endl;
	*/

	// Task two:
	int cardNumber;
	short currentDigit;
	int cardVersion;
	int ownerID;
	std::cin >> cardNumber;
	currentDigit = (cardNumber / 100000000) % 10;
	if (currentDigit == 0)std::cout << "Invalid card number" << std::endl;
	else {
		cardVersion = currentDigit;
		if (((cardNumber / 100000) % 10 == 0) && ((cardNumber / 10000) % 10 == 0) && ((cardNumber / 1000) % 10 == 0) && ((cardNumber / 100) % 10 == 0) && ((cardNumber / 10) % 10 == 0))std::cout << "Invalid card number" << std::endl;
		else {
			ownerID = cardNumber / 100000 % 10 * 10000 + cardNumber / 10000 % 10 * 1000 + cardNumber / 1000 % 10 * 100 + cardNumber / 100 % 10 * 10 + cardNumber / 10 % 10;
			currentDigit = (cardNumber / 1000000) % 10;
			if (currentDigit == 7 || currentDigit == 9)std::cout << "Invalid card number" << std::endl;
			else {
				switch (currentDigit)
				{
				case 0: {
					std::cout << "{\"card_version\":" << cardVersion << ", \"owner_spec\":" << "\"Informatics\"" << ", \"owner_id\":" << ownerID << "}" << std::endl;
					break;
				}
				case 1: {
					std::cout << "{\"card_version\":" << cardVersion << ", \"owner_spec\":" << "\"Computer science\"" << ", \"owner_id\":" << ownerID << "}" << std::endl;
					break;
				}
				case 2: {
					std::cout << "{\"card_version\":" << cardVersion << ", \"owner_spec\":" << "\"Information systems\"" << ", \"owner_id\":" << ownerID << "}" << std::endl;
					break;
				}
				case 3: {
					std::cout << "{\"card_version\":" << cardVersion << ", \"owner_spec\":" << "\"Software engineering\"" << ", \"owner_id\":" << ownerID << "}" << std::endl;
					break;
				}
				case 4: {
					std::cout << "{\"card_version\":" << cardVersion << ", \"owner_spec\":" << "\"Applied mathematics\"" << ", \"owner_id\":" << ownerID << "}" << std::endl;
					break;
				}
				case 5: {
					std::cout << "{\"card_version\":" << cardVersion << ", \"owner_spec\":" << "\"Mathematics\"" << ", \"owner_id\":" << ownerID << "}" << std::endl;
					break;
				}
				case 6: {
					std::cout << "{\"card_version\":" << cardVersion << ", \"owner_spec\":" << "\"Statistics\"" << ", \"owner_id\":" << ownerID << "}" << std::endl;
					break;
				}
				case 8: {
					std::cout << "{\"card_version\":" << cardVersion << ", \"owner_spec\":" << "\"Maths and IT\"" << ", \"owner_id\":" << ownerID << "}" << std::endl;
					break;
				}
				default: {
					std::cout << "Invalid card number" << std::endl;
					break;
				}
				}
			}
		}
	}
	return 0;
}
