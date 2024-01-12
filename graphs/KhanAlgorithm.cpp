#include <iostream>
#include <vector>
#include <queue>


int main()
{

    // Hold an adjacency list
    std::vector<std::vector<int>> adjacencyList(5);

    // Hold the indegrees
    std::vector<int> indegrees(5, 0);

    // Hold the edges
    std::vector<std::vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {4, 0},
        {1, 4}
    };

    // Construct the adjacency list
    for(std::vector<int> edge : edges)
    {

        // Add to the adjacency list
        adjacencyList[edge[1]].push_back(edge[0]);

        // Increment the indegrees
        indegrees[edge[0]]++;
    }

    // Loop through the adjacency list
    for(int i = 0; i < adjacencyList.size(); i++)
    {
        
        // Print the vertex
        std::cout << "This is vertex: " << i << std::endl;

        // Print the vertex
        std::cout << "Neighbors: ";

        // Loop through the neighbors
        for(int neighbor : adjacencyList[i])
        {

            // Print the neighbor 
            std::cout << neighbor << " ";
        }

        // Print indegrees
        std::cout << std::endl;
        std::cout << "Indegrees: " << indegrees[i] << std::endl;
    }

    // Hold the vertices visited
    int visitedVertices = 0;
    
    // Hold the queue
    std::queue<int> MyQueue;

    // Push all the nodes with 0 indegrees
    for(int i = 0; i < 5; i++)
    {

        // Check if the indegrees is 0
        if(indegrees[i] == 0) MyQueue.push(i);
    }

    // Loop until the queue is empty
    while(!MyQueue.empty())
    {

        // Hold the vertex
        int vertex = MyQueue.front();

        // Pop the vertex
        MyQueue.pop();

        // Increment nodes visited
        visitedVertices++;

        // Loop through the neighbors of the vertex
        for(int neighbor : adjacencyList[vertex])
        {
            std::cout << vertex << std::endl;
            // Decrement the indegrees
            indegrees[neighbor]--;

            // Check if we can add it to our queue
            if(indegrees[neighbor] == 0)
            {

                // Push the neighbor
                MyQueue.push(neighbor);
            }
        }
    }

    // Return the result
    std::cout << visitedVertices << std::endl;
}       
