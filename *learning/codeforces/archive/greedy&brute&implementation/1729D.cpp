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
    int n; cin >> n;
    vi x(n), y(n);
    for (int &v : x) cin >> v;
    for (int &v : y) cin >> v;

    vi minus, plus;
    int equal = 0;
    for (int i = 0; i < n; ++i){
        if (x[i] > y[i]) minus.pb(x[i]-y[i]);
        else if (x[i] < y[i]) plus.pb(y[i]-x[i]);
        else equal++;
    }
    sort(all(minus)), sort(all(plus));

    int ans = 0;
    int mp = 0, pp = 0;
    while (mp < sz(minus) && pp < sz(plus)){
        if (plus[pp] >= minus[mp]){
            ans++;
            mp++, pp++;
        } else pp++;
    }
    if (ans != sz(plus)){
        ans += (equal + (sz(plus) - ans)) / 2;
    } else ans += equal / 2;

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