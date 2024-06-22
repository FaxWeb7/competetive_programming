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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n, x; cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mx = a[0], mn = a[0];
    int res = 0;
    for (int i = 0; i < n; ++i){
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        if (mx - mn > 2*x){
            res++;
            mx = mn = a[i];
        }
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