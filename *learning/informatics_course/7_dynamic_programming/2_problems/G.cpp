#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rooms(n, vector<int>(m));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) cin >> rooms[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (j+1 < m && rooms[i][j+1]) dp[i][j+1] += dp[i][j];
            if (i+1 < n && rooms[i+1][j]) dp[i+1][j] += dp[i][j];
        }
    }

    cout << (dp[n-1][m-1] >= 1 ? to_string(dp[n-1][m-1]) : "Impossible");
    
    return 0;
}