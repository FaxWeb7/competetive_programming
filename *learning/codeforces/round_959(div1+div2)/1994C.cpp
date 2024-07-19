#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n, x; cin >> n >> x;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    partial_sum(a.begin() + 1, a.end(), a.begin() + 1);
    vector<int> dp(n + 2);
    for (int i = n - 1; i >= 0; --i) {
        int q = upper_bound(a.begin(), a.end(), a[i] + x) - a.begin();
        dp[i] = dp[q] + q - i - 1;
    }
    cout << accumulate(dp.begin(), dp.end(), 0ll) << '\n';
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