#include <iostream>

/*
A tatic that is useful with number is binary operations. 
Left bit shift is << and will shift the bits to the left 111 << is now 1110
Right bit shift is >> and will shift the bits to the right 111 >> is now 11
And is & and will return 1 if the bits are the same
Xor is ^ which will return 1 for two bits that are different
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