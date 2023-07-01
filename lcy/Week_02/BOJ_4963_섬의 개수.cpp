#include <iostream>
#define MAX 51
using namespace std;

int arr[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { false };

int w, h, numOfIsland;

// 우,하,좌,상,우상,우하,좌상,좌하
int dw[8] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
int dh[8] = { 0, 1, 0 , -1, -1, 1,-1, 1 };

void dfs(int h, int w) {
    for (int i = 0; i < 8; i++) {
        int nh = h + dh[i];
        int nw = w + dw[i];

        if (nh < 0 || nh >= MAX || nw < 0 || nw >= MAX)
            continue;
        if (arr[nh][nw] == 1 && visited[nh][nw] == false) {
            visited[nh][nw] = true;
            dfs(nh, nw);
        }
    }
}

void reset() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            arr[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void countIsland() {
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (arr[i][j] == 1 && visited[i][j] == false) {
                visited[i][j] = true;
                dfs(i, j);
                numOfIsland++;
            }
        }
    }
    cout << numOfIsland << endl;
}

int main() {
    while (1) {
        cin >> w >> h;
        numOfIsland = 0;
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
            }
        }
        countIsland();
        reset();
    }
}