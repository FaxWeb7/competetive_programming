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
#define sz(x) (int)a.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<pii> vec;
    for (int l = 1; l <= n; ++l){
        for (int r = 1; r <= n; ++r){
            if (r-l >= k && a[l-1] > a[r-1]) {
                swap(a[l-1], a[r-1]);
                vec.pb({l, r});
            }
        }
    }

    cout << vec.size() << '\n';
    for (pii &p : vec) cout << p.F << ' ' << p.S << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}