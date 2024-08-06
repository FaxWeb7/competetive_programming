#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
// #define int ll
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
    int n, s, m; cin >> n >> s >> m;
    vector<pii> a(n);
    for (auto &p : a) cin >> p.F >> p.S;

    bool ok = false;
    for (int i = 1; i < n; ++i){
        if (a[i].F - a[i-1].S >= s) ok = true;
    }

    if (ok || a[0].F >= s || m-a.back().S >= s) cout << "YES\n";
    else cout << "NO\n";
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