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
    int n; cin >> n;
    vi a(n);
    int idx = -1;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if (i > 0 && a[i] != a[i-1]) {
            idx = i;
        }
    }

    if (idx == -1) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i){
            if (i == idx) continue;
            if (a[i] != a[idx]) cout << i+1 << ' ' << idx+1 << '\n';
            else cout << i+1 << ' ' << idx << '\n';
        }
    }
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