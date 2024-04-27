#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int r = 0;
    int curSum = 0, maxSum = 0;
    for (int l = 0; l < n; l++){
        while (r < n && arr[r] >= 0){
            curSum += arr[r++];
            maxSum = curSum;
        }
        curSum = 0;
    }

    cout << maxSum;

    return 0;
}