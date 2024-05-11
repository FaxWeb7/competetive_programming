#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    vector<int> dp(n + 2);
    dp[1] = v[1] - v[0];
    dp[2] = v[2] - v[0];

    for (int i = 3; i <= n; ++i){
        dp[i] = min(dp[i-1], dp[i-2]) + v[i] - v[i-1];
    }

    cout << dp[n-1];

    return 0;
}