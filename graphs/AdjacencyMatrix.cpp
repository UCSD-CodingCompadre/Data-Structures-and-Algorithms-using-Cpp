#include <iostream>
#include <vector>

class GraphAdjacencyMatrix
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
    GraphAdjacencyMatrix(int count);

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

GraphAdjacencyMatrix::GraphAdjacencyMatrix(int count)
{

    // Hold the amount of nodes
    this->count = count;

    // Create the matrix 
    matrix = std::vector<std::vector<int>>(count, std::vector<int>(count, 0));
}

void GraphAdjacencyMatrix::addDirectedEdge(int src, int dst, int cost)
{

    // Add the directed edge with the cost
    matrix[src][dst] = cost;
}

void GraphAdjacencyMatrix::addUndirectedEdge(int src, int dst, int cost)
{

    // Add two directed edges with the cost
    addDirectedEdge(src, dst, cost);
    addDirectedEdge(dst, src, cost);
}

void GraphAdjacencyMatrix::print()
{

    // Loop through the rows
    for(int i = 0; i < count; i++)
    {

        // Print the vertex
        std::cout << "Vertex: " << i << " is connected to : ";

        // Loop through the columns
        for(int j = 0; j < count; j++)
        {

            // Check if the edge exists
            if(matrix[i][j] != 0)
            {

                // Print the vertex and the cost 
                std::cout << j << "(cost : " << matrix[i][j] << ") ";
            }
        }

        // Print new line
        std::cout << std::endl;
    }
}

int main() {
    // Example usage:
    GraphAdjacencyMatrix graph(4);
    graph.addDirectedEdge(0, 1, 2);
    graph.addUndirectedEdge(1, 2, 3);
    graph.print();

    return 0;
}