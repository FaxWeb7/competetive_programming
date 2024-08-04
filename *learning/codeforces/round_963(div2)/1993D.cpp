#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

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
    int n, k; cin >> n >> k;
    vi a(n);
    vi b(n), dp(n);
    for (int &x : a) cin >> x;
    if (k >= n) {
        sort(all(a));
        cout << a[(n+1)/2-1] << '\n';
        return;
    }
    
    auto check = [&](int mid){
        for (int i = 0; i < n; ++i){
            if (a[i] >= mid) b[i] = 1;
            else b[i] = -1;
        }

        dp[0] = b[0];
        for (int i = 1; i < n; ++i){
            if (i % k == 0){
                dp[i] = max(dp[i-k], b[i]);
            } else {
                dp[i] = dp[i-1] + b[i];
                if (i > k){
                    dp[i] = max(dp[i], dp[i-k]);
                }
            }
        }

        return dp[n-1] > 0;
    };

    int l = 1, r = 1e9;
    while (l < r){
        int mid = l + (r - l + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << '\n';
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
