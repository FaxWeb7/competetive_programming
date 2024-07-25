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
    int n, m, k, t; cin >> n >> m >> k >> t;

    int ans1 = (m / k) * k;
    int ans2 = ans1;
    if (ans2 < m && ans2 + k <= m + t) ans2 += k;

    cout << (n+m) - max(m, max(ans1, ans2));
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}