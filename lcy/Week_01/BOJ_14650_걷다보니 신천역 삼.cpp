#include <iostream>
using namespace std;

int n;

long long check(int num, int sum, int length){
    if(length == 1 && sum % 3 == 0)
        return 1;
    else if(length == 1)
        return 0;

    long long result = 0;
    for(int i = 0; i<=2; i++){
        result += check(i, sum + i, length - 1);
    }
    return result;
}

int main(){
    cin >> n;
    if(n == 1)
        cout << 0 << endl;
    else{
        long long result = 0;
        for(int i = 1; i <= 2; i++){
            result += check(i, i, n);
        }
        cout << result << endl;
    }
}