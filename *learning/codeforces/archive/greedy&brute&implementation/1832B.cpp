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
const int INF = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;
    vi a(n), pref(n+1);
    pref[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i-1] + a[i-1];
    }

    int ans = 0;
    for (int i = 0; i <= k; ++i){
        ans = max(ans, pref[n - i] - pref[2 * (k - i)]);
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