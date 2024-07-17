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

int64_t ceil_div(int64_t a, int64_t b) {
    return (a + (b - 1)) / b;
}

void solve(){
    string s; cin >> s;
    int n = s.size();

    int t = 0;
    int cur = 0;
    for (int i = 0; i < 2*n-1; ++i){
        if (s[i%n] == '1') cur++;
        else {
            cur = 0;
            if (i >= n) break;
        }
        t = max(t, cur);
    }
    t = min(n, t);

    if (t == n) cout << n*n << '\n';
    else {
        int ans;
        if (t % 2) ans = pow(ceil_div(t, 2), 2);
        else ans = t/2 * (t/2 + 1);

        cout << ans << '\n';
    }
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