#include <iostream>
#include <vector>

/*
This is bubble sort a sorting algorithm
@param vector<int> nums the vector we are going to sort
@return void
*/
void bubbleSort(std::vector<int>& nums, bool isDescending)
{
    for(int counter1 = 0; counter1 < nums.size()-1; counter1++)
    {
        for(int counter2 = counter1+1; counter2 < nums.size()-counter1-1; counter2++)
        {
            if(isDescending)
            {
                if(isLess(nums[counter1], nums[counter2])) swap(nums, counter1, counter2);
            }
            else
            {
                if(isGreater(nums[counter1], nums[counter2])) swap(nums, counter1, counter2);
            }
        }
    }
    return;
}

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

int main ()
{
    std::vector<int> example1 = {4, 8, 9, 2, 0, 11, 16, 3, 6};
    bubbleSort(example1, true);
    
    for(int value : example1)
    {
        std::cout << value << std::endl;
    }
}