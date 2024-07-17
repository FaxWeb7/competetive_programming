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
    int n, m; cin >> n >> m;
    vector<string> a(n), b(n);
    vi sumsARows(n), sumsACols(m);
    vi sumsBRows(n), sumsBCols(m);
    for (int i = 0; i < n; ++i){
        int sum = 0;
        cin >> a[i];
        for (int j = 0; j < a[i].size(); ++j){
            sum += a[i][j] - '0';
            sumsACols[j] += a[i][j];
        }
        sumsARows[i] = sum;
    }
    for (int i = 0; i < n; ++i){
        int sum = 0;
        cin >> b[i];
        for (int j = 0; j < b[i].size(); ++j){
            sum += b[i][j] - '0';
            sumsBCols[j] += b[i][j];
        }
        sumsBRows[i] = sum;
    }

    bool ok = true;
    for (int i = 0; i < n; ++i){
        if (sumsARows[i] % 3 != sumsBRows[i] % 3) ok = false;
    }
    for (int i = 0; i < m; ++i){
        if (sumsACols[i] % 3 != sumsBCols[i] % 3) ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
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