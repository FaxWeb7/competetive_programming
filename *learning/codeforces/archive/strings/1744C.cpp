#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;
// #define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;

    unordered_map<int, int> mpc;
    vi a;
    for (int i = 0; i < n; ++i){
        if (s[i] == c) mpc[i] = 1;
        if (s[i] == 'g') a.pb(i);
    }

    int res = 0;
    for (auto &p : mpc){
        auto it = lower_bound(all(a), p.F);

        if (it != a.end()) res = max(res, *it-p.F);
        else res = max(res, (n-p.F) + a[0]);
    }

    cout << res << '\n';
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