// Cparser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Cparser.h"
#include <string>
#include <iostream>
#include <fstream>

int account[5];
int main()
{
	makeAccounts();
	streamMoneyFile();
	checkAmountMoney();
	system("pause");
    return 0;
}

void makeAccounts() {
	std::cout << "Before the money is parsed: " << std::endl;
	int amoutAccount = (sizeof(account) / sizeof(*account));
	for (int i = 0; i < amoutAccount; i++) {
		account[i] = 100;
		std::cout << i << ": " << account[i] << std::endl;
	}
}

void streamMoneyFile() {
	std::cout << "Sender, receiver, amout " << std::endl;
	std::ifstream file("../Money.txt");
	std::string setLine;
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (std::getline(file, setLine))
	{
		std::cout << setLine << std::endl;
		processMoney(setLine);
	}
}

void processMoney(std::string setLine) {
	std::string parserMoney[3];
	for (int i = 0; i < 3; i++) {
		std::string splitter = ",";
		std::string substring = setLine.substr(0, setLine.find(splitter));
		setLine.erase(0, substring.length() + 1);
		parserMoney[i] = substring;
		}
	int checkAccount1 = atoi(parserMoney[0].c_str());
	int checkAccount2 = atoi(parserMoney[1].c_str());
	int checkAmount = atoi(parserMoney[2].c_str());
	account[checkAccount1] = account[checkAccount1] - checkAmount;
	account[checkAccount2] = account[checkAccount2] + checkAmount;

}

void checkAmountMoney() {
	std::cout << "After the money is parsed: " << std::endl;
	int amoutAccount = (sizeof(account) / sizeof(*account));
	for (int i = 0; i < amoutAccount; i++) {
		std::cout << i << ": " << account[i] << std::endl;
	}
}

