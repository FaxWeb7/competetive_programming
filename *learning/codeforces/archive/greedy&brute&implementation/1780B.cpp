#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>

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
    vi pref(n+1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        pref[i] = pref[i-1] + x;
    }

    int ans = 1;
    for (int k = 1; k < n; ++k){
        ans = max(ans, gcd(pref[k], pref[n]-pref[k]));
    }

    cout << ans << '\n';
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