#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int maxLen = 0;
    int l = 0;
    int curSum = 0;
    for (int r = 0; r < n; r++){
        curSum += arr[r];

        while (curSum > k){
            curSum -= arr[l];
            l++;
        }
        maxLen = max(maxLen, r-l+1);
    }

    cout << maxLen;

    return 0;
}