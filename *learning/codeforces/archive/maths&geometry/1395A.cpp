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
    int r, g, b, w; cin >> r >> g >> b >> w;

    int res1 = r%2 + g%2 + b%2 + w%2;
    int res2 = res1;
    if (r > 0 && g > 0 && b > 0){
        r--, g--, b--, w += 3;
        res2 = r%2 + g%2 + b%2 + w%2;
    }

    cout << (res1 <= 1 || res2 <= 1 ? "Yes\n" : "No\n");
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