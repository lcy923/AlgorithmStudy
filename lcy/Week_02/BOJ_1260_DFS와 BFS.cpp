#include <iostream>
#include <queue>
#define MAX 1001   // 1<=N<=1000

using namespace std;

int map[MAX][MAX];



int N, M, V;
bool visited[MAX];
queue <int> q;

//모두 방문한 적 없는 상태로 만들어줌
void reset(){
    for(int i = 1; i <= N; i++){
        visited[i] = false;
    }
}

void DFS(int n){
    //방문했다고 변경
    visited[n] = true;
    //방문 노드 출력
    cout << n << " ";
    //n과 바로 닿아있는 비방문 노드를 찾아 방문
    for(int i = 1; i <= N; i++){
        if(map[n][i] == 1 && visited[i] == false){
            DFS(i);
        }
    }
}

void BFS(int n){
    //방문한 노드 큐에 넣기
    q.push(n);
    //방문했다고 변경
    visited[n] = true;
    //방문 노드 출력
    cout << n << " ";
    
    //큐가 비어있을 때까지 계속 진행
    while(!q.empty()){
        //큐의 가장 앞에 있는 노드를 선택하고 
        n = q.front();
        q.pop();
        //n과 닿아있는 모든 노드를 찾아 방문 및 큐에 삽입, 방문으로 출력
        for (int j = 1; j <= N; j++) {
            if (map[n][j] == 1 && visited[j] == false) { //현재 정점과 연결되어있고 방문되지 않았으면
                q.push(j);
                visited[j] = true;
                cout << j << " ";
            }
        }
    }

}

int main() {
    cin >> N >> M >> V;
 
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
 
    reset();
    DFS(V);
    
    cout << '\n';
    
    reset();
    BFS(V);
 
    return 0;
}
