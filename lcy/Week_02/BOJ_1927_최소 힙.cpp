#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

int N;
int arr[MAX] = { -1 };

void solution() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int printNum;
    for (int i = 0; i < N; i++) {
        //0이면 배열 중 가장 작은 수 출력, 비어있는 경우 0 출력
        if (arr[i] == 0) {
            if (!pq.empty()) {
                printNum = pq.top();
                pq.pop();
            }
            else
                printNum = 0;
            cout << printNum << "\n";
        }
        else if (arr[i] > 0) {
            pq.push(arr[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    solution();
}