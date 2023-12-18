#include <iostream>
#include <string>
#include <algorithm>

/*
A tactic that is useful is reversing a string. This uses the <algrotihm> function reverse
for our case we pass in the beginning iterator of the string and ending iterator to reverse
an entire string. 
*/

int main ()
{

    // Hold an example string
    std::string MyString = "Reverse Me";

    // Use the reverse function
    std::reverse(MyString.begin(), MyString.end());

    // Loop through the string
    for(char Char : MyString)
    {

        // Print out the num
        std::cout << Char << std::endl;
    }
}