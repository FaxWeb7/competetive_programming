#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main(){
    int n, m;
    cin >> m >> n;

    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (i-2 >= 0 && j-1 >= 0) dp[i][j] += dp[i-2][j-1];
            if (i-1 >= 0 && j-2 >= 0) dp[i][j] += dp[i-1][j-2];
        }
    }

    cout << dp[n-1][m-1];
    
    return 0;
}