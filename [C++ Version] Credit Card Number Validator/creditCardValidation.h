#ifndef creditCardValidation_H
#define creditCardValidation_H

#include <string>		// std::string, std::stoi

// Functions for testing program either from user or file input
// If testing from user input, you need to type in credit card numbers yourself
void testingFromUserInput(void);
// If testing from file input, the input file contains credit card numnbers
void testingFromFile(void);

// See if the credit card number given is valid using Luhn's algorithm
bool passesLuhnAlgorithm(const std::string creditCardNumber);

// Functions for cleaning the input before applying Luhn's algorithm to it
// See if the input is valid (all numbers, no letters/symbols)
bool validInput(const std::string input);
// Removes spaces from the input
void removeSpaces(std::string& input);

/*
*  Determines who issued the card (Visa, Mastercard, etc)
* Assumes the credit card number is valid
* (So only pass the number here after running it through 
* validInput(), removeSpaces(), and passesLuhnAlgorithm() )
* Will return the name of the card issuer
*/
std::string findCardIssuer(const std::string creditCardNumber);

#endif // creditCardValidation_H