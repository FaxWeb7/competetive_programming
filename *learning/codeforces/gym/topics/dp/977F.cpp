#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

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
    vi a(n);
    for (int &x : a) cin >> x;

    map<int, pii> dp; //{bool, len}
    dp[a[0]] = {1, 1};

    pii mx = {0, 0};
    for (int i = 0; i < n; ++i){
        dp[a[i]] = {1, 1};
        if (dp[a[i]-1].F) dp[a[i]] = {1, dp[a[i]-1].S+1};

        if (dp[a[i]].S > mx.S) {
            mx = {a[i], dp[a[i]].S};
        }
    }

    int cur = mx.F-mx.S+1;
    cout << mx.S << '\n';
    for (int i = 0; i < n; ++i){
        if (cur == mx.F+1) break;
        if (a[i] == cur) {
            cout << i+1 << ' ';
            cur++;
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}