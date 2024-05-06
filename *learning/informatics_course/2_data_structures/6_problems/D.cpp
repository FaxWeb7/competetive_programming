#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, d;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> d;

    sort(arr.begin(), arr.end());
    int maxLen = 0;
    for (int l = 0, r = 0; l < n; l++){
        int prevR = r;
        while (r < n && arr[r] - arr[l] <= d){
            r++;
        }
        if (prevR != r) r--;
        maxLen = max(maxLen, r-l+1);
    }

    cout << maxLen;

    return 0;
}