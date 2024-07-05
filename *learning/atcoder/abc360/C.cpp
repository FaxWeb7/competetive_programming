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
    vvi boxes(n);
    vi w(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; --x;
        boxes[x].pb(i);
    }
    for (int i = 0; i < n; ++i) cin >> w[i];

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (boxes[i].size() < 2) continue;
        pii mx = {w[boxes[i][0]], 0};
        for (int j = 0; j < boxes[i].size(); ++j){
            if (mx.F < w[boxes[i][j]]) mx = {w[boxes[i][j]], j};
        }

        for (int j = 0; j < boxes[i].size(); ++j){
            if (j == mx.S) continue;
            res += w[boxes[i][j]];
        }
    }

    cout << res << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}