#include <iostream>

/*
A tatic that is useful with number is binary operations. 
The use of Xor is shown in Easy Leetcode problem Single Number 
*/

int main()
{

    // Hold nums
    int a = 2;
    int b = 2;
    int c = 3;

    // Two similar numbers that Xor will result in 0
    std::cout << (a^b) << std::endl;

    // A number that Xor's with 0 will result in that same number
    std::cout << ((a ^ b) ^ c) << std::endl;
}