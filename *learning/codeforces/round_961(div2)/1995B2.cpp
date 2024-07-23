#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

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

int64_t ceil_div(int64_t a, int64_t b) {
    return (a + (b - 1)) / b;
}

void solve(){
    int n, m; cin >> n >> m;
    vi a(n);
    for (int &x : a) cin >> x;
    map<int, int> mp;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        mp[a[i]] = x;
    }
    sort(all(a));

    int ans = 0;
    for (int i = 0; i < n; ++i){
        ans = max(ans, a[i] * min(mp[a[i]], m / a[i]));

        if (i+1 < n && a[i+1] == a[i]+1){
            int cur = m;

            int v1 = min(cur / a[i], mp[a[i]]);
            cur -= a[i] * v1;
            int v2 = min(cur / a[i+1], mp[a[i+1]]);
            cur -= a[i+1] * v2;

            cur -= min(cur, min(v1, mp[a[i+1]] - v2));

            ans = max(ans, m-cur);
        }
    }

    cout << ans << '\n';
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


