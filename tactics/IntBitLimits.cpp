#include <iostream>
#include <climits>
#include <limits>

/*
A tactic that is useful for checking bit limits of long long 64-bit and 32-bit
*/

int main()
{

    std::cout << "Minimum 32-bit signed integer: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Maximum 32-bit signed integer: " << std::numeric_limits<int>::max() << std::endl;

    std::cout << "Minimum 64-bit signed integer: " << std::numeric_limits<long long>::min() << std::endl;
    std::cout << "Maximum 64-bit signed integer: " << std::numeric_limits<long long>::max() << std::endl;

    std::cout << "Maximum int: " << INT_MAX << std::endl;
    std::cout << "Maximum long long: " << LLONG_MAX << std::endl;

    std::cout << "Minimum int: " << INT_MIN << std::endl;
    std::cout << "Minimum long long: " << LLONG_MIN<< std::endl;
}