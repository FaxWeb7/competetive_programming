#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;

void solve(){
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n-1; ++i) {
        if (a[i][m-1] == 'R') ans++;
    }
    for (int i = 0; i < m-1; ++i) {
        if (a[n-1][i] == 'D') ans++;
    }

    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}