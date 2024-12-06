#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 結構體表示一條邊，包含兩個頂點和一個權重
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// 類表示並查集數據結構
class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // 查找根節點並壓縮路徑
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    // 合併兩個集合
    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

private:
    vector<int> parent; // 父節點數組
    vector<int> rank;   // 節點的秩數組
};

int main() {
    int n = 6; // 節點數量
    vector<Edge> edges = {
        {0, 1, 10}, {1, 2, 20}, {1, 3, 25}, {2, 4, 18}, {3, 4, 22},
        {3, 5, 95}, {4, 5, 77}
    };

    // 將邊按權重排序
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    vector<Edge> mst; // 最小生成樹
    int mst_cost = 0; // 最小生成樹的總成本

    // Kruskal算法構建最小生成樹
    for (const auto& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unite(edge.u, edge.v);
            mst.push_back(edge);
            mst_cost += edge.weight;
        }
    }

    // 構建鄰接矩陣
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    for (const auto& edge : edges) {
        adjMatrix[edge.u][edge.v] = edge.weight;
        adjMatrix[edge.v][edge.u] = edge.weight; // 假設無向圖
    }

    // 輸出鄰接矩陣
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Dijkstra算法計算從頂點0到其他頂點的最短距離
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n - 1; ++i) {
        int minDist = INT_MAX, u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    // 輸出從頂點0到其他頂點的最短距離
    cout << "Minimum distances from vertex 0:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "1 to " << i+1 << " : " << dist[i] << endl;
    }

    // 輸出最小生成樹
    cout << "Minimum Cost Spanning Tree:" << endl;
    for (const auto& edge : mst) {
        cout << edge.u+1 << " - " << edge.v+1 << " : " << edge.weight << endl;
    }
    cout << "Total cost: " << mst_cost << endl;

    return 0;
}