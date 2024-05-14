#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m + 1);
    for (int i = 1; i <= m; ++i) cin >> b[i];

    // dp[i][j] => ноп на первых i элементах первой последовательности и первых j элементах второй последовательности
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    vector<int> order;
    int i = n, j = m;
    while (i > 0 && j > 0){
        if (a[i] == b[j]){
            order.push_back(a[i]);
            i--, j--;
        }
        else if (dp[i-1][j] == dp[i][j]) i--;
        else j--;
    }

    reverse(order.begin(), order.end());
    for (int &num : order) cout << num << ' ';

    return 0;
}