#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
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

vvi pairs(1001);

void solve(){
    int n; cin >> n;
    vvi nums(1001);
    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        nums[x].pb(i);
    }

    int ans = -1;
    for (int i = 1; i <= 1000; ++i){
        if (!nums[i].size()) continue;
        for (int j = 0; j < pairs[i].size(); ++j){
            if (!nums[pairs[i][j]].size()) continue;
            ans = max(ans, nums[i].back() + nums[pairs[i][j]].back());
        }
    }

    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 1000; ++i){
        for (int j = 1; j <= 1000; ++j){
            if (gcd(i, j) == 1) pairs[i].pb(j);
        }
    }

    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}