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
    int n, h; cin >> n >> h;
    vi a(n);
    for (int &x : a) cin >> x;

    auto check = [&](int m){
        int res = 0;
        for (int i = 0; i < n; ++i){
            if (i < n-1) res += min(m, a[i+1]-a[i]);
            else res += m;
        }

        return res >= h;
    };

    int l = 0, r = 1e18;
    while (l < r){
        int m = l + (r - l) / 2;
        if (check(m)) r = m;
        else l = m + 1;
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