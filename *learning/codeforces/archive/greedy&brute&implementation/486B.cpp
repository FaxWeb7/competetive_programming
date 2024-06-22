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
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const double PI = acos(-1);
const double EPS = 1e-10;
const int INF = 1e9 + 6;

void solve(){
    int n, m; cin >> n >> m;
    vvi a(n, vi(m, 1)), b(n, vi(m));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) cin >> b[i][j];
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (b[i][j] == 0){
                for (int k = 0; k < n; ++k) a[k][j] = 0;
                for (int k = 0; k < m; ++k) a[i][k] = 0;
            }
        }
    }

    vi rowOr(n), colOr(m);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) cnt |= a[i][j];
        rowOr[i] = cnt;
    }
    for (int j = 0; j < m; ++j) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) cnt |= a[i][j];
        colOr[j] = cnt;
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (b[i][j] != (rowOr[i] | colOr[j])){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) cout << a[i][j] << ' ';
        cout << '\n';
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}