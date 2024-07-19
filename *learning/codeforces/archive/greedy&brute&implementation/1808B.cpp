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
    int n, m; cin >> n >> m;
    vvi a(m, vi(n));
    vvi pr(m, vi(n+1));

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> a[j][i];
        }
    }
    for (int i = 0; i < m; ++i){
        sort(all(a[i]));
        for (int j = 0; j < n; ++j){
            pr[i][j+1] = pr[i][j] + a[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            ans += (pr[i][n] - pr[i][j+1]) - (a[i][j] * (n-j-1));
        }
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