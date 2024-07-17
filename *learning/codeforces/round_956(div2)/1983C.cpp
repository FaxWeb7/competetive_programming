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
    vi a(n), b(n), c(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;

    vvi pref(3, vi(n+1));
    for (int i = 1; i <= n; ++i){
        pref[0][i] = pref[0][i-1] + a[i-1];
        pref[1][i] = pref[1][i-1] + b[i-1];
        pref[2][i] = pref[2][i-1] + c[i-1];
    }
    int s = pref[0][n];

    for (int i = 0; i < 3; ++i){
        vector<pii> vec{{0, 0},{0, 0},{0, 0}};
        for (int j = 1; j <= n; ++j){
            if (!vec[i].F && pref[i][j] >= (s+2)/3) vec[i] = {1, j};
            if (vec[i].F && !vec[(i+1)%3].F && pref[(i+1)%3][j]-pref[(i+1)%3][vec[i].S] >= (s+2)/3) vec[(i+1)%3] = {vec[i].S+1, j};
        }
        if (vec[i].F && vec[(i+1)%3].F && pref[(i+2)%3][n]-pref[(i+2)%3][vec[(i+1)%3].S] >= (s+2)/3){
            vec[(i+2)%3] = {vec[(i+1)%3].S+1, n};
            cout << vec[0].F << ' ' << vec[0].S << ' ' << vec[1].F << ' ' << vec[1].S << ' ' << vec[2].F << ' ' << vec[2].S << '\n';
            return;
        }

        vec = {{0, 0},{0, 0},{0, 0}};
        for (int j = 1; j <= n; ++j){
            if (!vec[i].F && pref[i][j] >= (s+2)/3) vec[i] = {1, j};
            if (vec[i].F && !vec[(i+2)%3].F && pref[(i+2)%3][j]-pref[(i+2)%3][vec[i].S] >= (s+2)/3) vec[(i+2)%3] = {vec[i].S+1, j};
        }
        if (vec[i].F && vec[(i+2)%3].F && pref[(i+1)%3][n]-pref[(i+1)%3][vec[(i+2)%3].S] >= (s+2)/3){
            vec[(i+1)%3] = {vec[(i+2)%3].S+1, n};
            cout << vec[0].F << ' ' << vec[0].S << ' ' << vec[1].F << ' ' << vec[1].S << ' ' << vec[2].F << ' ' << vec[2].S << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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