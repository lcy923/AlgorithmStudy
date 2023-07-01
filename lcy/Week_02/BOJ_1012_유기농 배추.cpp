#include <iostream>
#define MAX 51
using namespace std;

int baechu[MAX][MAX] = { 0 };
int T, M, N, K, numOfWorms;
bool safe[MAX][MAX] = { false };

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;

        if (baechu[ny][nx] && !safe[ny][nx]) {
            safe[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}

void reset() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            baechu[i][j] = 0;
            safe[i][j] = 0;
        }
    }
}

void countEarthworm() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (baechu[i][j] == 1 && safe[i][j] == 0) {
                numOfWorms++;
                safe[i][j] = true;
                dfs(i, j);
            }
        }
    }
    cout << numOfWorms << endl;
}

int main() {
    cin >> T;
    while (T != 0) {
        numOfWorms = 0;
        T--;
        //reset();
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            baechu[b][a] = 1;
        }
        countEarthworm();
        reset();
    }
}