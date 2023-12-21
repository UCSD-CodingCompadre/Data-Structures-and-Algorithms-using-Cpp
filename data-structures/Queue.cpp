#include <iostream> 
#include <queue>

/*
This is a queue that follows a First-In-First-Out sorting order.
*/

int main()
{

    // Hold an example stacks
    std::queue<int> MyQueue;

    // Push elements
    MyQueue.push(1);
    MyQueue.push(2);
    MyQueue.push(3);
    MyQueue.push(4);
    MyQueue.push(5);

    // Print queue size
    std::cout << "queue size: " << MyQueue.size() << std::endl;

    // Loop until queue is empty
    while(!MyQueue.empty())
    {

        // Print the element at the top of the queue
        std::cout << MyQueue.front() << std::endl;

        // Pop the top element from the queue
        MyQueue.pop();
    }
}
