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
    int n, m; cin >> n >> m;
    vi a(m), b;
    for (int &x : a) cin >> x;
    sort(all(a));

    for (int i = 0; i < m-1; ++i){
        b.pb(a[i+1]-a[i]-1);
    }
    b.pb((n - a.back()) + a[0] - 1);
    sort(all(b)), reverse(all(b));

    int alive = 0, cnt = 0;
    for (int i = 0; i < b.size(); ++i){
        if (b[i] - cnt - 1 >= 0) {
            alive += max(1, b[i] - cnt - 1);
            cnt += 4;
        } else break;
    }

    cout << n - alive << '\n';
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