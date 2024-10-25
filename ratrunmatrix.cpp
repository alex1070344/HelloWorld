#include <iostream>
#include <vector>

#define N 12

using namespace std;
//迷宮地圖
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
//檢查是否安全
bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0);
}
//印出路徑
void printSolution(vector<pair<int, int>> &path) {
    for (auto p : path) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

void solveMazeUtil(int x, int y, vector<pair<int, int>> &path) {
    //到達終點
    if (x == N-2 && y == N-2) {
        path.push_back({x, y});
        printSolution(path);
        path.pop_back();
        return;
    }

    if (isSafe(x, y)) {
        //將當前座標加入路徑
        path.push_back({x, y});
        maze[x][y] = 2; // mark as visited
        //遞迴，先後順序為下、上、右、左
        solveMazeUtil(x + 1, y, path); // move down
        solveMazeUtil(x - 1, y, path); // move up
        solveMazeUtil(x, y + 1, path); // move right
        solveMazeUtil(x, y - 1, path); // move left

        maze[x][y] = 0; // unmark as visited
        path.pop_back();
    }
}

void solveMaze() {
    //向量儲存路徑
    vector<pair<int, int>> path;
    //設定起點為(1, 1)
    solveMazeUtil(1, 1, path);
}

int main() {
    //解迷宮
    solveMaze();
    return 0;
}