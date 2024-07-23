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
    int n, x; cin >> n >> x;
    vi a(n);
    for (int &h : a) cin >> h;

    int curSum = count(all(a), 1);
    if (curSum < x) {cout << "-1\n"; return;}


    vi pref(n+1), suff(n+1);
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        if (a[i]){
            pref[++cnt] = i+1;
        }
    }
    cnt = 0;
    for (int i = n-1; i >= 0; --i){
        if (a[i]){
            suff[++cnt] = n-i;
        }
    }

    int m = curSum-x;
    int ans = INF;
    for (int i = 0; i <= m; ++i){
        ans = min(ans, pref[i]+suff[m-i]);
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