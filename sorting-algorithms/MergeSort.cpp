#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, std::vector<int> &tempArray, int lowerIndex, int middleIndex, int upperIndex)
{

    // Hold the the lower start
    int lowerStart = lowerIndex;

    // Hold the lower stop
    int lowerStop = middleIndex;

    // Hold the upper start
    int upperStart = middleIndex + 1;

    // Hold the upper stop
    int upperStop = upperIndex;

    // Hold the count
    int count = lowerIndex;

    // Loop until one the lower or upper reaches a stop
    while(lowerStart <= lowerStop && upperStart <= upperStop)
    {

        // Check if the element in the lower section is in the correct index;
        if(arr[lowerStart] < arr[upperStart])
        {

            // Move along the lower section
            tempArray[count++] = arr[lowerStart++];
        }

        // Else the upper element is smaller
        else
        {

            // Move along the upper section 
            tempArray[count++] = arr[upperStart++];
        }
    }

    // Loop the rest of the lower section
    while(lowerStart <= lowerStop)
    {

        // Insert the element 
        tempArray[count++] = arr[lowerStart++];
    }

    // Loop the rest of the upper section
    while(upperStart <= upperStop)
    {
        
        // Insert the element
        tempArray[count++] = arr[upperStart++];
    }

    // Loop from the lower start to the upper end
    for(int i = lowerIndex; i <= upperIndex; i++)
    {

        // Insert the element in the original array
        arr[i] = tempArray[i];
    }
}

void mergeSortUtil(std::vector<int> &arr, std::vector<int> &tempArray, int lowerIndex, int upperIndex)
{

    // Check if the lower index is past the upper index
    if(lowerIndex >=  upperIndex) return;

    // Hold a middle index 
    int middleIndex = (lowerIndex + upperIndex) / 2;

    // Recursive call the helper function
    mergeSortUtil(arr, tempArray, lowerIndex, middleIndex);
    mergeSortUtil(arr, tempArray, middleIndex + 1, upperIndex);

    // Call the merge function
    merge(arr, tempArray, lowerIndex, middleIndex, upperIndex);
}

int main()
{

    std::vector<int> MyVector = {1, 6, 9, 2, 4, -1, 11, 8, -4, -2, 15, 0};

    int size = MyVector.size();
    std::vector<int> MyTempVector(size);
    mergeSortUtil(MyVector, MyTempVector, 0, size-1);

    // Print vector
    for(int MyInt : MyVector) 
    {
        std::cout << MyInt << ' ';
    }

    std::cout << std::endl;
}