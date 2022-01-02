#include "creditCardValidation.h"

bool passesLuhnAlgorithm(const std::string creditCardNumber)
{
	/* 
	* For keeping track of every other digit to double.
	* Since the for loop starts at the last credit card digit, we
	* set position = 1 so every even number is a number we need to 
	* do the double procedure on while the odd numbers we just add.
	*/
	int position = 1;
	int sum = 0;
	for (int i = creditCardNumber.length() - 1; i >= 0; i--)
	{
		// For even positions
		if ((position % 2) == 0)
		{
			// To convert from char to int, we need to subtract 0 from 
			// the ASCII value to get the real int value
			int temp = (creditCardNumber[i] - '0') * 2;
			// If the product is >10, then we add the digits of the 
			// product together then add them to the sum
			if (temp >= 10)
			{
				int digit1 = (temp / 10);
				int digit2 = (temp % 10);
				sum = sum + digit1 + digit2;
			}
			else
			{
				sum = sum + temp;
			}
		}
		// For odd positions
		else
		{
			sum = sum + (creditCardNumber[i] - '0');
		}
		position++;
	}

	// If the mod = 0, then we return true, else false
	return !(sum % 10);
}

bool validInput(const std::string input)
{
	// If the input contains only numbers and/or spaces and tabs, then return true, otherwise false
	std::size_t found = input.find_first_not_of("0123456789 \t");
	if (found == std::string::npos)
	{
		return true;
	}
	return false;
}

void removeSpaces(std::string& input)
{
	// Make a new variable, iterate over string and add any numbers to the new variable, then set string to variable
	std::string newInput = "";
	for (std::string::iterator stringIter = input.begin(); stringIter != input.end(); stringIter++)
	{
		if (std::isdigit(*stringIter))
		{
			newInput.push_back(*stringIter);
		}
	}
	input = newInput;
}

std::string findCardIssuer(const std::string creditCardNumber)
{
	bool issuerFound = false;
	std::string issuer = "";
	int numberLength = creditCardNumber.length();

	switch (numberLength) {
	case 13:
		if (creditCardNumber.substr(0,1) == "4")
		{
			issuerFound = true;
			issuer = "Visa";
		}
		break;
	case 14:
		if ((creditCardNumber.substr(0, 2) == "36") || (creditCardNumber.substr(0, 2) == "38") || (creditCardNumber.substr(0, 2) == "39"))
		{
			issuerFound = true;
			issuer = "Diners Club";
		}
		else
		{
			int digit1 = creditCardNumber[0] - '0';
			int digit2 = creditCardNumber[1] - '0';
			int digit3 = creditCardNumber[2] - '0';
			int first3Digits = (digit1 * 100) + (digit2 * 10) + digit3;
			if (((first3Digits >= 300) && (first3Digits <= 305)) || (first3Digits == 309))
			{
				issuerFound = true;
				issuer = "Diners Club";
			}
		}
		break;
	case 15:
		if ((creditCardNumber.substr(0, 2) == "34") || (creditCardNumber.substr(0, 2) == "37"))
		{
			issuerFound = true;
			issuer = "American Express";
		}
		else if (creditCardNumber.substr(0, 4) == "2123" || (creditCardNumber.substr(0, 4) == "1800"))
		{
			issuerFound = true;
			issuer = "JCB";
		}
		break;
	case 16:
		if (creditCardNumber.substr(0, 1) == "4")
		{
			issuerFound = true;
			issuer = "Visa";
		}
		
		/*
		* Since 55 can be the start for both Mastercards and Diners Club cards, I will make it
		* so the program will identify 55 as a Mastercard because the user has a higher probability
		* of using a Mastercard than a Diners Club card
		*/ 
		//else if ((creditCardNumber.substr(0, 2) == "54") || (creditCardNumber.substr(0, 2) == "55"))
		else if (creditCardNumber.substr(0, 2) == "54")
		{
			issuerFound = true;
			issuer = "Diners Club";
		}
		else if ((creditCardNumber.substr(0, 1) == "5") || (creditCardNumber.substr(0, 1) == "2"))
		{
			issuerFound = true;
			issuer = "Mastercard";
		}
		else if ((creditCardNumber.substr(0, 4) == "6011") || (creditCardNumber.substr(0, 1) == "65"))
		{
			issuerFound = true;
			issuer = "Discover";
		}
		else if (creditCardNumber.substr(0, 1) == "3")
		{
			issuerFound = true;
			issuer = "JCB";
		}
		else if (creditCardNumber.substr(0, 2) == "62")
		{
			issuerFound = true;
			issuer = "UnionPay";
		}
		else
		{
			int digit1 = creditCardNumber[0] - '0';
			int digit2 = creditCardNumber[1] - '0';
			int digit3 = creditCardNumber[2] - '0';
			int digit4 = creditCardNumber[3] - '0';
			int digit5 = creditCardNumber[4] - '0';
			int digit6 = creditCardNumber[5] - '0';
			int first3Digits = (digit1 * 100) + (digit2 * 10) + digit3;
			int first6Digits = (digit1 * 100000) + (digit2 * 10000) + (digit3 * 1000) +
				(digit4 * 100) + (digit5 * 10) + digit6;
			if ((first3Digits >= 644) && (first3Digits <= 649))
			{
				issuerFound = true;
				issuer = "Discover";
			}
			else if ((first6Digits >= 622126) && (first6Digits <= 622925))
			{
				issuerFound = true;
				issuer = "Discover";
			}
		}
		break;
	case 17:
	case 18:
	case 19:
		if (creditCardNumber.substr(0, 2) == "62")
		{
			issuerFound = true;
			issuer = "UnionPay";
		}
		break;
	default:
		issuerFound = false;
		break;
	}

	if (issuerFound)
	{
		return issuer;
	}
	return "Other";
}
