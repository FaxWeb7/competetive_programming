#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long> dp(n + 3);
    dp[0] = (long long)1, dp[1] = (long long)3, dp[2] = 8, dp[3] = (long long)19;
    for (int i = 4; i <= n; ++i){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cout << dp[n];

    return 0;
}