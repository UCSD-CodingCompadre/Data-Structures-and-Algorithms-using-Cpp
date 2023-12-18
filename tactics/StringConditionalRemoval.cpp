#include <iostream>
#include <string>
#include <algorithm>
#include <cctype> 

/*
A tactic that filters a string based on a custom condition
A popular example of the use of this tactic is used in the Easy Leetcode problem ValidPalindrome
*/

/*
Check if the char is not an alphabetic letter
@param char c the character that is being checked
@return bool true if it is not a letter
*/
bool isNotLetter(char c) 
{
    return !std::isalpha(static_cast<unsigned char>(c));
}


int main() 
{
   
   // Hold the example string
    std::string myString = "Hello,123 World!";

    // Call the string erase function
    myString.erase(std::remove_if(myString.begin(), myString.end(), isNotLetter), myString.end());

    // Print the string out
    std::cout << "String after removing non-letter characters: " << myString << std::endl;

    return 0;
}