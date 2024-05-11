#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> weights(n, vector<int>(m));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) cin >> weights[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(m));
    vector<vector<pair<int, int>>> from(n, vector<pair<int, int>>(m, {-1, -1}));
    dp[0][0] = weights[0][0];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (j+1 < m) {
                if (weights[i][j+1] + dp[i][j] > dp[i][j+1]){
                    dp[i][j+1] = weights[i][j+1] + dp[i][j];
                    from[i][j+1] = {i, j};
                }
            }
            if (i+1 < n) {
                if (weights[i+1][j] + dp[i][j] > dp[i+1][j]){
                    dp[i+1][j] = weights[i+1][j] + dp[i][j];
                    from[i+1][j] = {i, j};
                }
            }
        }
    }

    cout << dp[n-1][m-1] << '\n';

    vector<char> order;
    pair<int, int> v = {n-1, m-1};
    while (v != pair<int, int>{-1, -1}) {
        if (v.first == from[v.first][v.second].first) order.push_back('R');
        else order.push_back('D');
        v = from[v.first][v.second];
    }
    
    reverse(order.begin(), order.end());
    for (int i = 1; i < order.size(); ++i) cout << order[i] << ' ';
    
    return 0;
}