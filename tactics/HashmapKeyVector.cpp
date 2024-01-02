#include <iostream>
#include <unordered_map>
#include <vector>

/*
This tactic is for creating a custom hash function for vectors in C++.
The standard library does not include hashing of vectors so we need to create our own.
This is used in Group Anagrams medium leetcode problem.
*/
struct VectorHash 
{

    // Overright the () function
    size_t operator()(const std::vector<int>& v) const 
    {

        // Hold the hasher for ints
        std::hash<int> hasher;

        // Hold the result of the has
        size_t result = 0;

        // Loop through the values in the vector
        for (int value : v) 
        {

            // Hash them using a hashing algorithm
            result ^= hasher(value) + 0x9e3779b9 + (result << 6) + (result >> 2);
        }

        // Return the result
        return result;
    }
};

int main() {
    std::unordered_map<std::vector<int>, std::string, VectorHash> myMap;

    std::vector<int> key1 = {1, 2, 3};
    std::vector<int> key2 = {4, 5, 6};

    myMap[key1] = "Value1";
    myMap[key2] = "Value2";

    // Access values using vectors as keys
    std::cout << "Value for key1: " << myMap[key1] << std::endl;
    std::cout << "Value for key2: " << myMap[key2] << std::endl;

    return 0;
}