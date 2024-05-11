#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main(){
    int n, m;
    cin >> m >> n;
    n--, m--;

    vector<vector<int>> dp(8, vector<int>(8));
    dp[n][m] = 1;
    for (int i = n; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            if (i == n && j == m) continue;
            if (j-1 >= 0 && i-1 >= 0) dp[i][j] += dp[i-1][j-1];
            if (j+1 < 8 && i-1 >= 0) dp[i][j] += dp[i-1][j+1];
        }
    }

    int res = 0;
    for (int j = 0; j < 8; ++j) res += dp[7][j];
    cout << res;
    
    return 0;
}