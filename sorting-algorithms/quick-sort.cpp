#include <iostream>
#include <algorithm>
#include <vector>

void quickSortHelper(std::vector<int>& nums, int lower, int upper)
{
    if(upper <=  lower) return;

    int pivot = nums[lower];
    int start = lower;
    int stop = upper;

    while(lower < upper)
    {
        while(nums[lower] <= pivot && lower < upper) lower++;

        while(nums[upper] > pivot && lower <= upper) upper--;

        if(lower < upper) std::swap(nums[upper], nums[lower]);
    }

    std::swap(nums[upper], nums[start]);
    quickSortHelper(nums, start, upper-1);
    quickSortHelper(nums, upper+1, stop);
}

void quickSort(std::vector<int>& nums)
{
    int size = nums.size();
    quickSortHelper(nums, 0, size-1);
}

int main()
{
    std::vector<int> example = {1, 4, 7, 9, 24, 12, 21, 17, 11, 10, 28, 31, 50, 41, 44, 40, 46, 33};
    quickSort(example);
    for(int value : example)
    {
        std::cout << value << std::endl;
    }
}