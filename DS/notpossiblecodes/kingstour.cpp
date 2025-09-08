#include <iostream>
#include <iomanip>
using namespace std;

const int N = 8;

// Possible knight moves
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Check if position is inside board and not visited
bool isValid(int x, int y, int board[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Count available moves from a position
int countOnwardMoves(int x, int y, int board[N][N]) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, board))
            count++;
    }
    return count;
}

// Warnsdorff's algorithm
bool knightTour(int board[N][N], int x, int y) {
    board[x][y] = 1; // Start from 1
    for (int move = 2; move <= N * N; ++move) {
        int min_deg = 9, next_x = -1, next_y = -1;

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, board)) {
                int deg = countOnwardMoves(nx, ny, board);
                if (deg < min_deg) {
                    min_deg = deg;
                    next_x = nx;
                    next_y = ny;
                }
            }
        }

        if (next_x == -1 || next_y == -1)
            return false; // No valid move

        x = next_x;
        y = next_y;
        board[x][y] = move;
    }
    return true;
}

// Print board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << setw(3) << board[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int board[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = -1;

    int startX = 0, startY = 0; // You can change the start position

    if (knightTour(board, startX, startY))
        printBoard(board);
    else
        cout << "No solution found.\n";

    return 0;
}
