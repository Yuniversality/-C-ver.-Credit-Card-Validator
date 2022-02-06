# Credit Card Validator (C++ Ver.)  
By Ethan Yu  

## What is it?  
This credit card validator takes in a credit card number (either from user or file input) and 
sees if the number would be a valid credit card number. If valid, then it will try to deduce 
the issuing company.  
Currently, the following companies are supported: __Visa, Mastercard, American Express (AMEX)
Discover, Diner's Club, Japanese Credit Bureau (JCB), UnionPay__. All other valid numbers
will be labeled as "Other".  

Please note: This program only tells you if the credit card number is possible, **NOT** if
the number is active/in-use and chargable.  

## How to Use  
If you are on a Linux system, download the _[C++ Version] Credit Card Number Validator_ folder 
from this Github and run it by opening the terminal, going into the directory it is downloaded 
in, and typing in: 
> ./creditCardValidator.exe

If you are using Windows, download the _[C++ Version] Credit Card Number Validator_ folder
from this Github and run it in an IDE like Visual Studio. I unfortunately have not figured 
out how to compile it into a Windows executable yet.

**If you are going to test using File Input, you must put the numbers you want to test in
the _userInput.txt_ file**  
That file is the designated file the program reads from. The program will terminate after
the file has been read and the numbers validated.  
If you want some valid dummy credit card numbers, check the _creditCardNumbers.txt_ and 
_creditCardNumbersAnswerKey.txt_ files and copy-and-paste some numbers from there to 
the _userInput.txt_ file.  

If you are testing using user input, then follow the on-screen prompts.

## Resources Used
_Also noted in the main.cpp file_  
Websites Used for Research:  
> Luhn Number Checksum https://www.dcode.fr/luhn-algorithm  
> Luhn algorithm https://www.geeksforgeeks.org/luhn-algorithm/  
> Anatomy of a Credit Card https://www.creditcardinsider.com/learn/anatomy-of-a-credit-card/#:~:text=The%20digits%20of%20a%20card,and%20the%20final%20digit%20is  
> What Is A Credit Card Number? The Meaning of Each Digit https://wallethub.com/edu/cc/what-is-a-credit-card-number/44066  
> List of Issuer Identification Numbers https://stevemorse.org/ssn/List_of_Bank_Identification_Numbers.html  
> Handling Credit Cards https://www.ibm.com/docs/en/order-management-sw/9.3.0?topic=solution-handling-credit-cards  
> Credit Card IIN Ranges & Spacing Patterns https://baymard.com/checkout-usability/credit-card-patterns  

Test Credit Card Numbers From:  
> Test your integration https://stripe.com/docs/testing  
> Test Credit Card Account Numbers https://www.paypalobjects.com/en_GB/vhelp/paypalmanager_help/credit_card_numbers.htm  
> Testing https://developer.paypal.com/braintree/docs/reference/general/testing/ruby#no-credit-card-errors  

Websites Used for Programming Help:  
> Remove spaces from a given string https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/  
> How to determine if a string is a number with C++? https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c  
> std::getline(string) https://www.cplusplus.com/reference/string/string/getline/  
> isdigit https://www.cplusplus.com/reference/cctype/isdigit/  
> Input/output with files https://www.cplusplus.com/doc/tutorial/files/  
> Substring in C++ https://www.tutorialspoint.com/substring-in-cplusplus#:~:text=A%20function%20to%20obtain%20a,of%20characters%20in%20a%20substring.  

