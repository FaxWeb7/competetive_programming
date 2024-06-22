#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9 + 6;
const ld EPS = 0.00001;

void solve(){
    int x, y, z, k; cin >> x >> y >> z >> k;

    int ans = 0;
    for (int i = 1; i <= x; ++i){
        for (int j = 1; j <= y; ++j){
            if (k % (i * j)) continue;

            int l = k / (i * j);
            if (l > z) continue;

            ans = max(ans, (x-i+1) * (y-j+1) * (z-l+1));
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