#include <iostream>
#include <vector>
#include <stack>

class Graph
{
private: 

    // Hold the struct for the edge
    struct Edge
    {

        // Hold the edge source vertex
        int src;

        // Hold the edge destination vertex
        int dest;

        // Hold the weight of the edge
        int cost;

        // Constructor
        Edge(int src, int dst, int cst);
    };

    // Hold the amount of nodes
    int count;

    // Hold the adjacency list
    std::vector<std::vector<Edge>> Adj;

    // Hold a custom comparator for the edges
    struct EdgeComparator
    {
        bool operator()(Edge* x, Edge* y)
        {
            return (x->cost > y->cost);
        }
    };

    // Hold another compare function
    static bool compare(Edge* e1, Edge* e2)
    {
        return (e1->cost < e2->cost);
    }

public:

    /*
    Create a graph that is stored using an adjacency list
    @param int cnt the amount of nodes in the graph
    @return Graph
    */
    Graph(int cnt);

    /*
    Add a directed edge to the graph
    @param int source the source vertex
    int destination the destination vertex
    int cost the weight of the edge
    @return void
    */
    void addDirectedEdge(int source, int destination, int cost = 1);

    /*
    Add an undirected edge to the graph
    @param int source the source vertex
    int destination the destination vertex
    int cost cost the weight of the edge
    @return void
    */
    void addUndirectedEdge(int source, int destination, int cost = 1);

    /*
    Print the adjacency list
    */
    void print();

    /*
    DFS Algorithm implementation using stack
    @param int source the source of the path
    int target the target we are looking for
    @return bool true if the path exists in the path
    */
   bool dfsStack(int source, int target);

    /*
    DFS recursive algorithm
    @param int source the source of the path 
    int target the target we are looking for
    @return bool true if the path exists in the path
    */
    bool dfsRecursive(int source, int target);

    /*
    DFS recursive algorithm helper
    @param int index the current vertex
    vector<bool> visited the vector that holds the visited vertices
    @return void
    */
    void dfsRecursiveHelper(int index, std::vector<bool>& visited);


   
};

Graph::Edge::Edge(int s, int d, int c = 1)
{

    // Set the variables for the edge
    src = s;
    dest = d;
    cost = c;
}

Graph::Graph(int cnt)
{

    // Set the count of the graph
    count = cnt;

    // Create the adjacency list
    Adj = std::vector<std::vector<Edge>>(cnt);
}

void Graph::addDirectedEdge(int source, int dest, int cost)
{

    // Add the directed edge
    Adj[source].push_back(Edge(source, dest, cost));
}

void Graph::addUndirectedEdge(int source, int dest, int cost)
{

    // Add the directed edges
    addDirectedEdge(source, dest, cost);
    addDirectedEdge(dest, source, cost);
}

void Graph::print()
{

    // Loop through the vertexes
    for(int i = 0; i < count; i++)
    {

        // Hold the list
        auto &adl = Adj[i];

        // Print the vertex
        std::cout << "Vertex " << i << " is connected to: ";
        for(auto adn : adl)
        {

            // Print the cost and destination
            std::cout << adn.dest << "(cost : " << adn.cost << ") ";
        }

        // Print a new line
        std::cout << std::endl;
    }
}

bool Graph::dfsStack(int source, int target)
{

    // Hold a visted vector for the vertices
    std::vector<bool> visited(count, false);

    // Hold a stack 
    std::stack<int> MyStack;
    
    // Mark the source as true
    visited[source] = true;

    // Push the source
    MyStack.push(source);
    
    // Hold the current vertex
    int curr;

    // Loop until the stack is empty
    while(!MyStack.empty())
    {

        // Hold the top of the stack
        curr = MyStack.top();

        // Pop the top of the stack
        MyStack.pop();

        // Hold the adjacency list
        auto &adl = Adj[curr];

        // Loop through each edge in the list
        for(auto adn : adl)
        {

            // Check if we didn't visit the vertex
            if(visited[adn.dest] == false)
            {

                // Set the vertex to visited
                visited[adn.dest] = true;

                // Push the vertex visited
                MyStack.push(adn.dest);
            }
        }
    }

    // Return if we visited the target
    return visited[target];
}

bool Graph::dfsRecursive(int source, int target)
{

    // Hold the visited vector
    std::vector<bool> visited(count, false);

    // Call the recursive helper
    dfsRecursiveHelper(source, visited);
    
    // Return if visited the target
    return visited[target];
}

void Graph::dfsRecursiveHelper(int index, std::vector<bool>& visited)
{

    // Set the vertex visited to true
    visited[index] = true;

    // Hold the adjancency list for the vertex
    auto &adl = Adj[index];

    // Loop through the edges
    for(auto adn : adl)
    {

        // Check if we visited this vertex
        if(visited[adn.dest] == false)
        {

            // Recursive call dfs
            dfsRecursiveHelper(adn.dest, visited);
        }
    }
}


int main() {
    Graph graph(6);

    graph.addUndirectedEdge(0, 1);
    graph.addUndirectedEdge(0, 2);
    graph.addUndirectedEdge(1, 3);
    graph.addUndirectedEdge(2, 4);
    graph.addUndirectedEdge(4, 5);

    graph.print();

    int sourceVertex = 0;
    int targetVertex = 5;

    if (graph.dfsStack(sourceVertex, targetVertex)) {
        std::cout << "There is a path from vertex " << sourceVertex << " to vertex " << targetVertex << ".\n";
    } else {
        std::cout << "There is no path from vertex " << sourceVertex << " to vertex " << targetVertex << ".\n";
    }

    if (graph.dfsRecursive(sourceVertex, targetVertex)) {
        std::cout << "There is a path from vertex " << sourceVertex << " to vertex " << targetVertex << ".\n";
    } else {
        std::cout << "There is no path from vertex " << sourceVertex << " to vertex " << targetVertex << ".\n";
    }

    return 0;
}