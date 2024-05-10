#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;

    for (int i = 1; i <= n; ++i){
        if (2*i <= n){
            dp[2*i] = dp[i] + dp[i-1];
        }
        if (2*i + 1 <= n) {
            dp[2*i + 1] = dp[i] - dp[i - 1];
        }
    }

    cout << dp[n];

    return 0;
}