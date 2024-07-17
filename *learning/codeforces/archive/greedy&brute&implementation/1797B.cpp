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
    int n, k; cin >> n >> k;
    vvi a(n, vi(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }

    int cnt = 0;
    for (int i = 0; i < n/2; ++i){
        for (int j = 0; j < n; ++j){
            if (a[i][j] != a[n-i-1][n-j-1]) cnt++;
        }
    }
    if (n % 2){
        for (int j = 0; j < n/2; ++j){
            if (a[n/2][j] != a[n/2][n-j-1]) cnt++;
        }
    }
    
    if (cnt > k) cout << "NO\n";
    else if (n % 2) cout << "YES\n";
    else cout << ((k-cnt) % 2 == 0 ? "YES\n" : "NO\n");
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