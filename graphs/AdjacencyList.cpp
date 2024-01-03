#include <iostream>
#include <vector>

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

int main() 
{
    // Example usage:
    Graph graph(4);
    graph.addDirectedEdge(0, 1, 2);
    graph.addUndirectedEdge(1, 2, 3);
    graph.print();

    return 0;
}