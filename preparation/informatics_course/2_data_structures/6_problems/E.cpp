#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){ 
    int t, n, x;
    cin >> t;

    vector<int> res;
    res.reserve(t);
    for (int i = 0; i < t; i++){
        cin >> n >> x;
        vector<ll> arr(n);
        for (int j = 0; j < n; j++) cin >> arr[j];

        ll curSum = 0;
        int maxLen = 0;
        for (int l = 0, r = 0; r < n; r++){
            curSum += arr[r];
            while (l < n && curSum%x == 0){
                curSum -= arr[l++];
            }
            maxLen = max(maxLen, r-l+1);
        }
        res.push_back(maxLen ? maxLen : -1);
    }

    for (int i = 0; i < t; i++) cout << res[i] << endl;

    return 0;
}