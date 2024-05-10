#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long> dp(n + 2);
    dp[0] = (long long)1, dp[1] = (long long)2, dp[2] = (long long) 4;
    for (int i = 3; i <= n; ++i){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cout << dp[n];

    return 0;
}