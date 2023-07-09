#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int n, r, c;
int ans;

void Z(int y, int x, int size) {
    if (y == r && x == c) {
        cout << ans << '\n';
        return;
    }

    if (r < y + size && r >= y && c < x + size && c >= x) {

        //1사분면 탐색
        Z(y, x, size / 2);
        //2사분면 탐색
        Z(y, x + size / 2, size / 2);
        //3사분면 탐색
        Z(y + size / 2, x, size / 2);
        //4사분면 탐색
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else {
        ans += size * size;
    }
}

int main() {
    //백준을 위한 시간초과 방지
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //값 입력받기
    cin >> n >> r >> c;
    
    Z(0, 0, pow(2, n));
        return 0;
}