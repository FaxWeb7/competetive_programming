#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main(){
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();

    // dp[i][j] => минимальное количество операций, необходимых для преобразования подстроки a0..i-1 в подстроку b0..j-1.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
            }
        }
    }

    cout << dp[n][m];

    return 0;
}