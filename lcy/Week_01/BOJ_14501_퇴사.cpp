#include <iostream>
#include <algorithm>

using namespace std;

int n;
int* T;
int* P;
int* dp;

void solution(){
    int biggest = 0;
    for(int i = 0; i<=n; i++){
        dp[i] = max(biggest, dp[i]);
        if(T[i] + i <= n){
            dp[T[i]+i] = max(dp[T[i]+i], P[i]+dp[i]);
        }
        biggest = max(biggest, dp[i]);
    }
    cout << biggest;
}

int main(){
    //input
    cin >> n;
    T = new int[n+1];
    P = new int[n+1];
    dp = new int[n+1];
    
    fill(dp, dp+n+1, 0);
    for(int i = 0; i<n; i++){
        cin >> T[i] >> P[i];
    }

    solution();
}