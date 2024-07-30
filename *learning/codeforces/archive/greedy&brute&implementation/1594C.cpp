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

void solve(){
    int n; cin >> n;
    char c; cin >> c;

    string s = "";
    bool ans0 = true;
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        char ch; cin >> ch; s += ch;
        if (ch != c) ans0 = false;
        if (ch == c) cnt++;
    }

    if (ans0) {cout << "0\n"; return;}

    int ans1 = 0;
    for (int k = 2; k <= n; ++k){
        bool ok = true;
        for (int i = k-1; i < n; i += k){
            if (s[i] != c) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans1 = k;
            break;
        }
    }

    if (ans1) cout << "1\n" << ans1 << '\n';
    else cout << "2\n" << n << ' ' << n/2 + 1 << '\n';
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
