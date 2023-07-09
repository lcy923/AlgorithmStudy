#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;

int N, K;
bool visited[MAX];

int solution(){
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, N});
    visited[N] = true;
    while(!pq.empty()){
        //시간이 몇 초인지 뽑아오기
        int time = pq.top().first;
        //현재 위치가 어디인지 뽑아오기
        int x = pq.top().second;
        pq.pop();

        if(x == K) return time;
        if(x*2 < MAX && visited[x*2] != true){
            pq.push({time, x*2});
            visited[x*2] = true;
        }
        if(x+1 < MAX && visited[x+1] != true){
            pq.push({time+1, x+1});
            visited[x+1] = true;
        }
        if(x-1 >= 0 && visited[x-1] != true){
            pq.push({time+1, x-1});
            visited[x-1] = true;
        }
    }
}

int main(){

    //백준을 위한 시간초과 방지
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    cout << solution();
}