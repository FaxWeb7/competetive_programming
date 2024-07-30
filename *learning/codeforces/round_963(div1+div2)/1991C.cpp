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
    int n; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;

    bool ok = true;
    bool ansno = false;
    int mn = a[0], mx = a[0];
    for (int i = 1; i < n; ++i){
        if (a[i] != a[i-1]) ok = false;
        if ((a[i] % 2) != (a[i-1] % 2)) ansno = true;
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    if (ok) {
        if (a[0] == 0) cout << "0\n";
        else cout << "1\n" << a[0] << '\n';
        return;
    }
    if (ansno) {cout << "-1\n"; return;}

    vi res;
    int diff = mx;
    while (diff != 1){
        res.pb(diff);
        for (int i = 0; i < n; ++i){
            a[i] = abs(a[i]-diff);
        }
        diff = (diff+1) / 2;
    }

    bool has1 = false, has2 = false, all = true;
    for (int i = 0; i < n; ++i){
        if (a[i] == 1) has1 = true;
        if (a[i] == 2) has2 = true;
        if (i > 0 & a[i] != a[i-1]) all = false;
    }
    if (has1) res.pb(1);
    if (has2) {
        if (all) res.pb(2);
        else {
            res.pb(1);
            res.pb(1);
        }
    }
    cout << res.size() << '\n';
    for (int &x : res) cout << x << ' ';
    cout << '\n';
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