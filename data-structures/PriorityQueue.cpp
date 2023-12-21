#include <iostream> 
#include <queue>
#include <vector>

/*
This is a priority queue that maintains a min or max order of elements.
*/

// Custom compare struct
struct compare
{

    // Override the comparison operator
    bool operator()(const int & a, const int & b)
    {
        return a>b;
    }
};

int main()
{

    // Hold an example priority queue
    // std::priority_queue<int> MyPriorityQueue;

    // Construct min priority queue using custom compare struct
    std::priority_queue<int, std::vector<int>, compare> MyPriorityQueue;

    // Push elements
    MyPriorityQueue.push(1);
    MyPriorityQueue.push(4);
    MyPriorityQueue.push(5);
    MyPriorityQueue.push(2);
    MyPriorityQueue.push(3);

    // Print queue size
    std::cout << "queue size: " << MyPriorityQueue.size() << std::endl;

    // Loop until queue is empty
    while(!MyPriorityQueue.empty())
    {

        // Print the element at the top of the queue
        std::cout << MyPriorityQueue.top() << std::endl;

        // Pop the top element from the queue
        MyPriorityQueue.pop();
    }

}