#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> coins(n + 1);
    for (int i = 1; i <= n; ++i) cin >> coins[i];

    // dp[i][j] = true, если можно набрать вес j с помощью первых i слитков
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            dp[i][j] = dp[i - 1][j];

            if (j - coins[i] >= 0 && dp[i - 1][j - coins[i]]) {
                dp[i][j] = true;
            }
        }
    }

    cout << (dp[n][m] ? "YES" : "NO");

    return 0;
}