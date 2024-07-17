#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

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

int lastIdx(vi &a){
    int x = 0;
    while (x+1 < sz(a) && a[x+1] == a[0]) x++;
    return x;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;
    reverse(all(a));

    int ans = 0;
    while (lastIdx(a) != n-1 && ans < 30){
        ans++;
        int idx = lastIdx(a);
        for (int i = idx+1; i < min(n, 2 * (idx+1)); ++i){
            a[i] = a[0];
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