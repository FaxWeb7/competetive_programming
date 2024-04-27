#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, targetSum;
    cin >> n >> targetSum;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int maxLen = 0;
    int curSum = 0;
    for (int l = 0, r = 0; r < n; r++){
        curSum += arr[r];
        while (curSum > targetSum){
            curSum -= arr[l++];
        }
        maxLen = max(maxLen, r-l+1);
    }

    cout << maxLen;

    return 0;
}