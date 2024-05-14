#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];

    // dp[i][j] => максимальная стоимость рюкзака из первых i предметов веса j
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            dp[i][j] = dp[i-1][j];
            if (j - w[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + c[i]);
            }
        }
    }

    cout << dp[n][m];

    return 0;
}