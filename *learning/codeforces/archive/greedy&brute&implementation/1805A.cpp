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
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int res = 0;
    for (int &i : a){
        res ^= i;
    }

    if (res == 0 || n % 2 == 1) cout << res << '\n';
    else cout << -1 << '\n';
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