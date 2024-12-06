#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    void addEdge(int start, int end) {
        adjMatrix[start][end] = 1;
    }

    void removeEdge(int start, int end) {
        adjMatrix[start][end] = 0;
    }

    void display() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};
int main() {
    Graph g(10);
    int matrix[24][2] = {
        {0, 1}, {0, 2}, {1, 0}, {1, 3}, {1, 4}, {2, 0}, {2, 5}, {2, 6},
        {3, 1}, {3, 7}, {4, 1}, {4, 7}, {5, 2}, {5, 8}, {6, 2}, {6, 8},
        {7, 3}, {7, 4}, {7, 9}, {8, 5}, {8, 6}, {8, 9}, {9, 7}, {9, 8}
    };
    for (int i = 0; i < 24; ++i) {
        g.addEdge(matrix[i][0], matrix[i][1]);
    }

    g.display();

    return 0;
}