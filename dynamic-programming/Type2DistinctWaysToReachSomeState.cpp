#include <iostream>
#include <vector>

/*
This is an example problem for the second type of dymanic programming problems.
This type is Distinct Ways to Reach Some State.
*/

int climbStairs(int n) 
{
    
    // Edge case
    if(n < 2) return n;
    
    // Hold the steps vector
    std::vector<int>steps(n);
    
    // Hold the first steps
    steps[0] = 1;
    steps[1] = 2;
    
    // Loop and populate steps vector
    for(int currentStep = 2; currentStep < n; currentStep++)
    {
        steps[currentStep] = steps[currentStep-1] + steps[currentStep-2];
    }
    
    // Return the steps we need
    return steps[n-1];
}