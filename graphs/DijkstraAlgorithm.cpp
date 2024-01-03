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
    Find the shortest paths using a positive weighted graph
    @param int source the source of the paths
    @return void
    */
   void dijkstra(int source);
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

void Graph::dijkstra(int source)
{

    // Hold the previous vertices
    std::vector<int> previous(count, -1);

    // Hold the current distance
    std::vector<int> dist(count, std::numeric_limits<int>::max());

    // Hold the visited nodes
    std::vector<bool> visited(count, false);

    // Set the distance to source to 0
    dist[source] = 0;
    
    // Set the previous vertex of source to source
    previous[source] = source;

    // Hold the priority queue 
    std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> MyPriorityQueue;

    // Hold a new edge
    Edge* node = new Edge(source, source, 0);

    // Push the edge into the priority queue
    MyPriorityQueue.push(node);

    // Loop until the priority queue is empty
    while(!MyPriorityQueue.empty())
    {

        // Hold the node at the top of the priority queue
        node = MyPriorityQueue.top();

        // Pop the top element from the priority queue
        MyPriorityQueue.pop();
        
        // Hold the source vertex
        int src = node->dest;

        // Set the visited vertex to true
        visited[src] = true;

        // Hold the adjancency list
        auto &adl = Adj[src];

        // Loop through the adjanceny list
        for(auto adn : adl)
        {

            // Hold the destination vertex
            int dest = adn.dest;

            // Hold the alternative path
            int alt = adn.cost + dist[src];

            // Check if path is greater and the node is not visisted
            if(dist[dest] > alt && visited[dest] == false)
            {

                // Set the new distance
                dist[dest] = alt;

                // Set the previous node 
                previous[dest] = src;

                // Create a new edge 
                node = new Edge(src, dest, alt);

                // Push the edge into the priority queue
                MyPriorityQueue.push(node);
            }
        }
    }

    // Print the source vertex
    std::cout << "Shortest Paths from Source Vertex " << source << " using Dijkstra's Algorithm:\n";

    // Loop through all the vertices
    for (int i = 0; i < count; i++) 
    {

        // Print the destination vertex
        std::cout << "To Vertex " << i << ": ";

        // Reconstruct and print the path
        int currentVertex = i;

        // Loop until the current vertex is not source
        while (currentVertex != source && currentVertex != -1) 
        {

            // Print the path
            std::cout << currentVertex << " <- ";

            // Set the new current vertex
            currentVertex = previous[currentVertex];
        }

        // Check if the current vertex is -1
        if (currentVertex == -1) 
        {

            // Print no path exists
            std::cout << "No path exists.";
        } 
        else 
        {

            // Print the source
            std::cout << source;
        }

        // Print the distance
        std::cout << " (Distance: " << dist[i] << ")\n";
    }
}

int main() {
    Graph graph(6);

    graph.addUndirectedEdge(0, 1, 4);
    graph.addUndirectedEdge(0, 2, 2);
    graph.addUndirectedEdge(1, 3, 5);
    graph.addUndirectedEdge(2, 4, 1);
    graph.addUndirectedEdge(4, 5, 3);

    graph.print();

    int sourceVertex = 0;
    graph.dijkstra(sourceVertex);

    return 0;
}