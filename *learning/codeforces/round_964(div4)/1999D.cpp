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
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    bool ok = false;
    int p = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] == '?' || s[i] == t[p]){
            s[i] = t[p];
            if (p+1 == m) ok = true;
            p = min(p+1, m-1);
        }
    }

    if (ok) cout << "YES\n" << s << '\n';
    else cout << "NO\n";
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