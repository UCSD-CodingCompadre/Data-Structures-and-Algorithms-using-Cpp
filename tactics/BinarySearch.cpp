#include <iostream>
#include <vector>

/*
This is Binary Search a tatic used to find a certain element in an ascending data structure. 
You can use the sort function from the <algorithm> library to sort a data structure like a vector.
*/

bool binarySearchIterative(std::vector<int>& data, int value)
{

    // Hold the size of the data
    int size = data.size();

    // Hold the lower index
    int low = 0;

    // Hold the high index
    int high = size - 1;

    // Hold the middle index
    int mid;

    // Loop until the lower index is equal or greater than the upper index
    while(low <= high)
    {

        // Calculate the middle index
        mid = (low + high) / 2;

        // Check if we found the value
        if(data[mid] == value) return true;

        // Else check if we need to search the upper half
        else if(data[mid] < value) low = mid + 1;

        // Else we need to search the lower half
        else high = mid -1;
    }

    // Return false since we did not find the element
    return false;
}

bool binarySearchRecursive(std::vector<int>& data, int low, int high, int value)
{

    // Check if the lower index is past the upper index
    if(low > high) return false;

    // Hold the mid index
    int mid = (low + high) / 2;

    // Check if the mid index has the value
    if(data[mid] == value) return true;

    // Else check if we need to search the upper half
    else if(data[mid] < value) return binarySearchRecursive(data, mid  + 1, high, value);

    // Else we neeed to search the lower half
    else return binarySearchRecursive(data, low, mid - 1, value); 
}

int main()
{

    // Hold an example vector
    std::vector<int> MyVector = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12, 13, 15, 16, 17, 18,  19, 20};

    // Hold the value to find
    int valueToFind = 5;

    // Print the iterative result
    std::cout << binarySearchIterative(MyVector, valueToFind) << std::endl;

    // Print the recursive result
    std::cout << binarySearchRecursive(MyVector, 0, MyVector.size()-1, valueToFind) << std::endl;
}