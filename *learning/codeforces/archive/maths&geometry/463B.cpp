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
const int INF = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vi h(n+1);
    h[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> h[i];

    int ans = 0;
    int e = 0;
    for (int i = 0; i < n; ++i){
        e += h[i] - h[i+1];
        if (e < 0) {
            ans += abs(e);
            e = 0;
        }
    }

    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}