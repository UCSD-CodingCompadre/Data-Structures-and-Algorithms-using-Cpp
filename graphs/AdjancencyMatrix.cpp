#include <iostream>
#include <vector>

class GraphAdjancenyMatrix
{

private:

    // Hold the amount of nodes in the matrix
    int count;

    // Hold the matrix 
    std::vector<std::vector<int>> matrix;
    
    // Define the edges of the matrix
    struct Edge
    {

        // Hold the desitination of the edge
        int destination;

        // Hold the cost of the edge
        int cost;
        
        // Construct an edge
        Edge(int dst, int cst)
        {

            // Hold the destination
            destination = dst;

            // Hold the cost
            cost = cst;
        }
    };

    // Hold a comparator for the edges
    struct EdgeComparator
    {

        // Create the definition of the bool operator
        bool operator()(Edge* x, Edge* y)
        {
            return x->cost > y->cost;
        }
    };

public:

    /*
    Create an adjanceny matrix using the expected amount of nodes
    @param int count the amount of nodes in the graph
    @return none
    */
    GraphAdjancenyMatrix(int count);

    /*
    Create a directed edge in the adjancency matrix
    @param int src the soure of the edge
    int dst the destination of the edge
    int cost the cost of the edge
    @return void
    */
    void addDirectedEdge(int src, int dst, int cost = 1);

    /*
    Create an undirected edge in the adjancency matrix
    @param int the source of the edge
    int dst the destination of the edge
    int cost the cost of the edge
    @return void
    */
    void addUndirectedEdge(int src, int dst, int cost = 1);

    /*
    Print the adjancency matrix 
    @param none
    @return void
    */
    void print();
};

GraphAdjancenyMatrix::GraphAdjancenyMatrix(int count)
{

    count = count;
    matrix = std::vector<std::vector<int>>(count, std::vector<int>(count, 0));
}