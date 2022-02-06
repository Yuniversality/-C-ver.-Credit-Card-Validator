#include <iostream>					// std::cin, std::cout
#include <fstream>					// std::ifstream 
#include "creditCardValidation.h"

int main(int argc, char* argv[])
{
	std::cout << "Do you want to test from user input or from file? \n";
	std::cout << "Type 0 for user input, 1 for file input \n";
	char inputChoice = ' ';
	std::cin >> inputChoice;
	while ((inputChoice != '0') && (inputChoice != '1'))
	{
		std::cout << "Please enter 0 for user input, 1 for file input \n";
		std::cin >> inputChoice;
	}
	if (inputChoice == '1')
	{
		testingFromFile();
	}
	else
	{
		testingFromUserInput();
	}

	return 0;
}

void testingFromUserInput(void) 
{
	std::string userInput = "";
	std::string continueProgram = "y";
	while (continueProgram == "y")
	{
		std::cout << "Please input a credit card number: \n";
		std::cin >> userInput;
		if (validInput(userInput))
		{
			removeSpaces(userInput);
			if (passesLuhnAlgorithm(userInput))
			{
				std::cout << "The credit card number " << userInput << " is valid and is a " << findCardIssuer(userInput) << std::endl;
			}
			else
			{
				std::cout << userInput << " is an invalid credit card number. Does not pass Luhn's algorithm.\n";
			}
		}
		else
		{
			std::cout << userInput << " is an invalid credit card number. It should only contain numbers.\n";
		}
		std::cout << "Want to input another credit card number? (y/n)\n";
		std::cin >> continueProgram;
		while (!(continueProgram == "y" || continueProgram == "n"))
		{
			std::cout << "Please answer with y (yes) or n (no): ";
			std::cin >> continueProgram;
		}
		userInput = "";
	}
}

void testingFromFile(void)
{
	std::string line;
	//std::ifstream inputFile("creditCardNumbers.txt");
	std::ifstream inputFile("userInput.txt");
	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			if (validInput(line))
			{
				removeSpaces(line);
				if (line.length() > 0)
				{
					if (passesLuhnAlgorithm(line))
					{
						std::cout << "The credit card number " << line << " is valid and is a " << findCardIssuer(line) << std::endl;
					}
					else
					{
						std::cout << line << " is an invalid credit card number. Does not pass Luhn's algorithm.\n";
					}
				}
			}
			else
			{
				std::cout << line << " is an invalid credit card number. It should only contain numbers.\n";
			}
		}
	}
	else
	{
		std::cout << "There was an error opening the file \n";
	}
}

/*
* Luhn Algorithm Resources:
* https://www.dcode.fr/luhn-algorithm
* https://www.geeksforgeeks.org/luhn-algorithm/
*/

/* 
* Anatomy of a Credit Card Number:
* The last digit is the checksum
* If we don't have the last digit, then it can be found by doing last_digit = 10 - ((sum % 10) % 10)
* First digit is represents the network that produced the card
* 
* Visa cards: 
*	- Begins with a 4 and have 13 or 16 digits
*	- Digits 2-6 are the bank number
*	- Digits 7-12 or 7-15 represent the account number
*	- Digit 13 or 16 is the checksum
* 
* Mastercard cards:
*	- Begins with a 5 (or 2 for 2-series) and has 16 digits
*	- Second digit ranges from 1-5 (inclusive) 
*	- Digits 2 & 3, 2-4, 2-5, or 2-6: Make up the bank number; depends on whether digit two is a 1, 2, 3 or other digit
*	- Digits after the bank number, up to digit 15: Represent the account number
*	- Digit 16: Is a checksum
*	- Conflicts with diners Club because both can start with 55
* 
* American Express (AMEX) cards:
*	- Begins with a 37 or 34 and has 15 digits
*	
* Discover cards:
*	- Begins with 6011 or 65 and has 16 digits
*	- Also beginning can range from 622126‑622925 and 644‑649 and have 16 digits?
* 
* Diners Club and Carte Blanche cards:
*	- Begins with 300-305 (inclusive), 309, 36, 38, or 39 and has 14 digits
*	- Begins with 54 or 55 and has 16 digits 
* 
* Japanese Credit Bureau (JCB) cards:
*	- If it begins with 3, then it has 16 digits
*	- If it starts with 2123 or 1800, then it has 15 digits
* 
* UnionPay cards:
*	- Begins with 62 and has 16-19 digits (inclusive)
* 
* We will run all other valid numbers through Luhn's Algorithm 
* and if they pass, they will be labeled as "Other"
* 
* Sources:
* https://www.dcode.fr/luhn-algorithm
* https://www.creditcardinsider.com/learn/anatomy-of-a-credit-card/#:~:text=The%20digits%20of%20a%20card,and%20the%20final%20digit%20is
* https://wallethub.com/edu/cc/what-is-a-credit-card-number/44066
* https://stevemorse.org/ssn/List_of_Bank_Identification_Numbers.html
* https://www.ibm.com/docs/en/order-management-sw/9.3.0?topic=solution-handling-credit-cards
* https://baymard.com/checkout-usability/credit-card-patterns
* 
*/

/*
* Test Credit Card Numbers From:
* https://stripe.com/docs/testing
* https://www.paypalobjects.com/en_GB/vhelp/paypalmanager_help/credit_card_numbers.htm
* https://developer.paypal.com/braintree/docs/reference/general/testing/ruby#no-credit-card-errors
*
*/

/*
* Programming Sources Used:
* Remove spaces from a given string https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
* How to determine if a string is a number with C++? https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
* std::getline(string) https://www.cplusplus.com/reference/string/string/getline/
* isdigit https://www.cplusplus.com/reference/cctype/isdigit/
* Input/output with files https://www.cplusplus.com/doc/tutorial/files/
* Substring in C++ https://www.tutorialspoint.com/substring-in-cplusplus#:~:text=A%20function%20to%20obtain%20a,of%20characters%20in%20a%20substring.
* 
*/
