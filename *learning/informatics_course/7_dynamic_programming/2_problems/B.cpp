#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    if (n == 0) return 0;

    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i){
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    
    for (auto &row : dp){
        for (ll &num : row) 
            if (num != -1) cout << num << ' ';
        cout << '\n';
    }
    
    return 0;
}