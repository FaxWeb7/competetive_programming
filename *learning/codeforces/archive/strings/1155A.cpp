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
#define sz(x) (int)a.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    pii ans = {-1, -1};
    for (int i = 1; i < n; ++i){
        if (s[i] < s[i-1]) ans = {i-1, i};
    }

    if (ans.F == -1) cout << "NO\n";
    else cout << "YES\n" << ans.F+1 << ' ' << ans.S+1 << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}