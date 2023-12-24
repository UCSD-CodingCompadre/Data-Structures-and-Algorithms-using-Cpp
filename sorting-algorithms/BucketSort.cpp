#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

void bucketSort(std::vector<int> &arr, int maxValue, int numBucket)
{

    // Hold the size
    int size = arr.size();

    // Check if the size is 0
    if(size == 0) return;

    // Create the buckets
    std::vector<std::vector<int>> MyBuckets(numBucket);

    // Loop through the buckets and push an empty vector
    for(std::vector<int>& MyBucket : MyBuckets)
    {

        // Create an empty bucket
        MyBucket = std::vector<int>();
    }

    // Hold the range of each bucket
    int div = std::ceil(static_cast<double>(maxValue) / numBucket);

    // Add elements into the buckets
    for(int i = 0; i < size; i++)
    {

        // Check if the value can not be placed in a bucket
        if(arr[i] < 0 || arr[i] > maxValue)
        {

            // Print out an error message
            std::cout << "Value out of range." << std::endl;

            // End the function
            return;
        }

        // Hold the corresponding bucket index
        int bucketIndex = (arr[i] / div);

        // Maximum value will be assigned to last bucket
        if(bucketIndex >= numBucket)
        {

            // Set the bucket index to be the last bucket
            bucketIndex = numBucket - 1;
        }

        // Push the value into the corresponding bucket
        MyBuckets[bucketIndex].push_back(arr[i]);
    }

    // Sort the elements in each bucket
    for(std::vector<int>& MyBucket : MyBuckets)
    {

        // Sort the bucket
        std::sort(MyBucket.begin(), MyBucket.end());
    }

    // Hold the index of the result vector
    int index = 0;

    // Loop through each bucket
    for(int i = 0; i < numBucket; i++)
    {

        // Hold the vector from the bucket
        std::vector<int> MyTempVector = MyBuckets[i];

        // Hold the size of the vector
        int MyTempVectorSize = MyTempVector.size();

        // Loop through the bucket
        for(int j  = 0; j < MyTempVectorSize; j++)
        {

            // Insert the element in the correct index
            arr[index++] = MyTempVector[j];
        }
    }
}

void bucketSort(std::vector<int> &arr, int maxValue)
{

    // Hold the amount of buckets
    int numBucket = 5;

    // Call the bucket sort function
    bucketSort(arr, maxValue, numBucket);
}

int main()
{

    // Hold an example vector
    std::vector<int> array = {1, 34, 7, 99, 5, 23, 45, 88, 77, 19, 91, 100};

    // Hold the max value
    int maxValue = 100;

    // Call the bucket sort function
    bucketSort(array, maxValue);

    // Loop through the array and print the elements
    for(int MyInt : array)
    {

        // Print the int
        std::cout << MyInt << " ";

    }

    std::cout << std::endl;
}