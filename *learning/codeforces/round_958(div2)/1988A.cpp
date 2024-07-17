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

int64_t ceil_div(int64_t a, int64_t b) {
    return (a + (b - 1)) / b;
}

void solve(){
    int n, k; cin >> n >> k;

    int ans = 0;
    int curSz = 1;
    while (curSz < n){
        curSz += k-1;
        ans++;
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