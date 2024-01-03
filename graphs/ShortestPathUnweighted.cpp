#include <iostream>
#include <vector>
#include <limits>
#include <queue>

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
    Find the shortest path to each vertex from the source vertex
    in an unweighted graph
    @param int source the source to start calculating shortest paths
    @return void
    */
   void shortestPath(int source);

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

void Graph::shortestPath(int source)
{

    // Hold the previous vertex for the given path
    std::vector<int> previous(count, -1);

    // Hold the distance from the source to the desired vertex
    std::vector<int> distance(count, std::numeric_limits<int>::max());

    // Hold a queue
    std::queue<int> MyQueue;
    
    // Push the source vertex to the queue
    MyQueue.push(source);

    // Set the distance to the source to 0
    distance[source] = 0;

    // Set the source path to source
    previous[source] = source;

    // Loop until the queue is empty
    while(!MyQueue.empty())
    {

        // Hold the current vertex
        int curr = MyQueue.front();

        // Pop the vertex from the queue
        MyQueue.pop();

        // Hold the adjacency list
        auto &adl = Adj[curr];

        // Loop through the edges of the adjancency list
        for(auto adn : adl)
        {

            // Check if the there is no path 
            if(distance[adn.dest] == std::numeric_limits<int>::max())
            {

                // Set the distance 
                distance[adn.dest] = distance[curr] + 1;

                // Set the previous node in this path
                previous[adn.dest] = curr;

                // Push the destination vertex
                MyQueue.push(adn.dest);
            }
        }
    }

    // Print the source vertex
    std::cout << "Shortest Paths from Source Vertex " << source << ":\n";
    
    // Loop through each vertex
    for (int i = 0; i < count; i++) 
    {

        // Print the destination vertex
        std::cout << "To Vertex " << i << ": ";

        // Reconstruct and print the path
        int currentVertex = i;

        // Loop until the vertex is not source
        while (currentVertex != source && currentVertex != -1) 
        {

            // Print the path
            std::cout << currentVertex << " <- ";
            
            // Hold the current vertex
            currentVertex = previous[currentVertex];
        }

        // Check if the vertex is -1
        if (currentVertex == -1) 
        {

            // Print no path exists
            std::cout << "No path exists.";
        } 

        // Else print the source
        else 
        {
            std::cout << source;
        }

        // Print the distance 
        std::cout << " (Distance: " << distance[i] << ")\n";
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
    graph.shortestPath(sourceVertex);
    return 0;
}