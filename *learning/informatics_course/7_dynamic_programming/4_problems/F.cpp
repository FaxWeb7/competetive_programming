#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> dp(n, INF);
    vector<int> from(n, -1);
    dp[0] = -INF;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j){
            if (a[j] < a[i] && dp[i] < 1 + dp[j]){
                dp[i] = 1 + dp[j];
                from[i] = j;
            }
        }
    }

    int maxIdx = 0;
    for (int i = 0; i < n; ++i){
        if (dp[i] > dp[maxIdx]) maxIdx = i;
    }

    vector<int> order;
    while (maxIdx != -1){
        order.push_back(a[maxIdx]);
        maxIdx = from[maxIdx];
    }
    reverse(order.begin(), order.end());

    for (int &num : order) cout << num << ' ';

    return 0;
}