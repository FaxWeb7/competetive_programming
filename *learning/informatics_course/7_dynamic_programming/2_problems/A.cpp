#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dp(n, vector<ll>(m));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (j-1 >= 0) dp[i][j] += dp[i][j-1];
            if (i-1 >= 0) dp[i][j] += dp[i-1][j];
        }
    }
    
    cout << dp[n-1][m-1];
    
    return 0;
}