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
    int n; cin >> n;

    string s = to_string(n);
    int ss = s.size();
    s += s, s += s, s += s, s += s;

    vector<pii> res;
    for (int a = 1; a <= 10000; ++a){
        int num = 0;
        for (int j = 1; j <= min(10ll, a * ss); ++j){
            num = num * 10 + (s[j-1] - '0');
            int b = ss*a - j;
            if (num == n*a-b && b != 0) res.pb({a, b});
        }
    }

    cout << res.size() << '\n';
    for (pii &p : res) cout << p.F << ' ' << p.S << '\n';
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