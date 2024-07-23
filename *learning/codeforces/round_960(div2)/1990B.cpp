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
    int n, x, y; cin >> n >> x >> y;
    x--, y--;
    
    vi a(n);
    a[x] = 1, a[y] = 1;
    for (int i = x+1; i < n; ++i){
        if (a[i-1] == -1) a[i] = 1;
        else a[i] = -1;
    }
    for (int i = y-1; i >= 0; --i){
        if (a[i+1] == -1) a[i] = 1;
        else a[i] = -1;
    }
    for (int i = y+1; i <= x-1; ++i){
        a[i] = 1;
    }

    for (int &x : a) cout << x << ' ';
    cout << '\n';
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