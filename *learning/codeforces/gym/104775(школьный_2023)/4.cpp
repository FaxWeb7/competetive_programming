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
    int n, t; cin >> n >> t;
    vi s(n-1);
    for (int &x : s) cin >> x;

    pii ans = {0, 0};
    int curSum = 0;
    for (int l = 0, r = 0; l < n-1; ++l){
        while (r+1 < n && curSum + 2*s[r] <= t) curSum += 2*s[r++];

        if (r-l+1 > ans.S-ans.F+1) ans = {l, r};
        if (curSum > 0) {
            curSum -= 2*s[l];
        } else r++;
    }

    cout << ans.F+1 << '\n' << ans.S+1;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}