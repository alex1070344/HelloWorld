#include <iostream>
#include <vector>

#define N 12

using namespace std;

int maze[N][N] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1}, 
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0);
}

void printSolution(vector<pair<int, int>> &path) {
    for (auto p : path) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

void solveMazeUtil(int x, int y, vector<pair<int, int>> &path) {
    if (x == N-2 && y == N-2) {
        path.push_back({x, y});
        printSolution(path);
        path.pop_back();
        return;
    }

    if (isSafe(x, y)) {
        path.push_back({x, y});
        maze[x][y] = 2; // mark as visited

        solveMazeUtil(x + 1, y, path); // move down
        solveMazeUtil(x - 1, y, path); // move up
        solveMazeUtil(x, y + 1, path); // move right
        solveMazeUtil(x, y - 1, path); // move left

        maze[x][y] = 0; // unmark as visited
        path.pop_back();
    }
}

void solveMaze() {
    vector<pair<int, int>> path;
    solveMazeUtil(1, 1, path);
}

int main() {
    solveMaze();
    return 0;
}