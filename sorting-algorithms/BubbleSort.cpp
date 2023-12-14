#include <iostream>
#include <vector>

/*
This is bubble sort which is a sorting algorithm that is O(n^2) time complexity and uses
O(1) space complexity.
*/

/*
Helper method to check if a number is greater than the next number
@param int num1 the first number used to compare
int num2 the second number used to compare
@return bool true if num1 is greater than num2
*/
bool isGreater(int num1, int num2)
{

    // Return the bool expression
    return num1 > num2;
}

/*
Helper method to check if a number is less than the next number
@param int num1 the first number used to compare
int num2 the second number used to compre
@return bool true if num1 is less than num2
*/
bool isLess(int num1, int num2)
{

    // Return the bool expression
    return num1 < num2;
}

/*
Helper method that swaps two indexes in a referenced vector
@param vector<int> nums the vector being referenced
int index1 the first index to swap
int index2 the second index to swap
@return void
*/
void swap(std::vector<int>& nums, int index1, int index2)
{

    // Hold the value that will be erased after the first swap
    int temp = nums[index1];

    // Swap the temp value being erased
    nums[index1] = nums[index2];

    // Swap value using the erased value
    nums[index2] = temp;
    return;
}

/*
This is bubble sort a sorting algorithm
@param vector<int> nums the vector we are going to sort
bool isDescending true if the sorting results in an descending vector
@return void
*/
void bubbleSort(std::vector<int>& nums, bool isDescending)
{

    // Outer loop for the amount of comparisons made
    for(int counter1 = 0; counter1 < nums.size() - 1; counter1++)
    {
        // Hold an early termination flag
        bool flag = true;
        
        // Inner loop that moves the next number in the correct index
        for(int counter2 = 0; counter2 < nums.size() - counter1 - 1; counter2++)
        {

            // Check if the sorting is descending
            if(isDescending)
            {

                // Check if we need to swap
                if(isLess(nums[counter2], nums[counter2+1])) 
                {

                    // Turn off the termination flag
                    flag = false;

                    // Swap the indexes
                    swap(nums, counter2, counter2+1);
                }
            }

            // Else the sorting is ascending
            else
            {

                // Check if we need to swap
                if(isGreater(nums[counter2], nums[counter2+1])) 
                {

                    // Turn off the termination flag
                    flag = false;

                    // Swap the indexes
                    swap(nums, counter2, counter2+1);
                }
            }
        }

        // Check if we can terminate early
        if(flag) return;
    }
    return;
}

int main ()
{
    std::vector<int> example1 = {4, 8, 9, 2, 0, 11, 16, 3, 6};
    std::vector<int> example2 = {7, 1, 9, 4, 5, 0, 11, 3};
    bubbleSort(example1, true);
    bubbleSort(example2, false);
    
    std::cout << "Example 1 descending order: ";
    for(int value : example1)
    {
        std::cout << value << ", ";
    }

    std::cout << '\n';

    std::cout << "Example 2 ascending order: ";
    for(int value : example2)
    {
        std::cout << value << ", ";
    }
}