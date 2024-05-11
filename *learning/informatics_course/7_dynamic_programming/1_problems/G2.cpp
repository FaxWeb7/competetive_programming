#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main(){
    int n;
    cin >> n;

    // dp[i] => минимальное кол-во операций для получения числа i
    vector<int> dp(n + 1, INF);
    vector<pair<int, int>> from(n + 1, {-1, -1}); // { {idx, op} }
    dp[1] = 0;

    int res = 0;
    for (int i = 1; i <= n; ++i){
        if (i + 1 <= n){
            if (dp[i] + 1 < dp[i+1]){
                from[i+1] = {i, 1};
            }
            dp[i+1] = min(dp[i+1], dp[i] + 1); 
        }
        if (i * 2 <= n){
            if (dp[i] + 1 < dp[i*2]){
                from[i*2] = {i, 2};
            }
            dp[i*2] = min(dp[i*2], dp[i] + 1);
        }
        if (i * 3 <= n){
            if (dp[i] + 1 < dp[i*3]){
                from[i*3] = {i, 3};
            }
            dp[i*3] = min(dp[i*3], dp[i] + 1);
        }
    }

    string order = "";
    for (auto v = from[n]; v != make_pair(-1,-1); v = from[v.first]){
        order += to_string(v.second);
    }
    reverse(order.begin(), order.end());

    cout << order;

    return 0;
}