#include <iostream>
#include <queue>
using namespace std;
int N, M;
int arr[101][101] = { 0 };
bool visited[101] = { 0 };

int result = 0;

queue <int> q;

int bfs(int k) {
   q.push(k);
   visited[k] = true;
   while (!q.empty()) {
      k = q.front();
      q.pop();
      for (int i = 1; i <= N; i++) {
         if (arr[k][i] == 1 && visited[i] == false) {
            q.push(i);
            visited[i]= true;
            result++;
         }
      }
   }
   return result;
}

int main() {
   cin >> N;
   cin >> M;
   int x, y;
   for (int i = 0; i < M; i++) {
      cin >> x >> y;
      arr[x][y] = 1;
      arr[y][x] = 1;
   }
   cout << bfs(1);
}