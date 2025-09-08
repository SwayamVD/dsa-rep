#include <iostream>
#include <cstdlib> // for rand()
#include <ctime> // for srand(time(0))

using namespace std;

const int MAX = 20; 
int dx[8] = {-1, -1,  0, 1, 1, 1, 0, -1};
int dy[8] = { 0,  1,  1, 1, 0,-1,-1, -1};

void display(bool visited[MAX][MAX], int n, int m, int x, int y){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == x && j == y)
                cout << "C ";
            else if (visited[i][j])
                cout << ". ";
            else
                cout << "# ";
        }
        cout << endl;
    }
    cout << "--------------------------" << endl;
}

int main() {
    srand(time(0));
    
    int n = 10, m = 10;
    bool visited[MAX][MAX] = {false};

    int x = n / 2;
    int y = m / 2;
    visited[x][y] = true;

    int totalVisited = 1;
    int totalMoves = 0;

    display(visited, n, m, x, y);

    while(totalVisited < n * m){
        int dir = rand() % 8;
        int newX = x + dx[dir];
        int newY = y + dy[dir];

        if(newX >= 0 && newX < n && newY >= 0 && newY < m){
            x = newX;
            y = newY;
            if(!visited[x][y]){
                visited[x][y] = true;
                totalVisited++;
            }
            totalMoves++;
            display(visited, n, m, x, y);
        }
    }

    cout << "All tiles visited!" << endl;
    cout << "Total moves made: " << totalMoves << endl;

    return 0;
}
