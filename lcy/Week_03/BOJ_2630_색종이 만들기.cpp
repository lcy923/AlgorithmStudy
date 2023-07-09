#include <iostream>
#define MAX 128
using namespace std;

int N;
int arr[MAX][MAX];
int blue_cnt, white_cnt = 0;

void solution(int n, int a, int b){
    bool white, blue = true;

    //전체적인 크기에 대해 색을 조사한다.
    //하나라도 다른 색이 나오면 white, blue 가 false가 되어야 한다.
    //white나 blue가 true 인 것이 있다면 다 그 색이라는 것이다. 
    for(int i = a; i < a + n; i++){
        for(int j = b; j < b + n; j++){
            if(arr[i][j] == 1) white = false;
            if(arr[i][j] == 0) blue = false;
        }
    }

    if(blue == true) {
        blue_cnt++;
        return;
    }
    if(white == true){
        white_cnt ++;
        return;
    }

    int m = n/2;
    solution(m, a, b);
    solution(m, a+m, b);
    solution(m, a, b+m);
    solution(m, a+m, b+m);

}


int main(){
    //N과 map을 입력받는다
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    solution(N, 0, 0);

    cout << white_cnt << "\n" << blue_cnt;
}