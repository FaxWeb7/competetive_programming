#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main(){
    int n, a1, k, b, m;
    cin >> n >> a1 >> k >> b >> m;
    vector<int> a(n);
    a[0] = a1;
    for (int i = 0; i < n; ++i){
        a[i+1] = (k*a[i] + b) % m;
    }

    vector<int> dp(n, INF);
    dp[0] = -INF;
    for (int i = 0; i < n; ++i) {
        int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (dp[j-1] < a[i] && a[i] < dp[j]){
            dp[j] = a[i];
        }
    }
    
    int maxIdx = 1;
    for (int i = 0; i < n; ++i) {
        if (dp[i] < INF) {
            maxIdx = i;
        }
    }

    return 0;
}