#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;


int N;
int arr[MAX] = {0};

void compareNum(){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++){
        pq.push(arr[i]);
    }
    int count = 0;
    int totComparing = N-1;

    while(!pq.empty()){
        if(totComparing == 0) break;
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        count = count + x + y;
        pq.push(x+y);
        totComparing--;
    }
    cout << count << endl;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    compareNum();
}