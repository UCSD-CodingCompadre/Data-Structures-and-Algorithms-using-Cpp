#include <iostream>
#include <vector>

/*
This is an example problem for the second type of dymanic programming problems.
This type is State Selection.
*/

int maxProfit(std::vector<int>& prices) 
{
    
    // Edge cases
    if(prices.size() == 1 || (prices.size() == 2 && prices[0] > prices [1])) return 0;
    
    // Hold left pointer
    int leftPointer = 0;
    
    // Hold right pointer
    int rightPointer = 0;
    
    // Hold max profit
    int maxProfit = 0;
    
    // Hold the sell price
    int sellPrice = 0;
    
    // Loop through the prices
    while(rightPointer != prices.size())
    {
        
        // Hold current profit/loss
        int currentProfit = prices[rightPointer] - prices[leftPointer];
        
        // Check if we have a new profit
        if(currentProfit > 0 && currentProfit > maxProfit)
        {
            
            // Hold the price it was sold at
            sellPrice = prices[rightPointer];
            
            // Set the new max profit
            maxProfit = currentProfit;
        }
        
        // Else check if we have a max profit
        else if(maxProfit > 0 && prices[rightPointer] > sellPrice)
        {
            // Set new max profit
            maxProfit += prices[rightPointer] - sellPrice;
            
            // Hold the new sell price
            sellPrice = prices[rightPointer];
            
        }
        // Else check if we potentially have a new lower limit
        else if(prices[rightPointer] < prices[leftPointer])
        {
            
            // Set a new left pointer
            leftPointer = rightPointer;
        }
        
        // Increment the right pointer
        rightPointer++;
    }
    
    // Return the max profit
    return maxProfit;
}