#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <numeric>

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

vi dividers(int n){
    vi res;
    for (int i = 2; i*i <= n; ++i){
        if (n % i == 0){
            res.pb(i);
            if (n/i != i) res.pb(n/i);
        }
    }
    res.pb(n);
    return res;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;

    vi dp(n+1, 1); //dp[i] -> max len of good sequence
    vi d(1e5+1);

    int ans = 1;
    for (int i = 1; i <= n; ++i){
        vi divs = dividers(a[i-1]);
        for (int &div : divs){
            dp[i] = max(dp[i], d[div]+1);
        }
        for (int &div : divs){
            d[div] = max(d[div], dp[i]);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}