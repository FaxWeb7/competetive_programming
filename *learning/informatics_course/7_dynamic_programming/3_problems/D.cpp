#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i) cin >> w[i];
    
    // dp[i][j] = максимальный вес золота, который можно унести в рюкзаке вместимости j с помощью первых i слитков
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            dp[i][j] = dp[i-1][j];
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + w[i]);
            }
        }
    }

    cout << dp[n][m];

    return 0;
}