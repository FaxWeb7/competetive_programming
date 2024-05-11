#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> weights(n, vector<int>(m));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) cin >> weights[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = weights[0][0];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (j+1 < m) dp[i][j+1] = max(dp[i][j+1], weights[i][j+1] + dp[i][j]);
            if (i+1 < n) dp[i+1][j] = max(dp[i+1][j], weights[i+1][j] + dp[i][j]);
        }
    }

    cout << dp[n-1][m-1];
    
    return 0;
}