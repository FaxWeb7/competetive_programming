#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m, INF));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) cin >> dp[i][j];
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (i != 0 && j != 0){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + dp[i][j];
            }
            else if (i != 0) dp[i][j] = dp[i][j] + dp[i-1][j];
            else if (j != 0) dp[i][j] = dp[i][j] + dp[i][j-1];
        }
    }

    cout << dp[n-1][m-1];
    
    return 0;
}