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
    vi a(2), b(2);
    cin >> a[0] >> a[1] >> b[0] >> b[1];

    int ans = 0;
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 2; ++j){
            int cnt = (a[i] > b[j] ? 1 : a[i] == b[j] ? 0 : -1) + (a[1-i] > b[1-j] ? 1 : a[1-i] == b[1-j] ? 0 : -1);
            if (cnt > 0) ans++;
        }
    }

    cout << ans << '\n';
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