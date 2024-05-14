#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main(){
    int n, sum;
    cin >> n;
    vector<int> coins(n);
    for (int &coin : coins) cin >> coin;
    cin >> sum;

    // dp[i] = мин. кол-во монет для взятия суммы i
    vector<int> dp(sum + 1, INF);
    vector<pair<int, int>> from(sum + 1, {-1, -1}); //{ {from, diff} }
    dp[0] = 0;
    for (int i = 1; i <= sum; ++i){
        for (int j = 0; j < n; ++j){
            if (i - coins[j] >= 0 && dp[i - coins[j]] + 1 < dp[i]){
                dp[i] = dp[i - coins[j]] + 1;
                from[i] = {i - coins[j], coins[j]};
            }
        }
    }


    if (dp[sum] == INF) {cout << "No solution"; return 0;}
    vector<int> order;
    for (auto v = from[sum]; v != pair<int, int>{-1, -1}; v = from[v.first]){
        order.push_back(v.second);
    }
    reverse(order.begin(), order.end());
    for (int &num : order) cout << num << ' ';

    return 0;
}