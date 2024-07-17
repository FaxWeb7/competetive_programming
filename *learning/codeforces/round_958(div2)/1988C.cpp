#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

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

    set<int> res;
    res.insert(n);
    for (int i = 0; i <= 64; ++i){
        int bit = n & (1ll << i);
        if (bit){
            if (n-bit != n && n-bit != 0) res.insert(n-bit);
        }
    }

    cout << res.size() << '\n';
    for (auto it = res.begin(); it != res.end(); ++it) cout << *it << ' ';
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