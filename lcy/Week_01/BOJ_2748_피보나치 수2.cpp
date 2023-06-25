#include <iostream>
using namespace std;

long long fibarr[100] = {0,1,};

long long fib(int n) {
    if(n == 0 || n == 1)
        return fibarr[n];
    else if(fibarr[n] == 0)
        fibarr[n] = fib(n-1) + fib(n-2);
    return fibarr[n];
}
int main() {
    int n;
    cin >> n;
    cout << fib(n);
}