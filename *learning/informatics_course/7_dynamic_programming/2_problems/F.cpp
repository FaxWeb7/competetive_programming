#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int sol(vector<vector<int>> &dp, int n, int m){
    if (n < 0 || m < 0 || n >= dp.size() || m >= dp[0].size()) return 0;
    if (n == 0 && m == 0) return 1;

    dp[n][m] = sol(dp, n-2, m-1) + sol(dp, n-2, m+1) + sol(dp, n-1, m-2) + sol(dp, n+1, m-2);
    return dp[n][m];
}

int main(){
    int n, m;
    cin >> m >> n;

    vector<vector<int>> dp(n, vector<int>(m));

    cout << sol(dp, n-1, m-1);
    
    return 0;
}