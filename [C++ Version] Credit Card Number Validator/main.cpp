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
* Programming Sources Used:
* Remove spaces from a given string https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
* How to determine if a string is a number with C++? https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
* std::getline(string) https://www.cplusplus.com/reference/string/string/getline/
* isdigit https://www.cplusplus.com/reference/cctype/isdigit/
* Input/output with files https://www.cplusplus.com/doc/tutorial/files/
* Substring in C++ https://www.tutorialspoint.com/substring-in-cplusplus#:~:text=A%20function%20to%20obtain%20a,of%20characters%20in%20a%20substring.
* 
*/
