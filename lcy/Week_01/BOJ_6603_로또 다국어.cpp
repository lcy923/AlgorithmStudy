#include <iostream>
using namespace std;

int S[13];
int lotto[6];
int n;
//start는 S의 인덱스, depth는 lotto의 인덱스 
void getCombi(int start, int depth) {
    //다 채워졌으면 출력하기
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << " ";
		}
		cout << endl;
		return;
	}
	//로또 번호 채우기
	for (int i = start; i < n; i++) {
		lotto[depth] = S[i];
		getCombi(i+1, depth+1);
	}
}
int main(void) {
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> S[i];
		}
		getCombi(0, 0);
		cout << endl;
	}
}