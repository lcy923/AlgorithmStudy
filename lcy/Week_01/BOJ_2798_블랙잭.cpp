#include <iostream>
using namespace std;

int main() {
    int num, target,result,sum = 0;
    int min = 9999999;
    int arr[100] = {0, };
    cin >> num >> target;
    for(int i = 0; i < num; i++)
        cin >> arr[i];

    for(int i = 0; i < num-2; i++)
        for(int j = i+1; j < num-1; j++)
            for(int k = j+1; k < num; k++)
            {
                sum = arr[i]+arr[j]+arr[k];
                if(target - sum < min && target - sum >= 0) {
                    min = target - sum;
                    result = sum;
                }
            }
    cout << result;
}