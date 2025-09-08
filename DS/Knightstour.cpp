#include <iostream>
#include <iomanip> // for setw()
#include <cstdlib> // for rand()
#include <ctime> // for srand(time(0))

using namespace std;

const int N = 8;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2}; // All possible x - directions, w.r.t. (0,0)
int dy[8] = {1, 2,  2,  1, -1, -2, -2, -1}; //All possible y - directions, w.r.t. (0,0)

bool isValid(int x, int y, int board[N][N]){
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0);
}

int countOnwardMoves(int x, int y, int board[N][N]){
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, board))
            count++;
    }
    return count;
}

bool knightsTour(int board[N][N], int x, int y, int moveNum) {
    board[x][y] = moveNum;

    if (moveNum == N * N)
        return true;

    int min_deg = 9;
    int next_x = -1, next_y = -1;

    int move_order[8];
    for(int i = 0; i < 8; i++){
        move_order[i] = i;
    }

    for(int i = 0; i < 8; ++i){
        int r = rand() % 8;
        int temp = move_order[i];
        move_order[i] = move_order[r];
        move_order[r] = temp;
    }

    for (int i = 0; i < 8; i++){
        int d = move_order[i];
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (isValid(nx, ny, board)){
            int c = countOnwardMoves(nx, ny, board);
            if (c < min_deg){
                min_deg = c;
                next_x = nx;
                next_y = ny;
            }
        }
    }

    if (next_x == -1 || next_y == -1)
        return false;

    if (knightsTour(board, next_x, next_y, moveNum + 1))
        return true;

    board[x][y] = 0;
    return false;
}


void printBoard(int board[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------" << endl;
}

int main(){
    srand(time(0));

    int board[N][N] = {0};

    int startX = 0, startY = 0; 
    bool success = knightsTour(board, startX, startY, 1);

    if (success) {
        cout << "Knight's Tour completed successfully!\n";
        printBoard(board);
    } else {
        cout << "Failed to complete Knight's Tour.\n";
    }

    return 0;
}
