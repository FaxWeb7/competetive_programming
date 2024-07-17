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
const int INF = 1e9 + 7;

void solve(){
    int n, q; cin >> n >> q;
    vi a(n);
    for (int &x : a) cin >> x;

    int mn = 31;
    while (q--){
        int x; cin >> x;
        if (x >= mn) continue;
        mn = x;

        for (int i = 0; i < n; ++i){
            if (a[i] % (1 << x) == 0) a[i] += (1 << (x-1));
        }
    }

    for (int &x : a) cout << x << ' ';
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