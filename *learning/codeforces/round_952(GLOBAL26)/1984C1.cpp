#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9 + 6;

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    vector<pii> dp(n);
    dp[0] = {abs(a[0]), a[0]};
    for (int i = 1; i < n; ++i){
        dp[i].F = max(dp[i-1].F + a[i], abs(dp[i-1].F + a[i]));
        dp[i].F = max(dp[i].F, max(dp[i-1].S + a[i], abs(dp[i-1].S + a[i])));
        dp[i].S = dp[i-1].S + a[i];
    }
    int c = dp[n-1].F;
    cout << c << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}