#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 999999999
using namespace std;

int dis[1001];
vector<pair<int, int>> vec[10001];

void solution(int start) {
    dis[start] = 0;

   priority_queue<pair<int, int>> pq;
   pq.push({ dis[start], start });
   while (!pq.empty()) {
      //큐의 가장 맨 앞에 있는 정점의 번호를 가져옴
      int cur = pq.top().second;
      int distance = pq.top().first * -1;
      pq.pop();

      if (dis[cur] < distance) continue;

      for (int i = 0; i < vec[cur].size(); i++) {
         int next = vec[cur][i].first;
         int nextDistance = distance + vec[cur][i].second;

         if (nextDistance < dis[next]) {
            dis[next] = nextDistance;
            pq.push({ nextDistance * -1, next });
         }
      }
   }
}

int main() {

   ios::sync_with_stdio(0);
   cin.tie(0);

   int start, end;
   int N, M;
   cin >> N; // 도시 개수
   cin >> M; // 버스 개수

   for (int i = 1; i <= N; i++)
      dis[i] = MAX;

   for (int i = 0; i < M; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      vec[u].push_back({ v,w });
   }

   cin >> start;
   cin >> end;

   solution(start);

   cout << dis[end];

   return 0;
}