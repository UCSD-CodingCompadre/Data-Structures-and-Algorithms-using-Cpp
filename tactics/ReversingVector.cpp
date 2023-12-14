#include <iostream>
#include <vector>
#include <algorithm>

/*
A tactic that is useful is reversing a vector. This uses the <algrotihm> function reverse
for our case we pass in the beginning iterator of the vector and ending iterator to reverse
an entire vector. 
A popular example of the use of this tactic is used in the Easy Leetcode problem Rotate Array
*/

int main ()
{

    // Hold an example vector
    std::vector<int> MyVector = {1, 2, 3, 4, 5, 6, 7, 8};

    // Use the reverse function
    std::reverse(MyVector.begin(), MyVector.end());

    // Loop through the vector
    for(int Num : MyVector)
    {

        // Print out the num
        std::cout << Num << std::endl;
    }
}

