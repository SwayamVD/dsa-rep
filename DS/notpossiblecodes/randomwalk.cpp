#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 10; // Rows
const int M = 10; // Columns

// 8 directions: N, NE, E, SE, S, SW, W, NW
int dx[8] = {-1, -1,  0, 1, 1,  1, 0, -1};
int dy[8] = { 0,  1,  1, 1, 0, -1, -1, -1};

// Check if position is inside grid
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

// Check if all tiles are visited
bool allVisited(const vector<vector<bool>>& visited) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (!visited[i][j])
                return false;
    return true;
}

int main() {
    srand(time(0)); // Seed random

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    // Start from the center
    int x = N / 2;
    int y = M / 2;
    visited[x][y] = true;

    int moves = 0;

    while (!allVisited(visited)) {
        int dir = rand() % 8;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (isValid(nx, ny)) {
            x = nx;
            y = ny;
            visited[x][y] = true;
            moves++;
        }
    }

    cout << "All tiles visited in " << moves << " moves." << endl;
    return 0;
}
