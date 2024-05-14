#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // dp[i] => длина нвп оканчивающающейся на индексе i
    vector<int> dp(n, INF);
    dp[0] = -INF;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j){
            if (a[j] < a[i]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    
    int ans = dp[0];
    for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
    cout << ans;

    return 0;
}

int main2(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // dp[i] => число, на которое заканчивается нвп длины i
    vector<int> dp(n, INF);
    dp[0] = -INF;
    for (int i = 0; i < n; ++i) {
        int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (dp[j-1] < a[i] && a[i] < dp[j]){
            dp[j] = a[i];
        }
    }
    
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (dp[i] < INF) {
            ans = i;
        }
    }
    cout << ans;

    return 0;
}