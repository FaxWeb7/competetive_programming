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
const int INF = 2*1e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    sort(all(a));
    sort(all(b));
    bool ok = true;
    for (int i = 0; i < n; ++i){
        if (a[i] <= b[i]) ok = false;
    }
    if (!ok) {
        cout << 0 << '\n';
        return;
    }

    int ans = 1;
    int p = 0;
    for (int i = 0; i < n; ++i){
        int cnt = 0;
        while (p+1 < n && a[i] > b[p+1]) p++;
        ans = (ans * (p + 1 - i)) % MOD;
    }

    cout << ans % MOD << '\n';
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