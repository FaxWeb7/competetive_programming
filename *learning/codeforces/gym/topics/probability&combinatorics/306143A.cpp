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
    vi cnt0R(n), cnt0C(m);
    vi cnt1R(n), cnt1C(m);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            int x; cin >> x;
            if (x) {
                cnt1R[i]++;
                cnt1C[j]++;
            } else {
                cnt0R[i]++;
                cnt0C[j]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i){
        ans += (1ll << cnt1R[i]) - 1;
        ans += (1ll << cnt0R[i]) - 1;
    }
    for (int i = 0; i < m; ++i){
        ans += (1ll << cnt1C[i]) - 1;
        ans += (1ll << cnt0C[i]) - 1;
    }

    cout << ans - (n * m) << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}