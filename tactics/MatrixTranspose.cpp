#include <iostream>
#include <vector>

/*
This is how you transpose a matrix which is swapping its columns for its rows
*/

/*
Print a matrix
*/
void printMatrix(const std::vector<std::vector<int>>& matrix) 
{

    // Loop through rows
    for (const auto& row : matrix) 
    {

        // Loop through columns
        for (int num : row) 
        {

            // Print the num
            std::cout << num << " ";
        }

        // New line after the row
        std::cout << "\n";
    }
}

int main ()
{

    // Hold an example matrix 
    std::vector<std::vector<int>> matrix = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Hold the matrix size
    int n = matrix.size();

    // Loop through rows
    for (int i = 0; i < n; i++) 
    {

        // Loop through columns
        for (int j = i + 1; j < n; j++) 
        {

            // Swap elements
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Print the matrix
    printMatrix(matrix);
}