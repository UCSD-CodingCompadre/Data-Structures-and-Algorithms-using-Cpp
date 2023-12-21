#include <iostream> 
#include <stack>

/*
This is a stack that follows a Last-In-First-Out sorting order.
*/

int main()
{

    // Hold an example stacks
    std::stack<int> MyStack;

    // Push elements
    MyStack.push(1);
    MyStack.push(2);
    MyStack.push(3);
    MyStack.push(4);
    MyStack.push(5);

    // Print stack size
    std::cout << "Stack size: " << MyStack.size() << std::endl;

    // Loop until stack is empty
    while(!MyStack.empty())
    {

        // Print the element at the top of the stack
        std::cout << MyStack.top() << std::endl;

        // Pop the top element from the stack
        MyStack.pop();
    }
}